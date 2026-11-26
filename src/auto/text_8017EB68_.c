// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#define FC48 (*(const float *)&lbl_80561C48)
#define FC4C (*(const float *)&lbl_80561C4C)
#define FC7C (*(const float *)&lbl_80561C7C)
#define FC80 (*(const float *)&lbl_80561C80)
#define FC84 (*(const float *)&lbl_80561C84)
#define FC88 (*(const float *)&lbl_80561C88)
#define FC8C (*(const float *)&lbl_80561C8C)
#define FC90 (*(const float *)&lbl_80561C90)
#define FC94 (*(const float *)&lbl_80561C94)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))

extern float lbl_80561C48;
extern float lbl_80561C4C;
extern float lbl_80561C7C;
extern float lbl_80561C80;
extern float lbl_80561C84;
extern float lbl_80561C88;
extern float lbl_80561C8C;
extern float lbl_80561C90;
extern float lbl_80561C94;
extern float lbl_8055A330;
extern float lbl_8055A334;
extern float lbl_8055A338;
extern float lbl_8055A33C;
extern float lbl_8055A340;
extern float lbl_8055A344;
extern int lbl_802F9530[];
extern int lbl_802F9540[];
extern char lbl_80331F80[];
extern char lbl_80331F90[];
extern char lbl_80331F9C[];
extern char lbl_80331FA8[];
extern char lbl_80331FB4[];
extern char lbl_80331FC0[];
extern char lbl_80331FCC[];
extern char lbl_80331FD8[];
extern char lbl_80331FE4[];
extern char lbl_80331FF0[];
extern char lbl_80331FFC[];
extern char lbl_80332008[];
extern char lbl_80332020[];
extern char lbl_80332030[];
extern char lbl_8033203C[];
extern char lbl_80332050[];
extern char lbl_80332064[];
extern char lbl_80332078[];
extern char lbl_8033208C[];
extern char lbl_8033209C[];
extern char lbl_803320B0[];
extern char lbl_803320BC[];
extern char lbl_803320C8[];
extern char lbl_803320D4[];
extern char lbl_803320E0[];
extern char lbl_803320EC[];
extern char lbl_803320F8[];
extern char lbl_80332104[];
extern char lbl_80332110[];
extern char lbl_8033211C[];
extern char lbl_8033212C[];
extern char lbl_80332138[];
extern char lbl_80332144[];
extern char lbl_80332150[];
extern char lbl_8033215C[];
extern char lbl_80332168[];
extern char lbl_80332178[];
extern char lbl_80332184[];
extern char lbl_80332194[];
extern char lbl_803321A0[];
extern char lbl_803321AC[];
extern char lbl_803321B8[];
extern char lbl_803321C4[];
extern char lbl_803321D0[];
extern char lbl_803321E4[];
extern char lbl_803321F0[];
extern char lbl_80332200[];
extern char lbl_80332210[];
extern char lbl_80332220[];
extern char lbl_80332238[];
extern char lbl_80332248[];
extern char lbl_80332258[];
extern char lbl_80332270[];
__declspec(section ".sdata") extern const char lbl_8055A350[];
__declspec(section ".sdata") extern const char lbl_8055A358[];
__declspec(section ".sdata") extern const char lbl_8055A360[];
__declspec(section ".sdata") extern const char lbl_8055A368[];
__declspec(section ".sdata") extern const char lbl_8055A370[];
__declspec(section ".sdata") extern const char lbl_8055A378[];
__declspec(section ".sdata") extern const char lbl_8055A380[];
__declspec(section ".sdata") extern const char lbl_8055A388[];
__declspec(section ".sdata") extern const char lbl_8055A390[];
__declspec(section ".sdata") extern const char lbl_8055A398[];
extern void LoadFloatOption(int, const char *, void *);
extern void fn_801333E8(int, const char *, void *);
extern void fn_801A7974(void *, const char *, int);
extern void fn_801A7DFC(int, int, int);
extern void fn_801A9110(void *, const char *);
extern int sprintf(char *, const char *, ...);
/* One of a driver's 42 input bindings (object +0x6C).  fn_8017F718 fills one
 * from the player's options by control name ("steer_left", "throttle", ...);
 * the input layer (fn_801A7F98 and friends) reads it back: `type` says how the
 * value is produced, `value` selects a 0x64-byte control record and `axis` the
 * axis, key code or bit mask within it. */
struct Di718Slot {
    s32 type;   /* 0x00 1 key, 2 analog axis, 3 button byte, 4 button mask,
                 *      5 special axis, 6 special button (0 = unbound) */
    s32 value;  /* 0x04 control record holding the device's state */
    s32 axis;   /* 0x08 axis / key code / bit mask within that record */
    u8 inUse;   /* 0x0C rising-edge latch (fn_801A8E68); cleared when rebound */
    u8 pad0D[3];
};

/* The control values the bindings drive (object +0x0C), written every frame by
 * PhysDriverUpdate (fn_8017ED00) and read by the physics driver. */
enum DriverControl {
    CTRL_STEER,      /* 0 steering, -1..1 */
    CTRL_STEER2,     /* 1 the second steering axis (steer2_*) */
    CTRL_BRAKE,      /* 2 */
    CTRL_BRAKE2,     /* 3 the second brake pedal */
    CTRL_CLUTCH,     /* 4 ramps up while the clutch is held */
    CTRL_THROTTLE,   /* 5 */
    CTRL_THROTTLE2,  /* 6 the second throttle */
    CTRL_E_BRAKE     /* 7 the hand brake axis */
};

/* The response levels fn_8017F718 registers with the level system (object
 * +0x02C) under those names, so the options can tune them per driver. */
enum DriverLevel {
    LEVEL_STEER_DEAD_SPOT,    /* "steer_dead_spot" */
    LEVEL_STEER_OVERSHOOT,    /* "steer_overshoot" */
    LEVEL_STEER_SPEED,        /* "steer_speed" */
    LEVEL_THROTTLE_DEAD_SPOT, /* "throttle_dead_spot" */
    LEVEL_THROTTLE_OVERSHOOT, /* "throttle_overshoot" */
    LEVEL_THROTTLE_SPEED,     /* "throttle_speed" */
    LEVEL_BRAKE_DEAD_SPOT,    /* "brake_dead_spot" */
    LEVEL_BRAKE_OVERSHOOT,    /* "brake_overshoot" */
    LEVEL_BRAKE_SPEED         /* "brake_speed" */
};

/* The slot[] bindings, in the order fn_8017F718 resolves them from the
 * options.  The gaps are the bindings this file's update does not read. */
enum DriverBinding {
    BIND_STEER_LEFT,        /* "steer_left" */
    BIND_STEER_RIGHT,       /* "steer_right" */
    BIND_THROTTLE,          /* "throttle" */
    BIND_BRAKING,           /* "braking" */
    BIND_E_BRAKE,           /* "e_brake" */
    BIND_DIG_THROTTLE,      /* "dig_throttle": the throttle button */
    BIND_DIG_BRAKING,       /* "dig_braking": the brake button */
    BIND_THROTTLE2,         /* "throttle2" */
    BIND_BRAKING2,          /* "braking2" */
    BIND_REVERSE,           /* "reverse" */
    BIND_ALT_REVERSE,       /* "alt_reverse" */
    BIND_HORN,              /* "horn" */
    BIND_HORN2,             /* "horn2" */
    BIND_UPSHIFT,           /* "upshift" */
    BIND_DOWNSHIFT,         /* "downshift" */
    BIND_CLUTCH,            /* "clutch" */
    BIND_HELP,              /* "help" */
    BIND_AIRLIFT,           /* "airlift" */
    BIND_STEER2_LEFT,       /* "steer2_left" */
    BIND_STEER2_RIGHT,      /* "steer2_right" */
    BIND_LOOK_LEFT,         /* "look_left" */
    BIND_LOOK_RIGHT,        /* "look_right" */
    BIND_LOOK_BACK,         /* "look_back" */
    BIND_FREE_G1 = 23,      /* "free_g1".."free_g6": the gear buttons */
    BIND_FREE_REVERSE = 29, /* "free_reverse" */
    BIND_MIRROR_CONTROL = 33, /* "mirror_control" */
    BIND_PITCH_UP = 34,     /* "pitch_up" */
    BIND_PITCH_DOWN = 35,   /* "pitch_down" */
    BIND_ROLL_LEFT = 36,    /* "roll_left" */
    BIND_ROLL_RIGHT = 37    /* "roll_right" */
};

/* The per-player "DriverInterface" object (the name it is heap-allocated
 * under, lbl_80331E68): one per driver index, created on demand by
 * getOrCreateDriverInterface and kept in lbl_804348D8[].  Its vtable is lbl_80331E78
 * (fn_80181428 is the base constructor).  fn_8017F718 fills one from the
 * player's options - the bindings, the response levels and the option bytes
 * below - and PhysDriverUpdate (fn_8017ED00) turns those bindings into the
 * control values each frame.  Only the fields this file's code touches are
 * named; struct DriverInterface further down is an alias for this tag. */
struct Di718 {
    void *vtable;
    s32 index;
    s32 axStackHead;              /* 0x008 __AXGetStackHead_80137CFC(index) */
    f32 pad0C[8];                 /* 0x00C control values, see DriverControl */
    f32 level2C[9];               /* 0x02C response levels, see DriverLevel */
    s32 pad50[2];                 /* 0x050 [0] gear (-1 = reverse), [1] gear count */
    u8 flag58;                    /* 0x058 horn */
    u8 flag59;                    /* 0x059 a shift button is held (one step per press) */
    u8 flag5A;                    /* 0x05A reverse */
    u8 flag5B;                    /* 0x05B help */
    u8 flag5C;                    /* 0x05C sound parameters are being driven */
    u8 flag5D;                    /* 0x05D throttle pressed (rising edge) */
    u8 flag5E;                    /* 0x05E */
    u8 pad5F;
    f32 pad60;                    /* 0x060 steering curve expansion, pass 1 */
    f32 pad64;                    /* 0x064 steering curve expansion, pass 2 */
    u8 flag68;                    /* 0x068 airlift */
    u8 pad69[3];
    struct Di718Slot slot[42];    /* 0x06C input bindings, see DriverBinding */
    f32 pad30C[9];                /* 0x30C [8] camera look, slew-limited */
    u8 pad330[8];                 /* 0x330 [0] pitch, [4] roll (both f32) */
    u8 flag338;                   /* 0x338 look back / mirror control */
    u8 pad339[3];
    f32 pad33C;                   /* 0x33C */
    u8 flag340;                   /* 0x340 option "game_pad": ramp every axis */
    u8 flag341;                   /* 0x341 option "free_shift": gear buttons */
    u8 flag342;                   /* 0x342 controller status flag & 8 */
    u8 flag343;                   /* 0x343 digital steering (status flag & 2) */
    u8 flag344;                   /* 0x344 controller status flag & 0x10 */
    u8 pad345[3];                 /* 0x345 options "digital_throttle" and
                                   *       "digital_braking" */
    s32 mode348;                  /* 0x348 0x10, or the index + 0xC */
    s32 soundId;                  /* 0x34C axStackHead + 8 */
    u8 flag350;                   /* 0x350 */
    u8 pad351[3];
};
extern void fn_8017E930(void *);
extern s32 __AXGetStackHead_80137CFC(s32);
extern s32 fn_801298E8(void *, s32);
extern f32 fn_801429D0(f32, f32);
extern f32 fn_801429E0(f32, f32);
extern f32 fn_80144C80(f32, f32, f32);
extern f32 fn_8014C8F8(f32, f32, f32);
extern s32 fn_80179300(void);
extern void fn_8017F628(void *);
float fn_8017F70C(float);
extern void fn_8017F718(void *);
extern void fn_801A7844(s32);
extern f32 fn_801A7F98(void *);
extern int fn_801A8E38(void *);
extern int fn_801A8E68(void *);
extern s32 fn_801A8F10(void *);
extern void fn_802E30C8(const char *, ...);
extern void Abend_Panic(const char *, ...);
extern s32 fn_802E85B0(s32);
extern const char lbl_80331E28[];
extern const char lbl_80332280[];
extern f32 lbl_80561C50;
extern f32 lbl_80561C54;
extern f32 lbl_80561C5C;
extern f32 lbl_80561C60;
extern f32 lbl_80561C64;
extern f32 lbl_80561C68;
extern f32 lbl_80561C6C;
extern f32 lbl_80561C70;
extern f32 lbl_80561C74;
extern f32 lbl_80561C78;
extern int fn_801A8EE4(void *);
extern int fn_80128668(void);
extern double fabs(double);
extern float lbl_80561C48;
extern float lbl_80561C58;
extern float lbl_80561C4C;
extern float lbl_80561C98;
extern float lbl_80561C9C;
extern void fn_802E8518(void);
typedef struct Unk8017Object Unk8017Object;
typedef struct Unk8017VTable {
    void (*unk_0x0[32])(void);
    void (*unk_0x80)(Unk8017Object *, int);
} Unk8017VTable;
struct Unk8017Object {
    Unk8017VTable *vtable;
};
extern Unk8017Object *lbl_804348D8[4];
extern signed char lbl_8055E4B8;
extern signed char lbl_8055E4B9;
extern signed char lbl_8055E4BA;
extern void fn_801808DC();
extern void fn_802E8524(int, int);

/* Ball-body vtable method: `child` points 0x1EC into the owning object, so recover
 * the BallBody base and forward to fn_8017E930 (out params pass through in r4/r5),
 * which reports the placed ball's x/z position and velocity. */
void fn_8017EB68(void *child) {
    fn_8017E930((char *)child - 0x1EC);
}

extern void fn_8017E96C(void *);
/* Ball-body vtable method: `child` points 0x1EC into the owning object, so recover
 * the BallBody base and forward to fn_8017E96C (out params pass through in r4/r5),
 * which reports a status string and flag derived from the ball's state. */
void fn_8017EB70(void *child) {
    fn_8017E96C((char *)child - 0x1EC);
}

extern void fn_8017E9FC(void *);
/* Ball-body vtable method: `child` points 0x1EC into the owning object, so recover
 * the BallBody base and forward to fn_8017E9FC (other args pass through in r4/r5),
 * which advances the ball's state machine and plays a sound when triggered. */
void fn_8017EB78(void *child) {
    fn_8017E9FC((char *)child - 0x1EC);
}

float fn_8017EB80(float input, float deadSpot, float overshoot) {
    /* Shape a signed analog input into a signed [-1,1] response: clamp
     * (1 + deadSpot + overshoot)*|input| - deadSpot into [0,1]
     * (lbl_80561C48 = 1.0f, lbl_80561C4C = 0.0f), then reapply the sign. */
    float absInput = (float)__fabs(input);
    float response = lbl_80561C48;
    float scaled = response + deadSpot;
    scaled = scaled + overshoot;
    scaled = scaled * absInput;
    scaled = scaled - deadSpot;
    response = response < scaled ? response : scaled;
    response = response > lbl_80561C4C ? response : lbl_80561C4C;
    if (input >= lbl_80561C4C) return response;
    return -response;
}

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
int fn_8017EBE0(void) {
    int zero;
    int one;

    /* Initialize global player/object state slots and run startup setup. */
    zero = 0;
    one = 1;
    lbl_8055E4B8 = zero;
    lbl_8055E4BA = one;
    lbl_8055E4B9 = zero;
    lbl_804348D8[0] = (Unk8017Object *)zero;
    lbl_804348D8[1] = (Unk8017Object *)zero;
    lbl_804348D8[2] = (Unk8017Object *)zero;
    lbl_804348D8[3] = (Unk8017Object *)zero;
    fn_801808DC();
    return 1;
}
#pragma scheduling on
void fn_8017EC30(void) {
    /* Shut down the four driver interfaces: for each occupied slot in
     * lbl_804348D8[], call the object's virtual release method (vtable +0x80),
     * clear the slot, then mark the whole group inactive in lbl_8055E4BA. */
    Unk8017Object **slot = lbl_804348D8;
    int driverIndex = 0;
    do {
        Unk8017Object *driver;
        fn_802E8524(0, driverIndex);
        driver = *slot;
        if (driver != 0) {
#pragma push
#pragma cplusplus on
            {
                class DriverInterfaceView {
                public:
                    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
                    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
                    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
                    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
                    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
                    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
                    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
                    virtual void f28(); virtual void f29();
                    virtual void release(int);
                };
                if (driver != 0) ((DriverInterfaceView *)driver)->release(1);
            }
#pragma pop
            *slot = 0;
        }
        driverIndex++;
        slot++;
    } while (driverIndex < 4);
    lbl_8055E4BA = 0;
}
int fn_8017ECC0(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
/* PhysDriverUpdate (the name its own debug print uses): read the four drivers'
 * input bindings and turn them into the control values the physics driver
 * consumes; called once per frame with the clamped frame time.  An analog
 * binding is shaped by the driver's dead-spot/overshoot levels, while a digital
 * one - and everything a game-pad player or a controller without an analog
 * wheel produces - is instead ramped toward +-1 at the level's speed.  The
 * buttons the game only needs an edge for (horn, reverse, help, airlift, gear
 * changes) are latched into the object's flag bytes. */
void fn_8017ED00(f32 dt) {
#define InputValue        fn_801A7F98   /* a binding's value, 0..1 */
#define InputPressed      fn_801A8E38   /* ... above the press threshold */
#define InputPressedOnce  fn_801A8E68   /* ... on the frame it is pressed */
#define InputIsDigital    fn_801A8EE4   /* the binding is a key/button, not an axis */
#define InputIsBound      fn_801A8F10   /* the device really has that axis/button */
#define ShapeResponse     fn_8017EB80   /* rescale past the dead spot, keep the sign */
#define AbsFloat          fn_8017F70C
#define FloatMax          fn_801429D0
#define FloatMin          fn_801429E0
#define LerpTo            fn_80144C80   /* a + t * (b - a) */
#define ClampTo           fn_8014C8F8   /* value, low, high */
#define LogPrint          fn_802E30C8
#define PanicPrint        Abend_Panic
#define PollInput         fn_801A7844
#define ControllerType    fn_802E85B0   /* rjoy stub: always reports 3 */
#define ReadController    fn_801298E8   /* snapshot of one controller's status */
#define SceneFrames       fn_80179300
#define UpdateDriverSound fn_8017F628
#define ResetDriverLevels fn_8017F718
#define GetStackHead      __AXGetStackHead_80137CFC
#define sDrivers          lbl_804348D8
#define sUpdateSuspended  lbl_8055E4B8
#define sSmoothing        lbl_8055E4B9  /* option "smoothing" */
#define sUnexpectedUseMsg lbl_80331E28  /* "I don't expect PhysDriverUpdate (fg) to be used" */
#define sControllerMsg    lbl_80332280  /* "driver: controller changed for player %d" */
#define K_ONE             lbl_80561C48  /* 1.0f */
#define K_ZERO            lbl_80561C4C  /* 0.0f */
#define K_RAMP_GAIN       lbl_80561C50  /* 1.9f: extra steering ramp on top of the base */
#define K_RAMP_BASE       lbl_80561C54  /* 2.5f: steering ramp, times steer_speed */
#define K_MINUS_ONE       lbl_80561C58  /* -1.0f */
#define K_RELEASE_RATE    lbl_80561C5C  /* 1.5f: pedal release, and raw digital steering */
#define K_STEER_SMOOTH    lbl_80561C60  /* 0.4f: steering smoothing weight / look dead spot */
#define K_THROTTLE_RATE   lbl_80561C64  /* 6.0f: throttle ramp, times throttle_speed */
#define K_BRAKE_RATE      lbl_80561C68  /* 12.0f: brake ramp, times brake_speed */
#define K_CLUTCH_RATE     lbl_80561C6C  /* 10.0f: clutch ramp per second */
#define K_CLUTCH_RELEASE  lbl_80561C70  /* 5.0f: clutch release per second */
#define K_LOOK_DEAD_SPOT  lbl_80561C74  /* 0.07f: camera look dead spot */
#define K_LOOK_RATE       lbl_80561C78  /* 4.0f: camera look per second */
    struct {
        u8 pad00[0x50];
        u32 flags;      /* +0x50 the controller's status bits */
        u8 pad54[0x1C];
    } ctrlInfo;
    u8 digitalBraking;  /* use the brake button rather than the brake axis */
    u8 digitalThrottle; /* ... the throttle button rather than the throttle axis */
    struct Di718 **driverPtr;
    struct Di718 *driver;
    s32 driverIdx;

    if ((u8)sUpdateSuspended != 0) {
        return;
    }
    {
        f32 lookRate;
        f32 clutchRelease;
        f32 clutchRate;
        f32 throttleRate;
        f32 brakeRate;
        f32 releaseRate;
        f32 minusOne;
        f32 one;
        f32 zero;
        f32 rampGain;
        f32 rampBase;
        PanicPrint(sUnexpectedUseMsg);
        PollInput(1);
        zero = K_ZERO;
        clutchRelease = K_CLUTCH_RELEASE;
        clutchRate = K_CLUTCH_RATE;
        brakeRate = K_BRAKE_RATE;
        throttleRate = K_THROTTLE_RATE;
        releaseRate = K_RELEASE_RATE;
        rampBase = K_RAMP_BASE;
        rampGain = K_RAMP_GAIN;
        one = K_ONE;
        minusOne = K_MINUS_ONE;
        lookRate = K_LOOK_RATE;
        driverPtr = (struct Di718 **)sDrivers;
        for (driverIdx = 0; driverIdx < 4; driverIdx++, driverPtr++) {
            s32 deviceIndex;
            struct Di718Slot *binding;
            struct Di718Slot *gearBinding;
            s32 gear;

            driver = *driverPtr;
            if (driver == NULL) {
                continue;
            }
            /* The sound player this driver drives changed: re-register its
             * bindings, levels and options before reading any input. */
            if (driver->axStackHead != GetStackHead(driver->index)) {
                LogPrint(sControllerMsg, driver->index);
                ResetDriverLevels(driver);
            }
            digitalThrottle = driver->pad345[0];
            digitalBraking = driver->pad345[1];
            driver->flag342 = 0;
            driver->flag343 = 0;
            deviceIndex = driver->slot[BIND_THROTTLE].value;
            if (ControllerType(deviceIndex) == 4) {
                driver->flag343 = 1;
                digitalThrottle = 0;
                digitalBraking = 0;
            }
            if (ReadController(&ctrlInfo, deviceIndex) != 0) {
                if (ctrlInfo.flags & 2) {
                    driver->flag343 = 1;
                    digitalThrottle = 0;
                    digitalBraking = 0;
                }
                if (ctrlInfo.flags & 8) {
                    driver->flag342 = 1;
                    driver->flag343 = 1;
                }
            }

            /* Steering: the two steer axes against each other. */
            if (driver->flag340 || InputIsDigital(&driver->slot[BIND_STEER_LEFT]) || InputIsDigital(&driver->slot[BIND_STEER_RIGHT])) {
                f32 rampStep = rampBase * driver->level2C[LEVEL_STEER_SPEED];
                f32 rampRate = rampGain * rampStep;
                f32 pressedRate = rampRate + rampStep;
                if (driver->pad0C[CTRL_STEER] > zero) {
                    driver->pad0C[CTRL_STEER] = FloatMax(driver->pad0C[CTRL_STEER] - rampRate * dt, zero);
                }
                if (driver->pad0C[CTRL_STEER] < zero) {
                    driver->pad0C[CTRL_STEER] = FloatMin(driver->pad0C[CTRL_STEER] + rampRate * dt, zero);
                }
                if (InputPressed(&driver->slot[BIND_STEER_LEFT])) {
                    driver->pad0C[CTRL_STEER] -= pressedRate * dt;
                }
                if (InputPressed(&driver->slot[BIND_STEER_RIGHT])) {
                    driver->pad0C[CTRL_STEER] += pressedRate * dt;
                }
                if (driver->pad0C[CTRL_STEER] > one) {
                    driver->pad0C[CTRL_STEER] = one;
                }
                if (driver->pad0C[CTRL_STEER] < minusOne) {
                    driver->pad0C[CTRL_STEER] = minusOne;
                }
            } else {
                f32 prevSteer = driver->pad0C[CTRL_STEER];
                f32 rightAxis = InputValue(&driver->slot[BIND_STEER_RIGHT]);
                f32 leftAxis = InputValue(&driver->slot[BIND_STEER_LEFT]);
                f32 steerInput = -leftAxis + rightAxis;
                if (driver->flag344) {
                    driver->pad0C[CTRL_STEER] = ShapeResponse(steerInput, driver->level2C[LEVEL_STEER_DEAD_SPOT], driver->level2C[LEVEL_STEER_OVERSHOOT]);
                } else if (!driver->flag343) {
                    driver->pad0C[CTRL_STEER] = ShapeResponse(steerInput, driver->level2C[LEVEL_STEER_DEAD_SPOT], driver->level2C[LEVEL_STEER_OVERSHOOT]);
                    /* Two passes of (1 + k*|x|) - k: keeps the ends of the range
                     * and pulls the middle of the wheel toward zero. */
                    driver->pad0C[CTRL_STEER] *= (one + driver->pad60 * AbsFloat(driver->pad0C[CTRL_STEER])) - driver->pad60;
                    driver->pad0C[CTRL_STEER] *= (one + driver->pad64 * AbsFloat(driver->pad0C[CTRL_STEER])) - driver->pad64;
                } else {
                    driver->pad0C[CTRL_STEER] = steerInput;
                    if (driver->flag342) {
                        driver->pad0C[CTRL_STEER] *= releaseRate;
                    }
                }
                if ((u8)sSmoothing != 0) {
                    driver->pad0C[CTRL_STEER] = LerpTo(driver->pad0C[CTRL_STEER], prevSteer, K_STEER_SMOOTH);
                }
            }

            /* The second steering axis always decays, and only the steer2
             * buttons push it back. */
            {
                f32 rampStep = rampBase * driver->level2C[LEVEL_STEER_SPEED];
                f32 rampRate = rampGain * rampStep;
                f32 pressedRate = rampRate + rampStep;
                if (driver->pad0C[CTRL_STEER2] > zero) {
                    driver->pad0C[CTRL_STEER2] = FloatMax(driver->pad0C[CTRL_STEER2] - rampRate * dt, zero);
                }
                if (driver->pad0C[CTRL_STEER2] < zero) {
                    driver->pad0C[CTRL_STEER2] = FloatMin(driver->pad0C[CTRL_STEER2] + rampRate * dt, zero);
                }
                if (InputPressed(&driver->slot[BIND_STEER2_LEFT])) {
                    driver->pad0C[CTRL_STEER2] -= pressedRate * dt;
                }
                if (InputPressed(&driver->slot[BIND_STEER2_RIGHT])) {
                    driver->pad0C[CTRL_STEER2] += pressedRate * dt;
                }
                if (driver->pad0C[CTRL_STEER2] > one) {
                    driver->pad0C[CTRL_STEER2] = one;
                }
                if (driver->pad0C[CTRL_STEER2] < minusOne) {
                    driver->pad0C[CTRL_STEER2] = minusOne;
                }
            }

            /* Throttle: the analog pedal, or the button when the options ask
             * for digital throttle (or when the pedal is not bound at all). */
            binding = &driver->slot[BIND_THROTTLE];
            if (!InputIsBound(binding)) {
                binding = &driver->slot[BIND_DIG_THROTTLE];
            } else if (digitalThrottle && InputIsBound(&driver->slot[BIND_DIG_THROTTLE])) {
                binding = &driver->slot[BIND_DIG_THROTTLE];
            }
            if (driver->flag340 || digitalThrottle || InputIsDigital(binding)) {
                f32 down;
                f32 up;
                up = throttleRate * driver->level2C[LEVEL_THROTTLE_SPEED];
                down = releaseRate * up;
                if (InputPressed(binding)) {
                    driver->pad0C[CTRL_THROTTLE] = FloatMin(driver->pad0C[CTRL_THROTTLE] + up * dt, K_ONE);
                } else {
                    driver->pad0C[CTRL_THROTTLE] = FloatMax(driver->pad0C[CTRL_THROTTLE] - down * dt, K_ZERO);
                }
            } else {
                driver->pad0C[CTRL_THROTTLE] = ShapeResponse(InputValue(binding), driver->level2C[LEVEL_THROTTLE_DEAD_SPOT], driver->level2C[LEVEL_THROTTLE_OVERSHOOT]);
            }

            if (driver->flag340 || InputIsDigital(&driver->slot[BIND_THROTTLE2])) {
                f32 down;
                f32 up;
                up = throttleRate * driver->level2C[LEVEL_THROTTLE_SPEED];
                down = releaseRate * up;
                if (InputPressed(&driver->slot[BIND_THROTTLE2])) {
                    driver->pad0C[CTRL_THROTTLE2] = FloatMin(driver->pad0C[CTRL_THROTTLE2] + up * dt, K_ONE);
                } else {
                    driver->pad0C[CTRL_THROTTLE2] = FloatMax(driver->pad0C[CTRL_THROTTLE2] - down * dt, K_ZERO);
                }
            } else {
                driver->pad0C[CTRL_THROTTLE2] = ShapeResponse(InputValue(&driver->slot[BIND_THROTTLE2]), driver->level2C[LEVEL_THROTTLE_DEAD_SPOT], driver->level2C[LEVEL_THROTTLE_OVERSHOOT]);
            }

            /* Brake, same choice between pedal and button. */
            binding = &driver->slot[BIND_BRAKING];
            if (!InputIsBound(binding)) {
                binding = &driver->slot[BIND_DIG_BRAKING];
            } else if (digitalBraking && InputIsBound(&driver->slot[BIND_DIG_BRAKING])) {
                binding = &driver->slot[BIND_DIG_BRAKING];
            }
            if (driver->flag340 || digitalBraking || InputIsDigital(binding)) {
                f32 up = brakeRate * driver->level2C[LEVEL_BRAKE_SPEED];
                f32 down = throttleRate * driver->level2C[LEVEL_BRAKE_SPEED];
                if (driver->pad0C[CTRL_BRAKE] > zero) {
                    driver->pad0C[CTRL_BRAKE] = FloatMax(driver->pad0C[CTRL_BRAKE] - down * dt, zero);
                }
                if (InputPressed(binding)) {
                    driver->pad0C[CTRL_BRAKE] += up * dt;
                }
                if (driver->pad0C[CTRL_BRAKE] > one) {
                    driver->pad0C[CTRL_BRAKE] = one;
                }
            } else {
                driver->pad0C[CTRL_BRAKE] = ShapeResponse(InputValue(binding), driver->level2C[LEVEL_BRAKE_DEAD_SPOT], driver->level2C[LEVEL_BRAKE_OVERSHOOT]);
            }

            if (driver->flag340 || InputIsDigital(&driver->slot[BIND_BRAKING2])) {
                f32 up = brakeRate * driver->level2C[LEVEL_BRAKE_SPEED];
                f32 down = throttleRate * driver->level2C[LEVEL_BRAKE_SPEED];
                if (driver->pad0C[CTRL_BRAKE2] > zero) {
                    driver->pad0C[CTRL_BRAKE2] = FloatMax(driver->pad0C[CTRL_BRAKE2] - down * dt, zero);
                }
                if (InputPressed(&driver->slot[BIND_BRAKING2])) {
                    driver->pad0C[CTRL_BRAKE2] += up * dt;
                }
                if (driver->pad0C[CTRL_BRAKE2] > one) {
                    driver->pad0C[CTRL_BRAKE2] = one;
                }
            } else {
                driver->pad0C[CTRL_BRAKE2] = ShapeResponse(InputValue(&driver->slot[BIND_BRAKING2]), driver->level2C[LEVEL_BRAKE_DEAD_SPOT], driver->level2C[LEVEL_BRAKE_OVERSHOOT]);
            }

            driver->pad0C[CTRL_E_BRAKE] = InputValue(&driver->slot[BIND_E_BRAKE]);
            if (!driver->flag341) {
                driver->flag5A = InputPressed(&driver->slot[BIND_REVERSE]) || InputPressed(&driver->slot[BIND_ALT_REVERSE]);
            }

            /* The clutch builds up while held and falls back on its own. */
            if (InputIsDigital(&driver->slot[BIND_CLUTCH])) {
                if (InputPressed(&driver->slot[BIND_CLUTCH])) {
                    driver->pad0C[CTRL_CLUTCH] += clutchRate * dt;
                } else if (driver->pad0C[CTRL_CLUTCH] > zero) {
                    driver->pad0C[CTRL_CLUTCH] = FloatMax(driver->pad0C[CTRL_CLUTCH] - clutchRelease * dt, zero);
                }
                if (driver->pad0C[CTRL_CLUTCH] > one) {
                    driver->pad0C[CTRL_CLUTCH] = one;
                }
            } else {
                driver->pad0C[CTRL_CLUTCH] = InputValue(&driver->slot[BIND_CLUTCH]);
            }

            driver->flag5B = InputPressed(&driver->slot[BIND_HELP]);
            driver->flag58 = InputPressed(&driver->slot[BIND_HORN]) || InputPressed(&driver->slot[BIND_HORN2]);
            driver->flag5D = InputPressedOnce(&driver->slot[BIND_THROTTLE]);
            if (SceneFrames() < 40) {
                driver->flag58 = 0;
            }
            driver->flag68 = InputPressed(&driver->slot[BIND_AIRLIFT]);

            /* Camera look: slew-limited toward the look buttons' value. */
            {
                f32 lookLeft = InputValue(&driver->slot[BIND_LOOK_LEFT]);
                f32 look = ShapeResponse(-lookLeft + InputValue(&driver->slot[BIND_LOOK_RIGHT]), K_STEER_SMOOTH, K_LOOK_DEAD_SPOT);
                f32 maxStep = lookRate * dt;
                driver->pad30C[8] += ClampTo(look - driver->pad30C[8], -maxStep, maxStep);
            }

            driver->flag338 = InputPressed(&driver->slot[BIND_LOOK_BACK]);
            if (InputPressed(&driver->slot[BIND_MIRROR_CONTROL])) {
                driver->flag338 = 1;
            }
            {
                f32 pitchUp = InputValue(&driver->slot[BIND_PITCH_UP]);
                *(f32 *)&driver->pad330[0] = InputValue(&driver->slot[BIND_PITCH_DOWN]) - pitchUp;
            }
            {
                f32 rollLeft = InputValue(&driver->slot[BIND_ROLL_LEFT]);
                *(f32 *)&driver->pad330[4] = InputValue(&driver->slot[BIND_ROLL_RIGHT]) - rollLeft;
            }

            if (!driver->flag341) {
                /* Sequential shifting: one step per press of the shift buttons. */
                if (InputPressed(&driver->slot[BIND_UPSHIFT])) {
                    if (!driver->flag59) {
                        if (driver->pad50[0] < driver->pad50[1]) {
                            driver->pad50[0]++;
                        }
                        driver->flag59 = 1;
                    }
                } else if (InputPressed(&driver->slot[BIND_DOWNSHIFT])) {
                    if (!driver->flag59) {
                        if (driver->pad50[0] > -1) {
                            driver->pad50[0]--;
                        }
                        driver->flag59 = 1;
                    }
                } else {
                    driver->flag59 = 0;
                }
            } else {
                /* Free shifting: the gear buttons pick the gear directly. */
                driver->flag59 = 0;
                driver->pad50[0] = 0;
                gearBinding = &driver->slot[BIND_FREE_G1];
                for (gear = 0; gear < driver->pad50[1]; gearBinding++, gear++) {
                    if (InputPressed(gearBinding)) {
                        driver->pad50[0] = gear + 1;
                    }
                }
                if (InputPressed(&driver->slot[BIND_FREE_REVERSE])) {
                    driver->pad50[0] = -1;
                }
            }
            UpdateDriverSound(driver);
        }
    }
}
#pragma pop

extern int fn_801769F8(void);
extern int fn_801B526C(void);
extern int fn_801C5B60(void);
extern void fn_802E8528(int, float, float);
extern void fn_802E85A8(int, float, float, float);
extern void fn_802E85AC(int, float, float, float);
extern float lbl_8055A334;
extern float lbl_80561C60;
#pragma push
#pragma processor 750
void fn_8017F628(void *arg0) {
    /* Updates rumble/audio parameters from the object's state when active; otherwise resets them. */
    float scaleFactor = lbl_8055A334;
    if (fn_801769F8() == 0 && fn_801B526C() == 0 && fn_801C5B60() == 0 &&
        *(unsigned char *)((char *)arg0 + 0x5C) && *(unsigned char *)((char *)arg0 + 0x350)) {
        float scaledBase = *(float *)((char *)arg0 + 0x30C) * scaleFactor;
        fn_802E85AC(*(int *)((char *)arg0 + 8), *(float *)((char *)arg0 + 0x314) + scaledBase,
                    *(float *)((char *)arg0 + 0x310) * scaleFactor, scaledBase);
        {
            float scaledParamB = *(float *)((char *)arg0 + 0x318) * scaleFactor;
            float scaledParamC = *(float *)((char *)arg0 + 0x320) * scaleFactor;
            float paramD = *(float *)((char *)arg0 + 0x31C);
            fn_802E85A8(*(int *)((char *)arg0 + 8), scaledParamB, paramD, scaledParamC);
        }
        {
            float scaledX = *(float *)((char *)arg0 + 0x324) * scaleFactor;
            float rawY = *(float *)((char *)arg0 + 0x328);
            float absY = __fabs(rawY);
            float absScaledX = __fabs(scaledX);
            fn_802E8528(*(int *)((char *)arg0 + 8), lbl_80561C60 * absScaledX, absY);
        }
    } else ((void (*)(int))fn_802E8518)(*(int *)((char *)arg0 + 8));
}
#pragma pop
/* Single-precision absolute value (computed in double, then rounded back to float). */
float fn_8017F70C(float value) { double temp = __fabs(value); return temp; }

#pragma scheduling invalid_target
void fn_8017F718(void *arg0) {
    char name[64];
    unsigned char flag;
    int keys1[4];
    int keys2[4];
    int *slot;
    int i;
    int j;
    struct Di718 *v;
    float value;
    float f90;
    float f8C;
    float f88;
    float f84;
    float f48;
    float f80;
    float f7C;
    float value2;
    v = (struct Di718 *)arg0;
    {
        s32 axHead = __AXGetStackHead_80137CFC(v->index);
        f7C = lbl_80561C7C;
        f8C = lbl_80561C8C;
        f80 = lbl_80561C80;
        f48 = lbl_80561C48;
        f84 = lbl_80561C84;
        f88 = lbl_80561C88;
        f90 = lbl_80561C90;
        v->axStackHead = axHead;
    }
    v->level2C[0] = f7C;
    v->level2C[3] = f7C;
    v->level2C[6] = f80;
    v->level2C[2] = f48;
    v->level2C[5] = f84;
    v->level2C[8] = f88;
    v->level2C[1] = f8C;
    v->level2C[4] = f90;
    v->level2C[7] = f8C;
    v->flag340 = 0;
    v->flag341 = 0;
    LoadFloatOption(v->soundId, lbl_80332270, (char *)v + 0x2C);
    LoadFloatOption(v->soundId, lbl_80332258, (char *)v + 0x38);
    LoadFloatOption(v->soundId, lbl_80332248, (char *)v + 0x44);
    LoadFloatOption(v->soundId, lbl_80332238, (char *)v + 0x30);
    LoadFloatOption(v->soundId, lbl_80332220, (char *)v + 0x3C);
    LoadFloatOption(v->soundId, lbl_80332210, (char *)v + 0x48);
    LoadFloatOption(v->soundId, lbl_80332200, (char *)v + 0x34);
    LoadFloatOption(v->soundId, lbl_803321F0, (char *)v + 0x40);
    LoadFloatOption(v->soundId, lbl_803321E4, (char *)v + 0x4C);
    LoadFloatOption(v->soundId, lbl_803321D0, (char *)v + 0x60);
    v->flag5C = 1;
    fn_801333E8(v->soundId, lbl_803321C4, (char *)v + 0x340);
    fn_801333E8(v->soundId, lbl_803321B8, &v->flag341);
    v->flag5E = 1;
    value = lbl_80561C48;
    value = value < (v->pad60 - lbl_80561C48) ? value : (v->pad60 - lbl_80561C48);
    value = value > lbl_80561C4C ? value : lbl_80561C4C;
    value2 = lbl_80561C48;
    v->pad64 = value;
    value2 = value2 < v->pad60 ? value2 : v->pad60;
    value2 = value2 > lbl_80561C4C ? value2 : lbl_80561C4C;
    value = v->level2C[2];
    v->pad60 = value2;
    value = value > lbl_80561C94 ? value : lbl_80561C94;
    value2 = v->level2C[5];
    v->level2C[2] = value;
    value2 = value2 > lbl_80561C94 ? value2 : lbl_80561C94;
    value = v->level2C[8];
    v->level2C[5] = value2;
    value = value > lbl_80561C94 ? value : lbl_80561C94;
    v->level2C[8] = value;
#pragma push
#pragma cplusplus on
#pragma paired_single off
    {
        class Callback {
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
            virtual int f21();
        };
        if (((Callback *)v)->f21() != 0) {
            v->pad60 = lbl_80561C4C;
        }
    }
#pragma pop
    fn_802E8524(v->flag5C, v->axStackHead);
    {
        int *p1 = lbl_802F9530;
        int *p2 = lbl_802F9540;
        keys1[0] = *p1++;
        keys1[1] = *p1++;
        keys1[2] = *p1++;
        keys1[3] = *p1;
        keys2[0] = *p2++;
        keys2[1] = *p2++;
        keys2[2] = *p2++;
        keys2[3] = *p2;
    }
    slot = (int *)((char *)v + 0x2CC);
    for (i = 0; i < 4; i++, slot += 4) {
        fn_801A7DFC(keys1[i], keys2[i], v->soundId);
        fn_801A7974((char *)slot, (const char *)keys1[i], v->soundId);
    }
    fn_801A7974((char *)v + 0x6C, lbl_803321AC, v->soundId);
    fn_801A7974((char *)v + 0x7C, lbl_803321A0, v->soundId);
    fn_801A7974((char *)v + 0x18C, lbl_80332194, v->soundId);
    fn_801A7974((char *)v + 0x19C, lbl_80332184, v->soundId);
    fn_801A7974((char *)v + 0x8C, lbl_80332178, v->soundId);
    fn_801A7974((char *)v + 0x9C, lbl_8055A398, v->soundId);
    fn_801A7974((char *)v + 0xBC, lbl_80332168, v->soundId);
    fn_801A7974((char *)v + 0xCC, lbl_8033215C, v->soundId);
    fn_801A7974((char *)v + 0xDC, lbl_80332150, v->soundId);
    fn_801A7974((char *)v + 0xEC, lbl_80332144, v->soundId);
    fn_801A7974((char *)v + 0x24C, lbl_8055A390, v->soundId);
    fn_801A7974((char *)v + 0x25C, lbl_80332138, v->soundId);
    fn_801A7974((char *)v + 0x26C, lbl_8033212C, v->soundId);
    fn_801A7974((char *)v + 0x27C, lbl_8033211C, v->soundId);
    fn_801A7974((char *)v + 0xAC, lbl_8055A388, v->soundId);
    fn_801A7974((char *)v + 0xFC, lbl_8055A380, v->soundId);
    fn_801A7974((char *)v + 0x10C, lbl_80332110, v->soundId);
    fn_801A7974((char *)v + 0x15C, lbl_8055A378, v->soundId);
    fn_801A7974((char *)v + 0x13C, lbl_8055A370, v->soundId);
    fn_801A7974((char *)v + 0x14C, lbl_80332104, v->soundId);
    fn_801A7974((char *)v + 0x16C, lbl_8055A368, v->soundId);
    fn_801A7974((char *)v + 0x17C, lbl_8055A360, v->soundId);
    fn_801A7974((char *)v + 0x11C, lbl_8055A358, v->soundId);
    fn_801A7974((char *)v + 0x12C, lbl_8055A350, v->soundId);
    fn_801A7974((char *)v + 0x1AC, lbl_803320F8, v->soundId);
    fn_801A7974((char *)v + 0x1BC, lbl_803320EC, v->soundId);
    fn_801A7974((char *)v + 0x1CC, lbl_803320E0, v->soundId);
    fn_801A7974((char *)v + 0x28C, lbl_803320D4, v->soundId);
    fn_801A7974((char *)v + 0x29C, lbl_803320C8, v->soundId);
    fn_801A7974((char *)v + 0x2AC, lbl_803320BC, v->soundId);
    fn_801A7974((char *)v + 0x2BC, lbl_803320B0, v->soundId);
    LoadFloatOption(v->soundId, lbl_8033209C, &lbl_8055A330);
    LoadFloatOption(v->soundId, lbl_8033208C, &lbl_8055A334);
    LoadFloatOption(v->soundId, lbl_80332078, &lbl_8055A338);
    LoadFloatOption(v->soundId, lbl_80332064, &lbl_8055A33C);
    LoadFloatOption(v->soundId, lbl_80332050, &lbl_8055A340);
    LoadFloatOption(v->soundId, lbl_8033203C, &lbl_8055A344);
    v->flag341 = 0;
    fn_801333E8(v->soundId, lbl_80332030, (char *)v + 0x341);
    v->pad345[1] = 0;
    v->pad345[0] = 1;
    fn_801333E8(v->soundId, lbl_80332020, (char *)v + 0x346);
    fn_801333E8(v->soundId, lbl_80332008, (char *)v + 0x345);
    flag = 0;
    fn_801333E8(v->soundId, lbl_80331FFC, &flag);
    if (flag != 0) {
        fn_802E30C8(lbl_80331FF0);
        v->pad345[1] = 0;
        v->pad345[0] = 0;
    }
    fn_801A9110(&v->slot[23], lbl_80331FE4);
    fn_801A9110(&v->slot[24], lbl_80331FD8);
    fn_801A9110(&v->slot[25], lbl_80331FCC);
    fn_801A9110(&v->slot[26], lbl_80331FC0);
    fn_801A9110(&v->slot[27], lbl_80331FB4);
    fn_801A9110(&v->slot[28], lbl_80331FA8);
    fn_801A9110(&v->slot[29], lbl_80331F9C);
    slot = (int *)((char *)v + 0x1DC);
    for (j = 0; j < 6; j++, slot += 4) {
        sprintf(name, lbl_80331F90, j + 1);
        fn_801A7974((char *)slot, name, v->soundId);
    }
    fn_801A7974((char *)v + 0x23C, lbl_80331F80, v->soundId);
    {
        int head = v->axStackHead;
        v->flag344 = 0;
        v->slot[0].value = head;
        v->slot[1].value = head;
        v->slot[18].value = head;
        v->slot[19].value = head;
        v->slot[2].value = head;
        v->slot[3].value = head;
        v->slot[4].value = head;
        v->slot[7].value = head;
        v->slot[8].value = head;
        v->slot[5].value = head;
        v->slot[6].value = head;
        v->slot[9].value = head;
        v->slot[10].value = head;
        v->slot[13].value = head;
        v->slot[14].value = head;
        v->slot[15].value = head;
        v->slot[11].value = head;
        v->slot[12].value = head;
        v->slot[17].value = head;
        v->slot[30].value = head;
        v->slot[31].value = head;
        v->slot[32].value = head;
        v->slot[33].value = head;
        v->slot[16].value = head;
        v->slot[20].value = head;
        v->slot[21].value = head;
        v->slot[22].value = head;
        v->slot[34].value = head;
        v->slot[35].value = head;
        v->slot[36].value = head;
        v->slot[37].value = head;
        v->slot[38].value = head;
        v->slot[39].value = head;
        v->slot[40].value = head;
        v->slot[41].value = head;
        {
            char buf[96];
            if (fn_801298E8(buf, head) != 0 && ((*(int *)(buf + 0x50) & 0x10) != 0)) {
                *(volatile unsigned char *)((char *)v + 0x344) = 1;
                *(volatile unsigned char *)((char *)v + 0x344) = 1u;
            }
        }
    }
}
extern int fn_80128668(void);
extern int fn_801A8EE4(void *);
/* Return 1 if the object's flag at 0x340 is set or if either of the checked subobjects at offsets 0x6C or 0x7C reports active via fn_801A8EE4. */
int fn_8017FEE4(void *object) {
    int isActive = 0;
    if (*(unsigned char *)((char *)object + 0x340) != 0 ||
        fn_801A8EE4((char *)object + 0x6C) != 0 ||
        fn_801A8EE4((char *)object + 0x7C) != 0) {
        isActive = 1;
    }
    return isActive;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_8017FF4C(f32 dt) {
    /* Per-frame input update for all four players: translate each bound slot
     * into a control value (fn_801A7F98), apply analog rates/dead-zones and
     * digital presses, and write the results into the player's pad0C[] controls
     * and flag bytes. When the early-out condition holds, zero the cached
     * pad30C[] history instead. dt is the frame delta time. */
    struct {
        u8 pad00[0x50];
        u32 flags;
        u8 pad54[0x1C];
    } ctrlInfo;
    u8 useAltB;
    u8 useAltA;
    struct Di718 **playerPtr;
    struct Di718 *player;
    s32 playerIdx;

    if ((u8)lbl_8055E4B8 == 0) {
        return;
    }
    if (fn_801769F8() == 0 && fn_801B526C() == 0) {
        f32 k78;
        f32 k70;
        f32 k6C;
        f32 k64;
        f32 k68;
        f32 k5C;
        f32 minusOne;
        f32 one;
        f32 zero;
        f32 k50;
        f32 k54;
        fn_801A7844(1);
        zero = lbl_80561C4C;
        k70 = lbl_80561C70;
        k6C = lbl_80561C6C;
        k68 = lbl_80561C68;
        k64 = lbl_80561C64;
        k5C = lbl_80561C5C;
        k54 = lbl_80561C54;
        k50 = lbl_80561C50;
        one = lbl_80561C48;
        minusOne = lbl_80561C58;
        k78 = lbl_80561C78;
        playerPtr = (struct Di718 **)lbl_804348D8;
        for (playerIdx = 0; playerIdx < 4; playerIdx++, playerPtr++) {
            s32 slotValue;
            struct Di718Slot *activeSlot;
            struct Di718Slot *gearSlot;
            s32 gear;

            player = *playerPtr;
            if (player == NULL) {
                continue;
            }
            if (player->axStackHead != __AXGetStackHead_80137CFC(player->index)) {
                fn_802E30C8(lbl_80332280, player->index);
                fn_8017F718(player);
            }
            useAltA = player->pad345[0];
            useAltB = player->pad345[1];
            player->flag342 = 0;
            player->flag343 = 0;
            slotValue = player->slot[2].value;
            if (fn_802E85B0(slotValue) == 4) {
                player->flag343 = 1;
                useAltA = 0;
                useAltB = 0;
            }
            if (fn_801298E8(&ctrlInfo, slotValue) != 0) {
                if (ctrlInfo.flags & 2) {
                    player->flag343 = 1;
                    useAltA = 0;
                    useAltB = 0;
                }
                if (ctrlInfo.flags & 8) {
                    player->flag342 = 1;
                    player->flag343 = 1;
                }
            }

            /* Steering: digital left/right or the analog axis difference. */
            if (player->flag340 || fn_801A8EE4(&player->slot[0]) || fn_801A8EE4(&player->slot[1])) {
                f32 base = k54 * player->level2C[2];
                f32 rate = k50 * base;
                f32 fast = rate + base;
                if (player->pad0C[0] > zero) {
                    player->pad0C[0] = fn_801429D0(player->pad0C[0] - rate * dt, zero);
                }
                if (player->pad0C[0] < zero) {
                    player->pad0C[0] = fn_801429E0(player->pad0C[0] + rate * dt, zero);
                }
                if (fn_801A8E38(&player->slot[0])) {
                    player->pad0C[0] -= fast * dt;
                }
                if (fn_801A8E38(&player->slot[1])) {
                    player->pad0C[0] += fast * dt;
                }
                if (player->pad0C[0] > one) {
                    player->pad0C[0] = one;
                }
                if (player->pad0C[0] < minusOne) {
                    player->pad0C[0] = minusOne;
                }
            } else {
                f32 prevSteer = player->pad0C[0];
                f32 rightAxis = fn_801A7F98(&player->slot[1]);
                f32 leftAxis = fn_801A7F98(&player->slot[0]);
                f32 steerInput = -leftAxis + rightAxis;
                if (player->flag344) {
                    player->pad0C[0] = fn_8017EB80(steerInput, player->level2C[0], player->level2C[1]);
                } else if (!player->flag343) {
                    player->pad0C[0] = fn_8017EB80(steerInput, player->level2C[0], player->level2C[1]);
                    player->pad0C[0] *= (one + player->pad60 * fn_8017F70C(player->pad0C[0])) - player->pad60;
                    player->pad0C[0] *= (one + player->pad64 * fn_8017F70C(player->pad0C[0])) - player->pad64;
                } else {
                    player->pad0C[0] = steerInput;
                    if (player->flag342) {
                        player->pad0C[0] *= k5C;
                    }
                }
                if ((u8)lbl_8055E4B9 != 0) {
                    player->pad0C[0] = fn_80144C80(player->pad0C[0], prevSteer, lbl_80561C60);
                }
            }

            /* Acceleration/brake axis. */
            {
                f32 base = k54 * player->level2C[2];
                f32 rate = k50 * base;
                f32 fast = rate + base;
                if (player->pad0C[1] > zero) {
                    player->pad0C[1] = fn_801429D0(player->pad0C[1] - rate * dt, zero);
                }
                if (player->pad0C[1] < zero) {
                    player->pad0C[1] = fn_801429E0(player->pad0C[1] + rate * dt, zero);
                }
                if (fn_801A8E38(&player->slot[18])) {
                    player->pad0C[1] -= fast * dt;
                }
                if (fn_801A8E38(&player->slot[19])) {
                    player->pad0C[1] += fast * dt;
                }
                if (player->pad0C[1] > one) {
                    player->pad0C[1] = one;
                }
                if (player->pad0C[1] < minusOne) {
                    player->pad0C[1] = minusOne;
                }
            }

            activeSlot = &player->slot[2];
            if (!fn_801A8F10(activeSlot)) {
                activeSlot = &player->slot[5];
            } else if (useAltA && fn_801A8F10(&player->slot[5])) {
                activeSlot = &player->slot[5];
            }
            if (player->flag340 || useAltA || fn_801A8EE4(activeSlot)) {
                f32 down;
                f32 up;
                up = k64 * player->level2C[5];
                down = k5C * up;
                if (fn_801A8E38(activeSlot)) {
                    player->pad0C[5] = fn_801429E0(player->pad0C[5] + up * dt, lbl_80561C48);
                } else {
                    player->pad0C[5] = fn_801429D0(player->pad0C[5] - down * dt, lbl_80561C4C);
                }
            } else {
                player->pad0C[5] = fn_8017EB80(fn_801A7F98(activeSlot), player->level2C[3], player->level2C[4]);
            }

            if (player->flag340 || fn_801A8EE4(&player->slot[7])) {
                f32 down;
                f32 up;
                up = k64 * player->level2C[5];
                down = k5C * up;
                if (fn_801A8E38(&player->slot[7])) {
                    player->pad0C[6] = fn_801429E0(player->pad0C[6] + up * dt, lbl_80561C48);
                } else {
                    player->pad0C[6] = fn_801429D0(player->pad0C[6] - down * dt, lbl_80561C4C);
                }
            } else {
                player->pad0C[6] = fn_8017EB80(fn_801A7F98(&player->slot[7]), player->level2C[3], player->level2C[4]);
            }

            activeSlot = &player->slot[3];
            if (!fn_801A8F10(activeSlot)) {
                activeSlot = &player->slot[6];
            } else if (useAltB && fn_801A8F10(&player->slot[6])) {
                activeSlot = &player->slot[6];
            }
            if (player->flag340 || useAltB || fn_801A8EE4(activeSlot)) {
                f32 up = k68 * player->level2C[8];
                f32 down = k64 * player->level2C[8];
                if (player->pad0C[2] > zero) {
                    player->pad0C[2] = fn_801429D0(player->pad0C[2] - down * dt, zero);
                }
                if (fn_801A8E38(activeSlot)) {
                    player->pad0C[2] += up * dt;
                }
                if (player->pad0C[2] > one) {
                    player->pad0C[2] = one;
                }
            } else {
                player->pad0C[2] = fn_8017EB80(fn_801A7F98(activeSlot), player->level2C[6], player->level2C[7]);
            }

            if (player->flag340 || fn_801A8EE4(&player->slot[8])) {
                f32 up = k68 * player->level2C[8];
                f32 down = k64 * player->level2C[8];
                if (player->pad0C[3] > zero) {
                    player->pad0C[3] = fn_801429D0(player->pad0C[3] - down * dt, zero);
                }
                if (fn_801A8E38(&player->slot[8])) {
                    player->pad0C[3] += up * dt;
                }
                if (player->pad0C[3] > one) {
                    player->pad0C[3] = one;
                }
            } else {
                player->pad0C[3] = fn_8017EB80(fn_801A7F98(&player->slot[8]), player->level2C[6], player->level2C[7]);
            }

            player->pad0C[7] = fn_801A7F98(&player->slot[4]);
            if (!player->flag341) {
                player->flag5A = fn_801A8E38(&player->slot[9]) || fn_801A8E38(&player->slot[10]);
            }

            if (fn_801A8EE4(&player->slot[15])) {
                if (fn_801A8E38(&player->slot[15])) {
                    player->pad0C[4] += k6C * dt;
                } else if (player->pad0C[4] > zero) {
                    player->pad0C[4] = fn_801429D0(player->pad0C[4] - k70 * dt, zero);
                }
                if (player->pad0C[4] > one) {
                    player->pad0C[4] = one;
                }
            } else {
                player->pad0C[4] = fn_801A7F98(&player->slot[15]);
            }

            player->flag5B = fn_801A8E38(&player->slot[16]);
            player->flag58 = fn_801A8E38(&player->slot[11]) || fn_801A8E38(&player->slot[12]);
            player->flag5D = fn_801A8E68(&player->slot[2]);
            if (fn_80179300() < 40) {
                player->flag58 = 0;
            }
            player->flag68 = fn_801A8E38(&player->slot[17]);

            /* Camera/look axis is rate-limited towards the raw stick value. */
            {
                f32 leftAxis = fn_801A7F98(&player->slot[20]);
                f32 steerInput = fn_8017EB80(-leftAxis + fn_801A7F98(&player->slot[21]), lbl_80561C60, lbl_80561C74);
                f32 maxStep = k78 * dt;
                player->pad30C[8] += fn_8014C8F8(steerInput - player->pad30C[8], -maxStep, maxStep);
            }

            player->flag338 = fn_801A8E38(&player->slot[22]);
            if (fn_801A8E38(&player->slot[33])) {
                player->flag338 = 1;
            }
            {
                f32 negAxis = fn_801A7F98(&player->slot[34]);
                *(f32 *)&player->pad330[0] = fn_801A7F98(&player->slot[35]) - negAxis;
            }
            {
                f32 negAxis = fn_801A7F98(&player->slot[36]);
                *(f32 *)&player->pad330[4] = fn_801A7F98(&player->slot[37]) - negAxis;
            }

            /* Gear selection via +/- keys or the sequential gear slots. */
            if (!player->flag341) {
                if (fn_801A8E38(&player->slot[13])) {
                    if (!player->flag59) {
                        if (player->pad50[0] < player->pad50[1]) {
                            player->pad50[0]++;
                        }
                        player->flag59 = 1;
                    }
                } else if (fn_801A8E38(&player->slot[14])) {
                    if (!player->flag59) {
                        if (player->pad50[0] > -1) {
                            player->pad50[0]--;
                        }
                        player->flag59 = 1;
                    }
                } else {
                    player->flag59 = 0;
                }
            } else {
                player->flag59 = 0;
                player->pad50[0] = 0;
                gearSlot = &player->slot[23];
                for (gear = 0; gear < player->pad50[1]; gearSlot++, gear++) {
                    if (fn_801A8E38(gearSlot)) {
                        player->pad50[0] = gear + 1;
                    }
                }
                if (fn_801A8E38(&player->slot[29])) {
                    player->pad50[0] = -1;
                }
            }
            fn_8017F628(player);
        }
    } else {
        struct Di718 **playerPtr;
        s32 playerIdx;
        dt = lbl_80561C4C;
        playerPtr = (struct Di718 **)lbl_804348D8;
        for (playerIdx = 0; playerIdx < 4; playerIdx++, playerPtr++) {
            player = *playerPtr;
            if (player != NULL) {
                player->pad30C[6] = dt;
                player->pad30C[7] = dt;
                player->pad30C[2] = dt;
                player->pad30C[1] = dt;
                player->pad30C[0] = dt;
                player->pad30C[5] = dt;
                player->pad30C[4] = dt;
                player->pad30C[3] = dt;
                if (player->axStackHead >= 0) {
                    ((void (*)(s32))fn_802E8518)(player->axStackHead);
                }
            }
        }
    }
}
#pragma pop
extern float lbl_80561C7C;
extern float lbl_80561C80;
extern float lbl_80561C84;
extern float lbl_80561C88;
extern float lbl_80561C8C;
extern float lbl_80561C90;
extern float lbl_80561C94;
extern float lbl_8055A330;
extern float lbl_8055A338;
extern float lbl_8055A33C;
extern float lbl_8055A340;
extern float lbl_8055A344;
extern char lbl_80331E58[];
extern char lbl_80331F80[];
extern char lbl_80331F90[];
extern char lbl_80331F9C[];
extern char lbl_80331FA8[];
extern char lbl_80331FB4[];
extern char lbl_80331FC0[];
extern char lbl_80331FCC[];
extern char lbl_80331FD8[];
extern char lbl_80331FE4[];
extern char lbl_80331FF0[];
extern char lbl_80331FFC[];
extern char lbl_80332008[];
extern char lbl_80332020[];
extern char lbl_80332030[];
extern char lbl_8033203C[];
extern char lbl_80332050[];
extern char lbl_80332064[];
extern char lbl_80332078[];
extern char lbl_8033208C[];
extern char lbl_8033209C[];
extern char lbl_803320B0[];
extern char lbl_803320BC[];
extern char lbl_803320C8[];
extern char lbl_803320D4[];
extern char lbl_803320E0[];
extern char lbl_803320EC[];
extern char lbl_803320F8[];
extern char lbl_80332104[];
extern char lbl_80332110[];
extern char lbl_8033211C[];
extern char lbl_8033212C[];
extern char lbl_80332138[];
extern char lbl_80332144[];
extern char lbl_80332150[];
extern char lbl_8033215C[];
extern char lbl_80332168[];
extern char lbl_80332178[];
extern char lbl_80332184[];
extern char lbl_80332194[];
extern char lbl_803321A0[];
extern char lbl_803321AC[];
extern char lbl_803321B8[];
extern char lbl_803321C4[];
extern char lbl_803321D0[];
extern char lbl_803321E4[];
extern char lbl_803321F0[];
extern char lbl_80332200[];
extern char lbl_80332210[];
extern char lbl_80332220[];
extern char lbl_80332238[];
extern char lbl_80332248[];
extern char lbl_80332258[];
extern char lbl_80332270[];
extern int lbl_802F9530[];
extern int lbl_802F9540[];
__declspec(section ".sdata") extern const char lbl_8055A350[];
__declspec(section ".sdata") extern const char lbl_8055A358[];
__declspec(section ".sdata") extern const char lbl_8055A360[];
__declspec(section ".sdata") extern const char lbl_8055A368[];
__declspec(section ".sdata") extern const char lbl_8055A370[];
__declspec(section ".sdata") extern const char lbl_8055A378[];
__declspec(section ".sdata") extern const char lbl_8055A380[];
__declspec(section ".sdata") extern const char lbl_8055A388[];
__declspec(section ".sdata") extern const char lbl_8055A390[];
__declspec(section ".sdata") extern const char lbl_8055A398[];
extern void LoadFloatOption(int, const char *, void *);
extern void fn_801333E8(int, const char *, void *);
extern void fn_801A7974(void *, const char *, int);
extern void fn_801A7DFC(int, int, int);
extern void fn_801A9110(void *, const char *);
extern int sprintf(char *, const char *, ...);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801808DC(void) {
    char name[64];
    unsigned char flag;
    int keys2[4];
    int keys1[4];
    float f4C;
    float f90;
    float f8C;
    float f88;
    float f84;
    float f48;
    float f80;
    float f7C;
    int *keyBase1;
    int *keyBase2;
    int j;
    int *namedSlot;
    int i;
    Unk8017Object **table;
    const int *readKey2;
    const int *readKey1;
    int *slot;
    struct Di718 *v;
    int count;
    fn_801333E8(8, lbl_80331E58, &lbl_8055E4B9);
    lbl_8055E4B8 = 1;
    f48 = lbl_80561C48;
    f7C = lbl_80561C7C;
    f80 = lbl_80561C80;
    f84 = lbl_80561C84;
    f88 = lbl_80561C88;
    f8C = lbl_80561C8C;
    f90 = lbl_80561C90;
    f4C = lbl_80561C4C;
    table = lbl_804348D8;
    keyBase1 = lbl_802F9530;
    keyBase2 = lbl_802F9540;
    for (count = 0; count < 4; count++, table++) {
        v = (struct Di718 *)*table;
        if (v == 0) continue;
        v->axStackHead = __AXGetStackHead_80137CFC(v->index);
        v->level2C[0] = f7C;
        v->level2C[3] = f7C;
        v->level2C[6] = f80;
        v->level2C[2] = f48;
        v->level2C[5] = f84;
        v->level2C[8] = f88;
        v->level2C[1] = f8C;
        v->level2C[4] = f90;
        v->level2C[7] = f8C;
        v->flag340 = 0;
        v->flag341 = 0;
        LoadFloatOption(v->soundId, lbl_80332270, (char *)v + 0x2C);
        LoadFloatOption(v->soundId, lbl_80332258, (char *)v + 0x38);
        LoadFloatOption(v->soundId, lbl_80332248, (char *)v + 0x44);
        LoadFloatOption(v->soundId, lbl_80332238, (char *)v + 0x30);
        LoadFloatOption(v->soundId, lbl_80332220, (char *)v + 0x3C);
        LoadFloatOption(v->soundId, lbl_80332210, (char *)v + 0x48);
        LoadFloatOption(v->soundId, lbl_80332200, (char *)v + 0x34);
        LoadFloatOption(v->soundId, lbl_803321F0, (char *)v + 0x40);
        LoadFloatOption(v->soundId, lbl_803321E4, (char *)v + 0x4C);
        LoadFloatOption(v->soundId, lbl_803321D0, (char *)v + 0x60);
        v->flag5C = 1;
        fn_801333E8(v->soundId, lbl_803321C4, (char *)v + 0x340);
        fn_801333E8(v->soundId, lbl_803321B8, &v->flag341);
        v->flag5E = 1;
        {
            float limit = lbl_80561C4C;
            v->pad64 = fn_8014C8F8(v->pad60 - f48, limit, f48);
            limit = lbl_80561C4C;
            v->pad60 = fn_8014C8F8(v->pad60, limit, lbl_80561C48);
            limit = lbl_80561C94;
            v->level2C[2] = fn_801429D0(v->level2C[2], limit);
            limit = lbl_80561C94;
            v->level2C[5] = fn_801429D0(v->level2C[5], limit);
            limit = lbl_80561C94;
            v->level2C[8] = fn_801429D0(v->level2C[8], limit);
        }
#pragma push
#pragma cplusplus on
#pragma paired_single off
        {
            class Callback {
            public:
                virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
                virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
                virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
                virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
                virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
                virtual void f20(); virtual int f21();
            };
            if (((Callback *)v)->f21() != 0) {
                v->pad60 = f4C;
            }
        }
#pragma pop
        fn_802E8524(v->flag5C, v->axStackHead);
        {
            register int *p1 = keyBase1;
            register int *p2 = keyBase2;
            keys1[0] = *p1++;
            keys1[1] = *p1++;
            keys1[2] = *p1++;
            keys1[3] = *p1;
            keys2[0] = *p2++;
            keys2[1] = *p2++;
            keys2[2] = *p2++;
            keys2[3] = *p2;
        }
        readKey2 = keys2;
        readKey1 = keys1;
        slot = (int *)&v->slot[(0x2CC - 0x6C) / 0x10];
        for (i = 0; i < 4; i++, readKey2++, readKey1++, slot += 4) {
            fn_801A7DFC(*readKey1, *readKey2, v->soundId);
            fn_801A7974((char *)slot, (const char *)*readKey1, v->soundId);
        }
        fn_801A7974((char *)v + 0x6C, lbl_803321AC, v->soundId);
        fn_801A7974((char *)v + 0x7C, lbl_803321A0, v->soundId);
        fn_801A7974((char *)v + 0x18C, lbl_80332194, v->soundId);
        fn_801A7974((char *)v + 0x19C, lbl_80332184, v->soundId);
        fn_801A7974((char *)v + 0x8C, lbl_80332178, v->soundId);
        fn_801A7974((char *)v + 0x9C, lbl_8055A398, v->soundId);
        fn_801A7974((char *)v + 0xBC, lbl_80332168, v->soundId);
        fn_801A7974((char *)v + 0xCC, lbl_8033215C, v->soundId);
        fn_801A7974((char *)v + 0xDC, lbl_80332150, v->soundId);
        fn_801A7974((char *)v + 0xEC, lbl_80332144, v->soundId);
        fn_801A7974((char *)v + 0x24C, lbl_8055A390, v->soundId);
        fn_801A7974((char *)v + 0x25C, lbl_80332138, v->soundId);
        fn_801A7974((char *)v + 0x26C, lbl_8033212C, v->soundId);
        fn_801A7974((char *)v + 0x27C, lbl_8033211C, v->soundId);
        fn_801A7974((char *)v + 0xAC, lbl_8055A388, v->soundId);
        fn_801A7974((char *)v + 0xFC, lbl_8055A380, v->soundId);
        fn_801A7974((char *)v + 0x10C, lbl_80332110, v->soundId);
        fn_801A7974((char *)v + 0x15C, lbl_8055A378, v->soundId);
        fn_801A7974((char *)v + 0x13C, lbl_8055A370, v->soundId);
        fn_801A7974((char *)v + 0x14C, lbl_80332104, v->soundId);
        fn_801A7974((char *)v + 0x16C, lbl_8055A368, v->soundId);
        fn_801A7974((char *)v + 0x17C, lbl_8055A360, v->soundId);
        fn_801A7974((char *)v + 0x11C, lbl_8055A358, v->soundId);
        fn_801A7974((char *)v + 0x12C, lbl_8055A350, v->soundId);
        fn_801A7974((char *)v + 0x1AC, lbl_803320F8, v->soundId);
        fn_801A7974((char *)v + 0x1BC, lbl_803320EC, v->soundId);
        fn_801A7974((char *)v + 0x1CC, lbl_803320E0, v->soundId);
        fn_801A7974((char *)v + 0x28C, lbl_803320D4, v->soundId);
        fn_801A7974((char *)v + 0x29C, lbl_803320C8, v->soundId);
        fn_801A7974((char *)v + 0x2AC, lbl_803320BC, v->soundId);
        fn_801A7974((char *)v + 0x2BC, lbl_803320B0, v->soundId);
        LoadFloatOption(v->soundId, lbl_8033209C, &lbl_8055A330);
        LoadFloatOption(v->soundId, lbl_8033208C, &lbl_8055A334);
        LoadFloatOption(v->soundId, lbl_80332078, &lbl_8055A338);
        LoadFloatOption(v->soundId, lbl_80332064, &lbl_8055A33C);
        LoadFloatOption(v->soundId, lbl_80332050, &lbl_8055A340);
        LoadFloatOption(v->soundId, lbl_8033203C, &lbl_8055A344);
        v->flag341 = 0;
        fn_801333E8(v->soundId, lbl_80332030, (char *)v + 0x341);
        v->pad345[1] = 0;
        v->pad345[0] = 1;
        fn_801333E8(v->soundId, lbl_80332020, (char *)v + 0x346);
        fn_801333E8(v->soundId, lbl_80332008, (char *)v + 0x345);
        flag = 0;
        fn_801333E8(v->soundId, lbl_80331FFC, &flag);
        if (flag != 0) {
            fn_802E30C8(lbl_80331FF0);
            v->pad345[1] = 0;
            v->pad345[0] = 0;
        }
        fn_801A9110(&v->slot[23], lbl_80331FE4);
        fn_801A9110(&v->slot[24], lbl_80331FD8);
        fn_801A9110(&v->slot[25], lbl_80331FCC);
        fn_801A9110(&v->slot[26], lbl_80331FC0);
        fn_801A9110(&v->slot[27], lbl_80331FB4);
        fn_801A9110(&v->slot[28], lbl_80331FA8);
        fn_801A9110(&v->slot[29], lbl_80331F9C);
        namedSlot = (int *)((char *)v + 0x1DC);
        for (j = 0; j < 6; j++, namedSlot += 4) {
            sprintf(name, lbl_80331F90, j + 1);
            fn_801A7974((char *)namedSlot, name, v->soundId);
        }
        fn_801A7974((char *)v + 0x23C, lbl_80331F80, v->soundId);
        {
            int head = v->axStackHead;
            v->slot[0].value = head;
            v->slot[1].value = head;
            v->slot[18].value = head;
            v->slot[19].value = head;
            v->slot[2].value = head;
            v->slot[3].value = head;
            v->slot[4].value = head;
            v->slot[7].value = head;
            v->slot[8].value = head;
            v->slot[5].value = head;
            v->slot[6].value = head;
            v->slot[9].value = head;
            v->slot[10].value = head;
            v->slot[13].value = head;
            v->slot[14].value = head;
            v->slot[15].value = head;
            v->slot[11].value = head;
            v->slot[12].value = head;
            v->slot[17].value = head;
            v->slot[30].value = head;
            v->slot[31].value = head;
            v->slot[32].value = head;
            v->slot[33].value = head;
            v->slot[16].value = head;
            v->slot[20].value = head;
            v->slot[21].value = head;
            v->slot[22].value = head;
            v->slot[34].value = head;
            v->slot[35].value = head;
            v->slot[36].value = head;
            v->slot[37].value = head;
            v->slot[38].value = head;
            v->slot[39].value = head;
            v->slot[40].value = head;
            v->slot[41].value = head;
            v->flag344 = 0;
            {
                char buf[96];
                if (fn_801298E8(buf, head) != 0 && ((*(int *)(buf + 0x50) & 0x10) != 0)) {
                    *(volatile unsigned char *)((char *)v + 0x344) = 1;
                    *(volatile unsigned char *)((char *)v + 0x344) = 1u;
                }
            }
        }
    }
}
#pragma pop
/* One of the sound-player slots a DriverInterface owns from 0x6C on;
 * fn_80181418 resets one (its id and its "in use" byte), fn_8017F718 gives
 * each of them a name and the sound it plays. */
/* The same binding as struct Di718Slot at the top of this file: the layout was
 * written twice in this translation unit, so keep one and alias the tag. */
#define DriverInterfaceSlot Di718Slot

/* The same object as struct Di718 at the top of this file, where it is now
 * documented; alias the tag this half of the file was written with. */
#define DriverInterface Di718

/* The object is handled as a void * here; cast it to name its fields. */
#define DRIVER(p) ((struct DriverInterface *)(p))

/* The float at 0x30C on its own.  Reaching it as a member (rather than as an
 * array element of the whole object) is what lets the compiler reuse the
 * address the slot loops leave in a register. */
struct DriverInterface30C { u8 pad[0x30c]; f32 field; };

/* The float literals this unit keeps in .sdata2. */
#define F_ZERO lbl_80561C4C  /* 0.0f */
#define F_ONE lbl_80561C48   /* 1.0f */
#define F_TENTH lbl_80561C8C /* 0.1f */

#pragma dont_inline fn_80181418
#pragma dont_inline fn_80181428
extern void fn_80181418(void *, int);
extern void fn_80181428(void **);
extern void *fn_801284F8(s32, const char *);
extern s32 fn_8027AA48(void);
extern u8 lbl_80331E68[];
extern u8 lbl_80331E78[];
extern f32 lbl_80561C8C;
#pragma dont_inline fn_80181418
#pragma dont_inline fn_80181428
#pragma scheduling invalid_target
/* Create the DriverInterface of driver index arg0 - once; the four of them
 * live in lbl_804348D8[] - and return it, or 0 when the heap has no room.
 * The object itself only gets its identity, its sound id and zeroed player
 * slots here; fn_8017F718 is what names the slots and registers the sounds. */
s32 getOrCreateDriverInterface(s32 arg0) {
    Unk8017Object **table;
    s32 entry_offset = arg0 * 4;
    void *slot_end;
    void *driver;
    void *slot;
    void *slot2;
    s32 zero;
    f32 zero_f, one_f, tenth_f;

    if ((table = lbl_804348D8,
         *(Unk8017Object **)((u8 *)table + entry_offset)) == 0) {
        driver = fn_801284F8(sizeof(struct DriverInterface), (const char *)lbl_80331E68);
        if (driver != 0) {
            fn_80181428(&DRIVER(driver)->vtable);
            DRIVER(driver)->vtable = lbl_80331E78;
            fn_80181418(&DRIVER(driver)->slot[0], 0);
            fn_80181418(&DRIVER(driver)->slot[1], 0);
            fn_80181418(&DRIVER(driver)->slot[2], 0);
            fn_80181418(&DRIVER(driver)->slot[3], 0);
            fn_80181418(&DRIVER(driver)->slot[4], 0);
            fn_80181418(&DRIVER(driver)->slot[5], 0);
            fn_80181418(&DRIVER(driver)->slot[6], 0);
            fn_80181418(&DRIVER(driver)->slot[7], 0);
            fn_80181418(&DRIVER(driver)->slot[8], 0);
            fn_80181418(&DRIVER(driver)->slot[9], 0);
            fn_80181418(&DRIVER(driver)->slot[10], 0);
            fn_80181418(&DRIVER(driver)->slot[11], 0);
            fn_80181418(&DRIVER(driver)->slot[12], 0);
            fn_80181418(&DRIVER(driver)->slot[13], 0);
            fn_80181418(&DRIVER(driver)->slot[14], 0);
            fn_80181418(&DRIVER(driver)->slot[15], 0);
            fn_80181418(&DRIVER(driver)->slot[16], 0);
            fn_80181418(&DRIVER(driver)->slot[17], 0);
            fn_80181418(&DRIVER(driver)->slot[18], 0);
            fn_80181418(&DRIVER(driver)->slot[19], 0);
            fn_80181418(&DRIVER(driver)->slot[20], 0);
            fn_80181418(&DRIVER(driver)->slot[21], 0);
            fn_80181418(&DRIVER(driver)->slot[22], 0);
            slot = (u8 *)driver + 0x1DC; /* slot[23] .. slot[28] */
            slot_end = (u8 *)driver + 0x23C;
            do {
                fn_80181418(slot, 0);
                slot = (u8 *)slot + 0x10;
            } while (slot < slot_end);
            fn_80181418(slot_end, 0);
            fn_80181418(&DRIVER(driver)->slot[30], 0);
            fn_80181418(&DRIVER(driver)->slot[31], 0);
            fn_80181418(&DRIVER(driver)->slot[32], 0);
            fn_80181418(&DRIVER(driver)->slot[33], 0);
            fn_80181418(&DRIVER(driver)->slot[34], 0);
            fn_80181418(&DRIVER(driver)->slot[35], 0);
            fn_80181418(&DRIVER(driver)->slot[36], 0);
            fn_80181418(&DRIVER(driver)->slot[37], 0);
            slot2 = (u8 *)driver + 0x2CC; /* slot[38] .. slot[41] */
            slot_end = (u8 *)driver + 0x30C;
            do {
                fn_80181418(slot2, 0);
                slot2 = (u8 *)slot2 + 0x10;
            } while (slot2 < slot_end);

            DRIVER(driver)->index = arg0;
            DRIVER(driver)->axStackHead = __AXGetStackHead_80137CFC(arg0);
            DRIVER(driver)->flag350 = 0;
            if (fn_8027AA48() != 0)
                DRIVER(driver)->mode348 = 0x10;
            else
                DRIVER(driver)->mode348 = arg0 + 0xC;
            zero = 0;
            zero_f = F_ZERO;
            DRIVER(driver)->soundId =
                DRIVER(driver)->axStackHead + 8;
            one_f = F_ONE;
            {
                DRIVER(driver)->pad33C = zero_f;
                tenth_f = F_TENTH;
                DRIVER(driver)->flag5B = zero;
                DRIVER(driver)->flag5C = zero;
                DRIVER(driver)->flag5E = 1;
                DRIVER(driver)->pad60 = one_f;
                DRIVER(driver)->level2C[0] = zero_f;
                DRIVER(driver)->level2C[2] = one_f;
                DRIVER(driver)->level2C[1] = tenth_f;
                DRIVER(driver)->level2C[3] = tenth_f;
                DRIVER(driver)->level2C[5] = one_f;
                DRIVER(driver)->level2C[4] = tenth_f;
                DRIVER(driver)->level2C[6] = tenth_f;
                DRIVER(driver)->level2C[8] = one_f;
                DRIVER(driver)->level2C[7] = tenth_f;
                DRIVER(driver)->pad50[0] = zero;
                DRIVER(driver)->pad50[1] = zero;
                DRIVER(driver)->pad0C[0] = zero_f;
                DRIVER(driver)->pad0C[1] = zero_f;
                DRIVER(driver)->pad0C[2] = zero_f;
                DRIVER(driver)->pad0C[5] = zero_f;
                DRIVER(driver)->pad0C[3] = zero_f;
                DRIVER(driver)->pad0C[6] = zero_f;
                DRIVER(driver)->pad0C[4] = zero_f;
                DRIVER(driver)->pad0C[7] = zero_f;
                DRIVER(driver)->flag58 = zero;
                DRIVER(driver)->flag5D = zero;
                DRIVER(driver)->flag68 = zero;
                DRIVER(driver)->flag59 = zero;
                DRIVER(driver)->flag5A = zero;
                DRIVER(driver)->pad30C[2] = zero_f;
                DRIVER(driver)->pad30C[1] = zero_f;
                ((struct DriverInterface30C *)driver)->field = zero_f;
                DRIVER(driver)->pad30C[5] = zero_f;
                DRIVER(driver)->pad30C[4] = zero_f;
                DRIVER(driver)->pad30C[3] = zero_f;
                DRIVER(driver)->pad30C[7] = zero_f;
                DRIVER(driver)->pad30C[6] = zero_f;
                DRIVER(driver)->pad30C[8] = zero_f;
                DRIVER(driver)->flag338 = zero;
                DRIVER(driver)->flag340 = zero;
                DRIVER(driver)->flag341 = zero;
                DRIVER(driver)->flag342 = zero;
                DRIVER(driver)->flag343 = zero;
                DRIVER(driver)->flag344 = zero;
                ((void (*)(void *, f32, f32))fn_8017F718)(driver, one_f, zero_f);
            }
        }
        *(Unk8017Object **)((u8 *)table + entry_offset) = driver;
    }
    return (s32)*(Unk8017Object **)((u8 *)table + entry_offset);
}
int fn_801813D8(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_80181418(void *arg0, int arg1) {
    /* Reset a driver-interface sound slot: assign its value/id and clear its in-use flag. */
    ((struct DriverInterfaceSlot *)arg0)->value = arg1;
    ((struct DriverInterfaceSlot *)arg0)->inUse = 0;
}

extern void lbl_80331EFC(void);
#define s_baseDriverVTable lbl_80331EFC
/* Base DriverInterface constructor: store the address of the all-null base
 * vtable in *vtableSlot; getOrCreateDriverInterface then overrides it with the real vtable,
 * lbl_80331E78. */
void fn_80181428(void **vtableSlot) {
    *vtableSlot = (void *)&s_baseDriverVTable;
}
#undef s_baseDriverVTable

/* Empty stub (no operation). */
void fn_80181438(void) {

}

/* Empty virtual method of the DriverInterface base class: base vtable
 * lbl_80331EFC slot +0x78, a no-op default like the neighbouring stubs at
 * slots +0x74 (fn_80181438) and +0x7C (fn_80181440), just before the deleting
 * destructor at +0x80. The live vtable lbl_80331E78 has no such slot, so this
 * base implementation is never dispatched on a constructed DriverInterface. */
void fn_8018143C(void) {

}

/* No-op stub (empty function). */
void fn_80181440(void) {
}

/* Return the driver's sound id (soundId at +0x34C), derived from its AX stack head. */
int fn_80181444(void *driver) { return DRIVER(driver)->soundId; }

/* Return the driver's mode (mode348 at +0x348): 0x10, or the driver index + 0xC. */
int fn_8018144C(void *driver) { return DRIVER(driver)->mode348; }

void GXInitLightAttnA_80181454(void *light, float a, float b, float c) {
    /* Set the three diffuse-attenuation coefficients a/b/c of the light object. */
    *(float *)((char *)light + 0x30C) = a;
    *(float *)((char *)light + 0x310) = b;
    *(float *)((char *)light + 0x314) = c;
}

void GXInitLightAttnK_80181464(void *light, float a, float b, float c) {
    /* Set the three specular-attenuation coefficients a/b/c of the light object. */
    *(float *)((char *)light + 0x318) = a;
    *(float *)((char *)light + 0x31C) = b;
    *(float *)((char *)light + 0x320) = c;
}

void fn_80181474(void *obj, float x, float y) {
    /* Set the two rumble-parameter floats at +0x324/+0x328 (read by fn_8017F628). */
    *(float *)((char *)obj + 0x324) = x;
    *(float *)((char *)obj + 0x328) = y;
}

/* Update the running minimum at +0x50 with value, always recording the latest value at +0x54. */
void fn_80181480(void *tracker, int value) {
 int minSoFar=*(int *)((char *)tracker+0x50);
 *(int *)((char *)tracker+0x54)=value;
 if(minSoFar>value) *(int *)((char *)tracker+0x50)=value;
}

#pragma push
#pragma cplusplus on
#pragma processor 750
#pragma paired_single off
#pragma scheduling invalid_target
extern "C" float fn_80181498(void *arg0) {
    class Callback {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
        virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual int f21();
    };
    float a;
    float b;
    a = *(float *)((char *)arg0 + 0xC);
    a = (a > 1.0f) ? a : 1.0f;
    b = *(float *)((char *)arg0 + 0xC);
    b = (b < -1.0f) ? -1.0f : b;
    a = (a < (*(float *)((char *)arg0 + 0xC) + *(float *)((char *)arg0 + 0x10))) ? (*(float *)((char *)arg0 + 0xC) + *(float *)((char *)arg0 + 0x10)) : a;
    a = (a > b) ? b : a;
    if (((Callback *)arg0)->f21() != 0) {
        a = *(float *)((char *)arg0 + 0xC);
    }
    return a;
}
#pragma pop
/* Return the sum of the two driver stats at +0x20 and +0x24, capped at 1.0. */
float fn_80181548(void *driver) {
#define MAX_STAT lbl_80561C48
    float sum = *(float *)((char *)driver + 0x20) + *(float *)((char *)driver + 0x24);
    if (sum < MAX_STAT) return sum;
    return MAX_STAT;
#undef MAX_STAT
}

/* Return the sum of the two driver stats at +0x14 and +0x18, capped at 1.0. */
float fn_80181568(void *driver) {
#define MAX_STAT lbl_80561C48
    float sum = *(float *)((char *)driver + 0x14) + *(float *)((char *)driver + 0x18);
    if (sum < MAX_STAT) return sum;
    return MAX_STAT;
#undef MAX_STAT
}

extern void fn_802E8518(void);
extern float lbl_80561C98;
extern float lbl_80561C9C;
/* Normalize the stat at +0x1C as (1.1 - 1.2 * value), then clamp to [0,1]
 * (lbl_80561C4C = 0.0f, lbl_80561C48 = 1.0f). */
float fn_80181588(void *arg0) {
    float scaled = lbl_80561C98 - lbl_80561C9C * *(float *)((char *)arg0 + 0x1C);
    float clamped = lbl_80561C4C;
    clamped = clamped > scaled ? clamped : scaled;
    if (lbl_80561C48 < clamped) return lbl_80561C48;
    return clamped;
}

/* Return the float stat at offset 0x28 of the object. */
float fn_801815C4(void *obj) {
    return *(float *)((char *)obj + 0x28);
}

/* Return the integer field at offset 0x50 of this object (set by fn_801815D4). */
int fn_801815CC(void *object) {
    return *(int *)((char *)object + 0x50);
}

/* Set the running-minimum field at +0x50 (paired with the fn_801815CC getter and fn_80181480 updater). */
void fn_801815D4(void *arg0, int minValue) {
    typedef struct { char pad[0x50]; int minValue; } MinTracker;
    ((MinTracker *)arg0)->minValue = minValue;
}

/* Clamp a level to [0,1] and store it in the object's field at +0x20. */
void fn_801815DC(void *obj, float level) {
#define MAX_LEVEL lbl_80561C48  /* 1.0f */
#define MIN_LEVEL lbl_80561C4C  /* 0.0f */
    float clamped = MAX_LEVEL < level ? MAX_LEVEL : level;
    clamped = clamped > MIN_LEVEL ? clamped : MIN_LEVEL;
    *(float *)((char *)obj + 0x20) = clamped;
#undef MIN_LEVEL
#undef MAX_LEVEL
}

extern int fn_801A8E68(void *);
extern void fn_801797F8(int, int, int);
void fn_8018160C(void *arg0) {
    /* Poll input/state slots on this object and queue events through fn_801797F8
     * (using the id at +0x4) when fn_801A8E68 reports a triggered edge. */
    char *slotPtr;
    int slotIndex;
    if (fn_801A8E68((char *)arg0 + 0x25c)) fn_801797F8(*(int *)((char *)arg0 + 4), 2, 0);
    if (fn_801A8E68((char *)arg0 + 0x26c)) fn_801797F8(*(int *)((char *)arg0 + 4), 1, 0);
    if (fn_801A8E68((char *)arg0 + 0x27c)) fn_801797F8(*(int *)((char *)arg0 + 4), 3, 0);
    if (fn_801A8E68((char *)arg0 + 0x24c)) fn_801797F8(*(int *)((char *)arg0 + 4), 0, 0);
    for (slotPtr = (char *)arg0 + 0x2cc, slotIndex = 0; slotIndex < 4; slotIndex++, slotPtr += 0x10) {
        if (fn_801A8E68(slotPtr)) {
            fn_801797F8(*(int *)((char *)arg0 + 4), 4, slotIndex);
            break;
        }
    }
}

/* Store the control flag at +0x350; when it is cleared, recenter the steering
 * of the (non-negative) axis index kept at +0x8. */
void fn_80181700(void *self, int flag) {
    int stackHead;
    *(unsigned char *)((char *)self + 0x350) = flag;
    if (flag != 0) return;
    stackHead = *(int *)((char *)self + 8);
    if (stackHead < 0) return;
    ((void (*)(int))fn_802E8518)(stackHead);
}

/* Stop the sound/event on a slot when it is valid and its owner is not type 0x11. */
void fn_80181720(void *arg0) {
    if (*(int *)((char *)arg0 + 8) >= 0 && fn_8026A368(*(int *)((char *)arg0 + 4)) != 0x11) {
        RjoyUpdateTiltHistory(*(int *)((char *)arg0 + 8));
    }
}

/* Return the unsigned byte field at offset 0x58 of this object. */
int fn_8018176C(void *object) {
    return *(unsigned char *)((char *)object + 0x58);
}

/* Return the unsigned control-flag byte at offset 0x5D of this object. */
int fn_80181774(void *object) {
    return ((struct Di718 *)object)->flag5D;
}

/* Return the flag68 byte (offset 0x68) of this audio-driver object. */
int fn_8018177C(void *object) {
    return ((struct Di718 *)object)->flag68;
}

/* Return the unsigned control-flag byte at offset 0x5A of this object. */
int fn_80181784(void *object) {
    return ((struct Di718 *)object)->flag5A;
}

/* Return the unsigned control-flag byte flag5B (offset 0x5B) of this audio-driver object. */
unsigned char fn_8018178C(void *object) { return ((struct Di718 *)object)->flag5B; }

/* Return the driver's rate-limited camera/look axis (pad30C[8] at +0x32C). */
float fn_80181794(void *driver) { return DRIVER(driver)->pad30C[8]; }

/* Return the driver's float value at +0x330, just past the pad30C history block. */
float fn_8018179C(void *driver) { return *(float *)((char *)driver + 0x330); }

/* Return the float field at offset 0x334 of this audio-driver object. */
float fn_801817A4(void *object) { return *(float *)((char *)object + 0x334); }

/* Return the unsigned control-flag byte flag338 (offset 0x338) of this audio-driver object. */
unsigned char fn_801817AC(void *object) { return ((struct Di718 *)object)->flag338; }

/* RealName: IsSubobjectActiveAt9C (tentative). Returns 1 if object has flag set at 0x340 or the subobject at offset 0x9C is active per fn_801A8EE4, else 0. */
int fn_801817B4(void *object) {
    int isActive = 0;

    if (*(unsigned char *)((char *)object + 0x340) != 0 || fn_801A8EE4((char *)object + 0x9C) != 0) {
        isActive = 1;
    }

    return isActive;
}

/* RealName: IsSubobjectActiveAt8C (tentative). Returns 1 if object has flag set at 0x340 or the subobject at offset 0x8C is active per fn_801A8EE4, else 0. */
int fn_80181800(void *object) {
    int isActive = 0;

    if (*(unsigned char *)((char *)object + 0x340) != 0 || fn_801A8EE4((char *)object + 0x8C) != 0) {
        isActive = 1;
    }

    return isActive;
}

/* Return the audio driver's flag344 control byte at offset 0x344. */
unsigned char fn_8018184C(void *object) { return ((struct Di718 *)object)->flag344; }
extern int fn_801769F8(void);
extern int fn_801B526C(void);
extern int fn_801C5B60(void);
extern void fn_802E8528(int, float, float);
extern void fn_802E85A8(int, float, float, float);
extern void fn_802E85AC(int, float, float, float);
extern float lbl_8055A334;
extern float lbl_80561C60;
