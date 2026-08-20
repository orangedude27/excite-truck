#include <revolution/OS.h>

extern void fn_802E2CFC(void* out);
extern void fn_80129C80(int, u32, u32);
extern int  fn_80129D18(int, int);
extern int  fn_80278A1C(const char* fmt);
extern void fn_80130390(void);
extern void fn_8012DDA8(void);
extern void fn_8012E498(void);
extern int  fn_80005158(const char*);
extern int  fn_80027550(char*, const char*, ...);
extern void fn_800199B8(void);
extern int  fn_80028F94(char*, const char*, int);
extern void fn_80265D48(void);
extern void fn_80129BD4(void);
extern void fn_802E30C8(const char*);
extern int  fn_80019B6C(void);
extern int  fn_80019B48(void);
extern int  fn_80019B54(void);
extern int  fn_80019B3C(void);
extern void fn_8023B6B0(void);
extern void fn_8024BE04(void);
extern void fn_801E78A0(void);
extern void fn_80129BF8(void);
extern void fn_80265D4C(void);
extern void fn_80005304(void);

extern u32 lbl_8055890C;
extern u32 lbl_802FAFA0[];
extern char lbl_8034EC58[];
extern const char* lbl_802FAFD4;

void fn_800049C0(void) {
    register const char* rodata_base = (const char*)0x802ED680;
    volatile u32 local[10];
    u16* dp;
    u16 year_val, month_val, day_val, hour_val;
    int lang_result;
    const char** table;

    local[0] = *(volatile u32*)(rodata_base + 0);
    local[1] = *(volatile u32*)(rodata_base + 4);
    local[2] = *(volatile u32*)(rodata_base + 8);
    local[3] = *(volatile u32*)(rodata_base + 12);
    local[4] = *(volatile u32*)(rodata_base + 16);
    local[5] = *(volatile u32*)(rodata_base + 20);
    local[6] = *(volatile u32*)(rodata_base + 24);
    local[7] = *(volatile u32*)(rodata_base + 28);
    local[8] = *(volatile u32*)(rodata_base + 32);
    local[9] = *(volatile u32*)(rodata_base + 36);

    dp = (u16*)&local[3];
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
        table = (const char**)local;
        fn_80278A1C(table[(lang_result >> 2) & 3]);
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

void fn_80004D64(char* args) {
    register char* p;
    register int result;

    if (args == NULL) return;

    fn_800199B8();
    p = args;
    goto check_char;

next_char:
    p++;
    if (*p != 0) goto check_char;
    return;

check_char:
    result = *p++;
    switch ((signed char)result) {
    case -0x7F: /* 0x81 = '-' as signed */
        break;
    default:
        goto next_char_done;
    case -0x7E: /* 0x82 */
        goto handle_space;
    case 0x20:
handle_space:
        break;
    }

next_char_done:
    if (fn_80028F94((char*)p, lbl_802FAFD4, 9) == 0) {
        *(u8*)0x8055D6FC = 1;
    } else {
        fn_80028F94((char*)p, (char*)0x8055D9D0, 4);
    }
    goto check_char;
}

void fn_80004E20(void) {
    fn_80265D48();
    fn_80129BD4();
    fn_80004B5C();
    fn_802E30C8((const char*)0x802FAFE0);
    if (fn_80019B6C() == 0) {
        if (fn_80019B48() == 0) {
            if (fn_80019B54() == 0) {
                if (fn_80019B3C() == 0) {
                    fn_8023B6B0();
                } else {
                    fn_800052F8();
                }
            } else {
                fn_80005304();
            }
        } else {
            fn_8024BE04();
        }
    } else {
        fn_801E78A0();
    }
    fn_80004CB4();
    fn_80129BF8();
    fn_80265D4C();
}
