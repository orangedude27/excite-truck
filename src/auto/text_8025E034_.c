// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_80345A30[];
extern char lbl_80345A1C[];
extern void* fn_8023512C(const char*);
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);
void* __dt__Q28PSSystem7SeqHeapFv_8025E614(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80345A30;
        fn_80235380(*(void**)((char*)arg0 + 0x2C), lbl_80345A30);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_8025F9B8(void* arg0, int arg1) {
    *(int*)((char*)arg0 + 0x18) = arg1;
}

void* fn_8025F9C0(void* arg0) {
    *(int*)((char*)arg0 + 0x14) = 0;
    *(void**)arg0 = lbl_80345A30;
    *(int*)((char*)arg0 + 0x18) = 0;
    *((char*)arg0 + 0x25) = 0;
    *(void**)((char*)arg0 + 0x2C) = fn_8023512C(lbl_80345A1C);
    return arg0;
}

