// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
typedef signed char s8;
typedef long s32;

void fn_801E6CC4(void) {
    fn_8012C4D8();
}

extern void fn_801E6924();
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
#pragma scheduling reset
void fn_801E6924(void* arg0) {
    s32* var_r31 = lbl_80487CC0;
    s8* var_r30 = lbl_8055EAC8;
    s32 var_r6;
    for (var_r6 = 0; var_r6 < 8; var_r6++) {
        if (var_r31[var_r6] == (s32)arg0) {
            var_r30[var_r6] = 0;
            return;
        }
    }
    fn_802E317C(&lbl_80339A20[0], arg0);
}
#pragma dont_inline off

extern char lbl_80339A20[0x40];
void fn_801E6978(void) {
    s32* var_r30 = lbl_80487CC0;
    s8* var_r29 = lbl_8055EAC8;
    s8* var_r28_2 = lbl_8055EAC8;
    s32 var_r28 = 0;
    do {
        *var_r30++ = fn_8012EC90(0x4000);
        var_r28 += 1;
        *var_r29++ = 0;
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
        ((void (*)(s32))fn_801E6924)(*(s32 *)((u8 *)arg0 + 0x14));
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

