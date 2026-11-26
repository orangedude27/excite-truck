// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed char s8;
typedef unsigned char u8;
typedef signed long s32;

extern void *getResourceData(void *, s32, s32 *, s32 *, s32, u8 *);
extern void Abend_Panic(const char *, ...);
extern char lbl_8032AF68[];
extern char lbl_8032AF84[];
#pragma scheduling invalid_target
#pragma unroll off
#pragma optimize_for_size on
#pragma use_lmw_stmw off
/* Load a STAB resource chunk and byte-swap its fields in place when the data is flagged as endian-swapped. */
void *loadStabResource(s32 resourceId) {
    s32 dataType;
    u8 endianSwapped;
    void *stabData;
    volatile u8 *bytes;
    volatile u8 *entryBytes;
    u8 swapByte;
    s32 entryIndex;
    stabData = getResourceData((void *)resourceId, 0x53544142, &dataType, 0, 0, &endianSwapped);
    if (stabData == 0) {
        Abend_Panic(lbl_8032AF68, resourceId);
    }
    if (dataType != 0) {
        Abend_Panic(lbl_8032AF84, dataType, 0, resourceId);
    }
    if (endianSwapped != 0) {
        bytes = (volatile u8 *)stabData;
        swapByte = bytes[0];
        bytes[0] = bytes[3];
        bytes[3] = swapByte;
        swapByte = bytes[1];
        bytes[1] = bytes[2];
        bytes[2] = swapByte;
        swapByte = bytes[4];
        bytes[4] = bytes[7];
        bytes[7] = swapByte;
        swapByte = bytes[5];
        bytes[5] = bytes[6];
        bytes[6] = swapByte;
        entryBytes = bytes + 8;
        for (entryIndex = 0; entryIndex < 4; entryIndex++) {
            swapByte = entryBytes[0];
            entryBytes[0] = entryBytes[3];
            entryBytes[3] = swapByte;
            swapByte = entryBytes[1];
            entryBytes[1] = entryBytes[2];
            entryBytes[2] = swapByte;
            swapByte = entryBytes[4];
            entryBytes[4] = entryBytes[7];
            entryBytes[7] = swapByte;
            swapByte = entryBytes[5];
            entryBytes[5] = entryBytes[6];
            entryBytes[6] = swapByte;
            swapByte = entryBytes[8];
            entryBytes[8] = entryBytes[0xB];
            entryBytes[0xB] = swapByte;
            swapByte = entryBytes[9];
            entryBytes[9] = entryBytes[0xA];
            entryBytes[0xA] = swapByte;
            swapByte = entryBytes[0xC];
            entryBytes[0xC] = entryBytes[0xF];
            entryBytes[0xF] = swapByte;
            swapByte = entryBytes[0xD];
            entryBytes[0xD] = entryBytes[0xE];
            entryBytes[0xE] = swapByte;
            entryBytes += 0x10;
        }
        swapByte = bytes[0x48];
        bytes[0x48] = bytes[0x4B];
        bytes[0x4B] = swapByte;
        swapByte = bytes[0x49];
        bytes[0x49] = bytes[0x4A];
        bytes[0x4A] = swapByte;
    }
    return stabData;
}
#pragma use_lmw_stmw reset
#pragma optimize_for_size reset
#pragma unroll reset
#pragma scheduling on
void fn_8012F2E4(void) {
    releaseResource();
}

/* Return the value pointed to: the row count of the most recently loaded STAB table. */
s32 fn_8012F2E8(s32 *value) {
    return *value;
}

void *fn_8012F2F0(s32 *table, s32 row, s32 column) {
    /* Return the string at (row, column) in a STAB text table: text begins at +0x4C,
       the row stride is the word at +0x48, and column-relative offsets start at +0x8. */
    s32 *offsetEntry = table + column;
    s32 columnOffset = *(offsetEntry + 2);
    s32 rowOffset = *(table + 0x12) * row;
    s32 textAddr = (s32)table + rowOffset;
    textAddr = textAddr + columnOffset;
    return (void *)(textAddr + 0x4C);
}

