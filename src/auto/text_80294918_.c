// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <revolution/MTX/mtxtypes.h> /* Vec */

/* One row of the rotation table lbl_804B4030 (text_802924E8_.c): the axis
 * fn_80292698 turns about, the speed its angle grows by per frame, and the 3x3
 * rotation matrix it rebuilds from the two every frame. */
typedef struct RotationAxis {
    Vec axis;         /* +0x00 */
    f32 speed;        /* +0x0C */
    f32 matrix[3][3]; /* +0x10 */
} RotationAxis;       /* 0x34 */

#define ROTATION_AXIS_COUNT 6

/* fn_8000D838 pushes this module's static record (tag byte at +0, next pointer at
 * +4) onto the list headed by lbl_8055D450. */
extern void fn_8000D838(void *);
/* __construct_array, the runtime's C++ array constructor (src/runtime/array.s):
 * calls ctor(element, 1) on each of `count` objects of `size` bytes. */
extern void fn_8002F53C(void *, void *, int, int, int);
extern void fn_8029496C(void);   /* the trivial RotationAxis constructor */
extern unsigned char lbl_8055F760; /* this module's static record */
extern RotationAxis lbl_804B4030[ROTATION_AXIS_COUNT]; /* the rotation table */
extern unsigned char lbl_804B4168[]; /* the chunk cache; entries in use at +0x180 */

#pragma scheduling invalid_target
/* Static initializer (a .ctors entry) of the chunk-system module whose code is in
 * text_802924E8_.c: registers this module's static record with the runtime, runs
 * the default constructor over the six rotation-axis rows and clears the chunk
 * cache's entry count. */
void fn_80294918(void) {
    fn_8000D838(&lbl_8055F760);
    fn_8002F53C(lbl_804B4030, fn_8029496C, 0, sizeof(RotationAxis), ROTATION_AXIS_COUNT);
    *(s32 *)(lbl_804B4168 + 0x180) = 0;
}
