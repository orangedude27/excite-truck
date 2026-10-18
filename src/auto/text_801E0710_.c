// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"

extern f64 fn_8002F234(f32);
extern void *fn_801284E8(void *, s32);
extern unsigned int lbl_8032C108;
extern f32 lbl_80562C78;
extern f32 lbl_80562C7C;

extern void *lbl_8055EA10;

extern void NWC24Data_Init_801E1028(void *);
extern void *fn_801E07E8(void *, s32);
extern void fn_8002F53C(void *, void *, void *, s32, s32);
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_801284F8(s32, void *);
extern void fn_801E1038(void **);
extern void *fn_801E0FC4(void *);
extern void fn_801E0890(void *);
extern void fn_801E0864(void *);
extern s32 fn_802CAC28(void *, s32);
extern void fn_801777CC(void *);
extern u8 lbl_80339780[];
extern u8 lbl_80339818[];
void fn_801E0710(void) {
    void *obj;
    void *base;
    void *row;
    s32 i;
    s32 value;
    if (((u32 *)__AXFXGetLfoSinTable_801769CC())[1] & 0x200000) {
        obj = fn_801284F8(0xB78, lbl_80339780);
        if (obj != 0) {
            fn_801E1038((void **)obj);
            *(void **)obj = lbl_80339818;
            fn_801E0FC4((u8 *)obj + 0x7C);
            *(s32 *)((u8 *)obj + 4) = fn_802CAC28(lbl_80339780 + 0xC, 0);
            *(s32 *)((u8 *)obj + 8) = fn_802CAC28(lbl_80339780 + 0x1C, 0);
            fn_801E0890(obj);
            base = obj;
            row = (u8 *)obj + 0xC;
            value = -1;
            for (i = 0; i < 4; i++, row = (u8 *)row + 0x18, base = (u8 *)base + 4) {
                *(s32 *)((u8 *)base + 0x6C) = value;
                fn_801E0864(row);
            }
            fn_801777CC(obj);
            lbl_8055EA10 = obj;
        }
    }
}

void *fn_801E07E8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 value = *(s32 *)arg0;
        if (value != 0) {
            fn_80128658();
            *(s32 *)arg0 = 0;
            fn_80128670(*(s32 *)((u8 *)arg0 + 4));
            *(s32 *)((u8 *)arg0 + 4) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_801E0864(void *arg0) {
    float x;
    float y;
    y = lbl_80562C7C;
    x = lbl_80562C78;
    *(int *)arg0 = -1;
    *((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(float *)((char *)arg0 + 8) = x;
    *(float *)((char *)arg0 + 0xC) = y;
}

int fn_801E0ED4(int arg0, int arg1) {
    return arg1 > arg0 ? arg1 : arg0;
}

#pragma scheduling off
float fn_801E0EE4(void *arg0, void *arg1) {
    float delta[2];
    delta[1] = *(float *)((char *)arg0 + 4) - *(float *)((char *)arg1 + 4);
    delta[0] = *(float *)arg0 - *(float *)arg1;
    return (float)fn_8002F234(delta[0] * delta[0] + delta[1] * delta[1]);
}
#pragma scheduling on
void fn_801E0F34(int arg0) {
    void *ptr;
    int value = arg0;
    int size = (arg0 << 3) + 8;
    ptr = fn_801284E8((void *)lbl_8032C108, size);
    *(int *)((char *)ptr + 4) = value;
    *(int *)ptr = value;
}

void fn_801E0F78(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    f32 x = arg2[0];
    f32 y = arg2[1];
    f32 b = arg1[1];
    f32 a = arg1[0];
    arg0[0] = a + x * arg3;
    arg0[1] = b + y * arg3;
}

f32 fn_801E0FA4(f32 *arg0, f32 *arg1) {
    f32 a = arg1[1];
    f32 b = arg0[1];
    f32 c = arg1[0];
    f32 d = arg0[0];
    f32 x = b * a;
    f32 y = d * c;
    return y + x;
}

void *fn_801E0FC4(void *arg0) {
    void *temp_r6 = (u8 *)arg0 + 0xC;
    ((s32 *)arg0)[2] = 0x64;
    ((void **)arg0)[0] = temp_r6;
    ((s32 *)arg0)[1] = 0;
    fn_8002F53C(temp_r6, NWC24Data_Init_801E1028, fn_801E07E8, 0x1C, 0x64);
    return arg0;
}

void NWC24Data_Init_801E1028(void *arg0) {
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
}

extern void lbl_8032CE98(void);
void fn_801E1038(void **arg0) {
    *arg0 = (void *)&lbl_8032CE98;
}

void fn_801E1250(s32 arg0, s8 arg1) {
    typedef struct { u8 pad0[0xC]; s32 first; u8 pad10[0x14]; s32 second; u8 pad28[8]; } Rec;
    Rec *p = (Rec *)lbl_8055EA10;
    if (p == 0) return;
    if (arg0 == p->first) p->pad10[0] = arg1;
    if (arg0 == p->second) p->pad28[0] = arg1;
    p++;
    if (arg0 == p->first) p->pad10[0] = arg1;
    if (arg0 == p->second) p->pad28[0] = arg1;
}

extern s32 fn_801E85B4(void);
extern s32 fn_801E866C(void);
extern void fn_801E1384(s32, s32);
extern s32 fn_801E1510(s32 *, s32);
extern s32 fn_801E137C(void *);
extern void fn_802C8BD0(void *);
extern void fn_802C8D74(void);
void fn_801E12A4(void) {
    u8 *obj = (u8 *)lbl_8055EA10;
    s32 slot;
    s32 i;
    s32 *entry;
    if (obj != 0) {
        slot = fn_801E85B4();
        *(s32 *)(obj + slot * 4 + 0x6C) = fn_801E866C();
        fn_802C8BD0(*(void **)(obj + 4));
        entry = (s32 *)(obj + slot * 0x18);
        i = 0;
        goto loop1;
loop1:
        fn_801E1384(fn_801E1510((s32 *)(obj + 0x7C), i), *(s32 *)(entry + 8));
        i++;
        if (i < fn_801E137C(obj + 0x7C)) goto loop1;
        fn_802C8D74();
        fn_802C8BD0(*(void **)(obj + 8));
        i = 0;
        goto loop2;
loop2:
        fn_801E1384(fn_801E1510((s32 *)(obj + 0x7C), i), *(s32 *)(entry + 7));
        i++;
        if (i < fn_801E137C(obj + 0x7C)) goto loop2;
        fn_802C8D74();
    }
}

s32 fn_801E137C(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_801E1510(s32 *arg0, s32 arg1) { return *arg0 + arg1 * 0x1C; }

void fn_801E1520(void) {
    struct Obj { void **vtable; };
    void *obj = lbl_8055EA10;
    if (obj != 0) {
        if (obj != 0) {
            void (*call)(void *, s32);
            call = (void (*)(void *, s32))((struct Obj *)obj)->vtable[7];
            call(obj, 1);
        }
        lbl_8055EA10 = 0;
    }
}

void fn_801E1684(void) {

}

void fn_801E1688(void) {

}

#pragma push
#pragma scheduling off
void fn_801E168C(void *arg0) {
    f32 y = lbl_80562C7C;
    f32 x = lbl_80562C78;
    *(s32 *)((u8 *)arg0 + 0x6C) = -1;
    *(s32 *)((u8 *)arg0 + 0x0C) = -1;
    *(u8 *)((u8 *)arg0 + 0x10) = 0;
    *(s32 *)((u8 *)arg0 + 0x1C) = 0;
    *(s32 *)((u8 *)arg0 + 0x20) = 0;
    *(f32 *)((u8 *)arg0 + 0x14) = x;
    *(f32 *)((u8 *)arg0 + 0x18) = y;
    *(s32 *)((u8 *)arg0 + 0x70) = -1;
    *(s32 *)((u8 *)arg0 + 0x24) = -1;
    *(u8 *)((u8 *)arg0 + 0x28) = 0;
    *(s32 *)((u8 *)arg0 + 0x34) = 0;
    *(s32 *)((u8 *)arg0 + 0x38) = 0;
    *(f32 *)((u8 *)arg0 + 0x2C) = x;
    *(f32 *)((u8 *)arg0 + 0x30) = y;
    *(s32 *)((u8 *)arg0 + 0x74) = -1;
    *(s32 *)((u8 *)arg0 + 0x3C) = -1;
    *(u8 *)((u8 *)arg0 + 0x40) = 0;
    *(s32 *)((u8 *)arg0 + 0x4C) = 0;
    *(s32 *)((u8 *)arg0 + 0x50) = 0;
    *(f32 *)((u8 *)arg0 + 0x44) = x;
    *(f32 *)((u8 *)arg0 + 0x48) = y;
    *(s32 *)((u8 *)arg0 + 0x78) = -1;
    *(s32 *)((u8 *)arg0 + 0x54) = -1;
    *(u8 *)((u8 *)arg0 + 0x58) = 0;
    *(s32 *)((u8 *)arg0 + 0x64) = 0;
    *(s32 *)((u8 *)arg0 + 0x68) = 0;
    *(f32 *)((u8 *)arg0 + 0x5C) = x;
    *(f32 *)((u8 *)arg0 + 0x60) = y;
}
#pragma pop
void fn_801E1868(void) {

}

