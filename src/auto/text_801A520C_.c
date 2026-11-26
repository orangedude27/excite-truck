void fn_8018956C(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct D_801A520C {
    void **vtable;
    void *pad0; void *pad1; void *pad2; void *pad3; void *pad4; void *pad5; void *pad7; void *pad8; void *pad9;
    int (*d5)(struct D_801A520C *);
} D_801A520C;

void fn_8018B0D8(void *, int, int, int *, int *, float);
int fn_8018BA54();
void fn_80189CB4(void);
void fn_8018AF00(void);
void fn_80183DF8(void);
void fn_8018381C(void);
extern float lbl_805623C8, lbl_805623EC, lbl_805623F4, lbl_805623F8, lbl_805623FC, lbl_80562400;
extern int lbl_8055E3C4;
extern char lbl_80333C20[];
extern int lbl_80435050[];
extern void fn_801A5AD0(void *, unsigned int, void *, void *);
extern void fn_802E30C8(const char *, ...);
int fn_801E9E30(void *, int *, int *);
void *fn_801B83A0(void);
void fn_80265D3C(void *);
void fn_801836E0(void *, int);
void fn_80128668(void *);
void fn_80182010(void);
void fn_80182074(void);
void fn_8018B09C(void);
int fn_80265D38(void *, int);
extern char lbl_80333C48[];
extern float PSVECDotProduct(float *, float *);
#pragma scheduling invalid_target
/* Constructor for the object whose vtable is lbl_80333C48: run the base constructor,
 * bind the subobject at +0x270C, then install the derived vtable and return self. */
void *fn_801A520C(void *self, void *subobject) {
    fn_80182010();
    *(void **)((char *)self + 0x270C) = subobject;
    *(void **)self = lbl_80333C48;
    return (void *)((char *)self + 0);
}

#pragma cplusplus on
struct Dummy_801A5258_v2 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2(void *, void *) {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
};
struct Dummy_801A5660 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
    virtual void d10() {}
    virtual void d11() {}
};
struct Dummy_801A5258 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2(void *, void *, void *) {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
    virtual void d10(void *) {}
};
#pragma cplusplus on
extern "C" void fn_801A5258(void *self, void *initData) {
    /* Reset this object's runtime state, bind/init its subobject, and clear transient timers. */
    class SubobjectVTable {
    public:
        virtual void f0();
        virtual void f2(void *owner, void *data);
        virtual void f1();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f9();
    };
    SubobjectVTable *subobj;
    float zero;

    fn_80182074();
    fn_80265D38(self, *(int *)((char *)self + 0x1EC));

    subobj = (SubobjectVTable *)*(void **)((char *)self + 0x270C);
    *(int *)((char *)self + 0x2708) = 0;
    *(unsigned char *)((char *)self + 0x2704) = 0;
    *(int *)((char *)self + 0x2700) = 0;
    subobj->f2(self, initData);

    subobj = (SubobjectVTable *)*(void **)((char *)self + 0x270C);
    subobj->f9();

    zero = lbl_805623C8;
    *(int *)((char *)self + 0x2714) = 1;
    *(int *)((char *)self + 0x2720) = 0;
    *(float *)((char *)self + 0x271C) = zero;
    *(float *)((char *)self + 0x2718) = zero;
    *(unsigned char *)((char *)self + 0x2710) = 0;
}
#pragma cplusplus on
/* Replace the subobject at +0x270C: detach the old one, attach the new one to this owner, and notify it. */
extern "C" void fn_801A5300(void *self, void **newSubobject) {
    class Obj {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2(void *);
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f9();
        virtual void f10();
    };
    Obj *oldSubobject = *(Obj **)((char *)self + 0x270C);
    if (oldSubobject != 0) {
        oldSubobject->f10();
    }
    *(void **)((char *)self + 0x270C) = (void *)newSubobject;
    if (newSubobject != 0) {
        ((Obj *)newSubobject)->f2(self);
        ((Obj *)*(void **)((char *)self + 0x270C))->f9();
    }
}
#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_801A538C(void *self, int shouldDelete) {
    /* Destructor for the object owning the subobject at +0x270C: reset its vtable,
       detach and destroy the subobject, clear the pointer, chain to the base
       destructor, and optionally delete this object. */
    class Obj {
    public:
        virtual void f0(int);
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
    };
    void *subObject;
    if (self != 0) {
        *(void **)self = &lbl_80333C48;
        fn_80265D3C(self);
        subObject = *(void **)((char *)self + 0x270C);
        ((Obj *)subObject)->f8();
        subObject = *(void **)((char *)self + 0x270C);
        if (subObject != 0)
            ((Obj *)subObject)->f0(1);
        *(void **)((char *)self + 0x270C) = 0;
        fn_801836E0(self, 0);
        if (shouldDelete > 0)
            fn_80128668(self);
    }
    return self;
}
#pragma scheduling on
#pragma pop
extern "C" void fn_801A5434(void *arg0) {
    /* Periodically validate this object's position and notify via v41 if stuck. */
    class Obj {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
        virtual void f20();
        virtual void f21();
        virtual void f22();
        virtual void f23();
        virtual void f24();
        virtual void f25();
        virtual void f26();
        virtual void f27();
        virtual void f28();
        virtual void f29();
        virtual void f30();
        virtual void f31();
        virtual void f32();
        virtual void f33();
        virtual void f34();
        virtual void f35();
        virtual void f36();
        virtual void f37();
        virtual void f38();
        virtual void f39();
        virtual void f40();
        virtual void f41(int);
    };
    int count;
    int position[3];
    int first;
    int second;
    void *obj;
    count = *(int *)((char *)arg0 + 0x2700);
    if (count == 0 &&
        ((lbl_8055E3C4 + *(int *)((char *)arg0 + 0x1EC)) & 0x1F) != 0)
        return;
    first = *(int *)((char *)arg0 + 0x60);
    second = *(int *)((char *)arg0 + 0x64);
    position[0] = first;
    position[1] = second;
    position[2] = *(int *)((char *)arg0 + 0x68);
    if (((int (*)(void *, int *, int))fn_801E9E30)((char *)arg0 + 0x6C, position, first) == 0) {
        *(int *)((char *)arg0 + 0x2700) = *(int *)((char *)arg0 + 0x2700) + 1;
    } else {
        *(int *)((char *)arg0 + 0x2700) = 0;
    }
    if (*(int *)((char *)arg0 + 0x2700) > 10) {
        obj = fn_801B83A0();
        ((Obj *)obj)->f41(*(int *)((char *)arg0 + 0x1EC));
        *(int *)((char *)arg0 + 0x2700) = 0;
    }
}
extern "C" void fn_80186DE4(void);
extern "C" void fn_801A5434(void *);
extern "C" void applyWallContactImpulse(void *, void *, float *);
extern "C" void fn_801A61B0(void *, void *, float);
extern unsigned char lbl_8055A518;
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801A54EC(void *arg0) {
    /* Updates an object: runs per-frame helpers, conditionally refreshes state from a subobject, and initializes 8 child entries. */
    struct Dummy11 {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
        virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    };
    struct Dummy7 {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
        virtual void *f5();
    };
    void *obj;
    void *ret;
    float vec[3];
    unsigned int i;
    char *base = (char *)arg0;
    fn_80186DE4();
    fn_801A5434(arg0);
    ((Dummy11 *)*(void **)(base + 0x270C))->f9();
    if (*(unsigned char *)(base + 0x2710) != 0 && lbl_8055A518 != 0) {
        ret = ((Dummy7 *)*(void **)(base + 0x270))->f5();
        fn_801A61B0(base + 0x2714, arg0, *(float *)((char *)*(void **)((char *)ret + 4) + 0x20));
    }
    vec[0] = lbl_805623C8;
    vec[1] = lbl_805623C8;
    vec[2] = lbl_805623C8;
    i = 0;
    obj = base + 0x2724;
    do {
        applyWallContactImpulse(obj, arg0, vec);
        i++;
        obj = (char *)obj + 0x24;
    } while (i < 8);
}
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_801A55BC(void *arg0) {
    class Obj {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6();
        virtual void f7();
        virtual void f8(int);
    };
    Obj *obj;
    fn_8018381C();
    *(int *)((char *)arg0 + 0x2744) = 0;
    *(int *)((char *)arg0 + 0x2768) = 0;
    *(int *)((char *)arg0 + 0x278C) = 0;
    *(int *)((char *)arg0 + 0x27B0) = 0;
    *(int *)((char *)arg0 + 0x27D4) = 0;
    *(int *)((char *)arg0 + 0x27F8) = 0;
    *(int *)((char *)arg0 + 0x281C) = 0;
    *(int *)((char *)arg0 + 0x2840) = 0;
    *(int *)((char *)arg0 + 0x2714) = 1;
    obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    *(int *)((char *)arg0 + 0x2720) = 0;
    *(float *)((char *)arg0 + 0x271C) = lbl_805623C8;
    *(float *)((char *)arg0 + 0x2718) = lbl_805623C8;
    obj->f8(0);
    obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    obj->f7();
    *(int *)((char *)arg0 + 0x2700) = 0;
    *(unsigned char *)((char *)arg0 + 0x2704) = 0;
}
#pragma pop
extern "C" void fn_801A5660(void *wrapper) {
    /* Tick the shared state (fn_80183DF8), then forward virtual d11 to the object held at +0x270C of the wrapper. */
    fn_80183DF8();
    ((Dummy_801A5660 *)*(void **)((char *)wrapper + 0x270C))->d11();
}

extern float lbl_805623CC, lbl_805623D0, lbl_805623D4, lbl_805623D8, lbl_805623DC, lbl_805623E0, lbl_805623E4, lbl_805623E8, lbl_805623F0;
extern int lbl_80558DC4[]; /* MSL __float_epsilon: FLT_EPSILON */
extern double __fabs(double);
#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" void fn_8017B3A8(void *, float *, float *);
extern "C" float fn_801A5A7C(void *, float *, float *);
#pragma opt_dead_assignments off
extern "C" void applyWallContactImpulse(void *contactPtr, void *carPtr, float *pointVelocity) {
    /* Apply one frame of a spring-wall contact impulse.  contactPtr is one of the
       car's eight WallContact slots (filled by fn_801A5AD0), carPtr is the car and
       pointVelocity its velocity at the contact point; the slot's wall normal
       drives a separation/restitution impulse added to pointVelocity and sent as
       a force at a point to fn_8017B3A8.  The contact timer is advanced and the
       slot freed once the eased-in speed passes its target. */
    typedef struct { float v[3]; } Vec3;
#define kZero            0.0f
#define kOne             1.0f
#define kFrameTime       lbl_805623D0      /* one frame, shared constant */
#define kSecondsPerFrame 0.016683366f      /* the same constant as a literal */
#define kHalf            0.5f
#define kRestitution     6.6666665f
#define kMaxVertForce    0.44444445f
#define kVertScale       0.1f
#define kMaxForce        17.777779f
#define kForceScale      0.8f
#define kReleaseDelay    0.2f
#define kHalfPi          1.5707964f
#define kEpsilon         (*(float *)lbl_80558DC4)
    float relVel[3], futurePoint[3], force[3], impulse[3], forcePoint[3];
    Vec3 direction;
    float normalSpeed, blend, movement, temp, push, limit, bounce, impulseScale, mass;
    double absPush;
    float planeOffset;
    int engaged, outsidePlane;
    char *slot = (char *)contactPtr;
    char *car = (char *)carPtr;
    if (*(void **)(slot + 0x20) != 0) {
        relVel[0] = pointVelocity[0] + *(float *)(car + 0x118);
        relVel[1] = pointVelocity[1] + *(float *)(car + 0x11c);
        relVel[2] = pointVelocity[2] + *(float *)(car + 0x120);
        normalSpeed = PSVECDotProduct(relVel, (float *)contactPtr);
        blend = *(float *)(slot + 0x18) / *(float *)(slot + 0x1c);
        blend = kOne < blend ? kOne : blend;
        blend = blend > kZero ? blend : kZero;
        movement = *(float *)(slot + 0xc) + blend * (*(float *)(slot + 0x10) - *(float *)(slot + 0xc));
        futurePoint[0] = *(float *)(car + 0x60) + relVel[0] * kFrameTime;
        futurePoint[1] = *(float *)(car + 0x64) + relVel[1] * kFrameTime;
        futurePoint[2] = *(float *)(car + 0x68) + relVel[2] * kFrameTime;
        temp = fn_801A5A7C(contactPtr, futurePoint, (float *)((char *)*(void **)((char *)*(void **)(slot + 0x20) + 0xc) + 0x24));
        planeOffset = *(float *)(slot + 0x14);
        outsidePlane = 0;
        if (kZero < planeOffset) {
            outsidePlane = 1;
        }
        engaged = *(float *)(slot + 0x18) < *(float *)(slot + 0x1c);
        if (engaged) {
            push = movement - normalSpeed;
            push = kZero > push ? kZero : push;
            bounce = kZero;
            if (normalSpeed < kZero) {
                blend = (temp - kHalf) / -kHalf;
                blend = kOne < blend ? kOne : blend;
                blend = blend > kZero ? blend : kZero;
                push = kZero;
                bounce = push + blend * ((kRestitution + -normalSpeed) - push);
            }
            impulseScale = bounce + push;
            impulse[0] = *(float *)(slot + 0) * impulseScale;
            impulse[1] = *(float *)(slot + 4) * impulseScale;
            impulse[2] = *(float *)(slot + 8) * impulseScale;
            pointVelocity[0] += impulse[0]; pointVelocity[1] += impulse[1]; pointVelocity[2] += impulse[2];
            blend = *(float *)(car + 0xd4) / kSecondsPerFrame;
            force[0] = impulse[0] * blend; force[1] = impulse[1] * blend; force[2] = impulse[2] * blend;
            limit = kMaxVertForce;
            if (relVel[1] > limit && *(int *)(car + 0x2620) == 0) {
                temp = kVertScale * relVel[1];
                mass = *(float *)(car + 0xd4);
                limit = limit < temp ? limit : temp;
                force[1] = -limit * (mass / kFrameTime);
            }
            push += bounce;
            absPush = __fabs(push);
            temp = (float)absPush;
            direction = *(Vec3 *)(car + 0x54);
            direction.v[1] = kZero;
            if (!(temp <= kEpsilon) && PSVECDotProduct(direction.v, (float *)contactPtr) < kZero && (float)__fabs(*(float *)(car + 0x128)) < kHalfPi) {
                blend = kMaxForce / push;
                blend = kOne < blend ? kOne : blend;
                blend = kForceScale * blend;
                forcePoint[0] = *(float *)(car + 0x60) + direction.v[0] * blend;
                forcePoint[1] = *(float *)(car + 0x64) + direction.v[1] * blend;
                forcePoint[2] = *(float *)(car + 0x68) + direction.v[2] * blend;
            } else {
                forcePoint[0] = *(float *)(car + 0x60);
                forcePoint[1] = *(float *)(car + 0x64);
                forcePoint[2] = *(float *)(car + 0x68);
            }
            fn_8017B3A8(carPtr, force, forcePoint);
            *(float *)(car + 0x26b4) = kZero;
            *(float *)(car + 0x26b8) = kZero;
            *(float *)(car + 0x26bc) = kZero;
        }
        movement = *(float *)(slot + 0x18) + kFrameTime;
        *(float *)(slot + 0x18) = movement;
        if (movement > kReleaseDelay + *(float *)(slot + 0x1c) && !engaged)
            *(void **)(slot + 0x20) = 0;
    }
#undef kZero
#undef kOne
#undef kFrameTime
#undef kSecondsPerFrame
#undef kHalf
#undef kRestitution
#undef kMaxVertForce
#undef kVertScale
#undef kMaxForce
#undef kForceScale
#undef kReleaseDelay
#undef kHalfPi
#undef kEpsilon
}
#pragma opt_dead_assignments reset
#pragma pop

/* Signed distance of a world point from a contact plane: dot(normal, point - origin).
   `contact` is a contact record whose first three floats are its world-space normal
   (see fn_801A5AD0, which fills it at +0x00 and stores this result at +0x14). */
extern "C" float fn_801A5A7C(void * __restrict contact, float * __restrict point, float * __restrict origin) {
    float diff[3];
    diff[0] = point[0] - origin[0];
    diff[1] = point[1] - origin[1];
    diff[2] = point[2] - origin[2];
    return PSVECDotProduct((float *)contact, diff);
}

/* One of the eight spring-wall contacts a car carries from +0x2724, 0x24 apart.
 * fn_801A5C4C() picks the slot a wall may use, fn_801A5AD0() fills it in and
 * applyWallContactImpulse() turns it into an impulse every frame until it is released. */
typedef struct WallContact {
    float normal[3];           /* 0x00 wall normal; the impulse pushes along it */
    float startSpeed;          /* 0x0C speed closing on the normal when claimed */
    float targetSpeed;         /* 0x10 speed the impulse eases up to */
    float planeDistance;       /* 0x14 last frame's contact point, from the plane */
    float elapsed;             /* 0x18 time the contact has been held */
    float duration;            /* 0x1C how long it is eased in (0.2) */
    volatile unsigned int wall;/* 0x20 wall holding the slot; 0 when it is free */
} WallContact;

/* A wall the car can hit; only the plane record behind +0x0C is read here. */
typedef struct WallRecord {
    char pad0[0xC];
    struct WallPlane *plane;   /* 0x0C the wall's plane */
} WallRecord;

typedef struct WallPlane {
    float normal[3];           /* 0x00 outward normal */
    char pad0C[0x18];
    float origin[3];           /* 0x24 one point on the wall */
} WallPlane;

/* The part of the car (or any 'PCAR'/'ACAR' vehicle) a contact looks at. */
typedef struct VehicleState {
    char pad0[0x60];
    float position[3];         /* 0x60 world position */
    char pad6C[0x118 - 0x6C];
    float velocity[3];         /* 0x118 world velocity */
} VehicleState;

#pragma push
#pragma dont_inline on
/* Claim a spring-wall contact slot for the wall in `wallKey`, or restart the one
 * that wall already holds.  fn_801A5C4C() picks the slot out of the car's eight
 * at +0x2724 and hands it over with the wall a collision was reported for, the
 * car itself and `heldContact`, a contact the car already has (0 when it has none).
 *
 * A free slot takes the wall's normal -- flipped when it points away from the
 * normal of `heldContact`, so two contacts on one car cannot push against each
 * other -- records how far the car's contact point stood outside the wall plane
 * one frame ago, and turns the speed the car is closing on the normal into the
 * impulse speed the contact eases up to over WallContact.duration.  A slot the
 * same wall already owns only has its contact timer restarted; a slot held by
 * another wall is left alone. */
extern "C" void fn_801A5AD0(void *contactPtr, unsigned int wallKey, void *carPtr, void *heldPtr) {
#define slot        ((WallContact *)contactPtr)
#define wallRec     ((WallRecord *)wallKey)
#define heldContact ((WallContact *)heldPtr)
#define kZero       lbl_805623C8 /* 0.0f */
#define kSpeedMax   lbl_805623EC /* 17.7778: most of a closing speed that counts */
#define kSpeedMin   lbl_80562400 /* 0.888889: least of it that counts */
#define kSpeedScale lbl_805623F4 /* 0.2: impulse speed per unit of closing speed, and the ease-in time */
#define kFrameLag   lbl_805623F8 /* -0.0166834: one frame back, to where the car was */
#define kFlip       lbl_805623FC /* -1.0f */
    float lagPoint[3];
    float *planeNormal;
    float speedScale;
    float closingSpeed;
    float frameLag;
    float speed;
    float dot;
    VehicleState *car = (VehicleState *)carPtr;

    if (slot->wall == 0) {
        planeNormal = wallRec->plane->normal;
        frameLag = kFrameLag;
        slot->normal[0] = planeNormal[0];
        slot->normal[1] = planeNormal[1];
        slot->normal[2] = planeNormal[2];

        lagPoint[0] = car->position[0] + car->velocity[0] * frameLag;
        lagPoint[1] = car->position[1] + car->velocity[1] * frameLag;
        lagPoint[2] = car->position[2] + car->velocity[2] * frameLag;

        if (heldContact) {
            dot = PSVECDotProduct(heldContact->normal, (float *)contactPtr);
            if (dot < kZero) {
                float normalX = slot->normal[0];
                float flip = kFlip;
                slot->normal[0] = normalX * flip;
                slot->normal[1] *= flip;
                slot->normal[2] *= flip;
            }
        }

        slot->planeDistance = fn_801A5A7C(contactPtr, lagPoint, wallRec->plane->origin);

        dot = PSVECDotProduct(car->velocity, (float *)contactPtr);
        speed = kSpeedMax;
        closingSpeed = -(float)(double)dot;
        slot->startSpeed = dot;
        speed = (speed < closingSpeed) ? speed : closingSpeed;
        speed = (speed > kSpeedMin) ? speed : kSpeedMin;

        speedScale = kSpeedScale;
        frameLag = kZero;
        speed = speedScale * speed;
        slot->duration = speedScale;
        slot->elapsed = frameLag;
        slot->targetSpeed = speed;
        slot->wall = wallKey;
    } else if (slot->wall == wallKey) {
        slot->elapsed = kZero;
    }
#undef slot
#undef wallRec
#undef heldContact
#undef kZero
#undef kSpeedMax
#undef kSpeedMin
#undef kSpeedScale
#undef kFrameLag
#undef kFlip
}
#pragma opt_dead_assignments off
extern "C" void fn_801A5C4C(void *arg0, unsigned int key) {
    float values[3];
    int count;
    int i;
    int val;
    void *slot = (char *)arg0 + 0x2724;
    void *candidate = 0;
    void *other = 0;
    void *record = arg0;

    for (count = 4, i = 0; count > 0; count--, i++) {
        val = *(int *)((char *)record + 0x2744);
        if (val != 0 && (unsigned int)val != key)
            other = slot;
        if (candidate == 0 || *(unsigned int *)((char *)candidate + 0x20) != key) {
            if ((unsigned int)val == key || val == 0)
                candidate = slot;
        }

        val = *(int *)((char *)record + 0x2768);
        slot = (char *)slot + 0x24;
        if (val != 0 && (unsigned int)val != key)
            other = slot;
        if (candidate == 0 || *(unsigned int *)((char *)candidate + 0x20) != key) {
            if ((unsigned int)val == key || val == 0)
                candidate = slot;
        }

        record = (char *)record + 0x48;
        slot = (char *)slot + 0x24;
    }

    if (candidate != 0) {
        fn_801A5AD0(candidate, key, arg0, other);
    } else {
        fn_802E30C8(lbl_80333C20, lbl_8055E3C4);
    }

    values[0] = lbl_805623C8;
    values[1] = lbl_805623C8;
    values[2] = lbl_805623C8;
    {
        class Obj {
        public:
            virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
            virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
            virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
            virtual void f12(float *, float *, int, int);
        };
        Obj *obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
        obj->f12(values, values, 0x3EA, 0);
    }
}
#pragma opt_dead_assignments reset
/* Forward action (vslot 12) to the subobject at +0x270C; on mode 0x6D reset the local timer/state fields. */
extern "C" void fn_801A5D80(void *self, int arg1, int arg2, int mode, int arg4) {
    class Obj {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(int, int, int, int);
    };
    float zero;
    Obj *subobj;
    fn_8018B09C();
    subobj = (Obj *)*(void **)((char *)self + 0x270C);
    subobj->f12(arg1, arg2, mode, arg4);
    if (mode == 0x6D) {
        zero = lbl_805623C8;
        *(int *)((char *)self + 0x2714) = 1;
        *(int *)((char *)self + 0x2720) = 0;
        *(float *)((char *)self + 0x271C) = zero;
        *(float *)((char *)self + 0x2718) = zero;
    }
}

#pragma cplusplus on
extern "C" void fn_801A5E0C(void *self, int param1, int param2, int mode, int param4) {
    /* Forward action to the subobject at +0x270C (vslot 13); on mode 0x6D reset timer/state. */
    class Subobject {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12();
        virtual void f13(int, int, int, int);
    };
    float zero;
    Subobject *subobj;
    fn_8018956C();
    subobj = (Subobject *)*(void **)((char *)self + 0x270C);
    subobj->f13(param1, param2, mode, param4);
    if (mode == 0x6D) {
        zero = lbl_805623C8;
        *(int *)((char *)self + 0x2714) = 1;
        *(int *)((char *)self + 0x2720) = 0;
        *(float *)((char *)self + 0x271C) = zero;
        *(float *)((char *)self + 0x2718) = zero;
    }
}
struct Dummy_801A5E98 {
    virtual void h0() {}
    virtual void h1() {}
    virtual void h2() {}
    virtual void h3() {}
    virtual void h4() {}
    virtual void h5() {}
    virtual void h6() {}
    virtual void h7() {}
    virtual void h8() {}
    virtual void h9() {}
    virtual void h10() {}
    virtual void h11() {}
    virtual void h12() {}
    virtual void h13() {}
    virtual void h14() {}
};
#pragma cplusplus on
extern "C" void fn_801A5E98(void *wrapper) {
    /* Call the shared pre-update hook, then forward h14 to the subobject held at +0x270C of the wrapper. */
    fn_8018AF00();
    ((Dummy_801A5E98 *)*(void **)((char *)wrapper + 0x270C))->h14();
}
#pragma cplusplus off

#pragma cplusplus on
struct Dummy_801A5ED8 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
};
  struct Dummy_801A6088 {
      virtual void g0();
      virtual void g1();
      virtual void g2();
      virtual int g3();
      virtual void g4();
  };
  #pragma cplusplus off
  
#pragma cplusplus on
extern "C" void fn_801A5ED8(void *arg0) {
    /* Resets the subobject at +0x270C: marks active, invokes vtable slot f15,
     * and clears the eight per-slot state words from +0x2744 onward. */
    fn_80189CB4();
    void *obj = *(void **)((char *)arg0 + 0x270C);
    *(unsigned char *)((char *)arg0 + 0x2704) = 1;
    ((Dummy_801A5ED8 *)obj)->f15();
    *(int *)((char *)arg0 + 0x2744) = 0;
    *(int *)((char *)arg0 + 0x2768) = 0;
    *(int *)((char *)arg0 + 0x278C) = 0;
    *(int *)((char *)arg0 + 0x27B0) = 0;
    *(int *)((char *)arg0 + 0x27D4) = 0;
    *(int *)((char *)arg0 + 0x27F8) = 0;
    *(int *)((char *)arg0 + 0x281C) = 0;
    *(int *)((char *)arg0 + 0x2840) = 0;
}
#pragma cplusplus off
  
#pragma cplusplus on
extern "C" int fn_801A5F44(void *owner, int index) {
    /* Resolves a 0x44-biased index through the subobject held at +0x270C and returns the result, also biased by 0x44. */
    class VTable {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void *f4(int);
    };
    VTable *obj = (VTable *)*(void **)((char *)owner + 0x270C);
    return (int)((char *)obj->f4(index + 0x44) + 0x44);
}
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void fn_801A5F7C(void *arg0, int inX, int inY, int *outX, int *outY, float scale) {
    /* Query a base offset and a child object's offset, returning their sums in outX/outY. */
    class Obj {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5(int, int, int *, int *, float);
    };
    int baseX, baseY, childX, childY;
    Obj *obj;
    fn_8018B0D8(arg0, inX, inY, &baseX, &baseY, scale);
    obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    obj->f5(inX + baseX, inY + baseY, &childX, &childY, scale);
    *outX = baseX + childX;
    *outY = baseY + childY;
}
#pragma use_lmw_stmw on
extern "C" int fn_801A6024(void *arg0, int arg1) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual int v6(int);
    };
    /* Computes the size contributed beyond arg1 by combining fn_8018BA54()
     * with a query on the child object at +0x270C (vtable slot 0x20). */
    int base = arg1 + fn_8018BA54();
    Obj *obj = (Obj *)*(void **)((char *)arg0 + 0x270C);
    base += obj->v6(base);
    return base - arg1;
}
#pragma cplusplus off
  void fn_80188E2C(void);
  int fn_8018BA54(void);
  void fn_8018956C(void);
#pragma cplusplus on
extern "C" void fn_801A6088(void *owner, int indexOffset) {
    /* Stores a queried value from the child object at +0x270C into the indexed slot at +0x2C0. */
    void *child;
    int slotBase;

    fn_80188E2C();
    child = *(void **)((char *)owner + 0x270C);
    slotBase = indexOffset + *(int *)((char *)owner + 8);
    *(int *)((char *)slotBase + 0x2C0) = ((Dummy_801A6088 *)child)->g3();
}
#pragma cplusplus off
#pragma scheduling invalid_target
#pragma push
#pragma cplusplus on
extern float lbl_80562404;
extern float lbl_80562408;
extern float lbl_8056240C;
extern void fn_8017B3A8(void *, float *, float *);
#pragma scheduling invalid_target
/* Kick the vehicle straight up: adds a world-+Y force of controller->+4 to the
 * rigid body's force/torque accumulators (fn_8017B3A8).  When the body's +0x124
 * angle is past 15 degrees the force is applied at the body's centre pushed
 * ahead along its +0x54 velocity by 2*(-0.1 - velocity.y), never backwards, so
 * a kick lands further ahead the faster the vehicle is falling and pitches it
 * instead of only lifting it. */
extern "C" void fn_801A60E0(void *controller, void *body) {
    float point[3];
    float force[3];
    float upForce;
    float wanted;
    float ahead;
    char *b = (char *)body;

    if (*(float *)(b + 0x124) > 0.2617994f /* 15 degrees */) {
        wanted = 2.0f * (-0.1f - *(float *)(b + 0x58));
        ahead = 0.0f;
        if (ahead > wanted) {
            ahead = ahead;
        } else {
            ahead = wanted;
        }
        point[0] = *(float *)(b + 0x60) + *(float *)(b + 0x54) * ahead;
        point[1] = *(float *)(b + 0x64) + *(float *)(b + 0x58) * ahead;
        point[2] = *(float *)(b + 0x68) + *(float *)(b + 0x5C) * ahead;
    } else {
        point[0] = *(float *)(b + 0x60);
        point[1] = *(float *)(b + 0x64);
        point[2] = *(float *)(b + 0x68);
    }
    upForce = *(float *)((char *)controller + 4);
    force[0] = 0.0f;
    force[1] = upForce;
    force[2] = 0.0f;
    fn_8017B3A8(body, force, point);
}
#pragma scheduling on
extern void fn_801A60E0(void *, void *);
extern float lbl_8055E3C8, lbl_805623C8, lbl_805623CC, lbl_805623D4, lbl_80562410, lbl_80562414;
#pragma cplusplus on
extern "C" void fn_801A61B0(void *arg0, void *arg1, float arg2)
{
  int active;
  float zero;
  int counter;
  float limit;
  float bound;
  float ratio;
  float value;
  float tmp;
  float scale;
  if (*((int *) arg0))
  {
    active = 1;
    if ((((!(*((unsigned char *) (((char *) arg1) + 0x23CC)))) && (!(*((unsigned char *) (((char *) arg1) + 0x2440))))) && (*((unsigned char *) (((char *) arg1) + 0x24B4)))) && (*((unsigned char *) (((char *) arg1) + 0x2528))))
    {
      value = *((float *) (((char *) arg1) + 0x25D4));
      ratio = value / arg2;
      if (ratio > lbl_80562410)
      {
        limit = *((float *) (((char *) arg1) + 0x11C));
        if ((limit > lbl_805623C8) && (limit < (lbl_805623D4 * value)))
        {
          counter = (*((int *) (((char *) arg0) + 0xC))) + 1;
          *((int *) (((char *) arg0) + 0xC)) = counter;
          if (counter > 4)
          {
            bound = lbl_805623CC;
            value = bound - ratio;
            *((float *) (((char *) arg0) + 8)) = lbl_8055E3C8;
            bound = (bound < value) ? (value) : (bound);
            bound = (bound > lbl_805623C8) ? (lbl_805623C8) : (bound);
            tmp = *((float *) (((char *) arg1) + 0xD4));
            scale = lbl_80562414;
            tmp = bound * tmp;
            *((int *) arg0) = 0;
            *((float *) (((char *) arg0) + 4)) = tmp * scale;
            while ((--(*((int *) (((char *) arg0) + 0xC)))) != 0)
            {
              fn_801A60E0(arg0, arg1);
            }

          }
          else
          {
            active = 0;
          }
        }
      }
    }
    if (active)
    {
      *((int *) (((char *) arg0) + 0xC)) = 0;
    }
  }
  else
  {
    fn_801A60E0(arg0, arg1);
    if (((*((int *) (((char *) arg1) + 0x2620))) > 0) && ((lbl_8055E3C8 - (*((float *) (((char *) arg0) + 8)))) > lbl_805623CC))
    {
      zero = lbl_805623C8;
      *((int *) arg0) = 1;
      *((int *) (((char *) arg0) + 0xC)) = 0;
      *((float *) (((char *) arg0) + 8)) = zero;
      *((float *) (((char *) arg0) + 4)) = zero;
    }
  }
}
