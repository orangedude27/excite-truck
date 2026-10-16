typedef signed long s32;
typedef s32 (*UnkFunc)(s32);
extern float lbl_80563898;
extern float lbl_805638A8;
extern double lbl_805638A0;
void fn_80246CAC(float);
void fn_80127464(void);
void fn_802E2D74(s32);
void fn_8020A634(void);
s32 fn_802E2C20(void);
void fn_80214AF0(s32);
void fn_80214A9C(s32);
extern char lbl_80343600;
typedef struct Obj_802470D4 {
    void *vtable;
    char pad[0x14];
    s32 field18;
    s32 field1C;
    s32 field20;
    char pad24[0xC];
    s32 *field30;
} Obj_802470D4;
void fn_80235380(s32);
void fn_802C519C(s32);
void fn_802328D4(s32);
void fn_80128668(void *);


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055F260;
void fn_80247174(void) {
    s32 i = 0;
    do {
        fn_80246CAC(lbl_80563898 - ((float)i / lbl_805638A8));
        fn_80127464();
        fn_802E2D74(0x10);
        i++;
    } while (i < 0x32);
    fn_8020A634();
    fn_80246CAC(lbl_80563898);
}

s32 fn_8024739C(void) { return 0; }

char fn_80247624(void) {
    return lbl_8055F260;
}

s32 fn_8024762C(void) {
    if (fn_802E2C20() % 1500 > 500) fn_80214AF0(1);
    else fn_80214A9C(1);
    return 0;
}

extern void* lbl_8055BEAC;
s32 fn_80214D04(void);
void fn_80247768(void) {
    lbl_8055BEAC = (void*)fn_80214D04();
}

extern void* lbl_8055BEB0;
void fn_80247880(void) {
    lbl_8055BEB0 = (void*)fn_80214D04();
}

extern void* lbl_8055BEB4;
void fn_80247AAC(void) {
    lbl_8055BEB4 = (void*)fn_80214D04();
}
