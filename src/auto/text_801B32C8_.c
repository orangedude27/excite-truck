// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <stddef.h>

extern f32 lbl_8055E3C8;
extern f32 lbl_80562630;
extern f32 lbl_80562650;
extern s32 lbl_802F9630[39];
extern void fn_80128670(s32);
extern void fn_80128668(void*);
extern void fn_8002F634(void*, void*, s32, s32);
extern void* fn_801B3BD4(void*, s32);
extern s32 fn_802077A4();
extern s32 lbl_80335DAC[3];
extern f32 lbl_80562624;
extern void fn_8002F53C(void*, void*, void*, s32, s32);
extern void fn_801B3FD8(void*);
extern void fn_801B4204(void*);
extern void fn_801B537C(void*);
extern s32 fn_801B3398(void*);
extern void fn_801B3C64(void*);
extern void* fn_801B3D24(void*, s32);
extern void fn_801B42D0(void*);
extern s32 lbl_8055E6C0;
extern u8 lbl_80335D3C[];
extern s32 fn_801284F8(s32, void*);
extern s32 fn_801B5364(s32, void*);
extern s32 fn_801B3398(void*);
void* fn_801B3B70(void*);
extern void* memset(void*, s32, u32);
extern u8 lbl_80435C50[0x20];

void fn_801B435C(void*);
void fn_801B3DBC(void*);

typedef void (*Dtor1Arg)(void*, s32);

static void callPrevDtor(void* p) {
    Dtor1Arg fn = ((Dtor1Arg*)*(void***)p)[2];
    fn(p, 1);
}

typedef struct Unk801B3BD4 {
    Dtor1Arg unk_0x0[3];
    s32 unk_0xC[4];
    void* unk_0x1C;
} Unk801B3BD4;

typedef struct Unk801B3398 {
    s32 unk_0x00;
    s32 unk_0x04;
    s32 unk_0x08;
    s32 unk_0x0C;
    s32 unk_0x10;
    s32 unk_0x14;
    s32 unk_0x18;
    s32 unk_0x1C;
    s32 unk_0x20;
    s32 unk_0x24;
    s32 unk_0x28;
    s32 unk_0x2C;
    s32 unk_0x30;
    s32 unk_0x34;
} Unk801B3398;

s32 fn_801B32C8(void* arg0, s32 arg1) {
    s32 vals[2];
    s32 idx = -1;
    s32 result = 0;

    if (*(s32*)((char*)arg0 + 0x20) == 0x6D) {
        idx = 0;
    } else if (arg1 == 0x6D) {
        idx = 1;
    }
    vals[0] = *(s32*)((char*)arg0 + 0x20);
    vals[1] = arg1;
    if (idx != -1) {
        switch (vals[!idx]) {
        case 0x6E:
        case 1:
            result = 1;
            break;
        }
    }
    return result;
}

void* fn_801B3338(void* arg0) {
    s32 found = 0;
    s32* obj = *(s32**)((char*)arg0 + 4);

    if (obj != NULL) {
        if ((u32)(obj[4] - 0x43410000) == 0x5220
            || (u32)(obj[4] - 0x50430000) == 0x4152
            || (u32)(obj[4] - 0x41430000) == 0x4152
            || (u32)(obj[4] - 0x4E430000) == 0x4152) {
            found = 1;
        }
    }
    if (found != 0) {
        return obj;
    }
    return NULL;
}

int fn_801B3390(void) {
    return 0x14;
}

s32 fn_801B3398(void* arg0) {
    Unk801B3398 local;
    s32* src = (s32*)arg0;
    s32 t0, t1, t2, t3, t4, t5, t6, t7;
    s32 t8, t9, t10, t11, t12, t13;

    t0 = src[0];
    t1 = src[1];
    t2 = src[2];
    t3 = src[3];
    t4 = src[4];
    t5 = src[5];
    t6 = src[6];
    t7 = src[7];
    t8 = src[8];
    t9 = src[9];
    t10 = src[10];
    t11 = src[11];
    t12 = src[12];
    t13 = src[13];
    local.unk_0x00 = t0;
    local.unk_0x04 = t1;
    local.unk_0x08 = t2;
    local.unk_0x0C = t3;
    local.unk_0x10 = t4;
    local.unk_0x14 = t5;
    local.unk_0x18 = t6;
    local.unk_0x1C = t7;
    local.unk_0x20 = t8;
    local.unk_0x24 = t9;
    local.unk_0x28 = t10;
    local.unk_0x2C = t11;
    local.unk_0x30 = t12;
    local.unk_0x34 = t13;
    fn_801796CC(1, &local, 0x38);
    return 0x38;
}
#pragma use_lmw_stmw reset
void fn_801B3448(void) {
    void* p = (void*)fn_801284F8(0x5C0, &lbl_80335D3C);
    if (p == NULL) {
        return;
    }
    p = fn_801B3B70(p);
    lbl_8055E6C0 = (s32)p;
    fn_801B5364(1, fn_801B3390);
    fn_801B5364(0xF, fn_801B3398);
}

#pragma scheduling off
void fn_801B34A4(void) {
    fn_801B3DBC((void*)lbl_8055E6C0);
    memset(lbl_80435C50, 0, 0x20);
}
#pragma scheduling reset
void fn_801B3B24(void) {

}

void fn_801B3B28(void) {
    fn_801B537C(fn_801B3390);
    fn_801B537C(fn_801B3398);
    fn_801B3D24((void*)lbl_8055E6C0, 1);
    lbl_8055E6C0 = 0;
}

#pragma scheduling off
void* fn_801B3B70(void* arg0) {
    fn_8002F53C((u8*)arg0 + 0x2FC, fn_801B3C64, fn_801B3BD4, 0x2C, 0x10);
    fn_801B3FD8(arg0);
    fn_801B4204(arg0);
    fn_801B42D0(arg0);
    return arg0;
}
#pragma scheduling reset
void* fn_801B3BD4(void* arg0, s32 arg1) {
    if (arg0 != NULL) {
        if (arg0 != NULL) {
            void* prev = *(void**)((u8*)arg0 + 0x1C);
            *(void**)arg0 = (void*)&lbl_80335DAC;
            if (prev != NULL) {
                if (prev != NULL) {
                    (*(void (**)(void*, s32))(*(void***)prev + 2))(prev, 1);
                }
                *(void**)((u8*)arg0 + 0x1C) = NULL;
            }
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_801B3C64(void* arg0) {
    u8* p = (u8*)arg0;
    f32 zero = lbl_80562624;
    s32 i;

    *(void**)p = (void*)&lbl_80335DAC;
    for (i = 4; i < 0x1C; i += 4) {
        *(f32*)(p + i) = zero;
    }
    *(s32*)(p + 0x1C) = 0;
}

typedef void (*Vfn2)(void*, s32);
void* fn_801B3C98(void* arg0, s32 arg1) {
    if (arg0 != NULL) {
        void* prev = *(void**)((u8*)arg0 + 0x1C);
        *(void**)arg0 = (void*)&lbl_80335DAC;
        if (prev != NULL) {
            if (prev != NULL) {
                Vfn2 fn = ((Vfn2*)*(void***)prev)[2];
                fn(prev, 1);
            }
            *(void**)((u8*)arg0 + 0x1C) = NULL;
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma scheduling off
void* fn_801B3D24(void* arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32* p = (s32*)arg0;
        s32 i;

        for (i = 0; i < 6; i++) {
            fn_80128670(*p);
            p += 3;
        }
        fn_8002F634((u8*)arg0 + 0x2FC, (void*)fn_801B3BD4, 0x2C, 0x10);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma scheduling reset
void fn_801B3DBC(void* arg0) {
    fn_801B435C(arg0);
}

s32 fn_801B3DC0(void* arg0, u32 arg1, u32 arg2) {
    u8* p = (u8*)arg0 + 0x2FC;
    s32 found = 0;
    s32 i = 0;

    while (found == 0 && i < 0x10) {
        found = 0;
        if (*(u32*)(p + 0x20) == arg1 && *(u32*)(p + 0x24) == arg2
            && *(f32*)(p + 0x28) > lbl_8055E3C8 - lbl_80562630) {
            found = 1;
        }
        p += 0x2C;
        i++;
    }
    return found;
}

s32 fn_801B3FD0(void) {
    return 0;
}

#pragma scheduling off
void fn_801B42D0(void* arg0) {
    u8* p = (u8*)arg0 + 0x2FC;
    void* val = *(void**)lbl_802F9630;
    f32 init = lbl_80562650;
    s32 i;

    for (i = 0; i < 0x10; i++, p += 0x2C) {
        *(s32*)(p + 0x1C) = fn_802077A4(val, 5, p + 0x10, p + 4);
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x24) = 0;
        *(f32*)(p + 0x28) = init;
    }
    *(s32*)((u8*)arg0 + 0x5BC) = 0;
}
#pragma scheduling reset
