// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

typedef struct {
    u8 unk_0x0[0x1E4];
    void* unk_0x1E4;
} Unk8034EF38;

typedef struct {
    u32 unk_0x0;
    const char* unk_0x4;
    const char* unk_0x8;
} Unk802FB70C;

extern Unk8034EF38 lbl_8034EF38;
extern Unk802FB70C lbl_802FB70C[];
extern const char lbl_802FB77C[];
extern const char lbl_80558998[1];
extern const char lbl_805589A0[1];
void fn_80007DA0(void);
void fn_80279464(void);
void fn_80012778(void);
void fn_80131818(void*);
void fn_802E317C(const char*, ...);

int stricmp(const char*, const char*);
void fn_80012794(void);
void fn_80279488(void);
void fn_802E30C8(const char*, ...);
extern const char lbl_802FB7A4[];
void fn_80007D94(const char** arg0, const char** arg1) {
    stricmp(*arg0, *arg1);
}

void fn_80007F04(void) {
    Unk8034EF38* p = &lbl_8034EF38;
    fn_80131818(p->unk_0x1E4);
    p->unk_0x1E4 = 0;
}

void fn_80007F40(void) {
    fn_80007DA0();
    fn_80279464();
    fn_80012778();
}

#pragma dont_inline fn_80007F04
void fn_80007F04(void);
#pragma dont_inline fn_80007F04
void fn_80007F68(void) {
    fn_80012794();
    fn_80279488();
    fn_80007F04();
}
const char* fn_80007F90(u32 arg0) {
    Unk802FB70C* p;
    u32 key;
    for (p = lbl_802FB70C; (key = p->unk_0x0) != 0; ++p) {
        if (key == arg0) return p->unk_0x4;
    }
    fn_802E317C(lbl_802FB77C, arg0);
    return lbl_80558998;
}
const char* fn_80007FF0(u32 arg0) {
    Unk802FB70C* p;
    u32 key;
    for (p = lbl_802FB70C; (key = p->unk_0x0) != 0; ++p) {
        if (key == arg0) return p->unk_0x8;
    }
    fn_802E317C(lbl_802FB77C, arg0);
    return lbl_805589A0;
}

#pragma dont_inline fn_80007F04
u32 fn_80008050(const char* arg0) {
    Unk802FB70C* p;
    u32 key;
    for (p = lbl_802FB70C; (key = p->unk_0x0) != 0; ++p) {
        if (strcmp(p->unk_0x4, arg0) == 0) return key;
    }
    fn_802E30C8(lbl_802FB7A4, arg0);
    return 0;
}
u32 fn_800080D8(void) {
    return *(u32*)((u8*)&lbl_8034EF38 + 0x1E0);
}

s32 fn_80008158(s32);
extern const char lbl_805589A8[];
const char* fn_80008188(void) {
    return *(const char**)((u8*)&lbl_8034EF38 + fn_800080E8() * 0xC + 4);
}

s32 fn_800081BC(void) {
    return *(s32 *)((u8 *)&lbl_8034EF38 + fn_800080E8() * 0xC + 8);
}

s32 fn_800081F0(void *arg0) {
    s32 result;
    if (*(u32 *)((u8 *)arg0 + 0x10) & 1) goto done;
    result = *(s32 *)((u8 *)fn_8001285C(*(s32 *)arg0) + 0xC);
    return result;
done:
    return 0xC8;
}

void fn_8000822C(void *arg0) {
    *(u32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 0) = -1;
    *(u32 *)((u8 *)arg0 + 0x10) = 0;
    *(u32 *)((u8 *)arg0 + 0xC) = 0;
    *(u32 *)((u8 *)arg0 + 8) = 0;
}

void fn_8000822C(void *);
#pragma dont_inline fn_8000822C
void fn_8000824C(void *arg0, s32 arg1) {
    void *temp_r3;
    fn_8000822C(arg0);
    temp_r3 = (void *)fn_8001285C(arg1);
    *(u32 *)((u8 *)arg0) = *(u32 *)((u8 *)temp_r3);
    *(u32 *)((u8 *)arg0 + 4) = *(u32 *)((u8 *)temp_r3 + 8);
}
