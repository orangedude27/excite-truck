#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/MTX/vec.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80235380(void *);
extern s32 lbl_8055F8BC;
extern s32 lbl_8055F8C0;
extern void fn_802328D4(s32);
extern long loadFontTexture(void *);
extern long ArtSetGet(void *);
extern long lbl_80349CF0[];
extern long lbl_80349CFC[];
void fn_802A7BE8(void) {
    #define sRankFont          lbl_8055F8BC
    #define gCarMarkerArtSet   lbl_8055F8C0
    #define FONT_FILE_NAME     lbl_80349CF0  /* "uifnt_o.gtx" */
    #define ART_SET_NAME       lbl_80349CFC  /* "mapgems.art" */
    /* Load the UI font texture block and the car-marker art set used by the debug markers. */
    sRankFont = loadFontTexture(&FONT_FILE_NAME);
    gCarMarkerArtSet = ArtSetGet(&ART_SET_NAME);
    #undef ART_SET_NAME
    #undef FONT_FILE_NAME
    #undef gCarMarkerArtSet
    #undef sRankFont
}

void fn_802A7C24(void) {
    #define sRankFont          lbl_8055F8BC
    #define gCarMarkerArtSet   lbl_8055F8C0
    #define GTexBlock_release  fn_802328D4
    #define ArtSet_release     fn_80235380
    /* Release the car-marker texture block and art set, then clear both globals. */
    GTexBlock_release(sRankFont);
    sRankFont = 0;
    ArtSet_release((void *)gCarMarkerArtSet);
    gCarMarkerArtSet = 0;
    #undef ArtSet_release
    #undef GTexBlock_release
    #undef gCarMarkerArtSet
    #undef sRankFont
}

/* Empty subsystem init hook, called from fn_80287914's start-up sequence
 * (between fn_802A4C20 and fn_802AB5B8); does nothing in this build. */
void fn_802A7C64(void) {
}

void fn_802A7EEC(void);
void fn_802A7C68(void) {
    #define dbgIsEnabled      fn_801C5B60
    #define dbgGetModeObj     fn_801E87A8
    #define dbgDrawCarMarkers fn_802A7EEC
    /* Draw the car markers only while debug mode is off and the game mode word
     * (the u32 at dbgGetModeObj()+4) is not 0x180304. */
    if ((dbgIsEnabled() == 0) &&
        ((u32)(*(u32 *)((u8 *)dbgGetModeObj() + 4) + 0xFFE80000) != 0x304U)) {
        dbgDrawCarMarkers();
    }
    #undef dbgIsEnabled
    #undef dbgGetModeObj
    #undef dbgDrawCarMarkers
}

extern void *fn_801EA9A0(void);
extern void fn_802C8E70(float *, float *);
extern int fn_802C8FF4(float *, float);
extern void fn_80235CBC(void *, int, float, float, float, float, float);
extern float lbl_805648F0;
extern float lbl_805648F4;
extern float lbl_805648F8;
extern float lbl_805648FC;
extern float lbl_80564900;
extern float lbl_80564904;
extern float lbl_80564908;
extern float lbl_8056490C;
#pragma processor 750
#pragma scheduling invalid_target
/* Project the tracked object to screen space and draw a distance-faded, scaled marker. */
void fn_802A7CA8(void *unused, float distance, int arg1)
{
  unsigned int position[3];
  float screen[3];
  unsigned int xBits;
  void *object;
  float scratch;
  float *scratchPtr;
  float opacity;
  float sizeFactor;
  float size;
  unsigned int colorMask;
  object = *((void **) (((char *) fn_801EA9A0()) + 8));
  xBits = *((unsigned int *) (((char *) object) + 0x24));
  position[1] = *((unsigned int *) (((char *) object) + 0x28));
  scratch = *((float *) (&position[1]));
  position[0] = xBits;
  scratch = (*(scratchPtr = &scratch)) + lbl_805648F0;
  position[2] = *((unsigned int *) (((char *) object) + 0x2C));
  *((float *) (&position[1])) = *scratchPtr;
  fn_802C8E70((float *) position, screen);
  scratch = (distance - lbl_805648F4) / lbl_805648F8;
  opacity = lbl_805648F4;
  opacity = (opacity < (*scratchPtr)) ? (opacity) : (scratch);
  if (1)
  {
    opacity = (opacity > lbl_805648FC) ? (opacity) : (lbl_805648FC);
    opacity = lbl_805648F4 + (opacity * lbl_805648F8);
    colorMask = (((unsigned int) ((int) (lbl_80564900 * opacity))) << 24) | 0x00FFFFFF;
    scratch = (distance - lbl_805648F4) / lbl_805648F8;
    sizeFactor = lbl_805648F4;
    sizeFactor = (sizeFactor < scratch) ? (sizeFactor) : (scratch);
  }
  sizeFactor = (sizeFactor > lbl_805648FC) ? (sizeFactor) : (lbl_805648FC);
  size = lbl_80564904 + (sizeFactor * lbl_80564908);
  if (fn_802C8FF4(screen, lbl_805648FC))
  {
    ((void (*)(void *, int, unsigned int, float, float, float, float, float)) fn_80235CBC)((void *) lbl_8055F8C0, arg1, colorMask, screen[0] - (lbl_8056490C * size), screen[1] - (lbl_8056490C * size), lbl_805648FC, size, size);
  }
}
extern void fn_801E85B4(void);
extern void *fn_802678C0(void);
extern f32 lbl_80564910;
extern f32 lbl_80564914;
extern f32 lbl_80564918;
extern f32 lbl_8056491C;
extern f32 lbl_80564920;
extern char lbl_8055CC30[4];
extern s32 fn_801CF064(void);
extern s32 fn_801EA994(void);
extern s32 fn_801E866C(s32);
extern s32 fn_8027AA48(void);
extern void *fn_8027ABF8(s32);
extern s32 fn_8027AC50(void);
extern s32 fn_8027AC64(void);
extern s32 fn_8027AC80(void);
extern s32 fn_800122B4(u32, void *);
void qsort(void *, u32, u32, s32 (*)(s32 *, s32 *));
void fn_802339A8(s32 a, f32 b, s32 c, f32 d, ...);

/* ---- what fn_802A7EEC draws its markers from ----
   Its cars are the records of the CarMgrEntry table of
   src/auto/text_801EA4C4_.c (fn_801EA9A0(index) is one record); fn_801EA9DC
   refreshes 0x0C-0x40 of a record from the live car object every frame. */
struct CarRecord {
    u8 field00[4];              /* 0x00 */
    s32 index;                  /* 0x04 this record's number */
    void *object;               /* 0x08 the live car object the marker follows */
    s32 field0C;                /* 0x0C */
    s32 rank;                   /* 0x10 place in the race, drawn as "2nd" */
    u8 field14[0x30 - 0x14];
    s32 field30;                /* 0x30 no marker for the car while this is set */
    u8 field34[0xAC - 0x34];
    s32 team;                   /* 0xAC the team entry this car belongs to */
};

/* The live car object behind CarRecord.object: fn_802C8E70 projects the
   position at 0x24 and bit 0x40 of the flags at 0x6E hides its marker. */
struct CarObject {
    u8 field00[0x24];
    u32 xBits;                  /* 0x24 world position, as float bits */
    u32 yBits;                  /* 0x28 */
    u32 zBits;                  /* 0x2C */
    u8 field30[0x6E - 0x30];
    u16 flags;                  /* 0x6E */
};

/* One entry of the global list fn_8027ABF8 searches by key (lbl_804A433C):
   fn_8027AC50 asks about its 0xF0, fn_8027AC64 answers its 0xF8 when that is
   set, and fn_8027AC80 looks its 0xE8 up in the same list. */
struct TeamEntry {
    u8 field00[0xE8];
    s32 team;                   /* 0xE8 */
    s32 mode;                   /* 0xF0 */
    s32 otherTeam;              /* 0xF8 */
};

/* The loaded rank-font handle, the "%s" format and the marker float constants. */
#define sRankFont         lbl_8055F8BC   /* loaded from "uifnt_o.gtx" */
#define STR_PERCENT_S     lbl_8055CC30   /* "%s" */
#define MARKER_ONE        lbl_805648F4   /* 1.0f: clamp low end, and the "1 -" of every fade */
#define MARKER_SLOPE      lbl_805648F8   /* -1.0f: fades fall as the distance grows */
#define MARKER_MARGIN     lbl_805648FC   /* 0.0f: clamp high end, and the on-screen margin */
#define MARKER_ALPHA_255  lbl_80564900   /* 255.0f: what the alpha is scaled to */
#define MARKER_LIFT       lbl_80564910   /* 2.0f: how far above the car the marker sits */
#define MARKER_NEAR_SQ    lbl_80564914   /* 100.0f: squared distance a label starts to fade */
#define MARKER_FAR_SQ     lbl_80564918   /* 7056.0f = 84*84: squared distance it is gone */
#define MARKER_TEXT_SCALE lbl_8056491C   /* 0.42f: the label's scale */
#define MARKER_TEAM_RANGE lbl_80564920   /* 3.0f: team icons fade over 3x MARKER_FAR_SQ */
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
// Comparator: orders objects by squared distance to the manager position (+Y offset), returning -1/1 for qsort.
s32 fn_802A7E08(s32 *arg0, s32 *arg1) {
    unsigned int a[3];
    unsigned int x;
    float dist;
    s32 manager;
    void *obj;
    float f;
    fn_801E85B4();
    manager = (s32)fn_802678C0();
    obj = *(void **)((char *)((void *(*)(int))fn_801EA9A0)(*arg0) + 8);
    x = *(unsigned int *)((char *)obj + 0x24);
    a[1] = *(unsigned int *)((char *)obj + 0x28);
    f = *(float *)&a[1];
    f = f + lbl_80564910;
    a[0] = x;
    a[2] = *(unsigned int *)((char *)obj + 0x2C);
    *(float *)&a[1] = f;
    dist = PSVECSquareDistance((Vec *)a, (Vec *)(manager + 0x24));
    obj = *(void **)((char *)((void *(*)(int))fn_801EA9A0)(*arg1) + 8);
    ((float *)a)[0] = *(float *)((char *)obj + 0x24);
    ((float *)a)[1] = *(float *)((char *)obj + 0x28);
    ((float *)a)[2] = *(float *)((char *)obj + 0x2C);
    ((float *)a)[1] = ((float *)a)[1] + lbl_80564910;
    if (dist > PSVECSquareDistance((Vec *)a, (Vec *)(manager + 0x24))) {
        return -1;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* Markers over the other cars.  fn_802A7C68 calls this every frame: it sorts
   the car records farthest-first (fn_802A7E08), and for every car but the
   local player's own, one whose live object is not flagged and whose record is
   free, projects its position MARKER_LIFT above the ground and draws its place
   in the race ("2nd", fn_800122B4) there in white whose alpha falls from full
   at MARKER_NEAR_SQ to nothing at MARKER_FAR_SQ of squared distance from the
   camera.  In team play a car of the local player's own team also gets the
   team icon of fn_802A7CA8, style 3 when the team is the entry's 0xF8 and
   style 2 when it is the 0xE8 one. */
void fn_802A7EEC(void) {
    u32 worldPos[3];
    char rankText[8];
    f32 screen[3];
    s32 order[8];
    s32 *cursor;
    s32 value;                    /* loop counter, then the label's colour */
    struct CarRecord *car;
    s32 carIndex;
    s32 i;
    u32 xBits;
    struct CarObject *obj;
    f32 norm;
    f32 alpha;
    f32 alphaByte;
    f32 sqDist;
    register f32 lift;            /* f31: MARKER_LIFT */
    register f32 nearSq;          /* f30: MARKER_NEAR_SQ */
    register f32 farSq;           /* f29: MARKER_FAR_SQ */
    register f32 teamRange;       /* f28: MARKER_TEAM_RANGE */
    register f32 alpha255;        /* f27: MARKER_ALPHA_255 */
    register f32 slope;           /* f26: MARKER_SLOPE */
    register f32 zero;            /* f25: MARKER_MARGIN */
    register f32 one;             /* f24: MARKER_ONE */
    f32 teamFade;

    if (fn_801CF064() != 0) {
        return;
    }

    for (value = 0, cursor = order; value < fn_801EA994(); cursor++, value++) {
        *cursor = value;
    }

    qsort(order, fn_801EA994(), 4, fn_802A7E08);

    one = MARKER_ONE;
    cursor = order;
    zero = MARKER_MARGIN;
    lift = MARKER_LIFT;
    nearSq = MARKER_NEAR_SQ;
    farSq = MARKER_FAR_SQ;
    slope = MARKER_SLOPE;
    alpha255 = MARKER_ALPHA_255;
    teamRange = MARKER_TEAM_RANGE;

    for (i = 0; i < fn_801EA994(); cursor++, i++) {
        carIndex = *cursor;
        if (carIndex == fn_801E866C(-1)) {
            continue;
        }

        car = ((void *(*)(int))fn_801EA9A0)(carIndex);
        obj = car->object;
        if (obj->flags & 0x40) {
            continue;
        }
        if (car->field30 != 0) {
            continue;
        }

        xBits = obj->xBits;
        worldPos[1] = obj->yBits;
        norm = *(float *)&worldPos[1];
        worldPos[0] = xBits;
        norm = norm + lift;
        worldPos[2] = obj->zBits;
        *(float *)&worldPos[1] = norm;
        fn_802C8E70((float *)worldPos, screen);

        fn_801E85B4();
        sqDist = PSVECSquareDistance((Vec *)worldPos, (Vec *)((u8 *)fn_802678C0() + 0x24));

        if (fn_802C8FF4(screen, MARKER_MARGIN) != 0) {
            norm = (sqDist - nearSq) / (farSq - nearSq);
            alpha = one;
            alpha = (alpha < norm) ? alpha : norm;
            alpha = (alpha > zero) ? alpha : zero;
            alpha = one + alpha * slope;
            alphaByte = alpha255 * alpha;
            value = ((unsigned int)(int)alphaByte << 24) | 0x00FFFFFF;

            fn_802339A8(sRankFont, screen[0], value, screen[1], MARKER_MARGIN, MARKER_TEXT_SCALE, 0x44, MARKER_ONE, STR_PERCENT_S, fn_800122B4(car->rank, rankText));
        }

        if (fn_8027AA48() != 0) {
            s32 team;
            s32 myTeam;
            norm = (sqDist - farSq) / (teamRange * farSq - farSq);
            alpha = one;
            alpha = (alpha < norm) ? alpha : norm;
            alpha = (alpha > zero) ? alpha : zero;
            team = car->team;
            teamFade = one + alpha * slope;
            myTeam = ((struct CarRecord *)((void *(*)(int))fn_801EA9A0)(fn_801E866C(-1)))->team;

            fn_8027ABF8(myTeam);
            if (fn_8027AC50() != 0) {
                fn_8027ABF8(myTeam);
                if (team == fn_8027AC64()) {
                    fn_802A7CA8((void *)carIndex, teamFade, 3);
                }
            } else {
                fn_8027ABF8(myTeam);
                if (fn_8027AC80() != 0) {
                    if (team == ((struct TeamEntry *)fn_8027ABF8(myTeam))->team) {
                        fn_802A7CA8((void *)carIndex, teamFade, 2);
                    }
                }
            }
        }
    }
}
#pragma pop
