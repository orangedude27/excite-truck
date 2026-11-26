// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void fn_80012158(void);
extern s32 fn_80161C38(void);
extern s32 fn_8000C848(s32);

extern void fn_8000C964(void);
extern void fn_8000CD24(void);
extern u32 fn_8000C7F4(s32);
extern s32 fn_8000C840(void);
extern char lbl_80558A7C[];
extern void fn_80230B5C(void *);
extern void DrawList_loadMatrix(void *);
extern void fn_802C974C(f32, f32, f32);
extern void fn_800109E4(s32, f32, f32, f32, f32);
extern void fn_801345D8(void *, s32, const char *, ...);
extern void fn_80147230(void *, const char *, ...);
extern void fn_801473F8(void *, const char *, ...);
extern void fn_80147940(void *, void *, const char *, s32, ...);
extern void fn_80230F78(u8 *, f32 *, u32 *, s32);
extern void fn_802C9904(void);
extern const char lbl_80558A74[];
extern s32 lbl_80560210, lbl_80560214;
extern f32 lbl_8056021C, lbl_80560220, lbl_80560224, lbl_80560228;
extern f32 lbl_8056022C, lbl_80560230, lbl_80560234, lbl_80560238;

extern const char lbl_80558A70[];
extern s32 fn_80131234(s32);
extern void fn_801476C4(void);
extern void fn_80011A2C(void);

extern s32 lbl_8055D400;
extern u8 lbl_8055D404;
extern u8 lbl_8055D405;
extern u8 lbl_8055D406;
extern u8 lbl_8055D407;
extern s32 lbl_8055D408;
extern s32 lbl_8055D40C;
extern s32 lbl_8055D420;
extern void **lbl_8055D414;
extern void **lbl_8055D418;
extern void **lbl_8055D41C;
extern s32 lbl_8055D410;

void fn_802066C8(void*, u32);
void fn_80128668(void*);
s32 fn_8000CCB8(void);
void fn_80209110(s32);

// Externs for fn_8000CE60
extern u8 lbl_802FC058[];
extern s32 fn_802090D4(void*);
extern void fn_80209190(f32);
extern s32 fn_80145E70(void*);
extern s32 fn_80207848(void*, s32);
extern f32 lbl_80560218;

// Externs for fn_8000D070, fn_8000D100
extern f32 fn_80209028(void);
extern s32 fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80206444(void);
extern void fn_80230E90(s32);
extern f32 lbl_80560234;

// Externs for fn_8000D100
extern char lbl_802FC1CC[];
extern void fn_80206454(void);
extern void fn_802E30C8(const char*, ...);
extern void Sound_start(void);

// Externs for fn_8000CCB8
extern s32 fn_800075A0(s32);
extern u32 __AXGetStackHead_80137CFC(s32);
extern s32 RjoyIsPadConnected(void);
extern s32 fn_80137C74(void);

s32 fn_8000CFA8(s32 object, s32 shouldDelete) {
    /* Destroys an object and optionally deletes it. */
    if (object != 0) {
        fn_802066C8((void*)object, 0);
        if (shouldDelete > 0) {
            fn_80128668((void*)object);
        }
    }
    return object;
}

#pragma scheduling invalid_target
void fn_8000D000(s32 paramA, s32 paramB, s32 paramC) {
    /* InitAudioState: store initial audio params, set active flags, and cache free audio slot. */
#define sAudioParamA lbl_8055D408
#define sAudioActiveFlag lbl_8055D404
#define sAudioFlagB lbl_8055D405
#define sAudioFlagC lbl_8055D406
#define sAudioFlagD lbl_8055D407
#define sAudioParamB lbl_8055D40C
#define sAudioParamC lbl_8055D400
#define sAudioSlot lbl_8055D420
#define FindFreeAudioSlot fn_8000CCB8
    sAudioParamA = paramA;
    sAudioActiveFlag = 1;
    sAudioFlagB = 0;
    sAudioFlagC = 0;
    sAudioFlagD = 0;
    sAudioParamB = paramB;
    sAudioParamC = paramC;
    sAudioSlot = FindFreeAudioSlot();
#undef sAudioParamA
#undef sAudioActiveFlag
#undef sAudioFlagB
#undef sAudioFlagC
#undef sAudioFlagD
#undef sAudioParamB
#undef sAudioParamC
#undef sAudioSlot
#undef FindFreeAudioSlot
}
void fn_8000D000(s32, s32, s32);
#define sAudioFlagD lbl_8055D407
void fn_8000D048(void) {
    /* Initialize the audio state, then set audio flag D active. */
    ((void (*)(void))fn_8000D000)();
    sAudioFlagD = 1;
}
#undef sAudioFlagD

void fn_8000CE60(void) {
    /* Initialize pause/menu UI state and create its mixer, layout and sound resources. */
    volatile u8 *activeFlag = &lbl_8055D404;

    *activeFlag = 0;
    lbl_8055D405 = 0;
    lbl_8055D407 = 0;
    lbl_8055D400 = 0;
    lbl_8055D408 = 0;
    lbl_8055D40C = 0;
    lbl_8055D410 = fn_802090D4((void*)(lbl_802FC058 + 0x140));
    fn_80209190(lbl_80560218);
    lbl_8055D414 = (void**)fn_80145E70((void*)(lbl_802FC058 + 0x14C));
    lbl_8055D418 = (void**)fn_80207848((void*)(lbl_802FC058 + 0x158), 0);
    lbl_8055D41C = (void**)fn_80207848((void*)(lbl_802FC058 + 0x164), 0);
    lbl_8055D420 = -1;
}

#pragma cplusplus on
extern "C" void fn_8000CEF0(void) {
    /* Release owned UI objects/resources and reset associated state flags. */
    class Object {
    public:
        virtual void release(s32);
    };
    Object *p;

    p = (Object *)lbl_8055D418;
    if (p != NULL) {
        if (p != NULL)
            p->release(1);
        lbl_8055D418 = NULL;
    }
    p = (Object *)lbl_8055D41C;
    if (p != NULL) {
        if (p != NULL)
            p->release(1);
        lbl_8055D41C = NULL;
    }
    p = (Object *)lbl_8055D414;
    if (p != NULL) {
        if (p != NULL)
            p->release(1);
        lbl_8055D414 = NULL;
    }
    fn_80209110((s32)&lbl_8055D410);
    lbl_8055D404 = 0;
    lbl_8055D405 = 0;
    lbl_8055D407 = 0;
}
#pragma cplusplus off
void fn_8000D070(void) {
    /* Update active audio/UI state object if present, run init/update hooks, reset a flag, apply mixer volume, and enable some mode. */
    u8 *state;

    if (lbl_8055D418 != NULL) {
        f32 value = fn_80209028();
        f32 *valuePtr = (f32 *)((u8 *)lbl_8055D418 + 8);
        if (value != *valuePtr) {
            *(u8 *)((u8 *)lbl_8055D418 + 0x4D) = 1;
            *valuePtr = value;
        }
        state = (u8 *)lbl_8055D418;
        state[0x49] = 1;
        state[0x4B] = 0;
        state[0x4A] = 0;
    }

    if (fn_80265D64() == 0) {
        __AXDSPInitCallback_801769E0();
    }

    fn_80206444();
    lbl_8055D400 = 0;
    ((void (*)(s32, f32))fn_80209190)(lbl_8055D410, lbl_80560234);
    fn_80230E90(1);
}

#pragma scheduling invalid_target
void fn_8000D100(void) {
    /* Update the active UI/audio object, refresh mixer volume, then handle leave/escape flow. */
    u8 *obj;
    if (lbl_8055D41C != NULL) {
        f32 volume = fn_80209028();
        f32 *volumePtr = (f32*)((u8*)lbl_8055D41C + 8);
        if (volume != *volumePtr) {
            *(u8*)((u8*)lbl_8055D41C + 0x4D) = 1;
            *volumePtr = volume;
        }
        obj = (u8*)lbl_8055D41C;
        obj[0x49] = 1;
        obj[0x4B] = 0;
        obj[0x4A] = 0;
    }
    ((void (*)(s32, f32))fn_80209190)(lbl_8055D410, lbl_80560218);
    fn_80206454();
    if (lbl_8055D404 != 0) {
        fn_802E30C8(lbl_802FC1CC);
        lbl_8055D404 = 0;
        return;
    }
    Sound_start();
}
void fn_8000D19C(void) {
    /* Update the cached audio slot while the audio flag is set; clear it if no slot is available. */
#define sAudioFlagD lbl_8055D407
#define sAudioSlot lbl_8055D420
#define FindFreeAudioSlot fn_8000CCB8
    if (sAudioFlagD != 0) {
        sAudioSlot = FindFreeAudioSlot();
        if (sAudioSlot == -1) {
            sAudioFlagD = 0;
        }
    }
#undef sAudioFlagD
#undef sAudioSlot
#undef FindFreeAudioSlot
}

#pragma cplusplus on
__declspec(section ".sdata") extern const char lbl_80558A70[];
__declspec(section ".sdata") extern const char lbl_80558A74[];
__declspec(section ".sdata") extern char lbl_80558A7C[];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_propagation off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
extern "C" void fn_8000D1DC(void) {
    struct Dummy { public: virtual void *f2(); virtual s32 *get3(const char *); virtual void *f4(); virtual s32 *get5(const char *); };
    struct Info { u32 a, b, c, d; f32 e; u32 f, g, h; };
    struct Update { u32 value, x, y, flags; f32 z, w; u32 color; };
    f32 matrix[12];
    char name0[0x20], name1[0x20];
    struct Info item;
    struct Update out;
    u8 alpha;
    f32 temp_f0;
    f32 baseVal, scale, factor, selectedVal;
    f32 temp_f1, temp_f1_2, temp_f2, temp_f3, temp_f4, temp_f5, temp_f7;
    s32 temp_r8;
    register s32 i, selected;
    register u8 *base = lbl_802FC058;
    register s32 *obj;
    if (lbl_8055D405 != 0) {
        fn_8000C964();
        goto done;
    }
    if (lbl_8055D40C != 0) {
        ((void (*)(void))(u32)lbl_8055D40C)();
    }
    fn_80230B5C(matrix);
    DrawList_loadMatrix(matrix);
    fn_802C974C(lbl_80560218, lbl_8056021C, lbl_80560220);
    fn_800109E4(0x7F000000, lbl_80560224, lbl_80560228, lbl_8056022C, lbl_80560230);
    if (lbl_8055D407 != 0) {
        fn_8000CD24();
        goto done;
    }
    if (lbl_8055D414 != 0) {
        fn_801473F8(lbl_8055D414, lbl_80558A7C, lbl_80558A70, fn_80131234((s32)(base + 0x198)));
        factor = lbl_80560234;
        scale = lbl_80560238;
        i = 0;
        baseVal = lbl_80560218;
        do {
            if (fn_8000C7F4(i) != 0) {
                fn_801345D8(name0, 0x20, (const char *)base + 0x94, i);
                fn_801345D8(name1, 0x20, lbl_80558A74, i);
                selected = (i == lbl_8055D400);
                obj = ((Dummy *)lbl_8055D414)->get3(name1);
                item.a = obj[0]; item.b = obj[1]; item.c = obj[2]; item.d = obj[3];
                item.e = ((f32 *)obj)[4];
                item.f = obj[5]; item.g = obj[6]; item.h = obj[7];
                alpha = 0xFF;
                selectedVal = factor;
                if (selected != 0) fn_80230F78(&alpha, &selectedVal, &item.g, 1);
                if (((s32 (*)(s32))fn_8000C840)(i) == 0) item.g = (item.g & 0xFFFFFF) | 0x80000000;
                obj = ((Dummy *)lbl_8055D414)->get5(name0);
                if (obj != 0) {
                    if (((s32 (*)(s32))fn_8000C840)(i) == 0) obj[6] = (obj[6] & 0xFFFFFF) | 0x80000000;
                    ((void (*)(void *, void *, const char *, s32))fn_80147940)(lbl_8055D414, obj, (const char *)base + 0xA4, ((-selected | selected) >> 31) + 2);
                    if (selected != 0) {
                        out.value = obj[0]; out.x = obj[1]; out.y = obj[2]; out.flags = obj[3]; out.z = ((f32 *)obj)[4]; out.w = ((f32 *)obj)[5];
                        temp_f0 = baseVal + selectedVal;
                        temp_f2 = *(f32 *)&out.y;
                        temp_f1 = out.z;
                        temp_f7 = out.w;
                        temp_f5 = scale * temp_f1 * selectedVal;
                        temp_r8 = obj[6];
                        temp_f4 = *(f32 *)&out.x - temp_f5;
                        temp_f3 = scale * temp_f7 * selectedVal;
                        out.z = temp_f1 * temp_f0;
                        temp_f1_2 = temp_f2 - temp_f3;
                        *(f32 *)&out.x = temp_f4;
                        *(f32 *)&out.y = temp_f1_2;
                        out.w = temp_f7 * temp_f0;
                        out.color = (temp_r8 & 0x00FF0000) | ((u32)alpha << 24) | (temp_r8 & 0xFFFF);
                        ((void (*)(void *, void *, const char *, s32, u8, s32, f32, f32, f32, f32, f32, f32, f32))fn_80147940)(
                            lbl_8055D414, &out, (const char *)base + 0xA4, 1, alpha, temp_r8,
                            temp_f1_2, temp_f2, temp_f3, temp_f4, temp_f5, selectedVal, temp_f7);
                    }
                }
                fn_80147230(&item, lbl_80558A70, (const char *)fn_80131234(*(s32 *)(base + 0x40 + i * 4)));
            }
            ++i;
        } while (i < 4);
        ((Dummy *)lbl_8055D414)->get3((const char *)base + 0xB0);
        fn_801476C4();
        ((Dummy *)lbl_8055D414)->get3((const char *)base + 0xC0);
        fn_801476C4();
    }
done:
    fn_80011A2C();
    fn_802C9904();
}
#pragma pop
extern "C" s32 fn_8000D540(s32 input) {
    /* Handle menu/controller input: dispatch to alternate handler when active,
       cycle/select the current slot for navigation keys, and run the confirm callback. */
    if (lbl_8055D405 != 0) {
        return fn_8000C848(input);
    }
    if (lbl_8055D407 != 0) {
        return 0;
    }
    switch (input) {
    case 0x1B:
        lbl_8055D404 = 0;
        if (((s32 (*)(s32))lbl_8055D408)(0) == 0) {
            lbl_8055D404 = 1;
        }
        break;
    case 0x126:
        lbl_8055D400 = (lbl_8055D400 + 3) % 4;
        while (fn_8000C7F4(lbl_8055D400) == 0 || ((s32 (*)(s32))fn_8000C840)(lbl_8055D400) == 0) {
            lbl_8055D400 = (lbl_8055D400 + 3) % 4;
        }
        fn_80230E90(1);
        break;
    case 0x128:
        lbl_8055D400 = (lbl_8055D400 + 1) % 4;
        while (fn_8000C7F4(lbl_8055D400) == 0 || ((s32 (*)(s32))fn_8000C840)(lbl_8055D400) == 0) {
            lbl_8055D400 = (lbl_8055D400 + 1) % 4;
        }
        fn_80230E90(1);
        break;
    case 0x53:
        lbl_8055D400 = 0;
    case 0x58:
    case 0xD:
        if (lbl_8055D400 == 3 && fn_80161C38() == 0) {
            lbl_8055D405 = 1;
            lbl_8055D406 = 0;
        } else if (((s32 (*)(s32))fn_8000C840)(lbl_8055D400) != 0) {
            lbl_8055D404 = 0;
            if (((s32 (*)(s32))lbl_8055D408)(lbl_8055D400) == 0) {
                lbl_8055D404 = 1;
            }
        }
        break;
    default:
        return 0;
    }
    fn_80012158();
    return 1;
}

#pragma cplusplus reset
u8 Sound_isActive(void) {
    /* Return the global audio-active flag (1 while audio is running). */
#define sAudioActiveFlag lbl_8055D404
    return sAudioActiveFlag;
#undef sAudioActiveFlag
}

s32 fn_8000D764(void) {
    /* Return a free audio slot index, or -1 when audio is already active. */
    if (lbl_8055D404 != 0) {
        return -1;
    }
    return fn_8000CCB8();
}

extern s32 fn_80019BA8(void);
/* Return 1 when boot option bit 0x400 (lbl_8055D5A0 bit 10) is clear. */
s32 fn_8000C7CC(void) {
    return fn_80019BA8() == 0;
}

#pragma dont_inline on
#pragma scheduling invalid_target
u32 fn_8000C7F4(s32 slot) {
    /* Whether the menu may offer the queried slot (the four slots are drawn and
     * cycled through with this test, and fn_8000C840's own check).  With the
     * usual boot option -- bit 0x400 clear, which fn_8000C7CC reports as 1 --
     * every slot is offered.  With that option set, slot 2 is hidden: the
     * (2-slot)|(slot-2) pair is zero only for slot 2, so its sign bit shifted
     * down gives 0 there and 1 for every other slot. */
#define BootOptionOffersAllSlots fn_8000C7CC /* 1 when boot option bit 0x400 is clear */
#define HiddenSlot 2

    switch (BootOptionOffersAllSlots()) {
        case 0:
            break;
        default:
            return 1;
    }
    return (u32)((HiddenSlot - slot) | (slot - HiddenSlot)) >> 31;
#undef BootOptionOffersAllSlots
#undef HiddenSlot
}
#pragma scheduling on
#pragma dont_inline off
/* Slot-availability predicate for the menu: always reports the queried slot as enabled (nonzero). */
s32 fn_8000C840(void) {
    return 1;
}

s32 fn_8000C848(s32 messageId) {
    /* Handle UI/input state messages: toggle or clear state flags, invoke the state callback when enabled, then refresh; returns 1 if handled. */
    switch (messageId) {
    case 0x126:
        if (lbl_8055D406 == 0) { lbl_8055D406 = 1; fn_80230E90(1); }
        goto done;
    case 0x128:
        if (lbl_8055D406 != 0) { lbl_8055D406 = 0; fn_80230E90(1); }
        goto done;
    case 0x1B:
    case 0x53:
        lbl_8055D406 = 0;
    case 0x58:
    case 0xD:
        if (lbl_8055D406 != 0) {
            if (((s32 (*)(s32))fn_8000C840)(lbl_8055D400) != 0) {
                lbl_8055D404 = 0;
                if (((s32 (*)(s32))lbl_8055D408)(lbl_8055D400) == 0) lbl_8055D404 = 1;
            }
        } else lbl_8055D405 = 0;
        goto done;
    default:
        return 0;
    }
done:
    fn_80012158();
    return 1;
}

extern void fn_80230B5C(void *);
extern void DrawList_loadMatrix(void *);
extern void fn_802C974C(f32, f32, f32);
extern void fn_800109E4(s32, f32, f32, f32, f32);
extern void fn_801345D8(void *, s32, const char *, ...);
extern void fn_80147230(void *, const char *, ...);
extern void fn_801473F8(void *, const char *, ...);
extern void fn_80147940(void *, void *, const char *, s32, ...);
extern void fn_80230F78(u8 *, f32 *, u32 *, s32);
extern void fn_802C9904(void);
extern const char lbl_80558A74[];
extern s32 lbl_80560210, lbl_80560214;
extern f32 lbl_8056021C, lbl_80560220, lbl_80560224, lbl_80560228;
extern f32 lbl_8056022C, lbl_80560230, lbl_80560234, lbl_80560238;
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_8000C964(void) {
class Dummy { public: virtual void *f2(); virtual s32 *get3(const char *); virtual void *f4(); virtual s32 *get5(const char *); };
struct Info { u32 a, b, c, d; f32 e; u32 f, g, h; };
struct Update { u32 value, x, y, flags; f32 z, w; u32 color; };
struct Base { u8 pad[0x40]; s32 entry[1]; };
f32 matrix[12];
char name0[0x20], name1[0x20];
struct Info item;
struct Update out;
s32 labels[2];
u8 alpha;
f32 baseVal, scale, factor, selectedVal;
f32 temp_f0, temp_f1, temp_f1_2, temp_f2, temp_f3, temp_f4, temp_f5, temp_f7;
s32 temp_r8, drawMode;
register int addr;
register u8 *base = lbl_802FC058;
register s32 *labelp;
register s32 i, selected;
register s32 *obj;
fn_80230B5C(matrix);
DrawList_loadMatrix(matrix);
fn_802C974C(lbl_80560218, lbl_8056021C, lbl_80560220);
fn_800109E4(0x7F000000, lbl_80560224, lbl_80560228, lbl_8056022C, lbl_80560230);
if (lbl_8055D414 != 0) {
labels[0] = lbl_80560210;
labels[1] = lbl_80560214;
fn_801473F8(lbl_8055D414, (const char *)base + 0x68, lbl_80558A70, fn_80131234(((Base *)base)->entry[lbl_8055D400]));
fn_801473F8(lbl_8055D414, (const char *)base + 0x78, lbl_80558A70, fn_80131234((s32)(base + 0x84)));
factor = lbl_80560234;
labelp = labels;
scale = lbl_80560238;
i = 0;
baseVal = lbl_80560218;
do {
addr = (int)lbl_802FC058;
fn_801345D8(name0, 0x20, (char *)(addr + 0x94), i + 1);
fn_801345D8(name1, 0x20, lbl_80558A74, i + 1);
obj = ((Dummy *)lbl_8055D414)->get3(name1);
selected = 0;
item.a = obj[0]; item.b = obj[1]; item.c = obj[2]; item.d = obj[3];
item.e = ((f32 *)obj)[4];
item.f = obj[5]; item.g = obj[6]; item.h = obj[7];
alpha = 0xFF;
selectedVal = factor;
if ((i == 0 && lbl_8055D406 != 0) || (i == 1 && lbl_8055D406 == 0)) selected = 1;
if (selected != 0) fn_80230F78(&alpha, &selectedVal, &item.g, 1);
obj = ((Dummy *)lbl_8055D414)->get5(name0);
if (obj != 0) {
if (((s32 (*)(s32))fn_8000C840)(i) == 0) obj[6] = (obj[6] & 0xFFFFFF) | 0x80000000;
drawMode = ((-selected | selected) >> 31) + 2;
addr = (int)lbl_802FC058;
((void (*)(void *, void *, const char *, s32))fn_80147940)(lbl_8055D414, obj, (char *)(addr + 0xA4), drawMode);
if (selected != 0) {
out.value = obj[0]; out.x = obj[1]; out.y = obj[2]; out.flags = obj[3]; out.z = ((f32 *)obj)[4];
temp_f0 = baseVal + selectedVal;
temp_f2 = *(f32 *)&out.y;
temp_f1 = out.z;
temp_f7 = ((f32 *)obj)[5];
temp_f5 = scale * temp_f1 * selectedVal;
temp_r8 = obj[6];
temp_f4 = *(f32 *)&out.x - temp_f5;
temp_f3 = scale * temp_f7 * selectedVal;
out.z = temp_f1 * temp_f0;
temp_f1_2 = temp_f2 - temp_f3;
*(f32 *)&out.x = temp_f4;
*(f32 *)&out.y = temp_f1_2;
out.w = temp_f7 * temp_f0;
out.color = (temp_r8 & 0x00FF0000) | ((u32)alpha << 24) | (temp_r8 & 0xFFFF);
addr = (int)lbl_802FC058;
((void (*)(void *, void *, const char *, s32, u8, s32, f32, f32, f32, f32, f32, f32, f32))fn_80147940)(lbl_8055D414, &out, (char *)(addr + 0xA4), 1, alpha, temp_r8, temp_f1_2, temp_f2, temp_f3, temp_f4, temp_f5, selectedVal, temp_f7);
}
}
fn_80147230(&item, lbl_80558A70, (const char *)fn_80131234(*labelp));
++i; ++labelp;
} while (i < 2);
((Dummy *)lbl_8055D414)->get3((const char *)base + 0xB0);
fn_801476C4();
((Dummy *)lbl_8055D414)->get3((const char *)base + 0xC0);
fn_801476C4();
}
fn_80011A2C();
fn_802C9904();
}
#pragma cplusplus reset
/* Returns the index of the first active, unoccupied AX stack entry, or -1 if none is available. */
s32 fn_8000CCB8(void) {
    s32 index = 0;
    goto compare;
body:
    if (fn_800075A0(index) != 0) {
        __AXGetStackHead_80137CFC(index);
        if (RjoyIsPadConnected() == 0) {
            return index;
        }
    }
    index++;
compare:
    if (index < fn_80137C74()) {
        goto body;
    }
    return -1;
}

extern void fn_80148070(void *, s32, s32);
extern void fn_80148134(f32 *, f32 *, s32, f32, f32);
extern s32 fn_80131234(s32);
extern void fn_801476C4(void);
extern void fn_800103B8(s32, s32, f32, f32, f32, f32, const char *, ...);
extern void fn_80011A2C(void);
extern f32 lbl_80560248;
extern s32 lbl_80560240;
extern s32 lbl_80560244;
extern const char lbl_80558A70[];
#pragma cplusplus on
#pragma scheduling on
extern "C" void fn_80148134(f32 *, f32 *, s32, f32, f32);
struct ConfigService {
    virtual void slot0();
    virtual void *lookup(const char *);
    virtual void slot2();
    virtual void *open(const char *);
    virtual void *find(const char *);
};
extern "C" void fn_8000CD24(void) {
    ConfigService *service;
    u8 *base = lbl_802FC058;
    void *object;
    void *temp;
    f32 out0;
    f32 out1;
    s32 names[2];

    service = (ConfigService *)lbl_8055D414;
    if (service == 0) return;
    object = service->open((const char *)base + 0xFC);
    if (object != 0) {
        temp = ((ConfigService *)*(volatile void ***)&lbl_8055D414)->find((const char *)base + 0x108);
        fn_80148070(object, 0x96FFFFFF, (s32)temp);
    }
    ((ConfigService *)*(volatile void ***)&lbl_8055D414)->lookup((const char *)base + 0x118);
    fn_801476C4();
    temp = ((ConfigService *)*(volatile void ***)&lbl_8055D414)->lookup((const char *)base + 0x12C);
    if (temp == 0) return;
    names[0] = lbl_80560240;
    names[1] = lbl_80560244;
    fn_80148134(&out0, &out1, *(volatile s32 *)((u8 *)temp + 0xC), *(f32 *)((u8 *)temp + 4), *(f32 *)((u8 *)temp + 8));
    ((void (*)(s32, s32, f32, f32, f32, f32, const char *, ...))fn_800103B8)(
        *(s32 *)((u8 *)temp + 0x18),
        *(s32 *)((u8 *)temp + 0x14),
        *(f32 *)((u8 *)temp + 0x10),
        out0,
        out1,
        *(f32 *)((u8 *)object + 0x10) - lbl_80560248,
        lbl_80558A70,
        fn_80131234(names[lbl_8055D420]));
    fn_80011A2C();
}
#pragma scheduling on
#pragma cplusplus off
