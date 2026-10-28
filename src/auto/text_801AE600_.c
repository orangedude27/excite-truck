extern int lbl_80435780[];
extern void *fn_801AF8D0(int);
extern void fn_801AFABC();
extern int *lbl_8055E624;
extern unsigned char *fn_801EA9A0(int);
extern int fn_801B8728(void);
extern int fn_801B2C70(void *);
extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern char lbl_80558DC4[];
extern float lbl_8055E630;
extern float lbl_8056255C;
  extern float lbl_80562558;
  extern float lbl_80562560;
extern int lbl_8055E628;
extern signed char lbl_8055E635;
  extern int lbl_8055E62C;
  extern double lbl_80562568;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80435740[];

int fn_801AE618(int arg0);
int fn_801AE600(int arg0) {
    return arg0 == 0x50;
}

short fn_801AE610(int arg0, short arg1) {
    return 0;
}

#pragma dont_inline on
int fn_801AE618(int arg0) {
    return arg0 & 1;
}
#pragma dont_inline reset

#pragma dont_inline on
int fn_801AE620(void *arg0) {
    return fn_801AE618(*(unsigned short *)((char *)arg0 + 0xE));
}
#pragma dont_inline reset

#pragma dont_inline on
int fn_801AE790(void *arg0) {
    return *((unsigned char *)arg0 + 0x70) & 3;
}
#pragma dont_inline reset

#pragma scheduling invalid_target
void fn_801AE79C(int arg0) {
    register int flag;
    register int *base;
    register char *entry;
    short selected;
    int index;

    flag = 0;
    if (arg0 == 2 && lbl_80435780[0x3C0 / 4] > 10)
        flag = 1;
    if (flag != 0) {
        entry = (char *)lbl_80435780;
        base = (int *)entry;
        selected = 0;
        index = 0;
        for (; index < base[0x3C0 / 4]; entry += 0x78, index++) {
            if (*(int *)entry == 0x50 && fn_801AE790(entry) == 0) {
                void *value = fn_801AF8D0(index);
                if (value != 0)
                    selected = *(short *)((char *)value + 0xC);
            }
        }
        if (selected >= 1)
            fn_801AFABC(lbl_8055E628, selected);
    }
}
#pragma scheduling on
extern int lbl_8055E62C;
extern float lbl_8056255C;
extern double lbl_80562568;
void fn_801AE874(unsigned short *arg0, int arg1) {
    unsigned short value = *arg0 | 1;
    *arg0 = value;
    if (arg1) *arg0 = value | 4;
}

#pragma scheduling invalid_target
void fn_801AE894(void *arg0) {
    float temp_f2;
    float temp_f4;
    register int temp_r0;

    temp_r0 = *(short *)((char *)arg0 + 0x18);
    if (temp_r0 > 0) {
        temp_f4 = *(float *)arg0;
        if (temp_f4 > lbl_8056255C) {
            temp_f2 = (lbl_8055E630 * (float)temp_r0) / temp_f4;
            *(float *)((char *)arg0 + 4) = temp_f2;
            *(float *)((char *)arg0 + 4) =
                temp_f2 * ((float)temp_r0 / (float)lbl_8055E62C);
            return;
        }
    }
    *(float *)((char *)arg0 + 4) = lbl_80562560;
}

#pragma processor 750
#pragma dont_inline on
void fn_801AE928(void) {
    int count;
    float duration;
    int offset;
    int index;
    char *entry;
    count = fn_801EA994();
    duration = lbl_80562560;
    index = 0;
    offset = 0;
    while (index < count) {
        if (index < lbl_8055E624[1]) {
            entry = (char *)lbl_8055E624[0] + offset;
            if (!fn_801AE620(entry)) {
                fn_801AE874((unsigned short *)(entry + 0xE), 1);
                *(unsigned short *)(entry + 0xE) |= 8;
                *(float *)entry = duration;
                fn_801AE894(entry);
            }
        }
        offset += 0x1C;
        index++;
    }
}
#pragma dont_inline reset
#pragma processor gekko

float fn_801AE9E0(int arg0, float *arg1) {
    char *entry;
    if (arg1 != 0) *arg1 = lbl_80562560;
    entry = (char *)lbl_8055E624[0] + arg0 * 0x1C;
    if (fn_801AE620(entry)) {
        if (arg1 != 0) *arg1 = lbl_8055E630 / *(float *)(entry + 8);
        return *(float *)(entry + 8);
    }
    return lbl_80562558;
}

#pragma small_data off
extern float lbl_80562560;
extern float lbl_8055E630;
extern float lbl_80562558;
extern int lbl_8055E62C;
extern double lbl_80562568;
extern float lbl_8056255C;
extern void fn_801AE874(unsigned short *, int);
extern void fn_801AE894(void *);
extern int fn_801EA994(void);
extern double __fabs(double);
int fn_801AEA64(float arg0, float arg1) {
    /* Round the absolute float difference and compare with the full-address tolerance. */
    float diff = arg0 - arg1;
    float magnitude = (float)__fabs((double)diff);
    if (magnitude <= *(float *)(void *)&lbl_80558DC4) return 0;
    if (arg1 < arg0) return 1;
    return -1;
}
#pragma small_data on
void fn_801AED54(void) {

}

void fn_801AED58(void) {

}

extern signed char lbl_8055E634;
extern void fn_801B8778(void);
extern void fn_801B878C(void);
extern float fn_801AF9EC(int, float *);
extern int fn_801AEA64(float, float);
extern void *fn_801AF8D0(int);
void fn_801AED5C(void) {
    lbl_8055E634 = 1;
    fn_801B8778();
}

void fn_801AED68(void) {
    lbl_8055E634 = 0;
    fn_801B878C();
}

extern void *lbl_8055E620;
extern int fn_801B2F24(void);
extern int fn_801B3050(int);
extern int fn_801B2ED4(void);
extern void *memset(void *, int, unsigned int);
void fn_801AED74(void) {
    int i;
    int offset;
    float value;
    void *base;
    void **table;
    int j;
    int k;
    void *entry;
    void *data;

    if (lbl_8055E634 == 0) {
        base = (void *)lbl_8055E624[0];
        value = lbl_80562558;
        offset = 0;
        for (i = 0; i < lbl_8055E624[1]; i++) {
            data = (char *)base + offset;
            memset(data, 0, 0x1C);
            *(float *)((char *)data + 8) = value;
            *(short *)((char *)data + 0xC) = -100;
            if (i < fn_801B2F24())
                *(short *)((char *)data + 0x1A) = fn_801B3050(i);
            else
                *(short *)((char *)data + 0x1A) = -1;
            offset += 0x1C;
        }
        table = (void **)lbl_8055E620;
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 4; k++) {
                entry = table[k];
                if (entry != 0) {
                    for (i = 0; i < *(int *)((char *)entry + 4); i++)
                        *(short *)((char *)*(int *)entry + i * 8 + 6) = 0;
                }
            }
            table += 4;
        }
    }
    lbl_8055E62C = fn_801B2ED4();
}

extern void fn_801AFA5C(int);
extern void fn_80128670(void *);
extern void fn_80128668();
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_801AF598(void) {
    register unsigned int i;
    register int **slot;
    register int *entry;
    register int **array;
    int value = lbl_8055E628;
    int zero = 0;
    lbl_8055E635 = zero;
    fn_801AFA5C(value);
    array = (int **)lbl_8055E620;
    lbl_8055E628 = zero;
    if (array != 0) {
        slot = array;
        for (i = 0; i < 8U; i++, slot++) {
            entry = *slot;
            if (entry == 0)
                goto clear;
            if (entry == 0)
                goto clear;
            fn_80128670((void *)*entry);
            *entry = zero;
            fn_80128668(entry);
        clear:
            *(volatile int **)slot = 0;
        }
        fn_80128668(array);
    }
    {
        register int **last;
        last = (int **)lbl_8055E624;
        lbl_8055E620 = 0;
        if (last != 0) {
            fn_80128670((void *)*last);
            *last = 0;
            fn_80128668(last);
        }
    }
    lbl_8055E624 = 0;
}
#pragma dont_inline reset
#pragma pop

#pragma scheduling invalid_target
void fn_801AF65C(void) {
    int i = 0;
    int offset = 0;
    int *base = lbl_80435780;
    while (i < base[0x3C0 / 4]) {
        char *entry = (char *)lbl_8055E624[0] + offset;
        if (fn_801AE620(entry) && *fn_801EA9A0(i)) {
            *(unsigned short *)(entry + 0xE) |= 2;
        }
        offset += 0x1C;
        i++;
    }
}
#pragma scheduling on
void *fn_801AF8D0(int arg0) {
    void *result = 0;
    if (arg0 < lbl_8055E624[1]) {
        result = (char *)lbl_8055E624[0] + arg0 * 0x1C;
        fn_801AE620(result);
        if (fn_801AE618(*(unsigned short *)((char *)result + 0xE))) {
            result = 0;
        }
    }
    return result;
}

#pragma small_data off
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_801AF92C(void *arg0) {
    void *base = arg0;
    char *entry;
    int count;
    register int i;
    register int zero = 0;
    register int minusOne = -1;

    if (fn_801B8728() != 0)
        goto done;
    if (fn_801B2C70(base) != 0)
        goto done;

    count = lbl_80435780[0x3C0 / 4];
    *(int *)base = count;
    entry = (char *)base + 0x10;
    i = 0;
    *(int *)((char *)base + 4) = zero;
    *((signed char *)base + 0xC) = zero;
    *((signed char *)base + 0xD) = 1;

    for (; i < count; entry += 0x14, i++) {
        void *item = fn_801AF8D0(i);
        if (item != 0) {
            *(int *)(entry + 4) = *(short *)((char *)item + 0xC);
            *(int *)(entry + 8) = zero;
            entry[0x10] = zero;
        } else {
            *(int *)(entry + 4) = minusOne;
            *(int *)(entry + 8) = zero;
            entry[0x10] = zero;
        }
    }

done:
    ;
}
#pragma scheduling on
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma small_data on
float fn_801AF9EC(int arg0, float *arg1) {
    if (arg1 != 0) *arg1 = lbl_80435740[arg0 * 2 + 1];
    return lbl_80435740[arg0 * 2];
}

#pragma scheduling invalid_target
void fn_801AFA20(void) {
    /* Pass the check result through and set its failure value to minus one. */
    int result = fn_801284F8(4, lbl_803359A0);
    if (result != 0) {
        ((void (*)(int *, int))fn_801AFA64)((int *)result, -1);
    }
}
#pragma scheduling on
void fn_801AFA5C(int arg0) { fn_801AFA70(arg0, 1); }

extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern float lbl_80435740[];

void fn_801AFA64(int *arg0) { *arg0 = 0; }

int fn_801AFA70(int arg0, int arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

void fn_801AFAB4(void) {

}

void fn_801AFABC(void) {

}

void fn_801AFAB8(void) {

}

void fn_801AFAB0(void) {

}
extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern float lbl_80435740[];
extern int *lbl_8055E624;
extern unsigned char *fn_801EA9A0(int);
extern int fn_801B8728(void);
extern int fn_801B2C70(void *);
