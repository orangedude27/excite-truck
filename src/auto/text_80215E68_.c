extern void fn_8021889C(void);

#include <types.h>
static inline void fn_80216244_rotate(const f32 *m, f32 *out, const f32 *v) {
    if (out == v) {
        f32 x = v[2]*m[6] + (v[0]*m[0] + v[1]*m[3]);
        f32 y = v[2]*m[7] + (v[0]*m[1] + v[1]*m[4]);
        f32 z = v[2]*m[8] + (v[0]*m[2] + v[1]*m[5]);
        out[0] = x; out[1] = y; out[2] = z;
    } else {
        out[0] = v[2]*m[6] + (v[0]*m[0] + v[1]*m[3]);
        out[1] = v[2]*m[7] + (v[0]*m[1] + v[1]*m[4]);
        out[2] = v[2]*m[8] + (v[0]*m[2] + v[1]*m[5]);
    }
}

extern void *lbl_8055EF88;
extern s32 lbl_8055EF78;
extern u32 lbl_8055EF7C;
extern u32 lbl_8055EF8C;
extern void (*lbl_8055EF90)(void);
extern u8 lbl_8055EF70;
extern u8 lbl_8055F024;
extern u32 lbl_804908C8[16];
extern s32 DrawList_beginFrame(void);
extern s32 fn_80216244(void);
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern void fn_802184D0(void);
extern void fn_80218574(void *);
extern void fn_80230B5C(void *);
extern void fn_8023108C(s32);
extern void DrawList_loadMatrix(void *);
extern void fn_802C86E8(u32);
extern void DrawList_setViewport(s32, s32, s32, s32);
extern void fn_802C88BC(s32);
extern void fn_802C974C(f32, f32, f32);
extern s32 fn_802160AC(void);
extern s32 fn_80211F54(void);
extern s32 fn_80019BA8(void);
extern s32 fn_80230DA0(void);
extern s32 DrawList_shutdown(void);
extern s32 fn_802C2B48(void);
extern s32 fn_80211F64(void);
extern s32 fn_802164D8(void);
extern s32 fn_80129AFC(void);
extern void fn_80218370(void *);
extern s32 fn_802E97B4(void);
extern void fn_802166B8(void);
/* Vtable for the 0x18-byte objects in the 16-element pool at base+0x200:
 * fn_80215EC4 (delete) and the fn_80215Cxx methods. */
extern char lbl_8033D690[];

/* One such 0x18-byte pooled object: +0x00 is the vtable pointer, +0x14 a cleared state word. */
typedef struct {
    /* 0x00 */ char *vtable;
    /* 0x04 */ char pad04[0x10];
    /* 0x14 */ s32 state;
} VtblObject;

extern s32 fn_80215EC4(s32, s32);
extern char lbl_80490710[];
extern void __array_delete(void *, void *, s32, s32);
extern f32 lbl_8055EF94;
extern s32 lbl_8055EF74;
extern s32 fn_80217270(s32);
extern s32 Abend_Panic(const char *, ...);
extern char lbl_8033D7EC[];
extern void fn_80218464();
extern u32 lbl_8055EF98;
extern char lbl_8055EF99;
__declspec(section ".data") extern f32 lbl_80558DC4;
extern u32 lbl_8055EF80;
extern u32 lbl_8055EF84;


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80128668(void);
s32 fn_80215E68(s32 value, s32 count) {
    /* Return value unchanged; if non-zero and count is positive, call fn_80128668 as a side effect. */
    if (value != 0 && count > 0) {
        fn_80128668();
    }
    return value;
}

#pragma scheduling invalid_target
/* Delete the array at lbl_80490710: 16 elements of 24 bytes each, using the deleting destructor fn_80215EC4. */
void fn_80215EA8(void) {
    __array_delete(lbl_80490710, fn_80215EC4, 0x18, 0x10);
}
#pragma scheduling on
s32 fn_80215EC4(s32 value, s32 count) {
    /* Return value unchanged; if non-zero and count is positive, call fn_80128668 as a side effect. */
    if (value != 0 && count > 0) {
        fn_80128668();
    }
    return value;
}

#pragma scheduling invalid_target
void fn_80215F04(VtblObject *obj) {
    /* Pool element constructor: install the vtable pointer and clear the state word. */
    obj->vtable = lbl_8033D690;
    obj->state = 0;
}
#pragma scheduling on
/* Return value if non-zero and count > 0 (side effect via Notify/Trigger); otherwise just return value. */
s32 fn_80215F1C(s32 value, s32 count) {
    if (value != 0 && count > 0) {
        fn_80128668();
    }
    return value;
}

/* If value is non-zero and count is positive, perform a side-effect callback; return value unchanged. */
s32 fn_80215F5C(s32 value, s32 count) {
    if (value != 0 && count > 0) {
        fn_80128668();
    }
    return value;
}

extern s32 fn_802C3034(s32);
extern s32 gxCanvasFillRect(s32, s32, s32, s32, s32);
extern s32 lbl_8055FBDC;
extern s32 fn_802E4A10(void);
extern char lbl_8033D768[];
extern char lbl_8033D774[];
#define OptionOneLabel lbl_8033D768 /* "OPTION 1" */
#define OptionTwoLabel lbl_8033D774 /* "OPTION 2" */
char *fn_80215F9C(void *option) {
    /* Return "OPTION 2" when the selector flag at +0x10 is set, otherwise "OPTION 1". */
    if (*(s32 *)((u8 *)option + 0x10) != 0) return (char *)OptionTwoLabel;
    return (char *)OptionOneLabel;
}

void fn_80215FBC(void *option) {
    /* Toggle the selector flag at +0x10 that fn_80215F9C reads to choose
     * between "OPTION 1" and "OPTION 2". */
    *(u32 *)((u8 *)option + 0x10) ^= 1;
}

/* Toggle the option selector at +0x10: flip its low bit so fn_80215F9C reports the other label (OPTION 1 <-> OPTION 2). */
void fn_80215FCC(void *option) {
    *(u32 *)((u8 *)option + 0x10) ^= 1;
}

/* Query stub in the option UI: always answers 1 (true) in this build. */
u32 fn_80215FDC(void) {
    return 1;
}

/* Query stub in the option UI: always answers 1 (true) in this build. */
u32 fn_80215FE4(void) {
    return 1;
}

u8 fn_80215FEC(void *option) {
    /* Return the byte field at offset 0x08 of the option object. */
    return *(u8 *)((u8 *)option + 8);
}

/* Read and return the byte at the given pointer. */
u8 fn_80215FF4(u8 *pValue) {
    return *pValue;
}

#define getCurrentInputNibble fn_802E4A10
#pragma scheduling invalid_target
s32 fn_80215FFC(const void *entry) {
    /* True when the option entry is active (byte +0) and its input-type id (s32 +4)
     * equals the high nibble of the current input word. */
    s32 matches = 0;
    if (*(const u8 *)entry != 0 && *(const s32 *)((const u8 *)entry + 4) == getCurrentInputNibble()) matches = 1;
    return matches;
}
#pragma scheduling on
#undef getCurrentInputNibble
/* Query stub in the option UI: always answers 1 (true) in this build. */
u32 fn_80216054(void) {
    return 1;
}

/* Draws the given rectangle on the current canvas using the global draw color. */
void fn_8021605C(void *rect, s32 canvasState) {
    s32 top;
    s32 left;

    fn_802C3034(canvasState);
    top = *(s32 *)((u8 *)rect + 8);
    left = *(s32 *)((u8 *)rect + 4);
    gxCanvasFillRect(left, top, left + *(s32 *)((u8 *)rect + 0xC), top + *(s32 *)((u8 *)rect + 0x10), lbl_8055FBDC);
}

extern s32 fn_8021832C();
extern void fn_80230B5C(void *);
extern void DrawList_loadMatrix(void *);
extern void fn_802C974C(f32, f32, f32);
extern void fn_802C5310(s32, s32, f32, f32, f32);
extern u32 lbl_8055EF80;
extern u32 lbl_8055EF84;
extern f32 lbl_80563458;
extern f64 lbl_80563460;
extern f32 lbl_80563468;
extern f32 lbl_8056346C;
extern f32 lbl_80563470;
extern f32 lbl_80563474;
extern f32 lbl_80563478;
#pragma push
#pragma scheduling invalid_target
#pragma fp_contract on
s32 fn_802160AC(void)
{
  u8 scratch[0x30];
  s32 temp_r31;
  f32 a;
  f32 *new_var;
  f32 b;
  register s32 cond = (s32)lbl_8055EF88;
  if (cond != 0)
  {
    temp_r31 = fn_8021832C();
  }
  else
  {
    temp_r31 = 0;
  }
  if ((temp_r31 == 0) && (lbl_8055EF7C == 0))
  {
    goto done;
  }
  fn_802C974C(lbl_80563468, lbl_8056346C, lbl_80563470);
  fn_80230B5C(scratch);
  DrawList_loadMatrix(scratch);
  a = (f32)(lbl_8055EF80 ^ 0x80000000u);
  a -= lbl_80563474;
  b = (f32)(lbl_8055EF84 ^ 0x80000000u);
  new_var = &a;
  b = lbl_80563478 - b;
  if (temp_r31 != 0)
  {
    do { fn_802C5310(temp_r31, 0, a, b, lbl_80563458); } while (0);
  }
  else
  {
    fn_802C5310(lbl_8055EF7C, 0, *new_var, b, lbl_80563458);
  }
  done:
  ;
}
#pragma pop
void fn_80216194(void) {
    s32 pass = 1;
    /* Run the shared update/draw pass three times. */
    do {
        fn_802166B8();
    } while (pass++ < 3);
}

#define sWindowGroupTable lbl_804908C8
#define sPrimaryGroup     lbl_8055EF88
#define updateGroup       fn_80218464
#pragma dont_inline on
void fn_802161CC(s32 includePrimary) {
    /* Run the per-group update on every registered window group, skipping the
     * primary group unless includePrimary is set and skipping empty slots. */
    s32 slot;
    for (slot = 0; slot < 16; slot++) {
        void *group = ((void **)sWindowGroupTable)[slot];
        if (group != 0 && (includePrimary != 0 || group != sPrimaryGroup)) {
            updateGroup(group);
        }
    }
}
#undef sWindowGroupTable
#undef sPrimaryGroup
#undef updateGroup

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline reset
s32 fn_80216244(void) {
    s32 i;
    u32 *p;
    u8 *obj;
    f32 matrix[12];
    f32 vec[3], pos[3];
    f32 x, y;
    f64 d;
    u32 raw;
    void (*callback)(void);
    p = lbl_804908C8;
    for (i = 0; i < 16; i++, p++) if (*p != 0) ((void (*)(void *))fn_802184D0)((void *)*p);
    callback = (void (*)(void))lbl_8055EF8C;
    if (callback != 0) callback();
    fn_802C86E8(0xFF0000FF);
    DrawList_setViewport(0, 0, lbl_8055CFF0, lbl_8055CFF4);
    fn_802C88BC(2);
    p = lbl_804908C8;
    for (i = 0; i < 16; i++, p++) {
        if (*p != 0) {
            obj = (u8 *)*p;
            DrawList_setViewport(0, 0, lbl_8055CFF0, lbl_8055CFF4);
            fn_80230B5C(matrix);
            fn_802C974C(lbl_80563468, lbl_8056346C, lbl_80563470);
            raw = *(u32 *)(obj + 0x454);
            x = -(f32)(s32)raw;
            raw = *(u32 *)(obj + 0x458);
            y = (f32)(s32)raw;
            vec[2] = 0.0f;
            vec[0] = x;
            vec[1] = y;
            fn_80216244_rotate(matrix, pos, vec);
            matrix[9] += pos[0];
            matrix[10] += pos[1];
            matrix[11] += pos[2];
            DrawList_loadMatrix(matrix);
            fn_8023108C(obj == lbl_8055EF88);
            fn_80218574(obj);
        }
    }
    fn_8023108C(1);
}
#pragma pop
extern s32 fn_80127A50(void *);
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern f32 lbl_8056347C, lbl_80563480;
extern void fn_80217590(void *,s32,s32), fn_802176D4(void *,s32,s32), fn_8021749C(void *,s32,s32), fn_802175F0(void *,s32,s32), fn_80217734(void *,s32,s32);
extern void fn_80217834(void *), fn_80217854(void *);
extern s32 fn_802E47B8(void), fn_802E46F0(void);
extern void fn_80217874(void *,u16);
s32 fn_802164D8(void) {
    s32 event[6];

    /* Poll pointer events, scale to screen coords, dispatch to active UI object, then handle key input. */
    if (fn_80127A50(event)) {
        s32 x = (s32)((lbl_8056347C * (f32)event[1]) / (f32)lbl_8055CFF0);
        s32 y = (s32)((lbl_80563480 * (f32)event[2]) / (f32)lbl_8055CFF4);
        lbl_8055EF80 = x;
        lbl_8055EF84 = y;
        if (lbl_8055EF88) {
            switch (event[0]) {
            case 0: fn_80217590(lbl_8055EF88, x, y); break;
            case 1: fn_802176D4(lbl_8055EF88, x, y); break;
            case 2: fn_8021749C(lbl_8055EF88, x, y); break;
            case 3: fn_802175F0(lbl_8055EF88, x, y); break;
            case 4: fn_80217734(lbl_8055EF88, x, y); break;
            case 7: fn_80217834(lbl_8055EF88); break;
            case 8: fn_80217854(lbl_8055EF88); break;
            }
        }
    }
    if (fn_802E47B8()) {
        s32 key = fn_802E46F0();
        if (lbl_8055EF88) fn_80217874(lbl_8055EF88, key);
    }
}

#pragma dont_inline reset

void fn_8021662C(void) {
    /* Run one UI frame: process input, update active UI, and render if the frame state is unchanged. */
    s32 savedFrameState = lbl_8055EF78;
    fn_80211F64();
    if (lbl_8055EF90 != NULL) lbl_8055EF90();
    fn_802164D8();
    if (lbl_8055EF88 != 0) fn_80129AFC();
    fn_802161CC(0);
    if (lbl_8055EF88 != 0) {
        fn_80218370(lbl_8055EF88);
    }
    if (savedFrameState == (s32)lbl_8055EF78) {
        if ((s32)lbl_8055EF70 == 0) fn_802166B8();
        fn_802E97B4();
    }
}

// Renders one UI frame: run render/update steps, optionally the frame callback and extra update pass.
void fn_802166B8(void) {
    DrawList_beginFrame();
    fn_80216244();
    fn_802160AC();
    if (fn_80211F54() == 0) {
        fn_80019BA8();
    }
    if (lbl_8055F024 != 0) {
        fn_80230DA0();
    }
    DrawList_shutdown();
    fn_802C2B48();
}

extern u32 lbl_8055EF98;
/* Getter for the UI mode flag byte: callers read *(u8 *)returned (0 or nonzero) to tell which UI mode is active. */
u32 *fn_80216708(void) {
#define kUiModeFlag lbl_8055EF98
    return &kUiModeFlag;
#undef kUiModeFlag
}

#pragma scheduling invalid_target
/* Clears a 16-entry state array and related counters/flags to zero. */
void fn_80216710(void) {
    int index;
    lbl_8055EF88 = 0;
    for (index = 0; index < 16; index++) {
        lbl_804908C8[index] = 0;
    }
    lbl_8055EF7C = 0;
    lbl_8055EF8C = 0;
    lbl_8055EF90 = 0;
}
void fn_8021676C(void) {
    /* Intentional no-op: empty callback/placeholder, touches no state. */
}

extern char lbl_8033D7A4[];
extern char lbl_8033D7B4[];
extern void *fn_801284F8(s32, const char *);
extern void *fn_80216D40(void *, s32, s32, s32, s32, s32, s32);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Allocate and initialize a 0xDE8-byte widget/window object, register it in
 * the 16-entry window table (lbl_804908C8), or report if the table is full. */
void *fn_80216770(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    const char *name = (const char *)lbl_8033D7A4;
    void *result = fn_801284F8(0xDE8, name);
    s32 i;
    if (result != 0)
        result = fn_80216D40(result, arg0, arg1, arg2, arg3, arg4, arg5);
    for (i = 0; i < 16; i++) {
        if (lbl_804908C8[i] == 0) {
            lbl_804908C8[i] = (u32)result;
            return result;
        }
    }
    Abend_Panic((const char *)&lbl_8033D7B4);
    return 0;
}
#pragma small_data off
/* Remove a window pointer from the managed window table and destroy it, or log an error if it is not found. */
void fn_8021683C(u32 windowPtr) {
    s32 slotIndex;
    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        u32 value = lbl_804908C8[slotIndex];
        if (value == windowPtr) {
            ((void (*)(u32, s32))fn_80217270)(windowPtr, 1);
            lbl_804908C8[slotIndex] = 0;
            return;
        }
    }
    Abend_Panic((const char *)(void *)&lbl_8033D7EC);
}
#pragma small_data on
/* Request a fade/transition: store the requested result and signal the fade loop to proceed. */
void fn_802168BC(s32 result) {
    #define s_fadeActive lbl_8055EF70
    #define s_fadeResult lbl_8055EF74
    s_fadeResult = result;
    s_fadeActive = 1;
    #undef s_fadeActive
    #undef s_fadeResult
}

/* Thunk for UIWindow_HideGroup: tail-forwards (window, groupId, fadeTime) unchanged to the hide-group implementation fn_8021889C. */
void fn_802168CC(void) {
    fn_8021889C();
}

void fn_802168D0(void) {
    /* Callback trampoline: forward to the sound-manager notification handler. */
    fn_80218968();
}

/* UIWindow_IsGroupVisible: forward (window, groupId) to the window's hidden-group
 * test; returns nonzero when the group's bit is clear in the +0x464 mask. */
s32 fn_802168D4(s32 window, s32 groupId) {
    #define UIWindow_TestGroupVisibility fn_8021885C
    return UIWindow_TestGroupVisibility((void *)window, groupId);
    #undef UIWindow_TestGroupVisibility
}

/* UIWindow_EnableGroup: forward to the group-enable method (fn_80218A34), which
 * clears the group's disabled bit and re-marks its child widgets as active. */
void fn_802168D8(void) {
    fn_80218A34();
}

/* UIWindow_DisableGroup: forward to the group-disable method (fn_80218ADC), which
 * sets the group's disabled bit and clears its child widgets' active flags. */
void fn_802168DC(void) {
    fn_80218ADC();
}

/* UIWindow_DispatchToGroup: forward to the window method that calls a virtual
 * handler on each child widget belonging to the given group. */
void fn_802168E0(void) {
    fn_80218B88();
}

extern void *lbl_8055EF88;
/* UIGetActiveWindow: return the currently active UI window (NULL when none). */
void* fn_802168E4(void) {
    return lbl_8055EF88;
}

void fn_802168EC(void *parent, void *child, int id) {
    #define UIWindow_AddChild fn_80218C98
    /* UIWindow_AddChild: register a child widget under this parent window;
     * forward (parent, child, id) to the add-child implementation. */
    UIWindow_AddChild(parent, (void **)child, id);
    #undef UIWindow_AddChild
}

extern s32 fn_8012742C(void);
extern void fn_80214D50(s32);
extern void fn_8023660C(void);
extern void fn_802D3E9C(s32);
extern void fn_80127A84(void *, void *, void *);
extern void fn_801282E8(void);
extern void fn_80236780(void);
extern void fn_8021734C(void *);
extern void fn_8021747C(void *, s32, f32 *, f32);
extern void fn_80236674(void);
extern void fn_80230E90(s32);
extern f32 fn_80214D48(void);
extern void fn_80236900(void);
extern void fn_802368D0(void);
extern void fn_802173F8(void *);
extern void fn_80217478(void *);
extern void fn_80236848(void);
extern void fn_80236600(void);
extern f32 lbl_80563484, lbl_80563488;
extern f32 lbl_80558DC4;
extern double __fabs(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
s32 fn_802168F0(void *arg0) {
    f32 sp[2];
    s32 sp8;
    void *prev;
    f32 f28, f29, f30, f31, f2;
    s32 flag;
    s32 gt;
    s32 old = lbl_8055EF78;
    lbl_8055EF78 = old + 1;
    if (fn_8012742C() != 0) return -1;
    if (*(u8 *)((u8 *)arg0 + 0xDE4) != 0) fn_80214D50(5);
    else fn_8023660C();
    fn_802D3E9C(0);
    *(u8 *)&lbl_8055EF98 = 1;
    fn_80127A84(&lbl_8055EF80, &lbl_8055EF84, &sp8);
    prev = lbl_8055EF88;
    sp[0] = lbl_80563458;
    lbl_8055EF88 = arg0;
    sp[1] = lbl_80563458;
    fn_80236780();
    fn_8021734C(arg0);
    fn_8021747C(arg0, 0, sp, lbl_80563458);
    fn_801282E8();
    lbl_8055EF70 = 0;
    if (prev != 0) lbl_8055EF74 = 0;
    fn_80217734(lbl_8055EF88, lbl_8055EF80, lbl_8055EF84);
    fn_80211F64();
    fn_80211F64();
    f2 = sp[0] > lbl_80563484 ? sp[0] : lbl_80563484;
    f28 = lbl_80563468;
    f29 = f28 / f2;
    f30 = lbl_80563468;
    f28 = (f32)__fabs(sp[0]) <= lbl_80558DC4 ? f28 : lbl_80563458;
    flag = 0;
    lbl_8055EF94 = f28;
    f31 = lbl_80563488;
    while (lbl_8055EF70 == 0) {
        fn_80236674();
        if (lbl_8055EF88 != 0) {
            void (*cb)(void *) = *(void (**)(void *))((u8 *)lbl_8055EF88 + 0x434);
            if (cb != 0) cb(lbl_8055EF88);
            if (f28 < f30) {
                fn_8021747C(lbl_8055EF88, 1, sp, f28);
            } else {
                if (flag == 0) {
                    flag = 1;
                    fn_80230E90(0);
                }
                fn_8021747C(lbl_8055EF88, 2, sp, lbl_80563468);
            }
        }
        if (f28 < f31) {
            while (fn_802E47B8() != 0) fn_802E46F0();
        }
        fn_8021662C();
        f28 += f29 * fn_80214D48();
        lbl_8055EF94 = f28 < f30 ? f28 : f30;
        if (fn_8012742C() != 0) {
            lbl_8055EF74 = -1;
            break;
        }
    }
    fn_8012742C();
    if (lbl_8055EF74 == -1) fn_80236900();
    else fn_802368D0();
    fn_8021747C(arg0, 0, sp, lbl_80563458);
    f2 = sp[1] > lbl_80563484 ? sp[1] : lbl_80563484;
    f30 = lbl_80563468;
    f31 = f30 / f2;
    if ((f32)__fabs(sp[1]) <= lbl_80558DC4) f30 = lbl_80563458;
    lbl_8055EF94 = f30;
    if (*(u8 *)&lbl_8055EF99 == 0) fn_80214D50(4);
    else *(u8 *)&lbl_8055EF99 = 0;
    f28 = lbl_80563458;
    for (;;) {
        gt = f28 > f30;
        f30 = gt ? f28 : f30;
        lbl_8055EF94 = f30;
        if (fn_8012742C() != 0) {
            lbl_8055EF74 = -1;
            break;
        }
        if (sp[1] > f28) {
            fn_80236674();
            if (lbl_8055EF88 != 0) fn_8021747C(lbl_8055EF88, 3, sp, f30);
        }
        fn_802161CC(1);
        fn_802166B8();
        if (f28 == f30) break;
        f30 -= f31 * fn_80214D48();
        fn_80211F64();
    }
    fn_80216194();
    lbl_8055EF70 = 0;
    fn_802173F8(arg0);
    lbl_8055EF88 = prev;
    if (prev != 0) {
        fn_80217734(prev, lbl_8055EF80, lbl_8055EF84);
        if (*(u8 *)((u8 *)arg0 + 0xDE4) == 0) fn_80217478(lbl_8055EF88);
    }
    fn_80236848();
    if (*(u8 *)((u8 *)arg0 + 0xDE4) == 0) fn_80236600();
    return lbl_8055EF74;
}
#pragma pop

extern char lbl_8055EF99;
/* Set the one-shot flag that suppresses the next fn_80214D50(4) speaker-volume
   refresh in the screen update; that update clears the flag once it is used. */
void fn_80216CA8(void) {
#define sSkipSpeakerRefresh lbl_8055EF99
    sSkipSpeakerRefresh = 1;
#undef sSkipSpeakerRefresh
}

/* Return the current screen-transition fade/progress factor, ramped by the transition update and read elsewhere (e.g. as "time") to scale fade and animation alpha. */
f32 fn_80216CB4(void) { return lbl_8055EF94; }

