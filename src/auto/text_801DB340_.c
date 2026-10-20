// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562B70;
extern float lbl_80562BB8;
extern int lbl_80446F08[];
extern int lbl_8055E990;
extern void (*lbl_8055E994)(int);
extern char lbl_8055E9A4;
extern int lbl_8055E998;
extern int lbl_80339468;
extern unsigned char lbl_80446F18[];
extern int fn_801DC258(float *, int *, short *, float, float);
extern int fn_80128670(void);
extern int fn_801D049C(void);
extern int lbl_8055E99C;
extern int lbl_8055E9A0;
extern unsigned short lbl_80442708[];
extern float lbl_804424B0[];
extern int fn_801DB348(int, int, float *, int *);
extern float fn_801DB398(float grid[4][4], float, float);
extern float fn_801DB514(float grid[4][4], void *, float, float);

static inline int sample_tile(int x, int y, float *out_h, int *out_type, void *arg4) {
    int tileX, tileZ, remX, remZ;
    char *node;
    char *layer;
    unsigned char *type_p;
    int tile, next, sum;
    float h;

    if (x < 0 || y < 0) {
        return 0;
    }
    if (*(int *)((char *)lbl_8055E990 + 0x10) == 0) {
        return fn_801DB348(x, y, out_h, out_type);
    }
    tileX = (x / 32) - lbl_8055E99C;
    tileZ = (y / 32) - lbl_8055E9A0;
    remX = x - (x / 32) * 32;
    remZ = y - (y / 32) * 32;
    if (tileX >= 0 && tileZ >= 0 && tileX < 0x60 && tileZ < 0x60) {
        tile = ((unsigned short (*)[0x60])lbl_80442708)[tileX][tileZ];
        if (tile != 0xFFFF) {
            node = *(char **)((char *)lbl_8055E990 + 0x18) + tile * 0x894;
        } else {
            node = 0;
        }
    } else {
        node = 0;
    }
    if (node == 0) {
        return 0;
    }
    h = *(float *)(node + 0) + *(float *)(node + 4) * (float)*(unsigned short *)(node + (remX * 64 + remZ * 2) + 8);
    next = *(int *)(node + 0x890);
    if (next >= 0) {
        do {
            layer = *(char **)((char *)lbl_8055E990 + 0x20) + next * 0x810;
            h += lbl_804424B0[*(int *)(layer + 0x808)] * (*(float *)(layer + 0) + *(float *)(layer + 4) * (float)*(unsigned short *)(layer + (remX * 64 + remZ * 2) + 8));
            next = *(int *)(layer + 0x80C);
        } while (next >= 0);
    }
    type_p = *(unsigned char **)((char *)lbl_8055E990 + 0x30) + *(int *)(node + 0x810 + remZ * 4);
    sum = 0;
    while (sum + type_p[1] <= remX) {
        sum += type_p[1];
        type_p += 2;
    }
    if (type_p[0] != 0xFF) {
        *out_h = h;
        if (out_type != 0) {
            *out_type = type_p[0];
        }
        return 1;
    }
    return 0;
}

void fn_801DB340(int arg0) { fn_801DB13C(arg0 - 4); }

int fn_801DB348(int arg0, int arg1, float *arg2, int *arg3) {
    int width, height;
    float *data;

    if (arg3 != 0) {
        *arg3 = 0;
    }
    width = lbl_80446F08[0];
    height = lbl_80446F08[1];
    data = (float *)lbl_80446F08[2];

    arg1 = (arg1 & (height - 1)) * width;
    arg0 = (arg0 & (width - 1)) + arg1;
    *arg2 = data[arg0];
    return 1;
}

#pragma paired_single off
int fn_801DB74C(int arg0, int arg1, float *arg2, int *arg3, void *arg4, void *arg5, float farg0, float farg1) {
    float grid[4][4];
    float sp8;
    int i, j;

    if (!sample_tile(arg0, arg1, &sp8, arg3, arg4) &&
        !sample_tile(arg0 + 1, arg1, &sp8, arg3, arg4) &&
        !sample_tile(arg0, arg1 + 1, &sp8, arg3, arg4) &&
        !sample_tile(arg0 + 1, arg1 + 1, &sp8, arg3, arg4)) {
        return 0;
    }

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            if (!sample_tile(arg0 - 1 + i, arg1 - 1 + j, &grid[i][j], 0, 0)) {
                grid[i][j] = sp8;
            }
        }
    }

    if (arg5 != 0) {
        *arg2 = fn_801DB514(grid, arg5, farg0, farg1);
    } else {
        *arg2 = fn_801DB398(grid, farg0, farg1);
    }
    return 1;
}
#pragma paired_single reset
void fn_801DCA5C(void) {
    fn_8012C4D8();
}

void fn_801DCD24(void) {
    fn_80128668();
}

void fn_801DCDA0(void) {

}

void fn_801DCDA4(void) {
    if (*(volatile int *)((char *)lbl_80446F08 + 8)) {
        fn_80128670();
        *(volatile int *)((char *)lbl_80446F08 + 8) = 0;
    }
    lbl_8055E994(lbl_8055E990);
    lbl_8055E994 = 0;
    lbl_8055E990 = 0;
    lbl_8055E9A4 = 0;
    fn_801D049C();
}

void fn_801DCE0C(void) {
    fn_801DCD28();
}

void fn_801DCE10(void) {

}

int fn_801DCE14(short *arg0, float *arg1, float *arg2, int arg3, int *arg4) {
    float spC;
    int sp8;

    if (arg0 != 0) {
        *arg0 = 0;
    }
    sp8 = 0xFF;
    if (((int (*)(void *, void *, void *, void *, float, float))fn_801DC258)(&spC, &sp8, arg0, (void *)arg3, arg1[0], arg1[2]) != 0) {
        if (arg4 != 0) {
            *arg4 = sp8;
        }
        arg2[1] = spC;
        arg2[0] = arg1[0];
        arg2[2] = arg1[2];
        return 1;
    }
    return 0;
}

float fn_801DCEC0(void) {
    return lbl_80562B70;
}

extern float lbl_804424B0[];
void fn_801DCEC8(int arg0, float arg1) {
    lbl_804424B0[arg0] = arg1;
}

extern float lbl_804425DC[];
void fn_801DCEDC(int arg0, float arg1) {
    lbl_804425DC[arg0] = arg1;
}

void fn_801DCEF0(void) {

}

extern void *lbl_8055E9A8;
void fn_801DCEF4(void) {
    lbl_8055E9A8 = 0;
}

extern void *lbl_8055E9A8;
void fn_801DCF00(void) {
    lbl_8055E9A8 = 0;
}

float fn_801DCF0C(void) {
    volatile float sp8 = lbl_80562BB8;
    ((int (*)(float *, int, int, int))fn_801DC258)((float *)&sp8, 0, 0, 0);
    return sp8;
}

extern int fn_801DC9B0(void);
extern int fn_801DCA60(void);
extern void fn_802E30C8(const char *, ...);
extern void fn_801D02B0(void);
void fn_801DD808(void) {
    unsigned char *entry = lbl_80446F18;
    int i = 0;
    do {
        int index0 = *(int *)(entry + 8);
        int index1 = *(int *)(entry + 0x10);
        int index2 = *(int *)(entry + 0x18);
        float value = *(float *)(entry + 4);
        value += *(float *)(entry + 0xC) * lbl_804424B0[index0];
        value += *(float *)(entry + 0x14) * lbl_804424B0[index1];
        value += *(float *)(entry + 0x1C) * lbl_804424B0[index2];
        *(float *)*(int *)entry = value;
        entry += 0x20;
        i++;
    } while (i < (int)lbl_8055E9A8);
}

extern int lbl_8055E99C;
extern int lbl_8055E9A0;
extern unsigned short lbl_80442708[];
extern float lbl_80562B64, lbl_80562B84, lbl_80562B78;
int fn_801DDA84(int *arg0, int arg1, float farg0, float farg1, float farg2) {
    int *state = (int *)lbl_8055E990;
    int ix, iz, tileX, tileZ, remX, remZ;
    int tile, node, count = 0, offset = 0;
    float x, z;
    float roundX, roundZ;
    float *map;

    if (state[4] == 0)
        return 0;
    x = farg0 + *(float *)((char *)state + 0);
    z = farg1 + *(float *)((char *)state + 4);
    x *= *(float *)((char *)state + 8);
    z *= *(float *)((char *)state + 12);
    roundX = x < lbl_80562B84 ? x - lbl_80562B64 : lbl_80562B64 + x;
    roundZ = z < lbl_80562B84 ? z - lbl_80562B64 : lbl_80562B64 + z;
    ix = (int)roundX;
    iz = (int)roundZ;
    if (ix < 0 || iz < 0)
        return 0;
    tileX = (ix >> 5) - lbl_8055E99C;
    tileZ = (iz >> 5) - lbl_8055E9A0;
    remX = ix - (tileX + lbl_8055E99C) * 32;
    remZ = iz - (tileZ + lbl_8055E9A0) * 32;
    if (tileX < 0 || tileZ < 0 || tileX >= 0x60 || tileZ >= 0x60)
        return 0;
    tile = lbl_80442708[tileX * 0x60 + tileZ];
    if (tile == 0xFFFF)
        return 0;
    node = *(int *)(*(int *)((char *)state + 0x18) + tile * 0x894);
    if (node == 0)
        return 0;
    if (*(int *)((char *)node + 0x890) < 0)
        return 0;
    map = (float *)(*(int *)((char *)state + 0x20) + *(int *)((char *)node + 0x890) * 0x810);
    do {
        unsigned short value = *(unsigned short *)((char *)map + (remX * 64 + remZ * 2) + 8);
        float h = fabsf(map[1] * ((float)value - lbl_80562B78) + map[0]);
        if (h < farg2 && count < arg1) {
            arg0[count++] = *(int *)((char *)map + 0x808);
        }
        node = *(int *)((char *)map + 0x80C);
        if (node < 0)
            break;
        map = (float *)(*(int *)((char *)lbl_8055E990 + 0x20) + node * 0x810);
    } while (1);
    return count;
}

extern float lbl_80562B70;
extern float lbl_80562BB8;
extern int fn_801DC258(float *, int *, short *, float, float);
extern int fn_80128670(void);
extern int fn_801D049C(void);
extern int lbl_80446F08[];
extern int lbl_8055E990;
extern void (*lbl_8055E994)(int);
extern char lbl_8055E9A4;
