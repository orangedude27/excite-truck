#include <revolution/FS.h>
#include <revolution/NAND.h>
#include <revolution/OS.h>
#include <revolution/SC.h>

#include <string.h>

#define SC_CONF_MIN_SIZE (sizeof(SCConfHeader) + sizeof(u32))
#define SC_CONF_MAX_SIZE 0x4000

#define SC_CONF_BEGIN_MAGIC s_SCv0
#define SC_CONF_END_MAGIC s_SCed

#define SC_SMALLARRAY_MAX 0xFF
#define SC_BIGARRAY_MAX 0xFFFF

// The header counts its items in a u16, and the item's desc byte keeps only
// five bits for the name length (minus one).
#define SC_ITEM_MAX_NUM 0xFFFF
#define SC_ITEM_NAME_LEN_MAX 0b00011111

// Steps of the asynchronous SYSCONF write started by SCFlushAsync(). Each step
// names the NAND operation that is in flight; MyNandCallback() handles the
// result of that operation and queues the next one.
typedef enum {
    SC_FLUSH_STATE_FILE_TYPE,   // NANDPrivateGetTypeAsync() on SYSCONF
    SC_FLUSH_STATE_FILE_STATUS, // NANDPrivateGetStatusAsync() on SYSCONF
    SC_FLUSH_STATE_DELETE_FILE, // NANDPrivateDeleteAsync()
    SC_FLUSH_STATE_DIR_TYPE,    // NANDPrivateGetTypeAsync() on the config dir
    SC_FLUSH_STATE_CREATE_DIR,  // NANDPrivateCreateDirAsync()
    SC_FLUSH_STATE_CREATE_FILE, // NANDPrivateCreateAsync()
    SC_FLUSH_STATE_OPEN_FILE,   // NANDPrivateOpenAsync()
    SC_FLUSH_STATE_WRITE_FILE,  // NANDWriteAsync()
    SC_FLUSH_STATE_CLOSE_FILE,  // NANDCloseAsync()
    SC_FLUSH_STATE_CLOSED       // NANDCloseAsync() after an error
} SCFlushState;

typedef enum {
    SC_CONF_FILE_SYSTEM,  // SYSCONF
    SC_CONF_FILE_PRODUCT, // setting.txt
    SC_CONF_FILE_MAX
} SCConfFile;

typedef enum {
    SC_ITEM_BIGARRAY = (1 << 5),
    SC_ITEM_SMALLARRAY = (2 << 5),
    SC_ITEM_BYTE = (3 << 5),
    SC_ITEM_SHORT = (4 << 5),
    SC_ITEM_LONG = (5 << 5),
    SC_ITEM_LONGLONG = (6 << 5),
    SC_ITEM_BOOL = (7 << 5)
} SCItemType;

typedef void (*SCAsyncCallback)(s32 result);

typedef struct SCConfHeader {
    u32 magic;         // at 0x0
    u16 numItems;      // at 0x4
    u16 itemOffsets[]; // at 0x6
} SCConfHeader;

typedef struct SCConfItem {
    // & 00011111 -> name length (-1)
    // & 11100000 -> item type
    u8 desc;     // at 0x0
    char name[]; // at 0x4
} SCConfItem;

typedef struct SCControl {
    OSThreadQueue threadQueue;     // at 0x0
    NANDFileInfo fileInfo;         // at 0x8
    struct {
        u8 _[0xB8]; // NANDCommandBlock without the 8-byte oldSdkPad
    } commandBlock; // at 0x94
    union {
        NANDStatus fileAttr;
        u8 fileType;
    }; // at 0x14C
    u8 nandCbState;                          // at 0x154
    u8 isFileOpen;                           // at 0x155
    u8 openFileType;                         // at 0x156
    SCAsyncCallback asyncCallback;           // at 0x158
    s32 asyncResult;                         // at 0x15C
    const char* filePaths[SC_CONF_FILE_MAX]; // at 0x160
    u8* fileBuffers[SC_CONF_FILE_MAX];       // at 0x168
    u32 bufferSizes[SC_CONF_FILE_MAX];       // at 0x170
    u32 fileSizes[SC_CONF_FILE_MAX];         // at 0x178
    SCFlushCallback flushCallback;           // at 0x180
    SCStatus flushStatus;                    // at 0x184
    u32 flushSize;                           // at 0x188
    u32 unk18C;                              // at 0x18C
} SCControl;

typedef struct SCNameAndID {
    const char* name; // at 0x0
    SCItemID id;      // at 0x4
} SCNameAndID;

typedef struct SCItem {
    char UNK_0x0[0x8];
    u8 primType;      // at 0x8
    u8 arrayType;     // at 0x9
    u32 nameLen;      // at 0xC
    u32 dataLen;      // at 0x10
    const char* name; // at 0x14
    u8* data;         // at 0x18
    u32 itemLen;      // at 0x1C
} SCItem;

#pragma push
#pragma small_data on
extern const char* __SCVersion;
extern char s_SCv0[5];
extern char s_SCed[5];
#pragma small_data off
#pragma pop

static SCControl Control;
static u8 ConfBuf[SC_CONF_MAX_SIZE] ALIGN(32);
static u8 ConfBufForFlush[SC_CONF_MAX_SIZE] ALIGN(32);

extern const char s_SC_ConfDir[]; // "/shared2/sys"
extern const char ConfFileName[]; // "/shared2/sys/SYSCONF"
extern const char ProductInfoFileName[]; // "/title/00000001/00000002/data/setting.txt"

static u8 BgJobStatus = SC_STATUS_OK;

static u32 ItemRestSize = 0;
static u32 ItemNumTotal = 0;
static u32 ItemIDMaxPlus1 = 0;
static u32 ItemIDOffsetTblOffset = 0;

static u8 IsDevKit = FALSE;
static u8 DirtyFlag = FALSE;
static u8 Initialized = FALSE;

// Pooled item-name strings (live in shared sdata/data auto units; referenced via extern).
extern const char s_ipldcb[];  // "IPL.CB"
extern const char s_iplar[];   // "IPL.AR"
extern const char s_iplarn[];  // "IPL.ARN"
extern const char s_ipldh[];   // "IPL.DH"
extern const char s_iplE60[];  // "IPL.E60"
extern const char s_ipidl[];   // "IPL.IDL"
extern const char s_ipllng[];  // "IPL.LNG"
extern const char s_iplnik[];  // "IPL.NIK"
extern const char s_iplpc[];   // "IPL.PC"
extern const char s_iplpgs[];  // "IPL.PGS"
extern const char s_iplssv[];  // "IPL.SSV"
extern const char s_iplsadr[]; // "IPL.SADR"
extern const char s_iplsnd[];  // "IPL.SND"
extern const char s_netcnf[];  // "NET.CNF"
extern const char s_netctpc[]; // "NET.CTPC"
extern const char s_netprof[]; // "NET.PROF"
extern const char s_netwcpc[]; // "NET.WCPC"
extern const char s_devbtm[];  // "DEV.BTM"
extern const char s_devvim[];  // "DEV.VIM"
extern const char s_devctc[];  // "DEV.CTC"
extern const char s_devdsm[];  // "DEV.DSM"
extern const char s_btdinf[];  // "BT.DINF"
extern const char s_btsens[];  // "BT.SENS"
extern const char s_btspkv[];  // "BT.SPKV"
extern const char s_btmot[];   // "BT.MOT"
extern const char s_btbar[];   // "BT.BAR"
extern const char s_dvdcnf[];  // "DVD.CNF"
extern const char s_wwwrst[];  // "WWW.RST"

static SCNameAndID NameAndIDTbl[SC_ITEM_MAX] = {
    {s_ipldcb, SC_ITEM_IPL_CB},     {s_iplar, SC_ITEM_IPL_AR},
    {s_iplarn, SC_ITEM_IPL_ARN},    {s_ipldh, SC_ITEM_IPL_DH},
    {s_iplE60, SC_ITEM_IPL_E60},    {s_ipidl, SC_ITEM_IPL_IDL},
    {s_ipllng, SC_ITEM_IPL_LNG},    {s_iplnik, SC_ITEM_IPL_NIK},
    {s_iplpc, SC_ITEM_IPL_PC},      {s_iplpgs, SC_ITEM_IPL_PGS},
    {s_iplssv, SC_ITEM_IPL_SSV},    {s_iplsadr, SC_ITEM_IPL_SADR},
    {s_iplsnd, SC_ITEM_IPL_SND},    {s_netcnf, SC_ITEM_NET_CNF},
    {s_netctpc, SC_ITEM_NET_CTPC},  {s_netprof, SC_ITEM_NET_PROF},
    {s_netwcpc, SC_ITEM_NET_WCPC},  {s_devbtm, SC_ITEM_DEV_BTM},
    {s_devvim, SC_ITEM_DEV_VIM},    {s_devctc, SC_ITEM_DEV_CTC},
    {s_devdsm, SC_ITEM_DEV_DSM},    {s_btdinf, SC_ITEM_BT_DINF},
    {s_btsens, SC_ITEM_BT_SENS},    {s_btspkv, SC_ITEM_BT_SPKV},
    {s_btmot, SC_ITEM_BT_MOT},      {s_btbar, SC_ITEM_BT_BAR},
    {s_dvdcnf, SC_ITEM_DVD_CNF},    {s_wwwrst, SC_ITEM_WWW_RST}};

static void SetBgJobStatus(SCStatus status);
static s32 SCReloadConfFileAsync(u8* buf, u32 size, SCAsyncCallback callback);
static void OpenCallbackFromReload(s32 result, NANDCommandBlock* block);
static void ReadCallbackFromReload(s32 result, NANDCommandBlock* block);
static void CloseCallbackFromReload(s32 result, NANDCommandBlock* block);
static void FinishFromReload(void);
static void ErrorFromReload(s32 result);
static void CloseCallbackFromReloadError(s32 result, NANDCommandBlock* block);
static void ClearConfBuf(u8* conf);
static SCStatus ParseConfBuf(u8* conf, u32 size);
static BOOL ParseGetBEValue(const u8* start, const u8* end, u32* out, u32 size);
static BOOL UnpackItem(const SCConfItem* raw, SCItem* item);
static void MyNandCallback(s32 result, NANDCommandBlock* block);
static void FinishFromFlush(void);
static void ErrorFromFlush(void);

static BOOL __SCIsDirty(void);
static void __SCSetDirtyFlag(void);
static void __SCClearDirtyFlag(void);
static u8* __SCGetConfBuf(void);
static u32 __SCGetConfBufSize(void);

void SCInit(void) {
    BOOL enabled = OSDisableInterrupts();

    if (Initialized) {
        OSRestoreInterrupts(enabled);
        return;
    }

    Initialized = TRUE;

    SetBgJobStatus(SC_STATUS_BUSY);
    OSRestoreInterrupts(enabled);

    OSRegisterVersion(__SCVersion);
    OSInitThreadQueue(&Control.threadQueue);

    if (OSGetConsoleType() & OS_CONSOLE_MASK_EMU) {
        IsDevKit = TRUE;
    }

    if (NANDInit() != NAND_RESULT_OK ||
        SCReloadConfFileAsync(__SCGetConfBuf(), __SCGetConfBufSize(), NULL) !=
            NAND_RESULT_OK) {

        SetBgJobStatus(SC_STATUS_FATAL);
    }
}

static void SetBgJobStatus(SCStatus status) {
    BgJobStatus = status;
}

u32 SCCheckStatus(void) {
    BOOL enabled;
    u32 status;

    /* Poll background SC job status; when parse is pending, parse/copy or clear the system config buffer. */
    enabled = OSDisableInterrupts();
    status = BgJobStatus;

    if (status == SC_STATUS_PARSE) {
        BgJobStatus = SC_STATUS_BUSY;
        OSRestoreInterrupts(enabled);

        if (ParseConfBuf(Control.fileBuffers[SC_CONF_FILE_SYSTEM],
                         Control.fileSizes[SC_CONF_FILE_SYSTEM]) == 0) {
            if (ConfBuf != Control.fileBuffers[SC_CONF_FILE_SYSTEM]) {
                memcpy(ConfBuf, Control.fileBuffers[SC_CONF_FILE_SYSTEM],
                       SC_CONF_MAX_SIZE);
            }
        } else {
            ClearConfBuf(Control.fileBuffers[SC_CONF_FILE_SYSTEM]);
        }

        DirtyFlag = FALSE;
        BgJobStatus = SC_STATUS_OK;
        status = SC_STATUS_OK;
    } else {
        OSRestoreInterrupts(enabled);
    }

    return status;
}

static s32 SCReloadConfFileAsync(u8* buf, u32 size, SCAsyncCallback callback) {
    int i;

    if (size < __SCGetConfBufSize()) {
        return NAND_RESULT_FATAL_ERROR;
    }

    SetBgJobStatus(SC_STATUS_BUSY);
    Control.asyncCallback = callback;
    Control.asyncResult = NAND_RESULT_OK;
    Control.openFileType = 0;

    for (i = 0; i < SC_CONF_FILE_MAX; i++) {
        Control.fileSizes[i] = 0;
    }

    Control.filePaths[SC_CONF_FILE_SYSTEM] = ConfFileName;
    Control.filePaths[SC_CONF_FILE_PRODUCT] = ProductInfoFileName;

    Control.fileBuffers[SC_CONF_FILE_SYSTEM] = buf;
    Control.fileBuffers[SC_CONF_FILE_PRODUCT] = OS_SC_PRDINFO;

    Control.bufferSizes[SC_CONF_FILE_SYSTEM] = __SCGetConfBufSize();
    Control.bufferSizes[SC_CONF_FILE_PRODUCT] = ARRAY_SIZE(OS_SC_PRDINFO);

    ClearConfBuf(buf);

    ItemIDOffsetTblOffset = 0;
    ItemNumTotal = 0;
    ItemRestSize = 0;

    Control.isFileOpen = FALSE;

    return NANDPrivateOpenAsync(Control.filePaths[Control.openFileType],
                                &Control.fileInfo, NAND_ACCESS_READ,
                                OpenCallbackFromReload, (NANDCommandBlock*)&Control.commandBlock);
}

static void OpenCallbackFromReload(s32 result, NANDCommandBlock* block) {
#pragma unused(block)

    if (result == NAND_RESULT_OK) {
        Control.isFileOpen = TRUE;

        if (NANDReadAsync(&Control.fileInfo,
                          Control.fileBuffers[Control.openFileType],
                          Control.bufferSizes[Control.openFileType],
                          ReadCallbackFromReload,
                          (NANDCommandBlock*)&Control.commandBlock) == NAND_RESULT_OK) {
            return;
        }
    }

    ErrorFromReload(result);
}

/* NAND read callback during config reload: on a full read, record size and close the file. */
static void ReadCallbackFromReload(s32 result, NANDCommandBlock* block) {
#pragma unused(block)

    if (result == Control.bufferSizes[Control.openFileType]) {
        Control.fileSizes[Control.openFileType] = result;
        Control.isFileOpen = FALSE;

        if (NANDCloseAsync(&Control.fileInfo, CloseCallbackFromReload,
                           (NANDCommandBlock*)&Control.commandBlock) == NAND_RESULT_OK) {
            return;
        }
    }

    ErrorFromReload(result != NAND_RESULT_OK ? result
                                             : NAND_RESULT_FATAL_ERROR);
}

static void CloseCallbackFromReload(s32 result, NANDCommandBlock* block) {
#pragma unused(block)

    if (result == NAND_RESULT_OK) {
        FinishFromReload();
    } else {
        ErrorFromReload(result);
    }
}

/* Completes SYSCONF reload by opening remaining files or finalizing parse status. */
static void FinishFromReload(void) {
    SCStatus status;

_openFile:
    Control.openFileType++;

    if (Control.openFileType < SC_CONF_FILE_MAX) {
        Control.isFileOpen = FALSE;

        if (NANDPrivateOpenAsync(Control.filePaths[Control.openFileType],
                                 &Control.fileInfo, NAND_ACCESS_READ,
                                 OpenCallbackFromReload,
                                 (NANDCommandBlock*)&Control.commandBlock) == NAND_RESULT_OK) {
            return;
        }

        goto _openFile;
    }

    switch (Control.asyncResult) {
    case NAND_RESULT_OK:
        status = SC_STATUS_PARSE;
        break;
    case NAND_RESULT_NOEXISTS:
        ClearConfBuf(Control.fileBuffers[SC_CONF_FILE_SYSTEM]);

        Control.fileSizes[SC_CONF_FILE_SYSTEM] =
            Control.bufferSizes[SC_CONF_FILE_SYSTEM];

        status = SC_STATUS_PARSE;
        break;
    default:
        status = SC_STATUS_FATAL;
        break;
    }

    OS_SC_PRDINFO[ARRAY_SIZE(OS_SC_PRDINFO) - 1] = '\0';

    if (Control.asyncCallback != NULL) {
        Control.asyncCallback(Control.asyncResult);
        Control.asyncCallback = NULL;
    }

    SetBgJobStatus(status);
}

static void ErrorFromReload(s32 result) {
    if (Control.openFileType == SC_CONF_FILE_SYSTEM) {
        Control.asyncResult = result;
    }

    Control.fileSizes[Control.openFileType] = 0;

    if (!Control.isFileOpen ||
        NANDCloseAsync(&Control.fileInfo, CloseCallbackFromReloadError,
                       (NANDCommandBlock*)&Control.commandBlock) != NAND_RESULT_OK) {
        FinishFromReload();
    }
}

static void CloseCallbackFromReloadError(s32 result, NANDCommandBlock* block) {
#pragma unused(result)
#pragma unused(block)

    FinishFromReload();
}

static void ClearConfBuf(u8* conf) {
    u8* end;
    u32 size;
    SCConfHeader* header;

    header = (SCConfHeader*)conf;
    size = __SCGetConfBufSize();
    memset(conf, 0, size);

    if (size > SC_CONF_MIN_SIZE) {
        memcpy(conf, SC_CONF_BEGIN_MAGIC, 4);

        end = conf + size - sizeof(u32);
        memcpy(end, SC_CONF_END_MAGIC, 4);

        header->itemOffsets[0] = sizeof(SCConfHeader);
    }
}

/*
 * Validate a SYSCONF image read from NAND and build its lookup table.
 *
 * Checks both magics, walks every item through the header's offset table to
 * make sure each one sits exactly where the table says and unpacks, then
 * searches the items for each name in NameAndIDTbl and records, at
 * confLutBase[-id], the offset of that item's offset entry. Returns
 * SC_STATUS_FATAL on any problem, which makes the caller start over with a
 * cleared buffer.
 */
static SCStatus ParseConfBuf(u8* conf, u32 size) {
    int i;

    u8* confBegin;    // first byte of the image
    u8* confEnd;      // first byte of the trailing magic
    u32 itemOffset;   // offset of the item being walked

    u32 numItems;     // item count from the header
    u16* itemOffsets; // SCConfHeader::itemOffsets, one offset per item
    u32 restSize;     // free bytes between the items and the lookup table

    u8* confLutStart; // lookup table's lowest address
    u8* confLutBase;  // entry for ID 0; the table grows downward from here

    SCNameAndID* nameAndId;    // walk of NameAndIDTbl
    SCNameAndID* nameAndIdEnd;
    const char* name;          // name to look up

    nameAndId = NameAndIDTbl;

    // Config parameters

    if (size < SC_CONF_MIN_SIZE) {
        goto _error;
    }

    if (size > __SCGetConfBufSize()) {
        goto _error;
    }

    confBegin = conf;
    confEnd = conf + size - sizeof(u32);
    ItemIDMaxPlus1 = SC_ITEM_MAX;

    // File magic

    if (memcmp(conf, SC_CONF_BEGIN_MAGIC, sizeof(u32)) != 0) {
        goto _error;
    }

    if (memcmp(confEnd, SC_CONF_END_MAGIC, sizeof(u32)) != 0) {
        goto _error;
    }

    conf += sizeof(u32);

    // The file may be shorter than the buffer: clear the rest of it and move
    // the trailing magic down to the end of the whole buffer.
    if (size < __SCGetConfBufSize()) {
        u32 confRest = __SCGetConfBufSize() - size;
        memset(confEnd, 0, confRest);
        confEnd += confRest;
        memcpy(confEnd, SC_CONF_END_MAGIC, sizeof(u32));
    }

    // Item count

    if (!ParseGetBEValue(conf, confEnd, &numItems, sizeof(u16))) {
        goto _error;
    }

    conf += sizeof(u16);

    // Item data; the first item follows the offset table and the terminator
    // entry that points past the last item.

    itemOffsets = (u16*)conf;
    itemOffset = (u8*)(itemOffsets + numItems + 1) - confBegin;

    for (i = 0; i < numItems; i++) {
        SCItem item;

        if (itemOffset > size) {
            goto _error;
        }

        if ((u8*)&itemOffsets[i] - confBegin > size) {
            goto _error;
        }

        if (itemOffset != itemOffsets[i]) {
            goto _error;
        }

        if (!UnpackItem((SCConfItem*)(confBegin + itemOffset), &item)) {
            goto _error;
        }

        itemOffset += item.itemLen;
    }

    // i is the terminator entry here
    if (itemOffset > size || itemOffset != itemOffsets[i]) {
        goto _error;
    }

    // Item lookup table

    confLutStart = confEnd - (SC_ITEM_MAX - 1) * sizeof(u16);

    if (confBegin + itemOffset > confLutStart) {
        goto _error;
    }

    restSize = confLutStart - (confBegin + itemOffset);
    memset(confLutStart, 0, confEnd - confLutStart);

    // First LUT entry (grows upward)
    confLutBase = confEnd - sizeof(u16);

    // Build lookup table

    for (nameAndIdEnd = &nameAndId[ItemIDMaxPlus1];
         nameAndId < nameAndIdEnd && (name = nameAndId->name) != (void*)NULL;
         nameAndId++) {

        u32 nameLen = strlen(name);

        for (i = 0; i < numItems; i++) {
            SCConfItem* rawItem = (SCConfItem*)(confBegin + itemOffsets[i]);

            // Item length doesn't include terminator
            if (nameLen != (rawItem->desc & SC_ITEM_NAME_LEN_MAX) + 1) {
                continue;
            }

            if (memcmp(name, rawItem->name, nameLen) != 0) {
                continue;
            }

            // LUT items are in reverse order
            ((u16*)confLutBase)[-nameAndId->id] =
                (u8*)(itemOffsets + i) - confBegin;

            break;
        }
    }

    ItemIDOffsetTblOffset = confLutBase - confBegin;
    ItemNumTotal = numItems;
    ItemRestSize = restSize;
    return SC_STATUS_OK;

_error:
    return SC_STATUS_FATAL;
}

static BOOL ParseGetBEValue(const u8* start, const u8* end, u32* out,
                            u32 size) {
    u32 imm = 0;

    if (start + size > end) {
        return FALSE;
    }

    for (; size > 0; start++, size--) {
        imm = imm << 8 | *start;
    }

    *out = imm;
    return TRUE;
}

/* Unpacks a raw SYSCONF item record into the parsed SCItem form used by lookups.
 * Decodes the descriptor/type, locates name/data payloads, computes lengths, and
 * copies primitive values into item storage. Returns TRUE when a non-empty data
 * payload was decoded. */
static BOOL UnpackItem(const SCConfItem* rawItem, SCItem* item) {
    u8 itemType;

    memset(item, 0, sizeof(SCItem));
    itemType = rawItem->desc & 0b11100000;
    item->name = rawItem->name;
    item->nameLen = (rawItem->desc & 0b00011111) + 1;
    item->data = (u8*)rawItem + item->nameLen + 1;

    switch (itemType) {
    case SC_ITEM_BYTE:
    case SC_ITEM_BOOL:
        item->dataLen = sizeof(u8);
        break;
    case SC_ITEM_SHORT:
        item->dataLen = sizeof(u16);
        break;
    case SC_ITEM_LONG:
        item->dataLen = sizeof(u32);
        break;
    case SC_ITEM_LONGLONG:
        item->dataLen = sizeof(u64);
        break;
    case SC_ITEM_SMALLARRAY:
        item->dataLen = *item->data + sizeof(u8);
        item->data = item->data + sizeof(u8);
        item->itemLen += sizeof(u8);
        break;
    case SC_ITEM_BIGARRAY:
        item->dataLen = (item->data[0] << 8 | item->data[1]) + sizeof(u8);
        item->data = item->data + sizeof(u16);
        item->itemLen += sizeof(u16);
        break;
    default:
        goto _exit;
    }

    if (itemType == SC_ITEM_SMALLARRAY || itemType == SC_ITEM_BIGARRAY) {
        item->arrayType = SC_ITEM_SMALLARRAY;
    } else {
        item->primType = itemType;
        memcpy(item, item->data, item->dataLen);
    }

    item->itemLen += item->nameLen + item->dataLen + sizeof(u8);

_exit:
    return item->dataLen != 0;
}

static BOOL FindItemByID(SCItemID id, SCItem* item) {
    u8* conf;
    u16* ofsTbl;
    u16 itemOfsOfs;

    conf = __SCGetConfBuf();
    if (id < ItemIDMaxPlus1 && ItemIDOffsetTblOffset > 0) {
        ofsTbl = (u16*)(conf + ItemIDOffsetTblOffset);

        // LUT items are in reverse order
        itemOfsOfs = ofsTbl[-id];

        if (itemOfsOfs > 0) {
            return UnpackItem((SCConfItem*)(conf + *(u16*)(conf + itemOfsOfs)),
                              item);
        }
    }

    return FALSE;
}

static void DeleteItemByID(SCItemID itemId) {
    u8* conf;
    u16* itemOfs;
    u32 itemOfsOfs;
    u32 itemsEndOfs;
    u32 itemSize;
    u16* confLut;
    u16* confItemsBegin;
    u16* confItemsEnd;
    u32 sp14;
    u16* it;
    int i;

    /* Removes an SC config item by ID, compacts item data/offsets, updates the ID lookup table, and marks the config dirty. */
    conf = __SCGetConfBuf();

    if (itemId >= ItemIDMaxPlus1) {
        return;
    }

    if (ItemIDOffsetTblOffset == 0) {
        return;
    }

    confLut = (u16*)(conf + ItemIDOffsetTblOffset);
    // LUT items are in reverse order
    itemOfsOfs = confLut[-itemId];

    if (itemOfsOfs == 0) {
        return;
    }

    if (ItemNumTotal == 0) {
        return;
    }

    confItemsBegin = ((SCConfHeader*)conf)->itemOffsets;

    // LUT -> Item offset -> Item data
    itemOfs = (u16*)(conf + itemOfsOfs);

    // Last offset -> past end of items
    confItemsEnd = &confItemsBegin[ItemNumTotal];
    itemsEndOfs = *confItemsEnd;

    // Offset from next item
    itemSize = itemOfs[1] - itemOfs[0] + sizeof(u16);

    sp14 = *itemOfs - (itemOfsOfs + sizeof(u16));
    memmove(conf + itemOfsOfs, conf + itemOfsOfs + sizeof(u16), sp14);

    // Adjust item offsets
    for (it = confItemsEnd - 1; it >= confItemsBegin; it--) {
        if (it < itemOfs) {
            // After deleted item
            *it -= sizeof(u16);
        } else {
            // Before deleted item
            *it -= itemSize;
        }
    }

    memmove(conf + *itemOfs, conf + itemSize + *itemOfs,
            itemsEndOfs - (*itemOfs + itemSize));

    memset(conf + (itemsEndOfs - itemSize), 0, itemSize);

    // Adjust item lookup table
    for (i = 0; i < ItemIDMaxPlus1; i++) {
        // Before deleted slot
        if (confLut[-i] < itemOfsOfs) {
            continue;
        }

        // After deleted slot
        if (confLut[-i] > itemOfsOfs) {
            confLut[-i] -= sizeof(u16);
        } else {
            confLut[-i] = 0;
        }
    }

    ItemRestSize += itemSize;
    ItemNumTotal--;
    ((SCConfHeader*)conf)->numItems = ItemNumTotal;
    __SCSetDirtyFlag();
}

/* Adds a SYSCONF item under an ID, in the shape UnpackItem() reads back: a
 * descriptor byte (the item type, with the name's length minus one in its low
 * five bits), the name, an array's length minus one (one byte, or two once the
 * item outgrows a small array and is stored as a big one) and the data.  The
 * item goes at the end of the configuration's item area, so its slot in the
 * header's offset table is made by shifting every item two bytes up and adding
 * sizeof(u16) to every stored offset; the ID's entry in the lookup table, which
 * runs backwards from ItemIDOffsetTblOffset, then points at that slot.  FALSE
 * means the ID, the source or the length was rejected, or the buffer has no
 * room left for the item. */
static BOOL CreateItemByID(SCItemID id, u8 primType, const void* src, u32 len) {
    u8* conf;
    u32 itemNameLen;
    u32 itemSize;
    u32 itemsEndOfs;
    const char* itemName;
    u8* newItem;
    u16* confItemsBegin;
    u16* confItemsEnd;
    u16* confLut;
    SCNameAndID* it;
    u16* ofsIter;

    conf = __SCGetConfBuf();
    // the item's descriptor byte
    itemSize = 1;
    it = NameAndIDTbl;

    if (id >= ItemIDMaxPlus1) {
        goto _error;
    }

    if (src == (void*)NULL) {
        goto _error;
    }

    if (ItemNumTotal >= SC_ITEM_MAX_NUM) {
        goto _error;
    }

    // no room left in the buffer for the lookup table yet
    if (ItemIDOffsetTblOffset == 0) {
        goto _error;
    }

    // An array keeps its length; a primitive's length comes from its type.
    switch (primType) {
    case SC_ITEM_BYTE:
    case SC_ITEM_BOOL:
        len = sizeof(u8);
        break;
    case SC_ITEM_SHORT:
        len = sizeof(u16);
        break;
    case SC_ITEM_LONG:
        len = sizeof(u32);
        break;
    case SC_ITEM_LONGLONG:
        len = sizeof(u64);
        break;
    case SC_ITEM_SMALLARRAY:
        if (len == 0) {
            goto _error;
        }

        // Length is stored minus one
        if (len > SC_BIGARRAY_MAX + 1) {
            goto _error;
        }

        // Length is stored minus one
        if (len > SC_SMALLARRAY_MAX + 1) {
            // two length bytes instead of one, and the type changes
            itemSize += 2;
            primType = SC_ITEM_BIGARRAY;
        } else {
            itemSize += 1;
        }
        break;
    default:
        goto _error;
    }

    itemSize += len;

    // The name is whatever the item table registers under that ID.
    for (; (itemName = it->name) != (void*)NULL; it++) {
        if (it->id == id) {
            break;
        }
    }

    if (itemName == (void*)NULL) {
        goto _error;
    }

    // Only five bits reserved for name length (minus one)
    itemNameLen = strlen(itemName);
    if (itemNameLen > SC_ITEM_NAME_LEN_MAX + 1) {
        goto _error;
    }

    itemSize += itemNameLen;
    // the item itself and its new offset table slot
    if (ItemRestSize < itemSize + sizeof(u16)) {
        goto _error;
    }

    confItemsBegin = ((SCConfHeader*)conf)->itemOffsets;
    // the table's last entry is the offset past the end of the items
    confItemsEnd = &confItemsBegin[ItemNumTotal];
    itemsEndOfs = *confItemsEnd;

    // Make room for new item
    memmove(confItemsBegin[0] + sizeof(u16) + conf, confItemsBegin[0] + conf,
            itemsEndOfs - confItemsBegin[0]);

    // Adjust offsets
    ofsIter = confItemsBegin;
    do {
        *ofsIter++ += sizeof(u16);
    } while (ofsIter <= confItemsEnd);

    // The new item is appended, and takes the offset slot just made for it.
    itemsEndOfs = *confItemsEnd;
    newItem = conf + itemsEndOfs;

    *newItem = primType | (itemNameLen - 1);
    memcpy(newItem + 1, itemName, itemNameLen);
    newItem += itemNameLen + 1;

    if (primType == SC_ITEM_SMALLARRAY) {
        *newItem++ = len - 1;
    } else if (primType == SC_ITEM_BIGARRAY) {
        *newItem++ = (len - 1) >> 8 & 0xFF;
        *newItem++ = (len - 1) >> 0 & 0xFF;
    }

    memcpy(newItem, src, len);
    newItem += len;

    // The ID's lookup entry points at the item's offset slot, and that slot
    // gains the end offset of the item just written.
    confLut = (u16*)(conf + ItemIDOffsetTblOffset);
    confLut[-id] = (u8*)confItemsEnd - conf;
    confItemsEnd[1] = confItemsEnd[0] + itemSize;

    ItemRestSize -= itemSize + sizeof(u16);
    ItemNumTotal++;
    ((SCConfHeader*)conf)->numItems = ItemNumTotal;
    __SCSetDirtyFlag();
    return TRUE;

_error:
    return FALSE;
}

BOOL SCFindByteArrayItem(void* dstBuffer, u32 itemLength, SCItemID itemId) {
    BOOL found;
    BOOL interruptsEnabled;
    SCItem confItem;

    /* Finds a byte-array SC item by ID and copies its contents into dstBuffer when lengths match. */
    found = FALSE;
    interruptsEnabled = OSDisableInterrupts();

    if (dstBuffer != ((void*)NULL) && FindItemByID(itemId, &confItem) &&
        confItem.arrayType != 0 && confItem.dataLen == itemLength) {
        memcpy(dstBuffer, confItem.data, itemLength);
        found = TRUE;
    }

    OSRestoreInterrupts(interruptsEnabled);
    return found;
}

BOOL SCReplaceByteArrayItem(const void* src, u32 len, SCItemID id) {
    BOOL success;
    BOOL enabled;
    SCItem item;

    /* Replaces an existing small byte-array SC item with new data, creating it if missing. */
    success = FALSE;
    enabled = OSDisableInterrupts();

    if (src != ((void*)NULL)) {
        if (FindItemByID(id, &item)) {
            if (item.arrayType != 0 && item.dataLen == len) {
                if (memcmp(item.data, src, len) != 0) {
                    memcpy(item.data, src, len);
                    __SCSetDirtyFlag();
                }

                success = TRUE;
                goto _exit;

            } else {
                DeleteItemByID(id);
            }
        }

        success = CreateItemByID(id, SC_ITEM_SMALLARRAY, src, len);
    }

_exit:
    OSRestoreInterrupts(enabled);
    return success;
}

static BOOL SCFindIntegerItem(void* dst, SCItemID id, u8 primType) {
    BOOL success;
    BOOL enabled;
    SCItem item;

    success = FALSE;
    enabled = OSDisableInterrupts();

    if (FindItemByID(id, &item) && item.primType == primType) {
        memcpy(dst, item.data, item.dataLen);
        success = TRUE;
    }

    OSRestoreInterrupts(enabled);
    return success;
}

static BOOL SCReplaceIntegerItem(const void* src, SCItemID id, u8 primType) DECOMP_DONT_INLINE {
    /* Replace a System Config item's integer value by ID; copies if changed, or recreates the item if its primitive type differs. */
    BOOL success;
    BOOL interrupts;
    SCItem item;

    success = FALSE;
    interrupts = OSDisableInterrupts();

    if (FindItemByID(id, &item)) {
        if (item.primType == primType) {
            if (memcmp(item.data, src, item.dataLen) != 0) {
                memcpy(item.data, src, item.dataLen);
                __SCSetDirtyFlag();
            }

            success = TRUE;
            goto _exit;

        } else {
            DeleteItemByID(id);
        }
    }

    success = CreateItemByID(id, primType, src, 0);

_exit:
    OSRestoreInterrupts(interrupts);
    return success;
}

BOOL SCFindU8Item(u8* dst, SCItemID id) {
    /* Read an 8-bit (unsigned byte) System Config item's value by ID into *dst. */
    return SCFindIntegerItem(dst, id, SC_ITEM_BYTE);
}

BOOL SCFindS8Item(s8* dst, SCItemID id) {
    return SCFindIntegerItem(dst, id, SC_ITEM_BYTE);
}

BOOL SCFindU32Item(u32* dst, SCItemID id) {
    return SCFindIntegerItem(dst, id, SC_ITEM_LONG);
}

BOOL SCReplaceU8Item(u8 data, SCItemID id) {
    return SCReplaceIntegerItem(&data, id, SC_ITEM_BYTE);
}

void __SCFlushSyncCallback(SCStatus status) {
#pragma unused(status)

    OSWakeupThread(&Control.threadQueue);
}

// Writes the SYSCONF image in ConfBuf out to NAND, without blocking the caller.
// The write is a chain of asynchronous NAND operations (see MyNandCallback and
// the SCFlushState steps): this function queues the first one, asking what
// /shared2/sys/SYSCONF is, and the callback queues the rest.  Nothing is
// written when the image was not changed since the last flush.  callback gets
// the SCStatus of the flush when it is done; passing NULL installs
// __SCFlushSyncCallback(), which wakes this thread instead, so that
// SCFlush() can wait here.  Only one background job runs at a time: while one
// is going, this reports its status and does nothing else.
void SCFlushAsync(SCFlushCallback callback) {
    SCControl* ctrl;
    BOOL enabled;
    u8 status;

    ctrl = &Control;
    enabled = OSDisableInterrupts();
    status = BgJobStatus;

    if (status == SC_STATUS_OK) {
        // claim the background job before dropping the lock
        SetBgJobStatus(SC_STATUS_BUSY);

        if (callback == ((void*)NULL)) {
            callback = __SCFlushSyncCallback;
        }

        ctrl->flushCallback = callback;
        ctrl->flushStatus = SC_STATUS_OK;
        ctrl->isFileOpen = FALSE;
        ctrl->flushSize = __SCGetConfBufSize();

        if (!__SCIsDirty()) {
            // the file already holds what the buffer holds: done
            OSRestoreInterrupts(enabled);
            FinishFromFlush();
        } else {
            __SCClearDirtyFlag();
            // the NAND chain writes ConfBufForFlush, so later changes to
            // ConfBuf are not lost halfway through the flush
            memcpy(ConfBufForFlush, __SCGetConfBuf(), __SCGetConfBufSize());

            OSRestoreInterrupts(enabled);
            ctrl->nandCbState = SC_FLUSH_STATE_FILE_TYPE;

            // fileType is the union member of the NANDStatus this fills in
            if (NANDPrivateGetTypeAsync(ConfFileName, &ctrl->fileType,
                                        MyNandCallback, (NANDCommandBlock*)&ctrl->commandBlock) !=
                NAND_RESULT_OK) {
                ErrorFromFlush();
            }
        }
    } else {
        // another job is busy: report it, anything else is a dead SC module
        if (callback != NULL) {
            callback(status == SC_STATUS_BUSY ? status : SC_STATUS_FATAL);
        }

        OSRestoreInterrupts(enabled);
    }
}

// NAND completion callback for the whole SYSCONF write started by SCFlushAsync().
// Every time one of the queued NAND operations finishes, this runs the step for
// the operation Control.nandCbState was waiting on: it checks the result, then
// queues the next operation (or finishes/errors out through FinishFromFlush()
// and ErrorFromFlush()). The file is recreated from scratch when it is missing
// or not readable/writable by everyone, creating /shared2/sys as needed.
static void MyNandCallback(s32 result, NANDCommandBlock* block) {
#pragma unused(block)

    SCControl* ctrl = &Control;

    switch (ctrl->nandCbState) {
    case SC_FLUSH_STATE_FILE_TYPE: // SYSCONF's type is known
        if (result == NAND_RESULT_OK && ctrl->fileType == NAND_FILE_TYPE_FILE) {
            ctrl->nandCbState = SC_FLUSH_STATE_FILE_STATUS;

            if (NANDPrivateGetStatusAsync(
                    ConfFileName, &ctrl->fileAttr, MyNandCallback,
                    (NANDCommandBlock*)&ctrl->commandBlock) != NAND_RESULT_OK) {
                goto error;
            }
        } else {
            goto delete_conf_file;
        }
        return;

    case SC_FLUSH_STATE_FILE_STATUS: // SYSCONF's permissions are known
        if (result == NAND_RESULT_OK &&
            ctrl->fileAttr.perm == NAND_PERM_RWALL) {
            goto open_conf_file; // usable as is
        }
        // wrong permissions: delete it and create a new one
    delete_conf_file:
        ctrl->nandCbState = SC_FLUSH_STATE_DELETE_FILE;

        if (NANDPrivateDeleteAsync(ConfFileName, MyNandCallback,
                                   (NANDCommandBlock*)&ctrl->commandBlock) != NAND_RESULT_OK) {
            goto error;
        }
        return;

    case SC_FLUSH_STATE_DELETE_FILE: // SYSCONF is gone
        ctrl->nandCbState = SC_FLUSH_STATE_DIR_TYPE;

        if (NANDPrivateGetTypeAsync(s_SC_ConfDir, &ctrl->fileType,
                                    MyNandCallback,
                                    (NANDCommandBlock*)&ctrl->commandBlock) != NAND_RESULT_OK) {
            goto error;
        }
        return;

    case SC_FLUSH_STATE_DIR_TYPE: // the config directory's type is known
        if (result == NAND_RESULT_OK && ctrl->fileType == NAND_FILE_TYPE_DIR) {
            goto create_conf_file;
        }

        ctrl->nandCbState = SC_FLUSH_STATE_CREATE_DIR;

        if (NANDPrivateCreateDirAsync(s_SC_ConfDir, NAND_PERM_RWALL, 0,
                                      MyNandCallback,
                                      (NANDCommandBlock*)&ctrl->commandBlock) != NAND_RESULT_OK) {
            goto error;
        }
        return;

    case SC_FLUSH_STATE_CREATE_DIR: // the config directory exists now
    create_conf_file:
        ctrl->nandCbState = SC_FLUSH_STATE_CREATE_FILE;
        if (NANDPrivateCreateAsync(ConfFileName, NAND_PERM_RWALL, 0,
                                   MyNandCallback,
                                   (NANDCommandBlock*)&ctrl->commandBlock) != NAND_RESULT_OK) {
            goto error;
        }
        return;

    case SC_FLUSH_STATE_CREATE_FILE: // SYSCONF exists now
    open_conf_file:
        ctrl->nandCbState = SC_FLUSH_STATE_OPEN_FILE;
        if (NANDPrivateOpenAsync(ConfFileName, &ctrl->fileInfo,
                                 NAND_ACCESS_WRITE, MyNandCallback,
                                 (NANDCommandBlock*)&ctrl->commandBlock) != NAND_RESULT_OK) {
            goto error;
        }
        return;

    case SC_FLUSH_STATE_OPEN_FILE: // SYSCONF is open for writing
        if (result != NAND_RESULT_OK) {
            goto error;
        }

        ctrl->isFileOpen = TRUE;
        ctrl->nandCbState = SC_FLUSH_STATE_WRITE_FILE;

        if (NANDWriteAsync(&ctrl->fileInfo, ConfBufForFlush, ctrl->flushSize,
                           MyNandCallback,
                           (NANDCommandBlock*)&ctrl->commandBlock) != NAND_RESULT_OK) {
            goto error;
        }
        return;

    case SC_FLUSH_STATE_WRITE_FILE: // the whole buffer is written
        if (result != ctrl->flushSize) {
            goto error;
        }

        ctrl->isFileOpen = FALSE;
        ctrl->nandCbState = SC_FLUSH_STATE_CLOSE_FILE;

        if (NANDCloseAsync(&ctrl->fileInfo, MyNandCallback,
                           (NANDCommandBlock*)&ctrl->commandBlock) != NAND_RESULT_OK) {
            goto error;
        }
        return;

    case SC_FLUSH_STATE_CLOSE_FILE: // SYSCONF is closed
        if (result != NAND_RESULT_OK) {
            goto error;
        }
        // FALLTHROUGH

    case SC_FLUSH_STATE_CLOSED: // closed after an error
        FinishFromFlush();
        // FALLTHROUGH

    default:
        return;
    }

error:
    ErrorFromFlush();
}

static void FinishFromFlush(void) {
    SCControl* ctrl;
    SCFlushCallback callback;

    ctrl = &Control;
    if (ctrl->flushStatus != SC_STATUS_OK) {
        __SCSetDirtyFlag();
    }

    callback = ctrl->flushCallback;
    if (callback != NULL) {
        ctrl->flushCallback = NULL;
        callback(ctrl->flushStatus);

        if (ctrl->threadQueue.head != ((void*)NULL)) {
            OSWakeupThread(&ctrl->threadQueue);
        }
    }

    SetBgJobStatus(ctrl->flushStatus);
}

static void ErrorFromFlush(void) {
    SCControl* ctrl;

    ctrl = &Control;
    ctrl->flushStatus = SC_STATUS_FATAL;

    if (ctrl->isFileOpen) {
        ctrl->nandCbState = SC_FLUSH_STATE_CLOSED;

        if (NANDCloseAsync(&ctrl->fileInfo, MyNandCallback,
                           (NANDCommandBlock*)&ctrl->commandBlock) == NAND_RESULT_OK) {
            return;
        }
    }

    FinishFromFlush();
}

static BOOL __SCIsDirty(void) {
    return DirtyFlag ? TRUE : FALSE;
}

static void __SCSetDirtyFlag(void) {
    DirtyFlag = TRUE;
}

static void __SCClearDirtyFlag(void) {
    DirtyFlag = FALSE;
}

static u8* __SCGetConfBuf(void) {
    return ConfBuf;
}

static u32 __SCGetConfBufSize(void) {
    return SC_CONF_MAX_SIZE;
}
