// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
extern void fn_801D611C(s32);
extern void fn_801D77E8(s32);
extern void fn_801D77EC(s32);
extern void fn_801D7874(s32);

extern void fn_80128668(void*);
void* fn_801D9090(void* arg0, s32 arg1) {
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

void fn_801D90E8(s32 arg0) {
    fn_801D611C(arg0 - 4);
}

void fn_801D90F0(s32 arg0) {
    fn_801D77E8(arg0 - 4);
}

void fn_801D90F8(s32 arg0) {
    fn_801D77EC(arg0 - 4);
}

void fn_801D9100(s32 arg0) {
    fn_801D7874(arg0 - 4);
}

void fn_801D9108(int arg0) { fn_801D8938(arg0 - 4); }

void fn_801D9110(int arg0) { fn_801D893C(arg0 - 4); }

void fn_801D9118(int arg0) { fn_801D89C0(arg0 - 4); }

