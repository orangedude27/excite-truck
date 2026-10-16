// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055E744;
void* fn_801B83A0(void) {
    return lbl_8055E744;
}

void fn_801B8418(void) {

}

void fn_801B8488(void) {

}

void fn_801B84BC(void) {

}

void fn_801B84D8(void* arg0) {
    (*(void (***)(void*, void*))lbl_8055E744)[21](lbl_8055E744, arg0);
}

int fn_801B84F0(void) {
    return 0;
}

void fn_801B84F8(void) {
    extern char lbl_8055E748;
    lbl_8055E748 = 1;
    (*(void (***)(void*))lbl_8055E744)[6](lbl_8055E744);
}

extern char lbl_8055E748;
char fn_801B8514(void) {
    return lbl_8055E748;
}

int fn_801B851C(void* arg0) {
    extern int fn_80161BB8(void);
    if (fn_80161BB8() != 0) {
        return 0;
    }
    return (*(int (***)(void*, void*))lbl_8055E744)[10](lbl_8055E744, arg0);
}

int fn_801B8804(void) { return 0; }

float fn_801B8950(int arg0) {
    extern float lbl_80436D08[];
    return lbl_80436D08[arg0];
}

extern float lbl_80436D08[];
void fn_801B8964(int arg0, float arg1) {
    lbl_80436D08[arg0] = arg1;
}

void fn_801B8978(void) {
    register void* obj = lbl_8055E744;
    register void (**vtable)(void*) = *(void (***)(void*))obj;
    vtable[27](obj);
}

void fn_801B898C(void) {
    register void* obj = lbl_8055E744;
    register void (**vtable)(void*) = *(void (***)(void*))obj;
    vtable[28](obj);
}

void fn_801B8AD4(void) {

}

void fn_801B8AD8(void) {

}

void fn_801B8AEC(void) {

}

void fn_801B8AF0(void) {

}

void fn_801B8AF4(void) {

}

void fn_801B8AF8(void) {

}

void fn_801B8AFC(void) {

}

