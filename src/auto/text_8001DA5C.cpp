#include <types.h>
#include <math.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern f32 lbl_8055E3C8;
extern f32 lbl_80560470;
extern f32 lbl_80560474;
extern f32 lbl_80560490;

extern "C" s32 fn_80128668(void);
extern void* lbl_80358680[];

/* Indices into the HUD overlay table lbl_80358680 (allocated in fn_8001DB54). */
enum {
    OVERLAY_SCORE = 0,
    OVERLAY_OVERHEAT = 1,
    OVERLAY_GRADE = 2,
    OVERLAY_LAP_TITLE = 3,
    OVERLAY_CONTINUE = 4,
    OVERLAY_OUT_OF_TIME = 5,
    OVERLAY_COUNT = 6
};

class CollisionEntry {
public:
    virtual void unk0();
    virtual void apply(s32, s32);
};
extern s32 lbl_8055E3C4;
extern "C" void** lbl_8055D5FC;
extern "C" void** lbl_8055D600;
extern "C" void** lbl_8055D604;
extern "C" void** lbl_8055D5F4;
extern "C" void** lbl_8055D5F8;

class CleanupEntry {
public:
    virtual void cleanup(s32);
};

class PaneContainer {
public:
    virtual void dummy0();
    virtual void* getPane(const char* name);
    virtual void* select(const char* name);
};

struct PaneData {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    f32 f10;
    u32 w14;
    u32 w18;
    u32 w1c;
};

extern "C" const char* fn_80131234(const char*);
extern "C" void fn_80147230(void*, const char*, ...);
extern "C" void fn_801476C4(...);
extern "C" s32 fn_80147C50(u32, u32, f32);
extern "C" void fn_80147CEC(void*, void*, void*, f32);
extern "C" void* fn_8017960C(s32);
extern "C" s32 fn_801E85A4(void);
extern "C" void fn_80232928(s32);
extern "C" void fn_80232930(void);

extern char lbl_802FDB68[], lbl_802FDC70[];
extern f32 lbl_80560478;
extern char lbl_802FDC84[], lbl_802FDC5C[], lbl_802FDC48[], lbl_802FDC34[];
extern "C" int lbl_802FDC98[];
extern "C" void* fn_80145E70(void*);
extern "C" void* fn_801284F8(u32, void*);
extern "C" void* fn_802CAC28(void*, s32);
extern "C" void* fn_80207848(void*, s32);
extern char lbl_80558D08[4];
__declspec(section ".data") extern f32 lbl_80558DC4;
extern f32 lbl_8056047C;
extern f32 lbl_80560480;
extern f32 lbl_80560484;
extern f32 lbl_80560488;
extern f32 lbl_8056048C;
extern f32 lbl_80560460;
extern f32 lbl_80560464;
extern f64 lbl_80560468;

/* ---- the overheat overlay (fn_8001E2AC) ----
 * One slot per player in the array handed to it, three floats at playerIndex *
 * 3 (fn_8001E544 clears them): [1] the time the truck started overheating, [2]
 * the 0..1 level of its OVERHEAT text and [3] the truck's own warning level.
 */
#define OVERLAY_ONE       lbl_80560470  /* 1.0f: a full overheat, and the top of every clamp */
#define OVERLAY_ZERO      lbl_80560474  /* 0.0f: no overheat, and the bottom of every clamp */
#define OVERLAY_COOL_RATE lbl_8056047C  /* 0.0333667: what a level loses per frame */
#define OVERLAY_SHOW_MIN  lbl_80560480  /* 0.01: below this the OVERHEAT text is dropped */
#define OVERLAY_ALPHA_MAX lbl_80560484  /* 255.0f: the text's alpha at a full level */
#define OVERLAY_FADE_TIME lbl_80560488  /* 0.4: seconds the text takes to fade in */
#define OVERLAY_WARN_MIN  lbl_8056048C  /* 0.66: above this the warn pane shows */
#define FLOAT_EPS         lbl_80558DC4  /* 2^-23: "has this float moved at all" */
#define sOverlayTime      lbl_8055E3C8  /* the overlay module's clock, fn_8001DAE8() */
#define STR_PERCENT_S     lbl_80558D08  /* "%s" */
#define overlayPulse      fn_8001DAD8   /* the 0..1 sine pulse fn_8001DA5C(0x40) */
#pragma push
#pragma scheduling invalid_target
extern "C" f32 fn_8001DA5C(s32 arg0) {
    s32 quotient = lbl_8055E3C4 / arg0;
    f32 fraction = (f32)(lbl_8055E3C4 - quotient * arg0);
    f32 angle = (f32)arg0;
    f32 scale = lbl_80560460;
    f32 x = (scale * fraction) / angle;
    return lbl_80560464 + lbl_80560464 * (f32)sin((double)x);
}
#pragma pop
extern "C" void fn_8001DAD8(void) { extern int fn_8001DA5C(int); fn_8001DA5C(0x40); }

extern "C" void fn_8001DAE0(f32* dest, f32 value) {
    /* Store a float into a field: a tiny setter used to initialize f32 members. */
    *dest = value;
}

extern "C" f32 fn_8001DAE8(void) {
    return lbl_8055E3C8;
}

#pragma dont_inline on
extern "C" f32 fn_8001DAF0(void *arg0) {
    f32 v = (fn_8001DAE8() - *(f32 *)((u8 *)arg0 + 4)) / *(f32 *)arg0;
    f32 r = lbl_80560470;
    r = r < v ? r : v;
    r = r > lbl_80560474 ? lbl_80560474 : r;
    return r;
}

#pragma scheduling invalid_target
extern "C" void fn_8001DB54(void) {
    char* base = lbl_802FDB68;
    register void* object;

    lbl_8055D5F4 = (void**)fn_80145E70(base + 0);
    lbl_8055D5F8 = (void**)fn_80145E70(base + 0xC);
    lbl_8055D5FC = (void**)fn_80145E70(base + 0x1C);
    lbl_8055D600 = (void**)fn_80145E70(base + 0x28);
    lbl_8055D604 = (void**)fn_80145E70(base + 0x38);

    object = fn_801284F8(0xC, base + 0x48);
    if (object != 0) {
        *(void**)object = lbl_802FDC98;
        *(void**)((u8*)object + 4) = fn_802CAC28(base + 0x58, 0);
    }
    lbl_80358680[0] = object;

    object = fn_801284F8(0x64, base + 0x68);
    if (object != 0) *(void**)object = lbl_802FDC84;
    lbl_80358680[1] = object;

    object = fn_801284F8(0x38, base + 0x78);
    if (object != 0) {
        f32 initial_value = lbl_80560478;
        *(void**)object = lbl_802FDC70;
        fn_8001DAE0((f32*)((u8*)object + 0x28), initial_value);
        fn_8001DAE0((f32*)((u8*)object + 0x30), lbl_80560464);
        *(void**)((u8*)object + 0x24) = fn_80207848(base + 0x88, 1);
        *(s32*)((u8*)object + 4) = -1;
        *(s32*)((u8*)object + 8) = -1;
        *(s32*)((u8*)object + 0xC) = -1;
        *(s32*)((u8*)object + 0x10) = -1;
        *(s32*)((u8*)object + 0x14) = -1;
        *(s32*)((u8*)object + 0x18) = -1;
        *(s32*)((u8*)object + 0x1C) = -1;
        *(s32*)((u8*)object + 0x20) = -1;
    }
    lbl_80358680[2] = object;

    object = fn_801284F8(0x44, base + 0x98);
    if (object != 0) *(void**)object = lbl_802FDC5C;
    lbl_80358680[3] = object;

    object = fn_801284F8(4, base + 0xA8);
    if (object != 0) *(void**)object = lbl_802FDC48;
    lbl_80358680[4] = object;

    object = fn_801284F8(4, base + 0xB8);
    if (object != 0) *(void**)object = lbl_802FDC34;
    lbl_80358680[5] = object;
}
#pragma scheduling on

extern "C" s32 fn_8001DD2C(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma scheduling on
/* Global layout pane containers built by fn_8001DB54, named after the
 * layout resources they hold ("betalyt.val", "betares.val", etc.). */
#define sBetalyLayout      lbl_8055D5F4
#define sBetaly2Layout     lbl_8055D5F8
#define sBetaresLayout     lbl_8055D5FC
#define sBetares2Layout    lbl_8055D600
#define sLaptitleLayout    lbl_8055D604
#define sHudOverlays       lbl_80358680

/* HUD/race-overlay teardown: destroy every layout pane container and HUD
 * overlay widget created by fn_8001DB54, then clear all their global slots. */
extern "C" void fn_8001DD6C(void) {
    if (sLaptitleLayout != 0) ((CleanupEntry*)sLaptitleLayout)->cleanup(1);
    sLaptitleLayout = 0;
    if (sBetaresLayout != 0) ((CleanupEntry*)sBetaresLayout)->cleanup(1);
    sBetaresLayout = 0;
    if (sBetares2Layout != 0) ((CleanupEntry*)sBetares2Layout)->cleanup(1);
    sBetares2Layout = 0;
    if (sBetalyLayout != 0) ((CleanupEntry*)sBetalyLayout)->cleanup(1);
    sBetalyLayout = 0;
    if (sBetaly2Layout != 0) ((CleanupEntry*)sBetaly2Layout)->cleanup(1);
    sBetaly2Layout = 0;
    for (s32 i = 0; i < OVERLAY_COUNT; i++) {
        if (sHudOverlays[i] != 0) ((CleanupEntry*)sHudOverlays[i])->cleanup(1);
        sHudOverlays[i] = 0;
    }
}
#pragma scheduling invalid_target
/* Calls virtual method 2 on each of the 6 HUD overlay objects. */
extern "C" void fn_8001DEA8(void) {
    class HudOverlay {
    public:
        virtual void v0();
        virtual void v1();
        virtual void update();
    };
    void ***overlayPtr;
    u32 index;
    overlayPtr = (void ***)lbl_80358680;
    index = 0;
    do {
        HudOverlay *overlay = (HudOverlay *)overlayPtr[0];
        overlay->update();
        index++;
        overlayPtr++;
    } while (index < 6);
}
#pragma scheduling on
extern "C" void fn_8001DF04(void) {
}

/* Notifies the ScoreOverlay and GradeOverlay HUD widgets of a score/star update
   for the given player. */
extern "C" void fn_8001DF08(s32 playerIndex, s32 stars) {
    ((CollisionEntry*)lbl_80358680[OVERLAY_SCORE])->apply(playerIndex, stars);
    ((CollisionEntry*)lbl_80358680[OVERLAY_GRADE])->apply(playerIndex, stars);
}

// Invalid-target scheduling reuses r5 for the object base before passing the zero argument.
#pragma scheduling invalid_target
/* Refresh the overheat HUD overlay for the given racer (its virtual apply method). */
extern "C" void fn_8001DF84(s32 playerIndex) {
    void *overlay = sHudOverlays[OVERLAY_OVERHEAT];
    ((CollisionEntry *)overlay)->apply(playerIndex, 0);
}
#pragma scheduling invalid_target
/* Refresh the lap-title HUD overlay for the given racer via its virtual apply. */
extern "C" void fn_8001DFA8(s32 playerIndex) {
    ((CollisionEntry*)sHudOverlays[OVERLAY_LAP_TITLE])->apply(playerIndex, 0);
}
#pragma scheduling on
// Invalid-target scheduling keeps the table load ahead of the literal arguments.
#pragma scheduling invalid_target
/* Show the continue-prompt HUD overlay via its virtual apply; the two arguments
 * are placeholders and are ignored by the overlay. */
extern "C" void fn_8001DFCC(void) {
    ((CollisionEntry *)sHudOverlays[OVERLAY_CONTINUE])->apply(9, 17);
}
#pragma scheduling on
/* Update the out-of-time HUD overlay with zeroed arguments (hide/reset it). */
extern "C" void fn_8001DFF0(void) {
    ((CollisionEntry*)lbl_80358680[OVERLAY_OUT_OF_TIME])->apply(0, 0);
}

extern "C" void fn_802CAC54(void*);
extern "C" int lbl_802FDC98[];
/* Destructor for CollisionSpace: restore vtable, release owned collision resource, and conditionally free storage. */
extern "C" void* __dt__14CollisionSpaceFv(void* collisionSpace, s32 shouldDelete) {
    if (collisionSpace != 0) {
        *(void**)collisionSpace = lbl_802FDC98;
        fn_802CAC54(((void**)collisionSpace)[1]);
        if (shouldDelete > 0) {
            ((s32 (*)(void*))fn_80128668)(collisionSpace);
        }
    }
    return collisionSpace;
}

extern "C" void fn_801308F4(void *, s32, s32);
extern "C" void fn_801308F8(char *, s32, s32);
extern "C" void fn_801473F8(void *, const char *, ...);
extern "C" void fn_801476D8(void *, s32, s32);
extern "C" void fn_8014784C(void *, const char *, const char *, s32);
extern "C" s32 fn_801609C4(s32);
extern "C" s32 fn_80160A90(void);
extern "C" s32 fn_800167F4(s32);
extern "C" s32 fn_80204CF0(void);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" u32 lbl_80558D00;
#pragma scheduling invalid_target
/*
 * ScoreOverlay's score update - virtual slot +0xC of the vtable lbl_802FDC98
 * that fn_8001DB54 builds the "ScoreOverlay" HUD widget with.  It picks the
 * betalyt layout variant fn_801E85A4() asks for, selects the score art of the
 * current difficulty from the "excite_artset" set, points the star art at the
 * row the "star_color_1" pane carries, and writes value into the "score"
 * pane - together with the "score_denominator" pane while fn_800167F4()
 * reports one of the two plain score modes.
 */
extern "C" void fn_8001E078(void* overlay, s32 arg1, s32 value) {
    register char *strings = lbl_802FDB68;
    register s32 colorRow;
    register s32 texHandle;
    register PaneContainer *layout;
    s32 scoreArtIdx;
    s32 difficulty;
    s32 status;
    s32 flipped;
    s32 shifted;
    s32 cleared;
    PaneData *pane;
    PaneData paneData;
    char denomText[0x14];
    char scoreText[0x14];

    if (fn_801E85A4() == 2)
        layout = (PaneContainer*)lbl_8055D5F8;   // "betalyt_2.val"
    else
        layout = (PaneContainer*)lbl_8055D5F4;   // "betalyt.val"

    if (layout != 0) {
        difficulty = fn_80204CF0();
        switch (difficulty) {
        case 0:
            scoreArtIdx = 0;
            break;
        case 1:
            scoreArtIdx = 2;
            break;
        case 2:
            scoreArtIdx = 4;
            break;
        default:
            fn_802E30C8(strings + 0x158 /* "stdoverlay: Couldn't find score art idx ..." */,
                        difficulty);
            scoreArtIdx = 0;
            break;
        }
        fn_8014784C(layout, strings + 0x1A0 /* "score_art" */,
                    strings + 0x1AC /* "excite_artset" */, scoreArtIdx);
        texHandle = *(s32 *)((u8 *)overlay + 4);
        pane = (PaneData *)layout->getPane(strings + 0x1BC /* "star_color_1" */);
        colorRow = *(volatile s32 *)((u8 *)pane + 0x18);
        fn_801476D8(layout->select(strings + 0x1CC /* "score_star_art" */),
                    colorRow, texHandle);
        fn_801609C4(value);
        pane = (PaneData *)layout->getPane((const char *)&lbl_80558D00 /* "score" */);
        if (pane != 0) {
            s32 tempW8;
            s32 tempW4;
            paneData.w0 = pane->w0;
            tempW4 = ((volatile PaneData *)pane)->w4;
            tempW8 = ((volatile PaneData *)pane)->w8;
            paneData.w4 = tempW4;
            paneData.w8 = tempW8;
            paneData.wc = pane->wc;
            paneData.f10 = pane->f10;
            paneData.w14 = pane->w14;
            paneData.w18 = pane->w18;
            paneData.w1c = pane->w1c;
            status = ((s32 (*)(void))fn_800167F4)();
            flipped = status ^ 1;
            shifted = flipped >> 1;
            flipped &= status;
            cleared = flipped;
            if (((u32)(shifted - cleared) >> 31) == 0) { /* status is 0 or 1 */
                layout->getPane(strings + 0x1DC /* "score_slash" */);
                ((void (*)(void))fn_801476C4)();
                fn_801308F4(denomText, 0x14, fn_80160A90());
                fn_801473F8(layout, strings + 0x1E8 /* "score_denominator" */,
                             lbl_80558D08 /* "%s" */, denomText);
            }
            fn_801308F8(scoreText, 0x14, value);
            fn_80147230(&paneData, lbl_80558D08 /* "%s" */, scoreText);
        }
    }
}
#pragma scheduling on

extern "C" s32 fn_8001E26C(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma push
#pragma opt_propagation off
/* The overheat overlay of one player.  Its slot keeps a 0..1 level that is
   held at full while the truck is overheating (truck +0x2588) and otherwise
   falls by OVERLAY_COOL_RATE a frame, plus the truck's own warning level
   (truck +0x25A0).  While the level is above OVERLAY_SHOW_MIN the "OVERHEAT"
   text is drawn on the pane line interpolated between the "overheat_text" and
   "overheat_text_end" panes, fading in over OVERLAY_FADE_TIME seconds and
   pulsing its colour between the two panes' colours with an alpha of
   level * OVERLAY_ALPHA_MAX; otherwise a warning level above OVERLAY_WARN_MIN
   shows the "overheat_warn" pane, its colour pulsed between 0xC0FFFFFF and
   0xFFFF2020. */
extern "C" void fn_8001E2AC(void* slots, s32 playerIndex) {
    PaneData warnData;
    PaneData textData;
    f32* slot;
    const char* strings = lbl_802FDB68;
    void* truck = fn_8017960C(playerIndex);
    slot = (f32*)slots + playerIndex * 3;
    f32 zero;
    f32 heat;
    f32 cooled;
    heat = *(f32*)((u8*)truck + 0x2588);
    zero = OVERLAY_ZERO;
    bool active = heat > zero;
    if (active) {
        if (!((f32)fabs(slot[2] - OVERLAY_ONE) <= FLOAT_EPS)) {
            slot[1] = sOverlayTime;
        }
        slot[2] = OVERLAY_ONE;
    } else {
        f32 level = *(volatile f32 *)&slot[2];
        cooled = level - OVERLAY_COOL_RATE;
        slot[2] = cooled;
    }
    slot[3] = *(f32*)((u8*)truck + 0x25A0);
    PaneContainer* layout;
    if (fn_801E85A4() == 2) {
        layout = (PaneContainer*)lbl_8055D5F8;   /* "betalyt_2.val" */
    } else {
        layout = (PaneContainer*)lbl_8055D5F4;   /* "betalyt.val" */
    }
    if (layout == NULL) {
        return;
    }
    if (slot[2] > OVERLAY_SHOW_MIN) {
        playerIndex = (s32)(OVERLAY_ALPHA_MAX * slot[2]);   /* the text's alpha */
        void* textPane = layout->getPane(strings + 0x1FC);      /* "overheat_text" */
        void* endPane = layout->getPane(strings + 0x20C);       /* "overheat_text_end" */
        if (textPane != NULL && endPane != NULL) {
            f32 blend = OVERLAY_ONE;
            f32 elapsed = ((sOverlayTime - slot[1]) - blend) / OVERLAY_FADE_TIME;
            blend = (blend < elapsed) ? blend : elapsed;
            blend = (blend > OVERLAY_ZERO) ? blend : OVERLAY_ZERO;
            fn_80147CEC(&textData, textPane, endPane, OVERLAY_ZERO + blend * OVERLAY_ONE);
            f32 pulse1 = ((f32(*)(void))overlayPulse)();
            u32 textColor = (u32)fn_80147C50(*(u32*)((u8*)textPane + 0x18), *(u32*)((u8*)endPane + 0x18), pulse1) & 0x00FFFFFF;
            textData.w18 = __rlwimi((int)textColor, playerIndex, 24, 0, 7);
            playerIndex <<= 24;
            f32 pulse2 = ((f32(*)(void))overlayPulse)();
            u32 endColor = (u32)fn_80147C50(*(u32*)((u8*)endPane + 0x18), *(u32*)((u8*)textPane + 0x18), pulse2);
            u32 endColorRgb = __rlwinm(endColor, 0, 8, 31);
            fn_80232928((int)(endColorRgb | (u32)playerIndex));
            fn_80147230(&textData, STR_PERCENT_S, fn_80131234(strings + 0x220));   /* "RaceOverlay:OVERHEAT" */
            fn_80232930();
        }
    } else if (slot[3] > OVERLAY_WARN_MIN) {
        void* warnPane = layout->getPane(strings + 0x238);    /* "overheat_warn" */
        if (warnPane != NULL) {
            PaneData* src = (PaneData*)warnPane;
            warnData.w0 = src->w0;
            u32 a2;
            u32 a1;
            a1 = ((volatile PaneData *)src)->w4;
            a2 = ((volatile PaneData *)src)->w8;
            warnData.w4 = a1;
            warnData.w8 = a2;
            warnData.wc = src->wc;
            warnData.f10 = src->f10;
            warnData.w14 = src->w14;
            warnData.w18 = src->w18;
            warnData.w1c = src->w1c;
            f32 pulse = ((f32(*)(void))overlayPulse)();
            warnData.w18 = fn_80147C50(0xC0FFFFFFU, 0xFFFF2020U, pulse);
            ((void(*)(void*))fn_801476C4)(&warnData);
        }
    }
}
#pragma pop
extern "C" f32 fn_8001DA5C(s32);
extern f32 lbl_80560490;
#pragma scheduling off
/* Initializes eight 3-float overlay slots (indices 1-24) to (sentinel, zero, zero). */
extern "C" void fn_8001E544(void* overlay) {
    f32 zeroValue;
    f32 sentinelValue;
    sentinelValue = lbl_80560490;
    zeroValue = lbl_80560474;
    ((f32*)overlay)[1] = sentinelValue;
    ((f32*)overlay)[2] = zeroValue;
    ((f32*)overlay)[3] = zeroValue;
    ((f32*)overlay)[4] = sentinelValue;
    ((f32*)overlay)[5] = zeroValue;
    ((f32*)overlay)[6] = zeroValue;
    ((f32*)overlay)[7] = sentinelValue;
    ((f32*)overlay)[8] = zeroValue;
    ((f32*)overlay)[9] = zeroValue;
    ((f32*)overlay)[10] = sentinelValue;
    ((f32*)overlay)[11] = zeroValue;
    ((f32*)overlay)[12] = zeroValue;
    ((f32*)overlay)[13] = sentinelValue;
    ((f32*)overlay)[14] = zeroValue;
    ((f32*)overlay)[15] = zeroValue;
    ((f32*)overlay)[16] = sentinelValue;
    ((f32*)overlay)[17] = zeroValue;
    ((f32*)overlay)[18] = zeroValue;
    ((f32*)overlay)[19] = sentinelValue;
    ((f32*)overlay)[20] = zeroValue;
    ((f32*)overlay)[21] = zeroValue;
    ((f32*)overlay)[22] = sentinelValue;
    ((f32*)overlay)[23] = zeroValue;
    ((f32*)overlay)[24] = zeroValue;
}
#pragma scheduling on
extern char lbl_802FDC70[];
#pragma push
#pragma scheduling invalid_target
extern "C" void* fn_8001E5B0(void* object, s32 deleteFlag) {
    /* Destroys the owned object at +0x24, resets the vtable to lbl_802FDC70, and optionally frees this object. */
    class Entry {
    public:
        virtual void destroy(s32);
    };
    void* owned;

    if (object != 0) {
        owned = *(void**)((u8*)object + 0x24);
        *(void**)object = (void*)lbl_802FDC70;
        if (owned != 0) {
            if (owned != 0)
                ((Entry*)owned)->destroy(1);
        }
        if (deleteFlag > 0)
            ((s32 (*)(void*))fn_80128668)(object);
    }
    return object;
}

extern "C" s32 __AXGetStackHead(s32, s32);
extern f32 lbl_80560494;
extern f32 lbl_80560498;
extern f32 lbl_8056049C;
extern f32 lbl_805604A0;
extern f32 lbl_805604A4;
extern u32 lbl_80558D0C;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void fn_8001E634(void *arg0, s32 arg1, s32 arg2) {
    s32 pick;
    void **var_r27;
    void *temp_r3;
    void *temp_r3_2;
    s32 var_r28;
    s32 temp_r31;
    s32 var_r0;
    float var_f2;
    float temp_f31;
    float temp_f0;
    float temp_f1;
    s32 sp44; s32 sp40; s32 sp3C; float sp38; s32 sp34; s32 sp30; s32 sp2C; s32 sp28; s32 sp24; s32 sp20; s32 sp1C; float sp18; s32 sp14; s32 sp10; s32 spC; s32 sp8;
    temp_r31 = fn_801609C4(arg2);
    if (fn_801E85A4() == 2) { var_r27 = lbl_8055D5F8; } else { var_r27 = lbl_8055D5F4; }
    if (var_r27 != 0) {
        fn_8014784C(var_r27, lbl_802FDB68 + 0x248, lbl_802FDB68 + 0x258, 0);
        if (temp_r31 <= 4 && temp_r31 >= 0) {
            pick = *(s32 *)((unsigned char *)arg0 + arg1 * 4 + 4);
            if (temp_r31 != pick) { *(float *)((unsigned char *)arg0 + 0x2C) = fn_8001DAE8(); }
            else { *(float *)((unsigned char *)arg0 + 0x34) = fn_8001DAE8(); }
            temp_f31 = lbl_80560494 - fn_8001DAF0((unsigned char *)arg0 + 0x30);
            var_r28 = (s32)lbl_802FDB68;
            { typedef void *(*PaneFunc)(void *, const char *); PaneFunc paneFn = (PaneFunc)(*(void **)((unsigned char *)*var_r27 + 0xC)); temp_r3 = paneFn((void **)*var_r27, (const char *)(var_r28 + 0x26C)); }
            if (temp_r3 != 0) {
                sp28 = *(s32 *)temp_r3; sp2C = *(s32 *)((unsigned char *)temp_r3 + 4); sp30 = *(s32 *)((unsigned char *)temp_r3 + 8); sp34 = *(s32 *)((unsigned char *)temp_r3 + 0xC);
                sp38 = *(float *)((unsigned char *)temp_r3 + 0x10); sp3C = *(s32 *)((unsigned char *)temp_r3 + 0x14); sp40 = *(s32 *)((unsigned char *)temp_r3 + 0x18); sp44 = *(s32 *)((unsigned char *)temp_r3 + 0x1C);
                sp38 = (*(float *)((unsigned char *)temp_r3 + 0x10)) * temp_f31;
                fn_8001DAF0((unsigned char *)arg0 + 0x30);
                sp40 = fn_80147C50(sp40 & 0xFFFFFF, sp40, sp38);
                fn_801476C4(&sp28);
            }
            if (temp_r31 >= 0) {
                typedef void *(*PaneFunc)(void *, const char *); PaneFunc paneFn2 = (PaneFunc)(*(void **)((unsigned char *)*var_r27 + 0xC));
                temp_r3_2 = paneFn2((void **)*var_r27, (const char *)&lbl_80558D0C);
                if (temp_r3_2 != 0) {
                    sp8 = *(s32 *)temp_r3_2; spC = *(s32 *)((unsigned char *)temp_r3_2 + 4); sp10 = *(s32 *)((unsigned char *)temp_r3_2 + 8); sp14 = *(s32 *)((unsigned char *)temp_r3_2 + 0xC);
                    sp18 = *(float *)((unsigned char *)temp_r3_2 + 0x10); sp1C = *(s32 *)((unsigned char *)temp_r3_2 + 0x14); sp20 = *(s32 *)((unsigned char *)temp_r3_2 + 0x18); sp24 = *(s32 *)((unsigned char *)temp_r3_2 + 0x1C);
                    var_r28 = __AXGetStackHead(temp_r31, spC);
                    var_r0 = 0;
                    temp_f1 = fn_8001DAE8() - (*(float *)((unsigned char *)arg0 + 0x2C));
                    if ((temp_f1 == lbl_80560474) && (temp_f1 < *(float *)((unsigned char *)arg0 + 0x28))) { var_r0 = 1; }
                    if (var_r0 != 0) {
                        var_r28 = __AXGetStackHead(temp_r31, spC);
                        if (fn_8001DAF0((unsigned char *)arg0 + 0x28) > lbl_80560464) {
                            var_f2 = lbl_80560470; temp_f0 = (fn_8001DAF0((unsigned char *)arg0 + 0x28) - var_f2) / lbl_80560498;
                            if (var_f2 < temp_f0) { } else { var_f2 = temp_f0; }
                            if (var_f2 > lbl_80560474) { } else { var_f2 = lbl_80560474; }
                            sp18 *= lbl_80560470 + (var_f2 * lbl_8056049C);
                        } else {
                            var_f2 = lbl_80560470; temp_f0 = (fn_8001DAF0((unsigned char *)arg0 + 0x28) - lbl_80560464) / lbl_80560498;
                            if (var_f2 < temp_f0) { } else { var_f2 = temp_f0; }
                            if (var_f2 > lbl_80560474) { } else { var_f2 = lbl_80560474; }
                            sp18 *= lbl_805604A0 + (var_f2 * lbl_805604A4);
                        }
                    } else {
                        sp18 *= temp_f31;
                        fn_8001DAF0((unsigned char *)arg0 + 0x30);
                        sp20 = fn_80147C50(sp20 & 0xFFFFFF, sp20, sp18);
                    }
                    fn_80147230(&sp8, (const char *)var_r28);
                }
            }
        }
    }
    *(s32 *)((unsigned char *)arg0 + arg1 * 4 + 4) = temp_r31;
}
#pragma pop
extern "C" void fn_8001E964(void* object) {
    #define INVALID_VALUE lbl_80560490 /* -999.0f */
    /* Reset the two float fields at +0x2C and +0x34 to the invalid sentinel. */
    f32 value = INVALID_VALUE;
    *(f32*)((u8*)object + 0x34) = value;
    *(f32*)((u8*)object + 0x2C) = value;
    #undef INVALID_VALUE
}

extern "C" s32 fn_8001E974(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" void* fn_801EA9A0(s32);
extern "C" f32 fn_801E7E18(void);
extern "C" void* fn_801E7E3C(void);
extern "C" void fn_801345D8(char*, s32, const char*, ...);
extern "C" s32 fn_80147ABC(s32, s32, const char*, f64, ...);
extern "C" u32 lbl_802ED840[];
extern "C" char lbl_80558D14[];
extern "C" char lbl_80558D1C[];
extern "C" char lbl_80558D24[];
__declspec(section ".sdata") extern char lbl_80558D14[];
__declspec(section ".sdata") extern char lbl_80558D1C[];
__declspec(section ".sdata") extern char lbl_80558D24[];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_8001E9B4(s32 arg0, s32 arg1) {
    register char* base = lbl_802FDB68;
    register s32* record;
    register void* object = fn_801EA9A0(arg1);
    f32 now = fn_801E7E18();
    s32 offset = arg1 << 3;
    record = (s32*)((u8*)arg0 + offset);
    struct Locals {
        s32 idsA[4];
        s32 idsB[4];
        u32 thresholds[4];
        char temp[30];
        u16 pad;
        char nameB[32];
        char nameA[32];
        char text[32];
    } work;
    volatile u32* src = (volatile u32*)lbl_802ED840;
    void* widget;
    f32 delta;
    if (*(s32*)((u8*)object + 0x1C) > record[1]) {
        *(f32*)((u8*)record + 8) = now;
        record[1] = *(s32*)((u8*)object + 0x1C);
    }
    delta = now - *(volatile f32*)((u8*)arg0 + offset + 8);
    work.thresholds[0] = *src++;
    work.thresholds[1] = *src++;
    work.thresholds[2] = *src++;
    work.thresholds[3] = *src++;
    widget = *((void* volatile*)&lbl_8055D604);
    if (widget != 0 && delta < *(f32*)&work.thresholds[3]) {
        s32 row = 0;
        do {
            s32* out = work.idsA;
            if (row == 0) out = work.idsB;
            s32 col = 0;
            do {
                const char* suffix = lbl_80558D24;
                if (row == 0) suffix = lbl_80558D1C;
                fn_801345D8(work.text, 0x20, lbl_80558D14, suffix, col);
                *out = ((s32 (**)(void*, char*))(*(void***)widget))[3](widget, work.text);
                col++;
                out++;
            } while (col < 4);
            row++;
        } while (row < 2);
        void* menu = fn_801E7E3C();
        s32 current = record[1];
        if (current != 1 && current <= 3) {
            s32 count = *(s32*)((u8*)menu + 8);
            if (current < count) {
                const char* text = fn_80131234(base + 0x278);
                char* dst = work.nameA;
                s32 left = 0x20;
                goto copy_a;
            count_a:
                left--;
                if (left > 0) goto copy_a;
                *(dst - 1) = 0;
                goto end_a;
            copy_a:
                { char c = *text++; *dst++ = c;
                  if ((s8)c != 0) goto count_a; }
            end_a: ;
                fn_801345D8(work.temp, 0x1E, base + 0x28C, record[1]);
                text = fn_80131234(work.temp);
                dst = work.nameB;
                left = 0x20;
                goto copy_b;
            count_b:
                left--;
                if (left > 0) goto copy_b;
                *(dst - 1) = 0;
                goto end_b;
            copy_b:
                { char c = *text++; *dst++ = c;
                  if ((s8)c != 0) goto count_b; }
            end_b: ;
            } else {
                if (current == count) {
                const char* text = fn_80131234(base + 0x2A4);
                char* dst = work.nameA;
                s32 left = 0x20;
                goto copy_c;
            count_c:
                left--;
                if (left > 0) goto copy_c;
                *(dst - 1) = 0;
                goto end_c;
            copy_c:
                { char c = *text++; *dst++ = c;
                  if ((s8)c != 0) goto count_c; }
            end_c: ;
                text = fn_80131234(base + 0x2B8);
                dst = work.nameB;
                left = 0x20;
                goto copy_d;
            count_d:
                left--;
                if (left > 0) goto copy_d;
                *(dst - 1) = 0;
                goto end_d;
            copy_d:
                { char c = *text++; *dst++ = c;
                  if ((s8)c != 0) goto count_d; }
            end_d: ;
                } else if ((count + 1) != current) {
                    return;
                }
            }
            s32 index = 0;
            if (delta < *(f32*)&work.thresholds[1]) {
                index = 0;
            } else if (delta < *(f32*)&work.thresholds[2]) {
                index = 1;
            } else if (delta < *(f32*)&work.thresholds[3]) {
                index = 2;
            }
            s32 nextIndex = index + 1;
            f32 low = *(f32*)&work.thresholds[index];
            f32 high = *(f32*)&work.thresholds[nextIndex];
            f32 numerator = delta - low;
            f32 denominator = high - low;
            f32 lower = lbl_80560470;
            f32 t = numerator / denominator;
            if (lower < t) lower = t;
            if (lower > lbl_80560474) lower = lbl_80560474;
            f32 value = lbl_80560474 + lower * lbl_80560470;
            fn_80232928(-1);
            fn_80147ABC(work.idsB[index], work.idsB[nextIndex], lbl_80558D08, value, work.nameA);
            fn_80147ABC(work.idsA[index], work.idsA[nextIndex], lbl_80558D08, value, work.nameB);
            fn_80232930();
        }
    }
}
#pragma pop
extern "C" void fn_8001ED2C(void* arg0) {
#define INVALID_VALUE lbl_80560490 /* -999.0f */
    /* Initialize eight (int, float) pairs at offsets 0x04..0x40 to (0, -999.0f). */
    f32 value = INVALID_VALUE;
    *(s32*)((u8*)arg0 + 0x04) = 0;
    *(f32*)((u8*)arg0 + 0x08) = value;
    *(s32*)((u8*)arg0 + 0x0C) = 0;
    *(f32*)((u8*)arg0 + 0x10) = value;
    *(s32*)((u8*)arg0 + 0x14) = 0;
    *(f32*)((u8*)arg0 + 0x18) = value;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(f32*)((u8*)arg0 + 0x20) = value;
    *(s32*)((u8*)arg0 + 0x24) = 0;
    *(f32*)((u8*)arg0 + 0x28) = value;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *(f32*)((u8*)arg0 + 0x30) = value;
    *(s32*)((u8*)arg0 + 0x34) = 0;
    *(f32*)((u8*)arg0 + 0x38) = value;
    *(s32*)((u8*)arg0 + 0x3C) = 0;
    *(f32*)((u8*)arg0 + 0x40) = value;
#undef INVALID_VALUE
}

/* CodeWarrior deleting-destructor helper: free the object with MemFree when
 * deleting (flag > 0), then return the object pointer. */
extern "C" s32 fn_8001ED78(s32 object, s32 deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern "C" s32 fn_801E85A4(void);
extern "C" char lbl_802FDE38[];
extern "C" char lbl_802FDE48[];
extern "C" char lbl_802FDE54[];
extern "C" void** lbl_8055D5FC;
extern "C" void** lbl_8055D600;
// The array label, typed virtual call, and fixed-arity cleanup call preserve the target instructions.
extern "C" void fn_8001EDB8(void) {
    /* Notify the active continue-prompt UI object with the "continue_prompt" data. */
    struct Obj { virtual void v0(); virtual void v1(void *); };
    void *data = lbl_802FDE38;
    void *target;
    if (fn_801E85A4() == 2) {
        target = lbl_8055D600;
    } else {
        target = lbl_8055D5FC;
    }
    ((Obj *)target)->v1(data);
    ((void (*)(void))fn_801476C4)();
}

extern "C" s32 fn_8001EE14(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Show "timed_out" and "disqualified" result panes on the active UI object, refreshing after each. */
extern "C" void fn_8001EE54(void) {
    class Pane {
    public:
        virtual void v0();
        virtual void set(void*);
    };
    void* paneText = lbl_802FDE48;
    void* targetPane;

    if (fn_801E85A4() == 2)
        targetPane = lbl_8055D600;
    else
        targetPane = lbl_8055D5FC;
    ((Pane*)targetPane)->set(paneText);
    ((void (*)(void))fn_801476C4)();

    paneText = lbl_802FDE54;
    if (fn_801E85A4() == 2)
        targetPane = lbl_8055D600;
    else
        targetPane = lbl_8055D5FC;
    ((Pane*)targetPane)->set(paneText);
    ((void (*)(void))fn_801476C4)();
}

