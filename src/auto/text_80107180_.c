// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055DEA0;
extern unsigned int lbl_8055DE98;
/* Static initializer: point the global sentinel pointer lbl_8055DE98 at lbl_8055DEA0 (the next node in the chain). */
void fn_80107180(void) {
#define gSentinelNode lbl_8055DEA0
#define gpSentinelPointer lbl_8055DE98
    gpSentinelPointer = (unsigned int)&gSentinelNode;
#undef gpSentinelPointer
#undef gSentinelNode
}
