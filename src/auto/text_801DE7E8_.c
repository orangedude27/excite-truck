// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

__declspec(section ".data") extern int lbl_80339570;
extern int fn_8000DA10(void);
extern void fn_801332D0(int, int*, int*);
extern int lbl_8055E9F4;
extern void *fn_80131810(void *);
extern void fn_802E30C8(const char *, ...);
extern int fn_802090D4(void *);
extern void *fn_80207848(void *, int);
extern int stricmp(const char *, const char *);
__declspec(section ".sdata") extern char lbl_8055AE00[];
__declspec(section ".sdata") extern char lbl_8055AE08[];
__declspec(section ".sdata") extern char lbl_8055AE10[];
__declspec(section ".sdata") extern char lbl_8055AE18[];
__declspec(section ".sdata") extern char lbl_8055AE20[];
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

/* Popup ids: the nine rows of lbl_804872B0.  Id 8 is the run-time queue pushed by
   fn_801DF380 (level-up and friends); showing it copies the next queued entry into
   row 8, so it repeats for as long as the queue holds entries. */
#define POPUP_QUEUED 8

/* One popup: a row of lbl_804872B0 or an entry of the run-time queue. */
struct PopupEntry {
    unsigned char always;        /* 0x00: show again even when already seen */
    int id;                      /* 0x04 */
    int arg1;                    /* 0x08 */
    void *text;                  /* 0x0C: text/resource handle */
    int arg3;                    /* 0x10 */
    int state;                   /* 0x14: sound state, -1 once stopped */
    int (*callback)(int, int);   /* 0x18: replaces the default message */
};

/* Header of the run-time popup queue at lbl_804873B8, filled by fn_801DF380. */
struct PopupQueue {
    struct PopupEntry *entries;
    int count;
};

/* The sound object fn_80207848 builds (0x70 bytes, see src/auto/text_802062E8.cpp).
   Each flag below queues the matching call on the sound at +0xC when it is next
   updated; fn_80206824 is what starts, loops and stops it. */
struct SoundObject {
    void *vtable;                /* 0x00 */
    float volume2;               /* 0x04: second volume, queued by flag 0x4E */
    float volume;                /* 0x08 */
    void *sound;                 /* 0x0C */
    unsigned char gap10[0x39];
    unsigned char play;          /* 0x49: start playing on the next update */
    unsigned char loop;          /* 0x4A */
    unsigned char stopMode;      /* 0x4B */
    unsigned char gap4C;         /* 0x4C */
    unsigned char volumeChanged; /* 0x4D: hand `volume` to the sound */
};

#pragma scheduling invalid_target
void fn_801DE7E8(int arg0) {
    extern char lbl_804872B0[];
    extern char lbl_803394B0[];
    extern char lbl_803394BC[];
    extern int fn_80145E70(const char *);
    extern int fn_802CAC28(const char *, int);
    int index;
    int value;
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
extern void fn_80147F30(int, int, int, float, float, float, float, float, float, float, float, float, float);
extern void fn_8014E7D8(int, int, int);
extern int lbl_8055CFF0;
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
                float r10;
                float be4;
                float r14;
                float t6;
                float t5;
                float r4v;
                float r8v;
                float bf4;
                float be0;
                fn_801476D8((int)result, -1, *(int *)(entry + 0x14));
                r10 = *(float *)((char *)result + 0x10);
                be4 = lbl_80562BE4;
                r14 = *(float *)((char *)result + 0x14);
                t6 = r10 * be4;
                t5 = r14 * be4;
                r4v = *(float *)((char *)result + 4);
                r8v = *(float *)((char *)result + 8);
                bf4 = lbl_80562BF4;
                be0 = lbl_80562BE0;
                fn_80147F30(0xFFC8C800, 0x3E8, -1, r4v + t6, r8v + t5, be0 * t6,
                    lbl_80562BE8, lbl_80562BEC, lbl_80562BF0, lbl_80562BE8, lbl_80562BE8,
                    bf4, bf4);
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
/* Show popup `popupId`.  The queued popup (POPUP_QUEUED) first copies the next entry
   of the run-time queue into row 8 of the popup table and stops once the queue is
   empty.  The popup is remembered as seen in the saved popups_seen mask, its id and
   the time it was raised are kept for fn_801DEFE0/fn_801DF238, and - when playSound
   is set - the level-up sound is given the effects_volume setting and started once
   without looping. */
void fn_801DE9F0(int popupId, int playSound) {
    float volume;
    register float newVolume;
    register struct SoundObject *sound;
    int seenBits;
    unsigned long long start;

    if (popupId != POPUP_QUEUED ||
        lbl_8055E9E0 < ((struct PopupQueue *)lbl_804873B8)->count) {
        if (popupId == POPUP_QUEUED) {
            int next = lbl_8055E9E0;
            struct PopupEntry *entries = ((struct PopupQueue *)lbl_804873B8)->entries;
            memcpy(lbl_804872B0 + POPUP_QUEUED * sizeof(struct PopupEntry),
                   (char *)entries + next * sizeof(struct PopupEntry),
                   sizeof(struct PopupEntry));
            lbl_8055E9E0 = lbl_8055E9E0 + 1;
        }
        seenBits = lbl_8055E9DC;
        lbl_8055E9E8 = popupId;
        lbl_8055E9DC = seenBits | (1 << popupId);
        start = fn_802E2C9C(seenBits); /* time in us; the argument is left over */
        lbl_8055ADF4 = (int)start;
        lbl_8055ADF0 = (int)(start >> 32);
        if (lbl_8055E9F0 != 0 && playSound != 0) {
            volume = lbl_80562BF4;
            fn_801331C4(4, (int *)lbl_803394FC, &volume); /* "effects_volume" */
            newVolume = volume;
            sound = (struct SoundObject *)lbl_8055E9F0;
            if (newVolume != sound->volume) {
                sound->volumeChanged = 1;
                sound->volume = newVolume;
            }
            sound = (struct SoundObject *)lbl_8055E9F0;
            sound->play = 1;
            sound->stopMode = 0;
            sound->loop = 0;
        }
    }
}

#pragma dont_inline on
void fn_801DEB10(void) {
    unsigned long long result;
    if (lbl_8055E9E8 == 8) {
        lbl_8055E9E0 = 0;
        *(int *)(lbl_804873B8 + 4) = 0;
    }
    lbl_8055E9E8 = 0;
    lbl_8055E9DC |= 1;
    result = ((unsigned long long (*)(void))fn_802E2C9C)();
    lbl_8055ADF4 = (unsigned int)result;
    lbl_8055ADF0 = result >> 32;
}
#pragma dont_inline off

#pragma small_data on

/* Return the index of the given event/popup name in the 7-entry lbl_802F99C8 name table, or 0 if not found. */
unsigned int fn_801DEB6C(const char *name) {
    extern const char *lbl_802F99C8[7];
    extern int stricmp(const char *, const char *);
    const char *nameTable[7];
    const char **src = lbl_802F99C8;
    const char **entry;
    unsigned int index;
    nameTable[0] = *src++;
    nameTable[1] = *src++;
    nameTable[2] = *src++;
    nameTable[3] = *src++;
    nameTable[4] = *src++;
    nameTable[5] = *src++;
    nameTable[6] = *src++;
    entry = nameTable;
    index = 0;
    do {
        if (stricmp(name, *entry) == 0) return index;
        ++index;
        ++entry;
    } while (index < 7);
    return 0;
}

#pragma push
#pragma cplusplus on
#pragma dont_inline on
extern "C" void fn_801DEC18(void) {
    class Node {
    public:
        virtual const char *m0();
        virtual void m1();
        virtual void m2();
        virtual int m3(const char *);
        virtual void m4();
        virtual void m5();
        virtual void m6();
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual char m10(const char *, int);
    };
    class Handle {
    public:
        virtual void m0();
        virtual Node *get(int);
    };
    float sp8;
    register char *base = (char *)lbl_803394B0;
    char *name;
    Handle *h;
    int n;
    Node *node;
    unsigned int j;
    void *obj;
    fn_801332D0(fn_8000DA10() + 0xC, (int *)(base + 0xC0), &lbl_8055E9DC);
    name = base + 0xCC;
    h = (Handle *)fn_80131810(name);
    lbl_8055E9E4 = (int)h;
    if (h != 0) {
        n = 0;
        node = h->get(0);
        while (node != 0) {
            if (stricmp(node->m0(), lbl_8055AE00) == 0) {
                name = lbl_804872B0 + fn_801DEB6C((const char *)node->m3(lbl_8055AE08)) * 0x1C;
                *(int *)(name + 4) = node->m3(lbl_8055AE10);
                *(char *)name = node->m10(lbl_8055AE18, 0);
            }
            n++;
            node = ((Handle *)lbl_8055E9E4)->get(n);
        }
    } else {
        fn_802E30C8(base + 0xD8, name);
    }
    lbl_8055E9EC = fn_802090D4(lbl_8055AE20);
    lbl_8055E9F0 = fn_80207848(base + 0xF8, 0);
    sp8 = lbl_80562BF4;
    fn_801331C4(4, (int *)(base + 0x4C), &sp8);
    obj = lbl_8055E9F0;
    if (obj != 0) {
        float v = sp8;
        if (v != *(float *)((char *)obj + 8)) {
            *((unsigned char *)obj + 0x4D) = 1;
            *(float *)((char *)obj + 8) = v;
        }
    }
    name = (char *)lbl_804874A8;
    for (j = 0; j < 4; j++) {
        obj = fn_80207848(base + 0x104, 0);
        *(void **)name = obj;
        if (obj != 0) {
            float v = sp8;
            if (v != *(float *)((char *)obj + 8)) {
                *((unsigned char *)obj + 0x4D) = 1;
                *(float *)((char *)obj + 8) = v;
            }
        }
        name += 4;
    }
    lbl_8055E9F4 = 0;
    lbl_8055E9E8 = 0;
    lbl_8055ADF4 = -1;
    lbl_8055ADF0 = -1;
    for (j = 0; j < 9; j++)
        fn_801DE7E8(j);
}
#pragma pop

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
    /* Tear down popup/UI state: for 9 rows at lbl_804872B0 (stride 0x1C)
       destroy object (vcall d0(1)) and clear, stop active state via
       fn_802CAC54 if != -1, call fn_801DE88C(i); then shutdown lbl_8055E9EC via
       fn_80209110 and destroy singleton object lbl_8055E9F0; destroy/clear 4
       objects in table lbl_804874A8; if handle lbl_8055E9E4 nonzero close via
       fn_80131818; clear lbl_8055E9E8 and save/clear flags lbl_8055E9DC through
       fn_80133348(fn_8000DA10()+0xC, &lbl_80339570 "popups_seen", lbl_8055E9DC). */
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
/* If enabled (lbl_8055E9E8), run the AX DSP init callback and apply level
 * lbl_80562BE8 to lbl_8055E9EC. Otherwise, when the 64-bit value at
 * lbl_8055ADF0/lbl_8055ADF4 is non-negative, run fn_801769EC, apply
 * lbl_80562BF4 to lbl_8055E9EC, then clear both to -1. */
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

int fn_801DF074(int popupId, int arg1) {
    /* Attempts to show popup 7 or 8 when allowed; delegates to fn_801DE9F0 and returns 1 on success. */
    if ((unsigned int)(popupId - 7) <= 1U && fn_801E85A4() == 1 && lbl_8055E9E8 == 0 && (((unsigned char *)lbl_804872B0)[popupId * 0x1C] != 0 || !(lbl_8055E9DC & (1 << popupId)))) {
        fn_801DE9F0(popupId, arg1);
        return 1;
    }
    return 0;
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
                ((void (*)(int))fn_801DE890)(lbl_8055E9E8);
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

int fn_801DF238(int eventId) {
    extern int fn_801769F8(void);
    extern void fn_800121A4(void);
    extern void fn_801331C4(int, int *, float *);
    extern int lbl_804874A8[];
    extern int lbl_8055E9F4;
    extern float lbl_80562BF4;
    /* Handles popup/input events 0x0D and 0x58 while the UI is active: advances or resets
       popup state, samples a value into the current queued object (or advances the queue on
       failure), marks it updated, and rotates the active object index. Returns 1 if active,
       0 otherwise. */
    float value;
    register float sampled;
    int *object;
    if (lbl_8055E9E8 != 0) {
        if (fn_801769F8() != 0) {
            if (eventId == 0x58) {
                goto handle;
            } else if (eventId < 0x58) {
                switch (eventId) {
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
    char *base;
    int index;
    char *entry;
    base = *(char **)lbl_804873B8;
    index = *(int *)(lbl_804873B8 + 4);
    *(int *)(lbl_804873B8 + 4) = index + 1;
    entry = base + index * 0x1C;
    *(int *)(entry + 0x18) = arg2;
    *(int *)(entry + 0x10) = arg3;
    *(int *)(entry + 0x8) = arg0;
    *(int *)(entry + 0x4) = arg1;
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
