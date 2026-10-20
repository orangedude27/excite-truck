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
void fn_802E8528(int, float, float);
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

void fn_802E7920(int arg0) {
    extern int WPADControlMotor(int, int);
    extern int fn_802D9BF0(void);
    extern int fn_802E2C20(void);
    extern unsigned char lbl_80505978[];
    extern unsigned char lbl_80560008;
    unsigned char *p;
    int time;
    int motor;
    int value;

    p = lbl_80505978 + arg0 * 0x638;
    time = fn_802E2C20();
    motor = fn_802D9BF0();
    if (*(unsigned short *)(p + 0xB0) < 0x5000) {
        if (time - *(int *)(p + 0xBC) > 0x3E8)
            *(int *)(p + 0xB8) = time;
    } else {
        *(int *)(p + 0xBC) = time;
        if (time - *(int *)(p + 0xB8) > 0x1388)
            motor = 1;
    }
    if (lbl_80560008 == 0)
        motor = 1;
    if (motor == 0) {
        value = *(int *)(p + 0xB4) + *(unsigned short *)(p + 0xB0);
        *(int *)(p + 0xB4) = value;
        if ((unsigned int)value >= 0x8000U)
            *(int *)(p + 0xB4) -= 0x10000;
    } else {
        *(int *)(p + 0xB4) = 0;
    }
    WPADControlMotor(arg0, motor);
}

extern int fn_801282EC(int);
extern int fn_801282F4(void);
extern int fn_801284E8(void *, int);
extern int lbl_80507258[];
extern int lbl_8055D224;
extern int lbl_8056000C;
void fn_802E7A14(int arg0) {
    fn_801282EC(0x80);
    fn_801282F4();
    lbl_80507258[lbl_8056000C] = fn_801284E8(&lbl_8055D224, arg0);
    lbl_8056000C++;
}

extern float lbl_805651A0, lbl_805651A4;
extern int fn_8005ED8C(void), fn_8005EE20(void), fn_8005EE7C(void);
extern int fn_80128684(void), fn_802E30C8(int *);
extern int lbl_8034D8B4, lbl_8034D8E8;
extern int lbl_80507258[], lbl_8056000C;
extern int fn_80128658(int, int *);
int fn_802E7A70(unsigned int value) {
    int found = -1;
    int i = 0;
    int count = lbl_8056000C;
    int *p = lbl_80507258;
    while (count--) {
        if ((unsigned int)*p == value) found = i;
        p++;
        i++;
    }
    count = lbl_8056000C;
    count--;
    lbl_8056000C = count;
    p = lbl_80507258;
    i = p[count];
    p[found] = i;
    fn_80128658(i, p);
    return 1;
}

int fn_802E7AF4(int arg0,int arg1) {
 if(arg0==1){
  fn_80128684();
  if(arg1==2)fn_8005ED8C();else fn_8005EE20();
  fn_802E30C8(&lbl_8034D8B4);
  if(fn_8005EE7C()!=4)fn_802E30C8(&lbl_8034D8E8);
 }
 return 0;
}

extern int WPADSetSamplingCallback(int, int);
extern int fn_8006022C(int);
extern int fn_8005ED8C(void);
extern int fn_8005EE7C(void);
extern int fn_802E30C8(int *);
extern int lbl_8034D908, lbl_8034D8E8;
extern int lbl_80507268[], lbl_80507258[], lbl_8056000C;
void fn_802E7D0C(void) {
    int i;
    int *p;
    for (i = 0, p = lbl_80507268; i < 4; i++, p++)
        WPADSetSamplingCallback(i, *p);
    for (i = 0; i < 4; i++)
        fn_8006022C(i);
    fn_8005ED8C();
    fn_802E30C8(&lbl_8034D908);
    while (fn_8005EE7C() == 4) {}
    fn_802E30C8(&lbl_8034D8E8);
    for (i = 0, p = lbl_80507258; i < lbl_8056000C; i++, p++)
        ((int (*)(int))fn_80128658)(*p);
    lbl_8056000C = 0;
}

void fn_802E830C(int *p) {
 p[0]=3; p[1]=0; p[2]=2; p[9]=-1; p[3]=1; p[4]=7; p[12]=4; p[13]=-1; p[10]=-1; p[11]=-1; p[5]=5; p[6]=6;
}

unsigned char fn_802E8504(int index) {
    extern unsigned char lbl_80505978[];
    return lbl_80505978[index * 0x638];
}

extern float lbl_80565164, lbl_80565170, lbl_80565198, lbl_8056519C;
extern unsigned char lbl_80505978[];
void fn_802E8528(int, float, float);
void fn_802E8524(void) {}

void fn_802E8528(int index, float value, float unused) {
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

void fn_802E85F4(int index) {
 unsigned char *p=lbl_80505978+index*0x638;
 float value=lbl_805651A4, current=*(float *)(p+0x6C);
 int count;
 if(value<current)value=current;
 if(value>lbl_805651A0)value=lbl_805651A0;
 count=*(int *)(p+0x68);
 *(float *)(p+count*4+0x70)=value;
 count++;
 *(int *)(p+0x68)=count%16;
}

void fn_802E8664(void) {}

void *fn_802E8668(int index) {
    unsigned char offset = lbl_80505978[index * 0x638];
    if (offset != 0)
        return lbl_80505978 + index * 0x638 + 0xC8;
    return 0;
}

int fn_802E8690(int index) {
    return *(unsigned int *)(lbl_80505978 + index * 0x638 + 0x124) == 1;
}

unsigned char fn_802E86B4(int index) {
    unsigned char *base = lbl_80505978;
    return *(base + index * 0x638 + 0x630);
}

extern int lbl_802FAE80[4];
extern float lbl_805651A0, lbl_805651A4;
extern unsigned char lbl_80505978[];
extern int fn_8005ED8C(void), fn_8005EE20(void), fn_8005EE7C(void);
extern int fn_80128684(void), fn_802E30C8(int *);
extern int lbl_8034D8B4, lbl_8034D8E8;
extern int fn_80128658(int, int *);
