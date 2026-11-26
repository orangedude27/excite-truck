// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562B38;
extern float lbl_80562B3C;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern void *getResourceData(void *, int, int *, int, int, u8 *);
extern void Abend_Panic(const char *, ...);
extern char lbl_80339200[];
extern char lbl_80339218[];
#define SWAP2(q, a, b) do { u8 t = (q)[a]; (q)[a] = (q)[b]; (q)[b] = t; } while (0)
#define SWAP4(q, o) do { SWAP2(q, (o), (o) + 3); SWAP2(q, (o) + 1, (o) + 2); } while (0)
#define SWAP2T(q, a, b, t) do { (t) = (q)[a]; (q)[a] = (q)[b]; (q)[b] = (t); } while (0)
#define SWAP4T(q, o, t) do { SWAP2T(q, (o), (o) + 3, t); SWAP2T(q, (o) + 1, (o) + 2, t); } while (0)

#pragma opt_propagation off
#pragma scheduling invalid_target
void *fn_801D9CC4(void *arg0)
{
  int type = 0;
  u8 flag = 0;
  volatile u8 *base;
  int i;
  int j;
  u32 off;
  volatile u8 *e;
  volatile u8 *r;
  u32 t;
  base = (volatile u8 *) getResourceData(arg0, 0x50507468, &type, 0, 0, &flag);
  if (base == 0)
  {
    Abend_Panic(lbl_80339200, arg0);
    return 0;
  }
  if (type != 0)
  {
    Abend_Panic(lbl_80339218, arg0, type, 0);
    return 0;
  }
  if (flag != 0)
  {
    SWAP4T(base, 0, t);
    e = base + 4;
    for (i = 0; i < *((s32 *) base); i++, e += 0x18)
    {
      SWAP4T(e, 0x10, t);
      SWAP4T(e, 0x14, t);
      *((u32 *) (e + 0x14)) = (*((u32 *) (e + 0x14))) + ((u32) base);
      for (j = 0, off = 0; j < (*((s32 *) (e + 0x10))); j++, off += 0x20)
      {
        r = ((volatile u8 *) (*((u32 *) (e + 0x14)))) + off;
        SWAP4T(r, 0, t);
        SWAP4T(r, 4, t);
        SWAP4T(r, 8, t);
        SWAP4T(r, 0xC, t);
        SWAP4T(r, 0x10, t);
        SWAP4T(r, 0x14, t);
        SWAP4T(r, 0x18, t);
        SWAP4T(r, 0x1C, t);
      }
    }
  }
  return (void *) base;
}
#pragma opt_propagation reset
/* Forward to fn_8012C4D8. */
void fn_801D9F24(void) {
    fn_8012C4D8();
}

void fn_801D9F28(void *player) {
    /* Initialize a path-follower object: clear its three header words and set its current time (+0xC) to the default 0.0. */
    volatile int *header = (volatile int *)player;
    float initialTime = lbl_80562B38;
    header[0] = 0;
    header[1] = 0;
    header[2] = 0;
    *(volatile float *)((char *)player + 0xC) = initialTime;
}

extern int fn_80128668(void);
extern float lbl_80562B38;
extern int strcmp(const char *, const char *);
int fn_801D9F44(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

#pragma scheduling invalid_target
void fn_801D9F84(void *catalog, int *table) {
    /* Initialize a parsed-table catalog object: +0 raw table, +4 pointer to its first 0x18-byte entry (when count > 0), +8 zero, +0xC default float. */
    float defaultValue = lbl_80562B38;
    int tableIsNull = (table == 0);
    *(int **)catalog = table;
    *(int *)((char *)catalog + 8) = 0;
    *(float *)((char *)catalog + 0xC) = defaultValue;
    if (!tableIsNull && *table > 0)
        *(int *)((char *)catalog + 4) = (int)(table + 1);
    else
        *(int *)((char *)catalog + 4) = 0;
}
#pragma scheduling on
#pragma use_lmw_stmw off
/* Return 1 if any 0x18-byte entry (name at +4) in the table pointed to by *arg0 matches arg1. */
int fn_801D9FC4(char **arg0, const char *arg1) {
    register int offset;
    register int count;
    register char *base;
    register int index;

    base = *arg0;
    count = *(int *)base;
    index = 0;
    offset = 0;
    while (index < count) {
        if (strcmp(base + offset + 4, arg1) == 0)
            return 1;
        offset += 0x18;
        index++;
    }
    return 0;
}
#pragma use_lmw_stmw reset

/* Return a pointer to the name field (offset 4) of the 0x18-byte table entry at index, or NULL if index is out of range. */
void *fn_801DA03C(int **catalog, int index) {
    int *table = *catalog;
    if (index < *table) {
        return (char *)table + index * 0x18 + 4;
    }
    return 0;
}

#pragma use_lmw_stmw off
int fn_801DA064(void *lookup, const char *name, int unused) {
    /* Find a named entry (0x18-byte stride) in a table at lookup[0] and store its address in lookup[1]. */
    register int offset;
    register int count;
    register char *entries;
    register int index;
    char *table;

    table = *(char **)lookup;
    count = *(int *)table;
    entries = table + 4;
    index = 0;
    offset = 0;
    while (index < count) {
        if (strcmp(entries + offset, name) == 0) {
            *(char **)((char *)lookup + 4) = entries + index * 0x18;
            return 1;
        }
        offset += 0x18;
        index++;
    }
    return 0;
}

#pragma push
#pragma scheduling invalid_target
void fn_801DA0EC(void *arg0, float farg0) {
    struct S { int pad0; void *obj; int idx; float cur; };
    volatile struct S *vs = (volatile struct S *)arg0;
    float zero;
    float old;
    float *values;
    void *o;
    int idx;
    if (vs->obj == 0) {
        return;
    }
    zero = lbl_80562B38;
    old = vs->cur;
    vs->cur = old + farg0;
    if (farg0 >= zero) goto forward;
    goto backward;
forward:
    goto fwd_body;
fwd_inc:
    ++vs->idx;
fwd_body:
    o = (void *)vs->obj;
    idx = vs->idx;
    if (idx + 1 >= *(int *)((char *)o + 0x10)) {
        return;
    }
    values = *(float **)((char *)o + 0x14);
    if (*(float *)((char *)arg0 + 0xC) > values[idx * 8 + 8]) goto fwd_inc;
    goto done;
done:
    return;
    goto backward;
backward:
    do {
        --vs->idx;
        idx = vs->idx;
        if (idx <= 0) {
            return;
        }
        o = (void *)vs->obj;
        values = *(float **)((char *)o + 0x14);
    } while (values[idx * 8] > *(float *)((char *)arg0 + 0xC));
}
#pragma scheduling on
#pragma pop

void fn_801DA198(void *pathCursor, float value) {
    /* Seek a path-follower cursor to `value`: store it as the current value (+0xC), reset the
       segment index (+8) to 0, then advance that index while the next keyframe's time (the
       second float, +8, of each 0x20-byte keyframe in the curve's array at curve+0x14) is
       at or below the value. */
    float *keyframes;
    int segment;
    *(float *)((char *)pathCursor + 0xC) = value;
    *(int *)((char *)pathCursor + 8) = 0;
    if (*(void **)((char *)pathCursor + 4) == 0) return;
    while (*(int *)((char *)pathCursor + 8) + 1 < *(int *)((char *)*(void **)((char *)pathCursor + 4) + 0x10)) {
        segment = *(int *)((char *)pathCursor + 8);
        keyframes = *(float **)((char *)*(void **)((char *)pathCursor + 4) + 0x14);
        if (keyframes[segment * 8 + 8] > *(float *)((char *)pathCursor + 0xC)) return;
        *(int *)((char *)pathCursor + 8) = *(int *)((char *)pathCursor + 8) + 1;
    }
}

int fn_801DA1F8(void *pathCursor, void **outCurrent, void **outNext, float *outT) {
    /* Find the two 0x20-byte path keyframes surrounding the cursor's time and
     * return them with the interpolation factor, clamped to the last segment. */
    register int segment;
    register void *curve;
    register int maxSegment;
    register float *keyframes;
    register float *nextKeyframe;
    register float *currentKeyframe;
    register float time;
    register float timeSpan;
    register float elapsed;

    curve = *(void **)((char *)pathCursor + 4);
    if (curve != 0) {
        maxSegment = *(int *)((char *)curve + 0x10) - 2;
        segment = *(int *)((char *)pathCursor + 8);
        if (maxSegment >= segment) {
        } else {
            segment = maxSegment;
        }

        keyframes = *(float **)((char *)curve + 0x14);
        nextKeyframe = keyframes + (segment + 1) * 8;
        currentKeyframe = keyframes + segment * 8;
        time = *(float *)((char *)pathCursor + 0xC);
        time = (time < *nextKeyframe) ? time : *nextKeyframe;
        timeSpan = *nextKeyframe - *currentKeyframe;
        timeSpan = (timeSpan > lbl_80562B3C) ? timeSpan : lbl_80562B3C;
        elapsed = time - *currentKeyframe;

        *(float **)outCurrent = currentKeyframe;
        *(float **)outNext = nextKeyframe;
        *outT = elapsed / timeSpan;
        return 1;
    }
    return 0;
}

extern float lbl_80562B40, lbl_80562B44, lbl_80562B48, lbl_80562B4C, lbl_80558DC4;
extern double fn_8002F234(float);
extern double fn_8002EFA8(double);
extern double sin(double);
extern double __fabs(double);
extern int fn_801DA1F8(void *, void **, void **, float *);
extern float __fabsf(float);
#pragma processor 750
#pragma scheduling invalid_target
int fn_801DA294(void *arg0, void *arg1, void *arg2, void *arg3) {
    float *a = 0, *b = 0;
    float t = 0.0f;
    float tr[3], ax[3], qb[4], qa[4], dl[3], q[4];
    float inv, sc, len, w, omt;
    float *m = (float *)arg1, *d = (float *)arg2, *r = (float *)arg3;
    if (fn_801DA1F8(arg0, (void **)&a, (void **)&b, &t) != 0) {
        tr[2] = t * (b[3] - a[3]) + a[3];
        tr[1] = t * (b[2] - a[2]) + a[2];
        tr[0] = t * (b[1] - a[1]) + a[1];
        m[0xB] = tr[2];
        m[0xA] = tr[1];
        m[9] = tr[0];
        omt = 1.0f - t;
        q[3] = b[7] * t + a[7] * omt;
        q[2] = b[6] * t + a[6] * omt;
        q[0] = b[4] * t + a[4] * omt;
        q[1] = b[5] * t + a[5] * omt;
        inv = 1.0f / (float)fn_8002F234(q[0]*q[0] + (q[1]*q[1] + (q[3]*q[3] + q[2]*q[2])));
        q[1] *= inv; q[2] *= inv; q[0] *= inv; q[3] *= inv;
        m[0] = 1.0f - (q[1]*(q[1]+q[1]) + q[2]*(q[2]+q[2]));
        m[4] = 1.0f - (q[0]*(q[0]+q[0]) + q[2]*(q[2]+q[2]));
        m[8] = 1.0f - (q[0]*(q[0]+q[0]) + q[1]*(q[1]+q[1]));
        m[6] = q[0]*(q[2]+q[2]) + q[3]*(q[1]+q[1]);
        m[3] = q[0]*(q[1]+q[1]) - q[3]*(q[2]+q[2]);
        m[1] = q[0]*(q[1]+q[1]) + q[3]*(q[2]+q[2]);
        m[7] = q[1]*(q[2]+q[2]) - q[3]*(q[0]+q[0]);
        m[2] = q[0]*(q[2]+q[2]) - q[3]*(q[1]+q[1]);
        m[5] = q[1]*(q[2]+q[2]) + q[3]*(q[0]+q[0]);
        len = b[0] - a[0];
        w = 1e-5f;
        sc = 1.0f / (len > w ? len : w);
        dl[0] = b[1] - a[1];
        dl[1] = b[2] - a[2];
        dl[2] = b[3] - a[3];
        d[0] = dl[0] * sc;
        d[1] = dl[1] * sc;
        d[2] = dl[2] * sc;
        qa[0] = a[4] * -1.0f;
        qa[1] = a[5] * -1.0f;
        qa[2] = a[6] * -1.0f;
        qa[3] = a[7] * -1.0f;
        qb[0] = b[4] + qa[0];
        qb[1] = b[5] + qa[1];
        qb[2] = b[6] + qa[2];
        qb[3] = b[7] + qa[3];
        len = fn_8002EFA8(qb[3]);
        w = sin(len);
        if ((float)__fabs(w) > 1.1920929e-7f) {
            inv = 2.0f * len / w;
            ax[0] = qb[0] * inv;
            ax[1] = qb[1] * inv;
            ax[2] = qb[2] * inv;
        } else {
            ax[0] = 0.0f;
            ax[1] = 0.0f;
            ax[2] = 0.0f;
        }
        r[0] = ax[0] * sc;
        r[1] = ax[1] * sc;
        r[2] = ax[2] * sc;
        return 1;
    }
    return 0;
}
int fn_801DA648(void *player) {
    void *path;
    int keyCount;
    float *keys;
    /* Return nonzero when the player's current time has reached the final keyframe of its path. */
    path = *(void **)((char *)player + 4);
    if (path != 0) {
        keyCount = *(int *)((char *)path + 0x10);
        keys = *(float **)((char *)path + 0x14);
        return *(float *)((char *)player + 0xC) >= keys[(keyCount - 1) * 8];
    }
    return 0;
}

int fn_801DA688(void *player) {
    /* Return whether a path-bearing object's current time (+0xC) is at or before
     * zero, or false when it has no path (+4). */
    if (*(void **)((char *)player + 4) != 0)
        return *(float *)((char *)player + 0xC) <= lbl_80562B38;
    return 0;
}

extern float lbl_80562B3C;
float fn_801DA6B8(void *player) {
    /* Return the time held in the final keyframe (8 floats per keyframe) of the
     * player's path, or 0.0 when it has no path. */
    void *path = *(void **)((char *)player + 4);
    if (path != 0) {
        int keyCount = *(int *)((char *)path + 0x10);
        float *keys = *(float **)((char *)path + 0x14);
        return keys[(keyCount - 1) * 8];
    }
    return lbl_80562B38;
}

