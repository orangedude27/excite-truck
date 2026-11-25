// PPCArch.c - Revolution SDK processor-register accessors for Broadway/Gekko.
// The SPR read/write helpers below are hand-written CodeWarrior inline assembly
// (nofralloc, no frame): there is no C intrinsic for mfspr/mtspr, so they stay
// assembly for good. Only PPCDisableSpeculation, PPCSetFpNonIEEEMode and
// PPCMthid4 have any C in them.
#include <revolution/BASE.h>
#include <revolution/OS.h>

asm u32 PPCMfmsr(void) {
    // clang-format off
    nofralloc
    mfmsr r3
    blr
    // clang-format on
}

asm void PPCMtmsr(register u32 val) {
    // clang-format off
    nofralloc
    mtmsr val
    blr
    // clang-format on
}

asm u32 PPCMfhid0(void) {
    // clang-format off
    nofralloc
    mfhid0 r3
    blr
    // clang-format on
}

asm void PPCMthid0(register u32 val) {
    // clang-format off
    nofralloc
    mthid0 val
    blr
    // clang-format on
}

asm u32 PPCMfl2cr(void) {
    // clang-format off
    nofralloc
    mfl2cr r3
    blr
    // clang-format on
}

asm void PPCMtl2cr(register u32 val) {
    // clang-format off
    nofralloc
    mtl2cr val
    blr
    // clang-format on
}

asm void PPCMtdec(register u32 val) {
    // clang-format off
    nofralloc
    mtdec val
    blr
    // clang-format on
}

asm void PPCSync(void) {
    // clang-format off
    nofralloc
    sc
    blr
    // clang-format on
}

asm void PPCHalt(void) {
    // clang-format off
    nofralloc
    sync

loop:
    nop
    li r3, 0
    nop
    b loop
    // clang-format on
}

asm void PPCMtmmcr0(register u32 val) {
    // clang-format off
    nofralloc
    mtmmcr0 val
    blr
    // clang-format on
}

asm void PPCMtmmcr1(register u32 val) {
    // clang-format off
    nofralloc
    mtmmcr1 val
    blr
    // clang-format on
}

asm void PPCMtpmc1(register u32 val) {
    // clang-format off
    nofralloc
    mtpmc1 val
    blr
    // clang-format on
}

asm void PPCMtpmc2(register u32 val) {
    // clang-format off
    nofralloc
    mtpmc2 val
    blr
    // clang-format on
}

asm void PPCMtpmc3(register u32 val) {
    // clang-format off
    nofralloc
    mtpmc3 val
    blr
    // clang-format on
}

asm void PPCMtpmc4(register u32 val){
    // clang-format off
    nofralloc
    mtpmc4 val
    blr
    // clang-format on
}

/* Read the Floating-Point Status and Control Register (FPSCR) with mffs, then
 * return its low 32 bits.  Storing f31 to a local is what makes the value
 * available to C; the surrounding register save/restore is CodeWarrior's. */
u32 PPCMffpscr(void) {
    // clang-format off
    register u64 fpscr;
    asm {
        mffs f31
        stfd f31, fpscr
    }

    return fpscr;
    // clang-format on
}

/* Write val to the Floating-Point Status and Control Register (FPSCR):
 * zero-extend the 32-bit value into a 64-bit word, then load and store it
 * through f31 with mtfsf. */
/* Write fpscrValue to the Floating-Point Status and Control Register (FPSCR) via mtfsf. */ void PPCMtfpscr(register u32 fpscrValue) {
    PPC_MTFSF(fpscrValue);
}

asm u32 PPCMfhid2(void) {
    // clang-format off
    nofralloc
    mfspr r3, 0x398
    blr
    // clang-format on
}

asm void PPCMthid2(register u32 val) {
    // clang-format off
    nofralloc
    mtspr 0x398, val
    blr
    // clang-format on
}

asm u32 PPCMfwpar(void) {
    // clang-format off
    nofralloc
    sync
    mfwpar r3
    blr
    // clang-format on
}

asm void PPCMtwpar(register u32 val) {
    // clang-format off
    nofralloc
    mtwpar r3
    blr
    // clang-format on
}

void PPCDisableSpeculation(void) {
    // Set HID0's speculative-cache-access-disable bit.
    PPCMthid0(PPCMfhid0() | HID0_SPD);
}

asm void PPCSetFpNonIEEEMode(void) {
    // clang-format off
    nofralloc
    mtfsb1 29
    blr
    // clang-format on
}

/* Write hid4 to the HID4 special-purpose register, forcing the H4A bit on. */
void PPCMthid4(register u32 hid4) {
    if (hid4 & HID4_H4A) {
        PPC_MTSPR_HID4(hid4);
    } else {
        OSReport("H4A should not be cleared because of Broadway errata.\n");
        hid4 |= HID4_H4A;
        PPC_MTSPR_HID4(hid4);
    }
}
