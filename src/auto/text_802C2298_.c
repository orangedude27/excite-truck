// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_804C109C[];
extern void fn_802C6CF8(void *);
extern char lbl_8034AFE8[];
extern char lbl_8055CFD0;
extern char lbl_8055CFD8;
extern char lbl_8055CFE0;
extern char lbl_8055CFE8;
extern float lbl_80564E90;
extern float lbl_80564E94;
extern void *fn_80131810(void *);
extern void releaseValueFile(void *);
extern void fn_801345D8(void *, int, void *, ...);
extern int fn_802C6FC0(int, int, int);
extern float randFloatInRange(int, float, float);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802C2298(void) {
    struct Vec3 { float x, y, z; };
    struct BoatModel {
        int modelId;
        float position[3];
        float angle;
    };
    struct Manager { virtual void **get(void *); };
    struct Iterator {
        virtual void *m0(); virtual void *m1(); virtual void *m2(); virtual void *m3();
        virtual void *m4(); virtual void *m5(); virtual void *m6(); virtual void *m7();
        virtual void *m8(); virtual void *m9(); virtual void *m10(); virtual void *m11();
        virtual void *m12(); virtual void *m13(); virtual void *m14(); virtual void *m15();
        virtual void *m16(); virtual void *m17(); virtual void *m18(); virtual void *m19();
        virtual void *m20(); virtual void **find(char *);
    };
    struct Entry {
        virtual void *m0(); virtual void *m1(); virtual void *m2();
        virtual void *create(void *, int, void *);
        virtual void *m4(); virtual void *m5(); virtual void *m6(); virtual void *m7();
        virtual void *m8(); virtual void *m9(); virtual void *m10();
        virtual Vec3 getVector(void *);
    };
    char query[0x20];
    float value0, arg1, arg2;
    int temp_r5;
    struct BoatModel *record;
    void **manager;
    void **iterator;
    int index;
    void **entry;

    *(int *)((char *)lbl_804C109C + 4) = 0;
    manager = (void **)fn_80131810(lbl_8034AFE8);
    if (manager != 0) {
        iterator = ((Manager *)manager)->get((void *)&lbl_8055CFD0);
        index = 0;
        fn_801345D8(query, 0x20, (void *)&lbl_8055CFD8, index++);
        entry = ((Iterator *)iterator)->find(query);
        while (entry != 0) {
            temp_r5 = *(int *)((char *)lbl_804C109C + 4);
            *(int *)((char *)lbl_804C109C + 4) = temp_r5 + 1;
            record = (struct BoatModel *)((char *)*(void **)lbl_804C109C + temp_r5 * 0x14);
            record->modelId = fn_802C6FC0(
                (int)((Entry *)entry)->create((void *)&lbl_8055CFE0, temp_r5, *(void **)lbl_804C109C),
                0, 0);
            const Vec3 &values = ((Entry *)entry)->getVector((void *)&lbl_8055CFE8);
            value0 = values.x;
            arg1 = lbl_80564E90;
            record->position[0] = value0;
            arg2 = lbl_80564E94;
            record->position[1] = values.y;
            record->position[2] = values.z;
            record->angle = randFloatInRange(0, arg1, arg2);
            fn_801345D8(query, 0x20, (void *)&lbl_8055CFD8, index++);
            entry = ((Iterator *)iterator)->find(query);
        }
        releaseValueFile(manager);
    }
}
#pragma cplusplus reset
#pragma scheduling on

/* mrModelUnload every boat model the loader put on the list, then empty the list. */
void fn_802C2410(void) {
    struct BoatModel {
        int modelId;        /* handle mrModelUnload releases */
        float position[3];  /* where the boat sits on the stage */
        float angle;        /* its heading, spun by fn_802C2488 */
    };
    struct BoatModelList {
        struct BoatModel *models; /* 32 records, inline behind this header */
        int count;
        int capacity;
    };
    #define boatModels    ((struct BoatModelList *)lbl_804C109C)

    int i = 0;
    while (i < boatModels->count) {
        fn_802C6CF8((void *)boatModels->models[i].modelId);
        i++;
    }
    boatModels->count = 0;

    #undef boatModels
}

extern double sin(float);
extern void fn_80015A20(void *, float *);
extern void fn_80015B20(void *, void *, void *);
extern void MRModel_SetInstanceTransform(int, float *, float, float, float, float, float);
extern float lbl_8055E3C8;
extern float lbl_80564E98;
extern float lbl_80564E9C;
extern float lbl_80564EA0;
extern float lbl_80564EA8;
extern float lbl_80564EA4;
extern float lbl_80564EAC;
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma processor 750
void fn_802C2488(void) {
    struct Scratch {
        float args[3];
        float rotation[3];
        int key;
        unsigned int values[3];
        float angle;
        float rotationMatrix[9];
        float matrix[12];
    };
    volatile struct Scratch scratch;
    register int offset;
    register int index = 0;
    register float c31;
    register float c30;
    register float c29;
    register float c28;
    register float c27;
    register float c26;
    register float c25;
    register float sine;
    float angle;
    float theta;
    float angleSine;
    float y;
    float z;
    float w;
    float sum9;
    float sum10;
    float sum11;
    float lift;
    float result1;
    float result2;
    float result3;
    float tmpAngle;
    int keyArg;
    register unsigned int tmpV1;
    register unsigned int tmpV0;
    register int tmpKey;
    unsigned int tmpV2;
    register unsigned char *record;
    if (*(int *)((char *)lbl_804C109C + 4) <= 0)
        return;
    c26 = lbl_80564E98;
    offset = 0;
    c27 = lbl_80564E90;
    c28 = lbl_80564E9C;
    c29 = lbl_80564EA0;
    c30 = lbl_80564EA8;
    c31 = lbl_80564EA4;
    c25 = lbl_80564EAC;
    goto check_count;
loop:
    tmpKey = *(int *)(offset + (int)lbl_804C109C[0]);
    record = (unsigned char *)lbl_804C109C[0] + offset;
    tmpAngle = *(float *)(record + 0x10);
    tmpV0 = *(unsigned int *)(record + 4);
    tmpV1 = *(unsigned int *)(record + 8);
    tmpV2 = *(unsigned int *)(record + 0xC);
    scratch.key = tmpKey;
    angle = tmpAngle;
    scratch.values[0] = tmpV0;
    scratch.values[1] = tmpV1;
    scratch.values[2] = tmpV2;
    scratch.angle = angle;
    scratch.matrix[0] = c26;
    scratch.matrix[1] = c27;
    scratch.matrix[2] = c27;
    scratch.matrix[3] = c27;
    scratch.matrix[4] = c26;
    scratch.matrix[5] = c27;
    scratch.matrix[6] = c27;
    scratch.matrix[7] = c27;
    scratch.matrix[8] = c26;
    scratch.matrix[9] = c27;
    scratch.matrix[10] = c27;
    scratch.matrix[11] = c27;
    sine = (float)sin(c28 * (angle + lbl_8055E3C8));
    theta = lbl_8055E3C8 + scratch.angle;
    theta = c28 * theta;
    theta = c29 * theta;
    angleSine = (float)sin(theta);
    angleSine = c30 * angleSine;
    angleSine = c31 * angleSine;
    scratch.rotation[1] = c27;
    scratch.rotation[0] = angleSine;
    scratch.rotation[2] = angleSine;
    fn_80015A20((void *)scratch.rotationMatrix, (float *)scratch.rotation);
    fn_80015B20((void *)scratch.matrix, (void *)scratch.rotationMatrix, (void *)scratch.matrix);
    keyArg = scratch.key;
    sum9 = scratch.matrix[9];
    y = *(float *)&scratch.values[0];
    sum9 = sum9 + y;
    lift = c29 + c25 * sine;
    sum10 = scratch.matrix[10];
    z = *(float *)&scratch.values[1];
    sum10 = sum10 + z;
    sum11 = scratch.matrix[11];
    w = *(float *)&scratch.values[2];
    sum11 = sum11 + w;
    result1 = sum10 + lift;
    result2 = sum9 + c27;
    result3 = sum11 + c27;
    scratch.args[0] = c27;
    scratch.args[1] = lift;
    scratch.args[2] = c27;
    scratch.matrix[9] = result2;
    scratch.matrix[10] = result1;
    scratch.matrix[11] = result3;
    MRModel_SetInstanceTransform(keyArg, (float *)scratch.matrix,
                result1, result2, lift, sum10, sum9);
    offset += 0x14;
    index++;
check_count:
    if (index < *(int *)((char *)lbl_804C109C + 4))
        goto loop;
}
#pragma scheduling on
