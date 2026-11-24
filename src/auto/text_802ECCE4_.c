#include "types.h"
// Symbol guide (the project cannot rename game symbols yet): copyMovieName
// (fn_802ECCE4), initMovieRecord (fn_802ECD68), popSingleMovie (fn_802ECDF4),
// playSingleMovie (fn_802ECE48), retireSingleMovie (fn_802ECEC0), playUISingle
// (fn_802ECEC4), hasSingleMovie (fn_802ECEEC), openMovieRecord (fn_802ECF08),
// movieNameMatches (fn_802ECF90), playMovie (fn_802ECFEC), destroyMovie
// (fn_802ECFF4), setupMovieDraw (fn_802ED038), movieFinished (fn_802ED040).
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Movie play records (src/game/video.c is the movie player they drive).
 * A record is 0x44 bytes: char name[0x40] holding the movie's file name without
 * extension, then the movie handle fn_802E11A4 opened for that name at +0x40.
 * fn_802ECE48 builds 0x48-byte "single_movie_info" nodes: the same record plus a
 * next pointer at +0x44, chained into lbl_805600F8. */
typedef struct MoviePlayInfo {
    char name[0x40]; /* 0x00 movie file name, without its extension */
    void *handle;    /* 0x40 the movie object fn_802E11A4 opened for that name */
} MoviePlayInfo;     /* 0x44: the record the heap tag "MoviePlayInfo" names */

/* One entry of the "single_movie_info" list: the movie record plus the link into
 * that list, whose head lbl_805600F8 answers every movie request with.
 * fn_802ECE48 pushes an entry, fn_802ECDF4 pops the head again. */
typedef struct SingleMovieInfo {
    MoviePlayInfo info;           /* 0x00 the movie's name and its opened handle */
    struct SingleMovieInfo *next; /* 0x44 the entry this one pushes off the head */
} SingleMovieInfo;                /* 0x48: the node the heap tag "single_movie_info" names */

extern void fn_802E12DC(void *); /* video.c: play/advance a movie */
extern void BinkMovie_Unload(void *); /* video.c: drMovieUnload, close a movie */
extern void fn_80128668(void *); /* free an allocated object block */
extern s32 lbl_805600F8; /* head of the "single_movie_info" list; while it is set that
                          * one record answers every request, so nothing is allocated,
                          * freed or compared against */
extern char lbl_8034EC04[]; /* "single_movie_info": heap tag of the 0x48-byte node */
extern char lbl_8034EC18[]; /* "MoviePlayInfo": heap tag of the 0x44-byte record */
extern s32 lbl_8055D308; /* char[8] "missing": movie name opened when the wanted one is not there */
#pragma dont_inline fn_802ECCE4
#pragma dont_inline fn_802ECD68
#pragma dont_inline fn_802ECDF4
#pragma dont_inline fn_802ECE48
#pragma dont_inline fn_802ECEC0
#pragma dont_inline fn_802ECF04
extern void fn_802ECCE4(char *, void *, s32);
extern s32 stricmp(const char *, const char *);
extern s32 fn_802ECEEC(void);
// fn_802ECE48 declared at its definition below
extern s32 fn_802ECDF4(void);
// fn_802ECEC0 declared at its definition below
extern char *lbl_8055D300; /* points at "uisingle": the movie to play when none was asked for */
extern void *fn_801284F8(s32, const char *);
extern s32 fn_802ECD68(void *, void *, s32);
#pragma scheduling reset
extern unsigned char *fn_80029004(const unsigned char *, int);
extern void strncpy(unsigned char *, const unsigned char *, int);
#pragma dont_inline on
/* Copies at most arg2 bytes of src into dst, truncating at the first '.' (including it) when present, and NUL-terminates within the copied length. */
void fn_802ECCE4(char *dst, void *src, s32 maxLen) {
    s32 length = maxLen;
    unsigned char *match = fn_80029004((const unsigned char *)src, 0x2E);

    if (match != 0) {
        s32 matchLength = (s32)((match + 1) - (unsigned char *)src);
        if (matchLength < length) {
            length = matchLength;
        }
    }
    strncpy((unsigned char *)dst, (const unsigned char *)src, length);
    *((unsigned char *)dst + length - 1) = 0;
}
#pragma dont_inline reset

/* Initializes a 0x44-byte record with a copied name and resolves/stores its handle. */
s32 fn_802ECD68(void *record, void *name, s32 mode) {
    s32 handle;
    memset(record, 0, 0x44);
    fn_802ECCE4((char *)record, name, 0x40);
    handle = fn_802E11A4(record, mode);
    if (handle == 0) {
        handle = fn_802E11A4((char *)&lbl_8055D308, mode);
    }
    ((s32 *)record)[16] = handle;
    return handle != 0;
}

#pragma dont_inline on
s32 fn_802ECDF4(void) {
    /* Retire the movie at the head of the single-movie list: close the movie it
     * opened, free the node and let the entry behind it take its place. 0 when the
     * list is empty; fn_802ECEC4 pops one and then queues the "uisingle" movie. */
    SingleMovieInfo *next;

    if (lbl_805600F8 != 0) {
        BinkMovie_Unload(((SingleMovieInfo *)lbl_805600F8)->info.handle);
        next = ((SingleMovieInfo *)lbl_805600F8)->next;
        fn_80128668((void *)lbl_805600F8);
        lbl_805600F8 = (s32)next;
        return 1;
    }
    return 0;
}

#pragma dont_inline on
s32 fn_802ECE48(char *movieName) {
    /* Play one movie by itself: make a node for it and put it at the head of the
     * single-movie list lbl_805600F8, whose head record answers every movie request
     * (fn_802ECF08 hands that record out instead of opening one, and fn_802ECF90
     * finds any name a match for it). The node is freed and 0 returned when the
     * movie cannot be opened. */
    SingleMovieInfo *node;

    node = fn_801284F8(sizeof(SingleMovieInfo), lbl_8034EC04);
    if (fn_802ECD68(node, movieName, 1) != 0) {
        node->next = (SingleMovieInfo *)lbl_805600F8;
        lbl_805600F8 = (s32)node;
        return 1;
    }
    fn_80128668(node);
    return 0;
}
#pragma dont_inline reset

#pragma dont_inline on
/* Retire the current single movie: tail-call fn_802ECDF4 to pop the list head,
 * returning nonzero when a movie was removed. */
s32 fn_802ECEC0(void) {
    return fn_802ECDF4();
}
#pragma dont_inline reset

/* Stop the current single movie, then play the "uisingle" movie on its own. */
void fn_802ECEC4(void) {
    fn_802ECEC0();
    fn_802ECE48(lbl_8055D300);
}

s32 fn_802ECEEC(void) {
    /* Branchless 1 when the single-movie list head is set (one record answers every request), else 0. */
    s32 listHead = lbl_805600F8;
    u32 bits = (u32)(-listHead) | (u32)listHead;
    return (s32)(bits >> 31);
}

/* Tail-call forward to fn_802ECE48: enqueue movieName as the head of the
   single-movie list, passing its success/failure result straight back. */
void fn_802ECF00(char *movieName) {
    fn_802ECE48(movieName);
}

#pragma dont_inline on
/* Pop the head of the single-movie list via fn_802ECDF4, returning nonzero if a
 * movie was removed. The dont_inline pragma keeps this a real tail-call wrapper. */
s32 fn_802ECF04(void) {
    return fn_802ECDF4();
}
#pragma dont_inline reset

#pragma dont_inline on
#pragma scheduling invalid_target
/* Open a movie and keep it for the caller: allocate a MoviePlayInfo record (heap
 * tag "MoviePlayInfo") for the movie file `movieName`, resolve it through
 * fn_802ECD68 (which opens "<name>.bik" with @p mode) and return the record, or
 * NULL when the movie could not be opened. Unlike fn_802ECE48 the record is not
 * chained into the movie list, so the caller owns it (fn_802ECFF4 destroys it).
 * While one "single_movie_info" record stands in for every movie, that record
 * answers for every name and nothing is allocated. */
void *fn_802ECF08(void *movieName, s32 mode) {
    MoviePlayInfo *record;
    if (fn_802ECEEC() != 0) {
        return (void *)lbl_805600F8;
    }
    record = fn_801284F8(sizeof(MoviePlayInfo), lbl_8034EC18);
    if (fn_802ECD68(record, movieName, mode) == 0) {
        fn_80128668(record);
        record = 0;
    }
    return record;
}
#pragma scheduling reset
#pragma dont_inline reset
/* Returns whether a movie record already plays the movie `movieName` asks for: the
 * name stored in the record (its first 0x40 bytes) and `movieName`'s base name, up to
 * and including the first '.', are the same ignoring case. While one
 * "single_movie_info" record stands in for every movie (lbl_805600F8), every name
 * matches, so the caller keeps the record it has. */
s32 fn_802ECF90(char *record, void *movieName) {
    char baseName[64];

    if (lbl_805600F8 != 0) {
        return 1;
    }
    fn_802ECCE4(baseName, movieName, 64);
    return stricmp(baseName, record) == 0;
}
/* Advance/play, for this frame, the movie whose handle the MoviePlayInfo record holds. */
void fn_802ECFEC(MoviePlayInfo *record) {
    fn_802E12DC(record->handle);
}

/* Destroy the given movie object when no current movie is set. */
void fn_802ECFF4(void *movie) {
    if (lbl_805600F8 == 0) {
        BinkMovie_Unload(((void **)movie)[16]);
        fn_80128668(movie);
    }
}

extern void fn_802E13D8(void *);
/* Tail-calls the movie video setup/draw routine fn_802E13D8 with the movie object
 * fn_802E11A4 opened for `record` (the handle stored at record+0x40). */
void fn_802ED038(MoviePlayInfo *record) {
    fn_802E13D8(record->handle);
}

extern void fn_802E1718(void *);
/* Report whether the movie held by the MoviePlayInfo record has finished (video.c helper; currently always 0). */
void fn_802ED040(MoviePlayInfo *record) {
    fn_802E1718(record->handle);
}

