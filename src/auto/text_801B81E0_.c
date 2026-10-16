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

void fn_801B880C(void) {
    register void* obj = lbl_8055E744;
    register void (**vtable)(void*) = *(void (***)(void*))obj;
    vtable[33](obj);
}

void fn_801B8820(void) {
    register void* obj = lbl_8055E744;
    register void (**vtable)(void*) = *(void (***)(void*))obj;
    vtable[16](obj);
}

void fn_801B8834(void) {
    register void* obj = lbl_8055E744;
    register void (**vtable)(void*) = *(void (***)(void*))obj;
    vtable[17](obj);
}

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

void fn_801B89B4(void) {
    (*(void (***)(void*))lbl_8055E744)[30](lbl_8055E744);
}

void fn_801B89C8(void* arg0) {
    (*(void (***)(void*, void*))lbl_8055E744)[31](lbl_8055E744, arg0);
}

int fn_801B89E0(void) {
    extern float lbl_8055E750;
    extern float lbl_8056274C;
    return lbl_8055E750 > lbl_8056274C;
}

extern float lbl_8055E750;
extern float lbl_8056274C;
extern void fn_801CB6B4(int, int, int);
void fn_801B8A10(void* arg0, int arg1, int arg2) {
    fn_801CB6B4(arg1, arg2, 2);
}

void fn_801B8A68(void *arg0, int arg1) {
    extern void fn_801B0C78(void *);
    fn_801B0C78((void *)arg1);
}

void fn_801B8A70(void *arg0, int arg1, int arg2) {
    extern void fn_801B0F70(int, int);
    fn_801B0F70(arg1, arg2);
}

void fn_801B8A7C(void *arg0, int arg1) {
    extern void fn_801B2C70(void *);
    fn_801B2C70((void *)arg1);
}

void fn_801B8A84(void) {
    extern void fn_8013C9F4(int);
    fn_8013C9F4(0);
}

int fn_801B8ACC(void) { return 1; }

void fn_801B8AD4(void) {

}

void fn_801B8AD8(void) {

}

int fn_801B8ADC(void) { return 1; }

int fn_801B8AE4(void) { return 0; }

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

extern int fn_800167F4(void);
int fn_801B8B08(void) {
    int result;
    if (fn_800167F4() > 1) {
        result = 0x160B;
    } else {
        result = 0x564B;
    }
    return result;
}

int fn_801B8B38(void) { return 1; }

int fn_801B8B40(void) { return 1; }

int fn_801B8B48(void) { return 1; }

int fn_801B8B50(void) { return 0; }

