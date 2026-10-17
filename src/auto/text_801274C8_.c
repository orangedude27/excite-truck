// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern void fn_80127968(void);
extern void *memset(void*, int, unsigned long);
extern u32 lbl_8055DF1C;
extern s32 lbl_8055DF44;
extern const char lbl_80329EF4[];
extern const char lbl_80329E30[];
extern u8 lbl_8041D790[];
extern u8 lbl_8041DC10[];
extern s32 lbl_8041DF30[];
extern void fn_80127C90(void (*)(void), const char*);
extern void fn_80127D58(void (*)(void));
extern void fn_802E30C8(const char*, ...);
extern void fn_802E2C20(void);
extern s32 lbl_8055DF30;
extern u32 lbl_8055DF34;
extern u64 lbl_8055DF18;
extern u64 lbl_8055DF20;
extern u64 fn_802E2C9C(void);

s32 fn_80127538(void) {
    memset(lbl_8041D790, 0, 0x480);
    memset(lbl_8041DC10, 0, 0x10);
    fn_80127968();
    fn_80127C90(fn_80127968, lbl_80329EF4);
    lbl_8055DF1C = 0;
    lbl_8055DF18 = 0;
    lbl_8055DF30 = 0;
    lbl_8055DF34 = 0;
    return 1;
}

void fn_80127930(void* alarm) {
    fn_801274C8(fn_8012766C(alarm));
}

void fn_80127954(void) {
    fn_802E2C20();
}

void fn_80127958(void) {

}

s32 fn_8012795C(void) {
    return 0;
}

void fn_80127964(void) {

}

void fn_80127968(void) {
    u64 now = fn_802E2C9C();
    lbl_8055DF18 += now - lbl_8055DF20;
    lbl_8055DF20 = now;
}

void fn_801279B8(void) {
    if (++lbl_8055DF34 != 0) {
        return;
    }
    fn_80127954();
}

void fn_801279D0(void) {
    lbl_8055DF30 += 1;
}
extern u32 lbl_8055DF1C;
extern s32 lbl_8055DF44;
extern void fn_80127C90(void (*)(void), const char*);
extern void fn_80127D58(void (*)(void));
extern void fn_802E30C8(const char*, ...);
extern const char lbl_80329EF4[];
extern const char lbl_80329E30[];
extern u8 lbl_8041D790[];
extern u8 lbl_8041DC10[];
extern s32 lbl_8041DF30[];

