// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_8017960C(int);
extern double fn_8002F234(float), cos(double), sin(double);
extern float fn_80129DC4(int,float,float);
extern unsigned long long fn_80171FF0(void *,int,float,float);
extern int fn_80171EF8(void *,void *);
extern float lbl_80558DC4[];
extern float lbl_8055E3C8,lbl_80561A38,lbl_80561A78,lbl_80561A80,lbl_80561AB4,lbl_80561ABC,lbl_80561AC8,lbl_80561AF8,lbl_80561AFC,lbl_80561B00,lbl_80561B04,lbl_80561B08,lbl_80561B0C;

#pragma cplusplus on
class TObj4C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16();
    virtual void v4C();
};
#pragma cplusplus reset

void fn_80171D10(int arg0) { fn_80171930(arg0 - 4); }

void fn_80171D18(int arg0) { fn_80171934(arg0 - 4); }

void fn_80171D20(int arg0) { fn_80171A4C(arg0 - 4); }

void fn_80171D28(int arg0) { fn_80171A80(arg0 - 4); }

void fn_80171D30(int arg0) { fn_80171CE0(arg0 - 4); }

int fn_80171D38(int arg0) {
    unsigned char sp[0x68];
    int index;
    int result = 0;
    if (fn_801298E8(sp, arg0) != 0) {
        index = *(int *)(__AXFXGetLfoSinTable_801297F4() + 0x30);
        if (*(sp + 0x20 + index) != 0)
            result = 1;
    }
    return result;
}

int fn_80171DE4(void *arg0) {
    extern int fn_80139EC4(int, float, float);
    extern int lbl_8055E3A4;
    int result = 0;
    if (lbl_8055E3A4 != 0 && fn_80139EC4(lbl_8055E3A4, *(float *)arg0, *(float *)((char *)arg0 + 4)) != 0) result = 1;
    return result;
}

#pragma push
#pragma dont_inline on
int fn_80171E3C(void *arg0) {
    extern int fn_802B04D4(float *, float, float);
    extern int fn_80139EC4(int, float, float);
    extern int lbl_8055E3A4;
    extern float lbl_80561A38;
    float sp8, spC, sp10;
    sp10 = *(float *)((char *)arg0 + 4);
    sp8 = *(float *)arg0;
    spC = lbl_80561A38;
    if (fn_802B04D4(&sp8, sp8, sp10)) return 0;
    if (lbl_8055E3A4 && fn_80139EC4(lbl_8055E3A4, *(float *)arg0, *(float *)((char *)arg0 + 4))) return 0;
    return 1;
}
#pragma pop

int fn_80171EC0(void) {
    extern void *fn_8017960C(int);
    return *(int *)((char *)fn_8017960C(0) + 0x10) == 0x50434152;
}

unsigned long long fn_80171FF0(void *arg0, int arg1, float angle, float step) {
    extern float lbl_80561A44, lbl_80561A48;
    float zero = lbl_80561A44;
    float off[2];
    float pos[2];
    float rad, c, s;
    while (arg1-- > 0) {
        off[0] = angle;
        off[1] = zero;
        rad = fn_80129DC4(3, zero, lbl_80561A48);
        c = (float)cos(rad);
        s = (float)sin(rad);
        off[1] = off[0] * s + off[1] * c;
        off[0] = angle * c - zero * s;
        pos[1] = *((float *)arg0 + 1) + off[1];
        pos[0] = *(float *)arg0 + off[0];
        if (fn_80171E3C(pos) != 0)
            break;
        angle += step;
    }
    return *(unsigned long long *)pos;
}

unsigned int fn_801720E0(unsigned int arg0) {
    return ((arg0 & 0x7F7F7F) | ((arg0 & 0xFF000000) >> 1));
}

void fn_801720FC(float *arg0, int arg1, float arg2) {
    extern float PSVECMag(float *);
    extern float lbl_80558DC4[];
    extern float lbl_8055E3A8;
    extern float lbl_80561A40, lbl_80561A44, lbl_80561A4C, lbl_80561A50, lbl_80561A54, lbl_80561A58;
    extern double lbl_80561A60;
    extern unsigned short lbl_802F9520[];
    extern void fn_802C8BD0(int);
    extern void fn_802C8DB8(void *, int, void *, int);
    extern void fn_802C8D74(void);
    float sp2C, sp30, sp34;
    float sp14, sp18, sp1C;
    float sp20, sp24, sp28;
    float sp38, sp3C, sp40;
    float sp50, sp54, sp58;
    float sp68, sp6C, sp70;
    float sp80, sp84, sp88;
    float sp98, sp9C, spA0;
    int sp44, sp5C, sp74, sp8C, spA4;
    unsigned short sp8, spA, spC, spE, sp10, sp12;
    float f1, f2, f3, f4;
    int i;

    sp2C = lbl_80561A44;
    sp30 = lbl_80561A50;
    sp34 = lbl_80561A44;
    sp14 = lbl_80561A40;
    sp18 = lbl_80561A44;
    sp1C = lbl_80561A44;
    sp20 = lbl_80561A44;
    sp24 = lbl_80561A44;
    sp28 = lbl_80561A40;
    f1 = PSVECMag(&sp2C);
    f2 = __fabs(f1);
    f2 = __frsp(f2);
    if (f2 > lbl_80558DC4[0]) {
        f4 = -arg2 / f1;
        sp2C *= f4;
        sp30 *= f4;
        sp34 *= f4;
    }
    f1 = PSVECMag(&sp14);
    f2 = __fabs(f1);
    f2 = __frsp(f2);
    if (f2 > lbl_80558DC4[0]) {
        f4 = (lbl_80561A4C * arg2) * lbl_80561A54 / f1;
        sp14 *= f4;
        sp18 *= f4;
        sp1C *= f4;
    }
    f1 = PSVECMag(&sp20);
    f2 = __fabs(f1);
    f2 = __frsp(f2);
    if (f2 > lbl_80558DC4[0]) {
        f4 = (lbl_80561A4C * arg2) * lbl_80561A54 / f1;
        sp20 *= f4;
        sp24 *= f4;
        sp28 *= f4;
    }
    sp38 = lbl_80561A44;
    sp3C = lbl_80561A44;
    sp40 = lbl_80561A44;
    sp50 = sp2C + sp14 * lbl_80561A50;
    sp54 = sp30 + sp18 * lbl_80561A50;
    sp58 = sp34 + sp1C * lbl_80561A50;
    sp68 = sp2C + sp14 * lbl_80561A40;
    sp6C = sp30 + sp18 * lbl_80561A40;
    sp70 = sp34 + sp1C * lbl_80561A40;
    sp80 = sp2C + sp20 * lbl_80561A50;
    sp84 = sp30 + sp24 * lbl_80561A50;
    sp88 = sp34 + sp28 * lbl_80561A50;
    sp98 = sp2C + sp20 * lbl_80561A40;
    sp9C = sp30 + sp24 * lbl_80561A40;
    spA0 = sp34 + sp28 * lbl_80561A40;
    sp44 = fn_801720E0(arg1);
    for (i = 0; i < 5; i++) {
        sp38 += arg0[0];
        sp3C += arg0[1];
        sp40 += arg0[2];
        arg0 += 3;
        sp38 = sp38;
        sp3C = sp3C;
        sp40 = sp40;
    }
    sp8 = lbl_802F9520[0];
    spA = lbl_802F9520[1];
    spC = lbl_802F9520[2];
    spE = lbl_802F9520[3];
    sp10 = lbl_802F9520[4];
    sp12 = lbl_802F9520[5];
    fn_802C8BD0(lbl_8055E3A8);
    fn_802C8DB8(&sp38, 5, &sp8, 6);
    fn_802C8D74();
    sp44 &= 0x3FFFFFFF;
    sp5C &= 0x3FFFFFFF;
    sp74 &= 0x3FFFFFFF;
    sp8C &= 0x3FFFFFFF;
    spA4 &= 0x3FFFFFFF;
    fn_802C8BD0(-1);
    fn_802C8DB8(&sp38, 5, &sp8, 6);
    fn_802C8D74();
}

float fn_801725C8(float arg0) {
    extern float lbl_8043038C[];
    extern float lbl_80561A40;
    extern float lbl_80561A44;
    float f0 = lbl_8043038C[2];
    float f2 = lbl_8043038C[3];
    float f3 = lbl_8043038C[0];
    float f4 = lbl_8043038C[1];
    float value = (arg0 - f0) / (f2 - f0);
    float t = lbl_80561A40;
    if (t < value) { t = value; } else { t = t; }
    if (t > lbl_80561A44) { t = lbl_80561A44; } else { t = t; }
    return f3 + t * (f4 - f3);
}

int fn_80172624(void *arg0, int arg1) {
    extern void *fn_8017960C(int);
    extern float PSQUATMultiply(void *, void *);
    extern float lbl_8043038C[];
    void *a = fn_8017960C((int)arg0);
    void *b = fn_8017960C(arg1);
    float dot = PSQUATMultiply((char *)a + 0x118, (char *)b + 0x118);
    float threshold = *(float *)((char *)a + 0x25D4);
    float upper = lbl_8043038C[9];
    int result;
    float value = upper * dot + lbl_8043038C[10] * threshold;
    result = 0;
    if (value >= lbl_8043038C[8])
        return 2;
    if (value >= lbl_8043038C[7])
        result = 1;
    return result;
}

void *fn_801726C4(void *arg0) {
    extern void *fn_801284F8(unsigned int, void *);
    extern char lbl_80330F48[];
    extern char lbl_80330FE8[];
    void *result = fn_801284F8(0x12C, lbl_80330F48);
    if (result != 0) {
        *(void **)result = lbl_80330FE8;
        *(int *)((char *)result + 0x124) = fn_801EA994();
        *(void **)((char *)result + 0x128) = arg0;
    }
    return result;
}

int fn_80172E24(int arg0, int arg1) {
    extern int fn_80128668(void);
    if (arg0 != 0 && arg1 > 0)
        fn_80128668();
    return arg0;
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void deleteThreads__6SystemFv_80173A2C(void *arg0) {
    class ThreadObject80173A2C {
    public:
        virtual void destroy(int);
    };
    ThreadObject80173A2C *p = *(ThreadObject80173A2C **)arg0;
    if (p) {
        if (p)
            p->destroy(1);
        *(ThreadObject80173A2C **)arg0 = 0;
    }
}
#pragma cplusplus reset
#pragma pop

int fn_80173A84(void *arg0) {
    int count = *(int *)((char *)arg0 + 0x170);
    int result = 0;
    int i;
    if (count > 0) {
        for (i = 0; i < count; i++) {
            if (*(unsigned char *)((char *)arg0 + 0x91) == 0 &&
                *(unsigned char *)((char *)arg0 + 0x90) != 0)
                result++;
            arg0 = (char *)arg0 + 0x1C;
        }
    }
    return result != 0;
}

int fn_80174298(void *arg0, int arg1) {
    extern float lbl_80558DC4[];
    extern float lbl_8055E3C8;
    extern float lbl_80561A44;
    int result = *((unsigned char *)arg0 + arg1 * 0x1C + 0x90);
    if (result != 0) {
        float one = lbl_8055E3C8;
        float value = *(float *)((char *)arg0 + 0x19C) - one;
        float limit = lbl_80561A44;
        limit = limit > value ? limit : value;
        result = !((float)__fabs(limit) <= lbl_80558DC4[0]);
    }
    return result;
}

int fn_801742FC(void *arg0) {
    extern float lbl_80561A44;
    return *(float *)((char *)arg0 + 0x1A0) > lbl_80561A44;
}

int fn_80174314(void) {
    return 8;
}

#pragma push
#pragma use_lmw_stmw off
void fn_80174794(void **arg0) {
    extern float fn_801B306C(void);
    extern int fn_800216D0(void);
    extern int fn_801EA994(void);
    extern int fn_801E866C(int);
    extern void fn_8017248C(int);
    extern float lbl_80561A44;
    int count;
    int i;
    if (fn_801B306C() < lbl_80561A44 && fn_800216D0() == 0) {
        count = fn_801EA994();
        for (i = 0; i < count; i++) {
            if (i != fn_801E866C(-1) &&
                (*(int (**)(void **, int))((char *)*arg0 + 0x20))(arg0, i) != 0) {
                fn_8017248C(i);
            }
        }
    }
}
#pragma pop
int fn_8017483C(void *arg0, void *arg1, int arg2) {
    extern double fn_8002F234(float);
    extern void fn_801B7C8C(void *, void *, float *);
    extern float lbl_80561A40, lbl_80561A50, lbl_80561AD0;
    float xy[2], length, scale;
    void *entry;
    int zero = 0;
    int two = 2;
    if (arg2 < *(int *)((char *)arg0 + 8)) {
        entry = (char *)*(void **)((char *)arg0 + 4) + arg2 * 8;
        xy[0] = *(float *)entry * lbl_80561A50;
        xy[1] = *(float *)((char *)entry + 4) * lbl_80561A50;
        length = (float)fn_8002F234(xy[0] * xy[0] + xy[1] * xy[1]);
        if (length < lbl_80561AD0) length = lbl_80561AD0;
        scale = lbl_80561A40 / length;
        xy[0] = xy[0] * scale;
        xy[1] = xy[1] * scale;
        fn_801B7C8C(arg1, entry, xy);
        *(int *)((char *)arg1 + 0x48) = zero;
        *(int *)((char *)arg1 + 0x44) = two;
        *(int *)((char *)arg1 + 0x4C) = zero;
        return 1;
    }
    return 0;
}

void fn_80175080(void **arg0, int arg1, int arg2, char *arg3, int arg4, int arg5, int arg6, int arg7, double farg0, double farg1, double farg2, double farg3, double farg4, double farg5, double farg6, double farg7, void *arg_sp8) {
    extern void *fn_80147CEC(void *, void *, void *, double);
    extern void fn_80147230(void *, const char *, const char *);
    extern void fn_801476C4(void *);
    extern void fn_802E317C(const char *, unsigned int, const char *);
    extern int vsprintf(char *, const char *, void *);
    extern unsigned int strlen(const char *);
    extern const char lbl_803314F8[];
    extern const char lbl_8055A2EC[];
    char result[0x20];
    char text[0x80];
    void *v;
    void *p;
    v = ((void *(*)(void *))((char *)*arg0 + 0xC))(arg0);
    p = ((void *(*)(void *, int))((char *)*arg0 + 0xC))(arg0, arg2);
    if (v != 0) {
        fn_80147CEC(result, v, p, farg0);
    } else {
        *(int *)(result + 0) = *(int *)p;
        *(int *)(result + 4) = *(int *)((char *)p + 4);
        *(int *)(result + 8) = *(int *)((char *)p + 8);
        *(int *)(result + 0xC) = *(int *)((char *)p + 0xC);
        *(float *)(result + 0x10) = *(float *)((char *)p + 0x10);
        *(int *)(result + 0x14) = *(int *)((char *)p + 0x14);
        *(int *)(result + 0x18) = *(int *)((char *)p + 0x18);
        *(int *)(result + 0x1C) = *(int *)((char *)p + 0x1C);
    }
    if (arg3 != 0) {
        vsprintf(text, arg3, &arg_sp8);
        if (strlen(text) >= 0x80) {
            fn_802E317C(lbl_803314F8, strlen(text), arg3);
        }
        fn_80147230(result, lbl_8055A2EC, text);
    } else {
        fn_801476C4(result);
    }
}

typedef void (*Fn_80175228)(void *);
#pragma scheduling off
void fn_80175228(void *arg0) {
    (*(void (**)(void *))(*(char **)arg0 + 0x4C))(arg0);
}
#pragma scheduling on
extern float lbl_80561AEC;
float fn_801757A8(void) { return lbl_80561AEC; }

int fn_801757B0(void) { return 1; }

int fn_801757B8(void *arg0, int arg1) {
    extern float fn_8001DAE8(void *);
    extern int fn_802AE220(int, int);
    extern void fn_8001DFCC(void);
    extern float lbl_80561A44;
    float value;
    int result = 0;
    int field;
    fn_801E866C(arg1);
    value = fn_8001DAE8((char *)arg0 + 0x17C) - *(float *)((char *)arg0 + 0x180);
    if (value >= lbl_80561A44 && value < *(float *)((char *)arg0 + 0x17C))
        result = 1;
    if (result != 0) {
        ((void (*)(void *, int))((*(void ***)arg0)[19]))(arg0, arg1);
    } else {
        if (*(unsigned char *)((char *)arg0 + 0x1B4) != 0)
            ((void (*)(void *, int))((*(void ***)arg0)[19]))(arg0, arg1);
        if (*(int *)((char *)arg0 + 0x1B8) != 0)
            fn_802AE220(*(int *)((char *)arg0 + 0x1B8), 0);
    }
    if (((int (*)(void *))((*(void ***)arg0)[26]))(arg0) != 0)
        fn_8001DFCC();
    field = *(int *)((char *)arg0 + 0x1AC);
    return (unsigned int)((4 - field) | (field - 4)) >> 31;
}

int fn_801758B8(void *arg0) { return *(int *)((char *)arg0 + 0x1AC) == 2; }

int fn_80175A38(void *arg0, float *arg1, float *arg2, int arg3, int arg4, int *arg5) {
    char *p = (char *)arg0 + arg3 * 0x24;
    *arg5 = 0x21F;
    arg1[0] = *(float *)(p + 0x18);
    arg1[1] = *(float *)(p + 0x1C);
    *arg2 = *(float *)(p + 0x20);
    return 1;
}

extern void *fn_8017960C(int);
extern float lbl_80561AF0;
extern float lbl_80561AF4;
int fn_80175A68(void *unused, float *arg0, float *arg1, int arg2, void *unused2, int *arg3) {
    float *p = (float *)fn_8017960C(arg2);
    float scale = lbl_80561AF0;
    float x = p[0x54 / 4] * scale + p[0x60 / 4];
    float y = p[0x5C / 4] * scale + p[0x68 / 4];
    float z = p[0x58 / 4] * scale + p[0x64 / 4];
    arg0[0] = x;
    arg0[1] = y;
    *arg3 = 0x21F;
    *arg1 = lbl_80561AF4;
    *(volatile float *)((char *)&z) = z;
    return 1;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
void fn_80175D40(void *arg0) {
 float old[2],delta[2],base[2],velocity[2],pos[2],candidate[2];
 union {unsigned long long bits;float v[2];} result;
 float angle,cs,sn,len,scale,x,y;
 float factor=lbl_80561B04, step=lbl_80561A38;
 float decay=lbl_80561B08, minTime=lbl_80561A80,minValue=lbl_80561B0C;
 float grow=lbl_80561ABC,minScale=lbl_80561A78,radius=lbl_80561AB4,fallback=lbl_80561AC8;
 float left,right,value,time,distance;
 int i,tries;void *p,*obj;char *entry=(char *)arg0+4;
 for(i=0;i<(*(int *)((char *)(arg0)+(0x124)));i++,entry+=0x24) {
 obj=(*(void * *)((char *)(arg0)+(0x128)));
 if(((int (*)(void *,int))(*(void ***)obj)[8])(obj,i)==0)continue;
 p=fn_8017960C(i);
 old[0]=(*(float *)((char *)(p)+(0x60)));old[1]=(*(float *)((char *)(p)+(0x68)));
 delta[0]=old[0]-(*(float *)((char *)(entry)+(0x14)));delta[1]=old[1]-(*(float *)((char *)(entry)+(0x18)));
 if(delta[0]*delta[0]+delta[1]*delta[1]<radius*radius || lbl_8055E3C8>(*(float *)((char *)(entry)+(0x20)))){
 p=fn_8017960C(i);
 base[0]=(*(float *)((char *)(p)+(0x60)));base[1]=(*(float *)((char *)(p)+(0x68)));
 if(fn_80171E3C(base)) {
 left=lbl_80561AF8;right=lbl_80561AFC;
 value=fn_801725C8(lbl_8055E3C8);
 time=lbl_80561A38;distance=lbl_80561B00;
 tries=19;
 do{
 p=fn_8017960C(i);
 pos[0]=(*(float *)((char *)(p)+(0x60)));pos[1]=(*(float *)((char *)(p)+(0x68)));
 velocity[0]=(*(float *)((char *)(p)+(0x54)));velocity[1]=(*(float *)((char *)(p)+(0x5c)));
 len=(float)fn_8002F234(velocity[0]*velocity[0]+velocity[1]*velocity[1]);
 if(!((float)__fabs(len)<=lbl_80558DC4[0])){
 scale=distance/len;velocity[0]*=scale;velocity[1]*=scale;
 }
 angle=fn_80129DC4(3,factor*left,factor*right);
 x=velocity[0];cs=(float)cos(angle);sn=(float)sin(angle);
 candidate[0]=(*(float *)((char *)(p)+(0x60)));
 y=velocity[1];
 velocity[0]=x*cs-y*sn;
 velocity[1]=x*sn+y*cs;
 candidate[0]+=velocity[0];candidate[1]=(*(float *)((char *)(p)+(0x68)))+velocity[1];
 if(fn_80171EF8(pos,candidate))break;
 time*=decay;left-=step;right+=step;
 time=time>minTime?time:minTime;
 value*=decay;value=value>minValue?value:minValue;
 distance*=grow;distance=distance>minScale?distance:minScale;
 }while(tries-->0);
 (*(float *)((char *)(entry)+(0x14)))=candidate[0];(*(float *)((char *)(entry)+(0x18)))=candidate[1];
 (*(float *)((char *)(entry)+(0x1c)))=value;(*(float *)((char *)(entry)+(0x20)))=time+lbl_8055E3C8;
 }else{
 result.bits=fn_80171FF0(base,10,lbl_80561AC8,lbl_80561AC8);
 (*(float *)((char *)(entry)+(0x14)))=result.v[0];(*(float *)((char *)(entry)+(0x18)))=result.v[1];
 (*(float *)((char *)(entry)+(0x1c)))=minValue;(*(float *)((char *)(entry)+(0x20)))=fallback+lbl_8055E3C8;
 }
 }
 }
}
#pragma pop

int fn_80176030(void) { return 0; }

int fn_80176038(void) { return 0; }

void fn_80176400(void) {
}
