#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#pragma cplusplus on
extern "C" f32 fn_8016FD58(void);
extern "C" void fn_8016FD60(void *,void *);
extern "C" void fn_8016FD9C(const f32 *,void *);

extern "C" s32 fn_80141FA0(void);
extern "C" void fn_80142B60(s32);
extern "C" f32 fn_80144BD8(f32);
extern "C" f32 fn_80144C80(f32, f32, f32);
extern "C" void fn_80147230(void *, const void *, ...);
extern "C" void fn_801476C4(void *);
extern "C" void fn_80147940(void *, void *, const void *, s32);
extern "C" void fn_8014C72C(void *, const void *);
extern "C" f32 fn_8014C8B4(f32, f32, f32, f32, f32);
extern "C" void fn_8014C920(void *, void *);

extern "C" s32 fn_802C9A58(void);
extern "C" char lbl_8055A264;
extern "C" f32 lbl_805619B0,lbl_805619B4,lbl_805619C8,lbl_805619CC,lbl_805619D0,lbl_805619D4,lbl_805619D8,lbl_805619DC,lbl_805619E0,lbl_805619E4,lbl_805619E8,lbl_805619EC,lbl_805619F0,lbl_805619F4,lbl_805619F8,lbl_805619FC,lbl_80561A00,lbl_80561A04,lbl_80561A08;

#pragma cplusplus reset
#pragma ppc_psq_save off
#pragma cplusplus on
extern "C" char lbl_80330A90[];
extern "C" void fn_80128670(s32);
extern "C" void releaseValueFile(s32);
extern "C" void fn_80235380(void *, char *);
extern "C" void fn_802C2930(void *, s32);
extern "C" void *fn_8000AC38(void);
extern "C" void *fn_80131810(void);
extern "C" s32 countAvailableRingSets(void);
extern "C" void fn_8016C55C(void *, void *);
extern "C" void *fn_8016C598(void *, int, int);
extern "C" s8 fn_8016C768(void *, void *, void *);
extern "C" s32 fn_8016CD4C(void *);
extern "C" void *fn_8016CD68(void *, s32, s32);
extern "C" s32 fn_8016CDF8(void *, void *);
extern "C" void fn_8016CE94(void *, f32);
extern "C" int fn_8016C760(void *);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" f32 lbl_8056199C;
#pragma cplusplus reset
typedef struct PtrVec { void **data; s32 count; } PtrVec;
extern s32 fn_801284F8(s32, const char *);
extern char lbl_80330A90[];
extern void fn_80144504(void **);
extern void *fn_8016CEC0(void *, s32);
extern void fn_8016CEFC(void *);
extern void *fn_8016CF08(void *);
extern void *constructRingSetController(void *);
extern void fn_8016D278(void *);
extern void **fn_8016CE9C(void *, void **);
extern void fn_8016A0B0(void);
extern void fn_8016C328(void *);
extern s32 fn_80207848(void *, s32);
extern char lbl_80330990[];
extern s32 lbl_8055E378;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 fn_80161C38(void);
extern s32 fn_801B8514(void);
extern u8 *fn_80131234(const char *);
extern s32 fn_801609C4(s32);
int fn_8012850C(int, int);
extern char lbl_80330B7C[];
extern char lbl_80330B8C[];
extern char lbl_8055A248;
extern char lbl_8055A268;
extern void fn_80130978(void *, s32, f32);
extern void fn_8014784C(void *, const char *, const char *, s32);
extern void fn_801475D0(void *, const char *, const char *, ...);
extern void fn_8016A438(void);
extern char lbl_8033072C[];
extern char lbl_803308A0[];
extern f32 lbl_80561980;
extern f32 lbl_80561998;
extern f32 lbl_805619A0;
extern f32 lbl_805619A4;
extern void fn_802AE0E0(s32);
extern char lbl_80330AEC[];
/* Label-key table for the Crush-mode results overlay: HUD text nodes and
   info panels are looked up by the scene manager using offsets into this. */
extern char lbl_803306D0[];
extern void fn_801345D8(void *, s32, const char *, ...);
extern void Abend_Panic(const char *, ...);
extern void fn_8001B450(s32);
typedef struct { f32 first; f32 second; } FloatPair8016A6B0;
extern FloatPair8016A6B0 fn_8016A6B0(const char *, s32);
extern s32 fn_8001B308(void *, s32, s32);
extern void fn_8016A15C(char *);
extern void fn_802BAF98(void *, s8);
void *fn_80128668(void *);
void fn_802C6CF8(int);
extern s32 fn_8002F6AC(void *);
extern void *fn_80128668(void *);
extern s32 fn_8002F37C(void *, void *, s32, s32);
extern void fn_8016B4FC(void *);
extern s32 fn_802BAA68(s32, void *);
extern void fn_8016CDE0(void *);
extern void *fn_8016C168(void *, s32);
extern void *fn_8016C29C(void *, int);
extern int fn_8016C25C(int, int);
extern f32 lbl_80561984;
extern int fn_8000DA10();
typedef struct { s32 w[12]; } Blk8016C768;
// A fixed array of same-sized entries, built by fn_8016CD68/fn_8016C768: the
// entries come from fn_8012850C(count * entrySize + 0x10) and the runtime's
// array constructor fn_8002F37C, which returns the first entry (0x10 past the
// array header it keeps there).  data/data2 both hold that pointer, count is
// how many entries there are and index is the next entry to hand out;
// fn_8016CD4C/fn_8016C55C return entry index and advance it, fn_8016C760 reads
// the index back as how many entries were filled in.
typedef struct { s32 data; s32 index; s32 count; s32 data2; } List8016C768;
#pragma cplusplus on
class UiLayout8016 { public: virtual void d0(); virtual void *lookup(const void *); virtual void d4(); virtual void *lookupDraw(const void *); };
#pragma cplusplus reset
typedef struct UiDraw8016 { u32 unk; f32 x, y, z, width, height; u32 color; } UiDraw8016;
typedef struct UiText8016 { u32 unk; f32 x, y, z, width, height; u32 color; u32 extra; } UiText8016;
#define VT(obj, off) (*(void ***)(obj))[(off) / 4]
#define VFN(obj, off, ret, args) ((ret (*) args)VT(obj, off))
extern int stricmp(const char *, const char *);
extern int strcmp(const char *, const char *);
extern char lbl_8055A228, lbl_8055A230, lbl_8055A238, lbl_8055A240;
extern s32 fn_802C6FC0();
/* Bring one of the controller's sound effects back to full scale: the 1.0f at
 * +8 (one of the two scales fn_802065F8 initialises a sound object with) and
 * the "changed" byte at +0x4D that makes the sound library pick it up. */
static inline void SetNodeF8(void *node) {
    if (node != 0) {
        f32 value = lbl_80561984;
        if (value != *(f32 *)((u8 *)node + 8)) {
            *(u8 *)((u8 *)node + 0x4D) = 1;
            *(f32 *)((u8 *)node + 8) = value;
        }
    }
}
#pragma cplusplus on
extern "C" void releaseValueFile(s32);
class TObj4C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual int d7();
          virtual int d8(); virtual int d9(); virtual void d10(); virtual void d11();
    virtual f32 d12(); virtual void d13(); virtual f32 d14(); virtual void d15();
    virtual void d16();
    virtual void v4C();
};
#pragma cplusplus reset
/* Destroy/clear this object: run element destructor on owned array, reset fields, and optionally delete. */
void *fn_8016B79C(void *obj, s32 deleteFlag) {
    if (obj != 0) {
        s32 ownedArray = *(s32 *)((u8 *)obj + 0x10);
        if (ownedArray != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(ownedArray, fn_8016B4FC);
            *(s32 *)((u8 *)obj + 0x10) = 0;
            *(s32 *)((u8 *)obj + 0x14) = 0;
            *(s32 *)obj = 0;
            *((s32 *)obj + 1) = 0;
            *((s32 *)obj + 2) = 0;
        }
        if (obj != 0) {
            *(s32 *)obj = 0;
            *((s32 *)obj + 1) = 0;
            *((s32 *)obj + 2) = 0;
        }
        if (deleteFlag > 0) fn_80128668(obj);
    }
    return obj;
}

extern void fn_8016B550(void *);
// Global container object (lbl_804302E0+0x28): owns a dynamic array of elements.
typedef struct {
    void *data;   // 0x0
    s32 count;    // 0x4
    s32 limit;    // 0x8
    s32 pad0c;    // 0xc
    void *array;  // 0x10 owned array of elements
    s32 cap;      // 0x14
} ObjArray;
void *fn_8016B834(void *arg0, s32 arg1) {
    /* Deleting destructor for the global container object at lbl_804302E0+0x28:
       destroys its owned element array (element destructor fn_8016B550 via the
       runtime array-delete fn_8002F6AC), clears the container fields, and frees
       the object itself when arg1 > 0. */
    if (arg0 != 0) {
        ObjArray *obj = (ObjArray *)arg0;
        s32 ownedArray = (s32)obj->array;
        if (ownedArray != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(ownedArray, fn_8016B550);
            obj->array = 0;
            obj->cap = 0;
            obj->data = 0;
            obj->count = 0;
            obj->limit = 0;
        }
        if (arg0 != 0) {
            obj->data = 0;
            obj->count = 0;
            obj->limit = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern void fn_8016AC24(void *);
void *fn_8016B8CC(void *obj, s32 shouldDelete) {
    /* Destroy/clear this object: run element destructor on owned array, reset fields, and optionally delete. */
    if (obj != 0) {
        s32 ownedArray = *(s32 *)((u8 *)obj + 0x10);
        if (ownedArray != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(ownedArray, fn_8016AC24);
            *(s32 *)((u8 *)obj + 0x10) = 0;
            *(s32 *)((u8 *)obj + 0x14) = 0;
            *(s32 *)obj = 0;
            *((s32 *)obj + 1) = 0;
            *((s32 *)obj + 2) = 0;
        }
        if (obj != 0) {
            *(s32 *)obj = 0;
            *((s32 *)obj + 1) = 0;
            *((s32 *)obj + 2) = 0;
        }
        if (shouldDelete > 0) fn_80128668(obj);
    }
    return obj;
}

#pragma cplusplus on
extern "C" s32 strlen(const char *);
extern "C" void fn_801308F4(void *, s32, s32);
extern "C" void fn_80130980(void *, s32, s32, f32);
extern "C" void fn_801312EC(void *, void *);
extern "C" void fn_80131318();
extern "C" void fn_802ADFF4(s32, s32);
extern "C" void fn_802AE02C(s32, s32);
extern "C" void fn_802AE0B8(s32, s32);
extern "C" void fn_802AE168(s32);
extern "C" u8 *__AXGetStackHead(void);
extern "C" u8 lbl_8055A208;               /* "%d" */
extern "C" u8 lbl_8055A20C, lbl_8055A210; /* "" and "-" */
extern "C" u32 lbl_8055E044;              /* message table stamp */
extern "C" u8 lbl_8055E374;               /* the time-bonus caption key has been cached */
extern "C" f32 lbl_8055E3C8, lbl_80561984, lbl_80561988; /* game time, 1.0f (count-up length), 0.5f */
extern "C" f64 lbl_80561990;              /* 4503599627370496.0: float->int conversion bias */
extern "C" u8 lbl_8043036C[];             /* the CachedMessage8016B964 holding the caption */

/* A Sound object (created by fn_80207848). Its update (Sound3D_update) acts on the
   request flags below and keeps +0x19 set while the sound is running, so callers
   ask for a sound by testing +0x19 and then setting +0x49. */
typedef struct Sound8016B964 {
    char pad19[0x19];
    unsigned char active;     /* +0x19: kept set while the sound is running */
    char pad1A[0x49 - 0x1A];
    unsigned char play;       /* +0x49: play request, cleared by the update */
    unsigned char stop;       /* +0x4A: stop request */
    unsigned char loop;       /* +0x4B: play mode: loop rather than play once */
    unsigned char stopOnce;   /* +0x4C: stop when the current play ends */
} Sound8016B964;

/* A message key with the text it resolved to, cached until the message table
   changes (lbl_8055E044): fn_801312EC stores the key, fn_80131318 resolves it
   and stamps the current table, fn_80131234 looks a key up. */
typedef struct CachedMessage8016B964 {
    const char *key;          /* +0x00 */
    char *text;               /* +0x04 */
    unsigned int tag;         /* +0x08: the table stamp, ~it while unresolved */
} CachedMessage8016B964;

/* One round's results state, carried at +0xAC of the "ringchalmaster" object and
   laid out exactly like the crush-mode CrushRoundState (updateCrushRoundResults).  The ten
   text cells are the results overlay's fields; updateRingChallengeResults refills them. */
typedef struct CrushRoundState8016B964 {
    int state;                    /* +0x00: 0 idle, 1 running, 2 ended, 4 scored */
    float time;                   /* +0x04: game time the round began */
    unsigned char active;         /* +0x08 */
    unsigned char flag9;          /* +0x09: resume the results animation */
    char padA[2];
    void **animPlayer;            /* +0x0C: DSA player holding the round's cues */
    unsigned char flag10;         /* +0x10: hide the time-bonus text */
    char pad11[3];
    Sound8016B964 *sound14; Sound8016B964 *sound18; Sound8016B964 *sound1C;
    unsigned char flag20;         /* +0x20: the +0x1C sound has been asked for */
    char pad21[3];
    Sound8016B964 *sound24; Sound8016B964 *sound28; Sound8016B964 *sound2C;
    char bonusText[0x14];         /* +0x30: bonus score, comma grouped */
    char countText[0x14];         /* +0x44: time bonus counting up, "%d" */
    char captionText[0x14];       /* +0x58: ResultsOverlay:TIME_BONUS_CAPS */
    char totalText[0x14];         /* +0x6C: total score, comma grouped */
    char rankText[0xA];           /* +0x80: grade letter, "-" when unranked */
    char scoreText[0x14];         /* +0x8A: score without the time bonus */
    char timeText[0x14];          /* +0x9E: time bonus left, as a clock */
    char textB2[0x14];            /* +0xB2 */
    char textC6[0x14];            /* +0xC6 */
    char textDA[0x14];            /* +0xDA: non-empty picks sound2C over sound28 */
    char padEE[6];
    int animIndex;                /* +0xF4: the round's cue in the animation player */
    int counters[4];              /* +0xF8: cue flags: abort, step, pause, finish */
} CrushRoundState8016B964;
#pragma scheduling invalid_target
/* Refill the ring-challenge results overlay's text cells (bonus, counting time bonus, caption, totals and grade) and step the round's animation/sound state machine. */ extern "C" void updateRingChallengeResults(CrushRoundState8016B964 *round, s32 totalScore, s32 bonusScore, s32 timeBonus) {
    /* Refills the results overlay's text cells (bonus, the time bonus counting up,
       its caption, total, score without the time bonus, time left and the grade)
       and steps the round's animation and sound state machine.  Same shape as the
       crush-mode twin updateCrushRoundResults, for the round state carried at +0xAC here. */
    f32 startTime, gameTime, sinceStart, elapsed, progress;
    s32 left, counted, state;
    u8 byte;
    /* the five text copies below each walk their own cursor */
    u8 *emptySrc;
    int timeRoom;
    u8 *timeDst;
    u8 *emptySrc2;
    int captionRoom;
    u8 *captionDst;
    u8 *captionMsg;
    int captionRoom2;
    u8 *captionDst2;
    u8 *rankText;
    int rankRoom;
    u8 *rankDst;
    u8 *dashSrc;
    int dashRoom;
    u8 *dashDst;

    if (round->animPlayer == 0) return;
    ((void (*)(void *, s32))fn_801308F4)(round->bonusText, 0x14);
    /* Count the time bonus up from zero over the second after the round began;
       what is still to be added shows as a clock beside it. */
    left = timeBonus;
    counted = 0;
    if (timeBonus != 0) {
        startTime = round->time;
        if (startTime > lbl_80561980) {
            gameTime = lbl_8055E3C8;
            progress = lbl_80561984;
            sinceStart = gameTime - startTime;
            elapsed = sinceStart - lbl_80561980;
            elapsed = elapsed / progress;
            progress = (progress < elapsed) ? progress : elapsed;
            progress = (progress > lbl_80561980) ? progress : lbl_80561980;
            counted = (s32)(lbl_80561980 + (progress * ((lbl_80561988 + (f32)timeBonus) - lbl_80561980)));
            left = timeBonus - counted;
        }
    }
    ((void (*)(void *, s32, const void *, ...))fn_801345D8)(round->countText, 0x14, &lbl_8055A208, counted);
    if ((s8)lbl_8055E374 == 0) {
        fn_801312EC(lbl_8043036C, lbl_803306D0);
        lbl_8055E374 = 1;
    }
    if (round->flag10 != 0) {
        /* time bonus hidden: blank the clock and the caption */
        timeDst = (u8 *)round->timeText; emptySrc = &lbl_8055A20C; timeRoom = 0x14;
        goto clearTime;
        for (;;) {
            if (--timeRoom <= 0) { timeDst[-1] = 0; break; }
        clearTime:
            byte = *emptySrc++;
            *timeDst++ = byte;
            if ((s8)byte == 0) break;
        }
        captionDst = (u8 *)round->captionText; emptySrc2 = &lbl_8055A20C; captionRoom = 0x14;
        goto clearCaption;
        for (;;) {
            if (--captionRoom <= 0) { captionDst[-1] = 0; break; }
        clearCaption:
            byte = *emptySrc2++;
            *captionDst++ = byte;
            if ((s8)byte == 0) break;
        }
    } else {
        fn_80130980(round->timeText, 0x14, 2, (f32)left);
        /* the caption is the text a message key resolved to, re-resolved when the
           message table changed under the cache */
        if (((CachedMessage8016B964 *)lbl_8043036C)->tag != lbl_8055E044) ((void (*)(void *))fn_80131318)(lbl_8043036C);
        captionMsg = (u8 *)((CachedMessage8016B964 *)lbl_8043036C)->text;
        captionDst2 = (u8 *)round->captionText; captionRoom2 = 0x14;
        goto copyCaption;
        for (;;) {
            if (--captionRoom2 <= 0) { captionDst2[-1] = 0; break; }
        copyCaption:
            byte = *captionMsg++;
            *captionDst2++ = byte;
            if ((s8)byte == 0) break;
        }
    }
    fn_801308F4(round->totalText, 0x14, totalScore);
    fn_801308F4(round->scoreText, 0x14, totalScore - timeBonus);
    if (fn_801609C4(totalScore) != -1) {
        /* the grade for this score, as the ranking helper left it */
        rankText = __AXGetStackHead();
        rankDst = (u8 *)round->rankText; rankRoom = 0xA;
        goto copyRank;
        for (;;) {
            if (--rankRoom <= 0) { rankDst[-1] = 0; break; }
        copyRank:
            byte = *rankText++;
            *rankDst++ = byte;
            if ((s8)byte == 0) break;
        }
    } else {
        dashDst = (u8 *)round->rankText; dashSrc = &lbl_8055A210; dashRoom = 0xA;
        goto noRank;
        for (;;) {
            if (--dashRoom <= 0) { dashDst[-1] = 0; break; }
        noRank:
            byte = *dashSrc++;
            *dashDst++ = byte;
            if ((s8)byte == 0) break;
        }
    }
    if (round->counters[0] != 0) round->active = 0;
    state = round->state;
    switch (state) {
    case 4:
        break;
    case 0:
        /* start the round's cue, ask for the jingle that fits the result, and
           for the time-bonus jingle only when there was one to count up */
        fn_802ADFF4((s32)round->animPlayer, round->animIndex);
        if (strlen(round->textDA) != 0) {
            Sound8016B964 *sound = round->sound2C;
            if (sound != 0 && sound->active == 0) {
                sound->play = 1; sound->loop = 0; sound->stop = 0;
            }
        } else {
            Sound8016B964 *sound = round->sound28;
            if (sound != 0 && sound->active == 0) {
                sound->play = 1; sound->loop = 0; sound->stop = 0;
            }
        }
        if (timeBonus > 0) {
            Sound8016B964 *sound = round->sound14;
            if (sound != 0) { sound->play = 1; sound->loop = 0; sound->stop = 0; }
        } else {
            Sound8016B964 *sound = round->sound18;
            if (sound != 0) { sound->play = 1; sound->loop = 0; sound->stop = 0; }
        }
        round->state = 1;
        break;
    case 1:
        if (round->counters[1] != 0 && round->time < lbl_80561980)
            round->time = lbl_8055E3C8;
        if (round->counters[1] == 2 && round->flag20 == 0) {
            Sound8016B964 *sound = round->sound1C; round->flag20 = 1;
            if (sound != 0) { sound->play = 1; sound->loop = 0; sound->stop = 0; }
        }
        if (round->counters[2] != 0) {
            fn_802AE02C((s32)round->animPlayer, round->animIndex); round->state = 2;
        }
        break;
    case 2:
        if (round->flag9 != 0) {
            fn_802AE0B8((s32)round->animPlayer, round->animIndex);
            Sound8016B964 *sound = round->sound24;
            if (sound != 0) { sound->play = 1; sound->loop = 0; sound->stop = 0; }
            round->state = 3;
        }
        break;
    case 3:
        if (round->counters[3] != 0) {
            fn_802AE02C((s32)round->animPlayer, round->animIndex); round->state = 4;
        }
        break;
    }
    fn_802AE168((s32)round->animPlayer);
}
#pragma scheduling on

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void *fn_8016BE60(void *setup) {
    /* Build the 0x1B4-byte RingChallengeMaster singleton (lbl_8055E378): allocate
     * it, install its vtable and sub-objects, add one "playerdata" entry per slot
     * in setup's count, then initialize the region/difficulty fields and the
     * "chal_prerace.sfx" sound. */
    u8 *master = (u8 *)fn_801284F8(0x1B4, lbl_803306D0 + 0x20);
    char *strings = lbl_803306D0;
    if (master != 0) {
        fn_80144504((void **)master);
        *(void **)master = lbl_80330990;
        fn_8016D278(master + 4);
        constructRingSetController(master + 0x30);
        fn_8016CF08(master + 0xAC);
        lbl_8055E378 = (s32)master;
        fn_8016CEFC(master + 4);
        for (s32 entryIndex = 0; entryIndex < *(s32 *)((u8 *)setup + 0x3E0); entryIndex++) {
            void *newEntry = (void *)fn_801284F8(0x10, strings + 0x30);
            if (newEntry != 0) newEntry = fn_8016CEC0(newEntry, entryIndex);
            void *entry = newEntry;
            fn_8016CE9C(master + 4, &entry);
        }
        fn_8016A0B0();
        fn_8016C328(master + 0x30);
        *(s32 *)(master + 0x98) = 0;
        *(u8 *)(master + 0x9C) = 1;
        *(f32 *)(master + 0xA0) = -100.0f;
        *(s32 *)(master + 0xA4) = fn_80207848(strings + 0x3C, 1);
        *(u8 *)(master + 0xA8) = 0;
    }
    return master;
}

#pragma cplusplus on
#pragma cplusplus reset
#pragma scheduling on
#pragma cplusplus on
/* Destroys the ring-challenge controller, releasing its sounds, lists, art set and obstacle table, then unlinking and optionally freeing it. */ extern "C" void *destroyRingChallengeController(void *controller, s32 shouldFree) {
    /* The seven sounds the controller owns all answer to this: destroy(flag),
     * their vtable's first slot (+8), frees the sound when flag > 0. */
    class Sound { public: virtual void destroy(int); };
    /* The ring-challenge controller constructRingSetController builds at +0x30 of the
     * RingChallengeMaster (lbl_8055E378); only the fields used here. */
    struct Controller {
        /* 0x00 */ void *unk_00;
        /* 0x04 */ void *vtable;         /* lbl_80330A90 */
        /* 0x08 */ u8 pad_08[0x0C];
        /* 0x14 */ void *obstacleTable;  /* "race.res/obstacle.val" */
        /* 0x18 */ void *ringSetList;    /* { entries, count, flag, objects } */
        /* 0x1C */ void *gemList;        /* the same shape */
        /* 0x20 */ void *gemArtSet;      /* "mapgems.art" */
        /* 0x24 */ u8 pad_24[0x28];
        /* 0x4C */ Sound *sfxRingHit;    /* "ringhit.sfx" */
        /* 0x50 */ Sound *sfxCheerHit;   /* "cheerhit.sfx" */
        /* 0x54 */ Sound *sfxLongCheer;  /* "longcheer.sfx" */
        /* 0x58 */ Sound *sfxRingTally;  /* "rctally.sfx" */
        /* 0x5C */ Sound *sfxMissFlag;   /* "missflag.sfx" */
        /* 0x60 */ Sound *sfxLevelUp;    /* "levelup.sfx" */
        /* 0x64 */ Sound *sfxFail;       /* "rcfail.sfx" */
    };
    Sound *sound;
    void *list;
    register void *object = controller;
    register s32 freeFlag = shouldFree;
    Controller *self = (Controller *)object;

    /* Destructor of the ring-challenge controller (vtable lbl_80330A90, third
     * slot): gives back the "mapgems.art" set, destroys the seven sound effects,
     * frees the ring-set and gem lists -- the ring-set list's per-set objects
     * first running their destructor fn_8016C168 -- releases the obstacle table,
     * unlinks the object from the dispatch list and, with freeFlag > 0, frees
     * the object itself. */
    if (object != 0) {
        self->vtable = lbl_80330A90; /* back to this class's own vtable */
        /* fn_80235380 only reads the set; the vtable rides along in r4. */
        fn_80235380(self->gemArtSet, lbl_80330A90);
        sound = self->sfxRingHit;
        if (sound != 0) { if (sound != 0) sound->destroy(1); }
        sound = self->sfxLongCheer;
        if (sound != 0) { if (sound != 0) sound->destroy(1); }
        sound = self->sfxRingTally;
        if (sound != 0) { if (sound != 0) sound->destroy(1); }
        sound = self->sfxCheerHit;
        if (sound != 0) { if (sound != 0) sound->destroy(1); }
        sound = self->sfxMissFlag;
        if (sound != 0) { if (sound != 0) sound->destroy(1); }
        sound = self->sfxLevelUp;
        if (sound != 0) { if (sound != 0) sound->destroy(1); }
        sound = self->sfxFail;
        if (sound != 0) { if (sound != 0) sound->destroy(1); }
        /* the ring-set list: destroy its per-set objects, then the record */
        list = self->ringSetList;
        if (list != 0) {
            ((s32 (*)(s32, void *))fn_8002F6AC)(*(s32 *)((u8 *)list + 0xC), fn_8016C168);
            if (list != 0) { /* entries, count and flag of the record */
                *(s32 *)list = 0;
                *((s32 *)list + 1) = 0;
                *((s32 *)list + 2) = 0;
            }
            fn_80128668(list);
        }
        /* the gem list, whose array is freed without element destructors */
        list = self->gemList;
        if (list != 0) {
            fn_80128670(*(s32 *)((u8 *)list + 0xC));
            if (list != 0) {
                *(s32 *)list = 0;
                *((s32 *)list + 1) = 0;
                *((s32 *)list + 2) = 0;
            }
            fn_80128668(list);
        }
        /* the original tests the field's address, which is never null */
        if ((u32)object + 0x14 != 0) releaseValueFile((s32)self->obstacleTable);
        fn_802C2930(object, 0); /* unlink from the dispatch list, keep the memory */
        if (freeFlag > 0) fn_80128668(object);
    }
    return object;
}
#pragma cplusplus reset
#pragma scheduling on

#pragma scheduling on
#pragma pop

#pragma cplusplus reset

void *fn_8016C168(void *arg0, s32 arg1) {
    void *child;
    void *child2;

    /* Destroy this object and its two owned children when initialized, optionally freeing itself. */
    if (arg0 != 0) {
        if (*((u8 *)arg0 + 8) != 0) {
            child = *(void **)arg0;
            *((u8 *)arg0 + 8) = 0;
            if (child != 0) {
                ((s32 (*)(s32, void *))fn_8002F6AC)(*(s32 *)((u8 *)child + 0xC), fn_8016C29C);
                if (child != 0) {
                    *(s32 *)child = 0;
                    *((s32 *)child + 1) = 0;
                    *((s32 *)child + 2) = 0;
                }
                fn_80128668(child);
            }
            child2 = *((void **)arg0 + 1);
            *(void **)arg0 = 0;
            if (child2 != 0) {
                ((s32 (*)(s32, void *))fn_8002F6AC)(*(s32 *)((u8 *)child2 + 0xC), fn_8016C25C);
                if (child2 != 0) {
                    *(s32 *)child2 = 0;
                    *((s32 *)child2 + 1) = 0;
                    *((s32 *)child2 + 2) = 0;
                }
                fn_80128668(child2);
            }
            *((void **)arg0 + 1) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

/* CodeWarrior deleting-destructor helper: free object via Mem_freeObject (fn_80128668)
   when deleteFlag > 0, then return object. */
int fn_8016C25C(int object, int deleteFlag) {
    if (object != 0 && deleteFlag > 0) { fn_80128668((void *)object); }
    return object;
}

/* Destroys the object: if active, releases its handle and resets fields, then optionally frees it. */
void *fn_8016C29C(void *obj, int shouldDelete) {
    if (obj != 0) {
        if (*((unsigned char *)obj + 16) != 0) {
            int handle = *(int *)obj;
            *((unsigned char *)obj + 16) = 0;
            if (handle != -1) {
                fn_802C6CF8(handle);
                *(int *)obj = -1;
            }
            ((int *)obj)[1] = 0;
            ((int *)obj)[2] = 0;
        }
        if (shouldDelete > 0) fn_80128668(obj);
    }
    return obj;
}

#pragma cplusplus on
#pragma ppc_psq_save off
#pragma paired_single off
#pragma opt_common_subs off
extern "C" void fn_8016C328(void *arg0) {
    class Cfg {
    public:
        virtual void s8();
        virtual int has(const char *);
        virtual void s10();
        virtual void enter(const char *);
        virtual void s18();
        virtual void s1C();
        virtual void s20();
        virtual f32 getF(const char *);
    };
    class List {
    public:
        virtual void s8();
        virtual void *get(s32);
    };
    struct Entry { u8 b; s32 w; f32 a; f32 c; };
    /* lbl_803306D0 is the Crush-mode results layout table: its +0x458..+0x4dc slots
     hold the localized string ids and text-style handles for the two panels. */
  const char *base = lbl_803306D0;
    char buf[0x28];
    Cfg *cfg;
    void *obj;
    List *list;
    void *item;
    s32 i;
    cfg = *(Cfg **)((u8 *)fn_8000AC38() + 0x20);
    if (cfg->has(base + 0x50)) {
        fn_8016CE94((u8 *)arg0 + 8, cfg->getF(base + 0x50));
    } else {
        fn_8016CE94((u8 *)arg0 + 8, 120.0f);
    }
    fn_801345D8(buf, 0x1E, base + 0x5C);
    obj = (void *)fn_801284F8(0x10, base + 0x6C);
    if (obj) {
        obj = fn_8016CD68(obj, fn_8016CDF8(arg0, cfg), (s32)(base + 0x80));
    }
    *(void **)((u8 *)arg0 + 0x18) = obj;
    while (!cfg->has(buf)) {
        cfg->enter(buf);
        list = (List *)fn_80131810();
        if (list) {
            i = 0;
            goto get;
            do {
                fn_8016C768((void *)fn_8016CD4C(*(void **)((u8 *)arg0 + 0x18)), item, (u8 *)arg0 + 0x14 + (i & 0));
                i++;
get:
                item = list->get(i);
            } while (item);
            releaseValueFile((s32)list);
        } else {
            fn_802E30C8(base + 0x90, buf);
            return;
        }
        *(s32 *)((u8 *)arg0 + 0x3C) = *(s32 *)((u8 *)arg0 + 0x3C) + 1;
        fn_801345D8(buf, 0x1E, base + 0xD8, *(s32 *)((u8 *)arg0 + 0x3C));
    }
    *(s32 *)((u8 *)arg0 + 0x3C) = fn_8016C760(*(void **)((u8 *)arg0 + 0x18));
    *(s32 *)((u8 *)arg0 + 0x38) = ((s32 (*)(void *))countAvailableRingSets)(arg0);
    obj = (void *)fn_801284F8(0x10, base + 0xE8);
    if (obj) {
        obj = fn_8016C598(obj, *(s32 *)((u8 *)arg0 + 0x38), (int)(base + 0xE8));
    }
    *(void **)((u8 *)arg0 + 0x1C) = obj;
    {
        for (i = 0; i < *(s32 *)((u8 *)arg0 + 0x38); i++) {
            Entry e;
            e.b = 0;
            e.w = -1;
            e.a = -100.0f;
            e.c = -100.0f;
            fn_8016C55C(*(void **)((u8 *)arg0 + 0x1C), &e);
        }
    }
}
#pragma opt_common_subs on
#pragma cplusplus reset

#pragma ppc_psq_save on
void fn_8016C55C(void *arg0, void *arg1) {
    int index;
    void *dst;
    index = ((int *)arg0)[1];
    ((int *)arg0)[1] = index + 1;
    dst = (void *)((char *)*((void **)arg0) + index * 16);
    *(unsigned char *)dst = *(unsigned char *)arg1;
    *(int *)((char *)dst + 4) = *(int *)((char *)arg1 + 4);
    *(float *)((char *)dst + 8) = *(float *)((char *)arg1 + 8);
    *(float *)((char *)dst + 12) = *(float *)((char *)arg1 + 12);
}

/* Initializes a 16-byte-entry array container: allocates storage for entryCount
 * entries, sets the buffer/capacity pointers and count, clears the size, and
 * returns the container. */
void *fn_8016C598(void *container, int entryCount, int allocTag) {
    int buffer = fn_8012850C(entryCount * 16, allocTag);
    ((int *)container)[0] = buffer;
    ((int *)container)[3] = buffer;
    ((int *)container)[2] = entryCount;
    ((int *)container)[1] = 0;
    return container;
}

#pragma cplusplus on
extern "C" void *fn_8000AC38(void);
extern "C" void *getDifficultySettingString(const char *);
extern "C" void *fn_80131810(void);
extern "C" void fn_801345D8(void *, s32, const char *, ...);
extern "C" int strcmp(const char *, const char *);
extern "C" char *strstr(const char *, const char *);
extern "C" char lbl_803307C8[];
extern "C" char lbl_803307D8[];
extern "C" __declspec(section ".sdata") char lbl_8055A218[];
extern "C" __declspec(section ".sdata") char lbl_8055A220[];
extern "C" s32 countAvailableRingSets(void) {
    #pragma use_lmw_stmw off
    #pragma scheduling invalid_target
    struct Manager {
        virtual void m0();
        virtual void *probe(void *);
        virtual void m2();
        virtual void release(void *);
    };
    struct SourceList {
        virtual void m0();
        virtual void *at(s32);
    };
    struct Entry {
        virtual const char *name();
        virtual void m1();
        virtual void m2();
        virtual const char *search(const char *);
    };
    /* Count consecutive ring sets (set_0_, set_1_, ...) whose "name" field appears in a parsed ring_set source.
     * Walk set indices from zero, stopping at the first one with no matching entry. */
    Manager *manager = *(Manager **)((char *)fn_8000AC38() + 0x20);
    void *difficultyValue = getDifficultySettingString(lbl_803307C8);
    s32 ringSetCount = 0;
    char setPrefix[0x1E];
    if (manager->probe(difficultyValue) != 0) {
        s32 found;
        SourceList *sourceList;
        manager->release(difficultyValue);
        sourceList = (SourceList *)fn_80131810();
        if (sourceList != 0) {
            for (;;) {
                s32 entryIndex;
                found = 0;
                fn_801345D8(setPrefix, 0x1E, lbl_8055A218, ringSetCount);
                for (entryIndex = 0; sourceList->at(entryIndex) != 0; entryIndex++) {
                    if (strcmp(((Entry *)sourceList->at(entryIndex))->name(), lbl_803307D8) == 0 &&
                        strstr(((Entry *)sourceList->at(entryIndex))->search(lbl_8055A220), setPrefix) != 0) {
                        found = 1;
                        ringSetCount++;
                        break;
                    }
                }
                if (found == 0) {
                    break;
                }
            }
            releaseValueFile((s32)sourceList);
        }
    }
    return ringSetCount;
}
#pragma cplusplus reset

/* Return a List8016C768's filled-entry count: `index`, the s32 at +0x4. */
int fn_8016C760(void *list) { return ((int *)list)[1]; }

void fn_8016CD10(void *);
void fn_8016CD28(void *);
#pragma cplusplus off
#pragma cplusplus on
extern "C" void fn_8016CD10(void *);
extern "C" void fn_8016CD28(void *);
extern "C" s8 fn_8016C768(void *arg0, void *arg1, void *arg2) {
    struct Blk { s32 w[12]; };
    struct Item {
        virtual const char *name();
        virtual void m1();
        virtual void m2();
        virtual const char *search(const char *);
        virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual f32 getf(const char *, f32);
        virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
        virtual Blk getblk(const char *);
        virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20();
        virtual s32 check(const char *);
    };
    struct Doc {
        virtual const char *name();
        virtual Item *byIndex(s32);
        virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
        virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
        virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
        virtual void m20(); virtual void m21();
        virtual Item *at(s32);
    };
    char *str = lbl_803306D0;
    List8016C768 *list;
    Item *obj;
    s32 count1, i1, count2, i2, idx;
    s32 ok;
    List8016C768 **out = (List8016C768 **)arg0;
    Doc *doc = (Doc *)arg1;
    Doc **coll = (Doc **)arg2;
    list = (List8016C768 *)fn_801284F8(0x10, str + 0x114);
    if (list != 0) {
        count1 = 0;
        i1 = 0;
        while ((obj = doc->at(i1)) != 0) {
            if (stricmp(obj->name(), &lbl_8055A228) == 0) {
                if (stricmp(obj->search(&lbl_8055A230), str + 0x120) != 0) count1++;
            }
            i1++;
        }
        {
            s32 mem = ((s32 (*)(s32, char *))fn_8012850C)(count1 * 0x44 + 0x10, str + 0x12C);
            s32 r = ((s32 (*)(s32, void *, void *, s32, s32))fn_8002F37C)(mem, (void *)fn_8016CD28, (void *)fn_8016C29C, 0x44, count1);
            list->data = r;
            list->count = count1;
            list->index = 0;
            list->data2 = r;
        }
    }
    out[0] = list;
    list = (List8016C768 *)fn_801284F8(0x10, str + 0x13C);
    if (list != 0) {
        count2 = 0;
        i2 = 0;
        while ((obj = doc->at(i2)) != 0) {
            if (stricmp(obj->name(), &lbl_8055A228) == 0) {
                if (stricmp(obj->search(&lbl_8055A230), str + 0x120) == 0) count2++;
            }
            i2++;
        }
        {
            s32 mem = ((s32 (*)(s32, char *))fn_8012850C)(count2 * 0x38 + 0x10, str + 0x14C);
            s32 r = ((s32 (*)(s32, void *, void *, s32, s32))fn_8002F37C)(mem, (void *)fn_8016CD10, (void *)fn_8016C25C, 0x38, count2);
            list->data = r;
            list->count = count2;
            list->index = 0;
            list->data2 = r;
        }
    }
    out[1] = list;
    ok = 1;
    idx = 0;
    while ((obj = doc->at(idx)) != 0) {
        if (strcmp(obj->name(), &lbl_8055A228) == 0) {
            if (strcmp(obj->search(&lbl_8055A230), str + 0x120) != 0) {
                List8016C768 *l = out[0];
                u8 *e = (u8 *)l->data + l->index++ * 0x44;
                const char *nm = obj->search(&lbl_8055A230);
                Item *c;
                s32 j = 0;
                s32 t;
                while ((c = (*coll)->byIndex(j)) != 0) {
                    if (strcmp(c->name(), &lbl_8055A230) == 0 &&
                        strcmp(c->search(lbl_8055A220), nm) == 0) break;
                    j++;
                }
                if (c == 0) Abend_Panic(str + 0x160, nm);
                t = c->check(str + 0x180);
                if ((u32)(-t | t) >> 31) {
                    *(s32 *)(e + 0xC) = 0;
                    *(s32 *)(e + 8) = c->check(str + 0x180);
                } else if (strcmp(nm, str + 0x120) == 0) {
                    *(s32 *)(e + 0xC) = 2;
                } else {
                    *(s32 *)(e + 0xC) = 1;
                    *(s32 *)e = fn_802C6FC0((s32)c->search(&lbl_8055A238), 0, 0);
                }
                *(Blk *)(e + 0x14) = obj->getblk(str + 0x190);
                *(u8 *)(e + 0x10) = 1;
                if (*(u8 *)(e + 0x10) == 0) ok = 0;
            } else {
                if (strcmp(obj->search(&lbl_8055A230), str + 0x120) == 0) {
                    List8016C768 *l = out[1];
                    u8 *e = (u8 *)l->data + l->index++ * 0x38;
                    if (strcmp(obj->search(&lbl_8055A230), str + 0x120) != 0)
                        Abend_Panic(str + 0x1A0);
                    *(Blk *)e = obj->getblk(str + 0x190);
                    *(f32 *)(e + 0x34) = obj->getf(&lbl_8055A240, lbl_805619A0);
                    *(u8 *)(e + 0x31) = 1;
                    if (*(u8 *)(e + 0x31) == 0) ok = 0;
                }
            }
        }
        idx++;
    }
    *((u8 *)arg0 + 8) = ok;
    return ok;
}
#pragma cplusplus off
extern f32 lbl_805619A0;
#pragma scheduling invalid_target
void fn_8016CD10(void *record) {
    /* Array-element constructor: clear the two flag bytes at +0x30/+0x31 and
       set the float at +0x34 to the shared default value (80.0). */
    f32 defaultValue = lbl_805619A0;
    *(u8 *)((u8 *)record + 0x30) = 0;
    *(u8 *)((u8 *)record + 0x31) = 0;
    *(f32 *)((u8 *)record + 0x34) = defaultValue;
}
#pragma scheduling on
void fn_8016CD28(void *record) {
    // Array-element constructor: init a 0x44-byte record header -- id -1, two zero counters, a field of 3, and a cleared flag at +0x10.
    int zero = 0;
    int minusOne = -1;
    *((u8 *)record + 0x10) = zero;
    ((int *)record)[0] = minusOne;
    ((int *)record)[1] = zero;
    ((int *)record)[2] = zero;
    ((int *)record)[3] = 3;
}

s32 fn_8016CD4C(void *arg0) {
    /* Return the address of the next 0x14-byte "rc_object_files" array entry,
       advancing this fixed-array allocator's hand-out index. */
    s32 *base = (s32 *)((List8016C768 *)arg0)->data;
    s32 index = ((List8016C768 *)arg0)->index;
    ((List8016C768 *)arg0)->index = index + 1;
    return (s32)base + index * 0x14;
}

/* Builds an "rc_object_files" set: allocates count entries of 0x14 bytes behind
 * the runtime's 0x10-byte array header and has the array constructor
 * fn_8002F37C build each one with fn_8016CDE0 (fn_8016C168 is what takes an
 * entry apart again), then points the 0x10-byte container fn_801284F8 just
 * allocated at them: data/data2 the entries, count how many there are and
 * index the next one fn_8016CD4C hands out. */
void *fn_8016CD68(void *container, s32 count, s32 allocName) {
    List8016C768 *list = (List8016C768 *)container;
    s32 temp;
    s32 size = count * 0x14;
    void *buffer = (void *)fn_8012850C(size + 0x10, allocName);
    temp = ((s32 (*)(void *, void *, void *, s32, s32))fn_8002F37C)(
        buffer, fn_8016CDE0, fn_8016C168, 0x14, count);
    list->data = temp;
    list->data2 = temp;
    list->count = count;
    list->index = 0;
    return container;
}

void fn_8016CDE0(void *entry) {
    /* Initialize a 0x14-byte "rc_object_files" entry: clear the in-use flag and the three pointer/word fields so it owns no children. */
    *(u8 *)((u8 *)entry + 8) = 0;
    *(s32 *)((u8 *)entry) = 0;
    *(s32 *)((u8 *)entry + 4) = 0;
    *(s32 *)((u8 *)entry + 0x10) = 0;
}

#pragma cplusplus on
extern "C" s32 fn_8016CDF8(void *unused, void *namedObject) {
    /* Counts sequential named entries by probing the object's lookup with a base name, then numbered names, until lookup fails. */
    struct Obj {
        virtual void v0();
        virtual int v1(char *);
    };
    char nameBuffer[0x1E];
    s32 nameCount = 0;
    fn_801345D8(nameBuffer, 0x1E, lbl_8033072C);
    while (((Obj *)namedObject)->v1(nameBuffer) != 0) {
        nameCount++;
        fn_801345D8(nameBuffer, 0x1E, lbl_803308A0, nameCount);
    }
    return nameCount;
}
#pragma cplusplus reset
/* Store a float field at +4 of the given object; callers use it to record the
 * "time_limit" read from the results config (see fn_8016C328). */
void fn_8016CE94(void *object, f32 value) {
    *(f32 *)((u8 *)object + 4) = value;
}

extern f32 lbl_80561980;
extern char lbl_8033072C[];
extern char lbl_803308A0[];
/* Initialize one 16-byte ring-set entry: store its index, run the allocator
 * bookkeeping hook, reset its float value (lbl_80561980 is 0.0f) at +0xC,
 * then return the entry. */
void *fn_8016CEC0(void *entry, s32 index) {
    *(s32 *)((u8 *)entry + 4) = index;
    fn_8000DA10();
    *(f32 *)((u8 *)entry + 0xC) = lbl_80561980;
    return entry;
}

/* Clear a PtrVec: reset its element count to 0, keeping the backing storage. */
void fn_8016CEFC(void *vec) {
    ((PtrVec *)vec)->count = 0;
}

void *fn_8016CF08(void *obj) {
    // Initialize/clear fields and several fixed-size byte regions of this object.
    register s32 size = 0x30;
    register s32 count = 3;
    s32 zero = 0;
    *(s32 *)((u8 *)obj + 0xC) = zero;
    *(s32 *)((u8 *)obj + 0x14) = zero;
    *(s32 *)((u8 *)obj + 0x18) = zero;
    *(s32 *)((u8 *)obj + 0x1C) = zero;
    *(s32 *)((u8 *)obj + 0x24) = zero;
    *(s32 *)((u8 *)obj + 0x28) = zero;
    *(s32 *)((u8 *)obj + 0x2C) = zero;
    memset((u8 *)obj + 0x30, size, count);
    *((u8 *)obj + 0x33) = 0;
    memset((u8 *)obj + 0x44, size, count);
    *((u8 *)obj + 0x47) = 0;
    memset((u8 *)obj + 0x58, size, count);
    *((u8 *)obj + 0x5B) = 0;
    memset((u8 *)obj + 0x6C, size, count);
    *((u8 *)obj + 0x6F) = 0;
    memset((u8 *)obj + 0x80, size, count);
    *((u8 *)obj + 0x83) = 0;
    memset((u8 *)obj + 0x8A, size, count);
    *((u8 *)obj + 0x8D) = 0;
    memset((u8 *)obj + 0x9E, size, count);
    *((u8 *)obj + 0xA1) = 0;
    memset((u8 *)obj + 0xB2, size, count);
    *((u8 *)obj + 0xB5) = 0;
    memset((u8 *)obj + 0xC6, size, count);
    *((u8 *)obj + 0xC9) = 0;
    memset((u8 *)obj + 0xDA, size, count);
    *((u8 *)obj + 0xDD) = 0;
    return obj;
}

extern char lbl_80330A90[];
extern f32 lbl_80561984;
extern void fn_802C2914(void *);
extern void *getValueFile(void *);
extern void *ArtSetGet(void *);
extern void *fn_802076A0(void *, s32, s32, s32);
extern s32 fn_80204CF0(void);
#pragma push
#pragma optimization_level 4
/* Construct the ring-set controller: install its vtable, load the obstacle table, gem art and challenge sounds, and initialise its ring/marker/difficulty state. */ void *constructRingSetController(void *controller) {
    /* Construct the ring-set controller the RingChallengeMaster (lbl_8055E378)
       carries at +0x30: link it as the current object of its kind, install its
       vtable, load the obstacle table, the gem art set and the seven sound
       effects the challenge plays, and start it with no ring sets, no pending
       map marker and the difficulty the game is currently on. */
    char *const base = lbl_803306D0; /* this module's strings */
    f32 zero;
    void *failSound;
    void *ringHitSound;
    fn_802C2914(controller);                                  /* links it as the current one */
    *(void **)((u8 *)controller + 4) = lbl_80330A90;          /* the controller's vtable */
    *(void **)((u8 *)controller + 0x14) = getValueFile(base + 0x1E0);      /* "race.res/obstacle.val" */
    *(void **)((u8 *)controller + 0x20) = ArtSetGet(base + 0x1F8);      /* the "mapgems.art" set */
    *(void **)((u8 *)controller + 0x4C) = fn_802076A0(base + 0x204, 1, 0, 0); /* "ringhit.sfx" */
    *(void **)((u8 *)controller + 0x50) = fn_802076A0(base + 0x210, 1, 0, 0); /* "cheerhit.sfx" */
    *(void **)((u8 *)controller + 0x58) = fn_802076A0(base + 0x220, 1, 0, 0); /* "rctally.sfx" */
    *(void **)((u8 *)controller + 0x54) = fn_802076A0(base + 0x22C, 1, 0, 0); /* "longcheer.sfx" */
    *(void **)((u8 *)controller + 0x5C) = fn_802076A0(base + 0x23C, 1, 0, 0); /* "missflag.sfx" */
    *(void **)((u8 *)controller + 0x60) = fn_802076A0(base + 0x24C, 1, 0, 0); /* "levelup.sfx" */
    failSound = fn_802076A0(base + 0x258, 1, 0, 0);              /* "rcfail.sfx" */
    ringHitSound = *(void **)((u8 *)controller + 0x4C);
    zero = 0.0f;
    *(void **)((u8 *)controller + 0x64) = failSound;
    *(s32 *)((u8 *)controller + 0x24) = -1;                    /* no map marker queued */
    *(u8 *)((u8 *)controller + 0x48) = 0;
    *(u8 *)((u8 *)controller + 0x49) = 0;
    *(u8 *)((u8 *)controller + 0x4A) = 1;
    *(f32 *)((u8 *)controller + 0x28) = zero;
    *(s32 *)((u8 *)controller + 0x38) = 0;
    *(s32 *)((u8 *)controller + 0x3C) = 0;                     /* no ring sets yet */
    SetNodeF8(ringHitSound);                                     /* the seven sounds start at full scale */
    SetNodeF8(*(void **)((u8 *)controller + 0x50));
    SetNodeF8(*(void **)((u8 *)controller + 0x58));
    SetNodeF8(*(void **)((u8 *)controller + 0x54));
    SetNodeF8(*(void **)((u8 *)controller + 0x5C));
    SetNodeF8(*(void **)((u8 *)controller + 0x60));
    SetNodeF8(*(void **)((u8 *)controller + 0x64));
    *(s32 *)((u8 *)controller + 0x40) = fn_80204CF0();         /* the difficulty in use */
    return controller;
}
#pragma pop
void fn_8016D278(void *list) {
    /* Initialize a collection: point its items at the inline storage at +0xC,
     * set the element count (+0x4) to 0 and its capacity (+0x8) to 8. */
    *(u32 *)list = (u32)list + 0xC;
    *(u32 *)((u8 *)list + 8) = 8;
    *(u32 *)((u8 *)list + 4) = 0;
}

/* --- RingChallengeMaster (lbl_8055E378) -------------------------------------
 * 0x1B4-byte singleton built by fn_8016BE60 under the heap name "ringchalmaster"
 * (lbl_803306D0 + 0x20).  Its ring-set controller sub-object starts at +0x30
 * (constructed by constructRingSetController), so the fields below are that sub-object's
 * +0x18 .. +0x44; the same sub-object is what refreshRingSetMapMarker / fn_8016DFB8 /
 * fn_8016E06C / resetChallengeSetEntry are handed directly.
 *   +0x48  ring-set list: pointer to the array of 0x14-byte ring-set entries
 *   +0x50  map "mapgems.art" object the marker is drawn on
 *   +0x54  queue slot of the pending map marker, -1 when none (fn_8001B308 /
 *          fn_8001B450 reserve and release it)
 *   +0x5C  index of the selected ring set
 *   +0x6C  number of ring sets
 *   +0x74  difficulty selector: 0 = 5 rings, 1 = 10 rings, 2 = 15 rings
 * A ring-set entry (0x14 bytes) is { list of its 0x44-byte gems (+0), active
 * flag (+9), timer (+0xC, lbl_8055E3C8 == 0.0f), counter (+0x10, volatile) }.
 * The three name formats build the set's name, e.g. "set_3_10"; the last
 * string is the error for an out-of-range difficulty.
 */
#define RCM_SET_LIST(o)   (**(u8 ***)((u8 *)(o) + 0x48))
#define RCM_MAP_ART(o)    (*(s32 *)((u8 *)(o) + 0x50))
#define RCM_MAP_MARKER(o) (*(s32 *)((u8 *)(o) + 0x54))
#define RCM_SET_INDEX(o)  (*(s32 *)((u8 *)(o) + 0x5C))
#define RCM_SET_COUNT(o)  (*(s32 *)((u8 *)(o) + 0x6C))
#define RCM_DIFFICULTY(o) (*(s32 *)((u8 *)(o) + 0x74))
#define SET_FMT_5         (strings + 0x264) /* "set_%i_5" */
#define SET_FMT_10        (strings + 0x270) /* "set_%i_10" */
#define SET_FMT_15        (strings + 0x27C) /* "set_%i_15" */
#define SET_BAD_DIFFICULTY (strings + 0x288) /* "Unknown difficulty specification in Ring Challenge mode." */

/* The ring-set controller's gem lists.  Its +0x18 holds the ring-set list
 * { array of 0x14-byte ring-set entries (+0), number of sets (+4) }; each
 * entry's +0 is its gem list { array of 0x44-byte gems (+0), gem count (+4) }.
 * A gem record holds the object fn_802BAA68 built for it (+4), the handle that
 * object is built from (+8), a built flag (+0xC, 0 = not built yet) and the
 * transform data fn_802BAA68 reads (+0x14). */
#define RING_SETS(o)     (*(u8 **)((u8 *)(o) + 0x18))
#define LIST_DATA(l)     (*(u8 **)(l))
#define LIST_COUNT(l)    (*(s32 *)((u8 *)(l) + 4))
#define GEM_OBJECT(g)    (*(s32 *)((u8 *)(g) + 4))
#define GEM_HANDLE(g)    (*(s32 *)((u8 *)(g) + 8))
#define GEM_BUILT(g)     (*(s32 *)((u8 *)(g) + 0xC))
#define GEM_TRANSFORM(g) ((u8 *)(g) + 0x14)

/*
 * Select ring set `setIndex` for the Ring Challenge master (lbl_8055E378).
 * Marks the set active, zeroes its timer and releases every gem object it still
 * holds, resets the gems of its "set_<index>_<5|10|15>" set (fn_8016A15C), then
 * drops the pending map marker and queues a new one for the set: fn_8001B308
 * reserves a slot in the shared 16-entry marker queue and that slot is kept at
 * +0x54 so it can be released again.  Kind 0 is the only request the master
 * handles; any other kind does nothing.
 */
/* Select a ring set for the Ring Challenge master: mark it active, clear its timer and gems, reset its configured gem set, then release the old map marker and queue a new one. Only kind 0 is handled. */ void RingChallengeMaster_SelectSet(s32 unused, s32 kind, s32 setIndex) {
    char setName[0x20];   /* "set_%i_5" &c., for the gem-set reset */
    char markerName[0x20]; /* the same name, for the marker position lookup */
    register u8 *master = (u8 *)lbl_8055E378;
    register char *strings = lbl_803306D0;
    FloatPair8016A6B0 pos15, pos10, pos5;
    s32 difficulty;

    if (master != 0) {
        switch (kind) {
        case 0:
        RCM_SET_INDEX(master) = setIndex;
        if (setIndex < RCM_SET_COUNT(master)) {
            s32 gemIndex;
            u8 *ringSet;
            s32 gemByteOffset;
            ringSet = RCM_SET_LIST(master) + setIndex * 0x14; /* 0x14-byte set entry */
            ringSet[9] = 1;                    /* set is active */
            gemIndex = 0;
            *(f32 *)(ringSet + 0xC) = lbl_8055E3C8; /* its timer back to 0.0f */
            gemByteOffset = 0;
            *(volatile s32 *)(ringSet + 0x10) = 0;  /* and its counter to 0 */
            while (gemIndex < *(s32 *)(*(u8 **)ringSet + 4)) { /* its gems */
                u8 *gemList = (u8 *)**(void ***)ringSet;
                void *gemRecord = *(void **)(gemList + gemByteOffset + 4);
                if (gemRecord != 0) {
                    fn_802BAF98(gemRecord, 1);       /* release the gem object */
                }
                gemByteOffset += 0x44;             /* 0x44 bytes per gem */
                gemIndex += 1;
            }
        }
        difficulty = RCM_DIFFICULTY(master);
        switch (difficulty) {
        case 0:
            fn_801345D8(setName, 0x1E, SET_FMT_5, RCM_SET_INDEX(master));
            break;
        case 1:
            fn_801345D8(setName, 0x1E, SET_FMT_10, RCM_SET_INDEX(master));
            break;
        case 2:
            fn_801345D8(setName, 0x1E, SET_FMT_15, RCM_SET_INDEX(master));
            break;
        default:
            Abend_Panic(SET_BAD_DIFFICULTY);
            break;
        }
        fn_8016A15C(setName);                  /* reset that set's gems */
        if (RCM_MAP_MARKER(master) != -1) {
            if (RCM_MAP_MARKER(master) != -1) {
                fn_8001B450(RCM_MAP_MARKER(master)); /* release the old marker */
                RCM_MAP_MARKER(master) = -1;
            }
        }
        difficulty = RCM_DIFFICULTY(master);
        switch (difficulty) {
        case 0:
            fn_801345D8(markerName, 0x1E, SET_FMT_5, RCM_SET_INDEX(master));
            break;
        case 1:
            fn_801345D8(markerName, 0x1E, SET_FMT_10, RCM_SET_INDEX(master));
            break;
        case 2:
            fn_801345D8(markerName, 0x1E, SET_FMT_15, RCM_SET_INDEX(master));
            break;
        default:
            Abend_Panic(SET_BAD_DIFFICULTY);
            break;
        }
        difficulty = RCM_DIFFICULTY(master);
        switch (difficulty) {
        case 0:
            pos5 = fn_8016A6B0(markerName, 0xC); /* marker position, 5-ring set */
            RCM_MAP_MARKER(master) = fn_8001B308(&pos5, RCM_MAP_ART(master), 2);
            break;
        case 1:
            pos10 = fn_8016A6B0(markerName, 9);  /* 10-ring set */
            RCM_MAP_MARKER(master) = fn_8001B308(&pos10, RCM_MAP_ART(master), 2);
            break;
        case 2:
            pos15 = fn_8016A6B0(markerName, 6);  /* 15-ring set */
            RCM_MAP_MARKER(master) = fn_8001B308(&pos15, RCM_MAP_ART(master), 2);
            break;
        default:
            Abend_Panic(SET_BAD_DIFFICULTY);
            break;
        }
        break;
        default:
            break;
        }
    }
}

/* Count gem records in all ring sets that are not yet built (record+0xC == 0). */
s32 fn_8016D544(void *arg0) {
    void **setEntries;
    s32 unbuiltCount;
    s32 setCount;
    s32 setOffset;
    s32 gemOffset;
    s32 *setList;
    s32 setIndex;
    s32 total;
    s32 gemCount;
    s32 gemIndex;
    setList = *(s32 **)((u8 *)arg0 + 0x18);
    total = 0;
    setIndex = 0;
    setCount = *(s32 *)((u8 *)setList + 4);
    setOffset = 0;
    goto outerTest;
outerBody:
    setEntries = *(void ***)setList;
    unbuiltCount = 0;
    gemOffset = 0;
    {
        void *setEntry = *(void **)((u8 *)setEntries + setOffset);
        gemCount = *(s32 *)((u8 *)setEntry + 4);
    }
    for (gemIndex = 0; gemIndex < gemCount; gemIndex++, gemOffset += 0x44) {
        volatile void *setEntrySlot = *(volatile void **)((u8 *)setEntries + setOffset);
        void *gemData = *(void **)(void *)setEntrySlot;
        if (*(s32 *)((u8 *)gemData + gemOffset + 0xC) == 0) unbuiltCount++;
    }
    total += unbuiltCount;
    setOffset += 0x14;
    setIndex++;
outerTest:
    if (setIndex < setCount) goto outerBody;
    return total;
}

s32 fn_802BAA68(s32, void *);
#pragma use_lmw_stmw off
void fn_8016D5B8(void *controller) {
    u8 *ctrl = (u8 *)controller;
    u8 *setList;
    u8 *setEntries;
    s32 gemIndex;
    u8 *gem;
    s32 setOffset;
    s32 gemOffset;
    s32 setIndex;
    u8 *gemList;

    /* For every ring set, build the render object of each gem that lacks one. */
    setIndex = 0;
    setOffset = 0;
    goto outer_check;

outer_setup:
    setEntries = LIST_DATA(setList);
    gemIndex = 0;
    gemOffset = 0;
    goto inner_check;

inner_body:
    gem = LIST_DATA(gemList) + gemOffset;
    if (GEM_BUILT(gem) == 0) {
        GEM_OBJECT(gem) =
            fn_802BAA68(GEM_HANDLE(gem), GEM_TRANSFORM(gem));
    }
    gemOffset += 0x44;
    gemIndex++;

inner_check:
    gemList = *(u8 **)(setEntries + setOffset);
    if (gemIndex < LIST_COUNT(gemList)) goto inner_body;
    setOffset += 0x14;
    setIndex++;

outer_check:
    setList = RING_SETS(ctrl);
    if (setIndex < LIST_COUNT(setList)) goto outer_setup;
}
#pragma use_lmw_stmw on
int fn_8000DA10();
#pragma cplusplus on
extern "C" char lbl_80330990[];
extern "C" char lbl_80330A90[];
extern "C" s32 lbl_8055E378;
extern "C" void fn_8016A68C(void);
extern "C" void fn_80128670(s32);
extern "C" void releaseValueFile(s32);
extern "C" void fn_80235380(void *, char *);
extern "C" void fn_802C2930(void *, s32);
extern "C" void fn_802ADE60(s32, s32);
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma opt_common_subs off
extern "C" void *fn_8016D658(void *arg0, s32 arg1) {
 class VObj { public: virtual void destroy(int); };
 struct List { void *vtable; VObj **items; s32 count; };
 VObj *old; VObj *p; s32 offset, i;
 if (arg0 != 0) {
  old = *(VObj **)((u8 *)arg0 + 0xA4); *(char **)arg0 = lbl_80330990;
  if (old != 0) { if (old != 0) old->destroy(1); }
  i = 0; offset = 0;
  while (i < ((List *)arg0)->count) {
   p = *(VObj **)((u8 *)((List *)arg0)->items + offset);
   if (p != 0) { fn_8000DA10(); fn_80128668(p); }
   offset += 4; i += 1;
  }
  lbl_8055E378 = 0; fn_8016A68C();
  if ((u8 *)arg0 + 0xAC != 0) {
   s32 value = *(s32 *)((u8 *)arg0 + 0xB8);
   if (value != 0) { fn_802ADE60(value, 1); *(s32 *)((u8 *)arg0 + 0xB8) = 0; }
   p = *(VObj **)((u8 *)arg0 + 0xC0); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xC0) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xC4); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xC4) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xC8); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xC8) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xD0); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xD0) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xD4); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xD4) = 0; }
p = *(VObj **)((u8 *)arg0 + 0xD8); if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((u8 *)arg0 + 0xD8) = 0; }
  }
  if ((u8 *)arg0 + 0x30 != 0) {
   *(char **)((u8 *)arg0 + 0x34) = lbl_80330A90;
   fn_80235380(*(void **)((u8 *)arg0 + 0x50), lbl_80330A90);
   p = *(VObj **)((u8 *)arg0 + 0x7C); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x84); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x88); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x80); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x8C); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x90); if (p != 0) { if (p != 0) p->destroy(1); }
p = *(VObj **)((u8 *)arg0 + 0x94); if (p != 0) { if (p != 0) p->destroy(1); }
   p = *(VObj **)((u8 *)arg0 + 0x48);
   if (p != 0) { ((s32 (*)(s32, void *))fn_8002F6AC)(*(s32 *)((u8 *)p + 0xC), fn_8016C168); if (p != 0) { *(s32 *)p = 0; *(s32 *)((u8 *)p + 4) = 0; *(s32 *)((u8 *)p + 8) = 0; fn_80128668(p); } }
   p = *(VObj **)((u8 *)arg0 + 0x4C);
   if (p != 0) { fn_80128670(*(s32 *)((u8 *)p + 0xC)); if (p != 0) { *(s32 *)p = 0; *(s32 *)((u8 *)p + 4) = 0; *(s32 *)((u8 *)p + 8) = 0; fn_80128668(p); } }
   if ((u8 *)arg0 + 0x44 != 0) releaseValueFile(*(s32 *)((u8 *)arg0 + 0x44));
   fn_802C2930((u8 *)arg0 + 0x30, 0);
  }
  if ((u8 *)arg0 + 4 != 0) { if ((u8 *)arg0 + 4 != 0) { *(s32 *)((u8 *)arg0 + 4) = 0; *(s32 *)((u8 *)arg0 + 8) = 0; *(s32 *)((u8 *)arg0 + 0xC) = 0; } }
  if (arg1 > 0) fn_80128668(arg0);
 }
 return arg0;
}
#pragma opt_common_subs on
 #pragma scheduling on
 #pragma cplusplus off


extern s32 fn_8016DD98(void *);
extern s32 fn_8016DE08(void *);
extern s32 fn_8016DE10(s32 *, s32);
extern void fn_8016E06C(void *);
extern void fn_8016DFB8(void *);
extern void refreshRingSetMapMarker(void *);
extern void fn_8016E118(void *);
extern void fn_8016E15C(void *);
extern s32 fn_8016E1A4(s32 *, s32);
extern void resetChallengeSetEntry(void *, s32);
extern void fn_8016E314(void *);
extern void fn_80144C54(s32);
extern void fn_8016A0D4(void);
extern void fn_802E30C8(const char *, ...);
extern char lbl_80330AA4[];
#pragma scheduling invalid_target
extern void fn_8016E15C();
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma ppc_psq_save off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma scheduling invalid_target
/* Reset a challenge-mode state object: clear its ring/set entries and 16-byte status records, reinitialize the active set, then reset its UI/sound handles, flags and timers to their initial values. */ void resetChallengeState(void *obj) {
    /* Reset this object's ring/set collections, sub-state and UI/sound handles to
       their initial values (clear per-entry fields, rebuild/reinit the active set,
       clear the 0x10-byte status entries, reset flags/timers and release/prime the
       handle slots). */
    s32 entryIdx, j, n;
    void *p;

    for (entryIdx = 0; entryIdx < M2C_FIELD(obj, s32 *, 8); entryIdx++) {
        p = ((void **) M2C_FIELD(obj, void **, 4))[entryIdx];
        M2C_FIELD(p, s32 *, 0) = 0;
        M2C_FIELD(p, s8 *, 8) = 0;
        M2C_FIELD(p, f32 *, 0xC) = 0.0f;
    }
    fn_8016A0D4();
    if (M2C_FIELD(obj, s32 *, 0x70) == 0) {
        M2C_FIELD(obj, s32 *, 0x74) = 0;
    } else {
        M2C_FIELD(obj, s32 *, 0x74) = 2;
    }
    M2C_FIELD(obj, s32 *, 0x5C) = 0;
    M2C_FIELD(obj, s32 *, 0x64) = 0;
    M2C_FIELD(obj, s32 *, 0x60) = 0;
    M2C_FIELD(obj, s8 *, 0x78) = 0;
    M2C_FIELD(obj, s8 *, 0x79) = 0;
    M2C_FIELD(obj, s8 *, 0x7A) = 1;
    M2C_FIELD(obj, f32 *, 0x58) = 0.0f;
    if (M2C_FIELD(obj, s32 *, 0x6C) < M2C_FIELD(obj, s32 *, 0x68))
        fn_802E30C8(lbl_80330AA4);
    fn_8016E314((u8 *) obj + 0x38);
    for (j = 0; j < M2C_FIELD(obj, s32 *, 0x68); j++)
        resetChallengeSetEntry((u8 *) obj + 0x30, j);
    for (j = 0; j < M2C_FIELD(obj, s32 *, 0x6C); j++)
        fn_8016E15C((void *) fn_8016E1A4((s32 *) M2C_FIELD(obj, s32 *, 0x48), j));
    fn_8016E118((u8 *) obj + 0x30);
    entryIdx = M2C_FIELD(obj, s32 *, 0x5C);
    if (entryIdx >= 0 && entryIdx < M2C_FIELD(obj, s32 *, 0x68)) {
        fn_8016E06C((u8 *) obj + 0x30);
        fn_8016DFB8((u8 *) obj + 0x30);
        refreshRingSetMapMarker((u8 *) obj + 0x30);
    }
    for (j = 0; j < fn_8016DE08(M2C_FIELD(obj, void **, 0x4C)); j++) {
        *(s8 *) fn_8016DE10((s32 *) M2C_FIELD(obj, void **, 0x4C), j) = 0;
        M2C_FIELD((void *) fn_8016DE10((s32 *) M2C_FIELD(obj, void **, 0x4C), j), s32 *, 4) = -1;
        M2C_FIELD((void *) fn_8016DE10((s32 *) M2C_FIELD(obj, void **, 0x4C), j), f32 *, 8) = -100.0f;
        M2C_FIELD((void *) fn_8016DE10((s32 *) M2C_FIELD(obj, void **, 0x4C), j), f32 *, 0xC) = -100.0f;
    }
    n = fn_8016DD98((u8 *) obj + 0x30);
    M2C_FIELD((void *) fn_8016DE10((s32 *) M2C_FIELD(obj, void **, 0x4C), M2C_FIELD(obj, s32 *, 0x5C)), s32 *, 4) = n;
    if (M2C_FIELD(obj, s32 *, 0x7C)) fn_80144C54(M2C_FIELD(obj, s32 *, 0x7C));
    if (M2C_FIELD(obj, s32 *, 0x84)) fn_80144C54(M2C_FIELD(obj, s32 *, 0x84));
    if (M2C_FIELD(obj, s32 *, 0x88)) fn_80144C54(M2C_FIELD(obj, s32 *, 0x88));
    if (M2C_FIELD(obj, s32 *, 0x80)) fn_80144C54(M2C_FIELD(obj, s32 *, 0x80));
    if (M2C_FIELD(obj, s32 *, 0x8C)) fn_80144C54(M2C_FIELD(obj, s32 *, 0x8C));
    if (M2C_FIELD(obj, s32 *, 0x90)) fn_80144C54(M2C_FIELD(obj, s32 *, 0x90));
    if (M2C_FIELD(obj, s32 *, 0x94)) fn_80144C54(M2C_FIELD(obj, s32 *, 0x94));
    M2C_FIELD(obj, s8 *, 0x9C) = 1;
    M2C_FIELD(obj, f32 *, 0xA0) = -100.0f;
    M2C_FIELD(obj, s32 *, 0xAC) = 0;
    M2C_FIELD(obj, f32 *, 0xB0) = -1.0f;
    M2C_FIELD(obj, s8 *, 0xB4) = 1;
    M2C_FIELD(obj, s8 *, 0xB5) = 0;
    M2C_FIELD(obj, s8 *, 0xBC) = 0;
    M2C_FIELD(obj, s32 *, 0x1A4) = 0;
    M2C_FIELD(obj, s32 *, 0x1A8) = 0;
    M2C_FIELD(obj, s32 *, 0x1AC) = 0;
    M2C_FIELD(obj, s32 *, 0x1B0) = 0;
    if (M2C_FIELD(obj, s32 *, 0xB8)) fn_802AE0E0(M2C_FIELD(obj, s32 *, 0xB8));
    p = M2C_FIELD(obj, void **, 0xC0);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(obj, void **, 0xC4);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(obj, void **, 0xC8);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(obj, void **, 0xD0);
    M2C_FIELD(obj, s8 *, 0xCC) = 0;
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(obj, void **, 0xD4);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(obj, void **, 0xD8);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    p = M2C_FIELD(obj, void **, 0xA4);
    if (p) { M2C_FIELD(p, s8 *, 0x4A) = 1; M2C_FIELD(p, s8 *, 0x4C) = 0; }
    M2C_FIELD(obj, s8 *, 0xA8) = 0;
}
#pragma scheduling on
#pragma opt_common_subs on
#pragma opt_loop_invariants on
#pragma pop
/* Returns the point value for a ring challenge spec (0->5, 1->10, 2->15); panics on unknown. */
s32 fn_8016DD98(void *arg0) {
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    switch (value) {
        case 0: return 5;
        case 1: return 0xA;
        case 2: return 0xF;
        default: {
            void (*report)(const char *, ...) = Abend_Panic;
            report(lbl_80330AEC);
            return 0;
        }
    }
}

/* Return a PtrVec's record count: `count`, the s32 at +0x4. Pairs with fn_8016DE10, which indexes the vec's data. */
s32 fn_8016DE08(void *vec) { return ((s32 *)vec)[1]; }

/* Compute the address of the index-th 16-byte record in the array whose base pointer is stored at *arg0 (record layout: +0 flag byte, +4 int, +8/+0xC floats). */
s32 fn_8016DE10(s32 *header, s32 index) {
    return *header + (index * 0x10);
}

/* Refreshes an object's display text/resource handle based on its mode/index.
 * Frees any existing handle, formats mode-specific label text, resolves display
 * metrics for that label, then allocates/updates the active handle; logs an
 * error for unknown modes. */
void refreshRingSetMapMarker(void *controller)
{
    /* Release the old marker slot, build the ring-set name for the current
       difficulty, measure its text and reserve a fresh map marker. */
    char labelText[0x20];
    register char *strings = lbl_803306D0;
    register void *ctrl = controller;
    s32 oldMarkerSlot;
    s32 difficulty;

    oldMarkerSlot = *(s32 *)((u8 *)ctrl + 0x24);
    if (oldMarkerSlot != -1) {
        if (oldMarkerSlot != -1) {
            fn_8001B450(oldMarkerSlot);
            *(s32 *)((u8 *)ctrl + 0x24) = -1;
        }
    }

    difficulty = *(s32 *)((u8 *)ctrl + 0x44);
    switch (difficulty) {
    case 0:
        fn_801345D8(labelText, 0x1E, strings + 0x264, *(s32 *)((u8 *)ctrl + 0x2C));
        break;
    case 1:
        fn_801345D8(labelText, 0x1E, strings + 0x270, *(s32 *)((u8 *)ctrl + 0x2C));
        break;
    case 2:
        fn_801345D8(labelText, 0x1E, strings + 0x27C, *(s32 *)((u8 *)ctrl + 0x2C));
        break;
    default:
        Abend_Panic(strings + 0x288);
        break;
    }

    difficulty = *(s32 *)((u8 *)ctrl + 0x44);
    switch (difficulty) {
    case 0: {
        FloatPair8016A6B0 labelMetrics = fn_8016A6B0(labelText, 0xC);
        *(s32 *)((u8 *)ctrl + 0x24) =
            fn_8001B308(&labelMetrics, *(s32 *)((u8 *)ctrl + 0x20), 2);
        break;
    }
    case 1: {
        FloatPair8016A6B0 labelMetrics = fn_8016A6B0(labelText, 9);
        *(s32 *)((u8 *)ctrl + 0x24) =
            fn_8001B308(&labelMetrics, *(s32 *)((u8 *)ctrl + 0x20), 2);
        break;
    }
    case 2: {
        FloatPair8016A6B0 labelMetrics = fn_8016A6B0(labelText, 6);
        *(s32 *)((u8 *)ctrl + 0x24) =
            fn_8001B308(&labelMetrics, *(s32 *)((u8 *)ctrl + 0x20), 2);
        break;
    }
    default:
        Abend_Panic(strings + 0x288);
        break;
    }
}

extern f32 lbl_8055E3C8;
extern f32 lbl_80561998;
extern void fn_8001B450(s32);
extern void fn_802BAF98(void *, s8);
void fn_8016DFB8(void *object) {
    /* Formats a mode-specific label for this object's value (+0x2C) based on its
       display mode (+0x44): modes 0/1/2 use format strings at lbl_803306D0+0x264/
       0x270/0x27C, any other logs the error string at +0x288, then passes the
       resulting text buffer to fn_8016A15C. */
    char textBuffer[30];
    char *formatBase = lbl_803306D0;
    switch (*(s32 *)((u8 *)object + 0x44)) {
    case 0:
        fn_801345D8(textBuffer, 0x1E, formatBase + 0x264, *(s32 *)((u8 *)object + 0x2C));
        break;
    case 1:
        fn_801345D8(textBuffer, 0x1E, formatBase + 0x270, *(s32 *)((u8 *)object + 0x2C));
        break;
    case 2:
        fn_801345D8(textBuffer, 0x1E, formatBase + 0x27C, *(s32 *)((u8 *)object + 0x2C));
        break;
    default:
        Abend_Panic(formatBase + 0x288);
        break;
    }
    fn_8016A15C(textBuffer);
}

#pragma scheduling invalid_target
void fn_8016E06C(void *arg0) {
    /* Activate the selected 0x14-byte item entry and enable each of its sub-handles. */
    u8 **baseSlot;
    s32 index = *(s32 *)((u8 *)arg0 + 0x2c);
    if (index < *(s32 *)((u8 *)arg0 + 0x3c)) {
        s32 i = 0;
        u8 *item;
        s32 offset;
        baseSlot = *(u8 ***)((u8 *)arg0 + 0x18);
        item = *baseSlot + index * 0x14;
        item[9] = 1;
        i = 0;
        *(f32 *)(item + 0xc) = lbl_8055E3C8;
        offset = 0;
        *(volatile s32 *)(item + 0x10) = 0;
        while (i < *(s32 *)(*(u8 **)item + 4)) {
            s32 value = *(s32 *)(*(u8 **)*(u8 **)item + offset + 4);
            if (value != 0) {
                fn_802BAF98((void *)value, 1);
            }
            offset += 0x44;
            i += 1;
        }
    }
}
#pragma scheduling on
/* Release the stored entry handle at offset 0x24 (if set) and clear it to -1. */
void fn_8016E118(void *obj)
{
    s32 value = *(s32 *)((u8 *)obj + 0x24);
    if (value != -1) {
        fn_8001B450(value);
        *(s32 *)((u8 *)obj + 0x24) = -1;
    }
}

#pragma push
#pragma scheduling off
void fn_8016E15C(void *arg0) {
    f32 f = lbl_80561998;
    int off;
    int i;
    *(u8 *)((u8 *)arg0 + 9) = 0;
    i = 0;
    off = 0;
    *(f32 *)((u8 *)arg0 + 0xC) = f;
    *(s32 *)((u8 *)arg0 + 0x10) = 0;
    while (i < *(int *)(*(char **)((u8 *)arg0 + 4) + 4)) {
        unsigned char *base = *(unsigned char **)*(char **)((u8 *)arg0 + 4);
        i++;
        base[off + 0x30] = 0;
        off += 0x38;
    }
}
#pragma pop
/* Address of the index-th 0x14-byte element in the array whose base pointer is *basePtr. */
s32 fn_8016E1A4(s32 *basePtr, s32 index) {
    return *basePtr + (index * 0x14);
}

extern void fn_8016A240(void *);

// Builds a formatted state label for this object, applies it via UI helper, resets the
// selected list entry's runtime fields/child handles when index is valid, and stops its
// active sound handle if one is set.
void resetChallengeSetEntry(void *arg0, s32 arg1) {
    char sp8[0x28];
    register char *format = lbl_803306D0;
    s32 value = *(s32 *)((u8 *)arg0 + 0x44);
    switch (value) {
    case 0:
        fn_801345D8(sp8, 0x1e, format + 0x264, *(s32 *)((u8 *)arg0 + 0x2c));
        break;
    case 1:
        fn_801345D8(sp8, 0x1e, format + 0x270, *(s32 *)((u8 *)arg0 + 0x2c));
        break;
    case 2:
        fn_801345D8(sp8, 0x1e, format + 0x27c, *(s32 *)((u8 *)arg0 + 0x2c));
        break;
    default:
        Abend_Panic(format + 0x288);
        break;
    }
    fn_8016A240(sp8);
    if (arg1 < *(s32 *)((u8 *)arg0 + 0x3c)) {
        register s32 i;
        register void **list = *(void ***)((u8 *)arg0 + 0x18);
        s32 delta = arg1 * 0x14;
        register u8 *base = (u8 *)*list;
        register u8 *item = base + delta;
        s32 offset;
        *(u8 *)(item + 9) = 0;
        i = 0;
        offset = 0;
        *(f32 *)(item + 0xc) = lbl_8055E3C8;
        while (i < *(s32 *)((u8 *)*(void **)item + 4)) {
            u8 *entries = (u8 *)*(void **)*(void **)item;
            void *handle = *(void **)(entries + offset + 4);
            if (handle != 0) {
                fn_802BAF98(handle, 0);
            }
            offset += 0x44;
            i += 1;
        }
    }
    if (*(s32 *)((u8 *)arg0 + 0x24) != -1) {
        fn_8001B450(*(s32 *)((u8 *)arg0 + 0x24));
        *(s32 *)((u8 *)arg0 + 0x24) = -1;
    }
}

#pragma dont_inline on
void fn_8016E314(void *pair) {
    /* Copy this two-float pair's second float (+4) into its first (+0). */
    *(f32 *)((u8 *)pair + 0) = *(f32 *)((u8 *)pair + 4);
}
#pragma dont_inline reset

/* Read the enable flag byte at +0x9C of the TObj4C object (set to 1 on creation,
 * cleared on reset, gates its +0xA0 timer/countdown logic). */
u8 fn_8016E320(void *object) {
    return *(u8 *)((u8 *)object + 0x9c);
}

#pragma cplusplus on
extern "C" float lbl_80561988, lbl_805619A8, lbl_805619AC, lbl_805619B0, lbl_805619B4, lbl_805619B8, lbl_805619BC;
extern "C" void *fn_801E7E3C(void);
extern "C" int fn_801E866C(int);
extern "C" int fn_80160998(void);
extern "C" void fn_8000FBE4(void), fn_80160A74(void);
extern "C" void fn_8001DF08(int,int);
extern "C" unsigned char *fn_80131234(const char *);
extern "C" float fn_80147204(void *, void *);
extern "C" void fn_801479A8(void *, void *, void *, ...);
static inline float HudEase(float t) {
    if (t < lbl_805619A4) return lbl_805619A4;
    if (t > lbl_80561984) return lbl_80561984;
    if (t > lbl_80561980) return t * (-2.0f * t * t) + 3.0f * t * t;
    return t * (-2.0f * t * t) - 3.0f * t * t;
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Draws the timed results panels on the Crush-mode results overlay: the
   "ring challenge master" and "player data" info boxes fade in and out on a
   fixed timeline relative to the round's start.  Skipped entirely while a
   challenge sub-task is still active. */
extern "C" int drawCrushHudInfoPanels(void *master, int playerIndex) {
#define getRoundClock fn_801E7E3C
#define showCountdown fn_8000FBE4
#define challengeSubtaskActive fn_80161C38
#define notifyScoreGrade fn_8001DF08
#define formatScore fn_801308F4
#define formatSeconds fn_80130978
#define lookupMessage fn_80131234
#define measureTextWidth fn_80147204
#define setupUiElement fn_8014784C
#define drawPanelText fn_801479A8
#define getPlayerNumber fn_801E866C
#define getScore fn_80160998
#define resultsLabels lbl_803306D0
#define fadeMax lbl_80561984
#define fadeMin lbl_80561980
#define textWidthScale lbl_80561988
#define timelineEnd lbl_805619A8
#define fadeOut1Dur lbl_805619AC
#define fadeIn1Dur lbl_805619B0
#define fadeOut2Dur lbl_805619B4
#define dataLabel lbl_8055A248
 struct Rect { int a; float b; int c,d; float e; int f,g,h; };
 struct Manager { virtual void *unused(); virtual void *get(const char *); };
 struct Frame { Rect rect2; char text2[24]; Rect rect1; char text1[20]; } frame;
   const char *base = resultsLabels;
  struct Manager *scene; void *backgroundHandle, *foregroundHandle;
  float totalTime, tFadeOut1, elapsedTime, tFadeIn1, tFadeOut2, tFadeIn2, tFadeStart, progress, fadeAmount;
  elapsedTime = *(float *)((char *)getRoundClock()+0x10);
  totalTime=timelineEnd; tFadeOut1=totalTime-fadeOut1Dur; tFadeIn1=tFadeOut1-fadeIn1Dur;
  tFadeOut2=tFadeIn1-fadeOut2Dur; tFadeIn2=tFadeOut2-fadeOut1Dur; tFadeStart=tFadeIn2-fadeIn1Dur;
  scene=*(struct Manager **)((char *)master+0x98);
  backgroundHandle=scene->get(base+0x458);
  scene=*(struct Manager **)((char *)master+0x98);
  foregroundHandle=scene->get(base+0x468);
  if (elapsedTime < tFadeStart) showCountdown();
  if (!challengeSubtaskActive()) {
    if (elapsedTime < totalTime) {
      void *panelHandle, *detailHandle;
      progress=(elapsedTime-tFadeOut1)/(tFadeIn1-tFadeOut1); fadeAmount=fadeMax;
      fadeAmount = fadeAmount < progress ? fadeAmount : progress;
      fadeAmount = fadeAmount > fadeMin ? fadeAmount : fadeMin;
      fadeAmount=fadeMin+fadeAmount*fadeMax;
      scene=*(struct Manager **)((char *)master+0x98);
      panelHandle=scene->get(base+0x478);
      scene=*(struct Manager **)((char *)master+0x98);
      detailHandle=scene->get(base+0x484);
      notifyScoreGrade(getPlayerNumber(playerIndex),0);
      if (backgroundHandle && foregroundHandle && panelHandle && detailHandle) {
        drawPanelText(backgroundHandle,foregroundHandle,lookupMessage(base+0x490),HudEase(fadeAmount));
        fn_80160A74(); ((void (*)(void *,int,int))formatScore)(frame.text1,0x14,getScore());
        frame.rect1.a=*(int *)panelHandle;
        { int cword; int bword; bword=*(volatile int *)((char *)panelHandle+4); cword=*(volatile int *)((char *)panelHandle+8); *(int *)&frame.rect1.b=bword; frame.rect1.c=cword; } frame.rect1.d=*(int *)((char *)panelHandle+12); frame.rect1.e=*(float *)((char *)panelHandle+16); frame.rect1.f=*(int *)((char *)panelHandle+20); frame.rect1.g=*(int *)((char *)panelHandle+24); frame.rect1.h=*(int *)((char *)panelHandle+28);
        frame.rect1.b-=textWidthScale*measureTextWidth(&frame.rect1,frame.text1);
        drawPanelText(&frame.rect1,detailHandle,frame.text1,HudEase(fadeAmount));
      }
    }
    if (elapsedTime < tFadeOut2) {
      void *panelHandle, *detailHandle;
      setupUiElement(*(void **)((char *)master+0x98),base+0x4ac,base+0x4bc,0);
      progress=(elapsedTime-tFadeIn2)/(tFadeStart-tFadeIn2); fadeAmount=fadeMax;
      fadeAmount = fadeAmount < progress ? fadeAmount : progress;
      fadeAmount = fadeAmount > fadeMin ? fadeAmount : fadeMin;
      fadeAmount=fadeMin+fadeAmount*fadeMax;
      scene=*(struct Manager **)((char *)master+0x98);
      panelHandle=scene->get(base+0x4d0);
      scene=*(struct Manager **)((char *)master+0x98);
      detailHandle=scene->get(&dataLabel);
      if (backgroundHandle && foregroundHandle && panelHandle && detailHandle) {
        drawPanelText(backgroundHandle,foregroundHandle,lookupMessage(base+0x4dc),HudEase(fadeAmount));
        formatSeconds(frame.text2,0x14,*(float *)((char *)master+0x38));
        frame.rect2.a=*(int *)panelHandle;
        { int cword; int bword; bword=*(volatile int *)((char *)panelHandle+4); cword=*(volatile int *)((char *)panelHandle+8); *(int *)&frame.rect2.b=bword; frame.rect2.c=cword; } frame.rect2.d=*(int *)((char *)panelHandle+12); frame.rect2.e=*(float *)((char *)panelHandle+16); frame.rect2.f=*(int *)((char *)panelHandle+20); frame.rect2.g=*(int *)((char *)panelHandle+24); frame.rect2.h=*(int *)((char *)panelHandle+28);
        frame.rect2.b+=textWidthScale*measureTextWidth(&frame.rect2,frame.text2);
        drawPanelText(&frame.rect2,detailHandle,frame.text2,HudEase(fadeAmount));
      }
    }
  }
#undef getRoundClock
#undef showCountdown
#undef challengeSubtaskActive
#undef notifyScoreGrade
#undef formatScore
#undef formatSeconds
#undef lookupMessage
#undef measureTextWidth
#undef setupUiElement
#undef drawPanelText
#undef getPlayerNumber
#undef getScore
#undef resultsLabels
#undef fadeMax
#undef fadeMin
#undef textWidthScale
#undef timelineEnd
#undef fadeOut1Dur
#undef fadeIn1Dur
#undef fadeOut2Dur
#undef dataLabel
  return 1;
}
#pragma pop
#pragma cplusplus reset

extern f32 lbl_805619C0;
extern f32 fn_8016E878(void);
/* Getter returning a fixed read-only tuning constant (7.75) shared by the HUD/gauge code. */
f32 fn_8016E878(void) {
    return lbl_805619C0;
}

extern char lbl_80330BC8[];
extern char lbl_80330BD8[];
extern void *fn_80145E70(const char *);
extern s32 fn_801284F8(s32, const char *);
extern void *fn_802ADDD8(s32);
extern void fn_8016EA9C(void *);
extern void fn_8016E984(void *);
extern s32 fn_80179650(void);
#pragma scheduling invalid_target
void fn_8016E880(void *arg0, void *arg1) {
    /* Initializes an output record from an input descriptor: copies count, stores current context, sets flags, and expands each input item into a 0x14-byte entry. */
    u8 *input = (u8 *)arg0;
    u8 *output = (u8 *)arg1;
    u8 *entry;
    s32 offset;
    s32 index;
    *(s32 *)output = *(s32 *)(input + 8);
    *(s32 *)(output + 4) = fn_80179650();
    *(u8 *)(output + 0xD) = 1;
    *(u8 *)(output + 0xE) = 0;
    index = 0;
    offset = 0;
    entry = output;
    goto check;
loop:
    *(s32 *)(entry + 0x10) = index;
    index++;
    *(u8 *)(entry + 0x20) = 0;
    *(s32 *)(entry + 0x18) = **(s32 **)(*(u32 *)(input + 4) + offset);
    offset += 4;
    *(s32 *)(entry + 0x14) = 1;
    *(u8 *)(output + 0xC) = 1;
    entry += 0x14;
check:
    if (index < *(s32 *)(input + 8)) goto loop;
}
#pragma scheduling on
// Initializes the freestyle system on `owner`: load its "freestyle.val" config
// into +0x98, construct an ArtAnim manager into +0xB8, and initialize/reset the
// embedded subobject at +0xAC.
void fn_8016E918(void *owner) {
#define freestyleConfig lbl_80330BC8
#define managerTag      lbl_80330BD8

    void *artAnimManager;
    *(void **)((u8 *)owner + 0x98) = fn_80145E70(freestyleConfig);
    artAnimManager = (void *)fn_801284F8(8, managerTag);
    if (artAnimManager != 0) {
        artAnimManager = ((void *(*)(void *, s32))fn_802ADDD8)(artAnimManager, 1);
    }
    *(void **)((u8 *)owner + 0xB8) = artAnimManager;
    {
        volatile u8 *p = (volatile u8 *)owner;
        fn_8016EA9C((void *)(p + 0xAC));
        fn_8016E984((void *)(p + 0xAC));
    }

#undef freestyleConfig
#undef managerTag
}

extern f32 lbl_805619A4;
#pragma scheduling on
void fn_8016E984(void *roundState) {
    /* Reset a ring-challenge round to idle: clear its state/timer/counters,
       deactivate the animation cues, and stop all six of its sounds. */
    CrushRoundState8016B964 *round = (CrushRoundState8016B964 *)roundState;
    Sound8016B964 *sound;

    round->state = 0;
    round->time = -1.0f;
    round->active = 1;
    round->flag9 = 0;
    round->flag10 = 0;
    round->counters[0] = 0;
    round->counters[1] = 0;
    round->counters[2] = 0;
    round->counters[3] = 0;
    if (round->animPlayer != 0)
        ((void (*)(void **))fn_802AE0E0)(round->animPlayer);
    sound = round->sound14;
    if (sound != 0) { sound->stop = 1; sound->stopOnce = 0; }
    sound = round->sound18;
    if (sound != 0) { sound->stop = 1; sound->stopOnce = 0; }
    sound = round->sound1C;
    if (sound != 0) { sound->stop = 1; sound->stopOnce = 0; }
    sound = round->sound24;
    round->flag20 = 0;
    if (sound != 0) { sound->stop = 1; sound->stopOnce = 0; }
    sound = round->sound28;
    if (sound != 0) { sound->stop = 1; sound->stopOnce = 0; }
    sound = round->sound2C;
    if (sound != 0) { sound->stop = 1; sound->stopOnce = 0; }
}
#pragma scheduling off
extern void fn_80130980(void *, s32, s32, f32);
extern s32 fn_80207848(void *, s32);
extern s32 fn_802ADF34(void *, char *, s32 *);
extern s32 lbl_802FAA40[3];
extern u8 lbl_8055A250;
extern u8 lbl_8055A258;
extern u8 lbl_8055A25C;
extern u8 lbl_8055A260;
extern f32 lbl_805619C4;
#pragma optimize_for_size on
#pragma scheduling invalid_target
void fn_8016EA9C(void *arg0)
{
  union Word
  {
    s32 i;
    void *p;
  } stack[94];
  char *base = lbl_803306D0;
  volatile s32 *vp = (volatile s32 *) (&stack[45].i);
  u32 ctr;
  u8 *s0;
  u8 *s1;
  u8 *s2;
  s32 n0;
  s32 n1;
  s32 n2;
  s32 ch;
  for (ctr = 0; ctr < 0x18; ctr++)
  {
    vp[1] = 0;
    vp += 2;
    vp[0] = 0;
  }

  stack[44].i = (s32) (((u8 *) arg0) + 0xF8);
  stack[48].i = (s32) (((u8 *) arg0) + 0xF8);
  stack[30].i = 1;
  stack[42].i = 3;
  stack[43].p = lbl_803306D0 + 0x518;
  stack[46].i = 3;
  stack[47].p = lbl_803306D0 + 0x518;
  stack[39].i = 3;
  stack[40].p = lbl_803306D0 + 0x524;
  stack[41].i = (s32) (((u8 *) arg0) + 0xFC);
  stack[49].i = 3;
  stack[50].p = base + 0x524;
  stack[51].i = (s32) (((u8 *) arg0) + 0xFC);
  stack[36].i = 3;
  stack[37].p = &lbl_8055A250;
  stack[38].i = (s32) (((u8 *) arg0) + 0x100);
  stack[52].i = 3;
  stack[53].p = &lbl_8055A250;
  stack[54].i = (s32) (((u8 *) arg0) + 0x100);
  stack[33].i = 3;
  stack[34].p = base + 0x530;
  stack[35].i = (s32) (((u8 *) arg0) + 0x104);
  stack[55].i = 3;
  stack[56].p = base + 0x530;
  stack[57].i = (s32) (((u8 *) arg0) + 0x104);
  stack[31].p = base + 0x53C;
  stack[32].i = (s32) (((u8 *) arg0) + 0x30);
  stack[58].i = 1;
  stack[59].p = base + 0x53C;
  stack[60].i = (s32) (((u8 *) arg0) + (0x30 & 0xFFFFFFFFFFFFFFFF));
  stack[27].i = 1;
  stack[28].p = base + 0x524;
  stack[29].i = (s32) (((u8 *) arg0) + 0x44);
  stack[61].i = 1;
  stack[62].p = base + 0x524;
  stack[63].i = (s32) (((u8 *) arg0) + 0x44);
  stack[24].i = 1;
  stack[25].p = base + 0x548;
  stack[26].i = (s32) (((u8 *) arg0) + 0x58);
  stack[64].i = 1;
  stack[65].p = base + 0x548;
  stack[66].i = (s32) (((u8 *) arg0) + 0x58);
  stack[21].i = 1;
  stack[22].p = base + 0x530;
  stack[23].i = (s32) (((u8 *) arg0) + 0x6C);
  stack[67].i = 1;
  stack[68].p = base + 0x530;
  stack[69].i = (s32) (((u8 *) arg0) + 0x6C);
  stack[18].i = 1;
  stack[19].p = &lbl_8055A250;
  stack[20].i = (s32) (((u8 *) arg0) + 0x80);
  stack[70].i = 1;
  stack[71].p = &lbl_8055A250;
  stack[72].i = (s32) (((u8 *) arg0) + 0x80);
  stack[15].i = 1;
  stack[16].p = base + 0x560;
  stack[74].p = base + 0x560;
  stack[73].i = 1;
  stack[12].i = 1;
  stack[13].p = base + 0x518;
  stack[14].i = (s32) (((u8 *) arg0) + 0x9E);
  stack[76].i = 1;
  stack[77].p = base + 0x518;
  stack[78].i = (s32) (((u8 *) arg0) + 0x9E);
  stack[9].i = 1;
  stack[10].p = base + 0x57C;
  stack[11].i = (s32) (((u8 *) arg0) + 0xB2);
  stack[79].i = 1;
  stack[80].p = base + 0x57C;
  stack[81].i = (s32) (((u8 *) arg0) + 0xB2);
  stack[6].i = 1;
  stack[7].p = base + 0x594;
  stack[8].i = (s32) (((u8 *) arg0) + 0xC6);
  stack[82].i = 1;
  stack[83].p = base + 0x594;
  stack[84].i = (s32) (((u8 *) arg0) + 0xC6);
  stack[3].i = 1;
  stack[4].p = base + 0x5AC;
  stack[5].i = (s32) (((u8 *) arg0) + 0xDA);
  stack[85].i = 1;
  stack[86].p = base + 0x5AC;
  stack[87].i = (s32) (((u8 *) arg0) + 0xDA);
  stack[0].i = 2;
  stack[1].p = base + 0x5C0;
  stack[2].i = (s32) (((u8 *) arg0) + 0xF0);
  stack[88].i = 2;
  stack[89].p = base + 0x5C0;
  stack[90].i = (s32) (((u8 *) arg0) + 0xF0);
  stack[91].i = lbl_802FAA40[0];
  stack[92].i = lbl_802FAA40[1];
  stack[93].i = lbl_802FAA40[2];
  s0 = ((u8 *) arg0) + 0x8A;
  stack[17].p = s0;
  stack[75].p = s0;
  s1 = (u8 *) (&lbl_8055A258);
  n0 = 0x14;
  ch = *(s1++);
  *(s0++) = ch;
  while (((s8) ch) != 0)
  {
    if ((--n0) <= 0)
    {
      *((s8 *) (s0 - 1)) = 0;
      break;
    }
    ch = *(s1++);
    *(s0++) = ch;
  }

  s2 = ((u8 *) arg0) + 0x44;
  s1 = (u8 *) (&lbl_8055A25C);
  n1 = 0x14;
  ch = *(s1++);
  *(s2++) = ch;
  while (((s8) ch) != 0)
  {
    if ((--n1) <= 0)
    {
      *((s8 *) (s2 - 1)) = 0;
      break;
    }
    ch = *(s1++);
    *(s2++) = ch;
  }

  s2 = ((u8 *) arg0) + ((((((((0x6C & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu);
  s1 = (u8 *) (&lbl_8055A260);
  n2 = 0x14;
  ch = *(s1++);
  *(s2++) = ch;
  while (((s8) ch) != 0)
  {
    if ((--n2) <= 0)
    {
      *((s8 *) (s2 - 1)) = 0;
      break;
    }
    ch = *(s1++);
    *(s2++) = ch;
  }

  fn_80130980(((u8 *) arg0) + 0x9E, 0x14, 2, lbl_805619C4);
  *((s32 *) (((u8 *) arg0) + (((((((((0xF0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF))) = fn_80204CF0() + 1;
  *((s32 *) (((u8 *) arg0) + 0xF4)) = fn_802ADF34(*((void **) (((u8 *) arg0) + 0xC)), base + 0x5D4, &stack[46].i);
  *((s32 *) (((u8 *) arg0) + 0x14)) = fn_80207848(base + 0x5E8, 1);
  *((s32 *) (((u8 *) arg0) + 0x18)) = fn_80207848(base + 0x5FC, 1);
  *((s32 *) (((u8 *) arg0) + 0x1C)) = fn_80207848(base + 0x618, 1);
  *((s32 *) (((u8 *) arg0) + 0x24)) = fn_80207848(base + 0x62C, 1);
  *((s32 *) (((u8 *) arg0) + 0x28)) = fn_80207848(base + 0x24C, 1);
  *((s32 *) (((u8 *) arg0) + 0x2C)) = fn_80207848(base + 0x640, 1);
}
#pragma scheduling on
#pragma optimize_for_size reset
extern void fn_802ADE60(s32, s32);
#pragma cplusplus on
/* Destroy the freestyle system: release the ArtAnim manager at +0xB8, destroy the six virtual subobjects at +0xC0..+0xD8 and clear their slots, then destroy the loaded config at +0x98. */ extern "C" void destroyFreestyleSystem(void *owner) {
    /* Release owned resources and virtual subobjects held by this object. */
    class VObj { public: virtual void destroy(int); };
    VObj *resource;
    s32 artAnimManager;

    artAnimManager = *(s32 *)((u8 *)owner + 0xB8);
    if (artAnimManager != 0) {
        fn_802ADE60(artAnimManager, 1);
        *(s32 *)((u8 *)owner + 0xB8) = 0;
    }
    resource = *(VObj **)((u8 *)owner + 0xC0);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)owner + 0xC0) = 0; }
    resource = *(VObj **)((u8 *)owner + 0xC4);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)owner + 0xC4) = 0; }
    resource = *(VObj **)((u8 *)owner + 0xC8);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)owner + 0xC8) = 0; }
    resource = *(VObj **)((u8 *)owner + 0xD0);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)owner + 0xD0) = 0; }
    resource = *(VObj **)((u8 *)owner + 0xD4);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)owner + 0xD4) = 0; }
    resource = *(VObj **)((u8 *)owner + 0xD8);
    if (resource != 0) { if (resource != 0) resource->destroy(1); *(VObj **)((u8 *)owner + 0xD8) = 0; }
    resource = *(VObj **)((u8 *)owner + 0x98);
    if (resource != 0) resource->destroy(1);
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
#pragma scheduling on
#pragma ppc_psq_save off
#pragma cplusplus on
extern "C" void fn_8016EFA4(void *arg0, s32 arg1) {
    char *base = lbl_803306D0;
    void **temp_r28;
    void *temp_r27;
    s32 var_r27, var_r26, var_r25;
    void *temp_r24, *temp_r23, *temp_r22, *temp_r21;
    s32 var_r20;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    UiDraw8016 sF8, sDC, sC0;
    UiText8016 sA0, s80;
    UiDraw8016 s64, s48;
    UiText8016 s28;
    UiDraw8016 s8;
    void *var_r21;
    void *temp_r22_2;
    f32 temp_f31, temp_f30, temp_f29, temp_f28, startY, startX;
    f32 temp_f25, temp_f24, temp_f23, temp_f22, temp_f21, temp_f20;
    f32 temp_f18, temp_f17, temp_f16, temp_f19, temp_f15_2, temp_f15, temp_f14;
    f32 temp_f1, temp_f1_2, temp_f1_3, temp_f1_5, temp_f1_6, temp_f1_7, temp_f1_8;
    f32 temp_f2, temp_f2_2, temp_f2_3, temp_f2_4, temp_f2_5, temp_f3;
    s32 temp_cr0_eq;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r20;
    s32 temp_r3;
    s32 temp_r4_2;
    s32 temp_r7;
    void *temp_r4;
    void *var_r3;

    temp_r4 = M2C_FIELD(arg0, void ***, 4)[fn_801E866C(arg1)];
    if (temp_r4 != NULL) {
        fn_8001DF08(M2C_FIELD(temp_r4, s32 *, 4), M2C_FIELD(temp_r4, s32 *, 0));
    }
    temp_r28 = M2C_FIELD(arg0, void ***, 0x98);
    fn_8016FD9C((f32 *)((u8 *)arg0 + 0x38), temp_r28);
    temp_r21 = ((UiLayout8016 *)temp_r28)->lookup(base + 0x64C);
    temp_r22 = ((UiLayout8016 *)temp_r28)->lookupDraw(base + 0x65C);
    temp_r23 = ((UiLayout8016 *)temp_r28)->lookupDraw(base + 0x66C);
    temp_r24 = ((UiLayout8016 *)temp_r28)->lookupDraw(base + 0x678);
    temp_f17 = lbl_805619CC;
    var_r25 = 0;
    sp150 = (f64) lbl_805619F0;
    var_r20 = 0;
    sp138 = (f64) lbl_80561988;
    temp_f16 = lbl_805619C8;
    sp130 = (f64) lbl_805619D0;
    temp_f18 = lbl_805619B0;
    sp148 = (f64) lbl_805619E8;
    temp_f20 = lbl_80561984;
    sp158 = (f64) lbl_805619F8;
    temp_f21 = lbl_805619D4;
    temp_f22 = lbl_805619E0;
    sp140 = (f64) lbl_805619E4;
    goto outer_check;
outer_body: {
        fn_8016FD60(&s8, temp_r22);
        fn_8014C920(&s28, temp_r21);
        temp_f14 = M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r25), f32 *, 8);
        temp_f23 = fn_8016FD58() - temp_f14;
        temp_r0 = M2C_FIELD(arg0, s32 *, 0x5C);
        s8.y += (f32) var_r20;
        s28.y += (f32) var_r20;
        if (var_r25 > temp_r0) {
            s8.color = 0x66FFFFFF;
        }
        fn_80147940(temp_r28, &s8, base + 0x684, 0);
        if (var_r25 < M2C_FIELD(arg0, s32 *, 0x5C) || M2C_FIELD(arg0, u8 *, 0x78) != 0) {
            var_r26 = 0;
            if ((s32) *(u8 *)fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r25) != 0) {
                var_r26 = (s32) (temp_f23 / temp_f16);
                if (var_r26 > (s32) M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r25), s32 *, 4)) {
                    var_r26 = M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r25), s32 *, 4);
                }
                temp_f24 = temp_f17 + (temp_f16 * (f32) M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r25), s32 *, 4));
                temp_f25 = (f32) sp130 + (temp_f16 * (f32) M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r25), s32 *, 4));
                if (temp_f23 < (temp_f25 + (temp_f18 + temp_f24))) {
                    startX = s8.x;
                    startY = s8.y;
                    temp_f3 = (f32) M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r25), s32 *, 4);
                    temp_f1 = M2C_FIELD(temp_r24, f32 *, 4);
                    temp_f29 = M2C_FIELD(temp_r24, f32 *, 8);
                    temp_f28 = temp_f1 - (s8.width * (temp_f3 * (f32) sp138));
                    temp_f30 = M2C_FIELD(((UiLayout8016 *)temp_r28)->lookup(base + 0x690), f32 *, 4);
                    temp_f31 = M2C_FIELD(((UiLayout8016 *)temp_r28)->lookup(base + 0x690), f32 *, 8);
                    var_r27 = 0;
                    goto inner_check;
inner_body: {
                        fn_8016FD60(&s48, temp_r24);
                        if (temp_f23 < temp_f24) {
                            temp_f14 = fn_8014C8B4(temp_f16 * (f32) var_r27, temp_f17 + (temp_f16 * (f32) var_r27), lbl_80561980, lbl_80561984, temp_f23);
                            s48.x = fn_80144C80(startX, temp_f28 + ((f32) var_r27 * s48.width), fn_80144BD8(temp_f14));
                            s48.y = fn_80144C80(startY, temp_f29, fn_80144BD8(temp_f14));
                            s48.color &= 0xFFFFFF;
s48.color |= ((s32) (temp_f21 * temp_f14) << 0x18);
                        } else {
                            temp_f1_2 = temp_f18 + temp_f24;
                            if ((temp_f23 > (temp_f1_2 + (temp_f16 * (f32) var_r27))) && ((temp_f23 - temp_f1_2) < temp_f25)) {
                                temp_f19 = (temp_f23 - temp_f24) - temp_f18;
                                if (temp_f19 > (temp_f16 * (f32) var_r27)) {
                                    temp_f14 = fn_8014C8B4(lbl_80561980, lbl_805619D0, lbl_80561980, lbl_80561984, temp_f19 - (temp_f16 * (f32) var_r27));
                                    temp_f19 = fn_8014C8B4(lbl_80561980, lbl_805619CC, lbl_80561980, lbl_80561984, temp_f19 - (temp_f16 * (f32) var_r27));
                                    s48.x = fn_80144C80(temp_f28 + ((f32) var_r27 * s48.width), temp_f30, temp_f14);
                                    s48.y = fn_80144C80(temp_f29, temp_f31, temp_f14);
                                    s48.color &= 0xFFFFFF;
s48.color |= ((s32) (temp_f21 * (temp_f20 - temp_f19)) << 0x18);
                                }
                            } else {
                                s48.color = -1;
                                s48.y = temp_f29;
                                s48.x = temp_f28 + ((f32) var_r27 * s48.width);
                            }
                        }
                        fn_80147940(temp_r28, &s48, base + 0x684, 0);
                        var_r27 += 1;
                    }
inner_check:
                    if (var_r27 < M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r25), s32 *, 4)) goto inner_body;
                }
                if (temp_f23 < temp_f17) {
                    temp_f1_3 = fn_8014C8B4(lbl_80561980, temp_f17, lbl_80561980, lbl_80561984, temp_f23);
                    s28.width = fn_80144C80(lbl_805619D8, s28.width, temp_f1_3);
                    s28.color &= 0xFFFFFF;
s28.color |= ((s32) (temp_f21 * temp_f1_3) << 0x18);
                }
            }
            fn_80147230(&s28, &lbl_8055A264, var_r26);
        } else if ((var_r25 == M2C_FIELD(arg0, s32 *, 0x5C)) && ((s32) M2C_FIELD(arg0, u8 *, 0x79) == 0)) {
            fn_8016FD60(&s64, &s8);
            temp_f19 = fn_8014C8B4(lbl_80561980, lbl_805619DC, lbl_80561980, lbl_80561984, M2C_FIELD(arg0, f32 *, 0x58));
            s64.width = fn_80144C80(s8.width, temp_f22 * s8.width, temp_f19);
            s64.height = fn_80144C80(s8.height, temp_f22 * s8.height, temp_f19);
            s64.x = fn_80144C80(s8.x, s8.x - (((temp_f22 * s8.width) - s8.width) * (f32) sp138), temp_f19);
            s64.y = fn_80144C80(s8.y, s8.y - (((temp_f22 * s8.height) - s8.height) * (f32) sp138), temp_f19);
            temp_r7 = (s32) (temp_f21 * (temp_f20 - temp_f19));
            s64.color &= 0xFFFFFF;
s64.color |= (temp_r7 << 0x18);
            fn_80147940(temp_r28, &s64, base + 0x684, 0);
        }
        if (temp_f23 < (f32) sp140) {
            temp_r27 = ((UiLayout8016 *)temp_r28)->lookup(base + 0x6A0);
            if ((s32) *(u8 *)fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r25) != 0) {
                var_r3 = ((UiLayout8016 *)temp_r28)->lookup(base + 0x6AC);
            } else {
                var_r3 = ((UiLayout8016 *)temp_r28)->lookup(base + 0x6B8);
            }
            if (var_r3 != NULL) {
                fn_8014C920(&s80, var_r3);
                if (temp_f23 < (f32) sp148) {
                    if (((s32 (*)(s32))fn_80141FA0)(M2C_FIELD(arg0, s32 *, 0x8C)) == 0) {
                        fn_80142B60(M2C_FIELD(arg0, s32 *, 0x8C));
                    }
                    temp_f1_5 = fn_8014C8B4(lbl_80561980, lbl_805619E8, lbl_80561980, lbl_80561984, temp_f23);
                    s80.width = fn_80144C80(lbl_805619EC, s80.width, temp_f1_5);
                    s80.color &= 0xFFFFFF;
s80.color |= ((s32) (temp_f21 * temp_f1_5) << 0x18);
                } else if (temp_f23 > (f32) sp150) {
                    temp_f1 = fn_8014C8B4(lbl_805619F4, (f32)sp150, lbl_80561980, lbl_80561984, temp_f23);
                    s80.color &= 0xFFFFFF;
                    s80.color |= (s32)(temp_f21 * (temp_f20 - temp_f1)) << 24;
                }
                fn_801476C4(&s80);
            }
            if ((temp_f23 > (f32) sp158) && (temp_r27 != NULL) && ((s32) M2C_FIELD(arg0, u8 *, 0x79) == 0)) {
                fn_8014C920(&sA0, temp_r27);
                temp_f14 = temp_f23 - (f32) sp158;
                if (temp_f14 < (f32) sp148) {
                    if (((s32 (*)(s32))fn_80141FA0)(M2C_FIELD(arg0, s32 *, 0x8C)) == 0) {
                        fn_80142B60(M2C_FIELD(arg0, s32 *, 0x8C));
                    }
                    temp_f1_6 = fn_8014C8B4(lbl_80561980, lbl_805619E8, lbl_80561980, lbl_80561984, temp_f14);
                    sA0.width = fn_80144C80(lbl_805619EC, sA0.width, temp_f1_6);
                    sA0.color &= 0xFFFFFF;
sA0.color |= ((s32) (temp_f21 * temp_f1_6) << 0x18);
                } else if (temp_f14 > (f32) sp150) {
                    temp_f1_7 = fn_8014C8B4((f32) sp150, (f32) sp158, lbl_80561980, lbl_80561984, temp_f14);
                    sA0.width = fn_80144C80(sA0.width, lbl_805619EC, temp_f1_7);
                    sA0.color &= 0xFFFFFF;
sA0.color |= ((s32) (temp_f21 * (temp_f20 - temp_f1_7)) << 0x18);
                }
                fn_801476C4(&sA0);
            }
        }
        var_r20 += 0x28;
        var_r25 += 1;
    }
outer_check:
    if (var_r25 < M2C_FIELD(arg0, s32 *, 0x68)) goto outer_body;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x79) == 0) {
        fn_8016FD60(&sC0, temp_r23);
        temp_r4_2 = M2C_FIELD(arg0, s32 *, 0x5C);
        if (temp_r4_2 > 0) {
            temp_f14 = M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), temp_r4_2 - 1), f32 *, 8);
            temp_f1 = fn_8014C8B4(lbl_80561980, lbl_805619E8, lbl_80561980, lbl_80561984, fn_8016FD58() - temp_f14);
            temp_r20 = M2C_FIELD(arg0, s32 *, 0x5C);
            temp_f2 = M2C_FIELD(temp_r23, f32 *, 8);
            sC0.y = fn_80144C80(temp_f2 + (f32) ((temp_r20 - 1) * 0x28), temp_f2 + (f32) (temp_r20 * 0x28), fn_80144BD8(temp_f1));
        }
        fn_80147940(temp_r28, &sC0, base + 0x6CC, 0);
    }
    if (fn_802C9A58() != 0) {
        var_r21 = ((UiLayout8016 *)temp_r28)->lookupDraw(base + 0x6D8);
    } else {
        var_r21 = ((UiLayout8016 *)temp_r28)->lookupDraw(base + 0x6E8);
    }
    temp_r22_2 = ((UiLayout8016 *)temp_r28)->lookupDraw(base + 0x6A0);
    fn_8016FD60(&sDC, var_r21);
    var_r20 = M2C_FIELD(arg0, s32 *, 0x5C);
    if ((var_r20 > 0) && ((s32) M2C_FIELD(arg0, u8 *, 0x79) == 0)) {
        temp_f15 = lbl_805619FC;
        temp_f14 = M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r20 - 1), f32 *, 8);
        temp_f15_2 = (fn_8016FD58() - temp_f14) - temp_f15;
        temp_f14 = M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r20 - 1), f32 *, 8);
        if ((fn_8016FD58() - temp_f14) > lbl_80561980) {
                if (temp_f15_2 <= lbl_80561A00) {
                var_r20 -= 1;
            }
        }
        if (temp_f15_2 >= lbl_80561980) {
            fn_8016FD60(&sF8, temp_r22_2);
                if (temp_f15_2 <= lbl_805619B4) {
                if ((s32) *(u8 *)fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C) - 1) != 0) {
                    if (((s32 (*)(s32))fn_80141FA0)(M2C_FIELD(arg0, s32 *, 0x90)) == 0) {
                        fn_80142B60(M2C_FIELD(arg0, s32 *, 0x90));
                    }
                } else if (((s32 (*)(s32))fn_80141FA0)(M2C_FIELD(arg0, s32 *, 0x94)) == 0) {
                    fn_80142B60(M2C_FIELD(arg0, s32 *, 0x94));
                }
                temp_f1_8 = fn_8014C8B4(lbl_80561980, lbl_805619B4, lbl_80561980, lbl_80561984, temp_f15_2);
                temp_r3 = (s32) (lbl_805619D4 * temp_f1_8);
                sF8.color &= 0xFFFFFF;
sF8.color |= (temp_r3 << 0x18);
                temp_f2_2 = M2C_FIELD(temp_r22_2, f32 *, 0x10);
                sF8.width = fn_80144C80(lbl_805619EC * temp_f2_2, temp_f2_2, temp_f1_8);
                temp_f2_3 = M2C_FIELD(temp_r22_2, f32 *, 0x14);
                sF8.height = fn_80144C80(lbl_805619EC * temp_f2_3, temp_f2_3, temp_f1_8);
                temp_f2_4 = M2C_FIELD(temp_r22_2, f32 *, 4);
                sF8.x = fn_80144C80(temp_f2_4 - (lbl_805619EC * M2C_FIELD(temp_r22_2, f32 *, 0x10) * lbl_80561988), temp_f2_4, temp_f1_8);
                temp_f2_5 = M2C_FIELD(temp_r22_2, f32 *, 8);
                sF8.y = fn_80144C80(temp_f2_5 - (lbl_805619EC * M2C_FIELD(temp_r22_2, f32 *, 0x14) * lbl_80561988), temp_f2_5, temp_f1_8);
            }
            if (temp_f15_2 > lbl_80561A04) {
                temp_f14 = fn_8014C8B4(lbl_80561A04, lbl_805619FC, lbl_80561980, lbl_80561984, temp_f15_2);
                sF8.x = fn_80144C80(M2C_FIELD(temp_r22_2, f32 *, 4), M2C_FIELD(var_r21, f32 *, 4), fn_80144BD8(temp_f14));
                sF8.y = fn_80144C80(M2C_FIELD(temp_r22_2, f32 *, 8), M2C_FIELD(var_r21, f32 *, 8), fn_80144BD8(temp_f14));
                temp_f1 = fn_8014C8B4(lbl_805619F4,lbl_80561A08,lbl_80561980,lbl_80561984,temp_f15_2);
                sDC.color &= 0xFFFFFF;
                sDC.color |= (s32)(lbl_805619D4 * (lbl_80561984 - temp_f1)) << 24;
            }
            temp_r0 = M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)), s32 *, 4);
            switch (temp_r0) {                      /* switch 1; irregular */
            case 15:                                /* switch 1 */
                fn_80147940(temp_r28, &sF8, base + 0x6F4, 0);
                break;
            case 10:                                /* switch 1 */
                fn_80147940(temp_r28, &sF8, base + 0x700, 0);
                break;
            case 5:                                 /* switch 1 */
                fn_80147940(temp_r28, &sF8, base + 0x70C, 0);
                break;
            }
        }
    }
    if ((s32) M2C_FIELD(arg0, u8 *, 0x79) == 0) {
        temp_r0_2 = M2C_FIELD(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), var_r20), s32 *, 4);
        switch (temp_r0_2) {                        /* switch 2; irregular */
        case 15:                                    /* switch 2 */
            fn_80147940(temp_r28, &sDC, base + 0x6F4, 0);
            break;
        case 10:                                    /* switch 2 */
            fn_80147940(temp_r28, &sDC, base + 0x700, 0);
            break;
        case 5:                                     /* switch 2 */
            fn_80147940(temp_r28, &sDC, base + 0x70C, 0);
            break;
        }
        fn_8014C72C(temp_r28, base + 0x718);
    }
}
#pragma pop
#pragma cplusplus reset

#pragma cplusplus reset

#pragma scheduling on
extern f32 fn_8016FD58(void);
/* Getter for the current game time in seconds (lbl_8055E3C8). */
f32 fn_8016FD58(void) {
    return lbl_8055E3C8;
}

/* Copy a 0x1C-byte UI draw record (4 ints, 2 floats, 1 int) from src to dst,
   reading the source words through volatile pointers. */
void fn_8016FD60(void *dst, void *srcRecord) {
    s32 word6;
    s32 word3, word2, word1, word0;
    f32 float1, float0;
    volatile s32 *srcWords = (volatile s32 *)srcRecord;
    volatile f32 *srcFloats = (volatile f32 *)((u8 *)srcRecord + 0x10);
    word0 = srcWords[0]; word1 = srcWords[1]; word2 = srcWords[2]; word3 = srcWords[3];
    float0 = srcFloats[0]; float1 = srcFloats[1]; word6 = srcWords[6];
    *(s32 *)dst = word0;
    *((s32 *)dst + 1) = word1;
    *((s32 *)dst + 2) = word2;
    *((s32 *)dst + 3) = word3;
    *(f32 *)((u8 *)dst + 0x10) = float0;
    *(f32 *)((u8 *)dst + 0x14) = float1;
    *((s32 *)dst + 6) = word6;
}

/* Clamp the stopwatch time at *timeSeconds to >= 0, format it to tenths of a second,
 * bind "stop_watch_art" to "stop_watch_artset", and update the "timer" UI text element. */
void fn_8016FD9C(const f32 *timeSeconds, void *uiElement) {
    char formattedTime[0x20];
    f32 rawTime = *timeSeconds;
    f32 clampedTime = (0.0f > rawTime) ? 0.0f : rawTime;
    fn_80130978(formattedTime, 0x20, clampedTime);
    fn_8014784C(uiElement, lbl_80330B7C, lbl_80330B8C, 0);
    fn_801475D0(uiElement, (const char *)&lbl_8055A248, (const char *)&lbl_8055A268, formattedTime);
}
#pragma cplusplus on
extern "C" void fn_8016FE1C(void *obj) {
    /* C-linkage adapter: dispatch virtual slot v4C() at vtable offset 0x4C on a TObj4C object. */
    ((TObj4C *)obj)->v4C();
}

extern f32 lbl_80561980, lbl_80561984, lbl_805619A4, lbl_80561A0C, lbl_805619D0, lbl_8055E3C8;
extern "C" void MRModel_SetInstanceTransform(s32, void *);
extern "C" void fn_802C9900(void);
extern "C" void fn_802C9904(void);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_8016FE2C(void *arg0, s32 arg1) {
    extern float lbl_80561980;
    extern float lbl_80561984;
    extern float lbl_805619A4;
    extern float lbl_805619D0;
    extern float lbl_80561A0C;
    extern float lbl_8055E3C8;
    extern void MRModel_SetInstanceTransform(s32, void *);
    extern void fn_802C9900(void);
    extern void fn_802C9904(void);
    f32 v3;
    f32 v2;
    f32 v0;
    f32 v1;
    f32 v4;
    struct { void *p; } selfH; void *&self = selfH.p;
    struct { s32 v; } iH; s32 &i = iH.v;
    struct { s32 v; } jH; s32 &j = jH.v;
    struct { u32 v; } suboffH; u32 &suboff = suboffH.v;
    struct { u8 *p; } entryH; u8 *&entry = entryH.p;
    struct { long v; } offsetH; long &offset = offsetH.v;
    f32 v;
    f32 t;
    register u8 *item;
    self = arg0;
    i = 0;
    j = 0;
    suboff = 0;
    entry = 0;
    offset = 0;
    v0 = lbl_80561980;
    v1 = lbl_80561984;
    v2 = lbl_805619A4;
    v3 = lbl_80561A0C;
    v4 = lbl_805619D0;
    goto outer_check;
outer_body:
    entry = *(u8 **)*(void **)((u8 *)self + 0x48) + offset;
    if (*(u8 *)(entry + 9) != 0) {
        j = 0;
        suboff = 0;
        goto first_check;
first_body:
        item = *(u8 **)*(void **)entry + suboff;
        if (*(s32 *)(item + 0xC) == 1) {
            MRModel_SetInstanceTransform(*(s32 *)item, item + 0x14);
        }
        suboff += 0x44;
        j += 1;
first_check:
        if (j < *(s32 *)((u8 *)*(void **)entry + 4)) {
            goto first_body;
        }
        goto outer_inc;
    }
    if (*(u8 *)(entry + 9) != 0) {
        goto outer_inc;
    }
    t = lbl_8055E3C8 - *(f32 *)(entry + 0xC);
    if (t < v4) {
        v = (t - v0) / v4;
        if (v1 < v) {
            v = v1;
        }
        v = v > v0 ? v : v0;
        t = v1 + v * v2;
        if (t > v3) {
            fn_802C9900();
            j = 0;
            suboff = 0;
            goto second_check;
second_body:
            item = *(u8 **)*(void **)entry + suboff;
            if (*(s32 *)(item + 0xC) == 1) {
                MRModel_SetInstanceTransform(*(s32 *)item, item + 0x14);
            }
            suboff += 0x44;
            j += 1;
second_check:
            if (j < *(s32 *)((u8 *)*(void **)entry + 4)) {
                goto second_body;
            }
            fn_802C9904();
        }
    }
outer_inc:
    offset += (unsigned)0x14;
    ++i;
outer_check:
    if (i < *(s32 *)((u8 *)self + 0x6C)) {
        goto outer_body;
    }
}
#pragma pop

#pragma cplusplus reset
void fn_8016FF98(void *container) {
    /* Call fn_8016A438 if none of the container's items have their flag set at +8. */
    s32 itemOffset;
    s32 foundActiveItem;
    s32 itemCount = *(s32 *)((u8 *)container + 8);
    s32 i;
    foundActiveItem = 0;
    itemOffset = 0;
    for (i = 0; i < itemCount; i++, itemOffset += 4) {
        void **items = *(void ***)((u8 *)container + 4);
        void *item = *(void **)((u8 *)items + itemOffset);
        if (*(u8 *)((u8 *)item + 8) != 0) {
            foundActiveItem = 1;
            break;
        }
    }
    if (foundActiveItem == 0) {
        fn_8016A438();
    }
}

s32 fn_8016FFE4(void) { return 0x1408; /* fixed constant 0x1408 (5128) */ }

extern void *fn_8000AC38(void);
extern char lbl_80330DF4[];
__declspec(section ".sdata") extern char lbl_8055A270[];
__declspec(section ".sdata") extern char lbl_8055A278[];
extern float lbl_80561980;
#pragma push
#pragma processor 750
#pragma ppc_psq_save off
#pragma scheduling invalid_target
struct Frame_8016FFEC {
    float f8, fC, f10, f14, f18, f1C;
    float ret[2];
    float d28[2];
    float f30, f34, f38, f3C;
    char sp40[16];
    char stk50[16];
    char sp60[16];
    float pts[6];
    char query[56];
};
#pragma cplusplus on
extern "C" double fn_8002F234(float, float, float, float, float);
extern "C" void fn_801352B8(void *);
extern "C" void fn_8013530C(void *, int, float, float, float);
extern "C" void fn_801355C0(void *, void *, int, void *, int);
extern "C" int fn_80135D60(void *, int);
extern "C" void *fn_80156A40(void);
extern "C" void fn_801B7C8C(void *, float *, float *);
extern "C" char lbl_80330E04[];
extern "C" float lbl_80561A10;
#pragma cplusplus on
extern "C" int fn_8016FFEC(void *arg0, void *arg1, int arg2) {
struct Frame8016FFEC {
    float f8, fC, f10, f14, f18, f1C;
    float ret[2];
    float d28[2];
    float f30, f34, f38, f3C;
    char sp40[16];
    char stk50[16];
    char sp60[16];
    float pts[3][2];
    char query[56];
};
struct Mgr {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void *make(void *);
};
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual float getf(void *, float);
    virtual void v9();
    virtual int test(void *, int, float, float, float);
    virtual void v11(); virtual void v12();
    virtual unsigned long long get2(void *);
};
struct Helper {
    virtual void h0();
    virtual int h1(int);
};
struct Frame8016FFEC s;
void *obj;
int i;
float *p;
int idx;
int o1, o2;
float sqf;
float inv;
float nx;
void *manager;
manager = *(void **)((char *)fn_8000AC38() + 0x20);
if (manager != 0) {
fn_801345D8(s.sp60, 0x10, lbl_80330DF4, arg2);
obj = ((Mgr *)manager)->make(s.sp60);
if (obj != 0) {
p = (float *)s.pts;
i = 0;
s.f38 = lbl_80561980;
s.f3C = lbl_80561980;
s.f30 = lbl_80561980;
s.f34 = lbl_80561980;
do {
fn_801345D8(s.sp40, 0x10, lbl_8055A270, i);
{
unsigned long long xy = ((Obj *)obj)->get2(s.sp40);
((unsigned int *)s.ret)[0] = (unsigned int)(xy >> 32);
((unsigned int *)s.ret)[1] = (unsigned int)xy;
}
{
float b = s.ret[1];
float a = s.ret[0];
p[0] = a;
p[1] = b;
}
p += 2;
i += 1;
} while (i < 3);
idx = 2;
{
float dy20 = -(s.pts[0][1] - s.pts[2][1]);
float dx20 = s.pts[2][0] - s.pts[0][0];
float dx01 = s.pts[0][0] - s.pts[1][0];
float dy01 = s.pts[0][1] - s.pts[1][1];
float dxsq = dx20 * dx20;
float len1 = dxsq + dy20 * dy20;
float len2 = dx01 * dx01 + dy01 * dy01;
s.f18 = dx20;
s.f1C = dy20;
s.f10 = dx01;
s.f14 = dy01;
if (len2 > len1) {
    len1 = len2;
    idx = 0;
}
{
    float g = s.pts[1][1] - s.pts[2][1];
    float h = s.pts[1][0] - s.pts[2][0];
    s.f14 = g;
    s.f10 = h;
    if (h * h + g * g > len1) {
        idx = 1;
    }
}
}
o1 = (idx + 1) % 3;
o2 = idx;
{
    float fraction = lbl_80561988;
    float nextY = s.pts[o1][1];
    float curY = s.pts[o2][1];
    float nextX = s.pts[o1][0];
    float curX = s.pts[o2][0];
    float deltaX = fraction * (nextX - curX);
    float deltaY = fraction * (nextY - curY);
    o1 = (idx + 2) % 3;
    s.fC = curY + deltaY;
    s.f8 = curX + deltaX;
}
{
double dd = *(double *)&s.f8;
*(double *)s.d28 = dd;
{
float dx = s.pts[o1][0] - s.d28[0];
float dy = s.pts[o1][1] - *((float *)&s.d28 + 1);
s.f38 = s.d28[0];
s.f3C = *((float *)&s.d28 + 1);
s.f30 = dx;
s.f34 = dy;
sqf = (float)((double (*)(float))fn_8002F234)(dx * dx + dy * dy);
}
}
inv = lbl_80561984 / sqf;
nx = s.f30 * inv;
s.f30 = nx;
s.f34 = s.f34 * inv;
if (((Obj *)obj)->test(lbl_80330E04, 1, nx, inv, sqf) != 0) {
fn_801352B8(s.query);
fn_80135D60(s.query, ((Helper *)fn_80156A40())->h1(0));
{
*(void **)s.stk50 = 0;
*(int *)(s.stk50 + 8) = 0x2710;
*(float *)(s.stk50 + 4) = lbl_80561980;
fn_801355C0(s.query, &s.f38, 0, s.stk50, 0);
{
float tt = *(float *)(s.stk50 + 4);
void *nd = *(void **)s.stk50;
float v0 = *(float *)nd;
float w0 = *(float *)(*(void **)((char *)nd + 0x14));
s.f38 = v0 + tt * (w0 - v0);
v0 = *((float *)nd + 1);
w0 = *((float *)(*(void **)((char *)nd + 0x14)) + 1);
s.f3C = v0 + tt * (w0 - v0);
v0 = *((float *)nd + 2);
s.f30 = v0 + tt * (*((float *)(*(void **)((char *)nd + 0x14)) + 2) - v0);
w0 = *((float *)nd + 3);
s.f34 = w0 + tt * (*((float *)(*(void **)((char *)nd + 0x14)) + 3) - w0);
sqf = (float)((double (*)(float))fn_8002F234)(s.f30 * s.f30 + s.f34 * s.f34);
}
}
inv = lbl_80561984 / sqf;
nx = s.f30 * inv;
s.f30 = nx;
s.f34 = s.f34 * inv;
fn_8013530C(s.query, -1, nx, inv, sqf);
}
fn_801B7C8C(arg1, &s.f38, &s.f30);
{
float sc = lbl_80561A10 * ((Obj *)obj)->getf(lbl_8055A278, lbl_80561980);
*(float *)((char *)arg1 + 0x30) = *(float *)((char *)arg1 + 0x18) * sc;
*(float *)((char *)arg1 + 0x34) = *(float *)((char *)arg1 + 0x1C) * sc;
*(float *)((char *)arg1 + 0x38) = *(float *)((char *)arg1 + 0x20) * sc;
}
return 1;
}
}
return 0;
}
extern "C" s32 fn_80009C84(void);
extern "C" u8 *fn_80131234(const char *);
extern "C" s32 fn_80141FA0(void);
extern "C" void fn_80142B60(s32);
extern "C" void fn_80144C54(s32);
extern "C" s32 fn_8015A404(s32);
extern "C" s32 fn_801609C4(s32);
extern "C" s32 fn_80161C38(void);
extern "C" s32 fn_8016A30C(void);
extern "C" s32 fn_8016A780(void *, s32);
extern "C" s32 fn_8016A878(void *);
extern "C" void refreshRingSetMapMarker(void *);
extern "C" void resetChallengeSetEntry(void *, s32);
extern "C" f32 fn_8016FD58(void);
extern "C" void fn_80170E98(void *, void *, s32);
extern "C" s32 fn_80179650(void);
extern "C" f32 fn_801B306C(void);
extern "C" void fn_801CB5DC(s32, s32, s32);
extern "C" void fn_801CB648(s32, s32, f32);
extern "C" u8 fn_80170E90(void *);
extern "C" s32 fn_80170E88(void *);
extern "C" f32 fn_80170E80(f32 *);
extern "C" s32 fn_80170E78(void *);
extern "C" void fn_80170DA8(void *, void *);
extern "C" char lbl_803306D0[];
extern "C" u8 lbl_8055A20C;
extern "C" f32 lbl_8055E3C8;
extern "C" f32 lbl_80561980;
extern "C" f32 lbl_80561984;
extern "C" f32 lbl_805619A8;
extern "C" f32 lbl_805619AC;
extern "C" f32 lbl_805619B0;
extern "C" f32 lbl_805619C8;
extern "C" f32 lbl_805619CC;
extern "C" f32 lbl_805619D0;
extern "C" f32 lbl_805619E0;
extern "C" f32 lbl_80561A14;
extern "C" f32 lbl_80561A18;
extern "C" f32 lbl_80561A1C;
#pragma cplusplus on
extern "C" void fn_80170414(void *arg0) {
    u32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f2;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f31;
    f32 var_f29;
    f32 var_f30;
    f32 var_f4;
    f32 var_f7;
    s32 *temp_r3_4;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r22;
    s32 temp_r22_2;
    s32 temp_r23;
    s32 temp_r23_2;
    s32 temp_r23_3;
    s32 temp_r24;
    s32 temp_r3_10;
    s32 temp_r3_11;
    s32 temp_r3_3;
    s32 temp_r3_8;
    s32 temp_r3_9;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_6;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r8;
    s32 var_r0;
    s32 var_r26;
    s32 var_r27;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    u8 *var_r3;
    u8 *var_r3_2;
    u8 *var_r3_3;
    u8 *var_r4;
    u8 *var_r4_2;
    u8 *var_r4_3;
    u8 *var_r6;
    u8 *var_r6_2;
    u8 *var_r6_3;
    u8 *var_r6_4;
    u8 *var_r6_5;
    u8 *var_r6_6;
    u8 temp_r3_5;
    u8 temp_r3_6;
    u8 temp_r3_7;
    u8 temp_r4_3;
    u8 temp_r4_4;
    u8 temp_r4_5;
    void *temp_r3;
    void *temp_r3_12;
    void *temp_r3_13;
    void *temp_r3_2;
    void *temp_r4_7;
    void *temp_r7;

    temp_f1 = fn_801B306C();
    if (((s32) M2C_FIELD(arg0, u8 *, 0xA8) == 0) && (temp_f1 < lbl_805619A8)) {
        M2C_FIELD(arg0, u8 *, 0xA8) = 1U;
        if (((void *) M2C_FIELD(arg0, void **, 0xA4) != 0) && (fn_80161C38() == 0) && (fn_80179650() == 1) && (fn_80009C84() == 0)) {
            temp_r3 = M2C_FIELD(arg0, void **, 0xA4);
            M2C_FIELD(temp_r3, s8 *, 0x49) = 1;
            M2C_FIELD(temp_r3, s8 *, 0x4B) = 0;
            M2C_FIELD(temp_r3, s8 *, 0x4A) = 0;
        }
    }
    temp_f29 = lbl_8055E3C8;
    if ((temp_f29 > ((TObj4C *)arg0)->d12()) && ((s32) M2C_FIELD(arg0, s32 *, 0x68) > 0)) {
        temp_f29_2 = lbl_80561A14;
        var_r26 = 0;
        temp_f31 = lbl_80561980;
        var_r27 = 0;
loop_83:
        if (var_r26 < (s32) M2C_FIELD(arg0, s32 *, 8)) {
            if (((TObj4C *)arg0)->d7() == 0) {
                temp_r3_2 = *(void **)(*(u8 **)((u8 *)arg0 + 4) + var_r27);
                if ((s32) M2C_FIELD(temp_r3_2, u8 *, 8) != 0) {
                    M2C_FIELD(temp_r3_2, f32 *, 0xC) = (f32) (M2C_FIELD(temp_r3_2, f32 *, 0xC) + temp_f29_2);
                }
                temp_r23 = *(s32 *)(*(u8 **)((u8 *)arg0 + 4) + var_r27);
                fn_80170E98((u8 *)arg0 + 0x30, &sp8, 0x1E);
                if ((fn_80170E90((void *)temp_r23) == 0) && ((s32) M2C_FIELD(arg0, u8 *, 0x79) == 0)) {
                    temp_r22 = fn_80170E88((void *)temp_r23);
                    temp_f30 = fn_80170E80((f32 *)((u8 *)arg0 + 0x38));
                    *(f32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 3) = temp_f30;
                    fn_80170E78((void *)temp_r22);
                    temp_r23_2 = fn_8016A30C();
                    temp_r3_3 = fn_8016A780(&sp8, fn_80170E78((void *)temp_r22));
                    if ((temp_r3_3 == 0) && ((s32) M2C_FIELD(arg0, u8 *, 0x7A) == 0)) {
                        M2C_FIELD(arg0, u8 *, 0x7A) = 1U;
                        fn_8016DFB8((u8 *)arg0 + 0x30);
                    }
                    if (((s32) M2C_FIELD(arg0, u8 *, 0x7A) != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x54) == -1)) {
                        refreshRingSetMapMarker((u8 *)arg0 + 0x30);
                    }
                    if (((temp_r23_2 > 0) || (temp_r3_3 == fn_8016A878(&sp8)) || ((temp_r3_3 > 0) && (fn_8015A404(temp_r22) > 1))) && ((s32) M2C_FIELD(arg0, u8 *, 0x7A) != 0)) {
                        temp_f30_2 = fn_8016FD58();
                        *(f32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 2) = temp_f30_2;
                        resetChallengeSetEntry((u8 *)arg0 + 0x30, M2C_FIELD(arg0, s32 *, 0x5C));
                        if (temp_r23_2 > 0) {
                            *(s8 *)fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) = 1;
                            M2C_FIELD(arg0, s32 *, 0x64) = (s32) M2C_FIELD(arg0, s32 *, 0x60);
                            temp_r5 = *(s32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 1);
                            temp_r0 = M2C_FIELD(arg0, s32 *, 0x74) + 1;
                            M2C_FIELD(arg0, s32 *, 0x74) = temp_r0;
                            M2C_FIELD(arg0, s32 *, 0x60) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) + temp_r5);
                            if (temp_r0 > 2) {
                                M2C_FIELD(arg0, s32 *, 0x74) = 2;
                            }
                            if ((s32) M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
                                if (fn_80141FA0() != 0) {
                                    fn_80144C54(M2C_FIELD(arg0, s32 *, 0x7C));
                                }
                                fn_80142B60(M2C_FIELD(arg0, s32 *, 0x7C));
                            }
                            if ((s32) M2C_FIELD(arg0, s32 *, 0x80) != 0) {
                                if (fn_80141FA0() != 0) {
                                    fn_80144C54(M2C_FIELD(arg0, s32 *, 0x80));
                                }
                                fn_80142B60(M2C_FIELD(arg0, s32 *, 0x80));
                            }
                            if (((*(s32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 1) == 0xA) || (*(s32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 1) == 0xF)) && ((void *) M2C_FIELD(arg0, void **, 0x84) != 0)) {
                                fn_80142B60(M2C_FIELD(arg0, s32 *, 0x84));
                            }
                        } else {
                            temp_r0_2 = M2C_FIELD(arg0, s32 *, 0x74) - 1;
                            M2C_FIELD(arg0, s32 *, 0x74) = temp_r0_2;
                            if (temp_r0_2 < 0) {
                                M2C_FIELD(arg0, s32 *, 0x74) = 0;
                            }
                        }
                        temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
                        if (temp_r4 < (s32) (M2C_FIELD(arg0, s32 *, 0x68) - 1)) {
                            M2C_FIELD(arg0, u8 *, 0x7A) = 0U;
                            M2C_FIELD(arg0, s32 *, 0x5C) = (s32) (temp_r4 + 1);
                            temp_r24 = fn_8016DD98((u8 *)arg0 + 0x30);
                            *(s32 *)(fn_8016DE10(M2C_FIELD(arg0, s32 **, 0x4C), M2C_FIELD(arg0, s32 *, 0x5C)) + 1) = temp_r24;
                            fn_8016E06C((u8 *)arg0 + 0x30);
                        } else {
                            M2C_FIELD(arg0, u8 *, 0x78) = 1U;
                            M2C_FIELD(arg0, u8 *, 0x79) = 1U;
                        }
                    } else {
                        fn_80170DA8((void *)fn_8016E1A4((s32 *)*(void **)((u8 *)arg0 + 0x48), *(s32 *)((u8 *)arg0 + 0x5C)), (void *)temp_r22);
                    }
                } else if ((s32) M2C_FIELD(arg0, s32 *, 0x54) != -1) {
                    fn_8016E118((u8 *)arg0 + 0x30);
                }
            }
            temp_r4_2 = M2C_FIELD(arg0, s32 *, 0x64);
            temp_r3_4 = *(s32 **)(*(u8 **)((u8 *)arg0 + 4) + var_r27);
            if ((s32) *temp_r3_4 != temp_r4_2) {
                *temp_r3_4 = temp_r4_2;
            }
            if (((s32) M2C_FIELD(arg0, u8 *, 0x9C) != 0) && ((s32) M2C_FIELD(arg0, u8 *, 0x79) != 0)) {
                if (M2C_FIELD(arg0, f32 *, 0xA0) < temp_f31) {
                    M2C_FIELD(arg0, f32 *, 0xA0) = (f32) lbl_8055E3C8;
                }
                if ((s32) M2C_FIELD(arg0, u8 *, 0x78) != 0) {
                    var_r3 = fn_80131234(lbl_803306D0 + 0x744);
                    var_r6 = (u8 *)arg0 + 0x15E;
                    var_r5 = 0x14;
loop_59:
                    temp_r4_3 = *var_r3;
                    var_r3 += 1;
                    *var_r6 = temp_r4_3;
                    var_r6 += 1;
                    if ((s8) temp_r4_3 != 0) {
                        var_r5 -= 1;
                        if (var_r5 <= 0) {
                            M2C_FIELD(var_r6, s8 *, -1) = 0;
                        } else {
                            goto loop_59;
                        }
                    }
                    var_r3_2 = fn_80131234(lbl_803306D0 + 0x768);
                    var_r6_2 = (u8 *)arg0 + 0x172;
                    var_r5_2 = 0x14;
loop_63:
                    temp_r4_4 = *var_r3_2;
                    var_r3_2 += 1;
                    *var_r6_2 = temp_r4_4;
                    var_r6_2 += 1;
                    if ((s8) temp_r4_4 != 0) {
                        var_r5_2 -= 1;
                        if (var_r5_2 <= 0) {
                            M2C_FIELD(var_r6_2, s8 *, -1) = 0;
                        } else {
                            goto loop_63;
                        }
                    }
                    var_r6_3 = (u8 *)arg0 + 0x186;
                    var_r4 = (u8 *)&lbl_8055A20C;
                    var_r5_3 = 0x14;
loop_67:
                    temp_r3_5 = *var_r4;
                    var_r4 += 1;
                    *var_r6_3 = temp_r3_5;
                    var_r6_3 += 1;
                    if ((s8) temp_r3_5 != 0) {
                        var_r5_3 -= 1;
                        if (var_r5_3 <= 0) {
                            M2C_FIELD(var_r6_3, s8 *, -1) = 0;
                        } else {
                            goto loop_67;
                        }
                    }
                } else {
                    var_r3_3 = fn_80131234(lbl_803306D0 + 0x78C);
                    var_r6_4 = (u8 *)arg0 + 0x186;
                    var_r5_4 = 0x14;
loop_72:
                    temp_r4_5 = *var_r3_3;
                    var_r3_3 += 1;
                    *var_r6_4 = temp_r4_5;
                    var_r6_4 += 1;
                    if ((s8) temp_r4_5 != 0) {
                        var_r5_4 -= 1;
                        if (var_r5_4 <= 0) {
                            M2C_FIELD(var_r6_4, s8 *, -1) = 0;
                        } else {
                            goto loop_72;
                        }
                    }
                    var_r6_5 = (u8 *)arg0 + 0x15E;
                    var_r4_2 = (u8 *)&lbl_8055A20C;
                    var_r5_5 = 0x14;
loop_76:
                    temp_r3_6 = *var_r4_2;
                    var_r4_2 += 1;
                    *var_r6_5 = temp_r3_6;
                    var_r6_5 += 1;
                    if ((s8) temp_r3_6 != 0) {
                        var_r5_5 -= 1;
                        if (var_r5_5 <= 0) {
                            M2C_FIELD(var_r6_5, s8 *, -1) = 0;
                        } else {
                            goto loop_76;
                        }
                    }
                    var_r6_6 = (u8 *)arg0 + 0x172;
                    var_r4_3 = (u8 *)&lbl_8055A20C;
                    var_r5_6 = 0x14;
loop_80:
                    temp_r3_7 = *var_r4_3;
                    var_r4_3 += 1;
                    *var_r6_6 = temp_r3_7;
                    var_r6_6 += 1;
                    if ((s8) temp_r3_7 != 0) {
                        var_r5_6 -= 1;
                        if (var_r5_6 <= 0) {
                            M2C_FIELD(var_r6_6, s8 *, -1) = 0;
                        } else {
                            goto loop_80;
                        }
                    }
                }
                temp_f0 = M2C_FIELD(arg0, f32 *, 0x38);
                temp_r23_3 = M2C_FIELD(arg0, s32 *, 0x60);
                fn_801CB5DC(var_r26, temp_r23_3 + (s32) temp_f0, fn_801609C4(temp_r23_3 + (s32) temp_f0));
                fn_801CB648(var_r26, 1, M2C_FIELD(arg0, f32 *, 0x38));
                M2C_FIELD(arg0, u8 *, 0x9C) = 0U;
            }
            var_r27 += 4;
            var_r26 += 1;
            goto loop_83;
        }
        if ((s32) M2C_FIELD(arg0, u8 *, 0x79) == 0) {
            temp_f1_2 = M2C_FIELD(arg0, f32 *, 0x58) + lbl_80561A14;
            M2C_FIELD(arg0, f32 *, 0x58) = temp_f1_2;
            if (temp_f1_2 > lbl_80561A18) {
                M2C_FIELD(arg0, f32 *, 0x58) = (f32) lbl_80561980;
            }
            if (*(f32 *)((u8 *)arg0 + 0x38) <= lbl_80561980) {
                *(u8 *)((u8 *)arg0 + 0x79) = 1;
            } else if (!(fn_801B306C() <= lbl_80561980)) {
                *(f32 *)((u8 *)arg0 + 0x38) -= lbl_80561A14;
            }
        }
        temp_r3_8 = M2C_FIELD(arg0, s32 *, 0x5C);
        if (temp_r3_8 > 0) {
            var_r5_7 = temp_r3_8 - 1;
            if ((s32) M2C_FIELD(arg0, u8 *, 0x78) != 0) {
                var_r5_7 = temp_r3_8;
            }
            temp_r6 = M2C_FIELD(arg0, s32 *, 0x60);
            temp_r4_6 = M2C_FIELD(arg0, s32 *, 0x64);
            if (temp_r4_6 < temp_r6) {
                temp_r0_3 = var_r5_7 * 0x10;
                temp_r3_9 = *M2C_FIELD(arg0, s32 **, 0x4C);
                temp_r7 = (u8 *)temp_r3_9 + temp_r0_3;
                if ((s32) *(s32 *)((u8 *)temp_r3_9 + temp_r0_3) != 0) {
                    temp_r8 = M2C_FIELD(temp_r7, s32 *, 4);
                    var_f7 = lbl_80561984;
                    temp_f2 = lbl_805619B0 + (lbl_805619CC + (lbl_805619C8 * (f32) temp_r8)) + (lbl_805619C8 * (f32) (temp_r8 - (temp_r6 - temp_r4_6)));
                    temp_f0_2 = ((lbl_8055E3C8 - M2C_FIELD(temp_r7, f32 *, 8)) - temp_f2) / ((lbl_805619D0 + temp_f2) - temp_f2);
                    if (var_f7 < temp_f0_2) {
                        var_f7 = temp_f0_2;
                    }
                    if (var_f7 > lbl_80561980) {
                        var_f7 = lbl_80561980;
                    }
                    temp_r3_10 = (s32) (lbl_80561980 + (var_f7 * lbl_80561984));
                    if (temp_r3_10 != 0) {
                        temp_r4_7 = M2C_FIELD(arg0, void **, 0x88);
                        temp_r3_11 = M2C_FIELD(arg0, s32 *, 0x64) + temp_r3_10;
                        M2C_FIELD(arg0, s32 *, 0x64) = temp_r3_11;
                        if ((temp_r4_7 != 0) && ((s32) M2C_FIELD(temp_r4_7, u8 *, 0x19) == 0) && (temp_r3_11 != (s32) M2C_FIELD(arg0, s32 *, 0x60))) {
                            M2C_FIELD(temp_r4_7, s8 *, 0x4A) = 0;
                            M2C_FIELD(temp_r4_7, s8 *, 0x4B) = 1;
                            M2C_FIELD(temp_r4_7, s8 *, 0x49) = 1;
                        }
                        if ((s32) M2C_FIELD(arg0, s32 *, 0x64) == (s32) M2C_FIELD(arg0, s32 *, 0x60)) {
                            temp_r3_12 = M2C_FIELD(arg0, void **, 0x88);
                            if ((temp_r3_12 != 0) && ((s32) M2C_FIELD(temp_r3_12, u8 *, 0x19) != 0)) {
                                M2C_FIELD(temp_r3_12, s8 *, 0x4A) = 1;
                                M2C_FIELD(temp_r3_12, s8 *, 0x4C) = 0;
                            }
                        }
                    }
                }
            }
            if ((void *) M2C_FIELD(arg0, void **, 0x84) != 0) {
                temp_r22_2 = var_r5_7 * 0x10;
                temp_r0_4 = *M2C_FIELD(arg0, s32 **, 0x4C);
                if ((s32) *(s32 *)((u8 *)temp_r0_4 + temp_r22_2) != 0) {
                    var_f30 = lbl_80561980;
                    temp_r0_5 = M2C_FIELD(((u8 *)temp_r0_4 + temp_r22_2), s32 *, 4);
                    var_f29 = var_f30;
                    switch (temp_r0_5) {
                    case 5:
                        var_r0 = 0;
                        break;
                    case 10:
                        var_r0 = 1;
                        break;
                    case 15:
                        var_r0 = 2;
                        break;
                    default:
                        Abend_Panic(lbl_803306D0 + 0x7A8);
                        var_r0 = 0;
                        break;
                    }
                    switch (var_r0) {
                    case 1:
                        var_f30 = lbl_805619AC;
                        var_f29 = lbl_80561984;
                        break;
                    case 2:
                        var_f30 = lbl_80561984;
                        var_f29 = lbl_805619E0;
                        break;
                    }
                    if (var_f30 != lbl_80561980) {
                        var_f4 = lbl_80561984;
                        temp_f0_3 = ((lbl_8055E3C8 - *(f32 *)((u8 *)*M2C_FIELD(arg0, s32 **, 0x4C) + temp_r22_2 + 8)) - lbl_80561980) / (var_f29 - lbl_80561980);
                        if (var_f4 < temp_f0_3) {
                            var_f4 = temp_f0_3;
                        }
                        if (var_f4 > lbl_80561980) {
                            var_f4 = lbl_80561980;
                        }
                        temp_r3_13 = M2C_FIELD(arg0, void **, 0x84);
                        temp_f1_3 = var_f30 + (var_f4 * (lbl_80561980 - var_f30));
                        if (temp_f1_3 != M2C_FIELD(temp_r3_13, f32 *, 8)) {
                            M2C_FIELD(temp_r3_13, s8 *, 0x4D) = 1;
                            M2C_FIELD(temp_r3_13, f32 *, 8) = temp_f1_3;
                        }
                    }
                }
            }
        }
    }
    if ((((TObj4C *)arg0)->d7() != 0) && !((lbl_8055E3C8 - M2C_FIELD(arg0, f32 *, 0xA0)) < lbl_80561A1C)) {
        temp_r5_2 = M2C_FIELD(arg0, s32 *, 0x60);
        temp_r6_2 = (s32) M2C_FIELD(arg0, f32 *, 0x38);
        updateRingChallengeResults((CrushRoundState8016B964 *)((u8 *)arg0 + 0xAC), temp_r5_2 + temp_r6_2, temp_r5_2, temp_r6_2);
    }
}
#pragma cplusplus off

extern f64 fn_8002F234(f32, f32, f32, f32, f32);
#pragma use_lmw_stmw off
/* Advance a route's waypoint index when the vehicle enters the next waypoint's
 * radius: compare the waypoint XZ (+0x24/+0x2C) to the vehicle XZ (+0x60/+0x68),
 * and if within the waypoint's radius (+0x34) clear the old waypoint's active flag
 * (+0x30), bump the index and set the new waypoint's flag. */
void fn_80170DA8(void *route, void *vehicle) {
    u8 *base;
    u8 *item;
    s32 index;
    s32 next;
    struct { f32 x, z; } q, p, d;
    f32 distance;
    f32 threshold;
    index = *(s32 *)((u8 *)route + 0x10);
    next = index + 1;
    if (next < *(s32 *)(*(u8 **)((u8 *)route + 4) + 4)) {
        base = *(u8 **)*(void **)((u8 *)route + 4);
        item = base + (index + 1) * 0x38;
        q.x = *(f32 *)(item + 0x24);
        q.z = *(f32 *)(item + 0x2C);
        p.x = *(f32 *)((u8 *)vehicle + 0x60);
        p.z = *(f32 *)((u8 *)vehicle + 0x68);
        d.x = q.x - p.x;
        d.z = q.z - p.z;
        distance = (f32)fn_8002F234(d.x * d.x + d.z * d.z, p.z, p.x, d.x, d.z);
        threshold = *(f32 *)(item + 0x34);
        if (distance < threshold) {
            *(u8 *)(base + index * 0x38 + 0x30) = 0;
            *(s32 *)((u8 *)route + 0x10) = next;
            *(u8 *)(*(u8 **)*(void **)((u8 *)route + 4) + next * 0x38 + 0x30) = 1;
        }
    }
}
#pragma use_lmw_stmw on
/* Read the car index/id at +0x1EC of the given vehicle object (sibling getter
 * of the TObj4C accessor family fn_80170E80/88/90). */
s32 fn_80170E78(void *vehicle) { return *(s32 *)((u8 *)vehicle + 0x1ec); }

f32 fn_80170E80(f32 *ptr) {
    /* Return the float value pointed to by ptr (identity accessor kept as a separate function). */
    return *ptr;
}

extern s32 getRegisteredObject(s32);
/* Resolve a list entry to the object it names: take the object-table index stored at
 * +4 of the entry and look it up in the 8-entry global object table (getRegisteredObject),
 * which holds the vehicle/player registered at each index (0 if out of range). */
s32 fn_80170E88(void *entry) {
    return getRegisteredObject(*(s32 *)((u8 *)entry + 4));
}

/* Read the byte flag at +8 of an item/entry object handled by the TObj4C
 * accessor family (fn_80170E78/80/88 are its sibling field getters). */
u8 fn_80170E90(void *entry) { return *(u8 *)((u8 *)entry + 8); }

extern char lbl_803306D0[];
extern char lbl_80330AEC[];
extern char lbl_8033072C[];
extern char lbl_803308A0[];
extern f32 lbl_80561980;
extern void Abend_Panic(const char *, ...);
/* Format a status label for arg0's kind (field 0x44) and value (field 0x2C) into the output buffer; panics on unknown kinds. */
void fn_80170E98(void *source, void *buffer, s32 bufferSize) {
    register const char *messages = lbl_803306D0;
    s32 kind = *(s32 *)((u8 *)source + 0x44);

    switch (kind) {
    case 0:
        ((void (*)(void *, s32, const char *, ...))fn_801345D8)(
            buffer, bufferSize, messages + 0x264, *(s32 *)((u8 *)source + 0x2c));
        break;
    case 1:
        ((void (*)(void *, s32, const char *, ...))fn_801345D8)(
            buffer, bufferSize, messages + 0x270, *(s32 *)((u8 *)source + 0x2c));
        break;
    case 2:
        ((void (*)(void *, s32, const char *, ...))fn_801345D8)(
            buffer, bufferSize, messages + 0x27c, *(s32 *)((u8 *)source + 0x2c));
        break;
    default:
        Abend_Panic(messages + 0x288);
        break;
    }
}

/* Return whether the global scene flag is set and the object is active but not in its disabled state. */
s32 fn_80170F1C(void *obj) {
    s32 result = 0;
    if (fn_801B8514() != 0 && *((u8 *)obj + 0x79) != 0 && *((u8 *)obj + 0x9C) == 0) {
        result = 1;
    }
    return result;
}

#pragma cplusplus on
extern "C" s32 fn_80170F7C(void *object) {
    /* Return true if the object is active (d7) and its state at +0xAC is 2. */
    if (((TObj4C *)object)->d7() != 0) {
        return *(s32 *)((u8 *)object + 0xAC) == 2;
    }
    return 0;
}
#pragma cplusplus off
u32 fn_80170FD4(void) {
    /* Constant predicate (returns 1 / true); likely a virtual getter reached through a dispatch table. */
    return 1;
}

extern f32 lbl_80561A1C;
extern s32 fn_802AE220(s32, s32);
extern s32 fn_8001DFCC(void);
#pragma cplusplus on
class Q70FDC {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
    virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
    virtual s32 query();
};
/* Near-deadline hook: fire the virtual callback (or the flagged fallbacks), then
 * return 1 unless this object's status field at +0xAC equals 4. */
extern "C" u32 fn_80170FDC(const void *self) {
    s32 status;
    const u8 *bytes = (const u8 *)self;
    if ((lbl_8055E3C8 - *(const f32 *)(bytes + 0xA0)) < 2.25f) {
        ((Q70FDC *)(void *)self)->f17();
    } else {
        if (*(const u8 *)(bytes + 0xB4) != 0)
            ((Q70FDC *)(void *)self)->f17();
        if (*(const s32 *)(bytes + 0xB8) != 0)
            fn_802AE220(*(const s32 *)(bytes + 0xB8), 0);
    }
    if (((Q70FDC *)(void *)self)->query() != 0)
        fn_8001DFCC();
    status = *(const s32 *)(bytes + 0xAC);
    return (u32)((4 - status) | (status - 4)) >> 31;
}
#pragma cplusplus reset

extern s32 fn_802AE118(void);
#pragma cplusplus on
extern "C" s32 handleTimedAction(void *obj, s32 unused, s32 actionId) {
    /* Handles action 0x58 or advances the object's timed state: when a countdown in
     * state 1 is near its end, fire the timer callback, activate four child objects
     * and rewind the start time; reports whether the action was handled. */
    struct Query {
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
        virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
        virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
        virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
        virtual s32 query();
    };
    s32 timerState;
    f32 startTime;
    f32 gameTime;

    if (((Query *)obj)->query() != 0 && actionId == 0x58) {
        if (*(volatile s32 *)((u8 *)obj + 0xAC) == 2)
            *(u8 *)((u8 *)obj + 0xB5) = 1;
        return 1;
    }
    if (*(volatile s32 *)((u8 *)obj + 0xAC) != 0) {
        gameTime = lbl_8055E3C8;
        timerState = *(volatile s32 *)((u8 *)obj + 0xAC);
        if (timerState == 1 && *(u8 *)((u8 *)obj + 0xBC) == 0) {
            startTime = *(f32 *)((u8 *)obj + 0xB0);
            if (startTime > lbl_80561980 && gameTime - startTime < lbl_80561984) {
                register void *timerHandle;
                void *child;
                timerHandle = *(void **)((u8 *)obj + 0xB8);
                *(u8 *)((u8 *)obj + 0xBC) = 1;
                if (timerHandle != 0)
                    fn_802AE118();
                child = *(void **)((u8 *)obj + 0xC0);
                if (child != 0) {
                    *(u8 *)((u8 *)child + 0x4A) = 1;
                    *(u8 *)((u8 *)child + 0x4C) = 0;
                }
                child = *(void **)((u8 *)obj + 0xC4);
                if (child != 0) {
                    *(u8 *)((u8 *)child + 0x4A) = 1;
                    *(u8 *)((u8 *)child + 0x4C) = 0;
                }
                child = *(void **)((u8 *)obj + 0xD4);
                if (child != 0) {
                    *(u8 *)((u8 *)child + 0x4A) = 1;
                    *(u8 *)((u8 *)child + 0x4C) = 0;
                }
                child = *(void **)((u8 *)obj + 0xD8);
                if (child != 0) {
                    *(u8 *)((u8 *)child + 0x4A) = 1;
                    *(u8 *)((u8 *)child + 0x4C) = 0;
                }
                {
                    f32 windowLength;
                    f32 now;
                    s32 zero;
                    now = lbl_8055E3C8;
                    zero = 0;
                    windowLength = lbl_80561984;
                    if ((*(volatile u8 *)((u8 *)obj + 0xB4) = zero) == 0)
                        *(f32 *)((u8 *)obj + 0xB0) = now - windowLength;
                }
            }
        }
        return 1;
    }
    return 0;
}
#pragma cplusplus reset
s32 fn_801711F8(void *obj) {
    /* Returns nonzero while this object's countdown flag at +0x79 is clear (countdown still running). */
    typedef struct {
        u8 _pad[0x79];
        u8 countdownDone;
    } CountdownObj;
    return ((CountdownObj *)obj)->countdownDone == 0;
}

/* Member callback: ignores the object and forwards the slot index to the per-slot request builder. */
void fn_80171208(void *self, s32 slotIndex) {
    Deity_submitSlotRequest((void *)slotIndex);
}

extern void fn_801B8060(void *, void *);
extern f32 lbl_80561A20;
extern f32 lbl_80561A24;
#pragma push
#pragma opt_common_subs off
/* Compute/update output transform (arg2) from this object's active sub-record:
   clear the selected item's flags, validate the current entry/record, copy base
   transform via fn_801B8060, scale its position (x/y/z by 26.666666) and adjust
   Y offset (+7.625); returns 1 on success, 0 if no valid record. */
s32 fn_80171210(void *arg0, s32 arg1, void *arg2) {
    s32 count;
    register void *item;
    register void *entry;
    register void *record;
    s32 index;
    void *list;
    f32 x;
    f32 scaledX;
    f32 scale;

    item = ((void **)M2C_FIELD(arg0, void **, 4))[arg1];
    M2C_FIELD(item, u8 *, 8) = 0;
    M2C_FIELD(item, f32 *, 0xC) = 0.0f;
    count = M2C_FIELD(arg0, s32 *, 0x5C);
    if (count < M2C_FIELD(arg0, s32 *, 0x6C)) {
        list = M2C_FIELD(arg0, void **, 0x48);
        entry = (u8 *)M2C_FIELD(list, void **, 0) + count * 0x14;
        list = M2C_FIELD(entry, void **, 4);
        if (list != 0 && M2C_FIELD(list, s32 *, 4) > 0 &&
            *((u8 *)M2C_FIELD(list, void **, 0) +
              *(volatile s32 *)((u8 *)entry + 0x10) * 0x38 + 0x30) != 0) {
            void *list2 = *(void * volatile *)((u8 *)entry + 4);
            index = *(volatile s32 *)((u8 *)entry + 0x10);
            if (index + 1 < M2C_FIELD(list2, s32 *, 4))
                record = (u8 *)M2C_FIELD(list2, void * volatile *, 0) + (index + 1) * 0x38;
            else
                record = (u8 *)M2C_FIELD(list2, void * volatile *, 0) + index * 0x38;
            fn_801B8060(arg2, record);
            x = *(volatile f32 *)((u8 *)record + 0x18);
            scale = 26.666666f;
            scaledX = x * scale;
            *(f32 *)((u8 *)arg2 + 0x30) = scaledX;
            *(f32 *)((u8 *)arg2 + 0x34) = *(f32 *)((u8 *)record + 0x1C) * scale;
            *(f32 *)((u8 *)arg2 + 0x38) = *(f32 *)((u8 *)record + 0x20) * scale;
            *(f32 *)((u8 *)arg2 + 0x28) += 7.625f;
            return 1;
        }
        return 0;
    }
    return 0;
}
#pragma pop
extern f32 lbl_80558DC4;
extern f32 lbl_80561A28;
extern f32 PSVECDotProduct(const void *, const void *, f32);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
__declspec(section ".data") extern f32 lbl_80558DC4;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 fn_8017133C(void *arg0, s32 arg1, s8 *arg2) {
    class Base {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual f32 f12();
    };
    class Pcr {
    public:
        virtual void p0(); virtual void p1(); virtual void p2();
        virtual s32 m3();
    };
    register void *obj;
    register void *holder;
    u32 result;
    register s32 index;
    s32 d;
    void *data;
    register void *item;
    s32 r25;
    s32 r4v;
    s32 cond;
    register void *info;
    void *ent;
    volatile f32 sp1C, sp18, sp14, sp10, spC, sp8;
    f32 x, y, dx, dy;
    f32 v;
    result = 0;
    v = lbl_8055E3C8;
    if (v > ((Base *)arg0)->f12() && *(u8 *)((u8 *)arg0 + 0x78) == 0) {
        index = arg1 * 4;
        data = (void *)getRegisteredObject(*(s32 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 4));
        cond = ((f32)__fabs((f64)*(f32 *)((u8 *)data + 0x2690)) <= lbl_80558DC4);
        if (cond) {
            obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index);
            r4v = *(s32 *)((u8 *)arg0 + 0x5C);
            if (r4v < *(s32 *)((u8 *)arg0 + 0x6C)) {
                holder = (u8 *)(**(s32 ***)((u8 *)arg0 + 0x48)) + r4v * 0x14;
                if (*(void **)((u8 *)holder + 4) != 0 &&
                    *(s32 *)((u8 *)*(void **)((u8 *)holder + 4) + 4) > 0 &&
                    *(u8 *)((u8 *)(*(s32 **)*(void **)((u8 *)holder + 4)) + *(s32 *)((u8 *)holder + 0x10) * 0x38 + 0x30) != 0) {
                    data = (void *)getRegisteredObject(*(s32 *)((u8 *)obj + 4));
                    item = (u8 *)(*(s32 **)*(void **)((u8 *)holder + 4)) + *(s32 *)((u8 *)holder + 0x10) * 0x38;
                    x = *(f32 *)((u8 *)data + 0x60);
                    y = *(f32 *)((u8 *)data + 0x68);
                    dx = *(f32 *)((u8 *)item + 0x24) - x;
                    dy = *(f32 *)((u8 *)item + 0x2C) - y;
                    sp10 = *(f32 *)((u8 *)item + 0x24);
                    sp14 = *(f32 *)((u8 *)item + 0x2C);
                    sp18 = x;
                    sp1C = y;
                    sp8 = dx;
                    spC = dy;
                    r25 = ((f32)fn_8002F234(dx * dx + dy * dy, y, x, dx, dy) > *(f32 *)((u8 *)item + 0x34));
                    d = (PSVECDotProduct((u8 *)item + 0x18, (u8 *)data + 0x54, *(f32 *)((u8 *)item + 0x34)) < lbl_80561980);
                    if (*(s32 *)((u8 *)holder + 0x10) == *(s32 *)((u8 *)*(void **)((u8 *)holder + 4) + 4) - 1 && r25) {
                        result = 0;
                        *(u8 *)((u8 *)(*(s32 **)*(void **)((u8 *)holder + 4)) + *(s32 *)((u8 *)holder + 0x10) * 0x38 + 0x30) = 0;
                    } else {
                        if (r25 || d) {
                            if (*(u8 *)((u8 *)obj + 8) == 0) {
                                *(u8 *)((u8 *)obj + 8) = 1;
                                *(f32 *)((u8 *)obj + 0xC) = lbl_80561980;
                            }
                            if (*(f32 *)((u8 *)obj + 0xC) > lbl_80561A28) {
                                *arg2 = 1;
                            } else {
                                *arg2 = 0;
                            }
                        } else {
                            *(u8 *)((u8 *)obj + 8) = 0;
                            *(f32 *)((u8 *)obj + 0xC) = lbl_80561980;
                            *arg2 = 0;
                        }
                        result = 1;
                    }
                } else {
                    result = 0;
                }
            } else {
                result = 0;
            }
        }
        if (result == 0 &&
            *(s32 *)((u8 *)(void *)getRegisteredObject(*(s32 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 4)) + 0x10) == 0x50434152) {
            info = (void *)getRegisteredObject(*(s32 *)((u8 *)(*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index)) + 4));
            if (((Pcr *)*(void **)((u8 *)info + 0x270C))->m3() & 0x10) {
                ent = *(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index);
                if (*(u8 *)((u8 *)ent + 8) == 0) {
                    *(u8 *)((u8 *)ent + 8) = 1;
                    *(f32 *)((u8 *)ent + 0xC) = lbl_80561980;
                }
            } else {
                if (!(((Pcr *)*(void **)((u8 *)info + 0x270C))->m3() & 0x10)) {
                    ent = *(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + index);
                    if (*(u8 *)((u8 *)ent + 8) != 0) {
                        *(u8 *)((u8 *)ent + 8) = 0;
                        *(f32 *)((u8 *)ent + 0xC) = lbl_80561980;
                    }
                }
            }
        }
    }
    return result;
}
extern char lbl_80330BC8[];
extern char lbl_80330BD8[];
extern void *fn_80145E70(const char *);
extern s32 fn_801284F8(s32, const char *);
extern void *fn_802ADDD8(s32);
extern void fn_8016EA9C(void *);
extern void fn_8016E984(void *);
extern s32 fn_80179650(void);

/* Append one pointer, returning the slot that received it. */
#pragma push
#pragma dont_inline on
#pragma cplusplus on
void **fn_8016CE9C(void *vec, void **__restrict pValue) {
    int index;
    void **data;
    int newIndex;
    /* Append *pValue to the vector's data array, advance its count, and return the filled slot. */
    index = ((PtrVec *)vec)->count;
    data = ((PtrVec *)vec)->data;
    newIndex = index + 1;
    ((PtrVec *)vec)->count = newIndex;
    data[index] = *pValue;
    return &data[index];
}
#pragma pop

#pragma cplusplus reset
