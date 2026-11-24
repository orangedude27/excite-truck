// voicesnd — voice sounds (SndVoice::Set3D, VoiceSoundMixer, sounds.val).
// Recovered TU window 0x8020A6AC..0x8020BCB8+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_8020BCB8 (+ .ctors slot 0x802ED390) remains in
// auto/text_8020BCB8_.c pending a promotion pass.
extern void *fn_802E6058(int);
extern void fn_802E6ABC(int);
extern void fn_80207938(void);
extern void fn_802E61BC(void *);
extern void fn_802E61A8(void *);
extern const char lbl_8033C3D8[], lbl_8033C3E4[], lbl_8033C4A0[], lbl_8033C4C8[];
extern char lbl_8033C3F4[];
__declspec(section ".sdata") extern const char lbl_8055B5B8[], lbl_8055B5C0[];
extern float lbl_805632BC, lbl_805632C0, lbl_805632C4;
extern void *fn_802E5AE8(void *);
extern float fn_802E6040(void *);
extern void fn_802E30C8(const char *, ...);
extern char *strchr(const char *, int);
extern void fn_802E317C(const char *, ...);
extern const char lbl_8033C510[];
extern void fn_802E61E4(float);
extern float fn_80209028(void), fn_802091CC(void);
extern int fn_802090CC(void), fn_802E2C20(void);
extern void fn_802E625C(int);
extern void fn_802E61EC(void *, float), fn_802E620C(void *, float), fn_802E6234(void *, float), fn_802E6238(void *, float), fn_802E623C(void *, float), fn_802E622C(void *, float), fn_802E6240(void *, int);
__declspec(section ".data") extern float lbl_80558DC4;
extern float lbl_8055B590, lbl_8055B594, lbl_805632B8;
extern int lbl_8055EDF8;
extern unsigned int lbl_8055EE00;

extern void fn_802E6264(void);
extern void fn_802E5D5C(void *);
extern void fn_8020B2BC(void *, int, int);
extern int lbl_8055EE0C;
extern void *lbl_8055EE10;
extern char lbl_8033C35C[];
extern char lbl_8033C338[];
extern int stricmp(const char *, const char *);
extern char lbl_8033C368[];
extern char lbl_804892D0[];
extern int fn_801284F8(int, void *);
extern void *fn_8012A13C(void *, int, int);
extern int fn_8012A2D8(void *);
extern int fn_8012A364(void *, void *);
extern void *fn_8012850C(unsigned int, void *);
extern void *memset(void *, int, unsigned int);
  extern void fn_802E6B04(void);
      extern char lbl_8033C388[];
    #define kUnfreedSoundFmt lbl_8033C388
    extern void fn_802E6B34(void);
  typedef struct { void **vtable; } Unk8012A570;
    extern void fn_8020A860();
  extern int fn_80208E90(int);
  extern float lbl_805632B0, lbl_805632B4, lbl_8055B598;

  extern void *lbl_8055EE04;
#define gVoiceMixerInstance lbl_8055EE04
extern char lbl_8033C37C[];
extern void *lbl_8055EE08;
extern unsigned char lbl_8033C520[];
extern unsigned char lbl_80489BD0[];
extern int fn_80128668(void);
extern char lbl_8033C458[];
typedef struct { char *callbacks; int state; } VoiceMixerDevice;
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma scheduling invalid_target
/* Find a 0x24-byte voice entry in lbl_804892D0 by name (case-insensitive); return its pointer or a default label. */
void *fn_8020A6AC(void *name) {
    char *entry = lbl_804892D0;
    int index = 0;
    while (index < (int)lbl_8055EE08) {
        if (stricmp((const char *)name, entry) == 0)
            return entry;
        entry += 0x24;
        index++;
    }
    return lbl_8033C338;
}
#pragma scheduling on
#pragma dont_inline reset

void fn_8020A72C(void) {
    /* Create the voice-sound mixer object and register it as a sound device. */
    void *mixer = (void *)fn_801284F8(0xC, lbl_8033C35C);
    if (mixer != 0)
        mixer = ((void *(*)(void *))fn_8020A860)(mixer);
    ((int (*)(void *, int))fn_80208E90)(mixer, 0);
}
#pragma scheduling on
/* Return s_voiceEntryCount (lbl_8055EE08), the number of registered 0x24-byte voice-sound entries. */
void* fn_8020A76C(void) {
    return lbl_8055EE08;
}

void *fn_8020A774(int index) {
    /* Return a pointer to the 0x24-byte voice-sound entry at the given index in lbl_804892D0. */
    return lbl_804892D0 + index * 0x24;
}

int fn_8020A788(void) {
    /* Lazily create/initialize the shared voice-sound pool object, then increment the active-use count on success. */
    void *voicePool;
    int initialized;

    if (lbl_8055EE0C == 0) {
        voicePool = (void *)fn_801284F8(0x20, lbl_8033C368);
        if (voicePool != 0) {
            voicePool = ((void *(*)(void *, void *, int, int))fn_8012A13C)(voicePool, lbl_8033C368, 0x200, 0x54);
        }
        lbl_8055EE10 = voicePool;
    }

    initialized = fn_8012A2D8(lbl_8055EE10);
    if (initialized != 0) {
        lbl_8055EE0C += 1;
    }
    return initialized;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020A800(void *voiceSound) {
    /* Return a voice sound to the shared pool and, when the last user is gone,
     * delete the pool object (virtual destructor, deleting) and clear it. */
    class PoolObject {
    public:
        virtual void dtor(int shouldDelete);
    };
    fn_8012A364(lbl_8055EE10, voiceSound);
    if (--lbl_8055EE0C == 0) {
        if (lbl_8055EE10 != 0)
            ((PoolObject *)lbl_8055EE10)->dtor(1);
        lbl_8055EE10 = 0;
    }
}
#pragma cplusplus reset
#pragma pop

#pragma scheduling invalid_target
void fn_8020A860(VoiceMixerDevice *mixer) {
    /* Voice-mixer device constructor: install the callback table and clear the state word. */
    mixer->callbacks = lbl_8033C458;
    mixer->state = 0;
}

#pragma scheduling invalid_target
int fn_8020A878(void *arg0) {
    // Initialize voice mixer: pick scale, store mixer instance, allocate/clear 0x800-byte work buffer, then start mixer init.
    void *workBuffer;

    #define gVoiceScale lbl_8055B598
    #define gVoiceScaleAltA lbl_805632B0
    #define gVoiceScaleAltB lbl_805632B4
    #define gActiveVoiceMixer lbl_8055EE04
    #define kVoiceWorkBufferSize 0x800

    if (fn_80019B60() != 0) {
        gVoiceScale = gVoiceScaleAltA;
    } else {
        gVoiceScale = gVoiceScaleAltB;
    }
    gActiveVoiceMixer = arg0;
    workBuffer = fn_8012850C(kVoiceWorkBufferSize, lbl_8033C37C);
    *(void **)((char *)arg0 + 4) = workBuffer;
    memset(workBuffer, 0, kVoiceWorkBufferSize);
    fn_802E6B04();
    return 1;

    #undef gVoiceScale
    #undef gVoiceScaleAltA
    #undef gVoiceScaleAltB
    #undef gActiveVoiceMixer
    #undef kVoiceWorkBufferSize
}
#pragma scheduling on
/* VoiceSoundMixer::End: call the SPU teardown hook, warn about any still-unfreed sound handles in the 0x200-entry work buffer at +4, free that buffer, clear its slot and the global mixer instance. */ /* VoiceSoundMixer::End: call the SPU teardown hook, warn about any still-unfreed sound handles in the 0x200-entry work buffer at +4, free that buffer, clear its slot and the global mixer instance. */ void fn_8020A8E8(void *mixer) {
    /* VoiceSoundMixer::End: warn about any still-unfreed sound handles in the
       0x200-entry work buffer, free it, clear its slot, and clear the mixer. */
    int slotOffset;
    int slotIndex;
    fn_802E6B34();
    slotIndex = 0;
    slotOffset = 0;
    while (slotIndex < 0x200) {
        int *handleBuffer = *(int **)((char *)mixer + 4);
        int unfreedHandle = *(int *)((char *)handleBuffer + slotOffset);
        if (unfreedHandle != 0) {
            fn_802E317C(kUnfreedSoundFmt, unfreedHandle);
        }
        slotIndex++;
        slotOffset += 4;
    }
    fn_80128670(*(void **)((char *)mixer + 4));
    *(int *)((char *)mixer + 4) = 0;
    gVoiceMixerInstance = 0;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020A978(void *arg0) {
    /* Stop every active voice sound in the mixer's 0x200-entry work buffer, then tick the SPU mixer. */
    class VoiceSndObj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void releaseVoices();
        virtual int getState();
    };
    register int slotOffset = 0;
    register int slotIndex = 0;
    VoiceSndObj *sound;

    do {
        sound = *(VoiceSndObj **)((char *)*(void **)((char *)arg0 + 4) + slotOffset);
        if (sound != 0) {
            if (sound->getState() != 3) {
                sound = *(VoiceSndObj **)((char *)*(void **)((char *)arg0 + 4) + slotOffset);
                sound->releaseVoices();
            }
        }
        slotIndex++;
        slotOffset += 4;
    } while (slotIndex < 0x200);
    fn_802E6264();
}
#pragma cplusplus reset
#pragma pop

#pragma scheduling on

extern void fn_802E59BC(void *);
extern void fn_802E5950(int, int);
extern void fn_802E6138(void);
extern void fn_802E61D8(void *);
void fn_8020AA0C(void *self) {
    /* VoiceSnd::releaseVoices — stop and release both AX voice handles, clear
       them, set state to stopped (3) and clear the mute flag. */
    struct VoiceSnd {
        void *vtable;        /* 0x00 */
        int state;           /* 0x04: 1 = playing, 2 = muted, 3 = stopped */
        int voice;           /* 0x08: main voice handle */
        int voice2;          /* 0x0C: second voice handle */
        char pad[0x2E];      /* 0x10..0x3D */
        unsigned char mute;  /* 0x3E */
    };
    struct VoiceSnd *snd = (struct VoiceSnd *)self;
    int handle = snd->voice;

    if (handle != 0) {
        fn_802E61D8((void *)handle);
        handle = snd->voice2;
        if (handle != 0) {
            fn_802E61D8((void *)handle);
        }
        handle = snd->voice2;
        if (handle != 0) {
            ((void (*)(void *))fn_802E6138)((void *)handle);
            snd->voice2 = 0;
        }
        handle = snd->voice;
        if (handle != 0) {
            ((void (*)(void *))fn_802E6138)((void *)handle);
            snd->voice = 0;
        }
    }
    snd->state = 3;
    snd->mute = 0;
}

/* Return a voice sound's effective state: a playing sound (1) whose mute flag
 * is set is reported as muted (2); otherwise its raw state is returned. */
int fn_8020AA98(void *arg0) {
    volatile int *state = (volatile int *)((char *)arg0 + 4);
    if (*state == 1 && *((unsigned char *)arg0 + 0x3E) != 0) return 2;
    return *state;
}

extern const char lbl_8033C3B4[];
extern const char lbl_8033C3C0[];
#include <macros.h>
DECL_SECTION(".sdata") extern const char lbl_8055B5A0[];
DECL_SECTION(".sdata") extern const char lbl_8055B5A8[];
DECL_SECTION(".sdata") extern const char lbl_8055B5B0[];
extern float lbl_805632B4;
extern void *fn_80131808(const char *);
extern void fn_80131818(void *);
extern void fn_802E58B8(int);
extern int strcmp(const char *, const char *);
#pragma push
#pragma cplusplus on
/* Load the value file, copy each "samples" entry's "name" and "volume" into consecutive 0x24-byte records, release the table, then queue the given resource directory. */ extern "C" void fn_8020AAC0(int unused, int directory) {
    struct List {
        virtual void dummy0();
        virtual void *getAt(int);
    };
    struct Entry {
        virtual const char *getName();
        virtual void dummy1();
        virtual void dummy2();
        virtual const char *getString(const char *, int);
        virtual void dummy4();
        virtual void dummy5();
        virtual void dummy6();
        virtual void dummy7();
        virtual float getValue(const char *, float);
    };
    char *records;
    List *list = (List *)fn_80131808(lbl_8033C3B4);
    if (list != 0) {
        records = lbl_804892D0;
        Entry *entry;
        int entryIndex = 0;
        /* Scans list entries named lbl_8055B5A0, copies their string/value into records, then finalizes. */
        while ((entry = (Entry *)list->getAt(entryIndex)) != 0) {
            const char *entryName = entry->getName();
            if (strcmp(entryName, lbl_8055B5A0) == 0) {
                int recordIndex = (int)lbl_8055EE08;
                char *record = records + recordIndex * 0x24;
                const char *source;
                lbl_8055EE08 = (void *)(recordIndex + 1);
                source = entry->getString(lbl_8055B5A8, recordIndex);
                {
                    int remaining = 0x20;
                    char *dest = record;
                    goto copy_check;
copy_loop:
                    if (--remaining > 0)
                        goto copy_check;
                    dest[-1] = 0;
                    goto copy_done;
copy_check:
                    {
                        unsigned char ch = *source++;
                        *dest++ = ch;
                        if ((signed char)ch != 0)
                            goto copy_loop;
                    }
copy_done:
                    ;
                }
                *((float *)(record + 0x20)) = entry->getValue(lbl_8055B5B0, lbl_805632B4);
            }
            ++entryIndex;
        }
        fn_80131818(list);
    } else {
        fn_802E317C(lbl_8033C3C0);
    }
    fn_802E58B8(directory);
}
#pragma cplusplus reset
#pragma pop
/* Voice-sound thunk: drop the unused object pointer and forward the directory
 * and file names to the path-building helper fn_802E5950. */
void fn_8020AC0C(int self, int dirName, int fileName) {
    fn_802E5950(dirName, fileName);
}

/* Voice-sound thunk: drop the unused object pointer and forward the SFX0
 * sound-directory name to fn_802E59BC to queue it for playback. */
void fn_8020AC18(void *self, int dirName) { fn_802E59BC((void *)dirName); }

extern void fn_802E5A54(void);
/* Voice-sound shutdown: clear the registered voice-entry count, then tear down
 * SPU state (fn_802E5A54). */
void fn_8020AC20(void) {
#define s_voiceEntryCount lbl_8055EE08
    s_voiceEntryCount = 0;
#undef s_voiceEntryCount
    fn_802E5A54();
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_8020AC2C(void *arg0) {
    class VoiceObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); };
    float low, high, volume, x, v;
    void *p;
    int i, j, mode, now;
    void *handle;
    int *slot = (int *)((char *)arg0 + 8);
    lbl_8055B590 = fn_80209028();
    lbl_8055B594 = fn_802091CC();
    lbl_8055EDF8++;
    now = fn_802E2C20();
    lbl_8055EE00 = now - *slot;
    if (lbl_8055EE00 > 200U) lbl_8055EE00 = 200;
    high = lbl_805632B4;
    low = lbl_805632B0;
    *slot = now;
    for (i = 0; i < 512; i++) {
        p = (*(void ***)((char *)(arg0) + (4)))[i];
        if (p) {
            mode = 1;
            switch (fn_802090CC()) {
            case 0: mode = 0; break;
            case 1: break;
            case 2: mode = 2; break;
            }
            fn_802E625C(mode);
            handle = (*(void **)((char *)(p) + (8)));
            if (handle) {
                v = (*(float *)((char *)(p) + (0x1c))) * (*(float *)((char *)((*(void **)((char *)(p) + (0x18)))) + (0x20)));
                if ((*(unsigned char *)((char *)(p) + (0x3e)))) {
                    volume = lbl_805632B0;
                } else {
                    v = (*(unsigned char *)((char *)(p) + (0x3c))) ? v : v * lbl_8055B590;
                    volume = lbl_8055B598 * v;
                }
                if ((*(void **)((char *)(p) + (0xc)))) {
                    x = high + -(*(float *)((char *)(p) + (0x20)));
                    if (high < x) x = high;
                    x = x > low ? x : low;
                    ((void (*)(void *, float))fn_802E61E4)(handle, volume * x);
                    fn_802E61EC((*(void **)((char *)(p) + (8))), lbl_805632B8);
                    x = high + (*(float *)((char *)(p) + (0x20)));
                    if (high < x) x = high;
                    x = x > low ? x : low;
                    ((void (*)(void *, float))fn_802E61E4)((*(void **)((char *)(p) + (0xc))), volume * x);
                    fn_802E61EC((*(void **)((char *)(p) + (0xc))), lbl_805632B4);
                } else {
                    ((void (*)(void *, float))fn_802E61E4)(handle, volume);
                    fn_802E61EC((*(void **)((char *)(p) + (8))), (*(float *)((char *)(p) + (0x20))));
                }
                for (j = 0; j < 2; j++) {
                    void *voice;
                    if (j == 0) voice = (*(void **)((char *)(p) + (8)));
                    else voice = (*(void **)((char *)(p) + (0xc)));
                    if (voice) {
                        fn_802E620C(voice, (*(float *)((char *)(p) + (0x28))));
                        fn_802E6234(voice, (*(float *)((char *)(p) + (0x2c))));
                        fn_802E6238(voice, (*(float *)((char *)(p) + (0x30))));
                        fn_802E623C(voice, (*(float *)((char *)(p) + (0x34))));
                        fn_802E622C(voice, (*(float *)((char *)(p) + (0x24))));
                        fn_802E6240(voice, (*(int *)((char *)(p) + (0x38))));
                    }
                }
            }
            if ((*(int *)((char *)(p) + (4))) == 1) {
                (*(int *)((char *)(p) + (0x44)))++;
                if (!(*(unsigned char *)((char *)(p) + (0x3e))) && !((float)__fabs((*(float *)((char *)(p) + (0x24)))) <= lbl_80558DC4)) (*(unsigned int *)((char *)(p) + (0x50))) += lbl_8055EE00;
                if (!(*(unsigned char *)((char *)(p) + (0x3d))) && (*(unsigned int *)((char *)(p) + (0x50))) > (*(unsigned int *)((char *)(p) + (0x4c))))
                    ((VoiceObj *)p)->v6();
            } else {
                (*(unsigned int *)((char *)(p) + (0x50))) = 0;
            }
        }
    }
    fn_802E6264();
}
#pragma cplusplus reset

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma cplusplus on
extern "C" void *fn_8020AF18(void *arg0, char *name, int unused, unsigned char flag) {
    class Sound { public: virtual void destroy(int); virtual void slot1(); virtual int valid(); };
    char *obj;
    int i;
    for (i = 0; i < 0x200; i++) {
        if (((void **)*(void **)((char *)arg0 + 4))[i] == 0) {
            obj = (char *)((void *(*)(int, const char *))fn_8020A788)(0x54, lbl_8033C3D8);
            if (obj != 0) {
                char buffer[64], *src, *dst, *dot;
                int left;
                double length;
                { float initial = lbl_805632B0;
                *(void **)obj = lbl_8033C3F4;
                *(float *)(obj + 0x48) = initial; }
                *(int *)(obj + 0x40) = i;
                *(int *)(obj + 0x44) = 0;
                *(int *)(obj + 4) = 3;
                *(int *)(obj + 0xc) = 0;
                *(int *)(obj + 8) = 0;
                *(int *)(obj + 0x14) = 0;
                *(int *)(obj + 0x10) = 0;
                *(unsigned char *)(obj + 0x3d) = 0;
                *(unsigned char *)(obj + 0x3e) = 0;
                *(unsigned char *)(obj + 0x3c) = flag;
                *(void **)(obj + 0x10) = fn_802E5AE8(name);
                if (*(void **)(obj + 0x10) != 0) {
                    { char *copy_src = name; int copy_left = 0x40; char *copy_dst = buffer;
                    goto copy_check;
copy_next:
                    if (--copy_left > 0) goto copy_check;
                    copy_dst[-1] = 0; goto copied;
copy_check:
                    { unsigned char c = *copy_src++; *copy_dst++ = c; if ((signed char)c != 0) goto copy_next; }
copied: ; }
                    dot = strchr(buffer, '.');
                    if (dot != 0) {
                        if (stricmp(dot, lbl_8055B5C0) != 0) fn_802E317C(lbl_8033C4C8, name);
                        *dot = 0;
                        { int append_left = 0x40; char *append_dst = buffer;
                        while (*append_dst != 0) { append_left--; append_dst++; }
                        if (append_left > 0) {
                            src = (char *)lbl_8055B5B8;
                            goto append_check;
append_next:
                            if (--append_left > 0) goto append_check;
                            append_dst[-1] = 0; goto appended;
append_check:
                            { unsigned char c = *src++; *append_dst++ = c; if ((signed char)c == 0) goto appended; else goto append_next; }
appended:                   ;
                        } }
                    } else fn_802E317C(lbl_8033C4A0, name);
                    *(void **)(obj + 0x14) = fn_802E5AE8(buffer);
                    *(void **)(obj + 0x18) = fn_8020A6AC(name);
                    length = ((double (*)(void *))fn_802E6040)(*(void **)(obj + 0x10));
                    { float scale = lbl_805632C4, base = lbl_805632C0, n = (float)length;
                    *(float *)(obj + 0x48) = length;
                    *(unsigned int *)(obj + 0x4c) = (unsigned int)(lbl_805632BC * (base + scale * n)); }
                    { float one, zero; zero = lbl_805632B0; one = lbl_805632B4;
                    *(float *)(obj + 0x20) = zero;
                    *(float *)(obj + 0x1c) = zero;
                    *(float *)(obj + 0x24) = one;
                    *(float *)(obj + 0x28) = one;
                    *(float *)(obj + 0x2c) = zero;
                    *(float *)(obj + 0x30) = zero;
                    *(float *)(obj + 0x34) = zero;
                    *(int *)(obj + 0x38) = 0; }
                }
            }
            if (((Sound *)obj)->valid() == 0) {
                if (obj != 0) ((Sound *)obj)->destroy(1);
                return 0;
            }
            ((void **)*(void **)((char *)arg0 + 4))[i] = obj;
            return obj;
        }
    }
    fn_802E30C8(lbl_8033C3E4);
    return 0;
}
#pragma pop

extern char lbl_8033C3F4[];
#pragma scheduling invalid_target
/* Destroy a VoiceSnd: reset its vtable, stop and release the voices at +8/+0xC, free the sound resources at +0x10/+0x14 and clear the mixer work-buffer slot (index at +0x40), then free the object when shouldFree > 0. */ void *fn_8020B1C8(void *voiceSnd, int shouldFree) {
    /* Destroys a voice-sound object, releasing owned SPU resources and freeing it when requested. */
    void *voice;
    int resource;

    if (voiceSnd != 0) {
        voice = *(void **)((char *)voiceSnd + 8);
        *(void **)voiceSnd = (void *)lbl_8033C3F4;
        if (voice != 0)
            fn_802E61D8(voice);
        resource = *(int *)((char *)voiceSnd + 0xC);
        if (resource != 0)
            fn_802E61D8((void *)resource);
        resource = *(int *)((char *)voiceSnd + 0xC);
        if (resource != 0) {
            ((void (*)(void *))fn_802E6138)((void *)resource);
            *(int *)((char *)voiceSnd + 0xC) = 0;
        }
        resource = *(int *)((char *)voiceSnd + 8);
        if (resource != 0) {
            ((void (*)(void *))fn_802E6138)((void *)resource);
            *(int *)((char *)voiceSnd + 8) = 0;
        }
        resource = *(int *)((char *)voiceSnd + 0x14);
        if (resource != 0)
            fn_802E5D5C((void *)resource);
        resource = *(int *)((char *)voiceSnd + 0x10);
        if (resource != 0) {
            fn_802E5D5C((void *)resource);
            ((void (*)(void *, int, int))fn_8020B2BC)(lbl_8055EE04, (int)voiceSnd, *(int *)((char *)voiceSnd + 0x40));
        }
        if (shouldFree > 0)
            ((void (*)(void *))fn_8020A800)(voiceSnd);
    }
    return voiceSnd;
}
#pragma scheduling on

#pragma pop

int fn_8020B2A8(void *voiceSnd) {
    // Nonzero if this voice sound has a main sound resource loaded (+0x10).
    return *(int *)((char *)voiceSnd + 0x10) != 0;
}

/* Clear slot slotIndex in the active voice mixer's work-buffer slot array (voiceSound is passed but unused). */
void fn_8020B2BC(void *mixer, int voiceSound, int slotIndex) {
    int *slots = *(int **)((unsigned char *)mixer + 4);
    slots[slotIndex] = 0;
}

/* "Voice Mixer" device (callback table lbl_8033C458, installed by the device
 * constructor fn_8020A860), slot +0x3C: a mixer-device method this backend
 * does not implement.  The null backend's device table leaves the same slot
 * empty too (fn_80206480), so neither sound device in this build answers it. */
void fn_8020B2D0(void) {

}

extern unsigned char lbl_8033C520[];
extern unsigned char lbl_80489BD0[];
extern int fn_80128668(void);
int fn_8020B2D4(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Return the "Voice Mixer" name string. */
void *fn_8020B314(void) {
#define sVoiceMixerName lbl_8033C520
    return sVoiceMixerName;
#undef sVoiceMixerName
}

void fn_8020B320(void) {
    /* Reset the sound-voice state block at lbl_80489BD0: clear the flag and
     * used count, then set its capacity to 32 voices. */
    volatile unsigned char *voiceState = lbl_80489BD0;
    voiceState[0] = 0;
    *(volatile int *)(voiceState + 4) = 0;
    *(volatile int *)(voiceState + 8) = 0x20;
}

extern void fn_802E5824(void); /* SPU voice layer, slot +0x40 of the device: empty here */
extern void fn_802E5828(void); /* SPU voice layer, slot +0x44 of the device: empty here */

/* "Voice Mixer" device method, slot +0x40 of the voice backend's device vtable
 * (lbl_8033C458, installed by the constructor fn_8020A860): forwards the call to
 * the SPU voice layer's routine at 0x802E5824, dropping the device pointer.
 * That routine is empty in this build, and the "Null Mixer" device answers the
 * same slot with an empty function of its own (fn_80207C48), so neither sound
 * device in this game does anything here. */
void fn_8020B340(void) {
    fn_802E5824();
}

/* "Voice Mixer" device method, slot +0x44 of the voice backend's device vtable
 * (lbl_8033C458): the next device method, likewise only forwarding to the SPU
 * voice layer's routine at 0x802E5828 and dropping the device pointer.  That
 * routine is empty in this build too, and the "Null Mixer" device answers the
 * slot with an empty function of its own (fn_80207C4C). */
void fn_8020B344(void) {
    fn_802E5828();
}

#pragma push
#pragma cplusplus on
/* If obj is non-null, invoke its virtual deleting destructor (vtable slot 0)
 * with flag 1, i.e. destroy the object and free its storage. */
extern "C" void fn_8020B348(void *self) {
    class Obj {
    public:
        virtual void destroy(int);
    };
    if (self == 0) return;
    ((Obj *)self)->destroy(1);
}

// ---------------------------------------------------------------------------
// One sound of the sound player: 0x54 bytes allocated as "Voicesnd" by
// fn_8020AF18, with the vtable lbl_8033C3F4.
//     +0x08 fn_8020B1C8  destroy
//     +0x10 fn_8020B2A8  has a sound loaded
//     +0x14 fn_8020B874  load another sound by name
//     +0x18 VoiceSnd_playOnce  play once
//     +0x1C VoiceSnd_playLooping  play, looping
//     +0x20 fn_8020AA0C  release the voices
//     +0x24 fn_8020AA98  state
//     +0x28 fn_8020B908  mute
//     +0x2C VoiceSnd_unmute  unmute
// fn_8020AC2C pushes the mix values below into the voices every frame.
typedef struct SoundGroup {
    char name[0x20]; // at 0x00  group name, from the sound configuration
    float volume;    // at 0x20  volume set for that group
} SoundGroup;

typedef struct VoiceSnd {
    void *vtable;           // at 0x00  lbl_8033C3F4
    int state;              // at 0x04  1 = playing, 2 = muted, 3 = stopped
    void *voice;            // at 0x08  voice of the main sound
    void *voice2;           // at 0x0C  voice of the second sound, or 0
    void *sound;            // at 0x10  main sound resource
    void *sound2;           // at 0x14  second resource, played hard right
    SoundGroup *group;      // at 0x18  volume group the sound belongs to
    float volume;           // at 0x1C
    float pan;              // at 0x20  -1 = left, 1 = right
    float rate;             // at 0x24
    float surroundPan;      // at 0x28  rear balance, surround mode only
    float unused2c;         // at 0x2C  its setter does nothing
    float unused30;         // at 0x30  its setter does nothing
    float unused34;         // at 0x34  its setter does nothing
    int auxFlags;           // at 0x38  effect sends, see the mixer fn_802E6264
    unsigned char unscaled; // at 0x3C  ignore the per-frame volume scale
    unsigned char loop;     // at 0x3D  set by the play call that started it
    unsigned char mute;     // at 0x3E  set while the sound is muted
    int index;              // at 0x40  slot in the player's list
    int time;               // at 0x44  frames since the sound started
    float length;         // at 0x48  length of the sound, in seconds
    unsigned int limit;     // at 0x4C  ms after which the sound is dropped
    unsigned int elapsed;   // at 0x50  ms the sound has been playing
} VoiceSnd;

// The sound library's voices: 32 slots of which fn_802E6058 grabs one, and
// the mix values the mixer fn_802E6264 hands to the AX voice every frame.
// This unit's prototypes for the library still say int, hence the casts.
#define SND_GrabVoice(res) fn_802E6058((int)(res))
#define SND_ReleaseVoice(v) ((void (*)(void *))fn_802E6138)((v))
#define SND_SetVolume(v, x) ((void (*)(void *, float))fn_802E61E4)((v), (x))
#define SND_SetPan(v, x) fn_802E61EC((v), (x))
#define SND_SetSurroundPan(v, x) fn_802E620C((v), (x))
#define SND_SetRate(v, x) fn_802E622C((v), (x))
#define SND_SetAuxFlags(v, x) fn_802E6240((v), (x))
#define SND_Start(v) fn_802E61A8(v)      // play once, from the start
#define SND_StartLoop(v) fn_802E61BC(v)  // start looping unless already playing
#define SND_Name(res) fn_802E6ABC((int)(res))
#define SND_ReportGrabFailed() fn_80207938()  // "sound: %08d: grab failed (%s)"

// Volume knobs: the master volume is 0 while the sound is switched off
// (fn_8020A878); the scale is refreshed every frame by fn_8020AC2C.
#define MASTER_VOLUME lbl_8055B598
#define VOLUME_SCALE lbl_8055B590
#define FLOAT_ZERO lbl_805632B0
#define FLOAT_ONE lbl_805632B4
#define FLOAT_NEG_ONE lbl_805632B8

#pragma push
#pragma processor 750
/* VoiceSnd vtable +0x18: grab one or two voices, apply group volume and pan, then start the sound playing once. */ /* VoiceSnd vtable +0x18: grab one or two voices, apply group volume and pan, then start the sound playing once. */ extern "C" void VoiceSnd_playOnce(void *arg0) {
    VoiceSnd *snd = (VoiceSnd *)arg0;
    float master, gain, side;
    int i;
    void *voice;
    snd->loop = 0;
    if (snd->sound != 0 && snd->voice == 0) {
        snd->voice = SND_GrabVoice(snd->sound);
        if (snd->voice == 0) {
            // The name the library returns is the report's argument.
            SND_Name(snd->sound);
            SND_ReportGrabFailed();
        } else if (snd->sound2 != 0) {
            snd->voice2 = SND_GrabVoice(snd->sound2);
            if (snd->voice2 == 0) {
                SND_ReleaseVoice(snd->voice);
                snd->voice = 0;
            }
        }
    }
    if (snd->voice != 0) {
        snd->elapsed = 0;
        gain = snd->volume * snd->group->volume;
        if (snd->mute != 0) master = FLOAT_ZERO;
        else {
            master = MASTER_VOLUME * (snd->unscaled ? gain : gain * VOLUME_SCALE);
        }
        if (snd->voice2 != 0) {
            // Two resources: one per channel, the pan splits the volume.
            gain = FLOAT_ONE;
            side = gain + -snd->pan;
            gain = (gain < side) ? gain : side;
            gain = (gain > FLOAT_ZERO) ? gain : FLOAT_ZERO;
            SND_SetVolume(snd->voice, master * gain);
            SND_SetPan(snd->voice, FLOAT_NEG_ONE);
            gain = FLOAT_ONE;
            side = gain + snd->pan;
            gain = (gain < side) ? gain : side;
            gain = (gain > FLOAT_ZERO) ? gain : FLOAT_ZERO;
            SND_SetVolume(snd->voice2, master * gain);
            SND_SetPan(snd->voice2, FLOAT_ONE);
        } else {
            SND_SetVolume(snd->voice, master);
            SND_SetPan(snd->voice, snd->pan);
        }
        i = 0;
        do {
            if (i == 0) voice = snd->voice;
            else voice = snd->voice2;
            if (voice != 0) {
                SND_SetSurroundPan(voice, snd->surroundPan);
                fn_802E6234(voice, snd->unused2c);  // the three setters
                fn_802E6238(voice, snd->unused30);  // of this build do
                fn_802E623C(voice, snd->unused34);  // nothing at all
                SND_SetRate(voice, snd->rate);
                SND_SetAuxFlags(voice, snd->auxFlags);
            }
            i++;
        } while (i < 2);
        if (snd->loop != 0) {
            SND_StartLoop(snd->voice);
            if (snd->voice2 != 0) SND_StartLoop(snd->voice2);
        } else {
            SND_Start(snd->voice);
            if (snd->voice2 != 0) SND_Start(snd->voice2);
        }
    }
    snd->time = 0;
    snd->state = 1;
}

#pragma push
#pragma processor 750
/* VoiceSnd vtable +0x1C: grab one or two voices, feed them the group volume and
 * pan (split across hard left/right when there are two resources), then start
 * the sound playing in a loop. */
extern "C" void VoiceSnd_playLooping(void *arg0) {
    VoiceSnd *snd = (VoiceSnd *)arg0;
    float finalVolume, gain, side;
    int voiceIndex;
    void *voice;
    snd->loop = 1;
    if (snd->sound != 0 && snd->voice == 0) {
        snd->voice = SND_GrabVoice(snd->sound);
        if (snd->voice == 0) {
            // The name the library returns is the report's argument.
            SND_Name(snd->sound);
            SND_ReportGrabFailed();
        } else if (snd->sound2 != 0) {
            snd->voice2 = SND_GrabVoice(snd->sound2);
            if (snd->voice2 == 0) {
                SND_ReleaseVoice(snd->voice);
                snd->voice = 0;
            }
        }
    }
    if (snd->voice != 0) {
        snd->elapsed = 0;
        gain = snd->volume * snd->group->volume;
        if (snd->mute != 0) finalVolume = FLOAT_ZERO;
        else {
            finalVolume = MASTER_VOLUME * (snd->unscaled ? gain : gain * VOLUME_SCALE);
        }
        if (snd->voice2 != 0) {
            // Two resources: one per channel, the pan splits the volume.
            gain = FLOAT_ONE;
            side = gain + -snd->pan;
            gain = (gain < side) ? gain : side;
            gain = (gain > FLOAT_ZERO) ? gain : FLOAT_ZERO;
            SND_SetVolume(snd->voice, finalVolume * gain);
            SND_SetPan(snd->voice, FLOAT_NEG_ONE);
            gain = FLOAT_ONE;
            side = gain + snd->pan;
            gain = (gain < side) ? gain : side;
            gain = (gain > FLOAT_ZERO) ? gain : FLOAT_ZERO;
            SND_SetVolume(snd->voice2, finalVolume * gain);
            SND_SetPan(snd->voice2, FLOAT_ONE);
        } else {
            SND_SetVolume(snd->voice, finalVolume);
            SND_SetPan(snd->voice, snd->pan);
        }
        voiceIndex = 0;
        do {
            if (voiceIndex == 0) voice = snd->voice;
            else voice = snd->voice2;
            if (voice != 0) {
                SND_SetSurroundPan(voice, snd->surroundPan);
                fn_802E6234(voice, snd->unused2c);  // the three setters
                fn_802E6238(voice, snd->unused30);  // of this build do
                fn_802E623C(voice, snd->unused34);  // nothing at all
                SND_SetRate(voice, snd->rate);
                SND_SetAuxFlags(voice, snd->auxFlags);
            }
            voiceIndex++;
        } while (voiceIndex < 2);
        if (snd->loop != 0) {
            SND_StartLoop(snd->voice);
            if (snd->voice2 != 0) SND_StartLoop(snd->voice2);
        } else {
            SND_Start(snd->voice);
            if (snd->voice2 != 0) SND_Start(snd->voice2);
        }
    }
    snd->time = 0;
    snd->state = 1;
}
#pragma pop

#pragma pop

#pragma cplusplus reset
#pragma pop
extern void *fn_802E5AE8(void *);
extern void fn_802E5D5C(void *);
#pragma dont_inline fn_8020A6AC
extern void *fn_8020A6AC(void *);
#pragma dont_inline fn_8020A6AC
extern void fn_802E30C8(const char *, ...);
extern const char lbl_8033C4F0[];
/* Rebinds the voice sound's SPU resource by name, updating stored resource and lookup entry on success. */
/* Rebind a voice object's SPU sample by name: allocate the new resource, release the old one at +0x10, store the new resource and its lookup entry at +0x18, returning 1 on success or logging a failure and returning 0. */ int fn_8020B874(void *voice, void *name) {
    int success = 0;
    void *newResource = fn_802E5AE8(name);
    if (newResource != 0) {
        fn_802E5D5C(*(void **)((char *)voice + 0x10));
        *(void **)((char *)voice + 0x10) = newResource;
        *(void **)((char *)voice + 0x18) = fn_8020A6AC(name);
        success = 1;
    } else {
        fn_802E30C8(lbl_8033C4F0, name);
    }
    return success;
}

extern void fn_802E61E4(float);
extern int lbl_8055EDFC;
extern float lbl_805632B0;
/* Mute a voice sound (vtable +0x28 of lbl_8033C3F4): if not already muted and
 * still playing, set the mute flag, stop and release its voices, and zero their
 * volume; counterpart of VoiceSnd_unmute. */
void fn_8020B908(void *self) {
    VoiceSnd *snd = (VoiceSnd *)self;
    if (snd->mute == 0 && snd->state != 3) {
        snd->mute = 1;
        lbl_8055EDFC++;
        if (snd->voice != 0) {
            fn_802E61D8(snd->voice);
            if (snd->voice2 != 0)
                fn_802E61D8(snd->voice2);
            if (snd->voice2 != 0) {
                SND_ReleaseVoice(snd->voice2);
                snd->voice2 = 0;
            }
            if (snd->voice != 0) {
                SND_ReleaseVoice(snd->voice);
                snd->voice = 0;
            }
        }
        if (snd->voice != 0)
            SND_SetVolume(snd->voice, FLOAT_ZERO);
        if (snd->voice2 != 0)
            SND_SetVolume(snd->voice2, FLOAT_ZERO);
    }
}

extern void *fn_802E6058(int);
extern void fn_802E6ABC(int);
extern void fn_80207938(void);
extern void fn_802E61BC(void *);
extern void fn_802E61A8(void *);
#pragma push
#pragma processor 750
/* Unmute a voice sound (vtable slot +0x2C of lbl_8033C3F4): clear the mute flag
 * and, if fn_8020B908 took it down while it was playing (state 1, its voices
 * released), grab its voices again, re-apply the mix values and restart it. */
void VoiceSnd_unmute(void *self) {
    VoiceSnd *snd = (VoiceSnd *)self;
    float master, gain, side;
    int i;
    void *voice;
    if (snd->mute != 0) {
        snd->mute = 0;
        // Only a sound that was playing when it got muted comes back.
        if (snd->state == 1 && snd->voice == 0) {
            // From here this is the grab-and-start code of VoiceSnd_playOnce (play).
            if (snd->sound != 0 && snd->voice == 0) {
                snd->voice = SND_GrabVoice(snd->sound);
                if (snd->voice == 0) {
                    // The name the library returns is the report's argument.
                    SND_Name(snd->sound);
                    SND_ReportGrabFailed();
                } else if (snd->sound2 != 0) {
                    snd->voice2 = SND_GrabVoice(snd->sound2);
                    if (snd->voice2 == 0) {
                        SND_ReleaseVoice(snd->voice);
                        snd->voice = 0;
                    }
                }
            }
            if (snd->voice != 0) {
                gain = snd->volume * snd->group->volume;
                // snd->mute was just cleared, so this takes the live path.
                if (snd->mute != 0) master = FLOAT_ZERO;
                else {
                    master = MASTER_VOLUME * (snd->unscaled ? gain : gain * VOLUME_SCALE);
                }
                if (snd->voice2 != 0) {
                    // Two resources: one per channel, the pan splits the volume.
                    gain = FLOAT_ONE;
                    side = gain + -snd->pan;
                    gain = (gain < side) ? gain : side;
                    gain = (gain > FLOAT_ZERO) ? gain : FLOAT_ZERO;
                    SND_SetVolume(snd->voice, master * gain);
                    SND_SetPan(snd->voice, FLOAT_NEG_ONE);
                    gain = FLOAT_ONE;
                    side = gain + snd->pan;
                    gain = (gain < side) ? gain : side;
                    gain = (gain > FLOAT_ZERO) ? gain : FLOAT_ZERO;
                    SND_SetVolume(snd->voice2, master * gain);
                    SND_SetPan(snd->voice2, FLOAT_ONE);
                } else {
                    SND_SetVolume(snd->voice, master);
                    SND_SetPan(snd->voice, snd->pan);
                }
                i = 0;
                do {  // the same mix values onto both voices
                    if (i == 0) voice = snd->voice;
                    else voice = snd->voice2;
                    if (voice != 0) {
                        SND_SetSurroundPan(voice, snd->surroundPan);
                        fn_802E6234(voice, snd->unused2c);  // the three setters
                        fn_802E6238(voice, snd->unused30);  // of this build do
                        fn_802E623C(voice, snd->unused34);  // nothing at all
                        SND_SetRate(voice, snd->rate);
                        SND_SetAuxFlags(voice, snd->auxFlags);
                    }
                    i++;
                } while (i < 2);
                if (snd->loop != 0) {
                    SND_StartLoop(snd->voice);
                    if (snd->voice2 != 0) SND_StartLoop(snd->voice2);
                } else {
                    SND_Start(snd->voice);
                    if (snd->voice2 != 0) SND_Start(snd->voice2);
                }
            }
        }
    }
}
#pragma pop
/* Set the playback rate (offset 0x24) of a VoiceSnd, mixed into its voices every frame. */
void fn_8020BC50(VoiceSnd *snd, float rate) { snd->rate = rate; }

typedef float f32;
typedef signed int s32;
/* Set the per-sound volume of a VoiceSnd (mixed into its voices every frame). */
void fn_8020BC58(VoiceSnd *snd, f32 volume) { snd->volume = volume; }

/* SndVoice parameter stub: a no-arg getter that reports zero in this build. */
s32 fn_8020BC60(void) { return 0; }

/* Set the pan field (offset 0x20) of a VoiceSnd: -1 = left, 1 = right. */
void fn_8020BC68(void *snd, f32 pan) { *(f32 *)((char *)snd + 0x20) = pan; }

/* Set the surround-pan field (offset 0x28, the rear balance used in surround mode) of a VoiceSnd. */
void fn_8020BC70(void *snd, f32 surroundPan) {
    *(f32 *)((signed char *)snd + 0x28) = surroundPan;
}

/* Store the unused effect float at +0x2C of a VoiceSnd (its voice setter does nothing in this build). */
void fn_8020BC78(void *snd, f32 value) {
    *(f32 *)((signed char *)snd + 0x2C) = value;
}

/* Store the unused effect float at +0x30 of a VoiceSnd (its voice setter does nothing in this build). */
void fn_8020BC80(VoiceSnd *snd, float value) { snd->unused30 = value; }

/* Store the unused effect float at +0x34 of a VoiceSnd (its voice setter does nothing in this build). */
void fn_8020BC88(VoiceSnd *snd, float value) { snd->unused34 = value; }

/* Set the effect-send (aux) flags of a VoiceSnd (consumed by the mixer fn_802E6264). */
void fn_8020BC90(VoiceSnd *snd, int auxFlags) { snd->auxFlags = auxFlags; }

#pragma scheduling invalid_target
void fn_8020BC98(void) {
#define kSndVoiceSet3DMsg lbl_8033C510
    /* Unimplemented SndVoice::Set3D; panic with the method name. */
    fn_802E317C(kSndVoiceSet3DMsg);
#undef kSndVoiceSet3DMsg
}

/* Return the configured length (in seconds) of this voice sound. */
float fn_8020BCA8(void *snd) {
    return ((VoiceSnd *)snd)->length;
}

/* "SndVoice" (the voice backend's Sound object, vtable lbl_8033C3F4), vtable
 * slot +0x58: the Sound interface method between Set3D (+0x54, which only
 * reports "SndVoice::Set3D") and setParam (+0x5C).  No recovered game code
 * calls it through a sound and the null backend's "Null Sound" leaves the same
 * slot empty as well (fn_80209408), so a voice sound has nothing to do here. */
void fn_8020BCB0(void) {

}

/* "SndVoice" (the voice backend's Sound object, vtable lbl_8033C3F4), vtable
 * slot +0x5C setParam(void *paramBlock): receive the parameter block a Sound3D
 * queued at Sound3D+0x50, handed over once by Sound3D::update (fn_80206824),
 * which clears the queue right after.  A voice sound takes its mix values from
 * its sound group and the per-frame mixer fn_8020AC2C instead, so the block is
 * ignored here -- as it is in the null backend's "Null Sound" (fn_8020940C). */
void fn_8020BCB4(void *snd, void *paramBlock) {

}

extern void fn_802E6264(void);
extern void fn_802E6B34(void);
extern int fn_80128670(void *);
extern int fn_80019B60(void);
extern void *fn_8012850C(unsigned int, void *);
extern void *memset(void *, int, unsigned int);
extern char lbl_8033C388[];
extern char lbl_8033C37C[];
extern float lbl_805632B0, lbl_805632B4, lbl_8055B598;
extern void *lbl_8055EE04;
extern int lbl_8055EE0C;
extern void *lbl_8055EE10;
extern int fn_8012A364(void *, void *);
extern int fn_801284F8(int, void *);
extern void *fn_8012A13C(void *, int, int);
extern int fn_8012A2D8(void *);
extern char lbl_8033C368[];
extern char lbl_8033C35C[];
extern char lbl_804892D0[];
extern void fn_8020A860();
extern int fn_80208E90(int);
