#include "include/MSL/stddef.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern float lbl_80563490;
extern void fn_802E30C8(const char *, ...);
struct Rec80216 { int w[12]; float f[3]; };
extern int fn_802182F0(void *, void *);
extern int fn_802368B4(int);
#pragma cplusplus on
struct Fn8021734CEntry {
    virtual void m0();
    virtual void update();
};
/* A widget (menu item) of the UI menu groups in this file.  This ABI keeps two
   destructor slots ahead of the first declared method, so declared method N sits
   at vtable + 0x8 + N * 4. */
struct UiWidget {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual void OnSelected();   /* 0x34: became the group's current widget */
    virtual void OnDeselected(); /* 0x38: no longer the group's current widget */
    virtual void v13(); virtual void v14(); /* 0x3C/0x40: other pointer handlers */
    virtual void v15(int, int); /* 0x44: pointer handler of fn_802175F0, at group-local (x, y) */
    virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22();
    virtual int TakesKey(int);   /* 0x64: does this widget take this key code (fn_80217874) */
    virtual int IsSelectable();  /* 0x68: the menu can be moved onto this widget */
    virtual void v25();
    virtual int HitTest(int, int); /* 0x70: is this group-local (x, y) on the widget */
    unsigned char gap0[0x16];
    unsigned char shown;   /* 0x1A: on state; fn_80219044 flips it as the timers run out */
    unsigned char enabled; /* 0x1B: cleared while the group holds this widget's mask bit */
    unsigned char gap1[4];
    float offTimer;        /* 0x20: runs down while `shown` is clear */
};

/* The UI menu group most of this file's functions take as their first argument
   (built by fn_80216D40).  Widgets are added to the array at +0x30. */
struct UiMenuGroup {
    unsigned char gap0[0x30];
    void *widgets[1];  /* 0x30: widgetCount widget pointers */
    unsigned char gap1[0x3FC];
    int widgetCount;   /* 0x430 */
    unsigned char gap2[0x14];
    void *hovered;     /* 0x448: widget the pointer is over (fn_80217734) */
    void *pressed;     /* 0x44C: widget the pointer went down on (fn_8021749C) */
    void *current;     /* 0x450: the widget the menu is on (fn_80218198) */
    int originX;       /* 0x454: where the group is drawn; pointer coords are relative to it */
    int originY;       /* 0x458 */
};

struct Fn8021832CObj {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21();
    virtual int Query();
};
struct VObj2 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void f28();
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3(); virtual void q4();
    virtual void q5(); virtual void q6(); virtual void q7(); virtual void q8(); virtual void q9();
    virtual void q10(); virtual void q11(); virtual void q12(); virtual void q13(); virtual void q14();
    virtual void q15(); virtual void q16(); virtual void q17(); virtual void q18();
    virtual int f78();
};
#pragma cplusplus reset
// split_file divides it into the game's real files (file_status shows its range).

/* UI key-sound suppression.  fn_80217874 clears it at the head of every key and
   the game's screens set it when they take the key themselves; while it is set
   fn_80218E08 plays no UI key sound. */
extern char lbl_8055EFAC;
int fn_80216D14(int arg0) {
    return arg0 < 0 ? 0 : 1 << arg0;
}

#pragma dont_inline fn_80216D28
void fn_80216D28(void) {
    lbl_8055EFAC = 1;
}

#pragma noinline
void fn_80216D34(void) {
    lbl_8055EFAC = 0;
}

extern char lbl_8055B868[];
extern char lbl_8055B870[];
extern char lbl_8033D808[];
extern int fn_8012C33C(char *);
extern int fn_802C5130(char *);
extern void *fn_8022EE9C(int);
extern void fn_8022EE98(int, void *);
extern void fn_802C2CDC(void *, int, int);
extern int stricmp(char *, char *);
extern char *strstr(char *, char *);
__declspec(section ".sdata") extern char lbl_8055B868[];
__declspec(section ".sdata") extern char lbl_8055B870[];
void *fn_80216D40(void *arg0, char *arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    char *obj = (char *)arg0;
    *(int *)(obj + 0x454) = arg2;
    *(int *)(obj + 0x490) = arg6;
    *(int *)(obj + 0x458) = arg3;
    *(int *)(obj + 0x45C) = arg4;
    *(int *)(obj + 0x460) = arg5;
    *(char *)(obj + 0x46C) = 1;
    *(int *)(obj + 0x430) = 0;
    *(int *)(obj + 0x434) = 0;
    *(int *)(obj + 0x438) = 0;
    *(int *)(obj + 0x43C) = 0;
    *(int *)(obj + 0x440) = 0;
    *(int *)(obj + 0x444) = 0;
    *(int *)(obj + 0x448) = 0;
    *(int *)(obj + 0x44C) = 0;
    *(int *)(obj + 0x450) = 0;
    *(int *)(obj + 0x468) = 0;
    *(int *)(obj + 0x464) = 0;
    fn_802C2CDC(obj + 0xC, 4, 4);
    *(char *)(obj + 0xDE4) = 0;
    *(int *)(obj + 0) = 0;
    *(int *)(obj + 4) = 0;
    *(int *)(obj + 8) = 0;
    if (arg1 != (char *)0 && (signed char)*arg1 != 0) {
        if (strstr(arg1, lbl_8055B868) != (char *)0) {
            if (fn_8012C33C(arg1) != 0) {
                *(int *)(obj + 8) = fn_802C5130(arg1);
            } else {
                fn_802E30C8(lbl_8033D808, arg1);
            }
        } else if (stricmp(arg1, lbl_8055B870) == 0) {
            *(char *)(obj + 0xDE4) = 1;
        }
    }
    {
        char *p = obj + 0x46D;
        int i;
        for (i = 0; i < 0x20; i++) p[i] = 0;
        *(int *)(obj + 0x494) = 0;
        *(int *)(obj + 0x498) = -1;
    }
    {
        struct Rec80216 *rec = (struct Rec80216 *)fn_8022EE9C(0);
        char *dest = obj;
        int slot = 0;
        int iter = 5;
        int *s = (int *)rec;
        float *sf = (float *)rec;
        do {
            int *d;
            d = (int *)(dest + 0x6A0); d[0]=s[0]; d[1]=s[1]; d[2]=s[2]; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[6]=s[6]; d[7]=s[7]; d[8]=s[8]; d[9]=s[9]; d[10]=s[10]; d[11]=s[11]; ((float *)d)[12]=sf[12]; ((float *)d)[13]=sf[13]; ((float *)d)[14]=sf[14];
            d = (int *)(dest + 0x6DC); d[0]=s[0]; d[1]=s[1]; d[2]=s[2]; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[6]=s[6]; d[7]=s[7]; d[8]=s[8]; d[9]=s[9]; d[10]=s[10]; d[11]=s[11]; ((float *)d)[12]=sf[12]; ((float *)d)[13]=sf[13]; ((float *)d)[14]=sf[14];
            d = (int *)(dest + 0x718); d[0]=s[0]; d[1]=s[1]; d[2]=s[2]; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[6]=s[6]; d[7]=s[7]; d[8]=s[8]; d[9]=s[9]; d[10]=s[10]; d[11]=s[11]; ((float *)d)[12]=sf[12]; ((float *)d)[13]=sf[13]; ((float *)d)[14]=sf[14];
            d = (int *)(dest + 0x754); d[0]=s[0]; d[1]=s[1]; d[2]=s[2]; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[6]=s[6]; d[7]=s[7]; d[8]=s[8]; d[9]=s[9]; d[10]=s[10]; d[11]=s[11]; ((float *)d)[12]=sf[12]; ((float *)d)[13]=sf[13]; ((float *)d)[14]=sf[14];
            slot += 6;
            d = (int *)(dest + 0x790); d[0]=s[0]; d[1]=s[1]; d[2]=s[2]; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[6]=s[6]; d[7]=s[7]; d[8]=s[8]; d[9]=s[9]; d[10]=s[10]; d[11]=s[11]; ((float *)d)[12]=sf[12]; ((float *)d)[13]=sf[13]; ((float *)d)[14]=sf[14];
            dest += 0x168;
            iter--;
        } while (iter != 0);
        {
            char *finalDest = obj + slot * 0x3C;
            int *d = (int *)(finalDest + 0x6A0);
            d[0]=s[0]; d[1]=s[1]; d[2]=s[2]; d[3]=s[3]; d[4]=s[4]; d[5]=s[5]; d[6]=s[6]; d[7]=s[7]; d[8]=s[8]; d[9]=s[9]; d[10]=s[10]; d[11]=s[11]; ((float *)d)[12]=sf[12]; ((float *)d)[13]=sf[13]; ((float *)d)[14]=sf[14];
            fn_8022EE98(s[10], finalDest);
        }
    }
    return arg0;
}

extern void fn_802C2D94(void *);
extern void fn_802C4C80(void *);
extern void fn_802C2FC4(void *);
extern void fn_802C519C(void *);
extern void fn_80128668(void *);

#pragma cplusplus on
extern "C" void *fn_80217270(void *container, int shouldFree) {
    class Obj {
    public:
        virtual void v0(int);
    };
    char *slotPtr;
    int index;
    /* Destructor-like cleanup: walk child object slots at +0x30 (count at +0x430)
     * and virtual-delete non-null entries, release embedded/owned substructures,
     * then optionally free the container itself. */
    if (container != 0) {
        index = *(int *)((char *)container + 0x430) - 1;
        slotPtr = (char *)container + index * 4;
        while (index >= 0) {
            void *child = *(void **)(slotPtr + 0x30);
            if (child != 0) {
                ((Obj *)child)->v0(1);
            }
            slotPtr -= 4;
            index--;
        }
        fn_802C2D94((char *)container + 0xC);
        if (*(void **)container != 0) fn_802C4C80(*(void **)container);
        if (*(void **)((char *)container + 4) != 0) fn_802C2FC4(*(void **)((char *)container + 4));
        if (*(void **)((char *)container + 8) != 0) fn_802C519C(*(void **)((char *)container + 8));
        if (shouldFree > 0) fn_80128668(container);
    }
    return container;
}
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8021734C(void *menuGroup) {
    register char *entry = (char *)menuGroup;
    register char *self = (char *)menuGroup;
    register int i = 0;
    Fn8021734CEntry *object;
    void *source;
    long value;
    void (*callback)(void);

    goto check;
loop:
    object = *(Fn8021734CEntry **)(entry + 0x30);
    object->update();
    if (*(int *)(self + 0x440) != 0) {
        object = *(Fn8021734CEntry **)(entry + 0x30);
        source = *(void **)((char *)object + 0x240);
        value = source ? *(long *)source : *(long *)((char *)object + 0x23C);
        fn_802368B4(value);
    }
    entry += 4;
    i++;
check:
    if (i < *(int *)(self + 0x430))
        goto loop;
    callback = *(void (**)(void))(self + 0x438);
    if (callback != 0)
        callback();
}
#pragma cplusplus on
#pragma dont_inline on
extern "C" void fn_802173F8(void *arg0) {
    class Obj {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
    };
    char *base = (char *)arg0;
    int i;
    if (*(void **)(base + 0x43C) != 0) (*(void (**)(void))(base + 0x43C))();
    i = *(int *)(base + 0x430) - 1;
    base += i * 4;
    while (i >= 0) {
        void *obj = *(void **)(base + 0x30);
        ((Obj *)obj)->m2();
        base -= 4;
        i--;
    }
    fn_80216D28();
}
#pragma dont_inline reset
#pragma cplusplus off
void fn_80217478(void) {

}

extern int fn_802368B4(int);
extern void fn_80216D28(void);
void fn_8021747C(void *arg0, void *arg1, void *arg2) {
    void (*callback)(void *, void *) = *(void (**)(void *, void *))((char *)arg0 + 0x440);
    if (callback != 0) {
        callback(arg1, arg2);
    }
}

extern void fn_80218198(void *, void **);
extern int fn_80218214(void *, int, int);
#pragma cplusplus on
extern "C" void fn_8021749C(void *menuGroup, int screenX, int screenY) {
    class Dummy {
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
        virtual void v13(int, int);
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual int v24();
    };
    char *groupBase = (char *)menuGroup;
    int localX;
    int localY;
    int hitIndex;
    Dummy *widget;

    /* On pointer press, hit-test widgets to set the pressed widget, update selection, and notify it. */
    if (*(void **)(groupBase + 0x44C) == 0) {
        localX = screenX - *(int *)(groupBase + 0x454);
        localY = screenY - *(int *)(groupBase + 0x458);
        hitIndex = fn_80218214(menuGroup, localX, localY);
        widget = 0;
        if (hitIndex >= 0) widget = (Dummy *)*(void **)(groupBase + hitIndex * 4 + 0x30);
        *(void **)(groupBase + 0x44C) = widget;
        if (widget != 0 && widget->v24() != 0) {
            if (*(void **)(groupBase + 0x450) != widget)
                fn_80218198(menuGroup, (void **)widget);
        } else {
            fn_80218198(menuGroup, 0);
        }
        if (widget != 0) widget->v13(localX, localY);
    }
}
#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_80217590(void *arg0, int arg1, int arg2) {
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
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14(int, int);
    };
    char *base = (char *)arg0;
    void *obj = *(void **)(base + 0x44C);
    int x = arg1 - *(int *)(base + 0x454);
    int y = arg2 - *(int *)(base + 0x458);
    if (obj != 0) {
        ((Obj *)obj)->v14(x, y);
    }
    *(void **)(base + 0x44C) = 0;
}
#pragma cplusplus off
void fn_80218198(void *, void **);
int fn_80218214(void *, int, int);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802175F0(void *menuGroup, int screenX, int screenY) {
    /* Second pointer-press handler: while no widget is being held, hit-test the
       group's widgets, hold the one under the pointer, move the menu onto it when it
       is selectable and not the current widget yet, and give it the press at the
       group-local position. */
    char *base = (char *)menuGroup;
    int localX;
    int localY;
    int hitIndex;
    UiWidget *widget;
    if (*(void **)(base + 0x44C) == 0) {
        localX = screenX - *(int *)(base + 0x454);
        localY = screenY - *(int *)(base + 0x458);
        hitIndex = fn_80218214(menuGroup, localX, localY);
        widget = 0;
        if (hitIndex >= 0) widget = (UiWidget *)*(void **)(base + hitIndex * 4 + 0x30);
        *(void **)(base + 0x44C) = widget;
        if (widget != 0 && *(void **)(base + 0x450) != widget) {
            if (widget->IsSelectable() != 0) {
                fn_80218198(menuGroup, (void **)widget);
            }
        }
        if (widget != 0) {
            widget->v15(localX, localY);
        }
    }
}
#pragma scheduling on
extern "C" void fn_802176D4(void *arg0, int arg1, int arg2) {
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
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16(int, int);
    };
    char *base = (char *)arg0;
    void *obj = *(void **)(base + 0x44C);
    int x = arg1 - *(int *)(base + 0x454);
    int y = arg2 - *(int *)(base + 0x458);
    if (obj != 0) {
        ((Obj *)obj)->v16(x, y);
    }
    *(void **)(base + 0x44C) = 0;
}
#pragma push
#pragma cplusplus on
extern "C" void fn_80217734(void *menuGroup, int screenX, int screenY) {
    /* Convert screen-space pointer position to group-local coordinates, track which
       widget the pointer is over (hovered, 0x448) with OnDeselected/OnSelected
       callbacks (v21/v20), constrained to the pressed widget (0x44C) while held, and
       deliver the move to that widget or the pressed one (v17). */
    class UiHoverWidget {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void OnPointerMove(int x, int y); virtual void v18();
        virtual void v19(); virtual void OnHoverEnter(); virtual void OnHoverLeave();
    };
    UiMenuGroup *group = (UiMenuGroup *)menuGroup;
    int localX = screenX - *(int *)((char *)group + 0x454);
    int localY = screenY - *(int *)((char *)group + 0x458);
    int hitIndex = fn_80218214(menuGroup, localX, localY);
    UiHoverWidget *hitWidget = 0;
    UiHoverWidget *hoveredWidget;
    if (hitIndex >= 0) hitWidget = *(UiHoverWidget **)((char *)group + hitIndex * 4 + 0x30);
    if (*(UiHoverWidget **)((char *)group + 0x44C) != 0 && hitWidget != *(UiHoverWidget **)((char *)group + 0x44C)) hitWidget = 0;
    hoveredWidget = *(UiHoverWidget **)((char *)group + 0x448);
    if (hitWidget != hoveredWidget) {
        if (hoveredWidget != 0) hoveredWidget->OnHoverLeave();
        *(UiHoverWidget **)((char *)group + 0x448) = hitWidget;
        if (hitWidget != 0) hitWidget->OnHoverEnter();
    }
    if (hitWidget == 0) hitWidget = *(UiHoverWidget **)((char *)group + 0x44C);
    if (hitWidget != 0) hitWidget->OnPointerMove(localX, localY);
}
#pragma pop
extern "C" void fn_80217834(void *arg0) {
    class Dummy_80217834 {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void m10();
        virtual void m11();
        virtual void m12();
        virtual void m13();
        virtual void m14();
        virtual void m15();
        virtual void m16();
        virtual void m17();
        virtual void call();
    };
    Dummy_80217834 *obj = *(Dummy_80217834 **)((char *)arg0 + 0x448);
    if (obj != 0) obj->call();
}
#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_80217854(void *arg0) {
    class Dummy_80217854 {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual void m10();
        virtual void m11();
        virtual void m12();
        virtual void m13();
        virtual void m14();
        virtual void m15();
        virtual void m16();
        virtual void m17();
        virtual void m18();
        virtual void call();
    };
    Dummy_80217854 *obj = *(Dummy_80217854 **)((char *)arg0 + 0x448);
    if (obj != 0) obj->call();
}
#pragma cplusplus off
void fn_80218E08(void *arg0, int arg1);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
/* Key input for a UI menu group: fn_802164D8 hands this the code fn_802E46F0 read
   from the keyboard.  It clears the UI key-sound flag, and while the pointer is
   not held down on a widget asks the widget the menu is on - then every other
   widget that is shown (or whose off timer has run down) and enabled - whether it
   takes this key (UiWidget::TakesKey).  The first widget that does gets the UI
   key sound for that key (fn_80218E08), and no other is asked. */
extern "C" void fn_80217874(void *menuGroup, int key) {
    UiMenuGroup *group = (UiMenuGroup *)menuGroup;
    char *cursor;
    int i;
    UiWidget *widget;
    int eligible;
    float timerLimit;
    void (*clearKeySoundFlag)(void) = fn_80216D34;
    clearKeySoundFlag();
    if (group->pressed == 0) {
        widget = (UiWidget *)group->current;
        if (widget != 0 && widget->TakesKey(key)) {
            fn_80218E08(menuGroup, key);
            return;
        }
        timerLimit = lbl_80563490; /* 0.0f */
        cursor = (char *)group;
        i = 0;
        while (i < group->widgetCount) {
            widget = *(UiWidget **)(cursor + 0x30);
            if (widget != (UiWidget *)group->current) {
                eligible = (widget->shown != 0) || (widget->offTimer >= timerLimit);
                if (eligible && widget->enabled != 0 && widget->TakesKey(key)) {
                    fn_80218E08(menuGroup, key);
                    return;
                }
            }
            cursor += 4;
            i++;
        }
    }
}
#pragma cplusplus off
#pragma pop

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma paired_single off
#pragma cplusplus on
/* Move the menu onto the next selectable widget after the current one, wrapping round
   the group's widget array.  A widget is passed over unless it is showing (its `shown`
   flag set, or its off-timer not run down yet -- see fn_80219044), answers yes to
   IsSelectable() and is enabled. */
extern "C" void fn_802179A0(void *menuGroup) {
    UiMenuGroup *group = (UiMenuGroup *)menuGroup;
    int index;
    int step;
    float timerLimit;
    char *slot;
    UiWidget *widget;
    if (group->current != 0) index = fn_802182F0(menuGroup, group->current);
    else index = 0;
    if (index < 0) goto error;
    timerLimit = lbl_80563490; /* 0.0f */
    step = 0;
    goto check;
loop:
    index++;
    slot = (char *)group + (index % group->widgetCount) * 4;
    widget = (UiWidget *)*(void **)(slot + 0x30); /* group->widgets[] */
    {
        int eligible = 0;
        if (widget->shown != 0) goto eligible_yes;
        if (widget->offTimer >= timerLimit) goto eligible_yes;
        goto eligible_check;
    eligible_yes:
        eligible = 1;
    eligible_check:
        if (eligible != 0 &&
            widget->IsSelectable() != 0 &&
            widget->enabled != 0) {
            fn_80218198(menuGroup, (void **)widget);
            return;
        }
    }
    step++;
check:
    if (step < group->widgetCount - 1) goto loop;
    return;
error:
    {
        extern void fn_802E30C8(const char *, ...);
        extern char lbl_8033D824[];
        fn_802E30C8(lbl_8033D824); /* "Couldn't find widget." */
    }
}
#pragma cplusplus reset
#pragma paired_single reset
#pragma pop

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma scheduling on
#pragma cplusplus on
extern "C" void fn_80217AC0(void *arg0) {
    class Dummy {
    public:
        virtual int f0(); virtual int f1(); virtual int f2(); virtual int f3();
        virtual int f4(); virtual int f5(); virtual int f6(); virtual int f7();
        virtual int f8(); virtual int f9(); virtual int f10(); virtual int f11();
        virtual int f12(); virtual int f13(); virtual int f14(); virtual int f15();
        virtual int f16(); virtual int f17(); virtual int f18(); virtual int f19();
        virtual int f20(); virtual int f21(); virtual int f22(); virtual int f23();
        virtual int f24();
    };
    char *base = (char *)arg0;
    int scan;
    float threshold;
    int initialCount;
    int i;
    initialCount = *(int *)(base + 0x450);
    if (initialCount != 0) scan = fn_802182F0(arg0, (void *)initialCount);
    else scan = 0;
    threshold = lbl_80563490;
    for (i = 0; i < *(int *)(base + 0x430) - 1; i++) {
        char *entry;
        void *obj;
        int eligible;
        scan--;
        entry = base + (((short)scan + *(int *)(base + 0x450)) %
                        *(int *)(base + 0x450)) * 4;
        obj = *(void **)(entry + 0x30);
        eligible = 0;
        if (*(unsigned char *)((char *)obj + 0x1A) != 0) goto eligible_yes;
        if (*(float *)((char *)obj + 0x20) >= threshold) goto eligible_yes;
        goto eligible_check;
    eligible_yes:
        eligible = 1;
    eligible_check:
        if (eligible != 0) {
            if (((Dummy *)obj)->f24() != 0 &&
                *(unsigned char *)((char *)obj + 0x1B) != 0) {
                fn_80218198(arg0, (void **)obj);
                return;
            }
        }
    }
}
#pragma cplusplus reset
#pragma scheduling reset
#pragma dont_inline reset
#pragma pop
int fn_80217BC8(int *arg0, int *arg1) {
    return *arg0 - *arg1;
}

#pragma scheduling invalid_target
void *fn_80217BD8(void *arg0, int arg1, int arg2) {
    char *base = (char *)arg0;
    int cnt;
    *(int *)(base + *(int *)(base + 0x494) * 8 + 0x4A0) = arg1;
    *(int *)(base + *(int *)(base + 0x494) * 8 + 0x4A4) = arg2;
    cnt = *(int *)(base + 0x494) + 1;
    *(int *)(base + 0x494) = cnt;
    qsort(base + 0x4A0, cnt, 8, fn_80217BC8);
    *(int *)(base + 0x498) = *(int *)(base + 0x4A0);
    return base + 0x498;
}
#pragma scheduling on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_80217C4C(void *arg0) {
    char *base = (char *)arg0;
    char *entry;
    int count;
    float threshold;
    int i;
    int last;
    int matches;
    int eligible;
    count = *(int *)(base + 0x494);
    if (1 > count) return;
    threshold = lbl_80563490;
    entry = base;
    last = -1;
    matches = 0;
    i = 0;
    for (; i < count; i++, entry += 8) {
        char *item;
        float value;
        if (*(int *)(base + 0x498) == *(int *)(entry + 0x4A0)) last = i;
        item = *(char **)(entry + 0x4A4);
        eligible = 0;
        if (*(unsigned char *)(item + 0x1A) != 0) goto first_yes;
        value = *(float *)(item + 0x20);
        if (value >= threshold) goto first_yes;
        goto first_check;
    first_yes:
        eligible = 1;
    first_check:
        if (eligible != 0 && *(unsigned char *)(item + 0x1B) != 0) matches += 1;
    }
    {
        int found = -1;
        int step;
        threshold = lbl_80563490;
        for (step = 1; step < count; step++) {
            int idx = (last + step) % count;
            char *current = base + idx * 8;
            char *item2;
            float value;
            item2 = *(char **)(current + 0x4A4);
            eligible = 0;
            if (*(unsigned char *)(item2 + 0x1A) != 0) goto second_yes;
            value = *(float *)(item2 + 0x20);
            if (value >= threshold) goto second_yes;
            goto second_check;
        second_yes:
            eligible = 1;
        second_check:
            if (eligible != 0 && *(unsigned char *)(item2 + 0x1B) != 0) {
                found = idx;
                break;
            }
        }
        if (found >= 0 && (found > last || matches > 3)) {
            *(int *)(base + 0x498) = *(int *)(base + found * 8 + 0x4A0);
        }
    }
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_80217D84(void *arg0) {
    char *base = (char *)arg0;
    char *entry, *item1, *e2;
    int count = *(int *)(base + 0x494);
    int last, matches, i, found, step, idx, item_ok;
    register char *item2;
    if (count < 1) return;
    i = count;
    entry = base + count * 8;
    last = -1;
    matches = 0;
    goto first_test;
first_body:
    if (*(volatile int *)(base + 0x498) == *(int *)(entry + 0x4A0)) last = i;
    item1 = *(char **)(entry + 0x4A4);
    item_ok = 0;
    if (*(unsigned char *)(item1 + 0x1A) == 0 && *(volatile float *)(item1 + 0x20) < lbl_80563490) item_ok = 1;
    if (item_ok && *(unsigned char *)(item1 + 0x1B) != 0) matches++;
first_test:
    entry -= 8;
    if (i-- > 0) goto first_body;
    found = -1;
    step = 1;
    while (step < count) {
        idx = (last + count - step) % count;
        e2 = base + idx * 8;
        item2 = *(char **)(e2 + 0x4A4);
        item_ok = 0;
        if (*(unsigned char *)(item2 + 0x1A) == 0 && *(volatile float *)(item2 + 0x20) < lbl_80563490) item_ok = 1;
        if (item_ok && *(unsigned char *)(item2 + 0x1B) != 0) { found = idx; break; }
        step++;
    }
    if (found >= 0 && (found < last || matches > 3))
        *(int *)(base + 0x498) = *(int *)(base + found * 8 + 0x4A0);
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
int fn_80217EC0(void *arg0, int arg1, int arg2) {
    register int currentX;
    register int currentY;
    register int count = *(int *)((char *)arg0 + 0x494);
    register int candidateIndex;
    register int last;
    register int bestIndex;
    register int best;
    register char *entry;
    register int deltaX;
    register int deltaY;
    register int keyIndex;
    char *item;
    int direction;
    int value;
    int score;
    int eligible;
    float threshold;

    if (count < 1) return;
    last = -1;
    keyIndex = 0;
    entry = (char *)arg0;
    for (; keyIndex < count; entry += 8, keyIndex++) {
        if (*(int *)((char *)arg0 + 0x498) == *(int *)(entry + 0x4A0))
            last = keyIndex;
    }
    threshold = lbl_80563490;
    item = *(char **)((char *)arg0 + last * 8 + 0x4A4);
    best = 100000;
    bestIndex = last;
    currentX = *(int *)(item + 4);
    entry = (char *)arg0;
    currentY = *(int *)(item + 8);
    candidateIndex = 0;
    goto loop_test;
loop:
    if (candidateIndex != last) {
        item = *(char **)(entry + 0x4A4);
        eligible = 0;
        if (*(unsigned char *)(item + 0x1A) != 0) goto eligible_yes;
        if (*(float *)(item + 0x20) >= threshold) goto eligible_yes;
        goto eligible_check;
eligible_yes:
        eligible = 1;
eligible_check:
        if (eligible != 0 && *(unsigned char *)(item + 0x1B) != 0) {
            deltaX = currentX - *(int *)(item + 4);
            deltaY = currentY - *(int *)(item + 8);
            if (arg1 != 0) {
                direction = arg2 != 0 ? -1 : 1;
                if (deltaX * direction <= 10) goto next_candidate;
            } else {
                direction = arg2 != 0 ? -1 : 1;
                if (deltaY * direction <= 10) goto next_candidate;
            }
            if (arg1 != 0) {
                value = fn_800241CC(deltaY) - 10;
                value &= ~(value >> 31);
                direction = arg2 != 0 ? -1 : 1;
                score = deltaX * direction;
                score += value * 300;
            } else {
                value = fn_800241CC(deltaX) - 10;
                value &= ~(value >> 31);
                direction = arg2 != 0 ? -1 : 1;
                score = deltaY * direction;
                score += value * 300;
            }
            if (score < best) {
                bestIndex = candidateIndex;
                best = score;
            }
        }
    }
next_candidate:
    entry += 8;
    candidateIndex++;
loop_test:
    if (candidateIndex < count) goto loop;
    if (bestIndex != -1)
        *(int *)((char *)arg0 + 0x498) =
            *(int *)((char *)arg0 + bestIndex * 8 + 0x4A0);
}
#pragma pop

#pragma pop
void fn_802180B0(void *arg0) { fn_80217EC0(arg0, 1, 0); }

void fn_802180BC(void *arg0) { fn_80217EC0(arg0, 1, 1); }

extern int fn_80217EC0(void *, int, int);
void fn_802180C8(void *arg0) { fn_80217EC0(arg0, 0, 0); }

void fn_802180D4(void *arg0) { fn_80217EC0(arg0, 0, 1); }

void fn_802180E0(void *arg0, int arg1) {
    extern void fn_802E30C8(const char *, ...);
    extern char lbl_8033D83C[];
    if (arg1 < 0 || arg1 >= *(int *)((char *)arg0 + 0x494)) {
        fn_802E30C8(lbl_8033D83C, arg1, *(int *)((char *)arg0 + 0x494));
        return;
    }
    *(int *)((char *)arg0 + 0x498) = *(int *)((char *)arg0 + 0x4A0 + arg1 * 8);
}

int fn_80218120(void *arg0) {
    extern char lbl_8033D860[];
    extern void fn_802E30C8(const char *, ...);
    char *base = (char *)arg0;
    char *p = (char *)arg0;
    int i;
    int count = *(int *)(base + 0x494);
    for (i = 0; i < count; p += 8, i++) {
        if (*(int *)(base + 0x498) == *(int *)(p + 0x4A0)) return i;
    }
    fn_802E30C8(lbl_8033D860);
    return 0;
}

void fn_8021818C(void *arg0) {
    *(int *)((char *)arg0 + 0x498) = -1;
}

#pragma cplusplus on
extern "C" void fn_80218198(void *arg0, void **arg1) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
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
    };
    void *old = *(void **)((char *)arg0 + 0x450);
    if (arg1 != old) {
        if (old != 0) {
            ((Dummy *)old)->f12();
        }
        *(void **)((char *)arg0 + 0x450) = arg1;
        if (arg1 != 0) {
            ((Dummy *)arg1)->f11();
        }
    }
}
#pragma cplusplus off

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma cplusplus on
extern "C" int fn_80218214(void *menuGroup, int x, int y) {
    struct Dummy {
        virtual int f0(); virtual int f1(); virtual int f2(); virtual int f3();
        virtual int f4(); virtual int f5(); virtual int f6(); virtual int f7();
        virtual int f8(); virtual int f9(); virtual int f10(); virtual int f11();
        virtual int f12(); virtual int f13(); virtual int f14(); virtual int f15();
        virtual int f16(); virtual int f17(); virtual int f18(); virtual int f19();
        virtual int f20(); virtual int f21(); virtual int f22(); virtual int f23();
        virtual int f24(); virtual int f25(); virtual int f26(int, int);
    };
    /* Scan menu widgets from back to front and return the index of the last eligible widget whose hit-test (slot 0x70) accepts (x, y), or -1. */
    char *entry;
    int index = *(int *)((char *)menuGroup + 0x430) - 1;
    entry = (char *)menuGroup + index * 4;
    while (index >= 0) {
        void *widget = *(void **)(entry + 0x30);
        if (*(unsigned char *)((char *)widget + 0x1B) != 0) {
            int isEligible = 0;
            if (*(unsigned char *)((char *)widget + 0x1A) != 0) goto eligible_yes;
            if (*(float *)((char *)widget + 0x20) >= 0.0f) goto eligible_yes;
            goto eligible_check;
        eligible_yes:
            isEligible = 1;
        eligible_check:
            if (isEligible != 0 && ((Dummy *)widget)->f26(x, y) != 0)
                return index;
        }
        entry -= 4;
        index--;
    }
    return -1;
}
#pragma cplusplus reset
#pragma dont_inline reset
#pragma pop
int fn_802182F0(void *arg0, void *arg1) {
    int i;
    int count = *(int *)((char *)arg0 + 0x430);
    for (i = 0; i < count; i++) {
        if (*(void **)((char *)arg0 + 0x30) == arg1) return i;
        arg0 = (char *)arg0 + 4;
    }
    return -1;
}

int fn_8021832C(void *arg0) {
    struct Fn8021832CObj *obj = *(struct Fn8021832CObj **)((char *)arg0 + 0x44C);
    if (obj != 0) {
        return obj->Query();
    }
    obj = *(struct Fn8021832CObj **)((char *)arg0 + 0x448);
    if (obj != 0) {
        return obj->Query();
    }
    return 0;
}

extern void fn_80217D84(void *);
#pragma cplusplus on
extern "C" void fn_80218370(void *menuGroup) {
    class Entry {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28();
        virtual void update();
    };
    register char *groupBase = (char *)menuGroup;
    register char *widgetCursor = groupBase;
    register int widgetIndex = 0;
    int entryCount;
    char *entryScan;
    void *entryObject;
    int foundActiveEntry;

    /* Update each menu widget, then ensure the selected entry still has an active/selectable object. */
    goto checkFirst;
firstLoop:
    ((Entry *)*(void **)(widgetCursor + 0x30))->update();
    widgetCursor += 4;
    widgetIndex++;
checkFirst:
    if (widgetIndex < *(int *)(groupBase + 0x430))
        goto firstLoop;

    entryCount = *(int *)(groupBase + 0x494);
    entryScan = groupBase;
    foundActiveEntry = 0;
    for (widgetIndex = 0; widgetIndex < entryCount; widgetIndex++, entryScan += 8) {
        if (*(int *)(groupBase + 0x498) == *(int *)(entryScan + 0x4A0)) {
            entryObject = *(void **)(entryScan + 0x4A4);
            if (*(unsigned char *)((char *)entryObject + 0x1B) != 0) {
                int matched = (*(unsigned char *)((char *)entryObject + 0x1A) != 0) ||
                              (*(float *)((char *)entryObject + 0x20) >= lbl_80563490);
                if (matched) {
                    foundActiveEntry = 1;
                    break;
                }
            }
        }
    }
    if (!foundActiveEntry)
        fn_80217D84(menuGroup);
}
#pragma cplusplus on
struct Dummy80218464 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27();
    virtual void f28(); virtual void f29(); virtual void f30();
};
#pragma cplusplus reset
struct VTab80218464 { void *pad[32]; void (*f32)(void *); };
struct VObj80218464 { struct VTab80218464 *vt; };
#pragma cplusplus on
extern "C" void fn_80218464(void *arg0) {
    char *cursor;
    int i = 0;
    char *base;
    base = (char *)arg0;
    cursor = base;
    while (i < *(int *)(base + 0x430)) {
        Dummy80218464 *obj = *(Dummy80218464 **)(cursor + 0x30);
        obj->f30();
        cursor += 4;
        i++;
    }
}
#pragma cplusplus off
extern float lbl_80563490;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802184D0(void *arg0) {
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
    };
    float threshold = lbl_80563490;
    char *cursor;
    int i;
    char *base;
    base = (char *)arg0;
    cursor = base;
    i = 0;
    while (i < *(int *)(base + 0x430)) {
        void *obj = *(void **)(cursor + 0x30);
        int call = 0;
        if (*(unsigned char *)((char *)obj + 0x1A) != 0 || *(float *)((char *)obj + 0x20) >= threshold) {
            call = 1;
        }
        if (call != 0) {
            ((Obj *)obj)->v9();
        }
        cursor += 4;
        i++;
    }
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
extern float lbl_80563494, lbl_80563498;
extern int fn_80215228(void);
extern void fn_80230C30(float *,float *,int,int);
extern void fn_802C5310(void *,int,float,float,float);
extern void fn_802C86E8(unsigned int);
extern void fn_802C88BC(int);
extern void fn_8022EDB8(void);
extern void fn_8022ED00(void *);
extern void *fn_8022EDC4(void);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
void fn_80218574(void *arg0) {
    struct Mtx { int w[12]; };
    struct State { struct Mtx m; float a, b, c; };
    struct VObj;
    struct VTab { void *pad0[10]; void (*f28)(struct VObj *); void *pad1[19]; int (*f78)(struct VObj *); };
    struct VObj { struct VTab *vt; };
    struct State state;
    struct State *src;
    float x,y;
    void *entry;
    int current, i;
    float limit, one, zero;
    void *obj;
    void *base;
    int index;
    base=arg0;
    if (*(void **)((char*)base+8)) {
        fn_80230C30(&x,&y,0,0);
        fn_802C5310(*(void **)((char*)base+8),0,x,y,lbl_80563490);
    } else if(fn_80215228() && !*(unsigned char *)((char*)base+0xde4)) {
        fn_802C86E8(0xff000000); fn_802C88BC(3);
    }
    zero=lbl_80563490; one=lbl_80563494; limit=lbl_80563498;
    entry=base; current=-1;
    for(i=0;i<*(int *)((char*)base+0x430);entry=(void*)((char*)entry+4),i++) {
        int active=0;
        obj=*(void **)((char*)entry+0x30);
        if(*(unsigned char *)((char*)obj+0x1a) || *(float *)((char*)obj+0x20)>=zero) active=1;
        if(active) {
            int pushed;
            float alpha;
            int *p=*(int **)((char*)obj+0x240);
            if(p) index=*p; else index=*(int *)((char*)obj+0x23c);
            if(index!=current) {
                if(current!=-1) fn_8022EDB8();
                current=index;
                fn_8022ED00((char*)base+index*0x3c+0x6a0);
            }
            if (*(float *)((char*)obj+0x20)>=zero) alpha=one-*(float *)((char*)obj+0x20);
            else if (*(float *)((char*)obj+0x1c)>=zero) alpha=*(float *)((char*)obj+0x1c);
            else if (*(unsigned char *)((char*)obj+0x1a)) alpha=lbl_80563494;
            else alpha=zero;
            pushed=0;
            if(alpha<limit && *(void **)((char*)base+0x444)) {
                int b,a,c,result;
                float innerAlpha;
                pushed=1;
                src=(struct State *)fn_8022EDC4();
                state.m = src->m;
                state.a=src->a; state.b=src->b; state.c=src->c;
                if (*(float *)((char*)obj+0x20)>=zero) innerAlpha=one-*(float *)((char*)obj+0x20);
                else if (*(float *)((char*)obj+0x1c)>=zero) innerAlpha=*(float *)((char*)obj+0x1c);
                else if (*(unsigned char *)((char*)obj+0x1a)) innerAlpha=lbl_80563494;
                else innerAlpha=zero;
                a=*(int *)((char*)obj+0x238); b=*(int *)((char*)obj+4); c=*(int *)((char*)obj+8);
                result=((struct VObj *)obj)->vt->f78((struct VObj *)obj);
                (*(void (**)(void *,int,int,int,int,int,int,float))((char*)base+0x444))(&state,a,b,c,result,*(int *)((char*)obj+0x10)-c,0,innerAlpha);
                fn_8022ED00(&state);
            }
            ((struct VObj *)obj)->vt->f28((struct VObj *)obj);
            if(pushed) fn_8022EDB8();
        }
    }
    if(current!=-1) fn_8022EDB8();
}
#pragma pop

#pragma dont_inline on
int fn_8021885C(void *arg0, int arg1) {
    return (*(int *)((char *)arg0 + 0x464) & fn_80216D14(arg1)) == 0;
}

extern int fn_80216D14(int);
extern void fn_802193C8(float);
/* Set the given sound-id bit on this sound manager and notify matching slots
 * (object at cursor+0x30 has mask at +0x238) via fn_802193C8; mark 0x46C if
 * more than 8 slots were notified. */
void fn_8021889C(void *arg0, int arg1, float arg2) {
    int mask = fn_80216D14(arg1);
    if (*(int *)((char *)arg0 + 0x464) & mask)
        return;
    {
        char *cursor;
        int called;
        int currentMask;
        int flags;
        int i;

        currentMask = fn_80216D14(arg1);
        flags = *(int *)((char *)arg0 + 0x464);
        cursor = (char *)arg0;
        called = 0;
        *(int *)((char *)arg0 + 0x464) = flags | currentMask;
        i = 0;
        goto check;
    loop:
        if (*(int *)((char *)arg0 + 0x464) &
            *(int *)((char *)*(void **)(cursor + 0x30) + 0x238)) {
            fn_802193C8(arg2);
            called++;
        }
        cursor += 4;
        i++;
    check:
        if (i < *(int *)((char *)arg0 + 0x430))
            goto loop;
        if (called > 8)
            *(char *)((char *)arg0 + 0x46C) = 1;
    }
}

extern void fn_80219358(float);
/* Unmute one sound id and notify each active sound slot when no other group still enables it. */
void fn_80218968(void *soundManager, int soundId, float fadeTime) {
    int bitMask = fn_80216D14(soundId);
    if (*(int *)((char *)soundManager + 0x464) & bitMask) {
        char *slotCursor;
        int notifiedCount;
        int currentMask;
        int flags;
        int i;

        notifiedCount = 0;
        currentMask = fn_80216D14(soundId);
        flags = *(int *)((char *)soundManager + 0x464);
        slotCursor = (char *)soundManager;
        i = 0;
        *(int *)((char *)soundManager + 0x464) = flags & ~currentMask;
        goto check;
    loop:
        if ((*(int *)((char *)soundManager + 0x464) &
             *(int *)((char *)*(void **)(slotCursor + 0x30) + 0x238)) == 0) {
            fn_80219358(fadeTime);
            notifiedCount++;
        }
        slotCursor += 4;
        i++;
    check:
        if (i < *(int *)((char *)soundManager + 0x430))
            goto loop;
        if (notifiedCount >= 8)
            *(char *)((char *)soundManager + 0x46C) = 1;
    }
}

#pragma dont_inline on
void fn_80218A34(void *group, int bitIndex) {
    /* Clear bitIndex in the group's mask and refresh child flags when no remaining mask bits overlap. */
    char *cursor;
    void *child;
    int i, one = 1;
    int mask = fn_80216D14(bitIndex);

    if (*(int *)((char *)group + 0x468) & mask) {
        mask = fn_80216D14(bitIndex);
        *(int *)((char *)group + 0x468) &= ~mask;
        cursor = (char *)group;
        i = 0;
        for (; i < *(int *)((char *)group + 0x430); cursor += 4, i++) {
            child = *(void **)(cursor + 0x30);
            if ((*(int *)((char *)group + 0x468) & *(int *)((char *)child + 0x238)) == 0) {
                *(unsigned char *)((char *)child + 0x1B) = one;
                if (*(unsigned char *)((char *)child + 0x1A))
                    *(unsigned char *)((char *)child + 0x234) = one;
            }
        }
    }
}
/* Sets a group disable-mask bit and disables/enqueues refresh for affected widgets. */
void fn_80218ADC(void *group, int bitIndex) {
    char *cursor;
    void *widget;
    int i, one = 1, zero = 0;
    int mask = fn_80216D14(bitIndex);
    if ((*(int *)((char *)group + 0x468) & mask) == 0) {
        mask = fn_80216D14(bitIndex);
        *(int *)((char *)group + 0x468) |= mask;
        cursor = (char *)group;
        i = 0;
        for (; i < *(int *)((char *)group + 0x430); cursor += 4, i++) {
            widget = *(void **)(cursor + 0x30);
            if (*(int *)((char *)group + 0x468) & *(int *)((char *)widget + 0x238)) {
                *(unsigned char *)((char *)widget + 0x1B) = zero;
                if (*(unsigned char *)((char *)widget + 0x1A))
                    *(unsigned char *)((char *)widget + 0x234) = one;
            }
        }
    }
}
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_80218B88(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    class Obj {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5();
        virtual void v8(int, int);
    };
    int mask = fn_80216D14(arg1);
    void **cursor = (void **)arg0;
    int i = 0;
    for (; i < *(int *)((char *)arg0 + 0x430); cursor++, i++) {
        void *obj = *(void **)((char *)cursor + 0x30);
        if (mask & *(int *)((char *)obj + 0x238)) {
            ((Obj *)obj)->v8(arg2, arg3);
        }
    }
}
#pragma cplusplus off
#pragma pop
void fn_80218C14(void *arg0, int arg1, void *arg2) {
    const unsigned int *src = (const unsigned int *)arg2;
    unsigned int a;
    unsigned int b;
    unsigned int *dst = (unsigned int *)((char *)arg0 + arg1 * 0x3C + 0x6A0);
    unsigned int c;
    float z;
    float y;
    float x;

    a = src[0];
    b = src[1];
    c = src[2];
    dst[0] = a;
    a = src[3];
    dst[1] = b;
    b = src[4];
    dst[2] = c;
    c = src[5];
    dst[3] = a;
    a = src[6];
    dst[4] = b;
    b = src[7];
    dst[5] = c;
    c = src[8];
    dst[6] = a;
    a = src[9];
    dst[7] = b;
    b = src[10];
    dst[8] = c;
    c = src[11];
    dst[9] = a;
    x = ((const float *)src)[12];
    dst[10] = b;
    y = ((const float *)src)[13];
    dst[11] = c;
    z = ((const float *)src)[14];
    ((float *)dst)[12] = x;
    ((float *)dst)[13] = y;
    ((float *)dst)[14] = z;
}
#pragma cplusplus on
/* Registers a child object in the parent's list and activates it if needed. */
extern "C" void fn_80218C98(void *parent, void **child, int arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual int v3();
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
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual int v24();
    };
    char *base = (char *)parent;
    Obj *obj = (Obj *)child;
    int count = *(int *)(base + 0x430);
    *(void **)(base + 0x30 + count * 4) = child;
    *(int *)(base + 0x430) = count + 1;
    if (obj->v24() != 0 &&
        *(int *)(base + 0x450) == 0 &&
        *(unsigned char *)(base + 0xDE4) != 0) {
        fn_80218198(parent, child);
    }
    *(int *)((char *)obj + 0x238) = fn_80216D14(arg2);
    *(void **)((char *)obj + 0x2C) = parent;
    obj->v3();
}
extern "C" void fn_80218D54(void *menu, int widgetId) {
    class Obj {
    public:
        virtual int v0();
        virtual int v1();
        virtual int v2();
        virtual int v3();
        virtual int v4();
        virtual int v5();
        virtual int v6();
        virtual int v7();
        virtual int v8();
        virtual int v9();
        virtual int v10();
        virtual int v11();
        virtual int v12();
        virtual int v13();
        virtual int v14();
        virtual int v15();
        virtual int v16();
        virtual int v17();
        virtual int v18();
        virtual int v19();
        virtual int v20();
        virtual int v21();
        virtual int v22();
        virtual int v23();
        virtual int v24();
    };
    char *base = (char *)menu;
    char *cursor = base;
    int i = 0;

    /* Find the first selectable child widget with matching id and set it as current. */
    while (i < *(int *)(base + 0x430)) {
        Obj *child = *(Obj **)(cursor + 0x30);
        if (child->v24() != 0 &&
            (*(Obj **)(cursor + 0x30))->v4() == widgetId) {
            fn_80218198(menu, *(void ***)(base + i * 4 + 0x30));
            return;
        }
        cursor += 4;
        i++;
    }
}
#pragma cplusplus off
extern void fn_80214D50(int);
void fn_80218E08(void *arg0, int arg1) {
    if ((unsigned char)lbl_8055EFAC != 0) return;
    if (arg1 == 0xD || (unsigned int)arg1 == 0x113) fn_80214D50(2);
    else if ((unsigned int)arg1 == 0x1B) fn_80214D50(3);
    else fn_80214D50(0);
}

#pragma dont_inline reset
extern int qsort(void *, int, int, int (*)(const void *, const void *), void *);
int fn_80217BC8(int *, int *);
typedef struct { unsigned int words[12]; float values[3]; } Fn80216D40Record;
