// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

typedef struct SrcCoef {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void* unkC;
} SrcCoef;

extern SrcCoef lbl_802FDF30[8];
extern s32 lbl_8055D610;
extern s32 fn_8000DA10(void);
void fn_80128668(void*);
void fn_80128670(s32);
void fn_80131818(s32);
s32 fn_8001F89C();
s32 fn_8001F2C8();
s32 fn_8001F388();
s32 fn_8001F3AC();
s32 stricmp(const char*, const char*);
extern void* memset(void*, int, unsigned long);
extern char lbl_80358698[0x2080];

void fn_8001EF38(void* alarm) {
    fn_8001EFF0(fn_8001F528(alarm));
}

void fn_8001EF5C(void) {
    fn_8001F7E4();
}

void fn_8001EF60(void* alarm) {
    fn_8001F89C(alarm, fn_8000DA10());
}

void fn_8001EF98(void) {
    fn_8001F89C();
}

void fn_8001EF9C(void) {
    fn_8001F388();
}

void fn_8001EFA0(void) {
    fn_8001F9A4();
}

void fn_8001EFA4(void) {
    fn_8001FA20();
}

void fn_8001EFA8(void) {
    fn_8001FA8C();
}

void fn_8001EFAC(void) {
    fn_8001F3AC();
}

void fn_8001EFB0(void) {
    fn_8001F908();
}

void fn_8001EFB4(void) {
    fn_8001F724();
}

void fn_8001EFB8(void) {
    fn_8001F76C();
}

void fn_8001EFBC(void) {
    fn_8001F780();
}

void fn_8001EFC0(void) {
    fn_8001FAC8();
}

void fn_8001EFC4(void) {
    fn_8001FBE4();
}

void fn_8001EFC8(void) {
    fn_8001F578();
}

void fn_8001EFCC(void* alarm) {
    fn_8001F578(fn_8001F2C8(alarm));
}

s32 fn_8001F2C8(void* alarm) {
    SrcCoef* p = lbl_802FDF30;
    void* zero = NULL;
    if (lbl_8055D610 != 0) {
        u32 i = 0;
        void* c;
        do {
            c = p->unkC;
            if (c != NULL && c != NULL) {
                if (*(s32*)c != 0) {
                    fn_80128670(*(s32*)c);
                }
                *(s32*)c = (s32)zero;
                ((s32*)c)[1] = (s32)zero;
                fn_80128668(c);
            }
            p->unkC = zero;
            i++;
            p++;
        } while (i < 8);
        fn_80131818(lbl_8055D610);
        lbl_8055D610 = 0;
    }
    return 0;
}
#pragma scheduling reset
f32* __AXFXGetSrcCoef(u32 i) {
    return (f32*)&lbl_802FDF30[i];
}

#pragma dont_inline on
s32 fn_8001F388(s32 arg) {
    return ((s32*)__AXFXGetSrcCoef(arg))[2];
}

s32 fn_8001F41C(const char* arg) {
    s32* p = (s32*)&lbl_802FDF30;
    s32 idx = 0;
    do {
        if (stricmp((const char*)p[0], arg) == 0) {
            return idx;
        }
        idx++;
        p += 4;
    } while (idx < 8);
    return -1;
}

void fn_8001F490(s32 arg) {
    if (arg == 0 || arg == 2) {
        memset(&lbl_80358698, 0, 0x2080);
    }
}

#pragma dont_inline off
