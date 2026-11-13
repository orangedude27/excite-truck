#include <types.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { void **items; int count; } DispatchList;
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

static inline int DispatchList_Find1(DispatchList *l, void *obj) {
    void **p = l->items;
    int i = 0;
    for (; i < l->count; i++) {
        if (*p == obj) return i;
        p++;
    }
    return -1;
}

static inline void DispatchList_RemoveAt1(DispatchList *l, int index) {
    int last;
    if (index < 0) return;
    if (index >= l->count) return;
    last = l->count - 1;
    if (index != last) {
        void **items = l->items;
        items[index] = items[last];
    }
    l->count = l->count - 1;
}

void fn_801D05B4(void *arg0) {
    int index = DispatchList_Find1(lbl_804386B4, arg0);
    if (index == -1) return;
    DispatchList_RemoveAt1(lbl_804386B4, index);
}

#pragma push
#pragma use_lmw_stmw off
void fn_801D0650(void *arg0) {
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_804386B4[0].count) {
        void *obj = *(void **)((char *)lbl_804386B4[0].items + offset);
        ((void (**)(void *, void *))(*(void ***)obj))[2](obj, arg0);
        offset += 4;
        i++;
    }
}
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
void fn_801D0738(void *arg0, void *arg1, void *arg2, void *arg3) {
    int type = *(int *)((char *)arg2 + 0x10);
    int ok = 0;
    if (type == 0x43415220 || type == 0x50434152 ||
        type == 0x41434152 || type == 0x4e434152) {
        ok = 1;
    }
    if (ok != 0) {
        int offset;
        int count;
        int i;
        count = *(int *)((char *)arg2 + 0x1ec);
        i = 0;
        offset = 0;
        while (i < lbl_804386B4[0].count) {
            void *obj = *(void **)((char *)lbl_804386B4[0].items + offset);
            ((void (*)(void *, void *, int, void *))(*(void ***)obj)[4])(obj, arg0, count, arg3);
            offset += 4;
            i++;
        }
    }
}

static inline int DispatchList_Find2(void *obj) {
    DispatchList *l = lbl_8043870C;
    void **p = l->items;
    int i = 0;
    for (; i < l->count; i++) {
        if (*p == obj) return i;
        p++;
    }
    return -1;
}

static inline void DispatchList_RemoveAt2(int index) {
    int last;
    DispatchList *l = lbl_8043870C;
    if (index < 0) return;
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

void fn_801D0824(void *arg0) {
    int index = DispatchList_Find2(arg0);
    if (index == -1) return;
    DispatchList_RemoveAt2(index);
}

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
extern "C" void fn_801D09A8(void *arg0, void *arg1) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2(void *, void *);
    };
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_8043870C[0].count) {
        void *obj = *(void **)((char *)lbl_8043870C[0].items + offset);
        ((Dummy *)obj)->f2(arg0, arg1);
        offset += 4;
        i++;
    }
}
#pragma cplusplus on
extern "C" void fn_801D0A24(void *arg0, void *arg1) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3(void *, void *);
    };
    int offset;
    int i;
    i = 0;
    offset = 0;
    while (i < lbl_8043870C[0].count) {
        void *obj = *(void **)((char *)lbl_8043870C[0].items + offset);
        ((Dummy *)obj)->f3(arg0, arg1);
        offset += 4;
        i++;
    }
}
#pragma cplusplus reset
