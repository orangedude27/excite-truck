// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern void fn_80296058(void);
extern int lbl_8055F768;
extern char lbl_804B42F0[];
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern void fn_80296058(void);
extern int lbl_8055F768;
extern char lbl_804B42F0[];
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern void fn_80296058(void);
extern int lbl_8055F768;
extern char lbl_804B42F0[];
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern void fn_80296058(void);
extern int lbl_8055F768;
extern char lbl_804B42F0[];
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern void fn_80296058(void);
extern int lbl_8055F768;
extern char lbl_804B42F0[];
#pragma scheduling invalid_target
void fn_80296014(void) {
    /* Initializes a fixed-size object pool/storage (8 entries of 0x184 bytes) using callback fn_80296058. */
#define poolStorage lbl_804B42F0
#define poolState lbl_8055F768
#define Pool_Init fn_8002F53C
#define Pool_ClearState fn_8000D838
#define Pool_ConstructEntry fn_80296058

    Pool_ClearState(&poolState);
    Pool_Init(poolStorage, Pool_ConstructEntry, 0, 0x184, 8);

#undef poolStorage
#undef poolState
#undef Pool_Init
#undef Pool_ClearState
#undef Pool_ConstructEntry
}
#pragma scheduling on
