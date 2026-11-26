// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

// Options files: readOptionsFile parses a text file ("default.opt", written back
// out as "options.dat") into the table lbl_8055E07C, which fn_80133024
// allocates here.  fn_80133E10 looks an option up by section + key and adds it
// when it is missing; LoadIntOptionValue/fn_80133348/fn_8013323C/fn_80133460/
// fn_8013358C read and write the typed values it keeps.

// Fourcc the resource manager (fn_8012C370) looks an options file up by.
#define OPTIONS_TAG 0x424F5054  // 'BOPT'
#define OPTIONS_FILE_VERSION 2  // the "version 2" line a file starts with
#define OPTIONS_MAX_ENTRIES 500 // options the table holds (0x1F4)
#define OPTIONS_LINE_SIZE 0x100 // line buffer readOptionsFile reads into

// The "[SECTION]" an option was written under.  fn_80133B24 turns a section
// name into one of these (the 17 names are in lbl_802F9308) and answers
// OPTIONS_SECTION_NONE for a name it doesn't know; readOptionsFile takes
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

// Why the save system (src/game/memcard.c) calls a save record's call-back
// around the memcpy of the record's bytes; the options record ('OPTS') uses
// fn_80133FCC as its call-back.
typedef enum SaveRecordStage {
    SAVE_RECORD_BEFORE_LOAD = 0, // the record's bytes are about to be replaced
    SAVE_RECORD_AFTER_LOAD = 1,  // they have just been copied over it
    SAVE_RECORD_LOAD_FAILED = 2, // no usable save data was found
    SAVE_RECORD_BEFORE_SAVE = 3, // the record is about to be written out
    SAVE_RECORD_AFTER_SAVE = 4   // it has been written out
} SaveRecordStage;

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

// What the save/load call-back fn_80133FCC keeps beside the table:
//   lbl_8042F558 - up to 8 OptionEntry values held back from the save file and
//                  copied back over the table after the card's data is loaded
//   lbl_8055E080 - how many of those entries there are (fn_80133024 zeroes it)
//   lbl_8042F718 - 8 {name, call-back} slots (fn_8013365C adds one,
//                  fn_801336E0 clears one, fn_80133144 complains about the ones
//                  still set at shutdown); each call-back is run after the
//                  options have been reloaded so its module reads them again

extern void *fn_8012C370(int, int, int *, int *, int, int);
extern void fn_8012C4D8(void *);
extern int fn_80133B24(char *);
extern char *strchr(const char *, int);
extern char *strcpy(char *, const char *);
extern int sscanf(const char *, const char *, ...);
extern char lbl_8032B868[];
extern int fn_802E30C8(const char *, ...);
extern int fn_801338D8(const char *);
extern float optionStringToFloat(const char *);
extern int fn_80133844(const char *);
extern unsigned long strlen(const char *);
extern const char lbl_8032B8F8[];
extern const char lbl_8032BA90[];

extern int lbl_8055E07C;
extern int lbl_80559B58;
extern int readOptionsFile(int, int, int);
extern int fn_80133AD8(int);
extern int Abend_Panic(const char *, ...);
extern const char lbl_8032B8B0[];
extern int lbl_8042F718[];
extern const char lbl_8032B8D0[];
extern int fn_80128668(int);
extern int fn_80133E10(void **, int, int);
extern int fn_8013323C(int, int, float);
extern const char lbl_8032B920[];
int fn_80133010(void) {
    /* Return nonzero once the options table (lbl_8055E07C) has been allocated. */
    int tablePtr = lbl_8055E07C;
    unsigned int nonzeroBits = (unsigned int)(-tablePtr) | (unsigned int)tablePtr;
    return nonzeroBits >> 31;
}
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
    if (readOptionsFile(lbl_80559B58, 0, 0x12) == 0)
        Abend_Panic(lbl_8032B88C, lbl_80559B58);
    fn_802E6BD8(0x4F505473, 6, lbl_8055E07C, 0x6D68, (void (*)(void))fn_80133FCC);
    fn_8000DBC8(fn_801341B4);
}
#pragma scheduling on
/* Load default options for a section, or report failure with the section name. */
void fn_801330E8(int section) {
    if (!readOptionsFile(lbl_80559B58, 0, section)) {
        const char *fmt = lbl_8032B8B0;
        int sectionName = fn_80133AD8(section);
        Abend_Panic(fmt, sectionName);
    }
}

void fn_80133144(void) {
    /* Shut down the options table: warn about any of the 8 reload-callback
     * slots in lbl_8042F718 ({name, callback}) that were never removed
     * ("opt: callback %s (%x) was never removed", lbl_8032B8D0), then free and
     * clear the OptionTable at lbl_8055E07C. */
    int *callbackSlot = &lbl_8042F718[0];
    int slotIndex;
    for (slotIndex = 0; slotIndex < 8; slotIndex++) {
        if (callbackSlot[1] != 0)
            Abend_Panic(lbl_8032B8D0, callbackSlot[0], callbackSlot[1]);
        callbackSlot += 2;
    }
    fn_80128668(lbl_8055E07C);
    lbl_8055E07C = 0;
}

/* Get a float option value by section/key; on miss, write the provided default via fn_8013323C. */
void LoadFloatOption(int arg0,int arg1,float *arg2) {
 void *sp8;
 int ok;
 ok=fn_80133E10(&sp8,arg0,arg1);
 if(ok) *arg2=*(float *)((char *)sp8+0x10);
 else fn_8013323C(arg0,arg1,*arg2);
}

__declspec(section ".sdata") extern const char lbl_80559B5C[];
#pragma push
#pragma processor 750
int fn_8013323C(int section, int key, float value) {
    extern float lbl_805612D0;
    extern int sprintf(char *, const char *, ...);
    char *entryData;
    char *result;
    int intValue;
    fn_80133E10((void **)&entryData, section, key);
    intValue = (int)value;
    *(float *)(entryData + 0x10) = value;
    *(unsigned char *)(entryData + 8) = lbl_805612D0 != value;
    *(int *)(entryData + 0xC) = intValue;
    sprintf(entryData + 0x14, lbl_80559B5C, value);
    result = entryData;
    *(int *)result = 4;
    return (int)result;
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
/* Reads an option (section, key) as an integer: fn_80133E10 looks the option up
 * and adds it when it is missing, so an option that is not in the table yet
 * takes the caller's *value as its default (through fn_80133348, which also
 * writes its bool/float/text readings) instead of reading back 0. */
void LoadIntOptionValue(int section, int key, int *value) {
    OptionEntry *entry;
    if (fn_80133E10((void **)&entry, section, key) != 0) {
        *value = entry->intValue;
    } else {
        fn_80133348(section, key, *value);
    }
}
#pragma scheduling on
__declspec(section ".sdata") extern const char lbl_80559B60[];
/* Set an option's value as an integer, updating its cached typed fields and text form. */
int fn_80133348(int section, int key, int value) {
    char *entryData;
    char *result;
    fn_80133E10((void **)&entryData, section, key);
    *(int *)(entryData + 0xC) = value;
    *(float *)(entryData + 0x10) = (float)value;
    *(unsigned char *)(entryData + 8) = value != 0;
    sprintf(entryData + 0x14, lbl_80559B60, value);
    result = entryData;
    *(int *)result = 2;
    return (int)result;
}

#pragma scheduling invalid_target
/* Reads an option (section, key) as a true/false value: fn_80133E10 looks the
 * option up and adds it when it is missing, so an option that is not in the
 * table yet takes the caller's *value as its default (through fn_80133460,
 * which also writes its int/float/text readings) instead of reading back 0. */
void fn_801333E8(int section, int key, unsigned char *value) {
    OptionEntry *entry;
    if (fn_80133E10((void **)&entry, section, key) != 0) {
        *value = entry->boolValue;
    } else {
        fn_80133460(section, key, *value);
    }
}

__declspec(section ".sdata") extern const char lbl_80559B64[];
__declspec(section ".sdata") extern const char lbl_80559B68[];
#pragma scheduling invalid_target
int fn_80133460(int section, int key, unsigned char value) {
    char *entryData;
    char *result;
    /* Store a boolean setting in its (section,key) record: type 1, numeric/float value and a "yes"/"no" string. */
    fn_80133E10((void **)&entryData, section, key);
    *(unsigned char *)(entryData + 8) = value;
    *(int *)(entryData + 0xC) = value;
    *(float *)(entryData + 0x10) = (float)value;
    strcpy(entryData + 0x14, value ? lbl_80559B64 : lbl_80559B68);
    result = entryData;
    *(int *)result = 1;
    return (int)result;
}
#pragma scheduling on
/* Copy a value's string (offset 0x14) for (groupId, valueId) into outBuf, or initialize it via fn_8013358C. */
void fn_801334F4(int groupId, int valueId, char *outBuf, int outSize) {
    void *sp8;
    if (fn_80133E10(&sp8, groupId, valueId) != 0) {
        strncpy(outBuf, (char *)sp8 + 0x14, outSize);
        outBuf[outSize - 1] = 0;
    } else {
        fn_8013358C(groupId, valueId, outBuf);
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
    *(float *)((char *)entry + 0x10) = optionStringToFloat((char *)entry + 0x14);
    *((unsigned char *)entry + 8) = fn_80133844((char *)entry + 0x14);
    *(int *)entry = 3;
    if (strlen(valueStr) > 15) {
        fn_802E30C8(lbl_8032B8F8, valueStr, (char *)entry + 0x14);
    }
}

#pragma scheduling invalid_target
/* Register a named callback in the first free slot of the 8-entry callback table, or log an error and return -1 if full. */
int fn_8013365C(int name, int callback) {
    typedef struct { int a; int b; } Pair;
    int *slot = lbl_8042F718;
    int index = 0;
    int remaining;
    for (remaining = 8; remaining != 0; remaining--) {
        if (slot[1] == 0) {
            ((Pair *)lbl_8042F718)[index].b = callback;
            ((Pair *)lbl_8042F718)[index].a = name;
            return index;
        }
        slot += 2;
        index++;
    }
    Abend_Panic(lbl_8032B920, name);
    return -1;
}

#pragma scheduling invalid_target
void fn_801336E0(int arg0, int arg1) {
    int offset = arg0 * 8;
    int *entry = &lbl_8042F718[arg0 * 2];
    if (entry[1] == 0) {
        Abend_Panic(lbl_8032B940, arg0);
    }
    if ((unsigned)entry[1] != (unsigned)arg1) {
        Abend_Panic(lbl_8032B968, *(int *)((char *)lbl_8042F718 + offset), entry[1], arg1);
    }
    entry[1] = 0;
}
#pragma push
#pragma processor 750
#pragma scheduling on
int fn_80133780(void *arg0, void *arg1) {
    int b = *(int *)((char *)arg1 + 4);
    int a = *(int *)((char *)arg0 + 4);
    int result = a - b;
    switch (result) {
    case 0:
        result = fn_8002B1D8((char *)arg0 + 0x24, (char *)arg1 + 0x24, 0x13);
        break;
    default:
        break;
    }
    return result;
}
#pragma pop
extern void qsort(void *, int, int, int (*)(void *, void *));
int fn_80133780(void *, void *);
#pragma scheduling invalid_target
void fn_801337C8(void) {
    /* Sort the options table's entries in place by section, then by key. */
    OptionTable *table = (OptionTable *)lbl_8055E07C;
    qsort(table->entries, table->count, sizeof(OptionEntry), fn_80133780);
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
#pragma peephole on
char *fn_801337E4(char *str) {
    /* Skip leading whitespace: advance past each character that the active
     * locale's ctype map flags as space (mask 0x100), stopping at NUL or the
     * first non-space character, and return that position. */
    char *p = str;
    unsigned char byte;
    int c;
    int ctypeTable = *(int *)((char *)&lbl_802FE850 + 0x38);
    while ((byte = *p, c = (signed char)byte) && ((c < 0 || c >= 0x100) ? 0 : (*(unsigned short *)(*(int *)(ctypeTable + 8) + c * 2) & 0x100)))
        p++;
    return p;
}
#pragma dont_inline on
int fn_80133844(const char *arg0) {
    /* Return nonzero if the whitespace-trimmed string is a nonzero integer or "yes". */
    char *text = fn_801337E4((char *)arg0);
    int invalid = 0;
    int c = (signed char)*text;
    int ctypeTable;
    int isDigit;

    if (c < 0)
        goto set_invalid;
    if (c < 0x100)
        goto check_invalid;
set_invalid:
    invalid = 1;
check_invalid:
    if (invalid != 0)
        isDigit = 0;
    else {
        ctypeTable = *(int *)((char *)&lbl_802FE850 + 0x38);
        isDigit = (*(unsigned short *)(*(int *)(ctypeTable + 8) + (c * 2)) & 8);
    }
    if (isDigit != 0)
        return atoi(text) != 0;
    return stricmp(text, lbl_80559B64) == 0;
}
#pragma dont_inline reset

#pragma dont_inline on
int fn_801338D8(const char *arg0) {
    char *p = fn_801337E4((char *)arg0);
    unsigned char b = *p;
    int isnum = 0;
    int isDigit;
    int c = (signed char)b;
    int ctypeTable;

    if (c < 0) goto set_invalid;
    if (c < 0x100) goto check_invalid;
set_invalid:
    isnum = 1;
check_invalid:
    if (isnum != 0)
        isDigit = 0;
    else {
        ctypeTable = *(int *)((char *)&lbl_802FE850 + 0x38);
        isDigit = *(unsigned short *)(*(int *)(ctypeTable + 8) + c * 2) & 8;
    }
    if (isDigit == 0) {
        if ((signed char)b == '-')
            return atoi(p);
        return fn_80133844(p);
    }
    return atoi(p);
}

extern int fn_802E30C8(const char *, ...);
extern double atof(const char *);
#pragma scheduling invalid_target
#pragma dont_inline on
float optionStringToFloat(const char *arg0) {
    char *p = fn_801337E4((char *)arg0);
    unsigned char c = *p;
    int value = 0;
    int ch = (signed char)c;

    if (ch < 0)
        goto set_invalid;
    if (ch < 0x100)
        goto check_invalid;
set_invalid:
    value = 1;
check_invalid:
    switch (value) {
    case 0:
        goto lookup;
    default:
        value = 0;
        goto test_char;
    }
lookup:
    {
        int table = *(int *)((char *)&lbl_802FE850 + 0x38);
        value = *(unsigned short *)(*(int *)(table + 8) + ch * 2) & 8;
    }
test_char:
    if (value || (unsigned char)(c - 0x2d) <= 1)
        return (float)atof(p);
    return (float)(unsigned int)fn_80133844(p);
}
#pragma opt_propagation off
/* Read one line from the text at *srcPtr into dst for readOptionsFile's BOPT parser: skip leading whitespace (ctype table bit 0x100), copy up to dstCapacity-1 bytes until CR/LF, NUL-terminate, advance the source cursor, and return whether any bytes were copied. */
int fn_80133A08(char **srcPtr, int srcRemaining, char *dst, int dstCapacity) {
    char *src;
    int ch, outOfRange, isSpace;
    int ctypeTable;
    char *dstStart;
    char *srcEnd;
    char *dstLimit;
    src = *srcPtr;
    dstLimit = dst + dstCapacity - 1;
    ctypeTable = *(int *)((char *)&lbl_802FE850 + 0x38);
    dstStart = dst;
    srcEnd = src + srcRemaining;
    while (src < srcEnd && ((ch = (signed char)*src, outOfRange = (ch < 0 || ch >= 256), isSpace = outOfRange ? 0 : (*(unsigned short *)(*(int *)(ctypeTable + 8) + ch * 2) & 0x100), isSpace)))
        src++;
    while (src < srcEnd && dst < dstLimit && (signed char)*src != 13 && (signed char)*src != 10)
        *dst++ = *src++;
    *dst = 0;
    *srcPtr = src;
    return dst != dstStart;
}
#pragma opt_propagation reset
extern void *memcpy(void *, const void *, unsigned long);
#pragma push
#pragma optimize_for_size on
int fn_80133AD8(int sectionIndex) {
    /* Returns the section name string at sectionIndex from the 17-entry options
       name table lbl_802F9308, copied to a local buffer before indexing. */
    int sectionNames[17];
    int *src;
    int *dst;
    int i;

    dst = sectionNames - 1;
    src = lbl_802F9308 - 1;
    for (i = 8; i > 0; --i) {
        dst[1] = src[1];
        dst[2] = src[2];
        src += 2;
        dst += 2;
    }
    dst[1] = src[1];
    return sectionNames[sectionIndex];
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
/* Looks up an options section name (case-insensitively) among the 17 known section names (0..16),
 * or logs "Can't get section for %s" (lbl_8032B9FC) and returns 0x12 if not found. */
int fn_80133B24(char *sectionName) {
    int sectionIndex = 0;

    do {
        if (stricmp(sectionName, (char *)fn_80133AD8(sectionIndex)) == 0) {
            return sectionIndex;
        }
        sectionIndex++;
    } while (sectionIndex < 0x11);
    fn_802E30C8(lbl_8032B9FC, sectionName);
    return 0x12;
}
#pragma dont_inline reset
#pragma scheduling on
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw off
/*
 * readOptionsFile - read an options file into the option table.
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
int readOptionsFile(int path, int ignoreVersion, int wantSection) {
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
                                    optionStringToFloat(((OptionEntry *)entry)->text);
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
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
int fn_80133E10(void **outEntry, int section, int key) {
    /* Options_FindOrAdd: find the option with this section and key in the options
     * table (lbl_8055E07C). Returns 1 with its OptionEntry in *outEntry, or appends
     * a new zero-initialized entry and returns 0 when it is missing. */
    register int entryOffset;
    register int entryIndex;
    register int *options;
    register char *candidate;
    register char *newEntry;
    register int usedCount;

    entryIndex = 0;
    entryOffset = 0;
    goto check;

loop:
    candidate = (char *)options + entryOffset;
    if (section == *(int *)(candidate + 0xC) &&
        fn_8002B1D8((void *)key, candidate + 0x2C, 0x13) == 0) {
        *outEntry = (void *)((char *)lbl_8055E07C + entryIndex * 0x38 + 8);
        return 1;
    }
    entryOffset += 0x38;
    entryIndex++;

check:
    options = (int *)lbl_8055E07C;
    if (entryIndex < options[1])
        goto loop;

    usedCount = options[1];
    if (usedCount < 0x1F4) {
        candidate = (char *)options + usedCount * 0x38;
        options[1] = usedCount + 1;
        newEntry = candidate + 8;
        *(int *)(candidate + 0xC) = section;
        strncpy(newEntry + 0x24, (char *)key, 0x14);
        newEntry[0x37] = 0;
        if (strlen((char *)key) >= 0x14)
            fn_802E30C8(lbl_8032BA90, (char *)key, newEntry + 0x24);
        {
            register int zero = 0;
            register float initial = 0.0f;
            newEntry[0x14] = zero;
            newEntry[8] = zero;
            *(int *)(newEntry + 0xC) = zero;
            *(float *)(newEntry + 0x10) = initial;
        }
        *outEntry = newEntry;
    } else {
        *outEntry = (char *)options + 8;
    }
    return 0;
}
#pragma peephole on
int fn_80133F3C(int arg0) {
    int i = 0;
    unsigned int offset;
    int *p;
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
extern char lbl_8042F558[], lbl_8032BAC8[];
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_80133FCC(long stage, long unusedArg) {
    /* Memory-card call-back for the options record ('OPTS' = 0x4F505473), which
     * fn_80133024 registers with the save system.  src/game/memcard.c calls it
     * with a SaveRecordStage around the memcpy of the record's bytes: after a
     * load the card's block has just replaced the whole option table, so the
     * entries held back in lbl_8042F558 are copied over the table entries of the
     * same section and key and every module that registered a call-back in
     * lbl_8042F718 is told to read its options again; a load that failed only
     * gets a message; before a save the table is sorted so the record is written
     * out in a fixed order. */
    typedef struct { long a, b; } Pair;
    char *slot;    /* a table slot; the OptionEntry it holds starts 8 later */
    char *staged;  /* an entry of lbl_8042F558, then a slot of lbl_8042F718 */
    long slotOff;
    long i, j;
    unsigned char key0, key1, key2, key3, key4, key5, key6, key7;
    unsigned char key8, key9, key10, key11, key12, key13, key14, key15;
    void (*callback)(void);
    if (stage == SAVE_RECORD_AFTER_LOAD) {
        staged = lbl_8042F558;
        for (i = 0; i < lbl_8055E080; staged += sizeof(OptionEntry), i++) {
            for (j = 0, slotOff = 0; j < *(long *)((char *)lbl_8055E07C + 4); /* the table's entry count */
                 slotOff += sizeof(OptionEntry), j++) {
                slot = (char *)lbl_8055E07C + slotOff;
                if (*(long *)(staged + 4) == *(long *)(slot + 0xC) && /* section */
                    stricmp(staged + 0x24, slot + 0x2C) == 0) {       /* key */
                    /* the staged entry over the slot's whole entry: its value
                     * words first, then its key one byte at a time. */
                    *(long *)(slot + 0x08) = *(long *)(staged + 0x00);  // valueType
                    *(long *)(slot + 0x0C) = *(long *)(staged + 0x04);  // section
                    *(Pair *)(slot + 0x10) = *(Pair *)(staged + 0x08);  // boolValue, intValue
                    *(Pair *)(slot + 0x18) = *(Pair *)(staged + 0x10);  // floatValue, text[0..3]
                    *(Pair *)(slot + 0x20) = *(Pair *)(staged + 0x18);  // text[4..11]
                    *(long *)(slot + 0x28) = *(long *)(staged + 0x20);  // text[12..15]
                    key0 = *(volatile unsigned char *)(staged + 0x24); key1 = *(volatile unsigned char *)(staged + 0x25);
                    *(volatile unsigned char *)(slot + 0x2C) = key0; *(volatile unsigned char *)(slot + 0x2D) = key1;
                    key2 = *(volatile unsigned char *)(staged + 0x26); key3 = *(volatile unsigned char *)(staged + 0x27);
                    *(volatile unsigned char *)(slot + 0x2E) = key2; *(volatile unsigned char *)(slot + 0x2F) = key3;
                    key4 = *(volatile unsigned char *)(staged + 0x28); key5 = *(volatile unsigned char *)(staged + 0x29);
                    *(volatile unsigned char *)(slot + 0x30) = key4; *(volatile unsigned char *)(slot + 0x31) = key5;
                    key6 = *(volatile unsigned char *)(staged + 0x2A); key7 = *(volatile unsigned char *)(staged + 0x2B);
                    *(volatile unsigned char *)(slot + 0x32) = key6; *(volatile unsigned char *)(slot + 0x33) = key7;
                    key8 = *(volatile unsigned char *)(staged + 0x2C); key9 = *(volatile unsigned char *)(staged + 0x2D);
                    *(volatile unsigned char *)(slot + 0x34) = key8; *(volatile unsigned char *)(slot + 0x35) = key9;
                    key10 = *(volatile unsigned char *)(staged + 0x2E); key11 = *(volatile unsigned char *)(staged + 0x2F);
                    *(volatile unsigned char *)(slot + 0x36) = key10; *(volatile unsigned char *)(slot + 0x37) = key11;
                    key12 = *(volatile unsigned char *)(staged + 0x30); key13 = *(volatile unsigned char *)(staged + 0x31);
                    *(volatile unsigned char *)(slot + 0x38) = key12; *(volatile unsigned char *)(slot + 0x39) = key13;
                    key14 = *(volatile unsigned char *)(staged + 0x32); key15 = *(volatile unsigned char *)(staged + 0x33);
                    *(volatile unsigned char *)(slot + 0x3A) = key14; *(volatile unsigned char *)(slot + 0x3B) = key15;
                    slot[0x3C] = staged[0x34]; slot[0x3D] = staged[0x35];  // the key's
                    slot[0x3E] = staged[0x36]; slot[0x3F] = staged[0x37];  // last 4 bytes
                }
            }
        }
        staged = (char *)lbl_8042F718;  // the {name, call-back} slots
        for (i = 0; i < 8; i++, staged += 8) {
            callback = *(void (**)(void))(staged + 4);
            if (callback) callback();
        }
    } else if (stage == SAVE_RECORD_LOAD_FAILED) {
        fn_802E30C8(lbl_8032BAC8);  // "opt: loading error not handled!"
    }
    if (stage == SAVE_RECORD_BEFORE_SAVE) fn_801337C8();  // sort the table
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
/* Callback invoked when an option identity is cleared; logs the cleared value and
 * removes the matching entry from the options table. */
void fn_801341B4(int optionValue, int event) {
    switch (event) {
    case 0:
        fn_802E30C8(lbl_8032BAE8, optionValue);
        fn_80133F3C(optionValue + 0xC);
        break;
    default:
        break;
    }
}

extern int lbl_8055E07C;
extern int lbl_80559B58;
extern int readOptionsFile(int, int, int);
extern int fn_80133AD8(int);
extern int Abend_Panic(const char *, ...);
extern const char lbl_8032B8B0[];
extern int lbl_8042F718[];
extern const char lbl_8032B8D0[];
extern int fn_80128668(int);
extern int fn_80133E10(void **, int, int);
extern int fn_8013323C(int, int, float);
