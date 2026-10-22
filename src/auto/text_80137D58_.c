// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80137F2C(void) {

}

void fn_80137F30(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned char a = base[8];
    unsigned char b = base[9];
    unsigned char c = base[0xc];
    unsigned char d = base[0xd];
    base[8] = base[0xb];
    base[0xb] = a;
    base[9] = base[0xa];
    base[0xa] = b;
    base[0xc] = base[0xf];
    base[0xf] = c;
    base[0xd] = base[0xe];
    base[0xe] = d;
}

void fn_80137F74(void *arg0) {
    unsigned char a0 = ((unsigned char *)arg0)[0];
    unsigned char a1 = ((unsigned char *)arg0)[1];
    unsigned char a4 = ((unsigned char *)arg0)[4];
    unsigned char a5 = ((unsigned char *)arg0)[5];
    unsigned char a8 = ((unsigned char *)arg0)[8];
    unsigned char a9 = ((unsigned char *)arg0)[9];
    ((unsigned char *)arg0)[0] = ((unsigned char *)arg0)[3];
    ((unsigned char *)arg0)[3] = a0;
    ((unsigned char *)arg0)[1] = ((unsigned char *)arg0)[2];
    ((unsigned char *)arg0)[2] = a1;
    ((unsigned char *)arg0)[4] = ((unsigned char *)arg0)[7];
    ((unsigned char *)arg0)[7] = a4;
    ((unsigned char *)arg0)[5] = ((unsigned char *)arg0)[6];
    ((unsigned char *)arg0)[6] = a5;
    ((unsigned char *)arg0)[8] = ((unsigned char *)arg0)[0xb];
    ((unsigned char *)arg0)[0xb] = a8;
    ((unsigned char *)arg0)[9] = ((unsigned char *)arg0)[0xa];
    ((unsigned char *)arg0)[0xa] = a9;
}

void fn_80137FF0(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned char a = base[8];
    unsigned char b = base[9];
    unsigned char c = base[0xc];
    unsigned char d = base[0xd];
    unsigned char e = base[0x10];
    unsigned char f = base[0x11];
    unsigned char *p;
    int i;
    base[8] = base[0xb];
    base[0xb] = a;
    base[9] = base[0xa];
    base[0xa] = b;
    base[0xc] = base[0xf];
    base[0xf] = c;
    base[0xd] = base[0xe];
    base[0xe] = d;
    base[0x10] = base[0x13];
    base[0x13] = e;
    base[0x11] = base[0x12];
    base[0x12] = f;
    p = base + 0x14;
    for (i = 0; i < *(int *)(base + 8); i++) {
        a = p[0];
        b = p[1];
        c = p[2];
        d = p[3];
        p[0] = p[3];
        p[3] = a;
        p[1] = p[2];
        p[2] = b;
        a = p[4];
        b = p[5];
        p[4] = p[7];
        p[7] = a;
        p[5] = p[6];
        p[6] = b;
        p += 8;
    }
}

void fn_801380DC(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned char a = base[8];
    unsigned char *p = base + 12;
    unsigned char b = base[9];
    int i;
    unsigned char c;
    base[8] = base[11];
    base[11] = a;
    base[9] = base[10];
    base[10] = b;
    for (i = 0; i < *(int *)(base + 8) * *(int *)(base + 8); i++) {
        a = p[0];
        c = p[3];
        p[0] = c;
        p[3] = a;
        a = p[1];
        c = p[2];
        p[1] = c;
        p[2] = a;
        p += 4;
    }
}

void fn_80137F30(void *);
void fn_80137F74(void *);
void fn_80137FF0(void *);
void fn_801380DC(void *);
extern char lbl_8032BF00[];
void fn_802E317C(char *, ...);
#pragma dont_inline fn_80137F30
#pragma dont_inline fn_80137F74
#pragma dont_inline fn_80137FF0
#pragma dont_inline fn_801380DC
void fn_80138144(void *arg0) {
    unsigned char a = *((unsigned char *)arg0);
    unsigned char b = *((unsigned char *)arg0 + 1);
    *((unsigned char *)arg0) = *((unsigned char *)arg0 + 3);
    *((unsigned char *)arg0 + 3) = a;
    *((unsigned char *)arg0 + 1) = *((unsigned char *)arg0 + 2);
    *((unsigned char *)arg0 + 2) = b;
    switch (*(int *)arg0) {
    case 2: fn_80137FF0(arg0); break;
    case 0: fn_80137F30(arg0); break;
    case 1: fn_80137F74((char *)arg0 + 8); break;
    case 3: fn_801380DC(arg0); break;
    default: fn_802E317C(lbl_8032BF00); break;
    }
}

#pragma dont_inline on
void fn_80138434(void) {
    fn_80137F2C();
}
#pragma dont_inline reset
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

void fn_80128670(void *);
void fn_8013530C(void *, int);
void fn_80135DC4(void *, int, int);
void fn_80135F64(void *, void *, void *, int, int);
void fn_80136068(void *, void *, int);
void *fn_80138438(void *);
void *fn_8013846C(void *);
void fn_801384A0(void *arg0, int arg1) {
    char sp[0x50];
    int value;
    int max;
    void *node;
    void *head;
    fn_80135DC4(sp, 1, arg1);
    head = *(void **)((char *)arg0 + 0x1C);
    fn_80135F64(sp, head, (char *)head + 8, 0, 0);
    node = *(void **)((char *)arg0 + 0x1C);
    do {
        fn_80136068(sp, node, 0);
        *(float *)((char *)node + 0x2C) = *(float *)(sp + 0x40);
        *(int *)((char *)node + 0x10) = *(int *)((char *)*(void **)(sp + 4) + 0x10);
        node = *(void **)((char *)node + 0x14);
    } while (node != *(void **)((char *)arg0 + 0x1C));
    node = fn_80138438(node);
    head = fn_8013846C(node);
    *(int *)((char *)head + 0x10) = 0;
    node = head;
    max = 0;
    do {
        value = *(int *)((char *)node + 0x10);
        if (max > value) {
            value = max;
            *(int *)((char *)node + 0x10) = value;
        }
        max = value;
        node = *(void **)((char *)node + 0x14);
    } while (node != head);
    if (*(void **)(sp + 0x50) != 0) fn_80128670(*(void **)(sp + 0x50));
    *(void **)(sp + 0x50) = 0;
    fn_8013530C(sp, 0);
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
        return lbl_805613A8 * value * value * value + lbl_805613AC * value * value;
    return lbl_805613A8 * value * value * value - lbl_805613AC * value * value;
}

extern float lbl_805613A4;
int fn_801388F4(void *arg0) { float spC,sp8,temp_f2,temp_f4; double temp_f3; void *p; p=*(void **)((char*)arg0+0x14); sp8=*(float*)((char*)arg0+8); spC=*(float*)((char*)arg0+0xC); temp_f3=-sp8; temp_f4=(float)temp_f3; temp_f2=spC**(float*)((char*)p+8); sp8=spC; spC=(float)temp_f3; if(temp_f2+temp_f4**(float*)((char*)p+0xC)<lbl_805613A4)return 1;return 0; }

void fn_80138958(void *arg0, float *arg1) { fn_801386D0(arg1[0], arg1[1], arg1[2]); }

extern void *fn_8012C370(int, unsigned int *, int *, void **, unsigned char *);
extern void fn_8012C4D8(void *);
extern void fn_801381B4(void *);
extern void fn_80138594(void *);
extern int fn_8013BFE8(int);
extern void fn_802E30C8(char *, ...);
extern char lbl_8032BF20[];
extern char lbl_8032BF70[];
void *fn_80138968(int arg0) {
    unsigned int size;
    int valid;
    void *data;
    unsigned char swap;
    int ok = 0;
    void *obj = fn_8012C370(0x494C494E, &size, &valid, &data, &swap);
    if (obj != 0) {
        if (valid != 0) {
            if (size == 0x1E) {
                unsigned int *words = (unsigned int *)obj;
                unsigned int a = words[0], b = words[1];
                if (swap) {
                    unsigned char *p = (unsigned char *)&a;
                    unsigned char *q = (unsigned char *)&b;
                    unsigned char t;
                    t=p[0]; p[0]=p[3]; p[3]=t;
                    t=p[1]; p[1]=p[2]; p[2]=t;
                    t=q[0]; q[0]=q[3]; q[3]=t;
                    t=q[1]; q[1]=q[2]; q[2]=t;
                }
                if (a == 0x3C && b == 0x30) {
                    if (swap) {
                        fn_801381B4(obj);
                        fn_80138594(obj);
                    }
                    *(int *)((char *)obj + 0x28) = fn_8013BFE8(arg0);
                    ok = 1;
                } else {
                    fn_802E30C8(lbl_8032BF20, 0x3C, b, 0x30, swap);
                }
            } else {
                fn_802E30C8(lbl_8032BF70, 0x1E);
            }
        }
        if (!ok) {
            fn_8012C4D8(obj);
            obj = 0;
        }
    }
    return obj;
}

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

