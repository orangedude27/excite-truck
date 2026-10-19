// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { float x, y, z; } Vec80295;
extern char lbl_80349338[];
extern char lbl_8055C998[8], lbl_8055C9A0[4], lbl_8055C9A4[8], lbl_8055C9AC[4];
extern float lbl_8056451C, lbl_80564520, lbl_80564544;
extern int fn_80288070(int, int, int *);
extern int fn_80287E20(int, int);
extern void *fn_80287E80(int, int);
int fn_80287B14(void);
int fn_802CAC54(int);
extern int lbl_8055C990;
extern int lbl_8055C994;
#pragma scheduling off
void fn_8029496C(void) {}

void fn_80294C68(void) {
    int i;
    fn_802CAC54(lbl_8055C990);
    fn_802CAC54(lbl_8055C994);
    lbl_8055C990 = -1;
    i = 0;
    lbl_8055C994 = -1;
    do { i++; } while (i < fn_80287B14());
}
#pragma scheduling on
void fn_80294CC0(void) {}

void fn_80294CC4(void) {}

void fn_80294ED4(void);
void fn_80294CC8(void) { fn_80294ED4(); }

#pragma scheduling off
void fn_80295C70(void *arg0, int arg1, float *arg2, unsigned int arg3, int arg4, float farg0, float farg1) {
    struct Entry { int value; float a,b,c,d,e; unsigned char flags[3]; int tail; };
    struct Obj { unsigned char pad[0x180]; int count; };
    struct Obj *obj = arg0;
    struct Entry *entry = (struct Entry *)((char *)obj + (obj->count << 5));
    entry->value = arg1;
    entry->a = arg2[0];
    entry->b = arg2[1];
    entry->c = arg2[2];
    entry->d = farg1;
    entry->e = farg0;
    entry->flags[0] = arg3 >> 16;
    entry->flags[1] = arg3 >> 8;
    entry->flags[2] = arg3;
    entry->tail = arg4;
    obj->count++;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
void fn_80295CC4(void *self, int a, int b, Vec80295 *input, int unused, float *pos, float size) {
    Vec80295 col = *input;
    int id;
    unsigned int packed;
    int extra;
    float base, sx, sy;
    void *obj;
    if (fn_80288070(a,b,&id)) {
        if (fn_80287E20(a,b)) {
            Vec80295 result, def;
            obj = fn_80287E80(a,b);
            def = col;
            result = ((Vec80295 (*)(void *, char *, Vec80295 *))(*(int **)obj)[14])(obj,lbl_8055C998,&def);
            packed = 0xFF000000U | ((unsigned char)(((int)(lbl_80564544 * result.x) > 0 ? (int)(lbl_80564544 * result.x) : 0) < 255 ? ((int)(lbl_80564544 * result.x) > 0 ? (int)(lbl_80564544 * result.x) : 0) : 255) << 16) | ((unsigned char)(((int)(lbl_80564544 * result.y) > 0 ? (int)(lbl_80564544 * result.y) : 0) < 255 ? ((int)(lbl_80564544 * result.y) > 0 ? (int)(lbl_80564544 * result.y) : 0) : 255) << 8) | (unsigned char)(((int)(lbl_80564544 * result.z) > 0 ? (int)(lbl_80564544 * result.z) : 0) < 255 ? ((int)(lbl_80564544 * result.z) > 0 ? (int)(lbl_80564544 * result.z) : 0) : 255);
            base = ((float (*)(void *, char *, float))(*(int **)obj)[10])(obj,lbl_8055C9A0,size);
            sx = ((float (*)(void *, char *, float))(*(int **)obj)[10])(obj,lbl_8055C9A4,lbl_80564520);
            sy = ((float (*)(void *, char *, float))(*(int **)obj)[10])(obj,lbl_8055C9AC,lbl_80564520);
            if (sx <= lbl_8056451C || sy <= lbl_8056451C) { sy=base; sx=base; }
            extra = ((int (*)(void *, char *, int))(*(int **)obj)[8])(obj,lbl_80349338,0);
        } else {
            packed = 0xFF000000U | ((unsigned char)(((int)(lbl_80564544 * col.x) > 0 ? (int)(lbl_80564544 * col.x) : 0) < 255 ? ((int)(lbl_80564544 * col.x) > 0 ? (int)(lbl_80564544 * col.x) : 0) : 255) << 16) | ((unsigned char)(((int)(lbl_80564544 * col.y) > 0 ? (int)(lbl_80564544 * col.y) : 0) < 255 ? ((int)(lbl_80564544 * col.y) > 0 ? (int)(lbl_80564544 * col.y) : 0) : 255) << 8) | (unsigned char)(((int)(lbl_80564544 * col.z) > 0 ? (int)(lbl_80564544 * col.z) : 0) < 255 ? ((int)(lbl_80564544 * col.z) > 0 ? (int)(lbl_80564544 * col.z) : 0) : 255);
            sx=size; sy=size; extra=0;
        }
        fn_80295C70(self,id,pos,packed,extra,sx,sy);
    }
}
#pragma pop

#pragma scheduling on
