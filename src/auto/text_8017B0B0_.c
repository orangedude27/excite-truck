// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E490;
extern int lbl_8055E488;
extern int lbl_8055E48C;
extern void fn_80128670(void*);
extern void fn_8012850C(void*, void*);
extern int fn_8002F37C(void*, int, int, int);
extern char lbl_80331CB8[16];
extern void fn_8017D330(void);
extern void fn_80179E00(void*);
extern void fn_8017B198(void*);
extern void fn_80179D94(void);
extern void fn_8017B2D0(void*, float, float, float, float);
extern void fn_80179D08(void);
extern char lbl_80331CC4[];

void *fn_8017B0B0(void *arg0) {
    fn_80179D08();
    *(int *)((char *)arg0 + 0x184) = 0;
    *(char **)arg0 = lbl_80331CC4;
    *((char *)arg0 + 0x1E8) = 0;
    return arg0;
}

void fn_8017B0F8(void *arg0, float *arg1) {
    fn_80179D94();
    *(volatile int *)((char *)arg0 + 0xD0) = 0;
    fn_8017B2D0(arg0, arg1[2], arg1[3], arg1[4], arg1[5]);
    *(int *)((char *)arg0 + 0x184) = 0;
    fn_8017B198(arg0);
}

void fn_8017B164(void *arg0) {
    fn_80179E00(arg0);
    fn_8017B198(arg0);
}

void fn_8017B4AC(float *arg0, float *arg1) {
    float x = arg0[0x13C / 4] + arg1[0];
    float y = arg0[0x140 / 4] + arg1[1];
    float z = arg0[0x144 / 4] + arg1[2];
    arg0[0x13C / 4] = x;
    arg0[0x140 / 4] = y;
    arg0[0x144 / 4] = z;
}

extern float lbl_80561BA8;
#pragma scheduling off
void fn_8017B6A8(void *arg0) {
    float value = lbl_80561BA8;
    *(int *)((char *)arg0 + 0x1E4) = 0;
    *(float *)((char *)arg0 + 0x188) = value;
    *(float *)((char *)arg0 + 0x18C) = value;
    *(float *)((char *)arg0 + 0x190) = value;
    *(float *)((char *)arg0 + 0x194) = value;
    *(float *)((char *)arg0 + 0x198) = value;
    *(float *)((char *)arg0 + 0x19C) = value;
    *(float *)((char *)arg0 + 0x1A0) = value;
}
#pragma scheduling on
void fn_8017C7BC(void) {

}

void fn_8017C7C0(void) {

}

void fn_8017C7C4(void) {

}

extern unsigned int fn_801B60F4(void *, float);
extern void fn_801B6428(unsigned int, void *);
extern void fn_801B63E0(unsigned int, void *);
void fn_8017D0C8(void *arg0) {
    unsigned int next = fn_801B60F4((char *)arg0 + 0x60, *(float *)((char *)arg0 + 0x2C));
    unsigned int old = *(unsigned int *)((char *)arg0 + 0x184);
    if (next != old) {
        if (old != 0) fn_801B6428(old, arg0);
        *(unsigned int *)((char *)arg0 + 0x184) = next;
        if (next != 0) fn_801B63E0(next, arg0);
    }
}

void fn_8017D140(unsigned char *dst, unsigned char *src, int count) {
    goto check;
loop:
    *dst++ = *src++;
check:
    if (--count >= 0) goto loop;
}

extern void fn_8017A804(void);
int fn_8017D274(void *arg0, void *arg1) {
    fn_8017A804();
    *(float *)((char *)arg1 + 0x14) = *(float *)((char *)arg0 + 0x118);
    *(float *)((char *)arg1 + 0x18) = *(float *)((char *)arg0 + 0x11C);
    *(float *)((char *)arg1 + 0x1C) = *(float *)((char *)arg0 + 0x120);
    return 0x20;
}

void fn_8017D2C8(void) {
    fn_8017B3A8();
}

void fn_8017D2CC(int arg0) {
    lbl_8055E48C = arg0;
    lbl_8055E488 = 0;
    fn_8012850C((char*)(arg0 * 0x28 + 0x10), &lbl_80331CB8);
    lbl_8055E490 = fn_8002F37C(fn_8017D330, 0, 0x28, arg0);
}

void fn_8017D330(void) {

}

void fn_8017D334(void) {
    int value = lbl_8055E490;
    lbl_8055E488 = 0;
    lbl_8055E48C = 0;
    if (value != 0) fn_80128670((char*)value - 0x10);
}

void fn_8017D358(void) {

}

int fn_8017D35C(void) { return 0x20; }

unsigned int fn_8017D364(void) { return 1; }

void fn_8017D36C(void) {

}

