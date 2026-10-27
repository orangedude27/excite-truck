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
typedef int (*Callback)(Obj *, int, int);
void fn_8016071C(Obj *obj) {
    int i;
    int head;
    if (fn_801284F8(0x18, lbl_8032F4C8)) {
        lbl_8055E2BC = (void *)fn_8001D884(obj);
    }
    for (i = 0; i < 5; i++) {
        head = __AXGetStackHead(i);
        lbl_8042FD60[i] = ((Callback)obj->vtable[4])(obj, head, -1);
    }
}

void fn_801607BC(void) {
    int a, b, c, d, e;
    a = lbl_802F9490[0];
    lbl_8042FD60[0] = a;
    b = lbl_802F9490[1];
    lbl_8042FD60[1] = b;
    c = lbl_802F9490[2];
    lbl_8042FD60[2] = c;
    d = lbl_802F9490[3];
    lbl_8042FD60[3] = d;
    e = lbl_802F9490[4];
    lbl_8042FD60[4] = e;
}

#pragma dont_inline on
void fn_801607F8(void) {
    if (lbl_8055E2BC == 0) {
        if (lbl_8055E2BC == 0) {
            fn_80128668();
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
extern void *fn_80131808(const char *);
extern void fn_80131818(void *);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8055A0A8;
typedef int (*Fn80160850Call)(void *, void *);
typedef int (*Fn80160850NamedCall)(void *, const char *);
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Virtual slots and the scalar key address reproduce the target lookup sequence. */
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
        resource = (Resource *)fn_80131808(name);
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
int fn_80160998(int arg0) {
    if (lbl_8055E2BC != 0)
        return fn_8001DA48(lbl_8055E2BC, arg0);
    return lbl_8042FD60[arg0];
}
#pragma dont_inline off

int fn_801609C4(int value) {
    int i;
    int *p;
    if (lbl_8055E2BC != 0)
        return fn_8001D9B4((int *)lbl_8055E2BC, value);
    p = lbl_8042FD60;
    for (i = 0; i < 5; i++) {
        int bound = *p++;
        if (bound >= 0 && value >= bound)
            return i;
    }
    return 4;
}

int fn_80160A74(void) {
    if (lbl_8055E2BC != 0) {
        return *(int *)((char *)lbl_8055E2BC + 0x14);
    }
    return 2;
}

void fn_80160A90(void* alarm) {
    fn_80160998(fn_80160AB4(alarm));
}

int fn_80160AB4(void *alarm) {
    fn_8027DED0();
    return fn_80160A74();
}

void fn_80160AE4(void) {
    fn_801607F8();
}
