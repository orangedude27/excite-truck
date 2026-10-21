// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned int u32;
typedef struct {
    volatile s32 unk0;
    volatile s32 unk4;
    volatile s32 unk8;
    volatile s32 unkC;
    volatile s32 unk10;
} UnkStruct_80430378;
extern void fn_8000D838(void *);
extern UnkStruct_80430378 lbl_80430378;
extern u32 lbl_8055E390;
extern volatile s32 lbl_8055E398;
extern volatile s32 lbl_8055E39C;
extern volatile s32 lbl_8055E3A0;

void fn_80176404(void) {
    fn_8000D838(&lbl_8055E390);
    lbl_80430378.unk0 = 0;
    lbl_80430378.unk8 = 0;
    lbl_80430378.unk4 = 0x7B;
    lbl_80430378.unkC = 0;
    lbl_80430378.unk10 = 0;
    lbl_8055E398 = 0xFFFF0000;
    lbl_8055E39C = 0xFFFF0000;
    lbl_8055E3A0 = 0x7F000000;
}
