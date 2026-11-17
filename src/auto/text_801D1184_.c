// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma small_data off
extern char lbl_80338208[];
extern char lbl_80338214[];
#pragma small_data on
extern void *lbl_804348E8[];
extern float lbl_80562A48;
extern void fn_801819A0(void *, void *, void *, float, float, float);

#pragma scheduling invalid_target
void fn_801D1184(void) {
    /* Allocate a 4-byte "carelmgr" object and install its vtable on success. */
    extern void *fn_801284F8(int, const char *);
    extern void fn_801D0FA4(void);
    void *object;
    object = fn_801284F8(4, (const char *)&lbl_80338208[0]);
    if (object != 0) {
        fn_801D0FA4();
        *(void **)object = &lbl_80338214[0];
    }
}
void fn_801D11D4(void) {
    fn_801D11D8();
}

#pragma scheduling on
int fn_801D11D8(void *arg0, int arg1) {
    char *p = (char *)lbl_804348E8[arg1];
    char *q = p + 0x32c;
    fn_801819A0((char *)arg0 + 4, q, p, lbl_80562A48 * *(float *)(p + 0x2dc), *(float *)(p + 0x2e4), *(float *)(p + 0x2e8));
    *(float *)((char *)arg0 + 0x30) = *(float *)(q + 0x64);
}
extern void *fn_801284F8(int, const char *);
extern void fn_801D0FA4(void);
extern void *lbl_804348E8[];
extern void fn_801819A0(void *, void *, void *, float, float, float);
extern float lbl_80562A4C;
/* Sets the first float field of an entry to lbl_80562A4C (0.0f). */
void fn_801D1244(float *entry) {
    *entry = lbl_80562A4C;
}

#pragma scheduling invalid_target
void fn_801D1250(float *arg0, int arg1) {
    char *p = (char *)lbl_804348E8[arg1];
    float f4 = *(float *)(p + 0x25d0);
    float f5 = *(float *)(p + 0x25f4);
    float f6;
    if (f4 > arg0[11]) {
        f6 = lbl_80562A4C > (f4 - arg0[8]) ? lbl_80562A4C : (f4 - arg0[8]);
        {
            float first = arg0[2] * f4;
            float square = f4 * f4;
            float second = arg0[1] * square;
            float base = arg0[3];
            float val = (base + (first + second)) - arg0[9] * f6;
            f6 = arg0[10] > val ? arg0[10] : val;
        }
    } else {
        float square = f4 * f4;
        f6 = arg0[6] + (arg0[5] * f4 + arg0[4] * square);
    }
    arg0[0] = f5 * f6 - f4 * arg0[7];
}
#pragma scheduling on
void fn_801D1008(void*, unsigned int);
void fn_80128668(void*);
/* Destructor for nw4hbm::snd::MemorySoundArchive: runs base destruction with
 * shouldDelete=0, then if requested frees this object. Returns this. */
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801D130C(long self, long shouldDelete) {
    if (self != 0) {
        fn_801D1008((void *)self, 0);
        if (shouldDelete > 0) {
            fn_80128668((void *)self);
        }
    }
    return self;
}

extern int lbl_8055E908;
extern int fn_80128670(int);
/* Frees the lbl_8055E908 array buffer (allocated with 0x10-byte header) and clears the pointer. */
void fn_801D1364(void) {
    if (lbl_8055E908 != 0) {
        fn_80128670(lbl_8055E908 - 0x10);
    }
    lbl_8055E908 = 0;
}

void fn_801D139C(void) {

}

extern int lbl_8055E8F8;
extern char lbl_8055ABD0;
void fn_801D1250(float*, int);
void *fn_8012850C(int, void*);
void* fn_8002F37C(void (*)(void*), int, int, int);
void fn_801D14BC(void*);
extern void *fn_8012850C();
extern void *fn_8002F37C();
#pragma inline_depth(0)
/* Call fn_801D1250 for each 0x34-byte entry in the lbl_8055E908 array
 * (count lbl_8055E8F8). */
void fn_801D13A0(void) {
    int entryOffset = 0;
    int index = 0;
    while (index < lbl_8055E8F8) {
        fn_801D1250((float *)(lbl_8055E908 + entryOffset), index);
        entryOffset += 0x34;
        index++;
    }
}
/* Iterates over the array at lbl_8055E908 (0x34 bytes per element, count lbl_8055E8F8)
 * and calls fn_801D1244 to reset each element's first float. */
void fn_801D13FC(void) {
    int offset = 0;
    int i = 0;
    while (i < lbl_8055E8F8) {
        ((void (*)(float *, int))fn_801D1244)((float *)(lbl_8055E908 + offset), i);
        offset += 0x34;
        i++;
    }
}
void fn_801D1458(void *arg0, int entryIndex) {
#define sEntries lbl_8055E908
#define processEntry fn_801D11D4
    /* Process the 0x34-byte entry at entryIndex in the entry array through the
       per-entry trampoline (which tail-calls into fn_801D11D8). */
    ((void (*)(int))processEntry)(sEntries + entryIndex * 0x34);
#undef processEntry
#undef sEntries
}

/* Allocates and initializes the lbl_8055E908 array with lbl_8055E8F8 entries of 0x34 bytes,
 * using fn_801D14BC to initialize each element. */
void fn_801D1468(void) {
    int count = lbl_8055E8F8;
    int buffer = (int)fn_8012850C(count * 0x34 + 0x10, &lbl_8055ABD0);
    lbl_8055E908 = ((int (*)(int, void *, int, int, int))fn_8002F37C)(buffer, fn_801D14BC, 0, 0x34, count);
}

// Zeroes the eight float fields of one 0x34-byte entry (element-init callback).
void fn_801D14BC(void* entry) {
    float zero = lbl_80562A4C;
    *(float*)((char*)entry+0x18)=zero; *(float*)((char*)entry+0x14)=zero;
    *(float*)((char*)entry+0x10)=zero; *(float*)((char*)entry+0xc)=zero;
    *(float*)((char*)entry+8)=zero; *(float*)((char*)entry+4)=zero;
    *(float*)((char*)entry+0x1c)=zero; *(float*)((char*)entry+0x20)=zero;
}

extern void *lbl_804348E8[];
extern float lbl_80562A4C;
extern void fn_801819A0(void *, void *, void *, float, float, float);
