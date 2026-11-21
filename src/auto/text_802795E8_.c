// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern void *lbl_8055F618;
extern s32 lbl_8055F61C;
extern void fn_80128670(s32);
extern void *fn_8012850C(s32, const char *);
extern void fn_8027974C(void);
extern void fn_802795E8();
extern void fn_802E30C8(const char *, ...);
extern char lbl_80347818[];
extern char lbl_80347824[];
extern void *memset(void *, int, u32);

/* One vehicle's entry in the carstate table (the "cs_block" allocation this file
   keeps in lbl_8055F618, lbl_8055F61C entries): the vehicle number it belongs to
   and the state block that follows it, which fn_802795E8() initializes. */
typedef struct {
    s32             vehicleId;      /* 0x000: vehicle number */
    unsigned char   state[0x2B4];   /* 0x004: the state block */
} CarStateEntry;                    /* 0x2B8 */
#pragma opt_propagation off
void fn_802795E8(arg0)
void *arg0;
{
    extern f32 lbl_805640F0;
    register unsigned char *p asm("r3");
    register int offset asm("r4");
    register int count asm("r0");
    f32 value;

    memset(arg0, 0, 0x2B4);
    value = lbl_805640F0;
    *(s32 *)((char *)arg0 + 0x298) = (s32)(void *)0;
    *(f32 *)((char *)arg0 + 0x290) = value;
    p = (unsigned char *)arg0;
    offset = 0;
    for (count = 10; count != 0; --count) {
        p[0] = 0x80;
        p[1] = 0x80;
        p[2] = 0x80;
        p[4] = 0x80;
        p[5] = 0x80;
        p[6] = 0x80;
        p[8] = 0x80;
        p[9] = 0x80;
        p[10] = 0x80;
        p[12] = 0x80;
        p[13] = 0x80;
        p[14] = 0x80;
        p[16] = 0x80;
        p[17] = 0x80;
        p[18] = 0x80;
        p[20] = 0x80;
        p[21] = 0x80;
        p[22] = 0x80;
        p[24] = 0x80;
        p[25] = 0x80;
        p[26] = 0x80;
        p[28] = 0x80;
        p[29] = 0x80;
        p[30] = 0x80;
        p[32] = 0x80;
        p[33] = 0x80;
        p[34] = 0x80;
        p[36] = 0x80;
        p[37] = 0x80;
        p[38] = 0x80;
        p[40] = 0x80;
        p[41] = 0x80;
        p[42] = 0x80;
        p[44] = 0x80;
        p[45] = 0x80;
        p[46] = 0x80;
        p[48] = 0x80;
        p[49] = 0x80;
        p[50] = 0x80;
        p[52] = 0x80;
        p[53] = 0x80;
        p[54] = 0x80;
        p[56] = 0x80;
        p[57] = 0x80;
        p[58] = 0x80;
        p[60] = 0x80;
        p[61] = 0x80;
        p[62] = 0x80;
        p += 0x40;
        offset += 0x10;
    }
    *(f32 *)((char *)arg0 + 0x294) = value;
    p = (unsigned char *)arg0 + (offset << 2);
    p[0] = 0x80;
    p[1] = 0x80;
    p[2] = 0x80;
    p[4] = 0x80;
    p[5] = 0x80;
    p[6] = 0x80;
    p[8] = 0x80;
    p[9] = 0x80;
    p[10] = 0x80;
    p[12] = 0x80;
    p[13] = 0x80;
    p[14] = 0x80;
}
#pragma opt_propagation reset
void fn_8027974C(void) {
    /* Call fn_802795E8 for each 0x2B8-byte entry in the array at lbl_8055F618
     * (count lbl_8055F61C), passing a pointer 4 bytes into each entry. */
    s32 entryOffset;
    s32 index;
    entryOffset = 0;
    index = 0;
    goto check;
loop:
    fn_802795E8((char *)lbl_8055F618 + entryOffset + 4);
    entryOffset += 0x2B8;
    index++;
check:
    if (index < lbl_8055F61C) goto loop;
}

#pragma push
#pragma scheduling invalid_target
#pragma inline_depth(0)
void fn_802797A8(s32 *arg0, s32 arg1) {
    s32 offset;
    s32 i;
    char *entry;
    s32 value;

    lbl_8055F61C = arg1;
    lbl_8055F618 = fn_8012850C(arg1 * 0x2B8, lbl_80347818);
    i = 0;
    offset = 0;
    for (; i < lbl_8055F61C; offset += 0x2B8, arg0++, i++) {
        entry = (char *)lbl_8055F618 + offset;
        memset(entry, 0, 0x2B8);
        value = *arg0;
        *(s32 *)entry = value;
    }
    fn_8027974C();
}
#pragma pop
void fn_80279848(void) {
    // Free the carstate block ("cs_block") held in lbl_8055F618 back to the
    // ring-buffer heap via fn_80128670, then clear the global pointer.
    fn_80128670((s32)lbl_8055F618);
    lbl_8055F618 = 0;
}

#pragma scheduling invalid_target
void *fn_80279874(s32 vehicleId) {
    /* CarStateFind(): look a vehicle up in the carstate table (the "cs_block"
       allocation of lbl_8055F61C entries at lbl_8055F618) by its number and
       return its entry, or NULL once the game has complained that the vehicle
       is not in the table. */
    CarStateEntry *entry;
    CarStateEntry *base;
    s32 count;
    s32 i;

    i = 0;
    count = lbl_8055F61C;
    base = (CarStateEntry *)lbl_8055F618;
    entry = base;
    for (; i < count; entry++, ++i) {
        if (vehicleId == entry->vehicleId)
            return base + i;
    }
    fn_802E30C8(lbl_80347824, vehicleId);   /* "carstate: can't find vehicle #%d" */
    return 0;
}
#pragma scheduling reset
f32 fn_802798E8(void *entry) {
    /* Return the float state field at +0x294 of a carstate entry. */
    return *(f32 *)((char *)entry + 0x294);
}

extern f32 lbl_805640F0;
extern f32 lbl_805640F4;
extern f32 lbl_805640F0;
#pragma opt_propagation off
unsigned char fn_802798F0(u32 from, u32 to, f32 weight) {
    /* Interpolate two byte values by weight, bias by +/-0.5 to round to the
       nearest integer, then clamp that integer to [0,255] and return it as a byte. */
    s32 masked;
    s32 rounded;
    f32 adjusted;
    if (((f32)from + (weight * ((f32)to - (f32)from))) < lbl_805640F0) {
        adjusted = ((f32)from + (weight * ((f32)to - (f32)from))) - lbl_805640F4;
    } else {
        adjusted = lbl_805640F4 + ((f32)from + (weight * ((f32)to - (f32)from)));
    }
    rounded = (s32)adjusted;
    masked = rounded & ((-rounded & ~rounded) >> 31);
    return (unsigned char)((masked < 0xFF) ? masked : 0xFF);
}
#pragma opt_propagation reset
extern unsigned char fn_802798F0(unsigned int, unsigned int, float);
extern float lbl_80564100, lbl_80564104;
#pragma dont_inline on
#pragma processor 603
#pragma scheduling invalid_target
/* Fade a car-state color block by `amount`, clamping the stored level (+0x298)
 * to [end - amount, end] (end at +0x294, floored to 0.001).  Each RGBA byte of
 * the 0xA4-entry table at +4 is interpolated toward 0x80/0x80/0x80/0 by the
 * resulting factor and the updated level is written to +0x294, with +0x298 and
 * the trailing bytes at +0x2A0 cleared. */
void fn_802799EC(void *arg0, float amount) {
    unsigned char *p;
    unsigned char *base;
    float current;
    float end;
    float remaining;
    float factor;
    int i;

    base = (unsigned char *)arg0 + 4;
    end = *(float *)((unsigned char *)arg0 + 0x294);
    current = *(float *)((unsigned char *)arg0 + 0x298);
    remaining = end - amount;
    current = current > remaining ? current : remaining;
    end = end > lbl_80564100 ? end : lbl_80564100;
    factor = lbl_80564104 - current / end;
    *(float *)(base + 0x290) = current;
    p = base;
    *(int *)(base + 0x298) = 0;
    for (i = 0; i < 0xA4; i++, p += 4) {
        p[0] = fn_802798F0(p[0], 0x80, factor);
        p[1] = fn_802798F0(p[1], 0x80, factor);
        p[2] = fn_802798F0(p[2], 0x80, factor);
        p[3] = fn_802798F0(p[3], 0, factor);
    }
    base[0x2A0] = 0;
    base[0x2A1] = 0;
    base[0x2A2] = 0;
    base[0x2A3] = 0;
    base[0x2A4] = 0;
    base[0x2A5] = 0;
    base[0x2A6] = 0;
    base[0x2A7] = 0;
    base[0x2A8] = 0;
    base[0x2A9] = 0;
    base[0x2AA] = 0;
    base[0x2AB] = 0;
    base[0x2AC] = 0;
    base[0x2AD] = 0;
    base[0x2AE] = 0;
    base[0x2AF] = 0;
    base[0x2B0] = 0;
    base[0x2B1] = 0;
}
#pragma push
#pragma optimize_for_size on
void fn_80279B28(unsigned char *arg0, unsigned char *arg1) {
    unsigned char second = arg0[5];
    unsigned char first;
    unsigned char *source;
    unsigned char *target;
    int i;

    target = arg1 - 1;
    source = arg0 + 3;
    for (i = 0; i < 0x148; i++) {
        first = source[1];
        second = *(source += 2);
        target[1] = first;
        *(target += 2) = second;
    }

    *(f32 *)(arg1 + 0x290) = *(f32 *)(arg0 + 0x294);
    *(f32 *)(arg1 + 0x294) = *(f32 *)(arg0 + 0x298);
    *(s32 *)(arg1 + 0x298) = *(s32 *)(arg0 + 0x29C);
    *(s32 *)(arg1 + 0x29C) = *(s32 *)(arg0 + 0x2A0);
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2A4];
        unsigned char odd = p[0x2A5];
        arg1[0x2A0] = even;
        arg1[0x2A1] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2A6];
        unsigned char odd = p[0x2A7];
        arg1[0x2A2] = even;
        arg1[0x2A3] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2A8];
        unsigned char odd = p[0x2A9];
        arg1[0x2A4] = even;
        arg1[0x2A5] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2AA];
        unsigned char odd = p[0x2AB];
        arg1[0x2A6] = even;
        arg1[0x2A7] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2AC];
        unsigned char odd = p[0x2AD];
        arg1[0x2A8] = even;
        arg1[0x2A9] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2AE];
        unsigned char odd = p[0x2AF];
        arg1[0x2AA] = even;
        arg1[0x2AB] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2B0];
        unsigned char odd = p[0x2B1];
        arg1[0x2AC] = even;
        arg1[0x2AD] = odd;
    }
    {
        volatile unsigned char *p = arg0;
        unsigned char even = p[0x2B2];
        unsigned char odd = p[0x2B3];
        arg1[0x2AE] = even;
        arg1[0x2AF] = odd;
    }
    arg1[0x2B0] = arg0[0x2B4];
    arg1[0x2B1] = arg0[0x2B5];
}
#pragma opt_unroll_loops off
/* Copy a packed car-state buffer into a carstate entry's state block. The state
 * starts four bytes into the entry (past its vehicleId), so every byte/float/word
 * is written 4 bytes further into the entry than it is read from the buffer. */
void fn_80279C00(unsigned char *entry, unsigned char *buffer) {
    unsigned char secondByte, firstByte;
    unsigned char *readPtr, *writePtr;
    int i;
    writePtr = entry + 3;
    readPtr = buffer - 1;

    for (i = 0; i < 0x148; i++) {
        firstByte = readPtr[1];
        secondByte = *(readPtr += 2);
        writePtr[1] = firstByte;
        *(writePtr += 2) = secondByte;
    }

    *(f32 *)(entry + 0x294) = *(f32 *)(buffer + 0x290);
    *(f32 *)(entry + 0x298) = *(f32 *)(buffer + 0x294);
    *(s32 *)(entry + 0x29C) = *(s32 *)(buffer + 0x298);
    *(s32 *)(entry + 0x2A0) = *(s32 *)(buffer + 0x29C);
    {
        volatile unsigned char *p = buffer;
        unsigned char even = p[0x2A0];
        unsigned char odd = p[0x2A1];
        entry[0x2A4] = even;
        entry[0x2A5] = odd;
    }
    {
        volatile unsigned char *p = buffer;
        unsigned char even = p[0x2A2];
        unsigned char odd = p[0x2A3];
        entry[0x2A6] = even;
        entry[0x2A7] = odd;
    }
    {
        volatile unsigned char *p = buffer;
        unsigned char even = p[0x2A4];
        unsigned char odd = p[0x2A5];
        entry[0x2A8] = even;
        entry[0x2A9] = odd;
    }
    {
        volatile unsigned char *p = buffer;
        unsigned char even = p[0x2A6];
        unsigned char odd = p[0x2A7];
        entry[0x2AA] = even;
        entry[0x2AB] = odd;
    }
    {
        volatile unsigned char *p = buffer;
        unsigned char even = p[0x2A8];
        unsigned char odd = p[0x2A9];
        entry[0x2AC] = even;
        entry[0x2AD] = odd;
    }
    {
        volatile unsigned char *p = buffer;
        unsigned char even = p[0x2AA];
        unsigned char odd = p[0x2AB];
        entry[0x2AE] = even;
        entry[0x2AF] = odd;
    }
    {
        volatile unsigned char *p = buffer;
        unsigned char even = p[0x2AC];
        unsigned char odd = p[0x2AD];
        entry[0x2B0] = even;
        entry[0x2B1] = odd;
    }
    {
        volatile unsigned char *p = buffer;
        unsigned char even = p[0x2AE];
        unsigned char odd = p[0x2AF];
        entry[0x2B2] = even;
        entry[0x2B3] = odd;
    }
    entry[0x2B4] = buffer[0x2B0];
    entry[0x2B5] = buffer[0x2B1];
}
void fn_80279CD8(void) { fn_802795E8(); }

