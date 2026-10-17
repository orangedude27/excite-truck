// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).


extern float lbl_80564560;
extern float lbl_80564564;
extern float lbl_80564568;
extern void *lbl_8055F788;
int stricmp(const char *, const char *);
extern void *lbl_8055F788;
int stricmp(const char *, const char *);
void fn_80296838(void *arg0) {
    int i;
    int offset;
    void *entry;
    if (arg0 == 0) return;
    if (*(void **)((char *)arg0 + 0x24) != 0) {
        i = 0;
        offset = 0;
        while (i < *(int *)((char *)arg0 + 0x2C)) {
            entry = (char *)*(void **)((char *)arg0 + 0x24) + offset;
            if (*(int *)((char *)entry + 0x18) != -1 &&
                *(int *)((char *)entry + 0x18) != -2) {
                fn_802CAC54();
                *(int *)((char *)entry + 0x18) = -2;
            }
            offset += 0x30;
            i++;
        }
        fn_80128670((char *)*(void **)((char *)arg0 + 0x24) - 0x10);
        *(void **)((char *)arg0 + 0x24) = 0;
    }
    fn_80128668(arg0);
}

void fn_802968E8(void *arg0) {
    int count = *(int *)((char *)arg0 + 0x28);
    *(int *)((char *)arg0 + 0x28) = count + 1;
    if (count == 0) {
        *(void **)((char *)arg0 + 0x20) = lbl_8055F788;
        lbl_8055F788 = arg0;
    }
}

void *fn_80296950(const char *arg0) {
    void *node = lbl_8055F788;
    while (node != 0) {
        if (stricmp(arg0, (const char *)node) == 0) return node;
        node = *(void **)((char *)node + 0x20);
    }
    return 0;
}

int fn_802969B4(unsigned int arg0, unsigned int arg1, float farg0) {
    return (int)((float)arg0 + farg0 * ((float)arg1 - (float)arg0));
}

#pragma scheduling off
void fn_80296AAC(void *arg0) {
    memset(arg0, 0, 0x30);
    *(float *)((char *)arg0 + 0x10) = lbl_80564560;
    *(float *)((char *)arg0 + 8) = lbl_80564560;
    *(float *)((char *)arg0 + 0) = lbl_80564564;
    *(float *)((char *)arg0 + 0x1C) = lbl_80564568;
    *(int *)((char *)arg0 + 0x18) = -1;
    *(int *)((char *)arg0 + 0x2C) = 10;
    *(int *)((char *)arg0 + 0x14) = -1;
}
#pragma scheduling on
void fn_80296D24(void) {}

void fn_80296D28(void) { fn_8029690C(); }

