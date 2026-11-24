#include <types.h>
#include <stdarg.h>
extern "C" void *fn_801284F8(u32, void *);
extern "C" void *fn_80131810(s32);
extern "C" void fn_80146BD4(u8 *, const s8 *, s32);
extern "C" void fn_80146C08(void *, s32);
extern "C" void fn_80146C1C(void **);
extern "C" void fn_80146824(void *);
extern "C" void *fn_80145FEC(void *, const char *, s32);
extern "C" void *fn_801460F8(void *, const char *, s32);
extern "C" void *fn_80146204(void *, const char *, s32);
extern "C" void *fn_80146310(void *, const char *, s32);
extern "C" u8 lbl_8055E208;

extern "C" void *fn_801284F8(u32, void *);
extern "C" void *fn_80131810(s32);
extern "C" void fn_80146BD4(u8 *, const s8 *, s32);
extern "C" void fn_80146C08(void *, s32);
extern "C" void fn_80146C1C(void **);
extern "C" void fn_80146824(void *);
extern "C" void *fn_80145FEC(void *, const char *, s32);
extern "C" void *fn_801460F8(void *, const char *, s32);
extern "C" void *fn_80146204(void *, const char *, s32);
extern "C" void *fn_80146310(void *, const char *, s32);
extern "C" void fn_8014647C(void *);
extern "C" void *__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C(void *, s32);
extern "C" {
__declspec(section ".sdata") extern char lbl_80559E48[];
}
extern "C" void *fn_80146490(void *);
extern "C" void fn_80145D8C(void *);

extern "C" f32 lbl_805615D0;
extern "C" s32 fn_801450A0(u32, u32, f32);
extern "C" void fn_80147DC0(void *, s32, s32, f32);
extern "C" void fn_801476D8(void *, s32, s32);
extern "C" s32 fn_80147C50(u32, u32, f32);

extern "C" void lbl_8032D214(void);
extern "C" {
__declspec(section ".data") extern void *lbl_8032D1E8;
}
extern "C" void *fn_80148294(const char *, void *);
extern "C" char lbl_8032D0EC[];
extern "C" char lbl_8032D0FC[];
extern "C" {
__declspec(section ".sdata") extern char lbl_80559E20[];
__declspec(section ".sdata") extern char lbl_80559E28[];
__declspec(section ".sdata") extern char lbl_80559E30[];
__declspec(section ".sdata") extern char lbl_80559E34[];
__declspec(section ".sdata") extern char lbl_80559E3C[];
}
extern "C" f32 lbl_8055E200;
extern "C" f32 lbl_8055E204;
extern "C" f32 lbl_805615E0;
extern "C" f32 lbl_805615E4;
extern "C" f32 lbl_805615E8;
extern "C" f32 lbl_805615EC;
extern "C" s32 fn_802C9A58(void);
extern "C" s32 fn_802C9A60(void);
extern "C" int stricmp(const char *, const char *);
extern "C" void *lbl_8032D1D8;
extern "C" f32 fn_801451DC(s32, f32);
extern "C" f32 fn_801452B4(f32);
extern "C" void fn_800104B0(s32, s32, s32, f32, f32, f32);
extern "C" void fn_80011278(s32, f32, f32, f32, f32);
extern "C" f32 lbl_805615D4;
extern "C" void fn_801470B0(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_80148DFC(void *);
  extern "C" void fn_80148E6C(void *);
  extern "C" void fn_80148EDC(void *);
  extern "C" void fn_80235380();
  extern "C" void fn_80128668(void *);
  extern "C" void deleteThreads__6SystemFv(void *);

class ThreadObject80144F40 {
public:
    virtual void destroy(s32);
};

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" {
struct Queue80145D8C {
    void **data;
    s32 count;
    s32 capacity;
};
extern Queue80145D8C lbl_8042FBC0;
extern char lbl_8032CEC8[];
__declspec(section ".sdata") extern char lbl_80559E14[6];
void fn_802E30C8(const char *);
extern char lbl_8032D0D0[];
void fn_8000FF88(s32, s32, s32, f32, f32, f32);
extern char lbl_8032CF48[];
extern __declspec(section ".sdata") char lbl_80559DD0[];
extern __declspec(section ".sdata") char lbl_80559DD8[];
extern __declspec(section ".sdata") char lbl_80559DDC[];
s32 ArtSetGet(void);
void fn_802E3AD0(s32, const char *, ...);
}

/* Table of the collection items whose name matched, as built by
   fn_80145FEC()/fn_801460F8()/fn_80146204()/fn_80146310(): the items live in a
   block that fn_8002F37C() lays out 0x10 bytes behind data (its header), so
   releasing a table frees data - 0x10 and then the table itself. */
struct NamedItemTable80145FEC {
    void *data;
    s32 count;
    s32 size;
    void *end; /* == data as built; what releases the item block */
};

extern "C" f32 lbl_805615F0;
extern "C" f32 lbl_8055D020;
extern "C" s32 fn_80144F40(const char *text, void *table) {
    /* Returns the bitwise OR of each table entry's flags whose pattern string
       appears anywhere in text. The table is terminated by an entry with a
       null pattern pointer. */
    extern char *strstr(const char *, const char *);
    struct StringFlagEntry {
        const char *pattern;
        s32 flags;
    };
    StringFlagEntry *entry = (StringFlagEntry *)table;
    s32 matchedFlags = 0;

    while (entry->pattern != 0) {
        if (strstr(text, entry->pattern) != 0) {
            matchedFlags |= entry->flags;
        }
        entry++;
    }
    return matchedFlags;
}

extern "C" u8 lbl_80559DCC;
#pragma scheduling invalid_target
extern "C" s32 fn_80144FB0(void *outStr, s32 maxLen, s32 flags, const char *flagDefs) {
    /* Append to outStr, up to maxLen bytes, an underscore-separated list of the
     * names whose masks are fully set in flags, following flagDefs' name/mask table. */
    struct FlagDef { const char *name; u32 mask; };
    FlagDef *flagDef = (FlagDef *)flagDefs;
    char *dst = (char *)outStr;
    s32 nul = 0;
    const char *sep = (const char *)&lbl_80559DCC;
    *dst = nul;
    while (flagDef->name != 0) {
        if ((flagDef->mask & (u32)flags) == flagDef->mask) {
            if ((s8)*dst != 0) {
                const char *src;
                s32 remaining = maxLen;
                char *cursor = dst;
                while ((s8)*cursor != 0) {
                    --remaining;
                    ++cursor;
                }
                if (remaining > 0) {
                    src = sep;
                    while ((s8)(*cursor++ = *src++) != 0) {
                        if (--remaining <= 0) {
                            cursor[-1] = nul;
                            break;
                        }
                    }
                }
            }
            {
                const char *src = flagDef->name;
                s32 remaining = maxLen;
                char *cursor = dst;
                while ((s8)*cursor != 0) {
                    --remaining;
                    ++cursor;
                }
                if (remaining > 0) {
                    while ((s8)(*cursor++ = *src++) != 0) {
                        if (--remaining <= 0) {
                            cursor[-1] = nul;
                            break;
                        }
                    }
                }
            }
        }
        ++flagDef;
    }
    return (s32)dst;
}
#pragma scheduling on
extern "C" s32 fn_801450A0(u32 from, u32 to, f32 weight) {
    /* Interpolate two byte values by weight, bias by +/-0.5 to round to the
       nearest integer, then clamp that integer to [0,255] and return it as a byte. */
    s32 masked;
    s32 rounded;
    f32 adjusted;
    f32 value = (f32)from + weight * ((f32)to - (f32)from);
    if (value < lbl_805615D4) {
        adjusted = value - lbl_805615D0;
    } else {
        adjusted = lbl_805615D0 + value;
    }
    rounded = (s32)adjusted;
    masked = rounded & ((-rounded & ~rounded) >> 31);
    return (u8)((masked < 0xFF) ? masked : 0xFF);
}

extern "C" s32 fn_80145140(void *container, const char *name) {
    // Count items in a virtual container whose virtual name string matches `name` (case-insensitive).
    struct Container {
        virtual void *v0(s32);
        virtual void *v1(s32);
    };
    struct Item {
        virtual const char *v0();
    };
    s32 count = 0;
    s32 index = 0;
    Item *item;

loop:
    item = (Item *)((Container *)container)->v1(index);
    if (item == 0)
        goto done;
    if (stricmp(item->v0(), name) == 0)
        count++;
    index++;
    goto loop;

done:
    return count;
}

#pragma push
#pragma processor 750
extern "C" f32 fn_801451DC(s32 justification, f32 x) {
    f32 adjustedX = x - 320.0f;
    s32 mode = justification;
    /* Convert a game-space X to screen space and slide it for letterbox/widescreen modes. */
    if ((fn_802C9A58() != 0) || (fn_802C9A60() != 0)) {
        if (mode == 0) {
            if (adjustedX < lbl_805615E8) {
                mode = 2;
            } else if (adjustedX > lbl_805615E4) {
                mode = 1;
            } else {
                mode = 3;
            }
        }
        switch (mode & 0xFFFFFFDF) {
        case 2:
            adjustedX -= lbl_805615EC;
            break;
        case 1:
            adjustedX += lbl_805615EC;
            break;
        case 3:
            break;
        default:
            break;
        }
    }
    adjustedX += lbl_8055E200;
    return adjustedX;
}
#pragma pop

#pragma dont_inline on
extern "C" f32 fn_801452A0(s32 flags, f32 value) {
    /* Undo the widescreen horizontal squeeze: when flags bit 0x20 is set,
       divide by the display aspect scale (lbl_8055D020: 1.0 fullscreen,
       0.75 widescreen) so artwork keeps its aspect. */
    if (flags & 0x20)
        value /= lbl_8055D020;
    return value;
}
#pragma dont_inline reset

#pragma dont_inline on
extern "C" f32 fn_801452B4(f32 inputY) {
    // Convert a game-space Y to screen space: mirror about 240.0 (lbl_805615F0), then add the current Y translation offset (lbl_8055E204).
    f32 screenY = lbl_805615F0 - inputY;
    screenY = screenY + lbl_8055E204;
    return screenY;
}
#pragma dont_inline reset

extern "C" f32 fn_801452C8(f32 x) {
    /* Converts a layout X coordinate to screen space for legacy-version text entries by adding the 320-unit screen width (lbl_805615E0); paired with fn_801452D4 for Y. */
    extern f32 lbl_805615E0;
#define SCREEN_WIDTH lbl_805615E0
    return SCREEN_WIDTH + x;
#undef SCREEN_WIDTH
}

extern "C" f32 fn_801452D4(f32 y) {
    /* Mirrors a layout Y coordinate about the 240-unit screen height, paired with fn_801452C8 (X + 320), for legacy-version text entries. */
#define SCREEN_HEIGHT lbl_805615F0
    return SCREEN_HEIGHT - y;
#undef SCREEN_HEIGHT
}

#pragma push
#pragma processor 750
#pragma dont_inline on
extern "C" float fn_801452E0(void *propertySource, const char *propertyName) {
    /* Get a property string and parse it as a float, or as a numerator/denominator fraction if it contains '/'. */
    extern char *strchr(const char *, int);
    extern double atof(const char *);
    class V { public: virtual void a(); virtual void b(); virtual void c(); virtual const char *get(const char *); };
    double denominator;
    const char *valueStr = ((V *)propertySource)->get(propertyName);
    if (strchr(valueStr, '/') != 0) {
        denominator = atof(strchr(valueStr, '/') + 1);
        return (float)(atof(valueStr) / denominator);
    }
    return (float)atof(valueStr);
}
#pragma dont_inline reset
#pragma pop
#pragma push
#pragma dont_inline on
extern "C" void fn_80145368(void *outEntry, void *propertySource) {
    /* Initializes a basic on-screen text entry (id, x, y, justification) from property keys. */
    class Obj {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual s32 f3(const char *);
        virtual void f4();
        virtual void f5();
        virtual s32 f6(const char *, s32);
        virtual f32 f7(const char *);
    };
    extern char lbl_8032CF18[];
    extern u8 lbl_8055E208;
    extern f32 fn_801452C8(f32);
    extern f32 fn_801452D4(f32);
    Obj *obj = (Obj *)propertySource;
    *(s32 *)outEntry = obj->f3(lbl_80559DD0);
    *(f32 *)((u8 *)outEntry + 4) = obj->f7(lbl_80559DD8);
    *(f32 *)((u8 *)outEntry + 8) = obj->f7(lbl_80559DDC);
    if (lbl_8055E208) {
        *(f32 *)((u8 *)outEntry + 4) = fn_801452C8(*(f32 *)((u8 *)outEntry + 4));
        *(f32 *)((u8 *)outEntry + 8) = fn_801452D4(*(f32 *)((u8 *)outEntry + 8));
    }
    *(s32 *)((u8 *)outEntry + 0xC) = obj->f6(lbl_8032CF18, 0);
}
#pragma dont_inline reset
#pragma pop

extern "C" f32 lbl_805615E0;
extern "C" s32 lbl_80559DE0;
extern "C" s32 lbl_80559DE4;
extern "C" s32 lbl_80559DE8;
extern "C" s32 lbl_80559DEC;
extern "C" s32 lbl_80559DF0;
extern "C" s32 lbl_80559DF4;
extern "C" __declspec(section ".sdata") char lbl_80559DFC[];
extern "C" __declspec(section ".sdata") char lbl_80559E04[];
extern "C" __declspec(section ".sdata") char lbl_80559E0C[];
extern "C" char lbl_8032CEC8[];
/* Initializes a textured/text entry from property keys: base fields via fn_80145368, width/height via virtual getter (slot 0x24), and UV bounds via fn_801452E0. */
extern "C" void fn_80145438(void *outEntry, void *propertySource) {
    class V { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual f32 f7(const char *); };
    V *obj = (V *)propertySource;
    fn_80145368(outEntry, propertySource);
    *(f32 *)((u8 *)outEntry + 0x10) = obj->f7((const char *)&lbl_80559DE0); /* "wid" */
    *(f32 *)((u8 *)outEntry + 0x14) = obj->f7((const char *)&lbl_80559DE4); /* "hit" */
    *(f32 *)((u8 *)outEntry + 0x18) = fn_801452E0(propertySource, (const char *)&lbl_80559DE8); /* "u0" */
    *(f32 *)((u8 *)outEntry + 0x20) = fn_801452E0(propertySource, (const char *)&lbl_80559DEC); /* "u1" */
    *(f32 *)((u8 *)outEntry + 0x1C) = fn_801452E0(propertySource, (const char *)&lbl_80559DF0); /* "v0" */
    *(f32 *)((u8 *)outEntry + 0x24) = fn_801452E0(propertySource, (const char *)&lbl_80559DF4); /* "v1" */
}

#pragma push
#pragma dont_inline on
extern "C" s32 fn_801454E8(void *propertySource, const char *propertyName) {
    /* Parse a "#rrggbb" hex color property and return it, or -1 if missing/invalid. */
    class V { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual const char *f3(const char *); };
    extern int lbl_80559DF8;
    extern int sscanf(const char *, const char *, ...);
    s32 value;
    const char *text = ((V *)propertySource)->f3(propertyName);
    if (sscanf(text, (const char *)&lbl_80559DF8, &value) != 1)
        value = -1;
    return value;
}
#pragma dont_inline reset
#pragma pop

// One line of on-screen text given an explicit pixel size instead of a scale:
// the 0x1C-byte entries fn_80146204 collects and fn_80145538 fills from the
// level's "name", "x", "y", "elem_just", "wid", "hit" and "color" keys.
struct TextSizeEntry80145538 {
    s32 id;            /* +0x00 "name" */
    f32 x;             /* +0x04 "x" */
    f32 y;             /* +0x08 "y" */
    s32 justification; /* +0x0C "elem_just": 0 auto, 1 right, 2 left, 3 centre; |0x20 = scale by aspect */
    f32 width;         /* +0x10 "wid" */
    f32 height;        /* +0x14 "hit" */
    s32 color;         /* +0x18 "color", "#rrggbb" parsed by fn_801454E8 */
};

/* Fills one on-screen text entry from a level's property set: the common
   id/x/y/justification fields by fn_80145368, then the "wid"/"hit" pixel size
   and the "#rrggbb" "color" that fn_801454E8 parses as an integer. */
extern "C" void fn_80145538(TextSizeEntry80145538 *entry, void *propertySource) {
    class PropertySet {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual f32 getFloat(const char *); /* vtable slot 0x24: float property */
    };
    PropertySet *props = (PropertySet *)propertySource;
    fn_80145368(entry, propertySource);
    entry->width = props->getFloat((const char *)&lbl_80559DE0);  /* "wid" */
    entry->height = props->getFloat((const char *)&lbl_80559DE4); /* "hit" */
    entry->color = fn_801454E8(propertySource, lbl_80559DFC);     /* "color" */
}

#pragma use_lmw_stmw off
#pragma dont_inline on
/* Fills one 0x20-byte extended on-screen text entry from a level element's property set: base id/x/y/justification, then style flags from "just", a "scale" float, a "#rrggbb" color, and a comparison flag. */
extern "C" void fn_801455B8(void *entry, void *propertySource) {
    class PropertySet {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual const char *getString(const char *);
        virtual s32 compareStrings(const char *, const char *);
        virtual void f5();
        virtual void f6();
        virtual f32 getFloat(const char *);
    };
    char *const baseline = lbl_8032CEC8;
    PropertySet *props = (PropertySet *)propertySource;
    fn_80145368(entry, propertySource);
    *(s32 *)((u8 *)entry + 0x14) = fn_80144F40(props->getString(lbl_80559E04), baseline + 0x10);
    *(f32 *)((u8 *)entry + 0x10) = props->getFloat(lbl_80559E0C);
    *(s32 *)((u8 *)entry + 0x18) = fn_801454E8(propertySource, lbl_80559DFC);
    *(s32 *)((u8 *)entry + 0x1C) = props->compareStrings(baseline + 0x5C, baseline + 0x70);
}
#pragma dont_inline reset
#pragma scheduling on
#pragma use_lmw_stmw reset
extern "C" void fn_80145670(void *outEntry, void *propertySource) {
    /* One 0xC-byte entry of a level's "gart_set" table (fn_80146310 collects the
       items named "gart_set", fn_8014595C dumps each as "\t%s %s"). */
    struct GArtSetEntry {
        const char *name;         /* +0x00 "name" */
        const char *resourceName; /* +0x04 "resource_name" */
        void *resource;           /* +0x08 gArt resource, refcounted by ArtSetGet */
    };
    class PropertySet {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual const char *getString(const char *); /* vtable slot 0x14: string property */
    };
    /* FillGArtSetEntry: one "gart_set" entry from a level element - its "name" and
       "resource_name" strings and the gArt resource loaded for that name (the name
       is still in r3 for ArtSetGet, which looks a resource up by name). */
    GArtSetEntry *entry = (GArtSetEntry *)outEntry;
    PropertySet *props = (PropertySet *)propertySource;
    entry->name = props->getString(lbl_80559DD0);
    entry->resourceName = props->getString(lbl_8032CF48);
    entry->resource = (void *)ArtSetGet();
}

extern "C" s32 fn_8013126C(void *, s32);
extern "C" s32 fn_80144FB0(void *, s32, s32, const char *);
#pragma scheduling invalid_target
extern "C" void fn_801456E8(void *arg0, s32 arg1) {
    /* Print a formatted dump of a 0x20-byte-entry list to the given output:
       write two header lines, then for each entry emit its floats, counts, id,
       a flag string, a value, and a resolved name, and finish with "end\r\n". */
    struct Entry {
        s32 unk0;
        f32 unk4;
        f32 unk8;
        s32 unkC;
        f32 unk10;
        s32 unk14;
        s32 unk18;
        s32 unk1C;
    };
    struct List {
        Entry *entries;
        s32 count;
    };
    char *base = lbl_8032CEC8;
    List *list = (List *)arg0;
    char flagBuffer[0x40];
    char nameBuffer[0x138];
    fn_802E3AD0(arg1, base + 0x90);
    fn_802E3AD0(arg1, base + 0xA0);
    s32 nameValue;
    Entry *entry;
    s32 offset;
    s32 i;
    i = 0;
    offset = 0;
    while (i < list->count) {
        entry = (Entry *)((u8 *)list->entries + offset);
        nameValue = fn_8013126C(nameBuffer, entry->unk1C);
        s32 flags = fn_80144FB0(flagBuffer, 0x40, entry->unk14, base + 0x10);
        fn_802E3AD0(arg1, base + 0xD4, entry->unk4, entry->unk8, entry->unkC, entry->unk18, flags, entry->unk10, entry->unk0, nameValue);
        offset += 0x20;
        i++;
    }
    fn_802E3AD0(arg1, lbl_80559E14);
}
#pragma scheduling on
/* Dump each 0x28-byte entry of a table to arg1 using format strings in lbl_8032CEC8. */
extern "C" void fn_801457D0(void *arg0, s32 arg1) {
    char *base = lbl_8032CEC8;
    s32 offset;
    s32 i;
    fn_802E3AD0(arg1, base + 0x104);
    fn_802E3AD0(arg1, base + 0x114);
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 4)) {
        u8 *entry = *(u8 **)arg0 + offset;
        fn_802E3AD0(arg1, base + 0x140,
            *(f32 *)(entry + 4), *(f32 *)(entry + 8),
            *(f32 *)(entry + 0x10), *(f32 *)(entry + 0x14),
            *(f32 *)(entry + 0x18), *(f32 *)(entry + 0x1C),
            *(f32 *)(entry + 0x20), *(f32 *)(entry + 0x24),
            *(s32 *)(entry + 0xC), *(s32 *)entry);
        offset += 0x28;
        i++;
    }
    fn_802E3AD0(arg1, lbl_80559E14);
}
#pragma scheduling on
extern "C" void fn_8014589C(void *arg0, s32 outputHandle) {
    /* Dump a table of 0x1C-byte entries (floats and ids) to the output handle using format strings from lbl_8032CEC8. */
    char *formatBase = lbl_8032CEC8;
    s32 offset;
    s32 index;

    fn_802E3AD0(outputHandle, formatBase + 0x170);
    fn_802E3AD0(outputHandle, formatBase + 0x180);
    index = 0;
    offset = 0;
    while (index < *(s32 *)((u8 *)arg0 + 4)) {
        u8 *entry = *(u8 **)arg0 + offset;
        fn_802E3AD0(outputHandle, formatBase + 0x1A8,
            *(f32 *)(entry + 4), *(f32 *)(entry + 8),
            *(f32 *)(entry + 0x10), *(f32 *)(entry + 0x14),
            *(s32 *)(entry + 0x18), *(s32 *)(entry + 0xC), *(s32 *)entry);
        offset += 0x1C;
        index++;
    }
    fn_802E3AD0(outputHandle, lbl_80559E14);
}
#pragma use_lmw_stmw off
/* Prints table/list debug info via formatted output (fn_802E3AD0): header lines, each entry's (field+4, field+0) values, then "end". */
extern "C" void fn_8014595C(void *list, const char *out) {
    char *base = lbl_8032CEC8;
    fn_802E3AD0((s32)out, base + 0x1D0);
    fn_802E3AD0((s32)out, base + 0x1E4);
    s32 offset;
    s32 i;
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)list + 4)) {
        void *entry = (void *)(*(u8 **)list + offset);
        fn_802E3AD0((s32)out, base + 0x1FC,
            *(s32 *)((u8 *)entry + 4), *(s32 *)entry);
        offset += 0xC;
        i++;
    }
    fn_802E3AD0((s32)out, lbl_80559E14);
}
#pragma dont_inline on
extern "C" f32 fn_80145A08(f32 x0, f32 x1, f32 y0, f32 y1, f32 x) {
    /* Linearly interpolate: value at x on the line through (x0,y0) and (x1,y1). */
    f32 num = x - x0;
    return y0 + ((num / (x1 - x0)) * (y1 - y0));
}
#pragma dont_inline reset

extern "C" s32 fn_802C9C38(void);
extern "C" s32 fn_802C9C48(void);
extern "C" f32 fn_80145A08(f32, f32, f32, f32, f32);
struct FloatPair80145A24 { f32 first; f32 second; };
extern "C" f32 lbl_805615F4; /* 640.0f, screen width */
extern "C" f32 lbl_805615F8; /* 0.75f */
extern "C" f32 lbl_805615FC; /* 480.0f, screen height */
extern "C" f64 lbl_80561600; /* int-to-float conversion bias */
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
/* Compute a screen-space coordinate pair from two raw sample fields: interpolate
 * the x field to the screen width and the y field (offset by a time-based range)
 * to the screen height. */
extern "C" FloatPair80145A24 fn_80145A24(void *sample) {
    struct FWrap { f32 v; } correction;
    f32 screenX = fn_80145A08(lbl_805615D4, (f32)(s32)fn_802C9C48(),
                              lbl_805615D4, lbl_805615F4,
                              (f32)*(s32 *)((u8 *)sample + 4));
    f32 span = lbl_805615F8 * (f32)(s32)fn_802C9C48();
    correction.v = span * lbl_805615D0;
    s32 rawMid = (s32)fn_802C9C38();
    s32 signBit = ((u32)rawMid >> 31);
    s32 mid = (s32)(signBit + rawMid) >> 1;
    f32 rangeStart = (f32)mid - correction.v;
    f32 screenY = fn_80145A08(rangeStart,
                              rangeStart + lbl_805615F8 * (f32)(s32)fn_802C9C48(),
                              lbl_805615D4, lbl_805615FC,
                              (f32)*(s32 *)((u8 *)sample + 8));
    FloatPair80145A24 coords;
    coords.first = screenX;
    coords.second = screenY;
    return coords;
}
#pragma scheduling on
#pragma pop
#pragma dont_inline reset
#pragma processor reset

// One line of the game's on-screen text, as read from the level's text data
// (see fn_80145368 / fn_801455B8, which fill it from the "name", "x", "y",
// "elem_just", ... keys) and drawn by the fn_80145B50..fn_80145CF4 printers.
struct TextEntry80145C08 {
    s32 id;            /* +0x00 "name" */
    f32 x;             /* +0x04 "x" */
    f32 y;             /* +0x08 "y" */
    s32 justification; /* +0x0C "elem_just": 0 auto, 1 right, 2 left, 3 centre; |0x20 = scale by aspect */
    f32 scale;         /* +0x10 */
    s32 fontId;        /* +0x14 font the drawer picks */
    s32 color;         /* +0x18 colour, parsed from "#rrggbb" by fn_801454E8 */
};

extern "C" f32 lbl_80561608;
extern "C" void fn_8001027C(s32, s32, void *, u32, f32, f32, f32);
extern "C" f32 fn_801452A0(s32, f32);
extern "C" void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern "C" s32 lbl_80559E1C;
extern "C" void fn_80145B50(void *arg0, s32 arg1)
{
  f32 value = (f32) (s32) arg1;
  f32 multiplier = lbl_80561608;
  *((f32 *) (((u8 *) arg0) + 4)) = lbl_805615D4;
  *((f32 *) (((u8 *) arg0) + 0xC)) = multiplier;
  *((f32 *) (((u8 *) arg0) + 8)) = multiplier;
  *((f32 *) arg0) = multiplier * value;
}

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Renders formatted text for a UI/text entry: computes screen-space Y via
 * fn_801452B4 and screen-space X via fn_801451DC from the entry fields, then
 * passes stored color, font, format arg, alpha, screen X, and screen Y to
 * fn_8000FF88 to format and draw the text. */
extern "C" void fn_80145B94(void * __restrict arg0, u32 arg1) {
    f32 screenY = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    f32 logicalX = *(f32 *)((u8 *)arg0 + 4);
    s32 justification = *(s32 *)((u8 *)arg0 + 0xC);
    f32 screenX = ((f32 (*)(s32, f32))fn_801451DC)(justification, logicalX);
    f32 alpha = *(f32 *)((u8 *)arg0 + 0x10);
    s32 fontId = *(s32 *)((u8 *)arg0 + 0x14);
    s32 color = *(s32 *)((u8 *)arg0 + 0x18);
    ((void (*)(s32, s32, s32, ...))fn_8000FF88)(color, fontId, (s32)arg1, alpha, screenX, screenY);
}
#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling on
extern "C" void fn_80145C08(void * __restrict arg0, const char *text) {
    // Draw one formatted line of on-screen text in the style `entry` holds:
    // fn_801451DC slides x into the visible area on letterbox screens and
    // fn_801452B4 flips y to the text drawer's origin; fn_800104B0 does the
    // vsprintf and hands the string to the 2D text drawer with the scale,
    // font and colour the entry carries.
    TextEntry80145C08 *entry = (TextEntry80145C08 *)arg0;
    f32 y = fn_801452B4(entry->y);
    f32 x = entry->x;
    s32 justification = entry->justification;
    f32 screenX = ((f32 (*)(s32, f32))fn_801451DC)(justification, x);
    f32 scale = entry->scale;
    s32 fontId = entry->fontId;
    s32 color = entry->color;
    ((void (*)(s32, s32, s32, ...))fn_800104B0)(color, fontId, (s32)text, scale, screenX, y);
}
#pragma scheduling on
#pragma pop
#pragma dont_inline reset

#pragma scheduling on
#pragma pop
#pragma dont_inline reset

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Draw a formatted text entry from a context: scale Y, compute X by justification, then call the text drawer with "%s" and the provided text argument. */
extern "C" void fn_80145C7C(void * __restrict arg0, u32 arg1) {
    f32 scale = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
    f32 input = *(f32 *)((u8 *)arg0 + 4);
    s32 id = *(s32 *)((u8 *)arg0 + 0xC);
    f32 value = ((f32 (*)(s32, f32))fn_801451DC)(id, input);
    f32 last = *(f32 *)((u8 *)arg0 + 0x10);
    s32 b = *(s32 *)((u8 *)arg0 + 0x14);
    s32 a = *(s32 *)((u8 *)arg0 + 0x18);
    ((void (*)(s32, s32, s32, ...))fn_8001027C)(a, b, (s32)&lbl_80559E1C, arg1, last, value, scale);
}
#pragma scheduling on
#pragma pop
#pragma dont_inline reset

#pragma processor 750
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_80145CF4(void *__restrict entry, void *resource, u32 pictureIndex) {
    /* Draws an entry's artwork: aspect-correct its scale (fn_801452A0), flip Y
       into screen space (fn_801452B4), resolve X by justification (fn_801451DC),
       then hand the resource, position, scale and remaining entry fields to the
       2D art drawer fn_802354A0. */
    f32 screenY;
    f32 scaledScale;
    f32 scale;
    f32 x;
    s32 justification;
    f32 screenX;
    scale = *(f32 *)((u8 *)entry + 0x10);
    justification = *(s32 *)((u8 *)entry + 0xC);
    scaledScale = fn_801452A0(justification, scale);
    screenY = fn_801452B4(*(f32 *)((u8 *)entry + 8));
    x = *(f32 *)((u8 *)entry + 4);
    justification = *(s32 *)((u8 *)entry + 0xC);
    screenX = ((f32 (*)(s32, f32))fn_801451DC)(justification, x);
    ((void (*)(s32, s32, f32, f32, f32, f32, f32, s32))fn_802354A0)(
        (s32)resource, pictureIndex, screenX, screenY, lbl_805615D4,
        scaledScale, *(f32 *)((u8 *)entry + 0x14),
        *(s32 *)((u8 *)entry + 0x18));
}
#pragma scheduling on
#pragma dont_inline reset
#pragma processor reset
extern "C" void fn_80145D8C(void *layout) {
    /* OVEdit_PushLayout: append a layout pointer to sOVEditLayoutQueue
       (lbl_8042FBC0), or log sOVEditTooManyLayoutsMsg when full. */
    volatile Queue80145D8C *queue = &lbl_8042FBC0;
    s32 count = queue->count;
    if (count + 1 <= queue->capacity) {
        register s32 slotIndex = queue->count;
        void **items = lbl_8042FBC0.data;
        queue->count = slotIndex + 1;
        items[slotIndex] = layout;
        return;
    }
    ((void (*)(const char *, ...))fn_802E30C8)(lbl_8032D0D0);
}

static inline s32 findLayout80145DD8(void *obj) {
    Queue80145D8C *q = &lbl_8042FBC0;
    void **p = q->data;
    s32 n = *(volatile s32 *)&q->count;
    s32 i = 0;
    for (; i < n; i++) {
        if (*p == obj) return i;
        p++;
    }
    return -1;
}

extern "C" void fn_80145DD8(void *layout) {
    /* OVEdit_RemoveLayout: remove a layout pointer from sOVEditLayoutQueue
       (lbl_8042FBC0) by swapping the last entry into its slot, then shrinking. */
    s32 slotIndex = findLayout80145DD8(layout);
    if ((slotIndex >= 0) && (slotIndex >= 0) && (slotIndex < lbl_8042FBC0.count)) {
        s32 lastIndex = lbl_8042FBC0.count - 1;
        if (slotIndex != lastIndex) {
            void **items = lbl_8042FBC0.data;
            items[slotIndex] = items[lastIndex];
        }
        lbl_8042FBC0.count = lbl_8042FBC0.count - 1;
    }
}

#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling on
#pragma small_data off
extern "C" void fn_80145E70(s32 arg0) {
    struct Config {
        virtual void *getObject(const char *);
        virtual void a1();
        virtual s32 has(const char *);
    };
    struct Properties {
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void a3();
        virtual void a4();
        virtual void a5();
        virtual s32 set(const char *, s32);
    };
    u8 *object;
    object = (u8 *)fn_801284F8(0x50, &lbl_8032D0EC);
    if (object == 0)
        return;
    fn_80146C1C((void **)object);
    *(void **)object = &lbl_8032D1E8;
    fn_80146C08(object + 0x40, (s32)object);
    *(s32 *)(object + 0x2C) = 0;
    {
        u8 *dst = object + 5;
        const s8 *src = (const s8 *)arg0;
        *(s32 *)(object + 0x30) = 0;
        *(s32 *)(object + 0x34) = 0;
        *(s32 *)(object + 0x3C) = 0;
        *(s32 *)(object + 0x48) = 0;
        *(s32 *)(object + 0x4C) = 0;
        object[4] = 0;
        ((void (*)(u8 *, const s8 *, s32, s32))fn_80146BD4)(dst, src, 0x20, 0);
    }
    *(void **)(object + 0x28) = fn_80131810(arg0);
    if (*(void **)(object + 0x28) != 0) {
        lbl_8055E208 = 1;
        if (((Config *)*(void **)(object + 0x28))->has(lbl_80559E20) != 0) {
            void *properties = ((Config *)*(void **)(object + 0x28))->getObject(lbl_80559E20);
            s32 value = ((Properties *)properties)->set(lbl_80559E28, 1) ^ 1;
            value = -((value & 1) - (value >> 1));
            lbl_8055E208 = (s8)((u32)value >> 31);
        }
        *(s32 *)(object + 0x2C) = (s32)((void *(*)(void *, const char *))fn_80145FEC)(*(void **)(object + 0x28), lbl_80559E30);
        *(s32 *)(object + 0x30) = (s32)((void *(*)(void *, const char *))fn_801460F8)(*(void **)(object + 0x28), lbl_80559E34);
        *(s32 *)(object + 0x34) = (s32)((void *(*)(void *, const char *))fn_80146204)(*(void **)(object + 0x28), lbl_80559E3C);
        *(s32 *)(object + 0x3C) = (s32)((void *(*)(void *, const char *))fn_80146310)(*(void **)(object + 0x28), lbl_8032D0FC);
        fn_80146824(object);
    }
    fn_80145D8C(object);
    fn_80146490(object);
}
#pragma small_data on
#pragma scheduling on
#pragma pop
#pragma dont_inline reset
extern "C" void *fn_801284F8(u32, void *);
extern "C" void *fn_8012850C(u32, void *);
extern "C" void *fn_8002F37C(void *, s32, s32, s32);
extern "C" s32 fn_80145140(void *, const char *);
extern "C" void fn_80145438(void *, void *);
extern "C" void fn_801460F4(void);
extern "C" char lbl_8032D108[];
extern "C" char lbl_80559E48[];
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
/* Builds a result object containing copies of all collection items whose name matches wantedName (0x28-byte entries). */
extern "C" void *fn_80145FEC(void *collection, const char *wantedName, s32 unused) {
    extern void fn_801460F4(void);
    struct Result { void *data; s32 count; s32 size; void *end; };
    class Collection { public: virtual void a(); virtual void *get(s32); };
    class Item { public: virtual const char *name(); };
    Result *result;
    s32 size = fn_80145140(collection, wantedName);
    result = (Result *)fn_801284F8(0x10, lbl_8032D108);
    if (result != 0) {
        s32 bytes = size * 0x28 + 0x10;
        s32 allocator = (s32)fn_8012850C(bytes, &lbl_80559E48);
        result->data = ((void *(*)(s32, void *, s32, s32, s32))fn_8002F37C)(allocator, (void *)fn_801460F4, 0, 0x28, size);
        result->size = size;
        result->count = 0;
        result->end = result->data;
    }
    s32 i = 0;
    while (1) {
        void *item = ((Collection *)collection)->get(i);
        if (item == 0) break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, wantedName) == 0) {
            s32 count = result->count;
            void *data = result->data;
            s32 offset = count * 0x28;
            result->count = count + 1;
            fn_80145438((char *)data + offset, item);
        }
        i++;
    }
    return result;
}
#pragma dont_inline reset
#pragma pop
/* Empty per-element destructor callback passed to the array allocator fn_8002F37C
 * by fn_80145FEC for its 0x28-byte result entries; they need no cleanup, so this
 * does nothing (a bare 'blr'). */
extern "C" void fn_801460F4(void) {
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void *fn_801460F8(void *collection, const char *wantedName, s32 unused) {
    /* Build a table of 0x20-byte entries for collection items whose name matches wantedName. */
    extern void fn_80146200(void);
    struct Result { void *data; s32 count; s32 size; void *end; };
    class Collection { public: virtual void a(); virtual void *get(s32); };
    class Item { public: virtual const char *name(); };
    Result *result;
    s32 size = fn_80145140(collection, wantedName);
    result = (Result *)fn_801284F8(0x10, lbl_8032D108);
    if (result != 0) {
        s32 bytes = (size << 5) + 0x10;
        s32 allocator = (s32)fn_8012850C(bytes, &lbl_80559E48);
        result->data = ((void *(*)(s32, void *, s32, s32, s32))fn_8002F37C)(allocator, (void *)fn_80146200, 0, 0x20, size);
        result->size = size;
        result->count = 0;
        result->end = result->data;
    }
    s32 i = 0;
    while (1) {
        void *item = ((Collection *)collection)->get(i);
        if (item == 0) break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, wantedName) == 0) {
            s32 count = result->count;
            void *data = result->data;
            s32 offset = count * 0x20;
            result->count = count + 1;
            fn_801455B8((char *)data + offset, item);
        }
        i++;
    }
    return result;
}
#pragma dont_inline reset
#pragma pop

/* Empty destructor callback passed to the array allocator fn_8002F37C by fn_801460F8 for its 0x20-byte result-table entries; the elements need no cleanup, so this does nothing (compiles to a bare 'blr'). */
extern "C" void fn_80146200(void) {

}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void *fn_80146204(void *collection, const char *wantedName, s32 unused) {
    extern void fn_8014630C(void);
    struct Result { void *data; s32 count; s32 size; void *end; };
    class Collection { public: virtual void a(); virtual void *get(s32); };
    class Item { public: virtual const char *name(); };
    Result *result;
    s32 size = fn_80145140(collection, wantedName);
    result = (Result *)fn_801284F8(0x10, lbl_8032D108);
    if (result != 0) {
        s32 bytes = size * 0x1C + 0x10;
        s32 allocator = (s32)fn_8012850C(bytes, &lbl_80559E48);
        result->data = ((void *(*)(s32, void *, s32, s32, s32))fn_8002F37C)(allocator, (void *)fn_8014630C, 0, 0x1C, size);
        result->size = size;
        result->count = 0;
        result->end = result->data;
    }
    s32 i = 0;
    while (1) {
        void *item = ((Collection *)collection)->get(i);
        if (item == 0) break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, wantedName) == 0) {
            s32 count = result->count;
            void *data = result->data;
            s32 offset = count * 0x1C;
            result->count = count + 1;
            fn_80145538((TextSizeEntry80145538 *)((char *)data + offset), item);
        }
        i++;
    }
    /* Build a result table of collection items whose name matches wantedName:
       count matches, allocate header/array (0x1C-byte entries), then append each match. */
    return result;
}
#pragma dont_inline reset
#pragma pop

/* Per-element constructor for the 0x1C-byte on-screen text entries
 * (TextSizeEntry80145538) whose array fn_80146204() builds: it is handed to the
 * runtime's array constructor fn_8002F37C(), which calls it as ctor(entry, 1)
 * for every element.  Empty because the entry is plain data -- fn_80145538()
 * fills each one in from the level's properties afterwards. */
extern "C" void fn_8014630C(void) {
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void *fn_80146310(void *collection, const char *wantedName, s32 unused) {
    /* Builds a result table for items in collection whose name matches wantedName:
       counts matches, allocates 0x10-byte header and array (0xC per entry) via fn_801284F8/fn_8012850C/fn_8002F37C,
       then appends each matching item with fn_80145670 and returns the header. */
    struct Result {
        void *data;
        s32 count;
        s32 size;
        void *end;
    };
    class Collection {
    public:
        virtual void a();
        virtual void *get(s32);
    };
    class Item {
    public:
        virtual const char *name();
    };

    Result *result;
    s32 size = fn_80145140(collection, wantedName);
    result = (Result *)fn_801284F8(0x10, lbl_8032D108);
    if (result != 0) {
        void *arena = fn_8012850C(size * 0xC + 0x10, lbl_80559E48);
        result->data = ((void *(*)(void *, void *, void *, s32, s32))fn_8002F37C)(
            arena, (void *)fn_8014647C,
            (void *)__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C, 0xC, size);
        result->size = size;
        result->count = 0;
        result->end = result->data;
    }

    s32 i = 0;
    while (1) {
        void *item = ((Collection *)collection)->get(i);
        if (item == 0)
            break;
        const char *name = ((Item *)item)->name();
        if (stricmp(name, wantedName) == 0) {
            s32 count = result->count;
            void *data = result->data;
            s32 offset = count * 0xC;
            result->count = count + 1;
            fn_80145670((char *)data + offset, item);
        }
        i++;
    }
    return result;
}
#pragma dont_inline reset
#pragma pop

extern "C" void *__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C(void *cacheTable, s32 shouldDelete) {
    /* Destroy J3DUMtxAnmCacheTableBase: release its cached matrix-animation data at +8 and optionally delete the object. */
    if (cacheTable != NULL) {
        void *mtxAnmCache = *(void **)((u8 *)cacheTable + 8);
        if (mtxAnmCache != NULL) {
            ((void (*)(void *))fn_80235380)(mtxAnmCache);
        }
        if (shouldDelete > 0) {
            fn_80128668(cacheTable);
        }
    }
    return cacheTable;
}

extern "C" void fn_8014647C(void *);
extern "C" void fn_8014647C(void *entry) {
    /* Zero one 0xC-byte "gart_set" table entry (name, resource_name, resource) before it is filled. */
    struct GArtSetEntry {
        void *name;
        void *resourceName;
        void *resource;
    };
    GArtSetEntry *e = (GArtSetEntry *)entry;
    e->name = 0;
    e->resourceName = 0;
    e->resource = 0;
}

extern "C" void fn_80128668(void *);
extern "C" void fn_80128670(s32);
extern "C" void fn_80131818(void * = 0);
extern "C" void fn_80145DD8(void *);
extern "C" void fn_80146584(void *);
extern "C" void fn_801465C8(void *);
extern "C" void fn_80146638(void *);
extern "C" void fn_801466B4(void *);
extern "C" void fn_80146730(void *);
extern "C" void fn_801467AC(void *);
extern "C" void fn_8002F6AC(s32, void *);

extern "C" void *fn_80146490(void *obj) {
    /* Returns obj if valid (flag at +0x28 nonzero); if the flag is zero,
       calls virtual destructor-like v0(1) and returns NULL. */
    struct Obj {
        virtual void *v0(s32);
    };
    if (obj != NULL) {
        if (((s32 *)obj)[10] == 0) {
            if (obj) {
                ((Obj *)obj)->v0(1);
            }
            return NULL;
        }
    }
    return obj;
}

#pragma dont_inline on
extern "C" void *fn_801464DC(void *obj, s32 shouldDelete) {
    /* Destructor-like cleanup for object with vtable lbl_8032D1E8: unregister, release member at 0x28, destroy subobjects, optionally delete self. */
    if (obj != NULL) {
        void *member28;
        *(void **)obj = &lbl_8032D1E8;
        fn_80145DD8(obj);
        member28 = *(void **)((u8 *)obj + 0x28);
        if (member28 != NULL) {
            fn_80131818(member28);
            *(void **)((u8 *)obj + 0x28) = NULL;
        }
        fn_80146584((u8 *)obj + 0x4C);
        fn_801465C8((u8 *)obj + 0x48);
        fn_80146638((u8 *)obj + 0x2C);
        fn_801466B4((u8 *)obj + 0x30);
        fn_80146730((u8 *)obj + 0x34);
        fn_801467AC((u8 *)obj + 0x3C);
        if (shouldDelete > 0) {
            fn_80128668(obj);
        }
    }
    return obj;
}

extern "C" void fn_80146584(void *object) {
    /* Free the owned buffer at offset 0 and clear the pointer. */
    void *buffer = *(void **)object;

    if (buffer != NULL) {
        fn_80128668(buffer);
        *(void **)object = NULL;
    }
}
extern "C" void fn_801465C8(void *slot) {
    /* Free and clear the heap object stored in *slot (frees its field at +0xC, resets fields, frees it). */
    void *obj = *(void **)slot;
    if (obj != NULL) {
        if (obj != NULL) {
            fn_80128670(((s32 *)obj)[3]);
            if (obj != NULL) {
                ((s32 *)obj)[0] = 0;
                ((s32 *)obj)[1] = 0;
                ((s32 *)obj)[2] = 0;
            }
            fn_80128668(obj);
        }
        *(void **)slot = NULL;
    }
}

/* Releases the name-matched item table an object holds in the slot it passes
   (its member at +0x2C): frees the item block the table's data points into
   (the block starts 0x10 bytes behind it), clears the table's header, frees
   the table itself and leaves the slot empty. */
extern "C" void fn_80146638(void *slot) {
    NamedItemTable80145FEC *table = *(NamedItemTable80145FEC **)slot;
    if (table != NULL) {
        if (table != NULL) {
            s32 items = (s32)table->end;
            if (items != 0) {
                fn_80128670(items - 0x10);
            }
            if (table != NULL) {
                table->data = NULL;
                table->count = 0;
                table->size = 0;
            }
            fn_80128668(table);
        }
        *(void **)slot = NULL;
    }
}

/* Releases the "text" item table an OverlayLayout object holds in the slot it is
   given (its member at +0x30): frees the block of 0x20-byte entries the table's
   data points into (the block starts 0x10 bytes behind it), clears the table's
   header, frees the table itself and leaves the slot empty. */
extern "C" void fn_801466B4(void *slot) {
    NamedItemTable80145FEC *table = *(NamedItemTable80145FEC **)slot;
    if (table != NULL) {
        if (table != NULL) {
            s32 items = (s32)table->end;
            if (items != 0) {
                fn_80128670(items - 0x10);
            }
            if (table != NULL) {
                table->data = NULL;
                table->count = 0;
                table->size = 0;
            }
            fn_80128668(table);
        }
        *(void **)slot = NULL;
    }
}

/* Releases the name-matched item table an object holds in the slot it passes
   (its member at +0x34): frees the item block the table's data points into
   (the block starts 0x10 bytes behind it), clears the table's header, frees
   the table itself and leaves the slot empty. */
extern "C" void fn_80146730(void *slot) {
    NamedItemTable80145FEC *table = *(NamedItemTable80145FEC **)slot;
    if (table != NULL) {
        if (table != NULL) {
            s32 items = (s32)table->end;
            if (items != 0) {
                fn_80128670(items - 0x10);
            }
            if (table != NULL) {
                table->data = NULL;
                table->count = 0;
                table->size = 0;
            }
            fn_80128668(table);
        }
        *(void **)slot = NULL;
    }
}

/* Releases an array-holding object stored in *slot: destroys its array at +0xC
   with __dt__24J3DUMtxAnmCacheTableBaseFv_8014641C via fn_8002F6AC, clears the
   object's fields, frees the object, and leaves the slot empty. */
extern "C" void fn_801467AC(void *slot) {
    void *object = *(void **)slot;
    if (object != 0) {
        if (object != 0) {
            fn_8002F6AC(((s32 *)object)[3], (void *)__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C);
            if (object != 0) {
                ((s32 *)object)[0] = 0;
                ((s32 *)object)[1] = 0;
                ((s32 *)object)[2] = 0;
            }
            fn_80128668(object);
        }
        *(void **)slot = 0;
    }
}

extern "C" char lbl_8032D114[];
extern "C" char lbl_8032D124[];
extern "C" char lbl_8055E20C[];
extern "C" char lbl_8055E210[];
extern "C" char lbl_8055E214[];
extern "C" char lbl_8055E218[];
extern "C" char lbl_8055E220[];
extern "C" f32 lbl_8056160C;
extern "C" f32 lbl_80561610;
extern "C" char lbl_8032D114[];
extern "C" char lbl_8032D124[];
extern "C" __declspec(section ".sdata") char lbl_80559E48[];
extern "C" __declspec(section ".sdata") char lbl_8055E20C[];
extern "C" __declspec(section ".sdata") char lbl_8055E210[];
extern "C" __declspec(section ".sdata") char lbl_8055E214[];
extern "C" __declspec(section ".sdata") char lbl_8055E218[];
extern "C" __declspec(section ".sdata") char lbl_8055E220[];
extern "C" __declspec(section ".sdata") f32 lbl_8056160C;
extern "C" __declspec(section ".sdata") f32 lbl_80561610;
extern "C" __declspec(section ".sdata") f32 lbl_805615D4;
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void fn_80146824(void *arg0)
{
  struct Block
  {
    s32 base;
    s32 count;
  };
  struct Record
  {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s32 value;
    char *label;
  };
  struct Data
  {
    Record *records;
    s32 count;
    volatile s32 capacity;
    Record *recordsAgain;
  };
  struct Proxy
  {
    s32 a;
    s32 b;
    u8 pad8[4];
    Data *data;
  };
  struct Owner
  {
    u8 pad[0x2C];
    Block *block2C;
    Block *block30;
    Block *block34;
    u8 pad38[0x10];
    Data *data;
    Proxy *proxy;
  };
  typedef void *(*AllocFn)(s32, const char *, s32, s32, s32, s32);
  Owner *owner = (Owner *) arg0;
  register Block *b2C = owner->block2C;
  register Block *b30 = owner->block30;
  register Block *b34 = owner->block34;
  register s32 n2C = b2C->count;
  register s32 n30 = b30->count;
  register s32 n34 = b34->count;
  register volatile long long size2C = n2C * 2;
  register unsigned size30 = (n30 * 4) - n30;
  register s32 size34 = (n34 * 4) - n34;
  Data *data = (Data *) ((AllocFn) fn_801284F8)(0x10, lbl_8032D114, n34, n30 * 4, n30, n2C);
  if (data != 0)
  {
    s32 total = ((size34 + size2C) + size30) + 1;
    data->records = (Record *) fn_8012850C(total * 0x18, lbl_80559E48);
    data->capacity = total;
    data->count = 0;
    data->recordsAgain = data->records;
  }
  owner->data = data;
  Proxy *proxy = (Proxy *) fn_801284F8(0x18, lbl_8032D124);
  if (proxy != 0)
  {
    Data *parent = owner->data;
    proxy->b = 0;
    proxy->a = 0;
    proxy->data = parent;
    owner->proxy = proxy;
  }
  Record *r1;
  for (s32 i = 0; i < owner->block2C->count; i++)
  {
    r1 = ((Record *) ((Data *) owner->proxy->data)->records) + (((Data *) owner->proxy->data)->count++);
    fn_80145B50(r1, 0);
    r1->value = owner->block2C->base + (i * 0x28);
    r1->label = lbl_8055E20C;
    r1 = ((Record *) ((Data *) owner->proxy->data)->records) + (((Data *) owner->proxy->data)->count++);
    fn_80145B50(r1, 1);
    r1->value = owner->block2C->base + (i * 0x28);
    r1->label = lbl_8055E210;
  }

  for (s32 i = 0; i < owner->block30->count; i++)
  {
    Record *r = ((Record *) ((Data *) owner->proxy->data)->records) + (((Data *) owner->proxy->data)->count++);
    fn_80145B50(r, 0);
    r->value = owner->block30->base + (i * 0x20);
    r->label = lbl_8055E20C;
    r = ((Record *) ((Data *) owner->proxy->data)->records) + (((Data *) owner->proxy->data)->count++);
    fn_80145B50(r, 1);
    r->value = owner->block30->base + (i * 0x20);
    r->label = lbl_8055E214;
    r = ((Record *) ((Data *) owner->proxy->data)->records) + (((Data *) owner->proxy->data)->count++);
    fn_80145B50(r, 2);
    r->value = owner->block30->base + (i * 0x20);
    r->label = lbl_8055E218;
  }

  for (s32 i = 0; i < owner->block34->count; i++)
  {
    Record *r = ((Record *) ((Data *) owner->proxy->data)->records) + (((Data *) owner->proxy->data)->count++);
    fn_80145B50(r, 0);
    r->value = owner->block34->base + (i * 0x1C);
    r->label = lbl_8055E20C;
    r = ((Record *) ((Data *) owner->proxy->data)->records) + (((Data *) owner->proxy->data)->count++);
    fn_80145B50(r, 1);
    r->value = owner->block34->base + (i * 0x1C);
    r->label = lbl_8055E210;
    r = ((Record *) ((Data *) owner->proxy->data)->records) + (((Data *) owner->proxy->data)->count++);
    fn_80145B50(r, 2);
    r->value = owner->block34->base + (i * 0x1C);
    r->label = lbl_8055E220;
  }

  register f32 third;
  register f32 second;
  register f32 first;
  char *label = ((char *) arg0) + 0x40;
  s32 zero = 0;
  first = lbl_805615D4;
  Record *records;
  Data *queue = owner->proxy->data;
  records = queue->records;
  second = lbl_8056160C;
  s32 count = queue->count;
  s32 byteOffset = count * 0x18;
  third = lbl_80561610;
  queue->count = count + 1;
  Record *last = (Record *) (((u8 *) records) + byteOffset);
  last->label = label;
  last->value = zero;
  last->f0 = first;
  last->f4 = first;
  last->f8 = second;
  last->fC = third;
}
extern "C" f32 fn_800108C8(const char *, f32);
extern "C" void fn_80235380();
extern "C" void fn_80145B94(void *, u32);
extern "C" void fn_80146BD4(u8 *dst, const s8 *src, s32 maxLen) {
    /* Bounded string copy: copy bytes from src to dst until NUL, or NUL-terminate at maxLen on truncation. */
    goto copy;
    for (;;) {
        if (--maxLen <= 0) {
            dst[-1] = 0;
            return;
        }
    copy:
        u8 c = (u8)*src;
        src++;
        *dst = c;
        dst++;
        if ((s8)c == 0) return;
    }
}

extern "C" void fn_80146C08(void *obj, s32 parent) {
    /* Initialise this sub-object: store the owner pointer at +0x4 and install its vtable (lbl_8032D214) at +0x0. */
    *(s32 *)((u8 *)obj + 4) = parent;
    *(void **)obj = (void *)&lbl_8032D214;
}

extern void lbl_8032D260(void);
/* Install the base-class vtable lbl_8032D260 at the start of the object (base-class constructor step). */
extern "C" void fn_80146C1C(void **vtableSlot) {
    *vtableSlot = (void *)&lbl_8032D260;
}

extern "C" char lbl_8032CEC8[];
extern "C" char lbl_80559E30[];
extern "C" char lbl_80559E34[];
extern "C" __declspec(section ".sdata") char lbl_80559E50[];
extern "C" __declspec(section ".sdata") char lbl_80559E58[];
extern "C" __declspec(section ".sdata") char lbl_80559E60[];
extern "C" __declspec(section ".data") void *lbl_8032D1D8;
extern "C" __declspec(section ".sdata") char lbl_80559DFC[];
#pragma opt_deadstores off
#pragma opt_common_subs off
extern "C" void *fn_80146C2C(s32 arg0, void *arg1, s32 arg2) {
    class Collection {
    public:
        virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3();
        virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7();
        virtual void c8(); virtual void c9(); virtual void c10(); virtual void c11();
        virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15();
        virtual void c16(); virtual void c17(); virtual void c18(); virtual void c19();
        virtual void c20(); virtual void c21();
        virtual void *get(s32);
    };
    class Item {
    public:
        virtual const char *name();
        virtual void i3(); virtual void i4(); virtual void *get(const char *, s32, void *);
        virtual void i6(); virtual void *get2(const char *);
    };
    class ItemShort {
    public:
        virtual const char *name();
        virtual void i3(); virtual void i4(); virtual void *get(const char *);
        virtual void i6(); virtual void i7();
    };
    struct Object {
        void *vtable;
        u8 flag;
        u8 pad5[3];
        s32 value;
        void *list0;
        void *list1;
        void *list2;
    };
    struct Result {
        void *data;
        s32 count;
        s32 size;
        void *end;
    };
    extern s32 fn_801454E8(void *, const char *);
    s32 dummy;
    s32 i;
    u32 count;
    Result *result;
    Object *object = (Object *)fn_801284F8(0x18, (char *)lbl_8032CEC8 + 0x26C);
    if (object != 0) {
        char *base = lbl_8032CEC8;
        char *search0 = base + 0x280;
        object->vtable = (void *)&lbl_8032D1D8;
        object->flag = 0;
        object->value = arg0;
        object->list0 = 0;
        object->list1 = 0;
        object->list2 = 0;
        dummy = 0;

        {
            count = 0;
            i = 0;
            while (1) {
                void *item = ((Collection *)arg1)->get(i);
                if (item == 0) break;
                if (stricmp(((Item *)item)->name(), search0) == 0) count++;
                i++;
            }
            result = (Result *)fn_801284F8(0x10, base + 0x28C);
            if (result != 0) {
                void *data = fn_8012850C(count * 8, lbl_80559E48);
                result->data = data;
                result->size = count;
                result->count = 0;
                result->end = data;
            }
            i = 0;
            while (1) {
                void *item = ((Collection *)arg1)->get(i);
                if (item == 0) break;
                if (stricmp(((Item *)item)->name(), search0) == 0) {
                    s32 index = result->count;
                    void **data = (void **)result->data;
                    void **record = (void **)((u8 *)data + index * 8);
                    result->count = index + 1;
                    record[0] = ((Item *)item)->get(lbl_80559E50, index, data);
                    record[1] = ((ItemShort *)item)->get(lbl_80559E34);
                }
                i++;
            }
            object->list0 = result;
        }

        {
            char *name1 = base + 0x29C;
            count = 0;
            i = 0;
            while (1) {
                void *item = ((Collection *)arg1)->get(i);
                if (item == 0) break;
                if (stricmp(((Item *)item)->name(), name1) == 0) count++;
                i++;
            }
            result = (Result *)fn_801284F8(0x10, base + 0x28C);
            if (result != 0) {
                void *data = fn_8012850C(count * 12, lbl_80559E48);
                result->data = data;
                result->size = count;
                result->count = 0;
                result->end = data;
            }
            i = 0;
            while (1) {
                void *item = ((Collection *)arg1)->get(i);
                if (item == 0) break;
                if (stricmp(((Item *)item)->name(), name1) == 0) {
                    s32 index = result->count;
                    void **data = (void **)result->data;
                    void **record = (void **)((u8 *)data + index * 12);
                    result->count = index + 1;
                    record[0] = ((Item *)item)->get(lbl_80559E50, index, data);
                    record[1] = ((ItemShort *)item)->get(lbl_80559E30);
                    record[2] = ((Item *)item)->get2(lbl_80559E58);
                }
                i++;
            }
            object->list1 = result;
        }

        {
            const char *name2 = lbl_80559E60;
            count = 0;
            i = 0;
            while (1) {
                void *item = ((Collection *)arg1)->get(i);
                if (item == 0) break;
                if (stricmp(((Item *)item)->name(), name2) == 0) count++;
                i++;
            }
            result = (Result *)fn_801284F8(0x10, base + 0x28C);
            if (result != 0) {
                void *data = fn_8012850C(count * 12, lbl_80559E48);
                result->data = data;
                result->size = count;
                result->count = 0;
                result->end = data;
            }
            i = 0;
            while (1) {
                void *item = ((Collection *)arg1)->get(i);
                if (item == 0) break;
                if (stricmp(((Item *)item)->name(), name2) == 0) {
                    s32 index = result->count;
                    void **data = (void **)result->data;
                    void **record = (void **)((u8 *)data + index * 12);
                    result->count = index + 1;
                    record[0] = ((Item *)item)->get(lbl_80559E50, index, data);
                    record[1] = ((ItemShort *)item)->get(lbl_80559E30);
                    record[2] = (void *)fn_801454E8(item, lbl_80559DFC);
                }
                i++;
            }
            object->list2 = result;
        }
    }
    return object;
}
#pragma opt_deadstores reset
#pragma opt_common_subs reset
extern "C" void fn_8002F6AC(s32, void *);
extern "C" void *__dt__24J3DUMtxAnmCacheTableBaseFv_8014641C(void *, s32);
extern "C" s32 fn_80147070(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
}

extern "C" void fn_802C8BD0(s32);
extern "C" s32 fn_802C8DBC(s32);
extern "C" void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
extern "C" void fn_802C8E48(void);
extern "C" void fn_802C8D74(void);
#pragma dont_inline on
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void fn_801470B0(s32 arg0, s32 arg1, s32 arg2, f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1) {
    f32 temp;

    /* Draw an axis-aligned quad as four vertices (two triangles/strip) when the draw state is ready. */
    fn_802C8BD0(arg1);
    if (fn_802C8DBC(4) != 0) {
        temp = fn_801452B4(y);
        fn_802C8E00(arg0, 0, ((f32 (*)(s32, f32))fn_801451DC)(arg2, x), temp, lbl_805615D4, u0, v0);
        temp = fn_801452B4(y);
        fn_802C8E00(arg0, 0, ((f32 (*)(s32, f32))fn_801451DC)(arg2, x + width), temp, lbl_805615D4, u1, v0);
        temp = fn_801452B4(y + height);
        fn_802C8E00(arg0, 1, ((f32 (*)(s32, f32))fn_801451DC)(arg2, x), temp, lbl_805615D4, u0, v1);
        temp = fn_801452B4(y + height);
        fn_802C8E00(arg0, 1, ((f32 (*)(s32, f32))fn_801451DC)(arg2, x + width), temp, lbl_805615D4, u1, v1);
        fn_802C8E48();
    }
    fn_802C8D74();
}
#pragma scheduling on
#pragma pop
#pragma dont_inline reset
extern "C" f32 fn_80147204(void *value, const char *text) {
    /* Parse a number from text (skipping a leading 0x01 tag byte), scaled by the
       value object's +0x10 field; return 0.0f when there is no value object. */
    if (value != 0) {
        if ((u8)*text == 1)
            text++;
        return fn_800108C8(text, *(f32 *)((u8 *)value + 0x10));
    }
    return lbl_805615D4;
}

extern "C" int vsprintf(char *, const char *, va_list);
extern "C" unsigned int strlen(const char *);
extern "C" void fn_802E317C(const char *, ...);
  extern "C" char lbl_8032D1A4[];
#pragma scheduling invalid_target
// Formats a string into a fixed buffer and applies it to the target if non-null, warning if the result is too large.
extern "C" void fn_80147230(void *arg0, const char *arg1, ...) {
    char buffer[0x200];
    if (arg0 != 0) {
        va_list args;
        va_start(args, arg1);
        vsprintf(buffer, arg1, args);
        if (strlen(buffer) >= 0x200)
            fn_802E317C(lbl_8032D1A4, strlen(buffer), arg1);
        fn_80145B94(arg0, (u32)buffer);
    }
}
#pragma scheduling on
extern "C" void fn_80145C08(void *arg0, const char *arg1);
extern "C" void fn_80147314(void *arg0, const char *format, ...) {
    /* Format varargs text into a stack buffer and pass it to the text renderer.
       If the formatted result would be >= 0x200 bytes (including terminator), log
       an oversized-text error via fn_802E317C with the length and format string,
       but still pass the buffer to fn_80145C08. No-op if arg0 is NULL. */
    char buffer[0x200];
    if (arg0 != 0) {
        va_list args;
        va_start(args, format);
        vsprintf(buffer, format, args);
        if (strlen(buffer) >= 0x200) {
            s32 length = strlen(buffer);
            fn_802E317C(lbl_8032D1A4, length, format);
        }
        fn_80145C08(arg0, buffer);
    }
}

extern int vsprintf(char *, const char *, va_list);
extern unsigned int strlen(const char *);
extern char lbl_8032D1A4[];

void fn_80145B94(void *, const char *);
extern "C" void fn_801473F8(void *arg0, s32 arg1, const char *format, ...) {
    /* Format text and apply it to the UI element returned by arg0's vtable slot 1.
     * Warns if the formatted string reaches the 0x200-byte buffer limit. */
    class UIElementAccessor {
    public:
        virtual void f0();
        virtual void *getElement();
    };
    char textBuffer[0x200];
    va_list args;
    void *element = ((UIElementAccessor *)arg0)->getElement();
    if (element != 0) {
        va_start(args, format);
        vsprintf(textBuffer, format, args);
        va_end(args);
        if (strlen(textBuffer) >= 0x200) {
            s32 textLength = strlen(textBuffer);
            fn_802E317C(lbl_8032D1A4, textLength, format);
        }
        fn_80145B94(element, (u32)textBuffer);
    }
}

#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void fn_801474EC(void *arg0, const char *arg1, ...) {
    /* Format varargs text into a stack buffer and append it to the text object.
       If the formatted result would be >= 0x200 bytes (including terminator), log
       an oversized-text error via fn_802E317C with the length and format string,
       but still pass the buffer to fn_80145C7C. No-op if arg0 is NULL. */
    char buffer[0x200];
    if (arg0 != 0) {
        va_list args;
        va_start(args, arg1);
        vsprintf(buffer, arg1, args);
        if (strlen(buffer) >= 0x200)
            fn_802E317C(lbl_8032D1A4, strlen(buffer), arg1);
        fn_80145C7C(arg0, (u32)buffer);
    }
}
#pragma dont_inline reset
#pragma scheduling on
/* Formats a printf-style message and sends it through the object's second virtual handler; logs when the text would exceed the 0x200-byte buffer. */
extern "C" void fn_801475D0(void *arg0, s32 arg1, const char *format, ...) {
    class V {
    public:
        virtual void f0();
        virtual void *f1();
    };
    char buffer[0x200];
    va_list args;
    void *result = ((V *)arg0)->f1();
    if (result != 0) {
        va_start(args, format);
        vsprintf(buffer, format, args);
        va_end(args);
        if (strlen(buffer) >= 0x200) {
            s32 length = strlen(buffer);
            fn_802E317C(lbl_8032D1A4, length, format);
        }
        fn_80145C7C(result, (u32)buffer);
    }
}

/* Draw this text entry using the text/value pointer held in its +0x1C field. */
extern "C" void fn_801476C4(void *entry) {
    if (entry != 0)
        fn_80145B94(entry, *(u32 *)((u8 *)entry + 0x1c));
}

#pragma scheduling on
void fn_801476D8(void *arg0, s32 arg1, s32 arg2) {
    extern s32 fn_802C8DBC(s32);
    extern void fn_802C8BD0(s32);
    extern void fn_802C8E00(s32, s32, f32, f32, f32, f32, f32);
    extern void fn_802C8E48(void);
    extern void fn_802C8D74(void);
    extern f32 fn_801452A0(s32, f32);
    f32 angle;
    register f32 tx;
    if (arg0 != 0) {
        fn_802C8BD0(arg2);
        if (fn_802C8DBC(4) != 0) {
            angle = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
            {
                f32 x = *(volatile f32 *)((u8 *)arg0 + 4);
                u32 mode = *(volatile s32 *)((u8 *)arg0 + 0xC);
                tx = ((f32 (*)(s32, f32))fn_801451DC)(mode, x);
            }
            fn_802C8E00(arg1, 0, tx, angle, lbl_805615D4,
                        *(f32 *)((u8 *)arg0 + 0x18),
                        *(f32 *)((u8 *)arg0 + 0x1C));

            angle = fn_801452B4(*(f32 *)((u8 *)arg0 + 8));
            {
                f32 scaleInput = *(volatile f32 *)((u8 *)arg0 + 0x10);
                s32 mode = *(volatile s32 *)((u8 *)arg0 + 0xC);
                tx = fn_801452A0(mode, scaleInput);
            }
            tx += ((f32 (*)(s32, f32))fn_801451DC)(
                *(volatile s32 *)((u8 *)arg0 + 0xC),
                *(volatile f32 *)((u8 *)arg0 + 4));
            fn_802C8E00(arg1, 0, tx, angle, lbl_805615D4,
                        *(f32 *)((u8 *)arg0 + 0x20),
                        *(f32 *)((u8 *)arg0 + 0x1C));

            angle = fn_801452B4(*(f32 *)((u8 *)arg0 + 8) +
                                *(f32 *)((u8 *)arg0 + 0x14));
            {
                f32 x = *(volatile f32 *)((u8 *)arg0 + 4);
                s32 mode = *(volatile s32 *)((u8 *)arg0 + 0xC);
                tx = ((f32 (*)(s32, f32))fn_801451DC)(mode, x);
            }
            fn_802C8E00(arg1, 1, tx, angle, lbl_805615D4,
                        *(f32 *)((u8 *)arg0 + 0x18),
                        *(f32 *)((u8 *)arg0 + 0x24));

            angle = fn_801452B4(*(f32 *)((u8 *)arg0 + 8) +
                                *(f32 *)((u8 *)arg0 + 0x14));
            {
                f32 scaleInput = *(volatile f32 *)((u8 *)arg0 + 0x10);
                s32 mode = *(volatile s32 *)((u8 *)arg0 + 0xC);
                tx = fn_801452A0(mode, scaleInput);
            }
            tx += ((f32 (*)(s32, f32))fn_801451DC)(
                *(volatile s32 *)((u8 *)arg0 + 0xC),
                *(volatile f32 *)((u8 *)arg0 + 4));
            fn_802C8E00(arg1, 1, tx, angle, lbl_805615D4,
                        *(f32 *)((u8 *)arg0 + 0x20),
                        *(f32 *)((u8 *)arg0 + 0x24));
            fn_802C8E48();
        }
        fn_802C8D74();
    }
}

extern "C" void fn_8014784C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    /* Resolve two virtual slots from arg0 (first() and second(arg2)); if both are non-null, forward them to fn_80145CF4 with arg3. */
    class V {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual s32 first();
        virtual s32 second(s32);
    };
    s32 firstResult;
    s32 secondResult;
    firstResult = ((V *)arg0)->first();
    secondResult = ((V *)arg0)->second(arg2);
    if (firstResult != 0 && secondResult != 0)
        ((void (*)(void *, void *, u32))fn_80145CF4)((void *)firstResult, (void *)secondResult, (u32)arg3);
}

#pragma push
#pragma dont_inline on
extern "C" void fn_801478E0(void *widget, s32 unused, s32 resource, s32 flags) {
    /* Look up a text entry via the widget's vtable (slot 3); if found and a resource is provided, draw it with fn_80145CF4. */
    class V {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual s32 f3();
    };
    s32 textEntry = ((V *)widget)->f3();
    if (textEntry != 0 && resource != 0)
        fn_80145CF4((void *)textEntry, (void *)resource, (u32)flags);
}
#pragma pop
#pragma dont_inline on
#pragma push
extern "C" void fn_80147940(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    /* Look up an object via arg0's vtable (slot f(arg2)); if arg1 and the result are non-null, forward them to fn_80145CF4. */
    class V {
    public:
        virtual void a();
        virtual void b();
        virtual void c();
        virtual void d();
        virtual s32 f(s32);
    };
    s32 result = ((V *)arg0)->f(arg2);
    if (arg1 != 0 && result != 0)
        fn_80145CF4((void *)arg1, (void *)result, (u32)arg3);
}
#pragma dont_inline reset
#pragma pop
  extern "C" void fn_80147CEC(void *, s32, s32, f64);
/* Formats a message with vsprintf, checks for overflow, builds a prefix via fn_80147CEC, then forwards it for output. */
extern "C" void fn_801479A8(void *param0, void *param1, const char *format, f64 value, ...) {
    char formattedText[0x200];
    char prefix[0x20];
    va_list args;
    va_start(args, value);
    vsprintf(formattedText, format, args);
    if (strlen(formattedText) >= 0x200)
        fn_802E317C(lbl_8032D1A4, strlen(formattedText), format);
    fn_80147CEC(prefix, (s32)param0, (s32)param1, value);
    fn_80147230(prefix, (const char *)&lbl_80559E1C, formattedText);
}

/* Formats a message with vsprintf, checks for buffer overflow, builds a prefix, and emits the final log line. */
extern "C" void fn_80147ABC(void *arg0, void *arg1, const char *format, f64 value, ...) {
    char text[0x200];
    char prefixBuffer[0x20];
    va_list args;
    va_start(args, value);
    vsprintf(text, format, args);
    if (strlen(text) >= 0x200)
        fn_802E317C(lbl_8032D1A4, strlen(text), format);
    fn_80147CEC(prefixBuffer, (s32)arg0, (s32)arg1, value);
    fn_80147314(prefixBuffer, (const char *)&lbl_80559E1C, text);
}

/* --- a 2D icon style of the on-screen drawing code ------------------------ */
/* 0x28 bytes.  fn_80147DC0 interpolates one of these toward another (every
   field but the word at 0x00), and fn_801476D8 draws one: it maps the
   position through the screen-edge placement modes fn_801451DC knows about
   and hands the four corners of the box to the draw list. */
struct DrawStyle80147BD0 {
    u32 kind;      /* 0x00 copied as-is, never interpolated */
    f32 x;         /* 0x04 */
    f32 y;         /* 0x08 */
    u32 mode;      /* 0x0C placement flags, read by fn_801451DC/fn_801452A0 */
    f32 width;     /* 0x10 divided by the aspect ratio when mode & 0x20 */
    f32 height;    /* 0x14 added to y for the far edge */
    f32 corner_x0; /* 0x18 */
    f32 corner_y0; /* 0x1C */
    f32 corner_x1; /* 0x20 */
    f32 corner_y1; /* 0x24 */
};

/* Draws one icon whose style is part-way between two: fills a temporary style
 * by interpolating the one at style toward the one at target by t (fn_80147DC0
 * copies the word at 0x00 and lerps the rest), interpolates the packed colour
 * from color toward targetColor by the same t, and draws the result into the
 * draw list given by drawList. */
extern "C" void fn_80147BD0(DrawStyle80147BD0 *style, DrawStyle80147BD0 *target,
                            u32 color, u32 targetColor, s32 drawList, f32 t) {
    s32 record[12]; /* the style fn_80147DC0 fills in and fn_801476D8 draws */
    ((void (*)(void *, s32, s32))fn_80147DC0)((u32 *)record, (s32)style, (s32)target);
    fn_801476D8((u32 *)record, fn_80147C50(color, targetColor, t), drawList);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_80147C50(u32 arg0, u32 arg1, f32 arg2) {
    /* Lerp each byte of a packed 32-bit color value from arg0 toward arg1 by arg2. */
    s32 a = fn_801450A0(arg0 & 0xFF, arg1 & 0xFF, arg2);
    s32 b = fn_801450A0((arg0 >> 8) & 0xFF, (arg1 >> 8) & 0xFF, arg2);
    s32 c = fn_801450A0((arg0 >> 16) & 0xFF, (arg1 >> 16) & 0xFF, arg2);
    s32 d = fn_801450A0(arg0 >> 24, arg1 >> 24, arg2);
    s32 lo = (a & 0xFF) | ((b & 0xFF) << 8);
    s32 hi = ((d & 0xFF) << 24) | ((c & 0xFF) << 16);
    return lo | hi;
}
#pragma scheduling invalid_target
extern "C" void fn_80147CEC(void *arg0, s32 arg1, s32 arg2, f64 arg3)
{
  union Pair
  {
    struct 
    {
      f32 x;
      f32 y;
    } f;
    f64 raw;
  };
  u8 *dst = (u8 *) arg0;
  u8 *src = (u8 *) arg1;
  u8 *other = (u8 *) arg2;
  f32 factor = (f32) arg3;
  f32 zSource = *((f32 *) (src + 0x10));
  f32 zOther = *((f32 *) (other + 0x10));
  f32 yOther = *((f32 *) (other + 8));
  f32 xOther = *((f32 *) (other + 4));
  f32 xSource = *((f32 *) (src + 4));
  f32 ySource = *((f32 *) (src + 8));
  yOther = yOther - ySource;
  xOther = xOther - xSource;
  zOther = zOther - zSource;
  f32 y = ySource + (factor * yOther);
  f32 x = xSource + (factor * xOther);
  f32 z = zSource + (factor * zOther);
  Pair second;
  Pair first;
  first.f.y = y;
  first.f.x = x;
  second.raw = first.raw;
  u32 w1c = *((u32 *) (src + 0x1C));
  u32 w18 = *((u32 *) (src + 0x18));
  u32 w14 = *((u32 *) (src + 0x14));
  u32 wc = *((u32 *) (src + 0xC));
  u32 w0 = *((u32 *) (src + 0));
  u32 w4 = *((u32 *) (src + 4));
  u32 w8 = *((u32 *) (src + 8));
  u32 other18 = *((u32 *) (other + 0x18));
  volatile u32 *d = (volatile u32 *) dst;
  *((f32 *) (dst + 0x10)) = zSource;
  d[1] = w4;
  d[2] = w8;
  d[0] = w0;
  d[3] = wc;
  d[5] = w14;
  d[6] = w18;
  d[7] = w1c;
  *((f32 *) (dst + 4)) = second.f.x;
  *((f32 *) (dst + 8)) = second.f.y;
  *((f32 *) (dst + 0x10)) = z;
  d[6] = fn_80147C50(w18, other18, factor);
}
extern "C" void fn_80147DC0(void *dst, s32 srcArg, s32 endArg, f32 t)
{
  struct State
  {
    u32 m0;
    f32 m4;
    f32 m8;
    u32 mC;
    f32 m10;
    f32 m14;
    f32 m18;
    f32 m1C;
    f32 m20;
    f32 m24;
  };
  union Pair
  {
    struct 
    {
      f32 x;
      f32 y;
    } f;
    f64 raw;
  };
  volatile State *src = (volatile State *) srcArg;
  volatile State *end = (volatile State *) endArg;
  register f32 out4;
  register f32 out8;
  f32 end4;
  f32 src4;
  f32 end8;
  f32 src8;
  f32 diff8;
  f32 src18;
  f32 diff4;
  f32 src10;
  f32 prod8;
  f32 src1C;
  f32 prod4;
  f32 src20;
  f32 end20;
  f32 diff20;
  f32 end18;
  f32 end1C;
  f32 diff18;
  f32 end10;
  f32 diff1C;
  f32 src14;
  f32 diff10;
  f32 prod18;
  f32 prod20;
  f32 prod1C;
  f32 prod10;
  f32 out20;
  f32 end24;
  f32 end14;
  f32 src24;
  f32 diff24;
  f32 out18;
  f32 diff14;
  f32 out1C;
  f32 prod24;
  f32 prod14;
  f32 out10;
  f32 out24;
  f32 out14;
  u32 w4;
  u32 w0;
  u32 wC;
  u32 w8;
  f64 pair;
  end8 = end->m8;
  src8 = src->m8;
  end4 = end->m4;
  src4 = src->m4;
  diff8 = end8 - src8;
  src18 = src->m18;
  diff4 = end4 - src4;
  src10 = src->m10;
  prod8 = t * diff8;
  src1C = src->m1C;
  prod4 = t * diff4;
  out8 = src8 + prod8;
  src20 = src->m20;
  end20 = end->m20;
  out4 = src4 + prod4;
  {
    Pair p;
    p.f.x = out4;
    p.f.y = out8;
    pair = p.raw;
  }
  diff20 = end20 - src20;
  end18 = end->m18;
  end1C = end->m1C;
  diff18 = end18 - src18;
  end10 = end->m10;
  diff1C = end1C - src1C;
  src14 = src->m14;
  diff10 = end10 - src10;
  prod18 = t * diff18;
  w4 = *((u32 *) (((u8 *) srcArg) + (4 & 0xFF)));
  prod20 = t * diff20;
  w0 = *((u32 *) (((u8 *) srcArg) + 0));
  prod1C = t * diff1C;
  prod10 = t * diff10;
  wC = *((u32 *) (((u8 *) srcArg) + 0xC));
  out20 = src20 + prod20;
  end24 = end->m24;
  end14 = end->m14;
  src24 = src->m24;
  diff24 = end24 - src24;
  w8 = *((u32 *) (((u8 *) srcArg) + 8));
  out18 = src18 + prod18;
  diff14 = end14 - src14;
  out1C = src1C + prod1C;
  prod24 = t * diff24;
  prod14 = t * diff14;
  out10 = src10 + prod10;
  out24 = src24 + prod24;
  out14 = src14 + prod14;
  volatile State *d = (volatile State *) dst;
  d->m18 = src18;
  d->m1C = src1C;
  d->m10 = src10;
  *((volatile u32 *) (((u8 *) dst) + 4)) = w4;
  *((volatile u32 *) (((u8 *) dst) + 8)) = w8;
  *((volatile u32 *) (((u8 *) dst) + 0)) = w0;
  *((volatile u32 *) (((u8 *) dst) + 0xC)) = wC;
  {
    Pair p;
    p.raw = pair;
    d->m4 = p.f.x;
    d->m8 = p.f.y;
  }
  d->m18 = out18;
  d->m20 = out20;
  d->m1C = out1C;
  d->m24 = out24;
  d->m10 = out10;
  d->m14 = out14;
}

#pragma dont_inline off
extern "C" void fn_80147EE0(void *arg0, f32 scale) {
    f32 x = *(f32 *)((u8 *)arg0 + 0x10);
    f32 decay = lbl_805615D0;
    f32 y = *(f32 *)((u8 *)arg0 + 0x14);
    f32 dx = x * scale;
    f32 gx = x * decay;
    f32 xpos = *(f32 *)((u8 *)arg0 + 4);
    f32 dy = y * scale;
    f32 gy = y * decay;
    f32 ypos = *(f32 *)((u8 *)arg0 + 8);
    *(f32 *)((u8 *)arg0 + 0x14) = dy;
    xpos = xpos + gx;
    scale = dx * decay;
    *(f32 *)((u8 *)arg0 + 0x10) = dx;
    ypos = ypos + gy;
    decay = dy * decay;
    *(f32 *)((u8 *)arg0 + 4) = xpos - scale;
    *(f32 *)((u8 *)arg0 + 8) = ypos - decay;
}

extern "C" void fn_80011630(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
#pragma dont_inline fn_801452B4
/* Transform the first two float coordinates and forward the full argument set to fn_80011630. */
extern "C" void fn_80147F30(s32 color, s32 param1, s32 layer,
                            f32 x, f32 y, f32 z, f32 scaleX,
                            f32 scaleY, f32 rot, f32 param7, f32 param8,
                            f32 param9, f32 param10) {
    f32 transformedY = fn_801452B4(y);
    f32 transformedX = ((f32 (*)(s32, f32))fn_801451DC)(0, x);
    fn_80011630(color, param1, layer, transformedX, transformedY, z, scaleX,
                scaleY, rot, param7, param8, param9, param10);
}
/* Draw the 9-slice frame the style describes: fn_80011278 lays the default
 * art set's nine pictures (four corners, four edges, centre) over the box,
 * tinted with the packed colour `color`.  The width is unscaled by the
 * aspect ratio when the style's 0x20 placement flag is set, and the position
 * goes through the letterbox/widescreen transforms (fn_801451DC slides x
 * toward the screen edge, fn_801452B4 flips y to the drawer's origin). */
extern "C" void fn_80147FF0(void * __restrict arg0, s32 color) {
    DrawStyle80147BD0 *style = (DrawStyle80147BD0 *)arg0;
    f32 screenY;
    f32 scaledWidth;
    f32 width = style->width;
    s32 mode = style->mode;
    scaledWidth = fn_801452A0(mode, width);
    screenY = fn_801452B4(style->y);
    f32 x = style->x;
    s32 placeMode = style->mode;
    f32 screenX = ((f32 (*)(s32, f32))fn_801451DC)(placeMode, x);
    fn_80011278(color, screenX, screenY, scaledWidth, style->height);
}

extern "C" void fn_80011280(s32, s32, f64, f64, f32, f32);
#pragma scheduling invalid_target
extern "C" void fn_80148070(void *__restrict arg0, s32 arg1, s32 arg2) {
    /* Compute transformed coordinates/scales from state at arg0 and forward to fn_80011280. */
    f32 temp_f31;
    f32 temp_f30;
    f32 yScale = *(f32 *)((u8 *)arg0 + 0x10);
    s32 mode = *(s32 *)((u8 *)arg0 + 0xC);
    temp_f30 = fn_801452A0(mode, yScale);
    temp_f31 = fn_801452B4(*(f32 *)((u8 *)arg0 + 0x8));
    f32 x = *(f32 *)((u8 *)arg0 + 0x4);
    s32 xMode = *(s32 *)((u8 *)arg0 + 0xC);
    ((void (*)(s32, s32, f64, f64, f32, f32))fn_80011280)(arg1, arg2, ((f64 (*)(s32, f32))fn_801451DC)(xMode, x), temp_f31, temp_f30, *(f32 *)((u8 *)arg0 + 0x14));
}
#pragma scheduling on

extern "C" void *lbl_8032D1D8;
extern "C" f32 fn_801452B4(f32);
extern "C" f32 lbl_805615D4;
extern "C" void fn_801470B0(s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void fn_80148100(void *pane) {
    /* Draw an untextured quad from the 2D pane descriptor at `pane`: x/y/width/height, coordinate mode and draw state. */
    f32 x = *(f32 *)((u8 *)pane + 4);
    f32 y = *(f32 *)((u8 *)pane + 8);
    f32 width = *(f32 *)((u8 *)pane + 0x10);
    f32 height = *(f32 *)((u8 *)pane + 0x14);
    s32 drawState = *(s32 *)((u8 *)pane + 0x18);
    s32 mode = *(s32 *)((u8 *)pane + 0xC);
    fn_801470B0(drawState, -1, mode, x, y, width, height,
        lbl_805615D4, lbl_805615D4, lbl_805615D4, lbl_805615D4);
}

#pragma dont_inline on
extern "C" void fn_80148134(f32 *outX, f32 *outY, s32 mode, f32 inputX, f32 inputY) {
    /* Computes screen-space X/Y outputs into the provided pointers when non-null, using helpers for axis conversion. */
    if (outX == 0) goto computeY;
    *outX = ((f32 (*)(s32, f32))fn_801451DC)(mode, inputX);
computeY:
    if (outY == 0) goto done;
    *outY = fn_801452B4(inputY);
done:
    return;
}
#pragma dont_inline reset
extern "C" void fn_8014819C(void *out, f32 deltaX, f32 deltaY) {
    // Copies the current screen-space origin (lbl_8055E200/lbl_8055E204, the 2D translation added by the
    // screen-coordinate helpers fn_801451DC/fn_801452B4) into out as two consecutive floats, then advances it by the delta.
    *(f32 *)out = lbl_8055E200;
    *(f32 *)((u8 *)out + 4) = lbl_8055E204;
    lbl_8055E200 += deltaX;
    lbl_8055E204 += deltaY;
}

extern "C" void *fn_80148294(const char *, void *);
extern "C" f32 lbl_8055E200;
extern "C" f32 lbl_8055E204;
// Captures the first two floats from an object and optionally finalizes it when the flag is positive.
extern "C" void *fn_801481C8(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        lbl_8055E200 = *(f32 *)arg0;
        lbl_8055E204 = *(f32 *)((u8 *)arg0 + 4);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

/* Does nothing: the first of the five default (unimplemented) virtuals of this
 * file's UI class group -- the run of stubs fn_80148218 / fn_8014821C /
 * fn_80148224 / fn_80148228 / fn_8014822C that sits between the 2D-drawing
 * helpers (fn_80148100 .. fn_801481C8) and the adapter sub-object's virtuals
 * (fn_80148230 .. fn_80148280, vtable lbl_8032D214).  Nothing in the game's
 * code names them, so they run only through the pointer table they sit in. */
extern "C" void fn_80148218(void) {
}

/* No-op predicate stub in this callback group: always reports 0 (false). */
extern "C" s32 fn_8014821C(void) {
    return 0;
}

/* No-op default implementation: the third of the five unimplemented virtuals
 * fn_80148218 / fn_8014821C / fn_80148224 / fn_80148228 / fn_8014822C, a run
 * of empty callbacks between this file's 2D-drawing helpers and the adapter
 * sub-object's virtuals (vtable lbl_8032D214). Nothing calls it by name, so it
 * runs only through the pointer table its slot occupies. */
extern "C" void fn_80148224(void) {
}

/* No-op default implementation: the last of the four unimplemented virtual
 * stubs fn_80148218 / fn_8014821C / fn_80148224 / fn_80148228 that sit between
 * this file's 2D-drawing helpers (fn_80148100 .. fn_801481C8) and the adapter
 * sub-object's virtuals (fn_80148230 .. fn_80148280, vtable lbl_8032D214).
 * Nothing in the game's code calls it by name, so it runs only when reached
 * through the pointer table its entry sits in. */
extern "C" void fn_80148228(void) {
}

/* No-op stub in this callback/vtable group; does nothing. */
extern "C" void fn_80148244(void) {
}

/* Default answer of the adapter sub-object's virtual at slot 0x34 of vtable
   lbl_8032D214 (installed by fn_80146C08 at +0x40 of the object fn_80145E70
   builds).  That sub-object forwards most of its calls to its owner (kept at
   +4, see fn_80148250) and answers the rest with defaults (-1 index,
   DISABLED_ITEM_COLOR); this query has nothing to report, so it says no. */
extern "C" s32 fn_80148248(void) {
    return 0;
}

extern "C" void fn_80148250(void *params) {
    /* Calls virtual slot 8 (offset 0x28) of the interface vtable stored at +4 of this params object. */
    struct VTable {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
    };
    VTable *vtable = *(VTable **)((u8 *)params + 4);
    vtable->f8();
}

extern "C" u32 lbl_80559E68;
/* Return the address of the static "Save" label string held in lbl_80559E68. */
extern "C" u32 *fn_80148264(void) {
    return &lbl_80559E68;
}

/* SDK DVDGetCurrentDiskID: this build has no on-disc ID loaded, so it returns the
 * fixed address 0x40000000 (normally the address of the current DVDDiskID). */
extern "C" s32 DVDGetCurrentDiskID(void) {
    return 0x40000000;
}

/* Fixed-value stub: always returns the sentinel constant 0xC0C0C0C0. */
extern "C" s32 fn_80148274(void) {
    return 0xC0C0C0C0;
}

/* Empty destructor of the adapter sub-object (the one fn_80146C08 installs at
 * +0x40 of its owner).  Its vtable lbl_8032D214 replaces the base class's
 * deleting destructor (slot 0x8 of the base vtable lbl_8032D260 ->
 * fn_80007A84, which frees the object when the delete flag is positive) with a
 * no-op, because this sub-object is embedded in its owner and is never freed
 * on its own; the same empty body also answers the base's pure virtual at slot
 * 0x24. */
extern "C" void fn_80148280(void) {

}

/* Look up a 0x20-byte table entry by name: obj holds the table pointer at +0x30 and name is the case-insensitive lookup key. */
extern "C" void fn_80148284(void *obj, s32 name) {
    fn_80148294((const char *)name, *(void **)((u8 *)obj + 0x30));
}

#pragma push
#pragma use_lmw_stmw off
/* Find a 0x20-byte table entry by case-insensitively matching its name string. */
extern "C" void *fn_80148294(const char *name, void *table) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)table + 4)) {
        if (stricmp(*(const char **)(*(u32 *)table + offset), name) == 0) {
            return (void *)(*(u32 *)table + i * 0x20);
        }
        offset += 0x20;
        i++;
    }
    return NULL;
}
#pragma pop
extern "C" void *fn_80148334(s32, s32, void *);
/* Look up a 0x28-byte table entry by name: obj holds the table pointer at +0x2C and name is the case-insensitive lookup key. */
extern "C" void fn_80148324(void *obj, s32 name) {
    fn_80148334(name, *(s32 *)((u8 *)obj + 0x2C), obj);
}

/* Find a 0x28-byte table entry by case-insensitively matching its name string. */
extern "C" void *fn_80148334(s32 name, s32 table, void *unused) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)table + 4)) {
        if (stricmp(*(const char **)(*(u32 *)table + offset), (const char *)name) == 0) {
            return (void *)(*(u32 *)table + i * 0x28);
        }
        offset += 0x28;
        i++;
    }
    return NULL;
}

extern "C" void *fn_801483D4(const char *, void *);
/* Look up a 0x1C-byte table entry by name: obj holds the table pointer at +0x34 and name is the case-insensitive lookup key. */
extern "C" void fn_801483C4(void *obj, s32 name) {
    fn_801483D4((const char *)name, *(void **)((u8 *)obj + 0x34));
}

#pragma push
#pragma use_lmw_stmw off
/* Finds an entry in a table by case-insensitively matching its name string. */
extern "C" void *fn_801483D4(const char *name, void *table) {
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)table + 4)) {
        if (stricmp(*(const char **)(*(u32 *)table + offset), name) == 0) {
            return (void *)(*(u32 *)table + i * 0x1C);
        }
        offset += 0x1C;
        i++;
    }
    return NULL;
}
#pragma pop

extern "C" void *fn_801484A4(const char *, void *);
/* Returns the resource stored in the named "gart_set" entry of this params object, or 0 if absent. */
extern "C" s32 fn_80148464(void *params, const char *name) {
#define findNamedEntry fn_801484A4
    void *entry = findNamedEntry(name, *(void **)((u8 *)params + 0x3C));
    if (entry != NULL) return *(s32 *)((u8 *)entry + 8);
    return 0;
#undef findNamedEntry
}

extern "C" int stricmp(const char *, const char *);
#pragma push
#pragma use_lmw_stmw off
extern "C" void *fn_801484A4(const char *arg0, void *arg1) {
    /* Find a 0xC-byte table entry by case-insensitively matching its name string. */
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)((u8 *)arg1 + 4)) {
        if (stricmp(*(const char **)(*(u32 *)arg1 + offset), arg0) == 0) {
            return (void *)(*(u32 *)arg1 + i * 0xC);
        }
        offset += 0xC;
        i++;
    }
    return NULL;
}
#pragma pop
extern "C" {
char *fn_80029004(char *, int);
char *strcpy(char *, const char *);
char *strchr(const char *, int);
s32 FileOpenSecondary(const char *);
void fn_802E3734(s32 *);
__declspec(section ".sdata") extern char lbl_80559E70[5];
extern char lbl_8032D28C[];
}
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_80148534(void *arg0) {
    /* Replace an object's name extension with ".txt", resolve it, apply loaded data to sub-objects at +0x2C/+0x30/+0x34/+0x3C, and release the handle. */
    strcpy(fn_80029004((char *)arg0 + 5, '.'), lbl_80559E70);
    char *name = (char *)arg0;
    name += 5;
    if (strchr(name, '/') != 0)
        name = strchr(name, '/') + 1;
    s32 value = FileOpenSecondary(name);
    if (value != -1) {
        fn_802E3AD0(value, lbl_8032D28C, 1);
        fn_801457D0(*(void **)((u8 *)arg0 + 0x2C), value);
        fn_801456E8(*(void **)((u8 *)arg0 + 0x30), value);
        fn_8014589C(*(void **)((u8 *)arg0 + 0x34), value);
        fn_8014595C(*(void **)((u8 *)arg0 + 0x3C), (const char *)value);
        fn_802E3AD0(value, lbl_80559E14);
        fn_802E3734(&value);
    }
}
#pragma scheduling on
#pragma dont_inline reset
extern "C" void fn_80148610(void *obj) {
    /* Toggle the boolean "enabled" flag (byte at offset 4) of this object. */
    bool *enabled = (bool *)((u8 *)obj + 4);
    *enabled = !*enabled;
}

/* Return this object's "enabled" boolean flag (the byte at offset 4). */
extern "C" u8 fn_80148624(void *obj) { return ((u8 *)obj)[4]; }

extern "C" s32 fn_80127A50(void *);
extern "C" void fn_80010B80(s32, f32, f32, f32, f32);
extern "C" f32 lbl_80558DC4;
extern "C" f32 __fabsf(f32);
extern "C" f32 lbl_80561614;
extern "C" f32 lbl_8056161C;
extern "C" f32 lbl_80561618;
extern "C" f32 lbl_80561620;
extern "C" f32 lbl_80561624;
extern "C" char lbl_8032D2B0[];
extern "C" void fn_8014862C(void *arg0) {
    struct Table { void *data; s32 count; s32 cap; void *end; };
    struct Cur { void *cur; void *sel; u8 flag; u8 p1[7]; f32 x10; f32 y14; struct Table *tab; };
    struct Obj { u8 pad[4]; u8 en; u8 p[39]; struct Table *t2c; u8 pad2[4]; struct Table *t34; u8 q[0x14]; struct Cur *cur; };
    struct Obj *obj = (struct Obj *)arg0;
    if (obj->en == 0) return;
    f32 eps = lbl_80558DC4;
    f32 zero = lbl_805615D4;
    (void)zero;
    while (fn_80127A50(arg0) != 0) {
        struct Cur *cur = obj->cur;
        u8 sbuf[0x40]; FloatPair80145A24 pp = fn_80145A24((void *)sbuf);
        f64 pair = *(f64 *)&pp;
        f32 px = ((f32 *)&pair)[0]; f32 py = ((f32 *)&pair)[1];
        if (cur->cur != 0) {
            if ((((s32 *)sbuf)[9] & 1) != 0) {
                f32 dx = px - cur->x10;
                f32 dy = py - cur->y14;
                float adx = __fabsf(dx);
                float ady = __fabsf(dy);
                cur->x10 = dx; cur->y14 = dy;
                if (!(adx <= eps) || !(ady <= eps)) cur->flag = 1;
                void *o = cur->cur;
                void **vt = *(void ***)o;
                void (*fn)(void *, f32 *, void *) = (void (*)(void *, f32 *, void *))vt[2];
                f32 tmp[2]; tmp[0]=dx; tmp[1]=dy;
                fn(o, tmp, *(void **)((u8 *)o + 0x10));
            } else {
                if (cur->flag == 0 && ((s32 *)sbuf)[0] == 1) {
                    void *o2 = cur->cur;
                    void **vt2 = *(void ***)o2;
                    void (*fn2)(void *) = (void (*)(void *))vt2[5];
                    fn2(o2);
                }
                cur->cur = 0;
            }
        } else {
            struct Table *t = cur->tab;
            void *cand[10]; s32 nc = 0;
            for (s32 i = 0; i < t->count; i++) {
                u8 *e = (u8 *)t->data + i * 0x18;
                if (*(s32 *)(e + 0x14) == 0) continue;
                u8 *pr = *(u8 **)(e + 0x10);
                if (pr == 0) continue;
                f32 x0 = *(f32 *)(e + 0) + *(f32 *)(pr + 4);
                if (!(px == x0)) {
                    if (!(px >= x0)) continue;
                    if (!(px < (*(f32 *)(e + 8) + x0))) continue;
                    f32 y0 = *(f32 *)(e + 4) + *(f32 *)(pr + 8);
                    if (!(py == y0)) {
                        if (!(py >= y0)) continue;
                        if (!(py < (*(f32 *)(e + 0xC) + y0))) continue;
                        if (nc < 10) cand[nc++] = e;
                    }
                }
            }
            void *pick = nc >= 1 ? cand[0] : 0;
            cur->sel = pick;
            if (pick != 0 && *(s32 *)((u8 *)pick + 0x14) != 0 && ((s32 *)sbuf)[0] == 0) {
                cur->cur = pick; cur->flag = 0;
            }
        }
        cur->x10 = px; cur->y14 = py;
    }
    {
        struct Cur *cur = obj->cur;
        struct Table *t = cur->tab;
        f32 z = lbl_80561608;
        (void)z;
        for (s32 i = 0; i < t->count; i++) {
            u8 *e = (u8 *)t->data + i * 0x18;
            void *o10 = *(void **)(e + 0x10);
            if (o10 != 0) {
                f32 y = fn_801452B4(*(f32 *)((u8 *)o10 + 8) + *(f32 *)(e + 4));
                u8 *o10b = *(u8 **)(e + 0x10);
                f32 x = fn_801451DC(4, *(f32 *)(o10b + 4) + *(f32 *)(e + 0));
                fn_80010B80(1, y, x, *(f32 *)(e + 8), *(f32 *)(e + 0xC));
            } else {
                f32 y2 = fn_801452B4(*(f32 *)(e + 4));
                f32 x2 = fn_801451DC(4, *(f32 *)(e + 0));
                fn_80010B80(1, y2, x2, *(f32 *)(e + 8), *(f32 *)(e + 0xC));
            }
        }
    }
    {
        struct Cur *cur = obj->cur;
        struct Table *t = obj->t2c;
        f32 z = lbl_80561610;
        (void)z;
        for (s32 i = 0; i < t->count; i++) {
            u8 *e = (u8 *)t->data + i * 0x28;
            s32 flag = 1;
            u8 *sel = (u8 *)cur->sel;
            if (sel != 0 && *(void **)(sel + 0x10) == e) flag = 0;
            s32 color = flag ? 0x70ffffff : 0xc0ffffff;
            f32 y = fn_801452B4(*(f32 *)(e + 8));
            f32 x = fn_801451DC(4, *(f32 *)(e + 4));
            fn_80010B80(color, y, x, *(f32 *)(e + 0x10), *(f32 *)(e + 0x14));
            void *cc = cur->cur;
            if (cc != 0 && *(void **)((u8 *)cc + 0x10) == e) {
                f32 y2 = fn_801452B4(*(f32 *)(e + 8) - z);
                f32 x2 = fn_801451DC(4, *(f32 *)(e + 4));
                ((void (*)(s32, s32, s32, ...))fn_8000FF88)(-1, 9, (s32)&lbl_8032D2B0, lbl_80561614, y2, x2, *(f32 *)(e + 4), *(f32 *)(e + 8), *(f32 *)(e + 0x10), *(f32 *)(e + 0x14));
            }
        }
    }
    {
        struct Cur *cur = obj->cur;
        struct Table *t = obj->t34;
        f32 z = lbl_80561610;
        (void)z;
        for (s32 i = 0; i < t->count; i++) {
            u8 *e = (u8 *)t->data + i * 0x1C;
            s32 flag = 1;
            u8 *sel = (u8 *)cur->sel;
            if (sel != 0 && *(void **)(sel + 0x10) == e) flag = 0;
            s32 color = flag ? ((*(u32 *)(e + 0x18) & 0x00FFFFFF) | 0x70000000) : 0xc0ffffff;
            f32 y = fn_801452B4(*(f32 *)(e + 8));
            f32 x = fn_801451DC(4, *(f32 *)(e + 4));
            fn_80010B80(color, y, x, *(f32 *)(e + 0x10), *(f32 *)(e + 0x14));
            void *cc = cur->cur;
            if (cc != 0 && *(void **)((u8 *)cc + 0x10) == e) {
                f32 y2 = fn_801452B4(*(f32 *)(e + 8) - z);
                f32 x2 = fn_801451DC(4, *(f32 *)(e + 4));
                ((void (*)(s32, s32, s32, ...))fn_8000FF88)(-1, 9, (s32)&lbl_8032D2B0, lbl_80561614, y2, x2, *(f32 *)(e + 4), *(f32 *)(e + 8), *(f32 *)(e + 0x10), *(f32 *)(e + 0x14));
            }
        }
    }
}

extern "C" void *fn_80148D74(void *object, s32 deleting) {
    /* Destroy this object: reset vtable, tear down subobjects, delete threads if owned, and optionally free. */
    if (object != 0) {
        *(void **)object = &lbl_8032D1D8;
        fn_80148DFC((u8 *)object + 0x14);
        fn_80148E6C((u8 *)object + 0x10);
        fn_80148EDC((u8 *)object + 0xC);
        if (*((u8 *)object + 4) != 0)
            deleteThreads__6SystemFv((u8 *)object + 8);
        if (deleting > 0)
            fn_80128668(object);
    }
    return object;
}

extern "C" void fn_80148DFC(void *);
extern "C" void fn_80148DFC(void *slot) {
    /* ReleaseItemTable: tears down the item table an object holds in the slot it
     * is given -- the member at +0x14 of the "baseline" object fn_80146C2C builds
     * (its "box_cmd" table), released by that object's destructor fn_80148D74.
     * The record array is the table's "end" field: unlike the tables released by
     * fn_80146638(), it was allocated whole by fn_8012850C() instead of being
     * carved out of a block with a 0x10-byte header, so it is freed as it stands
     * (fn_80128670 frees an array block).  The table's header is then cleared and
     * the table block itself (from fn_801284F8) is freed (fn_80128668 frees an
     * object block), leaving the slot empty. */
    NamedItemTable80145FEC *table = *(NamedItemTable80145FEC **)slot;
    if (table != NULL) {
        if (table != NULL) {
            fn_80128670((s32)table->end);
            if (table != NULL) {
                table->data = NULL;
                table->count = 0;
                table->size = 0;
            }
            fn_80128668(table);
        }
        *(void **)slot = NULL;
    }
}

extern "C" void fn_80148E6C(void *);
extern "C" void fn_80148E6C(void *arg0) {
    /* Release the object stored at *arg0: free its resource handle, clear its
       header fields, free the object, and null the slot. */
    void *object = *(void **)arg0;
    if (object != NULL) {
        if (object != NULL) {
            fn_80128670(((s32 *)object)[3]);
            if (object != NULL) {
                ((s32 *)object)[0] = 0;
                ((s32 *)object)[1] = 0;
                ((s32 *)object)[2] = 0;
            }
            fn_80128668(object);
        }
        *(void **)arg0 = NULL;
    }
}

extern "C" void fn_80148EDC(void *);
/* Releases and destroys the heap-allocated object stored at *slot: frees its
 * owned buffer at field index 3, clears fields 0-2, frees the object itself,
 * then clears the slot to NULL. */
extern "C" void fn_80148EDC(void *slot) {
    void *object = *(void **)slot;
    if (object != NULL) {
        if (object != NULL) {
            fn_80128670(((s32 *)object)[3]);
            if (object != NULL) {
                ((s32 *)object)[0] = 0;
                ((s32 *)object)[1] = 0;
                ((s32 *)object)[2] = 0;
            }
            fn_80128668(object);
        }
        *(void **)slot = NULL;
    }
}

extern "C" void deleteThreads__6SystemFv(void *system) {
    /* If this system owns a thread object, destroy it (deleting storage) and
     * clear the slot. The redundant null check matches the original. */
    ThreadObject80144F40 *thread = *(ThreadObject80144F40 **)system;
    if (thread) {
        if (thread)
            thread->destroy(1);
        *(ThreadObject80144F40 **)system = 0;
    }
}

#pragma push
#pragma scheduling on
#pragma dont_inline on
/* Refresh a UI screen's contents: when it has a handler at +8, walk its three element
   lists — 0xC-byte art records resolved through the handler and forwarded to fn_80148070,
   12-byte records via fn_8014784C, and 8-byte text records via fn_801473F8 with the "%s"
   format — updating each element in turn. The second parameter is required but ignored. */
extern "C" void fn_80148FA4(void *uiScreen, void *unused) {
    struct Handler {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual s32 v3(u32);
        virtual void *v4(u32);
    };
    struct E12 { u32 a; u32 b; u32 c; };
    struct E8 { u32 a; u32 b; };
    struct L12 { E12 *data; s32 count; };
    struct L8 { E8 *data; s32 count; };
    u8 *screen = (u8 *)uiScreen;
    s32 i;
    s32 firstOffset;
    u8 *entry;
    s32 firstIndex;
    #pragma unused(unused)
    if (*(Handler **)(screen + 8) != 0) {
        firstIndex = 0;
        firstOffset = 0;
        while (firstIndex < *(s32 *)(*(u8 **)(screen + 0x14) + 4)) {
            entry = *(u8 **)(*(u8 **)(screen + 0x14)) + firstOffset;
            void *result = (*(Handler **)(screen + 8))->v4(*(u32 *)(entry + 4));
            s32 found = (*(Handler **)(screen + 8))->v3(*(u32 *)entry);
            if (found != 0 && result != 0)
                fn_80148070((void *)found, *(s32 *)(entry + 8), (s32)result);
            firstOffset += 0xC;
            firstIndex++;
        }
        for (i = 0; i < (*(L12 **)(screen + 0x10))->count; i++) {
            E12 *e = &(*(L12 **)(screen + 0x10))->data[i];
            fn_8014784C(*(Handler **)(screen + 8), e->a, e->b, e->c);
        }
        for (i = 0; i < (*(L8 **)(screen + 0xC))->count; i++) {
            E8 *e = &(*(L8 **)(screen + 0xC))->data[i];
            fn_801473F8(*(Handler **)(screen + 8), e->a, (const char *)&lbl_80559E1C, e->b);
        }
    }
}
#pragma pop

/* No-op default implementation: the last of the five unimplemented virtual
 * stubs fn_80148218 / fn_8014821C / fn_80148224 / fn_80148228 / fn_8014822C
 * that sit between this file's 2D-drawing helpers (fn_80148100 .. fn_801481C8)
 * and the adapter sub-object's virtuals (fn_80148230 .. fn_80148280, vtable
 * lbl_8032D214).  Nothing calls it by name, so it runs only when reached
 * through the pointer table its entry sits in. */
extern "C" void fn_8014822C(void) {

}

extern "C" s32 fn_80148230(void) {
    /* Returns -1 as the invalid/no-value sentinel used by the menu-item code
       (pairing with the default-item colour helper fn_80148238). */
    return -1;
}

/* Opaque mid-grey ARGB, the colour menu code uses for disabled entries. */
#define DISABLED_ITEM_COLOR 0xFF808080
/* Return the disabled-menu-item colour: opaque mid-grey (ARGB 0xFF808080). */
extern "C" s32 fn_80148238(void) {
    return DISABLED_ITEM_COLOR;
}

