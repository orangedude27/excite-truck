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
extern void Abend_Panic(const char *);
extern int stricmp(const char *, const char *);
extern char lbl_8032C390[];
extern const char *lbl_802F9388[];
extern char lbl_80559CD8;
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single off
#pragma processor 750
#pragma use_lmw_stmw off
#pragma readonly_strings off
#pragma pool_strings off
/* Fill a 3x4 catch-up-assist parameter table from catchup.val: one row each for Easy, Medium and Hard. */
extern "C" void fn_8013B7B4(float *catchupParams, int carCount) {
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
    const char **diffName;
    float *dest;
    void *catchupList;
    void *entry;
    int entryIndex;
    const char *sectionName;
    unsigned int diffIndex;
    catchupList = fn_80131808((void *)"catchup.val");
    if (catchupList == 0) goto error;
    entryIndex = 0;
    while ((entry = ((List *)catchupList)->getAt(entryIndex)) != 0) {
        sectionName = ((Item *)entry)->getName();
        const char *difficultyNames[3] = { "Easy", "Medium", "Hard" };
        dest = catchupParams;
        for (diffIndex = 0, diffName = difficultyNames; diffIndex < 3; diffIndex++, diffName++, dest += 4) {
            if (stricmp(*diffName, sectionName) == 0) {
                dest[0] = ((DataItem *)entry)->getFloat("begin_t");
                dest[1] = ((DataItem *)entry)->getFloat("effect_t");
                dest[2] = ((DataItem *)entry)->getFloat("speed_factor");
                dest[3] = (float)carCount * ((DataItem *)entry)->getFloat("compare_car_pct");
            }
        }
        entryIndex++;
    }
    fn_80131818(catchupList);
    return;
error:
    ((void (*)(const char *, ...))Abend_Panic)("no catchup.val?");
}
#pragma pop

#pragma cplusplus on
extern "C" int fn_80179630(int);
extern "C" int getDeitySlotCount(void);
extern "C" int fn_801B2F40(int);
extern "C" void *fn_801B2ED0(int);
extern "C" double fn_801B2F90(int, int);
extern "C" u8 fn_8013BC70(float *);
extern "C" void fn_8013B950(void);
extern float lbl_80561470;
#pragma scheduling invalid_target
void fn_8013B950(void) {
    struct Dummy {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void *get() = 0;
    };
    float sp8;
    int selected;
    void *bestItem;
    int remaining;
    int index;
    int bestIndex;
    double score;
    register float rounded;

    *((volatile u8 *)lbl_8042F8A8 + 4) = 0;
    selected = fn_80179630(0);
    if (selected >= 0) {
        remaining = lbl_8055E170;
        bestItem = 0;
        bestIndex = -1;
        index = getDeitySlotCount() - 1;
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
                rounded = (float)score;
                *(float *)lbl_8042F8A8 = score;
                *(int *)((char *)lbl_8042F8A8 + 0xc) = bestIndex;
                *((u8 *)lbl_8042F8A8 + 4) = (rounded < lbl_80561470);
            }
        }
    }
    if (((int (*)(float *))fn_8013BC70)(&sp8) != 0) {
        float numerator;
        float base;
        float endpoint;
        float ratio;
        float denominator;
        float value;
        base = lbl_8042F8B8[0];
        numerator = sp8 - base;
        value = lbl_80561474;
        denominator = (base + lbl_8042F8B8[1]) - base;
        endpoint = lbl_8042F8B8[2];
        ratio = numerator / denominator;
        value = (value < ratio) ? value : ratio;
        value = (value > lbl_80561478) ? value : lbl_80561478;
        lbl_8042F8A8[2] = lbl_80561474 + value * (endpoint - lbl_80561474);
    } else {
        lbl_8042F8A8[2] = lbl_80561474;
    }
}
#pragma cplusplus reset

#pragma scheduling invalid_target
void fn_8013BAE4(int arg0) {
    float sp10[12];
    int spC;
    float sp8;
    volatile float *p;
    float t0, t1, t2, t3;
    float vf;
    double v;
    int index;
    int i;
    int n;
    *((unsigned char*)lbl_8042F8A8 + 4) = 0;
    fn_8013B7B4(sp10, arg0);
    index = *(int*)((char*)fn_801E87A8() + 0xC);
    fn_8013B6C0(&spC, &sp8, index);
    p = (volatile float *)(sp10 + spC * 4);
    t0 = p[0];
    *(volatile float*)&lbl_8042F8B8[0] = t0 + sp8 * (p[4] - t0);
    t1 = p[1];
    *(volatile float*)&lbl_8042F8B8[1] = t1 + sp8 * (p[5] - t1);
    t2 = p[2];
    *(volatile float*)&lbl_8042F8B8[2] = t2 + sp8 * (p[6] - t2);
    t3 = p[3];
    v = t3 + sp8 * (p[7] - t3);
    vf = (float)v;
    *(volatile float*)&lbl_8042F8B8[3] = (float)v;
    if (vf < lbl_80561478) v = vf - lbl_8056147C;
    else v = lbl_8056147C + vf;
    i = (int)v;
    n = 1;
    if (i > 1) n = i;
    i = arg0 - 1;
    if (n < i) i = n;
    lbl_8055E170 = i;
    lbl_8042F8B8[2] = (lbl_8042F8B8[2] < lbl_80561474) ? lbl_8042F8B8[2] : lbl_80561474;
}
#pragma scheduling on
/* Reset the shared status record: set the value at +0x08 to its default of 1.0,
 * clear the periodic-update counter, and clear the flag byte at +0x04. */
void fn_8013BC34(void) {
    *(float *)((char *)lbl_8042F8A8 + 8) = lbl_80561474;
    lbl_8055E174 = 0;
    *((u8 *)lbl_8042F8A8 + 4) = 0;
}

#define sPeriodicUpdateCounter lbl_8055E174

/* Increments the periodic-update tick counter and refreshes the shared status
   record every 8 ticks. */
void fn_8013BC54(void) {
    sPeriodicUpdateCounter++;
    if ((sPeriodicUpdateCounter & 7) == 0) {
        fn_8013B950();
    }
}

/* Copies the stored score (record +0x0) into *outScore and returns the flag
 * byte at +0x4, which records whether that score fell below the threshold. */
u8 fn_8013BC70(float *outScore) {
    *outScore = lbl_8042F8A8[0];
    return *((u8 *)lbl_8042F8A8 + 4);
}
