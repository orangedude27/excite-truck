typedef signed long s32;
typedef s32 (*UnkFunc)(s32);
typedef struct CallbackObject { void **vtable; } CallbackObject;
typedef void (*CallbackMethod)(CallbackObject *, s32);
extern void fn_802E317C(const char *, ...);
extern char lbl_8034CF40[];
extern char lbl_8034CF60[];
extern char lbl_804DB810[];
extern char lbl_8055D1A0[];
extern s32 lbl_8055FF20;
extern s32 fn_802E321C(const char *);
extern s32 fn_802E3270(s32);
extern s32 fn_802E32C4(s32);
extern s32 lbl_8055FF18;
extern s32 lbl_8055FF1C;

extern char lbl_8034CFB4[];
extern char lbl_8034D000[];
extern s32 fn_802E33D8(s32, const char *, s32);
#pragma cplusplus on
class Dummy_802E367C {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 f3(s32);
    virtual s32 f4(s32, s32);
};
#pragma cplusplus off

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055FF24;
s32 fn_802E98C8(void);
#pragma small_data on
__declspec(section ".sdata") extern char lbl_8055D1A0[];
s32 fn_802E321C(const char *arg0) {
    const char *prefix = lbl_8055D1A0;
    return strncmp(arg0, prefix, strlen(prefix)) == 0;
}

#pragma dont_inline on
s32 fn_802E32C4(s32 arg0) {
    if (arg0 != 0 && fn_802E321C((const char *)arg0) != 0 && lbl_8055FF20 != 0) {
        return lbl_8055FF20;
    }
    if (arg0 != 0 && fn_802E3270(arg0) != 0 && (s32)lbl_8055FF24 != 0) {
        return (s32)lbl_8055FF24;
    }
    return 0;
}
#pragma dont_inline reset
s32 *fn_802E333C(void) {
    s32 *temp_r3;
    temp_r3 = (s32 *)((s32 (*)())fn_802E32C4)();
    if (temp_r3 != 0) {
        return temp_r3;
    }
    return (s32 *)lbl_8055FF18;
}

s32 *fn_802E336C(void) {
    s32 *temp_r3;
    temp_r3 = (s32 *)((s32 (*)())fn_802E32C4)();
    if (temp_r3 != 0) {
        return temp_r3;
    }
    return (s32 *)lbl_8055FF1C;
}

#pragma dont_inline on
void fn_802E339C(void) {
    s32 *p = ((s32 *(*)())fn_802E333C)(0);
    ((void (*)(void))(*(s32 **)p)[9])();
}
#pragma dont_inline reset
s32 fn_802E33D0(void) { return 0; }

void fn_802E3498(void) {
    memset((void *)((char *)lbl_804DB810 + 0), 0, 0x280);
    if (lbl_8055FF18 == 0) {
        lbl_8055FF18 = fn_802E3F94();
    }
}

extern void fn_802E3550(void);
void fn_802E34DC(void) {
    s32 obj;
    fn_802E3550();
    obj = lbl_8055FF18;
    if (obj != 0) {
        ((void (*)(s32, s32))(*(s32 *)(*(s32 *)obj + 8)))(obj, 1);
    }
    lbl_8055FF18 = 0;
    obj = lbl_8055FF1C;
    if (obj != 0) {
        if (obj != 0) {
            ((void (*)(s32, s32))(*(s32 *)(*(s32 *)obj + 8)))(obj, 1);
        }
        lbl_8055FF1C = 0;
    }
}

extern char lbl_8034CF80[];
#pragma scheduling invalid_target
void fn_802E3550(void) {
    char *entry;
    s32 i;

    entry = lbl_804DB810;
    i = 0;
    do {
        if (((unsigned char *)entry)[0x20] != 0) {
            fn_802E317C(lbl_8034CF80, (s32)entry);
        }
        i++;
        entry += 0x28;
    } while (i < 16);
}
#pragma scheduling on
s32 fn_802E35C0(const char *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < 16; i++) {
        char *entry = lbl_804DB810 + i * 0x28;
        if (((unsigned char *)entry)[0x20] == 0) {
            entry[0x20] = 1;
            strncpy(entry, arg0, 0x20);
            *(s32 *)(entry + 0x24) = arg1;
            return i;
        }
    }
    fn_802E317C(lbl_8034CF40 + 0x58, arg0);
    return -1;
}

#pragma dont_inline on
#pragma cplusplus on
extern "C" s32 fn_802E367C(s32 arg0) {
    class V {
    public:
        virtual void a();
        virtual s32 b(s32);
    };
    V *obj = (V *)fn_802E333C();
    s32 result = obj->b(arg0);
    if (result != 0)
        return fn_802E35C0((const char *)arg0, result);
    return -1;
}
#pragma cplusplus on
extern "C" s32 fn_802E36D8(s32 arg0) {
    class V {
    public:
        virtual void a();
        virtual void b();
        virtual s32 c(s32);
    };
    V *obj = (V *)fn_802E333C();
    s32 result = obj->c(arg0);
    if (result != 0)
        return fn_802E35C0((const char *)arg0, result);
    return -1;
}
#pragma cplusplus off
void fn_802E3734(s32 *arg0) {
    s32 obj = fn_802E33D8(*arg0, lbl_8034CFB4, 0xE4);
    s32 entry = *(s32 *)(obj + 0x24);
    ((void (*)(s32))(*(s32 *)entry + 0x2C))(entry);
    ((void (*)(s32, s32))(*(s32 *)entry + 0x1C))(entry, entry);
    *(s32 *)(obj + 0x24) = 0;
    *((unsigned char *)obj + 0x20) = 0;
    *arg0 = -1;
}

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802E37C4(s32 arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
    };

    s32 obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x125);
    s32 entry = *(s32 *)(obj + 0x24);
    ((Obj *)entry)->v4();
}
#pragma cplusplus off
#pragma scheduling on
void fn_802E3898(s32 arg0, const char *arg1, s32 *arg2) {
    s32 total;
    s32 result;
    s32 obj;
    s32 entry;
    s32 count;
    total = *arg2;
    obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x142);
    result = 0;
    if (total > 0) {
        do {
            entry = *(s32 *)(obj + 0x24);
            count = ((s32 (*)(s32, const char *, s32))(*(s32 *)entry + 8))(entry, arg1, total - result);
            if (count < 0) { result = count; break; }
            if (count <= 0) break;
            result += count;
            arg1 += count;
        } while (total > 0);
    }
    *arg2 = result;
}

#pragma cplusplus on
extern "C" void fn_802E3930(s32 arg0, s32 arg1, s32 arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2(int, int);
    };
    s32 obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x15e);
    s32 entry = *(s32 *)(obj + 0x24);
    ((Obj *)entry)->v2(arg1, arg2);
}
#pragma cplusplus off
void fn_802E3990(s32 arg0) {
    s32 obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x16c);
    s32 entry = *(s32 *)(obj + 0x24);
    ((void (*)(s32))(*(s32 **)entry)[5])(entry);
}

s32 fn_802E39D0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp8 = arg2;
    fn_802E3898(arg0, (const char *)arg1, &sp8);
    return sp8 == arg2;
}

#pragma cplusplus on
extern "C" void fn_802E3A14(s32 arg0, s32 arg1) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v5();
        virtual void v4();
        virtual void v8(s32);
        virtual void v7();
        virtual void v6();
    };
    register int obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x1ab);
    s32 entry = *(s32 *)(obj + 0x24);
    ((Obj *)entry)->v8(arg1);
}
#pragma cplusplus on
extern "C" s32 fn_802E3A64(s32 arg0, s32 arg1, s32 arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual s32 v1(s32, s32);
    };
    s32 obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x1c3);
    s32 entry = *(s32 *)(obj + 0x24);
    s32 result = ((Obj *)entry)->v1(arg1, arg2);
    return arg2 == result;
}

#pragma cplusplus on
extern "C" s32 fn_802E3BB4(s32 arg0, s32 arg1, s32 arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual s32 v2(s32, s32, s32);
    };

    s32 obj = ((s32 (*)(void))fn_802E339C)();
    s32 result;
    if (obj != 0) {
        result = ((Obj *)obj)->v2(arg0, arg1, arg2);
    } else {
        result = -1;
    }
    return result;
}

extern char lbl_8034CFE4[];
#pragma cplusplus on
extern "C" s32 fn_802E3C24(s32 arg0, s32 arg1, s32 arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual s32 v3(s32, s32, s32);
    };
    s32 obj = ((s32 (*)(void))fn_802E339C)();
    s32 result;
    if (obj != 0) {
        result = ((Obj *)obj)->v3(arg0, arg1, arg2);
    } else {
        fn_802E317C(lbl_8034CFE4);
        result = 0;
    }
    return result;
}
#pragma cplusplus off

#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_802E3CA4(s32 arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4(s32);
    };

    s32 result = ((s32 (*)(void))fn_802E339C)();
    if (result != 0) {
        ((Obj *)result)->v4(arg0);
    } else {
        fn_802E317C(lbl_8034D000);
    }
}
#pragma cplusplus off

#pragma cplusplus off
void fn_802E3D00(void) {
}

s32 fn_802E3D04(s32 arg0) {
    s32 *obj = fn_802E336C();
    s32 result;
    if (obj == 0) {
        result = -1;
    } else {
        result = ((s32 (*)(s32, s32))(*(s32 **)obj)[4])((s32)obj, arg0);
        if (result != 0) {
            result = fn_802E35C0((const char *)arg0, result);
        } else {
            result = -1;
        }
    }
    return result;
}

#pragma cplusplus on
extern "C" s32 fn_802E3D68(s32 arg0) {
    class V {
    public:
        virtual void a();
        virtual s32 b(s32);
    };
    V *obj = (V *)fn_802E336C();
    s32 result;
    if (obj == 0) goto fail;
    result = obj->b(arg0);
    if (result == 0) goto fail;
    result = fn_802E35C0((const char *)arg0, result);
    goto done;
fail:
    result = -1;
done:
    return result;
}
#pragma cplusplus off
void fn_802E3DCC(void) {
    lbl_8055FF24 = (void*)fn_802E98C8();
}

