#include <revolution/MTX/vec.h>
#include <revolution/MTX/quat.h>
#include <types.h>

// A named pool of "path" objects (props spawned along a track). The manager keeps
// up to 8 pools in a table at lbl_8055EC98 (pool count at +0x2C0). Each pool hands
// objects out from its unused[] list and tracks handed-out ones in inUse[].
struct PathPool {
    char name[0x10];  // +0x00: pool name, matched with stricmp
    void *unused[8];  // +0x10: objects available to hand out
    void *inUse[8];   // +0x30: objects currently handed out
    int unusedCount;  // +0x50
    int inUseCount;   // +0x54
};

struct PathPoolTable {
    PathPool pools[8];
    int poolCount;    // +0x2C0
};

// One entry of a path spawner's list (the spawner object keeps 4 of them at +4,
// count at +0x94; fn_801FE88C fills one from the archive). fn_801FEDA4 spawns a
// prop from the pool named here, fn_801FEC74 hands it back.
struct PathSpawnEntry {
    void *source;          // +0x00: object to place the prop at (position +0x10, quaternion +0x1C)
    char poolName[0x10];   // +0x04: pool the prop is taken from, matched with stricmp
    unsigned short mode;   // +0x14: 0 = spawn every frame, 1 = spawn on a timer
    unsigned short endBehavior;  // +0x16: PathEndBehavior, what a drone does at the last node
    float minDelay;        // +0x18: timer range, low end
    float maxDelay;        // +0x1C: timer range, high end
    float nextSpawn;       // +0x20: time the next prop is due
};

// PathSpawnEntry::endBehavior: what a drone does when it runs off the end of
// its path; the drone updater picks its per-frame walker with it.
enum PathEndBehavior {
    PATH_END_LOOP = 0,    // wrap back to the first node and keep going
    PATH_END_REVERSE = 1, // run the node list backwards (ping-pong)
    PATH_END_STOP = 2     // hand the prop back to its pool at the last node
};

// One drone path segment of the larger "DroneManager" (name string
// lbl_8033B86C); fn_801FCA54 builds one from a spawn record.
struct DronePath {
    char *name;        // +0x00: pool name, matched with stricmp
    int unk04;         // +0x04: cleared
    void *source;      // +0x08: object the segment hangs off (record +4)
    float mtx[12];     // +0x0C: transform, starts as the identity
    int index;         // +0x3C: -1 until the segment is placed
};

// The larger "DroneManager" fn_801FEEC0 builds: up to 64 drone path segments
// from +4 with the count at +0x1004, and a table of up to 8 named pools at
// +0x1008 (its own count at +0x4C0) that each file the segments under their
// name (fn_801FF7D4). fn_801FF014 builds a smaller one: 32 segments of 0x70
// bytes, count at +0xE04, pools at +0xE08 (the PathPoolTable above).
struct DroneManager {
    void *vtable;              // +0x000
    struct DronePath path[64]; // +0x004
    int pathCount;             // +0x1004: segments in use, limit 64
};                             // +0x1008: the pool table follows

#define DMGR_PATH_COUNT(m) (*(int *)((char *)(m) + 0x1004)) /* DroneManager::pathCount */
#define DMGR_PATH(m, i)    ((char *)(m) + ((i) << 6) + 4)   /* &DroneManager::path[i] */
#define DMGR_POOLS(m)      ((char *)(m) + 0x1008)           /* the manager's pool table */
#define DMGR_PATH_MAX      0x40                             /* segments per manager */
#define STR_PATH_DRONE_LIMIT lbl_8033B8C8 /* "path: exceeded total drone limit" */
#define STR_PATH_END_BEHAVIOR lbl_8033B618 /* "path: unknown end behavior %d." */
extern "C" void fn_801FEA28(void*);
class SHMainMenu { public: ~SHMainMenu(); };
extern "C" {
extern void* lbl_8055EC98;
extern void* lbl_8055EC94;
extern const char lbl_8033B5D8[];
extern const char lbl_8033B638[];
extern const char lbl_8033B8C8[];
extern const char lbl_8033B8EC[];
extern const char lbl_8033B7F0[];
extern const char lbl_8033B820[];
extern const char lbl_8033B90C[];
void fn_80128668(void*);
#define Mem_freeObject fn_80128668 /* frees a game object through the pool allocator */
void fn_801FEDA4(void*);
float fn_80129DC4(int, void*, float, float);
extern float lbl_80563034;
extern const char lbl_8033B790[];
void* memset(void*, int, unsigned long);
void fn_801FF5D4(void*, void*, float);
void fn_801FCA54(void*, int, int);
void fn_801FF7D4(void*, void*);
void fn_801FF8DC(void*, void*, int);
void fn_802E317C(const char*, ...);
void fn_801FCF18(void*, int, int);
void fn_801FF484(void*, void*);
float fn_801E7E24(void);
extern float lbl_80558DC4;
void fn_801FF6FC(void*, float);
void fn_801FF3AC(void*, float);
    float fabs(float);
    void fn_801FF770(void*);
          void* fn_801FCED8(void*, int);
    void* fn_801284F8(int, const char*);
    void fn_8002F53C(void*, void*, void*, int, int);
    void fn_801FF1C4(void*, int, int);
    void fn_801FF6A4(void*);
    void fn_802CD320(int, void*);
    void fn_801FF2B8(void*, int, int);
    void fn_801FF0D4(void*);
    void fn_801FEF80(void*);
          void* fn_801FCA14(void*, int);
          extern char lbl_8033B608[];
      extern const char lbl_8033B86C[];
    extern const char lbl_8033B898[];
      extern const char lbl_8033B880[];
    extern const char lbl_8033B730[];
  extern const char lbl_8033B5E8[];
        }
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" const char lbl_8033B700[];
extern "C" float lbl_80563030;
extern "C" float lbl_80563034;
extern "C" float lbl_80563038;
extern "C" float lbl_8056303C;
extern "C" float lbl_80563040;
extern "C" float lbl_80563044;
extern "C" void fn_801FD3F0(void*, float);

extern "C" void fn_801FD5E8(void* = 0, float = 0);
extern "C" void fn_801FDF18(void*, float);
extern "C" void fn_801FEC74(void*);
extern "C" void fn_802E317C(const char*, ...);
extern "C" const char lbl_8033B618[];
extern "C" float fn_802C99E8(float);
extern "C" void fn_802C744C(void*, void*);
  #pragma scheduling invalid_target
/* Allocate and construct an 8-byte HermiteDroneTMH object with its vtable and a zeroed field at +4. */
extern "C" void fn_801FC9CC(void) {
    void *object = fn_801284F8(8, (const char *)&lbl_8033B608);
    if (object != 0) {
        *(void **)object = (void *)&lbl_8033B700[0];
        *(int *)((char *)object + 4) = 0;
    }
}
#pragma push
#pragma small_data off
extern "C" void* fn_801FE188(void*);
extern "C" void fn_801FC914(void) {
    /* Allocate a 0x38-byte LinearPathTMH object and install its vtable through fn_801FE188. */
    void *path = fn_801284F8(0x38, lbl_8033B5D8);
    if (path != 0) {
        fn_801FE188(path);
    }
}

extern "C" void fn_801FC94C(void) {
    /* Allocate and construct an 8-byte LinearDroneTMH object with its vtable and a zeroed field at +4. */
    void *p;
    if ((p = fn_801284F8(8, (const char *)&lbl_8033B5E8)) != 0) {
        *(void **)p = (void *)&lbl_8033B730;
        *(int *)((char *)p + 4) = 0;
    }
}

extern "C" const char lbl_8033B5F8[];
extern "C" void fn_801FE550(void *);
extern "C" void fn_801FC994(void) {
    /* Allocate the 0x98-byte "HermitePathTMH" object and install its vtable through fn_801FE550. */
    void *path = fn_801284F8(0x98, lbl_8033B5F8);
    if (path != 0) {
        fn_801FE550(path);
    }
}

#pragma pop

void* fn_801FCA14(void* object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668(object);
    }
    return object;
}

extern "C" void fn_801FCA54(void* arg0, int arg1, int arg2) {
    /* Initialize a DronePath segment from a spawn record: set its pool name and
     * source object, clear state, install an identity transform, and mark it
     * unplaced (index -1). */
    float zero;
    float one;
    zero = lbl_80563034;
    one = lbl_80563030;
    int source = *(int*)((char*)arg1 + 4);
    *(int*)((char*)arg0 + 0) = arg2;
    *(int*)((char*)arg0 + 4) = 0;
    *(int*)((char*)arg0 + 8) = source;
    *(float*)((char*)arg0 + 0xc) = one;
    *(float*)((char*)arg0 + 0x10) = zero;
    *(float*)((char*)arg0 + 0x14) = zero;
    *(float*)((char*)arg0 + 0x18) = zero;
    *(float*)((char*)arg0 + 0x1c) = one;
    *(float*)((char*)arg0 + 0x20) = zero;
    *(float*)((char*)arg0 + 0x24) = zero;
    *(float*)((char*)arg0 + 0x28) = zero;
    *(float*)((char*)arg0 + 0x2c) = one;
    *(float*)((char*)arg0 + 0x30) = zero;
    *(float*)((char*)arg0 + 0x34) = zero;
    *(float*)((char*)arg0 + 0x38) = zero;
    *(int*)((char*)arg0 + 0x3C) = -1;
}

extern "C" void fn_801FCB40(void*, float);
#pragma dont_inline on
extern "C" void fn_801FCAAC(void* drone, float dt) {
    /* Advance an active path drone along its path by dt; do nothing when it
       has no path (the state pointer at +4 is null). */
    if (*(void**)((char*)drone + 4) != 0) {
        fn_801FCB40(drone, dt);
    }
}
#pragma dont_inline reset

extern "C" void fn_801FCAC0(void* object) {
    /* For an active path drone (state pointer at +4), submit the model handle at
     * +8 for drawing with the embedded transform matrix at +0xC. */
    if (*(void**)((char*)object + 4) != 0) {
        fn_802C744C(*(void**)((char*)object + 8), (char*)object + 0xC);
    }
}

extern "C" void fn_801FCAE0(void* arg0, void* arg1) {
    /* Initialize a path/transform slot: bind it to source, reset index, set identity matrix, and copy source position. */
    float zero = lbl_80563034;
    float one = lbl_80563030;
    *(void**)((char*)arg0 + 4) = arg1;
    *(int*)((char*)arg0 + 0x3C) = 0;
    *(float*)((char*)arg0 + 0xC) = one;
    *(float*)((char*)arg0 + 0x10) = zero;
    *(float*)((char*)arg0 + 0x14) = zero;
    *(float*)((char*)arg0 + 0x18) = zero;
    *(float*)((char*)arg0 + 0x1C) = one;
    *(float*)((char*)arg0 + 0x20) = zero;
    *(float*)((char*)arg0 + 0x24) = zero;
    *(float*)((char*)arg0 + 0x28) = zero;
    *(float*)((char*)arg0 + 0x2C) = one;
    *(float*)((char*)arg0 + 0x30) = zero;
    *(float*)((char*)arg0 + 0x34) = zero;
    *(float*)((char*)arg0 + 0x38) = zero;
    *(float*)((char*)arg0 + 0x30) = *(float*)((char*)arg1 + 0x10);
    *(float*)((char*)arg0 + 0x34) = *(float*)((char*)arg1 + 0x14);
    *(float*)((char*)arg0 + 0x38) = *(float*)((char*)arg1 + 0x18);
}

#pragma push
#pragma processor 750
extern "C" void fn_801FCB40(void* arg0, float farg0) {
    char* a = (char*)arg0;
    float delta = farg0;
    int count = *(int*)(a + 0x3C);
    char* item = *(char**)(a + 4) + (count << 5);
    float* q = (float*)(a + 0x30);
    float* q0 = (float*)(item + 0x10);
    float* q1 = (float*)(item + 0x30);
    Vec dir;
    dir.x = q1[0] - q0[0]; dir.y = q1[1] - q0[1]; dir.z = q1[2] - q0[2];
    float mag = PSVECMag(&dir);
    float inv = lbl_80563030 / mag;
    float t = inv * ((float (*)(const void *, const void *))PSQUATMultiply)(a + 0x30, q0);
    float s = inv * (delta * (q0[6] + t * (q0[7] - q0[6])));
    Vec pos;
    pos.x = q[0] + dir.x * s;
    pos.y = q[1] + dir.y * s;
    pos.z = q[2] + dir.z * s;
    Vec d;
    d.x = q1[0] - pos.x;
    d.y = q1[1] - pos.y;
    d.z = q1[2] - pos.z;
    if (PSVECDotProduct(&dir, &d) <= lbl_80563034) {
        count = *(int*)(a + 0x3C) + 1;
        *(int*)(a + 0x3C) = count;
        char *base = *(char**)(a + 4);
        int max = *(int*)(base + 0x310);
        if (count >= max - 1) {
            fn_801FEA28(arg0);
            *(int*)(a + 4) = 0;
            return;
        }
        item = base + (count << 5);
        q0 = q1;
        q1 = (float*)(item + 0x30);
        dir.x = q1[0] - q0[0];
        dir.y = q1[1] - q0[1];
        dir.z = q1[2] - q0[2];
        mag = PSVECMag(&dir);
        inv = lbl_80563030 / mag;
        float k = inv * PSVECMag(&d);
        q[0] = q0[0] + dir.x * k;
        q[1] = q0[1] + dir.y * k;
        q[2] = q0[2] + dir.z * k;
    }
    else { q[0] = pos.x; q[1] = pos.y; q[2] = pos.z; }
    count = *(int*)(a + 0x3C) + 2;
    if (count < *(int*)(*(char**)(a + 4) + 0x310)) {
        item = *(char**)(a + 4) + (count << 5);
        float* q2 = (float*)(item + 0x10);
        Vec v;
        v.x = q2[0] - q1[0];
        v.y = q2[1] - q1[1];
        v.z = q2[2] - q1[2];
        float t = inv * ((float (*)(const void *, const void *))PSQUATMultiply)(a + 0x30, q0);
        float* p = (float*)(a + 0xC);
        Vec up;
        float ux = q1[3] - q0[3];
        float uz = q1[5] - q0[5];
        float uy = q1[4] - q0[4];
        up.z = q0[5] + t * uz;
        up.y = q0[4] + t * uy;
        up.x = q0[3] + t * ux;
        *(Vec*)p = up;
        Vec n;
        n.z = dir.z + t * (v.z - dir.z);
        n.y = dir.y + t * (v.y - dir.y);
        n.x = dir.x + t * (v.x - dir.x);
        *(Vec*)(a + 0x24) = n;
        PSVECNormalize((Vec*)(a + 0x24), (Vec*)(a + 0x24));
    } else {
        float* p = (float*)(a + 0xC);
        p[0] = q0[3];
        p[1] = q0[4];
        p[2] = q0[5];
        *(float*)(a + 0x24) = dir.x * inv;
        *(float*)(a + 0x28) = dir.y * inv;
        *(float*)(a + 0x2C) = dir.z * inv;
    }
    PSVECCrossProduct((const Vec*)(a + 0x24), (const Vec*)(a + 0xC), (Vec*)(a + 0x18));
}
#pragma pop
extern "C" void* fn_801FCED8(void* object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668(object);
    }
    return object;
}

extern "C" void fn_801FCF18(void* arg0, int arg1, int arg2) {
    /* Initialize a DronePath with the given pool name and source id and an identity transform. */
    float zero;
    float one;
    struct DronePath* path = (struct DronePath*)arg0;
    zero = lbl_80563034;
    one = lbl_80563030;
    int sourceId = *(int*)(arg1 + 4);
    *(int*)((char*)path + 0) = arg2;
    *(int*)((char*)path + 4) = 0;
    *(int*)((char*)path + 8) = sourceId;
    *(float*)((char*)path + 0xc) = one;
    *(float*)((char*)path + 0x10) = zero;
    *(float*)((char*)path + 0x14) = zero;
    *(float*)((char*)path + 0x18) = zero;
    *(float*)((char*)path + 0x1c) = one;
    *(float*)((char*)path + 0x20) = zero;
    *(float*)((char*)path + 0x24) = zero;
    *(float*)((char*)path + 0x28) = zero;
    *(float*)((char*)path + 0x2c) = one;
    *(float*)((char*)path + 0x30) = zero;
    *(float*)((char*)path + 0x34) = zero;
    *(float*)((char*)path + 0x38) = zero;
    *(int*)((char*)path + 0x3C) = -1;
    *(float*)((char*)path + 0x40) = zero;
}

/* Advance one path drone along its path by dt, using the end behavior its spawn
 * entry asked for: 0 loops back to the first node, 1 runs the node list
 * backwards, 2 walks off the end and hands the prop back to its pool. A null
 * entry is a drone that already retired, so it is skipped. */
extern "C" void fn_801FCF74(void *drone, float dt) {
    PathSpawnEntry *entry = *(PathSpawnEntry **)((char *)drone + 4);
    if (entry == 0)
        return;
    int endBehavior = *(unsigned short *)((char *)entry + 0x16);
    switch (endBehavior) {
    case PATH_END_LOOP:
        return ((void (*)(void *, int))fn_801FD3F0)(drone, endBehavior);
    case PATH_END_REVERSE:
        return ((void (*)(void *, int, float))fn_801FD5E8)(drone, endBehavior, dt);
    case PATH_END_STOP:
        return ((void (*)(void *, int))fn_801FDF18)(drone, endBehavior);
    default:
        return fn_802E317C((const char *)STR_PATH_END_BEHAVIOR);
    }
}

#pragma push
#pragma processor 750
extern "C" void fn_801FCFC8(void *obj) {
    /* If the object is active, save its float field, apply its transform, then restore it. */
    if (*(int *)((char *)obj + 4) != 0) {
        float savedValue = fn_802C99E8(*(float *)((char *)obj + 0x6C));
        fn_802C744C(*(void **)((char *)obj + 8), (char *)obj + 0xC);
        fn_802C99E8(savedValue);
    }
}
extern float lbl_80563030;
extern "C" void fn_801FD024(void* arg0, void* arg1) {
    char* dst = (char*)arg0;
    float initial = lbl_80563034;
    *(void**)(dst + 4) = arg1;
    void* src = *(void**)arg1;
    *(int*)(dst + 0x3C) = 0;
    register float one = lbl_80563030;
    *(float*)(dst + 0x40) = initial;
    *(float*)(dst + 0x44) = *(float*)((char*)src + 0x1C);
    *(float*)(dst + 0x48) = *(float*)((char*)src + 0x20);
    *(float*)(dst + 0x4C) = *(float*)((char*)src + 0x24);
    *(float*)(dst + 0x50) = *(float*)((char*)src + 0x28);
    *(float*)(dst + 0x54) = *(float*)((char*)src + 0x40);
    *(float*)(dst + 0x58) = *(float*)((char*)src + 0x44);
    *(float*)(dst + 0x5C) = *(float*)((char*)src + 0x48);
    *(float*)(dst + 0x60) = *(float*)((char*)src + 0x4C);
    float w0 = *(float*)((char*)src + 0x2C);
    *(float*)(dst + 0x64) = w0;
    *(float*)(dst + 0x68) = *(float*)((char*)src + 0x50);
    *(float*)(dst + 0x6C) = w0;
    *(float*)(dst + 0x30) = *(float*)((char*)src + 0x10);
    *(float*)(dst + 0x34) = *(float*)((char*)src + 0x14);
    *(float*)(dst + 0x38) = *(float*)((char*)src + 0x18);
    volatile float* quat = (volatile float*)((char*)src + 0x1C);
    register float x, y, z, w;
    x = quat[0];
    y = quat[1];
    z = quat[2];
    register float z2, y2, x2;
    x2 = x + x;
    y2 = y + y;
    w = quat[3];
    z2 = z + z;
    register float zz, yy, xx;
    xx = x * x2;
    yy = y * y2;
    zz = z * z2;
    float xw = w * x2;
    float yz = y * z2;
    float sum0 = yy + zz;
    float sum1 = xx + zz;
    float sum2 = xx + yy;
    float m00 = one - sum0;
    float m11 = one - sum1;
    float m22 = one - sum2;
    float m12 = yz - xw;
    *(float*)(dst + 0xC) = m00;
    float m21 = yz + xw;
    float yw = w * y2;
    float xz = x * z2;
    float zw = w * z2;
    *(float*)(dst + 0x1C) = m11;
    float xy = x * y2;
    float m24 = xz + yw;
    float m14 = xz - yw;
    float m18 = xy - zw;
    float m10 = xy + zw;
    *(float*)(dst + 0x28) = m12;
    *(float*)(dst + 0x24) = m24;
    *(float*)(dst + 0x18) = m18;
    *(float*)(dst + 0x10) = m10;
    *(float*)(dst + 0x14) = m14;
    *(float*)(dst + 0x20) = m21;
    *(float*)(dst + 0x2C) = m22;
}

#pragma processor 750
extern "C" void fn_801FD144(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, float farg0) {
    Vec dA;
    Vec dB;
    Vec *a = (Vec *)arg3;
    Vec *b = (Vec *)arg2;
    if (arg1 != 0) {
        Vec *prev = (Vec *)arg1;
        dA.x = a->x - prev->x;
        dA.y = a->y - prev->y;
        dA.z = a->z - prev->z;
    } else {
        dA.x = a->x - b->x;
        dA.y = a->y - b->y;
        dA.z = a->z - b->z;
    }
    if (arg4 != 0) {
        Vec *next = (Vec *)arg4;
        dB.x = next->x - b->x;
        dB.y = next->y - b->y;
        dB.z = next->z - b->z;
    } else {
        dB.x = a->x - b->x;
        dB.y = a->y - b->y;
        dB.z = a->z - b->z;
    }
    float t2 = farg0 * farg0;
    float t3 = farg0 * t2;
    float c38 = lbl_80563038;
    float c40 = lbl_80563040;
    float h01helper = lbl_8056303C * t2;
    float h00 = lbl_80563030 + (c38 * t3 - h01helper);
    float h10 = c40 * (farg0 + (t3 - c38 * t2));
    float h01 = c40 * (t3 - t2);
    float c44t3 = lbl_80563044 * t3;
    float bx = b->x, by = b->y, bz = b->z;
    float dax = dA.x, day = dA.y, daz = dA.z;
    float dbx = dB.x, dby = dB.y, dbz = dB.z;
    float ax = a->x, ay = a->y, az = a->z;
    float h11 = c44t3 + h01helper;
    float sx = (bx*h00 + dax*h10) + dbx*h01;
    float sy = (by*h00 + day*h10) + dby*h01;
    float sz = (bz*h00 + daz*h10) + dbz*h01;
    float px = sx + ax*h11;
    float py = sy + ay*h11;
    float pz = sz + az*h11;
    ((float *)arg0)[12] = px;
    ((float *)arg0)[13] = py;
    ((float *)arg0)[14] = pz;
}
extern "C" double cos(double);
extern "C" double sin(double);
extern "C" double fn_8002F234(float);
extern "C" float fn_80144514(float, float, float, float, float, float);
extern "C" void fn_801FD144(void*, void*, void*, void*, void*, float);
extern "C" float lbl_80563040;
extern "C" double lbl_80563048;

static inline char* GetTrackNode(char* track, int idx) {
    int count = *(int*)(track + 0x6D0);
    if (idx >= count && idx < count * 2) {
        return track + 0x10 + (count * 2 - idx - 1) * 0x24;
    }
    if (idx >= 0) {
        return track + 0x10 + (idx % count) * 0x24;
    }
    return track + 0x10 + (-idx) * 0x24;
}

static inline char* GetTrackNodeLinear(char* track, int idx) {
    if (idx >= 0 && idx < *(int*)(track + 0x6D0)) {
        return track + 0x10 + idx * 0x24;
    }
    return 0;
}

static inline void MatrixMul801FD5E8(float* dst, const float* left, const float* right) {
    if (dst == right || dst == left) {
        float t0 = fn_80144514(left[0], right[0], left[3], right[1], left[6], right[2]);
        float t3 = fn_80144514(left[0], right[3], left[3], right[4], left[6], right[5]);
        float t6 = fn_80144514(left[0], right[6], left[3], right[7], left[6], right[8]);
        float t1 = fn_80144514(left[1], right[0], left[4], right[1], left[7], right[2]);
        float t4 = fn_80144514(left[1], right[3], left[4], right[4], left[7], right[5]);
        float t7 = fn_80144514(left[1], right[6], left[4], right[7], left[7], right[8]);
        float t2 = fn_80144514(left[2], right[0], left[5], right[1], left[8], right[2]);
        float t5 = fn_80144514(left[2], right[3], left[5], right[4], left[8], right[5]);
        float t8 = fn_80144514(left[2], right[6], left[5], right[7], left[8], right[8]);
        dst[0] = t0;
        dst[3] = t3;
        dst[6] = t6;
        dst[1] = t1;
        dst[4] = t4;
        dst[7] = t7;
        dst[2] = t2;
        dst[5] = t5;
        dst[8] = t8;
    } else {
        dst[0] = fn_80144514(left[0], right[0], left[3], right[1], left[6], right[2]);
        dst[3] = fn_80144514(left[0], right[3], left[3], right[4], left[6], right[5]);
        dst[6] = fn_80144514(left[0], right[6], left[3], right[7], left[6], right[8]);
        dst[1] = fn_80144514(left[1], right[0], left[4], right[1], left[7], right[2]);
        dst[4] = fn_80144514(left[1], right[3], left[4], right[4], left[7], right[5]);
        dst[7] = fn_80144514(left[1], right[6], left[4], right[7], left[7], right[8]);
        dst[2] = fn_80144514(left[2], right[0], left[5], right[1], left[8], right[2]);
        dst[5] = fn_80144514(left[2], right[3], left[5], right[4], left[8], right[5]);
        dst[8] = fn_80144514(left[2], right[6], left[5], right[7], left[8], right[8]);
    }
}

extern "C" void fn_8012F57C(float*, void*, void*, float);
extern "C" float lbl_80563030;
#pragma scheduling invalid_target
extern "C" void fn_801FD320(void* arg0, float t) {
    float q[4];
    fn_8012F57C(q, (char*)arg0 + 0x44, (char*)arg0 + 0x54, t);
    volatile float* pq = q;
    register float x, y, z, w;
    x = pq[0];
    y = pq[1];
    z = pq[2];
    register float z2, y2, x2;
    x2 = x + x;
    y2 = y + y;
    w = pq[3];
    z2 = z + z;
    register float zz, yy, xx;
    xx = x * x2;
    yy = y * y2;
    zz = z * z2;
    float wx = w * x2;
    float yz = y * z2;
    float sum0 = yy + zz;
    float sum1 = xx + zz;
    float sum2 = xx + yy;
    float one = lbl_80563030;
    float r0 = one - sum0;
    float r1 = one - sum1;
    float r2 = one - sum2;
    float m28 = yz - wx;
    *(float*)((char*)arg0 + 0xC) = r0;
    float m20 = yz + wx;
    float wy = w * y2;
    float xz = x * z2;
    float wz = w * z2;
    *(float*)((char*)arg0 + 0x1C) = r1;
    float xy = x * y2;
    float m24 = xz + wy;
    float m14 = xz - wy;
    float m18 = xy - wz;
    float m10 = xy + wz;
    *(float*)((char*)arg0 + 0x28) = m28;
    *(float*)((char*)arg0 + 0x24) = m24;
    *(float*)((char*)arg0 + 0x18) = m18;
    *(float*)((char*)arg0 + 0x10) = m10;
    *(float*)((char*)arg0 + 0x14) = m14;
    *(float*)((char*)arg0 + 0x20) = m20;
    *(float*)((char*)arg0 + 0x2C) = r2;
}

#pragma push
#pragma processor 750
extern "C" void fn_801FD3F0(void* arg0, float farg0) {
    char* obj = (char*)arg0;
    char** slot = *(char***)(obj + 4);
    register float old_pos = *(float*)(obj + 0x40);
    char* track = *(char* volatile*)slot;
    register int index = *(int*)(obj + 0x3C);
    register float pos = old_pos + farg0;
    register int count = *(int*)(track + 0x6D0);
    char* nodes = track + 0x10;
    char* node = nodes + ((count + index) % count) * 0x24;
    float length = *(float*)(node + 0x20);
    register float step = length * pos;
    register float one = lbl_80563030;
    if (step < one) {
        *(float*)(obj + 0x40) = pos;
    } else {
        float inv_length = one / length;
        index++;
        float old54 = *(float*)(obj + 0x54);
        float old58 = *(float*)(obj + 0x58);
        float old5c = *(float*)(obj + 0x5C);
        float delta = farg0 - inv_length;
        float old60 = *(float*)(obj + 0x60);
        float old68 = *(float*)(obj + 0x68);
        step -= one;
        *(float*)(obj + 0x40) = old_pos + delta;
        count = *(volatile int*)(track + 0x6D0);
        index %= count;
        *(int*)(obj + 0x3C) = index;
        *(float*)(obj + 0x44) = old54;
        *(float*)(obj + 0x48) = old58;
        *(float*)(obj + 0x4C) = old5c;
        *(float*)(obj + 0x50) = old60;
        *(float*)(obj + 0x64) = old68;
        char* track2 = *(char* volatile*)slot;
        nodes = track2 + 0x10;
        node = nodes + ((count + index) % count) * 0x24;
        char* end_node = nodes + ((count + index + 1) % count) * 0x24;
        *(float*)(obj + 0x54) = *(float*)(end_node + 0x1C);
        *(float*)(obj + 0x58) = *(float*)(end_node + 0x20);
        *(float *)(obj + 0x5C) = *(float*)(end_node + 0x24);
        *(float*)(obj + 0x60) = *(float*)(end_node + 0x28);
        *(float*)(obj + 0x68) = *(float*)(end_node + 0x2C);
    }
    char* call_track = *(char* volatile*)slot;
    int call_count = *(int*)(call_track + 0x6D0);
    char* call_nodes = call_track + 0x10;
    int base = call_count + index;
    char* prev = call_nodes + ((base - 1) % call_count) * 0x24;
    char* next = call_nodes + ((base + 1) % call_count) * 0x24;
    char* next2 = call_nodes + ((base + 2) % call_count) * 0x24;
    fn_801FD144(arg0, prev, node, next, next2, step);
    fn_801FD320(arg0, step);
    float end = *(float*)(obj + 0x68);
    float begin = *(float*)(obj + 0x64);
    float difference = end - begin;
    float result = begin + step * difference;
    *(float*)(obj + 0x6C) = result;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_801FD5E8(void* arg0, float farg0) {
    char* obj = (char*)arg0;
    void* inner = *(void**)(obj + 4);
    int idx = *(int*)(obj + 0x3C);
    char* track = *(char**)inner;
    char* node = GetTrackNode(track, idx);

    float speed = *(float*)(node + 0x20);
    float t_step = *(float*)(obj + 0x40) + farg0;
    float step = speed * t_step;

    if (step < lbl_80563030) {
        *(float*)(obj + 0x40) = t_step;
    } else {
        step -= lbl_80563030;
        int cur_idx = *(int*)(obj + 0x3C);
        void* in = *(void**)(obj + 4);
        int next_idx = cur_idx + 1;
        *(float*)(obj + 0x40) = *(float*)(obj + 0x40) + (farg0 - lbl_80563030 / speed);

        int wrap = *(int*)(track + 0x6D0) * 2;
        idx = next_idx % wrap;
        *(int*)(obj + 0x3C) = idx;

        node = GetTrackNode(*(char**)in, idx);

        *(float*)(obj + 0x44) = *(float*)(obj + 0x54);
        *(float*)(obj + 0x48) = *(float*)(obj + 0x58);
        int next_i = *(int*)(obj + 0x3C) + 1;
        *(float*)(obj + 0x4C) = *(float*)(obj + 0x5C);
        *(float*)(obj + 0x50) = *(float*)(obj + 0x60);
        *(float*)(obj + 0x64) = *(float*)(obj + 0x68);

        void* in2 = *(void**)(obj + 4);
        char* next_node = GetTrackNode(*(char**)in2, next_i);
        *(float*)(obj + 0x54) = *(float*)(next_node + 0xC);
        int next_i2 = *(int*)(obj + 0x3C) + 1;
        *(float*)(obj + 0x58) = *(float*)(next_node + 0x10);
        *(float*)(obj + 0x5C) = *(float*)(next_node + 0x14);
        *(float*)(obj + 0x60) = *(float*)(next_node + 0x18);

        void* in3 = *(void**)(obj + 4);
        char* next2_node = GetTrackNode(*(char**)in3, next_i2 + 1);
        *(float*)(obj + 0x68) = *(float*)(next2_node + 0x1C);

        int turn_idx = *(int*)(obj + 0x3C) + 1;
        int count = *(int*)(track + 0x6D0);
        if (turn_idx >= count && turn_idx < count * 2) {
            float qx = *(float*)(obj + 0x54);
            float qy = *(float*)(obj + 0x58);
            float qz = *(float*)(obj + 0x5C);
            float y2 = qy + qy;
            float qw = *(float*)(obj + 0x60);
            float z2 = qz + qz;
            float x2 = qx + qx;
            float yy = qy * y2;
            float xx = qx * x2;
            float zz = qz * z2;
            float wx = qw * x2;
            float yz = qy * z2;

            float m[9];
            m[0] = lbl_80563030 - (yy + zz);
            m[4] = lbl_80563030 - (xx + zz);
            m[8] = lbl_80563030 - (xx + yy);

            float wy = qw * y2;
            float xz = qx * z2;
            float wz = qw * z2;
            float xy = qx * y2;

            m[7] = yz - wx;
            m[5] = yz + wx;
            m[6] = xz + wy;
            m[2] = xz - wy;
            m[1] = xy + wz;
            m[3] = xy - wz;

            float rot[9];
            float cos_val = (float)cos(lbl_80563048);
            float sin_val = (float)sin(lbl_80563048);
            rot[0] = cos_val;
            rot[1] = lbl_80563034;
            rot[2] = -sin_val;
            rot[3] = lbl_80563034;
            rot[4] = lbl_80563030;
            rot[5] = lbl_80563034;
            rot[6] = sin_val;
            rot[7] = lbl_80563034;
            rot[8] = cos_val;

            MatrixMul801FD5E8(m, m, rot);

            float trace = m[8] + (m[0] + m[4]);
            if (trace > lbl_80563034) {
                float root = (float)fn_8002F234(lbl_80563030 + trace);
                float inv_root = lbl_80563040 / root;
                *(float*)(obj + 0x60) = lbl_80563040 * root;
                *(float*)(obj + 0x54) = inv_root * (m[5] - m[7]);
                *(float*)(obj + 0x58) = inv_root * (m[6] - m[2]);
                *(float*)(obj + 0x5C) = inv_root * (m[1] - m[3]);
            } else {
                int i = 0;
                if (m[4] > m[0]) i = 1;
                if (m[8] > m[i * 3 + i]) i = 2;
                int j = (i + 1) % 3;
                int k = (j + 1) % 3;
                float diag_sum = m[j * 3 + j] + m[k * 3 + k];
                float root = (float)fn_8002F234(lbl_80563030 + (m[i * 3 + i] - diag_sum));
                float inv_root = lbl_80563040 / root;
                float* q_out = (float*)(obj + 0x54);
                q_out[i] = lbl_80563040 * root;
                *(float*)(obj + 0x60) = inv_root * (m[j * 3 + k] - m[k * 3 + j]);
                q_out[j] = inv_root * (m[i * 3 + j] + m[j * 3 + i]);
                q_out[k] = inv_root * (m[i * 3 + k] + m[k * 3 + i]);
            }
        }
    }

    int count = *(int*)(track + 0x6D0);
    int cur_idx = *(int*)(obj + 0x3C);
    if (count - 1 != cur_idx % count) {
        void* in = *(void**)(obj + 4);
        char* prev_node = GetTrackNode(*(char**)in, cur_idx - 1);
        char* next_node = GetTrackNode(*(char**)in, cur_idx + 1);
        char* next2_node = GetTrackNode(*(char**)in, cur_idx + 2);
        fn_801FD144(obj, prev_node, node, next_node, next2_node, step);
    }
    fn_801FD320(obj, step);
    float f64_val = *(float*)(obj + 0x64);
    *(float*)(obj + 0x6C) = f64_val + step * (*(float*)(obj + 0x68) - f64_val);
}
/* Advances a LinearPathTMH along its linear node track by deltaTime: rolls the
 * segment parameter over into the next node (or hands the path back at the end),
 * then refreshes the Hermite position, orientation matrix and scalar output. */
extern "C" void fn_801FDF18(void* walker, float deltaTime) {
    char* tmh = (char*)walker;
    char** trackSlot = *(char***)(tmh + 4);
    char* track = *trackSlot;
    int nodeIndex = *(int*)(tmh + 0x3C);
    char* node = GetTrackNodeLinear(track, nodeIndex);

    float one = lbl_80563030;
    float nextT;
    float t = *(float*)(tmh + 0x40);
    nextT = t + deltaTime;
    float step = *(float*)(node + 0x20) * nextT;

    if (step < one) {
        *(float*)(tmh + 0x40) = nextT;
    } else if (nodeIndex + 2 < *(int*)(track + 0x6D0)) {
        float invSpeed = one / *(float*)(node + 0x20);
        *(int*)(tmh + 0x3C) += 1;
        float tDelta = deltaTime - invSpeed;
        step -= one;
        *(float*)(tmh + 0x40) = t + tDelta;

        node = GetTrackNodeLinear(**(char***)(tmh + 4), *(int*)(tmh + 0x3C));

        *(float*)(tmh + 0x44) = *(float*)(tmh + 0x54);
        *(float*)(tmh + 0x48) = *(float*)(tmh + 0x58);
        *(float*)(tmh + 0x4C) = *(float*)(tmh + 0x5C);
        *(float*)(tmh + 0x50) = *(float*)(tmh + 0x60);
        *(float*)(tmh + 0x64) = *(float*)(tmh + 0x68);

        char* nextNode = GetTrackNodeLinear(*(char**)(*(char* volatile*)(tmh + 4)), *(int*)(tmh + 0x3C) + 1);
        *(float*)(tmh + 0x54) = *(float*)(nextNode + 0xC);
        *(float*)(tmh + 0x58) = *(float*)(nextNode + 0x10);
        *(float*)(tmh + 0x5C) = *(float*)(nextNode + 0x14);
        *(float*)(tmh + 0x60) = *(float*)(nextNode + 0x18);

        char* nextNode2 = GetTrackNodeLinear(*(char**)(*(char* volatile*)(tmh + 4)), *(int*)(tmh + 0x3C) + 1);
        *(float*)(tmh + 0x68) = *(float*)(nextNode2 + 0x1C);
    } else {
        fn_801FEC74(tmh);
        *(void**)(tmh + 4) = 0;
        *(int*)(tmh + 0x3C) = -1;
        return;
    }

    int prevIndex;
    char* activeTrack = **(char***)(tmh + 4);
    int curIndex = *(int*)(tmh + 0x3C);
    prevIndex = curIndex - 1;
    char* prevNode = GetTrackNodeLinear(activeTrack, prevIndex);
    char* nextNode = GetTrackNodeLinear(activeTrack, curIndex + 1);
    char* nextNode2 = GetTrackNodeLinear(activeTrack, curIndex + 2);

    fn_801FD144(tmh, prevNode, node, nextNode, nextNode2, step);
    fn_801FD320(tmh, step);

    float endValue = *(float*)(tmh + 0x68);
    float startValue = *(float*)(tmh + 0x64);
    *(float*)(tmh + 0x6C) = startValue + step * (endValue - startValue);
}
#pragma pop
extern "C" void fn_801FEDA4(void*);
extern "C" float fn_80129DC4(int, void*, float, float);
extern "C" float fn_801E7E24(void);
extern "C" void* memset(void*, int, unsigned long);
extern "C" const char lbl_8033B790[];
extern "C" void* fn_801FE188(void* obj) {
    /* Initialize a LinearPathTMH object: install its vtable, clear fields, reset entry count. */
    *(const char**)obj = lbl_8033B790;
    memset((char*)obj + 4, 0, 0x30);
    *(int*)((char*)obj + 0x34) = 0;
    return obj;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
extern "C" void fn_801FE1D8(void* arg0, unsigned char* p) {
    register unsigned char* q = p + 0x3C;
    register unsigned char a=p[0x2C];
    register unsigned char x0=p[0x3B];
    register unsigned char b=p[0x2D];
    register unsigned char x1=p[0x3A];
    register unsigned char c=p[0x2E];
    register unsigned char x2=p[0x39];
    register unsigned char d=p[0x2F];
    register unsigned char x3=p[0x38];
    register unsigned char e=p[0x30];
    register unsigned char x4=p[0x37];
    register unsigned char f=p[0x31];
    register unsigned char x5=p[0x36];
    register unsigned char g=p[0x32];
    register unsigned char x6=p[0x35];
    register unsigned char h=p[0x33];
    register unsigned char x7=p[0x34];
    p[0x2C]=x0; p[0x3B]=a; p[0x2D]=x1; p[0x3A]=b;
    p[0x2E]=x2; p[0x39]=c; p[0x2F]=x3; p[0x38]=d;
    p[0x32]=x6; p[0x35]=g; p[0x33]=x7; p[0x34]=h;
    p[0x30]=x4; p[0x37]=e; p[0x31]=x5; p[0x36]=f;
    for (int i=0; i<32; i++, q+=0x18) {
      unsigned char x;
      x=q[0];q[0]=q[3];q[3]=x; x=q[1];q[1]=q[2];q[2]=x;
      x=q[4];q[4]=q[7];q[7]=x; x=q[5];q[5]=q[6];q[6]=x;
      x=q[8];q[8]=q[11];q[11]=x; x=q[9];q[9]=q[10];q[10]=x;
      x=q[12];q[12]=q[15];q[15]=x; x=q[13];q[13]=q[14];q[14]=x;
      x=q[16];q[16]=q[19];q[19]=x; x=q[17];q[17]=q[18];q[18]=x;
      x=q[20];q[20]=q[23];q[23]=x; x=q[21];q[21]=q[22];q[22]=x;
    }
    volatile unsigned char *v = p;
    unsigned char i0=v[0x33C], i1=v[0x33F];
    unsigned char i2=v[0x33D], i3=v[0x33E];
    unsigned char i4=v[0x340], i5=v[0x343];
    unsigned char i6=v[0x341], i7=v[0x342];
    unsigned char i8=v[0x344], i9=v[0x347];
    unsigned char i10=v[0x345], i11=v[0x346];
    v[0x347]=i8;
    v[0x33C]=i1; v[0x33F]=i0;
    v[0x33D]=i3; v[0x33E]=i2;
    v[0x340]=i5; v[0x343]=i4;
    v[0x341]=i7; v[0x342]=i6;
    v[0x344]=i9; v[0x345]=i11;
    v[0x346]=i10;
}
#pragma cplusplus on
#pragma pop

/* Append a source entry (at arg1+0x2C) into arg0's list at +0x34 (max 6), storing computed value. */
extern "C" void fn_801FE3B8(void *container, void *arg1) {
    char *source = (char *)arg1 + 0x2C;
    char *entry;
    int count;
    float first;
    float second;
    float value;

    count = *(int *)((char *)container + 0x34);
    if (count >= 6) {
        fn_802E317C(lbl_8033B638, 6);
    }
    count = *(int *)((char *)container + 0x34);
    first = *(float *)(source + 0x314);
    entry = (char *)container + count * 8;
    second = *(float *)(source + 0x318);
    *(char **)(entry + 4) = source;
    value = fn_80129DC4(0, entry, first, second);
    count = *(int *)((char *)container + 0x34);
    entry = (char *)container + count * 8;
    *(float *)(entry + 8) = value;
    count = *(int *)((char *)container + 0x34);
    *(int *)((char *)container + 0x34) = count + 1;
}

extern "C" void fn_801FEB58(void*);
extern "C" float lbl_80558DC4;
#pragma push
#pragma processor 750
extern "C" double __fabs(double);
#pragma push
#pragma processor 750
__declspec(section ".data") extern float lbl_80558DC4;
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_801FE448(void *spawners) {
    #define kSpawnDeltaEpsilon lbl_80558DC4
    #define kSpawnZero lbl_80563034
    #define getDeltaTime fn_801E7E24
    #define spawnFromPool fn_801FEB58
    #define randomInRange fn_80129DC4
    float deltaTime = getDeltaTime();
    /* Advances each spawner's countdown by the frame delta; when a countdown
     * expires, spawns its pool object and reschedules it with a random delay. */
    if (!((float)__fabs((double)deltaTime) <= kSpawnDeltaEpsilon)) {
        struct { float value; } thresholdStorage;
        float &threshold = thresholdStorage.value;
        threshold = kSpawnZero;
        char *entry = (char *)spawners + 4;
        int index = 0;
        while (index < *(int *)((char *)spawners + 0x34)) {
            float remaining = *(float *)(entry + 4) - deltaTime;
            *(float *)(entry + 4) = remaining;
            if (remaining <= threshold) {
                spawnFromPool(*(void **)entry);
                void *spawner = *(void **)entry;
                *(float *)(entry + 4) = randomInRange(0, spawner, *(float *)((char *)spawner + 0x314), *(float *)((char *)spawner + 0x318));
            }
            entry += 8;
            ++index;
        }
    }
    #undef randomInRange
    #undef spawnFromPool
    #undef getDeltaTime
    #undef kSpawnZero
    #undef kSpawnDeltaEpsilon
}
#pragma scheduling on
#pragma pop
extern "C" void fn_802C7040(int);
float fn_80129DC4(int, void *, float, float);
extern "C" int fn_801FE88C(void *, void *);
extern const char lbl_8033B638[];
extern const char lbl_8033B654[];
extern char lbl_8033B760[];
extern "C" void fn_801FE510(void *unused, void *head) {
    /* Walks a linked list of model-instance nodes, updating each one's visibility/distance via fn_802C7040. Node layout: +4 instance id, +0xC next. */
    void *node = head;
    while (node != 0) {
        fn_802C7040(*(int *)((char *)node + 4));
        node = *(void **)((char *)node + 0xC);
    }
}

#pragma scheduling invalid_target
extern "C" void fn_801FE550(void *path) {
    /* Constructor for a 0x98-byte HermitePathTMH object: install its vtable and clear field +0x94. */
    *(char **)path = lbl_8033B760;
    *(int *)((char *)path + 0x94) = 0;
}
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
extern "C" void fn_801FE568(void* arg0, unsigned char* p) {
    unsigned char a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15;
    unsigned char t;
    unsigned char *ptr;
    int i;

    a0 = p[0x2c]; p[0x2c] = p[0x3b]; p[0x3b] = a0;
    a1 = p[0x2d]; p[0x2d] = p[0x3a]; p[0x3a] = a1;
    a2 = p[0x2e]; p[0x2e] = p[0x39]; p[0x39] = a2;
    a3 = p[0x2f]; p[0x2f] = p[0x38]; p[0x38] = a3;
    a4 = p[0x30]; p[0x30] = p[0x37]; p[0x37] = a4;
    a5 = p[0x31]; p[0x31] = p[0x36]; p[0x36] = a5;
    a6 = p[0x32]; p[0x32] = p[0x35]; p[0x35] = a6;
    a7 = p[0x33]; p[0x33] = p[0x34]; p[0x34] = a7;

    ptr = p + 0x3c;
    for (i = 0; i < 0x48; i++) {
        t = ptr[0]; ptr[0] = ptr[3]; ptr[3] = t;
        t = ptr[1]; ptr[1] = ptr[2]; ptr[2] = t;
        t = ptr[4]; ptr[4] = ptr[7]; ptr[7] = t;
        t = ptr[5]; ptr[5] = ptr[6]; ptr[6] = t;
        t = ptr[8]; ptr[8] = ptr[0xb]; ptr[0xb] = t;
        t = ptr[9]; ptr[9] = ptr[0xa]; ptr[0xa] = t;
        t = ptr[0xc]; ptr[0xc] = ptr[0xf]; ptr[0xf] = t;
        t = ptr[0xd]; ptr[0xd] = ptr[0xe]; ptr[0xe] = t;
        t = ptr[0x10]; ptr[0x10] = ptr[0x13]; ptr[0x13] = t;
        t = ptr[0x11]; ptr[0x11] = ptr[0x12]; ptr[0x12] = t;
        t = ptr[0x14]; ptr[0x14] = ptr[0x17]; ptr[0x17] = t;
        t = ptr[0x15]; ptr[0x15] = ptr[0x16]; ptr[0x16] = t;
        ptr += 0x18;
    }

    a8 = p[0x6fc]; p[0x6fc] = p[0x6ff]; p[0x6ff] = a8;
    a9 = p[0x6fd]; p[0x6fd] = p[0x6fe]; p[0x6fe] = a9;
}
#pragma pop
extern "C" void fn_801FE708(void *container, void *entry) {
#define hermitePathLimitMsg lbl_8033B654
    /* Append a path entry (at entry+0x2C) to the container, filling slot fields; max 4 entries. */
    char *pathData = (char *)entry + 0x2C;
    int count = *(int *)((char *)container + 0x94);
    if (count >= 4)
        fn_802E317C(hermitePathLimitMsg);
    count = *(int *)((char *)container + 0x94);
    char *slot = (char *)container + count * 0x24;
    *(char **)(slot + 4) = pathData;
    fn_801FE88C(container, slot + 4);
    ++*(int *)((char *)container + 0x94);
#undef hermitePathLimitMsg
}

extern "C" void fn_801FE77C(void* container) {
    /* Update unspawned path-spawn entries in a container by spawning their pool objects. */
    char* entry = (char*)container + 4;
    int index = 0;
    while (index < *(int*)((char*)container + 0x94)) {
        if (*(unsigned short*)(entry + 0x14) == 0)
            fn_801FEDA4(entry);
        entry += 0x24;
        ++index;
    }
}

#pragma scheduling invalid_target
extern "C" void fn_801FE7E8(void* arg0) {
    float threshold = lbl_80563034;
    char* item = (char*)arg0 + 4;
    int i = 0;
    while (i < *(int*)((char*)arg0 + 0x94)) {
        if (*(unsigned short*)(item + 0x14) == 1) {
            float time = *(float*)(item + 0x20) - fn_801E7E24();
            *(float*)(item + 0x20) = time;
            if (time < threshold) {
                typedef float (*UpdateFn)(int, float, float);
                fn_801FEDA4(item);
                *(float*)(item + 0x20) = ((UpdateFn)fn_80129DC4)(0, *(float*)(item + 0x18), *(float*)(item + 0x1C));
            }
        }
        item += 0x24;
        ++i;
    }
}
#pragma scheduling reset
extern const char lbl_8055B3C8[5];
extern const char lbl_8055B3D0[6];
extern const char lbl_8055B3D8[7];
extern "C" void* fn_802AE414(int);
extern "C" char* strncpy(char*, const char*, unsigned long);
#pragma use_lmw_stmw off
extern "C" int fn_801FE88C(void *unused, void *outRec) {
    // Look up an object by ID from outRec, read its name and configuration fields
    // (including optional float parameters when type == 1), and write them into outRec.
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual const char *getName(const char *);
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual float getFloat(const char *);
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual unsigned short getUshort(const char *, const char *);
    };
    const char *base = lbl_8033B5D8;
    const char *strA = base + 0xA0;
    const char *strB = base + 0xB0;
    Obj *obj = (Obj *)fn_802AE414(*(int *)outRec);
    if (obj == 0) {
        fn_802E317C(base + 0xC8);
    }
    strncpy((char *)outRec + 4, obj->getName(lbl_8055B3C8), 0x10);
    *((char *)outRec + 0x13) = 0;
    *(unsigned short *)((char *)outRec + 0x14) = obj->getUshort(lbl_8055B3D0, strA);
    *(unsigned short *)((char *)outRec + 0x16) = obj->getUshort(lbl_8055B3D8, strB);
    if (*(unsigned short *)((char *)outRec + 0x14) == 1) {
        float val;
        float zero;
        *(float *)((char *)outRec + 0x18) = obj->getFloat(base + 0x104);
        val = obj->getFloat(base + 0x114);
        zero = lbl_80563034;
        *(float *)((char *)outRec + 0x1C) = val;
        *(float *)((char *)outRec + 0x20) = zero;
    }
}
extern "C" void* fn_801FE9A8(void* object, int shouldDelete) {
    /* CodeWarrior deleting-destructor helper: free the object via Mem_freeObject
       (fn_80128668) when deleting, then return the object pointer. */
    if (object != 0 && shouldDelete > 0) {
        Mem_freeObject(object);
    }
    return object;
}

extern "C" int stricmp(const char*, const char*);

extern "C" void* fn_801FE9E8(void* object, int deleteFlag) {
#define MemFreeObject fn_80128668
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        MemFreeObject(object);
    }
    return object;
#undef MemFreeObject
}

extern "C" void fn_801FEA28(void* pEntry) {
    /* Remove an object from the menu's object pool list */
    char* poolBase = (char*)lbl_8055EC94;
    char* name = *(char**)pEntry;
    int entryIdx = 0;
    char* poolEntry = poolBase;
    while (entryIdx < *(int*)(poolBase + 0x4C0)) {
        if (stricmp(name, poolEntry) == 0) {
            poolBase += entryIdx * 0x98;
            goto foundEntry;
        }
        poolEntry += 0x98;
        entryIdx++;
    }
    poolBase = NULL;
foundEntry:
    if (poolBase == NULL) {
        fn_802E317C(lbl_8033B7F0, *(char**)pEntry);
    }
    int usedCount = *(int*)(poolBase + 0x94);
    int foundIdx = 0;
    void* searchPtr = poolBase;
    for (int k = usedCount; k > 0; k--) {
        if (*(void**)((char*)searchPtr + 0x50) == pEntry) {
            break;
        }
        searchPtr = (char*)searchPtr + 4;
        foundIdx++;
    }
    if (foundIdx >= usedCount) {
        fn_802E317C(lbl_8033B820, usedCount, *(int*)(poolBase + 0x90));
    }
    int* shiftPtr = (int*)(poolBase + (foundIdx + 1) * 4);
    int j = foundIdx + 1;
    for (; j < *(int*)(poolBase + 0x94); j++, shiftPtr++) {
        shiftPtr[19] = shiftPtr[20];
    }
    *(int*)(poolBase + 0x94) -= 1;
    int freeCount = *(int*)(poolBase + 0x90);
    *(void**)(poolBase + 0x10 + freeCount * 4) = pEntry;
    *(int*)(poolBase + 0x90) = freeCount + 1;
}

extern const char lbl_8033B84C[];
extern "C" int stricmp(const char*, const char*);
extern "C" int fn_80129D18(int, int = 0);
void fn_801FCAE0(void*, void*);
void fn_801FD024(void*, void*);
extern "C" void fn_801FEB58(void *poolName) {
    // Find the named pool entry in the global pool table (lbl_8055EC94), pick a
    // random free object from it, move that object to the used list, and initialize it.
    char *base = (char *)lbl_8055EC94;
    int i = 0;
    char *item = base;
    char *name = (char *)poolName;
    while (i < *(int *)(base + 0x4C0)) {
        if (stricmp(name, item) == 0) {
            base += i * 0x98;
            goto found;
        }
        item += 0x98;
        i++;
    }
    base = 0;
found:
    if (base == 0) {
        fn_802E317C(lbl_8033B84C, name);
    }
    int count = *(int *)(base + 0x90);
    if (count > 0) {
        int index = fn_80129D18(0, count);
        int selected = *(int *)(base + 0x10 + index * 4);
        int j = index + 1;
        int *p = (int *)(base + j * 4);
        for (; j < *(int *)(base + 0x90); j++, p++) {
            p[3] = p[4];
        }
        *(int *)(base + 0x90) -= 1;
        fn_801FCAE0((void *)selected, name);
        int c2 = *(int *)(base + 0x94);
        *(int *)(base + 0x50 + c2 * 4) = selected;
        *(int *)(base + 0x94) = c2 + 1;
    }
}

extern "C" void fn_801FEC74(void *arg) {
    // Return a path object to the pool named by its first field: find that pool,
    // remove the object from the pool's in-use list, and push it back onto the
    // unused list. Logs (and carries on) if the pool or the in-use slot is missing.
    PathPool *pool = (PathPool *)lbl_8055EC98;
    char *name = *(char **)arg;
    int i = 0;
    PathPool *scan = pool;
    while (i < ((PathPoolTable *)pool)->poolCount) {
        if (stricmp(name, scan->name) == 0) {
            pool = pool + i;
            goto foundEntry;
        }
        scan = scan + 1;
        i++;
    }
    pool = 0;
foundEntry:
    if (pool == 0) {
        fn_802E317C(lbl_8033B7F0, *(char **)arg);
    }
    int inUseCount = pool->inUseCount;
    int slotIdx = 0;
    void *scanPtr = pool;
    for (int k = inUseCount; k > 0; k--) {
        if (*(void **)((char *)scanPtr + 0x30) == arg) {
            break;
        }
        scanPtr = (char *)scanPtr + 4;
        slotIdx++;
    }
    if (slotIdx >= inUseCount) {
        fn_802E317C(lbl_8033B820, inUseCount, pool->unusedCount);
    }
    int *shiftPtr = (int *)((char *)pool + (slotIdx + 1) * 4);
    int j = slotIdx + 1;
    for (; j < pool->inUseCount; j++, shiftPtr++) {
        shiftPtr[11] = shiftPtr[12];
    }
    pool->inUseCount -= 1;
    int freeCount = pool->unusedCount;
    *(void **)((char *)pool + 0x10 + freeCount * 4) = arg;
    pool->unusedCount = freeCount + 1;
}

extern "C" int stricmp(const char *, const char *);
void fn_801FEDA4(void *arg0) {
    // Spawn a path prop: look up the pool named in the spawner entry (arg0+4) in the
    // global pool table, take a random object off that pool's unused list, initialize
    // it from the entry's source object and add it to the pool's in-use list.
    PathSpawnEntry *entry = (PathSpawnEntry *)arg0;
    PathPool *pool = (PathPool *)lbl_8055EC98;
    int i = 0;
    PathPool *scan = pool;
    while (i < ((PathPoolTable *)pool)->poolCount) {
        if (stricmp(entry->poolName, scan->name) == 0) {
            pool = pool + i;
            goto found;
        }
        scan = scan + 1;
        i++;
    }
    pool = 0;
found:
    if (pool == 0) {
        fn_802E317C(lbl_8033B84C, entry->poolName);
    }
    int count = pool->unusedCount;
    if (count > 0) {
        int index = fn_80129D18(0, count);
        void *selected = pool->unused[index];
        int j = index + 1;
        void **p = (void **)((char *)pool + j * 4);
        for (; j < pool->unusedCount; j++, p++) {
            p[3] = p[4];
        }
        pool->unusedCount -= 1;
        fn_801FD024(selected, arg0);
        int c2 = pool->inUseCount;
        pool->inUse[c2] = selected;
        pool->inUseCount = c2 + 1;
    }
}

#pragma push
#pragma use_lmw_stmw off
/* Lazily create the DroneManager object for this slot, register it, and update its active range. */
extern "C" void fn_801FEEC0(void *slot, int context, int start, int unused) {
    void *obj = *(void **)((char *)slot + 4);
    int end = start + 0x2C;
    if (obj == 0) {
        obj = fn_801284F8(0x14CC, lbl_8033B86C);
        if (obj != 0) {
            *(void **)obj = (void *)lbl_8033B880;
            fn_8002F53C((char *)obj + 4, (void *)fn_801FEF80, (void *)fn_801FCA14, 0x40, 0x40);
            *(int *)((char *)obj + 0x1004) = 0;
            fn_801FF6A4((char *)obj + 0x1008);
        }
        *(void **)((char *)slot + 4) = obj;
        fn_802CD320(context, obj);
    }
    fn_801FF2B8(*(void **)((char *)slot + 4), start, end);
}
#pragma pop
/* Construction callback for fn_8002F53C's pool: zero each element's first two words (its list links). */
extern "C" void fn_801FEF80(void* element) {
    *(int*)element = 0;
    *((int*)element + 1) = 0;
}

extern "C" char* strncpy(char*, const char*, unsigned long);
extern "C" void fn_801FEF90(void* holder) {
    // Forward a pool-reset request (flag 0) to the drone manager held at holder+4, if one exists.
    struct DroneManagerIf {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void resetPools(int);
    };
    DroneManagerIf* manager = *(DroneManagerIf**)((char*)holder + 4);
    if (manager != 0) manager->resetPools(0);
}

extern "C" void fn_801FEFB4(void* object) {
    /* Process the entry pool held at offset 0x1008 of object via fn_801FF770. */
    fn_801FF770((char*)object + 0x1008);
}

extern "C" void fn_801FEFBC(void) {

}

extern "C" void fn_801FEFC0(void) {

}

/* No-op virtual method (vtable lbl_8033B700, slot 0x10: the first one after the
 * deleting/complete destructors) of the holder class that owns the DroneManager
 * entry point fn_801FF014; this class leaves the handler empty. */
extern "C" void fn_801FF114(void *self) {

}

/* No-op virtual method (vtable lbl_8033B700, slot 0xC) of the menu/holder class
 * that also owns the DroneManager entry point fn_801FF014; does nothing here. */
extern "C" void fn_801FF118(void) {

}

extern "C" const char lbl_8033B700[];
#pragma scheduling invalid_target
extern "C" void *fn_801FF11C(void *object, int shouldDelete) {
    /* Scalar deleting destructor: reset the vtable; if requested, free the object. */
    if (object != 0) {
        *(void * volatile *)object = (void *)&lbl_8033B700[0];
        if (shouldDelete > 0) {
            fn_80128668(object);
        }
    }
    return object;
}
extern "C" void fn_801FF168(void) {

}

#pragma small_data off
extern "C" void fn_801FF16C(void *obj) {
    /* Apply the current delta (if nonzero) to the subobject at offset 0xE08. */
    float value = fn_801E7E24();
    if (!((float)__fabs((double)value) <= lbl_80558DC4)) {
        fn_801FF3AC((char *)obj + 0xE08, value);
    }
}
/* Constant virtual getter (returns the fixed value 3); likely a count/type reported through a dispatch table. */
extern "C" int fn_801FF1BC(void) { return 3; }

extern "C" void fn_801FF1C4(void* arg0, int arg1, int arg2) {
    /* Append a drone path segment if the object's drone list has room, else log limit overflow. */
    char* p = (char*)arg0;
    if (*(int*)(p + 0xE04) >= 0x20) {
        fn_802E317C(&lbl_8033B8C8[0]);
    }
    fn_801FCF18(p + *(int*)(p + 0xE04) * 0x70 + 4, arg1, arg2);
    fn_801FF484(p + 0xE08, p + *(int*)(p + 0xE04) * 0x70 + 4);
    ++*(int*)(p + 0xE04);
}

extern double __fabs(double);
#pragma push
#pragma small_data off
/* Applies the current non-zero input value to the object's sub-state at offset 0x1008. */
extern "C" void fn_801FF260(void *obj) {
    float value = fn_801E7E24();
    if (!((float)__fabs((double)value) <= lbl_80558DC4)) {
        fn_801FF6FC((char *)obj + 0x1008, value);
    }
}
#pragma pop
/* Constant virtual getter (returns the fixed value 3); likely a count/type reported through a dispatch table. */
extern "C" int fn_801FF2B0(void) { return 3; }

extern "C" void fn_801FF2B8(void* manager, int record, int name) {
 // Append a drone path segment to a DroneManager: build the next segment of its
 // list from the spawn record, file it under its name in the manager's pool
 // table, and count it.  Past 64 segments the game logs the limit overflow and
 // writes the segment anyway.
 char* mgr = (char*)manager;
 if (DMGR_PATH_COUNT(mgr) >= DMGR_PATH_MAX) fn_802E317C(STR_PATH_DRONE_LIMIT);
 fn_801FCA54(DMGR_PATH(mgr, DMGR_PATH_COUNT(mgr)), record, name);
 fn_801FF7D4(DMGR_POOLS(mgr), DMGR_PATH(mgr, DMGR_PATH_COUNT(mgr)));
 ++DMGR_PATH_COUNT(mgr);
}

/* Install a path-pool table as the global one and reset its pool count to zero. */
extern "C" void fn_801FF354(void *poolTable) {
#define s_pathPoolTable lbl_8055EC98
    s_pathPoolTable = poolTable;
    *(int *)((char *)poolTable + 0x2C0) = 0;
#undef s_pathPoolTable
}

extern "C" void* fn_801FF364(void* pool, int shouldFree) {
    /* Clear the global path-pool pointer; optionally free the pool object. */
    if (pool != 0) {
        lbl_8055EC98 = 0;
        if (shouldFree > 0) {
            fn_80128668(pool);
        }
    }
    return pool;
}

extern "C" void fn_801FF3AC(void* container, float arg) {
    /* Update each of the container's 0x58-sized entries (count at +0x2C0). */
    char* entry = (char*)container;
    int i = 0;
    while (i < *(int*)((char*)container + 0x2C0)) {
        fn_801FF5D4(container, entry, arg);
        entry += 0x58;
        ++i;
    }
}

extern "C" void fn_801FF644(void*, void*);
void fn_801FF644(void*, void*);
extern "C" void fn_801FF420(void*);
extern "C" void fn_801FF420(void* arg0) {
    char* entry;
    int i;

    /* Iterates over the pool entries at arg0 (count at +0x2C0) and applies
     * fn_801FF644 to each 0x58-byte entry. */
    i = 0;
    entry = (char*)arg0;
    while (i < *(int*)((char*)arg0 + 0x2C0)) {
        fn_801FF644(arg0, entry);
        entry += 0x58;
        i++;
    }
}

extern "C" void fn_801FF58C(void*, char*, const char*);
#pragma use_lmw_stmw off
extern "C" void fn_801FF484(void *arg0, void *arg1) {
    const char *name = *(const char **)arg1;
    int i = 0;
    char *entry = (char *)arg0;
    while (i < *(int *)((char *)arg0 + 0x2C0)) {
        if (stricmp(name, entry) == 0) {
            entry = (char *)arg0 + i * 0x58;
            goto found;
        }
        entry += 0x58;
        i++;
    }
    entry = 0;
found:
    if (entry == 0) {
        if (*(int *)((char *)arg0 + 0x2C0) >= 8) {
            fn_802E317C(lbl_8033B8EC, 8);
        }
        entry = (char *)arg0 + *(int *)((char *)arg0 + 0x2C0) * 0x58;
        fn_801FF58C(arg0, entry, *(const char **)arg1);
        *(int *)((char *)arg0 + 0x2C0) += 1;
    }
    if (*(int *)(entry + 0x50) + 1 > 8) {
        fn_802E317C(lbl_8033B90C, 8);
    }
    int count = *(int *)(entry + 0x50);
    *(void **)(entry + 0x10 + count * 4) = arg1;
    *(int *)(entry + 0x50) = count + 1;
}
/* Initialize a named pool slot: copy up to 16 bytes of the name, terminate it, and clear its item/in-use counts. */
extern "C" void fn_801FF58C(void* unused, char* slot, const char* name) {
    strncpy(slot, name, 0x10);
    slot[0xF] = 0;
    *(int*)(slot + 0x50) = 0;
    *(int*)(slot + 0x54) = 0;
}

void fn_801FF5D4(void* arg0, void* arg1, float farg0) {
    /* Calls fn_801FCF74 for each in-use entry (count at arg1+0x54) in the
     * array of object pointers starting at arg1+0x30, passing farg0. */
    char *entry = (char *)arg1;
    int i = 0;
    while (i < *(int *)((char *)arg1 + 0x54)) {
        ((void (*)(void*, float))fn_801FCF74)(*(void **)(entry + 0x30), farg0);
        entry += 4;
        i++;
    }
}

#pragma dont_inline on
void fn_801FF644(void* arg0, void* arg1) {
    /* Call fn_801FCFC8 for each in-use entry's object pointer (entries at +0x30, stride 4, count at +0x54). */
    void* entry;
    int i;
    i = 0;
    entry = arg1;
    while (i < *(int*)((char*)arg1 + 0x54)) {
        fn_801FCFC8(*(void**)((char*)entry + 0x30));
        entry = (char*)entry + 4;
        i++;
    }
}
#pragma dont_inline reset
extern "C" void* lbl_8055EC94;
/* Install the global object-pool table and zero its registered-pool count at +0x4C0. */
void fn_801FF6A4(void* poolTable) {
#define s_objectPoolTable lbl_8055EC94
    s_objectPoolTable = poolTable;
    *(int*)((char*)poolTable + 0x4C0) = 0;
#undef s_objectPoolTable
}

extern "C" void* fn_801FF6B4(void* pool, int shouldFree) {
    /* Clear the global pool pointer; optionally free the pool object. */
    if (pool != 0) {
        lbl_8055EC94 = 0;
        if (shouldFree > 0) {
            fn_80128668(pool);
        }
    }
    return pool;
}

extern "C" void fn_801FF924(void*, void*, float);
void fn_801FF6FC(void* arg0, float farg0) {
    /* Update each 0x98-byte element in the container's list (count at +0x4C0). */
    char* entry = (char*)arg0;
    int i = 0;

    while (i < *(int*)((char*)arg0 + 0x4C0)) {
        fn_801FF924(arg0, entry, farg0);
        entry += 0x98;
        i++;
    }
}

extern "C" void fn_801FF994(void*, void*);
extern "C" void fn_801FCAAC(void*, float);
void fn_801FCAC0(void*);
void fn_801FF770(void* container) {
    void* entry;
    int index;

    /* Calls fn_801FF994 for each 0x98-byte entry in the container (count at +0x4C0). */
    index = 0;
    entry = container;
    while (index < *(int*)((char*)container + 0x4C0)) {
        fn_801FF994(container, entry);
        entry = (char*)entry + 0x98;
        index++;
    }
}

extern "C" int stricmp(const char *, const char *);
#pragma use_lmw_stmw off
void fn_801FF7D4(void *arg0, void *arg1) {
    const char *name = *(const char **)arg1;
    int i = 0;
    char *scan = (char *)arg0;
    char *entry;
    while (i < *(int *)((char *)arg0 + 0x4C0)) {
        if (stricmp(name, scan) == 0) {
            entry = (char *)arg0 + i * 0x98;
            goto found;
        }
        scan += 0x98;
        i++;
    }
    entry = 0;
found:
    if (entry == 0) {
        if (*(int *)((char *)arg0 + 0x4C0) >= 8) {
            fn_802E317C(lbl_8033B8EC, 8);
        }
        entry = (char *)arg0 + *(int *)((char *)arg0 + 0x4C0) * 0x98;
        fn_801FF8DC(arg0, entry, *(int *)arg1);
        *(int *)((char *)arg0 + 0x4C0) += 1;
    }
    if (*(int *)(entry + 0x90) + 1 > 0x10) {
        fn_802E317C(lbl_8033B90C, 0x10);
    }
    int count = *(int *)(entry + 0x90);
    *(void **)(entry + 0x10 + count * 4) = arg1;
    *(int *)(entry + 0x90) = count + 1;
}
extern "C" void fn_801FF8DC(void *arg0, void *dest, int src) {
    /* Initialize a named container slot: copy up to 16 chars of the name, terminate it,
     * and clear the two counters at +0x90/+0x94 (e.g. item count / secondary count). */
    strncpy((char *)dest, (const char *)src, 0x10);
    ((char *)dest)[0xF] = 0;
    *(int *)((char *)dest + 0x90) = 0;
    *(int *)((char *)dest + 0x94) = 0;
}

extern "C" void fn_801FF924(void* arg0, void* arg1, float farg0) {
    /* For each pointer in the object's list at arg1+0x50 (count at arg1+0x94),
     * call fn_801FCAAC with the pointer and farg0. */
    char* entry = (char*)arg1;
    int index = 0;
    goto check;
body:
    fn_801FCAAC(*(void**)(entry + 0x50), farg0);
    entry += 4;
    index++;
check:
    if (index < *(int*)((char*)arg1 + 0x94))
        goto body;
}

#pragma dont_inline on
extern "C" void fn_801FF994(void* arg0, void* arg1) {
    /* For each pointer in the list at arg1+0x50 (count at arg1+0x94), invoke fn_801FCAC0. */
    void* entry;
    int index;
    index = 0;
    entry = arg1;
    while (index < *(int*)((char*)arg1 + 0x94)) {
        fn_801FCAC0(*(void**)((char*)entry + 0x50));
        entry = (char*)entry + 4;
        index++;
    }
}
#pragma dont_inline reset
extern "C" void* fn_8002F634(void*, void*, int, int);
#pragma dont_inline on
/* Destroy SHMainMenu: tear down the subobject at offset 0xE08, then destroy the
 * 0x20 inline elements at offset 4 (0x70 bytes each) using fn_801FCED8 as the
 * element destructor (fn_8002F634 runs the destructor over the array). */
SHMainMenu::~SHMainMenu() {
    fn_801FF364((char *)this + 0xE08, -1);
    fn_8002F634((char *)this + 4, (void *)fn_801FCED8, 0x70, 0x20);
}
#pragma dont_inline on
/* Deleting destructor for SHMainMenu: destroys the subobject at offset 0x1008,
 * destroys 0x40 inline elements at offset 4 using fn_801FCA14 as element
 * destructor, then frees storage when requested. */
extern "C" void* __dt__10SHMainMenuFv_801FFA68(void* thisPtr, int shouldDelete) {
    if (thisPtr != 0) {
        fn_801FF6B4((char*)thisPtr + 0x1008, -1);
        fn_8002F634((char*)thisPtr + 4, (void*)fn_801FCA14, 0x40, 0x40);
        if (shouldDelete > 0) fn_80128668(thisPtr);
    }
    return thisPtr;
}
#pragma dont_inline reset
extern "C" void fn_801FEFC4(void) {

}

extern "C" const char lbl_8033B730[];
  void fn_801FC94C(void);
#pragma scheduling invalid_target
extern "C" void *fn_801FEFC8(void *object, int shouldDelete) {
    /* Scalar deleting destructor: reset the vtable; if requested, free the object. */
    if (object != 0) {
        *(void * volatile *)object = (void *)lbl_8033B730;
        if (shouldDelete > 0) {
            fn_80128668(object);
        }
    }
    return object;
}
#pragma push
#pragma use_lmw_stmw off
/* Lazily creates and initializes the DroneManager object stored at (char*)arg0 + 4, then adds an entry covering [start, start + 0x2C). */
extern "C" void fn_801FF014(void *arg0, int arg1, int start, int arg3) {
    void *manager = *(void **)((char *)arg0 + 4);
    int end = start + 0x2C;
    if (manager == 0) {
        manager = fn_801284F8(0x10CC, lbl_8033B86C);
        if (manager != 0) {
            *(void **)manager = (void *)lbl_8033B898;
            fn_8002F53C((char *)manager + 4, (void *)fn_801FF0D4, (void *)fn_801FCED8, 0x70, 0x20);
            *(int *)((char *)manager + 0xE04) = 0;
            fn_801FF354((char *)manager + 0xE08);
        }
        *(void **)((char *)arg0 + 4) = manager;
        fn_802CD320(arg1, manager);
    }
    fn_801FF1C4(*(void **)((char *)arg0 + 4), start, end);
}
#pragma pop
/* Array-element constructor passed to fn_8002F53C alongside the deleting
 * destructor fn_801FCED8 when the small DroneManager builds its path array
 * (32 elements of 0x70 bytes). Zero the first two words of each new segment. */
extern "C" void fn_801FF0D4(void* segment) {
    *(int*)segment = 0;
    *((int*)segment + 1) = 0;
}

extern "C" void fn_801FF0E4(void* holder) {
    // Forward a pool-reset request (flag 0) to the drone manager held at holder+4, if one exists.
    struct DroneManagerIf {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void resetPools(int);
    };
    DroneManagerIf* manager = *(DroneManagerIf**)((char*)holder + 4);
    if (manager != 0) manager->resetPools(0);
}

/* Draw pass of the DroneManager object (vtable lbl_8033B898, slot 0x14):
 * tail-calls fn_801FF420 on the object pool held inline at +0xE08, which walks
 * the pool's groups and draws every object pointer in each of them
 * (fn_801FCFC8 draws one object: model handle at +8, transform at +0xC). */
extern "C" void fn_801FF108(void* manager) {
    fn_801FF420((char*)manager + 0xE08);
}

/* No-op DroneManager hook: retained as an empty function (its body does nothing
 * in this build), adjacent to the draw-pass wrapper fn_801FF108. */
extern "C" void fn_801FF110(void) {

}
struct Obj_801FEF90 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
};
#pragma paired off
