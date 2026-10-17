// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80137F2C(void) {

}

void fn_80137F74(void *arg0) {
    unsigned char a0,a1,a4,a5,a8,a9;
    a0=((unsigned char *)arg0)[0]; a1=((unsigned char *)arg0)[1];
    a4=((unsigned char *)arg0)[4]; a5=((unsigned char *)arg0)[5];
    a8=((unsigned char *)arg0)[8]; a9=((unsigned char *)arg0)[9];
    ((unsigned char *)arg0)[0]=((unsigned char *)arg0)[3];
    ((unsigned char *)arg0)[3]=a0;
    ((unsigned char *)arg0)[1]=((unsigned char *)arg0)[2];
    ((unsigned char *)arg0)[2]=a1;
    ((unsigned char *)arg0)[4]=((unsigned char *)arg0)[7];
    ((unsigned char *)arg0)[7]=a4;
    ((unsigned char *)arg0)[5]=((unsigned char *)arg0)[6];
    ((unsigned char *)arg0)[6]=a5;
    ((unsigned char *)arg0)[8]=((unsigned char *)arg0)[11];
    ((unsigned char *)arg0)[11]=a8;
    ((unsigned char *)arg0)[9]=((unsigned char *)arg0)[10];
    ((unsigned char *)arg0)[10]=a9;
}

void fn_80137FF0(void) {
    unsigned char *p = (unsigned char *)0;
    unsigned char a, b, c, d, e, f;
    unsigned char *q;
    int i = 0;
    p = (unsigned char *)__builtin_frame_address(0);
}

void fn_801380DC(void *arg0) {
    unsigned char a,b;
    unsigned char *p;
    int i;
    a=((unsigned char *)arg0)[8];
    p=(unsigned char *)arg0+12;
    b=((unsigned char *)arg0)[9];
    i=0;
    ((unsigned char *)arg0)[8]=((unsigned char *)arg0)[11];
    ((unsigned char *)arg0)[11]=a;
    ((unsigned char *)arg0)[9]=((unsigned char *)arg0)[10];
    ((unsigned char *)arg0)[10]=b;
    do {
        a=p[0]; p[0]=p[3]; p[3]=a;
        b=p[1]; p[1]=p[2]; p[2]=b;
        p+=4; i++;
    } while (i < ((unsigned char *)arg0)[8] * ((unsigned char *)arg0)[8]);
}

void fn_80137F30(void);
void fn_80137F74(void *);
void fn_80137FF0(void);
void fn_801380DC(void *);
extern char lbl_8032BF00[];
void fn_802E317C(char *, ...);
void fn_80138144(void *arg0) {
    unsigned char a = *((unsigned char *)arg0);
    unsigned char b = *((unsigned char *)arg0 + 1);
    *((unsigned char *)arg0) = *((unsigned char *)arg0 + 3);
    *((unsigned char *)arg0 + 3) = a;
    *((unsigned char *)arg0 + 1) = *((unsigned char *)arg0 + 2);
    *((unsigned char *)arg0 + 2) = b;
    switch (*(int *)arg0) {
    case 2: fn_80137FF0(); break;
    case 0: fn_80137F30(); break;
    case 1: fn_80137F74((char *)arg0 + 8); break;
    case 3: fn_801380DC(arg0); break;
    default: fn_802E317C(lbl_8032BF00); break;
    }
}

void fn_80138434(void) {
    fn_80137F2C();
}

void *fn_80138438(void *arg0) { void *node; void *best; node=*(void **)((char *)arg0+0x14); best=arg0; while(node!=arg0) { if(*(unsigned int *)((char *)node+0x10)>*(unsigned int *)((char *)best+0x10)) best=node; node=*(void **)((char *)node+0x14); } return best; }

void *fn_8013846C(void *arg0) {
    void *node;
    void *best;

    node = *(void **)((char *)arg0 + 0x14);
    best = arg0;
    while (node != arg0) {
        if (*(unsigned int *)((char *)node + 0x10) < *(unsigned int *)((char *)best + 0x10)) {
            best = node;
        }
        node = *(void **)((char *)node + 0x14);
    }
    return best;
}

void fn_801384A0();
void fn_801386D0(float, float, float);
void fn_80138958(void *, float *);
void fn_80138594(void *arg0) {
    void *node;

    node = *(void **)((char *)arg0 + 0x24);
    while (node != 0) {
        if (*(unsigned int *)node == 1) {
            fn_80138958(arg0, (float *)((char *)node + 8));
        }
        node = *(void **)((char *)node + 4);
    }
}

extern float lbl_80561398, lbl_8056139C, lbl_805613A0, lbl_805613A4, lbl_805613A8, lbl_805613AC;
extern float __fabsf(float);
float fn_801385F0(float arg0, float arg1, float arg2, float arg3) {
    float diff = arg0 - arg2;
    float value;
    if (__fabsf(diff) > arg1 * lbl_80561398) {
        float adjust = diff > lbl_805613A4 ? lbl_8056139C : lbl_805613A0;
        diff -= arg1 * adjust;
    }
    value = lbl_8056139C - __fabsf(diff) / arg3;
    if (lbl_8056139C < value) value = lbl_8056139C;
    if (lbl_805613A4 > value) value = lbl_805613A4;
    if (value < lbl_805613A0) return lbl_805613A0;
    if (value > lbl_8056139C) return lbl_8056139C;
    if (value > lbl_805613A4)
        return (value * (lbl_805613A8 * value * value)) + (lbl_805613AC * value * value);
    return (value * (lbl_805613A8 * value * value)) - (lbl_805613AC * value * value);
}

extern float lbl_805613A4;
int fn_801388F4(void *arg0) { float spC,sp8,temp_f2,temp_f4; double temp_f3; void *p; p=*(void **)((char*)arg0+0x14); sp8=*(float*)((char*)arg0+8); spC=*(float*)((char*)arg0+0xC); temp_f3=-sp8; temp_f4=(float)temp_f3; temp_f2=spC**(float*)((char*)p+8); sp8=spC; spC=(float)temp_f3; if(temp_f2+temp_f4**(float*)((char*)p+0xC)<lbl_805613A4)return 1;return 0; }

void fn_80138958(void *arg0, float *arg1) { fn_801386D0(arg1[0], arg1[1], arg1[2]); }

void fn_80138AD8(void **arg0) { void *p=*arg0; fn_8013C428(*(int*)((char*)p+0x28),p); fn_8012C4D8(*arg0); *arg0=0; }

void *fn_80138B1C(void *arg0) { void *p=*(void **)((char*)arg0+0x24); void *result=0; while(p){ if(*(int*)p==0){result=p;break;} p=*(void **)((char*)p+4); } return result; }

void *fn_80138B4C(void *arg0, void *arg1) {
    void *node;
    void *result;
    node = arg1 != 0 ? *(void **)((char *)arg1 + 4) : 0;
    result = 0;
    if (node == 0) node = *(void **)((char *)arg0 + 0x24);
    while (node != 0) {
        if (*(unsigned int *)node == 2) {
            result = node;
            break;
        }
        node = *(void **)((char *)node + 4);
    }
    return result;
}

void fn_80138BA0(void *arg0, void *arg1) {
    if (arg0 != arg1) {
        fn_801384A0();
    }
}

