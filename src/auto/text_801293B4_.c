// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055DFC4;
extern void lbl_8041E180(void);
extern void *memcpy(void *, const void *, unsigned long);
/* Install the AX DSP DMA work buffer: point the global 0x4000-byte buffer pointer at its static backing store. */
void fn_801293B4(void) {
#define gAXDmaBuffer lbl_8055DFC4
#define sAXDmaBufferData lbl_8041E180
    gAXDmaBuffer = sAXDmaBufferData;
#undef gAXDmaBuffer
#undef sAXDmaBufferData
}

void fn_801293C4(void) {

}

extern void *lbl_8055DFC0;
void fn_801293C8(void* hi) {
    lbl_8055DFC0 = hi;
}

void __AXDSPInitCallback_801293D0(void) {
    lbl_8055DFC0 = 0;
}

void fn_801293DC(void *arg0) {
    memcpy(arg0, lbl_8055DFC4, 0x4000);
}

/* Copy 0x4000 bytes from src into the AX DSP DMA buffer pointed to by lbl_8055DFC4 (inverse of fn_801293DC). */
void fn_801293E8(void *src) {
    memcpy(lbl_8055DFC4, src, 0x4000);
}

