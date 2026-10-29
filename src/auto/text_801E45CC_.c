// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int lbl_8055AEC0;
extern float lbl_8055AEC4;
extern unsigned char lbl_8055AEDC, lbl_8055EA8C, lbl_8055EA8D, lbl_8055EA8E, lbl_8055EA8F, lbl_8055EA90;
extern const char lbl_803399CC[];
extern float lbl_80562D30, lbl_80562D34, lbl_80562D38;
extern int fn_801769F8(void);
extern void fn_802E30C8(const char *);
extern void fn_801EC1F8(void);
extern void fn_801EC204(void);
extern void fn_802E4CDC(void);

extern void fn_8023895C(void);
extern void fn_802389E4(void);
extern void fn_80238A74(int, int, const char *, int);
extern void fn_80238B44(int, int, int, int, int);
extern int fn_802CC744(void);
extern int fn_802CC74C(void);
extern char lbl_80339930[];
extern int lbl_804874F0[];
extern int lbl_8055AEC8, lbl_8055AED4, lbl_8055AECC, lbl_8055AED8;
extern char lbl_8055AEE0[], lbl_8055AEE8[];
extern int lbl_8055EA88;
extern unsigned char lbl_8055EA8F, lbl_8055EA90;
void fn_801E45CC(void) {
    char buf[64];
    int color, i, y;
    fn_8023895C();
    fn_80238B44(10,10,230,84,0x80000000);
    sprintf(buf, (char *)&lbl_80339930 + 0x4c, lbl_8055AEC4);
    fn_80238A74(15,15,buf,-1);
    fn_80238A74(15,27,(char *)&lbl_80339930+0x60,-1);
    sprintf(buf,(char *)&lbl_80339930+0x74,lbl_8055AEC8,lbl_8055AED4);
    fn_80238A74(10,39,buf,-1);
    sprintf(buf,(char *)&lbl_80339930+0x80,lbl_8055AECC,lbl_8055AED8);
    fn_80238A74(10,51,buf,-1);
    color = lbl_8055EA90 ? 0xFF2DC82D : 0xFF202020;
    fn_80238A74(10,63,lbl_8055AEE0,color);
    if (fn_802CC744() == 0)
        fn_80238A74(50,63,(char *)&lbl_80339930+0x90,0xFF2D2DC8);
    else if (fn_802CC74C() == 0)
        fn_80238A74(50,63,lbl_8055AEE8,0xFF2DC82D);
    if (lbl_8055EA88)
        fn_80238A74(150,63,0,0xFF2DC82D);
    if (lbl_8055EA8F) {
        y = 100;
        fn_80238B44(20,100,320,112,0x60000000);
        i = 0;
        while (i < lbl_804874F0[32]) {
            fn_80238A74(20,y,(char *)&lbl_804874F0,-1);
            y -= 12;
            i++;
        }
    }
    fn_802389E4();
}
