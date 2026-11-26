// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <stdarg.h>
extern f32 lbl_80560250, lbl_80560254, lbl_80560258, lbl_8056025C, lbl_80560260, lbl_80560264;
extern s32 lbl_80558AA4;
extern s32 lbl_802FC2A8[];
static inline void setRange(s32 *p, s32 a, s32 b) {
    p[1] = a;
    p[2] = b;
}
typedef struct UnkF4F0Style {
    s32 unk_0x00, unk_0x04, unk_0x08, unk_0x0C;
    f32 unk_0x10;
    s32 unk_0x14;
    u32 unk_0x18;
    s32 unk_0x1C;
} UnkF4F0Style;
extern int vsprintf(char *, const char *, va_list);
extern unsigned int strlen(const char *);
__declspec(section ".data") extern s32 lbl_803514A0;


extern f32 lbl_80350EC4[];
extern f32 lbl_80350ED8[];

extern s32 lbl_8055D490;
extern s32 lbl_80558A90;
extern f32 lbl_805602C8;
extern void fn_802344CC(char *, s32, s32, s32, f32, f32, f32);
extern f64 lbl_80560268;
extern f64 lbl_805602D8;
extern s32 fn_8023441C(void);
extern s32 fn_80232B70(s32);
extern f32 fn_80011EDC(void);
extern s32 loadFontTexture(s32);
extern char lbl_802FC414[];
extern s32 lbl_8055D49C;
extern f32 lbl_8056025C;
extern f32 lbl_80560260;
extern f32 lbl_805602C4;
extern f32 lbl_805602C0;
extern f32 fn_80011E54(void);
extern f32 fn_80011E90(void);
extern f32 fn_80011E1C(s32);
extern f32 fn_80011DC0(s32);
extern s32 lbl_8055D498;
extern void fn_80234470(void);
extern void fn_802328D4();

extern s32 lbl_8055D4A8;
extern s32 lbl_8055D484;
extern s32 lbl_8055D488;
extern s32 lbl_802ED758[4];
extern s32 lbl_802ED770[4];
extern f32 lbl_80350F28[][6];

typedef struct Unk0x18 {
    f32 unk_0x00;
    f32 unk_0x04;
    f32 unk_0x08;
    f32 unk_0x0C;
    s32 unk_0x10;
    s32 unk_0x14;
} Unk0x18;
extern Unk0x18 lbl_8034F6B0[0x100];
extern void fn_80010A50(f32, f32, f32, f32, s32, s32);
extern void fn_80010B74(void);
extern void fn_80010B7C(void);
extern void fn_802C8BD0(s32);
extern void DrawList_RestoreNormalMode(void);
extern void fn_80234AEC(void);
extern void *fn_80010BEC(void *);

extern void fn_802346C8(void);

extern s32 lbl_8055D4D0;
extern s32 lbl_8055D4C0;
extern s32 lbl_8055D4C4;
extern s32 lbl_8055D4C8;
extern s32 ArtSetGet();
extern void fn_80235380();
__declspec(section ".data") extern s32 lbl_80350F88;
__declspec(section ".data") extern s32 lbl_80351214;
/* 3-2-1 countdown state: file handle opened by fn_8000F1E0 and released by
 * fn_8000F22C (fn_80235380 drops one reference to it). */
extern s32 lbl_8055D4BC;
/* Any object whose vtable begins with the two destructor slots; the first
 * declared method therefore sits at vtable+0x8. */
typedef struct UnkF22C UnkF22C;
typedef struct UnkF22CVtable {
    void *unk_0x0;
    void *unk_0x4;
    void (*unk_0x8)();
} UnkF22CVtable;
struct UnkF22C {
    UnkF22CVtable *vtable;
};
extern UnkF22C *lbl_8055D4B4; /* Sound for "321low.sfx" (each countdown step) */
extern UnkF22C *lbl_8055D4B8; /* Sound for "321high.sfx" ("GO!") */
  extern void fn_802328D4();
  extern char lbl_802FC414[];
extern s32 loadFontTexture(s32);
extern s32 lbl_80351738[0x54];
extern s32 lbl_8055D494;
extern char lbl_802FC518[];
extern s32 lbl_80558AA4;
extern f32 lbl_80560280;
extern f32 lbl_80560264;
extern void fn_802337A0(f32, s32, f32, s32, f32, f32, s32, f32, const char *, ...);
extern UnkF22C *lbl_8055D4B0;
extern void fn_802C6CF8(s32);
/* Handle of the UI arrow model ("hlparrow.mod") fn_8000F188 loads at startup and
 * fn_8000F1B4 unloads again. */
extern s32 lbl_80558A94;
/* mrModelLoad: load a MODL resource by path (variant/flags select within it) and
 * create its instance; returns the handle mrModelUnload (fn_802C6CF8) releases. */
extern s32 fn_802C6FC0(s32, s32, s32);
  extern void fn_80234470(void);
  extern s32 lbl_8055D498;
  extern s32 lbl_8055D49C;
  extern s32 fn_8023441C(void);
  extern f32 fn_80011EDC(void);
      extern s32 fn_801E85A4(void);
  extern f32 fn_80011E54(void);
  extern f32 fn_80011E90(void);
  extern f32 fn_80011E1C(s32);
  extern f32 fn_80011DC0(s32);
  extern f32 lbl_80560260;
  extern f32 lbl_805602C4;
  extern f32 lbl_805602C0;
extern s32 fn_80207848(void *, s32);
extern void fn_801310B4(void *, s32, s32);
extern s32 fn_80130FE0(s32);
extern char *strcpy(char *, const char *);
extern f32 lbl_805602B8;
extern f32 lbl_805602BC;
extern char lbl_802FC3A4[];
extern f64 lbl_80560278;
extern f64 fn_8002EFB4(f64);
extern void fn_801E7E18(void);
extern char lbl_802FC3DC[];
extern s32 Abend_Panic(void *, ...);
extern char lbl_802FC420[];
extern char lbl_802FC42C[];
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8000F188(const char *modelPath) {
#define mrModelLoad fn_802C6FC0
#define arrowModel  lbl_80558A94
    /* Load one of the UI's models by name -- the startup fn_8000F884 passes the
     * "hlparrow.mod" entry of its string table -- with mrModelLoad, and keep the
     * instance handle this module's shutdown fn_8000F1B4 unloads.  (rename_symbol
     * is refused here, so the suggested name DashUI_LoadArrowModel only lives in
     * this comment.) */
    arrowModel = mrModelLoad((s32)modelPath, 0, 0);
#undef arrowModel
#undef mrModelLoad
}

void fn_8000F1B4(void) {
    // Unload the model held in lbl_80558A94 (via mrModelUnload/fn_802C6CF8)
    // and reset its handle to MODEL_INVALID (-1).
    fn_802C6CF8(lbl_80558A94);
    lbl_80558A94 = -1;
}

/* Initializes the 3-2-1 countdown assets: caches the handle from ArtSetGet and loads the two sound objects. */
void fn_8000F1E0(void) {
    s32 createFlag;
    createFlag = 1;
    lbl_8055D4BC = ArtSetGet();
    lbl_8055D4B4 = (UnkF22C *)fn_80207848(lbl_802FC420, createFlag);
    lbl_8055D4B8 = (UnkF22C *)fn_80207848(lbl_802FC42C, createFlag);
}

#pragma push
#pragma cplusplus on
/* Shut the 3-2-1 countdown down: drop the file handle fn_8000F1E0 opened
 * (fn_80235380 releases a refcounted file handle) and destroy the two Sound
 * objects it made from "321low.sfx" and "321high.sfx".  Each destroy is the
 * virtual destructor (vtable slot 0x8) called with the delete flag, behind
 * the usual double null check. */
extern "C" void fn_8000F22C(void) {
    struct Sound { virtual void destroy(int); };
#define countdownFileHandle lbl_8055D4BC
#define lowSound lbl_8055D4B4
#define highSound lbl_8055D4B8
    void *sound;
    if (countdownFileHandle != 0) {
        fn_80235380(countdownFileHandle);
    }
    countdownFileHandle = 0;
    sound = lowSound;
    if (sound != 0) {
        volatile void *soundCheck = sound;
        if (soundCheck != 0) {
            ((Sound *)sound)->destroy(1);
        }
    }
    sound = highSound;
    if (sound != 0) {
        volatile void *soundCheck = sound;
        if (soundCheck != 0) {
            ((Sound *)sound)->destroy(1);
        }
    }
#undef countdownFileHandle
#undef lowSound
#undef highSound
}
#pragma pop
#pragma cplusplus reset
/* Opens two refcounted archive/file handles via ArtSetGet and stores them in globals
 * lbl_80350F88 and lbl_80351214 (released later by fn_8000F2EC). */
void fn_8000F2A8(s32 fileId0, s32 fileId1) {
    lbl_80350F88 = ArtSetGet(fileId0);
    lbl_80351214 = ArtSetGet(fileId1);
}

/* Releases the two refcounted file handles stored in lbl_80350F88 and lbl_80351214, if set. */
void fn_8000F2EC(void) {
    if (lbl_80350F88 != 0) fn_80235380(lbl_80350F88);
    if (lbl_80351214 != 0) fn_80235380(lbl_80351214);
}

/* Load the resources the two bottom-of-screen banners are drawn from, the same
 * ones fn_8000F384 releases again: the sprite sheet fn_8000FC8C and drawInterludeBanner
 * draw as their end caps, opened as a refcounted archive file handle
 * (ArtSetGet; getPictureWidth / getPictureHeight give one of its frames' size), and the
 * gText font taken twice, once per banner, so each holds a reference of its own
 * (fn_802328D4 drops one).  The names come from the string table at
 * lbl_802FC2A8 -- "interlude.art" and, for both font slots, the "uifnt.gtx" UI
 * font; the caller fn_8000F884 passes that one name twice.
 * (rename_symbol is refused here, so the suggested name
 * DashHelper_LoadBannerResources only lives in this comment.) */
void fn_8000F330(const char *artName, const char *fontName, s32 otherFontName) {
#define INTERLUDE_ART lbl_8055D4C0 /* the "interlude.art" file handle */
#define VALUE_FONT lbl_8055D4C4 /* font of the value banner fn_8000FC8C */
#define INTERLUDE_FONT lbl_8055D4C8 /* font of the interlude banner drawInterludeBanner */
    INTERLUDE_ART = ArtSetGet(artName);
    VALUE_FONT = loadFontTexture((s32)fontName);
    INTERLUDE_FONT = loadFontTexture(otherFontName);
#undef INTERLUDE_ART
#undef VALUE_FONT
#undef INTERLUDE_FONT
}

/* Free the interlude banner resources (art set and two font objects) loaded by fn_8000F330. */
void fn_8000F384(void) {
    if (lbl_8055D4C0 != 0) {
        fn_80235380(lbl_8055D4C0);
        lbl_8055D4C0 = 0;
    }
    if (lbl_8055D4C4 != 0) {
        fn_802328D4(lbl_8055D4C4);
        lbl_8055D4C4 = 0;
    }
    if (lbl_8055D4C8 != 0) {
        fn_802328D4(lbl_8055D4C8);
        lbl_8055D4C8 = 0;
    }
}

void fn_8000F3E8(const char *resourceName) {
    /* Load the ArtSet for the given resource path and cache its handle in the global. */
    lbl_8055D4D0 = ArtSetGet(resourceName);
}

void fn_8000F40C(void) {
    /* Release the global ArtSet created by fn_8000F3E8 and clear its pointer. */
    if (lbl_8055D4D0 != 0) {
        fn_80235380(lbl_8055D4D0);
        lbl_8055D4D0 = 0;
    }
}

extern s32 lbl_8055D4CC;
extern s32 lbl_8055D490;
extern s32 lbl_80558A90;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
extern s32 fn_8023441C(void);
extern s32 fn_80232B70(s32);
extern f32 fn_80011EDC(void);
extern s32 loadFontTexture(s32);
extern char lbl_802FC414[];
extern s32 lbl_8055D49C;
/* Caches the ArtSet named by the resource-name string in r3: ArtSetGet opens
 * it by name and takes a reference, released later by fn_8000F464. */
void fn_8000F440(const char *resourceName) {
    lbl_8055D4CC = ArtSetGet(resourceName);
}

/* Releases the globally cached ArtSet (lbl_8055D4CC) on teardown, if one is loaded. */
void fn_8000F464(void) {
    if (lbl_8055D4CC != 0) {
        fn_80235380(lbl_8055D4CC);
        lbl_8055D4CC = 0;
    }
}

extern s32 fn_80232B70(s32);
extern s32 lbl_8055D490;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
/* The UI's 9-slice frame art set: fn_8000F498 opens it by name, fn_80011278
 * lays its nine pictures as a frame, fn_8000F4BC releases it. */
extern s32 lbl_8055D4D4;
#define frameArtSet lbl_8055D4D4
/**
 * Caches the UI's 9-slice frame art set: opens the ArtSet named by `name`
 * (forwarded in r3 from the UI config table) and stores its handle in
 * frameArtSet for later use by fn_80011278 / fn_8000F4BC.
 */
void fn_8000F498(const char *name) {
    frameArtSet = ArtSetGet(name);
}
#undef frameArtSet

/* Shuts the UI frame art down: drops this module's reference to the 9-slice
 * frame art set that fn_8000F498 cached at startup (ArtSetGet opens it by
 * name, fn_80011278 lays its nine pictures as the frame) and clears the slot,
 * so the art set is freed once nothing else holds it.  Called by the UI module's
 * shutdown fn_8000FB44. */
void fn_8000F4BC(void) {
#define frameArtSet    lbl_8055D4D4
#define ArtSet_release fn_80235380
    if (frameArtSet != 0) {
        ArtSet_release(frameArtSet);
        frameArtSet = 0;
    }
#undef frameArtSet
#undef ArtSet_release
}

extern f64 ceil(f64);
extern char *fn_80131268(const char *);
extern void fn_801345D8(char *, s32, const char *, ...);
extern void fn_80147ABC(void *, void *, const char *, ...);
extern void *fn_801E7E3C(void);
extern void fn_80232928(s32);
extern void fn_80232930(void);
extern void DrawList_saveViewport(void *, s32, s32, s32, s32);
extern void DrawList_restoreViewport(void *, s32);
extern s32 lbl_80558A98;
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern f32 lbl_805602CC, lbl_805602D0, lbl_805602D4;
#pragma cplusplus on
#pragma processor 750
extern "C" void fn_8000F4F0(void)
{
  struct ObjF4F0 {
      virtual void dummy();
      virtual UnkF4F0Style *lookup(const char *);
  };
  char *strBase;
  char text[32];
  char buffer[20];
  UnkF4F0Style a;
  UnkF4F0Style b;
  s32 scope[4];
  f32 time;
  f32 scale;
  s32 number;
  u32 alpha;
  s32 count;
  char *src;
  char *dst;
  UnkF4F0Style *p;
  UnkF4F0Style *q;
  s32 b4;
  s32 b8;
  strBase = (char *) lbl_802FC2A8;
  DrawList_saveViewport(scope, 0, 0, lbl_8055CFF0, lbl_8055CFF4);
  time = *((f32 *) (((u8 *) fn_801E7E3C()) + 0x10));
  number = -1;
  *((s32 *) (text + 0)) = 0;
  *((s32 *) (text + 4)) = 0;
  *((s32 *) (text + 8)) = 0;
  *((s32 *) (text + 12)) = 0;
  *((s32 *) (text + 16)) = 0;
  *((s32 *) (text - (-20))) = 0;
  *((s32 *) (text + 24)) = 0;
  *((s32 *) (text + 28)) = 0;
  scale = lbl_80560280;
  alpha = 255;
  if (!(time > lbl_805602CC))
  {
    if ((time > lbl_805602D0) && (time <= lbl_805602CC))
    {
      number = (count = (s32) ((f32) ceil(time)));
      if (number != lbl_80558A98)
      {
        u8 *obj = (u8 *) lbl_8055D4B4;
        obj[0x49] = 1;
        obj[0x4B] = 0;
        obj[0x4A] = 0;
      }
      scale = ((f32) number) - time;
      fn_801345D8(buffer, 20, strBase + 0x190, number);
      src = fn_80131268(buffer);
      dst = text;
      count = 32;
      while ((*(dst++) = *(src++)) != 0)
      {
        if ((--count) <= 0)
        {
          dst[-1] = 0;
          break;
        }
      }

    }
    else
      if ((-time) < lbl_805602B8)
    {
      f32 x;
      f32 y;
      number = 0;
      if (lbl_80558A98 != 0)
      {
        u8 *obj = (u8 *) lbl_8055D4B8;
        obj[0x49] = 1;
        obj[0x4B] = 0;
        obj[0x4A] = 0;
      }
      x = ((-time) - lbl_8056025C) / lbl_80560264;
      x = (lbl_80560264 < x) ? (lbl_80560264) : (x);
      x = (x > lbl_80560280) ? (x) : (lbl_80560280);
      scale = lbl_80560280 + (x * lbl_80560264);
      y = lbl_805602B8;
      y = y - (-time);
      if (y < lbl_805602D4)
      {
        alpha = (s32)(((f32)alpha) * (y / lbl_805602D4));
      }
      src = fn_80131268(strBase + 0x1A4);
      dst = text;
      count = 32;
      while ((*(dst++) = *(src++)) != 0)
      {
        if ((--count) <= 0)
        {
          dst[-1] = 0;
          break;
        }
      }

    }
  }
  lbl_80558A98 = number;
  if (lbl_8055D4B0)
  {
    p = ((ObjF4F0 *)lbl_8055D4B0)->lookup(strBase + 0x1B8);
    q = ((ObjF4F0 *)lbl_8055D4B0)->lookup(strBase + 0x1C4);
    if (p && q)
    {
      a.unk_0x00 = p->unk_0x00;
      a.unk_0x04 = p->unk_0x04;
      a.unk_0x08 = p->unk_0x08;
      a.unk_0x0C = p->unk_0x0C;
      a.unk_0x10 = p->unk_0x10;
      a.unk_0x14 = p->unk_0x14;
      a.unk_0x18 = p->unk_0x18;
      a.unk_0x1C = p->unk_0x1C;
      b.unk_0x00 = q->unk_0x00;
      b4 = q->unk_0x04;
      b8 = q->unk_0x08;
      b.unk_0x04 = b4;
      b.unk_0x08 = b8;
      b.unk_0x0C = q->unk_0x0C;
      b.unk_0x10 = q->unk_0x10;
      b.unk_0x14 = q->unk_0x14;
      b.unk_0x18 = q->unk_0x18;
      b.unk_0x1C = q->unk_0x1C;
      (&a)->unk_0x18 = (alpha << 24) | (a.unk_0x18 & 0xFFFFFF);
      b.unk_0x18 = a.unk_0x18;
      fn_80232928(-1);
      fn_80147ABC(&a, &b, (const char *) (&lbl_80558AA4), text, scale);
      fn_80232930();
    }
  }
  DrawList_restoreViewport(scope, -1);
}
#pragma cplusplus reset
#pragma use_lmw_stmw off
void fn_8000F884(void) {
    extern s32 fn_800167F4(void);
    extern s32 fn_80145E70(s32);
    extern s32 fn_80235FD8(s32);
    extern f32 getPictureWidth(s32, s32);
    extern f32 getPictureHeight(s32, s32);
    extern void fn_802E30C8(const char *, ...);
    extern char lbl_802FC5CC[];
    extern char lbl_802FC590[];
    extern s32 lbl_80558AA0;
    extern s32 lbl_80558A9C;
    extern f32 lbl_8055D4D8;
    extern f32 lbl_805602E8, lbl_805602EC, lbl_805602F0, lbl_805602F4;
    s32 *tab = lbl_802FC2A8;
    char *base = (char *)tab;
    s32 count;
    s32 id;
    s32 handle;
    s32 len;
    f32 c;
    u8 *p;
    s32 n;

    ((void (*)(s32))fn_8000F188)((s32)(base + 0x1D0));
    ((void (*)(s32, s32))fn_8000F2A8)((s32)(base + 0x1E0), (s32)(base + 0x1F0));
    ((void (*)(s32))fn_8000F1E0)((s32)(base + 0x200));
    ((void (*)(s32, s32, s32))fn_8000F330)((s32)(base + 0x20C), (s32)(base + 0x21C), (s32)(base + 0x21C));
    ((void (*)(s32))fn_8000F440)((s32)(base + 0x228));
    ((void (*)(s32))fn_8000F3E8)((s32)(base + 0x238));
    ((void (*)(s32))fn_8000F498)((s32)(base + 0x244));
    lbl_8055D494 = loadFontTexture((s32)(base + 0x250));
    lbl_8055D4B0 = (UnkF22C *)fn_80145E70((s32)(base + 0x260));
    count = fn_800167F4();
    if (count > 1) {
        id = lbl_80558AA0;
        handle = ArtSetGet(id);
        lbl_80351738[0x14] = handle;
        if (handle == 0) {
            fn_802E30C8(lbl_802FC5CC, id);
        } else if (fn_80235FD8(handle) < 4) {
            fn_802E30C8(lbl_802FC590, id);
            fn_80235380(lbl_80351738[0x14]);
        } else {
            lbl_80351738[0x15] = 0x66000000;
            len = fn_80235FD8(lbl_80351738[0x14]);
            n = 8;
            if (len < 8) n = len;
            p = (u8 *)lbl_80351738 + n * 8;
            while (p -= 8, n-- > 0) {
                *(f32 *)(p + 0x10) = getPictureWidth(lbl_80351738[0x14], n);
                *(f32 *)(p + 0x14) = getPictureHeight(lbl_80351738[0x14], n);
            }
            c = lbl_805602E8;
            ((f32 *)lbl_80351738)[0] = c;
            ((f32 *)lbl_80351738)[1] = c;
            ((f32 *)lbl_80351738)[3] = c;
            ((f32 *)lbl_80351738)[2] = c;
        }
    } else {
        id = lbl_80558A9C;
        handle = ArtSetGet(id);
        lbl_80351738[0x14] = handle;
        if (handle == 0) {
            fn_802E30C8(lbl_802FC5CC, id);
        } else if (fn_80235FD8(handle) < 4) {
            fn_802E30C8(lbl_802FC590, id);
            fn_80235380(lbl_80351738[0x14]);
        } else {
            lbl_80351738[0x15] = 0x66000000;
            len = fn_80235FD8(lbl_80351738[0x14]);
            n = 8;
            if (len < 8) n = len;
            p = (u8 *)lbl_80351738 + n * 8;
            while (p -= 8, n-- > 0) {
                *(f32 *)(p + 0x10) = getPictureWidth(lbl_80351738[0x14], n);
                *(f32 *)(p + 0x14) = getPictureHeight(lbl_80351738[0x14], n);
            }
            c = lbl_805602EC;
            ((f32 *)lbl_80351738)[0] = c;
            ((f32 *)lbl_80351738)[1] = c;
            ((f32 *)lbl_80351738)[3] = c;
            ((f32 *)lbl_80351738)[2] = c;
        }
    }
    if (count > 2) {
        lbl_8055D4D8 = lbl_805602F0;
    } else {
        lbl_8055D4D8 = lbl_805602F4;
    }
    if (count == 1) {
        tab[1] = 0;
        tab[2] = 4;
    } else {
        tab[1] = 3;
        tab[2] = 7;
    }
    lbl_80558A98 = -1;
}
#pragma use_lmw_stmw on

#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8000FB44(void) {
    struct Obj {
        virtual void v0(int);
    };
    s32 handle;

    /* Release dash/UI resources (audio handle, font context, UI object) and shut down submodules. */
    handle = lbl_80351738[0x14];
    if (handle != 0) {
        ((void (*)(s32))fn_80235380)(handle);
    }
    lbl_80351738[0x14] = 0;
    fn_802328D4(lbl_8055D494, lbl_80351738);
    lbl_8055D494 = 0;
    if (lbl_8055D4B0 != 0) {
        if (lbl_8055D4B0 != 0) {
            ((Obj *)lbl_8055D4B0)->v0(1);
        }
    }
    lbl_8055D4B0 = 0;
    fn_8000F40C();
    fn_8000F464();
    fn_8000F384();
    fn_8000F1B4();
    fn_8000F2EC();
    fn_8000F22C();
    fn_8000F4BC();
}
#pragma cplusplus reset
#pragma scheduling on
extern void fn_8000F4F0(void);
void fn_8000FBE4(void) {
    /* Tail-call thunk forwarding to the countdown/start-timer renderer
     * (fn_8000F4F0), invoked by race setup once the remaining time drops
     * below its display threshold. */
    fn_8000F4F0();
}

#pragma scheduling invalid_target
void fn_8000FBE8(f32 arg0, f32 arg1, f32 arg2) {
    extern f32 getPictureHeight(s32, s32);
    extern s32 lbl_8055D4CC;
    extern f32 lbl_80560290, lbl_805602F8, lbl_805602FC;
    extern void fn_80010E94(f32, f32, f32, f32, s32, s32);
    f32 temp_f3;
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f28;

    temp_f28 = arg1 + lbl_80560264;
    temp_f3 = getPictureHeight(lbl_8055D4CC, 4) * arg2;
    temp_f31 = lbl_805602F8 + temp_f3;
    temp_f29 = lbl_80560290 + (temp_f28 + (temp_f3 * lbl_8056025C));
    temp_f30 = arg0 - lbl_80560290;
    ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(lbl_8055D4D0, 4, temp_f30, temp_f29, temp_f31, temp_f31);
    ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(lbl_8055D4D0, 5, temp_f30 + temp_f31, temp_f29, lbl_805602FC, temp_f31);
}

#pragma push
#pragma processor 750
#pragma paired_single off
void fn_8000FC8C(s32 value, s32 arg1) {
    extern s32 fn_80232B70(s32);
    extern f32 fn_80011E54(void);
    extern f32 fn_80011E70(void);
    extern f32 getPictureWidth(s32, s32);
    extern f32 getPictureHeight(s32, s32);
    extern void fn_80010E94(f32, f32, f32, f32, s32, s32);
    extern void fn_802337A0(f32, s32, f32, s32, f32, f32, s32, f32, const char *, ...);
    extern f32 lbl_80560300;
    extern f32 lbl_80560304;
    extern f32 lbl_805602B0;
    f32 textScale;
    f32 baseX;
    f32 baseY;
    f32 iconWidth;
    f32 iconX;
    f32 iconY;
    f32 temp_f1;
    f32 totalIconWidth;

    /* Draw the value text with a shadow, and optional icon/background pieces. */
    temp_f1 = (f32)fn_80232B70(lbl_8055D4C4);
    textScale = lbl_80560300 / temp_f1;
    baseX = fn_80011E70();
    baseY = fn_80011E54();
    if (lbl_8055D4C0 != 0) {
        iconWidth = getPictureWidth(lbl_8055D4C0, 0);
        totalIconWidth = iconWidth + getPictureWidth(lbl_8055D4C0, 1);
        iconX = baseX - (lbl_8056025C * totalIconWidth);
        iconY = (baseY - lbl_80560304) + (lbl_8056025C * getPictureHeight(lbl_8055D4C0, 0));
        ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(lbl_8055D4C0, 0, iconX, iconY, lbl_80560280, lbl_80560280);
        ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(lbl_8055D4C0, 1, iconX + iconWidth, iconY, lbl_80560280, lbl_80560280);
    }
    fn_802337A0(lbl_805602B0 + baseX, lbl_8055D4C4, baseY - lbl_805602B0,
                0xFF000000, lbl_80560280, textScale, 0xC, lbl_80560264,
                (const char *)&lbl_80558AA4, value);
    fn_802337A0(baseX, lbl_8055D4C4, baseY, -1,
                lbl_80560280, textScale, 0xC, lbl_80560264,
                (const char *)&lbl_80558AA4, value);
}

extern void fn_800109E4(s32, f32, f32, f32, f32);
extern f32 lbl_80560308, lbl_8056030C, lbl_80560310, lbl_80560314;
extern f32 lbl_805602B0, lbl_805602E8;

/* Resources fn_8000F330 loads for the interlude banner (names from the string
 * table at lbl_802FC2A8: "interlude.art" and the "uifnt.gtx" UI font). */
#define INTERLUDE_ART lbl_8055D4C0 /* "interlude.art" sprite sheet, 0 when absent */
#define INTERLUDE_FONT lbl_8055D4C8 /* "uifnt.gtx" */
#define INTERLUDE_END_CAP 2 /* its frame drawn at both ends of the banner */

/* Layout of the banner, all .sdata2 floats: the text is scaled to
 * INTERLUDE_TEXT_HEIGHT pixels and centred INTERLUDE_BOTTOM_GAP above the
 * screen's bottom edge, inside a panel INTERLUDE_PANEL_HEIGHT tall with
 * INTERLUDE_SIDE_PAD of room past the text on each side. */
#define INTERLUDE_TEXT_HEIGHT lbl_80560308 /* 27.0f */
#define INTERLUDE_BOTTOM_GAP lbl_805602E8 /* 13.0f */
#define INTERLUDE_SIDE_PAD lbl_8056030C /* 7.0f */
#define INTERLUDE_EXTRA_WIDTH lbl_80560310 /* 14.0f, i.e. 2 * INTERLUDE_SIDE_PAD */
#define INTERLUDE_PANEL_HEIGHT lbl_80560314 /* 26.0f, i.e. 2 * INTERLUDE_BOTTOM_GAP */
#define TEXT_SHADOW_OFFSET lbl_805602B0 /* 2.0f: how far above the base line the text sits */
#define ONE_PIXEL lbl_80560264 /* 1.0f: the shadow's pixel offset, and the text draw's default spacing */
#define HALF_PIXEL lbl_8056025C /* 0.5f */
#define DEFAULT_SCALE lbl_80560280 /* 0.0f: "unscaled" for the sprite draw fn_80010E94 */
#define COLOR_PANEL 0x66000000 /* black at 40% alpha */
#define COLOR_TEXT_SHADOW 0xFF000000 /* opaque black */
#define COLOR_TEXT (-1) /* 0xFFFFFFFF: opaque white */
#define TEXT_ALIGN_CENTER 0x14 /* applyTextAlignmentOffset bits 0x4|0x10: centre the text on the pen point */
#pragma push
#pragma processor 750
#pragma paired_single off
#pragma scheduling on
/* Draw one line of interlude text as a banner at the bottom of the screen: a
 * translucent black panel with the "interlude.art" end caps on both ends, and the
 * message (a "%s" printf of one argument, measured with fn_8023293C) scaled to
 * INTERLUDE_TEXT_HEIGHT pixels and centred on the screen's middle, white over a
 * black shadow. Called from fn_801C6B70 while an interlude message is pending.
 * (rename_symbol is refused here, so the suggested name DashHelper_DrawInterludeBanner
 * only lives in this comment; the original took a second, unused argument.) */
void drawInterludeBanner(const char *text) {
    extern f32 fn_80011E60(void);
    extern f32 fn_80011E70(void);
    extern f32 fn_8023293C(s32, f32);
    extern f32 getPictureHeight(s32, s32);
    extern f32 getPictureWidth(s32, s32);
    extern void fn_80010E94(f32, f32, f32, f32, s32, s32);
    /* Scale the UI font so a line is INTERLUDE_TEXT_HEIGHT pixels tall, and lay
     * the text out centred on the screen's horizontal middle. */
    f32 textScale = INTERLUDE_TEXT_HEIGHT / (f32)fn_80232B70(INTERLUDE_FONT);
    f32 centerX = fn_80011E70();
    f32 baseY = INTERLUDE_BOTTOM_GAP + fn_80011E60();
    f32 textWidth = textScale * ((f32 (*)(s32, const char *, f32))fn_8023293C)(
        INTERLUDE_FONT, text, ONE_PIXEL);
    f32 left = centerX - (HALF_PIXEL * textWidth);

    /* Translucent panel behind the whole banner, then the end caps hanging off
     * both ends of the text, vertically centred on the banner's middle. */
    fn_800109E4(COLOR_PANEL, left - INTERLUDE_SIDE_PAD,
                INTERLUDE_BOTTOM_GAP + baseY, INTERLUDE_EXTRA_WIDTH + textWidth,
                INTERLUDE_PANEL_HEIGHT);
    if (INTERLUDE_ART != 0) {
        f32 capY = baseY + (HALF_PIXEL * getPictureHeight(INTERLUDE_ART, INTERLUDE_END_CAP));
        ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(
            INTERLUDE_ART, INTERLUDE_END_CAP,
            (left - getPictureWidth(INTERLUDE_ART, INTERLUDE_END_CAP)) - INTERLUDE_SIDE_PAD,
            capY, DEFAULT_SCALE, DEFAULT_SCALE);
        ((void (*)(s32, s32, f32, f32, f32, f32))fn_80010E94)(
            INTERLUDE_ART, INTERLUDE_END_CAP,
            INTERLUDE_SIDE_PAD + (left + textWidth),
            capY, DEFAULT_SCALE, DEFAULT_SCALE);
    }
    {
        /* Black copy one pixel down and right of the white text; both are drawn
         * centred on their pen point (TEXT_ALIGN_CENTER). */
        f32 textY = TEXT_SHADOW_OFFSET + baseY;
        fn_802337A0(ONE_PIXEL + centerX, INTERLUDE_FONT,
                    textY - ONE_PIXEL, COLOR_TEXT_SHADOW,
                    DEFAULT_SCALE, textScale, TEXT_ALIGN_CENTER, ONE_PIXEL,
                    (const char *)&lbl_80558AA4, text);
        fn_802337A0(centerX, INTERLUDE_FONT, textY, COLOR_TEXT,
                    DEFAULT_SCALE, textScale, TEXT_ALIGN_CENTER, ONE_PIXEL,
                    (const char *)&lbl_80558AA4, text);
    }
}
#pragma pop

#pragma push
#pragma processor 750
void fn_8000FF88(s32 arg0, s32 arg1, const char *fmt, f32 farg0, f32 farg1, f32 farg2, ...) {
    #pragma scheduling invalid_target
    char buffer[0x200];
    va_list args;

    /* Format a printf-style string and draw it with fn_802344CC, scaling text by lbl_805602C8 (0.733333). */
    va_start(args, farg2);
    vsprintf(buffer, fmt, args);
    fn_802344CC(buffer, arg0, arg1, 0, farg1, farg2, lbl_805602C8 * farg0);
}
#pragma pop

#pragma scheduling on
extern f32 lbl_805602B0;
extern void fn_802344CC(char *, s32, s32, s32, f32, f32, f32);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Formats text and draws it twice: once offset/dimmed as a shadow pass, then at the given position. */
void fn_80010074(s32 arg0, s32 arg1, const char *fmt, f32 farg0, f32 farg1, f32 farg2, ...) {
    char textBuffer[0x200];
    va_list args;
    va_start(args, farg2);
    vsprintf(textBuffer, fmt, args);
    fn_802344CC(textBuffer, arg0 & 0xFF000000, arg1, 0,
                lbl_805602B0 + farg1, farg2 - lbl_805602B0, lbl_805602C8 * farg0);
    fn_802344CC(textBuffer, arg0, arg1, 0, farg1, farg2, lbl_805602C8 * farg0);
}
#pragma scheduling on
#pragma pop

extern void fn_80232BA4(char *, s32, s32, s32, f32, f32, f32, f32, f32);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80010188(s32 color, s32 lineHeight, const char *fmt, f32 scale, f32 x, f32 y, ...) {
    char textBuffer[0x200];
    va_list args;

    /* Format a string and draw it at (x, y) using the given color and scaled text size. */
    va_start(args, y);
    vsprintf(textBuffer, fmt, args);
    fn_80232BA4(textBuffer, lbl_8055D490, color, lineHeight,
                x, y, lbl_805602C8 * scale,
                lbl_80560280, lbl_80560264);
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Formats text with vsprintf and, if the dash text font/context is set (lbl_8055D494), draws it via fn_802337A0 at (value, scale/last) with the given color/fontId; warns on oversized buffer. */
void fn_8001027C(s32 color, s32 fontId, const char *fmt, f32 y, f32 x, f32 scale, ...) {
    char buffer[0x200];
    va_list args;

    if (lbl_8055D494 != 0) {
        va_start(args, scale);
        vsprintf(buffer, fmt, args);
        if (strlen(buffer) >= 0x200)
            Abend_Panic((void *)lbl_802FC518, strlen(buffer), fmt);
        fn_802337A0(x, lbl_8055D494, scale, color,
                    lbl_80560280, y, fontId, lbl_80560264,
                    (const char *)&lbl_80558AA4, buffer);
    }
}
#pragma scheduling on
#pragma pop

#pragma scheduling on
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* printf-style UI text draw: formats the message into a scratch buffer, then queues a
   word-wrapped draw of it (Text_drawWordWrapped) with the default UI font (lbl_8055D490) in the
   given color/flags at (x, y), wrapped at `width` and drawn at `scale` times the UI
   scale factor lbl_805602C8. The trailing 1 selects Text_drawWordWrapped's queued-draw mode. */
void fn_800103B8(s32 color, s32 flags, f32 scale, f32 x, f32 y, f32 width, const char *fmt, ...) {
    char buffer[0x200];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    Text_drawWordWrapped(buffer, lbl_8055D490,
                x, y, width,
                lbl_805602C8 * scale,
                lbl_80560280, lbl_80560264,
                color, flags, 1);
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* printf-style draw with the large font: formats the message into a scratch buffer
   and queues a draw of it (fn_80232BA4) with the "bigtext.gtx" font context
   (lbl_8055D498) in the given colour and line height, at (x, y) and at the given
   text scale -- unlike fn_80010188, which draws the same way with the normal UI
   font, the scale is used as-is and not multiplied by the UI scale lbl_805602C8.
   The two trailing floats are the default 0.0f and 1.0f pen values. */
void fn_800104B0(s32 color, s32 lineHeight, const char *fmt, f32 scale, f32 x, f32 y, ...) {
    char textBuffer[0x200];
    va_list args;
    va_start(args, y);
    vsprintf(textBuffer, fmt, args);
    fn_80232BA4(textBuffer, lbl_8055D498, color, lineHeight, x, y, scale, lbl_80560280, lbl_80560264);
}
#pragma scheduling on
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* Draw a highlighted UI label/text element: computes position/size offsets based on UI mode and renders a box and text. */
void fn_800105A0(s32 text, s32 layoutId, s32 unused) {
    extern s32 fn_80137C74(void);
    extern f32 fn_800108C8(f32, s32);
    extern f32 fn_80011E04(s32);
    extern f32 fn_80011E1C(s32);
    extern void fn_80010B80(s32, f32, f32, f32, f32);
    extern void fn_80010C74(f32, f32, f32);
    extern void fn_80010D88(f64, f64, f64);
    extern void fn_8000FF88(s32, s32, const char *, f32, f32, f32, ...);
    extern f32 lbl_8056025C;
    extern f32 lbl_80560264;
    extern f32 lbl_805602EC;
    extern f32 lbl_805602F8;
    extern f32 lbl_80560314;
    extern f32 lbl_80560318;
    s32 mode;
    s32 temp;
    s32 mask;
    s32 amount;
    s32 isHighlighted;
    f32 boxHeight;
    f32 textScale;
    f32 boxWidth;
    f32 boxX;
    f32 baseX;
    f32 textY;

    mode = fn_80137C74();
    temp = mode ^ 2;
    mask = temp >> 1;
    temp &= mode;
    temp = mask - temp;
    isHighlighted = ((u32)temp) >> 31;
    if (isHighlighted != 0)
        textScale = lbl_80560264;
    else
        textScale = lbl_80560318;
    boxWidth = lbl_805602F8 + fn_800108C8(textScale, text);
    if (isHighlighted != 0)
        boxHeight = lbl_805602EC;
    else
        boxHeight = lbl_80560314;
    boxX = (-boxWidth * lbl_8056025C) + fn_80011E04(layoutId);
    baseX = fn_80011E04(layoutId);
    amount = (isHighlighted != 0) ? 0 : -0x28;
    textY = (f32)amount + fn_80011E1C(layoutId);
    fn_80010B80(0x90000000, boxX, textY, boxWidth, boxHeight);
    fn_80010C74(boxX, lbl_80560264 + textY, lbl_80560264 + boxWidth);
    fn_80010D88(boxX + boxWidth, textY, boxHeight);
    fn_80010C74(boxX, textY - boxHeight, lbl_80560264 + boxWidth);
    fn_80010D88(boxX, textY, boxHeight);
    fn_8000FF88(-1, 0xC, (const char *)text, textScale, baseX, textY);
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma pop
extern void fn_80010FDC(char *, s32);
extern f32 lbl_80560280;
extern f32 fn_8023293C(s32, f32);
extern f32 getPictureHeight(s32, s32);
extern f32 lbl_8056025C;
extern f32 lbl_80560264;
extern f32 lbl_80560290;
extern f32 lbl_805602F8;
extern f32 lbl_805602FC;
extern s32 lbl_80558A90;
extern s32 lbl_8055D494;
  extern UnkF22C *lbl_8055D4B0;
  extern char lbl_802FC518[];
  extern s32 lbl_80558AA4;
  extern void fn_802337A0(f32, s32, f32, s32, f32, f32, s32, f32, const char *, ...);
typedef void (*RegisterTextEntry)(s32 name, s32 id);
void fn_8001071C(s32 name) {
    /* Register a text entry under the fixed id 0xD (13). */
    ((RegisterTextEntry)fn_80010FDC)(name, 0xD);
}

#pragma push
#pragma processor 750
#pragma paired_single off
void fn_80010724(s32 x, s32 y, s32 arg2) {
    extern s32 fn_8001084C();
    extern s32 fn_80010964(s32);
    extern f32 fn_800109A0(s32);
    extern void fn_80010B80(s32, f32, f32, f32, f32);
    extern f32 lbl_80560310;
    extern f32 lbl_8056031C;
    extern f32 lbl_80560320;
    extern f32 lbl_805602F4;
    f32 temp_f1;
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f31_2;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 result;

    /* Computes layout coordinates from scaled metrics and draws/formats a UI element. */
    temp_f1 = (f32)((s32 (*)(s32, s32))fn_8001084C)(0x10, arg2);
    temp_f31 = lbl_80560310 + temp_f1;
    temp_f4 = lbl_8056031C + (f32)fn_80010964(0x10);
    temp_f6 = (f32)x;
    temp_f5 = temp_f6 - lbl_80560320;
    temp_f30 = temp_f5 - (temp_f31 * lbl_8056025C);
    temp_f31_2 = (lbl_805602F4 - (f32)y) + (temp_f4 * lbl_8056025C);
    ((void (*)(s32, f32, f32, f32, f32, f32, f32))fn_80010B80)(0x80000000, temp_f30, temp_f31_2, temp_f31, temp_f4, temp_f5, temp_f6);
    result = fn_800109A0(lbl_80558A90);
    ((void (*)(s32, s32, const char *, f32, ...))fn_8000FF88)(-1, 0x14, (const char *)&lbl_80558AA4, result, arg2, temp_f30, temp_f31_2);
}
#pragma push
#pragma processor 750
#pragma paired_single off
s32 fn_8001084C(s32 scaleValue, s32 text) {
    /* Return a scaled text width in fixed units: measure text with the default UI font and scale factor 1.0, multiply by scaleValue, and divide by lbl_80558A90. */
    f32 defaultScale = 1.0f;
    return (s32)(((f32)scaleValue * ((f32 (*)(s32, s32, f32))fn_8023293C)(lbl_8055D490, text, defaultScale)) / (f32)lbl_80558A90);
}
#pragma pop
/* Measures text width with the default UI font, scaled by the given factor and the UI text scale. */
f32 fn_800108C8(f32 scale, s32 text) {
    return (scale * ((f32 (*)(s32, s32, f32))fn_8023293C)(lbl_8055D490, text, lbl_80560264)) * lbl_805602C8;
}
#pragma pop
extern s32 lbl_80558A90;
#pragma push
#pragma processor 750
#pragma paired_single off
#pragma fp_contract off
f32 fn_8001090C(f32 value) {
    /* Scale a value by the UI text scale factor (lbl_805602C8) and a count
     * queried from the UI/font object (lbl_8055D490). */
    f32 count;
    count = (f32)fn_80232B70(lbl_8055D490);
    return lbl_805602C8 * (value * count);
}
#pragma pop
/* Scale an integer value by the default UI font's metric using fixed point:
 * (value * fontMetric) / scaleDivisor. Integer counterpart of fn_8001084C. */
s32 fn_80010964(s32 value) {
#define gDefaultFont lbl_8055D490
#define gScaleDivisor lbl_80558A90
#define getFontMetric fn_80232B70
    return (s32)(value * getFontMetric(gDefaultFont)) / (s32)gScaleDivisor;
#undef getFontMetric
#undef gDefaultFont
#undef gScaleDivisor
}

extern s32 fn_80232B70(s32);
extern s32 lbl_8055D490;
extern s32 lbl_80558A90;
extern f32 lbl_805602C8;
extern f64 lbl_80560268;
/* Convert a signed integer to float divided by a fixed-point scale constant. */
f32 fn_800109A0(s32 value)
{
    return (f32)value / (f32)lbl_80558A90;
}

#pragma dont_inline fn_800109E4
/* Sets up and draws an axis-aligned colored quad using the same color for all corners. */
void fn_800109E4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    s32 sp18;
    s32 sp1C;

    sp8 = arg1;
    spC = arg2;
    sp10 = arg3;
    sp14 = arg4;
    sp18 = arg0;
    sp1C = arg0;
    fn_80010B74();
    fn_80010A50(arg1, arg2, arg3, arg4, arg0, arg0);
    fn_80010B7C();
}

extern void fn_80231380(void *, s32, f32, f32, f32, f32, f32);
extern void fn_802C8DB8(void *, s32, u16 *, s32);
struct IndexList802ED748 {
    u16 idx[6];
};
extern struct IndexList802ED748 lbl_802ED748;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_80010A50(f32 left, f32 top, f32 width, f32 height, s32 colorTop, s32 colorBottom) {
    /* Build four colored/textured vertices for an axis-aligned quad and submit
     * them as two triangles using the shared index list. */
    struct Frame {
        struct IndexList802ED748 indices;
        u8 pad[4];
        f32 topLeft[6];
        f32 topRight[6];
        f32 bottomLeft[6];
        f32 bottomRight[6];
    } __attribute__((aligned(16))) frame;

    fn_80231380(frame.topLeft, colorTop, left, top, lbl_80560264, lbl_80560280, lbl_80560280);
    fn_80231380(frame.topRight, colorBottom, left + width, top, lbl_80560264, lbl_80560280, lbl_80560280);
    fn_80231380(frame.bottomLeft, colorTop, left, top - height, lbl_80560264, lbl_80560280, lbl_80560280);
    fn_80231380(frame.bottomRight, colorBottom, left + width, top - height, lbl_80560264, lbl_80560280, lbl_80560280);
    frame.indices = lbl_802ED748;
    fn_802C8DB8(frame.topLeft, 4, frame.indices.idx, 6);
}
#pragma pop
/* Reset the draw list with no texture slot selected (-1) before drawing a quad. */
void fn_80010B74(void) {
    fn_802C8BD0(-1);
}

/* Tail-call wrapper for DrawList_RestoreNormalMode: restores the
 * normal GX render mode after a batched quad flush (fn_80010BEC). */
void fn_80010B7C(void) {
    DrawList_RestoreNormalMode();
}

/* Buffer a colored quad entry (left, top, width, height, color) if the queue has space. */
void fn_80010B80(s32 color, float left, float top, float width, float height) {
    volatile s32 spill_color_a;
    volatile s32 spill_color_b;
    volatile float spill_height;
    volatile float spill_width;
    volatile float spill_top;
    volatile float spill_left;
    register s32 index;
    index = lbl_8055D4A8;
    spill_left = left;
    spill_top = top;
    spill_width = width;
    spill_height = height;
    spill_color_b = color;
    spill_color_a = color;
    if (index < 0x100) {
        Unk0x18 *entry = &lbl_8034F6B0[index];
        entry->unk_0x00 = (float)(double)left;
        entry->unk_0x04 = (float)(double)top;
        entry->unk_0x08 = (float)(double)width;
        entry->unk_0x0C = (float)(double)height;
        entry->unk_0x10 = color;
        lbl_8055D4A8 = index + 1;
        entry->unk_0x14 = color;
    }
}

#pragma dont_inline on
#pragma scheduling invalid_target
void *fn_80010BEC(void *arg0) {
    /* Flush queued quad entries: replay each buffered entry through fn_80010A50
     * and reset the entry count. */
    Unk0x18 *entry;
    s32 index;

    if (lbl_8055D4A8 > 0) {
        fn_80010B74();
        entry = lbl_8034F6B0;
        index = 0;
        while (index < lbl_8055D4A8) {
            fn_80010A50(entry->unk_0x00, entry->unk_0x04, entry->unk_0x08,
                        entry->unk_0x0C, entry->unk_0x10, entry->unk_0x14);
            entry++;
            index++;
        }
        fn_80010B7C();
        lbl_8055D4A8 = 0;
    }
}
#pragma scheduling on
void fn_80010C74(f32 farg0, f32 farg1, f32 farg2) {
    volatile s32 sp34, sp30;
    volatile f32 sp2C, sp28, sp24, sp20;
    volatile s32 sp1C, sp18;
    volatile f32 sp14, sp10, spC, sp8;
    register s32 index, next, offset, count;
    register u32 *configA, *configB;
    register Unk0x18 *base, *current, *following;
    register f32 temp_f0, temp_f4, temp_f5, temp_f6, temp_f7, temp_f8, temp_f9;
    u32 word;
    s32 a0, a1, a2, b0, b1, b2;
    register s32 value484, value488;

    index = lbl_8055D4A8;
    if (index < 0xFF) {
        offset = index * 0x18;
        temp_f0 = *(volatile f32 *)&lbl_80560264;
        temp_f8 = (f32)(double)farg0;
        value484 = *(volatile s32 *)&lbl_8055D484;
        value488 = *(volatile s32 *)&lbl_8055D488;
        base = lbl_8034F6B0;
        temp_f7 = (f32)(double)farg1;
        configA = (u32 *)&lbl_802ED758;
        temp_f6 = (f32)(double)farg2;
        temp_f5 = temp_f0 + farg0;
        temp_f4 = farg1 - temp_f0;
        current = (Unk0x18 *)((u8 *)base + offset);
        word = configA[3];
        current->unk_0x00 = temp_f8;
        configB = (u32 *)&lbl_802ED770;
        *(volatile u32 *)&sp2C = word;
        next = index + 1;
        offset = next * 0x18;
        a0 = configA[0];
        current->unk_0x04 = temp_f7;
        temp_f9 = sp2C;
        current->unk_0x08 = temp_f6;
        following = (Unk0x18 *)((u8 *)base + offset);
        a1 = configA[1];
        current->unk_0x0C = temp_f9;
        word = configB[3];
        count = next + 1;
        current->unk_0x10 = value484;
        a2 = configA[2];
        *(volatile u32 *)&sp14 = word;
        b0 = configB[0];
        current->unk_0x14 = value484;
        b1 = configB[1];
        following->unk_0x00 = temp_f5;
        b2 = configB[2];
        following->unk_0x04 = temp_f4;
        temp_f9 = sp14;
        following->unk_0x08 = temp_f6;
        following->unk_0x0C = temp_f9;
        *(volatile u32 *)&sp20 = a0;
        *(volatile u32 *)&sp24 = a1;
        *(volatile u32 *)&sp28 = a2;
        *(volatile u32 *)&sp8 = b0;
        *(volatile u32 *)&spC = b1;
        *(volatile u32 *)&sp10 = b2;
        following->unk_0x10 = value488;
        sp20 = farg0;
        sp24 = farg1;
        sp28 = farg2;
        sp30 = value484;
        sp34 = value484;
        sp8 = temp_f5;
        spC = temp_f4;
        sp10 = farg2;
        sp18 = value488;
        sp1C = value488;
        lbl_8055D4A8 = count;
        following->unk_0x14 = value488;
    }
}
#pragma scheduling invalid_target
extern u32 lbl_802ED788[];
extern u32 lbl_802ED7A0[];
extern s32 lbl_8055D484;
extern s32 lbl_8055D488;
#pragma scheduling invalid_target
void fn_80010D88(f64 farg0, f64 farg1, f64 farg2) {
    volatile s32 sp34, sp30;
    volatile f32 sp2C, sp28, sp24, sp20;
    volatile s32 sp1C, sp18;
    volatile f32 sp14, sp10, spC, sp8;
    register Unk0x18 *base;
    register u32 *configA;
    register u32 *configB;
    register s32 index, next, offset;
    register Unk0x18 *current;
    register Unk0x18 *following;
    register s32 value484;
    register s32 value488;
    register f32 temp_f0;
    register f32 temp_f5;
    register f32 temp_f6;
    register f32 temp_f4;
    u32 word;

    index = lbl_8055D4A8;
    if (index < 0xFF) {
        configA = (u32 *)&lbl_802ED788;
        value484 = *(volatile s32 *)&lbl_8055D484;
        temp_f0 = (f32)farg0;
        offset = index * 0x18;
        word = configA[2];
        temp_f5 = (f32)farg1;
        value488 = *(volatile s32 *)&lbl_8055D488;
        base = lbl_8034F6B0;
        temp_f6 = (f32)farg2;
        *(volatile u32 *)&sp28 = word;
        current = (Unk0x18 *)((u8 *)base + offset);
        next = index + 1;
        current->unk_0x00 = temp_f0;
        current->unk_0x04 = temp_f5;
        current->unk_0x08 = sp28;
        current->unk_0x0C = temp_f6;
        current->unk_0x10 = value484;
        current->unk_0x14 = value484;
        temp_f4 = *(volatile f32 *)&lbl_80560264;
        temp_f5 = temp_f4 + (f32)farg0;
        temp_f4 = (f32)farg1 - temp_f4;
        configB = (u32 *)&lbl_802ED7A0;
        *(volatile u32 *)&sp10 = configB[2];
        offset = next * 0x18;
        following = (Unk0x18 *)((u8 *)base + offset);
        following->unk_0x00 = temp_f5;
        *(volatile u32 *)&sp20 = configA[0];
        following->unk_0x04 = temp_f4;
        following->unk_0x08 = sp10;
        following->unk_0x0C = temp_f6;
        *(volatile u32 *)&sp24 = configA[1];
        *(volatile u32 *)&sp2C = configA[3];
        *(volatile u32 *)&sp8 = configB[0];
        *(volatile u32 *)&spC = configB[1];
        *(volatile u32 *)&sp14 = configB[3];
        following->unk_0x10 = value488;
        sp20 = (f32)farg0;
        sp24 = (f32)farg1;
        sp2C = (f32)farg2;
        sp30 = value484;
        sp34 = value484;
        sp8 = temp_f5;
        spC = temp_f4;
        sp14 = (f32)farg2;
        sp18 = value488;
        sp1C = value488;
        lbl_8055D4A8 = next + 1;
        following->unk_0x14 = value488;
    }
}

void fn_80010EF0(void);
void fn_80010F08(void);
void fn_80010F20(void);
void fn_80010EC8(void) {
#define ResetHudList_0 fn_80010EF0 /* clears the lbl_80350F88 list */
#define ResetHudList_1 fn_80010F08 /* clears the lbl_80351214 list */
#define ResetHudList_2 fn_80010F20 /* clears the lbl_803514A0 list */
    /* Empty all three HUD display lists: clear each list's entry count and
     * active flag. Counterpart to fn_8001123C, which draws all three. */
    ResetHudList_0();
    ResetHudList_1();
    ResetHudList_2();
#undef ResetHudList_0
#undef ResetHudList_1
#undef ResetHudList_2
}

typedef struct Unk80350F88Entry {
    char name[0x28];
    u8 unk_0x28;
    u8 pad_0x29[3];
    s32 unk_0x2C;
    s32 unk_0x30;
    s32 unk_0x34;
    s32 unk_0x38;
    f32 unk_0x3C;
} Unk80350F88Entry;

typedef struct Unk80350F88 {
    s32 unk_0x00;
    u8 unk_0x04;
    u8 pad_0x05[3];
    Unk80350F88Entry entries[10];
    s32 unk_0x288;
} Unk80350F88;
extern char *strncpy(char *, const char *, unsigned long);
extern f32 lbl_80560264;
extern f32 lbl_80560280;
extern void drawPicture(f32, f32, f32, f32, f32, f32);
extern void drawPictureScaled(s32, s32, s32, f32, f32, f32, f32, f32);
extern void fn_80010E94(f32, f32, f32, f32, s32, s32);
void fn_80010E94(f32 x, f32 y, f32 scaleX, f32 scaleY, s32 artSet, s32 pictureIndex) {
    /* Draw a picture at (x,y): when both scales are the DEFAULT_SCALE (zero)
       draw it unscaled via drawPicture, otherwise draw a sized quad. */
    if (DEFAULT_SCALE == scaleX && DEFAULT_SCALE == scaleY) {
        drawPicture(x, y, ONE_PIXEL, scaleY, scaleY, scaleX);
    } else {
        drawPictureScaled(artSet, pictureIndex, -1, x, y, ONE_PIXEL, scaleX, scaleY);
    }
}
#pragma scheduling off
void fn_80010EF0(void) {
    /* Clear the HUD display list at lbl_80350F88: zero its entry count at
     * +0x288 and its active flag at +0x4. */
    s8 *list;
    s32 *count;
    list = (s8 *)&lbl_80350F88;
    count = (s32 *)(list + 0x288);
    *count = 0;
    *(s8 *)(list + 0x4) = 0;
}

void fn_80010F08(void) {
    /* Clear the second HUD display list (lbl_80351214): zero its entry count
       at +0x288 and its active flag at +0x4. */
    s8 *list;
    s32 *count;
    list = (s8 *)&lbl_80351214;
    count = (s32 *)(list + 0x288);
    *count = 0;
    *(s8 *)(list + 0x4) = 0;
}

void fn_80010F20(void) {
    /* Clear the HUD display list at lbl_803514A0: zero its entry count at
     * +0x288 and its active flag at +0x4. */
    s8 *list;
    s32 *count;
    list = (s8 *)&lbl_803514A0;
    count = (s32 *)(list + 0x288);
    *count = 0;
    *(s8 *)(list + 0x4) = 0;
}

#pragma scheduling on
extern void fn_80011280(s32, s32, f32, f32, f32, f32);
extern void fn_8000E3B4(s32);
extern void fn_8000E874(s32);
extern void fn_8000EF74(s32);
#pragma push
#pragma processor 750
void fn_80010F38(char *name, s32 a2, s32 a3, s32 a4, f32 f1) {
    s32 idx;
    Unk80350F88 *base;
    volatile Unk80350F88Entry *entry;
    char *n;
    base = (Unk80350F88 *)&lbl_80350F88;
    idx = base->unk_0x288;
    base->unk_0x288 = idx + 1;
    entry = &base->entries[idx];
    n = name;
    strncpy((char *)entry->name, n, 0x28);
    entry->unk_0x28 = 0;
    entry->unk_0x2C = a2;
    entry->unk_0x30 = a3;
    entry->unk_0x34 = 0;
    entry->unk_0x38 = a4;
    entry->unk_0x3C = f1;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_80010FDC(char *name, s32 id) {
    extern f32 lbl_8055D4D8;
    extern f32 fn_8000EDC0(s32);
    extern f32 fn_800108C8(f32, s32);
    extern void *memset(void *, s32, u32);
    extern char *strncpy(char *, const char *, unsigned long);
    char buf[0x200];
    Unk80350F88 *root;
    volatile Unk80350F88Entry *entry;
    char *bufp;
    char *namep;
    s32 zero;
    s32 len;
    s32 space;
    s32 idx;
    s32 i;
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f29;

    temp_f30 = lbl_8055D4D8;
    temp_f29 = fn_8000EDC0(id);
    if (fn_800108C8(temp_f29, (s32)name) > temp_f30) {
        root = (Unk80350F88 *)&lbl_803514A0;
        temp_f31 = lbl_80560264;
        bufp = buf;
        zero = 0;
        namep = name;
        while (*namep != 0) {
            memset(buf, zero, 0x200);
            len = 0;
            space = -1;
            while (*namep != 0 && *namep != '\n' && fn_800108C8(temp_f29, (s32)buf) < temp_f30) {
                if (*(volatile char *)namep == ' ') {
                    space = len;
                }
                buf[len] = *namep;
                namep++;
                len++;
            }
            if (*namep == '\n') {
                namep++;
            } else if (*namep != 0 && space >= 0) {
                buf[space] = (char)zero;
                namep -= (len - space) - 1;
            }
            idx = root->unk_0x288;
            root->unk_0x288 = idx + 1;
            entry = &root->entries[idx];
            strncpy((char *)entry->name, buf, 0x28);
            entry->unk_0x28 = (u8)zero;
            entry->unk_0x2C = zero;
            entry->unk_0x30 = zero;
            entry->unk_0x34 = zero;
            entry->unk_0x38 = id;
            entry->unk_0x3C = temp_f31;
        }
    } else {
        root = (Unk80350F88 *)&lbl_803514A0;
        idx = root->unk_0x288;
        root->unk_0x288 = idx + 1;
        entry = &root->entries[idx];
        strncpy((char *)entry->name, name, 0x28);
        entry->unk_0x28 = 0;
        entry->unk_0x2C = 0;
        entry->unk_0x30 = 0;
        entry->unk_0x34 = 0;
        entry->unk_0x38 = id;
        entry->unk_0x3C = lbl_80560264;
    }
}
#pragma ppc_psq_save off
void fn_800111A4(char *name, s32 a1, s32 a2, s32 a3, s32 a4, f32 f) {
    s32 idx;
    Unk80350F88 *base;
    volatile Unk80350F88Entry *entry;
    char *n;

    base = (Unk80350F88 *)&lbl_80350F88;
    idx = base->unk_0x288;
    n = name;
    base->unk_0x288 = idx + 1;
    entry = &base->entries[idx];
    strncpy((char *)entry->name, n, 0x28);
    entry->unk_0x28 = 0;
    entry->unk_0x2C = a1;
    entry->unk_0x30 = a2;
    entry->unk_0x38 = a4;
    entry->unk_0x3C = f;
    entry->unk_0x34 = a3;
}
#pragma ppc_psq_save reset
/* RealName: HudList_DrawAll. Draws each of the three 0x40-byte-entry HUD lists
   (lbl_80350F88, lbl_80351214, lbl_803514A0) for the given player; a negative
   index selects the shared default layout (fn_80011E34/54/70). */
void fn_8001123C(s32 playerIndex) {
#define DrawHudList_0 fn_8000E3B4 /* renders the lbl_80350F88 list */
#define DrawHudList_1 fn_8000E874 /* renders the lbl_80351214 list */
#define DrawHudList_2 fn_8000EF74 /* renders the lbl_803514A0 list */
    DrawHudList_0(playerIndex);
    DrawHudList_1(playerIndex);
    DrawHudList_2(playerIndex);
#undef DrawHudList_0
#undef DrawHudList_1
#undef DrawHudList_2
}

void fn_80011278(s32 color) {
    /* Alternate entry to the 9-slice frame drawer: tail-call fn_80011280 with the
       cached frame art-set handle (lbl_8055D4D4) in its second slot, forwarding
       color and the four float coords/scales still live in the float registers. */
    ((void (*)(s32, s32))fn_80011280)(color, lbl_8055D4D4);
}

extern f32 getPictureWidth(s32, s32);
#pragma scheduling invalid_target
void fn_80011280(s32 arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    volatile f32 spC;
    volatile f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_11;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_9;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f26_3;
    f32 temp_f26_4;
    f32 temp_f26_5;
    f32 temp_f27;
    f32 temp_f2;
    f32 temp_f5;

    temp_f26 = getPictureWidth(arg1, 0);
    temp_f5 = getPictureHeight(arg1, 0);
    sp8 = farg0;
    spC = farg1;
    drawPictureScaled(arg1, 0, arg0, (f32)(f64)farg0, (f32)(f64)farg1, lbl_80560280, temp_f26, temp_f5);
    temp_f1 = getPictureWidth(arg1, 1);
    spC = farg1;
    sp8 = (farg0 + farg2) - temp_f1;
    drawPictureScaled(arg1, 1, arg0, sp8, (f32)(f64)farg1, lbl_80560280, temp_f1, getPictureHeight(arg1, 1));
    temp_f26_2 = getPictureWidth(arg1, 2);
    temp_f1_2 = getPictureHeight(arg1, 2);
    sp8 = farg0;
    spC = temp_f1_2 + (farg1 - farg3);
    drawPictureScaled(arg1, 2, arg0, farg0, spC, lbl_80560280, temp_f26_2, getPictureHeight(arg1, 2));
    temp_f1_3 = getPictureWidth(arg1, 3);
    sp8 = (farg0 + farg2) - temp_f1_3;
    temp_f2 = getPictureHeight(arg1, 3);
    spC = temp_f2 + (farg1 - farg3);
    drawPictureScaled(arg1, 3, arg0, sp8, spC, lbl_80560280, temp_f1_3, getPictureHeight(arg1, 3));
    temp_f1_4 = getPictureWidth(arg1, 0);
    temp_f0 = farg0 + temp_f1_4;
    spC = farg1;
    sp8 = temp_f0;
    temp_f26_3 = farg2 - (temp_f1_4 + getPictureWidth(arg1, 1));
    drawPictureScaled(arg1, 4, arg0, sp8, (f32)(f64)farg1, lbl_80560280, temp_f26_3, getPictureHeight(arg1, 0));
    temp_f1_5 = getPictureWidth(arg1, 2);
    sp8 = farg0 + temp_f1_5;
    temp_f26_4 = farg2 - (temp_f1_5 + getPictureWidth(arg1, 3));
    temp_f1_6 = getPictureHeight(arg1, 2);
    temp_f2 = temp_f1_6 + (farg1 - farg3);
    spC = temp_f2;
    drawPictureScaled(arg1, 5, arg0, sp8, temp_f2, lbl_80560280, temp_f26_4, temp_f1_6);
    temp_f26_5 = getPictureWidth(arg1, 0);
    temp_f1_7 = getPictureHeight(arg1, 0);
    temp_f0_2 = farg1 - temp_f1_7;
    sp8 = farg0;
    spC = temp_f0_2;
    drawPictureScaled(arg1, 6, arg0, farg0, spC, lbl_80560280, temp_f26_5, farg3 - (temp_f1_7 + getPictureHeight(arg1, 2)));
    temp_f26_5 = getPictureWidth(arg1, 1);
    sp8 = (farg0 + farg2) - temp_f26_5;
    temp_f1_9 = getPictureHeight(arg1, 1);
    spC = farg1 - temp_f1_9;
    drawPictureScaled(arg1, 7, arg0, sp8, spC, lbl_80560280, temp_f26_5, farg3 - (temp_f1_9 + getPictureHeight(arg1, 3)));
    temp_f1_10 = getPictureWidth(arg1, 0);
    sp8 = farg0 + temp_f1_10;
    temp_f27 = (farg2 - temp_f1_10) - getPictureWidth(arg1, 1);
    temp_f1_11 = getPictureHeight(arg1, 0);
    spC = farg1 - temp_f1_11;
    drawPictureScaled(arg1, 8, arg0, sp8, spC, lbl_80560280, temp_f27, (farg3 - temp_f1_11) - getPictureHeight(arg1, 2));
}
#pragma scheduling on
extern f64 sin(f32);
extern f64 cos(f32);
extern s32 fn_8022EDC4(void);
extern void fn_802C8B98(s32, s32);
extern s32 beginMeshPass(s32);
extern s32 fn_801E4F3C(s32, s32, f32, f32, f32, f32, f32);
extern void endMeshPass(void);
extern f32 lbl_8056025C, lbl_80560264, lbl_80560280, lbl_805602E0, lbl_805602E4;
extern f32 lbl_805602E0;
extern f32 lbl_805602E4;
 #pragma scheduling on
 #define FPRBIND(n, r) register float n a##sm(r)
void fn_80011630(s32 arg0, s32 arg1, s32 arg2,
                 register f32 farg0, register f32 farg1, register f32 farg2, register f32 farg3,
                 register f32 farg4, register f32 farg5, register f32 farg6, register f32 farg7,
                 register f32 arg_sp8, register f32 arg_spC) {
    volatile f32 sp14, sp10, spC, sp8;
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f0_4;
    f32 temp_f1_2, temp_f23, temp_f23_2;
    f32 temp_f25, temp_f25_2, temp_f26, temp_f27, temp_f28;
    f32 temp_f29, temp_f2, temp_f2_2, temp_f30, temp_f31;
    f32 temp_f3, temp_f4, temp_f4_2, temp_f4_3, temp_f5;
    f32 var_f0, var_f0_2, var_f1, var_f1_2, var_f3, var_f4;
    f32 var_f5, var_f5_2;
    f32 w;
    f64 temp_f1;
    s32 var_r31;

    if (arg1 > 0) {
        fn_802C8B98(arg2, fn_8022EDC4());
        beginMeshPass(arg1 * 4);
        w = farg4;
        temp_f25 = (f32)sin(w);
        temp_f1 = cos(w);
        w = farg3 / farg2;
        var_f5 = lbl_80560264;
        sp14 = temp_f25;
        temp_f4 = (f32)temp_f1;
        sp10 = temp_f4;
        spC = temp_f25 * farg2;
        sp8 = temp_f4 * farg2;
        temp_f0 = lbl_8056025C * (temp_f4 - lbl_805602E0);
        var_f5 = (var_f5 < temp_f0) ? var_f5 : temp_f0;
        var_f5 = (var_f5 > lbl_80560280) ? var_f5 : lbl_80560280;
        temp_f29 = farg6 + (var_f5 * (arg_sp8 - farg6));
        temp_f0_2 = sp14;
        var_f3 = lbl_80560264;
        temp_f0_2 = (temp_f0_2 - var_f3) / lbl_805602E4;
        var_f3 = (var_f3 < temp_f0_2) ? var_f3 : temp_f0_2;
        var_f3 = (var_f3 > lbl_80560280) ? var_f3 : lbl_80560280;
        temp_f0_2 = var_f3 * (arg_spC - farg7);
        fn_801E4F3C(arg0, 0, farg0 + sp8, farg1 + spC, lbl_80560280,
                    temp_f29, farg7 + temp_f0_2);
        var_f4 = lbl_80560264;
        temp_f0_3 = lbl_8056025C * ((w * sp10) - lbl_805602E0);
        var_f4 = (var_f4 < temp_f0_3) ? var_f4 : temp_f0_3;
        var_f4 = (var_f4 > lbl_80560280) ? var_f4 : lbl_80560280;
        temp_f29 = farg6 + (var_f4 * (arg_sp8 - farg6));
        var_f5_2 = lbl_80560264;
        temp_f0_4 = ((w * sp14) - var_f5_2) / lbl_805602E4;
        var_f5_2 = (var_f5_2 < temp_f0_4) ? var_f5_2 : temp_f0_4;
        var_f5_2 = (var_f5_2 > lbl_80560280) ? var_f5_2 : lbl_80560280;
        temp_f0_2 = var_f5_2 * (arg_spC - farg7);
        fn_801E4F3C(arg0, 0, farg0 + (w * sp8), farg1 + (w * spC), lbl_80560280,
                    temp_f29, farg7 + temp_f0_2);
        temp_f29 = arg_sp8 - farg6;
        temp_f25_2 = lbl_80560264;
        temp_f31 = arg_spC - farg7;
        temp_f28 = lbl_80560280;
        temp_f26 = lbl_805602E0;
        temp_f27 = lbl_8056025C;
        var_r31 = 0;
        temp_f30 = lbl_805602E4;
        do {
            temp_f4 = sp8;
            temp_f23 = (f32)cos(farg5);
            temp_f5 = (f32)sin(farg5);
            temp_f0_3 = spC;
            temp_f4_2 = temp_f4 * temp_f23;
            temp_f3 = temp_f0_3 * temp_f5;
            temp_f2 = temp_f4_2 - temp_f3;
            spC = (temp_f4 * temp_f5) + (temp_f0_3 * temp_f23);
            sp8 = temp_f2;
            temp_f4 = sp10;
            temp_f23_2 = (f32)cos(farg5);
            temp_f4_3 = (f32)sin(farg5);
            temp_f2_2 = (temp_f4 * temp_f23_2) - (sp14 * temp_f4_3);
            temp_f1_2 = (temp_f4 * temp_f4_3) + (sp14 * temp_f23_2);
            sp10 = temp_f2_2;
            sp14 = temp_f1_2;
            var_f1 = (temp_f2_2 - temp_f26) * temp_f27;
            if (temp_f25_2 < var_f1) var_f1 = temp_f25_2;
            var_f1 = (var_f1 > temp_f28) ? var_f1 : temp_f28;
            temp_f4_2 = farg6 + (var_f1 * temp_f29);
            var_f0 = (sp14 - temp_f25_2) / temp_f30;
            if (temp_f25_2 < var_f0) var_f0 = temp_f25_2;
            var_f0 = (var_f0 > temp_f28) ? var_f0 : temp_f28;
            temp_f0_2 = var_f0 * temp_f31;
            fn_801E4F3C(arg0, 1, farg0 + sp8, farg1 + spC, lbl_80560280,
                        temp_f4_2, farg7 + temp_f0_2);
            var_f1_2 = ((w * sp10) - temp_f26) * temp_f27;
            if (temp_f25_2 < var_f1_2) var_f1_2 = temp_f25_2;
            var_f1_2 = (var_f1_2 > temp_f28) ? var_f1_2 : temp_f28;
            temp_f4_2 = farg6 + (var_f1_2 * temp_f29);
            var_f0_2 = ((w * sp14) - temp_f25_2) / temp_f30;
            if (temp_f25_2 < var_f0_2) var_f0_2 = temp_f25_2;
            var_f0_2 = (var_f0_2 > temp_f28) ? var_f0_2 : temp_f28;
            temp_f0_2 = var_f0_2 * temp_f31;
            fn_801E4F3C(arg0, 1, farg0 + (w * sp8), farg1 + (w * spC), lbl_80560280,
                        temp_f4_2, farg7 + temp_f0_2);
            var_r31++;
        } while (var_r31 < arg1);
        endMeshPass();
        DrawList_RestoreNormalMode();
    }
}
#pragma scheduling invalid_target
/* Draw everything queued for this frame: fn_80010BEC replays the quads buffered in
 * lbl_8034F6B0 through fn_80010A50 and empties that queue, then fn_802346C8 draws
 * the text strings queued in the font object and empties its own.  Neither reads a
 * real argument: r3 only travels from the caller through the flush into the drawer,
 * which is why decompilers show one as the other's argument. */
void fn_80011A2C(void *arg0) {
    fn_80010BEC(arg0);
    fn_802346C8();
}

/* Discard everything queued for drawing this frame: empty the quad queue and
 * then reset the on-screen text draw queue. */
#define s_quadCount lbl_8055D4A8
void fn_80011A50(void) {
    /* 0 = no quads buffered. */
    s_quadCount = 0;
    fn_80234AEC();
}
#undef s_quadCount

extern void fn_80231094(s32 *, s32 *, s32 *, s32 *);
extern s32 lbl_8055D4A0;
extern s8 lbl_8055D4A4;
extern f32 lbl_80560280, lbl_80560290, lbl_805602F4, lbl_805602FC;
extern f32 lbl_80560320, lbl_80560324, lbl_80560328, lbl_8056032C;
extern f32 lbl_80560330, lbl_80560334, lbl_80560338, lbl_8056033C;
extern f32 lbl_80560340, lbl_80560344;
void fn_80011A5C(s32 arg0)
{
  f32 sp[20];
  s32 sp14;
  s32 sp10;
  s32 spC;
  s32 sp8;
  f32 *var_r5;
  f32 temp_f0;
  f32 temp_f11;
  f32 temp_f1;
  f32 c40;
  f32 temp_f1_2;
  f32 temp_f2;
  f32 temp_f2_2;
  f32 temp_f30;
  f32 temp_f31;
  f32 temp_f3;
  f32 temp_f3_2;
  f32 temp_f4;
  f32 temp_f5;
  f32 temp_f5_2;
  f32 temp_f6;
  f32 temp_f7;
  f32 temp_f7_2;
  f32 temp_f8;
  f32 temp_f8_2;
  f32 c3C;
  f32 c44;
  f32 cFC;
  f32 c5C;
  f64 c268;
  s32 temp_r0;
  s32 temp_r0_2;
  s32 temp_r3_4;
  s32 temp_r7;
  s32 var_ctr;
  u8 *base;
  u8 *temp_r3;
  u8 *temp_r3_2;
  u8 *temp_r3_3;
  u8 *var_r4;
  u8 *var_r6;
  f32 sums[2];
  base = (u8 *) lbl_8034F6B0;
  lbl_8055D4A0 = arg0;
  fn_80231094(&spC, &sp8, &sp14, &sp10);
  temp_f5 = (f32) sp14;
  temp_f6 = (f32) sp10;
  temp_f7 = (f32) spC;
  temp_f8 = (f32) sp8;
  if (arg0 == 1)
  {
    sp[0] = temp_f7;
    sp[3] = temp_f8;
    sp[1] = temp_f5;
    sp[2] = temp_f6;
    sp[4] = lbl_80560320;
  }
  else
    if (arg0 == 2)
  {
    sp[0] = temp_f7;
    sp[3] = lbl_80560280;
    sp[1] = temp_f5;
    sp[2] = temp_f6;
    sp[5] = lbl_80560280;
    sp[8] = temp_f8;
    sp[6] = temp_f5;
    sp[7] = temp_f6;
    sp[4] = lbl_80560320;
    sp[9] = lbl_80560320;
  }
  else
  {
    sp[0] = temp_f7;
    sp[3] = lbl_80560280;
    sp[1] = temp_f5;
    sp[2] = lbl_80560290;
    sp[5] = temp_f7;
    sp[8] = lbl_80560280;
    sp[6] = lbl_80560290;
    sp[7] = temp_f6;
    sp[10] = lbl_80560280;
    sp[13] = temp_f8;
    sp[11] = temp_f5;
    sp[12] = lbl_80560290;
    sp[15] = lbl_80560280;
    sp[18] = temp_f8;
    sp[16] = lbl_80560290;
    sp[17] = temp_f6;
    temp_f1 = (lbl_80560290 - temp_f5) * lbl_8056025C;
    sp[4] = temp_f1;
    temp_f0 = (temp_f6 - lbl_80560290) * lbl_8056025C;
    sp[9] = temp_f0;
    sp[14] = temp_f1;
    sp[19] = temp_f0;
  }
  temp_r3 = base + 0x1814;
  temp_f4 = lbl_805602F4 - temp_f7;
  temp_f3 = lbl_80560324 + temp_f8;
  temp_f2 = lbl_80560328 + temp_f5;
  temp_f1_2 = lbl_80560320 - temp_f6;
  *((f32 *) (base + 0x1814)) = temp_f4;
  *((f32 *) (temp_r3 + 0xC)) = temp_f3;
  *((f32 *) (temp_r3 + 4)) = temp_f2;
  *((f32 *) (temp_r3 + 8)) = temp_f1_2;
  if (arg0 < 3)
  {
    temp_r3_2 = base + 0x1800;
    *((f32 *) (base + 0x1800)) = temp_f4;
    *((f32 *) (temp_r3_2 + 4)) = temp_f2;
    *((f32 *) (temp_r3_2 + 8)) = temp_f1_2;
    *((f32 *) (temp_r3_2 + 0xC)) = temp_f3;
    *((f32 *) (temp_r3_2 + 0x10)) = *((f32 *) (temp_r3 + 0x10));
  }
  else
  {
    temp_r3_3 = base + 0x1800;
    *((f32 *) (base + 0x1800)) = lbl_8056032C - temp_f7;
    *((f32 *) (temp_r3_3 + 0xC)) = lbl_80560330 + temp_f8;
    *((f32 *) (temp_r3_3 + 4)) = lbl_80560334 + temp_f5;
    *((f32 *) (temp_r3_3 + 8)) = lbl_80560338 - temp_f6;
  }
  c3C = lbl_8056033C;
  c40 = lbl_80560340;
  c44 = lbl_80560344;
  cFC = lbl_805602FC;
  c5C = lbl_8056025C;
  c268 = lbl_80560268;
  var_r5 = sp;
  var_r6 = base + 0x1878;
  temp_r3_4 = lbl_8055D4A0 ^ 1;
  temp_r0 = lbl_8055D4A0 ^ 2;
  temp_r7 = ((((u32) ((temp_r3_4 >> 1) - (temp_r3_4 & lbl_8055D4A0))) >> 0x1FU) + 1) * 2;
  temp_r0_2 = ((((u32) ((temp_r0 >> 1) - (temp_r0 & lbl_8055D4A0))) >> 0x1FU) + 1) * 2;
  var_r4 = base + 0x1828;
  for (var_ctr = lbl_8055D4A0; var_ctr > 0; var_ctr--)
  {
    *((f32 *) (var_r4 + 0)) = *((f32 *) (((u8 *) var_r5) + 0));
    *((f32 *) (var_r4 + 4)) = *((f32 *) (((u8 *) var_r5) + 4));
    temp_f30 = c3C / ((f32) temp_r7);
    temp_f31 = temp_f30 - (*((f32 *) (((u8 *) var_r5) + 0)));
    *((f32 *) (var_r4 + 8)) = *((f32 *) (((u8 *) var_r5) + 8));
    temp_f11 = *((f32 *) (((u8 *) var_r5) + 0xC));
    temp_f8_2 = *((f32 *) (((u8 *) var_r5) + 4));
    temp_f5_2 = *((f32 *) (((u8 *) var_r5) + 8));
    *((f32 *) (var_r4 + 0xC)) = *((f32 *) (((u8 *) var_r5) + 0xC));
    *((f32 *) (var_r4 + 0x10)) = *((f32 *) (((u8 *) var_r5) + 0x10));
    var_r5 += 5;
    var_r4 += 0x14;
    *((f32 *) (var_r6 + 0)) = temp_f31;
    temp_f7_2 = (c40 / ((f32) temp_r7)) + temp_f11;
    temp_f2_2 = (c44 / ((f32) temp_r0_2)) + temp_f8_2;
    temp_f3_2 = (cFC / ((f32) temp_r0_2)) - temp_f5_2;
    *((f32 *) (var_r6 + 0xC)) = temp_f7_2;
    *((f32 *) (var_r6 + 4)) = temp_f2_2;
    *((f32 *) (var_r6 + 8)) = temp_f3_2;
    sums[0] = ((c44 / ((f32) temp_r0_2)) + temp_f8_2) + temp_f3_2;
    sums[1] = temp_f31 + temp_f7_2;
    *((f32 *) (var_r6 + 0x10)) = sums[0] * c5C;
    *((f32 *) (var_r6 + 0x14)) = sums[1] * c5C;
    var_r6 += 0x18;
  }

  lbl_8055D4A4 = 1;
}

f32 fn_80011DC0(s32 regionId) {
    /* First stored top of layout region regionId (the [region][0] column of lbl_80350F28). */
    return lbl_80350F28[regionId][0];
}

f32 fn_80011DD4(s32 regionId) {
    /* Left edge of layout region regionId (the [region][1] column of lbl_80350F28). */
    return lbl_80350F28[regionId][1];
}

f32 fn_80011DEC(s32 regionId) {
    /* Width of layout region regionId (the [region][2] column of lbl_80350F28). */
    return lbl_80350F28[regionId][2];
}

f32 fn_80011E04(s32 regionId) {
    /* Base X position of layout region regionId (the [region][4] column of
     * lbl_80350F28), used as the anchor for region-local text. */
    return lbl_80350F28[regionId][4];
}

f32 fn_80011E1C(s32 regionId) {
    /* Second stored top of layout region regionId (the [region][5] column of lbl_80350F28), used to blend split-screen layout vertically. */
    return lbl_80350F28[regionId][5];
}

f32 fn_80011E34(void) {
    /* Left edge of the whole-screen layout box lbl_80350EC4, stored as {top, left, right, bottom}. */
    return lbl_80350EC4[1];
}

f32 fn_80011E44(void) {
    /* Right edge of the whole-screen layout box lbl_80350EC4, stored as {top, left, right, bottom}. */
    return lbl_80350EC4[2];
}

f32 fn_80011E54(void) {
    /* Top edge of the whole-screen layout box lbl_80350EC4, stored as {top, left, right, bottom}. */
    return lbl_80350EC4[0];
}

extern f32 lbl_80350EC4[];
/* Bottom edge of the whole-screen layout box lbl_80350EC4, stored as {top, left, right, bottom}. */
f32 fn_80011E60(void) {
    return lbl_80350EC4[3];
}

f32 fn_80011E70(void) {
    f32 horizontalCenter;
    /* Horizontal centre of the whole-screen layout box lbl_80350EC4, stored as
     * {top, left, right, bottom}: (left + right) * 0.5 (lbl_8056025C). */
    horizontalCenter = lbl_80350EC4[1] + lbl_80350EC4[2];
    return horizontalCenter * lbl_8056025C;
}

/* Vertical centre of the whole-screen layout box lbl_80350EC4, stored as
 * {top, left, right, bottom}: (top + bottom) * 0.5 (lbl_8056025C). */
f32 fn_80011E90(void) {
    f32 verticalCenter;
    verticalCenter = lbl_80350EC4[0] + lbl_80350EC4[3];
    return verticalCenter * lbl_8056025C;
}

f32 fn_80011EB0(s32 regionId) {
    /* Horizontal anchor for layout region regionId: the [2] column of its
     * 5-float record in lbl_80350ED8, used as a target when easing a box's
     * centre toward the region. */
    return lbl_80350ED8[regionId * 5 + 2];
}

f32 fn_80011EC8(s32 regionId) {
    /* Vertical anchor for layout region regionId: the [0] column of its 5-float record in lbl_80350ED8, the companion to the horizontal anchor at [2]. */
    return lbl_80350ED8[regionId * 5];
}

__declspec(section ".sdata") extern char lbl_80558ACC[];
extern int sprintf(char *, const char *, ...);
#pragma push
#pragma processor 750
#pragma scheduling on
#pragma dont_inline on
/* Returns the maximum scaled width among digit glyphs '0' through '9' for the font/UI object. */
f32 fn_80011EDC(void) {
    char digitText[0x10];
    f32 widthScale = 0.73333335f;
    f32 maxWidth = 0.0f;
    f32 glyphWidth;
    s32 digit = 0;

    do {
        sprintf(digitText, lbl_80558ACC, (char)(digit + 0x30));
        glyphWidth = widthScale * ((f32 (*)(s32, char *, f32))fn_8023293C)(
            lbl_8055D490, digitText, lbl_80560264);
        if (glyphWidth > maxWidth) {
            maxWidth = glyphWidth;
        }
        digit++;
    } while (digit < 10);

    return maxWidth;
}
#pragma pop

/* Build the dashboard sound player (fn_800120BC tears it down again): a
 * 0x1C-byte block, kept in gDashSoundPlayer, holding the round-robin slot the
 * dashboard sounds play from (+0x00) and two groups of three sounds -- the
 * "rd_press.sfx" button sounds at +0x04..+0x0C and the "rd_accept.sfx" ones at
 * +0x10..+0x18, each loaded by fn_80207848 (0 when it will not load).  fn_80012158
 * and fn_800121A4 play the next slot of either group and wrap the index at
 * three.  The block is allocated under the "DashSoundPlayer" pool tag, then the
 * saved "effects_volume" option (defaulting to, and being written back as, full
 * volume) is handed to every sound that loaded: a sound whose volume differs
 * gets the new value and its volumeDirty byte set so it passes the volume on to
 * its voice. */
void fn_80011F64(void) {
    extern s32 *fn_801284F8(s32, const char *);
    extern s32 fn_80207848(void *, s32);
    extern void LoadFloatOption(s32, void *, f32 *);
    extern char lbl_802FC550[];
    extern char lbl_802FC560[];
    extern char lbl_802FC570[];
    extern char lbl_802FC580[];
    extern s32 *lbl_8055D4AC;
    #define STR_DASH_SOUND_PLAYER lbl_802FC550 /* "DashSoundPlayer": pool tag of the block */
    #define STR_SFX_ACCEPT        lbl_802FC560 /* "rd_accept.sfx" */
    #define STR_SFX_PRESS         lbl_802FC570 /* "rd_press.sfx" */
    #define STR_EFFECTS_VOLUME    lbl_802FC580 /* "effects_volume" */
    #define FULL_VOLUME           lbl_80560264 /* 1.0f */
    #define OPTIONS_SECTION_SOUND 4            /* the [SOUND] options section */
    #define DASH_SLOTS            3            /* sounds in each group */
    #define SOUND_VOLUME          0x08         /* f32: a Sound's volume */
    #define SOUND_VOLUME_DIRTY    0x4D         /* byte: hand that volume to the sound */

    f32 volume;
    f32 value;
    s32 *block;
    s32 i;
    s32 j;
    s32 *slot;
    s32 *slot2;
    s32 n;
    void *sound;

    block = fn_801284F8(0x1C, STR_DASH_SOUND_PLAYER);
    if (block != 0) {
        *block = 0; /* the slot the next press/accept plays from */
        slot = block;
        i = 0;
        do { /* three button-press sounds at +0x04, +0x08, +0x0C */
            sound = (void *)fn_80207848(STR_SFX_PRESS, 0);
            i++;
            slot[1] = (s32)sound;
            slot++;
        } while (i < DASH_SLOTS);
        slot2 = block;
        n = 0;
        do { /* three accept sounds at +0x10, +0x14, +0x18 */
            sound = (void *)fn_80207848(STR_SFX_ACCEPT, 0);
            n++;
            slot2[4] = (s32)sound;
            slot2++;
        } while (n < DASH_SLOTS);
        volume = FULL_VOLUME;
        LoadFloatOption(OPTIONS_SECTION_SOUND, (void *)STR_EFFECTS_VOLUME, &volume);
        slot = block;
        for (i = 0; i < 2; i++) { /* both groups */
            for (j = 1; j < 4; j++) {
                sound = (void *)slot[j];
                if (sound != 0) {
                    value = volume;
                    if (value != *(f32 *)((char *)sound + SOUND_VOLUME)) {
                        *((u8 *)sound + SOUND_VOLUME_DIRTY) = 1;
                        *(f32 *)((char *)sound + SOUND_VOLUME) = value;
                    }
                }
            }
            slot += DASH_SLOTS;
        }
    }
    lbl_8055D4AC = block;
    #undef STR_DASH_SOUND_PLAYER
    #undef STR_SFX_ACCEPT
    #undef STR_SFX_PRESS
    #undef STR_EFFECTS_VOLUME
    #undef FULL_VOLUME
    #undef OPTIONS_SECTION_SOUND
    #undef DASH_SLOTS
    #undef SOUND_VOLUME
    #undef SOUND_VOLUME_DIRTY
}

extern s32 *lbl_8055D4AC;
extern void fn_80128668(void *);
#pragma use_lmw_stmw off
#pragma cplusplus on
/* Tear down the dashboard sound player: release each sound in its two groups of
 * three, free the block, and clear the global pointer. */
extern "C" void fn_800120BC(void) {
    #define gDashSoundPlayer lbl_8055D4AC
    struct Sound {
        virtual void release(s32);
        virtual void v1();
        virtual void v2();
    };
    s32 slotIndex;
    s32 groupIndex;
    u8 *group;
    u8 *slot;
    s32 *playerBlock;
    if ((playerBlock = gDashSoundPlayer) != 0) {
        slotIndex = 0;
        groupIndex = 0;
        group = (u8 *)playerBlock;
        slot = group;
        for (; groupIndex < 2; ++groupIndex, group += 0xC) {
            slot = group;
            slotIndex = 0;
            for (; slotIndex < 3; ++slotIndex, slot += 4) {
                void *sound = *(void **)(slot + 4);
                if (sound == 0)
                    goto next;
                if (sound == 0)
                    goto next;
                ((struct Sound *)sound)->release(1);
            next:
                ;
            }
        }
        fn_80128668(playerBlock);
    }
    gDashSoundPlayer = 0;
    #undef gDashSoundPlayer
}
#pragma cplusplus reset
/* Activates the current entry in lbl_8055D4AC's primary slot table, sets its active/state flags, and advances/wraps the table index. */
void fn_80012158(void) {
    u8 *object;
    s32 *state;
    state = (s32 *)lbl_8055D4AC;
    object = *(u8 **)((u8 *)state + state[0] * 4 + 4);
    if (object == 0) return;
    object[0x49] = 1;
    object[0x4B] = 0;
    object[0x4A] = 0;
    if (++state[0] < 3) return;
    state[0] = 0;
}

/* Activate the next queued object in slot group 2 of the state at lbl_8055D4AC: set its flags (0x49=1, 0x4B=0, 0x4A=0) and advance the index, wrapping at 3. */
void fn_800121A4(void) {
    u8 *object;
    s32 *state;
    state = (s32 *)lbl_8055D4AC;
    object = *(u8 **)((u8 *)state + state[0] * 4 + 0x10);
    if (object == 0) return;
    object[0x49] = 1;
    object[0x4B] = 0;
    object[0x4A] = 0;
    if (++state[0] < 3) return;
    state[0] = 0;
}

extern void LoadFloatOption(s32, void *, f32 *);
extern char lbl_802FC580[];
__declspec(section ".data") extern char lbl_802FC580[];
#pragma unroll off
#pragma optimize_for_size on
#pragma scheduling invalid_target
/* Reload the saved "effects_volume" setting and apply it to all loaded sounds in
 * the dashboard sound player block (lbl_8055D4AC). Both groups of three sound
 * slots are updated; a sound whose volume differs is given the new value and has
 * its volume-dirty flag set so the change reaches its voice. */
void fn_800121F0(void) {
    f32 volume = 1.0f;
    s32 *soundGroup;
    s32 groupIndex;
    register f32 soundVolume;
    void *sound0;
    void *sound1;
    void *sound2;
    soundGroup = (s32 *)lbl_8055D4AC;
    LoadFloatOption(4, (void *)lbl_802FC580, &volume);
    for (groupIndex = 0; groupIndex < 2; groupIndex++) {
        sound0 = (void *)soundGroup[1];
        if (sound0 != 0) {
            soundVolume = volume;
            if (soundVolume != *(f32 *)((u8 *)sound0 + 8)) {
                *((u8 *)sound0 + 0x4D) = 1;
                *(f32 *)((u8 *)sound0 + 8) = soundVolume;
            }
        }
        sound1 = (void *)soundGroup[2];
        if (sound1 != 0) {
            soundVolume = volume;
            if (soundVolume != *(f32 *)((u8 *)sound1 + 8)) {
                *((u8 *)sound1 + 0x4D) = 1;
                *(f32 *)((u8 *)sound1 + 8) = soundVolume;
            }
        }
        sound2 = (void *)soundGroup[3];
        if (sound2 != 0) {
            soundVolume = volume;
            if (soundVolume != *(f32 *)((u8 *)sound2 + 8)) {
                *((u8 *)sound2 + 0x4D) = 1;
                *(f32 *)((u8 *)sound2 + 8) = soundVolume;
            }
        }
        soundGroup += 3;
    }
}
// Formats the ordinal string for number into outBuffer and returns outBuffer.
s32 fn_800122B4(s32 number, s32 outBuffer) {
    struct { char sp8[0x14]; volatile s32 sp1C; } frame;

    fn_801310B4(frame.sp8, 0x14, number);
    frame.sp1C = fn_80130FE0(number);
    strcpy((char *)outBuffer, frame.sp8);
    return outBuffer;
}

void fn_8000F158(void) {
    /* Shut down UI text: release the big-text texture, free the active font and
       text queue, then clear the cached default UI font handle. */
#define bigTextTextureHandle lbl_8055D498
#define defaultUiFontHandle  lbl_8055D490
    fn_802328D4(bigTextTextureHandle);
    fn_80234470();
    defaultUiFontHandle = 0;
#undef defaultUiFontHandle
#undef bigTextTextureHandle
}

extern void fn_801310B4(void *, s32, s32);
extern s32 fn_80130FE0(s32);
extern char *strcpy(char *, const char *);
extern f32 lbl_805602B8;
extern f32 lbl_805602BC;
extern char lbl_802FC3A4[];
extern f64 lbl_80560278;
extern f64 fn_8002EFB4(f64);
extern void fn_801E7E18(void);
extern s32 lbl_802FC2A8[];
#define sBlinkPeriodSec lbl_80560278
#define sBlinkHalfDuty lbl_8056025C
#define Math_fmod(x, y) ((f64 (*)(f32, f64))fn_8002EFB4)(x, y)
#define Game_getTimeSec() ((f32 (*)(void))fn_801E7E18)()

enum {
    BAR_BLINK_MAX_PCT  = 15,
    BAR_LOW_MAX_PCT    = 40,
    BAR_MID_MAX_PCT    = 70,
    BAR_COLOR_WHITE    = -1,
    BAR_COLOR_RED      = (s32)0xFFF70000,
    BAR_COLOR_AMBER    = (s32)0xFFE5A703,
    BAR_COLOR_GREEN    = (s32)0xFF278F27
};
/* Return word 1 of the 3-word record `index` in the glyph-index table lbl_802FC2A8 (fn_8000DFC0 returns word 2); used by the text layout code. */
s32 fn_8000DFA8(s32 index) {
    return lbl_802FC2A8[index * 3 + 1];
}

/* Return the third word (offset +8) of the 12-byte attribute record for
 * `index` in the lbl_802FC2A8 lookup table. */
s32 fn_8000DFC0(s32 index) {
    return lbl_802FC2A8[index * 3 + 2];
}

#pragma push
#pragma processor 750
#pragma scheduling on
void fn_8000DFD8(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 count = *(s32 *)((char *)arg0 + 0x34);
    if (count > 0 && *(s32 *)((char *)arg0 + 0x38) == 9) {
        ((void (*)(u32, f32, f32, f32, f32))fn_800109E4)(
            (u32)(((s32)(lbl_80560258 * (f32)count) << 24) | 0x00FDB300),
            arg2, arg3 + lbl_80560254 * lbl_8056025C,
            lbl_80560250, lbl_80560254);
    }
    ((void (*)(u32, f32, f32, f32, f32))fn_800109E4)(
        (u32)-1, arg2, arg3 + lbl_80560254 * lbl_8056025C,
        ((f32)*(s32 *)((char *)arg0 + 0x30) * lbl_80560250) / lbl_80560260,
        lbl_80560254);
    ((void (*)(u32, f32, f32, f32, f32))fn_800109E4)(
        (u32)arg1, arg2, arg3 + lbl_80560254 * lbl_8056025C,
        ((f32)*(s32 *)((char *)arg0 + 0x2C) * lbl_80560250) / lbl_80560260,
        lbl_80560254);
    ((void (*)(s32, s32, const char *, void *, f32, ...))fn_80010074)(
        -1, 0x14, (const char *)&lbl_80558AA4, arg0,
        lbl_80560264, arg2 + lbl_80560250 * lbl_8056025C, arg3);
}
#pragma pop
extern f32 lbl_80560250, lbl_80560254, lbl_80560258, lbl_8056025C, lbl_80560260, lbl_80560264, lbl_80560270;
#pragma push
#pragma scheduling on
void fn_8000E15C(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 count = *(s32 *)((char *)arg0 + 0x34);
    if (count > 0) {
        if (*(s32 *)((char *)arg0 + 0x38) == 9) {
            ((void (*)(u32, f32, f32, f32, f32))fn_800109E4)(
                (u32)(((s32)(lbl_80560258 * (f32)count) << 24) | 0x00FDB300),
                arg2, arg3 + lbl_80560254 * lbl_8056025C,
                lbl_80560250, lbl_80560254);
        }
    }
    ((void (*)(u32, f32, f32, f32, f32))fn_800109E4)(
        (u32)-1, arg2, arg3 + lbl_80560254 * lbl_8056025C,
        ((f32)*(s32 *)((char *)arg0 + 0x30) * lbl_80560250) / lbl_80560260,
        lbl_80560254);
    ((void (*)(u32, f32, f32, f32, f32))fn_800109E4)(
        (u32)arg1, arg2, arg3 + lbl_80560254 * lbl_8056025C,
        ((f32)*(s32 *)((char *)arg0 + 0x2C) * lbl_80560250) / lbl_80560260,
        lbl_80560254);
    ((void (*)(s32, s32, const char *, void *, f32, ...))fn_80010074)(
        -1, 0x11, (const char *)&lbl_80558AA4, arg0,
        lbl_80560264, lbl_80560270 + arg2, arg3);
}
#pragma pop
/* Returns an ARGB color value for the given color index. */
s32 fn_8000E2D8(s32 colorIndex) {
    switch (colorIndex) {
    default:
    case 0:
        return -1;
    case 1:
        return -0x29FFC4;
    case 2:
        return 0xFF2DC82D;
    case 3:
        return 0xFF2D2DC8;
    case 4:
        return -0x100;
    }
}

/* HudBar_getColorForPercent: choose the ARGB fill color for a HUD percentage bar (blinking white/red at <=15%, red at <=40%, amber at <=70%, green above 70%). */
s32 fn_8000E338(s32 percent) {
    s32 barColor;
    if (percent <= BAR_BLINK_MAX_PCT) {
        if ((f32)Math_fmod(Game_getTimeSec(), sBlinkPeriodSec) > sBlinkHalfDuty)
            return BAR_COLOR_WHITE;
    }
    if (percent <= BAR_LOW_MAX_PCT) return BAR_COLOR_RED;
    barColor = BAR_COLOR_GREEN;
    if (percent <= BAR_MID_MAX_PCT) barColor = BAR_COLOR_AMBER;
    return barColor;
}

void fn_8000E3B4(s32 arg0) {
int __repair_literal;

    extern f32 lbl_80560250;
    extern f32 lbl_80560254;
    extern f32 lbl_8056025C;
    extern f32 lbl_80560260;
    extern f32 lbl_80560264;
    extern f32 lbl_80560270;
    extern f32 lbl_80560280;
    extern f32 lbl_80560284;
    extern f32 lbl_80560288;
    extern f32 lbl_8056028C;
    extern f32 lbl_80560290;
    extern f64 lbl_80560298;
    extern f32 lbl_805602A0;
    extern s32 lbl_8055D48C;
    extern s32 lbl_80558AA4;
    extern char lbl_80558AA8;
    extern char lbl_80558AAC;
    extern char lbl_80558AB0;
    extern char lbl_80558AB8;
    extern char lbl_80558ABC;
    extern f32 fn_80011E34(void);
    extern f32 fn_80011DD4(s32);
    extern f32 fn_80011E54(void);
    extern f32 fn_80011DC0(s32);
    extern s32 fn_8000DFA8(s32);
    extern s32 fn_8000DFC0(s32);
    extern f32 getPictureHeight(s32, s32);
    extern f32 getPictureWidth(s32, s32);
    extern f32 fn_80011EC8(s32);
    extern s32 fn_8000E2D8(s32);
    extern s32 fn_8000E338(s32);
    extern void fn_8000DFD8(void *, s32, f32, f32);
    extern void fn_80010074(s32, s32, const char *, f32, f32, f32, ...);
    extern s32 fn_800122B4(s32, s32);
    extern void fn_800109E4(s32, f32, f32, f32, f32);
    extern int sprintf(char *, const char *, ...);
    char buf[16];
    char *base, *entry;
    s32 i, a, b;
    f32 width, y, h, inset, x, x0, x1, x2, y1, aWidth, limit, v, q;
__repair_literal = 1;

    if (*(s32 *)((char *)&lbl_80350F88 + 0x288) < __repair_literal) return;
    if (arg0 < 0) y = fn_80011E54();
    else y = fn_80011DC0(arg0);
    a = fn_8000DFA8(0);
    h = getPictureHeight(lbl_80350F88, a);
    limit = fn_80011EC8(arg0) - h;
    v = lbl_80560280;
    v = v < limit ? v : limit;
    y = v + y - lbl_80560284;
    if (arg0 < 0) width = fn_80011E34();
    else width = fn_80011DD4(arg0);
    base = (char *)&lbl_80350F88;
    inset = *(u8 *)(base + 4) ? lbl_80560288 : lbl_80560280;
    limit = lbl_80560280;
    entry = base + 8;
    for (i = 0; i < *(s32 *)(base + 0x288); entry += 0x40, i++) {
        a = fn_8000DFA8(*(s32 *)(entry + 0x38));
        b = fn_8000DFC0(*(s32 *)(entry + 0x38));
        aWidth = getPictureWidth(lbl_80350F88, a) + inset;
        h = getPictureHeight(lbl_80350F88, a);
        x = (width + aWidth - lbl_8056028C) * *(f32 *)(entry + 0x3c) + lbl_8056028C - aWidth;
        getPictureWidth(lbl_80350F88, b);
        x0 = x + lbl_80560290;
        x2 = x + aWidth;
        y1 = lbl_80560264 + (y - h * lbl_8056025C);
        x2 = x2 - lbl_80560290;
        x1 = lbl_80560290 + x0;
        switch (*(s32 *)(entry + 0x38)) {
        case 1:
            fn_80010074(fn_8000E2D8(*(s32 *)(entry + 0x2c)), 0x11, (const char *)&lbl_80558AA4, lbl_80560264, x1, y1, entry);
            break;
        case 2:
            fn_80010074(-1, 0x12, (const char *)&lbl_80558AAC, lbl_80560264,
                        ((f32 (*)(const char *, f32))fn_800108C8)(&lbl_80558AA8, lbl_80560264) + x1, y1, *(s32 *)(entry + 0x2c));
            fn_80010074(-1, 0x11, (const char *)&lbl_80558AA4, lbl_80560264,
                        ((f32 (*)(const char *, f32))fn_800108C8)(&lbl_80558AB0, lbl_80560264) + x1, y1, entry);
            break;
        case 3:
            sprintf(buf, (const char *)&lbl_80558AAC, *(s32 *)(entry + 0x2c));
            switch (*(s32 *)(entry + 0x30)) {
            case 5: fn_800122B4(*(s32 *)(entry + 0x2c), (s32)buf); break;
            case 6: sprintf(buf, (const char *)&lbl_80558AB8, *(s32 *)(entry + 0x2c)); break;
            }
            fn_80010074(fn_8000E2D8(*(s32 *)(entry + 0x30)), 0x11, (const char *)&lbl_80558AA4, lbl_80560264, x1, y1, entry);
            fn_80010074(fn_8000E2D8(*(s32 *)(entry + 0x30)), 0x12, (const char *)&lbl_80558AA4, lbl_80560264, x2 - lbl_80560270, y1, buf);
            break;
        case 4:
            fn_80010074(-1, 0x11, (const char *)&lbl_80558AA4, lbl_80560264, x1, y1, entry);
            fn_80010074(-1, 0x12, (const char *)&lbl_80558ABC, lbl_80560264, x2 - lbl_80560270, y1, *(s32 *)(entry + 0x2c), *(s32 *)(entry + 0x30));
            break;
        case 5:
            fn_80010074(-0x2fc1, 0x11, (const char *)&lbl_80558AA4, lbl_80560264, x1, y1, entry);
            if ((f32)((f64 (*)(f32, f64))fn_8002EFB4)(((f32 (*)(void))fn_801E7E18)(), lbl_80560298) > lbl_805602A0)
                fn_80010074(-0x2fc1, 0x12, (const char *)&lbl_80558ABC, lbl_80560264, x2 - lbl_80560270, y1, *(s32 *)(entry + 0x2c), *(s32 *)(entry + 0x30));
            break;
        case 6:
            a = fn_8000E338(*(s32 *)(entry + 0x2c));
            fn_8000DFD8(entry, a, x0 + inset, y1);
            break;
        case 7:
            a = fn_8000E338(*(s32 *)(entry + 0x2c));
            fn_8000DFD8(entry, a, x0 + inset, y1);
            q = (f32)*(u32 *)(entry + 0x34) * lbl_80560250 / lbl_80560260;
            fn_800109E4(lbl_8055D48C, x0 + inset + q, y1 + lbl_80560254 * lbl_8056025C, lbl_80560250 - q, lbl_80560254);
            break;
        case 8:
            a = fn_8000E338(*(s32 *)(entry + 0x2c));
            fn_8000DFD8(entry, a, x0 + inset, y1);
            break;
        case 9:
            fn_8000DFD8(entry, 0xFF2D2DC8, x0 + inset, y1);
            break;
        }
        limit = limit > *(f32 *)(entry + 0x3c) ? limit : *(f32 *)(entry + 0x3c);
        y -= h - lbl_80560264;
    }
}

extern s32 fn_8000DFA8(s32);
extern s32 fn_8000DFC0(s32);
extern s32 fn_8000E2D8(s32);
extern s32 fn_8000E338(s32);
extern void fn_8000DFD8(void *, s32, f32, f32);
extern void fn_8000E15C(void *, s32, f32, f32);
extern f32 fn_80011DEC(s32);
extern f32 fn_80011E34(void);
extern f32 fn_80011EC8(s32);
extern s32 lbl_8055CFF0, lbl_8055D48C;
extern f32 lbl_80560288, lbl_80560290, lbl_805602A0, lbl_805602A4, lbl_805602A8, lbl_805602AC, lbl_805602B0, lbl_805602B4;
extern f64 lbl_80560298;
extern char lbl_80558AAC, lbl_80558AB8, lbl_80558ABC, lbl_80558AC4;
#pragma opt_common_subs off
void fn_8000E874(s32 arg0) {
    char buf[16];
    char *base;
    char *entry, *end;
    s32 i, a, b, color;
    f32 width, y, h, inset, x, x1, x2, y1, aWidth, limit, half, twenty;
    if (*(s32 *)((char *)&lbl_80351214 + 0x288) < 1) return;
    if (arg0 < 0) width = fn_80011E34();
    else width = fn_80011DEC(arg0);
    if (arg0 < 0) y = fn_80011E54();
    else y = fn_80011DC0(arg0);
    a = fn_8000DFA8(0);
    h = getPictureHeight(lbl_80351214, a);
    limit = fn_80011EC8(arg0) - h;
    y = (limit > 0.0f ? limit : 0.0f) + y;
    base = (char *)&lbl_80351214;
    inset = *(u8 *)(base+4) ? 56.0f : 0.0f;
    
    half = lbl_8056025C; twenty = lbl_805602B4;
    entry = base + 8;
    end = (char *)&lbl_80351214;
    limit = 0.0f;
    for (i = 0; i < *(s32 *)(end + 0x288); entry += 0x40, i++) {
        a = fn_8000DFA8(*(s32 *)(entry + 0x38));
        b = fn_8000DFC0(*(s32 *)(entry + 0x38));
        aWidth = getPictureWidth(lbl_80351214, a) + inset;
        h = getPictureHeight(lbl_80351214, a);
        x = 5.0f + (f32)lbl_8055CFF0;
        x += *(f32 *)(entry + 0x3c) * (width - x);
        getPictureWidth(lbl_80351214, b);
        x1 = 9.0f + x;
        x2 = 5.0f + x;
        x += aWidth;
        y1 = 1.0f + (y - h * half);
        switch (*(s32 *)(entry + 0x38)) {
        case 1:
            fn_8000FF88(fn_8000E2D8(*(s32 *)(entry+0x2c)), 0x12, (const char *)&lbl_80558AA4, 1.1f, x1, y1, entry);
            break;
        case 2:
            fn_8000FF88(-1, 0x12, (const char *)&lbl_80558AC4, 1.4f, x1, y1, *(s32 *)(entry+0x2c), entry);
            break;
        case 3:
            sprintf(buf, (const char *)&lbl_80558AAC, *(s32 *)(entry+0x2c));
            switch (*(s32 *)(entry+0x30)) {
            case 5: fn_800122B4(*(s32 *)(entry+0x2c), (s32)buf); break;
            case 6: sprintf(buf, (const char *)&lbl_80558AB8, *(s32 *)(entry+0x2c)); break;
            }
            fn_8000FF88(fn_8000E2D8(*(s32 *)(entry+0x30)), 0x11, (const char *)&lbl_80558AA4, 1.0f, x1, y1, entry);
            fn_8000FF88(fn_8000E2D8(*(s32 *)(entry+0x30)), 0x12, (const char *)&lbl_80558AA4, 1.0f, x-4.0f, y1, buf);
            break;
        case 4:
            fn_8000FF88(-1, 0x11, (const char *)&lbl_80558AA4, 1.0f, x1, y1, entry);
            fn_8000FF88(-1, 0x12, (const char *)&lbl_80558ABC, 1.0f, x-4.0f, y1, *(s32 *)(entry+0x2c), *(s32 *)(entry+0x30));
            break;
        case 5:
            fn_8000FF88(-0x2fc1, 0x11, (const char *)&lbl_80558AA4, 1.0f, x1, y1, entry);
            if ((f32)((f64 (*)(f32, f64))fn_8002EFB4)(((f32 (*)(void))fn_801E7E18)(), lbl_80560298) > 0.1f)
                fn_8000FF88(-0x2fc1, 0x12, (const char *)&lbl_80558ABC, 1.0f, x-4.0f, y1, *(s32 *)(entry+0x2c), *(s32 *)(entry+0x30));
            break;
        case 6:
            a = fn_8000E338(*(s32 *)(entry+0x2c));
            fn_8000DFD8(entry, a, x2, y1);
            break;
        case 7:
            a = fn_8000E338(*(s32 *)(entry+0x2c));
            fn_8000DFD8(entry, a, x2, y1);
            fn_800109E4(lbl_8055D48C, x2 + ((f32)*(s32 *)(entry+0x34) * 89.0f) / 100.0f - 1.0f, y1 + 17.0f*half, 2.0f, 17.0f);
            break;
        case 8:
            a = fn_8000E338(*(s32 *)(entry+0x2c));
            fn_8000DFD8(entry, a, x2 + inset, y1);
            break;
        case 9:
            fn_8000E15C(entry, 0xFF2D2DC8, x2, y1);
            break;
        case 10:
            aWidth = y1 + half * twenty;
            fn_8000FF88(fn_8000E2D8(*(s32 *)(entry+0x2c)), 0x12, (const char *)&lbl_80558AA4, 1.0f, x1, y1, entry);
            if (*(s32 *)(entry+0x30) >= 0) ((void (*)(s32,s32,f32,f32,f32,f32))fn_80010E94)(lbl_8055D4CC, *(s32 *)(entry+0x30), x1, aWidth, twenty, twenty);
            break;
        }
        limit = limit > *(f32 *)(entry+0x3c) ? limit : *(f32 *)(entry+0x3c);
        y -= h - 1.0f;
    }
    a = fn_8000DFA8(0);
    b = fn_8000DFC0(0);
    getPictureWidth(lbl_80351214, a);
    getPictureWidth(lbl_80351214, b);
    getPictureHeight(lbl_80351214, a);
}
#pragma opt_common_subs reset
/* get_center_item_scale: the draw scale of a DCIT center item of the given kind.
 * With more than two racers every center item draws at 1.0; kinds 12 and 14 use
 * 1.5, kind 13 uses 1.8 and kind 11 uses 1.0.  Any other kind is a fatal error. */
f32 fn_8000EDC0(s32 itemKind) {
    #define CENTER_SCALE_ONE   lbl_80560264 /* 1.0f */
    #define CENTER_SCALE_LARGE lbl_805602B8 /* 1.5f */
    #define CENTER_SCALE_TALL  lbl_805602BC /* 1.8f */
    #define sScaleAssertMsg    lbl_802FC3A4 /* "get_center_item_scale(%d) - not a center (DCIT_)" */
    #define sPanic             Abend_Panic
    #define sGetPlayerCount    fn_801E85A4
    if (sGetPlayerCount() > 2)
        return CENTER_SCALE_ONE;
    switch (itemKind) {
    case 12:
        return CENTER_SCALE_LARGE;
    case 13:
        return CENTER_SCALE_TALL;
    case 14:
        return CENTER_SCALE_LARGE;
    default:
        sPanic(&sScaleAssertMsg, itemKind);
    case 11:
        return CENTER_SCALE_ONE;
    }
    #undef CENTER_SCALE_ONE
    #undef CENTER_SCALE_LARGE
    #undef CENTER_SCALE_TALL
    #undef sScaleAssertMsg
    #undef sPanic
    #undef sGetPlayerCount
}

/* Get the center-item color value for a DCIT menu item kind; invalid kinds log and return -1. */
s32 fn_8000EE54(s32 itemKind) {
    switch (itemKind) {
    case 12:
        return -0x5400;
    case 13:
        return -1;
    case 14:
        return -0x5400;
    default:
        Abend_Panic(lbl_802FC3DC, itemKind);
    case 11:
        return -1;
    }
}

#pragma dont_inline on
f32 fn_8000EEC8(s32 regionId, f32 listHeight) {
    /* Top edge of a HUD list of the given total height inside layout region
     * regionId (negative: the whole screen, whose box is lbl_80350EC4 as
     * {top, left, right, bottom}, so fn_80011E90 is its vertical centre).
     * With one player (fn_801E85A4 is the player count) the list simply starts
     * 100 below the region's top; with more players the top is blended 0.2/0.8
     * between the region's two stored tops (lbl_80350F28[region][0] and [5]),
     * and half the list's height is added back to centre it. */
    f32 top;
    f32 scaledTop;
    f32 scaledAltTop;
    if (fn_801E85A4() == 1) {
        if (regionId < 0) top = fn_80011E54();
        else top = fn_80011DC0(regionId);
        return top - lbl_80560260; /* 100.0f */
    }
    if (regionId < 0) top = fn_80011E90();
    else {
        scaledTop = lbl_805602C4 * fn_80011DC0(regionId); /* 0.2f */
        scaledAltTop = fn_80011E1C(regionId) * lbl_805602C0; /* 0.8f */
        top = scaledAltTop + scaledTop;
    }
    return top + (lbl_8056025C * listHeight); /* 0.5f */
}

#pragma push
#pragma opt_lifetimes off
void fn_8000EF74(s32 arg0) {
    extern f32 fn_8000EDC0(s32);
    extern s32 fn_8000EE54(s32);
    extern f32 fn_8000EEC8(s32, f32);
    extern void fn_80010074(s32, s32, const char *, f32, f32, f32, ...);
    extern f32 fn_80011E70(void);
    u8 *root;
    u8 *entry1;
    u8 *entry2;
    f32 temp_f28;
    s32 i2;
    s32 i1;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    f32 temp_f27;
    f32 temp_f26;
    f32 temp_f25;
    if (*(s32 *)((u8 *)&lbl_803514A0 + 0x288) != 0) {
        if (arg0 < 0) temp_f29 = fn_80011E70();
        else temp_f29 = fn_80011E04(arg0);
        root = (u8 *)&lbl_803514A0;
        entry1 = root;
        temp_f30 = lbl_80560280;
        i1 = 0;
        while (i1 < *(s32 *)(root + 0x288)) {
            temp_f30 += fn_8000EDC0(*(s32 *)(entry1 + 0x40));
            entry1 += 0x40;
            i1++;
        }
        temp_f30 *= (f32)lbl_80558A90;
        temp_f28 = fn_8000EEC8(arg0, temp_f30);
        temp_f31 = lbl_8056025C;
        entry2 = root + 8;
        i2 = 0;
        while (i2 < *(s32 *)(root + 0x288)) {
            temp_f27 = fn_8000EDC0(*(s32 *)(entry2 + 0x38));
            temp_f26 = temp_f27 * (f32)lbl_80558A90;
            temp_f25 = temp_f28 - temp_f31 * temp_f26;
            fn_80010074(fn_8000EE54(*(s32 *)(entry2 + 0x38)), 0x14,
                        (const char *)entry2, temp_f27, temp_f29, temp_f25);
            temp_f28 -= temp_f26;
            entry2 += 0x40;
            i2++;
        }
    }
}
#pragma pop
/* Initialize UI font/text handles and scaling: cache the default font handle and its scaled metric, store the computed scale factor, and load the big text texture. */
void fn_8000F0E4(void) {
#define defaultUiFontHandle   lbl_8055D490
#define uiTextScaleMetric     lbl_80558A90
#define uiScaleFactor         lbl_8055D49C
#define bigTextTextureHandle  lbl_8055D498
#define uiTextScaleMultiplier lbl_805602C8
#define bigTextTextureName    lbl_802FC414
    s32 fontHandle;
    f32 fontSize;

    fontHandle = fn_8023441C();
    defaultUiFontHandle = fontHandle;
    fontSize = (f32)fn_80232B70(fontHandle);
    uiTextScaleMetric = (s32)(uiTextScaleMultiplier * fontSize);
    *(f32 *)&uiScaleFactor = fn_80011EDC();
    bigTextTextureHandle = loadFontTexture((s32)bigTextTextureName);
#undef bigTextTextureName
#undef uiTextScaleMultiplier
#undef bigTextTextureHandle
#undef uiScaleFactor
#undef uiTextScaleMetric
#undef defaultUiFontHandle
}

