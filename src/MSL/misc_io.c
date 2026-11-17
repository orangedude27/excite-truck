/* Review-source carve for auto_03_80025248_text. */
extern void __close_all(void);
extern void (*__stdio_exit)(void);

void __stdio_atexit(void) {
    /* Install __close_all as the stdio shutdown hook run at program exit. */
    __stdio_exit = __close_all;
}
