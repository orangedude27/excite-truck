// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void *);
extern unsigned char lbl_8055E32C;
extern float lbl_805618F0;
extern float lbl_8055E318;
extern float fn_80129DC4(int, float, float, float);

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
#pragma push
#pragma small_data off
void *fn_80165970(void *arg0, int arg1) {
    if (arg0 == 0) goto done;
    if (arg0 == 0) goto after_clear;
    *(int *)arg0 = 0;
    *((int *)arg0 + 1) = 0;
    *((int *)arg0 + 2) = 0;
after_clear:
    if (arg1 > 0) fn_80128668(arg0);
done:
    return arg0;
}

float fn_801659D0(int arg0) {
    float temp_f31;
    temp_f31 = fn_8013672C(arg0);
    return temp_f31 * (float)fn_800081F0(arg0);
}

void *fn_80166040(int arg0) {
    void *base;
    void *cur;
    void *found;
    int count;
    int i;
    base = *(void **)&lbl_8042FEB0;
    count = *(int *)((char *)&lbl_8042FEB0 + 4);
    cur = base;
    found = 0;
    i = 0;
    while (count > 0) {
        if (*(int *)((char *)cur + 0x10) == -1) {
            found = (char *)base + i * 0x14;
            *(int *)((char *)found + 0x10) = arg0;
            break;
        }
        cur = (char *)cur + 0x14;
        i++;
        count--;
    }
    return found;
}
#pragma pop
void fn_80166098(void) {
    fn_80179630(-1);
    fn_801B2EC0();
}

int fn_8016616C(void) {
    return lbl_8055E320 > *(float *)((char *)&lbl_8042FE38 + 0x48);
}

extern void fn_80128668(void *);
extern void fn_80163550(int);
extern int fn_800081F0(int);
extern int fn_801B2EC0(void);
extern void *fn_8017960C(void);
extern float lbl_805618D0;
extern float lbl_805618D4;
float fn_80166274(void) {
    float f2 = lbl_805618D0;
    void *p;
    fn_80179630(-1);
    p = *(void **)(*(int *)(fn_801B2EC0()) + 0x1C);
    p = ((void *(*)(void))p)();
    fn_80179630(-1);
    {
        void *r3 = fn_8017960C();
        float f0 = *(float *)(*(int *)((char *)p + 4) + 0x20);
        float f1 = *(float *)((char *)r3 + 0x25CC);
        if (f2 <= f0) f2 = f0;
        f0 = f1 / f2;
        if (lbl_805618D4 > f0) f0 = lbl_805618D4;
        return f0;
    }
}

int fn_801667F0(void) {
    int result = 0;
    if (lbl_8055E32A) {
        if (!lbl_8055E32B) result = 1;
    }
    return result;
}

void fn_80166E54(void *arg0) {
    *(float *)((char *)arg0 + 0xC) += lbl_805618F0;
}

void fn_80166F3C(float *arg0) {
    *arg0 = lbl_8055E318 + ((float (*)(int))fn_80129DC4)(3);
}

int fn_80166F78(float *arg0) {
    return lbl_8055E318 > *arg0;
}

unsigned char fn_801671AC(int arg0) { void *base; if (!((int (*)(void))fn_801667F0)()) return 0; base = *(void **)&lbl_8055E32C; return *((unsigned char *)((char *)*(void **)base + arg0 * 0x88 + 0x5C)); }

unsigned char fn_80167544(int arg0) { if (((int (*)(void))fn_801667F0)()) return *((unsigned char *)((char *)*(void **)&lbl_8055E32C + arg0 * 0x88 + 0x5D)); return 0; }

unsigned char fn_80167594(int arg0) { if (((int (*)(void))fn_801667F0)()) return *((unsigned char *)((char *)*(void **)&lbl_8055E32C + arg0 * 0x88 + 0x5E)); return 0; }

unsigned char fn_801675E4(int arg0) { if (((int (*)(void))fn_801667F0)()) return *((unsigned char *)((char *)*(void **)&lbl_8055E32C + arg0 * 0x88 + 0x5F)); return 0; }

extern float lbl_8055E324;
extern float fn_801660C0(void);
extern void fn_802E30C8(char *, ...);
extern char lbl_8032FF8C[];
extern char lbl_8032FFC4[];
void fn_80167684(float arg0) {
    float temp_f31;
    if (!lbl_8055E32B && arg0 < *(float *)((char *)&lbl_8042FE38 + 0x5C)) {
        temp_f31 = (lbl_8055E324 - fn_801660C0()) / *(float *)((char *)&lbl_8042FE38 + 0x60);
        if (temp_f31 > arg0) {
            fn_802E30C8(lbl_8032FF8C);
            fn_802E30C8(lbl_8032FFC4, arg0, temp_f31);
            lbl_8055E32B = 1;
        }
    }
}

#pragma push
#pragma small_data off
unsigned char fn_80167758(void) { return *((unsigned char *)&lbl_8042FE38 + 0x4E); }
int fn_80167768(float arg0) { return arg0 > *(float *)((char *)&lbl_8042FE38 + 0x50); }
#pragma pop
extern float lbl_80561898;
extern float lbl_805618D8;
extern float lbl_805618DC;
extern float lbl_805618E0;
extern float lbl_8055E318;
extern float lbl_80558DC4;
extern float fn_80129DC4(int, float, float, float);
extern void fn_80128670(void *);
extern void fn_80139E18(void);
extern unsigned char lbl_8055E32C;
extern unsigned char lbl_8055E334;
