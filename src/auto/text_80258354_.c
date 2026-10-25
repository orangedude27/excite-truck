// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

float fn_80235EF0(int, int);
extern float lbl_80563AD0;
extern float fn_80235EF0(int, int);
extern float fn_80235F64(int, int);
extern void fn_802354A0(int, int, int, float, float, float, float);
extern float lbl_80563ACC;
#pragma ppc_psq_save off
extern void fn_80235380(int);
extern void fn_802328D4(int);
extern void fn_80128668(void *);
extern int lbl_80344D98;
__declspec(section ".data") extern int lbl_80344D98;
extern char lbl_80344D88[];
extern void *fn_801284F8(int, void *);
#pragma scheduling invalid_target
void fn_80258354(void) {
    void *p = fn_801284F8(0x1328, lbl_80344D88);
    if (p != 0) {
        *(void **)p = &lbl_80344D98;
        *(void **)((char *)p + 4) = (char *)p + 0x10;
        *(int *)((char *)p + 0xC) = 0x20;
        *(int *)((char *)p + 8) = 0;
        *(void **)((char *)p + 0x910) = (char *)p + 0x91C;
        *(int *)((char *)p + 0x918) = 0x20;
        *(int *)((char *)p + 0x914) = 0;
        *(void **)((char *)p + 0xD9C) = (char *)p + 0xDA8;
        *(int *)((char *)p + 0xDA4) = 0x20;
        *(int *)((char *)p + 0xDA0) = 0;
    }
}
#pragma scheduling on

void *fn_802583CC(void *o, int arg1, int arg2) {
 int i;
 char *p=(char *)o;
 if (o != 0) {
  *(void **)p = &lbl_80344D98;
  for (i=0;i<*(int *)(p+8);i++) fn_80235380(*(int *)(*(char **)(p+4)+i*0x48+0x40));
  *(int *)(p+8)=0;
  for (i=0;i<*(int *)(p+0x914);i++) {
   void *v=*(void **)(*(char **)(p+0x910)+i*0x24+0x20);
   if(v) { fn_802328D4(*(int *)v); *(int *)v=0; fn_80128668(v); }
  }
  *(int *)(p+0x914)=0;
  for (i=0;i<*(int *)(p+0xda0);i++) {
   void *v=*(void **)(*(char **)(p+0xd9c)+i*0x2c+0x20);
   if(v) ((void (*)(void *,int))(*(void ***)v)[1])(v,1);
  }
  *(int *)(p+0xda0)=0;
  if (*(char **)(p+0xd9c)!=0) { *(int *)(p+0xd9c)=0; *(int *)(p+0xda0)=0; *(int *)(p+0xda4)=0; }
  if (*(char **)(p+0x910)!=0) { *(int *)(p+0x910)=0; *(int *)(p+0x914)=0; *(int *)(p+0x918)=0; }
  if (*(char **)(p+4)!=0) { *(int *)(p+4)=0; *(int *)(p+8)=0; *(int *)(p+0xc)=0; }
  if(arg1>0) fn_80128668(o);
 }
 return o;
}

void fn_8025878C(void *arg0, const char *arg1, int flags, int arg3, float x, float y) {
    int index = 0, offset = 0, result, entry;
    float cosine, sine;
    goto check;
loop:
    result = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1);
    if (!((unsigned int)__cntlzw(result) >> 5))
        goto found;
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)arg0 + 8))
        goto loop;
    index = -1;
found:
    if (index < 0) return;
    entry = *(int *)((char *)arg0 + 4) + index * 0x48;
    cosine = fn_80235EF0(*(int *)(entry + 0x40), *(int *)(entry + 0x44));
    sine = fn_80235F64(*(int *)(entry + 0x40), *(int *)(entry + 0x44));
    if (flags & 2) x -= cosine;
    else if (flags & 4) x -= lbl_80563ACC * cosine;
    if (flags & 0x40) y += sine;
    else if (flags & 0x10) y += lbl_80563ACC * sine;
    fn_802354A0(*(int *)(entry + 0x40), *(int *)(entry + 0x44), arg3, x, y, cosine, lbl_80563AD0);
}
void fn_802588C8(void *arg0, const char *arg1, int flags, int arg3, float x, float y, float scale) {
    int index = 0;
    int offset = 0;
    int result;
    float dx, dy, cosine, sine;
    int entry;
    goto check;
loop:
    result = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1);
    if ((unsigned int)__cntlzw(result) >> 5) {
        offset += 0x48;
        index++;
        goto check;
    }
    goto found;
check:
    if (index < *(int *)((char *)arg0 + 8)) goto loop;
    index = -1;
found:
    if (index < 0) return;
    entry = *(int *)((char *)arg0 + 4) + index * 0x48;
    cosine = scale * fn_80235EF0(*(int *)(entry + 0x40), *(int *)(entry + 0x44));
    sine = scale * fn_80235F64(*(int *)(entry + 0x40), *(int *)(entry + 0x44));
    dx = x;
    dy = y;
    if (flags & 2) dx -= cosine;
    else if (flags & 4) dx -= lbl_80563ACC * cosine;
    if (flags & 0x40) dy += sine;
    else if (flags & 0x10) dy += lbl_80563ACC * sine;
    fn_802354A0(*(int *)(entry + 0x40), *(int *)(entry + 0x44), arg3, dx, dy, lbl_80563AD0, cosine);
}
#pragma scheduling invalid_target
float fn_80258A00(void *arg0, int arg1) {
    int index = 0;
    int offset = 0;
    int len;
    goto check;
loop:
    len = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), (const char *)arg1);
    if (((unsigned int)__cntlzw(len) >> 5)) {
        if (lbl_80563AD0) goto found;
        else goto found;
    }
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)arg0 + 8)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        unsigned int p = *(unsigned int *)((char *)arg0 + 4) + index * 0x48;
        return fn_80235EF0(*(unsigned int *)(p + 0x40), *(unsigned int *)(p + 0x44));
    }
    return lbl_80563AD0;
}

float fn_80258AB0(void *arg0, int arg1) {
    int index = 0;
    int offset = 0;
    int len;
    goto check;
loop:
    len = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), (const char *)arg1);
    if (((unsigned int)__cntlzw(len) >> 5)) {
        if (lbl_80563AD0) goto found;
        else goto found;
    }
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)arg0 + 8)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        unsigned int p = *(unsigned int *)((char *)arg0 + 4) + index * 0x48;
        return fn_80235F64(*(unsigned int *)(p + 0x40), *(unsigned int *)(p + 0x44));
    }
    return lbl_80563AD0;
}

#pragma scheduling on
extern int stricmp(const char *, const char *);
extern int fn_80232B70(int, int, int);
extern double lbl_80563AD8;
void *fn_80258D58(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    char *base = (char *)arg0;
    int offset = 0;
    int index = 0;
    char *obj;
    int old, temp;
    goto check;
loop:
    if (stricmp(*(char **)(base + 0x910) + offset, (char *)arg1) == 0)
        goto found;
    offset += 0x24;
    index += 1;
check:
    if (index < *(int *)(base + 0x914))
        goto loop;
    index = -1;
found:
    if (index < 0)
        return 0;
    obj = *(char **)(*(char **)(base + 0x910) + index * 0x24 + 0x20);
    old = *(int *)(obj + 8);
    temp = (arg2 & 7) | (old & ~7);
    *(int *)(obj + 8) = (temp & ~0x58) | (arg2 & 0x78);
    *(float *)(obj + 0xC) = (float)arg3 / (float)fn_80232B70(*(int *)obj, temp, old);
    *(int *)(obj + 4) = arg4;
    return obj;
}

extern float fn_80209028(void);
void fn_80258E64(void *arg0, int arg1) {
    char *base = (char *)arg0;
    int index = 0, offset = 0, result;
    char *entry, *obj;
    float value;
    goto check;
loop:
    result = stricmp(*(char **)(base + 0xD9C) + offset, (char *)arg1);
    if ((unsigned int)__cntlzw(result) >> 5) goto found;
    offset += 0x2C;
    index++;
check:
    if (index < *(int *)(base + 0xDA0)) goto loop;
    index = -1;
found:
    if (index < 0) return;
    entry = *(char **)(base + 0xD9C) + index * 0x2C;
    obj = *(char **)(entry + 0x20);
    if (obj == 0) return;
    value = *(float *)(entry + 0x28) * fn_80209028();
    if (value != *(float *)(obj + 8)) {
        *(unsigned char *)(obj + 0x4D) = 1;
        *(float *)(obj + 8) = value;
    }
    if (*(unsigned char *)(entry + 0x24)) {
        *(unsigned char *)(obj + 0x4A) = 0;
        *(unsigned char *)(obj + 0x4B) = 1;
        *(unsigned char *)(obj + 0x49) = 1;
        return;
    }
    if (*(unsigned char *)(obj + 0x19)) {
        *(unsigned char *)(obj + 0x4C) = 1;
        *(unsigned char *)(obj + 0x4A) = 0;
    }
    *(unsigned char *)(obj + 0x49) = 1;
    *(unsigned char *)(obj + 0x4B) = 0;
    *(unsigned char *)(obj + 0x4A) = 0;
}

