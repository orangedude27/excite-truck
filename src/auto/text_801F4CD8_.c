// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055EC18;
extern void *lbl_8055EC14;
extern void *lbl_8055EC10;
extern void *lbl_8055EC1C;
extern void *lbl_8055EC20;
extern char lbl_8033ACE8[32];
extern void *fn_801284F8(int, void *);
extern char lbl_8033AC68[];
extern char *lbl_8033AC9C[5];
extern char lbl_8033AD08[];
extern int stricmp(const char *, const char *);
extern void fn_8012F9E8(void *, void *, void *);
extern void fn_801F7160(void *);
extern void fn_801F7220(void *);
extern void *fn_802AE414(void);
extern void fn_802E317C(const char *, ...);
extern void fn_801F7280(void *, void *, void *);
extern void fn_801F70D0(void *, int);
extern void fn_801F6D60(void *, int);
extern void fn_801F6A08(void *, int);
extern void fn_801F75A4(void *, void *, void *);
void fn_801F4D64(void) {
    fn_801F70D0(lbl_8055EC18, 1);
    lbl_8055EC18 = 0;
    fn_801F6D60(lbl_8055EC14, 1);
    lbl_8055EC14 = 0;
    fn_801F6A08(lbl_8055EC10, 1);
    lbl_8055EC10 = 0;
    lbl_8055EC1C = 0;
    lbl_8055EC20 = 0;
}

void fn_801F4DC4(void) {
    fn_801F7160(lbl_8055EC18);
}

void fn_801F4DCC(void) {
    fn_801F7220(lbl_8055EC18);
}

void fn_801F4DD4(void *arg0, void *arg1) {
    void *temp_r3;
    temp_r3 = fn_802AE414();
    if (temp_r3 == 0) {
        fn_802E317C(lbl_8033ACE8, arg0);
    }
    fn_801F7280(lbl_8055EC18, temp_r3, arg1);
}

extern void *fn_801284F8(int, void *);
extern char lbl_8033AC68[];
extern char *lbl_8033AC9C[5];
extern char lbl_8033AD08[];
extern int stricmp(const char *, const char *);
extern void fn_8012F9E8(void *, void *, void *);
extern void fn_80128670(int);
int fn_801F4E44(const char *arg0) {
    int i;
    i = 0;
    while (i < 5) {
        if (stricmp(arg0, lbl_8033AC9C[i]) == 0) {
            return i + 1;
        }
        i++;
    }
    fn_802E317C(lbl_8033AD08, arg0);
    return 0;
}

extern char lbl_8033AD28[];
extern char lbl_8033AD34[];
extern char lbl_8055B168[];
extern char lbl_8055B170[];
__declspec(section ".sdata") extern char lbl_8055B168[];
__declspec(section ".sdata") extern char lbl_8055B170[];
int fn_801F4ECC(void *arg0) {
    int result = 0;
    void **vtable = *(void ***)arg0;
    int (*call)(void *, const char *, int) = (int (*)(void *, const char *, int))vtable[12];
    if (call(arg0, lbl_8055B168, 0)) result |= 1;
    call = (int (*)(void *, const char *, int))(*(void ***)arg0)[12];
    if (call(arg0, lbl_8033AD28, 0)) result |= 2;
    call = (int (*)(void *, const char *, int))(*(void ***)arg0)[12];
    if (call(arg0, lbl_8055B170, 0)) result |= 4;
    if ((result & 1) && (result & 4)) fn_802E317C(lbl_8033AD34);
    return result;
}

typedef int (*F0)(void);
typedef void *(*F2)(void *, void *);
int fn_801F52BC(void **arg0, int arg1, int arg2, int arg3, int arg4) { int result = 0; if (((int (*)(void *))(*(void ***)arg0)[3])(arg0) != 0) { result = ((int (*)(int, int, int))fn_8012F9E8)(arg2, arg3, ((int (*)(void **, int))(*(void ***)arg0)[5])(arg0, arg1)); } return result; }

void fn_801F596C(void) {

}

void fn_801F6358(void *arg0) {
    int temp;
    fn_80128670(*(int *)((char *)arg0 + 0xC));
    temp = *(int *)arg0;
    if (temp != 0) {
        fn_80128670(temp - 0x10);
    }
}

#pragma dont_inline on
void fn_801F639C(void *arg0) {
    int temp_r4 = *(int*)((char*)arg0 + 0x1C);
    if (temp_r4 != 0) {
        fn_80128670(temp_r4 - 0x10);
    }
    fn_80128670(*(int*)((char*)arg0 + 0x14));
    fn_801F6358(arg0);
    fn_802CAC54(*(int*)((char*)arg0 + 0x24));
}

extern float lbl_80562FB0;
extern float lbl_80562FD4;
extern float lbl_80562FD8;
void fn_801F64E4(void *arg0, float *arg1, float arg2) {
    float sp10, spC, sp8;
    float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10;
    int r0, r4, r6, r7;
    void *r5, *r8;
    float *p4;
    r7 = 0;
    r6 = 0;
    f9 = lbl_80562FD4 - arg2;
    f10 = -(lbl_80562FB0 - arg2);
    p4 = arg1;
    do {
        r5 = *(void **)((char *)arg0 + 4);
        r7++;
        r0 = *(int *)((char *)arg0 + 8);
        r8 = (char *)r5 + r6;
        r5 = (char *)r0 + r6;
        f0 = *p4;
        f3 = *(float *)r8;
        f1 = *(float *)((char *)r0 + r6);
        f2 = f0 * lbl_80562FD8;
        f8 = f3 * f9;
        f3 = *(float *)((char *)r8 + 4);
        f1 = f1 * f10;
        f0 = *(float *)((char *)r5 + 4);
        f7 = f3 * f9;
        f4 = f0 * f10;
        f6 = *(float *)((char *)r8 + 8);
        f5 = f8 + f1;
        f3 = *(float *)((char *)r5 + 8);
        f1 = p4[1];
        f0 = p4[2];
        f6 = f6 * f9;
        f3 = f3 * f10;
        sp8 = f8;
        f2 = f5 + f2;
        f4 = f7 + f4;
        f1 = f1 * lbl_80562FD8;
        *(float *)((char *)r0 + r6) = f2;
        f3 = f6 + f3;
        f0 = f0 * lbl_80562FD8;
        f1 = f4 + f1;
        spC = f7;
        r6 += 0xC;
        f0 = f3 + f0;
        sp10 = f6;
        p4 += 3;
        *(float *)((char *)r5 + 4) = f1;
        sp8 = f5;
        spC = f4;
        sp10 = f3;
        *(float *)((char *)r5 + 8) = f0;
    } while (r7 < *(int *)((char *)arg0 + 0x10));
    r4 = *(int *)((char *)arg0 + 4);
    *(int *)((char *)arg0 + 4) = *(int *)((char *)arg0 + 8);
    *(int *)((char *)arg0 + 8) = r4;
}

#pragma dont_inline off
void fn_801F6728(void *arg0) {
    int i;
    int offset;
    unsigned short index;
    char *records;
    char *record;
    char *output;
    i = 0;
    offset = 0;
    records = *(char **)((char *)arg0 + 0x1C);
    while (i < *(int *)((char *)arg0 + 0x20)) {
        record = records + offset;
        output = *(char **)((char *)arg0 + 4);
        index = *(unsigned short *)(records + offset);
        *(float *)(output + index * 0xC) = *(float *)(record + 4);
        *(float *)(output + index * 0xC + 4) = *(float *)(record + 8);
        *(float *)(output + index * 0xC + 8) = *(float *)(record + 0xC);
        offset += 0x10;
        i++;
    }
}

void fn_801F69C8(void *arg0) {
    int size;
    size = 0x900;
    memset(arg0, 0, size);
    *(int *)((char *)arg0 + 0x900) = 0;
}

void *fn_801F6D20(void *arg0) {
    int size = 0x2A0;
    memset(arg0, 0, size);
    *(int *)((char *)arg0 + 0x2A0) = 0;
    return arg0;
}

void *fn_801F7090(void *arg0) {
    memset(arg0,0,0x120);
    *(int *)((char *)arg0+0x120)=0;
    return arg0;
}

extern void fn_801F639C(void *);
extern void fn_801F6880(void *);
void fn_801F70D0(void *arg0, int arg1) {
    int i;
    void *entry;
    if (arg0 != 0) {
        entry = arg0;
        i = 0;
        do {
            fn_801F639C(entry);
            entry = (char *)entry + 0x48;
            i++;
        } while (i < *(int *)((char *)arg0 + 0x120));
        *(int *)((char *)arg0 + 0x120) = 0;
        if (arg1 > 0) fn_80128668();
    }
}

void fn_801F7160(void *arg0) {
    float sp[6], scale, offset;
    int i;
    void *entry;
    i=0; entry=arg0;
    while(i < *(int *)((char *)arg0+0x120)) {
        scale=*(float *)((char *)entry+0x40);
        offset=*(float *)((char *)entry+0x3C);
        fn_801E8C84(&sp[0]);
        sp[3]=sp[0]*scale;
        sp[5]=sp[2]*scale;
        sp[4]=sp[1]*scale-offset;
        fn_801F63F0(entry,&sp[3],*(float *)((char *)entry+0x44));
        fn_801F65D0(entry); fn_801F6728(entry);
        entry=(char *)entry+0x48; i++;
    }
}

void fn_801F7220(void *arg0) {
    void *entry;
    int i;

    i = 0;
    entry = arg0;
    while (i < *(int *)((char *)arg0 + 0x120)) {
        fn_801F6880(entry);
        entry = (char *)entry + 0x48;
        i++;
    }
}

extern void fn_801F6A98(void *);
void fn_801F73E0(void) {
    fn_801F6A98(lbl_8055EC10);
}

extern void fn_801F6B98(void *);
void fn_801F73E8(void) { fn_801F6B98(lbl_8055EC10); }

extern void fn_801F6DF0(void *);
void fn_801F73F0(void) { fn_801F6DF0(lbl_8055EC14); }

extern void fn_801F6EC0(void *);
void fn_801F73F8(void) { fn_801F6EC0(lbl_8055EC14); }

void fn_801F78D8(void) {

}

extern void fn_801F75A4(void *, void *, void *);
void fn_801F78DC(void *arg0, void *arg1) {
    fn_801F75A4(arg1, (char *)arg1 + 0x2C, arg0);
}

int fn_801F7930(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_801F7970(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern int fn_80128668(void);
int fn_801F79B0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

int fn_801F79F0(void) { return 3; }

int fn_801F79F8(void) { return 3; }

void fn_801F7A00(void) {

}
extern float lbl_80562FB0;
extern float lbl_80562FD4;
extern float lbl_80562FD8;
