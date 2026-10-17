// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8018C50C(void) {

}

void fn_8018C510(void) {

}

extern int lbl_80332840;
extern float lbl_80561F74;
extern float lbl_80562050;
extern float lbl_80561F8C;
extern float lbl_8055E3C8;
extern float lbl_80561F70;
extern float PSQUATMultiply(void *, void *);
int fn_8018C514(void *arg0, void *arg1) {
    float min = lbl_80561F70;
    int best = 0;
    int i = 1;
    int offset = 0x34;
    while (i < *(int *)((char *)arg0 + 0x26C)) {
        float value = PSQUATMultiply(arg1, (char *)arg0 + offset + 0x20);
        if (value < min) {
            min = value;
            best = i;
        }
        offset += 0x34;
        i++;
    }
    return best;
}

void fn_8018F6F8(void *arg0) {
    int i;
    char *type = (char *)&lbl_80332840;
    char *entry = (char *)arg0 + 0x152C;
    for (i = 0x11; i != 0; i--) {
        if (*(int *)entry != 0 && *(int *)(entry + 0x7C) == 0 &&
            (unsigned int)(*(int *)type - 0xE) <= 2U) {
            *(int *)(entry + 0x7C) = 4;
            *(char *)(entry + 0x78) = 0;
            *(float *)(entry + 0xC) = lbl_80561F74;
            *(float *)(entry + 0x10) = *(float *)(entry + 0x14) / lbl_80562050;
        }
        type += 0x40;
        entry += 0x80;
    }
}

extern float lbl_80561F74;
extern float lbl_80562050;
extern float lbl_80561F8C;
extern float lbl_8055E3C8;
extern float lbl_80561F70;
extern int lbl_80332840;
int fn_80161A38(int, int, int);
int fn_801DFF1C(int);
float PSQUATMultiply(void *, void *);
