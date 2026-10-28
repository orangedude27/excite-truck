// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void fn_801A90A4(char *, int, const char *);
extern void fn_801A9110(void *, const char *);
// split_file divides it into the game's real files (file_status shows its range).
extern const char *lbl_802F9588[];
struct Entry_801A75B4 { const char *name; char pad[20]; };
typedef struct F801A9050Zero {
    int words[8];
} F801A9050Zero;
extern float fn_801A7F98(void);
extern float lbl_80562470;
extern char lbl_8055A850;
extern void *fn_801A9234(const char *);
extern int lbl_80435050[];
extern unsigned char lbl_80435370[];
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern double lbl_80562450;
extern void fn_80127A84(int *, int *, unsigned int *);
extern int fn_80129AE8(void *, int);
extern void *memset(void *, int, unsigned int);
extern int fn_801A8E38();

extern char lbl_8055E5C8;
#pragma push
#pragma scheduling invalid_target
const char **fn_801A75B4(const char *arg0) {
    const char **entry = (const char **)lbl_802F9588;
    int i = 0;

    do {
        if (stricmp(*entry, arg0) == 0)
            return entry;
        i++;
        entry = (const char **)((char *)entry + 8);
    } while (i < 0x15);
    return 0;
}
#pragma pop
extern signed char fn_802E47F8(int);
extern char lbl_803342D0[];
extern char lbl_8055E5D4;
void fn_801A7628(void) {
    extern const char **lbl_8055E5CC;
    extern int lbl_8055E5D0;
    const char **table;
    int count;
    if ((signed char)lbl_8055E5D4 == 0) {
        *(char *)(lbl_803342D0 + 0x6E8) = fn_802E47F8(0x1E);
        *(char *)(lbl_803342D0 + 0x700) = fn_802E47F8(0x30);
        *(char *)(lbl_803342D0 + 0x718) = fn_802E47F8(0x2E);
        *(char *)(lbl_803342D0 + 0x730) = fn_802E47F8(0x20);
        *(char *)(lbl_803342D0 + 0x748) = fn_802E47F8(0x12);
        *(char *)(lbl_803342D0 + 0x760) = fn_802E47F8(0x21);
        *(char *)(lbl_803342D0 + 0x778) = fn_802E47F8(0x22);
        *(char *)(lbl_803342D0 + 0x790) = fn_802E47F8(0x23);
        *(char *)(lbl_803342D0 + 0x7A8) = fn_802E47F8(0x17);
        *(char *)(lbl_803342D0 + 0x7C0) = fn_802E47F8(0x24);
        *(char *)(lbl_803342D0 + 0x7D8) = fn_802E47F8(0x25);
        *(char *)(lbl_803342D0 + 0x7F0) = fn_802E47F8(0x26);
        *(char *)(lbl_803342D0 + 0x808) = fn_802E47F8(0x32);
        *(char *)(lbl_803342D0 + 0x820) = fn_802E47F8(0x31);
        *(char *)(lbl_803342D0 + 0x838) = fn_802E47F8(0x18);
        *(char *)(lbl_803342D0 + 0x850) = fn_802E47F8(0x10);
        *(char *)(lbl_803342D0 + 0x868) = fn_802E47F8(0x13);
        *(char *)(lbl_803342D0 + 0x880) = fn_802E47F8(0x1F);
        *(char *)(lbl_803342D0 + 0x898) = fn_802E47F8(0x16);
        *(char *)(lbl_803342D0 + 0x8B0) = fn_802E47F8(0x2F);
        *(char *)(lbl_803342D0 + 0x8C8) = fn_802E47F8(0x11);
        *(char *)(lbl_803342D0 + 0x8E0) = fn_802E47F8(0x2D);
        *(char *)(lbl_803342D0 + 0x8F8) = fn_802E47F8(0x15);
        *(char *)(lbl_803342D0 + 0x910) = fn_802E47F8(0x2C);
        *(char *)(lbl_803342D0 + 0x928) = fn_802E47F8(7);
        *(char *)(lbl_803342D0 + 0x940) = fn_802E47F8(8);
        *(char *)(lbl_803342D0 + 0x958) = fn_802E47F8(9);
        *(char *)(lbl_803342D0 + 0x970) = fn_802E47F8(0xA);
        *(char *)(lbl_803342D0 + 0x988) = fn_802E47F8(0xB);
        *(char *)(lbl_803342D0 + 0x9A0) = fn_802E47F8(0x1A);
        *(char *)(lbl_803342D0 + 0x9B8) = fn_802E47F8(0x1B);
        *(char *)(lbl_803342D0 + 0x9D0) = fn_802E47F8(0x27);
        *(char *)(lbl_803342D0 + 0x9E8) = fn_802E47F8(0x28);
        *(char *)(lbl_803342D0 + 0xA00) = fn_802E47F8(0x33);
        *(char *)(lbl_803342D0 + 0xA18) = fn_802E47F8(0x34);
        *(char *)(lbl_803342D0 + 0xA30) = fn_802E47F8(0x35);
        *(char *)(lbl_803342D0 + 0xA48) = fn_802E47F8(0xC);
        *(char *)(lbl_803342D0 + 0xA60) = fn_802E47F8(0xD);
        lbl_8055E5D4 = 1;
    }
    table = (const char **)lbl_803342D0;
    count = 0x7A;
    lbl_8055E5CC = table;
    lbl_8055E5D0 = count;
}

#pragma push
#pragma scheduling invalid_target
void fn_801A7844(int arg0) {
    char *entry;
    int i;
    int sp10;
    int spC;
    unsigned int sp8;
    int a;
    int b;
    float x;
    float y;

    if (arg0 != 0) {
        entry = (char *)lbl_80435050;
        i = 0;
        do {
            memset(entry, 0, 0x64);
            fn_80129AE8(entry, i);
            i++;
            entry += 0x64;
        } while (i < 4);
    }
    fn_80127A84(&sp10, &spC, &sp8);
    a = lbl_8055CFF0 / 2;
    b = lbl_8055CFF4 / 2;
    x = (float)(sp10 - a) / (float)a;
    y = (float)(spC - b) / (float)b;
    lbl_80435370[8] = sp8 & 1;
    lbl_80435370[9] = (sp8 >> 1) & 1;
    lbl_80435370[10] = (sp8 >> 2) & 1;
    *(float *)&lbl_80435370[0] = x;
    *(float *)&lbl_80435370[4] = y;
}
#pragma pop
extern void fn_801334F4(int, int, int *, int);
#pragma push
#pragma scheduling invalid_target
void fn_801A7974(const char *arg0, int arg1, int arg2) {
    F801A9050Zero temp;

    temp.words[0] = 0;
    temp.words[1] = 0;
    temp.words[2] = 0;
    temp.words[3] = 0;
    temp.words[4] = 0;
    temp.words[5] = 0;
    temp.words[6] = 0;
    temp.words[7] = 0;
    fn_801A90A4((char *)&temp, 0x20, arg0);
    fn_801334F4(arg2, arg1, temp.words, 0x20);
    fn_801A9110((void *)arg0, (const char *)&temp);
}
#pragma scheduling on
#pragma pop
extern void fn_801A90A4(char *, int, const char *);
extern int fn_8013358C(int, int, char *);
#pragma push
#pragma scheduling invalid_target
void fn_801A7A08(const char *arg0, int arg1, int arg2) {
    char buffer[0x20];

    fn_801A90A4(buffer, 0x20, arg0);
    fn_8013358C(arg2, arg1, buffer);
}
#pragma pop
extern float lbl_80562458;
void fn_801A7A5C(void) {
    char *base = (char *)lbl_80435050;
    char *src = base;
    char *dst = base + 0x190;
    int i;
    *(float *)(base + 0x320) = lbl_80562458;
    *(float *)(base + 0x324) = lbl_80562458;
    base[0x328] = 0;
    base[0x329] = 0;
    base[0x32a] = 0;
    ((void (*)(int, void *))fn_801A7844)(1, base + 0x320);
    fn_801A7844(1);
    for (i = 0; i < 4; i++) {
        float *sf = (float *)src;
        float *df = (float *)dst;
        int j;
        for (j = 0; j < 8; j++) df[j] = sf[j];
        for (j = 0x20; j < 0x40; j++) dst[j] = src[j];
        for (j = 0x40; j < 0x60; j += 4) *(int *)(dst + j) = *(int *)(src + j);
        dst[0x60] = src[0x60];
        src += 0x64; dst += 0x64;
    }
    *(float *)(base + 0x32c) = *(float *)(base + 0x320);
    *(float *)(base + 0x330) = *(float *)(base + 0x324);
    base[0x334] = base[0x328]; base[0x335] = base[0x329]; base[0x336] = base[0x32a];
}

int fn_801A7C8C(void *arg0) {
    extern const char **lbl_8055E5CC;
    extern int lbl_8055E5D0;
    extern double lbl_80562460;
    extern float lbl_80562468;
    extern void fn_801A91B0(void *, const void *);
    extern int fn_801A8EE4(unsigned int *);
    extern int fn_801A8A10(void *);
    extern float fn_801A85E8(void *);
    int sp8[3];
    unsigned char sp14;
    int i;
    int offset;
    int result;
    float value;
    fn_801A7628();
    result = 0;
    offset = 0;
    for (i = 0; i < lbl_8055E5D0; i++) {
        if (*(unsigned char *)((char *)lbl_8055E5CC + offset + 0x14) == 0) {
            sp8[1] = 0;
            sp14 = 0;
            fn_801A91B0(sp8, (char *)lbl_8055E5CC + offset);
            if (sp8[0] != 5 && sp8[0] != 6) {
                if (fn_801A8EE4((unsigned int *)sp8) != 0) {
                    if (fn_801A8E38() != 0 && fn_801A8A10(sp8) == 0) {
                        *(int *)arg0 = sp8[0];
                        *((int *)arg0 + 1) = sp8[1];
                        *((int *)arg0 + 2) = sp8[2];
                        *((unsigned char *)arg0 + 0xC) = sp14;
                        result = 1;
                        break;
                    }
                } else {
                    value = fn_801A7F98();
                    if (fabsf(fn_801A85E8(sp8)) < lbl_80562460 && value > lbl_80562468) {
                        *(int *)arg0 = sp8[0];
                        *((int *)arg0 + 1) = sp8[1];
                        *((int *)arg0 + 2) = sp8[2];
                        *((unsigned char *)arg0 + 0xC) = sp14;
                        result = 1;
                        break;
                    }
                }
            }
        }
        offset += 0x18;
    }
    return result;
}

void fn_801A9110(void *, const char *);
#pragma dont_inline on
void fn_801A7DFC(int arg0, const char *arg1, int arg2) {
    struct {
        int unk0;
        int unk4;
        char unk8[4];
        char unkC;
    } local;

    local.unk4 = 0;
    local.unkC = 0;
    fn_801A9110(&local, arg1);
    fn_801A7A08((const char *)&local, arg0, arg2);
}
#pragma dont_inline reset

#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_801A7E54(char *dst, int len, const char *name) {
    void *found = fn_801A9234(name);

    if (found != 0) {
        const char **entry = fn_801A75B4(*(const char **)found);
        if (entry != 0) {
            const char *source = entry[1];
            int count;
            char *dest;
            dest = dst;
            count = len;
            while ((signed char)(*dest++ = *source++) != 0) {
                if (--count <= 0) {
                    dest[-1] = 0;
                    break;
                }
            }
        } else {
            int count;
            char *dest;
            const char *source;
            source = *(const char **)((char *)found + 4);
            switch ((int)source) {
            case 0:
                source = (const char *)found + 0x10;
                break;
            }
            dest = dst;
            count = len;
            while ((signed char)(*dest++ = *source++) != 0) {
                if (--count <= 0) {
                    dest[-1] = 0;
                    break;
                }
            }
        }
    } else {
        const char *source = &lbl_8055A850;
        int count;
        char *dest;
        dest = dst;
        count = len;
        while ((signed char)(*dest++ = *source++) != 0) {
            if (--count <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    }
    dst[len - 1] = 0;
}
#pragma cplusplus off
#pragma dont_inline reset

void fn_801A7F8C(void) {
    lbl_8055E5C8 = 0;
}

#pragma scheduling invalid_target
float fn_801A85E8(void *arg0) {
    struct Row {
        float floats[8];
        unsigned char bytes[32];
        unsigned int words[8];
        unsigned char last;
    };
    struct Config {
        float value0;
        float value1;
        unsigned char flags[3];
    };
    struct Row *output;
    struct Config *config;
    char *base;
    struct Row *row;
    struct Row *source;
    volatile char *sourceBase;
    struct Config *active;
    struct Row snapshot;
    union { unsigned int words[3]; float values[2]; unsigned char bytes[12]; } saved;
    unsigned int index;
    float result;
    float copyF0, copyF1;
    unsigned char copyB0, copyB1;
    unsigned int copyW0, copyW1;

    if (*(int *)arg0 == 1)
        return lbl_80562458;

    base = (char *)lbl_80435050;
    index = *(int *)((char *)arg0 + 4);
    row = (struct Row *)(base + index * 0x64);
    snapshot = *row;
    output = (struct Row *)((char *)lbl_80435050 + index * 0x64);
    sourceBase = (volatile char *)base + 0x190;
    source = (struct Row *)(sourceBase + index * 0x64);
    row->floats[0] = *(volatile float *)(sourceBase + index * 0x64);
    copyF0 = source->floats[1];
    copyF1 = source->floats[2];
    output->floats[1] = copyF0;
    copyF0 = source->floats[3];
    output->floats[2] = copyF1;
    copyF1 = source->floats[4];
    output->floats[3] = copyF0;
    copyF0 = source->floats[5];
    output->floats[4] = copyF1;
    copyF1 = source->floats[6];
    output->floats[5] = copyF0;
    copyF0 = source->floats[7];
    output->floats[6] = copyF1;
    output->floats[7] = copyF0;

    copyB0 = source->bytes[0];
    copyB1 = source->bytes[1];
    output->bytes[0] = copyB0;
    copyB0 = source->bytes[2];
    output->bytes[1] = copyB1;
    copyB1 = source->bytes[3];
    output->bytes[2] = copyB0;
    copyB0 = source->bytes[4];
    output->bytes[3] = copyB1;
    copyB1 = source->bytes[5];
    output->bytes[4] = copyB0;
    copyB0 = source->bytes[6];
    output->bytes[5] = copyB1;
    copyB1 = source->bytes[7];
    output->bytes[6] = copyB0;
    copyB0 = source->bytes[8];
    output->bytes[7] = copyB1;
    copyB1 = source->bytes[9];
    output->bytes[8] = copyB0;
    copyB0 = source->bytes[10];
    output->bytes[9] = copyB1;
    copyB1 = source->bytes[11];
    output->bytes[10] = copyB0;
    copyB0 = source->bytes[12];
    output->bytes[11] = copyB1;
    copyB1 = source->bytes[13];
    output->bytes[12] = copyB0;
    copyB0 = source->bytes[14];
    output->bytes[13] = copyB1;
    copyB1 = source->bytes[15];
    output->bytes[14] = copyB0;
    copyB0 = source->bytes[16];
    output->bytes[15] = copyB1;
    copyB1 = source->bytes[17];
    output->bytes[16] = copyB0;
    copyB0 = source->bytes[18];
    output->bytes[17] = copyB1;
    copyB1 = source->bytes[19];
    output->bytes[18] = copyB0;
    copyB0 = source->bytes[20];
    output->bytes[19] = copyB1;
    copyB1 = source->bytes[21];
    output->bytes[20] = copyB0;
    copyB0 = source->bytes[22];
    output->bytes[21] = copyB1;
    copyB1 = source->bytes[23];
    output->bytes[22] = copyB0;
    copyB0 = source->bytes[24];
    output->bytes[23] = copyB1;
    copyB1 = source->bytes[25];
    output->bytes[24] = copyB0;
    copyB0 = source->bytes[26];
    output->bytes[25] = copyB1;
    copyB1 = source->bytes[27];
    output->bytes[26] = copyB0;
    copyB0 = source->bytes[28];
    output->bytes[27] = copyB1;
    copyB1 = source->bytes[29];
    output->bytes[28] = copyB0;
    copyB0 = source->bytes[30];
    output->bytes[29] = copyB1;
    copyB1 = source->bytes[31];
    output->bytes[30] = copyB0;
    output->bytes[31] = copyB1;

    copyW0 = source->words[0];
    copyW1 = source->words[1];
    output->words[0] = copyW0;
    copyW0 = source->words[2];
    output->words[1] = copyW1;
    copyW1 = source->words[3];
    output->words[2] = copyW0;
    copyW0 = source->words[4];
    output->words[3] = copyW1;
    copyW1 = source->words[5];
    output->words[4] = copyW0;
    copyW0 = source->words[6];
    output->words[5] = copyW1;
    copyW1 = source->words[7];
    output->words[6] = copyW0;
    output->words[7] = copyW1;

    output->last = source->last;

    config = (struct Config *)(base + 0x320);
    active = (struct Config *)(base + 0x32C);
    saved.words[0] = *(unsigned int *)config;
    saved.words[1] = *((unsigned int *)config + 1);
    saved.words[2] = *((unsigned int *)config + 2);
    config->value0 = active->value0;
    config->value1 = active->value1;
    config->flags[0] = active->flags[0];
    config->flags[1] = active->flags[1];
    config->flags[2] = active->flags[2];

    result = fn_801A7F98();
    row->floats[0] = snapshot.floats[0];
    copyF0 = snapshot.floats[1];
    copyF1 = snapshot.floats[2];
    output->floats[1] = copyF0;
    copyF0 = snapshot.floats[3];
    output->floats[2] = copyF1;
    copyF1 = snapshot.floats[4];
    output->floats[3] = copyF0;
    copyF0 = snapshot.floats[5];
    output->floats[4] = copyF1;
    copyF1 = snapshot.floats[6];
    output->floats[5] = copyF0;
    copyF0 = snapshot.floats[7];
    output->floats[6] = copyF1;
    output->floats[7] = copyF0;

    copyB0 = snapshot.bytes[0];
    copyB1 = snapshot.bytes[1];
    output->bytes[0] = copyB0;
    copyB0 = snapshot.bytes[2];
    output->bytes[1] = copyB1;
    copyB1 = snapshot.bytes[3];
    output->bytes[2] = copyB0;
    copyB0 = snapshot.bytes[4];
    output->bytes[3] = copyB1;
    copyB1 = snapshot.bytes[5];
    output->bytes[4] = copyB0;
    copyB0 = snapshot.bytes[6];
    output->bytes[5] = copyB1;
    copyB1 = snapshot.bytes[7];
    output->bytes[6] = copyB0;
    copyB0 = snapshot.bytes[8];
    output->bytes[7] = copyB1;
    copyB1 = snapshot.bytes[9];
    output->bytes[8] = copyB0;
    copyB0 = snapshot.bytes[10];
    output->bytes[9] = copyB1;
    copyB1 = snapshot.bytes[11];
    output->bytes[10] = copyB0;
    copyB0 = snapshot.bytes[12];
    output->bytes[11] = copyB1;
    copyB1 = snapshot.bytes[13];
    output->bytes[12] = copyB0;
    copyB0 = snapshot.bytes[14];
    output->bytes[13] = copyB1;
    copyB1 = snapshot.bytes[15];
    output->bytes[14] = copyB0;
    copyB0 = snapshot.bytes[16];
    output->bytes[15] = copyB1;
    copyB1 = snapshot.bytes[17];
    output->bytes[16] = copyB0;
    copyB0 = snapshot.bytes[18];
    output->bytes[17] = copyB1;
    copyB1 = snapshot.bytes[19];
    output->bytes[18] = copyB0;
    copyB0 = snapshot.bytes[20];
    output->bytes[19] = copyB1;
    copyB1 = snapshot.bytes[21];
    output->bytes[20] = copyB0;
    copyB0 = snapshot.bytes[22];
    output->bytes[21] = copyB1;
    copyB1 = snapshot.bytes[23];
    output->bytes[22] = copyB0;
    copyB0 = snapshot.bytes[24];
    output->bytes[23] = copyB1;
    copyB1 = snapshot.bytes[25];
    output->bytes[24] = copyB0;
    copyB0 = snapshot.bytes[26];
    output->bytes[25] = copyB1;
    copyB1 = snapshot.bytes[27];
    output->bytes[26] = copyB0;
    copyB0 = snapshot.bytes[28];
    output->bytes[27] = copyB1;
    copyB1 = snapshot.bytes[29];
    output->bytes[28] = copyB0;
    copyB0 = snapshot.bytes[30];
    output->bytes[29] = copyB1;
    copyB1 = snapshot.bytes[31];
    output->bytes[30] = copyB0;
    output->bytes[31] = copyB1;

    copyW0 = snapshot.words[0];
    copyW1 = snapshot.words[1];
    output->words[0] = copyW0;
    copyW0 = snapshot.words[2];
    output->words[1] = copyW1;
    copyW1 = snapshot.words[3];
    output->words[2] = copyW0;
    copyW0 = snapshot.words[4];
    output->words[3] = copyW1;
    copyW1 = snapshot.words[5];
    output->words[4] = copyW0;
    copyW0 = snapshot.words[6];
    output->words[5] = copyW1;
    copyW1 = snapshot.words[7];
    output->words[6] = copyW0;
    output->words[7] = copyW1;

    output->last = snapshot.last;
    config->value0 = saved.values[0];
    config->value1 = saved.values[1];
    config->flags[0] = saved.bytes[8];
    config->flags[1] = saved.bytes[9];
    config->flags[2] = saved.bytes[10];
    return result;
}
#pragma scheduling on
int fn_801A8A10(void *arg0) {
struct Row {
float floats[8];
unsigned char bytes[32];
unsigned int words[8];
unsigned char last;
};
struct Config {
float value0;
float value1;
unsigned char flags[3];
};
struct Row *output;
struct Config *config;
volatile char *base;
struct Row *row;
struct Row *source;
volatile char *sourceBase;
struct Config *active;
struct Row snapshot;
union { unsigned int words[3]; float values[2]; unsigned char bytes[12]; } saved;
int index;
int result;

if (*(int *)arg0 == 1)
return 0;

base = (volatile char *)lbl_80435050;
index = ((int *)arg0)[1];
row = (struct Row *)(base + index * 0x64);
snapshot = *row;
output = (struct Row *)(base + index * 0x64);
sourceBase = (volatile char *)lbl_80435050 + 0x190;
source = (struct Row *)(sourceBase + index * 0x64);
row->floats[0] = *(volatile float *)(sourceBase + index * 0x64);
output->floats[1] = source->floats[1];
output->floats[2] = source->floats[2];
output->floats[3] = source->floats[3];
output->floats[4] = source->floats[4];
output->floats[5] = source->floats[5];
output->floats[6] = source->floats[6];
output->floats[7] = source->floats[7];
output->bytes[0] = source->bytes[0];
output->bytes[1] = source->bytes[1];
output->bytes[2] = source->bytes[2];
output->bytes[3] = source->bytes[3];
output->bytes[4] = source->bytes[4];
output->bytes[5] = source->bytes[5];
output->bytes[6] = source->bytes[6];
output->bytes[7] = source->bytes[7];
output->bytes[8] = source->bytes[8];
output->bytes[9] = source->bytes[9];
output->bytes[10] = source->bytes[10];
output->bytes[11] = source->bytes[11];
output->bytes[12] = source->bytes[12];
output->bytes[13] = source->bytes[13];
output->bytes[14] = source->bytes[14];
output->bytes[15] = source->bytes[15];
output->bytes[16] = source->bytes[16];
output->bytes[17] = source->bytes[17];
output->bytes[18] = source->bytes[18];
output->bytes[19] = source->bytes[19];
output->bytes[20] = source->bytes[20];
output->bytes[21] = source->bytes[21];
output->bytes[22] = source->bytes[22];
output->bytes[23] = source->bytes[23];
output->bytes[24] = source->bytes[24];
output->bytes[25] = source->bytes[25];
output->bytes[26] = source->bytes[26];
output->bytes[27] = source->bytes[27];
output->bytes[28] = source->bytes[28];
output->bytes[29] = source->bytes[29];
output->bytes[30] = source->bytes[30];
output->bytes[31] = source->bytes[31];
output->words[0] = source->words[0];
output->words[1] = source->words[1];
output->words[2] = source->words[2];
output->words[3] = source->words[3];
output->words[4] = source->words[4];
output->words[5] = source->words[5];
output->words[6] = source->words[6];
output->words[7] = source->words[7];
output->last = source->last;

config = (struct Config *)(base + 0x320);
active = (struct Config *)(base + 0x32C);
saved.words[0] = ((unsigned int *)config)[0];
saved.words[1] = ((unsigned int *)config)[1];
saved.words[2] = ((unsigned int *)config)[2];
config->value0 = active->value0;
config->value1 = active->value1;
config->flags[0] = active->flags[0];
config->flags[1] = active->flags[1];
config->flags[2] = active->flags[2];

result = fn_801A8E38();
row->floats[0] = snapshot.floats[0];
output->floats[1] = snapshot.floats[1];
output->floats[2] = snapshot.floats[2];
output->floats[3] = snapshot.floats[3];
output->floats[4] = snapshot.floats[4];
output->floats[5] = snapshot.floats[5];
output->floats[6] = snapshot.floats[6];
output->floats[7] = snapshot.floats[7];
output->bytes[0] = snapshot.bytes[0];
output->bytes[1] = snapshot.bytes[1];
output->bytes[2] = snapshot.bytes[2];
output->bytes[3] = snapshot.bytes[3];
output->bytes[4] = snapshot.bytes[4];
output->bytes[5] = snapshot.bytes[5];
output->bytes[6] = snapshot.bytes[6];
output->bytes[7] = snapshot.bytes[7];
output->bytes[8] = snapshot.bytes[8];
output->bytes[9] = snapshot.bytes[9];
output->bytes[10] = snapshot.bytes[10];
output->bytes[11] = snapshot.bytes[11];
output->bytes[12] = snapshot.bytes[12];
output->bytes[13] = snapshot.bytes[13];
output->bytes[14] = snapshot.bytes[14];
output->bytes[15] = snapshot.bytes[15];
output->bytes[16] = snapshot.bytes[16];
output->bytes[17] = snapshot.bytes[17];
output->bytes[18] = snapshot.bytes[18];
output->bytes[19] = snapshot.bytes[19];
output->bytes[20] = snapshot.bytes[20];
output->bytes[21] = snapshot.bytes[21];
output->bytes[22] = snapshot.bytes[22];
output->bytes[23] = snapshot.bytes[23];
output->bytes[24] = snapshot.bytes[24];
output->bytes[25] = snapshot.bytes[25];
output->bytes[26] = snapshot.bytes[26];
output->bytes[27] = snapshot.bytes[27];
output->bytes[28] = snapshot.bytes[28];
output->bytes[29] = snapshot.bytes[29];
output->bytes[30] = snapshot.bytes[30];
output->bytes[31] = snapshot.bytes[31];
output->words[0] = snapshot.words[0];
output->words[1] = snapshot.words[1];
output->words[2] = snapshot.words[2];
output->words[3] = snapshot.words[3];
output->words[4] = snapshot.words[4];
output->words[5] = snapshot.words[5];
output->words[6] = snapshot.words[6];
output->words[7] = snapshot.words[7];
output->last = snapshot.last;
config->value0 = saved.values[0];
config->value1 = saved.values[1];
config->flags[0] = saved.bytes[8];
config->flags[1] = saved.bytes[9];
config->flags[2] = saved.bytes[10];
return result;
}
#pragma scheduling on

#pragma scheduling on
int fn_801A8E38(void) {
    return fn_801A7F98() > lbl_80562470;
}

int fn_801A8E68(void *arg0) {
    int state = *(int *)arg0;
    if (state >= 7)
        return 0;
    if (state < 1)
        return 0;
    if (fn_801A8E38() == 0) {
        *(unsigned char *)((char *)arg0 + 0xC) = 0;
        return 0;
    }
    if (*(unsigned char *)((char *)arg0 + 0xC) != 0)
        return 0;
    *(unsigned char *)((char *)arg0 + 0xC) = 1;
    return 1;
}

#pragma push
#pragma scheduling invalid_target
int fn_801A8EE4(unsigned int *arg0) {
    unsigned int value = *arg0 - 1;
    int result = 0;
    if (value > 5)
        goto done;
    if (!((1U << value) & 0x2D))
        goto done;
    result = 1;
done:
    return result;
}
#pragma push
#pragma processor 750
int fn_801A8F10(int *arg0) {
    struct Struct16 {
        unsigned int a;
        unsigned int b;
        unsigned int c;
        unsigned int d;
    };
    struct Entry {
        unsigned char pad[0x44];
        struct Struct16 flags;
        unsigned char pad2[0x64 - 0x54];
    };
    extern char lbl_80334EE0[];
    extern void fn_802E317C(const char *, ...);

    int state = arg0[0];
    int idx = arg0[1];
    struct Entry *entry = &((struct Entry *)lbl_80435050)[idx];
    struct Struct16 flags = entry->flags;

    if (state == 4) {
        return (flags.a >> 15) & 1;
    }
    if (state == 3) {
        unsigned int bit = flags.b & (1 << arg0[2]);
        return (unsigned int)(-bit | bit) >> 31;
    }
    if (state == 2) {
        unsigned int axis = arg0[2];
        switch (axis) {
        case 0:
        case 1:
        case 16:
        case 24:
            return flags.a & 1;
        case 2:
        case 3:
        case 17:
        case 25:
            return (flags.a >> 1) & 1;
        case 4:
        case 5:
        case 18:
        case 26:
            return (flags.a >> 3) & 1;
        case 6:
        case 7:
        case 19:
        case 27:
            return (flags.a >> 2) & 1;
        case 8:
        case 9:
        case 20:
        case 28:
            return (flags.a >> 4) & 1;
        case 10:
        case 11:
        case 21:
        case 29:
            return (flags.a >> 5) & 1;
        case 12:
        case 13:
        case 22:
        case 30:
            return (flags.a >> 6) & 1;
        case 14:
        case 15:
        case 23:
        case 31:
            return (flags.a >> 7) & 1;
        default:
            fn_802E317C(lbl_80334EE0, arg0[2]);
            return 0;
        }
    }
    return (unsigned int)(-state | state) >> 31;
}
#pragma pop
extern void fn_801A7628(void);
extern void fn_801A9110(void *, const char *);
extern void *fn_801A9234(const char *);
extern void fn_801A91B0(void *, const void *);
extern int stricmp(const char *, const char *);
extern const char *lbl_802F9588[];
extern const char **lbl_8055E5CC;
extern int lbl_8055E5D0;
extern char *strncpy(char *, const char *, unsigned int);
int fn_801A902C(void) {
    fn_801A7628();
    return 0x15;
}

void fn_801A9050(void *arg0, int arg1) {
    F801A9050Zero zero = {{0}};
    const char **table = (const char **)lbl_802F9588;
    const char *name = *(const char **)((char *)table + arg1 * 8);

    ((void (*)(void *, const char *, const char **, int, F801A9050Zero))fn_801A9110)(
        arg0, name, table, 0, zero);
}

void fn_801A90A4(char *arg0, int arg1, const char *arg2) {
    const char **entry = (const char **)fn_801A9234(arg2);
    if (entry != 0)
        strncpy(arg0, *entry, arg1);
    else
        arg0[0] = 0;
    arg0[arg1 - 1] = 0;
}

void fn_801A9110(void *arg0, const char *arg1) {
    int i;
    int offset;
    fn_801A7628();
    i = 0;
    offset = 0;
    for (i = 0; i < lbl_8055E5D0; i++) {
        if (stricmp(*(const char **)((char *)lbl_8055E5CC + offset), arg1) == 0) {
            fn_801A91B0(arg0, (char *)lbl_8055E5CC + i * 0x18);
            return;
        }
        offset += 0x18;
    }
    *(int *)arg0 = 0;
}

void fn_801A91B0(void *arg0, const void *arg1) {
    int state = *(const int *)((const char *)arg1 + 8);
    *(int *)arg0 = state;
    switch (state) {
    case 2:
    case 3:
    case 5:
    case 6:
    case 4:
        *(int *)((char *)arg0 + 8) = *(const int *)((const char *)arg1 + 0xC);
        return;
    case 1:
        *(unsigned char *)((char *)arg0 + 8) = *(const unsigned char *)((const char *)arg1 + 0xC);
        return;
    }
}

void *fn_801A9234(const char *arg0) {
    extern int lbl_8055E5D0;
    extern const char **lbl_8055E5CC;
    const char *entry;
    const char **base;
    int count;
    int i;
    int type;

    fn_801A7628();
    count = lbl_8055E5D0;
    base = lbl_8055E5CC;
    for (i = 0, entry = (const char *)base; i < count; entry += 0x18, i++) {
        type = *(int *)arg0;
        if (type == *(int *)(entry + 8)) {
            switch (type) {
            case 4: goto check_word_a;
            case 2: goto check_word_b;
            case 3: goto check_word_c;
            case 5: goto check_word_d;
            case 6: goto check_word_e;
            case 1: goto check_byte;
            default: goto next;
            }
check_word_a:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_word_b:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_word_c:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_word_d:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_word_e:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_byte:
            if (*(unsigned char *)(arg0 + 8) == (unsigned char)*(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
        }
next:
        ;
    }
    return 0;
}

