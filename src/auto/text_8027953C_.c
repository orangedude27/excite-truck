// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_805640EC;
extern float lbl_805640E8;
#pragma push
#pragma scheduling invalid_target
/* Initialize the default vehicle "Drvr" record: clear the 0x64-byte block, set the
 * leading enabled byte, then fill its 24 tuning floats with 0.0/1.0 defaults. */
void fn_8027953C(void *arg0) {
    float zero, one;
    memset(arg0, 0, 0x64);
    zero = lbl_805640EC;
    one = lbl_805640E8;
    *(unsigned char *)arg0 = 1;
    ((float *)arg0)[1] = one;
    ((float *)arg0)[2] = zero;
    ((float *)arg0)[3] = one;
    ((float *)arg0)[4] = zero;
    ((float *)arg0)[5] = zero;
    ((float *)arg0)[6] = zero;
    ((float *)arg0)[7] = zero;
    ((float *)arg0)[8] = zero;
    ((float *)arg0)[9] = zero;
    ((float *)arg0)[10] = zero;
    ((float *)arg0)[11] = zero;
    ((float *)arg0)[12] = zero;
    ((float *)arg0)[13] = zero;
    ((float *)arg0)[14] = zero;
    ((float *)arg0)[15] = one;
    ((float *)arg0)[16] = one;
    ((float *)arg0)[17] = one;
    ((float *)arg0)[18] = one;
    ((float *)arg0)[19] = zero;
    ((float *)arg0)[20] = zero;
    ((float *)arg0)[21] = zero;
    ((float *)arg0)[22] = zero;
    ((float *)arg0)[23] = zero;
    ((float *)arg0)[24] = zero;
}
#pragma scheduling on
#pragma pop
