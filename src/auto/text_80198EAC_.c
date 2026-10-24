// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void __dt__Q36PSGame10SoundTable11CategoryMgrFv(void);
extern unsigned char lbl_80434A04[];
extern unsigned char lbl_80434A10[];
extern unsigned char lbl_8055E530;
extern int lbl_8055E538;
extern int lbl_8055E53C;
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *);
extern void __dt__Q36PSGame10SoundTable11CategoryMgrFv(void);
extern unsigned char lbl_80434A04[];
extern unsigned char lbl_80434A10[];
extern unsigned char lbl_8055E530;
extern int lbl_8055E538;
extern int lbl_8055E53C;

#pragma scheduling invalid_target
void fn_80198EAC(void) {
    fn_8000D838(&lbl_8055E530);
    lbl_8055E538 = 0xFFFF0000;
    lbl_8055E53C = 0xFFFF0000;
    *(int *)(lbl_80434A10 + 4) = 0x80;
    *(void **)lbl_80434A10 = lbl_80434A10 + 0x10;
    *(int *)(lbl_80434A10 + 8) = 0;
    *(int *)(lbl_80434A10 + 0xC) = 0;
    __register_global_object(lbl_80434A10, __dt__Q36PSGame10SoundTable11CategoryMgrFv, lbl_80434A04);
}
#pragma scheduling on
