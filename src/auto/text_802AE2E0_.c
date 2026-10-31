// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern int fn_80131810(void);
extern int lbl_804BD8CC[3];
#pragma push
#pragma scheduling invalid_target
#pragma opt_common_subs off
void fn_802AE2E0(void) {
    int result = fn_80131810();
    if (result) {
        int count = lbl_804BD8CC[1];
        lbl_804BD8CC[1] = count + 1;
        ((int *)lbl_804BD8CC[0])[count] = result;
    }
}
int fn_802AE414(void *arg0) {
    extern u8 lbl_8055F958;
    extern int lbl_804BD8CC[3];
    extern void fn_802AE328(void);
    typedef int (*Method)(void *, void *);
    typedef struct { Method *vtable; } Object;
    int offset;
    int *global;
    int i;
    Object *object;

    if (lbl_8055F958 == 0)
        fn_802AE328();
    offset = 0;
    i = 0;
    global = (int *)&lbl_804BD8CC;
    while (i < global[1]) {
        object = (Object *)(*(int * volatile *)&lbl_804BD8CC)[offset / 4];
        if (object->vtable[4](object, arg0)) {
            object = (Object *)(*(int * volatile *)&lbl_804BD8CC)[i];
            return object->vtable[2](object, arg0);
        }
        offset += 4;
        i++;
    }
    return 0;
}
#pragma pop
extern u8 lbl_8055F958;
extern u8 lbl_8055F959;
extern void fn_80131818(void *);
extern void fn_802AE328(void);
#pragma scheduling invalid_target
s32 fn_802AE4C8(s32 arg0) {
    s32 count;
    s32 *items;
    s32 result;
    if ((s32)lbl_8055F958 == 0)
        fn_802AE328();
    if (arg0 < 0)
        return 0;
    count = lbl_804BD8CC[1];
    if (arg0 >= count)
        return 0;
    items = (s32 *)lbl_804BD8CC[0];
    result = items[arg0];
    return result;
}
#pragma scheduling on
