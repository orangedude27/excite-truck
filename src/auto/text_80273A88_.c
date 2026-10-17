// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80272354(void);
extern void fn_8002F634(void *, void *, int, int);
extern void fn_80015B20(void *, void *, void *);
extern void fn_801BFD34(void *, void *, void *);
extern float PSVECMag(float *);
extern double sin(double);
extern double cos(double);
extern float lbl_80564024, lbl_80564020, lbl_80563FAC, lbl_80563FB0;
extern float lbl_802FA788[];
extern char lbl_80347364[];
extern char lbl_8049A2C8[];
extern char lbl_8049F9D8[];
extern int fn_80273B08(int, int);
extern void fn_80273978(void);
void fn_80273A88(void) {
    fn_8002F634(lbl_8049F9D8, fn_80273978, 0x1C, 0x20);
}

void fn_80273AA4(void *arg0) {
    *(int *)arg0 = 0;
    *(char **)((char *)arg0 + 0x18) = lbl_80347364;
}

int fn_80273ABC(int arg0) {
    fn_80272354();
    return arg0;
}

void fn_80273AEC(void) {
    fn_8002F634(lbl_8049A2C8, fn_80273B08, 0x60, 0xC8);
}

int fn_80273B08(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        extern int fn_80128668(void);
        fn_80128668();
    }
    return arg0;
}

void fn_80273B48(void) {
}

void fn_80273B4C(void *arg0) {
    extern void fn_80015A20(void *, float *, float, float);
    extern void fn_80015B20(void *, void *, void *);
    extern float lbl_80563FA8;
    extern float lbl_80563FAC;
    extern float lbl_80563FB0;
    extern float lbl_80563FB4;
    void *temp_r4 = *(void **)((char *)arg0 + 0x140);
    char out[0x14];
    volatile char pad[0x10];
    float vec[3];
    float var_f1;
    void *temp_r3;
    if (temp_r4 != 0) {
        if (*(unsigned char *)((char *)temp_r4 + 0x260C) != 0) {
            var_f1 = lbl_80563FA8;
        } else {
            var_f1 = lbl_80563FAC;
        }
        vec[0] = lbl_80563FB0;
        vec[1] = (lbl_80563FB0 * lbl_80563FB4) * var_f1;
        vec[2] = lbl_80563FB0;
        fn_80015A20(out, vec, var_f1, lbl_80563FB0);
        temp_r3 = (char *)arg0 + 0x58;
        fn_80015B20(temp_r3, out, temp_r3);
    }
}

void fn_8027445C(void) {
    extern void fn_80274268(void);
    fn_80274268();
}

void fn_802751AC(void *arg0, float angle) {
    float axis[3], input[3], matrix[12];
    float mag, scale, x, y, z, s, c, t;
    unsigned int *src = (unsigned int *)((char *)arg0 + 0xC0);
    unsigned int *dst = (unsigned int *)((char *)arg0 + 0x58);
    int i;
    for (i = 0; i < 12; i++) dst[i] = src[i];
    input[0] = lbl_80564024 * lbl_802FA788[3];
    input[1] = lbl_80564024 * lbl_802FA788[4];
    input[2] = lbl_80564024 * lbl_802FA788[5];
    axis[0] = lbl_802FA788[0]; axis[1] = lbl_802FA788[1]; axis[2] = lbl_802FA788[2];
    mag = PSVECMag(input);
    if (mag > lbl_80564020) {
        scale = lbl_80563FAC / mag;
        x = input[0] * scale; y = input[1] * scale; z = input[2] * scale;
        s = (float)sin(angle); c = (float)cos(angle); t = lbl_80563FAC - c;
        matrix[0] = c + t * x * x;
        matrix[1] = y * (t * x) + s * z;
        matrix[2] = z * (t * x) - s * y;
        matrix[3] = y * (t * x) - s * z;
        matrix[4] = c + t * y * y;
        matrix[5] = z * (t * y) + s * x;
        matrix[6] = z * (t * x) + s * y;
        matrix[7] = z * (t * y) - s * x;
        matrix[8] = c + t * z * z;
    } else {
        matrix[0] = lbl_80563FAC; matrix[1] = lbl_80563FB0; matrix[2] = lbl_80563FB0;
        matrix[3] = lbl_80563FB0; matrix[4] = lbl_80563FAC; matrix[5] = lbl_80563FB0;
        matrix[6] = lbl_80563FB0; matrix[7] = lbl_80563FB0; matrix[8] = lbl_80563FAC;
    }
    fn_801BFD34((char *)arg0 + 0x7C, axis, (char *)arg0 + 0xC0);
    fn_80015B20((char *)arg0 + 0x58, matrix, (char *)arg0 + 0xC0);
    *(float *)((char *)arg0 + 0xBC) = lbl_80564024 * angle;
}

void fn_80276044(int arg0) {
    fn_80276BE4(arg0 + 0x58, arg0 + 0xBC);
}

int fn_802704D4(int, int);
int fn_80276BE4(int, int);
int fn_80274730(float, float, float, float);
void fn_80276054(int arg0) {
    fn_802704D4(4, arg0);
}

