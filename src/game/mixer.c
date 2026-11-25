// mixer — sound mixer incl. null backend ("Null Mixer", "mixer: ...").
// Recovered TU window 0x80208A18..0x80209410+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_80209410 (+ .ctors slot 0x802ED380) remains in
// auto/text_80209410_.c pending a promotion pass.
#include "revolution/SC/scapi.h" /* SCSoundMode: the console sound mode */
extern char lbl_8033BF18[];
extern char lbl_8033C058[];
extern char lbl_8055B4F0;
extern void *lbl_8055B4D8;
extern int lbl_8055B4DC;
extern char lbl_8055B4E8;
extern void *fn_801284F8(int, void *);
extern void fn_8000DBC8(void *);
extern int ConfigGetSCSoundMode(void); /* config.c: the cached SCSoundMode */
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
extern void UpdateMasterVolume(float *);

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
extern void LoadFloatOption(int, void *, float *);
extern void fn_8013323C(int, void *, float);
extern void LoadIntOptionValue(int, void *, void *);
extern void SetEffectsVolume(float);
extern void SetSoundQuality(int);
#pragma scheduling invalid_target
#pragma push
#pragma inline_depth(0)
/* Return the input volume scaled by the stored volume of every active mixer
 * volume handle: MIXER_VOLUME_HANDLE_COUNT slots are in use out of at most
 * MIXER_VOLUME_HANDLE_MAX, and a slot contributes only when its name pointer is set. */
float fn_80208A18(float baseVolume) {
    struct MixerVolumeHandle *handles = MIXER_VOLUME_HANDLES;
    int count = MIXER_VOLUME_HANDLE_COUNT;
    int i;

    for (i = 0; i < count; i++) {
        if (handles[i].name != 0) {
            baseVolume *= handles[i].volume;
        }
    }
    return baseVolume;
}

#define baseEffectsVolume lbl_8055B4D0
#define effectiveMasterVolume lbl_8055B4D4
#define applyVolumeHandles fn_80208A18
/* Recompute the effective master volume: start from the configured effects volume,
   scale it by every active mixer volume handle, and store the result. The pointer
   argument is vestigial — callers pass a handle's volume but the body ignores it. */
/* Recompute the effective master volume from the base effects volume and all active mixer volume handles; the pointer argument is unused. */ void UpdateMasterVolume(float *unusedVolume) {
    effectiveMasterVolume = applyVolumeHandles(baseEffectsVolume);
}
#undef baseEffectsVolume
#undef effectiveMasterVolume
#undef applyVolumeHandles

void ReloadMixerSettings(void) {
    /* Reload the saved [SOUND] "effects_volume" and "quality" options and apply them. */
#define CONFIG_KEY_EFFECTS_VOLUME lbl_8033BEF8
#define CONFIG_KEY_QUALITY lbl_8055B4E0
#define OPTIONS_SECTION_SOUND 4
#define gEffectsVolume lbl_8055B4D0
    LoadFloatOption(OPTIONS_SECTION_SOUND, CONFIG_KEY_EFFECTS_VOLUME, &gEffectsVolume);
    SetEffectsVolume(gEffectsVolume);
    LoadIntOptionValue(OPTIONS_SECTION_SOUND, &CONFIG_KEY_QUALITY, &gSoundQuality);
    SetSoundQuality((int)gSoundQuality);
#undef gEffectsVolume
#undef OPTIONS_SECTION_SOUND
#undef CONFIG_KEY_QUALITY
#undef CONFIG_KEY_EFFECTS_VOLUME
}

#pragma pop

/* Identity-event callback: keeps the player-specific "player_sfx_vol" setting in sync
 * with the global "effects_volume".  Event 0 resets effects volume to the default,
 * event 3 loads the player's value into effects, events 1/2 copy effects back to the player. */
void fn_80208AC8(int playerSlot, int event) {
#define CONFIG_KEY_EFFECTS_VOLUME lbl_8033BEF8
#define CONFIG_KEY_PLAYER_SFX_VOL lbl_8033BF08
#define OPTIONS_SECTION_SOUND     4
    float volume = 1.0f;
    switch (event) {
    case 3:
        LoadFloatOption(playerSlot + 12, CONFIG_KEY_PLAYER_SFX_VOL, &volume);
        fn_8013323C(OPTIONS_SECTION_SOUND, CONFIG_KEY_EFFECTS_VOLUME, volume);
        SetEffectsVolume(volume);
        break;
    case 1:
    case 2:
        LoadFloatOption(OPTIONS_SECTION_SOUND, CONFIG_KEY_EFFECTS_VOLUME, &volume);
        fn_8013323C(playerSlot + 12, CONFIG_KEY_PLAYER_SFX_VOL, volume);
        break;
    case 0:
        fn_8013323C(OPTIONS_SECTION_SOUND, CONFIG_KEY_EFFECTS_VOLUME, volume);
        SetEffectsVolume(volume);
        break;
    }
#undef CONFIG_KEY_EFFECTS_VOLUME
#undef CONFIG_KEY_PLAYER_SFX_VOL
#undef OPTIONS_SECTION_SOUND
}

/* Names the mixer start-up works with.  The device registry (lbl_80489238) is
 * MIXER_DEVICE_MAX device pointers, the number registered at +0x18 and the
 * selected device at +0x1C; the selected device doubles as the "mixer" option,
 * so the options module reads and writes that field directly. */
#define gSoundMode (*(int *)&lbl_8055B4D8)     /* the sound mode the mixer runs in */
#define NULL_MIXER_NAME lbl_8033BF18           /* "Null Mixer": operator-new tag */
#define NULL_MIXER_VTABLE lbl_8033C058         /* the null backend's vtable */
#define CONFIG_KEY_MIXER lbl_8055B4E8          /* "mixer": the selected device */
#define CONFIG_KEY_EFFECTS_VOLUME lbl_8033BEF8 /* "effects_volume" */
#define CONFIG_KEY_QUALITY lbl_8055B4E0          /* "quality": the sound quality */
#define DEFAULT_EFFECTS_VOLUME lbl_80563230    /* 1.0f */
#define MIXER_CALLBACK_NAME lbl_8055B4F0       /* "Mixer": the reload hook's name */
#define gMixerReloadSlot lbl_8055B4DC          /* that hook's slot, freed on shutdown */
#define MIXER_SELECTED_OFFSET 0x1C             /* registry field holding the index */
#define OPTIONS_SECTION_SOUND 4                /* the [SOUND] options section */

#pragma push
#pragma inline_depth(0)
/* Initialize the sound subsystem: publish the configured sound mode, optionally
 * allocate and register a null mixer backend, load saved mixer settings, register
 * the settings-reload callback, and install the identity-event handler. */
void fn_80208B8C(int initBackends) {
    int soundMode = (int)ConfigGetSCSoundMode(); /* ConfigGetSoundMode() */
    switch (soundMode) {
    default: /* anything the config block holds besides mono and surround */
    case SC_SND_STEREO:
        gSoundMode = SC_SND_STEREO;
        break;
    case SC_SND_SURROUND:
        gSoundMode = SC_SND_SURROUND;
        break;
    case SC_SND_MONO:
        gSoundMode = SC_SND_MONO;
        break;
    }
    MIXER_VOLUME_HANDLE_COUNT = 0; /* no volume handles yet */
    if (initBackends != 0) {
        void *nullMixer;
        int *registry; /* devices[MIXER_DEVICE_MAX], count, selected index */
        int count;

        memset((void *)MIXER_DEVICES, 0, 0x20);
        nullMixer = fn_801284F8(0x10, NULL_MIXER_NAME);
        if (nullMixer != 0) {
            *(void **)nullMixer = NULL_MIXER_VTABLE;
            memset((char *)nullMixer + 4, 0, 0xC);
        }
        registry = (int *)MIXER_DEVICES;
        registry[registry[MIXER_DEVICE_MAX]] = (int)nullMixer;
        count = registry[MIXER_DEVICE_MAX];
        registry[MIXER_DEVICE_MAX] = count + 1;
        fn_8020A72C(); /* create the voice mixer and register it */
    }
    {
        int *registry = (int *)MIXER_DEVICES;
        int selected;

        LoadIntOptionValue(OPTIONS_SECTION_SOUND, &CONFIG_KEY_MIXER,
                    (char *)registry + MIXER_SELECTED_OFFSET);
        selected = registry[MIXER_DEVICE_MAX + 1];
        if (selected < 0 || selected >= registry[MIXER_DEVICE_MAX])
            *(int *)((char *)MIXER_DEVICES + MIXER_SELECTED_OFFSET) = 0; /* null mixer */
    }
    fn_8013323C(OPTIONS_SECTION_SOUND, CONFIG_KEY_EFFECTS_VOLUME, DEFAULT_EFFECTS_VOLUME);
    ReloadMixerSettings();
    gMixerReloadSlot = fn_8013365C((int)&MIXER_CALLBACK_NAME, (int)ReloadMixerSettings);
    fn_8000DBC8((void *)fn_80208AC8);
}
#pragma pop
/* CodeWarrior deleting-destructor helper: when deleteFlag > 0, free a non-null object via operator delete (fn_80128668), then return the object. */ /* CodeWarrior deleting-destructor helper: when deleteFlag > 0, free a non-null object via operator delete (fn_80128668), then return the object. */ int fn_80208CFC(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Return the number of registered sound devices in the mixer registry. */
/* Return the number of registered sound devices in the mixer registry. */ int GetMixerDeviceCount(void) { return MIXER_DEVICE_COUNT; }

int GetMixerDevice(int index) {
    /* Return the sound-device handle registered at the given slot of the mixer
     * device registry; its vtable getName sits at +0xC. */
    return MIXER_DEVICES[index];
}

/* Set the index of the currently selected mixer device. */
/* Select the active mixer backend by its index in the device registry (0 = null mixer); this field doubles as the saved "mixer" config option. */ void SetSelectedMixerDevice(int deviceIndex) { MIXER_SELECTED_DEVICE = deviceIndex; }

/* Return the index of the currently selected mixer device. */
/* Return the index of the currently selected mixer device. */ int GetSelectedMixerDevice(void) { return MIXER_SELECTED_DEVICE; }

extern const char lbl_8033BF28[];
extern char lbl_8055B4E8;
extern int lbl_8055B4DC;
extern void Abend_Panic(const char *, ...);
extern void fn_80133348(int, void *, int);
extern void fn_801336E0(int, void (*)(void));
#pragma scheduling default
#pragma cplusplus on
extern "C" const char lbl_8033BF28[];
extern "C" char lbl_8055B4E8;
extern "C" int lbl_8055B4DC;
extern "C" void Abend_Panic(const char *, ...);
extern "C" void fn_80133348(int, void *, int);
extern "C" void fn_801336E0(int, void (*)(void));
#pragma cplusplus reset
#pragma scheduling default
#pragma cplusplus on
extern "C" void fn_80208D80(int closeDevices) {
    /* Mixer shutdown: warn about volume handles still held, optionally close
     * every registered sound device, then persist the selected device ("mixer"),
     * effects volume and sound quality ("quality") to config and re-register the
     * settings-reload callback. */
    void **deviceIt;
    void *device;
    char *handleIt = lbl_80489258;
    int handleName;
    int i = 0;
    int j;

    while (i < MIXER_VOLUME_HANDLE_COUNT) {
        handleName = *(int *)(handleIt + 4);
        if (handleName != 0) {
            Abend_Panic(lbl_8033BF28, handleName);
        }
        handleIt += 8;
        i++;
    }

    if (closeDevices != 0) {
        deviceIt = (void **)MIXER_DEVICES;
        j = 0;
        while (j < MIXER_DEVICE_COUNT) {
            device = *deviceIt;
            if (device != 0) {
                struct SoundDevice {
                    virtual void close(int);
                };
                ((struct SoundDevice *)device)->close(1);
            }
            deviceIt++;
            j++;
        }
    }

    fn_80133348(OPTIONS_SECTION_SOUND, &CONFIG_KEY_MIXER, MIXER_SELECTED_DEVICE);
    fn_8013323C(OPTIONS_SECTION_SOUND, CONFIG_KEY_EFFECTS_VOLUME, lbl_8055B4D0);
    fn_80133348(OPTIONS_SECTION_SOUND, &CONFIG_KEY_QUALITY, (int)gSoundQuality);
    fn_801336E0(gMixerReloadSlot, ReloadMixerSettings);
}

#pragma cplusplus on
extern "C" int strncmp(const char *, const char *, unsigned int);
extern "C" void fn_802E30C8(const char *, ...);
/* RealName: Mixer_RegisterDevice — add one sound-mixer backend ("Null Mixer",
   "Voice Mixer", ...) to the mixer's device registry, which holds at most
   MIXER_DEVICE_MAX (6) device pointers at lbl_80489238 (+0x18 is the count).
   A device whose name matches the hard-coded bogus name, and any device past
   the 6th, is refused with a message and destroyed.  mode 0 registers the
   device as it stands; mode 1 registers it only if its startup method (+0x18)
   succeeds, and immediately runs its shutdown method (+0x24) again. */
extern "C" void fn_80208E90(void *devicePtr, int mode) {
    /* Sound-mixer backend interface.  CodeWarrior reserves the first two vtable
       slots for the deleting and complete destructors, so the first method
       declared here lands at +0x8; the two backends in the game implement this
       table ("Null Mixer" lbl_8033C058, "Voice Mixer" gVoiceMixerVtable). */
    struct MixerDevice {
        virtual void close(int deleteObject);  /* 0x8 deleting destructor */
        virtual const char *name();            /* 0xC backend name */
        virtual void reset();                  /* 0x10 clear the backend's voice state */
        virtual int method14();                /* 0x14 */
        virtual int begin();                   /* 0x18 start the backend, 1 on success */
        virtual void *createSound();           /* 0x1C allocate a Sound from this backend */
        virtual void update();                 /* 0x20 per-frame tick */
        virtual void end();                    /* 0x24 shut the backend down */
    };
    MixerDevice *device = (MixerDevice *)devicePtr;
    const char *messages = lbl_8033BEF8; /* string pool; the registry messages sit past the config keys */
    int registerDevice;
    unsigned int count;

    if (strncmp(device->name(), messages + MIXER_BOGUS_NAME_OFF, 0xB) == 0) {
        fn_802E30C8(messages + MIXER_BOGUS_MSG_OFF, device->name());
        if (devicePtr != 0) {
            device->close(1);
        }
    } else {
        count = (unsigned int)MIXER_DEVICE_COUNT;
        if (count < MIXER_DEVICE_MAX) {
            registerDevice = mode == 0;
            if (mode == 1 && device->begin() != 0) {
                registerDevice = 1;
                device->end();
            }
            if (registerDevice != 0) {
                MIXER_DEVICES[MIXER_DEVICE_COUNT++] = (int)devicePtr;
            } else if (devicePtr != 0) {
                device->close(1);
            }
        } else {
            fn_802E30C8(messages + MIXER_FULL_MSG_OFF, device->name());
            if (devicePtr != 0) {
                device->close(1);
            }
        }
    }
}
#pragma cplusplus reset

#pragma cplusplus reset
/* Return the effective master volume (relative to the configured effects volume), recomputed by UpdateMasterVolume from the active mixer volume handles. */
float fn_80209028(void) {
    return lbl_8055B4D4;
}

#pragma cplusplus on
#define gEffectsVolume lbl_8055B4D0
#define MIN_EFFECTS_VOLUME lbl_80563234
#define CONFIG_KEY_EFFECTS_VOLUME lbl_8033BEF8
void SetEffectsVolume(float volume) {
    /* Clamp the effects volume to [0,1], publish it to config under "effects_volume", then recompute the effective master volume. */
    float clamped = 1.0f < volume ? 1.0f : volume;
    clamped = clamped > MIN_EFFECTS_VOLUME ? clamped : MIN_EFFECTS_VOLUME;
    gEffectsVolume = clamped;
    fn_8013323C(4, CONFIG_KEY_EFFECTS_VOLUME, (float)(double)clamped);
    ((void (*)(void))UpdateMasterVolume)();
}
#undef CONFIG_KEY_EFFECTS_VOLUME
#undef MIN_EFFECTS_VOLUME
#undef gEffectsVolume
#pragma cplusplus reset
/* Set the sound-quality setting (config "quality"): accept values 0..2, reset to low otherwise. */
/* Set the sound-quality setting (config "quality"): values 0..2 are accepted, anything else resets it to low. */ void SetSoundQuality(int quality) {
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
/* Null mixer's sound-mode setter: does nothing but log that the requested sound mode is ignored. */
void NullMixerSetSoundMode(void) {
    fn_802E30C8(MIXER_SET_SOUND_MODE_NOOP_MSG);
}
#undef MIXER_SET_SOUND_MODE_NOOP_MSG
extern void *lbl_8055B4D8;
/* Get the configured sound mode (0/1/2, set in fn_80208B8C from config). */
void* fn_802090CC(void) {
    return lbl_8055B4D8;
}

/* Open a mixer volume handle for `name`, initialized to full volume (1.0f);
 * return the new handle, or NULL when all MIXER_VOLUME_HANDLE_MAX slots are in
 * use. */
void *fn_802090D4(int name) {
    struct MixerVolumeHandle *table = MIXER_VOLUME_HANDLES;
    int slotIndex = MIXER_VOLUME_HANDLE_COUNT;
    void *handle;
    handle = 0;
    if (((unsigned int)MIXER_VOLUME_HANDLE_COUNT) < MIXER_VOLUME_HANDLE_MAX) {
        MIXER_VOLUME_HANDLE_COUNT = MIXER_VOLUME_HANDLE_COUNT + 1;
        handle = (char *)table + slotIndex * 8;
        *(int *)((char *)handle + 4) = name;
        *(float *)((char *)table + slotIndex * 8) = lbl_80563230;
    }
    return handle;
}

#pragma push
#pragma inline_depth(0)
#pragma scheduling invalid_target
/* Releases a volume handle: frees its slot (dropping free slots from the end
 * of the table), recomputes the master volume and clears the caller's pointer
 * so releasing it twice does nothing. */
/* Release a mixer volume handle: free its table slot, drop unused slots from the end, recompute the effective master volume, and null the caller's pointer so double-release is a no-op. */ void fn_80209110(void **handle) {
    if (*handle != 0) {
        ((struct MixerVolumeHandle *)*handle)->name = 0;
        while (MIXER_VOLUME_HANDLE_COUNT > 0) {
            if (MIXER_VOLUME_HANDLES[MIXER_VOLUME_HANDLE_COUNT - 1].name != 0)
                break;
            MIXER_VOLUME_HANDLE_COUNT = MIXER_VOLUME_HANDLE_COUNT - 1;
        }
        ((void (*)(void))UpdateMasterVolume)();
        *handle = 0;
    }
}
#pragma scheduling on
#pragma pop

#pragma push
#pragma inline_depth(0)
void fn_80209190(float *handleVolume, float volume) {
#define MAX_VOLUME lbl_80563230  /* 1.0f */
#define MIN_VOLUME lbl_80563234  /* 0.0f */
    /* Clamp a mixer volume handle's level to [0,1], store it, and recompute
     * the effective master volume. */
    if (handleVolume != 0) {
        float clampedVolume = MAX_VOLUME < volume ? MAX_VOLUME : volume;
        clampedVolume = clampedVolume > MIN_VOLUME ? clampedVolume : MIN_VOLUME;
        *handleVolume = clampedVolume;
        UpdateMasterVolume(handleVolume);
    }
#undef MIN_VOLUME
#undef MAX_VOLUME
}
#pragma pop

extern float lbl_80563230;
extern float lbl_80563234;
extern float fn_80208A18(float);
extern void UpdateMasterVolume(float *);
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

/* CodeWarrior deleting-destructor helper: free a non-null object via operator delete when deleting, then return the object. */
int fn_802091D4(int object, int deleteFlag) {
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
extern void LoadIntOptionValue(int, void *, void *);
#pragma scheduling on
int fn_8020921C(void) {
    struct Config { int pad; int value; volatile unsigned int version; };
    extern struct Config lbl_8048929C;
    extern unsigned int lbl_8055E044;
    extern void fn_80131318(void);
    struct Config *c = &lbl_8048929C;
    if (c->version != lbl_8055E044)
        fn_80131318();
    return lbl_8048929C.value;
}
/* Trivial mixer helper: returns the supplied value advanced by 4. */
int fn_80209260(int value) { return value + 4; }

/* Trivial mixer helper: always reports 1 (boolean true / success). Identical to fn_80209270. */
int fn_80209268(void) { return 1; }

/* Null-backend virtual stub: always reports true (1). */
int fn_80209270(void) { return 1; }

/* Null-mixer backend device method, slot +0x20 of the Null Mixer vtable
 * (lbl_8033C058), just past its createSound (+0x1C, Sound_CreateNullSource
 * SoundCreateNullSource).  Slot +0x20 is the mixer's per-frame tick -- the voice backend
 * implements it as fn_8020AC2C, which walks its sound list and updates every
 * playing sound.  The null backend has no sounds and no hardware to act on, so
 * this method does nothing; fn_8020927C is the same no-op for slot +0x24
 * (the voice backend's shutdown/release-all, fn_8020A8E8). */
void fn_80209278(void) {
	return;
}

/* Null Mixer device method, slot +0x24 of the "Null Mixer" vtable (lbl_8033C058).
 * The voice backend's slot +0x24 (fn_8020A8E8) reports every sound still left in
 * its 512-entry sound list at shutdown and frees that list; the null backend
 * allocates no list and has no hardware to stop, so there is nothing to release. */
void fn_8020927C(void) {

}

extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];
/* Allocate a 12-byte "Null Sound" object: on success install its vtable and set value 3. */
void SoundCreateNullSource(void) {
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

/* CodeWarrior deleting-destructor (D0) thunk: when the delete flag is positive,
 * free a non-null object through operator delete (fn_80128668), then return the
 * object pointer. */
int fn_802092C8(int object, int deleteFlag) {
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Trivial mixer helper: always reports 1 (boolean true / success). */
int fn_80209308(void) { return 1; }

extern int KERNEL_GetTimeMs(void);
/* RealName: SoundTimer_Start — begins/restarts a sound timer: record the current
 * millisecond count (kernel clock KERNEL_GetTimeMs) as its start time (+4) and set
 * the state to running (1) at +8. This layout is shared by the nearby timer helpers. */
/* SoundTimer_Start: begin/restart a sound timer by stamping its start time at +4 with the kernel millisecond clock (KERNEL_GetTimeMs) and setting its state to running (1) at +8. */ void fn_80209310(void *timer) {
#define startTime ((int *)((char *)timer + 4))
#define state ((int *)((char *)timer + 8))
    *startTime = KERNEL_GetTimeMs();
    *state = 1;
#undef state
#undef startTime
}

/* Start/restart a sound timer (same layout as fn_80209310 and the checker fn_802093A4): stamp the start time at +4 with KERNEL_GetTimeMs and set the state to running (1) at +8. */ void fn_80209348(void *timer) {
#define startTime ((int *)((char *)timer + 4))
#define state ((int *)((char *)timer + 8))
    /* Initialize a timed object: record the current time as its start and set its state to 1 (running). */
    *startTime = KERNEL_GetTimeMs();
    *state = 1;
#undef startTime
#undef state
}

void SoundTimer_Expire(void *timer) {
    /* Expire a sound timer: mark its state word at +8 as expired (3). */
    *(int *)((char *)timer + 8) = 3;
}

void SoundTimer_Stop(void *timer) {
    /* Pause a sound timer by setting its state word (+8) to 2. */
    *((int *)((char *)timer + 8)) = 2;
}

void SoundTimer_SetRunning(void *timer) {
    /* Start a sound timer running: set its state word at +8 to 1 (running). */
    *(int *)((char *)timer + 8) = 1;
}

int fn_802093A4(void *timer) {
    /* Sound-timer check: if 2000 ms have passed since its start time, expire it (state 3); return its state. */
#define startTime ((int *)((char *)timer + 4))
#define state ((int *)((char *)timer + 8))
    if (*startTime + 0x7D0 < KERNEL_GetTimeMs()) {
        *state = 3;
    }
    return *state;
#undef startTime
#undef state
}

/* The rest of the "Null Sound" vtable (lbl_8033C0E8): the sound's control methods.
 * A null sound is bookkeeping only -- a state word and a timer -- so every control
 * the voice backend (vtable lbl_8033C3F4) implements on its VoiceSnd does nothing
 * here.  Each stub below is marked with its vtable slot and the voice backend's
 * method for that slot. */
void fn_802093EC(void) { /* +0x30 set rate    (voice: fn_8020BC50, VoiceSnd+0x24) */

}

/* +0x3C set pan: the voice backend (fn_8020BC68) stores it in VoiceSnd+0x20, which
 * its mixer tick then splits between the two channels; a null sound has no
 * channels to place, so it ignores the value. */
void fn_802093F0(void) {

}

/* Null Sound method, slot +0x40 of the "Null Sound" vtable (lbl_8033C0E8): set the
 * sound's surround pan.  The voice backend's slot +0x40 (fn_8020BC70) stores it in
 * VoiceSnd+0x28, which its mixer tick hands to the voice's surround-pan setter; a
 * null sound has no voice to hand it to, so it ignores the value. */
void fn_802093F4(void) {

}

/* Null Sound method, slot +0x34 of the "Null Sound" vtable (lbl_8033C0E8): set the
 * sound's volume.  The voice backend's slot +0x34 (fn_8020BC58) stores it in
 * VoiceSnd+0x1C, which its mixer tick multiplies with the sound group's volume to
 * get the voice gain; a null sound plays nothing, so it ignores the value. */
void fn_802093F8(void) {

}

/* +0x38 a sound query the voice backend answers "no" to as well (fn_8020BC60). */
int fn_802093FC(void) {
    return 0;
}

/* "Null Sound" (the null mixer backend's Sound object, vtable lbl_8033C0E8),
 * vtable slot +0x54 Set3D: hand the sound its 3D placement.  A null sound is
 * bookkeeping only -- a vtable, a timer and a state word -- so there is no
 * position to store.  The voice backend never implemented the method either:
 * its SndVoice slot +0x54 (SndVoice_Set3D) only reports "SndVoice::Set3D", while
 * the null backend does not even report. */
void fn_80209404(void) {

}

/* "Null Sound" (the null mixer backend's Sound object, vtable lbl_8033C0E8),
 * vtable slot +0x58: the Sound interface method between Set3D (+0x54) and
 * setParam (+0x5C).  No recovered game code calls it through a sound, and the
 * voice backend's SndVoice leaves the same slot empty as well (fn_8020BCB0),
 * so the null sound has nothing to do here either. */
void fn_80209408(void) {

}

/* "Null Sound" (the null mixer backend's Sound object, vtable lbl_8033C0E8),
 * vtable slot +0x5C setParam: take the parameter block a Sound3D queued at
 * Sound3D+0x50.  Sound3D::update (fn_80206824) hands it over once and clears
 * the queue.  A null sound has no mix parameters to receive, and the voice
 * backend's SndVoice slot +0x5C (fn_8020BCB4) ignores the block as well. */
void fn_8020940C(void *paramBlock) {

}
extern void *fn_801284F8(int, void *);
extern char lbl_8033C1C0[];
extern char lbl_8033C0E8[];
