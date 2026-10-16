#include <types.h>

extern char lbl_8055DF88;
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

s32 fn_801281F4(s32, s32);
void fn_802E30C8(void *, void *, void *);
s32 fn_802E317C(void *, void *);
void fn_8012834C(void *, void *, s32);
void fn_802E3DF8(s32, void *, void *);
void fn_80128714(void *, s32, s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

s32 fn_801281F4(s32 arg0, s32 arg1) {
    s32 r0 = arg1 - 1;
    s32 r3 = arg0 + arg1;
    r3--;
    return r3 & ~r0;
}

void fn_80128208(void) {

}

void fn_8012820C(void) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    fn_80128208();
    lbl_8055DF8C = 0;
    lbl_8055DF90 = 1;
    spC = 0;
    sp8 = 0;
    fn_802E3DF8(0, &sp14, &spC);
    fn_802E3DF8(1, &sp10, &sp8);
    fn_80128714(&lbl_8041E140, sp14, spC);
    fn_80128714(&lbl_8041E160, sp10, sp8);
    lbl_8055DF94 = sp14;
}

void fn_801282E8(void) {

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

void fn_801291BC(void) {

}

void fn_801291C0(void) {

}

void fn_801291C4(void) {

}

void fn_80129214(void) {

}

void fn_80129218(void) {

}

void fn_80128584(s32, s32);

void fn_80128658(void) {
    fn_80128584(0, 1);
}

void fn_80128660(void) {
    fn_80128584(0, 2);
}

void fn_80128668(void) {
    fn_80128584(0, 3);
}

void fn_80128670(s32 arg0) {
    fn_80128584(arg0, 0);
}

void fn_801286A0(void *arg0, s32 arg1) {
    s32 r7;
    s32 *arg0_s32;
    s32 r6;
    s32 r0;
    s32 *lbl_s32;
    s32 temp;
    s32 result;
    
    r7 = arg1 & ~0x3F;
    arg0_s32 = (s32*)arg0;
    r6 = arg0_s32[0x74];
    r0 = arg0_s32[0x75];
    arg0_s32[0x74] = r6 - r7;
    arg0_s32[0x75] = r0 - r7;
    lbl_s32 = (s32*)lbl_8041E140;
    temp = lbl_s32[1] - r7;
    lbl_s32[1] = temp;
    result = fn_801281F4(arg0_s32[0x75], r6 - r7);
    arg0_s32[r0] = result;
}

void fn_80128714(void *arg0, s32 arg1, s32 arg2) {
    s32 *ptr = (s32*)arg0;
    
    ptr[2] = arg2;
    ptr[1] = 0;
    ptr[4] = 0;
    ptr[3] = arg1;
    
    if (arg1 != 0) {
        fn_802E30C8(&lbl_8032A000[0xE8], NULL, NULL);
        fn_802E30C8(&lbl_8032A000[0x10C], &ptr[3], &ptr[3] + ptr[2]);
        ptr[7] = 0;
        ptr[6] = 0;
        ptr[5] = 0x2000000;
        return;
    }
    
    if (arg2 != 0) {
        fn_802E317C(&lbl_8032A000[0x130], (void*)(arg2 >> 10));
    } else {
        ptr[7] = 0;
        ptr[6] = 0;
    }
}
