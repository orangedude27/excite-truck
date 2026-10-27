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
extern char lbl_8055C258[];
__declspec(section ".sdata") extern char lbl_8055C258[];
extern float lbl_80563AC8;
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

extern int fn_8023512C(void *);
#pragma scheduling invalid_target
void fn_80258550(void *arg0, const char *arg1, const char *arg2, int arg3) {
    struct Entry { char first[0x20]; char second[0x20]; void *field; int value; };
    struct Entry *entry;
    int count;
    char *dst;
    count = 0x20;
    entry = &((struct Entry *)(*(unsigned int *)((char *)arg0 + 4)))[(*(int *)((char *)arg0 + 8))++];
    dst = entry->first;
    while (1) {
        count--;
        if (count <= 0) {
            dst[-1] = 0;
            break;
        }
        if ((*dst++ = *arg1++) == 0) break;
    }
    arg1 = arg2;
    dst = entry->second;
    count = 0x20;
    while (1) {
        count--;
        if (count <= 0) {
            dst[-1] = 0;
            break;
        }
        if ((*dst++ = *arg1++) == 0) break;
    }
    entry->field = (void *)fn_8023512C((void *)arg2);
    entry->value = arg3;
}
#pragma scheduling on
void fn_8025861C(void *arg0, const char *arg1, void *arg2) {
    register int count;
    register unsigned char *base;
    register unsigned char *dst;
    register int n;
    unsigned char c;
    void *p;

    count = *(int *)((char *)arg0 + 0x914);
    base = *(unsigned char **)((char *)arg0 + 0x910) + count * 0x24;
    *(int *)((char *)arg0 + 0x914) = count + 1;
    dst = base;
    n = 0x20;
    goto copy;
check:
    n--;
    if (n > 0) goto copy;
    dst[-1] = 0;
    goto copied;
copy:
    c = *arg1++;
    *dst++ = c;
    if ((signed char)c != 0) goto check;
copied:
    p = fn_801284F8(0x14, lbl_8055C258);
    if (p != 0) {
        *(int *)((char *)p + 0) = 0;
        *(int *)((char *)p + 4) = -1;
        *(int *)((char *)p + 8) = 9;
        *(float *)((char *)p + 0xC) = lbl_80563AC8;
        *(float *)((char *)p + 0x10) = lbl_80563AC8;
        *(int *)((char *)p + 0) = fn_80232578(arg2);
    }
    /* Store the new object's pointer beside its bounded copied name. */
    *(void **)(base + 0x20) = p;
}
#pragma scheduling on
extern void *fn_80207848(int, int);
extern float lbl_80563AC8;
#pragma scheduling invalid_target
void fn_802586F0(void *arg0, void *arg1, int arg2, int arg3) {
    char *base = (char *)arg0;
    int index;
    char *entry;
    char *dst;
    char *ptr = (char *)arg1;
    int count = 0x20;
    char c;
    index = *(int *)(base + 0xDA0);
    entry = *(char **)(base + 0xD9C) + index * 0x2C;
    *(int *)(base + 0xDA0) = index + 1;
    dst = entry;
    while (1) {
        count--;
        if (count <= 0) {
            dst[-1] = 0;
            break;
        }
        do {
            c = *ptr++;
            *dst++ = c;
        } while (c != 0);
    }
    *(void **)(entry + 0x20) = fn_80207848(arg2, 0);
    *(float *)(entry + 0x28) = lbl_80563AC8;
    *(char *)(entry + 0x24) = arg3;
}
#pragma scheduling invalid_target
void fn_8025878C(void *arg0, const char *arg1, int flags, int arg3, float x, float y) {
    int index = 0;
    int offset = 0;
    float cosine;
    float sine;
    goto check;
loop:
    switch ((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1)) >> 5) {
    case 0:
        offset += 0x48;
        index++;
        goto check;
    default:
        goto found;
    }
check:
    if (index < *(int *)((char *)arg0 + 8))
        goto loop;
    index = -1;
found:
    if (index < 0)
        return;
    index = (int)(*(unsigned int *)((char *)arg0 + 4) + index * 0x48);
    cosine = fn_80235EF0(*(int *)(index + 0x40), *(int *)(index + 0x44));
    sine = fn_80235F64(*(int *)(index + 0x40), *(int *)(index + 0x44));
    if (flags & 2)
        x -= cosine;
    else if (flags & 4)
        x -= lbl_80563ACC * cosine;
    if (flags & 0x40)
        y += sine;
    else if (flags & 0x10)
        y += lbl_80563ACC * sine;
    ((void (*)(int, int, int, float, float, float, float, float))fn_802354A0)(
        *(int *)(index + 0x40), *(int *)(index + 0x44), arg3,
        x, y, lbl_80563AD0, cosine, sine);
}
#pragma paired_single off
#pragma ppc_psq_save off
#pragma use_lmw_stmw on
#pragma scheduling invalid_target
void fn_802588C8(void *arg0, const char *arg1, int flags, int arg3, float x, float y, float scale) {
    int index = 0;
    int offset = 0;
    int result;
    int callId0;
    int callId1;
    float callX;
    float callY;
    float callColor;
    float callCosine;
    register float sine;
    register float cosine;
    goto check;
loop:
    result = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1);
    if ((unsigned int)__cntlzw(result) >> 5) {
        if (lbl_80563AD0)
            goto found;
        else
            goto found;
    }
    offset += 0x48;
    index++;
    goto check;
check:
    if (index < *(int *)((char *)arg0 + 8))
        goto loop;
    index = -1;
found:
    if (index < 0)
        return;
    index = *(int *)((char *)arg0 + 4) + index * 0x48;
    cosine = scale * fn_80235EF0(*(int *)(index + 0x40), *(int *)(index + 0x44));
    sine = scale * fn_80235F64(*(int *)(index + 0x40), *(int *)(index + 0x44));
    if (flags & 2)
        x -= cosine;
    else if (flags & 4)
        x -= lbl_80563ACC * cosine;
    if (flags & 0x40)
        y += sine;
    else if (flags & 0x10)
        y += lbl_80563ACC * sine;
    callX = x;
    callId0 = *(int *)(index + 0x40);
    callY = y;
    callColor = lbl_80563AD0;
    callCosine = cosine;
    callId1 = *(int *)(index + 0x44);
    fn_802354A0(callId0, callId1, arg3, callX, callY, callColor, callCosine);
}
#pragma scheduling on
#pragma paired_single reset
#pragma ppc_psq_save off
#pragma use_lmw_stmw reset
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

#pragma push
#pragma scheduling on
void *fn_80258B60(void *arg0, const char *arg1) {
    int index = 0;
    int offset = 0;
    int len;
    goto check;
loop:
    len = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1);
    if (((unsigned int)__cntlzw(len) >> 5))
        goto found;
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)arg0 + 8))
        goto loop;
    index = -1;
found:
    if (index >= 0) {
        int byte_offset = index;
        byte_offset *= 0x48;
        return (void *)((char *)*(unsigned int *)((char *)arg0 + 4) + byte_offset + 0x20);
    }
    return 0;
}

int fn_80258C08(void *arg0, const char *arg1) {
    int index = 0;
    int offset = 0;
    int entry_offset;
    unsigned int entries;
    goto check;
loop:
    if (((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1)) >> 5) == 0) goto increment;
found:
    goto done;
increment:
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)arg0 + 8)) goto loop;
    index = -1;
done:
    /* Return the final word of the matching 0x48-byte entry. */
    if (index >= 0) {
        entry_offset = index * 0x48;
        entries = *(unsigned int *)((char *)arg0 + 4);
        return *(int *)(entries + entry_offset + 0x44);
    }
    return 0;
}

int fn_80258CB0(void *arg0, const char *arg1) {
    int index = 0;
    int offset = 0;
    goto check;
loop:
    if (((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)arg0 + 0x910) + offset), arg1)) >> 5) == 0) {
        offset += 0x24;
        index++;
        goto check;
    }
    goto found;
check:
    if (index < *(int *)((char *)arg0 + 0x914)) goto loop;
    index = -1;
found:
    /* Return the word at offset 0x20 in the matching 0x24-byte entry. */
    if (index >= 0) return *(int *)(*(unsigned int *)((char *)arg0 + 0x910) + index * 0x24 + 0x20);
    return 0;
}

#pragma pop
extern int stricmp(const char *, const char *);
extern int fn_80232B70(int, int, int);
extern double lbl_80563AD8;
void *fn_80258D58(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    char *base = (char *)arg0;
    int index = 0;
    int offset = 0;
    int compare;
    char *obj;
    unsigned int old;
    unsigned int temp;
    unsigned int mask;
    goto check;
loop:
    compare = stricmp(*(char **)(base + 0x910) + offset, (char *)arg1);
    switch ((unsigned int)__cntlzw((unsigned int)compare) >> 5) {
    case 0:
        goto increment;
    default:
        goto found;
    }
increment:
    offset += 0x24;
    index++;
check:
    if (index < *(int *)(base + 0x914))
        goto loop;
    index = -1;
found:
    if (index >= 0) {
        int divisor;
        obj = *(char **)(*(char **)(base + 0x910) + index * 0x24 + 0x20);
        temp = (unsigned int)arg2 & 7;
        old = *(unsigned int *)(obj + 8);
        mask = (unsigned int)arg2 & 0x78;
        temp = __rlwimi(temp, old, 0, 0, 28);
        *(unsigned int *)(obj + 8) = (temp & ~0x58U) | mask;
        divisor = fn_80232B70(*(int *)obj, temp, old);
        *(float *)(obj + 0xC) = (float)arg3 / (float)divisor;
        *(int *)(obj + 4) = arg4;
        return obj;
    }
    return 0;
}

extern float fn_80209028(void);
void fn_80258E64(void *arg0, const char *arg1) {
    int index = 0;
    int offset = 0;
    void *obj;
    float value;
    goto check;
loop:
    switch ((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)arg0 + 0xD9C) + offset), arg1)) >> 5) {
    case 0:
        offset += 0x2C;
        index++;
        goto check;
    default:
        goto found;
    }
check:
    if (index < *(int *)((char *)arg0 + 0xDA0))
        goto loop;
    index = -1;
found:
    if (index < 0)
        return;
    index = (int)(*(unsigned int *)((char *)arg0 + 0xD9C) + index * 0x2C);
    if (*(void **)(index + 0x20) == 0)
        return;
    value = *(float *)(index + 0x28) * fn_80209028();
    obj = *(void **)(index + 0x20);
    if (value != *(float *)((char *)obj + 8)) {
        *(unsigned char *)((char *)obj + 0x4D) = 1;
        *(float *)((char *)obj + 8) = value;
    }
    if (*(unsigned char *)(index + 0x24)) {
        obj = *(void **)(index + 0x20);
        *(unsigned char *)((char *)obj + 0x4A) = 0;
        *(unsigned char *)((char *)obj + 0x4B) = 1;
        *(unsigned char *)((char *)obj + 0x49) = 1;
        return;
    }
    obj = *(void **)(index + 0x20);
    if (*(unsigned char *)((char *)obj + 0x19)) {
        *(unsigned char *)((char *)obj + 0x4C) = 1;
        *(unsigned char *)((char *)obj + 0x4A) = 0;
    }
    obj = *(void **)(index + 0x20);
    *(unsigned char *)((char *)obj + 0x49) = 1;
    *(unsigned char *)((char *)obj + 0x4B) = 0;
    *(unsigned char *)((char *)obj + 0x4A) = 0;
}

void fn_80258F94(void *arg0, const char *arg1) {
    int index = 0;
    int offset = 0;
    unsigned int entry;
    void *object;
    goto check;
loop:
    switch ((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)arg0 + 0xD9C) + offset), arg1)) >> 5) {
    case 0:
        offset += 0x2C;
        index++;
        goto check;
    default:
        goto found;
    }
check:
    if (index < *(int *)((char *)arg0 + 0xDA0)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        entry = *(unsigned int *)((char *)arg0 + 0xD9C);
        entry += index * 0x2C;
        object = *(void **)(entry + 0x20);
        if (object != 0) {
            /* Mark the matched object active and clear its secondary flag. */
            *(unsigned char *)((char *)object + 0x4A) = 1;
            *(unsigned char *)((char *)object + 0x4C) = 0;
        }
    }
}

#pragma scheduling invalid_target
void fn_8025904C(void *arg0, int arg1, float farg0) {
    int index = 0;
    int offset = 0;
    int len;
    goto check;
loop:
    len = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 0xD9C) + offset), (const char *)arg1);
    if (((unsigned int)__cntlzw(len) >> 5)) {
        if (lbl_80563AD0) goto found;
        else goto found;
    }
    offset += 0x2C;
    index++;
check:
    if (index < *(int *)((char *)arg0 + 0xDA0)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        struct Entry { char pad[0x28]; float value; };
        ((struct Entry *)(*(unsigned int *)((char *)arg0 + 0xD9C)))[index].value = farg0;
    }
}
#pragma scheduling on

