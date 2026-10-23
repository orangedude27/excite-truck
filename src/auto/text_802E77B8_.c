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

#pragma push
#pragma dont_inline on
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
#pragma pop

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

extern double fn_8002EFB0(float, float);
extern float fn_802E78A4(float);
extern float lbl_80565160, lbl_8056517C, lbl_80565180, lbl_80565184, lbl_80565188;
extern float lbl_8056518C, lbl_80565190, lbl_80565194, lbl_80565198;
void fn_802E7DDC(void *arg0, void *arg1) {
    float f0, f02, f1, f31, f4;
    double df1;
    int r5;
    unsigned int r31 = *(unsigned int *)arg1;
    *(int *)((char *)arg0 + 0x48) = 0x800F;
    *((signed char *)arg0 + 0x64) = *(int *)((char *)arg0 + 0x624) != 0;
    *(int *)((char *)arg0 + 0x4C) = 0xFF;
    r5 = 0;
    *(int *)((char *)arg0 + 0x54) |= 0x10;
    if (r31 & 2) r5 = 1;
    if (r31 & 1) r5 |= 4;
    if (r31 & 8) r5 |= 8;
    if (r31 & 4) r5 |= 2;
    *(int *)((char *)arg0 + 0x44) = r5;
    df1 = -(float)fn_8002EFB0(*(float *)((char *)arg1 + 0xC), -*(float *)((char *)arg1 + 0x10));
    f31 = (float)df1;
    *(float *)((char *)arg0 + 0x6C) = (float)df1;
    if (f31 > lbl_80565180) f31 -= lbl_80565184;
    else if (f31 < lbl_80565188) f31 += lbl_80565184;
    f1 = lbl_80565160;
    f0 = lbl_8056518C * *(float *)((char *)arg1 + 0x14);
    if (f1 >= f0) f1 = f0;
    f0 = lbl_8056517C;
    if (f1 <= f0) f1 = f0;
    *(float *)((char *)arg0 + 4) = fn_802E78A4(f1);
    f02 = lbl_80565194 * f31;
    f1 = (lbl_80565190 * (f02 / lbl_80565180));
    f4 = lbl_80565160;
    if (f4 >= f1) f4 = f1;
    f0 = lbl_8056517C;
    if (f4 <= f0) f4 = f0;
    *(float *)((char *)arg0 + 8) = f4;
    *((signed char *)arg0 + 0x25) = (r31 >> 9) & 1;
    *((signed char *)arg0 + 0x24) = (r31 >> 8) & 1;
    *((signed char *)arg0 + 0x28) = (r31 >> 11) & 1;
    *((signed char *)arg0 + 0x26) = (r31 >> 10) & 1;
    *((signed char *)arg0 + 0x2B) = (r31 >> 4) & 1;
    *((signed char *)arg0 + 0x27) = (r31 >> 12) & 1;
    *((signed char *)arg0 + 0x29) = (r31 >> 15) & 1;
    *(int *)((char *)arg0 + 0x54) |= 0x20;
    *(float *)((char *)arg0 + 0x58) = lbl_80565198 * -*(float *)((char *)arg1 + 0x14);
    *(float *)((char *)arg0 + 0x5C) = lbl_80565198 * *(float *)((char *)arg1 + 0x10);
    *(float *)((char *)arg0 + 0x60) = lbl_80565198 * -*(float *)((char *)arg1 + 0xC);
}

extern int KPADRead(int, void *, int);
extern int WPADProbe(int, int *);
extern void WPADiClearQueue(int);
extern void WPADiDisableRecalibration(int);
extern unsigned char fn_8005EE80(int);
extern int fn_800604E8(int, int, void *);
extern int fn_802ECC10(void);
extern void fn_802EC884(void);
extern void fn_802ECBF8(void);
extern void fn_802E2E38(int);
extern void fn_802E7C14(void);
extern void *memset(void *, int, unsigned int);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802E7FD0(void) {
    extern int lbl_8034D898;
    extern unsigned char lbl_80505978[];
    extern int lbl_80507278[];
    extern unsigned char lbl_8055D230;
    extern unsigned char lbl_80560009;
    extern int lbl_80560010;
    extern int lbl_80560014;

    int now;
    int previous;
    int elapsed;
    int count;
    register int changed;
    register int queueIndex;
    register int channel;
    int active;
    int result;
    char *formatBase;
    int probe;
    int readCount;
    int current;
    int old;
    int filtered;
    int timeNow;
    unsigned char *record;
    int *devices;
    unsigned char *base;
    unsigned char *lastState;

    formatBase = (char *)&lbl_8034D898;
    now = fn_802E2C20();
    previous = lbl_80560010;
    if (previous < now) {
        elapsed = now - previous;
        if (elapsed < 0xF)
            return;
        count = lbl_80560014;
        lbl_80560010 = now;
        lbl_80560014 = count + 1;
        changed = fn_802ECC10();
        if ((unsigned int)changed != (unsigned int)lbl_80560009) {
            lbl_80560009 = changed;
            queueIndex = 0;
            do {
                if (changed != 0)
                    WPADiClearQueue(queueIndex);
                else
                    WPADiDisableRecalibration(queueIndex);
                queueIndex += 1;
            } while (queueIndex < 4);
        }
    }

    record = lbl_80505978;
    devices = lbl_80507278;
    base = record;
    channel = 0;
    lastState = &lbl_8055D230;
    do {
        memset(record + 0xC8, 0, 0x550);
        active = 0;
        if (base[0x631] != 0)
            active = 1;
        if (base[0xC69] != 0)
            active = 1;
        if (base[0x12A1] != 0)
            active = 1;
        if (base[0x18D9] != 0)
            active = 1;
        if (active == 0 && now - *(int *)(record + 0x634) > 0x2710) {
            *(int *)(record + 0x634) = now;
            record[0x631] = 1;
            result = fn_800604E8(channel, (int)(record + 0x618), fn_802E7C14);
            if (result != 0) {
                record[0x631] = 0;
                if (result == -1)
                    memset(record + 0x618, 0, 0x18);
            }
        }

        probe = WPADProbe(channel, devices);
        result = KPADRead(channel, record + 0xC8, 1);
        if (result >= 1 && probe == 0 && record[0xC4] != 0) {
            current = *(signed char *)(record + 0x14D);
            old = *(signed char *)lastState;
            if (current != old) {
                result = (int)fn_802E77C0((signed char)current);
                probe = (int)fn_802E77C0((signed char)old);
                ((void (*)(const char *, ...))fn_802E30C8)(
                    formatBase + 0x94, channel, probe, result);
                *lastState = (unsigned char)current;
            }
            if ((signed char)current == 0) {
                if (record[0] == 0) {
                    record[0] = 1;
                    *(int *)(record + 0xB4) = 0;
                    record[0xC5] = 1;
                    ((void (*)(const char *, ...))fn_802E30C8)(
                        formatBase + 0xA8, channel);
                }
                record[0x630] = fn_8005EE80(channel);
                if (fn_802ECC10() == 0)
                    ((void (*)(int, int))fn_802E7920)(channel, 0x3091);
                fn_802E7DDC(record, record + 0xC8);
            }
        } else if (record[0xC4] == 0 && record[0] != 0) {
            record[0] = 0;
            ((void (*)(const char *, ...))fn_802E30C8)(
                formatBase + 0xC0, channel);
        }

        if (record[0x29] != 0) {
            if (record[0xC5] == 0) {
                record[0xC5] = 1;
                fn_802ECBF8();
            }
        } else {
            record[0xC5] = 0;
        }

        filtered = 0;
        if (((int (*)(int))fn_802E77B8)(channel) != 0 &&
            record[0x2B] != 0 && record[0x29] != 0 &&
            record[0x27] != 0)
            filtered = 1;
        timeNow = fn_802E2C20();
        if (filtered == 0)
            *(int *)(record + 0xC0) = timeNow;
        else if (timeNow - *(int *)(record + 0xC0) > 0x3E8)
            fn_802E2E38(0);

        channel += 1;
        record += 0x638;
        devices += 1;
        lastState += 1;
    } while (channel < 4);
    fn_802EC884();
}
#pragma pop
void fn_802E830C(int *p) {
 p[0]=3; p[1]=0; p[2]=2; p[9]=-1; p[3]=1; p[4]=7; p[12]=4; p[13]=-1; p[10]=-1; p[11]=-1; p[5]=5; p[6]=6;
}

unsigned char fn_802E8364(void *arg0,int arg1){extern unsigned char lbl_80505978[]; unsigned char *src=lbl_80505978+arg1*0x638; unsigned char *dst=(unsigned char*)arg0; unsigned char a,b; unsigned int x,y;
*(float*)(dst+0)=*(float*)(src+4);
*(float*)(dst+4)=*(float*)(src+8);
*(float*)(dst+8)=*(float*)(src+12);
*(float*)(dst+12)=*(float*)(src+16);
*(float*)(dst+16)=*(float*)(src+20);
*(float*)(dst+20)=*(float*)(src+24);
*(float*)(dst+24)=*(float*)(src+28);
*(float*)(dst+28)=*(float*)(src+32);
b=src[36]; a=src[37]; dst[32]=b; dst[33]=a;
a=src[38]; b=src[39]; dst[34]=a; dst[35]=b;
a=src[40]; b=src[41]; dst[36]=a; dst[37]=b;
a=src[42]; b=src[43]; dst[38]=a; dst[39]=b;
a=src[44]; b=src[45]; dst[40]=a; dst[41]=b;
a=src[46]; b=src[47]; dst[42]=a; dst[43]=b;
a=src[48]; b=src[49]; dst[44]=a; dst[45]=b;
a=src[50]; b=src[51]; dst[46]=a; dst[47]=b;
a=src[52]; b=src[53]; dst[48]=a; dst[49]=b;
a=src[54]; b=src[55]; dst[50]=a; dst[51]=b;
a=src[56]; b=src[57]; dst[52]=a; dst[53]=b;
a=src[58]; b=src[59]; dst[54]=a; dst[55]=b;
a=src[60]; b=src[61]; dst[56]=a; dst[57]=b;
a=src[62]; b=src[63]; dst[58]=a; dst[59]=b;
a=src[64]; b=src[65]; dst[60]=a; dst[61]=b;
a=src[66]; b=src[67]; dst[62]=a; dst[63]=b;
*(unsigned int*)(dst+0x40)=*(unsigned int*)(src+0x44);
y=*(unsigned int*)(src+0x4c); x=*(unsigned int*)(src+0x48); *(unsigned int*)(dst+0x44)=x; *(unsigned int*)(dst+0x48)=y;
y=*(unsigned int*)(src+0x54); x=*(unsigned int*)(src+0x50); *(unsigned int*)(dst+0x4c)=x; *(unsigned int*)(dst+0x50)=y;
y=*(unsigned int*)(src+0x5c); x=*(unsigned int*)(src+0x58); *(unsigned int*)(dst+0x54)=x; *(unsigned int*)(dst+0x58)=y;
*(unsigned int*)(dst+0x5c)=*(unsigned int*)(src+0x60); dst[0x60]=src[0x64]; return src[0];}

unsigned char fn_802E8504(int index) {
    extern unsigned char lbl_80505978[];
    return lbl_80505978[index * 0x638];
}

void fn_802E8518(int arg0) {
    fn_802E8528(arg0, lbl_80565164, lbl_80565164);
}

extern float lbl_80565164, lbl_80565170, lbl_80565198, lbl_8056519C;
extern unsigned char lbl_80505978[];
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
