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
void fn_80156188(s32 subobjectThis) {
    /* This-adjusting thunk: subtract the 4-byte multiple-inheritance offset to
     * recover the base subobject's `this`, then forward to the no-op method
     * fn_8015474C. */
    fn_8015474C(subobjectThis - 4);
}

extern "C" void fn_80154750(s32);
extern "C" void fn_80154754(s32);
extern "C" void fn_80154D30(s32);
extern "C" void fn_80155368(s32);
/* This-adjusting thunk: subtract the 4-byte multiple-inheritance offset to
 * recover the base subobject's `this`, then forward to the no-op virtual method
 * fn_80154750. */
void fn_80156190(s32 subobjectThis) { fn_80154750(subobjectThis - 4); }

/* This-adjusting thunk: subtract the 4-byte multiple-inheritance offset to
 * recover the base subobject's `this`, then forward to the fn_80154754 reset
 * routine. */
void fn_80156198(s32 subobjectThis) { fn_80154754(subobjectThis - 4); }

/* This-adjusting thunk: subtract the 4-byte multiple-inheritance offset to
 * recover the base subobject's `this`, then forward to the fn_80154D30 object
 * initialization routine. */
void fn_801561A0(s32 subobjectThis) { fn_80154D30(subobjectThis - 4); }

/* This-adjusting thunk: subtract the 4-byte multiple-inheritance offset to
 * recover the base subobject's `this`, then forward to the no-op fn_80155368
 * method. */
void fn_801561A8(s32 subobjectThis) { fn_80155368(subobjectThis - 4); }

/* This-adjusting thunk: subtract the 8-byte multiple-inheritance offset to recover the base subobject's `this`, then forward to fn_8015536C. */
extern "C" void fn_801561B0(s32 subobjectThis) {
    fn_8015536C(subobjectThis - 8);
}

/* This-adjusting thunk: subtract the 8-byte multiple-inheritance offset to recover the base subobject's `this`, then forward to the no-op virtual method fn_801556F4. */
extern "C" void fn_801561B8(s32 subobjectThis) {
    fn_801556F4(subobjectThis - 8);
}

/* This-adjusting thunk: subtract the 8-byte multiple-inheritance offset to recover the base subobject's `this`, then forward to the no-op virtual method fn_801556F8. */
extern "C" void fn_801561C0(s32 subobjectThis) {
    fn_801556F8(subobjectThis - 8);
}

extern "C" s32 fn_801556FC(s32);
extern "C" void fn_801561C8(s32 thisAtOffsetC) {
    /* This-adjusting thunk: subtract the 0xC multiple-inheritance offset to recover the base subobject's `this`, then forward to the no-op virtual method fn_801556FC. */
    fn_801556FC(thisAtOffsetC - 0xC);
}

extern "C" s32 fn_80155700(s32);
/* This-adjusting thunk: subtract the 0xC subobject offset to recover `this`, then forward to fn_80155700. */
extern "C" void fn_801561D0(s32 subobjectThis) {
    fn_80155700(subobjectThis - 0xC);
}

extern "C" s32 fn_80155AEC(s32);
/* Adjustor thunk: recover the owning object from a sub-object pointer (subtract 0xC) and call its fn_80155AEC method. */
extern "C" void fn_801561D8(s32 subObject) {
    fn_80155AEC(subObject - 0xC);
}

extern "C" s32 fn_80155AF0(s32);
/* This-adjusting thunk: subtract the 0xC subobject offset to recover `this`, then forward to fn_80155AF0. */
extern "C" void fn_801561E0(s32 subobjectThis) {
    fn_80155AF0(subobjectThis - 0xC);
}

extern "C" u8 *fn_80029004(void *, s32);
#pragma dont_inline fn_801561E8
extern "C" void fn_801561E8(u8 *path) {
    /* Strip a file extension by replacing the last '.' in the string with a null terminator. */
    u8 *dot = fn_80029004(path, '.');
    if (dot != 0) {
        *dot = 0;
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
    // Returns the current manager object (used as a text manager, config reader, etc.): reads a slot index
    // from the global pointed to by fn_801E87A8, indexes the table of 0x28-byte records at lbl_80352AD0
    // through fn_8001285C, and returns the object pointer stored at offset 0x20 of that record.
    return *(s32*)((char*)fn_8001285C(*fn_801E87A8()) + 0x20);
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
/* Format the track data file path ("%strack.ild") for the current line base
 * name into the output buffer and return the buffer. */
s32 fn_80156248(void *outBuffer, s32 bufferSize) {
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual char *m4(const char *, const char *);
    };
    Obj *textManager = (Obj *)fn_8015621C();
    char *lineBaseName = textManager->m4((const char *)lbl_8032E238, (const char *)&lbl_80559FC0);
    fn_801345D8((s32)outBuffer, bufferSize, lbl_8032E248, lineBaseName);
    return (s32)outBuffer;
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
extern "C" void Abend_Panic(const char *, ...);
extern "C" void *fn_801399FC(void *);
extern "C" u8 lbl_8032E238[];
extern "C" u8 lbl_8032E424[];
extern "C" u8 lbl_8032E3F8[];
extern "C" char lbl_80559FD0;
extern "C" char lbl_80559FD4;
extern "C" char lbl_80559FD8;
extern "C" char lbl_80559FE0;
extern "C" char lbl_80559FE8;
extern "C" char lbl_80559FF0;
extern "C" const f32 lbl_80561738;
extern "C" const f32 lbl_8056173C;
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
        virtual void *get(s32);
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
            Abend_Panic((const char *)base + 0xBC, path);
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
                Abend_Panic((const char *)base + 0xE8);

            IndexReader *list = (IndexReader *)reader->open((const char *)base + 0x128);
            if (list != 0) {
                s32 index = 0;
                void *item;
                while ((item = list->get(index)) != 0 &&
                       resource->objectCount + 1 <= resource->objectCapacity) {
                    resource->objects[resource->objectCount++] =
                        ((void *(*)(void *))fn_801399FC)(item);
                    index++;
                }
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
s32 fn_801568E0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

s32 fn_80156920(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern f32 randFloatInRange(s32, s32, s32, f32, f32);
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
        ((f32 *)out)[0xE4 / 4] = base + randFloatInRange(4, divisor, (s32)(long)data, angle1, angle2);
        *(s32 *)((u8 *)out + 0xE8) = sampledValue;
        out = (u8 *)out + 8;
        count++;
    } while ((u32)count < 8);
}
#pragma pop
void fn_801569FC(void) {
    /* Destroy the global singleton instance via vtable slot f8 (deleting) and clear its pointer. */
    struct Callback {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(int);
    };
    extern void **lbl_8055E27C;
    Callback *instance = (Callback *)lbl_8055E27C;
    if (instance != 0)
        instance->f8(1);
    lbl_8055E27C = 0;
}

/* Return the global PSSystem callback singleton pointer (lbl_8055E27C) as an integer. */
s32 fn_80156A40(void) {
    return (s32)lbl_8055E27C;
}

/* Empty no-op hook in the PSSystem code region; returns immediately without doing anything. */
extern "C" void fn_80156A48(void) {
}

extern void fn_80128668(void*);
extern void **lbl_8055E27C;
extern u8 lbl_8032E46C[];
extern void fn_80138AD8(void* this_, u32 a);
/* Destructor for PSSystem::SeqHeap (address-suffixed variant): restore vtable, destroy base subobject, and conditionally delete storage. */
void* __dt__Q28PSSystem7SeqHeapFv_80156A4C(void* seqHeap, s32 shouldDelete) {
    if (seqHeap) {
        *(u32*)seqHeap = (u32)lbl_8032E46C;
        fn_80138AD8((u8*)seqHeap + 4, (u32)lbl_8032E46C);
        if (shouldDelete > 0) {
            fn_80128668(seqHeap);
        }
    }
    return seqHeap;
}

/* Return the offset-4 field of a PSSystem object. */
s32 fn_80156AB0(void *object) {
    return ((s32 *)object)[1];
}

/* Return the offset-4 field of a PSSystem object. */
s32 fn_80156AB8(void *object) {
    return ((s32 *)object)[1];
}

extern u8 lbl_8032E448[];
extern void fn_80138AD8(void* this_, u32 a);
/* PSSystem::SeqHeap scalar-deleting destructor variant: install this variant's vtable, destroy the base subobject at +4, then delete the object when requested. */
void* __dt__Q28PSSystem7SeqHeapFv_80156AC4(void* this_, s32 shouldDelete) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_8032E448;
        fn_80138AD8((u8*)this_ + 4, (u32)lbl_8032E448);
        if (shouldDelete > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

/* Return the offset-4 field of a PSSystem object. */
s32 fn_80156B28(void *object) { return ((s32 *)object)[1]; }

/* Return the offset-4 field of a PSSystem object only in mode 0, otherwise 0. */
s32 fn_80156B30(void *object, s32 mode) {
    if (mode == 0) return ((s32 *)object)[1];
    return 0;
}

}

/* No-op virtual method occupying slot +0x14 of the PSSystem::SeqHeap vtable
 * lbl_8032E46C; it has an empty body and simply returns when called. */
extern "C" void fn_80156AC0(void) {
}

/* No-op virtual method at slot +0x14 of the PSSystem::SeqHeap vtable
 * lbl_8032E448; its body is empty and calling it does nothing. */
extern "C" void fn_80156B48(void) {
}

/* No-op virtual method at slot +0x18 of the PSSystem::SeqHeap vtables
 * lbl_8032E448 and lbl_8032E46C (also +0x3C of the latter); its empty body
 * simply returns. */
extern "C" void fn_80156B4C(void) {
}

/* No-op virtual method in the PSSystem::SeqHeap vtable family; its empty body simply returns. */
extern "C" void fn_80156B50(void) {
}

/* No-op virtual method: an empty slot shared by the PSSystem::SeqHeap vtables
 * (lbl_8032E448 at +0x20, lbl_8032E46C at +0x20/+0x44).  Calling it does nothing. */
extern "C" void fn_80156B54(void) {
}

extern "C" void fn_80128658(void*);
extern u8 lbl_8032E424[];
extern "C" void* fn_80156B58(void* arg0, s32 arg1) {
    /* Deleting destructor for the config container: install the final vtable,
       free every entry and owned object, clear both arrays, then free the
       container itself when the delete flag is positive. */
    struct ConfigObj {
        void *vtable;
        void * volatile entries;
        volatile s32 entryCount;
        u8 pad[0x84];
        void ** volatile objects;
        volatile s32 objectCount;
        volatile s32 objectCapacity;
    };
    s32 i;
    s32 offset;
    s32 j;
    s32 offset2;
    s32 zero = 0;
    if (arg0 != 0) {
        ConfigObj *self = (ConfigObj *)arg0;
        self->vtable = lbl_8032E424;
        i = 0;
        offset = 0;
        while (i < self->entryCount) {
            fn_c_linkage::fn_80138AD8((char *)self->entries + offset);
            offset += 8;
            i++;
        }
        self->entryCount = 0;
        j = 0;
        offset2 = 0;
        while (j < self->objectCount) {
            fn_c_linkage::fn_80128658(*(void **)((char *)self->objects + offset2));
            offset2 += 4;
            j++;
        }
        self->objectCount = zero;
        if (&self->objects != 0) {
            if (&self->objects != 0) {
                self->objects = 0;
                self->objectCount = zero;
                self->objectCapacity = zero;
            }
        }
        if (&self->entries != 0) {
            if (&self->entries != 0) {
                self->entries = 0;
                self->entryCount = zero;
                *(s32 *)((char *)self + 0xC) = zero;
            }
        }
        if (arg1 > 0)
            fn_c_linkage::fn_80128668(self);
    }
    return arg0;
}

extern "C" s32 fn_80156C60(void *config, s32 index) {
    /* Return the first word (name pointer) of the indexed 8-byte entry in the
     * config's entry array, or 0 if index is out of range. */
    struct ConfigObj { void *vtable; s32 *entries; s32 entryCount; };
    ConfigObj *self = (ConfigObj *)config;
    if (index < self->entryCount)
        return *(s32 *)((u8 *)self->entries + (index * 8));
    return 0;
}

extern "C" void* getRegisteredObject(s32);
extern "C" s32 fn_80139B70(s32, f32, f32);
extern "C" s32 fn_80129D90(s32, s32, s32);
extern "C" f32 randFloatInRange(s32, s32, s32, f32, f32);
extern "C" f32 fn_801B306C(void);
extern "C" f32 lbl_80561740;
extern "C" f32 lbl_80561744;
#pragma push
#pragma opt_lifetimes off
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" s32 fn_80156C84(void *arg0, s32 arg1) {
    s32 off = arg1 * 8;
    f32 f31 = lbl_8055E3C8;
    u8 *element = (u8 *)arg0 + off;
    void *self = arg0;

    if (f31 >= *(f32 *)(element + 0xE4)) {
        void *r29 = getRegisteredObject(arg1);
        s32 found;
        s32 i;
        s32 offset;
        for (i = 0, offset = 0; i < *(s32 *)((u8 *)self + 0x94); offset += 4, i++) {
            f32 a = *(f32 *)((u8 *)r29 + 0x60);
            f32 b = *(f32 *)((u8 *)r29 + 0x68);
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
            i = *(s32 *)((u8 *)table + idx * 8);
            if (i == 0) {
                s32 next = idx + 1;
                s32 divisor = *(s32 *)((u8 *)self + 8);
                idx = next % divisor;
                i = *(s32 *)((u8 *)table + idx * 8);
            }
            *(f32 *)(element + 0xE4) = f31 +
                ((f32 (*)(s32, f32, f32))randFloatInRange)(
                    4, *(f32 *)((u8 *)self + 0xDC), *(f32 *)((u8 *)self + 0xE0));
            *(s32 *)((u8 *)self + off + 0xE8) = i;
        } else {
            *(f32 *)(element + 0xE4) += lbl_80561740;
        }
    }

    if (fn_801B306C() > lbl_80561744) {
        return *(s32 *)((u8 *)self + 0xE8);
    }
    return *(s32 *)((u8 *)self + off + 0xE8);
}
#pragma pop
extern s32 fn_80129D90(s32, s32, s32);
#define GAME_TIME lbl_8055E3C8 /* .sbss: current game time in seconds */
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Pick a new random label id for one element of a sound sequence: draw an index
 * from the sequence's entry table, advance to the next entry when it would repeat
 * the element's current id, schedule the element at game time plus seeded jitter,
 * and store the chosen id back. */
extern "C" void fn_80156DCC(void *seq, s32 elementIndex) {
    struct Pick { u8 *element; u32 oldId; u32 newId; s32 offset; } p;
    p.offset = elementIndex * 8;
    p.element = (u8 *)seq + p.offset;
    f32 gameTime = GAME_TIME;
    p.oldId = *(u32 *)(p.element + 0xE8);
    s32 entryCount = *(s32 *)((u8 *)seq + 8);
    s32 entryIndex = fn_80129D90(4, 0, entryCount);
    u32 *entryTable = *(u32 **)((u8 *)seq + 4);
    p.newId = *(u32 *)((u8 *)entryTable + entryIndex * 8);
    if (p.newId == p.oldId) {
        s32 next = entryIndex + 1;
        s32 divisor = *(s32 *)((u8 *)seq + 8);
        entryIndex = next % divisor;
        p.newId = *(u32 *)((u8 *)entryTable + entryIndex * 8);
    }
    ((f32 *)seq)[elementIndex * 2 + 0x39] = gameTime +
        ((f32 (*)(s32, f32, f32))randFloatInRange)(
            4, *(f32 *)((u8 *)seq + 0xDC), *(f32 *)((u8 *)seq + 0xE0));
    *(u32 *)(p.element + 0xE8) = p.newId;
}
#pragma pop
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void* findPathStretch(f32*, s32, s32);
extern f32 lbl_80561748;
extern "C" void fn_80156E74(void *arg0, s32 arg1, void *arg2) {
    f32 point[2];
    volatile f32 vs1;
    volatile f32 vs0;
    f32 minimum;
    s32 best = -1;
    s32 offset = 0;
    s32 i = 0;
    f32 dx;
    f32 dy;
    f32 p1;
    f32 p0;

    p0 = ((f32 *)arg2)[0];
    p1 = ((f32 *)arg2)[2];

    point[0] = p0;
    point[1] = p1;
    minimum = lbl_80561748;
    while (i < *(s32 *)((u8 *)arg0 + 8)) {
        void *entry = *(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + offset);
        void *result = findPathStretch(point, 0, (s32)entry);
        dy = point[1] - *(f32 *)((u8 *)result + 4);
        dx = point[0] - *(f32 *)result;
        {
            f32 distance = dy * dy + dx * dx;
            vs1 = dy;
            vs0 = dx;
            if (distance < minimum) {
                best = i;
                minimum = distance;
            }
        }
        offset += 8;
        i++;
    }

    {
        void *tbl = *(void **)((u8 *)arg0 + 4);
        f32 base;
        offset = *(s32 *)((u8 *)tbl + best * 8);
        base = lbl_8055E3C8;
        ((f32 *)arg0)[arg1 * 2 + 0x39] = base + ((f32 (*)(s32, f32, f32))randFloatInRange)(
            4, *(f32 *)((u8 *)arg0 + 0xDC), *(f32 *)((u8 *)arg0 + 0xE0));
        *(s32 *)((u8 *)arg0 + arg1 * 8 + 0xE8) = offset;
    }
}
#pragma pop

extern "C" s32 getDeitySlotCount(void);
extern "C" void *fn_801B2ED0(s32);
extern "C" f32 lbl_8055E3C8;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma opt_propagation off
extern "C" void fn_80156F6C(void *arg0) {
    struct Object {
        virtual ~Object();
        virtual void unused();
        virtual Object *call();
    };
    u8 *out;
    s32 i;
    u8 *base = (u8 *)arg0;
    s32 total = getDeitySlotCount();
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
        s32 category;
        if (*(f32 *)((u8 *)obj + 0x34) > threshold) category = 1;
        else if (*(f32 *)((u8 *)obj + 0x34) <= threshold) category = 0;
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
            f32 result = ((f32 (*)(s32, f32, f32))randFloatInRange)(
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

extern "C" void fn_80157170(void* plane) {
    /* Forward the v1() virtual call to the m_b (back-plane) child of the
     * TBlackPlane, viewed as a TPlaneSubShort. */
    ((ebi::title::TPlaneSubShort*)((ebi::title::TBlackPlane*)plane)->m_b)->v1();
}

extern "C" void fn_80157184(void* plane) {
    /* Forward the virtual v1() call to the m_a (front-plane) child of the TBlackPlane. */
    ((ebi::title::TBlackPlane*)plane)->m_a->v1();
}

extern "C" void fn_80157198(void* plane) {
    /* Forward the virtual v2() call to the m_b (back-plane) child of the TBlackPlane. */
    ((ebi::title::TBlackPlane*)plane)->m_b->v2();
}

extern "C" void fn_801571AC(void* plane) {
    // Forwards the virtual v2() call to the TPlaneSub member (m_a) of the given TBlackPlane.
    ((ebi::title::TBlackPlane*)plane)->m_a->v2();
}

void ebi::title::TBlackPlane::updateAfterCamera() {
    /* Updates both black-plane layers after the camera transform (layer B then layer A). */
#define backPlane m_b
#define frontPlane m_a
    backPlane->v3();
    frontPlane->v3();
#undef backPlane
#undef frontPlane
}

// Forwards the virtual v4() call to the TPlaneSub member (m_a) of the given TBlackPlane.
extern "C" void fn_80157210(void* plane) {
    ((ebi::title::TBlackPlane*)plane)->m_a->v4();
}

extern "C" void fn_80157224(void* plane) {
    // Forwards the virtual v5() call to the TPlaneSub member (m_a) of the given TBlackPlane.
    ((ebi::title::TBlackPlane*)plane)->m_a->v5();
}

extern "C" void fn_80157238(void* plane) {
    // Forwards the virtual v6() call to the TPlaneSub member (m_a) of the given TBlackPlane.
    ((ebi::title::TBlackPlane*)plane)->m_a->v6();
}

