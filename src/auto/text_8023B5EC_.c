// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8023B5EC(void);
void fn_8023D7CC(void);
void fn_8023D70C(void);
void fn_8023B618(void) {
    fn_8023B5EC();
    fn_8023D7CC();
    fn_8023D70C();
}

extern void fn_802E712C(void);
extern void fn_802E6CA4(int);
extern void fn_802E6CA8(void);
extern int fn_802E30C8(const char *, ...);
extern void fn_802473A4(void);
extern void fn_80012794(void);
extern void fn_80012788(void);
extern void fn_80247210(void);
extern void fn_80012778(void);
extern void fn_80129AEC(int);
extern void fn_802E47E8(void);
extern void fn_80127A24(void);
extern void fn_8027B690(void);
extern int fn_8012742C(void);
extern void fn_80127434(void);
extern int fn_80019BA8(void);
extern void fn_8027B77C(void);
extern void fn_802ECEC0(void);
extern char lbl_803412D8[];
extern char lbl_803412EC[];
#pragma dont_inline on
void fn_8023B640(void) { fn_802E30C8(lbl_803412D8); fn_802473A4(); }
void fn_8023B670(void) { fn_802E30C8(lbl_803412EC); fn_80012794(); fn_80012788(); fn_80247210(); fn_80012794(); fn_80012778(); }

void fn_8023B6B0(void) {
    fn_80129AEC(0); fn_802E47E8(); fn_80127A24(); fn_8023B618(); fn_8027B690();
    if (fn_8012742C() != 0) fn_80127434();
    if (fn_80019BA8() != 0) fn_8023B670(); else fn_8023B640();
    fn_8027B77C(); fn_802ECEC0();
}
#pragma dont_inline off
