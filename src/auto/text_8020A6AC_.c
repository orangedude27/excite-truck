// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_805632B0, lbl_805632B4, lbl_8055B598;
extern void *lbl_8055EE04;
extern char lbl_8033C37C[];
extern void *lbl_8055EE08;
void* fn_8020A76C(void) {
    return lbl_8055EE08;
}

extern void fn_802E59BC(void *);
extern void fn_802E5950(int, int);
extern void fn_802E6138(void);
extern void fn_802E61D8(void *);
void fn_8020AA0C(void *arg0) {
    int value = *(int *)((char *)arg0 + 8);
    if (value != 0) {
        fn_802E61D8((void *)value);
        if (*(int *)((char *)arg0 + 0xC) != 0)
            fn_802E61D8(*(void **)((char *)arg0 + 0xC));
        if (*(int *)((char *)arg0 + 0xC) != 0) {
            fn_802E6138();
            *(int *)((char *)arg0 + 0xC) = 0;
        }
        if (*(int *)((char *)arg0 + 8) != 0) {
            fn_802E6138();
            *(int *)((char *)arg0 + 8) = 0;
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

void fn_8020B2D0(void) {

}

void fn_8020B340(void) {
    fn_802E5824();
}

void fn_8020B344(void) {
    fn_802E5828();
}

void fn_8020BC50(void *arg0, float farg0) { *(float *)((char *)arg0 + 0x24) = farg0; }

typedef float f32;
typedef signed int s32;
void fn_8020BC58(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x1C) = farg0; }

s32 fn_8020BC60(void) { return 0; }

void fn_8020BC68(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x20) = farg0; }

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

