// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
__declspec(section ".sdata") extern unsigned char lbl_8055FC18;
extern char lbl_804C1338[];
typedef struct ClearBlock3_t {
    unsigned int a;
    unsigned int b;
    unsigned int c;
} ClearBlock3_t;

static inline void ClearBlock3(ClearBlock3_t *p) {
    p->c = 0;
    p->b = 0;
    p->a = 0;
}

void fn_802C8238(void) {
    unsigned char *base = (unsigned char *)lbl_804C1338;
    fn_8000D838(&lbl_8055FC18);
    ClearBlock3((ClearBlock3_t *)(base + 0x00));
    ClearBlock3((ClearBlock3_t *)(base + 0x58));
    ClearBlock3((ClearBlock3_t *)(base + 0x64));
    ClearBlock3((ClearBlock3_t *)(base + 0x70));
    ClearBlock3((ClearBlock3_t *)(base + 0x7C));
}

