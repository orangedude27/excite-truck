#include <revolution/SC.h>

/* Return the TV aspect ratio (an SCAspectRatio) saved in the System Configuration's
   IPL aspect-ratio item (SC_ITEM_IPL_AR, id 0x1); standard 4:3 is returned when the
   item is missing or holds anything other than widescreen. */
u8 SCGetAspectRatio(void) {
    u8 aspect;

    if (!SCFindU8Item(&aspect, SC_ITEM_IPL_AR)) {
        aspect = SC_ASPECT_STD;
    } else if (aspect != SC_ASPECT_WIDE) {
        aspect = SC_ASPECT_STD;
    }

    return aspect;
}

/* Return the saved horizontal display offset, clamped to [-32, 32] and rounded down to even. */
s8 SCGetDisplayOffsetH(void) {
    s8 item;

    if (!SCFindS8Item(&item, SC_ITEM_IPL_DH)) {
        item = 0;
    } else if (item < -32) {
        item = -32;
    } else if (item > 32) {
        item = 32;
    }

    return item & ~1;
}

void SCGetIdleMode(SCIdleModeInfo* mode) {
    /* Read the two-byte IPL idle-mode item (SC_ITEM_IPL_IDL, id 0x5) into mode:
       wc24 and slot-light flags. Leaves mode untouched if the item is absent. */
    SCFindByteArrayItem(mode, 2, SC_ITEM_IPL_IDL);
}

/* Returns the system language, defaulting by product area if unset or to English if out of range. */
u8 SCGetLanguage(void) {
    u8 item;

    if (!SCFindU8Item(&item, SC_ITEM_IPL_LNG)) {
        if (SCGetProductArea() == SC_AREA_JPN) {
            item = SC_LANG_JP;
        } else {
            item = SC_LANG_EN;
        }
    } else if (item > SC_LANG_KR) {
        item = SC_LANG_EN;
    }

    return item;
}

/* Return the progressive-scan flag (an SCProgressiveMode) saved in the System
   Configuration's IPL progressive-mode item (SC_ITEM_IPL_PGS, id 0x9); interlaced
   is returned when the item is missing or holds anything other than progressive. */
u8 SCGetProgressiveMode(void) {
    u8 progressive;

    if (!SCFindU8Item(&progressive, SC_ITEM_IPL_PGS)) {
        progressive = SC_INTERLACED;
    } else if (progressive != SC_PROGRESSIVE) {
        progressive = SC_INTERLACED;
    }

    return progressive;
}

/* Return whether the screen saver is enabled, read from the System Configuration's
   IPL screen-saver item (SC_ITEM_IPL_SSV, id 0xA); enabled is returned when the item
   is missing, and any value other than TRUE is reported as disabled. */
u8 SCGetScreenSaverMode(void) {
    u8 screenSaver;

    if (!SCFindU8Item(&screenSaver, SC_ITEM_IPL_SSV)) {
        screenSaver = TRUE;
    } else if (screenSaver != TRUE) {
        screenSaver = FALSE;
    }

    return screenSaver;
}

u8 SCGetSoundMode(void) {
    /* Read the audio output mode from the System Configuration's IPL sound
       mode item (SC_ITEM_IPL_SND, id 0xC), defaulting to stereo when the item
       is missing and falling back to stereo for any value that is not one of
       the SCSoundMode values (mono / stereo / surround). */
    u8 item;

    if (!SCFindU8Item(&item, SC_ITEM_IPL_SND)) {
        item = SC_SND_STEREO;
    } else if (item != SC_SND_MONO && item != SC_SND_STEREO &&
               item != SC_SND_SURROUND) {
        item = SC_SND_STEREO;
    }

    return item;
}

void SCGetBtDeviceInfoArray(SCBtDeviceInfoArray* info) {
    SCFindByteArrayItem(info, 0x461, SC_ITEM_BT_DINF);
}

/* Write the Bluetooth device info array (0x461 bytes) to the System Configuration's
   SC_ITEM_BT_DINF item (id 0x15), returning whether the item was replaced. */
BOOL SCSetBtDeviceInfoArray(const SCBtDeviceInfoArray* info) {
    return SCReplaceByteArrayItem(info, 0x461, SC_ITEM_BT_DINF);
}

u32 SCGetBtDpdSensibility(void) {
    /* Get the Bluetooth DPD (pointer) sensitivity from system config (item 0x16),
       defaulting to 5 and clamping the result to the range [1, 5]. */
    u32 item;

    if (!SCFindU32Item(&item, SC_ITEM_BT_SENS)) {
        item = 5;
    } else if (item < 1) {
        item = 1;
    } else if (item > 5) {
        item = 5;
    }

    return item;
}

/* Return whether the Wii Remote's rumble motor is enabled, read from the System
   Configuration's Bluetooth motor-mode item (SC_ITEM_BT_MOT, id 0x18); enabled is
   returned when the item is missing, and any value other than SC_MOTOR_ON is
   reported as SC_MOTOR_OFF. */
u8 SCGetWpadMotorMode(void) {
    u8 motorMode;

    if (!SCFindU8Item(&motorMode, SC_ITEM_BT_MOT)) {
        motorMode = SC_MOTOR_ON;
    } else if (motorMode != SC_MOTOR_ON) {
        motorMode = SC_MOTOR_OFF;
    }

    return motorMode;
}

BOOL SCSetWpadMotorMode(u8 mode) {
    return SCReplaceU8Item(mode, SC_ITEM_BT_MOT);
}

/* Return where the WPAD sensor bar is placed (an SCSensorBarPos), read from the System
   Configuration's Bluetooth sensor-bar item (SC_ITEM_BT_BAR, id 0x19); bottom is
   returned when the item is missing, and any value other than SC_SENSOR_BAR_TOP is
   reported as SC_SENSOR_BAR_BOTTOM. */
u8 SCGetWpadSensorBarPosition(void) {
    u8 sensorBarPos;

    if (!SCFindU8Item(&sensorBarPos, SC_ITEM_BT_BAR)) {
        sensorBarPos = SC_SENSOR_BAR_BOTTOM;
    } else if (sensorBarPos != SC_SENSOR_BAR_TOP) {
        sensorBarPos = SC_SENSOR_BAR_BOTTOM;
    }

    return sensorBarPos;
}

/* Return the Wii Remote's speaker volume saved in the System Configuration's Bluetooth
   speaker-volume item (SC_ITEM_BT_SPKV, id 0x17); the loudest volume is returned when
   the item is missing, and anything above it is clamped down to SC_MAX_SPEAKER_VOLUME. */
u8 SCGetWpadSpeakerVolume(void) {
    u8 volume;

    if (!SCFindU8Item(&volume, SC_ITEM_BT_SPKV)) {
        volume = SC_MAX_SPEAKER_VOLUME;
    } else if (volume > SC_MAX_SPEAKER_VOLUME) {
        volume = SC_MAX_SPEAKER_VOLUME;
    }

    return volume;
}

BOOL SCSetWpadSpeakerVolume(u8 vol) {
    return SCReplaceU8Item(vol, SC_ITEM_BT_SPKV);
}
