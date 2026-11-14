#include <types.h>
#include <revolution/MTX/mtxtypes.h> /* Vec */
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* The game's two listener lists.  An object hands one of its sub-objects to
   fn_801D0590 (lbl_804386B4) or fn_801D0800 (lbl_8043870C) to be called later,
   and takes it back out with fn_801D05B4 / fn_801D0824 when it goes away; the
   rest of this file is the loops that walk one list and call one of every
   entry's virtual functions.  The order of the entries means nothing: removing
   an entry just moves the last one into its slot. */
typedef struct { void **items; int count; } DispatchList;

/* Scene object tags (object+0x10) of the vehicles that carry soevents -- the
   same four fn_801D2414 accepts. */
#define FOURCC_CAR  0x43415220 /* 'CAR ' */
#define FOURCC_PCAR 0x50434152 /* 'PCAR' player truck */
#define FOURCC_ACAR 0x41434152 /* 'ACAR' AI truck */
#define FOURCC_NCAR 0x4E434152 /* 'NCAR' */

/* What these walkers read of a scene object: its tag and the slot it holds in
   the per-object table.  text_801D21C0_.c describes the object as a whole. */
typedef struct VehicleObject {
    /* 0x00 */ void *vt;
    /* 0x04 */ u8 pad04[0x0C];
    /* 0x10 */ u32 fourcc;       /* FOURCC_* above */
    /* 0x14 */ u8 pad14[0x1D8];
    /* 0x1EC */ s32 recordIndex;
} VehicleObject;
#pragma push
#pragma small_data off
extern DispatchList lbl_804386B4[];
extern DispatchList lbl_8043870C[];
#pragma push
#pragma small_data off
__declspec(section ".data") extern DispatchList lbl_804386B4[];
#pragma scheduling invalid_target
void fn_801D0590(void* arg0) {
    DispatchList* list = lbl_804386B4;
    void** items = list->items;
    int count = list->count++;
    items[count] = arg0;
}

static inline int DispatchList_Find1(void *obj) {
    DispatchList *l = lbl_804386B4;
    void **p = l->items;
    int i = 0;
    for (; i < l->count; i++) {
        if (*p == obj) return i;
        p++;
    }
    return -1;
}

static inline void DispatchList_RemoveAt1(int index) {
    int last;
    int c;
    DispatchList *l;
    if (index < 0) return;
    l = lbl_804386B4;
    c = ((volatile DispatchList *)l)->count;
    if (index >= c) return;
    last = c - 1;
    if (index != last) {
        void **items = lbl_804386B4[0].items;
        items[index] = items[last];
    }
    lbl_804386B4[0].count = lbl_804386B4[0].count - 1;
}

/* Take an object out of the first listener list, the counterpart of fn_801D0590:
 * find it, then let the list's last entry move into the slot it frees.  An
 * object that is not in the list is left alone. */
void fn_801D05B4(void *obj) {
    int index = DispatchList_Find1(obj);
    if (index == -1) return;
    DispatchList_RemoveAt1(index);
}
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_801D0650(void *arg0) {
    struct Dummy {
        virtual void f0(void *);
    };
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_804386B4[0].count) {
        void *obj = *(void **)((char *)lbl_804386B4[0].items + offset);
        ((Dummy *)obj)->f0(arg0);
        offset += 4;
        i++;
    }
}
#pragma cplusplus reset
#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_801D06C4(void *arg0) {
    struct Dummy {
        virtual void f0();
        virtual void f1(void *);
    };
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_804386B4[0].count) {
        void *obj = *(void **)((char *)lbl_804386B4[0].items + offset);
        ((Dummy *)obj)->f1(arg0);
        offset += 4;
        i++;
    }
}
#pragma pop
#pragma cplusplus reset
#pragma cplusplus on
/* Notify every listener in the first listener list (lbl_804386B4) that a
 * truck's soevent is running: for each entry's dispatch sub-object, call the
 * virtual at slot 2 with the soevent instance, the truck's slot in the
 * per-object table and the caller's extra argument.  Only the four vehicle
 * tags that carry soevents get through; fn_801A4A10 calls this right after
 * fn_801D2414 has run the event's class record, and only when the instance
 * has a second handler (+0x48).  The truck's position is not passed on. */
extern "C" void fn_801D0738(void *instance, Vec *position, VehicleObject *object,
                            void *extra) {
    struct Listener {
        virtual void f0();
        virtual void f1();
        virtual void onSoevent(void *, int, void *);
    };
    u32 fourcc = object->fourcc;
    int isCar = 0;
    if (fourcc == FOURCC_CAR || fourcc == FOURCC_PCAR ||
        fourcc == FOURCC_ACAR || fourcc == FOURCC_NCAR) {
        isCar = 1;
    }
    if (isCar != 0) {
        int offset;
        int recordIndex;
        int i;
        recordIndex = object->recordIndex;
        i = 0;
        offset = 0;
        while (i < lbl_804386B4[0].count) {
            void *obj = *(void **)((char *)lbl_804386B4[0].items + offset);
            ((Listener *)obj)->onSoevent(instance, recordIndex, extra);
            offset += 4;
            i++;
        }
    }
}
#pragma cplusplus reset
static inline int DispatchList_Find2(void *obj) {
    DispatchList *l = lbl_8043870C;
    void **p = l->items;
    int n = *(volatile int *)&l->count;
    int i = 0;
    for (; i < n; i++) {
        if (*p == obj) return i;
        p++;
    }
    return -1;
}

static inline void DispatchList_RemoveAt2(int index) {
    DispatchList *l;
    int last;
    if (index < 0) return;
    l = lbl_8043870C;
    if (index >= l->count) return;
    last = l->count - 1;
    if (index != last) {
        void **items = lbl_8043870C[0].items;
        items[index] = items[last];
    }
    lbl_8043870C[0].count = lbl_8043870C[0].count - 1;
}

#pragma scheduling invalid_target
void fn_801D0800(s32 arg0) {
    DispatchList* list = lbl_8043870C;
    s32* items = (s32*)list->items;
    int count = list->count++;
    items[count] = arg0;
}

/* Take one listener out of the second listener list (lbl_8043870C), the
 * counterpart of fn_801D0800, which appends to it.  Objects register the
 * dispatch sub-object inside them (their +4, +0xC, +0x23C, ...) here so the
 * walkers further down this file can call one of its virtual functions for
 * every listener, and unregister it as they are destroyed: find it, then let
 * the list's last entry move into the slot it frees.  A sub-object that is
 * not in the list is left alone. */
void fn_801D0824(void *listener) {
    int index = DispatchList_Find2(listener);
    if (index == -1) return;
    DispatchList_RemoveAt2(index);
}

#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
/* Notify every listener in the second listener list (lbl_8043870C): call the first
   virtual function of each entry's dispatch sub-object, with the notifier's own
   sub-object as its argument.  fn_801D0934, fn_801D09A8 and fn_801D0A24 walk the
   same list for the three virtual functions after this one. */
extern "C" void fn_801D08C0(void *notifier) {
    struct Listener {
        virtual void notify(void *);
    };
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_8043870C[0].count) {
        void *obj = *(void **)((char *)lbl_8043870C[0].items + offset);
        ((Listener *)obj)->notify(notifier);
        offset += 4;
        i++;
    }
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_801D0934(void *arg0) {
    struct Dummy {
        virtual void f0();
        virtual void f1(void *);
    };
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_8043870C[0].count) {
        void *obj = *(void **)((char *)lbl_8043870C[0].items + offset);
        ((Dummy *)obj)->f1(arg0);
        offset += 4;
        i++;
    }
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus on
/* Notify every listener in the second listener list (lbl_8043870C): call virtual
 * slot 2 of each entry's dispatch sub-object with the notifier's own sub-object
 * and the vehicle's slot in the per-object table.  fn_801AD7C4 does this for a
 * truck whose scene-object tag is one of the four soevent vehicles, passing its
 * own +0x23C sub-object and the object's record index (+0x1EC).  This is the
 * third of the four walkers of this list -- fn_801D08C0, fn_801D0934, this one
 * and fn_801D0A24 run virtual slots 0, 1, 2 and 3 of every entry. */
extern "C" void fn_801D09A8(void *notifier, void *eventData) {
    struct Listener {
        virtual void f0();
        virtual void f1();
        virtual void onEvent(void *, void *);
    };
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_8043870C[0].count) {
        void *listener = *(void **)((char *)lbl_8043870C[0].items + offset);
        ((Listener *)listener)->onEvent(notifier, eventData);
        offset += 4;
        i++;
    }
}
#pragma cplusplus on
/* Notify every listener in the second listener list (lbl_8043870C): call virtual slot 3 on each entry's dispatch sub-object with the notifier and event data. */
extern "C" void fn_801D0A24(void *notifier, void *eventData) {
    struct Listener {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void notifyEvent(void *, void *);
    };
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_8043870C[0].count) {
        void *listener = *(void **)((char *)lbl_8043870C[0].items + offset);
        ((Listener *)listener)->notifyEvent(notifier, eventData);
        offset += 4;
        i++;
    }
}
#pragma cplusplus reset
