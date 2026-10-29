// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8020A76C(void);
extern char *fn_8020A774(int);
extern void fn_8023895C(void);
extern void fn_802389E4(void);
extern void fn_80238A74(int, int, const char *, int);
extern void fn_80238B44(int, int, int, int, int);
extern void fn_802E6B38(int, char *);
extern int lbl_8055EE24, lbl_8055EE28;
extern char lbl_8033C5CC[];
extern char lbl_8055B5C8;
void fn_8020BF58(void) {
    char sp48[64], sp8[64];
    int i, n, line, col;
    char *p;
    fn_8023895C();
    fn_80238A74(12,12,lbl_8033C5CC,0xFF2D2DC8);
    if (lbl_8055EE24 == 1) {
        fn_80238B44(7,7,0x15e,0x1c0,0x8c000000);
        for (i=0;i<32;i++) {
            fn_802E6B38(i,sp48);
            line = i/16;
            col = (i%16)*14+26;
            fn_80238A74(line ? 0x122 : 0x14,col,sp48,-0x100);
        }
    } else if (lbl_8055EE24 == 0) {
        fn_80238B44(7,7,0x12c,0x1c0,0x8c000000);
        n = fn_8020A76C()*2;
        for (i=0;i<n;i++) {
            p = fn_8020A774(i/2);
            line = i/2;
            if ((i&1)==0) {
                int j=0;
                while (j<63 && p[j]) { sp8[j]=p[j]; j++; }
                sp8[j]=0;
            } else sprintf(sp8,lbl_8055B5C8,*(float *)(p+0x20));
            col = (line == lbl_8055EE28) ? 0xFF2D2DC8 : -0x100;
            fn_80238A74((i&1)?0xf0:0x14,line*14+26,sp8,col);
        }
    }
    fn_802389E4();
}
