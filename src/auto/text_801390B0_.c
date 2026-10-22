// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_801392F8(void *arg0) {
    if (*(int *)((unsigned char *)arg0 + 0x1F0) == 0x50) {
        return *(unsigned char *)((unsigned char *)arg0 + 0x260) & 3;
    }
    return 0;
}
extern void *lbl_8032BFA0;
extern void *lbl_8032BFAC;
extern float lbl_805613E4;
extern float lbl_805613E8;
extern float lbl_805613EC;
extern void fn_80148134(float *, float *, int, float, float);
extern void fn_802C8E00(int, int, float, float, float, float, float);
