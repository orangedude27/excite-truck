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

void fn_801B435C(void*);

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

int fn_801B3390(void) {
    return 0x14;
}

void fn_801B3B24(void) {

}

void* fn_801B3BD4(void* arg0, s32 arg1) {
    if (arg0 != NULL) {
        if (arg0 != NULL) {
            if (*(void**)((u8*)arg0 + 0x1C) != NULL) {
                *(void**)arg0 = (void*)&lbl_80335DAC;
                if (*(void**)((u8*)arg0 + 0x1C) != NULL) {
                    ((void (*)(void*, s32))(*(void***)*(void**)((u8*)arg0 + 0x1C))[2])(
                        *(void**)((u8*)arg0 + 0x1C), 1);
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

void fn_801B42D0(void* arg0) {
    u8* p = (u8*)arg0 + 0x2FC;
    void* val = *(void**)lbl_802F9630;
    f64 init = lbl_80562650;
    s32 i;

    for (i = 0; i < 0x10; i++, p += 0x2C) {
        *(s32*)(p + 0x1C) = fn_802077A4(val, 5, p + 0x10, p + 4);
        *(s32*)(p + 0x20) = 0;
        *(s32*)(p + 0x24) = 0;
        *(f32*)(p + 0x28) = init;
    }
    *(s32*)((u8*)arg0 + 0x5BC) = 0;
}

