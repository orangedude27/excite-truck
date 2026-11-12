// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef unsigned long size_t;
typedef unsigned short wchar_t;
typedef int (*WctombCallback)(char *, wchar_t);
typedef struct WcLocaleCodec {
    unsigned char unused[0x24];
    WctombCallback convert;
} WcLocaleCodec;
typedef struct WcLocale {
    unsigned char unused[0x38];
    WcLocaleCodec *codec;
} WcLocale;
extern WcLocale lbl_802FE850;
extern char *strncpy(char *, const char *, unsigned long);

size_t wcstombs(char *dest, const wchar_t *src, size_t maxBytes) {
    /* Convert a wide string to multibyte chars via the active locale codec (lbl_802FE850). */
    char converted[8];
    char *locale;
    int charBytes;
    size_t bytesWritten;
    const wchar_t *current;

    bytesWritten = 0;
    if (dest == 0 || src == 0) {
        return 0;
    }
    locale = (char *)&lbl_802FE850;
    current = src;
    while (bytesWritten <= maxBytes) {
        wchar_t wc = *current;
        if (wc == 0) {
            dest[bytesWritten] = 0;
            break;
        }
        current++;
        charBytes = ((WctombCallback)(*(unsigned int *)(*(unsigned int *)(locale + 0x38) + 0x24)))(converted, wc);
        if (bytesWritten + charBytes > maxBytes) {
            break;
        }
        strncpy(dest + bytesWritten, converted, charBytes);
        bytesWritten += charBytes;
    }
    return bytesWritten;
}
