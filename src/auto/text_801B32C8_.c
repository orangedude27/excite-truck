// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <stddef.h>

#pragma cplusplus on
struct VTable_801B3C98 {
    virtual void destroy(s32);
};
#pragma push
#pragma scheduling invalid_target
extern "C" static inline void callPrevDtorCpp_801B3BD4(void *p) {
    ((VTable_801B3C98 *)p)->destroy(1);
}
#pragma pop
#pragma cplusplus reset

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

typedef struct V3_801B34DC { f32 x, y, z; } V3_801B34DC;
typedef struct Ev38_801B34DC { V3_801B34DC a, b, c, d; s32 id; s32 kind; } Ev38_801B34DC;
typedef struct Ev14_801B34DC { s32 id; V3_801B34DC p; f32 w; } Ev14_801B34DC;
typedef struct Ev20_801B34DC { V3_801B34DC p; V3_801B34DC q; s16 s; s32 id; } Ev20_801B34DC;
typedef struct Ev30_801B34DC { V3_801B34DC p; V3_801B34DC q; V3_801B34DC r; f32 dot; s32 id; s32 kind; } Ev30_801B34DC;
extern f32 PSVECDotProduct(void *, void *);
extern f32 PSVECMag(void *);
extern s32 lbl_8055E3C4;
extern void fn_8017B6D4(void *, void *, void *);
extern void fn_801796CC(s32, void *, s32);
extern void fn_801B5360(s32, void *, s32);
extern void fn_801B85E0(void *, void *, void *, void *);
extern void fn_801B3084(void *, void *, void *, void *);
extern f32 lbl_80562620, lbl_80562628, lbl_8056262C, lbl_80562634, lbl_80562638, lbl_8056263C, lbl_80562640, lbl_80562644, lbl_80562648;
extern void* fn_801B3338(void*);
extern s32 fn_801B32C8(void*, s32);
extern s32 fn_801B3DC0(void*, u32, u32);
extern void fn_801B3E24(void *, void *, void *, s32, s32, f32);

typedef struct Ent801B3FD8 { s32 a; s32 group; f32 c; } Ent801B3FD8;
typedef struct Out801B3FD8 { Ent801B3FD8* p; s32 n; s32 z; } Out801B3FD8;

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

#pragma scheduling invalid_target
s32 fn_801B32C8(void* arg0, s32 arg1) {
    s32 vals[2];
    s32 first = *(s32*)((char*)arg0 + 0x20);
    register s32 idx;
    s32 result = 0;
    s32 isMagic = (first == 0x6D);

    *(volatile s32*)&vals[0] = first;
    idx = -1;
    *(volatile s32*)&vals[1] = arg1;
    if (isMagic) {
        idx = 0;
    } else if (arg1 == 0x6D) {
        idx = 1;
    }
    if (idx != -1) {
        switch (vals[!idx]) {
        case 0x6E:
        case 1:
            result = 1;
            break;
        default:
            break;
        }
    }
    return result;
}
#pragma scheduling on
void* fn_801B3338(void* arg0) {
 s32* obj=*(s32**)((char*)arg0+4);
 if(obj!=NULL) {
   s32 found=0;
   s32 magic=obj[4];
   if((u32)(magic-0x43410000)==0x5220
      || (u32)(magic-0x50430000)==0x4152
      || (u32)(magic-0x41430000)==0x4152
      || (u32)(magic-0x4E430000)==0x4152) found=1;
   if(found!=0) return obj;
 }
 return NULL;
}

int fn_801B3390(void) {
    return 0x14;
}

s32 fn_801B3398(void* arg0) {
 Unk801B3398 local;
 s32* src=(s32*)arg0;
 s32 t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13;
 t0=src[0]; t1=src[1]; t2=src[2]; t3=src[3]; t4=src[4]; t5=src[5]; t6=src[6];
 t7=src[7]; t8=src[8]; t9=src[9]; t10=src[10]; t11=src[11]; t12=src[12]; t13=src[13];
 local.unk_0x00=t0; local.unk_0x04=t1; local.unk_0x08=t2; local.unk_0x0C=t3;
 local.unk_0x10=t4; local.unk_0x14=t5; local.unk_0x18=t6; local.unk_0x1C=t7;
 local.unk_0x20=t8; local.unk_0x24=t9; local.unk_0x28=t10; local.unk_0x2C=t11;
 local.unk_0x30=t12; local.unk_0x34=t13;
 fn_801796CC(1,&local,0x38);
 return 0x38;
}
#pragma scheduling invalid_target
void fn_801B3448(void) {
    void *p;
    int (*callback)(void);
    p = (void *)fn_801284F8(0x5C0, &lbl_80335D3C);
    if (p == NULL) return;
    p = fn_801B3B70(p);
    callback = fn_801B3390;
    lbl_8055E6C0 = (s32)p;
    fn_801B5364(1, callback);
    fn_801B5364(0xF, fn_801B3398);
}
#pragma scheduling on
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

#pragma scheduling invalid_target
void *fn_801B3B70(void *arg0) {
    fn_8002F53C((u8 *)arg0 + 0x2FC, fn_801B3C64, fn_801B3BD4, 0x2C, 0x10);
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
                if (prev != NULL)
                    callPrevDtorCpp_801B3BD4(prev);
                *(void**)((u8*)arg0 + 0x1C) = NULL;
            }
        }
        if (arg1 > 0)
            fn_80128668(arg0);
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
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_801B3C98(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        void *prev = *(void **)((u8 *)arg0 + 0x1C);
        *(void **)arg0 = (void *)&lbl_80335DAC;
        if (prev != NULL) {
            if (prev != NULL)
                ((VTable_801B3C98 *)prev)->destroy(1);
            *(void **)((u8 *)arg0 + 0x1C) = NULL;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}
#pragma cplusplus reset
#pragma scheduling on
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

extern void* fn_801B4570(void*, u32);
extern f32 lbl_8056264C;
#pragma cplusplus on
extern "C" void fn_801B3E24(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, f32 farg0) {
    class Item {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual s32 compare(s32);
        virtual void f4();
        virtual void f5();
        virtual void reset();
        virtual s32 getMode();
    };
    s32 first = *(s32 *)((u8 *)arg2 + 0x20);
    u32 packed;
    void *row;
    void *item;
    Item *object;
    void *selected;
    s32 selectedKey;
    f32 z;
    f32 y;
    f32 x;
    f32 zero;
    f32 candidate;
    f32 maximum;
    s32 index;
    volatile f32 unused[3];

    if (first < 0 || arg4 < 0) {
        packed = 0xFFFFFFFF;
    } else if (first >= arg4) {
        packed = ((u32)first & 0xFFFF) | ((u32)arg4 << 16);
    } else {
        packed = ((u32)arg4 & 0xFFFF) | ((u32)first << 16);
    }
    selected = fn_801B4570(arg0, packed);
    selectedKey = *(s32 *)selected;
    index = *(s32 *)((u8 *)arg0 + 0x5BC);
    row = (u8 *)arg0 + index * 0x2C;
    item = *(void **)((u8 *)row + 0x318);
    object = *(Item **)((u8 *)item + 0xC);
    if (object->getMode() != 3)
        object->reset();
    if (object->compare(selectedKey) != 0) {
        *(volatile void **)((u8 *)row + 0x31C) = arg2;
        maximum = lbl_8056264C;
        *(volatile s32 *)((u8 *)row + 0x320) = arg3;
        *(volatile f32 *)((u8 *)row + 0x324) = lbl_8055E3C8;
        candidate = farg0 * *(f32 *)((u8 *)selected + 4);
        if (maximum > candidate)
            maximum = candidate;
        zero = lbl_80562624;
        x = *(f32 *)arg1;
        *(volatile f32 *)((u8 *)row + 0x30C) = zero;
        y = *(f32 *)((u8 *)arg1 + 4);
        *(volatile f32 *)((u8 *)row + 0x310) = zero;
        z = *(f32 *)((u8 *)arg1 + 8);
        *(volatile f32 *)((u8 *)row + 0x314) = zero;
        *(f32 *)((u8 *)row + 0x300) = x;
        *(f32 *)((u8 *)row + 0x304) = y;
        *(f32 *)((u8 *)row + 0x308) = z;
        item = *(void **)((u8 *)row + 0x318);
        unused[0] = zero;
        unused[1] = zero;
        unused[2] = zero;
        if (item != 0) {
            if (maximum != *(f32 *)((u8 *)item + 8)) {
                *((u8 *)item + 0x4D) = 1;
                *(f32 *)((u8 *)item + 8) = maximum;
            }
            item = *(void **)((u8 *)row + 0x318);
            *((u8 *)item + 0x49) = 1;
            *((u8 *)item + 0x4B) = 0;
            *((u8 *)item + 0x4A) = 0;
        }
        index = (*(s32 *)((u8 *)arg0 + 0x5BC) + 1) % 16;
        *(s32 *)((u8 *)arg0 + 0x5BC) = index;
    }
}
#pragma cplusplus reset
s32 fn_801B3FD0(void) {
    return 0;
}

extern char lbl_80335D50[];
extern u8 lbl_80335D74[];
extern void fn_802E317C(const char*, ...);
extern void* fn_8012850C(s32, void*);
void fn_801B3FD8(void* arg0) {
    Out801B3FD8* out = (Out801B3FD8*)arg0;
    Ent801B3FD8* tbl = (Ent801B3FD8*)lbl_802F9630;
    Ent801B3FD8* p = tbl;
    s32 g = 0, start, i;
    u32 pos = 0;
    s32 n;
    for (; g < 6; g++, out++) {
        start = pos;
        while (pos < 13 && g == p->group) { p++; pos++; }
        n = pos - start;
        if (n < 1) fn_802E317C(lbl_80335D50, g);
        out->p = fn_8012850C(n * 8, lbl_80335D74);
        out->n = n;
        out->z = 0;
        for (i = 0; i < n; i++) {
            ((s32*)out->p)[i * 2] = tbl[start + i].a;
            ((f32*)out->p)[i * 2 + 1] = tbl[start + i].c;
        }
    }
}

extern s32 lbl_802F96CC[];
extern s32 fn_801B4428(u32 *, u32 *);
extern void *fn_801B447C(void *, void *, s32);
extern void qsort(void *, u32, u32, s32 (*)(u32 *, u32 *));
void fn_801B4204(void *arg0) {
    s32 i;
    s32 *src;
    u8 *dst;
    s32 a;
    s32 b;
    s32 key;
    s32 n;

    src = lbl_802F96CC;
    dst = (u8 *)arg0 + 0x48;
    for (i = 0; i < 0x2B; i++) {
        a = src[1];
        b = src[2];
        if (a < 0 || b < 0) {
            key = -1;
        } else if (a >= b) {
            key = (a & 0xFFFF) | (b << 16);
        } else {
            key = (b & 0xFFFF) | (a << 16);
        }
        n = src[0];
        *(s32 *)(dst + 0) = key;
        *(s32 *)(dst + 4) = (s32)arg0 + n * 0xC;
        *(s32 *)(dst + 8) = 0;
        *(s32 *)(dst + 0xC) = 0;
        src += 3;
        dst += 0x10;
    }
    qsort((u8 *)arg0 + 0x48, 0x2B, 0x10, fn_801B4428);
    *(void **)((u8 *)arg0 + 0x2F8) = fn_801B447C(arg0, (u8 *)arg0 + 0x48, 0x2B);
}

#pragma scheduling off
void fn_801B42D0(void* arg0) {
 void* val=*(void**)lbl_802F9630;
 f64 init=lbl_80562650;
 u8* p=(u8*)arg0+0x2fc;
 s32 i=0;
 s32 zero=0;
 while(i<0x10) {
   *(s32*)(p+0x1c)=fn_802077A4(val,5,p+0x10,p+4);
   i++;
   if(i>=0x10) break;
   *(s32*)(p+0x20)=zero;
   *(s32*)(p+0x24)=zero;
   *(f32*)(p+0x28)=init;
   p+=0x2c;
 }
 *(s32*)((u8*)arg0+0x5bc)=0;
}

#pragma scheduling on
void fn_801B435C(void *arg0) {
    register u32 zero = 0;
    f32 value;
    register u32 *p = (u32 *)arg0;

    value = lbl_80562650;
    p[0x31C / 4] = zero; p[0x320 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x324) = value;
    p[0x348 / 4] = zero; p[0x34C / 4] = zero; *(f32 *)((u8 *)arg0 + 0x350) = value;
    p[0x374 / 4] = zero; p[0x378 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x37C) = value;
    p[0x3A0 / 4] = zero; p[0x3A4 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x3A8) = value;
    p[0x3CC / 4] = zero; p[0x3D0 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x3D4) = value;
    p[0x3F8 / 4] = zero; p[0x3FC / 4] = zero; *(f32 *)((u8 *)arg0 + 0x400) = value;
    p[0x424 / 4] = zero; p[0x428 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x42C) = value;
    p[0x450 / 4] = zero; p[0x454 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x458) = value;
    p[0x47C / 4] = zero; p[0x480 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x484) = value;
    p[0x4A8 / 4] = zero; p[0x4AC / 4] = zero; *(f32 *)((u8 *)arg0 + 0x4B0) = value;
    p[0x4D4 / 4] = zero; p[0x4D8 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x4DC) = value;
    p[0x500 / 4] = zero; p[0x504 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x508) = value;
    p[0x52C / 4] = zero; p[0x530 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x534) = value;
    p[0x558 / 4] = zero; p[0x55C / 4] = zero; *(f32 *)((u8 *)arg0 + 0x560) = value;
    p[0x584 / 4] = zero; p[0x588 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x58C) = value;
    p[0x5B0 / 4] = zero; p[0x5B4 / 4] = zero; *(f32 *)((u8 *)arg0 + 0x5B8) = value;
}

extern void fn_802E317C(const char *, ...);
extern u8 lbl_80335D80[];
#pragma scheduling invalid_target
s32 fn_801B4428(u32 *arg0, u32 *arg1) {
    if (*arg0 < *arg1) return -1;
    if (*arg0 > *arg1) return 1;
    fn_802E317C((const char *)lbl_80335D80);
    return 0;
}
#pragma dont_inline on
void* fn_801B447C(void* arg0, void* arg1, s32 arg2) {
    s32 half;
    s32 right;
    if (arg2 == 1) return arg1;
    half = (arg2 + ((u32)arg2 >> 31)) >> 1;
    if (half > 0) *(void**)((u8*)arg1 + half * 16 + 8) = fn_801B447C(arg0, arg1, half);
    right = arg2 - half - 1;
    if (right > 0) *(void**)((u8*)arg1 + half * 16 + 12) = fn_801B447C(arg0, (u8*)arg1 + half * 16 + 16, right);
    return (u8*)arg1 + half * 16;
}
void *fn_801B4528(void *arg0, u32 *arg1, u32 arg2) {
    if (arg2 < *arg1) {
        arg1 = (u32 *)arg1[2];
        if (arg1 != NULL) return fn_801B4528(arg0, arg1, arg2);
        return NULL;
    } else if (arg2 > *arg1) {
        arg1 = (u32 *)arg1[3];
        if (arg1 != NULL) return fn_801B4528(arg0, arg1, arg2);
        return NULL;
    }
    return arg1;
}
void* fn_801B4570(void* arg0, u32 arg1) {
    void* found;
    s32* node;
    u32 idx;
    u32 count;
    u32* data;
    found = fn_801B4528(arg0, *(void**)((u8*)arg0 + 0x2F8), arg1);
    if (found == NULL) return NULL;
    node = *(s32**)((u8*)found + 4);
    idx = node[2];
    count = node[1];
    node[2] = (idx + 1) % count;
    data = (u32*)node[0];
    return data + idx * 2;
}

#pragma dont_inline off
