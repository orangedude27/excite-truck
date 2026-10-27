// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef signed int s32;
typedef float f32;

namespace nw4hbm {
namespace snd {
namespace detail {
class Channel {
public:
    Channel();
};
}
}
}

extern "C" void fn_800EB3AC(void *);
extern "C" void fn_800EC890(void *);
extern float lbl_80560FC0;
extern "C" unsigned char lbl_8055DE28;
extern "C" char lbl_80412778[];
extern "C" char lbl_8040EC78[];
extern "C" char lbl_80322B0C[];
extern "C" char lbl_80322AE4[];
extern "C" char lbl_80322AD8[];
extern "C" char lbl_80322AB4[];
extern "C" void __register_global_object(void *, void *, void *, void *, void *, void *);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...) __attribute__((noreturn));
extern "C" int __dt__Q46nw4hbm3snd6detail14ChannelManagerFv(int, int);
extern int SetPriority__Q46nw4hbm3snd6detail7AxVoiceFi(void *, int);
extern "C" int fn_800EC8B4(void *);
extern "C" int fn_800EB41C(void *);
extern "C" int Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(void *, const void *);
extern "C" int fn_800E519C(void *);
extern void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, int);
extern void *fn_80128668(void *);
extern "C" void *__ct__Q46nw4hbm3snd6detail7ChannelFv(void *arg0) {
    register void *object asm("r29") = arg0;
    int zero = 0;

    *(int *)((char *)object + 0x0) = zero;
    *(int *)((char *)object + 0x4) = zero;
    fn_800EB3AC((char *)object + 0x8);
    fn_800EC890((char *)object + 0x20);
    float initialVolume = lbl_80560FC0;
    *(int *)((char *)object + 0x30) = zero;
    *(float *)((char *)object + 0x34) = initialVolume;
    *((unsigned char *)object + 0x39) = zero;
    *((unsigned char *)object + 0x3A) = zero;
    *((unsigned char *)object + 0x3B) = zero;
    *((unsigned char *)object + 0xC4) = zero;
    *((unsigned char *)object + 0xC5) = zero;
    *(unsigned short *)((char *)object + 0xC6) = zero;
    *(unsigned short *)((char *)object + 0xC8) = zero;
    *(int *)((char *)object + 0xE0) = zero;
    if ((signed char)lbl_8055DE28 == 0) {
        char *managerName = lbl_8040EC78;
        char *globalManager = lbl_80412778;
        *(volatile int *)lbl_80412778 = zero;
        *(void * volatile *)(globalManager + 0x4) = 0;
        void *head = globalManager + 0x4;
        void *tail = globalManager + 0x10;
        *(void * volatile *)(globalManager + 0x8) = 0;
        *(void * volatile *)(globalManager + 0x10) = 0;
        *(void * volatile *)(globalManager + 0x14) = 0;
        *(void **)(globalManager + 0x4) = head;
        *(void **)(globalManager + 0x8) = head;
        *(int *)(globalManager + 0xC) = zero;
        *(void **)(globalManager + 0x10) = tail;
        *(void **)(globalManager + 0x14) = tail;
        ((void (*)(void *, void *, void *, void *, void *))__register_global_object)(
            globalManager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv,
            managerName, tail, head);
        lbl_8055DE28 = 1;
    }
    register char *manager asm("r30") = lbl_80412778;
    if (object == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322B0C, 0x43, lbl_80322AE4);
    register void *head asm("r31") = manager + 4;
    if (object == 0)
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8, 0x233, lbl_80322AB4);
    void *iterator = head;
    Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(
        manager, &iterator, object);
    return object;
}

extern "C" int __dt__Q46nw4hbm3snd6detail14ChannelManagerFv(int arg0, int arg1) {
    if (arg0 != 0) {
        if (arg0 + 0xC != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((void *)(arg0 + 0xC), 0);
        }
        if (arg0 != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((void *)arg0, 0);
        }
        if (arg1 > 0) {
            fn_80128668((void *)arg0);
        }
    }
    return arg0;
}

extern "C" void __register_global_object(void*, void*, void*, void*, void*, void*);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void*, void*);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...) __attribute__((noreturn));
extern "C" unsigned char lbl_8055DE28;
extern "C" char lbl_80412778[];
extern "C" char lbl_8040EC78[];
extern "C" char lbl_80322A78[];
extern "C" char lbl_80322AA0[];
extern "C" char lbl_80322AB4[];
extern "C" char lbl_80322AD8[];
extern "C" int __dt__Q46nw4hbm3snd6detail7ChannelFv(void* arg0, int arg1) {
    if (arg0 != 0) {
        if ((signed char)lbl_8055DE28 == 0) {
            void* manager = lbl_80412778;
            *(volatile void**)((char*)manager + 4) = 0;
            void* head = (char*)manager + 4;
            void* tail = (char*)manager + 0x10;
            *(volatile void**)((char*)manager + 8) = 0;
            *(volatile void**)((char*)manager + 0x10) = 0;
            *(volatile void**)((char*)manager + 0x14) = 0;
            *(volatile int*)lbl_80412778 = 0;
            *(void**)((char*)manager + 4) = head;
            *(void**)((char*)manager + 8) = head;
            *(int*)((char*)manager + 0xC) = 0;
            *(void**)((char*)manager + 0x10) = tail;
            *(void**)((char*)manager + 0x14) = tail;
            __register_global_object(manager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv, lbl_8040EC78, manager, tail, head);
            lbl_8055DE28 = 1;
        }
        void* list = lbl_80412778;
        if (arg0 == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AA0, 0x54, lbl_80322A78);
        if (arg0 == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8, 0x233, lbl_80322AB4);
        Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(list, arg0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return (int)arg0;
}

extern float lbl_80560FC0;
extern float lbl_80560FC4;
extern void fn_800EB3E4(void *, void *, unsigned long, float);
extern void fn_800EC890(void *);
extern "C" void InitParam__Q46nw4hbm3snd6detail7ChannelFPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(
    void *arg0, void (*arg1)(void *, int, unsigned long), unsigned long arg2) {
    // Fix note: resets channel callback/timing state and initializes both embedded voice helpers.
    int zero = 0, one = 1, sixty = 0x3C;
    unsigned char ff = 0xFF;
    float a = lbl_80560FC0, b = lbl_80560FC4;
    *(int *)((char *)arg0 + 0xE4) = zero;
    *(void (**)(void *, int, unsigned long))((char *)arg0 + 0xD8) = arg1;
    *(unsigned long *)((char *)arg0 + 0xDC) = arg2;
    *((unsigned char *)arg0 + 0x39) = 0;
    *((unsigned char *)arg0 + 0x3C) = one;
    *(int *)((char *)arg0 + 0xD4) = zero;
    *(int *)((char *)arg0 + 0xCC) = sixty;
    *(int *)((char *)arg0 + 0xD0) = sixty;
    *(float *)((char *)arg0 + 0xB4) = b;
    *(float *)((char *)arg0 + 0xB8) = a;
    *(float *)((char *)arg0 + 0xBC) = a;
    *(float *)((char *)arg0 + 0xC0) = b;
    *(float *)((char *)arg0 + 0x40) = b;
    *(float *)((char *)arg0 + 0xA4) = a;
    *(float *)((char *)arg0 + 0x44) = b;
    *(float *)((char *)arg0 + 0x48) = a;
    *(float *)((char *)arg0 + 0x4C) = a;
    *(float *)((char *)arg0 + 0x50) = a;
    *(float *)((char *)arg0 + 0x54) = a;
    *(float *)((char *)arg0 + 0x58) = a;
    *(int *)((char *)arg0 + 0x5C) = one;
    *(float *)((char *)arg0 + 0x60) = b;
    *(float *)((char *)arg0 + 0x64) = a;
    *(float *)((char *)arg0 + 0x68) = a;
    *(float *)((char *)arg0 + 0x6C) = a;
    *(float *)((char *)arg0 + 0x70) = a;
    *(float *)((char *)arg0 + 0x74) = b;
    *(float *)((char *)arg0 + 0x84) = a;
    *(float *)((char *)arg0 + 0x94) = a;
    *(float *)((char *)arg0 + 0x78) = b;
    *(float *)((char *)arg0 + 0x88) = a;
    *(float *)((char *)arg0 + 0x98) = a;
    *(float *)((char *)arg0 + 0x7C) = b;
    *(float *)((char *)arg0 + 0x8C) = a;
    *(float *)((char *)arg0 + 0x9C) = a;
    *(float *)((char *)arg0 + 0x80) = b;
    *(float *)((char *)arg0 + 0x90) = a;
    *(float *)((char *)arg0 + 0xA0) = a;
    *((unsigned char *)arg0 + 0xC4) = ff;
    *((unsigned char *)arg0 + 0xC5) = ff;
    *(unsigned short *)((char *)arg0 + 0xC6) = zero;
    *(unsigned short *)((char *)arg0 + 0xC8) = zero;
    *(float *)((char *)arg0 + 0xA8) = a;
    *(int *)((char *)arg0 + 0xB0) = zero;
    *(int *)((char *)arg0 + 0xAC) = zero;
    fn_800EB3E4((char *)arg0 + 8, arg1, arg2, b);
    fn_800EC890((char *)arg0 + 0x20);
    *((unsigned char *)arg0 + 0x38) = 0;
}

extern "C" void Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(void *arg0, const void *arg1, long arg2) {
    *(int *)((char *)arg0 + 0xD4) = arg2;
    fn_800EC8B4((char *)arg0 + 0x20);
    fn_800EB41C((char *)arg0 + 8);
    *(int *)((char *)arg0 + 0xAC) = 0;
    Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(*(void **)((char *)arg0 + 0xE0), arg1);
    fn_800E519C(*(void **)((char *)arg0 + 0xE0));
    *(signed char *)((char *)arg0 + 0x3A) = 1;
}

extern "C" char lbl_803228E8[];
extern "C" char lbl_80322924[];
extern "C" char lbl_80322A3C[];
extern "C" char lbl_80322A64[];
extern "C" void Stop__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" void Free__Q46nw4hbm3snd6detail7AxVoiceFv(void *);
extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern "C" void Stop__Q46nw4hbm3snd6detail7ChannelFv(void *arg0) {
    // Fix note: stops and frees the active voice, updates manager lists, and calls the channel callback while interrupts are disabled.
    void *voice, *callback;
    int enabled;
    char *manager;
    void *head, *tail, *iterator;
    enabled = OSDisableInterrupts();
    voice = *(void **)((char *)arg0 + 0xE0);
    if (!voice) { OSRestoreInterrupts(enabled); return; }
    Stop__Q46nw4hbm3snd6detail7AxVoiceFv(voice);
    Free__Q46nw4hbm3snd6detail7AxVoiceFv(*(void **)((char *)arg0 + 0xE0));
    *(void **)((char *)arg0 + 0xE0) = 0;
    if (*(unsigned char *)((char *)arg0 + 0x3B)) {
        *(unsigned char *)((char *)arg0 + 0x39) = 0;
        *(unsigned char *)((char *)arg0 + 0x3A) = 0;
        *(unsigned char *)((char *)arg0 + 0x3B) = 0;
        if ((signed char)lbl_8055DE28 == 0) {
            manager = lbl_80412778; head = manager + 4; tail = manager + 0x10;
            *(int *)manager = 0; *(void **)(manager+4)=0; *(void **)(manager+8)=0;
            *(void **)(manager+0x10)=0; *(void **)(manager+0x14)=0;
            *(void **)(manager+4)=head; *(void **)(manager+8)=head; *(int *)(manager+0xC)=0;
            *(void **)(manager+0x10)=tail; *(void **)(manager+0x14)=tail;
            __register_global_object(manager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv, lbl_8040EC78, manager, tail, head);
            lbl_8055DE28=1;
        }
        manager=lbl_80412778;
        if (!arg0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322A64,0x77,lbl_80322A3C);
        if (*(int *)(manager+0xC)) {
            if (!arg0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8,0x233,lbl_80322AB4);
            Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(manager+0xC,arg0);
            if (!arg0) Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8,0x233,lbl_80322AB4);
            iterator=head;
            Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(manager,&iterator,arg0);
        }
    }
    callback=*(void **)((char *)arg0+0xD8);
    if (callback) ((void (*)(void *,int,unsigned long))callback)(arg0,0,*(unsigned long *)((char *)arg0+0xDC));
    OSRestoreInterrupts(enabled);
}

extern "C" void fn_800EA880(void *arg0, int arg1) {
    int value = *(int *)((char *)arg0 + 0xAC) + arg1;
    int limit = *(int *)((char *)arg0 + 0xB0);
    *(int *)((char *)arg0 + 0xAC) = value;
    if (value > limit) {
        *(int *)((char *)arg0 + 0xAC) = limit;
    }
}

extern "C" void fn_800EA8A0(void *arg0, int arg1, signed char arg2, float farg0) {
    *(float *)((char *)arg0 + 0xA8) = farg0;
    *(int *)((char *)arg0 + 0xB0) = arg1;
    *(signed char *)((char *)arg0 + 0x3C) = arg2;
    *(int *)((char *)arg0 + 0xAC) = 0;
}

extern "C" void VoiceCallback__Q46nw4hbm3snd6detail7ChannelFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv(void *arg0,int arg1,void *arg2) {
 register void *voice=arg0; int status=arg1; char *v=(char*)arg2; char *manager; void *head; void (*cb)(void*,int,unsigned long);
 if(!v) Panic__Q26nw4hbm2dbFPCciPCce(lbl_803228E8,0x1c4,lbl_80322924);
 switch(status) { case 0: status=2; Free__Q46nw4hbm3snd6detail7AxVoiceFv(voice); break; case 1: status=3; Free__Q46nw4hbm3snd6detail7AxVoiceFv(voice); break; default: if(status<0 || status>=4) status=1; }
 cb=*(void (**)(void*,int,unsigned long))(v+0xd8); if(cb)cb(v,status,*(unsigned long*)(v+0xdc));
 *(int*)(v+0xe0)=0; v[0x39]=0;v[0x3a]=0;v[0x3b]=0;
 if((signed char)lbl_8055DE28==0){manager=lbl_80412778;head=manager+4;*(int*)manager=0;*(void**)(manager+4)=0;*(void**)(manager+8)=0;*(void**)(manager+0x10)=0;*(void**)(manager+0x14)=0;*(void**)(manager+4)=head;*(void**)(manager+8)=head;*(int*)(manager+0xc)=0;*(void**)(manager+0x10)=manager+0x10;*(void**)(manager+0x14)=manager+0x10;__register_global_object(manager,(void*) &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv,lbl_8040EC78,manager,manager+0x10,head);lbl_8055DE28=1;}
 manager=lbl_80412778;if(!v)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322A64,0x77,lbl_80322A3C);
 if(*(int*)(manager+0xc)){if(!v)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8,0x233,lbl_80322AB4);Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(manager+0xc,v);if(!v)Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322AD8,0x233,lbl_80322AB4);head=manager+4;Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(manager,&head,v);}
}

extern "C" void fn_800EAD00(void *arg0) {
    if (arg0 != 0) {
        *(int *)((char *)arg0 + 0xD8) = 0;
        *(int *)((char *)arg0 + 0xDC) = 0;
    }
}

extern "C" char lbl_803229AC[];
extern "C" char lbl_803229D0[];
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...) __attribute__((noreturn));
extern "C" void Update__Q46nw4hbm3snd6detail7ChannelFb(void *, int);
#pragma use_lmw_stmw off
extern "C" void UpdateAllChannel__Q46nw4hbm3snd6detail7ChannelFv(void) {
    char *manager;
    int zero = 0;
    int one = 1;
    void *head;
    void *end;
    void *node;
    void *current;
    if ((signed char)lbl_8055DE28 == 0) {
        manager = lbl_80412778;
        head = manager + 0x10;
        *(void **)(manager + 4) = (void *)zero;
        void *initTail = manager + 4;
        *(void **)(manager + 8) = (void *)zero;
        *(void **)(manager + 0x10) = (void *)zero;
        *(void **)(manager + 0x14) = (void *)zero;
        *(int *)lbl_80412778 = zero;
        *(void **)(manager + 4) = initTail;
        *(void **)(manager + 8) = initTail;
        *(int *)(manager + 0xC) = zero;
        *(void **)(manager + 0x10) = head;
        *(void **)(manager + 0x14) = head;
        ((void (*)(void *, void *, void *))__register_global_object)(manager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv, lbl_8040EC78);
        lbl_8055DE28 = one;
    }
    manager = lbl_80412778;
    end = manager + 0x10;
    node = *(void **)(manager + 0x10);
    do {
        current = node;
        node = *reinterpret_cast<void **>(node);
        if (current == 0)
            Panic__Q26nw4hbm2dbFPCciPCce(lbl_803229D0, 0x23D, lbl_803229AC);
        Update__Q46nw4hbm3snd6detail7ChannelFb(current, 1);
        if ((signed char)lbl_8055DE28 == 0) {
            head = manager + 4;
            *(void **)(manager + 4) = (void *)zero;
            void *initTail = manager + 0x10;
            *(void **)(manager + 8) = (void *)zero;
            *(void **)(manager + 0x10) = (void *)zero;
            *(void **)(manager + 0x14) = (void *)zero;
            *(int *)lbl_80412778 = zero;
            *(void **)(manager + 4) = head;
            *(void **)(manager + 8) = head;
            *(int *)(manager + 0xC) = zero;
            *(void **)(manager + 0x10) = initTail;
            *(void **)(manager + 0x14) = initTail;
            ((void (*)(void *, void *, void *, void *, void *))__register_global_object)(manager, &__dt__Q46nw4hbm3snd6detail14ChannelManagerFv, lbl_8040EC78, initTail, head);
            lbl_8055DE28 = one;
        }
    } while (node != end);
}
extern void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, int);
extern void *fn_80128668(void *);
extern "C" {
extern char lbl_803228E8[];
extern char lbl_803229AC[];
extern char lbl_803229D0[];
extern char lbl_803229DC[];
extern char lbl_80322A00[];
extern char lbl_80322A0C[];
extern char lbl_80322A30[];
extern char lbl_80322AB4[];
extern char lbl_80322AD8[];
extern char lbl_8040EC78[];
extern char lbl_80412778[];
extern unsigned char lbl_8055DE28;
extern void __register_global_object(void*,void*,void*,void*,void*,void*);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void Erase__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8Iterator(void*,void**);
extern void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void*,void**,void*);
extern void InitParam__Q46nw4hbm3snd6detail7ChannelFPFPQ46nw4hbm3snd6detail7ChannelQ56nw4hbm3snd6detail7Channel21ChannelCallbackStatusUl_vUl(void*,void(*)(void*,int,unsigned long),unsigned long);
extern int __dt__Q46nw4hbm3snd6detail14ChannelManagerFv(int,int);
extern char lbl_803229AC[];
extern char lbl_803229D0[];
extern char lbl_803229DC[];
extern char lbl_80322A00[];
extern char lbl_80322A0C[];
extern char lbl_80322A30[];
extern char lbl_80322AB4[];
extern char lbl_80322AD8[];
extern char lbl_8040EC78[];
extern void Warning__Q26nw4hbm2dbFPCciPCce(const char*, int, const char*, ...);
extern void *Instance__15EmissionManagerFv(void);
extern int fn_800E3954(int,int,int,void*,void*);
extern void VoiceCallback__Q46nw4hbm3snd6detail7ChannelFPQ46nw4hbm3snd6detail7AxVoiceQ56nw4hbm3snd6detail7AxVoice14CallbackStatusPv(void*,int,void*);
}
