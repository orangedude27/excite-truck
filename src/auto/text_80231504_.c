#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055F064;
extern u8 lbl_8055F068[0x16C];
extern s32 stricmp(const char *, const char *);
extern void *fn_8012850C(s32, const char *, s32, s32, void *);
extern char *strcpy(char *, const char *);
extern char lbl_80340440[];
extern void fn_802CAC54(void *);
extern void fn_8012C4D8(void *);
extern void fn_80128670(void *);
extern void *lbl_8055F060;
s32 fn_80231504(void) {
    return 0;
}

s32 fn_8023150C(const char *arg0) {
    s32 i = 0;
    s32 offset = 0;
    while (i < *(s32 *)(lbl_8055F068 + 0x168)) {
        if (stricmp((const char *)(*(void **)(lbl_8055F068 + offset + 4)), arg0) == 0) {
            return i;
        }
        offset += 0xC;
        i++;
    }
    return -1;
}

void fn_8023158C(void *arg0, const char *arg1) {
    s32 count = *(s32 *)(lbl_8055F068 + 0x168);
    s32 offset = count * 0xC;
    *(s32 *)(lbl_8055F068 + 0x168) = count + 1;
    *(void **)(lbl_8055F068 + offset) = arg0;
    *(s32 *)(lbl_8055F068 + offset + 8) = 1;
    strcpy(fn_8012850C(0x40, lbl_80340440, offset, count + 1, lbl_8055F068), arg1);
}

s32 fn_802315FC(s32 arg0) {
    s32 offset = arg0 * 0xC;
    u8 *entry = lbl_8055F068 + offset;
    s32 refCount = *(s32 *)(entry + 8) - 1;
    s32 last;
    s32 lastOffset;
    void *ptr;
    if ((*(s32 *)(entry + 8) = refCount) < 1) {
        ptr = *(void **)entry;
        fn_802CAC54(*(void **)ptr);
        fn_8012C4D8(ptr);
        fn_80128670(*(void **)(entry + 4));
        last = *(s32 *)(lbl_8055F068 + 0x168) - 1;
        lastOffset = last * 0xC;
        *(s32 *)(lbl_8055F068 + 0x168) = last;
        *(void **)entry = *(void **)(lbl_8055F068 + lastOffset);
        *(void **)(entry + 4) = *(void **)(lbl_8055F068 + lastOffset + 4);
        *(s32 *)(entry + 8) = *(s32 *)(lbl_8055F068 + lastOffset + 8);
        return 1;
    }
    return 0;
}

void fn_80231714(void) {}

s32 fn_80231718(s32 arg0) {
    u32 value = (u32)lbl_8055F060;
    return (arg0 & 0xFF000000) | (value & 0x00FF0000) | (value & 0x0000FFFF);
}

extern s32 sprintf(char *, const char *, ...);
extern s32 fn_8012C33C(const char *);
extern s32 fn_80232578(const char *);
extern char lbl_8055B9A0[];
s32 fn_80231730(s32 arg0) {
    char buffer[0x18];
    sprintf(buffer, lbl_8055B9A0, arg0);
    if (fn_8012C33C(buffer) != 0) {
        return fn_80232578(buffer);
    }
    return 0;
}

void fn_80232928(void* hi) {
    lbl_8055F060 = hi;
}

u8 fn_80232B70(void *arg0) {
    return ((u8 *)arg0)[4];
}

u8 fn_80232B78(void *arg0) {
    return ((u8 *)arg0)[5];
}

extern s32 lbl_8055F06C;
extern s32 lbl_8055F058;
extern void fn_802328D4(s32);
extern char lbl_80340614[];
extern u32 strlen(const char *);
s32 fn_802344B0(void) {
    s32 val = lbl_8055F06C;
    u32 tmp = (u32)(-val) | (u32)val;
    return (s32)(tmp >> 31);
}

void fn_802344C4(u8 arg0) {
    lbl_8055F064 = arg0;
}
