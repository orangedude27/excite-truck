// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef int s32;
typedef unsigned char u8;
s32 fn_80128670(s32);
s32 fn_80131818(s32);
s32 fn_802E317C(const char *, ...);
extern void* fn_8012850C(s32, const char*);
extern void* fn_80131808(const char*);
extern int fn_801345D8(char*, int, const char*, ...);
extern void* memset(void*, int, unsigned long);
static char lbl_802FD1B0[] = "car_stats.val";
static char lbl_802FD1C0[] = "carstats";
static char lbl_802FD1CC[] = "car_stats";
static char lbl_802FD1D8[] = "stat_name_%d";
static char lbl_802FD1E8[] = "stat_value_%d";
static char lbl_802FD1F8[] = "stat table for %s has too many stats (limit: %d)";
static char lbl_802FD22C[] = "stat table for %s has no stats! (maybe you didn't number from 1)";
struct Tbl8001880C {
    char f0[0x10];
    char f10[0xC];
    char f1C[0xC];
    char f28[0x10];
    char f38[0x10];
    char f48[0x34];
    char f7C[0x44];
};

extern const char lbl_80558C28[4];
typedef unsigned int u32;
#pragma cplusplus on
struct Item_8001880C {
    virtual const char* getName();
    virtual int hasKey(const char*);
    virtual void slot2();
    virtual int getA(const char*);
    virtual void slot4();
    virtual int getB(const char*);
};
struct Dir_8001880C {
    virtual void slot0();
    virtual Item_8001880C* getAt(int);
};
#pragma cplusplus reset
int stricmp(const char *, const char *);
extern u8 lbl_8055D570;
extern s32 lbl_8055D574;
extern s32 lbl_8055D578;
extern s32 lbl_8055D57C;
extern const char lbl_802FD270[];
#pragma cplusplus on
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
extern "C" void fn_8001880C(void)
{
  char buf1[0x14];
  char buf2[0x14];
  int off;
  struct Tbl8001880C *base = (struct Tbl8001880C *) lbl_802FD1B0;
  int *p;
  int count;
  Item_8001880C *item1;
  Item_8001880C *item2;
  int idx;
  int *rec;
  u32 n;
  lbl_8055D570 = 1;
  lbl_8055D574 = (s32) fn_80131808(base->f0);
  lbl_8055D57C = 0;
  idx = 0;
  while ((item1 = ((Dir_8001880C *) lbl_8055D574)->getAt(idx)) != 0)
  {
    if ((stricmp(item1->getName(), base->f10) == 0) && (item1->hasKey(lbl_80558C28) != 0))
    {
      lbl_8055D57C++;
    }
    idx++;
  }

  lbl_8055D578 = (s32) fn_8012850C(lbl_8055D57C * 0x2C, base->f1C);
  off = 0;
  count = 0;
  while ((item2 = ((Dir_8001880C *) lbl_8055D574)->getAt(count)) != 0)
  {
    if ((stricmp(item2->getName(), base->f10) == 0) && (item2->hasKey(lbl_80558C28) != 0))
    {
      rec = (int *)(lbl_8055D578 + off);
      off += 0x2C;
      memset(rec, 0, 0x2C);
      rec[0] = item2->getA(lbl_80558C28);
      p = rec;
      n = 0;
      while (1)
      {
        fn_801345D8(buf1, 0x14, base->f28, n + 1);
        fn_801345D8(buf2, 0x14, base->f38, n + 1);
        if ((item2->hasKey(buf1) == 0) || (item2->hasKey(buf2) == 0))
        {
          break;
        }
        if (n >= 5)
        {
          fn_802E317C(base->f48, rec[0], 5);
        }
        p[1] = item2->getA(buf1);
        *(p += 2) = item2->getB(buf2);
        n++;
      }

      if (n == 0)
      {
        fn_802E317C(base->f7C, rec[0]);
      }
    }
    count++;
  }

}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
s32 fn_80018A8C(const char *arg0) {
    s32 offset = 0;
    s32 i = 0;
    while (i < lbl_8055D57C) {
        if (stricmp(*(char **)((char *)lbl_8055D578 + offset), arg0) == 0)
            return (s32)((char *)lbl_8055D578 + i * 0x2C);
        offset += 0x2C;
        i++;
    }
    fn_802E317C(lbl_802FD270, arg0);
    return 0;
}
#pragma pop

/* RealName: CarStats_Shutdown (see the comment in the body). */
#pragma cplusplus reset

void fn_80018B24(void) {
    /* RealName: CarStats_Shutdown
     * Tears down the car stats table that fn_8001880C built out of the
     * "car_stats.val" parameter file: marks the table unused, frees the
     * record array off the "car_stats" heap, clears the table pointer and
     * its count, and releases the parameter directory it was read from. */
    struct CarStat {
        char *chassisName; /* 0x00: value of the item's "chassis" key */
        struct {
            char *name;    /* 0x04: "stat_name_%d" */
            s32 value;     /* 0x08: "stat_value_%d" */
        } stat[5];         /* 0x04..0x2C: five stats per chassis */
    };                     /* sizeof == 0x2C, the table's record size */

#define carStatsInUse lbl_8055D570 /* cleared once the table is released */
#define carStatDir    lbl_8055D574 /* directory of "car_stats.val" */
#define carStatTable  lbl_8055D578 /* CarStat records, carStatCount of them */
#define carStatCount  lbl_8055D57C /* records in carStatTable */
#define MemFree       fn_80128670  /* free off the heap the block came from */
#define ParamRelease  fn_80131818  /* drop a loaded parameter directory */

    carStatsInUse = 0;
    MemFree(carStatTable);
    carStatTable = 0;
    carStatCount = 0;
    ParamRelease(carStatDir);

#undef carStatsInUse
#undef carStatDir
#undef carStatTable
#undef carStatCount
#undef MemFree
#undef ParamRelease
}
