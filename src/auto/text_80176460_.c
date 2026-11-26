// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern u8 lbl_804303C8[12];
extern char lbl_8055E3BD;
extern void *lbl_8055A2F0;
extern s32 lbl_8055E3D8;
extern f32 lbl_8055A3A0;
extern f32 lbl_80561B18;
extern char *strcpy(char *, const char *);
extern s32 fn_8012F31C(s32);
extern s32 fn_8012F3CC(void);
extern void fn_8012F43C(void);
extern void fn_801E1D20(void);
extern void fn_80178DD0(void);
extern void fn_8017EBE0(void);
extern void fn_801AE5A8(void);
extern void fn_801B6604(void);
extern void fn_801D0BE4(void);
extern void fn_80177790(void);
extern void *lbl_8055E3E8;
extern void __AXDSPInitCallback_801769E0(void);
extern u8 lbl_8055E3E4;
extern char lbl_803316B4[];
extern char lbl_8033189C[];
int fn_80176F9C(void);
void fn_80176F24(void);
void fn_80176FC4(void);
void fn_801775EC(void);
void fn_80177048(void);

extern void fn_80179308(void);
extern u8 lbl_80430558[];
extern s32 lbl_804303D4[];
extern void fn_801AED68(void);
extern void fn_801AED5C(void);
extern s32 fn_801CF050(void);
extern void fn_80176A34(s32);
extern void fn_80176C4C(void);
extern s32 KERNEL_GetTimeMs();
extern void fn_80176F28(void);
extern void fn_80176DD4(void);
extern f32 lbl_8055A2F4;
extern s32 lbl_8055E3C4;
extern f32 lbl_8055E3C8;
extern f32 lbl_80561B20;
extern f32 lbl_8055E460;
extern f32 lbl_80561B1C;
extern s32 lbl_8055E3C0;
void fn_8013A208(void);
extern s32 lbl_8055E3CC;
extern u32 lbl_8055E3F8;
extern s32 lbl_8055E3E0;
extern s32 lbl_8055E3F4;
extern u8 lbl_8055E3EC;
extern char lbl_80331604[];
extern void fn_802E30C8(const char *, ...);
extern char lbl_803316EC[];
extern char lbl_8033170C[];
extern f32 lbl_8055E3FC;
extern f32 lbl_80561B38;
extern f32 lbl_80561B3C;
s32 fn_8012F458(s32, s32);
s32 fn_8012F4AC(s32, void *, s32);
s32 fn_80179658(s32);
__declspec(section ".data") extern u8 lbl_80430418;
extern u32 jumptable_8033182C[];
extern const char lbl_80331810[];
extern char lbl_8055E3D4;
extern void fn_802E4C14(s32);
extern void fn_80178CAC(u32, u32);
extern void fn_80178DD4(void);
extern void fn_8017952C(void);
extern void fn_80179110(void);
extern void fn_801791A8(void);
extern void fn_80179140(void);
extern void fn_801B235C(void);
void fn_80176CC8(void);
void Abend_Panic(const char *, ...);
s32 fn_8017ED00(f32);
void fn_80177138(void);
extern void fn_80176E4C(void);
extern s32 fn_8012F450(s32);
extern s32 fn_8012F384(s32);
extern s32 fn_8012F418(s32);
extern void fn_801D0BF4(void);
extern void fn_801B6614(void);
extern void fn_801AE5AC(void);
extern void fn_8017EC30(void);
extern void fn_801E1D2C(void);
extern void fn_801777C0(void);
extern void fn_8017779C(void);
extern void fn_80176DE0(void);
extern s32 fn_802090D4(s32);
extern s32 lbl_8055E3DC;
extern s32 lbl_8055E3F0;
extern s32 lbl_8055A2F8;
extern char lbl_803315A0[];
extern char lbl_803315C8[];
extern u8 lbl_8055E3BC;
extern u64 KERNEL_GetTimeUs(void);
extern void KERNEL_WaitMilliseconds(s32);
extern f32 fn_8017970C(void);
extern f32 fn_8002FD54(u32, u32);
extern void *fn_80179824(void);
extern s32 fn_801773E4(void);
extern void fn_801C6AD0(s32 *);
extern f32 lbl_8055E3D0;
extern f32 lbl_80561B30;
extern f32 lbl_80561B34;
extern f32 lbl_80561B40;
/* The phys-fader.  A physics mode change that is not applied at once first
 * fades the game out: the request arms this block, fn_801771A8 and fn_801773E4
 * move `alpha` towards 0xFF every tick, and once it has sat there for `hold`
 * ticks the mode goes to FADE_MODE_DONE (or FADE_MODE_IDLE when fading back
 * in) and `onDone` runs -- that is where the pending command is applied. */
typedef struct FadeState {
    s32 lastTime;         /* 0x00: lbl_8055E3C4 of the last step of the ramp */
    s32 lastTick;         /* 0x04: KERNEL_GetTimeMs() the ramp last moved on */
    s32 hold;             /* 0x08: ticks to sit at the end of the ramp */
    s32 mode;             /* 0x0C: FADE_MODE_* state of the ramp */
    void (*onDone)(void); /* 0x10: run when the ramp reaches its end */
    u8 alpha;             /* 0x14: 0..0xFF position in the ramp */
} FadeState;

#define FADE_MODE_IDLE  0 /* nothing fading */
#define FADE_MODE_IN    1 /* fading back in */
#define FADE_MODE_OUT   2 /* fading out; the request is not applied yet */
#define FADE_MODE_DONE  3 /* faded out, request applied */
#define sFadeState      lbl_80430558 /* the module's one FadeState */
#define fader           (*(FadeState *)sFadeState) /* ... reached by field name */
#define sPhysicsFlag    lbl_8055E3BD /* physics module is up (fn_801769F8); picks the fader's time base */
#define sFrameCount     lbl_8055E3C4 /* global frame/tick counter */
#define FADE_FULL       0xFF         /* alpha at the end of the ramp == fully faded */
#define FADE_FROZEN     0xFA         /* alpha an outgoing fade is held at while the Home menu is open */
#define HOME_MENU_HOLD  7            /* steps to sit at the end of the ramp before its callback may fire */
#define RAMP_MS         750          /* ms the whole ramp takes once the physics module is up */
#define RAMP_MS_MAX     0x21         /* ... counting at most 33 ms per step */
#define RAMP_FRAMES_MAX 2            /* ... and at most 2 frames per step while it is down */
#define TIME_SCALE_NONE lbl_80561B1C /* 1.0f: no time scaling outside gameplay */
#define TIME_SCALE_MIN  lbl_80561B30 /* 0.001f: floor for the time scale */
#define RAMP_PER_FRAME  lbl_80561B40 /* 45.0f: ramp units a frame adds at time scale 1 */
#define FADE_TO_VOLUME  lbl_80561B44 /* 255.0f: divides a fade level into a mixer volume */
#define sFaderVolume    lbl_8055E3F0 /* mixer volume handle the fader drives (fn_802090D4/fn_80209190) */
extern void *fn_80176A1C(void);
extern f32 fn_80176A2C(void);
extern f32 lbl_80561B44;
extern void fn_80209190(s32, f32);
extern s32 fn_802ECC10(void);

/* Physics module command: lbl_804303D4 is the request fn_80176780 files,
 * lbl_804303C8 the one in effect that fn_80176C4C copies it over on the next
 * tick.  The mode to switch to travels in the low byte of the first argument
 * of fn_80176780, the flags in its bits 0x1FF00. */
typedef struct PhysicsCommand {
    s32 mode;  /* 0x00: mode to switch to, PHYS_MODE_NONE when there is none */
    s32 flags; /* 0x04: PHYS_FLAG_* bits of the request */
    u8 extra;  /* 0x08: argument that goes with the mode */
} PhysicsCommand;

#define PHYS_MODE_NONE      4       /* no command pending */
#define PHYS_FLAG_100       0x100   /* dropped while lbl_8055E3E4 is set */
#define PHYS_FLAG_200       0x200   /* fn_80176EC0 also calls fn_801AED5C */
#define PHYS_FLAG_APPLY_NOW 0x1000  /* take the command through at once */
#define PHYS_FLAG_FADE      0x8000  /* fade, unless one is already running */
#define PHYS_FLAG_REFADE    0x10000 /* mark the fade done, then fade again */
#define PHYS_FLAG_MASK      0x1FF00 /* the flag bits of a fn_80176780 request */
#define sPendingCommand     lbl_804303D4 /* the PhysicsCommand waiting its turn */
#define STR_PHYS_FADER_ACTIVE lbl_803316B4 /* "physics: hey, phys-fader was active! (new race mode)" */

#pragma opt_common_subs off
void fn_80176460(void *arg0, const char *arg1, s32 *arg2)
{
  s32 v0 = arg2[0];
  s32 p2 = ((s32 *) arg0)[2];
  unsigned short p0 = ((s32 *) arg0)[0 & 0xFFFFFFFF];
  int p1 = ((s32 *) arg0)[1];
  s32 p3 = ((s32 *) arg0)[3];
  volatile short p4 = ((s32 *) arg0)[4] & 0xFFu;
  u8 *base = (u8 *) (&lbl_804303C8);
  u32 *f = (u32 *) (base + 0x18);
  u32 one = 1;
  long long zero = 0;
  u32 *blk;
  u32 *part;
  lbl_8055E3BC = one;
  lbl_8055E3F8 = v0;
  *((u32 *) (base + 0x18)) = p0;
  f[1] = (float) p1;
  ((u32 *) (base + 0x18))[2] = p2;
  ((u32 *) (base + 0x18))[3] = p3;
  ((u32 *) (base + 0x18))[4] = p4;
  strcpy(((char *) base) + 0x30, arg1);
  lbl_8055E3F4 = zero;
  lbl_8055E3BD = one;
  lbl_8055E3C0 = zero;
  lbl_8055E3D4 = zero;
  lbl_8055E3EC = zero;
  lbl_8055E3E8 = 0;
  lbl_8055E3D8 = one;
  lbl_8055A2F0 = (void *) one;
  lbl_8055A2F4 = lbl_80561B18;
  fn_80176A34(0);
  fn_801E1D20();
  fn_80178DD0();
  blk = (u32 *) base;
  part = blk;
  blk[1] = zero;
  blk[0] = 4;
  memset(base + 8, zero, (float) 1);
  part = (u32 *) (base + 0xC);
  part[0] = 4;
  ((u32 *) (base + 0xC))[1] = zero;
  memset(((u8 *) ((u32 *) (base + 0xC))) + 8, zero, 1);
  blk[0] = zero;
  blk[1] = 0x2800;
  if ((p4 & 1) == 0)
  {
    blk[1] |= 0x400;
  }
  lbl_8055E3E4 = 1;
  lbl_8055A3A0 = lbl_80561B1C;
  lbl_8055E3CC = zero;
  lbl_8055E3DC = fn_8012F31C(0x10000);
  lbl_8055E3E0 = fn_8012F3CC();
  fn_8012F43C();
  fn_8017EBE0();
  fn_801AE5A8();
  fn_801B6604();
  fn_801D0BE4();
  fn_80177790();
}
#pragma opt_common_subs reset
/* Shuts down the physics module: unregisters its update callback, clears state, runs subsystem shutdown steps, frees the physics heap/work buffers, resets scene timing, and marks the module inactive. (renames unavailable: fn_801765B8->Physics_Shutdown, lbl_8055E3F4->sPhysicsState, lbl_8055E3E0->sPhysicsHeapBlock, lbl_8055E3DC->sPhysicsWorkBuffer, lbl_8055E3BC->sPhysicsModuleActive) */
void fn_801765B8(void) {
#define sPhysicsState lbl_8055E3F4
#define sPhysicsHeapBlock lbl_8055E3E0
#define sPhysicsWorkBuffer lbl_8055E3DC
#define sPhysicsModuleActive lbl_8055E3BC
    fn_801777C0();
    sPhysicsState = 0;
    fn_801D0BF4();
    fn_801B6614();
    fn_801AE5AC();
    fn_8017EC30();
    fn_8012F418(sPhysicsHeapBlock);
    fn_8012F384(sPhysicsWorkBuffer);
    fn_801E1D2C();
    sPhysicsModuleActive = 0;
#undef sPhysicsState
#undef sPhysicsHeapBlock
#undef sPhysicsWorkBuffer
#undef sPhysicsModuleActive
}

#pragma dont_inline on
/* Step the physics state machine once. */
void fn_80176610(void) {
    fn_80176CC8();
}
#pragma dont_inline reset

#pragma scheduling invalid_target
/* Initialize physics: seal the init stream with a sentinel and log how much of it was used, pump the state machine until it leaves the init state (abort after 10 ticks), then enter state 3, arm the fade-in and notify listeners. */ void fn_80176614(void) {
    s32 ticks;
    lbl_8055E3F4 = 1;
    fn_8012F458(lbl_8055E3E0, -1);
    fn_802E30C8(lbl_803315A0, fn_8012F450(lbl_8055E3E0), 0x10000);
    ticks = 0;
    goto loop_test;
loop_body:
    fn_80176CC8();
    ticks++;
    if (ticks >= 10) Abend_Panic(lbl_803315C8);
loop_test:
    if (lbl_8055E3F4 == 1) goto loop_body;
    lbl_8055E3F4 = 3;
    fn_80176DE0();
    lbl_8055E3F0 = fn_802090D4((s32)&lbl_8055A2F8);
    fn_8017779C();
}
#pragma scheduling on
extern char lbl_803315E8[];
extern s32 fn_80209110(s32 *);
void fn_801766C4(void) {
    /* Pump the physics/scene state machine until it reaches state 8, then release lbl_8055E3F0. */
    s32 i = 0;
    lbl_8055E3F4 = 7;
    goto check_state;
loop:
    fn_80176CC8();
    i += 1;
    if (i >= 10)
        Abend_Panic(lbl_803315E8);
check_state:
    if (lbl_8055E3F4 != 8)
        goto loop;
    fn_80209110(&lbl_8055E3F0);
}

#pragma scheduling invalid_target
void fn_80176734(void) {
    /* If the physics fader is active, log the restart message, then clear the
     * pending physics command to PHYS_MODE_NONE and reinitialize the fade state. */
    if (fn_80176F9C() != 0) {
        fn_802E30C8(lbl_80331604);
    }
    lbl_804303D4[0] = 4;
    fn_80177048();
}
#pragma scheduling on
/* Empty stub; called as a no-op hook from fn_80176780. */
void fn_8017677C(void) {
}

#pragma push
#pragma scheduling invalid_target
/* fn_80176780 - files a physics mode change and starts it.  The low byte of
 * `mode` is the mode to switch to and its PHYS_FLAG_MASK bits the flags for
 * the request (PHYS_FLAG_100 is dropped while lbl_8055E3E4 is set).  The
 * request goes into sPendingCommand, which fn_80176C4C takes over on the next
 * tick, and the switch is started: straight through with
 * PHYS_FLAG_APPLY_NOW, otherwise behind a fade - warning first if a fade of
 * the previous mode is still running. */
void fn_80176780(int mode, u8 *extraByte) {
    s32 flags;
    s32 masked;
    masked = mode & PHYS_FLAG_MASK;
    mode = (u8)mode;
    flags = masked & ~(((s32)(-(s32)lbl_8055E3E4 | (s32)lbl_8055E3E4) >> 31) & PHYS_FLAG_100);
    ((void (*)(int, int, int, int))fn_8017677C)(mode, flags, lbl_8055E3E4, masked);
    if (fn_80176F9C()) fn_802E30C8(STR_PHYS_FADER_ACTIVE);
    ((PhysicsCommand *)sPendingCommand)->mode = mode;
    ((PhysicsCommand *)sPendingCommand)->flags = flags;
    if (extraByte) ((PhysicsCommand *)sPendingCommand)->extra = *extraByte;
    if (flags & PHYS_FLAG_APPLY_NOW) fn_80176F24();
    else if (flags & PHYS_FLAG_FADE) fn_80176FC4();
    else if (flags & PHYS_FLAG_REFADE) { fn_801775EC(); fn_80177048(); }
    else fn_80177048();
}
#pragma scheduling on
#pragma pop
/* Public entry point for the physics fade-in: tail-call the shared fade setup
 * that arms the fade-in callback (fn_80176E4C). */
void fn_80176858(void) {
    fn_80177138();
}

#pragma push
#pragma scheduling invalid_target
void fn_8017685C(s32 arg0) {
    /* Wait for physics to restart (unless arg0==3), set requested physics state, then spin until post-race transition completes. */
    s32 i;

    if (arg0 != 3) {
        __AXDSPInitCallback_801769E0();
        lbl_8055E3F4 = 5;
        i = 0;
        goto first_test;
    first_body:
        fn_80176CC8();
        i += 1;
        if (i >= 10) {
            Abend_Panic(lbl_803316EC);
        }
    first_test:
        if (lbl_8055E3F4 == 5) {
            goto first_body;
        }
    }
    lbl_8055E3E8 = (void *)arg0;
    lbl_8055E3EC = 1;
    i = 0;
    goto second_test;
second_body:
    fn_80176CC8();
    i += 1;
    if (i >= 10) {
        Abend_Panic(lbl_8033170C);
    }
second_test:
    if (lbl_8055E3EC != 0) {
        goto second_body;
    }
}
#pragma scheduling on
#pragma pop
int fn_80176F9C(void);
void fn_801770C8(void);
void fn_80177048(void);
void fn_8017691C(void) {
    // Start the DSP physics fader (fn_801770C8) only when no fader is active.
    if (fn_80176F9C() == 0) {
        fn_801770C8();
    }
}

/* Record current stream offset, write chunk bytes, then advance the offset by the chunk's padded size. */
void fn_80176948(void *chunk, s32 *outOffset) {
    s32 offset = lbl_8055E3CC;
    *outOffset = offset;
    fn_8012F458(lbl_8055E3E0, offset);
    fn_8012F4AC(lbl_8055E3E0, chunk, *(s32 *)((char *)chunk + 4));
    lbl_8055E3CC += fn_80179658(*(s32 *)chunk);
}

s32 fn_801769A8(void);
extern u8 lbl_804303C8[12];
s32 fn_801769A8(void) {
    // Return the flags of the currently active physics command.
    return ((PhysicsCommand*)lbl_804303C8)->flags;
}

void *fn_801769B8(void) {
    /* Return the mode word of the active physics command (callers read it as an s32 mode). */
    return (void *)((PhysicsCommand *)lbl_804303C8)->mode;
}

extern void *lbl_8055E3E8;
void* fn_801769C4(void) {
    /* lbl_8055E3E8 is the requested post-race physics mode: fn_80176460 clears
     * it on init, fn_8017685C sets it, and callers such as fn_80183DF8 test it
     * for mode 2. */
    #define sRequestedPhysicsMode lbl_8055E3E8
    return sRequestedPhysicsMode;
    #undef sRequestedPhysicsMode
}

extern u8 lbl_804303E0[];
/* Get the shared AXFX LFO sine-table object. */
void *__AXFXGetLfoSinTable_801769CC(void) {
    #define s_lfoSinTable lbl_804303E0
    return s_lfoSinTable;
    #undef s_lfoSinTable
}

/* Return a pointer to the configured car/vehicle count (saved from fn_80176460's
 * arg2[0] and copied into lbl_8055E8F8 when the race arrays are built). */
u32 *fn_801769D8(void) {
    #define sCarCount lbl_8055E3F8
    return &sCarCount;
    #undef sCarCount
}

extern void __AXDSPInitCallback_801769E0(void);
extern void Sound_start(void);

#pragma scheduling invalid_target
/* Return true while a physics fade is in progress (fading in or out). */
int fn_80176F9C(void) {
    s32 mode = ((FadeState *)sFadeState)->mode;
    return mode != FADE_MODE_IDLE && mode != FADE_MODE_DONE;
}
#pragma scheduling on
/* Request the AX DSP fade/init transition: if already in state 3 run the completion
 * callback immediately, otherwise arm state 2 with the pending callback and timing
 * fields, trigger DSP init, then run the common update step. */
void fn_80176FC4(void) {
    if (*(s32 *)(lbl_80430558 + 0xC) == 3) {
        fn_80176F28();
    } else {
        *(volatile void **)(lbl_80430558 + 0x10) = (void *)fn_80176F28;
        *(volatile s32 *)(lbl_80430558 + 0xC) = 2;
        *(s32 *)(lbl_80430558 + 4) = KERNEL_GetTimeMs((void *)fn_80176F28);
        *(s32 *)lbl_80430558 = lbl_8055E3C4;
        *(s32 *)(lbl_80430558 + 8) = 7;
        *(u8 *)(lbl_80430558 + 0x14) = 0;
        __AXDSPInitCallback_801769E0();
    }
    Sound_start();
}
#pragma push
#pragma opt_common_subs off
/* Start the fade a physics mode change waits behind: arm the fader with
 * fn_80176F28 as its done handler (that one applies the pending command and
 * fades back in), ramp `alpha` up from 0 with 7 ticks held at the end, and
 * ask the AX DSP for its init callback.  Already faded out there is nothing
 * to wait for, so the command is applied at once.  fn_80176FC4 is the same
 * request with a step of the ramp run right after it. */
void fn_80177048(void) {
    if (*(s32 *)(sFadeState + 0xC) == FADE_MODE_DONE) {
        fn_80176F28();
        return;
    }
    *(void **)(sFadeState + 0x10) = (void *)fn_80176F28;
    *(s32 *)(sFadeState + 0xC) = FADE_MODE_OUT;
    *(s32 *)(sFadeState + 4) = KERNEL_GetTimeMs();
    *(s32 *)sFadeState = lbl_8055E3C4;
    *(s32 *)(sFadeState + 8) = 7;
    *(u8 *)(sFadeState + 0x14) = 0;
    __AXDSPInitCallback_801769E0();
}
#pragma pop
/* Initializes the fade/state block in lbl_80430558 for a fade-out using fn_80176DD4
 * as completion callback: sets callback/time/state fields, latches time values,
 * clears alpha, then marks fade active. */
void fn_801770C8(void) {
    *(void **)(lbl_80430558 + 0x10) = fn_80176DD4;
    *(s32 *)(lbl_80430558 + 0xC) = 2;
    *(s32 *)(lbl_80430558 + 4) = KERNEL_GetTimeMs((void *)fn_80176DD4);
    *(s32 *)lbl_80430558 = lbl_8055E3C4;
    *(s32 *)(lbl_80430558 + 8) = 7;
    *(u8 *)(lbl_80430558 + 0x14) = 0;
    __AXDSPInitCallback_801769E0();
    Sound_start();
}

void fn_80177138(void) {
    /* Configure fade state for callback fn_80176E4C (mode 2, type 7, timing from lbl_8055E3C4). */
    *(void **)(lbl_80430558 + 0x10) = fn_80176E4C;
    *(s32 *)(lbl_80430558 + 0xC) = 2;
    *(s32 *)(lbl_80430558 + 4) = KERNEL_GetTimeMs((void *)fn_80176E4C);
    *(s32 *)lbl_80430558 = lbl_8055E3C4;
    *(s32 *)(lbl_80430558 + 8) = 7;
    *(u8 *)(lbl_80430558 + 0x14) = 0;
    __AXDSPInitCallback_801769E0();
    Sound_start();
}

#pragma push
#pragma opt_common_subs off
/* Step the phys-fader ramp once, every frame (fn_80176A6C).  While a fade
 * runs (mode FADE_MODE_IN/OUT) `alpha` climbs towards 0xFF: by frame at
 * lbl_80561B40/timeScale units per frame while the physics module is down
 * (at most 2 frames per step), or by real time at 255 units per 750 ms once
 * it is up (at most 33 ms per step).  With the Wii Home menu open an
 * outgoing fade is instead frozen just short of the end (alpha clamped to
 * 0xFA, hold re-armed) so its callback cannot fire.  Once alpha has sat at
 * 0xFF for `hold` steps, the mode becomes FADE_MODE_IDLE (faded in) or
 * FADE_MODE_DONE (faded out) and the armed onDone callback runs once. */
void fn_801771A8(void) {
    f32 speed;
    s32 elapsed, ramp, value;
    if ((u32)fader.mode - 1 <= 1U) {
        if (fn_802ECC10() != 0) {
            if (fader.mode == FADE_MODE_OUT) {
                s32 alpha = fader.alpha;
                fader.hold = 7;
                alpha = alpha < 0xFA ? alpha : 0xFA;
                fader.alpha = alpha;
            }
        } else if ((u8)sPhysicsFlag == 0) {
            s32 n, cur, step, frame, last;
            if ((s32)fn_80176A1C() == 2) {
                speed = fn_80176A2C();
            } else {
                speed = lbl_80561B1C; /* 1.0: no time scaling outside gameplay */
            }
            speed = (speed > lbl_80561B30) ? speed : lbl_80561B30; /* >= 0.001 */
            step = (s32)(lbl_80561B40 / speed); /* 45.0: ramp units per frame */
            last = fader.lastTime;
            frame = sFrameCount;
            cur = fader.alpha;
            elapsed = frame - last;
            n = (elapsed > 2) ? 2 : elapsed;
            ramp = cur + ((n << 8) - n) / step; /* + n * 255 / step */
            ramp = ramp & ((-ramp & ~ramp) >> 31);
            value = 0xFF;
            if (ramp < 0xFF) {
                value = ramp;
            }
            fader.lastTime = frame;
            fader.alpha = value;
        } else {
            s32 now = KERNEL_GetTimeMs(); /* milliseconds */
            s32 n = 0x21;
            s32 cur;
            elapsed = now - fader.lastTick;
            cur = fader.alpha;
            if (elapsed <= 0x21) {
                n = elapsed;
            }
            ramp = cur + ((n << 8) - n) / 750; /* 750 ms for the full ramp */
            ramp = ramp & ((-ramp & ~ramp) >> 31);
            value = 0xFF;
            if (ramp < 0xFF) {
                value = ramp;
            }
            fader.alpha = value;
            fader.lastTick = now;
        }
    }
    if (fader.alpha == 0xFF && fader.hold > 0) {
        fader.hold = fader.hold - 1;
    }
    if (fader.alpha == 0xFF && fader.hold <= 0 &&
        (u32)fader.mode - 1 <= 1U) {
        s32 st = FADE_MODE_DONE;
        void (*cb)(void);
        if (fader.mode == FADE_MODE_IN) {
            st = FADE_MODE_IDLE;
        }
        fader.mode = st;
        cb = fader.onDone;
        if (cb != 0) {
            cb();
            fader.onDone = 0;
        }
    }
}
#pragma pop
#pragma push
#pragma opt_common_subs off
/* RealName: Fader_StepAndApplyVolume (rename_symbol unavailable). */
/* Step the phys-fader ramp once -- exactly as fn_801771A8 does, but without
 * finishing the fade or running its callback -- and return where the fade
 * stands: `alpha` while fading out (mode FADE_MODE_OUT/DONE), its inverse
 * while idle or fading back in, so 0 is fully shown and FADE_FULL fully
 * faded.  The mixer volume handle the physics module opened is set to the
 * inverse of that level, and fn_80176A70 stores the level in the physics
 * object it returns. */
s32 fn_801773E4(void) {
    f32 speed;
    s32 elapsed, ramp, value;
    u8 fade;
    if ((u32)fader.mode - 1 <= 1U) {
        if (fn_802ECC10() != 0) {
            /* Wii Home menu open: hold an outgoing fade just short of its end. */
            if (fader.mode == FADE_MODE_OUT) {
                s32 alpha = fader.alpha;
                fader.hold = HOME_MENU_HOLD;
                alpha = alpha < FADE_FROZEN ? alpha : FADE_FROZEN;
                fader.alpha = alpha;
            }
        } else if ((u8)sPhysicsFlag == 0) {
            /* Physics not up yet: ramp by frames, scaled by the game's time scale. */
            s32 n, cur, step, frame, last;
            if ((s32)fn_80176A1C() == 2) {
                speed = fn_80176A2C();
            } else {
                speed = TIME_SCALE_NONE;
            }
            speed = (speed > TIME_SCALE_MIN) ? speed : TIME_SCALE_MIN;
            step = (s32)(RAMP_PER_FRAME / speed);
            last = fader.lastTime;
            frame = sFrameCount;
            cur = fader.alpha;
            elapsed = frame - last;
            n = (elapsed > RAMP_FRAMES_MAX) ? RAMP_FRAMES_MAX : elapsed;
            ramp = cur + ((n << 8) - n) / step; /* + n * 255 / step */
            ramp = ramp & ((-ramp & ~ramp) >> 31); /* 0 once the ramp overflowed */
            value = FADE_FULL;
            if (ramp < FADE_FULL) {
                value = ramp;
            }
            fader.lastTime = frame;
            fader.alpha = value;
        } else {
            /* Physics up: ramp by real time, RAMP_MS for the full ramp. */
            s32 now = KERNEL_GetTimeMs(); /* milliseconds */
            s32 n = RAMP_MS_MAX;
            s32 cur;
            elapsed = now - fader.lastTick;
            cur = fader.alpha;
            if (elapsed <= RAMP_MS_MAX) {
                n = elapsed;
            }
            ramp = cur + ((n << 8) - n) / RAMP_MS;
            ramp = ramp & ((-ramp & ~ramp) >> 31);
            value = FADE_FULL;
            if (ramp < FADE_FULL) {
                value = ramp;
            }
            fader.alpha = value;
            fader.lastTick = now;
        }
    }
    if ((u32)fader.mode <= 1U) {
        fade = FADE_FULL - fader.alpha;
    } else {
        fade = fader.alpha;
    }
    fn_80209190(sFaderVolume, (f32)(FADE_FULL - fade) / FADE_TO_VOLUME);
    return fade;
}
#pragma pop

void __AXDSPInitCallback_801769E0(void) {
    /* DSP init callback: advance the sound-init state to 1. */
#define sSoundInitState lbl_8055E3C0
    sSoundInitState = 1;
#undef sSoundInitState
}

void Sound_start(void) {
    /* Request sound-init state 2 (reset the one-shot flag), then run the DSP init hook. */
#define sSoundInitState lbl_8055E3C0
    sSoundInitState = 2;
#undef sSoundInitState
    fn_8013A208();
}

extern char lbl_8055E3BD;
/* Returns the global physics flag (set when physics is set up) that gates fader/restart handling. */
char fn_801769F8(void) {
    return lbl_8055E3BD;
}

extern void* lbl_8055A2F0;
void fn_80176A00(s32 mode) {
    /* Set the mode at lbl_8055A2F0; when it becomes 1, reset the interpolation factor at lbl_8055E460 to 1.0. */
    *(volatile s32*)&lbl_8055A2F0 = mode;
    if (*(volatile s32*)&lbl_8055A2F0 == 1) {
        lbl_8055E460 = lbl_80561B1C;
    }
}

extern void *lbl_8055A2F0;
#pragma dont_inline on
void* fn_80176A1C(void) {
    /* lbl_8055A2F0 is the global game-flow state (1 while setting up, 2 during
     * active gameplay); callers compare the returned value against 2. */
    #define sGameFlowState lbl_8055A2F0
    return sGameFlowState;
    #undef sGameFlowState
}
#pragma dont_inline reset

/* Sets the global time-scale factor read by fn_80176A2C (default 3.0f), used to scale timer deltas. */
void fn_80176A24(f32 scale) {
    lbl_8055A2F4 = scale;
}

extern f32 fn_80176A2C(void);
f32 fn_80176A2C(void) {
    #define sTimeScale lbl_8055A2F4
    return sTimeScale;
    #undef sTimeScale
}

#define sFrameTime    lbl_8055E3C8 /* that count expressed in seconds */
#define FRAME_SECONDS lbl_80561B20 /* ~1/59.94 s: one NTSC frame in seconds */
/* Set the global frame counter and update its equivalent elapsed time in seconds. */
void fn_80176A34(s32 frameCount) {
    sFrameCount = frameCount;
    sFrameTime = FRAME_SECONDS * (f32)frameCount;
}

/* Step the physics fade ramp once for the current frame. */
void fn_80176A6C(void) {
    fn_801771A8();
}

void *fn_80176A70(void) {
    /* Wait/pump loop during physics init: snapshots generation and start time, then
       runs fn_80176610 until state==2/cancelled/generation changed/isTileCaptureActive!=0.
       After >10000ms logs progress via base+0x190/0x1C8; on 16-bit wrap via +0x204.
       Updates smoothed elapsed in lbl_8055E3D0, stores fn_801773E4() at +0xDB0 of
       fn_80179824()'s result, notifies fn_801C6AD0, and returns it. */
    char *base;
    s32 generationSnap;
    s32 startTimeMs;
    s32 loopCount;
    u64 startTicks;
    u64 nowTicks;
    u64 elapsedTicks;
    f32 elapsedScaled;
    void *physicsObj;

    base = lbl_803315A0;
    generationSnap = lbl_8055E3C4;
    startTimeMs = KERNEL_GetTimeMs();
    loopCount = 0;
    startTicks = KERNEL_GetTimeUs();
    nowTicks = startTicks;

loop:
    fn_80176610();
    if ((s32)fn_80176A1C() == 2 || (u8)lbl_8055E3BD != 0 ||
        generationSnap != lbl_8055E3C4 || isTileCaptureActive() != 0) {
        goto done;
    }
    KERNEL_WaitMilliseconds(0);
    if (KERNEL_GetTimeMs() - startTimeMs > 0x2710) {
        fn_802E30C8(base + 0x190, fn_8017970C());
        Abend_Panic(base + 0x1C8, 10);
    }
    loopCount++;
    if ((u16)loopCount == 0) {
        fn_802E30C8(base + 0x204, loopCount);
    }
    nowTicks = KERNEL_GetTimeUs();
    goto loop;

done:
    elapsedTicks = nowTicks - startTicks;
    elapsedScaled = lbl_80561B30 * fn_8002FD54((u32)(elapsedTicks >> 32), (u32)elapsedTicks);
    lbl_8055E3D0 = elapsedScaled + lbl_80561B34 * (lbl_8055E3D0 - elapsedScaled);
    physicsObj = fn_80179824();
    ((s32 *)physicsObj)[0x36C] = fn_801773E4();
    fn_801C6AD0(&((s32 *)physicsObj)[0x36C]);
    return physicsObj;
}

/* Empty stub. */
void fn_80176BA8(void) {

}

#pragma push
#pragma processor 750
void fn_80176BAC(void) {
    f32 now = lbl_8055E3C8;
    f32 prev = lbl_8055E3FC;
    f32 upper = lbl_80561B38;
    f32 lower;
    f32 value;
    prev = now - prev;
    value = upper < prev ? prev : upper;
    lower = lbl_80561B3C;
    value = lower < value ? lower : value;
    fn_8017ED00(value);
    lbl_8055E3FC = now;
}
#pragma pop
s32 *fn_80176C0C(register s32 *dst, const s32 *src) {
    /* Copy a length-prefixed byte vector: src[0] holds the payload's byte count and
       the bytes follow it; write the same header and payload to dst and return it. */
    s32 byteCount = src[0];
    dst[0] = byteCount;
    memcpy(dst + 1, src + 1, byteCount);
    return dst;
}
#pragma scheduling on
#pragma dont_inline on
/* Promotes the pending PhysicsCommand (sPendingCommand / lbl_804303D4) into the active command slot (lbl_804303C8), resets the pending command to PHYS_MODE_NONE, runs physics world reset (fn_80179320), and advances the physics state machine (lbl_8055E3F4) to state 3. */
void fn_80176C4C(void) {
    if (*(volatile s32 *)sPendingCommand != PHYS_MODE_NONE) {
        ((s32 *)lbl_804303C8)[0] = *(s32 *)sPendingCommand;
        ((s32 *)lbl_804303C8)[1] = ((s32 *)sPendingCommand)[1];
        ((u8 *)lbl_804303C8)[8] = ((u8 *)sPendingCommand)[8];
        *(s32 *)sPendingCommand = PHYS_MODE_NONE;
        ((s32 *)sPendingCommand)[1] = 0;
        memset(sPendingCommand + 2, 0, 1);
    }
    fn_80179320();
    lbl_8055E3F4 = 3;
}
/* Updates the physics/system state each tick: consumes a pending command (if set), dispatches the current state (lbl_8055E3F4) to its handler(s), logs unknown states, and applies deferred flags. */
void fn_80176CC8(void) {
    fn_802E4C14(1);
    if (lbl_80430418 != 0) {
        u8 *pending = (u8 *)&lbl_80430418;
        fn_80178CAC(*(u32 *)(pending + 4), *(u32 *)(pending + 8));
        lbl_80430418 = 0;
    }
    switch ((u32)lbl_8055E3F4) {
        case 0:
            ((void (*)(s32))fn_80178DD4)(lbl_8055E3DC);
            lbl_8055E3F4 = 2;
            break;
        case 1:
            fn_8017952C();
            break;
        case 2:
            fn_80176C4C();
            break;
        case 3:
            fn_80179110();
            fn_8017952C();
            lbl_8055E3F4 = 6;
            break;
        case 4:
            fn_8017952C();
            break;
        case 5:
            fn_801791A8();
            lbl_8055E3F4 = 8;
            break;
        case 6:
        case 7:
        case 8:
        default:
            goto log_state;
    }
    goto check_flags;
log_state:
    Abend_Panic(lbl_80331810, *(volatile s32 *)&lbl_8055E3F4);
check_flags:
    if (*(u8 *)&lbl_8055E3D4 != 0) {
        fn_801B235C();
        lbl_8055E3D4 = 0;
    }
    if (lbl_8055E3EC != 0) {
        fn_80179140();
        lbl_8055E3EC = 0;
    }
}
extern char lbl_8055E3D4;
void fn_80176DD4(void) {
    /* Fade-out completion callback: flag that the pending scene change can run. */
    lbl_8055E3D4 = 1;
}

/* Arms a fade-in without applying a pending physics command, starting the ramp from black on the next step. */
void fn_80176DE0(void) {
    *(s32 *)(sFadeState + 0xC) = FADE_MODE_IN;
    *(s32 *)(sFadeState + 0x10) = 0;
    *(s32 *)(sFadeState + 4) = ((s32 (*)(void))KERNEL_GetTimeMs)() + 0x32;
    *(s32 *)sFadeState = lbl_8055E3C4 + 3;
    *(s32 *)(sFadeState + 8) = 0;
    *(u8 *)(sFadeState + 0x14) = 0;
}

#pragma dont_inline on
#pragma scheduling invalid_target
/* Rearm the fade state after applying the pending physics command:
 * bump the transition counter, tell the DSP the transition is through,
 * then start fading back in from black with a short hold (next step 50 ms /
 * 3 frames out) and no completion callback. */
void fn_80176E4C(void) {
    fn_80179308();
    Sound_start();
    *(s32 *)(sFadeState + 0xC) = FADE_MODE_IN;
    *(s32 *)(sFadeState + 0x10) = 0;
    *(s32 *)(sFadeState + 4) = ((s32 (*)(void))KERNEL_GetTimeMs)() + 0x32;
    *(s32 *)sFadeState = lbl_8055E3C4 + 3;
    *(s32 *)(sFadeState + 8) = 0;
    *(u8 *)(sFadeState + 0x14) = 0;
}

void fn_80176EC0(void) {
    /* Run the pending physics tick if active, then start or clear the next tick as needed. */
    if (sPendingCommand[0] != PHYS_MODE_NONE) {
        fn_801AED68();
        if (sPendingCommand[1] & PHYS_FLAG_200) {
            fn_801AED5C();
        }
    }
    if (fn_801CF050() == 0) {
        fn_80176A34(0);
    }
    fn_80176C4C();
}

#pragma scheduling on
/* Apply the pending physics command immediately. */
void fn_80176F24(void) {
    fn_80176EC0();
}

/* Fade-out done handler (armed by fn_80177048 / fn_80176FC4 as the fader's
 * onDone): takes the pending PhysicsCommand over into the active slot and
 * starts the physics tick it was waiting for (fn_80176EC0), tells the AX DSP
 * the transition is through (Sound_start), and re-arms the fader to fade back
 * in -- FADE_MODE_IN with the ramp restarted at 0, no done handler and nothing
 * held at the end, its next step 50 ms / 3 frames out so the screen stays
 * black for a moment.  fn_80176DE0 arms the same fade-in without applying a
 * command first. */
void fn_80176F28(void) {
    fn_80176EC0();
    Sound_start();
    *(s32 *)(sFadeState + 0xC) = FADE_MODE_IN;
    *(s32 *)(sFadeState + 0x10) = 0;
    *(s32 *)(sFadeState + 4) = ((s32 (*)(void))KERNEL_GetTimeMs)() + 0x32;
    *(s32 *)sFadeState = lbl_8055E3C4 + 3;
    *(s32 *)(sFadeState + 8) = 0;
    *(u8 *)(sFadeState + 0x14) = 0;
}

void fn_801775EC(void) {
    /* Mark the physics fader done (alpha 0xFF, mode 3 = FADE_MODE_DONE) so the
     * pending mode-change command is applied before the next fade starts. */
    u8 *fade = lbl_80430558;
    fade[0x14] = 0xFF;
    *(s32 *)(fade + 0xC) = 3;
}

#pragma cplusplus on
/* Physics-listener fan-out invoker: call `listener`'s first virtual method
 * (vtable slot 0). fn_80177790 passes this to fn_80177658 to run that slot on
 * every registered listener. */
extern "C" void fn_80177608(void* listener) {
    struct Dummy {
        virtual void f0();
    };
    ((Dummy*)listener)->f0();
}

extern "C" void fn_80177618(int* listener) {
    /* Physics-listener fan-out invoker: call the listener's 2nd virtual method
       (vtable +0xC). fn_8017779C passes this to fn_80177658 to run that slot
       on every registered listener. */
    struct Dummy {
        virtual void f0();
        virtual void f1();
    };
    ((Dummy*)listener)->f1();
}

extern "C" void fn_80177628(void* obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
    };
    /* Physics-listener fan-out invoker: call the listener's 3rd virtual method
       (vtable +0x10). fn_801777A8 passes this to fn_80177658 to run that slot
       on every registered listener. */
    ((Dummy*)obj)->f2();
}
#pragma cplusplus on
extern "C" void fn_80177638(int* obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
    };
    /* Physics-listener fan-out invoker: call the listener's 4th virtual method
     * (vtable +0x14). fn_801777B4 passes this to fn_80177658 to run that slot
     * on every registered listener. */
    ((Dummy*)obj)->f3();
}
#pragma cplusplus on
extern "C" void fn_80177648(int* obj) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
    };
    /* Physics-listener fan-out invoker: call the listener's 5th virtual method
     * (vtable +0x18). fn_801777C0 passes this to fn_80177658 to run that slot
     * on every registered listener. */
    ((Dummy*)obj)->f4();
}
#pragma cplusplus off
extern s32 lbl_8055E400;
extern s32 lbl_80430570[];
void fn_80177658(void *arg0) {
    s32 i;
    /* Invoke the given callback for each registered handle in the list. */
    for (i = 0; i < lbl_8055E400; i++) {
        ((void (*)(s32))arg0)(lbl_80430570[i]);
    }
}

extern char lbl_80331850[];
/* Register a physics state listener, panicking if it is already registered. */
void fn_801776C4(u32 listener) {
    s32 listenerCount = lbl_8055E400;
    u32 *entry = (u32 *)lbl_80430570;
    s32 i;
    for (i = listenerCount; i > 0; --i) {
        if (listener == *entry) {
            Abend_Panic(lbl_80331850);
            return;
        }
        entry++;
    }
    lbl_80430570[lbl_8055E400] = listener;
    lbl_8055E400++;
}

void fn_80177720(u32 listener) {
    /* Unregister a physics state listener: drop its handle from the registered array and shift the rest down, or abort if it was never registered. */
    s32 i;
    u32 *entry = (u32 *)lbl_80430570;
    u32 *dest;
    for (i = 0; i < lbl_8055E400; entry++, i++) {
        if (listener == *entry) {
            lbl_8055E400--;
            dest = (u32 *)lbl_80430570 + i;
            memmove(dest, dest + 1, (lbl_8055E400 - i) * 4);
            return;
        }
    }
    Abend_Panic(lbl_8033189C);
}

extern void fn_80177658(void *);
extern void fn_80177608(void *);
extern void fn_80177618(int *);
extern void fn_80177638(int *);
/* Notify every registered physics listener through its slot-0 virtual method. */
void fn_80177790(void) { fn_80177658((void *)fn_80177608); }

#pragma push
#pragma small_data off
/* Runs the slot-1 virtual method on every registered listener by handing the
   fan-out callback fn_80177618 to the per-listener iteration helper. */
void fn_8017779C(void) { fn_80177658((void *)fn_80177618); }
/* Runs the slot-2 virtual method on every registered listener by handing the
   fan-out callback fn_80177628 to the per-listener iteration helper. */
void fn_801777A8(void) { fn_80177658(&fn_80177628); }

/* Runs the slot-3 virtual method on every registered listener by handing the
   fan-out callback fn_80177638 to the per-listener iteration helper. */
void fn_801777B4(void) { fn_80177658(&fn_80177638); }

extern void fn_80177648(int *);
/* Runs the 5th (vtable +0x18) virtual method on every registered listener by
   handing the fan-out callback fn_80177648 to the per-listener iteration helper. */
void fn_801777C0(void) {
    fn_80177658(fn_80177648);
}

/* Register a physics state listener. */
void fn_801777CC(u32 listener) {
    fn_801776C4(listener);
}

extern char lbl_8033189C[];
void fn_801777D0(u32 listener) {
    /* Unregister a physics state listener (tail-call into the removal routine). */
    fn_80177720(listener);
}


