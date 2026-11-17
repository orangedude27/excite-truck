// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma opt_tail_call on
/* The static-destructor record the compiler emits for a file-scope C++ object.
 * fn_8000D838 tags it and links it onto the global chain (head lbl_8055D450)
 * whose objects get destroyed when the game exits. */
struct StaticDtorRecord {
    char tag;                         /* 0x00: '1' once registered */
    char pad01[3];
    struct StaticDtorRecord *next;    /* 0x04: previous head of the chain */
};
extern struct StaticDtorRecord lbl_8055E070[1];
extern void fn_8000D838(struct StaticDtorRecord *record);

void fn_80134204(void) {
    fn_8000D838(lbl_8055E070);
}
