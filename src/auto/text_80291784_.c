// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma dont_inline fn_802920D0

#pragma cplusplus on
struct QueryObject_80292114 {
    virtual int f0(int *);
    virtual int f1(int *);
    virtual int f2(int *);
    virtual int f3(int *);
    virtual int f4(int *);
};
struct QueryObject_80291A1C {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual float f8(int *, float);
    virtual void f8_unused();
    virtual void f9_unused();
    virtual float f10(int *, float);
};
struct QueryObject_802917C0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int *getSetting(char *);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual float getFloat(char *, float);
};
struct Manager_802917C0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual float getFinal(char *);
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
    virtual QueryObject_802917C0 *getQuery();
};
#pragma cplusplus reset

extern char lbl_804B4010[];
extern unsigned char lbl_8055F75C;
extern float fn_801EC114(void);
extern float fn_80291784(float, float, float, float);
extern void fn_80291B9C(void *, float *, float);
extern void *fn_802C86DC(void);
__declspec(section ".data") extern int lbl_804B3EC0;
extern unsigned char lbl_8055C920;
extern int fn_802C2C00(int);
extern void fn_802D3BB0(int);
extern void fn_802920D0(void);
extern void fn_80291E64(void *);
#pragma dont_inline on
extern float lbl_80564480;
extern float lbl_805644A0;
extern float lbl_80564484;
extern float lbl_80564490;
extern char lbl_80349158[];
extern int lbl_8055C938;
extern int lbl_8055C948;
extern void *fn_802AE414(int *);
extern int fn_802CAC28(int *, int);
extern int fn_802D39A4(float);
extern float fn_80129DC4(int, float, float);
extern int lbl_8055C924;
extern int lbl_8055C930;
extern int lbl_8055C940;
extern char lbl_80349140[];
extern char lbl_8034914C[];
extern float lbl_80564488;
extern float lbl_8056448C;
extern float lbl_80564494;
extern float lbl_80564498;
extern float lbl_8056449C;
/* Fetch the four current view parameters into scratch slots (DrawList_getViewParams
 * reports tangent, view X, view Y and depth), then return view Y minus 1.0
 * (lbl_80564480). The four incoming float arguments are not used. */
float fn_80291784(float deltaX, float deltaY, float deltaZ, float deltaW) {
    int out0, out1;
    float viewY;
    int out3;
    DrawList_getViewParams(&out0, &out1, &viewY, &out3);
    return viewY - lbl_80564480;
}

#pragma push
#pragma processor 750
#pragma scheduling 603
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" int fn_802917C0(void *arg0, void *arg1, void *arg2) {
    typedef struct { float x, y, z; int id; int unk10; unsigned char flags; unsigned char pad[3]; unsigned int color; float value1, value2; } Entry;
    register void *base = arg0;
    register QueryObject_802917C0 *query_object;
    register Entry *entry;
    register Manager_802917C0 *manager = (Manager_802917C0 *)arg1;
    register int zero = 0;
    register float initial;
    register float result2;
    register float scale;
    register float best;
    register float result1;
    register float result3;
    best = lbl_80564484;
    initial = best;
    scale = lbl_8056449C;
    *(int *)((char *)base + 0x120) = zero;
    goto check_count;
loop:
    query_object = manager->getQuery();
    if (query_object == 0) goto finish;
    result1 = fn_80129DC4(0, lbl_80564488, lbl_8056448C);
    result2 = fn_80129DC4(0, lbl_80564490, lbl_80564494);
    result3 = fn_80129DC4(0, lbl_80564498, lbl_80564494);
    result2 = query_object->getFloat((char *)&lbl_8055C924, result2);
    entry = (Entry *)((char *)base + *(int *)((char *)base + 0x120) * 0x24);
    entry->x = initial; entry->y = initial; entry->z = initial;
    entry->id = fn_802CAC28(query_object->getSetting((char *)&lbl_8055C930), 0);
    entry->unk10 = 0; entry->flags = 0;
    entry->color = ((int)(result2 * scale) << 24) | 0x00FFFFFF;
    entry->value1 = query_object->getFloat((char *)&lbl_8055C938, result1);
    entry->value2 = query_object->getFloat((char *)&lbl_8055C940, result3);
    if (best > entry->value1) best = entry->value1;
    *(int *)((char *)base + 0x120) = *(int *)((char *)base + 0x120) + 1;
check_count:
    if (*(int *)((char *)base + 0x120) < 8) goto loop;
finish:
    *(float *)((char *)base + 0x124) = manager->getFinal(lbl_80349140);
    *(float *)((char *)base + 0x128) = manager->getFinal(lbl_8034914C);
    *(float *)((char *)base + 0x12C) = best;
}
#pragma pop

#pragma scheduling invalid_target
/* Release texture references for each entry in the list and mark slots as invalid. */
void fn_802919AC(void *list) {
    void *base = list;
    void *entry = base;
    int index = 0;

    while (index < *((int *)((char *)base + 0x120))) {
        fn_802CAC54(*((int *)((char *)entry + 0xC)));
        *((int *)((char *)entry + 0xC)) = -1;
        entry = (char *)entry + 0x24;
        index++;
    }
}
#pragma push
#pragma processor 750
void fn_80291A1C(void) {
#define querySun  lbl_8055C948
#define keyRadius lbl_8055C938
#define kBurstTex lbl_80349158
#define gSunFlare lbl_804B4010
#define kZero     lbl_80564484
#define kFadeStep lbl_80564490
#define getFloat  f8
    /* Set up the global sun-flare settings: read the "sun" query's "radius"
     * (default 300), then fill in the burst texture, Z-query effect and fade. */
    struct QueryObject_80291A1C *sunQuery;
    int *flare;
    float radius = 300.0f;
    sunQuery = (struct QueryObject_80291A1C *)fn_802AE414(&querySun);
    if (sunQuery != 0) {
        radius = sunQuery->getFloat(&keyRadius, lbl_805644A0);
    }
    *(float *)&gSunFlare = kZero;
    flare = (int *)&gSunFlare;
    ((float *)flare)[1] = kZero;
    ((float *)flare)[2] = kZero;
    flare[3] = fn_802CAC28((int *)&kBurstTex, 0);
    getTextureSlotTexObj();
    flare[4] = fn_802D39A4(kFadeStep);
    *((unsigned char *)flare + 0x14) = 0;
    flare[6] = -1;
    ((float *)flare)[7] = radius;
#undef getFloat
#undef kFadeStep
#undef kZero
#undef gSunFlare
#undef kBurstTex
#undef keyRadius
#undef querySun
}
#pragma pop
/* Releases the texture and effect object held by the global sun/flare settings and clears their slots. */
void fn_80291AC8(void) {
    int *settings = (int *)&lbl_804B4010;
    fn_802CAC54(settings[3]);
    {
        int effect = settings[4];
        settings[3] = -1;
        fn_802D3A50(effect);
    }
    settings[4] = 0;
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
/* Submit a world-space point to the debug draw list: project it through the current
 * view matrix into the shared scratch at lbl_804B4010 (using depth), test the
 * projected point against the viewport, queue it for drawing, and record the
 * on-screen result as a byte flag in the scratch. */
void fn_80291B14(void *worldPos, float depth)
{
  int ignored;
  signed char visible;
  fn_802C8E70((int *) worldPos, (int *) lbl_804B4010);
  *((float *) (lbl_804B4010 + 8)) = depth;
  ;
  visible = 0;
  if ((fn_802C8FF4((int *) lbl_804B4010, *((float *) (lbl_804B4010 + 0x1C))) != 0) && (fn_802D3A5C(*((int *) (lbl_804B4010 + 0x10)), (int *) lbl_804B4010) != 0))
  {
    visible = 1;
  }
  if (lbl_804B4010)
  {
  }
      *((unsigned char *) (lbl_804B4010 + 0x14)) = visible;
  }
#pragma scheduling on
#pragma opt_common_subs off
void fn_80291B9C(void *arg0, float *__restrict arg1, float arg2) {
    float c, b, a;
    char *entry;
    int i;
    a = arg1[0];
    c = arg1[2];
    b = arg1[1];
    *((float *)((char *)arg0 + 0x130)) = a;
    *((float *)((char *)arg0 + 0x134)) = b;
    *((float *)((char *)arg0 + 0x138)) = c;
    fn_802C8E70(arg1, (char *)arg0 + 0x13C);
    *((float *)((char *)arg0 + 0x144)) = arg2;
    if (fn_802C8FF4((char *)arg0 + 0x13C, *((float *)((char *)arg0 + 0x12C)))) {
        *((unsigned char *)arg0 + 0x148) = *((int *)((char *)arg0 + 0x120)) > 0;
        entry = (char *)arg0;
        i = 0;
        while (i < *((int *)((char *)arg0 + 0x120))) {
            *((unsigned char *)entry + 0x14) = 1;
            entry += 0x24;
            i++;
        }
    } else {
        *((unsigned char *)arg0 + 0x148) = 0;
        entry = (char *)arg0;
        i = 0;
        while (i < *((int *)((char *)arg0 + 0x120))) {
            *((unsigned char *)entry + 0x14) = 0;
            entry += 0x24;
            i++;
        }
    }
}
extern double fabs(double);
extern double sin(double);
extern double cos(double);
extern double fn_8002EFB4(float, double);
extern void fn_802D3BB4(int, float *, float *, float *, unsigned int, float);
extern int lbl_8055CFF0;
extern float lbl_80564494, lbl_805644A4, lbl_805644A8, lbl_805644AC;
extern double lbl_805644B0;
extern float lbl_805644B8, lbl_805644BC;
extern double __fabs(double);
extern double lbl_805644C0;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma ppc_psq_save off
#pragma scheduling invalid_target
void fn_80291C7C(void *arg0, int arg1) {
    struct Vec3 { float x, y, z; };
    struct Vec3 pos = *(struct Vec3 *)arg0;
    float *p = (float *)arg0;
    float a[3], b[3];
    float ratio = 0.0f;
    float target, s, angle, c;
    unsigned int color;
    int amount;
    double d;

    float num, den;

    d = __fabs((double)(pos.x - lbl_80564494 * (float)lbl_8055CFF0));
    num = (float)d - lbl_805644A4 * (float)lbl_8055CFF0;
    den = lbl_80564494 * (float)lbl_8055CFF0 - lbl_805644A4 * (float)lbl_8055CFF0;
    ratio = 0.0f;
    target = num / den;
    pos.z = 1.0f;
    ratio = ratio < target ? target : ratio;
    ratio = ratio > 1.0f ? 1.0f : ratio;

    color = *(unsigned int *)((char *)arg0 + 0x18);
    amount = (int)((float)(color >> 24) * (lbl_80564480 + ratio * lbl_805644A8));
    if (amount <= 0) {
        return;
    }
    color = (amount << 24) | (color & 0xFFFFFF);
    if (arg1 == 0) {
        angle = fn_8002EFB4((pos.x - pos.y) / lbl_805644AC, lbl_805644B0);
        s = sin(angle);
        c = cos(angle);
        a[0] = c;
        a[1] = s;
        a[2] = 1.0f;
        b[0] = s;
        b[1] = -c;
        b[2] = 1.0f;
    } else {
        a[0] = lbl_805644B8;
        a[1] = lbl_805644BC;
        a[2] = 1.0f;
        b[0] = lbl_805644BC;
        b[1] = lbl_805644BC;
        b[2] = 1.0f;
    }
    fn_802D3BB4(*(int *)((char *)&lbl_804B4010 + 0x10), (float *)&pos, a, b, color, p[7]);
}
 #pragma pop

 extern double lbl_805644C0;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80291E64(void *arg0) {
    char *ent;
    int i;
    char *ctx;
    float o[3];
    float d[3];
    double s[3];
    double e[3];
    float v[3];
    float *p;
    float t, w, negd, one, zero, step, scale, k;
    float sx, sy, sz;
    ctx = (char *)arg0;
    p = (float *)fn_802C86DC();
    t = *(float *)(ctx + 0x124);
    o[0] = p[0x24 / 4] + p[0x18 / 4] * t;
    o[1] = p[0x28 / 4] + p[0x1C / 4] * t;
    o[2] = p[0x2C / 4] + p[0x20 / 4] * t;
    d[0] = o[0] - *(float *)(ctx + 0x130);
    d[1] = o[1] - *(float *)(ctx + 0x134);
    d[2] = o[2] - *(float *)(ctx + 0x138);
    PSVECNormalize(d, d);
    w = *(float *)(ctx + 0x128);
    negd = -(w - *(float *)(ctx + 0x124));
    one = lbl_80564480;
    k = *(float *)(ctx + 0x13C) / (float)lbl_8055CFF0;
    zero = lbl_80564484;
    step = one / (float)*(int *)(ctx + 0x120);
    s[0] = o[0] + d[0] * negd;
    s[1] = o[1] + d[1] * negd;
    s[2] = o[2] + d[2] * negd;
    e[0] = s[0] + d[0] * w;
    e[1] = s[1] + d[1] * w;
    e[2] = s[2] + d[2] * w;
    sx = (float)e[0] - (float)s[0];
    sy = (float)e[1] - (float)s[1];
    sz = (float)e[2] - (float)s[2];
    ent = ctx;
    for (i = 0; i < *(int *)(ctx + 0x120); ent += 0x24, i++) {
        scale = (float)i * step + *(float *)(ent + 0x20) * k;
        if (one < scale)
            scale = one;
        if (scale < zero)
            scale = zero;
        v[0] = (float)s[0] + scale * sx;
        v[1] = (float)s[1] + scale * sy;
        v[2] = (float)s[2] + scale * sz;
        fn_802C8E70(v, ent);
        if (*(unsigned char *)(ent + 0x14) != 0 && fn_802C8FF4(ent, lbl_80564484) != 0) {
            fn_802C8C04(*(int *)(ent + 0xC));
            fn_80291C7C(ent, 0);
            DrawList_RestoreNormalMode();
        }
    }
}
#pragma pop

#pragma dont_inline on
void fn_802920D0(void) {
    /* Reset/close the track camera state: release resource slot [3], apply state update, then finalize. */
    int *state = (int *)&lbl_804B4010;
    fn_802C8C04(state[3]);
    fn_80291C7C(state, 1);
    DrawList_RestoreNormalMode();
}

extern void *fn_801E1F44(void);
extern void *fn_80131810(int *);
extern void fn_80131818(void *);
extern int fn_802917C0(void *, void *, void *);
extern void fn_80291A1C(void);
extern int lbl_80349164;
__declspec(section ".data") extern int lbl_80349164;
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80292114(void) {
    void *state;
    void *object;
    int enabled;
    unsigned char active;

    /* Query the "sun" property from flare.val config and cache it when the global state allows. */
    state = fn_801E1F44();
    active = 0;
    enabled = 0;
    if (*((unsigned char *)state + 4) == 0 && *((int *)state) == 0)
        enabled = 1;
    if (enabled != 0)
        active = 1;
    lbl_8055F75C = active;

    if (active != 0) {
        object = fn_80131810(&lbl_80349164);
        if (object != 0) {
            if (((QueryObject_80292114 *)object)->f2(&lbl_8055C948) != 0) {
                int value = ((QueryObject_80292114 *)object)->f0(&lbl_8055C948);
                ((int (*)(void *, void *))fn_802917C0)(&lbl_804B3EC0, (void *)value);
            }
            fn_80131818(object);
        } else {
            int *p = (int *)((char *)&lbl_804B3EC0 + 0x120);
            *p = 0;
        }
        fn_80291A1C();
    }
}
#pragma scheduling on
#pragma cplusplus reset
void fn_802921F4(void) {
    /* If the lens-flare system is active, release its global effects and every effect held in the flare table. */
    #define sFlareActive   lbl_8055F75C
    #define gFlareTable    lbl_804B3EC0
    #define ReleaseGlobal  fn_80291AC8
    #define ReleaseTable   fn_802919AC
    if (sFlareActive != 0) {
        ReleaseGlobal();
        ReleaseTable((int *)&gFlareTable);
    }
    #undef ReleaseTable
    #undef ReleaseGlobal
    #undef gFlareTable
    #undef sFlareActive
}

#pragma processor 750
void fn_8029222C(void) {
    register int *base;
    register char *p;
    register int count;
    register char zero;
    if (lbl_8055F75C == 0) return;
    p = (char *)&lbl_804B3EC0;
    base = (int *)p;
    count = 0;
    zero = 0;
    goto check;
loop:
    p[0x14] = zero;
    p += 0x24;
    count++;
check:
    if (count < base[0x48]) goto loop;
    *((char *)&lbl_804B4010 + 0x14) = 0;
}
/* Debug draw hook gated on two flags: temporarily disable view-range clipping, refresh the track camera and effect overlays when enabled, then restore the previous view-range setting. */ void fn_8029227C(void)
{
  int prevViewRange;
  if (lbl_8055F75C == 0)
  {
    goto done;
  }
  if (lbl_8055C920 == 0)
  {
    if (lbl_8055C920)
    {
      goto done;
    }
    else
    {
      goto done;
    }
  }
  goto body;
  done2:
  goto done;

  body:
  prevViewRange = fn_802C2C00(0);

  if (*((unsigned char *) (lbl_804B4010 + 0x14)))
  {
    fn_802D3BB0(*((int *) (lbl_804B4010 + 0x10)));
  }
  if (*((unsigned char *) (lbl_804B4010 + 0x14)))
  {
    fn_802920D0();
  }
  if (*(((unsigned char *) (&lbl_804B3EC0)) + 0x148))
  {
    fn_80291E64(&lbl_804B3EC0);
  }
  fn_802C2C00(prevViewRange);
  done:
  ;

  ;
}

#pragma push
#pragma processor 750
void fn_8029231C(float *arg0) {
    float *base;
    register float dt;
    volatile float sp[3];
    register float temp_f1;
    register float temp_f2;
    register float temp_f3;
    register float temp_f4;
    /* Advance the sun/flare position by arg0 scaled by frame time when enabled. */
    if (lbl_8055F75C != 0) {
        dt = fn_801EC114();
        base = (float *)fn_802C86DC();
        temp_f4 = arg0[0] * dt;
        temp_f2 = arg0[1] * dt;
        temp_f3 = base[9];
        temp_f3 += temp_f4;
        temp_f1 = arg0[2] * dt;
        sp[0] = temp_f3;
        sp[1] = base[10] + temp_f2;
        sp[2] = base[11] + temp_f1;
        dt = fn_80291784(temp_f1, temp_f2, temp_f3, temp_f4);
        fn_80291B14((float *)sp, dt);
        fn_80291B9C(&lbl_804B3EC0, (float *)sp, dt);
    }
}
#pragma pop
void fn_802923C4(int color) {
    unsigned int packedColor;
    unsigned int *settings;
    unsigned int rgb;
    /* When the lens-flare system is active, set the low 24 bits (RGB) of the
       packed color/intensity word at settings+0x18, keeping its high byte. */
    if (lbl_8055F75C == 0) return;
    settings = (unsigned int *)lbl_804B4010;
    packedColor = settings[6];
    rgb = (unsigned int)color & 0x00FFFFFF;
    settings[6] = (packedColor & 0xFF000000) | rgb;
}

extern float lbl_8056449C;
extern double lbl_805644C8;
__declspec(section ".data") extern int lbl_804B3EC0;
void fn_802923EC(float scale) {
    /* When enabled, clamp scale to [0,1] and update packed alpha bytes for settings and all entries. */
    register int *settingsPtr;
    register int scaledAlpha;
    register int *entryPtr;
    register int entryIndex;
    register unsigned int packedWord;
    register float clampedScale;
    if (lbl_8055F75C != 0) {
        clampedScale = lbl_80564480 < scale ? lbl_80564480 : scale;
        clampedScale = clampedScale > lbl_80564484 ? clampedScale : lbl_80564484;
        settingsPtr = (int *)&lbl_804B4010;
        packedWord = (unsigned int)settingsPtr[6];
        packedWord &= 0xFFFFFFu;
        scaledAlpha = (int)(lbl_8056449C * clampedScale);
        settingsPtr[6] = (int)(((unsigned int)scaledAlpha << 24) | packedWord);
        entryPtr = (int *)&lbl_804B3EC0;
        for (entryIndex = 0; entryIndex < (&lbl_804B3EC0)[0x48]; entryIndex++) {
            packedWord = (unsigned int)entryPtr[6];
            entryPtr[6] = (int)(((unsigned int)(int)(clampedScale * (float)(packedWord >> 24)) << 24) | (packedWord & 0xFFFFFFu));
            entryPtr = (int *)((char *)entryPtr + 0x24);
        }
    }
}

