// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "ansi_files.h"
#include "buffer_io.h"

int fn_80024A0C(void *);
/* Flush a stream's output buffer; if stream is NULL, flush all open streams. */
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
        position = fn_80024A0C(stream);
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
