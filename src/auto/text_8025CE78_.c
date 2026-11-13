typedef struct { int id, category, flags; } Record8025;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_80345718[];
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);
extern int lbl_8055F3C4;
extern void fn_80128668(void *);
extern void fn_80214A9C(int);
extern void *fn_8023512C(void *, void *, void *);
extern char lbl_80345694[];
extern char lbl_8055C3E0[];
extern double lbl_80563B68;
extern float lbl_80563B58, lbl_80563B5C, lbl_80563B60;
extern void fn_80230C30(float *, float *, int, int);
extern void fn_802354A0(int, unsigned char, int, float, float, float, float, float);
extern void fn_80231220(int, int, float, float, float, float, float, float, float, float);
void *fn_8025D96C(void *arg0, int arg1)
{
  char *new_var2;
  unsigned int new_var;
  if (arg0)
  {
    int zero = 0;
    new_var2 = (char *) arg0;
    lbl_8055F3C4 = 0;
    if (((new_var2 + 0x18) != 0) && ((((char *) arg0) + 0x18) != 0))
    {
      new_var = 0x18;
      *((int *) (((char *) arg0) + new_var)) = zero;
      *((int *) (((char *) arg0) + 0x1c)) = zero;
      *((int *) (((char *) arg0) + 0x20)) = zero;
    }
    if (arg1 > 0)
    {
      fn_80128668(arg0);
    }
  }
  return arg0;
}

void *fn_8025D9D0(void *arg0) {
    char *src;
    int count;
    char *dst;
    *(volatile int *)((char *)arg0 + 0x420) = 0;
    *(volatile void **)((char *)arg0 + 0x40C) = lbl_80345718;
    *(int *)((char *)arg0 + 0x424) = 0;
    *((char *)arg0 + 0x42C) = 0;
    *(void **)((char *)arg0 + 0x434) = ((void *(*)(const char *))fn_8023512C)(lbl_80345694);
    dst = (char *)arg0 + 4;
    *(void **)arg0 = lbl_8055C3E0;
    src = lbl_8055C3E0;
    count = 0x14;
    goto copy;
    do {
        if (--count <= 0) {
            dst[-1] = 0;
            break;
        }
    copy:
        *dst++ = *src++;
    } while (dst[-1]);
    *(int *)((char *)arg0 + 0x408) = 0;
    *(void **)((char *)arg0 + 0x1C) = lbl_8055C3E0;
    *(void **)((char *)arg0 + 0x18) = lbl_8055C3E0;
    *((char *)arg0 + 0x20) = 0;
    *((char *)arg0 + 0x42C) = 0;
    return arg0;
}

void* __dt__Q28PSSystem7SeqHeapFv_8025DA88(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80345718;
        fn_80235380(*(void**)((char*)arg0 + 0x28), lbl_80345718);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern void *fn_8000DA10(void);
extern int fn_80012854(void);
extern void *fn_8001285C(int);
extern int fn_80012820(void *);
extern void *fn_80016510(int);
extern int fn_8001BA6C(void *);
extern void fn_8001BC38(void *, void *, void *, int, int);
extern int fn_8001BCF0(void *);
extern int fn_8001BD6C(void *, void *);
extern void fn_8001BD38(void *, void *, int);
extern void fn_8001BD54(void *, void *);
extern char *fn_80008188(void *);
extern char *fn_801345D8(char *, int, const char *, ...);
extern int stricmp(const char *, const char *);
extern char lbl_8055C3E4, lbl_8055C3E8, lbl_8055C3EC, lbl_8055C3F8;
extern char lbl_803456A4[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8025DAEC(void *arg0, int arg1) {
    struct Source {
        virtual void s2();
        virtual int has(const char *);
        virtual void s4();
        virtual char *get(const char *);
    };
    char current[0x24], best[0x24], selected[0x24];
    int best_i=-1, j, i, best_j=-1;
    Record8025 record, result;
    char *obj=(char *)arg0;
    for (j=0;j<3;j++) {
        for(i=0;i<fn_80012854();i++) {
            fn_8001BC38(current,fn_8000DA10(),(void *)arg1,i,j);
            if (fn_8001BCF0(current)) {
                if(best_i<0) { best_i=i; best_j=j; }
                else {
                    fn_8001BC38(best,fn_8000DA10(),(void *)arg1,best_i,best_j);
                    if(fn_8001BD6C(current,best)) { best_i=i; best_j=j; }
                }
            }
        }
    }
    *(int *)obj=fn_8001BA6C((void *)arg1);
    if(best_i<0) {
        const char *src=&lbl_8055C3E4;
        int n=0x14;
        char *dst=obj+4;
        goto copy1;
        do { if (--n <= 0) { dst[-1]=0; break; }
copy1:      *dst++=*src++; } while(dst[-1]);
        dst=obj+0x20; src=&lbl_8055C3E8; n=0x3e8;
        goto copy2;
        do { if (--n <= 0) { dst[-1]=0; break; }
copy2:      *dst++=*src++; } while(dst[-1]);
        *(char **)(obj+0x1c)=&lbl_8055C3E4;
        best_j=0;
        *(char **)(obj+0x18)=&lbl_8055C3E4;
    } else {
        char *entry;
        char *value;
        char *details;
        char *table;
        int index, offset;
        int cat;
        fn_8001BC38(selected,fn_8000DA10(),(void *)arg1,best_i,best_j);
        fn_8001BD38(selected,obj+4,0x14);
        entry=(char *)fn_8001285C(best_i);
        if((*(Source **)(entry+0x20))->has(&lbl_8055C3EC))
            *(char **)(obj+0x18)=fn_80008188((*(Source **)(entry+0x20))->get(&lbl_8055C3EC));
        else
            *(char **)(obj+0x18)=fn_80008188((void *)(fn_80012820(*(void **)(entry+4))+8));
        value=(*(Source **)(entry+0x20))->get(lbl_803456A4);
        *(char **)(obj+0x1c)=value;
        fn_801345D8(obj+0x20,0x3e8,&lbl_8055C3F8,*(char **)(obj+0x18),value+1);
        fn_8001BD54(&result,selected);
        record=result;
        cat=record.category;
        obj[0x438]=*(char *)&record.flags;
        details=(char *)fn_80016510(record.id);
        table=*(char **)(obj+0x424);
        for(index=0,offset=0;index<*(int *)(table+4);offset+=0x38,index++) {
            if(stricmp(*(char **)table+offset,details+0x2c)==0) goto found;
        }
        index=-1;
found:
        *(int *)(obj+0x428)=index;
        *(int *)(obj+0x430)=*(int *)(details+cat*4+0x64);
        obj[0x42c]=1;
    }
    *(int *)(obj+0x408)=best_j;
}

  #pragma pop

void fn_8025DDD0(void *arg0, int arg1) {
    float spC, sp8, f25, f24, f26, f27, f28, f29;
    char *base, *entry;
    unsigned int col;
    int b0, b1, b2, s0, s1, s2, color;
    if (*(unsigned char *)((char *)arg0 + 0x20) != 0) {
        fn_80230C30(&spC, &sp8, *(int *)((char *)arg0 + 4), *(int *)((char *)arg0 + 8));
        f25 = (float)*(int *)((char *)arg0 + 0xC);
        f24 = (float)*(int *)((char *)arg0 + 0x10);
        fn_802354A0(*(int *)((char *)arg0 + 0x28), *(unsigned char *)((char *)arg0 + 0x2C), -1, spC - lbl_80563B58, lbl_80563B58 + sp8, lbl_80563B5C, lbl_80563B60 + f25, lbl_80563B60 + f24);
        base = *(char **)((char *)arg0 + 0x18);
        entry = base + *(int *)((char *)arg0 + 0x1C) * 0x38;
        f26 = *(float *)(entry + 0x28);
        f27 = *(float *)(entry + 0x2C);
        f28 = *(float *)(entry + 0x30);
        f29 = *(float *)(entry + 0x34);
        col = *(unsigned int *)((char *)arg0 + 0x24);
        fn_80231220(*(int *)(entry + 0x20), -1, spC, sp8, f25, f24, f26, f27, f28, f29);
        b0 = col & 0xFF;
        b1 = (col >> 8) & 0xFF;
        b2 = (col >> 16) & 0xFF;
        s0 = (b0 * 0xFE01) >> 16;
        s1 = (b1 * 0xFE01) >> 16;
        s2 = (b2 * 0xFE01) >> 16;
        color = (int)(0xFF000000 | (s2 << 16) | (s1 << 8) | s0);
        fn_80231220(*(int *)(entry + 0x24), color, spC, sp8, f25, f24, f26, f27, f28, f29);
    }
}

#pragma push
#pragma cplusplus on
extern "C" void fn_8025DF80(void *arg0) {
    register long *base = (long *)arg0;
    register long offset = 0;
    register long count = 0;
    goto check;
loop:
    fn_80214A9C(*(long *)((unsigned char *)base[6] + offset));
    offset += 4;
    count++;
check:
    if (count < base[7])
        goto loop;
}
#pragma pop
extern void *fn_8000DA10(void); extern int fn_80012854(void); extern void *fn_8001285C(int); extern int fn_80012820(void *); extern void *fn_80016510(int); extern int fn_8001BA6C(void *); extern void fn_8001BC38(void *, void *, void *, int, int); extern int fn_8001BCF0(void *); extern int fn_8001BD6C(void *, void *); extern void fn_8001BD38(void *, void *, int); extern void fn_8001BD54(void *, void *); extern char *fn_80008188(void *); extern char *fn_801345D8(char *, int, const char *, ...); extern int stricmp(const char *, const char *); extern char lbl_8055C3E4, lbl_8055C3E8, lbl_8055C3EC, lbl_8055C3F8; extern char lbl_803456A4[];
