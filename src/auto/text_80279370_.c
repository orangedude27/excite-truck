// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_804A16E8[];
extern float lbl_805640D8;
extern float lbl_805640DC;
extern float lbl_805640E0;
extern float lbl_805640E4;

void fn_802793B0(int arg0);
void fn_80279370(void) {
    int var_r31;

    var_r31 = 0;
    do {
        fn_802793B0(var_r31);
        var_r31 += 1;
    } while (var_r31 < 4);
}

void fn_802793AC(void) {}

extern unsigned char lbl_804A16E8[];
extern float lbl_805640D8;
extern float lbl_805640DC;
extern float lbl_805640E0;
extern float lbl_805640E4;
void fn_802793B0(int arg0) {
    unsigned char *p = lbl_804A16E8 + arg0 * 0xA0;
    *(unsigned char *)(p + 0x00) = 0;
    *(float *)(p + 0x28) = lbl_805640D8;
    *(float *)(p + 0x24) = lbl_805640D8;
    *(float *)(p + 0x20) = lbl_805640D8;
    *(float *)(p + 0x34) = lbl_805640DC;
    *(float *)(p + 0x30) = lbl_805640DC;
    *(float *)(p + 0x2C) = lbl_805640DC;
    *(float *)(p + 0x38) = lbl_805640E0;
    *(float *)(p + 0x3C) = lbl_805640E4;
    *(float *)(p + 0x48) = lbl_805640D8;
    *(float *)(p + 0x44) = lbl_805640D8;
    *(float *)(p + 0x40) = lbl_805640D8;
    *(float *)(p + 0x54) = lbl_805640DC;
    *(float *)(p + 0x50) = lbl_805640DC;
    *(float *)(p + 0x4C) = lbl_805640DC;
    *(float *)(p + 0x58) = lbl_805640E0;
    *(float *)(p + 0x5C) = lbl_805640E4;
    *(float *)(p + 0x68) = lbl_805640D8;
    *(float *)(p + 0x64) = lbl_805640D8;
    *(float *)(p + 0x60) = lbl_805640D8;
    *(float *)(p + 0x74) = lbl_805640DC;
    *(float *)(p + 0x70) = lbl_805640DC;
    *(float *)(p + 0x6C) = lbl_805640DC;
    *(float *)(p + 0x78) = lbl_805640E0;
    *(float *)(p + 0x7C) = lbl_805640E4;
    *(float *)(p + 0x88) = lbl_805640D8;
    *(float *)(p + 0x84) = lbl_805640D8;
    *(float *)(p + 0x80) = lbl_805640D8;
    *(float *)(p + 0x94) = lbl_805640DC;
    *(float *)(p + 0x90) = lbl_805640DC;
    *(float *)(p + 0x8C) = lbl_805640DC;
    *(float *)(p + 0x98) = lbl_805640E0;
    *(float *)(p + 0x9C) = lbl_805640E4;
}

