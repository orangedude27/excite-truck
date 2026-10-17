// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804DB780[];
extern char lbl_8034CD48[];
extern char lbl_8034CD30[];
extern void fn_802E317C(const char *);
extern void fn_802E30C8(const char *, int, int);
extern char lbl_8034CEE4[];
extern int lbl_804DB790[];
extern int lbl_804DB7D0[];
extern int lbl_8055FF00;
typedef unsigned long long u64;
extern u64 fn_802E2C9C(void);
extern u64 OSGetTime(void);
struct OSTimeCalendar {
    int sec;
    int min;
    int hour;
    int mday;
    int month;
    int year;
    int wday;
    int yday;
    int msec;
};
extern void OSTicksToCalendarTime(u64, struct OSTimeCalendar *);
void fn_802E1728(void *arg0) {
    int value = *(int *)((char *)arg0 + 0x178);
    if (value != 0) {
        fn_80120084(value);
        *(int *)((char *)arg0 + 0x178) = 0;
    }
}

unsigned int fn_802E176C(unsigned int arg0) {
    return 1U << (32 - __cntlzw(arg0));
}

void fn_802E1780(void *arg0, unsigned int arg1, int arg2) {
    int x;
    int y;
    int row;

    x = 0;
    y = 0;
    for (row = 0; row < 4; row++) {
        int i;
        for (i = 0; i < (arg1 >> 3); i++) {
            unsigned char *p = (unsigned char *)arg0 + (i + row * arg2) * 2;
            p[0] = (unsigned char)(x - i + 0x80);
            y++;
            p[1] = (unsigned char)(y - row - 1 + 0x80);
            if (y == 4) {
                y = 0;
                x++;
            }
        }
    }
}

int fn_802E1954(int arg0) { return (arg0 + 0x7F) & 0xFFFFFF80; }

void fn_802E1A38(void *arg0, int arg1) {
    int result;
    result = fn_802E1980(arg1, (char *)arg0 + 0x190, (char *)arg0 + 0x180, (char *)arg0 + 0x184, *(int *)((char *)arg0 + 0x104));
    fn_802E1980(arg1 + result, (char *)arg0 + 0x1b0, (char *)arg0 + 0x188, (char *)arg0 + 0x18c, *(int *)((char *)arg0 + 0x10c));
}

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
extern unsigned int fn_802E176C(unsigned int);
extern void fn_802E1780(void *, unsigned int, int);
extern int fn_802E1804(void *, void *, int, int, int);
extern int fn_802E18D4(int, int, int, int, void *, void *);
extern void DCFlushRange(void *, int);
typedef struct { char data[0x20]; } GXTexObj;
extern void GXInitTexObj(GXTexObj *, void *, unsigned short, unsigned short, int, int, int, int);
extern void GXInitTexObjLOD(GXTexObj *, int, int, int, int, int, float, float, float);
extern float lbl_805650F0;

