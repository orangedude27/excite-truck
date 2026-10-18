// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F6C8;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned char u8;
typedef float f32;
extern void fn_802885C0(void);
extern void fn_802887EC(void);
extern f32 lbl_80564268;
extern f32 lbl_80564248;
extern f32 lbl_80564250;
extern double lbl_80564258;
extern u8 lbl_804B3150[12];
extern s32 lbl_804B31E0[];
extern s32 lbl_8055F6C0;
extern f32 fn_8023659C(void);
extern s32 fn_80214AF0(s32);
extern s32 lbl_8055F6C4;
extern s32 lbl_80488648[];
extern s32 fn_801EE0C8(s32);
extern s32 fn_801E2CCC(s32, s32);
extern s32 fn_8002F6AC(s32, void (*)(void));
extern void fn_80287C80(void);
extern void fn_802E317C(const char *, s32);
extern const char lbl_80348A4C[];
typedef struct Obj { void **vtable; } Obj;
void* fn_802875B8(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void* fn_80287610(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_80287668(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_802876A8(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x18) = fn_8023659C();
    *((u8 *)arg0 + 0x1C) = 0;
    fn_80214A9C(0x1D);
}

void fn_802876E8(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f1 = fn_8023659C();
    temp_f0 = *(f32 *)((u8 *)arg0 + 0x18);
    if ((temp_f1 < temp_f0) || ((temp_f1 - temp_f0) > lbl_80564248)) {
        *((u8 *)arg0 + 0x1C) = 1;
    }
    if (*((u8 *)arg0 + 0x1C) != 0) {
        fn_80214AF0(0x1D);
    }
}

s32 fn_8028774C(void *arg0) {
    return *((u8 *)arg0 + 0x1C) == 0;
}

void fn_8028775C(int arg0) { fn_802869CC(arg0 - 4); }

void fn_80287764(int arg0) { fn_80286A34(arg0 - 4); }

void fn_8028776C(int arg0) { fn_80287238(arg0 - 4); }

void fn_80287774(int arg0) { fn_80283938(arg0 - 4); }

void fn_8028777C(void) {
}

void fn_80287780(s32 arg0) {
    lbl_8055F6C0 = 0;
    fn_802AE374();
    fn_8028DF58();
    fn_802924E8();
    fn_802978B8(arg0);
    fn_80297ED4();
    fn_8029605C();
    fn_802AC458();
}

void fn_802877D0(void) {
    fn_802AC49C();
    fn_802978E4();
    fn_8029261C();
    fn_8028E0F0();
    fn_802AE394();
}

extern s32 fn_801E7DF0(s32);
extern void fn_8028777C(void);
extern void fn_80288218(s32);
extern void fn_802880F4(void);
extern void fn_802A81F0(void);
extern void fn_802888D8(void);
extern void fn_802A1590(void);
extern void fn_8028A664(void);
extern void fn_8028CED8(void);
extern void fn_80294970(void);
extern void fn_80297ED8(void);
extern void fn_8029C1C4(void);
extern void fn_8029EF70(void);
extern void fn_802924F4(void);
extern void fn_802A09B0(void);
extern void fn_802A1290(void);
extern void fn_802A4ADC(void);
extern void fn_80292114(void);
extern void fn_802A7BE8(void);
extern void fn_8029F03C(void);
extern void fn_802AB21C(void);
extern void fn_8028DFB0(void);
extern void fn_80288868(void *);
extern signed char lbl_8055F6BC;
extern void fn_802AB504(void);
extern void fn_8029F0D0(void);
extern void fn_802A7C24(void);
extern void fn_802921F4(void);
extern void fn_802A4B90(void);
extern void fn_802A14F8(void);
extern void fn_802A0AFC(void);
extern void fn_80292618(void);
extern void fn_8029EFBC(void);
extern void fn_8029C22C(void);
extern void fn_80296064(void);
extern void fn_80297FA4(void);
extern void fn_80294C68(void);
extern void fn_8028CF18(void);
extern void fn_8028A784(void);
extern void fn_802A1660(void);
extern void fn_80288988(void);
extern void fn_802A85C8(void);
extern void fn_802881D4(void);
extern void fn_802882A0(void);
extern void fn_802A86A4(void);
extern void fn_8028E138(void);
extern void fn_802980A0(void);
extern void fn_8028A89C(void);
extern void fn_8028CF50(void);
extern void fn_8029222C(void);
extern void fn_80294CC0(void);
extern void fn_80296060(void);
extern void fn_8029F124(void);
extern void fn_80292628(void);
extern void fn_802A172C(void);
extern void fn_802A4C20(void);
extern void fn_802A7C64(void);
extern void fn_802AB5B8(void);
extern void fn_802A9574(void);
extern void fn_80288868(void *);
extern void fn_8028E1A4(void);
void fn_80287974(void) { fn_8028E1A4(); }

void fn_80287978(void) { fn_8028E1D0(); }

void fn_8028797C(void) {
    fn_802882EC(); fn_802A8978(); fn_80298160(); fn_80288A20(); fn_802A1794();
    fn_8028A92C(); fn_8028CF64(); fn_80297980(); fn_80294CC4(); fn_8029C25C();
    fn_8029F188(); fn_80292698(); fn_802A0B50(); fn_802A4C60(); fn_801E7E24();
    fn_802AB628(); fn_802885F0(); fn_802887EC(); fn_802885C0();
}

void fn_802879E4(s32 arg0) {
    if (arg0 == 1) {
        if ((u8)lbl_8055F6BC != 0) fn_8028CFB0();
    } else {
        fn_8028CFB0(); fn_802A0B54(); fn_801B8820(); fn_80161AEC(); fn_802A8DE8(); fn_802AB6D0();
    }
}

void fn_80287A34(void) {
    void (*volatile fn)(void);
    fn_801E12A4();
    fn_802A1548();
    fn = (void (*)(void))(*(void***)fn_801B83A0())[18];
    fn();
}

void fn_80287A6C(s32 arg0) {
    if (arg0 == 1 && (u8)lbl_8055F6BC == 0) return;
    fn_80294CC8(arg0); fn_801B8834(); fn_802A1584(); fn_8029C2D4();
    fn_8028A9BC(arg0); fn_8028E240(arg0); fn_80288A1C(arg0); fn_802A17FC(arg0);
    fn_80298124(arg0); fn_8029F300(); fn_802A7C68(); fn_802AB6D4();
}

void fn_80287AF0(void* alarm) {
    fn_8028A9F4(fn_80292864(alarm));
}

s32 fn_80287B14(void) {
    return ((s32*)lbl_804B3150)[1];
}

s32 fn_80287B24(s32 arg0) {
    return ((s32*)lbl_804B3150)[0] + arg0 * 0x160;
}

void fn_80287B38(s32 arg0) {
    s32 index = lbl_8055F6C0;
    ((s32 *)lbl_804B31E0)[index] = arg0;
    lbl_8055F6C0 = index + 1;
}

extern u8 lbl_804B3150[12];
extern s32 lbl_8055F6C0;
extern s32 lbl_804B31E0[];
extern void fn_80288870(void);
void fn_80287B58(void) {
    fn_80288870();
}

s32 fn_80287B94(s32 arg0, s32 arg1) {
    return arg0 + fn_80287B5C(arg1 - arg0);
}

void *fn_80287C30(void *arg0) {
    *(s32 *)arg0 = 0;
    memset((u8 *)arg0 + 4, 0, 0x20);
    *(s32 *)((u8 *)arg0 + 0x24) = 0;
    return arg0;
}

extern void fn_801346B4(void *, s32, s32);
extern s32 fn_8012C33C(const char *);
extern s32 fn_80131808(const char *);
extern void fn_80287D70(void *, s32, s32);
extern int sprintf(char *, const char *, ...);
extern const char lbl_80348A40[];
extern const char lbl_80348A30[];
extern const char lbl_80348A20[];
void fn_80287E80(void **arg0, s32 arg1) {
    char local[0x40];
    void *obj;
    fn_801346B4(local, 0x40, arg1);
    obj = *arg0;
    ((void (*)(void *, void *))(*(void ***)obj)[2])(obj, local);
}

void fn_80287ED0(Obj *arg0, Obj **arg1, s32 arg2, s32 arg3) {
    Obj *obj;
    obj = *arg1;
    if (obj != 0 && ((s32 (*)(Obj *, s32))obj->vtable[2])(obj, arg2) != 0) {
    } else {
        fn_802E317C(lbl_80348A4C, arg2);
    }
    obj = *arg1;
    obj = ((Obj *(*)(Obj *, s32))obj->vtable[2])(obj, arg2);
    ((void (*)(Obj *, Obj *, s32))obj->vtable[13])(arg0, obj, arg3);
}

void fn_80287F90(void *arg0, void **arg1, s32 arg2, s32 arg3, s32 *src) {
    s32 sp8[3];
    void *obj;
    void *ret;
    obj = *arg1;
    if (obj == 0 || ((s32 (*)(void *, s32))(*(void ***)obj)[2])(obj, arg2) == 0) {
        fn_802E317C(lbl_80348A4C, arg2);
    }
    sp8[0] = src[0];
    sp8[1] = src[1];
    sp8[2] = src[2];
    obj = *arg1;
    ret = ((void *(*)(void *, s32))(*(void ***)obj)[2])(obj, arg2);
    ((void (*)(void *, void *, s32, s32 *))(*(void ***)ret)[14])(arg0, ret, arg3, sp8);
}

s32 fn_80288060(s32 arg0, s32 arg1) {
    return *(s32 *)(arg0 + (arg1 << 2) + 4);
}

void fn_80288070(s32 arg0, s32 arg1, s32 arg2) {
    s32 index = (arg0 - lbl_8055F6C4) / 40;
    s32 value;
    if ((unsigned int)index < 8U)
        value = lbl_80488648[index];
    else
        value = 0;
    value = fn_801EE0C8(value);
    ((s32 (*)(s32, s32, s32))fn_801E2CCC)(value, arg1, arg2);
}

void fn_802880F4(void) {
    extern int fn_801EA994(void);
    extern int fn_8012850C(int, const void *, int);
    extern int fn_8002F37C(int, void *, void *, int, int);
    extern int fn_801EA9A0(int);
    extern int fn_801EE0C8(int);
    extern void fn_80287CE8(int, void *, int, int);
    extern int lbl_80488648[];
    extern int lbl_8055F6C4;
    extern char lbl_80348A74[];
    int count = fn_801EA994();
    int *table = lbl_80488648;
    int offset = 0;
    int i = 0;
    lbl_8055F6C4 = fn_8002F37C(fn_8012850C(count * 0x28 + 0x10, lbl_80348A74, count * 0x28), fn_80287C30, fn_80287C80, 0x28, count);
    while (i < fn_801EA994()) {
        int obj = fn_801EA9A0(i);
        int id;
        if ((unsigned)i < 8)
            id = *table;
        else
            id = 0;
        fn_80287CE8(lbl_8055F6C4 + offset, (void *)(obj + 0x88), fn_801EE0C8(id), *(int *)(obj + 0xB8));
        table++;
        offset += 0x28;
        i++;
    }
}

void fn_802881D4(void) {
    fn_8002F6AC(lbl_8055F6C4, fn_80287C80);
    lbl_8055F6C4 = 0;
}

s32 fn_80288208(s32 arg0){return lbl_8055F6C0+arg0*0x28;}

void fn_8028829C(void) {}

void fn_802882A0(void){if(*(s32*)lbl_804B3150)fn_80128670(*(s32*)lbl_804B3150-0x10);*(s32*)lbl_804B3150=0;*(s32*)(lbl_804B3150+4)=0;lbl_804B3150[8]=0;}

void fn_802885C0(void) {}

s32 fn_802885C4(void *arg0, void *arg1) {
    return (s32)(lbl_80564268 * (*(f32 *)((u8 *)arg0 + 8) - *(f32 *)((u8 *)arg1 + 8)));
}

void fn_802887EC(void) {
    s32 i;
    for (i = 0; i < lbl_8055F6C0; i++) {
        ((void (*)(void *, s32))((s32 *)lbl_804B3150)[36 + i])((u8 *)lbl_804B3150 + 16, ((s32 *)lbl_804B3150)[1]);
    }
}

void fn_80288868(void* hi) {
    lbl_8055F6C8 = hi;
}

void fn_80288870(void) {
    s32 value = *(s32 *)&lbl_8055F6C8;
    value = (value * 0x12B9B0A1 + 0x1CCE8AC1) & 0x7FFFFFFF;
    *(s32 *)&lbl_8055F6C8 = value;
}

