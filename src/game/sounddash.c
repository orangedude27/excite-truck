/* Sound debug dash ("SOUND DASH"): an on-screen overlay for browsing and
 * adjusting voice volumes, plus a "sounds.txt" table dump. */
extern int fn_8020A76C(void);
extern char *fn_8020A774(int);
extern void fn_8020BCE4(void);
extern void fn_802E30C8(const char *, ...);

/* Debug-dash state: display mode and the currently selected entry index. */
extern int lbl_8055EE24, lbl_8055EE28;
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
extern void fn_802E3734(int *);
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
            sndEntry = (VoiceSndEntry *)fn_8020A774(entryIdx);
            fn_802E3AD0(outFile, "\t%s\t\t%1.2f\r\n\0\0\0", sndEntry->name, sndEntry->volume);
        }
        fn_802E3AD0(outFile, "end\r\n\r\nend\r\n\0\0\0");
        fn_802E3734(&outFile);
    } else {
        fn_802E30C8("can't write to sounds.txt\0\0");
    }
}
#pragma pop
/* Handle a SOUND DASH debug command: toggle mode, move the selected entry, adjust its volume, or dump sounds.txt. */
/* Handle one SOUND DASH debug-dash command: 0x6D toggles the overlay between the sound-name grid and the volume list (every other command is ignored while the grid is up); 0x128/0x126 move the selected voice entry, 0x125/0x127 step its volume down/up between the two clamps, and 0x53 prints "writing sounds.txt..." then dumps the table.  Returns 1 when the command was handled, 0 otherwise. */ int fn_8020BDB8(int command) {
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
    int soundIndex;
    int drawSlot;
    int entryIndex;
    int isValueColumn;
    int zero = 0;
    unsigned int column;
    unsigned int indexSign;
    int nameX, valueX, textColor, copyRemaining;
    unsigned int slotSign;
    char *sourceText, *destText;
    unsigned char copiedChar;

    /* Draw the "SOUND DASH" debug overlay: sound-name grid in mode 1, sound/value list in mode 0. */
    fn_8023895C();
    fn_80238A74(0xC, 0xC, lbl_8033C5CC, 0xFF2D2DC8);

    if (lbl_8055EE24 == 1) {
        fn_80238B44(7, 7, 0x15E, 0x1C0, 0x8C000000);
        soundIndex = 0;
        do {
            fn_802E6B38(soundIndex, scratch.sp48);
            column = (unsigned int)soundIndex << 28;
            indexSign = (unsigned int)soundIndex >> 31;
            column -= indexSign;
            column = (column << 4) | (column >> 28);
            column += indexSign;
            nameX = 0x14;
            if (soundIndex / 16 != 0)
                nameX = 0x122;
            fn_80238A74(nameX, (column * 0xE) + 0x1A, scratch.sp48, -0x100);
            soundIndex += 1;
        } while (soundIndex < 0x20);
    } else if (lbl_8055EE24 == 0) {
        fn_80238B44(7, 7, 0x12C, 0x1C0, 0x8C000000);
        soundIndex = fn_8020A76C() * 2;
        for (drawSlot = 0; drawSlot < soundIndex; drawSlot++) {
            sourceText = fn_8020A774(drawSlot / 2);
            slotSign = (unsigned int)drawSlot >> 31;
            isValueColumn = ((drawSlot & 1) ^ slotSign) - slotSign;
            entryIndex = (int)(slotSign + drawSlot) >> 1;
            if (isValueColumn == 0) {
                destText = scratch.sp8;
                copyRemaining = 0x40;
                goto copy_text_body;
            copy_text_limit:
                if (--copyRemaining <= 0) {
                    *(destText - 1) = zero;
                    goto copy_text_done;
                }
            copy_text_body:
                copiedChar = (unsigned char)*sourceText;
                sourceText += 1;
                *destText = copiedChar;
                destText += 1;
                if ((signed char)copiedChar == 0)
                    goto copy_text_done;
                else
                    goto copy_text_limit;
            copy_text_done:
                ;
            } else {
                sprintf(scratch.sp8, (const char *)&lbl_8055B5C8, *(float *)(sourceText + 0x20));
            }
            textColor = -0x100;
            if (entryIndex == lbl_8055EE28)
                textColor = 0xFF2D2DC8;
            valueX = 0x14;
            if (isValueColumn != 0)
                valueX = 0xF0;
            fn_80238A74(valueX, (entryIndex * 0xE) + 0x1A, scratch.sp8, textColor);
        }
    }

    fn_802389E4();
}
#pragma scheduling on
