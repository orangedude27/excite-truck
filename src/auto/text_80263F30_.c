// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).



extern int fn_8023695C(void *);
extern void fn_80216CA8(void);
extern void fn_802168BC(int);
extern float fn_80235F64(void *, int);
extern float fn_80235EF0(void *, int);
extern void fn_80235AFC(void *, int, unsigned int, float, float, float, float, float, float);
typedef struct SparkParticle {
    float x, y, vx, vy, a10, a14, life;
    int id;
} SparkParticle;
typedef struct SparkList {
    char pad0[0x2c];
    float gx, gy;
    char pad1[0x58 - 0x34];
    SparkParticle *items;
    int count;
} SparkList;
extern float fn_80214D48(void);
extern float lbl_80558DC4[];
static inline void fn_80264D5C_update(SparkList *l, float dt) {
    int i = 0;
    while (i < l->count) {
        SparkParticle *p = &l->items[i];
        p->life -= dt;
        if (p->life < lbl_80558DC4[0]) {
            int count = l->count;
            if (i >= 0 && i < count) {
                if (i != count - 1) {
                    *p = l->items[count - 1];
                }
                l->count = count - 1;
            }
        } else {
            i++;
            p->x += (p->vx += l->gx * dt) * dt;
            p->y += (p->vy += l->gy * dt) * dt;
            p->a10 += p->a14 * dt;
        }
    }
}
extern float lbl_80563C00;
extern float lbl_80563BF0;
extern float lbl_80563BF8, lbl_80563C18, lbl_80563C1C;
extern void fn_8022ACFC(int, void *, float *, float *, float *, float *, float, float);
extern int fn_8022AA84(int);
extern void fn_8022BD40(int, void *, int, int, float, float, float, float, float, float);
extern int fn_80265B5C(void);
extern void fn_80216D28(void);
extern void *lbl_8055F444;
extern void *lbl_8055F448;
extern void fn_80235380(void *);
extern void fn_80128670(void *);
extern void *lbl_8055C458;
extern void fn_80236914(void);
extern void fn_80264098(void *, int);
extern void *fn_80264A54(void);
extern void *fn_80264580(void);
#pragma push
#pragma cplusplus on
struct PropertyReader802640C4 {
    virtual ~PropertyReader802640C4();
    virtual void slot0C();
    virtual void slot10();
    virtual char *getString(const char *);
    virtual void slot18();
    virtual int getInt(const char *);
    virtual void slot20();
    virtual void slot24();
    virtual float getFloat(const char *, float);
};
#pragma pop

/* lbl_80346338 is the credits module's string/descriptor table (.data):
 *   +0x000 "credits.bik"  - the credits movie; lbl_8055C450 is a char* pointing at it
 *   +0x02C a 15-word float descriptor (the symbol lbl_80346364, copied by fn_802646D0)
 *   +0x068 "credits.val"   - the value table holding the credits page
 *   +0x074 "credits: failed to push my movie (%s) onto the stack!"
 *   +0x0AC "credits_page"  - the .val entry fn_80263F30 looks for
 *   +0x0C0 "credits: failed to pop my movie from the stack!"
 *   +0x0F0 "firetext",  +0x0FC "TextWoot"    - item types fn_802640C4 builds
 *   +0x108 "extra_delay", +0x114 "ExtraDelay"
 *   +0x120 "allow_keys",  +0x12C "KeyEnabler"
 *   +0x138 "ValTable_UIDialogMapping: can't handle item type '%s'"
 */
enum {
    CREDITS_VAL_NAME = 0x68,      /* "credits.val" */
    CREDITS_PAGE_NAME = 0xAC,     /* "credits_page" */
    CREDITS_PUSH_FAIL_MSG = 0x74, /* "credits: failed to push my movie (%s) onto the stack!" */
    CREDITS_POP_FAIL_MSG = 0xC0   /* "credits: failed to pop my movie from the stack!" */
};

extern char lbl_80346338[];      /* credits string table, see above */
extern int lbl_8055C450;         /* char *creditsMovieName -> "credits.bik" */
extern unsigned char lbl_8055F450; /* set while the credits may be skipped (read by fn_80265B5C) */

extern int fn_8020A69C(void);
extern void fn_8020A648(int);
extern void fn_80265A74(void);
extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern int fn_802ECF00(int);
extern int fn_802ECF04(void);
extern void fn_802E317C(const char *, ...);
extern void fn_80265940(void);
extern void *fn_802646D0(void *);
extern void fn_8026451C(void *);
extern int stricmp(const char *, const char *);
extern int fn_802656C8(void *);
extern int fn_80264538(int, int);
extern void *fn_80264968(void *, int);

#pragma use_lmw_stmw off
#pragma dont_inline off
#pragma cplusplus on
/* Starts the credits sequence.
 *
 * Pushes the credits movie (lbl_8055C450 -> "credits.bik") onto the movie stack, opens the
 * "credits.val" table and hands the entry named "credits_page" to fn_802656C8, which builds
 * the credits_page_items list and posts the request that shows them, then pops the movie
 * again.  The music song is switched to 1 for the walk and restored at the end; fadeOut and
 * fadeIn ask for the screen fade before and after it (fn_80265A74 = "fade_out",
 * fn_80265940 = "fade_in"), and skip is the flag fn_80265B5C reports the credits as
 * finished on.  Returns nothing; does nothing at all if credits.val is missing.
 */
extern "C" void fn_80263F30(int fadeOut, unsigned char skip, int fadeIn) {
    struct ValEntry { virtual const char *getName(); };             /* .val item, vtable+0x8 = getName */
    struct ValList { virtual void f0(); virtual void *get(int); };  /* .val list, vtable+0xC = get(index) */
    char timerObj[0x28];  /* sp8:  fade/timer object, vtable lbl_803466D8 */
    char pageObj[0xE0];   /* sp30: credits page object, vtable lbl_80346678 */
    register const char *base asm("r31") = lbl_80346338;
    register int prevSong asm("r30");
    register void *valList asm("r29");
    register void *entry asm("r28");
    register int keepGoing asm("r27");
    register int fadeOutOrIndex asm("r26") = fadeOut; /* the .val walk index takes over below */
    register int r_fadeIn asm("r25") = fadeIn;
    lbl_8055F450 = skip;
    prevSong = fn_8020A69C();
    fn_8020A648(1);
    if (fadeOutOrIndex != 0) {
        fn_80265A74();
    }
    valList = fn_80131810((void *)(base + CREDITS_VAL_NAME));
    if (valList != 0) {
        if (fn_802ECF00(lbl_8055C450) == 0) {
            fn_802E317C(base + CREDITS_PUSH_FAIL_MSG, lbl_8055C450);
        }
        fn_80265940();
        fn_802646D0(pageObj);
        fn_8026451C(timerObj);
        keepGoing = 1;
        fadeOutOrIndex = 0;
        while (keepGoing != 0 && (entry = ((ValList *)valList)->get(fadeOutOrIndex)) != 0) {
            if (stricmp(((ValEntry *)entry)->getName(), base + CREDITS_PAGE_NAME) == 0) {
                keepGoing = fn_802656C8(entry);
            }
            fadeOutOrIndex++;
        }
        fn_8020A648(-1);
        fn_80265A74();
        if (fn_802ECF04() == 0) {
            fn_802E317C(base + CREDITS_POP_FAIL_MSG);
        }
        fn_80131818(valList);
        fn_80264538((int)timerObj, -1);
        fn_80264968(pageObj, -1);
    }
    if (r_fadeIn != 0) {
        fn_80265940();
    }
    fn_8020A648(prevSong);
}
#pragma cplusplus off
#pragma use_lmw_stmw on
#pragma dont_inline on

void fn_80264098(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 4) = arg1;
}
#pragma dont_inline off

#pragma dont_inline on
#pragma dont_inline off
void fn_802640A0(void *arg0) {
    *(int *)((char *)arg0 + 8) = 0;
    *(void **)arg0 = lbl_8055C458;
    *(int *)((char *)arg0 + 4) = 0x7b;
    *(int *)((char *)arg0 + 0xc) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802640C4(void *arg0, void *arg1) {
    extern char lbl_8055C45C[4], lbl_8055C464[4], lbl_8055C46C[4], lbl_8055C474[4], lbl_8055C47C[4], lbl_8055C484[4];
    extern unsigned char lbl_80498F78[];
    extern void *fn_801284F8(unsigned int, void *);
    extern void fn_8026523C(void *), fn_80265558(void *), fn_802655A4(void *);
    extern void fn_80265268(void *, int, char *, float), fn_8026557C(void *, float), fn_80265610(void *, float);
    char *base=lbl_80346338;
    char *kind;
    PropertyReader802640C4 *properties = (PropertyReader802640C4 *)arg1;
    void *obj;
    int count;
    void **items;
    char *name;
    int val;
    float value;
    kind = properties->getString(lbl_8055C45C);
    if (stricmp(kind,lbl_8055C464)==0) {
        *(char **)arg0=properties->getString(lbl_8055C46C);
        fn_80264098(arg0,3);
        *(char **)((char *)arg0+8)=properties->getString(lbl_8055C474);
        *(int *)((char *)arg0+12)=0;
    } else if (stricmp(kind,base+0xf0)==0) {
        obj=fn_801284F8(0xbc,base+0xfc);
        if (obj) obj=((void *(*)(void *))fn_8026523C)(obj);
        value=properties->getFloat(lbl_8055C484,lbl_80563BF0);
        name=properties->getString(lbl_8055C474);
        val=properties->getInt(lbl_8055C47C);
        fn_80265268(obj,val,name,value);
        items=*(void ***)lbl_80498F78;
        count=(*(int *)(lbl_80498F78+4))++;
        items[count]=obj;
        *(char **)arg0=properties->getString(lbl_8055C46C);
        fn_80264098(arg0,5);
        *(void **)((char *)arg0+8)=obj;
    } else if (stricmp(kind,base+0x108)==0) {
        kind=(char *)fn_801284F8(0x20,base+0x114);
        if(kind) kind=(char *)((void *(*)(void *))fn_80265558)(kind);
        value=properties->getFloat(lbl_8055C484,lbl_80563BF0);
        fn_8026557C(kind,value);
        items=*(void ***)lbl_80498F78;
        count=(*(int *)(lbl_80498F78+4))++;
        items[count]=kind;
        *(int *)arg0=0;
        fn_80264098(arg0,5);
        *(void **)((char *)arg0+8)=kind;
    } else if (stricmp(kind,base+0x120)==0) {
        kind=(char *)fn_801284F8(0x24,base+0x12c);
        if(kind) kind=(char *)((void *(*)(void *))fn_802655A4)(kind);
        value=properties->getFloat(lbl_8055C484,lbl_80563BF0);
        fn_80265610(kind,value);
        items=*(void ***)lbl_80498F78;
        count=(*(int *)(lbl_80498F78+4))++;
        items[count]=kind;
        *(int *)arg0=0;
        fn_80264098(arg0,5);
        *(void **)((char *)arg0+8)=kind;
    } else {
        fn_802E317C(base+0x138,kind);
    }
}
#pragma pop

#pragma scheduling invalid_target
void fn_802643B8(void *arg0) {
    *(void **)arg0 = &lbl_8055C458;
    fn_80264098(arg0, 8);
    *(void (**)(void))((char *)arg0 + 8) = fn_80236914;
    *(int *)((char *)arg0 + 0xc) = 2;
}
#pragma scheduling on
void fn_80264404(void *arg0) {
    *(void **)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = fn_80264A54();
}

void fn_80264444(void *arg0) {
    *(void **)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = fn_80264580();
}

void fn_80264484(void *arg0) {
    extern void *fn_801284F8(unsigned int, void *);
    extern char lbl_803464A8[];
    extern char lbl_803464F8[];
    extern unsigned char lbl_80498F78[];
    void *result;
    int count;
    void **items;
    result = fn_801284F8(24, lbl_803464A8);
    if (result != 0) {
        *(int *)((char *)result + 20) = 0;
        *(void **)result = lbl_803464F8;
    }
    count = *(int *)(lbl_80498F78 + 4);
    items = *(void ***)(lbl_80498F78 + 0);
    *(int *)(lbl_80498F78 + 4) = count + 1;
    items[count] = result;
    *(int *)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = result;
}

#pragma scheduling invalid_target
void fn_8026451C(void *arg0) {
    extern char lbl_803466D8[];
    *(void **)arg0 = lbl_803466D8;
    *(int *)((char *)arg0 + 0x14) = 0;
    lbl_8055F444 = arg0;
}
#pragma scheduling on
int fn_80264538(int arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055F444 = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void* fn_80264580(void) {
    return lbl_8055F444;
}

#pragma dont_inline on
float fn_80264588(void) {
    extern int fn_802645C0(void);
    extern float lbl_80563BF4;
    if (fn_802645C0() != 0) {
        return *(float *)((char *)lbl_8055F444 + 0x20);
    }
    return lbl_80563BF4;
}

int fn_802645C0(void) {
    extern float lbl_80558DC4[];
    float v = *(float *)((char *)lbl_8055F444 + 0x18);
    double abs = __fabs((double)v);
    return (float)abs <= lbl_80558DC4[0];
}

void fn_802645EC(void) {
    extern float lbl_8055C454;
    *(float *)((char *)lbl_8055F444 + 0x1C) = lbl_8055C454;
}
#pragma dont_inline off

#pragma scheduling invalid_target
void fn_802645FC(void *arg0) {
    extern float lbl_80563BF8;
    extern float lbl_8055C454;
    extern float lbl_80563BF0;
    float b = lbl_80563BF0;
    float a = lbl_80563BF8;
    *(float *)((char *)arg0 + 0x18) = a;
    *(float *)((char *)arg0 + 0x1C) = lbl_8055C454;
    *(float *)((char *)arg0 + 0x20) = b;
}
#pragma dont_inline on
void fn_80264618(void *obj) {
    extern float lbl_80558DC4[];
    extern float lbl_80563BF0;
    extern float fn_80214D48(void);
    extern int fn_802645C0(void);
    extern void fn_80221F94(void *, int);
    extern void fn_80216CA8(void);
    float value;
    float clamped;
    float delta;
    float minValue;

    /* If the timer/counter at +0x1C has reached zero, clear state and run callback; then decay fields at +0x18,+0x20,+0x1C by frame delta down to min. */
    value = (float)__fabs((double)*(float *)((char *)obj + 0x1C));
    if (value <= lbl_80558DC4[0]) {
        fn_80221F94(obj, 0);
        fn_80216CA8();
    }
    value = fn_80214D48();
    clamped = *(float *)((char *)obj + 0x18);
    minValue = lbl_80563BF0;
    clamped = clamped - value;
    clamped = minValue > clamped ? minValue : clamped;
    *(float *)((char *)obj + 0x18) = clamped;
    if (fn_802645C0() != 0) {
        delta = fn_80214D48();
        clamped = *(float *)((char *)obj + 0x20);
        clamped = clamped + delta;
        *(float *)((char *)obj + 0x20) = clamped;
    }
    delta = fn_80214D48();
    clamped = *(float *)((char *)obj + 0x1C);
    minValue = lbl_80563BF0;
    clamped = clamped - delta;
    clamped = minValue > clamped ? minValue : clamped;
    *(float *)((char *)obj + 0x1C) = clamped;
}

#pragma push
#pragma use_lmw_stmw off
void *fn_802646D0(void *arg0) {
    extern int lbl_802FA700[], lbl_80346364[], lbl_80346678[];
    extern char lbl_8055C490[4];
    extern float lbl_80563BFC, lbl_80563C04;
    extern void *fn_8023512C(const char *);
    extern void *fn_8012850C(int, void *);
    struct Desc { int a[15]; };
    struct Desc desc = *(struct Desc *)lbl_802FA700;
    char *p = (char *)arg0;
    int n;
    void *data;
    float f;
    *(int *)(p+0x14) = 0;
    *(int **)(p+0) = lbl_80346678;
    *(int *)(p+0x18)=desc.a[0];
    *(int *)(p+0x1c)=desc.a[1];
    *(int *)(p+0x20)=desc.a[2];
    *(int *)(p+0x24)=desc.a[3];
    *(int *)(p+0x28)=desc.a[4];
    *(int *)(p+0x2c)=desc.a[5];
    *(int *)(p+0x30)=desc.a[6];
    *(int *)(p+0x34)=desc.a[7];
    *(int *)(p+0x38)=desc.a[8];
    *(int *)(p+0x3c)=desc.a[9];
    *(int *)(p+0x40)=desc.a[10];
    *(int *)(p+0x44)=desc.a[11];
    *(int *)(p+0x48)=desc.a[12];
    *(int *)(p+0x4c)=desc.a[13];
    *(int *)(p+0x50)=desc.a[14];
    *(void **)(p+0x54) = fn_8023512C((const char *)desc.a[0]);
    n = lbl_802FA700[9];
    data = fn_8012850C(n*32, lbl_8055C490);
    *(void **)(p+0x58)=data; *(int *)(p+0x60)=n; *(int *)(p+0x5c)=0; *(void **)(p+0x64)=data;
    f = *(float *)(p+0x44);
    f = f < lbl_80563BFC ? lbl_80563BFC : f;
    *(float *)(p+0x68)=lbl_80563C00/f;
    f = *(float *)(p+0x44);
    f = f < lbl_80563BFC ? lbl_80563BFC : f;
    *(float *)(p+0x6c)=lbl_80563C04/f;
    f = *(float *)(p+0x48);
    f = f < lbl_80563BFC ? lbl_80563BFC : f;
    *(int *)(p+0x5c)=0;
    *(float *)(p+0x74)=lbl_80563BF0;
    *(float *)(p+0x70)=lbl_80563C00/f;
    *(int *)(p+0x78) = ((int *)lbl_80346364)[0];
    *(int *)(p+0x7c) = ((int *)lbl_80346364)[1];
    *(int *)(p+0x80) = ((int *)lbl_80346364)[2];
    *(int *)(p+0x84) = ((int *)lbl_80346364)[3];
    *(int *)(p+0x88) = ((int *)lbl_80346364)[4];
    *(int *)(p+0x8c) = ((int *)lbl_80346364)[5];
    *(int *)(p+0x90) = ((int *)lbl_80346364)[6];
    *(int *)(p+0x94) = ((int *)lbl_80346364)[7];
    *(int *)(p+0x98) = ((int *)lbl_80346364)[8];
    *(int *)(p+0x9c) = ((int *)lbl_80346364)[9];
    *(int *)(p+0xa0) = ((int *)lbl_80346364)[10];
    *(int *)(p+0xa4) = ((int *)lbl_80346364)[11];
    *(int *)(p+0xa8) = ((int *)lbl_80346364)[12];
    *(int *)(p+0xac) = ((int *)lbl_80346364)[13];
    *(int *)(p+0xb0) = ((int *)lbl_80346364)[14];
    *(void **)(p+0xb4) = fn_8023512C((const char *)lbl_80346364[0]);
    n = lbl_80346364[9];
    data = fn_8012850C(n*32, lbl_8055C490);
    *(void **)(p+0xb8)=data; *(int *)(p+0xc0)=n; *(int *)(p+0xbc)=0; *(void **)(p+0xc4)=data;
    f=*(float *)(p+0xa4);
    f = f < lbl_80563BFC ? lbl_80563BFC : f;
    *(float *)(p+0xc8)=lbl_80563C00/f;
    f=*(float *)(p+0xa4);
    f = f < lbl_80563BFC ? lbl_80563BFC : f;
    *(float *)(p+0xcc)=lbl_80563C04/f;
    f=*(float *)(p+0xa8);
    f = f < lbl_80563BFC ? lbl_80563BFC : f;
    *(int *)(p+0xbc)=0;
    *(float *)(p+0xd4)=lbl_80563BF0;
    *(float *)(p+0xd0)=lbl_80563C00/f;
    lbl_8055F448=arg0;
    return arg0;
}
#pragma pop

#pragma dont_inline off
/* Destructor-like cleanup for the object at 0x802646D0: clears the current object pointer,
 * releases two owned sub-objects/buffers, and optionally frees the object itself. */
void *fn_80264968(void *obj, int freeFlag) {
    struct ObjectView {
        char pad_00[0x54];
        void *resource54;
        void *buffer58;
        void *bufferCount5C;
        void *bufferCapacity60;
        void *bufferStorage64;
        char pad_68[0x4C];
        void *resourceB4;
        void *bufferB8;
        void *bufferCountBC;
        void *bufferCapacityC0;
        void *bufferStorageC4;
    };
    struct ObjectView *self = (struct ObjectView *)obj;
    if (obj != 0) {
        lbl_8055F448 = 0;
        if ((char *)obj + 0x78 != 0) {
            if (self->resourceB4 != 0) {
                fn_80235380(self->resourceB4);
                self->resourceB4 = 0;
            }
            if (&self->bufferB8 != 0) {
                fn_80128670(self->bufferStorageC4);
                if (&self->bufferB8 != 0) {
                    self->bufferB8 = 0;
                    self->bufferCountBC = 0;
                    self->bufferCapacityC0 = 0;
                }
            }
        }
        if ((char *)obj + 0x18 != 0) {
            if (self->resource54 != 0) {
                fn_80235380(self->resource54);
                self->resource54 = 0;
            }
            if (&self->buffer58 != 0) {
                fn_80128670(self->bufferStorage64);
                if (&self->buffer58 != 0) {
                    self->buffer58 = 0;
                    self->bufferCount5C = 0;
                    self->bufferCapacity60 = 0;
                }
            }
        }
        if (freeFlag > 0) fn_80128668(obj);
    }
    return obj;
}

extern void *lbl_8055F448;
void* fn_80264A54(void) {
    return lbl_8055F448;
}

#pragma push
#pragma processor 750
void fn_80264A5C(float farg0, float farg1) {
    extern float lbl_80558DC4[];
    extern float lbl_80563BF0;
    
    extern float lbl_80563C08;
    extern float lbl_80563C0C;
    extern float fn_80214D48(void);
    extern void fn_80230C30(float *, float *, int, int);
    extern float fn_80129DC4(int, float, float);
    extern int fn_80129D18(int, int);
    extern int fn_80235FD8(int);
    extern double cos(double);
    extern double sin(double);
    volatile float sp1C;
    volatile float sp18;
    volatile float sp14;
    volatile float sp10;
    float spC;
    float sp8;
    float temp_f0;
    float temp_f0_2;
    float temp_f2;
    float temp_f30;
    float temp_f30_2;
    float temp_f31;
    float temp_f31_2;
    float temp_f3;
    float temp_f4;
    int temp_r0;
    int temp_r0_2;
    int temp_r4;
    int temp_r4_2;
    int temp_r5;
    int temp_r5_2;
    int temp_r6;
    int temp_r6_2;
    void *temp_r31;
    void *temp_r31_2;
    void *temp_r30;
    void *temp_r30_2;

    if (!((float)__fabs((double)fn_80214D48()) <= lbl_80558DC4[0])) {
        fn_80230C30(&spC, &sp8, (int)farg0, (int)farg1);
        temp_f4 = spC + (farg0 - (float)(int)farg0);
        temp_f3 = sp8 - (farg1 - (float)(int)farg1);
        spC = temp_f4;
        sp8 = temp_f3;
        sp18 = temp_f4;
        temp_r31 = lbl_8055F448;
        temp_f0 = 1.0f;
        temp_f0 = *(float *)((char *)temp_r31 + 0x74) + *(float *)((char *)temp_r31 + 0x40);
        sp1C = temp_f3;
        *(float *)((char *)temp_r31 + 0x74) = temp_f0;
        if (temp_f0 > 1.0f && *(int *)((char *)temp_r31 + 0x5C) + 1 <= *(int *)((char *)temp_r31 + 0x60)) {
            *(float *)((char *)temp_r31 + 0x74) = *(float *)((char *)temp_r31 + 0x74) - 1.0f;
            temp_r5 = *(int *)((char *)temp_r31 + 0x5C);
            temp_r6 = *(int *)((char *)temp_r31 + 0x58);
            temp_r4 = temp_r5 + 1;
            *(int *)((char *)temp_r31 + 0x5C) = temp_r4;
            temp_r0 = temp_r5 << 5;
            temp_r30 = (void *)((char *)temp_r6 + temp_r0);
            *(float *)((char *)temp_r6 + temp_r0) = temp_f4;
            *(float *)((char *)temp_r30 + 4) = temp_f3;
            temp_f30 = fn_80129DC4(6, *(float *)((char *)temp_r31 + 0x1C), *(float *)((char *)temp_r31 + 0x20));
            temp_f31 = fn_80129DC4(6, *(float *)((char *)temp_r31 + 0x24), *(float *)((char *)temp_r31 + 0x28));
            *(float *)((char *)temp_r30 + 8) = temp_f31 * (float)cos((double)temp_f30);
            *(float *)((char *)temp_r30 + 0xC) = temp_f31 * (float)sin((double)temp_f30);
            *(float *)((char *)temp_r30 + 0x10) = fn_80129DC4(6, lbl_80563BF0, lbl_80563C08);
            *(float *)((char *)temp_r30 + 0x14) = fn_80129DC4(6, *(float *)((char *)temp_r31 + 0x34), *(float *)((char *)temp_r31 + 0x38));
            *(float *)((char *)temp_r30 + 0x18) = *(float *)((char *)temp_r31 + 0x44);
            *(int *)((char *)temp_r30 + 0x1C) = fn_80129D18(6, fn_80235FD8(*(int *)((char *)temp_r31 + 0x54)));
        }
        temp_r31_2 = lbl_8055F448;
        temp_f4 = spC;
        temp_f0_2 = *(float *)((char *)temp_r31_2 + 0xD4) + *(float *)((char *)temp_r31_2 + 0xA0);
        temp_f2 = lbl_80563C0C + sp8;
        sp10 = spC;
        *(float *)((char *)temp_r31_2 + 0xD4) = temp_f0_2;
        sp14 = temp_f2;
        if (temp_f0_2 > 1.0f && *(int *)((char *)temp_r31_2 + 0xBC) + 1 <= *(int *)((char *)temp_r31_2 + 0xC0)) {
            *(float *)((char *)temp_r31_2 + 0xD4) = *(float *)((char *)temp_r31_2 + 0xD4) - 1.0f;
            temp_r5_2 = *(int *)((char *)temp_r31_2 + 0xBC);
            temp_r6_2 = *(int *)((char *)temp_r31_2 + 0xB8);
            temp_r4_2 = temp_r5_2 + 1;
            *(int *)((char *)temp_r31_2 + 0xBC) = temp_r4_2;
            temp_r0_2 = temp_r5_2 << 5;
            temp_r30_2 = (void *)((char *)temp_r6_2 + temp_r0_2);
            *(float *)((char *)temp_r6_2 + temp_r0_2) = temp_f4;
            *(float *)((char *)temp_r30_2 + 4) = temp_f2;
            temp_f30_2 = fn_80129DC4(6, *(float *)((char *)temp_r31_2 + 0x7C), *(float *)((char *)temp_r31_2 + 0x80));
            temp_f31_2 = fn_80129DC4(6, *(float *)((char *)temp_r31_2 + 0x84), *(float *)((char *)temp_r31_2 + 0x88));
            *(float *)((char *)temp_r30_2 + 8) = temp_f31_2 * (float)cos((double)temp_f30_2);
            *(float *)((char *)temp_r30_2 + 0xC) = temp_f31_2 * (float)sin((double)temp_f30_2);
            *(float *)((char *)temp_r30_2 + 0x10) = fn_80129DC4(6, lbl_80563BF0, lbl_80563C08);
            *(float *)((char *)temp_r30_2 + 0x14) = fn_80129DC4(6, *(float *)((char *)temp_r31_2 + 0x94), *(float *)((char *)temp_r31_2 + 0x98));
            *(float *)((char *)temp_r30_2 + 0x18) = *(float *)((char *)temp_r31_2 + 0xA4);
            *(int *)((char *)temp_r30_2 + 0x1C) = fn_80129D18(6, fn_80235FD8(*(int *)((char *)temp_r31_2 + 0xB4)));
        }
    }
}
#pragma pop
void fn_80264D5C(void *arg0) {
    SparkList *l;
    SparkParticle *p, *last;
    float dt;
    int i, count;

    l = (SparkList *)((char *)arg0 + 0x40);
    dt = fn_80214D48();
    i = 0;
    while (i < l->count) {
        p = &l->items[i];
        p->life -= dt;
        if (p->life < lbl_80558DC4[0]) {
            if (i >= 0 && i < l->count) {
                last = &l->items[l->count - 1];
                if (i != l->count - 1) {
                    *(int *)&p->x = *(int *)&last->x;
                    *(int *)&p->y = *(int *)&last->y;
                    *(int *)&p->vx = *(int *)&last->vx;
                    *(int *)&p->vy = *(int *)&last->vy;
                    p->a10 = last->a10;
                    p->a14 = last->a14;
                    p->life = last->life;
                    p->id = last->id;
                }
                l->count = l->count - 1;
            }
        } else {
            i++;
            p->vx += l->gx * dt;
            p->vy += l->gy * dt;
            p->x += p->vx * dt;
            p->y += p->vy * dt;
            p->a10 += p->a14 * dt;
        }
    }
    l = (SparkList *)((char *)arg0 + 0xA0);
    dt = fn_80214D48();
    i = 0;
    while (i < l->count) {
        p = &l->items[i];
        p->life -= dt;
        if (p->life < lbl_80558DC4[0]) {
            if (i >= 0 && i < l->count) {
                last = &l->items[l->count - 1];
                if (i != l->count - 1) {
                    *(int *)&p->x = *(int *)&last->x;
                    *(int *)&p->y = *(int *)&last->y;
                    *(int *)&p->vx = *(int *)&last->vx;
                    *(int *)&p->vy = *(int *)&last->vy;
                    p->a10 = last->a10;
                    p->a14 = last->a14;
                    p->life = last->life;
                    p->id = last->id;
                }
                l->count = l->count - 1;
            }
        } else {
            i++;
            p->vx += l->gx * dt;
            p->vy += l->gy * dt;
            p->x += p->vx * dt;
            p->y += p->vy * dt;
            p->a10 += p->a14 * dt;
        }
    }
}

#pragma cplusplus on
extern "C" void fn_80264FD4(void *arg0) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
    };
    ((Dummy*)arg0)->f5();
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_80264FE4(void *arg0) {
    char *p = (char *)arg0;
    float base, intensity, value, limit, zero;
    int id, offset;
    char *item;
    int i, alpha, a;

    limit = lbl_80563C00;
    zero = lbl_80563BF0;
    i = 0;
    offset = 0;
    while (i < *(int *)(p + 0xBC)) {
        item = *(char **)(p + 0xB8) + offset;
        value = *(float *)(p + 0xD0) * (*(float *)(p + 0xA4) - *(float *)(item + 0x18));
        if (limit < value) value = limit;
        value = (value > zero) ? value : zero;
        alpha = 0xFF;
        a = (int)(value * (*(float *)(item + 0x18) * *(float *)(p + 0xCC)));
        a = (a > 0) ? a : 0;
        if (a < 0xFF) alpha = a;
        id = *(int *)(item + 0x1C);
        base = *(float *)(p + 0xAC) + *(float *)(p + 0xB0) * (limit - *(float *)(item + 0x18) * *(float *)(p + 0xC8));
        intensity = base * fn_80235F64(*(void **)(p + 0xB4), id);
        fn_80235AFC(*(void **)(p + 0xB4), id, ((unsigned int)alpha << 24) | 0xFFFFFF,
                    *(float *)item, *(float *)(item + 4), lbl_80563BF0,
                    base * fn_80235EF0(*(void **)(p + 0xB4), *(int *)(item + 0x1C)), intensity, *(float *)(item + 0x10));
        offset += 0x20;
        i++;
    }
    {
        float limit2 = lbl_80563C00;
        zero = lbl_80563BF0;
        i = 0;
        offset = 0;
        while (i < *(int *)(p + 0x5C)) {
            item = *(char **)(p + 0x58) + offset;
            value = *(float *)(p + 0x70) * (*(float *)(p + 0x44) - *(float *)(item + 0x18));
            if (limit2 < value) value = limit2;
            value = (value > zero) ? value : zero;
            alpha = 0xFF;
            a = (int)(value * (*(float *)(item + 0x18) * *(float *)(p + 0x6C)));
            a = (a > 0) ? a : 0;
            if (a < 0xFF) alpha = a;
            id = *(int *)(item + 0x1C);
            base = *(float *)(p + 0x4C) + *(float *)(p + 0x50) * (limit2 - *(float *)(item + 0x18) * *(float *)(p + 0x68));
            intensity = base * fn_80235F64(*(void **)(p + 0x54), id);
            fn_80235AFC(*(void **)(p + 0x54), id, ((unsigned int)alpha << 24) | 0xFFFFFF,
                        *(float *)item, *(float *)(item + 4), lbl_80563BF0,
                        base * fn_80235EF0(*(void **)(p + 0x54), *(int *)(item + 0x1C)), intensity, *(float *)(item + 0x10));
            offset += 0x20;
            i++;
        }
    }
}
#pragma pop

#pragma cplusplus off
void fn_8026523C(void *arg0) {
    extern char lbl_80346618[];
    extern float lbl_80563BF0;
    float value = lbl_80563BF0;
    *(void **)arg0 = lbl_80346618;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(int *)((char *)arg0 + 0x18) = 0;
    *(unsigned char *)((char *)arg0 + 0x1C) = 0;
    *(int *)((char *)arg0 + 0xB4) = 0;
    *(float *)((char *)arg0 + 0xB8) = value;
}

int strlen(char *);
void fn_80265268(void *arg0, int arg1, char *arg2, float farg0) {
    char *dst = (char *)arg0 + 0x1C;
    int count = 0x96;
    char *src = arg2;
    unsigned char c;
    *(int *)((char *)arg0 + 0x18) = arg1;
    goto copy;
count_check:
    if (--count > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto count_check;
    goto done;
done:
    *(int *)((char *)arg0 + 0xB4) = strlen((char *)arg0 + 0x1C);
    *(float *)((char *)arg0 + 0xB8) = farg0;
}

void fn_802652E8(void *arg0) {
    char *p = (char *)arg0;
    char *q;
    float s[8];
    float f31, f30, f29;
    int v, max, flag;
    signed char saved;
    float t;

    t = fn_80264588();
    if (t < *(float *)(p + 0xB8)) return;
    f31 = lbl_80563C18 * (t - *(float *)(p + 0xB8));
    fn_8022ACFC(*(int *)(p + 0x18), p + 0x1C, &s[4], &s[5], &s[6], &s[7], (float)*(int *)(p + 4), (float)*(int *)(p + 8));
    v = (int)f31;
    max = *(int *)(p + 0xB4);
    flag = v > max;
    if (flag) {
        v = max;
    } else {
        fn_802645EC();
    }
    q = p + v;
    saved = q[0x1C];
    q[0x1C] = 0;
    fn_8022ACFC(*(int *)(p + 0x18), p + 0x1C, &s[0], &s[1], &s[2], &s[3], (float)*(int *)(p + 4), (float)*(int *)(p + 8));
    f30 = (s[6] - s[4]) - (s[2] - s[0]);
    f29 = (float)*(int *)(p + 4);
    {
        int r = fn_8022AA84(*(int *)(p + 0x18));
        if (r & 2) {
            f29 = f29 - f30;
        } else if (r & 4) {
            f29 = f29 - lbl_80563BF8 * f30;
        }
    }
    fn_8022BD40(*(int *)(p + 0x18), p + 0x1C, 0, 0, f29, (float)*(int *)(p + 8), lbl_80563BF0, s[6] - s[4], s[7] - s[5], lbl_80563C00);
    q[0x1C] = saved;
    if (!flag) {
        float f5 = f31 - (float)v;
        float f4 = lbl_80563C1C * f5;
        fn_80264A5C((float)(int)f4 + ((s[4] + s[2]) - s[0]), (s[7] + s[5]) * lbl_80563BF8 * 1.0f);
    }
}

void fn_80265558(void *arg0) {
    extern char lbl_803465B8[];
    extern float lbl_80563BF0;
    float value = lbl_80563BF0;
    *(void **)arg0 = lbl_803465B8;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(float *)((char *)arg0 + 0x18) = value;
    *(float *)((char *)arg0 + 0x1C) = value;
}

void fn_8026557C(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x18) = farg0;
}

void fn_80265584(void *arg0) {
    extern float lbl_8055C454;
    *(float *)((char *)arg0 + 0x1C) = lbl_8055C454;
    lbl_8055C454 = *(float *)((char *)arg0 + 0x18);
}

extern char lbl_80346558[];
extern float lbl_80563BF0;
extern float lbl_8055C454;
void fn_80265598(void *arg0) {
    extern float lbl_8055C454;
    lbl_8055C454 = *(float *)((char *)arg0 + 0x1C);
}

void fn_802655A4(void *arg0) {
    extern void *lbl_8055F44C;
    extern char lbl_80346558[];
    extern float lbl_80563BF0;
    void *ptr = lbl_80346558;
    float value = lbl_80563BF0;
    *(void **)arg0 = ptr;
    *(int *)((char *)arg0 + 0x14) = 0;
    lbl_8055F44C = arg0;
    *(float *)((char *)arg0 + 0x1C) = value;
}

int fn_802655C8(int arg0, int arg1) {
    extern void *lbl_8055F44C;
    if (arg0 != 0) {
        lbl_8055F44C = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

typedef float f32;
void fn_80265610(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x1C) = farg0; }

void fn_80265618(void *arg0) {
    *(unsigned char *)((char *)arg0 + 0x20) = 0;
    *(float *)((char *)arg0 + 0x18) = *(float *)((char *)arg0 + 0x1C);
}

#pragma dont_inline on
void fn_8026562C(void *arg0) {
    extern float lbl_80558DC4[];
    extern float fn_80214D48();
    fn_802645EC();
    if (*(float *)((char *)arg0 + 0x18) > lbl_80558DC4[0]) {
        *(float *)((char *)arg0 + 0x18) -= fn_80214D48();
    } else {
        *(unsigned char *)((char *)arg0 + 0x20) = 1;
    }
}

int fn_80265688(void) {
    if (fn_80265B5C() != 0) {
        fn_802168BC(-1);
        return 1;
    }
    fn_80216D28();
    return 0;
}

extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, int, int, int);
extern void fn_802640C4(void *, void *);
extern void fn_80236910(void *);
extern char lbl_803464B4[], lbl_803464C8[];
__declspec(section ".sdata") extern char lbl_8055C498[];
__declspec(section ".sdata") extern char lbl_8055C4A0[];
#pragma push
#pragma use_lmw_stmw off
int fn_802656C8(void *arg0) {
    extern unsigned char lbl_80498F78[];
    int sp[5];
    int count = 0;
    int i = 0;
    int j, k;
    int result;
    void *item;
    void *list;
    int n, idx;

    while ((item = ((void *(*)(void *, int))(*(void ***)arg0)[0x60 / 4])(arg0, i)) != 0) {
        if (stricmp(((char *(*)(void *))(*(void ***)item)[2])(item), lbl_8055C498) == 0) {
            count++;
        }
        i++;
    }
    n = count + 5;
    fn_8012850C(n * 0x14 + 0x10, lbl_803464B4);
    list = fn_8002F37C(fn_802640A0, 0, 0x14, n);
    idx = 0;
    k = 0;
    while ((item = ((void *(*)(void *, int))(*(void ***)arg0)[0x60 / 4])(arg0, k)) != 0) {
        if (stricmp(((char *(*)(void *))(*(void ***)item)[2])(item), lbl_8055C498) == 0) {
            void *dst = (char *)list + idx * 0x14;
            idx++;
            fn_802640C4(dst, item);
        }
        k++;
    }
    fn_802643B8((char *)list + idx++ * 0x14);
    fn_80264404((char *)list + idx++ * 0x14);
    fn_80264444((char *)list + idx++ * 0x14);
    fn_80264484((char *)list + idx * 0x14);
    sp[0] = 0; sp[1] = 0; sp[2] = 0; sp[3] = 0; sp[4] = 0;
    sp[0] = ((int (*)(void *, char *))(*(void ***)arg0)[0x14 / 4])(arg0, lbl_8055C4A0);
    sp[1] = (int)list;
    fn_80236910(lbl_803464C8);
    result = fn_802146BC(sp, -999, -999, 1);
    if (list != 0) {
        fn_80128670((char *)list - 0x10);
    }
    j = 0;
    while (j < *(int *)(lbl_80498F78 + 4)) {
        void *p = (*(void ***)lbl_80498F78)[j];
        if (p != 0) {
            ((void (*)(void *, int))(*(void ***)p)[2])(p, 1);
        }
        j++;
    }
    *(int *)(lbl_80498F78 + 4) = 0;
    return (unsigned)((-1 - result) | (result + 1)) >> 31;
}
#pragma pop
extern char lbl_8055C4A8[4];
extern void fn_80236954(void *queue);
void fn_802658FC(void) {
    fn_80236954(lbl_8055C4A8);
}

void fn_80265904(void) {
    fn_80236914();
    if (fn_8023695C(lbl_8055C4A8) == 2) {
        fn_80216CA8();
        fn_802168BC(0);
    }
}

extern int fn_802146BC();
extern int lbl_80498F58[5];
extern int lbl_802FA73C[5];
__declspec(section ".sdata") extern char lbl_8055BAC0[];
__declspec(section ".sdata") extern char lbl_8055BAB8[];
extern void fn_802658FC(void);
extern void fn_80265904(void);
#pragma push
#pragma use_lmw_stmw off
void fn_80265940(void) {
      int data[24];
      int *v;
      v = lbl_802FA73C;
      data[15] = lbl_80498F58[0];
      data[16] = lbl_80498F58[1];
      data[17] = lbl_80498F58[2];
      data[18] = lbl_80498F58[3];
      data[19] = lbl_80498F58[4];
      data[0] = v[0];
      data[1] = (int)&data[5];
      data[2] = v[2];
      data[3] = v[3];
      data[4] = v[4];
      data[7] = (int)fn_802658FC;
      data[12] = (int)fn_80265904;
      data[5] = (int)lbl_8055BAC0;
      data[10] = (int)lbl_8055BAB8;
      data[13] = 2;
      data[6] = 8;
      data[11] = 8;
      data[8] = 0;
      data[9] = 0;
      data[14] = 0;
      fn_802146BC(data, -999, -999, 1, v[4], v[3], v[2], v[0]);
  }
#pragma pop
extern void fn_80236954(void *);
extern int fn_8023695C(void *);
extern void fn_80216CA8(void);
extern void fn_802168BC(int);
extern char lbl_803464EC[];
extern void *lbl_8055F44C;
extern unsigned char lbl_8055F450;
int fn_80128668(void);
#pragma push
#pragma small_data off
void fn_80265A28(void) {
    fn_80236954(lbl_803464EC);
}
#pragma pop
void fn_80265A34(void) {
    fn_80236914();
    if (fn_8023695C(lbl_803464EC) == 2) {
        fn_80216CA8();
        fn_802168BC(0);
    }
}

int fn_80265B5C(void) {
    int ret = 1;
    void *p = lbl_8055F44C;
    int flag = 0;

    if (p != 0 && *((unsigned char *)p + 0x20) != 0) {
        flag = 1;
    }
    if (flag != 0) {
        goto done;
    }
    if (lbl_8055F450 == 0) {
        ret = 0;
    }
done:
    return ret;
}

int fn_80265B9C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_80265BDC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_80265C1C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

