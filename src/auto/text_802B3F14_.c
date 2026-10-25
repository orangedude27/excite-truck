// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct { void *vtable; int unk4; int unk8; } GlobalObject;
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_802B3F6C(void);
#pragma push
#pragma small_data off
extern int lbl_804BE1F0[];
#pragma pop
extern int lbl_804BE1FC[];
extern unsigned char lbl_8055F9A8;

# pragma scheduling invalid_target
# pragma opt_propagation off
# pragma opt_dead_assignments off
void fn_802B3F14(void) {
    fn_8000D838(&lbl_8055F9A8);
    lbl_804BE1FC[0] = (int)((char *)lbl_804BE1FC + 12);
    lbl_804BE1FC[2] = 0x10;
    lbl_804BE1FC[1] = 0;
    __register_global_object((void *)lbl_804BE1FC, (void *)fn_802B3F6C, (void *)&lbl_804BE1F0[0]);
}
# pragma opt_dead_assignments reset
# pragma opt_propagation reset
# pragma scheduling reset
