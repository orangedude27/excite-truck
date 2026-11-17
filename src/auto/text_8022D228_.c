// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma use_lmw_stmw off
#pragma small_data off
extern int sprintf(char *, const char *, ...);
extern char lbl_8055B958[8];
extern float lbl_805635D0;
extern float lbl_805635D4;
extern double lbl_805635C8;
extern char lbl_803401A0[];
extern float lbl_805635C0;
extern float lbl_805635C4;

extern char *strcpy(char *, const char *);
void fn_80128668(void);
extern char *fn_8022D82C(void *, int, int);
extern char *strncpy(char *, const char *, unsigned long);
extern double fabs(double);
extern float lbl_80558DC4[];
extern void *fn_8012850C(int, const char *);
extern char lbl_80340108[];
extern char lbl_80340114[];
/* A "UITB" text table: rows x columns of strings packed into one character buffer,
   each cell holding one tag byte and then its text. Cells are written by fn_8022D894
   and read back by fn_8022D850. */
typedef struct UITable {
    char *text;        /* 0x00 "UITable:buf": every cell's string */
    int columns;       /* 0x04 */
    int rowsUsed;      /* 0x08 highest row written + 1 */
    int rows;          /* 0x0C capacity */
    int rowsInit;      /* 0x10 capacity the text buffer was sized for */
    int rowSize;       /* 0x14 bytes of text per row: sum of (column size + 1) */
    int *columnSizes;  /* 0x18 "column_wids": string capacity of each column */
    int *columnStarts; /* 0x1C "column_offs": where each column starts in a row */
    int cursor;        /* 0x20 field_2C shared over the row count, see fn_8022D924 */
    int updates;       /* 0x24 bumped by every change */
    int magic;         /* 0x28 'UITB' */
    int field_2C;      /* 0x2C -1 as built */
} UITable;

/* Allocation-tag strings held in the pool at lbl_80340108 ("StringList"). */
#define UITAG_COLUMN_SIZES 0x38  /* "column_wids" */
#define UITAG_COLUMN_STARTS 0x44 /* "column_offs" */
#define UITAG_TEXT 0x50          /* "UITable:buf" */
#define UITABLE_MAGIC 0x55495442 /* 'UITB' */
#pragma scheduling invalid_target
void *fn_8022D228(void *arg0, int arg1, int arg2, int arg3) {
    /* Initialize a fixed-capacity string list: store capacity/count/maxLen and allocate
     * the pointer table plus one (maxLen+1)-byte buffer per entry. */
    int offset;
    int i;
    void *result;
    *(int *)arg0 = arg1;
    *(int *)((char *)arg0 + 4) = arg2;
    result = arg0;
    *(int *)((char *)arg0 + 8) = 0;
    *(void **)((char *)arg0 + 0x10) = fn_8012850C(arg1 * 4, lbl_80340108);
    i = 0;
    offset = 0;
    while (i < arg1) {
        *(void **)((char *)*(void **)((char *)result + 0x10) + offset) = fn_8012850C(arg2 + 1, lbl_80340114);
        i++;
        offset += 4;
    }
    return result;
}
#pragma scheduling on
void *fn_8022D2BC(void *object, int freeObject) {
    /* Free each entry in the pointer table at +0x10 (count at +0x00), free the table, then optionally free object. */
    int offset;
    int index;
    if (object != 0) {
        index = 0;
        offset = 0;
        while (index < *(int *)object) {
            fn_80128670(*(void **)((char *)(*(void **)((char *)object + 0x10)) + offset));
            offset += 4;
            index++;
        }
        fn_80128670(*(void **)((char *)object + 0x10));
        if (freeObject > 0) ((void (*)(void *))fn_80128668)(object);
    }
    return object;
}
#pragma scheduling on
/* Append a string entry into a fixed-capacity string table, storing a per-entry tag byte after the null terminator. */
void fn_8022D350(void *arg0, const char *arg1, char arg2) {
    if (*(int *)((char *)arg0 + 8) < *(int *)((char *)arg0)) {
        strncpy((*(char ***)((char *)arg0 + 0x10))[*(int *)((char *)arg0 + 8)],
                arg1, *(int *)((char *)arg0 + 4));
        (*(char ***)((char *)arg0 + 0x10))[*(int *)((char *)arg0 + 8)]
            [*(int *)((char *)arg0 + 4) - 1] = 0;
        (*(char ***)((char *)arg0 + 0x10))[*(int *)((char *)arg0 + 8)]
            [*(int *)((char *)arg0 + 4)] = arg2;
        (*(int *)((char *)arg0 + 8))++;
        (*(int *)((char *)arg0 + 0xC))++;
    }
}

char *fn_8022D3F8(void *arg0, int arg1, int *arg2) {
    /* Look up entry arg1 in the container's table at +0x10 (count at +0x08).
     * If in range, store the signed byte at [entry][+0x04 offset] in *arg2
     * (when non-null) and return the entry pointer; otherwise store 0 and
     * return null. */
    if (arg1 >= 0 && arg1 < *(int *)((char *)arg0 + 8)) {
        if (arg2 != 0) {
            *arg2 = ((signed char *)(*(char ***)((char *)arg0 + 0x10))[arg1])[
                *(int *)((char *)arg0 + 4)];
        }
        return (*(char ***)((char *)arg0 + 0x10))[arg1];
    }
    if (arg2 != 0) *arg2 = 0;
    return 0;
}

extern void fn_8022D76C(void *);
#pragma scheduling invalid_target
/* Build a "UITB" text table in the caller's record: `rows` rows of `columns` strings,
 * every cell one tag byte followed by its text, all packed into a single buffer of
 * rows * rowSize bytes. Allocates the column size and column offset tables and the
 * cell buffer (tags "column_wids", "column_offs" and "UITable:buf"), lays the columns
 * out back to back in a row, and clears the buffer. Returns the table. */
void *fn_8022D458(UITable *table, int rows, int columns, const int *__restrict columnWidths) {
    char *tagStrings;
    int tableBytes;
    int column;
    tagStrings = lbl_80340108;
    tableBytes = columns * 4;
    table->rows = rows;
    table->rowsUsed = 0;
    table->columns = columns;
    table->columnSizes = fn_8012850C(tableBytes, tagStrings + UITAG_COLUMN_SIZES);
    table->columnStarts = fn_8012850C(tableBytes, tagStrings + UITAG_COLUMN_STARTS);
    table->rowsInit = rows;
    table->field_2C = -1;
    table->updates = 0;
    table->magic = UITABLE_MAGIC;
    table->rowSize = 0;
    for (column = 0; column < columns; column++) {
        table->columnSizes[column] = columnWidths[column];
        table->columnStarts[column] = table->rowSize;
        table->rowSize += table->columnSizes[column] + 1;
    }
    table->text = fn_8012850C(rows * table->rowSize, tagStrings + UITAG_TEXT);
    fn_8022D76C(table);
    return table;
}
/* Clears a UITable's text buffer and resets its used-row/cursor counters, then bumps its update count. (renames unavailable: fn_8022D76C->UITable_Clear) */
void fn_8022D76C(void *table) {
    memset(*(void **)table, 0, *(int *)((char *)table + 0xC) * *(int *)((char *)table + 0x14));
    *(int *)((char *)table + 8) = 0;
    *(int *)((char *)table + 0x20) = 0;
    *(int *)((char *)table + 0x24) += 1;
}

/* Destroy table buffers and optionally free the table object. */
void *fn_8022D7C4(void *table, int shouldFree) {
    if (table != 0) {
        fn_80128670(*(int *)((char *)table + 0x18));
        fn_80128670(*(int *)((char *)table + 0x1C));
        fn_80128670(*(int *)table);
        if (shouldFree > 0) ((void (*)(void *))fn_80128668)(table);
    }
    return table;
}

#pragma push
#pragma dont_inline on
/* Returns a pointer to the text buffer cell at (row, column) of a UITable. */
char *fn_8022D82C(void *table, int row, int column) {
    return ((UITable *)table)->text +
           row * ((UITable *)table)->rowSize +
           ((UITable *)table)->columnStarts[column];
}
#pragma pop

/* RealName: UITable_ReadCell
 * Returns a pointer to the text of a UITable cell (after the tag byte) and,
 * if outTag is non-null, stores the cell's signed tag byte there.
 */
char *fn_8022D850(void *arg0, int row, int column, int *outTag) {
    char *cell = fn_8022D82C(arg0, row, column);
    if (outTag != 0) *outTag = (signed char)*cell;
    return cell + 1;
}

#pragma scheduling reset
/* Write a string cell in a fixed-stride table: store the tag byte, copy the text, update the used row count, and bump the modification count. */
void fn_8022D894(void *arg0, int arg1, int arg2, const char *arg3, signed char arg4) {
    char *ptr = fn_8022D82C(arg0, arg1, arg2);
    int next = arg1 + 1;
    int len;
    if (next > *(int *)((char *)arg0 + 8)) *(int *)((char *)arg0 + 8) = next;
    len = (*(int **)((char *)arg0 + 0x18))[arg2];
    *ptr = arg4;
    strncpy(ptr + 1, arg3, len);
    ptr += len;
    *ptr = 0;
    *(int *)((char *)arg0 + 0x24) += 1;
}
#pragma scheduling invalid_target
void fn_8022D924(volatile int *p, int arg1) {
    int cnt = p[0x24 / 4];
    int v = p[0x2C / 4];
    p[0x10 / 4] = arg1;
    p[0x24 / 4] = cnt + 1;
    if (v < 0) return;
    if (v >= 0) { arg1 = v; goto divide; }
    return;
store:
    cnt = p[0x24 / 4];
    p[0x20 / 4] = arg1;
    p[0x24 / 4] = cnt + 1;
    return;
divide:
    cnt = p[0x10 / 4];
    p[0x2C / 4] = arg1;
    arg1 = arg1 / cnt;
    p[0x24 / 4] = p[0x24 / 4] + 1;
    goto store;
}
#pragma scheduling on
/* Indexed accessor: returns the address of the index-th entry in a 40-byte-record array. */
int fn_8022D97C(int *basePtr, int index) {
    return *basePtr + index * 0x28;
}

#pragma push
#pragma scheduling invalid_target
void fn_8022D98C(void *arg0, int arg1, float arg2, float arg3, float arg4, float arg5, float arg6) {
    float value = arg4;
    volatile int *count = (volatile int *)((char *)arg0 + 0x1C);
    int n;
    *(int *)((char *)arg0 + 0x18) = arg1;
    *(void **)arg0 = lbl_803401A0;
    *(float *)((char *)arg0 + 4) = arg2;
    *(float *)((char *)arg0 + 8) = arg3;
    *(float *)((char *)arg0 + 0xC) = arg5;
    *(float *)((char *)arg0 + 0x10) = arg6;
    *count = 0;
    do {
        n = *count;
        value = value * lbl_805635C0;
        *count = n + 1;
        if ((value - (float)(int)value > lbl_805635C4) == 0)
            break;
        if (*count < 4)
            continue;
        break;
    } while (1);
    *(float *)((char *)arg0 + 0x14) = arg4 / (arg3 - arg2);
}
#pragma pop
int fn_8022DA34(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* RealName: FloatGauge_FormatValue. Constants used when printing a gauge value. */
#define GAUGE_FLOAT_FORMAT lbl_8055B958   /* "%1.*f" */
#define GAUGE_ROUND_EPS lbl_805635D0      /* 0.0004: nudges the printed value up */
#pragma push
#pragma scheduling invalid_target
/* Format a FloatGauge's value as a decimal string: the interpolated value
 * (min + value*(max-min)) is printed with the gauge's fixed decimal precision. */
void fn_8022DA74(void *gauge, char *out) {
    register void *data = gauge;
    register float displayMax = *(volatile float *)((char *)gauge + 8);
    register float displayMin = *(volatile float *)((char *)data + 4);
    register float displayRange = displayMax - displayMin;
    register float value = **(float **)((char *)data + 0x18);
    register int decimalPlaces = *(int *)((char *)data + 0x1C);
    sprintf(out, GAUGE_FLOAT_FORMAT, decimalPlaces, GAUGE_ROUND_EPS + (displayMin + value * displayRange), displayRange, displayMin);
}
#pragma pop
/* Normalize a float gauge's current value into [0, 1] as (value - min)/(max - min):
 * min/max live at +0x0C/+0x10 and +0x18 points to the gauge's current value. */
float fn_8022DAB0(void *gauge) {
    float min = *(float *)((char *)gauge + 0xC);
    return (**(float **)((char *)gauge + 0x18) - min) / (*(float *)((char *)gauge + 0x10) - min);
}

void fn_8022DAD0(void *params, float t) {
    /* Quantize an interpolated value (low + t*(high-low)) to step increments and store it. */
    float high = *(float *)((char *)params + 0x10);
    float low = *(float *)((char *)params + 0x0C);
    float step = *(float *)((char *)params + 0x14);
    **(float **)((char *)params + 0x18) = step * (float)(int)(lbl_805635D4 + ((low + t * (high - low)) / step));
}

#pragma push
#pragma scheduling invalid_target
void fn_8022DB34(void *gauge, char *text) {
    /* Format an int gauge's current value into text using the gauge's printf format. */
    int value = **(int **)((char *)gauge + 4);
    sprintf(text, *(char **)((char *)gauge + 0x10), value, gauge);
}
#pragma pop
/* Initialize a repeating counter/timer object. */
void fn_8022DB50(void *obj, int field0, int field4, int step, int field14) {
    *(int *)obj = field0;
    *(int *)((char *)obj + 4) = field4;
    *(int *)((char *)obj + 0x10) = step;
    *(int *)((char *)obj + 8) = step;
    while (*(int *)((char *)obj + 8) < 5) {
        *(int *)((char *)obj + 8) += *(int *)((char *)obj + 0x10);
    }
    *(int *)((char *)obj + 0x14) = field14;
    *(int *)((char *)obj + 0xC) = 0;
    *(char *)((char *)obj + 0x18) = 0;
}

int fn_8022DB94(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* A circular index selector: `index` walks [0, count) over parallel element arrays. */
typedef struct IndexSelector {
    int *values;  /* 0x00 */
    int *tags;    /* 0x04 */
    int field8;   /* 0x08 */
    int index;    /* 0x0C current index */
    int count;    /* 0x10 number of elements */
} IndexSelector;

#pragma dont_inline on
/* Return the element of the selector's values array at its current index. */
int fn_8022DBD4(IndexSelector *selector) {
    int *values = selector->values;
    return values[selector->index];
}
#pragma dont_inline off

/* Return the tag at an IndexSelector's current index (element of its +0x4 array at +0xC). */
int fn_8022DBE8(void *selector) {
    int *tags = *(int **)((char *)selector + 4);
    return tags[*(int *)((char *)selector + 0xC)];
}

void fn_8022DBFC(void *selector) {
    /* Advance the selector's index (+0xC) by one, wrapping back to 0 when it reaches the count (+0x10). */
    int nextIndex = *(int *)((char *)selector + 0xC) + 1;
    *(int *)((char *)selector + 0xC) = nextIndex;
    if (nextIndex >= *(int *)((char *)selector + 0x10)) *(int *)((char *)selector + 0xC) = 0;
}

void fn_8022DC20(IndexSelector *selector) {
    /* Step the selector's index back by one, wrapping to count-1 when it falls below zero (the inverse of fn_8022DBFC). */
    int index = selector->index - 1;
    selector->index = index;
    if (index < 0) selector->index = selector->count - 1;
}

#pragma dont_inline on
// Wraps the index at +0xC into [0, count) by subtracting the count at +0x10.
void fn_8022DC40(void *obj, int index) {
    int count;
    *(int *)((char *)obj + 0xC) = index;
    goto check;
loop:
    *(int *)((char *)obj + 0xC) -= count;
check:
    count = *(int *)((char *)obj + 0x10);
    if (*(int *)((char *)obj + 0xC) >= count) goto loop;
}
#pragma dont_inline off

int fn_8022DC68(void *arg0, int arg1) {
    /* Temporarily set the index at +0xC to arg1 via fn_8022DC40, fetch the element
     * at that index with fn_8022DBD4, then restore the saved index and return it. */
    int saved = *(int *)((char *)arg0 + 0xC);
    int value;
    fn_8022DC40(arg0, arg1);
    value = fn_8022DBD4(arg0);
    fn_8022DC40(arg0, saved);
    return value;
}

#pragma push
#pragma use_lmw_stmw off
/* Initializes a table of 0x10-byte string slots by copying `count` names from
 * `names`, then stores the count at +0x40 and `extra` at +0x44. Returns `dest`. */
void *fn_8022DCC4(void *dest, char **names, int count, int extra) {
    char **namePtr = names;
    char *slot = (char *)dest;
    int index = 0;
    while (index < count) {
        strcpy(slot, *namePtr);
        namePtr++;
        slot += 0x10;
        index++;
    }
    *(int *)((char *)dest + 0x40) = count;
    *(int *)((char *)dest + 0x44) = extra;
    return dest;
}
#pragma pop
void *fn_8022DD38(void *arg0, int arg1) {
#define mCount ((char *)arg0 + 0x40)
#define DeleteObject fn_80128668
    /* Reset the object's count to zero and optionally delete it, returning the object. */
    if (arg0 != 0) {
        *(int *)mCount = 0;
        if (arg1 > 0) DeleteObject();
    }
    return arg0;
#undef mCount
#undef DeleteObject
}

/* Return the number of entries stored in the 16-byte-slot string table (+0x40). */
int fn_8022DD80(void *table) { return *(int *)((char *)table + 0x40); }

int fn_8022DD88(void *arg0) { return *(int *)((char *)arg0 + 0x44); }

/* Return a pointer to the index-th 16-byte glyph record in the table. */
int fn_8022DD90(int table, int index) { return table + index * 16; }

/* Return a float gauge's value pointer (the word at +0x18) in *valuePtrOut and write the type code 4 to *typeOut. */
void fn_8022DD9C(void *gauge, int *valuePtrOut, int *typeOut) {
    *valuePtrOut = *(int *)((char *)gauge + 0x18);
    *typeOut = 4;
}

#pragma push
#pragma opt_propagation off
#pragma scheduling invalid_target
void fn_8022DDB0(void *arg0) {
    float c = lbl_805635D4;
    float *p = *(float **)((char *)arg0 + 0x18);
    float step = *(float *)((char *)arg0 + 0x14);
    float v = step * (float)(int)(c + ((*p + step) / step));
    float low = *(float *)((char *)arg0 + 0x10);
    *p = (low < v) ? low : v;
}
#pragma scheduling on
void fn_8022DE1C(void *arg0) {
    float c = lbl_805635D4;
    float *p = *(float **)((char *)arg0 + 0x18);
    float step = *(float *)((char *)arg0 + 0x14);
    float v = step * (float)(int)(c + ((*p - step) / step));
    float low = *(float *)((char *)arg0 + 0x0C);
    *p = (low > v) ? low : v;
}
#pragma scheduling invalid_target
int fn_8022DE88(void *object) {
#define gZeroEpsilon lbl_80558DC4
    /* Return 0 when |the float at +0x10 minus the float pointed to by +0x18| is within the zero epsilon, else 1. */
    float current = *(float *)((char *)object + 0x10);
    float *value_ptr = *(float **)((char *)object + 0x18);
    float value = *value_ptr;
    float mag = (float)__fabs(current - value);
    if (mag <= *(float *)(void *)&gZeroEpsilon) return 0;
    if (mag > *(float *)(void *)&gZeroEpsilon) return 1;
    return 1;
#undef gZeroEpsilon
}
#pragma pop
extern double __fabs(double);
#pragma push
#pragma optimization_level 1
int fn_8022DEC4(void *arg0) {
    float *valuePtr = *(float **)((char *)arg0 + 0x18);
    float current = *(float *)((char *)arg0 + 0xC);
    float value = *valuePtr;
    float diff = current - value;
    float mag = __fabs(diff);
    if (mag <= lbl_80558DC4[0]) {
        return 0;
    } else {
        return 1;
    }
}
#pragma pop
/* Return an int gauge's value pointer (the word at +0x04) in *valuePtrOut and write the type code 4 to *typeOut. */
void fn_8022DF00(void *gauge, int *valuePtrOut, int *typeOut) {
    *valuePtrOut = *(int *)((char *)gauge + 4);
    *typeOut = 4;
}

/* An int gauge: +0x04 int *value it owns, +0x08 min, +0x0C max, +0x10 a printf
 * format for the value (fn_8022DB34).  fn_8022DF14 / fn_8022DF48 step it up and
 * down inside [min, max], fn_8022DF7C / fn_8022DF9C test value != max / min,
 * fn_8022DFBC normalizes it and fn_8022E014 interpolates into it.
 * (The float gauges next door keep their value pointer at +0x18 instead.) */
void fn_8022DF14(void *gauge) {
    /* Step an int gauge's value up by one, held inside its [min, max] range. */
    int value;
    int max;
    int *valuePtr;
    int stepped;
    int min;
    valuePtr = *(int **)((char *)gauge + 4);
    max = *(int *)((char *)gauge + 0xC);
    value = *valuePtr;
    if (max < value + 1) {
        stepped = max;
    } else {
        stepped = value + 1;
    }
    min = *(int *)((char *)gauge + 8);
    if (stepped > min) {
        min = stepped;
    }
    *valuePtr = min;
}

/* Step an int gauge's value down by one, held inside its [min, max] range:
 * value = max(min, min(max, *valuePtr - 1)).  The gauge points at the value it
 * owns at +0x04 and keeps its low and high limits at +0x08 and +0x0C;
 * fn_8022DF14 is the step-up half of the pair, and fn_8022DF9C / fn_8022DF7C
 * say whether stepping down / up would change the value at all. */
void fn_8022DF48(void *gauge) {
    int value;
    int max;
    int *valuePtr;
    int stepped;
    int min;
    valuePtr = *(int **)((char *)gauge + 4);
    max = *(int *)((char *)gauge + 0xC);
    value = *valuePtr;
    if (max < value - 1) {
        stepped = max;
    } else {
        stepped = value - 1;
    }
    min = *(int *)((char *)gauge + 8);
    if (stepped > min) {
        min = stepped;
    }
    *valuePtr = min;
}

extern char *fn_8022D82C(void *, int, int);
extern char *strncpy(char *, const char *, unsigned long);
extern double fabs(double);
/* Returns nonzero while an int gauge's value has not reached its max (+0x0C),
 * i.e. stepping the gauge up would still change the value. */
int fn_8022DF7C(void *gauge) {
    int *valuePtr = *(int **)((char *)gauge + 4);
    return *(int *)((char *)gauge + 0xC) != *valuePtr;
}

/* Returns nonzero while an int gauge's value has not reached its min (+0x08),
 * i.e. stepping the gauge down would still change the value. */
int fn_8022DF9C(void *gauge) {
    int *valuePtr = *(int **)((char *)gauge + 4);
    return *(int *)((char *)gauge + 8) != *valuePtr;
}

#pragma scheduling invalid_target
float fn_8022DFBC(void *arg0) {
    /* Return normalized progress of *arg0->value within [arg0->min, arg0->max] as (value - min) / (max - min). */
    int offset = *(int *)((char *)arg0 + 8);
    int denominator = *(int *)((char *)arg0 + 0xC) - offset;
    int numerator = **(int **)((char *)arg0 + 4) - offset;
    float convertedNumerator = (float)numerator;
    float convertedDenominator = (float)denominator;
    return convertedNumerator / convertedDenominator;
}
#pragma scheduling on
/* Set the pointed-to value by interpolating from base (+8) toward max (+0xC) by t. */
void fn_8022E014(void *obj, float t) {
    int base = *(int *)((char *)obj + 8);
    *(int *)*(int **)((char *)obj + 4) = base + (int)(t * (float)(*(int *)((char *)obj + 0xC) - base));
}

int fn_8022E064(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

