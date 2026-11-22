// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct Obj80262EF8 {
    void *vtable;
    unsigned char unk_04[0x10];
    unsigned int unk_14;
    float unk_18;
} Obj80262EF8;

extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *, void *, int, void *);
extern void fn_80262F8C(void);
extern unsigned int lbl_80498F00[];
extern unsigned char lbl_8033D618[];
extern unsigned char lbl_80345F70[];
extern int lbl_8055F3D8;
extern int lbl_8055F3E0;
extern float lbl_80563B90;
void fn_80262EF8(void) {
    typedef struct {
        volatile unsigned int words[8];
        Obj80262EF8 obj;
    } Region;
    Region *r = (Region *)lbl_80498F00;
    fn_8000D838(&lbl_8055F3D8);
    r->words[8] = (unsigned int)lbl_8033D618;
    r->obj.unk_18 = lbl_80563B90;
    r->words[0] = 0;
    r->words[1] = 0x7B;
    r->words[2] = 0;
    r->words[3] = 0;
    r->words[4] = 0;
    lbl_8055F3E0 = 0x7F000000;
    r->obj.unk_14 = 0;
    r->words[8] = (unsigned int)lbl_80345F70;
    __register_global_object((void *)&r->obj, fn_80262F8C, (void *)&r->words[5], lbl_80345F70, 0, (void *)&r->words[0]);
}
