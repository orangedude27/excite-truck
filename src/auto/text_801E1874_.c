// Code of main that had no source file yet: decomp.wtf gave it this one.
extern char lbl_8055EA21;
extern float lbl_8055E3C8, lbl_80558DC4;
extern float lbl_80562CB0, lbl_80562CB4, lbl_80562CB8, lbl_80562CBC, lbl_80562CC0, lbl_80562CC4;
extern int fn_80129D18(int, int);
extern float fn_80129DC4(int, float, float);
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EA20;
extern char lbl_804874D4[];
extern int lbl_804874B8;
extern char lbl_8055EA22;
extern char lbl_8055EA22;
extern float lbl_80562CAC;
extern float lbl_80562CC8;
extern float lbl_80562CCC;
extern float lbl_80562CD0;
extern float lbl_80562CD4;
void fn_801E1B30(void);
extern const char lbl_80339878[];
extern const char lbl_80339884[];
int *fn_801E1F44(void);
void *fn_80207848(const char *, int);
#pragma scheduling invalid_target
void fn_801E1874(void) {
    *(volatile int *)lbl_804874D4 = 0;
    *((volatile char *)lbl_804874D4 + 0x18) = 0;
    *((volatile char *)lbl_804874D4 + 4) = 0;
    lbl_8055EA22 = 0;
}
#pragma scheduling on
extern void *fn_802AE414(const char *);
extern int stricmp(const char *, const char *);
extern unsigned char lbl_8055AE60[], lbl_8055AE68[], lbl_8055AE6C[], lbl_8055AE74[], lbl_8055AE7C[], lbl_8055AE84[], lbl_8055AE8C[], lbl_8055AE94[], lbl_8055AE9C[], lbl_8055AEA8[];
extern unsigned char lbl_80339860[], lbl_8033986C[];
extern float lbl_80562CA8;
int fn_801E1894(void) {
 void **obj; void **settings; char *name; float v[3]; int r,g,b;
 fn_801E1874();
 if (fn_802AE414((const char *)lbl_8055AE60) != 0) {
  obj=fn_802AE414((const char *)lbl_8055AE60);
  settings=((void **(*)(void *,const char *))(*(void ***)obj)[23])(obj,(const char *)lbl_8055AE68);
  name=((char *(*)(void *,const char *,const char *))(*(void ***)obj)[6])(obj,(const char *)lbl_8055AE6C,(const char *)lbl_8055AE74);
  if(stricmp(name,(const char *)lbl_8055AE7C)==0) *(int *)&lbl_804874D4=1;
  else if(stricmp(name,(const char *)lbl_8055AE84)==0) *(int *)&lbl_804874D4=2;
  if(((int(*)(void *,const char *))(*(void ***)obj)[3])(obj,(const char *)lbl_80339860)!=0)
   lbl_8055EA22=((int(*)(void *,const char *))(*(void ***)obj)[11])(obj,(const char *)lbl_80339860);
  else lbl_8055EA22=(*(int *)&lbl_804874D4==1);
  *((unsigned char *)&lbl_804874D4+4)=((int(*)(void *,const char *,int))(*(void ***)obj)[12])(obj,(const char *)lbl_8033986C,0);
  if(settings) {
   ((void(*)(float *,void *,const char *))(*(void ***)settings)[13])(v,settings,(const char *)lbl_8055AE8C);
   r=(int)(lbl_80562CA8*v[0]); if(r<0)r=-r; if(r>255)r=255;
   g=(int)(lbl_80562CA8*v[1]); if(g<0)g=-g; if(g>255)g=255;
   b=(int)(lbl_80562CA8*v[2]); if(b<0)b=-b; if(b>255)b=255;
   *(int *)((char *)&lbl_804874D4+8)=(r<<16)|0xff000000|(g<<8)|b;
   *(float *)((char *)&lbl_804874D4+0xc)=((float(*)(void *,const char *))(*(void ***)settings)[9])(settings,(const char *)lbl_8055AE94);
   *(float *)((char *)&lbl_804874D4+0x10)=((float(*)(void *,const char *))(*(void ***)settings)[9])(settings,(const char *)lbl_8055AE9C);
   *(float *)((char *)&lbl_804874D4+0x14)=((float(*)(void *,const char *))(*(void ***)settings)[9])(settings,(const char *)lbl_8055AEA8);
   *((unsigned char *)&lbl_804874D4+0x18)=1;
  }
 }
 lbl_8055EA20=1;
 return 0;
}

void fn_801E1D20(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D2C(void) {
    lbl_8055EA20 = 0;
}

void fn_801E1D38(void) {
    int *base;
    if (*fn_801E1F44() == 1) {
        base = &lbl_804874B8;
        base[5] = (int)fn_80207848(lbl_80339878, 2);
        base[6] = (int)fn_80207848(lbl_80339884, 2);
    }
}

void fn_801E1D9C(void) {
    void *p;
    p = *(void **)((char *)&lbl_804874B8 + 0x18);
    if (p != 0) {
        ((void (*)(void *, int))(*(void ***)p)[2])(p, 1);
        *(void **)((char *)&lbl_804874B8 + 0x18) = 0;
    }
    p = *(void **)((char *)&lbl_804874B8 + 0x14);
    if (p != 0) {
        ((void (*)(void *, int))(*(void ***)p)[2])(p, 1);
        *(void **)((char *)&lbl_804874B8 + 0x14) = 0;
    }
}

void fn_801E1E30(void) {
    int v = lbl_8055EA22;
    float x = lbl_80562CAC;
    float z = lbl_80562CC8;
    *((float *)&lbl_804874B8 + 1) = x;
    *(int *)&lbl_804874B8 = (v | -v) >> 31 & 1;
    *((float *)&lbl_804874B8 + 2) = x;
    *((float *)&lbl_804874B8 + 3) = z;
}

extern int fn_801E1894(void);
extern float lbl_80562CCC;
extern float lbl_80562CD0;
extern float lbl_80562CD4;
extern void fn_801E1B30(void);
void fn_801E1E64(void) {
    int *base = (int *)&lbl_804874B8;
    void *p = *(void **)((char *)base + 0x14);
    if (p != 0) {
        *(unsigned char *)((char *)p + 0x4A) = 0;
        *(unsigned char *)((char *)p + 0x4B) = 1;
        *(unsigned char *)((char *)p + 0x49) = 1;
    }
    if (*base != 0)
        fn_801E1B30();
}

void fn_801E1EA4(void *arg0) {
    int i;
    int count = *(int *)((char *)arg0 + 0x394);
    void *base = (char *)arg0 + 4;
    float *cfg = (float *)&lbl_804874B8;
    for (i = 0; i < count; i++) {
        int type = lbl_804874B8;
        if (type == 3) {
            *(float *)((char *)base + 0xD4) = lbl_80562CAC;
            *(float *)((char *)base + 0xD8) = lbl_80562CD4 * cfg[1];
            *(float *)((char *)base + 0xDC) = lbl_80562CAC;
        } else if (type == 2) {
            *(float *)((char *)base + 0xD4) = lbl_80562CCC * cfg[1];
            *(float *)((char *)base + 0xD8) = lbl_80562CD0 * cfg[1];
            *(float *)((char *)base + 0xDC) = cfg[4];
        } else {
            *(float *)((char *)base + 0xD4) = lbl_80562CAC;
            *(float *)((char *)base + 0xD8) = lbl_80562CAC;
            *(float *)((char *)base + 0xDC) = lbl_80562CAC;
        }
        base = (char *)base + 0xE0;
    }
}

int *fn_801E1F44(void) {
    if ((unsigned char)lbl_8055EA20 == 0)
        fn_801E1894();
    return (int *)&lbl_804874D4;
}

extern char lbl_8055EA21;
extern float lbl_8055E3C8;
extern float lbl_80558DC4;
extern float lbl_80562CB0, lbl_80562CB4, lbl_80562CB8, lbl_80562CBC, lbl_80562CC0, lbl_80562CC4;
extern int fn_80129D18(int, int);
extern float fn_80129DC4(int, float, float);
void fn_801E1F78(void) {
    lbl_8055EA21 = 1;
}
typedef struct { int pad0; float x; float y; float z; char pad10[4]; void *p14; void *p18; } Obj;
