// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

// Options files: fn_80133BA0 parses a text file ("default.opt", written back
// out as "options.dat") into the table lbl_8055E07C, which fn_80133024
// allocates here.  fn_80133E10 looks an option up by section + key and adds it
// when it is missing; fn_801332D0/fn_80133348/fn_8013323C/fn_80133460/
// fn_8013358C read and write the typed values it keeps.

// Fourcc the resource manager (fn_8012C370) looks an options file up by.
#define OPTIONS_TAG 0x424F5054  // 'BOPT'
#define OPTIONS_FILE_VERSION 2  // the "version 2" line a file starts with
#define OPTIONS_MAX_ENTRIES 500 // options the table holds (0x1F4)
#define OPTIONS_LINE_SIZE 0x100 // line buffer fn_80133BA0 reads into

// The "[SECTION]" an option was written under.  fn_80133B24 turns a section
// name into one of these (the 17 names are in lbl_802F9308) and answers
// OPTIONS_SECTION_NONE for a name it doesn't know; fn_80133BA0 takes
// OPTIONS_SECTION_NONE for its section argument to mean "every section".
typedef enum OptionSection {
    OPTIONS_SECTION_GLOBAL = 0,
    OPTIONS_SECTION_GX = 1,
    OPTIONS_SECTION_AI = 2,
    OPTIONS_SECTION_MULTI = 3,
    OPTIONS_SECTION_SOUND = 4,
    OPTIONS_SECTION_GAME = 5,
    OPTIONS_SECTION_PHYSICS = 6,
    OPTIONS_SECTION_TRKEDIT = 7,
    OPTIONS_SECTION_CONTROL = 8,
    OPTIONS_SECTION_CONTROL1 = 9,
    OPTIONS_SECTION_CONTROL2 = 10,
    OPTIONS_SECTION_CONTROL3 = 11,
    OPTIONS_SECTION_PLAYER0 = 12,
    OPTIONS_SECTION_PLAYER1 = 13,
    OPTIONS_SECTION_PLAYER2 = 14,
    OPTIONS_SECTION_PLAYER3 = 15,
    OPTIONS_SECTION_PLAYER_CAREER = 16,

    OPTIONS_SECTION_COUNT = 17, // names in lbl_802F9308
    OPTIONS_SECTION_NONE = 18   // unknown section / "any section"
} OptionSection;

// How an option's value was last written; the parser leaves 0 on the values it
// read straight out of the file.
typedef enum OptionValueType {
    OPTIONS_VALUE_FILE = 0,
    OPTIONS_VALUE_BOOL = 1,   // fn_80133460
    OPTIONS_VALUE_INT = 2,    // fn_80133348
    OPTIONS_VALUE_STRING = 3, // fn_8013358C
    OPTIONS_VALUE_FLOAT = 4   // fn_8013323C
} OptionValueType;

// One option: the value as written plus its int, float and true/false
// readings, so a reader can ask for whichever type it wants.
typedef struct OptionEntry {
    /* 0x00 */ int valueType;           // OptionValueType
    /* 0x04 */ int section;             // OptionSection it belongs to
    /* 0x08 */ unsigned char boolValue; // value read as true/false
    /* 0x0C */ int intValue;            // value read as a number
    /* 0x10 */ float floatValue;        // value read as a decimal
    /* 0x14 */ char text[0x10];         // value as written in the file
    /* 0x24 */ char name[0x14];         // key, as written
} OptionEntry;                          // 0x38 bytes

// The block lbl_8055E07C points at: a count and then the options themselves.
typedef struct OptionTable {
    /* 0x00 */ int unused_00; // nothing here reads it
    /* 0x04 */ int count;     // options in use
    /* 0x08 */ OptionEntry entries[OPTIONS_MAX_ENTRIES];
} OptionTable;

extern void *fn_8012C370(int, int, int *, int *, int, int);
extern void fn_8012C4D8(void *);
extern int fn_80133B24(char *);
extern char *strchr(const char *, int);
extern char *strcpy(char *, const char *);
extern int sscanf(const char *, const char *, ...);
extern char lbl_8032B868[];
extern int fn_802E30C8(const char *, ...);
extern int fn_801338D8(const char *);
extern float fn_80133960(const char *);
extern int fn_80133844(const char *);
extern unsigned long strlen(const char *);
extern const char lbl_8032B8F8[];
extern const char lbl_8032BA90[];

extern int lbl_8055E07C;
extern int lbl_80559B58;
extern int fn_80133BA0(int, int, int);
extern int fn_80133AD8(int);
extern int fn_802E317C(const char *, ...);
extern const char lbl_8032B8B0[];
extern int lbl_8042F718[];
extern const char lbl_8032B8D0[];
extern int fn_80128668(int);
extern int fn_80133E10(void **, int, int);
extern int fn_8013323C(int, int, float);
extern const char lbl_8032B920[];
int fn_80133010(void) { int val=lbl_8055E07C; unsigned int tmp=(unsigned int)(-val)|(unsigned int)val; return tmp>>31; }
extern const char lbl_8032B9FC[];

extern int lbl_8055E078, lbl_8055E080;
extern const char lbl_8032B880[], lbl_8032B88C[];
extern void* fn_801284F8(int, const char*);
extern void fn_80133FCC(long, long);
extern void fn_801341B4(int, int);
extern void fn_802E6BD8(int, int, int, int, void (*)(void));
extern void fn_8000DBC8(void (*)(int, int));
extern void *memmove(void *, const void *, unsigned int);
#pragma scheduling invalid_target
void fn_80133024(void) {
    /* Initialize the options table, load default options, and register save/load callbacks. */
    void *optionsTable;
    lbl_8055E078 = 1;
    optionsTable = fn_801284F8(0x6D68, lbl_8032B880);
    lbl_8055E07C = (int)optionsTable;
    *(int *)((char *)optionsTable + 4) = 0;
    lbl_8055E080 = 0;
    lbl_8042F718[1] = 0;
    lbl_8042F718[3] = 0;
    lbl_8042F718[5] = 0;
    lbl_8042F718[7] = 0;
    lbl_8042F718[9] = 0;
    lbl_8042F718[11] = 0;
    lbl_8042F718[13] = 0;
    lbl_8042F718[15] = 0;
    if (fn_80133BA0(lbl_80559B58, 0, 0x12) == 0)
        fn_802E317C(lbl_8032B88C, lbl_80559B58);
    fn_802E6BD8(0x4F505473, 6, lbl_8055E07C, 0x6D68, (void (*)(void))fn_80133FCC);
    fn_8000DBC8(fn_801341B4);
}
#pragma scheduling on
void fn_801330E8(int arg0) {
 if (!fn_80133BA0(lbl_80559B58,0,arg0)) {
   const char *fmt=lbl_8032B8B0;
   int result=fn_80133AD8(arg0);
   fn_802E317C(fmt,result);
 }
}

void fn_80133144(void) {
 int *entry=&lbl_8042F718[0];
 int i;
 for(i=0;i<8;i++){
  if(*(entry+1)!=0) fn_802E317C(lbl_8032B8D0, *entry);
  entry+=2;
 }
 fn_80128668(lbl_8055E07C);
 lbl_8055E07C=0;
}

void fn_801331C4(int arg0,int arg1,float *arg2) {
 void *sp8;
 int ok;
 ok=fn_80133E10(&sp8,arg0,arg1);
 if(ok) *arg2=*(float *)((char *)sp8+0x10);
 else fn_8013323C(arg0,arg1,*arg2);
}

__declspec(section ".sdata") extern const char lbl_80559B5C[];
#pragma push
#pragma processor 750
int fn_8013323C(int arg0, int arg1, float arg2) {
    extern float lbl_805612D0;
    extern int sprintf(char *, const char *, ...);
    void *sp8;
    int intValue;
    fn_80133E10(&sp8, arg0, arg1);
    intValue = (int)arg2;
    *(float *)((char *)sp8 + 0x10) = arg2;
    *(unsigned char *)((char *)sp8 + 8) = lbl_805612D0 != arg2;
    *(int *)((char *)sp8 + 0x0C) = intValue;
    sprintf((char *)sp8 + 0x14, lbl_80559B5C, arg2);
    *(int *)sp8 = 4;
}
#pragma pop
extern int fn_80133348(int, int, int);
extern int fn_80133460(int, int, unsigned char);
extern const char lbl_8032B940[];
extern const char lbl_8032B968[];
extern int sprintf(char *, const char *, ...);
extern const char lbl_80559B60[];
extern const char lbl_80559B5C[];
extern double lbl_805612D8;
extern float lbl_805612D0;
extern double lbl_805612E0;
extern const char lbl_80559B64[];
extern const char lbl_80559B68[];
int fn_80133348(int, int, int);
int fn_80133460(int, int, unsigned char);
int sprintf(char *, const char *, ...);
#pragma scheduling invalid_target
void fn_801332D0(int arg0, int arg1, int *arg2) {
    void *sp8;
    if (fn_80133E10(&sp8, arg0, arg1) != 0) {
        *arg2 = *(int *)((char *)sp8 + 0xC);
    } else {
        fn_80133348(arg0, arg1, *arg2);
    }
}
#pragma scheduling on
__declspec(section ".sdata") extern const char lbl_80559B60[];
int fn_80133348(int arg0, int arg1, int arg2) {
    char *sp8;
    char *p;
    fn_80133E10((void **)&sp8, arg0, arg1);
    *(int *)(sp8 + 0xC) = arg2;
    *(float *)(sp8 + 0x10) = (float)arg2;
    *(unsigned char *)(sp8 + 8) = arg2 != 0;
    sprintf(sp8 + 0x14, lbl_80559B60, arg2);
    p = sp8;
    *(int *)p = 2;
    return (int)p;
}

#pragma scheduling invalid_target
void fn_801333E8(int arg0, int arg1, unsigned char *arg2) {
    void *sp8;
    if (fn_80133E10(&sp8, arg0, arg1) != 0) {
        *arg2 = *(unsigned char *)((char *)sp8 + 8);
    } else {
        fn_80133460(arg0, arg1, *arg2);
    }
}
__declspec(section ".sdata") extern const char lbl_80559B64[];
__declspec(section ".sdata") extern const char lbl_80559B68[];
#pragma scheduling invalid_target
int fn_80133460(int arg0, int arg1, unsigned char arg2) {
    void *sp8;
    fn_80133E10(&sp8, arg0, arg1);
    *(unsigned char *)((char *)sp8 + 8) = arg2;
    *(int *)((char *)sp8 + 0xC) = arg2;
    *(float *)((char *)sp8 + 0x10) = (float)arg2;
    strcpy((char *)sp8 + 0x14, arg2 ? lbl_80559B64 : lbl_80559B68);
    *(int *)sp8 = 1;
}
#pragma scheduling on
void fn_801334F4(int arg0, int arg1, char *arg2, int arg3) {
    void *sp8;
    if (fn_80133E10(&sp8, arg0, arg1) != 0) {
        strncpy(arg2, (char *)sp8 + 0x14, arg3);
        arg2[arg3 - 1] = 0;
    } else {
        fn_8013358C(arg0, arg1, arg2);
    }
}

#pragma push
#pragma peephole on
/* Set an options entry (section, key) to a string value: copy up to 0x10 bytes
 * into the entry's text buffer (+0x14, null-terminated at +0x23), refresh its
 * int/float/bool readings, mark its type as OPTIONS_VALUE_STRING (3), and warn
 * via lbl_8032B8F8 if the input was truncated (longer than 15 chars). */
int fn_8013358C(int section, int key, char *valueStr) {
    void *entry;
    int savedSection = section;
    int savedKey = key;
    fn_80133E10(&entry, savedSection, savedKey);
    strncpy((char *)entry + 0x14, valueStr, 0x10);
    *((char *)entry + 0x23) = 0;
    *(int *)((char *)entry + 0xC) = fn_801338D8((char *)entry + 0x14);
    *(float *)((char *)entry + 0x10) = fn_80133960((char *)entry + 0x14);
    *((unsigned char *)entry + 8) = fn_80133844((char *)entry + 0x14);
    *(int *)entry = 3;
    if (strlen(valueStr) > 15) {
        fn_802E30C8(lbl_8032B8F8, valueStr, (char *)entry + 0x14);
    }
}

#pragma scheduling invalid_target
int fn_8013365C(int arg0, int arg1) {
    typedef struct { int a; int b; } Pair;
    Pair *p = (Pair *)lbl_8042F718;
    int i = 0;
    int count;
    for (count = 8; count != 0; count--) {
        if (p->b == 0) {
            Pair *q = &((Pair *)lbl_8042F718)[i];
            q->b = arg1;
            q->a = arg0;
            return i;
        }
        p++;
        i++;
    }
    fn_802E317C(lbl_8032B920, arg0);
    return -1;
}

#pragma scheduling invalid_target
void fn_801336E0(int arg0, int arg1) {
    int offset = arg0 << 3;
    int *entry = &lbl_8042F718[arg0 + arg0];
    if (entry[1] == 0) {
        fn_802E317C(lbl_8032B940, arg0);
    }
    if ((unsigned)entry[1] != (unsigned)arg1) {
        fn_802E317C(lbl_8032B968, *(int *)((char *)lbl_8042F718 + offset), entry[1], arg1);
    }
    entry[1] = 0;
}
#pragma scheduling on
int fn_80133780(void *arg0, void *arg1) {
    int result = *(int *)((char *)arg0 + 4) - *(int *)((char *)arg1 + 4);
    switch (result) {
    case 0:
        result = fn_8002B1D8((char *)arg0 + 0x24, (char *)arg1 + 0x24, 0x13);
        break;
    default:
        break;
    }
    return result;
}
#pragma optimize_for_size off
extern void qsort(void *, int, int, int (*)(void *, void *));
int fn_80133780(void *, void *);
#pragma scheduling invalid_target
void fn_801337C8(void) {
    void *base = (void *)lbl_8055E07C;
    qsort((char *)base + 8, *(int *)((char *)base + 4), 0x38, fn_80133780);
}
#pragma scheduling on
__declspec(section ".data") extern int lbl_802FE850;
static inline int is_line_space(int c) {
    int table = *(int *)((char *)&lbl_802FE850 + 0x38);
    return (c < 0 || c >= 256) ? 0 :
        (*(unsigned short *)(*(int *)(table + 8) + c * 2) & 0x100);
}
extern int lbl_802F9308[];
extern int fn_802E30C8(const char *, ...);
extern double atof(const char *);
extern int fn_8002B1D8(void *, void *, int);
extern int atoi(const char *);
extern int stricmp(const char *, const char *);
#pragma peephole off
#pragma dont_inline on
char *fn_801337E4(char *arg0) {
    char *p = arg0;
    unsigned char byte;
    int c;
    int table = *(int *)((char *)&lbl_802FE850 + 0x38);
    do {
        p = (char *)((unsigned int)p + 1);
        byte = *(volatile unsigned char *)p;
        c = (signed char)byte;
        if (c == 0) return p;
        if ((c < 0 || c >= 0x100) ? 0 : (*(unsigned short *)(*(int *)(table + 8) + c * 2) & 0x100)) continue;
        return p;
    } while (1);
}
#pragma dont_inline off
#pragma dont_inline on
int fn_80133844(const char *arg0) {
    char *p = fn_801337E4((char *)arg0);
    int invalid = 0;
    int c = (signed char)*p;
    int table;
    int isnum;
    if (c < 0)
        goto set_invalid;
    if (c < 0x100)
        goto check_invalid;
set_invalid:
    invalid = 1;
check_invalid:
    if (invalid != 0)
        isnum = 0;
    else {
        table = *(int *)((char *)&lbl_802FE850 + 0x38);
        isnum = (*(unsigned short *)(*(int *)(table + 8) + (c * 2)) & 8);
    }
    if (isnum != 0)
        return atoi(p) != 0;
    return stricmp(p, lbl_80559B64) == 0;
}
#pragma dont_inline off

int fn_801338D8(const char *arg0) {
    char *p = fn_801337E4((char *)arg0);
    unsigned char b = *p;
    int isnum = 0;
    int c = (signed char)b;
    int table;
    if (c < 0)
        isnum = 0;
    else if (c < 0x100) {
        table = *(int *)(lbl_802FE850 + 0x38);
        isnum = (*(unsigned short *)(*(int *)(table + 8) + c * 2) & 8) != 0;
    } else
        isnum = 1;
    if (isnum != 0)
        return atoi(p);
    if (c != '-')
        return fn_80133844(p);
    return atoi(p);
}

extern int fn_802E30C8(const char *, ...);
extern double atof(const char *);
#pragma scheduling invalid_target
#pragma dont_inline on
float fn_80133960(const char *arg0) {
    char *p = fn_801337E4((char *)arg0);
    unsigned char c = *p;
    register int ch = (signed char)c;
    int invalid = 0;

    if (ch < 0)
        goto set_invalid;
    if (ch < 0x100)
        goto check_invalid;
set_invalid:
    invalid = 1;
check_invalid:
    if (invalid != 0) {
        ch = 0;
        goto test_char;
    }
    {
        int table = *(int *)((char *)&lbl_802FE850 + 0x38);
        ch = *(unsigned short *)(*(int *)(table + 8) + ch * 2) & 8;
    }
test_char:
    if (ch || (unsigned char)(c - 0x2d) <= 1)
        return (float)atof(p);
    return (float)(unsigned int)fn_80133844(p);
}
#pragma dont_inline reset
#pragma scheduling on
int fn_80133A08(char **arg0, int arg1, char *arg2, int arg3) {
    char *p = *arg0;
    char *start = arg2;
    char *end = p + arg1;
    char *limit = arg2 + arg3 - 1;
    int table = *(int *)((char *)&lbl_802FE850 + 0x38);
    while (p < end && (((signed char)*p < 0 || (signed char)*p >= 256) ? 0 : (*(unsigned short *)(*(int *)(table + 8) + (signed char)*p * 2) & 0x100)))
        p++;
    while (p < end && arg2 < limit && (signed char)*p != 13 && (signed char)*p != 10)
        *arg2++ = *p++;
    *arg2 = 0;
    *arg0 = p;
    return arg2 != start;
}
#pragma pop
extern void *memcpy(void *, const void *, unsigned long);
#pragma push
#pragma optimize_for_size on
int fn_80133AD8(int arg0) {
    int values[17];
    int *src;
    int *dst;
    int i;

    dst = values - 1;
    src = lbl_802F9308 - 1;
    for (i = 8; i > 0; --i) {
        dst[1] = src[1];
        dst[2] = src[2];
        src += 2;
        dst += 2;
    }
    dst[1] = src[1];
    return values[arg0];
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
int fn_80133B24(char *arg0) {
    int i = 0;

    do {
        if (stricmp(arg0, (char *)fn_80133AD8(i)) == 0) {
            return i;
        }
        i++;
    } while (i < 0x11);
    fn_802E30C8(lbl_8032B9FC, arg0);
    return 0x12;
}
#pragma dont_inline reset
#pragma scheduling on
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw off
/*
 * fn_80133BA0 - read an options file into the option table.
 *
 * Asks the resource manager for the "BOPT" file called `path` and reads it
 * line by line.  "[SECTION]" lines pick the section (fn_80133B24 knows the 17
 * names), ';' '#' and empty lines are skipped, and any other line inside the
 * file is "key value": the text after the first space is stored under that
 * section and key, together with its int, float and true/false readings
 * (fn_80133E10 finds the option and adds it when it isn't there yet).  The
 * file has to start with "version 2" unless ignoreVersion is set, and only
 * options of wantSection are stored - OPTIONS_SECTION_NONE takes them all.
 * Returns 0 when the file can't be read or has the wrong version.
 */
int fn_80133BA0(int path, int ignoreVersion, int wantSection) {
    int size;
    int loadStatus;
    int fileVersion;
    char *pos;
    void *entry;
    union { char c[OPTIONS_LINE_SIZE]; double align; } bufu;
    char *strings = lbl_8032B868;
    void *data;
    int ok;
    int section;
    int inSection;
    char *sep;
    int newSection;
    int c;
#define buf bufu.c

    size = 0;
    data = fn_8012C370(path, OPTIONS_TAG, &loadStatus, &size, 0, 0);
    ok = 0;
    if (data != 0) {
        pos = (char *)data;
        inSection = 0;
        ok = 1;
        section = 0;
        while (ok != 0 &&
               fn_80133A08(&pos, size - (pos - (char *)data), buf,
                           OPTIONS_LINE_SIZE) != 0) {
            c = (signed char)buf[0];
            if (c == '[') {  // "[SECTION]" header
                sep = strchr(buf, ']');
                newSection = OPTIONS_SECTION_NONE;
                if (sep != 0) {
                    *sep = 0;
                    newSection = fn_80133B24(buf + 1);
                }
                if (newSection != OPTIONS_SECTION_NONE) {
                    section = newSection;
                } else {
                    // "opt: bad section on line %d"
                    fn_802E30C8(strings + 0x1B0, pos);
                }
            } else if (c == ';' || c == 0 || c == '#') {  // comment or blank
            } else {
                if (inSection != 0) {
                    if (((OptionTable *)lbl_8055E07C)->count <
                        OPTIONS_MAX_ENTRIES) {
                        sep = strchr(buf, ' ');
                        if (sep != 0 && (signed char)*sep != 0) {
                            *sep = 0;  // "key value": cut the key off
                            if (wantSection == OPTIONS_SECTION_NONE ||
                                wantSection == section) {
                                fn_80133E10(&entry, section, (int)buf);
                                strcpy(((OptionEntry *)entry)->text, sep + 1);
                                ((OptionEntry *)entry)->intValue =
                                    fn_801338D8(((OptionEntry *)entry)->text);
                                ((OptionEntry *)entry)->floatValue =
                                    fn_80133960(((OptionEntry *)entry)->text);
                                ((OptionEntry *)entry)->boolValue =
                                    fn_80133844(((OptionEntry *)entry)->text);
                                ((OptionEntry *)entry)->valueType =
                                    OPTIONS_VALUE_FILE;
                            }
                        } else {
                            // "Item %s:%s has no value"
                            fn_802E30C8(strings + 0x1D0,
                                        fn_80133AD8(section), buf);
                        }
                    }
                } else if ((sscanf(buf, strings + 0x1E8, &fileVersion) == 1 &&
                            fileVersion == OPTIONS_FILE_VERSION) ||
                           ignoreVersion != 0) {
                    inSection = 1;  // "version 2" (or told not to care)
                } else {
                    fn_802E30C8(strings + 0x1F4, path);  // "Wrong version"
                    ok = 0;
                }
            }
        }
        fn_8012C4D8(data);
    } else {
        // "Couldn't open options file: %s"
        fn_802E30C8(strings + 0x208, path);
    }
    return ok;
}
int fn_80133E10(void **arg0, int arg1, int arg2) {
    register int count;
    register int offset;
    register int *table;
    register char *entry;
    register char *slot;
    register int old_count;

    offset = 0;
    count = 0;
    goto check;

loop:
    entry = (char *)table + count;
    if (arg1 == *(int *)(entry + 0xC) &&
        fn_8002B1D8((void *)arg2, entry + 0x2C, 0x13) == 0) {
        *arg0 = (void *)((char *)lbl_8055E07C + offset * 0x38 + 8);
        return 1;
    }
    count += 0x38;
    offset++;

check:
    table = (int *)lbl_8055E07C;
    if (offset < table[1])
        goto loop;

    old_count = table[1];
    if (old_count < 0x1F4) {
        entry = (char *)table + old_count * 0x38;
        table[1] = old_count + 1;
        slot = entry + 8;
        *(int *)(entry + 0xC) = arg1;
        strncpy(slot + 0x24, (char *)arg2, 0x14);
        slot[0x37] = 0;
        if (strlen((char *)arg2) >= 0x14)
            fn_802E30C8(lbl_8032BA90, (char *)arg2, slot + 0x24);
        {
            register int zero = 0;
            register float initial = lbl_805612D0;
            slot[0x14] = zero;
            slot[8] = zero;
            *(int *)(slot + 0xC) = zero;
            *(float *)(slot + 0x10) = initial;
        }
        *arg0 = slot;
    } else {
        *arg0 = (char *)table + 8;
    }
    return 0;
}

#pragma dont_inline on
int fn_80133F3C(int arg0) {
    int i = 0;
    int *p;
    int offset;
    goto check;
loop:
    offset = i * 0x38;
    if (arg0 == *(int *)((char *)p + offset + 0xC)) {
        p[1] = p[1] - 1;
        p = (int *)lbl_8055E07C;
        memmove((char *)p + offset + 8,
                (char *)p + offset + 0x40,
                (unsigned int)((p[1] - i) * 0x38));
        i--;
    }
    i++;
check:
    p = (int *)lbl_8055E07C;
    if (i < p[1]) goto loop;
}
#pragma dont_inline reset

extern char lbl_8042F558[], lbl_8032BAC8[];
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_80133FCC(long arg0, long arg_sp0) {
    char *dst;
    char *src;
    long off;
    long i, j;
    long w2, w3, w4, w5, w6, w7;
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7;
    unsigned char b8, b9, b10, b11, b12, b13, b14, b15;
    void (*callback)(void);
    if (arg0 == 1) {
        src = lbl_8042F558;
        for (i = 0; i < lbl_8055E080; src += 0x38, i++) {
            for (j = 0, off = 0; j < *(long *)((char *)lbl_8055E07C + 4); off += 0x38, j++) {
                dst = (char *)lbl_8055E07C + off;
                if (*(long *)(src + 4) == *(long *)(dst + 0xC) &&
                    stricmp(src + 0x24, dst + 0x2C) == 0) {
                    *(long *)(dst + 0x08) = *(long *)(src + 0x00);
                    *(long *)(dst + 0x0C) = *(long *)(src + 0x04);
                    w2 = *(long *)(src + 0x08); w3 = *(long *)(src + 0x0C);
                    *(long *)(dst + 0x14) = w3; *(long *)(dst + 0x10) = w2;
                    w4 = *(long *)(src + 0x10); w5 = *(long *)(src + 0x14);
                    *(long *)(dst + 0x1C) = w5; *(long *)(dst + 0x18) = w4;
                    w6 = *(long *)(src + 0x18); w7 = *(long *)(src + 0x1C);
                    *(long *)(dst + 0x24) = w7; *(long *)(dst + 0x20) = w6;
                    *(long *)(dst + 0x28) = *(long *)(src + 0x20);
                    b0 = src[0x24]; b1 = src[0x25]; dst[0x2D] = b1; dst[0x2C] = b0;
                    b2 = src[0x26]; b3 = src[0x27]; dst[0x2F] = b3; dst[0x2E] = b2;
                    b4 = src[0x28]; b5 = src[0x29]; dst[0x31] = b5; dst[0x30] = b4;
                    b6 = src[0x2A]; b7 = src[0x2B]; dst[0x33] = b7; dst[0x32] = b6;
                    b8 = src[0x2C]; b9 = src[0x2D]; dst[0x35] = b9; dst[0x34] = b8;
                    b10 = src[0x2E]; b11 = src[0x2F]; dst[0x37] = b11; dst[0x36] = b10;
                    b12 = src[0x30]; b13 = src[0x31]; dst[0x39] = b13; dst[0x38] = b12;
                    b14 = src[0x32]; b15 = src[0x33]; dst[0x3B] = b15; dst[0x3A] = b14;
                    dst[0x3C] = src[0x34]; dst[0x3D] = src[0x35];
                    dst[0x3E] = src[0x36]; dst[0x3F] = src[0x37];
                }
            }
        }
        src = (char *)lbl_8042F718;
        for (i = 0; i < 8; i++, src += 8) {
            callback = *(void (**)(void))(src + 4);
            if (callback) callback();
        }
    } else if (arg0 == 2) {
        fn_802E30C8(lbl_8032BAC8);
    }
    if (arg0 == 3) fn_801337C8();
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma scheduling on
extern const char lbl_8032BAE8[];
extern const char lbl_8032B940[];
extern const char lbl_8032B968[];
extern const char lbl_8032B920[];
extern int fn_80133F3C(int);
extern void *memmove(void *, const void *, unsigned int);
void fn_801341B4(int arg0, int arg1) {
    switch (arg1) {
    case 0:
        fn_802E30C8(lbl_8032BAE8, arg0);
        fn_80133F3C(arg0 + 0xC);
        break;
    default:
        break;
    }
}

extern int lbl_8055E07C;
extern int lbl_80559B58;
extern int fn_80133BA0(int, int, int);
extern int fn_80133AD8(int);
extern int fn_802E317C(const char *, ...);
extern const char lbl_8032B8B0[];
extern int lbl_8042F718[];
extern const char lbl_8032B8D0[];
extern int fn_80128668(int);
extern int fn_80133E10(void **, int, int);
extern int fn_8013323C(int, int, float);
