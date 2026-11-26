// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_802ED860[];
extern void *memAlloc(void *, unsigned int, unsigned int *);
extern void *fn_80021F88(void *, unsigned int, unsigned int *);
extern void fn_80022064(void *, void *, void *, int, void *, int);
void *fn_80022188(void *arg0, unsigned int arg1, unsigned int *arg2)
{
  unsigned int spC;
  unsigned int sp8;
  unsigned int *p = lbl_802ED860;
  unsigned char *pool;
  int i = 0;
  unsigned char *p29;
  unsigned int cnt;
  unsigned int n23;
  unsigned int sz;
  unsigned int sz2;
  int r8;
  unsigned char *h;
  unsigned char *r5;
  while (arg1 > (*p))
  {
    p++;
    i++;
  }

  pool = ((unsigned char *) arg0) + (i * 8);
  h = *((unsigned char **) (pool + 8));
  if ((h == 0) || ((*((unsigned int *) (h + 0xC))) == 0))
  {
#pragma opt_common_subs off
    cnt = 0xFEC / (lbl_802ED860[i] + 4);
#pragma opt_common_subs on
    if (cnt > 0x100)
    {
      cnt = 0x100;
    }
    n23 = cnt;
    {
      unsigned int *tbl = lbl_802ED860;
      sz = (0, (*((volatile unsigned int *) (&tbl[i]))) + 4);
      while (cnt >= 10)
      {
        p29 = (unsigned char *) fn_80021F88(arg0, (cnt * sz) + 0x14, &spC);
        if (p29 != 0)
        {
          break;
        }
        if (spC > 0x14)
        {
          cnt = (spC - 0x14) / sz;
        }
        else
        {
          cnt = 0;
        }
      }

      if (p29 == 0)
      {
        sz = tbl[i] + 4;
        sz2 = tbl[i] + 0x18;
        for (;;)
        {
          p29 = (unsigned char *) memAlloc(arg0, (n23 * sz) + 0x14, &sp8);
          if (p29 != 0)
          {
            break;
          }
          n23 = sp8 / sz2;
          if (n23 < 10)
          {
            if (arg2 != 0)
            {
              *arg2 = 0;
            }
            return 0;
          }
        }

      }
    }
    {
      unsigned int t = *((unsigned int *) (p29 - 4));
      if ((t & 1) == 0)
      {
        r8 = *((int *) (t + 8));
      }
      else
      {
        r8 = ((*((unsigned int *) (p29 - 8))) & (~7)) - 8;
      }
    }
    if ((*((void **) (pool + 8))) == 0)
    {
      *((void **) (pool + 8)) = p29;
      *((void **) (pool + 4)) = p29;
    }
    fn_80022064(p29, *((void **) (pool + 4)), *((void **) (pool + 8)), i, p29 + 0x14, r8 - 0x14);
    *((void **) (pool + 8)) = p29;
  }
  h = *((unsigned char **) (pool + 8));
  r5 = *((unsigned char **) (h + 0xC));
  *((unsigned int *) (h + 0xC)) = *((unsigned int *) (r5 + 4));
  h = *((unsigned char **) (pool + 8));
  *((int *) (h + 0x10)) = (*((int *) (h + 0x10))) + 1;
  h = *((unsigned char **) (pool + 8));
  if ((*((unsigned int *) (h + 0xC))) == 0)
  {
    *((unsigned int *) (pool + 8)) = *((unsigned int *) (h + 4));
    *((unsigned int *) (pool + 4)) = *((unsigned int *) ((*((unsigned char **) (pool + 4))) + 4));
  }
  if (arg2 != 0)
  {
    *arg2 = lbl_802ED860[i];
  }
  return r5 + 4;
}
