// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct Item8020D2D4Head {
    int a;
    float b;
    float c;
    int d;
} Item8020D2D4Head;

typedef struct Item8020D2D4 {
    Item8020D2D4Head h;
    float e;
    float f;
    unsigned int color;
} Item8020D2D4;

typedef struct Names8020D2D4 {
    char *s[3];
} Names8020D2D4;

#pragma cplusplus on
class Dummy_8020D2D4 {
public:
    virtual void m0(const char *);
    virtual void m1(const char *);
    virtual void m2(const char *);
    virtual Item8020D2D4 *m3(const char *);
};
#pragma cplusplus off

extern Names8020D2D4 lbl_802F9E58;
__declspec(section ".sdata") extern char lbl_8055B630[], lbl_8055B638[], lbl_8055B63C[];
extern float lbl_80563324, lbl_80563328, lbl_80563330, lbl_80563334, lbl_80563338, lbl_8056333C;
extern float lbl_80563340, lbl_80563344, lbl_80563348, lbl_8056334C, lbl_80563350, lbl_80563354, lbl_80563358, lbl_8056335C;
extern void fn_80230B5C(void *);
extern void DrawList_loadMatrix(void *);
extern void setCameraProjection(float, float, float);
extern void fn_800109E4(int, float, float, float, float);
extern char *fn_80131234(const char *);
extern void fn_801473F8(int, const char *, const char *, const char *, ...);
extern void fn_801345D8(char *, int, const char *, ...);
extern char *fn_8000C69C(void);
extern void fn_80230F78(unsigned char *, float *, unsigned int *, int);
extern void fn_80147940(int, Item8020D2D4 *, const char *, int, ...);
extern void fn_80147230(Item8020D2D4 *, const char *, const char *);
extern void fn_801476C4(void);
extern void fn_80011A2C(void);
extern void fn_802C9904(void);
extern int lbl_8055EE74, lbl_8055EE78, lbl_8055EEA0;
extern void *lbl_8055EE7C, *lbl_8055EE80;
extern char lbl_8055EE94;
extern float lbl_8055EE84, lbl_8055EE88, lbl_8055EE8C, lbl_8055EE90, lbl_8055EE98, lbl_8055EE9C;
extern float lbl_8056331C, lbl_80563320;
extern float lbl_8056332C;
__declspec(section ".data") extern float lbl_80558DC4;
__declspec(section ".sdata") extern double lbl_80563360;
extern int KERNEL_GetTimeMs(void);
extern void fn_80012158(void);
extern void fn_8020CF6C(int);
extern double fabs(double);
extern char lbl_8033C6B0[], lbl_8033C6BC[];
extern float lbl_80563318;
extern void fn_8020C908(float);
extern void fn_8000C6E4(void);
extern void fn_80209190(int, float);
extern void fn_80206454(void);
extern void Sound_start(void);
extern void fn_80206444(void);
extern float fn_80209028(void);
extern float fn_8020A5F0(void);
extern int fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80230E90(int);
extern void *fn_802090D4(void *);
extern void *fn_80145E70(void *);
extern void fn_80209110(void *);
#pragma cplusplus on
class Dummy_8020D1C8 {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2(int);
};
#pragma cplusplus off

extern long hasTrackMusicSongs(void); /* trackmusic.c: true when at least one track-music song was found */

/* Menu wrapper for the track-music check hasTrackMusicSongs: nonzero once the dash has
 * found at least one song (its song count is > 0).  The options menu stepper
 * fn_8020D0CC calls it when the selection lands on entry 2 and steps past that
 * entry again when no song is available. */
int fn_8020CF68(void) {
    return hasTrackMusicSongs();
}

#pragma push
#pragma scheduling invalid_target
void fn_8020CF6C(int arg0) {
    if (arg0 == 1)
        goto case_one;
    if (arg0 < 1) {
        if (arg0 >= 0)
            goto case_zero;
        return;
    }
    if (arg0 == 4)
        goto case_four;
    return;

case_zero: {
        float value = lbl_80563318;
        value += lbl_8055EE8C;
        if (value < lbl_8056331C)
            lbl_8055EE8C = lbl_8056331C;
        else
            lbl_8055EE8C = value;
        fn_8020C908(lbl_8055EE8C);
        return;
    }

case_one: {
        float value = lbl_80563318 + lbl_8055EE90;
        if (value < lbl_8056331C)
            lbl_8055EE90 = lbl_8056331C;
        else
            lbl_8055EE90 = value;
        return;
    }

case_four:
    fn_8000C6E4();
    return;
}
#pragma pop
extern float lbl_80563318;
extern void fn_8020A5F8(float);
extern void fn_8020C908(float);
extern void SetEffectsVolume(float);
extern void fn_8013323C(int, char *, float);
extern void fn_800121F0(void);
extern void fn_8000C730(void);
extern void fn_8020D0CC(int);
extern int lbl_8055EE78;
extern float lbl_8055EE8C, lbl_8055EE90, lbl_8055EE98, lbl_8055EE9C;
extern float lbl_80563320;
extern char lbl_8033C690[], lbl_8033C6A0[];
extern void fn_8000C6E4(void);
void fn_8020CFEC(int arg0) {
    float value;
    if (arg0 == 1)
        goto case_one;
    if (arg0 >= 1)
        goto check_four;
    if (arg0 >= 0)
        goto case_zero;
    return;
check_four:
    if (arg0 == 4)
        goto call_four;
    return;
case_zero:
    value = lbl_8055EE8C;
    value -= lbl_80563318;
    if (value > lbl_80563320)
        lbl_8055EE8C = lbl_80563320;
    else
        lbl_8055EE8C = value;
    fn_8020C908(lbl_8055EE8C);
    return;
case_one:
    value = lbl_8055EE90 - lbl_80563318;
    if (value > lbl_80563320)
        lbl_8055EE90 = lbl_80563320;
    else
        lbl_8055EE90 = value;
    return;
call_four:
    fn_8000C730();
}

void fn_8020D06C(void) {
    /* Apply current music/effects volume settings and refresh/persist them. */
    fn_8020A5F8(lbl_8055EE8C);
    fn_8020C908(lbl_8055EE8C);
    SetEffectsVolume(lbl_8055EE90);
    fn_8013323C(4, lbl_8033C690, lbl_8055EE8C);
    fn_8013323C(4, lbl_8033C6A0, lbl_8055EE90);
    fn_800121F0();
}

/* Options-menu stepper: advance the menu selection index (wrapped mod 3). */
void fn_8020D0CC(int arg0) {
    struct { int sum; int num; } t;
    int r;
    t.sum = arg0 + lbl_8055EE78;
    t.num = t.sum + 3;
    r = t.num % 3;
    lbl_8055EE78 = r;
    if (r == 2 && (((int (*)(void))fn_8020CF68)() == 0)) {
        lbl_8055EE78 = (arg0 + lbl_8055EE78 + 3) % 3;
    }
    fn_80230E90(1);
    lbl_8055EE9C = lbl_80563320;
    lbl_8055EE98 = lbl_80563320;
}

/* Initialize the volume options menu: allocate the "volume-dash" mixer
 * volume handle, set it to full volume, clear menu callbacks, and load the
 * "vollyt.val" layout object. */
void fn_8020D178(void) {
    #define s_volMenuHandle lbl_8055EE74
    #define s_volMenuCallback lbl_8055EE7C
    #define s_volMenuDrawCallback lbl_8055EE80
    #define s_volMenuLayout lbl_8055EEA0
    #define VOLUME_FULL lbl_8056331C

    s_volMenuHandle = (int)fn_802090D4(lbl_8033C6B0);
    fn_80209190(s_volMenuHandle, VOLUME_FULL);
    s_volMenuCallback = 0;
    s_volMenuDrawCallback = 0;
    s_volMenuLayout = (int)fn_80145E70(lbl_8033C6BC);

    #undef s_volMenuHandle
    #undef s_volMenuCallback
    #undef s_volMenuDrawCallback
    #undef s_volMenuLayout
    #undef VOLUME_FULL
}

#pragma cplusplus on
/* Tear down the volume panel: destroy its object, release its mixer handle, and clear state. */
extern "C" void fn_8020D1C8(void) {
    struct Dummy_8020D1C8_Local {
        virtual void d1(int);
    };
    Dummy_8020D1C8_Local *panelObject = (Dummy_8020D1C8_Local *)lbl_8055EEA0;
    if (panelObject != 0) {
        if (panelObject != 0) {
            panelObject->d1(1);
        }
        lbl_8055EEA0 = 0;
    }
    fn_80209110(&lbl_8055EE74);
    lbl_8055EE7C = 0;
    lbl_8055EE80 = 0;
}
#pragma cplusplus off
/* Open the volume panel of the options menu (the "volume-dash" one set up by
 * fn_8020D178; fn_8020D29C closes it again).
 *
 * The panel edits the two volumes itself, so it first copies the values the
 * mixer and the music system are using into its editing slots and into a
 * saved pair, then mutes the game: the "volume-dash" mixer handle goes to the
 * minimum, the sound manager is paused and the sound system is asked to
 * rebuild its voices.  The selection returns to the first slider and the
 * "volume just changed" marks are cleared before the panel's transition
 * starts.
 */
void fn_8020D224(void) {
    /* this panel's state, laid out in .sbss (see fn_8020D178/fn_8020D1C8) */
#define volMenuHandle     lbl_8055EE74
#define volMenuSelection  lbl_8055EE78
#define volMusicSaved     lbl_8055EE84
#define volEffectsSaved   lbl_8055EE88
#define volMusic          lbl_8055EE8C
#define volEffects        lbl_8055EE90
#define volMenuActive     lbl_8055EE94
#define volTimeVolumeDn   lbl_8055EE98
#define volTimeVolumeUp   lbl_8055EE9C
#define VOLUME_MIN        lbl_80563320
    float value;

    volMenuActive = 1;
    value = fn_80209028(); /* mixer: the volume the effects play at */
    volEffects = value;
    volEffectsSaved = value;
    value = fn_8020A5F0(); /* music: the volume the music plays at */
    volMusic = value;
    volMusicSaved = value;
    if (fn_80265D64() == 0)
        __AXDSPInitCallback_801769E0(); /* ask the sound system to rebuild */
    fn_80206444();                      /* sound manager: pause */
    fn_80209190(volMenuHandle, VOLUME_MIN); /* mute through "volume-dash" */
    volMenuSelection = 0;
    volTimeVolumeUp = VOLUME_MIN;
    volTimeVolumeDn = VOLUME_MIN;
    fn_80230E90(1); /* start the panel's transition (records the start time) */
#undef volMenuHandle
#undef volMenuSelection
#undef volMusicSaved
#undef volEffectsSaved
#undef volMusic
#undef volEffects
#undef volMenuActive
#undef volTimeVolumeDn
#undef volTimeVolumeUp
#undef VOLUME_MIN
}
void fn_8020D29C(void) {
    float volume = 1.0f;
    int id = lbl_8055EE74;
    lbl_8055EE94 = 0;
    fn_80209190(id, volume);
    fn_80206454();
    Sound_start();
}

#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void fn_8020D2D4(void)
{
  char buf130[0x30];
  char buf110[32];
  char bufF0[32];
  char bufD0[32];
  Item8020D2D4 spB0;
  Item8020D2D4 sp94;
  Item8020D2D4 sp78;
  char buf58[32];
  Item8020D2D4 sp38;
  Item8020D2D4 sp1C;
  unsigned char sp8;
  float spC;
  float f31;
  float f30;
  float f29;
  float f28;
  float f27;
  float f26;
  float f25;
  float f24;
  float f23;
  float f22;
  float f21;
  unsigned int i;
  char *fmt = lbl_8033C690;
  if (lbl_8055EE80 != 0)
  {
    ((void (*)(void)) lbl_8055EE80)();
  }
  fn_80230B5C(buf130);
  DrawList_loadMatrix(buf130);
  setCameraProjection(lbl_8056331C, lbl_80563324, lbl_80563328);
  f21 = lbl_8056332C * ((float) KERNEL_GetTimeMs());
  fn_800109E4(0x7F000000 & 0xFFu, lbl_80563330, lbl_80563334, lbl_80563338, lbl_8056333C);
  if (lbl_8055EEA0 != 0)
  {
    fn_801473F8(lbl_8055EEA0, lbl_8055B630, lbl_8055B638, fn_80131234(fmt + 0x68));
  }
  Names8020D2D4 names = lbl_802F9E58;
  if (lbl_8055EEA0 != 0)
  {
    f24 = lbl_80563320;
    f25 = lbl_8056331C;
    f22 = lbl_80563344;
    f23 = lbl_80563340;
    f26 = lbl_80563348;
    f27 = lbl_80563350;
    f28 = lbl_8056334C;
    f29 = lbl_80563354;
    f30 = lbl_80563358;
    f31 = lbl_8056335C;
    for (i = 0; i < 3; i++)
    {
      int isSel;
      char *name;
      {
        unsigned long z;
        for (z = 0; z < 8; z++)
        {
          ((unsigned int *) buf110)[z] = 0;
        }

      }
      name = fn_80131234(names.s[i]);
      switch (i)
      {
        case 0:
          fn_801345D8(buf110, 0x20, fmt + 0x78, name, (int) (f23 + (f22 * lbl_8055EE8C)));
          break;

        case 1:
          fn_801345D8(buf110, 0x20, fmt + 0x78, name, (int) (f23 + (f22 * lbl_8055EE90)));
          break;

        case 4:
          fn_801345D8(buf110, 0x20, fmt + 0x84, fn_8000C69C());
          break;

        default:
          if (1)
        {
        }
        {
          char *d = buf110;
          int n = 0x20;
          do
          {
            volatile char c = *(name++);
            *(d++) = c;
            do
            {
              if (c == 0)
              {
                break;
              }
            }
            while (0);
          }
          while ((--n) > 0);
          if (n <= 0)
          {
            d[-1] = 0;
          }
          break;
        }

      }

      fn_801345D8(bufF0, 0x20, fmt + 0x90, i & 0xFFFFu);
      fn_801345D8(bufD0, 0x20, lbl_8055B63C, i);
      isSel = i == lbl_8055EE78;
      {
        Item8020D2D4 *it = ((Dummy_8020D2D4 *) lbl_8055EEA0)->m3(bufD0);
        spB0.h = it->h;
        spB0.e = it->e;
        spB0.f = it->f;
        spB0.color = it->color;
      }
      sp8 = 0xFF;
      spC = f24;
      if (isSel)
      {
        fn_80230F78(&sp8, &spC, &spB0.color, 1);
      }
      {
        Item8020D2D4 *it = ((Dummy_8020D2D4 *) (lbl_8055EEA0 & 0xFF))->m3(bufF0);
        if (it != 0)
        {
          sp94.h = it->h;
          sp94.e = it->e;
          sp94.f = it->f;
          sp94.color = it->color;
          if ((i == 2) && (fn_8020CF68() == 0))
          {
            sp94.color = ((sp94.color & 0x00FF0000) | (0x7F000000 & (sp94.color >> 1))) | (((((((((((sp94.color & 0xFFFF) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu);
          }
          fn_80147940(lbl_8055EEA0, &sp94, fmt + 0xA0, (((-isSel) | isSel) >> 31) + 2);
          if (isSel)
          {
            sp78.h = it->h;
            sp78.e = it->e;
            sp78.f = it->f;
            sp78.h.b = sp78.h.b - ((f23 * sp78.e) * spC);
            sp78.h.c = sp78.h.c - ((f23 * sp78.f) * spC);
            sp78.e = sp78.e * (f25 + spC);
            sp78.f = sp78.f * (f25 + spC);
            sp78.color = ((it->color & 0x00FF0000) | (sp8 << 24)) | (it->color & 0xFFFF);
            fn_80147940(lbl_8055EEA0, &sp78, fmt + 0xA0, 1, sp8);
          }
        }
      }
      if (isSel && ((i <= (5 - 1)) & 0xFFFFu))
      {
        int a = 1;
        int b = 1;
        unsigned int c30;
        unsigned int c24;
        switch (i)
        {
          case 0:
            if (((float) __fabs((double) lbl_8055EE8C)) <= lbl_80558DC4)
          {
            a = 0;
          }
            if (f25 == lbl_8055EE8C)
          {
            b = 0;
          }
            break;

          case 1:
            if (((float) __fabs((double) lbl_8055EE90)) <= lbl_80558DC4)
          {
            a = 0;
          }
            if (f25 == lbl_8055EE90)
          {
            b = 0;
          }
            break;

          case 2:
            b = 0;
            a = 0;
            break;

        }

        c30 = -1;
        c24 = -1;
        if (a == 0)
        {
          float f = ((f21 - lbl_8055EE98) - f24) / f26;
          if (f25 < f)
          {
            f = f25;
          }
          if (f <= f24)
          {
            f = f24;
          }
          c30 = (((int) (f28 + (f * f27))) << (24 & 0xFFFFFFFFFFFFFFFF)) | 0xFFFFFF;
        }
        if (b == 0)
        {
          float f = ((f21 - lbl_8055EE9C) - f24) / f26;
          if (f25 < f)
          {
            f = f25;
          }
          if (f <= f24)
          {
            f = f24;
          }
          c24 = (((int) (f28 + (f * f27))) << 24) | 0xFFFFFF;
        }
        fn_801345D8(buf58, 0x20, fmt - (-0xAC), bufD0);
        {
          Item8020D2D4 *it = ((Dummy_8020D2D4 *) lbl_8055EEA0)->m3(buf58);
          if (it != 0)
          {
            float f;
            sp38.h = it->h;
            sp38.e = it->e;
            sp38.f = it->f;
            f = ((f21 - lbl_8055EE98) - f29) / f30;
            sp38.color = it->color;
            if (f25 < f)
            {
              f = f25;
            }
            if (f <= f24)
            {
              f = f24;
            }
            sp38.color = c30;
            sp38.h.b = sp38.h.b - (f24 + (f * f31));
            fn_80147940(lbl_8055EEA0, &sp38, fmt + 0xBC, 1);
          }
        }
        fn_801345D8(buf58, 0x20, fmt + 0xCC, bufD0);
        {
          Item8020D2D4 *it = ((Dummy_8020D2D4 *) lbl_8055EEA0)->m3(buf58);
          if (it != 0)
          {
            float f;
            sp1C.h = it->h;
            sp1C.e = it->e;
            sp1C.f = it->f;
            f = ((f21 - lbl_8055EE9C) - f29) / f30;
            sp1C.color = it->color;
            if (f25 < f)
            {
              f = f25;
            }
            if (f < (f24 + 1))
            {
              f = f24;
            }
            sp1C.color = c24;
            sp1C.h.b = sp1C.h.b + (f24 + (f * f31));
            fn_80147940(lbl_8055EEA0, &sp1C, fmt + 0xE0, 1);
          }
        }
      }
      if ((i == (2 & 0xFFFFFFFFu)) && (fn_8020CF68() == 0))
      {
        spB0.color = ((spB0.color & 0x00FF0000) | ((spB0.color >> 1) & 0x7F000000)) | ((spB0.color & 0xFFFF) & 0xFFu);
      }
      fn_80147230(&spB0, lbl_8055B638, buf110);
    }

    ((Dummy_8020D2D4 *) lbl_8055EEA0)->m1(fmt + 0xF0);
    fn_801476C4();
    if (lbl_8055EE78 == 2)
    {
      ((Dummy_8020D2D4 *) lbl_8055EEA0)->m1(fmt + 0x100);
      fn_801476C4();
    }
  }
  fn_80011A2C();
  fn_802C9904();
}
#pragma cplusplus off
#pragma pop

#pragma dont_inline on
/* Update the volume options menu each frame: apply the current music and SFX volume settings, run the menu's per-frame logic, and if the "Reset/Default" option (index 2) is selected but unavailable, move the selection off it.
 * RealName: unknown (rename_symbol disabled). lbl_8055EE78 = menu selection index, lbl_8055EE8C = music volume, lbl_8055EE90 = SFX/effects volume.
 * Calls: fn_8020C908 set music mixer volume, SetEffectsVolume set SFX volume, fn_800121F0 menu tick/commit, fn_8020CF68 reset-option-available check, fn_8020D0CC change selection. */
void fn_8020DABC(void) {
#define menuSelection lbl_8055EE78
#define musicVolume lbl_8055EE8C
#define sfxVolume lbl_8055EE90
    fn_8020C908(musicVolume);
    SetEffectsVolume(sfxVolume);
    fn_800121F0();
    if (menuSelection == 2 && ((int (*)(void))fn_8020CF68)() == 0)
        fn_8020D0CC(-1);
#undef menuSelection
#undef musicVolume
#undef sfxVolume
}
#pragma scheduling invalid_target
/* Message handler for the volume options menu. Handles up/down navigation
   (0x126/0x128), volume decrease/increase with a short sound (0x125/0x127),
   exit/back (0x58/0xD), re-apply settings (0x53), and ignores unhandled
   messages. Returns 1 if the message was consumed, 0 otherwise. */
int volumeMenuHandleMessage(int msg) {
#define menuSelection   lbl_8055EE78
#define musicVolume     lbl_8055EE8C
#define sfxVolume       lbl_8055EE90
#define volTimeVolumeDn lbl_8055EE98
#define volTimeVolumeUp lbl_8055EE9C
#define menuCallback    lbl_8055EE7C
#define volumeEps       lbl_80558DC4
#define volumeMax       lbl_8056331C
#define volumeRateMs    lbl_8056332C
    int consumed = 1;

    switch (msg) {
    case 0x126:
        fn_8020D0CC(-1);
        break;
    case 0x128:
        fn_8020D0CC(1);
        break;
    case 0x125:
        switch (menuSelection) {
        case 0:
            if (!((float)__fabs(musicVolume) <= volumeEps)) {
                volTimeVolumeDn = volumeRateMs * (float)KERNEL_GetTimeMs();
            } else {
                consumed = 0;
            }
            break;
        case 1:
            if (!((float)__fabs(sfxVolume) <= volumeEps)) {
                volTimeVolumeDn = volumeRateMs * (float)KERNEL_GetTimeMs();
            } else {
                consumed = 0;
            }
            break;
        case 4:
            volTimeVolumeDn = volumeRateMs * (float)KERNEL_GetTimeMs();
            break;
        default:
            consumed = 0;
            break;
        }
        fn_8020CFEC(menuSelection);
        break;
    case 0x127:
        switch (menuSelection) {
        case 0:
            if (musicVolume < volumeMax) {
                volTimeVolumeUp = volumeRateMs * (float)KERNEL_GetTimeMs();
            } else {
                consumed = 0;
            }
            break;
        case 1:
            if (sfxVolume < volumeMax) {
                volTimeVolumeUp = volumeRateMs * (float)KERNEL_GetTimeMs();
            } else {
                consumed = 0;
            }
            break;
        case 4:
            volTimeVolumeUp = volumeRateMs * (float)KERNEL_GetTimeMs();
            break;
        default:
            consumed = 0;
            break;
        }
        fn_8020CF6C(menuSelection);
        break;
    case 0x58:
    case 0xD:
        if (menuCallback != 0 && menuSelection == 2) {
            ((void (*)(int, int))menuCallback)(menuSelection, msg);
            fn_8020D06C();
            break;
        }
        return 0;
    case 0x53:
        if (menuCallback != 0) {
            ((void (*)(int, int))menuCallback)(menuSelection, msg);
            fn_8020D06C();
        }
        break;
    case 0x1B:
    case 0x113:
        consumed = 0;
        break;
    default:
        return 0;
    }
    if (consumed != 0) {
        fn_80012158();
    }
    return 1;
#undef menuSelection
#undef musicVolume
#undef sfxVolume
#undef volTimeVolumeDn
#undef volTimeVolumeUp
#undef menuCallback
#undef volumeEps
#undef volumeMax
#undef volumeRateMs
}
extern void *lbl_8055EE7C;
extern void *lbl_8055EE80;
void AXFXSetHooks_8020DE10(void *callback, void *drawCallback) {
#define s_volMenuCallback lbl_8055EE7C
#define s_volMenuDrawCallback lbl_8055EE80
    /* Install the volume-menu update and draw callbacks (state set up by fn_8020D178). */
    s_volMenuCallback = callback;
    s_volMenuDrawCallback = drawCallback;
#undef s_volMenuCallback
#undef s_volMenuDrawCallback
}

extern char lbl_8055EE94;
/* Returns lbl_8055EE94 (volMenuActive): nonzero while the volume-control menu
 * panel is open. Callers use this to suppress input prompts/updates while it is. */
char fn_8020DE1C(void) {
    return lbl_8055EE94;
}
