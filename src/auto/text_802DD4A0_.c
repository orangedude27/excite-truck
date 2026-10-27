#include "revolution/GX/GXVert.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void *fn_80128668(void *);
void fn_80128670(int);
extern void *lbl_8055FED8;
extern float lbl_804DB6A0[];
void *fn_802DD4A0(void *arg0, int arg1) {
    void *local = arg0;
    if (arg0 != (void*)0) {
        if ((arg0 != (void*)0) && (arg0 != (void*)0)) {
            *(int*)arg0 = 0;
            *(int*)((char*)arg0 + 4) = 0;
            *(int*)((char*)arg0 + 8) = 0;
        }
        if (arg1 > 0) {
            fn_80128668(local);
        }
    }
    return local;
}

extern int lbl_8055FED0;
extern int lbl_8055FED4;
extern char lbl_8034CB50[];
extern char lbl_8034CB5C[];
void *fn_802D2D14(void);
void *fn_801284F8(int, void *);
int fn_8012850C(int, void *);
void GXInitTexObj(void *, void *, unsigned short, unsigned short, int, int, int, int);
void GXInitTexObjFilter(void *, int, int);
void fn_802DD4FC(void) {
    void *info = fn_802D2D14();
    lbl_8055FED0 = *(unsigned short *)((char *)info + 4);
    lbl_8055FED4 = *(unsigned short *)((char *)info + 6);
    {
        void *obj = fn_801284F8(0x50, lbl_8034CB50);
        if (obj != 0) {
            *(unsigned char *)((char *)obj + 0x4C) = 1;
            do {
                *(int *)((char *)obj + 0x44) = lbl_8055FED0 / 2;
                *(int *)((char *)obj + 0x48) = lbl_8055FED4 / 2;
                break;
                *(int *)((char *)obj + 0x44) = lbl_8055FED0;
                *(int *)((char *)obj + 0x48) = lbl_8055FED4;
            } while (0);
            *(int *)((char *)obj + 0x40) = fn_8012850C(*(int *)((char *)obj + 0x48) * (*(int *)((char *)obj + 0x44) * 2), lbl_8034CB5C);
            GXInitTexObj(obj, *(void **)((char *)obj + 0x40), *(int *)((char *)obj + 0x44), *(int *)((char *)obj + 0x48), 4, 0, 0, 0);
            GXInitTexObjFilter(obj, 1, 1);
            *(unsigned char *)((char *)obj + 0x4D) = 0;
        }
        lbl_8055FED8 = obj;
    }
}

void fn_802DD5F4(void) {
    void *temp_r31 = lbl_8055FED8;

    if (temp_r31 != 0) {
        fn_80128670(*(int*)((char*)temp_r31 + 0x40));
        fn_80128668(temp_r31);
    }
    lbl_8055FED8 = 0;
}

extern float lbl_80565088, lbl_8056508C, lbl_80565090, lbl_80565094;
void fn_802DD63C(int count) {
    float f0 = lbl_80565090;
    float f1 = lbl_8056508C;
    float f2 = lbl_80565094;
    float f3 = lbl_80565088;
    int i;
    float *entry;

    *(int *)((char *)lbl_804DB6A0 + 0x90) = count;
    entry = lbl_804DB6A0;
    for (i = 0; i < *(int *)((char *)lbl_804DB6A0 + 0x90); entry += 9, i++) {
        if (*(int *)((char *)lbl_804DB6A0 + 0x90) < 3) {
            entry[0] = f3; entry[1] = f1; entry[4] = f0; entry[5] = f1;
        } else if (i % 2 == 0) {
            entry[0] = f3; entry[1] = f0; entry[4] = f0; entry[5] = f2;
        } else {
            entry[0] = f0; entry[1] = f1; entry[4] = f2; entry[5] = f1;
        }
        if (*(int *)((char *)lbl_804DB6A0 + 0x90) == 1) {
            entry[2] = f1; entry[3] = f3; entry[6] = f0; entry[7] = f1;
        } else if (i < (*(int *)((char *)lbl_804DB6A0 + 0x90) + 1) / 2) {
            entry[2] = f1; entry[3] = f0; entry[6] = f0; entry[7] = f2;
        } else {
            entry[2] = f0; entry[3] = f3; entry[6] = f2; entry[7] = f1;
        }
        entry[8] = f0;
    }
    *(unsigned char *)((char *)lbl_8055FED8 + 0x4D) = 0;
}

void fn_802DD738(int arg0, float farg0) {
    *(float *)((char *)lbl_804DB6A0 + (arg0 * 0x24) + 0x20) = farg0;
}

void fn_802DD750(void) {
}

extern double lbl_805650A0;
extern float lbl_80565094, lbl_80565098;
void fn_802DE788(void);
void fn_802DD898(void *, float, float);
void fn_802DEA6C(void *);
void fn_802DD754(void) {
    float *entry;
    register int i;
    register int j;
    register int one;
    register void *texObj;
    int count;
    float *base;

    one = 1;
    entry = lbl_804DB6A0;
    count = *(int *)((char *)lbl_804DB6A0 + 0x90);
    while (count > 0) {
        if (entry[8] > lbl_80565098) {
            count = 1;
            break;
        }
        entry += 9;
        count -= 1;
    }
    if (count != 0) {
        fn_802DE788();
        base = lbl_804DB6A0;
        for (i = 0; i < 5; i++) {
            GXSetTexCopySrc(0, 0, (unsigned short)lbl_8055FED0, (unsigned short)lbl_8055FED4);
            texObj = lbl_8055FED8;
            GXSetTexCopyDst(
                (unsigned short)*(int *)((char *)texObj + 0x44),
                (unsigned short)*(int *)((char *)texObj + 0x48),
                4,
                *(unsigned char *)((char *)texObj + 0x4C));
            GXCopyTex(*(void **)((char *)texObj + 0x40), 0);
            *(unsigned char *)((char *)texObj + 0x4D) = one;
            GXLoadTexObj(lbl_8055FED8, 0);
            entry = base;
            for (j = 0; j < *(int *)((char *)base + 0x90); j++) {
                ((void (*)(void *, int, float, float))fn_802DD898)(
                    entry, i, (float)(one << i), lbl_80565094);
                entry += 9;
            }
        }
        ((void (*)(void))fn_802DEA6C)();
    }
}

extern float lbl_8056508C, lbl_80565090, lbl_80565094, lbl_80565098;
extern float lbl_805650A8, lbl_805650AC, lbl_805650B0, lbl_805650B4;
extern float lbl_805650B8, lbl_805650BC, lbl_805650C0, lbl_805650C4;
extern int fn_802CFF64(int);
extern void GXSetArray(unsigned int, void *, unsigned int);
extern void GXBegin(unsigned char, unsigned char, unsigned short);
extern float lbl_8056508C,lbl_80565090,lbl_80565094,lbl_80565098;
extern float lbl_805650A8,lbl_805650AC,lbl_805650B0,lbl_805650B4;
extern float lbl_805650B8,lbl_805650BC,lbl_805650C0,lbl_805650C4;
extern void GXSetArray(unsigned int,void *,unsigned int);
extern void GXBegin(unsigned char,unsigned char,unsigned short);
#pragma scheduling invalid_target
void fn_802DD898(void *arg0,float farg0,float farg1) {
    register float scale=lbl_805650A8;
    int color; int tempColor=0xff;
    register void *box=arg0;
    int alpha;
    register float f31,f30;
    register float t1,t0,t30,t91,t97,t09,z;
    register float xl,xh,yl,yh,ul,uh,vl,vh;
    register float *v;
    register int i;
    alpha=(int)(*(float *)((char *)box+0x20) * scale * farg1);
    alpha=alpha & ((-alpha & ~alpha)>>31);
    if(alpha<0xff) tempColor=alpha;
    color=(int)(tempColor | -0x100);
    f31=((*(float *)((char *)box+0x14)-*(float *)((char *)box+0x10))*farg0*lbl_80565094*lbl_80565098)/lbl_805650AC;
    f30=((*(float *)((char *)box+0x1C)-*(float *)((char *)box+0x18))*farg0*lbl_80565094*lbl_80565098)/lbl_805650AC;
    v=(float *)fn_802CFF64(0x240);
    i=0;
    t0=lbl_80565090; z=lbl_80565094;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t0;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t0;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t0;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t0;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    t09=lbl_805650B0;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t09;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t09;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    t1=lbl_8056508C;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t0;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t1;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t0;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t1;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    t97=lbl_805650B4;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t97;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t97;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t1;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t1;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    t91=lbl_805650B8;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t91;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t97;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t91;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t97;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t0;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t0;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t91;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t09;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t91;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t09;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t0;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t0;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t0;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t0;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t09;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t09;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t09;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t09;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    t30=lbl_805650BC;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t30;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t30;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t97;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t97;
    ((unsigned int *)v)[i*6+5]=0;
    i++;
    t0=lbl_805650C0;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t0;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t0;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t91;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t97;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t91;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t97;
    ((unsigned int *)v)[i*6+5]=0;
    i++;
    t1=lbl_805650C4;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t0;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t0;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t91;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t09;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t91;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t09;
    ((unsigned int *)v)[i*6+5]=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t30;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t30;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t09;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t09;
    ((unsigned int *)v)[i*6+5]=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t30;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t30;
    ((unsigned int *)v)[i*6+5]=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t30;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t30;
    ((unsigned int *)v)[i*6+5]=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t0;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t0;
    ((unsigned int *)v)[i*6+5]=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t30;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t30;
    ((unsigned int *)v)[i*6+5]=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); v[i*6+0]=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); v[i*6+1]=yl+(yh-yl)*t0;
    v[i*6+2]=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; v[i*6+3]=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; v[i*6+4]=vl+(vh-vl)*t0;
    ((unsigned int *)v)[i*6+5]=0;
    i++;
    GXSetArray(9,v,0x18);
    GXSetArray(0xD,v+3,0x18);
    GXSetArray(0xB,v+5,0x18);
    GXBegin(0x98,0,0x18);
    GXPosition1x8(0);GXColor1x8(0);GXTexCoord1x8(0);
    GXPosition1x8(1);GXColor1x8(1);GXTexCoord1x8(1);
    GXPosition1x8(2);GXColor1x8(2);GXTexCoord1x8(2);
    GXPosition1x8(3);GXColor1x8(3);GXTexCoord1x8(3);
    GXPosition1x8(4);GXColor1x8(4);GXTexCoord1x8(4);
    GXPosition1x8(5);GXColor1x8(5);GXTexCoord1x8(5);
    GXPosition1x8(6);GXColor1x8(6);GXTexCoord1x8(6);
    GXPosition1x8(7);GXColor1x8(7);GXTexCoord1x8(7);
    GXPosition1x8(8);GXColor1x8(8);GXTexCoord1x8(8);
    GXPosition1x8(9);GXColor1x8(9);GXTexCoord1x8(9);
    GXPosition1x8(10);GXColor1x8(10);GXTexCoord1x8(10);
    GXPosition1x8(11);GXColor1x8(11);GXTexCoord1x8(11);
    GXPosition1x8(12);GXColor1x8(12);GXTexCoord1x8(12);
    GXPosition1x8(13);GXColor1x8(13);GXTexCoord1x8(13);
    GXPosition1x8(14);GXColor1x8(14);GXTexCoord1x8(14);
    GXPosition1x8(15);GXColor1x8(15);GXTexCoord1x8(15);
    GXPosition1x8(16);GXColor1x8(16);GXTexCoord1x8(16);
    GXPosition1x8(17);GXColor1x8(17);GXTexCoord1x8(17);
    GXPosition1x8(18);GXColor1x8(18);GXTexCoord1x8(18);
    GXPosition1x8(19);GXColor1x8(19);GXTexCoord1x8(19);
    GXPosition1x8(20);GXColor1x8(20);GXTexCoord1x8(20);
    GXPosition1x8(21);GXColor1x8(21);GXTexCoord1x8(21);
    GXPosition1x8(22);GXColor1x8(22);GXTexCoord1x8(22);
    GXPosition1x8(23);GXColor1x8(23);GXTexCoord1x8(23);
}
#pragma scheduling on
void fn_802DE774(void) {
    *(int *)((char *)lbl_804DB6A0 + 0x90) = 0;
}

extern unsigned char lbl_802FAD58[];
extern int lbl_8055FED0, lbl_8055FED4;
extern float lbl_8056508C, lbl_80565090;
extern double lbl_805650A0;
extern void GXClearVtxDesc(void);
extern void GXSetVtxDescv(void *);
extern void GXSetVtxAttrFmtv(int, void *);
extern void GXSetViewport(float, float, float, float, float, float);
extern void GXSetProjection(void *, int);
extern void GXLoadPosMtxImm(void *, int);
extern void GXSetCurrentMtx(int);
extern void GXSetNumChans(int);
extern void GXSetChanCtrl(int, int, int, int, int, int, int);
extern void fn_802DEE88(void);
extern void GXSetColorUpdate(int);
extern void GXSetZMode(int, int, int);
extern void GXSetAlphaCompare(int, int, int, int, int);
void fn_802DE788(void) {
    int desc[8], fmt[16], proj[16], mtx[12];
    int i;
    for (i=0;i<8;i++) desc[i]=((int*)lbl_802FAD58)[i];
    GXClearVtxDesc();
    GXSetVtxDescv(desc);
    for (i=0;i<16;i++) fmt[i]=((int*)(lbl_802FAD58+0x20))[i];
    GXSetVtxAttrFmtv(0,fmt);
    GXSetViewport(lbl_80565090,lbl_80565090,
      (float)lbl_8055FED0,(float)lbl_8055FED4,lbl_80565090,lbl_8056508C);
    for (i=0;i<16;i++) proj[i]=((int*)(lbl_802FAD58+0x60))[i];
    GXSetProjection(proj,1);
    for (i=0;i<12;i++) mtx[i]=((int*)(lbl_802FAD58+0xA0))[i];
    GXLoadPosMtxImm(mtx,0);
    GXSetCurrentMtx(0); GXSetNumChans(1);
    GXSetChanCtrl(4,0,1,1,0,0,2); GXSetChanCtrl(5,0,1,1,0,0,2);
    fn_802DEE88();
    GXSetColorUpdate(1); GXSetZMode(0,7,0); GXSetAlphaCompare(4,0,0,7,255);
}

#pragma scheduling on
void fn_802DEA6C(void* alarm) {
    fn_802D3360(fn_802DEF70(alarm));
}
