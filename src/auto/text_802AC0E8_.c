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
void *fn_802AC0E8(void *arg0, const char *arg1, int arg2) {
    char *node = (char *)arg0;
    int key = arg2;
    const char *name = arg1;
    if (node == 0)
        return 0;
    while (*(int *)node != 0) {
        if (*(int *)node == key && strcmp(*(const char **)(node + 4), name) == 0)
            return node;
        node += 0xC;
    }
    return 0;
}

int fn_802AC174(const char *arg0) {
    int sp8;
    sp8 = 0;
    if (sscanf(arg0, &lbl_8055CC88, &sp8) == 1) return sp8;
    return -1;
}

extern char *strstr(const char *, const char *);
extern int lbl_802FAA50[];
int fn_802AC1BC(const char *arg0, int arg1) {
    struct Entry { const char *text; int flags; unsigned char align; };
    struct Entry entries[12];
    struct Entry *entry;
    int i;
    int flags = 0;
    int has_align = 0;
    int has_no_align = 0;
    for (i = 0; i < 12; ++i) {
        entries[i].text = ((struct Entry *)lbl_802FAA50)[i].text;
        entries[i].flags = ((struct Entry *)lbl_802FAA50)[i].flags;
        entries[i].align = ((struct Entry *)lbl_802FAA50)[i].align;
    }
    entry = entries;
    while (entry->text != 0) {
        if (strstr(arg0, entry->text) != 0) {
            flags = (flags & (entry->align ? ~7 : 7)) | entry->flags;
            if (has_align == 0 || entry->align != 0) has_align = 1;
            if (has_no_align == 0 || entry->align == 0) has_no_align = 1;
        }
        entry++;
    }
    if (has_align == 0) flags |= 4;
    if (has_no_align == 0) flags |= 0x10;
    return flags;
}

int fn_802AC2B4(void **arg0, int arg1, float *arg2) {
    if (arg0 != 0 && ((int (*)(void *))(*(void **)((char *)*arg0 + 0xC)))(arg0) != 0) {
        if (arg2 != 0) {
            *arg2 = ((float (*)(void *, int))(*(void **)((char *)*arg0 + 0x24)))(arg0, arg1);
        }
        return 1;
    }
    return 0;
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
extern void fn_802AD4C4(void *, int, float);
extern int strcmp(const char *, const char *);
extern float lbl_8055E3C8;
extern int lbl_8055CD70;
extern char lbl_80349FB0[];
extern void fn_802E30C8(const char *, int);
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

int fn_802ADCF8(int arg0) {
    int var_r0;
    int temp_r4;
    int temp_r3;
    int toggle;
    switch (arg0) {
    case 0x5B:
        temp_r3 = lbl_8055F940 - 1;
        lbl_8055F940 = temp_r3 < -1 ? -1 : temp_r3;
        return 1;
    case 0x5D:
        temp_r4 = (int)lbl_8055F93C - 1;
        var_r0 = lbl_8055F940 + 1;
        if (temp_r4 < var_r0) var_r0 = temp_r4;
        lbl_8055F940 = var_r0;
        return 1;
    case 0x22:
        lbl_8055F944 = fn_802E2C20();
        lbl_8055F948 = 0;
        return 1;
    case 0x27:
        toggle = ((unsigned char)lbl_8055F94C == 0);
        lbl_8055F94C = toggle;
        if (toggle) lbl_8055F948 = fn_802E2C20() - lbl_8055F944;
        return 1;
    default: return 0;
    }
}

void *fn_802ADDD8(void *arg0,int arg1) {
 int *obj; int data;
 obj=(int *)fn_801284F8(0x10,&lbl_80349FA4,&lbl_80349FA4);
 if(obj){data=(int)fn_8012850C(arg1*0x74,&lbl_8055CD70);obj[0]=data;obj[2]=arg1;obj[1]=0;obj[3]=data;}
 *(int **)arg0=obj; *(float *)((char *)arg0+4)=lbl_8055E3C8; return arg0;
}

extern void fn_80128668(void *);
extern void fn_80128670(void *);
extern void fn_802AD30C(void *);
void *fn_802ADE60(void **arg0, int arg1) {
    int count;
    int offset;
    void *obj;
    int zero;

    if (arg0 != 0) {
        count = *(int *)((char *)*arg0 + 4);
        offset = count * 0x74;
        while (count > 0) {
            fn_802AD30C(*(void **)(*(char **)*arg0 + offset + 0x64));
            count--;
            offset -= 0x74;
        }
        *(int *)((char *)*arg0 + 4) = 0;
        obj = *arg0;
        if (obj != 0) {
            fn_80128670(*(void **)((char *)obj + 0xC));
            if (obj != 0) {
                zero = 0;
                *(int *)((char *)obj + 0) = zero;
                *(int *)((char *)obj + 4) = zero;
                *(int *)((char *)obj + 8) = zero;
            }
            fn_80128668(obj);
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
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

void fn_802ADFF4(int **arg0,int arg1){unsigned char *p=*(unsigned char **)*arg0+arg1*0x74;if(p[0x68]==0){p[0x68]=1;p[0x69]=0;*(float *)(p+0x6c)=lbl_8055E3C8;}}

void fn_802AE02C(void *arg0, int arg1) {
    char **p;
    char *base;
    unsigned char *entry;
    p = *(char ***)arg0;
    base = *p;
    entry = (unsigned char *)base + arg1 * 0x74;
    if (!entry[0x69]) {
        if (!entry[0x68]) {
            fn_802E30C8(lbl_80349FB0, arg1);
            entry[0x68] = 1;
            *(float *)(entry + 0x6c) = *(float *)((char *)arg0 + 4);
        }
        entry[0x69] = 1;
        *(float *)(entry + 0x70) = *(float *)((char *)arg0 + 4);
    }
}

void fn_802AE0B8(int **arg0,int arg1){unsigned char *p; p=(unsigned char *)**arg0+arg1*0x74;if(p[0x69])p[0x69]=0;}

void fn_802AE0E0(void **arg0){int off=0,i=0;while(i<*(int *)(*(char **)arg0+4)){*(unsigned char *)(*(char **)*(char **)arg0+off+0x68)=0;off+=0x74;i++;}}

void fn_802AE118(void *arg0){int i=0,off=0;char *container=*(char **)arg0;while(i<*(int *)(container+4)){unsigned char *entry=(unsigned char *)*(char **)container+off;if(entry[0x68])*(float *)(entry+0x6c)=*(float *)((char *)arg0+4)-*(float *)(*(char **)(entry+0x64)+0x2c);off+=0x74;i++;}}

#pragma push
#pragma use_lmw_stmw off
void fn_802AE168(void *arg0) {
    extern float lbl_8055E3C8;
    extern void fn_802AD414(void *, float);
    int offset = 0;
    int i = 0;
    unsigned char *entry;
    *(float *)((char *)arg0 + 4) = lbl_8055E3C8;
    while (i < *(int *)(*(char **)arg0 + 4)) {
        entry = (unsigned char *)*(char **)*(char **)arg0 + offset;
        if (entry[0x69]) {
            *(float *)(entry + 0x6c) = *(float *)(entry + 0x6c) + (*(float *)((char *)arg0 + 4) - *(float *)(entry + 0x70));
            *(float *)(entry + 0x70) = *(float *)((char *)arg0 + 4);
        }
        if (entry[0x68]) fn_802AD414(*(void **)(entry + 0x64), *(float *)((char *)arg0 + 4) - *(float *)(entry + 0x6c));
        offset += 0x74;
        i++;
    }
}
#pragma pop
void fn_802AE220(void *arg0,int arg1){int offset=0,i=0;unsigned char *entry;while(i<*(int *)(*(char **)arg0+4)){entry=(unsigned char *)*(char **)*(char **)arg0+offset;if(entry[0x68])fn_802AD4C4(*(void **)(entry+0x64),arg1,*(float *)((char *)arg0+4)-*(float *)(entry+0x6c));offset+=0x74;i++;}}

