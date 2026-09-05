#include <types.h>
#include <internal/file_io.h>

/* REXE01 uses the compact MSL FILE mode word directly. The file-kind field is
 * bits 7..9 and the orientation field is bits 10..11. */
int fwide(FILE* stream, int mode) {
    u32 file_mode;
    u32 orientation;

    if (stream == 0) {
        return 0;
    }

    file_mode = *(u32*)((u8*)stream + 4);
    if (((file_mode >> 22) & 7) == 0) {
        return 0;
    }

    orientation = (file_mode >> 20) & 3;
    if (orientation == 0) {
        if (mode > 0) {
            file_mode = (file_mode & ~(3 << 20)) | (2 << 20);
            *(u32*)((u8*)stream + 4) = file_mode;
        } else if (mode < 0) {
            file_mode = (file_mode & ~(3 << 20)) | (1 << 20);
            *(u32*)((u8*)stream + 4) = file_mode;
        }
        return mode;
    }

    if (orientation == 1) {
        return -1;
    }
    if (orientation == 2) {
        return 1;
    }

    return mode;
}
