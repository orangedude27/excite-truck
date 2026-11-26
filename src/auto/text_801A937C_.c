// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_80435050[];
extern unsigned char lbl_80333D18[];
extern unsigned char lbl_8055E5C0;
extern void fn_8000D838(void *);
extern void fn_801312EC(void *, void *);
#pragma scheduling invalid_target
/* Register the static-destructor record for the global message cache, then bind
 * each cache slot in lbl_80435050 to its label-string key in lbl_80333D18. */
void bindMessageCacheKeys(void) {
    unsigned char * const entries = lbl_80435050;
    unsigned char * const keys = lbl_80333D18;
    fn_8000D838(&lbl_8055E5C0);
    fn_801312EC(entries + 0x338, keys + 0x126C);
    fn_801312EC(entries + 0x344, keys + 0x1288);
    fn_801312EC(entries + 0x350, keys + 0x12A4);
    fn_801312EC(entries + 0x35C, keys + 0x12C0);
    fn_801312EC(entries + 0x368, keys + 0x12DC);
    fn_801312EC(entries + 0x374, keys + 0x12F8);
    fn_801312EC(entries + 0x380, keys + 0x1314);
    fn_801312EC(entries + 0x38C, keys + 0x1330);
    fn_801312EC(entries + 0x398, keys + 0x1350);
    fn_801312EC(entries + 0x3A4, keys + 0x1368);
    fn_801312EC(entries + 0x3B0, keys + 0x1384);
    fn_801312EC(entries + 0x3BC, keys + 0x13A0);
    fn_801312EC(entries + 0x3C8, keys + 0x13B8);
    fn_801312EC(entries + 0x3D4, keys + 0x13D0);
    fn_801312EC(entries + 0x3E0, keys + 0x13EC);
    fn_801312EC(entries + 0x3EC, keys + 0x1408);
    fn_801312EC(entries + 0x3F8, keys + 0x1420);
    fn_801312EC(entries + 0x404, keys + 0x1438);
    fn_801312EC(entries + 0x410, keys + 0x1450);
    fn_801312EC(entries + 0x41C, keys + 0x1468);
    fn_801312EC(entries + 0x428, keys + 0x1480);
    fn_801312EC(entries + 0x434, keys + 0x1498);
    fn_801312EC(entries + 0x440, keys + 0x14B0);
    fn_801312EC(entries + 0x44C, keys + 0x14C8);
    fn_801312EC(entries + 0x458, keys + 0x14E0);
    fn_801312EC(entries + 0x464, keys + 0x14F8);
    fn_801312EC(entries + 0x470, keys + 0x1510);
    fn_801312EC(entries + 0x47C, keys + 0x1528);
    fn_801312EC(entries + 0x488, keys + 0x1540);
    fn_801312EC(entries + 0x494, keys + 0x1558);
    fn_801312EC(entries + 0x4A0, keys + 0x1570);
    fn_801312EC(entries + 0x4AC, keys + 0x1588);
    fn_801312EC(entries + 0x4B8, keys + 0x15A0);
    fn_801312EC(entries + 0x4C4, keys + 0x15B8);
    fn_801312EC(entries + 0x4D0, keys + 0x15D0);
    fn_801312EC(entries + 0x4DC, keys + 0x15E8);
    fn_801312EC(entries + 0x4E8, keys + 0x1600);
    fn_801312EC(entries + 0x4F4, keys + 0x1618);
    fn_801312EC(entries + 0x500, keys + 0x1630);
    fn_801312EC(entries + 0x50C, keys + 0x164C);
    fn_801312EC(entries + 0x518, keys + 0x1668);
    fn_801312EC(entries + 0x524, keys + 0x1684);
    fn_801312EC(entries + 0x530, keys + 0x16A4);
    fn_801312EC(entries + 0x53C, keys + 0x16C8);
    fn_801312EC(entries + 0x548, keys + 0x16E8);
    fn_801312EC(entries + 0x554, keys + 0x1700);
    fn_801312EC(entries + 0x560, keys + 0x1718);
    fn_801312EC(entries + 0x56C, keys + 0x1738);
    fn_801312EC(entries + 0x578, keys + 0x1750);
    fn_801312EC(entries + 0x584, keys + 0x1768);
    fn_801312EC(entries + 0x590, keys + 0x1780);
    fn_801312EC(entries + 0x59C, keys + 0x1798);
    fn_801312EC(entries + 0x5A8, keys + 0x17B0);
    fn_801312EC(entries + 0x5B4, keys + 0x17C8);
    fn_801312EC(entries + 0x5C0, keys + 0x17E0);
    fn_801312EC(entries + 0x5CC, keys + 0x17F8);
}
#pragma scheduling on
