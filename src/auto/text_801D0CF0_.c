// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E8E8;
extern void *lbl_80438818[];
void __AXDSPInitCallback_801D0CF0(void) {
    lbl_8055E8E8 = 0;
}
typedef struct CallbackVTable {
    void *unk[3];
    void (*callback12)(void *);
    void *unk10[2];
    void (*callback24)(void *);
} CallbackVTable;

typedef struct CallbackObject {
    CallbackVTable *vtable;
} CallbackObject;
