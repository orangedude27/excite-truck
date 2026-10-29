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
extern const char lbl_8055C010[], lbl_8055BAB8[], lbl_8055B860[];
extern char lbl_80343ECC;
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
        int selected;
        int *current;
        int *options;
        int count;
        int *value;
    } object;
    int args[20];
} Fn8024C070Frame;

void fn_8024C070(void) {
    unsigned char frame[0xA0];
    unsigned char *flagp;
    int *settings;
    int *config;
    int *object;
    int *params;
    int value;
    int i;

    flagp = frame;
    settings = (int *)(frame + 8);
    config = (int *)(frame + 0x18);
    object = (int *)(frame + 0x2C);
    params = (int *)(frame + 0x50);

    *flagp = 0;
    fn_801333E8(5, lbl_8055C010, flagp);
    value = *flagp != 0;
    settings[0] = lbl_80563928;
    settings[1] = lbl_8056392C;
    settings[2] = lbl_80563920;
    settings[3] = lbl_80563924;

    object[0] = 0;
    object[1] = -1;
    object[2] = 0;
    object[3] = (int)&lbl_80343ECC;
    object[4] = 0;
    if (value == lbl_80563920) object[4] = 0;
    if (value == settings[3]) object[4] = 1;
    object[5] = (int)&settings[2];
    object[6] = (int)&settings[0];
    object[7] = 2;
    object[8] = (int)&value;

    params[0] = (int)lbl_8055C010;
    params[1] = 0x10;
    params[2] = 0;
    params[3] = (int)object;
    params[4] = 0;
    params[5] = (int)lbl_8055BAB8;
    params[6] = 8;
    params[7] = (int)&fn_80236914;
    params[8] = 2;
    params[9] = 0;
    params[10] = (int)lbl_8055B860;
    params[11] = 6;
    params[12] = 0;
    params[13] = -2;
    params[14] = 0x1B;

    for (i = 0; i < 5; i++) params[15 + i] = lbl_804989D0[i];

    config[0] = lbl_802FA520[0];
    config[1] = 0;
    config[2] = lbl_802FA520[2];
    config[3] = lbl_802FA520[3];
    config[4] = lbl_802FA520[4];
    ((int (*)(int *, int, int, int))fn_802146BC)(config, -999, -999, 1);
    *flagp = *(int *)(frame + 4) == 1;
    fn_80133460(5, lbl_8055C010, *flagp);
}

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

