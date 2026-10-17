// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F014;
extern float lbl_805635FC;
extern float lbl_8056360C;
void fn_8022FB6C(void);
void fn_80214D48(void);
void fn_8022FD9C(int);
void fn_80015EB0(float);
void fn_80015E30(void *, float);
void fn_80015B20(void *, void *, void *);
void fn_80015AA0(void *, float);
char *stricmp(const char *, const char *);
void *fn_8022F2FC(char *arg0) {
    void *node = lbl_8055F014;
    while (node != 0) {
        if (stricmp((char *)*(void **)node + 0x3c, arg0) == 0) return node;
        node = *(void **)((char *)node + 8);
    }
    return 0;
}

void fn_8022F364(void *arg0) {
    void *node;
    void *next;
    if (arg0 == 0) return;
    node = lbl_8055F014;
    if (node == 0) {
        node = (void *)fn_801284F8(0xc, 0x803403CC);
        lbl_8055F014 = node;
        *(void **)node = arg0;
        *(int *)((char *)node + 4) = 1;
        *(void **)((char *)node + 8) = 0;
        return;
    }
    while ((next = *(void **)((char *)node + 8)) != 0) node = next;
    next = (void *)fn_801284F8(0xc, 0x803403CC);
    *(void **)((char *)node + 8) = next;
    *(void **)next = arg0;
    *(int *)((char *)next + 4) = 1;
    *(void **)((char *)next + 8) = 0;
}

void fn_8022F77C(void *arg0) {
    void *prev = 0;
    void *node = lbl_8055F014;
    while (*(void **)node != arg0) {
        if (node == 0) fn_802E317C((void *)0x80340408, (char *)arg0 + 0x3c);
        prev = node;
        node = *(void **)((char *)node + 8);
    }
    if (prev == 0) lbl_8055F014 = *(void **)((char *)node + 8);
    else *(void **)((char *)prev + 8) = *(void **)((char *)node + 8);
    *(int *)((char *)node + 4) = 0;
    *(void **)((char *)node + 8) = 0;
    *(void **)node = 0;
    fn_80128668(node);
}

void fn_8022F824(void *arg0) {
    fn_8022F418();
    fn_802CAC54(*(int *)((char *)arg0 + 0x30));
    fn_8022F77C(arg0);
    fn_80128668(arg0);
}

void fn_8022F868(void *arg0, void *arg1) {
    int temp = fn_8022EDC4();
    fn_801BFD34((char *)arg0 + 0x24, (char *)arg1 + 0x24, temp);
    fn_80015B20(arg0, arg1, (void *)temp);
}

void fn_8022FF10(void *arg0, void *arg1) {
    int sp8;
    float temp_f31 = *(float *)((char *)arg1 + 0);
    float temp_f30 = *(float *)((char *)arg1 + 8);
    fn_80015EB0(*(float *)((char *)arg1 + 4));
    fn_80015E30(&sp8, temp_f31);
    fn_80015B20(arg0, arg0, &sp8);
    fn_80015AA0(&sp8, temp_f30);
    fn_80015B20(arg0, arg0, &sp8);
}

void fn_8022FF90(void *arg0) {
    float f0 = lbl_805635FC;
    float f1 = lbl_8056360C;
    *(float *)((char *)arg0 + 4) = f0;
    *(float *)((char *)arg0 + 0) = f1;
    *(float *)((char *)arg0 + 8) = f0;
    *(float *)((char *)arg0 + 0xC) = f0;
    *(float *)((char *)arg0 + 0x10) = f1;
    *(float *)((char *)arg0 + 0x14) = f0;
    *(float *)((char *)arg0 + 0x18) = f0;
    *(float *)((char *)arg0 + 0x1C) = f0;
    *(float *)((char *)arg0 + 0x20) = f1;
    *(float *)((char *)arg0 + 0x24) = f0;
    *(float *)((char *)arg0 + 0x28) = f0;
    *(float *)((char *)arg0 + 0x2C) = f0;
    *(unsigned int *)((char *)arg0 + 0x34) = 0xFF000000;
    *(int *)((char *)arg0 + 0x38) = -1;
    *(float *)((char *)arg0 + 0x8C) = f0;
    *(float *)((char *)arg0 + 0x94) = f0;
    *(float *)((char *)arg0 + 0x98) = f0;
}

void fn_8022FFE8(int arg0) {
    fn_8022FB6C();
    fn_80214D48();
    fn_8022FD9C(arg0);
}

int fn_80230020(void) {
    int count = 0;
    void *p = lbl_8055F014;
    while (p != 0) {
        p = *(void **)((char *)p + 8);
        count++;
    }
    return count;
}
