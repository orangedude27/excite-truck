// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_80207848(int, int);
extern float lbl_8055C4F8;
extern void fn_8026B260(void);
extern void fn_801331C4(int, void *, float *);
extern void fn_8026B11C(void **, void *);
extern unsigned char lbl_80346988[];
extern int lbl_8055F4D0, lbl_8055F4CC, lbl_8055F4C8;
extern float lbl_80563D68;
extern int lbl_8055C4FC, lbl_8055C500;
extern unsigned char lbl_8049A028[];
void fn_8026B118(void) {}

extern int lbl_8055F4D0, lbl_8055F4CC;
#pragma dont_inline on
void fn_8026B11C(void **arg0, void *arg1) {
    void *obj = fn_80207848((int)arg1, 0);
    float value;
    *arg0 = obj;
    if (obj != 0) {
        value = lbl_8055C4F8;
        if (value != *(float *)((unsigned char *)obj + 8)) {
            *((unsigned char *)obj + 0x4D) = 1;
            *(float *)((unsigned char *)obj + 8) = value;
        }
    }
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void deleteThreads__6SystemFv_8026B178(void *arg0) {
    class ThreadObject {
    public:
        virtual void destroy(int);
    };
    ThreadObject *p = *(ThreadObject **)arg0;
    if (p) {
        if (p)
            p->destroy(1);
        *(ThreadObject **)arg0 = 0;
    }
}
#pragma cplusplus reset
#pragma pop

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_8026B1D0(void *obj_) {
    class Object {
    public:
        virtual void v00();
        virtual void v04();
        virtual void v08();
        virtual void v0C();
        virtual void v10();
        virtual void v14();
        virtual void v18();
        virtual void v1C();
        virtual float fn28(unsigned int, float);
        virtual void v2C();
        virtual void v30();
        virtual void v34();
        virtual void v38();
        virtual unsigned long long fn3C(unsigned int);
    };
    union Pair {
        unsigned long long bits;
        float values[2];
    } pair;
    float *dst = (float *)(lbl_8049A028 + lbl_8055F4C8 * 0xC);
    Object *obj = (Object *)obj_;

    pair.bits = obj->fn3C((unsigned int)&lbl_8055C4FC);
    dst[0] = pair.values[0];
    dst[1] = pair.values[1];
    dst[2] = obj->fn28((unsigned int)&lbl_8055C500, lbl_80563D68);
}
#pragma scheduling on
#pragma cplusplus reset
extern int *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(int);
extern void *fn_80028E00(char *, const char *);
extern int fn_8012C33C(char *);
extern void *fn_80131808(char *);
extern void fn_80131818(void *);
extern int fn_802E30C8(const char *, ...);
extern char *strchr(const char *, int);
extern char *strncpy(char *, const char *, unsigned int);
extern int stricmp(const char *, const char *);
extern char lbl_8055C504, lbl_8055C50C;
#pragma push
#pragma cplusplus on
extern "C" void fn_8026B260(void) {
    class FileName {
    public:
        virtual void v00();
        virtual void v04();
        virtual void v08();
        virtual void v0C();
        virtual char *getFileName(const char *, int);
    };
    class Iterator {
    public:
        virtual void v00();
        virtual void *next(int);
    };
    class Entry {
    public:
        virtual const char *getName();
    };
    char name[12];
    char *base = (char *)lbl_80346988;
    register int iteratorOrZero = 0;
    void *obj;
    FileName *nameObj;
    register Iterator *it;
    register Entry *entry;
    char *dot;
    register int index;
    lbl_8055F4C8 = iteratorOrZero;
    obj = fn_8001285C(*__AXFXGetLfoSinTable_801769CC());
    nameObj = *(FileName **)((char *)obj + 0x20);
    dot = nameObj->getFileName(base, 0);
    if (dot != 0) {
        strncpy(name, dot, 11);
        dot = strchr(name, '.');
        if (dot) *dot = iteratorOrZero;
        fn_80028E00(name, (const char *)&lbl_8055C504);
        if (!fn_8012C33C(name)) {
            fn_802E30C8(base + 0xC, name);
            return;
        }
        iteratorOrZero = (int)fn_80131808(name);
        it = (Iterator *)iteratorOrZero;
        index = 0;
        do {
            entry = (Entry *)it->next(index++);
            if (entry && stricmp(entry->getName(), (const char *)&lbl_8055C50C) == 0) {
                fn_8026B1D0(entry);
                lbl_8055F4C8++;
            }
        } while (entry);
        fn_80131818(it);
        fn_802E30C8(base + 0x34, lbl_8055F4C8, name);
        return;
    }
    fn_802E30C8(base + 0x5C);
}
#pragma cplusplus reset
#pragma pop

#pragma scheduling invalid_target
void fn_8026B644(void) {
    register unsigned char *base = lbl_80346988;
    fn_8026B260();
    fn_801331C4(4, base + 0xA0, &lbl_8055C4F8);
    fn_8026B11C((void **)&lbl_8055F4D0, base + 0xB0);
    fn_8026B11C((void **)&lbl_8055F4CC, base + 0xBC);
}
#pragma scheduling on
void fn_8026B69C(void) {
    lbl_8055F4C8 = 0;
    deleteThreads__6SystemFv_8026B178(&lbl_8055F4CC);
    deleteThreads__6SystemFv_8026B178(&lbl_8055F4D0);
}

extern unsigned char lbl_8049A0E8[];
extern int lbl_8055F4C8;
extern int lbl_8055F4CC, lbl_8055F4D0;
extern void *memset(void *, int, unsigned int);
extern int fn_801B2F24(void);
extern void fn_8026B3D4(int);
extern void deleteThreads__6SystemFv_8026B178(void *);
#pragma scheduling invalid_target
void fn_8026B6D0(void) {
    void *p = lbl_8049A0E8;
    memset(p, 0, 0x80);
}
#pragma scheduling on
void fn_8026B6E4(void) {
    int i;
    if (lbl_8055F4C8 > 0) {
        i = 0;
        do {
            fn_8026B3D4(i);
            i++;
        } while (i < fn_801B2F24());
    }
}

int fn_8026B734(int arg0, float *arg1) {
    register int index = arg0 << 4;
    if (lbl_8049A0E8[index] != 0) {
        *arg1 = *(float *)(lbl_8049A0E8 + index + 8);
        return 1;
    }
    return 0;
}

int fn_8026B768(int arg0) {
    if (lbl_8049A0E8[arg0 * 0x10] != 0) {
        fn_8026A1F0(0xB, lbl_8049A0E8, 0);
        return 1;
    }
    return 0;
}

unsigned char fn_8026B7B4(int arg0) {
    return lbl_8049A0E8[arg0 * 0x10];
}

