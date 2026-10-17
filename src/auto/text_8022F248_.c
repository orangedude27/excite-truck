// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F014;
extern float lbl_805635FC;
extern float lbl_8056360C;
void fn_8022FB6C(void);
void fn_80214D48(void);
void fn_8022FD9C(int);
void fn_80015EB0(float);
void fn_80015E30(void *, float);
void fn_80015B20(void *, void *, void *);
void fn_80015AA0(void *, float);
void fn_8022FF90(void *arg0) {
    float f0 = lbl_805635FC;
    float f1 = lbl_8056360C;
    *(float *)((char *)arg0 + 4) = f0;
    *(float *)((char *)arg0 + 0) = f1;
    *(float *)((char *)arg0 + 8) = f0;
    *(float *)((char *)arg0 + 0xC) = f0;
    *(float *)((char *)arg0 + 0x10) = f1;
    *(float *)((char *)arg0 + 0x14) = f0;
    *(float *)((char *)arg0 + 0x18) = f0;
    *(float *)((char *)arg0 + 0x1C) = f0;
    *(float *)((char *)arg0 + 0x20) = f1;
    *(float *)((char *)arg0 + 0x24) = f0;
    *(float *)((char *)arg0 + 0x28) = f0;
    *(float *)((char *)arg0 + 0x2C) = f0;
    *(unsigned int *)((char *)arg0 + 0x34) = 0xFF000000;
    *(int *)((char *)arg0 + 0x38) = -1;
    *(float *)((char *)arg0 + 0x8C) = f0;
    *(float *)((char *)arg0 + 0x94) = f0;
    *(float *)((char *)arg0 + 0x98) = f0;
}

void fn_8022FFE8(int arg0) {
    fn_8022FB6C();
    fn_80214D48();
    fn_8022FD9C(arg0);
}

int fn_80230020(void) {
    int count = 0;
    void *p = lbl_8055F014;
    while (p != 0) {
        p = *(void **)((char *)p + 8);
        count++;
    }
    return count;
}
