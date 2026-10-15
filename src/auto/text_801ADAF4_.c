// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 fn_801284F8(s32, void *);
extern void fn_80128668(void *);
extern void *lbl_8055E604;
extern void *lbl_8033596C;
extern void *lbl_8055A8B8;
extern f32 lbl_80562520;

extern void fn_801AD888(void **);
void fn_801ADAF4(void *arg0) {
    fn_801AD888((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801AD8C8(void **);
void fn_801ADAFC(void *arg0) {
    fn_801AD8C8((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801AD99C(void **);
void fn_801ADB04(void *arg0) {
    fn_801AD99C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA38(void **);
void fn_801ADB0C(void *arg0) {
    fn_801ADA38((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA7C(void **);
void fn_801ADB14(void *arg0) {
    fn_801ADA7C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA84(void **);
void fn_801ADB1C(void *arg0) {
    fn_801ADA84((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA8C(void **);
void fn_801ADB24(void *arg0) {
    fn_801ADA8C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA94(void **);
void fn_801ADB2C(void *arg0) {
    fn_801ADA94((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADA9C(void **);
void fn_801ADB34(void *arg0) {
    fn_801ADA9C((void **)((u8 *)arg0 - 0x23C));
}

extern void fn_801ADAB8(void **);
void fn_801ADB3C(void *arg0) {
    fn_801ADAB8((void **)((u8 *)arg0 - 0x23C));
}

void fn_801AE158(void *arg0) {
    f32 val = lbl_80562520;
    *(f32 *)((u8 *)arg0 + 0x1C) = val;
    *(f32 *)((u8 *)arg0 + 0x20) = val;
    *(f32 *)((u8 *)arg0 + 0x24) = val;
}

void fn_801AE4C4(void) {
    void *result = (void *)fn_801284F8(8, &lbl_8033596C);
    if (result != NULL) {
        *(s32 *)result = 0;
        *(void **)((u8 *)result + 4) = &lbl_8055A8B8;
        lbl_8055E604 = result;
    }
}

void fn_801AE50C(void) {
    void *ptr = lbl_8055E604;
    if (ptr != NULL) {
        void *r31;
        do {
            r31 = *(void **)ptr;
            fn_80128668(ptr);
            *(void **)ptr = r31;
            ptr = r31;
        } while (ptr != NULL);
        lbl_8055E604 = NULL;
    }
}

