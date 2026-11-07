// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80214CB4(int);
extern int fn_80235380(int);
extern int fn_80128668(void *);
extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
extern int fn_80214B44(int);
extern void *lbl_803430E8;
extern void *lbl_8055F244;
extern int fn_80232578(void *);
extern int fn_802C5130(void *);
extern int fn_802C519C(void *);
extern void fn_802E30C8(const char *, ...);
extern int fn_802328D4(void *);
extern int fn_802451DC(void *, int);
extern int fn_8024521C(void *, int);
extern int fn_80245264(void *);
extern int fn_802452E4(void *);
int fn_802451DC(void *arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668(arg0);
    return (int)arg0;
}

int fn_8024521C(void *arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055F244 = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return (int)arg0;
}

extern char lbl_80342FC0[];
extern float lbl_80563830;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
int fn_80245264(void *arg0) {
    char *base = lbl_80342FC0;
    int result;
    float value;

    result = fn_802C5130(base + 0x60);
    *(int *)((char *)arg0 + 4) = result;
    if (result == 0) {
        fn_802E30C8(base + 0x78);
    }
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 0x10) = fn_80232578(base + 0xB4);
    result = fn_80232578(base + 0xB4);
    value = lbl_80563830;
    *(int *)((char *)arg0 + 0xC) = result;
    *(float *)((char *)arg0 + 0x14) = value;
}
#pragma scheduling on
#pragma pop

extern int lbl_8055CFF0, lbl_8055CFF4, lbl_8055FB9C, lbl_8055FBA0;
extern float lbl_80563834, lbl_80563838, lbl_8056383C, lbl_80563840, lbl_80563844, lbl_80563848, lbl_8056384C, lbl_80563850, lbl_80563854, lbl_80563858, lbl_8056385C, lbl_80563860, lbl_80563864, lbl_80563868, lbl_8056386C, lbl_80563870, lbl_80563874, lbl_80563878, lbl_8056387C, lbl_80563888, lbl_8056388C, lbl_80563890;
extern char lbl_80343080[];
extern char lbl_8055BE50, lbl_8055BE58, lbl_8055BE5C;
extern int fn_80129AFC(void);
extern int fn_802E47B8(void);
extern int fn_802E46F0(void);
extern int fn_802E2D74(int);
extern int fn_802E2C20(void);
extern double sin(double);
extern void fn_802C5310(int, int, float, float, float);
extern void fn_802337A0(int, int, int, void *, void *, ...);
extern float lbl_80558DC4[];
extern char lbl_8055BE60, lbl_8055BE64;
extern void fn_802C8530(void);
extern void fn_802C87B4(int, int, int, int);
extern void fn_802C88BC(int);
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(float, float, float);
extern void fn_802C5320(int, float, float, float, float, float, int);
extern void fn_802C92D0(void);
extern void fn_802C92DC(int, int, int, int, int);
extern void fn_802C92D8(void);
extern void fn_80232BA4(char *, int, int, int, float, float, float, float, float);
extern float fn_8023293C(int, char *, float);
extern void fn_80028E00(char *, char *);
extern void fn_802335F0(char *, int, float, float);
extern void fn_802C9A70(int);
extern void fn_802C855C(void);
extern void fn_802C2B48(void);
extern char *strcpy(char *, const char *);

int fn_802452E4(void *arg0) {
    void *value;
    value = *(void **)((char *)arg0 + 4);
    if (value) fn_802C519C(value);
    value = *(void **)((char *)arg0 + 8);
    *(int *)((char *)arg0 + 4) = 0;
    if (value) fn_802C519C(value);
    *(int *)((char *)arg0 + 8) = 0;
    fn_802328D4(*(void **)((char *)arg0 + 0xC));
    fn_802328D4(*(void **)((char *)arg0 + 0x10));
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
    return 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern double fabs(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_unroll_loops off
extern double __fabs(double);
void fn_8024590C(int *a, int *b) {
    char obj[0x30];
    char tail[0x40];
    struct { int a, b; } buf[64];
    char text[0x200];
    char *s, *split, *p;
    int i, j, n, save;
    float step, shadow, limit, y, h, w, f, x1, x0;
    fn_802C8530();
    fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
    fn_802C88BC(2);
    fn_80230B5C(obj);
    fn_802C8638(obj);
    fn_802C974C(lbl_80563834, lbl_80563838, lbl_8056383C);
    w = (float)(lbl_8055FB9C + 1);
    h = (float)(lbl_8055FBA0 + 1);
    x0 = lbl_80563840 * (float)lbl_8055FB9C * lbl_80563844 - lbl_80563834;
    x1 = lbl_80563834 + (float)lbl_8055FBA0 * lbl_80563844;
    if (a[1] != 0) {
        fn_802C5320(a[1], x0, x1, lbl_80563830, w, h, 0);
    } else {
        fn_802C92D0();
        fn_802C92DC(0, 0, (int)w, (int)h, 0xFF000000);
        fn_802C92D8();
    }
    s = (char *)b[0];
    split = (char *)b[1];
    y = lbl_80563848;
    if (strlen(s) != 0) {
        fn_80232BA4(s, a[3], 0xFF000000, 12, lbl_8056384C + ((float *)a)[5], y - lbl_8056384C, lbl_80563834, lbl_80563830, lbl_80563834);
        fn_80232BA4(s, a[3], -1, 12, ((float *)a)[5], y, lbl_80563834, lbl_80563830, lbl_80563834);
    }
    y -= lbl_80563850;
    strcpy(text, split);
    limit = lbl_80563854;
    shadow = lbl_8056384C;
    step = lbl_8056385C;
    s = text;
    while (strlen(s) != 0) {
        for (i = 0; i < 64; i++) { buf[i].a = 0; buf[i].b = 0; }
        split = 0;
        j = 0;
        do {
            p = s + j;
            if (*p == 32) split = p;
            else if (*p == 94) *p = 32;
            ((char *)buf)[j] = *p;
            j++;
            ((char *)buf)[j] = 0;
        } while ((unsigned)j < strlen(s) && fn_8023293C(a[3], (char *)buf, lbl_80563834) < limit);
        save = 0;
        if ((unsigned)j != strlen(s)) {
            if (split == 0) {
                split = s + j;
                save = *split;
            }
            *split = 0;
        } else {
            split = s + j - 1;
        }
        fn_80232BA4(s, a[3], 0xFF000000, 12, shadow + ((float *)a)[5], y - shadow, lbl_80563858, lbl_80563830, lbl_80563834);
        fn_80232BA4(s, a[3], -1, 12, ((float *)a)[5], y, lbl_80563858, lbl_80563830, lbl_80563834);
        if (save == 0) s = split + 1;
        else { *split = save; s = split; }
        y -= step;
    }
    f = ((float *)b)[2];
    if (!((float)__fabs(f) <= lbl_80558DC4[0])) {
        strcpy(tail, &lbl_8055BE60);
        n = (int)(lbl_80563888 * f);
        for (i = 0; i < n; i++) fn_80028E00(tail, &lbl_8055BE64);
        fn_802335F0(tail, a[4], lbl_8056388C, lbl_80563890);
    }
    fn_802C9A70(1);
    fn_802C855C();
    fn_802C2B48();
}
#pragma pop

extern int fn_8012C33C(void *, void *);
extern int fn_80214D50(int);
extern char lbl_8034308C[];
void fn_80245CC8(void *arg0) {
 unsigned char result;
 *(unsigned char*)((char*)arg0+0x1C)=1;
 result=fn_8012C33C(lbl_8034308C, 0);
 *(unsigned char*)((char*)arg0+0x1D)=result;
 if(result==0) {
   void **obj=(void**)((char*)arg0+4);
   ((void(*)(void*))(*(void**)((char*)*obj+8)))((char*)arg0+4);
 }
 *(unsigned char*)((char*)arg0+0x1E)=1;
}

#pragma cplusplus on
extern "C" void fn_80245D2C(void *arg0) {
    unsigned char result;
    *(unsigned char *)((char *)arg0 + 0x1C) = 0;
    result = *(unsigned char *)((char *)arg0 + 0x1D);
    if (result == 0) {
        struct Dummy {
            virtual void f0();
            virtual void f1();
            virtual void f2();
            virtual void f3();
        };
        ((Dummy *)((char *)arg0 + 4))->f1();
    }
    fn_80214D50(4);
}
#pragma cplusplus reset
int fn_802461D0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

void fn_80246210(void) {
    int count;
    int i;
    int zero;

    zero = 0;
    *((char *)lbl_8055F244 + 0x1E) = (char)zero;
    i = 0;
    count = *(int *)((char *)*(void **)((char *)lbl_8055F244 + 0x20) + 0x14);
    while (i < count) {
        fn_80214AF0(i);
        i++;
    }
    while (count < 4) {
        fn_80214B44(count);
        fn_80214A9C(count);
        count++;
    }
    fn_80214CB4(*(int *)((char *)*(void **)((char *)lbl_8055F244 + 0x20) + 0x10));
}

extern int fn_8023512C(void *);
extern int fn_80216CA8(int, int, int, int, void *, int, int, int);
extern int fn_802146BC(int *, int, int, int);
extern int strlen(const char *);
extern char lbl_803430CC[];
extern char lbl_803430D8[];
__declspec(section ".sdata") extern void *lbl_8055BE70;
__declspec(section ".sdata") extern void *lbl_8055BE78;
extern int lbl_80498890[5];
extern int lbl_802FA350[5];
#pragma cplusplus on
#pragma small_data off
#pragma scheduling invalid_target
extern "C" void fn_802462A0(register void *arg0, register void *arg1) {
    struct Frame {
        unsigned int args[5];
        int pad;
        struct {
            void *object;
            int unused[4];
            int zero;
            float value;
            int result;
        } state;
        unsigned int config[20];
    };
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
    };
    struct Frame frame;
    int firstLength;
    int firstPointer;
    int secondLength;
    int secondPointer;

    if (*(unsigned char *)((char *)arg0 + 0x1D) == 0) {
        ((Dummy *)((char *)arg0 + 4))->f3();
        return;
    }
    frame.state.value = *(float *)((char *)arg1 + 8);
    frame.state.object = &lbl_803430E8;
    frame.state.zero = 0;
    frame.state.result = fn_8023512C(&lbl_803430CC);

    firstLength = strlen(*(char **)arg1);
    firstPointer = *(int *)arg1;
    frame.config[3] = firstLength;
    frame.config[0] = (unsigned int)&lbl_8055BE70;
    frame.config[1] = 3;
    frame.config[2] = firstPointer;
    frame.config[4] = 0;

    secondPointer = *(int *)((char *)arg1 + 4);
    secondLength = strlen((char *)secondPointer);
    frame.config[5] = (unsigned int)&lbl_8055BE78;
    frame.config[6] = 3;
    frame.config[7] = secondPointer;
    frame.config[8] = secondLength;
    frame.config[9] = 0;

    frame.config[10] = (unsigned int)&lbl_803430D8;
    frame.config[11] = 5;
    frame.config[12] = (unsigned int)&frame.state;
    frame.config[13] = 0;
    frame.config[14] = 0;
    frame.config[15] = lbl_80498890[0];
    frame.config[16] = lbl_80498890[1];
    frame.config[17] = lbl_80498890[2];
    frame.config[18] = lbl_80498890[3];
    frame.config[19] = lbl_80498890[4];

    frame.args[0] = lbl_802FA350[0];
    frame.args[1] = lbl_802FA350[1];
    frame.args[2] = lbl_802FA350[2];
    frame.args[3] = lbl_802FA350[3];
    frame.args[4] = lbl_802FA350[4];
    frame.args[1] = (unsigned int)&frame.config[0];

    *(int *)((char *)arg0 + 0x24) = 0;
    fn_80216CA8(lbl_802FA350[4], lbl_802FA350[3], lbl_802FA350[2],
                lbl_802FA350[0], lbl_802FA350, lbl_80498890[1],
                lbl_80498890[0], 5);
    fn_802146BC((int *)frame.args, -0x3E7, -0x3E7, 1);
    frame.state.object = &lbl_803430E8;
    if (frame.state.result != 0)
        fn_80235380(frame.state.result);
}
#pragma scheduling on
#pragma small_data on
#pragma cplusplus reset

void *fn_80246428(void *arg0, int arg1) {
    int temp_r0;

    if (arg0 != 0) {
        temp_r0 = *(int *)((char *)arg0 + 0x1C);
        *(void **)arg0 = lbl_803430E8;
        if (temp_r0 != 0) {
            fn_80235380(temp_r0);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_80246498(void *arg0) {
    fn_80214CB4(*(unsigned char *)((char *)arg0 + 0x18) == 0);
}

void fn_802464A8(void *arg0) {
    *((signed char *)arg0 + 0x19) = 0;
}

extern int fn_80230E90(int);
extern int fn_80216D28(void);
int fn_802464B4(void *arg0, int arg1) {
    switch (arg1) {
    case 0x125:
        if (*(unsigned char *)((char *)arg0 + 0x19) == 0) {
            fn_80214CB4(0); fn_80230E90(0);
        } else fn_80216D28();
        goto done;
    case 0x127:
        if (*(unsigned char *)((char *)arg0 + 0x19) == 0) {
            fn_80214CB4(1); fn_80230E90(0);
        } else fn_80216D28();
        goto done;
    case 0x126:
        if (*(unsigned char *)((char *)arg0 + 0x19) != 0) {
            fn_80214CB4(0); fn_80230E90(0);
        } else fn_80216D28();
        goto done;
    case 0x128:
        if (*(unsigned char *)((char *)arg0 + 0x19) != 0) {
            fn_80214CB4(1); fn_80230E90(0);
        } else fn_80216D28();
        goto done;
    default: return 0;
    }
done:
    return 1;
}

extern void fn_80230C30(float *, float *, int, int);
extern void fn_80230924(int, float, float, float, float, float);
extern float fn_80235EF0(int, int);
extern float fn_80235F64(int, int);
extern void fn_802353F4(int, int, float, float, float);
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern void fn_80235758(int, int, int, float, float, float, float, float, float, float, float);
extern float lbl_80563834;
extern float lbl_80563844;
#pragma push
#pragma processor 750
void fn_802465A4(void *arg0) {
    float x, y, xpos;
    float width, height, left, right, mid, total, barheight, fill, part;
    int obj;
    fn_80230C30(&x, &y, *(int *)((char *)arg0+4), *(int *)((char *)arg0+8));
    width = (float)*(int *)((char *)arg0+0xc);
    height = (float)*(int *)((char *)arg0+0x10);
    obj = *(int *)((char *)arg0+0x1c);
    if (obj) {
        left = fn_80235EF0(obj, 0);
        right = fn_80235EF0(*(int *)((char *)arg0+0x1c), 2);
        mid = (width-left)-right;
        total = right+(left+mid);
        barheight = fn_80235F64(*(int *)((char *)arg0+0x1c), 0);
        x = (x + lbl_80563844*width) - lbl_80563844*total;
        y = (y + lbl_80563844*height) - lbl_80563844*barheight;
        fill = total * *(float *)((char *)arg0+0x18);
        if (fill < left) {
            fn_80235758(*(int *)((char *)arg0+0x1c), 3, -1, x, y, fill, barheight, lbl_80563830, lbl_80563830, fill/left, lbl_80563834);
        } else if (fill < left+mid) {
            fn_802353F4(*(int *)((char *)arg0+0x1c), 3, x, y, lbl_80563830);
            part = fill-left;
            fn_80235758(*(int *)((char *)arg0+0x1c), 4, -1, x+left, y, part, barheight, lbl_80563830, lbl_80563830, part/mid, lbl_80563834);
        } else {
            fn_802353F4(*(int *)((char *)arg0+0x1c), 3, x, y, lbl_80563830);
            fn_802354A0(*(int *)((char *)arg0+0x1c), 4, -1, x+left, y, lbl_80563830, mid, barheight);
            xpos = x+left;
            part = (fill-left)-mid;
            fn_80235758(*(int *)((char *)arg0+0x1c), 5, -1, mid+xpos, y, part, barheight, lbl_80563830, lbl_80563830, part/right, lbl_80563834);
        }
        fn_802353F4(*(int *)((char *)arg0+0x1c), 0, x, y, lbl_80563830);
        fn_802354A0(*(int *)((char *)arg0+0x1c), 1, -1, x+left, y, lbl_80563830, mid, barheight);
        fn_802353F4(*(int *)((char *)arg0+0x1c), 2, mid+(x+left), y, lbl_80563830);
    } else {
        fn_80230924(-1, x, y, x+width* *(float *)((char *)arg0+0x18), y-height, lbl_80563830);
    }
}
#pragma pop
extern int fn_80129AF4(void);
extern int fn_801298E8(void *, int);
extern int fn_80214FD8(const char *, const char *);
extern char lbl_80343210[];
extern char lbl_80343224[];
void fn_8024683C(void) {
    unsigned char data[0xD0];
    int found;
    int i;
    int result;

    result = fn_80129AF4();
    found = 0;
    if (result == -1) {
        i = 0;
        do {
            if (fn_801298E8(data + 0x64, i) != 0 && (*(unsigned int *)(data + 0xB4) & 1) != 0) {
                found = 1;
            }
            i++;
        } while (i < 4);
    } else if (fn_801298E8(data, result) != 0 && (*(unsigned int *)(data + 0x50) & 1) != 0) {
        found = 1;
    }
    if (found != 0) {
        fn_80214FD8(lbl_80343210, lbl_80343224);
    }
}

