// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_800E6A44(void);

extern "C" unsigned int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(unsigned int);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, int, const char *, ...);
extern "C" void Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode(void *, void *);
extern "C" void Insert__Q46nw4hbm2ut6detail12LinkListImplFQ56nw4hbm2ut6detail12LinkListImpl8IteratorPQ36nw4hbm2ut12LinkListNode(void *, void **, void *);
extern const char lbl_80322094[];
extern const char lbl_80322070[];
extern const char lbl_80321F80[];
extern const char lbl_80321FAC[];
extern "C" void UnregisterCallback__Q46nw4hbm3snd6detail9AxManagerFPQ56nw4hbm3snd6detail9AxManager16CallbackListNode(void *self, void *node) {
    unsigned int level = OSDisableInterrupts();
    if (node == 0) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_80322094, 0x233, lbl_80322070);
    }
    Erase__Q46nw4hbm2ut6detail12LinkListImplFPQ36nw4hbm2ut12LinkListNode((char *)self + 8, node);
    OSRestoreInterrupts(level);
}

extern "C" void fn_800E5A8C(void) {
    fn_800E6A44();
}

void fn_800E80B4(void) {

}
