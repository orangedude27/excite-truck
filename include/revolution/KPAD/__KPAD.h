#ifndef RVL_SDK_KPAD_PRIVATE_H
#define RVL_SDK_KPAD_PRIVATE_H

#include <types.h>

typedef struct KPADInsideStatus {
    u8 _pad[0xBC];
    f32 center_org_x;
    f32 center_org_y;
    f32 dpd2pos_scale;
} KPADInsideStatus;

#endif
