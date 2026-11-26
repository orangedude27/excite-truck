// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

/* One entry of the Locale module's language table (lbl_802F8E60), one per
 * supported language: "usenglish.res"/"English (US)"/"flag_usa.art" and
 * "japanese.res"/"Japanese"/"flag_jp.art". */
typedef struct {
    /* 0x00 */ char *resName;     /* archive holding the messages */
    /* 0x04 */ char *displayName; /* name shown in the language menu */
    /* 0x08 */ char *flagArt;     /* flag icon art */
} LocaleLanguage;

/* The Locale module's data block (lbl_804230D0): which language's resource is
 * loaded and the message table copied out of it. */
typedef struct {
    /* 0x00 */ s32 language;     /* loaded language index, -1 = none loaded */
    /* 0x04 */ char *msgTable;   /* message table, 0 until one is loaded */
    /* 0x08 */ u8 table[0xC350]; /* the table, copied in from the resource */
} LocaleData;

extern char lbl_80423040[];
extern char lbl_8032B028[];
__declspec(section ".sdata") extern char lbl_80559A5C[];
__declspec(section ".sdata") extern char lbl_80559A64[];
__declspec(section ".sdata") extern char lbl_80559A6C[];
__declspec(section ".sdata") extern char lbl_80559A74[];
__declspec(section ".sdata") extern char lbl_80559A7C[];
__declspec(section ".sdata") extern char lbl_80559A84[];
__declspec(section ".sdata") extern char lbl_80559A8C[];
__declspec(section ".sdata") extern char lbl_80559A94[];
extern int lbl_8055E044;
typedef struct {
    char *key;
    char *value;
    int tick;
} CacheEntry;
typedef struct {
    char *f0;
    char *f1;
    float f2;
    int f3;
} Rec10;
typedef struct {
    char pad[0xC3E8];
    CacheEntry entries[12];
    Rec10 records[7];
} LargeStruct;
typedef struct ObjVTable ObjVTable;
struct ObjVTable {
    void *slot0;
    void *slot1;
    char *(*getName)(void *self);
    void *(*getChild)(void *self, int index);
    void *slot4;
    void *slot5;
    char *(*getString)(void *self, const char *key, char *def);
    void *slot7;
    int (*getInt)(void *self, const char *key, int def);
    void *slot9;
    float (*getFloat)(void *self, const char *key, float def);
};
typedef struct {
    ObjVTable *vt;
} Obj;
extern Obj *fn_80131808(void *arg);
extern void fn_80131818(Obj *arg);
extern void fn_80131318(int *arg);
extern void *fn_80131234();
extern void fn_8013072C(char *, int, int);
#pragma inline off(fn_801302E0)
#pragma inline off(fn_801305C4)
extern int fn_801302E0(void *);

__declspec(section ".sdata") extern char lbl_80559AF8;
extern char lbl_8032B224[];
__declspec(section ".sdata") extern char lbl_80559B00[];

extern int lbl_804230D0;
extern char lbl_80423054[];
extern char lbl_8042F4B8[];
extern char lbl_8055E048;
extern void fn_8013111C();

typedef struct {
    int f[26];
    char pad[12];
    char f2;
} MsgCopy;

extern int lbl_802F8E60[];
extern int lbl_8055E04C;
extern char *lbl_8055E050;
extern int fn_8012BF24(void *);
extern int stricmp(const char *, const char *);
void fn_8012FAB8(void *arg0)
{
  char *srcBase;
  char *dstBase;
  srcBase = lbl_80423040 + 0x10000;
  dstBase = lbl_8032B028;
  {
    int *e = (int *) ((lbl_80423040 + 0x10000) - 0x3C18);
    if (((unsigned int) e[2]) != ((unsigned int) lbl_8055E044))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0xA0)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3C0C);
    if (((unsigned int) lbl_8055E044) != ((unsigned int) e[2]))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0xB0)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3C00);
    if (((unsigned int) lbl_8055E044) != ((unsigned int) e[2]))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0xC0)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3BF4);
    if (((unsigned int) e[2]) != ((unsigned int) lbl_8055E044))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0xD0)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3BE8);
    if (((unsigned int) lbl_8055E044) != ((unsigned int) e[2]))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0xE0)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3BDC);
    if (((unsigned int) e[2]) != ((unsigned int) lbl_8055E044))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0xF0)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3BD0);
    if (((unsigned int) lbl_8055E044) != ((unsigned int) e[2]))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0x124)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3BC4);
    if (((unsigned int) lbl_8055E044) != ((unsigned int) e[2]))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0x134)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3BB8);
    if (((unsigned int) lbl_8055E044) != ((unsigned int) e[2]))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0x144)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3BAC);
    if (((unsigned int) lbl_8055E044) != ((unsigned int) e[2]))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0x154)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3BA0);
    if (((unsigned int) e[2]) != ((unsigned int) lbl_8055E044))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0x164)) = (char *) e[1];
  }
  {
    int *e = (int *) (srcBase - 0x3B94);
    if (((unsigned int) lbl_8055E044) != ((unsigned int) e[2]))
    {
      fn_80131318(e);
    }
    *((char **) (dstBase + 0x174)) = (char *) e[1];
  }
  if (arg0 != 0)
  {
    Obj *child;
    Obj *parent;
    Rec10 *records;
    parent = fn_80131808(arg0);
    if (parent != 0)
    {
      long index;
      index = 1;
      child = (Obj *) parent->vt->getChild(parent, 0);
      records = (Rec10 *) (srcBase - 0x3B88);
srcBase = 0;
      while (child != 0)
      {
        if (stricmp(lbl_80559A5C, child->vt->getName(child)) == 0)
        {
          records[0].f0 = child->vt->getString(child, lbl_80559A64, records[0].f0);
          records[0].f1 = child->vt->getString(child, lbl_80559A6C, records[0].f0);
          records[0].f2 = child->vt->getFloat(child, lbl_80559A74, records[0].f2);
          records[0].f3 = child->vt->getInt(child, lbl_80559A7C, records[0].f3);
        }
        if (stricmp(lbl_80559A84, child->vt->getName(child)) == 0)
        {
          records[1].f0 = child->vt->getString(child, lbl_80559A64, records[1].f0);
          records[1].f1 = child->vt->getString(child, lbl_80559A6C, records[1].f0);
          records[1].f2 = child->vt->getFloat(child, lbl_80559A74, records[1].f2);
          records[1].f3 = child->vt->getInt(child, lbl_80559A7C, records[1].f3);
        }
        if (stricmp(lbl_80559A8C, child->vt->getName(child)) == 0)
        {
          records[2].f0 = child->vt->getString(child, lbl_80559A64, records[2].f0);
          records[2].f1 = child->vt->getString(child, lbl_80559A6C, records[2].f0);
          records[2].f2 = child->vt->getFloat(child, lbl_80559A74, records[2].f2);
          records[2].f3 = child->vt->getInt(child, lbl_80559A7C, records[2].f3);
        }
        if (stricmp(dstBase + 0x198, child->vt->getName(child)) == 0)
        {
          records[3].f0 = child->vt->getString(child, lbl_80559A64, records[3].f0);
          records[3].f1 = child->vt->getString(child, lbl_80559A6C, records[3].f0);
          records[3].f2 = child->vt->getFloat(child, lbl_80559A74, records[3].f2);
          records[3].f3 = child->vt->getInt(child, lbl_80559A7C, records[3].f3);
        }
        if (stricmp(dstBase + 0x1A8, child->vt->getName(child)) == 0)
        {
          records[4].f0 = child->vt->getString(child, lbl_80559A64, records[4].f0);
          records[4].f1 = child->vt->getString(child, lbl_80559A6C, records[4].f0);
          records[4].f2 = child->vt->getFloat(child, lbl_80559A74, records[4].f2);
          records[4].f3 = child->vt->getInt(child, lbl_80559A7C, records[4].f3);
        }
        if (stricmp(lbl_80559A94, child->vt->getName(child)) == 0)
        {
          records[5].f0 = child->vt->getString(child, lbl_80559A64, records[5].f0);
          records[5].f1 = child->vt->getString(child, lbl_80559A6C, records[5].f0);
          records[5].f2 = child->vt->getFloat(child, lbl_80559A74, records[5].f2);
          records[5].f3 = child->vt->getInt(child, lbl_80559A7C, records[5].f3);
        }
        if (stricmp(dstBase - (-0x1B4), child->vt->getName(child)) == 0)
        {
          records[6].f0 = child->vt->getString(child, lbl_80559A64, records[6].f0);
          records[6].f1 = child->vt->getString(child, lbl_80559A6C, records[6].f0);
          records[6].f2 = child->vt->getFloat(child, lbl_80559A74, records[6].f2);
          records[6].f3 = child->vt->getInt(child, lbl_80559A7C, records[6].f3);
        }
        child = (Obj *) parent->vt->getChild(parent, (0, index++));
      }

      fn_80131818(parent);
    }
  }
}

/* Byte-swap a loaded big-endian LANG table in place: the 32-bit entry count at
   +0x40 is swapped first, then every stored pointer offset at +0x44 onward is
   byte-swapped and relocated by adding the table base address. */
void fn_801301E0(unsigned char *table) {
    #pragma scheduling invalid_target
    unsigned char t3, t1, t0;
    unsigned char *wordA;
    unsigned char *wordB;
    unsigned char *reloc;
    unsigned char t2;
    int i;

    t0 = table[0x40];
    reloc = table;
    t1 = table[0x42];
    wordA = table + 0x44;
    t2 = table[0x41];
    t3 = table[0x43];
    wordB = table + 0x48;
    table[0x40] = table[0x43];
    i = 0;
    table[0x43] = t0;
    table[0x41] = table[0x42];
    table[0x42] = t2;
    for (; i < *(int *)(table + 0x40); i++) {
        t1 = wordA[0]; t3 = wordA[3]; wordA[0] = t3; wordA[3] = t1;
        t3 = wordA[1]; t1 = wordA[2]; wordA[1] = t1; wordA[2] = t3;
        wordA += 8;
        t3 = wordB[0]; t1 = wordB[3]; wordB[0] = t1; wordB[3] = t3;
        t3 = wordB[1]; t1 = wordB[2]; wordB[1] = t1; wordB[2] = t3;
        wordB += 8;
        *(unsigned int *)(reloc + 0x44) += (unsigned int)table;
        *(unsigned int *)(reloc + 0x48) += (unsigned int)table;
        reloc += 8;
    }
}

__declspec(section ".data") extern int lbl_804230D0;
#pragma dont_inline on
/* Release the language resource archive the Locale module has loaded, if any,
 * and mark that no language is loaded any more.  fn_8012BF24 releases a
 * resource by name; the archive of language n is named by entry n of the
 * Locale language table (lbl_802F8E60). */
void fn_8013028C(void) {
#define sLocaleData (*(LocaleData *)&lbl_804230D0)
#define sLocaleLanguages ((LocaleLanguage *)lbl_802F8E60)
    int index = sLocaleData.language;
    if (index >= 0 && (unsigned int)index < 2) {
        fn_8012BF24(sLocaleLanguages[index].resName);
    }
    sLocaleData.language = -1;
#undef sLocaleData
#undef sLocaleLanguages
}

int fn_801302E0(void *arg0) {
    char *base = (char *)&lbl_804230D0;
    char **head = (char **)(base + 4);
    int offset, index;
    if (*head != 0) {
        index = 0;
        offset = 0;
        while (index < *(int *)(*head + 0x40)) {
            if (stricmp((const char *)arg0, *(const char **)(*head + offset + 0x44)) == 0)
                return *(int *)(*(char **)((char *)&lbl_804230D0 + 4) + index * 8 + 0x48);
            offset += 8;
            index++;
        }
    }
    return 0;
}

#pragma dont_inline reset

/* Returns the resource-archive name (word 0 of the 12-byte LocaleLanguage entry) for the currently selected language. */
int fn_80130390(void) {
    int langIndex = lbl_8055E04C;
    return *(int *)((char *)lbl_802F8E60 + langIndex * 12);
}

extern char lbl_80423054[];
extern char lbl_8042F4B8[];
extern char lbl_8055E048;
extern void fn_8013111C();
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_801303A8(void) {
    register int v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11;
    register int v12, v13, v14, v15, v16, v17, v18, v19, v20, v21;
    register int v22, v23, v24, v25, v26, v27;
    unsigned char c;
    register int *s;
    register int *d;

    lbl_8055E048 = 1;
    lbl_804230D0 = -1;
    fn_8013111C(lbl_8055E04C);
    s = (int *)lbl_8042F4B8;
    d = (int *)lbl_80423054;

    v24 = s[24]; d[26] = v24;
    v22 = s[22]; d[24] = v22;
    v25 = s[25]; d[27] = v25;
    v26 = s[26]; d[28] = v26;
    v27 = s[27]; d[29] = v27;
    c = *((unsigned char *)s + 0x70);

    v0 = s[0]; v1 = s[1]; v2 = s[2]; v3 = s[3];
    v4 = s[4]; v5 = s[5]; v6 = s[6]; v7 = s[7];
    v8 = s[8]; v9 = s[9]; v10 = s[10]; v11 = s[11];
    v12 = s[12]; v13 = s[13]; v14 = s[14]; v15 = s[15];
    v16 = s[16]; v17 = s[17]; v18 = s[18]; v19 = s[19];
    v20 = s[20]; v21 = s[21]; v23 = s[23];
    d[2] = v0; d[3] = v1; d[4] = v2; d[5] = v3;
    d[6] = v4; d[7] = v5; d[8] = v6; d[9] = v7;
    d[10] = v8; d[11] = v9; d[12] = v10; d[13] = v11;
    d[14] = v12; d[15] = v13; d[16] = v14; d[17] = v15;
    d[18] = v16; d[19] = v17; d[20] = v18; d[21] = v19;
    d[22] = v20; d[23] = v21; d[25] = v23;

    *((char *)d + 0x78) = c;
    lbl_80423054[0] = c ? 0x2C : 0x2E;
}
#pragma scheduling on
#pragma use_lmw_stmw on
void fn_80130518(void) {
    /* Reset locale/resource state and clear the locale data buffer. */
    fn_8013028C();
    *(int *)((char *)&lbl_804230D0 + 4) = 0;
    memset((char *)&lbl_804230D0 + 8, 0, 0xC350);
    lbl_8055E048 = 0;
}

extern void *lbl_80559AA0;
extern void *lbl_80559AA8;
extern void fn_801345D8(void *, ...);
static inline void format_append(char *dstp, int sizep, char *str) {
    char *dst = dstp;
    int size = sizep;
    char *src;
    char c;
    while (*dst != 0) {
        size--;
        dst++;
    }
    if (size > 0) {
        src = str;
        goto copy;
    count_check:
        if (--size > 0)
            goto copy;
        dst[-1] = 0;
        goto done;
    copy:
        c = *src++;
        *dst++ = c;
        if (c != 0)
            goto count_check;
    done:;
    }
}

extern char *strchr(const char *, int);
#pragma opt_propagation off
#pragma opt_common_subs off
/* Localize decimal points: replace every '.' in text with the active locale's decimal-separator character (lbl_8055E050[0]); no-op when that separator is '.'. */
void fn_80130568(char *text) {
    char *base = text;
    if (*(char *)lbl_8055E050 != '.') {
        while ((text = strchr(base, '.')) != 0) {
            *text = *(char *)lbl_8055E050;
        }
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
void fn_801305C4(char *arg0, int arg1, Rec10 *arg2, int arg3, float farg0)
{
  if (farg0 == 0)
  {
    fn_801345D8(arg0, arg1, &lbl_80559AA0, 1, (int) (farg0 * arg2->f2));
  }
  else
  {
    fn_801345D8(arg0, arg1, &lbl_80559AA8, 1, farg0, farg0 * arg2->f2);
  }
  switch (arg3)
  {
    case 0:
      break;

    case 1:
      format_append(arg0, arg1, arg2->f1 + 1);
      break;

    case 2:
      format_append(arg0, arg1, arg2->f0 + 1);
      break;

  }

}
#pragma scheduling on

#pragma opt_lifetimes off
void fn_8013072C(char *arg0, int arg1, int arg2) {
    int sign = arg2 >> 31;
    int magnitude = (sign ^ arg2) - sign;
    unsigned int negative = (unsigned int)arg2 >> 31;
    register int digits;
    int groups;
    int high;
    int quotient;
    char *p;
    int current;

    high = magnitude;
    quotient = magnitude / 1000;
    groups = 0;
    while (quotient > 0) {
        high = quotient;
        quotient /= 1000;
        groups++;
    }
    if (high < 10)
        digits = 1;
    else if (high < 100)
        digits = 2;
    else
        digits = 3;
    p = arg0 + groups * 4 + digits + negative;
    p[1] = 0;
    if (arg2 == 0) {
        p[0] = '0';
        p--;
    } else {
        current = arg2 < 0 ? -arg2 : arg2;
        while (current > 0) {
            if (current >= 1000) {
                int d1, d2, d3;
                d1 = current % 10;
                current /= 10;
                d2 = current % 10;
                current /= 10;
                d3 = current % 10;
                p[0] = (char)(d1 + '0');
                p[-1] = (char)(d2 + '0');
                p[-2] = (char)(d3 + '0');
                p[-3] = ',';
                current /= 10;
                p -= 4;
            } else {
                int q;
                q = current / 10;
                p[0] = (char)(current % 10 + '0');
                current = q;
                p--;
            }
        }
        if (negative != 0) {
            p[0] = '-';
            p--;
        }
    }
    *p = 1;
}
#pragma opt_lifetimes reset
void fn_801305C4(char *arg0, int arg1, Rec10 *arg2, int arg3, float farg0);
#pragma dont_inline on
/* Format with the global locale record at lbl_8055E050+8 into dst (size bytes);
 * suffixKind picks the appended unit suffix and value is scaled by the record's factor. */
void fn_801308E4(void *dst, int size, int suffixKind, float value) {
    fn_801305C4(dst, size, (Rec10 *)((char *)lbl_8055E050 + 8), suffixKind, value);
}
#pragma dont_inline reset

/* Format an integer as comma-grouped decimal text into dst for on-screen display (size is the buffer capacity, ignored by the formatter). */
void fn_801308F4(char *dst, int size, int value) {
    fn_8013072C(dst, size, value);
}

/* Write a score into a text buffer of `size` bytes.  A score under 1000 is
 * spelled out as a comma-grouped number by fn_8013072C; one at or over that no
 * longer fits the field, so the localized string of the "Locale:OUT_OF_BOUNDS_SCORE"
 * key (lbl_8032B224) is copied in instead -- the current language's overflow
 * text, or "???" (lbl_80559B00) when it has no entry for the key.  The copy
 * stops at the string's NUL; a buffer too small for it gets its last byte
 * turned into the NUL, so the text is cut short rather than running past it. */
void fn_801308F8(char *dst, int size, int score) {
    char *src;
    unsigned char c;
    if (score < 1000)
        goto formatNumber;
    src = (char *)fn_80131234(lbl_8032B224);
    goto copy;
size_check:
    if (--size > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto size_check;
    goto done;
formatNumber:
    fn_8013072C(dst, size, score);
done:
    ;
}

extern void fn_801345D8(void *, ...);
__declspec(section ".sdata") extern char lbl_80559A9C[];
__declspec(section ".sdata") extern char lbl_80559AE4[];
__declspec(section ".sdata") extern char lbl_80559AEC[];
__declspec(section ".sdata") extern char lbl_80559AF0[];
__declspec(section ".sdata") extern char lbl_80559AF4[];
extern char lbl_8032B240[];
typedef struct {
    char c;
    char *s;
} TimeSepEnt;
typedef struct {
    TimeSepEnt e[13];
} TimeSepTab;
extern TimeSepTab lbl_802F8E78;
__declspec(section ".data") extern float lbl_80558DC0;
extern float lbl_805612C8;
extern float lbl_805612CC;

static inline void time_append(char *dstp, int sizep, char *str) {
    char *dst = dstp;
    int size = sizep;
    char *src;
    char c;
    while (*dst != 0) {
        size--;
        dst++;
    }
    if (size > 0) {
        src = str;
        goto copy;
    count_check:
        if (--size > 0)
            goto copy;
        dst[-1] = 0;
        goto done;
    copy:
        c = *src++;
        *dst++ = c;
        if (c != 0)
            goto count_check;
    done:;
    }
}

static inline void time_append_sizefirst(char *dstp, int sizep, char *str) {
    char *dst;
    int size;
    char *src;
    size = sizep;
    dst = dstp;
    while (*dst != 0) {
        size--;
        dst++;
    }
    if (size > 0) {
        src = str;
        goto copy;
    count_check:
        if (--size > 0)
            goto copy;
        dst[-1] = 0;
        goto done;
    copy:
        if ((*dst++ = *src++) != 0)
            goto count_check;
    done:;
    }
}

static inline void time_append2(char *dstp, int sizep, char *str) {
    int size = sizep;
    char *dst = dstp;
    char *src;
    char c;
    while (*dst != 0) {
        size--;
        dst++;
    }
    if (size > 0) {
        src = str;
        goto copy;
    count_check:
        if (--size > 0)
            goto copy;
        dst[-1] = 0;
        goto done;
    copy:
        c = *src++;
        *dst++ = c;
        if (c != 0)
            goto count_check;
    done:;
    }
}

void fn_80130980(char *out, int size, int level, float t);
/* Format `seconds` into `out` (capacity `size`) down to tenths of a second:
 * convenience wrapper that calls the general time formatter at level 3. */
void fn_80130978(char *out, int size, float seconds) { fn_80130980(out, size, 3, seconds); }

void fn_80130980(char *out, int size, int level, float seconds) {
    char buf[100];
    char hoursStr[12];
    char minsStr[12];
    char secsStr[12];
    char tenthsStr[12];
    char hundredthsStr[12];
    char tenthsSep[8];
    TimeSepTab sepTable;
    int mins, hundredths, tenths, secs, hours;
    int hasPrev;
    int found;
    char *src;
    char *p;
    char c;
    unsigned int i;

    /* Format a time in seconds into `out` at precision `level` (0=hours ..
     * 4=hundredths), localizing digits/separators via the separator table;
     * the negative-time sentinel instead prints the localized empty string. */
    if (seconds == -lbl_80558DC0) {
        src = fn_80131234(lbl_8032B240);
        goto copy;
    count_check:
        if (--size > 0)
            goto copy;
        out[-1] = 0;
        return;
    copy:
        c = *src++;
        *out++ = c;
        if (c != 0)
            goto count_check;
        return;
    }
    hundredths = (int)(lbl_805612C8 * seconds) % 10;
    tenths = (int)(lbl_805612CC * seconds) % 10;
    secs = (int)seconds % 60;
    mins = ((int)seconds / 60) % 60;
    hours = (int)seconds / 3600;
    buf[0] = 0;
    hasPrev = 0;
    if (level >= 0 && hours > 0) {
        fn_801345D8(hoursStr, 10, lbl_80559A9C, hours);
        time_append(buf, 100, hoursStr);
        hasPrev = 1;
    }
    if (level >= 1 && (mins > 0 || hasPrev)) {
        if (hasPrev)
            fn_801345D8(minsStr, 10, lbl_80559AE4, lbl_80559AEC, 2, mins);
        else
            fn_801345D8(minsStr, 10, lbl_80559A9C, mins);
        time_append(buf, 100, minsStr);
        hasPrev = 1;
    }
    if (level >= 2) {
        if (hasPrev)
            fn_801345D8(secsStr, 10, lbl_80559AE4, lbl_80559AEC, 2, secs);
        else
            fn_801345D8(secsStr, 10, lbl_80559A9C, secs);
        time_append(buf, 100, secsStr);
        hasPrev = 1;
    }
    if (level >= 3) {
        fn_801345D8(tenthsSep, 8, lbl_80559AF0, *lbl_8055E050);
        if (hasPrev)
            fn_801345D8(tenthsStr, 10, lbl_80559AE4, tenthsSep, 1, tenths);
        else
            fn_801345D8(tenthsStr, 10, lbl_80559A9C, tenths);
        time_append(buf, 100, tenthsStr);
        hasPrev = 1;
    }
    if (level >= 4) {
        if (hasPrev)
            fn_801345D8(hundredthsStr, 10, lbl_80559AE4, lbl_80559AF4, 1, hundredths);
        else
            fn_801345D8(hundredthsStr, 10, lbl_80559A9C, hundredths);
        time_append(buf, 100, hundredthsStr);
    }
    fn_801345D8(out, size, lbl_80559AF0, 1);
    sepTable = lbl_802F8E78;
    for (p = buf; *p != 0; p++) {
        found = 0;
        for (i = 0; found == 0 && i < 13; i++) {
            if (*p == sepTable.e[i].c) {
                time_append_sizefirst(out, size, sepTable.e[i].s);
                found = 1;
            }
        }
        if (!found) {
            char tmp[2] = {0};
            tmp[0] = *p;
            time_append_sizefirst(out, size, tmp);
        }
    }
}

extern void *lbl_80559AA0;
#pragma scheduling invalid_target
/* Write the `\x01` control code followed by the decimal `value` into the
 * game-text buffer `dst` (`size` bytes); `\x01` makes the game's text renderer
 * display the number that follows. */
void fn_80130FCC(char *dst, int size, int value) {
    fn_801345D8(dst, size, &lbl_80559AA0, 1, value);
}
#pragma scheduling on
extern int lbl_802F8EE0[];
extern char lbl_8032B300[];
#pragma scheduling invalid_target
int fn_80130FE0(int arg0) {
    int ordinalTable[10];
    int *entry;
    int tens;
    int ones;

    /* Return the ordinal string for a value in the 0-10 range (TENTH when tens == 1). */
    entry = &lbl_802F8EE0[0];
    ordinalTable[0] = *entry++;
    ordinalTable[1] = *entry++;
    ordinalTable[2] = *entry++;
    ordinalTable[3] = *entry++;
    ordinalTable[4] = *entry++;
    ordinalTable[5] = *entry++;
    ordinalTable[6] = *entry++;
    ordinalTable[7] = *entry++;
    ordinalTable[8] = *entry++;
    ordinalTable[9] = *entry++;
    tens = arg0 / 10;
    if (tens == 1) {
        fn_80131234(lbl_8032B300);
    } else {
        ones = arg0 % 10;
        fn_80131234((void *)ordinalTable[ones]);
    }
}
#pragma scheduling on
/* Format an ordinal ("21st", "3rd", ...) into buffer: "%d%s" of the number and
   the localized ordinal suffix fn_80130FE0 gives for it.  That function's
   strings carry the digit first ("21st"), so +1 skips down to the suffix. */
void fn_801310B4(char *buffer, int bufferSize, int number) {
#define ordinalFormat (&lbl_80559AF8)
    char *suffix = (char *)fn_80130FE0(number);
    fn_801345D8(buffer, bufferSize, ordinalFormat, number, suffix + 1);
#undef ordinalFormat
}

extern void *getResourceData(const char *, unsigned int, unsigned int *, int *, int, void **);
extern void fn_8012C4D8(void *);
extern void fn_8012BEF0(void *);
extern void fn_802E30C8(const char *, ...);
extern void fn_8012FAB8(void *);
extern void fn_80131308(void);
extern void *memcpy(void *, const void *, unsigned int);
extern char lbl_8032B028[];
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Load language resource for the specified language index (0 or 1). */
void fn_8013111C(int langIndex) {
    int size;
    unsigned int status;
    void *out;
    char *data;
    char *strings = lbl_8032B028;
    char *path;
    void *buffer;
    if (langIndex < 0)
        return;
    if ((unsigned int)langIndex >= 2)
        return;
    fn_8013028C();
    fn_80131308();
    fn_8012BEF0(*(void **)((char *)lbl_802F8E60 + langIndex * 0xC));
    path = strings + 0x2E8;
    size = 0;
    buffer = getResourceData(path, 0x4C414E47, &status, &size, 0, &out);
    if (buffer != 0) {
        data = (char *)&lbl_804230D0;
        memcpy(data + 8, buffer, size);
        fn_8012C4D8(buffer);
        if (status == 1) {
            fn_801301E0((unsigned char *)(data + 8));
        } else {
            fn_802E30C8(strings + 0x1C0, path);
        }
        *(char **)((char *)&lbl_804230D0 + 4) = (char *)&lbl_804230D0 + 8;
    } else {
        fn_802E30C8(strings + 0x1D4, path);
    }
    fn_8012FAB8(strings + 0x2F4);
    lbl_804230D0 = langIndex;
}
#pragma scheduling on
#pragma use_lmw_stmw on
/* Locale string lookup: return the localized message registered for `key` in
   the loaded message table, or the literal "???" (lbl_80559B00) if not found. */
void *fn_80131234(void *key) {
    int message = fn_801302E0(key);
    switch (message) {
    case 0:
        return lbl_80559B00;
    default:
        return (void *)message;
    }
}
#pragma scheduling on
/* Return the message id registered for a locale key (0 when the key is absent
 * from the loaded message table); callers use it to test key existence. */
int fn_80131264(void *key) {
    return fn_801302E0(key);
}

/* Tail-call wrapper: resolve a message key to its localized text via fn_80131234. */
void fn_80131268(void *key) {
    fn_80131234(key);
}

extern int lbl_8055E044;
void fn_80131308(void) {
    /* Advance the message-table generation stamp used to invalidate lazy cache entries. */
    #define s_msgTableStamp lbl_8055E044
    s_msgTableStamp += 1;
    #undef s_msgTableStamp
}

void fn_801312EC(int *msg, int key) {
    /* Start a lazy message-cache entry: remember the table key, clear the
     * resolved text, and mark it unresolved with ~the message-table stamp
     * (lbl_8055E044); fn_80131318 fills in the text and stamp on resolution. */
    msg[0] = key;
    msg[1] = 0;
    msg[2] = ~lbl_8055E044;
}

// Resolves a handle to its object; stores the resolved value and, on success, records the associated state.
void fn_80131318(int *arg0) {
    int temp_r3;
    temp_r3 = fn_801302E0((void *)arg0[0]);
    arg0[1] = temp_r3;
    if (temp_r3 == 0) {
        arg0[1] = arg0[0];
        return;
    }
    arg0[2] = lbl_8055E044;
}

__declspec(section ".data") extern int lbl_802FE850;
extern int atoi(const char *);
extern int strlen(const char *);
extern int fn_8002B1D8(const char *, const char *, int);
#pragma scheduling on
void fn_80131368(char *arg0)
{
  int flag = 0;
  int c;
  int signedC;
  int isNumber;
  int *p;
  unsigned int i;
  c = *((unsigned char *) arg0);
  signedC = (signed char) c;
  if (((signedC < 0) & 0xFFFFu) || (signedC >= 0x100))
  {
    flag = 1;
  }
  if (flag != 0)
  {
    isNumber = 0;
  }
  else
  {
    isNumber = (*((unsigned short *) ((*((int *) ((*((int *) (((char *) (&lbl_802FE850)) + 0x38))) + 8))) + (signedC * 2)))) & 8;
  }
  if (isNumber)
  {
    lbl_8055E04C = atoi(arg0);
    return;
  }
  p = lbl_802F8E60;
  i = 0;
  do
  {
    if (fn_8002B1D8(arg0, (const char *) p[0], strlen(arg0)) == 0)
    {
      lbl_8055E04C = i;
      return;
    }
    i++;
    p += 3;
  }
  while (i < 2);
}
extern int lbl_8055E044;
/* "LocaleUnXlator - really shouldn't use this in non-DEBUG mode" */
extern char lbl_8032B328[];
/* panic(): prints "PANIC: " + fmt (fn_802E3028), reports "PANIC" and exit(-1);
 * matched in src/game/abend.c as Abend_Panic. */
int Abend_Panic(const char *, ...);

/* LocaleUnXlator: copy the string src into dst and return dst, copying at most
 * 0x12C bytes -- when the limit runs out the last byte written is replaced by
 * the terminator.  The copy is dead code in this build: the function first
 * panics with "LocaleUnXlator - really shouldn't use this in non-DEBUG mode"
 * (Abend_Panic prints and exits), so reverse translation only exists in DEBUG. */
char *fn_8013126C(char *dst, const char *src) {
    const unsigned char *s = (const unsigned char *)src;
    int count;
    char *out;
    unsigned char c;

    Abend_Panic(lbl_8032B328);
    out = dst;
    count = 0x12c;
    goto copy;
count_check:
    if (--count > 0)
        goto copy;
    out[-1] = 0;
    goto done;
copy:
    c = *s++;
    *out++ = c;
    if ((signed char)c != 0)
        goto count_check;
done:
    return dst;
}
extern char lbl_80559B00[];
extern char lbl_8032B224[];
