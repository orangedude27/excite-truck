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
extern "C" void fn_801561E8(u8 *arg0) {
    u8 *result = fn_80029004(arg0, 0x2E);
    if (result != 0) {
        *result = 0;
    }
}

extern "C" s32* fn_801E87A8();
extern "C" void* fn_8001285C(s32);
#pragma dont_inline fn_8015621C
s32 fn_8015621C(void) {
    return *(s32*)((char*)fn_8001285C(*fn_801E87A8()) + 0x20);
}

extern "C" u8 *fn_801E879C(void);
extern "C" void fn_801561E8(u8 *);
extern "C" s32 fn_801345D8(s32, s32, const char *, ...);
extern "C" char lbl_8032E254[];
extern "C" char lbl_80559FC0;
extern "C" char lbl_80559FC4[];
extern "C" char lbl_80559FC8[];
s32 fn_801562BC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 buffer[0x20];
    u8 *src = fn_801E879C();
    u8 *dst = buffer;
    u8 *name = (u8 *)arg2;
    s32 count = 0x20;
    do {
        u8 c = *src++;
        *dst++ = c;
        count--;
        if ((s8)c == 0)
            break;
    } while (count > 0);
    if (count == 0)
        dst[-1] = 0;
    fn_801561E8(buffer);
    if (arg3 != 0) {
        const char *choice = (s8)*name != 0 ? lbl_80559FC4 : (const char *)&lbl_80559FC0;
        fn_801345D8((s32)arg0, arg1, lbl_8032E254, name, choice, buffer);
    } else {
        fn_801345D8((s32)arg0, arg1, lbl_80559FC8,
                    (s8)*name != 0 ? name : buffer);
    }
    return (s32)arg0;
}

extern s32 fn_801562BC(void*, s32, s32, s32);
extern s32 fn_80156248(void*, s32);
extern s32 fn_80138968(void*);
extern void fn_802E30C8(const char*, void*);
extern s32 fn_80138BA0(s32, s32);
extern char lbl_8032E270[];
extern char lbl_8032E2AC[];
s32 fn_801563BC(s32 arg0, void* arg1) {
    char buffer[0x40];
    s32 result;
    fn_801562BC(buffer, 0x40, arg0, 0);
    result = fn_80138968(buffer);
    if (result == 0) {
        fn_802E30C8(lbl_8032E270, buffer);
        fn_801562BC(buffer, 0x40, arg0, 1);
        result = fn_80138968(buffer);
    }
    if (result == 0) {
        fn_802E30C8(lbl_8032E2AC, buffer);
        fn_80156248(buffer, 0x40);
        result = fn_80138968(buffer);
    } else {
        void** vtable = *(void***)arg1;
        s32 value = ((s32 (*)(void*, s32))vtable[3])(arg1, 0);
        fn_80138BA0(result, value);
    }
    return result;
}

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
        void *vtable; Entry *entries; s32 count; s32 capacity;
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
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
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
    void *helper;
    void *resource;
    void *wrapper;
    Reader *reader;
    Config *config;
    u8 *base = lbl_8032E238;

    fn_8012E81C(base + 0xAC);
    helper = fn_801284F8(8, (const char *)&lbl_80559FD0);
    if (helper != 0) {
        *(void **)helper = lbl_8032E46C;
        fn_80156248(path, 0x40);
        s32 helperId = fn_80138968(path);
        *(s32 *)((u8 *)helper + 4) = helperId;
        if (helperId == 0)
            fn_802E317C((const char *)base + 0xBC, path);
    }

    reader = ((Reader *)(long)fn_8015621C())->open((const char *)base + 0xD8);
    if (reader != 0) {
        config = (Config *)fn_801284F8(0x124, (const char *)&lbl_80559FD4);
        resource = config;
        if (config != 0) {
            config->vtable = lbl_8032E424;
            config->entries = (Entry *)((u8 *)config + 0x10);
            config->capacity = 0x10;
            config->count = 0;
            config->objects = (void **)((u8 *)config + 0x9C);
            config->objectCapacity = 0x10;
            config->objectCount = 0;
            const char *format = (const char *)&lbl_80559FD8;
            s32 line = 1;
            const char *suffix = (const char *)&lbl_80559FE8;
            for (;; ++line) {
                fn_801345D8((s32)input, 0x10, (const char *)&lbl_80559FE0, format, line);
                char *result = reader->read(input, 0);
                if (result == 0)
                    break;
                s32 oldCount = config->count;
                if (oldCount + 1 > config->capacity)
                    break;
                config->count = oldCount + 1;
                Entry *entry = &config->entries[oldCount];
                entry->id = fn_801563BC((s32)result, helper);

                char *src = input;
                char *dst = text;
                s32 remaining = 0x20;
                for (;;) {
                    u8 c = *src++;
                    *dst++ = c;
                    if ((s8)c == 0) break;
                    if (--remaining <= 0) { dst[-1] = 0; break; }
                }

                dst = text;
                remaining = 0x20;
                do { remaining--; dst++; } while ((s8)*dst != 0);
                if (remaining > 0) {
                    src = (char *)suffix;
                    do {
                        u8 c = *src++;
                        *dst++ = c;
                        if ((s8)c == 0) break;
                        remaining--;
                        if (remaining <= 0) { dst[-1] = 0; break; }
                    } while (1);
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
            if (config->count == 0)
                fn_802E317C((const char *)base + 0xE8);

            IndexReader *list = (IndexReader *)reader->open((const char *)base + 0x128);
            if (list != 0) {
                s32 index = 0;
                do {
                    config->objects[config->objectCount++] = fn_801399FC();
                    index++;
                    if (list->valid(index) == 0) break;
                } while (config->objectCount + 1 <= config->objectCapacity);
            }

            config->value0 = reader->value((const char *)base + 0x144, lbl_80561738);
            config->value1 = reader->value((const char *)base + 0x154, lbl_8056173C);
            ((void (*)(const char *, s32, const char *, s32, const char *, f32, f32))fn_802E30C8)(
                (const char *)base + 0x168,
                config->count, config->count == 1 ? (const char *)&lbl_80559FC0 : (const char *)&lbl_80559FF0,
                config->objectCount, config->objectCount == 1 ? (const char *)&lbl_80559FC0 : (const char *)&lbl_80559FF0,
                config->value0, config->value1);
            ((ConfigVtable *)config)->dispose();
        }
    } else {
        Helper *fallback = (Helper *)fn_801284F8(8, (const char *)&lbl_80559FD4);
        resource = fallback;
        if (fallback != 0) {
            fallback->vtable = lbl_8032E448;
            TextManager *textManager = (TextManager *)fn_8015621C();
            char *value = textManager->get((const char *)lbl_8032E238, (const char *)&lbl_80559FC0);
            value = textManager->get((const char *)base + 0x1A0, value);
            fallback->id = fn_801563BC((s32)value, helper);
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

void fn_80156960(void *arg0) {
    void *inp = arg0;
    s32 count = 0;
    void *out = arg0;
    f32 f31 = lbl_8055E3C8;
    
    do {
        s32 divisor = ((s32 *)inp)[2];
        void *data_ptr = (void *)((s32 *)inp)[1];
        s32 idx = count - ((count / divisor) * divisor);
        s32 val = *(s32 *)((u8 *)data_ptr + (idx * 8));
        f32 f1 = ((f32 *)inp)[0xDC / 4];
        f32 f2 = ((f32 *)inp)[0xE0 / 4];
        f32 result = fn_80129DC4(4, divisor, (s32)(long)data_ptr, f1, f2);
        result = f31 + result;
        ((f32 *)out)[0xE4 / 4] = result;
        *(s32 *)((u8 *)out + 0xE8) = val;
        out = (u8 *)out + 8;
        count++;
    } while (count < 8);
}

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
    s32 i;
    s32 offset;
    s32 zero = 0;
    if (arg0 != 0) {
        *(void**)arg0 = lbl_8032E424;
        i = 0;
        offset = 0;
        while (i < *(s32*)((char*)arg0 + 8)) {
            ((void(*)(void*))fn_80138AD8)((char*)*(void**)((char*)arg0 + 4) + offset);
            offset += 8;
            i++;
        }
        *(s32*)((char*)arg0 + 8) = 0;
        i = 0;
        offset = 0;
        while (i < *(s32*)((char*)arg0 + 0x94)) {
            fn_80128658(*(void**)((char*)*(void**)((char*)arg0 + 0x90) + offset));
            offset += 4;
            i++;
        }
        if ((char*)arg0 + 0x90 != 0) {
            *(s32*)((char*)arg0 + 0x94) = zero;
            *(s32*)((char*)arg0 + 0x90) = zero;
            *(s32*)((char*)arg0 + 0x94) = zero;
            *(s32*)((char*)arg0 + 0x98) = zero;
        }
        if ((char*)arg0 + 4 != 0) {
            *(s32*)((char*)arg0 + 4) = zero;
            *(s32*)((char*)arg0 + 8) = zero;
            *(s32*)((char*)arg0 + 0xC) = zero;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_80156C60(void *arg0, s32 arg1) {
    if (arg1 >= ((s32 *)arg0)[2]) return 0;
    return ((s32 *)((s32 *)arg0)[1])[arg1 * 2];
}

extern "C" void* fn_8017960C(s32);
extern "C" s32 fn_80139B70(s32, f32, f32);
extern "C" s32 fn_80129D90(s32, s32, s32);
extern "C" f32 fn_80129DC4(s32, s32, s32, f32, f32);
extern "C" f32 fn_801B306C(void);
extern "C" f32 lbl_80561740;
extern "C" f32 lbl_80561744;
s32 fn_80156C84(void *arg0, s32 arg1) {
    s32 off = arg1 * 8;
    u8 *r28 = (u8 *)arg0 + off;
    f32 f31 = lbl_8055E3C8;
    if (f31 != *(f32 *)(r28 + 0xE4)) {
        void *r29 = fn_8017960C(arg1);
        s32 r26 = 0;
        s32 r27 = 0;
        s32 count = ((s32 *)r28)[0x94 / 4];
        for (;;) {
            if (r27 >= count) {
                if (count == 0) break;
            } else {
                s32 v = fn_80139B70(((s32 *)r28)[0x90 / 4] + r26,
                                     ((f32 *)r29)[0x60 / 4],
                                     ((f32 *)r29)[0x68 / 4]);
                if (v != 0) break;
                r26 += 4;
                r27 += 1;
                continue;
            }
            s32 r3 = fn_80129D90(4, 0, ((s32 *)r28)[2]);
            s32 *r5 = (s32 *)((s32 *)r28)[1];
            s32 r27b = r5[r3 * 2];
            if (r27b == 0) {
                s32 next = r3 + 1;
                s32 index = next - ((next / ((s32 *)r28)[2]) * ((s32 *)r28)[2]);
                r27b = r5[index * 2];
            }
            *(f32 *)(r28 + 0xE4) = f31 +
                fn_80129DC4(4, ((s32 *)r28)[2], (s32)(long)r5,
                            *(f32 *)(r28 + 0xDC), *(f32 *)(r28 + 0xE0));
            *(s32 *)(r28 + 0xE8) = r27b;
            break;
        }
    } else {
        *(f32 *)(r28 + 0xE4) = *(f32 *)(r28 + 0xE4) + lbl_80561740;
    }
    if (fn_801B306C() > lbl_80561744)
        return *(s32 *)(r28 + 0xE8);
    return *(s32 *)((u8 *)arg0 + off + 0xE8);
}

extern s32 fn_80129D90(s32, s32, s32);
void fn_80156DCC(void *arg0, s32 arg1) {
    s32 temp_r28 = arg1 * 8;
    void *temp_r31 = (u8 *)arg0 + temp_r28;
    f32 temp_f31 = lbl_8055E3C8;
    u32 temp_r30 = *(u32 *)((u8 *)temp_r31 + 0xE8);
    s32 temp_r3 = fn_80129D90(4, 0, ((s32 *)arg0)[2]);
    u32 *temp_r5 = (u32 *)((s32 *)arg0)[1];
    u32 var_r29 = *(u32 *)((u8 *)temp_r5 + temp_r3 * 8);
    if (var_r29 == temp_r30) {
        s32 count = ((s32 *)arg0)[2];
        s32 next = temp_r3 + 1;
        s32 index = next - ((next / count) * count);
        var_r29 = *(u32 *)((u8 *)temp_r5 + index * 8);
    }
    *(f32 *)((u8 *)arg0 + temp_r28 + 0xE4) = temp_f31 +
      fn_80129DC4(4, ((s32 *)arg0)[2], (s32)(long)temp_r5,
                  *(f32 *)((u8 *)arg0 + 0xDC), *(f32 *)((u8 *)arg0 + 0xE0));
    *(u32 *)((u8 *)temp_r31 + 0xE8) = var_r29;
}

extern void* fn_80135420(void*, s32, s32);
extern f32 lbl_80561748;
extern f32 fn_80129DC4(s32, f32, f32);
void fn_80156E74(void *arg0, s32 arg1, void *arg2) {
    f32 sp10 = ((f32*)arg2)[0];
    f32 sp14 = ((f32*)arg2)[2];
    f32 f31 = lbl_80561748;
    s32 r30 = -1;
    s32 r29 = 0;
    s32 r31 = 0;
    do {
        void *p = fn_80135420(&sp10, 0, *(s32*)((u8*)*(void**)((u8*)arg0 + 4) + r31));
        f32 f3 = sp14 - ((f32*)p)[1];
        f32 f2 = sp10 - ((f32*)p)[0];
        f32 x = f2*f2 + f3*f3;
        if (x < f31) { r30 = r29; f31 = x; }
        r31 += 8;
        r29++;
    } while (r29 < *(s32*)((u8*)arg0 + 8));
    s32 value = *(s32*)((u8*)*(void**)((u8*)arg0 + 4) + r30*8);
    f32 base = lbl_8055E3C8;
    f32 result = fn_80129DC4(4, *(f32*)((u8*)arg0 + 0xDC), *(f32*)((u8*)arg0 + 0xE0));
    *(f32*)((u8*)arg0 + arg1*8 + 0xE4) = base + result;
    *(s32*)((u8*)arg0 + arg1*8 + 0xE8) = value;
}

extern "C" s32 fn_801B2F24(void);
extern "C" void *fn_801B2ED0(s32);
extern "C" f32 lbl_8055E3C8;
extern "C" void fn_80156F6C(void *arg0) {
    // Fix note: builds the category list on the stack, then assigns a randomized matching entry.
    u8 *base = (u8 *)arg0;
    s32 total = fn_801B2F24();
    f32 threshold = lbl_80561744;
    s32 i;
    u32 entries[8];
    s32 count;
    s32 j;
    s32 offset;
    s32 category;
    s32 n;
    u32 *selected;
    u8 *out = base;
    for (i = 0; i < total; i++) {
        count = 0;
        category = 0;
        void *obj = fn_801B2ED0(i);
        f32 value = ((f32 (*)(void *))(*(void ***)obj)[4])(obj);
        if (value > threshold)
            category = 1;
        for (j = 0, offset = 0; j < *(s32 *)(base + 8) && count < 8; j++, offset += 8) {
            u8 *entry = *(u8 **)(base + 4) + offset;
            if (category == *(s32 *)(entry + 4))
                entries[count++] = *(u32 *)entry;
        }
        if (count > 0) {
            selected = &entries[(i / count) * count == i ? 0 : i - (i / count) * count];
            f32 result = fn_80129DC4(4, 0, 0, *(f32 *)(base + 0xDC), *(f32 *)(base + 0xE0));
            *(f32 *)(out + 0xE4) = result;
            *(u32 *)(out + 0xE8) = *selected;
        }
        out += 8;
    }
}

extern "C" void* fn_801570D0(void* arg0, s32 arg1) {
    extern u8 lbl_8032E3F8[];
    struct Obj { virtual void c(s32); };
    if (arg0 != 0) {
        Obj* obj = *(Obj**)((u8*)arg0 + 8);
        *(u32*)arg0 = (u32)lbl_8032E3F8;
        if (obj != 0) obj->c((s32)(volatile u8)1);
        obj = *(Obj**)((u8*)arg0 + 4);
        if (obj != 0) obj->c((s32)(volatile u8)1);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
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

