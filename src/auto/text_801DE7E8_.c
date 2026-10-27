// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

__declspec(section ".data") extern int lbl_80339570;
extern int fn_8000DA10(void);
extern void fn_801332D0(int, int*, int*);
extern int fn_80133348(int, int, int);
extern int lbl_8055E9DC;
extern int lbl_8055E9E0;
extern int lbl_8055E9EC;
extern int lbl_8055E9E4;
extern int lbl_804874A8[];
extern char lbl_804873B8[];
extern char lbl_803394FC[];
extern void *lbl_8055E9F0;
extern char lbl_804872B0[];
extern void fn_802CAC54(void);
extern void fn_80209110(void *);
extern void fn_80131818(void);
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

#pragma cplusplus off
extern void fn_801473F8(void *, const char *, ...);
extern int fn_802E2C20(void);
extern void fn_801476D8(int, int, int);
extern void fn_80147F30(int, int, int, float, float, float, float, float, float, float, float);
extern void fn_8014E7D8(int, int, int);
extern unsigned int lbl_8055CFF0;
extern float lbl_80562BE0, lbl_80562BE4, lbl_80562BE8, lbl_80562BEC, lbl_80562BF0, lbl_80562BF4;
extern char lbl_803394B0[], lbl_804872B0[];
#pragma cplusplus on
extern "C" void fn_801DE890(int arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void *call(const char *);
    };
    char *text = lbl_803394B0;
    char *entry = lbl_804872B0 + arg0 * 0x1C;
    switch (arg0) {
    case 1:
        fn_801473F8(*(void **)(entry + 0xC), text + 0x18, text + 0x28);
        break;
    case 2:
        if ((fn_802E2C20() / 500) % 2 != 0) {
            struct Dummy *object = *(struct Dummy **)(entry + 0xC);
            void *result = object->call(text + 0x38);
            if (result != 0) {
                fn_801476D8((int)result, -1, *(int *)(entry + 0x14));
                fn_80147F30(0xFFC8C800, 0x3E8, -1,
                    *(float *)((char *)result + 4) + *(float *)((char *)result + 0x10) * lbl_80562BE4,
                    *(float *)((char *)result + 8) + *(float *)((char *)result + 0x14) * lbl_80562BE4,
                    lbl_80562BE0 * (*(float *)((char *)result + 0x10) * lbl_80562BE4),
                    lbl_80562BE8, lbl_80562BEC, lbl_80562BF0, lbl_80562BE8, lbl_80562BE8);
            }
        }
        break;
    case 3:
        fn_8014E7D8(lbl_8055CFF0 / 2, 0x6E, 0x32);
        break;
    }
}
#pragma cplusplus reset

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

#pragma cplusplus on
extern "C" void fn_801DEE3C(void) {
    struct Dummy {
        virtual void d0(int);
    };
    struct Row {
        int field0;
        int field1;
        int field2;
        Dummy *object;
        int field4;
        int state;
        int field6;
    };
    register int sentinel = -1;
    register int zero = 0;
    register char *row = lbl_804872B0;
    register unsigned int i = 0;
    Dummy *object;

    do {
        object = ((struct Row *)row)->object;
        if (object != 0) {
            if (object != 0)
                object->d0(1);
            ((struct Row *)row)->object = (Dummy *)zero;
        }
        {
            int state = ((struct Row *)row)->state;
            if (state != -1) {
                ((void (*)(int))fn_802CAC54)(state);
                ((struct Row *)row)->state = sentinel;
            }
        }
        ((void (*)(unsigned int))fn_801DE88C)(i);
        ++i;
        row += 0x1C;
    } while (i < 9);

    fn_80209110((void *)&lbl_8055E9EC);
    object = (Dummy *)lbl_8055E9F0;
    if (object != 0) {
        if (object != 0)
            object->d0(1);
        lbl_8055E9F0 = (void *)zero;
    }

    {
        register unsigned int j = 0;
        zero = (int)lbl_804874A8;
        sentinel = 0;
        do {
            object = *(Dummy **)zero;
            if (object != 0) {
                if (object != 0)
                    object->d0(1);
                *(int *)zero = sentinel;
            }
            ++j;
            zero += 4;
        } while (j < 4);
    }

    if (lbl_8055E9E4 != 0) {
        ((void (*)(int))fn_80131818)(lbl_8055E9E4);
        lbl_8055E9E4 = 0;
    }
    sentinel = 0;
    lbl_8055E9E8 = sentinel;
    fn_80133348(fn_8000DA10() + 0xC, (int)&lbl_80339570, lbl_8055E9DC);
    lbl_8055E9DC = sentinel;
}
#pragma cplusplus reset

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
#pragma cplusplus on
extern "C" int fn_801DF110(void) {
    struct Dummy {
        virtual void unused();
        virtual void call();
    };
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
                fn_800103B8(-1, 0xC, lbl_80562BF4, lbl_80562BE8, lbl_80562C08, lbl_80562C0C, (const char *)&lbl_8055AE28, entry->arg1);
                fn_8000FF88(-1, 0xC, (const char *)lbl_803395C4, lbl_80562BF4, lbl_80562BE8, lbl_80562C10);
                fn_801DE890(lbl_8055E9E8);
            }

            entry = (struct Entry *)(lbl_804872B0 + lbl_8055E9E8 * 0x1C);
            if (entry->object != 0)
                ((Dummy *)entry->object)->call();
            fn_80011A2C();
            return 1;
        }
    }
    return 0;
}
#pragma cplusplus reset

int fn_801DF238(int arg0) {
    extern int fn_801769F8(void);
    extern void fn_801DEB10(void);
    extern void fn_800121A4(void);
    extern void fn_801331C4(int, int *, float *);
    extern int lbl_804874A8[];
    extern int lbl_8055E9F4;
    extern float lbl_80562BF4;
    // Fix note: isolate the 0xD case in a bounded switch while keeping output conversion and object updates matched.
    float value;
    register float sampled;
    int *object;
    if (lbl_8055E9E8 != 0) {
        if (fn_801769F8() != 0) {
            if (arg0 == 0x58) {
                goto handle;
            } else if (arg0 < 0x58) {
                switch (arg0) {
                case 0xD:
                    goto handle;
                default:
                    goto event_done;
                }
            } else {
                goto event_done;
            }
handle:
            if (lbl_8055E9E8 == 8 && lbl_8055E9E0 < *(int *)((char *)&lbl_804873B8 + 4))
                fn_801DE9F0(8, 0);
            else
                fn_801DEB10();
            object = (int *)lbl_804874A8[lbl_8055E9F4];
            if (object != 0 && *(unsigned char *)((char *)object + 0x19) == 0) {
                value = lbl_80562BF4;
                fn_801331C4(4, (int *)lbl_803394FC, &value);
                sampled = value;
                object = (int *)lbl_804874A8[lbl_8055E9F4];
                if (sampled != *(float *)((char *)object + 8)) {
                    *((unsigned char *)object + 0x4D) = 1;
                    *(float *)((char *)object + 8) = sampled;
                }
                object = (int *)lbl_804874A8[lbl_8055E9F4];
                *((unsigned char *)object + 0x49) = 1;
                *((unsigned char *)object + 0x4B) = 0;
                *((unsigned char *)object + 0x4A) = 0;
            } else {
                fn_800121A4();
            }
            lbl_8055E9F4 = (lbl_8055E9F4 + 1) & 3;
event_done:
            ;
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
