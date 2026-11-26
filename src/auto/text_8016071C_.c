// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E2BC;
extern int lbl_8042FD60[5];
extern int fn_8027DED0(void);
extern int fn_8001D9B4(int *, int);
extern int fn_8001DA48(void *, int);
extern int lbl_802F9490[5];
extern const char lbl_8032F4C8[];
extern int fn_801284F8(int, const char *);
extern int fn_8001D884(void *);
extern int fn_80128668(void);
extern void fn_801607F8(void);
extern int __AXGetStackHead(int);
typedef struct Obj { void **vtable; } Obj;
#pragma cplusplus on
/* Build the active grade handler from the given schedule object: allocate a 0x18-byte
 * "gradeschedule" block, construct it from the object, store it as the active handler,
 * then fill the five-entry bound table from the object's per-stack-head values. */
extern "C" void fn_8016071C(void *sourceObj) {
    #pragma scheduling invalid_target
    class ObjV {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual int meth(int head, int x);
    };
    int i;
    int head;
    void *gradeHandler;
    void *mem = (void *)fn_801284F8(0x18, lbl_8032F4C8);
    if (mem != 0) {
        gradeHandler = (void *)((int (*)(void *, void *))fn_8001D884)(mem, sourceObj);
    }
    lbl_8055E2BC = gradeHandler;
    ObjV *obj = (ObjV *)sourceObj;
    for (i = 0; i < 5; i++) {
        head = __AXGetStackHead(i);
        lbl_8042FD60[i] = obj->meth(head, -1);
    }
}
#pragma cplusplus off
/* Restore the fallback five-entry rank-bound table lbl_8042FD60 to its default
 * thresholds from the constant table lbl_802F9490 (used when no handler is bound). */
void fn_801607BC(void) {
    int default0 = lbl_802F9490[0];
    int default1 = lbl_802F9490[1];
    int default2 = lbl_802F9490[2];
    int default3 = lbl_802F9490[3];
    int default4 = lbl_802F9490[4];
    lbl_8042FD60[0] = default0;
    lbl_8042FD60[1] = default1;
    lbl_8042FD60[2] = default2;
    lbl_8042FD60[3] = default3;
    lbl_8042FD60[4] = default4;
}

#pragma dont_inline on
void fn_801607F8(void) {
    /* Frees the audio instance at lbl_8055E2BC if set, then resets the five bound slots to -1. */
    void *instance = lbl_8055E2BC;
    if (instance != 0) {
        if (instance != 0) {
            ((int (*)(void *))fn_80128668)(instance);
        }
        lbl_8055E2BC = 0;
    }
    lbl_8042FD60[0] = -1;
    lbl_8042FD60[1] = -1;
    lbl_8042FD60[2] = -1;
    lbl_8042FD60[3] = -1;
    lbl_8042FD60[4] = -1;
}

extern void **__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(void *);
extern void *fn_80204EA0(const char *);
extern void *getValueFile(const char *);
extern void fn_80131818(void *);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8055A0A8;
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Initialize audio/effect data: try obtaining it via the audio interface, fall back to loading the named resource by key, and log/reset on failure. */
extern "C" void fn_80160850(void) {
    class Audio {
    public:
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void a3();
        virtual void a4();
        virtual void a5();
        virtual void a6();
        virtual void a7();
        virtual void a8();
        virtual void a9();
        virtual void a10();
        virtual void a11();
        virtual void a12();
        virtual void a13();
        virtual void a14();
        virtual void a15();
        virtual void a16();
        virtual void a17();
        virtual void a18();
        virtual void a19();
        virtual void a20();
        virtual int apply(void *);
    };
    class Resource {
    public:
        virtual int get(const char *);
        virtual void r1();
        virtual int validate(const char *);
    };
    const char *base;
    int succeeded;
    const char *name;
    const char *key;
    Audio *audio;
    void *parameter;
    Resource *resource;
    int result;

    base = lbl_8032F4C8;
    fn_801607F8();
    name = base + 0x10;
    succeeded = 0;
    key = (const char *)&lbl_8055A0A8;
    audio = (Audio *)*((void **)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20));
    parameter = fn_80204EA0(base + 0x1C);
    result = audio->apply(parameter);
    if (((unsigned int)(-result | result) >> 31) != 0) {
        result = audio->apply(parameter);
        fn_8016071C((Obj *)result);
        succeeded = 1;
    } else {
        resource = (Resource *)getValueFile(name);
        if (resource != 0) {
            if (resource->validate(key) != 0) {
                result = resource->get(key);
                fn_8016071C((Obj *)result);
                succeeded = 1;
            } else {
                fn_802E30C8(base + 0x28, key, name);
            }
            fn_80131818(resource);
        } else {
            fn_802E30C8(base + 0x68, name);
        }
    }
    if (succeeded == 0) {
        fn_802E30C8(base + 0x88);
        fn_801607BC();
    }
}
#pragma use_lmw_stmw on
#pragma scheduling on
#pragma cplusplus off

#pragma dont_inline on
/* Return the value at `index` in the active handler's 5-entry table, or in the static fallback table when no handler is bound. */
int fn_80160998(int index) {
    if (lbl_8055E2BC != 0)
        return fn_8001DA48(lbl_8055E2BC, index);
    return lbl_8042FD60[index];
}
#pragma dont_inline off

/* Returns a rank index for value using the active handler if present, otherwise scans the 5-entry bounds table. */
int fn_801609C4(int value) {
    int index;
    int *boundPtr;
    if (lbl_8055E2BC != 0)
        return fn_8001D9B4((int *)lbl_8055E2BC, value);
    boundPtr = lbl_8042FD60;
    for (index = 0; index < 5; index++) {
        int bound = *boundPtr++;
        if (bound >= 0 && value >= bound)
            return index;
    }
    return 4;
}

/* Return the rank held by the active stat handler (offset 0x14), or 2 when none is bound. */
int fn_80160A74(void) {
    if (lbl_8055E2BC != 0) {
        return *(int *)((char *)lbl_8055E2BC + 0x14);
    }
    return 2;
}

/* OS alarm callback: refresh the audio setting for the current rank. It
   resolves the active rank (an override from fn_8027DED0, else the default
   rank) and passes it to the rank-value lookup fn_80160998. The alarm itself
   is unused. */
void fn_80160A90(void *alarm) {
    fn_80160998(fn_80160AB4(alarm));
}

#pragma dont_inline on
/* Return the rank override from fn_8027DED0 if valid, else the active stat handler's rank; the alarm argument is unused. */
int fn_80160AB4(void *alarm) {
    int rank = fn_8027DED0();
    if (rank != -1) {
        return rank;
    }
    return fn_80160A74();
}
#pragma dont_inline reset
/* Tail-call wrapper that forwards to fn_801607F8. */
void fn_80160AE4(void) {
    fn_801607F8();
}
