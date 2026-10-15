typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

M2C_UNK GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(s32);

void fn_800F27C4(void *arg0) {
    GetPlayerCount__Q46nw4hbm3snd6detail22SoundArchiveFileReaderCFv(M2C_FIELD(arg0, s32 *, 4));
}
