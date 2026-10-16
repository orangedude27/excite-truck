// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80235380(void);
extern int fn_80235FD8(void);
typedef float f32;
extern f32 fn_80235EF0(int);
extern f32 lbl_80564EE8;
extern f32 lbl_80564EEC;
extern int fn_8023512C(char*);
extern int fn_802E30C8(const char*, ...);
extern unsigned int strlen(const char*);
extern char lbl_8034B178[];
extern unsigned char lbl_8055FC14;
int fn_802C5130(char* arg0) {
    if (strlen(arg0) > 15) {
        if (lbl_8055FC14 == 0) {
            fn_802E30C8(lbl_8034B178, arg0);
        }
        lbl_8055FC14 = 1;
        return 0;
    }
    return fn_8023512C(arg0);
}

void fn_802C519C(void* arg0) {
    if (arg0 == 0) return;
    fn_80235380();
}

