/* Sound debug dash ("SOUND DASH"): an on-screen overlay for browsing and
 * adjusting voice volumes, plus a "sounds.txt" table dump. */
extern int fn_8020A76C(void);
extern char *voiceSndGetEntry(int);
extern void fn_8020BCE4(void);
extern void fn_802E30C8(const char *, ...);

/* Debug-dash state: display mode and the currently selected entry index. */
extern int soundDashMode, soundDashSelectedIndex;
/* Volume step, lower clamp and upper clamp. */
extern float lbl_805632C8, lbl_805632CC, lbl_805632D0;
/* "writing sounds.txt..." and the "SOUND DASH" overlay title. */
extern char lbl_8033C5B4[];
extern char lbl_8033C5CC[];
extern void fn_8023895C(void);
extern void fn_802389E4(void);
extern void fn_80238A74(int, int, const char *, int);
extern void fn_80238B44(int, int, int, int, int);
extern void fn_802E6B38(int, char *);
/* "%1.2f" format string. */
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
extern int FileOpenSecondary(const char *);
extern void fn_802E3AD0(int, const char *, ...);
extern void closeFileHandle(int *);
#pragma push
#pragma pool_strings off
#pragma readonly_strings on
/* Dump the voice-sound table to sounds.txt: a header, one "<name>  <volume>" line
 * per entry, then a footer; reports a panic if the file cannot be opened. */
/* Dump the voice-sound table to sounds.txt: write a header, one "<name>  <volume>" line per entry, then a footer; log a panic message if the file cannot be opened. */ void fn_8020BCE4(void) {
    int outFile;
    int entryIdx;
    VoiceSndEntry *sndEntry;
    outFile = FileOpenSecondary("sounds.txt\0");
    if (outFile != -1) {
        fn_802E3AD0(outFile, "tabular samples\r\n\0\0");
        fn_802E3AD0(outFile, "\tname\t\t\tvolume\r\n\0\0\0");
        fn_802E3AD0(outFile, ";\t----\t\t\t------\r\n\0\0");
        for (entryIdx = 0; entryIdx < fn_8020A76C(); entryIdx++) {
            sndEntry = (VoiceSndEntry *)voiceSndGetEntry(entryIdx);
            fn_802E3AD0(outFile, "\t%s\t\t%1.2f\r\n\0\0\0", sndEntry->name, sndEntry->volume);
        }
        fn_802E3AD0(outFile, "end\r\n\r\nend\r\n\0\0\0");
        closeFileHandle(&outFile);
    } else {
        fn_802E30C8("can't write to sounds.txt\0\0");
    }
}
#pragma pop
/* Handle a SOUND DASH debug command: toggle mode, move the selected entry, adjust its volume, or dump sounds.txt. */
/* Handle one SOUND DASH debug command: toggle mode, move the selection, step its volume, or dump sounds.txt. */ /* Handle one SOUND DASH debug-dash command: 0x6D toggles the overlay between the sound-name grid and the volume list (every other command is ignored while the grid is up); 0x128/0x126 move the selected voice entry, 0x125/0x127 step its volume down/up between the two clamps, and 0x53 prints "writing sounds.txt..." then dumps the table.  Returns 1 when the command was handled, 0 otherwise. */ int handleSoundDashCommand(int command) {
    int index;
    VoiceSndEntry *entry;
    float volume;
    switch (command) {
    case SOUND_DASH_CMD_TOGGLE_MODE:
        soundDashMode = !soundDashMode;
        return 1;
    case SOUND_DASH_CMD_NEXT:
        if (soundDashMode != 0) break;
        index = fn_8020A76C() - 1;
        soundDashSelectedIndex = index < soundDashSelectedIndex + 1 ? index : soundDashSelectedIndex + 1;
        return 1;
    case SOUND_DASH_CMD_PREV:
        if (soundDashMode != 0) break;
        index = soundDashSelectedIndex - 1;
        soundDashSelectedIndex = index & ~(index >> 31);
        return 1;
    case SOUND_DASH_CMD_VOL_DOWN:
        if (soundDashMode != 0) break;
        index = soundDashSelectedIndex;
        if (index < fn_8020A76C()) {
            entry = (VoiceSndEntry *)voiceSndGetEntry(index);
            volume = entry->volume - lbl_805632C8;
            volume = volume > lbl_805632CC ? volume : lbl_805632CC;
            entry->volume = volume;
            return 1;
        }
        break;
    case SOUND_DASH_CMD_VOL_UP:
        if (soundDashMode != 0) break;
        index = soundDashSelectedIndex;
        if (index < fn_8020A76C()) {
            entry = (VoiceSndEntry *)voiceSndGetEntry(index);
            volume = lbl_805632C8 + entry->volume;
            volume = volume < lbl_805632D0 ? volume : lbl_805632D0;
            entry->volume = volume;
            return 1;
        }
        break;
    case SOUND_DASH_CMD_DUMP:
        if (soundDashMode != 0) break;
        fn_802E30C8(lbl_8033C5B4);
        fn_8020BCE4();
        return 1;
    }
    return 0;
}

void drawSoundDash(void) {
    struct { char sp8[64]; char sp48[64]; char padding[0xD0]; } scratch;
    int soundIdx;
    int slotIndex;
    int entryIdx;
    int isValueColumn;
    int zero = 0;
    unsigned int gridRow;
    unsigned int rowSign;
    int nameX, valueX, textColor, copyLimit;
    unsigned int slotSign;
    char *srcText, *dstText;
    unsigned char ch;

    /* Draw the SOUND DASH debug overlay: a grid of sound names in mode 1, or a
     * sound-name/volume list with the selected entry highlighted in mode 0. */
    fn_8023895C();
    fn_80238A74(0xC, 0xC, lbl_8033C5CC, 0xFF2D2DC8);

    if (soundDashMode == 1) {
        fn_80238B44(7, 7, 0x15E, 0x1C0, 0x8C000000);
        soundIdx = 0;
        do {
            fn_802E6B38(soundIdx, scratch.sp48);
            gridRow = (unsigned int)soundIdx << 28;
            rowSign = (unsigned int)soundIdx >> 31;
            gridRow -= rowSign;
            gridRow = (gridRow << 4) | (gridRow >> 28);
            gridRow += rowSign;
            nameX = 0x14;
            if (soundIdx / 16 != 0)
                nameX = 0x122;
            fn_80238A74(nameX, (gridRow * 0xE) + 0x1A, scratch.sp48, -0x100);
            soundIdx += 1;
        } while (soundIdx < 0x20);
    } else if (soundDashMode == 0) {
        fn_80238B44(7, 7, 0x12C, 0x1C0, 0x8C000000);
        soundIdx = fn_8020A76C() * 2;
        for (slotIndex = 0; slotIndex < soundIdx; slotIndex++) {
            srcText = voiceSndGetEntry(slotIndex / 2);
            slotSign = (unsigned int)slotIndex >> 31;
            isValueColumn = ((slotIndex & 1) ^ slotSign) - slotSign;
            entryIdx = (int)(slotSign + slotIndex) >> 1;
            if (isValueColumn == 0) {
                dstText = scratch.sp8;
                copyLimit = 0x40;
                goto copy_text_body;
            copy_text_limit:
                if (--copyLimit <= 0) {
                    *(dstText - 1) = zero;
                    goto copy_text_done;
                }
            copy_text_body:
                ch = (unsigned char)*srcText;
                srcText += 1;
                *dstText = ch;
                dstText += 1;
                if ((signed char)ch == 0)
                    goto copy_text_done;
                else
                    goto copy_text_limit;
            copy_text_done:
                ;
            } else {
                sprintf(scratch.sp8, (const char *)&lbl_8055B5C8, *(float *)(srcText + 0x20));
            }
            textColor = -0x100;
            if (entryIdx == soundDashSelectedIndex)
                textColor = 0xFF2D2DC8;
            valueX = 0x14;
            if (isValueColumn != 0)
                valueX = 0xF0;
            fn_80238A74(valueX, (entryIdx * 0xE) + 0x1A, scratch.sp8, textColor);
        }
    }

    fn_802389E4();
}
#pragma scheduling on
