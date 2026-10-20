// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct {
    float time;
    float f4;
    float f8;
    float fc;
    float f10;
} TrailKey;

typedef struct {
    unsigned char pad[0x20];
    int field20;
    TrailKey *keys;
    int keyCount;
    unsigned char flag2C;
    unsigned char active;
    float field30;
} TrailEntry;

typedef struct {
    unsigned char pad[4];
    TrailEntry *entries;
    int count;
} TrailMgr;
extern int stricmp(const char *, const char *);
extern char lbl_8034094C[];
extern void *fn_801284F8(int, char *);
extern float lbl_805636E0;
extern void fn_8002F6AC(void *, void (*)(void));
extern void fn_80128668(void *);
extern void fn_80237968(void);
extern void fn_80237A08(void);
extern char lbl_8034095C[];
extern char lbl_80340970[];

extern int lbl_8055F0B0;
extern int lbl_8055F0B4;
extern int lbl_8055F0B8;
extern char *lbl_8055F0BC;
extern char *lbl_8055F0C0;
extern char lbl_8055F0C4;
extern char lbl_8055F0C5;
extern char lbl_8055F0C6;
extern char lbl_8055F0C7;
void fn_80236774(void) {
    lbl_8055F0C4 = 0;
}

void fn_802368B4(int arg0) {
    if (((unsigned char *)lbl_8055F0C0)[arg0] == 0) {
        lbl_8055F0C0[arg0] = 1;
    }
}

void fn_802368D0(void) {
    lbl_8055F0C0[0x21] = 1;
}

extern char lbl_8055F0C5;
void fn_802368E0(void) {
    lbl_8055F0C5 = 1;
}

int fn_802368EC(void) {
    return (unsigned char)lbl_8055F0C0[0x21] == 0;
}

extern int fn_80215264(void);
extern void fn_80236A5C(void*, int);
extern void fn_80237AA0();
extern void fn_80236960(void);
extern char *lbl_8055F0C0;
void fn_80236900(void) {
    lbl_8055F0C0[0x21] = 0;
}

void fn_80236910(void) {
    fn_80236960();
}

void fn_80236914(void) {
    fn_80237AA0();
}

void fn_80236918(void* alarm) {
    fn_80236A5C(alarm, fn_80215264());
}

extern void fn_80237A9C(void);
extern void fn_80237DA0(void);
extern int fn_80237EFC(void);
void fn_80236950(void) { fn_80237A9C(); }

void fn_80236954(void) { fn_80237DA0(); }

extern void fn_80237E7C(char *, int);
void fn_80236958(char *arg0, int unused) { fn_80237E7C(arg0, unused); }

void fn_8023695C(void) { fn_80237EFC(); }

#pragma push
#pragma scheduling on
void fn_802369A8(char *arg0, int arg1, int arg2) {
    extern char lbl_8055BA08[8], lbl_8055BA10[8];
    extern int fn_801345D8(void *, int, const char *, ...);
    extern char *fn_80029004(char *, int);
    char *dot;
    const char *suffix;
    fn_801345D8(arg0, arg1, lbl_8055BA08, arg2);
    dot = fn_80029004(arg0, '.');
    if (dot) *dot = 0;
    suffix = lbl_8055BA10;
    while ((signed char)*arg0) { --arg1; ++arg0; }
    if (arg1 > 0) {
        while ((signed char)(*arg0++ = *suffix++) != 0) {
            if (--arg1 <= 0) { arg0[-1] = 0; break; }
        }
    }
}
#pragma pop
void fn_802379EC(void *arg0) {
    int minus = -1;
    int zero = 0;
    *(int *)((char *)arg0 + 0x20) = minus;
    *(int *)((char *)arg0 + 0x28) = zero;
    *(int *)((char *)arg0 + 0x24) = zero;
}

void fn_80237A04(void) {
}

void fn_80237A84(void *arg0) {
    *(int *)arg0 = -1;
    *(int *)((char *)arg0 + 8) = 0;
    *(int *)((char *)arg0 + 4) = 0;
}

extern char lbl_8055BA08[];
extern char lbl_8055BA10[];
extern char lbl_80498664[];
extern char *fn_80029004(char *, int);
extern char *fn_80237C40(void);
void fn_80237A9C(void) {
}

extern float lbl_805636E4;
void fn_80237AA0(arg0, arg1, arg2)
int arg0; void *arg1; double arg2;
{
    double var_f31 = arg2;
    float var_f1, var_f2;
    unsigned char var_r4;
    void *p;
    if (arg0 == 0) {
        p = *(void **)(lbl_8055F0C0 + 0x28);
        if (p) { void **v = *(void ***)p; var_f1 = ((float (*)(void))v[3])(); }
        else var_f1 = lbl_805636E0;
        *(float *)arg1 = var_f1;
        p = *(void **)(lbl_8055F0C0 + 0x2C);
        if (p) { void **v = *(void ***)p; var_f2 = ((float (*)(void))v[3])(); }
        else var_f2 = lbl_805636E0;
        *(float *)((char *)arg1 + 4) = var_f2;
        var_r4 = (unsigned char)lbl_8055F0C0[0x21];
        if (var_r4 == 0) {
            *(float *)((char *)arg1 + 4) = *(float *)arg1;
            *(float *)arg1 = var_f2;
        }
        if ((unsigned char)lbl_8055F0C0[0x1F] != 0) *(float *)arg1 = lbl_805636E0;
        if ((unsigned char)lbl_8055F0C0[0x20] != 0) *(float *)((char *)arg1 + 4) = lbl_805636E0;
    } else {
        if (arg0 == 3) {
            var_r4 = (unsigned char)lbl_8055F0C0[0x21];
            if (var_r4 != 0) var_f31 = (double)lbl_805636E4 - arg2;
        } else {
            var_r4 = (unsigned char)lbl_8055F0C0[0x21];
            if (var_r4 == 0) var_f31 = (double)lbl_805636E4 - arg2;
        }
        if ((unsigned int)(arg0 == 3) == var_r4) {
            p = *(void **)(lbl_8055F0C0 + 0x2C);
            if (p) { void **v = *(void ***)p; ((void (*)(double))v[4])(var_f31); }
        } else {
            p = *(void **)(lbl_8055F0C0 + 0x28);
            if (p) { void **v = *(void ***)p; ((void (*)(double))v[4])(var_f31); }
        }
        p = *(void **)(lbl_8055F0C0 + 0x30);
        if (p) { void **v = *(void ***)p; ((void (*)(double))v[4])(var_f31); }
    }
}

extern int stricmp(const char *, const char *);
extern char lbl_8034094C[];
extern void *fn_801284F8(int, char *);
char *fn_80237C40(void) {
    void *data = lbl_8034094C;
    char *p = fn_801284F8(0x34, data);
    int i;
    for (i = 0; i < 0x21; i++) p[i] = 0;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x2c) = 0;
    *(int *)(p + 0x24) = 0;
    return p;
}

void fn_80128668(void*);
void fn_80237D00(void *arg0) {
    void *p = *(void **)((char *)arg0 + 0x28);
    if (p != 0) {
        volatile void *q = p;
        if (q != 0) {
            void **vt = *(void ***)p;
            ((void (*)(void *, int))vt[2])(p, 1);
        }
    }
    p = *(void **)((char *)arg0 + 0x2c);
    if (p != 0) {
        volatile void *q = p;
        if (q != 0) {
            void **vt = *(void ***)p;
            ((void (*)(void *, int))vt[2])(p, 1);
        }
    }
    p = *(void **)((char *)arg0 + 0x30);
    if (p != 0) {
        volatile void *q = p;
        if (q != 0) {
            void **vt = *(void ***)p;
            ((void (*)(void *, int))vt[2])(p, 1);
        }
    }
    fn_80128668(arg0);
}

void fn_80237E7C(char *arg0, int unused) {
    int i = 0, offset = 0;
    char **items = *(char ***)((char *)lbl_8055F0C0 + 0x30);
    while (i < *(int *)((char *)items + 8)) {
        if (stricmp(*(char **)((char *)items + 4) + offset, arg0) == 0)
            *(*(char **)((char *)items + 4) + offset + 0x2d) = 0;
        offset += 0x34; i++;
    }
}

void *fn_80237FF8(void *arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 4);
        *(void **)arg0 = lbl_80340970;
        if (value != 0) fn_8002F6AC((void *)value, fn_80237A08);
        *(float *)((char *)arg0 + 0xC) = lbl_805636E0;
        if (arg1 > 0) fn_80128668(arg0);
        *(int *)((char *)arg0 + 4) = 0;
        *(int *)((char *)arg0 + 8) = 0;
    }
    return arg0;
}

float fn_80238084(void *arg0) { return *(float *)((char *)arg0 + 0xC); }

extern float lbl_805636E8;
extern void *fn_8022EDE4(float *, float);
extern void *fn_8022EE9C(void);
extern void fn_8022EE98(void *);
extern void fn_80214C54(void *, void *);
#pragma push
#pragma processor 750
void fn_8023808C(void *arg0, float value) {
    struct Pos {float x,y;};
    struct Key { float time, scale, z; struct Pos pos; };
    struct Track {void *object; struct Key *keys; int count;};
    struct Anim {void *vtable; struct Track *tracks; int count; float duration;};
    struct Anim *anim = arg0;
    float a[12], b[12], c[12];
    float time;
    float zero=lbl_805636E0, one=lbl_805636E4, epsilon=lbl_805636E8;
    int i;
    value = lbl_805636E4 < value ? lbl_805636E4 : value;
    value = value > lbl_805636E0 ? value : lbl_805636E0;
    time = anim->duration * value;
    for(i=0;i<anim->count;i++) {
        struct Track *track=&anim->tracks[i];
        void *result;
        if(track->count>0) {
            int j, index=-1;
            for(j=0;j<track->count;j++) if(time >= track->keys[j].time) index=j;
            if(index==-1) {
                struct Key *key=track->keys;
                struct Pos pos;
                float scale=key->scale, z=key->z;
                pos=key->pos;
                a[9]=pos.x; a[10]=pos.y; a[11]=zero; a[0]=one; a[1]=zero; a[2]=zero; a[3]=zero; a[4]=one; a[5]=zero; a[6]=zero; a[7]=zero; a[8]=one;
                result=fn_8022EDE4(a,scale); ((float*)result)[14]=z;
            } else if(index==track->count-1) {
                struct Key *key=&track->keys[track->count-1];
                struct Pos pos;
                float scale=key->scale, z=key->z;
                pos=key->pos;
                b[9]=pos.x; b[10]=pos.y; b[11]=zero; b[0]=one; b[1]=zero; b[2]=zero; b[3]=zero; b[4]=one; b[5]=zero; b[6]=zero; b[7]=zero; b[8]=one;
                result=fn_8022EDE4(b,scale); ((float*)result)[14]=z;
            } else {
                struct Key *first=&track->keys[index], *next=&track->keys[index+1];
                float delta=next->time-first->time;
                float t,scale,z;
                struct Pos pos;
                delta=delta>epsilon?delta:epsilon;
                t=(time-first->time)/delta;
                pos.y=first->pos.y+t*(next->pos.y-first->pos.y);
                scale=first->scale+t*(next->scale-first->scale);
                pos.x=first->pos.x+t*(next->pos.x-first->pos.x);
                z=first->z+t*(next->z-first->z);
                c[9]=pos.x; c[10]=pos.y; c[11]=zero; c[0]=one; c[1]=zero; c[2]=zero; c[3]=zero; c[4]=one; c[5]=zero; c[6]=zero; c[7]=zero; c[8]=one;
                result=fn_8022EDE4(c,scale); ((float*)result)[14]=z;
            }
        } else result=fn_8022EE9C();
        fn_80214C54(track->object,result);
        fn_8022EE98(result);
    }
}
#pragma pop

void *fn_80238370(void *arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 4);
        *(void **)arg0 = lbl_8034095C;
        if (value != 0) fn_8002F6AC((void *)value, fn_80237968);
        *(int *)((char *)arg0 + 4) = 0;
        *(int *)((char *)arg0 + 8) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

float fn_802383F4(void) { return lbl_805636E0; }

#pragma push
#pragma processor 750
void fn_802383FC(TrailMgr *mgr) {
    extern float fn_8023659C(void);
    extern void *fn_8022EDE4(float *, float);
    extern void *fn_8022EE9C(void);
    extern void fn_8022EE98(void *);
    extern void fn_80214C54(void *, void *);
    extern float lbl_805636E0, lbl_805636E4, lbl_805636E8;
    float f29 = fn_8023659C();
    float f30 = lbl_805636E0;
    float f31 = lbl_805636E4;
    float f27 = lbl_805636E8;
    int i;
    int off;
    for (i = 0, off = 0; i < mgr->count; i++, off += 0x34) {
        TrailEntry *e = (TrailEntry *)((char *)mgr->entries + off);
        if (e->active == 0) continue;
        {
            float t = f29 - e->field30;
            void *obj;
            if (e->keyCount > 0) {
                int idx = -1;
                int j;
                for (j = 0; j < e->keyCount; j++) {
                    if (t >= e->keys[j].time) idx = j;
                }
                if (idx == -1) {
                    TrailKey *k = e->keys;
                    float mtx[12];
                    mtx[9] = k->fc;
                    mtx[10] = k->f10;
                    mtx[11] = f30;
                    mtx[0] = f31; mtx[1] = f30; mtx[2] = f30; mtx[3] = f30;
                    mtx[4] = f31; mtx[5] = f30; mtx[6] = f30; mtx[7] = f30;
                    mtx[8] = f31;
                    obj = fn_8022EDE4(mtx, k->f4);
                    *(float *)((char *)obj + 0x38) = k->f8;
                } else if (idx == e->keyCount - 1) {
                    TrailKey *k = &e->keys[e->keyCount - 1];
                    float mtx[12];
                    mtx[9] = k->fc;
                    mtx[10] = k->f10;
                    mtx[11] = f30;
                    mtx[0] = f31; mtx[1] = f30; mtx[2] = f30; mtx[3] = f30;
                    mtx[4] = f31; mtx[5] = f30; mtx[6] = f30; mtx[7] = f30;
                    mtx[8] = f31;
                    obj = fn_8022EDE4(mtx, k->f4);
                    *(float *)((char *)obj + 0x38) = k->f8;
                } else {
                    TrailKey *c = &e->keys[idx];
                    TrailKey *n = &e->keys[idx + 1];
                    float denom = n->time - c->time;
                    float tt;
                    float mtx[12];
                    if (denom <= f27) denom = f27;
                    tt = (t - c->time) / denom;
                    mtx[11] = f30;
                    mtx[0] = f31; mtx[1] = f30; mtx[2] = f30; mtx[3] = f30;
                    mtx[4] = f31; mtx[5] = f30; mtx[6] = f30; mtx[7] = f30;
                    mtx[8] = f31;
                    mtx[9] = c->fc + tt * (n->fc - c->fc);
                    mtx[10] = c->f10 + tt * (n->f10 - c->f10);
                    obj = fn_8022EDE4(mtx, c->f4 + tt * (n->f4 - c->f4));
                    *(float *)((char *)obj + 0x38) = c->f8 + tt * (n->f8 - c->f8);
                }
            } else {
                obj = fn_8022EE9C();
            }
            fn_80214C54((void *)e->field20, obj);
            fn_8022EE98(obj);
            if (e->flag2C != 0) {
                float lim;
                if (e->keyCount > 0) {
                    lim = e->keys[e->keyCount - 1].time;
                } else {
                    lim = f30;
                }
                if (t > lim) e->active = 0;
            }
        }
    }
}
#pragma pop
extern void fn_80237AA0();
extern void fn_80236960(void);
extern float lbl_805636E0;
extern void fn_8002F6AC(void *, void (*)(void));
extern void fn_80128668(void *);
extern void fn_80237968(void);
extern void fn_80237A08(void);
extern char lbl_8034095C[];
extern char lbl_80340970[];
