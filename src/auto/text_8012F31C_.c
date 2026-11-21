#include "types.h"
#include "string.h"

/* Debug-heap wrappers from text_801281A0_.c (tagged allocations): allocate an
   object ("new"), allocate an array ("new[]"), delete an object, delete an
   array.  The first word of every block holds its heap tag at runtime. */
extern void fn_80128668(void);                    /* delete   */
extern void fn_80128670(s32 block);               /* delete[] */
extern void *fn_801284F8(s32 size, void *tag);    /* new      */
extern s32 fn_8012850C(s32 size, s32 *tag);       /* new[]    */

/* Heap tag strings: cursors are tagged "MemStreamPtr"; stream objects and
   their backing buffers are both tagged "MemStream". */
extern char lbl_8032AFC4[]; /* "MemStreamPtr" */
extern char lbl_8032AFB8[]; /* "MemStream"    */
extern char lbl_8032AFD4[]; /* "MemStream"    */
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
/* Allocate an 8-byte MemStream object tagged "MemStream": store the requested
   buffer size at +4 and allocate the backing buffer (tagged "MemStream") at +0.
   Returns NULL on allocation failure. */
void *fn_8012F31C(s32 bufferSize) {
    MemStream *stream = fn_801284F8(8, lbl_8032AFB8);
    if (stream != 0) {
        stream->size = bufferSize;
        stream->buffer = (u8 *)fn_8012850C(bufferSize, (s32 *)lbl_8032AFD4);
    }
    return stream;
}

#pragma scheduling invalid_target
/* MemStream_Destroy: free a stream's backing buffer (delete[]), clear its
   stored size, then delete the MemStream object itself. */
void fn_8012F384(MemStream *stream) {
    if (stream != 0) {
        fn_80128670((s32)stream->buffer);
        stream->size = 0;
        ((void (*)(void *))fn_80128668)(stream);
    }
}
#pragma scheduling on
/* MemStreamPtr_Create: allocate an 8-byte cursor tagged "MemStreamPtr" for the
   given stream, with its byte position set to 0. */
void fn_8012F3CC(MemStream *stream) {
    MemStreamPtr *cursor = fn_801284F8(8, lbl_8032AFC4);
    if (cursor != 0) { cursor->stream = stream; cursor->pos = 0; }
}
/* MemStreamPtr_Destroy: release a cursor block -- clear its stream pointer,
   stamp the position word with the 0x2bad2bad freed-memory poison, then free
   the block. */
void fn_8012F418(MemStreamPtr *cursor) {
    if (cursor == 0) return;
    cursor->stream = 0;
    cursor->pos = 0x2bad2bad;
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
   position and advances the cursor past them (the block-write twin of the
   word write above). */
void fn_8012F4AC(MemStreamPtr *cursor, const void *src, s32 size) {
    memcpy(cursor->stream->buffer + cursor->pos, src, size);
    cursor->pos += size;
}

/* MemStreamPtr_ReadWord: copy 4 bytes from the cursor's current position into
   dest, then advance the cursor past them. */
void fn_8012F500(MemStreamPtr *cursor, void *dest) {
    MemStream *stream = cursor->stream;
    memcpy(dest, stream->buffer + cursor->pos, 4);
    cursor->pos += 4;
}

void fn_8012F550(MemStreamPtr *cursor, u8 **outPtr, s32 advance) {
    /* Return the address at the cursor's current position in *outPtr, then advance the cursor by `advance` bytes. */
    *outPtr = cursor->stream->buffer + cursor->pos;
    cursor->pos += advance;
}

