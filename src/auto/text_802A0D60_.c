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
#pragma scheduling invalid_target
s32 fn_802A0FBC(void) {
    char *self = (char *)fn_8000AC38();
    void *obj = *(void **)(self + 0x20);
    s32 status = ((s32 (*)(void *, char *, s32))(*(void **)((char *)*(void **)obj + 0x30)))(obj, (char *)&lbl_80349900, 1);
    u32 type = *(u32 *)(self + 8);
    s32 result = 0;

    if (status != 0 && type == 0x180304 && (type & 0x100) != 0 && fn_80161C38() == 0) {
        result = 1;
    }
    return result;
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
