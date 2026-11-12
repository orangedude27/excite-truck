// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

  extern char lbl_8055E8C0;
      extern char lbl_80338098[];
  extern char lbl_802F9940[];
  extern char lbl_8033819C[];
  extern int stricmp(const char *, const char *);
  extern int fn_802E317C(const char *, ...);
  typedef struct { const char *name; int value; } Entry;
  typedef struct { char bytes[0x14]; } Record;
  void fn_801D049C(void) {
      lbl_8055E8C0 = 0;
  }
  
void *fn_801D04A8(int arg0) {
    if (arg0 < 0 || arg0 >= 8)
        arg0 = 0;
    return &lbl_80338098[arg0 * 0x14];
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
   "surftype: invalid surface type '%s'" via fn_802E317C and returns 100. */
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
    fn_802E317C(lbl_8033819C, surfaceName);
    return 100;
}
#pragma pop
