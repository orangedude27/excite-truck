#include <types.h>
#include <macros.h>
#include <revolution/OS.h>
#include <revolution/SC.h>
#include <string.h>

#define XOR_KEY 0x73B5DBFA

typedef struct SCRegion {
    s8 area;      // at 0x0
    char name[4]; // at 0x1
} SCRegion;

char lbl_805591E8[] = "AREA";

u8 lbl_8031B120[72] = {
    SC_AREA_JPN, 'J', 'P', 'N', 0,
    SC_AREA_USA, 'U', 'S', 'A', 0,
    SC_AREA_EUR, 'E', 'U', 'R', 0,
    SC_AREA_AUS, 'A', 'U', 'S', 0,
    SC_AREA_BRA, 'B', 'R', 'A', 0,
    SC_AREA_TWN, 'T', 'W', 'N', 0,
    SC_AREA_TWN, 'R', 'O', 'C', 0,
    SC_AREA_KOR, 'K', 'O', 'R', 0,
    SC_AREA_HKG, 'H', 'K', 'G', 0,
    SC_AREA_ASI, 'A', 'S', 'I', 0,
    SC_AREA_LTN, 'L', 'T', 'N', 0,
    SC_AREA_SAF, 'S', 'A', 'F', 0,
    (u8)-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/* Looks up a key in SC product info and copies its value into buf if found. */
static BOOL __SCF1(const char* type, char* buf, u32 sz) {
    u8 ptext;
    BOOL found = FALSE;
    u32 i;
    const u8* settings = (const u8*)OSPhysicalToCached(OS_PHYS_SC_PRDINFO);
    u32 key = XOR_KEY;
    u32 typeOfs = 0;
    u32 bufOfs = 0;

    for (i = 0; i < SC_PRDINFO_SIZE; i++, key = key >> 31 | key << 1) {
        ptext = settings[i];

        if (ptext != 0x00) {
            ptext ^= key;
            if (type[typeOfs] == 0x00 && ptext == '=') {
                found = TRUE;
                break;
            }

            if (((ptext ^ type[typeOfs]) & 0xDF) == 0) {
                typeOfs++;
            } else {
                typeOfs = 0;
            }
        }
    }

    if (found) {
        for (i++; i < SC_PRDINFO_SIZE && bufOfs < sz; i++) {
            key = key >> 31 | key << 1;
            ptext = settings[i];

            if (ptext != 0x00) {
                ptext ^= key;
                if (ptext == '\r' || ptext == '\n') {
                    ptext = 0x00;
                }
            }

            buf[bufOfs++] = ptext;

            if (ptext == 0x00) {
                return TRUE;
            }
        }
    }

    return FALSE;
}

static inline BOOL SCGetProductAreaString(char* buf, u32 sz) {
    return __SCF1(lbl_805591E8, buf, sz);
}

/* Resolve the console's product area code by looking up the "AREA" string in the SC region table. */
s8 SCGetProductArea(void) {
    s8 area;
    char name[4];
    SCRegion* region = (SCRegion*)lbl_8031B120;

    if (SCGetProductAreaString(name, sizeof(name))) {
        for (; (area = region->area) != -1; region++) {
            if (!strcmp(region->name, name)) {
                return area;
            }
        }
    }

    return -1;
}
