// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#define M2C_FIELD(expr, T, offset) (*(T)((char *)(expr) + (offset)))
extern void PSVECCrossProduct(float *, float *, int *);
extern float PSVECDotProduct(int *, float *);
extern void *__AXFXGetLfoSinTable_801769CC(int);
extern void fn_80015A20(int *, float *, float, float, float, float);
extern void fn_80015B20(float *, int *, float *);
extern int fn_80129D18(int, int);
extern void fn_8014452C(int *, float, float, float);
extern void fn_8017B6D4(void *, float *, float *, float, float);
extern void fn_8017B778(void *, float *, float *);
extern void fn_8018BFA0(void *, float *, int *, int, float, float);
extern float lbl_80561F88, lbl_80561F90, lbl_80561F94, lbl_80561F98, lbl_80561F9C, lbl_80561FA0, lbl_80561FA4, lbl_80561FA8, lbl_80561FAC, lbl_80561FB0, lbl_80561FB4, lbl_80561FB8, lbl_80561FBC, lbl_80561FC0, lbl_80561FC4;

void fn_8018C50C(void) {

}

void fn_8018C510(void) {

}

extern int lbl_80332840;
extern float lbl_80561F74;
extern float lbl_80562050;
extern float lbl_80561F8C;
extern float lbl_8055E3C8;
extern float lbl_80561F70;
extern float PSQUATMultiply(void *, void *);
int fn_8018C514(void *arg0, void *arg1) {
    float min = lbl_80561F70;
    int best = 0;
    int i = 1;
    int offset = 0x34;
    while (i < *(int *)((char *)arg0 + 0x26C)) {
        float value = PSQUATMultiply(arg1, (char *)arg0 + offset + 0x20);
        if (value < min) {
            min = value;
            best = i;
        }
        offset += 0x34;
        i++;
    }
    return best;
}

extern float PSVECMag(void *);
extern void PSVECNormalize(float *, float *);
extern float lbl_80561F74, lbl_80561F88, lbl_80561FC0;
extern float lbl_80561FEC, lbl_80561FF0, lbl_80561FF4;
#pragma scheduling invalid_target
void fn_8018DE94(void *arg0, int arg1, float *arg2, int arg3, int arg4) {
    char *base = (char *)arg0;
    char *record = *(char **)(base + 0x26C) + arg1 * 0x34;
    float gain = lbl_80561FF0 * *(float *)(record + 0x30);
    float factor = lbl_80561FEC * gain;
    float damping;
    float speed = PSVECMag(arg2);
    float scaled[3];
    float *velocity;
    int normal[3];
    float dot;
    int i, offset;

    scaled[1] = arg2[1] * factor;
    scaled[0] = arg2[0] * factor;
    scaled[2] = arg2[2] * factor;
    if (scaled[1] < lbl_80561F74)
        scaled[1] = lbl_80561F74;
    damping = lbl_80561FC0;
    velocity = (float *)(base + *(int *)(record + 4) * 0xC + 0x5FC);
    velocity[0] = velocity[0] + scaled[0] * damping;
    velocity[1] = velocity[1] + scaled[1] * lbl_80561FC0;
    velocity[2] = velocity[2] + scaled[2] * lbl_80561FC0;
    dot = PSVECDotProduct((int *)velocity, (float *)(record + 0x20));
    if (dot > lbl_80561F74) {
        normal[0] = *(int *)(record + 0x20);
        normal[1] = *(int *)(record + 0x24);
        normal[2] = *(int *)(record + 0x28);
        PSVECNormalize((float *)normal, (float *)normal);
        dot = -PSVECDotProduct((int *)velocity, (float *)normal);
        velocity[0] = velocity[0] + ((float *)normal)[0] * dot;
        velocity[1] = velocity[1] + ((float *)normal)[1] * dot;
        velocity[2] = velocity[2] + ((float *)normal)[2] * dot;
    }
    if (*(float *)(record + 0x14) > velocity[0])
        velocity[0] = *(float *)(record + 0x14);
    if (velocity[0] > *(float *)(record + 8))
        velocity[0] = *(float *)(record + 8);
    if (*(float *)(record + 0x18) > velocity[1])
        velocity[1] = *(float *)(record + 0x18);
    if (velocity[1] > *(float *)(record + 0xC))
        velocity[1] = *(float *)(record + 0xC);
    if (*(float *)(record + 0x1C) > velocity[2])
        velocity[2] = *(float *)(record + 0x1C);
    if (velocity[2] > *(float *)(record + 0x10))
        velocity[2] = *(float *)(record + 0x10);

    if (arg4 > 2)
        return;
    {
        float center[3];
        float unit;
        float limit;
        float zero;
        center[0] = *(float *)(record + 0x20) + velocity[0];
        center[1] = *(float *)(record + 0x24) + velocity[1];
        center[2] = *(float *)(record + 0x28) + velocity[2];
        unit = lbl_80561F88;
        limit = lbl_80561FF4;
        zero = lbl_80561F74;
        i = 0;
        offset = 0;
        while (i < *(int *)(*(char **)(base + 0x26C) + 0x20F0)) {
            char *manager = *(char **)(base + 0x26C);
            char *link = *(char **)(manager + 0x20EC) + offset;
            int id = *(int *)link;
            int other = *(int *)(link + 4);
            if ((id == arg1 && other != arg3) || (other == arg1 && id != arg3)) {
                int selected = (id == arg1) ? other : id;
                char *otherRecord = manager + selected * 0x34;
                float *otherVelocity = (float *)(base + selected * 0xC + 0x5FC);
                float delta[3];
                float next[3];
                float distance;
                float scale;

                delta[0] = *(float *)(otherRecord + 0x20) + otherVelocity[0] - center[0];
                delta[1] = *(float *)(otherRecord + 0x24) + otherVelocity[1] - center[1];
                delta[2] = *(float *)(otherRecord + 0x28) + otherVelocity[2] - center[2];
                distance = PSVECMag(delta);
                if (distance > limit) {
                    scale = unit / distance;
                    delta[0] = delta[0] * scale;
                    delta[1] = delta[1] * scale;
                    delta[2] = delta[2] * scale;
                    dot = -PSVECDotProduct((int *)delta, arg2);
                    next[0] = arg2[0] + delta[0] * dot;
                    next[1] = arg2[1] + delta[1] * dot;
                    next[2] = arg2[2] + delta[2] * dot;
                    next[0] = next[0] * *(float *)(link + 0xC);
                    next[1] = next[1] * *(float *)(link + 0xC);
                    next[2] = next[2] * *(float *)(link + 0xC);
                    dot = PSVECDotProduct((int *)arg2, delta);
                    scale = dot * *(float *)(link + 8);
                    next[0] = next[0] + delta[0] * scale;
                    next[1] = next[1] + delta[1] * scale;
                    next[2] = next[2] + delta[2] * scale;
                    scale = speed * *(float *)(link + 0x10);
                    next[0] = next[0] + zero * scale;
                    next[1] = next[1] + unit * scale;
                    next[2] = next[2] + zero * scale;
                } else {
                    next[0] = arg2[0] * *(float *)(link + 8);
                    next[1] = arg2[1] * *(float *)(link + 8);
                    next[2] = arg2[2] * *(float *)(link + 8);
                }
                fn_8018DE94(arg0, selected, next, arg1, arg4 + 1);
            }
            offset += 0x14;
            i++;
        }
    }
}
#pragma scheduling on
void fn_8018E330(void *arg0) {
    void *manager;
    void *object;
    manager = (void *)fn_801B83A0();
    ((void (*)(void *))(*(void **)((char *)*(void **)manager + 0xA4)))(arg0);
    fn_80161A38(0, *(int *)((char *)arg0 + 0x1EC), 0);
    fn_801DFF1C(*(int *)((char *)arg0 + 0x1EC));
    *(float *)((char *)arg0 + 0x258C) = lbl_80561F74;
    object = *(void **)((char *)arg0 + 0x270);
    *(float *)((char *)arg0 + 0x2690) = lbl_80561F8C;
    *(float *)((char *)arg0 + 0x25BC) = lbl_80561F74;
    *(float *)((char *)arg0 + 0x26A0) = lbl_8055E3C8;
    object = ((void *(*)(void *))(*(void **)((char *)*(void **)object + 0x10)))(object);
    *(int *)((char *)arg0 + 0x26A4) = *(int *)((char *)object + 4);
    *(float *)((char *)arg0 + 0x2588) = lbl_80561F74;
    *(float *)((char *)arg0 + 0x25A0) = lbl_80561F74;
    *(char *)((char *)arg0 + 0x259D) = 0;
    *(char *)((char *)arg0 + 0x259C) = 0;
    *(int *)((char *)arg0 + 0x2638) = 0;
    *(int *)((char *)arg0 + 0x2644) = 0;
    *(float *)((char *)arg0 + 0x2630) = lbl_80561F74;
    *(float *)((char *)arg0 + 0x262C) = lbl_80561F74;
    *(float *)((char *)arg0 + 0x2628) = lbl_80561F74;
}

extern float lbl_80561F88;
extern float lbl_80562038;
extern float lbl_8056203C;
extern float lbl_80562040;
void fn_8018F538(void *arg0, void *arg1) {
    unsigned char *src = arg0;
    unsigned char *dst = arg1;
    int i = 0;
    float v;
    *(float *)(dst + 0x290) = *(float *)(src + 0x2690);
    *(float *)(dst + 0x294) = *(float *)(src + 0x2698);
    *(int *)(dst + 0x298) = *(int *)(src + 0x268C);
    while (i < *(int *)((unsigned char *)arg0 + 0x5F8)) {
        v = (*(float *)(src + 0x5FC) - lbl_8056203C) / lbl_80562040;
        if (v < lbl_80561F88) v = lbl_80561F88;
        if (v > lbl_80561F74) v = lbl_80561F74;
        dst[0] = (unsigned char)(int)(lbl_80561F8C + lbl_80561F74 + v * lbl_80562038);
        v = (*(float *)(src + 0x600) - lbl_8056203C) / lbl_80562040;
        if (v < lbl_80561F88) v = lbl_80561F88;
        if (v > lbl_80561F74) v = lbl_80561F74;
        dst[1] = (unsigned char)(int)(lbl_80561F8C + lbl_80561F74 + v * lbl_80562038);
        v = (*(float *)(src + 0x604) - lbl_8056203C) / lbl_80562040;
        if (v < lbl_80561F88) v = lbl_80561F88;
        if (v > lbl_80561F74) v = lbl_80561F74;
        dst[2] = (unsigned char)(int)(lbl_80561F8C + lbl_80561F74 + v * lbl_80562038);
        src += 0xC;
        dst += 4;
        i++;
    }
    dst = arg1;
    *(unsigned char *)(dst + 0x2A0) = *(int *)((unsigned char *)arg0 + 0x15A8);
    *(unsigned char *)(dst + 0x2A1) = *(int *)((unsigned char *)arg0 + 0x1628);
    *(unsigned char *)(dst + 0x2A2) = *(int *)((unsigned char *)arg0 + 0x16A8);
    *(unsigned char *)(dst + 0x2A3) = *(int *)((unsigned char *)arg0 + 0x1728);
    *(unsigned char *)(dst + 0x2A4) = *(int *)((unsigned char *)arg0 + 0x17A8);
    *(unsigned char *)(dst + 0x2A5) = *(int *)((unsigned char *)arg0 + 0x1828);
    *(unsigned char *)(dst + 0x2A6) = *(int *)((unsigned char *)arg0 + 0x18A8);
    *(unsigned char *)(dst + 0x2A7) = *(int *)((unsigned char *)arg0 + 0x1928);
    *(unsigned char *)(dst + 0x2A8) = *(int *)((unsigned char *)arg0 + 0x19A8);
    *(unsigned char *)(dst + 0x2A9) = *(int *)((unsigned char *)arg0 + 0x1A28);
    *(unsigned char *)(dst + 0x2AA) = *(int *)((unsigned char *)arg0 + 0x1AA8);
    *(unsigned char *)(dst + 0x2AB) = *(int *)((unsigned char *)arg0 + 0x1B28);
    *(unsigned char *)(dst + 0x2AC) = *(int *)((unsigned char *)arg0 + 0x1BA8);
    *(unsigned char *)(dst + 0x2AD) = *(int *)((unsigned char *)arg0 + 0x1C28);
    *(unsigned char *)(dst + 0x2AE) = *(int *)((unsigned char *)arg0 + 0x1CA8);
    *(unsigned char *)(dst + 0x2AF) = *(int *)((unsigned char *)arg0 + 0x1D28);
    *(unsigned char *)(dst + 0x2B0) = *(int *)((unsigned char *)arg0 + 0x1DA8);
    *(int *)(dst + 0x29C) = *(int *)((unsigned char *)arg0 + 0x1E3C);
}

void fn_8018F6F8(void *arg0) {
    int i;
    char *type = (char *)&lbl_80332840;
    char *entry = (char *)arg0 + 0x152C;
    for (i = 0x11; i != 0; i--) {
        if (*(int *)entry != 0 && *(int *)(entry + 0x7C) == 0 &&
            (unsigned int)(*(int *)type - 0xE) <= 2U) {
            *(int *)(entry + 0x7C) = 4;
            *(char *)(entry + 0x78) = 0;
            *(float *)(entry + 0xC) = lbl_80561F74;
            *(float *)(entry + 0x10) = *(float *)(entry + 0x14) / lbl_80562050;
        }
        type += 0x40;
        entry += 0x80;
    }
}

void fn_8018F76C(void *arg0, int arg1) {
    extern void fn_801BEB30(int, void **);
    extern void fn_802E30C8(void *, int);
    extern float lbl_80562054;
    extern float lbl_80561F74;
    extern float lbl_80561F9C;
    extern int lbl_80332E40;
    char *base=(char*)arg0; char *state=base+arg1*0x74; void *p; float a[4], b[4], pos[3], vel[3]; int i;
    if (*(int*)(state+0x241C)&8) fn_802E30C8(&lbl_80332E40,*(int*)(base+0x1EC));
    fn_801BEB30(*(int*)(base+0x1EC),&p);
    for(i=0;i<4;i++) a[i]=*(float*)((char*)p+0x70+i*4);
    for(i=0;i<4;i++) a[i]*=lbl_80562054;
    for(i=0;i<4;i++) *(float*)((char*)p+0x70+i*4)=a[i];
    for(i=0;i<9;i++) b[i%9]=*(float*)(base+0x3C+i*4);
    for(i=0;i<3;i++) { vel[i]=*(float*)(base+0x48+i*4); pos[i]=*(float*)(state+0x23D0+i*4)+vel[i]*lbl_80561F98; }
    fn_8017B6D4(arg0,(float*)0,pos,0,0.0f);
    if (fabsf(*(float*)(state+0x23AC))<lbl_80561F9C && *(float*)(state+0x23AC)<lbl_80561F74) {
        for(i=0;i<3;i++) pos[i]=*(float*)(base+0x3C+i*4)* *(float*)(state+0x23AC)+*(float*)(base+0x124+i*4);
        fn_801AFC44(*(int*)(base+0x1EC),arg1,b,(int*)0,pos,0,0,0,0);
    }
    *(int*)(state+0x241C)|=8;
}

extern void fn_801BF2A4(void *, int, float *, void *, void *, int, void *, float, float, float);
extern float lbl_80561FE4;
void fn_8018F9B4(void *arg0) {
    // Fix note: computes scaled motion values for active slots, dispatches them, then advances each slot state.
    unsigned char *base = (unsigned char *)arg0;
    char *slot = (char *)arg0 + 0x152C;
    char *table = (char *)&lbl_80332840;
    float scale = lbl_80561FE4;
    int i = 0;
    int one = 1;
    int three = 3;
    int zero = 0;
    float x;
    float y;
    float z;
    float sp8;
    float spC;
    float sp10;
    do {
        if (*(int *)slot != 0 && *(int *)(slot + 4) > 0) {
            int state = *(int *)(slot + 0x7C);
            if (state == 0 || state == 2) {
                int row = *(int *)(table + 8);
                float *position = (float *)(*(unsigned char **)(base + 0x26C) + row * 0x18 + 0x2138);
                x = position[0] + position[3];
                y = position[1] + position[4];
                z = position[2] + position[5];
                sp8 = x * scale;
                spC = y * scale;
                sp10 = z * scale;
                fn_801BF2A4(arg0, one << row, &sp8, position, (char *)position + 0xC,
                            *(int *)(table + 0x34), table + 0x38, sp8, spC, sp10);
                *(int *)(slot + 0x7C) = three;
                *(char *)(slot + 0x78) = zero;
            }
        }
        i++;
        slot += 0x80;
        table += 0x40;
    } while (i < 0x11);
}

extern float lbl_80561F74;
extern float lbl_80562050;
extern float lbl_80561F8C;
extern float lbl_8055E3C8;
extern float lbl_80561F70;
extern int lbl_80332840;
int fn_80161A38(int, int, int);
int fn_801DFF1C(int);
float PSQUATMultiply(void *, void *);

