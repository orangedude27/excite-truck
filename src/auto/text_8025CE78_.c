// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_80345718[];
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);
void* __dt__Q28PSSystem7SeqHeapFv_8025DA88(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80345718;
        fn_80235380(*(void**)((char*)arg0 + 0x28), lbl_80345718);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
