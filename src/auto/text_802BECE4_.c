// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void *);
extern void fn_802BEDFC(void);
extern int fn_801E85AC(void);
extern int fn_802C00A4(void);
extern int fn_8012C33C(int);
extern int fn_802C6FC0(int, int, int);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034AD78[];
extern int lbl_8055CF68;
extern void fn_801E866C(int);
extern void *fn_801EA9A0(void);
extern float lbl_80564D80, lbl_80564D84, lbl_80564D88, lbl_80564D8C;
extern float lbl_80564D90, lbl_80564D94;
extern void fn_802CAC54(int);
extern char lbl_8034AE20[];
typedef unsigned int u32;
extern int sscanf(const char *, const char *, ...);
extern float lbl_8055FAF4;
extern float lbl_8055FAE0;
extern int lbl_8055FAE4, lbl_8055FAE8, lbl_8055FAEC, lbl_8055FAF0;
extern float lbl_80564D84;
extern char lbl_8034ACA0[];
#pragma small_data on
extern char lbl_8055CF80;
#pragma small_data off
extern void *fn_80131808(void *, int, int);
extern int fn_80131818(void *);
#pragma dont_inline fn_802BECE4
extern int fn_802BECE4(const char *, int);
extern float lbl_80564D7C;
extern float lbl_80564D80;
extern float PSVECMag(void *);
extern char lbl_8034ACC0[];
extern char lbl_8055CF78[];
extern unsigned char lbl_8055CF71;
extern int fn_801E85B4(void);
extern void fn_802BF160(void);
extern int fn_802C2C00(int);
extern void fn_802C6CF8();
extern void *lbl_804C07F0[];
extern unsigned char lbl_8055CF70;
extern int lbl_8055FADC;
extern int lbl_8055CF6C;
#pragma dont_inline on
int fn_802BECE4(const char *arg0, int arg1) {
    int d, c, b, a;
    int result = arg1;
    a = b = c = d = 0;
    if (sscanf(arg0, lbl_8034ACC0, &d, &c, &b, &a) == 4) {
        result = ((d & 0xff) << 24) | ((c & 0xff) << 16) |
                 ((b & 0xff) << 8) | (a & 0xff);
    } else {
        sscanf(arg0, lbl_8055CF78, &result);
    }
    return result;
}
void fn_802BED90(float *arg0) {
    float mag = PSVECMag(arg0);
    float scale;
    if (lbl_80564D7C > mag) mag = lbl_80564D7C;
    scale = lbl_80564D80 / mag;
    arg0[0] *= scale;
    arg0[1] *= scale;
    arg0[2] *= scale;
}

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802BEDFC(void) {
    class Resource {
    public:
        virtual void *getStyle(const char *);
        virtual void unused1();
        virtual int hasStyle(const char *);
        virtual void unused3();
        virtual const char *setProperty(const char *, const char *);
        virtual void unused5();
        virtual void unused6();
        virtual void unused7();
        virtual float setScale(const char *, float);
    };
    Resource *resource;
    char *strings = lbl_8034ACA0;
    Resource *style;
    lbl_8055FAE8 = 0xE0FFFFFF;
    lbl_8055FAE4 = 0xE0005030;
    lbl_8055FAEC = 0x202040;
    lbl_8055FAE0 = lbl_80564D84;
    lbl_8055FAF0 = 0xE0001040;
    resource = (Resource *)fn_80131808(strings + 0x2C, 0xE0FFFFFF, 0xE0000000);
    if (resource != 0) {
        if (resource->hasStyle(strings + 0x38) != 0)
            style = (Resource *)resource->getStyle(strings + 0x38);
        else
            style = 0;
        if (style != 0) {
            lbl_8055FAE0 = style->setScale(strings + 0x44, lbl_8055FAE0);
            lbl_8055FAE4 = fn_802BECE4(style->setProperty(strings + 0x54, (const char *)&lbl_8055CF80), lbl_8055FAE4);
            lbl_8055FAE8 = fn_802BECE4(style->setProperty(strings + 0x68, (const char *)&lbl_8055CF80), lbl_8055FAE8);
            lbl_8055FAEC = fn_802BECE4(style->setProperty(strings + 0x78, (const char *)&lbl_8055CF80), lbl_8055FAEC);
            lbl_8055FAF0 = fn_802BECE4(style->setProperty(strings + 0x90, (const char *)&lbl_8055CF80), lbl_8055FAF0);
            fn_802E30C8(strings + 0xA4, lbl_8055FAE4, lbl_8055FAE8, lbl_8055FAEC, lbl_8055FAF0);
        }
        fn_80131818(resource);
    }
    lbl_8055FAF4 = lbl_8055FAE0;
}
#pragma scheduling on
#pragma cplusplus reset

float fn_802BEFB4(void) {
    float value;
    float limit;
    float result;
    fn_801E866C(-1);
    value = (*(float *)((char *)*(void **)((char *)fn_801EA9A0() + 8) + 0x64) - lbl_80564D88) / lbl_80564D8C;
    limit = lbl_80564D80;
    result = limit < value ? value : limit;
    limit = result;
    limit = limit > lbl_80564D90 ? lbl_80564D90 : limit;
    result = limit * lbl_80564D94;
    return lbl_80564D84 + result;
}

extern u32 lbl_802FABA0[];
float fn_802BF02C(float arg0, int arg1) {
    struct Pair { float x, y; } points[7];
    register u32 *src = lbl_802FABA0;
    register u32 *dst = (u32 *)points;
    register struct Pair *p;
    register struct Pair *q;
    register int i;
    register float min, t;
    float highX, lowX, highY, numerator, lowY, denominator;

    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst = *src;
    p = points + 1;
    i = 1;

    for (; i <= 6; ++p, ++i) {
        if (p->x > arg0) {
            q = points;
            min = lbl_80564D80;
            highX = q[i].x;
            lowX = q[i - 1].x;
            highY = q[i].y;
            numerator = arg0 - lowX;
            lowY = q[i - 1].y;
            denominator = highX - lowX;
            t = numerator / denominator;
            if (t < min) t = min;
            if (t > lbl_80564D90) t = lbl_80564D90;
            return lowY + t * (highY - lowY);
        }
    }
    return points[6].y;
}

void fn_802BF350(void) {
    int i;
    fn_802BEDFC();
    lbl_8055FADC = fn_801E85AC();
    for (i = 0; i < lbl_8055FADC; i++) {
        lbl_804C07F0[i] = (void *)fn_802C00A4();
        if (i == 0 && lbl_804C07F0[i] != 0) {
            fn_802E30C8(lbl_8034AD78);
        }
    }
    if (fn_8012C33C(lbl_8055CF68) != 0) {
        lbl_8055CF6C = fn_802C6FC0(lbl_8055CF68, 0, 0);
    } else {
        lbl_8055CF6C = -1;
    }
}

void fn_802BF40C(void) {
    int i;
    void **obj;
    int handle;
    for (i = 0; i < lbl_8055FADC; i++) {
        obj = (void **)lbl_804C07F0[i];
        if (obj != 0) {
            if (obj != 0) {
                ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
            }
            lbl_804C07F0[i] = 0;
        }
    }
    handle = lbl_8055CF6C;
    lbl_8055FADC = 0;
    if (handle != -1) {
        fn_802C6CF8();
        lbl_8055CF6C = -1;
    }
}

int fn_802BF4B0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

int fn_802BF4F0(void) {
    return (int)(unsigned int)lbl_804C07F0 != 0;
}

void fn_802BF508(void) {
    int index = fn_801E85B4();
    int saved;
    if (lbl_804C07F0[index] != 0 && lbl_8055CF70 != 0) {
        saved = fn_802C2C00(0);
        ((void (*)(void *, int))(*(void ***)lbl_804C07F0[index])[4])(lbl_804C07F0[index], 0);
        fn_802C2C00(saved);
    }
    fn_802BF160();
}

float fn_802BF590(void) { return lbl_8055FAF4; }

#pragma cplusplus on
extern "C" void fn_802BF598(int arg0, float farg0) {
    class Dummy {
    public:
        virtual void f0();
        virtual void f1(int, float);
    };
    int index = fn_801E85B4();
    Dummy *obj = (Dummy *)lbl_804C07F0[index];
    if (obj != 0) {
        obj->f1(arg0, farg0);
    }
}

extern float lbl_80564DA8;
extern float lbl_80564DB0;
extern "C" void fn_802BF600(void *arg0, void *dst, void *src) {
    float v4 = *(float *)((char *)src + 4);
    float v10 = *(float *)((char *)src + 0x10);
    float v1c = *(float *)((char *)src + 0x1C);
    float v28 = *(float *)((char *)src + 0x28);
    float scale = lbl_80564DA8;
    int i0 = *(int *)((char *)src + 0);
    int i8 = *(int *)((char *)src + 8);
    int ic = *(int *)((char *)src + 0xC);
    int i14 = *(int *)((char *)src + 0x14);
    int i18 = *(int *)((char *)src + 0x18);
    int i20 = *(int *)((char *)src + 0x20);
    int i24 = *(int *)((char *)src + 0x24);
    int i2c = *(int *)((char *)src + 0x2C);
    *(float *)((char *)dst + 4) = v4;
    *(float *)((char *)dst + 0x10) = v10;
    *(float *)((char *)dst + 0x1C) = v1c;
    *(float *)((char *)dst + 0x28) = v28;
    *(int *)((char *)dst + 0) = i0;
    *(int *)((char *)dst + 8) = i8;
    *(int *)((char *)dst + 0xC) = ic;
    *(int *)((char *)dst + 0x14) = i14;
    *(int *)((char *)dst + 0x18) = i18;
    *(int *)((char *)dst + 0x20) = i20;
    *(int *)((char *)dst + 0x24) = i24;
    *(int *)((char *)dst + 0x2C) = i2c;
    *(float *)((char *)dst + 4) = v4 * scale;
    *(float *)((char *)dst + 0x10) = v10 * scale;
    *(float *)((char *)dst + 0x1C) = v1c * scale;
    *(float *)((char *)dst + 0x28) = v28 * scale;
    *(float *)((char *)dst + 0x28) += lbl_80564DB0 * lbl_8055FAE0;
}

extern "C" int fn_802BF6AC(void) {
    struct Dummy {
        virtual void f0(int);
        virtual int f1();
        virtual int f2();
        virtual int f3();
    };
    extern void *fn_801284F8(int, const char *);
    extern void *fn_802BF780(void);
    extern const char lbl_8034AD90[];
    register void *obj;
    obj = fn_801284F8(0x18, lbl_8034AD90);
    if (obj != 0) {
        obj = fn_802BF780();
        if (obj != 0) {
            if (((Dummy *)obj)->f3() == 0) {
                if (obj != 0)
                    ((Dummy *)obj)->f0(1);
                obj = 0;
            }
        }
    }
    return (int)obj;
}
#pragma scheduling on
#pragma cplusplus reset
extern void *fn_801284F8(int, const char*);
extern void* fn_802BF780(void);
extern const char lbl_8034AD90[];
extern void* lbl_804C07F0[];
extern float lbl_80564DA8, lbl_80564DB0, lbl_8055FAE0;
int fn_802BF740(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

extern void fn_802CB228(void *);
extern int lbl_8055FAFC;
extern void *lbl_8055FB00;
extern char lbl_8034AE40[];
#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void *fn_802BFA58(void *arg0, int arg1) {
    struct SharedTable {
        void *items[6];
        int val;
        void cleanup() {
            void **cur = items;
            int i = 0;
            do {
                fn_802CB228(*cur);
                cur++;
                i++;
            } while (i < 6);
            if (val != -2) {
                fn_802CAC54(val);
            }
            fn_80128668(this);
        }
    };
    int id;
    int c;

    if (arg0 != 0) {
        id = *(int *)((char *)arg0 + 8);
        *(char **)arg0 = lbl_8034AE40;
        if (id != -2) {
            fn_802CB228((void *)id);
            *(int *)((char *)arg0 + 8) = -2;
        }
        c = *(int *)((char *)arg0 + 0xC);
        if (c != -1) {
            fn_802C6CF8(c);
            *(int *)((char *)arg0 + 0xC) = -1;
        }
        c = *(int *)((char *)arg0 + 0x10);
        if (c != -1) {
            fn_802C6CF8(c);
            *(int *)((char *)arg0 + 0x10) = -1;
        }
        if (*(int *)((char *)arg0 + 4) != 0) {
            if (--lbl_8055FAFC == 0) {
                SharedTable *table = (SharedTable *)lbl_8055FB00;
                if (table != 0) {
                    table->cleanup();
                }
                lbl_8055FB00 = 0;
            }
            *(int *)((char *)arg0 + 4) = 0;
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma cplusplus reset
extern float lbl_80564DCC, lbl_80564DD0, lbl_80564DD4;
extern unsigned short lbl_802FAC20;
extern void fn_80015A20(void *, float *, float, float, float, float, float);
extern void fn_80015B20(float *, void *, float *);
extern void fn_802C8B98(int, float *);
extern void fn_802C8DB8(void *, int, unsigned short *, int);
extern void fn_802C8D74(void);
void fn_802BFE48(void *arg0, void *arg1, float arg2) {
    struct V { float x,y,z; int pad; float nx,ny,nz; int pad2; } v[4];
    float mat[16];
    float point[4];
    float *p;
    float x, y, z;
    int i;
    unsigned short *indices = &lbl_802FAC20;
    if (*(int *)((char *)arg0 + 0x18) == -2) return;
    x = lbl_80564DCC * arg2;
    y = lbl_80564DD0 * arg2;
    for (i = 0; i < 4; i++) {
        v[i].x = (i & 1) ? x : -x;
        v[i].y = (i & 2) ? x : -x;
        v[i].z = y;
        v[i].pad = -1;
        v[i].nx = (i & 1) ? lbl_80564D80 : lbl_80564D90;
        v[i].ny = (i & 2) ? lbl_80564D80 : lbl_80564D90;
        v[i].nz = lbl_80564D90;
        v[i].pad2 = -1;
    }
    p = mat + 8;
    p[0]=lbl_80564D80; p[1]=lbl_80564D90; p[2]=lbl_80564D90; p[3]=lbl_80564D90;
    p[4]=lbl_80564D80; p[5]=lbl_80564D90; p[6]=lbl_80564D90; p[7]=lbl_80564D90;
    p[8]=lbl_80564D80;
    point[0]=lbl_80564DD4; point[1]=lbl_80564D90; point[2]=lbl_80564D90;
    fn_80015A20(point, mat + 2, lbl_80564D90, lbl_80564D80,
                ((float *)arg1)[11], ((float *)arg1)[10], ((float *)arg1)[9]);
    fn_80015B20(mat + 8, point, mat + 8);
    fn_802C8B98(*(int *)((char *)arg0 + 0x18), mat + 8);
    fn_802C8DB8(v, 4, indices, 6);
    fn_802C8D74();
}

void fn_802C0054(void *dst, const void *src) {
    struct Copy {
        u32 words[9];
    };
    *(struct Copy *)dst = *(const struct Copy *)src;
}

void fn_802C00A0(void) {
}

extern void *fn_801284F8(int, const char *);
extern void *fn_802C0138(void);
extern char lbl_8034ADC8[];
int fn_802C00A4(void) {
    extern void *fn_801284F8(int, const char *);
    extern void *fn_802C0138(void);
    extern char lbl_8034ADC8[];
    void *obj;
    obj = fn_801284F8(0x2c60, lbl_8034ADC8);
    if (obj == 0)
        return 0;
    obj = fn_802C0138();
    if (obj != 0) {
        if (((int (*)(void *))(*(void ***)obj)[5])(obj) == 0) {
            if (obj != 0)
                ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
            obj = 0;
        }
    }
    return (int)obj;
}

extern char lbl_8034AE08[];
#pragma cplusplus on
extern "C" void *fn_802C0310(void *arg0, int arg1) {
    class Obj {
    public:
        virtual void v0(int);
    };
    int id;
    void *obj;
    if (arg0 != 0) {
        id = *(int *)((char *)arg0 + 0x2c50);
        *(void **)arg0 = lbl_8034AE08;
        if (id != -2) fn_802CAC54(id);
        id = *(int *)((char *)arg0 + 0x2c54);
        if (id != -2) fn_802CAC54(id);
        obj = *(void **)((char *)arg0 + 0x2c58);
        if (obj != 0) {
            if (obj != 0)
                ((Obj *)obj)->v0(1);
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma cplusplus off
void fn_802C03B4(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 0x2c58);
    void (*fn)(void *);
    if (obj == 0) return;
    if (lbl_8055CF71 == 0) return;
    fn = (void (*)(void *))(*(void ***)obj)[3];
    fn(obj);
}

int fn_802C03E0(u32 arg0) {
    register u32 a = (arg0 & 0xFFFF) << 8;
    register u32 b = (arg0 << 8) & 0xFF0000FF;
    return a | b;
}

int fn_802C0C98(void *arg0) { return *(int *)((char *)arg0 + 8); }

float fn_802C0CA0(void *arg0) { return *(float *)((char *)arg0 + 0x14); }

int fn_802C0CA8(void) { return 1; }

void *fn_802C0CB0(void *arg0, int arg1) {
    int temp_r0;

    if (arg0 != 0) {
        temp_r0 = *(int *)((char *)arg0 + 4);
        *(char **)arg0 = lbl_8034AE20;
        if (temp_r0 != -2) {
            fn_802CAC54(temp_r0);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_802C0D20(void) {
}

int fn_802C0D24(void *arg0) {
    return *(int *)((char *)arg0 + 4);
}

float fn_802C0D2C(void) {
    return lbl_80564D80;
}

unsigned int fn_802C0D34(void) {
    return 1;
}

unsigned char fn_802C0D3C(void *arg0) {
    return *((unsigned char *)arg0 + 0x2C5C);
}

extern int fn_801E85AC(void);
extern int fn_802C00A4(void);
extern int fn_8012C33C(int);
extern int fn_802C6FC0(int, int, int);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034AD78[];
extern int lbl_8055CF68;
extern void fn_801E866C(int);
extern void *fn_801EA9A0(void);
extern float lbl_80564D80, lbl_80564D84, lbl_80564D88, lbl_80564D8C;
extern float lbl_80564D90, lbl_80564D94;
