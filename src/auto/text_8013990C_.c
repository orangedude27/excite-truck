// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_80128668();
int fn_80131818();
int fn_80128658(int);
int fn_80139B70(int, float, float);
extern int lbl_8055E138;
extern int lbl_8055E13C;
extern unsigned char lbl_8042F7C0;
void fn_80139E18(void *arg0) {
    int i, offset, value;
    if (arg0 == 0)
        return;
    i = 0;
    offset = 0;
    while (i < *(int *)((char *)arg0 + 8)) {
        fn_80128658(*(int *)(*(int *)((char *)arg0 + 4) + offset));
        offset += 4;
        i++;
    }
    *(int *)((char *)arg0 + 8) = 0;
    if (*(int *)arg0 != 0)
        fn_80131818();
    value = 0;
    *(int *)arg0 = value;
    if ((char *)arg0 + 4 != 0) {
        *(int *)((char *)arg0 + 4) = value;
        *(int *)((char *)arg0 + 8) = value;
        *(int *)((char *)arg0 + 12) = value;
    }
    fn_80128668(arg0);
}

int fn_80139EC4(void *arg0, float arg1, float arg2) {
    int i = 0;
    int offset = 0;
    while (i < *(int *)((char *)arg0 + 8)) {
        if (fn_80139B70(*(int *)(*(int *)((char *)arg0 + 4) + offset), arg1, arg2) != 0)
            return 1;
        offset += 4;
        i++;
    }
    return 0;
}

void fn_8013A074(void) {
    if (lbl_8055E138 != 0)
        fn_80131818();
    lbl_8055E13C = 0;
    lbl_8042F7C0 = 0;
}

int *fn_8013A198(int *arg0, int arg1) {
    if (arg0 != 0) {
        *arg0 = 0;
        if (arg1 > 0)
            fn_80128668();
    }
    return arg0;
}

