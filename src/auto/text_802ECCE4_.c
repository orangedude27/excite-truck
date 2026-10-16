#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802E12DC(void *);
extern void fn_802E1290(void *);
extern void fn_80128668(void *);
extern s32 lbl_805600F8;
extern char lbl_8034EC18[];
extern void fn_802ECCE4(char *, void *, s32);
extern s32 stricmp(const char *, const char *);
extern s32 fn_802ECEEC(void);
extern void *fn_801284F8(s32, const char *);
extern s32 fn_802ECD68(void *, void *, s32);
void *fn_802ECF08(void *arg0, s32 arg1) {
    void *result;
    if (fn_802ECEEC() != 0) {
        return (void *)lbl_805600F8;
    }
    result = fn_801284F8(0x44, lbl_8034EC18);
    if (fn_802ECD68(result, arg0, arg1) == 0) {
        fn_80128668(result);
        result = 0;
    }
    return result;
}

s32 fn_802ECF90(const char *arg0, void *arg1) {
    char buffer[64];
    if (lbl_805600F8 != 0) {
        return 1;
    }
    fn_802ECCE4(buffer, arg1, 64);
    return stricmp(buffer, arg0) == 0;
}

void fn_802ECFEC(void *arg0) {
    fn_802E12DC(((void **)arg0)[16]);
}

void fn_802ECFF4(void *arg0) {
    if (lbl_805600F8 == 0) {
        fn_802E1290(((void **)arg0)[16]);
        fn_80128668(arg0);
    }
}

extern void fn_802E13D8(void *);
void fn_802ED038(void *arg0) {
    fn_802E13D8(((void **)arg0)[16]);
}

