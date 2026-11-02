#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"

extern char lbl_80342ED8[];
extern char lbl_80342E38[];
extern char lbl_802FA338[];
extern char lbl_80498878[];
extern char lbl_8055BE20, lbl_8055B860, lbl_8055BAB8;
extern void fn_80236914(void);
extern int fn_80232578(void *);
extern int fn_802C5130(void *);
extern int fn_80019088(void);
extern int fn_80019888(void);
extern int *fn_80019054(int);
extern int fn_802146BC(void *, int, int, int);
extern int sprintf(char *, const char *, ...);
extern void fn_802E30C8(const char *, ...);
typedef struct { int label, type, value, flags, id; } Ent2449;
typedef struct {
    int one;
    int hdr[5];
    Ent2449 e[6];
    char *p98;
    int pad9c[4];
    int spAC, spB0, spB4;
    char buf[0x84];
    int sp138, sp13C;
    int pad140[2];
    int sp148, sp14C;
} Frame2449;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

s32 fn_8024497C(void* arg0) {
    fn_80236900(arg0);
    return 1;
}

void *fn_80244BD0(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80342ED8;
        fn_802328D4(*(s32 *)((char *)arg0 + 0xB0), lbl_80342ED8);
        *(s32 *)((char *)arg0 + 0xB0) = 0;
        fn_802C519C(*(s32 *)((char *)arg0 + 0xB4));
        *(s32 *)((char *)arg0 + 0xB4) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_8013C804(void);
void fn_8013C8B8(void);
s32 fn_802E2C20(void);
extern char lbl_80342ED8[];
void fn_80244C50(void) { fn_8013C804(); }

void fn_80244C54(void) { fn_8013C8B8(); }

s32 fn_80244C58(void *arg0, s32 arg1) {
    s32 *f1c = (s32 *)((char *)arg0 + 0x1C);
    s32 v;
    s32 limit;
    s32 r;
    switch (arg1) {
    case 0x126:
        *(s32 *)((char *)arg0 + 0xA8) = fn_802E2C20();
        *f1c = *f1c - 1;
        break;
    case 0x128:
        *(s32 *)((char *)arg0 + 0xAC) = fn_802E2C20();
        *f1c = *f1c + 1;
        break;
    default:
        return 0;
    }
    v = *f1c;
    limit = *(s32 *)((char *)arg0 + 0x18);
    r = v & ((-v & ~v) >> 31);
    if (r < limit - 3) limit = r;
    *f1c = limit;
    return 1;
}

void fn_80244D0C(void *arg0) {
    s32 temp_r3;
    s32 limit;
    temp_r3 = fn_802E2C20();
    limit = *(s32 *)((char *)arg0 + 0xA8) + 0xFA;
    *(volatile s32 *)((char *)arg0 + 0xA0) = temp_r3 <= limit;
    limit = *(s32 *)((char *)arg0 + 0xAC) + 0xFA;
    *(volatile s32 *)((char *)arg0 + 0xA4) = temp_r3 <= limit;
}

