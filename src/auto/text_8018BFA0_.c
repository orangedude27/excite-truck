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
extern float lbl_80561F74;
extern float lbl_80562050;
extern float lbl_80561F8C;
extern float lbl_8055E3C8;
extern float lbl_80561F70;
extern int lbl_80332840;
void *fn_801B83A0(void);
int fn_80161A38(int, int, int);
int fn_801DFF1C(int);
float PSQUATMultiply(void *, void *);
