// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int __equals_dec(void *a, void *b) {
    unsigned char *x = (unsigned char *)a;
    unsigned char *y = (unsigned char *)b;
    unsigned char c;
    int nx;
    int ny;
    int i;
    int n;

    c = x[5];
    if (c == 0) return y[5] == 0;
    if (y[5] == 0) return c == 0;
    if (*(short *)(x + 2) == *(short *)(y + 2)) {
        nx = x[4];
        ny = y[4];
        n = nx;
        if (nx > ny) n = ny;
        for (i = 0; i < n; i++) {
            if (x[i + 5] != y[i + 5]) return 0;
        }
        if (n == nx) x = y;
        for (; i < x[4]; i++) {
            if (x[i + 5] != 0) return 0;
        }
        return 1;
    }
    return 0;
}

/* Returns 1 if the decimal value in lhs is less than rhs, 0 otherwise. */
int __less_dec(void *lhs, void *rhs)
{
  unsigned char *lhs_bytes = (unsigned char *) lhs;
  unsigned char *rhs_bytes = (unsigned char *) rhs;
  int lhs_len;
  int rhs_len;
  int i;
  int min_len;
  unsigned char *rhs_len_ptr;
  if (lhs_bytes[5] == 0)
  {
    return rhs_bytes[5] != 0;
  }
  if (rhs_bytes[5] == 0)
  {
    return 0;
  }
  if ((*((short *) (lhs_bytes + 2))) == (*((short *) (rhs_bytes + 2))))
  {
    lhs_len = lhs_bytes[4];
    rhs_len = rhs_bytes[4];
    rhs_len_ptr = &rhs_bytes[4];
    min_len = lhs_len;
    if (lhs_len > rhs_len)
    {
      min_len = rhs_len;
    }
    for (i = 0; i < min_len; i++)
    {
      if (lhs_bytes[i + 5] < rhs_bytes[i + 5])
      {
        return 1;
      }
      if (rhs_bytes[i + 5] < lhs_bytes[i + 5])
      {
        return 0;
      }
    }

    if (min_len == lhs_len)
    {
      for (; i < (*rhs_len_ptr); i++)
      {
        if (rhs_bytes[i + 5] != 0)
        {
          return 1;
        }
      }

    }
    return 0;
  }
  return (*((short *) (lhs_bytes + 2))) < (*((short *) (rhs_bytes + 2)));
}

