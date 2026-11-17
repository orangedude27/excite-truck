// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"
#include "revolution/MTX/mtxtypes.h"

#pragma small_data off
__declspec(section ".sdata") extern char lbl_80559B10[], lbl_80559B18[];
__declspec(section ".sdata") extern char lbl_80559B1C[7];
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

/* A string-named value table: `count` entries, each a 0x1C-byte Unk131588Elem. */
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
typedef void *fn_80131960_ret;
#define fn_80131960_RETURN(x) return (fn_80131960_ret)(x)
extern fn_80131960_ret fn_80131960(void *, void *);
extern char lbl_8032B4D0[], lbl_8032B4F8[], lbl_8032B558[], lbl_8032B6B8[], lbl_8032B6E4[], lbl_8032B714[];
extern void fn_802E317C(const char*, ...);

#pragma use_lmw_stmw off
Unk131588 *fn_80131588(void *arg0, s32 arg1) {
    u32 type;
    u8 flag;
    Unk131588 *r;
    u8 *b;
    int i, j;
    int off1, off2;
    u8 t;

    r = fn_8012C370(arg0, 0x56414C54, &type, 0, 0, &flag);
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
                off1 = 0;
                for (i = 0; i < r->count; i++) {
                    Unk131588Elem *e = (Unk131588Elem *)((char *)r->elems + off1);
                    if (e != NULL) fn_80131960(e, r);
                    ((Unk131588Elem *)((char *)r->elems + off1))->parent = r;
                    off1 += 0x1C;
                }
                off1 = 0;
                for (i = 0; i < r->count; i++) {
                    char *s = ((Unk131588Elem *)((char *)r->elems + off1))->str;
                    if (s != NULL && *s != 0) {
                        int found = 0;
                        off2 = 0;
                        for (j = 0; j < r->count; j++) {
                            char *nm = ((Unk131588Elem *)((char *)r->elems + off2))->name;
                            if (stricmp(s, nm) == 0) {
                                if (i == j) fn_802E317C(lbl_8032B714, s);
                                if (found) {
                                    fn_802E317C(lbl_8032B6E4, ((char *(*)(void *))((Unk131588Elem *)((char *)r->elems + off1))->vtable[2])((Unk131588Elem *)((char *)r->elems + off1)), s);
                                }
                                found = 1;
                                ((Unk131588Elem *)((char *)r->elems + off1))->link = (Unk131588Elem *)((char *)r->elems + off2);
                            }
                            off2 += 0x1C;
                        }
                        if (!found) {
                            fn_802E317C(lbl_8032B6B8, ((char *(*)(void *))((Unk131588Elem *)((char *)r->elems + off1))->vtable[2])((Unk131588Elem *)((char *)r->elems + off1)), s);
                        }
                    }
                    off1 += 0x1C;
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
unsigned char* fn_801317F0(void* valueNode) {
    /* Value-file lookup: return the string held at +0x04 of a value node; when it
     * begins with a '$' reference marker, skip that 6-byte prefix. */
    unsigned char* text = *(unsigned char**)((char*)valueNode + 4);
    if ((int)*text == 0x24) return text + 6;
    return text;
}

/* Open the named value file ("*.val") and return its parsed VALT table
 * (Unk131588), or 0 if it cannot be fetched.  fn_80131588's second argument is
 * the quiet flag, so this variant reports "Can't get value file %s" when the
 * file is missing; fn_80131810 is the silent one.  The caller releases the
 * table with fn_80131818. */
Unk131588 *fn_80131808(const char *fileName) { return fn_80131588((void *)fileName, 0); }

void fn_80131810(s32 data) {
    /* Parse this data block through fn_80131588 with the silent flag (1), suppressing the failure report. */
    fn_80131588((void *)data, 1);
}

/* Release the parsed value-file table in `table` (loaded by fn_80131588 /
 * fn_80131808) by forwarding it to the resource decref/release path. */
void fn_80131818(void *table) {
    fn_8012C4D8(table);
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
__declspec(section ".sdata") extern char lbl_80559B24[7]; /* "%f, %f" */
__declspec(section ".sdata") extern char lbl_80559B2C[], lbl_80559B38[], lbl_80559B40[], lbl_80559B48[];
extern char lbl_8032B818[]; /* "Bad vector value \"%s\" for \"%s\" i" */
extern char lbl_8032B840[]; /* "Bad real64 value \"%s\" for \"%s\" i" */
#pragma push
#pragma scheduling invalid_target
/* Non-PC stub: logs "Attempt to call ValueFileLoadHumanReadable() from
   non-PC platform" (lbl_8032B510) via fn_802E30C8, then returns 0. */
s32 fn_8013181C(void) {
    fn_802E30C8(lbl_8032B510);
    return 0;
}
#pragma push
#pragma scheduling invalid_target
void* fn_8013184C(void) {
    if (lbl_8055E060 == 0) {
        void *tmp = (void*)lbl_8032B64C;
        ((void* volatile*)lbl_8042F53C)[0] = tmp;
        tmp = (void*)lbl_8032B574;
        ((void* volatile*)lbl_8042F53C)[0] = tmp;
        ((void* volatile*)lbl_8042F53C)[5] = 0;
        tmp = (void*)&lbl_80559B0C;
        ((void* volatile*)lbl_8042F53C)[1] = tmp;
        ((void* volatile*)lbl_8042F53C)[2] = &lbl_80559B08;
        ((void* volatile*)lbl_8042F53C)[3] = 0;
        ((void* volatile*)lbl_8042F53C)[4] = 0;
        ((void* volatile*)lbl_8042F53C)[5] = 0;
        ((void* volatile*)lbl_8042F53C)[6] = 0;
        tmp = (void*)fn_80131920;
        __register_global_object(lbl_8042F53C, (void (*)(void*))tmp, lbl_8042F530);
        lbl_8055E060 = 1;
    }
    return lbl_8042F53C;
}
#pragma pop
/* CodeWarrior deleting-destructor helper: free the object with MemFree when
 * deleting (flag > 0), then return the object pointer. */
s32 fn_801318E0(s32 object, s32 deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* CodeWarrior deleting-destructor helper for the registered global object: free it with MemFree when deleting (flag > 0), then return the object pointer. */
s32 fn_80131920(s32 object, s32 deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern char lbl_8032B5E0[];
extern s32 fn_80131234(char *);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_80131960(void *arg0, void *arg1)
{
  u8 *obj = (u8 *) arg0;
  u32 new_var3;
  u8 *base = (u8 *) arg1;
  u8 t8;
  u8 t10;
  long long new_var;
  u8 t29;
  u8 t25;
  u8 t26;
  u8 t31;
  u8 t30;
  u8 t24;
  u8 t7;
  u8 t;
  u32 v4;
  u32 v8;
  s32 i;
  u8 *new_var2;
  u32 off;
  u8 one = 1;
  t8 = obj[0x10];
  t10 = obj[0x11];
  obj[0x10] = obj[0x13];
  t29 = obj[4];
  obj[0x13] = t8;
  t25 = obj[5];
  obj[0x11] = obj[0x12];
  new_var = obj[9];
  t26 = obj[0xC];
  obj[0x12] = t10;
  t31 = obj[0xD];
  t7 = obj[7];
  obj[4] = t7;
  new_var2 = obj;
  obj[7] = t29;
  t30 = new_var2[8];
  obj[5] = new_var2[6];
  t24 = new_var;
  obj[6] = t25;
  v4 = *((u32 *) (obj + 4));
  *((u32 *) (new_var2 + 0x14)) = 0;
  *((void **) new_var2) = lbl_8032B5E0;
  *((u32 *) (obj + 0x10)) += (u32) base;
  obj[0xC] = new_var2[0xF];
  obj[0xF] = t26;
  obj[0xD] = new_var2[0xE];
  obj[0xE] = t31;
  obj[8] = new_var2[0xB];
  obj[0xB] = t30;
  obj[9] = new_var2[0xA];
  obj[0xA] = t24;
  if (v4 != 0)
  {
    *((u32 *) (new_var2 + 4)) = v4 + ((u32) base);
  }
  v8 = *((u32 *) (new_var2 + 8));
  if (v8 != 0)
  {
    *((u32 *) (new_var2 + 8)) = v8 + ((u32) base);
  }
  off = 0;
  for (i = 0; i < (*((s32 *) (new_var2 + 0xC))); i++, off += 8)
  {
    u8 *entry = (u8 *) ((*((u32 *) (new_var2 + 0x10))) + off);
    t = entry[0];
    entry[0] = entry[3];
    entry[3] = t;
    t = entry[1];
    entry[1] = entry[2];
    entry[2] = t;
    t = entry[4];
    entry[4] = entry[7];
    entry[7] = t;
    t = entry[5];
    entry[5] = entry[6];
    entry[6] = t;
    *((u32 *) entry) += (u32) base;
    new_var3 = *((u32 *) (entry + 4));
    *((u32 *) (entry + 4)) += (u32) base;
    t30 = t30;
    if (((s8) (*((u8 *) (base + new_var3)))) == 0x7C)
    {
      if (base)
      {
        *((u32 *) (entry + 4)) = (u32) fn_80131234(((char *) (base + new_var3)) + 1);
      }
      else
      {
        if (1)
        {
        }
        *((u32 *) (entry + 4)) = (u32) fn_80131234(((char *) (base + new_var3)) + 1);
      }
    }
    else
      if (((s8) (*((u8 *) (base + new_var3)))) == 0x7E)
    {
      *((u8 *) (base + new_var3)) = one;
    }
  }
  return arg0;
}
s32 fn_80131B10(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
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
            hash += (s32)0xFAC0000;
            hash -= 0x5355;
            s++;
        }
        off += 8;
    }
    return hash;
}

#pragma push
#pragma use_lmw_stmw off
extern s32 fn_80131C88(void*, const char*);
/* Return nonzero if `name` exists in this table's entries or, if not found, in its child table. */
s32 fn_80131BD0(void* table, const char* name) {
    volatile struct { const char *n; s32 v; } key;
    s32 index;
    char *found;
    s32 offset;
    key.n = name;
    key.v = 0;
    found = 0;
    index = 0;
    offset = 0;
    while (index < *(s32*)((char*)table + 0xC)) {
        if (stricmp(name, *(char**)(*(char**)((char*)table + 0x10) + offset)) == 0) {
            found = *(char**)((char*)table + 0x10) + index * 8;
            break;
        }
        offset += 8;
        index++;
    }
    if (found == 0 && *(void**)((char*)table + 0x14) != 0) {
        found = (char*)fn_80131C88(*(void**)((char*)table + 0x14), name);
    }
    return found != 0;
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
/* Looks up entry `index` of a named-value table (RealName: ValueTable_GetByIndex):
   writes the entry's name word and value word to outName/outValue, returning 1;
   returns 0 when the index is out of range. */
s32 fn_80132098(void* table, s32 index, void* outName, void* outValue) {
    u32 (*entries)[2];
    if (index >= 0 && index < *(s32*)((char*)table + 0xC)) {
        entries = (u32 (*)[2])*(u32*)((char*)table + 0x10);
        *(u32*)outName = entries[index][0];
        *(u32*)outValue = entries[index][1];
        return 1;
    }
    return 0;
}

extern char lbl_8032B764[];
#pragma cplusplus on
extern "C" s32 fn_801320D8(void *table, const char *name) {
    /* Looks up a named entry in a value table and its parent chain, aborts with an error if missing, and returns the entry's value. */
    class Dummy {
    public:
        virtual char *v0(void);
    };
    volatile struct {
        const char *name;
        s32 value;
    } key;
    s32 index;
    char *found;
    s32 offset;

    key.name = name;
    key.value = 0;
    found = NULL;
    index = 0;
    offset = 0;
    while (index < *(s32 *)((char *)table + 0xC)) {
        if (stricmp(name, *(char **)(*(char **)((char *)table + 0x10) + offset)) == 0) {
            found = *(char **)((char *)table + 0x10) + index * 8;
            break;
        }
        offset += 8;
        index++;
    }
    if (found == NULL && *(void **)((char *)table + 0x14) != NULL)
        found = ((char *(*)(void *, const char *))fn_80131C88)(*(void **)((char *)table + 0x14), name);
    if (found == NULL)
        fn_802E317C(lbl_8032B764, name, ((Dummy *)table)->v0());
    return *(s32 *)(found + 4);
}
#pragma cplusplus reset
extern int atoi(const char*);
extern int atoi();
#pragma cplusplus on
extern "C" s32 fn_801321BC(void **valueNode) {
    /* Read this value node's string and convert it to an integer. */
    class ValueNode {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual char *getString();
    };
    return atoi(((ValueNode *)valueNode)->getString());
}
#pragma cplusplus reset
extern double atof(const char*);
extern double atof(const char *);
#pragma cplusplus on
extern "C" f32 fn_801321EC(void **valueNode) {
    /* Read this value node's string and convert it to a float. */
    class ValueNode {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual char *getString();
    };
    return (f32) atof(((ValueNode *)valueNode)->getString());
}
#pragma cplusplus on
extern "C" s32 fn_80132220(void **node) {
    #define BOOL_YES_STR lbl_80559B18
    #define BOOL_TRUE_STR lbl_80559B10
    /* Returns 1 when this value node's string is "yes" or "true" (case-insensitive), else 0. */
    class ValueNode {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual char *getValue();
    };
    s32 isTrue;
    char *text = ((ValueNode *)node)->getValue();
    isTrue = 0;
    if (stricmp(text, BOOL_YES_STR) == 0 || stricmp(text, BOOL_TRUE_STR) == 0)
        isTrue = 1;
    #undef BOOL_YES_STR
    #undef BOOL_TRUE_STR
    return isTrue;
}
#pragma cplusplus reset
extern unsigned long strlen(const char*);
extern char lbl_8032B790[];
#pragma push
#pragma scheduling invalid_target
extern "C" s32 fn_80132290(void* arg0, const char* arg1, const char* arg2) {
    class Node {
    public:
        virtual char *getFirst();
        virtual void v1();
        virtual void v2();
        virtual char *getString();
    };
    const char *value = ((Node *)arg0)->getString();
    s32 index = 0;
    while ((s8)*arg2 != 0) {
        if (stricmp(arg2, value) == 0) return index;
        arg2 += strlen(arg2) + 1;
        index++;
    }
    fn_802E317C(lbl_8032B790, value, arg1, ((Node *)arg0)->getFirst());
    return -1;
}
#pragma processor 750
#pragma small_data on
#pragma cplusplus on
/* Parses a "min, max" range string from a node and returns linear interpolation by factor. */
extern "C" f32 fn_80132354(void *node, s32 index, f32 factor) {
    class A {
    public:
        virtual char *f0(); virtual void f1(); virtual void f2(); virtual char *f3();
    };
    f32 minVal;
    f32 maxVal;
    char *text = ((A *)node)->f3();
    if (sscanf(text, lbl_80559B1C, &minVal, &maxVal) != 2) {
        fn_802E317C(lbl_8032B7BC, text, index, ((A *)node)->f0());
    }
    return minVal + factor * (maxVal - minVal);
}
#pragma cplusplus off
#pragma small_data off
#pragma processor reset
extern char lbl_8032B80C[], lbl_8032B7E4[];
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80132410(void *out, void *node, const char *key) {
    /* Parse a Vec3 ("x, y, z" floats) from this node's string value (vtable slot f3);
     * on failure, report the bad value via fn_802E317C with the node name (f0). */
    class A {
    public:
        virtual char *f0(); virtual void f1(); virtual void f2(); virtual char *f3(const char *);
    };
    typedef struct { s32 x, y; } Vec2;
    typedef struct { Vec2 a; s32 z; } Vec3;
    Vec3 values;
    char *value = ((A *)node)->f3(key);
    if (sscanf(value, lbl_8032B80C, &values.a.x, &values.a.y, &values.z) != 3) {
        fn_802E317C(lbl_8032B7E4, value, key, ((A *)node)->f0());
    }
    *(Vec3 *)out = values;
}
#pragma small_data on
#pragma cplusplus on
extern "C" Vec2 fn_801324E0(void *node, s32 index) {
    /* Parse a Vec2 ("x, y") from this node's string value (vtable slot f3).
     * On parse failure, reports the bad value via fn_802E317C with the node
     * name (f0). Returns the parsed Vec2 (uninitialized on failure). */
    class A {
    public:
        virtual char *f0(); virtual void f1(); virtual void f2(); virtual char *f3();
    };
    Vec2 result;
    char *value = ((A *)node)->f3();
    if (sscanf(value, lbl_80559B24, &result.x, &result.y) != 2) {
        fn_802E317C(lbl_8032B818, value, index, ((A *)node)->f0());
    }
    return result;
}
#pragma cplusplus off
#pragma small_data off
void fn_80132584(void *arg0, void *arg1, const char *arg2) {
    typedef struct { float x, y, z; } Vec3;
    Vec3 v1, v2, v3, v4;
    void *obj = arg1;
    void *out = arg0;
    const char *value = ((const char *(**)(void *, const char *))(*(void **)obj))[5](obj, arg2);
    if (fn_8012F9E8(out, 0x30, value) != 0) {
        u8 *p = (u8 *)out;
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
    ((void (**)(Vec3 *, void *, const char *))*(void **)obj)[13](&v1, obj, lbl_80559B48);
    ((float *)out)[0] = v1.x;
    ((float *)out)[1] = v1.y;
    ((float *)out)[2] = v1.z;
    ((void (**)(Vec3 *, void *, const char *))*(void **)obj)[13](&v2, obj, lbl_80559B40);
    ((float *)out)[3] = v2.x;
    ((float *)out)[4] = v2.y;
    ((float *)out)[5] = v2.z;
    ((void (**)(Vec3 *, void *, const char *))*(void **)obj)[13](&v3, obj, lbl_80559B38);
    ((float *)out)[6] = v3.x;
    ((float *)out)[7] = v3.y;
    ((float *)out)[8] = v3.z;
    ((void (**)(Vec3 *, void *, const char *))*(void **)obj)[13](&v4, obj, lbl_80559B2C);
    ((float *)out)[9] = v4.x;
    ((float *)out)[10] = v4.y;
    ((float *)out)[11] = v4.z;
}
#pragma cplusplus on
extern "C" float fn_8013278C(void *arg0, s32 arg1) {
    class Dummy {
    public:
        virtual char *f0();
        virtual void f1();
        virtual void f2();
        virtual char *f3();
    };
    /* Read a 4-byte float property value from the object and byte-swap it; log an error if unavailable. */
    float value;
    float b;
    char *name = ((Dummy*)arg0)->f3();
    if (fn_8012F9E8(&value, 4, (const char*)name) != 0) {
        unsigned char *p = (unsigned char*)&value;
        unsigned char t0 = p[0];
        unsigned char t1 = p[1];
        p[0] = p[3]; p[3] = t0;
        p[1] = p[2]; p[2] = t1;
    } else {
        fn_802E317C(lbl_8032B840, (long)name, arg1, ((Dummy*)arg0)->f0());
    }
    return value;
}
#pragma cplusplus off

#pragma cplusplus on
extern "C" s32 fn_8013284C(void *container, s32 symbolIndex) {
    /* Look up the Nth name in the container that starts with '@' and invoke it via
     * the handler at +0x18; if not found (and no match), fall back to calling the
     * default handler at +0x14's slot 22 (or return 0 if absent). */
    class DefaultHandler {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual s32 defaultAction();
    };
    class SymbolHandler {
    public:
        virtual s32 invoke(void *);
    };
    s32 count = *(s32*)((char*)container + 0xC);
    s32 nameOffset;
    s32 index;
    index = 0;
    nameOffset = 0;
    while (index < count) {
        char *name = *(char**)(*(char**)((char*)container + 0x10) + nameOffset);
        if (*name == '@') {
            if (symbolIndex-- == 0) {
                void *handler = *(void**)((char*)container + 0x18);
                return ((SymbolHandler*)handler)->invoke(*(void**)(*(char**)((char*)container + 0x10) + index * 8 + 4));
            }
        }
        nameOffset += 8;
        index++;
    }
    {
        void *handler = *(void**)((char*)container + 0x14);
        if (handler != 0) {
            return ((DefaultHandler*)handler)->defaultAction();
        }
    }
    return 0;
}
#pragma small_data on
#pragma cplusplus on
extern "C" s32 fn_801328D4(void *arg0, s32 arg1) {
    /* Look up "@<arg1>" in arg0: if present, fetch its value and resolve it through arg0->+0x18's virtual method; otherwise return 0. */
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
struct Unk80132968Vector { s32 x, y, z; };
#pragma cplusplus on
extern "C" struct Unk80132968Vector fn_80132968(void *arg1, s32 arg2, struct Unk80132968Vector *arg3) {
    class A {
    public:
        virtual void f0(); virtual s32 f1(s32); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    };
    struct Unk80132968Vector copy;
    struct Unk80132968Vector value;
    struct Unk80132968Vector result;
    if (((A *)arg1)->f1(arg2)) {
        ((void (**)(struct Unk80132968Vector *, void *, s32))*(void **)arg1)[13](&value, arg1, arg2);
        result = value;
    } else {
        result = *arg3;
    }
    return copy = result;
}
#pragma cplusplus off

struct Unk80132AE4Value {
    struct { s32 a[9]; } matrix;
    struct Unk80132968Vector vector;
};

#pragma cplusplus on
extern "C" unsigned long long fn_80132A48(void *arg0, s32 arg1, void *arg2) {
    /* Return a 64-bit value for a keyed element, or copy the fallback value when the element is unavailable. */
    class Dummy {
    public:
        virtual s32 f0(); virtual s32 f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual unsigned long long f13(s32);
    };
    unsigned long long value;
    double result;
    if (((Dummy*)arg0)->f1() != 0) {
        value = ((Dummy*)arg0)->f13(arg1);
    } else {
        ((unsigned*) &value)[0] = ((unsigned*)arg2)[0];
        ((unsigned*) &value)[1] = ((unsigned*)arg2)[1];
    }
    result = *(double*)&value;
    return *(unsigned long long*)&result;
}
#pragma cplusplus on
extern "C" void fn_80132AE4(void *out, void *table, s32 key, void *defaultValue) {
    typedef struct { s32 a[9]; } Matrix;
    typedef struct { Matrix matrix; struct Unk80132968Vector vector; } Transform;
    class ValueTable {
    public:
        virtual void unknown0(); virtual s32 hasEntry(s32);
        virtual void unknown2(); virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
        virtual void unknown6(); virtual void unknown7(); virtual void unknown8(); virtual void unknown9();
        virtual void unknown10(); virtual void unknown11(); virtual void unknown12(); virtual void unknown13();
        virtual void unknown14(); virtual Transform getTransform(s32);
    };
    /* Copies a value table's matrix+vector transform for `key` into `out`, or the
     * caller's default transform when the table has no such entry. */
    const Transform *source = (Transform *)defaultValue;
    if (((ValueTable *)table)->hasEntry(key)) {
        const Transform &value = ((ValueTable *)table)->getTransform(key);
        source = &value;
    }
    ((Transform *)out)->matrix = source->matrix;
    ((Transform *)out)->vector = source->vector;
}
#pragma cplusplus off
typedef float f32;
typedef signed long s32;
#pragma cplusplus on
/* ValueTable real32 accessor: returns the float value the table holds for `key`,
 * or the caller's default when the table has no such entry.
 * ValueTable's vtable is dispatched through here: hasEntry at +0x0C, getReal32 at +0x4C. */
extern "C" f32 fn_80132BD0(void *table, s32 key, f32 defaultValue) {
    class ValueTable {
    public:
        virtual void unknown0x08();
        virtual s32 hasEntry(s32 key);
        virtual void unknown0x10();
        virtual void unknown0x14();
        virtual void unknown0x18();
        virtual void unknown0x1C();
        virtual void unknown0x20();
        virtual void unknown0x24();
        virtual void unknown0x28();
        virtual void unknown0x2C();
        virtual void unknown0x30();
        virtual void unknown0x34();
        virtual void unknown0x38();
        virtual void unknown0x3C();
        virtual void unknown0x40();
        virtual void unknown0x44();
        virtual void unknown0x48();
        virtual f32 getReal32(s32 key);
    };
    if (((ValueTable *)table)->hasEntry(key) != 0) {
        return ((ValueTable *)table)->getReal32(key);
    }
    return defaultValue;
}
#pragma cplusplus reset

/* ValueTable integer accessor: a virtual hook that simply yields the default
 * integer value 0 (it ignores any dispatch arguments). */
s32 fn_80132C48(void) { return 0; }

// Returns a pointer (as s32) to the 0x1C-byte record at `index` in the table,
// or 0 if it is past the end (count at +8, record array at +0xC).
s32 fn_80132C50(void* table, s32 index) {
    if (index < *(s32*)((char*)table + 8))
        return (s32)(*(char**)((char*)table + 0xC) + index * 0x1C);
    return 0;
}

#pragma push
#pragma scheduling invalid_target
s32 fn_80132C74(void *table, s32 name) {
    /* Find a string-named entry in a ValueTable by case-insensitive name and return
     * a pointer to its 0x1C-byte record; panic via lbl_8032B73C ("ValueTable \"%s\"
     * not found in %d tables") if no entry matches. */
    Unk131588 *valueTable = (Unk131588 *)table;
    s32 byteOffset = 0;
    s32 index = 0;
    while (index < valueTable->count) {
        Unk131588Elem *entry = (Unk131588Elem *)((char *)valueTable->elems + byteOffset);
        if (stricmp(entry->name, (char *)name) == 0)
            return (s32)((char *)valueTable->elems + index * 0x1C);
        byteOffset += 0x1C;
        index++;
    }
    fn_802E317C(lbl_8032B73C, (char *)name, valueTable->count);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
s32 fn_80132D1C(void *table, char *name) {
    /* Return 1 if table contains an entry whose name matches (case-insensitively), else 0. Entries are 0x1C bytes; name pointer is at +4. */
    s32 byteOffset = 0;
    s32 index = 0;
    while (index < *(s32 *)((u8 *)table + 4)) {
        char *entry = *(char **)((u8 *)table + 0xC) + byteOffset;
        if (stricmp(*(char **)(entry + 4), name) == 0)
            return 1;
        byteOffset += 0x1C;
        index++;
    }
    return 0;
}
#pragma cplusplus on
extern "C" s32 fn_80132DA8(void *container) {
    /* Compute a checksum over container items by summing each item's virtual hash result with a per-item salt. */
    class Item {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
        virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
        virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
        virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22(); virtual s32 f23();
    };
    s32 offset = 0;
    s32 checksum = 0xFEEDFACE;
    s32 index = 0;
    while (index < *(s32 *)((u8 *)container + 4)) {
        char *item = (char *)*(void **)((u8 *)container + 0xC) + offset;
        checksum += ((Item *)item)->f23();
        checksum += 0x123B;
        offset += 0x1C;
        index++;
    }
    return checksum;
}
#pragma cplusplus off
s32 fn_80132E34(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern void fn_802E317C(const char*, ...);
extern char lbl_80559B24[];
extern char lbl_8032B818[], lbl_8032B840[];
typedef struct { void** vtable; } Unk80132BD0;

