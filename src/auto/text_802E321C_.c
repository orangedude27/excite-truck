#include <stdarg.h>
#include <string.h>
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
__declspec(section ".sdata") extern char lbl_8055D1A8[];
s32 fn_802E321C(const char *arg0) {
    const char *prefix = lbl_8055D1A0;
    return strncmp(arg0, prefix, strlen(prefix)) == 0;
}

s32 fn_802E3270(s32 arg0) {
    s32 p = (s32)lbl_8055D1A8;
    s32 len = strlen((char *)p);
    s32 r = strncmp((const char *)arg0, (char *)p, len);
    return (unsigned int)__cntlzw(r) >> 5;
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

#pragma cplusplus on
extern "C" void fn_802E339C(void) {
    class V {
    public:
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void a3();
        virtual void a4();
        virtual void a5();
        virtual void a6();
        virtual void a7();
    };
    V *obj = (V *)((s32 (*)(s32))fn_802E333C)(0);
    obj->a7();
}
#pragma cplusplus off
s32 fn_802E33D0(void) { return 0; }

#pragma scheduling invalid_target
s32 fn_802E33D8(s32 arg0, const char *arg1, s32 arg2) {
    s32 offset;
    unsigned char *entry;
    if (arg0 < 0 || arg0 == -1 || arg0 > 0x10) {
        fn_802E317C(lbl_8034CF40, arg0, arg1, arg2);
    }
    offset = arg0 * 0x28;
    entry = (unsigned char *)(lbl_804DB810 + offset);
    if (entry[0x20] == 0) {
        fn_802E317C(lbl_8034CF60, arg0, entry, arg1, arg2);
    }
    return (s32)lbl_804DB810 + offset;
}
#pragma scheduling on
void fn_802E3498(void) {
    memset((void *)((char *)lbl_804DB810 + 0), 0, 0x280);
    if (lbl_8055FF18 == 0) {
        lbl_8055FF18 = fn_802E3F94();
    }
}

extern void fn_802E3550(void);
#pragma cplusplus on
extern "C" void fn_802E34DC(void) {
    class Obj {
    public:
        virtual void v0(s32);
    };
    s32 obj;
    fn_802E3550();
    obj = lbl_8055FF18;
    if (obj != 0) {
        ((Obj *)obj)->v0(1);
    }
    lbl_8055FF18 = 0;
    obj = lbl_8055FF1C;
    if (obj != 0) {
        if (obj != 0) {
            ((Obj *)obj)->v0(1);
        }
        lbl_8055FF1C = 0;
    }
}
#pragma cplusplus off
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
extern char lbl_8034CF98[];
s32 fn_802E35C0(const char *arg0, s32 arg1) {
    unsigned char *p = (unsigned char *)lbl_804DB810;
    s32 j = 0;
    s32 count;
    for (count = 16; count != 0; count--) {
        if (p[0x20] == 0) {
            char *entry = lbl_804DB810 + j * 0x28;
            entry[0x20] = 1;
            strncpy(entry, arg0, 0x20);
            *(s32 *)(entry + 0x24) = arg1;
            return j;
        }
        p += 0x28;
        j++;
    }
    fn_802E317C(lbl_8034CF98, arg0);
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
#pragma cplusplus on
extern "C" void fn_802E3734(s32 *arg0) {
    class Result {
    public:
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void a3();
        virtual void a4();
        virtual void destroy(void *);
    };
    class Entry {
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
        virtual Result *get();
    };
    s32 obj = fn_802E33D8(*arg0, lbl_8034CFB4, 0xE4);
    Entry *entry = *(Entry **)((unsigned char *)obj + 0x24);
    Result *result = entry->get();
    result->destroy(entry);
    *(void **)((unsigned char *)obj + 0x24) = 0;
    *((unsigned char *)obj + 0x20) = 0;
    *arg0 = -1;
}
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

extern char lbl_8034CFC0[];

#pragma cplusplus on
extern "C" void fn_802E3898(s32, const char *, s32 *);
extern "C" void fn_802E3804(s32 arg0, const char *arg1, s32 arg2) {
    s32 object = fn_802E33D8(arg0, lbl_8034CFB4, 0x130);
    s32 value = arg2;
    fn_802E3898(arg0, arg1, &value);
    if (value != arg2) {
        fn_802E317C(lbl_8034CFC0, arg2, object);
    }
}
#pragma use_lmw_stmw off
#pragma cplusplus on
void fn_802E3898(s32 arg0, const char *arg1, s32 *arg2) {
    class V {
    public:
        virtual s32 f0(const char *, s32);
    };
    s32 obj;
    s32 total;
    s32 result;
    s32 entry;
    s32 count;

    obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x142);
    total = *arg2;
    result = 0;
    while (total > 0) {
        entry = *(s32 *)(obj + 0x24);
        count = ((V *)entry)->f0(arg1, total - result);
        if (count < 0) {
            result = count;
            break;
        }
        if (count <= 0) {
            break;
        }
        result += count;
        arg1 += count;
    }
    *arg2 = result;
}
#pragma use_lmw_stmw reset
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
#pragma cplusplus on
extern "C" void fn_802E3990(s32 arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
    };
    s32 obj = fn_802E33D8(arg0, lbl_8034CFB4, 0x16c);
    s32 entry = *(s32 *)(obj + 0x24);
    ((Obj *)entry)->v3();
}
#pragma cplusplus off
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

extern int vsprintf(char *, const char *, va_list);
extern "C" int vsprintf(char *, const char *, va_list);
#pragma scheduling invalid_target
extern "C" void fn_802E3AD0(s32 arg0, const char *fmt, ...) {
    char buf[0x400];
    va_list args;
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    if (arg0 != -0x29A) {
        fn_802E3A64(arg0, (s32)buf, strlen(buf));
        return;
    }
    s32 *p = ((s32 *(*)(s32))fn_802E333C)(0);
    if (p != 0) {
        class Obj {
        public:
            virtual void v0();
            virtual void v1();
            virtual void v2();
            virtual void v3();
            virtual void v4();
            virtual void v5();
            virtual void v6(char *);
        };
        p = ((s32 *(*)(s32))fn_802E333C)(0);
        ((Obj *)p)->v6(buf);
    }
}
#pragma scheduling on
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

#pragma cplusplus on
extern "C" s32 fn_802E3D04(s32 arg0) {
    class V {
    public:
        virtual void a();
        virtual void b();
        virtual s32 c(s32);
    };
    V *obj = (V *)fn_802E336C();
    s32 result;
    if (obj == 0) goto fail;
    result = obj->c(arg0);
    if (result == 0) goto fail;
    result = fn_802E35C0((const char *)arg0, result);
    goto done;
fail:
    result = -1;
done:
    return result;
}
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

