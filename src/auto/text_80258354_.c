// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

float getPictureWidth(int, int);
extern float lbl_80563AD0;
extern float getPictureWidth(int, int);
extern float getPictureHeight(int, int);
extern void drawPictureScaled(int, int, int, float, float, float, float);
extern float lbl_80563ACC;
extern void fn_80235380(int);
extern void fn_802328D4(int);
extern void fn_80128668(void *);
extern int lbl_80344D98;
__declspec(section ".data") extern int lbl_80344D98;
extern char lbl_80344D88[];
extern void *fn_801284F8(int, void *);
extern char lbl_8055C258[];
__declspec(section ".sdata") extern char lbl_8055C258[];
extern float lbl_80563AC8;
extern int loadFontTexture(void *); /* gText: font handle for a font name (used by fn_8025861C) */
#pragma scheduling invalid_target
/* UIObjects_Create: allocate the UI object manager and start its three fixed
 * tables.  Each is a {array, count, capacity} header whose array points at the
 * 0x20 entries kept inline right behind it:
 *   +0x010 objects: 0x48-byte UIObjectEntry (fn_80258550 adds one)
 *   +0x91C texts:   {char name[0x20]; UITextObject *text} (fn_8025861C adds one)
 *   +0xDA8 sounds:  {char name[0x20]; void *sound; char flags; float scale}
 *                   (fn_802586F0 adds one)
 * destroyUIObjects (vtable +8) releases what the tables hold and clears the counts.
 * The block is tagged "UIObjects_impl"; callers keep what it returns. */
void *fn_80258354(void) {
#define Allocate fn_801284F8            /* size, tag -> new block named for the tag */
#define sUIObjectsImplName lbl_80344D88 /* "UIObjects_impl" */
#define UIObjectsVTable lbl_80344D98    /* this class's vtable */
    struct UIObjects {
        void *vtable;                   /* +0x000 */
        void *objects;                  /* +0x004 table of 0x48-byte entries */
        int objectCount;                /* +0x008 */
        int objectCapacity;             /* +0x00C: 0x20 */
        char objectEntries[0x20][0x48]; /* +0x010 */
        void *texts;                    /* +0x910 table of 0x24-byte entries */
        int textCount;                  /* +0x914 */
        int textCapacity;               /* +0x918: 0x20 */
        char textEntries[0x20][0x24];   /* +0x91C */
        void *sounds;                   /* +0xD9C table of 0x2C-byte entries */
        int soundCount;                 /* +0xDA0 */
        int soundCapacity;              /* +0xDA4: 0x20 */
        char soundEntries[0x20][0x2C];  /* +0xDA8 */
    };                                  /* == 0x1328 */
    struct UIObjects *mgr = (struct UIObjects *)Allocate(sizeof(struct UIObjects),
                                                         sUIObjectsImplName);
    if (mgr != 0) {
        mgr->vtable = &UIObjectsVTable;
        mgr->objects = mgr->objectEntries;
        mgr->objectCapacity = 0x20;
        mgr->objectCount = 0;
        mgr->texts = mgr->textEntries;
        mgr->textCapacity = 0x20;
        mgr->textCount = 0;
        mgr->sounds = mgr->soundEntries;
        mgr->soundCapacity = 0x20;
        mgr->soundCount = 0;
    }
    return mgr;
#undef Allocate
#undef sUIObjectsImplName
#undef UIObjectsVTable
}
#pragma scheduling on

#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void *destroyUIObjects(void *mgr, int freeManager, int arg2) {
    /* UIObjects destructor: release the art sets, texts and sounds held by the
     * manager's three fixed tables, clear their counts and table headers, and
     * free the manager itself when freeManager is positive. */
    struct Release {
        virtual void release(int);
    };
    char *base = (char *)mgr;
    int zero;
    int offset;
    int entry;
    int textIndex;
    int soundIndex;
    void *soundObj;

    if (mgr) {
        *(void **)base = &lbl_80344D98;
        entry = 0;
        offset = 0;
        goto L_check1;
L_loop1:
        fn_80235380(*(int *)(*(char **)(base + 4) + offset + 0x40));
        offset += 0x48;
        entry += 1;
L_check1:
        if (entry < *(int *)(base + 8))
            goto L_loop1;
        zero = 0;
        *(int *)(base + 8) = zero;

        textIndex = 0;
        offset = 0;
        goto L_check2;
L_loop2:
        entry = *(int *)(*(char **)(base + 0x910) + offset + 0x20);
        if (entry != 0) {
            fn_802328D4(*(int *)entry);
            *(int *)entry = zero;
            fn_80128668((void *)entry);
        }
        offset += 0x24;
        textIndex++;
L_check2:
        if (textIndex < *(int *)(base + 0x914))
            goto L_loop2;
        zero = 0;
        *(int *)(base + 0x914) = zero;

        soundIndex = 0;
        offset = 0;
        goto L_check3;
L_loop3:
        soundObj = *(void **)(*(char **)(base + 0xd9c) + offset + 0x20);
        if (soundObj != 0)
            ((Release *)soundObj)->release(1);
        offset += 0x2c;
        soundIndex++;
L_check3:
        if (soundIndex < *(int *)(base + 0xda0))
            goto L_loop3;
        zero = 0;
        *(int *)(base + 0xda0) = zero;
        if ((char *)base + 0xd9c != 0) {
            if ((char *)base + (unsigned)0xd9c != 0) {
                *(int *)(base + 0xd9c) = 0;
                *(int *)(base + 0xda0) = 0;
                *(int *)(base + 0xda4) = 0;
            }
        }
        if ((char *)base + 0x910 != 0) {
            if ((char *)base + 0x910 != 0) {
                *(int *)(base + 0x910) = zero;
                *(int *)(base + 0x914) = zero;
                *(int *)(base + 0x918) = zero;
            }
        }
        if ((char *)base + 4 != 0) {
            if ((char *)base + 4 != 0) {
                *(int *)(base + 4) = zero;
                *(int *)(base + 8) = zero;
                *(int *)(base + 0xc) = zero;
            }
        }
        if (freeManager > 0)
            fn_80128668(mgr);
    }
    return mgr;
}
#pragma cplusplus reset
#pragma use_lmw_stmw on
#pragma scheduling on
extern int ArtSetGet(void *);

/* One entry of UIObjects_impl's object table (array at +0x04, count at +0x08,
 * 0x20 entries of 0x48 bytes; fn_80258550 adds them and fn_8025878C,
 * fn_802588C8, fn_80258A00, fn_80258AB0, fn_80258B60 and fn_80258C08 look them
 * up by name).  The pair at +0x40 says which item of an art set the object
 * shows: getPictureWidth and getPictureHeight read that item's two floats, which the
 * callers use as the x and y offset to draw at. */
typedef struct UIObjectEntry {
    char name[0x20];    /* +0x00 what callers look the object up by */
    char artName[0x20]; /* +0x20 name of the art set it draws from */
    void *art;          /* +0x40 the art set, referenced (see ArtSetGet) */
    int item;           /* +0x44 which item of that art set */
} UIObjectEntry;        /* == 0x48 */

#pragma scheduling invalid_target
/* UIObjects_impl: add a named object to the manager's object table.  The next
 * free entry (+0x04 array, its count at +0x08 incremented here) takes a copy of
 * the name callers look the object up by and of the art set's name -- both at
 * most 0x20 characters, the last one given up to the terminator when the string
 * is longer -- then a reference on that art set and the number of the item
 * within it the object shows. */
void fn_80258550(void *mgr, const char *name, const char *artName, int item) {
    UIObjectEntry *entry;
    int remaining;
    char *dst;
    remaining = 0x20;
    entry = &((UIObjectEntry *)*(unsigned int *)((char *)mgr + 4))[( *(int *)((char *)mgr + 8))++];
    dst = entry->name;
    goto copy1;
check1:
    if (--remaining > 0) goto copy1;
    dst[-1] = 0;
    goto copied1;
copy1:
    if ((*dst++ = *name++) != 0) goto check1;
copied1:
    name = artName;
    dst = entry->artName;
    remaining = 0x20;
    goto copy2;
check2:
    if (--remaining > 0) goto copy2;
    dst[-1] = 0;
    goto copied2;
copy2:
    if ((*dst++ = *name++) != 0) goto check2;
copied2:
    entry->art = (void *)ArtSetGet((void *)artName);
    entry->item = item;
}
#pragma scheduling on
/* Append a named text entry to the UI object manager's text table: copy `name`
 * into the next 0x24-byte slot, allocate and initialize a UITextObject (its
 * font handle comes from loadFontTexture(`fontName`)) and store it in that slot. */
void fn_8025861C(void *mgr, const char *name, void *fontName) {
    char *entry;
    int count = 0x20;
    char *dst;
    void *text;
    entry = *(char **)((char *)mgr + 0x910) + (*(int *)((char *)mgr + 0x914))++ * 0x24;
    dst = entry;
    goto copy;
check:
    if (--count > 0) {
        goto copy;
    }
    dst[-1] = 0;
    goto copied;
copy:
    if ((*dst++ = *name++) != 0) {
        goto check;
    }
copied:
    text = fn_801284F8(0x14, lbl_8055C258);
    if (text != 0) {
        ((int *)text)[0] = 0;
        ((int *)text)[1] = -1;
        ((int *)text)[2] = 9;
        ((float *)text)[3] = 1.0f;
        ((float *)text)[4] = 1.0f;
        ((int *)text)[0] = loadFontTexture(fontName);
    }
    *(void **)(entry + 0x20) = text;
}
#pragma scheduling on
extern void *fn_80207848(int, int);
extern float lbl_80563AC8;
#pragma scheduling invalid_target
/* Add a named sound to a container's list: copy the name (up to 32 chars), allocate the sound object for resourceId, then store it with flags and a default float value. */ void fn_802586F0(void *container, void *name, int resourceId, int flags) {
    char *containerData = (char *)container;
    int charBudget = 0x20;
    char *entry;
    char *dst;
    char *src = (char *)name;
    entry = *(char **)(containerData + 0xD9C) + (*(int *)(containerData + 0xDA0))++ * 0x2C;
    dst = entry;
    goto copy;
check:
    if (--charBudget > 0) {
        goto copy;
    }
    dst[-1] = 0;
    goto done;
copy:
    if ((*dst++ = *src++) != 0) {
        goto check;
    }
done:
    *(void **)(entry + 0x20) = fn_80207848(resourceId, 0);
    *(float *)(entry + 0x28) = lbl_80563AC8;
    *(char *)(entry + 0x24) = (char)flags;
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_8025878C(void *arg0, const char *arg1, int flags, int arg3, float x, float y)
{
  int new_var2;
  int index = 0x44 * 0;
  int offset = 0;
  float cosine;
  float sine;
  int new_var;
  goto check;
  loop:
  switch (((unsigned int) __cntlzw(stricmp((const char *) ((*((unsigned int *) (((char *) arg0) + 4))) + offset), arg1))) >> 5)
  {
    case 0:
      offset += 0x48;
      index++;
      goto check;

    default:
      goto found;

  }


  check:
  if (index < (*((int *) (((char *) arg0) + 8))))
  {
    goto loop;
  }

  new_var = 0x40;
  index = -1;
  found:
  if (index < 0)
  {
    return;
  }

  index = (int) ((*((unsigned int *) (((char *) arg0) + 4))) + (index * 0x48));
  cosine = getPictureWidth(*((int *) (index + new_var)), *((int *) (index + 0x44)));
  sine = getPictureHeight(*((int *) (index + new_var)), *((int *) (index + 0x44)));
  if (flags & 2)
  {
    x -= cosine;
  }
  else
    if (flags & 4)
  {
    x -= lbl_80563ACC * cosine;
  }
  new_var2 = *((int *) (index + new_var));
  if (flags & new_var)
  {
    y += sine;
  }
  else
    if (flags & 0x10)
  {
    y += lbl_80563ACC * sine;
  }
  ((void (*)(int, int, int, float, float, float, float, float)) drawPictureScaled)(new_var2, *((int *) (index + 0x44)), arg3, x, y, lbl_80563AD0, cosine, sine);
}
#pragma opt_common_subs off
void fn_802588C8(void *arg0, const char *arg1, int flags, int arg3, float x, float y, float scale)
{
  int index = 0;
  int offset = 0;
  int result;
  int new_var;
  float c;
  float s;
  goto check;
  loop:
  result = stricmp((const char *) ((*((unsigned int *) (((char *) arg0) + 4))) + offset), arg1);

  switch (((unsigned int) __cntlzw(result)) >> 5)
  {
    case 0:
      offset += 0x48;
      index++;
      goto check;

    default:
      goto found;

  }

  check:
  if (index < (*((int *) (((char *) arg0) + 8))))
  {
    goto loop;
  }

  index = -1;
  found:
  if (index < 0)
  {
    return;
  }

  index = (*((int *) (((char *) arg0) + 4))) + (index * 0x48);
  new_var = flags & 0x10;
  c = scale * getPictureWidth(*((int *) (index + 0x40)), *((int *) (index + 0x44)));
  s = scale * getPictureHeight(*((int *) (index + 0x40)), *((int *) (index + 0x44)));
  if (flags & 2)
  {
    x -= c;
  }
  else
    if (flags & 4)
  {
    x -= lbl_80563ACC * c;
  }
  if (flags & 0x40)
  {
    y += s;
  }
  else
  {
 do { } while (0);
    if (new_var)
    {
      y += lbl_80563ACC * s;
    }
  }
  ((void (*)(int, int, int, float, float, float, float, float)) drawPictureScaled)(*((int *) (index + 0x40)), *((int *) (index + 0x44)), arg3, x, y, lbl_80563AD0, c, s);
}
/* Look up a named entry in a 0x48-byte stride table and return its value via getPictureWidth, or 0.0f if not found. */
float fn_80258A00(void *table, int name) {
    int index = 0;
    int offset = 0;
    int compareResult;
    goto check;
loop:
    compareResult = stricmp((const char *)(*(unsigned int *)((char *)table + 4) + offset), (const char *)name);
    if (((unsigned int)__cntlzw(compareResult) >> 5)) {
        if (lbl_80563AD0) goto found;
        else goto found;
    }
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)table + 8)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        unsigned int entry = *(unsigned int *)((char *)table + 4) + index * 0x48;
        return getPictureWidth(*(unsigned int *)(entry + 0x40), *(unsigned int *)(entry + 0x44));
    }
    return lbl_80563AD0;
}

// Look up a named entry in a 0x48-byte stride table and return its computed float value, or 0.0f if not found.
float fn_80258AB0(void *table, int name) {
    int index = 0;
    int offset = 0;
    int compareResult;
    goto check;
loop:
    compareResult = stricmp((const char *)(*(unsigned int *)((char *)table + 4) + offset), (const char *)name);
    if (((unsigned int)__cntlzw(compareResult) >> 5)) {
        if (lbl_80563AD0) goto found;
        else goto found;
    }
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)table + 8)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        unsigned int entry = *(unsigned int *)((char *)table + 4) + index * 0x48;
        return getPictureHeight(*(unsigned int *)(entry + 0x40), *(unsigned int *)(entry + 0x44));
    }
    return lbl_80563AD0;
}

#pragma push
#pragma scheduling on
// Find an entry by name in a table of 0x48-byte records (array at table + 4,
// count at table + 8) and return a pointer to the field at +0x20 in the
// matching record, or 0 if not found.
void *fn_80258B60(void *table, const char *name) {
    int index = 0;
    int offset = 0;
    int compareResult;
    goto check;
loop:
    compareResult = stricmp((const char *)(*(unsigned int *)((char *)table + 4) + offset), name);
    switch (((unsigned int)__cntlzw(compareResult) >> 5)) {
    case 0:
        goto increment;
    default:
        goto found;
    }
increment:
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)table + 8))
        goto loop;
    index = -1;
found:
    if (index >= 0) {
        int byteOffset = index;
        byteOffset *= 0x48;
        return (void *)((char *)*(unsigned int *)((char *)table + 4) + byteOffset + 0x20);
    }
    return 0;
}

int fn_80258C08(void *mgr, const char *name) {
    int index = 0;
    int offset = 0;
    char *entries;
    int entry_offset;
    int len;
    /* Look up name in UIObjectEntry table (+4, count +8, stride 0x48) and return the item id at +0x44, or 0. */
    goto check;
loop:
    len = stricmp((const char *)(*(unsigned int *)((char *)mgr + 4) + offset), name);
    switch (((unsigned int)__cntlzw(len) >> 5)) {
    case 0:
        goto increment;
    default:
        goto found;
    }
increment:
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)mgr + 8)) {
        goto loop;
    }
    index = -1;
found:
    if (index >= 0) {
        entry_offset = index * 0x48;
        entries = *(char **)((char *)mgr + 4);
        return *(int *)(entries + entry_offset + 0x44);
    }
    return 0;
}

int fn_80258CB0(void *mgr, const char *name) {
    int index = 0;
    int offset = 0;
    int len;
    /* Look up name in the text-entry table (+0x910, count +0x914, stride 0x24) and return its +0x20 value, or 0. */
    goto check;
loop:
    len = stricmp((const char *)(*(unsigned int *)((char *)mgr + 0x910) + offset), name);
    switch (((unsigned int)__cntlzw(len) >> 5)) {
    case 0:
        goto increment;
    default:
        goto found;
    }
increment:
    offset += 0x24;
    index++;
check:
    if (index < *(int *)((char *)mgr + 0x914))
        goto loop;
    index = -1;
found:
    if (index >= 0) {
        int byte_offset = index;
        byte_offset *= 0x24;
        return *(int *)((char *)*(unsigned int *)((char *)mgr + 0x910) + byte_offset + 0x20);
    }
    return 0;
}

#pragma pop
extern int stricmp(const char *, const char *);
extern int fn_80232B70(int, int, int);
extern double lbl_80563AD8;

/* The per-text object UIObjects_impl keeps (0x14 bytes, alloc name "gText";
 * created by fn_8025861C). */
typedef struct UITextObject {
    void *font;    /* +0x00 font block loaded by gText (loadFontTexture) */
    int value;     /* +0x04 -1 until a caller sets it */
    unsigned int flags; /* +0x08 draw flags, 9 when created */
    float scale;   /* +0x0C pixels per font unit */
    float field10; /* +0x10 0 when created */
} UITextObject;

/* One entry of the manager's text table (array at +0x910, count at +0x914,
 * 0x24 bytes each: a 0x20-byte name and the object drawn for it). */
typedef struct UITextEntry {
    char name[0x20];
    UITextObject *text;
} UITextEntry;

/* UIObjects_impl: set up the named text object.  Looks the name up in the
 * manager's text table (+0x910, count +0x914), copies the low seven bits of
 * `flags` into the object's draw flags, makes its scale `height` pixels over
 * the font's own height (gText keeps that as a byte in the font block) and
 * stores `value`; returns the object, or 0 when the name is unknown. */
void *fn_80258D58(void *mgr, const char *name, int flags, int height, int value) {
    char *base = (char *)mgr;
    int index = 0;
    int offset = 0;
    int compare;
    UITextObject *text;
    unsigned int old;
    unsigned int temp;
    unsigned int mask;
    goto check;
loop:
    compare = stricmp((*(UITextEntry **)(base + 0x910))->name + offset, name);
    switch ((unsigned int)__cntlzw((unsigned int)compare) >> 5) {
    case 0:
        goto increment;
    default:
        goto found;
    }
increment:
    offset += 0x24;
    index++;
check:
    if (index < *(int *)(base + 0x914))
        goto loop;
    index = -1;
found:
    if (index >= 0) {
        int divisor;
        text = *(UITextObject **)(*(char **)(base + 0x910) + index * 0x24 + 0x20);
        temp = (unsigned int)flags & 7;
        old = text->flags;
        mask = (unsigned int)flags & 0x78;
        temp = __rlwimi(temp, old, 0, 0, 28);
        text->flags = (temp & ~0x58U) | mask;
        divisor = fn_80232B70((int)text->font, temp, old);
        text->scale = (float)height / (float)divisor;
        text->value = value;
        return text;
    }
    return 0;
}

extern float fn_80209028(void);
/* Find a named sub-object entry on this object, apply its timed value, and update
 * playback/control flags based on whether the entry requests a restart. */
/* Find the named entry in root's table at +0xD9C (count +0xDA0, stride 0x2C); apply its timed value to the referenced object and set its playback/control flags, requesting a restart when the entry's flag at +0x24 is set. */ void fn_80258E64(void *root, const char *name) {
    int index = 0;
    int offset = 0;
    void *obj;
    float value;

    goto check;
loop:
    switch ((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)root + 0xD9C) + offset), name)) >> 5) {
    case 0:
        offset += 0x2C;
        index++;
        goto check;
    default:
        goto found;
    }
check:
    if (index < *(int *)((char *)root + 0xDA0))
        goto loop;
    index = -1;
found:
    if (index < 0)
        return;
    index = (int)(*(unsigned int *)((char *)root + 0xD9C) + index * 0x2C);
    if (*(void **)(index + 0x20) == 0)
        return;
    value = *(float *)(index + 0x28) * fn_80209028();
    obj = *(void **)(index + 0x20);
    if (value != *(float *)((char *)obj + 8)) {
        *(unsigned char *)((char *)obj + 0x4D) = 1;
        *(float *)((char *)obj + 8) = value;
    }
    if (*(unsigned char *)(index + 0x24)) {
        obj = *(void **)(index + 0x20);
        *(unsigned char *)((char *)obj + 0x4A) = 0;
        *(unsigned char *)((char *)obj + 0x4B) = 1;
        *(unsigned char *)((char *)obj + 0x49) = 1;
        return;
    }
    obj = *(void **)(index + 0x20);
    if (*(unsigned char *)((char *)obj + 0x19)) {
        *(unsigned char *)((char *)obj + 0x4C) = 1;
        *(unsigned char *)((char *)obj + 0x4A) = 0;
    }
    obj = *(void **)(index + 0x20);
    *(unsigned char *)((char *)obj + 0x49) = 1;
    *(unsigned char *)((char *)obj + 0x4B) = 0;
    *(unsigned char *)((char *)obj + 0x4A) = 0;
}

/* Find the named entry (table at +0xD9C, count at +0xDA0, stride 0x2C) and mark its object active (+0x4A=1, +0x4C=0). */
/* Find the named entry in root's table at +0xD9C (count +0xDA0, stride 0x2C) and mark its object active (+0x4A=1, +0x4C=0). */ void fn_80258F94(void *root, const char *name) {
    int index = 0;
    int offset = 0;
    unsigned int entry;
    void *object;
    goto check;
loop:
    switch ((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)root + 0xD9C) + offset), name)) >> 5) {
    case 0:
        offset += 0x2C;
        index++;
        goto check;
    default:
        goto found;
    }
check:
    if (index < *(int *)((char *)root + 0xDA0)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        entry = *(unsigned int *)((char *)root + 0xD9C);
        entry += index * 0x2C;
        object = *(void **)(entry + 0x20);
        if (object != 0) {
            *(unsigned char *)((char *)object + 0x4A) = 1;
            *(unsigned char *)((char *)object + 0x4C) = 0;
        }
    }
}

#pragma scheduling invalid_target
/* Find the named entry (entries at +0xD9C, count at +0xDA0, stride 0x2C) and set its float value at +0x28. */
void fn_8025904C(void *table, int name, float value) {
    int index = 0;
    int offset = 0;
    int cmp;
    goto check;
loop:
    cmp = stricmp((const char *)(*(unsigned int *)((char *)table + 0xD9C) + offset), (const char *)name);
    if (((unsigned int)__cntlzw(cmp) >> 5)) {
        if (lbl_80563AD0) goto found;
        else goto found;
    }
    offset += 0x2C;
    index++;
check:
    if (index < *(int *)((char *)table + 0xDA0)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        struct Entry { char pad[0x28]; float value; };
        ((struct Entry *)(*(unsigned int *)((char *)table + 0xD9C)))[index].value = value;
    }
}
#pragma scheduling on

