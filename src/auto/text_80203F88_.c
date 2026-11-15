// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern float lbl_80563140;
extern float lbl_80563144;

extern void fn_80128668(void*);
void* fn_80203F88(void* object, int shouldDelete) {
    /* Reset the object's three 32-bit fields to 0, then free it when
     * shouldDelete > 0 (deleting-destructor style helper). */
    if (object != 0) {
        if (object != 0) {
            *(int *)object = 0;
            *((int *)object + 1) = 0;
            *((int *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

float fn_80203FE0(void) { return lbl_80563140; }

void fn_80203FE8(void) {

}

void fn_80203FF8(void) {

}

void fn_80204000(void) {

}

void fn_80204008(void) {

}

int fn_8020400C(void) {
    return 0;
}

void fn_80204014(void) {

}

void fn_80204018(void) {

}

void fn_8020401C(void) {

}

void fn_80204020(void) {

}

int fn_80204024(void) {
    return 0;
}

int fn_8020402C(void) {
    return 0;
}

void fn_80204034(void) {

}

void fn_80204038(void) {

}

int fn_8020403C(void) {
    return 1;
}

void fn_80204044(void) {

}

void fn_80204048(void) {

}

void fn_8020404C(void) {

}

void fn_80204050(void) {

}

int fn_80204054(void *a, void *b, void *c, void *d, int e, int f, int g) { return 0; }

void fn_80204004(void) {

}

void fn_80203FFC(void) {

}

void fn_80203FEC(void) {

}

float fn_80203FF0(void) { return lbl_80563144; }

extern float lbl_80563140;
extern float lbl_80563144;
