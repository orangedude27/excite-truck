// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
// DIAGNOSTIC: build probe.

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

typedef struct {
    s32 sp8; s32 *spC; s32 sp10; s32 sp14; s32 sp18; s32 *sp1C;
    u8 pad18[0x10];
    s32 sp30; s32 sp34; s32 *sp38;
    u8 pad34[0x10];
    s32 sp4C; s32 sp50; s32 sp54; s32 sp58; s32 sp5C;
    s8 sp60, sp61, sp62; u8 pad5B;
    s32 sp64; s32 *sp68; s32 *sp6C;
    u8 pad68[0x10];
    s32 sp80; s32 sp84; s32 sp88; u8 pad8C[8];
    s8 sp94, sp95, sp96; u8 pad8F;
    s32 sp98; s32 *sp9C; s32 *spA0; u8 padA4[0x10];
    s32 spB4; s32 spB8; s32 spBC; s32 spC0; s32 spC4;
    s8 spC8, spC9; u8 padCA[2]; f32 spCC; s32 *spD0; u8 padD4[0x10];
    s32 spE4; s32 spE8; s32 spEC; u8 padF0[8];
    s8 spF8, spF9; u8 padFA[2]; f32 spFC;
    s32 *sp100; s32 sp104; s32 **sp108; s32 sp10C; s32 sp110;
    s32 *sp114; s32 sp118; s32 **sp11C; s32 sp120; s32 sp124;
    s32 *sp128; s32 sp12C; s32 **sp130; s32 sp134; s32 sp138;
    s32 *sp13C; s32 sp140; s32 **sp144; s32 sp148; s32 sp14C;
    s32 *sp150; s32 sp154; s32 **sp158; s32 sp15C; s32 sp160;
    s32 sp164; s32 sp168; s32 *sp16C; s32 sp170; s32 sp174;
    s32 *sp178; s32 sp17C; s32 *sp180; s32 sp184; s32 sp188;
    s32 *sp18C; s32 sp190; s32 *sp194; s32 sp198; s32 sp19C;
    s32 *sp1A0; s32 sp1A4; s32 sp1A8; s32 sp1AC; s32 sp1B0;
    s32 sp1B4; s32 sp1B8; s32 sp1BC; s32 sp1C0; s32 sp1C4;
} Fn8026311CFrame;

void fn_8026311C(void) {
#pragma scheduling invalid_target
    extern s32 fn_80129890(void);
    extern s32 fn_80133460(s32, const u8 *, u8, s32);
    extern void *fn_80207848(void *, s32);
    extern s32 fn_802146BC(s32 *, s32, s32, s32, s32, s32, s32, s32);
    extern void *fn_80232578(void *);
    extern s32 Abend_Panic(void *, ...);
    extern void fn_802E6FBC(void);
    extern void fn_802E8518(s32);
    extern s32 fn_802E8D84(void);
    extern const u8 lbl_802FA6E8[];
    extern const u8 lbl_80345FD0[];
    extern const u8 lbl_803460B4[];
    extern const u8 lbl_80346188[];
    extern const u8 lbl_80346248[];
    extern const u8 lbl_80346270[];
    extern const u8 lbl_80346280[];
    extern const u8 lbl_80346294[];
    extern const u8 lbl_803462B8[];
    extern const u8 lbl_803462C8[];
    extern const u8 lbl_80498F40[];
    extern const u8 lbl_8055B860[];
    extern const u8 lbl_8055C444[];
    extern f32 lbl_80563BD0;
    Fn8026311CFrame s;
    char *v22, *v24, *v30, *v29b;
    char *base45;
    void *p;
    s32 i, r, k;

    base45 = (char *)lbl_80345FD0;
    s.spB4 = 0;
    s.spA0 = (s32 *)lbl_80346120;
    s.spBC = 0;
    s.spC8 = 1;
    s.spC9 = 0;
    s.spB8 = (s32)fn_80232578((void *)lbl_803462C8);
    s.spA0 = (s32 *)lbl_803460B4;
    s.spCC = lbl_80563BD0;
    s.spE4 = 0;
    s.spD0 = (s32 *)lbl_80346120;
    s.spEC = 0;
    s.spF8 = 1;
    s.spF9 = 0;
    s.spE8 = (s32)fn_80232578((void *)lbl_803462C8);
    s.spD0 = (s32 *)lbl_803460B4;
    s.spFC = lbl_80563BD0;
    s.sp4C = 0;
    s.sp38 = (s32 *)lbl_80346120;
    s.sp54 = 0;
    s.sp60 = 1;
    s.sp61 = 0;
    s.sp50 = (s32)fn_80232578((void *)lbl_803462C8);
    s.sp38 = (s32 *)lbl_80346048;
    s.sp62 = 0;
    s.sp64 = 0;
    p = fn_80207848((void *)lbl_80346270, 0);
    s.sp68 = (s32 *)p;
    if (p != 0) {
        f32 vf = lbl_80563BD4;
        if (vf != *(f32 *)((char *)p + 8)) {
            *((s8 *)p + 0x4D) = 1;
            *(f32 *)((char *)p + 8) = vf;
        }
    } else {
        Abend_Panic((void *)lbl_80346248);
    }

    s.sp80 = 0;
    s.sp6C = (s32 *)lbl_80346120;
    s.sp88 = 0;
    s.sp94 = 1;
    s.sp95 = 0;
    s.sp84 = (s32)fn_80232578((void *)lbl_803462C8);
    s.sp6C = (s32 *)lbl_80346048;
    s.sp96 = 0;
    s.sp98 = 0;
    p = fn_80207848((void *)lbl_80346270, 0);
    s.sp9C = (s32 *)p;
    if (p != 0) {
        f32 vf = lbl_80563BD4;
        if (vf != *(f32 *)((char *)p + 8)) {
            *((s8 *)p + 0x4D) = 1;
            *(f32 *)((char *)p + 8) = vf;
        }
    } else {
        Abend_Panic((void *)lbl_80346248);
    }

    v22 = (char *)&s.spA0;
    v24 = (char *)&s.sp38;
    i = 0;
    r = 0;
    do {
        *(s32 *)(v22 + 0x24) = i;
        *(s32 *)(v22 + 0x20) = r;
        ((void (*)(s32, s32, u8 *))fn_801333E8)(i + 8, (s32)&lbl_803462A8, (u8 *)(v22 + 0x28));
        *(s32 *)(v24 + 0x24) = i;
        *(s32 *)(v24 + 0x20) = r + 1;
        ((void (*)(s32, s32, u8 *))fn_801333E8)(i + 8, (s32)&lbl_80346280, (u8 *)(v24 + 0x28));
        i += 1;
        *(s32 *)(v24 + 0x2C) |= 1 << *(s32 *)(v24 + 0x24);
        v22 += 0x30;
        r += 2;
        v24 += 0x34;
    } while (i < 2);

    s.sp1C = (s32 *)&lbl_80346188;
    s.sp30 = 0;
    s.sp34 = 0;
    s.sp104 = 5;
    s.sp100 = (s32 *)(base45 + 0x10);
    v30 = (char *)&s.spA0;
    v29b = (char *)&s.sp38;
    s.sp114 = (s32 *)(base45 + 0x1C);
    s.sp10C = 0;
    s.sp108 = (s32 **)v30;
    s.sp110 = 0;
    s.sp118 = 5;
    s.sp11C = (s32 **)v29b;
    s.sp120 = 0;
    s.sp124 = 0;
    s.sp12C = 5;
    s.sp128 = (s32 *)(base45 + 0x28);
    s.sp130 = (s32 **)&s.spD0;
    s.sp134 = 0;
    s.sp138 = 0;
    s.sp140 = 5;
    s.sp13C = (s32 *)(base45 + 0x34);
    s.sp144 = (s32 **)&s.sp6C;
    s.sp148 = 0;
    s.sp14C = 0;
    s.sp154 = 5;
    s.sp150 = (s32 *)lbl_8055C444;
    s.sp158 = (s32 **)&s.sp1C;
    s.sp15C = 0;
    s.sp160 = 0;
    s.sp168 = 6;
    s.sp164 = (s32)lbl_8055B860;
    s.sp16C = (s32 *)&fn_80263080;
    s.sp170 = 0;
    s.sp174 = 0x126;
    s.sp17C = 6;
    s.sp178 = (s32 *)lbl_8055B860;
    s.sp180 = (s32 *)&fn_802630C0;
    s.sp184 = 0;
    s.sp188 = 0x128;
    s.sp190 = 6;
    s.sp18C = (s32 *)lbl_8055B860;
    s.sp194 = (s32 *)&fn_80263104;
    s.sp198 = -2;
    s.sp19C = 0xD;
    s.sp1A4 = 6;
    s.sp1A0 = (s32 *)lbl_8055B860;
    s.sp1A8 = 0;
    s.sp1AC = -1;

    s.spC = (s32 *)*(s32 **)((char *)lbl_802FA6E8 + 4);
    s.sp1B0 = 0x1B;
    s.sp1B4 = *(s32 *)((char *)lbl_80498F40 + 0);
    s.sp1B8 = *(s32 *)((char *)lbl_80498F40 + 4);
    s.sp1BC = *(s32 *)((char *)lbl_80498F40 + 8);
    s.sp1C0 = *(s32 *)((char *)lbl_80498F40 + 0xC);
    s.sp1C4 = *(s32 *)((char *)lbl_80498F40 + 0x10);
    s.sp8 = *(s32 *)((char *)lbl_802FA6E8 + 0);
    s.sp10 = *(s32 *)((char *)lbl_802FA6E8 + 8);
    s.sp14 = *(s32 *)((char *)lbl_802FA6E8 + 0xC);
    s.sp18 = *(s32 *)((char *)lbl_802FA6E8 + 0x10);
    s.spC = (s32 *)&s.sp100;

    r = fn_802146BC(&s.sp8, -0x3E7, -0x3E7, 1,
                    *(s32 *)((char *)lbl_802FA6E8 + 0x10),
                    *(s32 *)((char *)lbl_802FA6E8 + 0xC),
                    *(s32 *)((char *)lbl_802FA6E8 + 8),
                    *(s32 *)((char *)lbl_802FA6E8 + 0));
    switch (r) {
    case -2:
        k = 0;
        do {
            ((void (*)(s32, const u8 *, u8))fn_80133460)(
                *(s32 *)(v30 + 0x24) + 8, lbl_803462B8, *(u8 *)(v30 + 0x28));
            ((void (*)(s32, const u8 *, u8))fn_80133460)(
                *(s32 *)(v29b + 0x24) + 8, lbl_80346294, *(u8 *)(v29b + 0x28));
            k += 1;
            v30 += 0x30;
            v29b += 0x34;
        } while (k < 2);
        if (fn_802E8D84() != 0) {
            fn_802E6FBC();
        }
        i = 0;
        while (i < fn_80129890()) {
            fn_802E8518(i);
            i += 1;
        }
        lbl_8055F434 = 0;
        break;
    case -1:
        lbl_8055F434 = 0;
        break;
    default:
        Abend_Panic((void *)(base45 + 0x40));
        break;
    }

    s.sp6C = (s32 *)lbl_80346048;
    if (s.sp9C != 0) {
        if (s.sp9C != 0) {
            ((void (**)(s32))(*(void **)s.sp9C))[2](1);
        }
    }
    s.sp6C = (s32 *)lbl_80346120;
    fn_802328D4(s.sp84);
    s.sp84 = 0;
    s.sp38 = (s32 *)lbl_80346048;
    if (s.sp68 != 0) {
        if (s.sp68 != 0) {
            ((void (**)(s32))(*(void **)s.sp68))[2](1);
        }
    }
    s.sp38 = (s32 *)lbl_80346120;
    fn_802328D4(s.sp50);
    s.spD0 = (s32 *)lbl_80346120;
    s.sp50 = 0;
    fn_802328D4(s.spE8);
    s.spE8 = 0;
    s.spA0 = (s32 *)lbl_80346120;
    fn_802328D4(s.spB8);
    s.spB8 = 0;
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
extern s32 KERNEL_GetTimeMs(void);
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

/* Virtual slot 0x10 of the unified-control menu widget's vtable lbl_80346188:
 * this widget overrides that method with a no-op, so it has an empty body. */
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
/* No-op virtual slot 0x64 of the menu-widget vtable lbl_80346120: this widget
 * leaves this method as an empty stub. */
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
                *(f32 *)(objBytes + 0x2C) = (f32)KERNEL_GetTimeMs() / lbl_80563BD8;
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
    /* After KERNEL_GetTimeMs ticks (ms) exceed the start time at +0x2C by 0.5s, fades
       the handle at +0x24 to (0,0) via fn_802E8528, else to (1,0). Mirrors active
       selection (lbl_8055F434 == id at +0x20) into flags at +0x1C/+0x29. */
    f32 nowMs = (f32)KERNEL_GetTimeMs();
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

/* No-op virtual slot 0x60 of the menu-widget vtables lbl_80346048 / lbl_80346120:
 * those widgets leave this method as an empty stub. */
void fn_80263D10(void) {}

/* No-op virtual slot 0x10 of the menu-widget vtables lbl_80346048 / lbl_80346120:
 * those widgets leave this method as an empty stub. */
void fn_80263D14(void) {}

extern const u8 lbl_80346310[], lbl_803462FC[], lbl_803462E8[], lbl_803462D4[];
#pragma push
#pragma scheduling invalid_target
void fn_80263D18(void *arg0, int arg_sp0) {
    struct Object {
        int unk0; int field4; int field8; int fieldC; int field10;
        int unk14; int unk18; int field1C; int field20; int unk24;
        unsigned char field28; unsigned char field29;
    };
    struct Object *obj = (struct Object *)arg0;
    int var_r31, var_r30;
    int a, b, c, d, e;
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
#pragma pop
