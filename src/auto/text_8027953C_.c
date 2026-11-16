// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_805640EC;
extern float lbl_805640E8;
#pragma push
#pragma scheduling invalid_target
/* Initialize the default vehicle "Drvr" record: clear the 0x64-byte block, set the
 * leading enabled byte, then fill its 24 tuning floats with 0.0/1.0 defaults. */
void fn_8027953C(void *out) {
    float one, zero;
    memset(out, 0, 0x64);
    one = lbl_805640EC;
    zero = lbl_805640E8;
    *(unsigned char *)out = 1;
    ((float *)out)[1] = zero;
    ((float *)out)[2] = one;
    ((float *)out)[3] = zero;
    ((float *)out)[4] = one;
    ((float *)out)[5] = one;
    ((float *)out)[6] = one;
    ((float *)out)[7] = one;
    ((float *)out)[8] = one;
    ((float *)out)[9] = one;
    ((float *)out)[10] = one;
    ((float *)out)[11] = one;
    ((float *)out)[12] = one;
    ((float *)out)[13] = one;
    ((float *)out)[14] = one;
    ((float *)out)[15] = zero;
    ((float *)out)[16] = zero;
    ((float *)out)[17] = zero;
    ((float *)out)[18] = zero;
    ((float *)out)[19] = one;
    ((float *)out)[20] = one;
    ((float *)out)[21] = one;
    ((float *)out)[22] = one;
    ((float *)out)[23] = one;
    ((float *)out)[24] = one;
}
#pragma scheduling on
#pragma pop
