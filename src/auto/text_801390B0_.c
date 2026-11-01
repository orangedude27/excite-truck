// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8032BFA0;
extern void *lbl_8032BFAC;
extern float lbl_805613E4;
extern float lbl_805613E8;
extern float lbl_805613EC;
extern void fn_80148134(float *, float *, int, float, float);
extern void fn_802C8E00(int, int, float, float, float, float, float);
void fn_801390B0(void *arg0, float *arg1, float *arg2, int arg3, float farg0, float farg1) {
    float sp1C, sp18, sp14, sp10, spC, sp8;
    char *obj;
    float f2, f4, f3, f1;
    int color;
    void *tbl = &lbl_8032BFAC;
    if (arg3 != 0) tbl = &lbl_8032BFA0;
    obj = (*(char *(**)(void *, void *))(*(char **)arg0 + 0x10))(arg0, tbl);
    f4 = farg0 * *(float *)(obj + 0x10) * lbl_805613E8;
    f3 = farg0 * *(float *)(obj + 0x14) * lbl_805613E8;
    f2 = arg2[0];
    f1 = arg2[1];
    sp18 = f2 * f3;
    sp1C = f1 * f3;
    sp10 = f1 * f4;
    sp14 = -(f2 * f4);
    if (obj != 0) {
        color = ((int)(lbl_805613EC * farg1) << 24) | 0xFFFFFF;
        fn_80148134(&spC, &sp8, 0, sp18 + (arg1[0] - sp10), sp1C + (arg1[1] - (float)sp14));
        fn_802C8E00(color, 0, spC, sp8, lbl_805613E4, *(float *)(obj + 0x18), *(float *)(obj + 0x1C));
        fn_80148134(&spC, &sp8, 0, sp18 + (arg1[0] + sp10), sp1C + (arg1[1] + sp14));
        fn_802C8E00(color, 0, spC, sp8, lbl_805613E4, *(float *)(obj + 0x20), *(float *)(obj + 0x1C));
        fn_80148134(&spC, &sp8, 0, (arg1[0] - sp10) - sp18, (arg1[1] - sp14) - sp1C);
        fn_802C8E00(color, 1, spC, sp8, lbl_805613E4, *(float *)(obj + 0x18), *(float *)(obj + 0x24));
        fn_80148134(&spC, &sp8, 0, (arg1[0] + sp10) - sp18, (arg1[1] + sp14) - sp1C);
        fn_802C8E00(color, 1, spC, sp8, lbl_805613E4, *(float *)(obj + 0x20), *(float *)(obj + 0x24));
    }
}

int fn_801392F8(void *arg0) {
    if (*(int *)((unsigned char *)arg0 + 0x1F0) == 0x50) {
        return *(unsigned char *)((unsigned char *)arg0 + 0x260) & 3;
    }
    return 0;
}
