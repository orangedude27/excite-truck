// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EA20;
extern int lbl_804874D4;
extern int lbl_804874B8;
extern char lbl_8055EA22;
extern char lbl_8055EA22;
extern float lbl_80562CAC;
extern float lbl_80562CC8;
extern const char lbl_80339878[];
extern const char lbl_80339884[];
int *fn_801E1F44(void);
void *fn_80207848(const char *, int);
void fn_801E1874(void) {
    *(int *)&lbl_804874D4 = 0;
    *((char *)&lbl_804874D4 + 0x18) = 0;
    *((char *)&lbl_804874D4 + 4) = 0;
    lbl_8055EA22 = 0;
}

void fn_801E1D20(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D2C(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D38(void) {
    if (*fn_801E1F44() == 1) {
        lbl_804874B8 /* offset fields below */ = lbl_804874B8;
    }
}

extern char lbl_8055EA21;
void fn_801E1F78(void) {
    lbl_8055EA21 = 1;
}
typedef struct { int pad0; float x; float y; float z; char pad10[4]; void *p14; void *p18; } Obj;
