// sounddash - sound debug dash ("SOUND DASH", sounds.txt dump).
// Recovered TU window 0x8020BCE4..0x8020C114+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_8020C114 (+ .ctors slot 0x802ED394) remains in
// auto/text_8020C114_.c pending a promotion pass.
extern int fn_8020A76C(void);
extern char *fn_8020A774(int);
extern void fn_8020BCE4(void);
extern void fn_802E30C8(const char *, ...);
extern int lbl_8055EE24, lbl_8055EE28;
extern float lbl_805632C8, lbl_805632CC, lbl_805632D0;
extern char lbl_8033C5B4[];
extern char lbl_8033C5CC[];
extern void fn_8023895C(void);
extern void fn_802389E4(void);
extern void fn_80238A74(int, int, const char *, int);
extern void fn_80238B44(int, int, int, int, int);
extern void fn_802E6B38(int, char *);
extern char lbl_8055B5C8;
extern int sprintf(char *, const char *, ...);

typedef struct {
    char name[0x20];
    float volume;
} VoiceSndEntry;

enum SoundDashCommand {
    SOUND_DASH_CMD_DUMP = 0x53,
    SOUND_DASH_CMD_TOGGLE_MODE = 0x6D,
    SOUND_DASH_CMD_VOL_DOWN = 0x125,
    SOUND_DASH_CMD_PREV = 0x126,
    SOUND_DASH_CMD_VOL_UP = 0x127,
    SOUND_DASH_CMD_NEXT = 0x128
};

#pragma scheduling invalid_target
extern char lbl_8033C530[];
extern int fn_802E3D68(const char *);
extern void fn_802E3AD0(int, const char *, ...);
extern void fn_802E3734(int *);
#pragma push
#pragma pool_strings off
#pragma readonly_strings on
void fn_8020BCE4(void) {
    int handle;
    int i;
    void *item;
    handle = fn_802E3D68("sounds.txt\0");
    if (handle != -1) {
        fn_802E3AD0(handle, "tabular samples\r\n\0\0");
        fn_802E3AD0(handle, "\tname\t\t\tvolume\r\n\0\0\0");
        fn_802E3AD0(handle, ";\t----\t\t\t------\r\n\0\0");
        for (i = 0; i < fn_8020A76C(); i++) {
            item = fn_8020A774(i);
            fn_802E3AD0(handle, "\t%s\t\t%1.2f\r\n\0\0\0", item, *(float *)((char *)item + 0x20));
        }
        fn_802E3AD0(handle, "end\r\n\r\nend\r\n\0\0\0");
        fn_802E3734(&handle);
    } else {
        fn_802E30C8("can't write to sounds.txt\0\0");
    }
}
#pragma pop
/* Handle a SOUND DASH debug command: toggle mode, move the selected entry, adjust its volume, or dump sounds.txt. */
int fn_8020BDB8(int command) {
    int index;
    VoiceSndEntry *entry;
    float volume;
    switch (command) {
    case SOUND_DASH_CMD_TOGGLE_MODE:
        lbl_8055EE24 = !lbl_8055EE24;
        return 1;
    case SOUND_DASH_CMD_NEXT:
        if (lbl_8055EE24 != 0) break;
        index = fn_8020A76C() - 1;
        lbl_8055EE28 = index < lbl_8055EE28 + 1 ? index : lbl_8055EE28 + 1;
        return 1;
    case SOUND_DASH_CMD_PREV:
        if (lbl_8055EE24 != 0) break;
        index = lbl_8055EE28 - 1;
        lbl_8055EE28 = index & ~(index >> 31);
        return 1;
    case SOUND_DASH_CMD_VOL_DOWN:
        if (lbl_8055EE24 != 0) break;
        index = lbl_8055EE28;
        if (index < fn_8020A76C()) {
            entry = (VoiceSndEntry *)fn_8020A774(index);
            volume = entry->volume - lbl_805632C8;
            volume = volume > lbl_805632CC ? volume : lbl_805632CC;
            entry->volume = volume;
            return 1;
        }
        break;
    case SOUND_DASH_CMD_VOL_UP:
        if (lbl_8055EE24 != 0) break;
        index = lbl_8055EE28;
        if (index < fn_8020A76C()) {
            entry = (VoiceSndEntry *)fn_8020A774(index);
            volume = lbl_805632C8 + entry->volume;
            volume = volume < lbl_805632D0 ? volume : lbl_805632D0;
            entry->volume = volume;
            return 1;
        }
        break;
    case SOUND_DASH_CMD_DUMP:
        if (lbl_8055EE24 != 0) break;
        fn_802E30C8(lbl_8033C5B4);
        fn_8020BCE4();
        return 1;
    }
    return 0;
}

void fn_8020BF58(void) {
    struct { char sp8[64]; char sp48[64]; char padding[0xD0]; } scratch;
    int var_r29;
    int var_r28;
    int temp_r26;
    int temp_r27;
    int zero = 0;
    unsigned int temp_r0;
    unsigned int temp_r3;
    int var_r3, var_r3_3, var_r6_2, var_r5;
    unsigned int temp_r4;
    char *var_r3_2, *var_r6;
    unsigned char temp_r4_2;

    /* Draw the "SOUND DASH" debug overlay: sound-name grid in mode 1, sound/value list in mode 0. */
    fn_8023895C();
    fn_80238A74(0xC, 0xC, lbl_8033C5CC, 0xFF2D2DC8);

    if (lbl_8055EE24 == 1) {
        fn_80238B44(7, 7, 0x15E, 0x1C0, 0x8C000000);
        var_r29 = 0;
        do {
            fn_802E6B38(var_r29, scratch.sp48);
            temp_r0 = (unsigned int)var_r29 << 28;
            temp_r3 = (unsigned int)var_r29 >> 31;
            temp_r0 -= temp_r3;
            temp_r0 = (temp_r0 << 4) | (temp_r0 >> 28);
            temp_r0 += temp_r3;
            var_r3 = 0x14;
            if (var_r29 / 16 != 0)
                var_r3 = 0x122;
            fn_80238A74(var_r3, (temp_r0 * 0xE) + 0x1A, scratch.sp48, -0x100);
            var_r29 += 1;
        } while (var_r29 < 0x20);
    } else if (lbl_8055EE24 == 0) {
        fn_80238B44(7, 7, 0x12C, 0x1C0, 0x8C000000);
        var_r29 = fn_8020A76C() * 2;
        for (var_r28 = 0; var_r28 < var_r29; var_r28++) {
            var_r3_2 = fn_8020A774(var_r28 / 2);
            temp_r4 = (unsigned int)var_r28 >> 31;
            temp_r27 = ((var_r28 & 1) ^ temp_r4) - temp_r4;
            temp_r26 = (int)(temp_r4 + var_r28) >> 1;
            if (temp_r27 == 0) {
                var_r6 = scratch.sp8;
                var_r5 = 0x40;
                goto copy_text_body;
            copy_text_limit:
                if (--var_r5 <= 0) {
                    *(var_r6 - 1) = zero;
                    goto copy_text_done;
                }
            copy_text_body:
                temp_r4_2 = (unsigned char)*var_r3_2;
                var_r3_2 += 1;
                *var_r6 = temp_r4_2;
                var_r6 += 1;
                if ((signed char)temp_r4_2 == 0)
                    goto copy_text_done;
                else
                    goto copy_text_limit;
            copy_text_done:
                ;
            } else {
                sprintf(scratch.sp8, (const char *)&lbl_8055B5C8, *(float *)(var_r3_2 + 0x20));
            }
            var_r6_2 = -0x100;
            if (temp_r26 == lbl_8055EE28)
                var_r6_2 = 0xFF2D2DC8;
            var_r3_3 = 0x14;
            if (temp_r27 != 0)
                var_r3_3 = 0xF0;
            fn_80238A74(var_r3_3, (temp_r26 * 0xE) + 0x1A, scratch.sp8, var_r6_2);
        }
    }

    fn_802389E4();
}
#pragma scheduling on
