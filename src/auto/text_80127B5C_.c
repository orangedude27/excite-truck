// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8041E098[];
extern char lbl_80329FC0[];
extern void fn_802E317C(const char *, ...);
extern char lbl_80329FA0[];

void fn_80127C8C(void) {

}

void fn_80127C90(int arg0, int arg1) {
    int *base = lbl_8041E098;
    int count = base[1];
    int value = count ^ 10;
    int masked = value & 10;
    int shifted = value >> 1;
    unsigned int available = (unsigned int)(masked - shifted) >> 31;
    char *entry;

    if (available != 0) {
        base[1] = count + 1;
        entry = (char *)base + count * 16;
        *(int *)(entry + 8) = arg0;
        *(int *)(entry + 12) = 0;
        *(int *)(entry + 16) = arg1;
        entry[20] = 0;
    }
    if (available == 0)
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80329FA0);
}

void fn_80127CF4(void *arg0, void *arg1) {
    int count = lbl_8041E098[1];
    int value = count ^ 10;
    int masked = value & 10;
    int shifted = (value >> 1) - masked;
    if (((unsigned int)shifted >> 31) != 0) {
        unsigned char *slot = (unsigned char *)lbl_8041E098 + count * 16;
        lbl_8041E098[1] = count + 1;
        *(int *)(slot + 8) = 0;
        *(void **)(slot + 12) = arg0;
        *(void **)(slot + 16) = arg1;
        slot[20] = 0;
    } else {
        fn_802E317C(lbl_80329FC0);
    }
}

extern int fn_802E2C20();
extern void fn_80127B5C();
extern int lbl_8055DF70;
extern int lbl_8041E098[];
extern char lbl_80329FE8[];
extern char lbl_80329FC0[];
extern char lbl_80329FA0[];
extern void fn_802E30C8();
void fn_80127EF8(void) {
    int i;
    for (i = 0; i < lbl_8041E098[1]; i++)
        fn_802E30C8(lbl_80329FE8, lbl_8041E098[i * 4 + 4]);
}

void fn_80127F70(void* alarm) {
    fn_80127B5C(fn_802E2C20(alarm));
}

void fn_80127F94(void) {
    if (fn_802E2C20() - lbl_8055DF70 > 0x10)
        fn_80127B5C();
}

