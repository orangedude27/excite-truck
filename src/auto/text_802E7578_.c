typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055FFF0;
s32 fn_802E769C(void);
void fn_802E7578(void) {
    lbl_8055FFF0 = (void*)fn_802E769C();
}

void fn_802E75E4(s32 arg0) {
    ((void (*)(void*, s32))(*(void***)lbl_8055FFF0)[3])(lbl_8055FFF0, arg0);
}

void fn_802E765C(s32 arg0, s32 arg1, s32 arg2) {
    ((void (*)(void*, s32, s32, s32))(*(void***)lbl_8055FFF0)[5])(lbl_8055FFF0, arg0, arg1, arg2);
}

extern s32 fn_80128668(void);
extern s32 OSGetConsoleType(void);
extern s32 fn_802E30C8(void*);
extern s32 fn_801284F8(s32, void*);
extern char lbl_8034D828[];
extern char lbl_8034D84C[];
extern char lbl_8034D860[];
void fn_802E7684(void* arg0) {
    ((UnkFunc)(*(void**)lbl_8055FFF0))( (s32)arg0 );
}

s32 fn_802E76F0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_802E7730(void) {
    return 1;
}

void fn_802E7738(void) {
}

void fn_802E773C(void) {
}

void fn_802E7740(void) {
}

void fn_802E7744(void) {
}

void fn_802E7748(void) {
}

s32 fn_802E774C(void) {
    return 0;
}

s32 fn_802E7754(void) {
    return 0;
}

void fn_802E775C(void) {
}

void fn_802E7760(void) {
}

void fn_802E7764(void) {
}

