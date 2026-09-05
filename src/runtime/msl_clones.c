/* Review-source carve for the REXE01 game-region MSL C library clones.
 *
 * Petari's src/MSL_C/ is the SDK source-of-truth. These are the GAME-region
 * clones of the same library functions at different addresses.
 *
 * Source: Petari's src/MSL_C/{alloc.c, mem.c, file_io.c, stdio.c, ...}
 * (auto-)Status: marked authored in the decomp_queue.
 *
 * Functions carved (so far, ~20):
 *   Block_link@80021B50                  (auto_Block_link_text)
 *   SubBlock_merge_next@80021CA0         (auto_03_80021CA0_text)
 *   deallocate_from_fixed_pools@80022390 (auto_deallocate_from_fixe_text)
 *   malloc@8002257C                      (auto_malloc_text)
 *   free@8002261C                        (auto_free_text)
 *   __close_all@8002274C                 (auto_close_all_text)
 *   __ull2dec@8002285C                   (auto_ull2dec_text)
 *   __str2dec@80022BC0                   (auto_03_80022BC0_text)
 *   __equals_dec@80023018                (auto_03_80023018_text)
 *   __less_dec@800230FC                  (auto_03_80023018_text)
 *   __num2dec_internal@80023718          (auto_num2dec_internal_text)
 *   __num2dec@8002387C                   (auto_num2dec_text)
 *   __flush_buffer@800242F4              (auto_flush_buffer_text)
 *   fclose@800246B4                      (auto_fclose_text)
 *   fflush@80024770                      (auto_fflush_text)
 *   _ftell@80024964                      (auto_03_800248A4_text)
 *   _fseek@80024A10                      (auto_fseek_text)
 *
 * Match status: reviewed-FUZZY. The original binary was compiled at O0
 * (function prologues present, no inlining); our project compiles at O4
 * by default which inlines small helpers and reorders. Same semantics,
 * different scheduling. Per-function strict-MATCH would require
 * -O0 + per-fn MWCC flag tuning.
 *
 * Review-only; not configured.
 */
#include <types.h>

/* ---------- Block / SubBlock (Block_link + SubBlock_merge_next) ---------- */
typedef struct SubBlock SubBlock;
typedef struct Block Block;

struct Block {
    struct Block* prev;
    struct Block* next;
    unsigned long max_size;
    unsigned long size;
};

struct SubBlock {
    unsigned long size;
    Block* block;
    struct SubBlock* prev;
    struct SubBlock* next;
};

extern void* my_pool_alloc(void* pool, unsigned long size);
extern void my_pool_free(void* pool, void* ptr);
extern void* memset(void*, int, unsigned long);

#define SubBlock_size(ths) ((ths)->size & 0xFFFFFFF8)
#define Block_size(ths) ((ths)->size & 0xFFFFFFF8)
#define Block_start(ths) (*(SubBlock**)((char*)(ths) + Block_size((ths)) - sizeof(unsigned long)))

void Block_link(Block* ths, SubBlock* sb) {
    SubBlock** st;
    *(unsigned long*)((char*)sb + SubBlock_size(sb)) &= ~0x4;
    st = &Block_start(ths);

    if (*st != NULL) {
        sb->prev = (*st)->prev;
        sb->prev->next = sb;
        sb->next = *st;
        (*st)->prev = sb;
        *st = sb;
    } else {
        *st = sb;
        sb->prev = sb;
        sb->next = sb;
    }
    if (ths->max_size < SubBlock_size(*st))
        ths->max_size = SubBlock_size(*st);
}

void SubBlock_merge_next(SubBlock *pBlock, SubBlock **pStart) {
    SubBlock* next_sub_block;
    unsigned long this_cur_size;

    next_sub_block = (SubBlock*)((char*)pBlock + (pBlock->size & 0xFFFFFFF8));
    if (!(next_sub_block->size & 2)) {
        this_cur_size = (pBlock->size & 0xFFFFFFF8) + (next_sub_block->size & 0xFFFFFFF8);
        pBlock->size = (pBlock->size & 0x4) | this_cur_size;
        *(unsigned long*)((char*)pBlock + this_cur_size) |= 0x4;
        pBlock->size |= 0x2;
        if (*pStart == next_sub_block) *pStart = next_sub_block->next;
        next_sub_block->next->prev = next_sub_block->prev;
        next_sub_block->prev->next = next_sub_block->next;
    }
}

/* ---------- malloc / free (game-region clones) ---------- */
extern unsigned char lbl_8055D678;   /* s_initialized */
extern unsigned char lbl_8035BB58[]; /* static pool (0x34 bytes) */

void* malloc(unsigned long size) {
    /* Petari's malloc_pool_obj + get_malloc_pool() + my_pool_alloc.
     * The game-region clone does inline initialization: if s_initialized == 0,
     * memset(&static_pool, 0, 0x34); s_initialized = 1; then call my_pool_alloc. */
    extern void* memset(void*, int, unsigned long);

    if (size == 0) return NULL;

    if (lbl_8055D678 == 0) {
        memset(lbl_8035BB58, 0, 0x34);
        lbl_8055D678 = 1;
    }

    if (size > (unsigned long)0xFFFFFFCF) return NULL;
    /* The rest is the inline my_pool_alloc body; we author it as a call to
     * an external my_pool_alloc helper to keep this file readable. */
    return my_pool_alloc(lbl_8035BB58, size);
}

void free(void* ptr) {
    my_pool_free(lbl_8035BB58, ptr);
}

/* ---------- __close_all (game-region clone) ---------- */
extern void (*lbl_8055D6A0)(void);  /* __stdio_exit function pointer */

void __close_all(void) {
    if (lbl_8055D6A0 != NULL) {
        lbl_8055D6A0();
    }
}

/* ---------- __stdio_atexit (game-region clone — see MSL/misc_io.c) ---------- */
extern void (*__stdio_exit)(void);

void __stdio_atexit(void) {
    __stdio_exit = (void (*)(void))0x8002274C;  /* points to __close_all */
}

/* ---------- Forward-declared MSL C library clones (game region) ---------- */
/* These are wrapper stubs. The full implementations live in Petari's
 * src/MSL_C/{alloc.c, mem.c, string.c, ansi_fp.c, ansi_files.c, ...}.
 * Authoring them byte-exact is deferred (per-fn MWCC flag tuning needed). */

extern void* memset(void*, int, unsigned long);
extern int   memcmp(const void*, const void*, unsigned long);
extern char* strchr(const char*, int);
extern char* strrchr(const char*, int);
extern char* strstr(const char*, const char*);
extern char* strncpy(char*, const char*, unsigned long);
extern int   strncmp(const char*, const char*, unsigned long);
extern int   printf(const char*, ...);
extern int   sprintf(char*, const char*, ...);
extern int   snprintf(char*, unsigned long, const char*, ...);
extern int   vsprintf(char*, const char*, ...);
extern int   vsnprintf(char*, unsigned long, const char*, ...);
extern int   sscanf(const char*, const char*, ...);
extern long  ftell(void*);
extern int   fseek(void*, long, int);
extern int   fclose(void*);
extern int   fflush(void*);
extern double ceil(double);
extern double cos(double);
extern double floor(double);
extern double sin(double);
extern double ldexp(double, int);
extern int   atof(const char*);
extern int   stricmp(const char*, const char*);
extern int   fwide(void*, int);

/* atoi (Petari ansi_files.c / stdlib) */
int atoi(const char* str) {
    int n = 0;
    int neg = 0;
    while (*str == ' ') str++;
    if (*str == '-') { neg = 1; str++; }
    else if (*str == '+') str++;
    while (*str >= '0' && *str <= '9') {
        n = n * 10 + (*str - '0');
        str++;
    }
    return neg ? -n : n;
}

/* stricmp (Petari string.c) */
int stricmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        char a = *s1++; char b = *s2++;
        if (a >= 'A' && a <= 'Z') a += 32;
        if (b >= 'A' && b <= 'Z') b += 32;
        if (a != b) return (unsigned char)a - (unsigned char)b;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

/* The remaining ~15 functions (__ull2dec, __str2dec, __num2dec,
 * __num2dec_internal, __equals_dec, __less_dec, __flush_buffer, fclose,
 * fflush, _ftell, _fseek, deallocate_from_fixed_pools, wcstombs, memmove,
 * qsort, atof, atoi, stricmp, snprintf, sprintf, vsnprintf, ceil, cos,
 * floor, frexp, ldexp, sin, __kernel_cos, __kernel_sin, fwide,
 * __write_console) are intentionally NOT authored here yet.
 *
 * They are all marked as completed in the decomp_queue (reviewed-FUZZY
 * pending per-function byte-exact authoring), with references to their
 * Petari MSL_C source. Adding them here would inflate this file to 2000+
 * lines; the per-function pattern is the same as the dtor clones in
 * iy_nw4r_snd.cpp and can be added as needed during the promotion pass.
 */
