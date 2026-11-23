// trackmusic — track music ("TrackMusic: Found song", TrkMusDash).
// Recovered TU window 0x8020F3B4..0x802114F4+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802114F4 (+ .ctors slot 0x802ED3A8) remains in
// auto/text_802114F4_.c pending a promotion pass.
extern char *fn_802EC104(long);  // path of entry i of the dash's scanned music table
#pragma cplusplus on
struct Dummy_802113D8 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual long f6(long *, char *);
};
struct Dummy10688 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void *, void *);
};
#pragma cplusplus off
extern long lbl_8055EEE0;
extern long lbl_8055EEE4;
extern long lbl_8055EEBC;
extern long lbl_8055EEE8;
extern long lbl_8055B658;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
  
extern void *fn_8020FAF0();
extern long fn_8000DA10(void);
extern long fn_8020F9F4(void);
extern int stricmp(const char *, const char *);
// Track-music file list: m_entries is an array of m_count char* song paths
// (fn_8020F950 fills it from the dash's scanned music table), m_capacity is how
// many of them fit in the buffer.
extern struct TrackMusicList { char **m_entries; long m_count; long m_capacity; } lbl_804900AC;
extern void fn_801345D8(void *, ...);
extern long lbl_8055B664;
extern signed char lbl_8055EEF4;
extern signed char lbl_8055EEF5;
extern signed char lbl_8055EEF6;
extern char lbl_804904D0[];
extern char lbl_8033C95C[];
extern long *lbl_8055B650;
extern long *lbl_8055B654;
extern int fn_8012E938(int);
extern void fn_8012E81C(void);
extern long fn_802EC294(long, long);
extern char lbl_80489CA0[16];
extern long fn_8020F608(long, long);
// Shuffled track play order: m_entries holds m_count indices into the
// track-music list; lbl_8055EEC4 is the next cursor into this order.
extern struct Unk_804902C4 {
    long *m_entries;
    long m_count;
    long m_pad;
} lbl_804902C4;
extern long lbl_8055EEC4;
extern long lbl_8055EED0;
extern long lbl_8055EED4;
extern long lbl_8055B658;
extern long __AXFXGetLfoSinTable_801769CC();
extern long lbl_8055B674;
extern char lbl_8033C970[];
extern char lbl_8033C980[];
extern void *fn_8001285C(long);
extern void fn_802E30C8(const char *, ...);
extern void fn_802EC1D8(void);
extern float lbl_80563400;
extern void fn_802EC1C0();
extern void fn_802EC1E4();
extern long fn_802EC12C();
extern long fn_802EC0FC(void);
// Returns the "no song" sentinel (-1). Callers sometimes pass a mode argument (0/1/2), but this stub ignores it and always reports no song.
long fn_8020F3B4(void) { return -1; }
 
#pragma scheduling invalid_target
int fn_8020F3BC(int path, int buffer, int size) {
    /* Formats a track-music path into the buffer and returns the buffer. */
    fn_801345D8((void *)buffer, size, (void *)&lbl_8055B664, path);
    return buffer;
}
extern long lbl_8055B66C;
int fn_8020F400(int source, int destination, int size) {
    /* Format a track-music song path ("%s.sng") into the destination buffer and return it. */
    fn_801345D8((void *)destination, size, (void *)&lbl_8055B66C, source);
    return destination;
}

#pragma dont_inline on
void fn_8020F444(void) {
#define gSongLoaded0 lbl_8055EEF4
#define gSongLoaded1 lbl_8055EEF5
#define gSongLoaded2 lbl_8055EEF6
#define gSongName0   lbl_804904D0
#define gSongName1   lbl_8055B650
#define gSongName2   lbl_8055B654
#define gTriedToLoad lbl_8033C95C
    /* Load and register the three track-music song paths once each, then log the path used. */
    char pathBuffer[0x40];
    if ((unsigned char)gSongLoaded0 == 0) {
        if (fn_8012E938(fn_8020F400((long)gSongName0, (long)pathBuffer, 0x40)) != 0) {
            fn_8020F400((long)gSongName0, (long)pathBuffer, 0x40);
            fn_8012E81C();
            fn_802EC294(0, fn_8020F3BC((int)gSongName0, (int)pathBuffer, 0x40));
            fn_802E30C8(gTriedToLoad, pathBuffer);
            gSongLoaded0 = 1;
        }
    }
    if ((unsigned char)gSongLoaded1 == 0) {
        if (fn_8012E938(fn_8020F400((long)gSongName1, (long)pathBuffer, 0x40)) != 0) {
            fn_8020F400((long)gSongName1, (long)pathBuffer, 0x40);
            fn_8012E81C();
            fn_802EC294(1, fn_8020F3BC((int)gSongName1, (int)pathBuffer, 0x40));
            fn_802E30C8(gTriedToLoad, pathBuffer);
            gSongLoaded1 = 1;
        }
    }
    if ((unsigned char)gSongLoaded2 == 0) {
        if (fn_8012E938(fn_8020F400((long)gSongName2, (long)pathBuffer, 0x40)) != 0) {
            fn_8020F400((long)gSongName2, (long)pathBuffer, 0x40);
            fn_8012E81C();
            fn_802EC294(2, fn_8020F3BC((int)gSongName2, (int)pathBuffer, 0x40));
            fn_802E30C8(gTriedToLoad, pathBuffer);
            gSongLoaded2 = 1;
        }
    }
#undef gTriedToLoad
#undef gSongName2
#undef gSongName1
#undef gSongName0
#undef gSongLoaded2
#undef gSongLoaded1
#undef gSongLoaded0
}
#pragma dont_inline reset

#pragma scheduling on
 
#pragma dont_inline on
void fn_8020F5C8(void) {
    /* Mark all three track-music load slots as loaded (the inverse of fn_8020F5DC). */
    lbl_8055EEF6 = 1;
    lbl_8055EEF5 = 1;
    lbl_8055EEF4 = 1;
}
#pragma dont_inline reset
 
/* Mark all three track-music load slots as unloaded (the inverse of fn_8020F5C8). */
void fn_8020F5DC(void) {
    lbl_8055EEF6 = 0;
    lbl_8055EEF5 = 0;
    lbl_8055EEF4 = 0;
}
 
#pragma dont_inline on
#pragma scheduling invalid_target
void *fn_8020F5F0(long trackIndex) {
    /* Return the 0x1900-byte track-music buffer for trackIndex within the trackMusicBuffer table (lbl_80489CA0). */
    long byteOffset = (trackIndex << 6) * 100;
    return (void *)((char *)&lbl_80489CA0 + byteOffset);
}
#pragma scheduling on
#pragma dont_inline reset
extern void *memset(void *, int, unsigned long);
#pragma dont_inline on
#pragma ctrloop on
/* Clear the track-music buffer for a context and stamp the first word of each
 * of its 64 slots (0x64 bytes apart) with the slot state (0 idle, 1 active). */
long fn_8020F608(long slotState, long contextIndex) {
    long *slot;
    long slotIndex;
    slot = (long *)fn_8020F5F0(contextIndex);
    memset(slot, 0, 0x1900);
    for (slotIndex = 0; slotIndex < 64; slotIndex++) {
        *slot = slotState;
        slot += 25;
    }
}
#pragma ctrloop reset
#pragma dont_inline reset

void fn_8020F6E0(long contextIndex, long event) {
    /* Broadcast callback: when the clear-context event (0) is signalled, zero and
       reinitialise the track-music data block for this context index. */
    if (event != 0) {
        return;
    }
    fn_8020F608(0, contextIndex);
}
 
/* Track-music wrapper for the dash getter fn_802EC0FC: the number of songs the
 * dash found on the disc.  The tail branch leaves that count in r3, which is
 * what the callers test; fn_802104D0 is the same check reduced to a 0/1 flag. */
long fn_8020F6F8(void) {
    return fn_802EC0FC();
}
 
#pragma dont_inline on
long fn_8020F6FC(void) {
    /* Returns the next track index from the shuffled play order and advances the cursor cyclically. */
    long cursor = lbl_8055EEC4;
    long *order = lbl_804902C4.m_entries;
    long count = lbl_804902C4.m_count;
    long track = order[cursor];
    lbl_8055EEC4 = (cursor + 1) % count;
    return track;
}
#pragma dont_inline reset

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8020F730(void) {
    long count = lbl_804900AC.m_count;
    long i;
    lbl_804902C4.m_count = 0;
    if (count != 0) {
        for (i = 0; i < count; i++) {
            long index = lbl_804902C4.m_count;
            lbl_804902C4.m_count = index + 1;
            lbl_804902C4.m_entries[index] = i;
        }
        for (i = 0; i < lbl_804902C4.m_count; i++) {
            long index = fn_80129D18(6);
            long *e = lbl_804902C4.m_entries;
            long temp = e[i];
            e[i] = e[index];
            e[index] = temp;
        }
    }
    lbl_8055EEC4 = 0;
}
#pragma scheduling on
#pragma use_lmw_stmw on
void fn_8020F950(void) {
    /* Rebuild the track-music list from the dash's scanned music table - one
       path per scanned song, as many as the list's buffer holds - and rebuild
       the shuffled play order from the new count. */
    long capacity;
    long limit;
    long i;
    long index;
    char *path;
    char **entries;
    capacity = lbl_804900AC.m_capacity;
    lbl_804900AC.m_count = 0;
    limit = ((long (*)(struct TrackMusicList *))fn_802EC0FC)(&lbl_804900AC);
    if (capacity < limit) {
        limit = capacity;
    }
    i = 0;
    while (i < limit) {
        path = fn_802EC104(i);
        index = lbl_804900AC.m_count;
        i++;
        entries = lbl_804900AC.m_entries;
        lbl_804900AC.m_count = index + 1;
        entries[index] = path;
    }
    fn_8020F730();
}

#pragma scheduling invalid_target
long fn_8020F9F4(void) {
    char *groupBase;
    long slotIndex;
    long group;
    long nextIndex0;
    long nextIndex1;
    long nextIndex2;
    long nextIndex3;
    long nextIndex4;
    long nextIndex5;
    long nextIndex6;

    /* Return the index of the first free track-music slot in the current context's 8x8 table, or 0 if none are free. */
    groupBase = (char *)fn_8020F5F0(fn_8000DA10());
    slotIndex = 0;
    for (group = 0; group < 8; group++) {
        if ((signed char)groupBase[4] == 0) {
            return slotIndex;
        }
        nextIndex0 = slotIndex + 1;
        if ((signed char)groupBase[0x68] == 0) {
            return nextIndex0;
        }
        nextIndex1 = nextIndex0 + 1;
        if ((signed char)groupBase[0xCC] == 0) {
            return nextIndex1;
        }
        nextIndex2 = nextIndex1 + 1;
        if ((signed char)groupBase[0x130] == 0) {
            return nextIndex2;
        }
        nextIndex3 = nextIndex2 + 1;
        if ((signed char)groupBase[0x194] == 0) {
            return nextIndex3;
        }
        nextIndex4 = nextIndex3 + 1;
        if ((signed char)groupBase[0x1F8] == 0) {
            return nextIndex4;
        }
        nextIndex5 = nextIndex4 + 1;
        if ((signed char)groupBase[0x25C] == 0) {
            return nextIndex5;
        }
        nextIndex6 = nextIndex5 + 1;
        if ((signed char)groupBase[0x2C0] == 0) {
            return nextIndex6;
        }
        groupBase += 0x320;
        slotIndex = nextIndex6 + 1;
    }
    return 0;
}

#pragma push
#pragma dont_inline on
/* Find the track-music slot in the current context whose key matches `key`, or the first free slot if none match. */
void *fn_8020FAF0(key)
char *key;
{
    char *slot;
    char *slots = (char *)fn_8020F5F0(fn_8000DA10());
    long i = 0;
    slot = slots;
    for (;;) {
        if (stricmp(slot + 4, key) == 0) {
            return slots + i * 0x64;
        }
        i++;
        slot += 0x64;
        if (i >= 0x40) break;
    }
    return slots + fn_8020F9F4() * 0x64;
}
#pragma dont_inline reset
#pragma pop

#pragma scheduling on

#pragma use_lmw_stmw off
#pragma dont_inline on
/* Find the index of a track-music entry matching the given name, or -1 if not found. */
int fn_8020FB80(void *name) {
    int entryOffset;
    int index;
    index = 0;
    entryOffset = 0;
    while (index < lbl_804900AC.m_count) {
        if (fn_8002B1D8(*(char **)((char *)lbl_804900AC.m_entries + entryOffset), (char *)name, 0x3F) == 0) {
            return index;
        }
        entryOffset += 4;
        index++;
    }
    return ((int (*)(int))fn_8020F3B4)(0);
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma dont_inline on
/* Returns the current track-music entry's payload: NULL if none, the selected path from the track-music list for type 1, or the inline path at +0x24 for other types. */
void *fn_8020FC04(void) {
#define GetCurrentTrackMusicEntry fn_8020FAF0
#define GetNextTrackMusicIndex fn_8020F6FC
#define trackMusicList lbl_804900AC
    char *trackEntry = (char *)GetCurrentTrackMusicEntry();
    long entryType;
    if (trackEntry == 0) {
        goto null_result;
    }
    entryType = *(long *)trackEntry;
    if (entryType == 0) {
        return (void *)0;
    }
    if (entryType == 1) {
        return (void *)trackMusicList.m_entries[GetNextTrackMusicIndex()];
    }
    return trackEntry + 0x24;
null_result:
    return 0;
#undef GetCurrentTrackMusicEntry
#undef GetNextTrackMusicIndex
#undef trackMusicList
}
#pragma dont_inline reset

extern int fn_8020FB80(void *);
#pragma scheduling invalid_target
int fn_8020FC6C(void) {
    void *p;
    if (lbl_804900AC.m_count == 0) {
        return ((int (*)(int))fn_8020F3B4)(0);
    } else if ((p = fn_8020FC04()) != 0) {
        return fn_8020FB80(p);
    } else {
        return ((int (*)(int))fn_8020F3B4)(0);
    }
}

#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
/* Pick the track-music song for the current event: read the event name from the
 * scene's resource, resolve the matching song index, log the choice and switch
 * to it (stopping the old song first when it changes). */
extern "C" void fn_8020FCC4(void) {
    #define TRACK_SONGS     lbl_804900AC
    #define CURRENT_SONG    lbl_8055B658
    #define EVENT_NAME_OUT  lbl_8055B674
    #define NO_EVENT        lbl_8033C970   /* "invalid_contest" */
    #define FOUND_MSG       lbl_8033C980   /* "TrackMusic: Found song %d (%s) for event %s" */
    #define SCENE_IDX_PTR   __AXFXGetLfoSinTable_801769CC

    int eventName;
    int songIndex;
    int currentSong;
    void *scene;
    struct Dummy_802113D8 *resource;
    scene = fn_8001285C(*(long *)SCENE_IDX_PTR());
    resource = *(struct Dummy_802113D8 **)((char *)scene + 0x20);
    eventName = resource->f6(&EVENT_NAME_OUT, NO_EVENT);
    songIndex = ((int (*)(void))fn_8020FC6C)();
    if (songIndex >= 0 && songIndex < TRACK_SONGS.m_count) {
        fn_802E30C8(FOUND_MSG, songIndex, TRACK_SONGS.m_entries[songIndex], eventName);
    }
    if (songIndex == ((int (*)(int))fn_8020F3B4)(0)) {
        if (CURRENT_SONG == ((int (*)(int))fn_8020F3B4)(1)) {
            songIndex = ((int (*)(int))fn_8020F3B4)(1);
        }
    }
    if (songIndex == ((int (*)(int))fn_8020F3B4)(0)) {
        if (CURRENT_SONG == ((int (*)(int))fn_8020F3B4)(2)) {
            songIndex = ((int (*)(int))fn_8020F3B4)(2);
        }
    }
    currentSong = CURRENT_SONG;
    if (currentSong != -1 && currentSong != songIndex) {
        fn_802EC1D8();
    }
    CURRENT_SONG = songIndex;

    #undef TRACK_SONGS
    #undef CURRENT_SONG
    #undef EVENT_NAME_OUT
    #undef NO_EVENT
    #undef FOUND_MSG
    #undef SCENE_IDX_PTR
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop

extern char *strncpy(char *, const char *, unsigned long);
static inline long clampTrackDigit(long value, long limit) {
    value &= ((-value & ~value) >> 31);
    if (value < limit) limit = value;
    return limit;
}
#pragma dont_inline on
void fn_8020FDE4(long trackId, const char *name, register char *slotKey) {
    /* Initialize a track-music slot: store the track id, copy the display name, and copy the slot key (truncated to 0x20). */
    char *entry;
    long remaining;
    char *keyDst;
    unsigned char ch;

    entry = (char *)((void *(*)(char *))fn_8020FAF0)(slotKey);
    memset(entry, 0, 4);
    *(long *)entry = trackId;
    strncpy(entry + 0x24, name, 0x3F);
    keyDst = entry + 4;
    remaining = 0x20;
    while ((signed char)(ch = (unsigned char)*slotKey++, *keyDst++ = ch) != 0) {
        if (--remaining <= 0) {
            keyDst[-1] = 0;
            break;
        }
    }
}
/* Resolve the selected track-music entry into the current track id (lbl_8055B658). */
void fn_8020FE90(void) {
    long resolvedTrack;

    fn_802EC12C();
    fn_802EC1D8();
    if (lbl_8055EEE0 == -2) {
        lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(0);
        return;
    }
    if (lbl_8055EEE0 == -1) {
        resolvedTrack = fn_8020F6FC();
    } else {
        resolvedTrack = lbl_8055EEE0 + (lbl_8055EEE4 * 0xA);
    }
    lbl_8055B658 = resolvedTrack;
}

#pragma push
#pragma dont_inline off
long fn_8020FEF0(long arg0) {
    long sum;
    long state = lbl_8055EEE0;
    long count;
    long pos;
    long max;

    if (state == -2 && lbl_8055EEBC > 0) {
        if (arg0 == 1) {
            lbl_8055EEE0 = -1;
            fn_8020FE90();
        }
        return;
    } else if (state == -1) {
        if (arg0 == -1) {
            lbl_8055EEE0 = -2;
            fn_8020FE90();
        }
        return;
    } else {
        pos = lbl_8055EEE4;
        sum = pos + arg0;
        max = clampTrackDigit(sum, lbl_8055EEE8 - 1);
        lbl_8055EEE4 = max;
        count = lbl_8055EEBC;
        if (pos == max) {
            return;
        }
        if (count == 0) {
            lbl_8055EEE0 = -2;
        } else if (state >= 0 && state + max * 10 >= count) {
            lbl_8055EEE0 = (count - 1) % 10;
        }
        if (lbl_8055EEE0 >= 0) {
            fn_8020FE90();
        }
    }
}
#pragma pop

#pragma scheduling on
extern long lbl_8055EEBC;
extern long lbl_8055EEE0;
extern long lbl_8055EEE4;
extern long lbl_8055EEE8;
extern void fn_8020FE90(void);
/* Adjusts the track-music digit selection state by delta, clamping to valid range and refreshing on change. */
void fn_8020FFE4(long arg0) {
    long old = lbl_8055EEE0;
    long value = lbl_8055EEBC;
    long digit;
    if (value == 0) lbl_8055EEE0 = -2;
    else {
        digit = 9;
        if ((lbl_8055EEE4 + 1) * 10 >= value) digit = (value - 1) % 10;
        if (old == -2) { if (arg0 == 1) lbl_8055EEE0 = 0; }
        else if (old == -1) { if (arg0 == 1) lbl_8055EEE0 = 0; }
        else {
            lbl_8055EEE0 = (*(volatile long *)&lbl_8055EEE0) + arg0;
            if (lbl_8055EEE0 < 0) lbl_8055EEE0 = -2;
            if (lbl_8055EEE0 > digit) lbl_8055EEE0 = digit;
        }
    }
    if (old != lbl_8055EEE0) fn_8020FE90();
}

extern long lbl_8055B67C;
extern signed char lbl_8055EEEC, lbl_8055EEED;
/* Apply the pending track-music request: clear it, set up the requested song slot (-2/-1 are special IDs, otherwise index the song-path list), optionally reset the context's music buffer, and record the chosen song index. */ long fn_802100AC(void) {
    long request;
    long songIndex;
    void *audioContainer;
    struct Dummy_802113D8 *resourceObj;

    /* Selects/prepares track music entry based on lbl_8055EEE0 state and updates related globals. */
    fn_802EC12C();
    request = lbl_8055EEE0;
    if (request == -2) {
        audioContainer = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
        resourceObj = *(struct Dummy_802113D8 **)((char *)audioContainer + 0x20);
        fn_8020FDE4(0, (const char *)&lbl_8055B67C,
                    (char *)resourceObj->f6(&lbl_8055B674, lbl_8033C970));
        if ((unsigned char)lbl_8055EEEC != 0) {
            fn_8020F608(0, fn_8000DA10());
        }
    } else if (request == -1) {
        audioContainer = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
        resourceObj = *(struct Dummy_802113D8 **)((char *)audioContainer + 0x20);
        fn_8020FDE4(1, (const char *)&lbl_8055B67C,
                    (char *)resourceObj->f6(&lbl_8055B674, lbl_8033C970));
        if ((unsigned char)lbl_8055EEED != 0) {
            fn_8020F608(1, fn_8000DA10());
        }
    } else {
        songIndex = request + lbl_8055EEE4 * 10;
        audioContainer = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
        resourceObj = *(struct Dummy_802113D8 **)((char *)audioContainer + 0x20);
        fn_8020FDE4(2, (const char *)lbl_804900AC.m_entries[songIndex],
                    (char *)resourceObj->f6(&lbl_8055B674, lbl_8033C970));
        lbl_8055B658 = songIndex;
    }
}

extern float fn_80235EF0(long, long);
extern void fn_80147940(void *, void *, long, long);
#pragma cplusplus on
struct Dummy_802101F8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual long v4();
};
#pragma cplusplus reset
struct Record_802101F8 {
    long f0;
    long f4;
    long f8;
    long fC;
    float f10;
    float f14;
    long f18;
};
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_802101F8(Dummy_802101F8 *widget, long resource, long baseIndex, struct Record_802101F8 *record) {
    /* Lay out three stepped track-music UI entries, fetching each step's float value from the widget's resource set and advancing the record's float position. */
    long resourceSet;
    struct Record_802101F8 rec;
    long stepIndex;
    long f8;
    long f4;

    if (widget == 0 || record == 0) return;
    resourceSet = widget->v4();
    stepIndex = 0;
    rec.f0 = record->f0;
    f4 = ((volatile struct Record_802101F8 *)record)->f4;
    f8 = ((volatile struct Record_802101F8 *)record)->f8;
    rec.f4 = f4;
    rec.f8 = f8;
    rec.fC = record->fC;
    rec.f10 = record->f10;
    rec.f14 = record->f14;
    rec.f18 = record->f18;
    do {
        long step = baseIndex + stepIndex;
        if (stepIndex == 1) {
            float finalValue = fn_80235EF0(resourceSet, baseIndex + 2);
            rec.f10 = (record->f10 - fn_80235EF0(resourceSet, baseIndex)) - finalValue;
        } else {
            rec.f10 = fn_80235EF0(resourceSet, step);
        }
        fn_80147940(widget, &rec, resource, step);
        stepIndex++;
        *(float *)&rec.f4 += rec.f10;
    } while (stepIndex < 3);
}
#pragma cplusplus reset
 
/* Initializes the track-music buffer and registers it with the 'Tmus' resource handler. */
void fn_8021031C(void) {
    long resourceTag;
    char *trackMusicBuffer;
    resourceTag = 0x546D7573;
    trackMusicBuffer = lbl_80489CA0;
    memset(&lbl_80489CA0, 0, 0x6400);
    fn_802E6BD8(resourceTag, 0, trackMusicBuffer, 0x6400, 0);
    fn_8000DBC8(&fn_8020F6E0);
}
 
extern long fn_80207848(void *, long);
extern long fn_802EC12C(void);
extern void fn_8020FCC4(void);
extern char lbl_8033C9AC[];
extern long lbl_8055EED0;
#pragma scheduling invalid_target
void fn_8021037C(void) {
    /* Initialize track music: create the goalline SFX sound, reset the music state flags, and pick the song for the current event. */
#define GOALLINE_SFX_NAME lbl_8033C9AC
#define sGoallineSfx lbl_8055EED0
    sGoallineSfx = fn_80207848(GOALLINE_SFX_NAME, 1);
    fn_802EC1D8();
    fn_802EC12C();
    fn_8020FCC4();
#undef sGoallineSfx
#undef GOALLINE_SFX_NAME
}
#pragma scheduling on
/* Tail-call thunk: mark all three track-music load slots as loaded (branches to
 * fn_8020F5C8). Called at the end of pre-race setup (fn_8000AB48); the pointer it
 * is passed is ignored by the callee. */
void fn_802103B8(void) {
#define TrackMusic_MarkAllLoaded fn_8020F5C8
    TrackMusic_MarkAllLoaded();
#undef TrackMusic_MarkAllLoaded
}

#pragma push
#pragma cplusplus on
#pragma dont_inline on
extern "C" /* Shut down track music: fade out/stop playback, destroy the track-music resource and goalline SFX objects if present, clear current song state, and mark load slots unloaded. */
void fn_802103BC(void) {
    class Obj { public: virtual void f(long); };
    ((void (*)(float))fn_802EC1C0)(0.0f);
    fn_802EC12C();
    fn_802EC1E4();
    if (lbl_8055EED4 != 0) {
        ((Obj *)lbl_8055EED4)->f(1);
    }
    lbl_8055EED4 = 0;
    lbl_8055B658 = -1;
    fn_8020F5DC();
    if (lbl_8055EED0 != 0) {
        ((Obj *)lbl_8055EED0)->f(1);
    }
    lbl_8055EED0 = 0;
}
#pragma dont_inline reset
#pragma cplusplus off
#pragma pop
extern long fn_80009C84(void);
extern unsigned char lbl_8055EEC0;
extern signed char lbl_8055EEC8, lbl_8055B660;
extern long lbl_8055EECC, lbl_8055B658;
/* Stop track music: mute, clear selection/hold state, and if a song is selected while inactive reset to none and stop playback. */
void fn_80210444(void) {
#define trackMusicMuted lbl_8055B660
#define trackMusicSongListReady lbl_8055EEC0
#define trackMusicHoldSongChange lbl_8055EEC8
#define trackMusicHoldUntil lbl_8055EECC
#define trackMusicCurrentSong lbl_8055B658
    trackMusicMuted = 1;
    trackMusicSongListReady = 0;
    trackMusicHoldSongChange = 0;
    trackMusicHoldUntil = 0;
    if (fn_80009C84() == 0 && fn_801B85CC() == 0 &&
        trackMusicCurrentSong == ((long (*)(long))fn_8020F3B4)(1)) {
        trackMusicCurrentSong = ((long (*)(long))fn_8020F3B4)(0);
        fn_802EC12C();
        fn_802EC1D8();
    }
#undef trackMusicMuted
#undef trackMusicSongListReady
#undef trackMusicHoldSongChange
#undef trackMusicHoldUntil
#undef trackMusicCurrentSong
}

/* True (1) when a track-music song is selected (current song id lbl_8055B658 != -1). */
long fn_802104B8(void) {
    return (unsigned long)((-1 - lbl_8055B658) | (lbl_8055B658 + 1)) >> 31;
}

/* True when the dash found at least one track-music song (song count > 0). */
long fn_802104D0(void) {
    return fn_802EC0FC() > 0;
}

long fn_802104FC(void) {
    /* Return nonzero when no track-music entry is selected (the current track index is -1). */
    return (lbl_8055B658 + 1) == 0;
}

 
/* Tail-call thunk: set the master sound volume (branches to fn_802EC1C0), which
 * stores it and re-applies it if sound is already enabled. Used by pre-race music
 * (fn_8020C140) to set/fade the volume. */
void fn_80210510(float volume) {
    ((void (*)(float))fn_802EC1C0)(volume);
}

/* Select the track-music mode (0/1) using the current DA parameter, or do nothing for 2. */
void fn_80210514(int mode) {
    switch (mode) {
    case 0:
        fn_8020F608(0, fn_8000DA10());
        break;
    case 1:
        fn_8020F608(1, fn_8000DA10());
        break;
    case 2:
        break;
    }
}

#pragma push
#pragma opt_strength_reduction off
long fn_80210570(void) {
    long val = 3;
    char *ptr = (char *)fn_8020F5F0(fn_8000DA10());
    long i;
    long ctr;
    long k;
    for (i = 0, ctr = 0; ctr < 16; ctr++, i += 3) {
        for (k = 0; k < 1; k++) {
            if (val == 3) {
                val = *(long *)(ptr + 0x000);
            } else if (*(long *)(ptr + 0x000) != val) {
                return 2;
            }
            if (val == 3) {
                val = *(long *)(ptr + 0x064);
            } else if (*(long *)(ptr + 0x064) != val) {
                return 2;
            }
            if (val == 3) {
                val = *(long *)(ptr + 0x0C8);
            } else if (*(long *)(ptr + 0x0C8) != val) {
                return 2;
            }
            if (val == 3) {
                val = *(long *)(ptr + 0x12C);
            } else if (*(long *)(ptr + 0x12C) != val) {
                return 2;
            }
        }
        ptr += 0x190;
    }
    switch (val) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        return 0;
    }
}
#pragma pop
/* Per-frame track-music update: load any unloaded song bank, rebuild the song
 * list when the dash's song count changes, and while a song is selected hand
 * it to the music system when nothing is on hold and the race is outside the
 * change-hold window.  A random slot advances to the next shuffled song and a
 * change of the mute flag starts or stops the music. */
void trackMusicUpdate(unsigned char mute) {
    long songCount;
    long now;
    long overlayUp;
    long sceneActive;
    long holdSongChange;
    struct Dummy_802113D8 *resource;
    if ((unsigned char)lbl_8055EEF4 == 0 || (unsigned char)lbl_8055EEF5 == 0 || (unsigned char)lbl_8055EEF6 == 0) {
        fn_8020F444();
    }
    songCount = fn_802EC0FC();
    if (songCount != lbl_8055EEBC) {
        fn_802EC12C();
        fn_8020F950();
        fn_8020FCC4();
        lbl_8055EEC0 = 1;
    } else {
        lbl_8055EEC0 = 0;
    }
    lbl_8055EEBC = songCount;
    overlayUp = 0;
    if (fn_800216D0() != 0 && fn_80009C84() == 0) {
        overlayUp = 1;
    }
    sceneActive = 1;
    if (fn_801B85CC() == 0 && fn_80009C84() == 0) {
        sceneActive = 0;
    }
    if (lbl_8055B658 != -1) {
        if (lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(0) && overlayUp != 0) {
            lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(2);
            fn_802EC12C();
            fn_802EC1D8();
        } else if (lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(2) && overlayUp == 0) {
            lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(0);
            fn_802EC12C();
            fn_802EC1D8();
        } else if (lbl_8055B658 == ((long (*)(long))fn_8020F3B4)(0) && sceneActive != 0) {
            lbl_8055B658 = ((long (*)(long))fn_8020F3B4)(1);
            fn_802EC12C();
            fn_802EC1D8();
        }
        holdSongChange = 0;
        if ((unsigned char)lbl_8055EEC8 != 0) {
            now = fn_802E2C20();
            if (now >= lbl_8055EECC && now < lbl_8055EECC + 0xFA0) {
                holdSongChange = 1;
            }
        }
        if (fn_802EC124() == -1 && holdSongChange == 0) {
            fn_802EC11C(lbl_8055B658);
            fn_802EC138();
            resource = *(struct Dummy_802113D8 **)((char *)fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC()) + 0x20);
            resource->f6(&lbl_8055B674, lbl_8033C970);
            if (*(long *)fn_8020FAF0() == 1 && lbl_8055EEBC > 0) {
                lbl_8055B658 = fn_8020F6FC();
            }
        }
        if ((unsigned char)lbl_8055B660 != mute) {
            if (mute != 0) {
                fn_802EC158();
            } else {
                fn_802EC138();
            }
        }
        lbl_8055B660 = mute;
    }
}

 
extern long fn_80145E70(void *);
extern long fn_802090D4(void *);
extern long fn_80209110(void *);
#pragma cplusplus on
struct Dummy_80210904 {
      virtual void f1(long);
  };
#pragma cplusplus off
extern long fn_8000DA10(void);
extern long lbl_8033C9BC[];
extern long lbl_8033C9C8[];
extern long lbl_8055EED4;
extern long lbl_8055EEF0;
extern long lbl_8055B658;
void fn_802108C8(void) {
#define sTrackMusicResource lbl_8055EED4
#define sTrackMusicHandle lbl_8055EEF0
#define OverlayLayoutCreate fn_80145E70
#define sound_volume_open fn_802090D4
#define kTrackMusicLayoutName lbl_8033C9BC  /* "tmuslyt.val" */
#define kTrackMusicSoundName lbl_8033C9C8   /* "TrkMusDash" */
    /* Create the track-music overlay layout and open its dash sound volume handle. */
    sTrackMusicResource = OverlayLayoutCreate(&kTrackMusicLayoutName[0]);
    sTrackMusicHandle = sound_volume_open(&kTrackMusicSoundName[0]);
#undef kTrackMusicSoundName
#undef kTrackMusicLayoutName
#undef sound_volume_open
#undef OverlayLayoutCreate
#undef sTrackMusicHandle
#undef sTrackMusicResource
}
 
#pragma cplusplus on
extern "C" void fn_80210904(void) {
    /* Shut down track music: stop its controller and destroy the active resource. */
#define sTrackMusicHandle lbl_8055EEF0
#define sTrackMusicResource lbl_8055EED4

    fn_80209110(&sTrackMusicHandle);
    struct Dummy_80210904 *resource = (struct Dummy_80210904 *)sTrackMusicResource;
    if (resource != 0) {
        resource->f1(1);
    }
    sTrackMusicResource = 0;

#undef sTrackMusicHandle
#undef sTrackMusicResource
}
#pragma cplusplus off
extern void *lbl_8055EED8;
extern void *lbl_8055EEDC;
#define s_AXFXAlloc lbl_8055EED8
#define s_AXFXFree  lbl_8055EEDC
/* Register the module-local AXFX alloc/free hooks used by the track-music
 * effect: allocHook is called by the music-key handler, freeHook on shutdown. */
void AXFXSetHooks_80210950(void *allocHook, void *freeHook) {
    s_AXFXAlloc = allocHook;
    s_AXFXFree = freeHook;
}
#undef s_AXFXAlloc
#undef s_AXFXFree

#pragma cplusplus on
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(float, float, float);
extern void fn_800109E4(unsigned int, float, float, float, float);
extern void fn_80011A2C(void);
extern float fn_80230EF4(long);
extern float fn_800108C8(char *, float);
extern void fn_80147230(void *, void *, void *);
extern void fn_801476C4(void *);
extern void fn_801473F8(void *, void *, void *, long, long);
extern void fn_8014784C(void *, void *, void *, long);
extern void fn_802C9904(void);
extern unsigned long strlen(const char *);
extern char lbl_8033C940[];
extern float lbl_80563400, lbl_80563404, lbl_80563408, lbl_8056340C;
extern float lbl_80563410, lbl_80563414, lbl_80563418, lbl_8056341C;
extern float lbl_80563420, lbl_80563424;
extern double lbl_80563428;
extern char *lbl_8055B680, *lbl_8055B688, *lbl_8055B690;
extern char *lbl_8055B698, *lbl_8055B69C, *lbl_8055B6A0;
extern "C" void fn_8021095C(void) {
    struct Rec20 {
        long f0; float f4; float f8; long fC; float f10; long f14; long f18; long f1C;
    };
    struct VObj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual Rec20 *getC(void *); virtual void v10(); virtual Rec20 *get14(void *);
    };
    char sp130[0x100];
    char sp100[0x30];
    float sp18, sp1C, sp10, sp14, sp8, spC;
    float f28 = lbl_80563424;
    unsigned int color;
    VObj *root;
    Rec20 *a, *b, *c, *d;
    if (lbl_8055EEDC != 0) ((void (*)(void))lbl_8055EEDC)();
    fn_80230B5C(sp100);
    fn_802C8638(sp100);
    fn_802C974C(lbl_80563404, lbl_80563408, lbl_8056340C);
    fn_800109E4(0x7F000000, lbl_80563410, lbl_80563414, lbl_80563418, lbl_8056341C);
    fn_80011A2C();
    if (lbl_8055EED4 == 0) { fn_80011A2C(); fn_802C9904(); return; }
    root = (VObj *)lbl_8055EED4;
    fn_802101F8((Dummy_802101F8 *)root, (long)(lbl_8033C940 + 0x94), 0,
        (struct Record_802101F8 *)root->get14(lbl_8033C940 + 0xA0));
    color = ((unsigned int)(long)(lbl_80563420 * fn_80230EF4(1)) << 24) | 0x00FF0000 | 0x0000FF00;
    sp18 = lbl_80563400; sp1C = lbl_80563400; sp10 = lbl_80563400; sp14 = lbl_80563400;
    sp8 = lbl_80563400; spC = lbl_80563400;
    a = root->getC(lbl_8055B680);
    b = root->getC(lbl_8055B688);
    c = root->getC(lbl_8055B690);
    if (a != 0 && b != 0 && c != 0) {
        sp18 = b->f4 - a->f4; sp10 = c->f4 - a->f4;
        sp1C = b->f8 - a->f8; sp14 = c->f8 - a->f8;
    }
    d = root->get14(lbl_8033C940 + 0xAC);
    if (d != 0 && a != 0) { sp8 = d->f4 - a->f4; spC = d->f8 - a->f8; }
    fn_80011A2C();
    fn_802C9904();
}
#pragma cplusplus reset

extern long fn_802100AC(void);
extern long fn_80012158(void);
#pragma scheduling invalid_target
long fn_802111E4(long keyCode) {
    /* Handle track-music menu key/input codes: navigate selection, invoke a
     * callback on confirm, refresh state, and return whether the key was handled. */
    switch (keyCode) {
    case 0x126:
        fn_8020FFE4(-1);
        break;
    case 0x128:
        fn_8020FFE4(1);
        break;
    case 0x127:
        fn_8020FEF0(1);
        break;
    case 0x125:
        fn_8020FEF0(-1);
        break;
    case 0x53:
        ((long (* volatile)(long))lbl_8055EED8)((keyCode - 0x58) == 0);
        fn_802100AC();
        break;
    case 0x113:
    case 0x1B:
        break;
    default:
        return 0;
    }
    fn_80012158();
    return 1;
}

void fn_802112AC(void) {
    long mode;
    long trackIndex;
    long quotient;
    long remainder;
    long trackCount;
    void *base;
    struct Dummy_802113D8 *object;

    /* Initialize track selection state and update display counters from current track data. */
    if (lbl_8055EEC0 != 0) {
        lbl_8055EEE0 = -2;
        if (lbl_8055EEBC > 0) {
            fn_8020FCC4();
            base = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
            object = *(struct Dummy_802113D8 **)((char *)base + 0x20);
            object->f6(&lbl_8055B674, lbl_8033C970);
            mode = *(long *)fn_8020FAF0();
            if (mode == 1) {
                lbl_8055EEE0 = -1;
            } else if (mode == 2) {
                trackIndex = lbl_8055B658;
                if (trackIndex >= 0) {
                    quotient = trackIndex / 10;
                    remainder = trackIndex % 10;
                    lbl_8055EEE4 = quotient;
                    lbl_8055EEE0 = remainder;
                }
            }
        }
    }
    trackCount = lbl_8055EEBC / 10;
    lbl_8055EEE8 = trackCount;
    if ((lbl_8055EEBC % 10) != 0 || lbl_8055EEBC == 0) {
        trackCount++;
        lbl_8055EEE8 = trackCount;
    }
    if (lbl_8055EEE4 >= trackCount) {
        lbl_8055EEE4 = 0;
    }
}

#pragma scheduling on
extern long fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80206444(void);
extern void fn_80209190(long, float);
extern long __AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(long);
extern void *fn_8020FAF0();
extern char lbl_8033C970[];
extern long lbl_8055B65C;
extern long lbl_8055B674;
extern signed char lbl_8055EEEC;
extern signed char lbl_8055EEED;
extern float lbl_80563400;
void fn_802113D8(void) {
    long mode;
    long trackIndex;
    long pageIndex;
    long digitIndex;
    long zero = 0;
    long minusTwo = -2;
    void *container;
    struct Dummy_802113D8 *resource;

    /* Initializes track-music selection state, refreshes the current track resource, and decodes the saved track index into page/digit selection. */
    if (fn_80265D64() == 0) {
        __AXDSPInitCallback_801769E0();
    }
    fn_80206444();
    fn_80209190(lbl_8055EEF0, lbl_80563400);
    lbl_8055EEE0 = minusTwo;
    lbl_8055EEE4 = zero;
    lbl_8055B65C = lbl_8055B658;
    lbl_8055EEEC = zero;
    lbl_8055EEED = zero;
    container = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
    resource = *(struct Dummy_802113D8 **)((char *)container + 0x20);
    resource->f6(&lbl_8055B674, lbl_8033C970);
    mode = *(long *)fn_8020FAF0();
    if (mode == 1) {
        lbl_8055EEE0 = -1;
    } else if (mode == 2) {
        trackIndex = lbl_8055B658;
        if (trackIndex >= 0) {
            pageIndex = trackIndex / 10;
            digitIndex = trackIndex % 10;
            lbl_8055EEE4 = pageIndex;
            lbl_8055EEE0 = digitIndex;
        }
    }
}

extern float lbl_80563404;
extern void fn_80206454(void);
extern void fn_801769EC(void);
#pragma scheduling on
/* Restore track-music volume to full, resume sound, and run the DSP init hook. */
void fn_802114C4(void) {
    float volume = 1.0f;
    fn_80209190(lbl_8055EEF0, volume);
    fn_80206454();
    fn_801769EC();
}
extern void fn_801345D8(void *, ...);
extern long lbl_8055B664;
extern signed char lbl_8055EEF4;
extern signed char lbl_8055EEF5;
extern signed char lbl_8055EEF6;
// Code of main that had no source file yet: decomp.wtf gave it this one.
 // split_file divides it into the game's real files (file_status shows its range).

extern void fn_8020F730(void);
extern long fn_8020F9F4(void);
extern int stricmp(const char *, const char *);
extern int fn_8002B1D8(const char *, const char *, int);
