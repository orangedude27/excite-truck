// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80565160, lbl_80565164, lbl_80565168, lbl_8056516C;
extern float lbl_80565170, lbl_80565174, lbl_80565178;
extern int lbl_8055D208, lbl_8055D210, lbl_8055D218, lbl_8055D220;
extern int lbl_8034D898, lbl_8034D8A8;
extern int fn_801282EC(int);
extern int fn_801282F4(void);
extern int fn_801284E8(void *, int);
extern int lbl_80507258[];
extern int lbl_8055D224;
extern int lbl_8056000C;
int fn_802E77B8(void) { return 0; }

void *fn_802E77C0(int x) {
    if (x < -2) {
        if (x == -4) return &lbl_8034D8A8;
        if (x < -4) return &lbl_8055D220;
        return &lbl_8055D220;
    }
    if (x == -2) return &lbl_8055D210;
    if (x < 0) return &lbl_8034D898;
    if (x == 0) return &lbl_8055D208;
    return &lbl_8055D220;
}

float fn_802E7824(float arg0, float arg1) {
    float t = lbl_80565160 / (lbl_80565160 - arg1);
    if (arg0 == lbl_80565164) {
        float v = t * (arg0 - arg1);
        if (v < lbl_80565168) v = lbl_80565168;
        if (v > lbl_80565164) v = lbl_80565164;
        return v;
    } else {
        float v = t * (arg0 + arg1);
        if (v < lbl_80565164) v = lbl_80565164;
        if (v > lbl_8056516C) v = lbl_8056516C;
        return v;
    }
}

float fn_802E78A4(float arg0) {
    float a = fn_802E7824(lbl_80565174 + arg0, lbl_80565178);
    float b = fn_802E7824(arg0 - lbl_80565174, lbl_80565178);
    float v = lbl_80565170 * (b + a);
    return v + lbl_80565164 * (v * __fabs(v) - v);
}

extern int fn_801282EC(int);
extern int fn_801282F4(void);
extern int fn_801284E8(void *, int);
extern int lbl_80507258[];
extern int lbl_8055D224;
extern int lbl_8056000C;
void fn_802E7A14(int arg0) {
    int *slot;
    int value;
    fn_801282EC(0x80);
    fn_801282F4();
    value = fn_801284E8(&lbl_8055D224, arg0);
    slot = lbl_80507258 + lbl_8056000C;
    *slot = value;
    lbl_8056000C++;
}

unsigned char fn_802E8504(int index) {
    extern unsigned char lbl_80505978[];
    return lbl_80505978[index * 0x638];
}

extern float lbl_80565164, lbl_80565170, lbl_80565198, lbl_8056519C;
extern unsigned char lbl_80505978[];
void fn_802E8528(int, float);
void fn_802E8524(void) {}

void fn_802E8528(int index, float value) {
    float scaled = (value - lbl_80565198) * lbl_8056519C;
    float rounded;
    int converted;
    int magnitude;
    unsigned short result = 0xFFFF;
    if (scaled < lbl_80565164)
        rounded = scaled - lbl_80565170;
    else
        rounded = lbl_80565170 + scaled;
    converted = (int)rounded;
    magnitude = converted & ((-converted & ~converted) >> 31);
    if (magnitude < 0xFFFF)
        result = magnitude;
    *(unsigned short *)(lbl_80505978 + index * 0x638 + 0xB0) = result;
}

void fn_802E85A8(void) {}

void fn_802E85AC(void) {}

int fn_802E85B0(void) { return 3; }

extern int lbl_802FAE80[4];
int fn_802E85B8(int arg0) {
    int values[4];
    int *p = lbl_802FAE80;
    values[0] = *p++;
    values[1] = *p++;
    values[2] = *p++;
    values[3] = *p;
    return values[arg0];
}
extern int lbl_802FAE80[4];
