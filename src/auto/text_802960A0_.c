// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).


extern float lbl_80564560;
extern float lbl_80564564;
extern float lbl_80564568;
extern float lbl_8056456C;
extern void *lbl_8055F788;
int stricmp(const char *, const char *);
extern void *lbl_8055F788;
int stricmp(const char *, const char *);
__declspec(section ".sdata") extern char lbl_8055C9B8[];
__declspec(section ".sdata") extern char lbl_8055C9C0[];
#pragma push
#pragma cplusplus on
extern float lbl_80564548, lbl_8056454C;
extern unsigned short lbl_802FA9C0[6];
extern "C" void *fn_802C86DC(void);
extern "C" void fn_802C8BD0(int, float, float, float, float, float, float, float, float, float, float, float, float, float);
extern "C" void fn_802C8D74(void);
extern "C" void fn_802C8DB8(void *, int, void *, int, unsigned short, unsigned short, unsigned short, unsigned short);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_802960A0(float *pos, unsigned int color, int tex, float s, double u0, double u1, double v0, double v1) {
    float *m = (float *)fn_802C86DC();
    float v[3];
    float uv[8];
    float vtx[4][6];
    unsigned short idx[6];
    unsigned short *ip = lbl_802FA9C0;
    float ns = -s;
    float t9 = m[0] * ns, t12 = m[1] * ns, t25 = m[2] * ns;
    float f5, f4, f6, px, py, pz, k, f13, f12, f11;
    v[0] = t9; v[1] = t12; v[2] = t25;
    f5 = t12 + m[4] * s;
    f4 = t25 + m[5] * s;
    f6 = t9 + m[3] * s;
    px = pos[0]; py = pos[1]; pz = pos[2];
    vtx[0][0] = px + f6; vtx[0][1] = py + f5; vtx[0][2] = pz + f4;
    k = lbl_8056454C * s;
    vtx[2][0] = px + f6 * lbl_80564548; vtx[2][1] = py + f5 * lbl_80564548; vtx[2][2] = pz + f4 * lbl_80564548;
    uv[0] = u0; uv[1] = v0; uv[2] = u1; uv[3] = v0; uv[4] = u1; uv[5] = v1; uv[6] = u0; uv[7] = v1;
    f13 = f6 + m[0] * k; f12 = f5 + m[1] * k; f11 = f4 + m[2] * k;
    vtx[1][0] = px + f13; vtx[1][1] = py + f12; vtx[1][2] = pz + f11;
    vtx[3][0] = px + f13 * lbl_80564548; vtx[3][1] = py + f12 * lbl_80564548; vtx[3][2] = pz + f11 * lbl_80564548;
    v[0] = f13; v[1] = f12; v[2] = f11;
    vtx[0][4] = uv[0]; vtx[0][5] = uv[1];
    vtx[1][4] = uv[2]; vtx[1][5] = uv[3];
    vtx[2][4] = uv[4]; vtx[2][5] = uv[5];
    vtx[3][4] = uv[6]; vtx[3][5] = uv[7];
    ((int *)vtx[0])[3] = color; ((int *)vtx[1])[3] = color; ((int *)vtx[2])[3] = color; ((int *)vtx[3])[3] = color;
    fn_802C8BD0(tex, pz, py + f12 * lbl_80564548, px + f13 * lbl_80564548, f12 * lbl_80564548, f13 * lbl_80564548, pz + f11 * lbl_80564548, uv[2], uv[5], py + f12, px + f13, f11, f12, f13);
    idx[0] = ip[0]; idx[1] = ip[1]; idx[2] = ip[2];
    idx[3] = ip[3]; idx[4] = ip[4]; idx[5] = ip[5];
    fn_802C8DB8(vtx, 4, idx, 6, ip[4], ip[3], ip[2], ip[1]);
    fn_802C8D74();
}
#pragma pop
#define kFrameName lbl_8055C9B8  // .sdata: "frame", the name of an opening frame entry
// True when a parsed list entry's virtual name is "frame" (case-insensitive).
extern "C" int fn_802962CC(void *entry) {
    class NameNode {
    public:
        virtual char *getName();
    };
    return stricmp(((NameNode *)entry)->getName(), (const char *)kFrameName) == 0;
}

#define kDefaultName lbl_8055C9C0  // .sdata: "default"
// True when a parsed list entry's virtual name is "default" (case-insensitive).
#pragma push
#pragma cplusplus on
extern "C" int fn_80296308(void *node) {
    class NameNode {
    public:
        virtual char *getName();
    };
    return stricmp(((NameNode *)node)->getName(), (const char *)kDefaultName) == 0;
}

#pragma cplusplus on
extern "C" int sscanf(const char *, const char *, ...);
extern char lbl_802FE850[];
__declspec(section ".sdata") extern char lbl_8055C9C8[];
__declspec(section ".sdata") extern char lbl_8055C9CC[];
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_80296344(void *arg0, void *arg1, int arg2) {
    class Node {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual const char *getString(const char *key, const char *defaultValue);
    };
    int result;
    register int invalid;
    register int c;
    const char *text;
    unsigned char *charMap;
    void *localeData;

    /* Get a string property and parse "0x..." hex; otherwise return default arg2. */
    text = ((Node *)arg0)->getString((const char *)arg1, lbl_8055C9C8); /* default "" */
    if (text[0] != '0') {
        goto fallback;
    }
    c = (signed char)text[1];
    invalid = 0;
    if (c < 0) {
        goto set_invalid;
    }
    if (c < 0x100) {
        goto check_invalid;
    }
set_invalid:
    invalid = 1;
check_invalid:
    switch (invalid) {
    case 0:
        goto lookup;
    default:
        goto test_char;
    }
lookup:
    localeData = *(void **)(lbl_802FE850 + 0x38);
    charMap = *(unsigned char **)((char *)localeData + 0x10);
    c = charMap[c];
test_char:
    if (c != 'x') {
        goto fallback;
    }
    sscanf(text + 2, lbl_8055C9CC, &result); /* "%x" */
    goto done;
fallback:
    result = arg2;
done:
    return result;
}

#pragma cplusplus on
extern int lbl_802FA9D0[];
__declspec(section ".sdata") extern char lbl_8055C9E4[];
extern "C" char *strstr(const char *, const char *);
#pragma cplusplus on
/* Return a node's "blend" attribute as a mask of channels (uv=1,color=2,tex=4,pos=8) found in its text, or defaultFlags when the attribute is absent. */ extern "C" int fn_802963F0(void *node, int defaultFlags) {
    class Node {
    public:
        virtual void f0();
        virtual int has(const char *);
        virtual void f2();
        virtual char *getText(const char *);
    };
    int *entry;
    int flags = defaultFlags;
    int entries[8];
    char *blendText;
    unsigned int i;
    if (((Node *)node)->has((const char *)lbl_8055C9E4) != 0) {
        entry = (int *)lbl_802FA9D0;
        entries[0] = *entry++;
        entries[1] = *entry++;
        entries[2] = *entry++;
        entries[3] = *entry++;
        entries[4] = *entry++;
        entries[5] = *entry++;
        entries[6] = *entry++;
        entries[7] = *entry++;
        blendText = ((Node *)node)->getText((const char *)lbl_8055C9E4);
        flags = 0;
        entry = entries;
        for (i = 0; i < 4; i++, entry += 2) {
            if (strstr(blendText, (char *)entry[1]) != 0)
                flags |= entry[0];
        }
    }
    return flags;
}
#pragma cplusplus reset

#pragma cplusplus reset
#pragma scheduling on

extern "C" int fn_80296344(void *, void *, int);
extern "C" int fn_802963F0(void *, int);
extern "C" int fn_802CAC28(void *, int);
__declspec(section ".sdata") extern char lbl_8055C9D4[];
__declspec(section ".sdata") extern char lbl_8055C9DC[];
__declspec(section ".sdata") extern char lbl_8055C9EC[];
__declspec(section ".sdata") extern char lbl_8055C9F0[];
__declspec(section ".sdata") extern char lbl_8055C9F4[];
__declspec(section ".sdata") extern char lbl_8055C9F8[];
__declspec(section ".sdata") extern char lbl_8055C9FC[];
__declspec(section ".sdata") extern char lbl_8055CA00[];
__declspec(section ".sdata") extern char lbl_8055CA08[];
__declspec(section ".sdata") extern char lbl_8055CA0C[];
__declspec(section ".sdata") extern char lbl_8055CA14[];
__declspec(section ".sdata") extern char lbl_8055CA1C[];
__declspec(section ".sdata") extern char lbl_8055CA24[];
extern float lbl_80564550;
extern float lbl_80564554;
#pragma scheduling invalid_target
extern "C" int fn_802964EC(void *arg0, void *arg1, void *__restrict arg2) {
    struct Vec3 { float x, y, z; };
    class Node {
    public:
        virtual void v0();
        virtual int has(const char *);
        virtual void v2();
        virtual void *getObject(const char *);
        virtual void v4();
        virtual int getInt(const char *);
        virtual void v6();
        virtual float getFloat(const char *);
        virtual float getFloatDefault(const char *, float);
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual Vec3 getVector(const char *, Vec3);
    };
    void *node = arg1;
    float *src = (float *)arg2;
    float *dst = (float *)arg0;
    int *word = (int *)((char *)arg0 + 0x14);

    dst[0] = ((Node *)node)->getFloatDefault(lbl_8055C9EC, src[0]);
    dst[1] = ((Node *)node)->getFloatDefault(lbl_8055C9F0, src[1]);
    dst[2] = ((Node *)node)->getFloatDefault(lbl_8055C9F4, src[2]);
    dst[3] = ((Node *)node)->getFloatDefault(lbl_8055C9F8, src[3]);
    dst[4] = ((Node *)node)->getFloatDefault(lbl_8055C9FC, src[4]);
    *word = fn_80296344(node, lbl_8055C9D4, *(int *)((char *)arg2 + 0x14));

    if (((Node *)node)->has(lbl_8055CA00)) {
        *word &= 0x00FFFFFF;
        *word |= ((Node *)node)->getInt(lbl_8055CA00) << 24;
    }
    if (((Node *)node)->has(lbl_8055CA08)) {
        *word &= 0xFF00FFFF;
        *word |= ((Node *)node)->getInt(lbl_8055CA08) << 16;
    }
    if (((Node *)node)->has(lbl_8055CA0C)) {
        *word &= 0xFFFF00FF;
        *word |= ((Node *)node)->getInt(lbl_8055CA0C) << 8;
    }
    if (((Node *)node)->has(lbl_8055CA14)) {
        *word &= 0xFFFFFF00;
        *word |= ((Node *)node)->getInt(lbl_8055CA14);
    }
    if (((Node *)node)->has(lbl_8055C9DC))
        *(int *)((char *)arg0 + 0x18) = fn_802CAC28(((Node *)node)->getObject(lbl_8055C9DC), 0);
    else
        *(int *)((char *)arg0 + 0x18) = *(int *)((char *)arg2 + 0x18);

    if (((Node *)node)->has(lbl_8055CA1C)) {
        float scaled = ((Node *)node)->getFloat(lbl_8055CA1C);
        scaled *= lbl_80564550;
        dst[7] = scaled / lbl_80564554;
    } else
        dst[7] = src[7];

    const Vec3 &result = ((Node *)node)->getVector(
        lbl_8055CA24, *(Vec3 *)((char *)arg2 + 0x20));
    dst[8] = result.x;
    dst[9] = result.y;
    dst[10] = result.z;
    *(int *)((char *)arg0 + 0x2C) = fn_802963F0(node, *(int *)((char *)arg2 + 0x2C));
    return 1;
}

 #pragma cplusplus reset
#pragma pop

#pragma cplusplus reset
#pragma pop
extern void fn_802CAC54(int);
extern void fn_80128670(void *);
extern void fn_80128668(void *);
extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *, int);
extern void *fn_80131808(void *);
extern void fn_80131818(void *);
extern int fn_8012C33C(void *);
extern void *fn_8002F37C(void *, void *, void *, int, int);
extern char *strncpy(char *, const char *, unsigned int);
extern char lbl_80349348[], lbl_80349354[];
extern void fn_80296D24(void);
#pragma use_lmw_stmw off
void fn_80296838(void *obj) {
    int offset;
    int i;
    int entryPtr;
    int state;
    void *entries;

    /* Destroy: release each active entry's resource (state at +0x18, -1/-2 unused) via fn_802CAC54 and mark freed, then free the 0x30-sized entry array and the object. */
    if (obj == 0) {
        return;
    }
    entries = *(void **)((char *)obj + 0x24);
    if (entries != 0) {
        i = 0;
        offset = 0;
        while (i < *(int *)((char *)obj + 0x2C)) {
            entries = *(void **)((char *)obj + 0x24);
            entryPtr = (int)entries + offset;
            state = *(int *)(entryPtr + 0x18);
            if (state != -1 && state != -2) {
                fn_802CAC54(state);
                *(int *)(entryPtr + 0x18) = -2;
            }
            offset += 0x30;
            i++;
        }
        entries = *(void **)((char *)obj + 0x24);
        if (entries != 0) {
            fn_80128670((char *)entries - 0x10);
        }
        *(void **)((char *)obj + 0x24) = 0;
    }
    fn_80128668(obj);
}
#pragma use_lmw_stmw on
/* Increment the object's reference count; on the first reference, link it
 * into the global object list via its +0x20 next pointer. */
void fn_802968E8(void *object) {
    int count = *(int *)((char *)object + 0x28);
    *(int *)((char *)object + 0x28) = count + 1;
    if (count == 0) {
        *(void **)((char *)object + 0x20) = lbl_8055F788;
        lbl_8055F788 = object;
    }
}

#pragma push
#pragma dont_inline on
void fn_8029690C(arg0)
void *arg0;
{
    /* Decrement refcount; when it hits zero, unlink from list and destroy. */
    #define gObjectListHead lbl_8055F788

    int count;
    void **link;

    count = *(int *)((char *)arg0 + 0x28) - 1;
    *(int *)((char *)arg0 + 0x28) = count;
    if (count != 0)
        return;

    link = &gObjectListHead;
    while (*link != 0) {
        if (*link == arg0) {
            *link = *(void **)((char *)arg0 + 0x20);
            break;
        }
        link = (void **)((char *)*link + 0x20);
    }
    fn_80296838(arg0);

    #undef gObjectListHead
}
#pragma pop

/* Find a node in the lbl_8055F788 linked list whose name (at offset 0)
 * matches the given string case-insensitively; return NULL if not found. */
void *fn_80296950(const char *name) {
    void *node = lbl_8055F788;
    while (node != 0) {
        if (stricmp(name, (const char *)node) == 0) return node;
        node = *(void **)((char *)node + 0x20);
    }
    return 0;
}

/* Linearly interpolates between unsigned values a and b by factor t, returning the result as int. */
int fn_802969B4(unsigned int a, unsigned int b, float t) {
    return (int)((float)a + t * ((float)b - (float)a));
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling invalid_target
// Linearly interpolates two packed RGBA colors, byte by byte, by blend factor arg2.
int fn_80296A10(unsigned int arg0, unsigned int arg1, float arg2) {
    int byte0 = fn_802969B4(arg0 & 0xFF, arg1 & 0xFF, arg2);
    int byte1 = fn_802969B4((arg0 >> 8) & 0xFF, (arg1 >> 8) & 0xFF, arg2);
    int byte2 = fn_802969B4((arg0 >> 16) & 0xFF, (arg1 >> 16) & 0xFF, arg2);
    int byte3 = fn_802969B4(arg0 >> 24, arg1 >> 24, arg2);
    int lo = (byte0 & 0xFF) | ((byte1 & 0xFF) << 8);
    int hi = ((byte3 & 0xFF) << 24) | ((byte2 & 0xFF) << 16);
    return lo | hi;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_80296AAC(void *arg0) {
    /* Initialize a 0x30-byte record: zero it, then set default float/int fields. */
    register float value68;
    register float value64;
    register float value60;

    memset(arg0, 0, 0x30);
    value60 = lbl_80564560;
    value64 = lbl_80564564;
    value68 = lbl_80564568;
    *(float *)((char *)arg0 + 0x10) = value60;
    *(float *)((char *)arg0 + 8) = value60;
    *(float *)((char *)arg0 + 0) = value64;
    *(float *)((char *)arg0 + 0x1C) = value68;
    *(int *)((char *)arg0 + 0x18) = -1;
    *(int *)((char *)arg0 + 0x2C) = 10;
    *(int *)((char *)arg0 + 0x14) = -1;
}
#pragma inline_depth(0)
#pragma use_lmw_stmw off
#pragma push
#pragma cplusplus on
/* Looks up or builds a 0x30-byte-entry table from a named collection iterator,
 * filtering/copying entries into a newly allocated result buffer. */
extern "C" void *fn_80296B10(char *arg0, void *arg1) {
    class Iterator {
    public:
        virtual void v0();
        virtual void *get(int);
    };
    int closeCount, openCount;
    void *result;
    int ok;
    Iterator *it;
    void *entry;
    int idx, off, back;
    char sp8[0x30];

    result = fn_80296950(arg0);
    if (result == 0) {
        ok = 0;
        if (fn_8012C33C(arg0) != 0) {
            it = (Iterator *)fn_80131808(arg0);
            openCount = 0;
            fn_80296AAC(sp8);
            closeCount = 0;
            for (;;) {
                entry = it->get(openCount + closeCount);
                if (entry == 0) break;
                if (fn_802962CC(entry) != 0) {
                    openCount++;
                } else {
                    if (fn_80296308(entry) != 0) {
                        fn_802964EC(sp8, entry, sp8);
                    }
                    closeCount++;
                }
            }
            if (arg1 != 0) {
                fn_802964EC(sp8, arg1, sp8);
            }
            if (openCount != 0) {
                ok = 1;
                result = fn_801284F8(0x30, lbl_80349348);
                *(void **)((char *)result + 0x24) = fn_8002F37C(fn_8012850C(openCount * 0x30 + 0x10, lbl_80349354, openCount * 0x30), (void *)fn_80296D24, 0, 0x30, openCount);
                *(int *)((char *)result + 0x2C) = openCount;
                *(int *)((char *)result + 0x28) = 0;
                if (arg1 != 0) {
                    *(char *)result = 0;
                } else {
                    strncpy((char *)result, arg0, 0x20);
                }
                idx = 0;
                back = 0;
                off = 0;
                while (ok != 0) {
                    void *item = it->get(idx);
                    if (item == 0) break;
                    if (fn_802962CC(item) != 0) {
                        if (fn_802964EC((char *)*(void **)((char *)result + 0x24) + off - back, item, sp8) == 0) {
                            ok = 0;
                        }
                    } else {
                        back += 0x30;
                    }
                    off += 0x30;
                    idx++;
                }
            }
            fn_80131818(it);
        }
        if (ok == 0) {
            fn_80296838(result);
            result = 0;
        }
    }
    if (result != 0) {
        fn_802968E8(result);
    }
    return result;
}
#pragma pop
/* No-op element constructor for the 0x30-byte open-entry records that
 * fn_8002F37C allocates at result+0x24 in fn_80296B10; the records are filled
 * in afterwards by fn_802964EC, so each element needs no setup here. */
void fn_80296D24(void) {}

/* FlipBook_release: drop one reference to a FlipBook by tail-calling the
 * refcount-decrement/destroy routine fn_8029690C with the object still in r3. */
void fn_80296D28(void) { fn_8029690C(); }

extern void fn_802960A0(float *, unsigned int, int, float, double, double, double, double);
extern int fn_80296A10(unsigned int, unsigned int, float);
extern int fn_802969B4(unsigned int, unsigned int, float);
extern float lbl_80564548, lbl_80564560, lbl_8056456C, lbl_80564570, lbl_80564574;
struct KF { float dur; float a[4]; unsigned int col; int p18; float h; float v[3]; int flags; };
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
int fn_80296D2C(void *arg0, float *arg1, float farg0) {
    struct KF *kf[2];
    struct KF **kp = kf;
    struct KF *base;
    int count, i, flags, off;
    float dur, total, t, ease, x, y, z, w, h;
    unsigned int packed;
    float sp[3];
    float vec[3];
    kp[0] = 0; kp[1] = 0;
    count = *(int *)((char *)arg0 + 0x2C);
    base = *(struct KF **)((char *)arg0 + 0x24);
    total = lbl_8056456C;
    off = 0;
    for (i = 0; i < count; i++) {
        struct KF *b = *(struct KF **)((char *)arg0 + 0x24);
        dur = *(float *)((char *)b + off);
        if (farg0 < total + dur) { kp[0] = (struct KF *)((char *)b + off); break; }
        total += dur;
        off += 0x30;
    }
    if (kp[0] == 0) goto ret0;
    if (kp[0] == *(struct KF **)((char *)arg0 + 0x24) + *(int *)((char *)arg0 + 0x2C) - 1) kp[1] = kp[0];
    else kp[1] = kp[0] + 1;
    t = (total - farg0) / kp[0]->dur;
    flags = kp[1]->flags;
    if (t < lbl_80564548) ease = lbl_80564548;
    else if (t > lbl_80564560) ease = lbl_80564560;
    else if (t > lbl_8056456C) ease = t * (lbl_80564570 * t * t) + lbl_80564574 * t * t;
    else ease = t * (lbl_80564570 * t * t) - lbl_80564574 * t * t;
    if (flags & 1) x = kp[0]->a[0] + ease * (kp[1]->a[0] - kp[0]->a[0]); else x = kp[0]->a[0];
    if (flags & 1) y = kp[0]->a[1] + ease * (kp[1]->a[1] - kp[0]->a[1]); else y = kp[0]->a[1];
    if (flags & 1) z = kp[0]->a[2] + ease * (kp[1]->a[2] - kp[0]->a[2]); else z = kp[0]->a[2];
    if (flags & 1) w = kp[0]->a[3] + ease * (kp[1]->a[3] - kp[0]->a[3]); else w = kp[0]->a[3];
    if (flags & 2) packed = fn_80296A10(kp[0]->col, kp[1]->col, ease); else packed = kp[0]->col;
    if (flags & 8) h = kp[0]->h + ease * (kp[1]->h - kp[0]->h); else h = kp[0]->h;
    if (flags & 8) {
        vec[0] = kp[0]->v[0] + ease * (kp[1]->v[0] - kp[0]->v[0]);
        vec[1] = kp[0]->v[1] + ease * (kp[1]->v[1] - kp[0]->v[1]);
        vec[2] = kp[0]->v[2] + ease * (kp[1]->v[2] - kp[0]->v[2]);
    } else {
        vec[0] = kp[0]->v[0]; vec[1] = kp[0]->v[1]; vec[2] = kp[0]->v[2];
    }
    sp[0] = vec[0] + arg1[0];
    sp[1] = vec[1] + arg1[1];
    sp[2] = vec[2] + arg1[2];
    if (flags & 4) {
        int a = packed >> 24;
        int a2 = fn_802969B4(a, 0, ease) & 0xFF;
        fn_802960A0(sp, (a2 << 24) | (packed & 0xFFFFFF), kp[0]->p18, h, x, y, z, w);
        fn_802960A0(sp, (packed & 0xFFFFFF) | ((a - a2) << 24), kp[1]->p18, h, x, y, z, w);
    } else {
        fn_802960A0(sp, packed, kp[0]->p18, h, x, y, z, w);
    }
    return 1;
ret0:
    return 0;
}
#pragma pop

/* FlipBook: the named keyframe collection fn_80296B10 hands out and
 * FlipBook_release (fn_80296D28) refcounts.  Its 0x30-byte keyframe records
 * (struct KF above) start at +0x24; +0x2C counts them. */
typedef struct FlipBook {
    char pad[0x24];    /* +0x00 header, links; the next collection is at +0x20 */
    struct KF *kf;     /* +0x24 keyframe records, count of them */
    int refCount;      /* +0x28 references held */
    int count;         /* +0x2C number of keyframe records */
} FlipBook;

#define kZeroTime lbl_8056456C  /* .sdata2: 0.0f, the running time these sums start from */

#pragma push
#pragma cplusplus on
extern "C" float fn_802970C8(void *arg0) {
    struct Ctx { char pad[0x24]; struct KF *kf; int unk28; int count; };
    Ctx *ctx = (Ctx *)arg0;
    float sum = lbl_8056456C;
    int i;
    for (i = 0; i < ctx->count; i++) {
        sum += ctx->kf[i].dur;
    }
    return sum;
}
#pragma pop

#pragma scheduling on
#pragma pop
