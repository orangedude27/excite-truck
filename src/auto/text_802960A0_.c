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
extern "C" void fn_802960A0(float *pos, unsigned int color, int tex, float s, double u0, double u1, double v0, double v1) {
    float *m = (float *)fn_802C86DC();
    float v[3];
    float uv[8];
    float vtx[4][6];
    unsigned short idx[6];
    float ns = -s;
    float t9 = m[0] * ns, t12 = m[1] * ns, t25 = m[2] * ns;
    float f5, f4, f6, px, py, pz, k, f13, f12, f11;
    float a0, a1, a2, b0, b1, b2, c0, c1, c2, d0;
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
    a0 = px + f13; a1 = py + f12; a2 = pz + f11;
    b0 = f13 * lbl_80564548; b1 = f12 * lbl_80564548; b2 = f11 * lbl_80564548;
    c0 = px + b0; c1 = py + b1; c2 = pz + b2;
    d0 = pz + f11 * lbl_80564548;
    vtx[1][0] = a0; vtx[1][1] = a1; vtx[1][2] = a2;
    vtx[3][0] = c0; vtx[3][1] = c1; vtx[3][2] = c2;
    v[0] = f13; v[1] = f12; v[2] = f11;
    vtx[0][4] = u0; vtx[0][5] = v0;
    vtx[1][4] = u1; vtx[1][5] = v0;
    vtx[2][4] = u1; vtx[2][5] = v1;
    vtx[3][4] = u0; vtx[3][5] = v1;
    ((int *)vtx[0])[3] = color; ((int *)vtx[1])[3] = color; ((int *)vtx[2])[3] = color; ((int *)vtx[3])[3] = color;
    fn_802C8BD0(tex, pz, c1, c0, b1, b0, c2, u1, v1, a1, a0, f11, f12, f13);
    idx[0] = lbl_802FA9C0[0]; idx[1] = lbl_802FA9C0[1]; idx[2] = lbl_802FA9C0[2];
    idx[3] = lbl_802FA9C0[3]; idx[4] = lbl_802FA9C0[4]; idx[5] = lbl_802FA9C0[5];
    fn_802C8DB8(vtx, 4, idx, 6, lbl_802FA9C0[4], lbl_802FA9C0[3], lbl_802FA9C0[2], lbl_802FA9C0[1]);
    fn_802C8D74();
}

extern "C" int fn_802962CC(void *node) {
    class NameNode {
    public:
        virtual char *getName();
    };
    return stricmp(((NameNode *)node)->getName(), (const char *)lbl_8055C9B8) == 0;
}

#pragma push
#pragma cplusplus on
extern "C" int fn_80296308(void *node) {
    class NameNode {
    public:
        virtual char *getName();
    };
    return stricmp(((NameNode *)node)->getName(), (const char *)lbl_8055C9C0) == 0;
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
extern "C" int fn_802963F0(void *arg0, int arg1) {
    class Node {
    public:
        virtual void f0();
        virtual int has(const char *);
        virtual void f2();
        virtual char *getText(const char *);
    };
    int *table;
    int result = arg1;
    int values[8];
    char *text;
    unsigned int i;
    if (((Node *)arg0)->has((const char *)lbl_8055C9E4) != 0) {
        table = (int *)lbl_802FA9D0;
        values[0] = *table++;
        values[1] = *table++;
        values[2] = *table++;
        values[3] = *table++;
        values[4] = *table++;
        values[5] = *table++;
        values[6] = *table++;
        values[7] = *table++;
        text = ((Node *)arg0)->getText((const char *)lbl_8055C9E4);
        result = 0;
        table = values;
        for (i = 0; i < 4; i++, table += 2) {
            if (strstr(text, (char *)table[1]) != 0)
                result |= table[0];
        }
    }
    return result;
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
extern "C" int fn_802964EC(void *arg0, void *arg1, void *arg2) {
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
void fn_802968E8(void *arg0) {
    int count = *(int *)((char *)arg0 + 0x28);
    *(int *)((char *)arg0 + 0x28) = count + 1;
    if (count == 0) {
        *(void **)((char *)arg0 + 0x20) = lbl_8055F788;
        lbl_8055F788 = arg0;
    }
}

#pragma push
#pragma dont_inline on
void fn_8029690C(arg0)
void *arg0;
{
    int count;
    void **link;

    count = *(int *)((char *)arg0 + 0x28) - 1;
    *(int *)((char *)arg0 + 0x28) = count;
    if (count != 0)
        return;

    link = &lbl_8055F788;
    while (*link != 0) {
        if (*link == arg0) {
            *link = *(void **)((char *)arg0 + 0x20);
            break;
        }
        link = (void **)((char *)*link + 0x20);
    }
    fn_80296838(arg0);
}
#pragma pop

void *fn_80296950(const char *arg0) {
    void *node = lbl_8055F788;
    while (node != 0) {
        if (stricmp(arg0, (const char *)node) == 0) return node;
        node = *(void **)((char *)node + 0x20);
    }
    return 0;
}

int fn_802969B4(unsigned int arg0, unsigned int arg1, float farg0) {
    return (int)((float)arg0 + farg0 * ((float)arg1 - (float)arg0));
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling invalid_target
int fn_80296A10(unsigned int arg0, unsigned int arg1, float arg2) {
    int a = fn_802969B4(arg0 & 0xFF, arg1 & 0xFF, arg2);
    int b = fn_802969B4((arg0 >> 8) & 0xFF, (arg1 >> 8) & 0xFF, arg2);
    int c = fn_802969B4((arg0 >> 16) & 0xFF, (arg1 >> 16) & 0xFF, arg2);
    int d = fn_802969B4(arg0 >> 24, arg1 >> 24, arg2);
    int lo = (a & 0xFF) | ((b & 0xFF) << 8);
    int hi = ((d & 0xFF) << 24) | ((c & 0xFF) << 16);
    return lo | hi;
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_80296AAC(void *arg0) {
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
void fn_80296D24(void) {}

void fn_80296D28(void) { fn_8029690C(); }

extern void fn_802960A0(float *, unsigned int, int, float, double, double, double, double);
extern int fn_80296A10(unsigned int, unsigned int, float);
extern int fn_802969B4(unsigned int, unsigned int, float);
extern float lbl_80564548, lbl_80564560, lbl_8056456C, lbl_80564570, lbl_80564574;
struct KF { float dur; float a[4]; unsigned int col; int p18; float h; float v[3]; int flags; };
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
int fn_80296D2C(void *arg0, float *arg1, float farg0) {
    struct KF *kf[2];
    struct KF *base;
    struct KF *cur, *nxt;
    int count, i, flags;
    float total, dur, t, ease, x, y, z, w, h;
    unsigned int packed;
    float vec[3];
    float sp[3];
    kf[0] = 0; kf[1] = 0;
    count = *(int *)((char *)arg0 + 0x2C);
    base = *(struct KF **)((char *)arg0 + 0x24);
    total = lbl_8056456C;
    for (i = 0; i < count; i++) {
        dur = base[i].dur;
        if (farg0 < total + dur) { kf[0] = &base[i]; break; }
        total += dur;
    }
    if (kf[0] == 0) return 0;
    kf[1] = kf[0];
    if (kf[0] != &base[count] - 1) kf[1] = kf[1] + 1;
    cur = kf[0];
    t = (total - farg0) / cur->dur;
    nxt = kf[1];
    flags = nxt->flags;
    if (t < lbl_80564548) ease = lbl_80564548;
    else if (t > lbl_80564560) ease = lbl_80564560;
    else if (t > lbl_8056456C) ease = t * (lbl_80564570 * t * t) + lbl_80564574 * t * t;
    else ease = t * (lbl_80564570 * t * t) - lbl_80564574 * t * t;
    if (flags & 1) x = cur->a[0] + ease * (nxt->a[0] - cur->a[0]); else x = cur->a[0];
    if (flags & 1) y = cur->a[1] + ease * (nxt->a[1] - cur->a[1]); else y = cur->a[1];
    if (flags & 1) z = cur->a[2] + ease * (nxt->a[2] - cur->a[2]); else z = cur->a[2];
    if (flags & 1) w = cur->a[3] + ease * (nxt->a[3] - cur->a[3]); else w = cur->a[3];
    if (flags & 2) packed = fn_80296A10(cur->col, nxt->col, ease); else packed = cur->col;
    if (flags & 8) h = cur->h + ease * (nxt->h - cur->h); else h = cur->h;
    if (flags & 8) {
        vec[0] = cur->v[0] + ease * (nxt->v[0] - cur->v[0]);
        vec[1] = cur->v[1] + ease * (nxt->v[1] - cur->v[1]);
        vec[2] = cur->v[2] + ease * (nxt->v[2] - cur->v[2]);
    } else {
        vec[0] = cur->v[0]; vec[1] = cur->v[1]; vec[2] = cur->v[2];
    }
    sp[0] = vec[0] + arg1[0];
    sp[1] = vec[1] + arg1[1];
    sp[2] = vec[2] + arg1[2];
    if (flags & 4) {
        int a = packed >> 24;
        int a2 = fn_802969B4(a, 0, ease) & 0xFF;
        fn_802960A0(sp, (a2 << 24) | (packed & 0xFFFFFF), kf[0]->p18, h, x, y, z, w);
        fn_802960A0(sp, (packed & 0xFFFFFF) | ((a - a2) << 24), kf[1]->p18, h, x, y, z, w);
    } else {
        fn_802960A0(sp, packed, kf[0]->p18, h, x, y, z, w);
    }
    return 1;
}

#pragma push
#pragma cplusplus on
extern "C" float fn_802970C8(void *arg0) {
    int use_unrolled = 0;
    int count = *(int *)((char *)arg0 + 0x2C);
    int processed = 0;
    int rest;
    unsigned int groups;
    float sum = lbl_8056456C;
    if (count <= 0) {
        return sum;
    }
    rest = count - 8;
    if (rest <= 0) {
        goto tail;
    }
    if (count < 0) {
        goto check;
    }
    if (count > 0x7FFFFFFE) {
        goto check;
    }
    use_unrolled = 1;
check:
    if (use_unrolled == 0) {
        goto tail;
    }
    groups = ((unsigned int)rest + 7) >> 3;
    {
        int offset = 0;
        unsigned int g = groups;
        float *base0 = *(float **)((char *)arg0 + 0x24);
        do {
            float *rec = (float *)((char *)base0 + offset);
            sum += rec[0];
            sum += rec[0x30/4];
            sum += rec[0x60/4];
            sum += rec[0x90/4];
            sum += rec[0xC0/4];
            sum += rec[0xF0/4];
            sum += rec[0x120/4];
            sum += rec[0x150/4];
            processed += 8;
            offset += 0x180;
        } while (--g != 0);
    }
tail:
    if (processed < count) {
        float *base = *(float **)((char *)arg0 + 0x24);
        int off = processed * 0x30;
        int r = count - processed;
        do {
            sum += *(float *)((char *)base + off);
            off += 0x30;
        } while (--r != 0);
    }
    return sum;
}
#pragma pop

#pragma scheduling on
#pragma pop
