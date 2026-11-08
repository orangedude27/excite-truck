// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct decform {
    char style;
    char pad;
    short digits;
} decform;

typedef struct decimal {
    char sign;
    char unk;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[36];
    } sig;
} decimal;

typedef struct print_format {
    unsigned char flags;
    unsigned char sign_options;
    unsigned char pad2;
    unsigned char alternate_form;
    unsigned char pad4;
    unsigned char conversion_char;
    unsigned char pad6[6];
    int precision;
} print_format;

typedef struct CtypeTable {
    char pad[8];
    unsigned short *map;
} CtypeTable;

typedef struct LocaleData {
    char pad[0x38];
    CtypeTable *ctype;
} LocaleData;

extern char *lbl_802FE6A0;
extern LocaleData lbl_802FE850;

#define MY_ISUPPER(c) (((c) < 0 || (c) >= 256) ? 0 : (lbl_802FE850.ctype->map[(c)] & 0x200))

void __num2dec(const decform *, double, decimal *);
void round_decimal(decimal *, int);
