// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F444;
extern void *lbl_8055C458;
extern void fn_80236914(void);
extern void fn_80264098(void *, int);
extern void *fn_80264A54(void);
void fn_80264098(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 4) = arg1;
}

void* fn_80264580(void) {
    return lbl_8055F444;
}

extern void *lbl_8055F448;
void* fn_80264A54(void) {
    return lbl_8055F448;
}

typedef float f32;
void fn_80265610(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x1C) = farg0; }

extern char lbl_8055C4A8[4];
extern void fn_80236954(void *queue);
void fn_802658FC(void) {
    fn_80236954(lbl_8055C4A8);
}

