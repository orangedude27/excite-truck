extern int lbl_8055F7A4;
extern void *lbl_8055F7A8;
extern int lbl_8055F7AC;
extern const char lbl_803493F8[];
extern void fn_80297A80(void);
extern void *fn_8012850C(int, const char *);
extern void *fn_8002F37C(void (*)(void), int, int, int);
extern int lbl_804B4F10[];
void fn_80297998(void);
extern unsigned char lbl_8055F7B4;
extern void *lbl_8055CA60;
extern const char lbl_803493D8[];
extern int fn_802C9C8C(void *);
extern void fn_802C7ADC(int);
extern void *fn_801E87A8(void);
extern void fn_802979A4(void);
extern void fn_80297AFC(void);
extern void fn_802C9CE0(void);
extern void fn_802E30C8(void *, ...);

#define gStaticShadowRecords lbl_8055F7A8 /* the "static shadows" heap block */
#define gStaticShadowCount   lbl_8055F7AC /* entries in use, of the 0x80 allocated */
#define Model_releaseInstance fn_802C6CF8 /* mrmodel: drop one model instance */
#define Mem_freeArray        fn_80128670  /* free a block fn_8012850C allocated */

/* One entry of the static-shadow list (fn_80297C3C appends, fn_80297AFC draws,
 * fn_80297A84 releases): the mrmodel instance made from the caller's model, the
 * group mask and 4x3 matrix (3x3 rotation, then the world position at +0x2C)
 * it is drawn with, and the two floats of the per-frame cull. */
typedef struct StaticShadow {
    void *model;       /* +0x00 mrmodel instance; fn_802C6CF8 releases it */
    int groupMask;     /* +0x04 which of the instance's groups to draw */
    float matrix[12];  /* +0x08 rotation at +0x00, position at +0x2C */
    float fade;        /* +0x38 value used when the camera is out of range */
    float range;       /* +0x3C cull radius, stretched by the truck's speed */
} StaticShadow;

typedef struct Obj Obj;
typedef void (*ObjMethod)(Obj *);
typedef struct {
    ObjMethod slots[8];
} ObjVtable;
struct Obj {
    ObjVtable *vtable;
};

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F7B0;
void fn_80297A84(void);
extern void fn_80297A30(void);
void fn_802978B8(void) {
    fn_80297998();
    fn_80297A30();
    lbl_8055F7B0 = (void*)0x50000000;
}

void fn_802978E4(void) {
    fn_80297A84();
    lbl_8055F7A4 = 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_8029790C(void) {
    if (fn_802C9C8C(lbl_8055F7B0)) {
        fn_802C7ADC((*(unsigned int *)((char *)fn_801E87A8() + 0x10) >> 1) & 1);
        fn_80297AFC();
        fn_802979A4();
        fn_802C9CE0();
    } else if (lbl_8055F7B4 == 0) {
        lbl_8055F7B4 = 1;
        fn_802E30C8(&lbl_8055CA60, lbl_803493D8);
    }
}
#pragma pop
void fn_80297980(void) {
}

void fn_80297984(void) {
}

void fn_80297A08();
void fn_80297C3C(void *, void *, int, float, float);
void fn_80297988(void) {
    fn_80297A08();
}

void fn_8029798C(void *unused, void *arg1, int arg2, float farg0, float farg1) {
    fn_80297C3C(unused, arg1, arg2, farg0, farg1);
}

void fn_80297990(void* hi) {
    lbl_8055F7B0 = hi;
}


    
void fn_80297998(void) {
    lbl_8055F7A4 = 0;
}

#pragma cplusplus on
extern "C" void fn_802979A4(void) {
    class Dummy_802979A4 {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void m4();
        virtual void m5();
    };
    int i;

    for (i = 0; i < lbl_8055F7A4; i++) {
        Dummy_802979A4 *obj = ((Dummy_802979A4 **)(void *)lbl_804B4F10)[i];
        obj->m5();
    }
}
#pragma cplusplus off
void fn_80297A08(int arg0) {
    int index = lbl_8055F7A4;
    if (index >= 0x40) return;
    lbl_804B4F10[index] = arg0;
    lbl_8055F7A4 = index + 1;
}

#pragma scheduling invalid_target
void fn_80297A30(void) {
    lbl_8055F7A8 = ((void *(*)(void *, void (*)(void), int, int, int))fn_8002F37C)(fn_8012850C(0x2010, lbl_803493F8), fn_80297A80, 0, 0x40, 0x80);
    lbl_8055F7AC = 0;
}
#pragma scheduling on
extern void *lbl_8055F7A8;
extern int lbl_8055F7AC;
extern const char lbl_803493F8[];
extern void fn_80128670(void *);
extern void fn_802C6CF8(void *);
extern void *fn_8012850C(int, const char *);
extern void *fn_8002F37C(void (*)(void), int, int, int);
void fn_80297A80(void) {}

/* Release every static shadow's model instance, hand the "static shadows" block
   back to the heap and leave the list empty. */
void fn_80297A84(void) {
    int offset = 0;
    int i = 0;
    goto test;
loop:
    Model_releaseInstance(((StaticShadow *)((char *)gStaticShadowRecords + offset))->model);
    offset += sizeof(StaticShadow);
    i++;
test:
    if (i < gStaticShadowCount)
        goto loop;
    if (gStaticShadowRecords != 0)
        Mem_freeArray((char *)gStaticShadowRecords - 0x10);
    gStaticShadowRecords = 0;
    gStaticShadowCount = 0;
}

extern void *fn_802C86DC(void);
extern float fn_801E88F0(int);
extern double fn_8002F234(void);
extern float PSVECSquareDistance(void *, void *);
extern void fn_802C7AE0(int, void *, int);
extern float lbl_80564580;
extern float lbl_80564584;
extern float lbl_80564588;
extern char lbl_80558DC4[];
#pragma paired_single off
extern double __fabs(double);
#pragma push
#pragma processor 750
void fn_80297AFC(void) {
    int cameraPosition[3];
    void *camera;
    int offset;
    int i;
    char *record;
    float speed;
    float minimum;
    float maximum;
    float divisor;
    float value;

    camera = fn_802C86DC();
    cameraPosition[0] = *(int *)((char *)camera + 0x24);
    i = 0;
    cameraPosition[1] = *(int *)((char *)camera + 0x28);
    offset = 0;
    maximum = lbl_80564584;
    minimum = lbl_80564580;
    divisor = lbl_80564588;
    cameraPosition[2] = *(int *)((char *)camera + 0x2C);

    for (; i < lbl_8055F7AC; offset += 0x40, i++) {
        float cur;
        float tmp;
        record = (char *)lbl_8055F7A8 + offset;
        speed = fn_801E88F0(-1);
        speed = speed * speed;
        if (PSVECSquareDistance(cameraPosition, record + 0x2C) * speed >
            *(float *)(record + 0x3C) * *(float *)(record + 0x3C)) {
            tmp = (float)fn_8002F234();
            cur = *(float *)(record + 0x38);
            value = tmp - *(float *)(record + 0x3C);
            value = (value - maximum) / divisor;
            if (value < minimum) {
                value = minimum;
            }
            if (value > maximum) {
                value = maximum;
            }
            value = cur + value * (maximum - cur);
        } else {
            value = *(float *)(record + 0x38);
        }

        if (!((float)__fabs((double)value) <= *(float *)lbl_80558DC4)) {
            fn_802C7AE0(*(int *)record, record + 8, *(int *)(record + 4));
        }
    }
}
#pragma pop
extern void *fn_802C6FC0(void *, int, int);
void fn_80297C3C(void *unused, void *arg1, int arg2, float farg0, float farg1) {
    register int count;
    register unsigned int *record;
    register unsigned int *source;
    register unsigned int temp_r0;
    register unsigned int temp_r3;
    count = lbl_8055F7AC;
    if (count >= 0x80)
        return;
    record = (unsigned int *)lbl_8055F7A8 + count * 0x10;
    source = (unsigned int *)arg1;
    record[0] = (unsigned int)fn_802C6FC0(unused, 0, 0);
    temp_r3 = source[0];
    record[1] = (unsigned int)arg2;
    temp_r0 = source[1];
    record[2] = temp_r3;
    temp_r3 = source[2];
    record[3] = temp_r0;
    temp_r0 = source[3];
    record[4] = temp_r3;
    temp_r3 = source[4];
    record[5] = temp_r0;
    temp_r0 = source[5];
    record[6] = temp_r3;
    temp_r3 = source[6];
    record[7] = temp_r0;
    temp_r0 = source[7];
    record[8] = temp_r3;
    temp_r3 = source[8];
    record[9] = temp_r0;
    temp_r0 = source[9];
    record[10] = temp_r3;
    temp_r3 = source[10];
    record[11] = temp_r0;
    temp_r0 = source[11];
    record[13] = temp_r0;
    record[12] = temp_r3;
    *(float *)&record[14] = farg0;
    *(float *)&record[15] = farg1;
    lbl_8055F7AC += 1;
}

