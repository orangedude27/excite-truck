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
extern long gTrackMusicPageCount;
extern long gTrackMusicCurrentSong;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
  
extern void *findTrackMusicEntry();
extern long fn_8000DA10(void);
extern long fn_8020F9F4(void);
extern int stricmp(const char *, const char *);
// Track-music file list: m_entries is an array of m_count char* song paths
// (fn_8020F950 fills it from the dash's scanned music table), m_capacity is how
// many of them fit in the buffer.
extern struct TrackMusicList { char **m_entries; long m_count; long m_capacity; } gTrackMusicPathList;
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
extern long gTrackMusicCurrentSong;
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
extern long gSngPathFormat;
int buildSngSongPath(int source, int destination, int size) {
    /* Format a track-music song path ("%s.sng") into the destination buffer and return it. */
    fn_801345D8((void *)destination, size, (void *)&gSngPathFormat, source);
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
        if (fn_8012E938(buildSngSongPath((long)gSongName0, (long)pathBuffer, 0x40)) != 0) {
            buildSngSongPath((long)gSongName0, (long)pathBuffer, 0x40);
            fn_8012E81C();
            fn_802EC294(0, fn_8020F3BC((int)gSongName0, (int)pathBuffer, 0x40));
            fn_802E30C8(gTriedToLoad, pathBuffer);
            gSongLoaded0 = 1;
        }
    }
    if ((unsigned char)gSongLoaded1 == 0) {
        if (fn_8012E938(buildSngSongPath((long)gSongName1, (long)pathBuffer, 0x40)) != 0) {
            buildSngSongPath((long)gSongName1, (long)pathBuffer, 0x40);
            fn_8012E81C();
            fn_802EC294(1, fn_8020F3BC((int)gSongName1, (int)pathBuffer, 0x40));
            fn_802E30C8(gTriedToLoad, pathBuffer);
            gSongLoaded1 = 1;
        }
    }
    if ((unsigned char)gSongLoaded2 == 0) {
        if (fn_8012E938(buildSngSongPath((long)gSongName2, (long)pathBuffer, 0x40)) != 0) {
            buildSngSongPath((long)gSongName2, (long)pathBuffer, 0x40);
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
/* Zero a context's 0x1900-byte track-music buffer and set the state word of each of its 64 slots (stride 0x64 = 25 longs) to slotState (0 idle, 1 active). */ long fn_8020F608(long slotState, long contextIndex) {
    long *slotPtr;
    long slotIndex;
    slotPtr = (long *)fn_8020F5F0(contextIndex);
    memset(slotPtr, 0, 0x1900);
    for (slotIndex = 0; slotIndex < 64; slotIndex++) {
        *slotPtr = slotState;
        slotPtr += 25;
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
long getNextTrackMusicIndex(void) {
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
    long count = gTrackMusicPathList.m_count;
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
/* Rebuild the track-music list from the dash's scanned songs (up to the buffer capacity), then recompute the shuffled play order. */ void fn_8020F950(void) {
    /* Rebuild the track-music list from the dash's scanned music table - one
       path per scanned song, as many as the list's buffer holds - and rebuild
       the shuffled play order from the new count. */
    long capacity;
    long limit;
    long i;
    long index;
    char *path;
    char **entries;
    capacity = gTrackMusicPathList.m_capacity;
    gTrackMusicPathList.m_count = 0;
    limit = ((long (*)(struct TrackMusicList *))fn_802EC0FC)(&gTrackMusicPathList);
    if (capacity < limit) {
        limit = capacity;
    }
    i = 0;
    while (i < limit) {
        path = fn_802EC104(i);
        index = gTrackMusicPathList.m_count;
        i++;
        entries = gTrackMusicPathList.m_entries;
        gTrackMusicPathList.m_count = index + 1;
        entries[index] = path;
    }
    fn_8020F730();
}

#pragma scheduling invalid_target
/* Return the index of the first free slot (slot state byte == 0) in the current context's 8 groups of 8 track-music entries, scanning groups in order; returns 0 when every slot is taken. */ long fn_8020F9F4(void) {
    char *groupSlots;
    long slotIndex;
    long groupIndex;
    long nextIndex0;
    long nextIndex1;
    long nextIndex2;
    long nextIndex3;
    long nextIndex4;
    long nextIndex5;
    long nextIndex6;

    groupSlots = (char *)fn_8020F5F0(fn_8000DA10());
    slotIndex = 0;
    for (groupIndex = 0; groupIndex < 8; groupIndex++) {
        if ((signed char)groupSlots[4] == 0) {
            return slotIndex;
        }
        nextIndex0 = slotIndex + 1;
        if ((signed char)groupSlots[0x68] == 0) {
            return nextIndex0;
        }
        nextIndex1 = nextIndex0 + 1;
        if ((signed char)groupSlots[0xCC] == 0) {
            return nextIndex1;
        }
        nextIndex2 = nextIndex1 + 1;
        if ((signed char)groupSlots[0x130] == 0) {
            return nextIndex2;
        }
        nextIndex3 = nextIndex2 + 1;
        if ((signed char)groupSlots[0x194] == 0) {
            return nextIndex3;
        }
        nextIndex4 = nextIndex3 + 1;
        if ((signed char)groupSlots[0x1F8] == 0) {
            return nextIndex4;
        }
        nextIndex5 = nextIndex4 + 1;
        if ((signed char)groupSlots[0x25C] == 0) {
            return nextIndex5;
        }
        nextIndex6 = nextIndex5 + 1;
        if ((signed char)groupSlots[0x2C0] == 0) {
            return nextIndex6;
        }
        groupSlots += 0x320;
        slotIndex = nextIndex6 + 1;
    }
    return 0;
}

#pragma push
#pragma dont_inline on
/* Find the track-music entry whose key matches `key`, or the first free entry if none match. */
void *findTrackMusicEntry(key)
char *key;
{
    char *entry;
    char *entries = (char *)fn_8020F5F0(fn_8000DA10());
    long index = 0;
    entry = entries;
    for (;;) {
        if (stricmp(entry + 4, key) == 0) {
            return entries + index * 0x64;
        }
        index++;
        entry += 0x64;
        if (index >= 0x40) break;
    }
    return entries + fn_8020F9F4() * 0x64;
}
#pragma dont_inline reset
#pragma pop

#pragma scheduling on

#pragma use_lmw_stmw off
#pragma dont_inline on
/* Return the index of the track-music path matching `name` (compared up to 63
 * bytes by fn_8002B1D8), or the -1 no-song sentinel (fn_8020F3B4) when absent. */
/* Return the index of the track-music path matching `name` (compared up to 63 bytes by fn_8002B1D8), or the -1 no-song sentinel (fn_8020F3B4) when absent. */ int fn_8020FB80(void *name) {
    int entryOffset;
    int index;
    index = 0;
    entryOffset = 0;
    while (index < gTrackMusicPathList.m_count) {
        if (fn_8002B1D8(*(char **)((char *)gTrackMusicPathList.m_entries + entryOffset), (char *)name, 0x3F) == 0) {
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
/* Return the song path of the current track-music entry: none, the next shuffled list path (type 1), or the entry's inline path. */
void *getCurrentTrackMusicPath(void) {
    char *entry = (char *)findTrackMusicEntry();
    long type;
    if (entry == 0) {
        goto null_result;
    }
    type = *(long *)entry;
    if (type == 0) {
        return (void *)0;
    }
    if (type == 1) {
        return (void *)gTrackMusicPathList.m_entries[getNextTrackMusicIndex()];
    }
    return entry + 0x24;
null_result:
    return 0;
}
#pragma dont_inline reset

extern int fn_8020FB80(void *);
#pragma scheduling invalid_target
int fn_8020FC6C(void) {
    void *p;
    if (gTrackMusicPathList.m_count == 0) {
        return ((int (*)(int))fn_8020F3B4)(0);
    } else if ((p = getCurrentTrackMusicPath()) != 0) {
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
/* Pick the track-music song for the current scene event, log the choice and switch to it, stopping the old song first when it changes. */ extern "C" void fn_8020FCC4(void) {
    #define TRACK_SONGS     gTrackMusicPathList
    #define CURRENT_SONG    gTrackMusicCurrentSong
    #define EVENT_NAME_OUT  lbl_8055B674
    #define NO_EVENT        lbl_8033C970   /* "invalid_contest" */
    #define FOUND_MSG       lbl_8033C980   /* "TrackMusic: Found song %d (%s) for event %s" */
    #define SCENE_IDX_PTR   __AXFXGetLfoSinTable_801769CC

    int eventName;
    int songIndex;
    int currentSong;
    void *scene;
    struct Dummy_802113D8 *sceneResource;
    scene = fn_8001285C(*(long *)SCENE_IDX_PTR());
    sceneResource = *(struct Dummy_802113D8 **)((char *)scene + 0x20);
    eventName = sceneResource->f6(&EVENT_NAME_OUT, NO_EVENT);
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
/* Initialize the current track-music slot (found by findTrackMusicEntry): store the track id, copy the display name, and copy the slot key (truncated to 0x20 bytes). */ void fn_8020FDE4(long trackId, const char *name, register char *slotKey) {
    /* Initialize a track-music slot: store the track id, copy the display name, and copy the slot key (truncated to 0x20). */
    char *entry;
    long remaining;
    char *keyDst;
    unsigned char ch;

    entry = (char *)((void *(*)(char *))findTrackMusicEntry)(slotKey);
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
/* Resolve the track-music menu selection into the song id now playing: cancel
 * the pending song request and abort the old MP3, then choose no song (OFF), the
 * next track of the shuffled order (RANDOM), or the selected row on its page. */
void fn_8020FE90(void) {
#define SELECTION     lbl_8055EEE0   /* -2 OFF, -1 RANDOM, >= 0 row on the page */
#define PAGE          lbl_8055EEE4
#define SONG          gTrackMusicCurrentSong
#define OFF           (-2)
#define RANDOM        (-1)
#define ROWS_PER_PAGE 10
    long track;

    fn_802EC12C();
    fn_802EC1D8();
    if (SELECTION == OFF) {
        SONG = ((long (*)(long))fn_8020F3B4)(0);
        return;
    }
    if (SELECTION == RANDOM) {
        track = getNextTrackMusicIndex();
    } else {
        track = SELECTION + (PAGE * ROWS_PER_PAGE);
    }
    SONG = track;
#undef ROWS_PER_PAGE
#undef RANDOM
#undef OFF
#undef SONG
#undef PAGE
#undef SELECTION
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
        max = clampTrackDigit(sum, gTrackMusicPageCount - 1);
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
extern long gTrackMusicPageCount;
extern void fn_8020FE90(void);
/* Adjust the track-music selection by delta (-2 = OFF, -1 = RANDOM, >= 0 = a row on the current page), clamping it to the last valid row, and re-resolve the current track when the selection changed. */
void fn_8020FFE4(long delta) {
    long oldSelection = lbl_8055EEE0;
    long songCount = lbl_8055EEBC;
    long maxRow;
    if (songCount == 0) lbl_8055EEE0 = -2;
    else {
        maxRow = 9;
        if ((lbl_8055EEE4 + 1) * 10 >= songCount) maxRow = (songCount - 1) % 10;
        if (oldSelection == -2) { if (delta == 1) lbl_8055EEE0 = 0; }
        else if (oldSelection == -1) { if (delta == 1) lbl_8055EEE0 = 0; }
        else {
            lbl_8055EEE0 = (*(volatile long *)&lbl_8055EEE0) + delta;
            if (lbl_8055EEE0 < 0) lbl_8055EEE0 = -2;
            if (lbl_8055EEE0 > maxRow) lbl_8055EEE0 = maxRow;
        }
    }
    if (oldSelection != lbl_8055EEE0) fn_8020FE90();
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
        fn_8020FDE4(2, (const char *)gTrackMusicPathList.m_entries[songIndex],
                    (char *)resourceObj->f6(&lbl_8055B674, lbl_8033C970));
        gTrackMusicCurrentSong = songIndex;
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
/* Lay out the three dash step markers, spacing UI entries along the record's x position using float widths read from the widget's resource set. */ extern "C" void fn_802101F8(Dummy_802101F8 *widget, long resource, long baseStep, struct Record_802101F8 *record) {
    /* Lay out three stepped track-music UI entries, fetching each step's float value from the widget's resource set and advancing the record's float position. */
    long widgetResourceSet;
    struct Record_802101F8 rec;
    long step;
    long posY;
    long posX;

    if (widget == 0 || record == 0) return;
    widgetResourceSet = widget->v4();
    step = 0;
    rec.f0 = record->f0;
    posX = ((volatile struct Record_802101F8 *)record)->f4;
    posY = ((volatile struct Record_802101F8 *)record)->f8;
    rec.f4 = posX;
    rec.f8 = posY;
    rec.fC = record->fC;
    rec.f10 = record->f10;
    rec.f14 = record->f14;
    rec.f18 = record->f18;
    do {
        long entryIndex = baseStep + step;
        if (step == 1) {
            float lastStepValue = fn_80235EF0(widgetResourceSet, baseStep + 2);
            rec.f10 = (record->f10 - fn_80235EF0(widgetResourceSet, baseStep)) - lastStepValue;
        } else {
            rec.f10 = fn_80235EF0(widgetResourceSet, entryIndex);
        }
        fn_80147940(widget, &rec, resource, entryIndex);
        step++;
        *(float *)&rec.f4 += rec.f10;
    } while (step < 3);
}
#pragma cplusplus reset
 
/* Set up the track-music buffer: zero its 0x6400 bytes, register it as the
 * 'Tmus' memcard chunk, and install the clear-context broadcast callback. */
void fn_8021031C(void) {
#define TMUS_TAG    0x546D7573
#define BUFFER_SIZE 0x6400
    long resourceTag;
    char *trackMusicBuffer;
    resourceTag = TMUS_TAG;
    trackMusicBuffer = lbl_80489CA0;
    memset(&lbl_80489CA0, 0, BUFFER_SIZE);
    fn_802E6BD8(resourceTag, 0, trackMusicBuffer, BUFFER_SIZE, 0);
    fn_8000DBC8(&fn_8020F6E0);
#undef BUFFER_SIZE
#undef TMUS_TAG
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
/* Shut down track music: fade out/stop playback, destroy the track-music resource and goalline SFX objects if present, clear current song state, and mark load slots unloaded. */
extern "C" void fn_802103BC(void) {
    class Obj { public: virtual void f(long); };
    ((void (*)(float))fn_802EC1C0)(0.0f);
    fn_802EC12C();
    fn_802EC1E4();
    if (lbl_8055EED4 != 0) {
        ((Obj *)lbl_8055EED4)->f(1);
    }
    lbl_8055EED4 = 0;
    gTrackMusicCurrentSong = -1;
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
extern unsigned char gTrackMusicListChanged;
extern signed char gTrackMusicHoldSongChange, gTrackMusicMuted;
extern long gTrackMusicHoldUntil, gTrackMusicCurrentSong;
/* Stop track music: mute playback and clear the song-list-changed and
 * song-change-hold flags.  If no scene or arena event is active and the current
 * song is the "off" sentinel, reset it to the no-song value and abort playback. */
void stopTrackMusic(void) {
    gTrackMusicMuted = 1;
    gTrackMusicListChanged = 0;
    gTrackMusicHoldSongChange = 0;
    gTrackMusicHoldUntil = 0;
    if (fn_80009C84() == 0 && fn_801B85CC() == 0 &&
        gTrackMusicCurrentSong == ((long (*)(long))fn_8020F3B4)(1)) {
        gTrackMusicCurrentSong = ((long (*)(long))fn_8020F3B4)(0);
        fn_802EC12C();
        fn_802EC1D8();
    }
}

/* True (1) when a track-music song is selected (current song id gTrackMusicCurrentSong != -1). */
long fn_802104B8(void) {
    return (unsigned long)((-1 - gTrackMusicCurrentSong) | (gTrackMusicCurrentSong + 1)) >> 31;
}

/* True when the dash found at least one track-music song (song count > 0). */
long fn_802104D0(void) {
    return fn_802EC0FC() > 0;
}

long fn_802104FC(void) {
    /* Return nonzero when no track-music entry is selected (the current track index is -1). */
    return (gTrackMusicCurrentSong + 1) == 0;
}

 
/* Tail-call thunk: set the master sound volume (branches to fn_802EC1C0), which
 * stores it and re-applies it if sound is already enabled. Used by pre-race music
 * (fn_8020C140) to set/fade the volume. */
void fn_80210510(float volume) {
    ((void (*)(float))fn_802EC1C0)(volume);
}

/* Clear the current player's track-music buffer and stamp its 64 slot states to
   slotState (0 idle, 1 active); state 2 is a no-op. */
void trackMusicSetSlotStates(int slotState) {
    switch (slotState) {
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
        gTrackMusicListChanged = 1;
    } else {
        gTrackMusicListChanged = 0;
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
    if (gTrackMusicCurrentSong != -1) {
        if (gTrackMusicCurrentSong == ((long (*)(long))fn_8020F3B4)(0) && overlayUp != 0) {
            gTrackMusicCurrentSong = ((long (*)(long))fn_8020F3B4)(2);
            fn_802EC12C();
            fn_802EC1D8();
        } else if (gTrackMusicCurrentSong == ((long (*)(long))fn_8020F3B4)(2) && overlayUp == 0) {
            gTrackMusicCurrentSong = ((long (*)(long))fn_8020F3B4)(0);
            fn_802EC12C();
            fn_802EC1D8();
        } else if (gTrackMusicCurrentSong == ((long (*)(long))fn_8020F3B4)(0) && sceneActive != 0) {
            gTrackMusicCurrentSong = ((long (*)(long))fn_8020F3B4)(1);
            fn_802EC12C();
            fn_802EC1D8();
        }
        holdSongChange = 0;
        if ((unsigned char)gTrackMusicHoldSongChange != 0) {
            now = KERNEL_GetTimeMs();
            if (now >= gTrackMusicHoldUntil && now < gTrackMusicHoldUntil + 0xFA0) {
                holdSongChange = 1;
            }
        }
        if (fn_802EC124() == -1 && holdSongChange == 0) {
            fn_802EC11C(gTrackMusicCurrentSong);
            fn_802EC138();
            resource = *(struct Dummy_802113D8 **)((char *)fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC()) + 0x20);
            resource->f6(&lbl_8055B674, lbl_8033C970);
            if (*(long *)findTrackMusicEntry() == 1 && lbl_8055EEBC > 0) {
                gTrackMusicCurrentSong = getNextTrackMusicIndex();
            }
        }
        if ((unsigned char)gTrackMusicMuted != mute) {
            if (mute != 0) {
                fn_802EC158();
            } else {
                fn_802EC138();
            }
        }
        gTrackMusicMuted = mute;
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
extern long gTrackMusicCurrentSong;
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
extern "C" void destroyTrackMusicResource(void) {
    /* Shut down track music: release the volume handle and destroy the overlay-layout resource. */
#define sTrackMusicHandle lbl_8055EEF0
#define sTrackMusicResource lbl_8055EED4

    fn_80209110(&sTrackMusicHandle);
    struct Dummy_80210904 *musicResource = (struct Dummy_80210904 *)sTrackMusicResource;
    if (musicResource != 0) {
        musicResource->f1(1);
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
    /* Handle one track-music dash command: 0x126/0x128 move the song selection up/down a row (fn_8020FFE4), 0x125/0x127 step the page or toggle OFF/RANDOM (fn_8020FEF0), 0x53 confirm/apply (call the hook at lbl_8055EED8 then fn_802100AC); 0x113/0x1B are ignored. Handled keys refresh the active entry (fn_80012158) and return 1; all others return 0. */
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

/* After the dash's song list changed, re-sync the track-music menu selection
 * (OFF / RANDOM / song row + page) to the song in use, then rebuild the page
 * count (10 songs per page, always at least one) and reset an out-of-range page. */
void fn_802112AC(void) {
#define trackMusicSongListChanged gTrackMusicListChanged /* the song list was just rebuilt */
#define trackMusicSelection       lbl_8055EEE0 /* -2 = OFF, -1 = RANDOM, >= 0 = row on the page */
#define trackMusicPage            lbl_8055EEE4 /* song-list page the menu is on */
#define trackMusicSongCount       lbl_8055EEBC /* songs the dash found */
#define trackMusicCurrentSong     gTrackMusicCurrentSong /* song id in use (-1 = none) */
#define EVENT_NAME_OUT            lbl_8055B674 /* scene/event name output buffer */
#define NO_EVENT                  lbl_8033C970 /* "invalid_contest" */
#define SEL_OFF                   (-2)
#define SEL_RANDOM                (-1)
#define SONGS_PER_PAGE            10
    long entryType;
    long songIndex;
    long page;
    long row;
    long pageCount;
    void *container;
    struct Dummy_802113D8 *resource;

    if (trackMusicSongListChanged != 0) {
        trackMusicSelection = SEL_OFF;
        if (trackMusicSongCount > 0) {
            fn_8020FCC4();
            container = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
            resource = *(struct Dummy_802113D8 **)((char *)container + 0x20);
            resource->f6(&EVENT_NAME_OUT, NO_EVENT);
            entryType = *(long *)findTrackMusicEntry();
            if (entryType == 1) {
                trackMusicSelection = SEL_RANDOM;
            } else if (entryType == 2) {
                songIndex = trackMusicCurrentSong;
                if (songIndex >= 0) {
                    page = songIndex / SONGS_PER_PAGE;
                    row = songIndex % SONGS_PER_PAGE;
                    trackMusicPage = page;
                    trackMusicSelection = row;
                }
            }
        }
    }
    pageCount = trackMusicSongCount / SONGS_PER_PAGE;
    gTrackMusicPageCount = pageCount;
    if ((trackMusicSongCount % SONGS_PER_PAGE) != 0 || trackMusicSongCount == 0) {
        pageCount++;
        gTrackMusicPageCount = pageCount;
    }
    if (trackMusicPage >= pageCount) {
        trackMusicPage = 0;
    }
#undef trackMusicSongListChanged
#undef trackMusicSelection
#undef trackMusicPage
#undef trackMusicSongCount
#undef trackMusicCurrentSong
#undef EVENT_NAME_OUT
#undef NO_EVENT
#undef SEL_OFF
#undef SEL_RANDOM
#undef SONGS_PER_PAGE
}

#pragma scheduling on
extern long fn_80265D64(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80206444(void);
extern void fn_80209190(long, float);
extern long __AXFXGetLfoSinTable_801769CC(void);
extern void *fn_8001285C(long);
extern void *findTrackMusicEntry();
extern char lbl_8033C970[];
extern long lbl_8055B65C;
extern long lbl_8055B674;
extern signed char lbl_8055EEEC;
extern signed char lbl_8055EEED;
extern float lbl_80563400;
void fn_802113D8(void) {
#define sTrackMusicHandle     lbl_8055EEF0
#define defaultVolume         lbl_80563400
#define trackMusicSelection   lbl_8055EEE0 /* -2 = OFF, -1 = RANDOM, >= 0 = row on the page */
#define trackMusicPage        lbl_8055EEE4 /* song-list page the menu is on */
#define trackMusicPrevSong    lbl_8055B65C /* song id from the previous selection, kept for restart */
#define trackMusicCurrentSong gTrackMusicCurrentSong /* song id in use (-1 = none) */
#define sResetOnStop          lbl_8055EEEC /* reset the context music buffer when stopped */
#define sResetOnRandom        lbl_8055EEED /* reset the context music buffer when randomized */
#define EVENT_NAME_OUT        lbl_8055B674 /* scene/event name output buffer */
#define NO_EVENT              lbl_8033C970 /* "invalid_contest" */
#define SEL_OFF               (-2)
#define SEL_RANDOM            (-1)
#define SONGS_PER_PAGE        10
    long entryType;
    long songIndex;
    long page;
    long row;
    long zero = 0;
    long minusTwo = -2;
    void *audioContainer;
    struct Dummy_802113D8 *resourceObj;

    /* Initializes track-music selection state, refreshes the current track resource, and decodes the saved song index into page/row selection. */
    if (fn_80265D64() == 0) {
        __AXDSPInitCallback_801769E0();
    }
    fn_80206444();
    fn_80209190(sTrackMusicHandle, defaultVolume);
    trackMusicSelection = minusTwo;
    trackMusicPage = zero;
    trackMusicPrevSong = trackMusicCurrentSong;
    sResetOnStop = zero;
    sResetOnRandom = zero;
    audioContainer = fn_8001285C(*(long *)__AXFXGetLfoSinTable_801769CC());
    resourceObj = *(struct Dummy_802113D8 **)((char *)audioContainer + 0x20);
    resourceObj->f6(&EVENT_NAME_OUT, NO_EVENT);
    entryType = *(long *)findTrackMusicEntry();
    if (entryType == 1) {
        trackMusicSelection = SEL_RANDOM;
    } else if (entryType == 2) {
        songIndex = trackMusicCurrentSong;
        if (songIndex >= 0) {
            page = songIndex / SONGS_PER_PAGE;
            row = songIndex % SONGS_PER_PAGE;
            trackMusicPage = page;
            trackMusicSelection = row;
        }
    }
#undef SONGS_PER_PAGE
#undef SEL_RANDOM
#undef SEL_OFF
#undef NO_EVENT
#undef EVENT_NAME_OUT
#undef sResetOnRandom
#undef sResetOnStop
#undef trackMusicCurrentSong
#undef trackMusicPrevSong
#undef trackMusicPage
#undef trackMusicSelection
#undef defaultVolume
#undef sTrackMusicHandle
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
