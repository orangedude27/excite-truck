// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562B54;
void fn_801DA198(int, float);
extern void *fn_80128668(void *);
extern void fn_80128670(void *);
extern int lbl_80339288[];
extern float fn_801DA6B8(int);
extern void *fn_801284F8(int, void *);
extern void fn_801D0DDC(void *);
extern int lbl_803381C0[];
extern int lbl_80339258[];
extern void *lbl_8055AD98;
extern void *lbl_8055E984;

void *__dt__14CollisionSpaceFv_801DAB70(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80339288;
        fn_80128670(*(void **)((char *)arg0 + 4));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

float fn_801DAC5C(void *arg0) {
    float value;
    float max;
    int count;
    int offset;
    int i;
    void **items;
    count = *(int *)((char *)arg0 + 8);
    offset = 0;
    max = lbl_80562B54;
    if (count > 0) {
        items = *(void ***)((char *)arg0 + 4);
        for (i = 0; i < count; i++) {
            value = *(float *)((char *)(*(void **)((char *)items[offset / 4] + 0x28)) + 0xC);
            if (max > value) {
            } else {
                max = value;
            }
            offset += 4;
        }
    }
    return max;
}

#pragma scheduling off
int fn_801DAD7C(void *arg0) {
    int count;
    int index;
    void **items;
    count = *(int *)((char *)arg0 + 8);
    index = 0;
    items = *(void ***)((char *)arg0 + 4);
    if (count <= 0)
        return 1;
    while (count-- > 0) {
        if (*((unsigned char *)items[index] + 0x18) != 0)
            return 0;
        index++;
    }
    return 1;
}
void fn_801DADBC(void *arg0) {
    int i;
    int offset;
    void **items;
    offset = 0;
    i = 0;
    while (i < *(int *)((char *)arg0 + 8)) {
        items = *(void ***)((char *)arg0 + 4);
        fn_801DA198(*(int *)((char *)items[offset / 4] + 0x28), lbl_80562B54);
        offset += 4;
        i += 1;
    }
}

void fn_801DAEF4(void) {

}

void fn_801DAEF8(void) {

}

void fn_801DAEFC(void *arg0) {
    unsigned char *entry;
    int i;
    entry = (unsigned char *)arg0 + 8;
    i = 0;
    for (; i < *(int *)((char *)arg0 + 0x5808); i++) {
        unsigned char flag = entry[0x19];
        fn_801DA198(*(int *)(entry + 0x28), (entry[0x18] = flag, lbl_80562B54));
        entry += 0x2C;
    }
}

