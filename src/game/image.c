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
extern int fn_8023512C(char*);
extern int fn_802E30C8(const char*, ...);
extern unsigned int strlen(const char*);
extern char lbl_8034B178[];
extern unsigned char lbl_8055FC14;
#define ROUND_HALF      lbl_80564EE8   /* 0.5f: rounding bias for image dimensions */
#define ZERO_F          lbl_80564EEC   /* 0.0f */
#define WARNED_LONG_NAME lbl_8055FC14  /* set once an overlong image name is reported */
#pragma push
#pragma scheduling invalid_target
int fn_802C5130(char* imageName) {
    /* Get an image handle, but reject names longer than 15 characters (once). */
    if (strlen(imageName) > 15) {
        if (WARNED_LONG_NAME == 0) {
            fn_802E30C8(lbl_8034B178, imageName);
        }
        WARNED_LONG_NAME = 1;
        return 0;
    }
    return fn_8023512C(imageName);
}
#pragma pop
/* Release the referenced art set through fn_80235380 when `artSet` is non-null;
   a null handle is ignored. */
void fn_802C519C(void* artSet) {
    if (artSet == 0) return;
    fn_80235380();
}

/* Returns the number of frames in the image resource set behind @p image
 * (the linked-entry count from fn_80235FD8), or 1 for a null handle. */
int fn_802C51AC(void* image) {
    if (image != 0) return fn_80235FD8();
    return 1;
}

int fn_802C51C0(void* arg0) {
    /* Return the float value of the node (fn_80235EF0, index 0) rounded to
     * the nearest integer, or 1 if the node is null. */
    f32 value;
    f32 rounded;
    if (arg0 != 0) {
        value = ((f32 (*)(void*, int))fn_80235EF0)(arg0, 0);
        if (value < ZERO_F) rounded = value - ROUND_HALF;
        else rounded = ROUND_HALF + value;
        return (int)rounded;
    }
    return 1;
}

extern f32 fn_80235F64(int);
/* Return the image height as an integer, rounding toward zero via a +/-0.5 bias;
 * return 1 for a null image handle. */
int fn_802C5220(void* arg0) {
    f32 value;
    f32 result;
    if (arg0 != 0) {
        value = ((f32 (*)(void*, int))fn_80235F64)(arg0, 0);
        if (value < ZERO_F) result = value - ROUND_HALF;
        else result = ROUND_HALF + value;
        return (int)result;
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
            (x < fn_802C51C0((void*)image)) &&
            (y < fn_802C5220((void*)image))) {
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
/* If the art-set handle is non-null, tail-call the picture-draw wrapper fn_802353F4; a null handle is ignored. */
void fn_802C5310(void* artSet) { if (artSet != 0) fn_802353F4(); }

/* If the image set is non-null, draw picture `picture` with the default tint (-1). */
void fn_802C5320(void* imageSet, void* picture) { if (imageSet != 0) fn_802354A0(imageSet, picture, -1); }

/* Guarded image-draw wrapper: if artSet is non-null, draw picture `pictureIndex`
   as a textured quad with color -1 (use the texture's own tint). The caller's
   third float (unusedZ) is discarded; the rest are forwarded to the drawer. */
void fn_802C5334(void* artSet, int pictureIndex, float x, float y, float unusedZ,
                 float width, float height, float u0, float v0, float u1, float v1) {
    if (artSet != 0)
        ((void (*)(void*, int, int, float, float, float, float, float, float, float, float))fn_80235758)(
            artSet, pictureIndex, -1, x, y, width, height, u0, v0, u1, v1);
}

