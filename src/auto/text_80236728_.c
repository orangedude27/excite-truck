// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int stricmp(const char *, const char *);
extern char lbl_8034094C[];
extern void *fn_801284F8(int, char *);
extern float lbl_805636E0;
extern void fn_8002F6AC(void *, void (*)(void));
extern void fn_80128668(void *);
extern void fn_80237968(void);
extern void fn_80237A08(void);
extern char lbl_8034095C[];
extern char lbl_80340970[];

extern char lbl_8055F0C4;
void fn_80236774(void) {
    lbl_8055F0C4 = 0;
}

extern char lbl_8055F0C5;
void fn_802368E0(void) {
    lbl_8055F0C5 = 1;
}

extern int fn_80215264(void);
extern void fn_80236A5C(void*, int);
extern void fn_80237AA0(void);
extern void fn_80236960(void);
extern char *lbl_8055F0C0;
void fn_80236900(void) {
    lbl_8055F0C0[0x21] = 0;
}

void fn_80236910(void) {
    fn_80236960();
}

void fn_80236914(void) {
    fn_80237AA0();
}

void fn_80236918(void* alarm) {
    fn_80236A5C(alarm, fn_80215264());
}

extern int stricmp(const char *, const char *);
extern char lbl_8034094C[];
extern void *fn_801284F8(int, char *);
void fn_80237C40(void) {
    char *p = fn_801284F8(0x34, lbl_8034094C);
    int i;
    for (i = 0; i < 0x21; i++) p[i] = 0;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x2c) = 0;
    *(int *)(p + 0x24) = 0;
}

void fn_80237E7C(char *arg0, int arg1) {
    int i = 0;
    int offset = 0;
    char **list = (char **)lbl_8055F0C0;
    void *items = *(void **)((char *)list + 0x30);
    for (;;) {
        if (i >= *(int *)((char *)items + 8)) break;
        if (stricmp(*(char **)((char *)items + 4) + offset, arg0) == 0)
            *(*(char **)((char *)items + 4) + offset + 0x2d) = 0;
        offset += 0x34;
        i++;
    }
}

void *fn_80237FF8(void *arg0, int arg1) {
    int value;
    float initial;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 4);
        *(void **)arg0 = lbl_80340970;
        if (value != 0) fn_8002F6AC((void *)value, fn_80237A08);
        initial = lbl_805636E0;
        if (arg1 <= 0) {
            *(int *)((char *)arg0 + 4) = 0;
            *(int *)((char *)arg0 + 8) = 0;
            *(float *)((char *)arg0 + 0xC) = initial;
        } else {
            *(int *)((char *)arg0 + 4) = 0;
            *(int *)((char *)arg0 + 8) = 0;
            *(float *)((char *)arg0 + 0xC) = initial;
            fn_80128668(arg0);
        }
    }
    return arg0;
}

float fn_80238084(void *arg0) { return *(float *)((char *)arg0 + 0xC); }

void *fn_80238370(void *arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 4);
        *(void **)arg0 = lbl_8034095C;
        if (value != 0) fn_8002F6AC((void *)value, fn_80237968);
        *(int *)((char *)arg0 + 4) = 0;
        *(int *)((char *)arg0 + 8) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

float fn_802383F4(void) { return lbl_805636E0; }

extern void fn_80237AA0(void);
extern void fn_80236960(void);
extern float lbl_805636E0;
extern void fn_8002F6AC(void *, void (*)(void));
extern void fn_80128668(void *);
extern void fn_80237968(void);
extern void fn_80237A08(void);
extern char lbl_8034095C[];
extern char lbl_80340970[];
