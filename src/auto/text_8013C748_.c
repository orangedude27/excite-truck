// Code of main that had no source file yet: decomp.wtf gave it this one.

#pragma cplusplus on
class SearchObject {
public:
    virtual const char *name();
};
class SearchManager {
public:
    virtual void v0();
    virtual SearchObject *get(int);
};
#pragma cplusplus off
// split_file divides it into the game's real files (file_status shows its range).

void *fn_8013C7D0();

extern int lbl_8055E188;
void fn_80131818(int);
void fn_8013C748(void);
#define CarClassManager lbl_8055E188   /* loaded "carclass.val" search manager */
#define ClearClassCache fn_8013C748    /* clear cached objects in the class registry */
#define ReleaseLoaded   fn_80131818    /* release a loaded resource */

extern char lbl_8032C478[];
void fn_8013C748(void) {
    #pragma scheduling invalid_target
    int *p = (int *)&lbl_8032C478;
    while (*p != 0) {
        p[2] = 0;
        p += 3;
    }
}

#pragma dont_inline on
#pragma scheduling invalid_target
/* Finds the 12-byte registry entry in lbl_8032C478 whose name matches (case-insensitive), returning a pointer to the entry (or the null terminator entry if not found). */
void *fn_8013C770(const char *name) {
    int *entry;

    entry = (int *)&lbl_8032C478;
    goto loop_test;
loop_body:
    if (stricmp(name, (const char *)*entry) != 0) {
        goto loop_next;
    }
    goto done;
loop_next:
    entry += 3;
loop_test:
    if (*entry != 0) {
        goto loop_body;
    }
done:
    return entry;
}

#pragma dont_inline on
#pragma scheduling invalid_target
/* Find the car-class registry entry in lbl_8032C478 whose class-type field (+4)
 * equals classType. Returns a pointer to the matching 12-byte entry, or to the
 * zero-terminator entry when no type matches. */
void *fn_8013C7D0(classType)
int classType;
{
    int *classEntry;
    classEntry = (int *)&lbl_8032C478;
    goto loop_test;
loop_body:
    if (classType == *(classEntry + 1)) {
        goto done;
    }
    classEntry += 3;
loop_test:
    if (*classEntry != 0) {
        goto loop_body;
    }
done:
    return classEntry;
}
#pragma scheduling on
#pragma dont_inline off

/* Wrapper around the car-class registry lookup by class type (fn_8013C7D0):
 * the class type arrives in r3 and the matching 12-byte entry pointer leaves
 * in r3, so this is a plain tail call. */
void *fn_8013C800(int classType) {
    return fn_8013C7D0(classType);
}

extern int fn_80131808(int);
extern void fn_802E317C(int, ...);
extern char lbl_8032C4C0[];
extern char lbl_8032C4D0[];
#pragma cplusplus on
extern "C" int fn_80131808(int);
extern "C" void fn_802E317C(int, ...);
extern "C" void fn_8013C748(void);
extern "C" void *fn_8013C770(const char *);
extern "C" char lbl_8032C4C0[];
extern "C" char lbl_8032C4D0[];
extern "C" int lbl_8055E188;
#pragma cplusplus on
#pragma dont_inline on
extern "C" void fn_8013C804(void) {
    /* Load the "carclass.val" search manager, then for each returned object look up
     * its registry entry by name and, unless the entry's type (+4) is 6, store the
     * object pointer at +8. Reports an error if the manager cannot be loaded. */
    SearchObject *managerObject;
    const char *objectName;
    void *registryEntry;
    int objectIndex;

    fn_8013C748();
    lbl_8055E188 = fn_80131808((int)lbl_8032C4C0);
    if (lbl_8055E188 != 0) {
        objectIndex = 0;
        goto get_object;
    }
    goto report_error;
loop_body:
    objectName = managerObject->name();
    registryEntry = fn_8013C770(objectName);
    if (*(int *)((char *)registryEntry + 4) != 6) {
        *(void **)((char *)registryEntry + 8) = managerObject;
    }
    objectIndex += 1;
get_object:
    managerObject = ((SearchManager *)lbl_8055E188)->get(objectIndex);
    if (managerObject != 0) {
        goto loop_body;
    }
    return;
report_error:
    fn_802E317C((int)lbl_8032C4D0);
}
#pragma dont_inline off
#pragma cplusplus off

#pragma dont_inline on
/* Tear down the car-class search manager: clear cached objects in the class
 * registry, release the loaded manager and clear the global. */
void fn_8013C8B8(void) {
    ClearClassCache();
    ReleaseLoaded(CarClassManager);
    CarClassManager = 0;
}
#pragma dont_inline off
void *fn_8013C770();
extern int lbl_8055E188;
void fn_80131818(int);
void fn_8013C748(void);
__declspec(section ".sdata") extern char lbl_80559D10[];
int stricmp(const char *, const char *);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
/* Searches the five car-class registry entries for a chassis whose name matches
 * chassisName (case-insensitive). Returns the entry's class type (+4) on a match,
 * otherwise 6 when no chassis matches. */
extern "C" int fn_8013C8E8(const char *chassisName) {
    class ChassisResult {
    public:
        virtual void v0();
        virtual void v1();
        virtual int query(int, int *, const char **) volatile;
    };
    class ChassisList {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual ChassisResult *get(const char *);
    };
    int classIndex;
    ChassisResult *chassis;
    int resultIndex;
    int unusedIndex;
    const char *candidateName;
    void *classEntry;

    classIndex = 0;
    do {
        classEntry = ((void *(*)(int))fn_8013C800)(classIndex);
        chassis = ((ChassisList *)*(void **)((char *)classEntry + 8))->get(lbl_80559D10);
        for (resultIndex = 0; ((volatile ChassisResult *)chassis)->query(resultIndex, &unusedIndex, &candidateName) != 0; resultIndex++) {
            if (stricmp(candidateName, chassisName) == 0)
                return *(int *)((char *)classEntry + 4);
        }
        classIndex++;
    } while (classIndex < 5);
    return 6;
}
#pragma cplusplus off
#pragma scheduling on
#pragma pop
int fn_8013C9A4(void) {
    /* Return the class-type field (+4) of the car-class registry entry found by fn_8013C770. */
    void *entry = fn_8013C770();
    return *(int *)((char *)entry + 4);
}

/* fn_8013C800 forwards to the car-class registry lookup that returns a 12-byte entry. */
typedef int *(*CarClassEntryLookup)(void);

int fn_8013C9C8(void) {
    /* Return the first field of the car-class registry entry returned by fn_8013C800. */
    CarClassEntryLookup getEntry = (CarClassEntryLookup)fn_8013C800;
    return *getEntry();
}

void *fn_8013C770();
extern int lbl_8055E188;
void fn_80131818(int);
void fn_8013C748(void);
extern char lbl_80559D10[];
int stricmp(const char *, const char *);
