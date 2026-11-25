// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055CFA0, lbl_8055FB2C, lbl_8055FB30;
extern float lbl_804C1050[16];
extern float lbl_8055FB38;
extern float lbl_80564E50, lbl_80564E54, lbl_80564E60, lbl_80564E70, lbl_80564E78, lbl_80564E7C, lbl_80564E80, lbl_80564E84, lbl_80564E88;
extern void *fn_802C110C(int);
extern void *fn_802C120C(void);
extern float fn_80129DC4(int, float, float);
extern void *lbl_8055FB50;
extern char lbl_8034AFB8[];
extern char lbl_8034AFC8[];
extern char lbl_8034AFD8[];
extern int lbl_8055FB54;
int fn_8012C33C(void);
int fn_802CAC28(int, int);
void fn_802B52C0(void *);
int getTextureSlotTexObj(void *, int, int, int, void *);
int fn_802D9628(short, short, unsigned int);
/* No-op constructor for each 0x48-byte TreeHitRecord in the hit ring
 * (lbl_804C0E10): fn_8002F53C calls it once per element while fn_802C1BB4
 * builds the array, but the records need no per-element setup. */
void fn_802C1C28(void) {}

/* Intentionally empty no-op; one of a run of placeholder entry points kept in the table. */
void fn_802C1C2C(void) {}

/* Intentionally empty no-op; one of a run of placeholder entry points kept in the table. */
void fn_802C1C30(void) {}

#pragma push
#pragma processor 750
#pragma ppc_psq_save off
#pragma use_lmw_stmw off
void fn_802C1C34(void *arg0, void *obj, int slot) {
#pragma scheduling invalid_target
    typedef struct { int v[9]; } Block9;
    typedef struct { float v[3]; } Vec3;
    float pos[3], mat[9], vel[3], scale[3];
    int index, i;
    int *info, *data, *entry;
    int **list;
    float *recent;
    void *effect;
    float x, y;
    index = ((int (*)(void *))(*(int **)obj)[9])(obj) - lbl_8055CFA0;
    if (index < 0) return;
    if (index >= lbl_8055FB2C) return;
    info = fn_802C110C(index);
    list = (int **)lbl_8055FB30;
    data = list[index];
    if (data == 0) return;
    if (((int (*)(void *))(*(int **)obj)[8])(obj) == 0x3eb) {
        if (((float *)data)[10] < lbl_80564E70)
            ((void (*)(void *, int))(*(int **)obj)[6])(obj, 0);
        return;
    }
    if (((float *)data)[10] < lbl_80564E70) return;
    recent = &lbl_804C1050[slot * 2];
    if (index != *(int *)recent || lbl_80564E78 < lbl_8055FB38 - recent[1]) {
        float one = lbl_80564E54, zero = lbl_80564E50, bias = lbl_80564E80;
        if (*((unsigned char *)info + 0x28)) {
            entry = fn_802C120C();
            entry[1] = (int)data;
            list[index] = 0;
            entry[0] = index;
            *(Block9 *)(entry+2) = *(Block9 *)data;
            *(Vec3 *)(entry+11) = *(Vec3 *)(data+9);
            ((float *)entry)[17] = lbl_8055FB38;
            ((float *)entry)[14] = one;
            ((float *)entry)[15] = zero;
            ((float *)entry)[16] = zero;
        }
        if (info[15] > 0) {
            float one = lbl_80564E54, zero = lbl_80564E50, bias = lbl_80564E80;
            for (i=0; i<info[15]; i++) {
                effect = ((void **)info[13])[i];
                pos[0] = ((float *)data)[9]; pos[1] = ((float *)data)[10]; pos[2] = ((float *)data)[11];
                pos[0] += fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                pos[2] += fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                pos[1] += ((float *)info)[11];
                mat[0]=one; mat[1]=zero; mat[2]=zero;
                mat[3]=zero; mat[4]=one; mat[5]=zero;
                mat[6]=zero; mat[7]=zero; mat[8]=one;
                x = fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                y = bias + fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                vel[0] = fn_80129DC4(4, lbl_80564E7C, lbl_80564E60);
                vel[1]=y; vel[2]=x;
                x = fn_80129DC4(4, lbl_80564E84, lbl_80564E88);
                y = fn_80129DC4(4, lbl_80564E84, lbl_80564E88);
                scale[0] = fn_80129DC4(4, lbl_80564E84, lbl_80564E88);
                scale[1]=y; scale[2]=x;
                ((void (*)(void *, float *, float *, float *))(*(int **)effect)[10])(effect, mat, vel, scale);
            }
        }
    }
    *(int *)recent = index;
    recent[1] = lbl_8055FB38;
}
#pragma pop
void fn_802C1F80(int allocation) {
    /* No-op finalizer: receives an allocation header (userData - 4) but does nothing. */
}

#pragma dont_inline on
/* No-op finalizer: accepts an allocation-header pointer and intentionally does nothing (placeholder cleanup callback). */
void fn_802C1F84(int header) {}

/* No-op finalizer: accepts an allocation-header pointer (passed on by the
 * fn_802C2064 release callback) and intentionally does nothing. */
void fn_802C1F88(int header) {}

extern int lbl_8055FB28;
extern char lbl_8055CFC0[];
extern char lbl_8055CFC8[];
extern char lbl_804C0810[];
extern int strcmp(const char *, const char *);
__declspec(section ".sdata") extern char lbl_8055CFC0[];
__declspec(section ".sdata") extern char lbl_8055CFC8[];
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_802C1F8C(int unused, void *arg1) {
    /* Resolve arg1 to a named object and append arg1 to the matching entry's
     * item list in the global entry table (lbl_804C0810, count lbl_8055FB28). */
    class FirstInterface {
    public:
        virtual void *resolve();
    };
    class SecondInterface {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual char *getName(const char *, const char *);
    };
    struct Fn802CEntry {
        char pad[8];
        char name[0x2C];
        void **items;
        int unk38;
        int count;
        char tail[0x20];
    };
    struct Fn802CEntry *entry;
    char *objectName;
    int i;
    SecondInterface *object;
    FirstInterface *input;

    input = (FirstInterface *)arg1;
    object = (SecondInterface *)input->resolve();
    if (object != 0) {
        objectName = object->getName(lbl_8055CFC0, lbl_8055CFC8);
        entry = (struct Fn802CEntry *)lbl_804C0810;
        i = 0;
        while (i < lbl_8055FB28) {
            if (strcmp(objectName, entry->name) == 0) {
                volatile int *countPtr = (volatile int *)((char *)entry + 0x3C);
                void ** volatile *itemsPtr = (void ** volatile *)((char *)entry + 0x34);
                int count = *countPtr;
                void **items = *itemsPtr;
                items[count] = input;
                *countPtr = count + 1;
            }
            entry++;
            i++;
        }
    }
}
#pragma cplusplus off
#pragma pop

/* Release-callback wrapper: forward to the no-op finalizer fn_802C1F80 with the pointer backed up to its enclosing allocation header (userData - 4). */
void fn_802C2054(int userData) { fn_802C1F80(userData - 4); }

/* Release-callback wrapper: forward to the no-op finalizer fn_802C1F84 with the pointer backed up to its enclosing allocation header (userData - 4). */
void fn_802C205C(int userData) { fn_802C1F84(userData - 4); }

/* Release-callback wrapper: forward to the no-op finalizer fn_802C1F88 with the pointer backed up to its enclosing allocation header (userData - 4). */
void fn_802C2064(int userData) { fn_802C1F88(userData - 4); }

void fn_802C1F8C();
/* Release-callback wrapper: forward to fn_802C1F8C with the pointer backed up to its enclosing allocation header (userData - 4). */
void fn_802C206C(int userData) { fn_802C1F8C(userData - 4); }

/* Returns a handle for the given resource path if valid and initialized, or -2 on failure. */
int fn_802C2074(void *path) {
    int valid = 0;
    if (path != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28((int)path, 0);
    return -2;
}

static int fn_802C2074_noinline(void *arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28((int)arg0, 0);
    return -2;
}

static int fn_802C2074_noinline2(void *arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28((int)arg0, 0);
    return -2;
}

/* Closes/releases the handle stored at *handleSlot if it is valid (not -2), then marks the slot empty (-2). */
void fn_802C20DC(int *handleSlot) {
    int handle = *handleSlot;
    if (handle != -2) {
        fn_802CAC54(handle);
        *handleSlot = -2;
    }
}

/* Convert a world X/Y coordinate to a short road-opacity texture pixel index (coord/4 + 128). */
short fn_802C2120(int coord) {
    return (short)(((coord << 8) / 1024) + 0x80);
}

/* Load the road opacity texture, falling back to an alternate texture if the preferred one is unavailable. */
void fn_802C2138(void) {
    int handle;
    handle = fn_802C2074(lbl_8034AFB8);
    lbl_8055FB50 = (void *)handle;
    if (handle == -2) {
        lbl_8055FB50 = (void *)fn_802C2074(lbl_8034AFC8);
    }
}

void fn_802B52B4(void *);
#pragma dont_inline on
void fn_802C217C(void) {
#define roadOpacityTexHandle lbl_8055FB50
#define roadOpacityTexture lbl_8055FB54
    /* RealName: ReleaseRoadOpacity - release the road opacity texture handle and
     * free the texture descriptor object, clearing the descriptor global. */
    fn_802C20DC((int *)&roadOpacityTexHandle);
    if (roadOpacityTexture == 0) return;
    fn_802B52B4((void *)roadOpacityTexture);
    roadOpacityTexture = 0;
#undef roadOpacityTexHandle
#undef roadOpacityTexture
}
#pragma dont_inline reset
void* fn_802C21B8(void) {
#define roadOpacityTexHandle lbl_8055FB50
    /* RealName: GetRoadOpacityTexHandle - return the current road-opacity texture handle. */
    return roadOpacityTexHandle;
#undef roadOpacityTexHandle
}

void fn_802C21C0(void) {
    /* Reload the road-opacity texture from "roadopac.tga" if its descriptor is still allocated. */
#define roadOpacityTexture lbl_8055FB54
#define roadOpacityTga lbl_8034AFD8
    if (roadOpacityTexture != 0)
        ((int (*)(int, void *))fn_802B52C0)((int)roadOpacityTga, (void *)roadOpacityTexture);
#undef roadOpacityTexture
#undef roadOpacityTga
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_802C21DC(int worldX, int worldY, unsigned int value) {
#define roadOpacityTexHandle lbl_8055FB50
#define roadOpacityTexture   lbl_8055FB54
    /* Plot one pixel of the road-opacity image: replicate value's low byte into a
     * packed RGBA word, store it in the texture buffer, then pack its low nibble
     * into the matching texel of the uploaded texture. */
    typedef struct { int width; int height; unsigned int *pixels; } RoadOpacityTex;
    unsigned int byteLow; unsigned int byteHigh; unsigned int packedColor;
    short texX;
    short texY;
    register unsigned int *pixels;
    short texYCoord;
    short texXCoord;
    int height;
    int width;
    RoadOpacityTex *texture;
    int pixelIndex;
    int texObject;
    if (roadOpacityTexture != 0) {
        byteLow = ((value & 0xFF) << 8) | (value & 0xFF);
        byteHigh = ((value & 0xFF) << 24) | ((value & 0xFF) << 16);
        packedColor = byteLow | byteHigh;
        texX = fn_802C2120(worldX);
        texY = fn_802C2120(worldY);
        texture = (RoadOpacityTex *)roadOpacityTexture;
        texYCoord = texY;
        height = texture->height;
        texXCoord = texX;
        width = texture->width;
        pixels = (unsigned int *)texture->pixels;
        height = height - 1 - texYCoord;
        pixelIndex = height * width + texXCoord;
        pixels[pixelIndex] = packedColor;
        texObject = ((int (*)(int))getTextureSlotTexObj)((int)roadOpacityTexHandle);
        ((void (*)(void *, int, int, unsigned int))fn_802D9628)((void *)texObject, texX, texY, packedColor);
    }
#undef roadOpacityTexture
#undef roadOpacityTexHandle
}
#pragma pop
