// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E890;
int fn_80128670(int);
int fn_8012850C(int, const void *);
void fn_801CECE0(void);
extern const char lbl_80338050[];
#pragma scheduling invalid_target
void fn_801CEC80(void) {
    lbl_8055E890 = fn_8012850C(0x180, lbl_80338050);
    fn_801CECE0();
}
#pragma scheduling on
void fn_801CECB4(void) {
    fn_80128670(lbl_8055E890);
    lbl_8055E890 = 0;
}

/* Reset 8 entries of 0x30 bytes (4 sub-slots of 0xC: id, f4, f8) in lbl_8055E890 to inactive/default values. */
void fn_801CECE0(void) {
    extern int lbl_8055E890;
    extern float lbl_80562A20;
    register float zeroValue = lbl_80562A20;
    register char *entryPtr;
    register int entryOffset = 0;
    register int inactiveId = -1;
    register int entryIndex;
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        entryPtr = (char *)lbl_8055E890;
        entryPtr += entryOffset;
        *(int *)entryPtr = inactiveId;
        entryOffset += 0x30;
        *(float *)(entryPtr + 8) = zeroValue;
        *(float *)(entryPtr + 4) = zeroValue;
        *(int *)(entryPtr + 0xC) = inactiveId;
        *(float *)(entryPtr + 0x14) = zeroValue;
        *(float *)(entryPtr + 0x10) = zeroValue;
        *(int *)(entryPtr + 0x18) = inactiveId;
        *(float *)(entryPtr + 0x20) = zeroValue;
        *(float *)(entryPtr + 0x1C) = zeroValue;
        *(int *)(entryPtr + 0x24) = inactiveId;
        *(float *)(entryPtr + 0x2C) = zeroValue;
        *(float *)(entryPtr + 0x28) = zeroValue;
    }
}

void fn_801CEDDC(void) {
    extern int lbl_8055E890;
    extern float lbl_80562A20, lbl_80562A24, lbl_80562A28, lbl_80562A2C, lbl_80562A30;
    register float decay = lbl_80562A30;
    register float min = lbl_80562A20;
    register float threshold = lbl_80562A2C;
    register float max = lbl_80562A28;
    register float step = lbl_80562A24;
    register char *p;
    register int i;
    register int j;
    for (i = 0; i < 8; ++i) {
        p = (char *)lbl_8055E890 + i * 0x30;
        for (j = 0; j < 4; ++j) {
            if (*(int *)p >= 0) {
                register float v = *(float *)(p + 4) + step;
                *(float *)(p + 4) = v;
                if (v > max) {
                    *(int *)p = -1;
                } else if (*(float *)(p + 4) > threshold) {
                    register float speed = *(float *)(p + 8) - decay;
                    if (min > speed)
                        speed = min;
                    *(float *)(p + 8) = speed;
                }
            }
            p += 0xc;
        }
    }
}

extern float lbl_80562A20;
extern void *fn_8017960C(void);
extern void fn_801B916C(void *);
extern void *fn_8017960C();
extern void fn_801B916C();
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Populate the 4 damage-car slots (+0x74, stride 0x18) of each 0xE0-byte record in manager
 * from the dmg_car_info table (lbl_8055E890) and the referenced car object (fn_8017960C),
 * then invoke fn_801B916C. */
void fn_801CEEC8(void *manager) {
    register float zeroFloat;
    register char *record;
    register int zeroInt;
    register char *srcSlot;
    register char *dstSlot;
    register int recordIndex;
    register int slotIndex;
    zeroFloat = lbl_80562A20;
    record = (char *)manager + 4;
    recordIndex = 0;
    zeroInt = 0;
    goto outer_check;
outer_body:
    dstSlot = record + 0x74;
    slotIndex = 0;
    srcSlot = (char *)lbl_8055E890 + *(int *)(record + 0x60) * 0x30;
    do {
        register int carOrObj;
        carOrObj = *(int *)srcSlot;
        *(int *)dstSlot = carOrObj;
        *(float *)(dstSlot + 4) = *(float *)(srcSlot + 4);
        *(float *)(dstSlot + 0x10) = *(float *)(srcSlot + 8);
        if (carOrObj >= 0) {
            carOrObj = (int)fn_8017960C(carOrObj);
            *(float *)(dstSlot + 8) = *(float *)((char *)carOrObj + 0x2690);
            *(float *)(dstSlot + 0xc) = *(float *)((char *)carOrObj + 0x2694);
            *(int *)(dstSlot + 0x14) = *(int *)((char *)carOrObj + 0x268c);
        } else {
            *(float *)(dstSlot + 8) = zeroFloat;
            *(int *)(dstSlot + 0x14) = zeroInt;
        }
        slotIndex++;
        srcSlot += 0xc;
        dstSlot += 0x18;
    } while (slotIndex < 4);
    record += 0xe0;
    recordIndex++;
outer_check:
    if (recordIndex < *(int *)((char *)manager + 0x394))
        goto outer_body;
    fn_801B916C(manager);
}
#pragma pop
