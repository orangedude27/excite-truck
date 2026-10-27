// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <macros.h>

typedef struct {
    u8 unk_0x0[0x1E4];
    void* unk_0x1E4;
} Unk8034EF38;

typedef struct {
    u32 unk_0x0;
    const char* unk_0x4;
    const char* unk_0x8;
} Unk802FB70C;

extern Unk8034EF38 lbl_8034EF38;
extern Unk802FB70C lbl_802FB70C[];
extern const char lbl_802FB77C[];
extern const char lbl_80558998[1];
extern const char lbl_805589A0[1];
extern const char lbl_805589A8[1];
void fn_80007DA0(void);
void fn_80279464(void);
void fn_80012778(void);
void fn_80131818(void*);
void fn_802E317C(const char*, ...);

int stricmp(const char*, const char*);
extern void qsort(void *, u32, u32, int (*)(const void *, const void *));
const char* fn_80008158(s32);
void fn_80012794(void);
void fn_80279488(void);
void fn_802E30C8(const char*, ...);
extern const char lbl_802FB7A4[];
void fn_80007D94(const char** arg0, const char** arg1) {
    stricmp(*arg0, *arg1);
}

extern void *fn_80131808(void *);
extern char lbl_802FB6E0[];
DECL_SECTION(".sdata") extern const char lbl_80558978[];
DECL_SECTION(".sdata") extern const char lbl_80558980[];
DECL_SECTION(".sdata") extern const char lbl_80558988[];
DECL_SECTION(".sdata") extern const char lbl_80558990[];
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80007DA0(void) {
    struct Config {
        virtual void unused();
        virtual void *getEntry(u32);
    };
    struct Item {
        virtual const char *getName();
        virtual void unused1();
        virtual void unused2();
        virtual const char *getValue(const char *);
        virtual void *getString(const char *, const char *);
    };
    volatile u32 *global;
    char *base;
    void *initialConfig;
    u32 index;

    base = lbl_802FB6E0;
    initialConfig = fn_80131808(base + 0x68);
    global = (volatile u32 *)&lbl_8034EF38;
    global[0x79] = (u32)initialConfig;
    index = 0;
    global[0x78] = 0;

loop:
    {
        void *config;
        Item *entry;
        void *value;
        u32 count;
        u32 entryIndex;

        config = (void *)global[0x79];
        entryIndex = index;
        index++;
        entry = (Item *)((Config *)config)->getEntry(entryIndex);
        if (entry == 0) {
            goto done;
        }
        if (stricmp(entry->getName(), lbl_80558978) != 0) {
            goto loop;
        }

        value = (void *)entry->getValue(lbl_80558980);
        *(void **)((u8 *)global + global[0x78] * 0xC) = value;

        value = entry->getString(base + 0x74, lbl_80558988);
        *(void **)((u8 *)global + global[0x78] * 0xC + 4) = value;

        value = entry->getString(lbl_80558990, lbl_80558988);
        *(void **)((u8 *)global + global[0x78] * 0xC + 8) = value;

        count = global[0x78] + 1;
        global[0x78] = count;
        if (count < 0x28) {
            goto loop;
        }
        fn_802E317C(base + 0x84);
    }

done:
    qsort(&lbl_8034EF38, *(volatile u32 *)((u8 *)&lbl_8034EF38 + 0x1E0), 0xC, (int (*)(const void *, const void *))fn_80007D94);
}
#pragma scheduling on
#pragma cplusplus reset

#pragma dont_inline on
void fn_80007F04(void) {
    Unk8034EF38* p = &lbl_8034EF38;
    fn_80131818(p->unk_0x1E4);
    p->unk_0x1E4 = 0;
}
#pragma dont_inline reset

void fn_80007F40(void) {
    fn_80007DA0();
    fn_80279464();
    fn_80012778();
}

#pragma dont_inline fn_80007F04
void fn_80007F04(void);
#pragma dont_inline fn_80007F04
void fn_80007F68(void) {
    fn_80012794();
    fn_80279488();
    fn_80007F04();
}
#pragma scheduling invalid_target
const char* fn_80007F90(u32 arg0) {
    Unk802FB70C* p = lbl_802FB70C;
    while (p->unk_0x0) {
        if (p->unk_0x0 == arg0) return p->unk_0x4;
        p++;
    }
    fn_802E317C(lbl_802FB77C, arg0);
    return lbl_80558998;
}
#pragma scheduling on
const char* fn_80007FF0(u32 arg0) {
    Unk802FB70C* p;
    u32 key;
    for (p = lbl_802FB70C; (key = p->unk_0x0) != 0; ++p) {
        if (key == arg0) return p->unk_0x8;
    }
    fn_802E317C(lbl_802FB77C, arg0);
    return lbl_805589A0;
}

#pragma scheduling invalid_target
u32 fn_80008050(const char* arg0) {
    register u32 key;
    register Unk802FB70C* p;
    for (p = lbl_802FB70C; (key = p->unk_0x0) != 0; ++p) {
        if (strcmp(p->unk_0x4, arg0) == 0) return key;
    }
    fn_802E30C8(lbl_802FB7A4, arg0);
    return 0;
}
#pragma scheduling on
u32 fn_800080D8(void) {
    return *(u32*)((u8*)&lbl_8034EF38 + 0x1E0);
}

#pragma dont_inline on
s32 fn_800080E8(arg0)
const char* arg0;
{
    s32 i = 0;
    goto compare;
body:
    if (stricmp(arg0, fn_80008158(i)) == 0) {
        return i;
    }
    i++;
compare:
    if (i < (s32)fn_800080D8()) {
        goto body;
    }
    return -1;
}
#pragma dont_inline reset

const char* fn_80008158(s32 arg0) {
    if (arg0 < 0) {
        goto done;
    }
    if (arg0 >= *(s32 *)((u8 *)&lbl_8034EF38 + 0x1E0)) {
        goto done;
    }
    return *(const char **)((u8 *)&lbl_8034EF38 + arg0 * 0xC);

done:
    return lbl_805589A8;
}

const char* fn_80008158(s32);
const char* fn_80008188(void) {
    return *(const char**)((u8*)&lbl_8034EF38 + fn_800080E8() * 0xC + 4);
}

s32 fn_800081BC(void) {
    return *(s32 *)((u8 *)&lbl_8034EF38 + fn_800080E8() * 0xC + 8);
}

s32 fn_800081F0(void *arg0) {
    s32 result;
    if (*(u32 *)((u8 *)arg0 + 0x10) & 1) goto done;
    result = *(s32 *)((u8 *)fn_8001285C(*(s32 *)arg0) + 0xC);
    return result;
done:
    return 0xC8;
}

#pragma dont_inline on
void fn_8000822C(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0) = -1;
    *(u32 *)((u8 *)arg0 + 4) = 0;
    *(u32 *)((u8 *)arg0 + 0x10) = 0;
    *(u32 *)((u8 *)arg0 + 0xC) = 0;
    *(u32 *)((u8 *)arg0 + 8) = 0;
}
#pragma dont_inline reset

void fn_8000822C(void *);
#pragma dont_inline fn_8000822C
void fn_8000824C(void *arg0, s32 arg1) {
    void *temp_r3;

    fn_8000822C(arg0);
    temp_r3 = (void *)fn_8001285C(arg1);
    *(u32 *)((u8 *)arg0) = *(u32 *)((u8 *)temp_r3);
    *(u32 *)((u8 *)arg0 + 4) = *(u32 *)((u8 *)temp_r3 + 8);
}
