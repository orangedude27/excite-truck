// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8029690C(void);
extern float lbl_80564560;
extern float lbl_80564564;
extern float lbl_80564568;
extern void *lbl_8055F788;
int stricmp(const char *, const char *);
extern void *lbl_8055F788;
int stricmp(const char *, const char *);
void *fn_80296950(const char *arg0) {
    void *node = lbl_8055F788;
    while (node != 0) {
        if (stricmp(arg0, (const char *)node) == 0)
            return node;
        node = *(void **)((char *)node + 0x20);
    }
    return 0;
}

int fn_802969B4(unsigned int arg0, unsigned int arg1, float farg0) {
    return (int)((float)arg0 + farg0 * ((float)arg1 - (float)arg0));
}

void fn_80296AAC(void *arg0) {
    float value0 = lbl_80564560;
    float value1 = lbl_80564564;
    float value2 = lbl_80564568;
    memset(arg0, 0, 0x30);
    *(float *)((char *)arg0 + 0x10) = value0;
    *(float *)((char *)arg0 + 8) = value0;
    *(float *)((char *)arg0 + 0) = value1;
    *(float *)((char *)arg0 + 0x1C) = value2;
    *(int *)((char *)arg0 + 0x18) = -1;
    *(int *)((char *)arg0 + 0x2C) = 10;
    *(int *)((char *)arg0 + 0x14) = -1;
}

void fn_80296D24(void) {}

void fn_80296D28(void) { fn_8029690C(); }

