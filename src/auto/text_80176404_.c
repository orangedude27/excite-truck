// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned int u32;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} UnkStruct_80430378;
extern void fn_8000D838(void *);
extern UnkStruct_80430378 lbl_80430378;
extern u32 lbl_8055E390;
extern volatile s32 lbl_8055E398;
extern volatile s32 lbl_8055E39C;
extern volatile s32 lbl_8055E3A0;

#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_80176404(void) {
    s32 v;
    s32 *p;
    s32 *arr = (s32 *)&lbl_80430378.unk0;
    fn_8000D838(&lbl_8055E390);
    p = arr + 1;
    arr[0] = 0;
    v = 0x7B;
    arr[1] = v;
    arr[2] = 0;
    arr[3] = 0;
    arr[4] = 0;
    lbl_8055E398 = 0xFFFF0000;
    lbl_8055E39C = 0xFFFF0000;
    lbl_8055E3A0 = 0x7F000000;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
