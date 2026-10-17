// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F93C;
extern int lbl_8055F940;
extern int lbl_8055F944;
extern int lbl_8055F948;
extern signed char lbl_8055F94C;
extern const char lbl_8055CC88[];
extern int fn_802E2C20(void);
extern int sscanf(const char *, ...);
extern void fn_802AC344(void);
int fn_802AC174(const char *arg0) {
    int sp8;
    sp8 = 0;
    if (sscanf(arg0, &lbl_8055CC88, &sp8) == 1) return sp8;
    return -1;
}

int fn_802AC2B4(void **arg0, int arg1, float *arg2) {
    void *vtable;
    int (*check)(void *);
    float (*value)(void *, int);
    if (arg0 == 0) return 0;
    vtable = *arg0;
    check = *(int (**)(void *))((char *)vtable + 0xC);
    if (check(vtable) == 0) return 0;
    if (arg2 == 0) return 1;
    vtable = *arg0;
    value = *(float (**)(void *, int))((char *)vtable + 0x24);
    *arg2 = value(*arg0, arg1);
    return 1;
}

void fn_802AC454(void) { fn_802AC344(); }

void fn_802AC458(void) {
    lbl_8055F93C = 0;
    lbl_8055F944 = fn_802E2C20();
    lbl_8055F948 = 0;
    lbl_8055F940 = 0;
    lbl_8055F94C = 1;
}

void fn_802AC49C(void) {
    lbl_8055F93C = 0;
}

extern float lbl_80564ACC;
extern float lbl_8055E3C8;
extern int lbl_8055CD70;
extern char lbl_80349FA4[];
extern float lbl_8055E3C8;
extern int lbl_8055CD70;
extern char lbl_80349FB0[];
extern void fn_802E30C8(const char *, ...);
extern void *fn_801284F8(int, void *, void *);
extern void *fn_8012850C(int, void *);
extern int fn_802AC4A8(const char *, int);
void fn_802AD308(void) {}

void fn_802AD414(void *arg0, float farg0) {
 int outer, offset, inner, byteOffset, count, idx; char *group,*entries,*entry,*records,*record; int *p; float a,b;
 outer=0; offset=0;
 while (outer < *(int *)((char *)arg0+0x24)) {
  inner=0; byteOffset=0; group=*(char **)((char *)arg0+0x28)+offset;
  count=*(int *)(group+4)-1;
  if (count>0) {
   entries=*(char **)(group+8);
   do {
    a=*(float *)(entries+byteOffset); entry=entries+byteOffset;
    b=*(float *)(entries+(inner+1)*0x38);
    if (farg0>=a && farg0<=lbl_80564ACC+b) {
     idx=*(int *)group; records=*(char **)((char *)arg0+0x20); record=records+idx*0x28;
     p=*(int **)(record+4); if(p) *p=*(int *)(entry+0x34);
     break;
    }
    byteOffset+=0x38; inner++;
   } while(--count);
  }
  offset+=0xC; outer++;
 }
}

void *fn_802ADDD8(void *arg0,int arg1) {
 int *obj; int data;
 obj=(int *)fn_801284F8(0x10,&lbl_80349FA4,&lbl_80349FA4);
 if(obj){data=(int)fn_8012850C(arg1*0x74,&lbl_8055CD70);obj[0]=data;obj[2]=arg1;obj[1]=0;obj[3]=data;}
 *(int **)arg0=obj; *(float *)((char *)arg0+4)=lbl_8055E3C8; return arg0;
}

int fn_802ADF34(void **arg0,char *arg1,int arg2) {
 int result,index,count; char *header,*entry,*dst; char c;
 result=fn_802AC4A8(arg1,arg2);
 if(result!=0){
  header=(char *)*arg0; index=*(int *)(header+4); entry=*(char **)header+index*0x74;
  *(int *)(header+4)=index+1; dst=entry; count=0x64;
  while(count>0){c=*arg1++;*dst++=c;if((signed char)c==0)break;count--;}
  if(count==0)dst[-1]=0;
  *(int *)(entry+0x64)=result;entry[0x68]=0;entry[0x69]=0;
  return *(int *)(header+4)-1;
 }
 return -1;
}

void fn_802AE0B8(int **arg0,int arg1){unsigned char *p; p=(unsigned char *)**arg0+arg1*0x74;if(p[0x69])p[0x69]=0;}

