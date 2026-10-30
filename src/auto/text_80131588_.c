// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"
#include "revolution/MTX/mtxtypes.h"

extern char lbl_80559B10[], lbl_80559B18[], lbl_80559B1C[];
extern char lbl_8032B7BC[], lbl_8032B73C[];
extern int sscanf(const char*, ...);

extern s32 fn_80128668(void);
extern int stricmp(const char*, const char*);
extern s32 fn_80131C88(void *, const char *);
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
        register void *vtable0 = lbl_8032B64C;
        register void *vtable1 = lbl_8032B574;
        register void **obj;
        register void *zero = 0;
        ((void* volatile*)lbl_8042F53C)[0] = vtable0;
        ((void* volatile*)lbl_8042F53C)[0] = vtable1;
        obj = lbl_8042F53C;
        ((void* volatile*)obj)[5] = zero;
        ((void* volatile*)obj)[1] = &lbl_80559B0C;
        ((void* volatile*)obj)[2] = &lbl_80559B08;
        ((void* volatile*)obj)[3] = zero;
        ((void* volatile*)obj)[4] = zero;
        ((void* volatile*)obj)[5] = zero;
        ((void* volatile*)obj)[6] = zero;
        __register_global_object(obj, (void (*)(void*))((s32(*)(s32,s32))fn_80131920), lbl_8042F530);
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
void fn_80131960(void *arg0, void *arg1) {
    volatile u8 *obj;
    u8 *base;
    u8 b10, b13, b11, b12, b4, b7, b5, b6, bC, bF, bD, bE, b8, bB, b9, bA;
    u32 table, word4, word8;
    s32 i, count;

    obj = (volatile u8 *)arg0;
    base = (u8 *)arg1;
    b10 = obj[0x10];
    b13 = obj[0x13];
    b11 = obj[0x11];
    b12 = obj[0x12];
    obj[0x10] = b13;
    b4 = obj[4];
    b7 = obj[7];
    obj[0x13] = b10;
    b5 = obj[5];
    b6 = obj[6];
    obj[0x11] = b12;
    bC = obj[0xC];
    bF = obj[0xF];
    obj[0x12] = b11;
    bD = obj[0xD];
    bE = obj[0xE];
    obj[4] = b7;
    table = *(u32 *)((u8 *)arg0 + 0x10);
    obj[7] = b4;
    b8 = obj[8];
    bB = obj[0xB];
    obj[5] = b6;
    b9 = obj[9];
    bA = obj[0xA];
    obj[6] = b5;
    word4 = *(u32 *)((u8 *)arg0 + 4);
    *(u32 *)((u8 *)arg0 + 0x14) = 0;
    *(void **)arg0 = lbl_8032B5E0;
    *(u32 *)((u8 *)arg0 + 0x10) = table + (u32)base;
    obj[0xC] = bF;
    obj[0xF] = bC;
    obj[0xD] = bE;
    obj[0xE] = bD;
    obj[8] = bB;
    obj[0xB] = b8;
    obj[9] = bA;
    obj[0xA] = b9;

    if (word4 != 0)
        *(u32 *)((u8 *)arg0 + 4) = word4 + (u32)base;
    word8 = *(u32 *)((u8 *)arg0 + 8);
    if (word8 != 0)
        *(u32 *)((u8 *)arg0 + 8) = word8 + (u32)base;

    count = *(s32 *)((u8 *)arg0 + 0xC);
    for (i = 0; i < count; i++) {
        volatile u8 *entry;
        u8 e0, e3, e1, e2, e4, e7, e5, e6;

        entry = (volatile u8 *)(*(u32 *)((u8 *)arg0 + 0x10) + i * 8);
        e0 = entry[0];
        e3 = entry[3];
        entry[0] = e3;
        entry[3] = e0;
        e1 = entry[1];
        e2 = entry[2];
        entry[1] = e2;
        entry[2] = e1;
        e4 = entry[4];
        e7 = entry[7];
        entry[4] = e7;
        entry[7] = e4;
        e5 = entry[5];
        e6 = entry[6];
        entry[5] = e6;
        entry[6] = e5;

        *(u32 *)entry += (u32)base;
        *(u32 *)(entry + 4) += (u32)base;
        if ((s8)*(u8 *)(base + *(u32 *)(entry + 4)) == 0x7C)
            *(u32 *)(entry + 4) = (u32)fn_80131234((char *)(base + *(u32 *)(entry + 4)) + 1);
        else if ((s8)*(u8 *)(base + *(u32 *)(entry + 4)) == 0x7E)
            *(u8 *)(base + *(u32 *)(entry + 4)) = 1;
    }
}

s32 fn_80131B10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80131B50(void *arg0) {
    struct Entry {
        char *first;
        char *second;
    };
    s32 count = *(s32 *)((char *)arg0 + 0xC);
    struct Entry *entries = *(struct Entry **)((char *)arg0 + 0x10);
    s32 hash = 0xBABBA;
    s32 i;
    for (i = 0; i < count; i++) {
        char *s = entries[i].first;
        while (*s != 0) {
            hash += (s8)*s + 0xBAF;
            s++;
        }
        s = entries[i].second;
        while (*s != 0) {
            hash += (s8)*s + 0xBAF;
            s++;
        }
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
s32 fn_80131C88(void *arg0, const char *arg1) {
    char *found;
    s32 index;
    s32 offset;
    void *node;
    volatile struct { const char *name; s32 value; } key0;
        key0.name = arg1;
        key0.value = 0;
        found = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)arg0 + 0xC)) {
            if (stricmp(arg1, *(char **)(*(char **)((char *)arg0 + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)arg0 + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
    if (found == 0) {
        node = *(void **)((char *)arg0 + 0x14);
        if (node != 0) {
            volatile struct { const char *name; s32 value; } key1;
        key1.name = arg1;
        found = 0;
        key1.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)node + 0xC)) {
            if (stricmp(arg1, *(char **)(*(char **)((char *)node + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)node + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                node = *(void **)((char *)node + 0x14);
                if (node != 0) {
                    volatile struct { const char *name; s32 value; } key2;
        key2.name = arg1;
        found = 0;
        key2.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)node + 0xC)) {
            if (stricmp(arg1, *(char **)(*(char **)((char *)node + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)node + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                node = *(void **)((char *)node + 0x14);
                if (node != 0) {
                    volatile struct { const char *name; s32 value; } key3;
        key3.name = arg1;
        found = 0;
        key3.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)node + 0xC)) {
            if (stricmp(arg1, *(char **)(*(char **)((char *)node + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)node + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                node = *(void **)((char *)node + 0x14);
                if (node != 0) {
                    volatile struct { const char *name; s32 value; } key4;
        key4.name = arg1;
        found = 0;
        key4.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)node + 0xC)) {
            if (stricmp(arg1, *(char **)(*(char **)((char *)node + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)node + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                node = *(void **)((char *)node + 0x14);
                if (node != 0) {
                    volatile struct { const char *name; s32 value; } key5;
        key5.name = arg1;
        found = 0;
        key5.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)node + 0xC)) {
            if (stricmp(arg1, *(char **)(*(char **)((char *)node + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)node + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                node = *(void **)((char *)node + 0x14);
                if (node != 0) {
                    volatile struct { const char *name; s32 value; } key6;
        key6.name = arg1;
        found = 0;
        key6.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)node + 0xC)) {
            if (stricmp(arg1, *(char **)(*(char **)((char *)node + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)node + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                node = *(void **)((char *)node + 0x14);
                if (node != 0) {
                    volatile struct { const char *name; s32 value; } key7;
        key7.name = arg1;
        found = 0;
        key7.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)node + 0xC)) {
            if (stricmp(arg1, *(char **)(*(char **)((char *)node + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)node + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                node = *(void **)((char *)node + 0x14);
                if (node != 0) {
                    volatile struct { const char *name; s32 value; } key8;
        key8.name = arg1;
        found = 0;
        key8.value = 0;
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)node + 0xC)) {
            if (stricmp(arg1, *(char **)(*(char **)((char *)node + 0x10) + offset)) == 0) {
                found = (char *)*(char **)((char *)node + 0x10) + index * 8;
                break;
            }
            offset += 8;
            index++;
        }
            if (found == 0) {
                node = *(void **)((char *)node + 0x14);
                if (node != 0)
                    found = (char *)fn_80131C88(node, arg1);
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
#pragma scheduling on
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

#pragma push
#pragma scheduling invalid_target
s32 fn_8013284C(void *arg0, s32 arg1) {
    s32 count = *(s32*)((char*)arg0 + 0xC);
    if (count > 0) {
        void **entries = *(void***)((char*)arg0 + 0x10);
        s32 i = 0;
        do {
            char *name = (char*)entries[i];
            if (*name == '@') {
                if (arg1-- == 0) {
                    void *obj = *(void**)((char*)arg0 + 0x18);
                    void **vt = *(void**)obj;
                    return ((s32 (*)(void*, void*))vt[2])(obj, entries[2*i + 1]);
                }
            }
            i++;
        } while (--count);
    }
    {
        void *obj = *(void**)((char*)arg0 + 0x14);
        if (obj != NULL) {
            void **vt = *(void**)obj;
            return ((s32 (*)(void*))vt[0x18])(obj);
        }
    }
    return 0;
}
#pragma push
#pragma scheduling on
s32 fn_801328D4(void *arg0, s32 arg1) {
    char buf[0x40];
    sprintf(buf, lbl_80559B50, arg1);
    if (((s32 (*)(void *, char *))(*(void ***)arg0)[3])(arg0, buf) != 0) {
        s32 val = ((s32 (*)(void *, char *))(*(void ***)arg0)[5])(arg0, buf);
        void *ptr = *(void **)((char *)arg0 + 0x18);
        return ((s32 (*)(void *, s32))(*(void ***)ptr)[2])(ptr, val);
    }
    return 0;
}
#pragma use_lmw_stmw off
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
#pragma scheduling invalid_target
s32 fn_80132DA8(void *arg0) {
    s32 offset = 0;
    s32 sum = 0xFEEDFACE;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        char *item = (char *)*(void **)((u8 *)arg0 + 0xC) + offset;
        sum += ((s32 (*)(void *))(*(void **)((u8 *)(*(void **)item) + 0x64)))(item);
        sum += 0x123B;
        offset += 0x1C;
        i++;
    }
    return sum;
}
#pragma scheduling on
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

