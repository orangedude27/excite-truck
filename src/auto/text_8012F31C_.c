#include "types.h"
#include "string.h"
extern void fn_80128668(void);
extern void fn_80128670(s32);
extern void *fn_801284F8(s32, void *);
extern char lbl_8032AFC4[];
extern s32 fn_8012850C(s32, s32 *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8032AFB8[];
extern char lbl_8032AFD4[];
/* A byte buffer of the given size allocated off the heap (heap tag
   "MemStream"); it is the storage a MemStreamPtr cursor reads and writes. */
typedef struct MemStream {
    u8 *buffer; /* 0x00 backing buffer, size bytes */
    s32 size;   /* 0x04 bytes the buffer holds */
} MemStream;

/* A read/write cursor over a MemStream (heap tag "MemStreamPtr"): the Read,
   Write and Seek helpers below work on pos, which they advance by what they
   moved. */
typedef struct MemStreamPtr {
    MemStream *stream; /* 0x00 buffer this cursor reads and writes */
    s32 pos;           /* 0x04 byte offset of the next access */
} MemStreamPtr;
/* Allocate an 8-byte MemStream object tagged "MemStream" (proposed name:
   MemStream_Create): store the requested buffer size at +4 and allocate the
   backing buffer (tagged "MemStream") at +0. Returns NULL on allocation failure. */
void *fn_8012F31C(s32 bufferSize) {
    void *stream = fn_801284F8(8, lbl_8032AFB8);
    if (stream != 0) {
        ((s32 *)stream)[1] = bufferSize;
        ((s32 *)stream)[0] = fn_8012850C(bufferSize, (s32 *)lbl_8032AFD4);
    }
    return stream;
}

#pragma scheduling invalid_target
void fn_8012F384(void *arg0) {
    /* Destroy an object: free its owned resource at +0x0, clear the pointer at +0x4, then delete the object. */
    if (arg0 != 0) {
        fn_80128670(*(s32 *)arg0);
        ((s32 *)arg0)[1] = 0;
        ((void (*)(void *))fn_80128668)(arg0);
    }
}
#pragma scheduling on
/* Create an 8-byte MemStreamPtr (heap tag "MemStreamPtr") and initialize it with the given stream and cursor position 0. */
void fn_8012F3CC(s32 arg0) {
    s32 *streamPtr = (s32 *)fn_801284F8(8, lbl_8032AFC4);
    if (streamPtr != 0) { streamPtr[0] = arg0; streamPtr[1] = 0; }
}
void fn_8012F418(s32 *obj) {
    /* Release an 8-byte tracked heap object (the physics heap block): clear its first word,
       stamp the second with the 0x2bad2bad freed-memory poison, then free the block. */
    if (obj == 0) return;
    obj[0] = 0;
    obj[1] = 0x2bad2bad;
    fn_80128668();
}

/* Rewind a MemStreamPtr cursor to the start of its stream (set its byte position to 0). */
void fn_8012F43C(MemStreamPtr *cursor) {
    cursor->pos = 0;
}

/* Seek a MemStreamPtr cursor: set the byte position of its next access. */
void fn_8012F448(MemStreamPtr *cursor, s32 pos) {
    cursor->pos = pos;
}

/* Return the current byte position (pos) of a MemStreamPtr cursor. */
s32 fn_8012F450(MemStreamPtr *cursor) {
    return cursor->pos;
}

/* Appends a 32-bit word to the stream at its cursor and advances the cursor
   past it (MemStreamPtr write). */
void fn_8012F458(MemStreamPtr *stream, s32 word) {
    s32 data = word;
    memcpy(stream->stream->buffer + stream->pos, &data, 4);
    stream->pos += 4;
}

/* Copies size bytes from src into the stream's buffer at the cursor's
   position and advances the cursor past them (proposed name:
   MemStreamPtr_Write, the block-write twin of fn_8012F458's word write). */
void fn_8012F4AC(MemStreamPtr *cursor, const void *src, s32 size) {
    memcpy(cursor->stream->buffer + cursor->pos, src, size);
    cursor->pos += size;
}

/* Read 4 bytes from the cursor's current position into dest and advance the cursor. */
void fn_8012F500(void *cursor, s32 dest) {
    s32 *bufferPtr = *(s32 **)cursor;
    memcpy((u8 *)dest, (u8 *)*bufferPtr + ((s32 *)cursor)[1], 4);
    ((s32 *)cursor)[1] += 4;
}

void fn_8012F550(MemStreamPtr *cursor, u8 **outPtr, s32 advance) {
    /* Return the address at the cursor's current position in *outPtr, then advance the cursor by `advance` bytes. */
    *outPtr = cursor->stream->buffer + cursor->pos;
    cursor->pos += advance;
}

