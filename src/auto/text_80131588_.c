// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"
#include "revolution/MTX/mtxtypes.h"

#pragma small_data off
__declspec(section ".sdata") extern char lbl_80559B10[], lbl_80559B18[], lbl_80559B1C[];
extern char lbl_8032B7BC[], lbl_8032B73C[];
extern int sscanf(const char*, ...);

extern s32 fn_80128668(void);
extern int stricmp(const char*, const char*);
extern s32 fn_80131C88(void *, const char *);
extern int sprintf(char *, const char *, ...);
__declspec(section ".sdata") extern char lbl_80559B50[4];
typedef struct {
    void *vtable;
    void *pad0;
    void *pad4;
    void *pad8;
    s32 (*vf3)(void *, char *);
    s32 (*vf4)(void *, char *);
    void *pad18;
} Unk801328D4;

typedef struct Unk131588Elem {
    void **vtable;
    char *name;
    char *str;
    void *pad0C;
    void *pad10;
    void *link;
    void *parent;
} Unk131588Elem;

typedef struct Unk131588 {
    void *vtable;
    s32 count;
    s32 pad8;
    Unk131588Elem *elems;
} Unk131588;

extern Unk131588 *fn_80131588(void *, s32);
extern Unk131588 *fn_8012C370();
extern void fn_80131960(void *, void *);
extern char lbl_8032B4D0[], lbl_8032B4F8[], lbl_8032B558[], lbl_8032B6B8[], lbl_8032B6E4[], lbl_8032B714[];
extern void fn_802E317C(const char*, ...);

#pragma use_lmw_stmw off
Unk131588 *fn_80131588(void *arg0, s32 arg1) {
    u32 type;
    u8 flag;
    Unk131588 *r;
    u8 *b;
    s32 i, j;
    u8 t;

    r = fn_8012C370(0x56414C54, &type, 0, 0, &flag);
    if (r != NULL) {
        if (type == 0xB) {
            if (flag != 0 && r != NULL) {
                r->vtable = lbl_8032B558;
                r->elems = (Unk131588Elem *)((char *)r + 0x10);
                b = (u8 *)r;
                t = b[4]; b[4] = b[7]; b[7] = t;
                t = b[5]; b[5] = b[6]; b[6] = t;
                t = b[8]; b[8] = b[0xB]; b[0xB] = t;
                t = b[9]; b[9] = b[0xA]; b[0xA] = t;
                for (i = 0; i < r->count; i++) {
                    Unk131588Elem *e = &r->elems[i];
                    if (e != NULL) fn_80131960(e, r);
                    r->elems[i].parent = r;
                }
                for (i = 0; i < r->count; i++) {
                    char *s = r->elems[i].str;
                    if (s != NULL && *s != 0) {
                        s32 found = 0;
                        for (j = 0; j < r->count; j++) {
                            if (stricmp(s, r->elems[j].name) == 0) {
                                if (i == j) fn_802E317C(lbl_8032B714, s);
                                if (found) {
                                    fn_802E317C(lbl_8032B6E4, ((char *(*)(void *))r->elems[i].vtable[2])(&r->elems[i]), s);
                                }
                                found = 1;
                                r->elems[i].link = &r->elems[j];
                            }
                        }
                        if (!found) {
                            fn_802E317C(lbl_8032B6B8, ((char *(*)(void *))r->elems[i].vtable[2])(&r->elems[i]), s);
                        }
                    }
                }
            }
        } else {
            fn_802E317C(lbl_8032B4D0, arg0);
        }
    } else if (arg1 == 0) {
        fn_802E317C(lbl_8032B4F8, arg0);
    }
    return r;
}
#pragma use_lmw_stmw reset
unsigned char* fn_801317F0(void* arg0) {
    unsigned char* p = *(unsigned char**)((char*)arg0 + 4);
    if ((int)*p == 0x24) return p + 6;
    return p;
}

void fn_80131808(int arg0) { fn_80131588((void *)arg0, 0); }

void fn_80131810(s32 arg0) {
    fn_80131588((void *)arg0, 1);
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
__declspec(section ".sdata") extern char lbl_80559B2C[], lbl_80559B38[], lbl_80559B40[], lbl_80559B48[];
extern char lbl_8032B818[]; /* "Bad vector value \"%s\" for \"%s\" i" */
extern char lbl_8032B840[]; /* "Bad real64 value \"%s\" for \"%s\" i" */
#pragma push
#pragma scheduling invalid_target
s32 fn_8013181C(void) {
    fn_802E30C8(lbl_8032B510);
    return 0;
}
#pragma push
#pragma scheduling invalid_target
void* fn_8013184C(void) {
    if (lbl_8055E060 == 0) {
        register void *vtable0 = (void*)lbl_8032B64C;
        register void *vtable1 = (void*)lbl_8032B574;
        register void **obj;
        register int zero = 0;
        ((void* volatile*)lbl_8042F53C)[0] = vtable0;
        ((void* volatile*)lbl_8042F53C)[0] = vtable1;
        obj = lbl_8042F53C;
        ((void* volatile*)obj)[5] = (void*)zero;
        ((void* volatile*)obj)[1] = &lbl_80559B0C;
        ((void* volatile*)obj)[2] = &lbl_80559B08;
        ((void* volatile*)obj)[3] = (void*)zero;
        ((void* volatile*)obj)[4] = (void*)zero;
        ((void* volatile*)obj)[5] = (void*)zero;
        ((void* volatile*)obj)[6] = (void*)zero;
        __register_global_object(obj, (void (*)(void*))fn_80131920, (void*)lbl_8042F530);
        lbl_8055E060 = 1;
    }
    return lbl_8042F53C;
}
#pragma pop
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

extern char lbl_8032B5E0[];
extern s32 fn_80131234(char *);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_80131960(void *arg0, void *arg1) {
    register u8 *obj = (u8 *)arg0;
    register u8 *base = (u8 *)arg1;
    register u8 t;
    register s32 i, count;

    t = obj[0x10]; obj[0x10] = obj[0x13]; obj[0x13] = t;
    t = obj[0x11]; obj[0x11] = obj[0x12]; obj[0x12] = t;
    t = obj[4]; obj[4] = obj[7]; obj[7] = t;
    t = obj[5]; obj[5] = obj[6]; obj[6] = t;
    t = obj[0xC]; obj[0xC] = obj[0xF]; obj[0xF] = t;
    t = obj[0xD]; obj[0xD] = obj[0xE]; obj[0xE] = t;
    t = obj[8]; obj[8] = obj[0xB]; obj[0xB] = t;
    t = obj[9]; obj[9] = obj[0xA]; obj[0xA] = t;

    *(u32 *)(obj + 0x14) = 0;
    *(void **)obj = lbl_8032B5E0;
    *(u32 *)(obj + 0x10) += (u32)base;
    if (*(u32 *)(obj + 4) != 0)
        *(u32 *)(obj + 4) += (u32)base;
    if (*(u32 *)(obj + 8) != 0)
        *(u32 *)(obj + 8) += (u32)base;

    count = *(s32 *)(obj + 0xC);
    for (i = 0; i < count; i++) {
        register u8 *entry = (u8 *)(*(u32 *)(obj + 0x10) + i * 8);
        t = entry[0]; entry[0] = entry[3]; entry[3] = t;
        t = entry[1]; entry[1] = entry[2]; entry[2] = t;
        t = entry[4]; entry[4] = entry[7]; entry[7] = t;
        t = entry[5]; entry[5] = entry[6]; entry[6] = t;
        *(u32 *)entry += (u32)base;
        *(u32 *)(entry + 4) += (u32)base;
        if ((s8)*(u8 *)(base + *(u32 *)(entry + 4)) == 0x7C)
            *(u32 *)(entry + 4) = (u32)fn_80131234((char *)(base + *(u32 *)(entry + 4)) + 1);
        else if ((s8)*(u8 *)(base + *(u32 *)(entry + 4)) == 0x7E)
            *(u8 *)(base + *(u32 *)(entry + 4)) = 1;
    }
}
#pragma scheduling on
#pragma use_lmw_stmw reset

s32 fn_80131B10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80131B50(void *arg0) {
    s32 count = *(s32 *)((char *)arg0 + 0xC);
    char *base = *(char **)((char *)arg0 + 0x10);
    s32 hash = 0xBABBA;
    s32 off = 0;
    s32 i;
    for (i = 0; i < count; i++) {
        char *s = *(char **)(base + off);
        while (*s != 0) {
            hash += (s8)*s + 0xBAF;
            s++;
        }
        s = *(char **)(base + off + 4);
        while (*s != 0) {
            hash += (s8)*s;
            hash += 0xFABFACAB;
            s++;
        }
        off += 8;
    }
    return hash;
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
        found = ((char *(*)(void *, const char *))fn_80131C88)(*(void **)((char *)arg0 + 0x14), name);
    }
    return found != NULL;
}

#pragma push
#pragma scheduling invalid_target
// Search a chain of value tables for the entry whose name matches (case-insensitive).
// Each table holds {name, value} pairs (8 bytes each) and links to a child table at +0x14.
// Returns a pointer to the matching entry, or NULL if no table in the chain has it.
s32 fn_80131C88(void *table, const char *name) {
    char *found;
    s32 index;
    s32 offset;
    void *child;
    volatile struct { const char *name; s32 value; } key;
        key.name = name;
        key.value = 0;
        found = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)table + 0xC)) {
            if (stricmp(name, *(char **)(*(char **)((char *)table + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)table + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
    if (found == 0) {
        child = *(void **)((char *)table + 0x14);
        if (child != 0) {
            volatile struct { const char *name; s32 value; } key;
        key.name = name;
        found = 0;
        key.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)child + 0xC)) {
            if (stricmp(name, *(char **)(*(char **)((char *)child + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)child + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                child = *(void **)((char *)child + 0x14);
                if (child != 0) {
                    volatile struct { const char *name; s32 value; } key;
        key.name = name;
        found = 0;
        key.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)child + 0xC)) {
            if (stricmp(name, *(char **)(*(char **)((char *)child + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)child + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                child = *(void **)((char *)child + 0x14);
                if (child != 0) {
                    volatile struct { const char *name; s32 value; } key;
        key.name = name;
        found = 0;
        key.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)child + 0xC)) {
            if (stricmp(name, *(char **)(*(char **)((char *)child + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)child + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                child = *(void **)((char *)child + 0x14);
                if (child != 0) {
                    volatile struct { const char *name; s32 value; } key;
        key.name = name;
        found = 0;
        key.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)child + 0xC)) {
            if (stricmp(name, *(char **)(*(char **)((char *)child + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)child + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                child = *(void **)((char *)child + 0x14);
                if (child != 0) {
                    volatile struct { const char *name; s32 value; } key;
        key.name = name;
        found = 0;
        key.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)child + 0xC)) {
            if (stricmp(name, *(char **)(*(char **)((char *)child + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)child + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                child = *(void **)((char *)child + 0x14);
                if (child != 0) {
                    volatile struct { const char *name; s32 value; } key;
        key.name = name;
        found = 0;
        key.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)child + 0xC)) {
            if (stricmp(name, *(char **)(*(char **)((char *)child + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)child + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                child = *(void **)((char *)child + 0x14);
                if (child != 0) {
                    volatile struct { const char *name; s32 value; } key;
        key.name = name;
        found = 0;
        key.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)child + 0xC)) {
            if (stricmp(name, *(char **)(*(char **)((char *)child + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)child + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                child = *(void **)((char *)child + 0x14);
                if (child != 0) {
                    volatile struct { const char *name; s32 value; } key;
        key.name = name;
        found = 0;
        key.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)child + 0xC)) {
            if (stricmp(name, *(char **)(*(char **)((char *)child + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)child + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                child = *(void **)((char *)child + 0x14);
                if (child != 0)
                    found = (char *)fn_80131C88(child, name);
            }
                }
            }
                }
            }
                }
            }
                }
            }
                }
            }
                }
            }
                }
            }
        }
    }
    return (s32)found;
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
#pragma cplusplus on
extern "C" s32 fn_801320D8(void *arg0, const char *name) {
    class Dummy {
    public:
        virtual char *v0(void);
    };
    volatile struct { const char *name; s32 value; } key;
    s32 index;
    char *found;
    s32 offset;
    key.name = name;
    key.value = 0;
    found = NULL;
    index = 0;
    offset = 0;
    while (index < *(s32 *)((char *)arg0 + 0xC)) {
        if (stricmp(name, *(char **)(*(char **)((char *)arg0 + 0x10) + offset)) == 0) {
            found = *(char **)((char *)arg0 + 0x10) + index * 8;
            break;
        }
        offset += 8;
        index++;
    }
    if (found == NULL && *(void **)((char *)arg0 + 0x14) != NULL)
        found = ((char *(*)(void *, const char *))fn_80131C88)(*(void **)((char *)arg0 + 0x14), name);
    if (found == NULL)
        fn_802E317C(lbl_8032B764, name, ((Dummy *)arg0)->v0());
    return *(s32 *)(found + 4);
}
#pragma cplusplus reset
extern int atoi(const char*);
extern int atoi();
#pragma cplusplus on
extern "C" s32 fn_801321BC(void **arg0) {
    class Dummy {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
    };
    ((Dummy *)arg0)->v3();
    return atoi();
}
#pragma cplusplus reset
extern double atof(const char*);
extern double atof(const char *);
#pragma cplusplus on
extern "C" f32 fn_801321EC(void **arg0) {
    class Dummy {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual char *v3();
    };
    return (f32) atof(((Dummy *)arg0)->v3());
}
#pragma cplusplus on
extern "C" s32 fn_80132220(void **arg0) {
    class Dummy {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual char *v3();
    };
    char *value = ((Dummy *)arg0)->v3();
    s32 result = 0;
    if (stricmp(value, lbl_80559B10) != 0 && stricmp(value, lbl_80559B18) == 0)
        result = 1;
    return result;
}
#pragma cplusplus reset
extern unsigned long strlen(const char*);
extern char lbl_8032B790[];
#pragma push
#pragma scheduling invalid_target
s32 fn_80132290(void* arg0, const char* arg1, const char* arg2) {
    void **vtable = *(void ***)arg0;
    const char *value = ((char *(*)(void *))vtable[5])(arg0);
    s32 index = 0;
    while ((s8)*arg2 != 0) {
        if (stricmp(arg2, value) == 0) return index;
        arg2 = strlen(arg2) + arg2 + 1;
        index++;
    }
    fn_802E317C(lbl_8032B790, value, arg1,
        ((char *(*)(void *))(*(void ***)((char *)*(void **)arg0 + 8)))(arg0));
    return -1;
}
#pragma pop
f32 fn_80132354(void *arg0, s32 arg1, f32 farg0) {
    f32 a, b;
    s32 name = ((s32 (*)(void *))(*(void **)((char *)*(void **)arg0 + 0x14)))(arg0);
    if (sscanf(lbl_80559B1C, &a, &b) != 2) {
        fn_802E317C(lbl_8032B7BC, name, arg1,
            ((char *(*)(void *))(*(void **)((char *)*(void **)arg0 + 8)))(arg0));
    }
    return a + farg0 * (b - a);
}

extern char lbl_8032B80C[], lbl_8032B7E4[];
#pragma push
#pragma scheduling invalid_target
void fn_80132410(void *arg0, void *arg1, const char *arg2) {
    typedef struct { s32 x, y, z; } Vector;
    Vector values;
    const char *value = ((char *(**)(void *, const char *))(*(void **)arg1))[5](arg1, arg2);
    if (sscanf(value, lbl_8032B80C, &values.x, &values.y, &values.z) != 3) {
        fn_802E317C(lbl_8032B7E4, value, arg2,
            ((char *(**)(void *))(*(void **)arg1))[2](arg1));
    }
    *(Vector *)arg0 = values;
}
#pragma pop
Vec2 fn_801324E0(void *arg0, s32 arg1) {
    Vec2 result;
    char *value = ((char *(*)(void *))(*(void **)((char *)*(void **)arg0 + 0x14)))(arg0);
    if (sscanf(value, lbl_80559B24, &result.x, &result.y) != 2) {
        fn_802E317C(lbl_8032B818, value, arg1,
            ((char *(*)(void *))(*(void **)((char *)*(void **)arg0 + 8)))(arg0));
    }
    return result;
}

#pragma push
#pragma optimize_for_size on
void fn_80132584(void *arg0, register void *arg1, const char *arg2) {
    typedef struct { float x, y, z; } Vec3;
    Vec3 v1, v2, v3, v4;
    const char *value;

    value = ((const char *(**)(void *, const char *))(*(void **)arg1))[5](arg1, arg2);
    if (fn_8012F9E8(arg0, 0x30, value) != 0) {
        u8 *p = (u8 *)arg0;
        int i;
        for (i = 0; i < 2; i++, p += 0x18) {
            u8 t;
            t = p[0]; p[0] = p[3]; p[3] = t;
            t = p[1]; p[1] = p[2]; p[2] = t;
            t = p[4]; p[4] = p[7]; p[7] = t;
            t = p[5]; p[5] = p[6]; p[6] = t;
            t = p[8]; p[8] = p[0xB]; p[0xB] = t;
            t = p[9]; p[9] = p[0xA]; p[0xA] = t;
            t = p[0xC]; p[0xC] = p[0xF]; p[0xF] = t;
            t = p[0xD]; p[0xD] = p[0xE]; p[0xE] = t;
            t = p[0x10]; p[0x10] = p[0x13]; p[0x13] = t;
            t = p[0x11]; p[0x11] = p[0x12]; p[0x12] = t;
            t = p[0x14]; p[0x14] = p[0x17]; p[0x17] = t;
            t = p[0x15]; p[0x15] = p[0x16]; p[0x16] = t;
        }
        return;
    }

    ((void (**)(Vec3 *, void *, const char *))*(void **)arg1)[13](&v1, arg1, lbl_80559B48);
    ((float *)arg0)[0] = v1.x;
    ((float *)arg0)[1] = v1.y;
    ((float *)arg0)[2] = v1.z;

    ((void (**)(Vec3 *, void *, const char *))*(void **)arg1)[13](&v2, arg1, lbl_80559B40);
    ((float *)arg0)[3] = v2.x;
    ((float *)arg0)[4] = v2.y;
    ((float *)arg0)[5] = v2.z;

    ((void (**)(Vec3 *, void *, const char *))*(void **)arg1)[13](&v3, arg1, lbl_80559B38);
    ((float *)arg0)[6] = v3.x;
    ((float *)arg0)[7] = v3.y;
    ((float *)arg0)[8] = v3.z;

    ((void (**)(Vec3 *, void *, const char *))*(void **)arg1)[13](&v4, arg1, lbl_80559B2C);
    ((float *)arg0)[9] = v4.x;
    ((float *)arg0)[10] = v4.y;
    ((float *)arg0)[11] = v4.z;
}
#pragma pop
f32 fn_8013278C(void *arg0, s32 arg1) {
    f32 a, b;
    s32 name = ((s32 (*)(void *))(*(void **)((char *)*(void **)arg0 + 0x14)))(arg0);
    if (fn_8012F9E8(&a, 4, (const char *)name) != 0) {
        u8 *p = (u8 *)&a;
        u8 t = p[0]; p[0] = p[3]; p[3] = t;
        t = p[1]; p[1] = p[2]; p[2] = t;
    } else {
        fn_802E317C(lbl_8032B840, name, arg1,
            ((char *(*)(void *))(*(void **)((char *)*(void **)arg0 + 8)))(arg0));
    }
    return a;
}
#pragma pop

#pragma cplusplus on
extern "C" s32 fn_8013284C(void *arg0, s32 arg1) {
    class Obj2 {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
        virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
        virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
        virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual s32 f22();
    };
    class Obj {
    public:
        virtual s32 f0(void*);
    };
    s32 count = *(s32*)((char*)arg0 + 0xC);
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    while (i < count) {
        char *name = *(char**)(*(char**)((char*)arg0 + 0x10) + off);
        if (*name == '@') {
            if (arg1-- == 0) {
                void *obj = *(void**)((char*)arg0 + 0x18);
                return ((Obj*)obj)->f0(*(void**)(*(char**)((char*)arg0 + 0x10) + i * 8 + 4));
            }
        }
        off += 8;
        i++;
    }
    {
        void *obj = *(void**)((char*)arg0 + 0x14);
        if (obj != 0) {
            return ((Obj2*)obj)->f22();
        }
    }
    return 0;
}
#pragma small_data on
#pragma cplusplus on
extern "C" s32 fn_801328D4(void *arg0, s32 arg1) {
    class A {
    public:
        virtual void f0(); virtual s32 f1(char *); virtual void f2(); virtual s32 f3(char *);
    };
    class B {
    public:
        virtual s32 g0(s32);
    };
    char buf[0x40];
    sprintf(buf, lbl_80559B50, arg1);
    if (((A *)arg0)->f1(buf) != 0) {
        s32 val = ((A *)arg0)->f3(buf);
        void *ptr = *(void **)((char *)arg0 + 0x18);
        return ((B *)ptr)->g0(val);
    }
    return 0;
}
#pragma cplusplus off
#pragma small_data off
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
#pragma use_lmw_stmw reset

struct Unk80132AE4Value {
    struct { s32 a[9]; } matrix;
    struct Unk80132968Vector vector;
};

#pragma cplusplus on
extern "C" unsigned long long fn_80132A48(void *arg0, s32 arg1, void *arg2) {
    class Dummy {
    public:
        virtual s32 f0(); virtual s32 f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual unsigned long long f13(s32);
    };
    unsigned long long tmp;
    double res;
    if (((Dummy*)arg0)->f1() != 0) {
        tmp = ((Dummy*)arg0)->f13(arg1);
    } else {
        tmp = *(unsigned long long*)arg2;
    }
    res = *(double*)&tmp;
    return *(unsigned long long*)&res;
}
#pragma cplusplus off
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
#pragma cplusplus on
extern "C" f32 fn_80132BD0(void *arg0, s32 arg1, f32 farg0) {
    class Dummy {
    public:
        virtual int v0();
        virtual int v1();
        virtual int v2();
        virtual int v3();
        virtual int v4();
        virtual int v5();
        virtual int v6();
        virtual int v7();
        virtual int v8();
        virtual int v9();
        virtual int v10();
        virtual int v11();
        virtual int v12();
        virtual int v13();
        virtual int v14();
        virtual int v15();
        virtual int v16();
        virtual float v17(s32);
    };
    if (((Dummy *)arg0)->v1() != 0) {
        return ((Dummy *)arg0)->v17(arg1);
    }
    return farg0;
}
#pragma cplusplus reset

s32 fn_80132C48(void) { return 0; }

s32 fn_80132C50(void* arg0, s32 arg1) {
    if (arg1 < *(s32*)((char*)arg0 + 8))
        return (s32)(*(char**)((char*)arg0 + 0xC) + arg1 * 0x1C);
    return 0;
}

#pragma push
#pragma scheduling invalid_target
s32 fn_80132C74(void *arg0, s32 arg1) {
    register s32 offset = 0;
    register s32 i = 0;
    register s32 count;
    while ((count = *(s32 *)((u8 *)arg0 + 4)), i < count) {
        char *s = *(char **)((u8 *)arg0 + 0xC) + offset;
        if (stricmp(*(char **)(s + 4), (char *)arg1) == 0)
            return (s32)(*(char **)((u8 *)arg0 + 0xC) + i * 0x1C);
        offset += 0x1C;
        i++;
    }
    fn_802E317C(lbl_8032B73C, (char *)arg1);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
s32 fn_80132D1C(void *arg0, char *arg1) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        char *s = *(char **)((u8 *)arg0 + 0xC) + offset;
        if (stricmp(*(char **)(s + 4), arg1) == 0)
            return 1;
        offset += 0x1C;
        i++;
    }
    return 0;
}
#pragma cplusplus on
extern "C" s32 fn_80132DA8(void *arg0) {
    class Item {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
        virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
        virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
        virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22(); virtual s32 f23();
    };
    s32 offset = 0;
    s32 sum = 0xFEEDFACE;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        char *item = (char *)*(void **)((u8 *)arg0 + 0xC) + offset;
        sum += ((Item *)item)->f23();
        sum += 0x123B;
        offset += 0x1C;
        i++;
    }
    return sum;
}
#pragma cplusplus off
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

