#include "types.h"
extern s32 fn_802B32E0(s32);
extern s32 fn_802B4E44(s32);
extern float lbl_8055FA10;
extern s32 fn_801345D8(char *, s32, const char *, s32);
extern s32 sscanf(const char *, const char *, ...);
__declspec(section ".sdata") extern const char lbl_8055CE38[];

#pragma small_data on
__declspec(section ".sdata") extern const char lbl_8055CE40[];
#pragma small_data off
typedef signed long s32;
typedef unsigned long u32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055FA38;
extern float lbl_8055FA18;
extern s32 lbl_8055FA2C;
extern u8 lbl_8055FA58;
extern s32 fn_80204054(void *, s32, s32, void *, s32, s32);
extern void *DrawList_getCurrentMatrix(void);
__declspec(section ".data") extern s32 lbl_804BE7D8;
extern void **lbl_8055FA48;
__declspec(section ".sdata") extern const char lbl_8055CE68[], lbl_8055CEB8[], lbl_8055CEC0[];
extern void fn_801473F8(void *, const char *, const char *, ...);
extern void fn_801476C4(void *);
typedef struct MenuRenderRecord {
    void *name;
    s32 value;
    f32 y;
    s32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} MenuRenderRecord;
#pragma pack(push, 4)
typedef struct MenuRenderCopy {
    void *name;
    f64 pair;
    s32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} MenuRenderCopy;
#pragma pack(pop)

extern char lbl_8034A598[];
extern char lbl_8034A6A0[];
extern char lbl_8034A790[];
__declspec(section ".sdata") extern const char lbl_8055CEA8[];
__declspec(section ".sdata") extern const char lbl_8055CE58[];
__declspec(section ".sdata") extern const char lbl_8055CE60[];
extern double lbl_80564C68;
extern float lbl_80564C58;
extern float lbl_80564C60;
extern s32 FileOpenSecondary(void *);
extern void fn_802E3AD0(s32, const char *, ...);
extern void closeFileHandle(void *);
extern float fn_801DCF48(float *, float, float);
extern char lbl_8034A8B0[];
extern float lbl_80564C98;
#define FRAME_STEP lbl_80564C98 /* 0.05: step added per frame (max clamp is 10) */
extern void formatDebugTextEntry(void *, const char *, ...);
extern s32 fn_802B05E4(void);
extern s32 fn_802B7B08(void);

extern char lbl_8055FA31;
extern s32 lbl_8055FA3C;
extern s32 lbl_8055FA40;
extern s32 fn_802B5D2C(const char *, s32);
__declspec(section ".sdata") extern const char lbl_8055CE38[];
extern s32 fn_802B59A4(s32);
extern s32 fn_802B321C(s32, void **, s32, s32);
extern s32 fn_802B3F0C(s32);
extern void fn_80128668(void*);
extern const char lbl_8055CE48[];
/* Resets the three 32-bit fields of a container to zero and, when shouldFree
 * is positive, frees the container itself. */
void *fn_802B5A68(void *object, s32 shouldFree) {
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldFree > 0)
            fn_80128668(object);
    }
    return object;
}

/* Destroys a 3-word container: clears its first three fields and, if shouldDelete
 * is positive, frees the container itself (delete-mode 3). Returns the container. */
void *fn_802B5AC0(void *object, s32 shouldDelete) {
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

/* Display name of each debug view mode, indexed by mode: "Objects", "Advanced",
   "Material-Map", "Road-Opacity". */
__declspec(section ".data") extern const char *lbl_802FAB30[4];
extern const char lbl_8055CE30; /* "<unk>" -- what an out-of-range mode shows */
/* Display name of a debug view mode: the lbl_802FAB30 entry for `mode` (0 "Objects",
   1 "Advanced", 2 "Material-Map", 3 "Road-Opacity"), or "<unk>" for anything else.
   The string pointer comes back as a u32, which is how the callers pass it on. */
u32 fn_802B5B18(s32 mode) {
    const char *names[4];
    const char **p = lbl_802FAB30;
    names[0] = *p++;
    names[1] = *p++;
    names[2] = *p++;
    names[3] = *p;
    if (mode >= 0 && (u32)mode < 4) return (u32)names[mode];
    return (u32)&lbl_8055CE30;
}

/* Return the material set the debug viewer is currently on: the UMatSet entry
 * at the global material-set index (callers use the tail-call's return value). */
void fn_802B5B6C(void) {
#define matSetIndex lbl_8055FA3C /* which UMatSet (material set) the viewer is on */
    fn_802B59A4(matSetIndex);
#undef matSetIndex
}

extern void *lbl_8055FA44;
s32 fn_802B5B74(void *arg0) {
#pragma opt_propagation off
    s32 workspace[51];
    s32 result;
    s32 index;
    void *object;

    workspace[2] = 0x10;
    workspace[0] = (s32)&workspace[3];
    workspace[1] = 0;
    object = ((void *(*)(void))fn_802B5B6C)();
    ((void (*)(void *, s32, s32, s32))fn_802B321C)(
        workspace, 0, *(s32 *)((u8 *)object + 8), lbl_8055FA40);

    index = (s32)lbl_8055FA44;
    result = 0;
    if (index >= 0 && index < workspace[1]) {
        result = 1;
    }
    if (result != 0) {
        s32 *entry = (s32 *)workspace[0] + index * 3;
        ((s32 *)arg0)[0] = entry[0];
        ((s32 *)arg0)[1] = entry[1];
        ((s32 *)arg0)[2] = entry[2];
    }
    workspace[0] = 0;
    workspace[1] = 0;
    workspace[2] = 0;
    return result;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
/* Advance the debug viewer's selected-object index (lbl_8055FA40) by `delta` modulo 7,
 * skipping indices past the current material set's object count until it is valid
 * or reaches the index-6 sentinel. */
void fn_802B5C24(s32 delta) {
    s32 newIndex;
    s32 sum;
    s32 wrapped;
    void *materialSet;

    do {
        sum = delta + lbl_8055FA40;
        wrapped = sum + 7;
        lbl_8055FA40 = wrapped % 7;
        newIndex = lbl_8055FA40;
        materialSet = ((void *(*)(void))fn_802B5B6C)();
    } while (newIndex >= fn_802B3F0C(*(s32 *)((u8 *)materialSet + 8)) && newIndex != 6);
}
#pragma pop

/* Advance the debug viewer's selected-object index to the next object (delta +1). */
void fn_802B5CAC(void) {
    fn_802B5C24(1);
}

#pragma push
#pragma dont_inline on
/* Advance the "tedash.val" debug viewer's current material set by `delta`. */
void fn_802B5CB4(s32 delta) {
#define matSetIndex lbl_8055FA3C /* which UMatSet (material set) the viewer is on */
    matSetIndex += delta;
#undef matSetIndex
}
#pragma pop

/* Advance the "tedash.val" debug viewer's current material set to the next one (delta +1). */
void fn_802B5CC4(void) {
    fn_802B5CB4(1);
}

extern int __cntlzw(unsigned int);
void fn_802B5CCC(void) {
    /* Refresh the debug viewer's selected object: gather its tweakers, flag an empty layer, then run per-tweaker updates and refresh cached fields. */
    #define objectIndex lbl_8055FA40
    u8 *layerState;
    u8 *matSet;

    matSet = (u8 *)((void *(*)(void))fn_802B5B6C)();
    fn_802B321C(0, (void **)&layerState, *(s32 *)(matSet + 8), objectIndex);
    *(signed char *)layerState = (unsigned int)__cntlzw(*layerState) >> 5;
    matSet = (u8 *)((void *(*)(void))fn_802B5B6C)();
    fn_802B32E0(*(s32 *)(matSet + 8));
    matSet = (u8 *)((void *(*)(void))fn_802B5B6C)();
    fn_802B4E44(*(s32 *)(matSet + 8));
    #undef objectIndex
}

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
/* Formats a "%s:%%d" pattern for the given name and parses one integer from the input string, or -1 on failure. */
s32 fn_802B5D2C(const char *name, s32 input) {
    char formatBuf[0x40];
    s32 value;
    ((s32 (*)(char *, s32, const char *, ...))fn_801345D8)(formatBuf, 0x40, lbl_8055CE38, name);
    if (sscanf((const char *)input, formatBuf, &value) != 1) {
        value = -1;
    }
    return value;
}
#pragma pop

#pragma push
#pragma dont_inline on
/* Parse the "object:"-tagged integer from a text line via fn_802B5D2C; returns -1 when absent. */
s32 fn_802B5D94(s32 text) {
#define TAG_OBJECT lbl_8055CE40
    return fn_802B5D2C(TAG_OBJECT, text);
#undef TAG_OBJECT
}

u32 fn_802B5DA0(void) {
    /* Branchless "parsed value != -1" test on fn_802B5D94's result: 1 when the
       "object" property parsed successfully, 0 when it returned -1. */
    s32 parsedValue = ((s32 (*)())fn_802B5D94)();
    return (u32)((-1 - parsedValue) | (parsedValue + 1)) >> 31;
}

#pragma pop

extern s32 fn_801345D8(char *, s32, const char *, s32);
extern s32 fn_802B05DC(void);
extern s32 fn_802B5D2C(const char *, s32);
__declspec(section ".sdata") extern const char lbl_8055CE38[];
__declspec(section ".sdata") extern const char lbl_8055CE48[]; /* "layer" -- tag parsed by fn_802B5D2C */
__declspec(section ".sdata") extern const char lbl_8055CE50[];
typedef struct {
    s32 w[5];
} Struct804BFF80_Entry;

typedef struct {
    s32 unk0[5];
    char str1[32];
    char str2[32];
    s32 unk54[5];
} Struct804BFF80;
extern s32 lbl_804BFF80[26];
extern void fn_802B83CC(void);
extern s32 fn_802B8510(s32);
extern s32 fn_80127A50(void *);
extern s32 lbl_8055FA28;
extern float lbl_8055FA08;
extern float lbl_80564C5C;
extern s32 fn_802B32E0(s32);
extern s32 fn_802B4E44(s32);
extern s32 sscanf(const char *, const char *, ...);
typedef s32 (*Fn802B83CCPredicate)(const char *);
typedef s32 (*Fn802B83CCAction)(s32, const char *);
typedef struct {
    const char *name;
    Fn802B83CCPredicate predicate;
    Fn802B83CCAction action;
} Fn802B83CCEntry;
extern Fn802B83CCEntry lbl_8034A95C[];
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
/* Predicate for the "layer" tag: true when `text` (a string passed as a number,
 * the way these tag helpers take it) carries a "layer:<n>" value naming a water
 * layer other than the one in use.  fn_802B5D2C parses the tag and answers -1
 * when it is absent; fn_802B05DC returns the "water_layer" index taken from the
 * game config (lbl_8055CD78, -1 when there is none).
 * Proposed name: IsLayerChangeRequested */
s32 fn_802B5DD0(s32 text) {
    s32 parsedLayer;
    s32 waterLayer;
    s32 result;
    parsedLayer = fn_802B5D2C(lbl_8055CE48 /* "layer" */, text);
    waterLayer = fn_802B05DC();
    result = 0;
    if ((parsedLayer != -1) && (parsedLayer != waterLayer)) {
        result = 1;
    }
    return result;
}
extern double lbl_80564C68;
extern float lbl_80564C70;
extern s32 KERNEL_GetTimeMs(void);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Parse the "layer" tag from `text` (a string passed as a number) into the
 * selected-layer global lbl_8055FA28; fn_802B5D2C returns -1 when absent.
 * Then reset the reference time lbl_8055FA08 to -100.0f (lbl_80564C5C). */
void fn_802B5E24(s32 text) {
    lbl_8055FA28 = fn_802B5D2C(lbl_8055CE48, text);
    lbl_8055FA08 = lbl_80564C5C;
}

/* Parses the "brush" tag from `text` (a string passed as a number) into
 * lbl_8055FA2C, via fn_802B5D2C which returns -1 when the tag is absent, then
 * resets lbl_8055FA10 to -100.0f (the constant lbl_80564C5C). */
void fn_802B5E58(s32 text) {
    extern s32 lbl_8055FA2C;
    extern float lbl_8055FA10;
    extern float lbl_80564C5C;
    extern const char lbl_8055CE50[];
    lbl_8055FA2C = fn_802B5D2C(lbl_8055CE50, text);
    lbl_8055FA10 = lbl_80564C5C;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
u32 fn_802B5E8C(s32 text) {
    /* Returns a nonzero mask if the "brush" value in text parses (fn_802B5D2C did not return -1), else 0. */
    s32 parsedValue = fn_802B5D2C(lbl_8055CE50, text);
    return (u32)((-1 - parsedValue) | (parsedValue + 1)) >> 31;
}
#pragma pop
extern void* lbl_8055FA44;
extern s32 fn_802B5D94();

/* Store the index parsed from the "object" property (fn_802B5D94) into the
   current object index lbl_8055FA44, later used to pick an entry from the
   parsed object list. */
void fn_802B5EC4(void) {
    lbl_8055FA44 = (void*)fn_802B5D94();
}

#pragma scheduling on
void fn_802B5EE8(void) {
    register s32 v = lbl_8055FA38 + 1;
    lbl_8055FA18 = lbl_80564C5C;
    v %= 4;
    lbl_8055FA38 = v;
    *(s32 *)((u8 *)&lbl_804BE7D8 + 4) = 0;
}
extern s32 lbl_8055FA38;
extern float lbl_8055FA18;
__declspec(section ".data") extern s32 lbl_804BE7D8;
extern s32 fn_80128678(void);
extern s32 fn_80128684(void);
extern void *fn_80156A40(void);
extern s32 fn_802A7BDC(s32, s32);
extern void fn_802BBEE4(void);
extern void fn_802C21C0(void);
#pragma push
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_802B5F24(s32 arg0) {
    /* Collect up to 10 non-null items from the current source object and add each to arg0. */
    class V {
    public:
        virtual void a();
        virtual s32 b(s32);
    };
    s32 count;
    s32 item;
    V *source;

    fn_80128684();
    count = 0;
    do {
        source = (V *)fn_80156A40();
        item = source->b(0);
        if (item == 0)
            break;
        fn_802A7BDC(arg0, item);
        count++;
    } while (count < 10);
    fn_80128678();
}
#pragma cplusplus reset
#pragma pop
#pragma push
#pragma use_lmw_stmw off
#pragma processor 750
void fn_802B5F98(void) {
    register char *base = lbl_8034A598;
    s32 index, i, j;
    s32 handle;
    register float gridScale, uvScale;
    float height, x, z;
    float u, v;
    float fi, fj;
    float points[3];

    handle = FileOpenSecondary(base + 0x2c);
    if (handle == -1) return;
    fn_802E3AD0(handle, lbl_8055CE58);
    fn_802E3AD0(handle, base + 0x3c);
    fn_802E3AD0(handle, base + 0x50);

    gridScale = lbl_80564C58;
    uvScale = lbl_80564C60;
    index = 0;
    for (i = -0x200; i <= 0x200; i += 8) {
        for (j = -0x200; j <= 0x200; j += 8, index++) {
            fi = (float)i;
            fj = (float)j;
            x = fi * gridScale;
            z = fj * gridScale;
            height = fn_801DCF48(points, x, z);
            u = (float)(i + 0x200) * uvScale;
            v = (float)(j + 0x200) * uvScale;
            fn_802E3AD0(handle, base + 0x60, x, height, z);
            fn_802E3AD0(handle, base + 0x78, u, v);
            fn_802E3AD0(handle, base + 0x8c, points[0], points[1], points[2]);
            if (i > -0x200 && j > -0x200) {
                fn_802E3AD0(handle, base + 0xa4, index, index - 1, index - 0x81);
                fn_802E3AD0(handle, base + 0xa4, index - 0x81, index - 1, index - 0x82);
            }
        }
    }
    fn_802E3AD0(handle, lbl_8055CE60);
    fn_802B5F24(handle);
    fn_802E3AD0(handle, lbl_8055CE60);
    closeFileHandle(&handle);
}
#pragma pop
/* Re-selects the material set the "tedash.val" debug viewer is on, then toggles
 * the memory-allocation subsystem's disable flag (clears it, then sets it). */
void fn_802B618C(void) {
#define matSetIndex lbl_8055FA3C /* which UMatSet (material set) the viewer is on */
    fn_802B59A4(matSetIndex);
    fn_80128684();
    fn_80128678();
#undef matSetIndex
}

/* "tedash.val" debug viewer: run the setup for the current view mode. Road-Opacity
 * (3) reloads the road-opacity texture, Material-Map (2) rebuilds the matmap images;
 * "Objects" and "Advanced" need no extra setup. */
void fn_802B61B8(void) {
#define viewMode lbl_8055FA38 /* 0 "Objects", 1 "Advanced", 2 "Material-Map", 3 "Road-Opacity" */
#define setupMaterialMap fn_802BBEE4  /* rebuilds the "matmap"/"matmap2" images */
#define reloadRoadOpacity fn_802C21C0 /* reloads the "roadopac.tga" texture */
    if (viewMode == 3) {
        goto call_c;
    }
    if (viewMode >= 3) {
        goto done;
    }
    if (viewMode >= 2) {
        goto call_b;
    }
done:
    return;
call_b:
    setupMaterialMap();
    return;
call_c:
    reloadRoadOpacity();
#undef viewMode
#undef setupMaterialMap
#undef reloadRoadOpacity
}

extern char lbl_8034A980[];
__declspec(section ".data") extern s32 lbl_804BE7D8;
extern s32 lbl_8055FA00;
extern s32 lbl_8055FA34;
extern s32 fn_80145E70(char *);
extern s32 fn_8026E214(void *, void *);
extern void deleteThreads__6SystemFv(void *);
extern s32 fn_802C6CF8(void);
extern char lbl_804BFA70[];
#pragma push
#pragma processor 750
#pragma scheduling 750
__declspec(section ".sdata") extern double lbl_80564C68;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802B61E0(void) {
    /* Store the current timer value in seconds at lbl_8055FA08. */
    s32 val = KERNEL_GetTimeMs();
    lbl_8055FA08 = (float)val / lbl_80564C70;
}

void fn_802B6228(void) {
    /* Update the secondary timer accumulator in seconds. */
    s32 val = KERNEL_GetTimeMs();
    lbl_8055FA10 = (float)val / lbl_80564C70;
}

#pragma pop
/* Return nonzero when the debug viewer's selected-object index is at its sentinel value 7. */
s32 fn_802B6270(void) {
#define objectIndex lbl_8055FA40
    return objectIndex == 7;
#undef objectIndex
}

/* Snap the debug viewer's selected-object index (lbl_8055FA40) to the sentinel 7,
 * or to 6 ("All Objects") when it is already 7.  (x-7)|(7-x) is zero only when
 * x==7; complementing and >>31 folds that into -1 vs 0, added to 7 below. */
void fn_802B6284(void) {
    lbl_8055FA40 = ((s32) ~((lbl_8055FA40 - 7) | (7 - lbl_8055FA40)) >> 31) + 7;
}

extern char lbl_8034A670[];
extern char lbl_8034A70C[];
extern int strcmp(const char *, const char *);
#pragma dont_inline on
#pragma scheduling invalid_target
/* Run the action of the track-editor debug view's dropdown control named *name.
 *
 * sDropdownTable is 4 ControlEntry records covering the two dropdowns:
 *   "layer_dropdown" (fn_802B61E0) and a nameless entry whose test fn_802B5DD0
 *   accepts any "layer:<n>" text, then "brush_dropdown" (fn_802B6228) and its
 *   nameless "brush:<n>" test fn_802B5E8C.  An entry matches when its own name
 *   equals *name, or when it has no name and its test function accepts *name;
 *   the entry found is called with the name and a pointer to itself, which
 *   restarts that dropdown's reference timer.  fn_802B6358 walks the
 *   11-entry table of named controls the same way. */
void fn_802B62A4(const char **name) {
    struct ControlEntry {
        const char *name;
        s32 (*test)(const char *);
        void (*action)(const char *, void *entry);
    };
#define sDropdownTable lbl_8034A670
    register struct ControlEntry *entry = (struct ControlEntry *)sDropdownTable;
    register u32 i = 0;

loop:
    if (entry->name != 0 && strcmp(entry->name, *name) == 0) {
        goto action;
    }
    if (entry->test != 0 && entry->test(*name) != 0) {
        goto action;
    }
    goto next;
action:
    {
        struct ControlEntry *actionEntry =
            (struct ControlEntry *)(sDropdownTable + i * sizeof(struct ControlEntry));
        actionEntry->action(*name, (void *)actionEntry);
        return;
    }
next:
    i++;
    entry += 1;
    if (i < 4) {
        goto loop;
    }
#undef sDropdownTable
}
/* Run the action of the editor-menu control whose name is *name.
 *
 * sControlTable is 11 ControlEntry records for the named controls of the
 * in-game track editor ("cur_material", "object_clump", "mode_button",
 * "generate_wmap", "save_matmap", "toggle_objects", "dump_world_model", ...).
 * An entry matches when its name equals *name, or when it has no name of its
 * own and its test function accepts *name; the entry found is called with the
 * name and a pointer to itself.  fn_802B62A4 walks the 4-entry dropdown table
 * (lbl_8034A670: "layer_dropdown", "brush_dropdown") the same way. */
void fn_802B6358(const char **name) {
    struct ControlEntry {
        const char *name;
        s32 (*test)(const char *);
        void (*action)(const char *, void *entry);
    };
#define sControlTable lbl_8034A70C
    register struct ControlEntry *entry = (struct ControlEntry *)sControlTable;
    register u32 i = 0;

loop:
    if (entry->name != 0 && strcmp(entry->name, *name) == 0) {
        goto action;
    }
    if (entry->test != 0 && entry->test(*name) != 0) {
        goto action;
    }
    goto next;
action:
    {
        struct ControlEntry *actionEntry =
            (struct ControlEntry *)(sControlTable + i * sizeof(struct ControlEntry));
        actionEntry->action(*name, (void *)actionEntry);
        return;
    }
next:
    i++;
    entry += 1;
    if (i < 11) {
        goto loop;
    }
#undef sControlTable
}
extern f32 fn_800108C8(f32, s32); /* measured text width, scaled by the UI font + text scale */
extern f32 fn_8001090C(f32);      /* a value scaled by the UI font's vertical metric */
extern float lbl_80564C74;        /* 0.0f: horizontal offset for left-aligned text */
extern float lbl_80564C78;        /* 0.5f: half-width factor for centered text */
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Hit test for a debug-menu text entry: returns 1 when the cursor held in the input
 * state (integer x/y at lbl_804BFF80+4/+8) lies inside the entry's text box. The text
 * width/height come from the UI font metrics; the entry's alignment flags shift the
 * box horizontally (left, right or centered). */
s32 fn_802B640C(const void *entryObj, s32 text) {
    const struct Entry {
        f32 unk0;
        f32 x;
        f32 y;
        f32 unkC;
        f32 scale;
        s32 flags;
    } *e = (const struct Entry *)entryObj;
    f32 textHeight, textWidth, alignOffset, entryX, rightEdge;
    s32 alignFlags, inside, withinX, withinY;
#define cursorX *(s32 *)((u8 *)&lbl_804BFF80 + 4)
#define cursorY *(s32 *)((u8 *)&lbl_804BFF80 + 8)
#define LEFT_ALIGN_OFFSET lbl_80564C74
#define CENTER_ALIGN_FACTOR lbl_80564C78

    textWidth = fn_800108C8(e->scale, text);
    textHeight = fn_8001090C(e->scale);
    alignFlags = e->flags;
    entryX = e->x;
    rightEdge = entryX + textWidth;
    if (alignFlags & 1)
        alignOffset = LEFT_ALIGN_OFFSET;
    else if (alignFlags & 2)
        alignOffset = -textWidth;
    else
        alignOffset = -textWidth * CENTER_ALIGN_FACTOR;
    inside = 0;
    withinY = 0;
    withinX = 0;
    if ((f32)cursorX >= entryX + alignOffset &&
        (f32)cursorX < rightEdge + alignOffset)
        withinX = 1;
    if (withinX && (f32)cursorY >= e->y)
        withinY = 1;
    if (withinY && (f32)cursorY < e->y + textHeight)
        inside = 1;
    return inside;
#undef cursorX
#undef cursorY
#undef LEFT_ALIGN_OFFSET
#undef CENTER_ALIGN_FACTOR
}
#pragma pop
__declspec(section ".sdata") extern const char lbl_8055CE70[];
extern int vsprintf(char *, const char *, va_list);
extern int stricmp(const char *, const char *);
extern void fn_80147230(void *, const char *, ...);
#pragma scheduling invalid_target
// Formats a UI/debug text entry, updates its highlight/state color and selection fields in
// the shared UI state (lbl_804BFF80) based on the formatted text/name, then forwards the
// formatted string for rendering.
/* Format a debug-menu text line, color it by the shared selection state, run the matched control's action, and forward the text for rendering. */ void formatDebugTextEntry(void *arg0, const char *fmt, ...) {
    char formattedText[256];
    va_list args;
    Struct804BFF80 *uiState;

    va_start(args, fmt);
    vsprintf(formattedText, fmt, args);

    uiState = (Struct804BFF80 *)&lbl_804BFF80;
    *(s32 *)((char *)arg0 + 0x18) = 0xFFD8D8D8;

    if (uiState->str1[0] != 0) {
        if (stricmp(uiState->str1, *(char **)arg0) == 0) {
            *(s32 *)((char *)arg0 + 0x18) = -0x100;
        }
    } else if (uiState->str2[0] != 0) {
        if (stricmp(uiState->str2, *(char **)arg0) == 0) {
            *(s32 *)((char *)arg0 + 0x18) = -1;
        }
    } else if (fn_802B640C(arg0, (s32)formattedText) != 0) {
        {
            char *src = *(char **)arg0;
            s32 n = 32;
            char *dst = uiState->str2;
            while ((*dst++ = *src++) != 0) {
                if (--n <= 0) {
                    dst[-1] = 0;
                    break;
                }
            }
        }
        *(s32 *)((char *)arg0 + 0x18) = -1;
        fn_802B62A4(arg0);
        if (*(s32 *)&lbl_804BFF80 == 0) {
            fn_802B6358(arg0);
            {
                char *src = *(char **)arg0;
                s32 n = 32;
                char *dst = (char *)&lbl_804BFF80 + 0x14;
                while ((*dst++ = *src++) != 0) {
                    if (--n <= 0) {
                        dst[-1] = 0;
                        break;
                    }
                }
            }
            *(s32 *)((char *)&lbl_804BFF80 + 0x54) = *(s32 *)&lbl_804BFF80;
            *(s32 *)((char *)&lbl_804BFF80 + 0x58) = *(s32 *)((char *)&lbl_804BFF80 + 4);
            *(s32 *)((char *)&lbl_804BFF80 + 0x5C) = *(s32 *)((char *)&lbl_804BFF80 + 8);
            *(s32 *)((char *)&lbl_804BFF80 + 0x60) = *(s32 *)((char *)&lbl_804BFF80 + 0xC);
            *(s32 *)((char *)&lbl_804BFF80 + 0x64) = *(s32 *)((char *)&lbl_804BFF80 + 0x10);
        }
    }
    fn_80147230(arg0, lbl_8055CE70, formattedText);
}

#pragma cplusplus on
extern "C" void fn_802B676C(void) {
    /* Show the current material name in the debug UI entry. */
    class Dummy_802B676C {
    public:
        virtual void m0();
        virtual Dummy_802B676C *m1(void *);
    };
    s32 *state = ((s32 *(*)())fn_802B5B6C)();
    Dummy_802B676C *uiRoot = (Dummy_802B676C *)lbl_8055FA48;
    uiRoot = uiRoot->m1(lbl_8034A6A0);
    formatDebugTextEntry(uiRoot, lbl_8034A790, *state);
}
#pragma cplusplus reset

#pragma scheduling on
__declspec(section ".sdata") extern const char lbl_8055CE78[], lbl_8055CE80[];
extern const char lbl_8034A808[], lbl_8034A814[];
extern s32 fn_80147FF0(s32);
#pragma cplusplus on
/* Look up a draw-style object by index through the global System's virtual factory,
 * then draw its 9-slice frame using the color stored at offset 0x18. */
extern "C" void fn_802B67C8(s32 index) {
    struct StyleFactory {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void *getStyle(s32);
    };
    StyleFactory *system = (StyleFactory *)lbl_8055FA48;
    void *style = system->getStyle(index);
    ((void (*)(void *, s32))fn_80147FF0)(style, *(s32 *)((char *)style + 0x18));
}
#pragma cplusplus reset
__declspec(section ".sdata") extern const char lbl_8055CE74[];
extern u8 lbl_8055FA30;
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_802B6804(void) {
    class Dummy {
    public:
        virtual void v0();
        virtual void *call(const char *);
        virtual void v2();
        virtual void *get(const char *);
    };
    typedef struct {
        void *name;
        s32 timeBits;
        s32 value;
        s32 unkC;
        f32 time10;
        s32 unk14;
        s32 unk18;
        s32 unk1C;
    } Record;
    typedef struct {
        u8 pad[0x20];
        void **currentPtr;
        void *current;
    } Item;

    const char *strs = lbl_8034A598;
    void *recordB;
    void *recordA;
    f32 step;
    Item *item;
    s32 offset;
    s32 i;
    void *best;
    void *selected;
    volatile const u8 *source;
    Record first;
    Record second;

    {
        Dummy *obj = (Dummy *)lbl_8055FA48;
        void *timing;

        fn_802B67C8((s32)(strs + 0x208));
        obj = (Dummy *)lbl_8055FA48;
        recordA = obj->call(strs + 0x218);
        obj = (Dummy *)lbl_8055FA48;
        recordB = obj->call(strs + 0x228);
        obj = (Dummy *)lbl_8055FA48;
        timing = obj->get(strs + 0x238);
        step = *(f32 *)((u8 *)timing + 0x14);
    }

    i = 0;
    offset = 0;
    goto loop_test;
loop_body:
    item = (Item *)((u8 *)*(u32 *)&lbl_804BFA70 + offset);
    best = *item->currentPtr;
    if ((u32)item->current < (u32)best)
        item->current = best;

    source = (volatile const u8 *)recordA;
    first.name = *(void * volatile *)(source + 0);
    s32 bitsA;
    s32 valueA;
    valueA = *(volatile const s32 *)(source + 4);
    bitsA = *(volatile const s32 *)(source + 8);
    first.value = bitsA;
    first.timeBits = valueA;
    first.unkC = *(volatile const s32 *)(source + 0xC);
    f32 time10A = *(volatile const f32 *)(source + 0x10);
    first.time10 = time10A;
    first.unk14 = *(volatile const s32 *)(source + 0x14);
    first.unk18 = *(volatile const s32 *)(source + 0x18);
    first.unk1C = *(volatile const s32 *)(source + 0x1C);
    *(f32 *)((u8 *)&first + 8) += step * (f32)i;

    if (lbl_8055FA30)
        selected = item->current;
    else
        selected = *item->currentPtr;
    fn_80147230(&first, lbl_8055CE74, selected);

    source = (volatile const u8 *)recordB;
    second.name = *(void * volatile *)(source + 0);
    s32 bitsB;
    s32 valueB;
    valueB = *(volatile const s32 *)(source + 4);
    bitsB = *(volatile const s32 *)(source + 8);
    second.value = bitsB;
    second.timeBits = valueB;
    second.unkC = *(volatile const s32 *)(source + 0xC);
    f32 time10B = *(volatile const f32 *)(source + 0x10);
    second.time10 = time10B;
    second.unk14 = *(volatile const s32 *)(source + 0x14);
    second.unk18 = *(volatile const s32 *)(source + 0x18);
    second.unk1C = *(volatile const s32 *)(source + 0x1C);
    *(f32 *)((u8 *)&second + 8) += step * (f32)i;
    fn_80147230(&second, lbl_8055CE70, item);

    offset += 0x28;
    i++;
loop_test:
    if (((s32 *)&lbl_804BFA70)[1] > i)
        goto loop_body;
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_802B69FC(void) {
    /* Configure two UI elements via the global manager using offsets from a string/data base. */
    class Dummy_802B69FC {
    public:
        virtual void m0();
        virtual Dummy_802B69FC *m1(void *);
    };
    char *base = lbl_8034A598;
    Dummy_802B69FC *manager = (Dummy_802B69FC *)lbl_8055FA48;

    manager = manager->m1(base + 0x134);
    formatDebugTextEntry(manager, base + 0x244);
    manager = (Dummy_802B69FC *)lbl_8055FA48;
    manager = manager->m1(base + 0x160);
    formatDebugTextEntry(manager, base + 0x258);
}
#pragma cplusplus reset

#pragma push
#pragma small_data off
/* Returns the brush/resource folder path string for a given mode:
 * 2="brush\\", 3="roadbrush\\", 5="excavate\\", 4/default="". */
s32 fn_802B6A70(s32 mode) {
#define kBrushPath lbl_8055CE78
#define kRoadBrushPath lbl_8034A808
#define kExcavatePath lbl_8034A814
#define kEmptyPath lbl_8055CE80
    switch (mode) {
    case 2:
        return (s32)&kBrushPath;
    case 3:
        return (s32)&kRoadBrushPath;
    case 5:
        return (s32)&kExcavatePath;
    default:
    case 4:
        return (s32)&kEmptyPath;
    }
#undef kBrushPath
#undef kRoadBrushPath
#undef kExcavatePath
#undef kEmptyPath
}
#pragma pop
extern float lbl_8055FA18;
extern s32 fn_802B6A70(s32);
extern void *fn_802B5240(void *);
extern void fn_802B52B4(void);
extern s32 FileFindFirst(void *, void *, s32);
extern s32 fn_802E3C24(s32, void *, s32);
extern void FileFind_Close(s32);
extern char *strchr(char *, int);
extern const char lbl_8055CE88[];
extern const char lbl_8055CE90[];
extern const char lbl_8055CE98[];
__declspec(section ".sdata") extern const char lbl_8055CE88[];
__declspec(section ".sdata") extern const char lbl_8055CE90[];
__declspec(section ".sdata") extern const char lbl_8055CE98[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma small_data off
#pragma use_lmw_stmw off
void fn_802B6AC0(void) {
    struct Texture { u32 width; u32 height; u32 *pixels; };
    struct Entry { char name[0x20]; u32 width; u32 height; u8 pixels[1]; };
    struct Scratch { char path[0x20]; char formatBuffer[0x40]; char imageBuffer[0x40]; } scratch;
    float seconds;
    s32 below;
    s32 *state;
    s32 result;
    s32 mode;
    s32 index;
    u32 row;
    u32 column;
    u32 height;
    u32 width;
    u32 color;
    u32 component;
    u32 pixel;
    s32 exists;
    char *entryName;
    struct Entry *entry;
    struct Texture *texture;
    seconds = (float)KERNEL_GetTimeMs() / lbl_80564C70;
    below = seconds - *(float *)((u8 *)&lbl_8055FA18 + 4) < lbl_8055FA18;
    if (below)
        return;
    seconds = (float)KERNEL_GetTimeMs() / lbl_80564C70;
    state = (s32 *)&lbl_804BE7D8;
    state[1] = 0;
    *(float *)((u8 *)&lbl_8055FA18) = seconds;
    mode = fn_802B6A70(lbl_8055FA38);
    ((s32 (*)(char *, s32, const char *, ...))fn_801345D8)(scratch.imageBuffer, 0x40, lbl_8055CE88, mode);
    result = FileFindFirst(scratch.imageBuffer, scratch.path, 0x20);
    if ((u32)result + 0x10000U != 0xFFFFU) {
        register char *suffix = (char *)lbl_8055CE98;
        do {
            index = state[1];
            entry = (struct Entry *)(*(u32 *)&lbl_804BE7D8 + index * 0x128);
            state[1] = index + 1;
            {
                s32 remaining = 0x20;
                char *dst = entry->name;
                char *src = scratch.path;
                char c;
                goto copy;
                dec:
                if (--remaining <= 0) {
                    dst[-1] = 0;
                    goto done;
                }
                copy:
                c = *src++;
                *dst++ = c;
                if ((signed char)c != 0)
                    goto dec;
                done:;
            }
            if (strchr(entry->name, '.') != 0)
                *strchr(entry->name, '.') = 0;
            entry->height = 0;
            entry->width = 0;
            exists = fn_80128690();
            if ((u8)exists == 0) fn_80128684();
            ((s32 (*)(char *, s32, const char *, ...))fn_801345D8)(scratch.formatBuffer, 0x40, lbl_8055CE90, mode, scratch.path);
            texture = (struct Texture *)fn_802B5240(scratch.formatBuffer);
            if (texture != 0) {
                width = texture->width;
                entry->width = width;
                height = texture->height;
                entry->height = height;
                if ((u32)(width * height) > 0x100U) {
                    width = width > 0x10U ? 0x10 : width;
                    entry->width = width;
                    entry->height = entry->height > 0x10U ? 0x10 : entry->height;
                }
                {
                    u32 byteOffset = 0;
                    for (row = 0; row < entry->width; row++, byteOffset += 4) {
                        for (column = 0; column < entry->height; column++) {
                            pixel = *(u32 *)((u8 *)texture->pixels + byteOffset +
                                ((texture->height - 1 - column) * texture->width * 4));
                            color = (pixel >> 8) & 0xFF;
                            component = pixel & 0xFF;
                            if (component > color) color = component;
                            component = (pixel >> 16) & 0xFF;
                            if (component > color) color = component;
                            component = pixel >> 24;
                            if (component > color) color = component;
                            entry->pixels[row + column * entry->width] = (u8)color;
                        }
                    }
                }
                fn_802B52B4();
            }
            if ((u8)exists == 0) fn_80128678();
            if (entry->width == 0) {
                s32 remaining = 0x20;
                entryName = entry->name;
                while ((signed char)*entryName != 0) {
                    remaining--;
                    entryName++;
                }
                if (remaining > 0) {
                    char *src = suffix;
                    char c2;
                    goto copy2;
                    dec2:
                    if (--remaining <= 0) {
                        entryName[-1] = 0;
                        goto done2;
                    }
                    copy2:
                    c2 = *src++;
                    *entryName++ = c2;
                    if ((signed char)c2 != 0)
                        goto dec2;
                    done2:;
                }
            }
        } while ((state[1] + 1 <= state[2]) &&
                 fn_802E3C24(result, scratch.path, 0x20) != 0);
        FileFind_Close(result);
    }
}
#pragma pop
__declspec(section ".sdata") extern s32 lbl_8055CEA0;
s32 fn_802B6E00(s32 x, s32 y) {
    /* Return 1 if either coordinate lies outside [-0x200, 0x200], else 0. */
    s32 outOfBounds = 0;
    if ((x < -0x200) || (x > 0x200) || (y < -0x200) || (y > 0x200))
        outOfBounds = 1;
    return outOfBounds;
}

s32 fn_802B6E30(void) {
    /* Return a scale/step value based on lbl_8055FA38 (view mode): 2->2, 3->4,
       5->1, 4 or any other value -> 0. */
    switch (lbl_8055FA38) {
    case 2: return 2;
    case 3: return 4;
    case 5: return 1;
    default:
    case 4: return 0;
    }
}

s32 fn_802B6E30(void);
#pragma push
#pragma scheduling on
s16 fn_802B6E7C(s32 base, s32 index, u32 count) {
    /* Compute a 16-bit position: offset `base` by (index - count/2) scaled by fn_802B6E30(). */
    return (s16)(base + ((index - (count >> 1)) * (s16)fn_802B6E30()));
}

s16 fn_802B6ED8(s32 base, s32 index, u32 count) {
    /* Compute a signed 16-bit offset position: center by half the count (>> 1),
     * scale the index delta by fn_802B6E30(), and add to base. */
    return (s16)(base + ((index - (count >> 1)) * (s16)fn_802B6E30()));
}

extern void fn_80204048();
extern void fn_8020404C(void);
/* The terrain viewer's mode-5 overlay, drawn around each brush pass and empty
 * in this build (see fn_802B7518, which reports the sampled cells to it). */
#define beginSampleOverlay fn_80204048 /* open it on the area's world corners */
#define endSampleOverlay   fn_8020404C /* flush it once the pass is done */
#pragma push
#pragma use_lmw_stmw off
void fn_802B6F34(void *arg0, void *arg1, void (*arg2)(s16, s16, u8)) {
    f32 sp[4];
    f32 x, y, adjusted;
    s32 rounded;
    s16 xBase, yBase;
    u32 scale, width, height;
    f32 temp, raw;
    register u32 row, column;

    if (*(s32 *)((u8 *)arg1 + 0x20) != 0) {
        x = *(f32 *)arg0 / lbl_80564C58;
        if (x < lbl_80564C74)
            adjusted = x - lbl_80564C78;
        else
            adjusted = lbl_80564C78 + x;
        rounded = (s32)adjusted;
        scale = fn_802B6E30() - 1;
        xBase = (s16)rounded & ~scale;

        y = *(f32 *)((u8 *)arg0 + 8) / lbl_80564C58;
        if (y < lbl_80564C74)
            adjusted = y - lbl_80564C78;
        else
            adjusted = lbl_80564C78 + y;
        rounded = (s32)adjusted;
        scale = fn_802B6E30() - 1;
        yBase = (s16)rounded & ~scale;
        width = lbl_8055CEA0 * *(u32 *)((u8 *)arg1 + 0x20);
        height = lbl_8055CEA0 * *(u32 *)((u8 *)arg1 + 0x24);
        if (lbl_8055FA38 == 5) {
            temp = lbl_80564C58 * (f32)fn_802B6ED8(yBase, 0, height);
            raw = (f32)fn_802B6E7C(xBase, 0, width);
            sp[2] = lbl_80564C58 * raw;
            sp[3] = temp;
            temp = lbl_80564C58 * (f32)fn_802B6ED8(yBase, height - 1, height);
            raw = (f32)fn_802B6E7C(xBase, width - 1, width);
            sp[1] = temp;
            sp[0] = lbl_80564C58 * raw;
            beginSampleOverlay(&sp[2], &sp[0], raw);
        }

        for (row = 0; row < width; row++) {
            for (column = 0; column < height; column++) {
                s16 xCoord = fn_802B6E7C(xBase, row, width);
                s16 yCoord = fn_802B6E7C(yBase, column, height);
                if (fn_802B6E00(xCoord, yCoord) == 0) {
                    u32 remX, remY, blockX, blockY;
                    s32 pixel;
                    u32 scale = lbl_8055CEA0;
                    blockX = row / scale;
                    blockY = column / scale;
                    remY = column - blockY * scale;
                    remX = row - blockX * scale;

                    if ((remX != 0) || (remY != 0)) {
                        u32 imageWidth = *(u32 *)((u8 *)arg1 + 0x20);
                        u32 nextX = imageWidth - 1;
                        u32 x1 = blockX + 1;
                        u32 nextY;
                        u32 y1;
                        u32 nextRowOffset;
                        u32 rowOffset;

                        if (x1 < nextX)
                            nextX = x1;
                        nextY = *(u32 *)((u8 *)arg1 + 0x24) - 1;
                        y1 = blockY + 1;
                        if (y1 < nextY)
                            nextY = y1;
                        rowOffset = blockY * imageWidth;
                        nextRowOffset = nextY * imageWidth;

                        {
                            f32 fx = (f32)remX / (f32)scale;
                            u32 c00 = *((u8 *)arg1 + 0x28 + blockX + rowOffset);
                            u32 c10 = *((u8 *)arg1 + 0x28 + nextX + rowOffset);
                            int c01 = *((u8 *)arg1 + 0x28 + blockX + nextRowOffset);
                            u32 c11 = *((u8 *)arg1 + 0x28 + nextX + nextRowOffset);
                            f32 top = (f32)c00 + fx * ((f32)c10 - (f32)c00);
                            f32 bottom = (f32)c01 + fx * ((f32)c11 - (f32)c01);
                            pixel = (s32)(top + ((f32)remY / (f32)scale) * (bottom - top));
                        }
                    } else {
                        u32 imageWidth = *(u32 *)((u8 *)arg1 + 0x20);
                        pixel = *((u8 *)arg1 + 0x28 + blockX + blockY * imageWidth);
                    }
                    arg2(xCoord, yCoord, (u8)pixel);
                }
            }
        }

        if (lbl_8055FA38 == 5)
            endSampleOverlay();
    }
}
#undef beginSampleOverlay
#undef endSampleOverlay
#pragma scheduling invalid_target
s32 fn_802B7300(s16 x, s16 y, s32 arg2, s32 arg3, f32 farg0) {
    extern float lbl_80564C74;
    extern float lbl_80564C78;
    extern float lbl_80564C88;
    extern s32 fn_801E41D8(void *, void *, s32, f32);
    f32 points[6];
    f32 height;
    f32 y1;
    register u32 alpha;
    f32 scale;
    s16 scaleValue;
    int color;
    register f32 x1;

    points[3] = x1;
    x1 = lbl_80564C88 + (f32)x * lbl_80564C58;
    points[4] = lbl_80564C74;
    y1 = lbl_80564C88 + (f32)y * lbl_80564C58;
    points[5] = y1;
    height = lbl_80564C78 + fn_801DCF48(0, x1, y1);

    *(u32 *)&points[0] = *(u32 *)&points[3];
    points[4] = height;
    *(u32 *)&points[1] = *(u32 *)&points[4];
    *(u32 *)&points[2] = *(u32 *)&points[5];
    points[4] = height + farg0;

    scaleValue = (s16)fn_802B6E30();
    scale = lbl_80564C88 * (f32)scaleValue;

    color = arg2;
    alpha = (u32)arg3;
    if (arg2 == 0) {
        alpha = 0xFF000000u;
        color = 0x20u;
    }
    return fn_801E41D8(&points[3], &points[0],
                 (alpha & 0xFFFFFFu) | (color << 24), scale);
}
extern float lbl_80564C8C;
extern double lbl_80564C80;
extern float lbl_80564C90;
extern float lbl_80564C94;
extern s32 fn_802BC09C();
extern void fn_80204044();
extern s32 fn_802C21DC();
extern s32 fn_802B7300(s16, s16, s32, s32, float);
void fn_802B7420(s16 x, s16 y, s32 value) {
    /* Render callback: draw a terrain-debug marker at grid cell (x, y) with the default 0.2 scale. */
    fn_802B7300(x, y, value, -1, lbl_80564C8C);
}

extern s16 lbl_8055FA50[4];
extern s32 fn_802BE8B4(s16, s16, s16);
#pragma use_lmw_stmw off
/* Subdivide the world grid at increasing block sizes (4..64) and submit any
 * block overlapping the current bounds in lbl_8055FA50 for rebuild when the
 * terrain mode is 2. */
void fn_802B7434(void) {
    s32 endX, endY, xMinusSize, start, step;
    s16 size, x, y;

    if (lbl_8055FA38 != 2)
        return;
    for (size = 4; size <= 0x40; size *= 2) {
        start = size - 0x200;
        x = (s16)start;
        endX = x + size;
        step = size * 2;
        while (x < 0x200) {
            y = (s16)start;
            endY = y + size;
            xMinusSize = x - size;
            while (y < 0x200) {
                if (xMinusSize <= lbl_8055FA50[1] &&
                    endX >= lbl_8055FA50[0] &&
                    y - size <= lbl_8055FA50[3] &&
                    endY >= lbl_8055FA50[2]) {
                    fn_802BE8B4(x, y, size);
                }
                {
                    s32 nextY = y + step;
                    endY += step;
                    y = (s16)nextY;
                }
            }
            {
                s32 nextX = x + step;
                endX += step;
                x = (s16)nextX;
            }
        }
    }
}
#pragma push
#pragma scheduling invalid_target
/* "tedash.val" debug viewer: the brush callback handed to fn_802B6F34(), which
 * walks the terrain grid around the brush and reports each bilinearly sampled
 * byte.  What becomes of the sample depends on the view mode:
 *   2 Material-Map - paint the selected water layer at full strength, blended by
 *     sample/255.  A cell that accepts the paint widens the dirty rectangle the
 *     block rebuild of fn_802B7434() scans; a cell that refuses it gets a red
 *     marker whose alpha is the sample instead.
 *   3 Road-Opacity - plot the sample as one pixel of the road-opacity image.
 *   5 (unnamed mode, grid step 1) - report the sample together with the cell's
 *     world position to a debug-draw hook, an empty stub in this build.
 * Every other mode ignores the sample. */
#define viewMode       lbl_8055FA38 /* 0 "Objects", 1 "Advanced", 2 "Material-Map", 3 "Road-Opacity" */
#define brushLayer     lbl_8055FA28 /* water layer the viewer paints, from its drop-down */
#define dirtyBounds    lbl_8055FA50 /* s16[4]: minX, maxX, minY, maxY painted since the last rebuild */
#define paintLayer     fn_802BC09C  /* blend a value into one cell of a water layer */
#define drawMarker     fn_802B7300  /* draw a terrain marker at a grid cell */
#define plotPixel      fn_802C21DC  /* write one pixel of the road-opacity image */
#define drawWorldPoint fn_80204044  /* debug-draw hook: empty in this build */
#define kSampleFull    lbl_80564C90 /* 255.0f: the sample of a fully applied brush stroke */
#define kMarkerSize    lbl_80564C94 /* 3.0f: size of the marker for a refused cell */
#define kGridStep      lbl_80564C58 /* 2.0f: world units per grid cell */
void fn_802B7518(s16 x, s16 y, s32 sample) {
    switch (viewMode) {
    case 2:
        if (sample != 0) {
            /* Paint at full strength, blended by how strong the sample is.
             * The cast keeps that blend a float: paintLayer is declared
             * without a prototype above. */
            if (((s32 (*)(s32, s32, s32, s32, f32))paintLayer)(
                    x, y, brushLayer, 0xFF,
                    (f32)(u32)sample / kSampleFull)) {
                dirtyBounds[0] = (dirtyBounds[0] < x) ? dirtyBounds[0] : x;
                dirtyBounds[1] = (dirtyBounds[1] > x) ? dirtyBounds[1] : x;
                dirtyBounds[2] = (dirtyBounds[2] < y) ? dirtyBounds[2] : y;
                dirtyBounds[3] = (dirtyBounds[3] > y) ? dirtyBounds[3] : y;
            } else {
                drawMarker(x, y, sample, (s32)0xFFFF0000, kMarkerSize);
            }
        }
        break;
    case 3:
        /* Called through a prototype-less declaration, so the pixel writer
         * reads x, y and the sample from the registers they arrived in. */
        plotPixel();
        break;
    case 5:
    {
        f32 worldX = (f32)x * kGridStep;
        f32 worldY = (f32)y * kGridStep;
        drawWorldPoint(sample, worldX, worldY);
    }
        break;
    }
}
#undef viewMode
#undef brushLayer
#undef dirtyBounds
#undef paintLayer
#undef drawMarker
#undef plotPixel
#undef drawWorldPoint
#undef kSampleFull
#undef kMarkerSize
#undef kGridStep
#pragma pop
extern float lbl_8055FA20[];
#pragma small_data on
__declspec(section ".sdata") extern float lbl_8055FA20[];
#pragma small_data on
#pragma small_data off
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Return 1 and update the stored timer once the elapsed seconds since the
 * previous timestamp exceeds the configured threshold; otherwise return 0. */
s32 fn_802B7694(void) {
    s32 triggered = 0;
    f32 elapsedSeconds = (f32)KERNEL_GetTimeMs() / lbl_80564C70;
    s32 belowThreshold = elapsedSeconds - lbl_8055FA20[1] < lbl_8055FA20[0];

    if (!belowThreshold) {
        f32 currentSeconds = (f32)KERNEL_GetTimeMs() / lbl_80564C70;
        triggered = 1;
        lbl_8055FA20[0] = currentSeconds;
    }
    return triggered;
}

#pragma optimization_level 2
void fn_802B773C(void) {
    struct StateBuf {
        s32 f0;
        s32 f1;
        s32 f2;
        s32 f3;
        u8 pad[0x24];
        s8 f34;
    };
    struct TblHeader {
        s32 entries;
        s32 count;
    };
    f32 sp8[3];
    struct StateBuf *state = (struct StateBuf *)lbl_804BFF80;
    u8 previous = lbl_8055FA58;

    lbl_8055FA58 = 0;
    if (state->f34 != 0)
        return;
    if (lbl_8055FA2C < 0)
        return;
    if (lbl_8055FA2C >= ((struct TblHeader *)&lbl_804BE7D8)->count)
        return;
    if (fn_80204054(sp8, 0, 0, DrawList_getCurrentMatrix(), state->f1, state->f2) == 0)
        return;

    if (state->f3 & 1) {
        if (state->f0 != 0 && previous == 0)
            return;
        lbl_8055FA58 = 1;
        if (((s32 (*)(void *))fn_802B7694)(sp8) == 0)
            return;
        lbl_8055FA50[0] = 0x400;
        lbl_8055FA50[2] = 0x400;
        lbl_8055FA50[3] = -0x400;
        lbl_8055FA50[1] = -0x400;
        fn_802B6F34(sp8,
                    (u8 *)(lbl_804BE7D8 + lbl_8055FA2C * 0x128),
                    (void (*)(s16, s16, u8))fn_802B7518);
        fn_802B7434();
    } else if ((state->f3 & 2) == 0) {
        fn_802B6F34(sp8,
                    (u8 *)(lbl_804BE7D8 + lbl_8055FA2C * 0x128),
                    (void (*)(s16, s16, u8))fn_802B7420);
    }
}
#pragma optimization_level reset
extern s32 fn_802B6270(void);
#pragma cplusplus on
extern "C" void fn_802B7884(void *arg0) {
    class Dummy {
    public:
        virtual void v0();
        virtual void *call(const char *);
    };
    register char *base = lbl_8034A598;
    register void *saved = arg0;
    Dummy *obj = (Dummy *)lbl_8055FA48;
    void *result = obj->call(base + 0x144);
    formatDebugTextEntry(result, (const char *)saved);
    char *selection = fn_802B6270() ? base + 0x288 : base + 0x294;
    obj = (Dummy *)lbl_8055FA48;
    result = obj->call(base + 0x150);
    formatDebugTextEntry(result, selection);
}

#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_802B7918(void) {
    /* Refresh the brush column of the "tedash.val" debug panel.
     *
     * lbl_8055FA48 is the panel root; virtual +0x04 looks a pane up by name and
     * +0x0C looks a data object up by name.  Used here:
     *   "matmap_col" - object whose +0x14 float is one row's vertical step
     *   kBrushColumn - the column whose own 0x20-byte row is the template that
     *                  formatDebugTextEntry()/fn_80147230() write each line into
     *   kBrushDropdown - the drop-down whose caption is set to "Brushes"
     * lbl_804BE7D8 is the brush list { entries; count; capacity }; every entry is
     * 0x128 bytes and starts with the file name fn_802B6AC0() read off disk.
     * lbl_8055FA10 is a pair of seconds: [1] a base stamp and [0] the reference
     * time fn_802B6228() stores.  While (now - [1]) is still under [0] the panel
     * rescans with fn_802B6AC0() and lists every brush of the current folder
     * ("kRowFormat" plus the entry name), each pushed down one more row step --
     * or the "none" text when the folder has none.  Past that window only the
     * brush the drop-down selected (lbl_8055FA2C) is shown. */
    class DebugUi {
    public:
        virtual void v0();
        virtual void *findPane(const char *name);   /* vtable +0x04 */
        virtual void v2();
        virtual void *findObject(const char *name); /* vtable +0x0C */
    };
    typedef struct {                /* a debug text row, copied from the column */
        void *name;                 /* +0x00 row name, matched by formatDebugTextEntry */
        s32 value;                  /* +0x04 */
        s32 unk8;                   /* +0x08 f32 row position */
        s32 unkC;                   /* +0x0C */
        f32 time;                   /* +0x10 */
        s32 unk14;                  /* +0x14 */
        s32 unk18;                  /* +0x18 text colour, set by formatDebugTextEntry */
        s32 unk1C;                  /* +0x1C */
    } DebugRow;

#define kMatmapCol      (base + 0x2A0) /* "matmap_col": +0x14 is one row's step */
#define kBrushColumn    (base + 0x2AC) /* column holding the row template */
#define kBrushDropdown  (base + 0xC8)  /* drop-down relabelled "Brushes" */
#define kRowFormat      (base + 0x2B8) /* "%d" label put on each row */
#define kNoBrushes      (base + 0x2C4) /* shown when the list is empty */
#define kNoSelection    (base + 0x2D0) /* shown when the index is out of range */
#define kBrushesCaption lbl_8055CEA8   /* "Brushes" */
#define kFormatS        lbl_8055CE70   /* "%s" */
#define kPanelRoot      lbl_8055FA48   /* the "tedash.val" debug panel */
#define kBrushList      lbl_804BE7D8   /* { entries; count; capacity }, 0x128 each */
#define kSelectedBrush  lbl_8055FA2C   /* brush picked from the drop-down */
#define kRefSeconds     lbl_8055FA10   /* reference time, fn_802B6228() */
#define kBaseSeconds    ((f32 *)&lbl_8055FA10)[1] /* base stamp */
#define kMsPerSecond    lbl_80564C70   /* 1000.0f */

    char *base = lbl_8034A598;
    s32 rowOffset;
    s32 i;
    s32 brushCount;
    DebugUi *uiRoot = (DebugUi *)kPanelRoot;
    void *object;
    volatile const u8 *rowBytes;
    f32 rowStep;
    f32 elapsed;
    s32 withinWindow;
    s32 rowBits;
    s32 rowValue;
    s32 index;
    void *selected;
    DebugRow row;
    char label[0x20];

    object = uiRoot->findObject(kMatmapCol);
    rowStep = *(f32 *)((u8 *)object + 0x14);
    uiRoot = (DebugUi *)kPanelRoot;
    object = uiRoot->findPane(kBrushColumn);
    rowBytes = (volatile const u8 *)object;
    row.name = *(void * volatile *)(rowBytes + 0);
    rowValue = *(volatile const s32 *)(rowBytes + 4);
    rowBits = *(volatile const s32 *)(rowBytes + 8);
    row.value = rowValue;
    row.unk8 = rowBits;
    row.unkC = *(volatile const s32 *)(rowBytes + 0xC);
    row.time = *(volatile const f32 *)(rowBytes + 0x10);
    row.unk14 = *(volatile const s32 *)(rowBytes + 0x14);
    row.unk18 = *(volatile const s32 *)(rowBytes + 0x18);
    row.unk1C = *(volatile const s32 *)(rowBytes + 0x1C);
    uiRoot = (DebugUi *)kPanelRoot;
    object = uiRoot->findPane(kBrushDropdown);
    formatDebugTextEntry(object, kBrushesCaption);
    elapsed = (f32)KERNEL_GetTimeMs() / kMsPerSecond -
              kBaseSeconds;
    withinWindow = elapsed < kRefSeconds;
    if (withinWindow != 0) {
        /* Still inside the window: rescan, then list every brush of the folder. */
        fn_802B6AC0();
        brushCount = ((s32 *)&kBrushList)[1];
        if (brushCount > 0) {
            i = 0;
            rowOffset = 0;
            while (i < ((s32 *)&kBrushList)[1]) {
                ((void (*)(char *, s32, const char *, ...))fn_801345D8)(
                    label, 0x20, kRowFormat, i);
                row.name = label;
                formatDebugTextEntry(&row, kFormatS,
                            (void *)(*(u32 *)&kBrushList + rowOffset));
                *(f32 *)((u8 *)&row + 8) += rowStep;
                rowOffset += 0x128;
                i++;
            }
        } else {
            fn_80147230(&row, kNoBrushes);
        }
    } else {
        /* Settled: only the brush the drop-down selected. */
        index = kSelectedBrush;
        selected = kNoSelection;
        if (index >= 0 && index < *(s32 *)((u8 *)&kBrushList + 4)) {
            selected = (void *)(*(u32 *)&kBrushList + index * 0x128);
        }
        fn_80147230(&row, kFormatS, selected);
    }

#undef kMatmapCol
#undef kBrushColumn
#undef kBrushDropdown
#undef kRowFormat
#undef kNoBrushes
#undef kNoSelection
#undef kBrushesCaption
#undef kFormatS
#undef kPanelRoot
#undef kBrushList
#undef kSelectedBrush
#undef kRefSeconds
#undef kBaseSeconds
#undef kMsPerSecond
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

extern "C" s32 fn_802B1C14(s32);
extern "C" s32 fn_802B1C1C(s32, s32);
__declspec(section ".sdata") extern const char lbl_8055CEB0[];
/* Debug overlay: rebuild the water-layer list in the "tedash.val" debug panel.
 *
 * lbl_8055FA48 is the panel root; virtual +0x04 looks a pane up by name and
 * +0x0C looks a data object up by name.  Used here:
 *   "matmap_col"   - object whose +0x14 float is one row's vertical step
 *   "layer_dropdown" - the drop-down whose caption is set to "Layers"
 *   "layer_col"    - the column whose own 0x20-byte row is the template that
 *                    formatDebugTextEntry()/fn_80147230() write each line into
 * lbl_8055FA08 is a pair of seconds: [1] a base stamp and [0] the reference
 * time fn_802B61E0() stores.  While (now - [1]) is still under [0] the panel
 * lists every water layer of the current entry ("layer:%d" plus the name
 * fn_802B1C1C() answers), each pushed down one more row step -- or "No Layers"
 * when the entry has none.  Past that window only the selected layer
 * (lbl_8055FA28) is shown. */
s32 fn_802B7B08(void) {
    class DebugUi {
    public:
        virtual void v0();
        virtual void *findPane(const char *name);   /* vtable +0x04 */
        virtual void v2();
        virtual void *findObject(const char *name); /* vtable +0x0C */
    };
    typedef struct {                /* a debug text row, copied from the column */
        void *name;                 /* +0x00 row name, matched by formatDebugTextEntry */
        s32 value;                  /* +0x04 */
        s32 unk8;                   /* +0x08 f32 row position */
        s32 unkC;                   /* +0x0C */
        f32 time;                   /* +0x10 */
        s32 unk14;                  /* +0x14 */
        s32 unk18;                  /* +0x18 text colour, set by formatDebugTextEntry */
        s32 unk1C;                  /* +0x1C */
    } DebugRow;

#define kLayerDropdown (base + 0xB8)   /* "layer_dropdown" */
#define kMatmapCol     (base + 0x2A0)  /* "matmap_col" */
#define kLayerCol      (base + 0x2DC)  /* "layer_col" */
#define kLayerFormat   (base + 0x2E8)  /* "layer:%d" */
#define kNoLayers      (base + 0x2F4)  /* "No Layers" */
#define kLayersCaption lbl_8055CEB0    /* "Layers" */
#define kFormatS       lbl_8055CE70    /* "%s" */
#define kPanelRoot     lbl_8055FA48    /* the "tedash.val" debug panel */
#define kSelectedLayer lbl_8055FA28    /* layer picked from the drop-down */
#define kRefSeconds    lbl_8055FA08    /* reference time, fn_802B61E0() */
#define kBaseSeconds   ((f32 *)&lbl_8055FA08)[1] /* base stamp */
#define kMsPerSecond   lbl_80564C70    /* 1000.0f */

    char *base;
    DebugUi *uiRoot;
    void *object;
    const u8 *rowBytes;
    f32 rowStep;
    f32 elapsed;
    s32 withinWindow;
    s32 layerSet;
    s32 layerCount;
    s32 i;
    s32 rowBits;
    s32 rowValue;
    DebugRow row;
    char label[0x20];

    base = lbl_8034A598;
    uiRoot = (DebugUi *)kPanelRoot;
    object = uiRoot->findObject(kMatmapCol);
    rowStep = *(f32 *)((u8 *)object + 0x14);
    uiRoot = (DebugUi *)kPanelRoot;
    object = uiRoot->findPane(kLayerDropdown);
    formatDebugTextEntry(object, kLayersCaption);
    uiRoot = (DebugUi *)kPanelRoot;
    object = uiRoot->findPane(kLayerCol);
    rowBytes = (const u8 *)object;
    row.name = *(void **)(rowBytes + 0);
    rowValue = *(volatile s32 *)(rowBytes + 4);
    rowBits = *(volatile s32 *)(rowBytes + 8);
    row.value = rowValue; row.unk8 = rowBits;
    row.unkC = *(s32 *)(rowBytes + 0xC);
    row.time = *(f32 *)(rowBytes + 0x10);
    row.unk14 = *(s32 *)(rowBytes + 0x14);
    row.unk18 = *(s32 *)(rowBytes + 0x18);
    row.unk1C = *(s32 *)(rowBytes + 0x1C);
    elapsed = (f32)KERNEL_GetTimeMs() / kMsPerSecond - kBaseSeconds;
    withinWindow = elapsed < kRefSeconds;
    if (withinWindow != 0) {
        /* Still inside the window: list every water layer of this entry. */
        void *entry = ((void *(*)(void))fn_802B5B6C)();
        layerSet = *(s32 *)((u8 *)entry + 4);
        layerCount = fn_802B1C14(layerSet);
        if (layerCount > 0) {
            i = 0;
            while (i < fn_802B1C14(layerSet)) {
                ((void (*)(void *, s32, const char *, ...))fn_801345D8)(label, 0x20, kLayerFormat, i);
                row.name = label;
                formatDebugTextEntry(&row, kFormatS, fn_802B1C1C(layerSet, i));
                *(f32 *)((u8 *)&row + 8) += rowStep;
                i++;
            }
        } else { fn_80147230(&row, kNoLayers); }
    } else {
        /* Settled: only the layer the drop-down selected. */
        void *entry = ((void *(*)(void))fn_802B5B6C)();
        fn_80147230(&row, kFormatS, fn_802B1C1C(*(s32 *)((u8 *)entry + 4), kSelectedLayer));
    }

#undef kLayerDropdown
#undef kMatmapCol
#undef kLayerCol
#undef kLayerFormat
#undef kNoLayers
#undef kLayersCaption
#undef kFormatS
#undef kPanelRoot
#undef kSelectedLayer
#undef kRefSeconds
#undef kBaseSeconds
#undef kMsPerSecond
}

#pragma cplusplus reset

extern void lbl_8034A898(void);
void fn_802B7884(void *);
void fn_802B7918(void);
void fn_802B7CF0(void) {
    /* Build the "Save Road-Opacity Map" debug panel: wire the save control, then set up the record list. */
    fn_802B7884(lbl_8034A898);
    fn_802B7918();
}

void fn_802B7D1C(void) {
    /* Build the "tedash.val" debug panel: wire the Save-Material-Maps control, then set up the brush and layer columns. */
    fn_802B7884(lbl_8034A8B0);
    fn_802B7918();
    fn_802B7B08();
}

#pragma cplusplus on
extern "C" void fn_802B7D4C(void) {
    class Dummy {
    public:
        virtual void v0();
        virtual void *call(const char *);
        virtual void v2();
        virtual void *get(const char *);
    };
    s32 workspace[51];
    s32 selected[3];
    u8 *state;
    MenuRenderCopy first, second;
    char name[32];
    MenuRenderCopy line, line2;
    register char *base = lbl_8034A598;
    void *object;
    void *(*lookup)(void *, const char *);
    void *(*get)(void *, const char *);
    const char *status;
    f32 step;
    s32 offset, i;
    s32 *entry;

    if (lbl_8055FA40 == 6) {

        formatDebugTextEntry(((Dummy *)lbl_8055FA48)->call(lbl_8055CE68), base + 0x32C);
        return;
    }
    object = ((void *(*)(void))fn_802B5B6C)();
    workspace[1] = 0;
    state = 0;
    workspace[2] = 16;
    workspace[0] = (s32)&workspace[3];
    fn_802B321C((s32)workspace, (void **)&state, *(s32 *)((u8 *)object + 8), lbl_8055FA40);
    status = base + 0x338;
    if (*state != 0) status = lbl_8055CEB8;

    formatDebugTextEntry(((Dummy *)lbl_8055FA48)->call(base + 0x118), lbl_8055CE70, status);

    object = ((Dummy *)lbl_8055FA48)->call(base + 0x344);
    first.name = *(void **)object;
    ((s32 *)&first)[1] = ((s32 *)object)[1];
    ((s32 *)&first)[2] = ((s32 *)object)[2];
    first.unkC = ((s32 *)object)[3];
    first.unk10 = ((f32 *)object)[4];
    first.unk14 = ((s32 *)object)[5];
    first.unk18 = ((s32 *)object)[6];
    first.unk1C = ((s32 *)object)[7];

    object = ((Dummy *)lbl_8055FA48)->call(base + 0x354);
    second.name = *(void **)object;
    ((s32 *)&second)[1] = ((s32 *)object)[1];
    ((s32 *)&second)[2] = ((s32 *)object)[2];
    second.unkC = ((s32 *)object)[3];
    second.unk10 = ((f32 *)object)[4];
    second.unk14 = ((s32 *)object)[5];
    second.unk18 = ((s32 *)object)[6];
    second.unk1C = ((s32 *)object)[7];

    step = *(f32 *)((u8 *)((Dummy *)lbl_8055FA48)->get(base + 0x238) + 0x14);
    i = 0;
    offset = 0;
    for (; i < workspace[1]; ++i) {
        entry = (s32 *)((u8 *)workspace[0] + offset);
        ((void (*)(char *, s32, const char *, ...))(s32 (*)(char *, s32, const char *, s32))fn_801345D8)(name, 32, base + 0x360, i);
        line.pair = first.pair;
        line.unkC = first.unkC;
        line.unk10 = first.unk10;
        line.unk14 = first.unk14;
        line.unk18 = first.unk18;
        line.unk1C = first.unk1C;
        line.name = name;
        *(f32 *)((u8 *)&line + 8) += step * (f32)i;
        formatDebugTextEntry(&line, lbl_8055CE74, **(void ***)(entry + 1));
        line2.pair = second.pair;
        line2.unkC = second.unkC;
        line2.unk10 = second.unk10;
        line2.unk14 = second.unk14;
        line2.unk18 = second.unk18;
        line2.unk1C = second.unk1C;
        line2.name = name;
        *(f32 *)((u8 *)&line2 + 8) += step * (f32)i;
        formatDebugTextEntry(&line2, lbl_8055CE70, (void *)entry[0]);
        offset += 12;
    }
    if (fn_802B5B74(selected)) {
        fn_802B67C8((s32)(base + 0x36C));

        fn_801476C4(((Dummy *)lbl_8055FA48)->call(base + 0x378));
        fn_801473F8(lbl_8055FA48, base + 0x384, lbl_8055CE70, selected[0]);

        formatDebugTextEntry(((Dummy *)lbl_8055FA48)->call(base + 0x390), lbl_8055CEC0, ((f32 *)selected[2])[0]);

        formatDebugTextEntry(((Dummy *)lbl_8055FA48)->call(base + 0x3A0), lbl_8055CEC0, ((f32 *)selected[2])[1]);
    }

    formatDebugTextEntry(((Dummy *)lbl_8055FA48)->call(lbl_8055CE68), base + 0x3B0, lbl_8055FA40 + 1);
    workspace[0] = 0;
    workspace[1] = 0;
    workspace[2] = 0;
}
#pragma cplusplus reset
#pragma opt_common_subs off
s32 fn_802B8110(u32 arg0, s32 arg1)
{
  s32 *new_var;
  struct Work
  {
    s32 *items;
    s32 count;
    s32 capacity;
    s32 entries[51];
  } work;
  void *temp_r3;
  s32 var_r30;
  s32 *temp_r6;
  s32 temp_r29;
  s32 temp_r3_2;
  s32 temp_r3_3;
  s32 temp_r4;
  s32 temp_r5;
  s32 var_r0;
  s32 var_r0_2;
  var_r30 = 0;
  temp_r29 = fn_802B5D94(arg1);
  temp_r3 = ((void *(*)(void)) fn_802B5B6C)();
  work.items = work.entries;
  work.capacity = 0x10;
  work.count = 0;
  new_var = (s32 *) (((u8 *) temp_r3) + 8);
  ((void (*)(void *, s32, s32, s32)) fn_802B321C)(&work.items, 0, *new_var, lbl_8055FA40);
  temp_r6 = *((s32 **) ((((u8 *) (&work)->items) + (temp_r29 * 0xC)) + 4));
  temp_r4 = *temp_r6;
  var_r0 = 0x80;
  temp_r3_2 = arg0 >> 31;
  temp_r5 = temp_r4 + (((s32) (temp_r3_2 + arg0)) >> 1);
  temp_r3_2 = temp_r5 & ((s32) (((-temp_r5) & (~temp_r5)) >> 31));
  if (temp_r3_2 < 0x80)
  {
    var_r0 = temp_r3_2;
  }
  if (temp_r4 != var_r0)
  {
    ;
    var_r0_2 = 0x80;
    if ((temp_r5 & ((s32) (((-temp_r5) & (~temp_r5)) >> 31))) < 0x80)
    {
      var_r0_2 = temp_r3_3;
    }
    *temp_r6 = var_r0_2;
    fn_802B32E0(*new_var);
    fn_802B4E44(*((s32 *) (((u8 *) temp_r3) + 8)));
    var_r30 = 1;
  }
  work.items = 0;
  work.count = 0;
  work.capacity = 0;
  return var_r30;
}
#pragma opt_common_subs reset
#pragma scheduling on
f32 fn_802B822C(s32 frames) {
    // Convert a frame count into a float step, advancing FRAME_STEP (0.05) per frame.
    return FRAME_STEP * (f32)frames;
}

extern s32 fn_802B5B74(void *);
extern f32 fn_802B822C(s32);
extern float lbl_80564C9C;
extern s32 lbl_8055CFF0;
extern s32 lbl_8055CFF4;
/* Adjust the selected item's lower value by the step for deltaIndex, clamping it
 * between 0.05f and the item's upper value, and mark it dirty if it changes. */
s32 fn_802B825C(s32 deltaIndex) {
    struct { s32 pad[2]; float *values; } result;
    float *values;
    float clampedValue;
    float adjustedValue;
    s32 changed = 0;
    if (fn_802B5B74(&result) != 0) {
        values = result.values;
        clampedValue = values[1];
        adjustedValue = values[0] + fn_802B822C(deltaIndex);
        clampedValue = clampedValue < adjustedValue ? clampedValue : adjustedValue;
        clampedValue = clampedValue > FRAME_STEP ? clampedValue : FRAME_STEP;
        if (clampedValue != values[0]) {
            values[0] = clampedValue;
            changed = 1;
            *(volatile u8 *)((u8 *)result.values + 8) = 1;
        }
    }
    return changed;
}

#pragma processor 750
#pragma scheduling 750
/* Adjust the selected item's upper value by the step for deltaIndex, clamping it
 * between the item's lower value and 10.0f, and mark it dirty if it changes. */
s32 fn_802B8310(s32 deltaIndex) {
    struct Result {
        s32 pad[2];
        float *values;
    } result;
    register f32 lowerBound;
    register f32 clampedValue = 10.0f;
    register float *values;
    register s32 changed;
    f32 adjustedValue;
    changed = 0;
    if (fn_802B5B74(&result) != 0) {
        values = result.values;
        lowerBound = values[0];
        adjustedValue = values[1] + fn_802B822C(deltaIndex);
        clampedValue = (clampedValue < adjustedValue) ? clampedValue : adjustedValue;
        clampedValue = (clampedValue > lowerBound) ? clampedValue : lowerBound;
        if (clampedValue != values[1]) {
            values[1] = clampedValue;
            *(volatile u8 *)((u8 *)result.values + 8) = 1;
            changed = 1;
        }
    }
    return changed;
}
#pragma processor 750
#pragma scheduling reset
void fn_802B83CC(void) {
    const Struct804BFF80 *state = (const Struct804BFF80 *)&lbl_804BFF80;
    Struct804BFF80 *callbackState;
    Fn802B83CCEntry *entry;
    Fn802B83CCEntry *actionEntry;
    s32 difference;
    u32 i;

    if (state->str1[0] == 0)
        return;
    difference = state->unk0[1] - state->unk54[1];
    if (difference == 0)
        return;

    for (i = 0; i < 3; i++) {
        entry = &lbl_8034A95C[i];
        if (entry->name == 0 || strcmp(entry->name, state->str1) != 0) {
            if (entry->predicate == 0 || entry->predicate(state->str1) == 0)
                continue;
        }

        actionEntry = (Fn802B83CCEntry *)(volatile void *)&lbl_8034A95C[i];
        callbackState = (Struct804BFF80 *)&lbl_804BFF80;
        if (actionEntry->action(difference, callbackState->str1) != 0) {
            callbackState->unk54[1] = callbackState->unk0[1];
            callbackState->unk54[0] = *(u32 *)&lbl_804BFF80;
            callbackState->unk54[2] = callbackState->unk0[2];
            callbackState->unk54[3] = callbackState->unk0[3];
            callbackState->unk54[4] = callbackState->unk0[4];
        }
        return;
    }
}
/* Rescale the UI state's X and Y fields from the live framebuffer resolution to the fixed 640x480 reference grid. */
void fn_802B84E4(void *state) {
#define REF_WIDTH  0x280
#define REF_HEIGHT 0x1E0
#define CUR_FB_WIDTH  lbl_8055CFF0
#define CUR_FB_HEIGHT lbl_8055CFF4
    *(s32 *)((u8 *)state + 4) = (*(s32 *)((u8 *)state + 4) * REF_WIDTH) / CUR_FB_WIDTH;
    *(s32 *)((u8 *)state + 8) = (*(s32 *)((u8 *)state + 8) * REF_HEIGHT) / CUR_FB_HEIGHT;
#undef CUR_FB_HEIGHT
#undef CUR_FB_WIDTH
#undef REF_HEIGHT
#undef REF_WIDTH
}

#pragma scheduling invalid_target
s32 fn_802B8510(s32 arg0)
{
  struct Entry
  {
    u8 unk[0x20];
    u32 first;
    u32 second;
    u8 pixels[0x100];
  } copy;
  struct Entry *entry;
  int row;
  u32 col;
  s32 height;
  s32 index;
  if (((u32) (arg0 - 6)) > 1U)
  {
    return;
  }
  index = lbl_8055FA2C;
  if (index < 0)
  {
    return;
  }
  if (index >= (*((s32 *) (((u8 *) (&lbl_804BE7D8)) + 4))))
  {
    return;
  }
  entry = ((struct Entry *) (*((u32 *) (&lbl_804BE7D8)))) + index;
  copy = *entry;
  index = copy.second;
  row = 0;
  entry->first = ((((((((((index & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu;
  height = copy.first;
  entry->second = copy.first;
  while (row < entry->first)
  {
    col = 0;
    while (col < entry->second)
    {
      if (arg0 != 6)
      {
        entry->pixels[row + (col * entry->first)] = (((index - row) - (((((((((1 & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu)) * height) + (col & 0xFF);
      }
      else
      {
        ((0, entry))->pixels[(((((((((row & 0xFF) & 0xFF) & 0xFF) & 0xFFu) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) + (((((((col & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) * entry->first)] = ((height * (row + 1)) - 1) - col;
      }
      col++;
    }

    row++;
  }

}
/* Apply a 5-word UI configuration to the global UI state, recompute layout, apply changes, and refresh. */ 
void fn_802B8624(void *config) {
    #pragma small_data off
    lbl_804BFF80[0] = 8;
    if (config != 0) {
        lbl_804BFF80[0] = *(s32 *)config;
        lbl_804BFF80[1] = ((s32 *)config)[1];
        lbl_804BFF80[2] = ((s32 *)config)[2];
        lbl_804BFF80[3] = ((s32 *)config)[3];
        lbl_804BFF80[4] = ((s32 *)config)[4];
        fn_802B84E4(lbl_804BFF80);
        fn_802B83CC();
        fn_802B8510(lbl_804BFF80[0]);
    }
}
#pragma pop
extern void fn_802B83CC(void);
extern void fn_802B84E4(void *);
extern s32 fn_802B8510(s32);
extern s32 fn_80127A50(void *);
#pragma cplusplus on
class Dummy_802B869C {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int f8();
};
#pragma cplusplus on
extern "C" void fn_802B869C(void) {
    /* Poll for an input event and apply its UI config when the active handler allows it. */
    s32 event[6];
    if (((Dummy_802B869C *)lbl_8055FA48)->f8() == 0) {
        if (fn_80127A50(event) != 0) {
            fn_802B8624(event);
        } else {
            fn_802B8624(0);
        }
    }
}
#pragma cplusplus off

#pragma cplusplus off
#pragma small_data off
void fn_802B86F8(void) {
    /* Clear the shared UI state's secondary name filter (str2); clear its
     * primary filter (str1) too unless the flag bit at +0xC is set. */
    s8 zero = 0;
    s8 value = (s8)((Struct804BFF80 *)&lbl_804BFF80)->str1[0];
    ((Struct804BFF80 *)&lbl_804BFF80)->str2[0] = zero;
    if (value == 0)
        return;
    if (((Struct804BFF80 *)&lbl_804BFF80)->unk0[3] & 1)
        return;
    ((Struct804BFF80 *)&lbl_804BFF80)->str1[0] = zero;
}
s32 fn_802B8728(void) {
    /* Registered update-check callback: true while the state byte at lbl_804BFF80+0x34 is zero. */
    return (s8)*((u8 *)&lbl_804BFF80 + 0x34) == 0;
}

#pragma push
#pragma scheduling on
void fn_802B8744(void) {
    lbl_8055FA48 = (void **)fn_80145E70(lbl_8034A980);
    lbl_8055FA40 = 6;
    *(s32 *)((u8 *)&lbl_804BE7D8 + 4) = 0;
    lbl_8055FA00 = fn_8026E214((void *)fn_802B8728, &lbl_804BE7D8);
    lbl_8055FA34 = -1;
}
#pragma pop
/* Clears the state of this menu/UI system, as run from the startup reset path:
 * hands the camera's update-check callback back to whatever was installed
 * before fn_802B8744() (lbl_8055FA00 holds the one fn_8026E214() returned for
 * us), destroys the UI handler object and its thread (lbl_8055FA48), releases
 * the model we still hold a handle to (lbl_8055FA34, -1 when none) and empties
 * the named-record list at lbl_804BFA70 by zeroing its entry count at +4. */
void fn_802B87A0(void) {
    ((s32 (*)(void *))fn_8026E214)((void *)lbl_8055FA00);
    deleteThreads__6SystemFv((void *)&lbl_8055FA48);
    if (lbl_8055FA34 != -1) {
        ((void (*)(s32))fn_802C6CF8)(lbl_8055FA34);
        lbl_8055FA34 = -1;
    }
    *(s32 *)((u8 *)&lbl_804BFA70 + 4) = 0;
}
#pragma push
#pragma dont_inline on
/* One frame of the "tedash.val" debug viewer while its UI object is up: polls the
 * UI's input events, makes the material set picked by matSetIndex the active one
 * (fn_802B0288() reloads the skagbag field caches when the set changes) and, in
 * every view but "Advanced", narrows the skagbag tables to the object selected in
 * the viewer (skipped while it is on "All Objects"). */
void fn_802B87F4(void) {
#define uiFrame     lbl_8055FA48 /* the "tedash.val" UI object fn_802B8744() creates */
#define viewMode    lbl_8055FA38 /* 0 "Objects", 1 "Advanced", 2 "Material-Map", 3 "Road-Opacity" */
#define matSetIndex lbl_8055FA3C /* which UMatSet (material set) the viewer is on */
#define objectIndex lbl_8055FA40 /* which object it shows; 6 is "All Objects" */
    extern void fn_802B0288(void *matSet); /* fn_802AE588: switch to this material set */
    extern void fn_802B4E3C(s32 object);   /* fn_802B3F6C: object the skagbag tables answer for */

    if (uiFrame != 0) {
        fn_802B869C();
        fn_802B0288((void *)fn_802B59A4(matSetIndex));
        if (viewMode != 1) {
            if (objectIndex != 6) {
                fn_802B4E3C(objectIndex);
            }
        }
    }
#undef uiFrame
#undef viewMode
#undef matSetIndex
#undef objectIndex
}
#pragma pop
extern char lbl_8055FA32;
extern float lbl_80564CA0, lbl_80564CA4;
extern char lbl_8034A6C0[];
extern void fn_802B773C(void), DrawModelInstance(s32), fn_80230B5C(void *), DrawList_loadMatrix(void *);
extern void fn_802C974C(float,float,float), fn_802B86F8(void), fn_802B676C(void), fn_802B6804(void);
extern void fn_802B7D4C(void), fn_802B69FC(void), fn_802B7D1C(void), fn_802B7CF0(void);
extern void fn_8001123C(s32), fn_80011A2C(void);
#pragma cplusplus on
extern "C" void fn_802B8848(void) {
    // One per-frame update of the "tedash.val" debug viewer: mode input, panel refresh and the mode label.
#define uiFrame     lbl_8055FA48 /* the "tedash.val" UI object fn_802B8744() creates */
#define viewMode    lbl_8055FA38 /* 0 "Objects", 1 "Advanced", 2 "Material-Map", 3 "Road-Opacity" */
    class UiFrame {
    public:
        virtual void v0();
        virtual void *v1(const char *);
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
    };
    s32 scratch[12], label;
    if (uiFrame != 0) {
        if ((u32)(viewMode - 2) <= 1U) fn_802B773C();
        if ((u8)lbl_8055FA32 != 0 && lbl_8055FA34 != -1) DrawModelInstance(lbl_8055FA34);
        fn_80230B5C(scratch); DrawList_loadMatrix(scratch);
        fn_802C974C(lbl_80564CA0, lbl_80564C70, lbl_80564CA4);
        fn_802B86F8(); fn_802B676C();
        if (viewMode != 2 && viewMode != 3) fn_802B6804();
        switch (viewMode) { case 0: fn_802B7D4C(); break; case 1: fn_802B69FC(); break; case 2: fn_802B7D1C(); break; case 3: fn_802B7CF0(); break; }
        label = fn_802B5B18(viewMode % 4);
        formatDebugTextEntry(((UiFrame *)uiFrame)->v1(lbl_8034A6C0), (const char *)label);
        ((UiFrame *)uiFrame)->v5();
        fn_8001123C(0); fn_80011A2C();
    }
#undef uiFrame
#undef viewMode
}
#pragma cplusplus reset
extern char lbl_8055FA59;
#pragma push
#pragma small_data off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_802B8998(s32 inputId) {
    struct Handler {
        virtual void method0();
        virtual void method2();
        virtual void method1();
        virtual void method3();
        virtual void method4();
        virtual void method5();
        virtual void method6();
        virtual void method7();
        virtual void method8();
    };

    /* Handles UI/menu input events while a handler is active: processes navigation/selection
       cases (0x125/0x127), dispatches virtual actions for 0x5/0x73, triggers mode changes, toggles
       flags for 0x6e/0x77, and returns 1 when handled or 0 for unrecognized input. */
    if (lbl_8055FA48) {
        switch (inputId) {
        case 0x125:
        case 0x127:
            if (lbl_8055FA38 == 0)
                fn_802B5C24(inputId == 0x125U ? -1 : 1);
            *(s32 *)&lbl_804BFF80 = 8;
            *(u8 *)((u8 *)&lbl_804BFF80 + 0x34) = 0;
            *(s32 *)&lbl_8055FA44 = -1;
            *(u8 *)((u8 *)&lbl_804BFF80 + 0x14) = 0;
            break;
        case 0x5:
            ((Handler *)(void *)lbl_8055FA48)->method6();
            break;
        case 0x65:
            fn_802B8510(6);
            break;
        case 0x6d:
            break;
        case 0x73:
            ((Handler *)(void *)lbl_8055FA48)->method8();
            break;
        case 0x6e:
            lbl_8055FA59 = ((u8)lbl_8055FA59 == 0);
            break;
        case 0x77:
            lbl_8055FA32 = ((u8)lbl_8055FA32 == 0);
            break;
        default:
            return 0;
        }
        return 1;
    }
    return 0;
}
#pragma cplusplus reset
#pragma pop
void fn_802B8AE0(const char *arg0, s32 arg1)
{
  struct Local
  {
    char name[32];
    volatile s32 savedArg;
    volatile s32 zero;
  } local;
  s32 count;
  s32 off;
  char *base;
  char *dst;
  volatile u8 *src;
  s32 n;
  u8 b0;
  u8 b1;
  u8 b2;
  u8 b3;
  u8 b4;
  u8 b5;
  u8 b6;
  u8 b7;
  u8 b8;
  u8 b9;
  u8 b10;
  u8 b11;
  u8 b12;
  u8 b13;
  u8 b14;
  u8 b15;
  u8 b16;
  u8 b17;
  u8 b18;
  u8 b19;
  u8 b20;
  u8 b21;
  u8 b22;
  u8 b23;
  u8 b24;
  u8 b25;
  u8 b26;
  u8 b27;
  u8 b28;
  u8 b29;
  u8 b30;
  u8 b31;
  if (fn_802B05E4() != 0)
  {
    return;
  }
  {
    const char *sp = arg0;
    char *dp = local.name;
    n = 0x20;
    while ((*dp++ = *sp++) != 0)
    {
      if ((--n) <= 0)
      {
        dp[-1] = 0;
        break;
      }
    }
  }
  src = (volatile u8 *) local.name;

  b0 = src[0];
  base = *(char * volatile *) (&lbl_804BFA70);
  count = *(volatile s32 *) (((u8 *) (&lbl_804BFA70)) + 4);
  b1 = src[1];
  b2 = src[2];
  b3 = src[3];
  b4 = src[4];
  *(volatile s32 *) (((u8 *) (&lbl_804BFA70)) + 4) = count + 1;
  b5 = src[5];
  off = count * 0x28;
  dst = base + off;
  dst[0] = b0;
  b6 = src[6];
  dst[1] = b1;
  b7 = src[7];
  dst[2] = b2;
  b8 = src[8];
  dst[3] = b3;
  b9 = src[9];
  dst[4] = b4;
  b10 = src[10];
  dst[5] = b5;
  b11 = src[11];
  dst[6] = b6;
  b12 = src[12];
  dst[7] = b7;
  b13 = src[13];
  dst[8] = b8;
  b14 = src[14];
  dst[9] = b9;
  b15 = src[15];
  dst[10] = b10;
  b16 = src[16];
  dst[11] = b11;
  b17 = src[17];
  dst[12] = b12;
  b18 = src[18];
  dst[13] = b13;
  b19 = src[19];
  dst[14] = b14;
  b20 = src[20];
  dst[15] = b15;
  b21 = src[21];
  dst[16] = b16;
  b22 = src[22];
  dst[17] = b17;
  b23 = src[23];
  dst[18] = b18;
  b24 = src[24];
  dst[19] = b19;
  b25 = src[25];
  dst[20] = b20;
  b26 = src[26];
  dst[21] = b21;
  b27 = src[27];
  dst[22] = b22;
  b28 = src[28];
  dst[23] = b23;
  b29 = src[29];
  dst[24] = b24;
  b30 = src[30];
  dst[25] = b25;
  b31 = src[31];
  (base + off)[26] = b26;
  (base + off)[27] = b27;
  (base + off)[28] = b28;
  (base + off)[29] = b29;
  (base + off)[30] = b30;
  (base + off)[31] = b31;
  *((s32 *) ((base + off) + 0x20)) = arg1;
  local.savedArg = arg1;
  local.zero = 0;
  *((s32 *) ((base + off) + 0x24)) = 0;
}
#pragma small_data on
extern s32 lbl_8055CEA0;
void fn_802B8C88(void) {
    /* Enable this menu renderer: set the active flag and reset the block scale to 1. */
    #define sRenderEnabled lbl_8055FA31
    #define sBlockScale    lbl_8055CEA0
    sRenderEnabled = 1;
    sBlockScale = 1;
    #undef sRenderEnabled
    #undef sBlockScale
}

#pragma small_data on
/* Disable this menu renderer by clearing its active flag (counterpart of fn_802B8C88). */
void fn_802B8C98(void) {
    lbl_8055FA31 = 0;
}
struct Texture802B { s32 width; s32 height; u32 *pixels; };
struct Entry802B { char name[0x20]; s32 width; s32 height; char pixels[1]; };
struct Entries802B { s32 pad; s32 count; struct Entry802B *entries; };

