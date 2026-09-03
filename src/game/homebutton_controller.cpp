#include <types.h>

/* Review carves for the REXE01 homebutton Controller class
 * (auto_03_800A485C_text):
 *
 *   soundOnCallback__Q210homebutton10ControllerFP7OSAlarmP9OSContext
 *   clearCallback__Q210homebutton10ControllerFv
 *   isPlayingSoundId__Q210homebutton10ControllerCFi
 *
 * Review-only; not configured.
 */

extern "C" u32 OSGetAlarmUserData(void* alarm);
#pragma push
#pragma small_data off
extern "C" u8 lbl_80407780_table[4];
#pragma pop
extern "C" u32 fn_80060C7C(void* p);
extern "C" u32 fn_80060CC0(void* p, u32 a, u32 b);
extern "C" void WPADSetSamplingCallback(void* p, void* cb);
extern "C" void WPADSetSamplingCallback_800603D0(void* p, void* cb);
extern "C" u32 fn_800D1E5C(void* p, void* dev);
extern "C" u32 fn_800D1E78(void* p, void* dev, u32 id);

struct Controller {
    void* m_pad;       // at 0x0
    u8 pad4[0x20];
    void* m_samplingCb; // at 0x24
    void* m_samplingCb2; // at 0x28
    void* m_otherCb;    // at 0x2C
    u8 pad30[0x11];
    u8 m_flag;          // at 0x41
};

extern "C" void soundOnCallback__Q210homebutton10ControllerFP7OSAlarmP9OSContext(
    void* alarm, void* ctx) {
    u32 idx = OSGetAlarmUserData(alarm);
    Controller* self = ((Controller * (*)[1])&lbl_80407780_table)[0][idx];
    void* obj = self->m_pad;

    if (fn_80060C7C(obj)) {
        fn_80060CC0(obj, 3, 0);
    }

    self->m_flag = 0;
    (void)ctx;
}

extern "C" void clearCallback__Q210homebutton10ControllerFv(Controller* self) {
    {
        void* old = self->m_samplingCb2;
        WPADSetSamplingCallback(self->m_pad, old);
        self->m_samplingCb2 = NULL;
    }
    {
        void* old = self->m_otherCb;
        WPADSetSamplingCallback_800603D0(self->m_pad, old);
        self->m_otherCb = NULL;
    }
}

extern "C" u32 isPlayingSoundId__Q210homebutton10ControllerCFi(
    Controller* self, s32 id) {
    u32 result;

    if (fn_800D1E5C(self->m_samplingCb, self->m_pad)) {
        result = fn_800D1E78(self->m_samplingCb, self->m_pad, id);
    } else {
        result = 0;
    }

    return result;
}