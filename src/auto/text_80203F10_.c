// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct GlobalObject {
    void *unk0;
    int unk4;
    int unk8;
} GlobalObject;
extern void fn_8000D838(void *);
extern void fn_80203F88(void);
  extern int lbl_80488970[];
    extern int lbl_8048897C[];
  extern int lbl_8055ECE8;
extern short lbl_8055ECF0;
extern short lbl_8055ECF2;
extern short lbl_8055ECF4;
extern int lbl_8055ECF8;
  extern void __register_global_object(void *, void *, void *, int, int);

#pragma push
#pragma scheduling invalid_target
void fn_80203F10(void) {
    int a;
    int b;
    fn_8000D838(&lbl_8055ECE8);
    lbl_8055ECF0 = 0x100;
    lbl_8055ECF2 = 0x405;
    lbl_8055ECF4 = 0x401;
    b = 0xFFFF0000;
    lbl_8055ECF8 = b;
    *(void **)&lbl_8048897C = (char *)&lbl_8048897C + 12;
    a = 0x40;
    lbl_8048897C[2] = a;
    lbl_8048897C[1] = 0;
    __register_global_object(&lbl_8048897C, &fn_80203F88, &lbl_80488970, a, b);
}
#pragma pop
