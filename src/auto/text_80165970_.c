// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055E32A;
extern unsigned char lbl_8055E32B;
#pragma push
#pragma small_data off
extern unsigned char lbl_8042FE38;
extern unsigned char lbl_8042FEB0;
#pragma pop
extern float lbl_8056189C;
extern double lbl_80561890;
extern float lbl_8055E320;
extern float fn_8013672C(int);
extern int fn_80179630(int);
extern int fn_801B2EC0();
extern int fn_80179630(int);
extern int fn_801B2EC0();
extern float fn_8013672C(int);
extern float lbl_8056189C;
extern double lbl_80561890;
extern unsigned char lbl_8042FE38;
extern unsigned char lbl_8042FEB0;
extern float lbl_8055E320;
void fn_80166098(void) {
    fn_80179630(-1);
    fn_801B2EC0();
}

int fn_8016616C(void) {
    return lbl_8055E320 > *(float *)((char *)&lbl_8042FE38 + 0x48);
}

int fn_801667F0(void) {
    int result = 0;
    if (lbl_8055E32A) {
        if (!lbl_8055E32B) result = 1;
    }
    return result;
}
