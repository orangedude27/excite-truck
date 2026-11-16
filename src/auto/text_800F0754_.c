// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void __register_global_object(void* p, void* dtor, void* allocator);
extern void* __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F078C(void*, s32);
#pragma push
#pragma small_data off
extern u8 lbl_80412A60[];
extern u8 lbl_80412A6C[];
#pragma pop

/* The static nw4hbm::snd::MemorySoundArchive and the node the PowerPC C++ runtime
 * uses to chain it into its global-destructor list (__register_global_object). */
#define gSoundArchive       lbl_80412A6C
#define gSoundArchiveRegNode lbl_80412A60

/* Byte offsets of the LinkListImpl sentinel at the head of the archive. mNext
 * and mPrev are self-links into the (initially empty) doubly linked list. */
#define ARCHIVE_HEAD 0
#define ARCHIVE_NEXT 4
#define ARCHIVE_PREV 8

/* Compiler-generated global constructor: initialise the static nw4hbm::snd::MemorySoundArchive,
 * pointing its LinkListImpl sentinel at itself, then register its destructor. */
void fn_800F0754(void) {
    void* selfNode = &gSoundArchive[ARCHIVE_NEXT];
    *(void**)&gSoundArchive[ARCHIVE_NEXT] = 0;
    *(void**)&gSoundArchive[ARCHIVE_PREV] = 0;
    *(void**)&gSoundArchive[ARCHIVE_HEAD] = 0;
    *(void**)&gSoundArchive[ARCHIVE_NEXT] = selfNode;
    *(void**)&gSoundArchive[ARCHIVE_PREV] = selfNode;
    __register_global_object(&gSoundArchive,
                             (void*)&__dt__Q36nw4hbm3snd18MemorySoundArchiveFv_800F078C,
                             &gSoundArchiveRegNode);
}
