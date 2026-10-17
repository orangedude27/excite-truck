// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int fn_802E30C8(const char *, ...);
extern int fn_801338D8(const char *);
extern float fn_80133960(const char *);
extern int fn_80133844(const char *);
extern unsigned long strlen(const char *);
extern const char lbl_8032B8F8[];

extern int lbl_8055E07C;
extern int lbl_80559B58;
extern int fn_80133BA0(int, int, int);
extern int fn_80133AD8(int);
extern int fn_802E317C(const char *, ...);
extern const char lbl_8032B8B0[];
extern int lbl_8042F718[];
extern const char lbl_8032B8D0[];
extern int fn_80128668(int);
extern int fn_80133E10(void **, int, int);
extern int fn_8013323C(int, int, float);
int fn_80133010(void) { int val=lbl_8055E07C; unsigned int tmp=(unsigned int)(-val)|(unsigned int)val; return tmp>>31; }

extern int lbl_8055E078, lbl_8055E080;
extern const char lbl_8032B880[], lbl_8032B88C[];
extern void* fn_801284F8(int, const char*);
extern void fn_80133FCC(void);
extern void fn_801341B4(int, int);
extern void fn_802E6BD8(int, int, int, int, void (*)(void));
extern void fn_8000DBC8(void (*)(int, int));
#pragma push
#pragma optimize_for_size on
void fn_80133024(void) {
    void *p;
    lbl_8055E078 = 1;
    p = fn_801284F8(0x6D68, lbl_8032B880);
    lbl_8055E07C = (int)p;
    *(int*)((char*)p + 4) = 0;
    lbl_8055E080 = 0;
    lbl_8042F718[1] = 0;
    lbl_8042F718[3] = 0;
    lbl_8042F718[5] = 0;
    lbl_8042F718[7] = 0;
    lbl_8042F718[9] = 0;
    lbl_8042F718[11] = 0;
    lbl_8042F718[13] = 0;
    lbl_8042F718[15] = 0;
    if (fn_80133BA0(lbl_80559B58, 0, 0x12) == 0) {
        fn_802E317C(lbl_8032B88C, lbl_80559B58);
    }
    fn_802E6BD8(0x4F505473, 6, lbl_8055E07C, 0x6D68, fn_80133FCC);
    fn_8000DBC8(fn_801341B4);
}
#pragma pop
void fn_801330E8(int arg0) {
 if (!fn_80133BA0(lbl_80559B58,0,arg0)) {
   const char *fmt=lbl_8032B8B0;
   int result=fn_80133AD8(arg0);
   fn_802E317C(fmt,result);
 }
}

void fn_80133144(void) {
 int *entry=&lbl_8042F718[0];
 int i=0;
 do {
   if(entry[1]) fn_802E317C(lbl_8032B8D0,entry[0]);
   i++; entry+=2;
 } while(i<8);
 fn_80128668(lbl_8055E07C); lbl_8055E07C=0;
}

void fn_801331C4(int arg0,int arg1,float *arg2) {
 void *sp8=0;
 int ok;
 ok=fn_80133E10(&sp8,arg0,arg1);
 if(ok) *arg2=*(float *)((char *)sp8+0x10);
 else fn_8013323C(arg0,arg1,*arg2);
}

extern int fn_80133348(int, int, int);
extern int fn_80133460(int, int, unsigned char);
extern int sprintf(char *, const char *, ...);
extern const char lbl_80559B60[];
extern const char lbl_80559B5C[];
extern double lbl_805612D8;
extern float lbl_805612D0;
extern double lbl_805612E0;
extern const char lbl_80559B64[];
extern const char lbl_80559B68[];
int fn_80133348(int, int, int);
int fn_80133460(int, int, unsigned char);
int sprintf(char *, const char *, ...);
void fn_801332D0(int arg0, int arg1, int *arg2) {
    void *sp8;
    if (fn_80133E10(&sp8, arg0, arg1) == 0)
        fn_80133348(arg0, arg1, *arg2);
    else
        *arg2 = *(int *)((char *)sp8 + 0xC);
}

int fn_80133348(int arg0, int arg1, int arg2) {
    void *sp8;
    fn_80133E10(&sp8, arg0, arg1);
    *(int *)((char *)sp8 + 0xC) = arg2;
    *(float *)((char *)sp8 + 0x10) = (float)(unsigned int)arg2;
    *(unsigned char *)((char *)sp8 + 8) = arg2 != 0;
    sprintf((char *)sp8 + 0x14, lbl_80559B60, arg2);
    *(int *)sp8 = 2;
    return 0;
}

void fn_801333E8(int arg0, int arg1, unsigned char *arg2) {
    void *sp8;
    if (fn_80133E10(&sp8, arg0, arg1) == 0)
        fn_80133460(arg0, arg1, *arg2);
    else
        *arg2 = *(unsigned char *)((char *)sp8 + 8);
}

int fn_80133460(int arg0, int arg1, unsigned char arg2) {
    void *sp8;
    fn_80133E10(&sp8, arg0, arg1);
    *(unsigned char *)((char *)sp8 + 8) = arg2;
    *(int *)((char *)sp8 + 0xC) = arg2;
    *(float *)((char *)sp8 + 0x10) = (float)arg2;
    strcpy((char *)sp8 + 0x14, arg2 ? "true" : "false");
    *(int *)sp8 = 1;
    return 0;
}

void fn_801334F4(int arg0, int arg1, char *arg2, int arg3) {
    void *sp8;
    if (fn_80133E10(&sp8, arg0, arg1) != 0) {
        strncpy(arg2, (char *)sp8 + 0x14, arg3);
        arg2[arg3 - 1] = 0;
    } else {
        fn_8013358C(arg0, arg1, arg2);
    }
}

#pragma push
#pragma peephole on
int fn_8013358C(int arg0, int arg1, char *arg2) {
    void *result;
    int first = arg0;
    int second = arg1;
    fn_80133E10(&result, first, second);
    strncpy((char*)result + 0x14, arg2, 0x10);
    *((char*)result + 0x23) = 0;
    *(int*)((char*)result + 0xC) = fn_801338D8((char*)result + 0x14);
    *(float*)((char*)result + 0x10) = fn_80133960((char*)result + 0x14);
    *((unsigned char*)result + 8) = fn_80133844((char*)result + 0x14);
    *(int*)result = 3;
    if (strlen(arg2) > 15) {
        fn_802E30C8(lbl_8032B8F8, arg2, (char*)result + 0x14);
    }
}
#pragma pop
int fn_80133780(void *arg0, void *arg1) {
    int result = *(int *)((char *)arg0 + 4) - *(int *)((char *)arg1 + 4);
    if (result == 0) result = fn_8002B1D8((char *)arg0 + 0x24, (char *)arg1 + 0x24, 0x13);
    return result;
}

__declspec(section ".data") extern int lbl_802FE850;
static inline int is_line_space(int c) {
    return (c < 0 || c >= 256) ? 0 :
        (*(unsigned short *)(*(int *)(*(int *)((char *)&lbl_802FE850 + 0x38) + 8) + c * 2) & 0x100);
}
extern int lbl_802F9308[];
extern int fn_802E30C8(const char *, ...);
extern double atof(const char *);
extern int fn_8002B1D8(void *, void *, int);
extern int atoi(const char *);
extern int stricmp(const char *, const char *);
char *fn_801337E4(char *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    int table = *(int *)(lbl_802FE850 + 0x38);
    while (*p != 0) {
        int c = (signed char)*p;
        if (c < 0 || c >= 0x100 || !(*(unsigned short *)(*(int *)(table + 8) + c * 2) & 0x100)) return (char *)p;
        p++;
    }
    return (char *)p;
}

int fn_80133844(const char *arg0) {
    int c = (signed char)*fn_801337E4((char *)arg0);
    int table = *(int *)(lbl_802FE850 + 0x38);
    if (c >= 0 && c < 0x100 && (*(unsigned short *)(*(int *)(table + 8) + c * 2) & 8)) return atoi(arg0) != 0;
    return stricmp(arg0, "true") == 0;
}

int fn_801338D8(const char *arg0) {
    unsigned char c = *fn_801337E4((char *)arg0);
    int ch = (signed char)c;
    int isNumber;
    if (ch < 0 || ch >= 0x100) isNumber = 0;
    else {
        int table = *(int *)(lbl_802FE850 + 0x38);
        isNumber = *(unsigned short *)(*(int *)(table + 8) + ch * 2) & 8;
    }
    if (!isNumber && ch != '-') return fn_80133844(arg0);
    return atoi(arg0);
}

extern int fn_802E30C8(const char *, ...);
extern double atof(const char *);
float fn_80133960(const char *arg0) {
    unsigned char c = *fn_801337E4((char *)arg0);
    int ch = (signed char)c;
    int isNumber;
    if (ch < 0 || ch >= 0x100) isNumber = 0;
    else {
        int table = *(int *)(lbl_802FE850 + 0x38);
        isNumber = *(unsigned short *)(*(int *)(table + 8) + ch * 2) & 8;
    }
    if (!isNumber && ((unsigned char)(c - '-') > 1)) return (float)fn_80133844(arg0);
    return (float)atof(arg0);
}

#pragma push
#pragma peephole on
int fn_80133A08(char **arg0, int arg1, char *arg2, int arg3) {
    char *limit;
    char *end;
    char *start;
    char *p;
    int table;
    p = *arg0;
    start = arg2;
    end = p + arg1;
    limit = arg2 + arg3 - 1;
    table = *(int *)((char *)&lbl_802FE850 + 0x38);
test:
    if (p < end) {
        int c = (signed char)*p;
        int invalid = 0;
        int space;
        if (c < 0 || c >= 256) invalid = 1;
        if (invalid) space = 0;
        else space = *(unsigned short *)(*(int *)(table + 8) + c * 2) & 0x100;
        if (space) { p++; goto test; }
    }
    while (p < end && arg2 < limit && (signed char)*p != 13 && (signed char)*p != 10)
        *arg2++ = *p++;
    *arg2 = 0;
    *arg0 = p;
    return arg2 != start;
}
#pragma pop
int fn_80133AD8(int arg0) {
    int values[17];
    int *p = lbl_802F9308;
    int i;
    for (i = 0; i < 16; i++) values[i] = *p++;
    values[16] = *p;
    return values[arg0];
}

extern const char lbl_8032BAE8[];
extern const char lbl_8032B940[];
extern const char lbl_8032B968[];
extern const char lbl_8032B920[];
extern int fn_80133F3C(int);
extern void *memmove(void *, const void *, unsigned int);
void fn_801341B4(int arg0, int arg1) {
    if (arg1 == 0) {
        fn_802E30C8(lbl_8032BAE8, arg0);
        fn_80133F3C(arg0 + 0xC);
    }
}

extern int lbl_8055E07C;
extern int lbl_80559B58;
extern int fn_80133BA0(int, int, int);
extern int fn_80133AD8(int);
extern int fn_802E317C(const char *, ...);
extern const char lbl_8032B8B0[];
extern int lbl_8042F718[];
extern const char lbl_8032B8D0[];
extern int fn_80128668(int);
extern int fn_80133E10(void **, int, int);
extern int fn_8013323C(int, int, float);
