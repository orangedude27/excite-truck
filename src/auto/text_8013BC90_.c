// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char *strchr(const char *, int);
extern char *fn_80029004(char *, int);
extern void *fn_801284F8(int, const char *);
extern void fn_8013A264(void *);
extern void fn_8013BF3C(void);
extern const char lbl_8032C414[];
char *fn_8013BC90(char *arg0, int arg1, const char *arg2) {
    char *base=arg0, *dst=arg0;
    const char *src=arg2;
    int n=arg1;
    char c;
    while (--n > 0) {
        c=*src++;
        *dst++=c;
        if (!c) goto copied;
    }
    dst[-1]=0;
copied:
    if (strchr(base, '/') != 0) base=strchr(base, '/')+1;
    { char *p=fn_80029004(base,'.'); if(p) *p=0; }
    return base;
}

extern void fn_8013BD30(void);
extern const char lbl_8032C3D8[];
extern const char lbl_80559CE0[];
extern const char lbl_80559CE8[];
extern const char lbl_80559CF0[];
void fn_8013BD5C(void *arg0, void *arg1) {
    float *v = (float *)arg0;
    void *p;
    fn_8013BD30();
    p = (*(void *(*)(void *, const char *))((char *)*(void **)arg1 + 0x5c))(arg1, lbl_8032C3D8);
    if (p != 0) {
        v[0] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, lbl_80559CE0, v[0]);
        v[1] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, lbl_80559CE8, v[1]);
        v[2] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, (const char *)lbl_8032C3D8 + 0xC, v[2]);
        v[4] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, (const char *)lbl_8032C3D8 + 0x18, v[4]);
        v[3] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, lbl_80559CF0, v[3]);
    }
}

extern void fn_8013A2FC(void *, int);
extern void fn_8013BD5C(void *, void *);
extern const char lbl_8032C420[];
void *fn_8013BE64(void *arg0, const char *arg1) {
    void *p;
    char *dst;
    const char *src;
    int n;
    char c;
    p = fn_801284F8(0x78, lbl_8032C414);
    if (p != 0) fn_8013A264((char *)p + 0x40);
    dst = (char *)p;
    src = arg1;
    n = 0x40;
    while (--n > 0) {
        c = *src++;
        *dst++ = c;
        if (!c) goto copied;
    }
    dst[-1] = 0;
copied:
    fn_8013A2FC((char *)p + 0x40, (*(int (**)(void *, const char *))((char *)*(void **)arg0 + 0x5c))(arg0, lbl_8032C420));
    fn_8013BD5C((char *)p + 0x60, arg0);
    *(int *)((char *)p + 0x74) = 0;
    return p;
}

void fn_8013BF3C(void) {
    fn_8013BD30();
}

void *fn_8013BF40(char *arg0) {
    void *p=fn_801284F8(0x78,lbl_8032C414);
    char *dst=(char *)p;
    const char *src=arg0;
    int n=0x40;
    if(p) fn_8013A264((char *)p+0x40);
    while (--n > 0) {
        char c=*src++;
        *dst++=c;
        if(!c) goto copied2;
    }
    dst[-1]=0;
copied2:
    fn_8013BF3C();
    *(int *)((char *)p+0x74)=0;
    return p;
}

void fn_8013BFE0(void) {

}

void fn_8013BFE4(void) {

}
typedef struct { void *obj; char name[0x40]; int refs; } CacheEntry;
extern CacheEntry lbl_8042F8C8[];
extern int cache_count_8042F8C8;
