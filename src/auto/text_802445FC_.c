// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80012870();
extern float fn_8020A5F0(void);
extern void fn_802146BC(int *, int, int, int, int, int, int, int);
extern int lbl_802FA320[];
extern char lbl_80342DC8[];
extern int lbl_80498860[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_802445FC(int arg0, int arg1, int arg2) {
    struct Context {
        volatile char *label;
        volatile int padding[4];
        volatile int zero;
        volatile int result;
        volatile int input;
        volatile int zero2;
        volatile int limit;
        volatile float value;
    } context;
    struct Config {
        volatile int zero;
        volatile int count;
        volatile char **context;
        volatile int zero2;
        volatile int zero3;
        volatile int setting[5];
    } config;
    struct Args {
        int first;
        volatile int config;
        int third;
        int fourth;
        int fifth;
    } args;
    int *v;

    context.result = fn_80012870();
    context.label = lbl_80342DC8;
    context.zero = 0;
    context.input = arg2;
    context.zero2 = 0;
    context.limit = 1000;
    context.value = fn_8020A5F0();
    v = lbl_802FA320;
    args.config = v[1];
    config.count = 5;
    config.zero = 0;
    config.context = &context.label;
    config.zero2 = 0;
    config.zero3 = 0;
    config.setting[0] = lbl_80498860[0];
    config.setting[1] = lbl_80498860[1];
    config.setting[2] = lbl_80498860[2];
    config.setting[3] = lbl_80498860[3];
    config.setting[4] = lbl_80498860[4];
    args.first = v[0];
    args.third = v[2];
    args.fourth = v[3];
    args.fifth = v[4];
    args.config = (int)&config;
    fn_802146BC((int *)&args, -999, -999, 1, v[4], v[3], v[2], v[0]);
}
#pragma pop
#pragma scheduling on
#pragma opt_propagation reset
#pragma opt_dead_assignments reset

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

void fn_8024477C(void *arg0) {
    extern int lbl_80342E28[];
    fn_8012E81C(&lbl_80342E28);
    fn_80021464(*(int *)((char *)arg0 + 0x18), *(int *)((char *)arg0 + 0x1C));
    *(int *)((char *)arg0 + 0x20) = fn_802E2C20();
}

extern int lbl_80342E28[];
__declspec(section ".sdata") extern float lbl_805637F0;
__declspec(section ".sdata") extern float lbl_805637F4;
__declspec(section ".sdata") extern double lbl_805637F8;

void fn_802447C4(void *arg0) {
    fn_8002167C();
    fn_8020A634();
    fn_8020A5F8(*(float *)((char *)arg0 + 0x28));
}

void fn_802448BC(void *arg0) {
    int a;
    int b;
    unsigned char result;
    fn_80021680();
    a = fn_802E2C20() - *(int *)((char *)arg0 + 0x20);
    b = (a << 8) - a;
    a = 0xFF - (b / (*(int *)((char *)arg0 + 0x24) - 0x32));
    result = a & ((-a & ~a) >> 31);
    if (result != 0) {
        fn_802C942C(result << 24);
    }
}

