// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055EA40;
extern void *lbl_8055EA3C;
extern char lbl_8055EA38;
void fn_801A47C8(void);
void fn_801A47FC(int);
void fn_8015F670(int *, int);
void fn_801E2100(void *arg0, void *arg1) {
    int result;
    int (*first)(int);
    int (*second)(void *, void *, void *, int, int *);
    first = *(int (**)(int))((char *)arg1 + 0x20);
    if (first == 0 || first(*(int *)((char *)arg0 + 0x20)) != 0) {
        result = ((int (*)(void *, void *, void *, int, int *))(*(void ***)arg0)[3])(arg0, arg1, (char *)arg1 + 0xC, *(int *)((char *)arg1 + 0x18), &result);
        if (result != 0)
            *((unsigned char *)arg1 + 0x1C) = 1;
    }
}

void fn_801E21B4(void* hi) {
    lbl_8055EA40 = hi;
}

void fn_801E21BC(void) {
    int values[2];
    int i;
    values[0] = (int)lbl_8055EA3C;
    values[1] = (int)lbl_8055EA40;
    lbl_8055EA38 = 1;
    for (i = 0; i < 2; i++)
        fn_801A47FC(values[i]);
    fn_8015F670(values, 2);
}

void fn_801E222C(void) {
    lbl_8055EA38 = 0;
    if (lbl_8055EA3C != 0) {
        ((void (*)(void))(*(void **)((char *)lbl_8055EA3C + 0x14)))();
        lbl_8055EA3C = 0;
    }
    if (lbl_8055EA40 != 0) {
        ((void (*)(void))(*(void **)((char *)lbl_8055EA40 + 0x14)))();
        lbl_8055EA40 = 0;
    }
}

void fn_801E2294(void) {
    if (lbl_8055EA3C != 0)
        fn_801A47C8();
    if (lbl_8055EA40 != 0)
        fn_801A47C8();
}
typedef struct VTable_801E2084 { void *unk0; void *unk4; void *unk8; void *unkC; void (*call)(void *, void *); } VTable_801E2084;
typedef struct Obj_801E2084 { VTable_801E2084 *vtable; } Obj_801E2084;
