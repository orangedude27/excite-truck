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

extern int lbl_8055F0B0;
extern int lbl_8055F0B4;
extern int lbl_8055F0B8;
extern char *lbl_8055F0BC;
extern char *lbl_8055F0C0;
extern char lbl_8055F0C4;
extern char lbl_8055F0C5;
extern char lbl_8055F0C6;
extern char lbl_8055F0C7;
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

extern void fn_80237A9C(void);
extern void fn_80237DA0(void);
extern void fn_80237EFC(void);
void fn_80236950(void) { fn_80237A9C(); }

void fn_80236954(void) { fn_80237DA0(); }

extern void fn_80237E7C(char *, int);
void fn_80236958(char *arg0, int unused) { fn_80237E7C(arg0, unused); }

void fn_8023695C(void) { fn_80237EFC(); }

void fn_802379EC(void *arg0) {
    *(int *)((char *)arg0 + 0x20) = -1;
    *(int *)((char *)arg0 + 0x28) = 0;
    *(int *)((char *)arg0 + 0x24) = 0;
}

void fn_80237A04(void) {
}

void fn_80237A84(void *arg0) {
    *(int *)arg0 = -1;
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 4) = 0;
}

extern char lbl_8055BA08[];
extern char lbl_8055BA10[];
extern char lbl_80498664[];
extern int fn_801345D8(void *, int, const char *, int);
extern char *fn_80029004(char *, int);
extern char *fn_80237C40(void);
void fn_80237A9C(void) {
}

extern int stricmp(const char *, const char *);
extern char lbl_8034094C[];
extern void *fn_801284F8(int, char *);
char *fn_80237C40(void) {
    char *p = fn_801284F8(0x34, lbl_8034094C);
    int i;
    for (i=0;i<0x21;i++) p[i]=0;
    *(int *)(p+0x28)=0; *(int *)(p+0x2c)=0; *(int *)(p+0x24)=0;
      return p;
}

void fn_80237D00(void *arg0) {
    void *p;
    unsigned int **v;
    p=*(void **)((char *)arg0+0x28);
    if(p){v=(unsigned int **)p;((void (*)(void *,int))v[0][2])(p,1);}
    p=*(void **)((char *)arg0+0x2c);
    if(p){v=(unsigned int **)p;((void (*)(void *,int))v[0][2])(p,1);}
    p=*(void **)((char *)arg0+0x30);
    if(p){v=(unsigned int **)p;((void (*)(void *,int))v[0][2])(p,1);}
    fn_80128668(arg0);
}

void fn_80237E7C(char *arg0, int unused) {
    int i = 0, offset = 0;
    char **items = *(char ***)((char *)lbl_8055F0C0 + 0x30);
    while (i < *(int *)((char *)items + 8)) {
        if (stricmp(*(char **)((char *)items + 4) + offset, arg0) == 0)
            *(*(char **)((char *)items + 4) + offset + 0x2d) = 0;
        offset += 0x34; i++;
    }
}

void *fn_80237FF8(void *arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 4);
        *(void **)arg0 = lbl_80340970;
        if (value != 0) fn_8002F6AC((void *)value, fn_80237A08);
        *(float *)((char *)arg0 + 0xC) = lbl_805636E0;
        if (arg1 > 0) fn_80128668(arg0);
        *(int *)((char *)arg0 + 4) = 0;
        *(int *)((char *)arg0 + 8) = 0;
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
