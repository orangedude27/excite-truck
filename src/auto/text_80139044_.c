// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80139044(void) {

}

extern void* fn_80137C54(int);
extern float lbl_805613D8;
extern float lbl_805613DC;
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
float fn_80139048(void) {
    float value;
    float product;
    value = ((float*)fn_80137C54(-1))[1];
    product = lbl_805613DC * value;
    return lbl_805613D8 + product;
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
#pragma scheduling on
