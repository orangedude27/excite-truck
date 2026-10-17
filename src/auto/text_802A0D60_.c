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
extern u32 lbl_80349900;
void fn_802A1548(void) {
    if (lbl_8055F840 != 0) {
        fn_802C8BD0(lbl_8055F844);
        fn_802CA0A0(lbl_8055F840);
        fn_802C8D74();
    }
}

void fn_802A1584(void) { fn_802A9428(); }
