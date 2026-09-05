/*
 * Bootstrap/menu initialization cluster.
 *
 * This is intentionally source-coverage-first code. The functions are bounded
 * and reviewed, but most names are still placeholder `fn_XXXXXXXX` aliases and
 * several differences are FUZZY source-shape/scheduling issues. Treat this TU as
 * a NonMatching review/promote-later cluster unless a dedicated promotion pass
 * proves section ownership and preserves the final DOL hash.
 */

#include <revolution/OS.h>

extern void fn_802E2CFC(void* out);
extern void fn_80129C80(int, u32, u32);
extern int  fn_80129D18(int, int);
extern int  fn_80278A1C(const char* fmt);
extern void fn_80130390(void);
extern void fn_8012DDA8(void);
extern void fn_8012E498(void);
extern int  fn_80005158(const char*);
extern int  sprintf(char*, const char*, ...);
extern void fn_800199B8(void);
extern int  fn_80028F94(char*, const char*, int);
extern void fn_80265D48(void);
extern void fn_80129BD4(void);
extern void fn_802E30C8(const char*, void (*)(void));
extern int  fn_80019B6C(void);
extern int  fn_80019B48(void);
extern int  fn_80019B54(void);
extern int  fn_80019B3C(void);
extern void fn_8023B6B0(void);
extern void fn_8024BE04(void);
extern void fn_801E78A0(void);
extern void fn_80129BF8(void);
extern void fn_80265D4C(void);
extern void fn_80005304(void) DECOMP_DONT_INLINE;
extern void fn_80004E20(void);
extern void fn_80004B5C(void);
extern void fn_80004CB4(void);

extern void fn_8020A634(void);
extern void fn_8020CA30(void);
extern void fn_8020CA34(void);
extern void fn_802063D8(void);
extern void fn_802062E8(void);

extern void fn_80211F4C(void);
extern void fn_80211F44(void);
extern void fn_8021031C(void);

extern void fn_802789A8(void);
extern void fn_802789AC(void);
extern void fn_802789B0(void);
extern void fn_80230090(void);
extern void fn_80230114(void);
extern void fn_80232230(void);
extern void fn_8023243C(void);
extern void fn_802E2C20(void);
extern void fn_802E47E8(void);
extern void fn_802E712C(void);
extern void fn_802E986C(void*);
extern void fn_802E9870(void*);
extern void fn_802E9874(void*);
extern void fn_802E9878(void*);
extern void fn_802E987C(void*);
extern void fn_802E9880(void*);
extern void fn_802E9884(void*);
extern void fn_802E9888(void*);
extern void fn_8023E7A8(void);
extern void fn_8023E5B4(void);
extern void fn_8023F0E8(void);
extern void fn_8023F4B8(void);
extern void fn_8023F694(void);
extern void fn_8023EEF8(void);
extern void fn_8023F2C4(void);
extern void fn_8023ED30(void);
extern void fn_8023D7CC(void);
extern void fn_8023D70C(void);
extern void fn_8023BFBC(int, int);
extern void fn_8012E81C(void*);
extern void fn_80127464(void);
extern void fn_80127434(void);

extern void fn_801303A8(void);
extern void fn_80130518(void);
extern void fn_80133024(void);
extern void fn_80133144(void);
extern void fn_80137B20(void);
extern void fn_80137BE4(void);
extern void fn_80141454(void);
extern void fn_80141458(void);
extern void fn_801AED54(void);
extern void fn_801AED58(void);
extern void fn_801E3C04(void);
extern void fn_801E3C88(void);
extern void fn_80245118(void);
extern void fn_80245124(void);
extern void fn_802C2AA8(int);
extern void fn_802C2B18(void);
extern void fn_8027DAF4(void);
extern void fn_80007F40(void);
extern void fn_80007F68(void);
extern void fn_8000D7E4(void);
extern void fn_8000D878(void);
extern void fn_8000D8C8(void);
extern void fn_8000D94C(void);
extern void fn_80012478(void);
extern void fn_800124DC(int, int, int);
extern void fn_800125C4(void);
extern void fn_80012628(void);
extern int fn_80012818(void);
extern void fn_80016354(void);
extern void fn_800163F0(void);
extern void fn_80018F40(void);
extern void fn_80018F7C(void);
extern void fn_80019864(void);
extern void fn_80019884(void);
extern void fn_8001BA78(void);
extern void fn_8001BA84(void);
extern void fn_8001EF38(void);
extern void fn_8001EFCC(void);
extern void fn_800218F4(void);
extern void fn_800218F8(void);

extern u32 lbl_8055890C;
extern u32 lbl_802FAFA0[];
extern char lbl_8034EC58[];
extern const char* lbl_802FAFD4;
extern const char lbl_802FB0B8[];
extern u32 lbl_8034EC40[];
extern u32 lbl_8055D320;
extern u32 lbl_8055D328;
extern u32 lbl_8055D32C;
extern void fn_8000D838(u32*);

extern u8* fn_80012820(int);
extern u8* fn_80012870(int, int);
extern int fn_8002B130(const char*, const char*);
DECL_SECTION(".sdata") extern const char lbl_80558918[];
DECL_SECTION(".sdata") extern u32 lbl_80558920[];

typedef struct GameVirtualObject GameVirtualObject;

typedef struct GameVirtualTable {
    void* reserved[3];
    int (*isReady)(GameVirtualObject*);
    void* reserved10;
    u32 (*getValue)(GameVirtualObject*, u32);
    const char* (*getName)(GameVirtualObject*, const char*, u32*);
} GameVirtualTable;

struct GameVirtualObject {
    GameVirtualTable* vtable;
};

void fn_800049C0(void) {
    const u32* rodata_base = (const u32*)0x802ED680;
    u32 local[16];
    u16* dp;
    u16 year_val, month_val, day_val, hour_val;
    int lang_result;
    const char** table;

    local[6] = rodata_base[0];
    local[7] = rodata_base[1];
    local[8] = rodata_base[2];
    local[9] = rodata_base[3];
    local[10] = rodata_base[4];
    local[11] = rodata_base[5];
    local[12] = rodata_base[6];
    local[13] = rodata_base[7];
    local[14] = rodata_base[8];
    local[15] = rodata_base[9];

    fn_802E2CFC(local);

    dp = (u16*)&local[1];
    year_val  = dp[0];
    month_val = dp[1];
    day_val   = dp[2];
    hour_val  = dp[3];

    fn_80129C80(6,
        ((u32)hour_val << 8) & ((u32)day_val ^ ((u32)month_val * 3600)),
        ((u32)day_val << 8) & (((u32)hour_val * 60) ^ ((u32)year_val * 43200)));

    lang_result = fn_80129D18(6, 10);

    fn_80278A1C((const char*)0x802FAF24);

    if (lang_result != 0) {
        table = (const char**)&local[6];
        fn_80278A1C(table[lang_result]);
    }
}

void fn_80004AB8(u32 val) DECOMP_DONT_INLINE {
    if (val == lbl_8055890C) {
        fn_80130390();
    }
}

void fn_80004ACC(void) {
    u32* p;
    for (p = lbl_802FAFA0; *p != 0; p++) {
        fn_80004AB8(*p);
        fn_8012DDA8();
    }
}

void fn_80004B14(void) {
    u32* p;
    for (p = lbl_802FAFA0; *p != 0; p++) {
        fn_80004AB8(*p);
        fn_8012E498();
    }
}

void fn_800052F8(void) {
    fn_80005158((const char*)0x802FB0A8);
}

extern void fn_800199B8(void);
extern int fn_80028F94(char*, const char*, int);

int fn_80004D64(char* args) {
    char* p;
    int result;

    if (args == NULL) {
        return 1;
    }

    fn_800199B8();
    for (p = args; *p != '\0'; p++) {
        result = *p;
        if (result == '-' || result == ' ' || result == '/') {
            if (fn_80028F94(p + 1, lbl_802FAFD4, 9) == 0) {
                *(u8*)0x8055F63C = 1;
            } else {
                fn_80028F94(p + 1, (char*)0x8055D9D0, 4);
            }
        }
    }

    return 1;
}

void fn_80004B5C(void) {
    fn_802E2C20();
    fn_80004ACC();
    fn_8012E81C((void*)0x802FAF30);
    fn_80133024();
    fn_802C2AA8(*(int*)0x80558900);
    fn_80127464();
    fn_80127464();
    fn_802062E8();
    fn_80230090();
    fn_801303A8();
    fn_80245118();
    fn_802E712C();
    fn_80012478();
    fn_800124DC(*(int*)0x80560100, 1, 1);
    fn_80127464();
    fn_8012E81C((void*)0x802FAF3C);
    fn_80232230();
    fn_80137B20();
    fn_80016354();
    fn_800125C4();
    fn_80127464();
    fn_800125C4();
    fn_80127464();
    fn_801E3C04();
    fn_80007F40();
    fn_8000D8C8();
    fn_8001BA78();
    fn_8001EF38();
    __AXDSPInitCallback();
    fn_80141454();
    fn_8027DAF4();
    fn_8021031C();
    fn_801AED54();
    fn_80019864();
    fn_80018F40();
    fn_802789A8();
    fn_8020CA30();
    fn_80127464();
    fn_800218F4();
    fn_80211F44();
    fn_802E986C((void*)fn_8023E7A8);
    fn_802E9870((void*)fn_8023E5B4);
    fn_802E9874((void*)fn_8023F0E8);
    fn_802E9878((void*)fn_8023F4B8);
    fn_802E987C((void*)fn_8023F694);
    fn_802E9884((void*)fn_8023EEF8);
    fn_802E9880((void*)fn_8023F2C4);
    fn_802E9888((void*)fn_8023ED30);
    fn_802789AC();
    fn_80127464();
    fn_802E47E8();
    fn_800049C0();
}

int fn_80005158(const char* name) {
    int found = 0;
    int count = 0;
    char first;

    fn_80127434();
    fn_8023D7CC();
    fn_8023D70C();

    {
        int reentrancy = *(volatile int*)0x8055D430 & 1;
        *(volatile int*)0x8055D430 |= 1;
        count = fn_80012818();
        first = lbl_8034EC58[0];

        if (first == '$' || first == '@') {
            if (!fn_80004F00(&count, &found, (const char*)&lbl_8034EC58[1])) {
                fn_802E30C8((const char*)0x802FAFF0, (void (*)(void))(uintptr_t)&lbl_8034EC58[1]);
            }
        } else if (first != '\0') {
            if (!fn_80005044(&count, &found, lbl_8034EC58)) {
                fn_802E30C8((const char*)0x802FB020, (void (*)(void))(uintptr_t)lbl_8034EC58);
            }
        } else {
            if (!fn_800050D0(&count, &found, name)) {
                fn_802E30C8((const char*)0x802FB050, (void (*)(void))(uintptr_t)name);
            }
        }

        if (found) {
            fn_8020A600();
            fn_8023BFBC(count, found);
        } else {
            if (lbl_8034EC58[0] != '\0') {
                fn_802E30C8((const char*)0x802FB07C, (void (*)(void))(uintptr_t)lbl_8034EC58);
            } else {
                fn_802E30C8((const char*)0x802FB090, (void (*)(void))(uintptr_t)name);
            }
        }

        *(volatile int*)0x8055D430 = (*(volatile int*)0x8055D430 & ~1) | (reentrancy & 1);
    }

    return 0;
}

void fn_80004CB4(void) {
    fn_8020A634();
    fn_802E9880(0);
    fn_802E9884(0);
    fn_802E9878(0);
    fn_802E9874(0);
    fn_802E986C(0);
    fn_80211F4C();
    fn_800218F8();
    fn_8020CA34();
    fn_802789B0();
    fn_80018F7C();
    fn_80019884();
    fn_801AED58();
    fn_80141458();
    fn_8000D7E4();
    fn_8001EFCC();
    fn_8001BA84();
    fn_8000D94C();
    fn_80007F68();
    fn_801E3C88();
    fn_800163F0();
    fn_80137BE4();
    fn_8023243C();
    fn_80012628();
    fn_80130518();
    fn_80245124();
    fn_80230114();
    fn_802063D8();
    fn_802C2B18();
    fn_80133144();
    fn_80004B14();
    fn_8000D878();
}

void fn_80004E20(void) {
    fn_80265D48();
    fn_80129BD4();
    fn_80004B5C();
    fn_802E30C8((const char*)0x802FAFE0, fn_80004E20);
    if (fn_80019B6C() != 0) {
        fn_801E78A0();
    } else if (fn_80019B48() != 0) {
        fn_8024BE04();
    } else if (fn_80019B54() != 0) {
        fn_80005304();
    } else if (fn_80019B3C() != 0) {
        fn_800052F8();
    } else {
        fn_8023B6B0();
    }
    fn_80004CB4();
    fn_80129BF8();
    fn_80265D4C();
}

void fn_80004EC0(const char* source) {
    int remaining;
    char* destination;

    destination = lbl_8034EC58;
    remaining = 0x20;

    while ((*destination++ = *source++) != '\0') {
        if (--remaining <= 0) {
            destination[-1] = '\0';
            return;
        }
    }
}

u32 fn_80004FCC(GameVirtualObject* object, u32 argument, u32 fallback) {
    if (object->vtable->isReady(object)) {
        return object->vtable->getValue(object, argument);
    }
    return fallback;
}

void fn_80005364(void) {
    fn_8000D838(&lbl_8055D320);
    lbl_802FAFA0[1] = lbl_8055890C;
    lbl_8055D328 = 0xFFFF0000;
    lbl_8034EC40[1] = 0x7B;
    lbl_8034EC40[0] = 0;
    lbl_8034EC40[2] = 0;
    lbl_8034EC40[3] = 0;
    lbl_8034EC40[4] = 0;
    lbl_8055D32C = 0x7F000000;
}

int fn_80005044(int* eventIndex, int* subIndex, const char* name) {
    int result = 0;
    int i;

    for (i = 0; i < fn_80012818(); i++) {
        u8* event = fn_80012820(i);
        if (fn_8002B130(name, (const char*)(event + 8)) == 0) {
            *eventIndex = i;
            *subIndex = 0;
            result = 1;
            break;
        }
    }
    return result;
}

int fn_80004F00(int* eventIndex, int* subIndex, const char* name) {
    int result = 0;
    int i;

    for (i = 0; i < fn_80012818(); i++) {
        u8* event = fn_80012820(i);
        int j;

        for (j = 0; j < *(int*)(event + 0x70); j++) {
            u8* entry = fn_80012870(i, j);
            GameVirtualObject* object = *(GameVirtualObject**)(entry + 0x20);
            const char* entryName = object->vtable->getName(object, lbl_80558918, lbl_80558920);

            if (fn_8002B130(entryName, name) == 0) {
                *eventIndex = i;
                *subIndex = j;
                result = 1;
                break;
            }
        }
        if (result != 0) {
            break;
        }
    }
    return result;
}

int fn_800050D0(int* eventIndex, int* subIndex, const char* name) {
    int result = 0;
    int i;

    for (i = 0; i < fn_80012818(); i++) {
        u8* event = fn_80012820(i);
        if (fn_8002B130((const char*)(event + 0x28), name) == 0) {
            *eventIndex = i;
            *subIndex = 0;
            result = 1;
            break;
        }
    }
    return result;
}

void fn_80005304(void) DECOMP_DONT_INLINE {
    char name[64];
    int index = 0;

    while (TRUE) {
        sprintf(name, lbl_802FB0B8, index);
        if (fn_80005158(name) == 0) {
            break;
        }
        index++;
    }
}
