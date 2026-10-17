// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8018B0D8(int *, int *);
void fn_80189CB4(void);
void fn_8018AF00(void);
void fn_80183DF8(void);
void fn_8018381C(void);
extern float lbl_805623C8;
int fn_801E9E30(void *, int *, int *);
void *fn_801B83A0(void);
void fn_80265D3C(void *);
void fn_801836E0(void *, int);
void fn_80128668(void *);
void fn_80182010(void);
void fn_80182074(void);
void fn_8018B09C(void);
int fn_80265D38(void *, int);
extern int lbl_80333C48;
void *fn_801A520C(void *arg0, void *arg1) {
    fn_80182010();
    *(void **)((char *)arg0 + 0x270C) = arg1;
    *(void **)arg0 = (void *)((unsigned long)&lbl_80333C48);
    return arg0;
}

void fn_801A5258(void *arg0, void *arg1) {
    void *obj;
    float zero;
    fn_80182074();
    fn_80265D38(arg0, *(int *)((char *)arg0 + 0x1EC));
    obj = *(void **)((char *)arg0 + 0x270C);
    *(int *)((char *)arg0 + 0x2708) = 0;
    *(unsigned char *)((char *)arg0 + 0x2704) = 0;
    *(int *)((char *)arg0 + 0x2700) = 0;
    ((void (*)(void *, void *, void *))(*(void ***)obj)[3])(obj, arg0, arg1);
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *))(*(void ***)obj)[9])(obj);
    zero = lbl_805623C8;
    *(int *)((char *)arg0 + 0x2714) = 1;
    *(int *)((char *)arg0 + 0x2720) = 0;
    *(float *)((char *)arg0 + 0x271C) = zero;
    *(float *)((char *)arg0 + 0x2718) = zero;
    *(unsigned char *)((char *)arg0 + 0x2710) = 0;
}

void fn_801A5300(void *arg0, void *arg1) {
    void *obj = *(void **)((char *)arg0 + 0x270C);
    if (obj != 0)
        ((void (*)(void *))(*(void ***)obj)[10])(obj);
    *(void **)((char *)arg0 + 0x270C) = arg1;
    if (arg1 != 0) {
        ((void (*)(void *, void *))(*(void ***)arg1)[4])(arg1, arg0);
        obj = *(void **)((char *)arg0 + 0x270C);
        ((void (*)(void *))(*(void ***)obj)[9])(obj);
    }
}

void fn_801A55BC(void *arg0) {
    void *obj;
    fn_8018381C();
    *(int *)((char *)arg0 + 0x2744) = 0;
    *(int *)((char *)arg0 + 0x2768) = 0;
    *(int *)((char *)arg0 + 0x278C) = 0;
    *(int *)((char *)arg0 + 0x27B0) = 0;
    *(int *)((char *)arg0 + 0x27D4) = 0;
    *(int *)((char *)arg0 + 0x27F8) = 0;
    *(int *)((char *)arg0 + 0x281C) = 0;
    *(int *)((char *)arg0 + 0x2840) = 0;
    *(int *)((char *)arg0 + 0x2714) = 1;
    obj = *(void **)((char *)arg0 + 0x270C);
    *(int *)((char *)arg0 + 0x2720) = 0;
    *(float *)((char *)arg0 + 0x271C) = lbl_805623C8;
    *(float *)((char *)arg0 + 0x2718) = lbl_805623C8;
    ((void (*)(void *, int))(*(void ***)obj)[10])(obj, 0);
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *))(*(void ***)obj)[9])(obj);
    *(int *)((char *)arg0 + 0x2700) = 0;
    *(unsigned char *)((char *)arg0 + 0x2704) = 0;
}

void fn_801A5660(void *arg0) {
    void *obj;
    fn_80183DF8();
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *))(*(void ***)obj)[13])(obj);
}

void fn_801A5D80(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    void *obj;
    float zero;
    fn_8018B09C();
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *, int, int, int, int))(*(void ***)obj)[14])(obj, arg1, arg2, arg3, arg4);
    if (arg3 == 0x6D) {
        zero = lbl_805623C8;
        *(int *)((char *)arg0 + 0x2714) = 1;
        *(int *)((char *)arg0 + 0x2720) = 0;
        *(float *)((char *)arg0 + 0x271C) = zero;
        *(float *)((char *)arg0 + 0x2718) = zero;
    }
}

void fn_801A5E98(void *arg0) {
    void *obj;
    fn_8018AF00();
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *))(*(void ***)obj)[16])(obj);
}

void fn_801A5ED8(void *arg0) {
    void *obj;
    fn_80189CB4();
    obj = *(void **)((char *)arg0 + 0x270C);
    *(unsigned char *)((char *)arg0 + 0x2704) = 1;
    ((void (*)(void *))(*(void ***)obj)[17])(obj);
    *(int *)((char *)arg0 + 0x2744) = 0;
    *(int *)((char *)arg0 + 0x2768) = 0;
    *(int *)((char *)arg0 + 0x278C) = 0;
    *(int *)((char *)arg0 + 0x27B0) = 0;
    *(int *)((char *)arg0 + 0x27D4) = 0;
    *(int *)((char *)arg0 + 0x27F8) = 0;
    *(int *)((char *)arg0 + 0x281C) = 0;
    *(int *)((char *)arg0 + 0x2840) = 0;
}

int fn_801A5F44(void *arg0, int arg1) {
    void *obj = *(void **)((char *)arg0 + 0x270C);
    return ((int (*)(void *, int))(*(void ***)obj)[6])(obj, arg1 + 0x44) + 0x44;
}

void fn_801A5F7C(void *arg0, int arg1, int arg2, int *arg3, int *arg4, float farg0) {
    int x, y, a, b;
    void *obj;
    fn_8018B0D8(&x, &y);
    obj = *(void **)((char *)arg0 + 0x270C);
    ((void (*)(void *, int, int, int *, int *, float))(*(void ***)obj)[7])(obj, arg1 + x, arg2 + y, &a, &b, farg0);
    *arg3 = x + a;
    *arg4 = y + b;
}

void fn_80188E2C(void);
int fn_8018BA54(void);
void fn_8018956C(void);
void fn_801A6088(void *arg0, int arg1) {
    void *obj;
    int offset;
    fn_80188E2C();
    obj = *(void **)((char *)arg0 + 0x270C);
    offset = arg1 + *(int *)((char *)arg0 + 8);
    *(int *)((char *)offset + 0x2C0) =
        ((int (*)(void *))(*(void ***)obj)[5])(obj);
}

