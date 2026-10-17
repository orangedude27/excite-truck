// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8041E098[];

void fn_80127C8C(void) {

}

extern int fn_802E2C20();
extern void fn_80127B5C();
extern int lbl_8055DF70;
extern int lbl_8041E098[];
extern char lbl_80329FE8[];
extern char lbl_80329FC0[];
extern char lbl_80329FA0[];
extern void fn_802E30C8();
extern void fn_802E317C();
void fn_80127EF8(void) {
    int i;
    for (i = 0; i < lbl_8041E098[1]; i++)
        fn_802E30C8(lbl_80329FE8, lbl_8041E098[i * 4 + 4]);
}

void fn_80127F70(void* alarm) {
    fn_80127B5C(fn_802E2C20(alarm));
}

