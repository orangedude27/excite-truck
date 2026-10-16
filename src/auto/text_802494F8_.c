typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80236074(void*, unsigned int);
void fn_80128668(void*);
extern void* lbl_8055BF34;
s32 fn_80214D04(void);
void fn_80249720(void) {
    lbl_8055BF34 = (void*)fn_80214D04();
}

long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8024A1AC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_80236074((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}
