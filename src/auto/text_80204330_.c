// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055ED48;
extern int fn_802E2C20(void);
int fn_80204354(void);
extern float lbl_80563168, lbl_8056316C, lbl_80563170, lbl_80563174, lbl_80563178, lbl_8056317C;
extern double lbl_80563180;
extern char lbl_80488BD0[];
#pragma dont_inline on
void fn_80204330(void) {
    lbl_8055ED48 = (void*)fn_802E2C20();
}
#pragma dont_inline off

int fn_80204354(void) { return fn_802E2C20() - (int)lbl_8055ED48; }

int fn_802E2C20(void);
extern int fn_80145E70(void*);
extern char lbl_8033BB18[];
extern int lbl_8055ED3C, lbl_8055ED40, lbl_8055ED44;
struct Obj80204 { void (*dtor)(void *, int); };
#pragma dont_inline
unsigned int fn_8020437C(void) {
    int temp = fn_80204354() ^ 0xDAC;
    return (unsigned int)(((temp & 0xDAC) * -1) + (temp >> 1)) >> 31;
}
void fn_802043B0(int *arg0) {
 float val = lbl_80563168;
 float temp = ((float)fn_80204354() - lbl_8056316C) / lbl_80563170;
 int packed;
 if (val < temp) val = temp;
 if (val > lbl_80563174) val = lbl_80563174;
 packed = *arg0 & 0xFFFFFF;
 *arg0 = packed;
 *arg0 = packed | ((int)(lbl_80563178 + val * lbl_8056317C) << 24);
}

void fn_80204460(void) {
    lbl_8055ED3C = 0;
    lbl_8055ED40 = 0;
    lbl_8055ED48 = 0;
    lbl_8055ED44 = fn_80145E70(lbl_8033BB18);
}

void fn_8020449C(void) {
    void *obj;
    lbl_8055ED3C = 0;
    obj = (void *)lbl_8055ED44;
    if (obj != 0) ((void (**)(void *, int))((int)*(void **)obj + 8))[0](obj, 1);
    lbl_8055ED44 = 0;
}

void fn_802049DC(int a, int b, float c, float d, float e) {
    int i;
    char *entry;
    i = lbl_8055ED3C;
    if (i < 0x40) {
      entry = lbl_80488BD0 + i * 0x18;
      *(int *)(entry + 0) = a;
      *(int *)(entry + 4) = 1;
      *(int *)(entry + 8) = b;
      *(float *)(entry + 0xC) = c;
      *(float *)(entry + 0x10) = d;
      lbl_8055ED3C = i + 1;
      *(float *)(entry + 0x14) = e;
    }
}

void fn_80204A1C(int a, int b) {
    int i;
    char *entry;
    i = lbl_8055ED3C;
    if (i < 0x40) {
      entry = lbl_80488BD0 + i * 0x18;
      *(int *)(entry + 0) = a;
      *(int *)(entry + 4) = 0;
      lbl_8055ED3C = i + 1;
      *(int *)(entry + 8) = b;
    }
}

void fn_80204A50(void) {
    fn_80204330();
}
