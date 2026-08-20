#ifndef RVL_SDK_SC_SCSYSTEM_H
#define RVL_SDK_SC_SCSYSTEM_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    SC_STATUS_OK,
    SC_STATUS_BUSY,
    SC_STATUS_FATAL,
    SC_STATUS_PARSE
} SCStatus;

typedef enum {
    // IPL settings
    SC_ITEM_IPL_CB,   // Counter bias          (id 0x0)
    SC_ITEM_IPL_AR,   // Aspect ratio          (id 0x1)
    SC_ITEM_IPL_ARN,  // Autorun mode          (id 0x2)
    SC_ITEM_IPL_DH,   // Display horiz offset  (id 0x3)
    SC_ITEM_IPL_E60,  // EuRgb60 mode          (id 0x4)
    SC_ITEM_IPL_IDL,  // Idle mode             (id 0x5)
    SC_ITEM_IPL_LNG,  // Language              (id 0x6)
    SC_ITEM_IPL_NIK,  // Owner nickname        (id 0x7)
    SC_ITEM_IPL_PC,   // Parental controls     (id 0x8)
    SC_ITEM_IPL_PGS,  // Progressive mode      (id 0x9)
    SC_ITEM_IPL_SSV,  // Screen saver mode     (id 0xA)
    SC_ITEM_IPL_SADR, // Simple address        (id 0xB)
    SC_ITEM_IPL_SND,  // Sound mode            (id 0xC)

    // Network settings
    SC_ITEM_NET_CNF,  // Network config               (id 0xD)
    SC_ITEM_NET_CTPC, // Network content restrictions (id 0xE)
    SC_ITEM_NET_PROF, // Network profile              (id 0xF)
    SC_ITEM_NET_WCPC, // WC24 parental controls       (id 0x10)

    // Development settings
    SC_ITEM_DEV_BTM, // Boot mode         (id 0x11)
    SC_ITEM_DEV_VIM, // Video mode        (id 0x12)
    SC_ITEM_DEV_CTC, // Country code      (id 0x13)
    SC_ITEM_DEV_DSM, // Drive-saving mode (id 0x14)

    // Bluetooth settings
    SC_ITEM_BT_DINF, // Bluetooth device info       (id 0x15)
    SC_ITEM_BT_SENS, // Remote sensitivity          (id 0x16)
    SC_ITEM_BT_SPKV, // WPAD speaker volume         (id 0x17)
    SC_ITEM_BT_MOT,  // WPAD motor mode             (id 0x18)
    SC_ITEM_BT_BAR,  // WPAD sensor bar position    (id 0x19)

    // Miscellaneous settings
    SC_ITEM_DVD_CNF, // DVD config           (id 0x1A)
    SC_ITEM_WWW_RST, // WWW restriction      (id 0x1B)

    SC_ITEM_MAX
} SCItemID;

typedef void (*SCFlushCallback)(SCStatus status);

void SCInit(void);
u32 SCCheckStatus(void);

BOOL SCFindByteArrayItem(void* dst, u32 len, SCItemID id);
BOOL SCReplaceByteArrayItem(const void* src, u32 len, SCItemID id);

BOOL SCFindU8Item(u8* dst, SCItemID id);
BOOL SCFindS8Item(s8* dst, SCItemID id);
BOOL SCFindU32Item(u32* dst, SCItemID id);

BOOL SCReplaceU8Item(u8 data, SCItemID id);

void SCFlushAsync(SCFlushCallback callback);

#ifdef __cplusplus
}
#endif
#endif
