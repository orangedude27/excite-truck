#include <types.h>
#include <string.h>

/* Debug event timeline drawn by this unit: 0x30C-byte entries appended by
 * fn_801C3C80 and kept sorted by fn_801C3B7C on the time at entry+0x0.
 * entry+0x4 is the rank among entries sharing a time, entry+0x8 the event type
 * (0..7, which selects the fields fn_801CA1C4 prints). */
#define sTimelineEntries   lbl_8055E7F8 /* entry table, 0xC300 bytes = 100 entries */
#define sTimelineCount     lbl_8055E7F0 /* entries in sTimelineEntries */
#define sTimelineSelection lbl_8055E828 /* entry the overlay shows details for */
#define sTimelineTypeNames lbl_80562950 /* '\\0'-separated name per event type */
#define STR_TIMELINE_TYPE  lbl_80337944 /* "type: %s" */
#define STR_TIMELINE_TIME  lbl_8055AB10 /* "t: %.2f" */
#define text_line_height   fn_80238A20  /* overlay line advance: (int)(0.4f * font height) */
#define debug_draw_text    fn_801C94B8  /* x, y, text, color (-1 = default) */
#define nth_string         fn_801C98F4  /* string blob, index -> index-th string */
#define draw_entry_details fn_801CA1C4  /* entry, x, y, line advance */

__declspec(section ".sdata") extern char lbl_8055AAF0[], lbl_8055AAF4[], lbl_8055AAF8[];
extern void fn_802E3AD0(s32, const char *, ...);
extern double fn_8002EFA8(double);
extern f32 lbl_805629BC;
extern f64 atof(const char *);
extern f32 lbl_8055E85C;
extern f32 lbl_8055E860;
extern f32 lbl_805629B4;
extern char lbl_8055AA4C[6];
extern char lbl_80336B00[];
extern f32 lbl_805629D4;
extern s32 lbl_80562954, lbl_80562958, lbl_8056295C, lbl_80562960;
__declspec(section ".sdata") extern char lbl_8055AB00[], lbl_8055AB08[];
extern void fn_801C8420(void);
extern void fn_801C6D94(void);
extern void fn_801C6E40(void);
extern void fn_801C80E8(void);
extern void fn_801C811C(void);
extern void fn_801C8150(void);
extern void fn_801C73DC(void);
extern void fn_801C7480(void);
extern void fn_801C756C(void);
extern void fn_801C7698(void);
extern void fn_801C84E0(void);
extern void fn_801C8500(void);
#include <internal/printf.h>
#include <revolution/MTX/vec.h>
extern Vec lbl_80438498;
static inline void fn_801C7C04_load2(f32 *out, Vec *v) {
    out[0] = v->x;
    out[1] = v->z;
}
extern char lbl_8055AA44[4];

extern char lbl_8055E839;
extern s32 lbl_8055E828;
extern s32 lbl_8055E81C;
extern s32 lbl_8055E820;
extern s32 lbl_8055E824;
extern char lbl_8055E838;
extern u8 lbl_8055E83F;
extern u8 lbl_8055E840;
extern u8 *lbl_8055E86C;
extern s32 lbl_8055E870;
extern char lbl_80337474[];
extern char lbl_80438464[];
extern char lbl_8043846C[];
extern char lbl_80438478[];
extern char lbl_80438484[];
extern char lbl_80438490[];
extern char lbl_80438564[];
extern char lbl_804383F8[];
extern char lbl_80438408[];
extern char lbl_8055AA54[5];
  
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E7E2;
extern s32 lbl_8055E804;
extern f32 lbl_805629CC;
extern u8* fn_8017960C(s32);
extern Vec lbl_80438268;
extern Vec lbl_8043848C;
extern char lbl_804380F0[256];
extern f32 lbl_8055E834;
extern f32 lbl_8055F47C;
extern s32 lbl_80499050[];
extern s32 lbl_80438220[];
extern s32 lbl_80437E24[];
extern void *fn_801C3C80(void);
extern void qsort(void *base, size_t count, size_t size, int (*compare)(const void *, const void *));
extern s32 fn_801C3B7C(const void *, const void *);
extern s32 fn_801C3524(char *);
extern char *strcpy(char *, const char *);
extern char lbl_80437FC0[304];
extern char lbl_80336EC8[];
extern char lbl_80336EE8[];
extern char lbl_80336F0C[];
extern s32 lbl_8055E7F0;
extern s32 lbl_8055E7F8;
extern s32 lbl_80499050[12];
extern s32 lbl_804381F0[12];
extern s32 lbl_80438220[12];
extern f32 lbl_8056296C;
extern f32 lbl_8055E3C8;
extern const f32 lbl_80562970;
extern f32 cos(f32);
extern f32 sin(f32);
extern void fn_801B7C8C(s32, s32, f32 *);
extern void *fn_80178C9C(void);
extern void fn_801B8054(s32, void *, f32, f32);
extern void fn_80015A20(void *, f32 *);
extern void fn_80015B20(s32, void *, s32);
extern f32 lbl_80562978;
extern f32 lbl_80562980;
extern f32 lbl_80562994;
extern f32 lbl_80562974;
extern f32 lbl_805629C8;
extern s32 lbl_80437E24[3];
extern f32 lbl_80558DC4[];
extern double fn_8002F234(float);
extern void fn_8012F57C(float *, float *, float *, float);
extern f32 lbl_8056296C, lbl_80562974;
#pragma scheduling invalid_target
f32 fn_801C2F58(s32 count, f32 factor) {
    // Return factor^count for non-negative count (accumulates from 1.0f).
    f32 result = lbl_8056296C;
    s32 i;

    for (i = 0; i < count; i++) {
        result *= factor;
    }
    return result;
}
#pragma scheduling on
void fn_801C2FF4(float *out, float *a, float *b, float weight) {
    float qa[4], qb[4], q[4], trace, root, half=lbl_80562974, w, x, y, z;
    int i,j,k;
    trace=a[0]+a[4]+a[8];
    if(trace>lbl_80562970){ root=fn_8002F234(lbl_8056296C+trace); qa[0]=half*root; root=half/root; qa[1]=root*(a[5]-a[7]); qa[2]=root*(a[6]-a[2]); qa[3]=root*(a[1]-a[3]); }
    else { i=0; if(a[4]>a[0])i=1; if(a[8]>a[i*3+i])i=2; j=(i+1)%3; k=(j+1)%3; root=fn_8002F234(lbl_8056296C+a[i*3+i]-(a[j*3+k]+a[k*3+j])); qa[i]=half*root; root=half/root; qa[3]=root*(a[j*3+k]-a[k*3+j]); qa[j]=root*(a[i*3+j]+a[j*3+i]); qa[k]=root*(a[i*3+k]+a[k*3+i]); }
    trace=b[0]+b[4]+b[8];
    if(trace>lbl_80562970){ root=fn_8002F234(lbl_8056296C+trace); qb[0]=half*root; root=half/root; qb[1]=root*(b[5]-b[7]); qb[2]=root*(b[6]-b[2]); qb[3]=root*(b[1]-b[3]); }
    else { i=0; if(b[4]>b[0])i=1; if(b[8]>b[i*3+i])i=2; j=(i+1)%3; k=(j+1)%3; root=fn_8002F234(lbl_8056296C+b[i*3+i]-(b[j*3+k]+b[k*3+j])); qb[i]=half*root; root=half/root; qb[3]=root*(b[j*3+k]-b[k*3+j]); qb[j]=root*(b[i*3+j]+b[j*3+i]); qb[k]=root*(b[i*3+k]+b[k*3+i]); }
    fn_8012F57C(q,qa,qb,weight);
    w=q[0]; x=q[1]; y=q[2]; z=q[3];
    out[9]=a[9]+weight*(b[9]-a[9]); out[10]=a[10]+weight*(b[10]-a[10]); out[11]=a[11]+weight*(b[11]-a[11]);
    out[0]=1-2*(y*y+z*z); out[4]=1-2*(x*x+z*z); out[8]=1-2*(x*x+y*y);
    out[7]=2*(y*z-w*x); out[2]=2*(y*z+w*x); out[1]=2*(x*y-w*z); out[3]=2*(x*y+w*z);
    out[6]=2*(x*z-w*y); out[5]=2*(x*z+w*y);
}

#pragma dont_inline on
#pragma push
#pragma processor 750
f32 fn_801C3450(f32 arg0) {
    f32 denom = fn_801C2F58(2, lbl_80562978);
    f32 value = (f32)(s32)(arg0 * fn_801C2F58(2, lbl_80562978));
    return value / denom;
}
#pragma pop
#pragma dont_inline reset

#pragma dont_inline on
s32 fn_801C34CC(f32 arg0, f32 arg1) {
    f32 diff = arg0 - arg1;
    f64 abs = __fabs((f64)diff);
    return (f32)abs <= lbl_80558DC4[0];
}
#pragma dont_inline reset

f32 fn_801C34F4(f32 arg0) {
    extern f32 lbl_80562988;
    extern f32 lbl_8056298C;
    return (lbl_80562988 * arg0) / lbl_8056298C;
}

s32 fn_801C3508(s32 arg0, s32 arg1) {
    return (arg0 & (1 << arg1)) != 0;
}

#pragma dont_inline on
// Turns one "who" token of an interlude (cutscene script) command into a mask of
// player bits: the words below, or a player number ("3", "-2" counts back from
// the last player). fn_801C3954 ORs the tokens of a whole list together.
s32 fn_801C3524(char *who) {
    extern char lbl_8055A95C[7];  // "nobody"
    extern char lbl_8055A964[7];  // "all"
    extern char lbl_8055A968[5];  // "last"
    extern char lbl_8055A970[2];  // "0"
    extern char lbl_8055A974[6];  // "first"
    extern char lbl_8055A97C[7];  // "player"
    extern char lbl_80336BC0[11]; // "eve_leader"
    extern char lbl_8055A984[5];  // "even"
    extern char lbl_8055A98C[4];  // "odd"
    extern char lbl_80336BCC[];   // "interlude: bad who %s"
    extern void fn_802E30C8(const char *, ...);
    extern s32 fn_80179630(s32);
    extern s32 lbl_8055E804;      // number of players in the game
    extern s32 lbl_8055E808;      // player bit of the Eve leader

    if (strcmp(who, lbl_8055A95C) == 0) return 0;
    if (strcmp(who, lbl_8055A964) == 0) return -1;
    if (strcmp(who, lbl_8055A968) == 0) return 1 << (lbl_8055E804 - 1);
    if (strcmp(who, lbl_8055A970) == 0 || strcmp(who, lbl_8055A974) == 0) return 1;
    if (strcmp(who, lbl_8055A97C) == 0) return 1 << fn_80179630(0);
    if (strcmp(who, lbl_80336BC0) == 0) return 1 << lbl_8055E808;
    if (strcmp(who, lbl_8055A984) == 0) {
        s32 mask = 0;
        s32 i;
        for (i = 0; i < lbl_8055E804; i += 2) mask |= 1 << i;
        return mask;
    }
    if (strcmp(who, lbl_8055A98C) == 0) {
        s32 mask = 0;
        s32 i;
        for (i = 1; i < lbl_8055E804; i += 2) mask |= 1 << i;
        return mask;
    }
    {
        s32 num = (s32) atoi(who);
        if (num > 0) return 1 << num;
        if (num < 0) return 1 << (lbl_8055E804 - num);
    }
    fn_802E30C8(lbl_80336BCC, who);
    return 0;
}
#pragma dont_inline reset

#pragma auto_inline off
s32 fn_801C3954(s32 arg0) {
    /* Parse a space-separated list of "who" tokens into a combined player mask. */
    char buf[0x100];
    char *token;
    char *p;
    s32 result;
    strcpy(buf, (char *)arg0);
    token = buf;
    p = token;
    result = 0;
    do {
        s32 isLastToken = 0;
        char c;
        while ((c = *p) != ' ' && c != 0) p++;
        if (c == 0) isLastToken = 1;
        *p = 0;
        result |= fn_801C3524(token);
        if (isLastToken) break;
        p++;
        token = p;
    } while (1);
    return result;
}
#pragma scheduling invalid_target
s32 fn_801C3A00(u32 arg0) {
    s32 i;
    for (i = 0; i < lbl_8055E804; i++) {
        if (arg0 == (1U << i))
            return i;
    }
    return -1;
}
#pragma scheduling on
extern f32 cos(f32);
extern f32 sin(f32);
extern void fn_801B7C8C(s32, s32, f32 *);
extern void *fn_80178C9C(void);
extern void fn_801B8054(s32, void *, f32, f32);
extern void fn_80015A20(void *, f32 *);
extern void fn_80015B20(s32, void *, s32);
#pragma push
#pragma processor 750
/* Applies a base Y offset (plus node offset) and a Z-axis rotation to the given transform object. */
void fn_801C3A3C(s32 target, f32 yOffset, f32 zRotation) {
    char out[0x24];
    f32 values[3];
    void *p = fn_80178C9C();
    void *r = *(void **)(*(char **)((char *)p + 0x2C) + 0x20);
    while (r != 0 && *(u8 *)((char *)r + 0x34) != 0)
        r = *(void **)((char *)r + 0x14);
    {
        f32 offset = (r != 0) ? *(f32 *)((char *)r + 0x1C) : lbl_80562970;
        fn_801B8054(target, p, lbl_80562970, offset + yOffset);
    }
    values[0] = lbl_80562970;
    values[1] = zRotation;
    values[2] = lbl_80562970;
    fn_80015A20(out, values);
    fn_80015B20(target, out, target);
}
#pragma push
#pragma processor 750
void fn_801C3AF8(s32 arg0, s32 arg1, f32 arg2) {
    f32 values[2];
    f32 cosine;
    f32 sine;
    cosine = (f32)((f64 (*)(f32))cos)(arg2);
    sine = (f32)((f64 (*)(f32))sin)(arg2);
    values[0] = sine;
    values[1] = cosine;
    fn_801B7C8C(arg0, arg1, &values[0]);
}
#pragma pop
s32 *__AXFXGetLfoSinTable_801769CC(void);
void *fn_8001285C(s32);
extern f32 lbl_80562990;
extern f32 lbl_8055E7E4;
f32 fn_801C3B6C(void) {
    register f32 r_a = lbl_8055E3C8;
    return lbl_8055E7E4 + r_a;
}

#pragma dont_inline fn_801C34CC
/* qsort comparator for 0x30C-byte timeline entries: orders by time at +0
 * (sentinel -1.0f sorts after valid times); ties (fn_801C34CC) by rank at +4. */
s32 fn_801C3B7C(const void *leftEntry, const void *rightEntry) {
    if (*(f32 *)rightEntry < -1.0f) {
        return -1;
    }
    if (*(f32 *)leftEntry < -1.0f) {
        return 1;
    }
    if (fn_801C34CC(*(f32 *)leftEntry, *(f32 *)rightEntry)) {
        return *(s32 *)((char *)leftEntry + 4) - *(s32 *)((char *)rightEntry + 4);
    }
    if (*(f32 *)leftEntry < *(f32 *)rightEntry) {
        return -1;
    }
    return 1;
}

#pragma push
#pragma scheduling on
void fn_801C3C14(s32 arg0) {
    s32 offset = arg0 * 0x30C;
    memset((void *)(lbl_8055E7F8 + offset), 0, 0x30C);
    *(f32 *)(lbl_8055E7F8 + offset) = lbl_80562994;
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
    lbl_8055E7F0--;
}
#pragma pop
extern char lbl_8055E80D;
extern f32 lbl_8055E810;
#pragma scheduling invalid_target
void *fn_801C3C80(void) {
    /* Allocate the next 0x30C-byte entry in lbl_8055E7F8, initialize its key at +0,
       then assign a rank at +4 one higher than any existing entry with the same key. */
    register s32 byteOffset;
    register char *newEntry;
    register s32 maxRank;
    register s32 index;
    newEntry = (char *)lbl_8055E7F8 + lbl_8055E7F0++ * 0x30C;
    if ((u8)lbl_8055E80D != 0) {
        *(f32 *)newEntry = lbl_8055E810;
    } else {
        fn_801C3B6C();
        *(f32 *)newEntry = ((f32 (*)(void))fn_801C3450)();
    }
    maxRank = 0;
    index = 0;
    byteOffset = 0;
    goto test;
loop:
    if (fn_801C34CC(*(f32 *)newEntry, *(f32 *)((char *)lbl_8055E7F8 + byteOffset))) {
        if (*(s32 *)((char *)lbl_8055E7F8 + byteOffset + 4) > maxRank)
            maxRank = *(s32 *)((char *)lbl_8055E7F8 + byteOffset + 4);
    }
    byteOffset += 0x30C;
    index += 1;
test:
    if (index < lbl_8055E7F0 - 1)
        goto loop;
    *(s32 *)(newEntry + 4) = maxRank + 1;
    return newEntry;
}
#pragma scheduling on
extern void fn_80128670(s32);
extern s32 fn_8012850C(s32, void *);
extern void fn_801C3D88(void *);
extern char lbl_80336D84[];
extern char lbl_80336D90[];
extern char lbl_8055E7E8;
extern char lbl_8055E7E9;
extern char lbl_8055E7E3;
extern s32 lbl_8055E808;

s32 fn_801C3D5C(void) {
    return *(s32 *)((char *)fn_8001285C(*__AXFXGetLfoSinTable_801769CC()) + 0x20);
}

void fn_801C9834(void);
void fn_801C4AD0(void) {
    lbl_8055E7E9 = 0;
    lbl_8055E7E8 = 0;
    lbl_8055E7E2 = 0;
    lbl_8055E7E3 = 0;
    lbl_8055E7F0 = 0;
    lbl_8055E804 = 0;
    lbl_8055E808 = 0;
    lbl_8055E7E4 = lbl_80562970;
    *(f32 *)&lbl_80437E24[2] = lbl_80562994;
    *(s32 *)&lbl_80437E24[0] = 0;
    fn_801C9834();
}

extern void fn_801C98F0(void);

#pragma scheduling on
#define UNK_80437D88_DEFINED
extern struct Unk_80437D88 {
    char x00[0x9C];
    s32 x9C;
    s32 xA0;
    f32 xA4;
    char pad_0[0x4D4 - 0xA8];
    Vec f_4D4;
    Vec f_4E0;
    char pad_1[0x6F8 - 0x4EC];
    Vec f_6F8;
} lbl_80437D88;
typedef struct Unk_80437D88 Unk_80437D88;
extern s32 lbl_8055E800, lbl_8055E7F4, lbl_8055E7F0;
extern char lbl_8055E7FC, lbl_8055E7E8, lbl_8055E7E9, lbl_8055E7E3;
extern f32 lbl_805629A8;
extern u32 fn_801769A8(void);
extern s32 fn_80179630(s32);
extern void fn_8020C8FC(void);
extern void fn_8020C8F8(void);
void fn_801C4B10(void) {
    for (lbl_8055E804 = 0; fn_8017960C(lbl_8055E804); lbl_8055E804++) {
    }
    lbl_8055E7F8 = fn_8012850C(0xC300, lbl_80336D84);
    fn_801C3D88(lbl_80336D90);
}


void fn_801C4B74(void) {
    fn_801C98F0();
    if (lbl_8055E7F8 != 0) {
        fn_80128670(lbl_8055E7F8);
        lbl_8055E7F8 = 0;
    }
}

void fn_801C4BAC(void) {
    register Unk_80437D88 *state;
    register s32 zero;
    u8 *lo;
    u8 *hi;
    s32 flag;
    state = &lbl_80437D88;
    zero = 0;
    lbl_8055E800 = zero;
    lbl_8055E7FC = 1;
    lbl_8055E7E8 = zero;
    lbl_8055E7F4 = zero;
    lbl_8055E7E3 = zero;
    lbl_8055E7E4 = lbl_80562970;
    memset(state->x00, zero, 0x9C);
    lo = (u8 *)state->x00;
    hi = (u8 *)&state->x9C;
    *(f32 *)(lo + 0x14) = lbl_8056296C;
    *(f32 *)(lo + 0x18) = lbl_80562970;
    *(f32 *)(lo + 0x1C) = lbl_80562970;
    *(f32 *)(lo + 0x20) = lbl_80562970;
    *(f32 *)(lo + 0x24) = lbl_8056296C;
    *(f32 *)(lo + 0x28) = lbl_80562970;
    *(f32 *)(lo + 0x2C) = lbl_80562970;
    *(f32 *)(lo + 0x30) = lbl_80562970;
    *(f32 *)(lo + 0x34) = lbl_8056296C;
    *(f32 *)(lo + 0x50) = lbl_805629A8;
    *(f32 *)(lo + 0x68) = lbl_8056296C;
    *(f32 *)(lo + 0x6C) = lbl_80562970;
    *(f32 *)(lo + 0x70) = lbl_80562970;
    *(f32 *)(lo + 0x74) = lbl_80562970;
    *(f32 *)(lo + 0x78) = lbl_8056296C;
    *(f32 *)(lo + 0x7C) = lbl_80562970;
    *(f32 *)(lo + 0x80) = lbl_80562970;
    *(f32 *)(lo + 0x84) = lbl_80562970;
    *(f32 *)(lo + 0x88) = lbl_8056296C;
    *(f32 *)(lo + 0x8C) = lbl_80562970;
    *(f32 *)(lo + 0x90) = lbl_80562970;
    *(f32 *)(lo + 0x94) = lbl_80562970;
    *(f32 *)(lo + 0x98) = lbl_805629A8;
    *(f32 *)(hi + 0x8) = lbl_80562994;
    state->x9C = zero;
    if (lbl_8055E7F0 == 0) {
        lbl_8055E7E2 = zero;
        return;
    }
    if ((u8)lbl_8055E7E9 != 0) {
        fn_8020C8FC();
        fn_8020C8F8();
        lbl_8055E7E9 = 0;
    }
    flag = (fn_801769A8() >> 14) & 1;
    lbl_8055E7E2 = flag;
    if (flag != 0) {
        memset((u8 *)state + 0xA8, zero, 0xA0);
        fn_8017960C(fn_80179630(0));
    }
}

void fn_8018ADCC(void *, float);
void fn_8018ADC4(void *, float);
void fn_8018ADEC(void *);
void fn_8018ADAC(void *, float);
void fn_8018ADB4(void *, float);
void fn_8018ADBC(void *, float);
void *fn_801B2ED0(s32);
void fn_801353C4(void *, float *);
void fn_80135B9C(void *, float *, float *, void *, void *, float);
float fn_80139030(float *, float, float);
extern float lbl_805629AC;
extern float lbl_805629B8;
extern float lbl_805629BC;
extern char lbl_80437E30[];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801C56AC(void) {
    char *cfg;
    s32 i;
    void *obj;
    void *vobj;
    void *obj2;
    float buf[20];
    float c6C;
    float c70;
    float c90;
    float cB4;
    float cAC;
    float cB8;
    float c74;
    float c78;
    float cBC;
    float var_f23;
    if ((u8)lbl_8055E7E2 == 0) return;
    cfg = lbl_80437E30;
    c6C = lbl_8056296C;
    c70 = lbl_80562970;
    c90 = lbl_80562990;
    i = 0;
    cB4 = lbl_805629B4;
    cAC = lbl_805629AC;
    cB8 = lbl_805629B8;
    c74 = lbl_80562974;
    c78 = lbl_80562978;
    cBC = lbl_805629BC;
    for (;;) {
        void **vtab;
        obj = fn_8017960C(i);
        if (obj == 0) return;
        var_f23 = *(float *)(cfg + 8);
        fn_8018ADCC(obj, lbl_80562970);
        fn_8018ADC4(obj, lbl_8056296C);
        fn_8018ADEC(obj);
        fn_8018ADAC(obj, lbl_80562970);
        vtab = *(void ***)fn_801B2ED0(i);
        vobj = ((void *(*)())vtab[6])();
        buf[6] = *(float *)((u8 *)obj + 0x60);
        buf[7] = *(float *)((u8 *)obj + 0x68);
        fn_801353C4(vobj, &buf[6]);
        if (*(s32 *)(cfg + 0) == 5) goto L2ac8;
        if (*(s32 *)(cfg + 0) == 0) goto L2ac8;
        {
            s32 idx;
            idx = 1;
            buf[4] = c70;
            buf[5] = c70;
            if (*(s32 *)(cfg + 4) > 1) {
                idx = ((i + lbl_8055E804) - *(s32 *)(cfg + 4)) % lbl_8055E804;
            }
            obj2 = fn_8017960C(idx);
            if (*(s32 *)(cfg + 0) == 2) {
                buf[4] = *(float *)(cfg + 0xC);
                buf[5] = *(float *)(cfg + 0x10);
            } else if ((*(s32 *)(cfg + 0) == 1) || (*(s32 *)(cfg + 0) == 4)) {
                float amount;
                amount = *(float *)(cfg + 0x10);
                if (cB4 > amount) amount = cB4;
                fn_80135B9C(vobj, &buf[4], &buf[2], 0, 0, amount);
                buf[4] = buf[4] + buf[2] * *(float *)(cfg + 0xC);
                buf[5] = buf[5] + buf[3] * *(float *)(cfg + 0xC);
            } else {
                float o60;
                float o68;
                float o44;
                float o3c;
                o60 = *(float *)((u8 *)obj2 + 0x60);
                o68 = *(float *)((u8 *)obj2 + 0x68);
                o44 = *(float *)((u8 *)obj + 0x44);
                o3c = *(float *)((u8 *)obj + 0x3C);
                buf[1] = o44;
                buf[0] = o3c;
                buf[4] = o60 + o3c * *(float *)(cfg + 0xC);
                buf[5] = o68 + o44 * *(float *)(cfg + 0xC);
            }
            {
                float vx;
                float vy;
                vx = buf[4] - buf[6];
                vy = buf[5] - buf[7];
                buf[4] = vx;
                buf[5] = vy;
                buf[11] = vx;
                buf[12] = c70;
                buf[13] = vy;
                {
                    float dot;
                    float v;
                    dot = PSVECDotProduct((Vec *)&buf[11], (Vec *)((u8 *)obj + 0x3C));
                    v = cAC * dot + cB8 * (-*(float *)((u8 *)obj + 0x128));
                    if (v > c6C) v = c6C;
                    if (v < c90) v = c90;
                    fn_8018ADAC(obj, v);
                }
            }
            if ((u32)(*(s32 *)(cfg + 0) - 3) <= 1U) {
                buf[8] = *(float *)((u8 *)obj2 + 0x60) - *(float *)((u8 *)obj + 0x60);
                buf[9] = *(float *)((u8 *)obj2 + 0x64) - *(float *)((u8 *)obj + 0x64);
                buf[10] = *(float *)((u8 *)obj2 + 0x68) - *(float *)((u8 *)obj + 0x68);
                var_f23 = PSVECDotProduct((Vec *)&buf[8], (Vec *)((u8 *)obj + 0x54)) - *(float *)(cfg + 0x10);
                buf[17] = c70;
                buf[18] = *(float *)((u8 *)obj2 + 0x25D4);
                buf[19] = c70;
                buf[14] = -var_f23;
                buf[15] = *(float *)((u8 *)obj + 0x25D4);
                buf[16] = c74 + (*(float *)(cfg + 8) - *(float *)((u8 *)obj + 0x25D4));
                {
                    float t;
                    float f21;
                    float v0;
                    float v1;
                    float base;
                    t = fn_80139030(&buf[14], buf[16], *(float *)((u8 *)obj2 + 0x25D4));
                    f21 = t;
                    v0 = c78 * t;
                    if (v0 > c6C) v0 = c6C;
                    if (v0 < c70) v0 = c70;
                    fn_8018ADB4(obj, v0);
                    v1 = -f21;
                    if (v1 > c6C) v1 = c6C;
                    if (v1 < c70) v1 = c70;
                    fn_8018ADBC(obj, v1);
                    base = *(float *)((u8 *)obj2 + 0x25D4) + c74 * (*(float *)(cfg + 8) - *(float *)((u8 *)obj2 + 0x25D4));
                    if (var_f23 > c70) {
                        var_f23 = base + c74 * (var_f23 * *(float *)(cfg + 8));
                    } else {
                        var_f23 = base + cBC * (var_f23 * *(float *)(cfg + 8));
                    }
                }
            }
        }
    L2ac8:
        if (*(s32 *)(cfg + 0) == 5) {
            fn_8018ADB4(obj, c6C);
            fn_8018ADBC(obj, c70);
            {
                float x;
                x = *(float *)(cfg + 0xC);
                if (x > c6C) x = c6C;
                if (x < c90) x = c90;
                fn_8018ADAC(obj, x);
            }
            goto LloopEnd;
        }
        if ((u32)(*(s32 *)(cfg + 0) - 3) <= 1U) goto LloopEnd;
        if ((float)__fabs((f64)var_f23) > lbl_80558DC4[0]) {
            float o;
            float a;
            float b;
            o = *(float *)((u8 *)obj + 0x25D4);
            a = c74 * (var_f23 - o);
            if (a > c6C) a = c6C;
            if (a < c70) a = c70;
            fn_8018ADB4(obj, a);
            b = c74 * (o - var_f23);
            if (b > c6C) b = c6C;
            if (b < c70) b = c70;
            fn_8018ADBC(obj, b);
        } else {
            fn_8018ADB4(obj, c70);
            fn_8018ADBC(obj, c6C);
            fn_8018ADCC(obj, c70);
            fn_8018ADC4(obj, c6C);
            fn_8018ADEC(obj);
        }
    LloopEnd:
        i += 1;
        cfg += 0x14;
        if (i < 8) continue;
        return;
    }
}
#pragma pop
s32 fn_801C5B60(void) {
    return (u8)lbl_8055E7E2;
}

extern s32 lbl_8055E800;
extern u8 lbl_8055E818, lbl_8055E819;
extern f32 lbl_805629A0, lbl_805629AC, lbl_805629C0, lbl_805629C4;
extern char lbl_80336E88[];
extern s32 fn_80179630(s32);
extern f32 fn_80144514(f32, f32, f32, f32, f32, f32);
extern void fn_801BFD34(void *, void *, void *);
extern void fn_8020655C(void *, s32);
extern void fn_802E317C(void *, ...);
extern struct Unk_80437D88 lbl_80437D88;
#pragma push
#pragma scheduling invalid_target
s32 fn_801C5B68(char *arg0, s32 arg1) {
    extern char lbl_8055E80C;
    register struct Unk_80437D88 *state = &lbl_80437D88;
    void *sp28;
    void *sp24;
    s32 sp20;
    f32 saved[12];
    union { f32 rotation[9]; f32 basis[12]; } matrixTemp;
    union { f32 velocity[3]; f32 axis[3]; } vectorTemp;
    union { f32 translated[3]; f32 offset[3]; } resultTemp;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 temp_f23_3;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f24_3;
    f32 temp_f25;
    f32 temp_f25_2;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f27;
    f32 temp_f27_2;
    f32 temp_f28;
    f32 temp_f28_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f30_3;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f31_3;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f23;
    float var_f29;
    s32 temp_r10;
    s32 temp_r5;
    s32 var_r29;
    char *temp_r31;
    char *temp_r4;
    char *temp_r5_2;
    char *temp_r6;
    char *temp_r9;

    if (arg1 == 0) {
        lbl_8055E800 += 1;
    }
    if ((fn_801C5B60() != 0) && ((u8) lbl_8055E80C == 0)) {
        temp_f0 = (f32) (*(f32 *)((char *)(state) + 0x50));
        (*(f32 *)((char *)(&lbl_80499050) + 0x24)) = (f32) (*(f32 *)((char *)(state) + 8));
        (*(f32 *)((char *)(&lbl_80499050) + 0x28)) = (f32) (*(f32 *)((char *)(state) + 0xC));
        (*(f32 *)((char *)(&lbl_80499050) + 0x2C)) = (f32) (*(f32 *)((char *)(state) + 0x10));
        {
            u32 *src = (u32 *)((char *)state + 0x14);
            u32 *dst = (u32 *)lbl_80499050;
            u32 copy8 = src[8];
            u32 copy7 = src[7];
            u32 copy6 = src[6];
            u32 copy5 = src[5];
            u32 copy4 = src[4];
            u32 copy3 = src[3];
            u32 copy2 = src[2];
            u32 copy1 = src[1];
            u32 copy0 = src[0];
            dst[0] = copy0;
            dst[1] = copy1;
            dst[2] = copy2;
            dst[3] = copy3;
            dst[4] = copy4;
            dst[5] = copy5;
            dst[6] = copy6;
            dst[7] = copy7;
            dst[8] = copy8;
        }
        lbl_8055F47C = temp_f0;
    }
    if ((fn_801C5B60() == 0) || ((u8) lbl_8055E80C != 0)) {
        return 0;
    }
    if ((s8) lbl_8055E818 == 0) {
        lbl_8055E818 = 1;
    }
    if ((s8) lbl_8055E819 == 0) {
        lbl_8055E819 = 1;
    }
    memset(arg0, 0, 0xE0);
    var_r29 = fn_80179630(arg1);
    if ((s32) (*(s32 *)((char *)(state) + 0x58)) >= 0) {
        var_r29 = (*(s32 *)((char *)(state) + 0x58));
    }
    temp_r31 = (char *)fn_8017960C(var_r29);
    (*(s32 *)((char *)(arg0) + 0x68)) = (s32) ((*(s32 *)((char *)(arg0) + 0x68)) | 5);
    if (fn_801C3B6C() > (*(f32 *)((char *)(state) + 4))) {
        var_f29 = (*(f32 *)((char *)(state) + 4)) - (*(f32 *)((char *)(state) + 0));
    } else {
        var_f29 = fn_801C3B6C() - (*(f32 *)((char *)(state) + 0));
    }
    temp_f2 = (*(f32 *)((char *)(state) + 4)) - (*(f32 *)((char *)(state) + 0));
    if (temp_f2 > lbl_805629AC) {
        temp_f3 = var_f29 / temp_f2;
        var_f0 = lbl_80562990;
        if (temp_f3 < var_f0) {

        } else {
            var_f0 = lbl_8056296C;
            if (temp_f3 > var_f0) {

            } else if (temp_f3 > lbl_80562970) {
                var_f0 = (temp_f3 * (lbl_805629C0 * temp_f3 * temp_f3)) + (lbl_805629C4 * temp_f3 * temp_f3);
            } else {
                var_f0 = (temp_f3 * (lbl_805629C0 * temp_f3 * temp_f3)) - (lbl_805629C4 * temp_f3 * temp_f3);
            }
        }
        if ((s32) (*(u8 *)((char *)(state) + 0x54)) != 0) {
            var_f29 = var_f0 * temp_f2;
        }
    }
    (*(f32 *)((char *)(arg0) + 0x24)) = (f32) (*(f32 *)((char *)(state) + 8));
    (*(f32 *)((char *)(arg0) + 0x28)) = (f32) (*(f32 *)((char *)(state) + 0xC));
    (*(f32 *)((char *)(arg0) + 0x2C)) = (f32) (*(f32 *)((char *)(state) + 0x10));
    (*(f32 *)((char *)(arg0) + 0)) = (f32) (*(f32 *)((char *)(state) + 0x14));
    (*(f32 *)((char *)(arg0) + 4)) = (f32) (*(f32 *)((char *)(state) + 0x18));
    (*(f32 *)((char *)(arg0) + 8)) = (f32) (*(f32 *)((char *)(state) + 0x1C));
    (*(f32 *)((char *)(arg0) + 0xC)) = (f32) (*(f32 *)((char *)(state) + 0x20));
    (*(f32 *)((char *)(arg0) + 0x10)) = (f32) (*(f32 *)((char *)(state) + 0x24));
    (*(f32 *)((char *)(arg0) + 0x14)) = (f32) (*(f32 *)((char *)(state) + 0x28));
    (*(f32 *)((char *)(arg0) + 0x18)) = (f32) (*(f32 *)((char *)(state) + 0x2C));
    (*(f32 *)((char *)(arg0) + 0x1C)) = (f32) (*(f32 *)((char *)(state) + 0x30));
    (*(f32 *)((char *)(arg0) + 0x20)) = (f32) (*(f32 *)((char *)(state) + 0x34));
    temp_f8 = (*(f32 *)((char *)(state) + 0x38)) * var_f29;
    temp_f6 = (*(f32 *)((char *)(state) + 0x3C)) * var_f29;
    temp_f7 = (*(f32 *)((char *)(state) + 0x40)) * var_f29;
    vectorTemp.velocity[0] = temp_f8;
    vectorTemp.velocity[1] = temp_f6;
    vectorTemp.velocity[2] = temp_f7;
    if (&resultTemp.translated[0] == &vectorTemp.velocity[0]) {
        f32 translatedX = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x18))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 0))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0xC))));
        f32 translatedY = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x1C))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 4))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0x10))));
        f32 translatedZ = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x20))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 8))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0x14))));
        resultTemp.translated[0] = translatedX;
        resultTemp.translated[1] = translatedY;
        resultTemp.translated[2] = translatedZ;
    } else {
        resultTemp.translated[0] = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x18))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 0))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0xC))));
        resultTemp.translated[1] = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x1C))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 4))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0x10))));
        resultTemp.translated[2] = (temp_f7 * (*(f32 *)((char *)(arg0) + 0x20))) + ((temp_f8 * (*(f32 *)((char *)(arg0) + 8))) + (temp_f6 * (*(f32 *)((char *)(arg0) + 0x14))));
    }
    (*(f32 *)((char *)(arg0) + 0x24)) = (f32) ((*(f32 *)((char *)(arg0) + 0x24)) + resultTemp.translated[0]);
    (*(f32 *)((char *)(arg0) + 0x28)) = (f32) ((*(f32 *)((char *)(arg0) + 0x28)) + resultTemp.translated[1]);
    (*(f32 *)((char *)(arg0) + 0x2C)) = (f32) ((*(f32 *)((char *)(arg0) + 0x2C)) + resultTemp.translated[2]);
    temp_f2_2 = (*(f32 *)((char *)(state) + 0x44)) * var_f29;
    temp_f1 = (*(f32 *)((char *)(state) + 0x48)) * var_f29;
    vectorTemp.axis[0] = temp_f2_2;
    vectorTemp.axis[1] = temp_f1;
    vectorTemp.axis[2] = (*(f32 *)((char *)(state) + 0x4C)) * var_f29;
    temp_f1_2 = PSVECMag((Vec *)&vectorTemp.axis[0]);
    if (temp_f1_2 > lbl_805629A0) {
        temp_f4 = lbl_8056296C / temp_f1_2;
        temp_f31 = temp_f4 * vectorTemp.axis[0];
        temp_f24 = temp_f4 * vectorTemp.axis[1];
        temp_f23 = temp_f4 * vectorTemp.axis[2];
        temp_f30 = (f32) sin(temp_f1_2);
        temp_f9 = (f32) cos(temp_f1_2);
        temp_f0 = lbl_8056296C - temp_f9;
        temp_f3_2 = temp_f30 * temp_f23;
        temp_f6_2 = temp_f0 * temp_f31;
        temp_f4_2 = temp_f24 * temp_f6_2;
        matrixTemp.rotation[0] = temp_f9 + (temp_f0 * (temp_f31 * temp_f31));
        temp_f6_3 = temp_f23 * temp_f6_2;
        temp_f2_3 = temp_f30 * temp_f24;
        matrixTemp.rotation[1] = temp_f4_2 + temp_f3_2;
        temp_f3_3 = temp_f23 * (temp_f0 * temp_f24);
        temp_f0_2 = temp_f30 * temp_f31;
        matrixTemp.rotation[3] = temp_f4_2 - temp_f3_2;
        matrixTemp.rotation[2] = temp_f6_3 - temp_f2_3;
        matrixTemp.rotation[4] = temp_f9 + (temp_f0 * (temp_f24 * temp_f24));
        matrixTemp.rotation[5] = temp_f3_3 + temp_f0_2;
        matrixTemp.rotation[6] = temp_f6_3 + temp_f2_3;
        matrixTemp.rotation[7] = temp_f3_3 - temp_f0_2;
        matrixTemp.rotation[8] = temp_f9 + (temp_f0 * (temp_f23 * temp_f23));
    } else {
        matrixTemp.rotation[1] = lbl_80562970;
        matrixTemp.rotation[0] = lbl_8056296C;
        matrixTemp.rotation[2] = lbl_80562970;
        matrixTemp.rotation[3] = lbl_80562970;
        matrixTemp.rotation[4] = lbl_8056296C;
        matrixTemp.rotation[5] = lbl_80562970;
        matrixTemp.rotation[6] = lbl_80562970;
        matrixTemp.rotation[7] = lbl_80562970;
        matrixTemp.rotation[8] = lbl_8056296C;
    }
    if ((void *)arg0 != (void *)&matrixTemp.rotation[0]) {
        temp_f31_2 = fn_80144514((*(f32 *)((char *)(arg0) + 0)), matrixTemp.rotation[0], (*(f32 *)((char *)(arg0) + 0xC)), matrixTemp.rotation[1], (*(f32 *)((char *)(arg0) + 0x18)), matrixTemp.rotation[2]);
        temp_f30_2 = fn_80144514((*(f32 *)((char *)(arg0) + 0)), matrixTemp.rotation[3], (*(f32 *)((char *)(arg0) + 0xC)), matrixTemp.rotation[4], (*(f32 *)((char *)(arg0) + 0x18)), matrixTemp.rotation[5]);
        temp_f28 = fn_80144514((*(f32 *)((char *)(arg0) + 0)), matrixTemp.rotation[6], (*(f32 *)((char *)(arg0) + 0xC)), matrixTemp.rotation[7], (*(f32 *)((char *)(arg0) + 0x18)), matrixTemp.rotation[8]);
        temp_f27 = fn_80144514((*(f32 *)((char *)(arg0) + 4)), matrixTemp.rotation[0], (*(f32 *)((char *)(arg0) + 0x10)), matrixTemp.rotation[1], (*(f32 *)((char *)(arg0) + 0x1C)), matrixTemp.rotation[2]);
        temp_f26 = fn_80144514((*(f32 *)((char *)(arg0) + 4)), matrixTemp.rotation[3], (*(f32 *)((char *)(arg0) + 0x10)), matrixTemp.rotation[4], (*(f32 *)((char *)(arg0) + 0x1C)), matrixTemp.rotation[5]);
        temp_f25 = fn_80144514((*(f32 *)((char *)(arg0) + 4)), matrixTemp.rotation[6], (*(f32 *)((char *)(arg0) + 0x10)), matrixTemp.rotation[7], (*(f32 *)((char *)(arg0) + 0x1C)), matrixTemp.rotation[8]);
        temp_f24_2 = fn_80144514((*(f32 *)((char *)(arg0) + 8)), matrixTemp.rotation[0], (*(f32 *)((char *)(arg0) + 0x14)), matrixTemp.rotation[1], (*(f32 *)((char *)(arg0) + 0x20)), matrixTemp.rotation[2]);
        temp_f23_2 = fn_80144514((*(f32 *)((char *)(arg0) + 8)), matrixTemp.rotation[3], (*(f32 *)((char *)(arg0) + 0x14)), matrixTemp.rotation[4], (*(f32 *)((char *)(arg0) + 0x20)), matrixTemp.rotation[5]);
        temp_f1_3 = fn_80144514((*(f32 *)((char *)(arg0) + 8)), matrixTemp.rotation[6], (*(f32 *)((char *)(arg0) + 0x14)), matrixTemp.rotation[7], (*(f32 *)((char *)(arg0) + 0x20)), matrixTemp.rotation[8]);
        (*(f32 *)((char *)(arg0) + 0)) = temp_f31_2;
        (*(f32 *)((char *)(arg0) + 0xC)) = temp_f30_2;
        (*(f32 *)((char *)(arg0) + 0x18)) = temp_f28;
        (*(f32 *)((char *)(arg0) + 4)) = temp_f27;
        (*(f32 *)((char *)(arg0) + 0x10)) = temp_f26;
        (*(f32 *)((char *)(arg0) + 0x1C)) = temp_f25;
        (*(f32 *)((char *)(arg0) + 8)) = temp_f24_2;
        (*(f32 *)((char *)(arg0) + 0x14)) = temp_f23_2;
        (*(f32 *)((char *)(arg0) + 0x20)) = temp_f1_3;
    } else {
        temp_f1_4 = fn_80144514((*(f32 *)((char *)(arg0) + 0)), matrixTemp.rotation[0], (*(f32 *)((char *)(arg0) + 0xC)), matrixTemp.rotation[1], (*(f32 *)((char *)(arg0) + 0x18)), matrixTemp.rotation[2]);
        (*(f32 *)((char *)(arg0) + 0)) = temp_f1_4;
        temp_f1_5 = fn_80144514((f32) temp_f1_4, matrixTemp.rotation[3], (*(f32 *)((char *)(arg0) + 0xC)), matrixTemp.rotation[4], (*(f32 *)((char *)(arg0) + 0x18)), matrixTemp.rotation[5]);
        (*(f32 *)((char *)(arg0) + 0xC)) = temp_f1_5;
        (*(f32 *)((char *)(arg0) + 0x18)) = fn_80144514((*(f32 *)((char *)(arg0) + 0)), matrixTemp.rotation[6], (f32) temp_f1_5, matrixTemp.rotation[7], (*(f32 *)((char *)(arg0) + 0x18)), matrixTemp.rotation[8]);
        temp_f1_6 = fn_80144514((*(f32 *)((char *)(arg0) + 4)), matrixTemp.rotation[0], (*(f32 *)((char *)(arg0) + 0x10)), matrixTemp.rotation[1], (*(f32 *)((char *)(arg0) + 0x1C)), matrixTemp.rotation[2]);
        (*(f32 *)((char *)(arg0) + 4)) = temp_f1_6;
        temp_f1_7 = fn_80144514((f32) temp_f1_6, matrixTemp.rotation[3], (*(f32 *)((char *)(arg0) + 0x10)), matrixTemp.rotation[4], (*(f32 *)((char *)(arg0) + 0x1C)), matrixTemp.rotation[5]);
        (*(f32 *)((char *)(arg0) + 0x10)) = temp_f1_7;
        (*(f32 *)((char *)(arg0) + 0x1C)) = fn_80144514((*(f32 *)((char *)(arg0) + 4)), matrixTemp.rotation[6], (f32) temp_f1_7, matrixTemp.rotation[7], (*(f32 *)((char *)(arg0) + 0x1C)), matrixTemp.rotation[8]);
        temp_f1_8 = fn_80144514((*(f32 *)((char *)(arg0) + 8)), matrixTemp.rotation[0], (*(f32 *)((char *)(arg0) + 0x14)), matrixTemp.rotation[1], (*(f32 *)((char *)(arg0) + 0x20)), matrixTemp.rotation[2]);
        (*(f32 *)((char *)(arg0) + 8)) = temp_f1_8;
        temp_f1_9 = fn_80144514((f32) temp_f1_8, matrixTemp.rotation[3], (*(f32 *)((char *)(arg0) + 0x14)), matrixTemp.rotation[4], (*(f32 *)((char *)(arg0) + 0x20)), matrixTemp.rotation[5]);
        (*(f32 *)((char *)(arg0) + 0x14)) = temp_f1_9;
        (*(f32 *)((char *)(arg0) + 0x20)) = fn_80144514((*(f32 *)((char *)(arg0) + 8)), matrixTemp.rotation[6], (f32) temp_f1_9, matrixTemp.rotation[7], (*(f32 *)((char *)(arg0) + 0x20)), matrixTemp.rotation[8]);
    }
    if ((s32) (*(s32 *)((char *)(state) + 0x58)) >= 0) {
        {
            u32 *src = (u32 *)arg0;
            u32 *dst = (u32 *)saved;
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
            dst[4] = src[4];
            dst[5] = src[5];
            dst[6] = src[6];
            dst[7] = src[7];
            dst[8] = src[8];
            dst[9] = src[9];
            dst[10] = src[10];
            dst[11] = src[11];
        }
        switch ((s32) (*(s32 *)((char *)(state) + 0x5C))) { /* irregular */
        case 0:
            matrixTemp.basis[1] = lbl_80562970;
            matrixTemp.basis[0] = lbl_8056296C;
            matrixTemp.basis[2] = lbl_80562970;
            matrixTemp.basis[3] = lbl_80562970;
            matrixTemp.basis[4] = lbl_8056296C;
            matrixTemp.basis[5] = lbl_80562970;
            matrixTemp.basis[6] = lbl_80562970;
            matrixTemp.basis[7] = lbl_80562970;
            matrixTemp.basis[8] = lbl_8056296C;
            matrixTemp.basis[9] = lbl_80562970;
            matrixTemp.basis[10] = lbl_80562970;
            matrixTemp.basis[11] = lbl_80562970;
            break;
        case 1:
            matrixTemp.basis[0] = (*(f32 *)((char *)(temp_r31) + 0x274));
            matrixTemp.basis[1] = (*(f32 *)((char *)(temp_r31) + 0x278));
            matrixTemp.basis[2] = (*(f32 *)((char *)(temp_r31) + 0x27C));
            matrixTemp.basis[3] = (*(f32 *)((char *)(temp_r31) + 0x280));
            matrixTemp.basis[4] = (*(f32 *)((char *)(temp_r31) + 0x284));
            matrixTemp.basis[5] = (*(f32 *)((char *)(temp_r31) + 0x288));
            matrixTemp.basis[6] = (*(f32 *)((char *)(temp_r31) + 0x28C));
            matrixTemp.basis[7] = (*(f32 *)((char *)(temp_r31) + 0x290));
            matrixTemp.basis[8] = (*(f32 *)((char *)(temp_r31) + 0x294));
            matrixTemp.basis[9] = (*(f32 *)((char *)(temp_r31) + 0x298));
            matrixTemp.basis[10] = (*(f32 *)((char *)(temp_r31) + 0x29C));
            matrixTemp.basis[11] = (*(f32 *)((char *)(temp_r31) + 0x2A0));
            break;
        case 2:
            matrixTemp.basis[0] = (*(f32 *)((char *)(temp_r31) + 0x70));
            matrixTemp.basis[1] = (*(f32 *)((char *)(temp_r31) + 0x74));
            matrixTemp.basis[2] = (*(f32 *)((char *)(temp_r31) + 0x78));
            matrixTemp.basis[3] = (*(f32 *)((char *)(temp_r31) + 0x7C));
            matrixTemp.basis[4] = (*(f32 *)((char *)(temp_r31) + 0x80));
            matrixTemp.basis[5] = (*(f32 *)((char *)(temp_r31) + 0x84));
            matrixTemp.basis[6] = (*(f32 *)((char *)(temp_r31) + 0x88));
            matrixTemp.basis[7] = (*(f32 *)((char *)(temp_r31) + 0x8C));
            matrixTemp.basis[8] = (*(f32 *)((char *)(temp_r31) + 0x90));
            matrixTemp.basis[9] = (*(f32 *)((char *)(temp_r31) + 0x94));
            matrixTemp.basis[10] = (*(f32 *)((char *)(temp_r31) + 0x98));
            matrixTemp.basis[11] = (*(f32 *)((char *)(temp_r31) + 0x9C));
            break;
        default:
            fn_802E317C(&lbl_80336E88);
            break;
        }
        if ((s32) (*(s32 *)((char *)(state) + 0x5C)) != 1) {
            fn_801BFD34(arg0 + 0x24, &saved[9], &matrixTemp.basis[0]);
            fn_80015B20((s32)arg0, &saved[0], (s32)&matrixTemp.basis[0]);
        } else {
            (*(f32 *)((char *)(arg0) + 0x24)) = matrixTemp.basis[9];
            (*(f32 *)((char *)(arg0) + 0x28)) = matrixTemp.basis[10];
            (*(f32 *)((char *)(arg0) + 0x2C)) = matrixTemp.basis[11];
            if (((void *)arg0 == (void *)&saved[0]) || ((void *)arg0 == (void *)&matrixTemp.basis[0])) {
                temp_f23_3 = fn_80144514(matrixTemp.basis[0], saved[0], matrixTemp.basis[3], saved[1], matrixTemp.basis[6], saved[2]);
                temp_f24_3 = fn_80144514(matrixTemp.basis[0], saved[3], matrixTemp.basis[3], saved[4], matrixTemp.basis[6], saved[5]);
                temp_f25_2 = fn_80144514(matrixTemp.basis[0], saved[6], matrixTemp.basis[3], saved[7], matrixTemp.basis[6], saved[8]);
                temp_f26_2 = fn_80144514(matrixTemp.basis[1], saved[0], matrixTemp.basis[4], saved[1], matrixTemp.basis[7], saved[2]);
                temp_f27_2 = fn_80144514(matrixTemp.basis[1], saved[3], matrixTemp.basis[4], saved[4], matrixTemp.basis[7], saved[5]);
                temp_f28_2 = fn_80144514(matrixTemp.basis[1], saved[6], matrixTemp.basis[4], saved[7], matrixTemp.basis[7], saved[8]);
                temp_f31_3 = fn_80144514(matrixTemp.basis[2], saved[0], matrixTemp.basis[5], saved[1], matrixTemp.basis[8], saved[2]);
                temp_f30_3 = fn_80144514(matrixTemp.basis[2], saved[3], matrixTemp.basis[5], saved[4], matrixTemp.basis[8], saved[5]);
                temp_f1_10 = fn_80144514(matrixTemp.basis[2], saved[6], matrixTemp.basis[5], saved[7], matrixTemp.basis[8], saved[8]);
                (*(f32 *)((char *)(arg0) + 0)) = temp_f23_3;
                (*(f32 *)((char *)(arg0) + 0xC)) = temp_f24_3;
                (*(f32 *)((char *)(arg0) + 0x18)) = temp_f25_2;
                (*(f32 *)((char *)(arg0) + 4)) = temp_f26_2;
                (*(f32 *)((char *)(arg0) + 0x10)) = temp_f27_2;
                (*(f32 *)((char *)(arg0) + 0x1C)) = temp_f28_2;
                (*(f32 *)((char *)(arg0) + 8)) = temp_f31_3;
                (*(f32 *)((char *)(arg0) + 0x14)) = temp_f30_3;
                (*(f32 *)((char *)(arg0) + 0x20)) = temp_f1_10;
            } else {
                (*(f32 *)((char *)(arg0) + 0)) = fn_80144514(matrixTemp.basis[0], saved[0], matrixTemp.basis[3], saved[1], matrixTemp.basis[6], saved[2]);
                (*(f32 *)((char *)(arg0) + 0xC)) = fn_80144514(matrixTemp.basis[0], saved[3], matrixTemp.basis[3], saved[4], matrixTemp.basis[6], saved[5]);
                (*(f32 *)((char *)(arg0) + 0x18)) = fn_80144514(matrixTemp.basis[0], saved[6], matrixTemp.basis[3], saved[7], matrixTemp.basis[6], saved[8]);
                (*(f32 *)((char *)(arg0) + 4)) = fn_80144514(matrixTemp.basis[1], saved[0], matrixTemp.basis[4], saved[1], matrixTemp.basis[7], saved[2]);
                (*(f32 *)((char *)(arg0) + 0x10)) = fn_80144514(matrixTemp.basis[1], saved[3], matrixTemp.basis[4], saved[4], matrixTemp.basis[7], saved[5]);
                (*(f32 *)((char *)(arg0) + 0x1C)) = fn_80144514(matrixTemp.basis[1], saved[6], matrixTemp.basis[4], saved[7], matrixTemp.basis[7], saved[8]);
                (*(f32 *)((char *)(arg0) + 8)) = fn_80144514(matrixTemp.basis[2], saved[0], matrixTemp.basis[5], saved[1], matrixTemp.basis[8], saved[2]);
                (*(f32 *)((char *)(arg0) + 0x14)) = fn_80144514(matrixTemp.basis[2], saved[3], matrixTemp.basis[5], saved[4], matrixTemp.basis[8], saved[5]);
                (*(f32 *)((char *)(arg0) + 0x20)) = fn_80144514(matrixTemp.basis[2], saved[6], matrixTemp.basis[5], saved[7], matrixTemp.basis[8], saved[8]);
            }
            if ((void *)arg0 == (void *)&saved[9]) {
                f32 offsetX = (saved[11] * (*(f32 *)((char *)(arg0) + 0x18))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 0))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0xC))));
                f32 offsetY = (saved[11] * (*(f32 *)((char *)(arg0) + 0x1C))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 4))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0x10))));
                f32 offsetZ = (saved[11] * (*(f32 *)((char *)(arg0) + 0x20))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 8))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0x14))));
                resultTemp.offset[0] = offsetX;
                resultTemp.offset[1] = offsetY;
                resultTemp.offset[2] = offsetZ;
            } else {
                resultTemp.offset[0] = (saved[11] * (*(f32 *)((char *)(arg0) + 0x18))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 0))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0xC))));
                resultTemp.offset[1] = (saved[11] * (*(f32 *)((char *)(arg0) + 0x1C))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 4))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0x10))));
                resultTemp.offset[2] = (saved[11] * (*(f32 *)((char *)(arg0) + 0x20))) + ((saved[9] * (*(f32 *)((char *)(arg0) + 8))) + (saved[10] * (*(f32 *)((char *)(arg0) + 0x14))));
            }
            (*(f32 *)((char *)(arg0) + 0x24)) = (f32) ((*(f32 *)((char *)(arg0) + 0x24)) + resultTemp.offset[0]);
            (*(f32 *)((char *)(arg0) + 0x28)) = (f32) ((*(f32 *)((char *)(arg0) + 0x28)) + resultTemp.offset[1]);
            (*(f32 *)((char *)(arg0) + 0x2C)) = (f32) ((*(f32 *)((char *)(arg0) + 0x2C)) + resultTemp.offset[2]);
        }
    }
    
    if (((f32) __fabs((*(f32 *)((char *)(state) + 0x64)))  > lbl_80558DC4[0]) && (var_f29 < (*(f32 *)((char *)(state) + 0x64)))) {
        var_f23 = var_f29 / (*(f32 *)((char *)(state) + 0x64));
        if ((s32) (*(s32 *)((char *)(state) + 0x60)) == 1) {
            var_f0_2 = lbl_80562990;
            if (var_f23 < var_f0_2) {

            } else {
                var_f0_2 = lbl_8056296C;
                if (var_f23 > var_f0_2) {

                } else if (var_f23 > lbl_80562970) {
                    var_f0_2 = (var_f23 * (lbl_805629C0 * var_f23 * var_f23)) + (lbl_805629C4 * var_f23 * var_f23);
                } else {
                    var_f0_2 = (var_f23 * (lbl_805629C0 * var_f23 * var_f23)) - (lbl_805629C4 * var_f23 * var_f23);
                }
            }
            var_f23 = var_f0_2;
        }
        fn_801C2FF4((f32 *)arg0, (f32 *)((char *)state + 0x68), (f32 *)arg0, var_f23);
        (*(f32 *)((char *)(state) + 0x50)) = (f32) ((*(f32 *)((char *)(state) + 0x98)) + (var_f23 * ((*(f32 *)((char *)(state) + 0x50)) - (*(f32 *)((char *)(state) + 0x98)))));
    } else {
        {
            u32 *src = (u32 *)arg0;
            u32 *dst = (u32 *)((char *)state + 0x68);
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
            dst[4] = src[4];
            dst[5] = src[5];
            dst[6] = src[6];
            dst[7] = src[7];
            dst[8] = src[8];
            dst[9] = src[9];
            dst[10] = src[10];
            dst[11] = src[11];
        }
        (*(f32 *)((char *)(state) + 0x98)) = (f32) (*(f32 *)((char *)(state) + 0x50));
    }
    temp_r5 = arg1 * 0x30;
    (*(f32 *)((char *)(arg0) + 0x30)) = (f32) (*(f32 *)((char *)(state) + 0x50));
    temp_r4 = (char *)state + 0x148;
    *(u32 *)(temp_r4 + temp_r5) = ((u32 *)arg0)[0];
    temp_r9 = temp_r4 + temp_r5;
    temp_r10 = arg1 * 0xC;
    *(u32 *)(temp_r9 + 4) = ((u32 *)arg0)[1];
    temp_r6 = (char *)state + 0x208;
    temp_r5_2 = temp_r6 + temp_r10;
    *(u32 *)(temp_r9 + 8) = ((u32 *)arg0)[2];
    *(u32 *)(temp_r9 + 0xC) = ((u32 *)arg0)[3];
    *(u32 *)(temp_r9 + 0x10) = ((u32 *)arg0)[4];
    *(u32 *)(temp_r9 + 0x14) = ((u32 *)arg0)[5];
    *(u32 *)(temp_r9 + 0x18) = ((u32 *)arg0)[6];
    *(u32 *)(temp_r9 + 0x1C) = ((u32 *)arg0)[7];
    *(u32 *)(temp_r9 + 0x20) = ((u32 *)arg0)[8];
    *(u32 *)(temp_r9 + 0x24) = ((u32 *)arg0)[9];
    *(u32 *)(temp_r9 + 0x28) = ((u32 *)arg0)[10];
    *(u32 *)(temp_r9 + 0x2C) = ((u32 *)arg0)[11];
    ((f32 *)temp_r6)[arg1 * 3] = (*(f32 *)((char *)(temp_r31) + 0x118));
    ((f32 *)temp_r6)[arg1 * 3 + 1] = (*(f32 *)((char *)(temp_r31) + 0x11C));
    ((f32 *)temp_r6)[arg1 * 3 + 2] = (*(f32 *)((char *)(temp_r31) + 0x120));
    (*(s32 *)((char *)(arg0) + 0x60)) = var_r29;
    (*(s32 *)((char *)(arg0) + 0x5C)) = 0xB;
    (*(s32 *)((char *)(arg0) + 0x58)) = 0xB;
    (*(s16 *)((char *)(arg0) + 0x64)) = (s16) (*(s16 *)((char *)(temp_r31) + 0x6C));
    sp20 = var_r29;
    sp24 = temp_r9;
    sp28 = temp_r5_2;
    fn_8020655C(&sp20, 0);
    return 1;
}
#pragma scheduling off
#pragma paired off
#pragma paired_single off
s32 fn_801C6C28(Vec *arg0) {
    float threshold = lbl_805629CC;
    s32 result = -1;
    s32 i = 0;

    goto check;
body:
    if (PSVECSquareDistance((Vec *)(fn_8017960C(i) + 0x60), arg0) < threshold) {
        result = i;
        goto done;
    }
    i++;
check:
    if (i < lbl_8055E804) {
        goto body;
    }
done:
    return result;
}
#pragma paired_single reset
#pragma paired reset
#pragma scheduling reset
void fn_801C6CB0(void) {
    return;
}

void fn_801C6CB4(void) {
    fn_801C957C(1);
}

#pragma inline off
void fn_801C6CBC(void) {
    sprintf(lbl_804380F0, lbl_8055AA4C, lbl_804380F0, fn_801C6C28(&lbl_80438268));
}
#pragma inline auto
void fn_801C6D00(void) {
    /* Copy a 12-word matrix/state block and an associated value from one global location to another. */
    struct MtxCopy {
        s32 data[12];
    };
    *(struct MtxCopy *)lbl_804381F0 = *(struct MtxCopy *)lbl_80499050;
    lbl_8055E834 = lbl_8055F47C;
}

void fn_801C7288(void);
void fn_801C7288(void) {
    fn_801C957C(0);
}

void fn_801C7290(void) {
    void *ptr = fn_801C3C80();
    ((s32 *)ptr)[2] = 2;
    sprintf(lbl_80437FC0, lbl_80336EC8, ((f32 *)ptr)[0]);
    qsort((void *)(s32)lbl_8055E7F8, (size_t)lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
}

extern char lbl_80336EE8[];
void fn_801C72F0(void) {
    void *ptr = fn_801C3C80();
    ((s32 *)ptr)[2] = 7;
    strncpy((char *)ptr + 0x10C, lbl_804380F0, 0x1FF);
    sprintf(lbl_80437FC0, lbl_80336EE8, (double)((f32 *)ptr)[0]);
    qsort((void *)(s32)lbl_8055E7F8, (size_t)lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
    fn_801C957C(0);
}

void fn_801C7374(void);
void fn_801C7374(void) {
    fn_801C957C(0);
}

void fn_801C737C(void) {
    lbl_8055E839 = 1;
}

extern char lbl_8055E839;
void fn_801C7388(void) {
    lbl_8055E839 = 0;
}

void fn_801C7394(void) {
    s32 temp_r3;

    if (lbl_8055E7F0 > 0) {
        fn_801C3C14(lbl_8055E828);
        temp_r3 = lbl_8055E7F0 - 1;
        if (lbl_8055E828 > temp_r3) {
            lbl_8055E828 = temp_r3;
        }
    }
}

void fn_801C73DC(void) {
    s32 count;
    s32 current;
    s32 index;
    s32 previousOffset;
    s32 currentOffset;
    char *base;
    s32 currentKey;
    s32 previousKey;
    count = lbl_8055E7F0;
    current = lbl_8055E828;
    index = current - 1;
    if (count == 0)
        goto done;
    if (index < 0)
        goto done;
    if (count <= index)
        goto done;
    previousOffset = index * 0x30C;
    currentOffset = current * 0x30C;
    base = (char *)lbl_8055E7F8;
    if (fn_801C34CC(*(f32 *)(base + currentOffset), *(f32 *)(base + previousOffset))) {
        base = (char *)lbl_8055E7F8;
        currentKey = *(s32 *)(base + currentOffset + 4);
        previousKey = *(s32 *)(base + previousOffset + 4);
        *(s32 *)(base + currentOffset + 4) = previousKey;
        *(s32 *)(base + previousOffset + 4) = currentKey;
        qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C,
              (int (*)(const void *, const void *))fn_801C3B7C);
    }
done:
    ;
}

#pragma scheduling invalid_target
/* Move the debug timeline selection down one entry.  When the entry left and the
 * one entered were recorded at the same time (fn_801C34CC compares the entry
 * times), their ranks at +0x4 are swapped so the player's order wins over the
 * stored one, and the table is re-sorted the way its writers do. */
void fn_801C7480(void) {
    typedef struct TimelineEntry {
        f32 time; /* +0x0: sort key of the entry */
        s32 rank; /* +0x4: order among entries sharing the time */
    } TimelineEntry; /* one 0x30C-byte entry of sTimelineEntries */
    register long selectedIndex = sTimelineSelection;
    long nextIndex = selectedIndex + 1;
    int entryCount = sTimelineCount;
    if (entryCount) {
        if (0 <= (int)nextIndex) {
            if (nextIndex < entryCount) {
                long nextOff = nextIndex * 0x30C;
                long selectedOff = selectedIndex * 0x30C;
                TimelineEntry *selected = (TimelineEntry *)((char *)(s32)sTimelineEntries + selectedOff);
                TimelineEntry *following = (TimelineEntry *)((char *)(s32)sTimelineEntries + nextOff);
                if (fn_801C34CC(selected->time, following->time)) {
                    /* both entry addresses are rebuilt here to trade their rank words */
                    s32 *selectedRank = (s32 *)((char *)sTimelineEntries + selectedOff);
                    s32 *followingRank = (s32 *)((char *)sTimelineEntries + nextOff);
                    int swappedRank = selectedRank[1];
                    selectedRank[1] = followingRank[1];
                    followingRank[1] = swappedRank;
                    qsort((void *)sTimelineEntries, (size_t)sTimelineCount, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
                }
            }
        }
    }
}
#pragma scheduling on
void fn_801C7524(void) {
    s32 index;
    fn_801C957C(1);
    index = lbl_8055E828 * 0x30C;
    sprintf(lbl_804380F0, lbl_8055AA54, *(f32 *)(lbl_8055E7F8 + index));
}

#pragma push
#pragma paired reset
#pragma paired_single reset
#pragma scheduling reset
void fn_801C756C(void) {
    /* Parse the input string into a time, update the selected entry's score/rank, sort entries, then refresh display. */
    register f64 parsedValue;
    register u32 entryOffset;
    register s32 highestRank;
    register s32 i;
    if (lbl_8055E7F0 <= 0)
        goto done;
    parsedValue = (f64)(f32)atof(lbl_804380F0);
    highestRank = 0;
    i = 0;
    entryOffset = 0;
    goto check;
loop:
    if (fn_801C34CC(*(f32*)((u8*)lbl_8055E7F8 + entryOffset), (f32)parsedValue)) {
        s32 rank = *(s32*)((u8*)lbl_8055E7F8 + entryOffset + 4);
        if (rank > highestRank)
            highestRank = rank;
    }
    entryOffset += 0x30C;
    i++;
check:
    if (i < lbl_8055E7F0)
        goto loop;
    {
        register s32 selectedIndex = lbl_8055E828;
        register u8 *entryBase = (u8*)lbl_8055E7F8;
        if (*(s32*)(entryBase + selectedIndex * 0x30C + 8) == 1) {
            *(f32*)(entryBase + selectedIndex * 0x30C + 0x58) =
                (f32)parsedValue + (*(f32*)(entryBase + selectedIndex * 0x30C + 0x58) -
                                    ((f32*)entryBase)[selectedIndex * 195]);
        }
    }
    *(f32*)((u8*)lbl_8055E7F8 + lbl_8055E828 * 0x30C) =
        fn_801C3450((f32)parsedValue);
    *(s32*)((u8*)lbl_8055E7F8 + lbl_8055E828 * 0x30C + 4) = highestRank + 1;
    qsort((void*)lbl_8055E7F8, lbl_8055E7F0, 0x30C,
          (int (*)(const void*, const void*))fn_801C3B7C);
done:
    fn_801C957C(0);
}
#pragma pop
void fn_801C7698(void) {
    s32 offset;
    s32 index;
    register f32 value;
    if (lbl_8055E7F0 > 0) {
        value = (f32)atof(lbl_804380F0);
        index = lbl_8055E828;
        offset = index * 0x30C;
        if (value + *(f32 *)((char *)(*(volatile s32 *)&lbl_8055E7F8) + offset) < lbl_80562970) {
            sprintf(lbl_80437FC0, lbl_80336F0C);
        } else {
            do {
                *(f32 *)((char *)(*(volatile s32 *)&lbl_8055E7F8) + offset) =
                    fn_801C3450(value + *(f32 *)((char *)(*(volatile s32 *)&lbl_8055E7F8) + offset));
                index++;
                offset += 0x30C;
            } while (index < lbl_8055E7F0);
            qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C,
                  (int (*)(const void *, const void *))fn_801C3B7C);
        }
    }
    fn_801C957C(0);
}
#pragma pop

extern u8 lbl_8055E83E;
extern u8 lbl_8055E841;
extern s32 lbl_8055E844;
extern char lbl_8055E83A;
extern char lbl_8055E83C;
extern void (*lbl_8055E868)(void);
extern s32 lbl_8055E848;
extern int atoi(const char *);
extern char lbl_8055E83B;
extern char lbl_8055E83D;
extern Vec lbl_80438250;
#ifndef UNK_80437D88_DEFINED
#define UNK_80437D88_DEFINED
typedef struct Unk_80437D88 {
    char pad_0[0x4D4];
    Vec f_4D4;
    Vec f_4E0;
    char pad_1[0x6F8 - 0x4EC];
    Vec f_6F8;
} Unk_80437D88;
#endif
extern Unk_80437D88 lbl_80437D88;
extern void fn_801C7964(void);
extern s32 lbl_8055E828;
extern char lbl_8055AA54[5];
extern s32 fn_801C34CC(f32, f32);
#pragma scheduling off
extern s32 lbl_8055E82C;
void fn_801C855C(void);
extern unsigned char lbl_8055E83E;
void fn_801C7770(void) {
    *(s8*)&lbl_8055E83E = !lbl_8055E83E;
}

void fn_801C7784(void) {
    *(s8*)&lbl_8055E83F = !lbl_8055E83F;
}

void fn_801C7798(void) {
    *(s8*)&lbl_8055E840 = !lbl_8055E840;
}

void fn_801C77AC(void) {
    *(s8*)&lbl_8055E841 = !lbl_8055E841;
}

#pragma scheduling on
void fn_801C77C0(void) {
    lbl_8055E844 = atoi(lbl_804380F0);
    lbl_8055E841 = 0;
    fn_801C957C(0);
}

extern u8 lbl_8055E83F;
extern u8 lbl_8055E840;
extern char lbl_8055AA5C;
extern char lbl_8055AA64;
extern char lbl_80336F24[];
/* Append a sound sample entry to the debug timeline (random or numbered), format a status message, and sort the timeline. */
void fn_801C77FC(void) {
    char sampleName[0x10];
    void *entry = fn_801C3C80();
    s32 flag;

    *(s32 *)((char *)entry + 8) = 3;
    *(u8 *)((char *)entry + 0x15) = lbl_8055E83F;
    *(u8 *)((char *)entry + 0x14) = lbl_8055E83E;
    flag = lbl_8055E840;
    *(s32 *)((char *)entry + 0x10) = flag != 0;
    flag = lbl_8055E841;
    if (flag != 0)
        *(s32 *)((char *)entry + 0xC) = -1;
    else
        *(s32 *)((char *)entry + 0xC) = lbl_8055E844;
    if (flag != 0) {
        strcpy(sampleName, (const char *)&lbl_8055AA5C);
    } else {
        sprintf(sampleName, (const char *)&lbl_8055AA64, lbl_8055E844);
    }
    sprintf(lbl_80437FC0, lbl_80336F24, sampleName, *(f32 *)entry);
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C,
          (int (*)(const void *, const void *))fn_801C3B7C);
}

#pragma auto_inline off
void fn_801C78D8(void) {
    lbl_8055E83C = 1;
    fn_801C957C(1);
    lbl_8055E83A = 1;
    lbl_8055E868 = fn_801C6CBC;
}

void fn_801C791C(void) {
    fn_801C78D8();
    lbl_8055E848 = 2;
}

void (*fn_801C7944(void))(void) {
    lbl_8055E83A = 1;
    lbl_8055E848 = 0;
    lbl_8055E868 = fn_801C6CB0;
    return fn_801C6CB0;
}

#pragma scheduling on
void fn_801C7964(void) {
    Vec* src = &lbl_80438268;
    Vec* dst = &lbl_80438250;
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
void (*fn_801C7990(void))(void) {
    register Unk_80437D88 *s = &lbl_80437D88;
    register Vec *src = (Vec *)((char *)s + 0x4E0);
    register Vec *dst1 = (Vec *)((char *)s + 0x6F8);
    register Vec *dst2 = (Vec *)((char *)s + 0x4D4);
    dst1->x = src->x;
    dst1->y = src->y;
    dst1->z = src->z;
    lbl_8055E83B = 1;
    dst2->x = src->x;
    dst2->y = src->y;
    dst2->z = src->z;
    lbl_8055E868 = fn_801C7964;
    return fn_801C7964;
}

void fn_801C79E0(void) {
    Vec *src = &lbl_80438268;
    Vec *dst = &lbl_8043848C;
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    lbl_8055E83B = 0;
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83D = 1;
}

extern char lbl_80438280[];
extern char lbl_80438380[];
extern char lbl_8055A95C[7];
extern char lbl_8055AA44[4];
extern s32 lbl_8055E864;
extern Vec lbl_80438498;
extern char lbl_8055E83D;
void fn_801C7A28(void) {
    lbl_80438498.x = lbl_80438268.x;
    lbl_80438498.y = lbl_80438268.y;
    lbl_80438498.z = lbl_80438268.z;
    lbl_8055E83A = 0;
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83D = 0;
    ((void (*)(f32, f32))fn_801C78D8)(lbl_80438268.y, lbl_80438268.x);
}

extern f64 atof(const char *);
void fn_801C7A6C(void) {
    f32 value = (f32)atof(lbl_804380F0);
    lbl_80438498.x = lbl_80562970;
    lbl_80438498.y = lbl_80562970;
    lbl_80438498.z = value;
    strcpy(lbl_804380F0, lbl_8055AA44);
}

#pragma push
#pragma small_data off
#pragma pop
extern Vec lbl_8043848C;
void fn_801C7AC4(void) {
    strcpy(lbl_80438280, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_80438280[0] == 0) strcpy(lbl_80438280, lbl_8055A95C);
}
void fn_801C7B28(void) {
    strcpy(lbl_80438380, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_80438380[0] == 0)
        strcpy(lbl_80438380, lbl_8055A95C);
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83A = 0;
}

#pragma push
#pragma small_data off
#pragma pop
void fn_801C7BA0(void) {
    void (*callback)(void) = fn_801C6CB0;
    lbl_8055E83D = 0;
    lbl_8055E83C = 0;
    lbl_8055E83B = 0;
    lbl_8055E83A = 0;
    lbl_8055E868 = callback;
    strcpy(lbl_80438280, lbl_8055AA44);
    strcpy(lbl_80438380, lbl_8055AA44);
    fn_801C957C(0);
}

#pragma push
#pragma scheduling on
void fn_801C7C04(void) {
    extern f32 lbl_805629D4, lbl_8055E84C;
    extern char lbl_80336F4C[], lbl_80336F88[];
    extern double fn_8002EFB0(f32, f32);
    char *base = (char *)&lbl_80437D88;
    char *obj;
    Vec *start = (Vec *)(base + 0x6F8), *mid = (Vec *)(base + 0x704), *end = (Vec *)(base + 0x710);
    f32 a[2], b[2], c[2], d[2], e[2], f[2], g[2], h[2], i[2];
    f32 *p, *q;
    f32 x, y, len, scale;
    lbl_8055E84C = lbl_805629D4 * (f32)atof(base + 0x368);
    fn_801C957C(0);
    obj = fn_801C3C80();
    *(s32 *)(obj + 8) = 4;
    *(s32 *)(obj + 0x210) = lbl_8055E848;
    strcpy(obj + 0x10, base + 0x4F8);
    strcpy(obj + 0x110, base + 0x5F8);
    *(s32 *)(obj + 0xC) = fn_801C3954((s32)obj + 0x10);
    *(s32 *)(obj + 0xC) &= ~fn_801C3954((s32)obj + 0x110);
    *(f32 *)(obj + 0x214) = lbl_8055E84C;
    switch (*(s32 *)(obj + 0x210)) {
    case 2:
        *(f32 *)(obj + 0x220) = lbl_80562970;
        b[1] = end->z; b[0] = end->x;
        *(f32 *)(obj + 0x218) = b[0]; *(f32 *)(obj + 0x21C) = b[1];
        break;
    case 0:
        c[0] = start->x; c[1] = start->z;
        *(f32 *)(obj + 0x218) = c[0]; *(f32 *)(obj + 0x21C) = c[1];
        d[0] = end->x; d[1] = end->z;
        *(f32 *)(obj + 0x224) = d[0] - *(f32 *)(obj + 0x218);
        *(f32 *)(obj + 0x228) = d[1] - *(f32 *)(obj + 0x21C);
        f[1] = start->z; e[1] = mid->z;
        f[0] = start->x; e[0] = mid->x;
        a[0] = e[0] - f[0]; a[1] = e[1] - f[1];
        g[0] = lbl_80562970; g[1] = lbl_8056296C;
        q = g; p = a;
        len = a[0]*a[0] + a[1]*a[1];
        if (!((f32)__fabs((f64)(len-lbl_8056296C)) <= lbl_80558DC4[0])) {
            i[0] = a[0]; i[1] = a[1];
            scale = lbl_8056296C / (f32)fn_8002F234(len);
            i[0] *= scale; i[1] *= scale; p = i;
        }
        len = g[0]*g[0] + g[1]*g[1];
        if (!((f32)__fabs((f64)(len-lbl_8056296C)) <= lbl_80558DC4[0])) {
            h[0] = g[0]; h[1] = g[1];
            scale = lbl_8056296C / (f32)fn_8002F234(len);
            h[0] *= scale; h[1] *= scale; q = h;
        }
        *(f32 *)(obj + 0x220) = (f32)fn_8002EFB0(p[0]*q[1]-q[0]*p[1], p[0]*q[0]+p[1]*q[1]);
        break;
    default:
        fn_802E317C(lbl_80336F4C);
        break;
    }
    sprintf(base + 0x238, lbl_80336F88, *(f32 *)(base+0x6F8), *(f32 *)(base+0x700), *(f32 *)obj);
    fn_801C7BA0();
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
}
#pragma pop
extern s32 lbl_8055E850;
extern void fn_801C78D8(void);
void fn_801C7EF4(void) {
    lbl_8055E850 = 0;
    fn_801C78D8();
}

extern char lbl_8055A964[7];
void fn_801C7F00(void) {
    strcpy(lbl_80438280, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_80438280[0] == 0) strcpy(lbl_80438280, lbl_8055A964);
}

#pragma push
#pragma small_data off
#pragma pop
void fn_801C7F64(void) {
    strcpy(lbl_80438380, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_80438380[0] == 0) {
        strcpy(lbl_80438380, lbl_8055A95C);
    }
    fn_801C957C(0);
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83A = 1;
}

#pragma push
#pragma opt_propagation off
void fn_801C7FE4(void) {
    extern char lbl_80336FB0[];
    char *base = (char *)&lbl_80437D88;
    char *obj;
    Vec *v = (Vec *)(base + 0x4E0);
    Vec *dst;
    lbl_8055E83A = 0;
    obj = fn_801C3C80();
    *(s32 *)(obj + 8) = 6;
    *(s32 *)(obj + 0xC) = lbl_8055E850;
    strcpy(obj + 0x14, base + 0x4F8);
    strcpy(obj + 0x114, base + 0x5F8);
    *(s32 *)(obj + 0x10) = fn_801C3954((s32)obj + 0x14);
    *(s32 *)(obj + 0x10) &= ~fn_801C3954((s32)obj + 0x114);
    dst = (Vec *)(obj + 0x214);
    dst->x = v->x;
    dst->y = v->y;
    dst->z = v->z;
    sprintf(base + 0x238, lbl_80336FB0, *(f32 *)obj);
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
}
#pragma pop
extern f32 lbl_805629B4;
extern f32 lbl_8055E85C, lbl_8055E860;
extern s32 lbl_8055E854;
extern void fn_801C78D8(void);
void fn_801C80BC(void) {
    lbl_8055E854 = 0;
    fn_801C78D8();
}

void fn_801C80C8(void) {
    lbl_8055E83A = 1;
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E854 = 2;
}

void fn_801C80E8(void) {
    lbl_8055E854 = 3;
    lbl_8055E860 = lbl_805629B4;
    lbl_8055E85C = lbl_80562970;
    lbl_8055E83A = 1;
    lbl_8055E868 = fn_801C6CBC;
    fn_801C957C(1, fn_801C6CBC, lbl_805629B4);
}

void fn_801C811C(void) {
    lbl_8055E854 = 4;
    lbl_8055E860 = lbl_805629B4;
    lbl_8055E85C = lbl_80562970;
    lbl_8055E83A = 1;
    lbl_8055E868 = fn_801C6CBC;
    fn_801C957C(1, fn_801C6CBC, lbl_805629B4);
}

void fn_801C8150(void) {
    lbl_8055E864 = atoi(lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
}

void fn_801C8190(void) {
    lbl_8055E854 = 1;
    fn_801C78D8();
}

extern f32 lbl_8055E85C;
extern f32 lbl_8055E860;
extern f32 lbl_8055A958;
extern s32 lbl_8055E864;
extern char lbl_804384A8[];
extern char lbl_804385A8[];
extern char lbl_80336FDC[];
extern void fn_801C7BA0(void);
void fn_801C819C(void) {
    lbl_8055E85C = lbl_80438268.x;
    lbl_8055E860 = lbl_80438268.z;
    fn_801C78D8();
}

extern char lbl_8055A964[7];
void fn_801C81B8(void) {
    strcpy(lbl_804384A8, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_804384A8[0] == 0) strcpy(lbl_804384A8, lbl_8055A964);
}

void fn_801C821C(void) {
    strcpy(lbl_804385A8, lbl_804380F0);
    strcpy(lbl_804380F0, lbl_8055AA44);
    if (lbl_804385A8[0] == 0)
        strcpy(lbl_804385A8, lbl_8055A95C);
    lbl_8055E83A = 0;
    lbl_8055E868 = fn_801C6CB0;
    lbl_8055E83C = 0;
}
#pragma push
#pragma scheduling on
#pragma dont_inline on
void fn_801C8298(void) {
    strcpy(lbl_804384A8, lbl_8055AA44);
    strcpy(lbl_804385A8, lbl_8055AA44);
    lbl_8055E864 = 0;
    fn_801C7BA0();
}
#pragma scheduling on

void fn_801C82E0(void) {
    extern char lbl_80336FC4[];
    extern f32 lbl_805629D4;
    extern f32 lbl_8055E85C;
    extern f32 lbl_8055E860;
    extern f32 lbl_8055E858;
    extern s32 lbl_8055E864;
    Unk_80437D88 *base = &lbl_80437D88;
    void *obj;
    f32 value = (f32)atof((char *)base + 0x368);
    lbl_8055E858 = lbl_805629D4 * value;
    /* Create an AI-think interlude command entry, fill its fields, sort entries, and reset interlude state. */
    obj = fn_801C3C80();
    *(s32 *)((char *)obj + 8) = 5;
    *(s32 *)((char *)obj + 0x210) = lbl_8055E854;
    strcpy((char *)obj + 0x10, (char *)base + 0x720);
    strcpy((char *)obj + 0x110, (char *)base + 0x820);
    *(s32 *)((char *)obj + 0xC) = fn_801C3954((s32)obj + 0x10);
    *(s32 *)((char *)obj + 0xC) &= ~fn_801C3954((s32)obj + 0x110);
    *(f32 *)((char *)obj + 0x21C) = lbl_8055E85C;
    *(f32 *)((char *)obj + 0x220) = lbl_8055E860;
    *(f32 *)((char *)obj + 0x218) = lbl_8055E858;
    *(s32 *)((char *)obj + 0x214) = lbl_8055E864;
    sprintf((char *)base + 0x238, lbl_80336FC4, *(f32 *)obj);
    qsort((void *)lbl_8055E7F8, lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
    fn_801C8298();
}

#pragma dont_inline off
#pragma pop
void fn_801C83D0(void) {
    f32 value = (f32)atof(lbl_804380F0);
    lbl_8055A958 = value;
    sprintf(lbl_80437FC0, lbl_80336FDC, value);
    fn_801C957C(0);
}

extern char lbl_8055AA68[6];
extern s32 fn_8013181C(void *, void *, void *);
extern void fn_80128684(void);
extern void fn_8012BEF0(void *);
extern void fn_8012BF24(void *);
extern void fn_80128678(void);
void fn_801C8420(void) {
    /* Load the selected interlude file from the debug menu: query path/name parts, build the file path, load it, and report status. */
    char filePath[256];
    char *debugStrings = lbl_80336B00;
    char *fileName = debugStrings + 0x4fc;
    char *dirName = debugStrings + 0x50c;

    if (fn_8013181C(debugStrings + 0x51c, dirName, fileName) != 0) {
        sprintf(filePath, lbl_8055AA68, fileName, dirName);
        fn_80128684();
        fn_8012BEF0(fileName);
        fn_801C3D88(filePath);
        fn_8012BF24(fileName);
        fn_80128678();
        sprintf(lbl_80437FC0, debugStrings + 0x52c);
    } else {
        sprintf(lbl_80437FC0, debugStrings + 0x544);
    }
}

extern char lbl_80337060[];
void fn_801C84E0(void) {
    lbl_8055E80D = 0;
    sprintf(lbl_80437FC0, lbl_80337060);
}

extern char lbl_8055AA70;
extern char lbl_8055AA78;
extern char lbl_8055AA7C;
extern char lbl_8055AA80;
extern char lbl_8055AA88;
extern char lbl_8055AA90;
extern char lbl_8055AA98;
extern char lbl_8055AAA0;
extern char lbl_8055AAA8;
extern char lbl_8055AAB0;
extern char lbl_8055AAB8;
extern char lbl_8055AAC0;
extern char lbl_8055AAC8;
extern char lbl_8055AAD0;
extern char lbl_8055AAD8;
extern char lbl_8055AAE0;
extern char lbl_8055AAE8;
#pragma scheduling on
void fn_801C855C(void) {
    struct Entry { void *name; void *callback; s32 id; s32 flags; };
    char *base = lbl_80336B00;
    void *root;
    struct Entry *items;
    void *cb4 = (void *)fn_801C6CB4;
    void *cb0 = (void *)fn_801C6CB0;
    root = (void *)fn_8012850C(0x210, &lbl_8055AA70);
    lbl_8055E86C = root;
    memset(root, 0, 0x210U);
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x4))[0] = (void *)(base + 0x5a0);
    *(s32 *)((char *)root + 0x8) = 0xb;
    items = (struct Entry *)fn_8012850C(0xb0, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x0) = items;
    items[0].name = (void *)(base + 0x5b4);
    items[0].callback = cb4;
    items[0].id = 0x1;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[1].name = (void *)(base + 0x5c8);
    items[1].callback = (void *)fn_801C6D00;
    items[1].id = 0x2;
    items[1].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[2].name = (void *)(base + 0x5dc);
    items[2].callback = cb0;
    items[2].id = 0x3;
    items[2].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[3].name = (void *)(base + 0x5ec);
    items[3].callback = cb0;
    items[3].id = 0x4;
    items[3].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[4].name = (void *)(base + 0x5fc);
    items[4].callback = cb0;
    items[4].id = 0x5;
    items[4].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[5].name = (void *)(base + 0x610);
    items[5].callback = cb0;
    items[5].id = 0x6;
    items[5].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[6].name = (void *)(base + 0x624);
    items[6].callback = cb0;
    items[6].id = 0x7;
    items[6].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[7].name = (void *)(base + 0x634);
    items[7].callback = (void *)fn_801C737C;
    items[7].id = 0xb;
    items[7].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[8].name = (void *)(base + 0x644);
    items[8].callback = cb4;
    items[8].id = 0xc;
    items[8].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[9].name = (void *)(base + 0x654);
    items[9].callback = cb0;
    items[9].id = 0x8;
    items[9].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x0);
    items[10].name = (void *)(base + 0x668);
    items[10].callback = cb0;
    items[10].id = 0x9;
    items[10].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x94))[0] = (void *)(base + 0x680);
    *(s32 *)((char *)root + 0x98) = 0x3;
    items = (struct Entry *)fn_8012850C(0x30, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x90) = items;
    items[0].name = (void *)&lbl_8055AA7C;
    items[0].callback = cb4;
    items[0].id = 0xa;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x90);
    items[1].name = (void *)(base + 0x694);
    items[1].callback = (void *)fn_801C84E0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x90);
    items[2].name = (void *)&lbl_8055AA80;
    items[2].callback = cb0;
    items[2].id = 0x0;
    items[2].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0xa4))[0] = (void *)(base + 0x6a0);
    *(s32 *)((char *)root + 0xa8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0xa0) = items;
    items[0].name = (void *)&lbl_8055AA7C;
    items[0].callback = (void *)fn_801C8500;
    items[0].id = 0x0;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xa0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7374;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x84))[0] = (void *)(base + 0x6b0);
    *(s32 *)((char *)root + 0x88) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x80) = items;
    items[0].name = (void *)&lbl_8055AA88;
    items[0].callback = cb0;
    items[0].id = 0x0;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x80);
    items[1].name = (void *)(base + 0x6c0);
    items[1].callback = (void *)fn_801C8420;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0xc4))[0] = (void *)(base + 0x6cc);
    *(s32 *)((char *)root + 0xc8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0xc0) = items;
    items[0].name = (void *)(base + 0x6dc);
    items[0].callback = (void *)fn_801C83D0;
    items[0].id = 0x0;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xc0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7374;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x14))[0] = (void *)(base + 0x6ec);
    *(s32 *)((char *)root + 0x18) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x10) = items;
    items[0].name = (void *)(base + 0x704);
    items[0].callback = (void *)fn_801C72F0;
    items[0].id = 0x0;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x10);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7374;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x34))[0] = (void *)&lbl_8055AA90;
    *(s32 *)((char *)root + 0x38) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x30) = items;
    items[0].name = (void *)(base + 0x710);
    items[0].callback = (void *)fn_801C7290;
    items[0].id = 0x0;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x30);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = cb0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x24))[0] = (void *)(base + 0x71c);
    *(s32 *)((char *)root + 0x28) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x20) = items;
    items[0].name = (void *)(base + 0x730);
    items[0].callback = (void *)fn_801C6D94;
    items[0].id = 0x20;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x20);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7288;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x204))[0] = (void *)(base + 0x750);
    *(s32 *)((char *)root + 0x208) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x200) = items;
    items[0].name = (void *)(base + 0x768);
    items[0].callback = (void *)fn_801C6E40;
    items[0].id = 0x0;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x200);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7288;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x44))[0] = (void *)(base + 0x774);
    *(s32 *)((char *)root + 0x48) = 0x7;
    items = (struct Entry *)fn_8012850C(0x70, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x40) = items;
    items[0].name = (void *)&lbl_8055AA98;
    items[0].callback = (void *)fn_801C7798;
    items[0].id = 0x4;
    items[0].flags = (s32)&lbl_8055E840;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x40);
    items[1].name = (void *)&lbl_8055AAA0;
    items[1].callback = (void *)fn_801C77AC;
    items[1].id = 0x4;
    items[1].flags = (s32)&lbl_8055E841;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x40);
    items[2].name = (void *)&lbl_8055AAA8;
    items[2].callback = (void *)fn_801C7770;
    items[2].id = 0x4;
    items[2].flags = (s32)&lbl_8055E83E;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x40);
    items[3].name = (void *)(base + 0x784);
    items[3].callback = (void *)fn_801C7784;
    items[3].id = 0x4;
    items[3].flags = (s32)&lbl_8055E83F;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x40);
    items[4].name = (void *)(base + 0x790);
    items[4].callback = cb4;
    items[4].id = 0x1f;
    items[4].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x40);
    items[5].name = (void *)(base + 0x7a0);
    items[5].callback = (void *)fn_801C77FC;
    items[5].id = 0x0;
    items[5].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x40);
    items[6].name = (void *)&lbl_8055AA80;
    items[6].callback = cb0;
    items[6].id = 0x0;
    items[6].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x1f4))[0] = (void *)(base + 0x7ac);
    *(s32 *)((char *)root + 0x1f8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x1f0) = items;
    items[0].name = (void *)(base + 0x7bc);
    items[0].callback = (void *)fn_801C77C0;
    items[0].id = 0x4;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x1f0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7374;
    items[1].id = 0x4;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x54))[0] = (void *)(base + 0x7c8);
    *(s32 *)((char *)root + 0x58) = 0x3;
    items = (struct Entry *)fn_8012850C(0x30, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x50) = items;
    items[0].name = (void *)(base + 0x7d8);
    items[0].callback = (void *)fn_801C791C;
    items[0].id = 0xd;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x50);
    items[1].name = (void *)(base + 0x7ec);
    items[1].callback = (void *)fn_801C7944;
    items[1].id = 0x10;
    items[1].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x50);
    items[2].name = (void *)&lbl_8055AA80;
    items[2].callback = (void *)fn_801C7BA0;
    items[2].id = 0x0;
    items[2].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0xd4))[0] = (void *)&lbl_8055AAB0;
    *(s32 *)((char *)root + 0xd8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0xd0) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C7A6C;
    items[0].id = 0xe;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xd0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0xe4))[0] = (void *)(base + 0x804);
    *(s32 *)((char *)root + 0xe8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0xe0) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C7AC4;
    items[0].id = 0xf;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xe0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0xf4))[0] = (void *)(base + 0x814);
    *(s32 *)((char *)root + 0xf8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0xf0) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C7B28;
    items[0].id = 0x13;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xf0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x104))[0] = (void *)(base + 0x820);
    *(s32 *)((char *)root + 0x108) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x100) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C7990;
    items[0].id = 0x11;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x100);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x114))[0] = (void *)(base + 0x830);
    *(s32 *)((char *)root + 0x118) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x110) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C79E0;
    items[0].id = 0x12;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x110);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x124))[0] = (void *)(base + 0x840);
    *(s32 *)((char *)root + 0x128) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x120) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C7A28;
    items[0].id = 0xe;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x120);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x134))[0] = (void *)(base + 0x854);
    *(s32 *)((char *)root + 0x138) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x130) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C7C04;
    items[0].id = 0x0;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x130);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x64))[0] = (void *)(base + 0x860);
    *(s32 *)((char *)root + 0x68) = 0x6;
    items = (struct Entry *)fn_8012850C(0x60, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x60) = items;
    items[0].name = (void *)(base + 0x86c);
    items[0].callback = (void *)fn_801C80C8;
    items[0].id = 0x17;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x60);
    items[1].name = (void *)&lbl_8055AAB8;
    items[1].callback = (void *)fn_801C80BC;
    items[1].id = 0x18;
    items[1].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x60);
    items[2].name = (void *)(base + 0x87c);
    items[2].callback = (void *)fn_801C8190;
    items[2].id = 0x18;
    items[2].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x60);
    items[3].name = (void *)&lbl_8055AAC0;
    items[3].callback = (void *)fn_801C80E8;
    items[3].id = 0x1b;
    items[3].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x60);
    items[4].name = (void *)(base + 0x888);
    items[4].callback = (void *)fn_801C811C;
    items[4].id = 0x1b;
    items[4].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x60);
    items[5].name = (void *)&lbl_8055AA80;
    items[5].callback = cb0;
    items[5].id = 0x0;
    items[5].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x174))[0] = (void *)(base + 0x89c);
    *(s32 *)((char *)root + 0x178) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x170) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C819C;
    items[0].id = 0x18;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x170);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C8298;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x1b4))[0] = (void *)(base + 0x8a8);
    *(s32 *)((char *)root + 0x1b8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x1b0) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C8150;
    items[0].id = 0x18;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x1b0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C8298;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x184))[0] = (void *)&lbl_8055AAC8;
    *(s32 *)((char *)root + 0x188) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x180) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C81B8;
    items[0].id = 0x19;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x180);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C8298;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x194))[0] = (void *)&lbl_8055AAD0;
    *(s32 *)((char *)root + 0x198) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x190) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C821C;
    items[0].id = 0x1a;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x190);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C8298;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x1a4))[0] = (void *)&lbl_8055AAD8;
    *(s32 *)((char *)root + 0x1a8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x1a0) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C82E0;
    items[0].id = 0x0;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x1a0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C8298;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x74))[0] = (void *)(base + 0x8b4);
    *(s32 *)((char *)root + 0x78) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x70) = items;
    items[0].name = (void *)(base + 0x8c0);
    items[0].callback = (void *)fn_801C7EF4;
    items[0].id = 0x14;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x70);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = cb0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x144))[0] = (void *)(base + 0x8cc);
    *(s32 *)((char *)root + 0x148) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x140) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C7F00;
    items[0].id = 0x15;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x140);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x154))[0] = (void *)(base + 0x8dc);
    *(s32 *)((char *)root + 0x158) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x150) = items;
    items[0].name = (void *)(base + 0x7f8);
    items[0].callback = (void *)fn_801C7F64;
    items[0].id = 0x16;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x150);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x164))[0] = (void *)(base + 0x8f0);
    *(s32 *)((char *)root + 0x168) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x160) = items;
    items[0].name = (void *)(base + 0x8fc);
    items[0].callback = (void *)fn_801C7FE4;
    items[0].id = 0x0;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x160);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7BA0;
    items[1].id = 0x0;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0xb4))[0] = (void *)(base + 0x90c);
    *(s32 *)((char *)root + 0xb8) = 0x6;
    items = (struct Entry *)fn_8012850C(0x60, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0xb0) = items;
    items[0].name = (void *)&lbl_8055AAE0;
    items[0].callback = (void *)fn_801C73DC;
    items[0].id = 0xb;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xb0);
    items[1].name = (void *)(base + 0x918);
    items[1].callback = (void *)fn_801C7480;
    items[1].id = 0xb;
    items[1].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xb0);
    items[2].name = (void *)(base + 0x924);
    items[2].callback = (void *)fn_801C7524;
    items[2].id = 0x1d;
    items[2].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xb0);
    items[3].name = (void *)(base + 0x930);
    items[3].callback = cb4;
    items[3].id = 0x1e;
    items[3].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xb0);
    items[4].name = (void *)&lbl_8055AAE8;
    items[4].callback = cb0;
    items[4].id = 0x1c;
    items[4].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0xb0);
    items[5].name = (void *)&lbl_8055AA80;
    items[5].callback = (void *)fn_801C7388;
    items[5].id = 0x0;
    items[5].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x1c4))[0] = (void *)(base + 0x940);
    *(s32 *)((char *)root + 0x1c8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x1c0) = items;
    items[0].name = (void *)&lbl_8055AA80;
    items[0].callback = cb0;
    items[0].id = 0xb;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x1c0);
    items[1].name = (void *)&lbl_8055AAE8;
    items[1].callback = (void *)fn_801C7394;
    items[1].id = 0xb;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x1d4))[0] = (void *)(base + 0x950);
    *(s32 *)((char *)root + 0x1d8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x1d0) = items;
    items[0].name = (void *)(base + 0x95c);
    items[0].callback = (void *)fn_801C756C;
    items[0].id = 0xb;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x1d0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7374;
    items[1].id = 0xb;
    items[1].flags = 0x0;
    root = lbl_8055E86C;
    ((void **)((char *)root + 0x1e4))[0] = (void *)(base + 0x950);
    *(s32 *)((char *)root + 0x1e8) = 0x2;
    items = (struct Entry *)fn_8012850C(0x20, &lbl_8055AA78);
    *(struct Entry **)((char *)root + 0x1e0) = items;
    items[0].name = (void *)(base + 0x968);
    items[0].callback = (void *)fn_801C7698;
    items[0].id = 0xb;
    items[0].flags = 0x0;
    items = (struct Entry *)*(volatile struct Entry **)((char *)root + 0x1e0);
    items[1].name = (void *)&lbl_8055AA80;
    items[1].callback = (void *)fn_801C7374;
    items[1].id = 0xb;
    items[1].flags = 0x0;
    lbl_8055E81C = 0;
    lbl_8055E820 = 0;
}

void fn_801C9444(void) {
    s32 zero = 0;
    s32 off = 0;
    s32 i = 0;
    u8 *base;
    do {
        base = lbl_8055E86C;
        fn_80128670(*(s32 *)(base + off));
        base = lbl_8055E86C;
        i++;
        *(s32 *)(base + off) = zero;
        off += 0x10;
    } while (i < 0x21);
    fn_80128670((s32)lbl_8055E86C);
    lbl_8055E86C = 0;
}

#pragma scheduling invalid_target
void fn_801C94B8(void) {
    fn_80238A74();
}

void fn_801C94BC(void) {
    fn_80238B44();
}

void fn_801C94C0(s32 arg0, s32 arg1) {
    fn_8023895C();
    ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg0, arg1, (char *)((u32)lbl_80437FC0 | 0), -1);
    fn_802389E4();
}

extern void fn_801769EC(void);
extern void fn_80176610(void);
extern void __AXDSPInitCallback_801769E0(void);
#pragma push
#pragma processor 750
void fn_801C9514(void) {
    f32 end;
    f32 start;
    start = lbl_8055E3C8;
    fn_801769EC();
    end = lbl_805629AC + start;
    while (lbl_8055E3C8 < end && lbl_8055E3C8 >= start) {
        fn_80176610();
    }
    __AXDSPInitCallback_801769E0();
}

int fn_801C957C(arg0)
int arg0;
{
    u8 *table;
    if (arg0 != 0) {
        strcpy(lbl_804380F0, lbl_8055AA44);
        table = (u8*)lbl_80337474;
        table[lbl_8055E824] = 0x1E;
    } else {
        table = (u8*)lbl_80337474;
        table[lbl_8055E824] = 0xFF;
    }
    lbl_8055E838 = arg0;
    return (int)table;
}

#pragma pop
void fn_801C95EC(f32 arg0) {
    struct Entry {
        void *name;
        void (*callback)(void *);
        s32 id;
        s32 flags;
    };
    struct L1 { struct Entry *e; s32 f4; s32 f8; s32 fC; };
    struct Entry *entry;
    s32 id;
    s32 prev;
    strcpy(lbl_80437FC0, lbl_8055AA44);
    entry = &((struct L1 *)lbl_8055E86C)[lbl_8055E81C].e[lbl_8055E820];
    entry->callback(entry);
    entry = &((struct L1 *)lbl_8055E86C)[lbl_8055E81C].e[lbl_8055E820];
    id = entry->id;
    if (id == 0x22) {
        lbl_8055E81C = lbl_8055E870;
    } else {
        prev = lbl_8055E81C;
        lbl_8055E870 = prev;
        lbl_8055E81C = id;
        if (prev != id) {
            lbl_8055E820 = 0;
        }
    }
}

void fn_801C968C(s32 delta) {
    s32 updated = lbl_8055E820 + delta;
    lbl_8055E820 = updated;
    if (updated < 0) {
        lbl_8055E820 = *(s32 *)((u8 *)lbl_8055E86C + lbl_8055E81C * 0x10 + 8) - 1;
        return;
    }
    if (updated >= *(s32 *)((u8 *)lbl_8055E86C + lbl_8055E81C * 0x10 + 8)) {
        lbl_8055E820 = 0;
    }
}

void fn_801C96E4(void) {
    lbl_8055E82C = lbl_8055E828 / 10;
}

#pragma scheduling invalid_target
s32 fn_801C9708(s32 arg0) {
    switch (arg0) {
    case 0xD:
        ((void (*)(void))fn_801C95EC)();
        break;
    case 0x126:
        fn_801C968C(-1);
        break;
    case 0x128:
        fn_801C968C(1);
        break;
    case 0x8:
    case 0x12E:
        if (strlen(lbl_804380F0) != 0) {
            *(char*)((u32)lbl_804380F0 + strlen(lbl_804380F0) - 1) = 0;
        }
        break;
    default:
        if ((arg0 >= 0x41 && arg0 <= 0x7A) ||
            (arg0 >= 0x30 && arg0 <= 0x39) ||
            arg0 == 0x3A || arg0 == 0x2E ||
            arg0 == 0x20 || arg0 == 0x2D) {
            u32 length = strlen(lbl_804380F0);
            if (length < 0xFF) {
                lbl_804380F0[length] = (char)arg0;
                *(length + lbl_804380F0 + 1) = 0;
            }
        }
        break;
    }
    return 1;
}
#pragma scheduling on
void fn_801C9830(void) {
    return;
}

extern void fn_801C855C(void);
/* Initializes/reloads state, finds the first 0xFF terminator in the byte table to set the active count, and clears the selection index. */
void fn_801C9834(void) {
    u8 *tablePtr;
    s32 tempIndex1;
    s32 tempIndex2;
    s32 tempIndex3;
    s32 tempIndex4;
    s32 scanCount;
    s32 index;

    fn_801C855C();
    tablePtr = (u8 *)lbl_80337474;
    index = 0;
    for (scanCount = 0; scanCount < 11; scanCount++) {
        if (tablePtr[0] == 0xFF) {
            lbl_8055E824 = index;
            break;
        } else {
            tempIndex1 = index + 1;
            if (tablePtr[1] == 0xFF) {
                lbl_8055E824 = tempIndex1;
                break;
            } else {
                tempIndex2 = tempIndex1 + 1;
                if (tablePtr[2] == 0xFF) {
                    lbl_8055E824 = tempIndex2;
                    break;
                } else {
                    tempIndex3 = tempIndex2 + 1;
                    if (tablePtr[3] == 0xFF) {
                        lbl_8055E824 = tempIndex3;
                        break;
                    } else {
                        tempIndex4 = tempIndex3 + 1;
                        if (tablePtr[4] == 0xFF) {
                            lbl_8055E824 = tempIndex4;
                            break;
                        } else {
                            tablePtr += 5;
                            index = tempIndex4 + 1;
                        }
                    }
                }
            }
        }
    }
    lbl_8055E838 = 0;
}
#pragma scheduling on
void fn_801C98F0(void) {
    fn_801C9444();
}

#pragma scheduling on
char *fn_801C98F4(char *p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        while (*p != 0) p++;
        p++;
    }
    return p;
}

#pragma push
#pragma processor 750
s32 fn_801C9920(s32 arg0, s32 arg1) {
    s32 handle = arg1;
    char *record = (char *)arg0;
    char *base = lbl_80336B00;
    f32 vec[3];
    f32 quat[4];
    fn_802E3AD0(handle, base + 0x9b0);
    fn_802E3AD0(handle, base + 0x9c0, *(f32 *)record);
    switch (*(u32 *)(record + 8)) {
    case 0:
        fn_802E3AD0(handle, base + 0x9cc);
        fn_802E3AD0(handle, base + 0x9dc, record + 0xC);
        break;
    case 1: {
        f32 trace;
        f32 root;
        s32 i;
        s32 j;
        s32 k;
        f32 angle;
        f32 sv;
        f32 scale;
        f32 *rot;
        fn_802E3AD0(handle, base + 0x9e8);
        fn_802E3AD0(handle, base + 0x9f8, ((f32 (*)(f32))fn_801C34F4)(*(f32 *)(record + 0x54)));
        fn_802E3AD0(handle, base + 0xa08, *(f32 *)(record + 0xC), *(f32 *)(record + 0x10), *(f32 *)(record + 0x14));
        rot = (f32 *)(record + 0x18);
        trace = rot[0] + rot[4] + rot[8];
        if (trace > lbl_80562970) {
            root = (f32)fn_8002F234(lbl_8056296C + trace);
            quat[3] = lbl_80562974 * root;
            root = lbl_80562974 / root;
            quat[0] = root * (rot[5] - rot[7]);
            quat[1] = root * (rot[6] - rot[2]);
            quat[2] = root * (rot[1] - rot[3]);
        } else {
            i = 0;
            if (rot[4] > rot[0]) i = 1;
            if (rot[8] > rot[i * 3 + i]) i = 2;
            j = (i + 1) % 3;
            k = (j + 1) % 3;
            root = (f32)fn_8002F234(lbl_8056296C + rot[i * 3 + i] - (rot[j * 3 + k] + rot[k * 3 + j]));
            quat[i] = lbl_80562974 * root;
            root = lbl_80562974 / root;
            quat[3] = root * (rot[j * 3 + k] - rot[k * 3 + j]);
            quat[j] = root * (rot[i * 3 + j] + rot[j * 3 + i]);
            quat[k] = root * (rot[i * 3 + k] + rot[k * 3 + i]);
        }
        angle = (f32)fn_8002EFA8(quat[3]);
        sv = sin(angle);
        if ((f32)__fabs((f64)sv) > lbl_80558DC4[0]) {
            scale = (lbl_805629BC * angle) / sv;
            vec[0] = quat[0] * scale;
            vec[1] = quat[1] * scale;
            vec[2] = quat[2] * scale;
        } else {
            vec[0] = lbl_80562970;
            vec[1] = lbl_80562970;
            vec[2] = lbl_80562970;
        }
        fn_802E3AD0(handle, base + 0xa24, vec[0], vec[1], vec[2]);
        fn_802E3AD0(handle, base + 0xa40, *(f32 *)(record + 0x3C), *(f32 *)(record + 0x40), *(f32 *)(record + 0x44));
        fn_802E3AD0(handle, base + 0xa58, *(f32 *)(record + 0x48), *(f32 *)(record + 0x4C), *(f32 *)(record + 0x50));
        fn_802E3AD0(handle, base + 0xa70, *(f32 *)(record + 0x58) - *(f32 *)record);
        fn_802E3AD0(handle, base + 0xa84, *(u8 *)(record + 0x5C) ? lbl_8055AAF0 : lbl_8055AAF4);
        break;
    }
    case 2:
        fn_802E3AD0(handle, base + 0xa98);
        break;
    case 3:
        fn_802E3AD0(handle, base + 0xaa8);
        fn_802E3AD0(handle, base + 0xab8, fn_801C98F4((char *)lbl_80562960, *(s32 *)(record + 0x10)));
        fn_802E3AD0(handle, base + 0xacc, *(u8 *)(record + 0x14) ? lbl_8055AAF0 : lbl_8055AAF4);
        fn_802E3AD0(handle, base + 0xadc, *(u8 *)(record + 0x15) ? lbl_8055AAF0 : lbl_8055AAF4);
        fn_802E3AD0(handle, base + 0xaf0, *(s32 *)(record + 0xC));
        break;
    case 4:
        fn_802E3AD0(handle, base + 0xb00);
        fn_802E3AD0(handle, base + 0xb14, *(f32 *)(record + 0x214));
        fn_802E3AD0(handle, base + 0xb24, record + 0x10);
        fn_802E3AD0(handle, base + 0xb30, record + 0x110);
        fn_802E3AD0(handle, base + 0xb40, fn_801C98F4((char *)lbl_80562954, *(s32 *)(record + 0x210)));
        switch (*(s32 *)(record + 0x210)) {
        case 1:
            fn_802E3AD0(handle, base + 0xb50, *(f32 *)(record + 0x218));
            fn_802E3AD0(handle, base + 0xb60, *(f32 *)(record + 0x21C));
            fn_802E3AD0(handle, base + 0xb74, *(f32 *)(record + 0x220));
            break;
        case 0:
            fn_802E3AD0(handle, base + 0xb84, *(f32 *)(record + 0x218), *(f32 *)(record + 0x21C));
            fn_802E3AD0(handle, base + 0xb74, *(f32 *)(record + 0x220));
            fn_802E3AD0(handle, base + 0xb98, *(f32 *)(record + 0x224), *(f32 *)(record + 0x228));
            break;
        case 2:
            fn_802E3AD0(handle, base + 0xb74, *(f32 *)(record + 0x220));
            fn_802E3AD0(handle, base + 0xb98, *(f32 *)(record + 0x218), *(f32 *)(record + 0x21C));
            break;
        default:
            fn_802E317C(base + 0xbb0);
            break;
        }
        break;
    case 5:
        fn_802E3AD0(handle, base + 0xbe8);
        fn_802E3AD0(handle, base + 0xb24, record + 0x10);
        fn_802E3AD0(handle, base + 0xb30, record + 0x110);
        fn_802E3AD0(handle, base + 0xbf8, fn_801C98F4((char *)lbl_80562958, *(s32 *)(record + 0x210)));
        fn_802E3AD0(handle, base + 0xb14, *(f32 *)(record + 0x218));
        fn_802E3AD0(handle, base + 0xc04, *(f32 *)(record + 0x21C));
        fn_802E3AD0(handle, base + 0xc14, *(f32 *)(record + 0x220));
        fn_802E3AD0(handle, base + 0xc24, *(s32 *)(record + 0x214));
        if (*(s32 *)(record + 0x210) == 2)
            fn_802E3AD0(handle, base + 0xb84, *(f32 *)(record + 0x21C), *(f32 *)(record + 0x220));
        break;
    case 6:
        fn_802E3AD0(handle, base + 0xc34);
        fn_802E3AD0(handle, base + 0xc44, fn_801C98F4((char *)lbl_8056295C, *(s32 *)(record + 0xC)));
        fn_802E3AD0(handle, base + 0xb24, record + 0x14);
        fn_802E3AD0(handle, base + 0xb30, record + 0x114);
        if (*(s32 *)(record + 0xC) == 0)
            fn_802E3AD0(handle, base + 0xc50, *(f32 *)(record + 0x214), *(f32 *)(record + 0x218), *(f32 *)(record + 0x21C));
        else
            fn_802E317C(base + 0xc68);
        break;
    case 7:
        fn_802E3AD0(handle, base + 0xc94);
        fn_802E3AD0(handle, base + 0x9dc, record + 0x10C);
        fn_802E3AD0(handle, base + 0xca4, record + 0xC);
        break;
    default:
        fn_802E317C(base + 0xcb4);
        fn_802E3AD0(handle, lbl_8055AAF8);
        break;
    }
}
#pragma pop
/* fn_801CA070 writes the debug interlude timeline out as a text "table" file.
 * The strings it prints live in the format pool at lbl_80336B00, so they are
 * named here by their offset into that pool. */
enum {
    OFF_INTERLUDE_VAR_NAME = 0x130, /* "interlude_name": variable holding the table name */
    OFF_TABLE_HEADER       = 0xD04, /* "table %s\r\n" */
    OFF_TABLE_DURATION     = 0xD10, /* "\tduration\t%.2f\r\n" */
    OFF_TABLE_FOOTER       = 0xD24, /* "end\r\nend\r\n" */
    OFF_TABLE_SAVED        = 0xD30, /* "Saved interlude to %s" */
    OFF_TABLE_SAVE_FAILED  = 0xD48  /* "Error: couldn't save interlude to %s!" */
};
#define sInterludeTableName  lbl_8055E814 /* name to save under; 0 = ask the scene's variable table */
#define sInterludeDuration   lbl_8055A958 /* interlude duration, set from the console */
#define console_message      lbl_80437FC0 /* console line the result is reported on */
#define file_create          fn_802E367C  /* name -> write handle, -1 on failure */
#define file_printf          fn_802E3AD0  /* handle, printf-style format, ... */
#define file_close           fn_802E3734  /* &handle */
#define timeline_write_entry fn_801C9920  /* entry, handle: one entry as text */
extern char lbl_80336B00[];
extern s32 lbl_8055E814;
extern s32 fn_802E367C(const char *);
extern s32 fn_801C9920(s32, s32);
extern const char *fn_80007F90(u32);
extern void fn_802E3734(s32 *);
extern void fn_802E3AD0(s32, const char *, ...);
#pragma scheduling invalid_target
#pragma cplusplus on
/* Save the debug interlude timeline to fileName as a text "table" file: a
 * "table <name>" header, the duration, one block per timeline entry and the
 * "end"/"end" footer; then report on the console whether it was written. */
extern "C" void fn_801CA070(char *fileName) {
 /* Named-variable table of the current scene: slot 0xC looks a name up and
  * slot 0x14 returns that variable's value as a string. */
 struct DebugVarTable {
  virtual void v0();
  virtual s32 find(char *name);
  virtual void v2();
  virtual char *valueOf(char *name);
 };
 char *base=lbl_80336B00;
 s32 handle;
 s32 offset, i;
 s32 tableName;
 DebugVarTable *table;
 DebugVarTable *table2;
 s32 foundName;
 handle=file_create(fileName);
 if(handle!=-1) {
  tableName=sInterludeTableName;
  switch(tableName) {
  case 0:
   table=(DebugVarTable*)fn_801C3D5C();
   if(table->find(base+OFF_INTERLUDE_VAR_NAME)!=0) {
    table2=(DebugVarTable*)fn_801C3D5C();
    foundName=(s32)table2->valueOf(base+OFF_INTERLUDE_VAR_NAME);
   } else foundName=(s32)fn_80007F90(__AXFXGetLfoSinTable_801769CC()[1]);
   tableName=foundName;
   break;
  default:
   goto common;
  }
 common:
  file_printf(handle,base+OFF_TABLE_HEADER,tableName);
  file_printf(handle,base+OFF_TABLE_DURATION,sInterludeDuration);
  for(i=0,offset=0;i<sTimelineCount;offset+=0x30C,i++)
   timeline_write_entry(sTimelineEntries+offset,handle);
  file_printf(handle,base+OFF_TABLE_FOOTER);
  file_close(&handle);
  sprintf(console_message,base+OFF_TABLE_SAVED,fileName);
 } else sprintf(console_message,base+OFF_TABLE_SAVE_FAILED,fileName);
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801CA1C4(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char buf[256];
    char *base = lbl_80336B00;
    u8 *record = (u8 *)arg0;
    if (lbl_8055E7F0 == 0 || lbl_8055E828 >= lbl_8055E7F0)
        return;
    switch (*(u32 *)(record + 8)) {
    case 0:
        sprintf(buf, lbl_8055AB00, record + 0xC);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        break;
    case 2:
        sprintf(buf, base + 0xD70);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        break;
    case 3:
        sprintf(buf, base + 0xD84, fn_801C98F4((char *)lbl_80562960, *(s32 *)(record + 0x10)));
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        break;
    case 4:
        sprintf(buf, base + 0xD94, fn_801C98F4((char *)lbl_80562954, *(s32 *)(record + 0x210)));
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        arg2 += arg3;
        sprintf(buf, lbl_8055AB08, record + 0x10);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        arg2 += arg3;
        sprintf(buf, base + 0xDA8, record + 0x110);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        arg2 += arg3;
        sprintf(buf, base + 0xDB4, *(f32 *)(record + 0x214) / lbl_805629D4);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        break;
    case 5:
        sprintf(buf, base + 0xDC0, fn_801C98F4((char *)lbl_80562958, *(s32 *)(record + 0x210)));
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        arg2 += arg3;
        sprintf(buf, lbl_8055AB08, record + 0x10);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        arg2 += arg3;
        sprintf(buf, base + 0xDA8, record + 0x110);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        arg2 += arg3;
        sprintf(buf, base + 0xDB4, *(f32 *)(record + 0x218) / lbl_805629D4);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        break;
    case 6:
        sprintf(buf, base + 0xDD0, fn_801C98F4((char *)lbl_8056295C, *(s32 *)(record + 0xC)));
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        arg2 += arg3;
        sprintf(buf, lbl_8055AB08, record + 0x14);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        arg2 += arg3;
        sprintf(buf, base + 0xDA8, record + 0x114);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        break;
    case 7: {
        char text[50] = {0};
        strncpy(text, (char *)record + 0xC, 0x31);
        sprintf(buf, base + 0xDE0, text);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        arg2 += arg3;
        strncpy(text, (char *)record + 0x10C, 0x31);
        sprintf(buf, base + 0xDEC, text);
        ((void (*)(s32, s32, char *, s32))fn_801C94B8)(arg1, arg2, buf, -1);
        break;
    }
    default:
        fn_802E317C(base + 0xDF8);
        break;
    }
}
#pragma cplusplus reset
#pragma pop

#pragma cplusplus reset

extern void fn_801CA1C4(void *, s32, s32, s32);
extern char lbl_80337944[];
extern s32 lbl_8055AB10;
extern s32 lbl_80562950;
extern int fn_80238A20(void);
#pragma scheduling invalid_target
/* Details panel of the debug overlay for the timeline entry the player has
 * selected (sTimelineSelection).  With the timeline non-empty it prints the
 * entry's event-type name ("type: %s"; the name is the entry->type-th string of
 * the sTimelineTypeNames blob) at x=400, y=180, then its time ("t: %.2f") one
 * line advance below, and finally hands the entry to draw_entry_details to
 * print the fields that go with its type under both lines. */
void fn_801CA5A8(void) {
    if (sTimelineCount != 0) {
        typedef struct TimelineEntry {
            f32 time; /* +0x0: sort key of the entry */
            s32 rank; /* +0x4: order among entries sharing the time */
            s32 type; /* +0x8: event kind, indexes sTimelineTypeNames */
        } TimelineEntry; /* one 0x30C-byte entry of sTimelineEntries */
        char buffer[0x100];
        s32 lineHeight;
        s32 index;
        s32 y;
        f32 entryTime;
        TimelineEntry *record;
        lineHeight = text_line_height();
        index = sTimelineSelection;
        record = (TimelineEntry *)((char *)(s32)sTimelineEntries + index * 0x30C);
        sprintf(buffer, STR_TIMELINE_TYPE,
                ((char *(*)(u8 *, s32))nth_string)((u8 *)(s32)sTimelineTypeNames, record->type));
        ((void (*)(s32, s32, char *, s32))debug_draw_text)(0x190, 0xB4, buffer, -1);
        entryTime = record->time;
        y = lineHeight + 0xB4;
        sprintf(buffer, (char *)&STR_TIMELINE_TIME, entryTime);
        ((void (*)(s32, s32, char *, s32))debug_draw_text)(0x190, y, buffer, -1);
        draw_entry_details((char *)(s32)sTimelineEntries + sTimelineSelection * 0x30C, 0x190,
                           y + lineHeight, lineHeight);
    }
}
#pragma scheduling on
extern char lbl_8055E7E0;
extern char lbl_8055E7E1;
extern char lbl_8055E80C;
extern char lbl_8033701C[]; /* "intrlude.txt" */
s32 fn_801C9708();
s32 fn_80176780(s32, s32);
void fn_801C9514(void);

/* State of the debug interlude overlay that the key handler below drives; the
 * overlay itself is fn_801CA67C and its help text the "%c - ..." strings of the
 * lbl_80336B00 pool from +0xE50 ("Un/Pause", "Restart", "Change Cam",
 * "+0.1 Secs", "Save", "Hide", "[ and ] Scroll"). */
#define sTextInputActive  lbl_8055E838 /* a console text field is being typed into */
#define sOverlayHidden    lbl_8055E7E0 /* 'h': overlay shows only "HIDDEN ('H')" */
#define sRestartRequested lbl_8055E7E1 /* 'r': interlude restart was asked for */
#define sFreeCamera       lbl_8055E80C /* 'c': interlude stops driving the camera */
#define sEntryListShown   lbl_8055E839 /* the timeline entry list panel is up */
#define INTERLUDE_FILE    lbl_8033701C /* 'l' saves the timeline here */
#define KEY_CURSOR_LEFT   0x126        /* debug keyboard cursor messages */
#define KEY_CURSOR_RIGHT  0x128
#define console_text_key  fn_801C9708  /* edits the console line lbl_804380F0 */
#define physics_switch    fn_80176780  /* new mode + PHYS_FLAG_* bits, extra byte */
#define save_interlude    fn_801CA070  /* writes the timeline table to a file */
#define fast_forward_time fn_801C9514  /* ticks the game on by 0.1 s */
#define menu_move         fn_801C968C  /* steps the menu item selection, wrapping */
#define timeline_page     fn_801C96E4  /* entry list page = selection / 10 */
#define menu_activate     fn_801C95EC  /* runs the selected menu entry */
/* Key handler of the debug interlude overlay.  `key` is a debug keyboard code: a
 * typed character, or one of the cursor/Enter messages above 0x100.  While a
 * console text field is being typed into the key goes to the line editor
 * instead; 'h' hides the overlay, which then swallows every other key.  Of the
 * rest 'c' stops the interlude driving the camera, 'r' restarts it (physics mode
 * none), 'l' saves the recorded timeline to "intrlude.txt", 'i' fast-forwards
 * 0.1 s, the cursor keys step the menu selection, '[' and ']' scroll the
 * selected timeline entry while its list is shown, and Enter runs the selected
 * menu entry.  Returns the line editor's result, or 0. */
s32 fn_801CB114(s32 key) {
    if ((u8)sTextInputActive != 0) return console_text_key(key);
    if (key == 'h') sOverlayHidden = (u8)sOverlayHidden == 0;
    if ((u8)sOverlayHidden != 0) return 0;
    switch (key) {
    case 'c': sFreeCamera = (u8)sFreeCamera == 0; break;
    case 'r': physics_switch(0x4200, 0); sRestartRequested = 1; break;
    case 'l': save_interlude(INTERLUDE_FILE); break;
    case 'i': fast_forward_time(); break;
    case KEY_CURSOR_LEFT: menu_move(-1); break;
    case KEY_CURSOR_RIGHT: menu_move(1); break;
    case '[':
        if ((u8)sEntryListShown != 0) {
            if (sTimelineSelection > 0) sTimelineSelection -= 1;
            timeline_page();
        } break;
    case ']':
        if ((u8)sEntryListShown != 0) {
            if (sTimelineSelection < sTimelineCount - 1) sTimelineSelection += 1;
            timeline_page();
        } break;
    case '\r': ((void (*)(void))menu_activate)(); break;
    }
    return 0;
}


extern void fn_8000FC8C(const char*);
extern void fn_8000FDF0(const char*);
extern f32 fn_801C3B6C(void);

extern void *fn_801C3C80(void);
extern void qsort(void *base, size_t count, size_t size, int (*compare)(const void *, const void *));
extern s32 fn_801C3B7C(const void *, const void *);
extern char lbl_80437FC0[304];
extern char lbl_80336EC8[];
extern s32 lbl_8055E7F0;
extern s32 lbl_8055E7F8;
#pragma push
#pragma scheduling reset
void fn_801C6B70(void) {
    const char *name1;
    const char *name0;

    /* If the pending timer at lbl_80437E24[2] is active, either reset it when out of window relative to lbl_8055E3C8, or trigger actions for the two stored string names. */
    if (*(f32 *)&lbl_80437E24[2] >= lbl_80562970) {
        if ((lbl_8055E3C8 < *(f32 *)&lbl_80437E24[2]) || ((lbl_8055E3C8 - *(f32 *)&lbl_80437E24[2]) > lbl_80562978)) {
            *(f32 *)&lbl_80437E24[2] = lbl_80562994;
            lbl_80437E24[0] = 0;
            lbl_80437E24[1] = 0;
            return;
        }
        name1 = (const char *)lbl_80437E24[1];
        if (strlen(name1) != 0) {
            fn_8000FC8C(name1);
        }
        name0 = (const char *)lbl_80437E24[0];
        if (strlen(name0) != 0) {
            fn_8000FDF0(name0);
        }
    }
}
#pragma pop
/* When the debug overlay is active, clamps/raises the value toward 255 based on remaining time from fn_801C3B6C(). */
void fn_801C6AD0(s32 *value) {
    f32 currentTime;
    f32 scaledTime;
    f32 roundedValue;
    s32 intValue;
    s32 clampedValue;
    s32 result;

    if ((u8)lbl_8055E7E2 != 0) {
        currentTime = fn_801C3B6C();
        if (currentTime < lbl_8056296C) {
            clampedValue = *value;
            scaledTime = lbl_805629C8 * (lbl_8056296C - currentTime);
            if (scaledTime < lbl_80562970) {
                roundedValue = scaledTime - lbl_80562974;
            } else {
                roundedValue = lbl_80562974 + scaledTime;
            }
            intValue = (s32)roundedValue;
            if (intValue > clampedValue) {
                clampedValue = intValue;
            }
            result = 0xFF;
            if (clampedValue < 0xFF) {
                result = clampedValue;
            }
            *value = result;
        }
    }
}

void fn_801C6D94(void) {
    /* Copy a 12-word state block into the working buffer, then enable mode 1. */
    struct MtxCopy {
        s32 data[12];
    };
    *(struct MtxCopy*)lbl_80438220 = *(struct MtxCopy*)lbl_80499050;
    fn_801C957C(1);
}

extern f32 lbl_8055E830;
extern f32 lbl_805629D0;
extern f32 lbl_805629BC;
extern char lbl_80336EA8[];
extern double fn_8002EFA8(double);
extern void fn_80144CD0(f32 *, f32 *, f32 *);
extern void fn_801C7254(void *);
extern double fabs(double);
void fn_801C6E40(void) {
    char *base;
    void *obj;
    f32 *mat;
    f32 quat[4];
    s32 swz[9];
    f32 rot[9];
    f32 vec[3];
    f32 trace;
    f32 root;
    s32 i;
    s32 j;
    s32 k;
    f32 angle;
    f32 sv;
    f32 scale;
    f32 inv;
    base = (char *)&lbl_80437D88;
    lbl_8055E830 = (f32) atof(base + 0x368);
    obj = fn_801C3C80();
    ((s32 *)obj)[2] = 1;
    mat = (f32 *)(base + 0x468);
    ((f32 *)obj)[21] = lbl_8055E834;
    ((f32 *)obj)[3] = mat[9];
    ((f32 *)obj)[4] = mat[10];
    ((f32 *)obj)[5] = mat[11];
    ((s32 *)obj)[6] = ((s32 *)mat)[0];
    ((s32 *)obj)[7] = ((s32 *)mat)[1];
    ((s32 *)obj)[8] = ((s32 *)mat)[2];
    ((s32 *)obj)[9] = ((s32 *)mat)[3];
    ((s32 *)obj)[10] = ((s32 *)mat)[4];
    ((s32 *)obj)[11] = ((s32 *)mat)[5];
    ((s32 *)obj)[12] = ((s32 *)mat)[6];
    ((s32 *)obj)[13] = ((s32 *)mat)[7];
    ((s32 *)obj)[14] = ((s32 *)mat)[8];
    ((f32 *)obj)[22] = ((f32 *)obj)[0] + lbl_8055E830;
    ((u8 *)obj)[0x5C] = 1;
    if (lbl_8055E830 > lbl_805629D0) {
        swz[0] = ((s32 *)mat)[0];
        swz[1] = ((s32 *)mat)[1];
        swz[2] = ((s32 *)mat)[2];
        swz[3] = ((s32 *)mat)[3];
        swz[4] = ((s32 *)mat)[4];
        swz[5] = ((s32 *)mat)[5];
        swz[6] = ((s32 *)mat)[6];
        swz[7] = ((s32 *)mat)[7];
        swz[8] = ((s32 *)mat)[8];
        fn_801C7254(swz);
        fn_80015B20((s32)rot, (void *)(base + 0x498), (s32)swz);
        fn_80144CD0(vec, (f32 *)(base + 0x498 + 0x24), mat);
        trace = rot[0] + rot[4] + rot[8];
        if (trace > lbl_80562970) {
            root = (f32) fn_8002F234(lbl_8056296C + trace);
            quat[3] = lbl_80562974 * root;
            root = lbl_80562974 / root;
            quat[0] = root * (rot[5] - rot[7]);
            quat[1] = root * (rot[6] - rot[2]);
            quat[2] = root * (rot[1] - rot[3]);
        } else {
            i = 0;
            if (rot[4] > rot[0]) i = 1;
            if (rot[8] > rot[i * 3 + i]) i = 2;
            j = (i + 1) % 3;
            k = (j + 1) % 3;
            root = (f32) fn_8002F234(lbl_8056296C + rot[i * 3 + i] - (rot[j * 3 + k] + rot[k * 3 + j]));
            quat[i] = lbl_80562974 * root;
            root = lbl_80562974 / root;
            quat[3] = root * (rot[j * 3 + k] - rot[k * 3 + j]);
            quat[j] = root * (rot[i * 3 + j] + rot[j * 3 + i]);
            quat[k] = root * (rot[i * 3 + k] + rot[k * 3 + i]);
        }
        angle = (f32) fn_8002EFA8(quat[3]);
        sv = sin(angle);
        if ((f32) fabs(sv) > lbl_80558DC4[0]) {
            scale = (lbl_805629BC * angle) / sv;
            ((f32 *)obj)[18] = quat[0] * scale;
            ((f32 *)obj)[19] = quat[1] * scale;
            ((f32 *)obj)[20] = quat[2] * scale;
        } else {
            ((f32 *)obj)[18] = lbl_80562970;
            ((f32 *)obj)[19] = lbl_80562970;
            ((f32 *)obj)[20] = lbl_80562970;
        }
        inv = lbl_8056296C / lbl_8055E830;
        ((f32 *)obj)[18] *= inv;
        ((f32 *)obj)[19] *= inv;
        ((f32 *)obj)[20] *= inv;
        inv = lbl_8056296C / lbl_8055E830;
        ((f32 *)obj)[15] = vec[0] * inv;
        ((f32 *)obj)[16] = vec[1] * inv;
        ((f32 *)obj)[17] = vec[2] * inv;
    } else {
        ((f32 *)obj)[18] = lbl_80562970;
        ((f32 *)obj)[19] = lbl_80562970;
        ((f32 *)obj)[20] = lbl_80562970;
        ((f32 *)obj)[15] = lbl_80562970;
        ((f32 *)obj)[16] = lbl_80562970;
        ((f32 *)obj)[17] = lbl_80562970;
    }
    sprintf(base + 0x238, lbl_80336EA8, ((f32 *)obj)[0]);
    qsort((void *)(s32)lbl_8055E7F8, (size_t)lbl_8055E7F0, 0x30C, (int (*)(const void *, const void *))fn_801C3B7C);
    fn_801C957C(0);
}

void fn_801C7254(void *arg0) {
    f32 *p = (f32 *)arg0;
    f32 t;
    
    t = p[1]; p[1] = p[3]; p[3] = t;
    t = p[2]; p[2] = p[6]; p[6] = t;
    t = p[5]; p[5] = p[7]; p[7] = t;
}
