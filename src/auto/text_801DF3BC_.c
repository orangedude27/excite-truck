// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern int __register_global_object(void *, void *, void *);
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, int, int);
extern void fn_801DF678(void);
extern void fn_801DF6D0(void);
extern char lbl_804872B0[];
extern char lbl_8055AE2C;
extern char lbl_8055E9D0[];
extern int lbl_8055E9D8;

#define FIELD_PTR(base, offset) (*(void **)((char *)(base) + (offset)))
#define FIELD_S32(base, offset) (*(s32 *)((char *)(base) + (offset)))
#define FIELD_S8(base, offset) (*(s8 *)((char *)(base) + (offset)))
