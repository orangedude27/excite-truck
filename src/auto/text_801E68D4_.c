// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
typedef signed char s8;
typedef long s32;

void fn_801E6CC4(void) {
    fn_8012C4D8();
}

extern void fn_801E6924(s32);
extern void fn_801E598C(s32);
extern void fn_802C6CF8(s32);
extern void fn_80128668(s32);
extern void fn_8012ED20(s32);
extern s32 fn_8012EC90(s32);
extern s8 lbl_8055EAC8[8];
extern s32 lbl_80487CC0[8];

extern s32 fn_801E5E24(s32, void*, s32, void*);
extern void fn_801BFD34(void*, void*, s32);
extern void fn_80015B20(void*, void*, s32);
extern void fn_802C70AC(s32, void*, s32, s32);
extern void fn_802E317C(const char*, ...);
extern char lbl_80339A20[];
#pragma scheduling invalid_target
s32 fn_801E68D4(void) {
    s32 i;
    s32 result;
    u8 *ptr;

    for (i = 0, ptr = (u8 *)lbl_8055EAC8; i < 8; ++ptr, ++i) {
        if (*ptr == 0) {
            result = lbl_80487CC0[i];
            lbl_8055EAC8[i] = 1;
            return result;
        }
    }
    return 0;
}
#pragma scheduling invalid_target
void fn_801E6924(s32 arg0) {
    s32* ptr = lbl_80487CC0;
    s32 i;
    for (i = 0; i < 8; i++) {
        if ((unsigned int)*ptr == (unsigned int)arg0) {
            lbl_8055EAC8[i] = 0;
            return;
        }
        ptr++;
    }
    fn_802E317C(&lbl_80339A20[0], arg0);
}
#pragma scheduling reset

extern char lbl_80339A20[0x40];
void fn_801E6978(void) {
    volatile s32 *var_r30 = lbl_80487CC0;
    volatile s8 *var_r29 = lbl_8055EAC8;
    s32 var_r28 = 0;

    do {
        *var_r30 = fn_8012EC90(0x4000);
        var_r28 += 1;
        *var_r29 = 0;
        var_r30 += 1;
        var_r29 += 1;
    } while (var_r28 < 8);
}

#pragma scheduling invalid_target
void fn_801E69EC(void) {
    s32* var_r31 = lbl_80487CC0;
    s32 var_r30 = 0;
    do {
        fn_8012ED20(*var_r31);
        var_r30 += 1;
        var_r31 += 1;
    } while (var_r30 < 8);
}

extern s32 *fn_801E592C(void);
extern s32 fn_801E5990(void *);
extern s32 fn_802C6FC0(s32, s32, s32);
extern void *fn_801284F8(s32, const char *);
extern void *memset(void *, int, unsigned long);
extern const char lbl_80339A48[];
extern char lbl_8055AEF8;
extern float lbl_80562D78;
extern float lbl_80562D7C;
void *fn_801E6A3C(s32 arg0, s32 arg1, s32 arg2) {
    s32 handle;
    s32 *entry;
    void *result;
    s32 i;
    float f1;
    float f0;
    float *dst;
    float *src;
    float *tail;

    handle = fn_802C6FC0(arg2, 0, 0);
    entry = fn_801E592C();
    if (entry == 0) {
        fn_802E317C(lbl_80339A48, arg0);
    }
    result = fn_801284F8(0x73C, (const char *)&lbl_8055AEF8);
    memset(result, 0, 0x73C);
    *(s32 *)((u8 *)result + 8) = fn_801E5990(entry);
    *(s32 **)((u8 *)result + 4) = entry;
    *(s32 *)result = handle;
    f1 = lbl_80562D78;
    *(float *)((u8 *)result + 0x38) = f1;
    *(s32 *)((u8 *)result + 0x10) = 0;
    *(s32 *)((u8 *)result + 0x18) = 0;
    *(s32 *)((u8 *)result + 0x1C) = -1;
    *((u8 *)result + 0xD) = 0;
    if (arg1 == 1) {
        *((u8 *)result + 0xD) = 1;
    }
    *(s32 *)((u8 *)result + 0x14) = 0;
    *((u8 *)result + 0xC) = 0;
    f0 = lbl_80562D7C;
    dst = (float *)((u8 *)result + 0x3C);
    src = (float *)((u8 *)result + 0x53C);
    tail = (float *)((u8 *)result + 0x548);
    i = 0;
    while (i < *(s32 *)((u8 *)result + 8) + 1) {
        dst[0] = f1;
        i++;
        dst[1] = f1;
        dst[2] = f1;
        dst[3] = f0;
        dst[4] = f1;
        dst[5] = f1;
        dst[6] = f1;
        dst[7] = f0;
        dst[9] = f1;
        dst[8] = f1;
        dst += 10;
        src[0] = f1;
        src[1] = f1;
        src[2] = f1;
        src += 4;
        tail[0] = f0;
        tail += 4;
    }
    return result;
}

#pragma scheduling reset
void fn_801E6B98(void* arg0) {
    s32* var_r31 = (s32*)arg0;
    s32 temp = var_r31[5];
    if (temp != 0) {
        ((void (*)(s32))fn_801E6924)(temp);
    }
    fn_801E598C(var_r31[1]);
    fn_802C6CF8(var_r31[0]);
    fn_80128668((s32)arg0);
}

extern void *fn_8012C370(const char *, unsigned int, int *, int *, unsigned char *, unsigned char *);
extern char *strcpy(char *, const char *);
extern char *fn_80029004(const char *, int);
extern void fn_80028E00(char *, const char *);
extern const char lbl_80339A64[];
extern const char lbl_80339A78[];
extern char lbl_8055AF00;
void *fn_801E6BEC(char *arg0) {
    struct {
        unsigned char sp8;
        unsigned char sp9;
        unsigned char pad[2];
        int spC;
        int sp10;
    } local;
    char *path = arg0;
    char *result;

    local.sp10 = 0;
    local.sp9 = 0;
    local.sp8 = 0;
    result = (char *)fn_8012C370(path, 0x416e696d, &local.spC, &local.sp10, &local.sp9, &local.sp8);
    if (result == 0)
        fn_802E317C(lbl_80339A64, path);
    if ((unsigned int)local.spC != 2)
        fn_802E317C(lbl_80339A78, path, local.spC, 2);
    strcpy(result + 0x10, path);
    {
        char *dot = fn_80029004(result + 0x10, 0x2e);
        if (dot != 0)
            *dot = 0;
    }
    fn_80028E00(result + 0x10, &lbl_8055AF00);
    return result;
}

void fn_801E6CC8(void* arg0, s8 arg1) {
    ((s8*)arg0)[0xC] = arg1;
}

typedef unsigned int u32;
extern int fn_8012EDA8(void *, int, u32 *);
extern void fn_802E317C(const char *, ...);
void fn_801E6CD0(void *arg0, void *arg1, float farg0) {
    u32 sp8;
    float temp_f0 = -farg0;
    *(void **)((u8 *)arg0 + 0x10) = arg1;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = -1;
    *(float *)((u8 *)arg0 + 0x38) = temp_f0;
    if (arg1 != 0 && *(s32 *)((u8 *)arg0 + 8) < *(s32 *)((u8 *)arg1 + 8))
        fn_802E317C(lbl_80339A20 + 0x80);
    {
        u8 *src = (u8 *)arg0;
        u8 *dst = (u8 *)arg0 + 0x3C;
        s32 i = 0;
        do {
            float a = *(float *)(src + 0x53C), b = *(float *)(src + 0x540);
            float c = *(float *)(src + 0x544), d = *(float *)(src + 0x548);
            *(float *)(dst + 0x10)=a; *(float *)(dst + 0x14)=b;
            *(float *)(dst + 0x18)=c; *(float *)(dst + 0x1C)=d;
            *(float *)(dst + 0)=a; *(float *)(dst + 4)=b;
            *(float *)(dst + 8)=c; *(float *)(dst + 0xC)=d;
            *(float *)(dst + 0x24)=temp_f0; *(float *)(dst + 0x20)=temp_f0;
            src += 0x10; dst += 0x28; i++;
        } while (i < *(s32 *)((u8 *)arg0 + 8) + 1);
    }
    if (arg1 != 0 && *(s32 *)arg1 > *(s32 *)((u8 *)arg1 + 4)) {
        if (*((u8 *)arg0 + 0xD) == 0) fn_802E317C(lbl_80339A20 + 0xB8);
        if (*(s32 *)((u8 *)arg0 + 0x14) == 0) *(s32 *)((u8 *)arg0 + 0x14)=fn_801E68D4();
        if (*(s32 *)((u8 *)arg0 + 0x14) == 0) { *(void **)((u8 *)arg0 + 0x10)=0; return; }
        if (fn_8012EDA8((u8 *)arg1 + 0x10, 0x416E6D30, &sp8) == 0)
            fn_802E317C(lbl_80339A20 + 0x100, (u8 *)arg1 + 0x10);
        if (sp8 != 2) fn_802E317C(lbl_80339A20 + 0x58, (u8 *)arg1 + 0x10, 2);
    } else if (*(s32 *)((u8 *)arg0 + 0x14) != 0) {
        fn_801E6924(*(s32 *)((u8 *)arg0 + 0x14));
        *(s32 *)((u8 *)arg0 + 0x14)=0;
    }
}

#pragma scheduling invalid_target
void fn_801E75C8(void* arg0, s32 arg1) {
    u8 sp[0x5c];
    s32 temp_r31;

    temp_r31 = fn_801E5E24(*(s32*)((u8*)arg0 + 4), (u8*)arg0 + 0x53c,
                             *(s32*)((u8*)arg0 + 8), sp + 0x30);
    fn_801BFD34(sp + 0x24, sp + 0x54, arg1);
    fn_80015B20(sp, sp + 0x30, arg1);
    fn_802C70AC(*(s32*)arg0, sp, temp_r31, -1);
}
#pragma scheduling reset
s32 fn_801E7650(void* arg0) {
    s32 result;
    s32* ptr;
    ptr = *(s32**)((u8*)arg0 + 0x10);
    if (ptr != 0) {
        result = 0;
        if (*(s32*)((u8*)arg0 + 0x18) >= ptr[0] && *(float*)((u8*)arg0 + 0x38) >= *(float*)((u8*)ptr + 0xC)) {
            result = 1;
        }
        return result;
    }
    return 0;
}

int fn_801E7698(void) {
    return 8;
}

