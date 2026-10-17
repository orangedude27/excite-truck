// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { void **items; int count; } DispatchList;
#pragma push
#pragma small_data off
extern DispatchList lbl_804386B4[];
extern DispatchList lbl_8043870C[];
#pragma push
#pragma small_data off
void fn_801D0650(void *arg0) {
    DispatchList *list = &lbl_804386B4[0];
    int i = 0;
    int offset = 0;
    while (i < list->count) {
        void *obj = *(void **)((char *)list->items + offset);
        ((void (*)(void *, void *))(*(void ***)obj)[2])(obj, arg0);
        offset += 4;
        i++;
    }
}
void fn_801D06C4(void *arg0) {
    DispatchList *list = &lbl_804386B4[0];
    int i = 0;
    int offset = 0;
    while (i < list->count) {
        void *obj = *(void **)((char *)list->items + offset);
        ((void (*)(void *, void *))(*(void ***)obj)[3])(obj, arg0);
        offset += 4;
        i++;
    }
}

void fn_801D09A8(void *arg0,void *arg1) { int i=0, offset=0; while(i < lbl_8043870C[0].count) { void *obj=*(void **)((char *)lbl_8043870C[0].items+offset); ((void (*)(void *,void *,void *))(*(void ***)obj)[4])(obj,arg0,arg1); offset+=4; i++; } }

void fn_801D0A24(void *arg0,void *arg1) { int i=0, offset=0; while(i < lbl_8043870C[0].count) { void *obj=*(void **)((char *)lbl_8043870C[0].items+offset); ((void (*)(void *,void *,void *))(*(void ***)obj)[5])(obj,arg0,arg1); offset+=4; i++; } }
#pragma pop
