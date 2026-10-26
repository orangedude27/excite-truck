// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80279464(void* alarm) {
    fn_80279CE4(fn_80279370(alarm));
}

extern void* fn_80279D3C(void*);
extern void fn_802793AC(void*);
void fn_80279488(void* alarm) {
    fn_802793AC(fn_80279D3C(alarm));
}

extern void *fn_801E87A8(void);
extern void fn_802E317C(char *, ...);
extern char lbl_803477F0[];
#pragma push
#pragma scheduling invalid_target
int fn_802794AC(int arg0, void *arg1) {
    switch (arg0) {
    case 0x50:
    case 0x51:
    case 0x52:
        return 1;
    case 0x54:
        return 0;
    case 0x53:
        if (arg1 == 0) {
            arg1 = fn_801E87A8();
        }
        return *(unsigned int *)((char *)arg1 + 0x10) & 1;
    default:
        fn_802E317C(lbl_803477F0, arg0);
        return 0;
    }
}
#pragma pop
