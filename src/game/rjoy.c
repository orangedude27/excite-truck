// rjoy — WPAD joystick layer ("rjoy: waiting for WPAD to shut down").
// Recovered TU window 0x802E77B8..0x802E86CC (see docs/attribution_analysis.md).
// Static-init thunk fn_802E86CC (+ .ctors slot 0x802ED618) remains in
// auto/text_802E86CC_.c pending a promotion pass.
extern void fn_802E6B44(int, int);
extern int lbl_80507268[];
extern unsigned char lbl_80505978[];
/* rjoy globals, named in comments because this project cannot rename game symbols:
 * lbl_80507268 - WPAD sampling callbacks saved per controller channel on init
 *                (restored on shutdown), chained to by our own callback.
 * lbl_80505978 - Wiimote/controller state table, 0x638 bytes per controller. */
#define gPrevSamplingCallbacks lbl_80507268
#define gWiimoteStateTable     lbl_80505978
#define WPAD_ERR_NONE          0
#define WPAD_ERR_NO_CONTROLLER (-1)
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80565160, lbl_80565164, lbl_80565168, lbl_8056516C;
extern float lbl_80565170, lbl_80565174, lbl_80565178;
extern int lbl_8055D208, lbl_8055D210, lbl_8055D218, lbl_8055D220;
__declspec(section ".rodata") extern int lbl_8034D898;
__declspec(section ".rodata") extern int lbl_8034D8A8;
extern int fn_801282EC(int);
extern int fn_801282F4(void);
extern int fn_801284E8(void *, int);
extern int gWpadAllocHandles[];
extern int wpadAllocTag;
extern int gWpadAllocCount;
extern unsigned char gRjoyMotorEnabled;
extern char ConfigGetWpadMotorMode(void);
  void fn_802E8528(int, float, float);
/* Stub for the rjoy input-filter predicate (called with a controller channel):
   always returns 0, so this filter path never marks input as filtered. */
int fn_802E77B8(void) { return 0; }

#pragma push
#pragma dont_inline on
/* Map a controller/WPAD status code to its human-readable label for the rjoy status-change debug log. */
/* Return the human-readable label for a controller/WPAD status code, used by the rjoy status-change debug log. */ void *RjoyStatusName(int statusCode) {
    switch (statusCode) {
    case 0:
        return &lbl_8055D208; /* "NONE" */
    case -1:
        return &lbl_8034D898; /* "NO_CONTROLLER" */
    case -2:
        return &lbl_8055D210; /* "BUSY" */
    case -3:
        return &lbl_8034D8A8; /* "TRANSFER" */
    case -4:
        return &lbl_8055D218; /* "INVALID" */
    default:
        return &lbl_8055D220; /* "???" */
    }
}
#pragma pop

  #pragma push
 #pragma scheduling invalid_target
/* Dead-zone response: rescale an axis value past its dead zone into +/-1.5,
 * saturating a non-negative value to [0.0, 1.5] and a negative one to [-1.5, 0.0]. */
/* Dead-zone response: rescale an axis past its dead zone into +/-1.5, saturating positive values to [0, 1.5] and negative ones to [-1.5, 0]. */ float RjoyDeadZoneResponse(float value, float deadZone) {
#define RJOY_ZERO       lbl_80565164 /* 0.0f: clamp midpoint and input threshold */
#define RJOY_ONE        lbl_80565160 /* 1.0f: scale numerator */
#define RJOY_MAX        lbl_80565168 /* 1.5f: positive output ceiling */
#define RJOY_MIN        lbl_8056516C /* -1.5f: negative output floor */
    float threshold = RJOY_ZERO;
    float scale = RJOY_ONE / (RJOY_ONE - deadZone);
    if (value >= threshold) {
        float result = RJOY_MAX;
        float scaled = scale * (value - deadZone);
        if (result < scaled) { result = result; } else { result = scaled; }
        if (result > RJOY_ZERO) { result = result; } else { result = RJOY_ZERO; }
        return result;
    } else {
        float scaled = scale * (value + deadZone);
        if (threshold < scaled) { threshold = threshold; } else { threshold = scaled; }
        if (threshold > RJOY_MIN) { threshold = threshold; } else { threshold = RJOY_MIN; }
        threshold = threshold;
        return threshold;
    }
#undef RJOY_MIN
#undef RJOY_MAX
#undef RJOY_ONE
#undef RJOY_ZERO
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
#pragma processor 750
/* Shapes one Wii Remote tilt/stick axis into the steering value fn_802E7DDC stores
 * in its input record: the dead-zone response RjoyDeadZoneResponse() is sampled twice, with
 * the axis pushed RJOY_KNEE toward and away from zero, and the two samples averaged,
 * which rounds that response's hard dead-zone corner into a soft knee. The result is
 * then blended toward the squared response v*|v| by RJOY_CURVE_AMOUNT, which is
 * 0.0f, so the output stays linear. */
/* Shapes a Wii Remote tilt axis into rjoy's steering angle: averages two dead-zone samples at axis +/- knee to soften the dead-zone corner, then blends toward a squared response by a curve-amount factor that is currently 0 (linear output). */ float RjoyShapeSteeringAxis(float axis) {
#define RJOY_KNEE         lbl_80565174 /* 0.05f: how far each sample is shifted */
#define RJOY_DEAD_ZONE    lbl_80565178 /* 0.1f: dead zone RjoyDeadZoneResponse rescales past */
#define RJOY_HALF         lbl_80565170 /* 0.5f: weight of the two samples */
#define RJOY_CURVE_AMOUNT lbl_80565164 /* 0.0f: 0 = linear, 1 = v*|v| */
    float highSample = RjoyDeadZoneResponse(RJOY_KNEE + axis, RJOY_DEAD_ZONE);
    float lowSample = RjoyDeadZoneResponse(axis - RJOY_KNEE, RJOY_DEAD_ZONE);
    float shapedAxis = RJOY_HALF * (lowSample + highSample);
    float curveDelta = shapedAxis * (float)__fabs(shapedAxis) - shapedAxis;
    return shapedAxis + RJOY_CURVE_AMOUNT * curveDelta;
#undef RJOY_KNEE
#undef RJOY_DEAD_ZONE
#undef RJOY_HALF
#undef RJOY_CURVE_AMOUNT
}
#pragma scheduling invalid_target
void fn_802E7920(int arg0) {
    extern int WPADControlMotor(int, int);
    extern int fn_802D9BF0(void);
    extern int KERNEL_GetTimeMs(void);
    extern unsigned char lbl_80505978[];
    extern unsigned char gRjoyMotorEnabled;
    unsigned char *p;
    int player = arg0;
    int time;
    int motor;
    int value;
    int cmd;
    p = lbl_80505978 + player * 0x638;
    time = KERNEL_GetTimeMs();
    motor = fn_802D9BF0();
    if (*(unsigned short *)(p + 0xB0) < 0x5000) {
        if (time - *(int *)(p + 0xBC) > 0x3E8)
            *(int *)(p + 0xB8) = time;
    } else {
        *(int *)(p + 0xBC) = time;
        if (time - *(int *)(p + 0xB8) > 0x1388)
            motor = 1;
    }
    if (gRjoyMotorEnabled == 0)
        motor = 1;
    if (motor == 0) {
        value = *(int *)(p + 0xB4) + *(unsigned short *)(p + 0xB0);
        *(int *)(p + 0xB4) = value;
        cmd = (value >= 0x8000);
        if (cmd != 0)
            *(int *)(p + 0xB4) = *(int *)(p + 0xB4) - 0x10000;
    } else {
        *(int *)(p + 0xB4) = cmd = 0;
    }
    WPADControlMotor(player, cmd);
}
extern int fn_801282EC(int);
extern int fn_801282F4(void);
extern int fn_801284E8(void *, int);
extern int gWpadAllocHandles[];
extern int wpadAllocTag;
extern int gWpadAllocCount;
#pragma scheduling invalid_target
/* WPAD/WUD allocator callback: request 0x80-byte alignment, select the heap
 * ring, then allocate a `size`-byte block tagged "wpad" and append its handle
 * to gWpadAllocHandles (the block is also left in r3 as the callback result). */
void wpadAlloc(int size) {
    int block;
    fn_801282EC(0x80);
    fn_801282F4();
    block = fn_801284E8(&wpadAllocTag, size);
    gWpadAllocHandles[gWpadAllocCount++] = block;
}
#pragma scheduling on
extern float lbl_805651A0, lbl_805651A4;
extern int fn_8005ED8C(void), fn_8005EE20(void), fn_8005EE7C(void);
extern int fn_80128684(void);
extern int fn_802E30C8(const char *, ...);
__declspec(section ".rodata") extern int lbl_8034D8B4, lbl_8034D8E8;
extern int gWpadAllocHandles[], gWpadAllocCount;
extern int fn_80128658(int, int *);
#pragma push
#pragma scheduling invalid_target
/* Callback on Wpad device disconnect: swap-removes `handle` from the
 * connected-device array (last element fills the gap), frees it via
 * fn_80128658, and always returns 1. */
int wpadFree(unsigned int handle) {
    int matchIndex;
    int *cursor;
    int index;
    int lastValue;
    for (matchIndex = -1, cursor = gWpadAllocHandles, index = 0; index < gWpadAllocCount; cursor++, index++)
        if ((unsigned int)*cursor == handle) matchIndex = index;
    gWpadAllocCount--;
    lastValue = gWpadAllocHandles[gWpadAllocCount];
    gWpadAllocHandles[matchIndex] = lastValue;
    ((void (*)(unsigned int, int))fn_80128658)(handle, lastValue);
    return 1;
}
#pragma pop
/* Reset callback: on a reset event, clear the save-state flag, shut WPAD down, and wait for the shutdown to complete. */ int handleResetEvent(int eventType, int shutdownMode) {
    /* On event type 1, trigger a WPAD shutdown/reconnect sequence and wait until the shutdown completes. */
    if (eventType == 1) {
        fn_80128684();
        if (shutdownMode != 2) {
            fn_8005EE20();
        } else {
            fn_8005ED8C();
        }
        ((void (*)(const char *, ...))fn_802E30C8)((const char *)&lbl_8034D8B4);
        while (fn_8005EE7C() == 4)
            ;
        ((void (*)(const char *, ...))fn_802E30C8)((const char *)&lbl_8034D8E8);
    }
    return 0;
}

/* WPAD sampling callback: forward the sample to the previously installed callback,
 * set the channel's sample-ready flag, then notify the sound connect callback. */
void fn_802E7B6C(int chan, int status) {
    register int channel = chan;
    int result = status;
    unsigned char *record;

    if (0 > channel) {
        goto done;
    }
    if (channel < 4) {
        goto dispatch;
    }
done:
    return;
dispatch:
    if (gPrevSamplingCallbacks[channel] != 0) {
        ((void (*)(int, int))gPrevSamplingCallbacks[channel])(channel, result);
    }
    record = gWiimoteStateTable + channel * 0x638;
    if (result == WPAD_ERR_NO_CONTROLLER) {
        record[0xC4] = 0;
    } else if (result == WPAD_ERR_NONE) {
        record[0xC4] = 1;
    }
    fn_802E6B44(channel, result);
}

#pragma push
#pragma scheduling invalid_target
/* Completion callback for the WPAD command queued by fn_800604E8: clear the controller's pending-command flag at state record +0x631 once the command finishes. */ void rjoyWpadCommandDone(int channel) {
    extern unsigned char lbl_80505978[];

    /* Clear the per-channel flag at +0x631 of this rjoy player record. */
    if (channel < 0)
        return;
    if (channel >= 4)
        return;
    *((unsigned char *)&lbl_80505978 + channel * 0x638 + 0x631) = channel - channel;
}
#pragma pop
void RjoyUpdateMotorEnabled(void) {
    /* Cache the WPAD rumble-motor setting from config into rjoy's motor-enabled flag. */
    gRjoyMotorEnabled = ConfigGetWpadMotorMode();
}

extern void fn_8005EE78();
extern int fn_800569D0(void);
extern void KPADInit(void);
extern int KERNEL_AddResetCallback(int, int);
extern int lbl_8055D22C;
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
/* Initialize WPAD/KPAD input: register callbacks, wait for ready state,
 * install per-controller sampling callbacks, register Joy handler, and mark ready. */
/* Initialize WPAD/KPAD input: install callbacks, wait for WPAD ready, save each channel's prior sampling callback while installing rjoy's, register the reset handler, and mark input ready. */
void fn_802E7C64(void) {
    extern unsigned char lbl_80560009;
    int *callbackSlot;
    int previousCallback;
    int controllerIndex;

    fn_8005EE78(&wpadAlloc, &wpadFree);
    fn_800569D0();
    KPADInit();
    do {
    } while (fn_8005EE7C() != 3);
    callbackSlot = lbl_80507268;
    controllerIndex = 0;
    do {
        previousCallback = WPADSetSamplingCallback(controllerIndex, (int)fn_802E7B6C);
        controllerIndex += 1;
        *callbackSlot = previousCallback;
        callbackSlot += 1;
    } while (controllerIndex < 4);
    KERNEL_AddResetCallback((int)handleResetEvent, (int)&lbl_8055D22C);
    RjoyUpdateMotorEnabled();
    lbl_80560009 = 1;
}
#pragma pop
extern int WPADSetSamplingCallback(int, int);
extern int fn_8006022C(int);
extern int fn_8005ED8C(void);
extern int fn_8005EE7C(void);
extern char lbl_8034D908[];
extern int lbl_8034D8E8;
extern int lbl_80507268[], gWpadAllocHandles[], gWpadAllocCount;
#pragma scheduling invalid_target
/* Reset WPAD controllers and sampling callbacks, wait for shutdown, then free any pending controller handles. */ void fn_802E7D0C(void) {
    int *samplingCallbacks;
    int controllerIndex;
    int shutdownIndex;
    int handleIdx;
    int *controllerHandles;

    /* Reset WPAD controllers and sampling callbacks, wait for shutdown, then
       free any pending controller handles. */
    samplingCallbacks = lbl_80507268;
    controllerIndex = 0;
    do {
        WPADSetSamplingCallback(controllerIndex, *samplingCallbacks);
        controllerIndex++;
        samplingCallbacks++;
    } while (controllerIndex < 4);

    shutdownIndex = 0;
    do {
        fn_8006022C(shutdownIndex);
        shutdownIndex++;
    } while (shutdownIndex < 4);

    fn_8005ED8C();
    fn_802E30C8((const char *)lbl_8034D908);
    while (fn_8005EE7C() == 4) {
    }
    fn_802E30C8((const char *)&lbl_8034D8E8);

    controllerHandles = gWpadAllocHandles;
    handleIdx = 0;
    while (handleIdx < gWpadAllocCount) {
        ((int (*)(int))fn_80128658)(*controllerHandles);
        controllerHandles++;
        handleIdx++;
    }
    gWpadAllocCount = 0;
}
extern double fn_8002EFB0(float, float);
extern float RjoyShapeSteeringAxis(float);
extern float lbl_80565160, lbl_8056517C, lbl_80565180, lbl_80565184, lbl_80565188;
extern float lbl_8056518C, lbl_80565190, lbl_80565194, lbl_80565198;
#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma paired off
#pragma paired_single off
void fn_802E7DDC(void *arg0, void *arg1) {
    typedef struct { float x, y, z; } Vec;
    typedef struct { unsigned int hold, trig, release; Vec acc; float accValue; } Input;
    typedef struct {
        unsigned char pad0[4]; float angle; float tilt; unsigned char pad0C[0x18];
        signed char buttons[8]; unsigned char pad2C[0x18];
        int buttonMask; int config0; int config1; unsigned char pad50[4];
        int flags; float x; float y; float z; signed char valid; unsigned char pad65[7];
        float heading; unsigned char pad70[0x5B4]; int sound;
    } Record;
    register unsigned int temp_r31 = *(volatile unsigned int *)arg1;
    Record *out = (Record *)arg0;
    Input *in = (Input *)arg1;
    float temp_f0, temp_f0_2, var_f1, var_f31, var_f4;
    float ax, ay, vectorX, vectorY, vectorZ;
    double temp_f1;
    int var_r5;

    out->config0 = 0x800F;
    out->valid = *(volatile int *)((char *)arg0 + 0x624) != 0;
    out->config1 = 0xFF;
    var_r5 = 0;
    out->flags |= 0x10;
    if (temp_r31 & 2) var_r5 |= 1;
    if (temp_r31 & 1) var_r5 |= 4;
    if (temp_r31 & 8) var_r5 |= 8;
    if (temp_r31 & 4) var_r5 |= 2;
    ay = *(volatile float *)&in->acc.y;
    ax = *(volatile float *)&in->acc.x;
    out->buttonMask = var_r5;
    temp_f1 = -(float)fn_8002EFB0(ax, -ay);
    var_f31 = (float)temp_f1;
    out->heading = var_f31;
    if (var_f31 > lbl_80565180) var_f31 -= lbl_80565184;
    else if (var_f31 < lbl_80565188) var_f31 += lbl_80565184;
    var_f1 = lbl_80565160;
    temp_f0 = lbl_8056518C * in->acc.z;
    var_f1 = (var_f1 > temp_f0) ? var_f1 : temp_f0;
    var_f1 = (var_f1 > lbl_8056517C) ? var_f1 : lbl_8056517C;
    var_f1 = RjoyShapeSteeringAxis(var_f1);
    var_f4 = lbl_80565160;
    temp_f0_2 = lbl_80565194 * var_f31;
    out->angle = var_f1;
    temp_f0_2 = lbl_80565190 * (temp_f0_2 / lbl_80565180);
    var_f4 = (temp_f0_2 < var_f4) ? temp_f0_2 : var_f4;
    var_f4 = (var_f4 > lbl_8056517C) ? var_f4 : lbl_8056517C;
    vectorX = lbl_80565198 * -in->acc.z;
    vectorY = lbl_80565198 * in->acc.y;
    vectorZ = lbl_80565198 * -in->acc.x;
    out->tilt = var_f4;
    out->buttons[1] = (temp_r31 >> 9) & 1;
    out->buttons[0] = (temp_r31 >> 8) & 1;
    out->buttons[4] = (temp_r31 >> 11) & 1;
    out->buttons[2] = (temp_r31 >> 10) & 1;
    out->buttons[7] = (temp_r31 >> 4) & 1;
    out->buttons[3] = (temp_r31 >> 12) & 1;
    out->buttons[5] = (temp_r31 >> 15) & 1;
    out->flags |= 0x20;
    out->x = vectorX;
    out->y = vectorY;
    out->z = vectorZ;
}
#pragma pop

extern int KPADRead(int, void *, int);
extern int WPADProbe(int, int *);
extern void WPADiClearQueue(int);
extern void WPADiDisableRecalibration(int);
extern unsigned char fn_8005EE80(int);
extern int fn_800604E8(int, int, void *);
extern int fn_802ECC10(void);
extern void HomeMenu_processRequest(void);
extern void HomeMenu_request(void);
extern void KERNEL_Reset(int);
extern void rjoyWpadCommandDone(int);
extern void *memset(void *, int, unsigned int);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802E7FD0(void) {
    extern int lbl_8034D898;
    extern unsigned char lbl_80505978[];
    extern int lbl_80507278[];
    extern unsigned char lbl_8055D230;
    extern unsigned char lbl_80560009;
    extern int lbl_80560010;
    extern int lbl_80560014;

    int now;
    int previous;
    int elapsed;
    int count;
    char *formatBase;
    unsigned char *record;
    int *devices;
    unsigned char *lastState;
    unsigned char *base;
    int channel;
    int probe;
    int readCount;
    register int queueIndex;
    register int changed;
    int current;
    int old;
    int active;
    int result;
    int filtered;
    int timeNow;

    formatBase = (char *)&lbl_8034D898;
    now = KERNEL_GetTimeMs();
    previous = lbl_80560010;
    if (previous < now) {
        elapsed = now - previous;
        if (elapsed < 0xF)
            return;
    }
    count = lbl_80560014;
    lbl_80560010 = now;
    lbl_80560014 = count + 1;
    changed = fn_802ECC10();
    if ((unsigned int)changed != (unsigned int)lbl_80560009) {
        lbl_80560009 = changed;
        queueIndex = 0;
        do {
            if (changed != 0)
                WPADiClearQueue(queueIndex);
            else
                WPADiDisableRecalibration(queueIndex);
            queueIndex += 1;
        } while (queueIndex < 4);
    }

    record = lbl_80505978;
    devices = lbl_80507278;
    base = record;
    channel = 0;
    lastState = &lbl_8055D230;
    do {
        memset(record + 0xC8, 0, 0x550);
        active = 0;
        if (base[0x631] != 0)
            active = 1;
        if (base[0xC69] != 0)
            active = 1;
        if (base[0x12A1] != 0)
            active = 1;
        if (base[0x18D9] != 0)
            active = 1;
        if (active == 0 && now - *(int *)(record + 0x634) > 0x2710) {
            *(int *)(record + 0x634) = now;
            record[0x631] = 1;
            result = fn_800604E8(channel, (int)(record + 0x618), rjoyWpadCommandDone);
            if (result != 0) {
                record[0x631] = 0;
                if (result == -1)
                    memset(record + 0x618, 0, 0x18);
            }
        }

        probe = WPADProbe(channel, devices);
        result = KPADRead(channel, record + 0xC8, 1);
        if (result >= 1 && probe == 0 && record[0xC4] != 0) {
            current = *(signed char *)(record + 0x14D);
            old = *(signed char *)lastState;
            if (current != old) {
                result = (int)RjoyStatusName((signed char)current);
                probe = (int)RjoyStatusName(*(signed char *)lastState);
                ((void (*)(const char *, ...))fn_802E30C8)(
                    formatBase + 0x94, channel, probe, result);
                *lastState = (unsigned char)current;
            }
            if ((signed char)current == 0) {
                if (record[0] == 0) {
                    record[0] = 1;
                    *(int *)(record + 0xB4) = 0;
                    record[0xC5] = 1;
                    ((void (*)(const char *, ...))fn_802E30C8)(
                        formatBase + 0xA8, channel);
                }
                record[0x630] = fn_8005EE80(channel);
                if (fn_802ECC10() == 0)
                    ((void (*)(int, int))fn_802E7920)(channel, 0x3091);
                fn_802E7DDC(record, record + 0xC8);
            }
        } else if (record[0xC4] == 0 && record[0] != 0) {
            record[0] = 0;
            ((void (*)(const char *, ...))fn_802E30C8)(
                formatBase + 0xC0, channel);
        }

        if (record[0x29] != 0) {
            if (record[0xC5] == 0) {
                record[0xC5] = 1;
                HomeMenu_request();
            }
        } else {
            record[0xC5] = 0;
        }

        filtered = 0;
        if (((int (*)(int))fn_802E77B8)(channel) != 0 &&
            record[0x2B] != 0 && record[0x29] != 0 &&
            record[0x27] != 0)
            filtered = 1;
        timeNow = KERNEL_GetTimeMs();
        if (filtered == 0)
            *(int *)(record + 0xC0) = timeNow;
        else if (timeNow - *(int *)(record + 0xC0) > 0x3E8)
            KERNEL_Reset(0);

        channel += 1;
        record += 0x638;
        devices += 1;
        lastState += 1;
    } while (channel < 4);
    HomeMenu_processRequest();
}
#pragma scheduling invalid_target
/* Initializes the 14-entry field-offset/state table with its default index map. */
/* Initialize the 14-entry controller field-offset table with its default index map; entries left at -1 are unavailable fields. */ void rjoyInitFieldOffsets(int *fieldOffsets) {
    fieldOffsets[0] = 3;
    fieldOffsets[1] = 0;
    fieldOffsets[2] = 2;
    fieldOffsets[3] = 1;
    fieldOffsets[4] = 7;
    fieldOffsets[9] = -1;
    fieldOffsets[12] = 4;
    fieldOffsets[13] = -1;
    fieldOffsets[10] = -1;
    fieldOffsets[11] = -1;
    fieldOffsets[5] = 5;
    fieldOffsets[6] = 6;
}
#pragma scheduling on
/* Take one controller's input snapshot: copy the 0x62 bytes at +0x04 of the
 * channel's 0x638-byte record in the Wiimote/controller state table into `out`
 * (+0x00..0x1C are the eight analog readings, +0x20..0x3B the button bytes,
 * +0x40..0x61 the words and error byte), and return the record's status byte at
 * +0x00.  fn_80129400 stores the result into its caller's snapshot at +0x1C. */
/* Copies one controller's 0x62-byte input snapshot (analog values, buttons, words and error byte) from the Wiimote state table into out and returns the record's status byte. */ unsigned char copyControllerInputSnapshot(void *out, int controllerIndex) {
#define gWiimoteStateTable lbl_80505978
    extern unsigned char gWiimoteStateTable[];
    unsigned char *record = gWiimoteStateTable + controllerIndex * 0x638;
    unsigned char *snapshot = (unsigned char *)out;
    unsigned char byte0, byte1;
    unsigned int word0, word1;

    /* the eight analog values, copied as floats */
    *(float *)(snapshot + 0) = *(float *)(record + 4);
    *(float *)(snapshot + 4) = *(float *)(record + 8);
    *(float *)(snapshot + 8) = *(float *)(record + 12);
    *(float *)(snapshot + 12) = *(float *)(record + 16);
    *(float *)(snapshot + 16) = *(float *)(record + 20);
    *(float *)(snapshot + 20) = *(float *)(record + 24);
    *(float *)(snapshot + 24) = *(float *)(record + 28);
    *(float *)(snapshot + 28) = *(float *)(record + 32);
    /* the button bytes, two at a time */
    byte1 = record[36]; byte0 = record[37]; snapshot[32] = byte1; snapshot[33] = byte0;
    byte0 = record[38]; byte1 = record[39]; snapshot[34] = byte0; snapshot[35] = byte1;
    byte0 = record[40]; byte1 = record[41]; snapshot[36] = byte0; snapshot[37] = byte1;
    byte0 = record[42]; byte1 = record[43]; snapshot[38] = byte0; snapshot[39] = byte1;
    byte0 = record[44]; byte1 = record[45]; snapshot[40] = byte0; snapshot[41] = byte1;
    byte0 = record[46]; byte1 = record[47]; snapshot[42] = byte0; snapshot[43] = byte1;
    byte0 = record[48]; byte1 = record[49]; snapshot[44] = byte0; snapshot[45] = byte1;
    byte0 = record[50]; byte1 = record[51]; snapshot[46] = byte0; snapshot[47] = byte1;
    byte0 = record[52]; byte1 = record[53]; snapshot[48] = byte0; snapshot[49] = byte1;
    byte0 = record[54]; byte1 = record[55]; snapshot[50] = byte0; snapshot[51] = byte1;
    byte0 = record[56]; byte1 = record[57]; snapshot[52] = byte0; snapshot[53] = byte1;
    byte0 = record[58]; byte1 = record[59]; snapshot[54] = byte0; snapshot[55] = byte1;
    byte0 = record[60]; byte1 = record[61]; snapshot[56] = byte0; snapshot[57] = byte1;
    byte0 = record[62]; byte1 = record[63]; snapshot[58] = byte0; snapshot[59] = byte1;
    byte1 = *(volatile unsigned char *)(record + 64);
    byte0 = *(volatile unsigned char *)(record + 65);
    snapshot[60] = byte1; snapshot[61] = byte0;
    byte1 = *(volatile unsigned char *)(record + 66);
    byte0 = *(volatile unsigned char *)(record + 67);
    snapshot[62] = byte1; snapshot[63] = byte0;
    /* the words that follow */
    *(unsigned int *)(snapshot + 0x40) = *(unsigned int *)(record + 0x44);
    word1 = *(unsigned int *)(record + 0x48);
    word0 = *(unsigned int *)(record + 0x4c);
    *(unsigned int *)(snapshot + 0x44) = word1;
    *(unsigned int *)(snapshot + 0x48) = word0;
    word0 = *(volatile unsigned int *)(record + 0x50);
    word1 = *(volatile unsigned int *)(record + 0x54);
    *(unsigned int *)(snapshot + 0x4c) = word0;
    *(unsigned int *)(snapshot + 0x50) = word1;
    word0 = *(volatile unsigned int *)(record + 0x58);
    word1 = *(volatile unsigned int *)(record + 0x5c);
    *(unsigned int *)(snapshot + 0x54) = word0;
    *(unsigned int *)(snapshot + 0x58) = word1;
    *(unsigned int *)(snapshot + 0x5c) = *(unsigned int *)(record + 0x60);
    snapshot[0x60] = record[0x64];
    return record[0];
#undef gWiimoteStateTable
}

/* Return byte 0 (the connected flag) of the given controller's record in the
 * Wiimote/controller state table (0x638 bytes per controller). */
/* Return the connected flag (byte 0) for a controller from the Wiimote state table. */ /* Return the connected flag (byte 0) for a controller from the Wiimote state table. */ /* Return the connected flag (byte 0) for a controller from the Wiimote state table. */ unsigned char RjoyIsPadConnected(int controller) {
#define gWiimoteStateTable lbl_80505978
    extern unsigned char gWiimoteStateTable[];
    return gWiimoteStateTable[controller * 0x638];
#undef gWiimoteStateTable
}

/* Center a controller's steering: feed a zero input to the rumble-level converter
 * so it stores the small centering level in that controller's state record. */
void fn_802E8518(int controllerIndex) {
#define RJOY_ZERO lbl_80565164 /* 0.0f */
    fn_802E8528(controllerIndex, RJOY_ZERO, RJOY_ZERO);
#undef RJOY_ZERO
}

extern float lbl_80565164, lbl_80565170, lbl_80565198, lbl_8056519C;
extern unsigned char lbl_80505978[];
/* No-op rjoy hook: called at driver shutdown (with 0 and a driver index) and before
   sound/key setup (with a flag and the AX stack head); empty in this build. */
void fn_802E8524(void) {}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802E8528(int controllerIndex, float level, float unused) {
#define gWiimoteStateTable lbl_80505978
    /* Sets a controller's rumble force: scale the 0..1 level to 16 bits, clamp
     * to 0..0xFFFF and store at +0xB0 of its Wiimote state record (arg 3 unused). */
    extern unsigned char gWiimoteStateTable[];
    float scaledLevel;
    float roundedLevel;
    int result;
    int truncatedValue;
    int lowerClamped;

    scaledLevel = (level - 0.01f) * 65535.0f;
    if (scaledLevel < 0.0f)
        roundedLevel = scaledLevel - 0.5f;
    else
        roundedLevel = 0.5f + scaledLevel;
    truncatedValue = (int)roundedLevel;
    lowerClamped = truncatedValue & ((-truncatedValue & ~truncatedValue) >> 31);
    result = 0xFFFF;
    if (lowerClamped < result)
        result = lowerClamped;
    *(unsigned short *)(gWiimoteStateTable + controllerIndex * 0x638 + 0xB0) = result;
#undef gWiimoteStateTable
}
#pragma pop
/* No-op rjoy stub: would apply the second set of rumble/audio parameters
 * (controller id, two scaled levels and a base level) sent from fn_8017F628;
 * this build leaves it empty. */
void fn_802E85A8(int controllerId, float levelA, float levelB, float baseLevel) {}

/* No-op rjoy stub: would apply rumble/audio parameters (controller id, two
 * scaled levels and a base level) sent from fn_8017F628; this build leaves it empty. */
void fn_802E85AC(int controllerId, float levelA, float levelB, float baseLevel) {
}

/* rjoy stub: reports a fixed controller-type id of 3 regardless of input.
 * Callers compare it against 4 to detect a type-4 controller, which never matches here. */
int fn_802E85B0(void) { return 3; }

extern int lbl_802FAE80[4];
/* Map a controller socket index (0-3) to its display string ("Controller Socket 1" through "Controller Socket 4") from a four-entry pointer table. */ int fn_802E85B8(int socketIndex) {
#define gControllerSocketNames lbl_802FAE80
    int names[4];
    int *cursor = gControllerSocketNames;
    /* Return the "Controller Socket N" string for the given socket index. */
    names[0] = *cursor++;
    names[1] = *cursor++;
    names[2] = *cursor++;
    names[3] = *cursor;
    return names[socketIndex];
#undef gControllerSocketNames
}

#pragma push
#pragma scheduling invalid_target
/* Clamp the controller's latest tilt value into [-0.523599, 0.261799], append it
   to the 16-entry circular history buffer at +0x70, and advance the write index. */
void RjoyUpdateTiltHistory(int padIndex) {
#define gWiimoteStateTable lbl_80505978
#define kTiltHistoryMin lbl_805651A0
#define kTiltHistoryMax lbl_805651A4
    unsigned char *padState;
    float currentTilt;
    float minTilt;
    float clampedTilt;
    int historyIndex;

    clampedTilt = kTiltHistoryMax;
    minTilt = kTiltHistoryMin;
    padState = gWiimoteStateTable + padIndex * 0x638;
    currentTilt = *(float *)(padState + 0x6C);
    clampedTilt = clampedTilt < currentTilt ? clampedTilt : currentTilt;
    clampedTilt = clampedTilt > minTilt ? clampedTilt : minTilt;
    *(float *)(padState + *(int *)(padState + 0x68) * 4 + 0x70) = clampedTilt;
    historyIndex = *(int *)(padState + 0x68);
    historyIndex++;
    *(int *)(padState + 0x68) = historyIndex % 16;
#undef gWiimoteStateTable
#undef kTiltHistoryMin
#undef kTiltHistoryMax
}
#pragma pop
/* No-op rjoy hook from control-scheme setup (passed 1 for schemes 0/2, 0 for 1/3),
   presumably to toggle rumble; empty in this build. */
void fn_802E8664(void) {}

/* lbl_80505978 is the table of 0x638-byte Wiimote/controller state records;
 * byte 0 of a record is its connected flag. */
#define gWiimoteStateTable lbl_80505978
/* Return a pointer to the connected Wiimote's KPAD status block (state record + 0xC8),
 * or NULL when byte 0 of the record says the controller is disconnected. */
void *RjoyGetKpadStatus(int controllerIndex) {
    unsigned char isConnected = gWiimoteStateTable[controllerIndex * 0x638];
    if (isConnected != 0)
        return gWiimoteStateTable + controllerIndex * 0x638 + 0xC8;
    return 0;
}
#undef gWiimoteStateTable

/* lbl_80505978 is the table of 0x638-byte Wiimote/controller state records. */
#define gWiimoteStateTable lbl_80505978
/* Return whether the given controller's ready flag (state record + 0x124) equals 1,
 * used by the countdown UI as a start/readiness gate. */
/* Return whether the controller's ready flag (state record +0x124) equals 1, used by the countdown UI as a start/readiness gate. */ int RjoyIsReady(int controllerIndex) {
    return *(unsigned int *)(gWiimoteStateTable + controllerIndex * 0x638 + 0x124) == 1;
}
#undef gWiimoteStateTable

/* Return the cached WPAD device handle (state record + 0x630) of a controller. */
/* Return the cached WPAD device handle (devHandle, state record +0x630) for a controller. */ unsigned char RjoyGetWpadDeviceHandle(int controllerIndex) {
    unsigned char *stateTable = lbl_80505978;
    return *(stateTable + controllerIndex * 0x638 + 0x630);
}

extern int lbl_802FAE80[4];
extern float lbl_805651A0, lbl_805651A4;
extern unsigned char lbl_80505978[];
extern int fn_8005ED8C(void), fn_8005EE20(void), fn_8005EE7C(void);
extern int fn_80128684(void);
extern int lbl_8034D8B4, lbl_8034D8E8;
extern int fn_80128658(int, int *);
