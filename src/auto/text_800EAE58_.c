// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8040EC90[];
extern char lbl_8040EC84[];
extern void __ct__Q46nw4hbm3snd6detail7ChannelFv(void);
extern void __dt__Q46nw4hbm3snd6detail7ChannelFv(void);
extern void fn_800EAEB0(void);
extern void fn_8002F53C(void *, void (*)(void), void (*)(void), int, int);
extern void __register_global_object(void *, void (*)(void), void *);
void fn_800EAE58(void) {
    fn_8002F53C(lbl_8040EC90, __ct__Q46nw4hbm3snd6detail7ChannelFv, __dt__Q46nw4hbm3snd6detail7ChannelFv, 0xE8, 0x41);
    __register_global_object(0, fn_800EAEB0, lbl_8040EC84);
}
