// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* The static-destructor record the compiler emits for a file-scope C++ object.
 * fn_8000D838 tags it '1' and links it onto the global chain whose head is
 * lbl_8055D450, so the object's destructor runs when the game exits. */
struct StaticDtorRecord {
    char tag;                        /* 0x00: '1' once registered */
    char pad01[3];
    struct StaticDtorRecord *next;   /* 0x04: the previous head of the chain */
};

extern struct StaticDtorRecord lbl_8055DFB0[1];
extern void fn_8000D838(struct StaticDtorRecord *record);
void fn_801293AC(void) {
    fn_8000D838(lbl_8055DFB0);
}
