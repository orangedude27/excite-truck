// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8017E930(void *);
extern double fabs(double);
extern float lbl_80561C48;
extern float lbl_80561C4C;
typedef struct Unk8017Object Unk8017Object;
typedef struct Unk8017VTable {
    void (*unk_0x0[32])(void);
    void (*unk_0x80)(Unk8017Object *, int);
} Unk8017VTable;
struct Unk8017Object {
    Unk8017VTable *vtable;
};
extern Unk8017Object *lbl_804348D8[4];
extern signed char lbl_8055E4B8;
extern signed char lbl_8055E4B9;
extern signed char lbl_8055E4BA;
extern void fn_801808DC(void);
extern void fn_802E8524(int, int);

void fn_8017EB68(void *arg0) {
    fn_8017E930((char *)arg0 - 0x1EC);
}

extern void fn_8017E96C(void *);
void fn_8017EB70(void *arg0) {
    fn_8017E96C((char *)arg0 - 0x1EC);
}

extern void fn_8017E9FC(void *);
void fn_8017EB78(void *arg0) {
    fn_8017E9FC((char *)arg0 - 0x1EC);
}

float fn_8017EB80(float arg0, float arg1, float arg2) {
    float value = lbl_80561C48;
    float temp = ((value + arg1 + arg2) * (float)fabs(arg0)) - arg1;
    value = value < temp ? value : temp;
    value = value > lbl_80561C4C ? value : lbl_80561C4C;
    if (arg0 >= lbl_80561C4C) return value;
    return -value;
}

int fn_8017EBE0(void) {
    lbl_8055E4B8 = 0;
    lbl_8055E4BA = 1;
    lbl_8055E4B9 = 0;
    lbl_804348D8[0] = 0;
    lbl_804348D8[1] = 0;
    lbl_804348D8[2] = 0;
    lbl_804348D8[3] = 0;
    fn_801808DC();
    return 1;
}

void fn_8017EC30(void) {
    Unk8017Object **ptr = lbl_804348D8;
    int i = 0;
    do {
        Unk8017Object *obj;
        fn_802E8524(0, i);
        obj = *ptr;
        if (obj != 0) {
            if (obj != 0) {
                obj->vtable->unk_0x80(obj, 1);
            }
            *ptr = 0;
        }
        i++;
        ptr++;
    } while (i < 4);
    lbl_8055E4BA = 0;
}

void fn_80181438(void) {

}

void fn_8018143C(void) {

}

void fn_80181440(void) {

}

