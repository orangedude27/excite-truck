#include <types.h>
extern "C" void fn_801556F8(s32 arg0 = 0);

extern "C" void fn_801556F4(s32 arg0 = 0);

extern "C" void fn_8015536C(s32 arg0 = 0);


// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8015474C(void);
extern s32 fn_80128668(void);
extern void fn_80128668(void*);
extern void fn_80138AD8(void* this_, u32 a);
extern u8 lbl_8032E46C[];
extern u8 lbl_8032E448[];

namespace fn_c_linkage {
    extern "C" void fn_80138AD8(void *);
    extern "C" void fn_80128658(void *);
    extern "C" void fn_80128668(void *);
}

extern void **lbl_8055E27C;

namespace ebi {
namespace title {
  class TPlaneSub {
  public:
      virtual void v0();
      virtual void v1();
      virtual void v2();
      virtual void v3();
      virtual void v4();
      virtual void v5();
      virtual void v6();
      virtual void update(); // 0x20
  };

class TPlaneSubShort {
public:
    virtual void v0();
    virtual void v1();
};

class TBlackPlane {
public:
    TBlackPlane() {}
    void* m_pad; // 0x0
    TPlaneSub* m_a; // 0x4
    TPlaneSub* m_b; // 0x8
    void updateAfterCamera();
};
} // namespace title
} // namespace ebi

extern "C" {
extern "C" void fn_8015474C(s32);
void fn_80156188(s32 arg0) {
    fn_8015474C(arg0 - 4);
}

extern "C" void fn_80154750(s32);
extern "C" void fn_80154754(s32);
extern "C" void fn_80154D30(s32);
extern "C" void fn_80155368(s32);
void fn_80156190(s32 arg0) { fn_80154750(arg0 - 4); }

void fn_80156198(s32 arg0) { fn_80154754(arg0 - 4); }

void fn_801561A0(s32 arg0) { fn_80154D30(arg0 - 4); }

void fn_801561A8(s32 arg0) { fn_80155368(arg0 - 4); }

extern "C" void fn_801561B0(s32 arg0) {
    fn_8015536C(arg0 - 8);
}

extern "C" void fn_801561B8(s32 arg0) {
    fn_801556F4(arg0 - 8);
}

extern "C" void fn_801561C0(s32 arg0) {
    fn_801556F8(arg0 - 8);
}

extern "C" s32 fn_801556FC(s32);
extern "C" void fn_801561C8(s32 arg0) {
    fn_801556FC(arg0 - 0xC);
}

extern "C" s32 fn_80155700(s32);
extern "C" void fn_801561D0(s32 arg0) {
    fn_80155700(arg0 - 0xC);
}

extern "C" s32 fn_80155AEC(s32);
extern "C" void fn_801561D8(s32 arg0) {
    fn_80155AEC(arg0 - 0xC);
}

extern "C" s32 fn_80155AF0(s32);
extern "C" void fn_801561E0(s32 arg0) {
    fn_80155AF0(arg0 - 0xC);
}

extern "C" u8 *fn_80029004(void *, s32);
#pragma dont_inline fn_801561E8
extern "C" void fn_801561E8(u8 *arg0) {
    u8 *result = fn_80029004(arg0, 0x2E);
    if (result != 0) {
        *result = 0;
    }
}

extern "C" u8 lbl_8032E238[];
extern "C" char lbl_8032E248[];
extern "C" char lbl_80559FC0;
extern "C" s32 fn_801345D8(s32, s32, const char *, ...);
extern "C" s32* fn_801E87A8();
extern "C" void* fn_8001285C(s32);
#pragma dont_inline fn_8015621C
s32 fn_8015621C(void) {
    return *(s32*)((char*)fn_8001285C(*fn_801E87A8()) + 0x20);
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
s32 fn_80156248(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual char *m4(const char *, const char *);
    };
    Obj *obj = (Obj *)fn_8015621C();
    char *result = obj->m4((const char *)lbl_8032E238, (const char *)&lbl_80559FC0);
    fn_801345D8((s32)arg0, arg1, lbl_8032E248, result);
    return (s32)arg0;
}
#pragma dont_inline off
#pragma pop

extern "C" u8 *fn_801E879C(void);
extern "C" void fn_801561E8(u8 *);
extern "C" s32 fn_801345D8(s32, s32, const char *, ...);
extern "C" char lbl_8032E254[];
extern "C" char lbl_80559FC0;
extern "C" char lbl_80559FC4;
extern "C" char lbl_80559FC8;
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
/* Format a ghostcar resource path string: copy up to 0x20 bytes from the current
 * name source into a local buffer, normalize it, then append either .il0 (with an
 * optional '_' infix when a name is provided) or .ili depending on the flag. */
s32 fn_801562BC(void *out, s32 arg1, s32 nameArg, s32 useIl0Path) {
    u8 buffer[0x20];
    u8 *src = fn_801E879C();
    s32 count = 0x20;
    u8 *dst = buffer;
    u8 *name = (u8 *)nameArg;

    goto copy;
check:
    if (--count > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    if ((s8)(*dst++ = *src++) != 0)
        goto check;
done:
    fn_801561E8(buffer);
    if (useIl0Path != 0) {
        const char *infix;
        if ((s8)*name != 0)
            infix = (const char *)&lbl_80559FC4;
        else
            infix = (const char *)&lbl_80559FC0;
        fn_801345D8((s32)out, arg1, lbl_8032E254, name, infix, buffer);
    } else {
        const char *text;
        if ((s8)*name != 0)
            text = (const char *)name;
        else
            text = (const char *)buffer;
        fn_801345D8((s32)out, arg1, (const char *)&lbl_80559FC8, text);
    }
    return (s32)out;
}
#pragma dont_inline off
#pragma pop
extern s32 fn_801562BC(void*, s32, s32, s32);
extern s32 fn_80156248(void*, s32);
extern s32 fn_80138968(void*);
extern void fn_802E30C8(const char*, ...);
extern s32 fn_80138BA0(s32, s32);
extern char lbl_8032E270[];
extern char lbl_8032E2AC[];
#pragma push
#pragma scheduling invalid_target
/*
 * Loads a racing line resource by path for the given provider.
 * Tries the normal path, then a ghostcar fallback, then a centerline fallback.
 * On success, updates the resource handle from the provider; on failure returns 0.
 */
s32 fn_801563BC(s32 nameArg, void *provider) {
    struct Obj {
        virtual void v0();
        virtual s32 get(s32);
    };
    char path[0x40];
    s32 resource;

    fn_801562BC(path, 0x40, nameArg, 0);
    resource = fn_80138968(path);
    if (resource == 0) {
        fn_802E30C8(lbl_8032E270, path);
        fn_801562BC(path, 0x40, nameArg, 1);
        resource = fn_80138968(path);
    }
    if (resource == 0) {
        fn_802E30C8(lbl_8032E2AC, path);
        resource = fn_80138968((void *)fn_80156248(path, 0x40));
    } else {
        s32 value = ((Obj *)provider)->get(0);
        fn_80138BA0(resource, value);
    }
    return resource;
}
#pragma pop
extern "C" void *fn_801284F8(s32, const char *);
extern "C" void fn_8012E81C(void *);
extern "C" void fn_802E317C(const char *, ...);
extern "C" void *fn_801399FC(void);
extern "C" u8 lbl_8032E238[];
extern "C" u8 lbl_8032E424[];
extern "C" u8 lbl_8032E3F8[];
extern "C" char lbl_80559FD0;
extern "C" char lbl_80559FD4;
extern "C" char lbl_80559FD8;
extern "C" char lbl_80559FE0;
extern "C" char lbl_80559FE8;
extern "C" char lbl_80559FF0;
extern "C" f32 lbl_80561738;
extern "C" f32 lbl_8056173C;
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_801564B0(void) {
    struct Entry { s32 id; s32 kind; };
    struct Config {
        void *vtable; Entry *entries; volatile s32 count; s32 capacity;
        u8 pad10[0x80]; void **objects; s32 objectCount; s32 objectCapacity;
        u8 pad9c[0x40]; f32 value0; f32 value1;
    };
    struct Helper { void *vtable; s32 id; };
    struct Reader {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual char *read(char *, const char *);
        virtual void v5(); virtual void v6(); virtual void v7();
        virtual f32 value(const char *, f32);
        virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
        virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
        virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
        virtual Reader *open(const char *);
    };
    struct IndexReader {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21();
        virtual s32 valid(s32);
    };
    struct TextManager {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual char *get(const char *, const char *);
    };
    struct ConfigVtable {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void dispose();
    };

    u8 path[0x40];
    char input[0x10], text[0x20];
    register u8 *base = lbl_8032E238;
    register const char *format;
    register s32 line;
    register const char *suffix;
    register Entry *entry;
    register void *helper;
    register Config *resource;
    register Reader *reader;
    void *wrapper;

    fn_8012E81C(base + 0xAC);
    helper = fn_801284F8(8, (const char *)&lbl_80559FD0);
    if (helper != 0) {
        *(void **)helper = lbl_8032E46C;
        s32 helperId = fn_80138968((void *)fn_80156248(path, 0x40));
        *(s32 *)((u8 *)helper + 4) = helperId;
        if (helperId == 0)
            fn_802E317C((const char *)base + 0xBC, path);
    }

    reader = ((Reader *)(long)fn_8015621C())->open((const char *)base + 0xD8);
    if (reader != 0) {
        resource = (Config *)fn_801284F8(0x124, (const char *)&lbl_80559FD4);
        if (resource != 0) {
            resource->vtable = lbl_8032E424;
            resource->entries = (Entry *)((u8 *)resource + 0x10);
            resource->capacity = 0x10;
            resource->count = 0;
            resource->objects = (void **)((u8 *)resource + 0x9C);
            resource->objectCapacity = 0x10;
            resource->objectCount = 0;
            format = (const char *)&lbl_80559FD8;
            line = 1;
            suffix = (const char *)&lbl_80559FE8;
            for (;; ++line) {
                fn_801345D8((s32)input, 0x10, (const char *)&lbl_80559FE0, format, line);
                char *result = reader->read(input, 0);
                if (result == 0)
                    break;
                if (resource->count + 1 > resource->capacity)
                    break;
                entry = &resource->entries[resource->count++];
                entry->id = fn_801563BC((s32)result, helper);

                char *src = input;
                s32 remaining = 0x20;
                char *dst = text;
                {
                    u8 c;
                    goto copy_body;
                copy_count:
                    if (--remaining > 0) goto copy_body;
                    dst[-1] = 0;
                    goto copy_done;
                copy_body:
                    c = *src++;
                    *dst++ = c;
                    if ((s8)c != 0) goto copy_count;
                copy_done:
                    ;
                }

                dst = text;
                remaining = 0x20;
                while ((s8)*dst != 0) { remaining--; dst++; }
                if (remaining > 0) {
                    src = (char *)suffix;
                    {
                        u8 c;
                        goto suffix_body;
                    suffix_count:
                        if (--remaining > 0) goto suffix_body;
                        dst[-1] = 0;
                        goto suffix_done;
                    suffix_body:
                        c = *src++;
                        *dst++ = c;
                        if ((s8)c != 0) goto suffix_count;
                    suffix_done:
                        ;
                    }
                }

                s8 kindChar = (s8)*reader->read(text, (const char *)&lbl_80559FC0);
                s32 category;
                switch (kindChar) {
                case 0x72: category = 1; break;
                case 0x6C: category = 0; break;
                default: category = 2; break;
                }
                entry->kind = category;
            }
            if (resource->count == 0)
                fn_802E317C((const char *)base + 0xE8);

            IndexReader *list = (IndexReader *)reader->open((const char *)base + 0x128);
            if (list != 0) {
                s32 index = 0;
                goto list_test;
                do {
                    resource->objects[resource->objectCount++] = fn_801399FC();
                    index++;
                list_test:
                    if (list->valid(index) == 0) break;
                } while (resource->objectCount + 1 <= resource->objectCapacity);
            }

            {
                f32 v0 = reader->value((const char *)base + 0x144, lbl_80561738);
                resource->value0 = v0;
                f32 v1 = reader->value((const char *)base + 0x154, lbl_8056173C);
                resource->value1 = v1;
            }
            {
                s32 oc = resource->objectCount;
                const char *ocs = oc == 1 ? (const char *)&lbl_80559FC0 : (const char *)&lbl_80559FF0;
                s32 cnt = resource->count;
                const char *cs = cnt == 1 ? (const char *)&lbl_80559FC0 : (const char *)&lbl_80559FF0;
                fn_802E30C8((const char *)base + 0x168, cnt, cs, oc, ocs,
                            resource->value0, resource->value1);
            }
            ((ConfigVtable *)resource)->dispose();
        }
    } else {
        resource = (Config *)fn_801284F8(8, (const char *)&lbl_80559FD4);
        if (resource != 0) {
            resource->vtable = lbl_8032E448;
            TextManager *textManager = (TextManager *)fn_8015621C();
            char *value = textManager->get((const char *)base, (const char *)&lbl_80559FC0);
            value = textManager->get((const char *)base + 0x1A0, value);
            ((Helper *)resource)->id = fn_801563BC((s32)value, helper);
        }
    }

    wrapper = fn_801284F8(0xC, (const char *)base + 0x1B4);
    if (wrapper != 0) {
        *(void **)wrapper = lbl_8032E3F8;
        *(void **)((u8 *)wrapper + 8) = helper;
        *(void **)((u8 *)wrapper + 4) = resource;
    }
    lbl_8055E27C = (void **)wrapper;
}
#pragma scheduling on
#pragma dont_inline reset
s32 fn_801568E0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80156920(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern f32 fn_80129DC4(s32, s32, s32, f32, f32);
extern f32 lbl_8055E3C8;

#pragma push
#pragma processor 750
void fn_80156960(void *arg0) {
    /* Sample 8 values into the output buffer using modulo-indexed data and a base plus interpolated offset. */
    s32 sampledValue;
    void *out = arg0;
    s32 count = 0;
    register f32 base = lbl_8055E3C8;
    do {
        s32 divisor = ((s32 *)arg0)[2];
        s32 *data = (s32 *)((s32 *)arg0)[1];
        s32 index = count % divisor;
        f32 angle1 = ((f32 *)arg0)[0xDC / 4];
        f32 angle2 = ((f32 *)arg0)[0xE0 / 4];
        sampledValue = data[index * 2];
        ((f32 *)out)[0xE4 / 4] = base + fn_80129DC4(4, divisor, (s32)(long)data, angle1, angle2);
        *(s32 *)((u8 *)out + 0xE8) = sampledValue;
        out = (u8 *)out + 8;
        count++;
    } while ((u32)count < 8);
}
#pragma pop
void fn_801569FC(void) {
    struct Callback {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(int);
    };
    extern void **lbl_8055E27C;
    Callback *ptr = (Callback *)lbl_8055E27C;
    if (ptr != 0)
        ptr->f8(1);
    lbl_8055E27C = 0;
}

s32 fn_80156A40(void) {
    return (s32)lbl_8055E27C;
}

extern "C" void fn_80156A48(void) {
}

extern void fn_80128668(void*);
extern void **lbl_8055E27C;
extern u8 lbl_8032E46C[];
extern void fn_80138AD8(void* this_, u32 a);
void* __dt__Q28PSSystem7SeqHeapFv_80156A4C(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_8032E46C;
        fn_80138AD8((u8*)this_ + 4, (u32)lbl_8032E46C);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

s32 fn_80156AB0(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_80156AB8(void *arg0) {
    return ((s32 *)arg0)[1];
}

extern u8 lbl_8032E448[];
extern void fn_80138AD8(void* this_, u32 a);
void* __dt__Q28PSSystem7SeqHeapFv_80156AC4(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_8032E448;
        fn_80138AD8((u8*)this_ + 4, (u32)lbl_8032E448);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

s32 fn_80156B28(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_80156B30(void *arg0, s32 arg1) {
    if (arg1 == 0) return ((s32 *)arg0)[1];
    return 0;
}

}

extern "C" void fn_80156AC0(void) {
}

extern "C" void fn_80156B48(void) {
}

extern "C" void fn_80156B4C(void) {
}

extern "C" void fn_80156B50(void) {
}

extern "C" void fn_80156B54(void) {
}

extern "C" void fn_80128658(void*);
extern u8 lbl_8032E424[];
extern "C" void* fn_80156B58(void* arg0, s32 arg1) {
    struct Obj {
        void *vtable;
        void * volatile first;
        volatile s32 firstCount;
        u8 pad[0x84];
        void ** volatile items;
        volatile s32 itemCount;
        volatile s32 itemCapacity;
    };
    s32 i;
    s32 offset;
    s32 j;
    s32 offset2;
    s32 zero = 0;
    void *chk;
    if (arg0 != 0) {
        Obj *self = (Obj *)arg0;
        self->vtable = lbl_8032E424;
        i = 0;
        offset = 0;
        while (i < self->firstCount) {
            fn_c_linkage::fn_80138AD8((char *)self->first + offset);
            offset += 8;
            i++;
        }
        self->firstCount = 0;
        j = 0;
        offset2 = 0;
        while (j < self->itemCount) {
            fn_c_linkage::fn_80128658(*(void **)((char *)self->items + offset2));
            offset2 += 4;
            j++;
        }
        chk = (char *)self + 0x90;
        self->itemCount = zero;
        if (chk != 0) {
            if (chk != 0) {
                self->items = 0;
                self->itemCount = zero;
                self->itemCapacity = zero;
            }
        }
        if ((s32)self + 4 != 0) {
            if ((s32)self + 4 != 0) {
                self->first = 0;
                self->firstCount = zero;
                *(s32 *)((char *)self + 0xC) = zero;
            }
        }
        if (arg1 > 0)
            fn_c_linkage::fn_80128668(self);
    }
    return arg0;
}

extern "C" s32 fn_80156C60(void *arg0, s32 arg1) {
    if (arg1 < ((s32 *)arg0)[2])
        return *(s32 *)((u8 *)((s32 *)arg0)[1] + (arg1 * 8));
    return 0;
}

extern "C" void* fn_8017960C(s32);
extern "C" s32 fn_80139B70(s32, f32, f32);
extern "C" s32 fn_80129D90(s32, s32, s32);
extern "C" f32 fn_80129DC4(s32, s32, s32, f32, f32);
extern "C" f32 fn_801B306C(void);
extern "C" f32 lbl_80561740;
extern "C" f32 lbl_80561744;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" s32 fn_80156C84(void *arg0, s32 arg1) {
    void *self = arg0;
    s32 off = arg1 * 8;
    u8 *element = (u8 *)arg0 + off;
    f32 f31 = lbl_8055E3C8;
    if (f31 >= *(f32 *)(element + 0xE4)) {
        void *r29v = fn_8017960C(arg1);
        s32 found;
        s32 i;
        s32 offset;
        for (i = 0, offset = 0; i < *(s32 *)((u8 *)self + 0x94); offset += 4, i++) {
            f32 a = *(f32 *)((u8 *)r29v + 0x60);
            f32 b = *(f32 *)((u8 *)r29v + 0x68);
            s32 elem = *(s32 *)(*(u8 **)((u8 *)self + 0x90) + offset);
            if (fn_80139B70(elem, a, b)) {
                found = 1;
                goto check;
            }
        }
        found = !*(s32 *)((u8 *)self + 0x94);
    check:
        if (found) {
            s32 idx = fn_80129D90(4, 0, *(s32 *)((u8 *)self + 8));
            u32 *table = *(u32 **)((u8 *)self + 4);
            s32 tbl = *(s32 *)((u8 *)table + idx * 8);
            if (tbl == 0) {
                s32 next = idx + 1;
                s32 divisor = *(s32 *)((u8 *)self + 8);
                idx = next % divisor;
                tbl = *(s32 *)((u8 *)table + idx * 8);
            }
            *(f32 *)(element + 0xE4) = f31 +
                ((f32 (*)(s32, f32, f32))fn_80129DC4)(
                    4, *(f32 *)((u8 *)self + 0xDC), *(f32 *)((u8 *)self + 0xE0));
            ((s32 *)self)[arg1 * 2 + 0x3A] = tbl;
        } else {
            *(f32 *)(element + 0xE4) += lbl_80561740;
        }
    }
    if (fn_801B306C() > lbl_80561744) {
        return *(s32 *)((u8 *)self + 0xE8);
    }
    return ((s32 *)self)[arg1 * 2 + 0x3A];
}
#pragma pop
extern s32 fn_80129D90(s32, s32, s32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_80156DCC(void *arg0, s32 arg1) {
    s32 offset = arg1 * 8;
    u8 *element = (u8 *)arg0 + offset;
    f32 base;
    u32 oldValue;
    s32 count;
    s32 index;
    u32 *table;
    u32 value;
    base = lbl_8055E3C8;
    oldValue = *(u32 *)(element + 0xE8);
    count = *(s32 *)((u8 *)arg0 + 8);
    index = fn_80129D90(4, 0, count);
    table = *(u32 **)((u8 *)arg0 + 4);
    value = *(u32 *)((u8 *)table + index * 8);
    if (value == oldValue) {
        s32 next = index + 1;
        s32 divisor = *(s32 *)((u8 *)arg0 + 8);
        index = next % divisor;
        value = *(u32 *)((u8 *)table + index * 8);
    }
    ((f32 *)arg0)[arg1 * 2 + 0x39] = base +
        ((f32 (*)(s32, f32, f32))fn_80129DC4)(
            4, *(f32 *)((u8 *)arg0 + 0xDC), *(f32 *)((u8 *)arg0 + 0xE0));
    *(u32 *)(element + 0xE8) = value;
}
#pragma pop
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void* fn_80135420(f32*, s32, s32);
extern f32 lbl_80561748;
extern "C" void fn_80156E74(void *arg0, s32 arg1, void *arg2) {
    f32 point[2];
    volatile f32 vs0;
    volatile f32 vs1;
    f32 minimum;
    s32 offset = 0;
    s32 best = -1;
    s32 i = 0;

    point[0] = ((f32 *)arg2)[0];
    point[1] = ((f32 *)arg2)[2];
    minimum = lbl_80561748;
    while (i < *(s32 *)((u8 *)arg0 + 8)) {
        void *entry = *(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + offset);
        void *result = fn_80135420(point, 0, (s32)entry);
        f32 dy = point[1] - *(f32 *)((u8 *)result + 4);
        f32 dx = point[0] - *(f32 *)result;
        f32 distance = dy * dy + dx * dx;
        vs1 = dy;
        vs0 = dx;
        if (distance < minimum) {
            best = i;
            minimum = distance;
        }
        offset += 8;
        i++;
    }

    {
        void *tbl = *(void **)((u8 *)arg0 + 4);
        f32 base;
        f32 result;
        offset = *(s32 *)((u8 *)tbl + best * 8);
        base = lbl_8055E3C8;
        best = arg1 * 8;
        result = ((f32 (*)(s32, f32, f32))fn_80129DC4)(
            4, *(f32 *)((u8 *)arg0 + 0xDC), *(f32 *)((u8 *)arg0 + 0xE0));
        *(f32 *)((u8 *)arg0 + best + 0xE4) = base + result;
        *(s32 *)((u8 *)arg0 + best + 0xE8) = offset;
    }
}
#pragma pop

extern "C" s32 fn_801B2F24(void);
extern "C" void *fn_801B2ED0(s32);
extern "C" f32 lbl_8055E3C8;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_80156F6C(void *arg0) {
    struct Object {
        virtual ~Object();
        virtual void unused();
        virtual Object *call();
    };
    u8 *out;
    s32 i;
    u8 *base = (u8 *)arg0;
    s32 total = fn_801B2F24();
    f32 threshold;
    f32 addValue;
    addValue = lbl_8055E3C8;
    threshold = lbl_80561744;
    out = base;
    i = 0;
    u32 entries[11];
    volatile s32 max;
    volatile s32 count;
    u32 * volatile values;
    while (i < total) {
        values = entries;
        max = 8;
        count = 0;
        Object *obj = (Object *)fn_801B2ED0(i);
        obj = obj->call();
        s32 category = 0;
        if (*(f32 *)((u8 *)obj + 0x34) > threshold)
            category = 1;
        s32 offset = 0;
        s32 j = 0;
        while (j < *(s32 *)(base + 8) && count + 1 <= max) {
            u8 *entry = *(u8 **)(base + 4) + offset;
            if (category == *(s32 *)(entry + 4)) {
                s32 index = count;
                u32 *array = values;
                count = index + 1;
                array[index] = *(volatile u32 *)entry;
            }
            offset += 8;
            j++;
        }
        s32 divisor = count;
        if (divisor > 0) {
            s32 index = i % divisor;
            u32 selected = values[index];
            f32 result = ((f32 (*)(s32, f32, f32))fn_80129DC4)(
                4, *(f32 *)(base + 0xDC), *(f32 *)(base + 0xE0));
            *(f32 *)(out + 0xE4) = addValue + result;
            *(u32 *)(out + 0xE8) = selected;
        }
        values = (u32 *)0;
        count = 0;
        max = 0;
        out += 8;
        i++;
    }
}
#pragma pop
extern "C" void* fn_801570D0(ebi::title::TBlackPlane* self, s32 deleteFlag) {
    /* Deleting destructor of ebi::title::TBlackPlane: restore this class's vtable,
     * destroy the two child planes (m_b at 0x8, then m_a at 0x4) through their
     * virtual destructors, then free the object itself when deleteFlag > 0. */
    struct Dtor { virtual void destroy(s32); };  // virtual destructor (vtable slot 0x8)
    if (self != 0) {
        Dtor* child = *(Dtor**)&self->m_b;
        *(u32*)self = (u32)lbl_8032E3F8;  // TBlackPlane's vtable
        if (child != 0) child->destroy((s32)(volatile u8)1);
        child = *(Dtor**)&self->m_a;
        if (child != 0) child->destroy((s32)(volatile u8)1);
        if (deleteFlag > 0) fn_80128668(self);
    }
    return self;
}

extern "C" void fn_80157170(void* arg0) {
    ((ebi::title::TPlaneSubShort*)((ebi::title::TBlackPlane*)arg0)->m_b)->v1();
}

extern "C" void fn_80157184(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v1();
}

extern "C" void fn_80157198(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_b->v2();
}

extern "C" void fn_801571AC(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v2();
}

void ebi::title::TBlackPlane::updateAfterCamera() {
    m_b->v3();
    m_a->v3();
}

extern "C" void fn_80157210(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v4();
}

extern "C" void fn_80157224(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v5();
}

extern "C" void fn_80157238(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v6();
}

