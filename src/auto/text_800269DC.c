// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "stdarg.h"
struct Fmt { char f0; char f1; char f2; char f3; char lenCode; char conv; char f6; char f7; int width; int prec; };
extern char *parse_format_80025258(char *, void *, void *);
extern char *longlong2str_80025A7C(int, int, char *, void *);
extern char *long2str_80025854(unsigned int, char *, void *);
extern char *float2str_8002620C(char *, void *, double);
extern char *double2hex_80025D1C(char *, void *, double);
extern int wcstombs(char *, void *, int);
extern char *memchr(const void *, int, unsigned int);
typedef int (*outfunc)(void *, const char *, int);
