// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8055C390;
extern void fn_80214CB4(void*);
extern void* fn_80214D04(void);
extern char lbl_803453B8[];
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);

void fn_8025C028(void) {
    lbl_8055C390 = fn_80214D04();
}

void fn_8025C04C(void) {
    fn_80214CB4(lbl_8055C390);
}

void* __dt__Q28PSSystem7SeqHeapFv_8025CC14(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_803453B8;
        fn_80235380(*(void**)((char*)arg0 + 0x28), lbl_803453B8);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

