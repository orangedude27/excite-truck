#include <types.h>

extern void *fn_801284F8(u32, const void *);
extern f32 lbl_8055E0A8;
extern void *lbl_8042F758[]; // 8 "AI::AICarInfo" slots: { s32 carIndex; u8 needsReset; }, built by fn_8013477C
extern void *lbl_8055E0D4;   // global "Proxer" object (fn_80137884/fn_801368F8): +0 car count, +8 pair table, +C entry stride, +10 per-car entries, +14 time
extern f32 lbl_80561304;
extern void *lbl_8055E0B0;
extern f32 lbl_80560108, lbl_8056010C;
extern f64 lbl_80561308, lbl_80561310;
extern void *fn_8001285C(s32);
extern s32 *fn_801E87A8(void);
extern u32 lbl_80559BD8;
extern const char lbl_8032BC84[], lbl_8032BC94[], lbl_8032BCA0[];
extern const char lbl_8032BD08[], lbl_8032BCC0[];
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_801792F8(void);
  extern s32 fn_80134D54(void);
  extern f32 fn_80134D78(void);
  extern f32 fn_80134DF8(void);
  extern s32 fn_801769A8(void);
  extern void *fn_80134E90(void);
      /* fn_80134EC8 takes bits arg; see definition */
  extern void *fn_80134FF8(void);
  extern void *fn_801350C0(void);
  extern void *fn_801A520C(void *, void *);
  extern void *fn_801B83A0(void);
  extern void *fn_801938F4(void *);
  extern void fn_802E30C8(const char *, ...);
  extern const char lbl_8032BC50[];
  extern const char lbl_8032BC5C[];
  
  extern s32 fn_80128668(void);
  extern f32 lbl_805612F4;
  extern f32 lbl_80561318;
  extern const char lbl_8032BD98[];
  extern s32 fn_802E317C(const char *, ...);
  
  // Code of main that had no source file yet: decomp.wtf gave it this one.
  // split_file divides it into the game's real files (file_status shows its range).
  
  extern void *lbl_8055E0AC;
  extern void *fn_8001285C(s32);
  extern s32 *fn_801E87A8(void);
  extern u32 lbl_80559BD8;
void fn_8013471C(void *carInfo, s32 carIndex) {
    /* Initialize an AI::AICarInfo slot: set its car index and flag it for reset. */
    typedef struct {
        s32 carIndex;
        u8 needsReset;
    } AICarInfo;
    AICarInfo *info = (AICarInfo *)carInfo;
    info->carIndex = carIndex;
    info->needsReset = 1;
}
  
#pragma dont_inline fn_8013472C
#pragma push
  #pragma cplusplus on
/* Cache the AI service interface for the current scene in lbl_8055E0AC. */
extern "C" void fn_8013472C(void) {
    struct SceneService {
        virtual void f0();
        virtual void f2();
        virtual void f1();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
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
        virtual void f21();
        virtual void *getService(u32 *);
        virtual void f20();
    };
    register void *service = *(void **)((u8 *)fn_8001285C(*fn_801E87A8()) + 0x20);
    lbl_8055E0AC = ((SceneService *)service)->getService(&lbl_80559BD8);
}
#pragma cplusplus reset
#pragma pop
  #pragma dont_inline __AXDSPInitCallback_80134770
/* DSP init callback: clear the cached AI service interface for the current
 * scene, which fn_8013472C re-fetches via getService. */
void __AXDSPInitCallback_80134770(void) {
    #define s_aiService lbl_8055E0AC
    s_aiService = 0;
    #undef s_aiService
}

extern char lbl_8032BBE8[];
extern f32 lbl_805612E8, lbl_805612EC, lbl_805612F0, lbl_805612F8, lbl_805612FC, lbl_80561300;
extern f32 lbl_8055E0A0, lbl_8055E0A4;
extern f32 fn_80134B58(s32, f32);
extern void fn_8013B4E0(void*, void*);
extern f32 fn_8013672C(void);
extern void fn_80137884(s32);
extern void fn_80139044(void);
extern void fn_8013BAE4(s32);
extern void fn_801663C8(s32, void*, void*);
extern void fn_8013A1E8(void);
extern void fn_8015F554(void);
extern void fn_80160850(void);
#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8013477C(void *arg0) {
    register char *strings = lbl_8032BBE8;
    register unsigned char *entry;
    register void **out;
    register unsigned char *obj = (unsigned char *)arg0 + 0x20;
    register s32 i;
    register s32 count;
    register unsigned char *end;
    void *slot;
    f32 value;
    f32 temp;
    f32 f0;
    f32 f1;
    f32 f2;

#pragma dont_inline on
    fn_8013472C();
#pragma dont_inline reset
    count = *(s32 *)(obj + 0x3C0);
    *(volatile s32 *)&lbl_8055E0B0 = count;
    end = obj + count * 0x78;
#pragma scheduling invalid_target
    while (count > 0 && *(s32 *)(end - 0x78) == 0x53) {
        count--;
        *(volatile s32 *)&lbl_8055E0B0 = count;
        end -= 0x78;
    }
#pragma scheduling on
    fn_8013B4E0(obj, arg0);
    value = fn_80134B58((s32)(strings + 0x0C), lbl_805612F0);
    lbl_8055E0A0 = value;
    if (value < lbl_805612F4) {
        temp = lbl_805612E8 * fn_80134B58((s32)(strings + 0), lbl_805612EC);
        lbl_8055E0A0 = fn_8013672C() - temp;
    }
    f1 = fn_80134B58((s32)(strings + 0x1C), lbl_805612FC);
    f2 = lbl_805612F8;
    fn_802E30C8(strings + 0x28, (lbl_8055E0A8 = f0 = f2 * f1, f0 / f2), f2);
    f1 = fn_8013672C();
    f0 = f1 * lbl_80561300;
    lbl_8055E0A4 = fn_80134B58((s32)(strings + 0x44), f0);
    fn_80137884(*(s32 *)&lbl_8055E0B0);
    fn_801E87A8();
    fn_80139044();
    fn_8013BAE4(*(s32 *)&lbl_8055E0B0);
    fn_801663C8(*(s32 *)&lbl_8055E0B0, obj, (unsigned char *)arg0 + 0x3E4);
#pragma scheduling invalid_target
    entry = obj;
    out = lbl_8042F758;
    i = 0;
    while (i < *(s32 *)(obj + 0x3C0)) {
        if (*(s32 *)entry != 0x53) {
            slot = fn_801284F8(8, strings + 0x58);
            if (slot != 0) {
                *out = ((void *(*)(void *, s32))fn_8013471C)(slot, i);
            }
        }
        entry += 0x78;
        out++;
        i++;
    }
#pragma scheduling on
    fn_8013A1E8();
    fn_8015F554();
    fn_80160850();
}
#pragma use_lmw_stmw reset
#pragma pop
extern void fn_80160AE4(void);
extern void fn_8015F558(void);
extern void fn_8013A1EC(void);
extern void fn_8013B56C(void);
extern void fn_80166814(void);
extern void fn_801378D0(void);
extern void __AXDSPInitCallback_80134770(void);
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_8013490C(void) {
    register void **entries;
    register s32 index;
    register s32 zero;
    void *item;

    /* Shut down AX/DSP-related subsystems, free/clear 8 tracked resource slots in lbl_8042F758, then reset DSP callback/state. */
    fn_80160AE4();
    fn_8015F558();
    fn_8013A1EC();
    fn_8013B56C();
    fn_80166814();
    entries = lbl_8042F758;
    index = 0;
    zero = 0;
    do {
        item = *entries;
        if (item == 0)
            goto skip_clear;
        if (item == 0)
            goto clear_item;
        ((void (*)(void *))fn_80128668)(item);
clear_item:
        *entries = (void *)zero;
skip_clear:
        index++;
        entries++;
    } while (index < 8);
    __AXDSPInitCallback_80134770();
    fn_801378D0();
}
#pragma dont_inline off
#pragma scheduling on

  
/* No-op AI hook: called once per frame from fn_801E7E48; reserved, does nothing. */
void fn_80134994(void) {
}
  
/* Resets the AI subsystem: clears per-car state, reinitializes the AI car-info and
 * proximity tables, then resets the Proxer tracker (the last hook is a no-op). */
void fn_80134998(void) {
    fn_8013BC34();
    fn_80166898();
    fn_80137904();
    fn_8013A1F0();
}

/* Re-arms the AI cars' proximity records after a restart: for each of the eight
 * "AI::AICarInfo" slots in lbl_8042F758 (allocated by fn_8013477C, one per AI car,
 * holding its car/actor index and a reset flag), resets its entry in the global
 * "Proxer" object lbl_8055E0D4 (fn_80136CB8 = fn_80136D20 update + zero its smoothed
 * values), runs the per-car hook fn_8013A200 (an empty stub) and sets the flag so the
 * next flush (fn_80134A8C) re-initializes that car again. */
void fn_801349C4(void) {
    extern void fn_80136CB8(void *, s32);
    extern void fn_8013A200(s32);
    struct AICarInfo { s32 carIndex; u8 needsReset; };
    struct AICarInfo **slots = (struct AICarInfo **)lbl_8042F758;
    struct AICarInfo *carInfo;
    s32 i = 0;
    do {
        carInfo = *slots;
        if (carInfo != 0) {
            fn_80136CB8(lbl_8055E0D4, carInfo->carIndex);
            fn_8013A200(carInfo->carIndex);
            carInfo->needsReset = 1;
        }
        i++;
        slots++;
    } while (i < 8);
}

extern s32 lbl_8055E3C4;
#pragma dont_inline on
s32 fn_80134A44(s32 arg0) {
    if (arg0 == -1) goto tail;
    switch (arg0) {
    case 0:
    case 1:
    case 2:
        return (arg0 + lbl_8055E3C4) & 1;
    default:
        return arg0;
    }
tail:
    return lbl_8055E3C4 & 1;
}
#pragma dont_inline reset

  
  void fn_80134A88(void) {
  
  }

#pragma scheduling invalid_target
/* Flushes per-entry pending changes: for each active entry in the table, applies
 * the enabled/disabled state transition, clears its flag, notifies by value, then
 * finalizes the owner context and runs end-of-frame updates. */
void fn_80134A8C(void) {
    extern void *lbl_8042F758[];
    extern void *lbl_8055E0D4;
    extern void *lbl_8055E0B0;
      extern void fn_80136CB8(void *, s32);
      extern void fn_80136D20(void *, s32);
    extern s32 fn_80134A44(s32);
    extern void fn_801371E0(void *);
    extern void fn_8013A204(s32);
    extern void fn_8013BC54(void);
    extern void fn_80166A24(void);
    struct Entry { s32 value; u8 flag; };
    struct Entry *entry;
    s32 index;
    struct Entry **entries = (struct Entry **)lbl_8042F758;
    for (index = 0; index < *(s32 *)&lbl_8055E0B0; index++) {
        entry = entries[index];
        if (entry != 0) {
            if (entry->flag != 0)
                fn_80136CB8(lbl_8055E0D4, entry->value);
            else
                fn_80136D20(lbl_8055E0D4, entry->value);
            entry->flag = 0;
            fn_8013A204(entry->value);
        }
    }
    if (fn_80134A44(-1) != 0)
        fn_801371E0(lbl_8055E0D4);
    fn_8013BC54();
    fn_80166A24();
}
#pragma scheduling on
  
/* Rebuild the global Proxer proximity tracker: refresh each entry's cached
 * data from its car/actor and recompute all pairwise deltas. */
void fn_80134B50(void) {
    extern void *lbl_8055E0D4;
    extern void fn_80136F08(void *proxer);
    fn_80136F08(lbl_8055E0D4);
}
  
#pragma push
#pragma processor 750
/* Returns the float value for the given config key, or the provided default if the key is absent. */
float fn_80134B58(s32 key, float defaultValue)
{
    extern s32 fn_80134B9C(s32, s32);
    extern double atof(void);
    float value = defaultValue;
    if (fn_80134B9C(key, 0) != 0) {
        value = (float)atof();
    }
    return value;
}
#pragma push
#pragma cplusplus on
extern "C" s32 fn_80134B9C(s32 key, s32 defaultValue) {
    struct Dummy {
        virtual s32 f0();
        virtual s32 f1(s32);
        virtual s32 f2();
        virtual s32 f3(s32);
    };
    s32 result;
    /* Look up key via global interface lbl_8055E0AC (f1 tests, f3 retrieves); return defaultValue if unavailable. */
    if (lbl_8055E0AC != 0 && ((Dummy *)lbl_8055E0AC)->f1(key) != 0) {
        result = ((Dummy *)lbl_8055E0AC)->f3(key);
    } else {
        result = defaultValue;
    }
    return result;
}
#pragma cplusplus reset
#pragma pop
  
/* Returns the global AI rate scale in lbl_8055E0A8, computed from track data
 * during setup (fn_8013477C) and used as a multiplier in AI driver math
 * (fn_80134E34, fn_80194C4C). */
f32 fn_80134C1C(void) {
    return lbl_8055E0A8;
}
  
s32 fn_80134C24(s32 playerIndex) {
    extern void *fn_8017960C(void);
    /* Return the label value from player slot 0-7, or -1 when the slot is out of range. */
    if (playerIndex >= 0 && playerIndex < 8)
        return *(s32 *)((char *)fn_8017960C() + 0x258);
    return -1;
}
  
s32 fn_80134C60(s32 value, char *dst)
{
    /* Format a "#"-prefixed label into dst: "#%3d" for a nonnegative value,
     * "#GST" for -20, "#---" for any other negative value; return dst. */
    extern s32 sprintf(char *, const char *, ...);
    extern char *strcpy(char *, const char *);
    extern u8 lbl_80559BDC, lbl_80559BE4, lbl_80559BEC;
#define FMT_HASH_NUMBER lbl_80559BDC
#define STR_HASH_GST    lbl_80559BE4
#define STR_HASH_DASHES lbl_80559BEC
    if (value >= 0) {
        sprintf(dst, (const char *)&FMT_HASH_NUMBER, value);
    } else {
        switch (value) {
        case -0x14:
            strcpy(dst, (const char *)&STR_HASH_GST);
            break;
        default:
            strcpy(dst, (const char *)&STR_HASH_DASHES);
            break;
        }
    }
#undef FMT_HASH_NUMBER
#undef STR_HASH_GST
#undef STR_HASH_DASHES
    return (s32)dst;
}
  
#pragma dont_inline on
s32 fn_80134CD4(s32 arg0, s32 arg1) {
    /* Format a slot/index-based text value into arg1 buffer and return it. */
    extern s32 fn_80134C60(s32, char *);
    s32 result;
    if (arg0 >= 0) {
        result = fn_80134C24(arg0);
        fn_80134C60(result, (char *)arg1);
    } else {
        fn_80134C60(-0x28, (char *)arg1);
    }
    return arg1;
}
#pragma dont_inline reset
/* Pick the AI-driver base amount consumed by fn_80134E34: the alternate value
 * when physics flag 0x800 is set, otherwise the normal value. Both floats are
 * computed in fn_8013477C when the driver is initialized. */
f32 fn_80134D20(void) {
    extern f32 lbl_8055E0A0;
    extern f32 lbl_8055E0A4;
#define AI_BASE_NORMAL lbl_8055E0A0
#define AI_BASE_ALT    lbl_8055E0A4
    if (fn_801769A8() & 0x800) {
        return AI_BASE_ALT;
    }
    return AI_BASE_NORMAL;
#undef AI_BASE_ALT
#undef AI_BASE_NORMAL
}
  
/* Report extra layout units: this build always answers 0; the config word read via fn_801769A8 is ignored. */
s32 fn_80134D54(void) {
    fn_801769A8();
    return 0;
}

/* Number of AI cars in the fn_8013477C table (lbl_8042F758); kept in sync by fn_8013477C. */
#define AI_CAR_COUNT ((s32)lbl_8055E0B0)
/* Layout steps of fn_80134D78 / fn_80134DF8; every one of them holds 4.0f in this build. */
#define LAYOUT_BASE  lbl_80561304 /* the list's own share */
#define LAYOUT_EXTRA lbl_80560108 /* per unit answered by fn_80134D54 */
#define LAYOUT_PAIR  lbl_8056010C /* per pair of AI cars */

#pragma dont_inline on
/* Fallback list length for fn_80134E00 (taken when the physics command carries flag 0x100):
   LAYOUT_BASE + LAYOUT_EXTRA * fn_80134D54() + LAYOUT_PAIR * ((carCount + 1) / 2), i.e. one
   share for the list itself plus one for every pair of AI cars.  fn_80134D54 always answers 0,
   and the two integer->float conversions go through the 2^52 / 2^52+2^31 magic doubles. */
f32 fn_80134D78(void) {
    unsigned long countPlusOne;
    s32 carPairs;
    f32 extra;
    extra = (f32)((u32 (*)(void))fn_80134D54)();
    countPlusOne = AI_CAR_COUNT + 1;
    carPairs = (s32)(((u32)countPlusOne >> 31) + countPlusOne) >> 1;
    return LAYOUT_BASE + (LAYOUT_EXTRA * extra) + ((f32)carPairs * LAYOUT_PAIR);
}
#pragma dont_inline reset

#pragma dont_inline on
/* Fixed AI list length used by fn_80134E00's non-flag path: just the list's
 * own layout share (LAYOUT_BASE = 4.0f). Kept non-inlined for the direct call. */
f32 fn_80134DF8(void) {
    return LAYOUT_BASE;
}
#pragma dont_inline reset

/* Pick the list length used by fn_80134E34: when the physics command's 0x100 flag is set,
   use the computed fallback length (fn_80134D78), otherwise the fixed base (fn_80134DF8). */
f32 fn_80134E00(void) {
    if ((fn_801769A8() >> 8) & 1) {
        return fn_80134D78();
    }
    return fn_80134DF8();
}

extern f32 fn_80134C1C(void);
extern f32 fn_80134D20(void);
extern f32 fn_80134E00(void);
#pragma dont_inline on
extern void *lbl_8055E0B0;
extern f32 lbl_80560108;
extern f32 lbl_8056010C;
extern f32 lbl_80561304;
extern f64 lbl_80561308;
extern f64 lbl_80561310;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
f32 fn_80134E34(f32 value) {
    /* Compute a base amount minus value scaled by a rate; uses a fallback value when below zero. */
    f32 clampedValue;
    f32 rate;
    if (value < lbl_805612F4) {
        clampedValue = fn_80134E00();
    } else {
        clampedValue = value;
    }
    rate = fn_80134C1C();
    return fn_80134D20() - clampedValue * rate;
}
#pragma scheduling on
#pragma pop
void *fn_80134E90(void) {
    /* Allocates a 0x30C-byte "AIDriver" object, initializes it, and returns it (0 if allocation fails). */
    void *driver = fn_801284F8(0x30C, lbl_8032BC50);
    if (driver != 0) {
        driver = fn_801938F4(driver);
    }
    return driver;
}

#pragma push
#pragma cplusplus on
extern "C" void *fn_80134EC8(s32 arenaType)
{
    /* Get an arena/driver object for arenaType: query current provider's slot 57,
       return its result if nonzero; otherwise handle 0x180201 or warn and return default. */
    struct ArenaProviderVTable {
        virtual void vfunc0();
        virtual void vfunc1();
        virtual void vfunc2();
        virtual void vfunc3();
        virtual void vfunc4();
        virtual void vfunc5();
        virtual void vfunc6();
        virtual void vfunc7();
        virtual void vfunc8();
        virtual void vfunc9();
        virtual void vfunc10();
        virtual void vfunc11();
        virtual void vfunc12();
        virtual void vfunc13();
        virtual void vfunc14();
        virtual void vfunc15();
        virtual void vfunc16();
        virtual void vfunc17();
        virtual void vfunc18();
        virtual void vfunc19();
        virtual void vfunc20();
        virtual void vfunc21();
        virtual void vfunc22();
        virtual void vfunc23();
        virtual void vfunc24();
        virtual void vfunc25();
        virtual void vfunc26();
        virtual void vfunc27();
        virtual void vfunc28();
        virtual void vfunc29();
        virtual void vfunc30();
        virtual void vfunc31();
        virtual void vfunc32();
        virtual void vfunc33();
        virtual void vfunc34();
        virtual void vfunc35();
        virtual void vfunc36();
        virtual void vfunc37();
        virtual void vfunc38();
        virtual void vfunc39();
        virtual void vfunc40();
        virtual void vfunc41();
        virtual void vfunc42();
        virtual void vfunc43();
        virtual void vfunc44();
        virtual void vfunc45();
        virtual void vfunc46();
        virtual void vfunc47();
        virtual void vfunc48();
        virtual void vfunc49();
        virtual void vfunc50();
        virtual void vfunc51();
        virtual void vfunc52();
        virtual void vfunc53();
        virtual void vfunc54();
        virtual void vfunc55();
        virtual void vfunc56();
        virtual s32 GetArenaDriver();
    };
    void *provider = fn_801B83A0();
    s32 driver = ((ArenaProviderVTable *)provider)->GetArenaDriver();
    if (driver == 0) {
        switch (arenaType) {
        case 0x180201:
            return fn_80134E90();
        default:
            fn_802E30C8(lbl_8032BC5C, (void *)arenaType);
            return fn_80134FF8();
        }
    }
    return (void *)driver;
}
#pragma cplusplus reset
#pragma pop
/* No-op stub: always returns 0. */
s32 fn_80134F40(void) {
    return 0;
}

// Select an AX/effect factory implementation from global state/config, then allocate and construct an object with it.
void *fn_80134F48(void) {
    void *factory = __AXFXGetLfoSinTable_801769CC();
    s32 useAltFactory = 0;
    void *result;
    u32 bits;
    if (*((u8*)fn_801792F8() + 0xD8) & 4) useAltFactory = 1;
    if (useAltFactory) factory = fn_801350C0();
    else {
        bits = *((u32*)factory + 1);
        if (bits & 0x100) factory = fn_80134E90();
        else if (bits & 0x200) factory = ((void *(*)(s32))fn_80134EC8)(bits);
        else factory = fn_80134FF8();
    }
    {
        register const void *name = lbl_8032BC84;
        register u32 id = 0x2844;
        result = fn_801284F8(id, name);
    }
    if (result != 0) result = fn_801A520C(result, factory);
    return result;
}
#pragma scheduling invalid_target
void *fn_80134FF8(void) {
    void **object = fn_801284F8(4, lbl_8032BC94);
    /* Allocate a NullDriver instance and point it at its vtable. */
    if (object != 0) {
        *object = (void *)lbl_8032BD08;
    }
    return object;
}
#pragma scheduling on
s32 fn_80135038(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void *fn_80135078(void) {
    /* Construct a 0xC-byte ParkDriver object: allocate, set vtable lbl_8032BCC0, clear flag at +4. */
#define kParkDriverClassName lbl_8032BCA0 /* "ParkDriver" */
#define kParkDriverVTable lbl_8032BCC0
    void *p = fn_801284F8(12, kParkDriverClassName);
    if (p != 0) {
        *(const void**)p = kParkDriverVTable;
        *((u8*)p + 4) = 0;
    }
    return p;
#undef kParkDriverClassName
#undef kParkDriverVTable
}

void *fn_801350C0(void) {
    /* Construct a 0xC-byte ParkDriver object: allocate, set vtable lbl_8032BCC0, set flag at +4. */
#define kParkDriverClassName lbl_8032BCA0 /* "ParkDriver" */
#define kParkDriverVTable lbl_8032BCC0
    void *p = fn_801284F8(12, kParkDriverClassName);
    if (p != 0) {
        *(const void**)p = kParkDriverVTable;
        *((u8*)p + 4) = 1;
    }
    return p;
#undef kParkDriverClassName
#undef kParkDriverVTable
}

void* fn_80135108(void) {
    /* Return the number of AI cars in the fn_8013477C table (global AI_CAR_COUNT
     * / lbl_8055E0B0), kept in sync as cars are added. */
    return lbl_8055E0B0;
}

s32 fn_80135110(s32 ptr, s32 count) {
    /* Free ptr via the mode-3 pool allocator when it is non-null and count is positive; return ptr unchanged. */
    if (ptr != 0 && count > 0) {
        fn_80128668();
    }
    return ptr;
}

s32 fn_80135150(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_80135190(void) {

}

void fn_80135194(void) {

}

void fn_80135198(void) {

}

#pragma scheduling invalid_target
int fn_8013519C(void) {
#define kSetCarNotOverriddenMsg lbl_8032BD98
    /* Panic with the message that the idriver SetCar callback is not overridden. */
    return fn_802E317C(kSetCarNotOverriddenMsg);
#undef kSetCarNotOverriddenMsg
}
extern const char lbl_8032BD98[];
extern s32 fn_802E317C(const char *, ...);
/* Null-driver default for this driver-interface virtual (vtable slot +0x14): reports no capability flags, i.e. 0. */
s32 fn_801351AC(void) {
    return 0;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801351B4(void* obj) {
    /* C-linkage adapter: dispatch virtual slot f2 (vtable offset 0x10) on obj. */
    struct VtableInterface {
        virtual void f0();
        virtual void f1();
        virtual void f2();
    };
    ((VtableInterface*)obj)->f2();
}
#pragma cplusplus reset
#pragma pop
/* Stores the truck/car handle at offset +8 of the AI driver object. */
void fn_801351C4(void *driver, s32 truck) {
    ((s32 *)driver)[2] = truck;
}

extern void fn_8018ADBC(void *, f32);
extern void fn_8018ADB4(void *, f32);
extern void fn_8018ADA4(void *, f32);
#pragma push
#pragma processor 750
#pragma peephole off
#pragma scheduling invalid_target
void fn_801351CC(void *arg0) {
    f32 first = *(volatile f32 *)&lbl_80561318;
    fn_8018ADBC(*(void **)((u8 *)arg0 + 8), first);
    fn_8018ADB4(*(void **)((u8 *)arg0 + 8), lbl_805612F4);
    fn_8018ADA4(*(void **)((u8 *)arg0 + 8), lbl_805612F4);
}
#pragma pop
void fn_80135218(void) {

}


s32 fn_8013521C(void *object) {
    u8 flag;
    /* Branchless test: returns 0x100 when the byte flag at +0x4 of object is nonzero, else 0. */
    flag = *(u8 *)((u8 *)object + 4);
    return ((s32)(-(s32)flag | flag) >> 0x1F) & 0x100;
}

/* Default/stub implementation: reports no result (zero). */
s32 fn_80135234(void) {
    return 0;
}

/* Default/stub implementation: zero both output values (no results to report). */
void fn_8013523C(void *arg0, void *arg1, void *arg2, s32 *outA, s32 *outB) {
    *outB = 0;
    *outA = 0;
}

/* Default/stub implementation: reports no result (zero). */
s32 fn_8013524C(void) {
    return 0;
}

void fn_80135254(void) {

}

void fn_80135258(void) {

}

void fn_8013525C(void) {

}

void fn_80135260(void) {

}

void fn_80135264(void) {

}

void fn_80135268(void) {

}

void fn_8013526C(void) {

}

