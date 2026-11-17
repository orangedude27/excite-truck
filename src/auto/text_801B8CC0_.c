#include <revolution/MTX/mtxtypes.h>
void fn_801836E0(void *, int);
void fn_80128668(void *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern float lbl_80562750;
extern float lbl_80562754;
extern float lbl_80562758;
extern float lbl_8056275C;
extern float lbl_80562760;
extern float lbl_8056277C;
extern float lbl_80562780;
extern float lbl_80562784;
extern float lbl_80562788;
extern float lbl_8056278C;
extern float lbl_80562790;
extern float lbl_80562794;
extern float lbl_80562798;
extern float lbl_8056279C;
extern float lbl_805627A0;
extern float lbl_805627A4;
extern char lbl_80336A30[];
extern void fn_8017B4AC(void *, void *);
extern void fn_8018ADA4(void *, float);
extern void fn_801AD394(void *);
extern void fn_802E30C8(const char *, ...);
extern long fn_801796CC(long, long, long);
extern float PSVECDotProduct(const float *, const float *);
extern void fn_8018381C(void *);
extern void fn_80189C64(void *, void **);
extern void fn_8018A08C(void *);
extern void fn_801AD148(void *, float *, void *, float, float, float);
extern void fn_801AD28C(void *, float *, void *, void *, float, float, float);
// split_file divides it into the game's real files (file_status shows its range).

extern void* __AXFXGetLfoSinTable_801769CC(void);
extern int lbl_8055E774;
extern float lbl_80562764;
extern void* lbl_80436D28[];

/* The trailer cars.  One "trlr_car" (alloc tag lbl_803369C0, vtable
   lbl_803369D0, 0x2760 bytes) per player index, kept in lbl_80436D28 next to
   the player it trails (lbl_80430830, handed out by fn_8017960C).
   fn_801B8E28 places one every frame and fn_801B949C (vtable+0x10) resets it;
   both hand the pose they work out to fn_80189CB4 at vtable+0x54. */

#pragma push
#pragma cplusplus on

/* What ties a body's point to a target point; see the Spring note in
   src/auto/text_801A9660_.c, whose fn_801AD0E0/fn_801AD148/fn_801AD28C set one
   up and fn_801AD394 measures it and applies the force it gives. */
struct Spring {
    Vec target;       /* 0x00 the point the anchor is pulled towards */
    void *other;      /* 0x0C the body the target is a point of, 0 for a fixed point */
    Vec anchor;       /* 0x10 the point on `body`, in its own frame */
    f32 strength;     /* 0x1C force per unit of stretch */
    f32 damping;      /* 0x20 */
    f32 range;        /* 0x24 how far past the rest length it still pulls */
    f32 restLength;   /* 0x28 */
    f32 stretch;      /* 0x2C */
    f32 flatDistance; /* 0x30 */
    void *body;       /* 0x34 the body the anchor rides on */
};                    /* 0x38 */

/* One of the eight players: a moving body whose pose is three axes and a
   position (fn_8017AB84 transforms a point by them; see the RigidBody note in
   src/auto/text_8017B0B0_.c), plus the frame its trailer hangs from and the
   way it is pointing. */
struct PlayerCar {
    char pad0[0x3C];
    Vec axes[3];          /* 0x3C the body's world frame */
    Vec position;         /* 0x60 */
    s16 heading;          /* 0x6C */
    u8 pad6E[2];
    Vec trailerAxes[3];   /* 0x70 the frame the trailer is placed in */
    Vec trailerPos;       /* 0x94 */
    char padA0[0x118 - 0xA0];
    Vec velocity;         /* 0x118 */
};

struct TrlrCar {
    void *vtable;             /* 0x00 */
    char pad4[0x2C];
    Vec localPoint;           /* 0x30 a point of the body, in its own frame */
    char pad3C[0x18];
    Vec facing;               /* 0x54 the body's facing axis, its frame's third axis */
    char pad60[0x2700 - 0x60];
    s32 index;                /* 0x2700 */
    struct Spring spring;     /* 0x2704 what pulls the trailer along */
    Vec anchorPos;            /* 0x273C the trailer's point in the level */
    Vec carPos;               /* 0x2748 the player's point in the level */
    struct PlayerCar *player; /* 0x2754 the player this trailer trails */
    f32 unk2758;              /* 0x2758 zeroed when the car is reset */
    u8 flag275C;              /* 0x275C fn_801B97D8 turns it into a fn_8018ADA4 value */
    u8 towed;                 /* 0x275D while set, the trailer hangs from the player */
};

/* The pose fn_80189CB4 (vtable+0x54) installs into a trailer car: it becomes
   the car's world pose (+0x3C, +0x60), its velocity (+0x118) and its heading
   (+0x6C). */
struct CarPose {
    Vec axes[3];      /* 0x00 the frame to place the trailer in */
    f32 position[3];  /* 0x24 where it goes, in the world */
    f32 velocity[3];  /* 0x30 how it travels along that frame */
    s32 flag;         /* 0x3C handed on to fn_801B30C0 */
    s16 heading;      /* 0x40 the way the player points */
};                    /* 0x44 */

/* A trailer car's own vtable: two leading destructor slots, so the pose setter
   is the twentieth declared method, at +0x54. */
struct TrlrCarVf {
    virtual void unk0(); virtual void unk1(); virtual void unk2(); virtual void unk3();
    virtual void unk4(); virtual void unk5(); virtual void unk6(); virtual void unk7();
    virtual void unk8(); virtual void unk9(); virtual void unk10(); virtual void unk11();
    virtual void unk12(); virtual void unk13(); virtual void unk14(); virtual void unk15();
    virtual void unk16(); virtual void unk17(); virtual void unk18();
    virtual void setPose(struct CarPose *pose, struct PlayerCar *player);
};

#pragma pop

static inline void transform_vec(float *out, const float *m, volatile float *in) {
    if (out == in) {
        register float x = in[0];
        register float y = in[1];
        register float z = in[2];
        float x0 = x * m[0] + y * m[3] + z * m[6];
        float x1 = x * m[1] + y * m[4] + z * m[7];
        float x2 = x * m[2] + y * m[5] + z * m[8];
        out[0] = x0;
        out[1] = x1;
        out[2] = x2;
    } else {
        out[0] = in[1] * m[3] + in[0] * m[0] + in[2] * m[6];
        out[1] = in[1] * m[4] + in[0] * m[1] + in[2] * m[7];
        out[2] = in[1] * m[5] + in[0] * m[2] + in[2] * m[8];
    }
}
#pragma cplusplus on
extern "C" static inline void transform_vec_struct(Vec *out, const float *m, volatile Vec *in) {
    if (out == in) {
        float x = in->x;
        float y = in->y;
        float z = in->z;
        float x0 = x * m[0] + y * m[3] + z * m[6];
        float x1 = x * m[1] + y * m[4] + z * m[7];
        float x2 = x * m[2] + y * m[5] + z * m[8];
        out->x = x0;
        out->y = x1;
        out->z = x2;
    } else {
        out->x = in->y * m[3] + in->x * m[0] + in->z * m[6];
        out->y = in->y * m[4] + in->x * m[1] + in->z * m[7];
        out->z = in->y * m[5] + in->x * m[2] + in->z * m[8];
    }
}
static inline void transform_vec_scheduled(float *out, const float *m, float *in) {
    if (out == in) {
        float m8, m5, m2, m7, m4, m1, m6, m3, m0;
        float z, y, x;
        m3 = m[3];
        m4 = m[4];
        m5 = m[5];
        m0 = m[0];
        m1 = m[1];
        m2 = m[2];
        m6 = m[6];
        m7 = m[7];
        m8 = m[8];
        x = in[0];
        y = in[1];
        z = in[2];
        out[0] = z * m6 + (x * m0 + y * m3);
        out[1] = z * m7 + (x * m1 + y * m4);
        out[2] = z * m8 + (x * m2 + y * m5);
    } else {
        float m3 = m[3];
        float m0 = m[0];
        float m6 = m[6];
        float z, y, x;
        y = in[1];
        x = in[0];
        z = in[2];
        out[0] = z * m6 + (x * m0 + y * m3);
        {
            float m4 = m[4];
            float m1 = m[1];
            float m7 = m[7];
            out[1] = z * m7 + (x * m1 + y * m4);
        }
        {
            float m5 = m[5];
            float m2 = m[2];
            float m8 = m[8];
            out[2] = z * m8 + (x * m2 + y * m5);
        }
    }

}
/* Rotate a vector into the frame whose axes are m's rows, in place. */
static inline void rotate_vec_in_place(f32 *v, const f32 *m) {
    f32 z, y, x;
    x = v[0];
    y = v[1];
    z = v[2];
    v[0] = x * m[0] + y * m[1] + z * m[2];
    v[1] = x * m[3] + y * m[4] + z * m[5];
    v[2] = x * m[6] + y * m[7] + z * m[8];
}
/* The same scheduled transform as transform_vec_scheduled, but with the
   non-alias path written so each row re-reads the source vector
   (fn_801B97D8's two trailer points). */
static inline void transform_vec_scheduled_reload(float *out, const float *m, float *in) {
    if (out == in) {
        float m8, m5, m2, m7, m4, m1, m6, m3, m0;
        float z, y, x;
        m3 = m[3];
        m4 = m[4];
        m5 = m[5];
        m0 = m[0];
        m1 = m[1];
        m2 = m[2];
        m6 = m[6];
        m7 = m[7];
        m8 = m[8];
        x = in[0];
        y = in[1];
        z = in[2];
        out[0] = z * m6 + (x * m0 + y * m3);
        out[1] = z * m7 + (x * m1 + y * m4);
        out[2] = z * m8 + (x * m2 + y * m5);
    } else {
        out[0] = in[1] * m[3] + in[0] * m[0] + in[2] * m[6];
        out[1] = in[1] * m[4] + in[0] * m[1] + in[2] * m[7];
        out[2] = in[1] * m[5] + in[0] * m[2] + in[2] * m[8];
    }
}
/* Same source as the out-of-line fn_801E67B4 (out = in * 3x3 m, safe in place). */
static inline void Mtx3MultVec(void *argOut, void *argIn, void *argMtx) {
    Vec *out = (Vec *)argOut;
    float *in = (float *)argIn;
    const float *m = (const float *)argMtx;

    if (out == (Vec *)argIn) {
        float x, y, z;
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        m10 = m[3]; m11 = m[4]; m12 = m[5]; m00 = m[0]; m01 = m[1]; m02 = m[2]; m20 = m[6]; m21 = m[7]; m22 = m[8];
        x = in[0]; y = in[1]; z = in[2];
        out->x = z * m20 + (x * m00 + y * m10);
        out->y = z * m21 + (x * m01 + y * m11);
        out->z = z * m22 + (x * m02 + y * m12);
    } else {
        float m00, m10, m20, m01, m11, m21, m02, m12, m22;
        float y;
        m10 = m[3]; m00 = m[0]; m20 = m[6]; m11 = m[4]; m01 = m[1]; m21 = m[7]; m12 = m[5]; m02 = m[2]; m22 = m[8];
        out->x = in[2] * m20 + (in[0] * m00 + in[1] * m10);
        y = in[1];
        out->y = in[2] * m21 + (in[0] * m01 + y * m11);
        y = in[1];
        out->z = in[2] * m22 + (in[0] * m02 + y * m12);
    }
}
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma cplusplus on
extern "C" int fn_801E320C(int, int);
extern "C" void *fn_801E3004(int, int, int);
extern "C" void fn_801E3488(void *, void *);
extern "C" void fn_801E323C(void *);
extern "C" int fn_802C7A10(int);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" char lbl_803369A0[];
#pragma cplusplus on
#pragma scheduling on
extern "C" void fn_801B8CC0(float *arg0, int arg1, int *arg2, float *arg3, float arg4, float arg5) {
    void *p;
    int result;

    *(Vec *)arg0 = *(Vec *)arg3;
    result = fn_801E320C(arg1, (int)arg2);
    if (result != 0) {
        p = fn_801E3004(arg1, (int)arg2, -1);
        if (p != 0) {
            fn_801E3488(arg0, p);
            fn_801E323C(p);
        }
    } else {
        result = fn_802C7A10(arg1);
        fn_802E30C8(lbl_803369A0, (int)arg2, result);
    }
}
extern "C" void *fn_801B8D80(void) {
    /* Allocate and initialize a "trlr_car" object (0x2760 bytes), set its vtable
       (lbl_803369D0), clear/init fields at 0x2700/0x2710/0x272C/0x2730/0x2738/0x275C,
       assign the next global index (lbl_8055E774), store in the object table
       (lbl_80436D28), and cache a per-object value from fn_8017960C at 0x2754. */
    extern void *fn_801284F8(unsigned int, void *); /* allocate tagged memory */
    extern void fn_80182010(void *);                /* base object constructor/init */
    extern int fn_8017960C(int);                    /* lookup/init by object index */
    extern char lbl_803369C0[];                     /* alloc tag string "trlr_car" */
    extern char lbl_803369D0[];                     /* trlr_car vtable */
    extern void *lbl_80436D28[];                    /* global trlr_car object table */
    extern float lbl_80562750;                      /* 0.0f constant */
    extern int lbl_8055E774;                        /* next trlr_car object index */
    void *object;
    void *vtable;
    float zeroFloat;
    int zero;
    int objectIndex;

    object = fn_801284F8(0x2760, lbl_803369C0);
    if (object != 0) {
        fn_80182010(object);
        vtable = lbl_803369D0;
        zeroFloat = lbl_80562750;
        *(void **)object = vtable;
        zero = 0;
        *(int *)((char *)object + 0x2738) = zero;
        *(int *)((char *)object + 0x2710) = zero;
        *(float *)((char *)object + 0x272C) = zeroFloat;
        *(float *)((char *)object + 0x2730) = zeroFloat;
        objectIndex = lbl_8055E774;
        *(int *)((char *)object + 0x2700) = objectIndex;
        lbl_8055E774 = objectIndex + 1;
        lbl_80436D28[*(int *)((char *)object + 0x2700)] = object;
        *(int *)((char *)object + 0x2754) =
            fn_8017960C(*(int *)((char *)object + 0x2700));
        *(unsigned char *)((char *)object + 0x275C) = zero;
    }
    return object;
}
/* Per-frame update of the trailer car of player `playerIndex`.

   A "trlr_car" trails one of the eight players (its +0x2754).  This carries
   the offset between the trailer's point in the level (+0x273C) and the
   player's (+0x2748), less the body's own reference point (+0x30), into the
   trailer frame the player carries at +0x70, and hands what comes out - that
   frame, the world position in it, and the player's speed along the frame's
   facing axis - to the trailer itself at vtable+0x54 (fn_80189CB4 installs it
   as the trailer's pose, velocity and heading).  The spring at +0x2704 that
   pulls the trailer along is then re-aimed at the same point, with the longer
   range of lbl_80562760 while the trailer hangs from the player (+0x275D). */
extern "C" void fn_801B8E28(int playerIndex) {
    struct CarPose pose;
    f32 towedAnchor[3];
    f32 anchor[3];
    f32 offset[3];
    f32 anchorZ;
    f32 forwardSpeed;
    struct TrlrCar *car = (struct TrlrCar *)lbl_80436D28[playerIndex];
    ((void (*)(void *))fn_80189C64)(car); /* drop its pending flag and zero +0x26A8 */
    offset[0] = car->carPos.x - car->anchorPos.x;
    offset[1] = car->carPos.y - car->anchorPos.y;
    offset[2] = car->carPos.z - car->anchorPos.z;
    offset[0] -= car->localPoint.x;
    offset[1] -= car->localPoint.y;
    offset[2] -= car->localPoint.z;
    if (car->towed != 0) {
        offset[2] -= lbl_80562754; /* 2.0f */
    }
    pose.heading = -1;
    {
        struct PlayerCar *player = car->player;
        transform_vec_scheduled(pose.position, (const float *)player->trailerAxes, offset);
        pose.position[0] += player->trailerPos.x;
        pose.position[1] += player->trailerPos.y;
        pose.position[2] += player->trailerPos.z;
    }
    {
        Vec *axes = car->player->trailerAxes;
        pose.axes[0] = axes[0];
        pose.axes[1] = axes[1];
        pose.axes[2] = axes[2];
    }
    forwardSpeed = PSVECDotProduct(&car->player->velocity.x, &car->facing.x);
    pose.flag = 0;
    pose.velocity[0] = pose.axes[2].x * forwardSpeed;
    pose.velocity[1] = pose.axes[2].y * forwardSpeed;
    pose.velocity[2] = pose.axes[2].z * forwardSpeed;
    {
        struct PlayerCar *player = car->player;
        pose.heading = player->heading;
        ((struct TrlrCarVf *)car)->setPose(&pose, player);
    }
    car->spring.body = car;
    if (car->towed == 0) {
        anchor[0] = car->anchorPos.x + car->localPoint.x;
        anchor[1] = car->anchorPos.y + car->localPoint.y;
        anchorZ = car->anchorPos.z;
        anchor[2] = anchorZ + car->localPoint.z;
        fn_801AD148(&car->spring, anchor, car->player, lbl_80562758, lbl_8056275C, anchorZ);
    } else {
        towedAnchor[0] = car->anchorPos.x + car->localPoint.x;
        towedAnchor[1] = car->anchorPos.y + car->localPoint.y;
        anchorZ = car->anchorPos.z;
        towedAnchor[2] = anchorZ + car->localPoint.z;
        fn_801AD28C(&car->spring, towedAnchor, car->player, &car->carPos, lbl_80562758,
                    lbl_80562760, anchorZ);
    }
    fn_8018A08C(car); /* stamp it with the shared value of lbl_8055E3C8 */
}
#pragma cplusplus reset
extern "C" void fn_801B916C(void *arg0) {
    void **table;
    void *obj;
    int id;
    char *p;
    int *slots;
    int i;
    int sentinel;
    float frequency;
    if (((int *)__AXFXGetLfoSinTable_801769CC())[1] & 0x400) {
        p = (char *)arg0 + 4;
        table = lbl_80436D28;
        frequency = lbl_80562764;
        i = 0;
        sentinel = -1;
        while (i < *(int *)((char *)arg0 + 0x394)) {
            int index = *(int *)(p + 0x60);
            if (index < 0) goto no_object;
            if (index >= lbl_8055E774) goto no_object;
            obj = table[index];
            goto have_object;
        no_object:
            obj = 0;
        have_object:
            if (obj != 0) {
                id = *(int *)((char *)obj + 0x1EC);
                if (*(int *)(p + 0x74) == id)
                    *(int *)(p + 0x74) = sentinel;
                if (*(int *)(p + 0x8C) == id) *(int *)(p + 0x8C) = sentinel;
                slots = (int *)(p + 0x8C);
                if (slots[6] == id) slots[6] = sentinel;
                if (slots[12] == id) slots[12] = sentinel;
                *(int *)(p + 0x74) = id;
                *(float *)(p + 0x78) = frequency;
                {
                    float value0;
                    float value1;
                    value0 = *(float *)((char *)obj + 0x2690);
                    *(float *)(p + 0x7C) = value0;
                    value1 = *(float *)((char *)obj + 0x2694);
                    *(float *)(p + 0x80) = value1;
                    *(float *)(p + 0x84) = value0 - value1;
                }
                *(int *)(p + 0x88) = *(int *)((char *)obj + 0x268C);
            }
            p += 0xE0;
            i++;
        }
    }
}

/* A trailer car's destructor (its vtable lbl_803369D0, slot +0xC): the car is
   taken out of the trailer table at its own index (+0x2700) and the number of
   cars drops by one; the car object it is built on is destroyed without being
   freed here, and called as the deleting destructor (flag > 0) the car's own
   memory is freed too. */
#pragma scheduling invalid_target
#pragma cplusplus off
void *fn_801B9274(struct TrlrCar *car, s32 deleteFlag) {
#define trlrCars lbl_80436D28     /* the trailer cars, by index */
#define trlrCarCount lbl_8055E774 /* how many there are */
    if (car != 0) {
        s32 index = car->index;
        trlrCars[index] = 0;
        trlrCarCount--;
        fn_801836E0(car, 0); /* the car object underneath, not freed here */
        if (deleteFlag > 0) {
            fn_80128668(car); /* operator delete */
        }
    }
#undef trlrCars
#undef trlrCarCount
    return car;
}
#pragma cplusplus reset
#pragma scheduling on
extern float lbl_80562750;
extern float lbl_80562768;
extern float lbl_8056276C;
extern float lbl_80562770;
extern float lbl_80562774;
extern float lbl_80562778;
extern int lbl_8055A918;
extern "C" void fn_80182074(void *, int);
extern "C" void fn_801B8CC0(float *, int, int *, float *, float, float);
extern "C" void fn_802C77F0(int, float *);
#pragma dont_inline on
void fn_801B92F0(void *arg0, int arg1) {
    struct Work {
        float sp8[3]; float sp14[3]; float sp20[3]; float sp2c[3];
        float sp38[3]; float sp44[3]; float sp50[3]; float sp5c[3];
        float sp68[3]; char pad74[4]; float sp78[6]; float sp90[6];
    };
    union { double align; struct Work work; } frame;
    unsigned int bits = ((unsigned int *)__AXFXGetLfoSinTable_801769CC())[1];
    unsigned int *copySrc;
    unsigned int word2, word1, word0;
    float result, top, zero, param1, out0, out1, out2;

    *((unsigned char *)arg0 + 0x275d) = (bits >> 12) & 1;
    fn_80182074(arg0, arg1);
    frame.work.sp44[0] = lbl_80562750;
    frame.work.sp44[1] = lbl_80562750;
    frame.work.sp44[2] = lbl_80562768;
    ((unsigned int *)frame.work.sp50)[0] = ((unsigned int *)frame.work.sp44)[0];
    ((unsigned int *)frame.work.sp50)[1] = ((unsigned int *)frame.work.sp44)[1];
    ((unsigned int *)frame.work.sp50)[2] = ((unsigned int *)frame.work.sp44)[2];
    fn_801B8CC0(frame.work.sp5c, *(int *)((unsigned char *)arg0 + 0x59c),
        &lbl_8055A918, frame.work.sp50, lbl_80562750, lbl_80562750);
    *(float *)((unsigned char *)arg0 + 0x273c) = frame.work.sp5c[0];
    *(float *)((unsigned char *)arg0 + 0x2740) = frame.work.sp5c[1];
    *(float *)((unsigned char *)arg0 + 0x2744) = frame.work.sp5c[2];

    fn_802C77F0(*(int *)((unsigned char *)arg0 + 0x59c), frame.work.sp90);
    if (*((unsigned char *)arg0 + 0x275d)) {
        top = frame.work.sp90[5];
        result = top - lbl_8056276C;
        zero = lbl_80562750;
        frame.work.sp38[0] = zero;
        frame.work.sp38[1] = zero;
        frame.work.sp38[2] = result;
        *(float *)((unsigned char *)arg0 + 0x273c) = zero;
        *(float *)((unsigned char *)arg0 + 0x2740) = zero;
        *(float *)((unsigned char *)arg0 + 0x2744) = result;
    }

    fn_802C77F0(*(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x2754) + 0x59c),
        frame.work.sp78);
    if (*((unsigned char *)arg0 + 0x275d)) {
        top = frame.work.sp78[4];
        param1 = lbl_80562750;
        result = top - lbl_80562770;
        frame.work.sp2c[0] = param1;
        frame.work.sp2c[1] = param1;
        frame.work.sp2c[2] = result;
        copySrc = (unsigned int *)frame.work.sp2c;
    } else {
        top = frame.work.sp78[4];
        param1 = lbl_80562774;
        result = top - lbl_8056276C;
        frame.work.sp20[0] = lbl_80562750;
        frame.work.sp20[1] = param1;
        frame.work.sp20[2] = result;
        copySrc = (unsigned int *)frame.work.sp20;
    }
    word0 = copySrc[0];
    word1 = copySrc[1];
    word2 = copySrc[2];
    ((unsigned int *)frame.work.sp68)[0] = word0;
    ((unsigned int *)frame.work.sp8)[0] = word0;
    ((unsigned int *)frame.work.sp68)[1] = word1;
    ((unsigned int *)frame.work.sp8)[1] = word1;
    ((unsigned int *)frame.work.sp68)[2] = word2;
    ((unsigned int *)frame.work.sp8)[2] = word2;
    fn_801B8CC0(frame.work.sp14,
        *(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x2754) + 0x59c),
        &lbl_8055A918, frame.work.sp8, param1, result);
    out0 = frame.work.sp14[0];
    out1 = frame.work.sp14[1];
    out2 = frame.work.sp14[2];
    *(float *)((unsigned char *)arg0 + 0x2748) = out0;
    *(float *)((unsigned char *)arg0 + 0x274c) = out1;
    *(float *)((unsigned char *)arg0 + 0x2750) = out2;
    *(float *)((unsigned char *)arg0 + 0x274c) = out1 + lbl_80562778;
}
#pragma dont_inline reset
extern "C" void fn_801B949C(struct TrlrCar *car) {
    struct CarPose pose;
    f32 towedAnchor[3];
    f32 anchor[3];
    f32 offset[3];
    f32 anchorZ;
    f32 forwardSpeed;
    car->flag275C = 0;
    car->unk2758 = 0.0f;
    fn_8018381C(car); /* back to the pose saved at +0x274, with the motion cleared */
    offset[0] = car->carPos.x - car->anchorPos.x;
    offset[1] = car->carPos.y - car->anchorPos.y;
    offset[2] = car->carPos.z - car->anchorPos.z;
    offset[0] -= car->localPoint.x;
    offset[1] -= car->localPoint.y;
    offset[2] -= car->localPoint.z;
    if (car->towed != 0) {
        offset[2] -= lbl_80562754; /* 2.0f */
    }
    pose.heading = -1;
    {
        struct PlayerCar *player = car->player;
        transform_vec_scheduled(pose.position, (const float *)player->trailerAxes, offset);
        pose.position[0] += player->trailerPos.x;
        pose.position[1] += player->trailerPos.y;
        pose.position[2] += player->trailerPos.z;
    }
    {
        Vec *axes = car->player->trailerAxes;
        pose.axes[0] = axes[0];
        pose.axes[1] = axes[1];
        pose.axes[2] = axes[2];
    }
    forwardSpeed = PSVECDotProduct(&car->player->velocity.x, &car->facing.x);
    pose.flag = 0;
    pose.velocity[0] = pose.axes[2].x * forwardSpeed;
    pose.velocity[1] = pose.axes[2].y * forwardSpeed;
    pose.velocity[2] = pose.axes[2].z * forwardSpeed;
    {
        struct PlayerCar *player = car->player;
        pose.heading = player->heading;
        ((struct TrlrCarVf *)car)->setPose(&pose, player);
    }
    car->spring.body = car;
    if (car->towed == 0) {
        anchor[0] = car->anchorPos.x + car->localPoint.x;
        anchor[1] = car->anchorPos.y + car->localPoint.y;
        anchorZ = car->anchorPos.z;
        anchor[2] = anchorZ + car->localPoint.z;
        fn_801AD148(&car->spring, anchor, car->player, lbl_80562758, lbl_8056275C, anchorZ);
    } else {
        towedAnchor[0] = car->anchorPos.x + car->localPoint.x;
        towedAnchor[1] = car->anchorPos.y + car->localPoint.y;
        anchorZ = car->anchorPos.z;
        towedAnchor[2] = anchorZ + car->localPoint.z;
        fn_801AD28C(&car->spring, towedAnchor, car->player, &car->carPos, lbl_80562758,
                    lbl_80562760, anchorZ);
    }
}
#pragma cplusplus reset
#pragma cplusplus on
extern "C" void fn_801B97D8(struct TrlrCar *car) {
    struct { s32 kind; s32 player; s32 count; f32 p[6]; u8 pad[0x30]; } event;
    struct CarPose pose;
    f32 turn[3];
    f32 angularDelta[3];
    f32 localDelta[3];
    f32 speedDelta[3];
    f32 anchorWorld[3];
    f32 carWorld[3];
    f32 towedAnchor[3];
    f32 anchor[3];
    f32 offset[3];
    struct PlayerCar *player;
    f32 anchorZ;
    f32 value;
    f32 limit;
    f32 forwardSpeed;
    f32 rotX;
    f32 rotY;
    f32 rotZ;
    s32 over;

    player = car->player;
    angularDelta[0] = ((Vec *)((char *)car + 0x124))->x - ((Vec *)((char *)player + 0x124))->x;
    angularDelta[1] = ((Vec *)((char *)car + 0x124))->y - ((Vec *)((char *)player + 0x124))->y;
    angularDelta[2] = ((Vec *)((char *)car + 0x124))->z - ((Vec *)((char *)player + 0x124))->z;
    turn[1] = angularDelta[1] * lbl_8056277C;
    turn[2] = lbl_80562750;
    turn[0] = lbl_80562750;
    fn_8017B4AC(car, turn);

    if (car->towed == 0) {
        fn_8018ADA4(car, car->flag275C != 0 ? lbl_80562780 : lbl_80562750);
    } else {
        const f32 *m;
        player = car->player;
        localDelta[0] = player->position.x - ((Vec *)((char *)car + 0x60))->x;
        localDelta[1] = player->position.y - ((Vec *)((char *)car + 0x60))->y;
        localDelta[2] = player->position.z - ((Vec *)((char *)car + 0x60))->z;
        rotX = localDelta[0];
        rotY = localDelta[1];
        rotZ = localDelta[2];
        m = (const f32 *)((char *)car + 0x3C);
        localDelta[0] = rotX * m[0] + rotY * m[1] + rotZ * m[2];
        localDelta[1] = rotX * m[3] + rotY * m[4] + rotZ * m[5];
        localDelta[2] = rotX * m[6] + rotY * m[7] + rotZ * m[8];
        speedDelta[0] = ((Vec *)((char *)car + 0x118))->x - player->velocity.x;
        speedDelta[1] = ((Vec *)((char *)car + 0x118))->y - player->velocity.y;
        speedDelta[2] = ((Vec *)((char *)car + 0x118))->z - player->velocity.z;
        limit = PSVECDotProduct(speedDelta, &car->facing.x);
        value = lbl_80562784 * limit;
        limit = lbl_80562780;
        limit = limit < value ? limit : value;
        limit = limit > lbl_80562788 ? limit : lbl_80562788;
        value = lbl_8056278C * localDelta[0] - lbl_80562790 * *(const f32 *)((const char *)car + 0x128) - limit;
        limit = lbl_80562794;
        limit = limit < value ? limit : value;
        limit = limit > lbl_80562798 ? limit : lbl_80562798;
        fn_8018ADA4(car, limit);
    }

    if (car->flag275C == 0) {
        fn_801AD394(&car->spring);
        over = car->spring.stretch > car->spring.range;
        if (over != 0) {
            car->unk2758 += lbl_8056279C;
        }
        if (car->unk2758 > lbl_805627A0) {
            player = car->player;
            if (*(f32 *)((char *)player + 0x25D4) > lbl_805627A4) {
                car->unk2758 = lbl_80562750;
                fn_802E30C8(lbl_80336A30);
                offset[0] = car->carPos.x - car->anchorPos.x;
                offset[1] = car->carPos.y - car->anchorPos.y;
                offset[2] = car->carPos.z - car->anchorPos.z;
                offset[0] -= car->localPoint.x;
                offset[1] -= car->localPoint.y;
                offset[2] -= car->localPoint.z;
                if (car->towed != 0) {
                    offset[2] -= lbl_80562754;
                }
                pose.heading = -1;
                {
                    struct PlayerCar *p = car->player;
                    transform_vec_scheduled(pose.position, (const float *)p->trailerAxes, offset);
                    pose.position[0] += p->trailerPos.x;
                    pose.position[1] += p->trailerPos.y;
                    pose.position[2] += p->trailerPos.z;
                }
                {
                    Vec *axes = car->player->trailerAxes;
                    pose.axes[0] = axes[0];
                    pose.axes[1] = axes[1];
                    pose.axes[2] = axes[2];
                }
                forwardSpeed = PSVECDotProduct(&car->player->velocity.x, &car->facing.x);
                pose.flag = 0;
                pose.velocity[0] = pose.axes[2].x * forwardSpeed;
                pose.velocity[1] = pose.axes[2].y * forwardSpeed;
                pose.velocity[2] = pose.axes[2].z * forwardSpeed;
                {
                    struct PlayerCar *p = car->player;
                    pose.heading = p->heading;
                    ((struct TrlrCarVf *)car)->setPose(&pose, p);
                }
                car->spring.body = car;
                if (car->towed == 0) {
                    anchor[0] = car->anchorPos.x + car->localPoint.x;
                    anchor[1] = car->anchorPos.y + car->localPoint.y;
                    anchorZ = car->anchorPos.z;
                    anchor[2] = anchorZ + car->localPoint.z;
                    fn_801AD148(&car->spring, anchor, car->player, lbl_80562758, lbl_8056275C, anchorZ);
                } else {
                    towedAnchor[0] = car->anchorPos.x + car->localPoint.x;
                    towedAnchor[1] = car->anchorPos.y + car->localPoint.y;
                    anchorZ = car->anchorPos.z;
                    towedAnchor[2] = anchorZ + car->localPoint.z;
                    fn_801AD28C(&car->spring, towedAnchor, car->player, &car->carPos, lbl_80562758,
                                lbl_80562760, anchorZ);
                }
            }
        }
    }

    if (car->towed != 0) {
        transform_vec_scheduled_reload(anchorWorld, (const float *)((char *)car + 0x70), (float *)&car->anchorPos);
        anchorWorld[0] += ((Vec *)((char *)car + 0x94))->x;
        anchorWorld[1] += ((Vec *)((char *)car + 0x94))->y;
        anchorWorld[2] += ((Vec *)((char *)car + 0x94))->z;
        {
            struct PlayerCar *p = car->player;
            transform_vec_scheduled_reload(carWorld, (const float *)p->trailerAxes, (float *)&car->carPos);
            carWorld[0] += p->trailerPos.x;
            carWorld[1] += p->trailerPos.y;
            carWorld[2] += p->trailerPos.z;
        }
        event.kind = 1;
        event.player = *(s32 *)((char *)car->player + 0x1EC);
        event.count = 2;
        event.p[0] = anchorWorld[0];
        event.p[1] = anchorWorld[1];
        event.p[2] = anchorWorld[2];
        event.p[3] = carWorld[0];
        event.p[4] = carWorld[1];
        event.p[5] = carWorld[2];
        fn_801796CC(6, (long)&event, 0x54);
        ((void (*)(void *))fn_80189C64)(car);
        ((void (*)(void *))fn_80189C64)(car->player);
    }
}
