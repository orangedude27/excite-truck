// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
typedef int s32;
extern void *fn_801E87A8(void);
extern s32 fn_8026E20C(void);
extern void fn_8026E204(s32);
#pragma small_data off
extern char lbl_8034F3D0[];
#pragma small_data on
extern s32 fn_800167F4(void);
extern s32 lbl_802ED6D8[];
extern s32 lbl_8055D370;
extern s32 lbl_805601B0;
void fn_80008390(void) {
 int *array=*(int **)&lbl_8034F3D0;
 int *count=(int *)((char *)&lbl_8034F3D0+4);
 int *src;
 int n,i;
 *count=0;
 if(fn_800167F4()>1){n=*count;*count=n+1;array[n]=lbl_805601B0;}
 if(lbl_8055D370==0) src=lbl_802ED6D8;
 else src=lbl_802ED6D8+4;
 for(i=0;i<(lbl_8055D370==0?4:5);i++){n=*count;*count=n+1;array[n]=src[i];}
 for(i=0;i<*count;i++) if(array[i]==1){
  src=lbl_802ED6D8+10;
  for(n=0;n<4;n++){int k=*count;*count=k+1;array[k]=src[n];}
  break;
 }
}

s32 fn_800085D8(s32 arg0) {
    s32 *entry = *(s32 **)lbl_8034F3D0;
    s32 count = *(s32 *)(lbl_8034F3D0 + 4);
    s32 i;

    if (count > 0) {
        for (i = 0; i < count; i++, entry++) {
            if (arg0 == *entry)
                return 1;
        }
    }
    return 0;
}

void fn_80008618(s32 arg0) {
    s32 value = fn_8026E20C();
    s32 result = value | arg0;
    if (value & arg0)
        result = value & ~arg0;
    fn_8026E204(result);
}

s32 fn_8000865C(void) {
    return (*(u32 *)((char *)fn_801E87A8() + 0x10) >> 1) & 1;
}

typedef unsigned char u8;
typedef float f32;
extern s32 fn_8000865C(void);
extern s32 fn_801298E8(void *, s32);
extern s32 fn_802ECC10(void);
extern s32 lbl_805589EC;
extern u8 lbl_8055D37A;
extern f32 lbl_8055D394;
extern f32 lbl_805601B8;
extern f32 lbl_805601BC;
extern f32 lbl_805601D0;
#pragma dont_inline on
s32 fn_80008C5C(void) {
    unsigned char sp[0x68];
    s32 old = lbl_805589EC;
    u32 input;
    u32 bit;
    s32 allowed;
    if (lbl_8055D37A == 0 && fn_802ECC10() == 0 && fn_801298E8(sp + 8, 0) != 0) {
        input = *(u32 *)(sp + 0x48);
        if (input == 8) {
            lbl_805589EC = fn_8000865C() ? 0xD : 0xC;
        } else if (input == 2) {
            lbl_805589EC = fn_8000865C() ? 0xC : 0xD;
        } else if (input == 4) {
            lbl_805589EC = 7;
        } else if (input == 1) {
            lbl_805589EC = 0xE;
        }
        allowed = 0;
        bit = input - 1;
        if (bit <= 7 && ((1 << bit) & 0x8B))
            allowed = 1;
        if (allowed == 0 && lbl_8055D394 > lbl_805601B8 && lbl_805589EC != 4)
            lbl_805589EC = 4;
        if (lbl_805589EC != old) {
            if (lbl_8055D394 <= lbl_805601B8 && old == 4)
                lbl_8055D394 = lbl_805601BC;
            else if (lbl_8055D394 <= lbl_805601B8)
                lbl_805589EC = old;
        }
        lbl_8055D394 += lbl_805601D0;
    }
    return lbl_805589EC;
}
#pragma dont_inline off

int fn_80008DBC(int arg0) {
    switch (arg0) {
    case 0x113: return 0x15;
    case 0x2C: return 0;
    case 0x1B: return 0x12;
    case 0xD: return 0x13;
    case 0x20: return 0xF;
    case 0x2B: return 0x1B;
    case 0x32: return 0x18;
    case 0x30: return 0x19;
    case 0x2E: return 0;
    case 0x2D: return 0x1A;
    case 0x6F: return 0xE;
    case 0x170: return 0;
    case 0x125: return 2;
    case 0x122: return 0x15;
    case 0x121: return 0x14;
    case 0x128: return 5;
    case 0x127: return 3;
    case 0x174: return 0;
    case 0x172: return 0;
    case 0x176: return 0;
    case 0x126: return 4;
    case 0x31: return 0x17;
    default: return 0;
    }
}

s32 fn_80008F68(s32 arg0) {
    switch (arg0) {
    case 0x15:
    case 2:
    case 3:
    case 4:
    case 5:
        return 1;
    default:
        return 0;
    }
}

void fn_80009C80(void) {
    fn_80009534();
}

extern char lbl_8055D36D;
char fn_80009C84(void) {
    return lbl_8055D36D;
}

extern char lbl_8055D378;
s32 fn_80009C8C(void) {
    s32 result = 0;

    if ((u8)lbl_8055D36D == 0 && (u8)lbl_8055D378 != 0)
        result = 1;
    lbl_8055D378 = 0;
    return result;
}

s32 fn_80009CB8(void) {
    s32 result = 0;
    if ((u8)lbl_8055D36D == 0 && *((u8 *)&lbl_8055D378 + 1) != 0) {
        result = 1;
        *((u8 *)&lbl_8055D378 + 1) = 0;
    }
    return result;
}

