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
/* Initialize the static-shadow module: clear the listener list, allocate the shadow record array, and seed the shadow-volume handle with its sentinel. */
void fn_802978B8(void) {
#define shadowVolumeHandle lbl_8055F7B0
    fn_80297998();
    fn_80297A30();
    shadowVolumeHandle = (void*)0x50000000;
#undef shadowVolumeHandle
}

#define gListenerCount lbl_8055F7A4 /* number of registered shadow listeners */
void fn_802978E4(void) {
    /* Shut down the static-shadow module: release its shadows and clear the listener count. */
    fn_80297A84();
    gListenerCount = 0;
}
#undef gListenerCount

#pragma push
#pragma scheduling invalid_target
/* If the shadow volume handle is ready, apply the current camera flag, draw shadow volumes and notify listeners, then finalize; otherwise log a failure once. */
void fn_8029790C(void) {
#define shadowVolumeHandle      lbl_8055F7B0
#define shadowVolumeFailLogged  lbl_8055F7B4
#define printfFormatString      lbl_8055CA60
#define shadowVolumeFailMessage lbl_803493D8
    if (fn_802C9C8C(shadowVolumeHandle)) {
        fn_802C7ADC((*(unsigned int *)((char *)fn_801E87A8() + 0x10) >> 1) & 1);
        fn_80297AFC();
        fn_802979A4();
        fn_802C9CE0();
    } else if (shadowVolumeFailLogged == 0) {
        shadowVolumeFailLogged = 1;
        fn_802E30C8(&printfFormatString, shadowVolumeFailMessage);
    }
#undef shadowVolumeFailMessage
#undef printfFormatString
#undef shadowVolumeFailLogged
#undef shadowVolumeHandle
}
#pragma pop
/* Intentionally empty no-op; placeholder hook in the static-shadow lifecycle sequence. */
void fn_80297980(void) {
}

/* Empty no-op hook called by the per-frame shutdown pass (fn_801E8CE4);
 * the static-shadow module has no per-frame teardown work to do. */
void fn_80297984(void) {
}

void fn_80297A08();
void fn_80297C3C(void *, void *, int, float, float);
/* Public entry point for registering a static-shadow listener: tail-calls the
 * internal list-appender (fn_80297A08), passing the caller's object pointer through. */
void fn_80297988(void) {
    fn_80297A08();
}

/* Thin wrapper that forwards a static-shadow registration to fn_80297C3C:
 * the model instance, its 3x3 matrix, group mask, fade and cull radius. */
void fn_8029798C(void *modelSource, void *sourceMatrix, int groupMask, float fade, float cullRange) {
    fn_80297C3C(modelSource, sourceMatrix, groupMask, fade, cullRange);
}

/* Set the static-shadow module's shadow-volume handle (0x50000000 sentinel at init, 0 to clear). */
void fn_80297990(void* shadowVolumeHandle) {
    lbl_8055F7B0 = shadowVolumeHandle;
}


    
void fn_80297998(void) {
    /* Clear the shadow-listener list by resetting the registered-listener count to zero. */
#define gListenerCount lbl_8055F7A4
    gListenerCount = 0;
#undef gListenerCount
}

#pragma cplusplus on
/* Calls virtual method 5 on each registered object in the listener list. */
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
    int index;

    for (index = 0; index < lbl_8055F7A4; index++) {
        Dummy_802979A4 *listener = ((Dummy_802979A4 **)(void *)lbl_804B4F10)[index];
        listener->m5();
    }
}
#pragma cplusplus off
#define gListenerCount lbl_8055F7A4 /* number of registered shadow listeners */
#define gListenerList  lbl_804B4F10 /* array of registered listener pointers */
/* Register a shadow listener: append its pointer to the bounded listener list (max 0x40 entries). */
void fn_80297A08(int listener) {
    int index = gListenerCount;
    if (index >= 0x40) return;
    gListenerList[index] = listener;
    gListenerCount = index + 1;
}

#pragma scheduling invalid_target
/* Allocate the static-shadow record array (0x80 entries of 0x40 bytes) and clear the count. */
void fn_80297A30(void) {
    gStaticShadowRecords = ((void *(*)(void *, void (*)(void), int, int, int))fn_8002F37C)(fn_8012850C(0x2010, lbl_803493F8), fn_80297A80, 0, 0x40, 0x80);
    gStaticShadowCount = 0;
}
#pragma scheduling on
extern void *lbl_8055F7A8;
extern int lbl_8055F7AC;
extern const char lbl_803493F8[];
extern void fn_80128670(void *);
extern void fn_802C6CF8(void *);
extern void *fn_8012850C(int, const char *);
extern void *fn_8002F37C(void (*)(void), int, int, int);
/* No-op element-initializer callback for the static-shadow record array: passed
 * to fn_8002F37C when that table is created; records need no per-element setup. */
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

extern void *DrawList_getCurrentMatrix(void);
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
    float maximum;
    float minimum;
    float divisor;
    float value;

    camera = DrawList_getCurrentMatrix();
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
/* Appends a static shadow record (model instance, group mask, transform, fade, and cull
 * range) to the global list by copying the transform from sourceMatrix; does nothing if
 * the list is full. */
void fn_80297C3C(void *modelSource, void *sourceMatrix, int groupMask, float fade, float cullRange) {
    unsigned int nextWord = 0;
    int count;
    unsigned int *record;
    unsigned int *source;
    unsigned int word;

    count = gStaticShadowCount;
    if (0x80 <= count)
        return;

    record = (unsigned int *)gStaticShadowRecords + count * 0x10;
    source = (unsigned int *)sourceMatrix;
    record[0] = (unsigned int)fn_802C6FC0(modelSource, 0, 0);
    word = source[0];
    record[1] = (unsigned int)groupMask;
    nextWord = source[1];
    record[2] = word;
    word = source[2];
    record[3] = nextWord;
    nextWord = source[3];
    record[4] = word;
    word = source[4];
    record[5] = nextWord;
    nextWord = source[5];
    record[6] = word;
    word = source[6];
    record[7] = nextWord;
    nextWord = source[7];
    record[8] = word;
    word = source[8];
    record[9] = nextWord;
    nextWord = source[9];
    record[10] = word;
    word = source[10];
    record[11] = nextWord;
    nextWord = source[11];
    record[12] = word;
    record[13] = nextWord;
    *(float *)&record[14] = fade;
    *(float *)&record[15] = cullRange;
    gStaticShadowCount += 1;
}

