#ifndef RVL_SDK_SI_SIBIOS_H
#define RVL_SDK_SI_SIBIOS_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    SI_CHAN_0,
    SI_CHAN_1,
    SI_CHAN_2,
    SI_CHAN_3,

    SI_MAX_CHAN,
    SI_CHAN_NONE = -1,
} SIChannel;

typedef enum {
    SI_TYPE_0,
    SI_TYPE_1,
    SI_TYPE_2,
    SI_TYPE_3,

    SI_MAX_TYPE
} SIType;

/**
 * The 24-bit reply to the SI_CMD_STATUS ("type and status") command, cached
 * per channel in SIBios.c's Type[]. Its low byte is the transfer status; the
 * rest describes the device on the channel and, for a wireless receiver, the
 * wireless ID it holds.
 */
#define SI_STATUS_ERROR_MASK 0x0000000f  //!< error bits of the status byte
#define SI_TYPE_MASK 0x18000000          //!< device type field
#define SI_TYPE_GC 0x08000000            //!< GameCube protocol device
#define SI_TYPE_GC_WIRELESS 0x80000000   //!< device is a wireless receiver
#define SI_TYPE_GC_ID_REQUEST 0x40000000 //!< receiver wants the ID in its reply
#define SI_TYPE_GC_FAULT 0x04000000      //!< receiver reports a fault
#define SI_WIRELESS_SET 0x00100000       //!< an ID is programmed in the device
#define SI_WIRELESS_ID_MASK 0x00cfff00   //!< wireless ID, at SI_WIRELESS_ID_SHIFT
#define SI_WIRELESS_ID_SHIFT 8
#define SI_CMD_SET_WIRELESS 0x4e         //!< command storing a wireless ID

typedef void (*SICallback)(s32 chan, u32 status);

void SIInit(void);
u32 SISetXY(u32 lines, u32 times);
BOOL SITransfer(s32 chan, void* outAddr, u32 outSize, void* inAddr, u32 inSize,
                SICallback callback, s64 wait);
u32 SIGetType(s32 chan);

#ifdef __cplusplus
}
#endif
#endif
