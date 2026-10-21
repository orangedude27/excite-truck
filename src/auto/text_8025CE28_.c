// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
} Unk8025CE28;
extern void fn_8000D838(void *);
extern int lbl_8055F3A8;
extern Unk8025CE28 lbl_80498EB8;
extern int lbl_8055F3B0;

void fn_8025CE28(void) {
    fn_8000D838(&lbl_8055F3A8);
    *(int *)&lbl_80498EB8 = 0;
    lbl_80498EB8.unk4 = 0x7B;
    lbl_80498EB8.unk8 = 0;
    lbl_80498EB8.unkC = 0;
    lbl_80498EB8.unk10 = 0;
    lbl_8055F3B0 = 0x7F000000;
}
