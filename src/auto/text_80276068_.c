// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055F598, lbl_8055F59C, lbl_8055F5A0;
extern unsigned char lbl_8049FD58;
extern float lbl_8055E3C8, lbl_80564054, lbl_80564060;
extern float lbl_8049FD58_float_dummy;
extern void *fn_80276A44(void);
extern void fn_8026A4A0(int, void *, float *);
extern void fn_80276098(void *, void *, float, float, float, int, int);
extern void *memcpy(void *, const void *, unsigned int);
int fn_80276068(int arg0) {
    unsigned int shift = arg0 - 4;
    int result = 0;
    if (shift > 0x13)
        return result;
    if (((1U << shift) & 0x80027) != 0)
        result = 1;
    return result;
}

extern unsigned char lbl_8049FEE0;
extern char lbl_8055C638, lbl_8055C63C, lbl_8055C644;
extern void fn_80277F84(void *, void *, int);
extern int stricmp(const char *, const char *);
extern char *strncpy(char *, const char *, unsigned int);
void fn_80276ACC(void *arg0, int arg1) {
    char *name = (*(char * (**)(void *, const char *, int))((char *)*(void **)arg0 + 0x18))(arg0, &lbl_8055C63C, arg1);
    int i = lbl_8055F5A0;
    unsigned char *entry = &lbl_8049FEE0 + i * 0x48;
    lbl_8055F5A0 = i + 1;
    fn_80277F84(entry, arg0, i + 1);
    strncpy((char *)(entry + 0x38), name, 0x10);
    if (stricmp(name, &lbl_8055C644) == 0) {
        lbl_8055F59C = (int)entry;
        return;
    }
    if (stricmp(name, &lbl_8055C638) == 0)
        lbl_8055F598 = (int)entry;
}

void fn_80276B8C(void) {
    unsigned char *entry = &lbl_8049FD58;
    int i = 0;
    do {
        memset(entry, 0, 0x50);
        i++;
        entry += 0x50;
    } while (i < 4);
}

typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
u32 fn_8027656C(void *, void *, u32);
extern u8 lbl_8049FD58;
extern u8 lbl_8049FE98[];
__declspec(section ".data") extern u8 lbl_8049FD58;
void fn_80276BE4(u32 *arg0, f32 *arg1) {
    u32 *src;
    if (lbl_8049FD58 != 0) {
        fn_8027656C(lbl_8049FE98 + 4, lbl_8049FE98 + 0x34, 0);
    }
    src = (u32 *)(lbl_8049FE98 + 4);
    arg0[0] = src[0]; arg0[1] = src[1];
    arg0[2] = src[2]; arg0[3] = src[3];
    arg0[4] = src[4]; arg0[5] = src[5];
    arg0[6] = src[6]; arg0[7] = src[7];
    arg0[8] = src[8]; arg0[9] = src[9];
    arg0[10] = src[10]; arg0[11] = src[11];
    *arg1 = *(f32 *)(lbl_8049FE98 + 0x34);
}

void fn_80276D3C(int unused, int arg) {
    unsigned char sp10[0x38];
    float sp8;
    unsigned char *p = (unsigned char *)fn_80276A44();
    if (arg == 1) {
        fn_8026A4A0(0, sp10, &sp8);
        fn_80276098(sp10, p + 4, sp8, *(float *)(p + 0x34), lbl_80564060, 0, 0x22);
    } else {
        memcpy(lbl_8049FE98, p, 0x48);
        lbl_8049FD58 = 0;
    }
}

float fn_80277704(int i) {
    unsigned char *p = (unsigned char *)&lbl_8049FD58 + i * 0x50;
    if (*p != 0) {
        float *f = (float *)p;
        return (lbl_8055E3C8 - f[0x48 / 4]) / f[0x44 / 4];
    }
    return lbl_80564054;
}

void fn_80277740(void) {
    lbl_8055F5A0 = 0;
    lbl_8055F598 = 0;
    lbl_8055F59C = 0;
}

extern char lbl_8055C650;
extern char lbl_803473B8[], lbl_803473C4[];
#pragma dont_inline on
int fn_80277754(void *arg0) {
    char *name;
    name = (*(char * (**)(void *))((char *)*(void **)arg0 + 8))(arg0);
    if (stricmp(name, &lbl_8055C650) == 0) {
        fn_80276ACC(arg0, *(int *)&lbl_8055C638);
        goto done;
    }
    name = (*(char * (**)(void *))((char *)*(void **)arg0 + 8))(arg0);
    if (stricmp(name, &lbl_8055C644) == 0) {
        fn_80276ACC(arg0, (int)&lbl_8055C644);
        goto done;
    }
    name = (*(char * (**)(void *))((char *)*(void **)arg0 + 8))(arg0);
    if (stricmp(name, (const char *)&lbl_803473B8) == 0) {
        fn_80276ACC(arg0, (int)&lbl_803473C4);
        goto done;
    }
    return 0;
done:
    return 1;
}
#pragma dont_inline reset
int fn_80277960(void *arg0, void *arg1, float *arg2) {
    unsigned char *p = (unsigned char *)fn_80276A44();
    if (p != 0) {
        unsigned int *dst = (unsigned int *)arg1;
        unsigned int *src = (unsigned int *)(p + 4);
        dst[0] = src[0]; dst[1] = src[1];
        dst[2] = src[2]; dst[3] = src[3];
        dst[4] = src[4]; dst[5] = src[5];
        dst[6] = src[6]; dst[7] = src[7];
        dst[8] = src[8]; dst[9] = src[9];
        dst[10] = src[10]; dst[11] = src[11];
        *arg2 = *(float *)(p + 0x34);
        return 1;
    }
    return 0;
}

