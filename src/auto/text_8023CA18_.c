#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
extern char lbl_803415CC[0xC0];
extern s32 lbl_8055BB68;
extern char lbl_803415E8[];
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8023CA18(void) {
#define SOUND_MENU_STATE lbl_8055BB68  /* s32 menu state: 0 = loading, 2 = ready */
#define UIHideGroup fn_80214A9C
    /* Sound-menu callback: while the menu state is 0 (loading), hide UI group
     * 0x1F; then always hide UI group 1 (the main sound-menu group). */
    if (SOUND_MENU_STATE == 0) {
        UIHideGroup(0x1F);
    }
    UIHideGroup(1);
#undef UIHideGroup
#undef SOUND_MENU_STATE
}

/* No-op UI callback: installed as the handler ("value") of a menu element in
   the frame built by fn_8023CA18; the body does nothing. */
void fn_8023CA50(void) {}

extern char lbl_803414D0[];
extern u8 lbl_8055F160;
extern f32 lbl_8055F164;
extern f32 lbl_8055F168;
extern f32 lbl_8055F16C;
extern f32 lbl_8055F170;
extern f32 lbl_8055F174;
extern s32 lbl_8055F178;
extern s32 lbl_8055F17C;
extern s32 lbl_8055BB70;
extern f32 lbl_80563738;
extern void fn_801333E8(s32, s32 *, u8 *);
extern void LoadFloatOption(s32, void *, f32 *);
extern void LoadIntOptionValue(s32, void *, s32 *);
extern void SetEffectsVolume(f32);
extern void SetSoundQuality(s32);
#pragma push
#pragma scheduling invalid_target
void fn_8023CA54(void) {
    struct Hdr { s32 f0; char pad[12]; };
    s32 zero = 0;
    char *base = (char *)&lbl_803414D0;
    lbl_8055F160 = zero;
    fn_801333E8(4, (s32 *)&((struct Hdr *)base)[0].f0, &lbl_8055F160);
    lbl_8055F164 = lbl_80563738;
    LoadFloatOption(4, &base[0x10], &lbl_8055F164);
    lbl_8055F168 = lbl_80563738;
    LoadFloatOption(4, &base[0x20], &lbl_8055F168);
    lbl_8055F16C = lbl_80563738;
    LoadFloatOption(4, &base[0x30], &lbl_8055F16C);
    SetEffectsVolume(lbl_8055F16C);
    lbl_8055F17C = zero;
    LoadIntOptionValue(4, &lbl_8055BB70, &lbl_8055F17C);
    SetSoundQuality(lbl_8055F17C);
    lbl_8055F170 = lbl_80563738;
    LoadFloatOption(4, &base[0x40], &lbl_8055F170);
    lbl_8055F174 = lbl_80563738;
    LoadFloatOption(4, &base[0x4C], &lbl_8055F174);
    lbl_8055F178 = 1;
    LoadIntOptionValue(4, &base[0x5C], &lbl_8055F178);
}
#pragma pop
s32 fn_8023CB54(void) {
    // Initializes sound options: parses the [SOUND] (section 4) block of the BOPT options file
    // (warning if it fails), then registers the sound debug variables.
#define OPTIONS_SECTION_SOUND 4
    fn_801330E8(OPTIONS_SECTION_SOUND);
#undef OPTIONS_SECTION_SOUND
    fn_8023CA54();
    return 0;
}

s32 fn_8023CB80(void *unused) {
    /* Debug-option callback: reset the UI-animation state flag (fn_80236900) and report success. */
    fn_80236900(unused);
    return 1;
}

extern s32 lbl_804987A0[];
extern s32 lbl_802FA090[];
extern f32 lbl_8056373C;
extern f32 lbl_80563740;
extern s32 lbl_8055BB78;
extern s32 lbl_8055BB80;
extern s32 lbl_8055BB88;
extern s32 lbl_8055BB90;
extern s32 lbl_8055BAB8;
extern s32 lbl_8055BABC;
extern s32 lbl_8055BAC0;
extern s32 GetSelectedMixerDevice(void);
extern void fn_8022D228(void *, s32, s32);
extern void fn_8022D350(void *, void *, s32);
extern void fn_8022D2BC(void *, s32);
extern void fn_8013323C(s32, void *, f32);
extern void fn_80133460(s32, void *, u8);
extern void fn_80133348(s32, void *, s32);
extern void fn_80236914(void);
extern void fn_8023CA54(void);
extern void fn_8023CBA4(void);
struct A48Obj { s32 a48[5]; s32 a5c; s32 pad[4]; s32 a70[10]; s32 a98[64]; };
struct Frame8023 { f32 fl[10]; s32 result; s32 argStruct[5]; struct A48Obj obj; s32 big[90]; };
extern s32 lbl_8055B860;
extern s32 fn_802146BC(s32 *, s32, s32, s32, s32, s32, s32, s32);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8023CBA4(void) {
    s32 data[20];
    s32 c6 = 6;
    s32 csda = (s32)&lbl_8055B860;
    s32 c0 = 0;
    s32 cm1 = -1;
    s32 c1b = 0x1B;
    s32 cm2 = -2;
    s32 cd = 0xD;
    s32 *v = lbl_802FA090;
    data[6] = c6;
    data[5] = csda;
    data[7] = c0;
    data[8] = cm1;
    data[9] = c1b;
    data[11] = c6;
    data[10] = csda;
    data[12] = c0;
    data[13] = cm2;
    data[14] = cd;
    data[15] = lbl_804987A0[0];
    data[16] = lbl_804987A0[1];
    data[17] = lbl_804987A0[2];
    data[18] = lbl_804987A0[3];
    data[19] = lbl_804987A0[4];
    data[0] = v[0];
    data[2] = v[2];
    data[3] = v[3];
    data[4] = v[4];
    data[1] = (s32)&data[5];
    fn_802146BC(data, -999, -999, 1, v[4], v[3], v[2], v[0]);
}
#pragma pop
void fn_8023CC84(char *arg0) {
    struct Frame8023 fr;
    s32 i;
    char *p7c, *p90;
    char *p4c, *pb8, *pc4, *p10, *p40, *pd8, *pe4, *pf0;
    char *base = lbl_803414D0;
    fr.argStruct[0] = (s32)arg0;
    fn_8023CA54();
    if (lbl_8055F160 == 0) {
        lbl_8055F164 = lbl_8056373C;
    }
    p7c = base + 0x7C;
    p90 = base + 0x90;
    fr.result = GetSelectedMixerDevice();
    fr.obj.a5c = (s32)lbl_803415E8;
    fr.obj.a70[3] = fr.result;
    fr.obj.a70[1] = (s32)&lbl_8055F16C;
    fr.obj.a70[0] = 0;
    fr.obj.a70[2] = (s32)&lbl_8055F17C;
    fr.obj.a70[4] = (s32)&lbl_8055F164;
    fr.obj.a70[5] = (s32)fr.obj.a98;
    fr.obj.a70[6] = (s32)&lbl_8055F168;
    fr.obj.a70[7] = (s32)&lbl_8055F170;
    fr.obj.a70[8] = (s32)&lbl_8055F174;
    fr.obj.a70[9] = 0;
    if (fr.obj.a70[9] != 0) {
        *(u8 *)((char *)fr.obj.a70[9] + 0x34) = 1;
        *(f32 *)((char *)fr.obj.a70[9] + 0x28) = lbl_8056373C;
    }
    {
        f32 v = lbl_8055F168;
        if (v != *(f32 *)((char *)fr.obj.a70[9] + 8)) {
            *(u8 *)((char *)fr.obj.a70[9] + 0x4D) = 1;
            *(f32 *)((char *)fr.obj.a70[9] + 8) = v;
        }
    }
    fn_8022D228(fr.obj.a48, 0x11, 0x20);
    i = 0;
    do {
        fn_8022D350(fr.obj.a48, &lbl_8055BB78, 0);
        i++;
    } while (i < 0x11);
    fr.fl[0] = lbl_80563738;
    fr.fl[1] = lbl_8056373C;
    fr.fl[2] = lbl_80563738;
    fr.fl[3] = lbl_8056373C;
    fr.fl[4] = lbl_80563738;
    fr.fl[5] = lbl_8056373C;
    fr.fl[6] = lbl_80563738;
    fr.fl[7] = lbl_8056373C;
    fr.fl[8] = lbl_80563738;
    fr.fl[9] = lbl_8056373C;
    p4c = base + 0x4C;
    pb8 = base + 0xB8;
    pc4 = base + 0xC4;
    p10 = base + 0x10;
    p40 = base + 0x40;
    pd8 = base + 0xD8;
    pe4 = base + 0xE4;
    pf0 = base + 0xF0;
    fr.big[0] = (s32)&lbl_8055BAC0;
    fr.big[1] = 8;
    fr.big[2] = (s32)fn_8023CA18;
    fr.big[3] = 0;
    fr.big[4] = 0;
    fr.big[5] = 0;
    fr.big[6] = 5;
    fr.big[7] = (s32)fr.obj.a48;
    fr.big[8] = 0;
    fr.big[9] = 0;
    fr.big[10] = (s32)&lbl_8055BB80;
    fr.big[11] = 0;
    fr.big[12] = (s32)fn_8023CB54;
    fr.big[13] = 0;
    fr.big[14] = 0;
    fr.big[15] = (s32)p4c;
    fr.big[16] = 9;
    fr.big[17] = (s32)&lbl_8055F174;
    fr.big[18] = *(s32 *)&fr.fl[9];
    fr.big[19] = *(s32 *)&fr.fl[8];
    fr.big[20] = (s32)pb8;
    fr.big[21] = 9;
    fr.big[22] = (s32)&lbl_8055F16C;
    fr.big[23] = *(s32 *)&fr.fl[7];
    fr.big[24] = *(s32 *)&fr.fl[6];
    fr.big[25] = (s32)pc4;
    fr.big[26] = 9;
    fr.big[27] = (s32)&lbl_8055F168;
    fr.big[28] = *(s32 *)&fr.fl[5];
    fr.big[29] = *(s32 *)&fr.fl[4];
    fr.big[30] = (s32)p10;
    fr.big[31] = 9;
    fr.big[32] = (s32)&lbl_8055F164;
    fr.big[33] = *(s32 *)&fr.fl[3];
    fr.big[34] = *(s32 *)&fr.fl[2];
    fr.big[35] = (s32)p40;
    fr.big[36] = 9;
    fr.big[37] = (s32)&lbl_8055F170;
    fr.big[38] = *(s32 *)&fr.fl[1];
    fr.big[39] = *(s32 *)&fr.fl[0];
    fr.big[40] = (s32)&lbl_8055BB88;
    fr.big[41] = 0;
    fr.big[42] = 0;
    fr.big[43] = -1;
    fr.big[44] = 0;
    fr.big[45] = (s32)&lbl_8055BB70;
    fr.big[46] = 7;
    fr.big[47] = (s32)&lbl_8055F17C;
    fr.big[48] = (s32)p7c;
    fr.big[49] = 0;
    fr.big[50] = (s32)pd8;
    fr.big[51] = 7;
    fr.big[52] = (s32)&lbl_8055F178;
    fr.big[53] = (s32)p90;
    fr.big[54] = 0;
    fr.big[55] = (s32)&lbl_8055BB90;
    fr.big[56] = 2;
    fr.big[57] = (s32)&fr.result;
    fr.big[58] = 0;
    fr.big[59] = 0;
    fr.big[60] = (s32)pe4;
    fr.big[61] = 3;
    fr.big[62] = (s32)fr.obj.a98;
    fr.big[63] = 0x100;
    fr.big[64] = 0;
    fr.big[65] = (s32)pf0;
    fr.big[66] = 0xA;
    fr.big[67] = (s32)fr.obj.a48;
    fr.big[68] = 0;
    fr.big[69] = 0;
    fr.big[70] = (s32)&lbl_8055B860;
    fr.big[71] = 6;
    fr.big[72] = (s32)fn_8023CB80;
    fr.big[73] = -1;
    fr.big[74] = 0x1B;
    fr.big[75] = (s32)&lbl_8055BABC;
    fr.big[76] = 8;
    fr.big[77] = (s32)fn_8023CA50;
    fr.big[78] = 1;
    fr.big[79] = 0;
    fr.big[80] = (s32)&lbl_8055BAB8;
    fr.big[81] = 8;
    fr.big[82] = (s32)fn_80236914;
    fr.big[83] = 2;
    fr.big[84] = 0;
    fr.big[85] = lbl_804987A0[0];
    fr.big[86] = lbl_804987A0[1];
    fr.big[87] = lbl_804987A0[2];
    fr.big[88] = lbl_804987A0[3];
    fr.big[89] = lbl_804987A0[4];
    fr.argStruct[1] = (s32)fr.big;
    fr.argStruct[2] = 0;
    fr.argStruct[3] = 0;
    fr.argStruct[4] = 0;
    if (fn_802146BC(fr.argStruct, -999, -999, 1, 0, lbl_804987A0[4], 8, 0x100) == -2) {
        fn_8023CBA4();
    }
    lbl_8055F160 = (lbl_8055F164 > lbl_80563740) ? 1 : 0;
    fn_8013323C(4, lbl_803414D0 + 0x10, lbl_8055F164);
    fn_80133460(4, lbl_803414D0, lbl_8055F160);
    fn_8013323C(4, lbl_803414D0 + 0x20, lbl_8055F168);
    fn_8013323C(4, lbl_803414D0 + 0x40, lbl_8055F170);
    fn_8013323C(4, lbl_803414D0 + 0x4C, lbl_8055F174);
    fn_80133348(4, lbl_803414D0 + 0x5C, lbl_8055F178);
    fn_8022D2BC(fr.obj.a48, -1);
    fr.obj.a5c = (s32)lbl_803415E8;
    if (fr.obj.a70[9] != 0) {
        ((void (*)(void *, s32))((void ***)fr.obj.a70[9])[0][2])((void *)fr.obj.a70[9], 1);
        fr.obj.a70[9] = 0;
    }
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80128668(void *);
/* Deleting destructor for the sound-options panel: install the panel vtable, destroy the owned widget via its virtual destroy(1), clear its pointer, and free the panel when shouldDelete > 0. */
extern "C" void *fn_8023D134(void *soundOptionsPanel, s32 shouldDelete) {
    struct VTable_8023D134 {
        virtual void destroy(s32);
    };
    if (soundOptionsPanel != NULL) {
        void *ownedWidget = *(void **)((u8 *)soundOptionsPanel + 0x38);
        *(void **)soundOptionsPanel = (void *)lbl_803415E8;
        if (ownedWidget != NULL) {
            if (ownedWidget != NULL)
                ((VTable_8023D134 *)ownedWidget)->destroy(1);
            *(void **)((u8 *)soundOptionsPanel + 0x38) = NULL;
        }
        if (shouldDelete > 0)
            fn_80128668(soundOptionsPanel);
    }
    return soundOptionsPanel;
}
#pragma scheduling on
#pragma cplusplus off
void fn_8023D1C0(void) {
    /* Open the sound settings menu: flag it as loading, build the "sound.lyt"
     * layout, then flag it as ready. */
    #define SOUND_MENU_STATE  lbl_8055BB68  /* s32 menu state: 0 = loading, 2 = ready */
    #define SOUND_LAYOUT_NAME lbl_803415CC  /* "sound.lyt" */
    #define CreateSoundMenu   fn_8023CC84   /* builds the sound settings layout/menu */
    SOUND_MENU_STATE = 0;
    CreateSoundMenu(SOUND_LAYOUT_NAME);
    SOUND_MENU_STATE = 2;
    #undef SOUND_MENU_STATE
    #undef SOUND_LAYOUT_NAME
    #undef CreateSoundMenu
}

/* Empty no-op method in the SoundOptions panel vtable (lbl_803415E8 slot +0x24):
 * this slot has no behaviour for the sound-options panel. */
void fn_8023D1F8(void) {}

extern void fn_80221EA0(void *, s32, s32, s32);
extern s32 GetMixerDeviceCount(void);
extern void *GetMixerDevice(s32);
extern char *strcpy(char *, const char *);
extern u8 lbl_8055BB98;
/* Refreshes this object's cached field pointers and copies the selected item's name (or "N/A") into its name buffer. */
void fn_8023D1FC(void *obj) {
    s32 itemIndex;
    void *item;
    fn_80221EA0(obj, 2, *(s32 *)((u8 *)obj + 0x24), 4);
    fn_80221EA0(obj, 0, *(s32 *)((u8 *)obj + 0x18), 4);
    fn_80221EA0(obj, 1, *(s32 *)((u8 *)obj + 0x20), 4);
    fn_80221EA0(obj, 3, *(s32 *)((u8 *)obj + 0x1c), 4);
    fn_80221EA0(obj, 4, *(s32 *)((u8 *)obj + 0x2c), 4);
    fn_80221EA0(obj, 5, *(s32 *)((u8 *)obj + 0x30), 4);
    fn_80221EA0(obj, 6, *(s32 *)((u8 *)obj + 0x34), 4);
    itemIndex = **(s32 **)((u8 *)obj + 0x24);
    if (itemIndex >= 0 && itemIndex < GetMixerDeviceCount()) {
        item = GetMixerDevice(itemIndex);
#pragma cplusplus on
        struct ItemView {
            virtual void unused();
            virtual const char* getName();
        };
        strcpy(*(char **)((u8 *)obj + 0x28), ((ItemView*)item)->getName());
#pragma cplusplus reset
    } else {
        strcpy(*(char **)((u8 *)obj + 0x28), (const char*)&lbl_8055BB98);
    }
}

extern void SetSelectedMixerDevice(int);
extern void fn_8020A5F8(float *, float);

/* Sound-options panel (vtable lbl_803415E8: deleting destructor fn_8023D134,
 * refresh fn_8023D1FC, apply-field fn_8023D304).  Its fields 0..6 are the value
 * pointers fn_8023D1FC registers with fn_80221EA0; fn_8023D304 pushes the field
 * the player changed into the sound code. */
typedef struct SoundOptions {
    u8 pad00[0x14];
    void *fieldList;     /* 0x14 field list fn_80221EA0 passes on */
    f32 *effectsVolume;  /* 0x18 field 0: "effects_volume" */
    f32 *musicVolume;    /* 0x1C field 3: music volume */
    s32 *speakerMode;    /* 0x20 field 1: 0..2 */
    s32 *deviceIndex;    /* 0x24 field 2: chosen sound device */
    char *deviceName;    /* 0x28 its name, STR_N_A when there is none */
    f32 *level;          /* 0x2C field 4: level handed to `widget` */
    s32 f30;             /* 0x30 field 5 */
    s32 f34;             /* 0x34 field 6 */
    void *widget;        /* 0x38 level (+0x8) and dirty flags (+0x49..+0x4D) */
} SoundOptions;

#define sound_device_count  GetMixerDeviceCount /* size of the sound device list */
#define sound_device_get    GetMixerDevice /* index -> device (getName at vtable +0xC) */
#define sound_device_select SetSelectedMixerDevice /* index -> current device */
#define effects_volume_set  SetEffectsVolume /* clamped, saved as "effects_volume" */
#define speaker_mode_set    SetSoundQuality /* 0..2, else 0 */
#define music_volume_set    fn_8020A5F8 /* f32 music volume */
#define STR_N_A             lbl_8055BB98 /* "N/A" */
/* Sound-options panel's "field changed" method (vtable lbl_803415E8 slot 0x18):
 * pushes the value of the field the player moved into the sound code.  Field 2
 * is the sound device: its index is clamped to the device list, selected, and
 * the device's name (or "N/A") is copied into the panel's name buffer. */
void fn_8023D304(SoundOptions *panel, s32 field) {
    f32 *value;
    f32 level;
    s32 idx;
    void *device;
    void *widget;
    switch (field) {
    case 2:
        if (*panel->deviceIndex >= sound_device_count()) {
            *panel->deviceIndex = sound_device_count() - 1;
        }
        sound_device_select(*panel->deviceIndex);
        idx = *panel->deviceIndex;
        if (idx >= 0 && idx < sound_device_count()) {
#pragma cplusplus on
            struct DeviceView { virtual void u0(); virtual const char *getName(); };
            device = sound_device_get(idx);
            strcpy(panel->deviceName, ((struct DeviceView *)device)->getName());
#pragma cplusplus reset
            return;
        }
        strcpy(panel->deviceName, (const char *)&STR_N_A);
        return;
    case 3:
        value = panel->musicVolume;
        music_volume_set(value, *value);
        return;
    case 0:
        value = panel->effectsVolume;
        ((void (*)(f32 *, f32))effects_volume_set)(value, *value);
        return;
    case 1:
        speaker_mode_set(*panel->speakerMode);
        return;
    case 4:
        widget = panel->widget;
        if (widget != 0) {
            level = *panel->level;
            if (level != *(f32 *)((char *)widget + 8)) {
                *(char *)((char *)widget + 0x4D) = 1;
                *(f32 *)((char *)widget + 8) = level;
            }
            widget = panel->widget;
            *(char *)((char *)widget + 0x4A) = 1;
            *(char *)((char *)widget + 0x4C) = 0;
            widget = panel->widget;
            *(char *)((char *)widget + 0x49) = 1;
            *(char *)((char *)widget + 0x4B) = 0;
            *(char *)((char *)widget + 0x4A) = 0;
        }
        return;
    case 5:
    case 6:
        return;
    default:
        return;
    }
}

extern s32 lbl_8055BB68;

