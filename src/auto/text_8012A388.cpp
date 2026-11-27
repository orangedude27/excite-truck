#include <types.h>
struct E7FC { char pad[0x28]; int v28; unsigned int v30; };

/* Bits in a resource entry's flag word (struct ResEntry +0x34). */
#define RES_ENTRY_REQUESTED 1 /* ResourceGet asked to report a first request */
#define RES_ENTRY_IN_USE 2    /* a reference is held (set by ResourceGet) */
#define RES_ENTRY_ALLOCATED 4 /* LoadEntryData allocated the object for it */
#define RES_ENTRY_LOADED 8    /* the entry's data is loaded and CRC-checked */
/* Bits tested together when two entries share a name (fn_8012B50C). */
#define RES_ENTRY_NAME_PRIMARY   0x20 /* set on the entry found first for a name */
#define RES_ENTRY_NAME_DUPLICATE 0x10 /* set on a later entry with the same name */

/* One entry of a resource manager's table (stride 0x44); the name is at +0x00
 * (findResourceEntry compares it with stricmp). The five words at +0x20 are stored
 * byte-reversed and swapped by fn_8012A388 when the table is read in. */
struct ResEntry {
    /* 0x00 */ char name[0x20];
    /* 0x20 */ u32 dataTag; /* fourcc the caller must ask for, e.g. 'SFX0', 'ETOC' */
    /* 0x24 */ u32 id;      /* 16-bit id (fn_8012A388 keeps only its low half) */
    /* 0x28 */ s32 size;    /* data size; the object is allocated with 0x80 bytes more */
    /* 0x2C */ s32 offset;  /* offset in the manager's archive (+ manager+0x80) */
    /* 0x30 */ u32 crc;     /* CRC the extracted data has to match */
    /* 0x34 */ u32 flags;   /* RES_ENTRY_* bits */
    /* 0x38 */ s32 useCount; /* references taken by ResourceGet, dropped by fn_8012BC50 */
    /* 0x3C */ u8 *header;  /* 0x80-byte block header ('MGI!' at +4); payload is +8 */
    /* 0x40 */ void *object; /* the allocation fn_80128660 frees */
};

/* One resource manager ("resource set") in the global list lbl_8055E000: the
 * 0xB0-byte node loadResourceNode builds from one resource file. Its directory name
 * is the string at +0x00 (findResourceEntry matches a path's directory against it)
 * and the list link is +0xA8. */
struct ResManager {
    /* 0x00 */ char dirName[0x20]; /* directory this set's entries answer to */
    /* 0x20 */ char fileName[0x40]; /* the archive FileLookup opens for the set */
    /* 0x60 */ u8 *entries; /* struct ResEntry[entryCount], stride 0x44 */
    char pad64[0x1C];
    /* 0x80 */ s32 dataOffset; /* where the set's data starts in the archive */
    char pad84[4];
    /* 0x88 */ s32 entryCount;
    char pad8C[0x10];
    /* 0x9C */ s32 useCount; /* live references held on this set */
    char padA0[0x8];
    /* 0xA8 */ struct ResManager *next;
};

/* The 0x18-byte async read request popped from the "AsyncResource" pool
 * (lbl_8032ABF8) and returned by openResourceStream. The code accesses it as a flat
 * volatile s32 array; this enum names the slots it writes. */
enum AsyncRequestField {
    ASYNC_REQ_MAGIC = 0,   /* 0x00: signature stamp */
    ASYNC_REQ_ENTRY = 1,   /* 0x04: struct ResEntry being streamed */
    ASYNC_REQ_MANAGER = 2, /* 0x08: owning struct ResManager */
    ASYNC_REQ_HANDLE = 3,  /* 0x0C: async read handle, -1 while idle */
    ASYNC_REQ_DATA = 4,    /* 0x10: loaded data pointer */
    ASYNC_REQ_UNUSED = 5   /* 0x14 */
};
#define ASYNC_RESOURCE_MAGIC 0x19AFEE2A
extern "C" int sprintf(char *, const char *, ...);
extern "C" s32 lbl_80559984;
extern "C" char lbl_805599AC[];
extern "C" void fn_801282F4(void);
extern "C" void fn_801284F0(void *, void *);
extern "C" s32 FileLookup(void);
extern "C" void fn_802E3A14(s32, s32);
extern "C" s32 fn_802E3804(s32, void *, s32);
extern "C" void closeFileHandle(s32 *);
extern "C" s8 lbl_8055DFF8;
extern "C" u8 lbl_805599B8;
extern "C" const char lbl_8032AE9C[];
extern "C" void fn_8012BEF0(s32);
extern "C" void fn_8012DBD0(void);
extern "C" s32 lbl_8055DFFC;
extern "C" const char lbl_8032AE60[];
extern "C" const char lbl_8032A8E8[];
extern "C" void releaseResource(void *);
extern "C" s32 fn_80128668(void *);
struct Fn8012AFE0Ent { u8 pad[0x34]; u32 flags; u8 pad2[0xC]; };
/* 13-word resource block header copied into a load request at +0x6C. */
struct ResBlockHeader { s32 words[13]; };
extern "C" const char lbl_8032ADF4[];
extern "C" const char lbl_8032AE20[];
extern "C" void fn_80128660(s32);
extern "C" s32 fn_802E748C(s32, s32, void *);
extern "C" s32 KERNEL_GetTimeMs(void);
extern "C" void fn_8002B0D8(char *);
extern "C" char *fn_80029004(char *, int);
extern "C" s32 getResourceData(s32, s32, s32, s32, s32, s32);
class Unk8012A570 { public: virtual ~Unk8012A570(); };

extern "C" s32 lbl_8055E004;
extern "C" void **lbl_8055E008;
extern "C" u32 lbl_805599A0;
extern "C" u8 lbl_8032A6F8[];
extern "C" s32 lbl_8055E00C;
extern "C" void **lbl_8055E010;
extern "C" u8 lbl_8032AC88[];
extern "C" u8 lbl_8032ACA0[];
extern "C" u8 lbl_8032ACD0[];
extern "C" u8 lbl_8032ACB0[];
namespace nw4r { namespace ef { class Effect; } }
extern "C" nw4r::ef::Effect *lbl_8055E014;
extern "C" void fn_80127CF4(s32, s32);
extern "C" void *fn_801284F8(u32, void *);
extern "C" void **fn_8012A13C(void *, void *, u32, u32);
extern "C" void *fn_8012A2D8(void **);
extern "C" void fn_8012A364(void **, void *);
extern "C" void *fn_8012A570(u32, void *);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" s32 stricmp(const char *, const char *);
extern "C" s32 ResourceGetEntry(s32, s32, s32, s32, s32, s32);
extern "C" const char lbl_805599A4[1];
extern "C" void *findResourceEntry(char *arg0, s32 *arg1, u32 arg2);
extern "C" void fn_80127464(void);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" void Abend_Panic(const char *, ...);
extern "C" const char lbl_8032AB78[];
extern "C" u8 lbl_8055DFF9;
extern "C" void *lbl_8055E000;
extern "C" s32 fn_8012BC50(void *, void *, s32);
extern "C" s32 findResourceOwningMount(s32, s32);
extern "C" const char lbl_8032AD88[];
extern "C" const char lbl_8032AD6C[];
extern "C" const char lbl_8032AD2C[];
extern "C" const char lbl_8032ADA0[];
extern "C" const char lbl_8032ADDC[];

extern "C" void *fn_8012CB44(void *, s32);
extern "C" void fn_8012CA40(void *);
extern "C" void waitForResourceLoad(s32, s32);
extern "C" void fn_8012E5E4(void *, void *);
extern "C" void fn_8012E630(void *);
extern "C" s32 fn_8012E674(void *);
extern "C" void fn_8012D3D8(s32);
extern "C" void fn_8012D8A8(s32);
extern "C" void *fn_801282EC(u32);
extern "C" void *fn_8012850C(u32, void *);
extern "C" void *memset(void *, s32, u32);
extern "C" u8 lbl_805599C8;
extern "C" u8 lbl_805599D0;
extern "C" u8 lbl_805599E0;

extern "C" void fn_8012E498(void *);
extern void fn_8012CC24(void);
extern "C" u32 fn_8012D3D0(void);
/* fn_8012CC24: two args (object*, char* path list), returns s32. */
extern "C" void fn_8012D33C(u32 *, u32 *);
extern "C" void fn_8012D1A8(s32 arg0);
extern "C" s32 loadResourceFromNameList(void *, s32, s32);

#pragma use_lmw_stmw off
/* Byte-swap the five little-endian u32 fields of a resource-table entry in place
 * (dataTag, id, size, offset, crc at +0x20..+0x33), clear its flags and useCount,
 * and mask id down to 16 bits. Returns the entry pointer. */
extern "C" s32 fn_8012A388(void *entry) {
    u8 idByte0, tagByte0, sizeByte0, offsetByte0, crcByte0;
    u8 idByte1, tagByte1, sizeByte1, offsetByte1, crcByte1;
    idByte0 = *(u8 *)((u8 *)entry + 0x24);
    idByte1 = *(u8 *)((u8 *)entry + 0x25);
    tagByte0 = *(u8 *)((u8 *)entry + 0x20);
    tagByte1 = *(u8 *)((u8 *)entry + 0x21);
    sizeByte0 = *(u8 *)((u8 *)entry + 0x28);
    sizeByte1 = *(u8 *)((u8 *)entry + 0x29);
    offsetByte0 = *(u8 *)((u8 *)entry + 0x2c);
    offsetByte1 = *(u8 *)((u8 *)entry + 0x2d);
    crcByte0 = *(u8 *)((u8 *)entry + 0x30);
    crcByte1 = *(u8 *)((u8 *)entry + 0x31);
    *(u8 *)((u8 *)entry + 0x24) = *(u8 *)((u8 *)entry + 0x27);
    *(u8 *)((u8 *)entry + 0x27) = idByte0;
    *(u8 *)((u8 *)entry + 0x25) = *(u8 *)((u8 *)entry + 0x26);
    *(u8 *)((u8 *)entry + 0x26) = idByte1;
    *(u8 *)((u8 *)entry + 0x20) = *(u8 *)((u8 *)entry + 0x23);
    *(u8 *)((u8 *)entry + 0x23) = tagByte0;
    *(u8 *)((u8 *)entry + 0x21) = *(u8 *)((u8 *)entry + 0x22);
    *(u8 *)((u8 *)entry + 0x22) = tagByte1;
    *(u8 *)((u8 *)entry + 0x28) = *(u8 *)((u8 *)entry + 0x2b);
    *(u8 *)((u8 *)entry + 0x2b) = sizeByte0;
    *(u8 *)((u8 *)entry + 0x29) = *(u8 *)((u8 *)entry + 0x2a);
    *(u8 *)((u8 *)entry + 0x2a) = sizeByte1;
    *(u8 *)((u8 *)entry + 0x2c) = *(u8 *)((u8 *)entry + 0x2f);
    *(u8 *)((u8 *)entry + 0x2f) = offsetByte0;
    *(u8 *)((u8 *)entry + 0x2d) = *(u8 *)((u8 *)entry + 0x2e);
    *(u8 *)((u8 *)entry + 0x2e) = offsetByte1;
    *(u8 *)((u8 *)entry + 0x30) = *(u8 *)((u8 *)entry + 0x33);
    *(u8 *)((u8 *)entry + 0x33) = crcByte0;
    *(u8 *)((u8 *)entry + 0x31) = *(u8 *)((u8 *)entry + 0x32);
    *(u8 *)((u8 *)entry + 0x32) = crcByte1;
    *(u32 *)((u8 *)entry + 0x38) = 0;
    *(u32 *)((u8 *)entry + 0x34) = 0;
    *(u32 *)((u8 *)entry + 0x24) &= 0xFFFF;
    return (s32)entry;
}
#pragma use_lmw_stmw reset
extern "C" const char lbl_8032A630[];
extern "C" void fn_8012A46C(void *, const char *);
extern "C" s32 fn_80132E7C(void *, s32);
/* Debug hook that reports a loaded resource (its data pointer and a label);
 * the release build compiles it away, leaving an empty body. */
extern "C" void fn_8012A46C(void *data, const char *label) {

}

#pragma dont_inline on
#pragma use_lmw_stmw off
extern "C" s32 fn_8012A470(void *arg0, s32 arg1, void *arg2, void *arg3) {
#pragma scheduling invalid_target
    register const char *strings = lbl_8032A630;
    register char *buffer;
    s32 result;

    buffer = (char *)arg3 + *(s32 *)((char *)arg2 + 0x2C) - 8;
    *(void **)((char *)arg2 + 0x3C) = buffer;
    fn_8012A46C(buffer + 8, strings);
    result = (u32)__cntlzw((u32)*(s32 *)((char *)arg2 + 0x30) -
                           (u32)fn_80132E7C((char *)*(void **)((char *)arg2 + 0x3C) + 8,
                                            *(s32 *)((char *)arg2 + 0x28))) >> 5;
    if (result) {
        if (*(u32 *)((char *)arg2 + 0x34) & 8) {
            fn_802E30C8(strings + 0xC);
            fn_802E30C8(strings + 0x34);
            fn_802E30C8(strings + 0x5C);
            fn_802E30C8(strings + 0xC);
            Abend_Panic(strings + 0x88, arg0, arg1, arg2);
        }
        *(u32 *)((char *)arg2 + 0x34) |= 8;
    } else {
        fn_802E30C8(strings + 0xA8, arg0, arg1, arg2);
    }
    return result;
}
#pragma push
#pragma scheduling invalid_target
/* Lazily create the shared fixed-size pool object, pop one element from it and
   bump the live-user count on success (size/name are ignored; the layout is fixed). */
extern "C" void *fn_8012A570(u32 size, void *name) {
#define poolRefCount lbl_8055E004
#define poolObject lbl_8055E008
#define Pool_NAME lbl_8032A6F8
    if (poolRefCount == 0) {
        void *value = fn_801284F8(0x20, Pool_NAME);
        if (value != 0)
            value = fn_8012A13C(value, Pool_NAME, 0x20, 0x18);
        poolObject = (void **)value;
    }
    void *element = fn_8012A2D8(poolObject);
    if (element != 0)
        poolRefCount += 1;
    return element;
#undef poolRefCount
#undef poolObject
#undef Pool_NAME
}
#pragma pop
extern "C" void fn_8012A5E8(void *element) {
    /* Return an element to the shared pool and destroy the pool when the last user releases it. */
    fn_8012A364(lbl_8055E008, element);
    if (--lbl_8055E004 == 0) {
        delete (Unk8012A570 *)lbl_8055E008;
        lbl_8055E008 = 0;
    }
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012A648(void) {
    /* Prime the shared fixed-size pool: grab one 0x18-byte element (creating the pool if needed) and push it back onto its free list. */
    void *element = fn_8012A570(0x18, &lbl_805599A0);
    fn_8012A364(lbl_8055E008, element);
}
#pragma pop
#pragma dont_inline reset
#pragma scheduling reset
#pragma dont_inline on
extern "C" void fn_8012A67C(void) {
#define poolRefCount lbl_8055E004
#define poolObject lbl_8055E008
    /* Clear the shared pool's reference count and destroy/release its object. */
    poolRefCount = 0;
    delete (Unk8012A570 *)poolObject;
    poolObject = 0;
#undef poolRefCount
#undef poolObject
}

#pragma push
#pragma scheduling invalid_target
extern "C" s32 fn_8012A6C8(s32 arg0, s32 arg1, s32 arg2) {
    /* Validates an RSTM/"RST0" header (magic, header size, version, and optional expected field) after running its 0x30-byte checksum/init; logs a mismatch and returns 0 on failure, 1 on success. */
    const char *messages = lbl_8032A630;
    u32 *header = (u32 *)arg0;
    volatile u8 magicText[5];
    u32 firstByte;
    u8 fourthByte;
    u32 secondByte;
    u8 thirdByte;
    u32 value;

    fn_80132E7C((void *)arg0, 0x30);
    value = header[0];
    if (value != 0x52535430) {
        *(volatile u32 *)magicText = 0x52535430;
        firstByte = magicText[0];
        fourthByte = magicText[3];
        secondByte = magicText[1];
        thirdByte = magicText[2];
        magicText[0] = fourthByte;
        magicText[3] = firstByte;
        magicText[1] = thirdByte;
        magicText[2] = secondByte;
        magicText[4] = 0;
        fn_802E30C8(messages + 0xDC, (const char *)arg1, value, (const char *)magicText);
        goto failed;
    }
    value = header[2];
    if (value != 8) {
        fn_802E30C8(messages + 0x114, (const char *)arg1, value, 8);
        goto failed;
    }
    value = header[1];
    if (value != 0x34) {
        fn_802E30C8(messages + 0x148, (const char *)arg1, value, 0x34);
        goto failed;
    }
    value = header[4];
    if (value != (u32)arg2 && arg2 != 0) {
        fn_802E30C8(messages + 0x180, (const char *)arg1, value, arg2);
        goto failed;
    }
    return 1;
failed:
    return 0;
}
#pragma pop
#pragma scheduling reset

extern "C" s32 KERNEL_WaitMilliseconds(s32);
extern "C" s32 fn_802E39D0(s32, s32);
extern "C" void fn_8012A80C(s32);
extern "C" s32 fn_8012A6C8(s32, s32, s32);
extern "C" s32 fn_8012AB34(s32, s32, s32, s32);
extern "C" s32 FileLookup(void);
extern "C" s32 fn_802E37C4(void);
extern "C" void closeFileHandle(s32 *);
extern "C" s32 fn_802E4CA8(void *, s32, s32);
extern "C" s32 fn_802E7354(void *);
extern "C" s32 getStreamEntryInfo(s32, s32 *, s32 *);
#pragma scheduling off
extern "C" void fn_8012A7FC(void) {
#define sLoadRetryFlag lbl_8055DFF9
#define waitMs KERNEL_WaitMilliseconds
    /* Raise the load-retry flag and busy-wait 50 ms (0x32) on the millisecond timer. */
    sLoadRetryFlag = 1;
    waitMs(0x32);
#undef waitMs
#undef sLoadRetryFlag
}

static inline void Swap4(u8 *q) {
    u8 t = q[0]; q[0] = q[3]; q[3] = t;
    t = q[1]; q[1] = q[2]; q[2] = t;
}

extern "C" void fn_8012A80C(s32 arg0)
{
  u8 *p = (u8 *) arg0;
  s32 s48;
  s32 s44;
  char s40;
  s32 s3C;
  s32 s38;
  s32 s30;
  s32 s2C;
  s32 s34;
  s32 s28;
  volatile unsigned int s24;
  s32 s20;
  s32 s1C;
  s32 s18;
  s32 s14;
  s32 s10;
  s32 sC;
  s32 s8;
  u8 k21;
  u8 k29;
  u8 k28;
  u8 k25;
  u8 k24;
  u8 k20;
  u8 k1D;
  u8 k1C;
  u8 k19;
  u8 k18;
  u8 k15;
  u8 k12;
  u8 k11;
  u8 k10;
  u8 kD;
  u8 k9;
  u8 b0;
  volatile long b1;
  u8 b2;
  u8 b3;
  u8 kC;
  u8 b4;
  u8 b5;
  u8 b6;
  u8 b7;
  u8 b8;
  u8 bB;
  s48 = p[0xA];
  kD = p[0xD];
  k9 = p[9];
  s8 = p[0xF];
  kC = p[0xC];
  sC = p[0xE];
  s10 = p[0x13];
  k10 = p[0x10];
  s14 = p[0x12];
  k11 = p[0x11];
  s18 = p[0x17];
  k12 = p[0x14];
  s1C = p[0x16];
  k15 = p[0x15];
  s20 = p[0x1B];
  k18 = p[0x18];
  s24 = p[0x1A];
  k19 = p[0x19];
  s28 = p[0x1F];
  k1C = p[0x1C];
  s2C = p[0x1E];
  k1D = p[0x1D];
  s30 = p[0x23];
  k20 = p[0x20];
  s34 = p[0x22];
  k21 = p[0x21];
  s38 = p[0x27];
  k24 = p[0x24];
  s3C = p[0x26];
  k25 = p[0x25];
  s40 = p[0x2B];
  b0 = p[0];
  k28 = p[0x28];
  s44 = p[0x2A];
  k29 = p[0x29];
  b1 = p[1];
  b2 = p[2];
  b3 = p[3];
  b4 = p[4] & 0xFFFFu;
  b5 = p[5];
  b6 = p[6];
  b8 = p[8];
  b7 = p[7];
  bB = p[0xB];
  ((u8 *) arg0)[9] = (u8) s48;
  ((u8 *) arg0)[0xC] = (u8) s8;
  ((u8 *) arg0)[0xD] = (u8) sC;
  ((u8 *) arg0)[0x10] = (u8) s10;
  ((u8 *) arg0)[0x11] = (u8) s14;
  ((u8 *) arg0)[0x14] = (u8) s18;
  ((u8 *) arg0)[0x15] = (u8) s1C;
  ((u8 *) arg0)[0x18] = (u8) s20;
  ((u8 *) arg0)[0x19] = (u8) s24;
  ((u8 *) arg0)[0x1C] = (u8) s28;
  ((u8 *) arg0)[0x1D] = (u8) s2C;
  ((u8 *) arg0)[0x20] = (u8) s30;
  ((u8 *) arg0)[0x21] = (u8) s34;
  ((u8 *) arg0)[0x24] = (u8) s38;
  ((u8 *) arg0)[0x25] = (u8) s3C;
  ((u8 *) arg0)[0x28] = (u8) s40;
  ((u8 *) arg0)[0x29] = (u8) s44;
  ((u8 *) arg0)[0] = b3;
  ((u8 *) arg0)[3] = b0;
  ((u8 *) arg0)[1] = b2;
  ((u8 *) arg0)[2] = b1;
  ((u8 *) arg0)[4] = b7;
  ((u8 *) arg0)[7] = b4;
  ((u8 *) arg0)[5] = b6;
  ((u8 *) arg0)[6] = b5;
  ((u8 *) arg0)[8] = bB;
  ((u8 *) arg0)[0xB] = b8;
  ((u8 *) arg0)[0xA] = k9;
  ((u8 *) arg0)[0xF] = kC;
  ((u8 *) arg0)[0xE] = kD;
  ((u8 *) arg0)[0x13] = k10;
  ((u8 *) arg0)[0x12] = k11;
  ((u8 *) arg0)[0x17] = k12;
  ((u8 *) arg0)[0x16] = k15;
  ((u8 *) arg0)[0x1B] = k18;
  ((u8 *) arg0)[0x1A] = k19;
  ((u8 *) arg0)[0x1F] = k1C;
  ((u8 *) arg0)[0x1E] = k1D;
  ((u8 *) arg0)[0x23] = k20;
  ((u8 *) arg0)[0x22] = k21;
  ((u8 *) arg0)[0x27] = k24;
  ((u8 *) arg0)[0x26] = k25;
  ((u8 *) arg0)[0x2B] = k28;
  ((u8 *) arg0)[0x2A] = k29;
  {
    u8 c = p[0x2C];
    u8 e = p[0x30];
    u8 f = p[0x31] ^ 0;
    u8 d = p[0x2D];
    do
    {
      p[0x2C] = p[0x2F];
      p[0x2F] = c;
      p[0x2D] = p[0x2E];
      p[0x2E] = d;
    }
    while (0);
    p[0x30] = p[0x33];
    p[0x33] = e;
    p[0x31] = p[0x32];
    p[0x32] = f;
  }
}

#pragma scheduling reset
enum { RST0_HEADER_SIZE = 0x34 };
#define File_readExact      fn_802E39D0
#define Rst0Header_byteSwap fn_8012A80C
#define Rst0Header_validate fn_8012A6C8
extern "C" s32 fn_8012A388(void *);
extern "C" s32 fn_802E7544(s32);
extern "C" void closeStreamHandle(s32);
extern "C" const char lbl_8032AC68[];
extern "C" s32 fn_8012A470(void *, s32, void *, void *);
extern "C" s32 fn_80132E7C(void *, s32);
extern "C" const char lbl_8032A7E8[];
extern int __cntlzw(unsigned int);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Validate a sound resource's table of contents: CRC the entry array and
 * compare it with the stored checksum, then for each 0x44-byte entry byte-swap
 * it in place and check that its data lies within avail and that its own CRC
 * passes.  A bad table checksum is reported and the function returns 0; a fully
 * valid table returns 1. */
extern "C" s32 fn_8012AA60(void *resource, s32 avail, s32 unusedOffset) {
    void *entry;
    s32 entryCount;
    void *tableBase;
    s32 expectedCrc;
    s32 valid;
    s32 entryIndex;

    entryCount = *(s32 *)((char *)resource + 0x88);
    entry = *(void **)((char *)resource + 0x60);
    expectedCrc = *(s32 *)((char *)resource + 0x94);
    tableBase = entry;
    valid = (u32)__cntlzw((u32)(fn_80132E7C(entry, entryCount * 0x44) - expectedCrc)) >> 5;
    if (valid != 0) {
        for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
            fn_8012A388(entry);
            if (*(s32 *)((char *)entry + 0x2C) + *(s32 *)((char *)entry + 0x28) <= avail) {
                if (fn_8012A470(resource, entryIndex, entry, tableBase) == 0) {
                    valid = 0;
                    break;
                }
            }
            entry = (char *)entry + 0x44;
        }
    } else {
        fn_802E30C8(lbl_8032A7E8, resource);
    }
    return valid;
}
#pragma pop
/* Read a 0x34-byte RST0 header from fileHandle into headerBuffer, byte-swap
 * its fields in place, and validate the header against fileName and expectedField. */
extern "C" s32 fn_8012AB34(s32 fileHandle, s32 headerBuffer, s32 fileName, s32 expectedField) {
    s32 isValid = 0;
    if (((s32 (*)(s32, s32, s32))File_readExact)(fileHandle, headerBuffer, RST0_HEADER_SIZE) != 0) {
        Rst0Header_byteSwap(headerBuffer);
        isValid = Rst0Header_validate(headerBuffer, fileName, expectedField);
    }
    return isValid;
}

/* OpenCheckRst0 - open `name` through the engine file API (src/game/file.c) and make sure the
 * file behind that name is really the one it claims to be: read its 0x34-byte RST0 header into
 * headerBuffer, byte-swap it and check it against the name and the size the file API reports
 * for the open file (fn_8012AB34).  A file whose header does not check out is closed again and
 * handed back as -1; otherwise the handle comes back still open with its header in hand. */
extern "C" s32 fn_8012ABB0(const char *name, void *headerBuffer) {
    /* The engine file API, as this open-check-and-maybe-close sequence uses it. */
    #define File_open       FileLookup  /* open `name`: file handle, or -1 */
    #define File_size       fn_802E37C4  /* size of the file the handle has open */
    #define File_close      closeFileHandle  /* close it; the handle goes back to -1 */
    #define Rst0_readHeader fn_8012AB34  /* read the RST0 header and validate it */
    s32 handle = ((s32 (*)(const char *))File_open)(name);
    if (handle != -1 && Rst0_readHeader(handle, (s32)headerBuffer, (s32)name, ((s32 (*)(s32))File_size)(handle)) == 0) {
        File_close(&handle);
        handle = -1;
    }
    #undef File_open
    #undef File_size
    #undef File_close
    #undef Rst0_readHeader
    return handle;
}

#pragma push
#pragma scheduling invalid_target
extern "C" s32 fn_8012AC28(s32 parser, s32 outSize) {
    /* Copy the stream name out of the parser, then return the stream's start sector
     * (2048-byte units) or -1; optionally write its byte size to outSize. */
    u8 name[0x104];
    s32 startSector;
    s32 size;
    s32 streamIndex;
    startSector = -1;
    fn_802E4CA8(&name[0], parser, 0x104);
    streamIndex = fn_802E7354(&name[0]);
    if (streamIndex != -1) {
        getStreamEntryInfo(streamIndex, &startSector, &size);
        if (outSize != 0) *(s32 *)outSize = size;
    }
    return startSector;
}
#pragma pop

extern "C" void fn_8012AC98(s32 parser) {
    /* Tail-call fn_8012AC28 with no output-size pointer: look up and return a
     * stream's start sector from its name without also fetching the byte size. */
    fn_8012AC28(parser, 0);
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" s32 fn_8012ACA0(void *arg0, void *arg1, s32 arg2) {
    char sp10[128];
    s32 spC;
    u8 sp8;
    register u8 *temp_r3_3;
    register const char *messages = (const char *)lbl_8032A630;
    char *var_r4;
    s32 var_r5;
    char *var_r6;
    char *var_r4_2;
    s32 var_r5_2;
    char *var_r6_2;
    s32 var_r25;
    u32 var_r24, var_r26;
    u8 temp_r3, temp_r3_2;
    u8 temp_r4, temp_r4_2, temp_r4_3, temp_r4_4, temp_r4_5;
    u8 temp_r4_6, temp_r4_7, temp_r4_8, temp_r4_9, temp_r4_10;
    u32 temp_r4_11;
    u8 *temp_r26, *var_r25_2, *var_r31;
    char *dot;
    if (lbl_8055DFFC == 0) Abend_Panic(messages + 0x1D0, arg0);
    var_r4 = (char *)arg0; var_r6 = sp10; var_r5 = 0x80;
    goto loop_5_copy;
loop_5_limit:
    var_r5 -= 1;
    if (var_r5 > 0) goto loop_5_copy;
    var_r6[-1] = 0;
    goto loop_5_done;
loop_5_copy:
    temp_r3 = *var_r4++;
    *var_r6++ = temp_r3;
    if ((s8)temp_r3 != 0) goto loop_5_limit;
loop_5_done:
    dot = fn_80029004(sp10, 0x2E);
    if ((s8)*dot != 0) {
        dot = fn_80029004(sp10, 0x2E);
        *dot = 0;
    }
    var_r6_2 = sp10; var_r5_2 = 0x80;
    goto loop_10_test;
loop_10_step:
    var_r5_2 -= 1;
    var_r6_2 += 1;
loop_10_test:
    if ((s8)*var_r6_2 != 0) goto loop_10_step;
    if (var_r5_2 <= 0) goto loop_10_done;
    var_r4_2 = (char *)&lbl_805599E0;
    goto loop_15_copy;
loop_15_limit:
    var_r5_2 -= 1;
    if (var_r5_2 > 0) goto loop_15_copy;
    var_r6_2[-1] = 0;
    goto loop_10_done;
loop_15_copy:
    temp_r3_2 = *var_r4_2++;
    *var_r6_2++ = temp_r3_2;
    if ((s8)temp_r3_2 != 0) goto loop_15_limit;
loop_10_done:
    fn_8002B0D8(sp10);
    temp_r3_3 = (u8 *)getResourceData((s32)sp10, 0x45544F43, (s32)&spC, 0, 0, (s32)&sp8);
    if (temp_r3_3 != 0 && sp8 != 0) {
        temp_r4 = temp_r3_3[0]; temp_r3_3[0] = temp_r3_3[3]; temp_r3_3[3] = temp_r4;
        temp_r4_2 = temp_r3_3[1]; temp_r3_3[1] = temp_r3_3[2]; temp_r3_3[2] = temp_r4_2;
        temp_r4_3 = temp_r3_3[4]; temp_r3_3[4] = temp_r3_3[7]; temp_r3_3[7] = temp_r4_3;
        temp_r4_4 = temp_r3_3[5]; temp_r3_3[5] = temp_r3_3[6]; temp_r3_3[6] = temp_r4_4;
        temp_r4_5 = temp_r3_3[8]; temp_r3_3[8] = temp_r3_3[0xB]; temp_r3_3[0xB] = temp_r4_5;
        temp_r4_6 = temp_r3_3[9]; temp_r3_3[9] = temp_r3_3[0xA]; temp_r3_3[0xA] = temp_r4_6;
        temp_r4_7 = temp_r3_3[0xC]; temp_r3_3[0xC] = temp_r3_3[0xF]; temp_r3_3[0xF] = temp_r4_7;
        temp_r4_8 = temp_r3_3[0xD]; temp_r3_3[0xD] = temp_r3_3[0xE]; temp_r3_3[0xE] = temp_r4_8;
        temp_r4_9 = temp_r3_3[0x10]; temp_r3_3[0x10] = temp_r3_3[0x13]; temp_r3_3[0x13] = temp_r4_9;
        temp_r4_10 = temp_r3_3[0x11]; temp_r3_3[0x11] = temp_r3_3[0x12]; temp_r3_3[0x12] = temp_r4_10;
        temp_r4_11 = *(u32 *)temp_r3_3;
        if (temp_r4_11 != 0 || *(u32 *)(temp_r3_3 + 4) != 0x14)
            Abend_Panic(lbl_8032AE60, temp_r4_11, 0, *(u32 *)(temp_r3_3 + 4), 0x14);
        var_r25_2 = temp_r3_3 + 0x14; var_r26 = 0;
        goto loop_23_test;
loop_23:
        fn_8012A388(var_r25_2);
        var_r25_2 += 0x44; var_r26 += 1;
loop_23_test:
        if (var_r26 < *(u32 *)(temp_r3_3 + 0xC)) goto loop_23;
    }
    if (temp_r3_3 == 0) Abend_Panic(messages + 0x200, arg0);
    if (*(u32 *)(temp_r3_3 + 8) != *(u32 *)((u8 *)arg0 + 0x7C))
        Abend_Panic(messages + 0x228, arg0);
    if (*(u32 *)(temp_r3_3 + 0xC) != *(u32 *)((u8 *)arg0 + 0x88))
        Abend_Panic(messages + 0x258, arg0);
    if (*(u32 *)(temp_r3_3 + 0x10) != *(u32 *)((u8 *)arg0 + 0x8C))
        Abend_Panic(messages + 0x288, arg0);
    temp_r26 = temp_r3_3 + 0x14; var_r31 = temp_r26; var_r25 = 1; var_r24 = 0;
    goto loop_37_test;
loop_37:
    if (*(s32 *)(var_r31 + 0x2C) + *(s32 *)(var_r31 + 0x28) <= arg2) {
        if (fn_8012A470(arg0, var_r24, var_r31, arg1) == 0) { var_r25 = 0; goto loop_37_done; }
    }
    var_r31 += 0x44; var_r24 += 1;
loop_37_test:
    if (var_r24 < *(u32 *)(temp_r3_3 + 0xC)) goto loop_37;
loop_37_done:
    *(void **)((u8 *)arg0 + 0x60) = temp_r26;
    *(void **)((u8 *)arg0 + 0x64) = temp_r3_3;
    return var_r25;
}

#pragma push
#pragma processor 750
extern "C" void *loadResourceNode(void *arg0, void *arg1) {
    /* Load a resource file into a 0xB0-byte node: open/validate it, allocate the
       node, copy the name strings and header, read the data, parse it, and on
       failure tear the node down; returns the node, or 0 on failure. */
    u32 header[13];
    s32 handle;
    u8 *node = 0;
    u8 *fileName = (u8 *)arg0;
    u8 c;
    u8 *src;
    s32 n;
    u8 *dst;
    u8 c2;
    s32 n2;
    u8 *dst2;
    s32 size;
    s32 data;
    s32 var_r31;
    s32 parseResult;

    handle = ((s32 (*)(void *, void *))fn_8012ABB0)(arg0, header);
    if (handle != -1) {
        node = (u8 *)fn_801284F8(0xB0, (void *)lbl_8032A8E8);
        if (node != 0) {
            var_r31 = ((s32 (*)(void *))fn_8012AC98)(fileName);
            node[0xAC] = 0;
            src = (u8 *)arg1; dst = node; n = 0x20;
            goto copy1;
limit1:
            n -= 1;
            if (n > 0) goto copy1;
            dst[-1] = 0;
            goto done1;
copy1:
            c = *src++; *dst++ = c;
            if ((s8)c != 0) goto limit1;
done1:
            dst2 = node + 0x20; n2 = 0x40;
            goto copy2;
limit2:
            n2 -= 1;
            if (n2 > 0) goto copy2;
            dst2[-1] = 0;
            goto done2;
copy2:
            c2 = *fileName++; *dst2++ = c2;
            if ((s8)c2 != 0) goto limit2;
done2:
            *(s32 *)(node + 0xA8) = 0;
            *(s32 *)(node + 0x60) = 0;
            if (header != 0) {
                *(u32 *)(node + 0x68) = header[0];
                *(u32 *)(node + 0x6C) = header[1];
                *(u32 *)(node + 0x70) = header[2];
                *(u32 *)(node + 0x74) = header[3];
                *(u32 *)(node + 0x78) = header[4];
                *(u32 *)(node + 0x7C) = header[5];
                *(u32 *)(node + 0x80) = header[6];
                *(u32 *)(node + 0x84) = header[7];
                *(u32 *)(node + 0x88) = header[8];
                *(u32 *)(node + 0x8C) = header[9];
                *(u32 *)(node + 0x90) = header[10];
                *(u32 *)(node + 0x94) = header[11];
                *(u32 *)(node + 0x98) = header[12];
            } else {
                memset(node + 0x68, 0, 0x34);
            }
            *(s32 *)(node + 0x9C) = 1;
            *(s32 *)(node + 0xA0) = 0;
            *(s32 *)(node + 0xA4) = var_r31;
            node[0xAC] = 1;
            *(s32 *)(node + 0x64) = 0;
            node[0xAD] = 0;
        }
        size = header[9];
        fn_801282F4();
        fn_801282EC(0x80);
        data = (s32)((void *(*)(void *, s32))fn_801284F0)(arg1, size);
        fn_802E3A14(handle, *(s32 *)(node + 0x80));
        fn_802E3804(handle, (void *)data, size);
        *(s32 *)(node + 0xA0) = data;
        if (header[3] & 1) {
            *(s32 *)(node + 0x60) = 0;
            parseResult = fn_8012ACA0(node, (void *)data, size);
        } else {
            *(s32 *)(node + 0x60) = *(s32 *)(node + 0xA0);
            parseResult = ((s32 (*)(void *, s32))fn_8012AA60)(node, size);
        }
        if (parseResult == 0) {
            fn_8012A7FC();
            if (node != 0) {
                if (node[0xAC] != 0) {
                    var_r31 = 0;
                    n = 0;
                    while (var_r31 < *(s32 *)(node + 0x88)) {
                        u8 *e = (u8 *)*(void **)(node + 0x60) + n;
                        if (*(u32 *)(e + 0x34) & 4) Abend_Panic(lbl_8032AE20, e);
                        var_r31 += 1;
                        e = (u8 *)*(void **)(node + 0x60) + n;
                        u32 fl = *(u32 *)(e + 0x34);
                        n += 0x44;
                        *(u32 *)(e + 0x34) = fl & ~0xF;
                    }
                    if (*(s32 *)(node + 0x64) != 0) releaseResource(*(void **)(node + 0x64));
                    if (*(s32 *)(node + 0xA0) != 0) fn_80128660(*(s32 *)(node + 0xA0));
                    node[0xAC] = 0;
                }
                fn_80128668(node);
            }
            node = 0;
        }
        closeFileHandle(&handle);
    }
    return node;
}

__declspec(section ".sdata") extern char lbl_805599AC[];
extern "C" s32 fn_8012B2C4(s32 buffer, s32 str, s32 flag) {
#define kStringPrefix lbl_80559984
#define kConcatFormat lbl_805599AC
    /* If flag is zero, write the fixed prefix followed by str into buffer and return buffer; otherwise return 0. */
    s32 result = 0;
    if (flag == 0) {
        sprintf((char *)buffer, kConcatFormat, kStringPrefix, str);
        result = buffer;
    }
    return result;
#undef kConcatFormat
#undef kStringPrefix
}

#pragma pop
extern "C" int sprintf(char *, const char *, ...);
extern "C" s32 lbl_80559984;
extern "C" char lbl_805599AC[];
extern "C" s32 fn_8012B2C4(s32, s32, s32);
/* Argument-swapping shim: calls fn_8012B2C4(buffer, value, flag) -- which formats value into
 * buffer when flag is zero -- and returns the resulting buffer pointer. */
extern "C" void *fn_8012B314(s32 value, s32 buffer, s32 flag) {
    return (void *)fn_8012B2C4(buffer, value, flag);
}

/* No-op resource-load failure hook: invoked with the rejected node when loadResourceNode
 * cannot resolve a resource (paired with the success hook fn_8012B328); does nothing. */
extern "C" void fn_8012B324(void) {

}

/* No-op resource-load success hook: invoked when a resource node is resolved
 * (paired with the failure hook fn_8012B324); does nothing. */
extern "C" void fn_8012B328(void) {

}

extern "C" void *loadResourceNode(void *, void *);
extern char lbl_8032A960[];
#pragma scheduling invalid_target
/* Look up a named resource by iterating candidate nodes until loadResourceNode resolves one (logs "res: loading %s"). */
extern "C" void *fn_8012B32C(const char *arg0) {
    u8 scratch[0x48];
    void *result = 0;
    s32 index;
    void *node;

    fn_802E30C8(lbl_8032A960, arg0);
    index = 0;
    for (;;) {
        node = ((void *(*)(void *, void *, s32))fn_8012B314)((void *)arg0, scratch, index);
        if (node == 0)
            break;
        result = loadResourceNode(node, (void *)arg0);
        if (result != 0) {
            ((void (*)(void))fn_8012B328)();
            break;
        }
        ((void (*)(void *))fn_8012B324)(node);
        index += 1;
    }
    return result;
}
#pragma scheduling on

extern "C" char *fn_80029004(char *, int);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012B3D4(char *arg0, int arg1, char *arg2, int arg3, char *arg4) {
    /* Splits path in arg4 at the last '/': copies directory part to arg0 (arg1 bytes max)
       and filename part to arg2 (arg3 bytes max). If no '/', arg0 becomes empty and arg2 gets the whole path. */
    char *src;
    char *dst;
    char *slash;
    int count;

    src = arg4;
    dst = arg0;
    count = arg1;
    while ((signed char)(*dst++ = *src++) != 0) {
        if (--count <= 0) {
            dst[-1] = 0;
            break;
        }
    }

    slash = fn_80029004(arg0, 0x2F);
    if (slash != 0) {
        *slash = 0;
        src = slash + 1;
        dst = arg2;
        count = arg3;
        while ((signed char)(*dst++ = *src++) != 0) {
            if (--count <= 0) {
                dst[-1] = 0;
                break;
            }
        }
    } else {
        *arg0 = 0;
        src = arg4;
        dst = arg2;
        count = arg3;
        while ((signed char)(*dst++ = *src++) != 0) {
            if (--count <= 0) {
                dst[-1] = 0;
                break;
            }
        }
    }
}
#pragma pop

#pragma scheduling invalid_target
extern "C" u8 *fn_8012B4E4(u8 *path, s8 *hasWildcard) {
    /* Detect a leading '*' wildcard in a resource path: report it through
       hasWildcard and skip the character when present. */
    s8 ch = (s8)*path;
    *hasWildcard = (s8)(ch - 0x2A == 0);
    if (ch == 0x2A)
        return path + 1;
    return path;
}
#pragma scheduling on
extern "C" s32 fn_8012B50C(void *existingEntry, void *duplicateEntry) {
    /* Name-clash check: true when the entry found first for a name is flagged
       as the primary and a later, duplicate-named entry is flagged as a
       duplicate. Used by findResourceEntry while resolving resources by path. */
    if ((((struct ResEntry *)existingEntry)->flags & RES_ENTRY_NAME_PRIMARY) &&
        (((struct ResEntry *)duplicateEntry)->flags & RES_ENTRY_NAME_DUPLICATE)) return 1;
    return 0;
}

extern "C" const char lbl_8032A970[];
extern "C" const char lbl_8032A99C[];
extern "C" u8 lbl_805599B4;
extern "C" void reportGetBeforeWaitError(s32);
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling invalid_target
/* Resolves a resource path (optionally '*'-wildcarded) to its manager and entry index,
 * warning on duplicate names and honoring flags for not-ready and missing-resource reporting. */
extern "C" void *findResourceEntry(char *path, s32 *entryIndexOut, u32 flags) {
    u8 hasWildcard;
    char name[0x100];
    char dir[0x100];
    s32 allowNotReady;
    s32 suppressErrors;
    u8 *foundManager;
    s32 entryOffset;
    u8 *manager;
    s32 index;

    allowNotReady = flags & 1;
    suppressErrors = (flags >> 1) & 1;
    path = (char *)fn_8012B4E4((u8 *)path, (s8 *)&hasWildcard);
    fn_8012B3D4(dir, 0x100, name, 0x100, path);
    if (hasWildcard != 0 && (s8)dir[0] == 0) {
        fn_802E30C8(lbl_8032A970, path);
    }
    *entryIndexOut = -1;
    foundManager = 0;
    for (manager = (u8 *)lbl_8055E000; manager != 0; manager = *(u8 **)(manager + 0xA8)) {
        if ((s8)dir[0] == 0 || stricmp((char *)manager, dir) == 0) {
            for (index = 0, entryOffset = 0; index < *(s32 *)(manager + 0x88); entryOffset += 0x44, index++) {
                if (stricmp((char *)(*(u8 **)(manager + 0x60) + entryOffset), name) == 0) {
                    if (*entryIndexOut != -1) {
                        fn_8012B50C((char *)*(u8 **)(foundManager + 0x60) + *entryIndexOut * 0x44,
                                    (char *)*(u8 **)(manager + 0x60) + entryOffset);
                    } else {
                        foundManager = manager;
                        *entryIndexOut = index;
                    }
                }
            }
        }
    }
    if (foundManager != 0 && *(u8 *)(foundManager + 0xAD) != 0 && suppressErrors == 0) {
        Abend_Panic(lbl_8032A99C, foundManager != 0 ? (char *)foundManager : (char *)&lbl_805599B4, path);
    }
    if (allowNotReady == 0 && foundManager != 0 && hasWildcard == 0 &&
        (*(u32 *)(*(u8 **)(foundManager + 0x60) + *entryIndexOut * 0x44 + 0x34) & 8) == 0) {
        foundManager = 0;
    }
    if (foundManager == 0 && suppressErrors == 0) {
        reportGetBeforeWaitError((s32)path);
    }
    return foundManager;
}

/* Base of this file's pooled string literals. */
static inline const char *GetStringBase(void) {
    return lbl_8032A630;
}

/* Entry `index` of the 0x44-byte table at +0x60. */
static inline u8 *GetEntry(void *self, s32 index) {
    return (u8 *)*(void **)((u8 *)self + 0x60) + index * 0x44;
}

/* Allocate `size` bytes for `owner`, aligned to 0x80. */
static inline void *AllocAligned80(void *owner, s32 size) {
    fn_801282F4();
    fn_801282EC(0x80);
    return ((void *(*)(void *, s32))fn_801284F0)(owner, size);
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling on
/* fn_8012B6FC's body; the pragmas below inline it into that function only. */
static inline s32 LoadEntryDataBody(struct ResManager *manager, s32 entryIndex) {
    struct ResEntry *entry;
    u8 *header;
    void *object;
    s32 handle;
    s32 startTime;
    u32 flags;
    const char *strings;

    entry = (struct ResEntry *)manager->entries + entryIndex;
    flags = entry->flags;
    strings = lbl_8032A630;
    if (!(flags & RES_ENTRY_LOADED)) {
        /* The object holds the entry's data behind an 0x80-byte block header. */
        object = AllocAligned80(entry, entry->size + 0x80);
        if (object != 0) {
            startTime = KERNEL_GetTimeMs();
            handle = ((s32 (*)(void *))FileLookup)(manager->fileName);
            if (handle != -1) {
                /* The block header sits in front of the data: back-pointer to the
                 * entry, then its 'MGI!' tag. */
                *(struct ResEntry **)((u8 *)object + 0x78) = entry;
                *(u32 *)((u8 *)object + 0x7C) = 0x4D474921; /* 'MGI!' */
                header = (u8 *)object + 0x78;
                fn_802E3A14(handle, entry->offset + manager->dataOffset);
                fn_802E3804(handle, header + 8, entry->size);
                if (entry->crc == (u32)fn_80132E7C(header + 8, entry->size)) {
                    flags = entry->flags | RES_ENTRY_ALLOCATED | RES_ENTRY_LOADED;
                    entry->flags = flags;
                    entry->header = header;
                    entry->object = object;
                    ((void (*)(void *, const char *))fn_8012A46C)(header + 8,
                                                                  strings + 0x3B0); /* "extracted res" */
                    fn_802E30C8(strings + 0x3C0, manager, entry,
                                KERNEL_GetTimeMs() - startTime); /* "EXTRACTION: LOADED %s/%s %d msec" */
                } else {
                    fn_802E30C8(strings + 0x3E4, entry); /* "res: crc failure on extraction: %s" */
                    fn_8012A7FC();
                }
                closeFileHandle(&handle);
            }
            flags = entry->flags;
            if (!(flags & RES_ENTRY_LOADED)) {
                fn_80128660((s32)object); /* nothing loaded: give the allocation back */
            }
        }
    }
    flags = entry->flags;
    return (flags >> 3) & 1; /* RES_ENTRY_LOADED */
}

/* The inline helpers above must be inlined into fn_8012B6FC only. */
#pragma push
#pragma dont_inline off
#pragma auto_inline off
/* LoadEntryData: make entry `entryIndex` of the resource set `manager` resident.
 * Unless it is loaded already, allocate the entry's data behind an 0x80-byte
 * block header, open the set's archive, seek to the entry's place in it, read
 * the data and check it against the entry's CRC: on success the entry keeps the
 * header and the allocation, gains RES_ENTRY_ALLOCATED|RES_ENTRY_LOADED and the
 * load is logged with the time it took, on failure the CRC message is logged and
 * the allocation handed back. Returns the entry's RES_ENTRY_LOADED bit, which
 * tells ResourceGet (ResourceGetEntry) whether it can hand out the entry's data. */
extern "C" s32 fn_8012B6FC(struct ResManager *manager, s32 entryIndex) {
    return LoadEntryDataBody(manager, entryIndex);
}
#pragma pop
#pragma scheduling invalid_target
/* ResourceGet: look the resource `path` up in the resource-manager list, make
 * sure its data is loaded (LoadEntryData) and, if the entry carries the fourcc
 * type tag the caller asked for, take a reference on it and hand back the
 * loaded data (the payload of the entry's 0x80-byte block header).
 * `path` is a char*, `dataTag` a fourcc such as 'ETOC', and the last four
 * arguments are out pointers:
 *   outId        - the entry's id
 *   outSize      - the size of its data
 *   outFirstUse  - whether this reference is the entry's first one
 *   outNewRequest- whether the entry was not marked "requested" until now
 * Returns 0 when the resource is unknown, could not be made resident, or has
 * another type tag than asked for (each reported on the "res:" log). */
/* Look up a resource by path and fourcc tag, make it resident, take a reference and return its loaded data. */ extern "C" s32 ResourceGetEntry(s32 path, s32 dataTag, s32 outId, s32 outSize, s32 outFirstUse, s32 outNewRequest) {
    /* The entry's flag word at +0x34, seen as bitfields. */
    struct EntryFlags {
        u32 rest : 31;
        u32 requested : 1;
    };
    s32 index;
    u8 wantedTagText[5];
    u8 entryTagText[5];
    struct ResManager *manager;
    const char *strings = lbl_8032A630;
    u8 *result = 0;
    manager = (struct ResManager *)((struct ResManager *(*)(s32, s32 *, s32))findResourceEntry)(path, &index, 0);
    if (manager != 0) {
        if (fn_8012B6FC(manager, index) != 0) {
            struct ResEntry *entry = (struct ResEntry *)(manager->entries + index * 0x44);
            if ((u32)dataTag == entry->dataTag) {
                s32 count;
                entry->flags |= RES_ENTRY_IN_USE;
                if ((s8 *)outNewRequest != 0) {
                    s32 requested = ((EntryFlags *)&entry->flags)->requested;
                    ((EntryFlags *)&entry->flags)->requested = 1;
                    *(s8 *)outNewRequest = !requested;
                }
                if ((s32 *)outSize != 0) *(s32 *)outSize = entry->size;
                if ((s8 *)outFirstUse != 0) *(s8 *)outFirstUse = entry->useCount == 0;
                count = entry->useCount;
                entry->useCount = count + 1;
                if (count == 0) {
                    /* (Re)stamp the block header of a freshly loaded entry. */
                    *(u32 *)(entry->header + 4) = 0x4D474921; /* 'MGI!' */
                    *(struct ResEntry **)entry->header = entry;
                }
                *(s32 *)outId = entry->id;
                result = entry->header + 8;
                ((void (*)(void *, const char *))fn_8012A46C)(result, strings + 0x408);
            } else {
                /* Both four-character type tags, byte-reversed into strings for the message. */
                u8 swap0;
                u8 swap1;
                *(u32 *)wantedTagText = dataTag;
                swap0 = wantedTagText[0];
                wantedTagText[0] = wantedTagText[3];
                wantedTagText[3] = swap0;
                swap1 = wantedTagText[1];
                wantedTagText[1] = wantedTagText[2];
                wantedTagText[2] = swap1;
                wantedTagText[4] = 0;
                *(u32 *)entryTagText = entry->dataTag;
                swap0 = entryTagText[0];
                entryTagText[0] = entryTagText[3];
                entryTagText[3] = swap0;
                swap1 = entryTagText[1];
                entryTagText[1] = entryTagText[2];
                entryTagText[2] = swap1;
                entryTagText[4] = 0;
                fn_802E30C8(strings + 0x414, path, (const char *)wantedTagText, (const char *)entryTagText);
            }
        } else {
            fn_802E30C8(strings + 0x450, path);
        }
    }
    return (s32)result;
}
#pragma dont_inline reset
#pragma scheduling reset
#pragma pop

extern "C" const char lbl_8032A630[];
extern "C" const char lbl_805599A4[1];
extern "C" s32 strstr(const char *, const char *);
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline off
static inline s32 res_entry_use_count(s32 a, s32 b, struct ResEntry *entry) { return entry->useCount; }
static inline u32 res_entry_flags(s32 a, s32 b, struct ResEntry *entry) { return entry->flags; }

extern "C" void fn_8012BA1C(void *resource) {
    /* Log usage warnings for a resource archive: entries with a positive use
     * count, and, for ".trk" archives other than the named exception, entries
     * whose flags report them as non-resident. */
    const char *messages = lbl_8032A630;
    s32 entryOffset, entryIndex;
    s32 secondIndex, secondOffset;
    u8 *entry;
    s32 useCount;

    entryIndex = 0;
    entryOffset = 0;
    while (entryIndex < *(s32 *)((char *)resource + 0x88)) {
        entry = *(u8 **)((char *)resource + 0x60) + entryOffset;
        useCount = *(s32 *)(entry + 0x38);
        if (useCount > 0) fn_802E30C8(messages + 0x470, resource, (const char *)entry, useCount);
        entryOffset += 0x44;
        entryIndex++;
    }
    if (strstr((const char *)resource, &lbl_805599A4[0]) != 0 &&
        stricmp((const char *)resource, messages + 0x4A0) != 0) {
        secondIndex = 0;
        secondOffset = 0;
        while (secondIndex < *(s32 *)((char *)resource + 0x88)) {
            entry = *(u8 **)((char *)resource + 0x60) + secondOffset;
            if ((*(u32 *)(entry + 0x34) & 0xA) == 8) fn_802E30C8(messages + 0x4AC, resource, (const char *)entry);
            secondOffset += 0x44;
            secondIndex++;
        }
    }
}
#pragma pop
extern "C" void fn_8012BC24(void **, void *);
extern "C" void releaseResource(void *);
extern "C" s32 fn_80128668(void *);
/* Always-true gate used by fn_8012BB20: it is called through a u32(void*) pointer
 * with a resource-set pointer, ignores that argument, and never vetoes cleanup. */
extern "C" u32 fn_8012BB18(void) { return 1; }

#pragma scheduling invalid_target
/* Frees a resource-set node: reports issues, unlinks it, releases any still-allocated entry data, and frees the node. */
extern "C" void fn_8012BB20(s32 listHead, void *node) {
    u8 *entry;
    s32 i;
    s32 entryOffset;
    u32 flags;

    if (((u32 (*)(void *))fn_8012BB18)(node) == 0) return;
    fn_8012BA1C(node);
    fn_8012BC24((void **)listHead, node);
    if (node == 0) return;
    if (*(u8 *)((u8 *)node + 0xAC) != 0) {
        i = 0;
        entryOffset = 0;
        while (i < *(s32 *)((u8 *)node + 0x88)) {
            entry = *(u8 **)((u8 *)node + 0x60) + entryOffset;
            flags = *(u32 *)(entry + 0x34);
            if ((flags & 4) != 0) {
                Abend_Panic(lbl_8032AE20, entry);
            }
            i++;
            entry = *(u8 **)((u8 *)node + 0x60) + entryOffset;
            flags = *(u32 *)(entry + 0x34);
            entryOffset += 0x44;
            *(u32 *)(entry + 0x34) = flags & 0xFFFFFFF0;
        }
        if (*(s32 *)((u8 *)node + 0x64) != 0) {
            releaseResource(*(void **)((u8 *)node + 0x64));
        }
        if (*(s32 *)((u8 *)node + 0xA0) != 0) {
            fn_80128660(*(s32 *)((u8 *)node + 0xA0));
        }
        *(u8 *)((u8 *)node + 0xAC) = 0;
    }
    fn_80128668(node);
}
extern "C" void fn_8012BC24(void **headPtr, void *node) {
    // Unlink `node` from the singly-linked list whose head pointer is *headPtr;
    // consecutive nodes are chained through the pointer at offset 0xA8 of each node.
    void **link = headPtr;
    while (*link != 0) {
        if (*link == node) {
            *link = *(void **)((char *)node + 0xA8);
            return;
        }
        link = (void **)((char *)*link + 0xA8);
    }
}

extern "C" const char lbl_8032AAFC[];
#pragma scheduling reset
/* Decrement a control block's refcount and invoke a release callback/cleanup when it reaches zero. */
extern "C" s32 fn_8012BC50(void *ownerPtr, void *onRelease, s32 releaseArg) {
    struct Struct8012BC50 {
        u8 pad[0x34];
        u32 f0 : 28;
        u32 f1 : 2;
        u32 f2 : 1;
        u32 f3 : 1;
        s32 field_38;
        s32 field_3c;
        s32 field_40;
    };
    u8 *controlBlock = *(u8 **)((u8 *)ownerPtr - 8);
    if (controlBlock == NULL) {
        return 0;
    }
    if (*(s32 *)(controlBlock + 0x38) != 0) {
        *(s32 *)(controlBlock + 0x38) -= 1;
    } else {
        fn_802E30C8(lbl_8032AAFC, controlBlock);
    }
    if (*(s32 *)(controlBlock + 0x38) == 0) {
        if (onRelease != NULL) {
            ((void (*)(void *, s32))onRelease)(ownerPtr, releaseArg);
        }
        if (*(u32 *)(controlBlock + 0x34) & 4) {
            register Struct8012BC50 *releaseState = (Struct8012BC50 *)controlBlock;
            fn_80128660(releaseState->field_40);
            releaseState->f1 = 0;
            releaseState->field_40 = 0;
            releaseState->field_3c = 0;
            releaseState->f3 = 0;
        }
    }
    return *(s32 *)(controlBlock + 0x38) == 0;
}
/* Finds and returns the first entry in a linked list (next at offset 0xA8) whose name matches (case-insensitive), or NULL if not found. */
extern "C" void *fn_8012BD3C(void *listHead, const char *name) {
    void *entry = listHead;
    goto test;
body:
    if (stricmp(name, (const char *)entry) == 0) goto done;
    entry = *(void **)((char *)entry + 0xA8);
test:
    if (entry != 0) goto body;
done:
    return entry;
}

extern "C" void *fn_8012B32C(const char *);
extern "C" void fn_8012748C(s32);
extern "C" const char lbl_8032AB2C[];
extern "C" const char lbl_8032AB58[];
#pragma scheduling invalid_target
extern "C" void *fn_8012BD98(const char *arg0, void **arg1, s32 arg2) {
    void *p;
    s32 tries;
    p = fn_8012BD3C(*arg1, arg0);
    if (p == 0) {
        tries = 0;
        do {
            lbl_8055DFF9 = 0;
            p = fn_8012B32C(arg0);
            if (p != 0) {
                *(void **)((char *)p + 0xA8) = *arg1;
                *arg1 = p;
            } else if (lbl_8055DFF9 != 0) {
                fn_802E30C8(lbl_8032AB2C, arg0);
                fn_80127464();
            }
            if (lbl_8055DFF9 != 0 && p == 0) ++tries;
            else break;
        } while (tries < 10);
        if (p == 0) {
            fn_802E30C8(lbl_8032AB58, arg0);
            fn_8012748C(2);
        }
    } else ++*(s32 *)((char *)p + 0x9C);
    return p;
}
extern "C" s32 fn_8012BE90(void) {
    /* Initialize the TOC library/resources subsystem and its async effect queue; returns success. */
    fn_8012A648();
    lbl_8055DFF8 = 1;
    void *allocatedObject = fn_801284F8(1, &lbl_805599B8);
    if (allocatedObject)
        fn_8012BEF0((s32)lbl_8032AE9C);
    lbl_8055DFFC = (s32)allocatedObject;
    fn_8012DBD0();
    return 1;
}
#pragma scheduling on

#pragma use_lmw_stmw reset
#pragma dont_inline reset
#pragma scheduling reset
extern "C" void fn_8012DDA8(s32);
extern "C" void fn_8012E81C(s32);
/* Queue the named resource for loading, then wait until it has finished. */
extern "C" void fn_8012BEF0(s32 resName) {
    fn_8012DDA8(resName);
    fn_8012E81C(resName);
}

extern "C" void fn_8012E498(void *);
/* Thunk: forwards a resource name to fn_8012E498, which releases the named
 * resource (decrementing its refcount and unlinking it from the effect lists). */
extern "C" void fn_8012BF24(void *resName) {
    fn_8012E498(resName);
}

extern "C" s32 FileFindFirst(s32, char *, s32);
extern "C" void fn_802E3A14(s32, s32);
extern "C" s32 fn_802E3804(s32, void *, s32);
extern "C" s32 fn_802E3C24(s32, char *, s32);
extern "C" void FileFind_Close(s32);
extern "C" void releaseResource(void *);
extern "C" s32 lbl_802F8E50[3];
extern "C" const char lbl_8032AF4C[];
extern "C" const char lbl_8032AF0C[];
extern "C" const char lbl_8032AEF4[];
extern "C" const char lbl_8032AED4[];
extern "C" const char lbl_8032AEB4[];
extern "C" u8 lbl_805599D8;
#pragma push
#pragma scheduling on
extern "C" void fn_8012BF28(void) {
    s32 paths[3], header[5], inner, size;
    s32 *table;
    register s32 handle;
    register s32 *pathPtr;
    u32 i;
    char filename[128], name[128];
    char *src_a1;
    s32 rem_s1;
    char *dst_s1;
    char *src_c;
    s32 rem_c;
    char *dst_c;
    char *src_a2;
    s32 rem_s2;
    char *dst_s2;
    u8 ch1, ch2;
    u8 ok;
    u8 *data;
    if (lbl_8055DFFC == 0) return;
    table = lbl_802F8E50;
    paths[0] = *table++; paths[1] = *table++; paths[2] = *table;
    pathPtr = paths; i = 0;
    do {
        s32 opened = FileFindFirst(*pathPtr, filename, 0x80);
        if ((u32)(opened + 0x10000) != 0xFFFF) {
            handle = opened;
            do {
                *fn_80029004(filename, '.') = 0;
                dst_s1 = filename; rem_s1 = 0x80; goto scan_test_1;
scan_step_1:
                --rem_s1; ++dst_s1;
scan_test_1:
                if ((s8)*dst_s1 != 0) goto scan_step_1;
                if (rem_s1 <= 0) goto suffix_done_1;
                src_a1 = (char *)&lbl_805599D8; goto append_1;
limit_1:
                --rem_s1; if (rem_s1 > 0) goto append_1; dst_s1[-1] = 0; goto suffix_done_1;
append_1:
                ch1 = *src_a1++; *dst_s1++ = ch1; if ((s8)ch1 != 0) goto limit_1;
suffix_done_1:
                inner = ((s32 (*)(char *))FileLookup)(filename);
                if (inner != -1) {
                    fn_802E3A14(inner, 0x14); fn_802E3804(inner, header, 0x14);
                    if (header[0] == 0) {
                        src_c = filename; dst_c = name; rem_c = 0x80; goto copy_name_body;
copy_name_limit:
                        --rem_c; if (rem_c > 0) goto copy_name_body; dst_c[-1] = 0; goto copy_name_done;
copy_name_body:
                        ch2 = *src_c++; *dst_c++ = ch2; if ((s8)ch2 != 0) goto copy_name_limit;
copy_name_done:
                        ;
                        if ((s8)*fn_80029004(name, '.') != 0) *fn_80029004(name, '.') = 0;
                        dst_s2 = name; rem_s2 = 0x80; goto scan_test_2;
scan_step_2:
                        --rem_s2; ++dst_s2;
scan_test_2:
                        if ((s8)*dst_s2 != 0) goto scan_step_2;
                        if (rem_s2 <= 0) goto suffix_done_2;
                        src_a2 = (char *)&lbl_805599E0; goto append_2;
limit_2:
                        --rem_s2; if (rem_s2 > 0) goto append_2; dst_s2[-1] = 0; goto suffix_done_2;
append_2:
                        ch1 = *src_a2++; *dst_s2++ = ch1; if ((s8)ch1 != 0) goto limit_2;
suffix_done_2:
                        fn_8002B0D8(name);
                        data = (u8 *)getResourceData((s32)name, 0x45544F43, (s32)&size, 0, 0, (s32)&ok);
                        if (data != 0 && ok != 0) {
                            u8 t; u32 n; u8 *entry;
                            t=data[0]; data[0]=data[3]; data[3]=t; t=data[1]; data[1]=data[2]; data[2]=t;
                            t=data[4]; data[4]=data[7]; data[7]=t; t=data[5]; data[5]=data[6]; data[6]=t;
                            t=data[8]; data[8]=data[0xB]; data[0xB]=t; t=data[9]; data[9]=data[0xA]; data[0xA]=t;
                            t=data[0xC]; data[0xC]=data[0xF]; data[0xF]=t; t=data[0xD]; data[0xD]=data[0xE]; data[0xE]=t;
                            t=data[0x10]; data[0x10]=data[0x13]; data[0x13]=t; t=data[0x11]; data[0x11]=data[0x12]; data[0x12]=t;
                            u32 magic = *(u32 *)data; if (magic != 0 || *(u32 *)(data+4) != 0x14)
                                Abend_Panic(lbl_8032AE60, magic, 0, *(u32 *)(data+4), 0x14);
                            entry = data+0x14; n=0; while (n < *(u32 *)(data+0xC)) { fn_8012A388(entry); entry += 0x44; ++n; }
                        }
                        if (data != 0) {
                            if ((u32)header[2] != *(u32 *)(data+8)) {
                                if ((u32)header[3] == *(u32 *)(data+0xC)) {
                                    fn_802E30C8(lbl_8032AF4C, filename);
                                    *(u32 *)(data+8)=header[2]; *(u32 *)(data+0x10)=header[4];
                                    fn_802E3804(inner, data+0x14, header[3]*0x44);
                                } else fn_802E30C8(lbl_8032AF0C, filename);
                            }
                            releaseResource(data);
                        } else fn_802E30C8(lbl_8032AEF4, filename);
                    } else {
                        fn_802E30C8(lbl_8032AED4, filename); closeFileHandle(&inner); goto read_rest;
                    }
                } else fn_802E30C8(lbl_8032AEB4, filename);
read_rest:
                ;
            } while (fn_802E3C24(handle, filename, 0x80) != 0);
            FileFind_Close(handle);
        }
        ++pathPtr; ++i;
    } while (i < 3);
}
#pragma pop
/* Return nonzero if the given resource path resolves to a registered entry;
   the index of the found entry is written to a throwaway local and ignored. */
extern "C" s32 fn_8012C33C(char *path) {
    s32 index;
    return findResourceEntry(path, &index, 0) != 0;
}

#pragma use_lmw_stmw off
/* ResourceGet: the public resource lookup, a retrying wrapper around the
 * entry lookup of ResourceGetEntry.  Every attempt clears the load-retry flag
 * (raised by fn_8012A7FC when a read of the archive had to wait), asks for
 * `path`'s data carrying the type tag `dataTag` (a fourcc such as 'ETOC') and
 * stops as soon as no read error happened or the data is in hand; a failed
 * read is logged and the background-task pump (fn_80127464) is run so the
 * pending load can finish - up to 10 attempts.  The last lookup result is
 * returned: the entry's data, or 0.  The four arguments after dataTag are the
 * out pointers ResourceGetEntry fills: entry id, data size, first reference and
 * newly-requested flag. */
extern "C" s32 getResourceData(s32 path, s32 dataTag, s32 outId, s32 outSize, s32 outFirstUse, s32 outNewRequest) {
#define sLoadRetryFlag   lbl_8055DFF9
#define ResourceGetInner ResourceGetEntry
#define badReadMsg       lbl_8032AB78 /* "ResourceGet(%s): BAD READ, retrying" */
#define pumpTasks        fn_80127464
    s32 result;
    s32 attempt;
    for (attempt = 0; attempt < 10; attempt++) {
        sLoadRetryFlag = 0;
        result = ResourceGetInner(path, dataTag, outId, outSize, outFirstUse, outNewRequest);
        if (sLoadRetryFlag == 0 || result != 0)
            break;
        fn_802E30C8(badReadMsg, path);
        pumpTasks();
    }
    return result;
#undef sLoadRetryFlag
#undef ResourceGetInner
#undef badReadMsg
#undef pumpTasks
}
#pragma push
#pragma use_lmw_stmw off
/* Walks the global resource-manager list (lbl_8055E000) and calls
 * callback(entry, entry->data, manager, userData) for every loaded entry
 * (RES_ENTRY_LOADED) of every manager whose directory matches dirName --
 * every manager when dirName is NULL. Stops at the first callback returning 0. */
extern "C" void fn_8012C41C(s32 (*callback)(void *, void *, void *, s32), s32 userData, const char *dirName) {
    s32 off;
    struct ResManager *manager;
    s32 i;
    for (manager = (struct ResManager *)lbl_8055E000; manager != NULL; manager = manager->next) {
        if (dirName == 0 || stricmp((const char *)manager, dirName) == 0) {
            i = 0;
            off = 0;
            while (i < manager->entryCount) {
                struct ResEntry *entry = (struct ResEntry *)(manager->entries + off);
                if (entry->flags & RES_ENTRY_LOADED) {
                    volatile void *param = (void *)entry->dataTag;
                    if (callback(entry, (void *)param, manager, userData) == 0) return;
                }
                off += 0x44;
                i++;
            }
        }
    }
}
#pragma pop
// Drop one reference to a loaded resource object; no callback when it is freed.
extern "C" void releaseResource(void *resource) {
    fn_8012BC50(resource, 0, 0);
}

/* Tail-call thunk: jump straight to the resource-set load request handler fn_8012CC24,
   leaving its incoming r3/r4 arguments (a request and a name) in place. */
extern "C" void fn_8012CC20(void) {
    ((s32 (*)(void))(void *)&fn_8012CC24)();
}

#pragma dont_inline on
extern "C" s32 fn_8012CC24(void *arg0, void *arg1) {
    u8 *self = (u8 *)arg0;
    s32 sum, count, value, result, temp, handle, size, done;
    s32 *record;
    u8 *destination, *source, byte;
    void *parser;
    u8 parseBuffer[0x40];

    if (*(s32 *)(self + 0xB8) == 2 && fn_802E7544(*(s32 *)(self + 0xB4)) != 0 &&
        ((u32 (*)(void *))fn_8012D3D0)(arg0) != 0) {
        closeStreamHandle(*(s32 *)(self + 0xB4));
        *(s32 *)(self + 0xB4) = -1;
        fn_8012D33C((u32 *)(self + 0x6C), (u32 *)*(void **)(self + 0xC8));
        fn_8012A80C((s32)(self + 0x6C));
        sum = *(s32 *)(self + 0x90) + *(s32 *)(self + 0x84);
        *(s32 *)(self + 0xA4) = 0;
        if (sum > *(s32 *)(self + 0xCC))
            Abend_Panic(lbl_8032ADF4);
        if (*(s32 *)(self + 0x78) & 1) {
            *(s32 *)(self + 0x64) = 0;
            result = ((s32 (*)(void *, void *, s32, s32))fn_8012ACA0)(
                self + 4, (u8 *)*(void **)(self + 0xC8) + *(s32 *)(self + 0x84),
                *(s32 *)(self + 0xC0) - *(s32 *)(self + 0x84), *(s32 *)(self + 0x84));
        } else {
            *(s32 *)(self + 0x64) = (s32)((u8 *)*(void **)(self + 0xC8) + *(s32 *)(self + 0x84));
            result = fn_8012AA60(self + 4, *(s32 *)(self + 0xC0) - *(s32 *)(self + 0x84),
                                 *(s32 *)(self + 0x84));
        }
        if (result != 0) {
            ((void (*)(void *))fn_8012B328)(self + 4);
            *(s32 *)(self + 0xAC) = (s32)lbl_8055E000;
            lbl_8055E000 = self + 4;
            *(s32 *)(self + 0xB8) = 3;
        } else {
            fn_8012D1A8((s32)arg0);
            ((void (*)(void *))fn_8012B324)(self + 0x24);
            value = *(s32 *)(self + 0xBC);
            *(s32 *)(self + 0xBC) = value + 1;
            loadResourceFromNameList(arg0, (s32)(self + 4), value);
        }
    }
    switch (*(s32 *)(self + 0xB8)) {
    case 2:
    {
        s32 index;

        if (*(s32 *)(self + 0xB4) != -1) {
            closeStreamHandle(*(s32 *)(self + 0xB4));
            *(s32 *)(self + 0xB4) = -1;
        }
        count = 0;
        index = 0;
        goto record_check_two;
    record_body_two:
        record = (s32 *)(*(s32 *)(self + 0x64) + index);
        if (record[0x34 / 4] & 4)
            Abend_Panic(lbl_8032AE20);
        count++;
        record = (s32 *)(*(s32 *)(self + 0x64) + index);
        index += 0x44;
        record[0x34 / 4] &= ~0xF;
    record_check_two:
        if (count < *(s32 *)(self + 0x8C))
            goto record_body_two;
        if (*(s32 *)(self + 0x68) != 0)
            releaseResource((void *)*(s32 *)(self + 0x68));
        if (*(s32 *)(self + 0xA4) != 0)
            fn_80128660(*(s32 *)(self + 0xA4));
        *(u8 *)(self + 0xB0) = 0;
        break;
    }
    case 3:
    {
        s32 index;

        fn_8012BA1C(self + 4);
        fn_8012BC24((void **)&lbl_8055E000, self + 4);
        count = 0;
        index = 0;
        goto record_check_three;
    record_body_three:
        record = (s32 *)(*(s32 *)(self + 0x64) + index);
        if (record[0x34 / 4] & 4)
            Abend_Panic(lbl_8032AE20);
        count++;
        record = (s32 *)(*(s32 *)(self + 0x64) + index);
        index += 0x44;
        record[0x34 / 4] &= ~0xF;
    record_check_three:
        if (count < *(s32 *)(self + 0x8C))
            goto record_body_three;
        if (*(s32 *)(self + 0x68) != 0)
            releaseResource((void *)*(s32 *)(self + 0x68));
        if (*(s32 *)(self + 0xA4) != 0)
            fn_80128660(*(s32 *)(self + 0xA4));
        *(u8 *)(self + 0xB0) = 0;
        break;
    }
    default:
        break;
    }
    *(s32 *)(self + 0xB8) = 1;
    *(s32 *)(self + 0xBC) = 0;
    done = 0;
    do {
        parser = ((void *(*)(void *, void *, s32))fn_8012B314)(arg1, parseBuffer,
                                                               *(s32 *)(self + 0xBC));
        if (!parser)
            goto func_exit;
        done = 0;
        temp = ((s32 (*)(void *, s32 *))fn_8012AC28)(parser, &size);
        if (temp != -1) {
            value = *(s32 *)(self + 0xCC);
            *(s32 *)(self + 0xC0) = value;
            if (value > *(s32 *)(self + 0xC0))
                goto parse_next;
            handle = ((s32 (*)(s32, void *, s32))fn_802E748C)(temp, *(void **)(self + 0xC8), value);
            *(s32 *)(self + 0xB4) = handle;
            if (handle != -1) {
                *(s32 *)(self + 0xB8) = 2;
                source = (u8 *)arg1;
                destination = self + 4;
                {
                    s32 limit = 32;
                    goto copy_name_body;
                copy_name_limit:
                    limit--;
                    if (limit > 0)
                        goto copy_name_body;
                    destination[-1] = 0;
                    goto copy_name_done;
                copy_name_body:
                    byte = *source++;
                    *destination++ = byte;
                    if ((s8)byte != 0)
                        goto copy_name_limit;
                }
            copy_name_done:
                source = (u8 *)parser;
                destination = self + 0x24;
                {
                    s32 limit = 64;
                    goto copy_path_body;
                copy_path_limit:
                    limit--;
                    if (limit > 0)
                        goto copy_path_body;
                    destination[-1] = 0;
                    goto copy_path_done;
                copy_path_body:
                    byte = *source++;
                    *destination++ = byte;
                    if ((s8)byte != 0)
                        goto copy_path_limit;
                }
            copy_path_done:
                *(s32 *)(self + 0xAC) = 0;
                *(s32 *)(self + 0x64) = 0;
                memset(self + 0x6C, 0, 0x34);
                *(s32 *)(self + 0xA0) = 1;
                done = 1;
                *(s32 *)(self + 0xA4) = 0;
                *(s32 *)(self + 0xA8) = temp;
                *(u8 *)(self + 0xB0) = 1;
                *(s32 *)(self + 0x68) = 0;
                *(u8 *)(self + 0xB1) = 0;
                *(s32 *)self = KERNEL_GetTimeMs() + *(s32 *)(self + 0xC0) / 3000 + 0x1F4;
            }
        }
    parse_next:
        *(s32 *)(self + 0xBC) = *(s32 *)(self + 0xBC) + 1;
    } while (!done);
func_exit:
    return done;
}

/* Resource request fields used by loadResourceFromNameList (offsets into the request). */
#define LOAD_REQ_NAME_INDEX 0xBC
#define LOAD_REQ_STATUS 0xB8
#define LOAD_REQ_HANDLE 0xB4
#define LOAD_REQ_LOADED_VALUE 0xC0
#define LOAD_REQ_DIRECTORY 0xC8
#define LOAD_REQ_TIMESTAMP 0xCC
#define LOAD_REQ_NAME 0x4
#define LOAD_REQ_PATH 0x24

extern "C" s32 loadResourceFromNameList(void *request, s32 nameList, s32 arg2) {
    /* Walk the candidate-name list until one name resolves to a stream, then open it
     * and fill in the resource request (name, path, handle, status, expiry).  Returns
     * 1 once a stream has been opened and 0 if the list is exhausted; arg2 is unused. */
    s32 loaded = 0;
    s32 startSector;
    u8 *req = (u8 *)request;
    u8 ch;
    u8 *src;
    s32 remaining;
    u8 *dst;
    u8 ch2;
    s32 pathRemaining;
    u8 *pathDst;
    u8 parseBuffer[0x40];
    s32 size;
    u8 *parser;
    do {
        parser = ((u8 *(*)(void *, void *, s32))fn_8012B314)((void *)nameList, parseBuffer,
                                                              *(s32 *)(req + LOAD_REQ_NAME_INDEX));
        if (!parser)
            goto func_exit;
        loaded = 0;
        startSector = ((s32 (*)(void *, s32 *))fn_8012AC28)(parser, &size);
        if (startSector != -1) {
            s32 timestamp = *(s32 *)(req + LOAD_REQ_TIMESTAMP);
            *(s32 *)(req + LOAD_REQ_LOADED_VALUE) = timestamp;
            if (timestamp > *(s32 *)(req + LOAD_REQ_LOADED_VALUE))
                goto parse_next;
            s32 handle = ((s32 (*)(s32, void *, s32))fn_802E748C)(startSector, *(void **)(req + LOAD_REQ_DIRECTORY), timestamp);
            *(s32 *)(req + LOAD_REQ_HANDLE) = handle;
            if (handle != -1) {
                *(s32 *)(req + LOAD_REQ_STATUS) = 2;
                src = (u8 *)nameList;
                dst = req + LOAD_REQ_NAME;
                remaining = 32;
                goto copy_name_body;
            copy_name_limit:
                remaining--;
                if (remaining > 0)
                    goto copy_name_body;
                dst[-1] = 0;
                goto copy_name_done;
            copy_name_body:
                ch = *src++;
                *dst++ = ch;
                if ((s8)ch != 0)
                    goto copy_name_limit;
            copy_name_done:
                src = (u8 *)parser;
                pathDst = req + LOAD_REQ_PATH;
                pathRemaining = 64;
                goto copy_path_body;
            copy_path_limit:
                pathRemaining--;
                if (pathRemaining > 0)
                    goto copy_path_body;
                pathDst[-1] = 0;
                goto copy_path_done;
            copy_path_body:
                ch2 = *src++;
                *pathDst++ = ch2;
                if ((s8)ch2 != 0)
                    goto copy_path_limit;
            copy_path_done:
                *(s32 *)(req + 0xAC) = 0;
                *(s32 *)(req + 0x64) = 0;
                memset(req + 0x6C, 0, 0x34);
                *(s32 *)(req + 0xA0) = 1;
                loaded = 1;
                *(s32 *)(req + 0xA4) = 0;
                *(s32 *)(req + 0xA8) = startSector;
                *(u8 *)(req + 0xB0) = 1;
                *(s32 *)(req + 0x68) = 0;
                *(u8 *)(req + 0xB1) = 0;
                s32 now = KERNEL_GetTimeMs();
                *(s32 *)req = now + *(s32 *)(req + LOAD_REQ_LOADED_VALUE) / 3000 + 0x1F4;
            }
        }
    parse_next:
        *(s32 *)(req + LOAD_REQ_NAME_INDEX) = *(s32 *)(req + LOAD_REQ_NAME_INDEX) + 1;
    } while (!loaded);
func_exit:
    return loaded;
}

extern "C" s32 fn_802E748C(s32 arg0, s32 arg1, void *arg2);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012D024_old(void *arg0, s32 arg1, s32 arg2) {
    u8 sp80[0x80];
    void *parser;
    u8 sp8[8];
    u8 *path;
    s32 timestamp;
    s32 value;
    s32 result;
    u8 *source;
    u8 *destination;
    s32 limit;
    u8 byte;

    // Call fn_8012B314 to get parser
    parser = fn_8012B314(arg1, (s32)sp80, *(s32 *)((u8 *)arg0 + 0xBC));

    if (parser == NULL) {
        return;
    }

    // Call fn_8012AC28 to parse the record
    fn_8012AC28((s32)parser, (s32)sp8);
    result = *(s32 *)sp8;
    if (result == -1) {
        return;
    }

    // Load and store timestamp value
    value = *(s32 *)((u8 *)arg0 + 0xCC);
    *(s32 *)((u8 *)arg0 + 0xC0) = value;

    // Load handle from fn_802E748C
    result = fn_802E748C(result, *(s32 *)((u8 *)arg0 + 0xC8), NULL);
    *(s32 *)((u8 *)arg0 + 0xB4) = result;

    if (result != -1) {
        // Copy name from arg1 (pointer) to arg0+4
        source = (u8 *)arg1;
        destination = (u8 *)arg0 + 4;
        limit = 32;
        do {
            limit--;
            if (limit > 0) {
                byte = *source++;
                *destination++ = byte;
                if ((s8)byte == 0) {
                    break;
                }
            } else {
                destination[-1] = 0;
                break;
            }
        } while (1);

        // Copy path from parser to arg0+0x24
        path = (u8 *)parser;
        destination = (u8 *)arg0 + 0x24;
        limit = 64;
        do {
            limit--;
            if (limit > 0) {
                byte = *path++;
                *destination++ = byte;
                if ((s8)byte == 0) {
                    break;
                }
            } else {
                destination[-1] = 0;
                break;
            }
        } while (1);

        // Clear memory with memset
        memset((u8 *)arg0 + 0x6C, 0, 0x34);

        // Calculate timestamp
        timestamp = KERNEL_GetTimeMs();
        // timestamp += (0x57619f1 * value) >> 38 + sign correction
        s32 scaled = ((s64)0x57619f1 * (s64)value) >> 38;
        if (scaled < 0) {
            scaled++;
        }
        timestamp += (s32)scaled;
        timestamp += 0x1F4;

        *(s32 *)((u8 *)arg0 + 0) = timestamp;

        // Set some flags
        *(s32 *)((u8 *)arg0 + 0xBC) = *(s32 *)((u8 *)arg0 + 0xBC) + 1;
        *(s32 *)((u8 *)arg0 + 0xA0) = 1;
        *(s32 *)((u8 *)arg0 + 0xA4) = 0;
        *(s32 *)((u8 *)arg0 + 0xA8) = result;
        *(u8 *)((u8 *)arg0 + 0xB0) = 1;
        *(s32 *)((u8 *)arg0 + 0x68) = 0;
        *(u8 *)((u8 *)arg0 + 0xB1) = 0;
    }
}

#pragma use_lmw_stmw off
extern "C" void fn_8012D1A8(s32 arg0) {
    u8 *self = (u8 *)arg0;
    s32 off;
    s32 i;
    switch (*(s32 *)(self + 0xB8)) {
    case 2:
        if (*(s32 *)(self + 0xB4) != -1) {
            closeStreamHandle(*(s32 *)(self + 0xB4));
            *(s32 *)(self + 0xB4) = -1;
        }
        for (i = 0, off = 0; i < *(s32 *)(self + 0x8C); i++, off += 0x44) {
            u32 *r = (u32 *)(*(s32 *)(self + 0x64) + off);
            if (r[0x34 / 4] & 4) {
                Abend_Panic(lbl_8032AE20, r);
            }
            r = (u32 *)(*(s32 *)(self + 0x64) + off);
            r[0x34 / 4] &= ~0xF;
        }
        if (*(s32 *)(self + 0x68) != 0) {
            releaseResource((void *)*(s32 *)(self + 0x68));
        }
        if (*(s32 *)(self + 0xA4) != 0) {
            fn_80128660(*(s32 *)(self + 0xA4));
        }
        *(u8 *)(self + 0xB0) = 0;
        break;
    case 3:
        fn_8012BA1C(self + 4);
        fn_8012BC24((void **)&lbl_8055E000, self + 4);
        for (i = 0, off = 0; i < *(s32 *)(self + 0x8C); i++, off += 0x44) {
            u32 *r = (u32 *)(*(s32 *)(self + 0x64) + off);
            if (r[0x34 / 4] & 4) {
                Abend_Panic(lbl_8032AE20, r);
            }
            r = (u32 *)(*(s32 *)(self + 0x64) + off);
            r[0x34 / 4] &= ~0xF;
        }
        if (*(s32 *)(self + 0x68) != 0) {
            releaseResource((void *)*(s32 *)(self + 0x68));
        }
        if (*(s32 *)(self + 0xA4) != 0) {
            fn_80128660(*(s32 *)(self + 0xA4));
        }
        *(u8 *)(self + 0xB0) = 0;
        *(s32 *)(self + 0xB8) = 1;
        break;
    }
}
extern "C" void fn_8012D33C(u32 *arg0, u32 *arg1) {
    u32 v4 = arg1[4];
    u32 v3 = arg1[3];
    u32 v2 = arg1[2];
    u32 v1 = arg1[1];
    u32 v0 = arg1[0];
    u32 v5 = arg1[5];
    u32 v6 = arg1[6];
    u32 v7 = arg1[7];
    u32 v8 = arg1[8];
    u32 v9 = arg1[9];
    u32 v10 = arg1[10];
    u32 v11 = arg1[11];
    u32 v12 = arg1[12];
    arg0[0] = v0;
    arg0[1] = v1;
    arg0[2] = v2;
    arg0[3] = v3;
    arg0[4] = v4;
    arg0[5] = v5;
    arg0[6] = v6;
    arg0[7] = v7;
    arg0[8] = v8;
    arg0[9] = v9;
    arg0[10] = v10;
    arg0[11] = v11;
    arg0[12] = v12;
}
/* Readiness hook for a resource-set load request.  fn_8012CC24 tests it once the
   request is in state 2 (LOAD_REQ_STATUS) and its stream handle (LOAD_REQ_HANDLE)
   reports data, before closing the stream and consuming the 13-word block header
   and entry table.  It ignores the request and always reports ready, so the
   shipped game never blocks at that gate. */
extern "C" u32 fn_8012D3D0(void) { return 1; }

extern "C" void fn_8012D40C(s32);
extern "C" void fn_8012D1A8(s32 arg0);
extern "C" void fn_8012D3D8(s32 object) {
    /* Advance the object: process pending data, then clean up finished state. */
    fn_8012D40C(object);
    fn_8012D1A8(object);
}

#pragma scheduling on
extern "C" void fn_8012D40C(s32 arg0) {
    u8 *self = (u8 *)arg0;
    s32 *object = (s32 *)self;
    s32 state, value, result, index, count, limit, done;
    s32 temp, handle, size;
    s32 *record;
    u8 *data, *source, *destination, byte;
    u8 *parser;
    u8 parseBuffer[0x40];
    state = object[0xB8 / 4];
    if (state == 2 && fn_802E7544(object[0xB4 / 4]) != 0) {
        closeStreamHandle(object[0xB4 / 4]);
        object[0xB4 / 4] = -1;
        data = *(u8 **)(self + 0xC8);
        *(s32 *)(self + 0x6C) = *(s32 *)(data + 0);
        *(s32 *)(self + 0x70) = *(s32 *)(data + 4);
        *(s32 *)(self + 0x74) = *(s32 *)(data + 8);
        *(s32 *)(self + 0x78) = *(s32 *)(data + 12);
        *(s32 *)(self + 0x7C) = *(s32 *)(data + 16);
        *(s32 *)(self + 0x80) = *(s32 *)(data + 20);
        *(s32 *)(self + 0x84) = *(s32 *)(data + 24);
        *(s32 *)(self + 0x88) = *(s32 *)(data + 28);
        *(s32 *)(self + 0x8C) = *(s32 *)(data + 32);
        *(s32 *)(self + 0x90) = *(s32 *)(data + 36);
        *(s32 *)(self + 0x94) = *(s32 *)(data + 40);
        *(s32 *)(self + 0x98) = *(s32 *)(data + 44);
        *(s32 *)(self + 0x9C) = *(s32 *)(data + 48);
        fn_8012A80C((s32)(self + 0x6C));
        {
            s32 sum = object[0x90 / 4] + object[0x84 / 4];
            object[0xA4 / 4] = 0;
            if (sum > object[0xCC / 4])
                Abend_Panic(lbl_8032ADF4);
        }
        if (object[0x78 / 4] & 1) {
            s32 off = object[0x84 / 4];
            u8 *base = *(u8 **)(self + 0xC8);
            s32 avail = object[0xC0 / 4] - off;
            u8 *ptr = base + off;
            object[0x64 / 4] = 0;
            result = fn_8012ACA0(self + 4, ptr, avail);
        } else {
            s32 off = object[0x84 / 4];
            u8 *base = *(u8 **)(self + 0xC8);
            s32 avail = object[0xC0 / 4] - off;
            object[0x64 / 4] = (s32)(base + off);
            result = fn_8012AA60(self + 4, avail, off);
        }
        if (result != 0) {
            ((void (*)(void *))fn_8012B328)(self + 4);
            object[0xAC / 4] = (s32)lbl_8055E000;
            lbl_8055E000 = self + 4;
            object[0xB8 / 4] = 3;
            return;
        }
    }
    state = object[0xB8 / 4];
    switch (state) {
    case 2:
        if (object[0xB4 / 4] != -1) {
            closeStreamHandle(object[0xB4 / 4]);
            object[0xB4 / 4] = -1;
        }
        count = 0;
        index = 0;
        goto record_check_two;
    record_body_two:
        record = (s32 *)(object[0x64 / 4] + index);
        if (record[0x34 / 4] & 4)
            Abend_Panic(lbl_8032AE20);
        count++;
        record = (s32 *)(object[0x64 / 4] + index);
        value = record[0x34 / 4];
        index += 0x44;
        record[0x34 / 4] = value & ~0xF;
    record_check_two:
        if (count < object[0x8C / 4])
            goto record_body_two;
        if (object[0x68 / 4] != 0)
            releaseResource((void *)object[0x68 / 4]);
        if (object[0xA4 / 4] != 0)
            fn_80128660(object[0xA4 / 4]);
        *(u8 *)(self + 0xB0) = 0;
        break;
    case 3:
        fn_8012BA1C(self + 4);
        fn_8012BC24((void **)&lbl_8055E000, self + 4);
        count = 0;
        index = 0;
        goto record_check_three;
    record_body_three:
        record = (s32 *)(object[0x64 / 4] + index);
        if (record[0x34 / 4] & 4)
            Abend_Panic(lbl_8032AE20);
        count++;
        record = (s32 *)(object[0x64 / 4] + index);
        value = record[0x34 / 4];
        index += 0x44;
        record[0x34 / 4] = value & ~0xF;
    record_check_three:
        if (count < object[0x8C / 4])
            goto record_body_three;
        if (object[0x68 / 4] != 0)
            releaseResource((void *)object[0x68 / 4]);
        if (object[0xA4 / 4] != 0)
            fn_80128660(object[0xA4 / 4]);
        *(u8 *)(self + 0xB0) = 0;
        break;
    }
    object[0xB8 / 4] = 1;
    ((void (*)(void *))fn_8012B324)(self + 0x24);
    object[0xBC / 4]++;
    do {
        parser = ((u8 *(*)(void *, void *, s32))fn_8012B314)(self + 4, parseBuffer, object[0xBC / 4]);
        if (!parser)
            return;
        done = 0;
        temp = ((s32 (*)(void *, s32 *))fn_8012AC28)(parser, &size);
        if (temp != -1) {
            value = object[0xCC / 4];
            object[0xC0 / 4] = value;
            if (value > object[0xC0 / 4])
                goto parse_next;
            handle = ((s32 (*)(s32, void *))fn_802E748C)(temp, *(void **)(self + 0xC8));
            object[0xB4 / 4] = handle;
            if (handle != -1) {
                source = self + 4;
                destination = source;
                object[0xB8 / 4] = 2;
                limit = 32;
                goto copy_name_body;
            copy_name_limit:
                limit--;
                if (limit > 0)
                    goto copy_name_body;
                destination[-1] = 0;
                goto copy_name_done;
            copy_name_body:
                byte = *source++;
                *destination++ = byte;
                if ((s8)byte != 0)
                    goto copy_name_limit;
            copy_name_done:
                source = parser;
                destination = self + 0x24;
                limit = 64;
                goto copy_path_body;
            copy_path_limit:
                limit--;
                if (limit > 0)
                    goto copy_path_body;
                destination[-1] = 0;
                goto copy_path_done;
            copy_path_body:
                byte = *source++;
                *destination++ = byte;
                if ((s8)byte != 0)
                    goto copy_path_limit;
            copy_path_done:
                object[0xAC / 4] = 0;
                object[0x64 / 4] = 0;
                memset(self + 0x6C, 0, 0x34);
                object[0xA0 / 4] = 1;
                done = 1;
                object[0xA4 / 4] = 0;
                object[0xA8 / 4] = temp;
                *(u8 *)(self + 0xB0) = 1;
                object[0x68 / 4] = 0;
                *(u8 *)(self + 0xB1) = 0;
                object[0] = KERNEL_GetTimeMs() + object[0xC0 / 4] / 3000 + 0x1F4;
            }
        }
    parse_next:
        object[0xBC / 4]++;
    } while (!done);
}
extern "C" s32 fn_8012D838(s32 obj) {
    /* Refresh state if needed, then map the object's state (+0xB8) to a simple status code. */
    s32 state;
    fn_8012D40C(obj);
    state = *(s32 *)((u8 *)obj + 0xB8);
    switch (state) {
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    default:
        return 0;
    }
}

/* Destroys the resource/object handle: refreshes and tears down its state, frees its data buffer, clears state, resets parser linkage, and releases the handle. */
extern "C" void fn_8012D8A8(s32 arg0) {
    if (arg0 != 0) {
        fn_8012D40C(arg0);
        fn_8012D1A8(arg0);
        fn_80128660(*(s32 *)((char *)arg0 + 0xC8));
        *(s32 *)((char *)arg0 + 0xB8) = 0;
        fn_8012CB44((void *)(arg0 + 4), -1);
        fn_8012CA40((void *)arg0);
    }
}

// --- res: mounted resource sets and their on-disc "ETOC" tables -------------
//
// lbl_8055E014 is the external-TOC manager built by fn_8012DBD0 (0xA24 bytes):
// a pool of 0x20 mount nodes at +0x8 and the list of mounted sets at +0xA18.
// Every mounted set has a "<set>.toc" resource whose data is an ETOC block: a
// ResTocHeader followed by entryCount ResTocEntry records (fn_8012A388 knows an
// entry's fields).  The block is written little-endian, so its words are
// byte-reversed in place the first time it is read in.

#define RES_TOC_MANAGER ((ResTocManager *)lbl_8055E014)
#define RES_TOC_FOURCC 0x45544F43            // 'ETOC'
#define RES_TOC_HEADER_SIZE 0x14             // ResTocHeader must be this size
#define RES_TOC_ENTRY_SIZE 0x44              // one ETOC entry
#define RES_TOC_EXT_PATH ((char *)&lbl_805599E0)  // ".toc"

struct ResTocMount {  // one resource set whose load is in flight, 0x50 bytes
    void *poolNext;   // 0x00: next node of the pool list it is on, free or in use (fn_8012E460)
    ResTocMount *next;
    s32 uses;         // 0x08: times this set has been asked for (fn_8012DDA8)
    char name[0x40];  // 0x0C: resource set name, e.g. "tracks"
    void *request;    // 0x4C: fn_8012CAA0 request reading the set (fn_8012DFE8)
};

struct ResTocMountList {
    ResTocMount *head;
    ResTocMount **tail;
};

struct ResTocNodePool {  // the manager's fixed pool of mount nodes, at +0x8
    ResTocMount *nodes;    // +0x00: the node array (the manager's own storage)
    s32 capacity;          // +0x04: how many nodes it holds (0x20)
    ResTocMount *inUse;    // +0x08: nodes handed out, chained at poolNext (fn_8012E460)
    ResTocMount *freeList; // +0x0C: nodes up for grabs, chained at poolNext
};

struct ResTocManager {
    void *vtable;              // 0x00: lbl_8032ACB0
    u8 unk_0x4[0x4];
    ResTocNodePool pool;       // 0x08: where mount nodes come from
    u8 nodes[0xA00];           // 0x18: the 0x20 pool nodes, 0x50 bytes each
    ResTocMountList mounts;    // 0xA18: the sets being loaded, in queue order
    u8 pumping;                // 0xA20: fn_8012DEE4 is working the queue
};

// findResourceEntry could not find NAME (arg0) in any loaded resource table.  Ask
// every mounted set's on-disc ETOC table whether it lists NAME; if one does,
// the set is mounted but its resources have not been set yet, which is the
// "Get-Before-Wait" error the res-CRIP() message reports with the set's name.
extern "C" void reportGetBeforeWaitError(s32 resName) {
    char tocPath[128];
    s32 tocOffset;
    u8 startedLoad;
    char *nameSrc;
    s32 nameLeft;
    char *pathDst;
    char *extSrc;
    s32 extLeft;
    char *extDst;
    u8 c, c2;
    u8 swap0, swap1, swap2, swap3, swap4;
    u8 swap5, swap6, swap7, swap8, swap9;
    u32 tocVersion;
    ResTocMount *mount;
    ResTocMount *matched;
    u8 *toc;
    u32 nameIndex;
    u32 hasName;
    u32 entryIndex;
    u8 *nameEntry;
    u8 *entry;

    if (lbl_8055E014 == 0) return;  // no external-TOC manager yet
    mount = RES_TOC_MANAGER->mounts.head;
    matched = 0;
    goto mount_test;
mount_loop:
    // tocPath = "<set name>.toc", the resource holding this set's ETOC block
    nameSrc = mount->name; pathDst = tocPath; nameLeft = sizeof(tocPath);
    goto name_copy;
name_limit:
    nameLeft -= 1;
    if (nameLeft > 0) goto name_copy;
    pathDst[-1] = 0;
    goto name_done;
name_copy:
    c = *nameSrc++; *pathDst++ = c;
    if ((s8)c != 0) goto name_limit;
name_done:
    if ((s8)*fn_80029004(tocPath, '.') != 0) *fn_80029004(tocPath, '.') = 0;  // cut the set name's own extension
    extDst = tocPath; extLeft = sizeof(tocPath);
    goto ext_scan_test;
ext_scan_step:
    extLeft -= 1; extDst += 1;
ext_scan_test:
    if ((s8)*extDst != 0) goto ext_scan_step;  // walk to the end of the name
    if (extLeft <= 0) goto path_ready;
    extSrc = RES_TOC_EXT_PATH;
    goto ext_copy;
ext_limit:
    extLeft -= 1;
    if (extLeft > 0) goto ext_copy;
    extDst[-1] = 0;
    goto path_ready;
ext_copy:
    c2 = *extSrc++; *extDst++ = c2;
    if ((s8)c2 != 0) goto ext_limit;
path_ready:
    fn_8002B0D8(tocPath);  // map the path through the current character table
    // Read the set's ETOC resource; startedLoad is set when this call had to
    // start the read, so the block that came in is still little-endian.
    toc = (u8 *)getResourceData((s32)tocPath, RES_TOC_FOURCC, (s32)&tocOffset, 0, 0, (s32)&startedLoad);
    if (toc != 0 && startedLoad != 0) {
        // byte-reverse the ETOC header's five words
        swap0 = toc[0]; toc[0] = toc[3]; toc[3] = swap0;
        swap1 = toc[1]; toc[1] = toc[2]; toc[2] = swap1;
        swap2 = toc[4]; toc[4] = toc[7]; toc[7] = swap2;
        swap3 = toc[5]; toc[5] = toc[6]; toc[6] = swap3;
        swap4 = toc[8]; toc[8] = toc[0xB]; toc[0xB] = swap4;
        swap5 = toc[9]; toc[9] = toc[0xA]; toc[0xA] = swap5;
        swap6 = toc[0xC]; toc[0xC] = toc[0xF]; toc[0xF] = swap6;
        swap7 = toc[0xD]; toc[0xD] = toc[0xE]; toc[0xE] = swap7;
        swap8 = toc[0x10]; toc[0x10] = toc[0x13]; toc[0x13] = swap8;
        swap9 = toc[0x11]; toc[0x11] = toc[0x12]; toc[0x12] = swap9;
        tocVersion = *(u32 *)toc;
        if (tocVersion != 0 || *(u32 *)(toc + 4) != RES_TOC_HEADER_SIZE)
            Abend_Panic(lbl_8032AE60, tocVersion, 0, *(u32 *)(toc + 4), RES_TOC_HEADER_SIZE);

        entry = toc + RES_TOC_HEADER_SIZE; entryIndex = 0;
        goto entry_test;
entry_loop:
        fn_8012A388(entry);  // byte-reverse one entry
        entry += RES_TOC_ENTRY_SIZE; entryIndex += 1;
entry_test:
        if (entryIndex < *(u32 *)(toc + 0xC)) goto entry_loop;  // entryCount
    }
    nameEntry = toc + RES_TOC_HEADER_SIZE; hasName = 0; nameIndex = 0;
    goto name_test;
name_loop:
    if (stricmp((const char *)nameEntry, (const char *)resName) == 0) {
        hasName = 1; goto name_found;
    }
    nameEntry += RES_TOC_ENTRY_SIZE; nameIndex += 1;
name_test:
    if (nameIndex < *(u32 *)(toc + 0xC)) goto name_loop;
name_found:
    if (hasName != 0) matched = mount;
    releaseResource(toc);  // release the ETOC resource again
    mount = mount->next;
mount_test:
    if (mount != 0 && matched == 0) goto mount_loop;
    if (matched != 0) Abend_Panic(lbl_8032ADA0, matched->name, (const char *)resName);
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012DBD0(void) {
    /* Allocate and initialize the async set queue/effect object when enabled, then register it. */
    void *queue;
    s32 index;
    u32 slotOffset;
    s32 lastIndex;
    u32 *entryBase;
    u32 endAddress;

    if (lbl_8055DFFC != 0) {
        queue = fn_801284F8(0xA24, lbl_8032ACA0);
        if (queue != 0) {
            *(void **)queue = lbl_8032ACB0;
            *(s32 *)((char *)queue + 0xC) = 0x20;
            *(void ***)((char *)queue + 8) = (void **)((char *)queue + 0x18);
            *(void **)((char *)queue + 0x14) = 0;
            *(s32 *)((char *)queue + 0x10) = 0;
            index = 0;
            slotOffset = 0;
            goto loop_test;
        loop_body:
            entryBase = *(u32 * volatile *)((char *)queue + 8);
            *(u32 *)((char *)entryBase + slotOffset) = (u32)((char *)entryBase + (u32)(index + 1) * 0x50);
            slotOffset += 0x50;
            index += 1;
        loop_test:
            lastIndex = *(s32 *)((char *)queue + 0xC) - 1;
            if (index < lastIndex) goto loop_body;
            entryBase = *(u32 * volatile *)((char *)queue + 8);
            *(u32 *)((char *)entryBase + (u32)lastIndex * 0x50) = 0;
            endAddress = (u32)queue + 0xA18;
            entryBase = *(u32 * volatile *)((char *)queue + 8);
            *(u32 *)((char *)queue + 0x14) = (u32)entryBase;
            *(s32 *)((char *)queue + 0xA18) = 0;
            *(u32 *)((char *)queue + 0xA1C) = endAddress;
            fn_80127CF4((s32)queue, (s32)lbl_8032ACD0);
            *(u8 *)((char *)queue + 0xA20) = 0;
        }
        lbl_8055E014 = (nw4r::ef::Effect *)queue;
    }
}
#pragma pop

extern "C" s32 fn_80128668(void *);
extern "C" s32 fn_8012DCC0(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper (Effect vtable slot +0x18): free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
}

extern "C" void fn_80127E28(void *);
extern "C" void fn_80128660(s32);
extern "C" void fn_80128670(s32);
extern "C" void fn_8012C90C(void *);
extern "C" void fn_8012C958(void *);
extern "C" void *memcpy(void *, const void *, u32);
extern "C" u8 lbl_8032ACB0[];
namespace nw4r { namespace ef {
// Effect: the game's effect object.  Its vtable is lbl_8032ACB0 (+0x8 the
// deleting destructor __dt__Q34nw4r2ef6EffectFv, +0xC fn_8012F06C,
// +0x18 fn_8012DCC0); the one instance, lbl_8055E014, is the 0xA24-byte
// "AsyncSetQ" queue fn_8012DBD0 allocates and fn_8012DD00 deletes.
class Effect {
public:
    virtual ~Effect();
};
} }
extern "C" nw4r::ef::Effect *lbl_8055E014;

struct Unk8012DFCCNode {
    void *unk_0x0;
    Unk8012DFCCNode *next;
    s32 unk_0x8;
    char unk_0xC[0x40];
};
struct Unk8012DFCCList {
    Unk8012DFCCNode *head;
    Unk8012DFCCNode **tail;
};


extern "C" s32 fn_8012CAA0(s32, void * = 0);
#pragma dont_inline on
extern "C" void fn_8012DD00(void) {
    /* Destroy the singleton AsyncSetQ/external-TOC manager instance (lbl_8055E014) if present. */
    if (lbl_8055E014) {
        delete lbl_8055E014;
        lbl_8055E014 = 0;
    }
}

extern "C" void *__dt__Q34nw4r2ef6EffectFv(nw4r::ef::Effect *effect, s32 deleteFlag) {
    /* nw4r::ef::Effect::~Effect(): the deleting destructor CodeWarrior emits for
     * the class declared above (the "AsyncSetQ" effect object fn_8012DBD0 builds).
     * Restores the vtable pointer, drops the object's record from the effect
     * registry and frees it when the hidden delete flag is set. */
    if (effect) {
        *(void **)effect = lbl_8032ACB0; // nw4r::ef::Effect's vtable
        fn_80127E28(effect);
        if (deleteFlag > 0) fn_80128668(effect); // operator delete
    }
    return effect;
}

extern "C" void fn_8012DFE8(void *, const char *, s32);
extern "C" void fn_8012DEE4(void *);
extern "C" void fn_8012DFCC(Unk8012DFCCList *, Unk8012DFCCNode *);
extern "C" void *loadTocFile(void *, const char *);
extern "C" s32 fn_8012D838(s32);
extern "C" void *fn_8012E3D4(void *);
extern "C" void fn_8012E40C(void *, s32);
extern "C" void fn_8012E2CC(void *);
extern "C" void *fn_8012E460(void *);
extern "C" s32 fn_8012E490(s32 *);
extern "C" const char lbl_8032ACE0[];
#pragma use_lmw_stmw off
extern "C" void fn_8012DDA8(s32 resName) {
    /* Queue the named resource set's external TOC ("<set>.toc") for loading:
     * reuse an existing mount and bump its use count, or allocate a fresh node
     * from the manager's pool and enqueue it. On failure fall back to the
     * ordinary resource lookup, which reports the set as not found. */
    s32 found;
    ResTocManager *manager;
    ResTocMount *mount;
    if (fn_8012BD3C(lbl_8055E000, (const char *)resName) != 0) goto not_found;
    manager = (ResTocManager *)lbl_8055E014;
    if (manager == 0) goto not_found;
    found = 0;
    mount = (ResTocMount *)fn_8012E490((s32 *)&manager->mounts);
    while (mount != 0) {
        if (stricmp(mount->name, (const char *)resName) == 0) {
            found = 1;
            mount->uses += 1;
            break;
        }
        mount = mount->next;
    }
    if (found != 0) goto check;
    fn_802E30C8(lbl_8032ACE0, (const char *)resName);
    mount = (ResTocMount *)fn_8012E460((ResTocNodePool *)&manager->pool);
    if (mount == 0) {
        fn_8012E2CC(manager);
        mount = (ResTocMount *)fn_8012E460((ResTocNodePool *)&manager->pool);
    }
    if (mount == 0) goto check;
    fn_8012DFE8(mount, (const char *)resName, (s32)loadTocFile(&manager->unk_0x4, (const char *)resName));
    fn_8012DFCC((Unk8012DFCCList *)&manager->mounts, (Unk8012DFCCNode *)mount);
    fn_8012DEE4(manager);
    found = 1;
check:
    if (found == 0) {
not_found:
        ((void *(*)(const char *, void **))fn_8012BD98)((const char *)resName, &lbl_8055E000);
    }
}

extern "C" s32 fn_8012CC24(void *, void *);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Work the manager's load queue (fn_8012DDA8 queues a set and calls this): while
 * the set at the head has no read in flight, start one with fn_8012CC24; once
 * its request has the set in memory, give the loaded resource the use count the
 * queue collected, mark it ready and retire the queue node.  Stops as soon as
 * the head stops making progress; the manager's pumping byte keeps a set that
 * finishes inside fn_8012CC24 from re-entering this. */
extern "C" void fn_8012DEE4(void *arg0) {
    ResTocManager *manager = (ResTocManager *)arg0;
    s32 one = 1;
    s32 zero = 0;
    ResTocMount *entry;
    s32 progress;
    s32 state;

    if (manager->pumping != 0) return;
    manager->pumping = (u8)one;
    do {
        progress = 0;
        entry = manager->mounts.head;
        if (entry != 0) {
            state = fn_8012D838((s32)entry->request);
            switch (state) {
            case 0:  // idle: have the request read on with this set's path list
                fn_8012CC24(entry->request, entry->name);
                break;
            case 2: {  // the set is in memory: hand it the queue's use count
                void *node = fn_8012BD3C(lbl_8055E000, entry->name);
                *(s32 *)((u8 *)node + 0x9C) = entry->uses;  // resource use count
                *(u8 *)((u8 *)node + 0xAD) = (u8)one;       // resource is ready
                entry = manager->mounts.head;
                if (entry != 0) {
                    ResTocMount *next = entry->next;
                    manager->mounts.head = next;
                    if (next == 0) manager->mounts.tail = &manager->mounts.head;
                    entry->next = (ResTocMount *)zero;
                }
                progress = 1;
                break;
            }
            default:  // a read is still in flight: nothing more to do for now
                break;
            }
        }
    } while (progress != 0);
    manager->pumping = 0;
}
#pragma pop

extern "C" void fn_8012DFCC(Unk8012DFCCList *list, Unk8012DFCCNode *node) {
    /* Append a node to the tail of an AsyncSetQ external-TOC node list. */
    *list->tail = node;
    list->tail = &node->next;
    node->next = 0;
}

/* Initializes an object with the given path (copied, up to 0x40 chars, into +0xC),
   starts a read request for that path via fn_8012CAA0 (stored at +0x4C), and
   marks the object ready (+8 = 1). */
extern "C" void fn_8012DFE8(void *obj, const char *path, s32 size) {
    const unsigned char *src = (const unsigned char *)path;
    int count = 0x40;
    char *dst = (char *)obj + 0xc;
    unsigned char c;
    goto copy;
count_check:
    if (--count > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto count_check;
done:
    *(s32 *)((u8 *)obj + 0x4c) = fn_8012CAA0(size, (void *)path);
    *(s32 *)((u8 *)obj + 8) = 1;
}

extern "C" void *loadTocFile(void *unused, const char *path) {
    /* Build "<path-without-ext>.toc", load that resource, byte-swap its header
     * and each entry, and return the data pointer offset by 0x80. */
    const char *originalPath = path;
    char tocPath[0x80];
    s32 dataSize;
    u8 needsByteSwap;
    s32 pathRemaining;
    char *pathDst;
    char *suffixSource;
    s32 suffixRemaining;
    char *scan;
    u8 pathChar;
    u8 suffixChar;
    void *tocData;
    u8 swapByte;
    u8 unusedByte;
    u32 entryIndex;
    u8 *tocEntry;
    void *tocEntries;
    char *dot;

    pathDst = tocPath; pathRemaining = 0x80;
    goto path_copy;
path_limit:
    pathRemaining -= 1;
    if (pathRemaining > 0) goto path_copy;
    pathDst[-1] = 0;
    goto path_done;
path_copy:
    pathChar = *path++; *pathDst++ = pathChar;
    if ((s8)pathChar != 0) goto path_limit;
path_done:
    dot = fn_80029004(tocPath, 0x2E);
    if ((s8)*dot != 0) {
        dot = fn_80029004(tocPath, 0x2E);
        *dot = 0;
    }
    scan = tocPath; suffixRemaining = 0x80;
    goto scan_test;
scan_step:
    suffixRemaining -= 1; scan += 1;
scan_test:
    if ((s8)*scan != 0) goto scan_step;
    if (suffixRemaining <= 0) goto path_all_done;
    suffixSource = (char *)&lbl_805599E0;
    goto suffix_copy;
suffix_limit:
    suffixRemaining -= 1;
    if (suffixRemaining > 0) goto suffix_copy;
    scan[-1] = 0;
    goto path_all_done;
suffix_copy:
    suffixChar = *suffixSource++; *scan++ = suffixChar;
    if ((s8)suffixChar != 0) goto suffix_limit;
path_all_done:
    fn_8002B0D8(tocPath);
    tocData = (void *)getResourceData((s32)tocPath, 0x45544F43, (s32)&dataSize, 0, 0, (s32)&needsByteSwap);
    if (tocData != 0 && needsByteSwap != 0) {
        u8 *bytes = (u8 *)tocData;
        swapByte = bytes[0]; bytes[0] = bytes[3]; bytes[3] = swapByte;
        swapByte = bytes[1]; bytes[1] = bytes[2]; bytes[2] = swapByte;
        swapByte = bytes[4]; bytes[4] = bytes[7]; bytes[7] = swapByte;
        swapByte = bytes[5]; bytes[5] = bytes[6]; bytes[6] = swapByte;
        swapByte = bytes[8]; bytes[8] = bytes[0xB]; bytes[0xB] = swapByte;
        swapByte = bytes[9]; bytes[9] = bytes[0xA]; bytes[0xA] = swapByte;
        swapByte = bytes[0xC]; bytes[0xC] = bytes[0xF]; bytes[0xF] = swapByte;
        swapByte = bytes[0xD]; bytes[0xD] = bytes[0xE]; bytes[0xE] = swapByte;
        swapByte = bytes[0x10]; bytes[0x10] = bytes[0x13]; bytes[0x13] = swapByte;
        swapByte = bytes[0x11]; bytes[0x11] = bytes[0x12]; bytes[0x12] = swapByte;
        if (*(u32 *)bytes != 0 || *(u32 *)(bytes + 4) != 0x14)
            Abend_Panic(lbl_8032AE60, *(u32 *)bytes, 0, *(u32 *)(bytes + 4), 0x14);
        tocEntry = bytes + 0x14; entryIndex = 0;
        goto entries_test;
entries_loop:
        fn_8012A388(tocEntry); tocEntry += 0x44; entryIndex += 1;
entries_test:
        if (entryIndex < *(u32 *)(bytes + 0xC)) goto entries_loop;
    }
    if (tocData == 0) Abend_Panic(lbl_8032ADDC, originalPath);
    tocEntries = (void *)(*(s32 *)((char *)tocData + 0x10) + 0x80);
    releaseResource(tocData);
    return tocEntries;
}

#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012E2CC(void *arg0) {
    /* Process pending resource-load requests queued at +0xA18: wait until the current
     * request's handle is ready, then for each queued entry start loads (status 0),
     * attach completed resources (status 2) into lbl_8055E000 by name, or ignore others,
     * guarding re-entry with the busy flag at +0xA20. */
    u8 *obj = (u8 *)arg0;
    void *currentRequest;
    void *entry;
    void *resource;
    s32 status;

    currentRequest = *(void **)(obj + 0xA18);
    if (currentRequest == 0) return;
    goto check_status;
retry_status:
    fn_80127464();
    KERNEL_WaitMilliseconds(0xA);
check_status:
    if (fn_8012D838(*(s32 *)((u8 *)currentRequest + 0x4C)) != 2) goto retry_status;
    if (obj[0xA20] != 0) return;
    obj[0xA20] = 1;
    do {
        currentRequest = 0;
        entry = (void *)fn_8012E490((s32 *)(obj + 0xA18));
        if (entry != 0) {
            status = fn_8012D838(*(s32 *)((u8 *)entry + 0x4C));
            switch (status) {
            case 0:
                fn_8012E40C((void *)*(s32 *)((u8 *)entry + 0x4C), (s32)((u8 *)entry + 0xC));
                break;
            case 2:
                resource = fn_8012BD3C(lbl_8055E000, (const char *)((u8 *)entry + 0xC));
                *(s32 *)((u8 *)resource + 0x9C) = *(s32 *)((u8 *)entry + 8);
                *(u8 *)((u8 *)resource + 0xAD) = 1;
                fn_8012E3D4(obj + 0xA18);
                currentRequest = (void *)1;
                break;
            default:
                break;
            }
        }
    } while (currentRequest != 0);
    obj[0xA20] = 0;
}
#pragma pop

/* Intrusive FIFO queue at arg0: head at +0, and tail at +4 is a pointer to the
 * last node's next field (or to the queue itself while empty). Nodes link at +4. */
#define QUEUE_TAIL    4
#define QUEUE_NODE_NEXT 4

extern "C" void *fn_8012E3D4(void *queue) {
    void *next;
    void *node;
    void *result;
    /* Pop the front node: advance the head, reset the tail when the queue empties,
     * clear the removed node's link, and return that node (or 0 if empty). */
    node = *(void **)queue;
    result = 0;
    if (node != 0) {
        next = *(void **)((u8 *)node + QUEUE_NODE_NEXT);
        result = node;
        *(void **)queue = next;
        if (next == 0) {
            *(void **)((u8 *)queue + QUEUE_TAIL) = queue;
        }
        *(void **)((u8 *)node + QUEUE_NODE_NEXT) = 0;
    }
    return result;
}

/* (Re)starts a queued resource request -- the handle a loader's queue node keeps
 * at +0x4C.  Runs the request's state machine once (fn_8012D40C), releases
 * whatever it holds right now (fn_8012D1A8), rewinds its cursor into the
 * candidate-name list (+0xBC) and starts loading from nameList again
 * (loadResourceFromNameList), which opens the first candidate that resolves.  The loader
 * calls this for a request whose status (fn_8012D838) is 0, i.e. one that never
 * got going. */
extern "C" void fn_8012E40C(void *request, s32 nameList) {
#define REQ_NAME_INDEX 0xBC /* which candidate of the name list the request is on */
    void *self = request;
    fn_8012D40C((s32)self);
    fn_8012D1A8((s32)self);
    *(s32 *)((u8 *)self + REQ_NAME_INDEX) = 0;
    /* loadResourceFromNameList is prototyped with a third, unused argument; called with the
     * two it uses. */
    ((void (*)(void *, s32))loadResourceFromNameList)(self, nameList);
#undef REQ_NAME_INDEX
}

extern "C" void *fn_8012E460(void *poolHeader) {
    ResTocNodePool *pool = (ResTocNodePool *)poolHeader;
    ResTocMount *node = pool->freeList;
    ResTocMount *result = 0;
    /* Take a mount node from the manager's node pool (its header is the pool
     * field at +0x8): unlink the head of the free list and chain it onto the
     * in-use list through the nodes' poolNext link.  Returns 0 when the pool
     * is empty; the caller then runs the load queue and asks again. */
    if (node != 0) {
        result = node;
        pool->freeList = (ResTocMount *)node->poolNext;
        node->poolNext = pool->inUse;
        pool->inUse = node;
    }
    return result;
}

/* Returns the value stored at slot (used to read an effect's +0xA18 linked-list head). */
extern "C" s32 fn_8012E490(s32 *slot) {
    return *slot;
}

extern "C" const char lbl_8032ACF4[];
#pragma push
#pragma scheduling invalid_target
/* Releases a named resource: decrements its refcount, and when it reaches zero
 * finalizes pending/active effect entries for that name or removes the resource. */
extern "C" void fn_8012E498(void *name) {
    s32 removed;
    s32 entry;
    s32 effect;
    s32 resource;
    fn_8012E81C((s32)name);
    resource = (s32)fn_8012BD3C(lbl_8055E000, (const char *)name);
    if (resource != 0 && --*(s32 *)(resource + 0x9C) == 0) {
        effect = (s32)lbl_8055E014;
        if (effect != 0) {
            removed = 0;
            entry = fn_8012E490((s32 *)(effect + 0xA18));
            while (entry != 0) {
                if (stricmp((const char *)(entry + 0xC), (const char *)name) == 0) {
                    waitForResourceLoad(effect, (s32)name);
                    break;
                }
                entry = *(s32 *)(entry + 4);
            }
            entry = fn_8012E490((s32 *)(effect + 0xA18));
            while (entry != 0) {
                if (stricmp((const char *)(entry + 0xC), (const char *)name) == 0) {
                    Abend_Panic(lbl_8032ACF4);
                }
                entry = *(s32 *)(entry + 4);
            }
            entry = fn_8012E674((void *)(effect + 8));
            while (entry != 0) {
                if (stricmp((const char *)(entry + 0xC), (const char *)name) == 0) {
                    fn_8012E630((void *)entry);
                    fn_8012E5E4((void *)(effect + 8), (void *)entry);
                    removed = 1;
                    break;
                }
                entry = *(s32 *)entry;
            }
            if (removed != 0) return;
        }
        fn_8012BB20((s32)&lbl_8055E000, (void *)resource);
    }
}
#pragma pop
#pragma scheduling reset

/* RealName: ListRemoveNodeToFreeList (tentative). Removes targetNode from a singly-linked list whose head pointer is at list+0x8; if found, pushes it onto a free list whose head pointer is at list+0xC. */
extern "C" void fn_8012E5E4(void *list, void *targetNode) {
    void *node;
    s32 found;
    void **link;
    link = (void **)((u8 *)list + 8);
    found = 0;
    while ((node = *link) != 0) {
        if (node == targetNode) {
            *link = *(void **)node;
            found = 1;
            break;
        }
        link = (void **)node;
    }
    if (found == 0) return;
    *(void **)targetNode = *(void **)((u8 *)list + 0xC);
    *(void **)((u8 *)list + 0xC) = targetNode;
}

/* Tear down the resource handle at +0x4C and clear the node's handle/state fields. */
extern "C" void fn_8012E630(void *node) {
    fn_8012D3D8(*(s32 *)((u8 *)node + 0x4C));
    fn_8012D8A8(*(s32 *)((u8 *)node + 0x4C));
    *(s32 *)((u8 *)node + 0x4C) = 0;
    *((u8 *)node + 0xC) = 0;
}

extern "C" s32 fn_8012E674(void *list) {
    /* Return the head of the singly-linked list whose head pointer lives at list+0x8. */
    return *(s32*)((u8*)list + 8);
}

  #pragma push
  #pragma scheduling invalid_target
/* Waits for the pending resource request named `name` on loader `loader` to
 * finish loading (state 2), draining the loader's request queue meanwhile, then
 * clears the resource entry's "pending" flag (+0xAD). */
/* Waits for a named pending resource request to finish loading, draining the loader's request queue as completions arrive, then clears the resource entry's pending flag. */ extern "C" void waitForResourceLoad(s32 loader, s32 name) {
    u8 *self = (u8 *)loader;
    s32 start, deadline, now, done;
    void *entry;
    void *resEntry;
    u8 *req;
    for (req = *(u8 **)(self + 0xA18); req != 0; req = *(u8 **)(req + 4)) {
        if (stricmp((const char *)name, (const char *)(req + 0xC)) == 0) {
            start = KERNEL_GetTimeMs();
            deadline = start + 0x7D0;
            while (fn_8012D838(*(s32 *)(req + 0x4C)) != 2) {
                fn_80127464();
                KERNEL_WaitMilliseconds(0xA);
                now = KERNEL_GetTimeMs();
                if (now > deadline) {
                    fn_802E30C8(lbl_8032AD88, (const char *)(req + 0xC));
                    deadline = now + 0x7D0;
                }
            }
            if (self[0xA20] == 0) {
                self[0xA20] = 1;
                do {
                    done = 0;
                    entry = (void *)fn_8012E490((s32 *)(self + 0xA18));
                    if (entry != 0) {
                        switch (fn_8012D838(*(s32 *)((u8 *)entry + 0x4C))) {
                        case 0:
                            fn_8012E40C((void *)*(s32 *)((u8 *)entry + 0x4C), (s32)((u8 *)entry + 0xC));
                            break;
                        case 2:
                            resEntry = fn_8012BD3C(lbl_8055E000, (const char *)((u8 *)entry + 0xC));
                            *(s32 *)((u8 *)resEntry + 0x9C) = *(s32 *)((u8 *)entry + 8);
                            *(u8 *)((u8 *)resEntry + 0xAD) = 1;
                            fn_8012E3D4(self + 0xA18);
                            done = 1;
                            break;
                        }
                    }
                } while (done != 0);
                self[0xA20] = 0;
            }
            fn_802E30C8(lbl_8032AD6C, (const char *)(req + 0xC), KERNEL_GetTimeMs() - start);
            break;
        }
    }
    resEntry = fn_8012BD3C(lbl_8055E000, (const char *)name);
    if (resEntry != 0) {
        *(u8 *)((u8 *)resEntry + 0xAD) = 0;
    } else {
        fn_802E30C8(lbl_8032AD2C, (const char *)name);
    }
}
  #pragma pop

extern "C" const char lbl_8032AD2C[];
extern "C" const char lbl_8032AD6C[];
extern "C" const char lbl_8032AD88[];
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012E81C(s32 arg0) {
    #pragma opt_common_subs off
    nw4r::ef::Effect *effect = lbl_8055E014;
    s32 limit;
    void *entry;
    s32 start;
    s32 current;

    if (effect == 0) return;
    entry = (void *)fn_8012E490((s32 *)((u8 *)effect + 0xA18));
    while (entry != 0) {
        if (stricmp((const char *)arg0,
                    (const char *)((u8 *)entry + 0xC)) == 0) {
            start = KERNEL_GetTimeMs();
            limit = start + 0x7D0;
            do {
                fn_80127464();
                KERNEL_WaitMilliseconds(0xA);
                current = KERNEL_GetTimeMs();
            } while (current <= limit);
            fn_802E30C8(lbl_8032AD88, (const char *)((u8 *)entry + 0xC));
            limit = current + 0x7D0;
            if (fn_8012D838(*(s32 *)((u8 *)entry + 0x4C)) == 2) {
                fn_8012DEE4(effect);
                fn_802E30C8(lbl_8032AD6C,
                            (const char *)((u8 *)entry + 0xC),
                            KERNEL_GetTimeMs() - start);
                return;
            }
        }
        entry = *(void **)((u8 *)entry + 4);
    }
    {
        void *found = fn_8012BD3C(lbl_8055E000, (const char *)arg0);
        if (found != 0) {
            *(u8 *)((u8 *)found + 0xAD) = 0;
            return;
        }
    }
    fn_802E30C8(lbl_8032AD2C, (const char *)arg0);
}
#pragma pop

extern "C" s32 fn_8012E938(s32 name) {
    /* Return nonzero if a resource set with this directory name is already
       registered in the global resource-manager list (lbl_8055E000). */
    return fn_8012BD3C(lbl_8055E000, (const char *)name) != 0;
}

/* Ensures the resource named by arg0 is loaded via the external-TOC manager: locates its owning set/mount, then waits for that resource to become ready. */
extern "C" void fn_8012E96C(s32 arg0) {
    s32 sp8;
    s32 result;
    s32 arg = arg0;
    nw4r::ef::Effect *entry = lbl_8055E014;
    if (entry != 0) {
        result = ((s32 (*)(s32, s32 *, s32))findResourceEntry)(arg0, &sp8, 3);
        if (result == 0) {
            result = findResourceOwningMount((s32)entry, arg);
            if (result != 0)
                waitForResourceLoad((s32)entry, result + 0xC);
        } else {
            waitForResourceLoad((s32)entry, result);
        }
    }
}

// Which mounted resource set owns the resource name arg1?  Walks arg0's mount
// list the way reportGetBeforeWaitError does - "<set>.toc" read as an ETOC block, its header
// and entries byte-reversed if the read just brought it in - and returns the
// mount whose table lists arg1 (fn_8012E96C reports the set by its name at
// +0xC), or 0 when no mounted set has it.
/* Find which mounted external-TOC set owns a named resource: build each set's .toc path, load and byte-swap its ETOC table when freshly read, then search the entries for the name and return the owning mount (or 0). */ extern "C" s32 findResourceOwningMount(s32 manager, s32 resName) {
    char tocPath[128];
    s32 tocOffset;
    u8 startedLoad;
    char *nameSrc;
    s32 nameLeft;
    char *pathDst;
    char *extSrc;
    s32 extLeft;
    char *extDst;
    u8 c, c2;
    u8 swap0, swap1, swap2, swap3, swap4;
    u8 swap5, swap6, swap7, swap8, swap9;
    u32 tocVersion;
    u8 *toc;
    ResTocMount *matched;
    ResTocMount *mount;
    u32 nameIndex;
    u32 hasName;
    u32 entryIndex;
    u8 *nameEntry;
    u8 *entry;

    mount = ((ResTocManager *)manager)->mounts.head;
    matched = 0;
    goto mount_test;
mount_loop:
    // tocPath = "<set name>.toc", the resource holding this set's ETOC block
    nameSrc = mount->name; pathDst = tocPath; nameLeft = sizeof(tocPath);
    goto name_copy;
name_limit:
    nameLeft -= 1;
    if (nameLeft > 0) goto name_copy;
    pathDst[-1] = 0;
    goto name_done;
name_copy:
    c = *nameSrc++; *pathDst++ = c;
    if ((s8)c != 0) goto name_limit;
name_done:
    if ((s8)*fn_80029004(tocPath, '.') != 0) *fn_80029004(tocPath, '.') = 0;  // cut the set name's own extension
    extDst = tocPath; extLeft = sizeof(tocPath);
    goto ext_scan_test;
ext_scan_step:
    extLeft -= 1; extDst += 1;
ext_scan_test:
    if ((s8)*extDst != 0) goto ext_scan_step;  // walk to the end of the name
    if (extLeft <= 0) goto path_ready;
    extSrc = RES_TOC_EXT_PATH;
    goto ext_copy;
ext_limit:
    extLeft -= 1;
    if (extLeft > 0) goto ext_copy;
    extDst[-1] = 0;
    goto path_ready;
ext_copy:
    c2 = *extSrc++; *extDst++ = c2;
    if ((s8)c2 != 0) goto ext_limit;
path_ready:
    fn_8002B0D8(tocPath);  // map the path through the current character table
    // Read the set's ETOC resource; startedLoad is set when this call had to
    // start the read, so the block that came in is still little-endian.
    toc = (u8 *)getResourceData((s32)tocPath, RES_TOC_FOURCC, (s32)&tocOffset, 0, 0, (s32)&startedLoad);
    if (toc != 0 && startedLoad != 0) {
        // byte-reverse the ETOC header's five words
        swap0 = toc[0]; toc[0] = toc[3]; toc[3] = swap0;
        swap1 = toc[1]; toc[1] = toc[2]; toc[2] = swap1;
        swap2 = toc[4]; toc[4] = toc[7]; toc[7] = swap2;
        swap3 = toc[5]; toc[5] = toc[6]; toc[6] = swap3;
        swap4 = toc[8]; toc[8] = toc[0xB]; toc[0xB] = swap4;
        swap5 = toc[9]; toc[9] = toc[0xA]; toc[0xA] = swap5;
        swap6 = toc[0xC]; toc[0xC] = toc[0xF]; toc[0xF] = swap6;
        swap7 = toc[0xD]; toc[0xD] = toc[0xE]; toc[0xE] = swap7;
        swap8 = toc[0x10]; toc[0x10] = toc[0x13]; toc[0x13] = swap8;
        swap9 = toc[0x11]; toc[0x11] = toc[0x12]; toc[0x12] = swap9;
        tocVersion = *(u32 *)toc;
        if (tocVersion != 0 || *(u32 *)(toc + 4) != RES_TOC_HEADER_SIZE)
            Abend_Panic(lbl_8032AE60, tocVersion, 0, *(u32 *)(toc + 4), RES_TOC_HEADER_SIZE);

        entry = toc + RES_TOC_HEADER_SIZE; entryIndex = 0;
        goto entry_test;
entry_loop:
        fn_8012A388(entry);  // byte-reverse one entry
        entry += RES_TOC_ENTRY_SIZE; entryIndex += 1;
entry_test:
        if (entryIndex < *(u32 *)(toc + 0xC)) goto entry_loop;  // entryCount
    }
    // does this set's table have an entry named arg1?
    nameEntry = toc + RES_TOC_HEADER_SIZE; hasName = 0; nameIndex = 0;
    goto name_test;
name_loop:
    if (stricmp((const char *)nameEntry, (const char *)resName) == 0) {
        hasName = 1; goto name_found;
    }
    nameEntry += RES_TOC_ENTRY_SIZE; nameIndex += 1;
name_test:
    if (nameIndex < *(u32 *)(toc + 0xC)) goto name_loop;
name_found:
    if (hasName != 0) matched = mount;
    releaseResource(toc);  // release the ETOC resource again
    mount = mount->next;
mount_test:
    if (mount != 0 && matched == 0) goto mount_loop;
    return (s32)matched;
}

// One prefetch slot of a ResourceStream, 0x10 bytes.
struct ResourceStreamEntry {
    s32 buffer;              // +0x00 where the chunk lands in the stream's buffer
    void *request;           // +0x04 async read of the chunk (fn_8012C720/fn_8012C7FC)
    s32 position;            // +0x08 file offset the chunk was read from
    s32 state;               // +0x0C StreamSlotState
};

// What a prefetch slot is doing.
enum StreamSlotState {
    STREAM_SLOT_FREE = 0,    // holds nothing
    STREAM_SLOT_READING = 1, // the disc read of the chunk is running
    STREAM_SLOT_READY = 2    // the chunk is in memory and can be read from
};

#define STREAM_SLOT_COUNT 2  // prefetch slots in a ResourceStream

// Double-buffered streaming reader over a resource file ("ResourceStream"), 0x2C
// bytes. The slots read the file ahead in chunks of `size` bytes into the buffer
// of 2 * size bytes made by fn_8012EC90; fn_8012EE80 runs the machine each frame
// and fn_8012EFB0 takes bytes out of a ready chunk at `boundary`.
struct ResourceStream {
    s32 size;                                  // +0x00 bytes of the file one slot holds
    ResourceStreamEntry entries[STREAM_SLOT_COUNT];  // +0x04 the prefetch slots
    s32 limit;                                 // +0x24 size of the streamed file
    s32 boundary;                              // +0x28 offset the reader has reached
};

// Heap-name tags fn_801284F8/fn_8012850C record with an allocation (strings in .sdata).
#define RES_STREAM_HEAP      ((void *)&lbl_805599C8)  // "resbuf": the stream object
#define RES_STREAM_DATA_HEAP ((void *)&lbl_805599D0)  // "resbufb": its read-ahead buffer

extern "C" ResourceStream *fn_8012EC90(s32 chunkSize) {
    /* Allocate and clear a ResourceStream that reads a resource file ahead in
       chunks of `chunkSize`: the object comes from the "resbuf" heap and its
       double buffer (2 * chunkSize bytes, 0x80-aligned) from "resbufb", with
       slot 1's buffer starting where slot 0's chunk lands. */
    s32 size = chunkSize;
    ResourceStream *stream = (ResourceStream *)fn_801284F8(sizeof(ResourceStream), RES_STREAM_HEAP);
    memset(stream, 0, sizeof(ResourceStream));
    stream->size = size;
    fn_801282EC(0x80);  // align the next allocation to 0x80
    s32 buffer = (s32)fn_8012850C(size << 1, RES_STREAM_DATA_HEAP);
    stream->entries[0].request = 0;
    stream->entries[0].buffer = buffer;
    stream->entries[0].state = 0;
    stream->entries[1].request = 0;
    stream->entries[1].buffer = buffer + size;
    stream->entries[1].state = 0;
    stream->boundary = 0;
    stream->limit = 0;
    return stream;
}

extern "C" void fn_8012ED20(void *object) {
    /* Release two child resource handles stored at offsets +8 and +0x18 of the
     * object (cancel/reset each if non-null, then clear), free the object's
     * owned buffer at +4, and delete the object. */
    u8 *slot;
    s32 index;
    struct OwnedBuffer { s32 _pad; s32 buffer; };
    for (index = 0, slot = (u8 *)object + 4; index < 2; index++, slot += 0x10) {
        if (*(s32 *)(slot + 4)) {
            fn_8012C90C((void *)*(s32 *)(slot + 4));
            fn_8012C958((void *)*(s32 *)(slot + 4));
            *(s32 *)(slot + 4) = 0;
        }
    }
    fn_80128670(((struct OwnedBuffer *)object)->buffer);
    fn_80128668(object);
}

extern "C" s32 openResourceStream(s32, s32, s32);
extern "C" s32 getResourceSizeAligned(void *);
extern "C" void fn_8012EE80(void *);
extern "C" s32 fn_8012EDA8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 *slot;
    s32 *slots = (s32 *)((char *)arg0 + 4);
    s32 slotIndex;
    s32 initIndex;
    s32 handle;
    /* Reset both stream slots (release any active request), open the resource
       identified by (arg1,arg2,arg3) into each slot, record its data size, then
       start the prefetch; returns 0 if a slot cannot be opened. */
    for (slot = slots, initIndex = 0; initIndex < 2; initIndex++, slot += 4) {
        if (slot[1]) {
            fn_8012C90C((void *)slot[1]);
            fn_8012C958((void *)slot[1]);
            slot[1] = 0;
            slot[3] = 0;
        }
    }
    *(s32 *)((char *)arg0 + 0x28) = 0;
    for (slotIndex = 0; slotIndex < 2; slotIndex++, slots += 4) {
        handle = openResourceStream(arg1, arg2, arg3);
        slots[1] = handle;
        if (!handle) return 0;
        *(s32 *)((char *)arg0 + 0x24) = getResourceSizeAligned((void *)handle);
    }
    fn_8012EE80(arg0);
    return 1;
}

/* Returns the stream's boundary: the file offset the read-ahead reader has reached. */
extern "C" s32 fn_8012EE78(void *arg0) {
    return ((ResourceStream *)arg0)->boundary;
}

extern "C" s32 fn_8012C7FC(void *, s32 *);
extern "C" void fn_8012C720(void *, s32, s32, s32);
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8012EE80(void *arg0) {
    // Run the ResourceStream prefetch machine once: retire the reads that have
    // finished, then give every free or already-read-past slot the next chunk of
    // the file, reading it into that slot's half of the stream buffer.
    ResourceStream *stream = (ResourceStream *)arg0;
    ResourceStreamEntry *slot = stream->entries;
    ResourceStreamEntry *scan = slot;
    s32 i;
    s32 j;
    s32 end = stream->boundary;  // file offset just past the chunks held in memory
    s32 state;
    s32 pos;
    s32 len;
    s32 request;

    // a slot whose disc read finished is now readable; find the end of the held range
    for (i = 0; i < STREAM_SLOT_COUNT; i++, scan++) {
        state = scan->state;
        if (state != STREAM_SLOT_FREE) {
            if (state == STREAM_SLOT_READING && fn_8012C7FC(scan->request, 0))
                scan->state = STREAM_SLOT_READY;
            pos = scan->position + stream->size;
            if (pos > end)
                end = pos;
        }
    }

    j = 0;
    scan = 0;  // null, stored as the FREE state below
    for (; j < STREAM_SLOT_COUNT; j++, slot++) {
        state = slot->state;
        if (state != STREAM_SLOT_FREE)
            goto check_state;
        if (slot->request != 0)  // a slot the file was just opened into
            goto fill_slot;
check_state:
        if (state != STREAM_SLOT_READY)
            goto next_slot;  // still reading
        pos = slot->position + stream->size;
        if (pos >= stream->boundary)
            goto next_slot;  // the reader has not passed this chunk yet
fill_slot:
        slot->position = end;
        pos = end;
        len = stream->size;
        end += len;
        request = len;
        if (pos + len > stream->limit)
            request = stream->limit - pos;  // the last chunk is short
        if (request > 0) {
            fn_8012C720(slot->request, slot->buffer, request, pos);
            slot->state = STREAM_SLOT_READING;
        } else {
            slot->state = (s32)scan;  // nothing left to read: the slot goes free
        }
next_slot:
        ;
    }
}
#pragma pop

/* Reads bytes from the current buffered stream chunk if available; advances read position on success. */
extern "C" s32 fn_8012EFB0(void *stream, void *dst, s32 length) {
    s32 pos = *(s32 *)((u8 *)stream + 0x28);
    s32 i;
    if (pos + length >= *(s32 *)((u8 *)stream + 0x24)) return 0;
    for (i = 0; i < 2; i++) {
        u8 *slot = (u8 *)stream + 4 + i * 0x10;
        s32 start;
        if (*(s32 *)(slot + 0xC) != 2) continue;
        start = *(s32 *)(slot + 8);
        if (pos >= start && pos < start + *(s32 *)stream) {
            memcpy(dst, (u8 *)*(void **)slot + (pos - start), length);
            *(s32 *)((u8 *)stream + 0x28) += length;
            return 1;
        }
    }
    return 0;
}

extern "C" s32 fn_8012D838(s32);
#pragma scheduling invalid_target
/* Pumps queued resource requests on this loader: starts idle requests, attaches completed resources into the global list, and pops them, guarded by the busy flag at +0xA20. */
extern "C" void fn_8012F06C(void *arg0) {
    u8 *loader = (u8 *)arg0;
    if (loader[0xA20] == 0) {
        s32 one = 1;
        s32 done;
        loader[0xA20] = (u8)one;
        do {
            done = 0;
            void *entry = (void *)fn_8012E490((s32 *)(loader + 0xA18));
            if (entry != 0) {
                s32 state = fn_8012D838(*(s32 *)((u8 *)entry + 0x4C));
                switch (state) {
                case 0:
                    fn_8012E40C((void *)*(s32 *)((u8 *)entry + 0x4C), (s32)((u8 *)entry + 0xC));
                    break;
                case 2: {
                    void *resource = fn_8012BD3C(lbl_8055E000, (const char *)((u8 *)entry + 0xC));
                    *(s32 *)((u8 *)resource + 0x9C) = *(s32 *)((u8 *)entry + 8);
                    *(u8 *)((u8 *)resource + 0xAD) = (u8)one;
                    fn_8012E3D4(loader + 0xA18);
                    done = 1;
                    break;
                }
                default:
                    break;
                }
            }
        } while (done != 0);
        loader[0xA20] = 0;
    }
}
#pragma scheduling on
extern "C" void fn_802E30C8(const char *, ...);
extern "C" void Abend_Panic(const char *, ...);
extern "C" s32 fn_8012BC50(void *arg0, void *arg1, s32 arg2);
extern "C" void fn_8012BF24(void *);
extern "C" s32 fn_80128668(void *);
extern "C" const char lbl_8032AEA8[];
extern "C" const char lbl_8032AB9C[];
extern "C" const char lbl_8032ABC8[];
extern "C" const char lbl_8032ABEC[];
extern "C" s32 lbl_8055DFFC;
extern "C" s8 lbl_8055DFF8;
extern "C" void *lbl_8055E000;

extern "C" s32 fn_8012BC50(void *arg0, void *arg1, s32 arg2);

/* Thin C-linkage alias forwarding to the refcounted resource release fn_8012BC50. */
extern "C" s32 fn_8012C4E4(void *ownerPtr, void *onRelease, s32 releaseArg) {
    return fn_8012BC50(ownerPtr, onRelease, releaseArg);
}

#pragma scheduling invalid_target
extern "C" void fn_8012C4E8(void) {
    /* Resource subsystem shutdown: destroy the TOC/async managers, release the
     * TOC resource, then report any resource sets still loaded as fatal. */
    ResManager *set;
    s32 tocObject;

    fn_8012DD00();
    fn_8012A67C();
    tocObject = lbl_8055DFFC;
    if (tocObject != 0) {
        fn_8012BF24((void *)lbl_8032AEA8);
        fn_80128668((void *)tocObject);
    }
    set = (ResManager *)lbl_8055E000;
    lbl_8055DFFC = 0;
    lbl_8055DFF8 = 0;
    if (set != NULL) {
        while (set != NULL) {
            fn_802E30C8(lbl_8032AB9C, (void *)set, set->useCount);
            set = set->next;
        }
        Abend_Panic(lbl_8032ABC8);
    }
}
extern "C" void *fn_8012C58C(void *arg0) {
    /* Resource name for the diagnostic dump: the name recorded in the node header
     * at -8, or "res:unknown" when the tag at -4 is not the resource tag 0x4D474921. */
    void *name = (void *)&lbl_8032ABEC;

    if (arg0 != NULL &&
        (u32)(*(u32 *)((u8 *)arg0 - 4) - 0x4D470000) == 0x4921U) {
        name = *(void **)((u8 *)arg0 - 8);
    }
    return name;
}

extern "C" const char lbl_8032ABF8[];
extern "C" const char lbl_8032AC08[];
#pragma scheduling reset
/* Open an async resource stream: find path's entry with the requested type tag,
 * write its id to *outId and return an "AsyncResource" request holding the entry
 * and its manager; on a tag mismatch log "ResourceGetStream" and return 0. */
extern "C" s32 openResourceStream(s32 path, s32 typeTag, s32 outId) {
    long index;
    long result = 0;
    struct ResManager *manager;
    struct ResEntry *entry;

    manager = (struct ResManager *)((struct ResManager *(*)(s32, s32 *, s32))findResourceEntry)(path, &index, 1);
    if (manager != 0) {
        entry = (struct ResEntry *)(manager->entries + index * 0x44);
        if (entry->dataTag == (u32)typeTag) {
            *(s32 *)outId = entry->id;
            register void *allocation = fn_8012A570(0x18, (void *)lbl_8032ABF8);
            volatile s32 *fields = (volatile s32 *)allocation;
            if (allocation != 0) {
                fields[ASYNC_REQ_HANDLE] = -1;
                fields[ASYNC_REQ_DATA] = 0;
                fields[ASYNC_REQ_ENTRY] = 0;
                fields[ASYNC_REQ_MANAGER] = 0;
                fields[ASYNC_REQ_UNUSED] = 0;
                fields[ASYNC_REQ_MAGIC] = ASYNC_RESOURCE_MAGIC;
            }
            fields[ASYNC_REQ_ENTRY] = (s32)entry;
            result = (s32)allocation;
            fields[ASYNC_REQ_MANAGER] = (s32)manager;
        } else {
            u8 wantedTagText[5];
            u8 entryTagText[5];
            u8 swap0;
            u8 swap1;
            *(u32 *)wantedTagText = (u32)typeTag;
            swap0 = wantedTagText[0];
            wantedTagText[0] = wantedTagText[3];
            wantedTagText[3] = swap0;
            swap1 = wantedTagText[1];
            wantedTagText[1] = wantedTagText[2];
            wantedTagText[2] = swap1;
            wantedTagText[4] = 0;
            *(u32 *)entryTagText = entry->dataTag;
            swap0 = entryTagText[0];
            entryTagText[0] = entryTagText[3];
            entryTagText[3] = swap0;
            swap1 = entryTagText[1];
            entryTagText[1] = entryTagText[2];
            entryTagText[2] = swap1;
            entryTagText[4] = 0;
            fn_802E30C8(lbl_8032AC08, wantedTagText, entryTagText);
        }
    }
    return result;
}
/* Return the 0x800-aligned size of an open resource: round_up(base + size) - round_down(base). */
extern "C" s32 getResourceSizeAligned(void *handle) {
#define ALIGN_UP 0x7FF        /* round-up addend */
#define ALIGN_MASK 0xFFFFF800 /* ~0x7FF */
    s32 base;
    void *block;
    block = *(void **)((u8 *)handle + 4);
    base = *(s32 *)((u8 *)block + 0x2C) +
           *(s32 *)((u8 *)*(void **)((u8 *)handle + 8) + 0x80);
    return ((base + *(s32 *)((u8 *)block + 0x28) + ALIGN_UP) & ALIGN_MASK) -
           (base & ALIGN_MASK);
#undef ALIGN_MASK
#undef ALIGN_UP
}

extern "C" s32 fn_802E748C(s32, s32, void *);
extern "C" const char lbl_8032AC34[];
extern "C" void fn_8012C720(void *request, s32 buffer, s32 size, s32 fileOffset) {
    /* Start or satisfy a stream read request: queue a disc read unless the file is resident, then copy resident data. */
    void *context;
    void *file = *(void * volatile *)((u8 *)request + 4);
    void *residentFile;
    s32 offset;
    s32 adjustedOffset;
    if ((*(volatile u32 *)((u8 *)file + 0x34) & 8) == 0) {
        residentFile = *(void * volatile *)((u8 *)request + 4);
        context = *(void * volatile *)((u8 *)request + 8);
        adjustedOffset = fileOffset + *(volatile s32 *)((u8 *)residentFile + 0x2C);
        context = (void *)*(volatile s32 *)((u8 *)context + 0x80);
        offset = (s32)context + adjustedOffset;
        context = *(void * volatile *)((u8 *)request + 8);
        *(s32 *)((u8 *)request + 0xC) = ((s32 (*)(s32, s32, s32, s32))fn_802E748C)(
            *(volatile s32 *)((u8 *)context + 0xA4) + offset / 2048, buffer, size, fileOffset);
        *(s32 *)((u8 *)request + 0x10) = buffer + (offset & 0x7FF);
        *(s32 *)((u8 *)request + 0x14) = size;
    } else {
        fn_802E30C8(lbl_8032AC34, file);
        file = *(void * volatile *)((u8 *)request + 4);
        memcpy((void *)buffer, (void *)(*(u32 *)((u8 *)file + 0x3C) + 8), *(u32 *)((u8 *)file + 0x28));
        *(s32 *)((u8 *)request + 0x10) = buffer;
        *(s32 *)((u8 *)request + 0xC) = -1;
        *(s32 *)((u8 *)request + 0x14) = size;
    }
}

#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_8012C7FC(void *request, s32 *outValue) {
    /* Fetch an async resource: drop any live handle, then if loaded data exists compare its CRC
       against the value recorded in the resource entry; return the data on success (optionally
       writing the entry's +0x28 value to outValue), or log a CRC error and reset the request. */
    void *resource;
    s32 result = 0;
    s32 handle;
    void *loadedData;
    handle = *(s32 *)((char *)request + 0xC);
    if (handle != -1 && fn_802E7544(handle)) {
        closeStreamHandle(*(s32 *)((char *)request + 0xC));
        *(s32 *)((char *)request + 0xC) = -1;
    }
    handle = *(s32 *)((char *)request + 0xC);
    if (handle == -1 && (loadedData = *(void **)((char *)request + 0x10)) != 0) {
        resource = *(void **)((char *)request + 4);
        if (*(s32 *)((char *)request + 0x14) < *(s32 *)((char *)resource + 0x28) ||
            *(u32 *)((char *)resource + 0x30) == ((u32 (*)(void *, s32))fn_80132E7C)(loadedData, *(s32 *)((char *)resource + 0x28))) {
            result = *(s32 *)((char *)request + 0x10);
            if (outValue) *outValue = *(s32 *)((char *)resource + 0x28);
        } else {
            fn_802E30C8(lbl_8032AC68, resource);
            fn_8012C720(request, *(s32 *)((char *)request + 0x10) -
                ((*(s32 *)((char *)*(void **)((char *)request + 4) + 0x2C) +
                  *(s32 *)((char *)*(void **)((char *)request + 8) + 0x80)) & 0x7FF),
                *(s32 *)((char *)request + 0x14), 0);
        }
    }
    return result;
}
#pragma pop
extern "C" void closeStreamHandle(s32);
extern "C" u8 lbl_8032AC88[];
/* Cancels the active stream read on a stream request, if any, and clears its handle and data pointer. */
extern "C" void fn_8012C90C(void *request) {
    s32 handle = *(s32 *)((u8 *)request + 0xC);
    if (handle != -1) {
        closeStreamHandle(handle);
        *(s32 *)((u8 *)request + 0xC) = -1;
        *(s32 *)((u8 *)request + 0x10) = 0;
    }
}

/* Releases an active load if present, resets the load request fields, and tags it as freed. */
extern "C" void fn_8012C958(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0xC) != -1) {
        fn_8012C90C(arg0);
    }
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 0x10) = 0;
        *(s32 *)((u8 *)arg0 + 0xC) = -1;
        *(s32 *)((u8 *)arg0 + 4) = 0;
        *(s32 *)((u8 *)arg0 + 8) = 0;
        *(s32 *)((u8 *)arg0 + 0x14) = 0;
        *(u32 *)arg0 = 0x19AFEE2A;
        fn_8012A5E8(arg0);
    }
}

extern "C" void *fn_8012C9C8(void) {
    /* Lazily create the shared AsyncResourceSet pool, then pop a block from it and bump the active-use count on success. */
    if (lbl_8055E00C == 0) {
        void *pool = fn_801284F8(0x20, lbl_8032AC88);
        if (pool != 0)
            pool = fn_8012A13C(pool, lbl_8032AC88, 0x20, 0xD0);
        lbl_8055E010 = (void **)pool;
    }
    void *item = fn_8012A2D8(lbl_8055E010);
    if (item != 0)
        lbl_8055E00C += 1;
    return item;
}
  
  extern "C" void fn_80127464(void);
  extern "C" const char lbl_8032AB78[];
  extern "C" u8 lbl_8055DFF9;
  extern "C" s32 lbl_8055E00C;
  extern "C" void **lbl_8055E010;
/* Return one item to the shared pool tracked by lbl_8055E010 and destroy the pool
 * when the last outstanding reference is released. */
extern "C" void fn_8012CA40(void *arg0) {
    fn_8012A364(lbl_8055E010, arg0);
    if (--lbl_8055E00C == 0) {
        delete (Unk8012A570 *)lbl_8055E010;
        lbl_8055E010 = 0;
    }
}

extern "C" u32 lbl_805599C0;
extern "C" void fn_801282F4(void);
extern "C" void fn_801284F0(void *, void *);
/* Allocates and initializes a 0xD0-byte object, computing an aligned size and fetching its buffer. */
extern "C" s32 fn_8012CAA0(s32 requestedSize, void *source) {
    void *obj = ((void *(*)(s32, void *))fn_8012C9C8)(0xD0, &lbl_805599C0);
    if (obj != 0) {
        s32 zero = 0;
        *(u8 *)((u8 *)obj + 0xB0) = zero;
        *(s32 *)((u8 *)obj + 0xB8) = 1;
        *(s32 *)((u8 *)obj + 0xB4) = -1;
        *(s32 *)((u8 *)obj + 0xCC) = (requestedSize + 0x7FF) & ~0x7FF;
        fn_801282F4();
        fn_801282EC(0x80);
        *(s32 *)((u8 *)obj + 0xC8) =
            ((s32 (*)(void *, s32))fn_801284F0)(source, *(s32 *)((u8 *)obj + 0xCC));
        *(s32 *)((u8 *)obj + 0xC0) = zero;
    }
    return (s32)obj;
}

extern "C" const char lbl_8032AE20[];
#pragma scheduling invalid_target
extern "C" void *fn_8012CB44(void *resourceSet, s32 shouldFree) {
    s32 entryIndex, entryOffset;
    u32 flags;
    void *base, *entry;
    /* Tear down a resource-set object: warn about entries still marked
     * allocated (flag 4), clear each entry's low flag nibble, release the
     * loaded header/data buffers at +0x64 and +0xA0, mark it unloaded, and
     * optionally free the object. */
    if (resourceSet != 0) {
        if (*(u8 *)((char *)resourceSet + 0xAC) != 0) {
            for (entryIndex = 0, entryOffset = 0; entryIndex < *(s32 *)((char *)resourceSet + 0x88); entryIndex++, entryOffset += 0x44) {
                base = *(void **)((char *)resourceSet + 0x60);
                entry = (char *)base + entryOffset;
                flags = *(u32 *)((char *)entry + 0x34);
                if ((flags & 4) != 0) Abend_Panic(lbl_8032AE20, entry);
                base = *(void **)((char *)resourceSet + 0x60);
                entry = (char *)base + entryOffset;
                flags = *(u32 *)((char *)entry + 0x34);
                *(u32 *)((char *)entry + 0x34) = flags & 0xFFFFFFF0;
            }
            base = *(void **)((char *)resourceSet + 0x64);
            if (base != 0) releaseResource(base);
            base = *(void **)((char *)resourceSet + 0xA0);
            if (base != 0) fn_80128660((s32)base);
            *(u8 *)((char *)resourceSet + 0xAC) = 0;
        }
        if (shouldFree > 0) fn_80128668(resourceSet);
    }
    return resourceSet;
}
