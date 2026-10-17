// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012C33C(void);
int fn_802CAC28(int, int);
int fn_802BC334(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

void *fn_802BE844(short, short, short);
void fn_802BC39C(void);
void fn_802BC3DC(void) {
    fn_802BC39C();
}

void fn_802BC3E0(short arg0, short arg1, short arg2, char *arg3) {
    char *obj = fn_802BE844(arg0, arg1, arg2);
    *(char **)arg3 = *(char **)(obj + 4);
    *(char **)(obj + 4) = arg3;
}

short fn_802BC424(int arg0) {
    short value = arg0 + 0x200;
    int mask = 0x1FF;
    while (1) {
        mask >>= 1;
        if ((value & mask) == 0)
            break;
    }
    return mask + 1;
}

void fn_802BC44C(void *arg0) {
    int offset = 0;
    int i = 0;
    char *entry;
    goto check;
loop:
    entry = *(char **)arg0 + offset;
    fn_802BC3E0(*(short *)(entry + 4), *(short *)(entry + 6), fn_802BC424(*(short *)(entry + 4)), entry);
    offset += 0x10;
    i++;
check:
    if (i < *(int *)((char *)arg0 + 4)) goto loop;
}

void *fn_802BC4D4(void *arg0) {
    return *(void **)(*(char **)((char *)arg0 + 4) + 0xC);
}

double fn_8002F234(float, float);
float fn_802BC540(void *arg0, float farg0) {
    float x = *(float *)arg0;
    float z = *(float *)((char *)arg0 + 8);
    return farg0 * (float)fn_8002F234(x * x + z * z, z);
}

int fn_802BD0C8(void *arg0) {
    int result = 0;
    if (*(int *)((char *)arg0 + 4) != 0) {
        void **ptr = *(void ***)((char *)arg0 + 0x58);
        if (ptr != 0)
            result = *(int *)((char *)*ptr + 4);
    }
    return result;
}

int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
void fn_802BD0F4(void *arg0) {
    int i, offset, count;
    char *entries, *entry;
    void *array;
    float pos[2];
    if (*(int *)((char *)arg0 + 4) != 0 && (array = *(void **)((char *)arg0 + 0x58)) != 0) {
        entries = *(char **)array;
        count = *(int *)(entries + 4);
        i = 0; offset = 0;
        while (i < count) {
            array = *(void **)((char *)arg0 + 0x58);
            entries = *(char **)array;
            entry = entries + offset;
            pos[0] = *(float *)(entry + 0x30);
            pos[1] = *(float *)(entry + 0x38);
            *(int *)(entry + 4) = fn_802BA580(*(int *)((char *)arg0 + 4), pos, *(float *)(entry + 0x1c));
            offset += 0x44; i++;
        }
    }
}

void *fn_802BD194(void *arg0, const char *arg1) {
    unsigned int count = *(unsigned int *)arg0;
    unsigned int i = 0;
    unsigned int offset = 0;
    char *base;
    while (i < count) {
        base = *(char **)((char *)arg0 + 4);
        if (strcmp(base + offset, arg1) == 0)
            return base + i * 0x38;
        offset += 0x38;
        i++;
    }
    return 0;
}

void *fn_801284F8(int, int);
int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
void fn_802BD414(int arg0, volatile int *arg1) {
    volatile int *result = (volatile int *)fn_801284F8(0xC, arg0);
    if (result != 0) {
        int second = arg1[1];
        int first = arg1[0];
        result[0] = second;
        result[2] = first;
        result[1] = 0;
        result[1] = result[1] + arg1[0];
    }
}

int fn_802BD5A8(int arg0, int arg1) { return arg0 + arg1; }

int fn_802BD694(int arg0, int arg1) { return arg0 + arg1; }

int fn_802BD80C(int arg0, int arg1) { return arg0 + arg1; }

void fn_802BDC3C(void* alarm) {
    fn_802C1550(fn_802BD210(alarm));
}

extern int lbl_8034AB38, lbl_8034AC48;
extern int lbl_8055FAA8, lbl_8055FAAC, lbl_8055FAB0;
extern void *lbl_8055FABC;
void deleteThreads__6SystemFv_802BDCA4(void **arg0) {
    void *obj = *arg0;
    if (obj != 0) {
        if (obj != 0) {
            void (**vtable)(void *, int) = *(void (***)(void *, int))((char *)obj + 4);
            vtable[4](obj, 1);
        }
        *arg0 = 0;
    }
}

void fn_802C2930(void*, unsigned int);
void fn_80128668(void*);
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802BDCFC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_802C2930((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_802BDD54(void) {
    fn_802BD814();
}

void *fn_801284F8(int, int);
