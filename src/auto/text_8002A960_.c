// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct CtypeCompat {
    int unk0;
    int unk4;
    const unsigned short *ctype_map_ptr;
    const unsigned char *upper_map_ptr;
    const unsigned char *lower_map_ptr;
} CtypeCompat;

typedef struct LocaleCompat {
    char pad[0x38];
    CtypeCompat *ctype_cmpt_ptr;
} LocaleCompat;

extern LocaleCompat lbl_802FE850;

#define strtoull_isspace(c) ((c) < 0 || (c) >= 0x100 ? 0 : (lbl_802FE850.ctype_cmpt_ptr->ctype_map_ptr[(c)] & 0x100))
#define strtoull_isdigit(c) ((c) < 0 || (c) >= 0x100 ? 0 : (lbl_802FE850.ctype_cmpt_ptr->ctype_map_ptr[(c)] & 0x8))
#define strtoull_isalpha(c) ((c) < 0 || (c) >= 0x100 ? 0 : (lbl_802FE850.ctype_cmpt_ptr->ctype_map_ptr[(c)] & 0x1))
#define strtoull_toupper(c) ((c) < 0 || (c) >= 0x100 ? (c) : lbl_802FE850.ctype_cmpt_ptr->upper_map_ptr[(c)])
