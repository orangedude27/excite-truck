// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_80287B14(void);
int fn_802CAC54(int);
extern int lbl_8055C990;
extern int lbl_8055C994;
#pragma scheduling off
void fn_8029496C(void) {}

void fn_80294C68(void) {
    int i;
    fn_802CAC54(lbl_8055C990);
    fn_802CAC54(lbl_8055C994);
    lbl_8055C990 = -1;
    i = 0;
    lbl_8055C994 = -1;
    goto loop;
loop:
    i = i + 1;
    if (i < fn_80287B14()) goto loop;
}
#pragma scheduling on
void fn_80294CC0(void) {}

void fn_80294CC4(void) {}

void fn_80294ED4(void);
void fn_80294CC8(void) { fn_80294ED4(); }

void fn_80295C70(void *arg0, int arg1, float *arg2, unsigned int arg3, int arg4, float farg0, float farg1) {
    int index = *(int *)((char *)arg0 + 0x180);
    char *entry = (char *)arg0 + (index << 5);
    *(int *)entry = arg1;
    *(float *)(entry + 4) = arg2[0];
    *(float *)(entry + 8) = arg2[1];
    *(float *)(entry + 0xC) = arg2[2];
    *(float *)(entry + 0x10) = farg1;
    *(float *)(entry + 0x14) = farg0;
    entry[0x18] = (arg3 >> 16);
    entry[0x19] = (arg3 >> 8);
    entry[0x1A] = arg3;
    *(int *)(entry + 0x1C) = arg4;
    *(int *)((char *)arg0 + 0x180) = index + 1;
}

