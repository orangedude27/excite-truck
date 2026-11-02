// Code of main that had no source file yet: decomp.wtf gave it this one.
#pragma ppc_psq_save off
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern const char lbl_80340808[];
extern const char lbl_80340834[];
extern float lbl_805636B8;
extern int fn_8012C33C(const char *);
extern int fn_802CAC28(const char *, int);
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void *);
static inline void CopyStr_8023512C(char *dst, const char *src, int n) {
    char c;
    for (;;) {
        c = *src++;
        *dst++ = c;
        if (c != 0) {
            if (--n > 0) continue;
            dst[-1] = 0;
        }
        break;
    }
}
static inline void CatStr_8023512C(char *dst, const char *src, int n) {
    while (*dst != 0) { n--; dst++; }
    if (n > 0) CopyStr_8023512C(dst, src, n);
}
extern void *fn_801284F8(int, const char *);
extern void fn_802E317C(const char *, ...);
extern unsigned char lbl_80340670[];
extern unsigned char lbl_80340680[];
extern void *lbl_8055F084;
void *fn_80234C94(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void *fn_80234CEC(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_80234D44(int arg0) {
    int *node;
    if (arg0 != 0) {
        node = (int *)lbl_8055F084;
        if (node == 0) {
            node = fn_801284F8(8, (const char *)lbl_80340670);
            lbl_8055F084 = node;
            *node = arg0;
            node = (int *)lbl_8055F084;
            node[1] = 0;
        } else {
            while (node[1] != 0)
                node = (int *)node[1];
            node[1] = (int)fn_801284F8(8, (const char *)lbl_80340670);
            node = (int *)node[1];
            node[0] = arg0;
            node[1] = 0;
        }
    }
}

void fn_80234DE4(unsigned int arg0) {
    unsigned int *node;
    unsigned int *prev;
    node = (unsigned int *)lbl_8055F084;
    prev = 0;
    while (*node != arg0) {
        if (node == 0)
            fn_802E317C((const char *)lbl_80340680, arg0);
        prev = node;
        node = (unsigned int *)node[1];
    }
    if (prev == 0)
        lbl_8055F084 = (void *)node[1];
    else
        prev[1] = node[1];
    node[1] = 0;
    node[0] = 0;
    fn_80128668(node);
}

void *fn_80234E88(const char *arg0) {
    void *node = lbl_8055F084;
    goto loop;
loop:
    node = *(void **)((char *)node + 4);
    if (node != 0 && stricmp(arg0, *(const char **)node) != 0)
        goto loop;
    if (node == 0)
        return 0;
    return *(void **)node;
}

extern double atof(const char *);
extern void *fn_8012F150(const char *);
extern int fn_8012F2E4(void *);
extern int fn_8012F2E8(void);
extern char *fn_8012F2F0(void *, int, int);
extern char lbl_8055B9E0[5];
extern unsigned char lbl_803406B0[];
extern void fn_80265940(void);
#pragma scheduling invalid_target
void fn_80234EF4(void *arg0, const char *arg1) {
    if (fn_8012C33C(arg1)) {
        void *source = fn_8012F150(arg1);
        int count = fn_8012F2E8();
        void *last = 0;
        int i;
        for (i = 0; i < count; i++) {
            void *item = fn_801284F8(0x1c, lbl_8055B9E0);
            *(float *)item = (float)atof(fn_8012F2F0(source, i, 0));
            *(float *)((char *)item + 4) = (float)atof(fn_8012F2F0(source, i, 1));
            *(float *)((char *)item + 8) = (float)atof(fn_8012F2F0(source, i, 2));
            *(float *)((char *)item + 0xc) = (float)atof(fn_8012F2F0(source, i, 3));
            *(float *)((char *)item + 0x14) = (float)atof(fn_8012F2F0(source, i, 4));
            *(float *)((char *)item + 0x10) = (float)atof(fn_8012F2F0(source, i, 5));
            if (!last) *(void **)((char *)arg0 + 0x88) = item;
            else *(void **)((char *)last + 0x18) = item;
            last = item;
        }
        fn_8012F2E4(source);
        *(void **)((char *)last + 0x18) = 0;
    } else {
        fn_802E317C((const char *)lbl_803406B0, arg1);
    }
}
#pragma scheduling on
#pragma dont_inline on
void *fn_8023505C(void *arg0, int arg1) {
    void *node;
    int i;
    if (arg1 == 0)
        return *(void **)((char *)arg0 + 0x88);
    node = *(void **)((char *)arg0 + 0x88);
    i = 0;
    do {
        if (i == arg1)
            return node;
        node = *(void **)((char *)node + 0x18);
        i += 1;
        if (node == 0)
            break;
    } while (i <= arg1);
    return node;
}
#pragma dont_inline reset

extern const char lbl_803406FC[];
extern const char lbl_80340724[];
extern const char lbl_80340760[];
extern int stricmp(const char *, const char *);
extern void fn_802E30C8(const char *, ...);
extern void fn_80235380(void *);
#pragma scheduling invalid_target
void fn_8023509C(void) {
    if (lbl_8055F084 != 0)
        fn_802E317C(lbl_803406FC);
}
#pragma scheduling on
void fn_802350BC(void) {
    if (lbl_8055F084 != 0)
        fn_802E30C8(lbl_80340724);
    while (lbl_8055F084 != 0) {
        fn_802E30C8(lbl_80340760, *(unsigned int *)lbl_8055F084);
        fn_80235380(*(void **)lbl_8055F084);
    }
}

extern char lbl_8055B9E8[4];
extern char lbl_8055B9F0[4];
extern char *fn_80029004(char *, int);
void *fn_8023512C(const char *arg0) {
    char full[0x80];
    char name[0x80];
    int *obj;
    char *dot;
    CopyStr_8023512C(full, arg0, 0x80);
    if (fn_8012C33C(arg0) == 0) {
        fn_802E30C8((char *)lbl_80340670 + 0x120, arg0);
        CopyStr_8023512C(full, (char *)lbl_80340670 + 0x140, 0x80);
    }
    obj = fn_80234E88(full);
    if (obj != 0) {
        obj[0x80 / 4] += 1;
        return obj;
    }
    obj = fn_801284F8(0x8C, lbl_8055B9E8);
    obj[0x84 / 4] = fn_802CAC28(full, 0);
    if (obj[0x84 / 4] == -1)
        fn_802E317C((char *)lbl_80340670 + 0x14C, full);
    obj[0x80 / 4] = 1;
    obj[0x88 / 4] = 0;
    CopyStr_8023512C((char *)obj, full, 0x80);
    CopyStr_8023512C(name, full, 0x80);
    dot = fn_80029004(name, 0x2E);
    if (dot != 0)
        *dot = 0;
    else
        fn_802E317C((char *)lbl_80340670 + 0x168, name);
    CatStr_8023512C(name, lbl_8055B9F0, 0x80);
    fn_80234EF4(obj, name);
    fn_80234D44((int)obj);
    return obj;
}

void fn_80235380(void *arg0) {
    int count;
    void *node;
    void *next;

    count = *(int *)((char *)arg0 + 0x80) - 1;
    *(int *)((char *)arg0 + 0x80) = count;
    if (count <= 0) {
        node = *(void **)((char *)arg0 + 0x88);
        while (node != 0) {
            next = *(void **)((char *)node + 0x18);
            fn_80128668(node);
            node = next;
        }
        fn_802CAC54(*(int *)((char *)arg0 + 0x84));
        fn_80234DE4((unsigned int)arg0);
        fn_80128668(arg0);
    }
}

extern void fn_802C8DB8(void *, int, unsigned short *, int);
extern void fn_802C8D74(void);
#pragma paired off
#pragma paired_single off
void fn_802353F4(int arg0, int arg1, float arg2, float arg3, float arg4) {
    void *node;
    if (arg1 < 0) return;
    node = ((void *(*)(void *, int))fn_8023505C)((void *)arg0, arg1);
    if (node == 0) {
        fn_802E30C8(lbl_80340808, arg1, arg0);
        return;
    }
    fn_802354A0(arg0, arg1, -1, arg2, arg3, arg4,
                *(float *)((char *)node + 0x14),
                *(float *)((char *)node + 0x10));
}

extern double cos(float);
extern double sin(float);
extern void fn_80231380(void *, int, float, float, float, float, float);
extern void fn_802C8B98(int, int);
extern float lbl_805636B0;
extern float lbl_805636B4;
extern unsigned short lbl_802FA014[];
#pragma paired_single off
void fn_80235AFC(void *arg0, int arg1, int arg2,
                 float x, float y, float z,
                 float width, float height, float angle) {
    struct Frame {
        unsigned short indices[6];
        unsigned char pad1[4];
        float matrix[12];
        float vertices[4][6];
    } __attribute__((aligned(16))) frame;
    void *node;
    float *matrix;
    unsigned short *p;
    register int render;
    float c;
    float s;
    float zero;
    float w;
    float h;

    matrix = frame.matrix;
    matrix[9] = x;
    matrix[10] = y;
    matrix[11] = z;
    c = (float)cos(angle);
    s = (float)sin(angle);
    zero = lbl_805636B8;
    matrix[0] = c;
    matrix[1] = s;
    matrix[2] = zero;
    matrix[3] = -s;
    matrix[4] = c;
    matrix[5] = zero;
    matrix[6] = zero;
    matrix[7] = zero;
    matrix[8] = lbl_805636B0;

    node = ((void *(*)(void *, int))fn_8023505C)(arg0, arg1);
    w = width * lbl_805636B4;
    h = height * lbl_805636B4;
    fn_80231380(frame.vertices[0], arg2, -w, h, zero,
                *(float *)node, *((float *)node + 1));
    fn_80231380(frame.vertices[1], arg2, w, h, zero,
                *((float *)node + 2), *((float *)node + 1));
    fn_80231380(frame.vertices[2], arg2, -w, -h, zero,
                *(float *)node, *((float *)node + 3));
    fn_80231380(frame.vertices[3], arg2, w, -h, zero,
                *((float *)node + 2), *((float *)node + 3));

    render = *(volatile int *)((char *)arg0 + 0x84);
    p = lbl_802FA014;
    frame.indices[0] = *p++;
    frame.indices[1] = *p++;
    frame.indices[2] = *p++;
    frame.indices[3] = *p++;
    frame.indices[4] = *p++;
    frame.indices[5] = *p++;
    fn_802C8B98(render, (int)matrix);
    fn_802C8DB8(frame.vertices, 4, frame.indices, 6);
    fn_802C8D74();
}
typedef struct Vtx_80235CBC { double a; int b, c; float d, e; } Vtx_80235CBC;
typedef struct Idx_80235CBC { unsigned short i[6]; } Idx_80235CBC;
extern Vtx_80235CBC fn_80230A68(int, float, float, float, float, float);
extern int fn_80230B9C(int);
extern void fn_802C8C04(int);
extern Idx_80235CBC lbl_802FA020;
#pragma push
#pragma paired_single off
void fn_80235CBC(void *arg0, int arg1, int arg2, float x, float y, float z, float dx, float dy) {
    void *node;
    int index;
    float n0, n1, n2, n3;
    Vtx_80235CBC t0, t1, t2, t3;
    struct Frame {
        Idx_80235CBC ids;
        unsigned char pad[4];
        Vtx_80235CBC v[4];
    } __attribute__((aligned(16))) frame;
    if (arg1 < 0)
        return;
    node = fn_8023505C(arg0, arg1);
    if (node == 0) {
        fn_802E30C8(lbl_80340808, arg1, arg0);
        return;
    }
    n0 = *(float *)node;
    n1 = *((float *)node + 1);
    n2 = *((float *)node + 2);
    n3 = *((float *)node + 3);
    fn_802C8C04(*(int *)((char *)arg0 + 0x84));
    index = fn_80230B9C(arg2);
    t3 = fn_80230A68(index, x, y, z, n0, n1);
    frame.v[0].a = t3.a; frame.v[0].b = t3.b; frame.v[0].c = t3.c; frame.v[0].d = t3.d; frame.v[0].e = t3.e;
    t2 = fn_80230A68(index, x + dx, y, z, n2, n1);
    frame.v[1].a = t2.a; frame.v[1].b = t2.b; frame.v[1].c = t2.c; frame.v[1].d = t2.d; frame.v[1].e = t2.e;
    t1 = fn_80230A68(index, x, y - dy, z, n0, n3);
    frame.v[2].a = t1.a; frame.v[2].b = t1.b; frame.v[2].c = t1.c; frame.v[2].d = t1.d; frame.v[2].e = t1.e;
    t0 = fn_80230A68(index, x + dx, y - dy, z, n2, n3);
    frame.v[3].a = t0.a; frame.v[3].b = t0.b; frame.v[3].c = t0.c; frame.v[3].d = t0.d; frame.v[3].e = t0.e;
    frame.ids = lbl_802FA020;
    fn_802C8DB8(frame.v, 4, frame.ids.i, 6);
    fn_802C8D74();
}
#pragma pop
float fn_80235EF0(int arg0, int arg1) {
    void *node;

    if (arg0 == 0)
        return lbl_805636B8;
    node = fn_8023505C((void *)arg0, arg1);
    if (node == 0) {
        fn_802E30C8(lbl_80340834, arg0, arg1);
        return lbl_805636B8;
    }
    return *(float *)((char *)node + 0x14);
}
#pragma dont_inline reset
extern const char lbl_80340878[];
#pragma dont_inline on
float fn_80235F64(int arg0, int arg1) {
    void *node;

    if (arg0 == 0)
        return lbl_805636B8;
    node = fn_8023505C((void *)arg0, arg1);
    if (node == 0) {
        fn_802E30C8(lbl_80340878, arg0, arg1);
        return lbl_805636B8;
    }
    return *(float *)((char *)node + 0x10);
}

int fn_80235FD8(void *arg0) {
    void *p;
    int count;

    if (arg0 == 0) {
        return 0;
    }
    p = *(void **)((char *)arg0 + 0x88);
    count = 0;
    while (p != 0) {
        p = *(void **)((char *)p + 0x18);
        count++;
    }
    return count;
}

extern void *fn_8012850C(int, void *, int);
extern char lbl_803408CC[];
extern int lbl_8055B9F8;
void *fn_80236008(void *arg0, int arg1, int arg2) {
    *(int *)((char *)arg0 + 8) = arg1;
    *(void **)arg0 = lbl_803408CC;
    *(void **)((char *)arg0 + 4) = fn_8012850C(arg1 * 0x2C, &lbl_8055B9F8, arg2);
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x10) = -2;
    *((char *)arg0 + 0x14) = arg2;
    return arg0;
}

void *fn_80236074(void *arg0, int arg1) {
    int offset;
    int i;
    int mode;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_803408CC;
        i = 0;
        offset = 0;
        while (i < *(int *)((char *)arg0 + 0xC)) {
            fn_802CAC54(*(void **)(*(char **)((char *)arg0 + 4) + offset + 0x24));
            offset += 0x2C;
            i++;
        }
        fn_80128670(*(void **)((char *)arg0 + 4));
        mode = *(int *)((char *)arg0 + 0x10);
        *(int *)((char *)arg0 + 8) = 0;
        *(int *)((char *)arg0 + 0xC) = 0;
        if (mode != -2)
            fn_802CAC54();
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline reset
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern const char lbl_80340808[];
extern const char lbl_80340834[];
extern float lbl_805636B8;
extern int fn_8012C33C(const char *);
extern int fn_802CAC28(const char *, int);
#pragma scheduling invalid_target
void fn_80236134(void *arg0, int arg1, const char *arg2) {
    unsigned char ch;
    char *dst;
    char *entry;
    register int count;
    int id;

    if (fn_8012C33C(arg2) != 0) {
        id = fn_802CAC28(arg2, 0);
        count = *(int *)((char *)arg0 + 0xC);
        entry = *(char **)((char *)arg0 + 4) + count * 0x2C;
        *(int *)((char *)arg0 + 0xC) = count + 1;
        dst = entry;
        count = 0x21;
        goto loop_body;
    count_check:
        count -= 1;
        if (count > 0)
            goto loop_body;
        dst[-1] = 0;
        goto finish;
    loop_body:
        ch = *arg2++;
        *dst = ch;
        dst++;
        if ((signed char)ch != 0)
            goto count_check;
    finish:
        *(int *)(entry + 0x28) = arg1;
        *(int *)(entry + 0x24) = id;
    }
}
#pragma scheduling on
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern const char lbl_80340808[];
extern const char lbl_80340834[];
extern float lbl_805636B8;
extern int fn_8012C33C(const char *);
extern int fn_802CAC28(const char *, int);
