// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern volatile unsigned char lbl_805599E8;
extern unsigned char lbl_80422F40[];
extern signed char lbl_8032AFE0[];
extern int memset(void *, int, unsigned int);
#pragma scheduling invalid_target
#pragma dont_inline on
unsigned char fn_8012F7E0(signed char arg0) {
    register int initialized = lbl_805599E8;
    int i;
    if (initialized != 0) {
        lbl_805599E8 = 0;
        memset(lbl_80422F40, 0xFF, 0x100);
        for (i = 0; i < 64; i++) {
            lbl_80422F40[lbl_8032AFE0[i]] = i;
        }
    }
    return lbl_80422F40[arg0];
}

int fn_8012F968(unsigned char *arg0) {
    unsigned char *p = arg0;
    int result = 0;
    int i = 0;
    do {
        unsigned char value;
        result <<= 6;
        value = fn_8012F7E0((signed char)*p);
        if (!(value & 0xC0)) {
            result |= value;
        } else {
            result = 0xFF000000;
            break;
        }
        i++;
        p++;
    } while (i < 4);
    return result;
}

extern int strlen(const char *);
extern int fn_8012F968(unsigned char *);
#pragma use_lmw_stmw off
int fn_8012F9E8(unsigned char *decodedBytes, int maxDecodedBytes, unsigned char *encodedText) {
    /* Decodes a base64-like string (length multiple of 4) into bytes, returning 1 on success or 0 on bad length/invalid chars. */
    int encodedLen = strlen((const char *)encodedText);
    int ok = 1;
    if (encodedLen & 3) return 0;
    {
        int inputPos = 0;
        int outputPos = 0;
        while (inputPos < encodedLen && outputPos < maxDecodedBytes) {
            int decodedBlock = fn_8012F968(encodedText + inputPos);
            if (!(decodedBlock & 0xFF000000)) {
                int shift = 16;
                while (outputPos < maxDecodedBytes && shift >= 0) {
                    decodedBytes[outputPos] = (unsigned int)decodedBlock >> shift;
                    shift -= 8;
                    outputPos++;
                }
            } else {
                ok = 0;
                break;
            }
            inputPos += 4;
        }
    }
    return ok;
}
#pragma use_lmw_stmw on
