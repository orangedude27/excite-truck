#include <types.h>
extern void fn_8000FF88(s32, s32, void *, f32, f32, f32, ...);
extern void *fn_801E87A8(void);
extern s32 fn_801B87A0(s32, s32);
extern s32 fn_801769A8(void);
extern s32 fn_80005580(s32);
extern s32 fn_80005678(void);
extern s32 fn_80005694(void);

extern u8 lbl_802FB5F0[];
extern u8 lbl_802FB5D8[];
extern s32 fn_801B880C(void);
extern s32 fn_80006580();
extern s32 fn_801CB880(void);
extern void fn_800121A4(void);
extern void fn_80012158(void);
extern void fn_8027AA48(void);
extern void fn_80230E90(s32);
extern void fn_801B84C0(void *);
extern s32 fn_801769B8(void);
extern s32 fn_8000C630(s32, s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80128668(void);
extern s32 fn_80005564(void); /* nonzero while the arena overlay is active */
extern void *fn_801B83A0(void); /* the global arena-event master object */
extern void *lbl_8055D350; /* session state: [7] player index, +0x10 time window, +0x30 HUD object */
extern f32 lbl_8056011C; /* zero, pooled as a read-only float constant */
extern s32 fn_801E866C(void);
extern void *fn_801EA9A0(void);
extern s32 fn_801B84D8(s32, s32);
extern s32 fn_801B8570(s32);
extern u8 lbl_8034EEB8_arr[]; /* arena overlay object table, indexed by player */
extern u8 lbl_802FB69C[]; /* "Your car is impaired." */
extern s32 fn_80011A5C(s32);
extern s32 fn_801B84A4(s32);
extern s32 fn_80230DA0(void);
extern void fn_80235380(s32);
extern u8 lbl_802FB478[];
extern u8 lbl_8034EE84[0x100];
extern u8 lbl_8055F024;

extern s32 lbl_8034EEB8[0x100];
extern void fn_800070DC(void);
extern s32 KERNEL_GetTimeMs(void);
extern s32 lbl_8055D348;
extern f32 lbl_8055D34C;
extern void fn_80005C20(void);
extern void fn_80230B5C(void *);
extern void DrawList_loadMatrix(void *);
extern void setCameraProjection(f32, f32, f32);
extern f32 lbl_80560130;
extern f32 lbl_80560124;
extern f32 lbl_8056019C;
extern void fn_801E7E18(void *, void *);
extern void fn_80011A2C(void);
extern void fn_802C9904(void);
extern void fn_800066B4(void *);
extern s32 fn_80009C84(void);
extern u8 lbl_8055D340[4];
extern s32 fn_801CB844(void);
extern s32 fn_801B8874(void);
extern void drawAwardsList(void *);
extern s32 fn_80010074(s32, s32, void *, void *, f32, f32, f32);
extern int sprintf(char *, const char *, ...);
extern u8 lbl_802FB2A0[];
extern s32 lbl_80558928;
extern s32 lbl_80558948;
extern f32 lbl_80560134;
extern f32 lbl_80560190;
extern u8 lbl_802FB0C8[];
extern s32 lbl_8055D354;
extern s32 fn_80007554(s32, s32, s32);

/* --- HUD overlay manager -------------------------------------------------
 * lbl_8034EEB8 is the game's one static HUD overlay manager.  fn_80005C88
 * fills it with the overlay objects it builds by name (the names are the
 * strings in the table at lbl_802FB0C8: "IntroOverlay", "RacingOverlay",
 * ...), fn_800057D0 picks each frame which overlay every player's HUD shows
 * and drawAllPlayerHuds updates the ones it picked.  Every overlay answers slot
 * 0x38 of its vtable with a "this overlay is finished" byte, which is what
 * fn_800057D0 asks the scene overlays before letting go of them.
 * lbl_8055D350 points at the per-session state block at lbl_8034EE84.
 * The overlays' own vtables (lbl_802FB2DC .. lbl_802FB520, one per class) answer
 * slot 0x14 with "take the screen", 0x18 with "give it back", 0x1C with the init
 * fn_80005C88 runs right after storing the vtable (and fn_800070DC runs again to
 * reset them), 0x20/0x24/0x2C with their per-frame update calls (0x2C also gets
 * the player index), 0x28 with a state byte and 0x38 with a "finished" byte. */
typedef struct OverlayEntry { /* manager + 0x10, one per player */
    void *active;     /* 0x00: the overlay this player's HUD shows now */
    void *lastActive; /* 0x04: the overlay it showed last frame */
    void *racing;     /* 0x08: this player's own "RacingOverlay" */
    void *fallback;   /* 0x0C: "ArenaOverlay" in arena mode, else racing */
} OverlayEntry;

/* fn_800057D0 walks the players by advancing the manager's own address 0x10
 * bytes at a time, so the player it is looking at has its entry at +0x1C. */
typedef struct OverlayCursor {
    u8 pad[0x1C];
    void *fallback; /* 0x1C: the player being looked at's own overlay */
} OverlayCursor;

typedef struct OverlayManager {
    void *interlude; /* 0x00: "InterludeOverlay" */
    void *preRace;   /* 0x04: "PreRaceOverlay", only while the race is ahead */
    void *postRace;  /* 0x08: "PostRaceOverlay" */
    void *intro;     /* 0x0C: "IntroOverlay", "ArenaIntroOverlay" in arenas */
    OverlayEntry entries[4]; /* 0x10: one slot per player */
    void *arena;     /* 0x50: "ArenaOverlay", shared by all players */
    void *replay;    /* 0x54: "ReplayOverlay" */
    void *closure;   /* 0x58: "ClosureOverlay", the race's end sequence */
    void *results;   /* 0x5C: lbl_8055D344, else a "ResultsOverlay" */
    s32 field60;     /* 0x60 */
} OverlayManager;

typedef struct SessionState { /* lbl_8034EE84, what lbl_8055D350 points at */
    u8 pad0[0x08];
    void *field08;   /* 0x08: the object fn_801E87A8 hands out at startup; the
                      * word at its +4 holds flags the HUD code tests (0x80000) */
    u8 pad0C[0x08];
    s32 playerCount; /* 0x14: how many of the four slots are in use */
    u8 pad18[0x04];
    s32 currentPlayer; /* 0x1C: the player fn_80005740 bound the session to; the HUD
                        * display lists are drawn for this one */
} SessionState;

#define OVERLAY_MGR ((OverlayManager *)lbl_8034EEB8)
#define SESSION     ((SessionState *)lbl_8055D350)
#define gSessionState lbl_8034EE84
#define Player_getCarSlot fn_801E866C
#define Car_getEntry fn_801EA9A0
#define Hud_queryPlayerFlags fn_801B84D8
#define OverlayMgr_hasArenaOverlay fn_80005564
#define Hud_checkArenaCar fn_801B8570

enum {
    SESSION_CUR_PLAYER_WORD   = 0x1C / 4,
    SESSION_PLAYER_FLAGS_WORD = 0x20 / 4,
    SESSION_CAR_SLOT_WORD     = 0x24 / 4,
    SESSION_CAR_ENTRY_WORD    = 0x28 / 4,
    SESSION_CAR_ID_WORD       = 0x2C / 4,
    SESSION_CAR_DATA_WORD     = 0x30 / 4,
    CAR_ENTRY_DATA_OFFSET     = 0x0C
};

#pragma scheduling invalid_target
#pragma push
#pragma dont_inline on
/* Set the active HUD overlay pointer for one player slot in the session table. */
void fn_800056C8(s32 playerIndex, s32 overlay) {
    lbl_8034EEB8[playerIndex * 4 + 4] = overlay;
}
#pragma pop
#pragma scheduling on

#pragma push
#pragma dont_inline on
/* Set the active HUD overlay to `overlay` for every player slot in use. */
void fn_800056E0(s32 overlay) {
    s32 playerCount = SESSION->playerCount;
    s32 playerIndex = 0;
    for (; playerIndex < playerCount; playerIndex++) {
        fn_800056C8(playerIndex, overlay);
    }
}
#pragma pop
/* Session_selectPlayer: bind the active player index, car slot, car entry pointers, and HUD flags in gSessionState, and update the arena car state when the arena overlay is active. */
void fn_80005740(s32 playerIdx) {
    u32 *sessionWords;
    void *carEntry;
    s32 carId;

    sessionWords = (u32 *)gSessionState;
    sessionWords[SESSION_CUR_PLAYER_WORD] = playerIdx;
    sessionWords[SESSION_CAR_SLOT_WORD] = (u32)Player_getCarSlot();
    carEntry = Car_getEntry();
    sessionWords[SESSION_CAR_ENTRY_WORD] = (u32)carEntry;
    carId = ((s32 *)carEntry)[2];
    sessionWords[SESSION_CAR_ID_WORD] = carId;
    sessionWords[SESSION_CAR_DATA_WORD] = (u32)((u8 *)carEntry + CAR_ENTRY_DATA_OFFSET);
    sessionWords[SESSION_PLAYER_FLAGS_WORD] = (u32)Hud_queryPlayerFlags(playerIdx, carId);
    if (OverlayMgr_hasArenaOverlay() != 0) {
        Hud_checkArenaCar((s32)sessionWords[SESSION_CAR_SLOT_WORD]);
    }
}
#pragma push
#pragma dont_inline on
/* Calls fn_80230DA0() only while the flag byte lbl_8055F024 is nonzero. */
void fn_800057BC(void) {
    if (lbl_8055F024 == 0) {
        return;
    }
    fn_80230DA0();
}
#pragma pop

#pragma cplusplus on
#pragma push
#pragma scheduling invalid_target
/* Chooses the HUD overlay every player sees this frame: one of the scene's own
 * overlays for all of them while that overlay is not finished yet (vtable slot
 * 0x38 answers its "I'm done" byte), otherwise each player's own overlay -
 * or the race's ClosureOverlay for the players already out of it.  drawAllPlayerHuds
 * then updates the overlays picked here. */
extern "C" void fn_800057D0(void) {
    struct Overlay {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        virtual s32 v8() = 0;
        virtual s32 v9() = 0;
        virtual s32 v10() = 0;
        virtual s32 v11() = 0;
        virtual s32 isDone() = 0; /* the overlays' finished byte */
    };
    OverlayManager *mgr;
    OverlayCursor *cursor;
    s32 playerCount, player;
    if (fn_801769A8() & 0x4000) { /* physics asks for an interlude */
        fn_800056E0((s32)OVERLAY_MGR->interlude);
        return;
    }
    if (OVERLAY_MGR->preRace != 0 &&
        ((Overlay *)OVERLAY_MGR->preRace)->isDone() == 0) {
        fn_800056E0((s32)OVERLAY_MGR->preRace);
        return;
    }
    if (fn_80005694() != 0) { /* the race has not gone green yet */
        fn_800056E0((s32)OVERLAY_MGR->intro);
        return;
    }
    if (fn_80005678() != 0) { /* ClosureOverlay->isDone() */
        if (OVERLAY_MGR->postRace != 0 &&
            ((Overlay *)OVERLAY_MGR->postRace)->isDone() == 0) {
            fn_800056E0((s32)OVERLAY_MGR->postRace);
            return;
        }
        fn_800056E0((s32)OVERLAY_MGR->results);
        return;
    }
    playerCount = SESSION->playerCount;
    cursor = (OverlayCursor *)OVERLAY_MGR;
    mgr = (OverlayManager *)cursor;
    for (player = 0; player < playerCount;
         cursor = (OverlayCursor *)((u8 *)cursor + sizeof(OverlayEntry)), player++) {
        if (fn_80005580(player) != 0) { /* this player is out of the race */
            fn_800056C8(player, (s32)mgr->closure);
        } else {
            fn_800056C8(player, (s32)cursor->fallback);
        }
    }
}
#pragma cplusplus off

#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma cplusplus on
/* Draws one frame of every player's HUD.
 *
 * First pass, per player: bind the session to that player (fn_80005740), and if the
 * overlay fn_800057D0 picked for it this frame is not the one its HUD showed last frame,
 * have the old one give the screen back (slot 0x18) and the new one take it (slot 0x14).
 * The overlay is then run inside its own rectangle -- the whole screen while it owns the
 * screen (its state byte, slot 0x28), the player's own split-screen viewport otherwise --
 * clearing the three HUD display lists, running the overlay's update (slot 0x20, plus
 * slot 0x24 unless the race is finishing, and for a full-screen overlay only for the
 * first player), drawing the lists and putting the viewport back.
 *
 * Second pass, per player: the same on the full screen, but with the update that is
 * given the player index (slot 0x2C). */
extern "C" s32 drawAllPlayerHuds(void) {
    extern s32 fn_801E85A4(void);                            /* viewports on screen */
    extern void fn_801E88B4(s32 *, s32 *, s32 *, s32 *, s32); /* one player's viewport rect */
    extern s32 fn_801E89EC(void);          /* race phase: 0 before start, 1 racing, 3 finishing */
    extern s32 DrawList_saveViewport(void *, s32, s32, s32, s32);  /* save the viewport, set a new one */
    extern s32 DrawList_restoreViewport(void *, s32);                 /* put a saved viewport back */
    extern s32 Sound_isActive(void);          /* audio-active flag; result unused here */
    extern s32 fn_80010EC8(void);          /* clear the three HUD display lists */
    extern s32 fn_8001123C(s32);           /* draw them for one player */
    extern s32 lbl_8055CFF0, lbl_8055CFF4; /* screen width (640) and height (480) */
    struct Overlay {
        virtual void v0() = 0;                 /* 0x08 */
        virtual void v1() = 0;                 /* 0x0C */
        virtual void v2() = 0;                 /* 0x10 */
        virtual void takeScreen() = 0;         /* 0x14: this overlay now owns the screen */
        virtual void releaseScreen() = 0;      /* 0x18: give the screen back again */
        virtual void v5() = 0;                 /* 0x1C: init */
        virtual void update() = 0;             /* 0x20: per-frame update */
        virtual void updateOnce() = 0;         /* 0x24: per-frame update, once per screen */
        virtual s32 ownsScreen() = 0;          /* 0x28: state byte, set while it is full-screen */
        virtual void updateForPlayer(s32) = 0; /* 0x2C: per-frame update of one player */
    };
    s32 savedViewportRect[4], savedFullScreenRect[4], viewportRect[4], playerCount = fn_801E85A4();
    /* The overlay manager; its per-player entry starts at overlayEntry[4], so overlayEntry[4]
       is the overlay that player's HUD shows and overlayEntry[5] the one it showed last frame. */
    s32 *overlayEntry = lbl_8034EEB8;
    for (s32 playerIndex = 0; playerIndex < playerCount; overlayEntry += 4, playerIndex++) {
        Overlay *overlay, *lastOverlay;

        fn_80005740(playerIndex);
        overlay = *(Overlay **)(overlayEntry + 4);
        lastOverlay = *(Overlay **)(overlayEntry + 5);
        if (lastOverlay != overlay) {
            if (lastOverlay) lastOverlay->releaseScreen();
            overlay->takeScreen();
            *(Overlay **)(overlayEntry + 5) = overlay;
        }
        fn_80010EC8();
        if (overlay->ownsScreen()) {
            viewportRect[3] = 0; viewportRect[2] = 0; viewportRect[1] = lbl_8055CFF0; viewportRect[0] = lbl_8055CFF4;
        } else {
            fn_801E88B4(&viewportRect[3], &viewportRect[2], &viewportRect[1], &viewportRect[0], playerIndex);
        }
        DrawList_saveViewport(savedViewportRect, viewportRect[3], viewportRect[2], viewportRect[1], viewportRect[0]);
        overlay->update();
        if (fn_801E89EC() != 3) {
            Sound_isActive();
            if (overlay->ownsScreen() == 0 || playerIndex == 0)
                overlay->updateOnce();
        }
        fn_8001123C(SESSION->currentPlayer);
        fn_80011A2C();
        DrawList_restoreViewport(savedViewportRect, -1);
    }
    overlayEntry = lbl_8034EEB8;
    for (s32 playerIndex = 0; playerIndex < playerCount; overlayEntry += 4, playerIndex++) {
        Overlay *overlay;

        fn_80005740(playerIndex);
        overlay = *(Overlay **)(overlayEntry + 4);
        fn_80010EC8();
        DrawList_saveViewport(savedFullScreenRect, 0, 0, lbl_8055CFF0, lbl_8055CFF4);
        overlay->update();
        if (fn_801E89EC() != 3) {
            Sound_isActive();
            overlay->updateForPlayer(playerIndex);
        }
        fn_8001123C(SESSION->currentPlayer);
        fn_80011A2C();
        DrawList_restoreViewport(savedFullScreenRect, -1);
    }
}
#pragma cplusplus off
#pragma dont_inline reset
#pragma pop
/* Empty no-op stub: one of a run of default callback slots that do nothing in this build. */ void fn_80005B54(void) {
    /* Empty no-op stub: one of a run of default callback slots that do nothing. */
    return;
}

void fn_80005B58(void) {
    /* Empty no-op stub: one of a run of default callback slots that do nothing. */
    return;
}

void fn_80005B64(void) {
    /* Empty no-op stub: one of a run of default callback slots that do nothing. */
    return;
}

void fn_80005B68(void) {
    /* Empty no-op stub: one of a run of default callback slots that do nothing. */
    return;
}

#pragma push
#pragma dont_inline on
void fn_80005B6C(void) {
    /* Empty no-op hook run near the end of the frame update dispatch
     * (fn_80007238); one of a run of default callback slots that do nothing. */
    return;
}
#pragma pop

void fn_80005B70(void) {
    /* Empty no-op stub: one of a run of default callback slots that do nothing. */
}

#pragma cplusplus on
#pragma push
#pragma dont_inline on
/* Draw a PA-timing hint when the locale flag is set: read the 'pa_sample_request_t' deadline from the audio object and show 'Please trigger PA' or '%.1f seconds til grab' against the session clock. */ extern "C" void fn_80005B74(void) {
    class LfoValue {
    public:
        virtual void method0() = 0;
        virtual void method1() = 0;
        virtual void method2() = 0;
        virtual void method3() = 0;
        virtual void method4() = 0;
        virtual void method5() = 0;
        virtual void method6() = 0;
        virtual f32 getValue(const char *) = 0;
    };
    extern s32 fn_80019B54(void);
    extern s32 *__AXFXGetLfoSinTable_801769CC(void);
    extern void *fn_8001285C(s32);
    extern void drawUiLabel(const char *, s32);
    extern f32 lbl_80560120;
    char message[0x20];
    f32 targetTime, currentTime;
    void *object;
    u8 *base = lbl_802FB0C8;
    if (fn_80019B54() != 0) {
        object = *(void **)((u8 *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
        targetTime = ((LfoValue *)object)->getValue((char *)base + 0x24);
        currentTime = *(f32 *)((u8 *)lbl_8055D350 + 0x10);
        if (currentTime > targetTime) {
            if (currentTime - targetTime < lbl_80560120)
                drawUiLabel((char *)base + 0x38, 0);
        } else {
            sprintf(message, (char *)base + 0x4C, targetTime - currentTime);
            drawUiLabel(message, 0);
        }
    }
}
/* Hud_UpdateFrameDelta: sample the frame timer, compute delta seconds since the
 * last HUD tick (clamped to >= 0), store it in lbl_8055D34C, and save the
 * current tick in lbl_8055D348. lbl_80560124 is 1000.0f (ticks-per-second). */
void fn_80005C20(void) {
    f32 deltaSeconds;
    f32 clampedDeltaSeconds;
    s32 currentTickMs;

    currentTickMs = KERNEL_GetTimeMs();
    clampedDeltaSeconds = lbl_8056011C;
    deltaSeconds = (f32)(currentTickMs - lbl_8055D348) / lbl_80560124;
    clampedDeltaSeconds = (clampedDeltaSeconds > deltaSeconds) ? clampedDeltaSeconds : deltaSeconds;
    lbl_8055D34C = clampedDeltaSeconds;
    lbl_8055D348 = currentTickMs;
}

#pragma pop
#pragma cplusplus off
extern void *fn_801284F8(s32, const char *);
extern void *fn_80014524(void *, s32);
extern void fn_80176780(s32, s32);
extern s32 fn_801B8914(void);
extern s32 fn_801B8900(void);
extern void *fn_80145E70(void *);
extern void *ArtSetGet(void *);
extern void *lbl_8055D344;
extern void *lbl_802FB4E8[];
extern void *lbl_802FB4B0[];
extern void *lbl_802FB358[];
extern void *lbl_802FB318[];
extern void *lbl_802FB408[];
extern void *lbl_802FB440[];
extern void *lbl_802FB520[];
extern void *lbl_802FB2DC[];
extern u8 lbl_802FB640[], lbl_802FB650[], lbl_802FB65C[];
#pragma cplusplus on
#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_80005C88(void) {
    struct Dummy {
        virtual void v0() = 0; virtual void v1() = 0;
        virtual void v2() = 0; virtual void v3() = 0;
        virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0;
    };
    u32 *manager = (u32 *)lbl_8055D350;
    u8 *strings = lbl_802FB0C8;
    u32 *config = (u32 *)manager[2];
    s32 flag = (config[1] >> 9) & 1;
    u8 *state;
    s32 zero = 0;
    void *object;
    u8 *entry;
    s32 count;
    s32 i;
    if (flag != 0) {
        object = fn_801284F8(4, (const char *)(strings + 0xB0));
        if (object != 0) {
            *(void **)object = lbl_802FB4E8;
            ((Dummy *)object)->v5();
        }
        *(void **)((u8 *)lbl_8034EEB8 + 0xC) = object;
    } else {
        object = fn_801284F8(4, (const char *)(strings + 0xC4));
        if (object != 0) *(void **)object = lbl_802FB4B0;
        *(void **)((u8 *)lbl_8034EEB8 + 0xC) = object;
    }
    object = fn_801284F8(4, (const char *)(strings + 0xD4));
    if (object != 0) *(void **)object = lbl_802FB358;
    *(void **)lbl_8034EEB8 = object;
    if (fn_801B8914() != 0) {
        object = fn_801284F8(8, (const char *)(strings + 0xE8));
        if (object != 0) {
            *(void **)object = lbl_802FB318;
            ((u8 *)object)[4] = 0;
            ((u8 *)object)[5] = 0;
            fn_80176780(0x1000, 0);
        }
        *(void **)((u8 *)lbl_8034EEB8 + 4) = object;
    } else {
        *(void **)((u8 *)lbl_8034EEB8 + 4) = 0;
    }
    if (flag != 0) {
        object = fn_801284F8(4, (const char *)(strings + 0xF8));
        if (object != 0) *(void **)object = lbl_802FB408;
    } else {
        object = 0;
    }
    *(void **)((u8 *)lbl_8034EEB8 + 0x50) = object;
    object = fn_801284F8(4, (const char *)(strings + 0x108));
    if (object != 0) *(void **)object = lbl_802FB440;
    state = (u8 *)lbl_8034EEB8;
    *(void **)(state + 0x54) = object;
    manager = (u32 *)lbl_8055D350;
    count = manager[5];
    entry = state;
    for (i = zero; (u32)i < 4U; i++, entry += 0x10) {
        *(s32 *)(entry + 0x10) = zero;
        *(s32 *)(entry + 0x14) = zero;
        if (i < count) {
            object = fn_801284F8(0x54, (const char *)(strings + 0x118));
            if (object != 0) object = fn_80014524(object, i);
            *(void **)(entry + 0x18) = object;
        } else {
            *(void **)(entry + 0x18) = (void *)zero;
        }
        if (flag != 0) object = *(void **)(state + 0x50);
        else object = *(void **)(entry + 0x18);
        *(void **)(entry + 0x1C) = object;
    }
    object = fn_801284F8(0x1C, (const char *)(strings + 0x128));
    if (object != 0) {
        *(void **)object = lbl_802FB520;
        ((Dummy *)object)->v5();
    }
    *(void **)((u8 *)lbl_8034EEB8 + 0x58) = object;
    if (fn_801B8900() != 0) {
        object = fn_801284F8(8, (const char *)(strings + 0x138));
        if (object != 0) {
            *(void **)object = lbl_802FB2DC;
            ((u8 *)object)[4] = 0;
        }
        *(void **)((u8 *)lbl_8034EEB8 + 8) = object;
    } else {
        *(void **)((u8 *)lbl_8034EEB8 + 8) = 0;
    }
    object = lbl_8055D344;
    if (object != 0) {
        ((Dummy *)object)->v1();
        *(void **)((u8 *)lbl_8034EEB8 + 0x5C) = lbl_8055D344;
    } else {
        object = fn_801284F8(0x20, (const char *)(strings + 0x148));
        if (object != 0) {
            *(void **)object = lbl_802FB478;
            *(void **)((u8 *)object + 0x14) = ArtSetGet(lbl_802FB65C);
            *(void **)((u8 *)object + 0x18) = ArtSetGet(lbl_802FB650);
            *(void **)((u8 *)object + 0x1C) = fn_80145E70(lbl_802FB640);
            ((Dummy *)object)->v5();
        }
        *(void **)((u8 *)lbl_8034EEB8 + 0x5C) = object;
    }
    *(s32 *)((u8 *)lbl_8034EEB8 + 0x60) = zero;
}
#pragma pop
#pragma scheduling on
#pragma cplusplus reset
s32 fn_80005FE0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_80006020(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_80006060(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

void fn_800060A0(void *object) {
    /* Clear the DSP-initialized flag (lbl_8055D340[1]) and reset the object's field at +0x8. */
    lbl_8055D340[1] = 0;
    ((s32 *)object)[2] = 0;
}

/* No-op default callback in the audio/HUD dispatch-table run around fn_800060A0
 * (DSP init-flag clear) and fn_800060B8 (parameter reset); this build leaves it empty. */
void fn_800060B4(void) {
    return;
}

extern f32 lbl_80560138;
void fn_800060B8(void *state) {
    // Reset a parameter block: clear the byte flag at +0x14 and default the five float fields at +4..+0x18 to -1.0 (lbl_80560138).
    float defaultValue = lbl_80560138;
    *(u8 *)((u8 *)state + 0x14) = 0;
    *(float *)((u8 *)state + 4) = defaultValue;
    *(float *)((u8 *)state + 8) = defaultValue;
    *(float *)((u8 *)state + 0xC) = defaultValue;
    *(float *)((u8 *)state + 0x10) = defaultValue;
    *(float *)((u8 *)state + 0x18) = defaultValue;
}

/* No-op companion hook to fn_800060E0 (sound-mode DSP init); reserved callback
 * slot kept for ABI compatibility, with no work to do in this build. */
void fn_800060DC(void) {
}

void fn_800060E0(u8 isMode2, u8 isMode1) {
#define gDspInitConfig lbl_8055D340
#define SignalDspInit __AXDSPInitCallback_801769E0
#define StartDsp fn_8017691C
    /* Store the chosen sound-mode flags into the DSP init config bytes, then
     * signal DSP init and start the DSP. */
    register u8 *dspConfig = gDspInitConfig;
    dspConfig[0] = isMode2;
    dspConfig[2] = isMode1;
    SignalDspInit();
    StartDsp();
#undef StartDsp
#undef SignalDspInit
#undef gDspInitConfig
}

#pragma push
#pragma processor 750
#pragma cplusplus on
/* Per-player car-impaired check: if the player's value is inside the session's
 * [0, window) range, query the arena master and stamp the player's status,
 * showing "Your car is impaired."; otherwise drive the overlay's v7 method. */
extern "C" void fn_80006110(void *playerData) {
    class VTable {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20();
        virtual s32 v21(s32);
        virtual void v22();
        virtual s32 v23();
    };
    extern void fn_8001071C(void *, s32);
    extern u8 lbl_802FB69C[];
    f32 zero;
    bool inWindow;
    s32 *gameState;
    s32 playerIndex;
    f32 playerValue;
    zero = 0.0f;
    gameState = (s32 *)lbl_8055D350;
    playerIndex = gameState[7];
    playerValue = *(f32 *)((s8 *)playerData + playerIndex * 4 + 4);
    inWindow = playerValue >= zero && (*(f32 *)(gameState + 4) - playerValue) > zero;
    if (!inWindow) {
        if (fn_80005564() == 0) {
            void **arenaObjects = (void **)lbl_8034EEB8;
            s32 playerIdx = ((s32 *)lbl_8055D350)[7];
            void *overlay = arenaObjects[playerIdx * 4 + 7];
            ((VTable *)overlay)->v7();
        }
    } else {
        if (fn_80005564() != 0) {
            VTable *master = (VTable *)fn_801B83A0();
            s32 queryResult = master->v23();
            if (queryResult != 0) {
                VTable *master2 = (VTable *)fn_801B83A0();
                queryResult = master2->v21(((s32 *)lbl_8055D350)[7]);
                s32 denied = (queryResult == 0);
                *(s8 *)((s8 *)playerData + 0x14) = denied;
                return;
            }
        }
        *(u8 *)((u8 *)playerData + 0x14) = 1;
        s32 *gameState2 = (s32 *)lbl_8055D350;
        void *hudObject = *(void **)((u8 *)gameState2 + 0x30);
        s32 playerIdx2 = gameState2[7];
        u8 *message = 0;
        if (*(u8 *)((u8 *)hudObject + 0x28) != 0)
            message = lbl_802FB69C;
        if (message != 0)
            fn_8001071C(message, playerIdx2);
    }
}
#pragma cplusplus reset
#pragma pop
/* No-op stub that always reports success (zero). */
s32 ARCClose(void) {
    return 0;
}

/* No-op stub that always reports success (zero). */
s32 fn_80006244(void) {
    return 0;
}

s32 fn_8000624C(void) {
    /* No-op stub that always reports success (zero), like fn_80006244 above. */
    return 0;
}

#pragma cplusplus on
/* When the current player's value is within the session time window and the arena overlay is active, notify the global master (v22). */
extern "C" void fn_80006254(s32 playerData, s32 eventParam) {
    bool inWindow;
    f32 zero = 0.0f;
    f32 playerValue = *(f32 *)((s8 *)playerData + ((s32 *)lbl_8055D350)[7] * 4 + 4);
    inWindow = playerValue >= zero && ((f32 *)lbl_8055D350)[4] - playerValue > zero;
    if (inWindow && fn_80005564()) {
        struct MasterVTable {
            virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
            virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
            virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
            virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
            virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
            virtual void f20(); virtual void f21(); virtual void f22(s32);
        };
        void *master = fn_801B83A0();
        ((MasterVTable *)master)->f22(eventParam);
    }
}
#pragma cplusplus reset
void fn_800062E4(void) {
    /* No-op stub in the HUD/race-timer callback cluster (beside fn_800062E8);
     * a reserved callback slot with no work to do in this build. */
    return;
}

/* fn_800062E8: when the current track/timer state is idle (fn_801B885C returns 0
 * for state[+0x1C]) and the counters at +0x18 and +0x14 are equal, trigger the
 * transition handled by fn_8000FBE4. */
void fn_800062E8(void) {
#define s_gameState lbl_8055D350
    if (fn_801B885C(((s32 *)s_gameState)[7]) == 0 &&
        ((s32 *)s_gameState)[6] == ((s32 *)s_gameState)[5]) {
        fn_8000FBE4();
    }
#undef s_gameState
}

#pragma cplusplus on
extern "C" void fn_80006330(void) {
    /* Clear session flag bits 0x80|0x07 and 0x600, then dispatch vfunc 7 on the current player's overlay. */
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
    };
    u32 *sessionState = (u32 *)lbl_8034EE84;
    s32 *session;
    sessionState[8] &= 0xFFFFFF78;
    sessionState[8] &= 0xFFFFF9FF;
    session = (s32 *)lbl_8055D350;
    ((Dummy *)((lbl_8034EEB8 + (session[7] << 2))[7]))->v7();
}
#pragma cplusplus off
extern s32 fn_80011A5C(s32);
extern s32 fn_801B84A4(s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80006378(s32 unused, s32 playerIndex) {
    struct Dummy {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void dispatch(); virtual void v11(); virtual void v12();
    };
    /* Call the slot-0x30 hook on this player's own HUD overlay, the fallback
     * pointer at +0x1C of its entry in the overlay manager's per-player table. */
    s32 *entry = (s32 *)&lbl_8034EEB8;
    entry += playerIndex * 4;
    ((Dummy *)entry[7])->dispatch();
}
#pragma scheduling on
#pragma cplusplus off
s32 fn_8000639C(void) {
    /* Constant predicate (returns 0 / false); likely a virtual getter reached through a dispatch table. */
    return 0;
}

void fn_800063A4(void) {
    /* Dispatch hook: run any pending timer-name actions queued in lbl_80437E24,
     * via fn_801C6B70 (reset the timer or invoke its two stored name callbacks). */
    fn_801C6B70();
}

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_800063A8(void) {
    s32 *sessionState = (s32 *)lbl_8055D350;
    s32 playerIndex = sessionState[7];
    s32 *overlayEntry;
    void *overlayObject;
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
    };

    fn_80011A5C(sessionState[5]);
    overlayEntry = (s32 *)&lbl_8034EEB8;
    overlayEntry += playerIndex * 4;
    overlayObject = (void *)overlayEntry[6];
    ((Dummy *)overlayObject)->v7();
    fn_801B84A4(playerIndex);
}

extern "C" s32 fn_80006408(void *unusedSelf, s32 playerIndex, u32 message, u32 param) {
    /* Check this player's HUD overlay for a consuming response, or forward UI message 0x3E8 to the global UI handler. */
    class HudOverlayVTable {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual s32 v10();
    };
    void *overlay;
    if ((((s32 *)lbl_8055D350)[8] & 4) != 0) {
        u8 *overlayBase = (u8 *)lbl_8034EEB8;
        overlayBase += (playerIndex << 4);
        overlay = *(void **)(overlayBase + 0x18);
        if (((HudOverlayVTable *)overlay)->v10() != 0) {
            return 1;
        }
    }
    if (message == 0x3E8) {
        return fn_801B87A0(playerIndex, (s32)(u16)param);
    }
    return 0;
}

#pragma cplusplus reset
void fn_800064A8(void *arg0) {
    s32 *p = (s32 *)arg0;
    if (p[2] != p[1]) {
        p[1] = p[2];
        p[3] = fn_80009C84() != 0 ? lbl_8055D348 : KERNEL_GetTimeMs();
    }
    fn_80011A2C();
    switch (p[1]) {
    case 3: fn_800066B4(arg0); return;
    case 2: fn_801CB844(); return;
    case 1: if (fn_801B8874() == 0) drawAwardsList(arg0); return;
    }
}
void fn_80006550(void *menu, s32 delta) {
    /* Move the menu's selection index (+0x10) by delta, clamping it to [0, 2]. */
    s32 selection;
    selection = *(s32 *)((u8 *)menu + 0x10) + delta;
    *(s32 *)((u8 *)menu + 0x10) = selection;
    if (selection < 0) *(s32 *)((u8 *)menu + 0x10) = 0;
    if (*(s32 *)((u8 *)menu + 0x10) >= 3) *(s32 *)((u8 *)menu + 0x10) = 2;
}

#pragma push
#pragma dont_inline on
/* Handles UI message 0x3E8 for a menu/state object: state at +4, selection at +0x10. 0x58 advances states 1->2->3 (state 2 gated by fn_801CB880), and in state 3 applies selection via fn_800060E0. 0x126/0x128 step selection down/up in state 3, clamped by fn_80006550, triggering feedback and fn_80230E90/fn_80012158. */
s32 fn_80006580(void *obj, u32 unused, u32 msg, u32 param) {
    s32 state;
    s32 event;
    s32 result = 0;
    s32 direction;
    s32 i;

    if (msg == 0x3E8) {
        state = *(s32 *)((u8 *)obj + 4);
        event = (u32)param & 0xFFFF;
        switch (state) {
        case 3:
            if (event == 0x58) {
                s32 selection = *(s32 *)((u8 *)obj + 0x10);
                ((void (*)(s32, s32))fn_800060E0)((selection - 2) == 0, (selection - 1) == 0);
                fn_800121A4();
                result = 1;
            } else if ((u32)event == 0x126 || (u32)event == 0x128) {
                direction = (u32)event == 0x126 ? -1 : 1;
                fn_80006550(obj, direction);
                for (i = 0; i < 3; i++) {
                    if (*(s32 *)((u8 *)obj + 0x10) == 2)
                        fn_8027AA48();
                }
                fn_80230E90(1);
                fn_80012158();
            }
            break;
        case 2:
            if (event == 0x58 && fn_801CB880() != 0) {
                *(s32 *)((u8 *)obj + 4) = 3;
                result = 1;
            }
            break;
        case 1:
            if (event == 0x58) {
                *(s32 *)((u8 *)obj + 4) = 2;
                result = 1;
            }
            break;
        }
    }
    return result;
}
#pragma pop

extern void fn_8027AA48(void);
extern void fn_80011E70(void);
extern void fn_80011E90(void);
extern void fn_800109E4(s32, f32, f32, f32, f32);
extern void fn_8014784C(void *, void *, s32);
extern f32 sin(f32);
extern f64 lbl_80560128;
extern f32 lbl_8056011C, lbl_80560130, lbl_8056013C;
extern f32 lbl_80560140, lbl_80560144, lbl_80560148, lbl_8056014C;
extern f32 lbl_80560150, lbl_80560154, lbl_80560158, lbl_8056015C;
extern f32 lbl_80560160, lbl_80560164, lbl_80560168, lbl_8056016C;
extern u32 lbl_802ED6A8[];
extern void fn_80230E90(s32);
extern void fn_80230F78(u8 *, f32 *, u32 *, s32);
extern void fn_80147940(void *, void *, void *, s32, ...);
extern void fn_801476C4(void *);
extern void fn_8001DFCC(void);
#pragma push
#pragma cplusplus on
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_800066B4(void *arg0) {
    class Menu {
    public:
        virtual void d0();
        virtual void *get(int);
        virtual void d2();
        virtual void *get2(int, int);
    };
    struct Table { u32 words[12]; };
    struct Item { u32 first[4]; f32 four; u32 rest[3]; };
    struct Out { u32 first[4]; f32 four, five; u32 color; };
    u8 *base = lbl_802FB0C8;
    void *obj;
    u32 table[12];
    f32 f;
    f32 t0, t1, t2;
    s32 now;
    s32 i;
    u8 alpha;
    s32 two;
    void *(*get)(void *, s32);
    void *(*get2)(void *, s32, s32);
    fn_8027AA48();
    fn_80011E70();
    fn_80011E90();
    two = 2;
    ((void (*)(u32, f32, f32, f32, f32, f64))fn_800109E4)(0x7F000000, lbl_80560140, lbl_80560144, lbl_80560148, lbl_8056014C, (f64)two);
    obj = *(void **)((u8 *)arg0 + 0x1C);
    if (obj != 0) ((void (*)(void *, void *, void *, s32))fn_8014784C)(obj, base + 0x1B4, base + 0x1C0, 0);
    f = (f32)KERNEL_GetTimeMs();
    sin(lbl_80560150 * (lbl_80560154 * f));
    if (*(void **)((u8 *)arg0 + 0x1C) == 0) return;
    if (fn_80009C84()) now = lbl_8055D348;
    else now = KERNEL_GetTimeMs();
    f = lbl_80560154 * (f32)(now - *(s32 *)((u8 *)arg0 + 0xC));
    if (f < lbl_8056015C) fn_80230E90(1);
    *(struct Table *)table = *(struct Table *)lbl_802ED6A8;
    t0 = (f - lbl_8056011C) / lbl_80560158;
    t0 = lbl_80560130 < t0 ? lbl_80560130 : t0;
    t0 = t0 > lbl_8056011C ? t0 : lbl_8056011C;
    *(f32 *)&table[1] = lbl_80560160 + t0 * lbl_80560164;
    t1 = (f - lbl_80560168) / lbl_80560158;
    t1 = lbl_80560130 < t1 ? lbl_80560130 : t1;
    t1 = t1 > lbl_8056011C ? t1 : lbl_8056011C;
    *(f32 *)&table[5] = lbl_80560160 + t1 * lbl_80560164;
    t2 = (f - lbl_8056016C) / lbl_80560158;
    t2 = lbl_80560130 < t2 ? lbl_80560130 : t2;
    t2 = t2 > lbl_8056011C ? t2 : lbl_8056011C;
    *(f32 *)&table[9] = lbl_80560160 + t2 * lbl_80560164;
    { f32 zero = lbl_8056011C, one = lbl_80560130, half = lbl_8056013C;
    for (i = 0; i < 3; i++) {
        s32 *entry = (s32 *)(table + i * 4);
        u32 item[8];
        if (entry[0] == 2) fn_8027AA48();
        obj = *(void **)((u8 *)arg0 + 0x1C);
        obj = ((Menu *)obj)->get(entry[2]);
        *(struct Item *)item = *(struct Item *)obj;
        *(f32 *)&item[1] += *(f32 *)&entry[1];
        {
            s32 selected = *(s32 *)((u8 *)arg0 + 0x10) == (s32)entry[0];
            f32 val = zero;
            alpha = 0xFF;
            if (selected) fn_80230F78(&alpha, &val, &item[6], 1);
            obj = *(void **)((u8 *)arg0 + 0x1C);
            s32 mode = selected ? 1 : 2;
            obj = ((Menu *)obj)->get2(entry[3], mode);
            {
                u32 out[7];
                f32 a = ((f32 *)obj)[1];
                f32 b = ((f32 *)obj)[5];
                *(struct Out *)out = *(struct Out *)obj;
                *(f32 *)&out[1] += *(f32 *)&entry[1];
                ((void (*)(void *, void *, void *, s32))fn_80147940)(*(void **)((u8 *)arg0 + 0x1C), out, base + 0x1CC, mode);
                if (selected) {
                    f32 h = *(f32 *)&out[4];
                    f32 w = *(f32 *)&out[5];
                    f32 q = *(f32 *)&out[1] - half * h * val;
                    f32 r = *(f32 *)&out[2] - half * w * val;
                    *(f32 *)&out[4] = h * (one + val);
                    *(f32 *)&out[5] = w * (one + val);
                    *(f32 *)&out[1] = q;
                    *(f32 *)&out[2] = r;
                    out[6] = ((u32)alpha << 24) | (out[6] & 0x00FFFF00);
                    ((void (*)(void *, void *, void *, s32))fn_80147940)(*(void **)((u8 *)arg0 + 0x1C), out, base + 0x1CC, 1);
                }
            }
        }
        fn_801476C4(item);
    }
    }
    fn_8001DFCC();
}
#pragma pop
/* Draw helpers for the awards list below. */
extern s32 fn_80010E94(s32 artSet, s32 pictureIndex, f32 x, f32 y, f32 scaleX, f32 scaleY); /* queue a picture draw */
extern f32 fn_80011E34(void); /* left edge of the whole-screen layout box */
extern f32 fn_80011E54(void); /* top edge of the whole-screen layout box */
extern void *fn_800122B4(s32 number, void *buffer); /* write number as decimal text */
extern void fn_801345D8(void *buffer, s32 size, const char *fmt, ...); /* snprintf-style formatting */
extern s32 fn_801EA994(void); /* number of real car records in the CarMgr table */
extern void *fn_801EA9B0(s32 slot); /* CarMgr slot table -> car record, rank order */
extern f32 lbl_80560118, lbl_80560170, lbl_80560178, lbl_8056017C;
extern f32 lbl_80560180, lbl_80560188;
extern const f32 lbl_80560174, lbl_80560184, lbl_8056018C;
extern const char lbl_80558930[4], lbl_80558934[6], lbl_80558940[8];

/* Awards-list layout constants (.sdata2): the row bar is 200.0 x 27.0
 * (lbl_80560118, lbl_8056017C), the list starts 24.0 below the screen top
 * (lbl_80560170), rows step 54.0 (lbl_80560174), the bar sits 21.6 above the
 * row line (lbl_80560178) and the text 27.0 above it (lbl_8056017C again),
 * list text scales by 1.5 (lbl_80560180), 100.0 turns seconds into
 * centiseconds (lbl_80560188), and the name column starts 85.0 or 135.0
 * right of the left column (lbl_80560184, lbl_8056018C). */

/* The fields of a CarMgr car record (the 0xBC-byte CarMgrEntry described in
 * src/auto/text_801EA4C4_.c) that the awards list reads. */
struct AwardCar {
    u8 pad00[0x0C];
    s32 displayFlags; /* 0x0C: bit0 show displayValue, bit1 show bestTime,
                       * neither: show the row number */
    s32 rank;         /* 0x10: rank the CarMgr slot table is sorted by */
    s32 displayValue; /* 0x14: a count, drawn with "%d" */
    f32 bestTime;     /* 0x18: best time in seconds; negative shows "--:--" */
    u8 pad1C[0x48 - 0x1C];
    char name[0x74];  /* 0x48: car name, first field of the copied definition */
};                    /* 0xBC */
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void drawAwardsList(void *screen) {
    /* Draw the awards list (fn_800064A8's state 1): one row per real car
     * record, in the order of the CarMgr slot table (rank order).  Each row
     * is a background bar plus two text columns: the left column shows the
     * record's count (flag bit 0), its best time as "s:cc" (flag bit 1,
     * "--:--" when there is none) or else the row number, and the right
     * column shows the car's name. */
    char rankText[16];
    char timeText[8];
    f32 rowX;        /* left edge of the screen box */
    f32 listTop;     /* screen top, raised by 24.0 */
    f32 nameAdvance; /* 85.0: x step after a count or a row number */
    f32 timeAdvance; /* 135.0: x step after a time */
    f32 hundred;     /* 100.0: seconds -> centiseconds */
    f32 zero;        /* 0.0 */
    f32 textLift;    /* 27.0: text above the row line */
    f32 rowGap;      /* 21.6: bar above the row line */
    f32 rowStep;     /* 54.0: distance between rows */
    f32 rowY;
    f32 textX;
    f32 bestTime;
    s32 carSlot;
    s32 flags;
    s32 seconds;
    s32 centis;
    struct AwardCar *awardCar;
    rowX = fn_80011E34();
    listTop = fn_80011E54() - lbl_80560170;
    carSlot = 0;
    rowGap = lbl_80560178;
    textLift = lbl_8056017C;
    zero = lbl_8056011C;
    hundred = lbl_80560188;
    for (; carSlot < fn_801EA994(); carSlot++) {
        awardCar = fn_801EA9B0(carSlot);
        rowY = (f32)carSlot;
        rowStep = lbl_80560174;
        nameAdvance = lbl_80560184;
        timeAdvance = lbl_8056018C;
        rowY = listTop - rowStep * rowY;
        fn_80010E94(*(s32 *)((u8 *)screen + 0x14), 0, rowX,
                    rowY - rowGap, lbl_80560118, lbl_8056017C);
        flags = awardCar->displayFlags;
        textX = rowX + rowStep;
        if (flags & 1) {
            fn_8000FF88(-0x100, 0x41, (void *)lbl_80558930,
                        lbl_80560180, textX, (rowY - rowGap) - textLift,
                        (void *)awardCar->displayValue);
            textX += nameAdvance;
        } else if (flags & 2) {
            bestTime = awardCar->bestTime;
            if (bestTime < zero) {
                fn_801345D8(timeText, 8, lbl_80558934);
            } else {
                seconds = (s32)bestTime;
                centis = (s32)(hundred * bestTime) - seconds * 100;
                fn_801345D8(timeText, 8, lbl_80558940, seconds, centis);
            }
            fn_8000FF88(-0x100, 0x41, (void *)&lbl_80558948,
                        lbl_80560180, textX, (rowY - rowGap) - textLift, timeText);
            textX += timeAdvance;
        } else {
            fn_8000FF88(-0x100, 0x41, (void *)&lbl_80558948,
                        lbl_80560180, textX, (rowY - rowGap) - textLift,
                        fn_800122B4(carSlot + 1, rankText));
            textX += nameAdvance;
        }
        fn_8000FF88(-0x100, 0x21, (void *)&lbl_80558948,
                    lbl_80560130, textX, (rowY - rowGap) - textLift,
                    awardCar->name);
    }
}
#pragma pop

#pragma scheduling invalid_target
/* If the "reset" input flag is set, draw "Press <button> to RESET" on screen. */
void fn_80006D30(void) {
    char message[0x48];
    if (((s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x2C) + 0x2C0))[0] & 0x10) {
        sprintf(message, (const char *)lbl_802FB2A0, lbl_80558928);
        ((void (*)(s32, s32, const char *, char *, f32, f32, f32, ...))fn_80010074)(-1, 0x14, (const char *)&lbl_80558948, message, lbl_80560134, lbl_8056011C, lbl_80560190);
    }
}
#pragma scheduling on

extern void Tips_LoadCameraSequence(void);
extern void fn_801A7F8C(void);
extern void fn_800054E0(void);
extern void fn_8000F0E4(void *);
extern void fn_8000F884(void);
extern void fn_80011F64(void);
extern s32 fn_80137C74(void);
extern s32 fn_802090D4(void *);
extern void LoadFloatOption(s32 kind, void *name, f32 *value); /* the saved float setting `name`, or *value as its default */
extern void fn_80005464(void);
extern void fn_8001DB54(void);
extern f32 lbl_8055892C; /* the "effects_volume" setting; startup reads it with 1.0 as the default */
#pragma push
#pragma cplusplus on
#pragma dont_inline on
/* fn_80006D9C - start the game's managers up; shutdownGameManagers is its reverse.
 *
 * It opens the subsystems shutdownGameManagers closes again at its end - Tips_LoadCameraSequence
 * (shut by fn_80020430), the HUD font read from "uifnt_o.gtx" (freed by
 * fn_8000F158), fn_8000F884 (fn_8000FB44) and fn_80011F64 (fn_800120BC) -
 * fills the session's state block with the object fn_801E87A8 hands out and the
 * number of players this session has, registers the "dashboard" sound group by
 * name (its handle is lbl_8055D354, which fn_800070DC brings back to full
 * volume), reads the saved "effects_volume" with 1.0 as its default, clears the
 * mode flags (fn_80005464) and builds the HUD overlay managers (fn_80005C88)
 * that fn_800070DC then resets to their starting state.  The current mode's
 * master object gets its slot-0xF8 hook, the same one shutdownGameManagers calls on the
 * way out.
 */
extern "C" void fn_80006D9C(void) {
    /* The game's own strings, the block the overlay names live in.  The
     * volatile is what makes the compiler materialise the base in r30 before
     * the first calls, as the original does - do not drop it. */
    volatile u8 *names = (volatile u8 *)lbl_802FB0C8;
    /* the session's state block (SessionState); declaring this pointer as a
     * SessionState * instead moves it to r30 and the strings to r31, which is
     * not what the original does. */
    u8 *session;
    /* The current mode's master object: fn_801B83A0 returns the instance
     * fn_801B81E0 created for the running mode.  Only its slot-0xF8 hook is
     * called here, so the 60 slots before it are placeholders. */
    struct ModeMaster {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
        virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
        virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
        virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0; virtual void v15() = 0;
        virtual void v16() = 0; virtual void v17() = 0; virtual void v18() = 0; virtual void v19() = 0;
        virtual void v20() = 0; virtual void v21() = 0; virtual void v22() = 0; virtual void v23() = 0;
        virtual void v24() = 0; virtual void v25() = 0; virtual void v26() = 0; virtual void v27() = 0;
        virtual void v28() = 0; virtual void v29() = 0; virtual void v30() = 0; virtual void v31() = 0;
        virtual void v32() = 0; virtual void v33() = 0; virtual void v34() = 0; virtual void v35() = 0;
        virtual void v36() = 0; virtual void v37() = 0; virtual void v38() = 0; virtual void v39() = 0;
        virtual void v40() = 0; virtual void v41() = 0; virtual void v42() = 0; virtual void v43() = 0;
        virtual void v44() = 0; virtual void v45() = 0; virtual void v46() = 0; virtual void v47() = 0;
        virtual void v48() = 0; virtual void v49() = 0; virtual void v50() = 0; virtual void v51() = 0;
        virtual void v52() = 0; virtual void v53() = 0; virtual void v54() = 0; virtual void v55() = 0;
        virtual void v56() = 0; virtual void v57() = 0; virtual void v58() = 0; virtual void v59() = 0;
        virtual void hook() = 0; /* +0xF8 */
    };
    Tips_LoadCameraSequence();
    fn_801A7F8C();
    fn_800054E0();
    fn_8000F0E4((u8 *)names + 0x1EC);   /* "uifnt_o.gtx": the HUD's font texture */
    fn_8000F884();
    fn_80011F64();
    session = lbl_8034EE84;
    ((SessionState *)session)->field08 = fn_801E87A8();
    ((SessionState *)session)->playerCount = fn_80137C74();
    lbl_8055D354 = fn_802090D4((u8 *)names + 0x1F8);     /* the "dashboard" sound group */
    LoadFloatOption(4, (u8 *)names + 0x204, &lbl_8055892C);  /* saved "effects_volume", else 1.0 */
    fn_80005464();                        /* the session's mode flags off */
    fn_80005C88();                        /* build the HUD overlay managers */
    fn_80011A5C(SESSION->playerCount);    /* the count shutdownGameManagers walks later */
    fn_8001DB54();
    ((ModeMaster *)fn_801B83A0())->hook();
    fn_800070DC();                        /* the overlays to their starting state */
}
#pragma pop

void fn_80006E50(void) {
    /* Empty no-op hook between manager startup (fn_80006D9C) and teardown
     * (shutdownGameManagers); a reserved slot with no work to do in this build. */
}

extern void fn_8001DD6C(void);
extern void fn_8000FB44(void);
extern void fn_800120BC(void);
extern void fn_8000F158(void);
extern void fn_80020430(void);
extern void fn_80209110(void *);
extern void *memset(void *, int, unsigned int);
#pragma cplusplus on
/* shutdownGameManagers - tear the game's managers down (the reverse of fn_80006D9C).
 *
 * The managers sit in the table at lbl_8034EEB8 that fn_80005C88 builds and
 * fn_800070DC walks every frame: one object per entry at +0x18, +0x28 ...
 * (((s32 *)lbl_8055D350)[5] of them - the count fn_80011A5C was handed at
 * startup) plus the singletons at +0x0, +0x4, +0x8, +0xC and +0x50 .. +0x60.
 * Each is dropped through the shared base class's release(1), and the table is
 * zeroed afterwards.  A manager installed over the +0x5C entry (lbl_8055D344,
 * set before fn_80005C88 runs) gets its own slot-0x10 hook instead of being
 * released.  The calls at the end shut down the subsystems fn_80006D9C
 * started up, the last of them the mode master's own teardown.
 */
/* Tear down the game's managers: call the mode master's teardown hook, release every object in the manager table and its singletons, clear the table, then shut down the subsystems the startup routine opened. */ extern "C" void shutdownGameManagers(void) {
    /* What the table's objects have in common: the game's usual release call,
     * the first virtual of their base class, with the "delete too" flag set. */
    struct Releasable {
        virtual void release(s32) = 0;
    };
    /* the manager lbl_8055D344 can install over the table's +0x5C entry;
     * fn_80005C88 calls its slot 0xC when it takes it over */
    struct InstalledManager {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    /* The current mode's master object: fn_801B83A0 returns the instance
     * fn_801B81E0 created for the running mode (a ZoneMaster in zone mode).
     * Only its slot-0xF8 hook is called here, so the slots before it are
     * placeholders. */
    struct ModeMaster {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
        virtual void v30() = 0;
        virtual void v31() = 0;
        virtual void v32() = 0;
        virtual void v33() = 0;
        virtual void v34() = 0;
        virtual void v35() = 0;
        virtual void v36() = 0;
        virtual void v37() = 0;
        virtual void v38() = 0;
        virtual void v39() = 0;
        virtual void v40() = 0;
        virtual void v41() = 0;
        virtual void v42() = 0;
        virtual void v43() = 0;
        virtual void v44() = 0;
        virtual void v45() = 0;
        virtual void v46() = 0;
        virtual void v47() = 0;
        virtual void v48() = 0;
        virtual void v49() = 0;
        virtual void v50() = 0;
        virtual void v51() = 0;
        virtual void v52() = 0;
        virtual void v53() = 0;
        virtual void v54() = 0;
        virtual void v55() = 0;
        virtual void v56() = 0;
        virtual void v57() = 0;
        virtual void v58() = 0;
        virtual void v59() = 0;
        virtual void v60() = 0;
        virtual void hook() = 0;
    };
    void *manager;

    ((ModeMaster *)fn_801B83A0())->hook();
    fn_8001DD6C();

    {
        u8 *entry = (u8 *)lbl_8034EEB8;   /* the per-entry objects, +0x18 apart */
        s32 i = 0;
        goto loop_test;
loop_body:
        manager = *(void **)(entry + 0x18);
        if (manager != 0) {
            ((Releasable *)manager)->release(1);
        }
        entry += 0x10;
        i += 1;
loop_test:
        if (i < ((s32 *)lbl_8055D350)[5]) {
            goto loop_body;
        }
    }

    manager = *(void **)((u8 *)lbl_8034EEB8 + 0xC);
    if (manager != 0) {
        ((Releasable *)manager)->release(1);
    }

    manager = *(void **)lbl_8034EEB8;     /* table+0x00 */
    if (manager != 0) {
        if (manager != 0) {
            ((Releasable *)manager)->release(1);
        }
        *(void **)lbl_8034EEB8 = 0;
    }

    if (lbl_8034EEB8[1] != 0) {           /* table+0x04 */
        if (lbl_8034EEB8[1] != 0) {
            ((Releasable *)lbl_8034EEB8[1])->release(1);
        }
        lbl_8034EEB8[1] = 0;
    }

    manager = lbl_8055D344;               /* manager installed over table+0x5C */
    if (manager != 0) {
        ((InstalledManager *)manager)->v2();
    } else {
        manager = *(void **)((u8 *)lbl_8034EEB8 + 0x5C);
        if (manager != 0) {
            ((Releasable *)manager)->release(1);
        }
    }

    manager = *(void **)((u8 *)lbl_8034EEB8 + 0x54);
    if (manager != 0) {
        ((Releasable *)manager)->release(1);
    }

    manager = *(void **)((u8 *)lbl_8034EEB8 + 0x50);
    if (manager != 0 && manager != 0) {
        ((Releasable *)manager)->release(1);
    }

    manager = *(void **)((u8 *)lbl_8034EEB8 + 0x58);
    if (manager != 0) {
        ((Releasable *)manager)->release(1);
    }

    if (lbl_8034EEB8[2] != 0) {           /* table+0x08 */
        if (lbl_8034EEB8[2] != 0) {
            ((Releasable *)lbl_8034EEB8[2])->release(1);
        }
        lbl_8034EEB8[2] = 0;
    }

    manager = *(void **)((u8 *)lbl_8034EEB8 + 0x60);
    if (manager != 0 && manager != 0) {
        ((Releasable *)manager)->release(1);
    }

    memset(lbl_8034EEB8, 0, 0x64);        /* the whole table is empty now */
    fn_80209110(&lbl_8055D354);           /* the subsystems fn_80006D9C started */
    fn_8000FB44();
    fn_800120BC();
    fn_8000F158();
    fn_801A7F8C();
    fn_80020430();
}
#pragma cplusplus off

void fn_800070D4(void) {
    /* No-op stub beside the HUD-overlay teardown/rebuild code (fn_800070DC);
     * a reserved callback slot with no work to do in this build. */
    return;
}

/* No-op stub beside the HUD-overlay rebuild code (fn_800070DC), immediately
 * after the companion stub fn_800070D4; a reserved callback slot with no work
 * to do in this build. */
void fn_800070D8(void) {
}

#pragma cplusplus on
extern "C" void fn_80209190(s32, f32);
extern "C" void fn_8001DEA8(void);
extern "C" void fn_80011A50(void);
extern "C" void fn_80005464(void);
/* Puts the HUD overlays back the way fn_80005C88 built them.
 *
 * Runs every overlay's init - vtable slot 0x1C, the one fn_80005C88 calls right after it
 * hands a freshly built overlay its vtable - on the intro overlay, the race's Results- and
 * ClosureOverlay, and on the Arena-, PreRace- and PostRaceOverlay when this mode has them.
 * It then does the same for every player's own RacingOverlay and, as it goes, forgets which
 * overlay that player was showing (its OverlayEntry::active), so fn_800057D0 picks a fresh
 * one next frame.  The "dashboard" sound group (lbl_8055D354, registered by name from
 * lbl_802FB0C8 + 0x1F8) is brought back to full volume first; fn_8001DEA8 resets the six
 * screen managers, fn_80011A50 the message/text state and fn_80005464 the session's mode
 * flags.  Called once startup finishes (fn_80006D9C), on a mode change (fn_8000AEC4) and
 * from fn_80007210.
 */
extern "C" void fn_800070DC(void) {
    class Overlay {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void show();  /* +0x14: take the screen */
        virtual void hide();  /* +0x18: give the screen back */
        virtual void init();  /* +0x1C: the ctor fn_80005C88 runs on a built overlay */
    };
    OverlayManager *mgr;
    Overlay *overlay;
    void *overlayObj;
    u8 *cursor;   /* walks the manager's OverlayEntry slots, 0x10 bytes each */
    s32 player;
    s32 noOverlay;
    fn_80209190(lbl_8055D354, 1.0f); /* the "dashboard" sound group back to full volume */
    mgr = OVERLAY_MGR;
    ((Overlay *)mgr->intro)->init();
    ((Overlay *)mgr->results)->init();
    ((Overlay *)mgr->closure)->init();
    if (mgr->arena != 0) {
        ((Overlay *)mgr->arena)->init();
    }
    if (OVERLAY_MGR->postRace != 0) {
        ((Overlay *)OVERLAY_MGR->postRace)->init();
    }
    if (OVERLAY_MGR->preRace != 0) {
        ((Overlay *)OVERLAY_MGR->preRace)->init();
    }
    cursor = (u8 *)lbl_8034EEB8;
    player = 0;
    noOverlay = 0;
    while (player < SESSION->playerCount) {
        overlayObj = *(void **)(cursor + 0x18); /* OverlayEntry::racing */
        overlay = (Overlay *)overlayObj;
        overlay->init();
        *(s32 *)(cursor + 0x10) = noOverlay;    /* OverlayEntry::active: none shown */
        cursor += sizeof(OverlayEntry);
        player++;
    }
    fn_8001DEA8();
    fn_80011A50();
    fn_80005464();
}
#pragma cplusplus reset
/* Reset the HUD: rebuild every overlay's initial state, then rebase the HUD
 * frame timer to the current millisecond tick so the next frame delta is small. */
void fn_80007210(void) {
#define ResetOverlays fn_800070DC
#define GetCurrentTimeMs KERNEL_GetTimeMs
#define hudFrameTimerBase lbl_8055D348
    ResetOverlays();
    hudFrameTimerBase = GetCurrentTimeMs();
#undef ResetOverlays
#undef GetCurrentTimeMs
#undef hudFrameTimerBase
}

extern s32 fn_801E7E3C(void);
extern s32 fn_801E85A4(void);
extern f32 lbl_80560194;
extern f32 lbl_80560198;
extern s32 fn_80161C18(void);
extern s32 updateResultsOverlay(void);
extern s32 fn_801DF110(void);
extern s32 fn_80161A70(void);
extern s32 drawAllPlayerHuds(void);
extern s32 reservedNoOp0(void);
extern s32 fn_80005460(void);
extern s32 getControlScheme(void);
extern s32 fn_800053CC(void);
extern s32 fn_800217E4(void);
#pragma dont_inline fn_800057BC
/* Updates per-frame game state values and runs the main scene update/dispatch sequence. */
void fn_80007238(void) {
    char stack[0x28];
    f32 f3;
    f32 f0;
    s32 mode;

    ((s32 *)lbl_8034EE84)[3] = ((s32 (*)(void))fn_801E7E3C)();
    ((f32 *)lbl_8034EE84)[4] = ((f32 (*)(void))fn_801E7E18)();
    ((s32 *)lbl_8034EE84)[6] = ((s32 (*)(void))fn_801E85A4)();

    fn_80230B5C(stack);
    DrawList_loadMatrix(stack);

    mode = ((s32 *)lbl_8034EE84)[6];
    f0 = lbl_80560194;
    f3 = lbl_80560198;
    f3 = (mode > 2) ? f3 : f0;
    setCameraProjection(lbl_80560130, lbl_80560124, f3);

    fn_800057D0();
    fn_80161C18();
    if (updateResultsOverlay() != 0) goto done;
    if (fn_801DF110() != 0) goto done;
    if (fn_80161A70() != 0) goto done;
    drawAllPlayerHuds();

done:
    fn_80005B6C();
    ((void (*)(s32))fn_80005B70)(0);
    reservedNoOp0();
    fn_80005460();
    if (getControlScheme() == 3) {
        fn_800053CC();
    }
    fn_80005B74();
    fn_80011A2C();
    fn_800057BC();
    fn_800217E4();
}
#pragma cplusplus on
/* Initializes game state/frame context and related managers (sets up state in lbl_8034EE84 from manager lbl_8055D350, triggers v7 on object at lbl_8034EEB8+0x54, and runs init/update routines). */
extern "C" void fn_80007318(void) {
    class Dummy {
    public:
        virtual void v0(void);
        virtual void v1(void);
        virtual void v2(void);
        virtual void v3(void);
        virtual void v4(void);
        virtual void v5(void);
        virtual void v6(void);
        virtual void v7(void);
    };
    char context[0x28];
    u32 *state;
    u32 **manager;
    fn_80005C20();
    fn_80230B5C(context);
    DrawList_loadMatrix(context);
    setCameraProjection(lbl_80560130, lbl_80560124, lbl_8056019C);
    state = (u32 *)lbl_8034EE84;
    state[0x1C / 4] = 0;
    state[0x24 / 4] = ((s32 (*)(s32))fn_801E866C)(0);
    ((u32 *)lbl_8034EE84)[0x28 / 4] = (u32)((void *(*)(void *))fn_801EA9A0)(*(void **)((u8 *)lbl_8055D350 + 0x24));
    manager = (u32 **)lbl_8055D350;
    state[0x2C / 4] = *(u32 *)((u8 *)manager[0x28 / 4] + 8);
    state[0x30 / 4] = (u32)((u8 *)manager[0x28 / 4] + 0xC);
    *(f32 *)&state[0x10 / 4] = ((f32 (*)(void))fn_801E7E18)();
    ((Dummy *)*(void **)((u8 *)lbl_8034EEB8 + 0x54))->v7();
    fn_800057BC();
    fn_80011A2C();
    fn_802C9904();
}
#pragma cplusplus reset
/* Ensures the object at lbl_8034EEB8+0x5C is in state 3 with an associated value, sets its mode (p[4]) from arg0 (0..2), then dispatches and updates. */
void fn_800073D8(s32 mode) {
    s32 *obj;
    s32 value;
    fn_80005C20();
    obj = (s32 *)*(u32 *)((u8 *)lbl_8034EEB8 + 0x5C);
    if (obj[2] != 3) {
        obj[2] = 3;
        if (fn_80009C84() != 0) {
            value = lbl_8055D348;
        } else {
            value = KERNEL_GetTimeMs();
        }
        obj[3] = value;
    }
    switch (mode) {
    case 0: obj[4] = 0; break;
    case 1: obj[4] = 1; break;
    case 2: obj[4] = 2; break;
    }
    fn_800066B4(obj);
    fn_80011A2C();
}

void fn_80007498(void) {
    /* Dispatch hook: forward to fn_80011A50, which zero s_quadCount (no quads
     * buffered) and flushes the buffered quads through fn_80234AEC. */
    fn_80011A50();
}

/* DSP init config bytes: [0] mode-2 flag, [1] DSP-initialized flag, [2] mode-1 flag. */
#define gDspInitFlags lbl_8055D340

/* Return nonzero when the DSP is initialized (flag 1) and mode 2 (flag 0) is selected. */
s32 fn_8000749C(void) {
    s32 enabled = 0;
    if (gDspInitFlags[1] != 0) {
        if (gDspInitFlags[0] != 0) enabled = 1;
    }
    return enabled;
}

/* Return nonzero when the DSP is initialized (flag 1) and mode 1 (flag 2) is selected. */
s32 fn_800074C4(void) {
    s32 enabled = 0;
    if (gDspInitFlags[1] != 0) {
        if (gDspInitFlags[2] != 0) {
            enabled = 1;
        }
    }
    return enabled;
}

extern s32 fn_800213DC(void);
s32 fn_800074EC(s32 eventCode) {
    s32 result;
    /* Dispatch an input/event code: report it handled (1) when the global key
     * handler (fn_800213DC) or the UI popup handler (fn_801DF238) consumes it;
     * otherwise find its index in the table at lbl_8042F798 (fn_80137C98) and
     * send message 0x3E8 with that index to the current player's HUD overlay
     * handler (fn_80007554). */
    if (fn_800213DC() != 0) {
        result = 1;
    } else if (fn_801DF238(eventCode) != 0) {
        result = 1;
    } else {
        fn_802E4A10();
        result = fn_80137C98();
        return fn_80007554(result, 0x3e8, eventCode);
    }
    return result;
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" s32 fn_80007554(s32 playerIndex, s32 param, s32 context) {
    /* Dispatch a per-player overlay handler (vtable slot 0x30) from the HUD overlay manager, if present. */
    struct OverlayHandler {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual s32 Handle(s32 playerIndex, s32 param, s32 context);
    };
    s32 *entry = (s32 *)&lbl_8034EEB8;
    entry += playerIndex * 4;
    OverlayHandler *handler = (OverlayHandler *)entry[4];

    if (handler != 0) {
        return handler->Handle(playerIndex, param, context);
    }
    return 0;
}
#pragma scheduling on
#pragma cplusplus off
/* Returns 1 if the active overlay for the given player is not the closure, post-race, or results overlay. */
s32 fn_800075A0(s32 playerIndex) {
    u32 activeOverlay = *(u32 *)((u8 *)&lbl_8034EEB8 + playerIndex * 0x10 + 0x10);
    s32 result = 0;
    if (activeOverlay != *(u32 *)((u8 *)&lbl_8034EEB8 + 0x58)) {
        if (activeOverlay != *(u32 *)((u8 *)&lbl_8034EEB8 + 8)) {
            if (activeOverlay != *(u32 *)((u8 *)&lbl_8034EEB8 + 0x5c)) {
                result = 1;
            }
        }
    }
    return result;
}

s32 fn_800075E4(s32 ptr, s32 count) {
    /* Return ptr unchanged; if it is non-null and count is positive, free it
     * through fn_80128668 as a side effect (the pointer is still returned). */
    if (ptr != 0 && count > 0) {
        fn_80128668();
    }
    return ptr;
}

s32 fn_80007624(s32 value, s32 count) {
    /* Return value unchanged; if non-zero and count is positive, call fn_80128668 as a side effect. */
    if (value != 0 && count > 0) {
        fn_80128668();
    }
    return value;
}

s32 fn_80007664(s32 ptr, s32 shouldDelete) {
    /* Frees the pointer via fn_80128668 when non-null and deletion is requested. */
    if (ptr != 0 && shouldDelete > 0) {
        fn_80128668();
    }
    return ptr;
}

s32 fn_800076A4(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_800076E4(s32 ptr, s32 shouldDelete) {
    /* Frees the pointer via fn_80128668 when non-null and deletion is requested. */
    if (ptr != 0 && shouldDelete > 0) {
        fn_80128668();
    }
    return ptr;
}

s32 fn_80007724(s32 value, s32 count) {
    /* Return value unchanged; if non-zero and count is positive, call fn_80128668 as a side effect. */
    if (value != 0 && count > 0) {
        fn_80128668();
    }
    return value;
}

s32 fn_80007764(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_800077A4(s32 value, s32 count) {
    /* Return value unchanged; if non-zero and count is positive, call fn_80128668 as a side effect. */
    if (value != 0 && count > 0) {
        fn_80128668();
    }
    return value;
}

extern s32 fn_8000561C(void *, void *);
extern void fn_80276DC8(s32);
extern void *fn_801E87A8(void);
extern s32 fn_801CB8FC(void);
#pragma scheduling on
void fn_800077E4(void *arg0) {
    void *base = lbl_8055D350;
    void *p = (u8 *)arg0 + ((s32 *)base)[7] * 4;
    *(f32 *)((u8 *)p + 4) = ((f32 *)base)[4];
    if (fn_8000561C(p, base)) {
        *(f32 *)((u8 *)arg0 + 0x18) = ((f32 *)lbl_8055D350)[4];
        fn_80276DC8(((s32 *)lbl_8055D350)[7]);
    }
}
/* If the input object's 0x20 flag is clear, queue a value-0x20 one-shot override
 * for the current player (session + 0x1C). */
void fn_80007848(void) {
    void *session = lbl_8055D350;
    void *input = *(void **)((u8 *)session + 0x2C);
    if ((*(u32 *)((u8 *)input + 0x2C0) & 0x20) != 0) {
        return;
    }
    fn_8000C630(0x20, *(s32 *)((u8 *)session + 0x1C));
}

/* UI message callback: only handle message 0x3E8 when the context is null, forwarding the low 16 bits of param to fn_801B87A0; otherwise return 0. */
s32 fn_8000786C(void *obj, void *context, s32 msg, void *param) {
    if (context != 0) {
        return 0;
    }
    if ((u32)msg == 0x3E8) {
        return fn_801B87A0((s32)context, (s32)((u32)param & 0xFFFF));
    }
    return 0;
}

extern f32 fn_80011E44(void);
extern f32 fn_80011E60(void);
extern void fn_8000FBE8(f32, f32, f32);

extern f32 lbl_805601A0, lbl_805601A4, lbl_805601A8, lbl_805601AC;
extern u8 lbl_802FB6B4[];
#pragma cplusplus on
#pragma processor 750
extern "C" void fn_80007898(void *object) {
    struct Dummy {
        virtual s32 f0(); virtual s32 f1(); virtual s32 f2(); virtual s32 f3();
        virtual s32 f4(); virtual s32 f5(); virtual s32 f6(); virtual s32 f7();
        virtual s32 f8(); virtual s32 f9(); virtual s32 f10(); virtual s32 f11();
        virtual s32 f12(); virtual s32 f13(); virtual s32 f14(); virtual s32 f15();
        virtual s32 f16(); virtual s32 f17(); virtual s32 f18(); virtual s32 f19();
        virtual s32 f20(); virtual s32 f21(); virtual s32 f22(); virtual s32 f23();
        virtual s32 f24();
    };
    f32 xPos;
    f32 yPos;
    /* If the global UI state allows it and object flag f12() is clear,
     * draw the "Continue" prompt at the standard screen position. */
    if (((Dummy *)fn_801B83A0())->f23() == 0) return;
    if (((Dummy *)fn_801B83A0())->f24() == 0) return;
    if (((Dummy *)object)->f12() != 0) return;
    xPos = fn_80011E44() - lbl_805601A0;
    yPos = lbl_805601A4 + fn_80011E60();
    fn_8000FBE8(xPos - lbl_805601A8, yPos, lbl_80560130);
    fn_8000FF88(-1, 0x11, lbl_802FB6B4, lbl_805601AC, xPos, yPos);
}
#pragma cplusplus reset
/* Virtual method of the ClosureOverlay UI class (alongside fn_8000797C/fn_80007984/fn_80007990): reports a constant enabled value (1). */
u32 fn_80007974(void) { return 1; }

/* Return this UI overlay's flag byte at offset 0x14. */
u8 fn_8000797C(void *object) { return *((u8 *)object + 0x14); }

extern u8 lbl_802FB6C0[];
/* Return the "ClosureOverlay" name string that identifies this overlay type. */
void *fn_80007984(void) {
    #define s_overlayName lbl_802FB6C0
    return s_overlayName;
    #undef s_overlayName
}

s32 fn_80007990(s32 ptr, s32 shouldDelete) {
    /* Frees the pointer via fn_80128668 when non-null and deletion is requested. */
    if (ptr != 0 && shouldDelete > 0) {
        fn_80128668();
    }
    return ptr;
}

/* Virtual method of the intro/arena-intro overlay UI class family (grouped with fn_800079D8/fn_800079E4/fn_800079F0): reports a constant enabled value (1). */
u32 fn_800079D0(void) { return 1; }

extern u8 lbl_802FB688[];
void *fn_800079D8(void) {
    /* Return the overlay's name string, "ArenaIntroOverlay". */
    #define s_arenaIntroOverlayName lbl_802FB688
    return s_arenaIntroOverlayName;
    #undef s_arenaIntroOverlayName
}

extern u8 lbl_802FB678[];
void *fn_800079E4(void) {
    /* Return the "IntroOverlay" name string. */
    #define s_introOverlayName lbl_802FB678
    return s_introOverlayName;
    #undef s_introOverlayName
}

#pragma cplusplus on
/* Destructor: install vtable, destroy owned child object, release two ref-counted resources, and optionally free this object. */
extern "C" void *fn_800079F0(void *self, s32 deletingFlag) {
    class Entry {
    public:
        virtual void destroy(s32);
    };
    void *child;
    if (self != 0) {
        child = *(void **)((u8 *)self + 0x1C);
        *(void **)self = (void *)lbl_802FB478;
        if (child != 0) {
            if (child != 0) {
                ((Entry *)child)->destroy(1);
            }
        }
        fn_80235380(*(s32 *)((u8 *)self + 0x18));
        fn_80235380(*(s32 *)((u8 *)self + 0x14));
        if (deletingFlag > 0) {
            ((s32 (*)(void *))fn_80128668)(self);
        }
    }
    return self;
}
#pragma cplusplus reset
s32 fn_80007A84(s32 object, s32 shouldDestroy) {
    /* If object is non-null and shouldDestroy > 0, signal it for destruction
     * via fn_80128668 (calls fn_80128584 with mode 3). Returns the object. */
    if (object != 0 && shouldDestroy > 0) {
        fn_80128668();
    }
    return object;
}

#pragma cplusplus on
extern "C" void fn_80007AC4(void *arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    s32 temp_r3;
    u32 temp_r0;

    /* Initialize object state from game mode/id and global flags, and set lbl_8055D340[1]. */
    ((Obj *)arg0)->v5();
    temp_r3 = ((s32 *)fn_801E87A8())[1];
    if (((s32 *)lbl_8055D350)[5] > 1) ((s32 *)arg0)[1] = 3;
    else {
        temp_r0 = temp_r3 + 0xFFE80000;
        if (temp_r0 == 0x302 || temp_r0 == 0x303 || temp_r0 == 0x304 || temp_r0 == 0x201) ((s32 *)arg0)[1] = 2;
        else ((s32 *)arg0)[1] = 1;
    }
    ((s32 *)arg0)[2] = 0;
    ((s32 *)arg0)[4] = 0;
    if (fn_801CB8FC() == 0) ((s32 *)arg0)[4] = 1;
    lbl_8055D340[1] = 1;
}
#pragma cplusplus off
/* Constant predicate/callback used by the game-setting code: always returns 1 (true). */
u32 fn_80007B84(void) { return 1; }

s32 fn_80007B8C(void) {
    /* Queue a one-shot override of game-setting value 0x20 for all four players (-1). */
    return fn_8000C630(0x20, -1);
}

/* UI message callback: forward to the menu handler fn_80006580 only when the
 * normally-unused second argument is zero; otherwise fail with 0. */
s32 fn_80007B98(s32 obj, s32 unused, u32 msg, u32 param) {
    if (unused != 0)
        return 0;
    return ((s32 (*)(void *, u32, u32, u32))fn_80006580)((void *)obj, unused, msg, param);
}

extern u8 lbl_802FB668[];
/* Returns the "ResultsOverlay" scene name string. */
void *fn_80007BB0(void) {
    #define s_resultsOverlayName lbl_802FB668
    return s_resultsOverlayName;
    #undef s_resultsOverlayName
}

/* When the session's startup object has flag 0x200 set, dispatch the HUD event with the session word at +0x1C. */
void fn_80007BBC(void) {
    void **session = (void **)lbl_8055D350;
    if ((*(u32 *)((u8 *)session[2] + 4) & 0x200) == 0) return;
    fn_801B84C0(*(void **)((u8 *)session + 0x1C));
}

extern u8 lbl_802FB630[];
/* Returns the "ArenaOverlay" scene name string. */
void *fn_80007BDC(void) {
    #define s_arenaOverlayName lbl_802FB630
    return s_arenaOverlayName;
    #undef s_arenaOverlayName
}

void fn_80007BE8(void) {
    /* No-op hook among the arena/HUD overlay name getters (fn_80007BDC,
     * fn_80007BEC, ...); a reserved callback slot with no work in this build. */
    return;
}

extern u8 lbl_802FB618[];
void *fn_80007BEC(void) {
    /* Return the "KioskDeadDriverOverlay" name string. */
    #define s_kioskDeadDriverOverlayName lbl_802FB618
    return s_kioskDeadDriverOverlayName;
    #undef s_kioskDeadDriverOverlayName
}

extern u8 lbl_802FB6D0[];
/* Returns the "<unknown>" fallback name string. */
void *fn_80007BF8(void) {
    #define s_unknownName lbl_802FB6D0
    return s_unknownName;
    #undef s_unknownName
}

extern u8 lbl_802FB604[];
/* Returns the "InterludeOverlay" scene name string. */
void *fn_80007C04(void) {
    #define s_interludeOverlayName lbl_802FB604
    return s_interludeOverlayName;
    #undef s_interludeOverlayName
}

extern int __cntlzw(unsigned int);
void fn_80007C10(void *obj) {
    /* Normalize the mode query fn_801769B8 to a 0/1 boolean (two count-leading-
     * zeros) into this overlay object's flag byte at +4, and clear byte +5. */
    s32 state = fn_801769B8();
    s32 isNonZero = (u32)__cntlzw(state) >> 5;
    isNonZero = (u32)__cntlzw(isNonZero) >> 5;
    ((s8 *)obj)[4] = (s8)isNonZero;
    ((s8 *)obj)[5] = 0;
}

extern s32 fn_801B8848(void);
extern s32 fn_801B87A0(s32, s32);
/* Set the queued one-shot override to 0xb for all four players (via fn_8000C630). */
s32 fn_80007C58(void) {
    return fn_8000C630(0xb, -1);
}

/* Returns the boolean flag at byte 4 of the overlay object (as set/cleared by fn_80007C10/fn_80007CD0). */
u8 fn_80007C64(void *obj) {
    return ((u8 *)obj)[4];
}

void fn_80007C6C(void *obj) {
    // Raise the flag at byte 5 of the object when the mode query reports zero.
    if (fn_801B8848() == 0) {
        ((u8 *)obj)[5] = 1;
    }
}

s32 fn_80007CA8(void *ctx, void *value, s32 command, void *packedParam) {
    /* For command 1000, forward `value` and the low 16 bits of the packed
     * parameter to the UI object's method; otherwise do nothing. */
    if ((u32)command == 0x3e8) {
        u32 bits = (u32)packedParam;
        s32 lowParam = bits & 0xFFFF;
        return fn_801B87A0((s32)value, lowParam);
    }
    return 0;
}

/* Returns the "ArenaPreRaceOverlay" scene name string. */
void *fn_80007CC4(void) {
    #define s_arenaPreRaceOverlayName lbl_802FB5F0
    return s_arenaPreRaceOverlayName;
    #undef s_arenaPreRaceOverlayName
}

/* Clear the boolean flag at byte 4 of an arena overlay object (inverse of fn_80007CF0). */
void fn_80007CD0(void *obj) {
    ((u8 *)obj)[4] = 0;
}

/* Return the boolean flag at byte 4 of an arena overlay object. */
u8 fn_80007CDC(void *obj) {
    return ((u8 *)obj)[4];
}

s32 fn_80007CE4(void) {
    /* Queue one-shot override code 0x0b for all four players (fn_8000C630 index -1). */
    return fn_8000C630(0xb, -1);
}

void fn_80007CF0(void *obj) {
    // Raise the flag at byte 4 of the object when the mode query reports zero.
    if (fn_801B880C() == 0) {
        ((u8 *)obj)[4] = 1;
    }
}

s32 fn_80007D2C(void *ctx, void *value, s32 command, void *packedParam) {
    /* For command 1000, forward `value` and the low 16 bits of the packed
     * parameter to the UI object's method; otherwise do nothing. */
    if ((u32)command == 0x3e8) {
        u32 bits = (u32)packedParam;
        s32 lowParam = bits & 0xFFFF;
        return fn_801B87A0((s32)value, lowParam);
    }
    return 0;
}

void *fn_80007D48(void) {
    /* Return the "ArenaPostRaceOverlay" name string. */
    #define s_arenaPostRaceOverlayName lbl_802FB5D8
    return s_arenaPostRaceOverlayName;
    #undef s_arenaPostRaceOverlayName
}

