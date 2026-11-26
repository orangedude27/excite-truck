#include "types.h"

extern "C" void GetSelectedMixerDevice(void);
extern "C" void *GetMixerDevice(void);
extern "C" void fn_80208D80(int);
extern "C" int fn_801284F8(int, void *);
extern "C" void fn_80208B8C(int);
extern int lbl_8055ED80;
extern unsigned char lbl_8055ED84;
extern "C" void *fn_80207990(void *, void *);
extern "C" void fn_8020A368(void);
extern "C" void fn_802E30C8(const char *, ...);
extern char lbl_8033BC50[];
extern char lbl_8033BC68[];
extern int lbl_8055D430;

static inline bool IsDebugFlagSet_802062E8(int mask) {
    return (lbl_8055D430 & 1) && (lbl_8055D430 & mask);
}

struct Rec80207490 { void *v; int pad[2]; };
struct Obj80207490 {
    char pad0[0x10]; void *key; char pad1[4]; bool flag18; char pad2[0x55]; bool flag6e;
};

class Obj80206518 {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14();
};
class Dispatch80206B14 {
public:
    virtual void pad0(); virtual void pad1(); virtual void pad2(); virtual void pad3();
    virtual void pad4(); virtual void pad5(); virtual void pad6(); virtual void pad7();
    virtual void pad8(); virtual void pad9();
    virtual void f12(float); virtual void f13(float);
    virtual void pad14(); virtual void pad15(); virtual void pad16(); virtual void pad17();
    virtual void pad18(); virtual void pad19(); virtual void f19(int);
};
class Dispatch4_80206B14 {
public:
    virtual void pad0(); virtual void pad1();
    virtual void f4(int, int);
};
class ObjIface80207218 {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21();
    virtual float get();
};
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8033BDC0;
__declspec(section ".rodata") extern char lbl_8033BDC0;
extern int lbl_8055ED80;
extern "C" void fn_80208620(int, void *);
extern "C" void Sound_releaseVoice(int, int);
extern "C" int fn_80128668(void *);
extern "C" void fn_802073A4(void*, int, int);
extern int lbl_8055ED8C;
extern void *lbl_8055ED90;
extern char lbl_8033BD3C[];
extern char lbl_8033BD4C[];
extern char lbl_8055B4C0[8];
extern char lbl_8055B4C8[8];
extern "C" void *fn_80206BF8(int, void*);
extern int lbl_8055ED80;
extern float lbl_805631F8;
extern "C" void *fn_80208994(int, int, int, float);
extern "C" void fn_802085E8(int, void *);
__declspec(section ".rodata") extern char lbl_8033BD90;
extern float lbl_805631FC;
extern float lbl_80563200;
extern float lbl_80563204;
extern "C" int fn_8012A364(void*, void*);
extern "C" int fn_801284F8(int, void*);
extern "C" void *fn_8012A13C(void *, void *, int, int);
extern "C" int fn_8012A2D8(void*);
extern "C" float PSVECMag(void*);

/* How many entries the sound-group table below is searched through; the scene
 * setup hands it its object count (fn_80206464). */
extern void *lbl_8055ED88;
extern "C" void fn_8020A400(void);
extern "C" void fn_80208D80(int);
extern unsigned char lbl_8055ED84;
#pragma scheduling invalid_target
extern "C" int fn_802062E8(void) {
    struct Service {
        virtual void f0();
        virtual int f1();
    };
    struct Dispose {
        virtual void f0(int);
    };
    int mixerName;
    void *soundManager;

    /* Initialize the sound system and SoundManager; returns 1 on success, 0 on failure. */
    fn_80208B8C(lbl_8055ED84 == 0);
    GetSelectedMixerDevice();
    mixerName = ((Service *)GetMixerDevice())->f1();
    fn_802E30C8(lbl_8033BC50, mixerName); /* "using sound mixer %s" */
    soundManager = (void *)fn_801284F8(0x118, lbl_8033BC68); /* "SoundManager" */
    if (soundManager != 0) {
        GetSelectedMixerDevice();
        soundManager = fn_80207990(soundManager, GetMixerDevice());
    }
    lbl_8055ED80 = (int)soundManager;
    if (soundManager != 0) {
        if (((unsigned char *)soundManager)[4] != 0) {
            fn_8020A368();
            return 1;
        }
        if (soundManager != 0)
            ((Dispose *)soundManager)->f0(1);
        lbl_8055ED80 = 0;
    }
    fn_80208D80(lbl_8055ED84 == 0);
    return 0;
}
#pragma scheduling on
extern "C" void fn_802063D8(void) {
    extern int lbl_8055ED80;
    struct Callback { virtual void slot0(int); };
    /* Flush sound work, notify the active manager if present, then clear and shut it down. */
    fn_8020A400();
    if (lbl_8055ED80)
        ((Callback *)lbl_8055ED80)->slot0(1);
    int value = lbl_8055ED84 == 0;
    lbl_8055ED80 = 0;
    fn_80208D80(value);
}

extern "C" int fn_80206430(void) {
    /* Returns 1 if the global status flag lbl_8055ED80 is set, 0 otherwise. */
    extern int lbl_8055ED80;
    return lbl_8055ED80 != 0;
}

extern "C" void fn_80206444(void) {
    extern int lbl_8055ED80;
    /* Set the SoundManager's byte-5 status flag to 1 (fn_80206454 clears it). */
    struct SoundManagerFlags { u8 pad[5]; u8 statusFlag; };
    ((struct SoundManagerFlags *)lbl_8055ED80)->statusFlag = 1;
}

extern "C" void fn_80206454(void) {
    extern int lbl_8055ED80;
    /* Clear the SoundManager's "paused" flag (byte +5), resuming sound. */
    struct SoundManagerFlags { char pad[5]; u8 paused; };
    ((struct SoundManagerFlags *)lbl_8055ED80)->paused = 0;
}

extern "C" void fn_80206464(void *soundGroupCount) {
    /* Set the number of scene sound-group table entries searched by fn_80206750 (carried as a pointer value). */
    lbl_8055ED88 = soundGroupCount;
}

extern "C" void fn_8020646C(long, long);
/* The scene's sound-group table: four slots, and the scene setup (fn_801E78D8)
 * stores in the slot its group id picks the index of that group's scene object. */
extern long lbl_804891E8[];
extern "C" void fn_8020646C(long slot, long value) {
    /* Set a slot of the scene's sound-group table to the index of that group's scene object. */
    lbl_804891E8[slot] = value;
}

/* No-op virtual callback stub in the audio mixer's default (null) sound device:
 * the voice-mixer backend's matching slot (fn_8020B2D0) is empty too, so neither
 * sound device implements this method in this build.  Compiles to a bare 'blr'. */
extern "C" void fn_80206480(void) {
}

extern "C" void GetSelectedMixerDevice(void);
extern "C" void *GetMixerDevice(void);
extern "C" int fn_80206430(void);
/* Dispatch an event notification to the current mixer through its callback interface. */
extern "C" void fn_80206484(int event) {
    struct MixerCallback {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8();
        virtual void notify(int);
    };
    GetSelectedMixerDevice();
    ((MixerCallback *)GetMixerDevice())->notify(event);
}

/* No-op virtual callback stub in the audio mixer's default (null) sound device,
 * alongside fn_80206480 and fn_802064CC.  Compiles to a bare 'blr'. */
extern "C" void fn_802064C8(void) {
}

/* No-op virtual callback stub in the audio mixer's device callback group, next
 * to fn_80206480/fn_802064C8.  Calling it does nothing; compiles to a bare 'blr'. */
extern "C" void fn_802064CC(void) {
}

extern "C" void fn_802064D0(int arg0) {
    struct Callback {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10();
        virtual void call(int);
    };
    /* RealName: Mixer_NotifyCurrentDevice? Dispatch event arg0 to the current mixer's vtable slot 13. */
    GetSelectedMixerDevice();
    ((Callback *)GetMixerDevice())->call(arg0);
}

/* No-op virtual callback stub in the audio mixer's device callback group, next
 * to fn_802064CC/fn_8020654C.  Calling it does nothing; compiles to a bare 'blr'. */
extern "C" void fn_80206514(void) {
}

extern "C" void fn_80206518(void) {
    extern void GetSelectedMixerDevice(void);
    extern void *GetMixerDevice(void);
    /* Select the current mixer, then invoke its f12 virtual callback. */
    GetSelectedMixerDevice();
    ((Obj80206518 *)GetMixerDevice())->f12();
}

/* No-op virtual callback in the audio mixer's device callback group (class
 * Obj80206518), alongside fn_802064CC/fn_80206514.  Calling it does nothing;
 * compiles to a bare 'blr'. */
extern "C" void fn_8020654C(void) {
}

extern "C" void fn_80206550(unsigned int value) {
    /* Set the sound manager's field at +0x8C to value. */
    #define sSoundManager lbl_8055ED80
    extern int lbl_8055ED80; extern void* fn_80207C74(int, unsigned int);
    fn_80207C74(sSoundManager, value);
    #undef sSoundManager
}

extern int lbl_8055ED80;
extern "C" int SoundMgr_setSlotData(int,int,int);
extern "C" void fn_8020655C(int soundData, int soundIndex) {
    // Store a 12-byte sound-data block into the sound manager's record for this slot.
    SoundMgr_setSlotData(lbl_8055ED80, soundData, soundIndex);
}

extern void* fn_80207C74(int, unsigned int);
extern int lbl_802F9DA0[10];
extern void* GetMixerDevice(void);
extern void GetSelectedMixerDevice(void);
extern char lbl_8033BD30[];
/* Returns the name for the given sound class index, or "<invalid>" if out of range. */
extern "C" void *fn_80206570(int soundClass) {
    struct SoundClassNameTable {
        int name[10];
    };
    struct SoundClassNameTable table = *(struct SoundClassNameTable *)&lbl_802F9DA0;
    if (soundClass < 10)
        return (void *)table.name[soundClass];
    return lbl_8033BD30;
}

extern "C" char *strncpy(char *, const char *, unsigned int);
/* Initialize base sound object fields and copy up to 12 bytes of the name. */
extern "C" void *fn_802065F8(void *arg0, int arg1, int arg2) {
    char *self = (char *)arg0;
    *(void **)self = &lbl_8033BDC0;
    strncpy(self + 0x37, (const char *)arg1, 0xC);
    int zeroInt = 0;
    int oneInt = 1;
    int neg = -0x64;
    self[0x43] = zeroInt;
    *(int *)(self + 0xC) = zeroInt;
    *(int *)(self + 0x44) = arg2;
    *(float *)(self + 4) = 1.0f;
    *(float *)(self + 8) = 1.0f;
    self[0x49] = zeroInt;
    self[0x48] = zeroInt;
    self[0x4A] = oneInt;
    self[0x4C] = zeroInt;
    self[0x4B] = zeroInt;
    self[0x4E] = oneInt;
    self[0x4D] = oneInt;
    self[0x4F] = oneInt;
    *(int *)(self + 0x10) = neg;
    *(int *)(self + 0x14) = zeroInt;
    self[0x18] = zeroInt;
    self[0x19] = zeroInt;
    *(float *)(self + 0x20) = 0.0f;
    *(float *)(self + 0x1C) = 1.0f;
    *(float *)(self + 0x24) = 0.0f;
    *(int *)(self + 0x50) = zeroInt;
    *(float *)(self + 0x28) = 0.0f;
    self[0x34] = oneInt;
    *(float *)(self + 0x2C) = 0.0f;
    self[0x35] = oneInt;
    *(float *)(self + 0x30) = 0.0f;
    self[0x36] = oneInt;
    return arg0;
}

#pragma dont_inline on
extern "C" void *fn_802066C8(void *object, u32 shouldFree) {
    /* Destructor-like cleanup: reset vtable to lbl_8033BDC0, detach/clear the handle at +0xC via lbl_8055ED80 manager helpers, and optionally free the object. */
    if (object != 0) {
        int handle = *(int *)((char *)object + 0xC);
        *(void **)object = (void *)&lbl_8033BDC0;
        if (handle != 0) {
            fn_80208620(lbl_8055ED80, object);
            Sound_releaseVoice(lbl_8055ED80, *(int *)((char *)object + 0xC));
            *(int *)((char *)object + 0xC) = 0;
        }
        if ((int)shouldFree > 0)
            fn_80128668(object);
    }
    return object;
}
#pragma dont_inline reset

/* Sound3D::setAuxGroup -- set the effect-send (aux) flags of a Sound3D from the
 * scene object it belongs to.  The scene setup (fn_801E78D8) fills the four
 * group slots with the index of each group's scene object, so the slot holding
 * `soundIndex` -- the index the sound was made for, which fn_80207428 keeps at
 * +0x10 -- is the group the sound plays in, and that slot's bit becomes its aux
 * flags.  A sound in no group, or one with `enable` 0, gets its flags cleared.
 * Either way the dirty flag goes up, so the next update (fn_80206B14) hands the
 * flags to the VoiceSnd, which passes them to the mixer.
 */
extern "C" void fn_80206750(void *sound, int soundIndex, int enable) {
    /* The two Sound3D fields written here; the class is laid out below. */
    #define auxFlags (*(int *)((char *)sound + 0x14))
    #define auxFlagsDirty (*(unsigned char *)((char *)sound + 0x4F))
    #define soundGroupTable lbl_804891E8
    #define soundGroupCount lbl_8055ED88
    int count = (int)(long)soundGroupCount;
    int group = -1;
    int i = 0;
    for (; i < count; i++) {
        if (soundIndex == soundGroupTable[i]) {
            group = i;
            break;
        }
    }
    if (group >= 0 && enable) {
        auxFlagsDirty = 1;
        auxFlags = 1 << group;
    } else {
        auxFlags = 0;
        auxFlagsDirty = 1;
    }
    #undef auxFlags
    #undef auxFlagsDirty
    #undef soundGroupTable
    #undef soundGroupCount
}

#pragma scheduling invalid_target
extern "C" void fn_802067C8(void *object, void *context, int arg) {
    struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(void *, int); };
    /* If enabled and either active (field_08 > 0.0f) or its list slot is empty,
     * mark this object active and dispatch virtual slot f3. */
    int slotEmpty = !*(int *)((u8 *)object + 0x44);
    if ((*(u8 *)((u8 *)object + 0x18) = (*(u8 *)((u8 *)object + 0x19) != 0 &&
        (*(float *)((u8 *)object + 8) > lbl_80563200 || slotEmpty)))) {
        ((Obj *)object)->f3(context, arg);
    }
}
#pragma scheduling on
/* Base-class no-op for Sound3D's per-frame update virtual (vtable lbl_8033BDC0
 * at +0x14), called every frame by Sound3D::update; derived sounds override it.
 * The base implementation does nothing, so it compiles to a bare 'blr'. */
extern "C" void fn_80206820(void) {
}

/* The sound a Sound3D plays: voicesnd.c's VoiceSnd (its vtable is
 * lbl_8033C3F4, the one the mixer's createSound hands back).  Only the slots
 * this unit calls through are declared; the mix-value setters at +0x30..+0x4C
 * and the effect flags at +0x50 just store into the sound, and
 * VoiceSnd_playOnce/VoiceSnd_playLooping push them into the voice when it starts. */
class VoiceSnd {
public:
    virtual void destroy();               /* +0x08 */
    virtual void dispose();               /* +0x0C */
    virtual int hasSound();               /* +0x10 */
    virtual void loadSound();             /* +0x14 */
    virtual void play();                  /* +0x18 */
    virtual void playLooping();           /* +0x1C */
    virtual void releaseVoices();         /* +0x20 */
    virtual int state();                  /* +0x24, one of VoiceSndState below */
    virtual void mute();                  /* +0x28 */
    virtual void unmute();                /* +0x2C */
    virtual void setRate(float);          /* +0x30 sound+0x24 */
    virtual void setVolume(float);        /* +0x34 sound+0x1C */
    virtual int slot38();                 /* +0x38 always 0 */
    virtual void setPan(float);           /* +0x3C sound+0x20 */
    virtual void setSurroundPan(float);   /* +0x40 sound+0x28 */
    virtual void setUnused2c(float);      /* +0x44 sound+0x2C */
    virtual void setUnused30(float);      /* +0x48 sound+0x30 */
    virtual void setUnused34(float);      /* +0x4C sound+0x34 */
    virtual void setAuxFlags(int);        /* +0x50 Sound3D.auxFlags */
    virtual void set3d();                 /* +0x54 unimplemented: SndVoice only reports "SndVoice::Set3D" */
    virtual void slot58();                /* +0x58 empty in both backends; nothing calls it */
    virtual void setParam(void *);        /* +0x5C the block queued at Sound3D+0x50 */
};

/* What VoiceSnd::state() answers; Sound3D_update runs its play/mute bookkeeping
 * off these. */
enum VoiceSndState {
    VOICE_STATE_PLAYING = 1,
    VOICE_STATE_MUTED   = 2,
    VOICE_STATE_STOPPED = 3
};

/* One of the game's 3D sounds -- "Sound3D" is the name its pool allocation
 * uses (lbl_8033BD3C), with "SoundDash" (lbl_8033BD4C) beside it.  The base
 * vtable is lbl_8033BDC0: +0x08 destructor, +0x0C update, +0x10 the mix-value
 * flush below (shared by every derived class), +0x14 the per-frame work.
 * Mix values are queued here with a dirty flag each (the setters set both);
 * the update virtuals push the flagged ones to the VoiceSnd and clear them.
 * The flags at +0x48.. are requests queued on the sound by the game, which
 * Sound3D_update carries out on the VoiceSnd on the next pass. */
struct Sound3D {
    void *vtable;                /* at 0x00 */
    float rate;                  /* at 0x04 -> VoiceSnd::setRate, flag at 0x4E */
    float volume;                /* at 0x08 -> VoiceSnd::setVolume, flag at 0x4D */
    VoiceSnd *sound;             /* at 0x0C the sound played, 0 when none */
    int slot10;                  /* at 0x10 -100 until the sound is placed */
    int auxFlags;                /* at 0x14 -> VoiceSnd slot +0x50, flag 0x4F */
    unsigned char audible;       /* at 0x18 fn_802067C8: playing, and audible this pass */
    unsigned char playing;       /* at 0x19 Sound3D_update keeps it up while the sound runs */
    char pad1A[0x28 - 0x1A];
    float unused2c;              /* at 0x28 -> VoiceSnd::setUnused2c */
    float unused30;              /* at 0x2C -> VoiceSnd::setUnused30 */
    float unused34;              /* at 0x30 -> VoiceSnd::setUnused34 */
    unsigned char unused2cDirty; /* at 0x34 */
    unsigned char unused30Dirty; /* at 0x35 */
    unsigned char unused34Dirty; /* at 0x36 */
    char pad37[0x44 - 0x37];
    int handle44;                /* at 0x44 what the sound was made with; 0 = no slot */
    unsigned char muted;         /* at 0x48 the sound is to be muted */
    unsigned char playPending;   /* at 0x49 start it on the next update */
    unsigned char releasePending;/* at 0x4A give its voices back on the next update */
    unsigned char loop;          /* at 0x4B play it looping rather than once */
    unsigned char releaseOnce;   /* at 0x4C give its voices back once */
    unsigned char volumeDirty;   /* at 0x4D hand `volume` to the sound */
    unsigned char rateDirty;     /* at 0x4E hand `rate` to the sound */
    unsigned char auxFlagsDirty; /* at 0x4F set with auxFlags, flushed by fn_80206B14 */
    int queuedParam;             /* at 0x50 block handed to VoiceSnd::setParam, then cleared */
};

/* Sound3D::update -- the pass the SoundManager runs over every sound it owns
 * (SoundMgr_refreshSounds, right after fn_802067C8 worked out whether each is audible).
 * The game queues its wishes as the flags at Sound3D+0x48; here they are
 * carried out on the VoiceSnd being played, in step with the state that sound
 * reports: a playing sound gets its voices back or is muted, a stopped one
 * starts the pending play (looping or once) unless nothing is pending, which
 * takes the sound out of play, and a muted sound is unmuted once the mute is
 * lifted.  Whatever was queued at +0x50 then goes to the sound, and a sound
 * that is not muted runs its own virtual update. */
extern "C" void Sound3D_update(void *object, int context, int arg) {
    /* The sound's own update: vtable slot +0x0C, fn_80206B14 in the base class. */
    struct SoundBase { virtual void dispose(); virtual void update(int, int); };
    Sound3D *self = (Sound3D *)object;
    int state = self->sound->state(); /* VOICE_STATE_* below */
    self->playing = 1;                /* stays down only if the sound is out of play */
    switch (state) {
    case VOICE_STATE_PLAYING:
        if (self->releasePending) {
            self->sound->releaseVoices();
        } else if (self->muted) {
            self->sound->mute();
        } else if (self->releaseOnce) { /* a one-shot release waits for the next pass */
            self->releaseOnce = 0;
            self->sound->releaseVoices();
        }
        break;
    case VOICE_STATE_STOPPED:
        if (self->playPending) {
            /* debug flag 0x200: a sound placed on something keeps its slot empty */
            if (IsDebugFlagSet_802062E8(0x200) && self->handle44 != 0)
                goto skip;
            self->playPending = 0;
            if (self->loop)
                self->sound->playLooping();
            else
                self->sound->play();
        } else {
skip:
            self->playing = 0;
        }
        if (self->muted)
            self->sound->mute();
        break;
    case VOICE_STATE_MUTED:
        if (!self->muted) {
            if (self->releasePending)
                self->sound->releaseVoices();
            else
                self->sound->unmute();
        }
        break;
    }
    if (self->queuedParam) { /* a parameter block queued for the sound */
        self->sound->setParam(&self->queuedParam);
        self->queuedParam = 0;
    }
    if (!self->muted) { /* a muted sound does not run its own update */
        ((SoundBase *)object)->update(context, arg);
    }
}

extern "C" void fn_80206A5C(void* arg0) {
    /* Sound3D::flushMixValues -- vtable slot +0x10, the one every sound class
     * of this unit shares: hand each queued mix value whose dirty flag is set
     * to the VoiceSnd being played and clear the flag.  These three are the
     * mix values voicesnd.c calls unused2c/30/34: this build's sound library
     * ignores them, so storing them is all the send amounts to. */
    Sound3D* self = (Sound3D*)arg0;
    if (self->unused2cDirty) {
        self->unused2cDirty = 0;
        self->sound->setUnused2c(((Sound3D*)arg0)->unused2c);
    }
    if (self->unused30Dirty) {
        VoiceSnd* sound = self->sound;
        self->unused30Dirty = 0;
        sound->setUnused30(self->unused30);
    }
    if (self->unused34Dirty) {
        VoiceSnd* sound = self->sound;
        self->unused34Dirty = 0;
        sound->setUnused34(self->unused34);
    }
}

/* Sound module: empty entry point, the first of three adjacent no-op stubs
 * (with fn_80206B0C and fn_80206B10) between the Sound3D mix-value flush
 * fn_80206A5C and the base Sound3D::update fn_80206B14.  Calling it does
 * nothing and no decompiled code or sound vtable references it. */
extern "C" void fn_80206B08(void) {
	return;
}

/* Sound module: an entry point whose implementation is empty in this build --
 * calling it does nothing.  It is one of three adjacent no-op stubs (with
 * fn_80206B08 and fn_80206B10) sitting between the Sound3D mix-value flush
 * fn_80206A5C and the base Sound3D::update fn_80206B14; no decompiled code
 * calls them and none of this module's sound vtables (lbl_8033BD78,
 * lbl_8033BD90, lbl_8033BDA8, lbl_8033BDC0 -- four slots each) points at them,
 * so they are hooks the original source left without a body. */
extern "C" void fn_80206B0C(void) {
	return;
}

/* Sound module: an entry point whose implementation is empty in this build --
 * calling it does nothing.  Third of the three adjacent no-op stubs
 * (fn_80206B08, fn_80206B0C, this one) between the Sound3D mix-value flush
 * fn_80206A5C and the base Sound3D::update fn_80206B14; nothing calls them and
 * none of this module's sound vtables (lbl_8033BD78, lbl_8033BD90,
 * lbl_8033BDA8, lbl_8033BDC0) has a slot for them. */
extern "C" void fn_80206B10(void) {
	return;
}

#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void fn_80206B14(void *arg0, int arg1, int arg2) {
    /* Dispatch queued float/int commands then forward (arg1,arg2) via vtable slot 4. */
    unsigned char *p = (unsigned char *)arg0;
    if (p[0x4D]) {
        p[0x4D] = 0;
        ((Dispatch80206B14 *)*(void **)(p + 0xC))->f13(*(float *)((char *)arg0 + 8));
    }
    if (p[0x4E]) {
        void *obj = *(void **)(p + 0xC);
        p[0x4E] = 0;
        ((Dispatch80206B14 *)obj)->f12(*(float *)(p + 4));
    }
    if (p[0x4F]) {
        void *obj = *(void **)(p + 0xC);
        p[0x4F] = 0;
        ((Dispatch80206B14 *)obj)->f19(*(int *)(p + 0x14));
    }
    ((Dispatch4_80206B14 *)arg0)->f4(arg1, arg2);
}
#pragma scheduling on
#pragma dont_inline reset
/* Sound module: empty entry point that does nothing.  It sits just ahead of
 * the Sound3D object-pool helpers -- fn_80206BF8 lazily builds the pool and
 * takes an object from it, fn_80206C70 hands one back and tears the pool down
 * when its use count lbl_8055ED8C reaches zero -- so it is the third slot of
 * that little allocator interface (an "initialize"/"reserve" step) left
 * without a body in this build; no decompiled code calls it. */
extern "C" void fn_80206BF4(void) {
	return;
}

#pragma dont_inline on
/* Lazily allocates/initializes the Sound3D pool (lbl_8055ED90, tag lbl_8033BD3C
   "Sound3D::pool") on first use, then takes an object from it via fn_8012A2D8
   and increments the use count lbl_8055ED8C on success. */
extern "C" void *fn_80206BF8(int unused0, void *unused1) {
    void *pool;
    (void)unused0;
    (void)unused1;
    if (lbl_8055ED8C == 0) {
        pool = (void *)fn_801284F8(0x20, lbl_8033BD3C);
        if (pool != 0) {
            pool = fn_8012A13C(pool, lbl_8033BD3C, 0xC0, 0x78);
        }
        lbl_8055ED90 = pool;
    }
    if (fn_8012A2D8(lbl_8055ED90) != 0) {
        lbl_8055ED8C += 1;
    }
}
#pragma dont_inline off

extern float lbl_8056320C;
extern float lbl_80563210;
extern float lbl_80563214;
extern float lbl_80563218;
extern float lbl_8056321C;
extern float lbl_80563200;
extern char lbl_8033BDC0;
__declspec(section ".rodata") extern char lbl_8033BDC0;
extern "C" void fn_80208620(int, void *);
extern "C" void Sound_releaseVoice(int, int);
extern "C" int fn_80128668(void *);
/* Returns an object to the Sound3D pool and destroys the pool when its use count reaches zero. */
extern "C" void fn_80206C70(void *object) {
    struct Callback {
        virtual void slot1(int);
        virtual void slot0();
    };
    fn_8012A364(lbl_8055ED90, object);
    if (--lbl_8055ED8C == 0) {
        if (lbl_8055ED90)
            ((Callback *)lbl_8055ED90)->slot1(1);
        lbl_8055ED90 = 0;
    }
}

#pragma push
#pragma processor 750
extern "C" float fn_80206CD0(void* arg0, float arg1) {
    /* Returns arg1 clamped by (vector magnitude minus max(0, 0.75*z)): computes
     * arg1 / max(arg1, |arg0| - max(0, 0.75 * arg0.z)). */
    float minOffset = lbl_805631FC;
    float zTerm = lbl_80563204 * *(float*)((char*)arg0 + 8);
    minOffset = (minOffset > zTerm) ? minOffset : zTerm;
    float dist = PSVECMag(arg0) - minOffset;
    dist = (dist > arg1) ? dist : arg1;
    return arg1 / dist;
}
#pragma pop
extern "C" float PSVECDotProduct(const void*, const void*);
extern float lbl_805631F8, lbl_805631FC, lbl_80563208;
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_80206D3C(void *self, void *list, int count) {
    register unsigned char *p = (unsigned char *)self;
    float vec[3];
    register int i;
    register unsigned char *it;

    p[0x64] = 0;
    *(float *)(p + 0x68) = 0.0f;
    if (p[0x18]) {
        register float threshold = 1.0f;
        register float margin = 200.0f;
        it = (unsigned char *)list;
        for (i = 0; i < count; ++i, it += 0xC) {
            register float *pos = *(float **)(p + 0x74);
            register unsigned char *item = *(unsigned char **)(it + 4);
            float dx = pos[0] - *(float *)(item + 0x24);
            vec[0] = dx;
            float dy = pos[1] - *(float *)(item + 0x28);
            vec[1] = dy;
            float dz = pos[2] - *(float *)(item + 0x2C);
            vec[2] = dz;
            float outX = dz * *(float *)(item + 8) +
                         (dx * *(float *)item + dy * *(float *)(item + 4));
            float outY = dz * *(float *)(item + 0x14) +
                         (dx * *(float *)(item + 0xC) + dy * *(float *)(item + 0x10));
            float outZ = dz * *(float *)(item + 0x20) +
                         (dx * *(float *)(item + 0x18) + dy * *(float *)(item + 0x1C));
            vec[0] = outX;
            vec[1] = outY;
            vec[2] = outZ;
            float dot = PSVECDotProduct(vec, vec);
            float radius = margin + *(float *)(p + 0x6C);
            if (dot < radius * radius) {
                float value = *(float *)(p + 8);
                p[0x64] = 1;
                value = (value < threshold) ? value : threshold;
                float p6c = *(float *)(p + 0x6C);
                float scaled = value * fn_80206CD0(vec, p6c);
                *(float *)(p + 0x68) = (*(float *)(p + 0x68) > scaled) ? *(float *)(p + 0x68) : scaled;
            }
        }
        if (!p[0x64]) p[0x18] = 0;
    }
}

extern "C" void fn_80206EE4(void *arg0, void *arg1, int arg2) {
    struct Hnd {
        virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
        virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
        virtual void p8(); virtual void p9();
        virtual void s30(float); virtual void s34(float); virtual int r38();
        virtual void s3c(float); virtual void s40(float);
        virtual void q15(); virtual void q16(); virtual void q17(); virtual void q18();
        virtual void f54(int, int);
    };
    struct Obj {
        virtual void p0(); virtual void p1();
        virtual void upd(void*, int);
    };
    unsigned char *obj;
    unsigned char *p;
    int count;
    obj = (unsigned char *)arg0;
    p = (unsigned char *)arg1;
    count = arg2;
    if (obj[0x64] == 0) return;
    if ((*(Hnd **)(obj + 0xC))->r38() != 0) {
        fn_80206B14(arg0, (int)arg1, arg2);
        (*(Hnd **)(obj + 0xC))->f54(*(int *)(obj + 0x70), *(int *)(obj + 0x74));
        return;
    }
    ((Obj *)arg0)->upd(arg1, arg2);
    (*(Hnd **)(obj + 0xC))->s34(*(float *)(obj + 0x68));
    if (obj[0x19] == 0) return;
    float f31, f30, f29, f28, f27, f26, f25, inv, f23;
    f28 = lbl_805631FC;
    f30 = lbl_805631F8;
    f31 = lbl_80563210;
    f23 = lbl_80563214;
    f29 = lbl_8056320C;
    f27 = f28; f26 = f28; f25 = f28;
    int idx = 0;
    while (idx < count) {
        int itmp[3];
        float btmp[3];
        float vec[3];
        float vec2[3];
        float *p74 = *(float **)(obj + 0x74);
        itmp[0] = (*(int **)(p + 4))[9];
        itmp[1] = (*(int **)(p + 4))[10];
        itmp[2] = (*(int **)(p + 4))[11];
        ((int*)btmp)[0] = (*(int **)(p + 8))[0];
        ((int*)btmp)[1] = (*(int **)(p + 8))[1];
        ((int*)btmp)[2] = (*(int **)(p + 8))[2];
        vec[0] = p74[0] - *(float*)&itmp[0];
        vec[1] = p74[1] - *(float*)&itmp[1];
        vec[2] = p74[2] - *(float*)&itmp[2];
        float mag = PSVECMag(vec);
        if (mag > f29) {
            inv = f30 / mag;
            vec[0] *= inv;
            float *dotp = *(float **)(p + 4);
            vec[1] *= inv; vec[2] *= inv;
            f28 += inv;
            float d1 = PSVECDotProduct(vec, dotp);
            if (mag < f31) d1 *= mag / f31;
            f27 += d1 * inv;
            float d2 = PSVECDotProduct(vec, (void *)((char *)*(int **)(p + 4) + 0x18));
            if (mag < f31) d2 = f30 + ((mag / f31) * (d2 - f30));
            f26 += (d2 * inv);
            float *p70 = *(float **)(obj + 0x70);
            vec2[0] = p70[0] - btmp[0];
            vec2[1] = p70[1] - btmp[1];
            vec2[2] = p70[2] - btmp[2];
            float d3 = PSVECDotProduct(vec2, vec);
            float ratio = f23 / (f23 + d3);
            f25 += ratio * inv;
        }
        p += 12;
        idx++;
    }
    f28 = (f28 > lbl_80563218) ? f28 : lbl_80563218;
    float inv2 = lbl_805631F8 / f28;
    (*(Hnd **)(obj + 0xC))->s30(*(float *)(obj + 4) * (f25 * inv2));
    float v27 = f27 * inv2;
    float c1 = lbl_805631F8;
    c1 = (c1 < v27) ? c1 : v27;
    c1 = (c1 > lbl_8056321C) ? c1 : lbl_8056321C;
    (*(Hnd **)(obj + 0xC))->s3c(c1);
    float v26 = f26 * inv2;
    float c2 = lbl_805631F8;
    c2 = (c2 < v26) ? c2 : v26;
    c2 = (c2 > lbl_8056321C) ? c2 : lbl_8056321C;
    (*(Hnd **)(obj + 0xC))->s40(c2);
}

#pragma processor gekko
#pragma use_lmw_stmw reset
#pragma scheduling on
#pragma dont_inline reset
extern "C" void *fn_802065F8(void *, int, int);
#define fn_802065F8() fn_802065F8(arg0, arg1, arg2)
extern "C" void *fn_80208998(int, int, int, float);
extern "C" void fn_802085EC(int, void *);
extern float lbl_80563220;
extern char lbl_8033BDA8;
__declspec(section ".rodata") extern char lbl_8033BDA8;
#pragma scheduling invalid_target
extern "C" void *fn_80207218(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    /* Initialize sound object: set vtable/default fields, acquire sound handle, and cache its value. */
    ObjIface80207218 *soundHandle;
    float value;
    float defaultRadius;
    void *vtable;

    fn_802065F8();
    value = *(volatile float *)&lbl_805631FC;
    vtable = &lbl_8033BDA8;
    defaultRadius = *(volatile float *)&lbl_80563220;
    *(volatile void **)arg0 = vtable;
    *(float *)((char *)arg0 + 0x68) = value;
    *(float *)((char *)arg0 + 0x6C) = defaultRadius;
    *(char *)((char *)arg0 + 0x64) = 1;
    *(int *)((char *)arg0 + 0x70) = arg3;
    *(int *)((char *)arg0 + 0x74) = arg4;
    soundHandle = (ObjIface80207218 *)fn_80208998(lbl_8055ED80, arg1, arg2, value);
    *(ObjIface80207218 **)((char *)arg0 + 0xC) = soundHandle;
    if (soundHandle != 0)
        fn_802085EC(lbl_8055ED80, arg0);
    soundHandle = *(ObjIface80207218 **)((char *)arg0 + 0xC);
    if (soundHandle != 0)
        value = soundHandle->get();
    else
        value = lbl_805631FC;
    *(float *)((char *)arg0 + 0x24) = value;
    return arg0;
}
#pragma scheduling on
#define SOUND_DEFAULT_VALUE lbl_805631FC  /* .sdata2: pooled 0.0f, default for sound parameters */
extern "C" f32 fn_802072DC(void) {
    /* Return the shared default sound-parameter value (0.0f). */
    return SOUND_DEFAULT_VALUE;
}

#pragma push
#pragma processor 750
/* Initialize a sound object: set its vtable and default fields, acquire a
 * VoiceSnd handle from the sound manager, register it, and cache the sound's
 * initial parameter value. */
extern "C" void *fn_802072E4(void *arg0, int arg1, int arg2) {
    void *vtable;
    float cachedValue;
    void *voiceSnd;
    fn_802065F8();
    vtable = &lbl_8033BD90;
    *(volatile void **)arg0 = vtable;
    *(float *)((char *)arg0 + 0x64) = 0.0f;
    *(char *)((char *)arg0 + 0x6C) = 1;
    *(float *)((char *)arg0 + 0x68) = 1.0f;
    *(char *)((char *)arg0 + 0x6D) = 1;
    voiceSnd = fn_80208994(lbl_8055ED80, arg1, arg2, 0.0f);
    *(void **)((char *)arg0 + 0xC) = voiceSnd;
    if (voiceSnd != 0)
        fn_802085E8(lbl_8055ED80, arg0);
    voiceSnd = *(void **)((char *)arg0 + 0xC);
    if (voiceSnd != 0) {
        struct Cb {
            virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
            virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
            virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
            virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
            virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
            virtual void m20(); virtual void m21();
            virtual float get();
        };
        cachedValue = ((Cb *)voiceSnd)->get();
    } else {
        cachedValue = 0.0f;
    }
    *(float *)((char *)arg0 + 0x24) = cachedValue;
    return arg0;
}
#pragma pop
/* Updates queued mix dispatch state, then flushes two pending float commands (flags at +0x6C/+0x6D, values at +0x64/+0x68) to the owned object at +0x0C via vtable slots +0x3C/+0x40. */
extern "C" void fn_802073A4(void *self, int arg1, int arg2) {
    class Dispatch {
    public:
        virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3();
        virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
        virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11();
        virtual void p12();
        virtual void f0(float);
        virtual void f1(float);
    };
    fn_80206B14(self, arg1, arg2);
    unsigned char *p = (unsigned char *)self;
    if (p[0x6c] != 0) {
        void *obj = *(void **)(p + 0x0c);
        p[0x6c] = 0;
        ((Dispatch *)obj)->f0(*(float *)(p + 0x64));
    }
    if (p[0x6d] != 0) {
        void *obj = *(void **)(p + 0x0c);
        p[0x6d] = 0;
        ((Dispatch *)obj)->f1(*(float *)(p + 0x68));
    }
}

extern "C" void *fn_802072E4(void *, int, int);
#undef fn_802065F8
extern void fn_802085E8(int, void *);
extern void *fn_80208994(int, int, int, float);
extern float lbl_805631F8;
__declspec(section ".rodata") extern char lbl_8033BD90;
extern char lbl_8033BD78;
#pragma dont_inline on
__declspec(section ".rodata") extern char lbl_8033BD78;
extern "C" void *fn_80207428(void *object, int arg1, int arg2, int soundIndex, int enableAux) {
    void *self = object;
    fn_802072E4(self, arg1, arg2);
    *(int *)((char *)self + 0x10) = soundIndex;
    *(void **)self = &lbl_8033BD78;
    fn_80206750(self, soundIndex, enableAux);
    return self;
}

#pragma scheduling invalid_target
/* Check whether a sound's key appears in a record list and update its flags:
 * set flag6e when any record's value matches the key, then clear flag18 unless
 * flag6e is set. */
extern "C" void fn_80207490(Obj80207490 *sound, const Rec80207490 *entries, int count) {
    sound->flag6e = false;
    int index = 0;
    if (count > 0) {
        for (; index < count; index++) {
            sound->flag6e = (sound->flag6e | (sound->key == entries[index].v)) != 0;
        }
    }
    sound->flag18 = (sound->flag18 & sound->flag6e) != 0;
}
extern "C" void fn_8020769C(void *self, int arg1, int arg2) {
    /* Tail-call forward to fn_802073A4, which flushes this sound object's dirty
     * mix values. */
    fn_802073A4(self, arg1, arg2);
}

/* Create a SoundDash sound object (0x70 bytes), initialize it, and
 * return it only if construction produced a valid inner sound handle at +0xC. */
extern "C" void *fn_802076A0(int arg0, int arg1, int arg2, int arg3) {
    struct Callback {
        virtual ~Callback();
    };
    void *soundObj = (void *)fn_801284F8(0x70, lbl_8033BD4C);
    if (soundObj != 0)
        soundObj = fn_80207428(soundObj, arg0, arg1, arg2, arg3);
    if (soundObj != 0 && *(int *)((char *)soundObj + 0xC) == 0) {
        delete (Callback *)soundObj;
        soundObj = 0;
    }
    return soundObj;
}

#pragma dont_inline reset

extern "C" void *fn_802066C8(void*, u32);
/* nw4hbm::snd::detail::DisposeCallbackManager scalar deleting destructor.
 * Destroys the subobject via fn_802066C8 when non-null, then frees storage
 * with fn_80128668 (operator delete, mode 3) if deletingFlag > 0. */
extern "C" void* __dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_80207748(
    void* thisPtr, s32 deletingFlag) {
    if (thisPtr) {
        if (thisPtr != NULL) {
            fn_802066C8(thisPtr, 0);
        }

        if (deletingFlag > 0) {
            fn_80128668(thisPtr);
        }
    }
    return thisPtr;
}

#pragma scheduling on
extern "C" void *fn_802077A4(int arg0, int arg1, int arg2, int arg3) {
    /* Allocate and initialize a Sound3D object (0x78 bytes, pool tag
     * lbl_8055B4C0 "Sound3D"); if initialization yields no inner handle at
     * +0xC, destroy and return NULL. */
    struct Callback { virtual ~Callback(); };
    void *obj = fn_80206BF8(0x78, lbl_8055B4C0);
    if (obj != 0)
        obj = fn_80207218(obj, arg0, arg1, arg2, arg3);
    if (obj != 0 && *(int *)((char *)obj + 0xC) == 0) {
        delete (Callback *)obj;
        obj = 0;
    }
    return obj;
}

/* Allocate and initialize a sound object; delete and return NULL if initialization produced no handle. */
extern "C" void *fn_80207848(int soundId, int flags) {
    struct Callback { virtual ~Callback(); };
    void *obj = (void *)fn_801284F8(0x70, lbl_8055B4C8);
    if (obj != 0)
        obj = fn_802072E4(obj, soundId, flags);
    if (obj != 0 && *(int *)((char *)obj + 0xC) == 0) {
        delete (Callback *)obj;
        obj = 0;
    }
    return obj;
}

#pragma scheduling invalid_target
extern "C" void *fn_802078CC(int arg0, int arg1, void *object) {
    /* Resolve object through fn_802072E4 when non-null, returning it only if its
     * handle at +0xC is set. */
    void *result = object;
    if (object != 0) {
        result = fn_802072E4(object, arg0, arg1);
    }
    return (*(int *)((u8 *)result + 0xC) != 0) ? result : 0;
}
#pragma scheduling on
extern "C" void fn_80207924(void *sound) {
    /* Dispatch the virtual at vtable slot 0x8 on the sound object, passing -1. */
    struct SoundObj { virtual void v0(int); };
    ((SoundObj *)sound)->v0(-1);
}

extern int lbl_8055ED94;
extern char lbl_8033BD58[];
extern "C" void fn_80206B14(void *, int, int);
extern "C" void *fn_802072E4(void *, int, int);
extern "C" void fn_802E30C8(const char *, ...);
extern int lbl_8055ED94;
extern "C" void fn_802E30C8(const char *, ...);
// Reports a sound "grab failed" error, logging the sound name with an incrementing counter.
// Keep the format label array-typed so MWCC emits the original lis/addi address load.
extern "C" void fn_80207938(int soundName) {
    fn_802E30C8(lbl_8033BD58, ++lbl_8055ED94, soundName);
}

