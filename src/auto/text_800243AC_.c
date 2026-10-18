#include "buffer_io.h"
#include "direct_io.h"
#include "misc_io.h"
#include "wchar_io.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

size_t __fwrite(const void* buffer, size_t size, size_t count, FILE* stream) {
    unsigned char* write_ptr;
    size_t num_bytes, bytes_to_go, bytes_written;
    int always_buffer;
    if (fwide(stream, 0) == 0) fwide(stream, -1);
    bytes_to_go = size * count;
    if (!bytes_to_go || stream->file_state.error || stream->file_mode.file_kind == __closed_file) return 0;
    if (stream->file_mode.file_kind == __console_file) __stdio_atexit();
    always_buffer = !stream->file_mode.binary_io || stream->file_mode.buffer_mode == _IOFBF ||
                    stream->file_mode.buffer_mode == _IOLBF;
    if (stream->file_state.io_state == __neutral && (stream->file_mode.io_mode & __write)) {
        if ((stream->file_mode.io_mode & __append) && _fseek(stream, 0, SEEK_END)) return 0;
        stream->file_state.io_state = __writing;
        __prep_buffer(stream);
    }
    if (stream->file_state.io_state != __writing) { set_error(stream); return 0; }
    write_ptr = (unsigned char*)buffer;
    bytes_written = 0;
    if (bytes_to_go && (stream->buffer_ptr != stream->buffer || always_buffer)) {
        stream->buffer_length = stream->buffer_size - (stream->buffer_ptr - stream->buffer);
        do {
            unsigned char* newline = NULL;
            num_bytes = stream->buffer_length;
            if (num_bytes > bytes_to_go) num_bytes = bytes_to_go;
            if (stream->file_mode.buffer_mode == _IOLBF && num_bytes)
                if ((newline = (unsigned char*)__memrchr(write_ptr, '\n', num_bytes)) != NULL)
                    num_bytes = newline + 1 - write_ptr;
            if (num_bytes) {
                memcpy(stream->buffer_ptr, write_ptr, num_bytes);
                write_ptr += num_bytes;
                bytes_to_go -= num_bytes;
                stream->buffer_ptr += num_bytes;
                stream->buffer_length -= num_bytes;
            }
            if (!stream->buffer_length || newline != NULL || stream->file_mode.buffer_mode == _IONBF) {
                if (__flush_buffer(stream, NULL)) { set_error(stream); bytes_to_go = 0; break; }
            }
            bytes_written += num_bytes;
        } while (bytes_to_go && always_buffer);
    }
    if (bytes_to_go && !always_buffer) {
        unsigned char* save_buffer = stream->buffer;
        size_t save_size = stream->buffer_size;
        stream->buffer = write_ptr;
        stream->buffer_size = bytes_to_go;
        stream->buffer_ptr = write_ptr + bytes_to_go;
        if (__flush_buffer(stream, &num_bytes) != __no_io_error) set_error(stream);
        else bytes_written += num_bytes;
        stream->buffer = save_buffer;
        stream->buffer_size = save_size;
        __prep_buffer(stream);
        stream->buffer_length = 0;
    }
    if (stream->file_mode.buffer_mode != _IOFBF) stream->buffer_length = 0;
    return bytes_written / size;
}
