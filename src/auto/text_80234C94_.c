// Code of main that had no source file yet: decomp.wtf gave it this one.
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
    do {
        node = *(void **)((char *)node + 4);
        if (node == 0)
            break;
    } while (stricmp(arg0, *(const char **)node) != 0);
    if (node == 0)
        return 0;
    return *(void **)node;
}

void *fn_8023505C(void *arg0, int arg1) {
    void *node;
    int i;
    if (arg1 == 0) return *(void **)((char *)arg0 + 0x88);
    node = *(void **)((char *)arg0 + 0x88);
    i = 0;
    for (;;) {
        if (i == arg1) return node;
        node = *(void **)((char *)node + 0x18);
        i++;
        if (node == 0) return node;
        if (i > arg1) return node;
    }
}

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
    char ch;

    if (fn_8012C33C(arg2) != 0) {
        id = fn_802CAC28(arg2, 0);
        count = *(int *)((char *)arg0 + 0xC);
        entry = (char *)(*(char **)((char *)arg0 + 4) + count * 0x2C);
        *(int *)((char *)arg0 + 0xC) = count + 1;
        dst = entry;
        do {
            ch = *arg2++;
            *dst++ = ch;
        } while (ch != 0);
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
