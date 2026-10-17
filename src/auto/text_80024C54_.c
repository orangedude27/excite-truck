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
