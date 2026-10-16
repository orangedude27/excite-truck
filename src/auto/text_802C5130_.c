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
    char* fmt;
    char* text;
    if (strlen(arg0) > 15) {
        if (lbl_8055FC14 == 0) {
            fmt = lbl_8034B178;
            text = arg0;
            fn_802E30C8(fmt, text);
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

int fn_802C51AC(void* arg0) {
    if (arg0 != 0) return fn_80235FD8();
    return 1;
}

int fn_802C51C0(void* arg0) {
    f32 value;
    f32 result;
    if (arg0 != 0) {
        value = ((f32 (*)(void*, int))fn_80235EF0)(arg0, 0);
        if (value < lbl_80564EEC) result = value - lbl_80564EE8;
        else result = lbl_80564EE8 + value;
        return (int)result;
    }
    return 1;
}

extern f32 fn_80235F64(int);
int fn_802C5220(void* arg0) {
    f32 value;
    f32 result;
    if (arg0 != 0) {
        value = ((f32 (*)(void*, int))fn_80235F64)(arg0, 0);
        if (value < lbl_80564EEC) result = value - lbl_80564EE8;
        else result = lbl_80564EE8 + value;
        return (int)result;
    }
    return 1;
}

extern void fn_802353F4(void);
extern void fn_802354A0(void*, void*, int);
extern void fn_80235758(void*, float, float, float, float, float, float, int);
void fn_802C5310(void* arg0) { if (arg0 != 0) fn_802353F4(); }

void fn_802C5320(void* arg0, void* arg1) { if (arg0 != 0) fn_802354A0(arg0, arg1, -1); }

