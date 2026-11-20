// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma scheduling invalid_target
extern char lbl_8049A258[];
extern float lbl_8055F538;
extern float lbl_8055F540, lbl_8055F544, lbl_8055F560;
extern float lbl_80563FA0, lbl_80563FA4, lbl_80563F9C;
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, int, int);
extern void __register_global_object(int, void *, void *);
extern void fn_80273B48(void);
extern void fn_80273B08(void);
extern void fn_80273AEC(void);
extern void fn_80273ABC(void);
extern void fn_80273AA4(void);
extern void fn_80273978(void);
extern void fn_80273A88(void);
#pragma opt_propagation off
#pragma processor 750
void fn_802739B8(void) {
    char *base = lbl_8049A258;
    fn_8000D838(&lbl_8055F538);
    lbl_8055F540 = lbl_80563FA0;
    lbl_8055F544 = lbl_80563FA4;
    fn_8002F53C(base + 0x70, fn_80273B48, fn_80273B08, 0x60, 0xC8);
    __register_global_object(0, fn_80273AEC, base + 0x64);
    fn_8002F53C(base + 0x4B70, fn_80273ABC, 0, 0x60, 0x20);
    fn_8002F53C(base + 0x5780, fn_80273AA4, fn_80273978, 0x1C, 0x20);
    __register_global_object(0, fn_80273A88, base + 0x5770);
#pragma opt_propagation reset
    lbl_8055F560 = lbl_80563F9C;
#pragma opt_propagation off
}
