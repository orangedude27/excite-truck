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
extern s32 fn_80005564(void);
extern void *fn_801B83A0(void);
extern void *lbl_8055D350;
extern f32 lbl_8056011C;
extern s32 fn_801E866C(void);
extern void *fn_801EA9A0(void);
extern s32 fn_801B84D8(s32, s32);
extern s32 fn_801B8570(s32);
extern u8 lbl_8034EEB8_arr[];
extern s32 fn_80011A5C(s32);
extern s32 fn_801B84A4(s32);
extern s32 fn_80230DA0(void);
extern void fn_80235380(s32);
extern u8 lbl_802FB478[];
extern u8 lbl_8034EE84[0x100];
extern u8 lbl_8055F024;

extern s32 lbl_8034EEB8[0x100];
extern void fn_800070DC(void);
extern s32 fn_802E2C20(void);
extern s32 lbl_8055D348;
extern f32 lbl_8055D34C;
extern void fn_80005C20(void);
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(f32, f32, f32);
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
extern void fn_80006B18(void *);
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
 * and fn_80005930 updates the ones it picked.  Every overlay answers slot
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
    u8 pad0[0x14];
    s32 playerCount; /* 0x14: how many of the four slots are in use */
} SessionState;

#define OVERLAY_MGR ((OverlayManager *)lbl_8034EEB8)
#define SESSION     ((SessionState *)lbl_8055D350)

#pragma scheduling invalid_target
#pragma push
#pragma dont_inline on
void fn_800056C8(s32 arg0, s32 arg1) {
    lbl_8034EEB8[arg0 * 4 + 4] = arg1;
}
#pragma pop
#pragma scheduling on

#pragma push
#pragma dont_inline on
void fn_800056E0(s32 arg0) {
    s32 count = ((s32 *)lbl_8055D350)[5];
    s32 i = 0;
    for (; i < count; i++) {
        fn_800056C8(i, arg0);
    }
}

#pragma pop
void fn_80005740(s32 arg0) {
    u32 *base;
    void *temp;
    s32 val_2c;
    
    base = (u32 *)lbl_8034EE84;
    base[0x1C / 4] = arg0;
    base[0x24 / 4] = (u32)fn_801E866C();
    temp = fn_801EA9A0();
    base[0x28 / 4] = (u32)temp;
    val_2c = ((s32 *)temp)[2];
    base[0x2C / 4] = val_2c;
    base[0x30 / 4] = (u32)((u8 *)temp + 0xC);
    base[0x20 / 4] = (u32)fn_801B84D8(arg0, val_2c);
    if (fn_80005564() != 0) {
        fn_801B8570((s32)base[0x24 / 4]);
    }
}

#pragma push
#pragma dont_inline on
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
 * or the race's ClosureOverlay for the players already out of it.  fn_80005930
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
s32 fn_80005930(void) {
    extern s32 fn_801E85A4(void);
    extern void fn_801E88B4(s32 *, s32 *, s32 *, s32 *, s32);
    extern s32 fn_801E89EC(void);
    extern s32 fn_802C86F0(void *, s32, s32, s32, s32);
    extern s32 fn_802C8750(void *, s32);
    extern s32 fn_8000D75C(void);
    extern s32 fn_80010EC8(void);
    extern s32 fn_8001123C(s32);
    extern s32 lbl_8055CFF0, lbl_8055CFF4;
    s32 sp28[4], sp18[4], count = fn_801E85A4(), i;
    s32 *entry = lbl_8034EEB8;
    for (i = 0; i < count; i++, entry += 4) {
        void *obj;
        fn_80005740(i); obj = *(void **)(entry + 4);
        if (obj != *(void **)(entry + 5)) {
            if (obj) (*(void (**)(void))((u8 *)*(void **)obj + 0x18))();
            obj = *(void **)(entry + 4);
            (*(void (**)(void *))((u8 *)*(void **)obj + 0x14))(obj);
            *(void **)(entry + 5) = obj;
        }
        fn_80010EC8();
        if ((*(s32 (**)(void *))((u8 *)*(void **)obj + 0x28))(obj)) {
            sp28[1] = 0; sp28[0] = 0; sp28[2] = lbl_8055CFF0; sp28[3] = lbl_8055CFF4;
        } else fn_801E88B4(&sp28[1], &sp28[0], &sp28[2], &sp28[3], i);
        fn_802C86F0(&sp28[0], sp28[1], sp28[0], sp28[2], sp28[3]);
        (*(void (**)(void *))((u8 *)*(void **)obj + 0x20))(obj);
        if (fn_801E89EC() != 3 && (fn_8000D75C(), (*(s32 (**)(void *))((u8 *)*(void **)obj + 0x28))(obj) != 0 || i == 0))
            (*(void (**)(void *))((u8 *)*(void **)obj + 0x24))(obj);
        fn_8001123C(*(s32 *)((u8 *)lbl_8055D350 + 0x1C)); fn_80011A2C(); fn_802C8750(&sp28[0], -1);
    }
    entry = lbl_8034EEB8;
    for (i = 0; i < count; i++, entry += 4) {
        void *obj;
        fn_80005740(i); obj = *(void **)(entry + 4); fn_80010EC8();
        fn_802C86F0(&sp18[0], 0, 0, lbl_8055CFF0, lbl_8055CFF4);
        (*(void (**)(void *))((u8 *)*(void **)obj + 0x20))(obj);
        if (fn_801E89EC() != 3) { fn_8000D75C(); (*(void (**)(void *, s32))((u8 *)*(void **)obj + 0x2C))(obj, i); }
        fn_8001123C(*(s32 *)((u8 *)lbl_8055D350 + 0x1C)); fn_80011A2C(); fn_802C8750(&sp18[0], -1);
    }
}
#pragma dont_inline reset
#pragma pop
void fn_80005B54(void) {
    return;
}

void fn_80005B58(void) {
    return;
}

void fn_80005B64(void) {
    return;
}

void fn_80005B68(void) {

}

#pragma push
#pragma dont_inline on
void fn_80005B6C(void) {
    return;
}
#pragma pop

void fn_80005B70(void) {
}

#pragma cplusplus on
#pragma push
#pragma dont_inline on
extern "C" void fn_80005B74(void) {
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
    extern void fn_800105A0(const char *, s32);
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
                fn_800105A0((char *)base + 0x38, 0);
        } else {
            sprintf(message, (char *)base + 0x4C, targetTime - currentTime);
            fn_800105A0(message, 0);
        }
    }
}
void fn_80005C20(void) {
    f32 temp_f0;
    f32 var_f3;
    s32 temp_r3;

    temp_r3 = fn_802E2C20();
    var_f3 = lbl_8056011C;
    temp_f0 = (f32)(temp_r3 - lbl_8055D348) / lbl_80560124;
    var_f3 = (var_f3 > temp_f0) ? var_f3 : temp_f0;
    lbl_8055D34C = var_f3;
    lbl_8055D348 = temp_r3;
}

#pragma pop
#pragma cplusplus off
extern void *fn_801284F8(s32, const char *);
extern void *fn_80014524(void *, s32);
extern void fn_80176780(s32, s32);
extern s32 fn_801B8914(void);
extern s32 fn_801B8900(void);
extern void *fn_80145E70(void *);
extern void *fn_8023512C(void *);
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
    u8 *entry;
    s32 count;
    s32 i;
    void *object;

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
    for (i = 0; (u32)i < 4U; i++, entry += 0x10) {
        *(s32 *)(entry + 0x10) = 0;
        *(s32 *)(entry + 0x14) = 0;
        if (i < count) {
            object = fn_801284F8(0x54, (const char *)(strings + 0x118));
            if (object != 0) object = fn_80014524(object, i);
            *(void **)(entry + 0x18) = object;
        } else {
            *(void **)(entry + 0x18) = 0;
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
            *(void **)((u8 *)object + 0x14) = fn_8023512C(lbl_802FB65C);
            *(void **)((u8 *)object + 0x18) = fn_8023512C(lbl_802FB650);
            *(void **)((u8 *)object + 0x1C) = fn_80145E70(lbl_802FB640);
            ((Dummy *)object)->v5();
        }
        *(void **)((u8 *)lbl_8034EEB8 + 0x5C) = object;
    }
    *(s32 *)((u8 *)lbl_8034EEB8 + 0x60) = 0;
}
#pragma pop
#pragma scheduling on
#pragma cplusplus reset
s32 fn_80005FE0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80006020(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80006060(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_800060A0(void *arg0) {
    lbl_8055D340[1] = 0;
    ((s32 *)arg0)[2] = 0;
}

void fn_800060B4(void) {
    return;
}

extern f32 lbl_80560138;
void fn_800060B8(void *arg0) {
    float value = lbl_80560138;
    *(u8 *)((u8 *)arg0 + 0x14) = 0;
    *(float *)((u8 *)arg0 + 4) = value;
    *(float *)((u8 *)arg0 + 8) = value;
    *(float *)((u8 *)arg0 + 0xC) = value;
    *(float *)((u8 *)arg0 + 0x10) = value;
    *(float *)((u8 *)arg0 + 0x18) = value;
}

void fn_800060DC(void) {
}

void fn_800060E0(u8 arg0, u8 arg1) {
    register u8 *p = lbl_8055D340;
    p[0] = arg0;
    p[2] = arg1;
    __AXDSPInitCallback_801769E0();
    fn_8017691C();
}

#pragma cplusplus on
extern "C" void fn_80006110(void *arg0) {
    class VTable {
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
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual s32 v21(s32);
        virtual void v22();
        virtual s32 v23();
    };
    extern void fn_8001071C(void *, s32);
    extern u8 lbl_802FB69C[];
    extern s32 lbl_8034EEB8[];
    f32 threshold;
    s32 flag;
    s32 *settings;
    s32 index;
    f32 f2;
    threshold = lbl_8056011C;
    flag = 0;
    settings = (s32 *)lbl_8055D350;
    index = settings[7];
    f2 = *(f32 *)((s8 *)arg0 + index * 4 + 4);
    if (f2 >= threshold) {
        f32 f0 = *(f32 *)(settings + 4) - f2;
        if (f0 > threshold)
            flag = 1;
    }
    if (flag == 0) {
        if (fn_80005564() == 0) {
            s32 *p = lbl_8034EEB8 + ((s32 *)lbl_8055D350)[7] * 4;
            void *obj = *(void **)(p + 7);
            ((VTable *)obj)->v7();
        }
    } else {
        if (fn_80005564() != 0) {
            VTable *obj = (VTable *)fn_801B83A0();
            s32 result = obj->v23();
            if (result != 0) {
                VTable *obj2 = (VTable *)fn_801B83A0();
                result = obj2->v21(((s32 *)lbl_8055D350)[7]);
                s32 normalized = (result == 0);
                *(s8 *)((s8 *)arg0 + 0x14) = normalized;
                return;
            }
        }
        *(u8 *)((u8 *)arg0 + 0x14) = 1;
        s32 *settings3 = (s32 *)lbl_8055D350;
        void *object = *(void **)((u8 *)settings3 + 0x30);
        s32 index3 = settings3[7];
        u8 *p = 0;
        if (*(u8 *)((u8 *)object + 0x28) != 0)
            p = lbl_802FB69C;
        if (p != 0)
            fn_8001071C(p, index3);
    }
}
#pragma cplusplus off
s32 ARCClose(void) {
    return 0;
}

s32 fn_80006244(void) {
    return 0;
}

s32 fn_8000624C(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_80006254(s32 arg0, s32 arg1) {
    int flag = 0;
    f32 threshold = lbl_8056011C;
    f32 f2 = *(f32 *)((s8 *)arg0 + ((s32 *)lbl_8055D350)[7] * 4 + 4);
    if (f2 >= threshold) {
        f32 f0 = ((f32 *)lbl_8055D350)[4] - f2;
        if (f0 > threshold) flag = 1;
    }
    if (flag && fn_80005564()) {
        struct Dummy {
            virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
            virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
            virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
            virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
            virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
            virtual void f20(); virtual void f21(); virtual void f22(s32);
        };
        void *obj = fn_801B83A0();
        ((Dummy *)obj)->f22(arg1);
    }
}
#pragma cplusplus reset
void fn_800062E4(void) {
    return;
}

void fn_800062E8(void) {
    if (fn_801B885C(((s32 *)lbl_8055D350)[7]) == 0 &&
        ((s32 *)lbl_8055D350)[6] == ((s32 *)lbl_8055D350)[5]) {
        fn_8000FBE4();
    }
}

#pragma cplusplus on
extern "C" void fn_80006330(void) {
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
    u32 *flags = (u32 *)lbl_8034EE84;
    s32 *manager;
    flags[8] &= 0xFFFFFF78;
    flags[8] &= 0xFFFFF9FF;
    manager = (s32 *)lbl_8055D350;
    ((Dummy *)((lbl_8034EEB8 + (manager[7] << 2))[7]))->v7();
}
#pragma cplusplus off
extern s32 fn_80011A5C(s32);
extern s32 fn_801B84A4(s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80006378(s32 arg0, s32 arg1) {
    struct Dummy { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); };
    s32 *entry = (s32 *)&lbl_8034EEB8;
    entry += arg1 * 4;
    ((Dummy *)entry[7])->v10();
}
#pragma scheduling on
#pragma cplusplus off
s32 fn_8000639C(void) {
    return 0;
}

void fn_800063A4(void) {
    fn_801C6B70();
}

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_800063A8(void) {
    s32 *state = (s32 *)lbl_8055D350;
    s32 index = state[7];
    s32 *entry;
    void *object;
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

    fn_80011A5C(state[5]);
    entry = (s32 *)&lbl_8034EEB8;
    entry += index * 4;
    object = (void *)entry[6];
    ((Dummy *)object)->v7();
    fn_801B84A4(index);
}

extern "C" s32 fn_80006408(void *arg0, s32 arg1, u32 arg2, u32 arg3) {
    class Obj {
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
    if ((((s32 *)lbl_8055D350)[8] & 4) != 0) {
        u8 *base = (u8 *)lbl_8034EEB8;
        s32 off = arg1 << 4;
        void *obj = *(void **)(base + off + 0x18);
        if (((Obj *)obj)->v10() != 0) {
            return 1;
        }
    }
    if (arg2 == 0x3E8) {
        return fn_801B87A0(arg1, (s32)(u16)arg3);
    }
    return 0;
}

#pragma cplusplus reset
void fn_800064A8(void *arg0) {
    s32 *p = (s32 *)arg0;
    if (p[2] != p[1]) {
        p[1] = p[2];
        p[3] = fn_80009C84() != 0 ? lbl_8055D348 : fn_802E2C20();
    }
    fn_80011A2C();
    switch (p[1]) {
    case 3: fn_800066B4(arg0); return;
    case 2: fn_801CB844(); return;
    case 1: if (fn_801B8874() == 0) fn_80006B18(arg0); return;
    }
}
void fn_80006550(void *arg0, s32 arg1) {
    s32 temp_r0;
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x10) + arg1;
    *(s32 *)((u8 *)arg0 + 0x10) = temp_r0;
    if (temp_r0 < 0) *(s32 *)((u8 *)arg0 + 0x10) = 0;
    if (*(s32 *)((u8 *)arg0 + 0x10) >= 3) *(s32 *)((u8 *)arg0 + 0x10) = 2;
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
extern f32 lbl_80560128, lbl_8056011C, lbl_80560130, lbl_8056013C;
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
    void *(*get)(void *, s32);
    void *(*get2)(void *, s32, s32);
    fn_8027AA48();
    fn_80011E70();
    fn_80011E90();
    fn_800109E4(0x7F000000, lbl_80560140, lbl_80560144, lbl_80560148, lbl_8056014C);
    obj = *(void **)((u8 *)arg0 + 0x1C);
    if (obj != 0) ((void (*)(void *, void *, void *, s32))fn_8014784C)(obj, base + 0x1B4, base + 0x1C0, 0);
    f = (f32)fn_802E2C20();
    sin(lbl_80560150 * (lbl_80560154 * f));
    if (*(void **)((u8 *)arg0 + 0x1C) == 0) return;
    if (fn_80009C84()) now = lbl_8055D348;
    else now = fn_802E2C20();
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
    { f32 zero = lbl_8056011C, half = lbl_8056013C, one = lbl_80560130;
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
            s32 mode;
            if (selected) mode = 1;
            else mode = 2;
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
                    out[6] = (out[6] & 0x00FFFF00) | ((u32)alpha << 24) | (out[6] & 0xFFFF);
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
extern s32 fn_80010E94(s32, s32, f32, f32, f32, f32);
extern f32 fn_80011E34(void);
extern f32 fn_80011E54(void);
extern void *fn_800122B4(s32, void *);
extern void fn_801345D8(void *, s32, const char *, ...);
extern s32 fn_801EA994(void);
extern void *fn_801EA9B0(s32);
extern f32 lbl_80560118, lbl_80560170, lbl_80560174, lbl_80560178, lbl_8056017C;
extern f32 lbl_80560180, lbl_80560184, lbl_80560188, lbl_8056018C;
extern const char lbl_80558930[], lbl_80558934[], lbl_80558940[];
void fn_80006B18(void *arg0) {
    u8 sp8[8];
    u8 sp10[16];
    f32 start;
    f32 now;
    f32 y;
    f32 advance;
    f32 scale;
    f32 gap;
    f32 threshold;
    f32 percent;
    f32 offset;
    f32 percentScale;
    f32 value;
    s32 i;
    s32 flags;
    s32 whole;
    s32 remainder;
    void *entry;

    start = fn_80011E34();
    now = fn_80011E54() - lbl_80560170;
    i = 0;
    scale = lbl_80560174;
    gap = lbl_80560178;
    threshold = lbl_8056017C;
    percent = lbl_80560188;
    offset = lbl_80560184;
    percentScale = lbl_8056018C;
    for (; i < fn_801EA994(); i++) {
        entry = fn_801EA9B0(i);
        y = now - scale * (f32)i;
        fn_80010E94(*(s32 *)((u8 *)arg0 + 0x14), 0, start,
                    y - gap, lbl_80560118, lbl_8056017C);
        flags = *(s32 *)((u8 *)entry + 0xC);
        advance = start + scale;
        if (flags & 1) {
            fn_8000FF88(-0x100, 0x41, (void *)lbl_80558930,
                        lbl_80560180, advance, (y - gap) - threshold,
                        *(void **)((u8 *)entry + 0x14));
            advance += offset;
        } else if (flags & 2) {
            value = *(f32 *)((u8 *)entry + 0x18);
            if (value < lbl_8056011C) {
                fn_801345D8(sp8, 8, lbl_80558934);
            } else {
                whole = (s32)value;
                remainder = (s32)(percent * value) - whole * 100;
                fn_801345D8(sp8, 8, lbl_80558940, whole, remainder);
            }
            fn_8000FF88(-0x100, 0x41, &lbl_80558948,
                        lbl_80560180, advance, (y - gap) - threshold, sp8);
            advance += percentScale;
        } else {
            fn_8000FF88(-0x100, 0x41, &lbl_80558948,
                        lbl_80560180, advance, (y - gap) - threshold,
                        fn_800122B4(i + 1, sp10));
            advance += offset;
        }
        fn_8000FF88(-0x100, 0x21, &lbl_80558948,
                    lbl_80560130, advance, (y - gap) - threshold,
                    (u8 *)entry + 0x48);
    }
}
#pragma ppc_psq_save reset
#pragma use_lmw_stmw reset

#pragma scheduling invalid_target
void fn_80006D30(void) {
    char sp8[0x48];
    if (((s32 *)((u8 *)*(void **)((u8 *)lbl_8055D350 + 0x2C) + 0x2C0))[0] & 0x10) {
        sprintf(sp8, (const char *)lbl_802FB2A0, lbl_80558928);
        ((void (*)(s32, s32, const char *, char *, f32, f32, f32, ...))fn_80010074)(-1, 0x14, (const char *)&lbl_80558948, sp8, lbl_80560134, lbl_8056011C, lbl_80560190);
    }
}
#pragma scheduling on

extern void fn_800201F0(void);
extern void fn_801A7F8C(void);
extern void fn_800054E0(void);
extern void fn_8000F0E4(void *);
extern void fn_8000F884(void);
extern void fn_80011F64(void);
extern s32 fn_80137C74(void);
extern s32 fn_802090D4(void *);
extern void fn_801331C4(s32, void *, s32 *);
extern void fn_80005464(void);
extern void fn_8001DB54(void);
extern s32 lbl_8055892C;
#pragma push
#pragma cplusplus on
#pragma dont_inline on
extern "C" void fn_80006D9C(void) {
#pragma scheduling invalid_target
    u8 *resource = lbl_802FB0C8;
    u8 *state;
    struct Dummy {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
        virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
        virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
        virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
        virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35();
        virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
        virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43();
        virtual void f44(); virtual void f45(); virtual void f46(); virtual void f47();
        virtual void f48(); virtual void f49(); virtual void f50(); virtual void f51();
        virtual void f52(); virtual void f53(); virtual void f54(); virtual void f55();
        virtual void f56(); virtual void f57(); virtual void f58(); virtual void f59();
        virtual void f60();
    };
    fn_800201F0();
    fn_801A7F8C();
    fn_800054E0();
    fn_8000F0E4(resource + 0x1EC);
    fn_8000F884();
    fn_80011F64();
    state = lbl_8034EE84;
    *(void **)(state + 8) = fn_801E87A8();
    *(s32 *)(state + 0x14) = fn_80137C74();
    lbl_8055D354 = fn_802090D4(resource + 0x1F8);
    fn_801331C4(4, resource + 0x204, &lbl_8055892C);
    fn_80005464();
    fn_80005C88();
    fn_80011A5C(((s32 *)lbl_8055D350)[5]);
    fn_8001DB54();
    ((Dummy *)fn_801B83A0())->f60();
    fn_800070DC();
#pragma scheduling on
}
#pragma pop

void fn_80006E50(void) {
}

extern void fn_8001DD6C(void);
extern void fn_8000FB44(void);
extern void fn_800120BC(void);
extern void fn_8000F158(void);
extern void fn_80020430(void);
extern void fn_80209110(void *);
extern void *memset(void *, int, unsigned int);
#pragma cplusplus on
/* fn_80006E54 - tear the game's managers down (the reverse of fn_80006D9C).
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
extern "C" void fn_80006E54(void) {
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
    return;
}

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
void fn_80007210(void) {
    fn_800070DC();
    lbl_8055D348 = fn_802E2C20();
}

extern s32 fn_801E7E3C(void);
extern s32 fn_801E85A4(void);
extern f32 lbl_80560194;
extern f32 lbl_80560198;
extern s32 fn_80161C18(void);
extern s32 fn_80021258(void);
extern s32 fn_801DF110(void);
extern s32 fn_80161A70(void);
extern s32 fn_80005930(void);
extern s32 fn_8000545C(void);
extern s32 fn_80005460(void);
extern s32 fn_8023D6FC(void);
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
    fn_802C8638(stack);

    mode = ((s32 *)lbl_8034EE84)[6];
    f0 = lbl_80560194;
    f3 = lbl_80560198;
    f3 = (mode > 2) ? f3 : f0;
    fn_802C974C(lbl_80560130, lbl_80560124, f3);

    fn_800057D0();
    fn_80161C18();
    if (fn_80021258() != 0) goto done;
    if (fn_801DF110() != 0) goto done;
    if (fn_80161A70() != 0) goto done;
    fn_80005930();

done:
    fn_80005B6C();
    ((void (*)(s32))fn_80005B70)(0);
    fn_8000545C();
    fn_80005460();
    if (fn_8023D6FC() == 3) {
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
    fn_802C8638(context);
    fn_802C974C(lbl_80560130, lbl_80560124, lbl_8056019C);
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
            value = fn_802E2C20();
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
    fn_80011A50();
}

s32 fn_8000749C(void) {
    s32 result = 0;
    if (lbl_8055D340[1] != 0) {
        if (lbl_8055D340[0] != 0) result = 1;
    }
    return result;
}

s32 fn_800074C4(void) {
    s32 result = 0;
    if (lbl_8055D340[1] != 0) {
        if (lbl_8055D340[2] != 0) {
            result = 1;
        }
    }
    return result;
}

extern s32 fn_800213DC(void);
s32 fn_800074EC(s32 arg0) {
    s32 result;
    if (fn_800213DC() != 0) {
        result = 1;
    } else if (fn_801DF238(arg0) != 0) {
        result = 1;
    } else {
        fn_802E4A10();
        result = fn_80137C98();
        return fn_80007554(result, 0x3e8, arg0);
    }
    return result;
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" s32 fn_80007554(s32 arg0, s32 arg1, s32 arg2) {
    struct Dummy { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual s32 call(s32, s32, s32); };
    s32 *entry = (s32 *)&lbl_8034EEB8;
    entry += arg0 * 4;
    Dummy *obj = (Dummy *)entry[4];
    if (obj != 0) {
        return obj->call(arg0, arg1, arg2);
    }
    return 0;
}
#pragma scheduling on
#pragma cplusplus off
s32 fn_800075A0(s32 arg0) {
    u32 p = *(u32 *)((u8 *)&lbl_8034EEB8 + arg0 * 0x10 + 0x10);
    s32 result = 0;
    if (p != *(u32 *)((u8 *)&lbl_8034EEB8 + 0x58)) {
        if (p != *(u32 *)((u8 *)&lbl_8034EEB8 + 8)) {
            if (p != *(u32 *)((u8 *)&lbl_8034EEB8 + 0x5c)) {
                result = 1;
            }
        }
    }
    return result;
}

s32 fn_800075E4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007624(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007664(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800076A4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800076E4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007724(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80007764(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_800077A4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern s32 fn_8000561C(void *, void *);
extern void fn_80276DC8(s32);
extern void *fn_801E87A8(void);
extern s32 fn_801CB8FC(void);
#pragma scheduling invalid_target
void fn_800077E4(void *arg0) {
    void *base = lbl_8055D350;
    void *p = (u8 *)arg0 + ((s32 *)base)[7] * 4;
    *(f32 *)((u8 *)p + 4) = ((f32 *)base)[4];
    if (!fn_8000561C(p, base)) {
        return;
    }
    *(f32 *)((u8 *)arg0 + 0x18) = ((f32 *)lbl_8055D350)[4];
    fn_80276DC8(((s32 *)lbl_8055D350)[7]);
}
void fn_80007848(void) {
    void *base = lbl_8055D350;
    void *object = *(void **)((u8 *)base + 0x2C);
    if ((*(u32 *)((u8 *)object + 0x2C0) & 0x20) != 0) {
        return;
    }
    fn_8000C630(0x20, *(s32 *)((u8 *)base + 0x1C));
}

s32 fn_8000786C(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg1 != 0) {
        return 0;
    }
    if ((u32)arg2 == 0x3E8) {
        return fn_801B87A0((s32)arg1, (s32)((u32)arg3 & 0xFFFF));
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
u32 fn_80007974(void) { return 1; }

u8 fn_8000797C(void *arg0) { return *((u8 *)arg0 + 0x14); }

extern u8 lbl_802FB6C0[];
void *fn_80007984(void) {
    return lbl_802FB6C0;
}

s32 fn_80007990(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

u32 fn_800079D0(void) { return 1; }

extern u8 lbl_802FB688[];
void *fn_800079D8(void) {
    return lbl_802FB688;
}

extern u8 lbl_802FB678[];
void *fn_800079E4(void) {
    return lbl_802FB678;
}

#pragma cplusplus on
extern "C" void *fn_800079F0(void *arg0, s32 arg1) {
    class Entry {
    public:
        virtual void destroy(s32);
    };
    void *entry;
    if (arg0 != 0) {
        entry = *(void **)((u8 *)arg0 + 0x1C);
        *(void **)arg0 = (void *)lbl_802FB478;
        if (entry != 0) {
            if (entry != 0) {
                ((Entry *)entry)->destroy(1);
            }
        }
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x18));
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x14));
        if (arg1 > 0) {
            ((s32 (*)(void *))fn_80128668)(arg0);
        }
    }
    return arg0;
}
#pragma cplusplus reset
s32 fn_80007A84(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
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
u32 fn_80007B84(void) { return 1; }

s32 fn_80007B8C(void) {
    return fn_8000C630(0x20, -1);
}

s32 fn_80007B98(s32 arg0, s32 arg1, u32 arg2, u32 arg3) {
    if (arg1 != 0)
        return 0;
    return ((s32 (*)(void *, u32, u32, u32))fn_80006580)((void *)arg0, arg1, arg2, arg3);
}

extern u8 lbl_802FB668[];
void *fn_80007BB0(void) {
    return lbl_802FB668;
}

void fn_80007BBC(void) {
    void **base = (void **)lbl_8055D350;
    if ((*(u32 *)((u8 *)base[2] + 4) & 0x200) == 0) return;
    fn_801B84C0(*(void **)((u8 *)base + 0x1C));
}

extern u8 lbl_802FB630[];
void *fn_80007BDC(void) {
    return lbl_802FB630;
}

void fn_80007BE8(void) {
    return;
}

extern u8 lbl_802FB618[];
void *fn_80007BEC(void) {
    return lbl_802FB618;
}

extern u8 lbl_802FB6D0[];
void *fn_80007BF8(void) {
    return lbl_802FB6D0;
}

extern u8 lbl_802FB604[];
void *fn_80007C04(void) {
    return lbl_802FB604;
}

extern int __cntlzw(unsigned int);
void fn_80007C10(void *arg0) {
    s32 value = fn_801769B8();
    s32 normalized = (u32)__cntlzw(value) >> 5;
    normalized = (u32)__cntlzw(normalized) >> 5;
    ((s8 *)arg0)[4] = (s8)normalized;
    ((s8 *)arg0)[5] = 0;
}

extern s32 fn_801B8848(void);
extern s32 fn_801B87A0(s32, s32);
s32 fn_80007C58(void) {
    return fn_8000C630(0xb, -1);
}

u8 fn_80007C64(void *arg0) {
    return ((u8 *)arg0)[4];
}

void fn_80007C6C(void *arg0) {
    if (fn_801B8848() == 0) {
        ((u8 *)arg0)[5] = 1;
    }
}

s32 fn_80007CA8(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if ((u32)arg2 == 0x3e8) {
        u32 val = (u32)arg3;
        s32 high = val & 0xFFFF;
        return fn_801B87A0((s32)arg1, high);
    }
    return 0;
}

void *fn_80007CC4(void) {
    return lbl_802FB5F0;
}

void fn_80007CD0(void *arg0) {
    ((u8 *)arg0)[4] = 0;
}

u8 fn_80007CDC(void *arg0) {
    return ((u8 *)arg0)[4];
}

s32 fn_80007CE4(void) {
    return fn_8000C630(0xb, -1);
}

void fn_80007CF0(void *arg0) {
    if (fn_801B880C() == 0) {
        ((u8 *)arg0)[4] = 1;
    }
}

s32 fn_80007D2C(void *arg0, void *arg1, s32 arg2, void *arg3) {
    if ((u32)arg2 == 0x3e8) {
        u32 val = (u32)arg3;
        s32 high = val & 0xFFFF;
        return fn_801B87A0((s32)arg1, high);
    }
    return 0;
}

void *fn_80007D48(void) {
    return lbl_802FB5D8;
}

