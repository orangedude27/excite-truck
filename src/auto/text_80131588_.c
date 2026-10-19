// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"
#include "revolution/MTX/mtxtypes.h"

extern char lbl_80559B10[], lbl_80559B18[], lbl_80559B1C[];
extern char lbl_8032B7BC[];
extern int sscanf(const char*, ...);

extern s32 fn_80128668(void);
extern int stricmp(const char*, const char*);
extern s32 fn_80131C88(s32);
extern int sprintf(char *, const char *, ...);
extern char lbl_80559B50[];
typedef struct {
    void *vtable;
    void *pad0;
    void *pad4;
    void *pad8;
    s32 (*vf3)(void *, char *);
    s32 (*vf4)(void *, char *);
    void *pad18;
} Unk801328D4;

unsigned char* fn_801317F0(void* arg0) {
    unsigned char* p = *(unsigned char**)((char*)arg0 + 4);
    if ((int)*p == 0x24) return p + 6;
    return p;
}

extern int fn_80131588(int, int);
void fn_80131808(int arg0) { fn_80131588(arg0, 0); }

void fn_80131810(s32 arg0) {
    fn_80131588(arg0, 1);
}

void fn_80131818(void) {
    fn_8012C4D8();
}

extern void fn_802E30C8(const char*, ...);
extern const char lbl_8032B510[];
extern char lbl_8032B64C[], lbl_8032B574[], lbl_8042F530[];
extern int lbl_80559B08, lbl_80559B0C;
extern signed char lbl_8055E060;
extern void* lbl_8042F53C[];
extern s32 fn_80131920(s32, s32);
extern void __register_global_object(void*, void (*)(void*), void*);
extern void fn_802E317C(const char*, ...);
extern s32 fn_8012F9E8(void*, s32, const char*);
extern char lbl_80559B24[]; /* "%f, %f" */
extern char lbl_8032B818[]; /* "Bad vector value \"%s\" for \"%s\" i" */
extern char lbl_8032B840[]; /* "Bad real64 value \"%s\" for \"%s\" i" */
s32 fn_8013181C(void) {
    fn_802E30C8(lbl_8032B510);
    return 0;
}
void* fn_8013184C(void) {
    if (lbl_8055E060 == 0) {
        ((void* volatile*)lbl_8042F53C)[0] = lbl_8032B64C;
        ((void* volatile*)lbl_8042F53C)[0] = lbl_8032B574;
        ((void* volatile*)lbl_8042F53C)[5] = 0;
        ((void* volatile*)lbl_8042F53C)[1] = &lbl_80559B0C;
        ((void* volatile*)lbl_8042F53C)[2] = &lbl_80559B08;
        ((void* volatile*)lbl_8042F53C)[3] = 0;
        ((void* volatile*)lbl_8042F53C)[4] = 0;
        ((void* volatile*)lbl_8042F53C)[5] = 0;
        ((void* volatile*)lbl_8042F53C)[6] = 0;
        __register_global_object(lbl_8042F53C, (void (*)(void*))((s32(*)(s32,s32))fn_80131920), lbl_8042F530);
        lbl_8055E060 = 1;
    }
    return lbl_8042F53C;
}

s32 fn_801318E0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80131920(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80131B10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80131B50(void* arg0) {
    s32 count = *(s32*)((char*)arg0 + 0xC);
    s32 h = 0xBABBA;
    s32 i = 0;
    if (count > 0) {
        do {
            char* s = *(char**)((char*)arg0 + 0x10 + i);
            char* c;
            do {
                c = s++;
                h = h * 33 + (s8)*c;
            } while (*c);
            s = *(char**)((char*)arg0 + 0x10 + i + 4);
            do {
                c = s++;
                h = h * 33 + (s8)*c;
            } while (*c);
            i += 8;
        } while (--count);
    }
    return h;
}

#pragma push
#pragma use_lmw_stmw off
s32 fn_80131BD0(void* arg0, const char* name) {
    s32 index = 0;
    char* found = NULL;
    s32 offset = 0;
    while (index < *(s32*)((char*)arg0 + 0xC)) {
        char* t = *(char**)((char*)arg0 + 0x10);
        if (stricmp(name, t + offset) == 0) {
            found = *(char**)((char*)arg0 + 0x10) + index * 8;
            break;
        }
        offset += 8;
        index++;
    }
    if (found == NULL && *(void**)((char*)arg0 + 0x14) != NULL) {
        found = (char*)fn_80131C88((s32)name);
    }
    return found != NULL;
}
#pragma pop
s32 fn_80132098(void* arg0, s32 index, void* dst1, void* dst2) {
    u32 (*base)[2];
    if (index >= 0 && index < *(s32*)((char*)arg0 + 0xC)) {
        base = (u32 (*)[2])*(u32*)((char*)arg0 + 0x10);
        *(u32*)dst1 = base[index][0];
        *(u32*)dst2 = base[index][1];
        return 1;
    }
    return 0;
}

extern char lbl_8032B764[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
s32 fn_801320D8(void* arg0, const char* name) {
    volatile struct { const char* name; s32 value; } key;
    s32 index;
    char* found;
    s32 offset;
    key.name = name;
    key.value = 0;
    found = NULL;
    index = 0;
    offset = 0;
    while (index < *(s32*)((char*)arg0 + 0xC)) {
        if (stricmp(name, *(char**)(*(char**)((char*)arg0 + 0x10) + offset)) == 0) {
            found = *(char**)((char*)arg0 + 0x10) + index * 8;
            break;
        }
        offset += 8;
        index++;
    }
    if (found == NULL && *(void**)((char*)arg0 + 0x14) != NULL)
        found = ((char* (*)(void*, const char*))fn_80131C88)(*(void**)((char*)arg0 + 0x14), name);
    if (found == NULL)
        fn_802E317C(lbl_8032B764, name,
            ((char* (*)(void*))(*(void**)((char*)*(void**)arg0 + 8)))(arg0));
    return *(s32*)(found + 4);
}
#pragma pop
extern int atoi(const char*);
extern int atoi();
s32 fn_801321BC(void **arg0) {
    volatile void **vtable = (volatile void **)*arg0;
    ((s32 (*)(void))vtable[5])();
    return atoi();
}

extern double atof(const char*);
f32 fn_801321EC(void *arg0) {
    char *(* volatile get)(void) = (char *(*)(void))(*(void **)((char *)*(void **)arg0 + 0x14));
    return (f32) atof(get());
}

s32 fn_80132220(void* arg0) {
    char* value = ((char* (*)(void*))(*(void**)((char*)*(void**)arg0 + 0x14)))(arg0);
    s32 result = 0;
    if (stricmp(value, lbl_80559B18) != 0 && stricmp(value, lbl_80559B10) == 0)
        result = 1;
    return result;
}

extern unsigned long strlen(const char*);
extern char lbl_8032B790[];
#pragma push
#pragma use_lmw_stmw off
s32 fn_80132290(void* arg0, const char* arg1, const char* arg2) {
    const char* value = ((char* (*)(void*))(*(void**)((char*)*(void**)arg0 + 0x14)))(arg0);
    s32 index = 0;
    while ((s8)*arg2 != 0) {
        if (stricmp(arg2, value) == 0) return index;
        arg2 = &arg2[strlen(arg2)] + 1;
        index++;
    }
    fn_802E317C(lbl_8032B790, value, arg1,
        ((char* (*)(void*))(*(void**)((char*)*(void**)arg0 + 8)))(arg0));
    return -1;
}

extern char lbl_8032B80C[], lbl_8032B7E4[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_80132410(void* arg0, void* arg1, const char* arg2) {
    typedef struct { s32 x,y,z; } Vector;
    Vector values;
    const char* value = ((char* (**)(void*, const char*))(*(void**)arg1))[5](arg1, arg2);
    if (sscanf(value, lbl_8032B80C, &values.x, &values.y, &values.z) != 3) {
        fn_802E317C(lbl_8032B7E4, value, arg2,
            ((char* (**)(void*))(*(void**)arg1))[2](arg1));
    }
    *(Vector*)arg0 = values;
}

Vec2 fn_801324E0(void *arg0, s32 arg1) {
    Vec2 result;
    char *value = ((char *(*)(void *))(*(void **)((char *)*(void **)arg0 + 0x14)))(arg0);
    if (sscanf(value, lbl_80559B24, &result.x, &result.y) != 2) {
        fn_802E317C(lbl_8032B818, value, arg1,
            ((char *(*)(void *))(*(void **)((char *)*(void **)arg0 + 8)))(arg0));
    }
    return result;
}

#pragma pop

#pragma pop
s32 fn_8013284C(void *arg0, s32 arg1) {
    s32 count;
    s32 i;
    void** entries;
    char* name;
    void* obj;

    count = *(s32*)((char*)arg0 + 0xC);
    if (count > 0) {
        entries = *(void***)((char*)arg0 + 0x10);
        i = 0;
        do {
            name = entries[i];
            if (*name == '@') {
                if (arg1-- == 0) {
                    obj = *(void**)((char*)arg0 + 0x18);
                    return (*(s32(**)(void*, void*))(*(s32*)obj + 12))(obj, entries[2 * i + 1]);
                }
            }
            i++;
        } while (--count);
    }
    obj = *(void**)((char*)arg0 + 0x14);
    if (obj == NULL) {
        return 0;
    }
    return (*(s32(**)(void*))(*(s32*)obj + 24))(obj);
}

s32 fn_801328D4(void *arg0, s32 arg1) {
    char buf[0x20];
    s32 (*vtable[8])(void *, char *);
    *(void ***)vtable = *(void ***)arg0;
    if (vtable[3](arg0, buf) != 0) {
        void *ptr = *(void **)((char *)arg0 + 0x18);
        s32 (*vt2[4])(void *, s32);
        *(void ***)vt2 = *(void ***)ptr;
        return vt2[2](ptr, vtable[5](arg0, buf));
    }
    return 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
struct Unk80132968Vector { s32 x, y, z; } fn_80132968(void *arg1, s32 arg2, struct Unk80132968Vector *arg3) {
    struct Unk80132968Vector copy;
    struct Unk80132968Vector result;
    struct Unk80132968Vector value;
    if (((s32 (**)(void *, s32))*(void **)arg1)[3](arg1, arg2)) {
        ((void (**)(struct Unk80132968Vector *, void *, s32))*(void **)arg1)[13](&value, arg1, arg2);
        result = value;
    } else {
        result = *arg3;
    }
    return copy = result;
}
#pragma pop

struct Unk80132AE4Value {
    struct { s32 a[9]; } matrix;
    struct Unk80132968Vector vector;
};

u64 fn_80132A48(void *arg0, s32 arg1, void *arg2) {
    u64 result;
    if (((s32 (**)(void *))(*(void **)arg0))[3](arg0) != 0) {
        result = ((u64 (**)(void *, s32))(*(void **)arg0))[15](arg0, arg1);
    } else {
        result = *(u64 *)arg2;
    }
    return result;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_80132AE4(void* arg0, void* arg1, s32 arg2, void* arg3) {
    typedef struct { s32 a[9]; } Matrix;
    typedef struct { Matrix matrix; struct Unk80132968Vector vector; } Value;
    Value value;
    Value* source = arg3;
    if (((s32 (**)(void*, s32))*(void**)arg1)[3](arg1, arg2)) {
        ((void (**)(Value*, void*, s32))*(void**)arg1)[17](&value, arg1, arg2);
        source = &value;
    }
    ((Value*)arg0)->matrix = source->matrix;
    ((Value*)arg0)->vector = source->vector;
}

typedef float f32;
typedef signed long s32;
f32 fn_80132BD0(void *arg0, s32 arg1, f32 farg0) {
    if (((s32 (*)(void *))(*(void ***)arg0)[3])(arg0) != 0) {
        return ((f32 (*)(void *, s32))(*(void ***)arg0)[19])(arg0, arg1);
    }
    return farg0;
}

#pragma pop

s32 fn_80132C48(void) { return 0; }

s32 fn_80132C50(void* arg0, s32 arg1) {
    if (arg1 < *(s32*)((char*)arg0 + 8))
        return (s32)(*(char**)((char*)arg0 + 0xC) + arg1 * 0x1C);
    return 0;
}

s32 fn_80132D1C(void *arg0, char *arg1) {
    s32 i = 0;
    s32 offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        char *s = *(char **)((u8 *)arg0 + 0xC) + offset;
        if (stricmp(*(char **)(s + 4), arg1) == 0)
            return 1;
        offset += 0x1C;
        i++;
    }
    return 0;
}

s32 fn_80132DA8(void *arg0) {
    s32 offset = 0;
    s32 i = 0;
    s32 sum = 0xFEEDFACE;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        char *item = (char *)*(void **)((u8 *)arg0 + 0xC) + offset;
        sum += ((s32 (*)(void *))(*(void **)(item + 0x64)))(item) + 0x123B;
        offset += 0x1C;
        i++;
    }
    return sum;
}

s32 fn_80132E34(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern void fn_802E317C(const char*, ...);
extern char lbl_80559B24[];
extern char lbl_8032B818[], lbl_8032B840[];
typedef struct { void** vtable; } Unk80132BD0;

