// strm — streaming ("StrmEnd: used %d of %d entries").
// Recovered TU window 0x802E72B8..0x802E7570 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E7570 (+ .ctors slot 0x802ED60C) remains in
// auto/text_802E7570_.c pending a promotion pass.
  typedef struct {
      int startSector;
      int endSector;
      int size;
      char name[0x80];
  } StreamEntry;
  extern void fn_802E3990(void);
extern int fn_802E3734(int *);
extern int findStreamEntryBySector(int);
extern int FileLookup(void *);
extern void fn_802E3A14(int);
extern void File_read(int, void *, int);
extern unsigned char lbl_804FC978[];
extern int lbl_8055FFD8;
extern int lbl_8055FFDC;
extern signed char lbl_8055FFE0;
extern const char lbl_8034D7D8[];
extern int fn_802E30C8(const char *, ...);
#pragma dont_inline on
/* Round a byte count up to a whole number of 2048-byte sectors (ceil(size/2048)). */
int fn_802E72B8(int size) {
    return (size + 0x7ff) / 2048;
}

#pragma push
#pragma scheduling invalid_target
/* Find the stream entry whose sector range [startSector, endSector) contains
 * `sector`; return its index in the entry table, or -1 if none matches. */
int findStreamEntryBySector(int sector) {
    unsigned char *entry = lbl_804FC978;
    int index = 0;
    int remaining;
    for (remaining = lbl_8055FFD8; remaining > 0; remaining--) {
        if (sector >= *(int *)entry && sector < *(int *)(entry + 4))
            return index;
        entry += 0x90;
        index++;
    }
    return -1;
}
#pragma pop

void fn_802E7318(void) {
    /* Begin streaming: reset the sector cursor and entry count, and set the active flag. */
    lbl_8055FFDC = 0;
    lbl_8055FFD8 = 0;
    lbl_8055FFE0 = 1;
}

#pragma scheduling invalid_target
void fn_802E7330(void) {
    /* Stop stream loading, clear the active flag, and log the entries used out of 0x100 plus the sectors used. */
    lbl_8055FFE0 = 0;
    fn_802E30C8(lbl_8034D7D8, lbl_8055FFD8, 0x100, lbl_8055FFDC);
}
#pragma scheduling on
extern int stricmp(const char *, const char *);
extern int fn_802E37C4(void);
extern int fn_802E72B8(int);
#pragma scheduling invalid_target
int fn_802E7354(const char *name) {
    int fileIndex;
    int index;
    unsigned char c;
    char *dst;
    int remaining;
    unsigned char *entry;
    int size;
    int blocks;
    entry = lbl_804FC978;
    index = 0;
    goto search_test;
search_body:
    if (stricmp(name, (char *)(entry + 0x10)) == 0)
        return index;
    entry += 0x90;
    index++;
search_test:
    if (index < lbl_8055FFD8)
        goto search_body;
    fileIndex = FileLookup((void *)name);
    if (fileIndex == -1)
        goto fail;
    index = lbl_8055FFD8++;
    entry = lbl_804FC978 + index * 0x90;
    dst = (char *)(entry + 0x10);
    remaining = 0x80;
    goto copy_start;
dec:
    if (--remaining <= 0) {
        dst[-1] = 0;
        goto done;
    }
copy_start:
    c = (unsigned char)*name++;
    *dst++ = (char)c;
    if ((signed char)c != 0)
        goto dec;
done:
    size = fn_802E37C4();
    blocks = fn_802E72B8(size);
    *(int *)entry = lbl_8055FFDC;
    lbl_8055FFDC += blocks;
    *(int *)(entry + 4) = lbl_8055FFDC;
    *(int *)(entry + 8) = size;
    fn_802E3734(&fileIndex);
    return index;
fail:
    return -1;
}
void fn_802E746C(int index, int *outStartSector, int *outSize) {
    /* Report the start sector (in 2048-byte units) and byte size of stream entry `index`. */
    StreamEntry *entry = (StreamEntry *)(lbl_804FC978 + index * 0x90);
    *outStartSector = entry->startSector;
    *outSize = entry->size;
}

#pragma push
#pragma use_lmw_stmw off
/* Open the stream entry containing arg0, seek to its byte offset, and read up to arg2 bytes into arg1. */
/* StreamRead: find the stream entry covering this sector, open its file, seek to the byte offset within it and read up to maxBytes into dst; return the file handle (or -1 on failure). */ int fn_802E748C(int sector, void *dst, int maxBytes, int arg3) {
    unsigned char *entry;
    int bytesToRead;
    int entryIndex;
    int fileId;
    int byteOffset;
    entryIndex = findStreamEntryBySector(sector);
    if (entryIndex < 0) return -1;
    entry = lbl_804FC978 + entryIndex * 0x90;
    fileId = FileLookup(entry + 0x10);
    if (fileId == -1) return -1;
    byteOffset = (sector - *(int *)entry) << 11;
    ((void (*)(int, int))fn_802E3A14)(fileId, byteOffset);
    bytesToRead = (*(int *)(entry + 8) - byteOffset + 0x1f) & ~0x1f;
    if (bytesToRead > maxBytes) bytesToRead = maxBytes;
    File_read(fileId, dst, bytesToRead);
    return fileId;
}
#pragma pop
/* Stream-end callback thunk: tail-calls fn_802E3990 to end the file stream for
 * the handle in r3 (the branch keeps the argument register intact). */
void fn_802E7544(void) { fn_802E3990(); }

/* Close the file/stream handle by value; fn_802E3734 takes the handle by address and invalidates it. */
void fn_802E7548(int handle) { fn_802E3734(&handle); }

