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
extern void __array_delete(void*, void*, s32, s32);
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

typedef struct Row801B4570 { s32 key; f32 value; } Row801B4570;
typedef struct Cursor801B4570 { Row801B4570 *rows; s32 count; s32 index; } Cursor801B4570;
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
#pragma pack(push, 1)
typedef struct Cp38_801B34DC { f64 d0; s32 w0; f64 d1; s32 w1; f64 d2; s32 w2; f64 d3; s32 w3; s32 w4; s32 w5; } Cp38_801B34DC;
#pragma pack(pop)
extern void* fn_801B3338(void*);
extern s32 fn_801B32C8(void*, s32);
extern s32 fn_801B3DC0(void*, u32, u32);
extern void fn_801B3E24(void *, void *, void *, s32, s32, f32);

typedef struct Ent801B3FD8 { s32 a; s32 group; f32 c; } Ent801B3FD8;
typedef struct Out801B3FD8 { Ent801B3FD8* p; s32 n; s32 z; } Out801B3FD8;

/* One of the 16 sound slots the manager at lbl_8055E6C0 keeps at +0x2FC (its ring
   index is at +0x5BC).  fn_801B42D0 builds the slot's Sound3D on the two vectors
   and fn_801B3E24 fills in what it is playing: the object, that object's pair key
   and the game time it was started at (lbl_80562650 = never). */
typedef struct SoundSlot801B3DC0 {
    void*          vtable;      /* 0x00 */
    V3_801B34DC    pos;         /* 0x04: where its sound plays (live, the Sound3D points here) */
    V3_801B34DC    vel;         /* 0x10: the sound's second vector, kept at zero */
    s32            sound;       /* 0x1C: the Sound3D built on those two vectors */
    u32            object;      /* 0x20: object the sound was last played for */
    u32            key;         /* 0x24: that object's pair key */
    f32            time;        /* 0x28: game time (lbl_8055E3C8) it was played at */
} SoundSlot801B3DC0;            /* 0x2C */

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
#pragma dont_inline on
s32 fn_801B32C8(void* arg0, s32 arg1) {
    s32 vals[2];
    s32 first = *(s32*)((char*)arg0 + 0x20);
    s32 result = 0;

    *(volatile s32*)&vals[0] = first;
    *(volatile s32*)&vals[1] = arg1;
    {
        s32 idx = (first == 0x6D) ? 0 : (arg1 == 0x6D) ? 1 : -1;
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
    }
    return result;
}
#pragma scheduling on
#pragma dont_inline on
/* Returns the inner object if it carries a known vehicle/archive tag (CAR / PCAR / ACAR / NCAR), else NULL. */
void *fn_801B3338(void *container) {
    s32 *object = *(s32 **)((char *)container + 4);
    if (object != NULL) {
        s32 found = 0;
        s32 tag = object[4];
        if ((u32)(tag - 0x43410000) == 0x5220 ||
            (u32)(tag - 0x50430000) == 0x4152 ||
            (u32)(tag - 0x41430000) == 0x4152 ||
            (u32)(tag - 0x4E430000) == 0x4152) {
            found = 1;
        }
        if (found != 0) {
            return object;
        }
    }
    return NULL;
}
#pragma dont_inline off

int fn_801B3390(void) {
    /* Handler registered for replay event 1: reports its fixed payload size, 0x14 bytes. */
    return 0x14;
}

#pragma use_lmw_stmw off
/* Copy 0x38 bytes from src into a local buffer and pass them to fn_801796CC; returns the size copied. */
s32 fn_801B3398(void* src) {
    Unk801B3398 local;
    s32 t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    t0 = *(volatile s32 *)((char *)src + 0x00);
    t1 = *(volatile s32 *)((char *)src + 0x04);
    t2 = *(volatile s32 *)((char *)src + 0x08);
    t3 = *(volatile s32 *)((char *)src + 0x0C);
    t4 = *(volatile s32 *)((char *)src + 0x10);
    t5 = *(volatile s32 *)((char *)src + 0x14);
    t6 = *(volatile s32 *)((char *)src + 0x18);
    t7 = *(volatile s32 *)((char *)src + 0x1C);
    t8 = *(volatile s32 *)((char *)src + 0x20);
    t9 = *(volatile s32 *)((char *)src + 0x24);
    t10 = *(volatile s32 *)((char *)src + 0x28);
    t11 = *(volatile s32 *)((char *)src + 0x2C);
    t12 = *(volatile s32 *)((char *)src + 0x30);
    t13 = *(volatile s32 *)((char *)src + 0x34);
    local.unk_0x00 = t0; local.unk_0x04 = t1; local.unk_0x08 = t2; local.unk_0x0C = t3;
    local.unk_0x10 = t4; local.unk_0x14 = t5; local.unk_0x18 = t6; local.unk_0x1C = t7;
    local.unk_0x20 = t8; local.unk_0x24 = t9; local.unk_0x28 = t10; local.unk_0x2C = t11;
    local.unk_0x30 = t12; local.unk_0x34 = t13;
    fn_801796CC(1, &local, 0x38);
    return 0x38;
}
#pragma push
#pragma scheduling invalid_target
void fn_801B3448(void) {
    void *check = (void *)fn_801284F8(0x5C0, &lbl_80335D3C);
    if (check != 0) {
        check = fn_801B3B70(check);
        *(void **)&lbl_8055E6C0 = check;
    }
    fn_801B5364(1, (void *)((u32)fn_801B3390 + 0));
    fn_801B5364(0xF, fn_801B3398);
}
#pragma pop
/* Reset all collision-sound history when the game state is restarted.
   lbl_8055E6C0 is the global collision-sound manager; fn_801B3DBC clears its
   16 per-pair sound records (played object / key / time). lbl_80435C50 is the
   8-entry table of last-play times by sound id, zeroed so a sound can retrigger. */
void fn_801B34A4(void) {
    fn_801B3DBC((void*)lbl_8055E6C0);
    memset(lbl_80435C50, 0, 0x20);
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801B34DC(void *arg0, void *arg1, V3_801B34DC *pos, V3_801B34DC *arg3, V3_801B34DC *arg4, s32 arg5) {
    Ev38_801B34DC ev;
    Cp38_801B34DC cp1;
    Cp38_801B34DC cp2;
    Ev30_801B34DC e30;
    Ev20_801B34DC e20;
    Ev14_801B34DC e14;
    V3_801B34DC a;
    V3_801B34DC b;
    V3_801B34DC p1, diff, p2, sc;
    V3_801B34DC t;
    Cp38_801B34DC *s = (Cp38_801B34DC *)&ev;
    f32 d, f;
    void *r31;
    void *r26;
    s32 ok, in;
    u32 ax, az, ay, bx, by, bz;
    ax = ((u32 *)arg3)[0]; ay = ((u32 *)arg3)[1]; az = ((u32 *)arg3)[2];
    bx = ((u32 *)arg4)[0]; by = ((u32 *)arg4)[1]; bz = ((u32 *)arg4)[2];
    ((u32 *)&a)[0] = ax; ((u32 *)&a)[1] = ay; ((u32 *)&a)[2] = az;
    ((u32 *)&b)[0] = bx; ((u32 *)&b)[1] = by; ((u32 *)&b)[2] = bz;
    if (*(s32 *)((u8 *)arg0 + 4) == 0) {
        void *sw = arg0;
        arg0 = arg1;
        a.x *= lbl_80562620; a.y *= lbl_80562620; a.z *= lbl_80562620;
        b.x *= lbl_80562620; b.y *= lbl_80562620; b.z *= lbl_80562620;
        arg1 = sw;
        if (sw != 0) arg5 = *(s32 *)((u8 *)sw + 0x20);
    }
    fn_8017B6D4(*(void **)((u8 *)arg0 + 4), &p1, pos);
    if (arg1 != 0 && *(void **)((u8 *)arg1 + 4) != 0) {
        fn_8017B6D4(*(void **)((u8 *)arg1 + 4), &p2, pos);
    } else {
        p2.x = lbl_80562624; p2.y = lbl_80562624; p2.z = lbl_80562624;
    }
    diff.x = p1.x - p2.x; diff.y = p1.y - p2.y; diff.z = p1.z - p2.z;
    d = PSVECDotProduct(&b, &a);
    {
        u32 kindIndex = (u32)arg5 - 0x6B;
        in = 0;
        ok = 1;
        if (kindIndex <= 3 && ((1U << kindIndex) & 0xD) != 0) {
            in = 1;
        }
        if ((in & 1) == 0 && arg5 >= 8) ok = 0;
    }
    r31 = fn_801B3338(arg0);
    if (r31 != 0 && ok != 0 && d * d > lbl_80562628 && PSVECDotProduct(&diff, &diff) > lbl_8056262C) {
        if (arg1 != 0) r26 = fn_801B3338(arg1); else r26 = 0;
        {
            f32 bz, by, bx, pz, py, px, az, ay, ax;
            f32 secondY, secondX, firstY, firstX;
            f32 combinedZ, combinedY, combinedX, firstZ, scale;
            {
                f32 first = p1.x;
                scale = lbl_80562630;
                firstX = first * scale;
            }
            firstY = p1.y * scale;
            firstZ = p1.z * scale;
            secondX = p2.x * scale;
            secondY = p2.y * scale;
            combinedX = firstX + secondX;
            combinedY = firstY + secondY;
            ax = a.x; ay = a.y; az = a.z;
            px = pos->x;
            combinedZ = firstZ + p2.z * scale;
            py = pos->y; pz = pos->z;
            bx = b.x; by = b.y; bz = b.z;
            ev.a.x = combinedX; ev.a.y = combinedY; ev.a.z = combinedZ;
            ev.c.x = ax; ev.c.y = ay; ev.c.z = az;
            ev.b.x = px; ev.b.y = py; ev.b.z = pz;
            ev.d.x = bx; ev.d.y = by; ev.d.z = bz;
        }
        ev.kind = arg5;
        ev.id = *(s32 *)((u8 *)r31 + 0x1EC);
        fn_801796CC(1, &ev, 0x38);
        cp1.d0 = s->d0; cp1.w0 = s->w0; cp1.d1 = s->d1; cp1.w1 = s->w1;
        cp1.d2 = s->d2; cp1.w2 = s->w2; cp1.d3 = s->d3; cp1.w3 = s->w3;
        cp1.w4 = s->w4; cp1.w5 = s->w5;
        fn_801B5360(0xF, &cp1, 0x38);
        if (r26 != 0) {
            ev.a.x *= lbl_80562620; ev.a.y *= lbl_80562620; ev.a.z *= lbl_80562620;
            ev.id = *(s32 *)((u8 *)r26 + 0x1EC);
            fn_801796CC(1, &ev, 0x38);
            cp2.d0 = s->d0; cp2.w0 = s->w0; cp2.d1 = s->d1; cp2.w1 = s->w1;
            cp2.d2 = s->d2; cp2.w2 = s->w2; cp2.d3 = s->d3; cp2.w3 = s->w3;
            cp2.w4 = s->w4; cp2.w5 = s->w5;
            fn_801B5360(0xF, &cp2, 0x38);
        }
    }
    if (PSVECDotProduct(&p1, &p1) > lbl_80562634 && fn_801B32C8(arg0, arg5) != 0) {
        f32 z, y, x, pz, py, px;
        px = pos->x; py = pos->y; pz = pos->z;
        x = p1.x; y = p1.y; z = p1.z;
        e20.q.x = px; e20.q.y = py; e20.q.z = pz;
        e20.p.x = x; e20.p.y = y; e20.p.z = z;
        e20.s = *(s16 *)(*(u8 **)((u8 *)arg0 + 4) + 0x6C);
        e20.id = r31 != 0 ? *(s32 *)((u8 *)r31 + 0x1EC) : -1;
        fn_801796CC(0, &e20, 0x20);
    }
    if (r31 != 0 && arg5 < 8 && ((s32 *)lbl_80435C50)[*(s32 *)((u8 *)r31 + 0x1EC)] < lbl_8055E3C4) {
        f32 bz, by, bx, z, y, x, pz, py, px;
        px = pos->x; py = pos->y; pz = pos->z;
        x = p1.x; y = p1.y; z = p1.z;
        bx = b.x; by = b.y; bz = b.z;
        e30.p.x = px; e30.p.y = py; e30.p.z = pz;
        e30.q.x = x; e30.q.y = y; e30.q.z = z;
        e30.r.x = bx; e30.r.y = by; e30.r.z = bz;
        e30.dot = d;
        e30.id = *(s32 *)((u8 *)r31 + 0x1EC);
        e30.kind = arg5;
        fn_801796CC(5, &e30, 0x30);
        ((s32 *)lbl_80435C50)[*(s32 *)((u8 *)r31 + 0x1EC)] = lbl_8055E3C4;
    }
    if (r31 != 0 && arg5 == 0x6D) {
        r26 = fn_801B3338(arg1);
        fn_801B85E0(r31, r26, pos, &a);
        fn_801B3084(r31, r26, pos, &a);
    }
    if (arg5 == 0x6E) {
        sc.x = a.x * lbl_80562638; sc.y = a.y * lbl_80562638; sc.z = a.z * lbl_80562638;
    } else {
        sc.x = a.x; sc.y = a.y; sc.z = a.z;
    }
    if (fn_801B3DC0((void *)lbl_8055E6C0, (u32)arg0, (u32)arg1) == 0 && (((u32)(PSVECDotProduct(&sc, &sc) > lbl_8056263C) & 1U) != 0)) {
        f32 mag = PSVECMag(&sc);
        f32 limit = lbl_80562640;
        f32 clamped = limit < mag ? limit : mag;
        f = lbl_80562644 + lbl_80562648 * (clamped / lbl_80562640);
        e14.p = (*(volatile V3_801B34DC *)&t = *pos);
        e14.w = f;
        e14.id = 0x4D2;
        fn_801B5360(1, &e14, 0x14);
        fn_801B3E24((void *)lbl_8055E6C0, pos, arg0, (s32)arg1, arg5, f);
    }
}
#pragma pop
/* No operation. */
void fn_801B3B24(void) {

}

void fn_801B3B28(void) {
    /* Shut down this subsystem: unregister handlers fn_801B3390/fn_801B3398, destroy the
       global object at lbl_8055E6C0, and clear the global pointer. */
    fn_801B537C(fn_801B3390);
    fn_801B537C(fn_801B3398);
    fn_801B3D24((void*)lbl_8055E6C0, 1);
    lbl_8055E6C0 = 0;
}

#pragma scheduling invalid_target
/* Initialize this object, including the pool at offset 0x2FC and its subsystems. */
void *fn_801B3B70(void *self) {
    fn_8002F53C((u8 *)self + 0x2FC, fn_801B3C64, fn_801B3BD4, 0x2C, 0x10);
    fn_801B3FD8(self);
    fn_801B4204(self);
    fn_801B42D0(self);
    return self;
}
#pragma scheduling reset
/* Destroys the object, releases its owned child at offset 0x1C, and optionally frees it. */
void* fn_801B3BD4(void* obj, s32 shouldFree) {
    if (obj != NULL) {
        if (obj != NULL) {
            void* ownedChild = *(void**)((u8*)obj + 0x1C);
            *(void**)obj = (void*)&lbl_80335DAC;
            if (ownedChild != NULL) {
                if (ownedChild != NULL)
                    callPrevDtorCpp_801B3BD4(ownedChild);
                *(void**)((u8*)obj + 0x1C) = NULL;
            }
        }
        if (shouldFree > 0)
            fn_80128668(obj);
    }
    return obj;
}

void fn_801B3C64(void* object) {
    /* Construct a pool element: install the vtable (lbl_80335DAC), zero the six floats at +4..+0x18, and clear the owned child at +0x1C. */
    u8* bytes = (u8*)object;
    f32 zero = lbl_80562624;
    s32 i;

    *(void**)bytes = (void*)&lbl_80335DAC;
    for (i = 4; i < 0x1C; i += 4) {
        *(f32*)(bytes + i) = zero;
    }
    *(s32*)(bytes + 0x1C) = 0;
}

typedef void (*Vfn2)(void*, s32);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void *fn_801B3C98(void *self, s32 shouldDelete) {
    /* Destructor-like cleanup: install vtable, destroy owned object at +0x1C, and
       optionally free the object when shouldDelete > 0. */
    if (self != NULL) {
        void *owned = *(void **)((u8 *)self + 0x1C);
        *(void **)self = (void *)&lbl_80335DAC;
        if (owned != NULL) {
            if (owned != NULL)
                ((VTable_801B3C98 *)owned)->destroy(1);
            *(void **)((u8 *)self + 0x1C) = NULL;
        }
        if (shouldDelete > 0)
            fn_80128668(self);
    }
    return self;
}
#pragma cplusplus reset
#pragma scheduling on
/* Destroys this object: release 6 owned handles, destroy 0x10 embedded elements at +0x2FC, and optionally free. */
void* fn_801B3D24(void* obj, s32 shouldFree) {
    if (obj != NULL) {
        s32* slot = (s32*)obj;
        s32 i;

        for (i = 0; i < 6; i++) {
            fn_80128670(*slot);
            slot += 3;
        }
        __array_delete((u8*)obj + 0x2FC, (void*)fn_801B3BD4, 0x2C, 0x10);
        if (shouldFree > 0) {
            fn_80128668(obj);
        }
    }
    return obj;
}
#pragma scheduling reset
void fn_801B3DBC(void* collisionManager) {
    /* Reset this manager's collision-sound history by clearing its 16 recent-collision records. */
    fn_801B435C(collisionManager);
}

/* hasRecentSoundSlot: TRUE if one of the manager's 16 sound slots is already
   playing for (object, key) - that is, holds that pair and was started less than
   half a second (lbl_80562630) ago, lbl_8055E3C8 being the running game time.
   The impact handler uses this to keep one collision from retriggering its
   sound every frame. */
s32 fn_801B3DC0(void* owner, u32 object, u32 key) {
    SoundSlot801B3DC0* slot = (SoundSlot801B3DC0*)((u8*)owner + 0x2FC);
    s32 found = 0;
    s32 i = 0;

    while (found == 0 && i < 0x10) {
        found = 0;
        if (slot->object == object && slot->key == key
            && slot->time > lbl_8055E3C8 - lbl_80562630) {
            found = 1;
        }
        slot++;
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
    s32 selectedKey;
    void *selected;
    void *item;
    Item *object;
    f32 z;
    f32 y;
    f32 x;
    f32 zero;
    f32 maximum;
    f32 product;
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
        product = farg0 * *(f32 *)((u8 *)selected + 4);
        maximum = (maximum > product) ? product : maximum;
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
/* Query stub: always answers 0 (false) in this build. */
s32 fn_801B3FD0(void) {
    return 0;
}

extern char lbl_80335D50[];
extern u8 lbl_80335D74[];
extern void Abend_Panic(const char*, ...);
extern void* fn_8012850C(s32, void*);
void fn_801B3FD8(void* arg0) {
    struct OutRec { s32 a; f32 c; };
    Out801B3FD8* out = (Out801B3FD8*)arg0;
    Ent801B3FD8* tbl = (Ent801B3FD8*)lbl_802F9630;
    s32 g;
    u32 pos = 0;
    s32 start;
    for (g = 0; g < 6; g++, out++) {
        s32 n, i;
        start = pos;
        while (pos < 13 && tbl[pos].group == g) pos++;
        n = pos - start;
        if (n < 1) Abend_Panic(lbl_80335D50);
        out->p = (Ent801B3FD8*)fn_8012850C(n * 8, lbl_80335D74);
        out->n = n;
        out->z = 0;
        for (i = 0; i < n; i++) {
            struct OutRec* d = &((struct OutRec*)out->p)[i];
            d->a = ((Ent801B3FD8*)lbl_802F9630)[start + i].a;
            d->c = ((Ent801B3FD8*)lbl_802F9630)[start + i].c;
        }
    }
}

extern s32 lbl_802F96CC[];
extern s32 fn_801B4428(u32 *, u32 *);
extern void *fn_801B447C(void *, void *, s32);
extern void qsort(void *, u32, u32, s32 (*)(u32 *, u32 *));
void fn_801B4204(void *arg0) {
    s32 key;
    s32 a;
    s32 b;
    s32 i;
    s32 n;
    s32 *src;
    u8 *base;
    register u8 *dst;

    base = (u8 *)arg0;
    src = lbl_802F96CC;
    dst = base;
    for (i = 0; i < 0x2B; i++) {
        a = src[1];
        b = src[2];
        if (a < 0 || b < 0) {
            key = -1;
        } else if (a < b) {
            key = ((a & 0xFFFF) << 16) | (b & 0xFFFF);
        } else {
            key = ((b & 0xFFFF) << 16) | (a & 0xFFFF);
        }
        n = src[0];
        *(s32 *)(dst + 0x48) = key;
        *(s32 *)(dst + 0x4C) = (s32)arg0 + n * 0xC;
        *(s32 *)(dst + 0x50) = 0;
        *(s32 *)(dst + 0x54) = 0;
        src += 3;
        dst += 0x10;
    }
    qsort(base + 0x48, 0x2B, 0x10, fn_801B4428);
    *(void **)(base + 0x2F8) = fn_801B447C(arg0, base + 0x48, 0x2B);
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Initialize 16 sound/slot entries at +0x2FC and clear the count at +0x5BC. */
void fn_801B42D0(void *owner) {
    u8 *entry = (u8 *)owner + 0x2FC;
    void *context = *(void **)lbl_802F9630;
    f64 initialValue = lbl_80562650;
    s32 i;
    s32 zero = 0;
    for (i = 0; i < 0x10; i++, entry += 0x2C) {
        *(s32 *)(entry + 0x1C) = fn_802077A4(context, 5, entry + 0x10, entry + 4);
        *(s32 *)(entry + 0x20) = 0;
        *(s32 *)(entry + 0x24) = 0;
        *(f32 *)(entry + 0x28) = initialValue;
    }
    *(s32 *)((u8 *)owner + 0x5BC) = 0;
}
#pragma pop
/* Clear the 16 recent-collision records at +0x31C: object, key, and play time (-5.0f = never). */
void fn_801B435C(void *arg0) {
    struct CollisionRecord {
        s32 object;
        s32 key;
        f32 time;
        u8 pad[0x20];
    } *record = (struct CollisionRecord *)((u8 *)arg0 + 0x31C);
    int i;

    for (i = 0; i < 16; i++) {
        record[i].object = 0;
        record[i].key = 0;
        record[i].time = -5.0f;
    }
}

extern void Abend_Panic(const char *, ...);
extern u8 lbl_80335D80[];
#pragma scheduling invalid_target
/* qsort comparator for the 0x2B collision-pair nodes fn_801B4204 lays out at +0x48
   (one 16-byte node per colliding pair of objects, its packed pair key in the first
   word).  Orders two nodes by that key; fn_801B447C then turns the sorted array into
   a balanced binary search tree that fn_801B4528 searches by key, so two nodes may
   not share one. */
s32 fn_801B4428(u32 * __restrict nodeA, u32 * __restrict nodeB) {
#define STR_SAME_KEY lbl_80335D80 /* "collide: tree nodes can't have the same key" */
    if (*nodeA < *nodeB) return -1;
    if (*nodeA > *nodeB) return 1;
    Abend_Panic((const char *)STR_SAME_KEY);
#undef STR_SAME_KEY
    return 0;
}
#pragma dont_inline on
/* Recursively build a balanced binary search tree from a sorted array of 16-byte collision-pair nodes: the middle node becomes the root and its +8/+0xC words link the left/right subtrees. */
void* fn_801B447C(void* context, void* nodes, s32 count) {
    s32 off;
    s32 mid;
    s32 rightCount;
    if (count == 1) return nodes;
    mid = ((s32)((u32)count >> 31) + count) >> 1;
    if (mid > 0) *(void**)((u8*)nodes + mid * 16 + 8) = fn_801B447C(context, nodes, mid);
    rightCount = count - mid - 1;
    if (rightCount > 0) {
        off = mid * 16;
        *(void**)((u8*)nodes + off + 12) = fn_801B447C(context, (u8*)nodes + 16 + off, rightCount);
    }
    return (u8*)nodes + mid * 16;
}
void *fn_801B4528(void *tree, u32 *node, u32 key) {
    /* Search a balanced binary tree node for the given key; return the node or NULL. */
    if (key < *node) {
        node = (u32 *)node[2];
        if (node != NULL) {
            return fn_801B4528(tree, node, key);
        }
        return NULL;
    } else if (key > *node) {
        node = (u32 *)node[3];
        if (node != NULL) {
            return fn_801B4528(tree, node, key);
        }
        return NULL;
    }
    return node;
}
#pragma scheduling invalid_target
/* Next collision-row pick for an object pair: search the balanced tree built at
 * +0x2F8 (fn_801B447C over the sorted pair nodes of fn_801B4204) for the node
 * with this packed pair key, take its cursor (stored at node+4) and return the
 * row the cursor points at, advancing the cursor round-robin
 * (index = (index + 1) % count) so repeated collisions between the same pair
 * walk through the pair's rows.  With no node for the key the object's own
 * header cursor is used.  fn_801B3E24 scales the collision sound by the
 * returned row's value. */
void* fn_801B4570(void* collide, u32 key) {
    Cursor801B4570 *cursor;
    void *found;
    Row801B4570 *rows;
    s32 index;
    Row801B4570 *row;
    cursor = (Cursor801B4570*)collide;
    found = fn_801B4528(collide, *(void**)((u8*)collide + 0x2F8), key);
    if (found != NULL) {
        cursor = *(Cursor801B4570**)((u8*)found + 4); /* the pair's own cursor */
    }
    index = cursor->index;
    rows = cursor->rows;
    row = &rows[index];
    cursor->index = (index + 1) % cursor->count;
    return row;
}
