// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_802E61E4(float);
extern float fn_80209028(void), fn_802091CC(void);
extern int fn_802090CC(void), fn_802E2C20(void);
extern void fn_802E625C(int);
extern void fn_802E61EC(void *, float), fn_802E620C(void *, float), fn_802E6234(void *, float), fn_802E6238(void *, float), fn_802E623C(void *, float), fn_802E622C(void *, float), fn_802E6240(void *, int);
extern float lbl_8055B590, lbl_8055B594, lbl_80558DC4, lbl_805632B8;
extern int lbl_8055EDF8;
extern unsigned int lbl_8055EE00;

extern void fn_802E6264(void);
extern int lbl_8055EE0C;
extern void *lbl_8055EE10;
extern char lbl_8033C35C[];
extern char lbl_8033C368[];
extern char lbl_804892D0[];
extern int fn_801284F8(int, void *);
extern void *fn_8012A13C(void *, int, int);
extern int fn_8012A2D8(void *);
extern int fn_8012A364(void *, void *);
typedef struct { void **vtable; } Unk8012A570;
extern void fn_8020A860(void);
extern int fn_80208E90(int);
extern float lbl_805632B0, lbl_805632B4, lbl_8055B598;
extern void *lbl_8055EE04;
extern char lbl_8033C37C[];
extern void *lbl_8055EE08;
extern unsigned char lbl_8033C520[];
extern unsigned char lbl_80489BD0[];
extern int fn_80128668(void);
void fn_8020A72C(void) {
    volatile char *p = lbl_8033C35C;
    int size = 0xC;
    if (fn_801284F8(size, (void *)p) != 0) fn_8020A860();
    fn_80208E90(0);
}

void* fn_8020A76C(void) {
    return lbl_8055EE08;
}

void *fn_8020A774(int arg0) { return lbl_804892D0 + arg0 * 0x24; }

void fn_8020A788(void) {
    if (lbl_8055EE0C == 0) {
        if (fn_801284F8(0x20, lbl_8033C368) != 0)
            lbl_8055EE10 = fn_8012A13C(lbl_8033C368, 0x200, 0x54);
    }
    if (fn_8012A2D8(lbl_8055EE10) != 0) {
        int count;
        count = lbl_8055EE0C;
        lbl_8055EE0C = count + 1;
    }
}

void fn_8020A800(void *arg0) {
    fn_8012A364(lbl_8055EE10, arg0);
    if (--lbl_8055EE0C == 0) {
        if (lbl_8055EE10 != 0)
            ((void (*)(void *, int))((void **)*(void **)lbl_8055EE10)[2])(lbl_8055EE10, 1);
        lbl_8055EE10 = 0;
    }
}

extern void fn_802E59BC(void *);
extern void fn_802E5950(int, int);
extern void fn_802E6138(void);
extern void fn_802E61D8(void *);
void fn_8020AA0C(void *arg0) {
    void *value = *(void **)((char *)arg0 + 8);
    if (value != 0) {
        fn_802E61D8(value);
        if (*(void **)((char *)arg0 + 0xC) != 0)
            fn_802E61D8(*(void **)((char *)arg0 + 0xC));
        if (*(void **)((char *)arg0 + 0xC) != 0) {
            fn_802E6138();
            *(void **)((char *)arg0 + 0xC) = 0;
        }
        if (*(void **)((char *)arg0 + 8) != 0) {
            fn_802E6138();
            *(void **)((char *)arg0 + 8) = 0;
        }
    }
    *(int *)((char *)arg0 + 4) = 3;
    *((unsigned char *)arg0 + 0x3E) = 0;
}

int fn_8020AA98(void *arg0) { volatile int *p = (volatile int *)((char *)arg0 + 4); if (*p == 1 && *((unsigned char *)arg0 + 0x3E) != 0) return 2; return *p; }

extern void fn_802E5950(int, int); void fn_8020AC0C(int arg0, int arg1, int arg2) { fn_802E5950(arg1, arg2); }

extern void fn_802E59BC(void *); void fn_8020AC18(void *arg0, int arg1) { fn_802E59BC((void *)arg1); }

extern void fn_802E5A54(void);
void fn_8020AC20(void) {
    lbl_8055EE08 = 0;
    fn_802E5A54();
}

int fn_8020B2A8(void *arg0) {
    return *(int *)((char *)arg0 + 0x10) != 0;
}

void fn_8020B2BC(void *arg0, int arg1, int arg2) {
    int *ptr = *(int **)((unsigned char *)arg0 + 4);
    ptr[arg2] = 0;
}

void fn_8020B2D0(void) {

}

extern unsigned char lbl_8033C520[];
extern unsigned char lbl_80489BD0[];
extern int fn_80128668(void);
int fn_8020B2D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void *fn_8020B314(void) {
    return lbl_8033C520;
}

void fn_8020B320(void) {
    volatile unsigned char *p = lbl_80489BD0;
    p[0] = 0;
    *(volatile int *)(p + 4) = 0;
    *(volatile int *)(p + 8) = 0x20;
}

void fn_8020B340(void) {
    fn_802E5824();
}

void fn_8020B344(void) {
    fn_802E5828();
}

void fn_8020B348(void *arg0) {
    if (arg0 == 0) return;
    ((void (*)(void *, int))(*(void ***)arg0)[2])(arg0, 1);
}

extern void *fn_802E5AE8(void *);
extern void fn_802E5D5C(void *);
extern void *fn_8020A6AC(void *);
extern void fn_802E30C8(const char *, ...);
extern const char lbl_8033C4F0[];
int fn_8020B874(void *object, void *name) {
    int result = 0;
    void *created = fn_802E5AE8(name);
    if (created != 0) {
        fn_802E5D5C(*(void **)((char *)object + 0x10));
        *(void **)((char *)object + 0x10) = created;
        *(void **)((char *)object + 0x18) = fn_8020A6AC(name);
        result = 1;
    } else {
        fn_802E30C8(lbl_8033C4F0, name);
    }
    return result;
}

extern void fn_802E61E4(float);
extern int lbl_8055EDFC;
extern float lbl_805632B0;
void fn_8020B908(void *arg0) {
    void *p;
    if (*((unsigned char *)arg0 + 0x3E) == 0 && *(int *)((char *)arg0 + 4) != 3) {
        *((unsigned char *)arg0 + 0x3E) = 1;
        lbl_8055EDFC++;
        p = *(void **)((char *)arg0 + 8);
        if (p != 0) {
            fn_802E61D8(p);
            p = *(void **)((char *)arg0 + 0xC);
            if (p != 0)
                fn_802E61D8(p);
            p = *(void **)((char *)arg0 + 0xC);
            if (p != 0) {
                fn_802E6138();
                *(void **)((char *)arg0 + 0xC) = 0;
            }
            p = *(void **)((char *)arg0 + 8);
            if (p != 0) {
                fn_802E6138();
                *(void **)((char *)arg0 + 8) = 0;
            }
        }
        p = *(void **)((char *)arg0 + 8);
        if (p != 0)
            fn_802E61E4(lbl_805632B0);
        p = *(void **)((char *)arg0 + 0xC);
        if (p != 0)
            fn_802E61E4(lbl_805632B0);
    }
}

void fn_8020BC50(void *arg0, float farg0) { *(float *)((char *)arg0 + 0x24) = farg0; }

typedef float f32;
typedef signed int s32;
void fn_8020BC58(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x1C) = farg0; }

s32 fn_8020BC60(void) { return 0; }

void fn_8020BC68(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x20) = farg0; }

void fn_8020BC70(void *arg0, f32 farg0) {
    *(f32 *)((signed char *)arg0 + 0x28) = farg0;
}

void fn_8020BC78(void *arg0, f32 farg0) {
    *(f32 *)((signed char *)arg0 + 0x2C) = farg0;
}

void fn_8020BC80(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x30) = arg1;
}

void fn_8020BC88(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x34) = arg1;
}

void fn_8020BC90(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x38) = arg1;
}

float fn_8020BCA8(void *arg0) {
    return *(float *)((char *)arg0 + 0x48);
}

void fn_8020BCB0(void) {

}

void fn_8020BCB4(void) {

}

extern void fn_802E6264(void);
extern void fn_802E6B34(void);
extern void fn_802E317C(const char *, ...);
extern int fn_80128670(void *);
extern int fn_80019B60(void);
extern void *fn_8012850C(unsigned int, void *);
extern void *memset(void *, int, unsigned int);
extern char lbl_8033C388[];
extern char lbl_8033C37C[];
extern float lbl_805632B0, lbl_805632B4, lbl_8055B598;
extern void *lbl_8055EE04;
extern int lbl_8055EE0C;
extern void *lbl_8055EE10;
extern int fn_8012A364(void *, void *);
extern int fn_801284F8(int, void *);
extern void *fn_8012A13C(void *, int, int);
extern int fn_8012A2D8(void *);
extern char lbl_8033C368[];
extern char lbl_8033C35C[];
extern char lbl_804892D0[];
extern void fn_8020A860(void);
extern int fn_80208E90(int);
