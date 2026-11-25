#include <revolution/OS.h>

/* The ConfigMEM* helpers below are handwritten asm stubs that program the PowerPC
 * BAT registers directly; BATConfig selects one and enters it through RealMode.
 * ConfigMEM2_52MB maps a 52 MB MEM2 window (0x90000000-0x93400000),
 * ConfigMEM2_56MB maps 56 MB (0x90000000-0x93800000), ConfigMEM2_64MB maps 64 MB,
 * and ConfigMEM2_112MB / 128MB cover the larger boards. Each writes the IBAT/DBAT
 * upper/lower register pairs with the SDK's cache and protection attributes.
 * ConfigMEM2_128MB maps the full 128 MB window: pair 0 cached at 0x90000000,
 * pair 1 guarded at the 0xD0000000 alias, pairs 2-7 disabled. */

static BOOL OnShutdown(BOOL final, u32 event);
static OSShutdownFunctionInfo ShutdownFunctionInfo = {OnShutdown, 127};

u32 OSGetPhysicalMem1Size(void) {
    /* Return the console's physical MEM1 size from the hardware config register. */
    return OS_PHYSICAL_MEM1_SIZE;
}

u32 OSGetPhysicalMem2Size(void) {
    /* Return the console's physical MEM2 size from the hardware config globals. */
    return OS_PHYSICAL_MEM2_SIZE;
}

/* Return the simulated MEM1 size from the OS globals area (0x80003104),
 * used to cap MEM1 when running with a simulated console memory size. */
u32 OSGetConsoleSimulatedMem1Size(void) {
    return OS_SIMULATED_MEM1_SIZE;
}

u32 OSGetConsoleSimulatedMem2Size(void) {
    /* Return the simulated MEM2 size the console reports to the game, from the hardware config globals. */
    return OS_SIMULATED_MEM2_SIZE;
}

/* Memory subsystem shutdown callback (registered at priority 127): on the final
 * shutdown pass it removes all MEM0..3 memory protection (0xFF = unrestricted)
 * and masks the four MEM interrupts so no protection fault can fire on the way
 * down.  The shutdown event is not used. */
static BOOL OnShutdown(BOOL final, u32 event) {
#pragma unused(event)

    if (final) {
        MI_HW_REGS[MI_PROT_MEM0] = 0xFF;
        __OSMaskInterrupts(
            OS_INTR_MASK(OS_INTR_MEM_0) | OS_INTR_MASK(OS_INTR_MEM_1) |
            OS_INTR_MASK(OS_INTR_MEM_2) | OS_INTR_MASK(OS_INTR_MEM_3));
    }

    return TRUE;
}

// @typo
/* MEM protection interrupt handler: __OSInitMemoryProtection() installs this for the
 * four MEM0..3 interrupts and for MEM_ADDRESS.  It takes the cause out of the MI
 * interrupt-cause register and the address of the offending access out of
 * MI_ADDRHI/MI_ADDRLO, acknowledges the interrupt, and hands both to the protection
 * error handler the game installed with OSSetErrorHandler(), or to the default
 * unhandled-exception report.  The name is misspelled in Nintendo's own SDK. */
static void MEMIntrruptHandler(s16 intr, OSContext* ctx) {
#pragma unused(intr)

    u32 dsisr = MI_HW_REGS[MI_INTSR];
    u32 dar = (MI_HW_REGS[MI_ADDRHI] & 0x3ff) << 0x10 | MI_HW_REGS[MI_ADDRLO];
    MI_HW_REGS[MI_REG_0x20] = 0; /* acknowledge the interrupt */

    if (__OSErrorTable[OS_ERR_PROTECTION] != NULL) {
        __OSErrorTable[OS_ERR_PROTECTION](OS_ERR_PROTECTION, ctx, dsisr, dar);
    } else {
        __OSUnhandledException(OS_ERR_PROTECTION, ctx, dsisr, dar);
    }
}

static asm void ConfigMEM1_24MB(void) {
    // clang-format off
    nofralloc

    li r7, 0
    lis r4, 0x00000002@ha
    addi r4, r4, 0x00000002@l
    lis r3, 0x800001FF@ha
    addi r3, r3, 0x800001FF@l
    lis r6, 0x01000002@ha
    addi r6, r6, 0x01000002@l
    lis r5, 0x810000FF@ha
    addi r5, r5, 0x810000FF@l
    isync
    mtdbatu 0, r7
    mtdbatl 0, r4
    mtdbatu 0, r3
    isync
    mtibatu 0, r7
    mtibatl 0, r4
    mtibatu 0, r3
    isync
    mtdbatu 2, r7
    mtdbatl 2, r6
    mtdbatu 2, r5
    isync
    mtibatu 2, r7
    mtibatl 2, r6
    mtibatu 2, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtspr 0x1b, r3
    mflr r3
    mtspr 0x1a, r3
    rfi
    // clang-format on
}

static asm void ConfigMEM1_48MB(void) {
    // clang-format off
    nofralloc

    li r7, 0
    lis r4, 0x00000002@ha
    addi r4, r4, 0x00000002@l
    lis r3, 0x800003FF@ha
    addi r3, r3, 0x800003FF@l
    lis r6, 0x02000002@ha
    addi r6, r6, 0x02000002@l
    lis r5, 0x820001FF@ha
    addi r5, r5, 0x820001FF@l
    isync
    mtdbatu 0, r7
    mtdbatl 0, r4
    mtdbatu 0, r3
    isync
    mtibatu 0, r7
    mtibatl 0, r4
    mtibatu 0, r3
    isync
    mtdbatu 2, r7
    mtdbatl 2, r6
    mtdbatu 2, r5
    isync
    mtibatu 2, r7
    mtibatl 2, r6
    mtibatu 2, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtspr 0x1b, r3
    mflr r3
    mtspr 0x1a, r3
    rfi
    // clang-format on
}

static asm void ConfigMEM2_52MB(void) {
    // clang-format off
    nofralloc

    li r7, 0
    lis r4, 0x10000002@ha
    addi r4, r4, 0x10000002@l
    lis r3, 0x900003FF@ha
    addi r3, r3, 0x900003FF@l
    lis r6, 0x1000002A@ha
    addi r6, r6, 0x1000002A@l
    lis r5, 0xD00007FF@ha
    addi r5, r5, 0xD00007FF@l
    isync
    mtspr 0x238, r7
    mtspr 0x239, r4
    mtspr 0x238, r3
    isync
    mtspr 0x230, r7
    mtspr 0x231, r4
    mtspr 0x230, r3
    isync
    mtspr 0x23a, r7
    mtspr 0x23b, r6
    mtspr 0x23a, r5
    isync
    mtspr 0x232, r7
    mtspr 0x233, r7
    isync
    lis r4, 0x12000002@ha
    addi r4, r4, 0x12000002@l
    lis r3, 0x920001FF@ha
    addi r3, r3, 0x920001FF@l
    lis r6, 0x13000002@ha
    addi r6, r6, 0x13000002@l
    lis r5, 0x9300007F@ha
    addi r5, r5, 0x9300007F@l
    isync
    mtspr 0x23c, r7
    mtspr 0x23d, r4
    mtspr 0x23c, r3
    isync
    mtspr 0x234, r7
    mtspr 0x235, r4
    mtspr 0x234, r3
    isync
    mtspr 0x23e, r7
    mtspr 0x23f, r6
    mtspr 0x23e, r5
    isync
    mtspr 0x236, r7
    mtspr 0x237, r6
    mtspr 0x236, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtspr 0x1b, r3
    mflr r3
    mtspr 0x1a, r3
    rfi
    // clang-format on
}

static asm void ConfigMEM2_56MB(void) {
    // clang-format off
    nofralloc

    li r7, 0
    lis r4, 0x10000002@ha
    addi r4, r4, 0x10000002@l
    lis r3, 0x900003FF@ha
    addi r3, r3, 0x900003FF@l
    lis r6, 0x1000002A@ha
    addi r6, r6, 0x1000002A@l
    lis r5, 0xD00007FF@ha
    addi r5, r5, 0xD00007FF@l
    isync
    mtspr 0x238, r7
    mtspr 0x239, r4
    mtspr 0x238, r3
    isync
    mtspr 0x230, r7
    mtspr 0x231, r4
    mtspr 0x230, r3
    isync
    mtspr 0x23a, r7
    mtspr 0x23b, r6
    mtspr 0x23a, r5
    isync
    mtspr 0x232, r7
    mtspr 0x233, r7
    isync
    lis r4, 0x12000002@ha
    addi r4, r4, 0x12000002@l
    lis r3, 0x920001FF@ha
    addi r3, r3, 0x920001FF@l
    lis r6, 0x13000002@ha
    addi r6, r6, 0x13000002@l
    lis r5, 0x930000FF@ha
    addi r5, r5, 0x930000FF@l
    isync
    mtspr 0x23c, r7
    mtspr 0x23d, r4
    mtspr 0x23c, r3
    isync
    mtspr 0x234, r7
    mtspr 0x235, r4
    mtspr 0x234, r3
    isync
    mtspr 0x23e, r7
    mtspr 0x23f, r6
    mtspr 0x23e, r5
    isync
    mtspr 0x236, r7
    mtspr 0x237, r6
    mtspr 0x236, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtspr 0x1b, r3
    mflr r3
    mtspr 0x1a, r3
    rfi
    // clang-format on
}

static asm void ConfigMEM2_64MB(void) {
    // clang-format off
    nofralloc

    li r7, 0
    lis r4, 0x10000002@ha
    addi r4, r4, 0x10000002@l
    lis r3, 0x900007FF@ha
    addi r3, r3, 0x900007FF@l
    lis r6, 0x1000002A@ha
    addi r6, r6, 0x1000002A@l
    lis r5, 0xD00007FF@ha
    addi r5, r5, 0xD00007FF@l
    isync
    mtspr 0x238, r7
    mtspr 0x239, r4
    mtspr 0x238, r3
    isync
    mtspr 0x230, r7
    mtspr 0x231, r4
    mtspr 0x230, r3
    isync
    mtspr 0x23a, r7
    mtspr 0x23b, r6
    mtspr 0x23a, r5
    isync
    mtspr 0x232, r7
    mtspr 0x233, r7
    isync
    mtspr 0x234, r7
    mtspr 0x235, r7
    isync
    mtspr 0x236, r7
    mtspr 0x237, r7
    isync
    mtspr 0x23c, r7
    mtspr 0x23d, r7
    isync
    mtspr 0x23e, r7
    mtspr 0x23f, r7
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtspr 0x1b, r3
    mflr r3
    mtspr 0x1a, r3
    rfi
    // clang-format on
}

static asm void ConfigMEM2_112MB(void) {
    // clang-format off
    nofralloc

    li r7, 0
    lis r4, 0x10000002@ha
    addi r4, r4, 0x10000002@l
    lis r3, 0x900007FF@ha
    addi r3, r3, 0x900007FF@l
    lis r6, 0x1000002A@ha
    addi r6, r6, 0x1000002A@l
    lis r5, 0xD0000FFF@ha
    addi r5, r5, 0xD0000FFF@l
    isync
    mtspr 0x238, r7
    mtspr 0x239, r4
    mtspr 0x238, r3
    isync
    mtspr 0x230, r7
    mtspr 0x231, r4
    mtspr 0x230, r3
    isync
    mtspr 0x23a, r7
    mtspr 0x23b, r6
    mtspr 0x23a, r5
    isync
    mtspr 0x232, r7
    mtspr 0x233, r7
    isync
    lis r4, 0x14000002@ha
    addi r4, r4, 0x14000002@l
    lis r3, 0x940003FF@ha
    addi r3, r3, 0x940003FF@l
    lis r6, 0x16000002@ha
    addi r6, r6, 0x16000002@l
    lis r5, 0x960001FF@ha
    addi r5, r5, 0x960001FF@l
    isync
    mtspr 0x23c, r7
    mtspr 0x23d, r4
    mtspr 0x23c, r3
    isync
    mtspr 0x234, r7
    mtspr 0x235, r4
    mtspr 0x234, r3
    isync
    mtspr 0x23e, r7
    mtspr 0x23f, r6
    mtspr 0x23e, r5
    isync
    mtspr 0x236, r7
    mtspr 0x237, r6
    mtspr 0x236, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtspr 0x1b, r3
    mflr r3
    mtspr 0x1a, r3
    rfi
    // clang-format on
}

/* Program the 128 MB MEM2 BAT map: pair 0 maps 0x90000000 cached, pair 1 maps
 * the 0xD0000000 alias guarded/uncached, pairs 2-7 are disabled. Each lower
 * register is written before its upper one, isync-separated; then MSR[IR/DR]
 * is enabled and rfi returns to protected mode. */

static asm void ConfigMEM2_128MB(void) {
    // clang-format off
    nofralloc

    li r7, 0
    lis r4, 0x10000002@ha
    addi r4, r4, 0x10000002@l
    lis r3, 0x90000FFF@ha
    addi r3, r3, 0x90000FFF@l
    lis r6, 0x1000002A@ha
    addi r6, r6, 0x1000002A@l
    lis r5, 0xD0000FFF@ha
    addi r5, r5, 0xD0000FFF@l
    isync
    mtspr 0x238, r7
    mtspr 0x239, r4
    mtspr 0x238, r3
    isync
    mtspr 0x230, r7
    mtspr 0x231, r4
    mtspr 0x230, r3
    isync
    mtspr 0x23a, r7
    mtspr 0x23b, r6
    mtspr 0x23a, r5
    isync
    mtspr 0x232, r7
    mtspr 0x233, r7
    isync
    mtspr 0x234, r7
    mtspr 0x235, r7
    isync
    mtspr 0x236, r7
    mtspr 0x237, r7
    isync
    mtspr 0x23c, r7
    mtspr 0x23d, r7
    isync
    mtspr 0x23e, r7
    mtspr 0x23f, r7
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtspr 0x1b, r3
    mflr r3
    mtspr 0x1a, r3
    rfi
    // clang-format on
}

static asm void ConfigMEM_ES1_0(void) {
    // clang-format off
    nofralloc

    li r7, 0
    lis r4, 0x00000002@ha
    addi r4, r4, 0x00000002@l
    lis r3, 0x80000FFF@ha
    addi r3, r3, 0x80000FFF@l
    isync
    mtdbatu 0, r7
    mtdbatl 0, r4
    mtdbatu 0, r3
    isync
    mtibatu 0, r7
    mtibatl 0, r4
    mtibatu 0, r3
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtspr 0x1b, r3
    mflr r3
    mtspr 0x1a, r3
    rfi
    // clang-format on
}

static asm void RealMode(register void* config) {
    // clang-format off
    nofralloc

    /* Enter real mode to run the BAT-config stub: SRR0 = the aligned stub
     * address, SRR1 = MSR with IR/DR (address translation) cleared, then rfi. */
    clrlwi config, config, 2
    mtspr 0x1a, config
    /* Clear IR/DR in the saved machine state so rfi enters the stub in real mode. */
    mfmsr config
    rlwinm config, config, 0, 0x1c, 0x19
    mtspr 0x1b, config
    rfi
    // clang-format on
}

/* Configures DBATs for the simulated/physical MEM1 and MEM2 layout.
 *
 * Each ConfigMEM* stub is run through RealMode(), which jumps to it with
 * address translation off; the stub writes its BAT pair(s) and returns with
 * rfi and MSR IR|DR set, so no translated access ever sees a half-written
 * mapping.  MEM1 is mapped at 0x80000000 (physical 0) and MEM2 at 0x90000000
 * (physical 0x10000000), with a second, cache-inhibited copy of MEM2 at
 * 0xD0000000; the sizes below are what each stub's BATs cover. */
static void BATConfig(void) {
    u32 mem1sim;
    u32 mem1phys;
    void* mem2end;

    if (OS_HOLLYWOOD_REV == 0) {
        // @bug Checks function address rather than result
        // NOLINTNEXTLINE (-Wtautological-pointer-compare)
        if (OSGetPhysicalMem1Size == 0) {
            // ES1 with no physical MEM1: ConfigMEM_ES1_0 covers the whole
            // 128 MB window with a single pair of BATs (virtual 0x80000000 ->
            // physical 0, cacheable, supervisor only).  A BAT upper half is
            // virtual base | (size / 64 KB - 1) << 1 | valid, a lower half is
            // physical base | PP (01 = supervisor read/write), and the upper
            // half is written last so an entry only appears once its base and
            // attributes are in place.
            RealMode(ConfigMEM_ES1_0);
            return;
        }
    }

    mem1sim = OSGetConsoleSimulatedMem1Size();
    mem1phys = OSGetPhysicalMem1Size();
    // 24 MB of MEM1 mapped on a console with more physical MEM1 than that:
    // drop the cached lines above the 24 MB window and put the memory-protect
    // block's mode register (0xCC004028) in mode 2 for the bigger chip.
    if (OSGetConsoleSimulatedMem1Size() < mem1phys &&
        mem1sim == OS_MEM_MB_TO_B(24)) {
        DCInvalidateRange((void*)0x81800000, OS_MEM_MB_TO_B(24));
        MI_HW_REGS[MI_REG_0x28] = 2;
    }

    // 24 MB = 16 MB + 8 MB at 0x81000000, 48 MB = 32 MB + 16 MB at 0x82000000.
    if (mem1sim <= OS_MEM_MB_TO_B(24)) {
        RealMode(ConfigMEM1_24MB);
    } else if (mem1sim <= OS_MEM_MB_TO_B(48)) {
        RealMode(ConfigMEM1_48MB);
    }

    // First address past the MEM2 the memory controller reports as accessible.
    mem2end = *(void**)OSPhysicalToCached(OS_PHYS_ACCESSIBLE_MEM2_END);
    // MEM2 in 4 MB steps: 52, 56 or 64 MB, or 112 / 128 MB on the big boards.
    if (OSGetConsoleSimulatedMem2Size() <= OS_MEM_MB_TO_B(64)) {
        if (mem2end <= (void*)0x93400000) {  // 0x90000000 + 52 MB
            RealMode(ConfigMEM2_52MB);
        } else if ((char*)mem2end <= (char*)0x93400000 + OS_MEM_MB_TO_B(4)) {
            RealMode(ConfigMEM2_56MB);       // + 56 MB
        } else {
            RealMode(ConfigMEM2_64MB);
        }
    } else if (OSGetConsoleSimulatedMem2Size() <= OS_MEM_MB_TO_B(128)) {
        if (mem2end <= (void*)0x97000000) {  // 0x90000000 + 112 MB
            RealMode(ConfigMEM2_112MB);
        } else {
            RealMode(ConfigMEM2_128MB);
        }
    }
}

/* Initialize memory protection hardware/interrupts and register shutdown handler. */
void __OSInitMemoryProtection(void) {
    BOOL enabled = OSDisableInterrupts();

    MI_HW_REGS[MI_REG_0x20] = 0;
    MI_HW_REGS[MI_PROT_MEM0] = 0xFF;

    __OSMaskInterrupts(
        OS_INTR_MASK(OS_INTR_MEM_0) | OS_INTR_MASK(OS_INTR_MEM_1) |
        OS_INTR_MASK(OS_INTR_MEM_2) | OS_INTR_MASK(OS_INTR_MEM_3));
    __OSSetInterruptHandler(OS_INTR_MEM_0, MEMIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_MEM_1, MEMIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_MEM_2, MEMIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_MEM_3, MEMIntrruptHandler);
    __OSSetInterruptHandler(OS_INTR_MEM_ADDRESS, MEMIntrruptHandler);
    OSRegisterShutdownFunction(&ShutdownFunctionInfo);

    BATConfig();
    __OSUnmaskInterrupts(OS_INTR_MASK(OS_INTR_MEM_ADDRESS));

    OSRestoreInterrupts(enabled);
}
