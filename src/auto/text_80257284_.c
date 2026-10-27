// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80257A8C();
void *fn_80257470(void *);
void *fn_8022D850(void *, int, int, int);
void fn_8022D894(void *, int, int, void *, int);
void fn_80257A6C(int *, int, int);
void fn_8022D458(int, int, int *);
void fn_8022D7C4(int, int);
int fn_80128668(int);
extern int lbl_80563AB8;
int fn_8000DB34(void);
int fn_80012778(void);
int fn_80012780(void);
int fn_80012794(void);
int fn_802146BC(int *, int, int, int);
int fn_80247624(void);
extern int lbl_802FA5E0, lbl_80344CD4, lbl_80344CF0, lbl_80498E38;
extern int lbl_80563AA8, lbl_80563AB0;
extern int lbl_8055B860, lbl_8055BAB8, lbl_8055C1D8, lbl_8055C1E0, lbl_8055C1E8, lbl_8055C1F0;
extern void fn_80236914(void);
void fn_80257284(void) {
    int obj[4][5]; int desc[4][5]; int state[4][5]; int data[5]; int tail[20];
    int *args; int result;
    if (fn_80247624()) { fn_80012794(); fn_80012780(); }
    fn_80257470(&obj[0][0]);
    desc[0][0]=(int)&obj[0][0]; desc[0][1]=5; desc[0][2]=0; desc[0][3]=0; desc[0][4]=0;
    desc[1][0]=13; desc[1][1]=(int)&lbl_8055C1D8; desc[1][2]=(int)&obj[0][0]; desc[1][3]=0; desc[1][4]=0;
    desc[2][0]=13; desc[2][1]=(int)&lbl_8055C1E0; desc[2][2]=(int)&obj[1][0]; desc[2][3]=0; desc[2][4]=0;
    desc[3][0]=13; desc[3][1]=(int)&lbl_8055C1E8; desc[3][2]=(int)&obj[2][0]; desc[3][3]=0; desc[3][4]=0;
    state[0][0]=13; state[0][1]=(int)&lbl_8055C1F0; state[0][2]=(int)&obj[2][0]; state[0][3]=1; state[0][4]=0;
    fn_8000DA10(&obj[2][0], &obj[1][0], &obj[0][0], 13, &lbl_8055C1D8, &lbl_8055C1E0, &lbl_8055C1E8, &lbl_8055C1F0);
    result=fn_8000DB34();
    data[0]=3; data[1]=(int)&lbl_80344CD4; data[2]=0; data[3]=0; data[4]=0;
    args=(int*)(&tail[0]); args[0]=6; args[1]=(int)&lbl_8055B860; args[2]=0; args[3]=-1; args[4]=0x1b;
    args[5]=8; args[6]=(int)&lbl_8055BAB8; args[7]=(int)&fn_80236914; args[8]=2; args[9]=0;
    args[10]=lbl_80498E38; args[11]=*(int*)((char*)&lbl_80498E38+4); args[12]=*(int*)((char*)&lbl_80498E38+8); args[13]=*(int*)((char*)&lbl_80498E38+12); args[14]=*(int*)((char*)&lbl_80498E38+16);
    args[15]=lbl_802FA5E0; args[16]=*(int*)((char*)&lbl_802FA5E0+8); args[17]=*(int*)((char*)&lbl_802FA5E0+12); args[18]=*(int*)((char*)&lbl_802FA5E0+16);
    while (fn_802146BC(&args[15],-999,-999,1) != -1) {}
    if (fn_80247624()) { fn_80012794(); fn_80012778(); }
    fn_802574E0((int)&obj[0][0],-1);
}

#pragma scheduling invalid_target
void *fn_80257470(void *arg0) {
    *(int *)arg0 = (int)&lbl_80344CF0;
    *(int *)((char *)arg0 + 0x14) = 0;
    ((void (*)(int, int, int, int *))fn_8022D458)((int)((char *)arg0 + 0x1C), 0x28, 2, &lbl_80563AA8);
    ((void (*)(int, int, int, int *))fn_8022D458)((int)((char *)arg0 + 0x54), 0x40, 2, &lbl_80563AB0);
    fn_80257B7C((int)((char *)arg0 + 0x18C));
    return arg0;
}
#pragma scheduling on

int fn_802574E0(int arg0, int arg1) { int temp_r3; if (arg0 != 0) { temp_r3 = arg0 + 0x18C; if (temp_r3 != 0) fn_8022D7C4(temp_r3, 0); fn_8022D7C4(arg0 + 0x54, -1); fn_8022D7C4(arg0 + 0x1C, -1); if (arg1 > 0) fn_80128668(arg0); } return arg0; }

int fn_80257904(void *arg0, int arg1) {
    char *self = (char *)arg0;
    switch (arg1) {
    case 0x125:
        if (*(int *)(self + 0x18) == 1)
            *(int *)(self + 0x18) = 0;
        goto return_one;
    case 0x127:
        if (*(int *)(self + 0x18) == 0 && *(int *)(self + 0x5C) > 0)
            *(int *)(self + 0x18) = 1;
        goto return_one;
    case 0x126:
    case 0x128:
        switch (*(int *)(self + 0x18)) {
        case 0: {
            int use = (unsigned int)arg1 == 0x128u;
            int value;
            fn_8022D894(self + 0x1C, *(int *)(self + 0x4C), 0,
                        fn_8022D850(self + 0x1C, *(int *)(self + 0x4C), 0, 0), 0);
            value = *(int *)(self + 0x24);
            fn_80257A6C((int *)(self + 0x4C), use ? 1 : -1, value);
            *(char *)(self + 0x50) = 1;
            goto return_one;
        }
        case 1: {
            int use = (unsigned int)arg1 == 0x128u;
            int value;
            fn_8022D894(self + 0x54, *(int *)(self + 0x84), 0,
                        fn_8022D850(self + 0x54, *(int *)(self + 0x84), 0, 0), 0);
            value = *(int *)(self + 0x5C);
            fn_80257A6C((int *)(self + 0x84), use ? 1 : -1, value);
            *(char *)(self + 0x88) = 1;
            goto return_one;
        }
        }
        goto return_one;
    }
    return 0;
return_one:
    return 1;
}

void fn_80257A6C(int *arg0, int arg1, int arg2) { *arg0 = (*arg0 + (arg2 + arg1)) % arg2; }

int fn_8000DA10(void);
int fn_8001BA74(int);
void *fn_8001BA6C(void);
void fn_8001BC38(void *, int, int, int, int);
int fn_8001BCF0(void *);
void *fn_8001BD38(void *, void *, int);
void fn_8022D76C(void);
extern char lbl_80344CE4[];
#pragma dont_inline on
void fn_80257A8C(void *arg0) {
    char sp1C[0x24];
    char sp8[0x14];
    int var_r30;
    int temp_r29;

    fn_8022D76C();
    var_r30 = 0;
    do {
        temp_r29 = fn_8001BA74(var_r30 + 1);
        fn_8022D894(arg0, var_r30, 0, fn_8001BA6C(), 0);
        fn_8001BC38(sp1C, fn_8000DA10(), temp_r29, *(int *)((char *)arg0 + 0x30), 0);
        if (fn_8001BCF0(sp1C) != 0) {
            fn_8022D894(arg0, var_r30, 1, fn_8001BD38(sp1C, sp8, 0x14), 0);
        } else {
            fn_8022D894(arg0, var_r30, 1, &lbl_80344CE4, 0);
        }
        var_r30 += 1;
    } while (var_r30 < 7);
}
#pragma dont_inline reset

#pragma scheduling invalid_target
int fn_80257B7C(int arg0) { ((int (*)(int, int, int, int *))fn_8022D458)(arg0, 7, 2, &lbl_80563AB8); return arg0; }
#pragma scheduling on

void fn_80257BB8(void *arg0, int arg1) { *(int *)((char *)arg0 + 0x30) = arg1; fn_80257A8C(arg0); }
