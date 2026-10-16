// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055C790;
extern void fn_8001D9B4(void *);
extern void *fn_8001285C(int);
extern int lbl_80347DE8;
extern int fn_80007F90(int);
extern int lbl_8055C784;
extern int lbl_8055C77C;
extern int lbl_8055C774;
extern int fn_80012820(int);
extern void fn_80008188(int);
extern void fn_8000DBC8(void *);
extern void fn_8027D96C(void);
extern void fn_8027D9A4(int, int);
extern int fn_80128668(void);
extern int fn_8002F53C(void*, void*, void*, int, int);
extern void *__dt__Q34nw4r2ef6EffectFv_8027D434(void*, int);
extern void *fn_8027D674(void*);
extern void *fn_8027D504(void*);
extern void *fn_8027D304(void*, int);
extern void fn_8027D39C(void);
extern void fn_8027AF94(void*);
extern void fn_8001D868(int*);
extern char lbl_80347CA8[];
extern char lbl_80347CC0[];
extern char lbl_80347CF8[];
extern void *lbl_804A4380;
int fn_8027D578(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void* fn_8027D5B8(void* arg0) {
    int* temp_r6 = (int*)((char*)arg0 + 0x24);
    *(void**)arg0 = lbl_80347CC0;
    *(int**)((char*)arg0 + 0x18) = temp_r6;
    *(int*)((char*)arg0 + 0x20) = 6;
    *(int*)((char*)arg0 + 0x1C) = 0;
    fn_8002F53C(temp_r6, fn_8027D674, __dt__Q34nw4r2ef6EffectFv_8027D434, 0x3C, 6);
    *(char*)((char*)arg0 + 4) = 0;
    return arg0;
}

int fn_8027D634(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_8027D6BC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_8027D6FC(void *arg0) {
    void *res = fn_8001285C(*(int *)((char *)arg0 + 0xC));
    void *obj = *(void **)((char *)res + 0x20);
    if ((*(int (**)(void *, int))(*(void ***)obj + 3))(obj, (int)&lbl_8055C77C) != 0) {
        obj = *(void **)((char *)res + 0x20);
        fn_80008188((*(int (**)(void *, int))(*(void ***)obj + 5))(obj, (int)&lbl_8055C774));
    } else {
        fn_80008188(fn_80012820(*(int *)((char *)res + 4)) + 8);
    }
}

void fn_8027D77C(void *arg0) {
    void *res = fn_8001285C(*(int *)((char *)arg0 + 0xC));
    void *obj = *(void **)((char *)res + 0x20);
    (*(void (**)(void *, int))(*(void ***)obj + 5))(obj, (int)&lbl_8055C784);
}

void fn_8027D7B8(void *arg0) {
    int id = *(int *)((char *)arg0 + 0xC);
    void *res = fn_8001285C(id);
    fn_80007F90(*(int *)((char *)res + 8));
}

void fn_8027D810(void *arg0) {
    int id = *(int *)((char *)arg0 + 0xC);
    void *res = fn_8001285C(id);
    void *p = *(void **)((char *)res + 0x20);
    (*(void (**)(void *, int))(*(char **)p + 0x14))(p, (int)&lbl_80347DE8);
}

int fn_8027D850(void *arg0) {
    return *(int *)((char *)arg0 + 0x34);
}

int fn_8027D858(void *arg0) {
    if (*((unsigned char *)arg0 + 0x38) != 0) {
        return (*(int (**)(void *, int))(*(char **)arg0 + 0x30))(arg0, *(int *)((char *)arg0 + 0x34));
    }
    return -1;
}

void fn_8027D880(void *arg0) {
    fn_8001D9B4((char *)arg0 + 0x14);
}

extern void fn_8001DA48(void *);
void fn_8027D888(void *arg0) {
    fn_8001DA48((char *)arg0 + 0x14);
}

int fn_8027D890(void *arg0) {
    return ((int *)arg0)[3];
}

int fn_8027D898(void *arg0) { return *(int *)((char *)arg0 + 0x30); }

int fn_8027D8A0(void *arg0) {
    return *(int *)((char *)arg0 + 0x28);
}

void fn_8027D8A8(void *arg0) {
    void *obj = arg0;
    int value = (*(int (**)(void))(*(char **)obj + 0x38))();
    ((int (*)(void *, int))fn_8001DA48)((char *)obj + 0x14, value);
}

int fn_8027D8EC(void *arg0) { return *(int *)((char *)arg0 + 0x2C); }

int fn_8027D8F4(void *arg0) {
    return ((int *)arg0)[3];
}

int fn_8027D8FC(void *arg0) {
    return ((int *)arg0)[4];
}

int fn_8027D904(void *arg0) { return *(int *)((char *)arg0 + 0x14); }

int fn_8027D90C(void *arg0) { return *(int *)((char *)arg0 + 0x1C); }

int fn_8027D914(void *arg0, int arg1) {
    return ((int *)arg0)[6] + arg1 * 0x3C;
}

unsigned char fn_8027D924(void *arg0) {
    return ((unsigned char *)arg0)[0x1F0];
}

unsigned char fn_8027D92C(void *arg0) { return ((unsigned char *)arg0)[0x1F1]; }

unsigned char fn_8027D934(void *arg0) { return ((unsigned char *)arg0)[0x1F2]; }

unsigned char fn_8027D93C(void *arg0) {
    return ((unsigned char *)arg0)[0x1F3];
}

int fn_8027D944(int arg0) {
    return arg0 + 0x18C;
}

int fn_8027D94C(void *arg0) {
    return ((int *)arg0)[3];
}

int fn_8027D954(void *arg0, int arg1) {
    return ((int *)arg0)[2] + arg1 * 0x1F4;
}

unsigned char fn_8027D964(void *arg0) { return ((unsigned char *)arg0)[0xBCC]; }

extern void *lbl_804B2FD8;
extern int memset(void *, int, unsigned int);
extern char lbl_80347DF8[];
extern void fn_802E30C8(char *, int);
void fn_8027D9A4(int arg0, int arg1) {
    if (arg1 != 0)
        return;
    fn_802E30C8(lbl_80347DF8, arg0);
    memset((char *)&lbl_804B2FD8 + arg0 * 8, 0, 8);
}

extern int lbl_8055C784;
extern int lbl_8055C77C;
extern int lbl_8055C774;
extern int fn_80012820(int);
extern void fn_80008188(int);
extern void fn_802E6BD8(int, int, void *, int, void *);
extern void fn_8000DBC8(void *);
extern void fn_8027D96C(void);
extern void fn_8027D9A4(int, int);
void fn_8027DAF4(void) {
    fn_802E6BD8(0x50435252, 1, &lbl_804B2FD8, 0x20, fn_8027D96C);
    fn_8000DBC8(fn_8027D9A4);
}

void fn_8027DE6C(void) {
    fn_8027B77C();
    fn_8027BF38();
    fn_8027B690();
    fn_8027DA08();
}

void fn_8027DEAC(void* alarm) {
    fn_8027DE98(fn_8000DA10(alarm));
}

void* fn_8027DED0(void) {
    return lbl_8055C790;
}
