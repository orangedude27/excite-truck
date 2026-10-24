// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#define M2C_FIELD(expr, T, offset) (*(T)((char *)(expr) + (offset)))
extern void PSVECCrossProduct(float *, float *, int *);
extern float PSVECDotProduct(int *, float *);
extern void *__AXFXGetLfoSinTable_801769CC(int);
extern void fn_80015A20(void *, void *);
extern void fn_80015B20(float *, int *, float *);
extern int fn_80129D18(int, int);
extern void fn_8014452C(int *, float, float, float);
extern void fn_8017B6D4(void *, float *, float *, ...);
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

void fn_8018CB3C(char *arg0) {
    float matrix[12];
    float position[3];
    float rotation[12];
    float position2[3];
    float rotation2[12];
    float transform[12];
    float scaleMatrix[12];
    float axis[3];
    float point[3];
    float origin[3];
    float world[3];
    float velocity[3];
    float force[3];
    float delta[3];
    float cross[3];
    float localAxis[3];
    float worldAxis[3];
    float angle[3];
    float rotated[3];
    float angle2[3];
    float rotated2[3];
    char *var_r19;
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float temp_f0_4;
    float temp_f0_5;
    float temp_f16;
    float temp_f17;
    float temp_f18;
    float temp_f19;
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f1_4;
    float temp_f1_5;
    float temp_f1_6;
    float temp_f1_7;
    float temp_f20;
    float temp_f21;
    float temp_f22;
    float temp_f23;
    float temp_f24;
    float temp_f25;
    float temp_f26;
    float temp_f27;
    float temp_f28;
    float temp_f29;
    float temp_f2;
    float temp_f2_10;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f2_4;
    float temp_f2_5;
    float temp_f2_6;
    float temp_f2_7;
    float temp_f2_8;
    float temp_f2_9;
    float temp_f30;
    float temp_f31;
    float temp_f3;
    float temp_f3_2;
    float temp_f3_3;
    float temp_f3_4;
    float temp_f3_5;
    float temp_f4;
    float temp_f4_2;
    float temp_f4_3;
    float temp_f5;
    float temp_f5_2;
    float temp_f5_3;
    float temp_f5_4;
    float temp_f6;
    float temp_f6_2;
    float temp_f6_3;
    float temp_f7;
    float temp_f7_2;
    float temp_f7_3;
    float temp_f7_4;
    float temp_f8;
    float temp_f8_2;
    float temp_f8_3;
    float temp_f8_4;
    float temp_r6;
    float var_f0;
    float var_f0_2;
    float var_f0_3;
    float var_f1;
    float var_f1_2;
    int temp_r3_10;
    int temp_r6_2;
    int temp_r6_3;
    int var_r18;
    char *temp_r3;
    char *temp_r3_2;
    char *temp_r3_3;
    char *temp_r3_4;
    char *temp_r3_5;
    char *temp_r3_6;
    char *temp_r3_7;
    char *temp_r3_8;
    char *temp_r3_9;
    char *temp_r5;
    char *var_r20;

    temp_f27 = lbl_80561F74;
    temp_f17 = lbl_80561F90;
    temp_f18 = lbl_80561F94;
    var_r20 = arg0 + 0x152C;
    temp_f19 = lbl_80561F98;
    temp_f20 = lbl_80561F9C;
    var_r19 = (char *)&lbl_80332840;
    temp_f21 = lbl_80561FA0;
    temp_f22 = lbl_80561FA8;
    temp_f23 = lbl_80561FA4;
    temp_f24 = lbl_80561FAC;
    temp_f25 = lbl_80561FB0;
    temp_f26 = lbl_80561F88;
    temp_f28 = lbl_80561FB4;
    temp_f29 = lbl_80561FB8;
    temp_f30 = lbl_80561FBC;
    temp_f16 = lbl_80561FC4;
    temp_f31 = lbl_80561FC0;
    var_r18 = 0;
    do {
        temp_r5 = M2C_FIELD(var_r20, char **, 0);
        if ((temp_r5 != 0) && ((int) M2C_FIELD(var_r20, int *, 0x7C) == 2)) {
            matrix[0] = M2C_FIELD(temp_r5, float *, 0);
            matrix[1] = M2C_FIELD(temp_r5, float *, 4);
            matrix[2] = M2C_FIELD(temp_r5, float *, 8);
            matrix[3] = M2C_FIELD(temp_r5, float *, 0xC);
            matrix[4] = M2C_FIELD(temp_r5, float *, 0x10);
            matrix[5] = M2C_FIELD(temp_r5, float *, 0x14);
            matrix[6] = M2C_FIELD(temp_r5, float *, 0x18);
            matrix[7] = M2C_FIELD(temp_r5, float *, 0x1C);
            matrix[8] = M2C_FIELD(temp_r5, float *, 0x20);
            temp_r6 = M2C_FIELD(temp_r5, float *, 0x24);
            matrix[9] = temp_r6;
            matrix[10] = M2C_FIELD(temp_r5, float *, 0x28);
            matrix[11] = M2C_FIELD(temp_r5, float *, 0x2C);
            temp_f3 = M2C_FIELD(var_r20, float *, 0xC);
            temp_f2 = M2C_FIELD(var_r19, float *, 0xC) * temp_f3;
            temp_f1 = M2C_FIELD(var_r19, float *, 0x10) * temp_f3;
            axis[0] = temp_f2;
            axis[1] = temp_f1;
            axis[2] = M2C_FIELD(var_r19, float *, 0x14) * temp_f3;
            fn_80015A20((int *)scaleMatrix, &axis[0]);
            fn_80015B20(&matrix[0], (int *)scaleMatrix, &matrix[0]);
            if (&point[0] == (void *) (var_r19 + 0x18)) {
                temp_f7 = M2C_FIELD(var_r19, float *, 0x1C);
                temp_f2_2 = M2C_FIELD(var_r19, float *, 0x18);
                temp_f8 = M2C_FIELD(var_r19, float *, 0x20);
                point[0] = (temp_f8 * matrix[6]) + ((temp_f2_2 * matrix[0]) + (temp_f7 * matrix[3]));
                point[1] = (temp_f8 * matrix[7]) + ((temp_f2_2 * matrix[1]) + (temp_f7 * matrix[4]));
                point[2] = (temp_f8 * matrix[8]) + ((temp_f2_2 * matrix[2]) + (temp_f7 * matrix[5]));
            } else {
                temp_f7_2 = M2C_FIELD(var_r19, float *, 0x1C);
                temp_f2_3 = M2C_FIELD(var_r19, float *, 0x18);
                temp_f8_2 = M2C_FIELD(var_r19, float *, 0x20);
                point[0] = (temp_f8_2 * matrix[6]) + ((temp_f2_3 * matrix[0]) + (temp_f7_2 * matrix[3]));
                point[1] = (temp_f8_2 * matrix[7]) + ((temp_f2_3 * matrix[1]) + (temp_f7_2 * matrix[4]));
                point[2] = (temp_f8_2 * matrix[8]) + ((temp_f2_3 * matrix[2]) + (temp_f7_2 * matrix[5]));
            }
            point[0] += matrix[9];
            point[1] += matrix[10];
            point[2] += matrix[11];
            temp_r3 = M2C_FIELD(var_r20, char **, 0);
            temp_r3_2 = temp_r3 + 0x24;
            if ((void *)&origin[0] == temp_r3_2) {
                temp_f7_3 = M2C_FIELD(temp_r3_2, float *, 4);
                temp_f2_4 = M2C_FIELD(temp_r3, float *, 0x24);
                temp_f8_3 = M2C_FIELD(temp_r3_2, float *, 8);
                origin[0] = (temp_f8_3 * M2C_FIELD(arg0, float *, 0x54)) + ((temp_f2_4 * M2C_FIELD(arg0, float *, 0x3C)) + (temp_f7_3 * M2C_FIELD(arg0, float *, 0x48)));
                origin[1] = (temp_f8_3 * M2C_FIELD(arg0, float *, 0x58)) + ((temp_f2_4 * M2C_FIELD(arg0, float *, 0x40)) + (temp_f7_3 * M2C_FIELD(arg0, float *, 0x4C)));
                origin[2] = (temp_f8_3 * M2C_FIELD(arg0, float *, 0x5C)) + ((temp_f2_4 * M2C_FIELD(arg0, float *, 0x44)) + (temp_f7_3 * M2C_FIELD(arg0, float *, 0x50)));
            } else {
                origin[0] = (M2C_FIELD(temp_r3_2, float *, 8) * M2C_FIELD(arg0, float *, 0x54)) + ((M2C_FIELD(temp_r3, float *, 0x24) * M2C_FIELD(arg0, float *, 0x3C)) + (M2C_FIELD(temp_r3_2, float *, 4) * M2C_FIELD(arg0, float *, 0x48)));
                origin[1] = (M2C_FIELD(temp_r3_2, float *, 8) * M2C_FIELD(arg0, float *, 0x58)) + ((M2C_FIELD(temp_r3, float *, 0x24) * M2C_FIELD(arg0, float *, 0x40)) + (M2C_FIELD(temp_r3_2, float *, 4) * M2C_FIELD(arg0, float *, 0x4C)));
                origin[2] = (M2C_FIELD(temp_r3_2, float *, 8) * M2C_FIELD(arg0, float *, 0x5C)) + ((M2C_FIELD(temp_r3, float *, 0x24) * M2C_FIELD(arg0, float *, 0x44)) + (M2C_FIELD(temp_r3_2, float *, 4) * M2C_FIELD(arg0, float *, 0x50)));
            }
            origin[0] += M2C_FIELD(arg0, float *, 0x60);
            origin[1] += M2C_FIELD(arg0, float *, 0x64);
            origin[2] += M2C_FIELD(arg0, float *, 0x68);
            if (&world[0] == &point[0]) {
                world[0] = (point[2] * M2C_FIELD(arg0, float *, 0x54)) + ((point[0] * M2C_FIELD(arg0, float *, 0x3C)) + (point[1] * M2C_FIELD(arg0, float *, 0x48)));
                world[1] = (point[2] * M2C_FIELD(arg0, float *, 0x58)) + ((point[0] * M2C_FIELD(arg0, float *, 0x40)) + (point[1] * M2C_FIELD(arg0, float *, 0x4C)));
                world[2] = (point[2] * M2C_FIELD(arg0, float *, 0x5C)) + ((point[0] * M2C_FIELD(arg0, float *, 0x44)) + (point[1] * M2C_FIELD(arg0, float *, 0x50)));
            } else {
                world[0] = (point[2] * M2C_FIELD(arg0, float *, 0x54)) + ((point[0] * M2C_FIELD(arg0, float *, 0x3C)) + (point[1] * M2C_FIELD(arg0, float *, 0x48)));
                world[1] = (point[2] * M2C_FIELD(arg0, float *, 0x58)) + ((point[0] * M2C_FIELD(arg0, float *, 0x40)) + (point[1] * M2C_FIELD(arg0, float *, 0x4C)));
                world[2] = (point[2] * M2C_FIELD(arg0, float *, 0x5C)) + ((point[0] * M2C_FIELD(arg0, float *, 0x44)) + (point[1] * M2C_FIELD(arg0, float *, 0x50)));
            }
            temp_f2_5 = world[1];
            temp_f1_2 = world[2];
            world[0] += M2C_FIELD(arg0, float *, 0x60);
            world[1] = temp_f2_5 + M2C_FIELD(arg0, float *, 0x64);
            world[2] = temp_f1_2 + M2C_FIELD(arg0, float *, 0x68);
            fn_8017B6D4(arg0, &velocity[0], &world[0]);
            fn_8017B778(arg0, &force[0], &origin[0]);
            temp_f2_6 = force[0] * temp_f18;
            temp_f1_3 = (force[1] + temp_f17) * temp_f18;
            temp_f6 = world[0] - origin[0];
            force[0] = temp_f2_6;
            temp_f5 = world[1] - origin[1];
            delta[0] = temp_f6;
            temp_f3_2 = world[2] - origin[2];
            delta[1] = temp_f5;
            delta[2] = temp_f3_2;
            force[1] = temp_f1_3;
            force[2] *= temp_f18;
            if (fn_80129D18(4, 4) < 3) {
                force[1] += velocity[1] * temp_f19;
                force[0] += velocity[0] * temp_f19;
                force[2] += velocity[2] * temp_f19;
            }
            PSVECCrossProduct(&delta[0], &force[0], (int *)cross);
            temp_r3_3 = M2C_FIELD(var_r20, char **, 0);
            if (&localAxis[0] == (void *) (var_r19 + 0xC)) {
                temp_f7_4 = M2C_FIELD(var_r19, float *, 0x10);
                temp_f2_7 = M2C_FIELD(var_r19, float *, 0xC);
                temp_f8_4 = M2C_FIELD(var_r19, float *, 0x14);
                localAxis[0] = (temp_f8_4 * M2C_FIELD(temp_r3_3, float *, 0x18)) + ((temp_f2_7 * M2C_FIELD(temp_r3_3, float *, 0)) + (temp_f7_4 * M2C_FIELD(temp_r3_3, float *, 0xC)));
                localAxis[1] = (temp_f8_4 * M2C_FIELD(temp_r3_3, float *, 0x1C)) + ((temp_f2_7 * M2C_FIELD(temp_r3_3, float *, 4)) + (temp_f7_4 * M2C_FIELD(temp_r3_3, float *, 0x10)));
                localAxis[2] = (temp_f8_4 * M2C_FIELD(temp_r3_3, float *, 0x20)) + ((temp_f2_7 * M2C_FIELD(temp_r3_3, float *, 8)) + (temp_f7_4 * M2C_FIELD(temp_r3_3, float *, 0x14)));
            } else {
                temp_f4 = M2C_FIELD(var_r19, float *, 0x10);
                temp_f3_3 = M2C_FIELD(var_r19, float *, 0xC);
                temp_f5_2 = M2C_FIELD(var_r19, float *, 0x14);
                localAxis[0] = (temp_f5_2 * M2C_FIELD(temp_r3_3, float *, 0x18)) + ((temp_f3_3 * M2C_FIELD(temp_r3_3, float *, 0)) + (temp_f4 * M2C_FIELD(temp_r3_3, float *, 0xC)));
                localAxis[1] = (temp_f5_2 * M2C_FIELD(temp_r3_3, float *, 0x1C)) + ((temp_f3_3 * M2C_FIELD(temp_r3_3, float *, 4)) + (temp_f4 * M2C_FIELD(temp_r3_3, float *, 0x10)));
                localAxis[2] = (temp_f5_2 * M2C_FIELD(temp_r3_3, float *, 0x20)) + ((temp_f3_3 * M2C_FIELD(temp_r3_3, float *, 8)) + (temp_f4 * M2C_FIELD(temp_r3_3, float *, 0x14)));
            }
            if (&worldAxis[0] == &localAxis[0]) {
                worldAxis[0] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x54)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x3C)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x48)));
                worldAxis[1] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x58)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x40)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x4C)));
                worldAxis[2] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x5C)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x44)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x50)));
            } else {
                worldAxis[0] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x54)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x3C)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x48)));
                worldAxis[1] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x58)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x40)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x4C)));
                worldAxis[2] = (localAxis[2] * M2C_FIELD(arg0, float *, 0x5C)) + ((localAxis[0] * M2C_FIELD(arg0, float *, 0x44)) + (localAxis[1] * M2C_FIELD(arg0, float *, 0x50)));
            }
            var_f1 = -PSVECDotProduct((int *)cross, &worldAxis[0]);
            if (temp_f20 < var_f1) {
                var_f1 = temp_f20;
            }
            if (var_f1 > temp_f21) {

            } else {
                var_f1 = temp_f21;
            }
            temp_f1_4 = M2C_FIELD(var_r20, float *, 0x10) + var_f1;
            var_f0 = temp_f1_4 - (temp_f23 * (temp_f22 * temp_f1_4));
            M2C_FIELD(var_r20, float *, 0x10) = var_f0;
            if (temp_f24 < var_f0) {
                var_f0 = temp_f24;
            }
            if (var_f0 > temp_f25) {

            } else {
                var_f0 = temp_f25;
            }
            M2C_FIELD(var_r20, float *, 0x10) = var_f0;
            temp_f0 = M2C_FIELD(var_r20, float *, 0xC);
            if (temp_f0 > temp_f26) {
                M2C_FIELD(var_r20, float *, 0xC) = temp_f26;
                var_f0_2 = M2C_FIELD(var_r20, float *, 0x10);
                if (var_f0_2 < temp_f27) {

                } else {
                    var_f0_2 = temp_f27;
                }
                M2C_FIELD(var_r20, float *, 0x10) = var_f0_2;
            } else if (temp_f0 < temp_f28) {
                if ((M2C_FIELD(__AXFXGetLfoSinTable_801769CC(0), int *, 4) & 0x4000) && (M2C_FIELD(var_r20, float *, 0x10) < temp_f27) && (fn_80129D18(4, 0xA) < 1)) {
                    M2C_FIELD(var_r20, float *, 0xC) = temp_f27;
                    M2C_FIELD(var_r20, float *, 0x10) = temp_f27;
                    M2C_FIELD(var_r20, int *, 0x7C) = 0;
                } else {
                    M2C_FIELD(var_r20, float *, 0x10) = (float) (M2C_FIELD(var_r20, float *, 0x10) + (temp_f22 * (temp_f29 * (temp_f28 - M2C_FIELD(var_r20, float *, 0xC)))));
                }
            }
            var_f0_3 = M2C_FIELD(var_r20, float *, 0xC) + (temp_f22 * M2C_FIELD(var_r20, float *, 0x10));
            M2C_FIELD(var_r20, float *, 0xC) = var_f0_3;
            if (var_f0_3 > temp_f30) {

            } else {
                var_f0_3 = temp_f30;
            }
            M2C_FIELD(var_r20, float *, 0xC) = var_f0_3;
            temp_r3_4 = M2C_FIELD(var_r20, char **, 0);
            temp_f6_2 = M2C_FIELD(temp_r3_4, float *, 0x24);
            position[0] = temp_f6_2;
            temp_f5_3 = M2C_FIELD(temp_r3_4, float *, 0x28);
            position[1] = temp_f5_3;
            temp_f4_2 = M2C_FIELD(temp_r3_4, float *, 0x2C);
            position[2] = temp_f4_2;
            temp_r3_5 = arg0 + (M2C_FIELD(var_r20, int *, 8) * 0xC);
            position[0] = temp_f6_2 + M2C_FIELD(temp_r3_5, float *, 0xD94);
            position[1] = temp_f5_3 + M2C_FIELD(temp_r3_5, float *, 0xD98);
            position[2] = temp_f4_2 + M2C_FIELD(temp_r3_5, float *, 0xD9C);
            temp_f3_4 = M2C_FIELD(var_r20, float *, 0xC);
            temp_f2_8 = M2C_FIELD(var_r19, float *, 0xC) * temp_f3_4;
            temp_f1_5 = M2C_FIELD(var_r19, float *, 0x10) * temp_f3_4;
            temp_f0_2 = M2C_FIELD(var_r19, float *, 0x14) * temp_f3_4;
            angle[0] = temp_f2_8;
            angle[1] = temp_f1_5;
            angle[2] = temp_f0_2;
            temp_r3_6 = M2C_FIELD(var_r20, char **, 0);
            if (&rotated[0] == &angle[0]) {
                rotated[0] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x18)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 0)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0xC)));
                rotated[1] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x1C)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 4)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0x10)));
                rotated[2] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x20)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 8)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0x14)));
            } else {
                rotated[0] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x18)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 0)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0xC)));
                rotated[1] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x1C)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 4)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0x10)));
                rotated[2] = (temp_f0_2 * M2C_FIELD(temp_r3_6, float *, 0x20)) + ((temp_f2_8 * M2C_FIELD(temp_r3_6, float *, 8)) + (temp_f1_5 * M2C_FIELD(temp_r3_6, float *, 0x14)));
            }
            fn_8014452C((int *)rotation, rotated[1], rotated[0], rotated[2]);
            M2C_FIELD(var_r20, float *, 0x48) = (float) M2C_FIELD(var_r20, float *, 0x18);
            M2C_FIELD(var_r20, float *, 0x4C) = (float) M2C_FIELD(var_r20, float *, 0x1C);
            M2C_FIELD(var_r20, float *, 0x50) = (float) M2C_FIELD(var_r20, float *, 0x20);
            M2C_FIELD(var_r20, int *, 0x54) = (int) M2C_FIELD(var_r20, int *, 0x24);
            M2C_FIELD(var_r20, int *, 0x58) = (int) M2C_FIELD(var_r20, int *, 0x28);
            M2C_FIELD(var_r20, int *, 0x5C) = (int) M2C_FIELD(var_r20, int *, 0x2C);
            M2C_FIELD(var_r20, int *, 0x60) = (int) M2C_FIELD(var_r20, int *, 0x30);
            M2C_FIELD(var_r20, int *, 0x64) = (int) M2C_FIELD(var_r20, int *, 0x34);
            M2C_FIELD(var_r20, int *, 0x68) = (int) M2C_FIELD(var_r20, int *, 0x38);
            temp_r6_2 = M2C_FIELD(var_r20, int *, 0x3C);
            M2C_FIELD(var_r20, int *, 0x6C) = temp_r6_2;
            M2C_FIELD(var_r20, int *, 0x70) = (int) M2C_FIELD(var_r20, int *, 0x40);
            M2C_FIELD(var_r20, int *, 0x74) = (int) M2C_FIELD(var_r20, int *, 0x44);
            fn_8018BFA0(var_r20 + 0x18, (float *)(arg0 + 0x70), (int *)rotation, temp_r6_2, 0, 0);
            if ((int) M2C_FIELD(var_r20, unsigned char *, 0x78) == 0) {
                M2C_FIELD(var_r20, unsigned char *, 0x78) = 1U;
                M2C_FIELD(var_r20, float *, 0x48) = (float) M2C_FIELD(var_r20, float *, 0x18);
                M2C_FIELD(var_r20, float *, 0x4C) = (float) M2C_FIELD(var_r20, float *, 0x1C);
                M2C_FIELD(var_r20, float *, 0x50) = (float) M2C_FIELD(var_r20, float *, 0x20);
                M2C_FIELD(var_r20, int *, 0x54) = (int) M2C_FIELD(var_r20, int *, 0x24);
                M2C_FIELD(var_r20, int *, 0x58) = (int) M2C_FIELD(var_r20, int *, 0x28);
                M2C_FIELD(var_r20, int *, 0x5C) = (int) M2C_FIELD(var_r20, int *, 0x2C);
                M2C_FIELD(var_r20, int *, 0x60) = (int) M2C_FIELD(var_r20, int *, 0x30);
                M2C_FIELD(var_r20, int *, 0x64) = (int) M2C_FIELD(var_r20, int *, 0x34);
                M2C_FIELD(var_r20, int *, 0x68) = (int) M2C_FIELD(var_r20, int *, 0x38);
                M2C_FIELD(var_r20, int *, 0x6C) = (int) M2C_FIELD(var_r20, int *, 0x3C);
                M2C_FIELD(var_r20, int *, 0x70) = (int) M2C_FIELD(var_r20, int *, 0x40);
                M2C_FIELD(var_r20, int *, 0x74) = (int) M2C_FIELD(var_r20, int *, 0x44);
            }
            M2C_FIELD(var_r20, float *, 0x10) = temp_f27;
        } else if ((temp_r5 != 0) && ((int) M2C_FIELD(var_r20, int *, 0x7C) == 4)) {
            temp_f0_3 = M2C_FIELD(var_r20, float *, 0xC) + (temp_f22 * M2C_FIELD(var_r20, float *, 0x10));
            M2C_FIELD(var_r20, float *, 0xC) = temp_f0_3;
            if ((temp_f0_3 < temp_f27) || (M2C_FIELD(var_r20, float *, 0xC) > M2C_FIELD(var_r20, float *, 0x14))) {
                var_f1_2 = M2C_FIELD(var_r20, float *, 0x14);
                temp_f0_4 = M2C_FIELD(var_r20, float *, 0xC);
                if (var_f1_2 < temp_f0_4) {

                } else {
                    var_f1_2 = temp_f0_4;
                }
                if (var_f1_2 > temp_f27) {

                } else {
                    var_f1_2 = temp_f27;
                }
                M2C_FIELD(var_r20, float *, 0xC) = (float) ((temp_f31 * var_f1_2) - M2C_FIELD(var_r20, float *, 0xC));
                M2C_FIELD(var_r20, float *, 0x10) = (float) -M2C_FIELD(var_r20, float *, 0x10);
            }
            temp_r3_7 = M2C_FIELD(var_r20, char **, 0);
            temp_f6_3 = M2C_FIELD(temp_r3_7, float *, 0x24);
            position2[0] = temp_f6_3;
            temp_f5_4 = M2C_FIELD(temp_r3_7, float *, 0x28);
            position2[1] = temp_f5_4;
            temp_f4_3 = M2C_FIELD(temp_r3_7, float *, 0x2C);
            position2[2] = temp_f4_3;
            temp_r3_8 = arg0 + (M2C_FIELD(var_r20, int *, 8) * 0xC);
            position2[0] = temp_f6_3 + M2C_FIELD(temp_r3_8, float *, 0xD94);
            position2[1] = temp_f5_4 + M2C_FIELD(temp_r3_8, float *, 0xD98);
            position2[2] = temp_f4_3 + M2C_FIELD(temp_r3_8, float *, 0xD9C);
            temp_f3_5 = M2C_FIELD(var_r20, float *, 0xC);
            temp_f2_9 = M2C_FIELD(var_r19, float *, 0xC) * temp_f3_5;
            temp_f1_6 = M2C_FIELD(var_r19, float *, 0x10) * temp_f3_5;
            temp_f0_5 = M2C_FIELD(var_r19, float *, 0x14) * temp_f3_5;
            angle2[0] = temp_f2_9;
            angle2[1] = temp_f1_6;
            angle2[2] = temp_f0_5;
            temp_r3_9 = M2C_FIELD(var_r20, char **, 0);
            if (&rotated2[0] == &angle2[0]) {
                rotated2[0] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x18)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 0)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0xC)));
                rotated2[1] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x1C)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 4)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0x10)));
                rotated2[2] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x20)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 8)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0x14)));
            } else {
                rotated2[0] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x18)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 0)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0xC)));
                rotated2[1] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x1C)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 4)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0x10)));
                rotated2[2] = (temp_f0_5 * M2C_FIELD(temp_r3_9, float *, 0x20)) + ((temp_f2_9 * M2C_FIELD(temp_r3_9, float *, 8)) + (temp_f1_6 * M2C_FIELD(temp_r3_9, float *, 0x14)));
            }
            fn_8014452C((int *)rotation2, rotated2[1], rotated2[0], rotated2[2]);
            M2C_FIELD(var_r20, float *, 0x48) = (float) M2C_FIELD(var_r20, float *, 0x18);
            M2C_FIELD(var_r20, float *, 0x4C) = (float) M2C_FIELD(var_r20, float *, 0x1C);
            M2C_FIELD(var_r20, float *, 0x50) = (float) M2C_FIELD(var_r20, float *, 0x20);
            M2C_FIELD(var_r20, int *, 0x54) = (int) M2C_FIELD(var_r20, int *, 0x24);
            M2C_FIELD(var_r20, int *, 0x58) = (int) M2C_FIELD(var_r20, int *, 0x28);
            M2C_FIELD(var_r20, int *, 0x5C) = (int) M2C_FIELD(var_r20, int *, 0x2C);
            M2C_FIELD(var_r20, int *, 0x60) = (int) M2C_FIELD(var_r20, int *, 0x30);
            M2C_FIELD(var_r20, int *, 0x64) = (int) M2C_FIELD(var_r20, int *, 0x34);
            M2C_FIELD(var_r20, int *, 0x68) = (int) M2C_FIELD(var_r20, int *, 0x38);
            temp_r3_10 = M2C_FIELD(var_r20, int *, 0x3C);
            M2C_FIELD(var_r20, int *, 0x6C) = temp_r3_10;
            M2C_FIELD(var_r20, int *, 0x70) = (int) M2C_FIELD(var_r20, int *, 0x40);
            M2C_FIELD(var_r20, int *, 0x74) = (int) M2C_FIELD(var_r20, int *, 0x44);
            if (M2C_FIELD(__AXFXGetLfoSinTable_801769CC(0), int *, 0x10) & 2) {
                transform[0] = M2C_FIELD(arg0, float *, 0x70);
                transform[1] = M2C_FIELD(arg0, float *, 0x74);
                temp_f2_10 = transform[0] * temp_f16;
                transform[2] = M2C_FIELD(arg0, float *, 0x78);
                temp_f1_7 = transform[1] * temp_f16;
                *(int *)&transform[3] = M2C_FIELD(arg0, int *, 0x7C);
                *(int *)&transform[4] = M2C_FIELD(arg0, int *, 0x80);
                *(int *)&transform[5] = M2C_FIELD(arg0, int *, 0x84);
                *(int *)&transform[6] = M2C_FIELD(arg0, int *, 0x88);
                *(int *)&transform[7] = M2C_FIELD(arg0, int *, 0x8C);
                *(int *)&transform[8] = M2C_FIELD(arg0, int *, 0x90);
                temp_r6_3 = M2C_FIELD(arg0, int *, 0x94);
                *(int *)&transform[9] = temp_r6_3;
                *(int *)&transform[10] = M2C_FIELD(arg0, int *, 0x98);
                *(int *)&transform[11] = M2C_FIELD(arg0, int *, 0x9C);
                transform[0] = temp_f2_10;
                transform[1] = temp_f1_7;
                transform[2] *= temp_f16;
                fn_8018BFA0(var_r20 + 0x18, &transform[0], (int *)rotation2, temp_r6_3, temp_f1_7, temp_f2_10);
                M2C_FIELD(var_r20, float *, 0x18) = (float) (M2C_FIELD(var_r20, float *, 0x18) * temp_f16);
                M2C_FIELD(var_r20, float *, 0x1C) = (float) (M2C_FIELD(var_r20, float *, 0x1C) * temp_f16);
                M2C_FIELD(var_r20, float *, 0x20) = (float) (M2C_FIELD(var_r20, float *, 0x20) * temp_f16);
            } else {
                fn_8018BFA0(var_r20 + 0x18, (float *)(arg0 + 0x70), (int *)rotation2, 0, 0, 0);
            }
            if ((int) M2C_FIELD(var_r20, unsigned char *, 0x78) == 0) {
                M2C_FIELD(var_r20, unsigned char *, 0x78) = 1U;
                M2C_FIELD(var_r20, float *, 0x48) = (float) M2C_FIELD(var_r20, float *, 0x18);
                M2C_FIELD(var_r20, float *, 0x4C) = (float) M2C_FIELD(var_r20, float *, 0x1C);
                M2C_FIELD(var_r20, float *, 0x50) = (float) M2C_FIELD(var_r20, float *, 0x20);
                M2C_FIELD(var_r20, int *, 0x54) = (int) M2C_FIELD(var_r20, int *, 0x24);
                M2C_FIELD(var_r20, int *, 0x58) = (int) M2C_FIELD(var_r20, int *, 0x28);
                M2C_FIELD(var_r20, int *, 0x5C) = (int) M2C_FIELD(var_r20, int *, 0x2C);
                M2C_FIELD(var_r20, int *, 0x60) = (int) M2C_FIELD(var_r20, int *, 0x30);
                M2C_FIELD(var_r20, int *, 0x64) = (int) M2C_FIELD(var_r20, int *, 0x34);
                M2C_FIELD(var_r20, int *, 0x68) = (int) M2C_FIELD(var_r20, int *, 0x38);
                M2C_FIELD(var_r20, int *, 0x6C) = (int) M2C_FIELD(var_r20, int *, 0x3C);
                M2C_FIELD(var_r20, int *, 0x70) = (int) M2C_FIELD(var_r20, int *, 0x40);
                M2C_FIELD(var_r20, int *, 0x74) = (int) M2C_FIELD(var_r20, int *, 0x44);
            }
        }
        var_r18 += 1;
        var_r20 += 0x80;
        var_r19 += 0x40;
    } while (var_r18 < 0x11);
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

float PSVECSquareDistance(float *, float *);         /* extern */
void *__AXFXGetLfoSinTable_801769CC();              /* extern */
void *fn_8017960C(int);                             /* extern */
int fn_801796CC(int, float *, int);       /* extern */
int fn_80189BDC(float, float, float, float, float, float);      /* extern */
int fn_8018A174(void *);                        /* extern */
void fn_8018F76C(void *, int);                   /* extern */
int fn_801B8610(int, int);                      /* extern */
void fn_801BF2A4(void *, int, float *, void *, void *, int, void *, float, float, float); /* extern */
void fn_802E30C8(void *, int);                   /* extern */
#pragma push
#pragma small_data off
extern char lbl_80332758;
#pragma pop
extern float lbl_80558DC4;
extern float lbl_8055A460;
extern float lbl_80561F98;
extern float lbl_80561FC4;
extern float lbl_80561FD0;
extern float lbl_80561FD4;
extern float lbl_80561FEC;
extern float lbl_80561FF4;
extern float lbl_80561FF8;
extern float lbl_80561FFC;
extern float lbl_80562000;
extern float lbl_80562004;
extern float lbl_80562008;
extern float lbl_8056200C;
extern float lbl_80562010;
extern float lbl_80562014;
extern float lbl_80562018;
extern float lbl_8056201C;
extern float lbl_80562020;
extern float lbl_80562024;
extern float lbl_80562028;
extern float lbl_8056202C;
extern float lbl_80562030;
extern float lbl_80562034;
#pragma scheduling invalid_target
void fn_8018E3EC(char *arg0, float *arg1, void *arg2, int arg3, int arg4, int arg5, int arg_sp0) {
    extern float __fabsf(float);
extern float lbl_80561FE8;
extern char lbl_80332758;
extern float lbl_80558DC4;
extern float lbl_8055A460;
extern float lbl_80561F74;
extern float lbl_80561F88;
extern float lbl_80561F8C;
extern float lbl_80561F98;
extern float lbl_80561FC4;
extern float lbl_80561FD0;
extern float lbl_80561FD4;
extern float lbl_80561FE4;
extern float lbl_80561FEC;
extern float lbl_80561FF4;
extern float lbl_80561FF8;
extern float lbl_80561FFC;
extern float lbl_80562000;
extern float lbl_80562004;
extern float lbl_80562008;
extern float lbl_8056200C;
extern float lbl_80562010;
extern float lbl_80562014;
extern float lbl_80562018;
extern float lbl_8056201C;
extern float lbl_80562020;
extern float lbl_80562024;
extern float lbl_80562028;
extern float lbl_8056202C;
extern float lbl_80562030;
extern float lbl_80562034;

    short spEC;
    float spE0[3];
    float spDC;
    float spD8;
    float spD4;
    float spD0;
    float spCC;
    float spC8;
    volatile float spC4;
    volatile int spC0;
    volatile float spBC;
    float spB8;
    float spB4;
    float spB0;
    float spA4;
    float spA0;
    float sp9C;
    float sp98;
    float sp94;
    float sp90;
    float sp8C;
    float sp88;
    float sp84;
    float sp80;
    float sp7C;
    float sp78;
    float sp74;
    float sp70;
    float sp6C;
    float sp68;
    float sp64;
    float sp60;
    float sp5C;
    float sp58;
    float sp54;
    float sp50;
    float sp4C;
    float sp48;
    float sp44;
    float sp40;
    float sp30;
    float sp20;
    float sp1C;
    float spC;
    float *temp_r3_3;
    float *temp_r3_4;
    float *temp_r3_7;
    float temp_f0;
    float temp_f0_2;
    float temp_f0_3;
    float temp_f0_4;
    float temp_f0_5;
    float temp_f0_6;
    float temp_f0_7;
    float temp_f0_8;
    float temp_f0_9;
    float temp_f1;
    float temp_f1_10;
    float temp_f1_11;
    float temp_f1_12;
    float temp_f1_13;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f1_4;
    float temp_f1_5;
    float temp_f1_6;
    float temp_f1_7;
    float temp_f1_8;
    float temp_f1_9;
    float temp_f23;
    float temp_f23_2;
    float temp_f23_3;
    float temp_f23_4;
    float temp_f24;
    float temp_f25;
    float temp_f25_2;
    float temp_f26;
    float temp_f26_2;
    float temp_f28;
    float temp_f29;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f2_4;
    float temp_f2_5;
    float temp_f2_6;
    float temp_f2_7;
    float temp_f30;
    float temp_f31;
    float temp_f3;
    float temp_f3_2;
    float temp_f3_3;
    float temp_f3_4;
    float temp_f4;
    float temp_f4_2;
    float temp_f4_3;
    float temp_f5;
    float temp_f5_2;
    float temp_f6;
    float temp_f6_2;
    float temp_f7;
    float temp_r5;
    float temp_r8;
    float var_f0;
    float var_f0_2;
    float var_f0_3;
    float var_f1;
    float var_f1_2;
    float var_f1_3;
    float var_f1_4;
    float var_f1_5;
    float var_f22;
    float var_f22_2;
    float var_f22_3;
    float var_f25;
    float var_f2;
    float var_f2_2;
    float var_f2_3;
    float var_f2_4;
    float var_f3;
    int temp_cr0_eq;
    int temp_cr0_eq_2;
    int temp_r0;
    int temp_r0_2;
    int temp_r21;
    int temp_r22;
    int temp_r3_5;
    int temp_r3_9;
    int temp_r4;
    int temp_r4_2;
    int temp_r7;
    int var_r0;
    int var_r17;
    int var_r17_2;
    int var_r19;
    int var_r19_2;
    int var_r20;
    int var_r20_2;
    int var_r20_3;
    int var_r4;
    int var_r4_2;
    unsigned char temp_r3_6;
    void **temp_r3_10;
    void **temp_r3_11;
    void *temp_r17;
    void *temp_r18;
    void *temp_r20;
    void *temp_r26;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_8;
    void *temp_r4_3;
    void *temp_r5_2;
    void *temp_r6;
    void *temp_r9;
    char *var_r18;
    void *var_r21;
    char *var_r21_2;
    char *var_r22;
    char *var_r24;

    temp_f6 = lbl_80561FF8 / M2C_FIELD(arg0, float *, 0xD4);
    temp_f5 = M2C_FIELD(arg1, float *, 0) * temp_f6;
    temp_f3 = M2C_FIELD(arg1, float *, 4) * temp_f6;
    temp_f1 = M2C_FIELD(arg1, float *, 8) * temp_f6;
    temp_f4 = M2C_FIELD(arg0, float *, 0x26F0) + temp_f5;
    temp_f2 = M2C_FIELD(arg0, float *, 0x26F4) + temp_f3;
    M2C_FIELD(arg0, float *, 0x26F0) = temp_f4;
    M2C_FIELD(arg0, float *, 0x26F4) = temp_f2;
    M2C_FIELD(arg0, float *, 0x26F8) = (float) (M2C_FIELD(arg0, float *, 0x26F8) + temp_f1);
    if (fn_80189BDC(temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6) != 0) {
        0;
        if ((__fabsf(M2C_FIELD(arg0, float *, 0x2690)) <= lbl_80558DC4) && (((M2C_FIELD(arg0, float *, 0x4C) < lbl_80561F74) && (arg5 != 0x6D)) || (arg5 == 0x3E7))) {
            fn_8018E330(arg0);
        }
        if (arg5 == 0x73) {
            var_r4 = 1;
            if (((int) M2C_FIELD(arg0, unsigned char *, 0x25C8) == 0) && (M2C_FIELD(arg0, float *, 0x25BC) <= lbl_80558DC4)) {
                var_r4 = 0;
            }
            if (var_r4 == 0) {
                goto block_11;
            }
        } else {
block_11:
            if (arg5 == 0x74) {
                return;
            }
            spC8 = M2C_FIELD(arg1, float *, 0);
            spCC = M2C_FIELD(arg1, float *, 4);
            spD0 = M2C_FIELD(arg1, float *, 8);
            if (arg3 != 0) {
                spC8 *= lbl_80561FC4;
                spCC *= lbl_80561FC4;
                spD0 *= lbl_80561FC4;
            }
            temp_r5 = M2C_FIELD(arg2, float *, 0);
            temp_r4 = M2C_FIELD(arg2, int *, 4);
            spBC = temp_r5;
            spC0 = temp_r4;
            spC4 = M2C_FIELD(arg2, float *, 8);
            temp_f24 = PSVECMag(&spC8);
            if (!(M2C_FIELD(__AXFXGetLfoSinTable_801769CC(), int *, 4) & 0x4000) && (M2C_FIELD(arg0, float *, 0x2690) < lbl_80561FFC)) {
                if (!(temp_f24 < lbl_80562000) && (lbl_8055E3C8 >= (lbl_80561FE8 + M2C_FIELD(arg0, float *, 0x26D8))) && ((arg4 < 0) || (M2C_FIELD(arg0, float *, 0x25BC) <= lbl_80558DC4))) {
                    spB4 = spCC;
                    var_f1 = lbl_80561F74;
                    spB0 = spC8;
                    spB8 = spD0;
                    if (var_f1 < spB4) {

                    } else {
                        var_f1 = spB4;
                    }
                    spB4 = var_f1;
                    temp_f1_2 = PSVECMag(&spB0);
                    var_f22 = temp_f1_2;
                    if (arg4 >= 0) {
                        var_f22 = temp_f1_2 * lbl_80561F98;
                        if (((int) M2C_FIELD(arg0, int *, 0x1F0) != 0x50) && (M2C_FIELD(arg0, float *, 0x25BC) <= lbl_80558DC4) && ((M2C_FIELD(fn_8017960C(arg4), float *, 0x25BC) > lbl_80558DC4) || (var_f22 > lbl_80562004)) && (M2C_FIELD(fn_8017960C(arg4), float *, 0x25D4) > M2C_FIELD(arg0, float *, 0x25D4))) {
                            fn_8018A174(arg0);
                        }
                    } else if (arg5 == 0x73) {
                        var_f22 = temp_f1_2 * lbl_8055A460;
                    }
                    if ((((arg4 >= 0) && (M2C_FIELD(fn_8017960C(arg4), float *, 0x25BC) > lbl_80558DC4)) || (!(var_f22 < lbl_80562008) && ((arg4 >= 0) || !(M2C_FIELD(arg0, float *, 0x25D4) < lbl_8056200C) || !(var_f22 < lbl_80562010)))) && (((unsigned int) (M2C_FIELD(__AXFXGetLfoSinTable_801769CC(), int *, 4) + 0xFFE80000) != 0x304U) || ((int) M2C_FIELD(arg0, int *, 0x1F0) != 0x50) || (arg4 < 0))) {
                        fn_8018E330(arg0);
                        goto block_43;
                    }
                }
            } else {
block_43:
                var_r18 = (char *)arg0 + 0xC;
                var_f25 = lbl_80562014;
                var_r21 = 0;
                spA4 = lbl_80561F74;
                temp_f26 = lbl_80562018;
                var_r19 = 1;
                spC = lbl_80561F74;
                var_r17 = 0x34;
                temp_f23 = lbl_8056201C;
                sp1C = lbl_80561F74;
loop_49:
                if (var_r19 < (int) M2C_FIELD(arg0, int *, 0x5F8)) {
                    temp_r3 = M2C_FIELD(arg0, char **, 0x26C) + var_r17;
                    temp_r20 = (char *)temp_r3 + 4;
                    if ((int) M2C_FIELD(temp_r3, unsigned char *, 0x34) == 0) {
                        sp98 = M2C_FIELD(temp_r20, float *, 0x1C) + (M2C_FIELD(var_r18, float *, 0x5FC) * temp_f26);
                        sp9C = M2C_FIELD(temp_r20, float *, 0x20) + (M2C_FIELD(var_r18, float *, 0x600) * temp_f26);
                        temp_f1_3 = M2C_FIELD(var_r18, float *, 0x604) * temp_f26;
                        spA0 = M2C_FIELD(temp_r20, float *, 0x24) + temp_f1_3;
                        temp_f1_4 = PSVECSquareDistance(&sp98, (float *)&spBC);
                        if ((temp_f1_4 < temp_f23) && (temp_f1_4 < var_f25)) {
                            var_f25 = temp_f1_4;
                            var_r21 = temp_r20;
                            sp20 = sp98;
                            sp30 = sp9C;
                            sp40 = spA0;
                        }
                    }
                    var_r17 += 0x34;
                    var_r18 += 0xC;
                    var_r19 += 1;
                    goto loop_49;
                }
                if (var_r21 != 0) {
                    temp_r4_2 = M2C_FIELD(var_r21, int *, 0);
                    temp_r9 = (char *)arg0 + (temp_r4_2 * 0xC);
                    temp_r8 = M2C_FIELD(temp_r9, float *, 0x600);
                    sp8C = M2C_FIELD(temp_r9, float *, 0x5FC);
                    sp90 = temp_r8;
                    sp94 = M2C_FIELD(temp_r9, float *, 0x604);
                    fn_8018DE94(arg0, temp_r4_2, &spC8, -1, 0);
                    temp_f2_2 = spC8 * lbl_80561FC4;
                    temp_f1_5 = spCC * lbl_80561FC4;
                    sp80 = temp_f2_2;
                    sp84 = temp_f1_5;
                    sp88 = spD0 * lbl_80561FC4;
                    PSVECNormalize(&sp80, &sp80);
                    temp_r5_2 = (char *)arg0 + (M2C_FIELD(var_r21, int *, 0) * 0xC);
                    sp74 = sp8C - M2C_FIELD(temp_r5_2, float *, 0x5FC);
                    sp78 = sp90 - M2C_FIELD(temp_r5_2, float *, 0x600);
                    sp7C = sp94 - M2C_FIELD(temp_r5_2, float *, 0x604);
                    var_r20 = 1;
                    temp_f23_2 = (float) fabs(PSVECDotProduct((int *)(&sp80), &sp74));
                    temp_r3_2 = (char *)arg0 + (M2C_FIELD(var_r21, int *, 0) * 0xC);
                    var_r19_2 = 0x34;
                    temp_f4_2 = M2C_FIELD(var_r21, float *, 0x1C) + M2C_FIELD(temp_r3_2, float *, 0x5FC);
                    temp_f2_3 = M2C_FIELD(var_r21, float *, 0x20) + M2C_FIELD(temp_r3_2, float *, 0x600);
                    temp_f0 = M2C_FIELD(var_r21, float *, 0x24) + M2C_FIELD(temp_r3_2, float *, 0x604);
                    temp_f29 = lbl_80561FD4;
                    sp68 = temp_f4_2;
                    sp6C = temp_f2_3;
                    sp70 = temp_f0;
                    temp_f30 = lbl_80561FD0;
                    temp_f31 = lbl_80561F88;
                    temp_f28 = lbl_80561F74;
loop_80:
                    if (var_r20 < (int) M2C_FIELD(arg0, int *, 0x5F8)) {
                        temp_r18 = M2C_FIELD(arg0, char **, 0x26C) + var_r19_2;
                        temp_r17 = (char *)arg0 + (M2C_FIELD(temp_r18, int *, 4) * 0xC);
                        temp_f5_2 = M2C_FIELD(temp_r18, float *, 0x20) + M2C_FIELD(temp_r17, float *, 0x5FC);
                        temp_f4_3 = M2C_FIELD(temp_r18, float *, 0x24) + M2C_FIELD(temp_r17, float *, 0x600);
                        temp_f3_2 = M2C_FIELD(temp_r18, float *, 0x28) + M2C_FIELD(temp_r17, float *, 0x604);
                        temp_f2_4 = temp_f5_2 - (float) temp_f4_2;
                        temp_f1_6 = temp_f4_3 - (float) temp_f2_3;
                        sp5C = temp_f5_2;
                        sp60 = temp_f4_3;
                        sp64 = temp_f3_2;
                        sp50 = temp_f2_4;
                        sp54 = temp_f1_6;
                        sp58 = temp_f3_2 - (float) temp_f0;
                        temp_f1_7 = PSVECDotProduct((int *)(&sp80), &sp50);
                        if (temp_f1_7 < temp_f23_2) {
                            var_f22_2 = temp_f1_7;
                        } else {
                            var_f22_2 = temp_f23_2;
                        }
                        if (var_f22_2 > temp_f28) {
                            var_f1_2 = PSVECDotProduct((int *)(&sp50), &sp50);
                            if (temp_f29 > var_f1_2) {
                                var_f1_2 = temp_f29;
                            }
                            var_f3 = temp_f30 / var_f1_2;
                            if (temp_f31 < var_f3) {
                                var_f3 = temp_f31;
                            }
                            temp_f3_3 = -var_f22_2 * var_f3;
                            temp_f2_5 = M2C_FIELD(temp_r17, float *, 0x5FC) + (sp80 * temp_f3_3);
                            M2C_FIELD(temp_r17, float *, 0x5FC) = temp_f2_5;
                            M2C_FIELD(temp_r17, float *, 0x600) = (float) (M2C_FIELD(temp_r17, float *, 0x600) + (sp84 * temp_f3_3));
                            M2C_FIELD(temp_r17, float *, 0x604) = (float) (M2C_FIELD(temp_r17, float *, 0x604) + (sp88 * temp_f3_3));
                            var_f1_3 = M2C_FIELD(temp_r18, float *, 0x14);
                            temp_f0_2 = M2C_FIELD(temp_r18, float *, 8);
                            if (var_f1_3 < temp_f2_5) {

                            } else {
                                var_f1_3 = temp_f2_5;
                            }
                            if (var_f1_3 > temp_f0_2) {

                            } else {
                                var_f1_3 = temp_f0_2;
                            }
                            M2C_FIELD(temp_r17, float *, 0x5FC) = var_f1_3;
                            var_f2 = M2C_FIELD(temp_r18, float *, 0x18);
                            temp_f0_3 = M2C_FIELD(temp_r17, float *, 0x600);
                            temp_f1_8 = M2C_FIELD(temp_r18, float *, 0xC);
                            if (var_f2 < temp_f0_3) {

                            } else {
                                var_f2 = temp_f0_3;
                            }
                            if (var_f2 > temp_f1_8) {

                            } else {
                                var_f2 = temp_f1_8;
                            }
                            M2C_FIELD(temp_r17, float *, 0x600) = var_f2;
                            var_f2_2 = M2C_FIELD(temp_r18, float *, 0x1C);
                            temp_f0_4 = M2C_FIELD(temp_r17, float *, 0x604);
                            temp_f1_9 = M2C_FIELD(temp_r18, float *, 0x10);
                            if (var_f2_2 < temp_f0_4) {

                            } else {
                                var_f2_2 = temp_f0_4;
                            }
                            if (var_f2_2 > temp_f1_9) {

                            } else {
                                var_f2_2 = temp_f1_9;
                            }
                            M2C_FIELD(temp_r17, float *, 0x604) = var_f2_2;
                        }
                        var_r19_2 += 0x34;
                        var_r20 += 1;
                        goto loop_80;
                    }
                    temp_f26_2 = lbl_80561FF4;
                    var_r22 = (char *)arg0 + 0x152C;
                    temp_f25 = lbl_80561FD0;
                    var_r21_2 = &lbl_80332758 + 0xE8;
                    temp_f23_3 = lbl_80561FE4;
                    var_r20_2 = 0;
                    do {
                        if ((((int) M2C_FIELD(var_r22, int *, 0) != 0) && ((int) M2C_FIELD(var_r22, int *, 4) > 0) && ((int) M2C_FIELD(var_r22, int *, 0x7C) == 0)) || ((int) M2C_FIELD(var_r22, int *, 0x7C) == 2)) {
                            temp_r3_3 = (float *)((char *)arg0 + (M2C_FIELD(var_r22, int *, 4) * 0xC) + 0x5FC);
                            temp_f0_5 = M2C_FIELD(var_r21_2, float *, 0x30);
                            if (PSVECDotProduct((int *)(temp_r3_3), temp_r3_3) > (temp_f0_5 * temp_f0_5)) {
                                temp_r3_4 = (float *)((char *)var_r21_2 + 0xC);
                                0;
                                if ((float) fabs(PSVECDotProduct((int *)(temp_r3_4), temp_r3_4)) != lbl_80558DC4) {
                                    if ((unsigned int) M2C_FIELD(var_r21_2, unsigned int *, 0) <= 1U) {
                                        if ((int) M2C_FIELD(var_r22, int *, 0x7C) != 2) {
                                            M2C_FIELD(var_r22, int *, 0x7C) = 2;
                                            M2C_FIELD(var_r22, signed char *, 0x78) = 0;
                                        }
                                    } else {
                                        temp_r3_5 = fn_80129D18(4, 0xA);
                                        if ((int) M2C_FIELD(var_r22, int *, 0x7C) == 2) {
                                            if (temp_r3_5 < 2) {
                                                M2C_FIELD(var_r22, int *, 0x7C) = 3;
                                                M2C_FIELD(var_r22, signed char *, 0x78) = 0;
                                            }
                                        } else {
                                            if (temp_r3_5 < 7) {
                                                M2C_FIELD(var_r22, int *, 0x7C) = 2;
                                            } else if (temp_r3_5 < 8) {
                                                M2C_FIELD(var_r22, int *, 0x7C) = 3;
                                            } else {
                                                M2C_FIELD(var_r22, int *, 0x7C) = 1;
                                            }
                                            M2C_FIELD(var_r22, signed char *, 0x78) = 0;
                                        }
                                        if ((int) M2C_FIELD(var_r22, int *, 0x7C) == 2) {
                                            var_f0 = M2C_FIELD(var_r22, float *, 0xC);
                                            if (var_f0 > temp_f26_2) {

                                            } else {
                                                var_f0 = temp_f26_2;
                                            }
                                            M2C_FIELD(var_r22, float *, 0xC) = var_f0;
                                            var_f0_2 = M2C_FIELD(var_r22, float *, 0x10);
                                            if (var_f0_2 > temp_f25) {

                                            } else {
                                                var_f0_2 = temp_f25;
                                            }
                                            M2C_FIELD(var_r22, float *, 0x10) = var_f0_2;
                                        }
                                    }
                                } else {
                                    M2C_FIELD(var_r22, int *, 0x7C) = 3;
                                    M2C_FIELD(var_r22, signed char *, 0x78) = 0;
                                }
                                if ((int) M2C_FIELD(var_r22, int *, 0x7C) == 3) {
                                    temp_r7 = M2C_FIELD(var_r21_2, int *, 8);
                                    temp_r4_3 = M2C_FIELD(arg0, char **, 0x26C) + (temp_r7 * 0x18);
                                    temp_r6 = (char *)temp_r4_3 + 0x2138;
                                    temp_f0_6 = M2C_FIELD(temp_r4_3, float *, 0x2138) + M2C_FIELD(temp_r4_3, float *, 0x2144);
                                    sp44 = temp_f0_6;
                                    temp_f1_10 = temp_f0_6 * temp_f23_3;
                                    temp_f0_7 = M2C_FIELD(temp_r6, float *, 4) + M2C_FIELD(temp_r6, float *, 0x10);
                                    sp48 = temp_f0_7;
                                    temp_f3_4 = M2C_FIELD(temp_r6, float *, 8);
                                    temp_f2_6 = temp_f3_4 + M2C_FIELD(temp_r6, float *, 0x14);
                                    sp48 = temp_f0_7 * temp_f23_3;
                                    sp44 = temp_f1_10;
                                    sp4C = temp_f2_6 * temp_f23_3;
                                    fn_801BF2A4(arg0, 1 << temp_r7, &sp44, temp_r6, (char *)temp_r6 + 0xC, M2C_FIELD(var_r21_2, int *, 0x34), (char *)var_r21_2 + 0x38, temp_f1_10, temp_f2_6, temp_f3_4);
                                }
                            }
                        }
                        var_r20_2 += 1;
                        var_r22 += 0x80;
                        var_r21_2 += 0x40;
                    } while (var_r20_2 < 0x11);
                    temp_f25_2 = lbl_80561FEC;
                    var_r24 = &lbl_80332758 + 0x5B0;
                    temp_f23_4 = lbl_80561F8C;
                    var_r20_3 = 0;
                    do {
                        temp_r21 = M2C_FIELD(var_r24, int *, 4);
                        temp_r26 = arg0 + temp_r21;
                        temp_r3_6 = M2C_FIELD(temp_r26, unsigned char *, 0x1E2C);
                        temp_r22 = 1 << temp_r21;
                        if ((temp_r3_6 != 0xFF) && !(M2C_FIELD(arg0, int *, 0x1E3C) & temp_r22)) {
                            temp_r3_7 = (float *)((char *)arg0 + (temp_r3_6 * 0xC) + 0x5FC);
                            temp_f0_8 = M2C_FIELD(var_r24, float *, 8);
                            if (PSVECDotProduct((int *)(temp_r3_7), temp_r3_7) > (temp_f0_8 * temp_f0_8)) {
                                M2C_FIELD(arg0, int *, 0x1E3C) = (int) (M2C_FIELD(arg0, int *, 0x1E3C) | temp_r22);
                                temp_r0 = M2C_FIELD(var_r24, int *, 0xC);
                                if (temp_r0 > 0) {
                                    M2C_FIELD(arg0, int *, 0x1E40) = (int) (M2C_FIELD(arg0, int *, 0x1E40) | (1 << temp_r0));
                                }
                                if ((temp_r21 >= 2) && (temp_r21 <= 7)) {
                                    temp_r3_8 = M2C_FIELD(arg0, char **, 0x26C) + (M2C_FIELD(temp_r26, unsigned char *, 0x1E2C) * 0x34);
                                    if (&spD4 == (float *)((char *)temp_r3_8 + 0x20)) {
                                        temp_f6_2 = M2C_FIELD(temp_r3_8, float *, 0x24);
                                        temp_f0_9 = M2C_FIELD(temp_r3_8, float *, 0x20);
                                        temp_f7 = M2C_FIELD(temp_r3_8, float *, 0x28);
                                        spD4 = (temp_f7 * M2C_FIELD(arg0, float *, 0x54)) + ((temp_f0_9 * M2C_FIELD(arg0, float *, 0x3C)) + (temp_f6_2 * M2C_FIELD(arg0, float *, 0x48)));
                                        spD8 = (temp_f7 * M2C_FIELD(arg0, float *, 0x58)) + ((temp_f0_9 * M2C_FIELD(arg0, float *, 0x40)) + (temp_f6_2 * M2C_FIELD(arg0, float *, 0x4C)));
                                        spDC = (temp_f7 * M2C_FIELD(arg0, float *, 0x5C)) + ((temp_f0_9 * M2C_FIELD(arg0, float *, 0x44)) + (temp_f6_2 * M2C_FIELD(arg0, float *, 0x50)));
                                    } else {
                                        spD4 = (M2C_FIELD(temp_r3_8, float *, 0x28) * M2C_FIELD(arg0, float *, 0x54)) + ((M2C_FIELD(temp_r3_8, float *, 0x20) * M2C_FIELD(arg0, float *, 0x3C)) + (M2C_FIELD(temp_r3_8, float *, 0x24) * M2C_FIELD(arg0, float *, 0x48)));
                                        spD8 = (M2C_FIELD(temp_r3_8, float *, 0x28) * M2C_FIELD(arg0, float *, 0x58)) + ((M2C_FIELD(temp_r3_8, float *, 0x20) * M2C_FIELD(arg0, float *, 0x40)) + (M2C_FIELD(temp_r3_8, float *, 0x24) * M2C_FIELD(arg0, float *, 0x4C)));
                                        spDC = (M2C_FIELD(temp_r3_8, float *, 0x28) * M2C_FIELD(arg0, float *, 0x5C)) + ((M2C_FIELD(temp_r3_8, float *, 0x20) * M2C_FIELD(arg0, float *, 0x44)) + (M2C_FIELD(temp_r3_8, float *, 0x24) * M2C_FIELD(arg0, float *, 0x50)));
                                    }
                                    temp_f2_7 = spD8;
                                    temp_f1_11 = spDC;
                                    spD4 += M2C_FIELD(arg0, float *, 0x60);
                                    spD8 = temp_f2_7 + M2C_FIELD(arg0, float *, 0x64);
                                    spDC = temp_f1_11 + M2C_FIELD(arg0, float *, 0x68);
                                    fn_8017B6D4(arg0, spE0, &spD4, temp_f1_11, temp_f2_7);
                                    spEC = M2C_FIELD(arg0, short *, 0x6C);
                                    fn_801796CC(7, &spD4, 0x1C);
                                }
                                if ((temp_r21 >= 8) && (temp_r21 <= 0xB) && (fn_80129D18(4, 0xA) < 5)) {
                                    fn_8018F76C(arg0, temp_r21 - 8);
                                }
                                if (temp_r21 == 0xC) {
                                    if (fn_80129D18(4, 0xA) < 5) {
                                        M2C_FIELD(arg0, int *, 0x268C) = 6;
                                    } else {
                                        M2C_FIELD(arg0, int *, 0x268C) = 3;
                                    }
                                    if ((int) M2C_FIELD(arg0, int *, 0x15A8) != 3) {
                                        var_f0_3 = M2C_FIELD(arg0, float *, 0x1538);
                                        M2C_FIELD(arg0, int *, 0x15A8) = 2;
                                        M2C_FIELD(arg0, signed char *, 0x15A4) = 0;
                                        M2C_FIELD(arg0, float *, 0x153C) = temp_f25_2;
                                        if (var_f0_3 > temp_f23_4) {

                                        } else {
                                            var_f0_3 = temp_f23_4;
                                        }
                                        M2C_FIELD(arg0, float *, 0x1538) = var_f0_3;
                                    }
                                }
                            }
                        }
                        var_r20_3 += 1;
                        var_r24 += 0x10;
                    } while (var_r20_3 < 0xD);
                }
                var_f22_3 = M2C_FIELD(arg0, float *, 0x2690);
                if (M2C_FIELD(__AXFXGetLfoSinTable_801769CC(), int *, 4) & 0x4000) {
                    temp_r0_2 = M2C_FIELD(arg0, int *, 0x268C);
                    var_r17_2 = 0;
                    if (temp_r0_2 == 0) {
                        if (temp_f24 > lbl_80562020) {
                            if (arg5 != 0x70) {
                                var_f1_4 = lbl_80561FD4;
                            } else {
                                var_f1_4 = lbl_80562024;
                            }
                            var_f2_3 = lbl_80562028 * temp_f24;
                            if (var_f2_3 < var_f1_4) {

                            } else {
                                var_f2_3 = var_f1_4;
                            }
                            temp_f1_12 = M2C_FIELD(arg0, float *, 0x2690) + var_f2_3;
                            M2C_FIELD(arg0, float *, 0x2690) = temp_f1_12;
                            if ((temp_f1_12 > lbl_8056202C) || ((temp_f1_12 > lbl_80561F8C) && (var_f2_3 > lbl_80562030))) {
                                if (fn_80129D18(4, 2) != 0) {
                                      M2C_FIELD(arg0, int *, 0x268C) = 2;
                                  } else {
                                      M2C_FIELD(arg0, int *, 0x268C) = 3;
                                  }
                                if (((int) M2C_FIELD(arg0, int *, 0x26B0) < 0) && (fn_80129D18(4, 6) == 0)) {
                                    var_r0 = 2;
                                      if ((spC4 > lbl_80561F74) && (spBC < lbl_80561F74)) {
                                          var_r0 = 3;
                                      }
                                      M2C_FIELD(arg0, int *, 0x26B0) = var_r0;
                                }
                            }
                        }
                    } else if ((temp_r0_2 >= 1) && (temp_r0_2 <= 4)) {
                        if (temp_f24 > lbl_80562020) {
                            if (arg5 != 0x70) {
                                var_f1_5 = lbl_80561FD4;
                            } else {
                                var_f1_5 = lbl_80562024;
                            }
                            var_f2_4 = lbl_80562028 * temp_f24;
                            if (var_f2_4 < var_f1_5) {

                            } else {
                                var_f2_4 = var_f1_5;
                            }
                            temp_f1_13 = M2C_FIELD(arg0, float *, 0x2690) + var_f2_4;
                            M2C_FIELD(arg0, float *, 0x2690) = temp_f1_13;
                            if ((arg5 == 0x70) && (arg4 == (int) M2C_FIELD(arg0, int *, 0x1EC)) && (temp_f1_13 > lbl_80562034)) {
                                if (var_f22_3 > lbl_80562034) {

                                } else {
                                    var_f22_3 = lbl_80562034;
                                }
                                M2C_FIELD(arg0, float *, 0x2690) = var_f22_3;
                            }
                            if (M2C_FIELD(arg0, float *, 0x2690) > lbl_80561F88) {
                                M2C_FIELD(arg0, float *, 0x2690) = (float) lbl_80561F88;
                                temp_r3_9 = fn_80129D18(4, 3);
                                switch (temp_r3_9) { /* irregular */
                                case 0:
                                    M2C_FIELD(arg0, int *, 0x268C) = 0xA;
                                    break;
                                case 1:
                                    M2C_FIELD(arg0, int *, 0x268C) = 0xB;
                                    break;
                                default:
                                    M2C_FIELD(arg0, int *, 0x268C) = 0xC;
                                    break;
                                }
                                if (fn_80129D18(4, 4) == 0) {
                                    if (spC4 > lbl_80561F74) {
                                          var_r4_2 = (spBC >= lbl_80561F74) ? 1 : 0;
                                      } else {
                                          var_r4_2 = (spBC < lbl_80561F74) ? 3 : 2;
                                      }
                                      if (!(M2C_FIELD(((char *)arg0 + (var_r4_2 * 0x74)), int *, 0x241C) & 8)) {
                                        fn_8018F76C(arg0, var_r4_2);
                                    }
                                }
                                fn_802E30C8(&lbl_80332758 + 0x6B8, M2C_FIELD(arg0, int *, 0x1EC));
                                var_r17_2 = 1;
                                fn_801B8610(M2C_FIELD(arg0, int *, 0x1EC), arg4);
                            }
                        }
                    } else if (temp_r0_2 >= 9) {
                        temp_r3_10 = M2C_FIELD(arg0, void ***, 0x270);
                        if (M2C_FIELD(*temp_r3_10, int (**)(void **), 0x38)(temp_r3_10) == 0) {
                            fn_802E30C8(&lbl_80332758 + 0x6CC, M2C_FIELD(arg0, int *, 0x1EC));
                            var_r17_2 = 1;
                        }
                    }
                    if (var_r17_2 != 0) {
                        temp_r3_11 = M2C_FIELD(arg0, void ***, 0x270);
                        M2C_FIELD(*temp_r3_11, int (**)(void **, int), 0x30)(temp_r3_11, arg4);
                    }
                }
                M2C_FIELD(arg0, float *, 0x269C) = (float) lbl_80561F74;
            }
        }
    }
}
#pragma scheduling on
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

