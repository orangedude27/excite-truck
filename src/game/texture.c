// texture — textures + SimpleHeap ("texture: create %s in scene").
// Recovered TU window 0x802CA0E4..0x802CCB84+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CCB84 (+ .ctors slot 0x802ED5AC) remains in
// auto/text_802CCB84_.c pending a promotion pass.
#include <macros.h>
extern char lbl_8034BA98[];
extern void fn_802E317C(const char *, ...);
extern char lbl_8034B538[];
extern char texMsgBadExtractionName[];
extern void *jumptable_8034B794[];
extern char lbl_8034B618[];
extern int defaultTextureName;
extern int fn_802C90E0(void);
extern int fn_802D8E9C(void *, unsigned int);
extern int lbl_8055D038;
extern int lbl_8055D040;
extern int fn_8012850C(int, int *);
extern void fn_802CB424(void);
extern void fn_802E30C8(const char *, ...);
extern int fn_802D92B8(int);
extern int lbl_8055D03C;
extern char lbl_8034B5F0[];
void fn_802CAC54(int);
void fn_802CB6B4(void);
int fn_80128670(int);
int fn_802CA2A8(void *, int, int);
int fn_8012C5B8(void *, int, int *);
int fn_8012C6F0(void);
int fn_8012C958(int);

#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
DECL_SECTION(".sdata") extern int lbl_8055FCB4;
DECL_SECTION(".sdata") extern int lbl_8055FCB8;
void fn_802D8FB4(void);
void fn_802D9160(int, int);
void fn_802DBDE8(int, int);
#pragma small_data off
#pragma pop

extern char lbl_8055D07D;
extern float lbl_80564F30;
#pragma scheduling invalid_target
extern void fn_802CAC28(int, int);
extern void *fn_801284F8(int, void *);
extern int lbl_8055D080;
extern void fn_801282EC(int);
extern void fn_801282F4(void);
/* Allocate and zero the 512-entry texture-slot table (lbl_8055FCB0), then register the built-in "null" and "gclmap" textures; on success select the lightmap and bind its GPU handle. */ /* Initialize the 0x200-entry texture record table, load the null and lightmap textures, and select the lightmap. */ void fn_802CA0E4(void) {
    char *messages = lbl_8034B538;
    int recordOffset;
    int slotIndex;
    int textureId;
    register int lightmapEntry;

    lbl_8055FCB0 = fn_8012850C(0x9800, &lbl_8055D040);
    fn_802CB424();
    slotIndex = 0;
    recordOffset = 0;
    do {
        memset((void *)(lbl_8055FCB0 + recordOffset), 0, 0x4C);
        slotIndex++;
        recordOffset += 0x4C;
    } while (slotIndex < 0x200);
    lbl_8055FCB8 = -2;
    textureId = ((int (*)(int, int))fn_802CAC28)(lbl_8055D038, 0);
    lbl_8055FCB4 = textureId;
    if (textureId == -1)
        fn_802E317C(messages + 0x40, lbl_8055D038);
    textureId = ((int (*)(int, int))fn_802CAC28)((int)(messages + 0x60), 0);
    lbl_8055D03C = textureId;
    if (textureId != -1) {
        fn_802E30C8(messages + 0x6C);
        lightmapEntry = lbl_8055FCB0;
        lightmapEntry += lbl_8055D03C * 0x4C;
        fn_802D92B8(*(int *)(lightmapEntry + 0x28));
        return;
    }
    fn_802E30C8(messages + 0x88);
}

/* Shut down the texture system: release the built-in texture handles, report any of the 512 texture slots still in use, and free the slot table. */ void fn_802CA1E0(void) {
    /* Texture system shutdown: release active texture handles, warn for any of the
       512 0x4C-byte texture slots still in use, then free the texture pool. */
    int byteOffset;
    int slotIndex;
    if (lbl_8055D03C != -1) {
        fn_802CAC54(lbl_8055D03C);
        lbl_8055D03C = -1;
    }
    fn_802CAC54(lbl_8055FCB4);
    lbl_8055FCB4 = -1;
    slotIndex = 0;
    byteOffset = 0;
    do {
        if (*(int *)(lbl_8055FCB0 + byteOffset) != 0)
            fn_802E317C(lbl_8034B5F0, slotIndex, lbl_8055FCB0 + byteOffset + 4);
        slotIndex++;
        byteOffset += 0x4C;
    } while (slotIndex < 0x200);
    fn_802CB6B4();
    fn_80128670(lbl_8055FCB0);
    lbl_8055FCB0 = 0;
}
#pragma scheduling on
/* Return the texture id (field +0x28) of the given 0x4C-byte texture slot. */
int fn_802CA294(int textureSlot) {
    int offset = textureSlot * 0x4C;
    int *slots = (int *)lbl_8055FCB0;
    return *(int *)((char *)slots + offset + 0x28);
}

extern char *fn_80029004(char *, int); /* strchr */
extern char lbl_8055D048;              /* ".tm0": suffix of a texture archive member's name */
/* Build a texture archive name into dst: bounded-copy srcName, truncate at its '.' extension, then append the ".tm0" suffix; returns dst. */ int fn_802CA2A8(void *dst, int capacity, int srcName) {
    /* Build a texture archive name: copy the source name into the caller's
       buffer, cut it at its '.' extension, then append the ".tm0" suffix. */
    int remaining = capacity;
    char *name = (char *)dst;
    const char *src = (const char *)srcName;
    const char *suffix;
    char *cursor;
    char *dot;

    {
        int copyCapacity = capacity;
        char *copyDst = name;
        while ((signed char)(*copyDst++ = *src++) != 0) {
            if (--copyCapacity <= 0) {
                copyDst[-1] = 0;
                break;
            }
        }
    }

    dot = fn_80029004(name, '.'); /* strchr: cut the name at its extension */
    *dot = 0;
    suffix = &lbl_8055D048;
    cursor = name;
    while ((signed char)*cursor != 0) {
        --remaining;
        ++cursor;
    }
    if (remaining > 0) {
        while ((signed char)(*cursor++ = *suffix++) != 0) {
            if (--remaining <= 0) {
                cursor[-1] = 0;
                break;
            }
        }
    }
    return (int)name;
}

/* Get the size of the "TEX " resource for the named texture, or 0 if absent. */
int getTextureResourceSize(int textureName) {
#define BuildTextureArchiveName fn_802CA2A8
#define OpenResource fn_8012C5B8
#define GetResourceSize fn_8012C6F0
#define CloseResource fn_8012C958
    char archiveName[0x20];
    int resourceHandleOut;
    int resourceSize;
    int resourceHandle;
    resourceSize = 0;
    BuildTextureArchiveName(archiveName, 0x20, textureName);
    resourceHandle = OpenResource(archiveName, 0x54455820, &resourceHandleOut);
    if (resourceHandle != 0) {
        resourceSize = GetResourceSize();
        CloseResource(resourceHandle);
    }
    return resourceSize;
#undef BuildTextureArchiveName
#undef OpenResource
#undef GetResourceSize
#undef CloseResource
}

#pragma use_lmw_stmw off
int fn_802CA3F4(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    register unsigned char *src = (unsigned char *)arg1;
    register int value = arg2;
    register int mode1 = arg3;
    register int mode2 = arg4;
    register int *dst = (int *)arg0;
    unsigned char c5, c12, c4, c7, c6, c10;
    unsigned short h12, h0, h2;
    int ptr14;
    int flags;

    memset(arg0, 0, 0x34);
    c5 = src[5];
    c12 = src[0xB];
    c4 = src[4];
    c7 = src[7];
    c6 = src[6];
    h12 = *(unsigned short *)(src + 0xC);
    c10 = src[0xA];
    h0 = *(unsigned short *)src;
    h2 = *(unsigned short *)(src + 2);
    ptr14 = *(int *)(src + 0x14);
    flags = c12 & 1;
    dst[2] = flags;
    dst[0] = c5 & 0x7F;
    dst[5] = c7;
    dst[4] = c6;
    dst[3] = h12;
    dst[6] = c12;
    *(unsigned char *)((char *)arg0 + 0x1C) = c10;
    dst[1] = value;
    dst[8] = (signed char)c4;
    dst[9] = h0;
    dst[10] = h2;
    dst[11] = ptr14;
    dst[12] = mode1;
    if (mode2 == 2) {
        flags |= 1;
        dst[2] = flags;
    } else if (mode2 == 6) {
        flags |= 2;
        dst[2] = flags;
    } else if (mode2 == 5) {
        flags |= 4;
        dst[2] = flags;
    }
}
#pragma dont_inline on
// Creates a texture from a descriptor and name, logging creation to the current scene when needed.
/* Build a texture-creation request from a descriptor and name, log it in the scene unless it is the default name, then create the texture. */ int fn_802CA4E0(int textureDesc, int textureName, int isRenderTarget, int createParam, int param4) {
    char request[0x34];
    if (fn_802C90E0() == 0 && (unsigned int)textureName != (unsigned int)defaultTextureName)
        fn_802E30C8(lbl_8034B618, textureName);
    fn_802CA3F4(request, textureDesc, isRenderTarget == 1 ? 3 : 1, createParam, param4);
    return fn_802D8E9C(request, textureName);
}
#pragma dont_inline reset
#pragma use_lmw_stmw on

extern void fn_802D8DCC(void *, int);
static inline void swap16_802CA57C(unsigned char *p) {
    unsigned char t = p[0];
    p[0] = p[1];
    p[1] = t;
}
static inline void swap32_802CA57C(unsigned char *p) {
    unsigned char t = p[0];
    p[0] = p[3];
    p[3] = t;
    t = p[1];
    p[1] = p[2];
    p[2] = t;
}
#pragma push
#pragma auto_inline off
/* Byte-swaps and relocates a resource header in place once, then builds a context and processes it. */
/* Byte-swaps and relocates a loaded "TEX " resource header in place once (guarded by the 0x80 flag at +5), then builds a texture request from it and dispatches it to fn_802D8DCC. */ void fn_802CA57C(void *texData, int texturePath, int value, int flags) {
    unsigned char *header = (unsigned char *)texData;
    char request[0x34];
    if ((header[5] & 0x80) == 0) {
        swap32_802CA57C(header + 0x14);
        swap16_802CA57C(header + 0);
        swap16_802CA57C(header + 2);
        swap16_802CA57C(header + 0xC);
        *(int *)(header + 0x14) = (int)((unsigned char *)texData + *(int *)(header + 0x14));
        fn_802CA3F4(request, (int)texData, 0, value, flags);
        fn_802D8DCC(request, texturePath);
        header[5] |= 0x80;
    }
}
#pragma pop
extern int fn_8012C370(const char *, int *, int *, signed char *, unsigned char *);
extern char lbl_8034B634[];
extern char lbl_8034B658[];
extern void fn_802CA57C(void *, int, int, int);
#pragma scheduling invalid_target
/* Loads a "TEX " texture resource by path (texturePath), verifies 128-byte alignment
   and version 15 (0xF), and endian-swaps/initializes the loaded header when newly
   loaded (swapEndian != 0). */
/* Load a "TEX " texture resource by path, verify 128-byte alignment and version 15, and byte-swap/initialize the loaded header when newly loaded. */ int fn_802CA658(int texturePath, int flags) {
    unsigned int version;
    int dataSize;
    signed char newlyLoaded = 0;
    unsigned char swapEndian = 0;
    int textureData;
    textureData = ((int (*)(int, int, unsigned int *, int *, signed char *, unsigned char *))fn_8012C370)(texturePath, 0x54455820, &version, &dataSize, &newlyLoaded, &swapEndian);
    if (textureData != 0) {
        if ((textureData & 0x7F) != 0)
            fn_802E317C(lbl_8034B634, texturePath, textureData);
        if (version != 0xF)
            fn_802E317C(lbl_8034B658, texturePath, version);
        if (swapEndian != 0)
            fn_802CA57C((void *)textureData, texturePath, 0, flags);
    }
    return textureData;
}
#pragma scheduling on
    /* Return the MMT_* material-type name string for a material type id (15 names, plus "<unknown>" for out-of-range ids). */
    char *fn_802CA72C(unsigned int matType) {
    char *nameTable = lbl_8034B538;
    switch (matType) {
    case 0: return nameTable + 0x140;
    case 1: return nameTable + 0x150;
    case 2: return nameTable + 0x174;
    case 3: return nameTable + 0x180;
    case 4: return nameTable + 0x190;
    case 5: return nameTable + 0x1A0;
    case 6: return nameTable + 0x1B4;
    case 7: return nameTable + 0x1C0;
    case 8: return nameTable + 0x1CC;
    case 9: return nameTable + 0x1E0;
    case 10: return nameTable + 0x1F0;
    case 11: return nameTable + 0x20C;
    case 12: return nameTable + 0x21C;
    case 13: return nameTable + 0x228;
    case 14: return nameTable + 0x244;
    default: return nameTable + 0x250;
    }
}

#pragma dont_inline fn_802CA7D4
/* Default texture-compatibility callback used by fn_802CA898 (called through an
 * int(*)(int,int,int) cast): always reports true (1), so a matched slot's state
 * is never reset. */
char fn_802CA7D4(void) { return 1; }
/* True when the path's first byte is '*' (0x2A), marking a special extraction name. */
int texIsExtractionName(const unsigned char *path) { return ((signed char)*path - 0x2A) == 0; }

#pragma dont_inline fn_802CA7F4
/* Return nonzero when the path string contains a '/' separator. */
int fn_802CA7F4(const char *path) { return strchr(path, '/') != 0; }

/* Returns the trailing name after '/' for a '*'-prefixed extraction path (warning if the separator is missing); otherwise returns the path unchanged. */
int texGetExtractionName(int path) {
    int slashPtr;
    if (((int (*)(const unsigned char *))texIsExtractionName)((const unsigned char *)path) != 0) {
        slashPtr = (int)strchr((char *)path, 0x2F);
        if (slashPtr == 0)
            fn_802E317C(texMsgBadExtractionName, path);
        return slashPtr + 1;
    }
    return path;
}

extern int texGetExtractionName(int);
extern void fn_802CA57C(void *, int, int, int);
extern int fn_802CA4E0(int, int, int, int, int);
extern int stricmp(const char *, const char *);
extern unsigned int strlen(const char *);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
int fn_802CA898(int arg0, int arg1, int arg2, int arg3) {
    struct Entry {
        int refCount;
        char name[0x20];
        int type;
        int handle;
        int resource;
        unsigned char flag;
        unsigned char pad[3];
        int arg3;
        int unk38;
        int size;
        int unk40;
        int unk44;
        int unk48;
    };
    struct Entry *entry;
    unsigned strings;
    unsigned char first;
    int best;
    int index;
    int path_value;
    int size;
    char *src;
    int count;
    char *dst;
    int c;
    int flag;

    path_value = arg0;
    strings = (int)lbl_8034B538;
    if (strlen((char *)path_value) >= 0x10 &&
        ((int (*)(const char *))texIsExtractionName)((char *)path_value) == 0 &&
        fn_802CA7F4((char *)path_value) == 0) {
        fn_802E317C((const char *)(strings + 0x2B8), (char *)path_value, strlen((char *)path_value), 0x10);
    }
    if (strlen((char *)path_value) >= 0x20)
        fn_802E317C((const char *)(strings + 0x2E0), (char *)path_value, strlen((char *)path_value), 0x20);
    if ((signed char)*(char *)path_value == 0 && arg3 == 1)
        path_value = (int)(strings + 0x30C);

    first = *(unsigned char *)path_value;
    flag = arg2 != 0;
    if ((signed char)first == 0 || (signed char)first == '.' || (signed char)first == '#')
        return -1;

    best = -1;
    for (index = 0; index < 0x200; index++) {
        entry = &((struct Entry *)lbl_8055FCB0)[index];
        if (entry->refCount > 0) {
            if (stricmp(entry->name, (char *)texGetExtractionName((int)(char *)path_value)) == 0 &&
                entry->type == arg1 &&
                flag == 0) {
                if (((int (*)(int, int, int))fn_802CA7D4)((int)(char *)path_value, arg3, ((struct Entry *)lbl_8055FCB0)[index].arg3) == 0) {
                    fn_802E30C8((const char *)(strings + 0x318), (char *)path_value);
                    ((struct Entry *)lbl_8055FCB0)[index].size = 0;
                    ((struct Entry *)lbl_8055FCB0)[index].arg3 = 0xE;
                }
                entry->refCount++;
                return index;
            }
        } else if (best < 0) {
            best = index;
        }
    }

    if (best < 0)
        fn_802E317C((const char *)(strings + 0x33C), (char *)path_value);

    if (flag == 0) {
        arg2 = fn_802CA658((int)(char *)path_value, arg3);
        if (arg2 == 0) {
            fn_802E30C8((const char *)(strings + 0x354), (char *)path_value);
            arg2 = fn_802CA658((int)(strings + 0x370), 0xE);
        }
    } else {
        ((int (*)(int, int, int, int))fn_802CA57C)(arg2, (int)(char *)path_value, 0, arg3);
    }
    if (arg2 == 0)
        return -1;

    entry = &((struct Entry *)lbl_8055FCB0)[best];
    entry->flag = flag;
    entry->refCount = 1;
    entry->unk48 = 0;
    entry->type = arg1;

    if (((int (*)(const char *))texIsExtractionName)((char *)path_value) == 0) {
        src = (char *)path_value;
        dst = entry->name;
        count = 0x20;
        goto copy1_body;
copy1_check:
        count--;
        if (count > 0)
            goto copy1_body;
        dst[-1] = 0;
        goto copy1_done;
copy1_body:
        c = (unsigned char)*src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto copy1_check;
copy1_done:
        if (flag != 0)
            size = 0;
        else
            size = getTextureResourceSize((int)(char *)path_value);
        entry->size = size;
        if (size < 0x3E80)
            entry->size = 0;
    } else {
        fn_802E30C8((const char *)(strings + 0x380), (char *)path_value);
        src = (char *)texGetExtractionName((int)(char *)path_value);
        dst = entry->name;
        count = 0x20;
        goto copy2_body;
copy2_check:
        count--;
        if (count > 0)
            goto copy2_body;
        dst[-1] = 0;
        goto copy2_done;
copy2_body:
        c = (unsigned char)*src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto copy2_check;
copy2_done:
        entry->size = 0;
    }

    entry->unk40 = 0;
    entry->unk44 = 0;
    entry->resource = arg2;
    entry->arg3 = arg3;
    entry->handle = fn_802CA4E0(arg2, (int)(char *)path_value, 0, 0, arg3);
    lbl_8055FCB8 = -2;
    return best;
}
#pragma dont_inline reset
#pragma scheduling on
#pragma use_lmw_stmw reset
void fn_802CAC28(int name, int sceneId) {
    /* Register a named texture with a scene id and fixed type 0xE, with no backing resource. */
    fn_802CA898(name, sceneId, 0, 0xE);
}

void fn_802CAC34(int name, int resource) {
    /* Register a named texture backed by an existing resource handle, with no scene id and fixed type 0xE. */
    fn_802CA898(name, 0, resource, 0xE);
}

void fn_802CAC44(int name, int type) {
    /* Register a named texture with no scene id and no backing resource, using type as its category. */
    fn_802CA898(name, 0, 0, type);
}

extern void fn_8012C4D8(void *);
extern void fn_802CB82C(int);
extern void fn_802CAD28(int);
extern char lbl_8034B8E0[];
#pragma opt_strength_reduction off
void fn_802CAC54(int arg0)
{
  int *entry;
  int offset;
  char *base;
  if (arg0 == (-1))
  {
    return;
  }
  if ((arg0 >= 0) && (arg0 < 0x200))
  {
    offset = arg0 * 0x4C;
    base = (char *) lbl_8055FCB0;
    entry = (int *) (base + offset);
    if (entry[0] <= 0)
    {
      fn_802E317C(lbl_8034B8E0, (base + offset) + 4);
    }
  }
  offset = arg0 * ((long) 0x4C);
  entry = (int *) (((char *) lbl_8055FCB0) + offset);
  if ((*((unsigned char *) (((char *) entry) + 0x30))) != 0)
  {
    fn_802CAD28(arg0);
    return;
  }
  entry[0]--;
  if ((entry[0] == 0) && (entry[0x2C / 4] != 0))
  {
    fn_802CB82C(arg0);
    fn_8012C4D8((void *) entry[0x2C / 4]);
    entry[0x2C / 4] = 0;
    ((void (*)(int)) fn_802D8FB4)(entry[0x28 / 4]);
  }
}
void fn_802CAD28(int slotIndex) {
    int *slot;
    int refCount;
#define gTextureSlots lbl_8055FCB0
    /* Release a texture slot reference; on the last one, drop its resource handle and GPU texture object. */
    if (slotIndex == -1)
        return;
    slot = (int *)(gTextureSlots + slotIndex * 0x4C);
    refCount = --slot[0];
    if (refCount != 0)
        return;
    if (slot[0x2C / 4] == 0)
        return;
    slot[0x2C / 4] = 0;
    ((void (*)(int))fn_802D8FB4)(slot[0x28 / 4]);
#undef gTextureSlots
}

/* Invalidate the texture module's "last bound slot" cache by setting it to -2,
   so the next fn_802CAD74 call rebinds even if the slot number is unchanged. */
void fn_802CAD68(void) {
#define gLastBoundTextureSlot lbl_8055FCB8
    gLastBoundTextureSlot = -2;
#undef gLastBoundTextureSlot
}

#pragma dont_inline fn_802CAD74
void fn_802CAD74(register int slotIndex) {
    /* Select a texture slot as active: on a change, remember it (or restore the saved default slot on -1),
       then bump the slot's use counter at +0x48 and bind its texture at +0x40 (fallback +0x28) to GX. */
    if (slotIndex == lbl_8055FCB8)
        return;
    lbl_8055FCB8 = slotIndex;
    if (slotIndex == -1) {
        ((void (*)(int))fn_802CAD74)(*(volatile int *)&lbl_8055FCB4);
        return;
    }
    {
        int *slot = (int *)(lbl_8055FCB0 + slotIndex * 0x4C);
        int texHandle;
        slot[0x48 / 4]++;
        texHandle = slot[0x40 / 4];
        if (texHandle != 0)
            fn_802D9160(texHandle, 0);
        else
            fn_802D9160(slot[0x28 / 4], 0);
    }
}
/* Bind the texture of slot textureSlot (no texture for -1) to unitIndex via fn_802DBDE8. */
void fn_802CADD0(int textureSlot, int unitIndex) {
    int slotOffset;
    char *slots;
    if (textureSlot == -1) {
        fn_802DBDE8(unitIndex, 0);
    } else {
        slotOffset = textureSlot * 0x4C;
        slots = (char *)lbl_8055FCB0;
        fn_802DBDE8(unitIndex, *(int *)(slots + slotOffset + 0x28));
    }
}

int TextureSlot_isLoaded(int slotIndex) {
    /* Return whether slotIndex names a valid texture slot whose texture is loaded. */
    int inUse = 0;
    if (slotIndex >= 0 && slotIndex < 0x200 &&
        *(int *)(lbl_8055FCB0 + slotIndex * 0x4C) > 0) {
        inUse = 1;
    }
    return inUse;
}

extern int fn_802C90E0(void);
extern void fn_802E30C8(const char *, ...);
extern int fn_802CA3F4(void *, int, int, int, int);
extern int fn_802D8E9C(void *, unsigned int);
extern char lbl_8034B618[];
extern char lbl_8034B538[];
extern void *jumptable_8034B794[];
extern int TextureSlot_isLoaded(int);
extern int lbl_8055FCB0;
extern char textureNullName[];
extern char invalidTextureName[];
/* Returns the name of a texture slot: "TEXTURE_NULL" for index -1, "(INVALID)" if not loaded, otherwise the slot's stored name. */
char *getTextureSlotName(int textureIndex) {
    int slotOffset;
    char *slot;
    if (textureIndex == -1)
        return textureNullName;
    if (!((int (*)(int))TextureSlot_isLoaded)(textureIndex))
        return invalidTextureName;
    slotOffset = textureIndex * 0x4C;
    slot = (char *)lbl_8055FCB0 + slotOffset;
    return slot + 4;
}
#pragma dont_inline on
/* Copy a texture name into the given slot's 0x20-byte name buffer, truncating to
 * 0x1F characters and always null-terminating. Does nothing for an invalid or
 * unloaded slot. */
void fn_802CAE98(int slotIndex, char *srcName) {
    int charsLeft;
    char *nameDst;
    unsigned char ch;

    if (!((int (*)(int))TextureSlot_isLoaded)(slotIndex))
        return;
    nameDst = (char *)lbl_8055FCB0 + slotIndex * 0x4C + 4;
    charsLeft = 0x20;
    goto copy;
count_check:
    if (--charsLeft > 0)
        goto copy;
    nameDst[-1] = 0;
    goto done;
copy:
    ch = *srcName++;
    *nameDst++ = ch;
    if ((signed char)ch != 0)
        goto count_check;
    goto done;
done:
    ;
}

/* Sets the filter/wrap mode bytes at +8/+9 of a valid texture slot's loaded resource. */
void TextureSlot_setModes(int textureSlot, signed char mode8, signed char mode9) {
#define TextureSlot_isValid TextureSlot_isLoaded
#define gTextureSlots lbl_8055FCB0
    int slotOffset;
    int textureResource;

    if (TextureSlot_isValid(textureSlot)) {
        slotOffset = textureSlot * 0x4C;
        textureResource = *(int *)((char *)gTextureSlots + slotOffset + 0x2C);
        *(signed char *)(textureResource + 8) = mode8;
        textureResource = *(int *)((char *)gTextureSlots + slotOffset + 0x2C);
        *(signed char *)(textureResource + 9) = mode9;
    }
#undef TextureSlot_isValid
#undef gTextureSlots
}

#pragma dont_inline reset
int fn_802DB2C0(int);
void fn_802CA57C(void *, int, int, int);
int fn_802CA4E0(int, int, int, int, int);
int fn_802CA898(int, int, int, int);
#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
#pragma small_data off
#pragma pop
void fn_802D8FB4(void);
extern int defaultTextureName;
extern int mip0Path;
#pragma scheduling invalid_target
#pragma dont_inline loadMipTexture
int loadMipTexture(void *loadedBlock, void *createParam, void *relocateBase) {
    /* Load a mipmapped texture: byte-swap/relocate the loaded descriptor under the "mip0" path, then create it with the default "mip-0" name. */
    register int data = (int)loadedBlock;
    register int base = (int)relocateBase;
    register int param = (int)createParam;
    ((int (*)(int, int, int, int))fn_802CA57C)(data, (int)&mip0Path, 0, base);
    return fn_802CA4E0(data, defaultTextureName, 0, param, base);
}
#pragma scheduling on
void fn_802CB3F4(void) {
#define releaseTexture fn_802D8FB4
    /* Tail-forward the caller's texture handle to the texture-object releaser. */
    releaseTexture();
#undef releaseTexture
}

void fn_802CB3F8(void) {
    /* Empty no-op callback used throughout the texture module (invoked with two arguments
     * via casts); it intentionally does nothing. */
}

DECL_SECTION(".sdata") extern char lbl_8055FCBC[];
#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
#pragma small_data off
#pragma pop
extern float lbl_80564F40; /* 1.0f: floor for the scale fn_802CC550 weighs a slot by */
extern float lbl_80564F44; /* 1e-5f: weight a slot is raised to when it is just used */
extern float lbl_8055FCC4; /* texel scale, set by fn_802CC518 */
      extern unsigned short lbl_8055FCA8; /* expected value (0x100) compared against a texture's referenced-object field at +0xC */
int fn_802CAF8C(int slot) {
    /* Return nonzero when the u16 at +0xC of the object referenced by texture slot `slot` differs from the expected value; slot -1 yields 0. */
    int *slotEntry;
    unsigned short expected;
    if (slot == -1)
        return 0;
    slotEntry = (int *)(slot * 0x4C + lbl_8055FCB0);
    expected = lbl_8055FCA8;
    return *(unsigned short *)(*(slotEntry + 11) + 0xC) != expected;
}
void fn_802CC550(int, float, float);
int fn_802CB274(int textureSlot) {
    /* Forward a texture slot's +0x28 handle to the no-op trace hook fn_802DB2C0. */
    int *entry = (int *)(lbl_8055FCB0 + textureSlot * 0x4C);
    return fn_802DB2C0(entry[0x28 / 4]);
}

int fn_802DB2C4(int);
int fn_802CB288(int textureSlot) {
    /* Forward a texture slot's +0x28 handle to the no-op trace hook fn_802DB2C4. */
    int *entry = (int *)(lbl_8055FCB0 + textureSlot * 0x4C);
    return fn_802DB2C4(entry[0x28 / 4]);
}

extern void fn_802D93E8(int);
extern void fn_802D9418(void);
extern int lbl_8055D06C;
void fn_802CB29C(int textureIndex) {
    /* Select a texture for the active drawing context, or clear the selection for invalid indices. */
    if (textureIndex != -1 && textureIndex != -2) {
        int offset = textureIndex * 0x4C;
        int *entry = (int *)(lbl_8055FCB0 + offset);
        fn_802D93E8(entry[0x28 / 4]);
        lbl_8055D06C = textureIndex;
        return;
    }
    fn_802D9418();
    lbl_8055D06C = -2;
}

#pragma use_lmw_stmw off
extern int lbl_8055D070;
/* Allocate and initialize a 0x18-byte texture descriptor with the given dimensions, format, mip count, texture id and creation flags. */ int fn_802CB2FC(int width, int height, int format, unsigned char mipCount, unsigned short texId, unsigned char createFlags) {
    /* Allocate and initialize a 0x18-byte texture/entry record with the given fields and defaults. */
    unsigned char *desc = (unsigned char *)fn_801284F8(0x18, &lbl_8055D070);
    *(unsigned short *)(desc + 0) = width;
    *(unsigned short *)(desc + 2) = height;
    desc[4] = format;
    desc[5] = mipCount;
    *(unsigned short *)(desc + 0xC) = texId;
    desc[6] = 0;
    desc[8] = 5;
    desc[9] = 0x32;
    desc[7] = createFlags;
    desc[0xB] = 2;
    *(int *)(desc + 0x14) = 0;
    desc[0xA] = 0;
    return (int)desc;
}

/* Return a texture slot's filter byte (+8 of its resource), or 5 for no texture. */
char fn_802CAFC8(int textureSlot) {
    int slotOffset;
    char *slots;
    if (textureSlot == -1)
        return 5;
    slotOffset = textureSlot * 0x4C;
    slots = (char *)lbl_8055FCB0;
    return *(char *)(*(int *)(slots + slotOffset + 0x2C) + 8);
}

/* Return a texture slot's mode byte (+9 of its resource), or 0x32 for no texture. */
char fn_802CAFF0(int textureSlot) {
    int slotOffset;
    char *slots;
    if (textureSlot == -1)
        return 0x32;
    slotOffset = textureSlot * 0x4C;
    slots = (char *)lbl_8055FCB0;
    return *(char *)(*(int *)(slots + slotOffset + 0x2C) + 9);
}

extern char lbl_8034B940[];
// The texture slot table: 0x200 slots of texSlotSize bytes, allocated as one
// block by fn_802CA0E4. Slot 0 is the reserved "no texture" slot, so
// allocation starts at 1. A slot is
// { s32 inUse; char name[0x20]; ?; s32 texture; void *sizeRecord; ... }.
#define textureSlots lbl_8055FCB0
#define texSlotSize 0x4C
#define texSlotGroups 0x49 /* 73 groups of 7 slots: the 511 allocatable ones */
#pragma push
#pragma opt_propagation off
// Allocate a texture slot: return the address of the first free one (its
// "in use" flag clear) after the reserved slot 0, walking the table 7 slots
// at a time. With none left it reports that and hands back the slot in front
// of the array, which no caller may use.
/* Allocate a texture slot: return the address of the first free one (in-use flag clear) from slot 1 onward, checking seven slots per group; on exhaustion panic and return the address just before the table. */ int fn_802CB018(void) {
    int index = 1;                    /* slot 0 is reserved */
    int freeSlot = -1;                  /* slot number, -1 while none is free */
    int group;
    unsigned char *groupStart = (unsigned char *)textureSlots + texSlotSize;
    for (group = 0; group < texSlotGroups; group++) {
        if (*(int *)groupStart == 0) { freeSlot = index; goto found; }
        index++;
        if (*(int *)(groupStart + texSlotSize) == 0) { freeSlot = index; goto found; }
        index++;
        if (*(int *)(groupStart + 2 * texSlotSize) == 0) { freeSlot = index; goto found; }
        index++;
        if (*(int *)(groupStart + 3 * texSlotSize) == 0) { freeSlot = index; goto found; }
        index++;
        if (*(int *)(groupStart + 4 * texSlotSize) == 0) { freeSlot = index; goto found; }
        index++;
        if (*(int *)(groupStart + 5 * texSlotSize) == 0) { freeSlot = index; goto found; }
        index++;
        if (*(int *)(groupStart + 6 * texSlotSize) == 0) { freeSlot = index; goto found; }
        groupStart += 7 * texSlotSize;
        index++;
    }
found:
    if (freeSlot < 0)
        fn_802E317C(lbl_8034B940); /* "tex: Out of texture slots" */
    return (int)((unsigned char *)textureSlots + freeSlot * texSlotSize);
}
#pragma pop

#pragma push
#pragma small_data on
extern char lbl_8055D05C;
extern char lbl_8055D064;
extern unsigned short lbl_8055FCAA;
#pragma small_data off
#pragma pop
extern int fn_802CB2FC(int, int, int, unsigned char, unsigned short, unsigned char);
#pragma dont_inline on
#pragma push
#pragma opt_propagation off
/* Allocate and initialize a render-target texture slot ("rtarg") and return its slot index. */
int fn_802CB128(int width, int height, int unused, int flagsMask) {
#define rtargName       lbl_8055D05C
#define rtTexName       lbl_8055D064
#define nextTexId       lbl_8055FCAA
#define allocTexSlot    fn_802CB018
#define makeTexDesc     fn_802CB2FC
#define createTexture   fn_802CA4E0
    int mipCount;
    const char *slotName;
    unsigned short texId;
    unsigned char createFlags;
    int *slot;

    /* Allocate and initialize a render-target ("rtarg") texture slot, then
     * return its index in the texture-slot table. */
    texId = nextTexId;
    slotName = &rtargName;
    createFlags = 3;
    if (flagsMask & 0x20)
        createFlags = 2;
    if (flagsMask & 0x40)
        createFlags &= ~2;
    mipCount = (flagsMask & 1) + 2;
    slot = (int *)allocTexSlot();
    memset(slot, 0, 0x4C);
    slot[0] = 1;
    slot[9] = 0;
    slot[15] = 0;
    slot[16] = 0;
    slot[17] = 0;
    slot[13] = 0xE;
    strcpy((char *)slot + 4, slotName);
    slot[11] = makeTexDesc(width, height, 1, (unsigned char)mipCount, texId, createFlags);
    slot[10] = createTexture(slot[11], (int)&rtTexName, 1, 0, slot[13]);
    return ((char *)slot - (char *)textureSlots) / 0x4C;
#undef createTexture
#undef makeTexDesc
#undef allocTexSlot
#undef nextTexId
#undef rtTexName
#undef rtargName
}
#pragma pop
/* Release a texture slot: destroy its GPU texture object, free its resource handle, and clear the slot. */
void fn_802CB228(int slotIndex) {
    int *slot = (int *)(lbl_8055FCB0 + slotIndex * 0x4C);
    ((void (*)(int))fn_802D8FB4)(slot[0x28 / 4]);
    fn_80128668(slot[0x2C / 4]);
    slot[0x2C / 4] = 0;
    slot[0] = 0;
}

/* Return the larger of a texture slot's width and height (its longest side). */
unsigned short fn_802CB3FC(int slotIndex) {
    int *slot = (int *)(textureSlots + slotIndex * texSlotSize);
    unsigned short *dims = (unsigned short *)slot[0x2C / 4];
    if ((int)dims[1] > (int)dims[0])
        return dims[1];
    return dims[0];
}

#pragma unroll off
#pragma ctrloop on
void fn_802CB424(void) {
    typedef struct Node { int a, b, c, d; struct Node *next; } Node;
    typedef struct Heap { int magic; int size; int unk8; void *sub; } Heap;
    typedef struct Sub { char used; char pad[3]; int mask; void *heap; int unkC; } Sub;
    typedef struct Big { int a, b, c, d, e; void *f14; int g[3]; int f24; int f28; int f2C; } Big;
    typedef struct Mgr {
        int f0; Big *f4; Big *f8; int fC; Node *f10; Node *f14; int f18[2];
        Heap *heap; Sub *sub; int f28; int f2C; int f30; int f34; void *f38;
        int slots[0x2800 / 4];
        int pad283C; int pad2840;
        int f2844; int f2848;
    } Mgr;
    Mgr *m;
    Heap *h;
    Sub *s;
    Big *n;
    Node *nd;
    int i;
    char *strs = lbl_8034B538;
    int zero;
    int zero2;

    m = (Mgr *)fn_801284F8(0x284C, strs + 0x488);
    if (m != 0) {
        int v;
        int *p;
        int count;
        zero = 0;
        m->heap = 0;
        m->sub = 0;
        m->f2C = zero;
        m->f30 = zero;
        m->f34 = zero;
        m->f28 = 0x177000;
        fn_801282EC(0x80);
        fn_801282F4();
        m->heap = (Heap *)fn_8012850C(0x177000, (int *)(strs + 0x494));
        s = (Sub *)fn_801284F8(0x10, strs + 0x4A0);
        if (s != 0) {
            int mask;
            h = m->heap;
            s->unkC = zero;
            s->mask = 0x7F;
            h->magic = 0xABCFEED0;
            h->unk8 = zero;
            mask = s->mask;
            h->size = 0x177000 - ((mask + 0x10) & ~mask);
            h->sub = s;
            s->heap = h;
            s->used = 1;
        }
        m->sub = s;
        zero2 = 0;
        s->used = zero2;
        m->f38 = &m->heap;
        n = (Big *)fn_8012850C(0x30, (int *)(strs + 0x4B0));
        m->f8 = n;
        m->f4 = n;
        m->f0 = zero2;
        n->f14 = (char *)n + 0x18;
        m->f8->f2C = zero2;
        nd = (Node *)fn_8012850C(0xC8, &lbl_8055D080);
        m->f14 = nd;
        m->f10 = nd;
        m->fC = zero2;
        for (i = 0; i < 9; i++) {
            m->f14[i].next = &m->f14[i + 1];
        }
        m->f14[i].next = (Node *)zero2;
        memset(m->f18, 0, 8);
        m->f2844 = zero2;
        memset(m->slots, 0, 0x2800);
        count = 0x40;
        p = (int *)m;
        v = 0;
        do {
            int k;
            for (k = 0; k < 8; k++)
                p[0xF + k * 5] = v++;
            p += 40;
        } while (--count != 0);
        m->f2848 = 0;
    }
    *(void **)lbl_8055FCBC = m;
}
extern char lbl_8034BAEC[];
extern char lbl_8034BB1C[];
extern char lbl_8034BB5C[];
extern char lbl_8034BB68[];
extern char lbl_8034BB7C[];
extern char lbl_8034BB88[];
extern char lbl_8034BB9C[];
extern char lbl_8034BBA8[];
extern char lbl_8055D098;
#pragma opt_propagation off
void fn_802CB6B4(void)
{
  register void *manager;
  register unsigned int total;
  register void *record;
  register void *root = *((void **) lbl_8055FCBC);
  register unsigned int secondTotal;
  if (root != 0)
  {
    if (root != 0)
    {
      fn_80128670(*((int *) (((char *) root) + 8)));
      fn_80128670(*((int *) (((char *) root) + 0x14)));
      *((int *) (((char *) root) + 0x38)) = 0;
      manager = *((void **) (((char *) root) + 0x24));
      if (manager != 0)
      {
        if ((*((int *) (((char *) manager) + 0xC))) != 0)
        {
          fn_802E30C8(lbl_8034BBA8, lbl_8034BB1C);
          fn_802E30C8(lbl_8034BB9C);
          total = 0;
          record = *((void **) (((char *) manager) + ((0, 0xC))));
          while (record != 0)
          {
            fn_802E30C8(lbl_8034BB88, ((char *) record) + 0x10, *((int *) (((char *) record) + 4)));
            total += *((unsigned int *) (((char *) record) + 4));
            record = *((void **) (((char *) record) + 8));
          }

          fn_802E30C8(lbl_8034BB7C, total >> 10);
          secondTotal = 0;
          fn_802E30C8(&lbl_8055D098);
          record = *((void **) (((char *) manager) + 8));
          while (record != 0)
          {
            fn_802E30C8(lbl_8034BB68, ((char *) record) + 0x10, *((int *) (((char *) record) + 4)));
            secondTotal += *((unsigned int *) (((char *) record) + 4));
            record = *((void **) (((char *) record) + 8));
          }

          fn_802E30C8(lbl_8034BB5C, secondTotal >> 10);
          fn_802E317C(lbl_8034BAEC);
        }
        fn_80128668(manager);
      }
      fn_80128670(*((int *) (((char *) root) + 0x20)));
      *((int *) (((char *) root) + 0x20)) = 0;
      *((void **) (((char *) root) + 0x24)) = 0;
      *((int *) (((char *) root) + 0x28)) = 0;
    }
    fn_80128668(root);
  }
  *((void **) lbl_8055FCBC) = 0;
}
#pragma opt_propagation reset

extern void fn_8012C90C(int);
extern void fn_802D915C(void *);
extern void fn_802CBB9C(int **, int, int *);
extern char lbl_8034B9F4;
#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern char lbl_8055FCBC[];
#pragma push
#pragma scheduling invalid_target
DECL_SECTION(".data") extern char lbl_8034B9F4;
void fn_802CB82C(int arg0) {
    char *temp_r31;
    char *temp_r29;
    char *temp_r30;
    int temp_r0;
    char *pool, *node, *other, *joined;
    char **link, **mergeLink, **scanLink;
    int pageSize, merged, mergeCandidate;

    temp_r29 = *(char **)lbl_8055FCBC;
    temp_r31 = temp_r29 + arg0 * 0x14;
    temp_r0 = *(int *)(temp_r31 + 0x40);

    if (temp_r0 == 2) {
        temp_r30 = (char *)lbl_8055FCB0 + arg0 * 0x4C;
        ((void (*)(int))fn_802CB3F4)(*(int *)(temp_r30 + 0x40));
        *(int *)(temp_r30 + 0x40) = 0;
        pool = *(char **)(*(char **)(temp_r29 + 0x38) + 4);
        link = (char **)(pool + 0xC);
        node = (char *)(*(int *)(temp_r30 + 0x44) - (*(int *)(pool + 4) + 1));
        while ((other = *link) != 0) {
            if (other == node) {
                *link = *(char **)(node + 8);
                break;
            }
            link = (char **)(other + 8);
        }
        mergeLink = (char **)(pool + 8);
        *(char **)(node + 8) = *mergeLink;
        *mergeLink = node;
        do {
            scanLink = (char **)(pool + 8);
            merged = 0;
            while ((other = *scanLink) != 0) {
                pageSize = *(int *)(pool + 4);
                mergeCandidate = 1;
                if (((char *)*mergeLink + pageSize + *(int *)(*mergeLink + 4) + 1 != other) &&
                    ((char *)other + pageSize + *(int *)(other + 4) + 1 != *mergeLink))
                    mergeCandidate = 0;
                if (mergeCandidate != 0) {
                    link = mergeLink;
                    if ((char *)other + pageSize + *(int *)(other + 4) + 1 == *mergeLink) {
                        link = scanLink;
                        scanLink = mergeLink;
                    }
                    merged = 1;
                    *(int *)(*link + 4) = (((pageSize + 0x10) & ~pageSize) +
                        (*(int *)(*link + 4) + *(int *)(*scanLink + 4)));
                    *scanLink = *(char **)(*scanLink + 8);
                    break;
                }
                scanLink = (char **)(other + 8);
            }
        } while (merged != 0);
        *(int *)(temp_r30 + 0x44) = 0;
        ((void (*)(void *, void *))fn_802CB3F8)(temp_r30 + 4, &lbl_8034B9F4);
    } else if (temp_r0 == 1) {
        temp_r30 = *(char **)temp_r29;
        while (temp_r30 != 0) {
            if (*(int *)(temp_r30 + 4) == arg0) {
                other = *(char **)(temp_r29 + 0xC);
                while (other != 0) {
                    if (*(char **)(other + 0xC) == temp_r30)
                        *(char **)(other + 0xC) = 0;
                    other = *(char **)(other + 0x10);
                }
                if (*(int *)(temp_r30 + 0x10) == -1)
                    fn_8012C90C(*(int *)temp_r30);
                fn_8012C958(*(int *)temp_r30);
                *(int *)temp_r30 = 0;
                fn_802D915C(*(void **)(temp_r30 + 0xC));
                *(int *)(temp_r30 + 0xC) = 0;

                pool = *(char **)(*(char **)(temp_r29 + 0x38) + 4);
                link = (char **)(pool + 0xC);
                node = (char *)(*(int *)(temp_r30 + 8) - (*(int *)(pool + 4) + 1));
                while ((other = *link) != 0) {
                    if (other == node) {
                        *link = *(char **)(node + 8);
                        break;
                    }
                    link = (char **)(other + 8);
                }
                mergeLink = (char **)(pool + 8);
                *(char **)(node + 8) = *mergeLink;
                *mergeLink = node;
                do {
                    scanLink = (char **)(pool + 8);
                    merged = 0;
                    while ((other = *scanLink) != 0) {
                        pageSize = *(int *)(pool + 4);
                        mergeCandidate = 1;
                        if (((char *)*mergeLink + pageSize + *(int *)(*mergeLink + 4) + 1 != other) &&
                            ((char *)other + pageSize + *(int *)(other + 4) + 1 != *mergeLink))
                            mergeCandidate = 0;
                        if (mergeCandidate != 0) {
                            link = mergeLink;
                            if ((char *)other + pageSize + *(int *)(other + 4) + 1 == *mergeLink) {
                                link = scanLink;
                                scanLink = mergeLink;
                            }
                            merged = 1;
                            *(int *)(*link + 4) = (((pageSize + 0x10) & ~pageSize) +
                                (*(int *)(*link + 4) + *(int *)(*scanLink + 4)));
                            *scanLink = *(char **)(*scanLink + 8);
                            break;
                        }
                        scanLink = (char **)(other + 8);
                    }
                } while (merged != 0);
                *(int *)(temp_r30 + 8) = 0;
                fn_802CBB9C((int **)(temp_r29 + 4), (int)temp_r29, (int *)temp_r30);
                break;
            }
            temp_r30 = *(char **)(temp_r30 + 0x14);
        }
    }
    *(int *)(temp_r31 + 0x40) = 0;
}
#pragma pop
 void fn_802CBBE8();
 extern char lbl_8034BA04[];
/* Remove arg2 from the list rooted at arg1, then push arg2 onto the front of *arg0. */
void fn_802CBB9C(int **arg0, int arg1, int *arg2) {
    fn_802CBBE8(arg1, arg2);
    *(int **)((char *)arg2 + 0x14) = *arg0;
    *arg0 = arg2;
}

#pragma scheduling invalid_target
void fn_802CBBE8(register int **link, int *node, int *scan) {
    /* Unlink `node` from the texture list threaded through `link` (each node's next pointer is at +0x14);
       log a diagnostic if the node is not in the list. */
    int found = 0;
    while ((scan = *link) != 0) {
        if (scan == node) {
            int *next = *(int **)((char *)node + 0x14);
            *link = next;
            *(int **)((char *)node + 0x14) = 0;
            found = 1;
            break;
        }
        link = (int **)((char *)scan + 0x14);
    }
    if (found == 0)
        fn_802E317C(lbl_8034BA04);
}

#pragma use_lmw_stmw off
extern void fn_8012C720(void *, int, int, int);
extern char lbl_8034BA28[];
extern char lbl_8055D088;
extern void fn_802CBD30(void **, void **, void *);
#pragma use_lmw_stmw off
/* Discard texture nodes with priority <= arg1 from the active list, moving them to
 * the free list and releasing/dereferencing any associated child resources. */
/* Evict texture nodes whose priority is at or below priorityLimit from the manager's loaded list to its free list, releasing their textures and any child resource's last reference. */ void fn_802CBC3C(void *managerPtr, int arg1) {
    register void **manager = (void **)managerPtr;
    register int priorityLimit = arg1;
    register char *childResource;
    register char *node = (char *)manager[3];
    register int zero = 0;
    register int minusOne = -1;
    int refCount;

    goto check;
inspect:
    if (*(int *)(node + 8) > priorityLimit)
        goto advance;
    ((void (*)(int, const char *))fn_802CB3F8)(*(int *)node, lbl_8034BA28);
    ((void (*)(int))fn_802CB3F4)(*(int *)(node + 4));
    *(int *)(node + 4) = zero;
    fn_802CBD30(manager + 4, manager + 3, node);
    childResource = *(char **)(node + 0xC);
    if (childResource != 0) {
        refCount = *(int *)(childResource + 0x10) - 1;
        *(int *)(childResource + 0x10) = refCount;
        if (refCount == 0) {
            *(int *)(childResource + 0x10) = minusOne;
            fn_8012C720(*(void **)childResource, *(int *)(childResource + 8),
                        *(int *)((char *)lbl_8055FCB0 +
                            *(int *)(childResource + 4) * 0x4C + 0x3C), 0);
            ((void (*)(void *, const char *))fn_802CB3F8)(
                (void *)((char *)lbl_8055FCB0 + *(int *)(childResource + 4) * 0x4C + 4),
                &lbl_8055D088);
        }
        *(void **)(node + 0xC) = 0;
    }
    node = (char *)manager[3];
    goto check;
advance:
    node = *(char **)(node + 0x10);
check:
    if (node != 0)
        goto inspect;
}
#pragma use_lmw_stmw on

#pragma scheduling on
/* tex_unlink_node(list_head, node), old-style on purpose: its 3rd register only
   carries the scan pointer the search starts from, which the callee overwrites
   with *list_head before reading it. */
void fn_802CBD7C();

/* Move one texture node from a list of the texture manager to another: unlink it
 * from the list whose head pointer is at srcHead, then push it on the front of the
 * list whose head pointer is at destHead.  The manager keeps the textures it holds
 * loaded in the list at +0xC and the spare nodes in the list at +0x10, both chained
 * through the node's +0x10 link; tex_unlink_node reports
 * "tex:unlink_node: can't find node!" if the node was not on srcHead's list. */
void fn_802CBD30(void **destHead, void **srcHead, void *node) {
    /* One node of those two lists (fn_802CBC3C and fn_802CC10C build and retire them). */
    typedef struct TexNode {
        /* 0x00 */ char *name;        /* the texture table entry's name (+0x04) */
        /* 0x04 */ int texHandle;     /* the entry's +0x40; released by fn_802CB3F4 */
        /* 0x08 */ int priority;      /* kept while above the eviction limit */
        /* 0x0C */ void *request;     /* the load waiting on this texture, or 0 */
        /* 0x10 */ struct TexNode *next; /* the link this rewires */
    } TexNode;

    fn_802CBD7C(srcHead, node);
    ((TexNode *)node)->next = *(TexNode **)destHead;
    *destHead = node;
}

void fn_802CBD7C(void **, void *, void *);
extern char lbl_8034BA04[];
/* Unlink a texture node from the list whose head pointer is *link, scanning
   from the given node; report "can't find node!" if it isn't on that list. */
void fn_802CBD7C(register void **link, void *node, void *scan) {
    int found = 0;
    while ((scan = *link) != 0) {
        if (scan == node) {
            void *next = *(void **)((char *)node + 0x10);
            *link = next;
            *(void **)((char *)node + 0x10) = 0;
            found = 1;
            break;
        }
        link = (void **)((char *)scan + 0x10);
    }
    if (found == 0)
        fn_802E317C(lbl_8034BA04);
}

extern int fn_802D9068(void);
extern void startTextureRequestRead(void *, void *);
extern void fn_802CBFA0(void *, unsigned int);
extern void fn_802CC03C(int **, int *, int);
extern int fn_802CC10C(void *, int, int, int);
extern int fn_802CC404(void *);
extern void *fn_802CC2C8(void *, int);
/* Service the texture manager's active request: split the priority-sorted node list so lower-priority textures can be evicted, allocate the request's texture from the heap (freeing nodes until it fits), and mark the texture active on success. */ void texAllocPending(void *texMgr) {
    // Queue the pending texture by priority, allocate it, evicting lower-priority entries until it fits.
    char *base;
    int texId;
    char *freeTex;
    char *record;
    char *request;
    int allocated;
    int zero = 0;
    char *activeTex;
    char *scanNode;
    char **link;
    int lowerPriority;

    activeTex = *(char **)((char *)texMgr + 0x2844);
    base = (char *)texMgr;
    if (activeTex == 0)
        return;
    if (*(void **)((char *)texMgr + 4) == 0)
        return;

    link = (char **)(base + 0x283C);
    goto load_scan;
compare_scan:
    lowerPriority = *(float *)(scanNode + 8) < *(float *)(activeTex + 8);
    if (lowerPriority != 0) {
        *(char **)(base + 0x2840) = scanNode;
        *link = 0;
        goto scan_done;
    }
    link = (char **)(scanNode + 0x10);
load_scan:
    scanNode = *link;
    if (scanNode != 0)
        goto compare_scan;
scan_done:
    request = *(char **)(base + 4);
    allocated = zero;
    activeTex = *(char **)(base + 0x2844);
    freeTex = *(char **)(base + 0x283C);
    texId = *(int *)activeTex;
    if (request != 0) {
        if (fn_802D9068() != 0) {
            record = (char *)lbl_8055FCB0 + texId * 0x4C;
            *(int *)(request + 0x10) = zero;
        alloc_loop:
            *(void **)(request + 8) =
                fn_802CC2C8((void *)fn_802CC404(base),
                            *(int *)(record + 0x3C));
            if (*(void **)(request + 8) == 0 && freeTex != 0 &&
                fn_802CC10C(base, *(int *)freeTex,
                            *(int *)(freeTex + 0xC) + 2, (int)request) != 0) {
                *(int *)(freeTex + 4) = zero;
                freeTex = *(char **)(freeTex + 0x10);
                (*(int *)(request + 0x10))++;
                goto alloc_loop;
            }
            if (*(void **)(request + 8) != 0) {
                fn_802CC03C((int **)base, (int *)request, texId);
                if (*(int *)(request + 0x10) == zero)
                    startTextureRequestRead(base, request);
                allocated = 1;
            } else {
                fn_802CBFA0(base, (unsigned int)request);
                *(int *)(request + 0x10) = zero;
            }
        } else if (freeTex != 0 &&
                   *(int *)((char *)lbl_8055FCB0 +
                            *(int *)freeTex * 0x4C + 0x44) != zero &&
                   fn_802CC10C(base, *(int *)freeTex,
                               *(int *)(freeTex + 0xC) + 2, zero) != 0) {
            *(int *)(freeTex + 4) = zero;
        }
    }
    if (allocated != zero) {
        activeTex = *(char **)(base + 0x2844);
        *(int *)(activeTex + 4) = 1;
    }
}

void fn_802CBFA0(void *mgr, unsigned int request) {
    /* Detach the given load request from every loaded texture in the manager's
       +0xC list: clear each node's owner field that points at it. */
    typedef struct TexNode {
        /* 0x00 */ char *name;
        /* 0x04 */ int texHandle;
        /* 0x08 */ int priority;
        /* 0x0C */ void *request;
        /* 0x10 */ struct TexNode *next;
    } TexNode;
    TexNode *node;
    node = *(TexNode **)((char *)mgr + 0xC);
    while (node != 0) {
        if ((unsigned int)node->request == request)
            node->request = 0;
        node = node->next;
    }
}

void startTextureRequestRead(void *mgr, void *request) {
    extern char lbl_8055D088;
    *(int *)((char *)request + 0x10) = -1;
    ((void (*)(int, int, int, int))fn_8012C720)(*(int *)((char *)request + 0), *(int *)((char *)request + 8), *(int *)((char *)lbl_8055FCB0 + *(int *)((char *)request + 4) * 0x4C + 0x3C), 0);
    ((void (*)(void *, void *))fn_802CB3F8)((char *)lbl_8055FCB0 + *(int *)((char *)request + 4) * 0x4C + 4, &lbl_8055D088);
}

extern char lbl_8034BA34[];
extern char lbl_8034BA70[];
int fn_802D9154(void);
void fn_802CC03C(int **listHead, int *record, int texId) {
    int entryOffset = texId * 0x4C;
    char nameBuf[0x20];
    int version;

    /* Set up a texture record for texId: build its ".tm0" name, load the TEX
       resource (version to version), store texId and drgc-tex context, report
       load/version errors, then link the record into the list. */
    record[0] = fn_8012C5B8((char *)fn_802CA2A8(nameBuf, 0x20, (int)((char *)lbl_8055FCB0 + entryOffset + 4)), 0x54455820, &version);
    record[1] = texId;
    record[3] = fn_802D9154();
    if (record[0] == 0)
        fn_802E317C(lbl_8034BA34, nameBuf);
    if ((unsigned int)version != 0xF)
        fn_802E317C(lbl_8034BA70, nameBuf, version, 0xF);
    ((void (*)(int **, int, int *))fn_802CBB9C)(listHead, (int)listHead + 4, record);
}

#pragma optimization_level 2
#pragma opt_common_subs off
int fn_802CC10C(void *arg0, int arg1, int arg2, int arg3) {
    int result = 0;
    char *table;
    char *node;
    char *pool;
    char **link;
    char **mergeLink;
    char **scanLink;
    char *other;
    char *joined;
    int pageSize;
    int mergeCandidate;
    int merged;

    node = *(char **)((char *)arg0 + 0x10);
    if (node != 0) {
        table = (char *)(lbl_8055FCB0 + arg1 * 0x4C);
        *(int *)(node + 4) = *(int *)(table + 0x40);
        *(int *)(node + 8) = arg2;
        *(int *)(node + 0xC) = arg3;
        *(char **)node = table + 4;
        ((void (*)(void **, void **, void *))fn_802CBD30)(
            (void **)((char *)arg0 + 0xC),
            (void **)((char *)arg0 + 0x10), node);
        *(int *)(table + 0x40) = 0;

        pool = *(char **)(*(char **)((char *)arg0 + 0x38) + 4);
        link = (char **)(pool + 0xC);
        node = (char *)(*(int *)(table + 0x44) - (*(int *)(pool + 4) + 1));
        for (other = *link; other != 0; other = *link) {
            if (other == node) {
                *link = *(char **)(node + 8);
                break;
            }
            link = (char **)(other + 8);
        }

        mergeLink = (char **)(pool + 8);
        *(char **)(node + 8) = *mergeLink;
        *mergeLink = node;
        do {
            scanLink = (char **)(pool + 8);
            merged = 0;
            other = *scanLink;
            while (other != 0) {
                joined = *mergeLink;
                pageSize = *(int *)(pool + 4);
                mergeCandidate = 1;
                if (((char *)((unsigned int)joined + pageSize +
                               *(int *)(joined + 4) + 1) != other) &&
                    ((char *)((unsigned int)other + pageSize +
                               *(int *)(other + 4) + 1) != joined))
                    mergeCandidate = 0;
                if (mergeCandidate != 0) {
                    link = mergeLink;
                    if ((char *)((unsigned int)other + pageSize +
                                 *(int *)(other + 4) + 1) == joined) {
                        link = scanLink;
                        scanLink = mergeLink;
                    }
                    joined = *link;
                    mergeLink = link;
                    merged = 1;
                    *(int *)(joined + 4) =
                        (((pageSize + 0x10) & ~pageSize) +
                         (*(int *)(joined + 4) + *(int *)(*scanLink + 4)));
                    *scanLink = *(char **)(*scanLink + 8);
                    scanLink = (char **)(joined + 8);
                } else {
                    scanLink = (char **)(other + 8);
                }
                other = *scanLink;
            }
        } while (merged != 0);
        *(int *)(table + 0x44) = 0;
        result = 1;
        ((void (*)(void *, void *))fn_802CB3F8)(table + 4, &lbl_8034BA98);
    }
    return result;
}
#pragma opt_common_subs on
#pragma optimization_level reset

extern char lbl_8034BB28[];
void *fn_802CC2C8(void *arg0, int arg1) {
    volatile int *manager = (volatile int *)arg0;
    int size = manager[1];
    int mask = ~size;
    int aligned = (arg1 + size) & mask;
    char *node = (char *)0x80000000;
    char **link = (char **)((char *)arg0 + 8);
    int best = (int)node - 1;
    char **choice = 0;
    void *result = 0;
    int s2;
    while (node != 0) {
        int start = *(int *)(node + 4);
        if (start >= aligned && best > start) {
            choice = link;
            best = start;
        }
        link = (char **)(node + 8);
        node = *link;
    }
    if (choice != 0) {
        char *block = *choice;
        char *next = *(char **)(block + 8);
        char *split = 0;
        int remaining = *(int *)(block + 4) - aligned;
        if (remaining > (((size + 0x10) & mask) + 0x20)) {
            char *p = block + size + aligned;
            *(int *)(p + 1) = 0xABCFEED0;
            split = p + 1;
            *(int *)(p + 9) = 0;
            s2 = manager[1];
            *(int *)(p + 5) = remaining - ((s2 + 0x10) & ~s2);
            *(void **)(p + 0xD) = arg0;
            *(int *)(block + 4) = aligned;
        }
        if (split != 0) {
            *(char **)(split + 8) = next;
            *choice = split;
        } else {
            *choice = next;
        }
        *(char **)(block + 8) = *(char **)((char *)arg0 + 0xC);
        *(char **)((char *)arg0 + 0xC) = block;
        result = block + manager[1] + 1;
    }
    if (result == 0 && *(unsigned char *)arg0 != 0)
        fn_802E317C(lbl_8034BB28);
    return result;
}

/* Return the SimpleHeap handle used for texture allocations: the scene context
   holds a heap container at +0x38, whose +4 field is the heap handle. */
int fn_802CC404(void *context) {
    char *heapContainer = *(char **)((char *)context + 0x38);
    return *(int *)(heapContainer + 4);
}

extern int fn_8012C7FC(void *, int *);
#pragma dont_inline on
extern char lbl_8055D090;
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_802CC410(void *texMgr) {
    struct { int *v; } w_request;
    register int zero = 0;
    register int doneFlag = 2;
    struct { int v; } w_entrySlot;
    register char *manager = (char *)texMgr;
    #define request w_request.v
    #define entry w_entrySlot.v
    int loadedSize;
    int loadedBlock;

    /* Process the manager's pending texture requests: for a request whose async
     * resource is loaded, fill its 0x4C-byte record in lbl_8055FCB0, tag it
     * "LOADED", accumulate its size into +0x18, and mark its status slot at
     * +0x40 done; then restart from the list head until none is ready. */
outer:
    request = *(int **)manager;
    entry = -2;
    while (request != 0) {
        if (request[4] == -1) {
            loadedBlock = fn_8012C7FC((void *)request[0], &loadedSize);
            if (loadedBlock != 0) {
                entry = lbl_8055FCB0 + request[1] * 0x4C;
                *(int *)(entry + 0x44) = request[2];
                *(int *)(entry + 0x40) = loadMipTexture((void *)loadedBlock,
                    (void *)request[3],
                    (void *)*(int *)(lbl_8055FCB0 + 0x34 + request[1] * 0x4C));
                request[3] = zero;
                fn_8012C958(request[0]);
                request[0] = zero;
                request[2] = zero;
                fn_802CBB9C((int **)(manager + 4), (int)manager, request);
                ((void (*)(void *, const char *))fn_802CB3F8)(
                    (void *)(entry + 4), &lbl_8055D090);
                *(int *)(manager + 0x18) += *(int *)(entry + 0x3C);
                entry = request[1];
                break;
            }
        }
        request = *(int **)((char *)request + 0x14);
    }
    if (entry != -2) {
        *(int *)(manager + entry * 0x14 + 0x40) = doneFlag;
        goto outer;
    }
#undef request
#undef entry
}
#pragma scheduling on
#pragma use_lmw_stmw on
#pragma dont_inline reset
extern double lbl_80564F38;
#pragma fp_contract on
void fn_802CC518(int arg0, float arg1) {
    union {
        double value;
        unsigned int words[2];
    } converted;
    double number;
    double magic;
    float result;

    converted.words[1] = (unsigned int)arg0 ^ 0x80000000;
    converted.words[0] = 0x43300000;
    number = converted.value;
    magic = lbl_80564F38;
    result = (lbl_80564F30 * arg1) / (float)(number - magic);
    lbl_8055FCC4 = result;
}
/* Clamp a texture slot's keep-alive weight (+0x38) to a scaled minimum; ignore invalid indices, a disabled texture system, or unused slots. */
void fn_802CC550(int textureIndex, float minWeight, float scale) {
    #pragma scheduling invalid_target
    int slotOffset;
    char *textureSlot;
    float clampedMin;
    float currentWeight;
    float maxWeight;
    if (textureIndex == -1)
        return;
    slotOffset = textureIndex * 0x4C;
    textureSlot = (char *)lbl_8055FCB0 + slotOffset;
    if ((unsigned char)lbl_8055D07D == 0)
        return;
    if (*(int *)(textureSlot + 0x3C) == 0)
        return;
    clampedMin = lbl_80564F40;
    clampedMin = (clampedMin > minWeight) ? clampedMin : minWeight;
    currentWeight = *(float *)(textureSlot + 0x38);
    maxWeight = scale * (lbl_8055FCC4 * clampedMin);
    currentWeight = (currentWeight < maxWeight) ? currentWeight : maxWeight;
    *(float *)(textureSlot + 0x38) = currentWeight;
}
#pragma dont_inline off
/* Marks a texture slot as used this pass: raises its keep-alive weight (+0x38)
 * to the floor fn_802CC550 keeps (the 1.0f / 1e-5f pair in .sdata2) and stamps
 * its use count (+0x48) with 1000000, so the eviction pass fn_802CC770 - which
 * only weighs slots whose count is positive - leaves it resident.
 * The slot index -1 (no texture) is ignored. */
void fn_802CC5B8(int textureIndex) {
#define gTextureSlots lbl_8055FCB0
#define TEX_KEEP_USE_COUNT 1000000
    int slotOffset;
    if (textureIndex == -1)
        return;
    fn_802CC550(textureIndex, lbl_80564F40, lbl_80564F44);
    slotOffset = textureIndex * 0x4C;
    *(int *)((char *)gTextureSlots + slotOffset + 0x48) = TEX_KEEP_USE_COUNT;
#undef gTextureSlots
#undef TEX_KEEP_USE_COUNT
}

extern int lbl_8055FCC0;
extern float lbl_80564F48;
extern int fn_802E2C20(void);
#pragma scheduling on
void fn_802CC60C(void) {
    float f = 1000000000000.0f;
    int offset = 0;
    int i;
    int counter;
    int next;
    void *root;

    for (i = 0; i < 0x40; i++) {
        *(float *)((char *)lbl_8055FCB0 + offset + 0x38) = f;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x48) = 0;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x84) = f;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x94) = 0;
        *(float *)((char *)lbl_8055FCB0 + offset + 0xD0) = f;
        *(int *)((char *)lbl_8055FCB0 + offset + 0xE0) = 0;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x11C) = f;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x12C) = 0;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x168) = f;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x178) = 0;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x1B4) = f;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x1C4) = 0;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x200) = f;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x210) = 0;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x24C) = f;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x25C) = 0;
        offset += 0x260;
    }

#pragma scheduling off
    root = *(void **)lbl_8055FCBC;
    *(int *)((char *)root + 0x2844) = 0;
    counter = lbl_8055FCC0;
    *(int *)((char *)root + 0x283C) = 0;
    next = counter + 1;
    *(int *)((char *)root + 0x2840) = 0;
    lbl_8055FCC0 = next;
    if ((unsigned char)counter == 0)
        *(int *)((char *)root + 0x1C) = fn_802E2C20();
#pragma scheduling on
}

/* Set the texture-system flag (lbl_8055D07D): zero disables per-entry texture
 * processing/updates; nonzero enables it. Read back by fn_802CC744. */
void fn_802CC73C(char enabled) {
    lbl_8055D07D = enabled;
}

/* Returns lbl_8055D07D, the texture-system flag set through fn_802CC73C.
 * Zero disables per-entry texture processing/updates; shown on the debug overlay. */
char fn_802CC744(void) {
    return lbl_8055D07D;
}

#pragma peephole reset
int fn_802CC74C(void) { int result = 0; char *p = *(char **)lbl_8055FCBC; if (p != 0) { if (*(int *)(p + 4) != 0) result = 1; } return result; }
extern float lbl_80564F4C;
extern float lbl_80564F50;
#pragma push
#pragma cplusplus reset
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802CC770(void) {
char *entry;
int slotOffset;
int offset;
int i;
float f4C;
float f40;
float magic;
float f50;
i = 0;
offset = 0;
slotOffset = 0;
f4C = lbl_80564F4C;
f40 = lbl_80564F40;
magic = lbl_80564F38;
f50 = lbl_80564F50;
do {
entry = (char *)lbl_8055FCB0 + offset;
if (*(int *)entry > 0 && *(int *)(entry + 0x3C) != 0) {
if (*(int *)(entry + 0x48) > 0) {
union { double value; unsigned int words[2]; } converted;
double number;
float convertedFloat;
float value;
int ret;
ret = fn_802CB3FC(i);
converted.words[0] = 0x43300000;
converted.words[1] = (ret * 2) ^ 0x80000000;
number = converted.value;
convertedFloat = (float)number - magic;
value = convertedFloat * *(float *)(entry + 0x38);
value = value - f40;
{
char *root = *(char **)lbl_8055FCBC;
char *node = root + slotOffset + 0x3C;
*(float *)(node + 8) = value;
if (*(int *)(node + 4) == 2)
*(int *)(node + 0xC) = *(int *)(root + 0x2848);
if (*(int *)(node + 4) == 0 && value < f4C && (*(char **)(root + 0x2844) == 0 || value < *(float *)(*(char **)(root + 0x2844) + 8)))
*(char **)(root + 0x2844) = node;
if (*(int *)(node + 4) == 2) {
char **link = (char **)(root + 0x283C);
char *scan = *link;
int less;
while (scan != 0) {
less = *(float *)(scan + 8) < *(float *)(node + 8);
if (less != 0)
break;
link = (char **)(scan + 0x10);
scan = *link;
}
*(void **)(node + 0x10) = scan;
*link = node;
}
}
} else {
char *root = *(char **)lbl_8055FCBC;
char *node = root + slotOffset + 0x3C;
*(float *)(node + 8) = f50;
if (*(int *)(node + 4) == 0 && f50 < f4C && (*(char **)(root + 0x2844) == 0 || f50 < *(float *)(*(char **)(root + 0x2844) + 8)))
*(char **)(root + 0x2844) = node;
if (*(int *)(node + 4) == 2) {
char **link = (char **)(root + 0x283C);
char *scan = *link;
int less;
while (scan != 0) {
less = *(float *)(scan + 8) < *(float *)(node + 8);
if (less != 0)
break;
link = (char **)(scan + 0x10);
scan = *link;
}
*(void **)(node + 0x10) = scan;
*link = node;
}
}
}
i++;
offset += 0x4C;
slotOffset += 0x14;
} while (i < 0x200);
if (lbl_8055D07D == 0) {
char *root = *(char **)lbl_8055FCBC;
char *node = *(char **)(root + 0x283C);
while (node != 0) {
if (*(int *)(node + 4) == 2) {
char *head = *(char **)(root + 0x10);
int flag = 0;
if (head != 0) {
char *entry2 = (char *)lbl_8055FCB0 + *(int *)node * 0x4C;
*(int *)(head + 4) = *(int *)(entry2 + 0x40);
*(int *)(head + 8) = *(int *)(node + 0xC) + 2;
*(int *)(head + 0xC) = 0;
*(char **)head = entry2 + 4;
fn_802CBD30((void **)(root + 0xC), (void **)(root + 0x10), head);
*(int *)(entry2 + 0x40) = 0;
{
char *pool;
char **link;
char *freeNode;
char *other;
char **mergeLink;
pool = *(char **)(*(char **)(root + 0x38) + 4);
link = (char **)(pool + 0xC);
freeNode = (char *)(*(int *)(entry2 + 0x44) - (*(int *)(pool + 4) + 1));
other = *link;
if (other != 0) {
do {
if (other == freeNode) {
*link = *(char **)(freeNode + 8);
break;
}
link = (char **)(other + 8);
other = *link;
} while (other != 0);
}
mergeLink = (char **)(pool + 8);
*(char **)(freeNode + 8) = *mergeLink;
*mergeLink = freeNode;
{
char **scanLink;
char *joined;
char *other2;
int pageSize;
int merged;
int candidate;
do {
scanLink = (char **)(pool + 8);
merged = 0;
merge_loop:
other2 = *scanLink;
if (other2 != 0) {
joined = *mergeLink;
pageSize = *(int *)(pool + 4);
candidate = 1;
if (((char *)joined + pageSize + *(int *)(joined + 4) + 1 != other2) && ((char *)other2 + pageSize + *(int *)(other2 + 4) + 1 != joined))
candidate = 0;
if (candidate != 0) {
link = mergeLink;
if ((char *)other2 + pageSize + *(int *)(other2 + 4) + 1 == joined) {
link = scanLink;
scanLink = mergeLink;
}
joined = *link;
mergeLink = link;
merged = 1;
*(int *)(joined + 4) = (((pageSize + 0x10) & ~pageSize) + (*(int *)(joined + 4) + *(int *)(*scanLink + 4)));
*scanLink = *(char **)(*scanLink + 8);
} else {
scanLink = (char **)(other2 + 8);
goto merge_loop;
}
}
} while (merged != 0);
}
*(int *)(entry2 + 0x44) = 0;
flag = 1;
((void (*)(void *, void *))fn_802CB3F8)(entry2 + 4, &lbl_8034BA98);
}
}
if (flag != 0)
*(int *)(node + 4) = 0;
}
node = *(char **)(node + 0x10);
}
}
{
char *root = *(char **)lbl_8055FCBC;
fn_802CC410(root);
texAllocPending(root);
fn_802CBC3C(root, *(int *)(root + 0x2848));
*(int *)(root + 0x2848) = *(int *)(root + 0x2848) + 1;
}
lbl_8055FCB8 = -2;
}
#pragma pop
extern void fn_802E317C(const char *, ...);
extern char texMsgBadExtractionName[];

extern int lbl_8055D03C;
extern char lbl_8034B5F0[];
void fn_802CAC54(int);
void fn_802CB6B4(void);
int fn_80128670(int);
int fn_802CA2A8(void *, int, int);
int fn_8012C5B8(void *, int, int *);
int fn_8012C6F0(void);
int fn_8012C958(int);
extern char lbl_8034B538[];
extern char textureNullName[];
extern char invalidTextureName[];
extern int TextureSlot_isLoaded(int);
extern char lbl_8034B538[];
