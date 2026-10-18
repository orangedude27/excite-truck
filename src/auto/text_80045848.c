#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void calc_button_repeat(void *arg0, void *arg1, u32 arg2) {
    u16 t, t2, t3, t4;
#define F(p,T,o) (*(T *)((u8 *)(p)+(o)))
    if(arg2==2) {
      if(F(arg1,s32,0x64)||F(arg1,s32,0x68)){ F(arg0,u16,0x3e4)=0; F(arg0,u16,0x3e6)=F(arg0,u16,0x3e8); if(F(arg1,s32,0x64)&&F(arg0,u16,0x3ea)) F(arg1,s32,0x60)|=0x80000000; }
      else if(F(arg1,s32,0x60)){ t=F(arg0,u16,0x3e4)+F(arg0,u16,0x112); F(arg0,u16,0x3e4)=t; if(t>=0x9c40) F(arg0,u16,0x3e4)=t-0x9c40; if(F(arg0,u16,0x3e4)>=F(arg0,u16,0x3e6)){ F(arg1,s32,0x60)|=0x80000000; F(arg0,u16,0x3e6)=F(arg0,u16,0x3e6)+F(arg0,u16,0x3ea); if(F(arg0,u16,0x3e4)>=0x4e20){ F(arg0,u16,0x3e4)=F(arg0,u16,0x3e4)-0x4e20; F(arg0,u16,0x3e6)=F(arg0,u16,0x3e6)-0x4e20; } } }
    } else if(F(arg1,s32,4)||F(arg1,s32,8)){F(arg0,u16,0x3dc)=0;F(arg0,u16,0x3de)=F(arg0,u16,0x3e0);if(F(arg1,s32,4)&&F(arg0,u16,0x3e2))F(arg1,s32,0)|=0x80000000;}
    else if(F(arg1,s32,0)){t3=F(arg0,u16,0x3dc)+F(arg0,u16,0x112);F(arg0,u16,0x3dc)=t3;if(t3>=0x9c40)F(arg0,u16,0x3dc)=t3-0x9c40;if(F(arg0,u16,0x3dc)>=F(arg0,u16,0x3de)){F(arg1,s32,0)|=0x80000000;F(arg0,u16,0x3de)=F(arg0,u16,0x3de)+F(arg0,u16,0x3e2);if(F(arg0,u16,0x3dc)>=0x4e20){F(arg0,u16,0x3dc)=F(arg0,u16,0x3dc)-0x4e20;F(arg0,u16,0x3de)=F(arg0,u16,0x3de)-0x4e20;}}
    }
#undef F
}
