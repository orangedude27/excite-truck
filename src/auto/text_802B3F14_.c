// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct { void *vtable; int unk4; int unk8; } GlobalObject;
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_802B3F6C(void);
#pragma push
#pragma small_data off
extern unsigned char lbl_804BE1F0;
#pragma pop
extern int lbl_804BE1FC[];
extern unsigned char lbl_8055F9A8;

void fn_802B3F14(void) {
    struct Obj { void *vtable; int unk4; int unk8; };
    struct Obj *obj;
    fn_8000D838(&lbl_8055F9A8);
    obj = (struct Obj *)&lbl_804BE1FC;
    obj->vtable = (void *)((char *)obj + 0xC);
    obj->unk8 = 0x10;
    obj->unk4 = 0;
    __register_global_object(obj, fn_802B3F6C, &lbl_804BE1F0);
}
