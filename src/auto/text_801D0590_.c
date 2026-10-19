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
void fn_801D0650(void *arg0) {
    int offset = 0;
    int i = 0;
    while (i < lbl_804386B4[0].count) {
        void *obj = *(void **)((char *)lbl_804386B4[0].items + offset);
        ((void (*)(void *, void *))(*(void ***)obj)[2])(obj, arg0);
        offset += 4;
        i++;
    }
}
#pragma push
#pragma use_lmw_stmw off
void fn_801D06C4(void *arg0) {
    int offset = 0;
    int i = 0;
    while (i < lbl_804386B4[0].count) {
        void *obj = *(void **)((char *)lbl_804386B4[0].items + offset);
        ((void (*)(void *, void *))(*(void ***)obj)[3])(obj, arg0);
        offset += 4;
        i++;
    }
}
#pragma pop
void fn_801D0738(void *arg0, void *arg1, void *arg2, void *arg3) {
    int type = *(int *)((char *)arg2 + 0x10);
    int ok = 0;
    if (type == 0x43415220 || type == 0x50434152 ||
        type == 0x41434152 || type == 0x4e434152) {
        ok = 1;
    }
    if (ok != 0) {
        int count = *(int *)((char *)arg2 + 0x1ec);
        int i = 0;
        int offset = 0;
        DispatchList *list = lbl_804386B4;
        while (i < list->count) {
            void *obj = *(void **)((char *)list->items + offset);
            ((void (*)(void *, void *, int, void *))(*(void ***)obj)[4])(obj, arg0, count, arg3);
            offset += 4;
            i++;
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
void fn_801D09A8(void *arg0, void *arg1) { int offset = 0; int i = 0; while (i < lbl_8043870C[0].count) { void *obj = *(void **)((char *)lbl_8043870C[0].items + offset); ((void (*)(void *, void *, void *))(*(void ***)obj)[4])(obj, arg0, arg1); offset += 4; i++; } }
#pragma pop
void fn_801D0A24(void *arg0,void *arg1) { int i=0, offset=0; while(i < lbl_8043870C[0].count) { void *obj=*(void **)((char *)lbl_8043870C[0].items+offset); ((void (*)(void *,void *,void *))(*(void ***)obj)[5])(obj,arg0,arg1); offset+=4; i++; } }
#pragma pop
