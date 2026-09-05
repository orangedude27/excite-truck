#include <types.h>

extern u16* __cpReg;

/* REXE01's symbol table calls this KPADSetBtnRepeat, but the body is the
 * four-counter CP performance read immediately following GXClearGPMetric. */
void KPADSetBtnRepeat(u32* cnt0, u32* cnt1, u32* cnt2, u32* cnt3) {
    volatile u16* cp;
    u16 high;
    u16 previous;
    u16 low;

    cp = (volatile u16*)__cpReg;
    high = cp[33];
    do {
        previous = high;
        low = cp[32];
        high = cp[33];
    } while (high != previous);
    *cnt2 = ((u32)high << 16) | low;

    cp = (volatile u16*)__cpReg;
    high = cp[35];
    do {
        previous = high;
        low = cp[34];
        high = cp[35];
    } while (high != previous);
    *cnt3 = ((u32)high << 16) | low;

    cp = (volatile u16*)__cpReg;
    high = cp[37];
    do {
        previous = high;
        low = cp[36];
        high = cp[37];
    } while (high != previous);
    *cnt0 = ((u32)high << 16) | low;

    cp = (volatile u16*)__cpReg;
    high = cp[39];
    do {
        previous = high;
        low = cp[38];
        high = cp[39];
    } while (high != previous);
    *cnt1 = ((u32)high << 16) | low;
}
