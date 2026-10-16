// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

unsigned char* fn_801317F0(void* arg0) {
    unsigned char* p = *(unsigned char**)((char*)arg0 + 4);
    if ((int)*p == 0x24) return p + 6;
    return p;
}

extern int fn_80131588(int, int);
void fn_80131808(int arg0) { fn_80131588(arg0, 0); }

void fn_80131818(void) {
    fn_8012C4D8();
}

extern void fn_802E30C8(const char*, ...);
extern const char lbl_8032B510[];
extern char lbl_8032B64C[], lbl_8032B574[], lbl_8042F530[];
extern int lbl_80559B08, lbl_80559B0C;
extern signed char lbl_8055E060;
extern void* lbl_8042F53C[];
extern void fn_80131920(void*);
extern void __register_global_object(void*, void (*)(void*), void*);
int fn_8013181C(void) {
    fn_802E30C8(lbl_8032B510);
    return 0;
}

void* fn_8013184C(void) {
    if (lbl_8055E060 == 0) {
        ((void* volatile*)lbl_8042F53C)[0] = lbl_8032B64C;
        ((void* volatile*)lbl_8042F53C)[0] = lbl_8032B574;
        ((void* volatile*)lbl_8042F53C)[5] = 0;
        lbl_8042F53C[1] = &lbl_80559B0C;
        lbl_8042F53C[2] = &lbl_80559B08;
        lbl_8042F53C[3] = 0;
        lbl_8042F53C[4] = 0;
        lbl_8042F53C[5] = 0;
        lbl_8042F53C[6] = 0;
        __register_global_object(lbl_8042F53C, fn_80131920, lbl_8042F530);
        lbl_8055E060 = 1;
    }
    return lbl_8042F53C;
}

