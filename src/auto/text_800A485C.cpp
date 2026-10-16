#include <types.h>
typedef void (*Unk800B7E18Callback)(u8);
extern "C" Unk800B7E18Callback lbl_80405D00[2];
extern "C" s32 lbl_80405C30[];
extern "C" s32 lbl_80405C98[];
extern "C" s32 fn_800B74B8(s8);
extern "C" s32 fn_800A5990(s32);
extern "C" s32 fn_800A59CC(s32);
extern "C" void fn_800B7E18(u8);
extern "C" void fn_800B7E38(u8);
extern "C" s32 fn_800BA3F4(Unk800B7E18Callback, Unk800B7E18Callback);
extern "C" s32 fn_800BBB58(s32, void**);
extern "C" s32 fn_800BAD9C(void*, u32*);
extern "C" s32 fn_800BB2C4(void*);
extern "C" s32 IOS_Close(s32);
extern "C" u8 fn_800BA974(s32,u8*,s32);
extern "C" void fn_800A68DC(s32);
extern "C" s32 lbl_80559248;
extern "C" u32 lbl_8055DD68;
extern "C" u8 lbl_80407300[];
#include <revolution/OS/OSAlarm.h>
#include <revolution/OS/OSTime.h>
#include <revolution/ARC/arc.h>
#include <string.h>
#pragma opt_tail_call on

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_800A6048();
s32 fn_800A61D0(void *);
s32 fn_800B75C4(void);
void fn_800C4BD0(void) __attribute__((noreturn));
extern "C" void fn_80128668(void);
void __dt__Q46nw4hbm2ut6detail12LinkListImplFv(void*, s32);
void fn_800DCE10(void*, s32);
extern "C" u32 fn_80060CC0(void*, u32, u32);
extern "C" void fn_800D1B1C(void);
extern "C" void fn_800D16C4(OSAlarm *, void *);

extern u32 lbl_8055DDB0;
extern "C" const char lbl_8031E9C0[];
DECL_SECTION(".sdata") extern u8 lbl_8055DDA8[];
extern "C" s32 fn_800D1E5C(void *arg0, s32 arg1);
extern "C" void fn_800D1668(s32 arg0, s32 arg1);
extern "C" s32 fn_800604E8(s32, s32, void *);
extern u32 lbl_8055DDF8;
extern "C" void fn_800D1C48(void);

#include <revolution/MEM/mem_allocator.h>
#include <revolution/MEM/mem_expHeap.h>
extern "C" void fn_800B7610(OSAlarm *alarm, OSContext *ctx);


extern "C" MEMAllocator lbl_804075E0;
extern "C" MEMAllocator* lbl_80559708;
extern "C" void* lbl_8055DD98;
extern "C" void* lbl_8055DDF0;
extern "C" void* fn_800C6914(void*, void* = 0);
extern "C" void fn_800C6A1C(void*, s32);
extern "C" void fn_800C6CE8(void*);
extern "C" void fn_800C7998(void*);

void fn_800A5954(void) {
    fn_800A6048();
}

void fn_800A5990(void) {
    fn_800A61D0(0);
}

extern "C" void* fn_800B1BDC(void*);
extern "C" void fn_800B73BC(void*);
extern "C" void fn_800B74E0(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC(fn_800B1BDC(alarm));
}

extern "C" void* fn_800B224C(void*);
extern "C" void fn_800B7504(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC(fn_800B224C(alarm));
}

extern "C" void* fn_800B1FF4(void*);
extern "C" void fn_800B75EC(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC(fn_800B1FF4(alarm));
}

extern "C" void* fn_800A9B0C(void*);
extern "C" void fn_800B7684(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800B73BC(fn_800A9B0C(alarm));
}

void fn_800B78EC(void) {

}

extern "C" s32 fn_800B7B34(s8 arg0) {
    s32 a = lbl_80405C30[arg0 - 0x41];
    s32 b = lbl_80405C98[arg0 - 0x41];
    if (fn_800B74B8(arg0)) return -1;
    if (a && b) {
        if (fn_800A59CC(b)) return -1;
        if (fn_800A5990(a)) return -1;
    }
    return 0;
}

extern "C" s32 fn_800B7BDC(void) {
    s32 result = ((s32 (*)(void))fn_800B74E0)();
    return (-result | result) >> 31;
}

extern "C" s32 fn_800B7C08(void) {
    s32 result = ((s32 (*)(void))fn_800B7504)();
    return (-result | result) >> 31;
}

void fn_800B7C60(void) {
    fn_800B75C4();
}

extern "C" s32 fn_800B7C64(void) {
    s32 result = ((s32 (*)(void))fn_800B75EC)();
    return (-result | result) >> 31;
}

extern "C" s32 fn_800B7C90(void) {
    s32 result = ((s32 (*)(void))fn_800B7610)();
    return (-result | result) >> 31;
}

extern "C" s32 fn_800B7CBC(void) {
    s32 result = ((s32 (*)(void))fn_800B7684)();
    return (-result | result) >> 31;
}

extern "C" s32 fn_800B7DB0(s32 arg0, Unk800B7E18Callback arg1, Unk800B7E18Callback arg2) {
    s32 result;
    switch (arg0) {
    case 0:
        lbl_80405D00[0] = arg1;
        lbl_80405D00[1] = arg2;
        result = fn_800BA3F4(fn_800B7E18, fn_800B7E38);
        break;
    default:
        return -2;
    }
    return -(result != 0);
}

extern "C" void fn_800B7E18(u8 arg0) {
    if (lbl_80405D00[0]) lbl_80405D00[0](arg0);
}

extern "C" s32 fn_800BA404(void) {
    u8 value;
    if (*(u32*)lbl_80407300 & 1) {
        if (*(s8*)(lbl_80407300 + 0x14) == 0 &&
            fn_800BA974(*(s32*)(lbl_80407300 + 0xC), &value, 1) == 1) {
            lbl_80407300[0x14] = value;
        }
        if (*(s32*)(lbl_80407300 + 0x10) != 0) {
            fn_800A68DC(*(s32*)(lbl_80407300 + 0xC));
            return 1;
        }
        return 0;
    }
    return 0;
}

extern "C" s32 fn_800BB3F4(s32 arg0) {
    u8 buffer[0x28];
    void* context = buffer;
    u32 flags;
    s32 result = -0x33;
    if (lbl_80559248 >= 0 && fn_800BBB58(arg0, &context) == 0) {
        if (fn_800BAD9C(context, &flags) == 0) {
            if (flags & 0x10000) result = 0;
            else {
                result = fn_800BB2C4(context);
                if (lbl_8055DD68 == 0x10000) result = 0;
            }
        }
        void* closeContext = context;
        *(s32*)((u8*)closeContext + 0x24) = 0;
        IOS_Close(*(s32*)closeContext);
        *(s32*)closeContext = -1;
    }
    return result;
}

extern "C" s32 fn_800BB4E0(s32,s32,s32,s32,s32,s32);
extern "C" s32 fn_800BBB58(s32, void**);
extern "C" s32 fn_800BAD9C(void*, u32*);
extern "C" s32 fn_800BB2C4(void*);
extern "C" s32 IOS_Close(s32);
extern "C" u8 fn_800BA974(s32,u8*,s32);
extern "C" void fn_800A68DC(s32);
extern "C" s32 lbl_80559248;
extern "C" u32 lbl_8055DD68;
extern "C" u8 lbl_80407300[];
extern "C" s32 fn_800BB4B0(s32 a,s32 b,s32 c,s32 d) {
    return fn_800BB4E0(a,b,c,d,0,0);
}

extern "C" s32 fn_800BB81C(s32,s32,s32,s32,s32,s32);
extern "C" s32 fn_800BB4BC(s32 a,s32 b,s32 c,s32 d) {
    return fn_800BB81C(a,b,c,d,0,0);
}

extern "C" s32 fn_800BB4C8(s32 a,s32 b,s32 c,s32 d) {
    return fn_800BB4E0(a,b,c,d,0,0);
}

extern "C" s32 fn_800BB4D4(s32 a,s32 b,s32 c,s32 d) {
    return fn_800BB81C(a,b,c,d,0,0);
}

extern "C" void fn_800BBCB4(void* context) {
    *(s32*)((u8*)context + 0x24) = 0;
    IOS_Close(*(s32*)context);
    *(s32*)context = -1;
}

void fn_800C3D9C(void) {
    fn_800C4BD0();
}

extern void *lbl_8055DD94;
extern "C" void fn_800C4BD0(void* hi) {
    lbl_8055DD94 = hi;
}

extern "C" void* fn_800C64DC(u32 size) {
    return MEMAllocFromAllocator(lbl_80559708, size);
}

extern "C" void fn_800C64F4(void* arg0) {
    void* block;

    MEMInitAllocatorForExpHeap(&lbl_804075E0,
                               MEMCreateExpHeapEx(*(void**)((u8*)arg0 + 0x10),
                                                  *(u32*)((u8*)arg0 + 0x24), 0),
                               0x20);
    lbl_80559708 = &lbl_804075E0;
    lbl_8055DDF0 = &lbl_804075E0;
    block = MEMAllocFromAllocator(&lbl_804075E0, 0x758);
    if (block != NULL) {
        if (block != NULL) {
            block = fn_800C6914(block, arg0);
        }
        lbl_8055DD98 = block;
    }
    fn_800C6CE8(lbl_8055DD98);
}

extern "C" void fn_800C657C(void) {
    fn_800C6A1C(lbl_8055DD98, -1);
    MEMFreeToAllocator(lbl_80559708, lbl_8055DD98);
    lbl_8055DD98 = NULL;
    MEMDestroyExpHeap((MEMiHeapHead*)lbl_80559708->heap);
}

extern "C" void fn_800C65C4(void) {
    fn_800C7998(lbl_8055DD98);
}

extern "C" void __dt__Q36nw4hbm3lyt19ArcResourceAccessorFv(void* this_ptr, s32 arg1) {
    void* r30 = this_ptr;
    s32 r31 = arg1;
    
    if (r30 != 0) {
        void* list_ptr = (u8*)r30 + 0x24;
        if (list_ptr != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(list_ptr, 0);
        }
        fn_800DCE10(r30, 0);
    }
    if (r31 > 0) {
        fn_80128668();
    }
}

extern "C" s32 fn_800C771C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800C775C(void *arg0, s32 arg1) {
    (*(u32 *)((u8 *)arg0 + 4)) = arg1;
}

extern "C" void fn_800CF280(void) {

}

extern "C" void fn_800CF288(void) {

}

extern "C" void fn_800CF28C(void) {

}

extern "C" void fn_800CF290(void) {

}

extern "C" s32 fn_800CF2B0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800CF930(void) {

}

extern "C" void fn_800CF968(void) {

}

extern "C" void fn_800CF96C(void) {

}

extern "C" s32 fn_800D010C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800D014C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_800D0AB4(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" void fn_800D0BA0(void) {

}

extern "C" void fn_800D1200(void) {

}

extern "C" void fn_800D1558(void) {

}

extern "C" s32 getInfoAsync__Q210homebutton10ControllerFP8WPADInfo(void *this_ptr, void *arg1) {
    u32 val = (u32)*(s32 *)this_ptr;
    
    if ((s32)val >= 4) {
        return -2;
    }
    
    if (fn_800D1E5C((void *)((u8 *)this_ptr + 0x24), (s32)val) != 0) {
        return -2;
    }
    
    if (((u8 *)this_ptr)[0x1C] != 0) {
        return -2;
    }
    
    return fn_800604E8((s32)val, (s32)(u32)arg1, (void *)&fn_800D1668);
}

extern "C" void fn_800D1668(s32 arg0, s32 arg1) {
    if (arg1 == 0 && arg0 < 4) {
        lbl_8055DDA8[arg0] = 1;
    }
}

extern "C" u8 fn_800D1688(s32 *arg0) {
    if (*arg0 >= 4) {
        return 0;
    }
    return lbl_8055DDA8[*arg0];
}

extern "C" void fn_800D16A8(s32 *arg0) {
    if (*arg0 < 4) {
        lbl_8055DDA8[*arg0] = 0;
    }
}

extern "C" void *fn_800D1948(void *arg0, s32 arg1) {
    void *r26 = arg0;
    if (r26 != NULL) {
        *(u32 *)((u8 *)r26 + 0x1F0) = (u32)&lbl_8031E9C0;
        lbl_8055DDB0 = (u32)r26;
        if (arg1 != 0) {
            BOOL result = ARCInitHandle((void *)arg1, (ARCHandle *)((u8 *)r26 + 0x1D0));
            s32 neg = -result;
            s32 or_result = neg | result;
            ((u8 *)r26)[0x1EC] = (u8)(or_result >> 31);
        } else {
            ((u8 *)r26)[0x1EC] = 0;
        }
    }

    void *r28 = r26;
    s32 r27 = 0;
    s32 r29 = 0;
    s32 r30 = -1;
    u8 r31 = 1;
    
    do {
        OSCreateAlarm((OSAlarm *)r28);
        *(u32 *)((u8 *)r28 + 0x50) = r29;
        r27++;
        *(u32 *)((u8 *)r28 + 0x58) = r30;
        ((u8 *)r28)[0x5C] = r31;
        ((u8 *)r28)[0x62] = r31;
        r28 = (u8 *)r28 + 0x68;
    } while (r27 < 4);

    return r26;
}

extern "C" void *fn_800D19F8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(u32 *)((u8 *)arg0 + 0x1F0) = (u32)&lbl_8031E9C0;
        lbl_8055DDB0 = 0;
        ((u8 *)arg0)[0x1EC] = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

extern "C" void Start__Q210homebutton9RemoteSpkFv(void *this_ptr) {
    if (((u8 *)this_ptr)[0x1EC] != 0) {
        OSAlarm *alarm = (OSAlarm *)((u8 *)this_ptr + 0x1A0);
        OSCreateAlarm(alarm);
        
        OSTime time = OSGetTime();
        s32 time_base = *(s32 *)0x800000F8;
        
        OSSetPeriodicAlarm(alarm, time_base >> 2, 0, (OSAlarmHandler)&fn_800D16C4);
    }
}

extern "C" void fn_800D1AE4(OSAlarm *arg0) {
    OSCancelAlarm((OSAlarm *)((u8 *)arg0 + 0x1A0));
}

extern void* OSGetAlarmUserData(void);
extern "C" void fn_800D1AEC(void) {
    void *r3 = OSGetAlarmUserData();
    fn_80060CC0(r3, 1, (u32)&fn_800D1B1C);
}

extern "C" void fn_800D1C18(void) {
    void* r3 = OSGetAlarmUserData(NULL);
    fn_80060CC0(r3, 4, (u32)&fn_800D1C48);
}

extern "C" void Connect__Q210homebutton9RemoteSpkFl(void *this_ptr, long arg1) {
    if (((u8 *)this_ptr)[0x1EC] != 0) {
        fn_80060CC0((void *)arg1, 1, (u32)&fn_800D1B1C);
        void *ptr = (u8 *)this_ptr + (arg1 * 0x68) + 0x30;
        memset(ptr, 0, 0x20);
        ((u8 *)this_ptr)[(arg1 * 0x68) + 0x5C] = 1;
        ((u8 *)this_ptr)[(arg1 * 0x68) + 0x62] = 0;
    }
}

extern "C" s32 fn_800D1E5C(void *arg0, s32 arg1) {
    s32 *ptr = (s32 *)((u8 *)arg0 + arg1 * 0x68);
    s32 val = ptr[0x50 / 4];
    s32 neg = -val;
    return (s32)((u32)(neg | val) >> 31);
}

extern "C" s32 fn_800D1E78(void *arg0, s32 arg1, s32 arg2) {
    void *ptr = (u8 *)arg0 + arg1 * 0x68;
    if (((s32 *)ptr)[0x50 / 4] != 0 && arg2 == ((s32 *)ptr)[0x58 / 4]) {
        return 1;
    }
    return 0;
}

extern "C" s32 fn_800D1EA8(void *arg0, s32 arg1) {
    u8 val = ((u8 *)((u8 *)arg0 + arg1 * 0x68))[0x62];
    s32 result = (s32)val;
    s32 neg = -result;
    return (s32)((u32)(neg | result) >> 31);
}

extern "C" s32 fn_800D2DD4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma opt_tail_call on
extern s32 lbl_8055DDD4;
extern void* lbl_8055DDD4_ptr;
extern void* lbl_8055DDBC;
extern "C" s32 fn_800D3F94(void*, s32, s32, s32);
extern u32 lbl_80407BD8[];
extern s32 lbl_8055DDC8;
#pragma opt_tail_call on
void DCStoreRange(const void *, u32);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *, ...) __attribute__((noreturn));
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" const char lbl_8031EA80[];
extern "C" const char lbl_8031EA90[];
extern "C" const char lbl_8031EA40[];
extern "C" const char lbl_8031EA4C[];
extern void* lbl_804077C0;
extern void fn_800D2E3C(s32, s32, s32, s32);
extern void fn_800D24D4(void*, s32);
extern void* lbl_8055DDBC;
extern "C" void fn_800D2098(void*);
extern "C" void __VprintfThunk(void*);
extern "C" void Console_VFPrintf__Q26nw4hbm2dbFQ36nw4hbm2db17ConsoleOutputTypePQ46nw4hbm2db6detail11ConsoleHeadPCcP16__va_list_struct(void*, void*, const char*, void*);
extern "C" s32 fn_80116A30(void*);
extern "C" void fn_800D1C48(void);
extern "C" s32 fn_80116A38(void*);
extern "C" u32 fn_80060CC0(void*, u32, u32);
extern "C" void fn_800D1B1C(void);

struct PanicStruct {
    const char *msg;
    const char *file;
    s32 line;
    s32 r7;
    s32 r8;
    s32 r9;
    s32 r10;
    s32 field_68;
    void *field_6C;
    void *field_70;
};

extern "C" s32 fn_800D2E14(void) {
    s32 _r3 = 0;
    if (lbl_8055DDC8 != 0) {
        if (lbl_80407BD8[0] != 0) {
            _r3 = 1;
        }
    }
    return _r3;
}

extern "C" void fn_800D2FC8(void) {
    DCStoreRange((void *)lbl_80407BD8[0], lbl_80407BD8[1]);
}

extern "C" s32 fn_800D3824(void) {
    s32 val = lbl_8055DDD4;
    u32 tmp = (u32)(-val) | (u32)val;
    return (s32)(tmp >> 31);
}
extern "C" u8 fn_800D3838(u8 *arg0) {
    return *arg0;
}

#pragma opt_tail_call on
#pragma opt_tail_call on
#pragma opt_tail_call on
extern "C" s32 fn_800D40B4(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4) {
    void *r31 = lbl_8055DDD4_ptr;
    s32 r28 = (s32)arg0;
    s32 r29 = (s32)arg1;
    s32 r30 = (s32)arg2;
    
    while (r31 != NULL) {
        if (fn_800D3F94(r31, r28, r29, r30) != 0) {
            return 1;
        }
        r31 = *(void **)((u8 *)r31 + 0xC);
    }
    return 0;
}
extern "C" s32 fn_800D43DC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern u32 lbl_8055DDE0;
extern "C" u32* fn_800D58B0(void) {
    return &lbl_8055DDE0;
}

void fn_800C7764(void *arg0, s8 arg1) {
    ((u8 *)arg0)[0x24] = (u8)arg1;
}

void fn_800C776C(void *arg0, s32 arg1) {
    ((u32 *)arg0)[0x24 / 4] = (u32)arg1;
}

void fn_800C790C(void *arg0) {
    u16 **ptr = *(u16 ***)((u8 *)arg0 + 4);
    u16 *var_r7 = *ptr;
    s32 var_r9 = 0;
    s32 var_r10 = 0;
    s32 var_r11 = 0;
    s32 var_r8 = 0;
    
    while (*var_r7 != 0) {
        if (*var_r7 == 0x22) {
            *var_r7 = 0;
            if (var_r11 == 0) {
                s32 temp_r4 = var_r10 * 0x18;
                var_r10++;
                var_r11 = 1;
                ((u32 *)((u8 *)arg0 + temp_r4 + var_r8))[0xB0 / 4] = (u32)(ptr + (var_r9 + 1) * 2);
                if (var_r10 == 7) {
                    var_r10 = 0;
                    var_r8 += 4;
                }
            } else {
                var_r11 = 0;
            }
        }
        var_r7 += 2;
        var_r9++;
    }
}

extern "C" u32* fn_800C7C68(void) {
    return &lbl_8055DDF8;
}

extern "C" void fn_800D15B4(void*);
extern "C" void fn_800CA148(OSAlarm *alarm, OSContext *ctx) {
#pragma unused(ctx)
    fn_800D15B4(OSGetAlarmUserData(alarm));
}

extern "C" s32 fn_800A4A8C(s32);
extern "C" s32 fn_800A4B54(s32);
extern "C" s32 fn_800A4D44(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern "C" void fn_800A4D4C(void *arg0, void *arg1) {
    if (((u32 *)arg0)[0xC / 4] == 1 || (s32)arg1 == 0) {
        ((s32 *)arg0)[8 / 4] = ((s32 *)arg0)[0];
    } else {
        ((s32 *)arg0)[8 / 4] = (s32)arg1;
    }
}

extern "C" s32 fn_800A4D74(void *arg0, u32 arg1) {
    if (arg1 == 1) {
        return ((s32 *)arg0)[0];
    }
    if (arg1 == 2) {
        return ((s32 *)arg0)[1];
    }
    return ((s32 *)arg0)[2];
}

extern "C" s32 fn_800A4E80(void *arg0, s32 arg1, u32 arg2) {
    if (arg2 == 1) {
        *(s32 *)((u8 *)arg0 + 0) = arg1;
        *(s32 *)((u8 *)arg0 + 4) = (s32)(arg1 + fn_800A4A8C(arg1));
    } else if (arg2 == 2) {
        *(s32 *)((u8 *)arg0 + 0) = arg1;
        *(s32 *)((u8 *)arg0 + 4) = (s32)(arg1 + (fn_800A4B54(arg1) * 2));
    }
        *(u32 *)((u8 *)arg0 + 0xC) = arg2;
      
      return 0;
}

#pragma opt_tail_call on
#pragma opt_tail_call on
#pragma opt_tail_call on
extern "C" void Console_DrawDirect__Q26nw4hbm2dbFPQ46nw4hbm2db6detail11ConsoleHead(void *arg0) {
    if (arg0 == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA80, 0x26D, lbl_8031EA90);
    }
    void *r30 = arg0;
    if (fn_800D2E14() != 0) {
        if (((u8 *)r30)[0x22] != 0) {
            void **r31 = (void **)&lbl_804077C0;
            OSLockMutex(r31);
            fn_800D2E3C(*(s16 *)((u8 *)r30 + 0x1C) - 6, *(s16 *)((u8 *)r30 + 0x1E) - 3,
                        (s32)(*(u16 *)((u8 *)r30 + 4)) * 6 + 12,
                        (s32)(*(u16 *)((u8 *)r30 + 0x20)) * 0xA + 4);
            fn_800D24D4(r30, 0);
            fn_800D2FC8();
            OSUnlockMutex(r31);
        }
    }
}
extern "C" void fn_800D2480(void) {
    if (lbl_8055DDBC == NULL) {
        Panic__Q26nw4hbm2dbFPCciPCce(lbl_8031EA40, 0x1F1, lbl_8031EA4C);
    }
    ((u8 *)lbl_8055DDBC)[0x22] = 0;
}

extern "C" void fn_800D16C4(OSAlarm*, void*);
extern "C" void Play__Q210homebutton9RemoteSpkFliSc(void *arg0, long arg1, int arg2, signed char arg3) {
    void *r26 = arg0;
    long r27 = arg1;
    int r28 = arg2;
    signed char r29 = arg3;
    
    if (((u8 *)r26)[0x1EC] != 0) {
        ARCFileInfo info;
        void *r30;
        s32 r31;
        
        ARCFastOpen((ARCHandle *)((u8 *)r26 + 0x1D0), r28, &info);
        r30 = ARCGetStartAddrInMem(&info);
        r31 = fn_80116A30(&info);
        fn_80116A38(&info);
        
        u8 *entry = (u8 *)r26 + ((s32)r27 * 0x68);
        entry[0x5E] = 0;
        *(s32 *)(entry + 0x58) = r28;
        *(s32 *)(entry + 0x54) = r31;
        entry[0x5D] = r29;
        *(s32 *)(entry + 0x50) = (s32)r30;
    }
}

#pragma opt_tail_call on
#pragma opt_tail_call on
extern "C" void fn_800D1C48(void);
extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *file, s32 line, const char *msg, ...) {
    u32 sp_8[2];
    u32 sp_C;
    u32 sp_10;
    u32 sp_14;
    u32 sp_18;
    u32 sp_1C;
    u32 sp_20;
    u32 sp_24;
    u32 sp_68;
    u32 sp_6C;
    u32 sp_70;
    u32 sp_88[16];
    
    sp_8[0] = (u32)msg;
    sp_8[1] = (u32)file;
    sp_C = (u32)line;
    sp_10 = 0;
    sp_14 = 0;
    sp_18 = 0;
    sp_1C = 0;
    sp_20 = 0;
    sp_24 = 0;
    sp_68 = 0x3000000;
    sp_6C = (u32)&sp_88[0];
    sp_70 = (u32)&sp_8[0];
    
    fn_800D2098(&sp_68);
}
extern s32 lbl_8055DDD4;
