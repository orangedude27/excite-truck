#include "MSL/ansi_files.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055D680;
extern int __flush_buffer(FILE *file, size_t *count);
extern long _ftell(FILE *file);
int _fseek(FILE *file, fpos_t offset, int mode) {
    if (file->file_mode.file_kind != __disk_file || file->file_state.error) {
        lbl_8055D680 = 0x28;
        return -1;
    }
    if (file->file_state.io_state == __writing && __flush_buffer(file, 0)) {
        set_error(file);
        lbl_8055D680 = 0x28;
        return -1;
    }
    if (mode == SEEK_CUR) {
        mode = SEEK_SET;
        offset += _ftell(file);
    }
    if (mode != SEEK_END && file->file_mode.io_mode != __read_write &&
        (file->file_state.io_state == __reading || file->file_state.io_state == __rereading)) {
        if (offset >= file->position || offset < file->buffer_position) {
            file->file_state.io_state = __neutral;
        } else {
            file->buffer_ptr = file->buffer + (offset - file->buffer_position);
            file->buffer_length = file->position - offset;
            file->file_state.io_state = 2;
        }
    } else {
        file->file_state.io_state = __neutral;
    }
    if (file->file_state.io_state == __neutral) {
        if (file->position_fn) {
            if (file->position_fn(file->handle, &offset, mode, file->idle_fn)) {
                set_error(file);
                lbl_8055D680 = 0x28;
                return -1;
            }
        }
        file->file_state.eof = 0;
        file->position = offset;
        file->buffer_length = 0;
    }
    return 0;
}
