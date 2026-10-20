// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_80335DCC;
extern char lbl_8055E6D0;
extern int memset(void *, int, unsigned int);
extern int lbl_8055E6D4;
extern void fn_80128670(int);
extern void fn_80128668(void *);
#pragma cplusplus on
extern "C" {
struct F801B4610 {
    virtual void f2(int) = 0;
};
}
#pragma cplusplus off
#pragma push
#pragma small_data off
extern char lbl_80435C70;
#pragma pop
extern char lbl_80335E48;
extern void fn_802E317C(const char *, int);
extern int __dt__15shdStateMachineFv_801B496C(int);
extern void *lbl_8055E6D8;
extern int *fn_801B479C();
extern int fn_801B47BC();
extern int fn_801B4B9C(int);
extern int fn_801B47AC(int);
extern int fn_802E30C8(int *, ...);
extern int fn_801284F8(int, int *);
extern int fn_801B4904(void);
#pragma push
#pragma small_data off
extern int lbl_80335E10;
extern int lbl_80335E28;
#pragma pop
void fn_801B45E0(void *arg0) {
    *(int *)((char *)arg0 + 0x00) = 0;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
    *(int *)((char *)arg0 + 0x0C) = 0;
    *(int *)((char *)arg0 + 0x08) = 0;
    *(int *)((char *)arg0 + 0x04) = 0;
    *(int *)((char *)arg0 + 0x18) = 0;
    *(int *)((char *)arg0 + 0x24) = 0;
    *(int *)((char *)arg0 + 0x20) = 0;
    *(int *)((char *)arg0 + 0x1C) = 0;
}

#pragma push
#pragma cplusplus on
extern "C" void *fn_801B4610(void *arg0, int arg1) {
    int zero;
    if (arg0 != 0) {
        F801B4610 *obj = *(F801B4610 **)arg0;
        if (obj != 0) {
            obj->f2(1);
        }
        zero = 0;
        *(int *)((char *)arg0 + 0x00) = zero;
        *(int *)((char *)arg0 + 0x14) = zero;
        *(int *)((char *)arg0 + 0x10) = zero;
        *(int *)((char *)arg0 + 0x0C) = zero;
        *(int *)((char *)arg0 + 0x08) = zero;
        *(int *)((char *)arg0 + 0x04) = zero;
        fn_80128670(*(int *)((char *)arg0 + 0x18));
        *(int *)((char *)arg0 + 0x18) = zero;
        *(int *)((char *)arg0 + 0x24) = zero;
        *(int *)((char *)arg0 + 0x20) = zero;
        *(int *)((char *)arg0 + 0x1C) = zero;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma cplusplus off
#pragma pop
extern int lbl_80335DB8;
extern int fn_8012850C(int, int *);
extern int fn_802E4CA4(int);
extern void fn_801B4720(int);
#pragma push
#pragma small_data off
#pragma pop
void fn_801B46BC(void *arg0, int arg1, int arg2) {
    *(int *)((char *)arg0 + 0x1C) = arg1;
    *(int *)((char *)arg0 + 0x18) = fn_8012850C(arg1 * 0xC, &lbl_80335DB8);
    *(int *)((char *)arg0 + 4) = arg2;
    *(int *)arg0 = fn_802E4CA4(arg2);
    fn_801B4720((int)arg0);
}
void fn_801B4720(int arg0) {
    unsigned int i;
    int offset;
    int *entries;

    i = 0;
    offset = 0;
    entries = *(int **)(arg0 + 0x18);
    while (i < *(unsigned int *)(arg0 + 0x1C)) {
        entries[offset / 4] = -1;
        *(int *)((char *)entries + offset + 4) = 0;
        *(int *)((char *)entries + offset + 8) = 0;
        offset += 12;
        i++;
    }
    *(int *)(arg0 + 8) = 0;
    *(int *)(arg0 + 0xC) = *(int *)(arg0 + 4);
    *(int *)(arg0 + 0x10) = *(int *)(arg0 + 4);
    *(int *)(arg0 + 0x14) = 0;
    *(int *)(arg0 + 0x20) = 0;
    *(int *)(arg0 + 0x24) = 0;
    (*(void (**)(void))(*(int *)*(int *)arg0 + 0x18))();
}

#pragma dont_inline on
int *fn_801B479C(int arg0, int arg1) {
    return (int *)(*(int *)(arg0 + 0x18) + arg1 * 12);
}
#pragma dont_inline reset

#pragma dont_inline on
int fn_801B47AC(int arg0) {
    return *(int *)(arg0 + 0x20);
}
#pragma dont_inline off

#pragma dont_inline on
int fn_801B47B4(void *arg0) {
    return fn_801B47D4(arg0, *(int *)((char *)arg0 + 0x24));
}
#pragma dont_inline off

int fn_801B47D4(int arg0, int arg1) {
    if (arg1 != 0) return arg1 - 1;
    return *(int *)(arg0 + 0x1C) - 1;
}

int fn_801B47F0(int arg0) {
    unsigned int a = *(unsigned int *)(arg0 + 0x20);
    unsigned int b = *(unsigned int *)(arg0 + 0x24);
    if (a >= b) return b + (*(int *)(arg0 + 0x1C) - a);
    return b - a;
}

int fn_801B4818(void) { return 0x100000; }

void fn_801B4820(int *arg0, int *arg1, unsigned int arg2) {
    unsigned int value;
    unsigned int limit;

    value = arg2 / ((fn_801B2F24() + 1) * 0x44 + 0xC);
    limit = 0x7E90;
    if ((int)value < 0x7E90) {
        limit = value;
    }
    *arg0 = 0x5000;
    *arg1 = 0x32;
    fn_802E30C8(&lbl_80335DCC, (limit / 9) / 60, (limit / 9) % 60,
                (0x32 * 0xC) >> 10, *arg0 / 1024, arg2 >> 10);
}

#pragma dont_inline on
void fn_801B49C8(void *arg0) {
    *(unsigned char *)arg0 = 1;
}
#pragma dont_inline reset

extern int fn_801B4B44(char *);
extern void fn_801B4C9C(int, int);
extern void fn_801B4C58();
extern void fn_801B4C60();
extern float fn_801B4D10(int, int);
int fn_801B49D4(void *arg0, void **arg1, void **arg2, float *arg3, int arg4) {
    int index;
    void *obj;
    int (*call)(void *, int, int);
    if (fn_801B4B44(arg0) == 0) return 0;
    index = ((int (*)(void *, int))fn_801B4C9C)(arg0, arg4);
    obj = ((void *(*)(void *, int))fn_801B4C58)(arg0, index);
    call = (int (*)(void *, int, int))(*(void ***)*(void **)((char *)arg0 + 4) + 3);
    *arg1 = (void *)call(*(void **)((char *)arg0 + 4), *(int *)((char *)obj + 8), 0x2200);
    if (fn_801B4C1C((int)arg0, arg4)) *arg2 = *arg1;
    else {
        obj = ((void *(*)(void *, int))fn_801B4C60)(arg0, index);
        *arg2 = (void *)call(*(void **)((char *)arg0 + 4), *(int *)((char *)obj + 8), 0x2200);
    }
    *arg3 = fn_801B4D10((int)arg0, arg4);
    return 1;
}

int fn_801B4B44(char *arg0) {
    int result = 0;
    if (fn_801B47F0((int)(arg0 + 4)) != 0 && *arg0 != 0) result = 1;
    return result;
}

int fn_801B4B9C(int arg0) {
    return *fn_801B479C(arg0 + 4, fn_801B47AC(arg0 + 4));
}

int fn_801B4BDC(int arg0);

int fn_801B4C1C(int arg0, int arg1) {
    int result = (int)fn_801B4BDC(arg0);
    return arg1 >= result;
}

int fn_801B4BDC(int arg0) {
    void *p = (void *)(arg0 + 4);
    return *fn_801B479C(arg0 + 4, fn_801B47B4(p));
}

void fn_801B4C58(int arg0, int arg1) {
    fn_801B479C(arg0 + 4, arg1);
}

void fn_801B4C60(int arg0) {
    fn_801B479C(arg0 + 4, fn_801B47BC(arg0 + 4));
}

void fn_801B4C9C(int arg0, int arg1) {
    int count;
    int value;

    count = arg1 - fn_801B4B9C(arg0);
    value = fn_801B47AC(arg0 + 4);
    count /= 6;
    do {
        fn_801B47BC(arg0 + 4, value);
        count--;
    } while (count != 0);
}

extern double lbl_80562660;
extern float lbl_80562658;
float fn_801B4D10(int arg0, int arg1) {
    return (float)((arg1 - fn_801B4B9C(arg0)) % 6) / lbl_80562658;
}

void *__AXGetStudio_80178C90(void);
int fn_801B4D80(void *, int, int, float);
void fn_801B5060(int arg0, int arg1, float arg2) {
 void *studio = __AXGetStudio_80178C90();
 fn_801B4D80(studio, arg0, arg1, arg2);
}

char fn_801B526C(void) {
    return lbl_8055E6D0;
}

extern int memset(void *, int, unsigned int);
extern int lbl_8055E6D4;
#pragma push
#pragma small_data off
void fn_801B5274(void) {
    memset((char *)&lbl_80435C70 + 0x208, 0, 0x40);
    *(int *)((char *)&lbl_80435C70 + 0x200) = 0;
    *(int *)((char *)&lbl_80435C70 + 0x204) = 0;
    lbl_8055E6D8 = 0;
    lbl_8055E6D0 = 0;
    lbl_8055E6D4 = 3;
}
#pragma pop
void fn_801B52CC(void) {
    int result;
    fn_802E30C8(&lbl_80335E10);
    result = fn_801284F8(0x2C, &lbl_80335E28);
    if (result != 0) {
        result = fn_801B4904();
    }
    lbl_8055E6D8 = (void *)result;
}

void fn_801B5318(void) {

}

extern void *lbl_8055E6D8;
extern void fn_801B49C8(void *);
extern char lbl_80435C70;
extern char lbl_80335E48;
extern void fn_802E317C(const char *, int);
extern int __dt__15shdStateMachineFv_801B496C(int);
void fn_801B531C(void) {
    if (lbl_8055E6D8 != 0) {
        __dt__15shdStateMachineFv_801B496C(1);
        lbl_8055E6D8 = 0;
    }
}

void fn_801B5354(void) {
    fn_801B49C8(lbl_8055E6D8);
}

void fn_801B535C(void) {

}

void fn_801B5360(void) {

}

void fn_801B5364(int arg0, int arg1) {
    *(int *)((char *)&lbl_80435C70 + 0x208 + arg0 * 4) = arg1;
}

void fn_801B537C(int arg0) {
    int i;
    for (i = 0; i < 16; i++) {
        if (*(int *)((char *)&lbl_80435C70 + 0x208 + i * 4) == arg0) {
            *(int *)((char *)&lbl_80435C70 + 0x208 + i * 4) = 0;
            return;
        }
    }
    fn_802E317C(&lbl_80335E48, arg0);
}

