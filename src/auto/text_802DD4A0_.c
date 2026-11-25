#include "revolution/GX/GXVert.h"
typedef struct { int words[8]; } GXDescCopy;
typedef struct { int words[16]; } GXMatrix4Copy;
typedef struct { int words[12]; } GXMatrix3Copy;
typedef struct { GXDescCopy desc; GXMatrix4Copy fmt; GXMatrix4Copy proj; GXMatrix3Copy mtx; } GXBlockCopy;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void *fn_80128668(void *);
void fn_80128670(int);
extern void *lbl_8055FED8;
extern float lbl_804DB6A0[];
/* Scalar deleting-style helper: zero the first three fields when non-null,
 * then free storage via fn_80128668 (operator delete, mode 3) if deletingFlag > 0. */
void *fn_802DD4A0(void *object, int deletingFlag) {
    void *result = object;
    if (object != (void *)0) {
        if ((object != (void *)0) && (object != (void *)0)) {
            *(int *)object = 0;
            *(int *)((char *)object + 4) = 0;
            *(int *)((char *)object + 8) = 0;
        }
        if (deletingFlag > 0) {
            fn_80128668(result);
        }
    }
    return result;
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
/* Allocates and initializes the cached blur texture object from the current render
 * target dimensions, storing half-size width/height and an RGB565 texture buffer. */
void fn_802DD4FC(void) {
#pragma scheduling invalid_target
#pragma opt_common_subs off
    void *renderInfo = fn_802D2D14();
    lbl_8055FED0 = *(unsigned short *)((char *)renderInfo + 4);
    lbl_8055FED4 = *(unsigned short *)((char *)renderInfo + 6);
    {
        void *texObj = fn_801284F8(0x50, lbl_8034CB50);
        if (texObj != 0) {
            int height, width;
            height = lbl_8055FED4;
            width = lbl_8055FED0;
            *(unsigned char *)((char *)texObj + 0x4C) = 1;
            if (*(unsigned char *)((char *)texObj + 0x4C)) {
                *(volatile int *)((char *)texObj + 0x44) = width / 2;
                *(volatile int *)((char *)texObj + 0x48) = height / 2;
            } else {
                *(volatile int *)((char *)texObj + 0x44) = width;
                *(volatile int *)((char *)texObj + 0x48) = height;
            }
            {
                int texWidth = *(volatile int *)((char *)texObj + 0x44);
                int texHeight = *(volatile int *)((char *)texObj + 0x48);
                *(int *)((char *)texObj + 0x40) = fn_8012850C(texHeight * (texWidth * 2), lbl_8034CB5C);
            }
            GXInitTexObj(texObj, *(void **)((char *)texObj + 0x40), *(int *)((char *)texObj + 0x44), *(int *)((char *)texObj + 0x48), 4, 0, 0, 0);
            GXInitTexObjFilter(texObj, 1, 1);
            *(unsigned char *)((char *)texObj + 0x4D) = 0;
        }
        lbl_8055FED8 = texObj;
    }
}

/* RealName: Gfx_DestroyCachedTexObj (release cached texture object and clear global)
 * If the global cached texture object exists, releases its owned resource at +0x40
 * and frees the object, then clears the global pointer.
 */
void fn_802DD5F4(void) {
#define sCachedTexObj lbl_8055FED8
    void *temp_r31 = sCachedTexObj;

    if (temp_r31 != 0) {
        fn_80128670(*(int*)((char*)temp_r31 + 0x40));
        fn_80128668(temp_r31);
    }
    sCachedTexObj = 0;
#undef sCachedTexObj
}

extern float lbl_80565088, lbl_8056508C, lbl_80565090, lbl_80565094;
/* Initialize per-region split-screen UV/bounds entries for the given region count and clear the cached texture dirty flag. */
void fn_802DD63C(int numRegions) {
    float two;
    float one;
    float zero;
    float negOne;
    int i;
    float *entry;
    int regionCount;

    zero = lbl_80565090;
    one = lbl_8056508C;
    two = lbl_80565094;
    negOne = lbl_80565088;
    *(int *)((char *)lbl_804DB6A0 + 0x90) = numRegions;
    entry = lbl_804DB6A0;
    for (i = 0; i < (regionCount = *(int *)((char *)lbl_804DB6A0 + 0x90)); entry += 9, i++) {
        if (regionCount < 3) {
            entry[0] = negOne; entry[1] = one; entry[4] = zero; entry[5] = one;
        } else if (i % 2 == 0) {
            entry[0] = negOne; entry[1] = zero; entry[4] = zero; entry[5] = two;
        } else {
            entry[0] = zero; entry[1] = one; entry[4] = two; entry[5] = one;
        }
        if (regionCount == 1) {
            entry[2] = one; entry[3] = negOne; entry[6] = zero; entry[7] = one;
        } else if (i < (regionCount + 1) / 2) {
            entry[2] = one; entry[3] = zero; entry[6] = zero; entry[7] = two;
        } else {
            entry[2] = zero; entry[3] = negOne; entry[6] = two; entry[7] = one;
        }
        entry[8] = zero;
    }
    *(unsigned char *)((char *)lbl_8055FED8 + 0x4D) = 0;
}

void fn_802DD738(int index, float value) {
    /* Set the +0x20 field of the index-th 0x24-byte entry in the texture-copy cache table. */
    *(float *)((char *)lbl_804DB6A0 + (index * 0x24) + 0x20) = value;
}

void fn_802DD750(void) {
    /* Empty no-op in the split-screen view-region / texture-copy cache group,
       sitting between fn_802DD738 (cache write) and fn_802DD754.  When reached
       through the fn_802C2C68 tail-call wrapper the caller's arguments are
       ignored and nothing changes; compiles to a bare 'blr'. */
}

extern double lbl_805650A0;
extern float lbl_80565094, lbl_80565098;
void fn_802DE788(void);
void fn_802DD898(void *, float, float);
void fn_802DEA6C();
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_common_subs off
void fn_802DD754(void)
{
  float *entry;
  register int i;
  register int j;
  register int one;
  register void *texObj;
  int new_var;
  int found;
  float *base;
  one = 1;
  entry = lbl_804DB6A0;
  for (found = *((int *) (((char *) lbl_804DB6A0) + 0x90)); found > 0; found--, entry += 9)
  {
    if (entry[8] > lbl_80565098)
    {
      found = 1;
      goto done;
    }
  }

  found = 0;
  done:
  if (found != 0)
  {
    fn_802DE788();
    base = lbl_804DB6A0;
    for (i = 0; i < 5; i++)
    {
      texObj = lbl_8055FED8;
      GXSetTexCopySrc(0, 0, (unsigned short) lbl_8055FED0, (unsigned short) lbl_8055FED4);
      GXSetTexCopyDst((unsigned short) (*((int *) (((char *) texObj) + 0x44))), (unsigned short) (*((int *) (((char *) texObj) + 0x48))), 4, *((unsigned char *) (((char *) texObj) + 0x4C)));
      new_var = i;
      GXCopyTex(*((void **) (((char *) texObj) + 0x40)), 0);
      *((unsigned char *) (((char *) texObj) + 0x4D)) = one;
      GXLoadTexObj(lbl_8055FED8, 0);
      entry = lbl_804DB6A0;
      for (j = 0; j < (*((int *) (((char *) base) + 0x90))); j++)
      {
        ((void (*)(void *, int, float, float)) fn_802DD898)(entry, new_var, (float) (one << i), lbl_80565094);
        entry += 9;
      }

    }

    ((void (*)(void)) fn_802DEA6C)();
  }

}
#pragma pop
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
    color=tempColor | -0x100;
    f31=((*(float *)((char *)box+0x14)-*(float *)((char *)box+0x10))*farg0*lbl_80565094*lbl_80565098)/lbl_805650AC;
    f30=((*(float *)((char *)box+0x1C)-*(float *)((char *)box+0x18))*farg0*lbl_80565094*lbl_80565098)/lbl_805650AC;
    v=(float *)fn_802CFF64(0x240);
    i=0;
    t0=lbl_80565090; z=lbl_80565094;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t0;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t0;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t0;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t0;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    t09=lbl_805650B0;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t09;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t09;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    t1=lbl_8056508C;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t0;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t1;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t0;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t1;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    t97=lbl_805650B4;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t97;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t97;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t1;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t1;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    t91=lbl_805650B8;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t91;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t97;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t91;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t97;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t0;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t0;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t91;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t09;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t91;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t09;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t0;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t0;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t0;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t0;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t09;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t09;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t09;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t09;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    t30=lbl_805650BC;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t30;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t30;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t97;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t97;
    *(unsigned int *)((char *)v+i*24+20)=0;
    i++;
    t0=lbl_805650C0;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t0;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t0;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t91;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t97;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t91;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t97;
    *(unsigned int *)((char *)v+i*24+20)=0;
    i++;
    t1=lbl_805650C4;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t0;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t0;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t91;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t09;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t91;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t09;
    *(unsigned int *)((char *)v+i*24+20)=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t30;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t30;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t09;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t09;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t09;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t09;
    *(unsigned int *)((char *)v+i*24+20)=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t30;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t30;
    *(unsigned int *)((char *)v+i*24+20)=color;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t30;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t30;
    *(unsigned int *)((char *)v+i*24+20)=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t30;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t0;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t30;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t0;
    *(unsigned int *)((char *)v+i*24+20)=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t30;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t30;
    *(unsigned int *)((char *)v+i*24+20)=0;
    i++;
    xh=*(float *)((char *)box+0x4); xl=*(float *)((char *)box+0x0); *(float *)((char *)v+i*24)=xl+(xh-xl)*t1;
    yh=*(float *)((char *)box+0xC); yl=*(float *)((char *)box+0x8); *(float *)((char *)v+i*24+4)=yl+(yh-yl)*t0;
    *(float *)((char *)v+i*24+8)=z;
    uh=*(float *)((char *)box+0x14)-f31; ul=*(float *)((char *)box+0x10)+f31; *(float *)((char *)v+i*24+12)=ul+(uh-ul)*t1;
    vh=*(float *)((char *)box+0x1C)-f30; vl=*(float *)((char *)box+0x18)+f30; *(float *)((char *)v+i*24+16)=vl+(vh-vl)*t0;
    *(unsigned int *)((char *)v+i*24+20)=0;
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
    i=16; do { GXPosition1x8((u8)i); GXColor1x8((u8)i); GXTexCoord1x8((u8)i); i++; } while (i<0x18);
}
#pragma scheduling on
void fn_802DE774(void) {
    /* Clear the texture-copy cache by resetting its valid-entry count to zero. */
#define gTexCopyCache lbl_804DB6A0
    *(int *)((char *)gTexCopyCache + 0x90) = 0;
#undef gTexCopyCache
}

extern unsigned int lbl_802FAD58[];
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
#pragma push
#pragma use_lmw_stmw off
void fn_802DE788(void) {
    GXDescCopy desc;
    GXMatrix4Copy fmt, proj;
    GXMatrix3Copy mtx;
    GXDescCopy *pd = (GXDescCopy *)lbl_802FAD58;
    GXMatrix4Copy *pf = (GXMatrix4Copy *)((char *)lbl_802FAD58 + 0x20);
    GXMatrix4Copy *pp = (GXMatrix4Copy *)((char *)lbl_802FAD58 + 0x60);
    GXMatrix3Copy *pm = (GXMatrix3Copy *)((char *)lbl_802FAD58 + 0xA0);
    desc.words[0] = pd->words[0];
    desc.words[1] = pd->words[1]; desc.words[2] = pd->words[2]; desc.words[3] = pd->words[3];
    desc.words[4] = pd->words[4]; desc.words[5] = pd->words[5]; desc.words[6] = pd->words[6]; desc.words[7] = pd->words[7];
    GXClearVtxDesc();
    GXSetVtxDescv(&desc);
    fmt.words[0] = ((GXMatrix4Copy *)lbl_802FAD58)->words[0];
    fmt.words[1] = pf->words[1]; fmt.words[2] = pf->words[2]; fmt.words[3] = pf->words[3];
    fmt.words[4] = pf->words[4]; fmt.words[5] = pf->words[5]; fmt.words[6] = pf->words[6]; fmt.words[7] = pf->words[7];
    fmt.words[8] = pf->words[8]; fmt.words[9] = pf->words[9]; fmt.words[10] = pf->words[10]; fmt.words[11] = pf->words[11];
    fmt.words[12] = pf->words[12]; fmt.words[13] = pf->words[13]; fmt.words[14] = pf->words[14]; fmt.words[15] = pf->words[15];
    GXSetVtxAttrFmtv(0,&fmt);
    GXSetViewport(lbl_80565090,lbl_80565090,
        (float)lbl_8055FED0,(float)lbl_8055FED4,lbl_80565090,lbl_8056508C);
    proj.words[0] = ((GXMatrix4Copy *)((char *)lbl_802FAD58 + 0x60))->words[0];
    proj.words[1] = pp->words[1]; proj.words[2] = pp->words[2]; proj.words[3] = pp->words[3];
    proj.words[4] = pp->words[4]; proj.words[5] = pp->words[5]; proj.words[6] = pp->words[6]; proj.words[7] = pp->words[7];
    proj.words[8] = pp->words[8]; proj.words[9] = pp->words[9]; proj.words[10] = pp->words[10]; proj.words[11] = pp->words[11];
    proj.words[12] = pp->words[12]; proj.words[13] = pp->words[13]; proj.words[14] = pp->words[14]; proj.words[15] = pp->words[15];
    GXSetProjection(&proj,1);
    mtx.words[0] = ((GXMatrix3Copy *)((char *)lbl_802FAD58 + 0xA0))->words[0];
    mtx.words[1] = pm->words[1]; mtx.words[2] = pm->words[2]; mtx.words[3] = pm->words[3];
    mtx.words[4] = pm->words[4]; mtx.words[5] = pm->words[5]; mtx.words[6] = pm->words[6]; mtx.words[7] = pm->words[7];
    mtx.words[8] = pm->words[8]; mtx.words[9] = pm->words[9]; mtx.words[10] = pm->words[10]; mtx.words[11] = pm->words[11];
    GXLoadPosMtxImm(&mtx,0);
    GXSetCurrentMtx(0); GXSetNumChans(1);
    GXSetChanCtrl(4,0,1,1,0,0,2); GXSetChanCtrl(5,0,1,1,0,0,2);
    fn_802DEE88();
    GXSetColorUpdate(1); GXSetZMode(0,7,0); GXSetAlphaCompare(4,0,0,7,255);
}
#pragma pop
void fn_802DEF70(void); /* video.c: GXSetTevSwapMode(0,0,0) + apply pending blend mode */
void gxInitRenderState(void); /* gx.c: rebuild default texcoord-gen / TEV / matrix state */
/* Restores the renderer's default state at the end of the glow/blur pass:
 * clears the TEV swap mode and applies any pending blend-mode change, then
 * rebuilds the default texture-coordinate generators, TEV order/op and
 * current matrix. */
void fn_802DEA6C(void) {
    fn_802DEF70();
    gxInitRenderState();
}
