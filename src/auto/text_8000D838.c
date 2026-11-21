// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Head of the global chain of static-destructor records. */
#define gStaticDtorListHead lbl_8055D450
extern void *gStaticDtorListHead;
#pragma push
#pragma scheduling invalid_target
void fn_8000D838(void *node) {
    /* Register a static-destructor record: tag it 0x31 and push it onto the head of the global chain. */
    memset(node, 0x31, 1);
    *(void **)((char *)node + 4) = gStaticDtorListHead;
    gStaticDtorListHead = node;
}
#pragma pop
void fn_8000D878(void) {
    /* Empty callback called during scene setup alongside static-destructor registration. */
    return;
}
