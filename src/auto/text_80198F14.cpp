// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <revolution/MTX/vec.h>
class VTab1A1E7C {
public:
 virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
 virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
 virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void Call();
};
class Fn801A014CDispatch {
public:
    virtual void Dummy0();
    virtual void Call();
};

#pragma opt_tail_call on
__declspec(section ".data") extern f32 lbl_80558DC4;
extern f32 lbl_805622DC;
extern f32 lbl_805622E8;
extern f32 lbl_805622E0;
extern f32 lbl_805622D0;
extern "C" void fn_8019AC44(void*, void*, void*, f32);
inline void fn_8019AC44(f32* a, f32* b, f32 c) {}
extern char lbl_803339B8;
extern void fn_8019F03C();
extern s32 fn_8019DDFC(s32, s32, s32, s32, void*, void*, f32);
extern "C" f64 fn_8002F234(f32);
extern "C" void fn_8019ECC4(void);
extern void* lbl_80333B48;
extern f32 lbl_80562370;

extern "C" void fn_8019CE4C(void*, void*);
extern "C" void fn_8019BD54(void*, void*, s32, s32);
extern "C" void fn_8019B068(void*, void*, s32, s32);
extern "C" void fn_8019CE3C(void*, s32);
extern "C" void fn_802E317C(const char*, ...);
extern "C" const char lbl_803335EC[];
extern void fn_801EA1E0(s32, s32, f32, f32);
extern "C" void fn_8019EBC0(void);
extern "C" void fn_8019F3D0(void);
extern "C" void fn_801A49E8(void*);
extern "C" void fn_801A49FC(s32);
extern "C" void fn_801796EC(s32, s32*, s32);
extern "C" s32 fn_8012C4E4(void*, void*, s32);
extern "C" s32 fn_801CFF18(s32, s32);
extern "C" void fn_801D0650(void);
extern "C" void fn_801CFF14(void);
extern "C" s32 fn_801CF828(s32, s32, s32, s32, s32);
extern s32 lbl_8055E5A0;
extern "C" s32 fn_801CFEAC(void*);
extern s32 lbl_803336EC[];

class VTab19 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void slot0x4C();
};

class VTab12C4 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
};
class VTab1250 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
};

class VTab13 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
    virtual void slot0x34(s32);
};

extern "C" void fn_8017B5D4(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801A4A10(s32, s32, s32);
extern "C" void fn_801A44D4(void*);
extern void* lbl_8055A508;
extern void* lbl_8055A510;

void fn_8019F1A4(void) __attribute__((noreturn));

extern "C" s32 fn_80128668(void);
void fn_801A5C4C(void);
void fn_80199870(void* arg0) {
    u32 value = *(u32*)((u8*)arg0 + 0x10);
    if ((u32)(value - 0x50430000) == 0x4152 ||
        (u32)(value - 0x41430000) == 0x4152) {
        fn_801A5C4C();
    }
}

extern "C" s32 fn_8019A780(void *arg0) {
    return *(s32*)((u8*)arg0 + 8);
}

void fn_8019A788(void* arg0, void* arg1, void* arg3, void* arg4, s32 arg5, f32 farg1, f32 farg2) {
    extern s32 fn_80199894(void*, void*, f32*, s32, void*, f32, f32, f32, f32, f32);
    f32 sp10, spC, sp8;
    f32 scale = lbl_805622DC;
    if (*(s32*)((u8*)arg0 + 4) != 0 || arg4 != 0) {
        fn_80199894(arg0, arg4, (f32*)0, arg5, arg4, farg2, farg1, 0.0f, 0.0f, 0.0f);
        return;
    }
    sp8 = *(f32*)arg3 * scale;
    spC = *((f32*)arg3 + 1) * scale;
    sp10 = *((f32*)arg3 + 2) * scale;
    fn_80199894(arg1, arg0, &sp8, arg5, arg4, farg2, farg1, 0.0f, 0.0f, 0.0f);
}

extern "C" void fn_8019A820(void*, void*, s32, s32, s32, f32);
extern "C" void fn_8019AA18(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_8019A820(arg0, (u8*)arg0 + 0x34, arg1, arg2, arg3, *(f32*)((u8*)arg0 + 0x24));
}

void fn_8019B068(void* arg0, void* arg1, s32 arg2, s32 arg3) {
    extern void fn_8019AA34(void*, void*, void*, s32, s32, void*, f32, f32);
    fn_8019AA34((u8*)arg0 + 0x34, arg1, (u8*)arg1 + 0x34, arg2, arg3, arg1, *(f32*)((u8*)arg0 + 0x24), *(f32*)((u8*)arg1 + 0x24));
}

extern "C" s32 fn_8019B08C(void* arg0, Vec* arg1, void* arg2, f32 farg0) {
    Vec* m = *(Vec**)((u8*)arg2 + 0xC);
    f32 x = arg1->x - *(f32*)((u8*)m + 0x24);
    f32 y = arg1->y - *(f32*)((u8*)m + 0x28);
    f32 z = arg1->z - *(f32*)((u8*)m + 0x2C);
    f32 a = x * *(f32*)((u8*)m + 0x18) + y * *(f32*)((u8*)m + 0x1C) + z * *(f32*)((u8*)m + 0x20);
    f32 b = x * *(f32*)m + y * *(f32*)((u8*)m + 4) + z * *(f32*)((u8*)m + 8);
    f32 c = x * *(f32*)((u8*)m + 0xC) + y * *(f32*)((u8*)m + 0x10) + z * *(f32*)((u8*)m + 0x14);
    if (a >= *(f32*)((u8*)arg2 + 0x28) || a <= -*(f32*)((u8*)arg2 + 0x28)) return 0;
    f32 mag = (f32)fn_8002F234(b*b + c*c);
    if (__fabsf(mag) == lbl_80558DC4) return 0;
    f32 t = farg0 - mag + *(f32*)((u8*)arg2 + 0x24);
    if (t <= lbl_805622D0) return 0;
    f32 dt = (*(f32*)((u8*)arg2 + 0x24) - t) / mag;
    Vec p, normal, out;
    p.x = (b * dt) * *(f32*)m + (c * dt) * *(f32*)((u8*)m + 0xC) + a * *(f32*)((u8*)m + 0x18);
    p.y = (b * dt) * *(f32*)((u8*)m + 4) + (c * dt) * *(f32*)((u8*)m + 0x10) + a * *(f32*)((u8*)m + 0x1C);
    p.z = (b * dt) * *(f32*)((u8*)m + 8) + (c * dt) * *(f32*)((u8*)m + 0x14) + a * *(f32*)((u8*)m + 0x20);
    p.x += *(f32*)((u8*)m + 0x24); p.y += *(f32*)((u8*)m + 0x28); p.z += *(f32*)((u8*)m + 0x2C);
    normal.x=b; normal.y=c; normal.z=lbl_805622D0;
    PSVECNormalize(&normal, &normal);
    out.x=normal.x * *(f32*)m + normal.y * *(f32*)((u8*)m + 0xC) + normal.z * *(f32*)((u8*)m + 0x18);
    out.y=normal.x * *(f32*)((u8*)m + 4) + normal.y * *(f32*)((u8*)m + 0x10) + normal.z * *(f32*)((u8*)m + 0x1C);
    out.z=normal.x * *(f32*)((u8*)m + 8) + normal.y * *(f32*)((u8*)m + 0x14) + normal.z * *(f32*)((u8*)m + 0x20);
    typedef void (*Call)(void*,void*,Vec*,Vec*,s32,s32,f32,f32,f32);
    ((Call)fn_8019A788)(arg0,arg2,&p,&out,0,0,t,lbl_805622D0,lbl_805622D0);
    return 1;
}

extern "C" s32 fn_8019BD4C(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern void fn_8019CCCC(void*, f32, s32);
extern void fn_8019CCCC(void*, void*, s32, f32);
void fn_8019CE3C(void* arg0, s32 arg1) {
    fn_8019CCCC(arg0, (u8*)arg0 + 0x34, arg1, *(f32*)((u8*)arg0 + 0x24));
}

extern "C" f32 PSVECSquareDistance(const Vec*, const Vec*);
extern "C" f32 PSVECDotProduct(const Vec*, const Vec*);
extern f32 lbl_8056232C;
void fn_8019D19C(void* arg0, void* arg1) {
    f32 sp14, sp18, sp1C;
    f32 sp8, spC, sp10;
    f32 scale, dot, value;
    Vec* v0 = (Vec*)((u8*)arg0 + 0x34);
    Vec* v1 = (Vec*)((u8*)arg1 + 0x34);
    sp14 = v1->x - v0->x;
    sp18 = v1->y - v0->y;
    sp1C = v1->z - v0->z;
    if (PSVECSquareDistance(v1, v0) > lbl_8056232C) {
        scale = lbl_805622E0 / (f32)fn_8002F234(PSVECSquareDistance(v1, v0));
        sp14 *= scale; sp18 *= scale; sp1C *= scale;
        dot = PSVECDotProduct((Vec*)&sp14, (Vec*)((u8*)arg0 + 0x18));
        value = *(f32*)((u8*)arg0 + 0x54) + __fabsf(dot) * (*(f32*)((u8*)arg0 + 0x58) - *(f32*)((u8*)arg0 + 0x54));
    } else {
        value = *(f32*)((u8*)arg0 + 0x54);
        if (value <= *(f32*)((u8*)arg0 + 0x58)) value = *(f32*)((u8*)arg0 + 0x58);
    }
    *(f32*)((u8*)arg0 + 0x24) = value;
    sp8 = v0->x - v1->x; spC = v0->y - v1->y; sp10 = v0->z - v1->z;
    if (PSVECSquareDistance(v0, v1) > lbl_8056232C) {
        scale = lbl_805622E0 / (f32)fn_8002F234(PSVECSquareDistance(v0, v1));
        sp8 *= scale; spC *= scale; sp10 *= scale;
        dot = PSVECDotProduct((Vec*)&sp8, (Vec*)((u8*)arg1 + 0x18));
        value = *(f32*)((u8*)arg1 + 0x54) + __fabsf(dot) * (*(f32*)((u8*)arg1 + 0x58) - *(f32*)((u8*)arg1 + 0x54));
    } else {
        value = *(f32*)((u8*)arg1 + 0x54);
        if (value <= *(f32*)((u8*)arg1 + 0x58)) value = *(f32*)((u8*)arg1 + 0x58);
    }
    *(f32*)((u8*)arg1 + 0x24) = value;
    fn_8019B068(arg0, arg1, 0, 0);
}

s32 fn_8019D618(void* arg0, void* arg1, s32 clamp, void* arg3) {
    Vec* a = *(Vec**)((u8*)arg0 + 0xC); Vec* b = *(Vec**)((u8*)arg1 + 0xC);
    Vec cross, mid, da, db, p, q, delta, normal, center;
    f32 h0=*(f32*)((u8*)arg0+0x28), h1=*(f32*)((u8*)arg1+0x28);
    PSVECCrossProduct((Vec*)((u8*)a+0x18),(Vec*)((u8*)b+0x18),&cross);
    f32 den=PSVECDotProduct(&cross,&cross), t0,t1;
    if(den<lbl_8056232C) {
        mid.x=(a->x+b->x)*lbl_805622E8; mid.y=(a->y+b->y)*lbl_805622E8; mid.z=(a->z+b->z)*lbl_805622E8;
        da.x=mid.x-a->x; da.y=mid.y-a->y; da.z=mid.z-a->z;
        t0=PSVECDotProduct((Vec*)((u8*)a+0x18),&da);
        db.x=mid.x-b->x; db.y=mid.y-b->y; db.z=mid.z-b->z;
        t1=PSVECDotProduct((Vec*)((u8*)b+0x18),&db);
    } else { t0=0.0f; t1=0.0f; }
    if(!clamp) { if(t0 < -h0 || t0>h0 || t1 < -h1 || t1>h1) return 0; }
    else { if(t0 < -h0)t0=-h0; if(t0>h0)t0=h0; if(t1 < -h1)t1=-h1; if(t1>h1)t1=h1; }
    p.x=a->x+((Vec*)((u8*)a+0x18))->x*t0; p.y=a->y+((Vec*)((u8*)a+0x18))->y*t0; p.z=a->z+((Vec*)((u8*)a+0x18))->z*t0;
    q.x=b->x+((Vec*)((u8*)b+0x18))->x*t1; q.y=b->y+((Vec*)((u8*)b+0x18))->y*t1; q.z=b->z+((Vec*)((u8*)b+0x18))->z*t1;
    delta.x=q.x-p.x; delta.y=q.y-p.y; delta.z=q.z-p.z;
    f32 dist=PSVECMag(&delta); if(__fabsf(dist)==lbl_80558DC4)return 0;
    f32 depth=*(f32*)((u8*)arg0+0x24)+*(f32*)((u8*)arg1+0x24)-dist; if(depth<lbl_805622D0)return 0;
    f32 scale=lbl_805622DC/dist; normal.x=delta.x*scale; normal.y=delta.y*scale; normal.z=delta.z*scale;
    center.x=(p.x+q.x)*lbl_805622E8; center.y=(p.y+q.y)*lbl_805622E8; center.z=(p.z+q.z)*lbl_805622E8;
    typedef void (*Call)(void*,void*,f32,f32,Vec*,Vec*,s32,s32);
    ((Call)fn_8019A788)(arg3?arg3:arg0,arg1,depth,lbl_805622D0,&center,&normal,0,0);
    return 1;
}

extern "C" f32 fn_8019DDEC(void *arg0) {
    return *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)arg0 + 0x28);
}

extern f32 lbl_805622E8;
extern f32 lbl_8056234C;
extern f32 lbl_80562350;
extern f32 lbl_80562354;
extern f32 lbl_80562358;
extern "C" s32 fn_8019DDFC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void* arg4, void* arg5, f32 farg0) {
    f32 sp8, spC, sp10;
    f32 dot1;
    f32 dot2;
    f32 val;
    f32 t;
    f32 mag;
    f32 scale;

    sp8 = *(f32*)arg4 - *(f32*)arg5;
    spC = ((f32*)arg4)[1] - ((f32*)arg5)[1];
    sp10 = ((f32*)arg4)[2] - ((f32*)arg5)[2];
    dot1 = PSVECDotProduct((const Vec*)&sp8, (const Vec*)&sp8);
    dot2 = PSVECDotProduct((const Vec*)&sp8, (const Vec*)&farg0);
    val = lbl_8056234C * dot1;
    t = val * val - lbl_80562350 * (dot2 - farg0 * farg0);
    if (t <= lbl_80562354)
        return 0;
    mag = (f32)fn_8002F234(t);
    scale = lbl_805622E8 * (-val - mag);
    if (scale != lbl_805622D0 || scale >= *(f32*)arg5)
        return 0;
    *(f32*)arg5 = scale;
    ((f32*)arg4)[0] = sp8 + ((f32*)arg5)[0] * scale;
    ((f32*)arg4)[1] = spC + ((f32*)arg5)[1] * scale;
    ((f32*)arg4)[2] = sp10 + ((f32*)arg5)[2] * scale;
    mag = PSVECMag((const Vec*)arg4);
    if (lbl_80562358 > mag)
        mag = lbl_80562358;
    scale = lbl_805622E0 / mag;
    ((f32*)arg4)[0] *= scale;
    ((f32*)arg4)[1] *= scale;
    ((f32*)arg4)[2] *= scale;
    return 1;
}

extern "C" s32 fn_8019E1F4(f32* arg0, f32* arg1, f32 f0, f32 f1, f32 f2) {
    if (__fabsf(f1) == lbl_80558DC4) {
        if (!(f0 < -f2) && !(f0 > f2)) return 1;
        return 0;
    }
    f32 lo, hi;
    if ((-f2 - f0) / f1 < (f2 - f0) / f1) {
        lo = (-f2 - f0) / f1;
        hi = (f2 - f0) / f1;
    } else {
        lo = (f2 - f0) / f1;
        hi = (-f2 - f0) / f1;
    }
    if (*arg0 > lo) *arg0 = lo;
    if (*arg1 < hi) *arg1 = hi;
    if (*arg0 > *arg1) return 0;
    return *arg1 < lbl_805622D0;
}

extern "C" s32 fn_8019E834(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_8019E874(void*, void**, void*, f32, f32, f32, f32);
extern void fn_8019AA34(void*, void*, void*, s32, s32, void*, f32, f32);
extern void fn_8019A820(void*, s32, s32, s32, f32);
s32 fn_8019EA7C(void* arg0, void** arg1) {
    void* temp_r3;
    void* temp_r5;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 sp20;
    f32 sp1C;
    f32 spC;

    temp_r3 = ((void* (*)(void*))(*(u32*)(*(u32*)arg1 + 0x50)))(arg1);
    temp_r5 = *(void**)((u8*)arg0 + 0xC);
    temp_f3 = *(f32*)((u8*)temp_r5 + 0x28);
    temp_f4 = *(f32*)((u8*)temp_r5 + 0x24) - *(f32*)((u8*)temp_r3 + 0x24);
    temp_f1 = *(f32*)((u8*)temp_r5 + 0x2C);
    temp_f2 = temp_f3 - *(f32*)((u8*)temp_r3 + 0x28);
    sp20 = temp_f4; spC = temp_f2;
    sp1C = temp_f1 - *(f32*)((u8*)temp_r3 + 0x2C);
    return fn_8019E874(arg0, arg1, temp_r5, temp_f1, temp_f2, temp_f3, temp_f4) != 0;
}

void fn_8019EB14(u8 *arg0, s32 arg1) {
    u32 offset = arg1 * 8;
    u8 *p = arg0 + offset;
    u8 t;
    t = p[0]; p[0] = p[1]; p[1] = t;
    t = p[2]; p[2] = p[3]; p[3] = t;
    t = p[4]; p[4] = p[5]; p[5] = t;
    t = p[6]; p[6] = p[7]; p[7] = t;
    if (*(u16 *)(p + 4) != 0) {
        s32 i;
        for (i = 0; i < 4; i++) {
            fn_8019EB14(arg0, *(u16 *)(p + 4) + i);
        }
    }
}

void fn_8019EBC0(void* arg0) {
    void* obj = *(void**)((u8*)arg0 + 4);
    if (obj != 0) {
        void** vtable = *(void***)obj;
        ((void (*)(void*))(*(u32*)((u8*)vtable + 0x48)))(obj);
    }
}

extern "C" void fn_8019EBE0(void* self, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 v1 = (s32)self;
    s32 v2 = a;
    s32 v3 = b;
    s32 v4 = c;
    s32 v5 = d;
    s32 v6 = e;
    s32 v7 = f;
    s32 obj = *(s32*)((u8*)self + 4);

    if (obj != 0) {
        fn_8017B5D4(obj, v1, v2, v3, v4, v5, v6);
        return;
    }

    obj = *(s32*)((u8*)self + 8);
    if (obj != 0) {
        fn_801A4A10(obj, v4, v7);
    }

    return (void)v1, (void)v2, (void)v3, (void)v5, (void)v6;
}

extern "C" void fn_8019EC84(void* this_) {
    VTab19* p = *(VTab19**)((u8*)this_ + 4);
    if (p == NULL) {
        return;
    }
    p->slot0x4C();
}

extern "C" void fn_8019ECA4(VTab13* this_, s32 arg1) {
    *(s32*)((u8*)this_ + 8) = arg1;
    this_->slot0x34(arg1 + 4);
}

extern "C" void fn_8017B5D4(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801A4A10(s32, s32, s32);
extern "C" void fn_8019ECBC(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0xC) = arg1;
}

void* fn_8019EDB8(void* arg0, void* arg1, s32 arg2) {
    fn_8019ECC4();
    *(void**)arg0 = &lbl_80333B48;
    if (arg2 != 0) {
        u8 a = *((u8*)arg0 + 0x24);
        u8 b = *((u8*)arg0 + 0x25);
        u8 c = *((u8*)arg0 + 0x26);
        u8 d = *((u8*)arg0 + 0x27);
        u8 e = *((u8*)arg0 + 0x28);
        u8 f = *((u8*)arg0 + 0x29);
        u8 g = *((u8*)arg0 + 0x2A);
        u8 h = *((u8*)arg0 + 0x2B);
        u8 i = *((u8*)arg0 + 0x2C);
        u8 j = *((u8*)arg0 + 0x2D);
        u8 k = *((u8*)arg0 + 0x2E);
        u8 l = *((u8*)arg0 + 0x2F);
        u8 m = *((u8*)arg0 + 0x30);
        u8 n = *((u8*)arg0 + 0x31);
        u8 o = *((u8*)arg0 + 0x32);
        u8 p = *((u8*)arg0 + 0x33);
        *((u8*)arg0 + 0x24) = d;
        *((u8*)arg0 + 0x27) = a;
        *((u8*)arg0 + 0x25) = c;
        *((u8*)arg0 + 0x26) = b;
        *((u8*)arg0 + 0x28) = h;
        *((u8*)arg0 + 0x2B) = e;
        *((u8*)arg0 + 0x29) = g;
        *((u8*)arg0 + 0x2A) = f;
        *((u8*)arg0 + 0x2C) = l;
        *((u8*)arg0 + 0x2F) = i;
        *((u8*)arg0 + 0x2D) = k;
        *((u8*)arg0 + 0x2E) = j;
        *((u8*)arg0 + 0x30) = p;
        *((u8*)arg0 + 0x33) = m;
        *((u8*)arg0 + 0x31) = o;
        *((u8*)arg0 + 0x32) = n;
        if (*(s32*)((u8*)arg0 + 0x20) == 0x3eb)
            *(f32*)((u8*)arg0 + 0x24) += lbl_80562370;
    }
    *(s8*)((u8*)arg0 + 0x4C) = 0;
    *(f32*)((u8*)arg0 + 0x34) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x38) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x3C) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x40) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x44) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x48) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x50) = lbl_805622D0;
    return arg0;
}

void fn_8019EECC(void* arg0, Vec* arg1) {
    arg1->x += *(f32*)((u8*)arg0 + 0x30);
    arg1->y += *(f32*)((u8*)arg0 + 0x34);
    arg1->z += *(f32*)((u8*)arg0 + 0x38);
}

void fn_8019F03C(void* arg0) {
    f32 value = lbl_805622D0;
    *(u8*)((u8*)arg0 + 0x4C) = 0;
    *(f32*)((u8*)arg0 + 0x40) = value;
    *(f32*)((u8*)arg0 + 0x44) = value;
    *(f32*)((u8*)arg0 + 0x48) = value;
    *(f32*)((u8*)arg0 + 0x34) = value;
    *(f32*)((u8*)arg0 + 0x38) = value;
    *(f32*)((u8*)arg0 + 0x3C) = value;
}

extern "C" void fn_8019F064(void* arg0, void* arg1) {
    u32 value = *(u32*)((u8*)arg1 + 0x18);
    if (value == 0x52414744) {
        return;
    } else if (value < 0x52414744) {
        if (value == 0x504F4C59) {
            ((void (*)(void*, void*))(*(u32*)*(u32*)arg1 + 0x10))(arg1, arg0);
            return;
        } else if (value < 0x47525550) {
            if (value == 0x424F5820) {
                fn_8019BD54(arg1, arg0, 0, 0);
                return;
            }
        } else if (value == 0x47525550) {
            ((void (*)(void*, void*))(*(u32*)*(u32*)arg1 + 0x10))(arg1, arg0);
            return;
        } else if (value < 0x464C5352) {
        } else if (value == 0x464C5352) {
            fn_8019CE4C(arg1, arg0);
            return;
        }
    } else {
        if (value == 0x53504852) {
            fn_8019B068(arg1, arg0, 0, 0);
            return;
        } else if (value < 0x53504852) {
            if (value == 0x52494E47) {
                ((void (*)(void*, void*))(*(u32*)*(u32*)arg1 + 0x10))(arg1, arg0);
                return;
            }
        } else if (value == 0x54554245) {
            fn_8019CE3C(arg1, (s32)arg0);
            return;
        }
    }
    fn_802E317C(lbl_803335EC, value);
}

extern "C" void fn_8019F1A4(void* arg0) {
    fn_8019AC44(arg0, (u8*)arg0 + 0x34, (u8*)arg0 + 0x40, *(f32*)((u8*)arg0 + 0x24));
}

void fn_8019F1B4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) { fn_8019DDFC(arg1,arg2,arg3,arg4,(u8*)arg0+0x34,arg0,*(f32*)((u8*)arg0+0x24)); }

void fn_8019F1D4(void *arg0, f32 *arg1, f32 *arg2) {
    f32 width = *(f32 *)((u8 *)arg0 + 0x24);
    f32 left = *(f32 *)((u8 *)arg0 + 0x34);
    f32 mid = *(f32 *)((u8 *)arg0 + 0x38);
    f32 right = *(f32 *)((u8 *)arg0 + 0x3C);
    f32 a = width * lbl_805622DC;
    f32 b = width * lbl_805622E0;
    f32 v0[2] = {width, width};
    f32 v1[4] = {width, left, mid, right};
    arg1[0] = left + a;
    arg1[1] = mid + a;
    arg1[2] = right + a;
    arg2[0] = left + b;
    arg2[1] = mid + b;
    arg2[2] = right + b;
}

void fn_8019F248(void *arg0) {
    extern f32 lbl_80562300;
    extern s32 lbl_8055E598;
    extern void fn_801E3FC8(void*, s32, f32);
    f32 var_f1 = *(f32*)((u8*)arg0 + 0x24);
    if (var_f1 <= lbl_80562300) {
        var_f1 = lbl_80562300;
    }
    fn_801E3FC8((u8*)arg0 + 0x34, lbl_8055E598, var_f1);
}

extern "C" void fn_8019F3D0(void) {

}

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_8019F3D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8019F414(void *arg0) {
    extern f32 lbl_8056237C;
    extern void fn_8019EECC(void*, void*);
    extern void fn_8019EF00(void*);
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r4;
    void *temp_r6;
    temp_r6 = *(void **)((u8*)arg0 + 0x54);
    temp_r4 = *(void **)arg0;
    sp8 = *(f32*)((u8*)temp_r6 + 0x30);
    spC = *(f32*)((u8*)temp_r6 + 0x34);
    sp10 = *(f32*)((u8*)temp_r6 + 0x38);
    sp8 = (sp8 - *(f32*)((u8*)temp_r4 + 0x30)) + *(f32*)((u8*)arg0 + 0x58);
    spC = (spC - *(f32*)((u8*)temp_r4 + 0x34)) + (lbl_8056237C + *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)temp_r6 + 0xC));
    sp10 = sp10 - *(f32*)((u8*)temp_r4 + 0x38);
    *(f32*)((u8*)arg0 + 0x28) = sp8;
    *(f32*)((u8*)arg0 + 0x2C) = spC;
    *(f32*)((u8*)arg0 + 0x30) = sp10;
    if (temp_r4 != 0) fn_8019EECC(temp_r4, (u8*)arg0 + 0x28);
    fn_8019EF00(arg0);
}

extern "C" void fn_8019F560(void) {
    fn_8019F1A4();
}

void fn_8019F6F0(void *arg0) { fn_8019F03C(arg0); *(f32*)((u8*)arg0+0x64)=lbl_805622D0; *(f32*)((u8*)arg0+0x68)=lbl_805622D0; *(f32*)((u8*)arg0+0x6C)=lbl_805622D0; *(f32*)((u8*)arg0+0x70)=lbl_805622D0; *(f32*)((u8*)arg0+0x74)=lbl_805622D0; *(f32*)((u8*)arg0+0x78)=lbl_805622D0; *(f32*)((u8*)arg0+0x7C)=lbl_805622D0; *(f32*)((u8*)arg0+0x80)=lbl_805622D0; *(f32*)((u8*)arg0+0x84)=lbl_805622D0; *(f32*)((u8*)arg0+0x88)=lbl_805622D0; *(f32*)((u8*)arg0+0x8C)=lbl_805622D0; *(f32*)((u8*)arg0+0x90)=lbl_805622D0; *(f32*)((u8*)arg0+0x94)=lbl_805622D0; *(f32*)((u8*)arg0+0x98)=lbl_805622D0; *(f32*)((u8*)arg0+0x9C)=lbl_805622D0; *(f32*)((u8*)arg0+0xA0)=lbl_805622D0; *(f32*)((u8*)arg0+0xA4)=lbl_805622D0; *(f32*)((u8*)arg0+0xA8)=lbl_805622D0; *(f32*)((u8*)arg0+0xAC)=lbl_805622D0; *(f32*)((u8*)arg0+0xB0)=lbl_805622D0; *(f32*)((u8*)arg0+0xB4)=lbl_805622D0; *(f32*)((u8*)arg0+0xB8)=lbl_805622D0; *(f32*)((u8*)arg0+0xBC)=lbl_805622D0; *(f32*)((u8*)arg0+0xC0)=lbl_805622D0; }

extern "C" void fn_8019FF88(void) {
    fn_8019EBC0();
}

extern "C" void fn_8019FF8C(void* arg0) {
    fn_8019F03C();
    *(f32*)((u8*)arg0 + 0x28) = *(f32*)((u8*)arg0 + 0x54);
    *(f32*)((u8*)arg0 + 0x2C) = *(f32*)((u8*)arg0 + 0x58);
    *(f32*)((u8*)arg0 + 0x30) = *(f32*)((u8*)arg0 + 0x5C);
    *(u8*)((u8*)arg0 + 0x78) = 0;
}

extern "C" void fn_8019FFD8(void* arg0, s32 arg1, s32 arg2) {
    *(s32*)((u8*)arg0 + 0xC) = arg1;
    *(s32*)((u8*)arg0 + 4) = arg2;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0x18) = 0x47525550;
    *(f32*)((u8*)arg0 + 0x10) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x14) = lbl_805622D0;
    *(s32*)((u8*)arg0 + 0x20) = 0x64;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(void**)((u8*)arg0) = &lbl_803339B8;
    *(f32*)((u8*)arg0 + 0x170) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x178) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x16C) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x168) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x164) = lbl_805622D0;
    *(s32*)((u8*)arg0 + 0x174) = 0;
    *(s32*)((u8*)arg0 + 0x17C) = 0;
    *(s32*)((u8*)arg0 + 0x180) = -1;
}

extern "C" void* fn_801A0040(void* arg0, s32 arg1) {
      if (arg0 != 0) {
          *(void**)arg0 = &lbl_803339B8;
          void* entries = arg0;
          s32 i = 0;
          while (i < *(s32*)((u8*)arg0 + 0x174)) {
              void* item = *(void**)((u8*)entries + 0x24);
              if (item != 0) {
                  void** vt = *(void***)item;
                  ((void (*)(void*, s32))vt[2])(item, 1);
              }
              entries = (u8*)entries + 4;
              i++;
          }
          void* p = *(void**)((u8*)arg0 + 0x17C);
          if (p != 0) {
              void** vt = *(void***)p;
              ((void (*)(void*, s32))vt[2])(p, 1);
          }
          if (arg1 > 0) ((void (*)(void*))fn_80128668)(arg0);
      }
      return arg0;
  }

extern "C" s32 fn_801A010C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801A014C(void* arg0) {
    Fn801A014CDispatch* item = (Fn801A014CDispatch*)*(void**)((u8*)arg0 + 0x17C);
    item->Call();
}

extern s32 lbl_8055E3C4;
extern "C" void fn_801A0160(void* arg0) {
    s32 value = lbl_8055E3C4;
    if (value != *(s32*)((u8*)arg0 + 0x180)) {
        *(s32*)((u8*)arg0 + 0x180) = value;
        void** entries = (void**)arg0;
        s32 i = 0;
    loop:
        void* item = *(void**)((u8*)entries + 0x24);
        ((void (*)(void*))((void**) *(void**)item)[3])(item);
        entries++;
        i++;
        if (i < *(s32*)((u8*)arg0 + 0x174))
            goto loop;
    }
}

extern "C" void fn_801A01E0(void* arg0, void* arg1, void* arg2) {
    f32 temp_f8 = *(f32*)((u8*)arg0 + 0x178);
    void* temp_r3 = *(void**)((u8*)arg0 + 0xC);
    f32 temp_f7 = *(f32*)((u8*)temp_r3 + 0x24);
    f32 temp_f2 = temp_f8 * lbl_805622DC;
    f32 temp_f6 = *(f32*)((u8*)temp_r3 + 0x28);
    f32 temp_f0 = temp_f8 * lbl_805622E0;
    f32 temp_f5 = *(f32*)((u8*)temp_r3 + 0x2C);
    f32 sp8 = temp_f8;
    *(f32*)arg1 = temp_f7 + temp_f2;
    *(f32*)((u8*)arg1 + 4) = temp_f6 + temp_f2;
    *(f32*)((u8*)arg1 + 8) = temp_f5 + temp_f2;
    f32 spC = temp_f8;
    f32 sp10 = temp_f8;
    f32 sp14 = temp_f7;
    f32 sp18 = temp_f6;
    f32 sp1C = temp_f5;
    *(f32*)arg2 = temp_f7 + temp_f0;
    *(f32*)((u8*)arg2 + 4) = temp_f6 + temp_f0;
    *(f32*)((u8*)arg2 + 8) = temp_f5 + temp_f0;
}

extern "C" void fn_801A0444(void* arg0, void* arg1) {
    *(void**)((u8*)arg0 + 0x17C) = arg1;
    *(f32*)((u8*)arg0 + 0x164) = *(f32*)((u8*)arg1 + 0x24);
    *(f32*)((u8*)arg0 + 0x168) = *(f32*)((u8*)arg1 + 0x28);
    *(f32*)((u8*)arg0 + 0x16C) = *(f32*)((u8*)arg1 + 0x2C);
}

extern "C" void fn_801A0160(void*);
extern "C" s32 fn_801A1148(void* arg0, const f32* vec, s32 arg2, f32* arg3, s32 arg4, s32 arg5) {
    f32 sp[3];
    sp[0] = *(f32*)((u8*)arg0 + 0x24) - vec[0];
    sp[1] = *(f32*)((u8*)arg0 + 0x28) - vec[1];
    sp[2] = *(f32*)((u8*)arg0 + 0x2C) - vec[2];
    f32 dot = PSVECDotProduct((const Vec*)sp, (const Vec*)vec);
    f32 f178 = *(f32*)((u8*)arg0 + 0x178);
    if (dot > -f178 && dot < *arg3 + f178) {
        fn_801A0160(arg0);
        void* entries = arg0;
        s32 found = 0;
        s32 i = 0;
        while (i < *(s32*)((u8*)arg0 + 0x174)) {
            if (fn_8019DDFC(arg2, arg4, arg5, 0, (u8*)entries + 0x34, entries, *(f32*)((u8*)entries + 0x24)) != 0)
                found = 1;
            entries = (u8*)entries + 4;
            i++;
        }
        return found;
    }
    return 0;
}

extern "C" void fn_801A1250(void* arg0) {
    VTab1250** entries = (VTab1250**)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x174)) {
        entries[9]->v08();
        entries++;
        i++;
    }
    *(s32*)((u8*)arg0 + 0x180) = -1;
}

void fn_801A12C4(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0x1C) = arg1;
    VTab12C4* first = *(VTab12C4**)((u8*)arg0 + 0x17C);
    first->v17();
    VTab12C4** entries = (VTab12C4**)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x174)) {
        ((void (*)(VTab12C4*, s32))(*(void***)entries[9])[17])(entries[9], arg1);
        entries++; i++;
    }
}

extern "C" void fn_801A1358(void *arg0, s32 arg1) { *(s32 *)((u8 *)arg0 + 0x1C) = arg1; }

extern "C" void fn_801A1360(void* arg0, s32 arg1) {
    class Dispatch {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void set(s32);
    };
    *(s32*)((u8*)arg0 + 0x20) = arg1;
    void* p = *(void**)((u8*)arg0 + 0x17C);
    ((Dispatch*)p)->set(arg1);
    u8* entries = (u8*)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x174)) {
        void* item = *(void**)(entries + 0x24);
        ((Dispatch*)item)->set(arg1);
        entries += 4;
        i++;
    }
}

extern "C" void fn_801A13F4(void* arg0) {
    void* p = *(void**)((u8*)arg0 + 0x17C);
    void** vt = *(void***)p;
    ((void (*)(void*))vt[19])(p);
    void** entries = (void**)arg0;
    s32 i = 0;
    do {
        void* item = *(void**)((u8*)entries + 0x24);
        void** ivt = *(void***)item;
        ((void (*)(void*))ivt[19])(item);
        entries++;
        i++;
    } while (i < *(s32*)((u8*)arg0 + 0x174));
}

extern "C" void fn_801A1474(void* arg0, f32 scale) {
    u8* p = (u8*)arg0;
    f32* src = (f32*)(p + 0x64);
    void* obj = *(void**)(p + 0x24);
    s32 i = 0;
    *(f32*)(p + 0x178) = *(f32*)(p + 0x170) * scale;
    do {
        f32 x = src[0] * scale;
        f32 y = src[1] * scale;
        f32 z = src[2] * scale;
        *(f32*)((u8*)obj + 0x28) = x;
        *(f32*)((u8*)obj + 0x2c) = y;
        *(f32*)((u8*)obj + 0x30) = z;
        *(f32*)((u8*)obj + 0x24) = src[3] * scale;
        src += 4;
        obj = *(void**)(p + 0x28 + i * 4);
        i++;
    } while (i < *(s32*)(p + 0x174));
    obj = *(void**)(p + 0x17c);
    *(f32*)((u8*)obj + 0x24) = *(f32*)(p + 0x164) * scale;
    *(f32*)((u8*)obj + 0x28) = *(f32*)(p + 0x168) * scale;
    *(f32*)((u8*)obj + 0x2c) = *(f32*)(p + 0x16c) * scale;
}

extern void fn_8019ECC4(void);
extern void* lbl_80333968;
extern f32 lbl_80562370;
extern "C" void* fn_801A1520(void* arg0, void* arg1, s32 arg2) {
    fn_8019ECC4();
    *(void**)arg0 = &lbl_80333968;
    if (arg2 != 0) {
        u8 a = *((u8*)arg0 + 0x24);
        u8 b = *((u8*)arg0 + 0x25);
        u8 c = *((u8*)arg0 + 0x28);
        u8 d = *((u8*)arg0 + 0x29);
        *((u8*)arg0 + 0x24) = *((u8*)arg0 + 0x27);
        *((u8*)arg0 + 0x27) = a;
        *((u8*)arg0 + 0x25) = *((u8*)arg0 + 0x26);
        *((u8*)arg0 + 0x26) = b;
        *((u8*)arg0 + 0x28) = *((u8*)arg0 + 0x2b);
        *((u8*)arg0 + 0x2b) = c;
        *((u8*)arg0 + 0x29) = *((u8*)arg0 + 0x2a);
        *((u8*)arg0 + 0x2a) = d;
        if (*(s32*)((u8*)arg0 + 0x20) == 0x3eb)
            *(f32*)((u8*)arg0 + 0x24) += lbl_80562370;
    }
    return arg0;
}

extern int lbl_80333918[64];
extern "C" void* fn_801A1520(void*, void*, s32);
#pragma scheduling off
extern "C" void** fn_801A1898(void** arg0) {
    ((void* (*)(void*))fn_801A1520)(arg0);
    *arg0 = &lbl_80333918;
    return arg0;
}

extern "C" void fn_8019CF60(void*);
extern "C" void fn_8019DC04(void*);
extern "C" void fn_8019CE3C(void*, s32);
extern "C" void fn_802E30C8(const char*, ...);
extern "C" const char lbl_80333650[];
extern "C" void fn_801A1ABC(void* arg0, void* arg1) {
    u32 value = *(u32*)((u8*)arg1 + 0x18);
    if (value == 0x52414744) {
        return;
    } else if (value < 0x52414744) {
        if (value == 0x504F4C59) {
            return;
        } else if (value < 0x47525550) {
            if (value == 0x424F5820) {
                fn_8019EA7C(arg1, (void**)arg0);
                return;
            }
        } else if (value == 0x47525550) {
            fn_8019EA7C(arg1, (void**)arg0);
            return;
        } else if (value < 0x464C5352) {
        } else if (value == 0x464C5352) {
            fn_8019CF60(arg1);
            return;
        }
    } else {
        if (value == 0x53504852) {
            fn_8019CE3C(arg1, (s32)arg0);
            return;
        } else if (value < 0x53504852) {
            if (value == 0x52494E47) {
                return;
            }
        } else if (value == 0x54554245) {
            fn_8019DC04(arg1);
            return;
        }
    }
    fn_802E30C8(lbl_80333650, value);
}

void fn_801A1B9C(void* arg0) {
    void* mat = *(void**)((u8*)arg0 + 0xC);
    f32 w = *(f32*)((u8*)arg0 + 0x28);
    f32 neg_w = -w;
    f32 sp8 = *(f32*)((u8*)mat + 0x24);
    f32 spC = *(f32*)((u8*)mat + 0x28);
    f32 sp10 = *(f32*)((u8*)mat + 0x2C);
    f32 sp14 = *(f32*)((u8*)mat + 0x18);
    f32 sp18 = *(f32*)((u8*)mat + 0x1C);
    f32 sp1C = *(f32*)((u8*)mat + 0x20);
    f32 sp20 = lbl_805622D0;
    f32 sp24 = lbl_805622D0;
    f32 sp28 = lbl_805622D0;
    f32 sp2C = sp8 + sp14 * neg_w;
    f32 sp30 = spC + sp18 * neg_w;
    f32 sp34 = sp10 + sp1C * neg_w;
    f32 sp38 = sp8 + sp14 * w;
    f32 sp3C = spC + sp18 * w;
    f32 sp40 = sp10 + sp1C * w;
    f32 f = *(f32*)((u8*)arg0 + 0x24);
    fn_8019AC44(&sp38, &sp20, f);
    fn_8019AC44(&sp2C, &sp20, f);
}

extern void* lbl_803338C0;
extern "C" void* fn_801A1CE4(void *arg0, s32 arg1, s32 arg2) {
    u8 temp_r12, temp_r22, temp_r23, temp_r24, temp_r25;
    u8 temp_r26, temp_r27, temp_r28, temp_r29, temp_r30;
    fn_8019ECC4();
    *(void**)arg0 = &lbl_803338C0;
    if (arg2 != 0) {
        temp_r12 = *(u8*)((u8*)arg0 + 0x24);
        temp_r26 = *(u8*)((u8*)arg0 + 0x25);
        temp_r30 = *(u8*)((u8*)arg0 + 0x28);
        temp_r25 = *(u8*)((u8*)arg0 + 0x29);
        temp_r29 = *(u8*)((u8*)arg0 + 0x2C);
        temp_r24 = *(u8*)((u8*)arg0 + 0x2D);
        temp_r28 = *(u8*)((u8*)arg0 + 0x30);
        temp_r23 = *(u8*)((u8*)arg0 + 0x31);
        temp_r27 = *(u8*)((u8*)arg0 + 0x34);
        temp_r22 = *(u8*)((u8*)arg0 + 0x35);
        *(u8*)((u8*)arg0 + 0x24) = *(u8*)((u8*)arg0 + 0x27);
        *(u8*)((u8*)arg0 + 0x27) = temp_r12;
        *(u8*)((u8*)arg0 + 0x25) = *(u8*)((u8*)arg0 + 0x26);
        *(u8*)((u8*)arg0 + 0x26) = temp_r26;
        *(u8*)((u8*)arg0 + 0x28) = *(u8*)((u8*)arg0 + 0x2B);
        *(u8*)((u8*)arg0 + 0x2B) = temp_r30;
        *(u8*)((u8*)arg0 + 0x29) = *(u8*)((u8*)arg0 + 0x2A);
        *(u8*)((u8*)arg0 + 0x2A) = temp_r25;
        *(u8*)((u8*)arg0 + 0x2C) = *(u8*)((u8*)arg0 + 0x2F);
        *(u8*)((u8*)arg0 + 0x2F) = temp_r29;
        *(u8*)((u8*)arg0 + 0x2D) = *(u8*)((u8*)arg0 + 0x2E);
        *(u8*)((u8*)arg0 + 0x2E) = temp_r24;
        *(u8*)((u8*)arg0 + 0x30) = *(u8*)((u8*)arg0 + 0x33);
        *(u8*)((u8*)arg0 + 0x33) = temp_r28;
        *(u8*)((u8*)arg0 + 0x31) = *(u8*)((u8*)arg0 + 0x32);
        *(u8*)((u8*)arg0 + 0x32) = temp_r23;
        *(u8*)((u8*)arg0 + 0x34) = *(u8*)((u8*)arg0 + 0x37);
        *(u8*)((u8*)arg0 + 0x37) = temp_r27;
        *(u8*)((u8*)arg0 + 0x35) = *(u8*)((u8*)arg0 + 0x36);
        *(u8*)((u8*)arg0 + 0x36) = temp_r22;
    }
    return arg0;
}

extern s32 fn_8019E2D0(s32, s32, s32, void*, f32, f32, f32);
extern "C" s32 fn_8019E2D0(s32, s32, s32, void*, f32, f32, f32);
extern "C" s32 fn_801A1E7C(void* arg0, s32 arg1, s32 arg2, s32 arg3, void* arg4) {
    f32 a = *(f32*)((u8*)arg0 + 0x24);
    f32 b = *(f32*)((u8*)arg0 + 0x28);
    f32 c = *(f32*)((u8*)arg0 + 0x2C);
    void* result = ((void* (*)(void*))(*(u32**)arg0)[0x50 / 4])(arg0);
    if (fn_8019E2D0(arg1, arg2, arg3, result, a, b, c)) {
        *(f32*)arg4 = lbl_805622D0;
        *((f32*)arg4 + 1) = lbl_805622E0;
        *((f32*)arg4 + 2) = lbl_805622D0;
        return 1;
    }
    return 0;
}

#pragma scheduling on
extern "C" void fn_801A1F44(void* arg0, void* arg1) {
    struct V {
        virtual void* a0() = 0; virtual void* a1() = 0; virtual void* a2() = 0; virtual void* a3() = 0;
        virtual void* a4() = 0; virtual void* a5() = 0; virtual void* a6() = 0; virtual void* a7() = 0;
        virtual void* a8() = 0; virtual void* a9() = 0; virtual void* a10() = 0; virtual void* a11() = 0;
        virtual void* a12() = 0; virtual void* a13() = 0; virtual void* a14() = 0; virtual void* a15() = 0;
        virtual void* a16() = 0; virtual void* a17() = 0; virtual void* f() = 0;
    };
    void* result = ((V*)arg1)->f();
    volatile s32* src = (volatile s32*)result;
    s32 a = src[9];
    s32 b = src[10];
    *(s32*)arg0 = a;
    *((s32*)arg0 + 1) = b;
    *((s32*)arg0 + 2) = src[11];
}

extern "C" s32 fn_801A2434(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801A2674(void* arg0, s32 arg1, s32 arg2, f32 arg3) {
    *(f32*)((u8*)arg0 + 0x24) = arg3;
    *(s32*)((u8*)arg0 + 0x28) = arg1;
    *(s32*)((u8*)arg0 + 0x2C) = arg2;
}

extern f32 lbl_805622E0;
void fn_801A2684(void* arg0, f32* arg1, f32* arg2) {
    f32 sp10, spC, sp8;
    f32 temp_f0 = *(f32*)((u8*)arg0 + 0x24);
    void* temp_r3 = *(void**)((u8*)arg0 + 0xC);
    f32 temp_f1 = lbl_805622E0 * temp_f0;
    sp8 = lbl_805622E0;
    f32 temp_f2 = lbl_805622E0 * -temp_f0;
    spC = lbl_805622E0;
    sp10 = lbl_805622E0;
    arg1[0] = *(f32*)((u8*)temp_r3 + 0x24) + temp_f2;
    arg1[1] = *(f32*)((u8*)temp_r3 + 0x28) + temp_f2;
    arg1[2] = *(f32*)((u8*)temp_r3 + 0x2C) + temp_f2;
    arg2[0] = *(f32*)((u8*)temp_r3 + 0x24) + temp_f1;
    arg2[1] = *(f32*)((u8*)temp_r3 + 0x28) + temp_f1;
    arg2[2] = *(f32*)((u8*)temp_r3 + 0x2C) + temp_f1;
}

extern void fn_801C28A8(void*, void*, void*, void*, void*, s32, s32, void*);
void fn_801A26FC(void* arg0, void* arg1) {
    u32 type = *(u32*)((u8*)arg1 + 0x18);
    if ((type - 0x47525500U) == 0x5550U) {
        Vec delta;
        f32* a = *(f32**)((u8*)arg0 + 0xC);
        f32* b = *(f32**)((u8*)arg1 + 0xC);
        delta.x = a[9] - b[9];
        delta.y = a[10] - b[10];
        delta.z = a[11] - b[11];
        f32 d = PSVECDotProduct(&delta, &delta);
        f32 radius = *(f32*)((u8*)arg0 + 0x24) +
            ((f32 (*)(void*))(*(u32*)(*(u32*)arg1 + 0x3C)))(arg1);
        if (d < radius * radius) {
            void* x = *(void**)((u8*)arg1 + 0x17C);
            Vec out;
            fn_801C28A8(*(void**)((u8*)arg0 + 0x30), x, a, b, &out,
                         *(s32*)((u8*)arg0 + 0x28), *(s32*)((u8*)arg0 + 0x2C), 0);
        }
    } else if ((type - 0x424F5800U) == 0x5820U) {
    } else if ((type - 0x504F4C00U) == 0x4C59U) {
    }
}

extern "C" void* fn_801A2C9C(void* arg0) {
    return (u8*)arg0 + 0x44;
}

extern "C" f32 fn_801A2CA4(void* arg0) {
    return *(f32*)((u8*)arg0 + 0x178);
}

extern "C" void fn_801A2CAC(void *arg0) {
    extern s32 lbl_8055E598;
    extern void fn_801E3FC8(s32, s32, s32, f32);
    s32 temp_r5 = *(s32 *)((u8 *)arg0 + 0xC);
    fn_801E3FC8(temp_r5 + 0x24, lbl_8055E598, temp_r5, *(f32 *)((u8 *)arg0 + 0x24));
}

extern void fn_8019ECC4();
extern char lbl_803337C8;
extern void fn_801E3FC8(s32, s32, s32, f32);
extern s32 lbl_8055E598;
__declspec(section ".data") extern char lbl_803337C8;
extern "C" void* fn_801A2CC0(void* arg0, s32 arg1, s32 arg2) {
    u8 temp_r6;
    u8 temp_r7;
    u8 temp_r8;
    u8 temp_r9;
    fn_8019ECC4();
    *(void**)arg0 = &lbl_803337C8;
    if (arg2 != 0) {
        temp_r6 = *(u8*)((u8*)arg0 + 0x24);
        temp_r8 = *(u8*)((u8*)arg0 + 0x25);
        temp_r7 = *(u8*)((u8*)arg0 + 0x28);
        temp_r9 = *(u8*)((u8*)arg0 + 0x29);
        *(u8*)((u8*)arg0 + 0x24) = *(u8*)((u8*)arg0 + 0x27);
        *(u8*)((u8*)arg0 + 0x27) = temp_r6;
        *(u8*)((u8*)arg0 + 0x25) = *(u8*)((u8*)arg0 + 0x26);
        *(u8*)((u8*)arg0 + 0x26) = temp_r8;
        *(u8*)((u8*)arg0 + 0x28) = *(u8*)((u8*)arg0 + 0x2B);
        *(u8*)((u8*)arg0 + 0x2B) = temp_r7;
        *(u8*)((u8*)arg0 + 0x29) = *(u8*)((u8*)arg0 + 0x2A);
        *(u8*)((u8*)arg0 + 0x2A) = temp_r9;
    }
    return arg0;
}

extern "C" void fn_801A2EC8(void) {

}

extern "C" void fn_801A3174(void *arg0) {
    ((void (*)(s32, s32, f32))fn_801E3FC8)(*(s32*)((u8*)arg0 + 0xC) + 0x24, lbl_8055E598, *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)arg0 + 0x28));
}

extern s32 lbl_80333778;
extern "C" void fn_801A3190(void *arg0, s32 arg1, void *arg2, s32 arg3, void *arg4, void *arg5, f32 farg0, f32 farg1) {
    s32 i;
    u8 *dst = (u8*)arg0;
    u8 *src = (u8*)arg2;
    *(s32*)(dst + 0xC) = arg1;
    *(s32*)(dst + 4) = 0;
    *(s32*)(dst + 0x18) = 0x504F4C59;
    *(s32*)(dst + 8) = 0;
    *(f32*)(dst + 0x10) = farg0;
    *(f32*)(dst + 0x14) = farg1;
    *(s32*)(dst + 0x20) = 100;
    *(s32*)(dst + 0x1C) = 0;
    *(void**)dst = &lbl_80333778;
    *(s32*)(dst + 0xDC) = 0;
    *(s32*)(dst + 0xBC) = arg3;
    for (i = 0; i < arg3; i++) {
        *(s32*)(dst + 0x3C) = *(s32*)src;
        *(s32*)(dst + 0x40) = *(s32*)(src + 4);
        *(s32*)(dst + 0x44) = *(s32*)(src + 8);
        *(f32*)(dst + 0x48) = *(f32*)(src + 0xC);
        src += 0x10;
        dst += 0x10;
    }
    *(f32*)((u8*)arg0 + 0x24) = ((f32*)arg4)[0];
    *(f32*)((u8*)arg0 + 0x28) = ((f32*)arg4)[1];
    *(f32*)((u8*)arg0 + 0x2C) = ((f32*)arg4)[2];
    *(f32*)((u8*)arg0 + 0x30) = ((f32*)arg5)[0];
    *(f32*)((u8*)arg0 + 0x34) = ((f32*)arg5)[1];
    *(f32*)((u8*)arg0 + 0x38) = ((f32*)arg5)[2];
}

f32 fn_801A3880(void* arg0) {
    f32 first;
    f32 second;
    first = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x30), (const Vec *)((u8 *)arg0 + 0x30));
    second = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x24), (const Vec *)((u8 *)arg0 + 0x24));
    if (second > first) {
        first = second;
    }
    return (f32)fn_8002F234(first);
}

extern "C" void fn_8019ECC4(void);
extern "C" void fn_801CFA48(void*);
extern s32 lbl_80333728;
void* fn_801A3F5C(void* arg0, s32 arg1, s32 arg2) {
    fn_8019ECC4();
    *(s32*)arg0 = (s32)&lbl_80333728;
    if (arg2 != 0) {
        *(void**)((u8*)arg0 + 0x24) = (u8*)arg0 + 0x40;
        fn_801CFA48((u8*)arg0 + 0x40);
    }
    return arg0;
}

#pragma push
#pragma small_data off
void *__dt__Q28PSSystem7SeqHeapFv_801A3FB8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80333728;
        ((void (*)(void *))fn_801CFF14)(*(void **)((u8 *)arg0 + 0x24));
        if (arg1 > 0)
            ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}
#pragma pop
void fn_801A442C(void *arg0, void *arg1, void *arg2) {
    *(f32 *)((u8 *)arg1 + 0) = *(f32 *)((u8 *)arg0 + 0x28);
    *(f32 *)((u8 *)arg1 + 4) = *(f32 *)((u8 *)arg0 + 0x2C);
    *(f32 *)((u8 *)arg1 + 8) = *(f32 *)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg2 + 0) = *(f32 *)((u8 *)arg0 + 0x34);
    *(f32 *)((u8 *)arg2 + 4) = *(f32 *)((u8 *)arg0 + 0x38);
    *(f32 *)((u8 *)arg2 + 8) = *(f32 *)((u8 *)arg0 + 0x3C);
}

f32 fn_801A4460(void *arg0) {
    f32 first;
    f32 second;
    first = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x34), (const Vec *)((u8 *)arg0 + 0x34));
    second = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x28), (const Vec *)((u8 *)arg0 + 0x28));
    if (second > first) {
        first = second;
    }
    return (f32)fn_8002F234(first);
}

extern "C" void fn_801A44C4(void* arg0) {
    fn_801CFF18(*(s32*)((u8*)arg0 + 0x24), *(s32*)((u8*)arg0 + 0xC));
}

extern "C" void fn_801A44D4(void* arg0) {
    register s32* r29 = (s32*)arg0;
    register s32 r30 = 0;
    register s32 r31 = 0;
    goto check;
loop:
    fn_801A49FC(*(s32*)((u8*)r29[1] + r30));
    r30 += 4;
    r31++;
check:
    if (r31 < r29[0]) goto loop;
}

#pragma scheduling invalid_target
extern "C" void fn_801A4538(void* arg0) {
    fn_8012C4E4(arg0, &fn_801A44D4, 0);
}
#pragma scheduling on
extern "C" void fn_801A4768(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

extern "C" void fn_801A4780(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

extern "C" void fn_801A4798(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

extern "C" void fn_801A47B0(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

#pragma opt_tail_call on
void fn_801A47C8(void* arg0) {
    s32 limit = *(s32*)arg0;
    s32** ptrs = *(s32***)((u8*)arg0 + 4);
    for (s32 i = 0; i < limit; i++) {
        ((u8*)ptrs[i])[0x40] = 1;
    }
}

#pragma opt_tail_call on
void fn_801A47FC(void* arg0) {
    if (arg0) {
        s32 limit = *(s32*)arg0;
        s32** ptrs = *(s32***)((u8*)arg0 + 4);
        for (s32 i = 0; i < limit; i++) {
            fn_801A49E8((void*)ptrs[i]);
        }
    }
}

#pragma opt_tail_call on
void fn_801A4868(void* arg0, u8 arg1) {
    if (*(u8*)((u8*)arg0 + 0x40) != arg1) {
        s32 local38;
        u8 localC;
        local38 = *(s32*)((u8*)arg0 + 0x38);
        localC = arg1;
        fn_801796EC(12, (s32*)&local38, 8);
        *(u8*)((u8*)arg0 + 0x40) = arg1;
    }
}

void fn_801A48C8(void* arg0) {
    void* ptr = *(void**)((u8*)arg0 + 0x48);
    ((void(*)(void*, void*, void**))(*(void***)((u8*)ptr + 0x18)))(ptr, &lbl_8055A508, &lbl_8055A510);
}

extern void fn_801EA1E0(void*, s32, f32, f32);
void fn_801A48E4(void* arg0) {
    u8* obj = (u8*)arg0;
    void* mat;
    f32 scale;
    f32 sp8, spC, sp10;
    *(u8*)(obj + 0x40) = 1;
    mat = *(void**)(obj + 0x3C);
    ((void (*)(void*))(*(u32*)*(u32*)mat + 0xC))(mat);
    if (*(s32*)((u8*)mat + 0x18) == 0x53504852) {
        fn_801EA1E0((u8*)mat + 0x38, 0, *(f32*)((u8*)mat + 0x34), *(f32*)((u8*)mat + 0x3C));
        fn_801EA1E0(obj + 0x2C, 0, *(f32*)(obj + 0x28), *(f32*)(obj + 0x30));
    }
    if (*(s32*)((u8*)mat + 0x18) == 0x54554245) {
        scale = *(f32*)(obj + 0x20) > lbl_805622D0 ? lbl_805622DC : lbl_805622E0;
        sp8 = *(f32*)(obj + 0x28) + *(f32*)(obj + 0x1C) * scale * *(f32*)((u8*)mat + 0x28);
        spC = *(f32*)(obj + 0x2C) + *(f32*)(obj + 0x20) * scale * *(f32*)((u8*)mat + 0x28);
        sp10 = *(f32*)(obj + 0x30) + *(f32*)(obj + 0x24) * scale * *(f32*)((u8*)mat + 0x28);
        fn_801EA1E0(obj + 0x2C, 0, sp8, sp10);
    }
}

void fn_801A49E8(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x48) != 0) {
        fn_801D0650();
    }
}

extern "C" void fn_801D06C4(void);
extern "C" void fn_8019BD54(void*, void*, s32, s32);
extern "C" void fn_8019D06C(void*, void*, s32, s32);
extern "C" void fn_8019EA7C(void*, void*);
extern f32 lbl_8056237C;
extern f32 lbl_80562300;
extern void fn_8019EECC(void*, void*);
extern void fn_8019EF00(void*);
extern void fn_801E3FC8(void*, s32, f32);
void fn_801A49FC(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x48) != 0) {
        fn_801D06C4();
    }
}

#pragma push
#pragma small_data off
extern "C" void fn_801A4E28(void) {
    lbl_8055E5A0 = fn_801CFEAC(&lbl_803336EC[0]);
}
#pragma pop
extern "C" void fn_801A4E54(void) {
    if (lbl_8055E5A0 != 0) {
        ((void (*)(s32))fn_801CFF14)(lbl_8055E5A0);
        lbl_8055E5A0 = 0;
    }
}

extern "C" void fn_801D0650(void);
extern s32 lbl_8055E5A0;
extern void fn_801CFF14(void);
extern s32 fn_801CF828(s32, s32, s32, s32, s32);
extern "C" s32 fn_801A4E88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32* arg4) {
    register s32 a0 = arg0;
    register s32 a1 = arg1;
    register s32 a2 = arg2;
    register s32* out = arg4;
    s32 result = 0;
    if (lbl_8055E5A0 != 0 && fn_801CF828(lbl_8055E5A0, a0, a1, a2, arg3) != 0) {
        *out = 0x6E;
        result = 1;
    }
    return result;
}

extern "C" s32 fn_801A4F00(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F40(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F80(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4FC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5000(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5040(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5080(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A50C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" f32 fn_801A5100(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" void fn_801A5108(void* arg0) {
    *(s32*)((u8*)arg0 + 0x180) = -1;
}

extern "C" f32 fn_801A5114(void *arg0) {
    return ((f32 *)arg0)[0x30 / 4];
}

extern "C" f32 fn_801A511C(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" float fn_801A5124(void* arg0) {
    return *(float*)((char*)arg0 + 0x28);
}

extern "C" s32 fn_801A512C(void) {
    return 0;
}

extern "C" s32 fn_801A5134(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5174(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x48);
}

extern "C" s32 fn_801A517C(s32 arg0) {
    return arg0 + 0x28;
}

extern "C" u8 fn_801A5184(void *arg0) { return *((u8*)arg0 + 0x40); }

extern "C" void fn_801A4868(void);

extern "C" void fn_801A4868(void);
extern "C" void fn_801A4868(void*, u8);

extern "C" void fn_801A518C(void) {
    fn_801A4868();
}

extern "C" void fn_801A5190(void* arg0) {
    VTab19* p = *(VTab19**)((u8*)arg0 + 0x3C);
    if (p == NULL) {
        return;
    }
    p->v14();
}

extern "C" s32 fn_801A51B0(void* arg0) {
    void* obj = *(void**)((u8*)arg0 + 0x3C);
    if (obj != NULL) {
        return *(s32*)((u8*)obj + 0x20);
    }
    return -1;
}

extern "C" s32 fn_801A51CC(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x34);
}

extern "C" void fn_801A51D4(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0x34) = arg1;
}
extern void fn_8019ECC4(void);
extern void* lbl_80333968;
extern f32 lbl_80562370;
typedef void (*VFunc)(void*);
typedef void (*VFuncArg)(void*, s32);
extern f32 lbl_805622DC;

