// Code of main that had no source file yet: decomp.wtf gave it this one.
extern float lbl_80562754;
extern float lbl_80562758;
extern float lbl_8056275C;
extern float lbl_80562760;
extern float PSVECDotProduct(const float *, const float *);
extern void fn_8018381C(void *);
extern void fn_80189C64(void *, void **);
extern void fn_8018A08C(void *);
extern void fn_801AD148(void *, float *, void *, float, float, float);
extern void fn_801AD28C(void *, float *, void *, void *, float, float, float);
// split_file divides it into the game's real files (file_status shows its range).

extern void* __AXFXGetLfoSinTable_801769CC(void);
extern int lbl_8055E774;
extern float lbl_80562764;
extern void* lbl_80436D28[];
void fn_801B916C(void* arg0) {
    char* p = (char*)arg0 + 4;
    int i = 0;
    if (((int*)__AXFXGetLfoSinTable_801769CC())[1] & 0x400) {
        do {
            int index = *(int*)(p + 0x60);
            void* obj = 0;
            if (index >= 0 && index < lbl_8055E774) obj = lbl_80436D28[index];
            if (obj != 0) {
                int id = *(int*)((char*)obj + 0x1EC);
                int* slots = (int*)(p + 0x74);
                if (slots[0] == id) slots[0] = -1;
                if (slots[6] == id) slots[6] = -1;
                if (slots[12] == id) slots[12] = -1;
                if (slots[18] == id) slots[18] = -1;
                slots[0] = id;
                *(float*)(p + 0x78) = lbl_80562764;
                *(float*)(p + 0x7C) = *(float*)((char*)obj + 0x2690);
                *(float*)(p + 0x80) = *(float*)((char*)obj + 0x2694);
                *(float*)(p + 0x84) = *(float*)((char*)obj + 0x2690) - *(float*)((char*)obj + 0x2694);
                *(int*)(p + 0x88) = *(int*)((char*)obj + 0x268C);
            }
            p += 0xE0;
            i++;
        } while (i < *(int*)((char*)arg0 + 0x394));
    }
}

extern float lbl_80562750;
extern float lbl_80562768;
extern float lbl_8056276C;
extern float lbl_80562770;
extern float lbl_80562774;
extern float lbl_80562778;
extern int lbl_8055A918;
extern void fn_80182074(void *, int);
extern void fn_801B8CC0(float *, int, int *, float *, float, float);
extern void fn_802C77F0(int, float *);
void fn_801B92F0(void *arg0, int arg1) {
    float sp5c[3], sp50[3], sp90[6], sp78[6], sp8[3], sp14[3];
    float v1[3], v2[3];
    unsigned int bits = ((unsigned int *)__AXFXGetLfoSinTable_801769CC())[1];
    *((unsigned char *)arg0 + 0x275d) = (bits >> 12) & 1;
    fn_80182074(arg0,arg1);
    v1[0]=lbl_80562750; v1[1]=lbl_80562750; v1[2]=lbl_80562768;
    fn_801B8CC0(sp5c, *(int *)((unsigned char *)arg0+0x59c), &lbl_8055A918, v1, lbl_80562750, lbl_80562750);
    *(float *)((unsigned char *)arg0+0x273c)=sp5c[0];
    *(float *)((unsigned char *)arg0+0x2740)=sp5c[1];
    *(float *)((unsigned char *)arg0+0x2744)=sp5c[2];
    fn_802C77F0(*(int *)((unsigned char *)arg0+0x59c),sp90);
    if (*((unsigned char *)arg0+0x275d)) {
        v2[0]=lbl_80562750; v2[1]=lbl_80562750; v2[2]=sp90[5]-lbl_8056276C;
        *(float *)((unsigned char *)arg0+0x273c)=v2[0];
        *(float *)((unsigned char *)arg0+0x2740)=v2[1];
        *(float *)((unsigned char *)arg0+0x2744)=v2[2];
    }
    fn_802C77F0(*(int *)((unsigned char *)*(void **)((unsigned char *)arg0+0x2754)+0x59c),sp78);
    if (*((unsigned char *)arg0+0x275d)) {
        v1[0]=lbl_80562750; v1[1]=lbl_80562750; v1[2]=sp78[4]-lbl_80562770;
    } else {
        v1[0]=lbl_80562750; v1[1]=lbl_80562774; v1[2]=sp78[4]-lbl_8056276C;
    }
    sp8[0]=v1[0]; sp8[1]=v1[1]; sp8[2]=v1[2];
    fn_801B8CC0(sp14, *(int *)((unsigned char *)*(void **)((unsigned char *)arg0+0x2754)+0x59c), &lbl_8055A918, sp8, v1[1], v1[2]);
    *(float *)((unsigned char *)arg0+0x2748)=sp14[0];
    *(float *)((unsigned char *)arg0+0x274c)=sp14[1];
    *(float *)((unsigned char *)arg0+0x2750)=sp14[2];
    *(float *)((unsigned char *)arg0+0x274c)=sp14[1]+lbl_80562778;
}

void fn_801B949C(void *arg0) {
    short sp6c;
    int sp68;
    float sp64;
    float sp60;
    float sp5c;
    unsigned int sp2c[9];
    float sp8[3];
    float sp50[3];
    float sp14[3];
    float sp20[3];
    float dot;
    float factorX;
    float factorY;
    float factorZ;
    float *matrix;
    float *dst;
    float *src;
    float x, y, z;
    unsigned char flag;

    *(unsigned char *)((char *)arg0 + 0x275c) = 0;
    *(float *)((char *)arg0 + 0x2758) = lbl_80562750;
    fn_8018381C(arg0);

    sp8[0] = *(float *)((char *)arg0 + 0x2748) - *(float *)((char *)arg0 + 0x273c);
    sp8[1] = *(float *)((char *)arg0 + 0x274c) - *(float *)((char *)arg0 + 0x2740);
    sp8[2] = *(float *)((char *)arg0 + 0x2750) - *(float *)((char *)arg0 + 0x2744);
    sp8[0] -= *(float *)((char *)arg0 + 0x30);
    sp8[1] -= *(float *)((char *)arg0 + 0x34);
    sp8[2] -= *(float *)((char *)arg0 + 0x38);
    flag = *(unsigned char *)((char *)arg0 + 0x275d);
    if (flag != 0) {
        sp8[2] -= lbl_80562754;
    }

    sp6c = -1;
    matrix = *(float **)((char *)arg0 + 0x2754);
    dst = sp50;
    src = sp8;
    if (dst == src) {
        x = sp8[0] * matrix[0x70 / 4] + sp8[1] * matrix[0x7c / 4];
        y = sp8[0] * matrix[0x74 / 4] + sp8[1] * matrix[0x80 / 4];
        z = sp8[0] * matrix[0x78 / 4] + sp8[1] * matrix[0x84 / 4];
        x += sp8[2] * matrix[0x88 / 4];
        y += sp8[2] * matrix[0x8c / 4];
        z += sp8[2] * matrix[0x90 / 4];
        dst[0] = x; dst[1] = y; dst[2] = z;
    } else {
        dst[0] = sp8[0] * matrix[0x70 / 4] + sp8[1] * matrix[0x7c / 4] + sp8[2] * matrix[0x88 / 4];
        dst[1] = sp8[0] * matrix[0x74 / 4] + sp8[1] * matrix[0x80 / 4] + sp8[2] * matrix[0x8c / 4];
        dst[2] = sp8[0] * matrix[0x78 / 4] + sp8[1] * matrix[0x84 / 4] + sp8[2] * matrix[0x90 / 4];
    }

    sp50[0] += matrix[0x94 / 4];
    sp50[1] += matrix[0x98 / 4];
    sp50[2] += matrix[0x9c / 4];

    sp2c[0] = ((unsigned int *)matrix)[0x70 / 4];
    sp2c[1] = ((unsigned int *)matrix)[0x74 / 4];
    sp2c[2] = ((unsigned int *)matrix)[0x78 / 4];
    sp2c[3] = ((unsigned int *)matrix)[0x7c / 4];
    sp2c[4] = ((unsigned int *)matrix)[0x80 / 4];
    sp2c[5] = ((unsigned int *)matrix)[0x84 / 4];
    sp2c[6] = ((unsigned int *)matrix)[0x88 / 4];
    sp2c[7] = ((unsigned int *)matrix)[0x8c / 4];
    sp2c[8] = ((unsigned int *)matrix)[0x90 / 4];
    dot = PSVECDotProduct((float *)((char *)matrix + 0x118), (float *)((char *)arg0 + 0x54));
    factorX = ((float *)((char *)matrix + 0x88))[0] * dot;
    sp68 = 0;
    factorY = ((float *)((char *)matrix + 0x8c))[0] * dot;
    sp5c = factorX;
    sp60 = factorY;
    factorZ = ((float *)((char *)matrix + 0x90))[0] * dot;
    sp64 = factorZ;
    sp6c = *(short *)((char *)matrix + 0x6c);
    {
        typedef void (*VFunc)(void *, float *, void *, float, float);
        void **vtable = *(void ***)arg0;
        VFunc method = (VFunc)*(void **)((char *)vtable + 0x54);
        method(arg0, (float *)sp2c, matrix, factorY, factorX);
    }

    *(void **)((char *)arg0 + 0x2738) = arg0;
    if (*(unsigned char *)((char *)arg0 + 0x275d) == 0) {
        sp14[0] = *(float *)((char *)arg0 + 0x273c) + *(float *)((char *)arg0 + 0x30);
        sp14[1] = *(float *)((char *)arg0 + 0x2740) + *(float *)((char *)arg0 + 0x34);
        sp14[2] = *(float *)((char *)arg0 + 0x2744) + *(float *)((char *)arg0 + 0x38);
        fn_801AD148((char *)arg0 + 0x2704, sp14, matrix, lbl_80562758, lbl_8056275C, *(float *)((char *)arg0 + 0x2744));
    } else {
        sp20[0] = *(float *)((char *)arg0 + 0x273c) + *(float *)((char *)arg0 + 0x30);
        sp20[1] = *(float *)((char *)arg0 + 0x2740) + *(float *)((char *)arg0 + 0x34);
        sp20[2] = *(float *)((char *)arg0 + 0x2744) + *(float *)((char *)arg0 + 0x38);
        fn_801AD28C((char *)arg0 + 0x2704, sp20, matrix, (char *)arg0 + 0x2748, lbl_80562758, lbl_80562760, *(float *)((char *)arg0 + 0x2744));
    }
}

