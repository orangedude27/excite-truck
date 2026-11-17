// rjoy — WPAD joystick layer ("rjoy: waiting for WPAD to shut down").
// Recovered TU window 0x802E77B8..0x802E86CC (see docs/attribution_analysis.md).
// Static-init thunk fn_802E86CC (+ .ctors slot 0x802ED618) remains in
// auto/text_802E86CC_.c pending a promotion pass.
extern void fn_802E6B44(int, int);
extern int lbl_80507268[];
extern unsigned char lbl_80505978[];
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80565160, lbl_80565164, lbl_80565168, lbl_8056516C;
extern float lbl_80565170, lbl_80565174, lbl_80565178;
extern int lbl_8055D208, lbl_8055D210, lbl_8055D218, lbl_8055D220;
__declspec(section ".rodata") extern int lbl_8034D898;
__declspec(section ".rodata") extern int lbl_8034D8A8;
extern int fn_801282EC(int);
extern int fn_801282F4(void);
extern int fn_801284E8(void *, int);
extern int lbl_80507258[];
extern int lbl_8055D224;
extern int lbl_8056000C;
extern unsigned char lbl_80560008;
extern char fn_802E9A24(void);
  void fn_802E8528(int, float, float);
/* Stub for the rjoy input-filter predicate (called with a controller channel):
   always returns 0, so this filter path never marks input as filtered. */
int fn_802E77B8(void) { return 0; }

#pragma push
#pragma dont_inline on
/* Returns the status label string for a WPAD/rjoy controller state code. */
void *fn_802E77C0(int statusCode) {
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
#pragma processor 750
float fn_802E7824(float arg0, float arg1) {
    float c = lbl_80565164;
    float t = lbl_80565160 / (lbl_80565160 - arg1);
    if (arg0 >= c) {
        float v = t * (arg0 - arg1);
        if (v < lbl_80565168) v = lbl_80565168;
        if (v > lbl_80565164) v = lbl_80565164;
        return v;
    } else {
        float v = t * (arg0 + arg1);
        if (v < lbl_80565164) v = lbl_80565164;
        if (v > lbl_8056516C) v = lbl_8056516C;
        return v;
    }
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
#pragma processor 750
/* Shapes one Wii Remote tilt/stick axis into the steering value fn_802E7DDC stores
 * in its input record: the dead-zone response fn_802E7824() is sampled twice, with
 * the axis pushed RJOY_KNEE toward and away from zero, and the two samples averaged,
 * which rounds that response's hard dead-zone corner into a soft knee. The result is
 * then blended toward the squared response v*|v| by RJOY_CURVE_AMOUNT, which is
 * 0.0f, so the output stays linear. */
float fn_802E78A4(float axis) {
#define RJOY_KNEE         lbl_80565174 /* 0.05f: how far each sample is shifted */
#define RJOY_DEAD_ZONE    lbl_80565178 /* 0.1f: dead zone fn_802E7824 rescales past */
#define RJOY_HALF         lbl_80565170 /* 0.5f: weight of the two samples */
#define RJOY_CURVE_AMOUNT lbl_80565164 /* 0.0f: 0 = linear, 1 = v*|v| */
    float up = fn_802E7824(RJOY_KNEE + axis, RJOY_DEAD_ZONE);
    float down = fn_802E7824(axis - RJOY_KNEE, RJOY_DEAD_ZONE);
    float v = RJOY_HALF * (down + up);
    float squared = v * (float)__fabs(v) - v;
    return v + RJOY_CURVE_AMOUNT * squared;
#undef RJOY_KNEE
#undef RJOY_DEAD_ZONE
#undef RJOY_HALF
#undef RJOY_CURVE_AMOUNT
}
#pragma cplusplus off
void fn_802E7920(int arg0) {
    extern int WPADControlMotor(int, int);
    extern int fn_802D9BF0(void);
    extern int fn_802E2C20(void);
    extern unsigned char lbl_80505978[];
    extern unsigned char lbl_80560008;
    struct MotorState { unsigned char pad[0xB0]; unsigned short level; unsigned short padB2; int value, lastLow, lastHigh; };
    struct MotorState *p;
    int player = arg0;
    int time;
    int motor;
    int value;
    int cmd;
    p = (struct MotorState *)(lbl_80505978 + player * 0x638);
    time = fn_802E2C20();
    motor = fn_802D9BF0();
    if (p->level < 0x5000) {
        if (time - p->lastHigh > 0x3E8)
            p->lastLow = time;
    } else {
        p->lastHigh = time;
        if (time - p->lastLow > 0x1388)
            motor = 1;
    }
    if (lbl_80560008 == 0)
        motor = 1;
    if (motor == 0) {
        value = p->value + p->level;
        p->value = value;
        cmd = (value >= 0x8000);
        if (cmd != 0)
            p->value = p->value - 0x10000;
    } else {
        p->value = cmd = 0;
    }
    WPADControlMotor(player, cmd);
}
#pragma cplusplus reset
extern int fn_801282EC(int);
extern int fn_801282F4(void);
extern int fn_801284E8(void *, int);
extern int lbl_80507258[];
extern int lbl_8055D224;
extern int lbl_8056000C;
#pragma scheduling invalid_target
/* Registers a WPAD input handler for the given device and stores its handle. */
void fn_802E7A14(int deviceIndex) {
    int handle;
    fn_801282EC(0x80);
    fn_801282F4();
    handle = fn_801284E8(&lbl_8055D224, deviceIndex);
    lbl_80507258[lbl_8056000C++] = handle;
}
#pragma scheduling on
extern float lbl_805651A0, lbl_805651A4;
extern int fn_8005ED8C(void), fn_8005EE20(void), fn_8005EE7C(void);
extern int fn_80128684(void);
extern int fn_802E30C8(const char *, ...);
__declspec(section ".rodata") extern int lbl_8034D8B4, lbl_8034D8E8;
extern int lbl_80507258[], lbl_8056000C;
extern int fn_80128658(int, int *);
#pragma push
#pragma scheduling invalid_target
/* Removes a value from the lbl_80507258 array by swapping in the last element,
 * notifies fn_80128658 of the removal, and returns 1. */
int fn_802E7A70(unsigned int value) {
    int foundIndex;
    int *entry;
    int i;
    int removedValue;
    for (foundIndex = -1, entry = lbl_80507258, i = 0; i < lbl_8056000C; entry++, i++)
        if ((unsigned int)*entry == value) foundIndex = i;
    lbl_8056000C--;
    removedValue = lbl_80507258[lbl_8056000C];
    lbl_80507258[foundIndex] = removedValue;
    ((void (*)(unsigned int, int))fn_80128658)(value, removedValue);
    return 1;
}
#pragma pop
int fn_802E7AF4(int eventType, int shutdownMode) {
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

void fn_802E7B6C(int arg0, int arg1) {
    register int var_r30 = arg0;
    int var_r31 = arg1;
    unsigned char *record;

    if (0 > var_r30) {
        goto done;
    }
    if (var_r30 < 4) {
        goto dispatch;
    }
done:
    return;
dispatch:
    if (lbl_80507268[var_r30] != 0) {
        ((void (*)(void))lbl_80507268[var_r30])();
    }
    record = lbl_80505978 + var_r30 * 0x638;
    if (var_r31 == -1) {
        record[0xC4] = 0;
    } else if (var_r31 == 0) {
        record[0xC4] = 1;
    }
    fn_802E6B44(var_r30, var_r31);
}

#pragma push
#pragma scheduling invalid_target
void fn_802E7C14(int channel) {
    extern unsigned char lbl_80505978[];

    /* Clear the per-channel flag at +0x631 of this rjoy player record. */
    if (channel < 0)
        return;
    if (channel >= 4)
        return;
    *((unsigned char *)&lbl_80505978 + channel * 0x638 + 0x631) = channel - channel;
}
#pragma pop
#define sRjoyMotorEnabled  lbl_80560008 /* cached WPAD rumble-enabled flag used by the motor driver */
#define getWpadMotorConfig fn_802E9A24  /* config getter: 1 when WPAD rumble is enabled */
void fn_802E7C40(void) {
    /* Cache the WPAD rumble config setting into rjoy's motor-enabled flag. */
    sRjoyMotorEnabled = getWpadMotorConfig();
}

extern void fn_8005EE78();
extern int fn_800569D0(void);
extern void KPADInit(void);
extern int fn_802E2E0C(int, int);
extern int lbl_8055D22C;
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
/* Initialize WPAD/KPAD input: register callbacks, wait for ready state,
 * install per-controller sampling callbacks, register Joy handler, and mark ready. */
void fn_802E7C64(void) {
    extern unsigned char lbl_80560009;
    int *callbackSlot;
    int previousCallback;
    int controllerIndex;

    fn_8005EE78(&fn_802E7A14, &fn_802E7A70);
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
    fn_802E2E0C((int)fn_802E7AF4, (int)&lbl_8055D22C);
    fn_802E7C40();
    lbl_80560009 = 1;
}
#pragma pop
extern int WPADSetSamplingCallback(int, int);
extern int fn_8006022C(int);
extern int fn_8005ED8C(void);
extern int fn_8005EE7C(void);
extern char lbl_8034D908[];
extern int lbl_8034D8E8;
extern int lbl_80507268[], lbl_80507258[], lbl_8056000C;
#pragma scheduling invalid_target
void fn_802E7D0C(void) {
    int *samplingCallbacks;
    int controllerIndex;
    int shutdownIndex;
    int freeIndex;
    int *handles;

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

    handles = lbl_80507258;
    freeIndex = 0;
    while (freeIndex < lbl_8056000C) {
        ((int (*)(int))fn_80128658)(*handles);
        handles++;
        freeIndex++;
    }
    lbl_8056000C = 0;
}
extern double fn_8002EFB0(float, float);
extern float fn_802E78A4(float);
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
    var_f1 = (temp_f0 < var_f1) ? temp_f0 : var_f1;
    var_f1 = (var_f1 > lbl_8056517C) ? var_f1 : lbl_8056517C;
    var_f1 = fn_802E78A4(var_f1);
    var_f4 = lbl_80565160;
    temp_f0_2 = lbl_80565190 * ((lbl_80565194 * var_f31) / lbl_80565180);
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
    out->angle = var_f1;
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
extern void fn_802EC884(void);
extern void fn_802ECBF8(void);
extern void fn_802E2E38(int);
extern void fn_802E7C14(int);
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
    int readCount;
    register int changed;
    register int queueIndex;
    int probe;
    int filtered;
    int current;
    int old;
    int active;
    int result;
    int timeNow;
    formatBase = (char *)&lbl_8034D898;
    now = fn_802E2C20();
    previous = lbl_80560010;
    if (previous < now) {
        elapsed = now - previous;
        if (elapsed < 0xF)
            return;
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
            result = fn_800604E8(channel, (int)(record + 0x618), fn_802E7C14);
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
                result = (int)fn_802E77C0((signed char)current);
                probe = (int)fn_802E77C0(*(signed char *)lastState);
                ((void (*)(const char *, ...))fn_802E30C8)(formatBase + 0x94, channel, probe, result);
                *lastState = (unsigned char)current;
            }
            if ((signed char)current == 0) {
                if (record[0] == 0) {
                    record[0] = 1;
                    *(int *)(record + 0xB4) = 0;
                    record[0xC5] = 1;
                    ((void (*)(const char *, ...))fn_802E30C8)(formatBase + 0xA8, channel);
                }
                record[0x630] = fn_8005EE80(channel);
                if (fn_802ECC10() == 0)
                    ((void (*)(int, int))fn_802E7920)(channel, 0x3091);
                fn_802E7DDC(record, record + 0xC8);
            }
        } else if (record[0xC4] == 0 && record[0] != 0) {
            record[0] = 0;
            ((void (*)(const char *, ...))fn_802E30C8)(formatBase + 0xC0, channel);
        }
        if (record[0x29] != 0) {
            if (record[0xC5] == 0) {
                record[0xC5] = 1;
                fn_802ECBF8();
            }
        } else {
            record[0xC5] = 0;
        }
        filtered = 0;
        if (((int (*)(int))fn_802E77B8)(channel) != 0 && record[0x2B] != 0 && record[0x29] != 0 && record[0x27] != 0)
            filtered = 1;
        timeNow = fn_802E2C20();
        if (filtered == 0)
            *(int *)(record + 0xC0) = timeNow;
        else if (timeNow - *(int *)(record + 0xC0) > 0x3E8)
            fn_802E2E38(0);
        channel += 1;
        record += 0x638;
        devices += 1;
        lastState += 1;
    } while (channel < 4);
    fn_802EC884();
}
#pragma scheduling invalid_target
/* Initializes the 14-entry field-offset/state table with its default index map. */
void fn_802E830C(int *table) {
    table[0] = 3;
    table[1] = 0;
    table[2] = 2;
    table[3] = 1;
    table[4] = 7;
    table[9] = -1;
    table[12] = 4;
    table[13] = -1;
    table[10] = -1;
    table[11] = -1;
    table[5] = 5;
    table[6] = 6;
}
#pragma scheduling on
/* Copy an indexed rjoy input/state record (0x638 bytes per entry) into an output buffer and return its status byte. */
unsigned char fn_802E8364(void *out, int index) {
    extern unsigned char lbl_80505978[];
    unsigned char *src = lbl_80505978 + index * 0x638;
    unsigned char *dst = (unsigned char *)out;
    unsigned char a, b;
    unsigned int x, y;

    *(float *)(dst + 0) = *(float *)(src + 4);
    *(float *)(dst + 4) = *(float *)(src + 8);
    *(float *)(dst + 8) = *(float *)(src + 12);
    *(float *)(dst + 12) = *(float *)(src + 16);
    *(float *)(dst + 16) = *(float *)(src + 20);
    *(float *)(dst + 20) = *(float *)(src + 24);
    *(float *)(dst + 24) = *(float *)(src + 28);
    *(float *)(dst + 28) = *(float *)(src + 32);
    b = src[36]; a = src[37]; dst[32] = b; dst[33] = a;
    a = src[38]; b = src[39]; dst[34] = a; dst[35] = b;
    a = src[40]; b = src[41]; dst[36] = a; dst[37] = b;
    a = src[42]; b = src[43]; dst[38] = a; dst[39] = b;
    a = src[44]; b = src[45]; dst[40] = a; dst[41] = b;
    a = src[46]; b = src[47]; dst[42] = a; dst[43] = b;
    a = src[48]; b = src[49]; dst[44] = a; dst[45] = b;
    a = src[50]; b = src[51]; dst[46] = a; dst[47] = b;
    a = src[52]; b = src[53]; dst[48] = a; dst[49] = b;
    a = src[54]; b = src[55]; dst[50] = a; dst[51] = b;
    a = src[56]; b = src[57]; dst[52] = a; dst[53] = b;
    a = src[58]; b = src[59]; dst[54] = a; dst[55] = b;
    a = src[60]; b = src[61]; dst[56] = a; dst[57] = b;
    a = src[62]; b = src[63]; dst[58] = a; dst[59] = b;
    b = *(volatile unsigned char *)(src + 64);
    a = *(volatile unsigned char *)(src + 65);
    dst[60] = b; dst[61] = a;
    b = *(volatile unsigned char *)(src + 66);
    a = *(volatile unsigned char *)(src + 67);
    dst[62] = b; dst[63] = a;
    *(unsigned int *)(dst + 0x40) = *(unsigned int *)(src + 0x44);
    y = *(unsigned int *)(src + 0x48);
    x = *(unsigned int *)(src + 0x4c);
    *(unsigned int *)(dst + 0x44) = y;
    *(unsigned int *)(dst + 0x48) = x;
    x = *(volatile unsigned int *)(src + 0x50);
    y = *(volatile unsigned int *)(src + 0x54);
    *(unsigned int *)(dst + 0x4c) = x;
    *(unsigned int *)(dst + 0x50) = y;
    x = *(volatile unsigned int *)(src + 0x58);
    y = *(volatile unsigned int *)(src + 0x5c);
    *(unsigned int *)(dst + 0x54) = x;
    *(unsigned int *)(dst + 0x58) = y;
    *(unsigned int *)(dst + 0x5c) = *(unsigned int *)(src + 0x60);
    dst[0x60] = src[0x64];
    return src[0];
}

/* Return byte 0 (the connected flag) of the given controller's record in the
 * Wiimote/controller state table (0x638 bytes per controller). */
unsigned char fn_802E8504(int controllerIndex) {
#define gWiimoteStateTable lbl_80505978
    extern unsigned char gWiimoteStateTable[];
    return gWiimoteStateTable[controllerIndex * 0x638];
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
void fn_802E8524(void) {}

void fn_802E8528(int index, float value, float unused) {
    extern float lbl_80565164, lbl_80565170, lbl_80565198, lbl_8056519C;
    extern unsigned char lbl_80505978[];
    float scaled;
    float rounded;
    int result;
    int converted;
    int magnitude;

    scaled = (value - lbl_80565198) * lbl_8056519C;
    if (scaled < lbl_80565164)
        rounded = scaled - lbl_80565170;
    else
        rounded = lbl_80565170 + scaled;
    converted = (int)rounded;
    magnitude = converted & ((-converted & ~converted) >> 31);
    result = 0xFFFF;
    if (magnitude < result)
        result = magnitude;
    *(unsigned short *)(lbl_80505978 + index * 0x638 + 0xB0) = result;
}
void fn_802E85A8(void) {}

void fn_802E85AC(void) {}

/* rjoy stub: reports a fixed controller-type id of 3 regardless of input.
 * Callers compare it against 4 to detect a type-4 controller, which never matches here. */
int fn_802E85B0(void) { return 3; }

extern int lbl_802FAE80[4];
int fn_802E85B8(int socketIndex) {
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
/* Clamps the latest tilt value (at +0x6C) into [-0.523599, 0.261799] and appends
 * it to the 16-entry circular history buffer at +0x70, advancing the write index. */
void fn_802E85F4(int padIndex) {
#define gWiimoteStateTable lbl_80505978
#define kTiltHistoryMin lbl_805651A0
#define kTiltHistoryMax lbl_805651A4
    extern unsigned char gWiimoteStateTable[];
    extern float kTiltHistoryMin, kTiltHistoryMax;
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
void fn_802E8664(void) {}

/* lbl_80505978 is the table of 0x638-byte Wiimote/controller state records;
 * byte 0 of a record is its connected flag. */
#define gWiimoteStateTable lbl_80505978
/* Return a pointer to the connected Wiimote's KPAD status block (record + 0xC8),
 * or NULL when byte 0 of its state record says the controller is disconnected. */
void *fn_802E8668(int controllerIndex) {
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
int fn_802E8690(int controllerIndex) {
    return *(unsigned int *)(gWiimoteStateTable + controllerIndex * 0x638 + 0x124) == 1;
}
#undef gWiimoteStateTable

/* Return the cached WPAD device handle (state record + 0x630) of a controller. */
unsigned char fn_802E86B4(int controllerIndex) {
    unsigned char *base = lbl_80505978;
    return *(base + controllerIndex * 0x638 + 0x630);
}

extern int lbl_802FAE80[4];
extern float lbl_805651A0, lbl_805651A4;
extern unsigned char lbl_80505978[];
extern int fn_8005ED8C(void), fn_8005EE20(void), fn_8005EE7C(void);
extern int fn_80128684(void);
extern int lbl_8034D8B4, lbl_8034D8E8;
extern int fn_80128658(int, int *);
