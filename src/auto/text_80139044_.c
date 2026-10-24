// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80139044(void) {

}

extern void* fn_80137C54(int);
extern float lbl_805613D8;
extern float lbl_805613DC;
#pragma scheduling invalid_target
float fn_80139048(void) {
    return lbl_805613D8 + lbl_805613DC * ((float*)fn_80137C54(-1))[1];
}
#pragma scheduling on
