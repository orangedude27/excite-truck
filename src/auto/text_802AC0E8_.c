// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F93C;
extern int lbl_8055F940;
extern int lbl_8055F944;
extern int lbl_8055F948;
extern signed char lbl_8055F94C;
extern const char lbl_8055CC88;
extern const char lbl_8055CCB8;
extern float lbl_80564AB0;
extern double atof(const char *);
extern int fn_802E2C20(void);
extern int sscanf(const char *, const char *, ...);

/* One symbol-table record used by the animation parser: a type tag, a name and the resolved id. */
typedef struct AnimSymbolEntry {
    int type;
    const char *name;
    int value;
} AnimSymbolEntry;

#pragma scheduling invalid_target
/* RealName: Anim_FindSymbolEntry. Walk the animation symbol table (a list of
   12-byte { type, name, value } records ended by a zero type) and return the
   entry whose type tag and name both match, or 0 if none does. */
void *fn_802AC0E8(void *entry, const char *name, int type) {
    if (entry == 0)
        return 0;
    while (((AnimSymbolEntry *)entry)->type != 0) {
        if (((AnimSymbolEntry *)entry)->type == type && strcmp(((AnimSymbolEntry *)entry)->name, name) == 0)
            return entry;
        entry = (char *)entry + 0xC;
    }
    return 0;
}
/* RealName: ParseHexColorCode (parses a "#%x" hex string into an integer, or -1 on failure). */
int fn_802AC174(const char *hexString) {
    int value;
    value = 0;
    if (sscanf(hexString, &lbl_8055CC88, &value) == 1)
        return value;
    return -1;
}
#pragma scheduling on
extern char *strstr(const char *, const char *);
extern int lbl_802FAA50[];
struct AcTable { int w[24]; };
#pragma use_lmw_stmw off
int fn_802AC1BC(const char *justify, int unused) {
    /* Parse a text "justify" attribute into an alignment bitmask.
       lbl_802FAA50 is a table of 12-byte { substring, flagBit, horizontal } records:
       left=1, right=2, center=4 (horizontal); top=8, middle=0x10, bottom=0x20,
       baseline=0x40 (vertical). Missing an axis defaults to center (4) / middle (0x10). */
    struct AcTable entries;
    int alignFlags = 0;
    int sawHorizontal = 0;
    int sawVertical = 0;
    entries = *(struct AcTable *)lbl_802FAA50;
    {
        int *entry = (int *)&entries;
        while (entry[0] != 0) {
            if (strstr(justify, (const char *)entry[0]) != 0) {
                int masked = alignFlags & 7;
                unsigned char horizontal = ((unsigned char *)entry)[8];
                if (horizontal != 0) masked = alignFlags & ~7;
                alignFlags = masked | entry[1];
                sawHorizontal = (sawHorizontal != 0 || horizontal != 0);
                sawVertical = (sawVertical != 0 || horizontal == 0);
            }
            entry = (int *)((char *)entry + 12);
        }
    }
    if (sawHorizontal == 0) alignFlags |= 4;
    if (sawVertical == 0) alignFlags |= 0x10;
    return alignFlags;
}
#pragma use_lmw_stmw on
#pragma cplusplus on
/* Read the float attribute `key` of the attribute set `attrs`: when the set exists and
 * holds that key, store its value through outValue and return 1; otherwise leave
 * *outValue alone and return 0.  fn_802AC4A8 uses this to let an animation override its
 * length with its "__anim_end__" attribute. */
extern "C" int fn_802AC2B4(void **attrs, int key, float *outValue) {
    /* attribute set: vtable+0xC = hasEntry(key), vtable+0x24 = getFloat(key) */
    struct AttributeSet {
        virtual void v0();
        virtual int hasEntry(const char *key);
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual float getFloat(const char *key);
    };
    if (attrs != 0 && ((AttributeSet *)attrs)->hasEntry((const char *)key) != 0) {
        if (outValue != 0) {
            *outValue = ((AttributeSet *)attrs)->getFloat((const char *)key);
        }
        return 1;
    }
    return 0;
}

#pragma push
#pragma processor 750
#pragma cplusplus on
/* Reads a segment's "t" (time) attribute: resolves its string through root's float attributes (or atof), and a leading '+' makes the result relative to baseTime instead of zero. */ extern "C" float fn_802AC344(void *segment, void *root, float *baseTime) {
    struct InterfaceA {
        virtual void v0();
        virtual int hasKey(const char *);
        virtual void v2();
        virtual char *getKey(const char *);
    };
    struct InterfaceB {
        virtual void v0();
        virtual int hasEntry(const char *);
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual float getFloat(const char *);
    };

    float defaultTime;
    float result;
    char *timeStr;

    if (baseTime != 0) {
        defaultTime = *baseTime;
    } else {
        defaultTime = lbl_80564AB0;
    }

    if (((InterfaceA *)segment)->hasKey(&lbl_8055CCB8) != 0) {
        timeStr = ((InterfaceA *)segment)->getKey(&lbl_8055CCB8);
        result = lbl_80564AB0;
        if (*timeStr == '+') {
            result = defaultTime;
            timeStr++;
        }
        if (root != 0 && ((InterfaceB *)root)->hasEntry(timeStr) != 0) {
            result += ((InterfaceB *)root)->getFloat(timeStr);
        } else {
            result += (float)atof(timeStr);
        }
        return result;
    }
    return defaultTime;
}
#pragma pop
#pragma cplusplus off

extern float fn_802AC344(void *, void *, float *);
/* Read a segment's "t" (time) attribute as an offset from the previous segment's start.
   Forwards to fn_802AC344 (the time-attribute reader), which resolves named times via
   the root attribute set and applies a leading '+' as a relative offset to baseTime. */
float fn_802AC454(void *segment, void *root, float *baseTime) {
    return fn_802AC344(segment, root, baseTime);
}

/* Initialize the animation state globals (count/index/timestamps and playback flag). */
void fn_802AC458(void) {
    lbl_8055F93C = 0;
    lbl_8055F944 = fn_802E2C20();
    lbl_8055F948 = 0;
    lbl_8055F940 = 0;
    lbl_8055F94C = 1;
}

void fn_802AC49C(void) {
    /* Reset the loaded-animation count to zero, emptying the animation table. */
#define sAnimCount lbl_8055F93C
    sAnimCount = 0;
#undef sAnimCount
}

__declspec(section ".sdata") extern char lbl_8055CCC0[], lbl_8055CCC8[], lbl_8055CCD0[], lbl_8055CCD8[], lbl_8055CCE0[], lbl_8055CCE8[], lbl_8055CCF0[];
__declspec(section ".sdata") extern char lbl_8055CCF8[], lbl_8055CCFC[], lbl_8055CD04[], lbl_8055CD0C[], lbl_8055CD14[], lbl_8055CD20[], lbl_8055CD28[];
__declspec(section ".sdata") extern char lbl_8055CD30[], lbl_8055CD38[], lbl_8055CD40[], lbl_8055CD48[], lbl_8055CD50[], lbl_8055CD58[], lbl_8055CD60[];
extern float lbl_80564AB4, lbl_80564AB8, lbl_80564ABC, lbl_80564AC0, lbl_80564AC4, lbl_80564AC8;
#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma use_lmw_stmw off
int fn_802AC4A8(const char *name, int table)
{
    typedef struct { float x, y, z; } LVec3;
    typedef struct { float x, y; } __attribute__((aligned(8))) LVec2;
    typedef union { float f; int i; char *s; } LWord;
    typedef struct { int type; int f4; int f8; void *ptr; LWord w[6]; } LRec;
    typedef struct { float start; LVec3 scale; float alpha; LVec3 pos; float rot[4]; int f30; int f34; } LSeg;
    typedef struct { int id; int count; LSeg *segs; } LGroup;
    typedef struct { char name[0x18]; int refs; int numRecs; LRec *recs; int numGroups; LGroup *groups; float length; } LAnim;
    typedef int (*HasFn)(void *, const char *);
    typedef void *(*AtFn)(void *, int);
    typedef char *(*NameFn)(void *);
    typedef char *(*StrFn)(void *, const char *);
    typedef char *(*StrDefFn)(void *, const char *, const char *);
    typedef int (*IntFn)(void *, const char *);
    typedef int (*IntDefFn)(void *, const char *, int);
    typedef float (*FltFn)(void *, const char *);
    typedef float (*FltDefFn)(void *, const char *, float);
    typedef LVec3 (*Vec3Fn)(void *, const char *);
    typedef LVec3 (*Vec3DefFn)(void *, const char *, LVec3);
    typedef LVec2 (*Vec2Fn)(void *, const char *);
    typedef LVec2 (*Vec2DefFn)(void *, const char *, LVec2);
    typedef int (*LookupFn)(void *, const char *, const char *);
    extern void *fn_801284F8(int, void *, void *);
    extern void *fn_8012850C(int, void *);
    extern void *fn_80131808(const char *);
    extern void fn_80131818(void *);
    extern void *memset(void *, int, int);
    extern int strcmp(const char *, const char *);
    extern int sscanf(const char *, const char *, ...);
    extern int fn_802AC174(const char *);
    extern int fn_802AC1BC(const char *, int);
    extern int fn_802AC2B4(void **, int, float *);
    extern void *fn_802AC0E8(void *, const char *, int);
    extern void *fn_802C6FC0(int, int, int);
    extern void *fn_80232578(const char *);
    extern void fn_802E30C8(const char *, ...);
    extern void Abend_Panic(const char *, ...);
    extern float fn_802AC344(void *, void *, float *);
    extern float fn_802AC454(void *, void *, float *);
    extern void *fn_8002F37C(void *, void *, void *, int, int);
    extern double fn_8002F234(double);
    extern float PSVECDotProduct(const LVec3 *, const LVec3 *);
    extern double sin(double);
    extern double cos(double);
    extern void fn_802AD308(void);
    extern void *lbl_804BD7C0[];
    extern void *lbl_8055F93C;
    extern char lbl_80349E38[];
    extern float lbl_80558DC4[];
    extern int lbl_8055CD1C;
    char *str = lbl_80349E38;
    LAnim *anim;
    void *set;
    void *root;
    void *e;
    void *records[64];
    void *groupsSrc[64];
    void *segSrc[128];
    int numRecs, numGroups, i, k, n;
    char *dst;
    const char *src;
    char c;

    anim = (LAnim *)((void *(*)(int, void *))fn_801284F8)(0x30, lbl_8055CCC0);
    memset(anim, 0, 0x30);
    anim->refs = 1;
    src = name;
    dst = anim->name;
    n = 0x18;
    goto copy;
check:
    if (--n > 0)
        goto copy;
    dst[-1] = 0;
    goto copied;
copy:
    c = *src++;
    *dst++ = c;
    if (c != 0)
        goto check;
copied:
    set = fn_80131808(name);
    if (((HasFn)(*(void ***)set)[4])(set, str + 0xC))
        root = ((StrFn)(*(void ***)set)[2])(set, str + 0xC);
    else
        root = 0;

    numRecs = 0;
    numGroups = 0;
    for (i = 0; (e = ((AtFn)(*(void ***)set)[3])(set, i)) != 0; i++) {
        if (strcmp(((NameFn)(*(void ***)e)[2])(e), lbl_8055CCC8) == 0) {
            records[numRecs++] = e;
        } else if (strcmp(((NameFn)(*(void ***)e)[2])(e), lbl_8055CCD0) == 0) {
            groupsSrc[numGroups++] = e;
        }
    }
    anim->numRecs = numRecs;
    anim->recs = fn_8012850C(numRecs * 0x28, str + 0x18);
    anim->numGroups = numGroups;
    anim->groups = fn_8012850C(numGroups * 0xC, str + 0x24);

    {
        float scale = lbl_80564AB8;
        float zero = lbl_80564AB0;
    for (k = 0; k < numRecs; k++) {
        LRec *rec;
        char *type;
        void *ent;
        e = records[k];
        rec = &anim->recs[k];
        type = ((StrFn)(*(void ***)e)[5])(e, lbl_8055CCD8);
        memset(rec, 0, 0x28);
        if (strcmp(type, lbl_8055CCE0) == 0) {
            LVec3 def3, v3;
            volatile LVec2 def2;
            volatile LVec2 p;
            char *sub;
            int model;
            rec->type = 2;
            model = (int)((StrFn)(*(void ***)e)[5])(e, lbl_8055CCE0);
            ent = fn_802AC0E8((void *)table, (char *)model, 4);
            if (ent != 0)
                model = ((int *)ent)[2];
            rec->ptr = fn_802C6FC0(model, 0, 0);
            rec->w[0].f = ((FltDefFn)(*(void ***)e)[10])(e, lbl_8055CCE8, lbl_80564AB4);
            def3.x = zero;
            def3.y = zero;
            def3.z = zero;
            v3 = ((Vec3DefFn)(*(void ***)e)[14])(e, lbl_8055CCF0, def3);
            rec->w[1].f = v3.x;
            rec->w[2].f = v3.y;
            rec->w[3].f = v3.z;
            def2.x = zero;
            def2.y = zero;
            p = ((Vec2DefFn)(*(void ***)e)[16])(e, lbl_8055CCF8, def2);
            rec->w[1].f += p.x;
            rec->w[2].f -= p.y;
            rec->w[4].i = ((IntDefFn)(*(void ***)e)[8])(e, lbl_8055CCFC, -1);
            rec->w[5].i = 0;
            sub = ((StrDefFn)(*(void ***)e)[6])(e, str + 0x30, 0);
            if (sub != 0) {
                ent = fn_802AC0E8((void *)table, sub, 3);
                if (ent != 0)
                    rec->f4 = ((int *)ent)[2];
                ent = fn_802AC0E8((void *)table, sub, 5);
                if (ent != 0)
                    rec->f8 = ((int *)ent)[2];
                ent = fn_802AC0E8((void *)table, sub, 2);
                if (ent != 0)
                    rec->w[5].i = ((int *)ent)[2];
                else
                    fn_802E30C8(str + 0x40, sub);
            }
        } else if (strcmp(type, lbl_8055CD04) == 0) {
            rec->type = 1;
            if (strcmp(str + 0x60, ((StrFn)(*(void ***)e)[5])(e, lbl_8055CD0C)) != 0) {
                rec->ptr = fn_80232578(((StrFn)(*(void ***)e)[5])(e, lbl_8055CD0C));
                rec->w[2].f = ((FltDefFn)(*(void ***)e)[10])(e, lbl_8055CCE8, lbl_80564AB4);
            } else {
                rec->ptr = fn_80232578(str + 0x6C);
                rec->w[2].f = scale * ((FltDefFn)(*(void ***)e)[10])(e, lbl_8055CCE8, lbl_80564AB4);
            }
            rec->w[1].i = fn_802AC174(((StrDefFn)(*(void ***)e)[6])(e, lbl_8055CD14, (const char *)&lbl_8055CD1C));
            rec->w[0].i = fn_802AC1BC(((StrDefFn)(*(void ***)e)[6])(e, lbl_8055CD20, str + 0x78), 0);
            rec->w[3].s = ((StrFn)(*(void ***)e)[5])(e, lbl_8055CD04);
            if (*rec->w[3].s == '#') {
                ent = fn_802AC0E8((void *)table, rec->w[3].s + 1, 3);
                if (ent != 0)
                    rec->f4 = ((int *)ent)[2];
                ent = fn_802AC0E8((void *)table, rec->w[3].s + 1, 5);
                if (ent != 0)
                    rec->f8 = ((int *)ent)[2];
                ent = fn_802AC0E8((void *)table, rec->w[3].s + 1, 1);
                if (ent != 0)
                    rec->w[3].i = ((int *)ent)[2];
                else
                    fn_802E30C8(str + 0x88, rec->w[3].s + 1);
            }
        } else {
            Abend_Panic(str + 0xA4, type);
        }
    }
    }

    {
        float degToRad = lbl_80564ABC;
        float zero = lbl_80564AB0;
        float half = lbl_80564AC0;
        float one = lbl_80564AB4;
        float cx = lbl_80564AC4;
        float cy = lbl_80564AC8;
        const char *layerKey = lbl_8055CD30;
        const char *layerTable = str + 0xDC;
    for (k = 0; k < numGroups; k++) {
        LGroup *grp;
        volatile LVec2 def2;
        volatile LVec2 origin;
        float base;
        int numSegs;
        int j;
        e = groupsSrc[k];
        grp = &anim->groups[k];
        grp->id = ((IntFn)(*(void ***)e)[7])(e, str + 0xC4);
        def2.x = zero;
        def2.y = zero;
        origin = ((Vec2DefFn)(*(void ***)e)[16])(e, lbl_8055CCF8, def2);
        base = fn_802AC344(e, root, 0);
        numSegs = 0;
        {
            void *s;
            for (i = 0; (s = ((AtFn)(*(void ***)e)[24])(e, i)) != 0; i++) {
                if (strcmp(((NameFn)(*(void ***)s)[2])(s), lbl_8055CD28) == 0)
                    segSrc[numSegs++] = s;
            }
        }
        grp->count = numSegs;
        grp->segs = fn_8002F37C(fn_8012850C(numSegs * 0x38 + 0x10, str + 0xD0), (void *)fn_802AD308, 0, 0x38, numSegs);
        {
            float ox = origin.x;
            float oy = origin.y;
            for (j = 0; j < numSegs; j++) {
            LSeg *seg = &grp->segs[j];
            LSeg *prev = j > 0 ? &grp->segs[j - 1] : 0;
            void *s = segSrc[j];
            seg->start = base + fn_802AC454(s, root, (float *)prev);
            if (((HasFn)(*(void ***)s)[3])(s, lbl_8055CD38)) {
                LVec3 axis;
                float d;
                float ang = degToRad * ((FltDefFn)(*(void ***)s)[10])(s, lbl_8055CD38, lbl_80564AB0);
                axis.x = zero;
                axis.y = zero;
                axis.z = -ang;
                d = PSVECDotProduct(&axis, &axis);
                if (!((float)__fabs(d) <= lbl_80558DC4[0])) {
                    float len = fn_8002F234(d);
                    float h = half * len;
                    float sn = sin(h);
                    float cs = cos(h);
                    float sc = sn / len;
                    seg->rot[0] = axis.x * sc;
                    seg->rot[1] = axis.y * sc;
                    seg->rot[2] = axis.z * sc;
                    seg->rot[3] = cs;
                } else {
                    seg->rot[0] = zero;
                    seg->rot[1] = zero;
                    seg->rot[2] = zero;
                    seg->rot[3] = one;
                }
            } else {
                char *q = ((StrDefFn)(*(void ***)s)[6])(s, lbl_8055CD40, lbl_8055CD48);
                if (sscanf(q, str + 0xF8, &seg->rot[0], &seg->rot[1], &seg->rot[2], &seg->rot[3]) != 4)
                    Abend_Panic(str + 0x104, q, name);
            }
            if (((HasFn)(*(void ***)s)[3])(s, lbl_8055CCF8)) {
                volatile LVec2 v;
                v = ((Vec2Fn)(*(void ***)s)[15])(s, lbl_8055CCF8);
                v.x += ox;
                v.y += oy;
                seg->pos.x = v.x - cx;
                seg->pos.y = cy - v.y;
                seg->pos.z = zero;
            } else if (((HasFn)(*(void ***)s)[3])(s, lbl_8055CCF0)) {
                LVec3 p;
                p = ((Vec3Fn)(*(void ***)s)[13])(s, lbl_8055CCF0);
                seg->pos.x = p.x;
                seg->pos.y = p.y;
                seg->pos.z = p.z;
                seg->pos.x += ox - cx;
                seg->pos.y += cy - oy;
            } else {
                LVec3 zv;
                LVec3 *from;
                if (prev != 0) {
                    from = &prev->pos;
                } else {
                    zv.x = zero;
                    zv.y = zero;
                    zv.z = zero;
                    from = &zv;
                }
                seg->pos.x = from->x;
                seg->pos.y = from->y;
                seg->pos.z = from->z;
            }
            if (((HasFn)(*(void ***)s)[3])(s, lbl_8055CD50)) {
                LVec3 p;
                p = ((Vec3Fn)(*(void ***)s)[13])(s, lbl_8055CD50);
                seg->scale.x = p.x;
                seg->scale.y = p.y;
                seg->scale.z = p.z;
            } else if (((HasFn)(*(void ***)s)[3])(s, lbl_8055CCE8)) {
                float f = ((FltFn)(*(void ***)s)[9])(s, lbl_8055CCE8);
                seg->scale.x = f;
                seg->scale.y = f;
                seg->scale.z = f;
            } else if (prev != 0) {
                seg->scale.x = prev->scale.x;
                seg->scale.y = prev->scale.y;
                seg->scale.z = prev->scale.z;
            } else {
                seg->scale.x = one;
                seg->scale.y = one;
                seg->scale.z = one;
            }
            seg->alpha = ((FltDefFn)(*(void ***)s)[10])(s, lbl_8055CD58, prev != 0 ? prev->alpha : lbl_80564AB4);
            {
                int dflt = prev != 0 ? prev->f30 : 0;
                seg->f30 = ((HasFn)(*(void ***)s)[3])(s, layerKey) ? ((LookupFn)(*(void ***)s)[21])(s, layerKey, layerTable) : dflt;
            }
            seg->f34 = ((IntDefFn)(*(void ***)s)[8])(s, lbl_8055CD60, prev != 0 ? prev->f34 : 0);
            }
        }
    }
    }

    if (((HasFn)(*(void ***)set)[4])(set, str + 0x128)) {
        void *g = ((StrFn)(*(void ***)set)[2])(set, str + 0x128);
        LVec3 off;
        float sc, sa;
        if (((HasFn)(*(void ***)g)[3])(g, lbl_8055CCF8)) {
            volatile LVec2 v;
            v = ((Vec2Fn)(*(void ***)g)[15])(g, lbl_8055CCF8);
            off.z = lbl_80564AB0;
            off.x = v.x;
            off.y = -v.y;
        } else if (((HasFn)(*(void ***)g)[3])(g, lbl_8055CCF0)) {
            LVec3 p;
            p = ((Vec3Fn)(*(void ***)g)[13])(g, lbl_8055CCF0);
            off.x = p.x;
            off.y = p.y;
            off.z = p.z;
        } else {
            off.x = lbl_80564AB0;
            off.y = lbl_80564AB0;
            off.z = lbl_80564AB0;
        }
        sc = ((FltDefFn)(*(void ***)g)[10])(g, lbl_8055CCE8, lbl_80564AB4);
        sa = ((FltDefFn)(*(void ***)g)[10])(g, lbl_8055CD58, lbl_80564AB4);
        for (k = 0; k < numGroups; k++) {
            LGroup *grp = &anim->groups[k];
            int j;
            for (j = 0; j < grp->count; j++) {
                LSeg *seg = &grp->segs[j];
                seg->pos.x += off.x;
                seg->pos.y += off.y;
                seg->pos.z += off.z;
                seg->scale.x *= sc;
                seg->scale.y *= sc;
                seg->scale.z *= sc;
                seg->alpha *= sa;
            }
        }
    }
    anim->length = lbl_80564AB0;
    for (k = 0; k < anim->numGroups; k++) {
        LGroup *grp = &anim->groups[k];
        float last = grp->segs[grp->count - 1].start;
        float len = anim->length;
        anim->length = len > last ? len : last;
    }
    fn_802AC2B4(root, (int)(str + 0x13C), &anim->length);
    fn_80131818(set);
    lbl_804BD7C0[(int)lbl_8055F93C] = anim;
    lbl_8055F93C = (char *)lbl_8055F93C + 1;
    return (int)anim;
}
#pragma pop
extern float lbl_80564ACC;
extern float lbl_8055E3C8;
extern int lbl_8055CD70;
extern char lbl_80349FA4[];
extern void fn_802AD4C4(void *, int, float);
extern int strcmp(const char *, const char *);
extern float lbl_8055E3C8;
extern int lbl_8055CD70;
extern char lbl_80349FB0[];
extern void fn_802E30C8(const char *, ...);
extern void *fn_801284F8(int, void *, void *);
extern void *fn_8012850C(int, void *);
extern int fn_802AC4A8(const char *, int);
extern void fn_80128668(void *);
extern void fn_80128670(void *);
extern void fn_802328D4(void *);
extern void fn_802C6CF8(void *);
/* No-op element constructor: the array builder fn_8002F37C calls it once per
 * 0x38-byte LSeg record while building an animation group's segment array. */
void fn_802AD308(void) {}

void fn_802AD30C(void *arg0) {
    struct Record {
        int type;
        int pad4;
        int pad8;
        void *ptr;
        int pad10[6];
    };
    struct Group {
        int pad0;
        int pad4;
        void *ptr;
    };
    int refCount;
    int i;

    /* Release a resource object: decrement its refcount, and on last reference
       destroy child records/groups and free owned allocations. */
    refCount = *(int *)((char *)arg0 + 0x18) - 1;
    *(int *)((char *)arg0 + 0x18) = refCount;
    if (refCount <= 0) {
        lbl_8055F93C = (char *)lbl_8055F93C - 1;
        for (i = 0; i < *(int *)((char *)arg0 + 0x1C); i++) {
            if ((*(struct Record **)((char *)arg0 + 0x20))[i].type == 1) {
                fn_802328D4((*(struct Record **)((char *)arg0 + 0x20))[i].ptr);
            } else if ((*(struct Record **)((char *)arg0 + 0x20))[i].type == 2) {
                fn_802C6CF8((*(struct Record **)((char *)arg0 + 0x20))[i].ptr);
            }
        }

        for (i = 0; i < *(int *)((char *)arg0 + 0x24); i++) {
            void *ptr = (*(struct Group **)((char *)arg0 + 0x28))[i].ptr;
            if (ptr != 0) {
                fn_80128670((char *)ptr - 0x10);
            }
        }

        if (*(void **)((char *)arg0 + 0x20) != 0) {
            fn_80128670(*(void **)((char *)arg0 + 0x20));
        }
        if (*(void **)((char *)arg0 + 0x28) != 0) {
            fn_80128670(*(void **)((char *)arg0 + 0x28));
        }
        fn_80128668(arg0);
    }
}

#pragma scheduling invalid_target
void fn_802AD414(void *arg0, float farg0) {
    struct Entry {
        volatile float lower;
        char pad[0x30];
        int *out;
    };
    float base = lbl_80564ACC;
    int offset = 0;
    int outer = 0;
    while (outer < *(int *)((char *)arg0 + 0x24)) {
        int byteOffset = 0;
        int inner = 0;
        char *group = *(char **)((char *)arg0 + 0x28) + offset;
        int count = *(int *)(group + 4);
        for (; inner < count - 1; inner++) {
            float a = *(volatile float *)((char *)*(struct Entry **)(group + 8) + byteOffset);
            float b = (*(struct Entry **)(group + 8))[inner + 1].lower;
            char *entry = (char *)*(struct Entry **)(group + 8) + byteOffset;
            if (farg0 >= a && farg0 <= base + b) {
                int idx = *(int *)group;
                char *records = *(char **)((char *)arg0 + 0x20);
                char *record = records + idx * 0x28;
                int *p = *(int **)(record + 4);
                if (p) *p = *(int *)((char *)entry + 0x34);
                break;
            }
            byteOffset += 0x38;
        }
        offset += 0xC;
        outer++;
    }
}

extern float lbl_80564AB4, lbl_80564ACC, lbl_80564AD0, lbl_80564AD4, lbl_80564AD8, lbl_80564AC0;
extern char lbl_8055CD68;
extern int fn_802C2C00(int);
extern void fn_8012F57C(float *, void *, void *, float);
extern void fn_802C9900(void);
extern void fn_802C9904(void);
extern void fn_802C744C(int, float *);
extern void fn_802C70AC(int, float *, int, int);
extern int fn_8023389C(int, unsigned int, int, float *, char *, int, ...);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802AD4C4(void *arg0, int arg1, float t) {
    char *obj = (char *)arg0;
    float *off = (float *)arg1;
    float m[12];
    float sp30[4];
    float sp20[3];
    float sp14[3];
    float sp8[3];
    int h;
    int i;
    int boff;
    float one, eps, lo, c1, c2, zero, half;
    h = fn_802C2C00(0);
    one = lbl_80564AB4;
    eps = lbl_80564ACC;
    lo = lbl_80564AD0;
    c1 = lbl_80564AD4;
    c2 = lbl_80564AD8;
    zero = lbl_80564AB0;
    boff = 0;
    for (i = 0; i < *(int *)(obj + 0x24); i++, boff += 0xC) {
        char *seg = *(char **)(obj + 0x28) + boff;
        int n = *(int *)(seg + 4) - 1;
        int j;
        int jo = 0;
        for (j = 0; j < n; j++, jo += 0x38) {
            char *a = *(char **)(seg + 8) + jo;
            char *b = *(char **)(seg + 8) + (j + 1) * 0x38;
            float f23, u, f4, f6, a0 = *(float *)a;
            if (t >= a0 && t <= *(float *)b + eps) {
                char *c;
                float *p2;
                u = (t - a0) / (*(float *)b - a0);
                if (one < u) u = one;
                u = (u > zero) ? u : zero;
                f23 = zero + u * one;
                switch (*(int *)(a + 0x30)) {
                case 1:
                    if (f23 < lo) {
                        f23 = lo;
                    } else if (f23 > one) {
                        f23 = one;
                    } else if (f23 > zero) {
                        f23 = f23 * (c1 * f23 * f23) + c2 * f23 * f23;
                    } else {
                        f23 = f23 * (c1 * f23 * f23) - c2 * f23 * f23;
                    }
                    break;
                case 2:
                    f23 = f23 * f23;
                    break;
                case 3:
                    f23 = one - (one - f23) * (one - f23);
                    break;
                }
                fn_8012F57C(sp30, a + 0x20, b + 0x20, f23);
                sp20[2] = *(float *)(a + 0x1C) + f23 * (*(float *)(b + 0x1C) - *(float *)(a + 0x1C));
                sp20[1] = *(float *)(a + 0x18) + f23 * (*(float *)(b + 0x18) - *(float *)(a + 0x18));
                sp20[0] = *(float *)(a + 0x14) + f23 * (*(float *)(b + 0x14) - *(float *)(a + 0x14));
                if (off != 0) f4 = off[0]; else f4 = lbl_80564AB4;
                if (off != 0) {
                    sp20[0] += off[1];
                    sp20[1] += off[2];
                    sp20[2] += off[3];
                }
                f6 = one;
                {
                    float x = sp30[0], y = sp30[1], z = sp30[2], w = sp30[3];
                    float y2 = y + y, z2 = z + z, x2 = x + x;
                    float yy = y * y2, zz = z * z2, xx = x * x2;
                    float wx = w * x2, wy = w * y2, wz = w * z2;
                    float yz = y * z2, xz = x * z2, xy = x * y2;
                    m[0] = one - (yy + zz);
                    m[4] = one - (xx + zz);
                    m[7] = yz - wx;
                    m[8] = one - (xx + yy);
                    m[5] = yz + wx;
                    m[2] = xz - wy;
                    m[6] = xz + wy;
                    m[3] = xy - wz;
                    m[1] = xy + wz;
                    m[9] = sp20[0] * f4;
                    m[10] = sp20[1] * f4;
                    m[11] = sp20[2] * f4;
                }
                sp14[2] = *(float *)(a + 0xC) + f23 * (*(float *)(b + 0xC) - *(float *)(a + 0xC));
                sp14[1] = *(float *)(a + 8) + f23 * (*(float *)(b + 8) - *(float *)(a + 8));
                sp14[0] = *(float *)(a + 4) + f23 * (*(float *)(b + 4) - *(float *)(a + 4));
                c = *(char **)(obj + 0x20) + *(int *)seg * 0x28;
                p2 = *(float **)(c + 8);
                if (p2 != 0) {
                    m[9] += p2[1] * f4;
                    m[10] += p2[2] * f4;
                    m[11] += p2[3] * f4;
                    f6 = one * (*(float **)(c + 8))[0];
                }
                if (*(int *)c == 2) {
                    if (sp8 == (float *)(c + 0x14)) {
                        float c14 = *(float *)(c + 0x14), c18 = *(float *)(c + 0x18), c1c = *(float *)(c + 0x1C);
                        sp8[0] = c1c * m[6] + (c14 * m[0] + c18 * m[3]);
                        sp8[1] = c1c * m[7] + (c14 * m[1] + c18 * m[4]);
                        sp8[2] = c1c * m[8] + (c14 * m[2] + c18 * m[5]);
                    } else {
                        sp8[0] = *(float *)(c + 0x1C) * m[6] + (*(float *)(c + 0x14) * m[0] + *(float *)(c + 0x18) * m[3]);
                        sp8[1] = *(float *)(c + 0x1C) * m[7] + (*(float *)(c + 0x14) * m[1] + *(float *)(c + 0x18) * m[4]);
                        sp8[2] = *(float *)(c + 0x1C) * m[8] + (*(float *)(c + 0x14) * m[2] + *(float *)(c + 0x18) * m[5]);
                    }
                    m[9] += sp8[0];
                    m[10] += sp8[1];
                    m[11] += sp8[2];
                    {
                        float k = f6 * (f4 * (sp14[0] * *(float *)(c + 0x10)));
                        m[0] *= k; m[1] *= k; m[2] *= k;
                        k = f6 * (f4 * (sp14[1] * *(float *)(c + 0x10)));
                        m[3] *= k; m[4] *= k; m[5] *= k;
                        k = f6 * (f4 * (sp14[2] * *(float *)(c + 0x10)));
                        m[6] *= k; m[7] *= k; m[8] *= k;
                    }
                    fn_802C9900();
                    {
                        int r;
                        if (*(int **)(c + 0x24) != 0) r = **(int **)(c + 0x24); else r = *(int *)(c + 0x20);
                        if (r < 0) {
                            fn_802C744C(*(int *)(c + 0xC), m);
                        } else {
                            fn_802C70AC(*(int *)(c + 0xC), m, -1, 1 << r);
                        }
                    }
                    fn_802C9904();
                } else if (*(int *)c == 1) {
                    unsigned int col = *(unsigned int *)(c + 0x14);
                    float lerp = *(float *)(a + 0x10) + f23 * (*(float *)(b + 0x10) - *(float *)(a + 0x10));
                    float v = lerp * (float)(col >> 24);
                    int iv;
                    half = lbl_80564AC0;
                    if (v < zero) v = v - half; else v = half + v;
                    iv = (int)v;
                    if (iv < 0) iv = 0;
                    if (iv > 0xFF) iv = 0xFF;
                    fn_8023389C(*(int *)(c + 0xC), (col & 0x00FFFFFF) | ((unsigned int)iv << 24), *(int *)(c + 0x10), m, &lbl_8055CD68, *(int *)(c + 0x1C),
                        zero, zero, zero, f6 * (f4 * (sp14[0] * *(float *)(c + 0x18))), one);
                }
                break;
            }
        }
    }
    fn_802C2C00(h);
}
#pragma pop

#pragma push
#pragma processor 750
extern void fn_8023895C(void);
extern void fn_80238B44(int, int, int, int, int);
extern void fn_80238A80(int, int, int, const char *, ...);
extern void fn_802389E4(void);
extern char lbl_80349F84[];
extern char lbl_80349F98[];
extern int lbl_8055CD1C;
extern void *lbl_804BD7C0[];
void fn_802ADBB4(void) {
    /* Renders a debug overlay for the current animation entry: updates the time offset while
       active, draws index/name and elapsed time, and evaluates the selected animation. */
    int currentTime = fn_802E2C20();
    float elapsedSeconds;
    int isValidIndex;

    if ((unsigned char)lbl_8055F94C != 0) {
        lbl_8055F944 = currentTime - lbl_8055F948;
    }
    elapsedSeconds = (float)(currentTime - lbl_8055F944) * 0.001f;
    fn_8023895C();
    fn_80238B44(0, 0, 0x12C, 0x32, 0xC0000000);
    isValidIndex = (lbl_8055F940 >= 0 && lbl_8055F940 < (int)lbl_8055F93C);
    fn_80238A80(10, 10, 0xC0FFFFFF, lbl_80349F84, lbl_8055F940, isValidIndex ? lbl_804BD7C0[lbl_8055F940] : &lbl_8055CD1C);
    fn_80238A80(10, 30, 0xC0FFFFFF, lbl_80349F98, elapsedSeconds);
    fn_802389E4();
    if (lbl_8055F940 >= 0 && lbl_8055F940 < (int)lbl_8055F93C) {
        fn_802AD4C4(lbl_804BD7C0[lbl_8055F940], 0, elapsedSeconds);
    }
}
#pragma pop

#pragma scheduling on
int fn_802ADCF8(int key) {
    /* Debug menu key handler: D-pad/select/enter-like controls update animation index or timer state. */
    int newIndex;
    int maxIndexMinus1;
    int nextIndex;
    int toggle;

    switch (key) {
    case 0x5B: /* move up */
        nextIndex = lbl_8055F940 - 1;
        lbl_8055F940 = nextIndex < -1 ? -1 : nextIndex;
        return 1;
    case 0x5D: /* move down */
        maxIndexMinus1 = (int)lbl_8055F93C - 1;
        newIndex = lbl_8055F940 + 1;
        if (maxIndexMinus1 < newIndex) {
            newIndex = maxIndexMinus1;
        }
        lbl_8055F940 = newIndex;
        return 1;
    case 0x22: /* reset timer */
        lbl_8055F944 = fn_802E2C20();
        lbl_8055F948 = 0;
        return 1;
    case 0x27: /* toggle timer */
        toggle = ((unsigned char)lbl_8055F94C == 0);
        lbl_8055F94C = toggle;
        if (toggle) {
            lbl_8055F948 = fn_802E2C20() - lbl_8055F944;
        }
        return 1;
    default:
        return 0;
    }
}

void *fn_802ADDD8(void *out, int count) {
    int *obj;
    int data;
    /* Allocate a 0x10-byte header and a count*0x74 entry buffer (tags "anim_list"/"dsa_buf"),
       store {buffer, 0, count, buffer} in the header, and write {header, 0.0f} to out. */
    obj = (int *)((void *(*)(int, void *))fn_801284F8)(0x10, &lbl_80349FA4);
    if (obj) {
        data = (int)fn_8012850C(count * 0x74, &lbl_8055CD70);
        obj[0] = data;
        obj[2] = count;
        obj[1] = 0;
        obj[3] = data;
    }
    *(int **)out = obj;
    *(float *)((char *)out + 4) = lbl_8055E3C8;
    return out;
}

extern void fn_80128668(void *);
extern void fn_80128670(void *);
extern void fn_802AD30C(void *);
#pragma scheduling invalid_target
void *fn_802ADE60(void **holder, int freeHolder) {
    int entryCount;
    int entryOffset;
    void *set;
    int zero;
    /* Destroy an entry-set holder: release each entry's resource, free the set
       buffer and clear the header, then optionally free the holder itself. */
    if (holder != 0) {
        entryCount = *(int *)((char *)*holder + 4);
        entryOffset = entryCount * 0x74;
        goto loop_test;
        do {
            fn_802AD30C(*(void **)(*(char **)*holder + entryOffset + 0x64));
loop_test:
            entryOffset -= 0x74;
        } while (entryCount-- > 0);
        *(int *)((char *)*holder + 4) = 0;
        set = *holder;
        if (set != 0) {
            if (set != 0) {
                fn_80128670(*(void **)((char *)set + 0xC));
                if (set != 0) {
                    zero = 0;
                    *(int *)((char *)set + 0) = zero;
                    *(int *)((char *)set + 4) = zero;
                    *(int *)((char *)set + 8) = zero;
                }
            }
            fn_80128668(set);
        }
        if (freeHolder > 0) fn_80128668(holder);
    }
    return holder;
}
/* Loads an animation and appends it to the list, copying its name into the new entry and returning its index. */
int fn_802ADF34(void **listPtr, char *name, int table) {
    int animId;
    char *list;
    int remaining;
    char *dst;
    char *entry;
    unsigned char ch;
    animId = fn_802AC4A8(name, table);
    if (animId != 0) {
        list = (char *)*listPtr;
        entry = *(char **)list + (*(int *)(list + 4))++ * 0x74;
        dst = entry;
        remaining = 0x64;
        goto copy;
check:
        remaining--;
        if (remaining > 0) goto copy;
        dst[-1] = 0;
        goto copied;
copy:
        ch = *name++;
        *dst++ = ch;
        if ((signed char)ch != 0) goto check;
copied:
        *(int *)(entry + 0x64) = animId;
        entry[0x68] = 0;
        entry[0x69] = 0;
        list = (char *)*listPtr;
        return *(int *)(list + 4) - 1;
    }
    return -1;
}
#pragma scheduling on
void fn_802ADFF4(int **manager, int animIndex) {
#define CurrentGameTime lbl_8055E3C8
    unsigned char *entry = *(unsigned char **)*manager + animIndex * 0x74;
    /* ArtAnimManager::StartAnim: if animation `animIndex` has not started yet,
     * mark it running and unpaused and record the current game time as its start. */
    if (entry[0x68] == 0) {
        entry[0x68] = 1;
        entry[0x69] = 0;
        *(float *)(entry + 0x6c) = CurrentGameTime;
    }
#undef CurrentGameTime
}

/* Pause an animation entry by index, recording its pause time; warn and mark it running if it was not already started. */
void fn_802AE02C(void *manager, int animIndex) {
    char **entriesHolder;
    char *entriesBase;
    unsigned char *entry;
    entriesHolder = *(char ***)manager;
    entriesBase = *entriesHolder;
    entry = (unsigned char *)entriesBase + animIndex * 0x74;
    if (!entry[0x69]) {
        if (!entry[0x68]) {
            fn_802E30C8(lbl_80349FB0, animIndex, animIndex);
            entry[0x68] = 1;
            *(float *)(entry + 0x6c) = *(float *)((char *)manager + 4);
        }
        entry[0x69] = 1;
        *(float *)(entry + 0x70) = *(float *)((char *)manager + 4);
    }
}

void fn_802AE0B8(int **manager, int animIndex) {
    unsigned char *entry;
    /* Unpause an animation entry: clear its pause flag (+0x69) if it is set. */
    entry = (unsigned char *)**manager + animIndex * 0x74;
    if (entry[0x69]) entry[0x69] = 0;
}

/* Reset every animation entry of the manager to not-started by clearing its running flag at +0x68. */
void fn_802AE0E0(void **manager) {
    int offset;
    int index;
    index = 0;
    offset = 0;
    while (index < *(int *)(*(char **)manager + 4)) {
        *(unsigned char *)(*(char **)*(char **)manager + offset + 0x68) = 0;
        offset += 0x74;
        index++;
    }
}

/* For each active entry in the nested list, stores (arg0->baseValue - entry->ref->valueAt2C)
 * into entry->computedValue at +0x6C when entry->active (+0x68) is set. */
void fn_802AE118(void *arg0) {
    int off;
    int i;
    i = 0;
    off = 0;
    while (i < *(int *)(*(char **)arg0 + 4)) {
        if (*(unsigned char *)((unsigned char *)*(char **)*(char **)arg0 + off + 0x68) != 0) {
            *(float *)((unsigned char *)*(char **)*(char **)arg0 + off + 0x6C) =
                *(float *)((char *)arg0 + 4) -
                *(float *)(*(char **)((unsigned char *)*(char **)*(char **)arg0 + off + 0x64) + 0x2C);
        }
        off += 0x74;
        i++;
    }
}

#pragma push
#pragma use_lmw_stmw off
/* Update each active entry's accumulated and previous time from the current time value. */
void fn_802AE168(void *arg0) {
    extern float lbl_8055E3C8;
    extern void fn_802AD414(void *, float);
    int offset = 0;
    int i = 0;
    unsigned char *entry;
    *(float *)((char *)arg0 + 4) = lbl_8055E3C8;
    while (i < *(int *)(*(char **)arg0 + 4)) {
        entry = (unsigned char *)*(char **)*(char **)arg0 + offset;
        if (entry[0x69]) {
            *(float *)(entry + 0x6c) = *(float *)(entry + 0x6c) + (*(float *)((char *)arg0 + 4) - *(float *)(entry + 0x70));
            *(float *)(entry + 0x70) = *(float *)((char *)arg0 + 4);
        }
        if (entry[0x68]) fn_802AD414(*(void **)(entry + 0x64), *(float *)((char *)arg0 + 4) - *(float *)(entry + 0x6c));
        offset += 0x74;
        i++;
    }
}
#pragma pop
/* Evaluate active timeline entries at the current time, passing an extra parameter. */
void fn_802AE220(void *arg0, int arg1) {
    int offset = 0;
    int i = 0;
    unsigned char *entry;

    while (i < *(int *)(*(char **)arg0 + 4)) {
        entry = (unsigned char *)*(char **)*(char **)arg0 + offset;
        if (entry[0x68]) {
            fn_802AD4C4(*(void **)(entry + 0x64), arg1,
                        *(float *)((char *)arg0 + 4) - *(float *)(entry + 0x6c));
        }
        offset += 0x74;
        i++;
    }
}

