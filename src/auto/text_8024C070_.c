// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80128668(void);
extern int fn_801333E8(int, const char *, unsigned char *);
extern int fn_80133460(int, const char *, unsigned char);
extern int fn_802146BC(int *, int, int, int, int, int, int, int);
extern int fn_80236914;
extern int lbl_802FA520[];
extern int lbl_804989D0[];
extern int lbl_80563920, lbl_80563924, lbl_80563928, lbl_8056392C;
extern const char lbl_8055C010, lbl_8055BAB8, lbl_8055B860;
extern char lbl_80343ECC[];
typedef struct {
    unsigned char flag;
    unsigned char pad0[3];
    int value;
    int settings[4];
    int config[5];
    struct {
        unsigned char enabled;
        unsigned char pad0[3];
        int sentinel;
        unsigned char secondary;
        unsigned char pad1[3];
        const char *name;
        volatile int selected;
        int *current;
        int *options;
        int count;
        int *value;
    } object;
    int args[20];
} Fn8024C070Frame;

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8024C070(void) {
    Fn8024C070Frame frame;

    /* Fix note: model the stack data as one frame and pass its argument table through config. */
    frame.flag = 0;
    fn_801333E8(5, &lbl_8055C010, &frame.flag);
    frame.value = frame.flag != 0;
    frame.settings[0] = lbl_80563928;
    frame.settings[1] = lbl_8056392C;
    frame.settings[2] = lbl_80563920;
    frame.settings[3] = lbl_80563924;

    frame.object.enabled = 0;
    frame.object.sentinel = -1;
    frame.object.secondary = 0;
    frame.object.name = lbl_80343ECC;
    frame.object.selected = 0;
    if (frame.value == lbl_80563920)
        frame.object.selected = 0;
    if (frame.value == frame.settings[3])
        frame.object.selected = 1;
    frame.object.current = &frame.settings[2];
    frame.object.options = &frame.settings[0];
    frame.object.count = 2;
    frame.object.value = &frame.value;

    frame.args[0] = (int)&lbl_8055C010;
    frame.args[1] = 0x10;
    frame.args[2] = 0;
    frame.args[3] = (int)&frame.object;
    frame.args[4] = 0;
    frame.args[5] = (int)&lbl_8055BAB8;
    frame.args[6] = 8;
    frame.args[7] = (int)&fn_80236914;
    frame.args[8] = 2;
    frame.args[9] = 0;
    frame.args[10] = (int)&lbl_8055B860;
    frame.args[11] = 6;
    frame.args[12] = 0;
    frame.args[13] = -2;
    frame.args[14] = 0x1B;
    frame.args[15] = lbl_804989D0[0];
    frame.args[16] = lbl_804989D0[1];
    frame.args[17] = lbl_804989D0[2];
    frame.args[18] = lbl_804989D0[3];
    frame.args[19] = lbl_804989D0[4];

    frame.config[0] = lbl_802FA520[0];
    frame.config[1] = (int)frame.args;
    frame.config[2] = lbl_802FA520[2];
    frame.config[3] = lbl_802FA520[3];
    frame.config[4] = lbl_802FA520[4];
    ((int (*)(int *, int, int, int))fn_802146BC)(frame.config, -999, -999, 1);
    frame.flag = frame.value == 1;
    fn_80133460(5, &lbl_8055C010, frame.flag);
}
#pragma scheduling on
#pragma use_lmw_stmw on
int fn_8024C24C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8024C28C(void *arg0) {
    int temp_r0;
    int temp_r7;
    int *temp_r5;
    int *temp_r4;
    temp_r7 = *(int *)((char *)arg0 + 0x1C);
    temp_r0 = *(int *)((char *)arg0 + 0x10);
    temp_r5 = *(int **)((char *)arg0 + 0x14);
    temp_r0 = (temp_r7 + temp_r0 - 1) % temp_r7;
    temp_r4 = *(int **)((char *)arg0 + 0x20);
    *(int *)((char *)arg0 + 0x10) = temp_r0;
    *temp_r4 = temp_r5[temp_r0];
}

void fn_8024C2C4(void *arg0) {
    int temp_r4;
    int temp_r6;
    int temp_r7;
    int *temp_r5;
    int *temp_r4p;
    temp_r4 = *(int *)((char *)arg0 + 0x10);
    temp_r6 = *(int *)((char *)arg0 + 0x1C);
    temp_r7 = temp_r4 + 1;
    temp_r5 = *(int **)((char *)arg0 + 0x14);
    temp_r4p = *(int **)((char *)arg0 + 0x20);
    temp_r7 = temp_r7 % temp_r6;
    *(int *)((char *)arg0 + 0x10) = temp_r7;
    *temp_r4p = temp_r5[temp_r7];
}

int fn_8024C2F8(void *arg0) {
    return (*(int **)((char *)arg0 + 0x18))[*(int *)((char *)arg0 + 0x10)];
}

int fn_8024C30C(void *arg0) {
    return (*(int **)((char *)arg0 + 0x14))[*(int *)((char *)arg0 + 0x10)];
}

