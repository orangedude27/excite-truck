// image — image wrapper ("image: gxGetImage(...)").
// Recovered TU window 0x802C5130..0x802C5364+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802C5364 (+ .ctors slot 0x802ED5A0) remains in
// auto/text_802C5364_.c pending a promotion pass.
extern void fn_80235380(void);
extern int fn_80235FD8(void);
typedef float f32;
extern f32 fn_80235EF0(int);
extern f32 lbl_80564EE8;
extern f32 lbl_80564EEC;
extern int ArtSetGet(char*);
extern int fn_802E30C8(const char*, ...);
extern unsigned int strlen(const char*);
extern char gxGetImageLongNameFmt[];
extern unsigned char gxGetImageWarnedLongName;
#define ROUND_HALF      lbl_80564EE8   /* 0.5f: rounding bias for image dimensions */
#define ZERO_F          lbl_80564EEC   /* 0.0f */
#define WARNED_LONG_NAME gxGetImageWarnedLongName  /* set once an overlong image name is reported */
#pragma push
#pragma scheduling invalid_target
int gxGetImageArt(char* imageName) {
    /* Get an image handle, but reject names longer than 15 characters (once). */
    if (strlen(imageName) > 15) {
        if (WARNED_LONG_NAME == 0) {
            fn_802E30C8(gxGetImageLongNameFmt, imageName);
        }
        WARNED_LONG_NAME = 1;
        return 0;
    }
    return ArtSetGet(imageName);
}
#pragma pop
/* Release the referenced art set through fn_80235380 when `artSet` is non-null;
   a null handle is ignored. */
/* Release an image art-set handle when it is non-null; ignore null. */ void fn_802C519C(void* artSet) {
    if (artSet == 0) return;
    fn_80235380();
}

/* Returns the number of frames in the image resource set behind @p image
 * (the linked-entry count from fn_80235FD8), or 1 for a null handle. */
/* Return the frame count of the image/art set behind image, or 1 when image is null. */ int gxGetImageFrameCount(void* image) {
    if (image != 0) return fn_80235FD8();
    return 1;
}

int gxGetImageWidth(void* image) {
    /* Round the image node's float value to the nearest integer, or return 1 for a null handle. */
    f32 imageWidth;
    f32 roundedWidth;
    if (image != 0) {
        imageWidth = ((f32 (*)(void*, int))fn_80235EF0)(image, 0);
        if (imageWidth < ZERO_F) roundedWidth = imageWidth - ROUND_HALF;
        else roundedWidth = ROUND_HALF + imageWidth;
        return (int)roundedWidth;
    }
    return 1;
}

extern f32 fn_80235F64(int);
/* Return the image height as an integer, rounding toward zero via a +/-0.5 bias;
 * return 1 for a null image handle. */
int gxGetImageHeight(void* image) {
    /* Return the image node's float height rounded to the nearest integer, or 1 for a null handle. */
    f32 height;
    f32 roundedHeight;
    if (image != 0) {
        height = ((f32 (*)(void*, int))fn_80235F64)(image, 0);
        if (height < ZERO_F) roundedHeight = height - ROUND_HALF;
        else roundedHeight = ROUND_HALF + height;
        return (int)roundedHeight;
    }
    return 1;
}

#pragma dont_inline on
/* Return nonzero if point (x, y) lies within the image bounds: 0 <= x < width and 0 <= y < height. */ int fn_802C5280(int image, int x, int y) {
    /* Return nonzero if (x,y) lies within the image bounds (0 <= x < width, 0 <= y < height). */
    int inside;

    if (image != 0) {
        inside = 0;
        if ((x >= 0) && (y >= 0) &&
            (x < gxGetImageWidth((void*)image)) &&
            (y < gxGetImageHeight((void*)image))) {
            inside = 1;
        }
    } else {
        inside = 0;
    }
    return inside;
}
#pragma dont_inline reset
extern void fn_802353F4(void);
extern void fn_802354A0(void*, void*, int);
extern void fn_80235758(void*, float, float, float, float, float, float, int);
/* If the art set is non-null, draw its picture at pictureIndex and position (x,y,z); a null handle is ignored. */
void gxDrawPictureAt(void* artSet) { if (artSet != 0) fn_802353F4(); }

/* Draw one picture (frame `picture`) from art set `artSet` with the default
   color/tint -1; the float position/size arguments x,y,z,width,height arrive in
   FPRs and pass through to fn_802354A0 untouched. A null art set is ignored. */
void gxDrawPicture(void* artSet, void* picture) { if (artSet != 0) fn_802354A0(artSet, picture, -1); }

/* Guarded image-draw wrapper: if artSet is non-null, draw picture `pictureIndex`
   as a textured quad with color -1 (use the texture's own tint). The caller's
   third float (unusedZ) is discarded; the rest are forwarded to the drawer. */
/* If artSet is non-null, draw picture `pictureIndex` with color -1 (the texture's own tint), forwarding x/y plus width, height and UVs to fn_80235758. The caller's third float (unusedZ) is dropped and the remaining floats shift down one register. */ void fn_802C5334(void* artSet, int pictureIndex, float x, float y, float unusedZ,
                 float width, float height, float u0, float v0, float u1, float v1) {
    if (artSet != 0)
        ((void (*)(void*, int, int, float, float, float, float, float, float, float, float))fn_80235758)(
            artSet, pictureIndex, -1, x, y, width, height, u0, v0, u1, v1);
}

