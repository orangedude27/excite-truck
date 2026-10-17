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
extern int fn_802E30C8(void *);
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
int fn_80245264(void *arg0) {
    int result;
    result = fn_802C5130(lbl_80342FC0 + 0x60);
    *(int *)((char *)arg0 + 4) = result;
    if (result == 0) fn_802E30C8(lbl_80342FC0 + 0x78);
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 0x10) = fn_80232578(lbl_80342FC0 + 0xB4);
    *(int *)((char *)arg0 + 0xC) = fn_80232578(lbl_80342FC0 + 0xB4);
    *(float *)((char *)arg0 + 0x14) = lbl_80563830;
    return 0;
}

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

void fn_80245D2C(void *arg0) {
 unsigned char result;
 result=*(unsigned char*)((char*)arg0+0x1D);
 *(unsigned char*)((char*)arg0+0x1C)=0;
 if(result==0) {
   void **obj=(void**)((char*)arg0+4);
   ((void(*)(void*))(*(void**)((char*)*obj+0xC)))((char*)arg0+4);
 }
 fn_80214D50(4);
}

int fn_802461D0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

void fn_80246210(void) {
    int i;
    int count;

    i = 0;
    *((char *)lbl_8055F244 + 0x1E) = 0;
    count = *(int *)((char *)*(void **)((char *)lbl_8055F244 + 0x20) + 0x14);
    do {
        fn_80214AF0(i);
        i++;
    } while (i < count);
    do {
        fn_80214B44(count);
        fn_80214A9C(count);
        count++;
    } while (count < 4);
    fn_80214CB4(*(int *)((char *)*(void **)((char *)lbl_8055F244 + 0x20) + 0x10));
}

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

