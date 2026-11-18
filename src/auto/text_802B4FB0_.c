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
/* Return 1 if an image file header's bits-per-pixel field is a supported depth
 * (0x20 = 32-bit or 0x18 = 24-bit), otherwise 0. */
int fn_802B4FB0(unsigned char bitsPerPixel) {
    int result = 0;
    if (bitsPerPixel == 0x20 || bitsPerPixel == 0x18) {
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
typedef struct { unsigned char pad0[2]; unsigned char kind; unsigned char pad3[9]; unsigned short w; unsigned short h; unsigned char idx; } Fn802B5070Arg;
extern char lbl_8034A4E0[];

#pragma dont_inline on
#pragma scheduling invalid_target
#pragma scheduling on
int fn_802B5070(void *p, int arg1) {
    int result = 0;
    int kind = *(unsigned char *)((char *)p + 2);
    if (kind != 2) goto out;
    if (fn_802B4FB0(*(unsigned char *)((char *)p + 0x10)) == 0) goto out;
    if (arg1 != *(unsigned short *)((char *)p + 0xc) * *(unsigned short *)((char *)p + 0xe)) goto out;
    result = 1;
out:
    return result;
}
extern int fn_802B5070(void *, int);
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
extern int fn_802E3D68(int, int, int);
extern int fn_802E3A64(int, void *, int);
extern void fn_802E30C8(char *, int);
extern char lbl_8034A4EC[];
#pragma push
#pragma scheduling on
int fn_802B52C0(int arg0, const void *arg1) {
    int result = 0;
    int value0;
    int value1;
    int sp8;
    unsigned char spC[0x12];

    memset(spC, 0, 0x12);
    value0 = *(const int *)arg1;
    spC[2] = 2;
    value1 = *(const int *)((const char *)arg1 + 4);
    *(short *)(spC + 0xC) = (short)value0;
    *(short *)(spC + 0xE) = (short)value1;
    spC[0x10] = 0x20;
    sp8 = fn_802E3D68(arg0, value1, value0);
    if (sp8 != -1) {
        fn_802E3A64(sp8, spC, 0x12);
        fn_802E3A64(sp8, *(void * const *)((const char *)arg1 + 8),
                    *(const int *)((const char *)arg1 + 4) * (*(const int *)arg1 * 4));
        fn_802E3734(&sp8);
        result = 1;
    } else {
        ((void (*)(char *, ...))fn_802E30C8)(lbl_8034A4EC, arg0);
    }
    return result;
}
#pragma pop
