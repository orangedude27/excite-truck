typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055FFF0;
s32 fn_802E769C(void);
void fn_802E7578(void) {
    lbl_8055FFF0 = (void*)fn_802E769C();
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

