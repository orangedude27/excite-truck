// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_80339570;
extern int fn_8000DA10(void);
extern void fn_801332D0(int, int*, int*);
extern int lbl_8055E9DC;
extern int lbl_8055E9E0;
extern char lbl_804873B8[];
extern char lbl_803394FC[];
extern void *lbl_8055E9F0;
extern char lbl_804872B0[];
extern int lbl_8055ADF0, lbl_8055ADF4, lbl_8055E9E8;
extern float lbl_80562BF4;
extern void *memcpy(void *, const void *, unsigned int);
extern unsigned long long fn_802E2C9C(int);
extern void fn_801331C4(int, int *, float *);

#pragma scheduling invalid_target
void fn_801DE7E8(int arg0) {
    /* Fix note: use the mode value to initialize the corresponding table fields. */
    extern char lbl_804872B0[];
    extern char lbl_803394B0[], lbl_803394BC[];
    extern int fn_80145E70(const char *);
    extern int fn_802CAC28(const char *, int);
    int index, value;
    switch (arg0) {
    case 1:
        value = fn_80145E70(lbl_803394B0);
        index = arg0 * 0x1c;
        *(int *)(lbl_804872B0 + index + 0xc) = value;
        break;
    case 2:
        index = arg0 * 0x1c;
        value = fn_80145E70(lbl_803394B0);
        *(int *)(lbl_804872B0 + index + 0xc) = value;
        value = fn_802CAC28(lbl_803394BC, 0);
        *(int *)(lbl_804872B0 + index + 0x14) = value;
        break;
    }
}
#pragma scheduling on
void fn_801DE88C(void) {

}

#pragma small_data off
void fn_801DE9F0(int arg0, int arg1) {
    float value;
    register float newValue;
    register void* object;
    int bits;
    unsigned long long time;

    if (arg0 != 8 || lbl_8055E9E0 < *(int*)((char*)lbl_804873B8 + 4)) {
        if (arg0 == 8) {
            int count = lbl_8055E9E0;
            int *table = *(int**)lbl_804873B8;
            memcpy(lbl_804872B0 + 0xE0, (char*)table + count * 0x1C, 0x1C);
            lbl_8055E9E0 = lbl_8055E9E0 + 1;
        }
        bits = lbl_8055E9DC;
        lbl_8055E9E8 = arg0;
        lbl_8055E9DC = bits | (1 << arg0);
        time = fn_802E2C9C(bits);
        lbl_8055ADF4 = (int)time;
        lbl_8055ADF0 = (int)(time >> 32);
        if (lbl_8055E9F0 != 0 && arg1 != 0) {
            value = lbl_80562BF4;
            fn_801331C4(4, (int *)lbl_803394FC, &value);
            newValue = value;
            object = lbl_8055E9F0;
            if (newValue != *(float*)((char*)object + 8)) {
                *((unsigned char*)object + 0x4D) = 1;
                *(float*)((char*)object + 8) = newValue;
            }
            object = lbl_8055E9F0;
            *((unsigned char*)object + 0x49) = 1;
            *((unsigned char*)object + 0x4B) = 0;
            *((unsigned char*)object + 0x4A) = 0;
        }
    }
}
#pragma small_data on

unsigned int fn_801DEB6C(const char *arg0) {
    extern const char *lbl_802F99C8[7];
    extern int stricmp(const char *, const char *);
    const char *items[7];
    const char **src = lbl_802F99C8;
    const char **p;
    unsigned int i;
    items[0] = *src++;
    items[1] = *src++;
    items[2] = *src++;
    items[3] = *src++;
    items[4] = *src++;
    items[5] = *src++;
    items[6] = *src++;
    p = items;
    i = 0;
    do {
        if (stricmp(arg0, *p) == 0) return i;
        ++i;
        ++p;
    } while (i < 7);
    return 0;
}

#pragma scheduling invalid_target
void fn_801DEF98(void) {
    extern char lbl_80339570_arr[];
    int *p = (int *)lbl_80339570_arr;
    fn_801332D0(fn_8000DA10() + 0xC, p, &lbl_8055E9DC);
    lbl_8055E9E0 = 0;
    *(int *)((char *)&lbl_804873B8 + 4) = 0;
}
#pragma scheduling on
void fn_801DEFE0(void) {
    extern int lbl_8055E9E8;
    extern int lbl_8055E9EC;
    extern int lbl_8055ADF0;
    extern int lbl_8055ADF4;
    extern float lbl_80562BE8;
    extern float lbl_80562BF4;
    extern void __AXDSPInitCallback_801769E0(void);
    extern void fn_801769EC(void);
    extern int fn_80209190(int, float);

    if (lbl_8055E9E8 != 0) {
        __AXDSPInitCallback_801769E0();
        fn_80209190(lbl_8055E9EC, lbl_80562BE8);
        return;
    }
    if (*(long long *)&lbl_8055ADF0 >= 0) {
        fn_801769EC();
        fn_80209190(lbl_8055E9EC, lbl_80562BF4);
        lbl_8055ADF4 = -1;
        lbl_8055ADF0 = -1;
    }
}

extern int lbl_8055E9E8;
extern int lbl_8055E9DC;
extern int lbl_8055E9EC;
extern int lbl_8055ADF0;
extern int lbl_8055ADF4;
extern int lbl_8055E9E0;
extern float lbl_80562BE8;
extern float lbl_80562BF4;
extern char lbl_804872B0[];
extern char lbl_804873B8[];
extern int fn_801E85A4(void);
extern int fn_80209190(int, float);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_801769EC(void);
extern int fn_8000DA10(void);
extern void fn_801332D0(int, int*, int*);
int fn_801DF060(void) {
    int val = lbl_8055E9E8;
    unsigned int tmp = (unsigned int)(-val) | (unsigned int)val;
    return (int)(tmp >> 31);
}

extern float lbl_80562BF8, lbl_80562BFC, lbl_80562C00, lbl_80562C04, lbl_80562C08, lbl_80562C0C, lbl_80562C10;
extern int lbl_8055AE28;
extern char lbl_803395C4[];
extern int fn_801769F8(void);
extern void fn_80011278(int, float, float, float, float);
extern void fn_800103B8(int, int, float, float, float, float, const char *, ...);
extern void fn_8000FF88(int, int, const char *, float, float, float, ...);
extern void fn_801DE890(int);
extern void fn_80011A2C(void);
int fn_801DF110(void) {
    struct Entry {
        int field0;
        int arg1;
        int arg2;
        int field3;
        void *object;
        int field5;
        int (*callback)(int, int);
    };
    if (lbl_8055E9E8 != 0) {
        if (fn_801769F8() != 0) {
            char *base = lbl_804872B0;
            struct Entry *entry = (struct Entry *)(base + lbl_8055E9E8 * 0x1C);
            int (*callback)(int, int) = entry->callback;

            if (callback != 0) {
                callback(entry->arg2, entry->arg1);
            } else {
                fn_80011278(-1, lbl_80562BF8, lbl_80562BFC, lbl_80562C00, lbl_80562C04);
                entry = (struct Entry *)(base + lbl_8055E9E8 * 0x1C);
                ((void (*)(int, int, float, float, float, float, const char *, ...))fn_800103B8)(
                    -1, 0xC, lbl_80562BF4, lbl_80562BE8, lbl_80562C08, lbl_80562C0C, (const char *)&lbl_8055AE28, entry->arg1);
                ((void (*)(int, int, const char *, float, float, float, ...))fn_8000FF88)(
                    -1, 0xC, (const char *)lbl_803395C4, lbl_80562BF4, lbl_80562BE8, lbl_80562C10);
                fn_801DE890(lbl_8055E9E8);
            }

            entry = (struct Entry *)(lbl_804872B0 + lbl_8055E9E8 * 0x1C);
            if (entry->object != 0)
                ((void (*)(void *))(*(void **)((char *)(*(void **)entry->object) + 0xC)))(entry->object);
            fn_80011A2C();
            return 1;
        }
    }
    return 0;
}

int fn_801DF238(int arg0) {
    extern int fn_801769F8(void);
    extern void fn_801DEB10(void);
    extern void fn_800121A4(void);
    extern void fn_801331C4(int, int *, float *);
    extern int lbl_804874A8[];
    extern int lbl_8055E9F4;
    extern float lbl_80562BF4;
    // Fix note: handles eligible event types, samples the selected object, and advances the four-entry ring index.
    float value;
    int *object;
    if (lbl_8055E9E8 != 0) {
        if (fn_801769F8() != 0) {
            if (arg0 == 0x58 || (arg0 < 0x58 && arg0 == 0xD)) {
                if (lbl_8055E9E8 == 8 && lbl_8055E9E0 < *(int *)((char *)&lbl_804873B8 + 4))
                    fn_801DE9F0(8, 0);
                else
                    fn_801DEB10();
                object = (int *)lbl_804874A8[lbl_8055E9F4];
                if (object != 0 && *(unsigned char *)((char *)object + 0x19) == 0) {
                    value = lbl_80562BF4;
                    fn_801331C4(4, (int *)lbl_803394FC, &value);
                      object = (int *)lbl_804874A8[lbl_8055E9F4];
                    if (value != *(float *)((char *)object + 8)) {
                        *((unsigned char *)object + 0x4D) = 1;
                        *(float *)((char *)object + 8) = value;
                    }
                    object = (int *)lbl_804874A8[lbl_8055E9F4];
                    *((unsigned char *)object + 0x49) = 1;
                    *((unsigned char *)object + 0x4B) = 0;
                    *((unsigned char *)object + 0x4A) = 0;
                } else fn_800121A4();
                lbl_8055E9F4 = (lbl_8055E9F4 + 1) & 3;
            }
        }
        return 1;
    }
    return 0;
}

#pragma small_data off
void fn_801DF380(int arg0, int arg1, int arg2, int arg3) {
    int *base = (int *)lbl_804873B8;
    int index = *(int *)((char *)&lbl_804873B8 + 4);
    int *entry = (int *)((char *)base + index * 0x1C);
    *(int *)((char *)&lbl_804873B8 + 4) = index + 1;
    entry[6] = arg2;
    entry[4] = arg3;
    entry[2] = arg0;
    entry[1] = arg1;
    *(unsigned char *)entry = 0;
}
#pragma small_data on
extern void *memcpy(void *, const void *, unsigned int);
extern unsigned long long fn_802E2C9C(int);
extern void fn_801331C4(int, int *, float *);
extern int lbl_80339570;
extern int fn_8000DA10(void);
extern void fn_801332D0(int, int*, int*);
extern int lbl_8055E9DC;
extern int lbl_8055E9E0;
extern char lbl_804873B8[];
