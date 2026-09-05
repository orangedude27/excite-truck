#include <string.h>
#include <wchar.h>

/* REXE01 MSL multibyte conversion. The active implementation uses the
 * locale codec at lbl_802FE850, rather than the UTF-8 implementation found in
 * later TP MSL sources. */
typedef int (*WctombCallback)(char*, wchar_t);

typedef struct WcLocaleCodec {
    unsigned char unused[0x24];
    WctombCallback convert;
} WcLocaleCodec;

typedef struct WcLocale {
    unsigned char unused[0x38];
    WcLocaleCodec* codec;
} WcLocale;

extern WcLocale lbl_802FE850;

size_t wcstombs(char* dst, const wchar_t* src, size_t limit) {
    char converted[8];
    size_t written = 0;
    const wchar_t* current = src;
    WcLocaleCodec* codec = lbl_802FE850.codec;

    if (dst == 0 || src == 0) {
        return 0;
    }

    while (written <= limit) {
        wchar_t wc = *current++;
        int bytes;

        if (wc == 0) {
            dst[written] = 0;
            break;
        }

        bytes = codec->convert(converted, wc);
        if (written + bytes > limit) {
            break;
        }

        strncpy(dst + written, converted, bytes);
        written += bytes;
    }

    return written;
}
