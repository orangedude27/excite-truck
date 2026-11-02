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
        virtual const char *getString(const char *, const char *);
    };
    int result;
    register int invalid;
    register int c;
    const char *name;
    unsigned char *table;
    void *cmap;

    name = ((Node *)arg0)->getString((const char *)arg1, lbl_8055C9C8);
    if (name[0] != '0') {
        goto fallback;
    }
    c = (signed char)name[1];
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
    cmap = *(void **)(lbl_802FE850 + 0x38);
    table = *(unsigned char **)((char *)cmap + 0x10);
    c = table[c];
test_char:
    if (c != 'x') {
        goto fallback;
    }
    sscanf(name + 2, lbl_8055C9CC, &result);
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
    typedef char *(*GetText)(void *, const char *);
    int result = arg1;
    int values[8];
    register int *table;
    register void **vtable;
    GetText getText;
    char *text;
    unsigned int i;

    if (((Node *)arg0)->has(lbl_8055C9E4) != 0) {
        vtable = *(void ***)arg0;
        table = lbl_802FA9D0;
        values[0] = *table++;
        getText = (GetText)vtable[5];
        values[1] = *table++;
        values[2] = *table++;
        values[3] = *table++;
        values[4] = *table++;
        values[5] = *table++;
        values[6] = *table++;
        values[7] = *table++;
        text = getText(arg0, lbl_8055C9E4);
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

    *(Vec3 *)(dst + 8) = ((Node *)node)->getVector(
        lbl_8055CA24, *(Vec3 *)((char *)arg2 + 0x20));
    *(int *)((char *)arg0 + 0x2C) = fn_802963F0(node, *(int *)((char *)arg2 + 0x2C));
    return 1;
}
#pragma scheduling on

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
void fn_80296838(void *arg0) {
    int offset;
    int i;
    int entryAddress;
    int state;
    void *list;

    if (arg0 == 0) {
        return;
    }
    list = *(void **)((char *)arg0 + 0x24);
    if (list != 0) {
        i = 0;
        offset = 0;
        while (i < *(int *)((char *)arg0 + 0x2C)) {
            list = *(void **)((char *)arg0 + 0x24);
            entryAddress = (int)list + offset;
            state = *(int *)(entryAddress + 0x18);
            if (state != -1 && state != -2) {
                fn_802CAC54(state);
                *(int *)(entryAddress + 0x18) = -2;
            }
            offset += 0x30;
            i++;
        }
        list = *(void **)((char *)arg0 + 0x24);
        if (list != 0) {
            fn_80128670((char *)list - 0x10);
        }
        *(void **)((char *)arg0 + 0x24) = 0;
    }
    fn_80128668(arg0);
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
extern "C" void *fn_80296B10(char *arg0, void *arg1) {
    class Iterator {
    public:
        virtual void v0();
        virtual void *get(int);
    };
    int close, open;
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
            open = 0;
            fn_80296AAC(sp8);
            close = 0;
            for (;;) {
                entry = it->get(open + close);
                if (entry == 0) break;
                if (fn_802962CC(entry) != 0) {
                    open++;
                } else {
                    if (fn_80296308(entry) != 0) {
                        fn_802964EC(sp8, entry, sp8);
                    }
                    close++;
                }
            }
            if (arg1 != 0) {
                fn_802964EC(sp8, arg1, sp8);
            }
            if (open != 0) {
                ok = 1;
                result = fn_801284F8(0x30, lbl_80349348);
                *(void **)((char *)result + 0x24) = fn_8002F37C(fn_8012850C(open * 0x30 + 0x10, lbl_80349354, open * 0x30), (void *)fn_80296D24, 0, 0x30, open);
                *(int *)((char *)result + 0x2C) = open;
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
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
int fn_80296D2C(void *arg0, float *arg1, float farg0) {
    char * volatile selected;
    char * volatile next;
    char *current;
    int count;
    register int offset;
    char *base;
    int flags;
    int color;
    int alpha;
    int alpha2;
    float total;
    float duration;
    
    float t;
    float ease;
    float x;
    float y;
    float z;
    float w;
    float h;
    float d;
    float v0;
    float v1;
    float v2;
    float v3;
    float v4;
    float v5;
    float vx;
    float vy;
    float vz;
    float sp1c;
    float sp20;
    float sp24;
    unsigned int packed;
    unsigned int rgb;
    unsigned int low;

    count = *(int *)((char *)arg0 + 0x2C);
    base = (char *)*(void **)((char *)arg0 + 0x24);
    selected = 0;
    next = 0;
    total = lbl_8056456C;
    offset = 0;
    if (count > 0) {
        do {
            duration = *(float *)(base + offset);
            if (farg0 < total + duration) {
                selected = base + offset;
                break;
            }
            total += duration;
            offset += 0x30;
        } while (--count != 0);
    }
    if (selected == 0) return 0;

    next = selected;
    current = (char *)*(void **)((char *)arg0 + 0x24) +
        *(int *)((char *)arg0 + 0x2C) * 0x30 - 0x30;
    if (selected != current) next += 0x30;

    current = selected;
    t = (total - farg0) / *(float *)current;
    flags = *(int *)(next + 0x2C);
    if (t < lbl_80564548) {
        ease = lbl_80564548;
    } else if (t > lbl_80564560) {
        ease = lbl_80564560;
    } else if (t > lbl_8056456C) {
        v0 = lbl_80564570 * t;
        v1 = lbl_80564574 * t;
        v0 = v0 * t;
        v1 = v1 * t;
        v0 = t * v0;
        ease = v0 + v1;
    } else {
        v0 = lbl_80564570 * t;
        v1 = lbl_80564574 * t;
        v0 = v0 * t;
        v1 = v1 * t;
        v0 = t * v0;
        ease = v0 - v1;
    }

    if (flags & 1) {
        v0 = *(float *)(current + 4);
        v1 = *(float *)(next + 4);
        x = v0 + ease * (v1 - v0);
    } else x = *(float *)(current + 4);
    if (flags & 1) {
        v0 = *(float *)(current + 8);
        v1 = *(float *)(next + 8);
        y = v0 + ease * (v1 - v0);
    } else y = *(float *)(current + 8);
    if (flags & 1) {
        v0 = *(float *)(current + 0xC);
        v1 = *(float *)(next + 0xC);
        z = v0 + ease * (v1 - v0);
    } else z = *(float *)(current + 0xC);
    if (flags & 1) {
        v0 = *(float *)(current + 0x10);
        v1 = *(float *)(next + 0x10);
        w = v0 + ease * (v1 - v0);
    } else w = *(float *)(current + 0x10);

    if (flags & 2)
        packed = fn_80296A10(*(unsigned int *)(current + 0x14), *(unsigned int *)(next + 0x14), ease);
    else
        packed = *(unsigned int *)(current + 0x14);

    if (flags & 8) {
        v0 = *(float *)(current + 0x1C);
        v1 = *(float *)(next + 0x1C);
        h = v0 + ease * (v1 - v0);
    } else h = *(float *)(current + 0x1C);

    if (flags & 8) {
        v0 = *(float *)(current + 0x20);
        v1 = *(float *)(next + 0x20);
        v2 = *(float *)(current + 0x24);
        v3 = *(float *)(next + 0x24);
        v4 = *(float *)(current + 0x28);
        v5 = *(float *)(next + 0x28);
        d = v4 + ease * (v5 - v4);
        y = v2 + ease * (v3 - v2);
        x = v0 + ease * (v1 - v0);
    } else {
        vx = *(float *)(current + 0x20);
        vy = *(float *)(current + 0x24);
        vz = *(float *)(current + 0x28);
    }

    sp1c = vx + arg1[0];
    sp20 = vy + arg1[1];
    sp24 = vz + arg1[2];

    if (flags & 4) {
        alpha = (packed >> 24) & 0xFF;
        alpha2 = fn_802969B4(alpha, 0, ease) & 0xFF;
        rgb = packed & 0xFFFFFF;
        fn_802960A0(&sp1c, (alpha2 << 24) | rgb, *(int *)(selected + 0x18), h, x, y, z, w);
        alpha = (packed >> 24) & 0xFF;
        low = packed & 0xFFFFFF;
        fn_802960A0((float *)&x, (low | ((alpha - alpha2) << 24)),
            *(int *)(next + 0x18), h, x, y, z, w);
    } else {
        fn_802960A0((float *)&x, packed, *(int *)(selected + 0x18), h, x, y, z, w);
    }
    return 1;
}

#pragma push
#pragma cplusplus on
extern "C" float fn_802970C8(void *arg0) {
    int count = *(int *)((char *)arg0 + 0x2C);
    int processed = 0;
    int offset = 0;
    int rest;
    unsigned int groups;
    float sum = lbl_8056456C;

    if (count <= 0) return sum;
    rest = count - 8;
    if (rest > 0 && count <= 0x7FFFFFFE) {
        groups = ((unsigned int)rest + 7) >> 3;
        do {
            float *base = *(float * volatile *)((char *)arg0 + 0x24);
            float *record = (float *)((char *)base + offset);
            sum += *(float *)((char *)record + 0x00);
            sum += *(float *)((char *)record + 0x30);
            sum += *(float *)((char *)record + 0x60);
            sum += *(float *)((char *)record + 0x90);
            sum += *(float *)((char *)record + 0xC0);
            sum += *(float *)((char *)record + 0xF0);
            sum += *(float *)((char *)record + 0x120);
            sum += *(float *)((char *)record + 0x150);
            processed += 8;
            offset += 0x180;
        } while (--groups != 0);
    }
    if (processed < count) {
        float *base = *(float * volatile *)((char *)arg0 + 0x24);
        offset = processed * 0x30;
        rest = count - processed;
        do {
            sum += *(float *)((char *)base + offset);
            offset += 0x30;
        } while (--rest != 0);
    }
    return sum;
}
#pragma pop

#pragma scheduling on
#pragma pop
