// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8029EFF0(int);
extern int fn_802CAC54(int);
extern int RegisterTextureByName(const char *, int);
extern int fn_802E30C8(const char *, ...);
extern int lbl_8055CAE0;
extern char lbl_803497D8[];
extern char lbl_803497E8[];
#pragma scheduling invalid_target
void fn_8029EF70(void) {
#define sLineTextureHandle    lbl_8055CAE0
#define kLineTextureName      lbl_803497D8    /* "efx_line.tex" */
#define kLineTextureError     lbl_803497E8    /* "drawline: Couldn't get the line texture" */
#define loadTexture           RegisterTextureByName
#define isResourceHandleValid fn_8029EFF0
#define debugPrint            fn_802E30C8
    /* Load the line-effect texture handle; log an error if the handle is invalid. */
    sLineTextureHandle = loadTexture(kLineTextureName, 0);
    if (isResourceHandleValid(sLineTextureHandle) == 0) {
        debugPrint(kLineTextureError);
    }
#undef debugPrint
#undef isResourceHandleValid
#undef loadTexture
#undef kLineTextureError
#undef kLineTextureName
#undef sLineTextureHandle
}
#pragma scheduling on

void fn_8029EFBC(void) {
#define sLineTextureHandle    lbl_8055CAE0
#define releaseTexture        fn_802CAC54
#define isResourceHandleValid fn_8029EFF0
    /* Release the line-effect texture, if its handle is still valid. */
    if (isResourceHandleValid(sLineTextureHandle) != 0) {
        releaseTexture(sLineTextureHandle);
    }
#undef isResourceHandleValid
#undef releaseTexture
#undef sLineTextureHandle
}

int fn_8029EFF0(int handle) {
    /* Return 0 for the invalid resource-handle sentinels -1/-2, 1 otherwise. */
    if (handle == -1)
        goto invalid;
    if (handle != -2)
        goto valid;
invalid:
    return 0;
valid:
    return 1;
}
