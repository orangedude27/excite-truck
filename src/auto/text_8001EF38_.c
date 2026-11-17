// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

int fn_8001F7E4();
s32 fn_8001FD24(void);
extern s8 lbl_8055D614;
extern s32 lbl_8055D618;
extern char lbl_802FE060[];

/* One of the 8 lifetime counters (lbl_802FDF30): the short key a caller
 * looks it up by ("score", "win", ...), its "Achievements:<KEY>" archive
 * key, the id resolved by fn_80131234 and the value list fn_8001EFF0 builds. */
typedef struct SrcCoef {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void* unkC;
} SrcCoef;

/* One row of a lifetime counter's threshold list, read off one "level" child
 * node of the ACHV archive by fn_8001EFF0: the value the counter has to reach
 * and the model name that goes with it. */
typedef struct AchThreshold {
    s32 threshold; /* "threshhold" attribute */
    s32 model;     /* "model_name" attribute */
} AchThreshold;    /* 8 bytes; the rows are kept in rising order */

/* What SrcCoef.unkC points at: the rows fn_8001EFF0 allocated for one
 * counter, and how many of them there are. */
typedef struct AchThresholdList {
    AchThreshold* rows; /* at 0x00, count * 8 bytes */
    s32 count;          /* at 0x04 */
} AchThresholdList;

/* Achievements module (registered as the 'ACHV' archive block).
 * Statistics live in ACH_BLOCK_SIZE-byte blocks: ACH_COUNTER_COUNT lifetime
 * counters at the head, then ACH_ENTRY_COUNT named per-object entries.
 * lbl_80358698 holds one block per profile (4 of them, indexed by
 * fn_8000DA10), lbl_8035A718 the block in play and lbl_8035AF38 this
 * session's pending additions, merged into it by fn_8001F724/fn_8001F5BC. */
#define ACH_BLOCK_SIZE 0x820  /* size of one statistics block */
#define ACH_COUNTER_COUNT 0x14 /* lifetime counters, indexed by counter id */
#define ACH_NAME_OFFSET 0x50  /* first entry's name, from the block start */
#define ACH_ENTRY_SIZE 0x28   /* one named entry */
#define ACH_ENTRY_COUNT 0x32  /* named entries per block */
#define ACH_NAME_SIZE 0x20    /* name held in an entry */
#define ACH_VALUE_OFFSET 0x70 /* an entry's values, from its row start */

typedef struct AchEntry {
    char name[ACH_NAME_SIZE]; /* object name; empty when the entry is free */
    s32 value[2];             /* the two statistics fn_8001FAC8 sums up */
} AchEntry;                   /* == ACH_ENTRY_SIZE */

extern SrcCoef lbl_802FDF30[8];
extern s32 lbl_8055D610;
extern s32 fn_8000DA10(void);
void fn_80128668(void*);
void fn_80128670(s32);
void fn_80131818(s32);
s32 fn_8001F89C();
s32 fn_8001F2C8();
s32 fn_8001F388();
s32 fn_8001F3AC();
s32 stricmp(const char*, const char*);
extern void* memset(void*, int, unsigned long);
extern char lbl_80358698[0x2080];
extern char lbl_8035AF38[0x820];

void fn_8001F578();
void fn_8001FBE4();
void fn_8001F724();
void fn_8001F780();
s32 fn_8001F9A4();
s32 fn_8001FA20();
s32 fn_8001FA8C();

extern void fn_802E6BD8(int, int, void *, int, void (*)(long));
extern void fn_8000DBC8(void (*)(long, long));
void fn_8001F528(void);
void fn_8001EFF0(void);
extern char lbl_802FDE68[];
extern char lbl_802FE0D4[], lbl_802FE0E0[], lbl_802FE0EC[], lbl_802FE0FC[];
extern char lbl_80558D5C[8], lbl_80558D64[8], lbl_80558D6C[8];
#pragma use_lmw_stmw off
extern s32 fn_80131234(s32);
extern s32 fn_80131810(void*);
extern void* fn_801284F8(int, void*);
extern void* fn_8012850C(int, void*);
extern void fn_802E317C(const char*, ...);
extern void fn_802E30C8(const char *, ...);
s32 fn_8001F41C(const char* arg);
#define VFN(o, off, T) ((T)(*(void***)(o))[(off) / 4])
typedef struct VObj VObj;
typedef struct VTbl {
    void* s0; void* s1;
    char* (*getName)(VObj*);
    VObj* (*getAt)(VObj*, s32);
    void* s4;
    s32 (*getAttr)(VObj*, char*);
    void* s6;
    s32 (*getAttr2)(VObj*, char*);
    void* pad[0x18 - 8];
    VObj* (*getChild)(VObj*, s32);
} VTbl;
struct VObj { VTbl* vt; };
/* Initialize the achievements module: register the ACHV archive block and build
 * the lifetime-counter coefficient table from it. */
void fn_8001EF38(void) {
    fn_8001F528();
    fn_8001EFF0();
}

void fn_8001EF5C(void) {
    fn_8001F7E4();
}

void fn_8001EF60(void* alarm) {
#define CurrentPlayer      fn_8000DA10
#define GetAchCounterValue fn_8001F89C
    /* Alarm callback: read the current player's stored achievements counter value for the counter id carried by alarm. */
    GetAchCounterValue(alarm, CurrentPlayer());
#undef GetAchCounterValue
#undef CurrentPlayer
}

s32 fn_8001EF98(s32 counterId, s32 profileIndex) {
#define GetAchCounterValue fn_8001F89C
    /* Profile-init thunk: return the stored achievements counter value for counterId in the given profile. */
    return GetAchCounterValue(counterId, profileIndex);
#undef GetAchCounterValue
}

s32 fn_8001EF9C(s32 coefIndex) {
#define GetAchCoefId fn_8001F388
    /* Thunk: return the resolved id of the achievements source-coefficient entry at coefIndex. */
    return GetAchCoefId(coefIndex);
#undef GetAchCoefId
}

s32 fn_8001EFA0(s32 counter, s32 value) {
#define GetAchLevel fn_8001F9A4
    /* Thunk: return the achievement level reached by value for the given counter. */
    return GetAchLevel(counter, value);
#undef GetAchLevel
}

s32 fn_8001EFA4(s32 counter, s32 level) {
#define GetAchLevelValue fn_8001FA20
    /* Thunk: return the threshold value needed to reach the given level for the given counter. */
    return GetAchLevelValue(counter, level);
#undef GetAchLevelValue
}

void fn_8001EFA8(void) {
#define GetAchievementThresholdCount fn_8001FA8C
    /* Tail-call thunk: forwards the achievement/counter id to return how many thresholds that achievement has. */
    GetAchievementThresholdCount();
#undef GetAchievementThresholdCount
}

/* RealName: Achievements_GetLevelModelName
 * Thunk for the achievements UI: the model (rank) name string of threshold
 * `level` (1-based) of lifetime counter `coefSet`, or 0 when it has none. */
const char *fn_8001EFAC(s32 coefSet, s32 level) {
    return (const char *)fn_8001F3AC(coefSet, level);
}

void fn_8001F908(void *);

void fn_8001EFB0(void *arg0) {
#define ComputeAchievementValues fn_8001F908
    /* Thunk: compute an achievement's progress values into the record pointed to by arg0. */
    ComputeAchievementValues(arg0);
#undef ComputeAchievementValues
}

void fn_8001EFB4(void) {
#define MergePendingAchievements fn_8001F724
    /* Thunk: merge this session's pending achievement statistics into the active block. */
    MergePendingAchievements();
#undef MergePendingAchievements
}

void fn_8001F76C(void);

void fn_8001EFB8(void) {
#define ClearPendingAchievements fn_8001F76C
    /* Thunk: clear this session's pending achievement statistics block. */
    ClearPendingAchievements();
#undef ClearPendingAchievements
}

void fn_8001EFBC(void) {
#define FinalizeAchievements fn_8001F780
    /* Tail-call thunk: finalize this player's achievements after the results screen - merge their stats into the career totals and reset the working achievement blocks. */
    FinalizeAchievements();
#undef FinalizeAchievements
}

int fn_8001EFC0(s32 counter, const char *name) {
#define QueryAchievementTotal fn_8001FAC8
    /* Tail-call alias: return the named achievement's summed statistic value for the given value slot. */
    return QueryAchievementTotal(counter, name);
#undef QueryAchievementTotal
}

/* RealName: AchAddPendingNamedValue
 * Thunk for gameplay code: add `amount` to lifetime statistic `stat` of the
 * object `objectName` in this session's pending achievements block. */
void fn_8001EFC4(s32 stat, const char *objectName, s32 amount) {
    fn_8001FBE4(stat, objectName, amount);
}

void fn_8001EFC8(void) {
#define ClearAchievementBlocks fn_8001F578
    /* Tail-call thunk: zero the active and pending achievement statistics blocks. */
    ClearAchievementBlocks();
#undef ClearAchievementBlocks
}

void fn_8001EFCC(void* alarm) {
#define releaseAchievementAttachments fn_8001F2C8
#define clearAchievementBlocks fn_8001F578
    /* Alarm callback: release the achievement attachment slots, then zero the active and pending achievement blocks. */
    clearAchievementBlocks(releaseAchievementAttachments(alarm));
#undef clearAchievementBlocks
#undef releaseAchievementAttachments
}

#pragma scheduling invalid_target
void fn_8001EFF0(void) {
    char* base = lbl_802FDE68;
    register VObj* obj;
    VObj* child;
    u32 n;
    s32 i;
    s32 j;
    s32 idx;
    SrcCoef* p;
    s32* res;
    p = (SrcCoef*)(base + 0xC8);
    n = 0;
    do {
        p->unk8 = fn_80131234(p->unk4);
        n++;
        p++;
    } while (n < 8);
    lbl_8055D610 = fn_80131810(base + 0x148);
    if (lbl_8055D610 != 0) {
        p = (SrcCoef*)(base + 0xC8);
        for (i = 0; (obj = ((VObj*)lbl_8055D610)->vt->getAt((VObj*)lbl_8055D610, i)) != NULL; i++) {
            if (stricmp(obj->vt->getName(obj), base + 0x15C) == 0) {
                idx = fn_8001F41C((char*)obj->vt->getAttr(obj, lbl_80558D5C));
                if (idx >= 0 && idx < 8) {
                    if ((u32)idx < 8) {
                        res = (s32*)fn_801284F8(8, base + 0x174);
                        if (res != NULL) {
                            res[0] = 0;
                            res[1] = 0;
                            for (j = 0; (child = obj->vt->getChild(obj, j)) != NULL; j++) {
                                if (stricmp(child->vt->getName(child), lbl_80558D6C) == 0) {
                                    res[1]++;
                                }
                            }
                            if (res[1] == 0) {
                                fn_802E317C(lbl_802FE0FC, obj->vt->getName(obj));
                            }
                            res[0] = (s32)fn_8012850C(res[1] * 8, lbl_802FE0EC);
                            res[1] = 0;
                            for (j = 0; (child = obj->vt->getChild(obj, j)) != NULL; j++) {
                                if (stricmp(child->vt->getName(child), lbl_80558D64) == 0) {
                                    *(s32*)(res[0] + res[1] * 8) = child->vt->getAttr2(child, lbl_802FE0E0);
                                    ((s32*)(res[0] + res[1] * 8))[1] = child->vt->getAttr(child, lbl_802FE0D4);
                                    res[1]++;
                                }
                            }
                        }
                        p[idx].unkC = res;
                    }
                } else {
                    s32 name = obj->vt->getAttr(obj, lbl_80558D5C);
                    fn_802E30C8(base + 0x188, obj->vt->getName(obj), name);
                }
            }
        }
    }
}
#pragma scheduling on
s32 fn_8001F2C8(void* alarm) {
    /* Release each lifetime-counter attachment and close the achievements archive. */
    if (lbl_8055D610 != 0) {
        SrcCoef* slot = lbl_802FDF30;
        void* attachment;
        u32 index = 0;
        void* zero = NULL;
        do {
            attachment = slot->unkC;
            if (attachment != NULL) {
                if (attachment != NULL) {
                    if (*(s32*)attachment != 0) {
                        fn_80128670(*(s32*)attachment);
                    }
                    *(s32*)attachment = (s32)zero;
                    ((s32*)attachment)[1] = (s32)zero;
                    fn_80128668(attachment);
                }
                slot->unkC = zero;
            }
            index++;
            slot++;
        } while (index < 8);
        fn_80131818(lbl_8055D610);
        lbl_8055D610 = 0;
    }
}
#pragma scheduling reset
/* Return the source-coefficient table slot at `index` (SrcCoef entries, 16 bytes each). */
f32* __AXFXGetSrcCoef(u32 index) {
    return (f32*)&lbl_802FDF30[index];
}

#pragma dont_inline on
s32 fn_8001F388(s32 arg) {
    /* Return the resolved id (unk8) of the achievements source-coefficient entry at index `arg`. */
    return ((SrcCoef*)__AXFXGetSrcCoef(arg))->unk8;
}

/* Returns the second field of the (index - 1)'th 8-byte entry in the source-coefficient table for the given coef set, or 0 if missing/out of range. */
s32 fn_8001F3AC(s32 coefSet, s32 index) {
    s32 *coefData = *(s32 **)((s32 *)__AXFXGetSrcCoef(coefSet) + 3);
    if (coefData == 0) goto null_result;
    if (index <= 0) goto bad_index;
    if (index > coefData[1]) goto bad_index;
    return ((s32 *)(coefData[0] + ((index - 1) * 8)))[1];
bad_index:
    return 0;
null_result:
    return 0;
}

s32 fn_8001F41C(const char* arg) {
    SrcCoef* p = lbl_802FDF30;
    u32 idx = 0;
    for (;;) {
        if (stricmp((const char*)p->unk0, arg) == 0) {
            return idx;
        }
        idx++;
        if (idx >= 8) break;
        p++;
    }
    return -1;
}

#pragma scheduling off
/* ACHV archive-block callback: when notified with event 0 or 2, clear the whole
   achievements statistics array (all four per-profile blocks). */
void fn_8001F490(s32 event) {
    if (event == 2)
        goto reset;
    if (event < 2) {
        if (event == 0)
            goto reset;
        return;
    }
    return;
reset:
    memset(&lbl_80358698, 0, 0x2080);
}
#pragma scheduling on
extern char lbl_802FE024[];
extern void fn_802E30C8(const char *, ...);
#pragma scheduling invalid_target
/* Identity callback: clear one profile's achievements statistics block when notified of event 0. */
void fn_8001F4C4(s32 profileIndex, s32 event) {
    switch (event) {
    case 0:
        fn_802E30C8(lbl_802FE024, profileIndex);
        memset(lbl_80358698 + profileIndex * ACH_BLOCK_SIZE, 0, ACH_BLOCK_SIZE);
        break;
    default:
        break;
    }
}

/* RealName: Achievements_Init
 * Registers the achievements ('ACHV') archive block and profile callback,
 * then initializes the achievements session/state. */
void fn_8001F528(void) {
#define ACHV_BLOCK_ID 0x41434856
    fn_802E6BD8(ACHV_BLOCK_ID, 3, lbl_80358698, 0x2080, fn_8001F490);
    fn_8000DBC8(fn_8001F4C4);
    fn_8001F578();
#undef ACHV_BLOCK_ID
}

#pragma scheduling on
extern char lbl_8035A718[0x820];
#pragma scheduling on
#pragma scheduling invalid_target
/* Clear the active and pending achievements statistics blocks. */
void fn_8001F578(void) {
#define sActiveAchievementsBlock lbl_8035A718
#define sPendingAchievementsBlock lbl_8035AF38
    memset(sActiveAchievementsBlock, 0, 0x820);
    memset(sPendingAchievementsBlock, 0, 0x820);
#undef sActiveAchievementsBlock
#undef sPendingAchievementsBlock
}
#pragma scheduling on
extern void *memcpy(void *, const void *, unsigned long);
void fn_8001F5BC(void *arg0, void *arg1, int arg2) {
    s32 *a = (s32 *)arg0;
    s32 *b = (s32 *)arg1;
    char *input = (char *)arg1 + 0x50;
    char *output = (char *)arg0;
    char *entry;
    s32 sum7, sum6, sum5, sum4, sum3, sum2, sum1, sum0;
    int found, empty;
    u32 i, j;
    sum0 = a[0] + b[0];
    sum1 = a[1] + b[1];
    sum2 = a[2] + b[2];
    sum3 = a[3] + b[3];
    sum4 = a[4] + b[4];
    sum5 = a[5] + b[5];
    sum6 = a[6] + b[6];
    sum7 = a[7] + b[7];
    a[0] = sum0;
    a[1] = sum1;
    a[2] = sum2;
    a[3] = sum3;
    a[4] = sum4;
    a[5] = sum5;
    a[6] = sum6;
    a[7] = sum7;
    i = 0;
    for (; i < 0x32; i++, input += 0x28) {
        entry = output + 0x50;
        found = 0;
        empty = -1;
        for (j = 0; found == 0 && j < 0x32; entry += 0x28, j++) {
            if (empty < 0 && (signed char)*entry == 0) {
                empty = (int)j;
            } else if (stricmp(entry, input) == 0) {
                int value20 = *(int *)(entry + 0x20) + *(int *)(input + 0x20);
                int value24 = *(int *)(input + 0x24);
                found = 1;
                *(int *)(entry + 0x20) = value20;
                *(int *)(entry + 0x24) += value24;
            }
        }
        if (found == 0) {
            memcpy(output + 0x50 + empty * 0x28, input, 0x28);
        }
    }
}

#pragma scheduling invalid_target
/* RealName: Achievements_CommitPendingSessionStats (merge pending session stats into active block, then clear pending)
 * Merges lbl_8035AF38 (pending session achievements/statistics block) into
 * lbl_8035A718 (active achievements block) and resets the pending block.
 */
void fn_8001F724(void) {
#define AchMergeBlocks fn_8001F5BC
#define sActiveAchievementsBlock lbl_8035A718
#define sPendingAchievementsBlock lbl_8035AF38
    ((void (*)())AchMergeBlocks)(sActiveAchievementsBlock, sPendingAchievementsBlock);
    memset(sPendingAchievementsBlock, 0, 0x820);
#undef AchMergeBlocks
#undef sActiveAchievementsBlock
#undef sPendingAchievementsBlock
}
#pragma scheduling on

#pragma scheduling invalid_target
void fn_8001F76C(void) {
    /* Clear this session's pending achievements/statistics block. */
#define sPendingAchievementsBlock lbl_8035AF38
    memset(sPendingAchievementsBlock, 0, ACH_BLOCK_SIZE);
#undef sPendingAchievementsBlock
}

#pragma scheduling invalid_target
int fn_8001F7E4(s32 arg0, s32 arg1) {
    s32 limit;
    s32 adjusted;

    if (fn_8001FD24()) {
        if (arg0 == 0 && *(u8 *)&lbl_8055D614 != 0) {
            limit = lbl_8055D618 - fn_8001F89C(arg0, fn_8000DA10());
            adjusted = arg1;
            if (limit < arg1)
                adjusted = limit;
            fn_802E30C8(lbl_802FE060, arg1, adjusted);
            arg1 = adjusted;
        }
        *(s32 *)(lbl_8035AF38 + (arg0 << 2)) += arg1;
    }
}
#pragma scheduling on
extern char lbl_802FE0A0[];
extern char lbl_80358698[];
extern char lbl_8035A718[];
s32 fn_8001F89C(s32 counterId, s32 profileIndex) {
    /* Return the stored achievements value for a counter in the given profile block. */
    if (profileIndex >= 0 && (u32)profileIndex < 4) {
        return *(s32 *)(lbl_8035A718 + counterId * 4)
             + *(s32 *)(lbl_80358698 + profileIndex * 0x820 + counterId * 4);
    }
    fn_802E30C8(lbl_802FE0A0);
    return 0;
}

void fn_8001F908(void *arg0) {
    int *p = (int *)arg0;
    int *tbl = (int *)lbl_80358698;
    int idx = fn_8000DA10();
    if (idx >= 0 && (u32)idx < 4U) {
        p[1] = tbl[idx * 0x208 + p[0]];
    } else {
        p[1] = 0;
    }
    p[2] = p[1] + tbl[0x820 + p[0]] + tbl[0xA28 + p[0]];
}

#pragma scheduling invalid_target
/* How many of a lifetime counter's levels `value` reaches: walks the counter's
 * threshold rows in rising order and stops at the first one above it, so the
 * result is the number of levels earned (all of them when none is above).
 * Counter indices run 0..7; 0 for a bad index or a counter with no rows. */
s32 fn_8001F9A4(s32 counter, s32 value) {
    volatile AchThresholdList* list;
    AchThreshold* row;
    s32 count;
    s32 n;
    s32 levels;
    if (counter < 0) goto no_coef;
    if ((u32)counter >= 8) goto no_coef;
    list = (volatile AchThresholdList*)lbl_802FDF30[counter].unkC;
    if (list == 0) goto no_coef;
    row = list->rows;
    if (row != 0) goto have_data;
    return 0;
have_data:
    count = list->count;
    levels = 0;
    for (n = count; n > 0; n--) {
        if (row->threshold > value) return levels;
        row++;
        levels++;
    }
    return list->count;
no_coef:
    return 0;
}
#pragma scheduling on
/* Get the threshold value for a lifetime counter level (1-based); returns -1 if invalid, 0 if counter unavailable. */
s32 fn_8001FA20(s32 counter, s32 level) {
    s32 *list;
    s32 rows;
    if (counter < 0) goto no_coef;
    if ((u32)counter >= 8) goto no_coef;
    list = lbl_802FDF30[counter].unkC;
    if (list == 0) goto no_coef;
    rows = list[0];
    if (rows == 0) goto invalid;
    if (list[1] < level) goto invalid;
    if (level > 0) goto get_value;
invalid:
    return -1;
get_value:
    return *(s32 *)(rows + ((level - 1) * 8));
no_coef:
    return 0;
}
#pragma scheduling on
/* RealName: Achievements_GetCounterLevelCount
 * How many threshold levels a lifetime counter has: the number of rows
 * fn_8001EFF0 built for it from the ACHV archive.  0 for a counter index
 * outside the table or one with no threshold list at all. */
s32 fn_8001FA8C(s32 counter) {
    SrcCoef *base;
    AchThresholdList *list;

    if (counter < 0)
        goto zero;
    if ((u32)counter >= 8)
        goto zero;
    base = lbl_802FDF30;
    list = (AchThresholdList *)base[counter].unkC;
    if (list == 0)
        goto zero;
    return list->count;
zero:
    return 0;
}

extern void *fn_80016720(const char *);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
int fn_8001FAC8(int arg0, const char *arg1) {
    register char *table = lbl_80358698;
    register char *name;
    register int total;
    register int offset;
    register char *region;
    register char *nameTable;
    register char *valueTable;

    name = (char *)fn_80016720(arg1);
    total = 0;
    region = table + fn_8000DA10() * 0x820;
    offset = arg0 * 4;
    nameTable = region + 0x50;
    valueTable = region + offset;
    arg0 = 0;
    for (; (unsigned int)arg0 < 0x32; arg0++) {
        if (stricmp(nameTable, name) == 0)
            total += *(int *)(valueTable + 0x70);
        nameTable += 0x28;
        valueTable += 0x28;
    }

    region = table + 0x2080;
    nameTable = region + 0x50;
    valueTable = region + offset;
    arg0 = 0;
    for (; (unsigned int)arg0 < 0x32; arg0++) {
        if (stricmp(nameTable, name) == 0)
            total += *(int *)(valueTable + 0x70);
        nameTable += 0x28;
        valueTable += 0x28;
    }

    region = table + 0x28A0;
    nameTable = region + 0x50;
    valueTable = region + offset;
    arg0 = 0;
    for (; (unsigned int)arg0 < 0x32; arg0++) {
        if (stricmp(nameTable, name) == 0)
            total += *(int *)(valueTable + 0x70);
        valueTable += 0x28;
        nameTable += 0x28;
    }
    return total;
}

/* Adds amount to statistic `stat` of the object named `objectName` in this
 * session's pending achievements block, giving the object an entry of its own
 * (its canonical name copied in) the first time it is scored. */
void fn_8001FBE4(s32 stat, const char *objectName, s32 amount) {
    char *row;
    AchEntry *entry;
    char *name;
    s32 count;
    char *dst;
    s32 found;
    s32 empty;
    u32 i;
    s32 address;
    s32 rowOffset;
    if (fn_8001FD24() == 0)
        return;
    name = (char *)fn_80016720(objectName);
    row = lbl_8035AF38;
    entry = (AchEntry *)(row + ACH_NAME_OFFSET);
    found = -1;
    empty = -1;
    i = 0;
    do {
        if (empty < 0 && (signed char)row[ACH_NAME_OFFSET] == 0)
            empty = i;
        else if (stricmp(entry->name, name) == 0)
            found = i;
        i++;
        row += ACH_ENTRY_SIZE;
        entry++;
    } while (i < ACH_ENTRY_COUNT);
    if (found < 0) {
        rowOffset = empty * ACH_ENTRY_SIZE;
        address = (s32)lbl_8035AF38;
        address += rowOffset;
        dst = (char *)(address + ACH_NAME_OFFSET);
        count = ACH_NAME_SIZE;
        goto copy;
        do {
            count--;
            if (count <= 0) {
                dst[-1] = 0;
                break;
            }
        copy:
            *dst++ = *name++;
        } while ((signed char)dst[-1] != 0);
        address = (s32)lbl_8035AF38;
        address += rowOffset;
        address += stat * 4;
        *(s32 *)(address + ACH_VALUE_OFFSET) = amount;
    } else {
        address = (s32)lbl_8035AF38;
        address += found * ACH_ENTRY_SIZE;
        address += stat * 4;
        *(s32 *)(address + ACH_VALUE_OFFSET) += amount;
    }
}

#pragma pop

extern s32 fn_801E8838(void);
// TRUE when the race manager's state field at +0xDB0 is clear (no physics step
// or transition in progress) — the gate that allows achievements to be recorded.
s32 fn_8001FD24(void) {
    return fn_801E8838() == 0;
}

extern s8 lbl_8055D614;
extern s32 lbl_8055D618;
extern s32 fn_80018FB4(void);
void fn_8001FD4C(s8 enabled) {
#define sCapExcitePoints lbl_8055D614
#define sMaxExcitePoints lbl_8055D618
    /* Sets the excite-point cap flag and caches the MAX_EXCITE_POINTS unlockable value used by fn_8001F7E4. */
    sCapExcitePoints = enabled;
    sMaxExcitePoints = fn_80018FB4();
#undef sCapExcitePoints
#undef sMaxExcitePoints
}

#pragma dont_inline off
#pragma scheduling invalid_target
