// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
extern u64 __mod2u(u64, u64);
extern u64 __div2u(u64, u64);
void __ull2dec(u8 *buf, u32 unused, u64 value) {
    u32 count;
    u32 high;
    u32 low;
    u64 result;
    u8 *right;
    u8 *left;

    buf[0] = 0;
    buf[4] = 0;
    while (value != 0) {
        high = (u32)(value >> 32);
        low = (u32)value;
        result = ((u64 (*)(u32, u32, u64))__mod2u)(high, low, 10);
        count = buf[4];
        buf[5 + count] = (u8)result;
        buf[4] = count + 1;
        result = ((u64 (*)(u32, u32, u64))__div2u)(high, low, 10);
        value = result;
    }
    count = buf[4];
    right = buf + count + 5;
    left = buf + 5;
    while (left < --right) {
        u8 temp = *left;
        *left++ = *right;
        *right = temp;
    }
    *(unsigned short *)(buf + 2) = buf[4] - 1;
}
