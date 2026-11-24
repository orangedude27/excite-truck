// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_802E3D04(void);
extern int fn_802E39D0(int, void *, int);
extern void fn_802E3734(int *);
extern void fn_80128658(void *);
extern int fn_802B4FD0(void *, int *, int *);
extern void *fn_802B51E4(int, int);
extern int fn_802B50E8(int, int, int);
extern void *fn_801284E8(void *, int);

/* The image files this module reads and writes carry the 18-byte header of an
 * uncompressed true-color TGA (Targa):
 *
 *   0x00  id length            0x08  x origin
 *   0x01  colour-map type      0x0A  y origin
 *   0x02  image type           0x0C  width  (u16)
 *   0x03  colour-map spec      0x0E  height (u16)
 *   0x10  bits per pixel       0x11  image descriptor
 *
 * Only type 2 (true-color, uncompressed) at 24 or 32 bits per pixel is
 * supported; the pixel data follows the header. */
#define TGA_HEADER_SIZE 0x12
#define TGA_IMAGE_TYPE 2   /* only TGA_TYPE_TRUECOLOR is read */
#define TGA_TYPE_TRUECOLOR 2
#define TGA_WIDTH 0xC
#define TGA_HEIGHT 0xE
#define TGA_DEPTH 0x10     /* TGA_DEPTH_24 or TGA_DEPTH_32 */
#define TGA_DEPTH_24 0x18
#define TGA_DEPTH_32 0x20
/* Return 1 if a TGA header's bits-per-pixel field is a supported depth
 * (32-bit or 24-bit), otherwise 0. */
int fn_802B4FB0(unsigned char bitsPerPixel) {
    int result = 0;
    if (bitsPerPixel == TGA_DEPTH_32 || bitsPerPixel == TGA_DEPTH_24) {
        result = 1;
    }
    return result;
}

#pragma dont_inline on
int fn_802B4FD0(void *arg0, int *width, int *height) {
    int result = 0;
    int handle;
    char header[0x12];

    handle = fn_802E3D04();
    if (handle != -1) {
        if (fn_802E39D0(handle, header, 0x12) != 0 &&
            (unsigned char)header[2] == 2 &&
            fn_802B4FB0((unsigned char)header[0x10]) != 0) {
            result = 1;
            *width = *(unsigned short *)(header + 0xC);
            *height = *(unsigned short *)(header + 0xE);
        }
        fn_802E3734(&handle);
    }
    return result;
}
#pragma dont_inline reset
/* Allocation tag "SimpleTGA" used for the image buffers this module allocates. */
extern char lbl_8034A4E0[];
#define sSimpleTga lbl_8034A4E0

#pragma dont_inline on
#pragma scheduling invalid_target
#pragma scheduling on
/* CheckTgaHeader: is `header` an uncompressed true-color TGA that can be read
 * as `pixelCount` pixels?  Its image type must be true-color, its bits-per-
 * pixel one of the supported depths, and its width * height must be exactly
 * `pixelCount`. */
int fn_802B5070(const void *header, int pixelCount) {
    int result = 0;
    if (*(const unsigned char *)((const char *)header + TGA_IMAGE_TYPE) != TGA_TYPE_TRUECOLOR) goto out;
    if (fn_802B4FB0(*(const unsigned char *)((const char *)header + TGA_DEPTH)) == 0) goto out;
    if (pixelCount != *(const unsigned short *)((const char *)header + TGA_WIDTH) * *(const unsigned short *)((const char *)header + TGA_HEIGHT)) goto out;
    result = 1;
out:
    return result;
}
/* Reads a count of values from an open file into output, using 32-bit or 24-bit entries based on the header. */
int fn_802B50E8(int unused, int output, int count) {
    int result = 0;
    int fileHandle;
    char header[0x12];
    int entryValue;
    int index;

    fileHandle = fn_802E3D04();
    if (fileHandle != -1) {
        if (fn_802E39D0(fileHandle, header, 0x12) != 0 &&
            fn_802B5070(header, count) != 0) {
            if ((unsigned char)header[0x10] == 0x20) {
                result = fn_802E39D0(fileHandle, (void *)output, count * 4);
            } else {
                result = 1;
                index = 0;
                while (result != 0 && index < count) {
                    if (fn_802E39D0(fileHandle, &entryValue, 3) != 0) {
                        *(int *)(output + index * 4) = entryValue;
                    } else {
                        result = 0;
                    }
                    index++;
                }
            }
        }
        fn_802E3734(&fileHandle);
    }
    return result;
}

#pragma dont_inline on
/* Allocate a simple 2D buffer (e.g. TGA/image grid) with header: width, height, and pointer to data after header. */
void *fn_802B51E4(int width, int height) {
    int dataBytes = width * height * 4;
    char *buffer = fn_801284E8(lbl_8034A4E0, dataBytes + 0xC);

    *(int *)buffer = width;
    *(int *)(buffer + 4) = height;
    *(void **)(buffer + 8) = buffer + 0xC;
    return buffer;
}
void *fn_802B5240(void *path) {
    /* Open a 2D image (TGA-like) at path, allocate a width/height/pixels buffer,
       read its pixel data into it, and return the buffer (or NULL on failure). */
    int width;
    int height;
    void *image = 0;
    if (fn_802B4FD0(path, &width, &height) != 0) {
        image = fn_802B51E4(width, height);
        fn_802B50E8((int)path, *(int *)((char *)image + 8),
                    *(int *)image * *(int *)((char *)image + 4));
    }
    return image;
}
#pragma scheduling on
void fn_802B52B4(void *image) {
    /* Destroy a 2D image buffer: clear its pixel-data pointer field at +8,
       then release the buffer itself via fn_80128658. */
    *(int *)((char *)image + 8) = 0;
    fn_80128658(image);
}

extern void *memset(void *, int, unsigned int);
extern int FileOpenSecondary(int, int, int);
extern int File_writeExact(int, void *, int);
extern void fn_802E30C8(char *, int);
extern char lbl_8034A4EC[]; /* "save_simple_tga: Can't create \"%s\"" error format */
#define sSaveTgaErr lbl_8034A4EC
#pragma push
#pragma scheduling on
int fn_802B52C0(int filePath, const void *image) {
    int result = 0;
    int width;
    int height;
    int fileHandle;
    unsigned char header[0x12];

    /* Save an image as a simple 32-bit TGA file: build an 18-byte header from
     * the width/height in image, write it and the pixel data, and report
     * success (1) or log an error and return 0 on failure. */
    memset(header, 0, 0x12);
    width = *(const int *)image;
    header[2] = 2;
    height = *(const int *)((const char *)image + 4);
    *(short *)(header + 0xC) = (short)width;
    *(short *)(header + 0xE) = (short)height;
    header[0x10] = 0x20;
    fileHandle = FileOpenSecondary(filePath, height, width);
    if (fileHandle != -1) {
        File_writeExact(fileHandle, header, 0x12);
        File_writeExact(fileHandle, *(void * const *)((const char *)image + 8),
                    *(const int *)((const char *)image + 4) * (*(const int *)image * 4));
        fn_802E3734(&fileHandle);
        result = 1;
    } else {
        ((void (*)(char *, ...))fn_802E30C8)(lbl_8034A4EC, filePath);
    }
    return result;
}
#pragma pop
