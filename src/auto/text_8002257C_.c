// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055D678;
extern unsigned char lbl_8035BB58[];
extern void *memset(void *, int, unsigned int);
extern void *fn_80022188(unsigned int, int);
extern void *fn_80021D48(unsigned int, int);
void *malloc(unsigned int arg0) {
    void *base;
    void *result;
    if (arg0 != 0) {
        if (lbl_8055D678 == 0) {
            memset(lbl_8035BB58, 0, 0x34);
            lbl_8055D678 = 1;
        }
        base = lbl_8035BB58;
        if (arg0 > (unsigned int)-0x31) {
            result = 0;
        } else if (arg0 <= 0x44) {
            result = ((void *(*)(void *, unsigned int, int))fn_80022188)(base, arg0, 0);
        } else {
            result = ((void *(*)(void *, unsigned int, int))fn_80021D48)(base, arg0, 0);
        }
        return result;
    }
    return 0;
}
