// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "ansi_files.h"
#include "buffer_io.h"

// MSL's fflush calls ftell(); this game links that through the stub at
// 0x80024A0C, which is just `b _ftell`.
#define ftell fn_80024A0C
int fn_80024A0C(void *);
/* MSL fflush(): write a stream's buffered output.  With NULL it flushes every
 * open stream.  A stream that was reading just drops its read buffer; one that
 * was writing has its buffer written and its file position re-read.
 * Returns 0, or -1 if the stream is closed, already in error, or the write
 * failed.  Same source as src/MSL/file_io.c's fflush(). */
int fflush(FILE *stream) {
    int position;

    if (stream == NULL) {
        return __flush_all();
    }

    if (stream->file_state.error != 0 || stream->file_mode.file_kind == __closed_file) {
        return -1;
    }

    if (stream->file_mode.io_mode == __read) {
        return 0;
    }

    if (stream->file_state.io_state >= __rereading) {
        stream->file_state.io_state = __reading;
    }

    if (stream->file_state.io_state == __reading) {
        stream->buffer_length = 0;
    }

    if (stream->file_state.io_state != __writing) {
        stream->file_state.io_state = __neutral;
        return 0;
    }

    if (stream->file_mode.file_kind != __disk_file) {
        position = 0;
    } else {
        position = ftell(stream);
    }

    if (__flush_buffer(stream, 0) != 0) {
        stream->file_state.error = 1;
        stream->buffer_length = 0;
        return -1;
    }

    stream->file_state.io_state = __neutral;
    stream->position = position;
    stream->buffer_length = 0;
    return 0;
}
