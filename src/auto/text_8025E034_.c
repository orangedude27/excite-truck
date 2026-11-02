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

extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
extern void *lbl_8055F3D4;
typedef int (*CountFn)(void *);
typedef void *(*GetFn)(void *, int);
typedef int (*TestFn)(void *);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8025F274(void) {
    struct Container {
        virtual int unused();
        virtual int count();
        virtual void *get(int);
    };
    struct Item {
        virtual int f0();
        virtual int f1();
        virtual int f2();
        virtual int f3();
        virtual int f4();
        virtual int f5();
        virtual int f6();
        virtual int test24();
        virtual int f8();
        virtual int test2c();
    };
    register int i;
    register int j;
    register void *value;
    register int offset;
    register int found;
    i = 0;
    goto L_check;
L_outer:
    j = 0;
    offset = 0;
    do {
        if (i >= ((Container *)(*(void **)((char *)lbl_8055F3D4 + offset + 4)))->count())
            goto L_first_retry;
        value = ((Container *)(*(void **)((char *)lbl_8055F3D4 + offset + 4)))->get(i);
        if (((Item *)value)->test24() != 0)
            goto L_first_found;
        if (((Item *)value)->test2c() != 0)
            goto L_first_retry;
L_first_found:
        found = 1;
        goto L_first_done;
L_first_retry:
        j++;
        offset += 4;
    } while (j < 3);
    found = 0;
L_first_done:
    if (found == 0)
        fn_80214A9C(i + 0x10);
    j = 0;
    offset = 0;
    do {
        if (i >= ((Container *)(*(void **)((char *)lbl_8055F3D4 + offset + 4)))->count())
            goto L_second_retry;
        value = ((Container *)(*(void **)((char *)lbl_8055F3D4 + offset + 4)))->get(i);
        if (((Item *)value)->test24() != 0)
            goto L_second_found;
        goto L_second_retry;
L_second_found:
        found = 1;
        goto L_second_done;
L_second_retry:
        j++;
        offset += 4;
    } while (j < 3);
    found = 0;
L_second_done:
    if (found == 0)
        fn_80214A9C(i + 0x1A);
    i++;
L_check:
    if (i < ((Container *)(*(void **)lbl_8055F3D4))->count())
        goto L_outer;
    {
        register int arg;
        register char *base;
        register int inner;
        register int group;
        base = (char *)lbl_8055F3D4;
        group = 0;
        do {
            arg = group + 1;
            inner = 0;
            do {
                if (inner == *(int *)(base + 0x144))
                    fn_80214AF0(arg);
                else
                    fn_80214A9C(arg);
                inner++;
                arg += 0xA;
            } while (inner < 3);
            group++;
            base += 0x58;
        } while (group < 5);
    }
}
#pragma cplusplus reset
#pragma scheduling on
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

extern void *fn_801284F8(int, const char *);
extern void *fn_8012850C(int, const char *);
extern void *fn_80131808(const char *);
extern void fn_80131818(void *);
extern int fn_802CAC28(const char *, int);
extern int strcmp(const char *, const char *);
extern char lbl_80344720[], lbl_80344730[], lbl_80344740[], lbl_80344750[], lbl_80344760[];
__declspec(section ".sdata") extern char lbl_8055C0EC[];
__declspec(section ".sdata") extern char lbl_8055C0F0[];
__declspec(section ".sdata") extern char lbl_8055C0F4[];
__declspec(section ".sdata") extern char lbl_8055C0F8[];
__declspec(section ".sdata") extern char lbl_8055C0FC[];
__declspec(section ".sdata") extern char lbl_8055C100[];
__declspec(section ".sdata") extern char lbl_8055C108[];
__declspec(section ".sdata") extern char lbl_8055C10C[];
__declspec(section ".sdata") extern char lbl_8055C114[];
extern void *lbl_8055F2E4;
extern int lbl_8055F2E8;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void *fn_8025FA18(void) {
    int count, index;
    void *heap, *set, *entry;
    char *dst, *src;
    int *record;
    int i;

    if (lbl_8055F2E8 == 0) {
        heap = fn_801284F8(8, lbl_8055C114);
        if (heap != 0) {
            set = fn_80131808(lbl_80344760);
            *(int *)((char *)heap + 4) = 0;
            *(void **)heap = fn_8012850C(0xAF0, lbl_8055C10C);
            count = 0;
            for (;;) {
                entry = ((void *(*)(void *, int))((void **)*(void **)set)[3])(set, count);
                if (entry == 0) break;
                if (strcmp(((char *(*)(void *))((void **)*(void **)entry)[2])(entry), lbl_8055C108) == 0) {
                    index = 0;
                    do {
                        int n = *(int *)((char *)heap + 4);
                        record = (int *)((char *)*(void **)heap + n * 0x38);
                        *(int *)((char *)heap + 4) = n + 1;
                        src = ((char *(*)(void *, const char *))((void **)*(void **)entry)[5])(entry, lbl_8055C100);
                        dst = (char *)record;
                        for (i = 0; i < 0x20; i++) {
                            char c = *src++;
                            *dst++ = c;
                            if (c == 0) break;
                        }
                        if (index != 0) {
                            dst = (char *)record;
                            for (i = 0; i < 0x20 && dst[i] != 0; i++) {}
                            if (i < 0x20) {
                                src = lbl_8055C0FC;
                                do { *dst++ = *src; } while (*src++ != 0);
                            }
                        }
                        record[8] = fn_802CAC28(index ? lbl_80344750 : lbl_80344740, 0);
                        record[9] = fn_802CAC28(index ? lbl_80344730 : lbl_80344720, 0);
                        *(float *)((char *)record + 0x28) = ((float (*)(void *, const char *))((void **)*(void **)entry)[9])(entry, lbl_8055C0F8);
                        *(float *)((char *)record + 0x2C) = ((float (*)(void *, const char *))((void **)*(void **)entry)[9])(entry, lbl_8055C0F4);
                        *(float *)((char *)record + 0x30) = ((float (*)(void *, const char *))((void **)*(void **)entry)[9])(entry, lbl_8055C0F0);
                        index++;
                        *(float *)((char *)record + 0x34) = ((float (*)(void *, const char *))((void **)*(void **)entry)[9])(entry, lbl_8055C0EC);
                    } while (index < 2);
                }
                count++;
            }
            fn_80131818(set);
        }
        lbl_8055F2E4 = heap;
    }
    lbl_8055F2E8++;
    return lbl_8055F2E4;
}
#pragma pop
extern float lbl_80563B70;
extern float lbl_80563B74;
extern float lbl_80563B78;
extern double lbl_80563B80;
extern void fn_80230C30(float *, float *, int, int);
extern void fn_802354A0(int, unsigned char, int, float, float, float, float, float);
extern void fn_80231220(int, int, float, float, float, float, float, float, float, float);
extern float lbl_80563B70, lbl_80563B74, lbl_80563B78;
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8025FC8C(void* p, int arg1) {
    float spC, sp8, outC, out8, f29, f28, f27, f26, f25, f24;
    unsigned int color, packed;
    int red, green, blue;
    char* item;
    if (*(unsigned char*)((char*)p + 0x25) == 0)
        return;
    fn_80230C30(&spC, &sp8, *(int*)((char*)p + 4), *(int*)((char*)p + 8));
    f25 = (float)*(int*)((char*)p + 0xC);
    f24 = (float)*(int*)((char*)p + 0x10);
    fn_802354A0(*(int*)((char*)p + 0x2C), *(unsigned char*)((char*)p + 0x24), -1,
        spC - lbl_80563B70, lbl_80563B70 + sp8, lbl_80563B74,
        lbl_80563B78 + f25, lbl_80563B78 + f24);
    item = (char*)**(void***)((char*)p + 0x18) + *(int*)((char*)p + 0x1C) * 0x38;
    out8 = sp8;
    outC = spC;
    f26 = *(float*)(item + 0x28);
    f27 = *(float*)(item + 0x2C);
    f28 = *(float*)(item + 0x30);
    f29 = *(float*)(item + 0x34);
    color = *(unsigned int*)((char*)p + 0x28);
    fn_80231220(*(int*)(item + 0x20), -1, outC, out8, f25, f24, f26, f27, f28, f29);
    blue = (color & 255) * 65025;
    blue = (blue / 256) / 256;
    green = ((color >> 8) & 255) * 65025;
    green = (green / 256) / 256;
    red = ((color >> 16) & 255) * 65025;
    red = (red / 256) / 256;
    packed = (red & 255) << 16;
    packed |= 0xFF000000;
    packed = (packed & 0xFFFF00FF) | ((green & 255) << 8);
    packed = (packed & 0xFFFFFF00) | (blue & 255);
    fn_80231220(*(int*)(item + 0x24), packed,
        outC, out8, f25, f24, f26, f27, f28, f29);
}
#pragma use_lmw_stmw on
#pragma scheduling on
