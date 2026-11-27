// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void fn_801A90A4(char *, int, const char *);
extern void fn_801A9110(void *, const char *);
// split_file divides it into the game's real files (file_status shows its range).
extern const char *lbl_802F9588[];
struct Entry_801A75B4 { const char *name; char pad[20]; };
typedef struct F801A9050Zero {
    int words[8];
} F801A9050Zero;
extern float fn_801A7F98();
extern float lbl_80562458;
extern const float lbl_80562468;
extern float lbl_8056246C;
extern int isKeyPressed(unsigned char);
extern float lbl_80562470;
extern char lbl_8055A850;
extern void *fn_801A9234(const char *);
extern int lbl_80435050[]; /* 4 controller configs of 0x64 bytes, reset by the caller's flag */
typedef struct Rec_801A7A5C { float f[8]; unsigned char b[0x20]; int w[8]; unsigned char c; } Rec_801A7A5C;
#define CB4_801A7A5C(n) dst->b[n] = src->b[n]; dst->b[n+1] = src->b[n+1]; dst->b[n+2] = src->b[n+2]; dst->b[n+3] = src->b[n+3];
typedef struct Rec2_801A7A5C {
    float f0, f1, f2, f3, f4, f5, f6, f7;
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15;
    unsigned char b16, b17, b18, b19, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b30, b31;
    int w0, w1, w2, w3, w4, w5, w6, w7;
    unsigned char c;
    unsigned char pad[3];
} Rec2_801A7A5C;
typedef struct Tail_801A7A5C { float x, y; unsigned char a, b, c; } Tail_801A7A5C;
extern unsigned char lbl_80435370[]; /* pointer state: f32 x @0, f32 y @4, button bits @8..10 */
extern int lbl_8055CFF0; /* screen width (640) */
extern int lbl_8055CFF4; /* screen height (480) */
extern double lbl_80562450;
extern void fn_80127A84(int *, int *, unsigned int *); /* read pointer x/y and button mask */
extern int fn_80129AE8(void *, int); /* copy controller config at index into a 0x64-byte dst */
extern void *memset(void *, int, unsigned int);
extern int fn_801A8E38();

/* Input binding table (built by initInputBindings): 0x18-byte entries mapping a
 * control's display name to the key/action bound to it. */
typedef struct InputBinding {
    const char *name;      /* +0x00 display name, e.g. "Joy AX+" */
    const char *id;        /* +0x04 internal id, e.g. "JoyAXPlus" */
    int type;              /* +0x08 binding type (1..6) */
    int value;             /* +0x0C bound key code */
    unsigned char keyFlag; /* +0x10 per-key byte filled in by initInputBindings; never read back */
    char pad11[3];         /* +0x11 */
    unsigned char enabled; /* +0x14 enabled flag (0 = active) */
    char pad15[3];         /* +0x15 */
} InputBinding;
#define NUM_INPUT_BINDINGS 122        /* entries of the table at lbl_803342D0 */
#define gInputBindingTable lbl_8055E5CC /* InputBinding*: table base */
#define gInputBindingCount lbl_8055E5D0 /* int: number of entries (0x7A) */
#define gInputBindingsReady lbl_8055E5D4 /* char: the table has been filled in */

/* Keyboard key codes (InputBinding::value, and the argument of the key-state
 * helper fn_802E47F8) are HID keyboard usage IDs. */
enum HidKey {
    HID_KEY_A = 0x04, HID_KEY_B = 0x05, HID_KEY_C = 0x06, HID_KEY_D = 0x07,
    HID_KEY_E = 0x08, HID_KEY_F = 0x09, HID_KEY_G = 0x0A, HID_KEY_H = 0x0B,
    HID_KEY_I = 0x0C, HID_KEY_J = 0x0D, HID_KEY_K = 0x0E, HID_KEY_L = 0x0F,
    HID_KEY_M = 0x10, HID_KEY_N = 0x11, HID_KEY_O = 0x12, HID_KEY_P = 0x13,
    HID_KEY_Q = 0x14, HID_KEY_R = 0x15, HID_KEY_S = 0x16, HID_KEY_T = 0x17,
    HID_KEY_U = 0x18, HID_KEY_V = 0x19, HID_KEY_W = 0x1A, HID_KEY_X = 0x1B,
    HID_KEY_Y = 0x1C, HID_KEY_Z = 0x1D,
    HID_KEY_1 = 0x1E, HID_KEY_2 = 0x1F, HID_KEY_3 = 0x20, HID_KEY_4 = 0x21,
    HID_KEY_5 = 0x22, HID_KEY_6 = 0x23, HID_KEY_7 = 0x24, HID_KEY_8 = 0x25,
    HID_KEY_9 = 0x26, HID_KEY_0 = 0x27,
    HID_KEY_ENTER = 0x28, HID_KEY_ESCAPE = 0x29, HID_KEY_BACKSPACE = 0x2A,
    HID_KEY_TAB = 0x2B, HID_KEY_SPACE = 0x2C, HID_KEY_MINUS = 0x2D,
    HID_KEY_EQUALS = 0x2E, HID_KEY_LBRACKET = 0x2F, HID_KEY_RBRACKET = 0x30,
    HID_KEY_BACKSLASH = 0x31, HID_KEY_HASH = 0x32, HID_KEY_SEMICOLON = 0x33,
    HID_KEY_QUOTE = 0x34, HID_KEY_BACKTICK = 0x35
};

/* A control's binding the way the options code keeps it: the kind of input and
 * the key/axis within it.  fn_801A9110 builds one from a binding's display
 * name, fn_801A9234 finds the table entry one describes, and fn_801A90A4 turns
 * one back into the name written to the options file. */
typedef struct InputKeySpec {
    int type;  /* +0x00 binding type (1..6, 0 = unbound) */
    int unk4;  /* +0x04 zeroed by the callers; fn_801A9234 never compares it */
    int value; /* +0x08 key code, compared as a byte for type 1 */
} InputKeySpec;

extern char lbl_8055E5C8;
#pragma push
#pragma scheduling invalid_target
/* Find the named entry in the global table (0x15 entries of 8 bytes), case-insensitively. */
const char **fn_801A75B4(const char *name) {
    const char **entry = (const char **)lbl_802F9588;
    int index = 0;

    do {
        if (stricmp(*entry, name) == 0)
            return entry;
        index++;
        entry = (const char **)((char *)entry + 8);
    } while (index < 0x15);
    return 0;
}
#pragma pop
extern signed char fn_802E47F8(int);
extern char lbl_803342D0[];
extern char lbl_8055E5D4;
/* Lazy initializer of the static input-binding table at lbl_803342D0
 * (NUM_INPUT_BINDINGS entries of InputBinding, filled in at link time with the
 * control names, ids, types and key codes).  The first time it is called it
 * also gives the 38 keyboard bindings (entries 73..110) their keyFlag, asking
 * the screenshot-subsystem helper fn_802E47F8 about the entry's HID key code --
 * that helper is a stub returning 0 in this build, so every flag ends up clear.
 * Either way it then publishes the table through gInputBindingTable /
 * gInputBindingCount; callers use it as "make sure the table is ready". */
#pragma push
#pragma scheduling invalid_target
/* Fill the input-binding table's per-key flags from the HID key codes once, then publish the table base pointer and entry count. */ void initInputBindings(void) {
    extern const char **gInputBindingTable;
    extern int gInputBindingCount;
#define gBindings ((InputBinding *)lbl_803342D0)
    if ((signed char)gInputBindingsReady == 0) {
        gBindings[73].keyFlag = fn_802E47F8(HID_KEY_1);
        gBindings[74].keyFlag = fn_802E47F8(HID_KEY_RBRACKET);
        gBindings[75].keyFlag = fn_802E47F8(HID_KEY_EQUALS);
        gBindings[76].keyFlag = fn_802E47F8(HID_KEY_3);
        gBindings[77].keyFlag = fn_802E47F8(HID_KEY_O);
        gBindings[78].keyFlag = fn_802E47F8(HID_KEY_4);
        gBindings[79].keyFlag = fn_802E47F8(HID_KEY_5);
        gBindings[80].keyFlag = fn_802E47F8(HID_KEY_6);
        gBindings[81].keyFlag = fn_802E47F8(HID_KEY_T);
        gBindings[82].keyFlag = fn_802E47F8(HID_KEY_7);
        gBindings[83].keyFlag = fn_802E47F8(HID_KEY_8);
        gBindings[84].keyFlag = fn_802E47F8(HID_KEY_9);
        gBindings[85].keyFlag = fn_802E47F8(HID_KEY_HASH);
        gBindings[86].keyFlag = fn_802E47F8(HID_KEY_BACKSLASH);
        gBindings[87].keyFlag = fn_802E47F8(HID_KEY_U);
        gBindings[88].keyFlag = fn_802E47F8(HID_KEY_M);
        gBindings[89].keyFlag = fn_802E47F8(HID_KEY_P);
        gBindings[90].keyFlag = fn_802E47F8(HID_KEY_2);
        gBindings[91].keyFlag = fn_802E47F8(HID_KEY_S);
        gBindings[92].keyFlag = fn_802E47F8(HID_KEY_LBRACKET);
        gBindings[93].keyFlag = fn_802E47F8(HID_KEY_N);
        gBindings[94].keyFlag = fn_802E47F8(HID_KEY_MINUS);
        gBindings[95].keyFlag = fn_802E47F8(HID_KEY_R);
        gBindings[96].keyFlag = fn_802E47F8(HID_KEY_SPACE);
        gBindings[97].keyFlag = fn_802E47F8(HID_KEY_D);
        gBindings[98].keyFlag = fn_802E47F8(HID_KEY_E);
        gBindings[99].keyFlag = fn_802E47F8(HID_KEY_F);
        gBindings[100].keyFlag = fn_802E47F8(HID_KEY_G);
        gBindings[101].keyFlag = fn_802E47F8(HID_KEY_H);
        gBindings[102].keyFlag = fn_802E47F8(HID_KEY_W);
        gBindings[103].keyFlag = fn_802E47F8(HID_KEY_X);
        gBindings[104].keyFlag = fn_802E47F8(HID_KEY_0);
        gBindings[105].keyFlag = fn_802E47F8(HID_KEY_ENTER);
        gBindings[106].keyFlag = fn_802E47F8(HID_KEY_SEMICOLON);
        gBindings[107].keyFlag = fn_802E47F8(HID_KEY_QUOTE);
        gBindings[108].keyFlag = fn_802E47F8(HID_KEY_BACKTICK);
        gBindings[109].keyFlag = fn_802E47F8(HID_KEY_I);
        gBindings[110].keyFlag = fn_802E47F8(HID_KEY_J);
        gInputBindingsReady = 1;
    }
    gInputBindingTable = (const char **)lbl_803342D0;
    gInputBindingCount = NUM_INPUT_BINDINGS;
#undef gBindings
}
#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
/* Refresh the pointer state: optionally reload all four controller configs, then
 * read the pointer and store its x/y as screen-normalized floats plus its 3 button bits. */
void fn_801A7844(int resetControllers) {
    char *config;
    int controllerIndex;
    int pointerX;
    int pointerY;
    unsigned int buttons;

    if (resetControllers != 0) {
        config = (char *)lbl_80435050;
        controllerIndex = 0;
        do {
            memset(config, 0, 0x64);
            fn_80129AE8(config, controllerIndex);
            controllerIndex++;
            config += 0x64;
        } while (controllerIndex < 4);
    }
    fn_80127A84(&pointerX, &pointerY, &buttons);
    *(float *)&lbl_80435370[0] = (float)(pointerX - (int)lbl_8055CFF0 / 2) / (float)((int)lbl_8055CFF0 / 2);
    *(float *)&lbl_80435370[4] = (float)(pointerY - (int)lbl_8055CFF4 / 2) / (float)((int)lbl_8055CFF4 / 2);
    lbl_80435370[8] = buttons & 1;
    lbl_80435370[9] = (buttons >> 1) & 1;
    lbl_80435370[10] = (buttons >> 2) & 1;
}
#pragma pop
extern void fn_801334F4(int, int, int *, int);
#pragma push
#pragma scheduling invalid_target
/* Resolve an input-binding name via config lookup and copy the matching binding record to outBinding. */
void fn_801A7974(const char *outBinding, int valueId, int groupId) {
    F801A9050Zero bindingName;

    bindingName.words[0] = 0;
    bindingName.words[1] = 0;
    bindingName.words[2] = 0;
    bindingName.words[3] = 0;
    bindingName.words[4] = 0;
    bindingName.words[5] = 0;
    bindingName.words[6] = 0;
    bindingName.words[7] = 0;
    fn_801A90A4((char *)&bindingName, 0x20, outBinding);
    fn_801334F4(groupId, valueId, bindingName.words, 0x20);
    fn_801A9110((void *)outBinding, (const char *)&bindingName);
}
#pragma scheduling on
#pragma pop
extern void fn_801A90A4(char *, int, const char *);
extern int setStringOption(int, int, char *);
#pragma push
#pragma scheduling invalid_target
/* Save a control's binding in the options: resolve the input binding the key
 * spec (an InputKeySpec, see fn_801A9234) describes to its display name, then
 * write that name as the string value of option (groupId, valueId). */
void fn_801A7A08(const char *keySpec, int valueId, int groupId) {
    char bindingName[0x20];

    fn_801A90A4(bindingName, 0x20, keySpec);
    setStringOption(groupId, valueId, bindingName);
}
#pragma pop
extern float lbl_80562458;
static inline void copy_recs_801A7A5C(Rec_801A7A5C *src, Rec_801A7A5C *dst, char *base) {
    int i;
    float fa, fb;
    unsigned char ba, bb;
    int wa, wb;
    for (i = 0; i < 4; i++) {
        fa = src->f[0];
        fb = src->f[1];
        dst->f[0] = fa;
        fa = src->f[2];
        dst->f[1] = fb;
        fb = src->f[3];
        dst->f[2] = fa;
        fa = src->f[4];
        dst->f[3] = fb;
        fb = src->f[5];
        dst->f[4] = fa;
        fa = src->f[6];
        dst->f[5] = fb;
        fb = src->f[7];
        dst->f[6] = fa;
        dst->f[7] = fb;
        ba = src->b[0];
        bb = src->b[1];
        dst->b[0] = ba;
        ba = src->b[2];
        dst->b[1] = bb;
        bb = src->b[3];
        dst->b[2] = ba;
        ba = src->b[4];
        dst->b[3] = bb;
        bb = src->b[5];
        dst->b[4] = ba;
        ba = src->b[6];
        dst->b[5] = bb;
        bb = src->b[7];
        dst->b[6] = ba;
        dst->b[7] = bb;
        ba = src->b[8];
        bb = src->b[9];
        dst->b[8] = ba;
        ba = src->b[10];
        dst->b[9] = bb;
        bb = src->b[11];
        dst->b[10] = ba;
        ba = src->b[12];
        dst->b[11] = bb;
        bb = src->b[13];
        dst->b[12] = ba;
        ba = src->b[14];
        dst->b[13] = bb;
        bb = src->b[15];
        dst->b[14] = ba;
        dst->b[15] = bb;
        ba = src->b[16];
        bb = src->b[17];
        dst->b[16] = ba;
        ba = src->b[18];
        dst->b[17] = bb;
        bb = src->b[19];
        dst->b[18] = ba;
        ba = src->b[20];
        dst->b[19] = bb;
        bb = src->b[21];
        dst->b[20] = ba;
        ba = src->b[22];
        dst->b[21] = bb;
        bb = src->b[23];
        dst->b[22] = ba;
        dst->b[23] = bb;
        ba = src->b[24];
        bb = src->b[25];
        dst->b[24] = ba;
        ba = src->b[26];
        dst->b[25] = bb;
        bb = src->b[27];
        dst->b[26] = ba;
        ba = src->b[28];
        dst->b[27] = bb;
        bb = src->b[29];
        dst->b[28] = ba;
        ba = src->b[30];
        dst->b[29] = bb;
        bb = src->b[31];
        dst->b[30] = ba;
        dst->b[31] = bb;
        wa = src->w[0];
        wb = src->w[1];
        dst->w[0] = wa;
        wa = src->w[2];
        dst->w[1] = wb;
        wb = src->w[3];
        dst->w[2] = wa;
        wa = src->w[4];
        dst->w[3] = wb;
        wb = src->w[5];
        dst->w[4] = wa;
        wa = src->w[6];
        dst->w[5] = wb;
        wb = src->w[7];
        dst->w[6] = wa;
        dst->w[7] = wb;
        ba = src->c;
        dst->c = ba;
        src++;
        dst++;
    }
    {
        Tail_801A7A5C *u = (Tail_801A7A5C *)(base + 0x320);
        Tail_801A7A5C *vv = (Tail_801A7A5C *)(base + 0x32C);
        vv->x = u->x;
        vv->y = u->y;
        vv->a = u->a;
        vv->b = u->b;
        vv->c = u->c;
    }
}
void fn_801A7A5C(void) {
    char *base = (char *)lbl_80435050;
    Tail_801A7A5C *tail = (Tail_801A7A5C *)(base + 0x320);
    float zero = 0.0f;


    Rec_801A7A5C *src;
    Rec_801A7A5C *dst;
    int i;
    float fa, fb;
    unsigned char ba, bb;
    int wa, wb;

    *(float *)(base + 0x320) = zero;
    tail->y = zero;
    tail->c = 0;
    tail->b = 0;
    tail->a = 0;
    fn_801A7844(1);
    fn_801A7844(1);
    src = (Rec_801A7A5C *)base;
    dst = src + 4;
    for (i = 0; i < 4; i++) {
        fb = src->f[1];
        fa = src->f[0];
        dst->f[0] = fa;
        fa = src->f[2];
        dst->f[1] = fb;
        fb = src->f[3];
        dst->f[2] = fa;
        fa = src->f[4];
        dst->f[3] = fb;
        fb = src->f[5];
        dst->f[4] = fa;
        fa = src->f[6];
        dst->f[5] = fb;
        fb = src->f[7];
        dst->f[6] = fa;
        ba = src->b[0];
        dst->f[7] = fb;
        bb = src->b[1];
        dst->b[0] = ba;
        ba = src->b[2];
        dst->b[1] = bb;
        bb = src->b[3];
        dst->b[2] = ba;
        ba = src->b[4];
        dst->b[3] = bb;
        bb = src->b[5];
        dst->b[4] = ba;
        ba = src->b[6];
        dst->b[5] = bb;
        bb = src->b[7];
        dst->b[6] = ba;
        ba = src->b[8];
        dst->b[7] = bb;
        bb = src->b[9];
        dst->b[8] = ba;
        ba = src->b[10];
        dst->b[9] = bb;
        bb = src->b[11];
        dst->b[10] = ba;
        ba = src->b[12];
        dst->b[11] = bb;
        bb = src->b[13];
        dst->b[12] = ba;
        ba = src->b[14];
        dst->b[13] = bb;
        bb = src->b[15];
        dst->b[14] = ba;
        ba = src->b[16];
        dst->b[15] = bb;
        bb = src->b[17];
        dst->b[16] = ba;
        ba = src->b[18];
        dst->b[17] = bb;
        bb = src->b[19];
        dst->b[18] = ba;
        ba = src->b[20];
        dst->b[19] = bb;
        bb = src->b[21];
        dst->b[20] = ba;
        ba = src->b[22];
        dst->b[21] = bb;
        bb = src->b[23];
        dst->b[22] = ba;
        ba = src->b[24];
        dst->b[23] = bb;
        bb = src->b[25];
        dst->b[24] = ba;
        ba = src->b[26];
        dst->b[25] = bb;
        bb = src->b[27];
        dst->b[26] = ba;
        ba = src->b[28];
        dst->b[27] = bb;
        bb = src->b[29];
        dst->b[28] = ba;
        ba = src->b[30];
        dst->b[29] = bb;
        bb = src->b[31];
        dst->b[30] = ba;
        wa = src->w[0];
        dst->b[31] = bb;
        wb = src->w[1];
        dst->w[0] = wa;
        wa = src->w[2];
        dst->w[1] = wb;
        wb = src->w[3];
        dst->w[2] = wa;
        wa = src->w[4];
        dst->w[3] = wb;
        wb = src->w[5];
        dst->w[4] = wa;
        wa = src->w[6];
        dst->w[5] = wb;
        wb = src->w[7];
        dst->w[6] = wa;
        ba = src->c;
        src++;
        dst->w[7] = wb;
        dst->c = ba;
        dst++;
    }
    {
        Tail_801A7A5C *u = (Tail_801A7A5C *)(base + 0x320);
        Tail_801A7A5C *vv = (Tail_801A7A5C *)(base + 0x32C);
        unsigned char c, b, a;
        float y, x;
        x = u->x;
        y = u->y;
        a = u->a;
        b = u->b;
        c = u->c;
        vv->x = x;
        vv->y = y;
        vv->a = a;
        vv->b = b;
        vv->c = c;
    }
}

#pragma push
#pragma scheduling invalid_target
#pragma processor 750
int getNextTriggeredInput(void *arg0) {
    /* Scans the initialized table (0x18-byte entries) for the first enabled
     * entry whose input/state passes the type-specific checks, copies its id
     * and fields into arg0, and returns 1; returns 0 if none qualify. */
    extern const char **lbl_8055E5CC;
    extern int lbl_8055E5D0;
    extern const double lbl_80562460;
    extern const float lbl_80562468;
    extern void initInputBindings(void);
    extern void fn_801A91B0(void *, const void *);
    extern int fn_801A8EE4(unsigned int *);
    extern int fn_801A8A10(void *);
    extern float fn_801A85E8(void *);
    extern double __fabs(double);
    struct {
        int unk0;
        int unk4;
        int unk8;
        unsigned char unkC;
    } local;
    int offset;
    int i;
    float value;

    initInputBindings();
    for (i = 0, offset = 0; i < lbl_8055E5D0; offset += 0x18, i++) {
        if (*(unsigned char *)((char *)lbl_8055E5CC + offset + 0x14) == 0) {
            local.unk4 = 0;
            local.unkC = 0;
            fn_801A91B0(&local, (char *)lbl_8055E5CC + offset);
            if (local.unk0 != 5 && local.unk0 != 6) {
                if (fn_801A8EE4((unsigned int *)&local) != 0) {
                    if (((int (*)(void *))fn_801A8E38)(&local) != 0 && fn_801A8A10(&local) == 0) {
                        *(int *)arg0 = local.unk0;
                        *((int *)arg0 + 1) = local.unk4;
                        *((int *)arg0 + 2) = local.unk8;
                        *((unsigned char *)arg0 + 0xC) = local.unkC;
                        return 1;
                    }
                } else {
                    value = ((float (*)(void *))fn_801A7F98)(&local);
                    if ((float)__fabs(fn_801A85E8(&local)) < lbl_80562460 && value > lbl_80562468) {
                        *(int *)arg0 = local.unk0;
                        *((int *)arg0 + 1) = local.unk4;
                        *((int *)arg0 + 2) = local.unk8;
                        *((unsigned char *)arg0 + 0xC) = local.unkC;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
#pragma pop
void fn_801A9110(void *, const char *);
#pragma dont_inline on
/* Look up the input binding named by bindingName and store it in the given
 * config slot (groupId, valueId). */
void fn_801A7DFC(int valueId, const char *bindingName, int groupId) {
    struct {
        int type;
        int field4;
        char field8[4];
        char fieldC;
    } binding;

    binding.field4 = 0;
    binding.fieldC = 0;
    fn_801A9110(&binding, bindingName);
    fn_801A7A08((const char *)&binding, valueId, groupId);
}
#pragma dont_inline reset

#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_801A7E54(char *dst, int len, const char *name) {
    /* Resolve an input/action key name to its display string into dst (always null-terminated). */
    void *found = fn_801A9234(name);

    if (found != 0) {
        const char **entry = fn_801A75B4(*(const char **)found);
        if (entry != 0) {
            const char *source = entry[1];
            int count;
            char *dest;
            dest = dst;
            count = len;
            while ((signed char)(*dest++ = *source++) != 0) {
                if (--count <= 0) {
                    dest[-1] = 0;
                    break;
                }
            }
        } else {
            int count;
            char *dest;
            const char *source;
            source = *(const char **)((char *)found + 4);
            switch ((int)source) {
            case 0:
                source = (const char *)found + 0x10;
                break;
            }
            dest = dst;
            count = len;
            while ((signed char)(*dest++ = *source++) != 0) {
                if (--count <= 0) {
                    dest[-1] = 0;
                    break;
                }
            }
        }
    } else {
        const char *source = &lbl_8055A850;
        int count;
        char *dest;
        dest = dst;
        count = len;
        while ((signed char)(*dest++ = *source++) != 0) {
            if (--count <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    }
    dst[len - 1] = 0;
}
#pragma cplusplus off
#pragma dont_inline reset

void fn_801A7F8C(void) {
    /* Re-enable keyboard input by clearing the flag that makes fn_801A7F98
     * ignore keyboard scan codes; called when a session starts and ends. */
    extern char lbl_8055E5C8;
#define gKeyboardInputDisabled lbl_8055E5C8
    gKeyboardInputDisabled = 0;
#undef gKeyboardInputDisabled
}

#pragma push
#pragma scheduling invalid_target
float fn_801A7F98(input)
int *input;
{
    /* Return the normalized (0..1) value of an input binding. input[0] is the
     * binding type, input[1] selects a 0x64-byte control record in lbl_80435050
     * and input[2] is the axis/key/bit within it. Analog types read the record's
     * eight floats (clamped to zero or remapped as 0.5*(1 +/- value)); digital
     * types return the 1.0/0.0 constants lbl_8056246C / lbl_80562458. */
    unsigned char *entry;
    float *axes;
    float value;
    if (fn_801A8F10(input) == 0)
        return lbl_80562458;
    entry = (unsigned char *)lbl_80435050 + input[1] * 0x64;
    axes = (float *)entry;
    switch (input[0]) {
    case 2: /* analog axis: the record's eight floats, selected by input[2] */
        switch (input[2]) {
        case 0: value = -axes[0]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 1: value = axes[0]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 2: value = -axes[1]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 3: value = axes[1]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 4: value = -axes[3]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 5: value = axes[3]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 6: value = -axes[2]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 7: value = axes[2]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 8: value = -axes[4]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 9: value = axes[4]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 10: value = -axes[5]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 11: value = axes[5]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 12: value = -axes[6]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 13: value = axes[6]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 14: value = -axes[7]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 15: value = axes[7]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 16: return lbl_80562468 * (lbl_8056246C - axes[0]);
        case 17: return lbl_80562468 * (lbl_8056246C - axes[1]);
        case 18: return lbl_80562468 * (lbl_8056246C - axes[3]);
        case 19: return lbl_80562468 * (lbl_8056246C - axes[2]);
        case 20: return lbl_80562468 * (lbl_8056246C - axes[4]);
        case 21: return lbl_80562468 * (lbl_8056246C - axes[5]);
        case 22: return lbl_80562468 * (lbl_8056246C - axes[6]);
        case 23: return lbl_80562468 * (lbl_8056246C - axes[7]);
        case 24: return lbl_80562468 * (lbl_8056246C + axes[0]);
        case 25: return lbl_80562468 * (lbl_8056246C + axes[1]);
        case 26: return lbl_80562468 * (lbl_8056246C + axes[3]);
        case 27: return lbl_80562468 * (lbl_8056246C + axes[2]);
        case 28: return lbl_80562468 * (lbl_8056246C + axes[4]);
        case 29: return lbl_80562468 * (lbl_8056246C + axes[5]);
        case 30: return lbl_80562468 * (lbl_8056246C + axes[6]);
        case 31: return lbl_80562468 * (lbl_8056246C + axes[7]);
        }
        break;
    case 3: /* per-axis button flag bytes at +0x20 */
        if (input[2] >= 0 && (unsigned int)input[2] < 0x20) {
            if ((entry + input[2])[0x20] != 0)
                return lbl_8056246C;
            return lbl_80562458;
        }
        break;
    case 4: /* button bitmask word at +0x40 */
        if (*(int *)(entry + 0x40) & input[2])
            return lbl_8056246C;
        return lbl_80562458;
    case 5: /* two special analog values held in lbl_80435370 */
        switch (input[2]) {
        case 0: value = -*(float *)&lbl_80435370[0]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 1: value = *(float *)&lbl_80435370[0]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 2: value = -*(float *)&lbl_80435370[4]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 3: value = *(float *)&lbl_80435370[4]; if (lbl_80562458 > value) return lbl_80562458; return value;
        case 4: return lbl_80562468 * (lbl_8056246C - *(float *)&lbl_80435370[0]);
        case 5: return lbl_80562468 * (lbl_8056246C - *(float *)&lbl_80435370[4]);
        case 6: return lbl_80562468 * (lbl_8056246C + *(float *)&lbl_80435370[0]);
        case 7: return lbl_80562468 * (lbl_8056246C + *(float *)&lbl_80435370[4]);
        }
        break;
    case 6: /* three special digital flags held in lbl_80435370 */
        switch (input[2]) {
        case 0:
            if (lbl_80435370[8] != 0) return lbl_8056246C;
            return lbl_80562458;
        case 2:
            if (lbl_80435370[9] != 0) return lbl_8056246C;
            return lbl_80562458;
        case 1:
            if (lbl_80435370[10] != 0) return lbl_8056246C;
            return lbl_80562458;
        }
        break;
    case 1: /* keyboard/action key, looked up in isKeyPressed's table */
        if (*(unsigned char *)&lbl_8055E5C8 == 0) {
            if (isKeyPressed(*(unsigned char *)(input + 2)) != 0)
                return lbl_8056246C;
            return lbl_80562458;
        }
        break;
    }
    return lbl_80562458;
}
#pragma push
#pragma scheduling invalid_target
float fn_801A85E8(void *arg0) {
    struct Row {
        float floats[8];
        unsigned char bytes[32];
        unsigned int words[8];
        unsigned char last;
    };
    struct Config {
        float value0;
        float value1;
        unsigned char flags[3];
    };
    struct Row *output;
    struct Config *config;
    char *base;
    struct Row *row;
    struct Row *source;
    volatile char *sourceBase;
    struct Config *active;
    struct Row snapshot;
    union { unsigned int words[3]; float values[2]; unsigned char bytes[12]; } saved;
    unsigned int index;
    float result;
    float copyF0, copyF1;
    unsigned char copyB0, copyB1;
    unsigned int copyW0, copyW1;

    base = (char *)lbl_80435050;
    if (*(int *)arg0 == 1)
        return lbl_80562458;

    index = *(int *)((char *)arg0 + 4);
    row = (struct Row *)(base + index * 0x64);
    snapshot = *row;
    output = (struct Row *)((char *)lbl_80435050 + index * 0x64);
    sourceBase = (volatile char *)base + 0x190;
    source = (struct Row *)(sourceBase + index * 0x64);
    row->floats[0] = *(volatile float *)(sourceBase + index * 0x64);
    copyF0 = source->floats[1];
    copyF1 = source->floats[2];
    output->floats[1] = copyF0;
    copyF0 = source->floats[3];
    output->floats[2] = copyF1;
    copyF1 = source->floats[4];
    output->floats[3] = copyF0;
    copyF0 = source->floats[5];
    output->floats[4] = copyF1;
    copyF1 = source->floats[6];
    output->floats[5] = copyF0;
    copyF0 = source->floats[7];
    output->floats[6] = copyF1;
    output->floats[7] = copyF0;

    copyB0 = source->bytes[0];
    copyB1 = source->bytes[1];
    output->bytes[0] = copyB0;
    copyB0 = source->bytes[2];
    output->bytes[1] = copyB1;
    copyB1 = source->bytes[3];
    output->bytes[2] = copyB0;
    copyB0 = source->bytes[4];
    output->bytes[3] = copyB1;
    copyB1 = source->bytes[5];
    output->bytes[4] = copyB0;
    copyB0 = source->bytes[6];
    output->bytes[5] = copyB1;
    copyB1 = source->bytes[7];
    output->bytes[6] = copyB0;
    copyB0 = source->bytes[8];
    output->bytes[7] = copyB1;
    copyB1 = source->bytes[9];
    output->bytes[8] = copyB0;
    copyB0 = source->bytes[10];
    output->bytes[9] = copyB1;
    copyB1 = source->bytes[11];
    output->bytes[10] = copyB0;
    copyB0 = source->bytes[12];
    output->bytes[11] = copyB1;
    copyB1 = source->bytes[13];
    output->bytes[12] = copyB0;
    copyB0 = source->bytes[14];
    output->bytes[13] = copyB1;
    copyB1 = source->bytes[15];
    output->bytes[14] = copyB0;
    copyB0 = source->bytes[16];
    output->bytes[15] = copyB1;
    copyB1 = source->bytes[17];
    output->bytes[16] = copyB0;
    copyB0 = source->bytes[18];
    output->bytes[17] = copyB1;
    copyB1 = source->bytes[19];
    output->bytes[18] = copyB0;
    copyB0 = source->bytes[20];
    output->bytes[19] = copyB1;
    copyB1 = source->bytes[21];
    output->bytes[20] = copyB0;
    copyB0 = source->bytes[22];
    output->bytes[21] = copyB1;
    copyB1 = source->bytes[23];
    output->bytes[22] = copyB0;
    copyB0 = source->bytes[24];
    output->bytes[23] = copyB1;
    copyB1 = source->bytes[25];
    output->bytes[24] = copyB0;
    copyB0 = source->bytes[26];
    output->bytes[25] = copyB1;
    copyB1 = source->bytes[27];
    output->bytes[26] = copyB0;
    copyB0 = source->bytes[28];
    output->bytes[27] = copyB1;
    copyB1 = source->bytes[29];
    output->bytes[28] = copyB0;
    copyB0 = source->bytes[30];
    output->bytes[29] = copyB1;
    copyB1 = source->bytes[31];
    output->bytes[30] = copyB0;
    output->bytes[31] = copyB1;

    copyW0 = source->words[0];
    copyW1 = source->words[1];
    output->words[0] = copyW0;
    copyW0 = source->words[2];
    output->words[1] = copyW1;
    copyW1 = source->words[3];
    output->words[2] = copyW0;
    copyW0 = source->words[4];
    output->words[3] = copyW1;
    copyW1 = source->words[5];
    output->words[4] = copyW0;
    copyW0 = source->words[6];
    output->words[5] = copyW1;
    copyW1 = source->words[7];
    output->words[6] = copyW0;
    output->words[7] = copyW1;

    output->last = source->last;

    config = (struct Config *)(base + 0x320);
    active = (struct Config *)(base + 0x32C);
    *(struct Config *)&saved = *config;
    config->value0 = active->value0;
    config->value1 = active->value1;
    config->flags[0] = active->flags[0];
    config->flags[1] = active->flags[1];
    config->flags[2] = active->flags[2];

    result = fn_801A7F98(arg0);
    row->floats[0] = snapshot.floats[0];
    copyF0 = snapshot.floats[1];
    copyF1 = snapshot.floats[2];
    output->floats[1] = copyF0;
    copyF0 = snapshot.floats[3];
    output->floats[2] = copyF1;
    copyF1 = snapshot.floats[4];
    output->floats[3] = copyF0;
    copyF0 = snapshot.floats[5];
    output->floats[4] = copyF1;
    copyF1 = snapshot.floats[6];
    output->floats[5] = copyF0;
    copyF0 = snapshot.floats[7];
    output->floats[6] = copyF1;
    output->floats[7] = copyF0;

    copyB0 = snapshot.bytes[0];
    copyB1 = snapshot.bytes[1];
    output->bytes[0] = copyB0;
    copyB0 = snapshot.bytes[2];
    output->bytes[1] = copyB1;
    copyB1 = snapshot.bytes[3];
    output->bytes[2] = copyB0;
    copyB0 = snapshot.bytes[4];
    output->bytes[3] = copyB1;
    copyB1 = snapshot.bytes[5];
    output->bytes[4] = copyB0;
    copyB0 = snapshot.bytes[6];
    output->bytes[5] = copyB1;
    copyB1 = snapshot.bytes[7];
    output->bytes[6] = copyB0;
    copyB0 = snapshot.bytes[8];
    output->bytes[7] = copyB1;
    copyB1 = snapshot.bytes[9];
    output->bytes[8] = copyB0;
    copyB0 = snapshot.bytes[10];
    output->bytes[9] = copyB1;
    copyB1 = snapshot.bytes[11];
    output->bytes[10] = copyB0;
    copyB0 = snapshot.bytes[12];
    output->bytes[11] = copyB1;
    copyB1 = snapshot.bytes[13];
    output->bytes[12] = copyB0;
    copyB0 = snapshot.bytes[14];
    output->bytes[13] = copyB1;
    copyB1 = snapshot.bytes[15];
    output->bytes[14] = copyB0;
    copyB0 = snapshot.bytes[16];
    output->bytes[15] = copyB1;
    copyB1 = snapshot.bytes[17];
    output->bytes[16] = copyB0;
    copyB0 = snapshot.bytes[18];
    output->bytes[17] = copyB1;
    copyB1 = snapshot.bytes[19];
    output->bytes[18] = copyB0;
    copyB0 = snapshot.bytes[20];
    output->bytes[19] = copyB1;
    copyB1 = snapshot.bytes[21];
    output->bytes[20] = copyB0;
    copyB0 = snapshot.bytes[22];
    output->bytes[21] = copyB1;
    copyB1 = snapshot.bytes[23];
    output->bytes[22] = copyB0;
    copyB0 = snapshot.bytes[24];
    output->bytes[23] = copyB1;
    copyB1 = snapshot.bytes[25];
    output->bytes[24] = copyB0;
    copyB0 = snapshot.bytes[26];
    output->bytes[25] = copyB1;
    copyB1 = snapshot.bytes[27];
    output->bytes[26] = copyB0;
    copyB0 = snapshot.bytes[28];
    output->bytes[27] = copyB1;
    copyB1 = snapshot.bytes[29];
    output->bytes[28] = copyB0;
    copyB0 = snapshot.bytes[30];
    output->bytes[29] = copyB1;
    copyB1 = snapshot.bytes[31];
    output->bytes[30] = copyB0;
    output->bytes[31] = copyB1;

    copyW0 = snapshot.words[0];
    copyW1 = snapshot.words[1];
    output->words[0] = copyW0;
    copyW0 = snapshot.words[2];
    output->words[1] = copyW1;
    copyW1 = snapshot.words[3];
    output->words[2] = copyW0;
    copyW0 = snapshot.words[4];
    output->words[3] = copyW1;
    copyW1 = snapshot.words[5];
    output->words[4] = copyW0;
    copyW0 = snapshot.words[6];
    output->words[5] = copyW1;
    copyW1 = snapshot.words[7];
    output->words[6] = copyW0;
    output->words[7] = copyW1;

    output->last = snapshot.last;
    config->value0 = saved.values[0];
    config->value1 = saved.values[1];
    config->flags[0] = saved.bytes[8];
    config->flags[1] = saved.bytes[9];
    config->flags[2] = saved.bytes[10];
    return result;
}
#pragma push
#pragma scheduling invalid_target
int fn_801A8A10(void *arg0) {
struct Row {
float floats[8];
unsigned char bytes[32];
unsigned int words[8];
unsigned char last;
};
struct Config {
float value0;
float value1;
unsigned char flags[3];
};
struct Row *output;
struct Config *config;
volatile char *base;
struct Row *row;
struct Row *source;
volatile char *sourceBase;
struct Config *active;
struct Row snapshot;
union { unsigned int words[3]; float values[2]; unsigned char bytes[12]; } saved;
int index;
int result;

if (*(const int *)arg0 == 1)
return 0;

base = (volatile char *)lbl_80435050;
index = *(const int *)((const char *)arg0 + 4);
row = (struct Row *)(base + index * 0x64);
snapshot = *row;
output = (struct Row *)(base + index * 0x64);
sourceBase = (volatile char *)lbl_80435050 + 0x190;
source = (struct Row *)(sourceBase + index * 0x64);
row->floats[0] = *(volatile float *)(sourceBase + index * 0x64);
output->floats[1] = source->floats[1];
output->floats[2] = source->floats[2];
output->floats[3] = source->floats[3];
output->floats[4] = source->floats[4];
output->floats[5] = source->floats[5];
output->floats[6] = source->floats[6];
output->floats[7] = source->floats[7];
output->bytes[0] = source->bytes[0];
output->bytes[1] = source->bytes[1];
output->bytes[2] = source->bytes[2];
output->bytes[3] = source->bytes[3];
output->bytes[4] = source->bytes[4];
output->bytes[5] = source->bytes[5];
output->bytes[6] = source->bytes[6];
output->bytes[7] = source->bytes[7];
output->bytes[8] = source->bytes[8];
output->bytes[9] = source->bytes[9];
output->bytes[10] = source->bytes[10];
output->bytes[11] = source->bytes[11];
output->bytes[12] = source->bytes[12];
output->bytes[13] = source->bytes[13];
output->bytes[14] = source->bytes[14];
output->bytes[15] = source->bytes[15];
output->bytes[16] = source->bytes[16];
output->bytes[17] = source->bytes[17];
output->bytes[18] = source->bytes[18];
output->bytes[19] = source->bytes[19];
output->bytes[20] = source->bytes[20];
output->bytes[21] = source->bytes[21];
output->bytes[22] = source->bytes[22];
output->bytes[23] = source->bytes[23];
output->bytes[24] = source->bytes[24];
output->bytes[25] = source->bytes[25];
output->bytes[26] = source->bytes[26];
output->bytes[27] = source->bytes[27];
output->bytes[28] = source->bytes[28];
output->bytes[29] = source->bytes[29];
output->bytes[30] = source->bytes[30];
output->bytes[31] = source->bytes[31];
output->words[0] = source->words[0];
output->words[1] = source->words[1];
output->words[2] = source->words[2];
output->words[3] = source->words[3];
output->words[4] = source->words[4];
output->words[5] = source->words[5];
output->words[6] = source->words[6];
output->words[7] = source->words[7];
output->last = source->last;

config = (struct Config *)(base + 0x320);
active = (struct Config *)(base + 0x32C);
saved.words[0] = ((unsigned int *)config)[0];
saved.words[1] = ((unsigned int *)config)[1];
saved.words[2] = ((unsigned int *)config)[2];
config->value0 = active->value0;
config->value1 = active->value1;
config->flags[0] = active->flags[0];
config->flags[1] = active->flags[1];
config->flags[2] = active->flags[2];

result = fn_801A8E38();
row->floats[0] = snapshot.floats[0];
output->floats[1] = snapshot.floats[1];
output->floats[2] = snapshot.floats[2];
output->floats[3] = snapshot.floats[3];
output->floats[4] = snapshot.floats[4];
output->floats[5] = snapshot.floats[5];
output->floats[6] = snapshot.floats[6];
output->floats[7] = snapshot.floats[7];
output->bytes[0] = snapshot.bytes[0];
output->bytes[1] = snapshot.bytes[1];
output->bytes[2] = snapshot.bytes[2];
output->bytes[3] = snapshot.bytes[3];
output->bytes[4] = snapshot.bytes[4];
output->bytes[5] = snapshot.bytes[5];
output->bytes[6] = snapshot.bytes[6];
output->bytes[7] = snapshot.bytes[7];
output->bytes[8] = snapshot.bytes[8];
output->bytes[9] = snapshot.bytes[9];
output->bytes[10] = snapshot.bytes[10];
output->bytes[11] = snapshot.bytes[11];
output->bytes[12] = snapshot.bytes[12];
output->bytes[13] = snapshot.bytes[13];
output->bytes[14] = snapshot.bytes[14];
output->bytes[15] = snapshot.bytes[15];
output->bytes[16] = snapshot.bytes[16];
output->bytes[17] = snapshot.bytes[17];
output->bytes[18] = snapshot.bytes[18];
output->bytes[19] = snapshot.bytes[19];
output->bytes[20] = snapshot.bytes[20];
output->bytes[21] = snapshot.bytes[21];
output->bytes[22] = snapshot.bytes[22];
output->bytes[23] = snapshot.bytes[23];
output->bytes[24] = snapshot.bytes[24];
output->bytes[25] = snapshot.bytes[25];
output->bytes[26] = snapshot.bytes[26];
output->bytes[27] = snapshot.bytes[27];
output->bytes[28] = snapshot.bytes[28];
output->bytes[29] = snapshot.bytes[29];
output->bytes[30] = snapshot.bytes[30];
output->bytes[31] = snapshot.bytes[31];
output->words[0] = snapshot.words[0];
output->words[1] = snapshot.words[1];
output->words[2] = snapshot.words[2];
output->words[3] = snapshot.words[3];
output->words[4] = snapshot.words[4];
output->words[5] = snapshot.words[5];
output->words[6] = snapshot.words[6];
output->words[7] = snapshot.words[7];
output->last = snapshot.last;
config->value0 = saved.values[0];
config->value1 = saved.values[1];
config->flags[0] = saved.bytes[8];
config->flags[1] = saved.bytes[9];
config->flags[2] = saved.bytes[10];
return result;
}
#pragma pop

#pragma scheduling on
#pragma dont_inline fn_801A8E38
/* Return 1 when the control value from fn_801A7F98 exceeds the 0.2 press threshold. */
int fn_801A8E38(void) {
#define PRESS_THRESHOLD lbl_80562470  /* 0.2f */
    return fn_801A7F98() > PRESS_THRESHOLD;
#undef PRESS_THRESHOLD
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
int fn_801A8E68(void *trigger) {
    /* Rising-edge detector: for input types 1-6, report 1 once when the monitored analog input
     * crosses its threshold (fn_801A8E38), latching the +0xC flag until the input drops back. */
    int inputType = *(int *)trigger;
    unsigned char *latched = (unsigned char *)((char *)trigger + 0xC);
    switch (inputType) {
    case 1: case 2: case 3: case 4: case 5: case 6:
        if (fn_801A8E38() != 0) {
            if (*latched == 0) {
                *latched = 1;
                return 1;
            }
            break;
        }
        *latched = 0;
        return 0;
    default:
        break;
    }
    return 0;
}
#pragma dont_inline reset
#pragma pop
#define SUPPORTED_TYPE_MASK 0x2D /* bit (type-1) set for each supported binding/subobject type: 1, 3, 4, 6 */
int fn_801A8EE4(unsigned int *type) {
    /* Return 1 if the 1-based input/subobject type at `type` is one of the
     * supported types selected by SUPPORTED_TYPE_MASK; 0 otherwise. */
    unsigned int typeIndex = *type - 1;
    int isValid = 0;
    if (typeIndex > 5)
        goto done;
    if (!((1U << typeIndex) & SUPPORTED_TYPE_MASK))
        goto done;
    isValid = 1;
done:
    return isValid;
}
#pragma push
#pragma scheduling invalid_target
/* ControlExists: report whether the control described by `control` (input type,
 * device index, axis/button code) exists on that device, using the per-device
 * axis and button presence masks held in the control-state table. */
int fn_801A8F10(int *__restrict control) {
#define gControlState lbl_80435050
#define sUnhandledAxisMsg lbl_80334EE0
#define Panic Abend_Panic
    struct ControlFlags {
        unsigned int axisMask;   /* +0x00 one bit per analog axis/direction */
        unsigned int buttonMask; /* +0x04 one bit per digital button */
        unsigned int unk08;
        unsigned int unk0C;
    };
    struct ControlState {
        unsigned char pad[0x44];
        struct ControlFlags flags;
        unsigned char pad2[0x64 - 0x54];
    };
    extern char sUnhandledAxisMsg[];
    extern void Panic(const char *, ...);

    int inputType = control[0];
    int deviceIndex = control[1];
    struct ControlState *entry = &((struct ControlState *)gControlState)[deviceIndex];
    struct ControlFlags flags = entry->flags;

    if (inputType == 4) {
        return (flags.axisMask >> 15) & 1;
    }
    if (inputType == 3) {
        unsigned int button = flags.buttonMask & (1 << control[2]);
        return (unsigned int)(-button | button) >> 31;
    }
    if (inputType == 2) {
        unsigned int axis = control[2];
        switch (axis) {
        case 0:
        case 1:
        case 16:
        case 24:
            return flags.axisMask & 1;
        case 2:
        case 3:
        case 17:
        case 25:
            return (flags.axisMask >> 1) & 1;
        case 4:
        case 5:
        case 18:
        case 26:
            return (flags.axisMask >> 3) & 1;
        case 6:
        case 7:
        case 19:
        case 27:
            return (flags.axisMask >> 2) & 1;
        case 8:
        case 9:
        case 20:
        case 28:
            return (flags.axisMask >> 4) & 1;
        case 10:
        case 11:
        case 21:
        case 29:
            return (flags.axisMask >> 5) & 1;
        case 12:
        case 13:
        case 22:
        case 30:
            return (flags.axisMask >> 6) & 1;
        case 14:
        case 15:
        case 23:
        case 31:
            return (flags.axisMask >> 7) & 1;
        default:
            Panic(sUnhandledAxisMsg, control[2]);
            return 0;
        }
    }
    return (unsigned int)(-inputType | inputType) >> 31;
#undef gControlState
#undef sUnhandledAxisMsg
#undef Panic
}
extern void initInputBindings(void);
extern void fn_801A9110(void *, const char *);
extern void *fn_801A9234(const char *);
extern void fn_801A91B0(void *, const void *);
extern int stricmp(const char *, const char *);
extern const char *lbl_802F9588[];
extern const char **lbl_8055E5CC;
extern int lbl_8055E5D0;
extern char *strncpy(char *, const char *, unsigned int);
#define INPUT_BINDING_MAX_INDEX 0x15 /* highest valid index into the 22-entry input binding name table */

int fn_801A902C(void) {
    /* Lazily build the input-binding name table (initInputBindings) and return the highest valid binding index. */
    initInputBindings();
    return INPUT_BINDING_MAX_INDEX;
}

void fn_801A9050(void *arg0, int arg1) {
    volatile int zeros[8];
    const char **table = (const char **)lbl_802F9588;
    register int zero = 0;
    register int index = arg1 * 8;
    const char *name = *(const char **)((char *)table + index);
    zeros[0] = zero; zeros[1] = zero; zeros[2] = zero; zeros[3] = zero;
    zeros[4] = zero; zeros[5] = zero; zeros[6] = zero; zeros[7] = zero;
    ((void (*)(void *, const char *, int *))fn_801A9110)(arg0, name, (int *)zeros);
}

/* Copies the display name of the input binding matching keySpec into outName, truncating to maxLen and always NUL-terminating. */
void fn_801A90A4(char *outName, int maxLen, const char *keySpec) {
    const InputBinding *entry = (const InputBinding *)fn_801A9234(keySpec);
    if (entry != 0)
        strncpy(outName, entry->name, maxLen);
    else
        outName[0] = 0;
    outName[maxLen - 1] = 0;
}

#pragma push
#pragma scheduling invalid_target
/* Finds the input binding whose display name matches `name` in the table built
 * by initInputBindings and copies its type/value into `out` (via fn_801A91B0); if no
 * entry matches, clears out's type field to 0. */
void fn_801A9110(void *out, const char *name) {
    int entryOffset;
    int index;

    initInputBindings();
    index = 0;
    entryOffset = 0;
    for (; index < gInputBindingCount; index++) {
        if (stricmp(((const InputBinding *)((const char *)gInputBindingTable + entryOffset))->name, name) == 0) {
            fn_801A91B0(out, (const char *)gInputBindingTable + index * 0x18);
            return;
        }
        entryOffset += 0x18;
    }
    *(int *)out = 0;
}
#pragma pop
/* Copy an input binding (type at +8, payload at +0xC) from src into dst; type 1 stores payload as a byte, other handled types store it as an int. */
void fn_801A91B0(void *dst, const void *src) {
    int type = *(const int *)((const char *)src + 8);
    *(int *)dst = type;
    switch (type) {
    case 2:
        *(int *)((char *)dst + 8) = *(const int *)((const char *)src + 0xC);
        return;
    case 3:
        *(int *)((char *)dst + 8) = *(const int *)((const char *)src + 0xC);
        return;
    case 5:
        *(int *)((char *)dst + 8) = *(const int *)((const char *)src + 0xC);
        return;
    case 6:
        *(int *)((char *)dst + 8) = *(const int *)((const char *)src + 0xC);
        return;
    case 4:
        *(int *)((char *)dst + 8) = *(const int *)((const char *)src + 0xC);
        return;
    case 1:
        *(unsigned char *)((char *)dst + 8) = *(const int *)((const char *)src + 0xC);
        return;
    }
}

#pragma push
#pragma scheduling invalid_target
void *fn_801A9234(const char *arg0) {
    /* Find an input binding table entry matching the given key spec (type and value). */
    extern int lbl_8055E5D0;
    extern const char **lbl_8055E5CC;
    const char *entry;
    const char **base;
    int i;
    int count;
    int type;

    initInputBindings();
    count = *(volatile int *)&lbl_8055E5D0;
    i = 0;
    entry = (const char *)(base = *(const char **volatile *)&lbl_8055E5CC);
    for (; i < count; i++) {
        type = *(int *)arg0;
        if (type == *(int *)(entry + 8)) {
            switch (type) {
            case 4: goto check_word_b;
            case 2: goto check_word_a;
            case 3: goto check_word_c;
            case 5: goto check_word_d;
            case 6: goto check_word_e;
            case 1: goto check_byte;
            default: goto next;
            }
check_word_a:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_word_b:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_word_c:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_word_d:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_word_e:
            if (*(int *)(arg0 + 8) == *(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
            goto next;
check_byte:
            if (*(unsigned char *)(arg0 + 8) == (unsigned char)*(int *)(entry + 0xC))
                return (char *)base + i * 0x18;
        }
next:
        entry += 0x18;
    }
    return 0;
}
#pragma pop
