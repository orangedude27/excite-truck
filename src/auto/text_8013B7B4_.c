// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
extern float lbl_8042F8A8[];
extern int lbl_8055E174;
extern double lbl_80561468;
extern float lbl_80561474;
void fn_8013B950(void);
extern int lbl_8055E170;
extern float lbl_80561478, lbl_8056147C;
extern float lbl_8042F8B8[];
extern int fn_801E87A8(void);
extern void fn_8013B7B4(float*, int);
extern void fn_8013B6C0(int*, float*, int);
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern void fn_802E317C(const char *);
extern int stricmp(const char *, const char *);
extern char lbl_8032C390[];
extern const char *lbl_802F9388[];
extern char lbl_80559CD8;
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single off
extern "C" void fn_8013B7B4(float *arg0, int value) {
    struct List {
        virtual void v0() = 0;
        virtual void *getAt(int) = 0;
    };
    struct Item {
        virtual const char *getName() = 0;
    };
    struct DataItem {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual float getFloat(const char *) = 0;
    };
    const char **table;
    char *keys = lbl_8032C390;
    const char **namep;
    float *out;
    void *list;
    void *item;
    int i;
    const char *name;
    const char *names[3];
    unsigned int j;

    list = fn_80131808(keys);
    if (list == 0) goto error;

    table = lbl_802F9388;
    i = 0;
    while ((item = ((List *)list)->getAt(i)) != 0) {
        name = ((Item *)item)->getName();
        names[0] = table[0];
        names[1] = table[1];
        names[2] = table[2];
        out = arg0;
        for (j = 0, namep = names; j < 3; j++, namep++, out += 4) {
            if (stricmp(*namep, name) == 0) {
                out[0] = ((DataItem *)item)->getFloat((const char *)&lbl_80559CD8);
                out[1] = ((DataItem *)item)->getFloat(keys + 0xC);
                out[2] = ((DataItem *)item)->getFloat(keys + 0x18);
                out[3] = (float)value * ((DataItem *)item)->getFloat(keys + 0x28);
            }
        }
        i++;
    }
    fn_80131818(list);
    return;
error:
    ((void (*)(const char *, ...))fn_802E317C)(keys + 0x38);
}
#pragma paired_single reset
#pragma paired reset
#pragma scheduling on
#pragma cplusplus reset

#pragma cplusplus on
extern "C" int fn_80179630(int);
extern "C" int fn_801B2F24(void);
extern "C" int fn_801B2F40(int);
extern "C" void *fn_801B2ED0(int);
extern "C" double fn_801B2F90(int, int);
extern "C" u8 fn_8013BC70(float *);
extern "C" void fn_8013B950(void);
extern float lbl_80561470;
void fn_8013B950(void) {
    struct Dummy {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void *get() = 0;
    };
    float sp8;
    int selected;
    int remaining;
    int index;
    int bestIndex;
    void *bestItem;
    double score;

    *((volatile u8 *)lbl_8042F8A8 + 4) = 0;
    selected = fn_80179630(0);
    if (selected >= 0) {
        remaining = lbl_8055E170;
        bestItem = 0;
        bestIndex = -1;
        index = fn_801B2F24() - 1;
        while (index >= 0) {
            bestIndex = fn_801B2F40(index);
            bestItem = ((struct Dummy *)fn_801B2ED0(bestIndex))->get();
            remaining--;
            if (remaining <= 0) break;
            index--;
        }
        if (bestItem != 0) {
            if (*(int *)((char *)((struct Dummy *)fn_801B2ED0(selected))->get() + 4) >
                *(int *)((char *)bestItem + 4)) {
                score = fn_801B2F90(selected, bestIndex);
                *(volatile float *)lbl_8042F8A8 = score;
                *(int *)((char *)lbl_8042F8A8 + 0xc) = bestIndex;
                *((volatile u8 *)lbl_8042F8A8 + 4) = ((float)score < lbl_80561470);
            }
        }
    }
    if (((int (*)(float *))fn_8013BC70)(&sp8) != 0) {
        float numerator;
        float denominator;
        float endpoint;
        float ratio;
        float value;
        value = lbl_8042F8B8[0];
        numerator = sp8 - value;
        value = lbl_80561474;
        denominator = lbl_8042F8B8[0] + lbl_8042F8B8[1];
        endpoint = lbl_8042F8B8[2];
        denominator = denominator - lbl_8042F8B8[0];
        ratio = numerator / denominator;
        if (value < ratio) value = ratio;
        if (value > lbl_80561478) value = lbl_80561478;
        lbl_8042F8A8[2] = lbl_80561474 + value * (endpoint - lbl_80561474);
    } else {
        lbl_8042F8A8[2] = lbl_80561474;
    }
}
#pragma cplusplus reset

void fn_8013BAE4(int arg0) {
    float sp10[12];
    int spC;
    float sp8;
    volatile float *p;
    register float x;
    float v;
    int index;
    int i;
    int n;

    *((unsigned char*)lbl_8042F8A8 + 4) = 0;
    fn_8013B7B4(sp10, arg0);
    index = *(int*)((char*)fn_801E87A8() + 0xC);
    fn_8013B6C0(&spC, &sp8, index);
    p = (volatile float*)(sp10 + spC * 4);
    x = sp8;
    lbl_8042F8B8[0] = p[0] + x * (p[4] - p[0]);
    lbl_8042F8B8[1] = p[1] + x * (p[5] - p[1]);
    lbl_8042F8B8[2] = p[2] + x * (p[6] - p[2]);
    v = p[3] + x * (p[7] - p[3]);
    lbl_8042F8B8[3] = v;
    if ((float)v < lbl_80561478) v = (float)v - lbl_8056147C;
    else v = lbl_8056147C + (float)v;
    i = (int)v;
    n = 1;
    if (i > 1) n = i;
    i = arg0 - 1;
    if (n < i) i = n;
    lbl_8055E170 = i;
    if (lbl_8042F8B8[2] < lbl_80561474) lbl_8042F8B8[2] = lbl_80561474;
}

void fn_8013BC34(void) {
    *(float *)((char *)lbl_8042F8A8 + 8) = lbl_80561474;
    lbl_8055E174 = 0;
    *((u8 *)lbl_8042F8A8 + 4) = 0;
}

void fn_8013BC54(void) {
    lbl_8055E174++;
    if ((lbl_8055E174 & 7) == 0) {
        fn_8013B950();
    }
}

u8 fn_8013BC70(float *arg0) {
    *arg0 = lbl_8042F8A8[0];
    return *((u8 *)lbl_8042F8A8 + 4);
}
