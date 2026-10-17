#define NULL 0
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F9C8;
extern void fn_80128668(void *);
extern void fn_80128670(int);
extern void fn_802B4D40(void *);
extern int fn_802B40B0(int, int);
extern unsigned short lbl_8055F9CC;
extern int fn_802B3FC4(void *);
extern int lbl_8055CE00;
extern int lbl_804BE248[128];
void *fn_802B3F6C(void *arg0, int arg1) {
    if (arg0 != NULL) {
        if (arg0 != NULL) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_802B4004(void) {
    lbl_8055F9CC += 1;
}

void *fn_802B4014(void *arg0) {
    int i = 0;
    void *p;
    do {
        p = (*(void *(**)(void *, int))((char *)*(void **)arg0 + 0x60))(arg0, i);
        if (fn_802B3FC4(p) != 0 &&
            (*(int (**)(void *, int *))((char *)*(void **)p + 0x1C))(p, &lbl_8055CE00) == 1)
            return p;
        i++;
    } while (1);
}

int fn_802B40B0(int arg0, int arg1) {
    int p;
    if (arg0 >= 0 && (unsigned int)arg0 < 0x80) {
        p = lbl_804BE248[arg0];
        if (p != 0) {
            if ((int)lbl_8055F9C8 == -1 || arg1 == (int)lbl_8055F9C8)
                return p;
        }
    }
    return 0;
}

int fn_80129D90(int, int, int);
#pragma scheduling off
int fn_802B475C(void* arg0) {
    int index = fn_80129D90(0, 0, *(int*)((char*)arg0 + 4));
    return ((int*)*(void**)arg0)[index];
}
#pragma scheduling on
int fn_802B4BC0(int arg0, int arg1, int arg2) {
    return arg0 + (((arg1 & 0x1F) + ((arg2 << 5) & 0x3E0)) << 3);
}

void fn_802B4BD8(void) {}

void fn_802B4CB4(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            if (*(unsigned char *)((char *)p + 0x2000) != 0) {
                char *q = (char *)p;
                int i = 0;
                do {
                    fn_802B4D40(q);
                    i += 1;
                    q += 8;
                } while (i < 0x400);
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

void fn_802B4D40(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            if (p != NULL) {
                int x = ((int *)p)[3];
                if (x != 0) {
                    fn_80128670(x - 0x10);
                }
                if (p != NULL) {
                    ((int *)p)[0] = 0;
                    ((int *)p)[1] = 0;
                    ((int *)p)[2] = 0;
                }
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

void fn_802B4DC0(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((int *)p)[3]);
            if (p != NULL) {
                ((int *)p)[0] = 0;
                ((int *)p)[1] = 0;
                ((int *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

void fn_802B4E30(void) {
    lbl_8055F9C8 = (void*)-1;
}

void fn_802B4E3C(void* hi) {
    lbl_8055F9C8 = hi;
}

extern int fn_802B3DA4(int, unsigned short, int);
void fn_802B4E44(int arg0, int arg1) {
    int **table = (int **)&lbl_804BE248;
    int **tableEnd = table + 0x80;
    while (table < tableEnd) {
        int **slots = (int **)*table++;
        if (slots != 0) {
            int **slot = slots;
            int **slotEnd = slots + 0x400;
            while (slot < slotEnd) {
                int *entry = *slot++;
                if (entry != 0) {
                    int count = 0;
                    int offset = 0;
                    while (count < entry[1]) {
                        char *record = (char *)entry[0] + offset;
                        int index = 0;
                        char *out = record + 0xC;
                        while (index < 6) {
                            int value = fn_802B3DA4(arg0, *(unsigned short *)(record + 8), index);
                            *(int *)out = value;
                            index++;
                            out += 4;
                        }
                        offset += 0x24;
                        count++;
                    }
                }
            }
        }
    }
}

void *fn_802B4F10(void *out, int x, int y, int a, int b) {
    int r = fn_802B40B0(a, b);
    if (r != 0) {
        int idx = (((x & 0x1F) + ((y << 5) & 0x3E0)) << 3);
        int p = r + idx;
        *(int *)out = ((int *)p)[1];
        if (((int *)p)[1] > 0) {
            return (void *)r;
        }
    }
    return NULL;
}
typedef struct { int *ptr; int value; } Slot;
typedef struct { char *data; int count; } Entry;
