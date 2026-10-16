// Code of main that had no source file yet: decomp.wtf gave it this one.

#include <types.h>
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_801B2ED0(s32);
typedef struct {
    void *pad[4];
    s32 (*fn)(void);
} VTable8014ACD8;
typedef struct {
    VTable8014ACD8 *vtable;
    u8 pad[0x20];
    s32 state;
    u8 flags;
} Obj8014ACD8;

extern s32 fn_80161C94(void);
extern void fn_801B8A84(s32);
extern s32 fn_801B2F24(void);
extern s32 fn_801B8514(void);
extern s32 lbl_804348E8[];
extern void fn_801B8A7C(void);
extern s32 lbl_8032E030[];
extern s32 lbl_8032E048[];
extern s32 lbl_8055E4D0;
typedef struct {
    s32 pad[8];
    s32 (*fn)(void *, s32);
} VTable80154618;
extern void fn_802E30C8();
typedef struct { s32 v[4]; } S4_80149234;
extern s32 lbl_802F93D0[];
extern f32 lbl_805615D4;
extern f64 lbl_805615D8;
extern f32 lbl_80561628;
extern f32 lbl_8056162C;
extern f32 lbl_80561630;
extern f32 lbl_80561634;

void fn_80149210(void *arg0) {
    u32 x = ((u32 *)arg0)[1] + 1;
    u32 t = x << 30;
    u32 b = x >> 31;
    ((u32 *)arg0)[1] = (((t - b) << 2) | ((t - b) >> 30)) + b;
}

s32 fn_80149234(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F93D0;
    return sp8.v[((s32 *)arg0)[1]];
}

s32 fn_80149274(void **arg0) {
    s32 (*fn)(void *) = ((void **)*arg0)[4];
    return fn(arg0) & 0xFF7F7F7F;
}

void fn_801492AC(void *arg0, f32 *arg1, s32 arg2) {
    u8 *obj = (u8 *)(arg2 + ((s32 *)arg0)[1]);
    f32 f2 = lbl_80561628;
    f32 b = *arg1;
    f32 v = b + (f32)obj[0x18];
    f2 = (f2 < v) ? f2 : v;
    f2 = (f2 > lbl_805615D4) ? f2 : lbl_805615D4;
    obj[0x18] = (u8)(s32)f2;
}

extern s32 lbl_802F93E0[];
s32 fn_8014931C(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F93E0;
    return sp8.v[((s32 *)arg0)[1]];
}

extern s32 lbl_802F93F0[];
s32 fn_80149380(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F93F0;
    return sp8.v[((s32 *)arg0)[1]];
}

void fn_801493F8(void *arg0, f32 *arg1, s32 arg2) {
    u8 *obj = (u8 *)(arg2 + ((s32 *)arg0)[1]);
    f32 f2 = lbl_80561628;
    f32 b = *arg1;
    f32 v = b + (f32)obj[0x18];
    f2 = (f2 < v) ? f2 : v;
    f2 = (f2 > lbl_805615D4) ? f2 : lbl_805615D4;
    obj[0x18] = (u8)(s32)f2;
}

extern s32 lbl_802F9400[];
s32 fn_80149468(void *arg0) {
    S4_80149234 sp8;
    sp8 = *(S4_80149234 *)lbl_802F9400;
    return sp8.v[((s32 *)arg0)[1]];
}

s32 fn_801494A8(void) {
    return 0xFF00FF00;
}

void fn_801494B4(void *arg0, f32 *arg1, f32 *arg2) {
    f32 y = arg2[1] + arg1[0];
    f32 z = arg2[2] + arg1[1];
    arg2[1] = y;
    arg2[2] = z;
}

int fn_801494E0(void) { return 0xFF0000FF; }

void fn_801494EC(void *arg0, float *arg1, float *arg2) {
    float temp_f1 = arg1[0];
    float temp_f3 = arg1[1];
    arg2[1] += temp_f1;
    arg2[4] -= temp_f1;
    arg2[2] += temp_f3;
    arg2[5] -= temp_f3;
}

extern unsigned long lbl_80559E94;
extern unsigned long lbl_80559E9C;
unsigned long *fn_80149528(void) { return &lbl_80559E9C; }

int fn_80149530(void) {
    return 0xFFC0D9D9;
}

void fn_8014953C(void *arg0, float *arg1, float *arg2) {
    float value = arg2[4] + lbl_8056162C * *arg1;
    if (value < lbl_80561630) value = lbl_80561630;
    if (value > lbl_80561634) value = lbl_80561634;
    arg2[4] = value;
}

s32 fn_8014ACBC(void) { return 0; }

s32 fn_8014ACC4(void) { return 0; }

void fn_8014ACCC(void) {

}

void fn_8014ACD0(void) {

}

void fn_8014ACD4(void) {

}

void fn_8014AED0(void *arg0, f32 farg0) {
    ((f32 *)arg0)[0x41] = farg0;
}

f32 fn_8014AED8(void *arg0) {
    return ((f32 *)arg0)[0x41];
}

u8 fn_8014AEE0(void *arg0) {
    return ((u8 *)arg0)[5];
}

u8 fn_8014AEE8(void *arg0) {
    return ((u8 *)arg0)[4];
}

s32 fn_8014C830(s32 arg0) { return arg0 + 0x14; }

void fn_8014DE4C(void) {

}

void fn_8014E704(void) {

}

void fn_8014E7D8(void) {

}

  extern void fn_80128668(void);
extern void fn_8016783C(void *arg0);
extern void fn_801688FC(s32 arg0);
extern void fn_80168020(void);
extern void fn_8016A0D4(void);
extern void *memset(void *arg0, s32 arg1, s32 arg2);
extern s32 fn_801284F8(s32 arg0, void *arg1);
extern s32 fn_802ADDD8(s32 arg0);
extern void fn_8014F194(void *arg0);
extern s32 fn_80145E70(void *arg0);
extern s32 lbl_8032DB34;
extern s32 lbl_8032DB40;
s32 *fn_801500F8(void *arg0, s32 *arg1) {
    s32 value = *arg1;
    s32 index = ((s32 *)arg0)[1];
    s32 *data = *(s32 **)arg0;
    ((s32 *)arg0)[1] = index + 1;
    data[index] = value;
    return &data[index];
}

s32 fn_80150AD8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80150B18(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80150B58(void *arg0, s32 arg1) {
    ((s32 *)arg0)[8] = arg1;
}

void fn_80150B60(void *arg0) {
    fn_8016783C(arg0);
    if (((u8 *)arg0)[0x8F4] != 0) {
        memset((char *)arg0 + 0x8F8, 0, 0xE0);
        fn_801688FC(1);
        fn_80168020();
    }
    fn_8016A0D4();
    if (((void **)arg0)[0x113] != 0) {
        ((u8 *)arg0)[0x450] = 0;
        ((u8 *)(((void **)arg0)[0x113]))[0x4A] = 1;
        ((u8 *)(((void **)arg0)[0x113]))[0x4C] = 0;
    }
}

void fn_80151688(void) {

}

void fn_80151914(void) {

}

void fn_801537C8(void) {

}

u32 fn_80153AC8(void) { return 1; }

u32 fn_80153CF8(void) { return 1; }

void fn_80154580(s32 arg0, void *arg1) {
    s32 *p;
    s32 i;
    s32 *q = (s32 *)arg1;
    fn_801B8A7C();
    fn_802E30C8(lbl_8032E030);
    p = (s32 *)(arg0 + 0x9E4);
    for (i = 0; i < lbl_8055E4D0; i++) {
        s32 v = *(s32 *)((u8 *)p + 0x90);
        *(s32 *)((u8 *)q + 0x18) = v;
        fn_802E30C8(lbl_8032E048, i, v);
        p = (s32 *)((u8 *)p + 0xC0);
        q = (s32 *)((u8 *)q + 0x14);
    }
}

s32 fn_80154618(void *arg0) {
    s32 **it = (s32 **)&lbl_804348E8;
    s32 found = 0;
    s32 i = 0;
    while (i < fn_801B2F24()) {
        if (*(s32 *)((u8 *)*it + 0x1F0) == 0x50) {
            if (((VTable80154618 *)(*(s32 **)arg0))->fn(arg0, i) != 0) {
                found = 1;
            }
        }
        it++;
        i++;
    }
    it = (s32 **)0;
    if (found == 0) {
        if (fn_801B8514() != 0) {
            it = (s32 **)1;
        }
    }
    return (s32)it;
}

void fn_801546D4(s32 arg0) {
    switch (fn_80161C94()) {
        case 0:
            fn_801B8A84(arg0);
            break;
    }
}

s32 fn_80154714(void) {
    return 1;
}

extern void fn_801B0F70(s32, s32);
extern void fn_80168104(void);
void fn_8015471C(s32 arg0, s32 arg1, s32 arg2) {
    fn_801B0F70(arg1, arg2);
}

void fn_80154728(void *arg0) {
    if (((u8 *)arg0)[0x8F4] != 0) {
        fn_80168104();
    }
}

s32 fn_8015473C(void) {
    return 0;
}

void fn_80154744(void) {

}

void fn_80154748(void) {

}

void fn_8015474C(void) {

}

void fn_80154750(void) {

}

void fn_80155368(void) {

}

void fn_801556F0(void) {

}

void fn_801556F4(void) {

}

void fn_801556F8(void) {

}

void fn_801556FC(void) {

}

void fn_80155AEC(void) {

}

u32 fn_80155C88(void) { return 1; }

void fn_80155E58(void *arg0) {
    ((u8 *)arg0)[4] = 0;
}

void fn_801560F4(void) {

}

void fn_80156100(void) {

}

void fn_80156104(void) {

}

void fn_80156108(void) {

}

s32 fn_8014F0C8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8014F108(void *arg0) {
    void *ptr = arg0;
    s32 i;
    for (i = 0; i < 2; i++) {
        s32 result = fn_801284F8(8, &lbl_8032DB34);
        if (result == 0) {
            result = fn_802ADDD8(2);
        }
        ((s32 *)ptr)[0x117] = result;
        fn_8014F194((void *)((u8 *)ptr + 0x454));
        ptr = (void *)((u8 *)ptr + 0x240);
    }
    ((s32 *)arg0)[0x276] = fn_80145E70(&lbl_8032DB40);
}
extern unsigned long lbl_80559E94;
extern unsigned long lbl_80559E9C;
