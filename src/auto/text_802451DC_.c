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
extern void *lbl_803430CC;
extern void *lbl_803430D8;
extern void *lbl_8055BE70;
extern void *lbl_8055BE78;
extern int lbl_80498890[5];
extern int lbl_802FA350[5];
#pragma cplusplus on
extern "C" void fn_802462A0(void *arg0, void *arg1) {
    struct Frame {
        int args[5];
        int pad;
        struct {
            void *object;
            int unused[4];
            int zero;
            float value;
            int result;
        } state;
        int config[20];
    };
    struct Frame frame;
    char *a;
    char *b;
    void **obj;

    if (*(unsigned char *)((char *)arg0 + 0x1D) == 0) {
        obj = (void **)((char *)arg0 + 4);
        ((void (*)(void *))(*(void **)((char *)*obj + 0x14)))((char *)arg0 + 4);
        return;
    }

    frame.state.value = *(float *)((char *)arg1 + 8);
    frame.state.object = &lbl_803430E8;
    frame.state.zero = 0;
    frame.state.result = fn_8023512C(&lbl_803430CC);

    a = *(char **)arg1;
    frame.config[3] = strlen(a);
    frame.config[2] = (int)a;
    frame.config[0] = (int)&lbl_8055BE70;
    frame.config[1] = 3;
    frame.config[4] = 0;

    b = *(char **)((char *)arg1 + 4);
    frame.config[8] = strlen(b);
    frame.config[7] = (int)b;
    frame.config[5] = (int)&lbl_8055BE78;
    frame.config[6] = 3;
    frame.config[9] = 0;

    frame.config[10] = (int)&lbl_803430D8;
    frame.config[11] = 5;
    frame.config[12] = (int)&frame.state;
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
    frame.args[1] = (int)&frame.config[0];

    *(int *)((char *)arg0 + 0x24) = 0;
    fn_80216CA8(lbl_802FA350[4], lbl_802FA350[3], lbl_802FA350[2],
                lbl_802FA350[0], lbl_802FA350, lbl_80498890[1],
                lbl_80498890[0], 5);
    fn_802146BC(frame.args, -999, -999, 1);
    frame.state.object = &lbl_803430E8;
    if (frame.state.result != 0)
        fn_80235380(frame.state.result);
}
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

