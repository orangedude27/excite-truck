// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern int fn_80131810(void *);
extern int lbl_804BD8CC[3];
typedef struct { char a[0xC]; char b[0x10]; char c[0x10]; } Lists802AE328;
extern char lbl_80349FF0[];
extern u8 lbl_8055F958;
extern u8 lbl_8055F959;
#pragma push
#pragma scheduling invalid_target
#pragma opt_common_subs off
#pragma dont_inline on
/* Append the object created for the given argument to the global object list. */
void fn_802AE2E0(void *arg) {
    int object = fn_80131810(arg);
    if (object) {
        int *items = (int *)lbl_804BD8CC[0];
        int index = lbl_804BD8CC[1]++;
        items[index] = object;
    }
}

#pragma push
#pragma optimization_level 1
void fn_802AE328(void) {
    char *lists = lbl_80349FF0;
    fn_802AE2E0(&lists[(int)(sizeof(char) - 1)]);
    fn_802AE2E0(&lists[0xC]);
    fn_802AE2E0(&lists[0x1C]);
    lbl_8055F958 = 1;
}

#pragma push
#pragma optimization_level 4
void fn_802AE374(void) {
    /* Reset the global object list on subsystem startup: mark it uninitialized,
     * raise its reset flag and clear the recorded entry count. */
    lbl_8055F958 = 0;
    lbl_8055F959 = 1;
    lbl_804BD8CC[1] = 0;
}
#pragma opt_common_subs reset
void fn_802AE394(void) {
    int offset = 0;
    int i = 0;
    while (i < lbl_804BD8CC[1]) {
        fn_80131818((void *)(*(int *)((char *)lbl_804BD8CC[0] + offset)));
        offset += 4;
        i += 1;
    }
    lbl_804BD8CC[1] = 0;
    lbl_8055F958 = 0;
    lbl_8055F959 = 0;
}
#pragma push
#pragma scheduling invalid_target
#pragma opt_common_subs off
#pragma dont_inline on
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
extern void fn_802AE328(void);
#pragma scheduling invalid_target
/* Return the entry at the given index from the global object list, initializing the list on first use. */
s32 fn_802AE4C8(s32 index) {
#define objectListInitialized lbl_8055F958
#define objectList lbl_804BD8CC
#define InitObjectList fn_802AE328
    if ((s32)objectListInitialized == 0)
        InitObjectList();
    if (index >= 0) {
        s32 count = objectList[1];
        if (index < count)
            return ((s32 *)objectList[0])[index];
    }
    return 0;
#undef objectListInitialized
#undef objectList
#undef InitObjectList
}
#pragma scheduling on
