// Code of main that had no source file yet: decomp.wtf gave it this one.
extern int fn_802E2C20(void);
__declspec(section ".data") extern int lbl_80507288;
extern int NANDCheck(unsigned int, unsigned int, unsigned int *);
extern char lbl_8034D9C0[];
// split_file divides it into the game's real files (file_status shows its range).
extern int fn_802E95E0(void *, void (*)(void), int);
extern void fn_802E9010(void);
extern int NANDInit(void);
extern void fn_802E317C(const char *, ...);
extern void fn_801282F4(void);
extern void fn_801282EC(int);
extern int fn_8012850C(int, const char *);
extern void fn_802E6B50(void);
extern void fn_80127C90(void *, void *);
extern void fn_802E2E0C(void *, void *);
extern int fn_802E8C6C(int);
extern char lbl_8034DED4[];
extern char lbl_8034DEF4[];
extern char lbl_8055D248;
extern char lbl_8055D250;
extern char lbl_8034DEC4[];
extern char lbl_8034DF00[];
extern int lbl_80560020;
extern void fn_802E6B94(void);
extern void fn_80127D58(void *);
extern void fn_80128670(int);

extern int lbl_8056002C;
extern char lbl_8034E108[];
extern void fn_802E9254(void *);
extern unsigned int fn_802E91BC(int *);
extern int fn_802E91AC(int *);
extern void fn_802E91D8(void *, const char *, int, int);
extern void fn_802E9160(void *);
extern void fn_802E9118(void *);
extern char lbl_80560028;
extern int lbl_80560030;
extern void *lbl_80560024;
extern char lbl_80560034;
extern char lbl_8034DD78[];
extern char lbl_8034DE94[];
extern void fn_802E30C8(const char *, ...);
extern void fn_802E8B34(const char *);
extern int fn_802E888C(int);
extern char lbl_8034DB28[];
extern void fn_802E86D4(void);
extern void fn_802E870C(void);
extern int fn_802E8744(void *);
extern void fn_80127464(void);
extern int NANDDelete(const char *);
extern char lbl_8034DE54[];
extern char lbl_8034DE6C[];

#pragma dont_inline on
void fn_802E86D4(void) {
    register void **vtable = *(void ***)lbl_80560024;
    register void *method = vtable[2];
    ((void (*)(void))method)();
    lbl_80560028 = 1;
}
void fn_802E870C(void) {
    ((void (*)(void *))(*(void ***)((void *)lbl_80560024))[3])(lbl_80560024);
    lbl_80560028 = 0;
}

extern int fn_80131234(int, int, int, int, int, int, int, int);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
int fn_802E8744(void *arg0) {
    volatile int *p = (volatile int *)arg0;
    int v13, v12, v11, v10, v9, v8, v7, v6, v5, v4, v3, v2, v1, v0;
    int values[14];
    int *out;
    int i;
    v0 = p[0]; v1 = p[1]; v2 = p[2]; v3 = p[3];
    v4 = p[4]; v5 = p[5]; v6 = p[6]; v7 = p[7];
    v8 = p[8]; v9 = p[9]; v10 = p[10]; v11 = p[11];
    v12 = p[12]; v13 = p[13];
    values[0] = v0; values[1] = v1; values[2] = v2; values[3] = v3;
    values[4] = v4; values[5] = v5; values[6] = v6; values[7] = v7;
    values[8] = v8; values[9] = v9; values[10] = v10; values[11] = v11;
    values[12] = v12; values[13] = v13;
    values[1] = fn_80131234(v1, v12, v11, v10, v9, v8, v7, v6);
    out = values;
    p = (volatile int *)arg0;
    for (i = 0; i < 4; i++) {
        int value = p[6];
        if (value != 0) out[6] = ((int (*)(int))fn_80131234)(value);
        p += 2;
        out += 2;
    }
    return ((int (*)(void *, int *))(*(void ***)((void *)lbl_80560024))[4])(lbl_80560024, values);
}
#pragma scheduling on
#pragma use_lmw_stmw reset
void fn_802E8838(void) {
    fn_80127464();
}

void fn_802E883C(void) {
    if (lbl_8056002C == 0) {
        fn_802E86D4();
    }
    lbl_8056002C += 1;
}

void fn_802E8874(void) {
    lbl_8056002C -= 1;
    if (lbl_8056002C == 0) {
        fn_802E870C();
    }
}

int fn_802E888C(int arg0) {
    int result;
    ((void (*)(void))fn_802E883C)();
    result = fn_802E8744(lbl_8034DB28 + arg0 * 0x38);
    ((void (*)(void))fn_802E8874)();
    return result;
}

#pragma scheduling invalid_target
int fn_802E88D8(void) {
    if (fn_802E888C(0) != 0) {
        lbl_80560034 = 1;
        return 1;
    }
    return 0;
}
#pragma scheduling on
void fn_802E8918(void) {
    fn_802E2E38(1);
}

#pragma scheduling invalid_target
void fn_802E8920(int arg0) {
    unsigned int flags = 0;
    char *messages = lbl_8034D9C0;
    int result = NANDCheck((arg0 + 0x3FFF) / 0x4000 + 4, 2, &flags);
    if (result == 0) {
        for (;;) {
            if (flags & 1) {
                fn_802E30C8(messages + 0x328);
            }
            if (flags & 2) {
                fn_802E30C8(messages + 0x35C);
            }
            if (flags & 0xF) {
                int request = 3;
                if (flags & 5) {
                    request = 2;
                }
                if (fn_802E888C(request) != 0) {
                    fn_802E8918();
                    break;
                }
                if (fn_802E88D8() != 0) {
                    break;
                }
            } else {
                if (fn_802E888C(7) != 0) {
                    break;
                }
                if (fn_802E88D8() != 0) {
                    break;
                }
            }
        }
    } else {
        fn_802E30C8(messages + 0x398, result);
    }
}
#pragma scheduling on
int fn_802E8AE8(const char *arg0) {
    unsigned char sp8[0x88];
    int result = 0;
    if (NANDOpen((void *)arg0, sp8, 1) == 0) {
        result = 1;
        NANDClose(sp8);
    }
    return result;
}

void fn_802E8B34(const char *arg0) {
    /* Report the path and status if NANDDelete fails. */
    fn_802E30C8(lbl_8034DE54, arg0);
    {
        int result = NANDDelete(arg0);
        if (result != 0) {
            fn_802E30C8(lbl_8034DE6C, result, arg0);
        }
    }
}

void fn_802E8B98(void) {
    if (lbl_80560030 != 0) {
        fn_802E8B34((const char *)0);
        fn_802E8B34(lbl_8034DD78);
    } else {
        fn_802E30C8(lbl_8034DE94);
    }
}

int fn_802E8BE4(void) {
    for (;;) {
        if (((int (*)(int))fn_802E888C)(1) != 0) {
            fn_802E8B98();
            return 1;
        }
        if (fn_802E88D8() != 0)
            return 0;
    }
}

#pragma dont_inline reset

extern int fn_8012C4D8(int);
extern int fn_802E88D8(void);
void fn_802E8C2C(void) { for (;;) { if(((int(*)(int))fn_802E888C)(4)!=0) { ((void(*)(void))fn_802E8918)(); return; } if(fn_802E88D8()!=0) return; } }

int fn_802E8C6C(int arg0) {
    if (arg0 == 1) {
        ((int (*)(const char *, void (*)(void)))fn_802E95E0)(lbl_8034DEC4, fn_802E9010);
    }
    return 0;
}

void fn_802E8CA8(void) {
    int result = NANDInit();
    if (result != 0) {
        fn_802E317C(lbl_8034DED4, result);
    }
    fn_801282F4();
    fn_801282EC(0x80);
    lbl_80560020 = fn_8012850C(0x55730, lbl_8034DEF4);
    fn_802E6B50();
    fn_80127C90((void *)fn_802E9010, &lbl_8055D248);
    fn_802E2E0C((void *)fn_802E8C6C, &lbl_8055D250);
}

void fn_802E8D2C(void) {
    ((int (*)(void *, void (*)(void)))fn_802E95E0)(lbl_8034DF00, fn_802E8838);
    fn_80127D58((void *)fn_802E9010);
    fn_802E6B94();
    fn_80128670(lbl_80560020);
    lbl_80560020 = 0;
}

extern void *lbl_80560024;
void fn_802E8D7C(void* hi) {
    lbl_80560024 = hi;
}

typedef unsigned int u32;
extern int fn_8012C4D8(int);
extern int fn_802E88D8(void);
extern int NANDDelete(const char *);
extern char lbl_8034DE54[];
extern char lbl_8034DE6C[];
  extern int NANDOpen(const char *, void *, int);
  extern int NANDGetLength(void *, unsigned int *);
  extern int NANDClose(void *);
extern char lbl_80560034;
extern int fn_802E95E0(void *, void (*)(void), int);
extern int fn_802E2C20(void);
extern char lbl_8034E024[];
__declspec(section ".data") extern int lbl_80507288;
extern unsigned char lbl_80560035;
extern char lbl_8034E0BC[];
extern int fn_802ECC10(void);
extern char lbl_8034E130[];
extern void fn_802E317C(const char *, ...);
extern void fn_802E6B94(void);
extern void fn_802E6B50(void);
extern void fn_80127D58(void *);
extern void fn_80128670(int);
extern void fn_801282F4(void);
extern void fn_801282EC(int);
extern int fn_8012850C(int, const char *);
extern void fn_80127C90(void *, void *);
extern void fn_802E2E0C(void *, void *);
extern int NANDInit(void);
extern void fn_802E8838(void);
extern void fn_802E9010(void);
extern int fn_802E8C6C(int);
extern char lbl_8034DF00[];
extern char lbl_8034DED4[];
extern char lbl_8034DEF4[];
extern int lbl_80560020;
extern char lbl_8055D248;
extern char lbl_8055D250;
extern char lbl_8034DEC4[];
extern unsigned char lbl_8055D255;
extern int NANDRead(void *, void *, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern int fn_802E8A18(void);
extern int fn_802E8AE8(const char *);
extern int fn_802E8BE4(void);
extern void fn_802E8C2C(void);
extern void fn_802E8920(int);
u32 fn_802E8D84(void) { return 1; }

/* Names for the state and helpers of this "rmemcard" NAND module (the debug
 * strings it logs are all prefixed "rmemcard: ").  The project cannot rename
 * the game's symbols yet, so these stand in for them; they are token-identical
 * to the symbols they name.
 *
 * rmemcard_current_path - path of the file the module is working on, NULL when
 *                         idle; the error handlers delete it when it is set.
 * rmemcard_out_of_space - flag set when a NAND operation ran out of free
 *                         blocks; the read below consumes (clears) it.
 * rmemcard_async_buffer - the shared staging buffer fn_802E8CA8 allocates
 *                         RMEMCARD_ASYNC_BUFFER_SIZE bytes of under the name
 *                         "mc_async", and fn_802E8D2C frees; NULL once freed.
 * rmemcard_log_strings  - this module's log strings (offsets into the block).
 * rmemcard_yield        - resumes the thread the NAND wait put to sleep, i.e.
 *                         gives the async machine a turn.
 * rmemcard_wait_async   - runs a pump callback until the async NAND machine
 *                         (fn_802E9010) leaves the busy states, giving up
 *                         after 0xFA0 ticks; 1 = idle, 0 = timed out.
 * rmemcard_test_banner_ok - 1 when the title's banner.bin exists and has the
 *                         size the game expects (0xF0A0 bytes).
 * rmemcard_file_exists  - 1 when NANDOpen can open the path at all.
 * rmemcard_recover_space - asks for len bytes of free NAND space and keeps
 *                         running the module's recovery requests until it has
 *                         them.
 */
#define rmemcard_current_path   lbl_80560030
#define rmemcard_out_of_space   lbl_8055D255
#define rmemcard_async_buffer   lbl_80560020
#define rmemcard_log_strings    lbl_8034D9C0
#define rmemcard_yield          fn_802E8838
#define rmemcard_wait_async     fn_802E95E0
#define rmemcard_test_banner_ok fn_802E8A18
#define rmemcard_file_exists    fn_802E8AE8
#define rmemcard_recover_space  fn_802E8920
#define RMEMCARD_ASYNC_BUFFER_SIZE 0x55730

#pragma use_lmw_stmw off

int fn_802E8D8C(const char *path, void *buf, int len) {
    struct { int pad; char info[0x8C]; } s;
    int a, saved;
    char *msg;
    int n;
    int b, r;

    msg = lbl_8034D9C0;
    lbl_80560030 = (int)path;
    if (((int (*)(void *, void (*)(void)))fn_802E95E0)(msg + 0x550, fn_802E8838) == 0) {
        if (&s.pad != 0) lbl_80560030 = 0;
        return 0;
    }
    saved = lbl_8055D255;
    lbl_8055D255 = 0;
    a = fn_802E8A18();
    b = fn_802E8AE8(path);
    if (a == 0 && b == 0) {
        fn_802E30C8(msg + 0x560);
        if (saved != 0) fn_802E8920(len);
        if (&s.pad != 0) lbl_80560030 = 0;
        return 0;
    }
    if (a == 0 || b == 0) {
        fn_802E30C8(msg + 0x594);
        if (((int (*)(void))fn_802E8BE4)() != 0) fn_802E8920(len);
        if (&s.pad != 0) lbl_80560030 = 0;
        return 0;
    }
    r = NANDOpen(path, s.info, 1);
    if (r != 0) {
        fn_802E30C8(msg + 0x5CC, r);
        if (saved != 0) fn_802E8920(len);
        if (&s.pad != 0) lbl_80560030 = 0;
        return 0;
    }
    if (lbl_80560020 != 0) {
        if (len > 0x55730) {
            fn_802E317C(msg + 0x5F0, len, 0x55730);
        }
        n = NANDRead(s.info, (void *)lbl_80560020, len);
        if (n == len) {
            memcpy(buf, (void *)lbl_80560020, len);
        }
    } else {
        n = NANDRead(s.info, buf, len);
    }
    if (n != len) {
        fn_802E30C8(msg + 0x624, n);
        NANDClose(s.info);
        if (n == -4) {
            ((void (*)(void))fn_802E8C2C)();
        } else if (((int (*)(void))fn_802E8BE4)() != 0) {
            fn_802E8920(len);
        }
        if (&s.pad != 0) lbl_80560030 = 0;
        return 0;
    }
    r = NANDClose(s.info);
    if (r != 0) {
        fn_802E30C8(msg + 0x644, r);
        if (&s.pad != 0) lbl_80560030 = 0;
        return 0;
    }
    if (&s.pad != 0) lbl_80560030 = 0;
    return 1;
}

#pragma push
#pragma optimization_level 3
void fn_802E9010(void) {
    char *data = (char *)&lbl_80507288;
    fn_802E9254(data + 4);
    switch ((&lbl_80507288)[0]) {
    case 2:
        fn_802E91D8(data + 4, lbl_8034E108, *(int *)(data + 0x260), *(int *)(data + 0x264));
        (&lbl_80507288)[0] = 3;
        break;
    case 3:
        if (fn_802E91BC((int *)(data + 4)) != 0) {
            if (fn_802E91AC((int *)(data + 4)) == 0) {
                fn_802E91D8(data + 4, data + 0x270, *(int *)(data + 0x268), *(int *)(data + 0x26C));
                (&lbl_80507288)[0] = 4;
            } else fn_802E9160(data);
        }
        break;
    case 4:
        if (fn_802E91BC((int *)(data + 4)) != 0) {
            if (fn_802E91AC((int *)(data + 4)) == 0) fn_802E9118(data);
            else fn_802E9160(data);
        }
        break;
    }
}
#pragma pop
void fn_802E9118(void *arg0) { fn_8012C4D8(*(int*)((char*)arg0+0x260)); *(int*)((char*)arg0+0x260)=0; *(int*)((char*)arg0+0x264)=0; *(int*)((char*)arg0+0x268)=0; *(int*)((char*)arg0+0x26c)=0; *(int*)arg0=0; }

void fn_802E9160(void *arg0) { fn_8012C4D8(*(int*)((char*)arg0+0x260)); *(int*)((char*)arg0+0x260)=0; *(int*)((char*)arg0+0x264)=0; *(int*)((char*)arg0+0x268)=0; *(int*)((char*)arg0+0x26c)=0; *(int*)arg0=1; }

int fn_802E91AC(int *arg0) { return *arg0 == 0; }

#pragma scheduling invalid_target
unsigned int fn_802E91BC(int *arg0) {
    int value = *arg0 ^ 2;
    int shifted = value >> 1;
    value &= 2;
    shifted -= value;
    return shifted < 0;
}
#pragma scheduling on
extern int fn_802E2C20(void);
extern char lbl_8034E024[];
extern int lbl_80507288;
extern unsigned char lbl_80560035;
extern char lbl_8034E0BC[];
extern int fn_802ECC10(void);
extern int fn_802E888C(int);
extern char lbl_8034E130[];
extern char lbl_8034E108[];
#pragma scheduling invalid_target
void fn_802E91D8(void *arg0, const char *arg1, int arg2, int arg3) {
    const char *original;
    const char *src;
    char *dst;
    int count;
    char c;
    original = arg1;
    *(int *)((char *)arg0 + 8) = arg2;
    src = original;
    *(int *)((char *)arg0 + 4) = arg3;
    dst = (char *)arg0 + 0xC;
    count = 0x100;
    goto copy;
dec_count:
    count--;
    if (count > 0) goto copy;
    dst[-1] = 0;
    goto after_copy;
copy:
    c = *src++;
    *dst++ = c;
    if (c != 0) goto dec_count;
after_copy:
    *(void **)((char *)arg0 + 0x198) = arg0;
    *(int *)((char *)arg0 + 0x258) = 0;
    *(char *)((char *)arg0 + 0x250) = 0;
    *(int *)((char *)arg0 + 0x254) = 0;
    *(int *)arg0 = 2;
    fn_802E30C8(lbl_8034E130, arg3, original);
}
#pragma scheduling on
extern void fn_802E95CC(int, void **);
extern int NANDCreateAsync(const char *, unsigned char, unsigned char, void (*)(int, void **), void *);
extern int NANDOpenAsync(const char *, void *, unsigned char, void (*)(int, void **), void *);
extern int NANDWriteAsync(void *, const void *, unsigned int, void (*)(int, void **), void *);
extern int NANDCloseAsync(void *, void (*)(int, void **), void *);
extern char lbl_8034E114[];
extern char lbl_8034E158[];
extern char lbl_8034E168[];
extern char lbl_8034E184[];
extern char lbl_8034E194[];
extern char lbl_8034E1B4[];
extern char lbl_8034E1C4[];
extern char lbl_8034E1E8[];
extern char lbl_8034E1F8[];
extern char lbl_8034E218[];
#pragma scheduling invalid_target
extern char lbl_8034E114[], lbl_8034E158[], lbl_8034E168[], lbl_8034E184[];
extern char lbl_8034E194[], lbl_8034E1B4[], lbl_8034E1C4[], lbl_8034E1E8[];
extern char lbl_8034E1F8[], lbl_8034E218[], lbl_80560034;

/* Steps of the async NAND file-write machine in fn_802E9254.  The context block
 * it walks (arg0) holds, at these offsets:
 *   0x000 state        - current step (values below)
 *   0x004 length       - byte count to write
 *   0x008 buffer       - source data
 *   0x00C filename     - NAND path (e.g. "banner.bin"), set by fn_802E91D8
 *   0x10C nand_info    - NANDInfo handle of the open file
 *   0x198 cb_ctx       - points back to this block; handed to the async calls
 *   0x250 async_done   - set to 1 by the completion callback fn_802E95CC
 *   0x254 async_result - result the callback left behind
 *   0x258 error        - result reported back to the caller
 */
enum {
    RMEMCARD_WRITE_IDLE     = 0,   /* stopped / failed */
    RMEMCARD_WRITE_DONE     = 1,   /* finished */
    RMEMCARD_WRITE_CREATE   = 2,   /* NANDCreateAsync */
    RMEMCARD_WRITE_OPEN     = 3,   /* NANDOpenAsync   */
    RMEMCARD_WRITE_WRITE    = 4,   /* NANDWriteAsync  */
    RMEMCARD_WRITE_CLOSE    = 5,   /* NANDCloseAsync  */
    RMEMCARD_WRITE_FINISHED = 6    /* report success  */
};

#pragma scheduling invalid_target
/* fn_802E9254 - one step of the removable-memory-card ("rmemcard") async
 * NAND file write.  Called repeatedly (from fn_802E9010); each call advances
 * the machine in ctx by one NAND operation.  The async calls all complete
 * through fn_802E95CC, which sets ctx's async_done flag (0x250) and stores the
 * operation's result in async_result (0x254); the machine polls that flag,
 * checks the result, and either moves to the next step or bails out to IDLE
 * recording the error in ctx+0x258.  Steps: create -> open -> write -> close.
 */
void fn_802E9254(void *ctx) {
    char *data = (char *)ctx;
    unsigned char *flags = (unsigned char *)ctx;
    int state = *(int *)data;
    int status = 0;
    int result;

    switch (state) {
    case RMEMCARD_WRITE_CREATE:
        flags[0x250] = status;
        *(int *)(data + 0x254) = status;
        result = NANDCreateAsync(data + 0xC, 0x30, 0, fn_802E95CC, data + 0x198);
        if (result != 0) {
            fn_802E30C8(lbl_8034E114, lbl_8034E218, result); /* "rmemcard: %s failed (%d)", "NANDCreateAsync" */
            *(int *)data = status;
            *(int *)(data + 0x258) = result;
        } else *(int *)data = RMEMCARD_WRITE_OPEN;
        break;
    case RMEMCARD_WRITE_OPEN:
        if (flags[0x250] != status) {          /* create has finished */
            status = *(int *)(data + 0x254);
            if (status == 0 || status == -6) { /* created OK, or already existed */
                flags[0x250] = 0;
                *(int *)(data + 0x254) = 0;
                result = NANDOpenAsync(data + 0xC, data + 0x10C, 2, fn_802E95CC, data + 0x198);
                if (result != 0) {
                    fn_802E30C8(lbl_8034E114, lbl_8034E1F8, result); /* "NANDOpenAsync" */
                    *(int *)data = RMEMCARD_WRITE_IDLE;
                    *(int *)(data + 0x258) = result;
                } else *(int *)data = RMEMCARD_WRITE_WRITE;
            } else {
                if (status == -11) {           /* title not found: needs a create */
                    lbl_80560034 = 1;
                    fn_802E888C(5);
                }
                status = *(int *)(data + 0x254);
                fn_802E30C8(lbl_8034E114, lbl_8034E1E8, status); /* "NANDCreateAsync" */
                *(int *)(data + 0x258) = status;
                *(int *)data = RMEMCARD_WRITE_IDLE;
            }
        }
        break;
    case RMEMCARD_WRITE_WRITE:
        if (flags[0x250] != 0) {               /* open has finished */
            status = *(int *)(data + 0x254);
            if (status == 0) {
                flags[0x250] = 0;
                *(int *)(data + 0x254) = 0;
                result = NANDWriteAsync(data + 0x10C, (const void *)*(int *)(data + 8),
                                        *(unsigned int *)(data + 4), fn_802E95CC, data + 0x198);
                if (result != 0) {
                    fn_802E30C8(lbl_8034E114, lbl_8034E1C4, result); /* "NANDWriteAsync" */
                    *(int *)data = RMEMCARD_WRITE_IDLE;
                    *(int *)(data + 0x258) = result;
                    NANDClose(data + 0x10C);
                } else *(int *)data = RMEMCARD_WRITE_CLOSE;
            } else {
                fn_802E30C8(lbl_8034E114, lbl_8034E1B4, status); /* "NANDOpenAsync" */
                *(int *)(data + 0x258) = status;
                *(int *)data = RMEMCARD_WRITE_IDLE;
            }
        }
        break;
    case RMEMCARD_WRITE_CLOSE:
        if (flags[0x250] != 0) {               /* write has finished */
            status = *(int *)(data + 0x254);
            if (status == *(int *)(data + 4)) { /* wrote the whole buffer */
                flags[0x250] = 0;
                *(int *)(data + 0x254) = 0;
                result = NANDCloseAsync(data + 0x10C, fn_802E95CC, data + 0x198);
                if (result != 0) {
                    fn_802E30C8(lbl_8034E114, lbl_8034E194, result); /* "NANDCloseAsync" */
                    *(int *)data = RMEMCARD_WRITE_IDLE;
                    *(int *)(data + 0x258) = result;
                    NANDClose(data + 0x10C);
                } else *(int *)data = RMEMCARD_WRITE_FINISHED;
            } else {
                fn_802E30C8(lbl_8034E114, lbl_8034E184, status); /* "NANDWriteAsync" */
                *(int *)(data + 0x258) = status;
                *(int *)data = RMEMCARD_WRITE_IDLE;
                NANDClose(data + 0x10C);
            }
        }
        break;
    case RMEMCARD_WRITE_FINISHED:
        if (flags[0x250] != 0) {               /* close has finished */
            status = *(int *)(data + 0x254);
            if (status == 0) {
                *(int *)data = RMEMCARD_WRITE_DONE;
                fn_802E30C8(lbl_8034E168, *(int *)(data + 4), data + 0xC); /* "rmemcard: Wrote %db to %s" */
            } else {
                fn_802E30C8(lbl_8034E114, lbl_8034E158, status); /* "NANDCloseAsync" */
                *(int *)(data + 0x258) = status;
                *(int *)data = RMEMCARD_WRITE_IDLE;
                NANDClose(data + 0x10C);
            }
        }
        break;
    }
}
#pragma scheduling on
void fn_802E95CC(int arg0, void **arg1) { void *obj=*arg1; *(int*)((char*)obj+0x254)=arg0; *(char*)((char*)obj+0x250)=1; }

#pragma dont_inline on
#pragma scheduling invalid_target
int fn_802E95E0(void *arg0, void (*callback)(void), int arg2) {
    void *log_arg = arg0;
    void (*loop_callback)(void) = callback;
    int base = fn_802E2C20();
    volatile int *state_page = (volatile int *)((unsigned int)&lbl_80507288 & 0xFFFF0000);
    goto check_state;
loop_body:
    {
        int value = fn_802E2C20();
        if (value < base || value > base + 0xFA0) {
            fn_802E30C8(lbl_8034E024, log_arg, value - base);
            return 0;
        }
        loop_callback();
    }
check_state:
    if (state_page[0x1CA2] >= 2) goto loop_body;
    return 1;
}
#pragma scheduling on
extern int fn_8012C370(const char *, int, void *, void *, int, int);
extern void fn_8012E81C(const char *);
extern char lbl_8034D9C0[];
extern char lbl_8034E0E8[];
extern char lbl_8034E0F8[];
extern void *memcpy(void *, const void *, unsigned int);
int fn_802E967C(char *arg0, void *arg1, int arg2) {
    char *data;
    int val;
    int count;
    char *dst;
    int sp8;

    if (((int (*)(void *, void (*)(void)))fn_802E95E0)(lbl_8034D9C0 + 0x694, fn_802E8838) == 0) {
        fn_802E30C8(lbl_8034D9C0 + 0x6A8);
        return 0;
    }
    if ((unsigned char)lbl_80560034 != 0) {
        fn_802E30C8(lbl_8034D9C0 + 0x6D8);
        return 0;
    }
    memcpy((void *)lbl_80560020, arg1, arg2);
    val = lbl_80560020;
    *(int *)&lbl_80507288 = 2;
    fn_8012E81C(lbl_8034E0F8);
    data = (char *)&lbl_80507288;
    *(int *)(data + 0x260) = fn_8012C370(lbl_8034E0E8, 0x5256424E, &sp8, data + 0x264, 0, 0);
    dst = data + 0x270;
    count = 0x100;
    *(int *)(data + 0x268) = val;
    *(int *)(data + 0x26C) = arg2;
    while ((*dst++ = *arg0++) != 0) {
        if (--count <= 0) {
            dst[-1] = 0;
            break;
        }
    }
    return 1;
}

__declspec(section ".data") extern int lbl_80507288;
void fn_802E97B4(void) {
    if (lbl_80560035 == 0) {
        if (fn_802ECC10() != 0) return;
        lbl_80560035 = 1;
        if (lbl_80507288 == 1) {
            switch (*(int *)((char *)&lbl_80507288 + 0x25C)) {
            case 0:
                break;
            case -9:
                fn_802E888C(6);
                break;
            case -11:
                fn_802E888C(5);
                break;
            default:
                fn_802E30C8(lbl_8034E0BC);
                break;
            }
        }
        lbl_80560035 = 0;
        *(int *)((char *)&lbl_80507288 + 0x25C) = 0;
    }
}

void fn_802E986C(void) {}

void fn_802E9870(void) {}

void fn_802E9874(void) {}

void fn_802E9878(void) {}

void fn_802E987C(void) {}

void fn_802E9880(void) {}

void fn_802E9884(void) {}

void fn_802E9888(void) {}

