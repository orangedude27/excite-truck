// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055D5A0;
extern int strlen(const char *);
extern int strncmp(const char *, const char *, unsigned int);
extern unsigned char lbl_802FE850[];
#pragma use_lmw_stmw off
char *fn_80019898(const char *s, const char *needle)
{
  register const char *nd = needle;
  register char *p = (char *) s;
  register void *tableRoot;
  register char *result = 0;
  register unsigned char byte;
  register int c;
  register int flag;
  unsigned char *new_var;
  const unsigned short *table;
  byte = strlen(nd);
  tableRoot = *((void **) (lbl_802FE850 + 0x38));
  goto candidate;
  main_loop:
  p++;

  candidate:
  byte = *p;

  if (((signed char) byte) == 0)
  {
    c = (signed char) byte;
    goto try_match;
  }
  flag = 0;
  if (((signed char) byte) < 0)
  {
    goto first_set;
  }
  if ((byte ^ 0) < 0x100)
  {
    goto first_check;
  }
  new_var = ((unsigned char *) tableRoot) + 8;
  first_set:
  flag = 1;

  first_check:
  if (flag != 0)
  {
    flag = 0;
    goto first_done;
  }

  table = *((const unsigned short **) new_var);
  flag = table[c] & 0x100;
  first_done:
  if (flag != 0)
  {
    goto main_loop;
  }

  try_match:
  if (strncmp(p, nd, byte) == 0)
  {
    result = p;
    goto done;
  }

  if (((signed char) byte) == 0)
  {
    goto done;
  }
  goto scan_loop;
  scan_advance:
  p++;

  scan_loop:
  byte = *p;

  c = (signed char) byte;
  if (c == 0)
  {
    goto candidate;
  }
  flag = 0;
  if (c < 0)
  {
    goto second_set;
  }
  if (c < 0x100)
  {
    goto second_check;
  }
  second_set:
  flag = 1;

  second_check:
  if (flag)
  {
    flag = 0;
    goto second_done;
  }

  table = *((const unsigned short **) new_var);
  flag = table[c] & 0x100;
  second_done:
  if (flag)
  {
    goto candidate;
  }

  goto scan_advance;
  done:
  return result;

}
#pragma use_lmw_stmw reset
extern unsigned char lbl_802FD528[];
extern char *fn_80019898(const char *, const char *);
extern unsigned char lbl_802FD528[];
extern char *fn_80019898(const char *, const char *);
#pragma scheduling invalid_target
#pragma optimize_for_size on
#pragma use_lmw_stmw off
#pragma unroll off
void fn_800199B8(const char *arg0) {
    register unsigned int *entry;
    register char *result;
    register const char *name;
    register unsigned char *input;
    register unsigned char *localeBase;
    register unsigned int clearCount = 0x20;
    char buffer[256];
    register unsigned int *clear;
    register char *src;
    register int count;
    register char *dst;
    unsigned int i;
    register int c;
    int flag;
    void *tableRoot;
    const unsigned short *table;
    lbl_8055D5A0 = 0;
    entry = (unsigned int *)lbl_802FD528;
    input = (unsigned char *)arg0;
    localeBase = lbl_802FE850;
    while (entry[0] != 0) {
        result = ((char *(*)(const char *))fn_80019898)((const char *)input);
        if (result != 0) {
            lbl_8055D5A0 |= entry[1];
            if (entry[2] != 0) {
                clear = (unsigned int *)((char *)buffer - 4);
                for (i = 0; i < clearCount; i++) {
                    clear[1] = 0;
                    clear += 2;
                    clear[0] = 0;
                }
                name = (const char *)entry[0];
                if (result[strlen(name)] == ':') {
                    src = result + strlen(name);
                    dst = buffer;
                    count = 0x100;
                    src++;
                    goto copy_chars;
copy_limit:
                    count--;
                    if (count > 0)
                        goto copy_chars;
                    dst[-1] = 0;
                    goto copy_done;
copy_chars:
                    c = (unsigned char)*src++;
                    *dst++ = (char)c;
                    if ((signed char)c != 0)
                        goto copy_limit;
copy_done:
                    dst = buffer;
                    tableRoot = *(void **)(localeBase + 0x38);
                    goto scan_loop;
scan_loop:
                    dst++;
                    c = (signed char)*dst;
                    if (c == 0)
                        goto scan_done;
                    flag = 0;
                    if (c < 0)
                        goto invalid_char;
                    if (c < 0x100)
                        goto valid_char;
invalid_char:
                    flag = 1;
valid_char:
                    if (flag != 0) {
                        flag = 0;
                        goto checked_char;
                    }
                    table = *(const unsigned short **)((char *)tableRoot + 8);
                    flag = table[c] & 0x100;
checked_char:
                    if (flag == 0)
                        goto scan_loop;
                    *dst = 0;
scan_done:
                    ((void (*)(char *))entry[2])(buffer);
                }
            }
        }
        entry += 3;
    }
    if (lbl_8055D5A0 & 0x24)
        lbl_8055D5A0 |= 1;
}
#pragma unroll reset
#pragma use_lmw_stmw on
#pragma optimize_for_size reset
#pragma scheduling on
/* Return bit 0 of the locale/language flag word assembled by fn_800199B8. */
int fn_80019B3C(void) { return lbl_8055D5A0 & 1; }

int fn_80019B48(void) {
    /* Return bit 1 of the parsed command-line option mask: the "-model_test" flag set by fn_800199B8. */
    return (lbl_8055D5A0 >> 1) & 1;
}

/* Return bit 2 of the locale/language flag word assembled by fn_800199B8. */
int fn_80019B54(void) { return (lbl_8055D5A0 >> 2) & 1; }

int fn_80019B60(void) { return (lbl_8055D5A0 >> 3) & 1; }

/* Return bit 6 of the locale/language flag word assembled by fn_800199B8. */
int fn_80019B6C(void) { return (lbl_8055D5A0 >> 6) & 1; }

/* Return bit 7 of the locale/language flag word assembled by fn_800199B8. */
int fn_80019B78(void) { return (lbl_8055D5A0 >> 7) & 1; }

/* Return bit 8 of the locale/language flag word assembled by fn_800199B8. */
int fn_80019B84(void) { return (lbl_8055D5A0 >> 8) & 1; }

/* Return bit 12 of the locale/language flag word assembled by fn_800199B8. */
int fn_80019B90(void) { return (lbl_8055D5A0 >> 12) & 1; }

/* Return bit 9 of the locale/language flag word assembled by fn_800199B8. */
int fn_80019B9C(void) { return (lbl_8055D5A0 >> 9) & 1; }

/* Return bit 10 of the locale/language flag word assembled by fn_800199B8. */
int fn_80019BA8(void) { return (lbl_8055D5A0 >> 10) & 1; }

