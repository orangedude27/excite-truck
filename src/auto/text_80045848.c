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

extern void reset_kpad(void *);
extern void calc_button_repeat(void *, void *, u32);
void calc_acc_horizon(void *p, void *input, u32 mode) {
    u8 *pad = (u8 *)p;
    u8 *report = (u8 *)input;
    u32 old_buttons;
    u32 old_horizon;
    u32 current;
    u32 changed;
    u32 previous;
    s16 count;
    s8 status;

    count = *(s16 *)(pad + 0x114);
    if (count < 0)
        return;
    previous = *(u32 *)(pad + 0);
    old_buttons = previous & 0xFFFF;
    if (mode == 2) {
        previous = *(u32 *)(pad + 0x60);
        old_horizon = previous & 0xFFFF;
    }
    if (mode == 1) {
        status = *(s8 *)(report + 0x29);
        if (status != 0) {
            if (status == -1) {
                *(s16 *)(pad + 0x114) -= 4;
                reset_kpad(p);
                return;
            }
            goto process;
        }
        *(u32 *)(pad + 0) = *(u16 *)(report + 0);
        goto process;
    }
    if (mode == 2) {
        status = *(s8 *)(report + 0x29);
        if (status != 0) {
            if (status == -1) {
                *(s16 *)(pad + 0x114) -= 4;
                reset_kpad(p);
                return;
            }
            goto process;
        }
        *(u32 *)(pad + 0) = *(u16 *)(report + 0);
        *(u32 *)(pad + 0x60) = *(u16 *)(report + 0x2A);
        goto process;
    }
    status = *(s8 *)(report + 0x29);
    if (status != 0) {
        if (status == -1) {
            *(s16 *)(pad + 0x114) -= 4;
            reset_kpad(p);
            return;
        }
        goto process;
    }
    *(u32 *)(pad + 0) = *(u16 *)(report + 0);
process:
    current = *(u32 *)(pad + 0);
    changed = current ^ old_buttons;
    *(u32 *)(pad + 4) = changed & current;
    *(u32 *)(pad + 8) = changed & old_buttons;
    calc_button_repeat(p, p, 0);
    if (mode == 2) {
        current = *(u32 *)(pad + 0x60);
        changed = current ^ old_horizon;
        *(u32 *)(pad + 0x64) = changed & current;
        *(u32 *)(pad + 0x68) = changed & old_horizon;
        calc_button_repeat(p, p, 2);
    }
}

