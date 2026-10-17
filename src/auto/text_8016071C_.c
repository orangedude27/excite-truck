// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E2BC;
extern int lbl_8042FD60[5];
extern int fn_8027DED0(void);
extern int fn_8001D9B4(int *, int);
extern int fn_8001DA48(void *, int);
extern int lbl_802F9490[5];
extern const char lbl_8032F4C8[];
extern int fn_801284F8(int, const char *);
extern int fn_8001D884(void *);
extern int fn_80128668(void);
extern int __AXGetStackHead(int);
typedef struct Obj { void **vtable; } Obj;
typedef int (*Callback)(Obj *, int, int);
void fn_8016071C(Obj *obj) {
    int i;
    if (fn_801284F8(0x18, lbl_8032F4C8)) {
        lbl_8055E2BC = (void *)fn_8001D884(obj);
    }
    for (i = 0; i < 5; i++) {
        int head = __AXGetStackHead(i);
        lbl_8042FD60[i] = ((Callback)obj->vtable[4])(obj, head, -1);
    }
}

void fn_801607BC(void) {
    int a = lbl_802F9490[0];
    int b = lbl_802F9490[1];
    int c = lbl_802F9490[2];
    int d = lbl_802F9490[3];
    int e = lbl_802F9490[4];
    lbl_8042FD60[0] = a;
    lbl_8042FD60[1] = b;
    lbl_8042FD60[2] = c;
    lbl_8042FD60[3] = d;
    lbl_8042FD60[4] = e;
}

int fn_801609C4(int value) {
    int *p = lbl_8042FD60;
    if (lbl_8055E2BC != 0) return fn_8001D9B4((int *)lbl_8055E2BC, value);
    if (*p >= 0 && value >= *p) return 0;
    if (p[1] >= 0 && value >= p[1]) return 1;
    if (p[2] >= 0 && value >= p[2]) return 2;
    if (p[3] >= 0 && value >= p[3]) return 3;
    if (p[4] >= 0 && value >= p[4]) return 4;
    return 4;
}

int fn_80160A74(void) {
    if (lbl_8055E2BC != 0) {
        return *(int *)((char *)lbl_8055E2BC + 0x14);
    }
    return 2;
}

void fn_80160A90(void* alarm) {
    fn_80160998(fn_80160AB4(alarm));
}

int fn_80160AB4(void *alarm) {
    fn_8027DED0();
    return fn_80160A74();
}

void fn_80160AE4(void) {
    fn_801607F8();
}
