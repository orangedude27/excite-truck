// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80128668(void *);
extern int fn_80179EE8(int);
extern char lbl_80338400;
extern float lbl_80562AB8;

void fn_801D32C8(void) {

}

void fn_801D32CC(void) {

}

extern void *lbl_8055E940;
void __AXDSPInitCallback_801D32D0(void) {
    lbl_8055E940 = 0;
}

void fn_801D32DC(void) {

}

int fn_801D36E8(void);
int fn_801D3FA4(int, int, int, int, int, int, int);
#pragma scheduling off
int fn_801D32E0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    int result;

    result = fn_801D36E8();
    fn_801D3FA4(result, arg0, arg1, arg2, arg3, arg4, arg5);
    return result;
}

extern int fn_801D411C(void *);
extern void *lbl_804421D8[];
int fn_801D36E8(void) {
    float bestValue;
    void **entry;
    void *best;
    int index;

    bestValue = lbl_80562AB8;
    entry = (void **)&lbl_804421D8;
    best = 0;
    index = 0;
    goto check;
loop:
    if ((*(int (**)(void *))(*(int *)*entry + 0x44))(*entry) == 0)
        return (int)((void **)&lbl_804421D8)[index];
    if (best != 0 && *(float *)((char *)*entry + 0x224) >= bestValue)
        goto next;
    best = *entry;
    bestValue = *(float *)((char *)best + 0x224);
next:
    entry++;
    index++;
check:
    if (index < *(int *)&lbl_8055E940)
        goto loop;
    fn_801D411C(best);
    return (int)best;
}

#pragma scheduling on
unsigned int fn_801D37AC(void *arg0) {
    int temp_r4;
    temp_r4 = *(int *)((char *)arg0 + 0x1EC);
    return (unsigned int)((-1 - temp_r4) | (temp_r4 + 1)) >> 31;
}

void *fn_801D3894(void *arg0, int arg1) {
 if (arg0 != 0) {
  *(int *)((char *)arg0 + 0x28) = 0;
  *(char **)arg0 = &lbl_80338400;
  *(int *)((char *)arg0 + 0x24) = 0;
  *(float *)((char *)arg0 + 0x2C) = lbl_80562AB8;
  if (arg0 != 0) fn_80179EE8(0);
  if (arg1 > 0) fn_80128668(arg0);
 }
 return arg0;
}

int fn_801D470C(void) { return 0; }

void fn_801D4714(void *a, void *b, void *c, int *arg3, int *arg4) { *arg4 = 0; *arg3 = 0; }

int fn_801D4724(void) { return 0; }


