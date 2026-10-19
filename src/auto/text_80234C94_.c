// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern const char lbl_80340808[];
extern const char lbl_80340834[];
extern float lbl_805636B8;
extern int fn_8012C33C(const char *);
extern int fn_802CAC28(const char *, int);
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void *);
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
void fn_8023509C(void) {
    if (lbl_8055F084 != 0)
        fn_802E317C(lbl_803406FC, 0);
}

void fn_802350BC(void) {
    if (lbl_8055F084 != 0) {
        fn_802E30C8(lbl_80340724, 0);
        do {
            fn_802E30C8(lbl_80340760, *(unsigned int *)lbl_8055F084);
            fn_80235380(*(void **)lbl_8055F084);
        } while (lbl_8055F084 != 0);
    }
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

void fn_802353F4(int arg0, int arg1, float arg2, float arg3, float arg4) {
    void *node;

    if (arg1 >= 0) {
        node = fn_8023505C((void *)arg0, arg1);
        if (node == 0) {
            fn_802E30C8(lbl_80340808, arg1, arg0);
        } else {
            fn_802354A0(arg0, arg1, -1, arg2, arg3, arg4,
                        *(float *)((char *)node + 0x14),
                        *(float *)((char *)node + 0x10));
        }
    }
}

extern void fn_80230A68(void *, int, float, float, float, float, float);
extern int fn_80230B9C(void *);
extern void fn_802C8C04(int);
extern void fn_802C8DB8(void *, int, unsigned short *, int, unsigned short, unsigned short, unsigned short, unsigned short, float, double);
extern void fn_802C8D74(void);
extern const char lbl_802FA020[];
void fn_80235CBC(void *arg0, int arg1, float x, float y, float z, float dx, float dy) {
    void *node;
    int index;
    struct V { double a; int b, c; float d, e; } v0, v1, v2, v3;
    unsigned short ids[6];
    if (arg1 < 0)
        return;
    node = fn_8023505C(arg0, arg1);
    if (node == 0) {
        fn_802E30C8(lbl_80340808, arg1, arg0);
        return;
    }
    fn_802C8C04(*(int *)((char *)arg0 + 0x84));
    index = fn_80230B9C(*(void **)((char *)arg0 + 0x88));
    fn_80230A68(&v0, index, x, y, z, *(float *)node, *((float *)node + 1));
    fn_80230A68(&v1, index, x + dx, y, z, *((float *)node + 2), *((float *)node + 1));
    fn_80230A68(&v2, index, x, y - dy, z, *(float *)node + 0, *((float *)node + 3));
    fn_80230A68(&v3, index, x + dx, y - dy, z, *((float *)node + 2), *((float *)node + 3));
    fn_802C8DB8(&v0, 4, ids, 6, *(unsigned short *)(lbl_802FA020 + 8), *(unsigned short *)(lbl_802FA020 + 6), *(unsigned short *)(lbl_802FA020 + 4), *(unsigned short *)(lbl_802FA020 + 2), *(float *)((char *)&v3 + 0x10), v3.a);
    fn_802C8D74();
}

#pragma dont_inline on
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
#pragma dont_inline reset
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern const char lbl_80340808[];
extern const char lbl_80340834[];
extern float lbl_805636B8;
extern int fn_8012C33C(const char *);
extern int fn_802CAC28(const char *, int);
void fn_80236134(void *arg0, int arg1, const char *arg2) {
    int id;
    int count;
    char *entry;
    char *dst;
    int i;
    char ch;

    if (fn_8012C33C(arg2) != 0) {
        id = fn_802CAC28(arg2, 0);
        count = *(int *)((char *)arg0 + 0xC);
        entry = *(char **)((char *)arg0 + 4) + count * 0x2C;
        *(int *)((char *)arg0 + 0xC) = count + 1;
        dst = entry;
        i = 0x21;
        while (i-- > 0)
            ;
        for (;;) {
            ch = *arg2++;
            *dst++ = ch;
            if ((signed char)ch == 0)
                break;
        }
        *(int *)(entry + 0x28) = arg1;
        *(int *)(entry + 0x24) = id;
    }
}
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern const char lbl_80340808[];
extern const char lbl_80340834[];
extern float lbl_805636B8;
extern int fn_8012C33C(const char *);
extern int fn_802CAC28(const char *, int);
