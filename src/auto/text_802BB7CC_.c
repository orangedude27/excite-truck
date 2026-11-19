// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012C33C(void);
int fn_802CAC28(int, int);
/* Destroys/resets a 12-byte object, zeroing its three fields, and frees it when deleting > 0. */
void *fn_802BB7CC(void *self, int deleting) {
    if (self != 0) {
        if (self != 0) {
            *(int *)self = 0;
            *((int *)self + 1) = 0;
            *((int *)self + 2) = 0;
        }
        if (deleting > 0)
            fn_80128668(self);
    }
    return self;
}

void *fn_802BB824(void *object, int shouldDelete) {
    /* Reset the object's three 32-bit fields to 0, then free it when shouldDelete > 0 (deleting-destructor helper). */
    if (object != 0) {
        if (object != 0) {
            *(int *)object = 0;
            *((int *)object + 1) = 0;
            *((int *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

#pragma push
#pragma dont_inline on
int fn_802BB87C(int path) {
    int isReady = 0;
    if (path != 0 && fn_8012C33C() != 0) isReady = 1;
    if (isReady != 0) return fn_802CAC28(path, 0);
    return -2;
}
#pragma pop

void fn_802BB8E4(int *handlePtr) {
    /* Releases the handle if set, then marks it as invalid (-2). */
    int handle = *handlePtr;
    if (handle != -2) {
        fn_802CAC54(handle);
        *handlePtr = -2;
    }
}

int fn_802BB928(int worldX) {
    /* Map a signed world X coordinate to a rounded 9-bit grid index (0..0x1FF):
     * round (worldX + 0x200)/2.  The Y counterpart is fn_802BB93C. */
    return (worldX + 0x200) / 2;
}

short fn_802BB93C(int worldY) {
    /* Map a signed world Y coordinate to a flipped 9-bit (0..0x1FF) grid index:
     * round (worldY + 0x200)/2, then invert about 0x1FF (Y grows downward). */
    unsigned int biased = (unsigned int)worldY + 0x200;
    unsigned int sign = biased >> 31;
    int rounded = (int)sign + (int)biased;
    return (short)(0x1FF - (rounded >> 1));
}

extern int fn_802CAC54(int);
extern int lbl_804C00B0[];
extern int fn_802D9628(short, short, unsigned int);
#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802BB958(short arg0, int arg1, unsigned char *arg2, unsigned char *arg3) {
    int *var_r31;
    short temp_r30;
    int temp_r29;
    int var_r28;
    temp_r30 = fn_802BB928(arg0);
    temp_r29 = fn_802BB93C(arg1);
    var_r31 = lbl_804C00B0;
    var_r28 = 0;
    do {
        int value = *var_r31;
        if (value != 0) {
            unsigned char temp_r4 = *arg2;
            if (temp_r4 != *arg3) {
                unsigned int packed = ((unsigned int)temp_r4 << 24) | ((unsigned int)temp_r4 << 16) |
                                      ((unsigned int)temp_r4 << 8) | temp_r4;
                int a3 = temp_r29;
                int a2 = temp_r30;
                void *a1 = (void *)value;
                ((void (*)(void *, int, int, unsigned int))fn_802D9628)(a1, a2, a3, packed);
            }
        }
        var_r28 += 1;
        var_r31 += 1;
        arg3++;
        arg2++;
    } while (var_r28 < 6);
}

extern void *fn_802B51E4(int, int);
extern void fn_802B52B4(void *);
extern int fn_802B52C0(int, void *);
extern char *strchr(const char *, int);
extern char lbl_8055CF18;
int fn_802BBA08(void *arg0, int arg1) {
    struct Image {
        int width;
        int height;
        int *pixels;
    };
    struct Image *image;
    int *layers;
    int *p;
    int y, x, pix, shift, k;
    char filename[0x80];
    char *dst;
    char *dst2;
    char *src;
    char *dot;
    int n;
    int m;
    char c;
    char d;
    char *name;

    name = (char *)arg0;
    image = (struct Image *)fn_802B51E4(0x200, 0x200);
    if (image != 0) {
        layers = &lbl_804C00B0[arg1];
        for (y = 0; y < 0x200; y++) {
            for (x = 0; x < 0x200; x++) {
                pix = 0;
                p = layers;
                for (k = 0, shift = 0; k < 3; k++, p++, shift += 8) {
                    if (*p != 0) {
                        pix |= ((fn_802D972C((void *)*p, y, x) >> 8) & 0xFF) << shift;
                    }
                }
                image->pixels[(image->height - 1 - x) * image->width + y] = pix;
            }
        }
        dst = filename;
        n = 0x80;
        goto body1;
        for (;;) {
            if (--n <= 0) {
                *--dst = 0;
                break;
            }
body1:
            c = *name++;
            *dst++ = c;
            if (c == 0) break;
        }
        if (strchr(filename, '.') != 0) {
            dot = strchr(filename, '.');
            *dot = 0;
        }
        dst2 = filename;
        m = 0x80;
        src = (char *)&lbl_8055CF18;
        goto scan;
        for (;;) {
            m--;
            dst2++;
scan:
            if (*dst2 == 0) break;
        }
        if (m > 0) {
            goto body2;
            for (;;) {
                if (--m <= 0) {
                    *--dst2 = 0;
                    break;
                }
body2:
                d = *src++;
                *dst2++ = d;
                if (d == 0) break;
            }
        }
        fn_802B52C0((int)filename, image);
        fn_802B52B4(image);
    }
}

#pragma pop
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_802BBBC8(void) {
    #define sLayerPathFmt lbl_8034AAB8
    #define sNoTextureFmt lbl_8034AAC4
    #define sMatMapPrefix lbl_80564CF8
    #define sMatMap2Prefix lbl_80564CFC
    #define sLayerHandles lbl_804C0098
    #define sLayerTextures lbl_804C00B0
    #define sChannelSuffixes lbl_8055CF30
    #define sSoftWaterMapPresent lbl_8055FA90
    #define sFormatPath fn_801345D8
    #define sPanic fn_802E317C
    #define sGetTextureIndex fn_802CA294
    #define sLoadTexture fn_802BB87C
    #define sIsSoftWaterMapPresent fn_802B05E4
    /* Loads the six material-map layers (matmap/matmap2 times b/g/r), saving each
     * layer's file handle and the texture index it maps to, panicking when a layer
     * texture is missing; finally caches the soft-water-map present flag. */
    extern int sMatMapPrefix;
    extern int sMatMap2Prefix;
    extern int sLayerHandles[];
    extern int sLayerTextures[];
    extern signed char sChannelSuffixes;
    extern signed char sSoftWaterMapPresent;
    extern char sLayerPathFmt[];
    extern char sNoTextureFmt[];
    extern void sFormatPath(char *, int, char *, ...);
    extern void sPanic(char *, ...);
    extern int sGetTextureIndex(int);
    extern signed char sIsSoftWaterMapPresent(void);
    char path[0x20];
    int prefixes[2];
    register int *handleOut;
    register int *textureOut;
    register int layer;
    register signed char *suffix;
    int handle;
    int texture;

    prefixes[0] = sMatMapPrefix;
    handleOut = sLayerHandles;
    textureOut = sLayerTextures;
    prefixes[1] = sMatMap2Prefix;
    layer = 0;
    suffix = &sChannelSuffixes;
    for (; layer < 6;) {
        sFormatPath(path, 0x20, sLayerPathFmt, prefixes[layer / 3], suffix[layer % 3]);
        handle = sLoadTexture((int)path);
        *handleOut = handle;
        if (handle == -2) {
            sPanic(sNoTextureFmt, layer);
        }
        handle = *handleOut;
        if (handle == -2) {
            texture = 0;
        } else {
            texture = sGetTextureIndex(handle);
        }
        layer += 1;
        *textureOut = texture;
        handleOut++;
        textureOut++;
    }
    sSoftWaterMapPresent = sIsSoftWaterMapPresent();
    #undef sLayerPathFmt
    #undef sNoTextureFmt
    #undef sMatMapPrefix
    #undef sMatMap2Prefix
    #undef sLayerHandles
    #undef sLayerTextures
    #undef sChannelSuffixes
    #undef sSoftWaterMapPresent
    #undef sFormatPath
    #undef sPanic
    #undef sGetTextureIndex
    #undef sLoadTexture
    #undef sIsSoftWaterMapPresent
}
#pragma pop
#pragma push
#pragma scheduling invalid_target
#pragma inline_depth(0)
void fn_802BBCC4(void) {
    /* Release up to 6 tracked resource handles in lbl_804C0098 and clear their corresponding flags in lbl_804C00B0. */
    extern int lbl_804C0098[];
    extern int lbl_804C00B0[];
    int *handle = lbl_804C0098;
    int *flag = lbl_804C00B0;
    int i = 0;
    do {
        fn_802BB8E4(handle);
        i += 1;
        *flag = 0;
        handle++;
        flag++;
    } while (i < 6);
}

#pragma use_lmw_stmw off
unsigned char fn_802BBD38(int arg0, int arg1, int arg2) {
    extern signed char lbl_8055FA90;
    extern int fn_802D972C(void *, int, int);
    int *slot;
    int value;
    int x;
    short y;
    int x2;
    int y2;
    unsigned char invalid;
    int result;

    if ((unsigned char)lbl_8055FA90 != 0)
        return (unsigned char)(~((arg2 - 1) | (1 - arg2)) >> 31);

    result = 0;
    slot = lbl_804C00B0 + arg2;
    value = *slot;
    if (value != 0) {
        x = fn_802BB928(arg0);
        y = fn_802BB93C(arg1);
        invalid = 0;
        if ((short)x < 0 || (short)x >= 0x200 || y < 0 || y >= 0x200)
            invalid = 1;

        if (invalid == 0) {
            y2 = (short)fn_802BB93C(arg1);
            x2 = (short)fn_802BB928(arg0);
            value = *slot;
            return (unsigned char)(((unsigned int)((int (*)(void *, int, int))fn_802D972C)(
                (void *)value, x2, y2)) >> 8);
        } else {
            result = ~((arg2 - 2) | (2 - arg2)) >> 31;
        }
    }
    return (unsigned char)result;
}
  extern int lbl_804C0098[];
extern void fn_802BB8E4(int*);
extern int fn_802D972C(void *, int, int);
extern int fn_802E30C8(const char*, ...);
extern char lbl_8034AAF0[];
#pragma scheduling invalid_target
#pragma push
#pragma use_lmw_stmw off
void fn_802BBE34(void) {
    #define sBadWeightFmt lbl_8034AAF0
    #define sLayerTextures lbl_804C00B0
    #define sampleTexture fn_802D972C
    #define logMessage fn_802E30C8
    int *texture;
    int x;
    int y;
    unsigned int sum;
    int layer;
    /* Scans every point of the 0x200 x 0x200 lightweight colormap and logs any
     * pixel whose six matmap layers do not add up to 0xFF. */
    for (x = 0; x < 0x200; x++) {
        for (y = 0; y < 0x200; y++) {
            sum = 0;
            for (layer = 0, texture = sLayerTextures; layer < 6; layer++, texture++) {
                if (*texture != 0) {
                    sum += ((unsigned int)((int (*)(void *, int, int))sampleTexture)(
                        (void *)*texture, x, y) >> 8) & 0xFF;
                }
            }
            if (sum != 0xFF) {
                logMessage(sBadWeightFmt, x, y, sum);
            }
        }
    }
    #undef logMessage
    #undef sampleTexture
    #undef sLayerTextures
    #undef sBadWeightFmt
}
#pragma pop
extern int fn_80128690(void);
extern void fn_80128684(void);
extern void fn_80128678(void);
extern int fn_802BBA08(void *, int);
extern int lbl_8055CF20;
extern int lbl_8055CF28;
#pragma push
#pragma scheduling invalid_target
void fn_802BBEE4(void) {
    /* Rebuild cached state, then run two setup passes bracketed by begin/end guards when not enabled. */
    register int savedState;
    register unsigned char isEnabled;

    fn_802BBE34();
    savedState = fn_80128690();
    isEnabled = (unsigned char)savedState;
    if (isEnabled == 0)
        fn_80128684();
    fn_802BBA08(&lbl_8055CF20, 0);
    fn_802BBA08(&lbl_8055CF28, 3);
    isEnabled = (unsigned char)savedState;
    if (isEnabled == 0)
        fn_80128678();
}
#pragma pop
extern const char lbl_8034AB00[];
#pragma push
#pragma scheduling invalid_target
/* Logs when the sum of six channel bytes is not 0xFF. */
void fn_802BBF44(unsigned char *bytes, int channelIndex) {
#define sInvalidChecksumFmt lbl_8034AB00
    register unsigned int byte5;
    register unsigned int byte4;
    register unsigned int byte3;
    register unsigned int byte2;
    register unsigned int byte1;
    register unsigned int byte0;
    unsigned int sum;

    byte0 = bytes[0];
    byte1 = bytes[1];
    byte2 = bytes[2];
    byte3 = bytes[3];
    byte4 = bytes[4];
    byte5 = bytes[5];
    sum = byte0 + byte1;
    sum += byte2;
    sum += byte3;
    sum += byte4;
    sum += byte5;
    if (sum != 0xFF) {
        fn_802E30C8(sInvalidChecksumFmt, byte0, byte1, byte2,
                    byte3, byte4, byte5, channelIndex);
    }
#undef sInvalidChecksumFmt
}
#pragma pop
int fn_802BBF94(unsigned char packedNibble) {
    int highNibble = (packedNibble >> 4) & 0xF;
    /* Expand the high 4-bit nibble into a byte whose two nibbles are equal. */
    return __rlwimi(highNibble, packedNibble, 0, 24, 27);
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma use_lmw_stmw off
/* Normalizes 6 nibble-duplicated bytes and adjusts them so their sum becomes 0xFF. */
void fn_802BBFA4(unsigned char *arg0, int arg1, int arg2, int arg3) {
    register unsigned char *base = arg0;
    register int index = arg1;
    register int skip = arg2;
    register int i = 0;
    register int value0;
    register int value1;
    register int value2;
    register int value3;
    register int value4;
    register int value5;
    register int sum;
    register int j;
    int delta;
    int value;

    do {
        arg0[i] = (unsigned char)fn_802BBF94(arg0[i]);
        i++;
    } while (i < 6);

    value0 = base[0];
    value1 = base[1];
    value2 = base[2];
    value3 = base[3];
    value4 = base[4];
    value5 = base[5];
    sum = value0 + value1;
    sum += value2;
    sum += value3;
    sum += value4;
    sum += value5;
    if (sum != 0xFF) {
        value = base[index];
        delta = sum - 0xFF;
        if (value >= delta) {
            base[index] = value - delta;
            return;
        }
        j = 0;
        while (sum != 0xFF && j < 6) {
            if (j != skip) {
                value = *base;
                delta = sum - 0xFF;
                if (delta < value) {
                    value = delta;
                }
                sum -= value;
                *base -= value;
            }
            j++;
            base++;
        }
    }
}
#pragma pop
extern int fn_802B05DC(void);
extern void *memset(void *, int, unsigned long);
extern float lbl_80564D00;
extern float lbl_80564D04;
extern double lbl_80564D08;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
int fn_802BC09C(short arg0, int arg1, int arg2, signed char arg3, float farg0) {
    unsigned char sp10[6];
    unsigned char sp8[6];
    int cur;
    int x;
    short y;
    int bad;
    int i, k;
    unsigned char base, old;
    unsigned char *d, *s, *w;
    int result;
    result = 0;
    cur = fn_802B05DC();
    if (arg2 != cur) {
        x = fn_802BB928(arg0);
        y = fn_802BB93C(arg1);
        bad = 0;
        if ((short)x < 0 || (short)x >= 0x200 || y < 0 || y >= 0x200) bad = 1;
        if (bad == 0) {
            w = sp10;
            for (i = 0; i < 6; i++) { *w = fn_802BBD38(arg0, arg1, i); w++; }
            if (cur == -1 || sp10[cur] < 0x80) {
                if (cur == -1) base = 0;
                else base = sp10[cur];
                memset(sp8, 0, 6);
                sp8[arg2] = arg3;
                d = sp8;
                s = sp10;
                {
                    int hi = *(int *)&lbl_80564D08;
                    float f, a, b;
                    double ds, dd;
                    for (k = 0; k < 3; k++) {
                        float zero = lbl_80564D00;
                        float half = lbl_80564D04;
                        ((int *)&dd)[0] = hi; ((int *)&dd)[1] = d[0];
                        b = (float)(dd - lbl_80564D08);
                        ((int *)&ds)[0] = hi; ((int *)&ds)[1] = s[0];
                        a = (float)(ds - lbl_80564D08);
                        f = a + farg0 * (b - a);
                        if (f < zero) f = f - half;
                        else f = half + f;
                        d[0] = (unsigned char)(int)f;
                        ((int *)&dd)[0] = hi; ((int *)&dd)[1] = d[1];
                        b = (float)(dd - lbl_80564D08);
                        ((int *)&ds)[0] = hi; ((int *)&ds)[1] = s[1];
                        a = (float)(ds - lbl_80564D08);
                        f = a + farg0 * (b - a);
                        if (f < zero) f = f - half;
                        else f = half + f;
                        d[1] = (unsigned char)(int)f;
                        s += 2;
                        d += 2;
                    }
                }
                if (cur != -1) {
                    old = sp8[cur];
                    sp8[cur] = base;
                    if (old > base) sp8[arg2] = sp8[arg2] - (old - base);
                    else sp8[arg2] = sp8[arg2] - (base - old);
                }
                ((void (*)(unsigned char *, int, int))fn_802BBFA4)(sp8, arg2, cur);
                fn_802BBF44(sp8, arg2);
                fn_802BB958(arg0, arg1, sp8, sp10);
                result = 1;
            }
        }
    }
    return result;
}
#pragma pop
extern int lbl_804C0098[4];
/* Return the stored file handle of material-map layer index from the sLayerHandles table (lbl_804C0098). */
int __AXGetStackHead_802BC30C(int index) { return lbl_804C0098[index]; }
extern int fn_802CAC54(int);
extern int lbl_804C00B0[6];
extern int fn_802D9628(short, short, unsigned int);
