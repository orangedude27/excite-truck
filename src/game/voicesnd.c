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
  extern void fn_802E6B34(void);
  typedef struct { void **vtable; } Unk8012A570;
    extern void fn_8020A860();
  extern int fn_80208E90(int);
  extern float lbl_805632B0, lbl_805632B4, lbl_8055B598;

  extern void *lbl_8055EE04;
extern char lbl_8033C37C[];
extern void *lbl_8055EE08;
extern unsigned char lbl_8033C520[];
extern unsigned char lbl_80489BD0[];
extern int fn_80128668(void);
extern char lbl_8033C458[];
typedef struct { char *name; int state; } UnkStruct_8020A860;
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma scheduling invalid_target
void *fn_8020A6AC(void *arg0) {
    char *entry = lbl_804892D0;
    int i = 0;
    while (i < (int)lbl_8055EE08) {
        if (stricmp((const char *)arg0, entry) == 0)
            return entry;
        entry += 0x24;
        i++;
    }
    return lbl_8033C338;
}
#pragma scheduling on
#pragma dont_inline reset

void fn_8020A72C(void) {
    void *object = (void *)fn_801284F8(0xC, lbl_8033C35C);
    if (object != 0)
        object = ((void *(*)(void *))fn_8020A860)(object);
    ((int (*)(void *, int))fn_80208E90)(object, 0);
}
#pragma scheduling on
void* fn_8020A76C(void) {
    return lbl_8055EE08;
}

void *fn_8020A774(int arg0) { return lbl_804892D0 + arg0 * 0x24; }

int fn_8020A788(void) {
    void *value;
    int ret;
    if (lbl_8055EE0C == 0) {
        value = (void *)fn_801284F8(0x20, lbl_8033C368);
        if (value != 0) {
            value = ((void *(*)(void *, void *, int, int))fn_8012A13C)(value, lbl_8033C368, 0x200, 0x54);
        }
        lbl_8055EE10 = value;
    }
    ret = fn_8012A2D8(lbl_8055EE10);
    if (ret != 0) {
        lbl_8055EE0C += 1;
    }
    return ret;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020A800(void *arg0) {
    class Obj {
    public:
        virtual void f(int);
    };
    fn_8012A364(lbl_8055EE10, arg0);
    if (--lbl_8055EE0C == 0) {
        if (lbl_8055EE10 != 0)
            ((Obj *)lbl_8055EE10)->f(1);
        lbl_8055EE10 = 0;
    }
}
#pragma cplusplus reset
#pragma pop

#pragma scheduling invalid_target
void fn_8020A860(UnkStruct_8020A860 *arg0) {
    arg0->name = lbl_8033C458;
    arg0->state = 0;
}

#pragma scheduling invalid_target
int fn_8020A878(void *arg0) {
    void *buffer;
    if (fn_80019B60() != 0)
        lbl_8055B598 = lbl_805632B0;
    else
        lbl_8055B598 = lbl_805632B4;
    lbl_8055EE04 = arg0;
    buffer = fn_8012850C(0x800, lbl_8033C37C);
    *(void **)((char *)arg0 + 4) = buffer;
    memset(buffer, 0, 0x800);
    fn_802E6B04();
    return 1;
}

void fn_8020A8E8(void *arg0) {
    int *list = *(int **)((char *)arg0 + 4);
    int i = 0;
    int off = 0;
    fn_802E6B34();
    while (i < 0x200) {
        if (*(int *)((char *)list + off) != 0) {
            fn_802E317C(lbl_8033C388);
        }
        i++;
        off += 4;
    }
    fn_80128670(*(void **)((char *)arg0 + 4));
    *(int *)((char *)arg0 + 4) = 0;
    lbl_8055EE04 = 0;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020A978(void *arg0) {
    class Dispatch {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void clear();
        virtual int state();
    };
    register int offset = 0;
    register int count = 0;
    Dispatch *object;

    do {
        object = *(Dispatch **)((char *)*(void **)((char *)arg0 + 4) + offset);
        if (object != 0) {
            if (object->state() != 3) {
                object = *(Dispatch **)((char *)*(void **)((char *)arg0 + 4) + offset);
                object->clear();
            }
        }
        count++;
        offset += 4;
    } while (count < 0x200);
    fn_802E6264();
}
#pragma cplusplus reset
#pragma pop

#pragma scheduling on

extern void fn_802E59BC(void *);
extern void fn_802E5950(int, int);
extern void fn_802E6138(void);
extern void fn_802E61D8(void *);
void fn_8020AA0C(void *arg0) {
    int value = *(int *)((char *)arg0 + 8);
    if (value != 0) {
        fn_802E61D8((void *)value);
        value = *(int *)((char *)arg0 + 0xC);
        if (value != 0) {
            fn_802E61D8((void *)value);
        }
        value = *(int *)((char *)arg0 + 0xC);
        if (value != 0) {
            ((void (*)(void *))fn_802E6138)((void *)value);
            *(int *)((char *)arg0 + 0xC) = 0;
        }
        value = *(int *)((char *)arg0 + 8);
        if (value != 0) {
            ((void (*)(void *))fn_802E6138)((void *)value);
            *(int *)((char *)arg0 + 8) = 0;
        }
    }
    *(int *)((char *)arg0 + 4) = 3;
    *((unsigned char *)arg0 + 0x3E) = 0;
}

int fn_8020AA98(void *arg0) { volatile int *p = (volatile int *)((char *)arg0 + 4); if (*p == 1 && *((unsigned char *)arg0 + 0x3E) != 0) return 2; return *p; }

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
extern "C" void fn_8020AAC0(int unused, int arg1) {
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
    char *recordBase;
    List *list = (List *)fn_80131808(lbl_8033C3B4);
    if (list != 0) {
        recordBase = lbl_804892D0;
        Entry *entry;
        int index = 0;
        /* Scans list entries named lbl_8055B5A0, copies their string/value into records, then finalizes. */
        while ((entry = (Entry *)list->getAt(index)) != 0) {
            const char *name = entry->getName();
            if (strcmp(name, lbl_8055B5A0) == 0) {
                int recordIndex = (int)lbl_8055EE08;
                char *record = recordBase + recordIndex * 0x24;
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
            ++index;
        }
        fn_80131818(list);
    } else {
        fn_802E317C(lbl_8033C3C0);
    }
    fn_802E58B8(arg1);
}
#pragma cplusplus reset
#pragma pop
extern void fn_802E5950(int, int); void fn_8020AC0C(int arg0, int arg1, int arg2) { fn_802E5950(arg1, arg2); }

extern void fn_802E59BC(void *); void fn_8020AC18(void *arg0, int arg1) { fn_802E59BC((void *)arg1); }

extern void fn_802E5A54(void);
void fn_8020AC20(void) {
    lbl_8055EE08 = 0;
    fn_802E5A54();
}

#pragma push
#pragma processor 750
void fn_8020AC2C(void *arg0) {
 int i,j,mode,now; void *p,*handle; float volume,x,v,high,low;
 lbl_8055B590=fn_80209028();
 lbl_8055B594=fn_802091CC();
 lbl_8055EDF8++;
 now=fn_802E2C20();
 lbl_8055EE00=now-(*(int *)((char *)(arg0)+(8)));
 if(lbl_8055EE00>200U) lbl_8055EE00=200;
 (*(int *)((char *)(arg0)+(8)))=now;
 high=lbl_805632B4; low=lbl_805632B0;
 for(i=0;i<512;i++) {
 p=(*(void ** *)((char *)(arg0)+(4)))[i];
 if(p) {
 mode=1;
 switch(fn_802090CC()) {case 0: mode=0;break;case 1:break;case 2:mode=2;break;}
 fn_802E625C(mode);
 handle=(*(void * *)((char *)(p)+(8)));
 if(handle) {
 v=(*(float *)((char *)(p)+(0x1c)))*(*(float *)((char *)((*(void * *)((char *)(p)+(0x18))))+(0x20)));
 if((*(unsigned char *)((char *)(p)+(0x3e)))) volume=lbl_805632B0;
 else {if(!(*(unsigned char *)((char *)(p)+(0x3c)))) v*=lbl_8055B590;volume=lbl_8055B598*v;}
 if((*(void * *)((char *)(p)+(0xc)))) {
 x=high+-(*(float *)((char *)(p)+(0x20)));
 if(high<x)x=high;
 x=x>low?x:low;
 ((void (*)(void *,float))fn_802E61E4)(handle,volume*x);
 fn_802E61EC((*(void * *)((char *)(p)+(8))),lbl_805632B8);
 x=high+(*(float *)((char *)(p)+(0x20)));
 if(high<x)x=high;
 x=x>low?x:low;
 ((void (*)(void *,float))fn_802E61E4)((*(void * *)((char *)(p)+(0xc))),volume*x);
 fn_802E61EC((*(void * *)((char *)(p)+(0xc))),lbl_805632B4);
 }else{
 ((void (*)(void *,float))fn_802E61E4)(handle,volume);
 fn_802E61EC((*(void * *)((char *)(p)+(8))),(*(float *)((char *)(p)+(0x20))));
 }
 for(j=0;j<2;j++){
 if(j==0)handle=(*(void * *)((char *)(p)+(8)));else handle=(*(void * *)((char *)(p)+(0xc)));
 if(handle) {
 fn_802E620C(handle,(*(float *)((char *)(p)+(0x28))));
 fn_802E6234(handle,(*(float *)((char *)(p)+(0x2c))));
 fn_802E6238(handle,(*(float *)((char *)(p)+(0x30))));
 fn_802E623C(handle,(*(float *)((char *)(p)+(0x34))));
 fn_802E622C(handle,(*(float *)((char *)(p)+(0x24))));
 fn_802E6240(handle,(*(int *)((char *)(p)+(0x38))));
 }}
 }
 if((*(int *)((char *)(p)+(4)))==1) {
 (*(int *)((char *)(p)+(0x44)))++;
 if(!(*(unsigned char *)((char *)(p)+(0x3e))) && !((float)__fabs((*(float *)((char *)(p)+(0x24))))<=lbl_80558DC4)) (*(unsigned int *)((char *)(p)+(0x50)))+=lbl_8055EE00;
 if(!(*(unsigned char *)((char *)(p)+(0x3d))) && (*(unsigned int *)((char *)(p)+(0x50)))>(*(unsigned int *)((char *)(p)+(0x4c))))
 ((void (*)(void *))(*(void ***)p)[8])(p);
 }else (*(unsigned int *)((char *)(p)+(0x50)))=0;
 }
 }
 fn_802E6264();
}

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
                    { register float scale = lbl_805632C4, base = lbl_805632C0, n = (float)length;
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
void *fn_8020B1C8(void *arg0, int arg1) {
    /* Destroys a voice-sound object, releasing owned SPU resources and freeing it when requested. */
    void *oldSlot;
    int value;

    if (arg0 != 0) {
        oldSlot = *(void **)((char *)arg0 + 8);
        *(void **)arg0 = (void *)lbl_8033C3F4;
        if (oldSlot != 0)
            fn_802E61D8(oldSlot);
        value = *(int *)((char *)arg0 + 0xC);
        if (value != 0)
            fn_802E61D8((void *)value);
        value = *(int *)((char *)arg0 + 0xC);
        if (value != 0) {
            ((void (*)(void *))fn_802E6138)((void *)value);
            *(int *)((char *)arg0 + 0xC) = 0;
        }
        value = *(int *)((char *)arg0 + 8);
        if (value != 0) {
            ((void (*)(void *))fn_802E6138)((void *)value);
            *(int *)((char *)arg0 + 8) = 0;
        }
        value = *(int *)((char *)arg0 + 0x14);
        if (value != 0)
            fn_802E5D5C((void *)value);
        value = *(int *)((char *)arg0 + 0x10);
        if (value != 0) {
            fn_802E5D5C((void *)value);
            ((void (*)(void *, int, int))fn_8020B2BC)(lbl_8055EE04, (int)arg0, *(int *)((char *)arg0 + 0x40));
        }
        if (arg1 > 0)
            ((void (*)(void *))fn_8020A800)(arg0);
    }
    return arg0;
}
#pragma scheduling on

#pragma pop

int fn_8020B2A8(void *arg0) {
    return *(int *)((char *)arg0 + 0x10) != 0;
}

void fn_8020B2BC(void *arg0, int arg1, int arg2) {
    int *ptr = *(int **)((unsigned char *)arg0 + 4);
    ptr[arg2] = 0;
}

void fn_8020B2D0(void) {

}

extern unsigned char lbl_8033C520[];
extern unsigned char lbl_80489BD0[];
extern int fn_80128668(void);
int fn_8020B2D4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void *fn_8020B314(void) {
    return lbl_8033C520;
}

void fn_8020B320(void) {
    volatile unsigned char *p = lbl_80489BD0;
    p[0] = 0;
    *(volatile int *)(p + 4) = 0;
    *(volatile int *)(p + 8) = 0x20;
}

void fn_8020B340(void) {
    fn_802E5824();
}

void fn_8020B344(void) {
    fn_802E5828();
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8020B348(void *arg0) {
    class Obj {
    public:
        virtual void f(int);
    };
    if (arg0 == 0) return;
    ((Obj *)arg0)->f(1);
}

// ---------------------------------------------------------------------------
// One sound of the sound player: 0x54 bytes allocated as "Voicesnd" by
// fn_8020AF18, with the vtable lbl_8033C3F4.
//     +0x08 fn_8020B1C8  destroy
//     +0x10 fn_8020B2A8  has a sound loaded
//     +0x14 fn_8020B874  load another sound by name
//     +0x18 fn_8020B368  play once
//     +0x1C fn_8020B5EC  play, looping
//     +0x20 fn_8020AA0C  release the voices
//     +0x24 fn_8020AA98  state
//     +0x28 fn_8020B908  mute
//     +0x2C fn_8020B9D4  unmute
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
extern "C" void fn_8020B368(void *arg0) {
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
/**
 * Starts the sound and loops it (vtable slot +0x1C of a Voicesnd object).
 *
 * Grabs a voice for the sound, plus one for its second resource when the
 * sound has one, and starts them looping. Before that the mix values are
 * handed to the sound library: the volume is the sound's own times its
 * group's, scaled by the master volume and, unless the sound is flagged
 * unscaled, by the scale refreshed every frame; a sound with two resources is
 * played hard left and hard right with the pan splitting the volume between
 * them. The playing counters start over.
 */
extern "C" void fn_8020B5EC(void *arg0) {
    VoiceSnd *snd = (VoiceSnd *)arg0;
    float master, gain, side;
    int i;
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
int fn_8020B874(void *object, void *name) {
    int result = 0;
    void *created = fn_802E5AE8(name);
    if (created != 0) {
        fn_802E5D5C(*(void **)((char *)object + 0x10));
        *(void **)((char *)object + 0x10) = created;
        *(void **)((char *)object + 0x18) = fn_8020A6AC(name);
        result = 1;
    } else {
        fn_802E30C8(lbl_8033C4F0, name);
    }
    return result;
}

extern void fn_802E61E4(float);
extern int lbl_8055EDFC;
extern float lbl_805632B0;
void fn_8020B908(void *arg0) {
    if (*((unsigned char *)arg0 + 0x3E) == 0 && *(int *)((char *)arg0 + 4) != 3) {
        *((unsigned char *)arg0 + 0x3E) = 1;
        lbl_8055EDFC++;
        if (*(void **)((char *)arg0 + 8) != 0) {
            fn_802E61D8(*(void **)((char *)arg0 + 8));
            if (*(void **)((char *)arg0 + 0xC) != 0)
                fn_802E61D8(*(void **)((char *)arg0 + 0xC));
            if (*(void **)((char *)arg0 + 0xC) != 0) {
                ((void (*)(void *))fn_802E6138)(*(void **)((char *)arg0 + 0xC));
                *(void **)((char *)arg0 + 0xC) = 0;
            }
            if (*(void **)((char *)arg0 + 8) != 0) {
                ((void (*)(void *))fn_802E6138)(*(void **)((char *)arg0 + 8));
                *(void **)((char *)arg0 + 8) = 0;
            }
        }
        if (*(void **)((char *)arg0 + 8) != 0)
            ((void (*)(void *, float))fn_802E61E4)(*(void **)((char *)arg0 + 8), lbl_805632B0);
        if (*(void **)((char *)arg0 + 0xC) != 0)
            ((void (*)(void *, float))fn_802E61E4)(*(void **)((char *)arg0 + 0xC), lbl_805632B0);
    }
}

extern void *fn_802E6058(int);
extern void fn_802E6ABC(int);
extern void fn_80207938(void);
extern void fn_802E61BC(void *);
extern void fn_802E61A8(void *);
#pragma push
#pragma processor 750
void fn_8020B9D4(void *arg0) {
    char *p = (char *)arg0;
    float f31, f1, f0;
    int i;
    void *h;
    void *h8;
    if (*(unsigned char *)(p + 0x3e) != 0) {
        *(unsigned char *)(p + 0x3e) = 0;
        if (*(int *)(p + 4) == 1 && *(void **)(p + 8) == 0) {
            if (*(int *)(p + 0x10) != 0 && *(void **)(p + 8) == 0) {
                *(void **)(p + 8) = fn_802E6058(*(int *)(p + 0x10));
                if (*(void **)(p + 8) == 0) {
                    fn_802E6ABC(*(int *)(p + 0x10));
                    fn_80207938();
                } else if (*(int *)(p + 0x14) != 0) {
                    *(void **)(p + 0xc) = fn_802E6058(*(int *)(p + 0x14));
                    if (*(void **)(p + 0xc) == 0) {
                        ((void (*)(void *))fn_802E6138)(*(void **)(p + 8));
                        *(void **)(p + 8) = 0;
                    }
                }
            }
            h8 = *(void **)(p + 8);
            if (h8 != 0) {
                f1 = *(float *)(p + 0x1c) * *(float *)(*(char **)(p + 0x18) + 0x20);
                if (*(unsigned char *)(p + 0x3e) != 0) {
                    f31 = lbl_805632B0;
                } else {
                    if (*(unsigned char *)(p + 0x3c) != 0) {
                    } else {
                        f1 = f1 * lbl_8055B590;
                    }
                    f31 = lbl_8055B598 * f1;
                }
                if (*(void **)(p + 0xc) != 0) {
                    f1 = lbl_805632B4;
                    f0 = f1 + -*(float *)(p + 0x20);
                    f1 = (f1 < f0) ? f1 : f0;
                    f1 = (f1 > lbl_805632B0) ? f1 : lbl_805632B0;
                    fn_802E61E4(f31 * f1);
                    fn_802E61EC(*(void **)(p + 8), lbl_805632B8);
                    f1 = lbl_805632B4;
                    f0 = f1 + *(float *)(p + 0x20);
                    f1 = (f1 < f0) ? f1 : f0;
                    f1 = (f1 > lbl_805632B0) ? f1 : lbl_805632B0;
                    fn_802E61E4(f31 * f1);
                    fn_802E61EC(*(void **)(p + 0xc), lbl_805632B4);
                } else {
                    fn_802E61E4(f31);
                    fn_802E61EC(*(void **)(p + 8), *(float *)(p + 0x20));
                }
                i = 0;
                do {
                    if (i == 0) h = *(void **)(p + 8);
                    else h = *(void **)(p + 0xc);
                    if (h != 0) {
                        fn_802E620C(h, *(float *)(p + 0x28));
                        fn_802E6234(h, *(float *)(p + 0x2c));
                        fn_802E6238(h, *(float *)(p + 0x30));
                        fn_802E623C(h, *(float *)(p + 0x34));
                        fn_802E622C(h, *(float *)(p + 0x24));
                        fn_802E6240(h, *(int *)(p + 0x38));
                    }
                    i++;
                } while (i < 2);
                if (*(unsigned char *)(p + 0x3d) != 0) {
                    fn_802E61BC(*(void **)(p + 8));
                    if (*(void **)(p + 0xc) != 0) fn_802E61BC(*(void **)(p + 0xc));
                } else {
                    fn_802E61A8(*(void **)(p + 8));
                    if (*(void **)(p + 0xc) != 0) fn_802E61A8(*(void **)(p + 0xc));
                }
            }
        }
    }
}
#pragma pop
void fn_8020BC50(void *arg0, float farg0) { *(float *)((char *)arg0 + 0x24) = farg0; }

typedef float f32;
typedef signed int s32;
void fn_8020BC58(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x1C) = farg0; }

s32 fn_8020BC60(void) { return 0; }

void fn_8020BC68(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x20) = farg0; }

void fn_8020BC70(void *arg0, f32 farg0) {
    *(f32 *)((signed char *)arg0 + 0x28) = farg0;
}

void fn_8020BC78(void *arg0, f32 farg0) {
    *(f32 *)((signed char *)arg0 + 0x2C) = farg0;
}

void fn_8020BC80(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x30) = arg1;
}

void fn_8020BC88(void *arg0, float arg1) {
    *(float *)((char *)arg0 + 0x34) = arg1;
}

void fn_8020BC90(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x38) = arg1;
}

#pragma scheduling invalid_target
void fn_8020BC98(void) {
    fn_802E317C(lbl_8033C510);
}

float fn_8020BCA8(void *arg0) {
    return *(float *)((char *)arg0 + 0x48);
}

void fn_8020BCB0(void) {

}

void fn_8020BCB4(void) {

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
