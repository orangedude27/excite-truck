// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { double a, b, c, d, e, f, g, h; } Key64;
typedef struct CacheEntry { void *obj; unsigned char name[0x40]; int ref; } CacheEntry;
extern int strcmp(const char *, const char *);
extern void *fn_80131810(const char *);
extern void fn_80131818(void *);
extern void *fn_8013184C(void);
extern void fn_802E30C8(const char *, ...);
extern const char lbl_8032C42C[];
extern const char lbl_8032C43C[];
#pragma cplusplus on
class CacheSrc {
public:
    virtual void *open(const char *);
    virtual void v1();
    virtual int has(const char *);
};
#pragma cplusplus reset
struct CacheVt;
typedef struct CacheObj { struct CacheVt *vt; } CacheObj;
struct CacheVt { void *pad[2]; void *(*m2)(CacheObj *, char *); void *pad3; int (*m4)(CacheObj *, char *); };
extern unsigned char lbl_8042F8C8[];
extern char *strchr(const char *, int);
extern char *fn_80029004(char *, int);
extern void *fn_801284F8(int, const char *);
extern void fn_8013A264(void *);
extern void fn_8013BF3C(void);
extern const char lbl_8032C414[];
char *fn_8013BC90(char *arg0, int arg1, const char *arg2) {
    char *base=arg0, *dst=arg0;
    const char *src=arg2;
    int n=arg1;
    char c;
    while (--n > 0) {
        c=*src++;
        *dst++=c;
        if (!c) goto copied;
    }
    dst[-1]=0;
copied:
    if (strchr(base, '/') != 0) base=strchr(base, '/')+1;
    { char *p=fn_80029004(base,'.'); if(p) *p=0; }
    return base;
}

extern float lbl_80561480;
extern float lbl_80561484;
extern float lbl_80561488;
extern float lbl_8056148C;
extern float lbl_80561490;
#pragma dont_inline on
void fn_8013BD30(void *arg0) {
    float e, d, c, b, a;
    float *p = (float *)arg0;
    a = lbl_80561480;
    b = lbl_80561484;
    c = lbl_80561488;
    d = lbl_8056148C;
    e = lbl_80561490;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[4] = d;
    p[3] = e;
}
#pragma dont_inline reset

extern void fn_8013BD30(void *);
extern char lbl_8032C3D8[];
__declspec(section ".sdata") extern const char lbl_80559CE0[];
__declspec(section ".sdata") extern const char lbl_80559CE8[];
__declspec(section ".sdata") extern const char lbl_80559CF0[];
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_8013BD5C(void *arg0, void *arg1) {
    class Selector {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20();
        virtual void *select(const char *);
    };
    class Getter {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual float get(const char *, float);
    };
    float *v = (float *)arg0;
    const char *names = lbl_8032C3D8;
    void *p;

    fn_8013BD30(arg0);
    p = ((Selector *)arg1)->select(names);
    if (p != 0) {
        v[0] = ((Getter *)p)->get(lbl_80559CE0, v[0]);
        v[1] = ((Getter *)p)->get(lbl_80559CE8, v[1]);
        v[2] = ((Getter *)p)->get(names + 0xC, v[2]);
        v[4] = ((Getter *)p)->get(names + 0x18, v[4]);
        v[3] = ((Getter *)p)->get(lbl_80559CF0, v[3]);
    }
}
#pragma scheduling on
#pragma cplusplus reset
extern void fn_8013A2FC(void *, int);
extern void fn_8013BD5C(void *, void *);
extern const char lbl_8032C420[];
void *fn_8013BE64(void *arg0, const char *arg1) {
    void *p;
    char *dst;
    const char *src;
    int n;
    char c;
    p = fn_801284F8(0x78, lbl_8032C414);
    if (p != 0) fn_8013A264((char *)p + 0x40);
    dst = (char *)p;
    src = arg1;
    n = 0x40;
    while (--n > 0) {
        c = *src++;
        *dst++ = c;
        if (!c) goto copied;
    }
    dst[-1] = 0;
copied:
    fn_8013A2FC((char *)p + 0x40, (*(int (**)(void *, const char *))((char *)*(void **)arg0 + 0x5c))(arg0, lbl_8032C420));
    fn_8013BD5C((char *)p + 0x60, arg0);
    *(int *)((char *)p + 0x74) = 0;
    return p;
}

void fn_8013BF3C(void) {
    ((void (*)(void))fn_8013BD30)();
}

#pragma scheduling invalid_target
void *fn_8013BF40(char *arg0) {
    void *p = fn_801284F8(0x78, lbl_8032C414);
    int count;
    char *dst;
    unsigned char c;
    if (p != 0)
        fn_8013A264((char *)p + 0x40);
    dst = (char *)p;
    count = 0x40;
    goto copy;
count_check:
    if (--count > 0)
        goto copy;
    dst[-1] = 0;
    goto copied;
copy:
    c = (unsigned char)*arg0++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto count_check;
copied:
    ((void (*)(void *))fn_8013BF3C)((char *)p + 0x60);
    *(volatile int *)((char *)p + 0x74) = 0;
    return p;
}
#pragma scheduling on
void fn_8013BFE0(void) {

}

void fn_8013BFE4(void) {

}

extern int strcmp(const char *, const char *);
extern void *fn_80131810(const char *);
extern void fn_80131818(void *);
extern void *fn_8013184C(void);
extern void fn_802E30C8(const char *, ...);
extern const char lbl_8032C42C[];
extern const char lbl_8032C43C[];
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_8013BFE8(char *arg0) {
    Key64 key;
    char buf[0x80];
    unsigned char *e;
    int i, count;
    unsigned char *p;
    CacheSrc *obj;
    char *name;
    void *res, *h;
    int n;
    char *dst;
    unsigned char c;
    dst = (char *)&key;
    n = 0x40;
    goto copy;
count_check:
    if (--n > 0)
        goto copy;
    dst[-1] = 0;
    goto copied;
copy:
    c = (unsigned char)*arg0++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto count_check;
copied:
    e = 0;
    p = lbl_8042F8C8;
    count = *(int *)(lbl_8042F8C8 + 0x240);
    i = 0;
    for (; i < count; i++) {
        int eq = strcmp((char *)&key, (char *)p + 4) == 0;
        if (eq) {
            e = lbl_8042F8C8 + i * 0x48;
            break;
        }
        p += 0x48;
    }
    if (e == 0) {
        res = 0;
        obj = (CacheSrc *)fn_80131810(lbl_8032C42C);
        if (obj != 0) {
            name = fn_8013BC90(buf, 0x80, (char *)&key);
            if (obj->has(name))
                h = obj->open(name);
            else
                h = 0;
            if (h != 0) fn_802E30C8(lbl_8032C43C, name);
            else h = fn_8013184C();
            res = fn_8013BE64(h, (char *)&key);
            fn_80131818(obj);
        }
        if (res == 0) res = fn_8013BF40((char *)&key);
        if (res != 0) {
            ((void (*)(void *))fn_8013BFE0)(res);
            ((void (*)(void *))fn_8013BFE4)(res);
        }
        if (res != 0) {
            Key64 tmp;
            unsigned char *s = (unsigned char *)&tmp;
            unsigned char *t = lbl_8042F8C8;
            int idx;
            tmp.a = key.a; tmp.b = key.b; tmp.c = key.c; tmp.d = key.d;
            tmp.e = key.e; tmp.f = key.f; tmp.g = key.g; tmp.h = key.h;
            idx = *(int *)(t + 0x240);
            *(int *)(t + 0x240) = idx + 1;
            e = t + idx * 0x48;
            *(void **)e = res;
            { unsigned char a = s[0]; unsigned char b = s[1]; e[4] = a; e[5] = b; }
            { unsigned char a = s[2]; unsigned char b = s[3]; e[6] = a; e[7] = b; }
            { unsigned char a = s[4]; unsigned char b = s[5]; e[8] = a; e[9] = b; }
            { unsigned char a = s[6]; unsigned char b = s[7]; e[10] = a; e[11] = b; }
            { unsigned char a = s[8]; unsigned char b = s[9]; e[12] = a; e[13] = b; }
            { unsigned char a = s[10]; unsigned char b = s[11]; e[14] = a; e[15] = b; }
            { unsigned char a = s[12]; unsigned char b = s[13]; e[16] = a; e[17] = b; }
            { unsigned char a = s[14]; unsigned char b = s[15]; e[18] = a; e[19] = b; }
            { unsigned char a = s[16]; unsigned char b = s[17]; e[20] = a; e[21] = b; }
            { unsigned char a = s[18]; unsigned char b = s[19]; e[22] = a; e[23] = b; }
            { unsigned char a = s[20]; unsigned char b = s[21]; e[24] = a; e[25] = b; }
            { unsigned char a = s[22]; unsigned char b = s[23]; e[26] = a; e[27] = b; }
            { unsigned char a = s[24]; unsigned char b = s[25]; e[28] = a; e[29] = b; }
            { unsigned char a = s[26]; unsigned char b = s[27]; e[30] = a; e[31] = b; }
            { unsigned char a = s[28]; unsigned char b = s[29]; e[32] = a; e[33] = b; }
            { unsigned char a = s[30]; unsigned char b = s[31]; e[34] = a; e[35] = b; }
            { unsigned char a = s[32]; unsigned char b = s[33]; e[36] = a; e[37] = b; }
            { unsigned char a = s[34]; unsigned char b = s[35]; e[38] = a; e[39] = b; }
            { unsigned char a = s[36]; unsigned char b = s[37]; e[40] = a; e[41] = b; }
            { unsigned char a = s[38]; unsigned char b = s[39]; e[42] = a; e[43] = b; }
            { unsigned char a = s[40]; unsigned char b = s[41]; e[44] = a; e[45] = b; }
            { unsigned char a = s[42]; unsigned char b = s[43]; e[46] = a; e[47] = b; }
            { unsigned char a = s[44]; unsigned char b = s[45]; e[48] = a; e[49] = b; }
            { unsigned char a = s[46]; unsigned char b = s[47]; e[50] = a; e[51] = b; }
            { unsigned char a = s[48]; unsigned char b = s[49]; e[52] = a; e[53] = b; }
            { unsigned char a = s[50]; unsigned char b = s[51]; e[54] = a; e[55] = b; }
            { unsigned char a = s[52]; unsigned char b = s[53]; e[56] = a; e[57] = b; }
            { unsigned char a = s[54]; unsigned char b = s[55]; e[58] = a; e[59] = b; }
            { unsigned char a = s[56]; unsigned char b = s[57]; e[60] = a; e[61] = b; }
            { unsigned char a = s[58]; unsigned char b = s[59]; e[62] = a; e[63] = b; }
            { unsigned char a = s[60]; unsigned char b = s[61]; e[64] = a; e[65] = b; }
            { unsigned char a = s[62]; unsigned char b = s[63]; e[66] = a; e[67] = b; }
            *(int *)(e + 0x44) = 0;
        }
    }
    if (e != 0) {
        *(int *)(e + 0x44) = *(int *)(e + 0x44) + 1;
        return *(void **)e;
    }
    return 0;
}
#pragma scheduling on
#pragma cplusplus reset
extern void fn_80128658(int);
extern void fn_80128668(void *);
extern void fn_8013A598(void *, int);
extern unsigned char lbl_8042F8C8[];

// The resource cache: CACHE_ENTRY_MAX entries with the number in use right
// behind them. fn_8013BFE8 files a resource under its name here and fn_8013C428
// takes it back out; an entry lives until its reference count reaches zero.
#define CACHE_ENTRY_MAX 8
typedef struct CacheTable {
    CacheEntry entry[CACHE_ENTRY_MAX];
    int count; // at 0x240
} CacheTable;

// A cached resource, as fn_8013BF40 builds it.
typedef struct CacheResource {
    unsigned char name[0x40];   // at 0x00: the name the entry is filed under
    unsigned char blocks[0x20]; // at 0x40: loaded blocks, freed by fn_8013A598
    unsigned char unk60[0x14];  // at 0x60: set up by fn_8013BF3C
    int buffer;                 // at 0x74: buffer released with the resource
} CacheResource;

// The game's compiler copies an entry's 64-byte name two bytes at a time, one
// register per byte, both loaded before either is stored. Written out that way
// so the entry copy below comes out byte for byte.
#define CACHE_COPY2(dst, src, n)                                               \
    {                                                                          \
        unsigned char a = (src)->name[n];                                      \
        unsigned char b = (src)->name[(n) + 1];                                \
        (dst)->name[n] = a;                                                    \
        (dst)->name[(n) + 1] = b;                                              \
    }
#define CACHE_COPY_NAME(dst, src)                                              \
    CACHE_COPY2(dst, src, 0) CACHE_COPY2(dst, src, 2)                          \
    CACHE_COPY2(dst, src, 4) CACHE_COPY2(dst, src, 6)                          \
    CACHE_COPY2(dst, src, 8) CACHE_COPY2(dst, src, 10)                         \
    CACHE_COPY2(dst, src, 12) CACHE_COPY2(dst, src, 14)                        \
    CACHE_COPY2(dst, src, 16) CACHE_COPY2(dst, src, 18)                        \
    CACHE_COPY2(dst, src, 20) CACHE_COPY2(dst, src, 22)                        \
    CACHE_COPY2(dst, src, 24) CACHE_COPY2(dst, src, 26)                        \
    CACHE_COPY2(dst, src, 28) CACHE_COPY2(dst, src, 30)                        \
    CACHE_COPY2(dst, src, 32) CACHE_COPY2(dst, src, 34)                        \
    CACHE_COPY2(dst, src, 36) CACHE_COPY2(dst, src, 38)                        \
    CACHE_COPY2(dst, src, 40) CACHE_COPY2(dst, src, 42)                        \
    CACHE_COPY2(dst, src, 44) CACHE_COPY2(dst, src, 46)                        \
    CACHE_COPY2(dst, src, 48) CACHE_COPY2(dst, src, 50)                        \
    CACHE_COPY2(dst, src, 52) CACHE_COPY2(dst, src, 54)                        \
    CACHE_COPY2(dst, src, 56) CACHE_COPY2(dst, src, 58)                        \
    CACHE_COPY2(dst, src, 60) CACHE_COPY2(dst, src, 62)
#pragma scheduling invalid_target
void fn_8013C428(void *arg0) {
    int i;
    int count;
    unsigned char *r5 = lbl_8042F8C8;
    i = 0;
    count = *(int *)(lbl_8042F8C8 + 0x240);
    for (; count > 0; --count) {
            if (*(void **)r5 == arg0) {
                int offset = i * 0x48;
                unsigned char *entry = lbl_8042F8C8 + offset;
                int ref = *(int *)(entry + 0x44) - 1;
                *(int *)(entry + 0x44) = ref;
                if (ref == 0) {
                    int n;
                    int tail;
                    unsigned char *dst;
                    volatile unsigned char *src;
                    if (*(int *)((char *)arg0 + 0x74) != 0) ((void (*)(int))fn_80128658)(*(int *)((char *)arg0 + 0x74));
                    if (arg0 != 0) {
                        fn_8013A598((char *)arg0 + 0x40, -1);
                        fn_80128668(arg0);
                    }
                    n = *(int *)(lbl_8042F8C8 + 0x240) - 1;
                    *(int *)(lbl_8042F8C8 + 0x240) = n;
                    tail = n * 0x48;
                    dst = lbl_8042F8C8 + (unsigned int)offset;
                    src = lbl_8042F8C8 + tail;
                    *(int *)dst = *(int *)(void *)src;
                    { unsigned char a = src[4]; unsigned char b = src[5]; dst[4] = a; dst[5] = b; }
                    { unsigned char a = src[6]; unsigned char b = src[7]; dst[6] = a; dst[7] = b; }
                    { unsigned char a = src[8]; unsigned char b = src[9]; dst[8] = a; dst[9] = b; }
                    { unsigned char a = src[10]; unsigned char b = src[11]; dst[10] = a; dst[11] = b; }
                    { unsigned char a = src[12]; unsigned char b = src[13]; dst[12] = a; dst[13] = b; }
                    { unsigned char a = src[14]; unsigned char b = src[15]; dst[14] = a; dst[15] = b; }
                    { unsigned char a = src[16]; unsigned char b = src[17]; dst[16] = a; dst[17] = b; }
                    { unsigned char a = src[18]; unsigned char b = src[19]; dst[18] = a; dst[19] = b; }
                    { unsigned char a = src[20]; unsigned char b = src[21]; dst[20] = a; dst[21] = b; }
                    { unsigned char a = src[22]; unsigned char b = src[23]; dst[22] = a; dst[23] = b; }
                    { unsigned char a = src[24]; unsigned char b = src[25]; dst[24] = a; dst[25] = b; }
                    { unsigned char a = src[26]; unsigned char b = src[27]; dst[26] = a; dst[27] = b; }
                    { unsigned char a = src[28]; unsigned char b = src[29]; dst[28] = a; dst[29] = b; }
                    { unsigned char a = src[30]; unsigned char b = src[31]; dst[30] = a; dst[31] = b; }
                    { unsigned char a = src[32]; unsigned char b = src[33]; dst[32] = a; dst[33] = b; }
                    { unsigned char a = src[34]; unsigned char b = src[35]; dst[34] = a; dst[35] = b; }
                    { unsigned char a = src[36]; unsigned char b = src[37]; dst[36] = a; dst[37] = b; }
                    { unsigned char a = src[38]; unsigned char b = src[39]; dst[38] = a; dst[39] = b; }
                    { unsigned char a = src[40]; unsigned char b = src[41]; dst[40] = a; dst[41] = b; }
                    { unsigned char a = src[42]; unsigned char b = src[43]; dst[42] = a; dst[43] = b; }
                    { unsigned char a = src[44]; unsigned char b = src[45]; dst[44] = a; dst[45] = b; }
                    { unsigned char a = src[46]; unsigned char b = src[47]; dst[46] = a; dst[47] = b; }
                    { unsigned char a = src[48]; unsigned char b = src[49]; dst[48] = a; dst[49] = b; }
                    { unsigned char a = src[50]; unsigned char b = src[51]; dst[50] = a; dst[51] = b; }
                    { unsigned char a = src[52]; unsigned char b = src[53]; dst[52] = a; dst[53] = b; }
                    { unsigned char a = src[54]; unsigned char b = src[55]; dst[54] = a; dst[55] = b; }
                    { unsigned char a = src[56]; unsigned char b = src[57]; dst[56] = a; dst[57] = b; }
                    { unsigned char a = src[58]; unsigned char b = src[59]; dst[58] = a; dst[59] = b; }
                    { unsigned char a = src[60]; unsigned char b = src[61]; dst[60] = a; dst[61] = b; }
                    { unsigned char a = src[62]; unsigned char b = src[63]; dst[62] = a; dst[63] = b; }
                    { unsigned char a = src[64]; unsigned char b = src[65]; dst[64] = a; dst[65] = b; }
                    { unsigned char a = src[66]; unsigned char b = src[67]; dst[66] = a; dst[67] = b; }
                    *(int *)(entry + 0x44) = *(int *)(void *)(src + 0x44);
                }
                break;
            }
            r5 += 0x48;
            i++;
    }
}
#pragma scheduling on
