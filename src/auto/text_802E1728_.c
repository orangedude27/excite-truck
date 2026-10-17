// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804DB780[];
extern char lbl_8034CD48[];
extern char lbl_8034CD30[];
extern void fn_802E317C(const char *);
extern void fn_802E30C8(const char *, int, int);
int fn_802E1954(int arg0) { return (arg0 + 0x7F) & 0xFFFFFF80; }

void fn_802E29AC(void) {
    int count = *(int *)lbl_804DB780;
    int *array = *(int **)((char *)lbl_804DB780 + 4);
    int i;
    int n = count >> 2;
    for (i = n - 1; i >= 0; --i) {
        if (array[-i] != 0x53ffeedd) {
            fn_802E30C8(lbl_8034CD30, (i * 4) >> 10, count >> 10);
            return;
        }
    }
}

void fn_802E2A1C(void) {
    int **p = (int **)((char *)lbl_804DB780 + 8);
    if (*p == 0)
        return;
    if (**p == 0x53ffeedd)
        return;
    fn_802E317C(lbl_8034CD48);
}

void fn_802E2A54(void) {}

void fn_802E2A58(void) {}
extern void fn_802E176C(void);
extern int fn_802E1780(void *, int, int);
extern int fn_802E1804(void *, void *, int, int, int);
extern int fn_802E18D4(int, int, int, int, void *, void *);
extern void DCFlushRange(void *, int);
typedef struct { char data[0x20]; } GXTexObj;
extern void GXInitTexObj(GXTexObj *, void *, unsigned short, unsigned short, int, int, int, int);
extern void GXInitTexObjLOD(GXTexObj *, int, int, int, int, int, float, float, float);
extern float lbl_805650F0;
