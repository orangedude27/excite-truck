// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8029690C(void);
extern float lbl_80564560;
extern float lbl_80564564;
extern float lbl_80564568;
int fn_802969B4(unsigned int arg0, unsigned int arg1, float farg0) {
    return (int)((float)arg0 + farg0 * ((float)arg1 - (float)arg0));
}

void fn_80296AAC(void *arg0) {
    memset(0, 0, 0x30);
    *(float *)((char *)arg0 + 0x10) = lbl_80564560;
    *(float *)((char *)arg0 + 8) = lbl_80564560;
    *(float *)((char *)arg0 + 0) = lbl_80564564;
    *(float *)((char *)arg0 + 0x1C) = lbl_80564568;
    *(int *)((char *)arg0 + 0x18) = -1;
    *(int *)((char *)arg0 + 0x2C) = 10;
    *(int *)((char *)arg0 + 0x14) = -1;
}

void fn_80296D24(void) {
}

