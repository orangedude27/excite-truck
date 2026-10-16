// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_802446F8(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_80244738(void) {
    char scratch[56];
    __AXDSPInitCallback_800216B8();
    fn_80230B5C(scratch);
    fn_80230AD8(scratch);
    fn_802C942C(0xFF000000);
    fn_800216C8();
    fn_80230B38();
    fn_800216C4();
}

extern int lbl_80342E28;
extern float lbl_805637F0;
extern float lbl_805637F4;
extern double lbl_805637F8;

void fn_802447C4(void *arg0) {
    fn_8002167C();
    fn_8020A634();
    fn_8020A5F8(*(float *)((char *)arg0 + 0x28));
}
