// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
typedef unsigned char u8;
s32 fn_80128670(s32);
s32 fn_80131818(s32);
s32 fn_802E317C(const char *, const char *);
int stricmp(const char *, const char *);
extern u8 lbl_8055D570;
extern s32 lbl_8055D574;
extern s32 lbl_8055D578;
extern s32 lbl_8055D57C;
extern const char lbl_802FD270[];
void fn_80018B24(void) {
    lbl_8055D570 = 0;
    fn_80128670(lbl_8055D578);
    lbl_8055D578 = 0;
    lbl_8055D57C = 0;
    fn_80131818(lbl_8055D574);
}
