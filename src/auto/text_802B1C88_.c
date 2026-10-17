// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma small_data off
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern int lbl_8055F990;
extern int lbl_804BE104;
extern int lbl_804BE0F8;
extern void fn_802B1CE0(void);
#pragma small_data off
void fn_802B1C88(void) {
    struct Obj { void *p; int a; int size; };
    struct Obj *obj;
    fn_8000D838(&lbl_8055F990);
    obj = (struct Obj *)&lbl_804BE104;
    obj->p = (char *)obj + 12;
    obj->size = 0x20;
    obj->a = 0;
    __register_global_object(obj, (void *)fn_802B1CE0, (void *)&lbl_804BE0F8);
}
#pragma small_data on
