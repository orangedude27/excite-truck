#include "MSL/ansi_fp.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void __two_exp(decimal *out, long exponent) {
 extern const char lbl_802ED878[];
 decimal power, copy;
 switch(exponent) {
 case -64: __str2dec(out,lbl_802ED878+0,-20); break;
 case -53: __str2dec(out,lbl_802ED878+46,-16); break;
 case -32: __str2dec(out,lbl_802ED878+85,-10); break;
 case -16: __str2dec(out,lbl_802ED878+109,-5); break;
 case -8: __str2dec(out,lbl_802ED878+122,-3); break;
 case -7: __str2dec(out,lbl_802ED878+129,-3); break;
 case -6: __str2dec(out,lbl_802ED878+135,-2); break;
 case -5: __str2dec(out,lbl_802ED878+141,-2); break;
 case -4: __str2dec(out,lbl_802ED878+146,-2); break;
 case -3: __str2dec(out,lbl_802ED878+150,-1); break;
 case -2: __str2dec(out,lbl_802ED878+154,-1); break;
 case -1: __str2dec(out,lbl_802ED878+157,-1); break;
 case 0: __str2dec(out,lbl_802ED878+159,0); break;
 case 1: __str2dec(out,lbl_802ED878+161,0); break;
 case 2: __str2dec(out,lbl_802ED878+163,0); break;
 case 3: __str2dec(out,lbl_802ED878+165,0); break;
 case 4: __str2dec(out,lbl_802ED878+167,1); break;
 case 5: __str2dec(out,lbl_802ED878+170,1); break;
 case 6: __str2dec(out,lbl_802ED878+173,1); break;
 case 7: __str2dec(out,lbl_802ED878+176,2); break;
 case 8: __str2dec(out,lbl_802ED878+180,2); break;
 default:
   __two_exp(&power,exponent/2);
   __timesdec(out,&power,&power);
   if(exponent & 1) {
     copy=*out;
     if(exponent>0) __str2dec(&power,lbl_802ED878+0xa1,0);
     else __str2dec(&power,lbl_802ED878+0x9d,-1);
     __timesdec(out,&copy,&power);
   }
   break;
 }
}
