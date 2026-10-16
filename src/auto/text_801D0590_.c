// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { void **items; int count; } DispatchList;
#pragma push
#pragma small_data off
extern DispatchList lbl_804386B4;
extern DispatchList lbl_8043870C;
#pragma pop
void fn_801D0650(void *arg0) { int i, offset, count; void **items; void *obj; i=0; offset=0; items=*(void ***)&lbl_804386B4; count=*(int *)((char *)&lbl_804386B4+4); while(i<count){obj=*(void **)((char *)items+offset); ((void (*)(void *,void *))(*(void ***)obj)[2])(obj,arg0); offset+=4; i++;}}

void fn_801D06C4(void *arg0) { int i, offset, count; void **items; void *obj; i=0; offset=0; items=*(void ***)&lbl_804386B4; count=*(int *)((char *)&lbl_804386B4+4); while(i<count){obj=*(void **)((char *)items+offset); ((void (*)(void *,void *))(*(void ***)obj)[3])(obj,arg0); offset+=4; i++;}}

void fn_801D09A8(void *arg0,void *arg1) { int i, offset, count; void **items; void *obj; i=0; offset=0; items=*(void ***)&lbl_8043870C; count=*(int *)((char *)&lbl_8043870C+4); while(i<count){obj=*(void **)((char *)items+offset); ((void (*)(void *,void *,void *))(*(void ***)obj)[4])(obj,arg0,arg1); offset+=4; i++;}}

void fn_801D0A24(void *arg0,void *arg1) { int i, offset, count; void **items; void *obj; i=0; offset=0; items=*(void ***)&lbl_8043870C; count=*(int *)((char *)&lbl_8043870C+4); while(i<count){obj=*(void **)((char *)items+offset); ((void (*)(void *,void *,void *))(*(void ***)obj)[5])(obj,arg0,arg1); offset+=4; i++;}}

