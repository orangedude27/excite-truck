// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef unsigned char u8;
extern s32 lbl_8033A048;
extern s32 lbl_802F9A08[];
extern s32 lbl_804885E8[];
extern f32 lbl_80562E68;
extern f32 lbl_8055EB98[2];
extern void fn_801EB9A4(s32 *);
s32 fn_801EB0E8(void) { return 0; }

s32 fn_801EB0F0(s32 arg0) {
    s32 var_r0 = 0;
    if ((arg0 >= 0) && (arg0 < 0x18)) var_r0 = 1;
    return var_r0;
}

s32 fn_801EB110(void *arg0) {
    return lbl_804885E8[((u32 *)arg0)[4]];
}

void fn_801EB128(void) {
    lbl_8055EB98[0] = lbl_80562E68;
    lbl_8055EB98[1] = lbl_80562E68;
}

void fn_801EB634(void *arg0, s32 arg1) {
    u8 a=((u8 *)arg0)[0];
    u8 b=((u8 *)arg0)[1];
    u8 c=((u8 *)arg0)[2];
    u8 d=((u8 *)arg0)[3];
    ((u8 *)arg0)[1]=c; ((u8 *)arg0)[2]=b; ((u8 *)arg0)[3]=a; ((u8 *)arg0)[0]=d;
    if (*(s32 *)arg0) *(s32 *)arg0 += arg1;
}

void fn_801EB6A4(void) {

}

void fn_801EB800(void *object, s32 arg1, s32 arg2) {
    register void **vt;
    vt=*(void ***)object;
    ((void (*)(void *, s32, s32))vt[10])(object,arg2,arg1);
}

void fn_801EB81C(void) {

}

void fn_801EB820(void) {

}

void fn_801EB824(s32 arg0) {
    s32 sp8;
    sp8=(s32)&lbl_8033A048;
    fn_801EB000(&sp8);
}

void fn_801EB854(void) {
    s32 *var_r31=lbl_802F9A08;
    s32 *var_r30=lbl_804885E8;
    u32 var_r29=0;
    for(;var_r29<0x18;var_r29++,var_r31+=2,var_r30++) {
        fn_801EB96C(var_r30,var_r31[1]);
    }
}

void fn_801EB8BC(void) {
    s32 *p = lbl_804885E8;
    u32 i = 0;
    do {
        fn_801EB9A4(p);
        i++;
        if (i < 0x18) p++;
    } while (i < 0x18);
}

void fn_801EB90C(void) {
    void **p = (void **)lbl_804885E8;
    u32 i = 0;
    do {
        void *obj = *p;
        void **vtable = *(void ***)obj;
        ((void (*)(void))vtable[6])();
        i++;
        if (i < 0x18) p++;
    } while (i < 0x18);
}

void fn_801EB968(void) {

}

s32 fn_801EB96C(s32 *out, s32 callback) {
    register s32 (*fn)(void) = (s32 (*)(void))callback;
    register s32 *ptr = out;
    *ptr = fn();
    return *ptr;
}

void fn_801EB9A4(s32 *arg0) {
    s32 temp_r0 = *arg0;
    if (temp_r0 && temp_r0) {
        s32 (*fn)(void *, s32) = (s32 (*)(void *, s32))(*((s32 **)temp_r0))[2];
        fn((void *)temp_r0, 1);
    }
    *arg0 = 0;
}

extern s32 lbl_8055AFB8;
extern s32 lbl_8055AFBC;
extern s32 *lbl_8055EBA0;
extern s32 fn_8012C4D8(s32);
extern void fn_802AE9D0(void);
extern void fn_802AEA44(void);
extern void fn_802C6CF8(s32);
extern void fn_802CCE24(s32);
void fn_801EBBB4(void) {
    fn_802C6CF8(lbl_8055AFBC);
    lbl_8055AFBC = -1;
    if (lbl_8055AFB8 != -1) {
        fn_802C6CF8(lbl_8055AFB8);
        lbl_8055AFB8 = -1;
    }
    if (lbl_8055EBA0 != 0) {
        fn_801EB824(*lbl_8055EBA0);
        fn_801EB8BC();
        fn_8012C4D8((s32)lbl_8055EBA0);
        lbl_8055EBA0 = 0;
        return;
    }
    fn_802AE9D0();
}
void fn_801EBC2C(void) {
    if (lbl_8055EBA0 != 0) {
        fn_802CCE24(((s32 *)lbl_8055EBA0)[1]);
        fn_802CCE24(((s32 *)lbl_8055EBA0)[2]);
        return;
    }
    fn_802AEA44();
}

extern void fn_802CD254(s32);
extern void fn_801E8718(s32);
extern f32 fn_801E8738(s32);
extern void fn_802BF598(f32);
extern s32 fn_801E85A4(void);
void fn_801EBC70(void) {
    if (lbl_8055EBA0 != 0) {
        fn_802CD254(((s32 *)lbl_8055EBA0)[1]);
        fn_802CD254(((s32 *)lbl_8055EBA0)[2]);
    }
}

void fn_801EBCAC(void) {
    if (lbl_8055EBA0 != 0) {
        s32 *p = lbl_804885E8;
        u32 i = 0;
        do {
            void **obj = *(void ***)p;
            void **vt = *(void ***)*obj;
            ((void (*)(void))vt[7])();
            i++;
            if (i < 0x18) p++;
        } while (i < 0x18);
    }
}

void fn_801EBD14(void) {

}

void fn_801EBD18(s32 arg0) {
    f32 temp;
    if (fn_801E85A4() > 1) {
        temp = fn_801E8738(arg0);
        fn_801E8718(arg0);
        fn_802BF598(temp);
    }
}

extern f32 lbl_8055EBA4;
extern f32 fn_801EC114(void);
f32 fn_801EC114(void) {
    return lbl_8055EBA4;
}

void fn_801EC19C(void) {

}
extern s32 lbl_802F9A08[];
extern s32 fn_801EB000(s32 *);
extern s32 fn_801EB96C(s32 *, s32);
extern void fn_801EB634(void *, s32);
