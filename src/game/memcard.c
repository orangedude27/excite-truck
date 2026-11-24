// memcard — memory-card saves ("memcard: writing file", mcs_data).
// Recovered TU window 0x802E6B50..0x802E72B0 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E72B0 (+ .ctors slot 0x802ED608) remains in
// auto/text_802E72B0_.c pending a promotion pass.
extern void *memcpy(void *, const void *, unsigned long);
extern int lbl_8055FFC8;
/* The buffer printed as "%s" by the "chunk: %s (%x) %d bytes" log: the 4-byte
 * chunk ID followed by a NUL.  The symbol itself is a project placeholder. */
#define chunkIdString lbl_8055FFC8
extern unsigned char lbl_804FC8B0[];
extern int lbl_8055FFC0;
extern unsigned char lbl_8055FFC4;
extern unsigned char lbl_8055FFC5;
extern void *memset(void *, int, unsigned long);
extern void *fn_802E6FBC(void);
extern int fn_802E30C8(const char *, ...);
extern char lbl_8034D678[];
extern int lbl_8055D200;
extern void *fn_801284E8(void *, int);
extern void fn_80128658(void *);
extern unsigned int fn_80132E7C(void *, int);
extern void *fn_802E967C(int, void *, int);
extern int fn_802E7130(void);
extern int fn_802E721C(unsigned int, unsigned int, int);
extern int rmemcardReadFile(void *, void *, int);
extern unsigned int lbl_8034D7B0[];
void fn_802E6B50(void) {
    #pragma scheduling invalid_target
    #define gChunkTable   lbl_804FC8B0
    #define gChunkCount   lbl_8055FFC0
    #define gMemcardReady lbl_8055FFC4
    #define gMemcardError lbl_8055FFC5
    /* Reset memory-card save state: clear the chunk-record table and its
       count, mark the card ready and clear the error flag. */
    memset(gChunkTable, 0, 0xC8);
    gChunkCount = 0;
    gMemcardReady = 1;
    gMemcardError = 0;
    #undef gMemcardError
    #undef gMemcardReady
    #undef gChunkCount
    #undef gChunkTable
}
#pragma scheduling on
/* Memory-card module shutdown hook, the counterpart of fn_802E6B50 (run from the
 * NAND-save teardown NandSaveShutdown).  The module owns no allocation, so there is
 * nothing to release here. */
void MemCardShutdown(void) {}

/* Formats a 4-byte memcard chunk ID (e.g. 'MCSH') as a NUL-terminated string
 * in the static chunkIdString buffer, for the "chunk: %s" registration log. */
void *fn_802E6B98(int chunkId) {
    int id = chunkId;
    ((unsigned char *)&chunkIdString)[4] = 0;
    memcpy(&chunkIdString, &id, 4);
    return &chunkIdString;
}

#pragma dont_inline on
extern void Abend_Panic(const char *, ...);
extern char lbl_8034D690[];
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma push
#pragma use_lmw_stmw off
/* Register a memcard chunk record: log its id/type/size, then panic (Abend_Panic
 * aborts) if a record with this cookie id is already in the table; otherwise append
 * a new 0x14-byte record {id, type, addr, size, callback} and bump the record count. */
void fn_802E6BD8(unsigned int cookieId, unsigned int recordType, unsigned int recordAddr, unsigned int recordSize, unsigned int recordCallback) {
    #define gChunkTable lbl_804FC8B0
    #define gChunkCount lbl_8055FFC0
    unsigned char *chunk;
    int index;
    int count;

    fn_802E30C8(lbl_8034D678, fn_802E6B98(cookieId), recordType, recordSize);
    chunk = gChunkTable;
    index = 0;
    goto loop_check;
loop_body:
    if (cookieId == *(unsigned int *)chunk)
        Abend_Panic(lbl_8034D690, cookieId);
    chunk += 0x14;
    index++;
loop_check:
    if (index < gChunkCount)
        goto loop_body;

    count = gChunkCount;
    chunk = gChunkTable + count * 0x14;
    *(unsigned int *)(chunk + 0) = cookieId;
    *(unsigned int *)(chunk + 4) = recordType;
    *(unsigned int *)(chunk + 8) = recordAddr;
    *(unsigned int *)(chunk + 0xC) = recordSize;
    gChunkCount = count + 1;
    *(unsigned int *)(chunk + 0x10) = recordCallback;
    #undef gChunkCount
    #undef gChunkTable
}
#pragma pop
#pragma scheduling on
#pragma dont_inline off

/* No-op second memory-card hook: called with flag 1 at the start of the save
 * flow (fn_8023B5EC), between fn_802E712C and the MCSH load fn_802E6CA8. */
void fn_802E6CA4(void) {}

#pragma use_lmw_stmw off
int fn_802E6CA8(void) {
    unsigned char *allocation;
    char *messages = lbl_8034D678;
    int size;
    int payloadSize;
    unsigned char flags[10];
    int success;
    int readError;
    int i;
    int result;
    int temp;
    unsigned char *desc;
    unsigned char *descIt;
    unsigned char *dataIt;
    unsigned char *slot;
    unsigned char *flagIt;
    void (*callback)(int);

    size = fn_802E7130();
    payloadSize = size - 0x20D0;
    allocation = (unsigned char *)fn_801284E8(messages + 0x40, size);
    memset(allocation, 0, 0x20D0);
    memset(allocation + 0x20D0, 0, payloadSize);
    flags[0] = 0; flags[1] = 0; flags[2] = 0; flags[3] = 0; flags[4] = 0;
    flags[5] = 0; flags[6] = 0; flags[7] = 0; flags[8] = 0; flags[9] = 0;
    success = 0;
    readError = 0;

    if (rmemcardReadFile((void *)lbl_8055D200, allocation, size) == 0) {
        fn_802E30C8(messages + 0x50);
        readError = 1;
    } else {
        temp = *(int *)(allocation + 0x204C);
        if (temp != payloadSize) {
            fn_802E30C8(messages + 0x68, temp, payloadSize);
        } else if (*(unsigned int *)(allocation + 0x2040) != 0x4D435348 ||
                   *(unsigned int *)(allocation + 0x2044) != 4 ||
                   *(unsigned int *)(allocation + 0x2048) != 0x20D0 ||
                   (unsigned int)temp != (unsigned int)payloadSize) {
            fn_802E30C8(messages + 0x88);
            fn_802E30C8(messages + 0xB0,
                        *(unsigned int *)(allocation + 0x2040),
                        *(unsigned int *)(allocation + 0x2044),
                        *(unsigned int *)(allocation + 0x2048),
                        *(unsigned int *)(allocation + 0x204C));
            fn_802E30C8(messages + 0xC4, payloadSize);
        } else {
            result = ((unsigned int (*)(void *))fn_80132E7C)(allocation + 0x20D0);
            if (result != *(unsigned int *)(allocation + 0x2050)) {
                fn_802E30C8(messages + 0xD4, result);
            } else {
                desc = allocation + 0x2058;
                descIt = desc;
                dataIt = allocation + 0x20D0;
                success = 1;
                i = 0;
                goto first_check;
first_body:
                if (fn_802E721C(*(unsigned int *)(descIt + 0),
                                *(unsigned int *)(descIt + 4),
                                *(int *)(descIt + 8)) < 0) success = 0;
                descIt += 0xC;
                i++;
first_check:
                if (i < *(int *)(allocation + 0x2054)) goto first_body;

                if (success != 0) {
                    descIt = desc;
                    i = 0;
                    goto second_check;
second_body:
                    result = fn_802E721C(*(unsigned int *)(descIt + 0),
                                         *(unsigned int *)(descIt + 4),
                                         *(int *)(descIt + 8));
                    if (result >= 0) {
                        (&flags[0])[result] = 1;
                        slot = lbl_804FC8B0 + result * 0x14;
                        callback = *(void (**)(int))(slot + 0x10);
                        if (callback != 0) callback(0);
                        memcpy(*(void **)(slot + 8), dataIt,
                               *(unsigned int *)(slot + 0xC));
                        callback = *(void (**)(int))(slot + 0x10);
                        if (callback != 0) callback(1);
                    } else {
                        success = 0;
                    }
                    {
                        unsigned int amount = *(unsigned int *)(descIt + 8);
                        descIt += 0xC;
                        i++;
                        dataIt += amount;
                    }
second_check:
                    if (i < *(int *)(allocation + 0x2054)) goto second_body;
                }
            }
        }
    }

    fn_80128658(allocation);
    if (success == 0) {
        int anyMissing = 0;
        int scanCount;
        flagIt = flags;
        scanCount = lbl_8055FFC0;
        while (scanCount > 0) {
            if (*flagIt == 0) anyMissing = 1;
            flagIt++;
            scanCount--;
        }
        if (anyMissing != 0) {
            slot = lbl_804FC8B0;
            i = 0;
            while (i < lbl_8055FFC0) {
                callback = *(void (**)(int))(slot + 0x10);
                if (callback != 0) callback(2);
                slot += 0x14;
                i++;
            }
        }
        if (readError == 0) {
            fn_802E30C8(messages + 0xF8);
        } else {
            fn_802E6FBC();
        }
    }
    return 0;
}
extern char lbl_8034D6B8[];
extern char lbl_8034D784[];
#pragma push
#pragma use_lmw_stmw off
/* Builds a memory card save image (MCSH) from registered save entries and writes it. */
/* Build a memory-card save image in MCSH format from the registered 0x14-byte save entries (lbl_804FC8B0), compute its header checksum, write it through the NAND save helper, and free the buffer. */ void *fn_802E6FBC(void) {
    register unsigned char *saveEntry;
    register unsigned char *descriptor;
    register int entryIndex;
    register int imageSize = fn_802E7130();
    register unsigned char *saveImage;
    register unsigned char *dataDest;
    unsigned int entrySize;
    void (*entryCallback)(int);
    void *writeResult;
    saveImage = (unsigned char *)fn_801284E8(lbl_8034D6B8, imageSize);
    memset(saveImage, 0, 0x20D0);
    *(unsigned int *)(saveImage + 0x2040) = 0x4D435348; /* 'MCSH' */
    *(unsigned int *)(saveImage + 0x2044) = 4;
    *(unsigned int *)(saveImage + 0x2048) = 0x20D0;
    *(unsigned int *)(saveImage + 0x204C) = imageSize - 0x20D0;
    *(unsigned int *)(saveImage + 0x2054) = lbl_8055FFC0;
    memset(saveImage + 0x20D0, 0, imageSize - 0x20D0);
    dataDest = saveImage + 0x20D0;
    saveEntry = lbl_804FC8B0;
    descriptor = saveImage + 0x2058;
    entryIndex = 0;
    goto loop_check;
loop_body:
    *(unsigned int *)(descriptor + 0) = *(unsigned int *)(saveEntry + 0);
    *(unsigned int *)(descriptor + 4) = *(unsigned int *)(saveEntry + 4);
    *(unsigned int *)(descriptor + 8) = *(unsigned int *)(saveEntry + 0xC);
    entryCallback = *(void (**)(int))(saveEntry + 0x10);
    if (entryCallback != 0)
        entryCallback(3);
    memcpy(dataDest, *(void **)(saveEntry + 8), *(unsigned int *)(saveEntry + 0xC));
    entryCallback = *(void (**)(int))(saveEntry + 0x10);
    if (entryCallback != 0)
        entryCallback(4);
    entrySize = *(unsigned int *)(saveEntry + 0xC);
    entryIndex++;
    dataDest += entrySize;
    saveEntry += 0x14;
    descriptor += 0xC;
loop_check:
    if (entryIndex < lbl_8055FFC0)
        goto loop_body;
    *(unsigned int *)(saveImage + 0x2050) =
        fn_80132E7C(saveImage + 0x20D0, *(unsigned int *)(saveImage + 0x204C));
    fn_802E30C8(lbl_8034D784, (imageSize + 0x1FFF) / 0x2000, imageSize);
    writeResult = fn_802E967C(lbl_8055D200, saveImage, imageSize);
    fn_80128658(saveImage);
    return writeResult;
}
#pragma pop

/* Public "save now" entry point: builds the MCSH memory-card image from the
 * registered save records and writes it to the card (fn_802E6FBC). */
void fn_802E7128(void) { fn_802E6FBC(); }

/* Hook run before every read of the save image from the memory card (with
 * fn_802E6CA8) and once during bootstrap: there is nothing to flush or cancel
 * before a read in this build, so it does nothing. */
void fn_802E712C(void) {}

#pragma scheduling reset
/* Return the memory-card save image size: the 0x20D0-byte header plus the data
 * size of every registered chunk, rounded up to a 0x2000-byte block boundary. */
int fn_802E7130(void) {
#define gChunkTable lbl_804FC8B0
#define gChunkCount lbl_8055FFC0
#define HEADER_SIZE 0x20D0
#define BLOCK_ROUND 0x1FFF
#define BLOCK_MASK  0xFFFFE000
    struct Chunk { unsigned char pad[0xC]; int dataSize; unsigned char tail[4]; };
    int total = HEADER_SIZE;
    int i;
    for (i = 0; i < gChunkCount; i++) {
        total += ((struct Chunk *)gChunkTable)[i].dataSize;
    }
    return (total + BLOCK_ROUND) & BLOCK_MASK;
#undef BLOCK_MASK
#undef BLOCK_ROUND
#undef HEADER_SIZE
#undef gChunkCount
#undef gChunkTable
}
/* Finds the index of a memcard record matching (arg0,arg1,arg2); logs and returns -1 on mismatch. */
/* Find the index of the memory-card chunk entry matching (chunkId, chunkFormat, chunkSize); if the id matches but the format or size differs, log a "bad chunk format" message and return -1. */ int fn_802E721C(unsigned int chunkId, unsigned int chunkFormat, int chunkSize) {
    unsigned char *chunkEntry = lbl_804FC8B0;
    int chunkCount = lbl_8055FFC0;
    int chunkIndex = 0;
    while (chunkCount > 0) {
        if (*(unsigned int *)chunkEntry == chunkId) {
            if (*(unsigned int *)(chunkEntry + 4) != chunkFormat || *(int *)(chunkEntry + 0xC) != chunkSize) {
                fn_802E30C8((const char *)lbl_8034D7B0, chunkId);
                return -1;
            }
            return chunkIndex;
        }
        chunkEntry += 0x14;
        chunkIndex++;
        chunkCount--;
    }
    return -1;
}

#pragma scheduling on

