// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80214CB4(int);
extern int fn_80235380(int);
extern int fn_80128668(void *);
extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
extern int fn_80214B44(int);
extern void *lbl_803430E8[];
extern void *lbl_8055F244;
extern int fn_80232578(void *);
extern int fn_802C5130(void *);
extern int fn_802C519C(void *);
extern void fn_802E30C8(const char *, ...);
extern int fn_802328D4(void *);
extern int fn_802451DC(void *, int);
extern int fn_8024521C(void *, int);
extern int fn_80216CA8();
extern int fn_802146BC(int *, int, int, int);
extern int strlen(const char *);
__declspec(section ".sdata") extern void *lbl_8055BE68;
__declspec(section ".sdata") extern void *lbl_8055BAC0;
extern char lbl_80343148[];
extern int lbl_802FA364[5];
extern void fn_80246210(void);
__declspec(section ".sdata") extern void *lbl_8055BE70;
__declspec(section ".sdata") extern void *lbl_8055BE78;
extern int lbl_80498890[5];
int fn_802451DC(void *arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668(arg0);
    return (int)arg0;
}

int fn_8024521C(void *arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055F244 = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return (int)arg0;
}

extern char lbl_80342FC0[];
extern float lbl_80563830;

// lbl_80342FC0 is the static description of the "mc_status" screen: its J3D
// layout name at +0x00, the image to fetch at +0x60, the message printed when
// that image is missing at +0x78 and the gText font file to load at +0xB4.

// The drawing context fn_80245264 builds from that block and fn_802452E4
// releases; fn_80245360 draws a menu title, description and items through it.
struct MenuTextContext {
    int unused0;    /* +0x00 */
    int image;      /* +0x04 the layout's image, fetched by name */
    int image2;     /* +0x08 a second image; none while the context starts up */
    int font;       /* +0x0C gText font block, loaded from its .gtx name */
    int font2;      /* +0x10 the same font loaded again, so a second use count */
    float xOffset;  /* +0x14 added to every x the printers are given */
};

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Loads what the "mc_status" screen draws with into `context`: its image,
   fetched by the name in the static description block (fn_802C5130 refuses
   names over 15 characters, and the block's own message is printed when the
   image is not there), then its gText font twice; the rest is cleared. */
int fn_80245264(struct MenuTextContext *context) {
    char *desc = lbl_80342FC0; /* the "mc_status.lyt" description block */
    int result;
    float value;

    result = fn_802C5130(desc + 0x60); /* the image's name */
    context->image = result;
    if (result == 0) {
        fn_802E30C8(desc + 0x78); /* printed once when the image is missing */
    }
    context->image2 = 0;
    context->font2 = fn_80232578(desc + 0xB4); /* the font's .gtx name */
    result = fn_80232578(desc + 0xB4);
    value = lbl_80563830;
    context->font = result;
    context->xOffset = value;
}
#pragma scheduling on
#pragma pop

extern int lbl_8055CFF0, lbl_8055CFF4, lbl_8055FB9C, lbl_8055FBA0;
extern const float lbl_80563834, lbl_80563838, lbl_8056383C, lbl_80563840, lbl_80563844, lbl_80563848, lbl_8056384C, lbl_80563850, lbl_80563854, lbl_80563858, lbl_8056385C, lbl_80563860, lbl_80563864, lbl_80563868, lbl_8056386C, lbl_80563870, lbl_80563874, lbl_80563878, lbl_8056387C, lbl_80563888, lbl_8056388C, lbl_80563890;
extern const double lbl_80563880;
extern char lbl_80343080[];
extern char lbl_8055BE50, lbl_8055BE58, lbl_8055BE5C;
extern int fn_80129AFC(void);
extern int fn_802E47B8(void);
extern int fn_802E46F0(void);
extern int fn_802E2D74(int);
extern int fn_802E2C20(void);
extern double sin(double);
extern void fn_802C5310(int, int, float, float, float);
extern void fn_802337A0(int, int, int, void *, void *, float, float, float, float, float, ...);
extern float lbl_80558DC4[];
extern char lbl_8055BE60, lbl_8055BE64;
extern void fn_802C8530(void);
extern void fn_802C87B4(int, int, int, int);
extern void fn_802C88BC(int);
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(float, float, float);
extern void fn_802C5320(int, float, float, float, float, float, int);
extern void fn_802C92D0(void);
extern void fn_802C92DC(int, int, int, int, int);
extern void fn_802C92D8(void);
extern void fn_80232BA4(char *, int, int, int, float, float, float, float, float);
extern float fn_8023293C(int, char *, float);
extern void fn_80028E00(char *, char *);
extern void fn_802335F0(char *, int, float, float);
extern void fn_802C9A70(int);
extern void fn_802C855C(void);
extern void fn_802C2B48(void);
extern char *strcpy(char *, const char *);

struct MenuItem {
    char *name;
    int value;
};

struct Menu {
    char *title;
    char *desc;
    void *unk8;
    int (*callback)(int *);
    int selected;
    int count;
    struct MenuItem items[1];
};

void fn_802452E4(void *arg0) {
    void *value;
    value = *(void **)((char *)arg0 + 4);
    if (value) fn_802C519C(value);
    value = *(void **)((char *)arg0 + 8);
    *(int *)((char *)arg0 + 4) = 0;
    if (value) fn_802C519C(value);
    *(int *)((char *)arg0 + 8) = 0;
    fn_802328D4(*(void **)((char *)arg0 + 0xC));
    fn_802328D4(*(void **)((char *)arg0 + 0x10));
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_unroll_loops off
int fn_80245360(int *a, struct Menu *b) {
    int sp8;
    char obj[0x30];
    char text[0x200];
    unsigned long long buf[64];
    char *s;
    float y;

    int selected = b->selected;
    float temp_f19 = lbl_80563854;
    float temp_f20 = lbl_8056384C;
    float temp_f21 = lbl_8056385C;
    float temp_f23 = lbl_80563864;
    float temp_f24 = lbl_80563838;
    float temp_f25 = lbl_80563870;
    float temp_f26 = lbl_8056386C;
    float temp_f27 = lbl_80563868;
    float temp_f28 = lbl_80563844;
    float temp_f29 = lbl_8056387C;
    float temp_f16 = lbl_80563840;
    float temp_f17 = lbl_80563834;
    float temp_f18 = lbl_80563850;
    float temp_f31 = lbl_80563874;
    float temp_f30 = lbl_80563878;

    for (;;) {
        float w, h;
        float fw, fh;
        float x0, x1;
        char *desc;
        fn_802C8530();
        fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_802C88BC(2);
        fn_80230B5C(obj);
        fn_802C8638(obj);
        fn_802C974C(lbl_80563834, lbl_80563838, lbl_8056383C);
        w = (float)(lbl_8055FB9C + 1);
        h = (float)(lbl_8055FBA0 + 1);
        fw = (float)lbl_8055FB9C;
        fh = (float)lbl_8055FBA0;
        x0 = temp_f16 * fw * temp_f28 - temp_f17;
        x1 = temp_f17 + fh * temp_f28;
        if (a[1] != 0) {
            fn_802C5320(a[1], x0, x1, lbl_80563830, w, h, 0);
        } else {
            fn_802C92D0();
            fn_802C92DC(0, 0, (int)w, (int)h, 0xFF000000);
            fn_802C92D8();
        }
        s = b->title;
        desc = b->desc;
        y = lbl_80563848;
        if (strlen(s) != 0) {
            fn_80232BA4(s, a[3], 0xFF000000, 12, temp_f20 + ((float *)a)[5], y - temp_f20, lbl_80563834, lbl_80563830, lbl_80563834);
            fn_80232BA4(s, a[3], -1, 12, ((float *)a)[5], y, lbl_80563834, lbl_80563830, lbl_80563834);
        }
        y -= temp_f18;
        strcpy(text, desc);
        s = text;
        while (strlen(s) != 0) {
            int i;
            char *last_space;
            char *p_buf;
            unsigned int j;
            signed char save;
            for (i = 0; i < 64; i++) {
                buf[i] = 0;
            }
            last_space = 0;
            p_buf = (char *)buf;
            j = 0;
            while (j < strlen(s) && fn_8023293C(a[3], (char *)buf, lbl_80563834) < temp_f19) {
                char ch = s[j];
                char *curr = &s[j];
                if (ch == ' ') {
                    last_space = curr;
                } else if (ch == '^') {
                    *curr = ' ';
                }
                j++;
                *p_buf++ = *curr;
                *p_buf = 0;
            }
            save = 0;
            if (j != strlen(s)) {
                if (last_space == 0) {
                    last_space = &s[j];
                    save = s[j];
                }
                *last_space = 0;
            } else {
                last_space = &s[j] - 1;
            }
            fn_80232BA4(s, a[3], 0xFF000000, 12, temp_f20 + ((float *)a)[5], y - temp_f20, lbl_80563858, lbl_80563830, lbl_80563834);
            fn_80232BA4(s, a[3], -1, 12, ((float *)a)[5], y, lbl_80563858, lbl_80563830, lbl_80563834);
            if (save == 0) {
                s = last_space + 1;
            } else {
                *last_space = save;
                s = last_space;
            }
            y -= temp_f21;
        }
        y = lbl_80563860;
        {
            void *item_ptr = b;
            int i = 0;
            while (i < b->count) {
                float wave = (float)sin(temp_f23 * (float)fn_802E2C20() / temp_f24);
                float alpha = temp_f27 * (temp_f26 + temp_f25 * wave);
                char *name = *(char **)((char *)item_ptr + 0x18);
                int color;
                fn_80232BA4(name, a[3], 0xFF000000, 12, temp_f20 + ((float *)a)[5], y - temp_f20, lbl_80563834, lbl_80563830, lbl_80563834);
                if (selected == i) {
                    color = ((int)alpha << 24) | 0x00FFD03F;
                } else {
                    color = 0xC8646464;
                }
                fn_80232BA4(name, a[3], color, 12, ((float *)a)[5], y, lbl_80563834, lbl_80563830, lbl_80563834);
                y -= temp_f21;
                item_ptr = (char *)item_ptr + 8;
                i++;
            }
        }
        if (a[2] != 0) {
            fn_802C5310(a[2], 0, temp_f29 + (temp_f30 + temp_f28 * fn_8023293C(a[4], &lbl_8055BE50, lbl_80563834)), temp_f23 + temp_f31, lbl_80563830);
            fn_802337A0(a[4], -1, 9, &lbl_8055BE58, &lbl_8055BE50, temp_f30, temp_f31, lbl_80563830, lbl_80563844, lbl_80563834);
        } else {
            fn_802337A0(a[4], -1, 12, lbl_80343080, &lbl_8055BE5C, temp_f30, temp_f31, lbl_80563830, lbl_80563844, lbl_80563834);
        }
        fn_802C9A70(1);
        fn_802C855C();
        fn_802C2B48();
        fn_80129AFC();
        if (fn_802E47B8()) {
            switch ((unsigned short)fn_802E46F0()) {
            case 0x126:
                if (selected > 0) {
                    fn_80214D50(0);
                    selected--;
                }
                break;
            case 0x128:
                if (selected + 1 < b->count) {
                    fn_80214D50(0);
                    selected++;
                }
                break;
            case 0xd:
                fn_80214D50(2);
                return *(int *)((char *)b + 0x1C + selected * 8);
            }
        }
        {
            int (*callback)(int *) = b->callback;
            if (callback != 0) {
                sp8 = -1;
                if (callback(&sp8) == 1) return sp8;
            }
        }
        fn_802E2D74(5);
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern double fabs(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_unroll_loops off
extern double __fabs(double);
void fn_8024590C(int *a, int *b) {
    char obj[0x30];
    char tail[0x40];
    struct { int a, b; } buf[64];
    char text[0x200];
    char *s, *split, *p;
    int i, j, n, save;
    float step, shadow, limit, y, h, w, f, x1, x0;
    fn_802C8530();
    fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
    fn_802C88BC(2);
    fn_80230B5C(obj);
    fn_802C8638(obj);
    fn_802C974C(lbl_80563834, lbl_80563838, lbl_8056383C);
    w = (float)(lbl_8055FB9C + 1);
    h = (float)(lbl_8055FBA0 + 1);
    x0 = lbl_80563840 * (float)lbl_8055FB9C * lbl_80563844 - lbl_80563834;
    x1 = lbl_80563834 + (float)lbl_8055FBA0 * lbl_80563844;
    if (a[1] != 0) {
        fn_802C5320(a[1], x0, x1, lbl_80563830, w, h, 0);
    } else {
        fn_802C92D0();
        fn_802C92DC(0, 0, (int)w, (int)h, 0xFF000000);
        fn_802C92D8();
    }
    s = (char *)b[0];
    split = (char *)b[1];
    y = lbl_80563848;
    if (strlen(s) != 0) {
        fn_80232BA4(s, a[3], 0xFF000000, 12, lbl_8056384C + ((float *)a)[5], y - lbl_8056384C, lbl_80563834, lbl_80563830, lbl_80563834);
        fn_80232BA4(s, a[3], -1, 12, ((float *)a)[5], y, lbl_80563834, lbl_80563830, lbl_80563834);
    }
    y -= lbl_80563850;
    strcpy(text, split);
    limit = lbl_80563854;
    shadow = lbl_8056384C;
    step = lbl_8056385C;
    s = text;
    while (strlen(s) != 0) {
        for (i = 0; i < 64; i++) { buf[i].a = 0; buf[i].b = 0; }
        split = 0;
        j = 0;
        do {
            p = s + j;
            if (*p == 32) split = p;
            else if (*p == 94) *p = 32;
            ((char *)buf)[j] = *p;
            j++;
            ((char *)buf)[j] = 0;
        } while ((unsigned)j < strlen(s) && fn_8023293C(a[3], (char *)buf, lbl_80563834) < limit);
        save = 0;
        if ((unsigned)j != strlen(s)) {
            if (split == 0) {
                split = s + j;
                save = *split;
            }
            *split = 0;
        } else {
            split = s + j - 1;
        }
        fn_80232BA4(s, a[3], 0xFF000000, 12, shadow + ((float *)a)[5], y - shadow, lbl_80563858, lbl_80563830, lbl_80563834);
        fn_80232BA4(s, a[3], -1, 12, ((float *)a)[5], y, lbl_80563858, lbl_80563830, lbl_80563834);
        if (save == 0) s = split + 1;
        else { *split = save; s = split; }
        y -= step;
    }
    f = ((float *)b)[2];
    if (!((float)__fabs(f) <= lbl_80558DC4[0])) {
        strcpy(tail, &lbl_8055BE60);
        n = (int)(lbl_80563888 * f);
        for (i = 0; i < n; i++) fn_80028E00(tail, &lbl_8055BE64);
        fn_802335F0(tail, a[4], lbl_8056388C, lbl_80563890);
    }
    fn_802C9A70(1);
    fn_802C855C();
    fn_802C2B48();
}
#pragma pop

extern int fn_8012C33C(void *, void *);
extern int fn_80214D50(int);
extern char lbl_8034308C[];
#pragma cplusplus on
extern "C" void fn_80245CC8(void *arg0) {
    unsigned char result;
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
    };
    *(unsigned char *)((char *)arg0 + 0x1C) = 1;
    result = ((int (*)(void *))fn_8012C33C)(lbl_8034308C);
    *(unsigned char *)((char *)arg0 + 0x1D) = result;
    if (result == 0) {
        ((Dummy *)((char *)arg0 + 4))->f0();
    }
    *(unsigned char *)((char *)arg0 + 0x1E) = 1;
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_80245D2C(void *arg0) {
    unsigned char result;
    *(unsigned char *)((char *)arg0 + 0x1C) = 0;
    result = *(unsigned char *)((char *)arg0 + 0x1D);
    if (result == 0) {
        struct Dummy {
            virtual void f0();
            virtual void f1();
            virtual void f2();
            virtual void f3();
        };
        ((Dummy *)((char *)arg0 + 4))->f1();
    }
    fn_80214D50(4);
}

void fn_80245D74(void *arg0, void *arg1, int arg2) {
    int i, count, *src, *dst;
    int slots[4][2];
    (void)arg2;
    if (*(unsigned char *)((char *)arg0 + 0x1D) == 0) {
        void **vtable = *(void ***)arg0;
        ((void (*)(void *))vtable[4])((char *)arg0 + 4);
        return;
    }
    count = *(int *)((char *)arg1 + 0x14);
    *(void **)((char *)arg0 + 0x20) = arg1;
    i = 0;
    if (count > 0) {
        src = (int *)((char *)arg1 + 0x18);
        dst = &slots[0][0];
        while (i < count) {
            dst[0] = src[0]; dst[1] = src[1];
            src += 2; dst += 2; i++;
        }
    }
    while (i < 4) { slots[i][0] = 0; slots[i][1] = 0; i++; }
    *(void **)((char *)arg0 + 0x20) = 0;
}

#pragma cplusplus reset
int fn_802461D0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

void fn_80246210(void) {
    /* Reset the flag at +0x1E, then update slots 0..activeCount-1 and disable remaining slots up to 3,
       finally apply the value at +0x10 from the same data block. */
    int activeCount;
    int index;
    int zeroValue;

    zeroValue = 0;
    *((char *)lbl_8055F244 + 0x1E) = (char)zeroValue;
    index = 0;
    activeCount = *(int *)((char *)*(void **)((char *)lbl_8055F244 + 0x20) + 0x14);
    while (index < activeCount) {
        fn_80214AF0(index);
        index++;
    }
    while (activeCount < 4) {
        fn_80214B44(activeCount);
        fn_80214A9C(activeCount);
        activeCount++;
    }
    fn_80214CB4(*(int *)((char *)*(void **)((char *)lbl_8055F244 + 0x20) + 0x10));
}

extern int fn_8023512C(void *);
extern int fn_80216CA8(int, int, int, int, void *, int, int, int);
extern int fn_802146BC(int *, int, int, int);
extern int strlen(const char *);
extern char lbl_803430CC[];
extern char lbl_803430D8[];
__declspec(section ".sdata") extern void *lbl_8055BE70;
__declspec(section ".sdata") extern void *lbl_8055BE78;
extern int lbl_80498890[5];
extern int lbl_802FA350[5];
#pragma cplusplus on
#pragma small_data off
#pragma scheduling invalid_target
extern "C" void fn_802462A0(register void *arg0, register void *arg1) {
    struct Frame {
        unsigned int args[5];
        int pad;
        struct {
            void *object;
            int unused[4];
            int zero;
            float value;
            int result;
        } state;
        unsigned int config[20];
    };
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
    };
    struct Frame frame;

    if (*(unsigned char *)((char *)arg0 + 0x1D) == 0) {
        ((Dummy *)((char *)arg0 + 4))->f3();
        return;
    }
    frame.state.value = *(float *)((char *)arg1 + 8);
    frame.state.object = &lbl_803430E8;
    frame.state.zero = 0;
    frame.state.result = fn_8023512C(&lbl_803430CC);

    frame.config[3] = strlen(*(char **)arg1);
    frame.config[0] = (unsigned int)&lbl_8055BE70;
    frame.config[2] = *(int *)arg1;
    frame.config[1] = 3;
    frame.config[4] = 0;

    frame.config[8] = strlen(*(char **)((char *)arg1 + 4));
    frame.config[5] = (unsigned int)&lbl_8055BE78;
    frame.config[7] = *(int *)((char *)arg1 + 4);
    frame.config[6] = 3;
    frame.config[9] = 0;

    frame.config[10] = (unsigned int)&lbl_803430D8;
    frame.config[11] = 5;
    frame.config[12] = (unsigned int)&frame.state;
    frame.config[13] = 0;
    frame.config[14] = 0;
    frame.config[15] = lbl_80498890[0];
    frame.config[16] = lbl_80498890[1];
    frame.config[17] = lbl_80498890[2];
    frame.config[18] = lbl_80498890[3];
    frame.config[19] = lbl_80498890[4];

    *(int *)((char *)arg0 + 0x24) = 0;
    frame.args[0] = lbl_802FA350[0];
    frame.args[1] = lbl_802FA350[1];
    frame.args[2] = lbl_802FA350[2];
    frame.args[3] = lbl_802FA350[3];
    frame.args[4] = lbl_802FA350[4];
    frame.args[1] = (unsigned int)&frame.config[0];

    fn_80216CA8(lbl_802FA350[4], lbl_802FA350[3], lbl_802FA350[2],
                lbl_802FA350[0], lbl_802FA350, lbl_80498890[1],
                lbl_80498890[0], 5);
    fn_802146BC((int *)frame.args, -0x3E7, -0x3E7, 1);
    frame.state.object = &lbl_803430E8;
    if (frame.state.result != 0)
        fn_80235380(frame.state.result);
}
#pragma scheduling on
#pragma small_data on
#pragma cplusplus reset

#pragma small_data off
void *fn_80246428(void *arg0, int arg1) {
    int temp_r0;
    if (arg0 != 0) {
        temp_r0 = *(int *)((char *)arg0 + 0x1C);
        *(void **)arg0 = &lbl_803430E8;
        if (temp_r0 != 0) {
            fn_80235380(temp_r0);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma small_data on

void fn_80246498(void *arg0) {
    fn_80214CB4(*(unsigned char *)((char *)arg0 + 0x18) == 0);
}

void fn_802464A8(void *arg0) {
    *((signed char *)arg0 + 0x19) = 0;
}

extern int fn_80230E90(int);
extern int fn_80216D28(void);
/* Handle directional input events (0x125-0x128) for a widget, using flag at +0x19
 * to choose between selection/value changes and the alternate action path. */
int fn_802464B4(void *arg0, int eventId) {
    switch (eventId) {
    case 0x125:
        if (*(unsigned char *)((char *)arg0 + 0x19) == 0) {
            fn_80214CB4(0); fn_80230E90(0);
        } else fn_80216D28();
        goto done;
    case 0x127:
        if (*(unsigned char *)((char *)arg0 + 0x19) == 0) {
            fn_80214CB4(1); fn_80230E90(0);
        } else fn_80216D28();
        goto done;
    case 0x126:
        if (*(unsigned char *)((char *)arg0 + 0x19) != 0) {
            fn_80214CB4(0); fn_80230E90(0);
        } else fn_80216D28();
        goto done;
    case 0x128:
        if (*(unsigned char *)((char *)arg0 + 0x19) != 0) {
            fn_80214CB4(1); fn_80230E90(0);
        } else fn_80216D28();
        goto done;
    default: return 0;
    }
done:
    return 1;
}

/* Gauge widget: a horizontal progress bar whose Draw method is fn_802465A4
 * (vtable lbl_803430E8, dtor fn_80246428).  Only the fields the draw uses are
 * named here. */
struct BarWidget {
    void *vtable;  /* 0x00 */
    int x;         /* 0x04 bar box top-left, screen units (origin at screen centre, y up) */
    int y;         /* 0x08 */
    int width;     /* 0x0C bar box size */
    int height;    /* 0x10 */
    int pad14;     /* 0x14 */
    float fill;    /* 0x18 part of the bar to fill, 0.0 .. 1.0 */
    int image;     /* 0x1C bar image (see fn_8023505C parts), 0 = plain rectangle */
};

/* Bar image pieces: two rows of three, the outer ones being fixed-width caps.
 * Row 0 (0,1,2) is the frame drawn over the full width, row 1 (3,4,5) the fill. */
#define BAR_PIECE_FRAME_LEFT 0
#define BAR_PIECE_FRAME_MID 1
#define BAR_PIECE_FRAME_RIGHT 2
#define BAR_PIECE_FILL_LEFT 3
#define BAR_PIECE_FILL_MID 4
#define BAR_PIECE_FILL_RIGHT 5

#define BAR_Z lbl_80563830      /* depth the bar quads are drawn at, 0.0f */
#define BAR_TEX_V lbl_80563834  /* whole height of a piece's texture, 1.0f */
#define BAR_HALF lbl_80563844   /* 0.5f, for centring */

extern void fn_80230C30(float *, float *, int, int);
extern void fn_80230924(int, float, float, float, float, float);
extern float fn_80235EF0(int, int);
extern float fn_80235F64(int, int);
extern void fn_802353F4(int, int, float, float, float);
extern void fn_802354A0(int, int, int, float, float, float, float, float);
extern void fn_80235758(int, int, int, float, float, float, float, float, float, float, float);
#pragma push
#pragma processor 750
/* Draw the gauge.
 *
 * The bar has its top-left corner at (x, y) - the widget's position turned
 * into screen coordinates (origin at the middle of the screen, y upwards) -
 * and is nudged so that it sits in the middle of the widget's height box.
 * widget->fill (0.0 .. 1.0) says how much of its total width to show.
 *
 * With a bar image, that width is spent on the fill row's left cap, then on
 * the stretchable middle, then on the right cap; whichever piece the fill
 * stops inside is drawn showing only the covered part of its texture
 * (fn_80235758's u1 argument is the fraction to show).  The frame row is then
 * drawn over the whole bar at its natural size.  Without an image the fill is
 * just a plain rectangle of the widget's own box. */
void fn_802465A4(struct BarWidget *widget) {
    float x, y, midX;
    float width, height, leftWidth, rightWidth, midWidth, totalWidth, barHeight, fillWidth, partWidth;
    int image;

    fn_80230C30(&x, &y, widget->x, widget->y);
    width = (float)widget->width;
    height = (float)widget->height;
    image = widget->image;
    if (image) {
        /* the caps keep their width; the middle takes the rest of the box */
        leftWidth = fn_80235EF0(image, BAR_PIECE_FRAME_LEFT);
        rightWidth = fn_80235EF0(widget->image, BAR_PIECE_FRAME_RIGHT);
        midWidth = (width-leftWidth)-rightWidth;
        totalWidth = rightWidth+(leftWidth+midWidth);
        barHeight = fn_80235F64(widget->image, BAR_PIECE_FRAME_LEFT);
        x = (x + BAR_HALF*width) - BAR_HALF*totalWidth;
        y = (y + BAR_HALF*height) - BAR_HALF*barHeight;
        fillWidth = totalWidth * widget->fill;

        if (fillWidth < leftWidth) {
            /* stops inside the left cap: show only that much of it */
            fn_80235758(widget->image, BAR_PIECE_FILL_LEFT, -1, x, y, fillWidth, barHeight, BAR_Z, BAR_Z, fillWidth/leftWidth, BAR_TEX_V);
        } else if (fillWidth < leftWidth+midWidth) {
            /* covers the left cap and part of the middle */
            fn_802353F4(widget->image, BAR_PIECE_FILL_LEFT, x, y, BAR_Z);
            partWidth = fillWidth-leftWidth;
            fn_80235758(widget->image, BAR_PIECE_FILL_MID, -1, x+leftWidth, y, partWidth, barHeight, BAR_Z, BAR_Z, partWidth/midWidth, BAR_TEX_V);
        } else {
            /* covers the middle too, and eats into the right cap */
            fn_802353F4(widget->image, BAR_PIECE_FILL_LEFT, x, y, BAR_Z);
            fn_802354A0(widget->image, BAR_PIECE_FILL_MID, -1, x+leftWidth, y, BAR_Z, midWidth, barHeight);
            midX = x+leftWidth;
            partWidth = (fillWidth-leftWidth)-midWidth;
            fn_80235758(widget->image, BAR_PIECE_FILL_RIGHT, -1, midWidth+midX, y, partWidth, barHeight, BAR_Z, BAR_Z, partWidth/rightWidth, BAR_TEX_V);
        }

        /* frame over the full width */
        fn_802353F4(widget->image, BAR_PIECE_FRAME_LEFT, x, y, BAR_Z);
        fn_802354A0(widget->image, BAR_PIECE_FRAME_MID, -1, x+leftWidth, y, BAR_Z, midWidth, barHeight);
        fn_802353F4(widget->image, BAR_PIECE_FRAME_RIGHT, midWidth+(x+leftWidth), y, BAR_Z);
    } else {
        fn_80230924(-1, x, y, x+width* widget->fill, y-height, BAR_Z);
    }
}
#pragma pop
extern int fn_80129AF4(void);
extern int fn_801298E8(void *, int);
extern int fn_80214FD8(const char *, const char *);
extern char lbl_80343210[];
extern char lbl_80343224[];
/* Warn the user if any connected controller is wireless (current slot or any slot when none selected). */
void fn_8024683C(void) {
    unsigned char status[0xD0];
    int isWireless;
    int chan;
    int currentChan;

    currentChan = fn_80129AF4();
    isWireless = 0;
    if (currentChan == -1) {
        chan = 0;
        do {
            if (fn_801298E8(status + 0x64, chan) != 0 && (*(unsigned int *)(status + 0xB4) & 1) != 0) {
                isWireless = 1;
            }
            chan++;
        } while (chan < 4);
    } else if (fn_801298E8(status, currentChan) != 0 && (*(unsigned int *)(status + 0x50) & 1) != 0) {
        isWireless = 1;
    }
    if (isWireless != 0) {
        fn_80214FD8(lbl_80343210, lbl_80343224);
    }
}

