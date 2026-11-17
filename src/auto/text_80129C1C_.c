// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* The static-destructor record the compiler emits for a file-scope C++ object.
 * fn_8000D838 tags it 0x31 and links it onto the global chain whose head is
 * lbl_8055D450, so the object's destructor runs when the game exits. */
struct StaticDtorRecord {
    char tag;                        /* 0x00: 0x31 once registered */
    char pad01[3];
    struct StaticDtorRecord *next;   /* 0x04: the previous head of the chain */
};

extern struct StaticDtorRecord lbl_8055DFD8[1];
extern void fn_8000D838(struct StaticDtorRecord *record);
/* Register this file-scope object's static destructor into the global chain. */
void fn_80129C1C(void) {
    fn_8000D838(lbl_8055DFD8);
}
