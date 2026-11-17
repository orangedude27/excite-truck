// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <math.h>
#include "types.h"

typedef struct {
    f32 x[9];
} Mat3x3;

extern f32 lbl_80562CE8;
extern f32 lbl_80562CEC;
extern void fn_801E35D4(void *dst, void *src);
extern void fn_801E3284(void *out, void *in, s32 arg2);
extern void fn_802C744C(s32 arg0, void *out);
extern int sscanf(const char *, const char *, ...);
extern int stricmp(const char *, const char *);
extern char *strcpy(char *, const char *);
extern char lbl_8055AEB4;
extern const char lbl_8055AEB0[];

void fn_8012A260(void*, unsigned int);
void fn_80128668(void*);
extern char lbl_803398D8[];
extern char lbl_80339904[];
extern void *lbl_8055EA50;
extern void *fn_801284F8(s32, void *);
extern void fn_8012A13C(void *, s32, s32);
void *fn_801E3004();
#pragma push
#pragma small_data off
#pragma pop
int fn_801E2C1C(void *archiveCtx, int index, void **outName, void **outValue) {
#pragma scheduling invalid_target
    /* Get the name and value pointers of the MRJT item at index in the sound
     * archive; returns 1 on success, 0 if no matching group or item exists. */
    int archive = fn_802C6C34();
    int groupCount = *(int *)(archive + 0x10);
    int groupOffset = 0;
    while (groupCount > 0) {
        int group = *(int *)(*(int *)(archive + 0x14) + groupOffset);
        if (*(unsigned int *)group == 0x4D524A54 && index >= 0 && index < *(int *)(group + 8)) {
            int item = group + index * 0x50;
            *outName = (void *)(item + 0xC);
            *outValue = (void *)(item + 0x2C);
            return 1;
        }
        groupOffset += 4;
        groupCount--;
    }
    return 0;
}

#pragma push
#pragma small_data on
extern const char lbl_8055AEB0[3];
#pragma push
#pragma small_data on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
/* Look up an MRJT item's value by name in the sound archive (uses first token unless the requested name contains a space). */
int fn_801E2CCC(void *archiveCtx, const char *requestedName, void **outValue) {
    void *itemValue;
    void *itemName;
    int nameBuf[16];
    BOOL hasSpace;
    int index;
    register int zero;

    zero = 0;
    itemValue = (void *)zero;
    itemName = (void *)zero;
    hasSpace = strchr(requestedName, ' ') != 0;
    for (index = 0; fn_801E2C1C(archiveCtx, index, &itemName, &itemValue) != 0; index++) {
        nameBuf[0] = zero;
        nameBuf[1] = zero;
        nameBuf[2] = zero;
        nameBuf[3] = zero;
        nameBuf[4] = zero;
        nameBuf[5] = zero;
        nameBuf[6] = zero;
        nameBuf[7] = zero;
        nameBuf[8] = zero;
        nameBuf[9] = zero;
        nameBuf[10] = zero;
        nameBuf[11] = zero;
        nameBuf[12] = zero;
        nameBuf[13] = zero;
        nameBuf[14] = zero;
        nameBuf[15] = zero;
        if (!hasSpace)
            sscanf((const char *)itemName, lbl_8055AEB0, (char *)nameBuf);
        else
            strcpy((char *)nameBuf, (const char *)itemName);
        if (stricmp((char *)nameBuf, requestedName) == 0) {
            *outValue = itemValue;
            return 1;
        }
    }
    *outValue = 0;
    return 0;
}
#pragma use_lmw_stmw reset
#pragma scheduling on
#pragma pop

#pragma push
#pragma small_data on
#pragma use_lmw_stmw off
s32 fn_801E2DEC(s32 arg0, s32 arg1, s32 arg2) {
    struct Group {
        int magic;
        int pad;
        int itemCount;
    };
    struct Archive {
        char pad[0x10];
        int groupCount;
        int groups;
    } *archive;
    struct Group *group;
    char *item;
    char name[32];
    int valueBuf[8];
    int groupIndex;
    int groupOffset;
    int index;
    register int zero;
    register int off;

    off = 0;
    zero = 0;
    archive = (struct Archive *)fn_802C6C34();
    groupIndex = zero;
    groupOffset = off;
    while (groupIndex < archive->groupCount) {
        group = (struct Group *)(*(int *)(archive->groups + groupOffset));
        if (group->magic == 0x4D524A54) {
            item = (char *)group + 0xC;
            index = zero;
            while (index < group->itemCount) {
                valueBuf[0] = zero; valueBuf[1] = zero; valueBuf[2] = zero; valueBuf[3] = zero;
                valueBuf[4] = zero; valueBuf[5] = zero; valueBuf[6] = zero; valueBuf[7] = zero;
                if (sscanf(item, (const char *)&lbl_8055AEB4, name, (char *)(void *)valueBuf) >= 1 &&
                    stricmp(name, (const char *)arg0) == 0) {
                    if (arg1 != 0) {
                        strcpy((char *)arg1, (char *)(void *)valueBuf);
                    }
                    return (s32)group + index * 0x50 + 0xC;
                }
                item += 0x50;
                index++;
            }
        }
        groupOffset += 4;
        groupIndex++;
    }
    return 0;
}
#pragma pop

#pragma pop
void fn_801E2F00(void) {
    /* Allocate and initialize the global "Joint Pool" object and store it in lbl_8055EA50. */
    void *jointPool = fn_801284F8(0x20, lbl_803398D8);
    if (jointPool != 0) {
        ((void (*)(void *, void *, s32, s32))fn_8012A13C)(jointPool, lbl_803398D8, 0x128, 0x68);
        *(void **)jointPool = lbl_80339904;
    }
    lbl_8055EA50 = jointPool;
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801E2F68(void) {
    /* Destroy the global Joint Pool object (deleting destructor) and clear its pointer. */
    class Obj {
    public:
        virtual void destroy(int);
    };
    if (lbl_8055EA50 != 0) {
        ((Obj*)lbl_8055EA50)->destroy(1);
    }
    lbl_8055EA50 = 0;
}
#pragma cplusplus reset
#pragma pop
/* Destructor for nw4hbm::snd::MemorySoundArchive: runs base destruction with
 * shouldDelete=0, then if requested frees this object. Returns this. */
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801E2FAC(long self, long shouldDelete) {
    if (self != 0) {
        fn_8012A260((void *)self, 0);
        if (shouldDelete > 0) {
            fn_80128668((void *)self);
        }
    }
    return self;
}

extern void *fn_8012A2D8(void *);
extern s32 fn_8012C33C(char *);
extern s32 fn_802C6FC0(char *, s32, s32);
extern void fn_802E30C8(const char *, ...);
extern char lbl_803398E4[];
#pragma scheduling invalid_target
void *fn_801E3004(s32 arg0, s32 arg1, s32 arg2)
{
  struct Pair
  {
    s32 x[2];
  };
  char path[0x28];
  s32 *result;
  s32 *source;
  f32 *matrix;
  f32 other;
  f32 one;
  result = (s32 *) fn_8012A2D8(lbl_8055EA50);
  result[1] = 0;
  result[0] = -1;
  matrix = (f32 *) (result + 2);
  one = lbl_80562CE8;
  matrix[1] = other;
  matrix[2] = other;
  matrix[3] = other;
  matrix[4] = one;
  matrix[5] = other;
  matrix[6] = other;
  matrix[7] = other;
  matrix[8] = one;
  matrix[9] = other;
  matrix[10] = other;
  matrix[11] = other;
  matrix[12] = one;
  matrix[13] = other;
  matrix[14] = other;
  matrix[15] = other;
  matrix[16] = one;
  matrix[17] = other;
  matrix[18] = other;
  matrix[19] = other;
  matrix[20] = one;
  matrix[21] = other;
  matrix[22] = other;
  matrix[23] = other;
  if (arg0 == (-1))
  {
    return result;
  }
  source = (s32 *) fn_801E2DEC(arg0, arg1, (s32) path);
  if (source != 0)
  {
    ((struct Pair *) (result + 14))[0] = ((struct Pair *) (source + 8))[0];
    ((struct Pair *) (result + 14))[1] = ((struct Pair *) (source + 8))[1];
    ((struct Pair *) (result + 14))[2] = ((struct Pair *) (source + 8))[2];
    ((struct Pair *) (result + 14))[3] = ((struct Pair *) (source + 8))[3];
    result[22] = source[16];
    ((struct Pair *) (result + 23))[0] = ((struct Pair *) (source + 17))[0];
    result[25] = source[19];
    if ((path[0] != 0) && (strchr(path, '.') != 0))
    {
      other = lbl_80562CEC;
      if (fn_8012C33C(path) != 0)
      {
        if (arg2 >= 0)
        {
          result[0] = fn_802C6FC0(path, arg2, 0);
        }
        else
        {
          result[0] = fn_802C6FC0(path, 0, 0);
        }
      }
      else
      {
        fn_802E30C8(lbl_803398E4, arg1, path);
      }
    }
  }
  return result;
  matrix[0] = one;
}
#pragma scheduling on
/* Allocates a child record from *record and stores a back-pointer to record at offset 4. */
void fn_801E31D8(s32 *record) {
    *(s32 **)((u8 *)((void *(*)(s32))fn_801E3004)(*record) + 4) = record;
}

/* Look up an MRJT sound-archive item by name, copying its value to outValue when
 * that buffer is given. Returns 1 if an item with the name exists, 0 otherwise. */
s32 fn_801E320C(s32 name, s32 outValue) {
    extern s32 fn_801E2DEC(s32, s32, s32);
    return fn_801E2DEC(name, outValue, 0) != 0;
}

/* Releases the referenced resource if present, then returns the handle object to its pool. */
void fn_801E323C(s32 *handle) {
    s32 resource = *handle;
    if (resource != -1) {
        fn_802C6CF8(resource);
    }
    fn_8012A364((s32)lbl_8055EA50, handle);
}

#pragma scheduling invalid_target
void fn_801E3284(void *out, void *in, s32 arg2) {
    struct Pair { s32 x[2]; };
    struct Locals {
        union {
            s32 sp8[12];
            struct { s32 pad[9]; s32 sp2c[3]; } overlap;
        } result;
        s32 sp38[9];
        s32 sp5c[3];
        s32 sp68[12];
    } local;
    void *next = *(void **)((u8 *)in + 4);
    if (next != 0) {
        fn_801E3284(local.sp68, next, arg2);
    } else {
        s32 *src = (s32 *)arg2;
        register s32 a11;
        register s32 a10;
        register s32 a9;
        register s32 a8;
        register s32 a7;
        register s32 a6;
        register s32 a5;
        register s32 a4;
        register s32 a3;
        register s32 a2;
        register s32 a1;
        register s32 a0;
        a0=src[0]; a1=src[11]; a2=src[1]; a3=src[2];
        a4=src[3]; a5=src[4]; a6=src[5]; a7=src[6];
        a8=src[7]; a9=src[8]; a10=src[9]; a11=src[10];
        local.sp68[0]=a0; local.sp68[1]=a2; local.sp68[2]=a3; local.sp68[3]=a4;
        local.sp68[4]=a5; local.sp68[5]=a6; local.sp68[6]=a7; local.sp68[7]=a8;
        local.sp68[8]=a9; local.sp68[9]=a10; local.sp68[10]=a11; local.sp68[11]=a1;
    }
    fn_801BFD34(local.sp5c, (u8 *)in + 0x5C, local.sp68);
    fn_80015B20(local.sp38, (u8 *)in + 0x38, local.sp68);
    fn_801BFD34(local.result.overlap.sp2c, (u8 *)in + 0x2C, local.sp38);
    fn_80015B20(local.result.sp8, (u8 *)in + 8, local.sp38);
    *(struct Pair *)((u8 *)out + 0x00) = *(struct Pair *)((u8 *)local.result.sp8 + 0x00);
    *(struct Pair *)((u8 *)out + 0x08) = *(struct Pair *)((u8 *)local.result.sp8 + 0x08);
    *(struct Pair *)((u8 *)out + 0x10) = *(struct Pair *)((u8 *)local.result.sp8 + 0x10);
    *(struct Pair *)((u8 *)out + 0x18) = *(struct Pair *)((u8 *)local.result.sp8 + 0x18);
    ((s32 *)out)[8] = local.result.sp8[8];
    *(struct Pair *)((u8 *)out + 0x24) = *(struct Pair *)((u8 *)local.result.sp8 + 0x24);
    ((s32 *)out)[11] = local.result.sp8[11];
}
#pragma scheduling on
void fn_801E33E4(void *outTransform, void *node) {
    /* Compute a node's world transform from the identity matrix (3x3 rotation + translation). */
    f32 identity[12];
    identity[0] = 1.0f;
    identity[1] = 0.0f;
    identity[2] = 0.0f;
    identity[3] = 0.0f;
    identity[4] = 1.0f;
    identity[5] = 0.0f;
    identity[6] = 0.0f;
    identity[7] = 0.0f;
    identity[8] = 1.0f;
    identity[9] = 0.0f;
    identity[10] = 0.0f;
    identity[11] = 0.0f;
    fn_801E3284(outTransform, node, (s32)identity);
}
void fn_801E3440(void *outTranslation) {
    /* Get the world translation from fn_801E3284 and copy its XYZ components. */
    f32 sp[12];
    ((void (*)(void *))fn_801E3284)(sp);
    *(f32 *)((u8 *)outTranslation + 0) = sp[9];
    *(f32 *)((u8 *)outTranslation + 4) = sp[10];
    *(f32 *)((u8 *)outTranslation + 8) = sp[11];
}

#pragma push
#pragma small_data off
/* Compute a node's world-space translation from an identity local transform. */
void fn_801E3488(void *outTranslation, void *node) {
    f32 identity[12];
    identity[0] = 1.0f;
    identity[1] = 0.0f;
    identity[2] = 0.0f;
    identity[3] = 0.0f;
    identity[4] = 1.0f;
    identity[5] = 0.0f;
    identity[6] = 0.0f;
    identity[7] = 0.0f;
    identity[8] = 1.0f;
    identity[9] = 0.0f;
    identity[10] = 0.0f;
    identity[11] = 0.0f;
    ((void (*)(void *, void *, f32 *))fn_801E3440)(outTranslation, node, identity);
}

#pragma push
#pragma processor 750
void fn_801E34E4(s32 *arg0, s32 arg1) {
    s32 sp8[12];

    if (*arg0 != -1) {
        fn_801E3284(&sp8[0], arg0, arg1);
        fn_802C744C(*arg0, &sp8[0]);
    }
}
#pragma pop
/* Read the s32 value pointed to by p (getter for handle-backed integer fields). */
s32 fn_801E3534(s32 *p) {
    return *p;
}

#pragma push
#pragma processor 750
#pragma opt_propagation off
void fn_801E353C(s32 transformObj, f32 angle) {
    /* Give the transform object (3x3 matrix at +0x08, translation at +0x2C) a
     * pure rotation by angle about the Z axis, [c s 0; -s c 0; 0 0 1], with
     * zero translation; fn_801E35D4 installs the matrix and clears the
     * translation. */
    f32 c;
    f32 s;
    Mat3x3 rot;
    Mat3x3 *m = &rot;
    c = (f32)((double (*)(float))cos)(angle);
    s = (f32)((double (*)(float))sin)(angle);
    m->x[0] = c;
    m->x[1] = s;
    m->x[2] = lbl_80562CEC; /* 0.0f */
    m->x[3] = -s;
    m->x[4] = c;
    m->x[5] = lbl_80562CEC; /* 0.0f */
    m->x[6] = lbl_80562CEC; /* 0.0f */
    m->x[7] = lbl_80562CEC; /* 0.0f */
    m->x[8] = lbl_80562CE8; /* 1.0f */
    fn_801E35D4((void *)transformObj, m);
}
#pragma pop
/* Copy 9 words from src to dst+0x8..0x28 and set dst+0x2C..0x34 to zero (lbl_80562CEC). */
void fn_801E35D4(void *arg0, void *arg1) {
    f32 zero = lbl_80562CEC;
    s32 *srcWords = (s32 *)arg1;
    s32 *dstWords = (s32 *)arg0;
    f32 *dstFloats = (f32 *)((u8 *)arg0 + 0x2C);
    s32 word8, word7, word6, word5, word4, word3, word2, word1, word0;
    word0 = srcWords[0];
    word1 = srcWords[1];
    word2 = srcWords[2];
    word3 = srcWords[3];
    word4 = srcWords[4];
    word5 = srcWords[5];
    word6 = srcWords[6];
    word7 = srcWords[7];
    word8 = srcWords[8];
    dstFloats[0] = zero;
    dstFloats[1] = zero;
    dstFloats[2] = zero;
    dstWords[2] = word0;
    dstWords[3] = word1;
    dstWords[4] = word2;
    dstWords[5] = word3;
    dstWords[6] = word4;
    dstWords[7] = word5;
    dstWords[8] = word6;
    dstWords[9] = word7;
    dstWords[10] = word8;
}

#pragma push
#pragma small_data off
float *fn_801E3630(void *handle) {
    /* Model-resource helper: return the float vector held at +0x5C of the handle (e.g. a node position). */
    return (float *)((char *)handle + 0x5C);
}

