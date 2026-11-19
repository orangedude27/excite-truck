// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, unsigned int, unsigned int);
extern void __register_global_object(void *, void *, void *);
extern unsigned char lbl_804B5070[];
extern void fn_802A08E8(void);
extern void fn_802A0940(void);
__declspec(section ".sdata") extern int lbl_8055F810;
struct S_802A086C { char pad[0x4B0C]; unsigned int f0, f1, f2; };
#pragma scheduling invalid_target
void fn_802A086C(void) {
#pragma scheduling invalid_target
    unsigned int *p;
    fn_8000D838(&lbl_8055F810);
    fn_8002F53C(lbl_804B5070, &fn_802A0940, 0, 0x78, 0x40);
    p = (unsigned int *)(lbl_804B5070 + 0x4B0C);
    *p = (unsigned int)(lbl_804B5070 + 0x4B18);
    p[2] = 0x100;
    p[1] = 0;
    __register_global_object(p, &fn_802A08E8, lbl_804B5070 + 0x4B00);
}
#pragma scheduling on
