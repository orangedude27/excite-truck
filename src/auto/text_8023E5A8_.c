// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_80236914(void);
extern int lbl_804987E0[5];
extern unsigned char lbl_8055BAC0, lbl_8055BABC, lbl_8055BAB8, lbl_8055BC98, lbl_8055BCA0;
extern unsigned char lbl_802FA280[];
extern unsigned char lbl_80341CE4[];
typedef unsigned char u8;
typedef signed int s32;
extern s32 lbl_8055F1B4;
extern s32 lbl_8055F1B8;
extern u8 lbl_8055F1BC;
extern s32 lbl_8055F1C0;
extern u8 lbl_8055F1C4;
extern void *lbl_8055F1B0;
extern s32 fn_802E8D84(void);
extern u8 lbl_80341CC8[];
extern u8 lbl_8055F1AC;
extern s32 lbl_8055F1C8;
extern s32 fn_80214A9C(s32);
extern s32 fn_80214AF0(s32);
extern s32 fn_802E2C20(void);

void *fn_8023E5A8(void) {
    return lbl_80341CC8;
}

extern unsigned char lbl_80341CC8[];
extern unsigned char lbl_8055BCA8, lbl_8055BCB0, lbl_8055BCB8;
extern unsigned char lbl_8055F1AC;
extern int lbl_8055F1C8;
extern unsigned char lbl_8055BAC0, lbl_8055BCA0, lbl_8055BCC0, lbl_8055BCC8, lbl_8055BCD0, lbl_8055BCD8, lbl_8055BCE0, lbl_8055BCE8, lbl_8055BCF0, lbl_8055BCF8, lbl_8055BD00, lbl_8055BD08;
extern int lbl_804987E0[5];
extern unsigned char lbl_802FA294[];
extern unsigned char lbl_80341CF0[];
extern unsigned char lbl_8055F1AC;
extern int fn_802E2C20(void);
extern void fn_802E30C8(const char *);
extern int fn_802146BC(void *, int, int, int, ...);
extern void fn_8023EC94(void);
extern void fn_80236914(void);
void fn_8023E7A8(unsigned int mode) {
    char name[28] = {0};
    char a[128] = {0}, b[128] = {0}, c[128] = {0};
    switch (mode) {
    case 0: strcpy(name, (char *)lbl_80341CC8 + 0x34); break;
    case 1: strcpy(name, (char *)lbl_80341CC8 + 0x40); break;
    case 2: strcpy(name, (char *)lbl_80341CC8 + 0x4c); break;
    case 3: strcpy(name, (char *)&lbl_8055BCA8); break;
    case 4: strcpy(name, (char *)&lbl_8055BCB0); break;
    case 5: strcpy(name, (char *)lbl_80341CC8 + 0x58); break;
    case 6: strcpy(name, (char *)lbl_80341CC8 + 0x68); break;
    case 7: strcpy(name, (char *)lbl_80341CC8 + 0x74); break;
    case 8:
        strcpy(name, (char *)lbl_80341CC8 + 0x1e8);
        strcpy(a, (char *)lbl_80341CC8 + 0x1f8);
        strcpy(b, (char *)lbl_80341CC8 + 0x21c);
        strcpy(c, (char *)lbl_80341CC8 + 0x238);
        break;
    case 9:
        strcpy(name, (char *)lbl_80341CC8 + 0xc4);
        strcpy(a, (char *)lbl_80341CC8 + 0xd4);
        strcpy(b, (char *)lbl_80341CC8 + 0xf4);
        strcpy(c, (char *)&lbl_8055BCB8);
        break;
    case 10:
        strcpy(name, (char *)lbl_80341CC8 + 0x160);
        strcpy(a, (char *)lbl_80341CC8 + 0x174);
        strcpy(b, (char *)lbl_80341CC8 + 0x198);
        strcpy(c, (char *)&lbl_8055BCB8);
        break;
    }
    lbl_8055F1AC = 0;
    *((char *)&lbl_8055F1AC + 1) = 0;
    *((char *)&lbl_8055F1AC + 2) = 0;
    if (mode == 1) { *((char *)&lbl_8055F1AC + 1)=1; *((char *)&lbl_8055F1AC + 2)=1; }
    if (mode == 2) { *((char *)&lbl_8055F1AC + 1)=1; *((char *)&lbl_8055F1AC + 2)=1; }
    if (mode == 3) {
        lbl_8055F1AC=1;
        fn_802E2C20();
        lbl_8055F1C8=fn_802E2C20()+100;
        fn_802146BC(0, -999, -999, 1);
    }
}

void fn_8023EC94(void) {
    u8 *p;
    s32 i;

    p = &lbl_8055F1AC;
    i = 0;
    do {
        if (*p != 0) {
            fn_80214AF0(i + 1);
        } else {
            fn_80214A9C(i + 1);
        }
        i++;
    } while (i < 3 && (p++, 1));
}

s32 fn_8023ECF8(void) {
    return lbl_8055F1C8 < fn_802E2C20();
}

extern unsigned char lbl_8055B860;
extern int lbl_802FA2A8[5];
#pragma use_lmw_stmw off
void fn_8023ED30(void) {
    volatile int *config = (volatile int *)lbl_804987E0;
    volatile int *source = (volatile int *)lbl_802FA2A8;
    register int config0 = *config++;
    register int config1 = *config++;
    register int config2 = *config++;
    register int config3 = *config++;
    register int config4 = *config;
    int arg0 = *source++;
    int arg1 = *source++;
    int arg2 = *source++;
    int arg3 = *source++;
    int arg4 = *source;
    int values[50];
    int args[5];

    values[0] = (int)&lbl_8055B860;
    values[1] = 6;
    values[2] = 0;
    values[3] = -2;
    values[4] = 13;
    values[5] = (int)&lbl_8055BCA0;
    values[6] = 3;
    values[7] = (int)(lbl_80341CC8 + 0x2A8);
    values[8] = 4;
    values[9] = 0;
    values[10] = (int)&lbl_8055BCD8;
    values[11] = 3;
    values[12] = (int)(lbl_80341CC8 + 0x2C0);
    values[13] = 4;
    values[14] = 0;
    values[15] = (int)&lbl_8055BCE0;
    values[16] = 3;
    values[17] = (int)(lbl_80341CC8 + 0x2DC);
    values[18] = 4;
    values[19] = 0;
    values[20] = (int)&lbl_8055BCE8;
    values[21] = 3;
    values[22] = (int)&lbl_8055BCB8;
    values[23] = 4;
    values[24] = 0;
    values[25] = (int)&lbl_8055BCF0;
    values[26] = 3;
    values[27] = (int)&lbl_8055BCB8;
    values[28] = 4;
    values[29] = 0;
    values[30] = (int)&lbl_8055BCF8;
    values[31] = 3;
    values[32] = (int)&lbl_8055BCB8;
    values[33] = 4;
    values[34] = 0;
    values[35] = (int)&lbl_8055BD08;
    values[36] = 3;
    values[37] = (int)(lbl_80341CC8 + 0x2F4);
    values[38] = 4;
    values[39] = 0;
    values[40] = (int)&lbl_8055BD00;
    values[41] = 3;
    values[42] = (int)&lbl_8055BCB8;
    values[43] = 4;
    values[44] = 0;
    values[45] = config0;
    values[46] = config1;
    values[47] = config2;
    values[48] = config3;
    values[49] = config4;
    lbl_8055F1C4 = 0;

    args[0] = arg0;
    args[1] = arg1;
    args[2] = arg2;
    args[3] = arg3;
    args[4] = arg4;
    args[0] = (int)fn_8023E5A8();
    args[1] = (int)values;
    fn_802146BC(args, -999, -999, 1);
}

extern int lbl_802FA2BC[5];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
int fn_8023EEF8(void) {
    struct Data { void *first; void *second; int zero[3]; int values[55]; };
    volatile struct Data data;
    data.values[0]=(int)&lbl_8055B860;
    data.values[1]=6;
    data.values[2]=0;
    data.values[3]=-2;
    data.values[4]=0xD;
    data.values[5]=(int)&lbl_8055B860;
    data.values[6]=6;
    data.values[7]=0;
    data.values[8]=-1;
    data.values[9]=0x1B;
    data.values[10]=(int)&lbl_8055BCA0;
    data.values[11]=3;
    data.values[12]=(int)(lbl_80341CC8+0x304);
    data.values[13]=4;
    data.values[14]=0;
    data.values[15]=(int)&lbl_8055BCD8;
    data.values[16]=3;
    data.values[17]=(int)(lbl_80341CC8+0x310);
    data.values[18]=4;
    data.values[19]=0;
    data.values[20]=(int)&lbl_8055BCE0;
    data.values[21]=3;
    data.values[22]=(int)(lbl_80341CC8+0x330);
    data.values[23]=4;
    data.values[24]=0;
    data.values[25]=(int)&lbl_8055BCE8;
    data.values[26]=3;
    data.values[27]=(int)(lbl_80341CC8+0x350);
    data.values[28]=4;
    data.values[29]=0;
    data.values[30]=(int)&lbl_8055BCF0;
    data.values[31]=3;
    data.values[32]=(int)(lbl_80341CC8+0x374);
    data.values[33]=4;
    data.values[34]=0;
    data.values[35]=(int)&lbl_8055BCF8;
    data.values[36]=3;
    data.values[37]=(int)&lbl_8055BCB8;
    data.values[38]=4;
    data.values[39]=0;
    data.values[40]=(int)&lbl_8055BD08;
    data.values[41]=3;
    data.values[42]=(int)(lbl_80341CC8+0x2F4);
    data.values[43]=4;
    data.values[44]=0;
    data.values[45]=(int)&lbl_8055BD00;
    data.values[46]=3;
    data.values[47]=(int)(lbl_80341CC8+0x390);
    data.values[48]=4;
    data.values[49]=0;
    data.values[50]=lbl_804987E0[0];
    data.values[51]=lbl_804987E0[1];
    data.values[52]=lbl_804987E0[2];
    data.values[53]=lbl_804987E0[3];
    data.values[54]=lbl_804987E0[4];
    lbl_8055F1C4=0;
    data.first=(void *)lbl_802FA2BC[0];
    data.second=(void *)lbl_802FA2BC[1];
    data.zero[0]=lbl_802FA2BC[2];
    data.zero[1]=lbl_802FA2BC[3];
    data.zero[2]=lbl_802FA2BC[4];
    data.first=fn_8023E5A8();
    data.second=(void *)(int *)&data.values[0];
    return (((int (*)(void *,int,int,int))fn_802146BC)((void *)&data,-999,-999,1)+2)==0;
}
#pragma cplusplus reset
#pragma pop

#pragma use_lmw_stmw on
extern unsigned char lbl_8055BD10;
extern unsigned char lbl_8055BD18;
extern unsigned char lbl_8055BCF0;
extern unsigned char lbl_8055BCF8;
extern unsigned char lbl_8055BD08;
extern unsigned char lbl_8055BD00;
extern void fn_8023F9E8(void);
#pragma scheduling invalid_target
int fn_8023F0E8(void) {
    struct Data {
        void *first;
        void *second;
        int zero[3];
        int values[55];
    };
    volatile struct Data data;
    data.values[7] = (int)fn_8023F9E8;
    data.values[0] = (int)&lbl_8055B860;
    data.values[5] = (int)&lbl_8055B860;
    data.values[8] = -1;
    data.values[1] = 6;
    data.values[6] = 6;
    data.values[3] = -2;
    data.values[25] = (int)&lbl_8055BCE8;
    data.values[4] = 0xD;
    data.values[9] = 0x1B;
    data.values[12] = (int)&lbl_8055BD10;
    data.values[30] = (int)&lbl_8055BCF0;
    data.values[10] = (int)&lbl_8055BCA0;
    data.values[15] = (int)&lbl_8055BCD8;
    data.values[20] = (int)&lbl_8055BCE0;
    data.values[35] = (int)&lbl_8055BCF8;
    data.values[2] = 0;
    data.values[11] = 3;
    data.values[13] = 4;
    data.values[14] = 0;
    data.values[16] = 3;
    data.values[17] = (int)(lbl_80341CC8 + 0x3A8);
    data.values[18] = 4;
    data.values[19] = 0;
    data.values[21] = 3;
    data.values[22] = (int)&lbl_8055BCB8;
    data.values[23] = 4;
    data.values[24] = 0;
    data.values[26] = 3;
    data.values[27] = (int)(lbl_80341CC8 + 0x3C8);
    data.values[28] = 4;
    data.values[29] = 0;
    data.values[31] = 3;
    data.values[32] = (int)&lbl_8055BCB8;
    data.values[33] = 4;
    data.values[34] = 0;
    data.values[36] = 3;
    data.values[37] = (int)&lbl_8055BCB8;
    data.values[38] = 4;
    data.values[39] = 0;
    data.values[40] = (int)&lbl_8055BD08;
    data.values[42] = (int)&lbl_8055BD18;
    data.values[43] = 4;
    data.values[44] = 0;
    data.values[46] = 3;
    data.values[45] = (int)&lbl_8055BD00;
    data.values[47] = (int)(lbl_80341CC8 + 0x3E8);
    data.values[48] = 4;
    data.values[49] = 0;
    data.values[50] = *(int *)(lbl_804987E0 + 0);
    data.values[51] = *(int *)(lbl_804987E0 + 4);
    data.values[52] = *(int *)(lbl_804987E0 + 8);
    data.values[53] = *(int *)(lbl_804987E0 + 12);
    data.values[54] = *(int *)(lbl_804987E0 + 16);
    data.first = 0;
    data.second = 0;
    data.zero[0] = 0;
    data.zero[1] = 0;
    data.zero[2] = 0;
    data.first = fn_8023E5A8();
    data.second = (void *)&data.values[0];
    return (((int (*)(void *, int, int, int, int, int, int, int))fn_802146BC)(
                (void *)&data, -0x3E7, -0x3E7, 1,
                *(int *)(lbl_804987E0 + 0), 3, 4, 0) + 2) == 0;
}

extern int lbl_802FA2D0[5];
extern unsigned char lbl_8055BD20;
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
int fn_8023F2C4(void) {
    register int zero = 0;
    register int three = 3;
    register int four = 4;
    register int bcb8a = (int)&lbl_8055BCB8;
    register int bcb8b = (int)&lbl_8055BCB8;
    volatile int args[5];
    volatile int values[55];
    values[0] = (int)&lbl_8055B860;
    values[1] = 6;
    values[2] = zero;
    values[3] = -2;
    values[4] = 0xD;
    values[5] = (int)&lbl_8055B860;
    values[6] = 6;
    values[7] = (int)fn_8023F9E8;
    values[8] = -1;
    values[9] = 0x1B;
    values[10] = (int)&lbl_8055BCA0;
    values[11] = three;
    values[12] = (int)(lbl_80341CC8+0x3F4);
    values[13] = four;
    values[14] = zero;
    values[15] = (int)&lbl_8055BCD8;
    values[16] = three;
    values[17] = (int)(lbl_80341CC8+0x40C);
    values[18] = four;
    values[19] = zero;
    values[20] = (int)&lbl_8055BCE0;
    values[21] = three;
    values[22] = (int)(lbl_80341CC8+0x428);
    values[23] = four;
    values[24] = zero;
    values[25] = (int)&lbl_8055BCE8;
    values[26] = three;
    values[27] = (int)(lbl_80341CC8+0x238);
    values[28] = four;
    values[29] = zero;
    values[30] = (int)&lbl_8055BCF0;
    values[31] = three;
    values[32] = bcb8a;
    values[33] = four;
    values[34] = zero;
    values[35] = (int)&lbl_8055BCF8;
    values[36] = three;
    values[37] = bcb8b;
    values[38] = four;
    values[39] = zero;
    values[40] = (int)&lbl_8055BD08;
    values[41] = three;
    values[42] = (int)&lbl_8055BD20;
    values[43] = four;
    values[44] = zero;
    values[45] = (int)&lbl_8055BD00;
    values[46] = three;
    values[47] = (int)(lbl_80341CC8+0x3E8);
    values[48] = four;
    values[49] = zero;
    values[50] = lbl_804987E0[0];
    values[51] = lbl_804987E0[1];
    values[52] = lbl_804987E0[2];
    values[53] = lbl_804987E0[3];
    values[54] = lbl_804987E0[4];
    lbl_8055F1C4 = 0;
    args[0] = lbl_802FA2D0[0];
    args[1] = lbl_802FA2D0[1];
    args[2] = lbl_802FA2D0[2];
    args[3] = lbl_802FA2D0[3];
    args[4] = lbl_802FA2D0[4];
    args[0] = (int)fn_8023E5A8();
    args[1] = (int)values;
    return (((int (*)(void *, int, int, int))fn_802146BC)((void *)args, -999, -999, 1) + 2) == 0;
}

extern unsigned char lbl_8055BD28;
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
int fn_8023F4B8(void) {
    struct Desc {
        void * p0;
        int n1;
        int n2;
        int n3;
        int n4;
        void * p5;
        int n6;
        void (*callback)(void);
        int n8;
        int n9;
        void * p10;
        int n11;
        void * p12;
        int n13;
        int n14;
        void * p15;
        int n16;
        void * p17;
        int n18;
        int n19;
        void * p20;
        int n21;
        void * p22;
        int n23;
        int n24;
        void * p25;
        int n26;
        void * p27;
        int n28;
        int n29;
        void * p30;
        int n31;
        void * p32;
        int n33;
        int n34;
        void * p35;
        int n36;
        void * p37;
        int n38;
        int n39;
        void * p40;
        int n41;
        void * p42;
        int n43;
        int n44;
        void * p45;
        int n46;
        void * p47;
        int n48;
        int n49;
        int n50;
        int n51;
        int n52;
        int n53;
        int n54;
    };
    struct Data {
        void *first;
        void *second;
        int zero[3];
        volatile struct Desc values;
    };
    struct Data data;
    register int pC = (int)(lbl_80341CC8 + 0x3E8);
    data.values.callback = fn_8023F9E8;
    data.values.p0 = &lbl_8055B860;
    data.values.p5 = &lbl_8055B860;
    data.values.n8 = -1;
    data.values.n1 = 6;
    data.values.n6 = 6;
    data.values.n3 = -2;
    data.values.p25 = &lbl_8055BCE8;
    data.values.n4 = 0xD;
    data.values.n9 = 0x1B;
    data.values.p12 = (void *)(pC + 0x64);
    data.values.p30 = &lbl_8055BCF0;
    data.values.p10 = &lbl_8055BCA0;
    data.values.p15 = &lbl_8055BCD8;
    data.values.p20 = &lbl_8055BCE0;
    data.values.p35 = &lbl_8055BCF8;
    data.values.n2 = 0;
    data.values.n11 = 3;
    data.values.n13 = 4;
    data.values.n14 = 0;
    data.values.n16 = 3;
    data.values.p17 = (void *)(pC + 0x70);
    data.values.n18 = 4;
    data.values.n19 = 0;
    data.values.n21 = 3;
    data.values.p22 = (void *)(pC + 0x90);
    data.values.n23 = 4;
    data.values.n24 = 0;
    data.values.n26 = 3;
    data.values.p27 = (void *)(pC + 0xA8);
    data.values.n28 = 4;
    data.values.n29 = 0;
    data.values.n31 = 3;
    data.values.p32 = &lbl_8055BCB8;
    data.values.n33 = 4;
    data.values.n34 = 0;
    data.values.n36 = 3;
    data.values.p37 = &lbl_8055BCB8;
    data.values.n38 = 4;
    data.values.n39 = 0;
    data.values.p40 = &lbl_8055BD08;
    data.values.p42 = &lbl_8055BD28;
    data.values.n43 = 4;
    data.values.n44 = 0;
    data.values.n46 = 3;
    data.values.p45 = &lbl_8055BD00;
    data.values.p47 = (void *)pC;
    data.values.n48 = 4;
    data.values.n49 = 0;
    data.values.n50 = *(int *)(lbl_804987E0 + 0);
    data.values.n51 = *(int *)(lbl_804987E0 + 4);
    data.values.n52 = *(int *)(lbl_804987E0 + 8);
    data.values.n53 = *(int *)(lbl_804987E0 + 12);
    data.values.n54 = *(int *)(lbl_804987E0 + 16);
    data.first = 0;
    data.second = 0;
    data.zero[0] = 0;
    data.zero[1] = 0;
    data.zero[2] = 0;
    data.first = fn_8023E5A8();
    data.second = (void *)&data.values;
    return (((int (*)(void *, int, int, int, int, int, int, int))fn_802146BC)(
                (void *)&data, -0x3E7, -0x3E7, 1,
                *(int *)(lbl_804987E0 + 0), 3, 4, 0) + 2) == 0;
}
#pragma use_lmw_stmw on
extern unsigned char lbl_8055BD2C;
#pragma use_lmw_stmw off
extern int __cntlzw(unsigned int);
int fn_8023F694(void) {
    struct Header {
        void *a;
        int b;
        int c;
        int d;
        int e;
    };
    struct Record {
        void *a;
        int b;
        void *c;
        int d;
        int e;
    };
    struct Descriptor {
        struct Header header;
        struct Record records[9];
        int config[5];
    } data;
    int args[5] = { 0, 0, 0, 0, 0 };

    data.header.a = &lbl_8055B860;
    data.header.b = 6;
    data.header.c = 0;
    data.header.d = -2;
    data.header.e = 13;

    data.records[0].a = &lbl_8055B860;
    data.records[0].b = 6;
    data.records[0].c = (void *)fn_8023F9E8;
    data.records[0].d = -1;
    data.records[0].e = 0x1B;

    data.records[1].a = &lbl_8055BCA0;
    data.records[1].b = 3;
    data.records[1].c = lbl_80341CC8 + 0x4A4;
    data.records[1].d = 4;
    data.records[1].e = 0;

    data.records[2].a = &lbl_8055BCD8;
    data.records[2].b = 3;
    data.records[2].c = lbl_80341CC8 + 0x4B8;
    data.records[2].d = 4;
    data.records[2].e = 0;

    data.records[3].a = &lbl_8055BCE0;
    data.records[3].b = 3;
    data.records[3].c = lbl_80341CC8 + 0x4E0;
    data.records[3].d = 4;
    data.records[3].e = 0;

    data.records[4].a = &lbl_8055BCE8;
    data.records[4].b = 3;
    data.records[4].c = lbl_80341CC8 + 0x500;
    data.records[4].d = 4;
    data.records[4].e = 0;

    data.records[5].a = &lbl_8055BCF0;
    data.records[5].b = 3;
    data.records[5].c = &lbl_8055BCB8;
    data.records[5].d = 4;
    data.records[5].e = 0;

    data.records[6].a = &lbl_8055BCF8;
    data.records[6].b = 3;
    data.records[6].c = &lbl_8055BCB8;
    data.records[6].d = 4;
    data.records[6].e = 0;

    data.records[7].a = &lbl_8055BD08;
    data.records[7].b = 3;
    data.records[7].c = &lbl_8055BD2C;
    data.records[7].d = 4;
    data.records[7].e = 0;

    data.records[8].a = &lbl_8055BD00;
    data.records[8].b = 3;
    data.records[8].c = lbl_80341CC8 + 0x3E8;
    data.records[8].d = 4;
    data.records[8].e = 0;

    data.config[0] = lbl_804987E0[0];
    data.config[1] = lbl_804987E0[1];
    data.config[2] = lbl_804987E0[2];
    data.config[3] = lbl_804987E0[3];
    data.config[4] = lbl_804987E0[4];

    args[0] = (int)((void *(*)(int, int, int, int, int, int, int, int))fn_8023E5A8)(
        lbl_804987E0[3], lbl_804987E0[2], lbl_804987E0[1],
        (int)lbl_804987E0, lbl_804987E0[0], 3, 4, 0);
    args[1] = (int)&data;
    return (fn_802146BC(args, -999, -999, 1) + 2) == 0;
}
#pragma use_lmw_stmw on

#pragma scheduling on

void fn_8023F870(void) {
}

void fn_8023F874(void) {}

#pragma cplusplus on
extern "C" int fn_8023F878(void) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual int v2();
        virtual void v3();
    };
    int now;
    if (lbl_8055F1C0 != 0) ((void (*)(void))lbl_8055F1C0)();
    now = fn_802E2C20();
    if (lbl_8055F1BC == 0) {
        if (now > lbl_8055F1B8) {
            if (((Obj *)lbl_8055F1B0)->v2() != 0)
                lbl_8055F1BC = 1;
            else
                ((Obj *)lbl_8055F1B0)->v3();
        }
    } else {
        if (now > lbl_8055F1B4) return 1;
    }
    return 0;
}
#pragma cplusplus off
int fn_8023F91C(int *arg0) {
    if (!fn_802E8D84())
        goto zero;
    *arg0 = -2;
    goto done;
zero:
    return 0;
done:
    return 1;
}

int fn_8023F964(int *arg0) {
    if (lbl_8055F1C0 != 0) ((void (*)(void))lbl_8055F1C0)();
    if (fn_802E8D84() == 0) {
        lbl_8055F1C4 = 1;
    } else {
        if (lbl_8055F1C4 != 0 && fn_802E8D84() != 0) {
            *arg0 = -2;
            return 1;
        }
    }
    return 0;
}

extern unsigned char lbl_80342238[];
extern unsigned char lbl_80342248[];
extern void fn_80215214(void *, void *, int);
#pragma scheduling invalid_target
void fn_8023F9E8(void) {
    void *first = lbl_80342238;
    void *second = lbl_80342248;
    fn_80215214(first, second, 0);
}
#pragma scheduling on
extern s32 lbl_8055F1B4;
extern s32 lbl_8055F1B8;
extern u8 lbl_8055F1BC;
extern s32 lbl_8055F1C0;
extern u8 lbl_8055F1C4;
extern void *lbl_8055F1B0;
extern s32 fn_802E8D84(void);
