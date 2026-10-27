// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned int u32;

extern void fn_802A9428(void);
extern s32 lbl_8055F840;
extern s32 lbl_8055F844;
extern void fn_802C8BD0(s32);
extern void fn_802CA0A0(s32);
extern void fn_802C8D74(void);
extern void fn_802CAC54(void);
extern void fn_802CA094(void);
extern void fn_802A93A4(void);
extern void *fn_8000AC38(void);
extern s32 fn_80161C38(void);
extern char lbl_80349900[];
#pragma scheduling off
s32 fn_802A0FBC(void) {
    struct CallbackVTable {
        void *reserved[12];
        s32 (*check)(void *, char *, s32);
    };
    struct CallbackObject {
        struct CallbackVTable *vtable;
    };
    char *self = (char *)fn_8000AC38();
    struct CallbackObject *obj = *(struct CallbackObject **)(self + 0x20);
    s32 status = obj->vtable->check(obj, (char *)&lbl_80349900, 1);
    u32 type = *(u32 *)(self + 8);
    s32 result = 0;

    if (status == 0) goto done;
    if (type == 0x180304) goto done;
    if ((type & 0x100) == 0) goto done;
    if (fn_80161C38() != 0) goto done;
    result = 1;
done:
    return result;
}

extern float lbl_805646F0;
extern float fn_802A0F7C(void *, void *, void *);
#pragma scheduling off
void *fn_802A1040(void *arg0, void *arg1, void *arg2) {
    register s32 count = 0;
    void *entry = arg1;
    for (;;) {
        float first;
        float threshold;
        float next;
        first = fn_802A0F7C((char *)arg0 + 8, entry, arg0);
        threshold = lbl_805646F0;
        next = fn_802A0F7C((void *)((u32)arg0 + 8), *(void **)((char *)entry + 0x14), arg0);
        if (threshold <= first) {
            if (next > threshold)
                break;
            if (threshold <= first) {
                entry = *(void **)((char *)entry + 0x14);
                goto step;
            }
        }
        if (*(u32 *)((char *)arg2 + 0x1c) == (u32)entry) {
            entry = (void *)(*(u32 *)((char *)arg2 + 0x1c) +
                             ((*(u32 *)((char *)arg2 + 0x18) >> 16) * 0x3c));
            entry = (char *)entry - 0x3c;
        } else {
            entry = (char *)entry - 0x3c;
        }
    step:
        if (count++ >= 10)
            break;
    }
    return entry;
}
#pragma scheduling on

void fn_802A1548(void) {
    if (lbl_8055F840 != 0) {
        fn_802C8BD0(lbl_8055F844);
        fn_802CA0A0(lbl_8055F840);
        fn_802C8D74();
    }
}

void fn_802A1584(void) { fn_802A9428(); }
#pragma cplusplus on
extern "C" void fn_802A1120(void *, void *) {}
#pragma cplusplus reset
