// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;
struct Words5_80260E04 { s32 w[5]; };
extern float lbl_80563B88;
extern void fn_80214A9C(s32);
extern s32 fn_8025C204(s32);
extern void fn_80214AF0(s32);
extern void fn_80230E90(s32);
extern void fn_80236914(void);
extern u8 lbl_8055F3E9;
extern u8 lbl_8055F3EA;
extern u8 lbl_8055F3EB;
extern void fn_80230F6C(s32 *);
extern float fn_8023659C(void);
extern float lbl_8055C404, lbl_8055C408, lbl_8055C40C, lbl_8055C410, lbl_8055C414;
extern u8 lbl_8055F3FC, lbl_8055F404, lbl_8055F40C, lbl_8055F414, lbl_8055F41C;
extern float lbl_8055F3F8, lbl_8055F400, lbl_8055F408, lbl_8055F410, lbl_8055F418;
extern float lbl_80563BB0, lbl_80563BB4, lbl_80563BB8;
extern float lbl_80563BBC, lbl_80563BC0, lbl_80563BC4;
#pragma push
#pragma small_data on
extern u8 *lbl_8055F420;
#pragma pop
extern u8 lbl_8055BAC0;
extern u8 lbl_8055BAB8;
extern s32 lbl_802FA6A8[];
extern u8 lbl_8055B860;
#pragma push
#pragma small_data off
extern u8 lbl_80345EA0[];
extern u8 lbl_80345E28[];
#pragma pop
extern u8 lbl_8055F3EC;
s32 fn_8025FE8C(void) {
    void *sound;
    /* On the challenge-select screen, start its sound handle playing once: set the play flag, clear loop and fade-out. */
    if ((s32)lbl_8055F3E9 != 0 && (s32)lbl_8055F3EC == 0) {
        sound = *(void **)(lbl_8055F420 + 0x14);
        *(u8 *)((u8 *)sound + 0x49) = 1;
        *(u8 *)((u8 *)sound + 0x4B) = 0;
        *(u8 *)((u8 *)sound + 0x4A) = 0;
        lbl_8055F3EC = 1;
    }
    return 0;
}

extern void fn_800167FC(s32);
extern void *fn_80012820(s32);
extern void *fn_8025007C(s32);
extern s32 fn_8024DAE0(s32,s32,s32,void*,s32);
extern void fn_802E317C(void *, ...);
extern s32 lbl_8055C400;
#pragma push
#pragma small_data off
extern u8 lbl_80345B40[];
#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" s32 fn_8025FECC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    /* If a global state flag is set, returns success early. Otherwise looks up an
     * object by arg2, queries it for a resource/value (logging errors via
     * fn_802E317C on failure), wraps a valid value in a temporary handle, passes
     * it to fn_8024DAE0, then deletes the handle and returns the result. */
    struct Inner3 {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual s32 vfunc_18(const void*, s32);
    };

    struct Inner2 {
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
        virtual Inner3* vfunc_5c(const void*);
    };

    struct Obj {
        u8 pad[0x80];
        Inner2* inner;
    };

    struct Handle {
        virtual ~Handle();
        virtual void vfunc_0c(s32, s32, s32);
    };

    const char* base = (const char*)lbl_80345B40;
    if (lbl_8055C400 >= 0) {
        return 1;
    }

    fn_800167FC(1);
    Obj* obj = (Obj*)fn_80012820(arg2);
    s32 val = 0;
    s32 check;
    if (obj != 0 && obj->inner != 0 && (check = (s32)obj->inner->vfunc_5c(base + 0x90), ((u32)(-check | check) >> 31) != 0)) {
        val = obj->inner->vfunc_5c(base + 0x90)->vfunc_18(base + 0xa0, 0);
    } else {
        fn_802E317C((void*)(base + 0xb0));
    }

    Handle* handle = 0;
    if (val != 0) {
        handle = (Handle*)fn_8025007C(1);
        handle->vfunc_0c(val, 1, 0);
    } else {
        fn_802E317C((void*)(base + 0x104));
    }

    s32 ret = fn_8024DAE0(arg0, arg1, 0, handle, arg3);
    delete handle;
    return ret;
}

extern "C" void *fn_80016464(int);
extern "C" void *fn_80016510(int);
extern "C" void *fn_8001285C(void);
extern void *lbl_8055F3E4;
extern u8 lbl_8055F3E8;
extern "C" void *fn_80016544(void *);
extern "C" void fn_80019144(void *);
extern "C" void fn_80016970(s32, s32, s32, s32);
extern "C" s32 fn_8000DA10(void);
extern "C" void *fn_8000DB34(s32);
extern "C" void fn_800169F8(const char *, s32);
extern "C" s32 fn_802E4A10(void);
extern "C" void fn_80137C84(s32, s32);
extern "C" void *fn_80012870(s32, s32);
extern "C" void fn_8023BF4C(void *);
extern "C" void fn_80016A44(s32);
extern "C" void fn_8001EFC8(void);
extern "C" void *fn_8027B878(s32);
extern "C" void *fn_801284F8(s32, void *);
extern "C" void *fn_8023512C(void *);
extern "C" void *fn_80232578(void *);
extern "C" void *fn_80207848(void *, s32);
extern "C" s32 fn_802E8D84(void);
extern "C" void fn_802E7128(void);
extern void *memset(void *, int, unsigned int);
#pragma cplusplus reset
void fn_8026003C(void) {
#define VC0(o,s) (((s32(*)(void*))(*(void***)(o))[(s)/4])(o))
#define VC1(o,s,a) (((s32(*)(void*,s32))(*(void***)(o))[(s)/4])(o,a))
    char *sel;
    char *strBase = (char *)&lbl_80345B40;
    s32 firstVal, queryId, parameter, localC, local8, found, idx, i, j, wasReady, ok;
    void *obj, *item, *value;
    u8 *groupList;
    s32 groupIndex, itemIndex, count, max;
    firstVal = *(s32 *)((char *)fn_80016464(0) + 4);
    localC = *(s32 *)((char *)fn_80016510(*(s32 *)((char *)fn_80016464(0) + 0x4C)) + 4);
    local8 = *(s32 *)((char *)fn_80016464(0) + 0x50);
    #pragma push
    #pragma cplusplus on
    {
        struct Manager {
            virtual void slot08();
            virtual void slot0C();
            virtual void slot10();
            virtual void slot14();
            virtual void slot18();
            virtual void slot1C();
            virtual s32 selectedItem();
        };
        s32 n0 = *(s32 *)lbl_8055F420;
        Manager *mgr = *(Manager **)((char *)lbl_8055F420 + (n0 << 2) + 0x60);
        found = mgr->selectedItem();
    }
    #pragma pop
    obj = fn_8001285C();
    queryId = *(s32 *)((char *)obj + 4);
    parameter = *(s32 *)(lbl_8055F420 + 0x10);
    if (fn_8025FECC((s32)&localC, (s32)&local8, queryId, parameter) == 0) return;
    {
        void *d = fn_80016544((void *)localC);
        if ((*(u32 *)((char *)d + 0xA0) & 0x2) == 0) fn_80019144((char *)d + 0x2C);
    }
    #pragma cplusplus on
    {
        u8 *list = (u8 *)lbl_8055F420;
        u8 *p = list;
        u8 *current;
        struct Widget { virtual ~Widget(); };
        Widget *g;
        for (i = 0; i < *(s32 *)(list + 8); p += 4, i++) {
            if (VC0(*(void **)(p + 0x60), 0x48) == 0) {
                wasReady = 0;
                goto closeWidgets;
            }
        }
        wasReady = 1;
closeWidgets:
        current = (u8 *)lbl_8055F420;
        g = *(Widget **)(current + 0x14);
        if (g != 0) {
            delete g;
            *(void **)(current + 0x14) = 0;
        }
        lbl_8055F3EC = 0;
        for (i = 0; i < *(s32 *)(current + 8); i++) {
            obj = (*(void ***)(current + 0x18))[i];
            if (obj) VC1(obj, 0x08, 1);
        }
        for (i = 0; i < *(s32 *)(current + 0xC); i++) {
            obj = (*(void ***)(current + 0x3C))[i];
            if (obj) VC1(obj, 0x08, 1);
        }
    }
    #pragma cplusplus reset
    fn_80016970(0, firstVal, localC, local8);
    fn_800169F8((const char *)fn_8000DB34(fn_8000DA10()), 0);
    fn_80137C84(fn_802E4A10(), 0);
    {
        char buf[0xB0];
        s32 st[4];
        memset(buf, 0, 0xB0);
        st[0] = queryId;
        st[1] = -1;
        {
            void *q = fn_80012820(queryId);
            idx = *(s32 *)((char *)q + 0x70);
            while (idx-- > 0) {
                void *r = fn_80012870(queryId, idx);
                if (found == *(s32 *)r) st[1] = idx;
            }
        }
        st[2] = parameter;
        *(void **)&st[3] = buf;
        fn_8023BF4C(st);
    }
    fn_80016A44(0);
    fn_8001EFC8();
    lbl_8055F3E4 = fn_8027B878(parameter);
    sel = (char *)lbl_8055F420;
    *(s32 *)(sel + 8) = 0;
    *(s32 *)(sel + 0xC) = VC0(lbl_8055F3E4, 0x0C);
    memset((void *)(sel + 0x60), 0, 0x18);
    memset((void *)(sel + 0x54), 0, 0xC);
    *(s32 *)(sel + 0x1C) = 0;
    *(s32 *)(sel + 0x40) = 0;
    groupList = (u8 *)sel;
    groupIndex = 0;
    goto outerCheck;
outerBody:
    *(void **)(groupList + 0x54) = (void *)VC1(lbl_8055F3E4, 0x10, groupIndex);
    obj = fn_801284F8(0x2C, strBase + 0x144);
    if (obj) {
        item = (void *)VC1(lbl_8055F3E4, 0x10, groupIndex);
        *(s32 *)((char *)obj + 0x14) = 0;
        *(void **)obj = (void *)&lbl_80345E28;
        *(s32 *)((char *)obj + 0x20) = groupIndex;
        *(void **)((char *)obj + 0x18) = item;
        *(u8 *)((char *)obj + 0x1C) = 0;
        *(u8 *)((char *)obj + 0x1D) = 1;
        *(u8 *)((char *)obj + 0x1E) = 0;
        *(u8 *)((char *)obj + 0x1F) = 0;
        *(void **)((char *)obj + 0x24) = fn_8023512C(strBase + 0x150);
        *(void **)((char *)obj + 0x28) = fn_80232578(strBase + 0x15C);
    }
    count = *(s32 *)(sel + 0x40);
    {
        void **widgets = *(void ***)(sel + 0x3C);
        *(s32 *)(sel + 0x40) = count + 1;
        widgets[count] = obj;
    }
    itemIndex = 0;
    goto innerCheck;
innerBody:
    item = (void *)VC1(*(void **)(groupList + 0x54), 0x1C, itemIndex);
    count = *(s32 *)(sel + 8);
    *(s32 *)(sel + 0x60 + count * 4) = (s32)item;
    {
        void *w = fn_801284F8(0x28, strBase + 0x168);
        void **widgets;
        if (w) {
            void *group = (void *)VC1(lbl_8055F3E4, 0x10, groupIndex);
            item = (void *)VC1(group, 0x1C, itemIndex);
            *(s32 *)((char *)w + 0x14) = 0;
            *(void **)w = (void *)&lbl_80345EA0;
            *(void **)((char *)w + 0x18) = item;
            *(u8 *)((char *)w + 0x1E) = 0;
            *(u8 *)((char *)w + 0x1C) = 0;
            *(u8 *)((char *)w + 0x1D) = 1;
            *(void **)((char *)w + 0x20) = fn_8023512C(strBase + 0x150);
            *(void **)((char *)w + 0x24) = fn_80232578(strBase + 0x15C);
        }
        count = *(s32 *)(sel + 0x1C);
        widgets = *(void ***)(sel + 0x18);
        *(s32 *)(sel + 0x1C) = count + 1;
        widgets[count] = w;
    }
    *(s32 *)(sel + 8) = *(s32 *)(sel + 8) + 1;
    itemIndex++;
innerCheck:
    count = VC0(*(void **)(groupList + 0x54), 0x18);
    max = 6;
    if (count < 6) max = count;
    if (itemIndex < max) goto innerBody;
    groupList += 4;
    groupIndex++;
outerCheck:
    count = VC0(lbl_8055F3E4, 0x0C);
    max = 3;
    if (count < 3) max = count;
    if (groupIndex < max) goto outerBody;

    value = fn_80207848(strBase + 0x178, 0);
    *(void **)(sel + 0x14) = value;
    if (value) {
        float targetValue = lbl_80563B88;
        if (targetValue != *(float *)((char *)value + 8)) {
            *(u8 *)((char *)value + 0x4D) = 1;
            *(float *)((char *)value + 8) = targetValue;
        }
    } else fn_802E317C(strBase + 0x188);
    i = 0; j = 0;
    while (i < *(s32 *)(lbl_8055F420 + 8)) {
        if (lbl_8055F3EB == 0) {
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x18) + j), 0x60);
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x18) + j), 0x6C);
        } else if (i == *(s32 *)(lbl_8055F420 + 0)) {
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x18) + j), 0x68);
        } else if (i == *(s32 *)(lbl_8055F420 + 4) * 2 || i == *(s32 *)(lbl_8055F420 + 4) * 2 + 1) {
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x18) + j), 0x64);
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x18) + j), 0x6C);
        } else {
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x18) + j), 0x6C);
        }
        j += 4; i++;
    }
    i = 0; j = 0;
    while (i < *(s32 *)(lbl_8055F420 + 0xC)) {
        if (lbl_8055F3EB == 0) {
            if (i == *(s32 *)(lbl_8055F420 + 4)) {
                VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x3C) + j), 0x68);
            } else {
                VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x3C) + j), 0x64);
                VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x3C) + j), 0x6C);
            }
        } else if (i == *(s32 *)(lbl_8055F420 + 4)) {
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x3C) + j), 0x68);
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x3C) + *(s32 *)(lbl_8055F420 + 4) * 4), 0x70);
        } else {
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x3C) + j), 0x60);
            VC0(*(void **)(*(s32 *)(lbl_8055F420 + 0x3C) + j), 0x6C);
        }
        j += 4; i++;
    }
    {
        u8 *list = lbl_8055F420;
        u8 *p = list;
        for (i = 0; i < *(s32 *)(list + 8); p += 4, i++) {
            if (VC0(*(void **)(p + 0x60), 0x48) == 0) {
                ok = 0;
                goto checkRefresh;
            }
        }
        ok = 1;
    }
checkRefresh:
    if (fn_802E8D84() != 0) fn_802E7128();
    if (wasReady == 0 && ok != 0) lbl_8055F3E8 = 1;
}
void fn_802607C4(void *widget) {
    /* Set this selector widget's dim flag at +0x1D. */
    *(u8 *)((u8 *)widget + 0x1D) = 1;
}

void fn_802607D0(void *row) {
    /* Open this selector row's group: set the expanded flag at +0x1E (see SelectorGroupRow.expanded). */
    *(u8 *)((u8 *)row + 0x1E) = 1;
}

/* Clear this selector row's expanded (+0x1E) and on-cursor (+0x1C) flags. */
void fn_802607DC(void *row) {
    *(u8 *)((u8 *)row + 0x1E) = 0;
    *(u8 *)((u8 *)row + 0x1C) = 0;
}

void fn_802607EC(void *widget) {
    /* Clear this selector widget's dim flag at +0x1D. */
    *(u8 *)((u8 *)widget + 0x1D) = 0;
}

void fn_802607F8(void *self) {
    /* If this object's active flag at +0x1C is clear, set it along with flag +0x1F. */
    if (*(u8 *)((u8 *)self + 0x1C) == 0) {
        *(u8 *)((u8 *)self + 0x1C) = 1;
        *(u8 *)((u8 *)self + 0x1F) = 1;
    }
}

void fn_80260814(void *row) {
    /* Draw this selector row normally: clear the dim flag at +0x1D (see SelectorGroupRow.dim). */
    *(u8 *)((u8 *)row + 0x1D) = 0;
}

void fn_80260820(void *self) {
    /* If this object's active flag at +0x1C is clear, set flag +0x1E and mark it active. */
    if (*(u8 *)((u8 *)self + 0x1C) == 0) {
        *(u8 *)((u8 *)self + 0x1E) = 1;
        *(u8 *)((u8 *)self + 0x1C) = 1;
    }
}

void fn_8026083C(void *row) {
    /* Clear this selector row's on-cursor flag at +0x1C (SelectorGroupRow.on_cursor). */
    *(u8 *)((u8 *)row + 0x1C) = 0;
}

void fn_80260848(void *item) {
    /* Set this selector item widget's dim flag at +0x1D. */
    *(u8 *)((u8 *)item + 0x1D) = 1;
}

/* --- one group row of the challenge-difficulty selector ------------------ */
/* 0x2C bytes, allocated by fn_80260DC4 with the vtable named below: the item
   rows (SelectorItem, below) have the same shape without the group number at
   0x20.  Slot 0x8 of both vtables is the row's destructor, which the screen
   loop's cleanup calls as destroy(1). */
typedef struct {
    void *vtable;      /* 0x00 the vtable above */
    s32   base[4];     /* 0x04 widget base class */
    s32   unused_0x14; /* 0x14 kept zero */
    void *data;        /* 0x18 the data node this row shows */
    u8    on_cursor;   /* 0x1C the cursor is on this row */
    u8    dim;         /* 0x1D draw this row dimmed */
    u8    expanded;    /* 0x1E this row's group is open */
    u8    pad_0x1F;    /* 0x1F */
    s32   group;       /* 0x20 which group of the data source this row shows */
    void *art;         /* 0x24 gArt resource, from fn_8023512C */
    void *font;        /* 0x28 gText font block, from fn_80232578 */
} SelectorGroupRow;
#define SELECTOR_GROUP_VTABLE lbl_80345E28

#pragma push
#pragma small_data off
/* Deleting destructor of one challenge-selector group row -- slot 0x8 of its
 * vtable, which the screen loop's cleanup calls as destroy(1).  It drops the
 * two resources the row was built with (the gArt animation and the gText
 * font) and then frees the row itself when the delete flag is set. */
void *fn_80260854(SelectorGroupRow *row, s32 deleteFlag) {
    if (row != 0) {
        row->vtable = &SELECTOR_GROUP_VTABLE;
        /* fn_80235380 only reads its first argument; the vtable is what the
         * store above leaves in the second register. */
        fn_80235380((s32)row->art, (s32 *)&SELECTOR_GROUP_VTABLE);
        row->art = 0;
        fn_802328D4((s32)row->font);
        row->font = 0;
        if (deleteFlag > 0) fn_80128668(row);
    }
    return row;
}
#pragma pop
extern s32 fn_80128668(void);
extern s32 fn_802328D4(s32);
extern s32 fn_80235380(s32, s32 *);
/* --- one item row of the challenge-difficulty selector ------------------- */
/* 0x28 bytes, allocated by fn_80261C68 with the vtable named below; the group
   rows (SelectorGroupRow, above) have the same shape plus their group number
   at 0x20.  Slot 0x8 of both vtables is the destructor fn_80260854/fn_802608D4,
   which the screen's cleanup loop calls as destroy(1). */
typedef struct {
    void *vtable;      /* 0x00 the vtable above */
    s32   base[4];     /* 0x04 widget base class */
    s32   unused_0x14; /* 0x14 kept zero */
    void *data;        /* 0x18 the data node this row shows */
    u8    on_cursor;   /* 0x1C the cursor is on this row */
    u8    dim;         /* 0x1D draw this row dimmed */
    u8    expanded;    /* 0x1E this row's group is open */
    u8    pad_0x1F;    /* 0x1F */
    void *art;         /* 0x20 gArt resource, from fn_8023512C */
    void *font;        /* 0x24 gText font block, from fn_80232578 */
} SelectorItem;
#define SELECTOR_ITEM_VTABLE lbl_80345EA0
#pragma push
#pragma small_data off
/* Deleting destructor of one challenge-selector item row -- slot 0x8 of its
 * vtable, which the screen's cleanup loop calls as destroy(1).  It drops the
 * two resources the row was built with (the gArt animation and the gText font)
 * and then frees the row itself when the delete flag is set. */
void *fn_802608D4(SelectorItem *item, s32 deleteFlag) {
    if (item != 0) {
        *(void **)item = &SELECTOR_ITEM_VTABLE;
        /* fn_80235380 only reads its first argument; the vtable is what the
         * store above leaves in the second register. */
        fn_80235380((s32)item->art, (s32 *)&SELECTOR_ITEM_VTABLE);
        item->art = 0;
        fn_802328D4((s32)item->font);
        item->font = 0;
        if (deleteFlag > 0) ((void (*)(void *))fn_80128668)(item);
    }
    return item;
}
extern void *lbl_8055F3E4;
extern u8 lbl_8055F3E8;
extern s32 lbl_802FA6C0[];
extern u8 lbl_80498F00[];
extern s32 fn_80012810(void);
extern void fn_80012794(void);
extern void fn_80012790(s32);
extern void *fn_8027B878(s32);
extern void fn_8026003C(void);
extern s32 fn_802146BC(s32 *, s32, s32, s32);
extern s32 fn_80261948(s32 *);
extern s32 fn_802619A0(s32 *);
extern s32 fn_802619D8(s32 *, s32);
extern s32 fn_80261A08(s32 *, s32);
extern void fn_802619E8(void *, s32, s32);
extern void fn_80261980(void *, s32, s32, s32);
extern void fn_80261A18(void *, s32);
extern void fn_80261A7C(void *, s32);
extern void fn_80261AE8(s32 *, s32);
extern void fn_80261AF0(s32 *, s32);
extern void fn_80261C68(s32 *);
extern void fn_80262120(void *);
extern void fn_8026213C(void *);
extern void fn_80261688(void *, s32, s32, s32);
extern void fn_80260E04(s32 *, s32 *);
extern void fn_80261AA0(void);
extern void fn_80261A40(s32);
extern s32 fn_802616A8(void);
extern s32 fn_802613E0(void);
extern s32 fn_80261178(void *);
extern s32 fn_802610C8(void);
extern s32 fn_80260E30(void);
#pragma push
#pragma small_data on
#pragma pop
#pragma push
#pragma small_data off
#pragma pop
extern s32 table[];
#pragma push
#pragma small_data on
#pragma pop
#pragma push
#pragma small_data off
#pragma pop
#pragma cplusplus on
extern "C" s32 fn_80260DC4(s32, s32);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80260954(s32 arg0) {
    struct Dummy { virtual void destroy(s32); };
          typedef struct {
              s32 word[5];
          } Obj20;
          typedef struct {
              s32 header[6];
              s32 bufA[9];
              s32 bufB[15];
              Obj20 objects[19];
          } Frame;
      
          Frame frame;
        s32 *header;
          s32 sp8;
          s32 args[5];
          s32 initialMode;
          s32 currentMode;
          s32 i;
          s32 offset;
          u8 *stringBase = (u8 *)&lbl_80345B40;
          void *object;
          s32 value;
          s32 result;
          s32 *table;
          
          
        initialMode = fn_80012810();
          if (initialMode != 0x130) {
              if (initialMode != 0x134) {
                  fn_80012794();
              }
              fn_80012790(0x130);
          }
          lbl_8055F3E4 = fn_8027B878(arg0);
          header = frame.header;
          fn_8026213C(frame.bufA);
          fn_80262120(frame.bufB);
          *(void **)&lbl_8055F420 = &header[0];
          header[4] = arg0;
          header[1] = 0;
          header[0] = 0;
          header[5] = 0;
          fn_80261C68(header);
          table = lbl_802FA6C0;
      
      loop_6:
          ((void (*)(void))fn_8026003C)();
          if (lbl_8055F3E8 != 0) {
              fn_80261AF0(header, header[4] + 1);
              lbl_8055F3E8 = 0;
              if (header[4] == 0) {
                  lbl_8055F3EB = 0;
                  result = -1;
                  goto loop_end;
              }
          }
      
          fn_80261AE8(&sp8, header[4]);
          fn_80261A7C(&frame.objects[0], (s32)fn_80261AA0);
          fn_80261A18(&frame.objects[1], (s32)fn_80261A40);
      
          value = *(s32 *)(u32)fn_80261A08(frame.bufB, 0);
           fn_802619E8(&frame.objects[2], (s32)(stringBase + 0x1B8), value);
          value = *(s32 *)(u32)fn_80261A08(frame.bufB, 1);
           fn_802619E8(&frame.objects[3], (s32)(stringBase + 0x1C8), value);
          value = *(s32 *)(u32)fn_80261A08(frame.bufB, 2);
           fn_802619E8(&frame.objects[4], (s32)(stringBase + 0x1D8), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 0);
           fn_802619E8(&frame.objects[5], (s32)(stringBase + 0x1E8), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 1);
           fn_802619E8(&frame.objects[6], (s32)(stringBase + 0x1F8), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 2);
           fn_802619E8(&frame.objects[7], (s32)(stringBase + 0x208), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 3);
           fn_802619E8(&frame.objects[8], (s32)(stringBase + 0x218), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 4);
           fn_802619E8(&frame.objects[9], (s32)(stringBase + 0x228), value);
          value = *(s32 *)(u32)fn_802619D8(frame.bufA, 5);
           fn_802619E8(&frame.objects[10], (s32)(stringBase + 0x238), value);
          fn_80261980(&frame.objects[11], (s32)(stringBase + 0x248),
                      fn_802619A0(&sp8), 0);
          fn_80261980(&frame.objects[12], (s32)(stringBase + 0x258),
                      fn_80261948(&sp8), 0);
          fn_80261688(&frame.objects[13], 0x126, 0, (s32)fn_802616A8);
          fn_80261688(&frame.objects[14], 0x128, 0, (s32)fn_802613E0);
          fn_80261688(&frame.objects[15], 0xD, -2, (s32)fn_80261178);
          fn_80261688(&frame.objects[16], 0x121, 0, (s32)fn_802610C8);
          fn_80261688(&frame.objects[17], 0x1B, -1, (s32)fn_80260E30);
          fn_80260E04((s32 *)&frame.objects[18], (s32 *)&lbl_80498F00);
      
          args[0] = table[0];
          args[1] = table[1];
          args[2] = table[2];
          args[3] = table[3];
          args[4] = table[4];
          args[1] = (s32)&frame.objects[0];
      
      loop_10:
         result = fn_802146BC(args, -0x3E7, -0x3E7, 1);
         if (result == -1) {
             goto result_minus_one;
         }
         if (result >= 0) {
             goto result_retry;
         }
         if (result >= -2) {
             goto result_minus_two;
         }
         goto result_retry;

     result_retry:
         fn_802E317C(stringBase + 0x268);
         goto loop_10;

     result_minus_two:
         fn_80260DC4((s32)&sp8, -1);
         result = -2;
         goto result_done;

     result_minus_one:
         fn_80260DC4((s32)&sp8, -1);
         result = -1;
         goto result_done;

     result_done:
     loop_end:
          if (result != -1) {
              goto loop_6;
          }
      
          *(void **)&lbl_8055F420 = 0;
          if (header[5] != 0) {
              if (header[5] != 0) {
                  object = (void *)header[5];
                                  ((Dummy *)object)->destroy(1);
              }
              header[5] = 0;
          }
          lbl_8055F3EC = 0;
      
          for (i = 0, offset = 0; i < header[2]; offset += 4, i++) {
              object = *(void **)((u8 *)(u32)frame.bufA[0] + offset);
              if (object != 0) {
                                  ((Dummy *)object)->destroy(1);
              }
          }
          for (i = 0, offset = 0; i < header[3]; offset += 4, i++) {
              object = *(void **)((u8 *)(u32)frame.bufB[0] + offset);
              if (object != 0) {
                                  ((Dummy *)object)->destroy(1);
              }
          }
      
          frame.bufB[0] = 0;
          frame.bufB[1] = 0;
          frame.bufB[2] = 0;
          frame.bufA[0] = 0;
          frame.bufA[1] = 0;
          frame.bufA[2] = 0;
      
          currentMode = fn_80012810();
          if (initialMode != currentMode) {
              if (currentMode != 0x134) {
                  fn_80012794();
              }
              if (initialMode != 0x134) {
                  fn_80012790(initialMode);
              }
          }
      }
#pragma pop
s32 fn_80260DC4(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

void fn_80260E04(s32 *dst, s32 *source) {
    /* Copy a 5-word block from source to dst, reading through a volatile
     * pointer so all five words are loaded before any is written. */
    s32 fifth;
    s32 fourth;
    s32 third;
    s32 second;
    s32 first;
    volatile s32 *src = source;
    first = src[0];
    second = src[1];
    third = src[2];
    fourth = src[3];
    fifth = src[4];
    dst[0] = first;
    dst[1] = second;
    dst[2] = third;
    dst[3] = fourth;
    dst[4] = fifth;
}

#pragma push
#pragma cplusplus on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* The challenge-difficulty selector (described in full further down). */
typedef struct {
    s32 cursor;                 /* 0x00 item the cursor is on */
    s32 group;                  /* 0x04 group the cursor is on */
    s32 item_count;             /* 0x08 widgets in the item array */
    s32 group_count;            /* 0x0C widgets in the group array */
    u8  pad_0x10[4];
    void *value_widget;         /* 0x14 the value display, looked up by fn_80207848 */
    u8 *item_widgets;           /* 0x18 SelectorWidget *[item_count] */
    s32 item_widget_count;      /* 0x1C items pushed on the item array so far */
    u8  pad_0x20[0x1C];
    u8 *group_widgets;          /* 0x3C SelectorWidget *[group_count] */
    s32 group_widget_count;     /* 0x40 groups pushed on the group array so far */
    u8  pad_0x44[0x10];
    void *group_data[3];        /* 0x54 the data node of each group built */
    s32 group_item_data[6];     /* 0x60 the data nodes of the items built so far */
} SelectorView;
#define SELECTOR          ((SelectorView *)lbl_8055F420)
#define SELECTOR_IN_ITEMS (lbl_8055F3EB) /* 0: cursor on a group, 1: in its items */
struct SelectorWidget {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C();
    virtual void setDim();      /* 0x60 */
    virtual void clearDim();    /* 0x64 */
    virtual void setCursor();   /* 0x68 */
    virtual void clearCursor(); /* 0x6C */
    virtual void setExpanded(); /* 0x70 */
};
/* Close the group the selector's cursor is inside (input event 0x1B of the
 * challenge screen, the pair of fn_80261178, which opens it).
 *
 * Only reachable from inside a group: with the cursor still on the group list the
 * callback reports that it did nothing by returning 1, which is how the screen
 * tells a "leave" pressed there.  Otherwise the cursor steps back out to the
 * groups -- every group widget first loses its cursor -- and both widget lists are
 * repainted the way fn_80261178 does it, now with the cursor outside: the whole
 * item list dims and loses its cursor, the group the cursor stands on gets
 * setCursor() and every other group comes out of the dim state. */
extern "C" s32 fn_80260E30(void) {
    s32 offset;
    s32 i;

    if (SELECTOR_IN_ITEMS != 0) {
        /* the cursor leaves the item list and goes back to the groups */
        SELECTOR_IN_ITEMS = 0;
        {
            /* This first loop keeps its own counter pair in its own block;
             * reusing the outer i and offset here shifts the registers the
             * loops below leave their widgets in. */
            s32 groupOffset;
            s32 groupIndex;
            groupIndex = 0;
            groupOffset = 0;
            for (; groupIndex < SELECTOR->group_count; groupOffset += 4, groupIndex++) {
                (*(SelectorWidget **)(SELECTOR->group_widgets + groupOffset))->clearCursor();
            }
        }

        /* repaint the item list */
        i = 0;
        offset = 0;
        for (; i < SELECTOR->item_count; offset += 4, i++) {
            if (SELECTOR_IN_ITEMS == 0) {
                /* the cursor went back to the groups, so the whole list dims;
                 * the branches below it are the ones the callbacks that run
                 * with the cursor inside a group take */
                (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setDim();
                (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
            } else if (i == SELECTOR->cursor) {
                (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setCursor();
            } else if (i == SELECTOR->group * 2 || i == SELECTOR->group * 2 + 1) {
                /* the two items of the open group stay bright */
                (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearDim();
                (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
            } else {
                (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
            }
        }

        /* repaint the group list */
        i = 0;
        offset = 0;
        for (; i < SELECTOR->group_count; offset += 4, i++) {
            if (SELECTOR_IN_ITEMS == 0) {
                if (i == SELECTOR->group) {
                    /* the group the cursor came back to */
                    (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
                } else {
                    (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearDim();
                    (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
                }
            } else if (i == SELECTOR->group) {
                /* the group the cursor is inside: open, and let it show its items */
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
                (*(SelectorWidget **)(SELECTOR->group_widgets + SELECTOR->group * 4))->setExpanded();
            } else {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setDim();
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
            }
        }
    } else {
        return 1;
    }
    return 0;
}
#pragma push
#pragma cplusplus on
/* If active, lock, invoke two virtual getters on the current manager object, pass results to handler, then unlock/clear state. */
extern "C" s32 fn_802610C8(void) {
    struct Manager {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual s32 getParam(u8 *self);
        virtual s32 getValue();
    };
    s32 value = 0;
    u32 *managerBase;
    Manager *manager;
    s32 param;
    if (lbl_8055F3EB != 0) {
        lbl_8055F3EA = 1;
        fn_80214A9C(30);
        managerBase = (u32 *)lbl_8055F420;
        manager = *(Manager **)(managerBase + managerBase[0] + 0x18);
        value = manager->getValue();
        managerBase = (u32 *)lbl_8055F420;
        manager = *(Manager **)(managerBase + managerBase[0] + 0x18);
        param = manager->getParam((u8 *)managerBase);
        ((s32 (*)(s32, s32))fn_8025C204)(param, value);
        fn_80214AF0(30);
        fn_80230E90(0);
        lbl_8055F3EA = 0;
    }
    return 0;
}
#pragma pop
#ifndef SELECTOR
/* --- the two-level selector of the challenge-difficulty screen --------- */
/* lbl_8055F420 points at the frame header the screen loop (fn_80260954)
   builds on its stack, which carries the state of its cursor: a list of
   groups (the difficulties, from the data source lbl_8055F3E4) and, inside
   each group, its items.  fn_80261C68 creates the two widget arrays and
   stores them at 0x18 and 0x3C; the input callbacks fn_80261178 (enter),
   fn_802616A8 (up), fn_802613E0 (down) and fn_80260E30 (leave) move the
   cursor and repaint both lists, and lbl_8055F3EB says which list the
   cursor is in. */
typedef struct {
    s32 cursor;                 /* 0x00 item the cursor is on */
    s32 group;                  /* 0x04 group the cursor is on */
    s32 item_count;             /* 0x08 widgets in the item array */
    s32 group_count;            /* 0x0C widgets in the group array */
    u8  pad_0x10[4];
    void *value_widget;         /* 0x14 the value display, looked up by fn_80207848 */
    u8 *item_widgets;           /* 0x18 SelectorWidget *[item_count] */
    s32 item_widget_count;      /* 0x1C items pushed on the item array so far */
    u8  pad_0x20[0x1C];
    u8 *group_widgets;          /* 0x3C SelectorWidget *[group_count] */
    s32 group_widget_count;     /* 0x40 groups pushed on the group array so far */
    u8  pad_0x44[0x10];
    void *group_data[3];        /* 0x54 the data node of each group built */
    s32 group_item_data[6];     /* 0x60 the data nodes of the items built so far */
} SelectorView;
#define SELECTOR          ((SelectorView *)lbl_8055F420)
#define SELECTOR_IN_ITEMS (lbl_8055F3EB) /* 0: cursor on a group, 1: in its items */

/* --- a group or item widget of that selector --------------------------- */
/* Slots 0x08-0x5C belong to the widget base class (its Draw is the slot the
   .data vtables fill at 0x28, fn_802621F0 for items).  The selector only
   uses the five state setters below, which set the flags Draw reads: 0x1C
   = the cursor is on this widget, 0x1D = dim it.  0x60 and 0x64 are the
   slots the two vtables (lbl_80345E28 groups, lbl_80345EA0 items) point at
   fn_802607C4/fn_802607EC and fn_80260848/fn_80260814, which set and clear
   byte 0x1D; the last three are named from how the selector calls them. */
struct SelectorWidget {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C();
    virtual void setDim();      /* 0x60 */
    virtual void clearDim();    /* 0x64 */
    virtual void setCursor();   /* 0x68 */
    virtual void clearCursor(); /* 0x6C */
    virtual void setExpanded(); /* 0x70 */
};
#endif

/* --- the data the selector shows ---------------------------------------- */
/* lbl_8055F3E4, the handle fn_8027B878 returns for the screen's argument.  Its
   groups are the difficulties and each group's items are the choices listed
   under it; fn_80261C68 turns at most 3 groups and 6 items per group into the
   two widget lists. */
struct SelectorDataGroup;
struct SelectorData {
    virtual void v08();
    virtual s32 groupCount();                /* 0x0C how many groups there are */
    virtual SelectorDataGroup *group(s32);   /* 0x10 one group, by number */
    virtual void v14();
};
struct SelectorDataGroup {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual s32 itemCount();                 /* 0x18 how many items this group has */
    virtual void *item(s32);                 /* 0x1C one item's data node */
};
#pragma pop
#pragma push
#pragma cplusplus on
/* Open the group the selector's cursor is on (input event 0xD of the challenge
 * screen, the pair of fn_80260E30, which closes it again).
 *
 * Only reachable from the group list: from inside a group the callback reports
 * that it did nothing by returning 1.  Otherwise the cursor moves into the
 * group, on its first item (the group holds the two items group * 2 and
 * group * 2 + 1), and both widget lists are repainted as fn_802613E0 does it:
 * the item under the cursor gets setCursor(), the two items of the open group
 * come out of the dim state, everything else is dimmed, and the open group is
 * the one widget that gets setExpanded().
 */
extern "C" s32 fn_80261178(void *unused) {
    s32 offset;
    s32 i;

    if (SELECTOR_IN_ITEMS != 0) return 1;

    /* the cursor goes into the group it was standing on */
    SELECTOR_IN_ITEMS = 1;
    i = 0;
    offset = 0;
    SELECTOR->cursor = SELECTOR->group << 1;

    /* repaint the item list */
    for (; i < SELECTOR->item_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            /* the cursor is not here, so the whole list dims */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else if (i == SELECTOR->cursor) {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setCursor();
        } else if (i == SELECTOR->group * 2 || i == SELECTOR->group * 2 + 1) {
            /* the two items of the group that was opened stay bright */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        }
    }

    /* repaint the group list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->group_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            if (i == SELECTOR->group) {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            } else {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearDim();
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
            }
        } else if (i == SELECTOR->group) {
            /* the group the cursor is inside: open, and let it show its items */
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            (*(SelectorWidget **)(SELECTOR->group_widgets + SELECTOR->group * 4))->setExpanded();
        } else {
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
        }
    }
    return 0;
}
/* Move the selector's cursor down (input event 0x128 of the challenge screen).
 *
 * The cursor walks the group list while it is outside one, and the items of
 * its group once it is inside; either way it stops at the last entry.  Both
 * widget lists are then repainted: the widget the cursor is on gets
 * setCursor(), the items of the group the cursor belongs to are taken out of
 * the dim state, and everything else is dimmed and cleared.  fn_802616A8 is
 * the same walk upwards.
 */
extern "C" s32 fn_802613E0(void) {
    s32 offset;
    s32 i;

    if (SELECTOR_IN_ITEMS == 0) {
        /* still on the group list: go to the next group */
        SELECTOR->group += 1;
        if (SELECTOR->group >= SELECTOR->group_count) {
            SELECTOR->group = SELECTOR->group_count - 1;
        }
    } else {
        /* inside the group: go to its next item, the last of the two shown */
        SELECTOR->cursor += 1;
        if (SELECTOR->cursor > SELECTOR->group * 2 + 1) {
            SELECTOR->cursor = SELECTOR->group * 2 + 1;
        }
    }

    /* repaint the item list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->item_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            /* the cursor is not here, so the whole list dims */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else if (i == SELECTOR->cursor) {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setCursor();
        } else if (i == SELECTOR->group * 2 || i == SELECTOR->group * 2 + 1) {
            /* the two items of the group the cursor is in stay bright */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        }
    }

    /* repaint the group list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->group_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            if (i == SELECTOR->group) {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            } else {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearDim();
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
            }
        } else if (i == SELECTOR->group) {
            /* the group the cursor is inside: open, and let it show its items */
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            (*(SelectorWidget **)(SELECTOR->group_widgets + SELECTOR->group * 4))->setExpanded();
        } else {
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
        }
    }
    return 0;
}
#pragma cplusplus off
extern s32 lbl_802FA6A8[];
extern u8 lbl_8055B860;
#pragma push
#pragma scheduling invalid_target
void fn_80261688(void *item, s32 keyCode, s32 delta, s32 handler) {
    /* Initialize a kind-6 debug-menu item: a key-binding row holding the handler,
     * key code and delta, with the default empty label. */
    struct MenuRow {
        void *name;  /* 0x00 */
        int type;    /* 0x04 */
        void *data;  /* 0x08 */
        int a;       /* 0x0C */
        int b;       /* 0x10 */
    };
    struct MenuRow *row = (struct MenuRow *)item;
    row->data = (void *)handler;
    row->type = 6;
    row->name = &lbl_8055B860;
    row->a = delta;
    row->b = keyCode;
}
#pragma push
#pragma cplusplus on
/* Move the selector's cursor up (the input event pairing with fn_802613E0).
 *
 * The cursor walks the group list while it is outside one, and the items of
 * its group once it is inside; either way it stops at the first entry.  Both
 * widget lists are then repainted as fn_802613E0 does it: the widget holding
 * the cursor gets setCursor(), the items of the cursor's group come out of the
 * dim state and everything else is dimmed and cleared.
 */
extern "C" s32 fn_802616A8(void) {
    s32 offset;
    s32 i;

    if (SELECTOR_IN_ITEMS == 0) {
        /* still on the group list: go back to the previous group */
        SELECTOR->group -= 1;
        if (SELECTOR->group < 0) {
            SELECTOR->group = 0;
        }
    } else {
        /* inside the group: go to its previous item, the first of the two shown */
        SELECTOR->cursor -= 1;
        if (SELECTOR->cursor < SELECTOR->group * 2) {
            SELECTOR->cursor = SELECTOR->group * 2;
        }
    }

    /* repaint the item list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->item_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            /* the cursor is not here, so the whole list dims */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else if (i == SELECTOR->cursor) {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setCursor();
        } else if (i == SELECTOR->group * 2 || i == SELECTOR->group * 2 + 1) {
            /* the two items of the group the cursor is in stay bright */
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        }
    }

    /* repaint the group list */
    i = 0;
    offset = 0;
    for (; i < SELECTOR->group_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            if (i == SELECTOR->group) {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            } else {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearDim();
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
            }
        } else if (i == SELECTOR->group) {
            /* the group the cursor is inside: open, and let it show its items */
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            (*(SelectorWidget **)(SELECTOR->group_widgets + SELECTOR->group * 4))->setExpanded();
        } else {
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
        }
    }
    return 0;
}
#pragma pop
s32 fn_80261948(s32 *indexPtr) {
    /* Return the bottom-bar art filename (bar4_bot_e/s/m.art) selected by *indexPtr. */
    s32 *p = lbl_802FA6A8;
    s32 artNames[3];
    artNames[0] = *p++;
    artNames[1] = *p++;
    artNames[2] = *p;
    return artNames[*indexPtr];
}

#pragma scheduling invalid_target
/* Initialize a debug-menu item of kind 3: store the label pointer, the data
 * value and one kind-specific word, and clear the last word (DbgMenuItem). */
void fn_80261980(void *item, s32 name, s32 data, s32 a) {
    s32 zero;
    *(s32 *)item = name;
    zero = 0;
    *(s32 *)((u8 *)item + 4) = 3;
    *(s32 *)((u8 *)item + 8) = data;
    *(s32 *)((u8 *)item + 0xC) = a;
    *(s32 *)((u8 *)item + 0x10) = zero;
}
#pragma scheduling on
extern s32 lbl_802FA6B4[];
/* Returns the "bar4 top" art filename (index 0=e, 1=s, 2=m) for the index at *arg0. */
s32 fn_802619A0(s32 *indexPtr) {
    s32 *p = lbl_802FA6B4;
    s32 artNames[3];
    artNames[0] = *p++;
    artNames[1] = *p++;
    artNames[2] = *p;
    return artNames[*indexPtr];
}

/* Return the byte address of word `index` in the array whose base address is stored at *basePtr. */
s32 fn_802619D8(s32 *basePtr, s32 index) {
    return *basePtr + index * 4;
}

/* Initialize a debug-menu item of kind 5: store the label pointer and the data
 * value, and clear the two kind-specific words (see DbgMenuItem in this file). */
void fn_802619E8(void *item, s32 name, s32 data) {
    s32 zero = 0;
    *(s32 *)item = name;
    *(s32 *)((u8 *)item + 4) = 5;
    *(s32 *)((u8 *)item + 8) = data;
    *(s32 *)((u8 *)item + 0xC) = zero;
    *(s32 *)((u8 *)item + 0x10) = zero;
}

/* Return the byte address of word `index` in the array whose base address is stored at *basePtr. */
s32 fn_80261A08(s32 *basePtr, s32 index) {
    return *basePtr + index * 4;
}

/* One line of a debug menu: label, kind (8 = callback), the value/callback it
   edits and two kind-specific words. */
typedef struct DbgMenuItem {
    void *name;
    int type;
    void *data;
    int a;
    int b;
} DbgMenuItem;

void fn_80261A18(void *arg0, s32 arg1) {
    /* Set up a debug-menu item that invokes `arg1` when selected (kind 8). */
    DbgMenuItem *item = (DbgMenuItem *)arg0;
    item->data = (void *)arg1;
    item->type = 8;
    item->name = &lbl_8055BAB8;
    item->a = 2;
    item->b = 0;
}

void fn_80261A40(s32 selection) {
    /* Menu callback: set the challenge-select flag when the selected index is 2. */
    fn_80236914();
    *(signed char*)&lbl_8055F3E9 = (selection - 2) == 0;
}

void fn_80261A7C(void *arg0, s32 arg1) {
    /* Set up a debug-menu item that invokes `arg1` when selected (kind 8). */
    DbgMenuItem *item = (DbgMenuItem *)arg0;
    item->data = (void *)arg1;
    item->type = 8;
    item->name = &lbl_8055BAC0;
    item->a = 0;
    item->b = 0;
}

/* Iterates over count entries stored at offset 0xC of lbl_8055F420 and calls
 * fn_80214A9C for each with argument (index + 10). */
void fn_80261AA0(void) {
    s32 index;
    index = 0;
    goto check;
loop:
    fn_80214A9C(index + 10);
    index++;
check:
    if (index < *(s32 *)(lbl_8055F420 + 0xC)) goto loop;
}

extern void fn_801345D8(char *, s32, const char *, ...);
extern s32 fn_80131234(const void *);
#pragma push
#pragma small_data off
extern char lbl_80345DE0[];
extern char lbl_80345E0C[];
extern u8 lbl_80498F20[];
extern s32 lbl_802FA6D4[];
#pragma pop
#pragma push
#pragma small_data on
extern u8 lbl_8055C418;
extern u8 lbl_8055C420;
#pragma pop

/* Store `value` into the s32 pointed to by `dst`. */
void fn_80261AE8(s32 *dst, s32 value) { *dst = value; }

#pragma scheduling invalid_target
void fn_80261AF0(s32 *arg0, s32 arg1) {
    struct Frame {
        s32 args[6];
        s32 objects[6][5];
        char buffer[116];
    } frame;
    register s32 zero = 0;
    register s32 zero1 = 0;
    register s32 zero2 = 0;
    register s32 three = 3;
    register s32 two = 2;
    register s32 six = 6;
    register s32 minusTwo = -2;
    register s32 thirteen = 13;
    register s32 eight = 8;
    register s32 *b = (s32*)lbl_80498F00;
    register s32 func = (s32)fn_80261A40;
    s32 hash1;
    s32 hash2;
    fn_801345D8(frame.buffer, 0x64, lbl_80345DE0, arg1);
    frame.objects[0][0] = zero;
    frame.objects[0][1] = 5;
    frame.objects[0][2] = (s32)lbl_80498F20;
    frame.objects[0][3] = zero;
    frame.objects[0][4] = zero;
    hash1 = fn_80131234(lbl_80345E0C);
    frame.objects[1][0] = (s32)&lbl_8055C418;
    frame.objects[1][1] = three;
    frame.objects[1][2] = hash1;
    frame.objects[1][3] = zero1;
    frame.objects[1][4] = zero;
    hash2 = fn_80131234(frame.buffer);
    frame.objects[2][0] = (s32)&lbl_8055C420;
    frame.objects[2][1] = three;
    frame.objects[2][2] = hash2;
    frame.objects[2][3] = zero2;
    frame.objects[2][4] = zero;
    frame.objects[3][0] = (s32)&lbl_8055B860;
    frame.objects[3][1] = six;
    frame.objects[3][2] = zero;
    frame.objects[3][3] = minusTwo;
    frame.objects[3][4] = thirteen;
    frame.objects[4][0] = (s32)&lbl_8055BAB8;
    frame.objects[4][1] = eight;
    frame.objects[4][2] = func;
    frame.objects[4][3] = two;
    frame.objects[4][4] = zero;
    frame.objects[5][0] = ((s32*)lbl_80498F00)[0];
    frame.objects[5][1] = ((s32*)lbl_80498F00)[1];
    frame.objects[5][2] = ((s32*)lbl_80498F00)[2];
    frame.objects[5][3] = ((s32*)lbl_80498F00)[3];
    frame.objects[5][4] = ((s32*)lbl_80498F00)[4];
    {
        s32 *a = lbl_802FA6D4;
        frame.args[0] = a[0];
        frame.args[2] = a[2];
        frame.args[3] = a[3];
        frame.args[4] = a[4];
    }
    frame.args[1] = (s32)frame.objects;
    fn_802146BC(frame.args, -0x3E7, -0x3E7, 1);
}

#pragma cplusplus on
extern "C" void *fn_801284F8(s32, void *);
extern "C" void *fn_80207848(void *, s32);
extern "C" void *fn_8023512C(void *);
extern "C" void *fn_80232578(void *);
extern "C" void *memset(void *, int, unsigned int);
/* Repaint both widget lists of the selector for its cursor state. */
static inline void Selector_Repaint(void) {
    s32 i;
    s32 offset;

    for (i = 0, offset = 0; i < SELECTOR->item_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else if (i == SELECTOR->cursor) {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->setCursor();
        } else if (i == SELECTOR->group * 2 || i == SELECTOR->group * 2 + 1) {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearDim();
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        } else {
            (*(SelectorWidget **)(SELECTOR->item_widgets + offset))->clearCursor();
        }
    }
    for (i = 0, offset = 0; i < SELECTOR->group_count; offset += 4, i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            if (i == SELECTOR->group) {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            } else {
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearDim();
                (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
            }
        } else if (i == SELECTOR->group) {
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setCursor();
            (*(SelectorWidget **)(SELECTOR->group_widgets + SELECTOR->group * 4))->setExpanded();
        } else {
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->setDim();
            (*(SelectorWidget **)(SELECTOR->group_widgets + offset))->clearCursor();
        }
    }
}
#pragma scheduling invalid_target
extern "C" void fn_80261C68(s32 *arg0) {
    /* Build both widget lists of the challenge-difficulty selector.
     *
     * arg0 is the screen's frame header, which becomes lbl_8055F420 (SELECTOR).
     * For every group of the data source (at most 3) one SelectorGroupRow is
     * allocated and pushed on the group list at 0x3C, and for every one of its
     * items (at most 6) one SelectorItem is allocated and pushed on the item
     * list at 0x18; the group's data node goes to 0x54 and each item's data
     * node to 0x60.  Both kinds of row start off-cursor and dimmed (byte 0x1D)
     * and hold the gArt animation and gText font Draw needs.  The value display
     * named at stringBase + 0x178 is looked up for the header's 0x14 slot, and
     * both lists are finally painted for the cursor state -- the same painting
     * Selector_Repaint() does, which the original keeps inline here. */
    u8 *stringBase;
    u8 *groupList;
    s32 groupIndex;
    s32 itemIndex;
    s32 i;
    s32 j;
    s32 count;
    s32 max;
    void *object;
    void *item;
    float targetValue;
    SelectorView *base;

    stringBase = (u8 *)&lbl_80345B40;
    ((SelectorView *)arg0)->item_count = 0;
    ((SelectorView *)arg0)->group_count = ((SelectorData *)lbl_8055F3E4)->groupCount();
    memset((char *)arg0 + 0x60, 0, 0x18);
    memset((char *)arg0 + 0x54, 0, 0xC);
    ((SelectorView *)arg0)->item_widget_count = 0;
    ((SelectorView *)arg0)->group_widget_count = 0;
    groupList = (u8 *)arg0;
    groupIndex = 0;
    goto outerCheck;
outerBody:
    /* the group's data node, kept at 0x54 so the inner loop can reach it */
    *(SelectorDataGroup **)(groupList + 0x54) =
        ((SelectorData *)lbl_8055F3E4)->group(groupIndex);
    object = fn_801284F8(0x2C, stringBase + 0x144); /* one SelectorGroupRow */
    if (object != 0) {
        item = (void *)((SelectorData *)lbl_8055F3E4)->group(groupIndex);
        ((SelectorGroupRow *)object)->unused_0x14 = 0;
        ((SelectorGroupRow *)object)->vtable = &SELECTOR_GROUP_VTABLE;
        ((SelectorGroupRow *)object)->group = groupIndex;
        ((SelectorGroupRow *)object)->data = item;
        ((SelectorGroupRow *)object)->on_cursor = 0;
        ((SelectorGroupRow *)object)->dim = 1;
        ((SelectorGroupRow *)object)->expanded = 0;
        ((SelectorGroupRow *)object)->pad_0x1F = 0;
        ((SelectorGroupRow *)object)->art = fn_8023512C(stringBase + 0x150);
        ((SelectorGroupRow *)object)->font = fn_80232578(stringBase + 0x15C);
    }
    {
        void **array = (void **)((SelectorView *)arg0)->group_widgets;
        count = ((SelectorView *)arg0)->group_widget_count;
        ((SelectorView *)arg0)->group_widget_count = count + 1;
        array[count] = object;
    }
    itemIndex = 0;
    goto innerCheck;
innerBody:
    item = (void *)((SelectorDataGroup *)*(void **)(groupList + 0x54))->item(itemIndex);
    count = ((SelectorView *)arg0)->item_count;
    ((SelectorView *)arg0)->group_item_data[count] = (s32)item;
    item = fn_801284F8(0x28, stringBase + 0x168); /* one SelectorItem */
    if (item != 0) {
        object = ((SelectorData *)lbl_8055F3E4)->group(groupIndex);
        object = ((SelectorDataGroup *)object)->item(itemIndex);
        ((SelectorItem *)item)->unused_0x14 = 0;
        ((SelectorItem *)item)->vtable = &SELECTOR_ITEM_VTABLE;
        ((SelectorItem *)item)->data = object;
        ((SelectorItem *)item)->expanded = 0;
        ((SelectorItem *)item)->on_cursor = 0;
        ((SelectorItem *)item)->dim = 1;
        ((SelectorItem *)item)->art = fn_8023512C(stringBase + 0x150);
        ((SelectorItem *)item)->font = fn_80232578(stringBase + 0x15C);
    }
    {
        void **array = (void **)((SelectorView *)arg0)->item_widgets;
        count = ((SelectorView *)arg0)->item_widget_count;
        ((SelectorView *)arg0)->item_widget_count = count + 1;
        array[count] = item;
    }
    itemIndex++;
    ((SelectorView *)arg0)->item_count += 1;
innerCheck:
    /* a group shows at most six of its items */
    count = ((SelectorDataGroup *)*(void **)(groupList + 0x54))->itemCount();
    max = 6;
    if (count < 6) max = count;
    if (itemIndex < max) goto innerBody;
    groupList += 4;
    groupIndex++;
outerCheck:
    /* and the screen offers at most three groups */
    count = ((SelectorData *)lbl_8055F3E4)->groupCount();
    max = 3;
    if (count < 3) max = count;
    if (groupIndex < max) goto outerBody;

    object = fn_80207848(stringBase + 0x178, 0);
    ((SelectorView *)arg0)->value_widget = object;
    if (object != 0) {
        targetValue = lbl_80563B88;
        if (targetValue != *(float *)((char *)object + 8)) {
            *(u8 *)((char *)object + 0x4D) = 1;
            *(float *)((char *)object + 8) = targetValue;
        }
    } else {
        fn_802E317C(stringBase + 0x188);
    }

    i = 0;
    j = 0;
    goto firstCheck;
firstBody:
    if (SELECTOR_IN_ITEMS == 0) {
        object = *(void **)(base->item_widgets + j);
        ((SelectorWidget *)object)->setDim();
        object = *(void **)(SELECTOR->item_widgets + j);
        ((SelectorWidget *)object)->clearCursor();
    } else if (i == base->cursor) {
        object = *(void **)(base->item_widgets + j);
        ((SelectorWidget *)object)->setCursor();
    } else if (i == base->group * 2 || i == base->group * 2 + 1) {
        object = *(void **)(base->item_widgets + j);
        ((SelectorWidget *)object)->clearDim();
        object = *(void **)(SELECTOR->item_widgets + j);
        ((SelectorWidget *)object)->clearCursor();
    } else {
        object = *(void **)(base->item_widgets + j);
        ((SelectorWidget *)object)->clearCursor();
    }
    j += 4;
    i++;
firstCheck:
    base = SELECTOR;
    if (i < base->item_count) goto firstBody;

    i = 0;
    for (j = 0; base = SELECTOR, i < base->group_count; i++) {
        if (SELECTOR_IN_ITEMS == 0) {
            if (i == base->group) {
                ((SelectorWidget *)*(void **)(base->group_widgets + j))->setCursor();
            } else {
                ((SelectorWidget *)*(void **)(base->group_widgets + j))->clearDim();
                ((SelectorWidget *)*(void **)(SELECTOR->group_widgets + j))->clearCursor();
            }
        } else if (i == base->group) {
            ((SelectorWidget *)*(void **)(base->group_widgets + j))->setCursor();
            base = SELECTOR;
            ((SelectorWidget **)base->group_widgets)[base->group]->setExpanded();
        } else {
            ((SelectorWidget *)*(void **)(base->group_widgets + j))->setDim();
            ((SelectorWidget *)*(void **)(SELECTOR->group_widgets + j))->clearCursor();
        }
        j += 4;
    }
}
#pragma scheduling on
#pragma cplusplus reset

void fn_80262120(void *vec) {
    /* Init an inline-buffer vector: data points at the inline storage (+0xC),
     * length starts at 0, capacity is 3; the zero temp is kept for store order. */
    s32 zero;
    *(s32 *)vec = (s32)((u8 *)vec + 0xC);
    *(s32 *)((u8 *)vec + 8) = 3;
    zero = 0;
    *(s32 *)((u8 *)vec + 4) = zero;
}

#pragma scheduling invalid_target
void fn_8026213C(void *object) {
    /* Initialize a collection object: point its items at the inline storage
     * at +0xC, set the element count (+0x4) to 0 and its capacity (+0x8) to 6. */
    *(s32 *)object = (s32)((u8 *)object + 0xC);
    *(s32 *)((u8 *)object + 8) = 6;
    *(s32 *)((u8 *)object + 4) = 0;
}
#pragma scheduling on
/* No-op virtual stub in this build, next to fn_8026215C and the default
 * getter fn_80262160; no implementation is needed here. */
void fn_80262158(void) {
}

/* No-op virtual stub in this build, next to fn_80262158 and the default
 * getter fn_80262160; no implementation is needed here. */
void fn_8026215C(void) {
}

/* Stub returning a default value of 0. */
s32 fn_80262160(void) {
    return 0;
}

void fn_80262168(void *obj) {
    /* If the object's flag at +0x1E is set while lbl_8055F3E9 is set and lbl_8055F3EA is clear,
       clear that flag and call fn_80230E90(0). Then enable UI element 0x1E with fn_80214AF0 if
       lbl_8055F3EB is set and lbl_8055F3EA is clear, otherwise disable it with fn_80214A9C. */
    if (*(u8 *)((u8 *)obj + 0x1E) && lbl_8055F3E9 && !lbl_8055F3EA) {
        fn_80230E90(0);
        *(u8 *)((u8 *)obj + 0x1E) = 0;
    }
    if (lbl_8055F3EB && !lbl_8055F3EA) {
        fn_80214AF0(0x1E);
        return;
    }
    fn_80214A9C(0x1E);
}

extern void fn_80230C30(float *, float *, s32, s32);
extern void fn_80230F78(u8 *, float *, u32 *, s32);
extern void fn_802354A0(void *, s32, s32, float, float, float, float, float);
extern void fn_80232BA4(char *, s32, s32, s32, float, float, float, float, float);
extern void fn_801308F4(char *, s32, s32);
extern void fn_801345D8(char *, s32, const char *, ...);
extern void *__AXGetStackHead(void);
extern u8 lbl_8055F3F4;
extern float lbl_8055F3F0;
extern char lbl_8055C428;
extern char lbl_8055C42C;
extern char lbl_8055C434;
extern double lbl_80563BA8;
extern float lbl_80563B88;
extern float lbl_80563B8C;
extern float lbl_80563B90;
extern float lbl_80563B94;
extern float lbl_80563B98;
extern float lbl_80563B9C;
extern float lbl_80563BA0;
#pragma cplusplus on
extern "C" void fn_802621F0(void *arg0) { struct Dummy { virtual void m0() = 0; virtual char *m1() = 0; virtual void m2() = 0; virtual char *m3() = 0; virtual void m4() = 0; virtual void m5() = 0; virtual void m6() = 0; virtual void m7() = 0; virtual s32 m8() = 0; virtual s32 m9() = 0; virtual s32 m10() = 0; virtual s32 m11() = 0; virtual void m12() = 0; virtual s32 m13() = 0; virtual void m14() = 0; virtual s32 m15() = 0; }; char text2[0x1E]; char text1[0x1E]; u8 alpha; float width; float height; s32 output; float scale; s32 mode; s32 color2; s32 marker; Dummy *obj; char *name; if ((signed char)lbl_8055F3F4 == 0) { s32 initial = *(s32 *)((u8 *)arg0 + 0x10); float initialFloat = (float)initial; lbl_8055F3F4 = 1; lbl_8055F3F0 = -initialFloat * lbl_80563B8C; } fn_80230C30(&width, &height, *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8)); output = -1; mode = 0; marker = -1; color2 = -1; if (*(u8 *)((u8 *)arg0 + 0x1C) != 0) { output = -1; mode = 1; marker = -1; color2 = -1; } else if (*(u8 *)((u8 *)arg0 + 0x1D) != 0) { output = -1; marker = -1; color2 = -1; } fn_802354A0(*(void **)((u8 *)arg0 + 0x20), mode, color2, width, height, lbl_80563B90, (float)*(s32 *)((u8 *)arg0 + 0xC), (float)*(s32 *)((u8 *)arg0 + 0x10)); if (*(u8 *)((u8 *)arg0 + 0x1C) != 0 && lbl_8055F3EA == 0) { fn_80230F78(&alpha, &scale, (u32 *)&output, 0); { s32 xValue = *(s32 *)((u8 *)arg0 + 0xC); s32 yValue = *(s32 *)((u8 *)arg0 + 0x10); float xFloat = (float)xValue; float yFloat = (float)yValue; float xUnit = lbl_80563B8C * xFloat; float yUnit = lbl_80563B8C * yFloat; float xScaled = scale * xUnit; float yScaled = scale * yUnit; float ratio = lbl_80563B88 + scale; float right = ratio * xFloat; float bottom = ratio * yFloat; u32 packedColor = ((u32)color2 & 0xFF00) | ((u32)alpha << 24) | ((u32)color2 & 0xFFFF); fn_802354A0(*(void **)((u8 *)arg0 + 0x20), mode, packedColor, width - xScaled, height + yScaled, lbl_80563B90, right, bottom); } } obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); fn_80232BA4(obj->m1(), *(s32 *)((u8 *)arg0 + 0x24), output, 0x11, lbl_80563B94 + width, height + lbl_8055F3F0, lbl_80563B98, lbl_80563B90, lbl_80563B88); obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); if (obj->m9() != -1) { obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); obj->m9(); name = (char *)__AXGetStackHead(); } else { name = &lbl_8055C428; } fn_80232BA4(name, *(s32 *)((u8 *)arg0 + 0x24), marker, 0x14, lbl_80563B9C + width, height + lbl_8055F3F0, lbl_80563B98, lbl_80563B90, lbl_80563B88); obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); fn_801308F4(text1, 0x1E, obj->m13()); obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); if (obj->m8() <= 0) { fn_801345D8(text2, 0x1E, &lbl_8055C42C, &text1[1]); } else { obj = (Dummy *)*(void **)((u8 *)arg0 + 0x18); fn_801308F4(text2, 0x1E, obj->m8()); fn_801345D8(text2, 0x1E, &lbl_8055C434, text2, &text1[1]); } fn_80232BA4(text2, *(s32 *)((u8 *)arg0 + 0x24), output, 0x12, lbl_80563BA0 + width, height + lbl_8055F3F0, lbl_80563B98, lbl_80563B90, lbl_80563B88); }
#pragma cplusplus reset
/* No-op handler stub, paired with fn_80262578 and the zero-returning
 * fn_8026257C; this build supplies no behaviour for it. */
void fn_80262574(void) {
}

/* No-op handler stub, paired with fn_80262574 and the zero-returning
 * fn_8026257C; this build supplies no behaviour for it. */
void fn_80262578(void) {
}

/* Default value-returning callback stub (alongside the no-op handlers fn_80262574/fn_80262578): reports a zero result. */
s32 fn_8026257C(void) {
    return 0;
}

/* Clear the object's pending flag at +0x1F and reset timing state when a global flag is set. */
void fn_80262584(void *obj) {
    if (*(u8 *)((u8 *)obj + 0x1F) && lbl_8055F3E9) {
        fn_80230E90(0);
        *(u8 *)((u8 *)obj + 0x1F) = 0;
    }
}

#pragma use_lmw_stmw on
void fn_802625D4(void *arg0, s32 arg_sp0) {
    float sp10;
    float spC;
    s32 sp8;
    s32 color2;
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float temp_f0_4;
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f1_4;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f2_4;
    float temp_f2_5;
    float temp_f2_6;
    float var_f28;
    float var_f29;
    float var_f30;
    float var_f31;
    float var_f3;
    float var_f3_2;
    float var_f3_3;
    float var_f5;
    float var_f5_2;
    float var_f6;
    float var_f6_2;
    float var_f6_3;
    float var_f6_4;
    float var_f7;
    float var_f7_2;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 var_r31;
    void **temp_r3;

    fn_80230C30(&sp10, &spC, *(s32 *)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8));
    sp8 = -1;
    color2 = -1;
    var_r31 = *(s32 *)(lbl_80345B40 + (*(s32 *)((u8 *)arg0 + 0x20) * 4)) + 1;
    if (*(u8 *)((u8 *)arg0 + 0x1C) != 0) {
        sp8 = -1;
        color2 = -1;
        var_r31 = *(s32 *)(lbl_80345B40 + (*(s32 *)((u8 *)arg0 + 0x20) * 4));
    } else if (*(u8 *)((u8 *)arg0 + 0x1D) != 0) {
        color2 = -1;
    }
    if ((signed char)lbl_8055F3FC == 0) {
        lbl_8055F3FC = 1;
        lbl_8055F3F8 = lbl_8055C410 + lbl_8055C414;
    }
    if ((signed char)lbl_8055F404 == 0) {
        lbl_8055F404 = 1;
        lbl_8055F400 = lbl_8055C408 * (float)*(s32 *)((u8 *)arg0 + 0xC);
    }
    if ((signed char)lbl_8055F40C == 0) {
        lbl_8055F40C = 1;
        lbl_8055F408 = lbl_8055C408 * (float)*(s32 *)((u8 *)arg0 + 0x10);
    }
    if ((signed char)lbl_8055F414 == 0) {
        lbl_8055F414 = 1;
        lbl_8055F410 = lbl_8055C40C * (float)*(s32 *)((u8 *)arg0 + 0xC);
    }
    if ((signed char)lbl_8055F41C == 0) {
        lbl_8055F41C = 1;
        lbl_8055F418 = lbl_8055C40C * (float)*(s32 *)((u8 *)arg0 + 0x10);
    }
    if (*(u8 *)((u8 *)arg0 + 0x1E) != 0 && lbl_8055F3E9 != 0) {
        fn_80214AF0(*(s32 *)((u8 *)arg0 + 0x20) + 0xA);
    } else {
        fn_80214A9C(*(s32 *)((u8 *)arg0 + 0x20) + 0xA);
    }
    if (*(u8 *)((u8 *)arg0 + 0x1C) != 0) {
        var_f31 = sp10 - (lbl_8055F410 * lbl_80563B8C);
        var_f30 = spC + (lbl_8055F418 * lbl_80563B8C);
        var_f29 = lbl_8055F410 + (float)*(s32 *)((u8 *)arg0 + 0xC);
        var_f28 = lbl_8055F418 + (float)*(s32 *)((u8 *)arg0 + 0x10);
        if (*(u8 *)((u8 *)arg0 + 0x1E) == 0) {
            temp_f1 = fn_8023659C();
            var_f3 = lbl_8055C404;
            if ((temp_f1 - var_f3) > lbl_8055F3F8) {
                var_f3 = temp_f1;
                lbl_8055C404 = temp_f1;
            }
            temp_f1_2 = temp_f1 - var_f3;
            if (temp_f1_2 < lbl_8055C410) {
                var_f3_2 = lbl_80563B88;
                temp_f0 = (temp_f1_2 - lbl_80563B90) / (lbl_8055C410 - lbl_80563B90);
                if (var_f3_2 < temp_f0) {
                } else {
                    var_f3_2 = temp_f0;
                }
                if (var_f3_2 > lbl_80563B90) {
                } else {
                    var_f3_2 = lbl_80563B90;
                }
                var_f5 = lbl_80563BB0;
                temp_f0_2 = lbl_80563B90 + (var_f3_2 * lbl_80563B88);
                if (temp_f0_2 < var_f5) {
                } else if (temp_f0_2 > lbl_80563B88) {
                    var_f5 = lbl_80563B88;
                } else if (temp_f0_2 > lbl_80563B90) {
                    var_f5 = (temp_f0_2 * (lbl_80563BB4 * temp_f0_2 * temp_f0_2)) + (lbl_80563BB8 * temp_f0_2 * temp_f0_2);
                } else {
                    var_f5 = (temp_f0_2 * (lbl_80563BB4 * temp_f0_2 * temp_f0_2)) - (lbl_80563BB8 * temp_f0_2 * temp_f0_2);
                }
                var_f6 = lbl_80563BB0;
                temp_f2 = sp10 - (lbl_8055F400 * lbl_80563B8C);
                var_f31 = temp_f2 + (var_f5 * ((sp10 - (lbl_8055F410 * lbl_80563B8C)) - temp_f2));
                if (temp_f0_2 < var_f6) {
                } else {
                    var_f6 = lbl_80563B88;
                    if (temp_f0_2 > var_f6) {
                    } else if (temp_f0_2 > lbl_80563B90) {
                        var_f6 = (temp_f0_2 * (lbl_80563BB4 * temp_f0_2 * temp_f0_2)) + (lbl_80563BB8 * temp_f0_2 * temp_f0_2);
                    } else {
                        var_f6 = (temp_f0_2 * (lbl_80563BB4 * temp_f0_2 * temp_f0_2)) - (lbl_80563BB8 * temp_f0_2 * temp_f0_2);
                    }
                }
                var_f7 = lbl_80563BB0;
                temp_f2_2 = spC + (lbl_8055F408 * lbl_80563B8C);
                var_f30 = temp_f2_2 + (var_f6 * ((spC + (lbl_8055F418 * lbl_80563B8C)) - temp_f2_2));
                if (temp_f0_2 < var_f7) {
                } else {
                    var_f7 = lbl_80563B88;
                    if (temp_f0_2 > var_f7) {
                    } else if (temp_f0_2 > lbl_80563B90) {
                        var_f7 = (temp_f0_2 * (lbl_80563BB4 * temp_f0_2 * temp_f0_2)) + (lbl_80563BB8 * temp_f0_2 * temp_f0_2);
                    } else {
                        var_f7 = (temp_f0_2 * (lbl_80563BB4 * temp_f0_2 * temp_f0_2)) - (lbl_80563BB8 * temp_f0_2 * temp_f0_2);
                    }
                }
                temp_r0 = *(s32 *)((u8 *)arg0 + 0xC);
                var_f6_2 = lbl_80563BB0;
                temp_f2_3 = lbl_8055F400 + (float)temp_r0;
                var_f29 = temp_f2_3 + (var_f7 * ((lbl_8055F410 + (float)temp_r0) - temp_f2_3));
                if (temp_f0_2 < var_f6_2) {
                } else {
                    var_f6_2 = lbl_80563B88;
                    if (temp_f0_2 > var_f6_2) {
                    } else if (temp_f0_2 > lbl_80563B90) {
                        var_f6_2 = (temp_f0_2 * (lbl_80563BB4 * temp_f0_2 * temp_f0_2)) + (lbl_80563BB8 * temp_f0_2 * temp_f0_2);
                    } else {
                        var_f6_2 = (temp_f0_2 * (lbl_80563BB4 * temp_f0_2 * temp_f0_2)) - (lbl_80563BB8 * temp_f0_2 * temp_f0_2);
                    }
                }
                temp_r0_2 = *(s32 *)((u8 *)arg0 + 0x10);
                temp_f1_3 = lbl_8055F408 + (float)temp_r0_2;
                var_f28 = temp_f1_3 + (var_f6_2 * ((lbl_8055F418 + (float)temp_r0_2) - temp_f1_3));
            } else {
                var_f3_3 = lbl_80563B88;
                temp_f0_3 = (temp_f1_2 - lbl_8055C410) / ((lbl_8055C410 + lbl_8055C414) - lbl_8055C410);
                if (var_f3_3 < temp_f0_3) {
                } else {
                    var_f3_3 = temp_f0_3;
                }
                if (var_f3_3 > lbl_80563B90) {
                } else {
                    var_f3_3 = lbl_80563B90;
                }
                var_f5_2 = lbl_80563BB0;
                temp_f0_4 = lbl_80563B90 + (var_f3_3 * lbl_80563B88);
                if (temp_f0_4 < var_f5_2) {
                } else if (temp_f0_4 > lbl_80563B88) {
                    var_f5_2 = lbl_80563B88;
                } else if (temp_f0_4 > lbl_80563B90) {
                    var_f5_2 = (temp_f0_4 * (lbl_80563BB4 * temp_f0_4 * temp_f0_4)) + (lbl_80563BB8 * temp_f0_4 * temp_f0_4);
                } else {
                    var_f5_2 = (temp_f0_4 * (lbl_80563BB4 * temp_f0_4 * temp_f0_4)) - (lbl_80563BB8 * temp_f0_4 * temp_f0_4);
                }
                var_f6_3 = lbl_80563BB0;
                temp_f2_4 = sp10 - (lbl_8055F410 * lbl_80563B8C);
                var_f31 = temp_f2_4 + (var_f5_2 * ((sp10 - (lbl_8055F400 * lbl_80563B8C)) - temp_f2_4));
                if (temp_f0_4 < var_f6_3) {
                } else {
                    var_f6_3 = lbl_80563B88;
                    if (temp_f0_4 > var_f6_3) {
                    } else if (temp_f0_4 > lbl_80563B90) {
                        var_f6_3 = (temp_f0_4 * (lbl_80563BB4 * temp_f0_4 * temp_f0_4)) + (lbl_80563BB8 * temp_f0_4 * temp_f0_4);
                    } else {
                        var_f6_3 = (temp_f0_4 * (lbl_80563BB4 * temp_f0_4 * temp_f0_4)) - (lbl_80563BB8 * temp_f0_4 * temp_f0_4);
                    }
                }
                var_f7_2 = lbl_80563BB0;
                temp_f2_5 = spC + (lbl_8055F418 * lbl_80563B8C);
                var_f30 = temp_f2_5 + (var_f6_3 * ((spC + (lbl_8055F408 * lbl_80563B8C)) - temp_f2_5));
                if (temp_f0_4 < var_f7_2) {
                } else {
                    var_f7_2 = lbl_80563B88;
                    if (temp_f0_4 > var_f7_2) {
                    } else if (temp_f0_4 > lbl_80563B90) {
                        var_f7_2 = (temp_f0_4 * (lbl_80563BB4 * temp_f0_4 * temp_f0_4)) + (lbl_80563BB8 * temp_f0_4 * temp_f0_4);
                    } else {
                        var_f7_2 = (temp_f0_4 * (lbl_80563BB4 * temp_f0_4 * temp_f0_4)) - (lbl_80563BB8 * temp_f0_4 * temp_f0_4);
                    }
                }
                temp_r0_3 = *(s32 *)((u8 *)arg0 + 0xC);
                var_f6_4 = lbl_80563BB0;
                temp_f2_6 = lbl_8055F410 + (float)temp_r0_3;
                var_f29 = temp_f2_6 + (var_f7_2 * ((lbl_8055F400 + (float)temp_r0_3) - temp_f2_6));
                if (temp_f0_4 < var_f6_4) {
                } else {
                    var_f6_4 = lbl_80563B88;
                    if (temp_f0_4 > var_f6_4) {
                    } else if (temp_f0_4 > lbl_80563B90) {
                        var_f6_4 = (temp_f0_4 * (lbl_80563BB4 * temp_f0_4 * temp_f0_4)) + (lbl_80563BB8 * temp_f0_4 * temp_f0_4);
                    } else {
                        var_f6_4 = (temp_f0_4 * (lbl_80563BB4 * temp_f0_4 * temp_f0_4)) - (lbl_80563BB8 * temp_f0_4 * temp_f0_4);
                    }
                }
                temp_r0_4 = *(s32 *)((u8 *)arg0 + 0x10);
                temp_f1_4 = lbl_8055F418 + (float)temp_r0_4;
                var_f28 = temp_f1_4 + (var_f6_4 * ((lbl_8055F408 + (float)temp_r0_4) - temp_f1_4));
            }
            fn_80230F6C(&sp8);
        } else {
            sp8 = -0x35BC;
        }
        fn_802354A0(*(void **)((u8 *)arg0 + 0x20), 0x12, color2, var_f31, var_f30, lbl_80563B90, var_f29, var_f28);
    }
    fn_802354A0(*(void **)((u8 *)arg0 + 0x20), var_r31, color2, sp10, spC, lbl_80563B90, (float)*(s32 *)((u8 *)arg0 + 0xC), (float)*(s32 *)((u8 *)arg0 + 0x10));
    temp_r3 = *(void **)((u8 *)arg0 + 0x18);
    {
        char *name = (*(char *(*)(void **))((u8 *)*temp_r3 + 0xC))(temp_r3);
        fn_80232BA4(name, *(s32 *)((u8 *)arg0 + 0x28), sp8, 0x11, lbl_80563BBC + sp10, lbl_80563BC0 + spC, lbl_80563BC4, lbl_80563B90, lbl_80563B88);
    }
}

