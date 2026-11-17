// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;
extern s32 fn_801333E8(s32, const u8 *, u8 *, u8 *);
extern const u8 lbl_803462A8[];
extern const u8 lbl_80346048[];
extern s32 lbl_8055F434;
extern s32 lbl_8055C440;
extern f32 lbl_80563BC8;
extern s32 fn_80230E90(s32);
extern f32 fn_8023659C(void);
extern s32 fn_80214AF0(s32);
extern s32 fn_80128668(void);
extern s32 fn_80131234(const u8 *name); /* resource/text lookup by name */
extern void fn_8022BAD0(s32 style, s32 x, s32 y, s32 w, s32 h, s32 param5, s32 text, s32 index, s32 flags, f32 scale);
extern s32 fn_802328D4(s32);
extern const u8 lbl_80346324[];
extern const u8 lbl_80346120[];
extern f32 lbl_80563BD4;
s32 fn_80262F8C(s32 ptr, s32 count) {
    /* Free ptr via the mode-3 pool allocator when it is non-null and count is positive; return ptr unchanged. */
    if (ptr != 0 && count > 0) {
        fn_80128668();
    }
    return ptr;
}

void fn_80262FCC(void *arg0) {
    /* Initialize this object's timer field at 0x18, clear the flag at 0x1C, and hide UI group 0x1D. */
    *(f32 *)((u8 *)arg0 + 0x18) = fn_8023659C();
    *((u8 *)arg0 + 0x1C) = 0;
    fn_80214A9C(0x1D);
}

/* If the current time is before the stored start time or more than lbl_80563BC8
 * seconds after it, marks this object expired (+0x1C) and signals event 0x1D. */
void fn_8026300C(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f1 = fn_8023659C();
    temp_f0 = *(f32 *)((u8 *)arg0 + 0x18);
    if ((temp_f1 < temp_f0) || ((temp_f1 - temp_f0) > lbl_80563BC8)) {
        *((u8 *)arg0 + 0x1C) = 1;
    }
    if (*((u8 *)arg0 + 0x1C) != 0) {
        fn_80214AF0(0x1D);
    }
}

/* Return nonzero while this timed object's flag at +0x1C is clear (it has not expired); fn_8026300C sets that flag when the timer at +0x18 runs out. */
s32 fn_80263070(void *obj) {
    return *((u8 *)obj + 0x1C) == 0;
}

s32 fn_80263080(void) {
#define menuPageIndex lbl_8055F434
#define Menu_RefreshState fn_80230E90
    /* Decrement the menu page index, clamping at 0, then refresh the menu state. */
    s32 newPageIndex;
    newPageIndex = menuPageIndex - 1;
    menuPageIndex = newPageIndex;
    if (newPageIndex < 0) {
        menuPageIndex = 0;
    }
    Menu_RefreshState(0);
#undef menuPageIndex
#undef Menu_RefreshState
    return 0;
}

s32 fn_802630C0(void) {
    /* Advances the menu page index by one, clamping it to the maximum, then refreshes menu state. */
#define menuPageIndex lbl_8055F434
#define menuPageMax lbl_8055C440
#define Menu_RefreshState fn_80230E90
    s32 current = menuPageIndex;
    s32 bound = menuPageMax;
    current++;
    menuPageIndex = current;
    if (current > bound) {
        menuPageIndex = bound;
    }
    Menu_RefreshState(0);
#undef menuPageIndex
#undef menuPageMax
#undef Menu_RefreshState
    return 0;
}

extern int fn_80263104(void);
int fn_80263104(void) {
#define menuPageIndex lbl_8055F434
#define menuPageMax lbl_8055C440
    return menuPageIndex == menuPageMax;
#undef menuPageIndex
#undef menuPageMax
}

void fn_8026311C(void) {
    extern s32 fn_80232578(void *);
    extern void *fn_80207848(void *, s32);
    extern const u8 lbl_803462C8[];
    extern const u8 lbl_803460B4[];
    extern const u8 lbl_80346270[];
    extern f32 lbl_80563BD0;
    s32 a;
    s32 b;
    s32 c;
    void *p;
    a = fn_80232578((void *)lbl_803462C8);
    b = fn_80232578((void *)lbl_803462C8);
    c = fn_80232578((void *)lbl_803462C8);
    p = fn_80207848((void *)lbl_80346270, 0);
    (void)a; (void)b; (void)c; (void)p;
    (void)lbl_803460B4; (void)lbl_80563BD0;
}

/* CodeWarrior deleting-destructor helper: free object via Mem_freeObject (fn_80128668)
   when deleteFlag > 0, then return object. */
s32 fn_80263658(s32 object, s32 deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_80263698(void *obj, s32 shouldDelete) {
    /* Destructor-like cleanup for object with vtable at lbl_80346048, then lbl_80346120; optionally frees it. */
    struct VTable_80263698 {
        virtual void destroy(s32);
    };
    if (obj != 0) {
        void *child = *(void **)((char *)obj + 0x30);
        *(void **)obj = (void *)lbl_80346048;
        if (child == 0)
            goto cleanup;
        if (child == 0)
            goto cleanup;
        ((VTable_80263698 *)child)->destroy(1);
    cleanup:
        if (obj != 0) {
            *(void **)obj = (void *)lbl_80346120;
            ((s32 (*)(s32, const u8 *))fn_802328D4)(*(s32 *)((char *)obj + 0x18), lbl_80346120);
            *(s32 *)((char *)obj + 0x18) = 0;
        }
        if (shouldDelete > 0)
            ((void (*)(void *))fn_80128668)(obj);
    }
    return obj;
}
#pragma scheduling on
#pragma cplusplus off
extern const u8 lbl_80346048[];
extern f32 lbl_80563BD8;
extern f32 lbl_80563BE8;
extern f32 lbl_80563BEC;
extern s32 fn_802E2C20(void);
extern s32 fn_802E8528(s32, f32, f32);
/* Destroys this object: installs its vtable, releases the owned resource at +0x18,
 * clears it, and optionally deletes the object; returns this. */
void *fn_80263740(void *this, s32 deleting) {
    if (this != 0) {
        if (this != 0) {
            *(const u8 **)this = lbl_80346120;
            fn_802328D4(*(s32 *)((u8 *)this + 0x18));
            *(s32 *)((u8 *)this + 0x18) = 0;
        }
        if (deleting > 0) ((s32 (*)(void *))fn_80128668)(this);
    }
    return this;
}

/* Destroying destructor: reset vtable, release owned resource at +0x18, and optionally delete. */
void *fn_802637B0(void *obj, s32 doDelete) {
    if (obj != 0) {
        *(const u8 **)obj = lbl_80346120;
        fn_802328D4(*(s32 *)((u8 *)obj + 0x18));
        *(s32 *)((u8 *)obj + 0x18) = 0;
        if (doDelete > 0) ((s32 (*)(void *))fn_80128668)(obj);
    }
    return obj;
}

void fn_8026381C(void) {}

void fn_80263820(void *widget) {
#define menuPageIndex lbl_8055F434
#define menuPageMax lbl_8055C440
    /* Sets this widget's flag at +0x18 to 1 when the current menu page is the last page, else 0. */
    if (menuPageIndex == menuPageMax)
        *(s32 *)((u8 *)widget + 0x18) = 1;
    else
        *(s32 *)((u8 *)widget + 0x18) = 0;
#undef menuPageIndex
#undef menuPageMax
}

#pragma push
#pragma scheduling invalid_target
/* Draws this options-menu row's caption: looks up the localized string
 * "UIOptions:DECIDE" by name and draws it with the text renderer (style 0x12)
 * at the row's rectangle (+0x04 x, +0x08 y, +0x0C/+0x10 size), page index +0x18. */
void fn_80263848(void *widget, s32 arg1) {
    s32 param5;
    s32 height;
    s32 y;
    s32 x;
    s32 labelText;
    void *p = widget;

    param5 = *(s32 *)((char *)p + 0x10);
    height = *(s32 *)((char *)p + 0xC);
    y = *(s32 *)((char *)p + 8);
    x = *(s32 *)((char *)p + 4);
    labelText = fn_80131234(lbl_80346324);
    fn_8022BAD0(0x12, x, y, 0, height, param5, labelText, *(s32 *)((char *)p + 0x18), 0, 1.0f);
}
#pragma pop
void fn_802638C4(void) {}

#pragma scheduling on
/* Handle input for this object: id 0x125 sets flag at +0x28 when +0x29 is set
 * and the flag is clear, id 0x127 clears it when set; returns 0. */
s32 fn_802638C8(void *obj, s32 inputId) {
    if (*((u8 *)obj + 0x29) == 0) goto done;
    if (inputId == 0x126) goto done;
    if (inputId < 0x126) {
        if (inputId < 0x125) goto done;
        goto set_flag;
    }
    if (inputId < 0x128) goto clear_flag;
    goto done;
set_flag:
    if (*((u8 *)obj + 0x28) != 0) goto done;
    *((u8 *)obj + 0x28) = 1;
    goto done;
clear_flag:
    if (*((u8 *)obj + 0x28) == 0) goto done;
    *((u8 *)obj + 0x28) = 0;
done:
    return 0;
}

/* Mirror the current menu page selection into a menu item's two flags: set the
 * s32 at +0x1C and the byte at +0x29 when the item's page id (+0x20) matches
 * lbl_8055F434 (the current page index), clear them otherwise. */
void fn_8026392C(void *item) {
    s32 pageIndex;
    pageIndex = lbl_8055F434;
    if (pageIndex == *(s32 *)((u8 *)item + 0x20)) {
        *(s32 *)((u8 *)item + 0x1C) = 1;
        *((u8 *)item + 0x29) = 1;
    } else {
        *(s32 *)((u8 *)item + 0x1C) = 0;
        *((u8 *)item + 0x29) = 0;
    }
}

#pragma push
#pragma scheduling invalid_target
s32 fn_8026395C(void *item, s32 index) {
    /* Initialize this options-menu item for the "force_feedback" setting: store the
       handle at +0x24 and page id (index*2) at +0x20, then load the option's boolean
       value into +0x28. */
    *(s32 *)((u8 *)item + 0x24) = index;
    *(s32 *)((u8 *)item + 0x20) = index * 2;
    return fn_801333E8(index + 8, lbl_803462A8, (u8 *)item + 0x28, (u8 *)item);
}
#pragma pop
extern s32 fn_80133460(s32, const u8 *, u8, s32);
extern s32 fn_801333E8(s32, const u8 *, u8 *, u8 *);
extern const u8 lbl_803462B8[];
extern const u8 lbl_803462A8[];
extern const u8 lbl_80346280[];
void fn_80263980(void *setting) {
    /* Write this setting's "force_feedback" option: section index + 8, its
     * current byte value at +0x28, and the index itself. */
    s32 index = *(s32 *)((u8 *)setting + 0x24);
    fn_80133460(index + 8, lbl_803462B8, *((u8 *)setting + 0x28), index);
}

extern double lbl_80563BE0;
s32 fn_80263998(void *obj, s32 event) {
    /* Handles events 0x125/0x126/0x127: when enabled, latches state at +0x28
     * and records a start time at +0x2C (ms) on event 0x125. */
    u8 *objBytes = (u8 *)obj;

    if (objBytes[0x29] != 0) {
        switch (event) {
        case 0x125:
            if (objBytes[0x28] == 0) {
                objBytes[0x28] = 1;
                *(f32 *)(objBytes + 0x2C) = (f32)fn_802E2C20() / lbl_80563BD8;
            }
            break;
        case 0x126:
            break;
        case 0x127:
            if (objBytes[0x28] != 0)
                objBytes[0x28] = 0;
            break;
        }
    }

    if (objBytes[0x29] != 0) {
        switch (event) {
        case 0x125:
            if (objBytes[0x28] == 0)
                objBytes[0x28] = 1;
            break;
        case 0x126:
            break;
        case 0x127:
            if (objBytes[0x28] != 0)
                objBytes[0x28] = 0;
            break;
        }
    }

    return 0;
}

#pragma push
#pragma scheduling invalid_target
#pragma fp_contract on
void fn_80263AB4(void *self) {
    /* After fn_802E2C20 ticks (ms) exceed the start time at +0x2C by 0.5s, fades
       the handle at +0x24 to (0,0) via fn_802E8528, else to (1,0). Mirrors active
       selection (lbl_8055F434 == id at +0x20) into flags at +0x1C/+0x29. */
    f32 nowMs = (f32)fn_802E2C20();
    f32 fadeA;
    f32 fadeB;
    s32 handle;

    if (nowMs / lbl_80563BD8 - *(f32 *)((u8 *)self + 0x2C) < lbl_80563BE8) {
        fadeA = lbl_80563BD4;
        fadeB = lbl_80563BEC;
        handle = *(s32 *)((u8 *)self + 0x24);
        ((s32 (*)(s32, f32, f32))fn_802E8528)(handle, fadeA, fadeB);
    } else {
        ((s32 (*)(s32, f32, f32))fn_802E8528)(
            *(s32 *)((u8 *)self + 0x24), lbl_80563BEC, lbl_80563BEC);
    }

    if (lbl_8055F434 == *(s32 *)((u8 *)self + 0x20)) {
        *(s32 *)((u8 *)self + 0x1C) = 1;
        *((u8 *)self + 0x29) = 1;
    } else {
        *(s32 *)((u8 *)self + 0x1C) = 0;
        *((u8 *)self + 0x29) = 0;
    }
}
#pragma pop
extern const u8 lbl_80346280[];
#pragma push
#pragma scheduling invalid_target
void fn_80263B68(void *object, s32 index) {
    /* Stores controller/speaker selection index and updates related fields/bitmask. */
    s32 selectedIndex;
    *(s32 *)((u8 *)object + 0x24) = index;
    *(s32 *)((u8 *)object + 0x20) = (index * 2) + 1;
    ((void (*)(s32, const u8 *, u8 *))fn_801333E8)(index + 8, lbl_80346280, (u8 *)object + 0x28);
    selectedIndex = *(s32 *)((u8 *)object + 0x24);
    *(s32 *)((u8 *)object + 0x2C) |= 1 << selectedIndex;
}
#pragma pop
extern const u8 lbl_80346294[];
void fn_80263BCC(void *setting) {
    /* Write this setting's "controller_speaker" option: section index + 8, its
     * current byte value at +0x28, and the index itself. */
    s32 index = *(s32 *)((u8 *)setting + 0x24);
    fn_80133460(index + 8, lbl_80346294, *((u8 *)setting + 0x28), index);
}

#pragma scheduling invalid_target
/* Handles UI/state events 0x125-0x127 using flags at +0x28, +0x29, and +0x2A. */
s32 fn_80263BE4(void *arg0, s32 event) {
    u8 *state = (u8 *)arg0;

    if (state[0x29] != 0) {
        switch (event) {
        case 0x125:
            if (state[0x28] == 0) {
                state[0x28] = 1;
                state[0x2A] = 1;
            }
            break;
        case 0x126:
            break;
        case 0x127:
            if (state[0x28] != 0) {
                state[0x28] = 0;
            }
            break;
        }
    }

    if (state[0x29] != 0) {
        switch (event) {
        case 0x125:
            if (state[0x28] == 0) {
                state[0x28] = 1;
            }
            break;
        case 0x126:
            break;
        case 0x127:
            if (state[0x28] != 0) {
                state[0x28] = 0;
            }
            break;
        }
    }

    return 0;
}
#pragma scheduling on
/* Sync this object's state with the current selection, updating its child and
 * selected flags when its id matches. */
void fn_80263CA8(void *obj) {
    if (*((u8 *)obj + 0x2A) != 0) {
        void *child = *(void **)((u8 *)obj + 0x30);
        *((u8 *)obj + 0x2A) = 0;
        *(s32 *)((u8 *)child + 0x14) = *(s32 *)((u8 *)obj + 0x2C);
        *((u8 *)child + 0x4F) = 1;
        child = *(void **)((u8 *)obj + 0x30);
        *((u8 *)child + 0x49) = 1;
        *((u8 *)child + 0x4B) = 0;
        *((u8 *)child + 0x4A) = 0;
    }
    if (lbl_8055F434 == *(s32 *)((u8 *)obj + 0x20)) {
        *(s32 *)((u8 *)obj + 0x1C) = 1;
        *((u8 *)obj + 0x29) = 1;
    } else {
        *(s32 *)((u8 *)obj + 0x1C) = 0;
        *((u8 *)obj + 0x29) = 0;
    }
}

void fn_80263D10(void) {}

void fn_80263D14(void) {}

extern const u8 lbl_80346310[], lbl_803462FC[], lbl_803462E8[], lbl_803462D4[];
void fn_80263D18(void *arg0, int arg_sp0) {
    struct Object {
        int unk0; int field4; int field8; int fieldC; int field10;
        int unk14; int unk18; int field1C; int field20; int unk24;
        unsigned char field28; unsigned char field29;
    };
    struct Object *obj = (struct Object *)arg0;
    int a, b, c, d, e;
    int var_r31, var_r30;
    if (obj->field29) {
        if (obj->field28) { var_r31=3; var_r30=0; }
        else { var_r31=0; var_r30=3; }
    } else if (obj->field28) { var_r31=2; var_r30=0; }
    else { var_r31=0; var_r30=2; }
    {
        int value = obj->field20;
        int sign = (int)((unsigned int)value >> 31);
        int low = value & 1;
        if (((low ^ sign) - sign) != 0) {
            a=obj->field10; b=obj->fieldC; c=obj->field8; d=obj->field4;
            e=((int (*)(const u8 *))fn_80131234)(lbl_80346310);
            ((void (*)(s32,s32,s32,s32,s32,s32,s32,s32,s32,f32))fn_8022BAD0)(
                0xC9,d,c,0,b,a,e,obj->field1C,0,1.0f);
        } else {
            a=obj->field10; b=obj->fieldC; c=obj->field8; d=obj->field4;
            e=((int (*)(const u8 *))fn_80131234)(lbl_803462FC);
            ((void (*)(s32,s32,s32,s32,s32,s32,s32,s32,s32,f32))fn_8022BAD0)(
                0xC9,d,c,0,b,a,e,obj->field1C,0,1.0f);
        }
    }
    a=obj->field10; b=obj->fieldC; c=obj->field8; d=obj->field4;
    e=((int (*)(const u8 *))fn_80131234)(lbl_803462E8);
    ((void (*)(s32,s32,s32,s32,s32,s32,s32,s32,s32,f32))fn_8022BAD0)(
        0xCA,d+0x159,c+2,0,b,a,e,var_r31,0,1.0f);
    a=obj->field10; b=obj->fieldC; c=obj->field8; d=obj->field4;
    e=((int (*)(const u8 *))fn_80131234)(lbl_803462D4);
    ((void (*)(s32,s32,s32,s32,s32,s32,s32,s32,s32,f32))fn_8022BAD0)(
        0xCA,d+0x1BD,c+2,0,b,a,e,var_r30,0,1.0f);
}

