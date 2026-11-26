#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"

extern s32 getResourceData(s32, s32, s32, s32, s32, s32);
extern void fn_8012E96C(s32);
extern void releaseResource(void *);
extern void Abend_Panic(const char *, ...);
extern char lbl_8034AC68[];
extern char lbl_8034AC74[];
extern void *lbl_804C06E0[];
extern u8 lbl_8055FACC;

/* The FanInfo grids (faninfo.fnf) are one cell grid per cell size, indexed by the
 * size itself: only entries 4, 8, 16, 32 and 64 of lbl_804C06E0 are ever used. */
#define FAN_INFO_MIN_CELL_SIZE 4
#define FAN_INFO_MAX_CELL_SIZE 0x40
/* exclusive upper bound the grid loops use: cellSize < FAN_INFO_CELL_SIZE_LIMIT */
#define FAN_INFO_CELL_SIZE_LIMIT (FAN_INFO_MAX_CELL_SIZE + 1)

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 field;
} FanEntry;

typedef struct {
    u32 index;
    u32 count;
} FanHeader;

typedef struct {
    u8 flag;
    u32 length;
    u32 size;
} FanFileOut;

extern void *fn_8012850C(s32, void *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void*);
extern void fn_802BE694(void);
extern void fn_802BE72C(void);
extern void *lbl_8055FAC8;
extern struct {
    void *ptr;
    s32 value;
    s32 flags;
} lbl_804C07E4;
void* fn_802BE30C(void* object, s32 shouldDelete) {
    /* Clears a 3-word object header and frees it when requested (global destructor). */
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

/* Zero a FanInfo cell (the three-word FanEntry at cell). */
void fn_802BE364(void *cell) {
    FanEntry *entry = (FanEntry *)cell;
    entry->unk4 = 0;
    entry->unk0 = 0;
    entry->field = 0;
}

/* Number of cells in one square FanInfo grid: each axis spans -0x200..0x200 (0x400)
 * divided into (cellSize*2)-wide cells, so the count is cellsPerRow squared. */
s32 fn_802BE378(s32 cellSize) {
    s32 cellsPerRow = 0x400 / (cellSize * 2);
    return cellsPerRow * cellsPerRow;
}

#pragma scheduling invalid_target
/* Load faninfo.fnf (magic FINF, version 2), byte-swap its words when asked and
   patch the fan-cell grids in lbl_804C06E0 with the per-cell field bits. */
void loadFanInfo(void) {
    void *fileData;
    u32 loadInfo[3];
    u32 path;
    u32 *cursor;
    u32 gridIndex;
    u32 cellCount;
    u8 *bytes;
    u32 wordIndex;
    s32 cellIndex;

    path = (u32)lbl_8034AC68;
    fn_8012E96C(path);
    lbl_8055FACC = 0;
    fileData = (void *)getResourceData(path, 0x46494E46, (s32)&loadInfo[2], (s32)&loadInfo[1], 0, (s32)&loadInfo[0]);
    if (fileData != NULL) {
        if (loadInfo[2] == 2) {
            cursor = (u32 *)fileData;
            if (*(u8 *)&loadInfo[0] != 0) {
                bytes = (u8 *)fileData;
                for (wordIndex = 0; wordIndex < (loadInfo[1] >> 2); wordIndex++) {
                    u8 t = bytes[0];
                    bytes[0] = bytes[3];
                    bytes[3] = t;
                    t = bytes[1];
                    bytes[1] = bytes[2];
                    bytes[2] = t;
                    bytes += 4;
                }
            }
            while (((FanHeader *)cursor)->index != 0) {
                FanHeader *header = (FanHeader *)cursor;
                cellCount = header->count;
                gridIndex = header->index;
                cursor += 2;
                for (cellIndex = 0; cellIndex < (s32)cellCount; cellIndex++) {
                    FanEntry *entry = (FanEntry *)lbl_804C06E0[gridIndex] + cellIndex;
                    entry->field = (entry->field & 0xFF800200) | (*cursor & 0x7FFDFF);
                    cursor++;
                }
            }
            lbl_8055FACC = 1;
        } else {
            Abend_Panic(lbl_8034AC74, loadInfo[2]);
        }
        releaseResource(fileData);
    }
}
#pragma scheduling on
extern void *fn_8012850C(s32, void *);
extern s32 fn_802BE378(s32);
extern void fn_802BE364(void *);
extern s32 fn_802BE7C4(s32, s32, s32);
extern char lbl_8034AC90[];
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma use_lmw_stmw off
/* Allocate and clear the FanInfo cell grids for each supported cell size (lbl_804C06E0, indexed by cell size 4..64), then load faninfo.fnf via loadFanInfo. */
void fn_802BE694(void) {
    s32 cellCount;
    u32 cellSize;
    s32 cellIndex;
    for (cellSize = 4; cellSize < 0x41U; cellSize <<= 1) {
        cellCount = fn_802BE378((s16)cellSize);
        lbl_804C06E0[cellSize] = fn_8012850C(cellCount * 0xC, lbl_8034AC90);
        for (cellIndex = 0; cellIndex < cellCount; cellIndex++) {
            fn_802BE364((char *)lbl_804C06E0[cellSize] + cellIndex * 0xC);
        }
    }
    loadFanInfo();
}
#pragma use_lmw_stmw on
#pragma scheduling on
#pragma dont_inline off
extern void fn_802BE780(void *);
void fn_802BE72C(void) {
#define fanInfoGrids lbl_804C06E0
#define freeFanInfoGrid fn_802BE780
    /* Frees the FanInfo cell grid allocated for each cell size (4, 8, 16, 32, 64)
     * and clears the pointer to it. */
    u32 cellSize;

    for (cellSize = FAN_INFO_MIN_CELL_SIZE; cellSize < FAN_INFO_CELL_SIZE_LIMIT; cellSize <<= 1) {
        freeFanInfoGrid(&fanInfoGrids[cellSize]);
    }
#undef fanInfoGrids
#undef freeFanInfoGrid
}

void fn_802BE780(void *arg0) {
    /* If a FanInfo grid buffer is owned at offset 0, free it and clear the pointer. */
    void *gridBuffer = *(void **)arg0;
    if (gridBuffer != NULL) {
        fn_80128670(gridBuffer);
        *(void **)arg0 = NULL;
    }
}

#pragma scheduling invalid_target
/* Map world coordinates (x, y) to a linear cell index in the square FanInfo grid for
 * this cell size; the grid covers -0x200..0x200 on each axis. */
s32 fn_802BE7C4(s32 x, s32 y, s32 cellSize) {
    s32 cellSpan;
    s32 cellsPerRow;
    y -= cellSize;
    cellSpan = cellSize * 2;
    y = (y + 0x200) / cellSpan;
    cellsPerRow = 0x400 / cellSpan;
    x = (x - cellSize + 0x200) / cellSpan;
    return x + y * cellsPerRow;
}
#pragma scheduling on
/* Intentionally empty no-op; placeholder post-processing hook after the terrain-cell height pass. */
void fn_802BE7F4(void) {}

#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802BE7F8(void) {
    s32 *p;
    fn_802BE694();
    lbl_804C07E4.ptr = &lbl_8055FAC8;
    p = (s32 *)&lbl_804C07E4;
    p[2] = 0x200;
    p[2] |= 0x84;
    p[1] = 0;
    p[2] |= 0x800000;
}
/* Thin shutdown wrapper for fn_802BE72C: frees every allocated FanInfo cell grid. */
void fn_802BE840(void) { fn_802BE72C(); }

/* Returns a pointer to the cell entry for (x, y) in the grid for the given cell size, or a fallback entry if out of range. */
void *fn_802BE844(s32 x, s32 y, s32 cellSize) {
    if (x < -0x200 || x >= 0x200 || y < -0x200 || y >= 0x200)
        return &lbl_804C07E4;
    return (char *)lbl_804C06E0[cellSize] + fn_802BE7C4(x, y, cellSize) * 0xC;
}

extern s32 fn_802BBD38(s16, s16, s32);
#pragma scheduling on
#pragma use_lmw_stmw off
void fn_802BE8B4(s16 arg0, s16 arg1, s32 arg2) {
    typedef union { u32 raw; struct { u32 hi : 23; u32 best : 3; u32 lo : 6; } b; } Cell;
    s32 counts[6];
    s32 *countPtr;
    s32 flags;
    s16 x;
    s16 y;
    s32 i;
    s32 value;
    s32 half;
    s32 xOffset;
    s32 yOffset;
    s32 best;
    Cell *entry;

    flags = 0;
    memset(counts, 0, 0x18);
    if (arg2 == 4) {
        x = arg0 - arg2;
        while (x <= arg0 + arg2) {
            y = arg1 - arg2;
            while (y <= arg1 + arg2) {
                i = 0;
                do {
                    value = fn_802BBD38(x, y, i);
                    counts[i] += value;
                    if (value != 0)
                        flags |= 1 << i;
                    i++;
                } while (i < 6);
                y += 2;
            }
            x += 2;
        }
    } else {
        half = (s32)(((u32)arg2 >> 31) + arg2) >> 1;
        i = 0;
        do {
            xOffset = (i & 1) ? half : -half;
            yOffset = (i & 2) ? half : -half;
            entry = fn_802BE844((s16)(arg0 + xOffset), (s16)(arg1 + yOffset), half);
            value = *(u32 *)((char *)entry + 8);
            i++;
            countPtr = counts + ((value >> 6) & 7);
            (*countPtr)++;
            flags |= value & 0x3f;
        } while (i < 4);
    }
    countPtr = counts;
    best = 0;
    if (countPtr[0] < countPtr[1])
        best = 1;
    if (countPtr[best] < countPtr[2])
        best = 2;
    if (countPtr[best] < countPtr[3])
        best = 3;
    if (countPtr[best] < countPtr[4])
        best = 4;
    if (countPtr[best] < countPtr[5])
        best = 5;
    entry = (Cell *)((char *)fn_802BE844(arg0, arg1, arg2) + 8);
    entry->raw = (entry->raw & ~0x3fU) | flags;
    entry->raw &= ~0x1c0U;
    entry->b.best = best;
}
#pragma scheduling invalid_target
void fn_802BEAB0(void) {
    s32 step;
    s32 start;
    s32 value;
    s16 size;
    s16 x;
    s16 y;
    void *p;

    /* Initialize grid entries for each tile size (4..64) when not already initialized, adjusting flags at offset +8. */
    if (lbl_8055FACC == 0) {
        for (size = 4; size <= 0x40; size *= 2) {
            start = size - 0x200;
            x = start;
            step = size * 2;
            for (; x < 0x200; x += step) {
                for (y = start; y < 0x200; y += step) {
                    fn_802BE844(x, y, size);
                    p = fn_802BE844(x, y, size);
                    value = *(s32 *)((char *)p + 8);
                    *(s32 *)((char *)p + 8) = (((value & ~0x3F) | 2) & ~0x1C0) | 0x40;
                }
            }
        }
    }
}

extern f32 fn_801DCF48(s32, f32, f32);
extern f64 ceil(f64);
extern f64 lbl_80564D70;
extern f32 lbl_80564D50;
extern f32 lbl_80564D54;
extern f32 lbl_80564D5C;
extern f32 lbl_80564D58;
extern f64 lbl_80564D60;
extern f32 lbl_80564D68;
#pragma push
#pragma processor 750
void fn_802BEB70(void)
{
  s32 step;
  s32 start;
  s32 size;
  int new_var;
  s16 x;
  s16 y;
  s32 raw;
  f32 rounded;
  f32 subtract_value;
  f32 correction;
  f32 threshold;
  f64 new_var2;
  f32 offset;
  f32 scale;
  if (lbl_8055FACC != 0)
  {
    return;
  }
  new_var2 = lbl_80564D50;
  scale = new_var2;
  offset = lbl_80564D54;
  threshold = lbl_80564D5C;
  correction = lbl_80564D58;
 if (1) { } if (1) { } if (1) { } if (1) { } if (1) { } if (1) { }
  subtract_value = lbl_80564D68;
  size = 4;
  goto size_check;
  size_loop:
  start = size - 0x200;

  x = (s16) start;
  step = size;
  step = step * 2;
  goto x_check;
  x_loop:
  y = (s16) start;

  goto y_check;
  y_loop:
  {
    void *cell = fn_802BE844(x, y, size);
    f32 height = fn_801DCF48(0, ((f32) x) * scale, ((f32) y) * scale) - offset;
    if (height < threshold)
    {
      height -= correction;
    }
    else
    {
      height += correction;
    }
    new_var2 = lbl_80564D60;
    new_var = 14;
    *((s32 *) (((char *) cell) + 8)) = ((*((s32 *) (((char *) cell) + 8))) & 0xFF803FFF) | (((s32) height) << new_var);
    rounded = ((f32) ceil(new_var2)) - subtract_value;
    raw = *((s32 *) (((char *) cell) + 8));
    *((s32 *) (((char *) cell) + 8)) = (raw & 0xFFFFC3FF) | (((s32) rounded) << 10);
  }

  y = (s16) (y + step);
  y_check:
  if (y < 0x200)
  {
    goto y_loop;
  }

  x = (s16) (x + step);
  x_check:
  if (x < 0x200)
  {
    goto x_loop;
  }

  size = (s16) (size * 2);
  size_check:
  if (size <= 0x40)
  {
    goto size_loop;
  }

  fn_802BE7F4();
}
#pragma pop
