// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern char lbl_80498664[];

__declspec(section ".sdata") extern char lbl_8055BA18[], lbl_8055BA1C[], lbl_8055BA24[], lbl_8055BA2C[];
__declspec(section ".sdata") extern char lbl_8055BA38[], lbl_8055BA40[], lbl_8055BA48[], lbl_8055BA50[];
__declspec(section ".sdata") extern char lbl_8055BA58[], lbl_8055BA60[], lbl_8055BA68[], lbl_8055BA70[];
__declspec(section ".sdata") extern char lbl_8055BA78[], lbl_8055BA80[], lbl_8055BA88[], lbl_8055BA90[];
__declspec(section ".sdata") extern char lbl_8055BA98[], lbl_8055BAA0[], lbl_8055BAA4[], lbl_8055BAAC[];
__declspec(section ".sdata") extern char lbl_8055F0C6;
__declspec(section ".sdata") extern int lbl_8055F0B0, lbl_8055F0B4, lbl_8055F0B8;

typedef struct {
    float time;
    float f4;
    float f8;
    float fc;
    float f10;
} TrailKey;

typedef struct {
    unsigned char pad[0x20];
    int field20;
    TrailKey *keys;
    int keyCount;
    unsigned char flag2C;
    unsigned char active;
    float field30;
} TrailEntry;

typedef struct {
    unsigned char pad[4];
    TrailEntry *entries;
    int count;
} TrailMgr;

typedef struct {
    void *object;
    TrailKey *keys;
    int keyCount;
} AnimEntry;

typedef struct {
    void *vtable;
    AnimEntry *entries;
    int count;
    float duration;
} AnimMgr;
extern int stricmp(const char *, const char *);
extern char lbl_8034094C[];
extern void *fn_801284F8(int, char *);
extern float lbl_805636E0;
extern void fn_8002F6AC(void *, void (*)(void));
extern void fn_80128668(void *);
extern void *fn_80237968(void *, int);
extern void fn_80237A08(void);
extern char lbl_8034095C[];
extern char lbl_80340970[];

extern int lbl_8055F0B0;
extern int lbl_8055F0B4;
extern int lbl_8055F0B8;
extern char *lbl_8055F0BC;
extern char *lbl_8055F0C0;
extern char lbl_8055F0C4;
extern char lbl_8055F0C5;
extern char lbl_8055F0C6;
extern char lbl_8055F0C7;
typedef struct QueueNode_80236848 {
    unsigned char pad[0x24];
    struct QueueNode_80236848 *next;
} QueueNode_80236848;
extern void fn_802E317C(const char *);
extern char lbl_80340910[];
void fn_80236728(void) {
    if (lbl_8055F0C4 != 0) {
        fn_802E317C(lbl_80340910);
    }
    lbl_8055F0BC = 0;
    lbl_8055F0C0 = 0;
    lbl_8055F0C4 = 1;
}

void fn_80236774(void) {
    lbl_8055F0C4 = 0;
}

extern void fn_80237D00(void *);
void fn_80236848(void) {
    QueueNode_80236848 *end = (QueueNode_80236848 *)lbl_8055F0C0;
    QueueNode_80236848 *node = (QueueNode_80236848 *)lbl_8055F0BC;

    if (node == end) {
        fn_80237D00(end);
        lbl_8055F0BC = 0;
        lbl_8055F0C0 = 0;
        return;
    }
    while (node->next != end) {
        node = node->next;
    }
    fn_80237D00(end);
    lbl_8055F0C0 = (char *)node;
    node->next = 0;
}

void fn_802368B4(int arg0) {
    if (((unsigned char *)lbl_8055F0C0)[arg0] == 0) {
        lbl_8055F0C0[arg0] = 1;
    }
}

void fn_802368D0(void) {
    lbl_8055F0C0[0x21] = 1;
}

extern char lbl_8055F0C5;
void fn_802368E0(void) {
    lbl_8055F0C5 = 1;
}

int fn_802368EC(void) {
    return (unsigned char)lbl_8055F0C0[0x21] == 0;
}

extern int fn_80215264(void);
extern void fn_80236A5C(void*, int);
extern void fn_80237AA0();
extern void fn_80236960();
extern char *lbl_8055F0C0;
void fn_80236900(void) {
    lbl_8055F0C0[0x21] = 0;
}

void fn_80236910(void) {
    fn_80236960();
}

void fn_80236914(void) {
    fn_80237AA0();
}

void fn_80236918(void* alarm) {
    fn_80236A5C(alarm, fn_80215264());
}

extern void fn_80237A9C(void);
extern void fn_80237DA0(void);
extern int fn_80237EFC(void);
void fn_80236950(void) { fn_80237A9C(); }

void fn_80236954(void) { fn_80237DA0(); }

extern void fn_80237E7C(char *, int);
void fn_80236958(char *arg0, int unused) { fn_80237E7C(arg0, unused); }

void fn_8023695C(void) { fn_80237EFC(); }

#pragma scheduling invalid_target
void fn_80236960(char *source) {
    int remaining;
    char *destination;
    if (source == 0)
        return;
    destination = lbl_80498664;
    remaining = 0x64;
    while ((*destination++ = *source++) != '\0') {
        if (--remaining > 0)
            continue;
        destination[-1] = '\0';
        return;
    }
}
#pragma scheduling on
void fn_802369A8(char *arg0, int arg1, int arg2) {
    extern char lbl_8055BA08[8], lbl_8055BA10[8];
    extern int fn_801345D8(void *, int, const char *, ...);
    extern char *fn_80029004(char *, int);
    char *dot;
    const char *suffix;
    fn_801345D8(arg0, arg1, lbl_8055BA08, arg2);
    dot = fn_80029004(arg0, '.');
    if (dot) *dot = 0;
    suffix = lbl_8055BA10;
    while ((signed char)*arg0) { --arg1; ++arg0; }
    if (arg1 > 0) {
        while ((signed char)(*arg0++ = *suffix++) != 0) {
            if (--arg1 <= 0) { arg0[-1] = 0; break; }
        }
    }
}

#pragma push
#pragma scheduling invalid_target
extern void *memset(void *, int, unsigned long);
extern char *strcpy(char *, const char *);
#pragma scheduling invalid_target
void fn_80236A5C(void *arg0, int arg1) {
    extern char lbl_80498664[];
    extern char lbl_8055BA18[], lbl_8055BA1C[], lbl_8055BA24[], lbl_8055BA2C[];
    extern char lbl_8055BA38[], lbl_8055BA70[], lbl_8055BA78[], lbl_8055BA80[], lbl_8055BAAC[];
    extern char lbl_8055BAA4[], lbl_8055BAA0[], lbl_8055BA98[], lbl_8055BA90[], lbl_8055BA88[];
    extern char lbl_8055BA68[], lbl_8055BA60[], lbl_8055BA50[], lbl_8055BA48[], lbl_8055BA40[], lbl_8055BA58[];
    extern char lbl_80340930[], lbl_80340940[], lbl_8034095C[], lbl_80340970[], lbl_803409DC[], lbl_803409E8[], lbl_80340A44[], lbl_80340A50[], lbl_80340A74[], lbl_80340AA4[], lbl_80340A18[], lbl_803409F4[], lbl_803409A8[], lbl_80340984[];
    extern char lbl_8055F0C6;
    extern float lbl_805636E0, lbl_805636E4;
    extern void *fn_80131810(char *);
    extern int fn_8002B1D8(const char *, const char *, int);
    extern void *fn_801284F8(int, char *);
    extern void *fn_8012850C(int, char *);
    extern void *fn_8002F37C(void *, void (*)(void *), void (*)(void), int, int);
    extern void fn_80237A84(void *);
    extern void fn_80237A08(void);
    extern void fn_80237A04(void);
    extern void fn_802379EC(void *);
    extern void *fn_80237968(void *, int);
    extern void fn_80131818(void *);
    extern void fn_802E30C8(const char *, ...);
    register void *parser;
    register int mode;
    float defaultZero, defaultOne;
    register void *list;
    register int index;
    register char *filename = (char *)arg1;
    char *elementName;
    char *elementText;
    AnimMgr *manager;
    void *node;
    AnimEntry *entry;
    void *detailList;
    void *child;
    void *keyOut;
    void *previous;
    char *(*get_name)(void *);
    int count;
    int childIndex;
    int keyCount;
    float defaults1[13];
    float defaults2[5];
    float value;
    unsigned long long pairBits1, pairBits2, pairBits3;
    float pairDefaults1[2], pairDefaults2[2], pairDefaults3[2];
    TrailMgr *trailMgr;
    void *group;
    void *trail;
    TrailEntry *trailEntry;
    void *trailKey;
    char *trailText;
    int groupIndex;
    int trailIndex;
    int trailCount;
    int trailKeyCount;
    int stringIndex;
    float trailDefaults[5];

    if (lbl_80498664[0] == 0)
        fn_802369A8(lbl_80498664, 0x64, (int)arg0);
    parser = fn_80131810(lbl_80498664);
    if (parser == 0)
        return;
    mode = 1;
    if (stricmp(filename, lbl_8055BA18) == 0) {
        mode = 0;
        goto mode_done;
    }
    if (mode != 0) {
        if (((int (*)(void *, const char *))(*(void * volatile **)parser)[4])(parser, lbl_8055BA1C) != 0) {
            list = ((void *(*)(void *, const char *))(*(void * volatile **)parser)[2])(parser, lbl_8055BA1C);
            index = 0;
            while (((int (*)(void *, int, char **, char **))(*(void * volatile **)list)[4])(list, index, &elementName, &elementText) != 0) {
                if (fn_8002B1D8(elementName, lbl_8055BA24, 6) == 0) {
                    if ((stricmp(elementText, lbl_8055BA2C) == 0) ||
                        (stricmp(elementText, filename) == 0)) {
                        mode = 0;
                        goto mode_done;
                    }
                }
                index++;
            }
        }
    }
mode_done:
    if (mode != 0)
        lbl_8055F0C6 = 1;
    manager = fn_801284F8(0x10, lbl_80340930);
    if (manager != 0) {
        manager->vtable = lbl_80340970;
        manager->entries = 0;
        manager->count = 0;
        manager->duration = lbl_805636E0;
        if (parser != 0) {
            index = 0;
            while ((node = ((void *(*)(void *, int))(*(void * volatile **)parser)[3])(parser, index)) != 0) {
                
                if (stricmp(((char *(*)(void *))(*(void * volatile **)node)[2])(node), lbl_8055BA80) == 0)
                    manager->count++;
                index++;
            }
        count = manager->count;
        if (count > 0) {
            manager->entries = (AnimEntry *)fn_8002F37C(
                fn_8012850C(count * 0xC + 0x10, lbl_8055BA78),
                fn_80237A84, fn_80237A08, 0xC, count);
            manager->count = 0;
            index = 0;
            while ((node = ((void *(*)(void *, int))(*(void * volatile **)parser)[3])(parser, index)) != 0) {
                
                if (stricmp(((char *(*)(void *))(*(void * volatile **)node)[2])(node), lbl_8055BA70) == 0) {
                    if (((void *(*)(void *, const char *))(*(void * volatile **)node)[0x5C / 4])(node, lbl_8055BA38) != 0) {
                        detailList = ((void *(*)(void *, const char *))(*(void * volatile **)node)[0x5C / 4])(node, lbl_8055BA38);
                        entry = &manager->entries[manager->count];
                        entry->object = ((void *(*)(void *, const char *))(*(void * volatile **)node)[0x1C / 4])(node, lbl_80340A44);
                        entry->keyCount = 0;
                        if (detailList != 0) {
                            childIndex = 0;
                            while ((child = ((void *(*)(void *, int))(*(void * volatile **)detailList)[0x60 / 4])(detailList, childIndex)) != 0) {
                                
                                if (stricmp(((char *(*)(void *))(*(void * volatile **)child)[2])(child), lbl_8055BAAC) == 0)
                                    (entry->keyCount)++;
                                childIndex++;
                            }
                            keyCount = entry->keyCount;
                            if (keyCount > 0) {
                                entry->keys = fn_8002F37C(
                                    fn_8012850C(keyCount * 0x14 + 0x10, lbl_80340AA4),
                                    (void (*)(void *))fn_80237A04, 0, 0x14, keyCount);
                                entry->keyCount = 0;
                                defaultZero = lbl_805636E0;
                                defaultOne = lbl_805636E4;
                                defaults1[0] = defaultZero;
                                defaults1[2] = defaultOne;
                                defaults1[1] = defaultOne;
                                defaults1[3] = defaultZero;
                                defaults1[4] = defaultZero;
                                childIndex = 0;
                                while ((child = ((void *(*)(void *, int))(*(void * volatile **)detailList)[0x60 / 4])(detailList, childIndex)) != 0) {
                                    
                                    if (stricmp(((char *(*)(void *))(*(void * volatile **)child)[2])(child), lbl_8055BAA4) == 0) {
                                        count = entry->keyCount;
                                        if (count > 0)
                                            previous = (char *)entry->keys + (count - 1) * 0x14;
                                        else
                                            previous = defaults1;
                                        keyOut = (char *)entry->keys + count * 0x14;
                                        (entry->keyCount)++;
                                        value = ((float (*)(void *, const char *))(*(void * volatile **)child)[0x24 / 4])(child, lbl_8055BAA0);
                                        *(float *)keyOut = value;
                                        *(float *)((char *)keyOut + 8) = ((float (*)(void *, const char *, float))(*(void * volatile **)child)[0x28 / 4])(child, lbl_8055BA98, *(float *)((char *)previous + 8));
                                        *(float *)((char *)keyOut + 4) = ((float (*)(void *, const char *, float))(*(void * volatile **)child)[0x28 / 4])(child, lbl_8055BA90, *(float *)((char *)previous + 4));
                                        pairDefaults1[0] = *(float *)((char *)previous + 0xC);
                                        pairDefaults1[1] = *(float *)((char *)previous + 0x10);
                                        pairBits1 = ((unsigned long long (*)(void *, const char *, float *))(*(void * volatile **)child)[0x40 / 4])(child, lbl_8055BA88, pairDefaults1);
                                        *(float *)((char *)keyOut + 0xC) = *(float *)&pairBits1;
                                        *(float *)((char *)keyOut + 0x10) = *((float *)&pairBits1 + 1);
                                    }
                                    childIndex++;
                                }
                            }
                        }
                        if (detailList == 0)
                            fn_802E30C8(lbl_80340A74, entry->object);
                        fn_802E30C8(lbl_80340A50, entry->object);
                        count = entry->keyCount;
                        if (count > 0)
                            value = *(float *)((char *)entry->keys + count * 0x14 - 0x14);
                        else
                            value = lbl_805636E0;
                        if (value < manager->duration)
                            manager->duration = value;
                        manager->count++;
                    }
                }
                index++;
            }
        } else {
            fn_802E30C8(lbl_803409F4, lbl_80498664);
        }
        } else {
            fn_802E30C8(lbl_80340A18, lbl_80498664);
        }
    }
    lbl_8055F0B0 = (int)manager;
    manager = fn_801284F8(0x10, lbl_80340930);
    if (manager != 0) {
        manager->vtable = lbl_80340970;
        manager->entries = 0;
        manager->count = 0;
        manager->duration = lbl_805636E0;
        if (parser != 0) {
            index = 0;
        while ((node = ((void *(*)(void *, int))(*(void * volatile **)parser)[3])(parser, index)) != 0) {
            
            if (stricmp(((char *(*)(void *))(*(void * volatile **)node)[2])(node), lbl_8055BA80) == 0)
                manager->count++;
            index++;
        }
        count = manager->count;
        if (count > 0) {
            manager->entries = (AnimEntry *)fn_8002F37C(
                fn_8012850C(count * 0xC + 0x10, lbl_8055BA78),
                fn_80237A84, fn_80237A08, 0xC, count);
            manager->count = 0;
            index = 0;
            while ((node = ((void *(*)(void *, int))(*(void * volatile **)parser)[3])(parser, index)) != 0) {
                
                if (stricmp(((char *(*)(void *))(*(void * volatile **)node)[2])(node), lbl_8055BA70) == 0) {
                    if (((void *(*)(void *, const char *))(*(void * volatile **)node)[0x5C / 4])(node, lbl_80340940) != 0) {
                        detailList = ((void *(*)(void *, const char *))(*(void * volatile **)node)[0x5C / 4])(node, lbl_80340940);
                        entry = &manager->entries[manager->count];
                        entry->object = ((void *(*)(void *, const char *))(*(void * volatile **)node)[0x1C / 4])(node, lbl_80340A44);
                        entry->keyCount = 0;
                        if (detailList != 0) {
                            childIndex = 0;
                            while ((child = ((void *(*)(void *, int))(*(void * volatile **)detailList)[0x60 / 4])(detailList, childIndex)) != 0) {
                                
                                if (stricmp(((char *(*)(void *))(*(void * volatile **)child)[2])(child), lbl_8055BAAC) == 0)
                                    (entry->keyCount)++;
                                childIndex++;
                            }
                            keyCount = entry->keyCount;
                            if (keyCount > 0) {
                                entry->keys = fn_8002F37C(
                                    fn_8012850C(keyCount * 0x14 + 0x10, lbl_80340AA4),
                                    (void (*)(void *))fn_80237A04, 0, 0x14, keyCount);
                                entry->keyCount = 0;
                                defaultZero = lbl_805636E0;
                                defaultOne = lbl_805636E4;
                                defaults2[0] = defaultZero;
                                defaults2[2] = defaultOne;
                                defaults2[1] = defaultOne;
                                defaults2[3] = defaultZero;
                                defaults2[4] = defaultZero;
                                childIndex = 0;
                                while ((child = ((void *(*)(void *, int))(*(void * volatile **)detailList)[0x60 / 4])(detailList, childIndex)) != 0) {
                                    
                                    if (stricmp(((char *(*)(void *))(*(void * volatile **)child)[2])(child), lbl_8055BAA4) == 0) {
                                        count = entry->keyCount;
                                        if (count > 0)
                                            previous = (char *)entry->keys + (count - 1) * 0x14;
                                        else
                                            previous = defaults2;
                                        keyOut = (char *)entry->keys + count * 0x14;
                                        (entry->keyCount)++;
                                        *(float *)keyOut = ((float (*)(void *, const char *))(*(void * volatile **)child)[0x24 / 4])(child, lbl_8055BAA0);
                                        *(float *)((char *)keyOut + 8) = ((float (*)(void *, const char *, float))(*(void * volatile **)child)[0x28 / 4])(child, lbl_8055BA98, *(float *)((char *)previous + 8));
                                        *(float *)((char *)keyOut + 4) = ((float (*)(void *, const char *, float))(*(void * volatile **)child)[0x28 / 4])(child, lbl_8055BA90, *(float *)((char *)previous + 4));
                                        pairDefaults2[0] = *(float *)((char *)previous + 0xC);
                                        pairDefaults2[1] = *(float *)((char *)previous + 0x10);
                                        pairBits2 = ((unsigned long long (*)(void *, const char *, float *))(*(void * volatile **)child)[0x40 / 4])(child, lbl_8055BA88, pairDefaults2);
                                        *(float *)((char *)keyOut + 0xC) = *(float *)&pairBits2;
                                        *(float *)((char *)keyOut + 0x10) = *((float *)&pairBits2 + 1);
                                    }
                                    childIndex++;
                                }
                            }
                        }
                        if (detailList == 0)
                            fn_802E30C8(lbl_80340A74, entry->object);
                        fn_802E30C8(lbl_80340A50, entry->object);
                        count = entry->keyCount;
                        if (count > 0)
                            value = *(float *)((char *)entry->keys + count * 0x14 - 0x14);
                        else
                            value = lbl_805636E0;
                        if (value < manager->duration)
                            manager->duration = value;
                        manager->count++;
                    }
                }
                index++;
            }
            } else {
                fn_802E30C8(lbl_80340A18, lbl_80498664);
            }
        } else {
            fn_802E30C8(lbl_803409F4, lbl_80498664);
        }
    }
    lbl_8055F0B4 = (int)manager;

    trailMgr = fn_801284F8(0xC, lbl_80340930);
    if (trailMgr != 0) {
        *(void **)trailMgr = lbl_8034095C;
        trailMgr->entries = 0;
        trailMgr->count = 0;
        if (parser != 0) {
            groupIndex = 0;
        while ((group = ((void *(*)(void *, int))(*(void * volatile **)parser)[3])(parser, groupIndex)) != 0) {
            
            if (stricmp(((char *(*)(void *))(*(void * volatile **)group)[2])(group), lbl_8055BA68) == 0) {
                trailIndex = 0;
                while ((trail = ((void *(*)(void *, int))(*(void * volatile **)group)[0x60 / 4])(group, trailIndex)) != 0) {
                    
                    if (stricmp(((char *(*)(void *))(*(void * volatile **)trail)[2])(trail), lbl_8055BA60) == 0)
                        trailMgr->count++;
                    trailIndex++;
                }
            }
            groupIndex++;
        }
        trailCount = trailMgr->count;
        if (trailCount > 0) {
            trailMgr->entries = (TrailEntry *)fn_8002F37C(
                fn_8012850C(trailCount * 0x34 + 0x10, lbl_8055BA58),
                fn_802379EC, (void (*)(void))fn_80237968, 0x34, trailCount);
            trailMgr->count = 0;
            groupIndex = 0;
            while ((group = ((void *(*)(void *, int))(*(void * volatile **)parser)[3])(parser, groupIndex)) != 0) {
                
                if (stricmp(((char *(*)(void *))(*(void * volatile **)group)[2])(group), lbl_8055BA50) == 0) {
                    trailIndex = 0;
                    while ((trail = ((void *(*)(void *, int))(*(void * volatile **)group)[0x60 / 4])(group, trailIndex)) != 0) {
                        
                        if (stricmp(((char *(*)(void *))(*(void * volatile **)trail)[2])(trail), lbl_8055BA48) == 0) {
                            trailEntry = &trailMgr->entries[trailMgr->count];
                            trailEntry->flag2C =
                                ((unsigned char (*)(void *, const char *, int))(*(void * volatile **)trail)[0x30 / 4])(trail, lbl_803409E8, 0);
                            trailText = ((char *(*)(void *, const char *))(*(void * volatile **)trail)[0x14 / 4])(trail, lbl_8055BA40);
                            memset((char *)trailEntry, 0, 0x1E);
                            {
                                char *copyDest = (char *)trailEntry;
                                char *copySrc = trailText;
                                char ch;
                                do {
                                    ch = *copySrc++;
                                    *copyDest++ = ch;
                                } while (ch != 0);
                            }
                            trailEntry->active = 0;
                            trailEntry->field20 = (int)
                                ((void *(*)(void *, const char *))(*(void * volatile **)group)[0x1C / 4])(group, lbl_803409DC);
                            trailEntry->keyCount = 0;
                            trailIndex = trailIndex;
                            if (trail != 0) {
                            trailKeyCount = 0;
                            keyCount = 0;
                            while ((trailKey = ((void *(*)(void *, int))(*(void * volatile **)trail)[0x60 / 4])(trail, keyCount)) != 0) {
                                
                                if (stricmp(((char *(*)(void *))(*(void * volatile **)trailKey)[2])(trailKey), lbl_8055BAAC) == 0)
                                    trailKeyCount++;
                                keyCount++;
                            }
                            trailEntry->keyCount = trailKeyCount;
                            if (trailKeyCount > 0) {
                                trailEntry->keys = fn_8002F37C(
                                    fn_8012850C(trailKeyCount * 0x14 + 0x10, lbl_80340AA4),
                                    (void (*)(void *))fn_80237A04, 0, 0x14, trailKeyCount);
                                trailEntry->keyCount = 0;
                                defaultZero = lbl_805636E0;
                                defaultOne = lbl_805636E4;
                                trailDefaults[0] = defaultZero;
                                trailDefaults[2] = defaultOne;
                                trailDefaults[1] = defaultOne;
                                trailDefaults[3] = defaultZero;
                                trailDefaults[4] = defaultZero;
                                keyCount = 0;
                                while ((trailKey = ((void *(*)(void *, int))(*(void * volatile **)trail)[0x60 / 4])(trail, keyCount)) != 0) {
                                    
                                    if (stricmp(((char *(*)(void *))(*(void * volatile **)trailKey)[2])(trailKey), lbl_8055BAA4) == 0) {
                                        count = trailEntry->keyCount;
                                        if (count > 0)
                                            previous = (char *)trailEntry->keys + (count - 1) * 0x14;
                                        else
                                            previous = trailDefaults;
                                        keyOut = (char *)trailEntry->keys + count * 0x14;
                                        (trailEntry->keyCount)++;
                                        *(float *)keyOut = ((float (*)(void *, const char *))(*(void * volatile **)trailKey)[0x24 / 4])(trailKey, lbl_8055BAA0);
                                        *(float *)((char *)keyOut + 8) = ((float (*)(void *, const char *, float))(*(void * volatile **)trailKey)[0x28 / 4])(trailKey, lbl_8055BA98, *(float *)((char *)previous + 8));
                                        *(float *)((char *)keyOut + 4) = ((float (*)(void *, const char *, float))(*(void * volatile **)trailKey)[0x28 / 4])(trailKey, lbl_8055BA90, *(float *)((char *)previous + 4));
                                        pairDefaults3[0] = *(float *)((char *)previous + 0xC);
                                        pairDefaults3[1] = *(float *)((char *)previous + 0x10);
                                        pairBits3 = ((unsigned long long (*)(void *, const char *, float *))(*(void * volatile **)trailKey)[0x40 / 4])(trailKey, lbl_8055BA88, pairDefaults3);
                                        *(float *)((char *)keyOut + 0xC) = *(float *)&pairBits3;
                                        *(float *)((char *)keyOut + 0x10) = *((float *)&pairBits3 + 1);
                                    }
                                    keyCount++;
                                }
                            }
                            }
                            trailMgr->count++;
                        }
                        trailIndex++;
                    }
                }
                groupIndex++;
            }
        }
        } else {
            fn_802E30C8(lbl_803409A8, lbl_80498664);
            fn_802E30C8(lbl_80340984, lbl_80498664);
        }
    }
    lbl_8055F0B8 = (int)trailMgr;
    fn_80131818(parser);
    lbl_80498664[0] = 0;

}
#pragma scheduling on
void fn_802379EC(void *arg0) {
    int minus = -1;
    int zero = 0;
    *(int *)((char *)arg0 + 0x20) = minus;
    *(int *)((char *)arg0 + 0x28) = zero;
    *(int *)((char *)arg0 + 0x24) = zero;
}

void fn_80237A04(void) {
}

void fn_80237A84(void *arg0) {
    *(int *)arg0 = -1;
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 4) = 0;
}

extern char lbl_8055BA08[];
extern char lbl_8055BA10[];
extern char lbl_80498664[];
extern char *fn_80029004(char *, int);
void fn_80237A9C(void) {
}

extern float lbl_805636E4;
void fn_80237AA0(arg0, arg1, arg2)
int arg0; void *arg1; double arg2;
{
    double var_f31 = arg2;
    float var_f1, var_f2;
    unsigned char var_r4;
    void *p;
    if (arg0 == 0) {
        p = *(void **)(lbl_8055F0C0 + 0x28);
        if (p) { void **v = *(void ***)p; var_f1 = ((float (*)(void))v[3])(); }
        else var_f1 = lbl_805636E0;
        *(float *)arg1 = var_f1;
        p = *(void **)(lbl_8055F0C0 + 0x2C);
        if (p) { void **v = *(void ***)p; var_f2 = ((float (*)(void))v[3])(); }
        else var_f2 = lbl_805636E0;
        *(float *)((char *)arg1 + 4) = var_f2;
        var_r4 = (unsigned char)lbl_8055F0C0[0x21];
        if (var_r4 == 0) {
            *(float *)((char *)arg1 + 4) = *(float *)arg1;
            *(float *)arg1 = var_f2;
        }
        if ((unsigned char)lbl_8055F0C0[0x1F] != 0) *(float *)arg1 = lbl_805636E0;
        if ((unsigned char)lbl_8055F0C0[0x20] != 0) *(float *)((char *)arg1 + 4) = lbl_805636E0;
    } else {
        if (arg0 == 3) {
            var_r4 = (unsigned char)lbl_8055F0C0[0x21];
            if (var_r4 != 0) var_f31 = (double)lbl_805636E4 - arg2;
        } else {
            var_r4 = (unsigned char)lbl_8055F0C0[0x21];
            if (var_r4 == 0) var_f31 = (double)lbl_805636E4 - arg2;
        }
        if ((unsigned int)(arg0 == 3) == var_r4) {
            p = *(void **)(lbl_8055F0C0 + 0x2C);
            if (p) { void **v = *(void ***)p; ((void (*)(double))v[4])(var_f31); }
        } else {
            p = *(void **)(lbl_8055F0C0 + 0x28);
            if (p) { void **v = *(void ***)p; ((void (*)(double))v[4])(var_f31); }
        }
        p = *(void **)(lbl_8055F0C0 + 0x30);
        if (p) { void **v = *(void ***)p; ((void (*)(double))v[4])(var_f31); }
    }
}

extern int stricmp(const char *, const char *);
extern char lbl_8034094C[];
extern void *fn_801284F8(int, char *);
void fn_80237C40(void)
{
  char *p = fn_801284F8(0x34, lbl_8034094C);
  int *new_var;
  int i;
  for (i = 0; i < 0x21; i++)
  {
    p[i] = 0;
  }

  *((int *) (p + 0x28)) = 0;
  *((int *) (p + 0x2c)) = 0;
  new_var = (int *) (p + 0x24);
  *new_var = 0;
}

void fn_80128668(void*);
void fn_80237D00(void *arg0) {
    void *p = *(void **)((char *)arg0 + 0x28);
    if (p != 0) {
        volatile void *q = p;
        if (q != 0) {
            void **vt = *(void ***)p;
            ((void (*)(void *, int))vt[2])(p, 1);
        }
    }
    p = *(void **)((char *)arg0 + 0x2c);
    if (p != 0) {
        volatile void *q = p;
        if (q != 0) {
            void **vt = *(void ***)p;
            ((void (*)(void *, int))vt[2])(p, 1);
        }
    }
    p = *(void **)((char *)arg0 + 0x30);
    if (p != 0) {
        volatile void *q = p;
        if (q != 0) {
            void **vt = *(void ***)p;
            ((void (*)(void *, int))vt[2])(p, 1);
        }
    }
    fn_80128668(arg0);
}

#pragma use_lmw_stmw off
void fn_80237E7C(char *arg0, int unused) {
    char **items = *(char ***)((char *)lbl_8055F0C0 + 0x30);
    int i = 0;
    int offset = 0;
    while (i < *(int *)((char *)items + 8)) {
        if (stricmp(*(char **)((char *)items + 4) + offset, arg0) == 0)
            *(*(char **)((char *)items + 4) + offset + 0x2d) = 0;
        offset += 0x34;
        i++;
    }
}
#pragma use_lmw_stmw reset
void *fn_80237FF8(void *arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 4);
        *(void **)arg0 = lbl_80340970;
        if (value != 0) fn_8002F6AC((void *)value, fn_80237A08);
        *(float *)((char *)arg0 + 0xC) = lbl_805636E0;
        if (arg1 > 0) fn_80128668(arg0);
        *(int *)((char *)arg0 + 4) = 0;
        *(int *)((char *)arg0 + 8) = 0;
    }
    return arg0;
}

float fn_80238084(void *arg0) { return *(float *)((char *)arg0 + 0xC); }

extern float lbl_805636E8;
extern void *fn_8022EDE4(float *, float);
extern void *fn_8022EE9C(void);
extern void fn_8022EE98(void *);
extern void fn_80214C54(void *, void *);
#pragma push
#pragma processor 750
void fn_8023808C(void *arg0, float value) {
    struct Pos {float x,y;};
    struct Key { float time, scale, z; struct Pos pos; };
    struct Track {void *object; struct Key *keys; int count;};
    struct Anim {void *vtable; struct Track *tracks; int count; float duration;};
    struct Anim *anim = arg0;
    float a[12], b[12], c[12];
    float time;
    float zero=lbl_805636E0, one=lbl_805636E4, epsilon=lbl_805636E8;
    int i;
    value = lbl_805636E4 < value ? lbl_805636E4 : value;
    value = value > lbl_805636E0 ? value : lbl_805636E0;
    time = anim->duration * value;
    for(i=0;i<anim->count;i++) {
        struct Track *track=&anim->tracks[i];
        void *result;
        if(track->count>0) {
            int j, index=-1;
            for(j=0;j<track->count;j++) if(time >= track->keys[j].time) index=j;
            if(index==-1) {
                struct Key *key=track->keys;
                struct Pos pos;
                float scale=key->scale, z=key->z;
                pos=key->pos;
                a[9]=pos.x; a[10]=pos.y; a[11]=zero; a[0]=one; a[1]=zero; a[2]=zero; a[3]=zero; a[4]=one; a[5]=zero; a[6]=zero; a[7]=zero; a[8]=one;
                result=fn_8022EDE4(a,scale); ((float*)result)[14]=z;
            } else if(index==track->count-1) {
                struct Key *key=&track->keys[track->count-1];
                struct Pos pos;
                float scale=key->scale, z=key->z;
                pos=key->pos;
                b[9]=pos.x; b[10]=pos.y; b[11]=zero; b[0]=one; b[1]=zero; b[2]=zero; b[3]=zero; b[4]=one; b[5]=zero; b[6]=zero; b[7]=zero; b[8]=one;
                result=fn_8022EDE4(b,scale); ((float*)result)[14]=z;
            } else {
                struct Key *first=&track->keys[index], *next=&track->keys[index+1];
                float delta=next->time-first->time;
                float t,scale,z;
                struct Pos pos;
                delta=delta>epsilon?delta:epsilon;
                t=(time-first->time)/delta;
                pos.y=first->pos.y+t*(next->pos.y-first->pos.y);
                scale=first->scale+t*(next->scale-first->scale);
                pos.x=first->pos.x+t*(next->pos.x-first->pos.x);
                z=first->z+t*(next->z-first->z);
                c[9]=pos.x; c[10]=pos.y; c[11]=zero; c[0]=one; c[1]=zero; c[2]=zero; c[3]=zero; c[4]=one; c[5]=zero; c[6]=zero; c[7]=zero; c[8]=one;
                result=fn_8022EDE4(c,scale); ((float*)result)[14]=z;
            }
        } else result=fn_8022EE9C();
        fn_80214C54(track->object,result);
        fn_8022EE98(result);
    }
}
#pragma pop

void *fn_80238370(void *arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 4);
        *(void **)arg0 = lbl_8034095C;
        if (value != 0) fn_8002F6AC((void *)value, (void (*)(void))fn_80237968);
        *(int *)((char *)arg0 + 4) = 0;
        *(int *)((char *)arg0 + 8) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

float fn_802383F4(void) { return lbl_805636E0; }

#pragma push
#pragma processor 750
void fn_802383FC(TrailMgr *mgr) {
    extern float fn_8023659C(void);
    extern void *fn_8022EDE4(float *, float);
    extern void *fn_8022EE9C(void);
    extern void fn_8022EE98(void *);
    extern void fn_80214C54(void *, void *);
    extern float lbl_805636E0, lbl_805636E4, lbl_805636E8;
    float f29 = fn_8023659C();
    float f30 = lbl_805636E0;
    float f31 = lbl_805636E4;
    float f27 = lbl_805636E8;
    int i;
    int off;
    for (i = 0, off = 0; i < mgr->count; i++, off += 0x34) {
        TrailEntry *e = (TrailEntry *)((char *)mgr->entries + off);
        if (e->active == 0) continue;
        {
            float t = f29 - e->field30;
            void *obj;
            if (e->keyCount > 0) {
                int idx = -1;
                int j;
                for (j = 0; j < e->keyCount; j++) {
                    if (t >= e->keys[j].time) idx = j;
                }
                if (idx == -1) {
                    TrailKey *k = e->keys;
                    float mtx[12];
                    mtx[9] = k->fc;
                    mtx[10] = k->f10;
                    mtx[11] = f30;
                    mtx[0] = f31; mtx[1] = f30; mtx[2] = f30; mtx[3] = f30;
                    mtx[4] = f31; mtx[5] = f30; mtx[6] = f30; mtx[7] = f30;
                    mtx[8] = f31;
                    obj = fn_8022EDE4(mtx, k->f4);
                    *(float *)((char *)obj + 0x38) = k->f8;
                } else if (idx == e->keyCount - 1) {
                    TrailKey *k = &e->keys[e->keyCount - 1];
                    float mtx[12];
                    mtx[9] = k->fc;
                    mtx[10] = k->f10;
                    mtx[11] = f30;
                    mtx[0] = f31; mtx[1] = f30; mtx[2] = f30; mtx[3] = f30;
                    mtx[4] = f31; mtx[5] = f30; mtx[6] = f30; mtx[7] = f30;
                    mtx[8] = f31;
                    obj = fn_8022EDE4(mtx, k->f4);
                    *(float *)((char *)obj + 0x38) = k->f8;
                } else {
                    TrailKey *c = &e->keys[idx];
                    TrailKey *n = &e->keys[idx + 1];
                    float denom = n->time - c->time;
                    float tt;
                    float mtx[12];
                    if (denom <= f27) denom = f27;
                    tt = (t - c->time) / denom;
                    mtx[11] = f30;
                    mtx[0] = f31; mtx[1] = f30; mtx[2] = f30; mtx[3] = f30;
                    mtx[4] = f31; mtx[5] = f30; mtx[6] = f30; mtx[7] = f30;
                    mtx[8] = f31;
                    mtx[9] = c->fc + tt * (n->fc - c->fc);
                    mtx[10] = c->f10 + tt * (n->f10 - c->f10);
                    obj = fn_8022EDE4(mtx, c->f4 + tt * (n->f4 - c->f4));
                    *(float *)((char *)obj + 0x38) = c->f8 + tt * (n->f8 - c->f8);
                }
            } else {
                obj = fn_8022EE9C();
            }
            fn_80214C54((void *)e->field20, obj);
            fn_8022EE98(obj);
            if (e->flag2C != 0) {
                float lim;
                if (e->keyCount > 0) {
                    lim = e->keys[e->keyCount - 1].time;
                } else {
                    lim = f30;
                }
                if (t > lim) e->active = 0;
            }
        }
    }
}
#pragma pop
extern void fn_80237AA0();
extern void fn_80236960();
extern float lbl_805636E0;
extern void fn_8002F6AC(void *, void (*)(void));
extern void fn_80128668(void *);
extern void *fn_80237968(void *, int);
extern void fn_80237A08(void);
extern char lbl_8034095C[];
extern char lbl_80340970[];
