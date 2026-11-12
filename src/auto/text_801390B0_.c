// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma paired off
#pragma paired_single off
extern char lbl_8032BFA0[];
extern char lbl_8032BFAC[];
extern float lbl_805613E4;
extern float lbl_805613E8;
extern float lbl_805613EC;
extern void fn_80148134(float *, float *, int, float, float);
extern void fn_802C8E00(int, int, float, float, float, float, float);
typedef struct VT390 { int pad[4]; char *(*fn)(void *, void *); } VT390;
typedef struct Obj390 { VT390 *vt; } Obj390;
#pragma push
#pragma processor 750
void fn_801390B0(void *arg0, float *arg1, float *arg2, int arg3, float farg0, float farg1) {
    float d[4];
    float pos[2];
    char *obj;
    float f2, f4, f3, f1;
    int color;
    char *tbl = lbl_8032BFAC;
    if (arg3 != 0) tbl = lbl_8032BFA0;
    obj = ((char *(**)(void *, void *))(*(char ***)arg0))[4](arg0, tbl);
    f4 = farg0 * *(float *)(obj + 0x10) * lbl_805613E8;
    f3 = farg0 * *(float *)(obj + 0x14) * lbl_805613E8;
    f2 = arg2[0];
    f1 = arg2[1];
    d[2] = f2 * f3;
    d[3] = f1 * f3;
    d[0] = f1 * f4;
    d[1] = -(f2 * f4);
    if (obj != 0) {
        color = ((int)(lbl_805613EC * farg1) << 24) | 0xFFFFFF;
        fn_80148134(&pos[1], &pos[0], 0, d[2] + (arg1[0] - d[0]), d[3] + (arg1[1] - (float)d[1]));
        fn_802C8E00(color, 0, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x18), *(float *)(obj + 0x1C));
        fn_80148134(&pos[1], &pos[0], 0, d[2] + (arg1[0] + d[0]), d[3] + (arg1[1] + d[1]));
        fn_802C8E00(color, 0, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x20), *(float *)(obj + 0x1C));
        fn_80148134(&pos[1], &pos[0], 0, (arg1[0] - d[0]) - d[2], (arg1[1] - d[1]) - d[3]);
        fn_802C8E00(color, 1, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x18), *(float *)(obj + 0x24));
        fn_80148134(&pos[1], &pos[0], 0, (arg1[0] + d[0]) - d[2], (arg1[1] + d[1]) - d[3]);
        fn_802C8E00(color, 1, pos[1], pos[0], lbl_805613E4, *(float *)(obj + 0x20), *(float *)(obj + 0x24));
    }
}
#pragma pop
int fn_801392F8(void *arg0) {
    if (*(int *)((unsigned char *)arg0 + 0x1F0) == 0x50) {
        return *(unsigned char *)((unsigned char *)arg0 + 0x260) & 3;
    }
    return 0;
}
