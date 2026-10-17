// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
extern int lbl_8032A5FC;
extern int lbl_8032A620;
extern int lbl_8055E174;
extern float lbl_80561474;
int fn_802E317C(int *, int);
int fn_80128658(int);
int fn_80128668(void *);
void fn_8013B950(void);
void fn_8012A364(void *arg0, int *arg1) {
    *arg1 = *(int *)((char *)arg0 + 0x10);
    *(int *)((char *)arg0 + 0x10) = (int)arg1;
    *(int *)((char *)arg0 + 0x1c) -= 1;
}
