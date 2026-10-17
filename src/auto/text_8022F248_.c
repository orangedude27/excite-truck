// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F014;
extern float lbl_805635FC;
extern float lbl_8056360C;
void fn_8022FB6C(void);
void fn_80214D48(void);
void fn_8022FD9C(int);
void fn_80015EB0(float);
void fn_80015E30(void *, float);
void fn_80015B20(void *, void *, void *);
void fn_80015AA0(void *, float);
int fn_80230020(void) {
    int count = 0;
    void *p = lbl_8055F014;
    while (p != 0) {
        p = *(void **)((char *)p + 8);
        count++;
    }
    return count;
}
