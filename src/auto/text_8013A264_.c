// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned char u8;
typedef float f32;

/* The seven AI driving values a track section can tune. The names in the comments are the
   keys they are read under in the track's "exception" container (see fn_8013A2FC). */
typedef struct AiParams {
    f32 onT;             /* "on_t": time the driver blends towards these values over */
    f32 moveout;         /* "moveout" */
    f32 passout;         /* "passout" */
    f32 pushSensitivity; /* "push_sensitivity" */
    f32 lookahead;       /* "lookahead_f" */
    f32 checks;          /* "checks" */
    f32 landing;         /* "landing_f" */
} AiParams;

/* One "AIException" entry (0x28 bytes): the parameters to drive with while the car's
   longitudinal track position is between onLon and offLon; entries form a list. */
typedef struct AiException {
    f32 onLon;                /* "on_lon":  start of the section this entry covers */
    f32 offLon;               /* "off_lon": end of the section this entry covers */
    AiParams params;          /* +0x08 */
    struct AiException *next; /* +0x24 */
} AiException;

/* The track's "exception" settings: default parameters plus the parsed AIException list
   (most recently read entry first). */
typedef struct AiExceptionConfig {
    AiException *list; /* +0x00 */
    AiParams params;   /* +0x04 defaults, used when no entry covers the position */
} AiExceptionConfig;

#pragma push
#pragma cplusplus on
struct Entry {
    virtual const char *GetName();
    virtual void _0C();
    virtual void _10();
    virtual void _14();
    virtual void _18();
    virtual void _1C();
    virtual void _20();
    virtual f32 GetFloat(const void *);
    virtual f32 GetFloatDef(const void *, f32);
};

struct Container {
    virtual void _00();
    virtual void _04();
    virtual void _08();
    virtual void _0C();
    virtual void _10();
    virtual void _14();
    virtual void _18();
    virtual void _1C();
    virtual void _20();
    virtual void _24();
    virtual void _28();
    virtual void _2C();
    virtual void _30();
    virtual void _34();
    virtual void _38();
    virtual void _3C();
    virtual void _40();
    virtual void _44();
    virtual void _48();
    virtual void _4C();
    virtual void _50();
    virtual void _54();
    virtual Entry *GetEntry(int);
};
#pragma pop

void *fn_801284F8(unsigned int, const void *);   /* alloc of that size, tagged with this string */
void *fn_80128668();                             /* free */
int stricmp(const char *, const char *);
void fn_802E30C8(const char *, ...);             /* log */
extern f32 lbl_8032C118[]; /* "pushpass_factor", "moveout_factor", "push_sensitivity", "exception",
                               "AIException", "lookahead_f", "landing_f", "ai: track has %d ai-exception%s" */
/* Offsets of those keys in the string block above. */
#define AI_KEY_PUSHPASS_FACTOR  0x00 /* "pushpass_factor" -- read into params.passout */
#define AI_KEY_MOVEOUT_FACTOR   0x10 /* "moveout_factor" */
#define AI_KEY_PUSH_SENSITIVITY 0x20 /* "push_sensitivity" */
#define AI_KEY_EXCEPTION        0x34 /* "exception" -- the entry name the parser accepts */
#define AI_EXCEPTION_TAG        0x40 /* "AIException" -- heap tag the nodes are allocated under */
#define AI_KEY_LOOKAHEAD_F      0x4C /* "lookahead_f" */
#define AI_KEY_LANDING_F        0x58 /* "landing_f" */
#define AI_FMT_EXCEPTIONS       0x68 /* "ai: track has %d ai-exception%s" */

/* The same kind of keys, held in small data instead of that block. */
#define AI_KEY_CHECKS           (&lbl_80559C60) /* "checks" */
#define AI_KEY_ON_LON           (&lbl_80559C68) /* "on_lon" */
#define AI_KEY_OFF_LON          (&lbl_80559C70) /* "off_lon" */
#define AI_KEY_ON_T             (&lbl_80559C78) /* "on_t" */
#define AI_KEY_MOVEOUT          (&lbl_80559C80) /* "moveout" */
#define AI_KEY_PASSOUT          (&lbl_80559C88) /* "passout" */
#define AI_PLURAL_S             (&lbl_80559C90) /* "s" -- for the log message above */
#define AI_PLURAL_NONE          (&lbl_80559C94) /* "" */

extern f32 lbl_80559C60;    /* "checks" -- a key string */
extern char lbl_80559C68;   /* "on_lon" */
extern char lbl_80559C70;   /* "off_lon" */
extern char lbl_80559C78;   /* "on_t" */
extern char lbl_80559C80;   /* "moveout" */
extern char lbl_80559C88;   /* "passout" */
extern char lbl_80559C90;   /* "s" -- plural for the log message above */
extern char lbl_80559C94;   /* "" */
extern f32 lbl_80561418, lbl_8056141C, lbl_80561420; /* default parameter values */
#define AI_DEFAULT_ONE          lbl_80561418 /* 1.0 -- default of every factor */
#define AI_DEFAULT_CHECKS       lbl_8056141C /* 10.0 */
#define AI_DEFAULT_ON_T         lbl_80561420 /* 3.0 */
extern f32 lbl_80561424, lbl_80561428, lbl_8056142C; /* track max, track min and blend time for a section wrapping the end */
#define AI_LON_MAX              lbl_80561424 /* 10000.0 -- end of a wrapping entry's section */
#define AI_LON_MIN              lbl_80561428 /* 0.0 -- start of that section */
#define AI_WRAP_ON_T            lbl_8056142C /* 0.1 -- blend time given to it */
f32 fn_80134B58(f32 *, f32);                     /* value set for this key, or the default */

#pragma push
#pragma scheduling invalid_target
void *fn_8013A264(void *arg0) {
    f32 first = lbl_80561418;
    unsigned int base = (unsigned int)lbl_8032C118;
    *(f32 *)((u8 *)arg0 + 0xC) = fn_80134B58((f32 *)(base + 0), first);
    *(f32 *)((u8 *)arg0 + 8) = fn_80134B58((f32 *)(base + 0x10), lbl_80561418);
    *(f32 *)((u8 *)arg0 + 0x10) = fn_80134B58((f32 *)(base + 0x20), lbl_80561418);
    {
        f32 r4, w, v;
        r4 = fn_80134B58(&lbl_80559C60, lbl_8056141C);
        v = lbl_80561418;
        w = lbl_80561420;
        *(f32 *)((u8 *)arg0 + 0x18) = r4;
        *(f32 *)((u8 *)arg0 + 0x14) = v;
        *(f32 *)((u8 *)arg0 + 0x1C) = v;
        *(f32 *)((u8 *)arg0 + 4) = w;
    }
    *(s32 *)arg0 = 0;
    return arg0;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_8013A2FC(AiExceptionConfig *config, struct Container *container, int i) {
    #pragma scheduling invalid_target
    const char *base = (const char *)lbl_8032C118;
    if (container != 0) {
        f32 step;
        f32 min;
        f32 max;
        struct Entry *entry;

        max = lbl_80561424;
        i = 0;
        min = lbl_80561428;
        step = lbl_8056142C;

        for (; (entry = container->GetEntry(i)) != 0; i++) {
            if (stricmp(entry->GetName(), base + 0x34) == 0) {
                AiException &node = *(AiException *)fn_801284F8(0x28, base + 0x40);
                node.onLon = entry->GetFloat(&lbl_80559C68);
                node.offLon = entry->GetFloat(&lbl_80559C70);
                node.params.onT = entry->GetFloatDef(&lbl_80559C78, config->params.onT);
                node.params.moveout = entry->GetFloatDef(&lbl_80559C80, config->params.moveout);
                node.params.passout = entry->GetFloatDef(&lbl_80559C88, config->params.passout);
                node.params.pushSensitivity = entry->GetFloatDef(base + 0x20, config->params.pushSensitivity);
                node.params.lookahead = entry->GetFloatDef(base + 0x4C, config->params.lookahead);
                node.params.checks = entry->GetFloatDef(&lbl_80559C60, config->params.checks);
                node.params.landing = entry->GetFloatDef(base + 0x58, config->params.landing);
                node.next = config->list;
                config->list = &node;

                if (node.onLon > node.offLon) {
                    AiException *copy = (AiException *)fn_801284F8(0x28, base + 0x40);
                    if (copy != 0) {
                        *copy = node;
                    }
                    node.offLon = max;
                    copy->onLon = min;
                    copy->params.onT = step;
                    copy->next = config->list;
                    config->list = copy;
                }
            }
        }

        fn_802E30C8(base + 0x68, i, (i != 1) ? &lbl_80559C90 : &lbl_80559C94);
    }
}
#pragma pop

/* Frees the AIException list whose head pointer is stored at *listHead (next at +0x24); when
   doDelete > 0 it also frees the head storage itself, i.e. the config the list head lives in. */
void **fn_8013A598(void **listHead, s32 doDelete) {
    if (listHead != 0) {
        while (*listHead != 0) {
            *listHead = *(void **)((u8 *)*listHead + 0x24);
            fn_80128668();
        }
        if (doDelete > 0) fn_80128668(listHead);
    }
    return listHead;
}

/* Returns the AI driving parameters that apply at longitudinal track position `lon`: those of
   the first AIException entry whose [onLon, offLon] section covers it, or, when no entry does,
   the defaults held in the config itself. */
AiParams *fn_8013A604(AiExceptionConfig *config, f32 lon) {
    AiException *node = config->list;
    s32 found;
    while (node != 0) {
        found = 0;
        if (lon >= node->onLon && lon <= node->offLon) found = 1;
        if (found) return &node->params;
        node = node->next;
    }
    return &config->params;
}
