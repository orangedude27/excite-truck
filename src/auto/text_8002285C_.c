// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
extern u64 __mod2u(u64, u64);
extern u64 __div2u(u64, u64);
void __ull2dec(u8 *decimal, u32 unused, u64 value) {
    u32 digitCount;
    u32 high;
    u32 low;
    u64 result;
    u8 *tail;
    u8 *head;

    /* Convert unsigned 64-bit value to decimal digits into the internal decimal buffer:
     * [0]=sign, [2..3]=last digit index, [4]=digit count, [5..]=digit bytes.
     * Digits are produced least-significant first, then reversed in place. */
    decimal[0] = 0;
    decimal[4] = 0;
    while (value != 0) {
        high = (u32)(value >> 32);
        low = (u32)value;
        result = ((u64 (*)(u32, u32, u64))__mod2u)(high, low, 10);
        digitCount = decimal[4];
        decimal[5 + digitCount] = (u8)result;
        decimal[4] = digitCount + 1;
        result = ((u64 (*)(u32, u32, u64))__div2u)(high, low, 10);
        value = result;
    }
    digitCount = decimal[4];
    tail = decimal + digitCount + 5;
    head = decimal + 5;
    while (head < --tail) {
        u8 temp = *head;
        *head++ = *tail;
        *tail = temp;
    }
    *(unsigned short *)(decimal + 2) = decimal[4] - 1;
}
