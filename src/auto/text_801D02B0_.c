// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

  extern char lbl_8055E8C0;
      extern char lbl_80338098[];
  extern char lbl_802F9940[];
  extern char lbl_8033819C[];
  extern int stricmp(const char *, const char *);
  extern int Abend_Panic(const char *, ...);
  typedef struct { const char *name; int value; } Entry;
      typedef struct { char bytes[0x14]; } Record;
typedef struct SurfObj SurfObj;
typedef struct {
    int pad0, pad1;
    SurfObj *(*get)(SurfObj *, char *);
    int pad3;
    int (*has)(SurfObj *, char *);
    int pad5, pad6, pad7;
    int (*getInt)(SurfObj *, const char *, int);
    int pad9;
    float (*getFloat)(SurfObj *, const char *, float);
} SurfVT;
struct SurfObj { SurfVT *vt; };
extern SurfObj *getValueFile(char *);
extern SurfObj *fn_80131810(char *);
extern void fn_80131818(SurfObj *);
extern int sprintf(char *, const char *, ...);
extern char lbl_8055AB58, lbl_8055AB60, lbl_8055AB68, lbl_8055AB70, lbl_8055AB78;
typedef struct { float f[3]; signed char b0; unsigned char b1; short pad; int i; } SurfRec;
/* Clear the surface-record initialization flag at lbl_8055E8C0 (set by fn_801D02B0). */
#pragma cplusplus on
#pragma opt_propagation off
#pragma scheduling invalid_target
extern "C" void fn_801D02B0(void) {
    class SurfObjV {
    public:
        virtual SurfObjV *get(char *);
        virtual void f3();
        virtual int has(char *);
        virtual void f5(); virtual void f6(); virtual void f7();
        virtual int getInt(const char *, int);
        virtual void f9();
        virtual float getFloat(const char *, float);
    };
    struct SurfTable { SurfRec recs[8]; };
    char buf[0x40];
    char *base;
    SurfRec *rec;
    SurfObjV *a;
    SurfObjV *b;
    int i;
    SurfObjV *item;
    base = lbl_80338098;
    lbl_8055E8C0 = 1;
    a = (SurfObjV *)getValueFile(base + 0xA0);
    b = (SurfObjV *)fn_80131810(base + 0xB0);
    rec = &((struct SurfTable *)base)->recs[0];
    i = 0;
    do {
        sprintf(buf, base + 0xBC, i);
        item = 0;
        if (b != 0 && b->has(buf)) {
            item = b->get(buf);
        } else if (a->has(buf)) {
            item = a->get(buf);
        }
        if (item != 0) {
            rec->f[0] = item->getFloat(&lbl_8055AB58, rec->f[0]);
            rec->f[1] = item->getFloat(&lbl_8055AB60, rec->f[1]);
            rec->f[2] = item->getFloat(&lbl_8055AB68, rec->f[2]);
            rec->b0 = item->getInt(&lbl_8055AB70, rec->b0);
            rec->b1 = item->getInt(&lbl_8055AB78, rec->b1);
            rec->i = item->getInt(base + 0xC8, i);
        }
        i++;
        rec++;
    } while (i < 8);
    fn_80131818((SurfObj *)a);
    if (b != 0)
        fn_80131818((SurfObj *)b);
}
#pragma scheduling on
#pragma opt_propagation reset
#pragma cplusplus off

void fn_801D049C(void) {
    lbl_8055E8C0 = 0;
}
  
/* Return surface record `index` from the 8-entry table, clamping out-of-range indices to 0. */
SurfRec *fn_801D04A8(int index) {
    if (index < 0 || index >= 8)
        index = 0;
    return &((SurfRec *)lbl_80338098)[index];
}
  
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
/* Look up a surface type name in the 13-entry table at lbl_802F9940
   ({name,value}: default->100, concrete->101, metal->105, plastic->106,
   rubber->107, wood->108, hay->110, water->111, powerup/glass?->1000,
   magic_concrete/dirt?->114, tree/grass?->115, tree_fragile/mud?->116,
   spring/sand?->1002). Copies the table to the stack, returns the matching
   value on a case-insensitive match, or logs lbl_8033819C
   "surftype: invalid surface type '%s'" via Abend_Panic and returns 100. */
int fn_801D04D0(const char *surfaceName) {
    Entry surfaceTable[13];
    unsigned int index;
    int *dst = (int *)surfaceTable - 1;
    int *src = (int *)lbl_802F9940 - 1;
    index = 13;
    while (index) {
        index--;
        *++dst = *++src;
        *++dst = *++src;
    }
    for (index = 0; index < 13; index++) {
        if (stricmp(surfaceName, surfaceTable[index].name) == 0)
            return surfaceTable[index].value;
    }
    Abend_Panic(lbl_8033819C, surfaceName);
    return 100;
}
#pragma pop
