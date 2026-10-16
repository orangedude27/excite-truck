// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055EC18;
extern void *lbl_8055EC14;
extern void *lbl_8055EC10;
extern void *lbl_8055EC1C;
extern void *lbl_8055EC20;
extern char lbl_8033ACE8[32];
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
extern void fn_801F6B98(void *);
extern void fn_801F6DF0(void *);
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
