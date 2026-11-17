// mixer — sound mixer incl. null backend ("Null Mixer", "mixer: ...").
// Recovered TU window 0x80208A18..0x80209410+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_80209410 (+ .ctors slot 0x802ED380) remains in
// auto/text_80209410_.c pending a promotion pass.
extern char lbl_8033BF18[];
extern char lbl_8033C058[];
extern char lbl_8055B4F0;
extern void *lbl_8055B4D8;
extern int lbl_8055B4DC;
extern char lbl_8055B4E8;
extern void *fn_801284F8(int, void *);
extern void fn_8000DBC8(void *);
extern int fn_802E9A14(void); /* config.c: the cached SCSoundMode */
extern void fn_8020A72C(void);
extern int fn_8013365C(int, int);
extern void *memset(void *, int, unsigned int);

extern float lbl_8055B4D0;
extern float lbl_8055B4D4;
extern float fn_80208A18(float);
extern char lbl_80489258[];

/* Mixer volume-handle table (bss lbl_80489258): up to 8 named volume handles.
 * A sound subsystem opens one with fn_802090D4(name) to scale the master
 * volume, sets its value with fn_80209190 and gives it back with
 * fn_80209110; fn_80208A18 multiplies the handles that have a name (an empty
 * name means the slot is free) and fn_80208D80 dumps the ones still held at
 * shutdown ("mixer: "%s" never destroyed their volume handle").
 * The number of slots in use is the int at +0x40. */
struct MixerVolumeHandle {
    /* 0x0 */ float volume;
    /* 0x4 */ const char *name;
};
#define MIXER_VOLUME_HANDLES ((struct MixerVolumeHandle *)lbl_80489258)
#define MIXER_VOLUME_HANDLE_COUNT (*(int *)(lbl_80489258 + 0x40))
#define MIXER_VOLUME_HANDLE_MAX 8

extern float lbl_80563230;
extern float lbl_80563234;
extern void fn_80208A50(float *);

extern void *lbl_8055EDA8;
/* Sound quality (config key "quality"): 0..2, kept in the void* slot gSoundQuality. */
enum SoundQuality {
    SOUND_QUALITY_LOW = 0,
    SOUND_QUALITY_MEDIUM = 1,
    SOUND_QUALITY_HIGH = 2
};
#define gSoundQuality lbl_8055EDA8
extern int lbl_80489238[4];
extern char lbl_8033BEF8[];
/* Messages in the lbl_8033BEF8 string block used by the mixer device registry. */
#define MIXER_BOGUS_NAME_OFF 0x60 /* "Dream 9407," */
#define MIXER_BOGUS_MSG_OFF 0x70  /* "tossing bogus mixer: %s" */
#define MIXER_FULL_MSG_OFF 0x88   /* "too many sound devices: %s" */
#define MIXER_DEVICE_MAX 6
#define MIXER_DEVICES lbl_80489238
#define MIXER_DEVICE_COUNT lbl_80489238[MIXER_DEVICE_MAX]
#define MIXER_SELECTED_DEVICE lbl_80489238[7]
extern char lbl_8033BF08[];
extern char lbl_8055B4E0;
extern void fn_801331C4(int, void *, float *);
extern void fn_8013323C(int, void *, float);
extern void fn_801332D0(int, void *, void *);
extern void fn_80209030(float);
extern void fn_80209090(int);
#pragma scheduling invalid_target
#pragma push
#pragma inline_depth(0)
float fn_80208A18(float value) {
    /* Scale value by the stored volume of every active mixer volume handle (a
     * slot whose name pointer is set); MIXER_VOLUME_HANDLE_COUNT slots are in
     * use out of at most MIXER_VOLUME_HANDLE_MAX. */
    struct MixerVolumeHandle *handles = MIXER_VOLUME_HANDLES;
    int count = MIXER_VOLUME_HANDLE_COUNT;
    int i;

    for (i = 0; i < count; i++) {
        if (handles[i].name != 0) {
            value *= handles[i].volume;
        }
    }
    return value;
}

#define baseEffectsVolume lbl_8055B4D0
#define effectiveMasterVolume lbl_8055B4D4
#define applyVolumeHandles fn_80208A18
/* Recompute the effective master volume: start from the configured effects volume,
   scale it by every active mixer volume handle, and store the result. The pointer
   argument is vestigial — callers pass a handle's volume but the body ignores it. */
void fn_80208A50(float *unusedVolume) {
    effectiveMasterVolume = applyVolumeHandles(baseEffectsVolume);
}
#undef baseEffectsVolume
#undef effectiveMasterVolume
#undef applyVolumeHandles

void fn_80208A78(void) {
    /* Load saved mixer settings for effects volume and sound quality, then apply them. */
    fn_801331C4(4, lbl_8033BEF8, &lbl_8055B4D0);
    fn_80209030(lbl_8055B4D0);
    fn_801332D0(4, &lbl_8055B4E0, &lbl_8055EDA8);
    fn_80209090((int)lbl_8055EDA8);
}

#pragma pop

void fn_80208AC8(int arg0, int arg1) {
    float value = lbl_80563230;
    switch (arg1) {
    case 3:
        fn_801331C4(arg0 + 12, lbl_8033BF08, &value);
        fn_8013323C(4, lbl_8033BEF8, value);
        fn_80209030(value);
        break;
    case 1:
    case 2:
        fn_801331C4(4, lbl_8033BEF8, &value);
        fn_8013323C(arg0 + 12, lbl_8033BF08, value);
        break;
    case 0:
        fn_8013323C(4, lbl_8033BEF8, value);
        fn_80209030(value);
        break;
    }
}

#pragma push
#pragma inline_depth(0)
/* Initializes the sound mixer backend and default settings. */
void fn_80208B8C(int initBackends) {
    int configMode = (int)fn_802E9A14();
    switch (configMode) {
    default:
    case 1:
        *(int *)&lbl_8055B4D8 = 1;
        break;
    case 2:
        *(int *)&lbl_8055B4D8 = 2;
        break;
    case 0:
        *(int *)&lbl_8055B4D8 = 0;
        break;
    }
    *(int *)(lbl_80489258 + 0x40) = 0;
    if (initBackends != 0) {
        void *nullMixer;
        int *mixerTable;
        memset((void *)lbl_80489238, 0, 0x20);
        nullMixer = fn_801284F8(0x10, lbl_8033BF18);
        if (nullMixer != 0) {
            *(void **)nullMixer = lbl_8033C058;
            memset((char *)nullMixer + 4, 0, 0xC);
        }
        mixerTable = (int *)lbl_80489238;
        mixerTable[mixerTable[6]] = (int)nullMixer;
        configMode = mixerTable[6];
        mixerTable[6] = configMode + 1;
        fn_8020A72C();
    }
    {
        int *mixerTable = (int *)lbl_80489238;
        fn_801332D0(4, &lbl_8055B4E8, (char *)mixerTable + 0x1C);
        configMode = mixerTable[7];
        if (configMode < 0 || configMode >= mixerTable[6])
            *(int *)((char *)lbl_80489238 + 0x1C) = 0;
    }
    fn_8013323C(4, lbl_8033BEF8, lbl_80563230);
    fn_80208A78();
    lbl_8055B4DC = fn_8013365C((int)&lbl_8055B4F0, (int)fn_80208A78);
    fn_8000DBC8((void *)fn_80208AC8);
}
#pragma pop
int fn_80208CFC(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Return the number of registered sound devices in the mixer registry. */
int fn_80208D3C(void) { return MIXER_DEVICE_COUNT; }

int fn_80208D4C(int index) {
    /* Return the mixer device handle registered at the given slot. */
    return MIXER_DEVICES[index];
}

/* Set the index of the currently selected mixer device. */
void fn_80208D60(int index) { MIXER_SELECTED_DEVICE = index; }

/* Return the index of the currently selected mixer device. */
int fn_80208D70(void) { return MIXER_SELECTED_DEVICE; }

extern const char lbl_8033BF28[];
extern char lbl_8055B4E8;
extern int lbl_8055B4DC;
extern void fn_802E317C(const char *, ...);
extern void fn_80133348(int, void *, int);
extern void fn_801336E0(int, void (*)(void));
#pragma scheduling default
#pragma cplusplus on
extern "C" const char lbl_8033BF28[];
extern "C" char lbl_8055B4E8;
extern "C" int lbl_8055B4DC;
extern "C" void fn_802E317C(const char *, ...);
extern "C" void fn_80133348(int, void *, int);
extern "C" void fn_801336E0(int, void (*)(void));
#pragma cplusplus reset
#pragma scheduling default
#pragma cplusplus on
extern "C" void fn_80208D80(int arg0) {
    char *entry = lbl_80489258;
    int enabled;
    int index = 0;
    int index2;
    struct Table {
        void *entries[6];
        int count;
        int value;
    };
    struct Table *base;
    void **items;
    void *object;

    while (index < *(int *)(lbl_80489258 + 0x40)) {
        enabled = *(int *)(entry + 4);
        if (enabled != 0) {
            fn_802E317C(lbl_8033BF28, enabled);
        }
        entry += 8;
        index++;
    }

    if (arg0 != 0) {
        items = (void **)lbl_80489238;
        base = (struct Table *)items;
        index2 = 0;
        while (index2 < base->count) {
            object = *items;
            if (object != 0) {
                struct Dummy {
                    virtual void call(int);
                };
                ((struct Dummy *)object)->call(1);
            }
            items++;
            index2++;
        }
    }

    fn_80133348(4, &lbl_8055B4E8, ((struct Table *)lbl_80489238)->value);
    fn_8013323C(4, lbl_8033BEF8, lbl_8055B4D0);
    fn_80133348(4, &lbl_8055B4E0, (int)lbl_8055EDA8);
    fn_801336E0(lbl_8055B4DC, fn_80208A78);
}

#pragma cplusplus on
extern "C" int strncmp(const char *, const char *, unsigned int);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" void fn_80208E90(void *objectPtr, int mode) {
    struct Dummy {
        virtual void close(int);
        virtual const char *name();
        virtual void unused10();
        virtual void unused14();
        virtual int enabled();
        virtual void unused1c();
        virtual void unused20();
        virtual void finish();
    };
    /* Registers a sound device: rejects a known-bogus device and devices past the
       6-slot limit, otherwise stores it (finalizing enabled ones when mode==1). */
    Dummy *device = (Dummy *)objectPtr;
    const char *messages = lbl_8033BEF8;
    int registerDevice;
    unsigned int count;

    if (strncmp(device->name(), messages + MIXER_BOGUS_NAME_OFF, 0xB) == 0) {
        fn_802E30C8(messages + MIXER_BOGUS_MSG_OFF, device->name());
        if (objectPtr != 0) {
            device->close(1);
        }
    } else {
        count = (unsigned int)MIXER_DEVICE_COUNT;
        if (count < MIXER_DEVICE_MAX) {
            registerDevice = mode == 0;
            if (mode == 1 && device->enabled() != 0) {
                registerDevice = 1;
                device->finish();
            }
            if (registerDevice != 0) {
                MIXER_DEVICES[MIXER_DEVICE_COUNT++] = (int)objectPtr;
            } else if (objectPtr != 0) {
                device->close(1);
            }
        } else {
            fn_802E30C8(messages + MIXER_FULL_MSG_OFF, device->name());
            if (objectPtr != 0) {
                device->close(1);
            }
        }
    }
}
#pragma cplusplus reset

#pragma cplusplus reset
float fn_80209028(void) {
    return lbl_8055B4D4;
}

#pragma cplusplus on
void fn_80209030(float arg0) {
    float value = lbl_80563230 < arg0 ? lbl_80563230 : arg0;
    value = value > lbl_80563234 ? value : lbl_80563234;
    lbl_8055B4D0 = value;
    fn_8013323C(4, lbl_8033BEF8, (float)(double)value);
    ((void (*)(void))fn_80208A50)();
}
#pragma cplusplus reset
/* Set the sound-quality setting (config "quality"): accept values 0..2, reset to low otherwise. */
void fn_80209090(int quality) {
    if (quality >= SOUND_QUALITY_LOW && quality <= SOUND_QUALITY_HIGH) {
        gSoundQuality = (void *)quality;
        return;
    }
    gSoundQuality = 0;
}

/* Get the current sound-quality setting (config "quality", 0..2). */
void* fn_802090B4(void) {
    return gSoundQuality;
}

extern void fn_802E30C8(const char *, ...);
extern const char lbl_8033C024[];
#define MIXER_SET_SOUND_MODE_NOOP_MSG lbl_8033C024 /* "mixer: MixerSetSoundMode is a NOOP" */
#pragma scheduling invalid_target
/* Null-mixer backend's MixerSetSoundMode: a no-op that only logs that the
 * requested sound mode is being ignored. */
void fn_802090BC(void) {
    fn_802E30C8(MIXER_SET_SOUND_MODE_NOOP_MSG);
}
#undef MIXER_SET_SOUND_MODE_NOOP_MSG
extern void *lbl_8055B4D8;
/* Get the configured sound mode (0/1/2, set in fn_80208B8C from config). */
void* fn_802090CC(void) {
    return lbl_8055B4D8;
}

void *fn_802090D4(int name) {
    /* Open a mixer volume handle for name, initialized to full volume (1.0f), and return it, or NULL if the table is full. */
    struct Entry {
        float value;
        int id;
    };
    struct State {
        struct Entry entries[8];
        int count;
    };
    struct State *state = (struct State *) lbl_80489258;
    int index = state->count;
    void *handle;
    handle = 0;
    if (((unsigned int) state->count) < 8U) {
        state->count = state->count + 1;
        handle = ((char *) state) + (index * 8);
        *((int *) (((char *) handle) + 4)) = name;
        *((float *) (((char *) state) + (index * 8))) = lbl_80563230;
    }
    return handle;
}

#pragma push
#pragma inline_depth(0)
#pragma scheduling invalid_target
/* Releases a volume handle: frees its slot (dropping free slots from the end
 * of the table), recomputes the master volume and clears the caller's pointer
 * so releasing it twice does nothing. */
void fn_80209110(void **handle) {
    if (*handle != 0) {
        ((struct MixerVolumeHandle *)*handle)->name = 0;
        while (MIXER_VOLUME_HANDLE_COUNT > 0) {
            if (MIXER_VOLUME_HANDLES[MIXER_VOLUME_HANDLE_COUNT - 1].name != 0)
                break;
            MIXER_VOLUME_HANDLE_COUNT = MIXER_VOLUME_HANDLE_COUNT - 1;
        }
        ((void (*)(void))fn_80208A50)();
        *handle = 0;
    }
}
#pragma scheduling on
#pragma pop

#pragma push
#pragma inline_depth(0)
void fn_80209190(float *volume, float newVolume) {
#define MAX_VOLUME lbl_80563230  /* 1.0f */
#define MIN_VOLUME lbl_80563234  /* 0.0f */
    /* Clamp a mixer volume to [0,1], store it in the handle, and recompute the master volume. */
    if (volume != 0) {
        float clamped = MAX_VOLUME < newVolume ? MAX_VOLUME : newVolume;
        clamped = clamped > MIN_VOLUME ? clamped : MIN_VOLUME;
        *volume = clamped;
        fn_80208A50(volume);
    }
#undef MIN_VOLUME
#undef MAX_VOLUME
}
#pragma pop

extern float lbl_80563230;
extern float lbl_80563234;
extern float fn_80208A18(float);
extern void fn_80208A50(float *);
extern int fn_80128668(void);
#pragma push
#pragma inline_depth(0)
/* Overall mixer gain for voices: start at full volume (lbl_80563230 is 1.0f),
 * multiply in every active volume handle, and return the product. The caller
 * in voicesnd.c stores this as gMasterVolume. Tail call, so the result stays
 * in f1. */
float fn_802091CC(void) {
    return fn_80208A18(lbl_80563230);
}
#pragma pop

int fn_802091D4(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

int fn_80209214(void) {
    // Trivial mixer helper stub; always reports 0 (false).
    return 0;
}

extern float lbl_8055B4D0;
extern void fn_801332D0(int, void *, void *);
#pragma scheduling on
int fn_8020921C(void) {
    extern unsigned int lbl_8048929C[];
    extern unsigned int lbl_8055E044;
    extern void fn_80131318(void);
    if (*(lbl_8048929C + 2) != lbl_8055E044)
        fn_80131318();
    return (int)*(lbl_8048929C + 1);
}
#pragma scheduling default
/* Trivial mixer helper: returns the supplied value advanced by 4. */
int fn_80209260(int value) { return value + 4; }

int fn_80209268(void) { return 1; }

/* Null-backend virtual stub: always reports true (1). */
int fn_80209270(void) { return 1; }

void fn_80209278(void) {

}

void fn_8020927C(void) {

}

extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];
/* RealName: Sound_CreateNullSource (allocate a 12-byte "Null Sound" object with vtable and value 3)
 * Allocates a small sound object tagged "Null Sound"; on success installs
 * its vtable pointer and sets its field at +8 to 3.
 */
void fn_80209280(void) {
#define sNullSoundTag lbl_8033C1C0
#define sNullSoundVTable lbl_8033C0E8
    struct Obj { void *vtable; int pad; int value; };
    struct Obj *soundObj = (struct Obj *)fn_801284F8(12, sNullSoundTag);

    if (soundObj) {
        soundObj->vtable = sNullSoundVTable;
        soundObj->value = 3;
    }
#undef sNullSoundTag
#undef sNullSoundVTable
}

int fn_802092C8(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

int fn_80209308(void) { return 1; }

extern int fn_802E2C20(void);
/* RealName: SoundTimer_Start — begins/restarts a sound timer: record the current
 * millisecond count (kernel clock fn_802E2C20) as its start time (+4) and set
 * the state to running (1) at +8. This layout is shared by the nearby timer helpers. */
void fn_80209310(void *timer) {
#define startTime ((int *)((char *)timer + 4))
#define state ((int *)((char *)timer + 8))
    *startTime = fn_802E2C20();
    *state = 1;
#undef state
#undef startTime
}

void fn_80209348(void *timer) {
#define startTime ((int *)((char *)timer + 4))
#define state ((int *)((char *)timer + 8))
    /* Initialize a timed object: record the current time as its start and set its state to 1 (running). */
    *startTime = fn_802E2C20();
    *state = 1;
#undef startTime
#undef state
}

void fn_80209380(void *timer) {
    /* Mark a timed object as expired by setting its state field (+8) to 3. */
#define state ((int *)((char *)timer + 8))
    *state = 3;
#undef state
}

void fn_8020938C(void *timer) {
    /* Set the timed object's state field (+8) to 2 (the stopped/paused state,
     * distinct from 1 = running and 3 = expired used by the neighbouring helpers). */
#define state ((int *)((char *)timer + 8))
    *state = 2;
#undef state
}

void fn_80209398(void *timer) {
    /* Set a sound timer's state field (+8) to 1 (running). */
#define state ((int *)((char *)timer + 8))
    *state = 1;
#undef state
}

int fn_802093A4(void *arg0) {
    /* If 2000ms elapsed since start, mark the timed object as expired; return its state. */
#define startTime ((int *)((char *)arg0 + 4))
#define state ((int *)((char *)arg0 + 8))
    if (*startTime + 0x7D0 < fn_802E2C20()) {
        *state = 3;
    }
    return *state;
#undef startTime
#undef state
}

void fn_802093EC(void) {

}

void fn_802093F0(void) {

}

void fn_802093F4(void) {

}

void fn_802093F8(void) {

}

int fn_802093FC(void) {
    return 0;
}

void fn_80209404(void) {

}

void fn_80209408(void) {

}

void fn_8020940C(void) {

}
extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];
