// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8033C258[];
extern char lbl_8033C268[];
extern int lbl_8055B548;
extern void *fn_801284F8(unsigned int, void *);
extern void *fn_802077A4(void *, int, void *, void *);
extern void *fn_8020CA3C(void *);
extern float lbl_80563278, lbl_8056327C, lbl_80563280, lbl_80563284, lbl_80563288;

// 0x74-byte record: value at 0x68, enable byte at 0x6c.
typedef struct {
    /* 0x00 */ char pad_00[0x68];
    /* 0x68 */ float value;
    /* 0x6c */ signed char enabled;
    /* 0x6d */ char pad_6D[7];
} Record;

// The record array starts at 0x2420 of the object fn_80209E94 loads; the
// first value/enable pair sits just before it.
typedef struct {
    /* 0x0000 */ char pad_0[0x2414];
    /* 0x2414 */ float firstValue;
    /* 0x2418 */ signed char firstEnabled;
    /* 0x2419 */ char pad_2419[7];
    /* 0x2420 */ Record records[3];
} RecordSet;
#pragma scheduling invalid_target
void *fn_80209D4C(void *arg0) {
    void *obj;
    void *child;
    obj = fn_801284F8(0x10, &lbl_8055B548);
    if (obj != 0) {
        *(void **)obj = lbl_8033C258;
        *((void **)obj + 1) = arg0;
        child = fn_802077A4(lbl_8033C268, 4, (char *)arg0 + 0x118, (char *)arg0 + 0x60);
        *((void **)obj + 2) = child;
        if (child != 0) *(int *)((char *)child + 0x10) = *(int *)((char *)*((void **)obj + 1) + 0x1ec);
        *((void **)obj + 3) = (void *)fn_8020CA3C(arg0);
    }
    return obj;
}

extern void fn_80128668(void *);
#pragma scheduling invalid_target
void *fn_80209DE4(void *arg0, int arg1) {
    register void *p;
    if (arg0 != 0) {
        p = *(void **)((char *)arg0 + 8);
        *(void **)arg0 = lbl_8033C258;
        if (p != 0) {
            if (p != 0) {
                ((void (*)(void *, int))(*(void * volatile **)p)[2])(p, 1);
            }
            *(void **)((char *)arg0 + 8) = 0;
        }
        p = *(void **)((char *)arg0 + 0xc);
        if (p != 0) {
            if (p != 0) {
                ((void (*)(void *, int))(*(void * volatile **)p)[2])(p, 1);
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma scheduling on
void fn_80209E94(void *arg0) {
    RecordSet *set = *(RecordSet **)((char *)arg0 + 4);
    Record *records = set->records;
    float total = lbl_80563278;
    float minimum = lbl_80563278;
    float bias = lbl_8056327C;
    float limit = lbl_80563280;
    float value;
    float replacement;
    char *obj;

    value = records[-1].value - bias;
    if (records[-1].enabled == 0 && value > minimum) {
        if (limit < value) {
            value = limit;
        }
        total += value;
    }
    value = records[0].value - bias;
    if (records[0].enabled == 0 && value > minimum) {
        if (limit < value) {
            value = limit;
        }
        total += value;
    }
    value = records[1].value - bias;
    if (records[1].enabled == 0 && value > minimum) {
        if (limit < value) {
            value = limit;
        }
        total += value;
    }
    value = records[2].value - bias;
    if (records[2].enabled == 0 && value > minimum) {
        if (limit < value) {
            value = limit;
        }
        total += value;
    }

    obj = *(char **)((char *)arg0 + 8);
    replacement = lbl_80563284;
    if (replacement != *(float *)(obj + 4)) {
        *(signed char *)(obj + 0x4e) = 1;
        *(float *)(obj + 4) = replacement;
    }
    obj = *(char **)((char *)arg0 + 8);
    if (total != *(float *)(obj + 8)) {
        *(signed char *)(obj + 0x4d) = 1;
        *(float *)(obj + 8) = total;
    }
    if (total > lbl_80563288) {
        obj = *(char **)((char *)arg0 + 8);
        *(signed char *)(obj + 0x4a) = 0;
        *(signed char *)(obj + 0x4b) = 1;
        *(signed char *)(obj + 0x49) = 1;
    } else {
        obj = *(char **)((char *)arg0 + 8);
        *(signed char *)(obj + 0x4a) = 1;
        *(signed char *)(obj + 0x4c) = 0;
    }
    obj = *(char **)((char *)arg0 + 0xc);
    if (obj != 0) {
        ((void (*)(void *))(*(void ***)obj)[3])(obj);
    }
}
#pragma scheduling on

#pragma scheduling on


