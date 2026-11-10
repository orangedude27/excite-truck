// mem — engine memory ids ("mem: bad memory id %d").
// Recovered TU window 0x802E3DF8..0x802E3EA8 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E3EA8 (+ .ctors slot 0x802ED5F4) remains in
// auto/text_802E3EA8_.c pending a promotion pass.
void fn_802E3DF8(int arena, void **outLo, unsigned int *outSize) {
    unsigned int hi = 0;
    unsigned int lo = 0;
    if (arena == 0) {
        lo = OSGetMEM1ArenaLo();
        hi = OSGetMEM1ArenaHi();
    } else if (arena == 1) {
        lo = OSGetMEM2ArenaLo();
        hi = OSGetMEM2ArenaHi();
    } else {
        fn_802E317C("invalid arena %d", arena);
    }
    lo = (lo + 0x7f) & ~0x7f;
    *outLo = (void *)lo;
    *outSize = hi - lo;
}
