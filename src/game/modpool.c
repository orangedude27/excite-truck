// modpool — model pool ("modpool: oldest_model is NULL", loadpool).
// Recovered TU window 0x802CE3A4..0x802CE858+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CE858 (+ .ctors slot 0x802ED5B8) remains in
// auto/text_802CE858_.c pending a promotion pass.
int fn_80128668(void *);
int fn_80128670(int);
int fn_801342B0(int, int);
void fn_802C6FB4(int);
void fn_802C703C(int);

int fn_80128668(void *);
int fn_80128670(int);
int fn_801342B0(int, int);
char *strcpy(char *, const char *);
void fn_802C6FB4(int);
void fn_802C703C(int);
extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8013420C(int, int);
extern void *fn_8002F37C(void *, int, int, int);
extern char lbl_8055D0A8[];
extern char lbl_8034BCE4[];
extern char lbl_8034BCD8[];
extern void fn_802CE474(void *);
__declspec(section ".sdata") extern char lbl_8055D0A8[];
void *fn_802CE3A4(int slotCount, int arg1, int arg2) {
    int count;
    void *pool;
    void *data;
    void *storage;

    /* Allocates and initializes a pooled manager: inner data block, backing storage, and a table of slotCount entries. */
    pool = fn_801284F8(0x14, lbl_8055D0A8);
    if (pool != 0) {
        *(int *)((char *)pool + 8) = slotCount;
        *(int *)((char *)pool + 0xC) = arg1;
        data = fn_801284F8(0x10, lbl_8034BCE4);
        if (data != 0) data = ((void *(*)(void *, int, int))fn_8013420C)(data, *(int *)((char *)pool + 0xC), arg2);
        *(void **)((char *)pool + 4) = data;
        count = *(int *)((char *)pool + 8);
        storage = fn_8012850C((count << 6) + 0x10, lbl_8034BCD8);
        *(void **)pool = ((void *(*)(void *, void *, int, int, int))fn_8002F37C)(storage, fn_802CE474, 0, 0x40, count);
        *(int *)((char *)pool + 0x10) = 0;
    }
    return pool;
}

void fn_802CE474(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(unsigned char *)arg0 = 0;
    *(int *)((char *)arg0 + 0x38) = 0;
    *(int *)((char *)arg0 + 0x34) = -1;
    *(int *)((char *)arg0 + 0x30) = 0;
    *(int *)((char *)arg0 + 0x2C) = -1;
    *(int *)((char *)arg0 + 0x3C) = -1;
}

void fn_802CE49C(void *arg0) {
    int value;
    if (arg0 != 0) {
        value = *(int *)arg0;
        if (value != 0) {
            fn_80128670(value - 0x10);
        }
        fn_801342B0(*(int *)((char *)arg0 + 4), 1);
        fn_80128668(arg0);
    }
}

int fn_801345A4(int, int);
void fn_8013436C(int);
void fn_802E30C8(const char *, ...);
extern char lbl_8034BCF0[];
#pragma push
#pragma scheduling invalid_target
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void fn_802CE4F4(void *arg0, int arg1) {
 /* Reclaim model pool slot when full: clear finished entries, evict oldest idle (state 2) if needed, then service manager. */
 void *entry;
 int best;
 int active;
 int i;
 int offset;
 void *manager=arg0;
 void *selected;
 active=0;
 selected=0;
 best=-1;
 i=0;
 offset=0;
 while (i < *(int *)((char *)manager+8)) {
  entry=(char *)*(void **)manager+offset;
  if (*(int *)((char *)entry+0x38)==3 &&
      fn_801345A4(*(int *)((char *)manager+4), *(int *)((char *)entry+0x2C))) {
   *(int *)((char *)entry+0x38)=0;
   *(int *)((char *)entry+0x2C)=-1;
  }
  if (*(int *)((char *)entry+0x38)!=0) active++;
  if (*(int *)((char *)entry+0x38)==2) {
   int delta=*(int *)((char *)manager+0x10)-*(int *)((char *)entry+0x3C);
   if (delta>best || selected==0) { best=delta; selected=entry; }
  }
  offset+=0x40; i++;
 }
 if (*(int *)((char *)manager+0xC)-active<1) {
  if (selected!=0) {
   if (*(int *)((char *)selected+0x38)==2) {
    fn_802C6FB4(*(int *)((char *)selected+0x30));
    fn_802C703C(*(int *)((char *)selected+0x34));
    *(int *)((char *)selected+0x34)=-1;
    *(int *)((char *)selected+0x30)=0;
    *(int *)((char *)selected+0x38)=3;
   }
  } else fn_802E30C8(lbl_8034BCF0, *(int *)((char *)manager+0x10));
 }
 fn_8013436C(*(int *)((char *)manager+4));
}
#pragma pop
#pragma scheduling on

#pragma push
#pragma scheduling invalid_target
void *fn_802CE630(void *arg0, const char *arg1, int arg2) {
    int cnt = *(int *)((char *)arg0 + 8);
    int off = 0;
    unsigned char *entry;
    void *ret = 0;
    while (cnt > 0) {
        entry = (unsigned char *)*(char **)arg0 + off;
        if (*entry == 0 && *(int *)(entry + 0x38) == 0) {
            entry[0] = 1;
            *(void **)(entry + 4) = arg0;
            ret = strcpy((char *)entry + 8, arg1);
            *(int *)(entry + 0x28) = arg2;
            return ret;
        }
        off += 0x40;
        cnt--;
    }
    return ret;
}
#pragma pop
void fn_802CE6C0(void *arg0) {
    if (*(int *)((char *)arg0 + 0x38) == 2 && *(int *)((char *)arg0 + 0x38) == 2) {
        fn_802C6FB4(*(int *)((char *)arg0 + 0x30));
        fn_802C703C(*(int *)((char *)arg0 + 0x34));
        *(volatile int *)((char *)arg0 + 0x34) = -1;
        *(volatile int *)((char *)arg0 + 0x30) = 0;
        *(volatile int *)((char *)arg0 + 0x38) = 3;
    }
    *(unsigned char *)arg0 = 0;
}

int fn_802CE728(void *arg0) {
    if (*(int *)((char *)arg0 + 0x38) == 2) {
        return *(int *)((char *)arg0 + 0x34);
    }
    return -1;
}

extern void fn_802CE7D4(int, int, void *);
extern int fn_80134424(int, void *, int, int *, void *, void *, int, int);
#pragma push
#pragma scheduling invalid_target
void fn_802CE744(void *arg0) {
    char *manager;
    char *entry;
    int value;
    int result;
    int sp8;
    manager = (char *)arg0;
    entry = *(char **)(manager + 4);
    value = *(int *)(entry + 0x10);
    *(int *)(manager + 0x3C) = value;
    *(int *)(entry + 0x10) = value + 1;
    if (*(int *)(manager + 0x38) == 0) {
        sp8 = 0;
        result = fn_80134424(*(int *)(entry + 4), manager + 8, 0x4D4F444C, &sp8, (void *)fn_802CE7D4, manager, 0, -1);
        if (result >= 0) {
            *(int *)(manager + 0x2C) = result;
            *(int *)(manager + 0x38) = 1;
        }
    }
}
#pragma pop
#pragma scheduling on
void fn_802CE7D4(int arg0, int arg1, void *arg2);
/* ModPool_onLoadComplete: async MODL load callback that fixes up the model resource, registers its textures, and creates a model instance if the slot is still in use. */
void fn_802CE7D4(int modelData, int dataSize, void *userData) {
#define mrModelFixupResource fn_802C61BC
#define mrModelRegisterTextures fn_802C6FA8
#define mrModelCreateInstance fn_802C6DC4
    unsigned char *slot = (unsigned char *)userData;
    if (*slot != 0) {
        *(int *)(slot + 0x30) = modelData;
        mrModelFixupResource(modelData, slot + 8);
        mrModelRegisterTextures(*(int *)(slot + 0x30));
        *(int *)(slot + 0x34) = mrModelCreateInstance(slot + 8, *(int *)(slot + 0x30), 0, 0);
        *(int *)(slot + 0x38) = 2;
    } else {
        *(int *)(slot + 0x38) = 0;
        *(int *)(slot + 0x2C) = -1;
    }
#undef mrModelCreateInstance
#undef mrModelRegisterTextures
#undef mrModelFixupResource
}

int fn_802CE850(void *arg0) {
    return *(int *)((char *)arg0 + 0x38);
}
