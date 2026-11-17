// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* The current arena-event master object ("amaster"): fn_801B826C installs the one
 * fn_801B81E0 built for the arena event, or the "null_amaster" null object.  The
 * wrappers in this file forward to its vtable (see struct ArenaMaster); it is 0
 * between fn_801B832C (shut down) and the next event. */
extern void *lbl_8055E744;
extern void *fn_801284F8(int, const char *);
extern void *fn_8001285C(int);
extern int fn_801B81E0(void *);
extern void fn_80161618(void);
extern char lbl_8033676C[];
extern char lbl_8033677C[];
extern char lbl_8033678C[];
extern float lbl_8055A910;
extern char lbl_8055E748;
extern int lbl_8055E74C;
extern float lbl_8055E750;
extern float lbl_80562740;
extern float lbl_80562744;
#pragma cplusplus on
struct Dummy_801B826C {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual float d10(const char *, float);
};
struct Dummy_801B8318 {
    virtual void f0(int);
    virtual void f1();
    virtual void f2();
    virtual void f3(void *);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
          virtual void f13(void *);
    virtual void f14();
    virtual void f15();
    virtual void f16();
          virtual int f17(void *);
    virtual void f18(void *);
    virtual void f19(void *);
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
          virtual void f29(void *);
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36(void *, void *);
    virtual void f37();
    virtual void f38(void *, void *);
    virtual void f39();
    virtual void f40();
          virtual void f41(void *);
          virtual void f42(void *, void *, void *);
          virtual void f43(int, void *);
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
};
              /* The arena-event "master" object lbl_8055E744 points at.  fn_801B826C picks it
 * by the arena event id at +0x3E8: fn_801B81E0 builds a ZoneMaster (0x180201) or
 * one of the other event masters, and an event that needs none gets the
 * "null_amaster" null object with the empty vtable lbl_8033678C.  MWCC keeps two
 * empty words (offset-to-top, type info) ahead of the first method, so d0 is the
 * slot at vtable+0x08 (the destructor) and d8 the one at vtable+0x28. */
typedef struct ArenaMaster Dummy_801B851C; /* the old placeholder name */
struct ArenaMaster {
          virtual void d0();
          virtual void d1();
          virtual void d2();
          virtual void d3();
          virtual void d4();
          virtual void d5();
          virtual void d6();
          virtual void d7();
          virtual int d8(void *);
      };
                struct Dummy_801B8570 {
            virtual void d0();
            virtual void d1();
            virtual void d2();
            virtual void d3();
            virtual void d4();
            virtual void d5();
            virtual void d6();
            virtual void d7();
            virtual void d8();
            virtual int d9(int);
        };
        struct Dummy_801B8874 {
          virtual void d0();
          virtual void d1();
          virtual void d2();
          virtual void d3();
          virtual void d4();
          virtual void d5();
          virtual void d6();
          virtual void d7();
          virtual void d8();
          virtual void d9();
          virtual void d10();
          virtual void d11();
          virtual void d12();
          virtual void d13();
          virtual void d14();
          virtual void d15();
          virtual void d16();
          virtual void d17();
          virtual void d18();
          virtual void d19();
          virtual void d20();
          virtual void d21();
          virtual void d22();
          virtual void d23();
          virtual void d24();
          virtual void d25();
          virtual void d26();
          virtual void d27();
          virtual void d28();
          virtual void d29();
          virtual void d30();
          virtual void d31();
                      virtual int d32();
          virtual void d33();
                      virtual void d34(void *, void *, void *, void *);
      };
#pragma cplusplus off
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline fn_801B81E0
int fn_801B81E0(void *__restrict arg0) {
    extern int fn_8014145C(void);
    extern int fn_8014DE50(void);
    extern int fn_8016BE60(void);
    extern int fn_80172C28(void);
    extern void fn_802E317C(const char *, ...);
    extern char lbl_80336740[];
    switch (*(int *)((char *)arg0 + 0x3E8)) {
    case 0x180201:
        return fn_8014145C();
    case 0x180303:
        return fn_8016BE60();
    case 0x180302:
        return fn_8014DE50();
    case 0x180304:
        return fn_80172C28();
    default:
        fn_802E317C(lbl_80336740);
        return 0;
    }
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void fn_801B826C(void *arg0) {
    volatile int *p = (volatile int *)((char *)arg0 + 0x3E8);
    int value = *p;
    void *object;
    void *manager;
    lbl_8055E74C = value;
    if (value & 0x200) {
        lbl_8055E744 = (void *)fn_801B81E0(arg0);
    } else {
        object = fn_801284F8(4, lbl_8033676C);
        if (object != 0) {
            *(char **)object = lbl_8033678C;
        }
        lbl_8055E744 = object;
    }
    manager = fn_8001285C(*(int *)((char *)arg0 + 0x3E4));
    object = *(void **)((char *)manager + 0x20);
    lbl_8055A910 = ((Dummy_801B826C *)object)->d10(lbl_8033677C, lbl_80562740);
    lbl_8055E748 = 0;
    fn_80161618();
    lbl_8055E750 = lbl_80562744;
}
#pragma dont_inline reset
#pragma pop

#pragma pop
#pragma cplusplus on
/* Forward to the arena-event master (lbl_8055E744) via its f59 vtable slot. */
extern "C" void fn_801B8318(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f59();
}
#pragma cplusplus on
/* Shut down the current object: notify the system, invoke its vfunc (slot f0)
 * with 1 if present, then clear the global pointer and reset the float array at
 * lbl_80436D08 to lbl_80562744. */
extern "C" void fn_801B832C(void) {
    extern void fn_801616FC(void);
    extern float lbl_80436D08[];
    extern float lbl_80562744;
    fn_801616FC();
    if (lbl_8055E744 != 0)
        ((Dummy_801B8318 *)lbl_8055E744)->f0(1);
    lbl_80436D08[0] = lbl_80562744;
    lbl_8055E744 = 0;
    lbl_80436D08[1] = lbl_80562744;
    lbl_80436D08[2] = lbl_80562744;
    lbl_80436D08[3] = lbl_80562744;
    lbl_80436D08[4] = lbl_80562744;
    lbl_80436D08[5] = lbl_80562744;
    lbl_80436D08[6] = lbl_80562744;
    lbl_80436D08[7] = lbl_80562744;
}
#pragma cplusplus off
void* fn_801B83A0(void) {
    /* lbl_8055E744 is the global master object (the arena-event master), created
     * by fn_801B81E0 and cleared on shutdown; return it. */
    #define gGlobalObject lbl_8055E744
    return gGlobalObject;
    #undef gGlobalObject
}

#pragma cplusplus on
extern "C" void fn_801B83A8(void) {
    /* Reset the global object's state via its vtable, clear the shared float array and status flag,
     * run the global update step, and reset the associated timer to zero. */
    #define gGlobalObject lbl_8055E744
    #define gSharedFloats lbl_80436D08
    #define gStatusFlag lbl_8055E748
    #define gTimer lbl_8055E750
    #define gZeroFloat lbl_80562744
    #define RunGlobalUpdate fn_801619A8

    extern float gSharedFloats[];
    extern char gStatusFlag;
    extern float gTimer;
    extern float gZeroFloat;
    extern void RunGlobalUpdate(void);
    ((Dummy_801B8318 *)gGlobalObject)->f2();
    gSharedFloats[0] = gZeroFloat;
    gStatusFlag = 0;
    gSharedFloats[1] = gZeroFloat;
    gSharedFloats[2] = gZeroFloat;
    gSharedFloats[3] = gZeroFloat;
    gSharedFloats[4] = gZeroFloat;
    gSharedFloats[5] = gZeroFloat;
    gSharedFloats[6] = gZeroFloat;
    gSharedFloats[7] = gZeroFloat;
    RunGlobalUpdate();
    gTimer = gZeroFloat;

    #undef gGlobalObject
    #undef gSharedFloats
    #undef gStatusFlag
    #undef gTimer
    #undef gZeroFloat
    #undef RunGlobalUpdate
}
#pragma cplusplus off
void fn_801B8418(void) {

}

#pragma cplusplus on
extern "C" void fn_801B841C(void) {
    extern void fn_80161A18(void);
    extern float lbl_8055E750;
    extern float lbl_80562744;
    extern float lbl_80562748;
    struct Dummy {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual void d6();
        virtual int d7();
    };

    /* Run the global object's per-frame update, then advance or reset its timer. */
    ((Dummy *)lbl_8055E744)->d1();
    fn_80161A18();
    if (((Dummy *)lbl_8055E744)->d7() != 0)
        lbl_8055E750 += lbl_80562748;
    else
        lbl_8055E750 = lbl_80562744;
}
#pragma cplusplus off
void fn_801B8488(void) {

}

#pragma cplusplus on
extern "C" void fn_801B848C(void *obj) {
    /* Forward obj to the arena-event master (lbl_8055E744) via its f3 vtable slot. */
    ((Dummy_801B8318 *)lbl_8055E744)->f3(obj);
}
#pragma cplusplus on
extern "C" void fn_801B84A4(void *playerIndex) {
    /* Forward the player index to the arena-event master (lbl_8055E744) via its f17 vtable slot. */
    ((Dummy_801B8318 *)lbl_8055E744)->f17(playerIndex);
}
#pragma cplusplus off
void fn_801B84BC(void) {

}

#pragma cplusplus on
extern "C" void fn_801B84C0(void *obj) {
    /* Forward obj to the arena-event master (lbl_8055E744) via its f18 vtable slot. */
    ((Dummy_801B8318 *)lbl_8055E744)->f18(obj);
}
#pragma cplusplus on
extern "C" void fn_801B84D8(void *obj) {
    /* Forward obj to the arena-event master (lbl_8055E744) via its f19 vtable slot. */
    ((Dummy_801B8318 *)lbl_8055E744)->f19(obj);
}
#pragma cplusplus off
/* No-arg stub among the arena-event master wrappers: always reports 0 (false)
 * when there is no master state to supply a value. */
int fn_801B84F0(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_801B84F8(void) {
    /* Mark the arena-event master active (lbl_8055E748 = 1) and invoke the f4()
     * virtual entry on the global master object (lbl_8055E744). */
    extern char lbl_8055E748;
    lbl_8055E748 = 1;
    ((Dummy_801B8318 *)lbl_8055E744)->f4();
}
#pragma cplusplus off
extern char lbl_8055E748;
/* Returns the arena-event master active flag (gStatusFlag). */
char fn_801B8514(void) {
    return lbl_8055E748;
}

#pragma cplusplus on
/* Hand obj on to the arena-event master (lbl_8055E744) through its vtable slot
 * 0x28: ZoneMaster's fn_801B8A20 runs obj's own slot 0x1C while the master is
 * active (lbl_8055E748), and the "null_amaster" answer is a plain 1.  Nothing is
 * handed on, and 0 comes back, while the screen's challenge sub-task reports
 * itself finished (fn_80161BB8, that object's vtable slot 0x24). */
extern "C" int fn_801B851C(void *obj) {
    extern int fn_80161BB8(void);
    if (fn_80161BB8() != 0) return 0;
    return ((ArenaMaster *)lbl_8055E744)->d8(obj);
}
/* Return 1 if the global object accepts arg0 and fn_80161B94 reports clear. */
extern "C" int fn_801B8570(int arg0) {
    extern int fn_80161B94(void);
    int accepted = 0;
    if (((Dummy_801B8570 *)lbl_8055E744)->d9(arg0) != 0 && fn_80161B94() == 0) accepted = 1;
    return accepted;
}

#pragma cplusplus on
/* Forward f7 to the current arena-event master via its vtable slot. */
extern "C" void fn_801B85CC(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f7();
}
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801B85E0(void *arg0, void *arg1, void *arg2, void *arg3) {
    /* Forward four arguments to slot d34 of the current arena master object. */
    ((Dummy_801B8874 *)lbl_8055E744)->d34(arg0, arg1, arg2, arg3);
}
#pragma scheduling on
extern "C" void fn_801B8610(void *arg0, void *arg1) {
    /* Forward two arguments to the current arena master's vtable slot f36. */
    ((Dummy_801B8318 *)lbl_8055E744)->f36(arg0, arg1);
}
#pragma cplusplus on
extern "C" int fn_801B8630(int arg0, int arg1, int arg2) {
    /* Forwards three arguments to vtable slot 0xA0 of the global UI/game object
     * (lbl_8055E744), returning 1 immediately if fn_80161BDC indicates blocked. */
    struct Dummy_801B8630 {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual void d6();
        virtual void d7();
        virtual void d8();
        virtual void d9();
        virtual void d10();
        virtual void d11();
        virtual void d12();
        virtual void d13();
        virtual void d14();
        virtual void d15();
        virtual void d16();
        virtual void d17();
        virtual void d18();
        virtual void d19();
        virtual void d20();
        virtual void d21();
        virtual void d22();
        virtual void d23();
        virtual void d24();
        virtual void d25();
        virtual void d26();
        virtual void d27();
        virtual void d28();
        virtual void d29();
        virtual void d30();
        virtual void d31();
        virtual void d32();
        virtual void d33();
        virtual void d34();
        virtual void d35();
        virtual void d36();
        virtual void d37();
        virtual int call(int, int, int);
    };
    extern int fn_80161BDC(void);
    if (fn_80161BDC() != 0) return 1;
    return ((Dummy_801B8630 *)lbl_8055E744)->call(arg0, arg1, arg2);
}
/* Forwards an object to virtual slot f41 of the current arena-event master object. */
extern "C" void fn_801B86A4(void *object) {
    ((Dummy_801B8318 *)lbl_8055E744)->f41(object);
}
#pragma cplusplus on
/* Forward to a virtual handler, scale the float at +0x50 by lbl_8055A910, then call fn_8027DED8 with the original value. */
extern "C" void fn_801B86BC(int arg0, void *arg1) {
    extern float lbl_8055A910;
    extern void fn_8027DED8(int, void *, float);
    register float value;
    ((Dummy_801B8318 *)lbl_8055E744)->f43(arg0, arg1);
    value = *(float *)((char *)arg1 + 0x50);
    *(float *)((char *)arg1 + 0x50) = value * lbl_8055A910;
    fn_8027DED8(arg0, arg1, value);
}
#pragma cplusplus on
extern "C" int fn_801B8728(int arg0) {
    /* Sends arg0 to the arena-event master (vtable slot 0xB8 / call1) and returns
       nonzero when its follow-up query (slot 0xE4 / call2) returns 0. */
    struct Dummy_801B8728 {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual void d6();
        virtual void d7();
        virtual void d8();
        virtual void d9();
        virtual void d10();
        virtual void d11();
        virtual void d12();
        virtual void d13();
        virtual void d14();
        virtual void d15();
        virtual void d16();
        virtual void d17();
        virtual void d18();
        virtual void d19();
        virtual void d20();
        virtual void d21();
        virtual void d22();
        virtual void d23();
        virtual void d24();
        virtual void d25();
        virtual void d26();
        virtual void d27();
        virtual void d28();
        virtual void d29();
        virtual void d30();
        virtual void d31();
        virtual void d32();
        virtual void d33();
        virtual void d34();
        virtual void d35();
        virtual void d36();
        virtual void d37();
        virtual void d38();
        virtual void d39();
        virtual void d40();
        virtual void d41();
        virtual void d42();
        virtual void d43();
        virtual void call1(int);
        virtual void d45();
        virtual void d46();
        virtual void d47();
        virtual void d48();
        virtual void d49();
        virtual void d50();
        virtual void d51();
        virtual void d52();
        virtual void d53();
        virtual void d54();
        virtual int call2();
    };
    ((Dummy_801B8728 *)lbl_8055E744)->call1(arg0);
    return ((Dummy_801B8728 *)lbl_8055E744)->call2() == 0;
}
extern "C" void fn_801B8778(void) {
    /* Forward the f46() virtual call to the arena-event master object (lbl_8055E744). */
    ((Dummy_801B8318 *)lbl_8055E744)->f46();
}
#pragma cplusplus on
extern "C" void fn_801B878C(void) {
    /* Forward the f47() virtual call to the arena-event master object (lbl_8055E744). */
    ((Dummy_801B8318 *)lbl_8055E744)->f47();
}
#pragma cplusplus on
extern "C" int fn_801B87A0(int arg0, int arg1) {
    /* Forward the call to the global UI object's vtable method at offset 0x8C, or return 1 if input is blocked. */
    struct UiObjectVTable_801B87A0 {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual void d6();
        virtual void d7();
        virtual void d8();
        virtual void d9();
        virtual void d10();
        virtual void d11();
        virtual void d12();
        virtual void d13();
        virtual void d14();
        virtual void d15();
        virtual void d16();
        virtual void d17();
        virtual void d18();
        virtual void d19();
        virtual void d20();
        virtual void d21();
        virtual void d22();
        virtual void d23();
        virtual void d24();
        virtual void d25();
        virtual void d26();
        virtual void d27();
        virtual void d28();
        virtual void d29();
        virtual void d30();
        virtual void d31();
        virtual void d32();
        virtual int method(int, int);
    };
    extern int fn_80161B0C(void);
    if (fn_80161B0C() != 0) {
        return 1;
    }
    return ((UiObjectVTable_801B87A0 *)lbl_8055E744)->method(arg0, arg1);
}
#pragma cplusplus off
/* No-arg stub among the arena-event master wrappers: always reports 0 (false)
 * where a master or system state would otherwise supply a result. */
int fn_801B8804(void) { return 0; }

#pragma cplusplus on
/* Forward the f31() virtual call to the arena-event master object (lbl_8055E744). */
extern "C" void fn_801B880C(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f31();
}
#pragma cplusplus on
/* Forward to the arena-event master (lbl_8055E744) via its f14 vtable slot. */
extern "C" void fn_801B8820(void) {
    ((Dummy_801B8318 *)lbl_8055E744)->f14();
}
#pragma cplusplus on
extern "C" void fn_801B8834(void) {
    /* Forward to the arena-event master (lbl_8055E744) via its f15 vtable slot. */
    ((Dummy_801B8318 *)lbl_8055E744)->f15();
}
#pragma cplusplus on
extern "C" void fn_801B8848(void) {
    /* Forward to the arena-event master (lbl_8055E744) via its f11 vtable slot. */
    ((Dummy_801B8318 *)lbl_8055E744)->f11();
}
#pragma cplusplus on
extern "C" void fn_801B885C(void *obj) {
    /* Forward obj to the arena-event master (lbl_8055E744) via its f13 vtable slot. */
    ((Dummy_801B8318 *)lbl_8055E744)->f13(obj);
}
extern "C" int fn_801B8874(void) {
    /* If a certain system state is active, run its handler and report handled; otherwise forward to slot 0x88 of lbl_8055E744. */
    extern int fn_80161C38(void);
    extern void fn_80161A70(void);
    if (fn_80161C38() != 0) {
        fn_80161A70();
        return 1;
    }
    return ((Dummy_801B8874 *)lbl_8055E744)->d32();
}
#pragma cplusplus on
/* If a specific state is active, run its handler; otherwise forward to the arena master vtable slot f12. */
extern "C" void fn_801B88BC(void) {
    extern int fn_80161C38(void);
    extern void fn_80161B70(void);
    if (fn_80161C38() != 0) {
        fn_80161B70();
        return;
    }
    ((Dummy_801B8318 *)lbl_8055E744)->f12();
}
extern "C" void fn_801B8900(void) {
    /* Forward the f30() virtual call to the arena-event master object (lbl_8055E744). */
    ((Dummy_801B8318 *)lbl_8055E744)->f30();
}
#pragma cplusplus on
extern "C" void fn_801B8914(void) {
    /* Forward to the arena-event master (lbl_8055E744) via its f10 vtable slot. */
    ((Dummy_801B8318 *)lbl_8055E744)->f10();
}
#pragma cplusplus on
#pragma scheduling invalid_target
/* Forward a per-slot request to the arena master's f42 vtable method, which
 * validates it (the tail call returns its status: nonzero rejects the request). */
extern "C" void fn_801B8928(void *slotIndex, void *request, void *flags) {
    ((Dummy_801B8318 *)lbl_8055E744)->f42(slotIndex, request, flags);
}
#pragma scheduling on
#pragma cplusplus off
/* Returns element @p index of the shared float array at lbl_80436D08. */
float fn_801B8950(int index) {
    extern float lbl_80436D08[];
    return lbl_80436D08[index];
}

extern float lbl_80436D08[];
/* Sets element @p index of the shared float array at lbl_80436D08 to @p value. */
void fn_801B8964(int index, float value) {
    lbl_80436D08[index] = value;
}

#pragma cplusplus on
#pragma cplusplus on
extern "C" void fn_801B8978(void) {
    /* Forward the f25() virtual call to the arena-event master object (lbl_8055E744). */
    ((Dummy_801B8318 *)lbl_8055E744)->f25();
}
#pragma cplusplus on
extern "C" void fn_801B898C(void) {
    /* Forward the f26() virtual call to the arena-event master object lbl_8055E744. */
    ((Dummy_801B8318 *)lbl_8055E744)->f26();
}
#pragma cplusplus off
extern int fn_80128668(void);
extern void* lbl_8055E744;
#pragma cplusplus on
extern "C" void fn_801B89A0(void) {
    /* Forward the f27() virtual call to the arena-event master object lbl_8055E744. */
    ((Dummy_801B8318 *)lbl_8055E744)->f27();
}
#pragma cplusplus on
extern "C" void fn_801B89B4(void) {
    /* Forward the f28() virtual call to the arena-event master object lbl_8055E744. */
    ((Dummy_801B8318 *)lbl_8055E744)->f28();
}
#pragma cplusplus on
extern "C" void fn_801B89C8(void *obj) {
    /* Forward obj to the arena-event master (lbl_8055E744) via its f29 vtable slot. */
    ((Dummy_801B8318 *)lbl_8055E744)->f29(obj);
}
#pragma cplusplus off
int fn_801B89E0(void) {
    /* True once the mode timer has passed the intro-end threshold. */
    extern float lbl_8055E750;
    extern float lbl_8056274C;
    return lbl_8055E750 > lbl_8056274C;
}

int fn_801B89F8(void) {
    /* True once the mode timer (lbl_8055E750) has passed the intro-end
     * threshold (lbl_8056274C). */
    extern float lbl_8055E750;
    extern float lbl_8056274C;
    return lbl_8055E750 > lbl_8056274C;
}

extern float lbl_8055E750;
extern float lbl_8056274C;
extern void fn_801CB6B4(int, int, int);
/* Callback adapter: ignores its user-data pointer and forwards the id and event id to the event gate with event category 2. */
void fn_801B8A10(void* context, int id, int eventId) {
    fn_801CB6B4(id, eventId, 2);
}

#pragma cplusplus on
extern "C" int fn_801B8A20(void *obj) {
    /* While the arena-event master is active (lbl_8055E748), forward to obj's
       virtual slot 0x1C and return its answer; otherwise return 0. */
    struct ZoneTarget {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual int slot1C();
    };
    if (*(unsigned char *)&lbl_8055E748 != 0) {
        return ((ZoneTarget *)obj)->slot1C();
    }
    return 0;
}
/* While an arena event is active (lbl_8055E748), ask obj through virtual slot 0x20
 * and return its answer; when no event is running, return 0. */
extern "C" int fn_801B8A44(void *obj) {
    struct ForwardTarget {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void d4();
        virtual void d5();
        virtual int slot20();
    };
    if (*(unsigned char *)&lbl_8055E748 != 0) {
        return ((ForwardTarget *)obj)->slot20();
    }
    return 0;
}
#pragma cplusplus off
/* Callback adapter: ignores the owner/context pointer and forwards the slot index
 * to fn_801B0C78, which builds and submits the request for that slot. */
void fn_801B8A68(void *owner, int slotIndex) {
    extern void fn_801B0C78(void *);
    fn_801B0C78((void *)slotIndex);
}

/* Callback adapter: ignores the context pointer and forwards (item index, payload)
 * to fn_801B0F70, which builds and submits a request for that item. */
void fn_801B8A70(void *ctx, int itemIndex, int payload) {
    extern void fn_801B0F70(int, int);
    fn_801B0F70(itemIndex, payload);
}

/* Callback adapter: ignores the context pointer and forwards the summary-buffer
 * pointer to fn_801B2C70, which fills a competitor result table there. */
void fn_801B8A7C(void *ctx, int buffer) {
    extern void fn_801B2C70(void *);
    fn_801B2C70((void *)buffer);
}

/* Callback: create the default "csubtasktmgr" (challenge sub-task manager).
 * The zero argument selects fn_8013C9F4's default-construction path. */
void fn_801B8A84(void) {
    extern void fn_8013C9F4(int);
    fn_8013C9F4(0);
}

int fn_801B8A8C(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Default boolean method for the arena-event master: reports true (1). */
int fn_801B8ACC(void) { return 1; }

void fn_801B8AD4(void) {

}

void fn_801B8AD8(void) {

}

/* Null arena-event master virtual method (lbl_8033678C slot +0x20): reports true (1). */
int fn_801B8ADC(void) { return 1; }

/* Null arena-event master virtual method (vtable lbl_8033678C slot +0x24).
 * The "null_amaster" has no event data, so it reports a zero/false status. */
int fn_801B8AE4(void) { return 0; }

void fn_801B8AEC(void) {

}

void fn_801B8AF0(void) {

}

void fn_801B8AF4(void) {

}

void fn_801B8AF8(void) {

}

void fn_801B8AFC(void) {

}

float fn_801B8B00(void) { return lbl_8056274C; }

extern int fn_800167F4(void);
/* Returns a status flag word: 0x160B when the stored record count exceeds one,
 * otherwise 0x564B. */
int fn_801B8B08(void) {
    int recordCount = fn_800167F4();
    int statusFlags;
    if (recordCount > 1) {
        statusFlags = 0x160B;
    } else {
        statusFlags = 0x564B;
    }
    return statusFlags;
}

int fn_801B8B38(void) { return 1; }

/* Null arena-event master virtual method ("null_amaster" vtable lbl_8033678C,
 * slot +0x28): reports true (1) as its default boolean result. */
int fn_801B8B40(void) { return 1; }

int fn_801B8B48(void) { return 1; }

/* Constant "return false" stub, alongside the always-true stubs fn_801B8B38,
 * fn_801B8B40 and fn_801B8B48; a default boolean method result. */
int fn_801B8B50(void) { return 0; }

