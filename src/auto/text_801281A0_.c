#include <types.h>

extern char lbl_8055DF88;
extern u32 lbl_802F8E40;
extern u32 lbl_80559968;
extern char lbl_8032A430[];
extern char lbl_8032A01C[];
extern u8 lbl_8055DF80;
extern s32 *lbl_8055DF84;
extern s32 lbl_8055DF98;
extern char lbl_8041E140[];
extern s32 lbl_8041E140_s32[];
extern char lbl_8032A000[];
extern char lbl_8032A068[];
extern char lbl_8032A074[];
extern char lbl_8041E160[];
extern s32 lbl_8055DF8C;
extern s32 lbl_8055DF90;
extern s32 lbl_8055DF94;
extern char lbl_8055DF81;
void fn_801287D0(void *);

s32 fn_801281F4(s32, s32);
void fn_802E30C8(void *, void *, void *);
s32 fn_802E317C(void *, void *);
void fn_8012834C(void *, void *, s32);
void fn_802E3DF8(s32, void *, void *);
void fn_80128714(void *, s32, s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

s32 *fn_801281A0(s32 arg0) {
    s32 vals[4];
    s32 *p = (s32 *)&lbl_802F8E40;
    vals[0] = p[0]; vals[1] = p[1]; vals[2] = p[2]; vals[3] = p[3];
    if (arg0 >= 0 && arg0 < 4) return &vals[arg0];
    return (s32 *)&lbl_80559968;
}

s32 fn_801281F4(s32 arg0, s32 arg1) {
    s32 r0 = arg1 - 1;
    s32 r3 = arg0 + arg1;
    r3--;
    return r3 & ~r0;
}

void fn_80128208(void) {

}

extern char lbl_8032A01C[];
extern u32 lbl_802F8E40;
extern u32 lbl_80559968;
extern char lbl_8032A430[];
void fn_8012820C(void) {
    s32 sp14, sp10, spC, sp8;
    s32 zero, one;
    ((void (*)(char *))fn_80128208)(lbl_8032A01C);
    zero = 0; one = 1;
    lbl_8055DF8C = zero;
    sp10 = zero; sp8 = zero;
    lbl_8055DF90 = one;
    fn_802E3DF8(0, &sp14, &spC);
    fn_802E3DF8(1, &sp10, &sp8);
    fn_80128714(&lbl_8041E140, sp14, spC);
    fn_80128714(&lbl_8041E160, sp10, sp8);
    lbl_8055DF94 = sp14;
    (void)one;
}

void fn_801282E8(void) {

}

void fn_801282EC(s32 arg0) { lbl_8055DF8C = arg0; }

void fn_801282F4(void) {
    s32 value = ((s32 *)lbl_8041E160)[2];
    lbl_8055DF81 = (u32)((-value) & ~value) >> 31;
}

s32 fn_80128314(s32 arg0) {
    if (arg0 == 0) return ((s32 *)lbl_8041E140)[1];
    if (arg0 == 1) return ((s32 *)lbl_8041E160)[1];
    return 0;
}

s32 fn_801284E8(void) {
    fn_8012834C(NULL, NULL, 1);
}

void fn_801284F0(void *arg0, void *arg1) {
    fn_8012834C(arg0, arg1, 2);
}

void fn_801284F8(void *arg0, void *arg1) {
    fn_8012834C(arg1, arg0, 3);
}

void fn_8012850C(void *arg0, void *arg1) {
    fn_8012834C(arg1, arg0, 0);
}

s32 fn_80128520(s32 arg0) {
    volatile s32 r4 = arg0;
    void *var_r3;

    if (lbl_8055DF80 != 0) {
        var_r3 = lbl_8055DF84;
        if (var_r3 != NULL) {
            fn_802E317C(var_r3, NULL);
        } else {
            fn_8012834C(&lbl_8032A068, NULL, 3);
        }
    } else {
        fn_802E317C(&lbl_8032A074, NULL);
    }
    (void)r4;
    return lbl_8055DF98;
}

void fn_80128678(void) {
    lbl_8055DF88 = 1;
}

extern char lbl_8055DF88;
void fn_80128684(void) {
    lbl_8055DF88 = 0;
}

s32 fn_80128690(void) {
    u8 val = lbl_8055DF88;
    u32 shifted;
    shifted = __cntlzw(val);
    return shifted >> 5;
}

void fn_80128710(void) {

}

const char* __AXGetStudio_80129164(void) {
    return lbl_8032A068;
}

s32 fn_8012919C(void *arg0) { return ((s32 *)arg0)[2]; }

s32 fn_801291A4(void *arg0) { return ((s32 *)arg0)[3] - ((s32 *)arg0)[2]; }

s32 fn_801291B4(void *arg0) { return ((s32 *)arg0)[3]; }

void fn_801291BC(void) {

}

void fn_801291C0(void) {

}

void fn_801291C4(void) {

}

s32 fn_801291C8(void *arg0, u32 arg1) {
    u32 end = ((u32 *)arg0)[3];
    s32 result = 0;
    if (arg1 >= end) {
        u32 limit = end + ((u32 *)arg0)[2];
        if (arg1 < limit) result = 1;
    }
    return result;
}

s32 fn_801291F4(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_8012920C(void *arg0) { return ((s32 *)arg0)[2]; }

void fn_80129214(void) {

}

void fn_80129218(void) {

}

void fn_80128584(s32, s32);

void fn_80128658(void) {
    fn_80128584(0, 1);
}

void fn_80128660(s32 arg0) { fn_80128584(arg0, 2); }

void fn_80128668(void) {
    fn_80128584(0, 3);
}

void fn_80128670(s32 arg0) {
    fn_80128584(arg0, 0);
}

void fn_801286A0(void *arg0, s32 arg1) {
    void *r31 = arg0;
    s32 r7 = arg1 & ~0x3F;
    s32 r6 = ((s32 *)arg0)[-6];
    s32 r0 = ((s32 *)arg0)[-5];
    
    ((s32 *)arg0)[-6] = r6 - r7;
    ((s32 *)arg0)[-5] = r0 - r7;
    ((s32 *)lbl_8041E140)[1] -= r7;
    fn_801281F4(((s32 *)arg0)[-5], r6 - r7);
    ((s32 *)r31)[r0 - r7] = 0x53544B41;
}

void fn_80128714(void *arg0, s32 arg1, s32 arg2) {
    void *r29;
    char *r30;
    s32 r31;
    
    r29 = arg0;
    r30 = lbl_8032A000;
    r31 = 0;
    
    ((s32 *)arg0)[2] = arg2;
    ((s32 *)arg0)[1] = 0;
    ((s32 *)arg0)[4] = 0;
    ((s32 *)arg0)[3] = arg1;
    
    if (arg1 == 0) {
        goto skip;
    }
    
    fn_802E30C8(&lbl_8032A000[0xE8], (void *)arg1, (void *)arg2);
    fn_802E30C8(&lbl_8032A000[0x10C], &((s32 *)arg0)[3], (void *)((s32)((s32 *)arg0)[3] + ((s32 *)arg0)[2]));
    ((s32 *)arg0)[7] = 0;
    ((s32 *)arg0)[6] = 0;
    ((s32 *)arg0)[5] = 0x200;
    return;
    
skip:
    if (arg2 != 0) {
        s32 shifted = arg2 >> 10;
        fn_802E317C(&lbl_8032A000[0x130], (void *)(shifted + (shifted >> 31)));
    }
    ((s32 *)arg0)[7] = 0;
    ((s32 *)arg0)[6] = 0;
}

s32 fn_801288A4(void) {
    return 0;
}

void fn_80128DCC(void *arg0) {
    s32 offset = 0;
    do {
        u8 *entry = (u8 *)(*(u32 *)((u8 *)arg0 + 0xC) + offset);
        if (*(u32 *)entry != 0x53544B41) fn_802E317C(lbl_8032A430, entry);
        offset += *(s32 *)(entry + 0x28) + 0x40;
    } while (offset < *(s32 *)((u8 *)arg0 + 4));
}

s32 fn_80128E58(void *arg0, s32 arg1) {
    s32 aligned = ((s32 (*)(s32, s32))fn_801281F4)(arg1, 0x40);
    s32 end = *(s32 *)((u8 *)arg0 + 8);
    s32 result;
    if (*(s32 *)((u8 *)arg0 + 4) < end - aligned)
        result = *(s32 *)((u8 *)arg0 + 0xC) + end - aligned;
    else
        result = 0;
    return result;
}

void *fn_80128EB4(void *arg0, void *arg1) {
    if ((u32)*(s32 *)((u8 *)arg1 - 0x40) != 0x53544B41U) {
        return &lbl_8032A068;
    }
    return (u8 *)arg1 - 0x3C;
}

void fn_80128ED8(void *arg0, s32 arg1, s32 arg2) {
    s32 *p = (s32 *)arg0;
    p[1] = arg1;
    p[2] = 0;
    p[3] = arg2;
    p[4] = 0;
}

