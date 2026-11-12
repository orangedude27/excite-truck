// Code of main that had no source file yet: decomp.wtf gave it this one.
extern char lbl_8055EA21;
extern float lbl_8055E3C8;
__declspec(section ".data") extern float lbl_80558DC4;
extern float lbl_80562CB0, lbl_80562CB4, lbl_80562CB8, lbl_80562CBC, lbl_80562CC0, lbl_80562CC4;
extern int fn_80129D18(int, int);
extern float fn_80129DC4(int, float, float);
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EA20;
extern char lbl_804874D4[];
extern char lbl_804874B8[];
extern unsigned char lbl_8055EA22;
extern unsigned char lbl_8055EA22;
extern float lbl_80562CAC;
extern float lbl_80562CC8;
extern float lbl_80562CCC;
extern float lbl_80562CD0;
extern float lbl_80562CD4;
void fn_801E1B30(void);
extern const char lbl_80339878[];
extern const char lbl_80339884[];
int *fn_801E1F44(void);
void *fn_80207848(const char *, int);
#pragma scheduling invalid_target
void fn_801E1874(void) {
    *(volatile int *)lbl_804874D4 = 0;
    *((volatile char *)lbl_804874D4 + 0x18) = 0;
    *((volatile char *)lbl_804874D4 + 4) = 0;
    lbl_8055EA22 = 0;
}
#pragma scheduling on
extern void *fn_802AE414(const char *);
extern int stricmp(const char *, const char *);
extern unsigned char lbl_8055AE60, lbl_8055AE68, lbl_8055AE6C, lbl_8055AE74, lbl_8055AE7C, lbl_8055AE84, lbl_8055AE8C, lbl_8055AE94, lbl_8055AE9C, lbl_8055AEA8;
extern unsigned char lbl_80339860[], lbl_8033986C[];
extern float lbl_80562CA8;

/* Keys of the level's weather parameters, read out of the parameter archive by
 * fn_801E1894 (pooled string literals). */
#define KEY_WEATHER     lbl_8055AE60 /* "weather": the archive object */
#define KEY_FOG         lbl_8055AE68 /* "fog": its value group */
#define KEY_PRECIP      lbl_8055AE6C /* "precip" */
#define VAL_PRECIP_NONE lbl_8055AE74 /* "none" */
#define VAL_PRECIP_RAIN lbl_8055AE7C /* "rain" */
#define VAL_PRECIP_SNOW lbl_8055AE84 /* "snow" */
#define KEY_COLOR       lbl_8055AE8C /* "color" */
#define KEY_START       lbl_8055AE94 /* "start" */
#define KEY_STOP        lbl_8055AE9C /* "stop" */
#define KEY_DENSITY     lbl_8055AEA8 /* "density" */
#define KEY_LIGHTNING   lbl_80339860 /* "lightning" */
#define KEY_IS_NIGHT    lbl_8033986C /* "is_night" */

/* WeatherState::precipType, from the "precip" text. */
#define PRECIP_NONE 0
#define PRECIP_RAIN 1
#define PRECIP_SNOW 2

/* Weather state block: cleared by fn_801E1874, filled by fn_801E1894 and handed
 * out by fn_801E1F44. */
typedef struct WeatherState {
    int precipType;               /* 0x00: PRECIP_* */
    unsigned char isNight;        /* 0x04: the "is_night" value */
    int fogColor;                 /* 0x08: 0xFFRRGGBB */
    float fogStart;               /* 0x0C: "start" */
    float fogStop;                /* 0x10: "stop" */
    float fogDensity;             /* 0x14: "density" */
    unsigned char fogActive;      /* 0x18: the object had a "fog" group */
} WeatherState;

#define gWeatherState  lbl_804874D4 /* the WeatherState above */
#define gWeatherLoaded lbl_8055EA20 /* 0: reload the parameters next time */
#define gLightningOn   lbl_8055EA22 /* lightning flashes with this weather */
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma inline_depth(0)
/* Reads the level's "weather" object out of the parameter archive and fills the
 * weather state block with it: what precipitation falls, whether lightning
 * flashes with it, whether it is night, and the "fog" group's colour, start,
 * stop and density.  fn_801E1F44 calls it the first time the weather is asked
 * for, and fn_801E1D20/fn_801E1D2C clear gWeatherLoaded to make it run again. */
extern "C" int fn_801E1894(void) {
 struct Vec3 { float x,y,z; };
 /* A named group of values inside the parameter object.  This ABI keeps the
  * two destructor slots first, so the first method declared here is the one at
  * vtable+0x8. */
 struct ParamGroup {
 virtual void method_0x8(); virtual void method_0xC(); virtual void method_0x10(); virtual void method_0x14(); virtual void method_0x18(); virtual void method_0x1C(); virtual void method_0x20();
 virtual float get(const char *key); virtual void method_0x28(); virtual void method_0x2C(); virtual void method_0x30();
 virtual Vec3 vector(const char *key); /* returns the three floats in a hidden buffer */
 };
 /* The archive object itself, found by name; hands out its groups and values. */
 struct ParamObject {
 virtual void method_0x8(); virtual int has(const char *key); virtual void method_0x10(); virtual void method_0x14();
 virtual char *text(const char *key, const char *fallback);
 virtual void method_0x1C(); virtual void method_0x20(); virtual void method_0x24(); virtual void method_0x28();
 virtual int flag(const char *key); virtual int val(const char *key, int fallback);
 virtual void method_0x34(); virtual void method_0x38(); virtual void method_0x3C(); virtual void method_0x40(); virtual void method_0x44(); virtual void method_0x48(); virtual void method_0x4C(); virtual void method_0x50(); virtual void method_0x54(); virtual void method_0x58();
 virtual ParamGroup *child(const char *name);
 };
 ParamObject *weather; ParamGroup *fog; char *precip; int r,g,b, clamped, scaled;
 fn_801E1874();
 if (fn_802AE414((const char *)&KEY_WEATHER) != 0) {
  weather=(ParamObject *)fn_802AE414((const char *)&KEY_WEATHER);
  fog=weather->child((const char *)&KEY_FOG);
  precip=weather->text((const char *)&KEY_PRECIP,(const char *)&VAL_PRECIP_NONE);
  if(stricmp(precip,(const char *)&VAL_PRECIP_RAIN)==0) ((WeatherState *)gWeatherState)->precipType=PRECIP_RAIN;
  else if(stricmp(precip,(const char *)&VAL_PRECIP_SNOW)==0) ((WeatherState *)gWeatherState)->precipType=PRECIP_SNOW;
  { int lightning;
  if(weather->has((const char *)KEY_LIGHTNING)!=0)
   lightning=weather->flag((const char *)KEY_LIGHTNING);
  else lightning=(((WeatherState *)gWeatherState)->precipType==PRECIP_RAIN);
  gLightningOn=lightning;
  }
  ((WeatherState *)gWeatherState)->isNight=weather->val((const char *)KEY_IS_NIGHT,0);
  if(fog) {
   const Vec3 &color = fog->vector((const char *)&KEY_COLOR);
   /* Each channel is 255.0f * the colour, clamped to 0..255; x & ((-x & ~x) >>
    * 31) is the branchless max(x, 0). */
   scaled=(int)(lbl_80562CA8*color.x); clamped=scaled&((-scaled&~scaled)>>31); r = clamped < 255 ? clamped : 255;
   scaled=(int)(lbl_80562CA8*color.y); clamped=scaled&((-scaled&~scaled)>>31); g = clamped < 255 ? clamped : 255;
   scaled=(int)(lbl_80562CA8*color.z); clamped=scaled&((-scaled&~scaled)>>31); b = clamped < 255 ? clamped : 255;
   ((WeatherState *)gWeatherState)->fogColor=((r & 255)<<16)|0xff000000|((g & 255)<<8)|(b & 255);
   ((WeatherState *)gWeatherState)->fogStart=fog->get((const char *)&KEY_START);
   ((WeatherState *)gWeatherState)->fogStop=fog->get((const char *)&KEY_STOP);
   ((WeatherState *)gWeatherState)->fogDensity=fog->get((const char *)&KEY_DENSITY);
   ((WeatherState *)gWeatherState)->fogActive=1;
  }
 }
 gWeatherLoaded=1;
}
#pragma pop
extern float __fabsf(float);
extern double __fabs(double);
#pragma scheduling invalid_target
#pragma push
#pragma processor 750
void fn_801E1B30(void) {
    float temp = lbl_8055E3C8;
    char *state = lbl_804874B8;
    int zero;

    zero = 0;
    if (fn_80129D18(4, 0x12C) == 0 || (unsigned char)lbl_8055EA21 != 0) {
        if (*(int *)state == 1 || (unsigned char)lbl_8055EA21 != 0) {
            if (fn_80129D18(4, 0xA) < 6 || (unsigned char)lbl_8055EA21 != 0) {
                *(int *)state = 2;
                *(float *)(state + 0x10) = fn_80129DC4(4, lbl_80562CAC, lbl_80562CB0);
            } else {
                *(int *)state = 3;
                *(float *)(state + 0xC) = temp + fn_80129DC4(4, lbl_80562CB4, lbl_80562CB8);
            }
            *(float *)(state + 8) = fn_80129DC4(4, lbl_80562CB8, lbl_80562CBC);
        } else if (*(float *)(state + 4) > *(float *)(state + 8)) {
            *(float *)(state + 8) = fn_80129DC4(4, *(float *)(state + 4), lbl_80562CC0);
        }
    }

    lbl_8055EA21 = zero;
    if (*(int *)state != 1) {
        float target = *(float *)(state + 8);
        float current = *(float *)(state + 4);
        if ((float)__fabs((double)(target - current)) < lbl_80562CC4) {
            if ((float)__fabs((double)target) <= lbl_80558DC4) {
                goto set_mode;
            }
            *(float *)(state + 8) = lbl_80562CAC;
            goto after_mode;
        set_mode:
            *(int *)state = 1;
        after_mode:
            ;
        }
        *(float *)(state + 4) =
            *(float *)(state + 4) +
            lbl_80562CB4 * (*(float *)(state + 8) - *(float *)(state + 4));
    }

    if (*(void **)(lbl_804874B8 + 0x18) != 0 &&
        *(float *)(state + 0xC) > lbl_80562CAC &&
        temp > *(float *)(state + 0xC)) {
        unsigned char *obj = *(unsigned char **)(lbl_804874B8 + 0x18);
        if (obj[0x19] != 0) {
            obj[0x4C] = 1;
            obj[0x4A] = 0;
        } else {
            obj[0x49] = 1;
            obj[0x4B] = 0;
            obj[0x4A] = 0;
        }
        *(float *)(state + 0xC) = lbl_80562CC8;
    }
}
#pragma pop
#pragma scheduling on
void fn_801E1D20(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D2C(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D38(void) {
    if (*fn_801E1F44() == 1) {
        *(void **)(lbl_804874B8 + 0x14) = fn_80207848(lbl_80339878, 2);
        *(void **)(lbl_804874B8 + 0x18) = fn_80207848(lbl_80339884, 2);
    }
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801E1D9C(void) {
    struct Dummy_801E1D9C_Local {
        virtual void d1(int);
    };
    typedef Dummy_801E1D9C_Local *LocalPtr;
    // try recompute base
    if (*(LocalPtr *)((char *)&lbl_804874B8 + 0x18) != 0) {
        if (*(LocalPtr *)((char *)&lbl_804874B8 + 0x18) != 0) {
            ((LocalPtr)*(LocalPtr *)((char *)&lbl_804874B8 + 0x18))->d1(1);
        }
        *(void **)((char *)&lbl_804874B8 + 0x18) = 0;
    }
    if (*(LocalPtr *)((char *)&lbl_804874B8 + 0x14) != 0) {
        if (*(LocalPtr *)((char *)&lbl_804874B8 + 0x14) != 0) {
            ((LocalPtr)*(LocalPtr *)((char *)&lbl_804874B8 + 0x14))->d1(1);
        }
        *(void **)((char *)&lbl_804874B8 + 0x14) = 0;
    }
}
#pragma pop
void fn_801E1E30(void) {
    int v = lbl_8055EA22;
    *((float *)&lbl_804874B8 + 1) = lbl_80562CAC;
    *(int *)&lbl_804874B8 = (-v | v) >> 31 & 1;
    *((float *)&lbl_804874B8 + 2) = lbl_80562CAC;
    *((float *)&lbl_804874B8 + 3) = lbl_80562CC8;
}

extern int fn_801E1894(void);
extern float lbl_80562CCC;
extern float lbl_80562CD0;
extern float lbl_80562CD4;
extern void fn_801E1B30(void);
void fn_801E1E64(void) {
    void *p = *(void **)(lbl_804874B8 + 0x14);
    if (p != 0) {
        *(unsigned char *)((char *)p + 0x4A) = 0;
        *(unsigned char *)((char *)p + 0x4B) = 1;
        *(unsigned char *)((char *)p + 0x49) = 1;
    }
    if (*(int *)lbl_804874B8 != 0)
        fn_801E1B30();
}

void fn_801E1EA4(void *arg0) {
    void *var_r6;
    int var_r7;
    float c0 = lbl_80562CAC;
    float c1 = lbl_80562CD4;
    float c3 = lbl_80562CD0;
    float c2 = lbl_80562CCC;
    float tmp;
    var_r6 = (char *)arg0 + 4;
    var_r7 = 0;
    goto check;
loop:
    switch (*(int *)&lbl_804874B8) {
    case 2:
        tmp = *(float *)((char *)&lbl_804874B8 + 4);
        *(float *)((char *)var_r6 + 0xD4) = c2 * tmp;
        tmp = *(float *)((char *)&lbl_804874B8 + 4);
        *(float *)((char *)var_r6 + 0xD8) = c3 * tmp;
        tmp = *(float *)((char *)&lbl_804874B8 + 0x10);
        *(float *)((char *)var_r6 + 0xDC) = tmp;
        break;
    case 3:
        *(float *)((char *)var_r6 + 0xD4) = c0;
        tmp = *(float *)((char *)&lbl_804874B8 + 4);
        *(float *)((char *)var_r6 + 0xD8) = c1 * tmp;
        *(float *)((char *)var_r6 + 0xDC) = c0;
        break;
    default:
        *(float *)((char *)var_r6 + 0xD4) = c0;
        *(float *)((char *)var_r6 + 0xD8) = c0;
        *(float *)((char *)var_r6 + 0xDC) = c0;
        break;
    }
    var_r6 = (char *)var_r6 + 0xE0;
    var_r7 += 1;
check:
    if (var_r7 < *(int *)((char *)arg0 + 0x394))
        goto loop;
}

int *fn_801E1F44(void) {
    if ((unsigned char)lbl_8055EA20 == 0)
        fn_801E1894();
    return (int *)&lbl_804874D4;
}

extern char lbl_8055EA21;
extern float lbl_8055E3C8;
extern float lbl_80558DC4;
extern float lbl_80562CB0, lbl_80562CB4, lbl_80562CB8, lbl_80562CBC, lbl_80562CC0, lbl_80562CC4;
extern int fn_80129D18(int, int);
extern float fn_80129DC4(int, float, float);
void fn_801E1F78(void) {
    lbl_8055EA21 = 1;
}
typedef struct { int pad0; float x; float y; float z; char pad10[4]; void *p14; void *p18; } Obj;
