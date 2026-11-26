// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#define M2F(e, t, o) (*(t)((char *)(e) + (o)))
extern char lbl_8033BBD8[];
extern void *fn_801E87A8(void);
extern void *fn_801284F8(int, void *);
extern const char lbl_8033BBE4[];
extern void *getValueFile(const char *);
extern int fn_80012854(void);
extern char lbl_802F9D68[];
#define sTypeEntries   lbl_802F9D68 /* 0xC-byte descriptors: {name, display name, property key} */
#define TYPE_ENTRY_SIZE 0xC
extern char lbl_8033BBA0[];
extern int *sDifficultyInfo;
extern int lbl_8055B468;
extern int lbl_8055B470;
extern int lbl_8055B478;
extern signed char lbl_8055ED58;
extern int stricmp(const char *, const char *);
extern void Abend_Panic(const char *, ...);
extern void *fn_8001285C(void);
extern void releaseValueFile(int);
extern void fn_80128668(void *);
#pragma dont_inline fn_80204B2C
int fn_80204B2C(const char *);
/* Return the contest-name string for the current scene's type, or 0 if unknown. */
int *fn_80204AA4(void) {
    int value = *(int *)((char *)fn_8001285C() + 8);
    switch (value) {
    case 0x180302: return &lbl_8055B468; /* "excite" */
    case 0x180201: return &lbl_8055B470; /* "zone" */
    case 0x180303: return &lbl_8055B478; /* "fs" */
    default: return 0;
    }
}

/* Return the 0xC-byte type descriptor {name, display name, property key}
 * for the given scene/type index. */
void *fn_80204B18(int typeIndex) {
    return sTypeEntries + typeIndex * TYPE_ENTRY_SIZE;
}

#pragma dont_inline on
/* Look up a type/difficulty name in the 3-entry type table lbl_802F9D68
 * (0xC-byte descriptors); return the matching index, or 0 after reporting. */
int fn_80204B2C(const char *name) {
    typedef struct TypeDesc {
        const char *name;
        const char *displayName;
        const char *propertyKey;
    } TypeDesc;
    const TypeDesc *entry;
    unsigned int index;
    index = 0;
    entry = (const TypeDesc *)sTypeEntries;
    while (3 > index) {
        if (stricmp(name, entry->name) == 0) {
            return index;
        }
        entry++;
        index++;
        entry--;
        entry++;
    }
    Abend_Panic(lbl_8033BBA0, name);
    return 0;
}
#pragma dont_inline reset

/* Name-to-index lookup thunk: forward a difficulty name (e.g. "easy") to
 * fn_80204B2C, which matches it against the difficulty table. */
int fn_80204BB4(const char *name) {
    return fn_80204B2C(name);
}

#pragma cplusplus on
#pragma dont_inline on
/* Build the 0x14-byte "difficulty" info block for the current scene (scene type,
 * property group, current difficulty value, stage value and contest name) and
 * publish it through sDifficultyInfo. */
extern "C" void fn_80204BB8(void)
{
    #define DIFFICULTY_READY  lbl_8055ED58   /* info block is valid */
    #define DIFFICULTY_INFO   sDifficultyInfo   /* published info block */
    #define DIFFICULTY_TAG    lbl_8033BBD8   /* "difficulty" allocation tag */
    #define DIFFICULTY_VAL    lbl_8033BBE4   /* "difficulty.val" property group */
    #define INFO_SIZE         0x14

    class PropertyGroup { public: virtual void *get(int) = 0; };
    class Stage { public:
        virtual void unused0() = 0;
        virtual void unused1() = 0;
        virtual void unused2() = 0;
        virtual void unused3() = 0;
        virtual void unused4() = 0;
        virtual void unused5() = 0;
        virtual void unused6() = 0;
        virtual void unused7() = 0;
        virtual void unused8() = 0;
        virtual void unused9() = 0;
        virtual void unused10() = 0;
        virtual void unused11() = 0;
        virtual void unused12() = 0;
        virtual void unused13() = 0;
        virtual void unused14() = 0;
        virtual void unused15() = 0;
        virtual void unused16() = 0;
        virtual void unused17() = 0;
        virtual void unused18() = 0;
        virtual void unused19() = 0;
        virtual void unused20() = 0;
        virtual int get(int) = 0; /* slot 0x17 */
    };
    void *scene;
    void **groupSlot;
    void *info;
    int stageIndex;
    int sceneType;
    void *typeEntry;
    void *groupValue;
    void **nameSlot;
    Stage *stageProps;
    int stageValue;
    DIFFICULTY_READY = 1;
    DIFFICULTY_INFO = 0;
    scene = fn_801E87A8();
    info = fn_801284F8(INFO_SIZE, DIFFICULTY_TAG);
    if (info == 0) goto done;
    stageIndex = *(int *)scene;
    sceneType = *(int *)((char *)scene + 8);
    *(int *)info = sceneType;
    *(int *)((char *)info + 4) = 0;
    groupSlot = (void **)((char *)info + 4);
    *(int *)((char *)info + 8) = 0;
    *(int *)((char *)info + 12) = 0;
    *(int *)((char *)info + 16) = 0;
    *groupSlot = getValueFile(DIFFICULTY_VAL);
    typeEntry = fn_80204B18(sceneType);
    groupValue = ((PropertyGroup *)*groupSlot)->get(*(int *)((char *)typeEntry + 8));
    *(void **)((char *)info + 8) = groupValue;
    if (stageIndex >= 0 && stageIndex < fn_80012854()) {
        stageProps = *(Stage **)((char *)((void *(*)(int))fn_8001285C)(stageIndex) + 0x20);
        stageValue = stageProps->get(*(int *)((char *)typeEntry + 8));
        if (((unsigned int)(-stageValue | stageValue) >> 31) != 0)
            *(int *)((char *)info + 12) = stageProps->get(*(int *)((char *)typeEntry + 8));
        nameSlot = (void **)((char *)info + 16);
        *nameSlot = ((void *(*)(int))fn_80204AA4)(stageIndex);
    }
done:
    DIFFICULTY_INFO = (int *)info;

    #undef DIFFICULTY_READY
    #undef DIFFICULTY_INFO
    #undef DIFFICULTY_TAG
    #undef DIFFICULTY_VAL
    #undef INFO_SIZE
}
#pragma dont_inline reset
#pragma cplusplus reset

extern int *sDifficultyInfo;
/* Return the current scene type (field +0 of the published difficulty info block). */
int fn_80204CF0(void) {
#define DIFFICULTY_INFO sDifficultyInfo
    return *DIFFICULTY_INFO;
#undef DIFFICULTY_INFO
}

extern double atof(const char *);
__declspec(section ".sdata") extern const char sDifficultyKeyFormat[];
extern const char sDifficultyNotFoundMsg[];
#pragma cplusplus on
extern "C" int fn_801345D8(void *, int, const char *, ...);
extern "C" double atof(const char *);
extern "C" void Abend_Panic(const char *, ...);
#pragma push
#pragma scheduling invalid_target
/* Read one difficulty setting of the current scene as a number.  The setting is
 * looked up in the difficulty info block fn_80204BB8 published in sDifficultyInfo:
 * first as "<contest>_<name>" in the stage's difficulty set, then in the
 * scene's, and if neither has it as the plain "<name>" in both.  A setting none
 * of them has is reported with the 'Difficulty: "%s" was not found' message and
 * reads as 0.0; the value string the lookup returns is parsed with atof. */
/* Read a current-scene difficulty setting as a float: try the contest-prefixed key in the stage set then scene set, then the plain key; panic if none has it. */ extern "C" float getDifficultySettingFloat(const char *name) {
    /* A difficulty setting set: has() at +0xC, the value string get() at +0x14. */
    class DifficultySet {
    public:
        virtual void unused0();
        virtual int has(void *);
        virtual void unused2();
        virtual int get(void *);
    };
    /* The 0x14-byte block fn_80204BB8 publishes in sDifficultyInfo. */
    struct DifficultyInfo {
        int sceneType;           /* +0x00 */
        void *propertyGroup;     /* +0x04 the "difficulty.val" group */
        DifficultySet *sceneSet; /* +0x08 the scene's difficulty set */
        DifficultySet *stageSet; /* +0x0C the stage's, 0 while none applies */
        const char *contestName; /* +0x10 "excite"/"zone"/"fs", 0 if unknown */
    };
    char key[0x64];
    DifficultyInfo *info;
    int setting = 0;
    int valueString;
    int foundString;
    info = (DifficultyInfo *)sDifficultyInfo;
    if (info->contestName != 0) {
        fn_801345D8(key, 0x64, sDifficultyKeyFormat, info->contestName, name);
        if (info->stageSet != 0 && info->stageSet->has(key)) {
            foundString = info->stageSet->get(key);
        } else if (info->sceneSet->has(key)) {
            foundString = info->sceneSet->get(key);
        } else {
            foundString = 0;
        }
        setting = foundString;
    }
    if (setting == 0) {
        if (info->stageSet != 0 && info->stageSet->has((void *)name)) {
            foundString = info->stageSet->get((void *)name);
        } else if (info->sceneSet->has((void *)name)) {
            foundString = info->sceneSet->get((void *)name);
        } else {
            foundString = 0;
        }
        setting = foundString;
    }
    if (setting == 0) Abend_Panic(sDifficultyNotFoundMsg, name);
    valueString = setting;
    return (float)atof((const char *)valueString);
}
#pragma pop
/* Read one difficulty setting of the current scene as its value string.  The
 * setting is looked up in the difficulty info block fn_80204BB8 published in
 * sDifficultyInfo: first as "<contest>_<name>" in the stage's difficulty set, then
 * in the scene's, and if neither has it as the plain "<name>" in both.  A
 * setting none of them has is reported with the 'Difficulty: "%s" was not
 * found' message and reads as 0.  getDifficultySettingFloat is the same lookup with the
 * string parsed as a number. */
#pragma push
#pragma scheduling invalid_target
extern "C" int getDifficultySettingString(const char *name) {
    /* A difficulty setting set: has() at +0xC, the value string get() at +0x14. */
    class DifficultySet {
    public:
        virtual void unused0();
        virtual int has(void *);
        virtual void unused2();
        virtual int get(void *);
    };
    /* The 0x14-byte block fn_80204BB8 publishes in sDifficultyInfo. */
    struct DifficultyInfo {
        int sceneType;           /* +0x00 */
        void *propertyGroup;     /* +0x04 the "difficulty.val" group */
        DifficultySet *sceneSet; /* +0x08 the scene's difficulty set */
        DifficultySet *stageSet; /* +0x0C the stage's, 0 while none applies */
        const char *contestName; /* +0x10 "excite"/"zone"/"fs", 0 if unknown */
    };
    char key[0x64];
    DifficultyInfo *info;
    int setting = 0;
    int found;
    info = (DifficultyInfo *)sDifficultyInfo;
    if (info->contestName != 0) {
        fn_801345D8(key, 0x64, sDifficultyKeyFormat, info->contestName, name);
        if (info->stageSet != 0 && info->stageSet->has(key)) {
            found = info->stageSet->get(key);
        } else if (info->sceneSet->has(key)) {
            found = info->sceneSet->get(key);
        } else {
            found = 0;
        }
        setting = found;
    }
    if (setting == 0) {
        if (info->stageSet != 0 && info->stageSet->has((void *)name)) {
            found = info->stageSet->get((void *)name);
        } else if (info->sceneSet->has((void *)name)) {
            found = info->sceneSet->get((void *)name);
        } else {
            found = 0;
        }
        setting = found;
    }
    if (setting == 0) Abend_Panic(sDifficultyNotFoundMsg, name);
    return setting;
}
#pragma cplusplus reset

__declspec(section ".sdata") extern const char lbl_8055B4B4[];
__declspec(section ".sdata") extern const char lbl_8055B4B8[];
#pragma cplusplus on
/* Is the current scene's difficulty setting `name` switched on?  The setting is
 * looked up in the difficulty info block fn_80204BB8 published in sDifficultyInfo:
 * first as "<contest>_<name>" in the stage's difficulty set, then in the scene's,
 * and if neither has it as the plain "<name>" in both.  A setting none of them
 * has is reported with the 'Difficulty: "%s" was not found' message and reads as
 * off.  The string the lookup returns is the flag: only "yes" and "true" are on. */
/* Report whether the current scene's difficulty setting `name` is on (via the stage/scene difficulty sets, then the plain name). */ extern "C" int isDifficultySettingOn(const char *settingName) {
    #define DIFFICULTY_INFO sDifficultyInfo  /* the published difficulty info block */
    #define KEY_FORMAT      sDifficultyKeyFormat  /* "%s_%s" */
    #define NOT_FOUND_MSG   sDifficultyNotFoundMsg  /* Difficulty: "%s" was not found */
    #define YES_STRING      lbl_8055B4B4  /* "yes" */
    #define TRUE_STRING     lbl_8055B4B8  /* "true" */
    class DifficultySet {
    public:
        virtual void unused0();
        virtual int has(const char *);
        virtual void unused2();
        virtual int get(const char *);
    };
    /* The 0x14-byte block fn_80204BB8 builds for the scene that is starting. */
    struct DifficultyInfo {
        int sceneType;             /* +0x00 */
        void *propertyGroup;       /* +0x04 the "difficulty.val" group */
        DifficultySet *sceneSet;   /* +0x08 the scene's difficulty set */
        DifficultySet *stageSet;   /* +0x0C the stage's, 0 while none applies */
        const char *contestName;   /* +0x10 "excite"/"zone"/"fs", 0 if unknown */
    };
    char key[0x64];
    DifficultyInfo *info;
    int setting;
    int text;
    int on;
    info = (DifficultyInfo *)DIFFICULTY_INFO;
    setting = 0;
    if (info->contestName != 0) {
        fn_801345D8(key, 0x64, KEY_FORMAT, info->contestName, settingName);
        if (info->stageSet != 0) {
            if (info->stageSet->has(key)) {
                text = info->stageSet->get(key);
                goto done1;
            }
        }
        if (info->sceneSet->has(key)) {
            text = info->sceneSet->get(key);
        } else {
            text = 0;
        }
    done1:
        setting = text;
    }
    if (setting == 0) {
        if (info->stageSet != 0) {
            if (info->stageSet->has(settingName)) {
                text = info->stageSet->get(settingName);
                goto done2;
            }
        }
        if (info->sceneSet->has(settingName)) {
            text = info->sceneSet->get(settingName);
        } else {
            text = 0;
        }
    done2:
        setting = text;
    }
    if (setting == 0) Abend_Panic(NOT_FOUND_MSG, settingName);
    text = setting;
    on = 0;
    if (stricmp((const char *)text, YES_STRING) == 0 ||
        stricmp((const char *)text, TRUE_STRING) == 0) on = 1;
    return on;

    #undef DIFFICULTY_INFO
    #undef KEY_FORMAT
    #undef NOT_FOUND_MSG
    #undef YES_STRING
    #undef TRUE_STRING
}
#pragma cplusplus reset
/* Clear the active contest configuration and release its resources. */
void fn_80205208(void) {
    int *contestConfig = sDifficultyInfo;
    lbl_8055ED58 = 0;
    if (contestConfig != 0) {
        contestConfig[4] = 0;
        contestConfig[2] = 0;
        contestConfig[3] = 0;
        releaseValueFile(contestConfig[1]);
        contestConfig[1] = 0;
        fn_80128668(contestConfig);
    }
}

extern const char lbl_8033BBE4[];
extern void *getValueFile(const char *);
extern int fn_80012854(void);
#pragma push
#pragma dont_inline on
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" int getDifficultyProperty(const char *propName, int typeIndex, int stageIndex) {
    /* Look up a difficulty property string.
     *
     * Opens the "difficulty.val" value group and takes the property set it holds
     * for this scene type's property key (sTypeEntries[typeIndex] + 8).  When
     * stageIndex names a live stage, that stage's own property set and its
     * contest name join the search.  The property is looked for first under the
     * stage-specific name "<contest>_<propName>" and then under the plain
     * propName, testing the stage's set before the type's default one.  Returns
     * the value string; panics if no set defines the property.
     */
    class ValueGroup { public: virtual void *get(int typeKey); };
    class StageProps { public:
        virtual void unused0(); virtual void unused1(); virtual void unused2(); virtual void unused3();
        virtual void unused4(); virtual void unused5(); virtual void unused6(); virtual void unused7();
        virtual void unused8(); virtual void unused9(); virtual void unused10(); virtual void unused11();
        virtual void unused12(); virtual void unused13(); virtual void unused14(); virtual void unused15();
        virtual void unused16(); virtual void unused17(); virtual void unused18(); virtual void unused19();
        virtual void unused20();
        virtual void *get(int typeKey); /* the stage's PropertySet for a scene type */
    };
    class PropertySet { public:
        virtual void unused0();
        virtual int has(const char *name);
        virtual void unused2();
        virtual const char *get(const char *name);
    };
    typedef int (*StringFormat)(void *, int, const char *, ...);
    typedef const char *(*ContestNameOf)(int);
    typedef void *(*StageEntryOf)(int);

    #define DIFFICULTY_VAL   lbl_8033BBE4 /* "difficulty.val" value group */
    #define STAGE_KEY_FORMAT sDifficultyKeyFormat /* "%s_%s" */
    #define NOT_FOUND_PANIC  sDifficultyNotFoundMsg /* 'Difficulty: "%s" was not found' */
    #define KEY_BUF_SIZE     0x64

    volatile struct {
        int typeIndex;
        void *group;   /* ValueGroup opened on "difficulty.val" */
        void *current; /* the type's default PropertySet */
        void *stage;   /* the stage's own PropertySet, if it has one */
        void *contest; /* the stage's contest name, if any */
    } lookup;
    char keyBuf[KEY_BUF_SIZE];
    char *typeEntry;
    int result;
    const char *value;
    void *propSet;
    void *contest;
    void *group;

    lookup.typeIndex = typeIndex;
    lookup.group = 0;
    lookup.current = 0;
    lookup.stage = 0;
    lookup.contest = 0;
    lookup.group = getValueFile(DIFFICULTY_VAL);
    typeEntry = (char *)fn_80204B18(typeIndex);
    lookup.current = ((ValueGroup *)lookup.group)->get(*(int *)(typeEntry + 8));
    if (stageIndex >= 0 && stageIndex < fn_80012854()) {
        void *stageProps = *(void **)((char *)((StageEntryOf)fn_8001285C)(stageIndex) + 0x20);
        int stageHasValue = ((StageProps *)stageProps)->get(*(int *)(typeEntry + 8)) != 0;
        if (stageHasValue) {
            lookup.stage = ((StageProps *)stageProps)->get(*(int *)(typeEntry + 8));
        }
        lookup.contest = (void *)((ContestNameOf)fn_80204AA4)(stageIndex);
    }
    result = 0;
    contest = lookup.contest;
    if (contest != 0) {
        /* "<contest>_<propName>": the contest-specific spelling of the property. */
        ((StringFormat)fn_801345D8)(keyBuf, KEY_BUF_SIZE, STAGE_KEY_FORMAT, contest, propName);
        propSet = lookup.stage;
        if (propSet != 0 && ((PropertySet *)propSet)->has(keyBuf) != 0) {
            propSet = lookup.stage;
            value = ((PropertySet *)propSet)->get(keyBuf);
        } else {
            propSet = lookup.current;
            if (((PropertySet *)propSet)->has(keyBuf) != 0) {
                propSet = lookup.current;
                value = ((PropertySet *)propSet)->get(keyBuf);
            } else {
                value = 0;
            }
        }
        result = (int)value;
    }
    if (result == 0) {
        /* Fall back to the plain property name. */
        propSet = lookup.stage;
        if (propSet != 0 && ((PropertySet *)propSet)->has(propName) != 0) {
            propSet = lookup.stage;
            value = ((PropertySet *)propSet)->get(propName);
        } else {
            propSet = lookup.current;
            if (((PropertySet *)propSet)->has(propName) != 0) {
                propSet = lookup.current;
                value = ((PropertySet *)propSet)->get(propName);
            } else {
                value = 0;
            }
        }
        result = (int)value;
    }
    if (result == 0) Abend_Panic(NOT_FOUND_PANIC, propName);
    group = lookup.group;
    lookup.contest = 0;
    lookup.current = 0;
    lookup.stage = 0;
    releaseValueFile((int)group);
    lookup.group = 0;
    return result;

    #undef DIFFICULTY_VAL
    #undef STAGE_KEY_FORMAT
    #undef NOT_FOUND_PANIC
    #undef KEY_BUF_SIZE
}
class PropSet802054EC { public: virtual void f0(); virtual int has(const char *); virtual void f2(); virtual const char *get(const char *); };
struct Lookup802054EC { int typeIndex; void *group; void *current; void *stage; void *contest; };
static inline const char *FindProp802054EC(volatile Lookup802054EC *l, const char *name) {
    void *set = l->stage;
    if (set != 0 && ((PropSet802054EC *)set)->has(name) != 0) {
        set = l->stage;
        return ((PropSet802054EC *)set)->get(name);
    }
    set = l->current;
    if (((PropSet802054EC *)set)->has(name) != 0) {
        set = l->current;
        return ((PropSet802054EC *)set)->get(name);
    }
    return 0;
}
class DiffLookup802054EC {
public:
    int typeIndex;
    void *group;
    void *current;
    void *stage;
    void *contest;
    DiffLookup802054EC(int type, int stageIndex);
    ~DiffLookup802054EC() {
        void *g = group;
        contest = 0;
        current = 0;
        stage = 0;
        releaseValueFile((int)g);
        group = 0;
    }
    const char *Find(const char *name) {
        void *set = stage;
        if (set != 0 && ((PropSet802054EC *)set)->has(name) != 0) {
            set = stage;
            return ((PropSet802054EC *)set)->get(name);
        }
        set = current;
        if (((PropSet802054EC *)set)->has(name) != 0) {
            set = current;
            return ((PropSet802054EC *)set)->get(name);
        }
        return 0;
    }
};
inline DiffLookup802054EC::DiffLookup802054EC(int type, int stageIndex) {
    class ValueGroup { public: virtual void *get(int); };
    class StageProps { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void *get(int); };
    char *entry;
    typeIndex = type;
    group = 0;
    current = 0;
    stage = 0;
    contest = 0;
    group = getValueFile(lbl_8033BBE4);
    entry = (char *)((void *(*)(int))fn_80204B18)(type);
    current = ((ValueGroup *)group)->get(*(int *)(entry + 8));
    if (stageIndex >= 0 && stageIndex < fn_80012854()) {
        void *props = *(void **)((char *)((void *(*)(int))fn_8001285C)(stageIndex) + 0x20);
        int ok = ((StageProps *)props)->get(*(int *)(entry + 8)) != 0;
        if (ok) {
            stage = ((StageProps *)props)->get(*(int *)(entry + 8));
        }
        contest = ((void *(*)(int))fn_80204AA4)(stageIndex);
    }
}
#pragma dont_inline off
/* Read a difficulty property as a boolean: true when its value string is "yes" or "true", checking the stage-specific key before the plain name. */ extern "C" int Difficulty_ReadBool(const char *propName, int typeIndex, int stageIndex) {
    /* Read a difficulty property as a boolean: resolve its value string first under the
     * stage-specific "<contest>_<propName>" key, then under the plain name, panicking if
     * no set defines it; return 1 when the value is "yes" or "true", otherwise 0. */
    #define STAGE_KEY_FORMAT sDifficultyKeyFormat /* "%s_%s" */
    #define NOT_FOUND_PANIC  sDifficultyNotFoundMsg /* 'Difficulty: "%s" was not found' */
    #define YES_VALUE        lbl_8055B4B4 /* "yes" */
    #define TRUE_VALUE       lbl_8055B4B8 /* "true" */
    #define KEY_BUF_SIZE     0x64
    DiffLookup802054EC lookup(typeIndex, stageIndex);
    char keyBuf[KEY_BUF_SIZE];
    const char *value = 0;
    void *contestName = lookup.contest;
    int isYes;
    if (contestName != 0) {
        ((int (*)(void *, int, const char *, ...))fn_801345D8)(keyBuf, KEY_BUF_SIZE, STAGE_KEY_FORMAT, contestName, propName);
        value = lookup.Find(keyBuf);
    }
    if (value == 0) {
        value = lookup.Find(propName);
    }
    if (value == 0) Abend_Panic(NOT_FOUND_PANIC, propName);
    isYes = 1;
    if (stricmp(value, YES_VALUE) != 0 && stricmp(value, TRUE_VALUE) != 0) isYes = 0;
    return isYes;
    #undef STAGE_KEY_FORMAT
    #undef NOT_FOUND_PANIC
    #undef YES_VALUE
    #undef TRUE_VALUE
    #undef KEY_BUF_SIZE
}
