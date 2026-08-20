# General Purpose Registers (GPRs)
.set r0, 0
.set r1, 1
.set r2, 2
.set r3, 3
.set r4, 4
.set r5, 5
.set r6, 6
.set r7, 7
.set r8, 8
.set r9, 9
.set r10, 10
.set r11, 11
.set r12, 12
.set r13, 13
.set r14, 14
.set r15, 15
.set r16, 16
.set r17, 17
.set r18, 18
.set r19, 19
.set r20, 20
.set r21, 21
.set r22, 22
.set r23, 23
.set r24, 24
.set r25, 25
.set r26, 26
.set r27, 27
.set r28, 28
.set r29, 29
.set r30, 30
.set r31, 31

# Floating Point Registers (FPRs)
.set f0, 0
.set f1, 1
.set f2, 2
.set f3, 3
.set f4, 4
.set f5, 5
.set f6, 6
.set f7, 7
.set f8, 8
.set f9, 9
.set f10, 10
.set f11, 11
.set f12, 12
.set f13, 13
.set f14, 14
.set f15, 15
.set f16, 16
.set f17, 17
.set f18, 18
.set f19, 19
.set f20, 20
.set f21, 21
.set f22, 22
.set f23, 23
.set f24, 24
.set f25, 25
.set f26, 26
.set f27, 27
.set f28, 28
.set f29, 29
.set f30, 30
.set f31, 31

# Graphics Quantization Registers (GQRs)
.set qr0, 0
.set qr1, 1
.set qr2, 2
.set qr3, 3
.set qr4, 4
.set qr5, 5
.set qr6, 6
.set qr7, 7

# Special Purpose Registers (SPRs)
.set XER, 1
.set LR, 8
.set CTR, 9
.set DSISR, 18
.set DAR, 19
.set DEC, 22
.set SDR1, 25
.set SRR0, 26
.set SRR1, 27
.set SPRG0, 272
.set SPRG1, 273
.set SPRG2, 274
.set SPRG3, 275
.set EAR, 282
.set PVR, 287
.set IBAT0U, 528
.set IBAT0L, 529
.set IBAT1U, 530
.set IBAT1L, 531
.set IBAT2U, 532
.set IBAT2L, 533
.set IBAT3U, 534
.set IBAT3L, 535
.set DBAT0U, 536
.set DBAT0L, 537
.set DBAT1U, 538
.set DBAT1L, 539
.set DBAT2U, 540
.set DBAT2L, 541
.set DBAT3U, 542
.set DBAT3L, 543
.set GQR0, 912
.set GQR1, 913
.set GQR2, 914
.set GQR3, 915
.set GQR4, 916
.set GQR5, 917
.set GQR6, 918
.set GQR7, 919
.set HID2, 920
.set WPAR, 921
.set DMA_U, 922
.set DMA_L, 923
.set UMMCR0, 936
.set UPMC1, 937
.set UPMC2, 938
.set USIA, 939
.set UMMCR1, 940
.set UPMC3, 941
.set UPMC4, 942
.set USDA, 943
.set MMCR0, 952
.set PMC1, 953
.set PMC2, 954
.set SIA, 955
.set MMCR1, 956
.set PMC3, 957
.set PMC4, 958
.set SDA, 959
.set HID0, 1008
.set HID1, 1009
.set IABR, 1010
.set DABR, 1013
.set L2CR, 1017
.set ICTC, 1019
.set THRM1, 1020
.set THRM2, 1021
.set THRM3, 1022

# Condition Register (CR) bits
.set cr0lt, 0
.set cr0gt, 1
.set cr0eq, 2
.set cr0un, 3
.set cr1lt, 4
.set cr1gt, 5
.set cr1eq, 6
.set cr1un, 7
.set cr2lt, 8
.set cr2gt, 9
.set cr2eq, 10
.set cr2un, 11
.set cr3lt, 12
.set cr3gt, 13
.set cr3eq, 14
.set cr3un, 15
.set cr4lt, 16
.set cr4gt, 17
.set cr4eq, 18
.set cr4un, 19
.set cr5lt, 20
.set cr5gt, 21
.set cr5eq, 22
.set cr5un, 23
.set cr6lt, 24
.set cr6gt, 25
.set cr6eq, 26
.set cr6un, 27
.set cr7lt, 28
.set cr7gt, 29
.set cr7eq, 30
.set cr7un, 31

# Defines a sized symbol with function type.
# Usage:
# .fn my_function, local
# /* asm here */
# .endfn my_function
.macro .fn name, visibility=global
.\visibility "\name"
.type "\name", @function
"\name":
.endm

.macro .endfn name
.size "\name", . - "\name"
.endm

# Defines a sized symbol with object type.
# Usage:
# .obj my_object, local
# /* data here */
# .endobj my_object
.macro .obj name, visibility=global
.\visibility "\name"
.type "\name", @object
"\name":
.endm

.macro .endobj name
.size "\name", . - "\name"
.endm

# Defines a sized symbol without a type.
# Usage:
# .sym my_sym, local
# /* anything here */
# .endsym my_sym
.macro .sym name, visibility=global
.\visibility "\name"
"\name":
.endm

.macro .endsym name
.size "\name", . - "\name"
.endm

# Generates a relative relocation against a symbol.
# Usage:
# .rel my_function, .L_label
.macro .rel name, label
.4byte "\name" + ("\label" - "\name")
.endm

# MSL C++ array construction/destruction helpers



# 0x800046B8..0x800046D0 | size: 0x18
.section extab, "a"
.balign 4

# extab:0x0 | 0x800046B8 | size: 0x18
.obj "@etb_800046B8", local
.hidden "@etb_800046B8"
/*
 * Flag values:
 * Has Elf Vector: No
 * Large Frame: Yes
 * Has Frame Pointer: No
 * Saved CR: No
 * Saved GPR range: r27-r31
 * 
 * PC actions:
 * PC=00000070, Action: 000010
 * 
 * Exception actions:
 * 000010:
 * Type: DESTROYLOCAL
 * Local: 0x8(SP)
 * Dtor: "dtor_8002F480"
 * Has end bit
 */
	.4byte 0x28080000
	.4byte 0x00000070
	.4byte 0x00000010
	.4byte 0x00000000
	.4byte 0x82000008
	.4byte dtor_8002F480
.endobj "@etb_800046B8"

# 0x80004964..0x80004970 | size: 0xC
.section extabindex, "a"
.balign 4

# extabindex:0x0 | 0x80004964 | size: 0xC
.obj "@eti_80004964", local
.hidden "@eti_80004964"
	.4byte fn_8002F37C
	.4byte 0x00000104
	.4byte "@etb_800046B8"
.endobj "@eti_80004964"

# 0x8002F37C..0x8002F480 | size: 0x104
.text
.balign 4

# .text:0x0 | 0x8002F37C | size: 0x104
.fn fn_8002F37C, global
/* 8002F37C 0002AFDC  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8002F380 0002AFE0  7C 08 02 A6 */	mflr r0
/* 8002F384 0002AFE4  2C 03 00 00 */	cmpwi r3, 0x0
/* 8002F388 0002AFE8  90 01 00 44 */	stw r0, 0x44(r1)
/* 8002F38C 0002AFEC  BF 61 00 2C */	stmw r27, 0x2c(r1)
/* 8002F390 0002AFF0  7C 7E 1B 78 */	mr r30, r3
/* 8002F394 0002AFF4  7C 9B 23 78 */	mr r27, r4
/* 8002F398 0002AFF8  7C DC 33 78 */	mr r28, r6
/* 8002F39C 0002AFFC  7C FD 3B 78 */	mr r29, r7
/* 8002F3A0 0002B000  41 82 00 C8 */	beq .L_8002F468
/* 8002F3A4 0002B004  2C 04 00 00 */	cmpwi r4, 0x0
/* 8002F3A8 0002B008  90 C3 00 00 */	stw r6, 0x0(r3)
/* 8002F3AC 0002B00C  3B C3 00 10 */	addi r30, r3, 0x10
/* 8002F3B0 0002B010  90 E3 00 04 */	stw r7, 0x4(r3)
/* 8002F3B4 0002B014  41 82 00 B4 */	beq .L_8002F468
/* 8002F3B8 0002B018  38 00 00 00 */	li r0, 0x0
/* 8002F3BC 0002B01C  93 C1 00 08 */	stw r30, 0x8(r1)
/* 8002F3C0 0002B020  7F DF F3 78 */	mr r31, r30
/* 8002F3C4 0002B024  90 C1 00 0C */	stw r6, 0xc(r1)
/* 8002F3C8 0002B028  90 E1 00 10 */	stw r7, 0x10(r1)
/* 8002F3CC 0002B02C  90 A1 00 14 */	stw r5, 0x14(r1)
/* 8002F3D0 0002B030  90 01 00 18 */	stw r0, 0x18(r1)
/* 8002F3D4 0002B034  48 00 00 28 */	b .L_8002F3FC
.L_8002F3D8:
/* 8002F3D8 0002B038  7F 6C DB 78 */	mr r12, r27
/* 8002F3DC 0002B03C  7F E3 FB 78 */	mr r3, r31
/* 8002F3E0 0002B040  38 80 00 01 */	li r4, 0x1
/* 8002F3E4 0002B044  7D 89 03 A6 */	mtctr r12
/* 8002F3E8 0002B048  4E 80 04 21 */	bctrl
/* 8002F3EC 0002B04C  80 61 00 18 */	lwz r3, 0x18(r1)
/* 8002F3F0 0002B050  7F FF E2 14 */	add r31, r31, r28
/* 8002F3F4 0002B054  38 03 00 01 */	addi r0, r3, 0x1
/* 8002F3F8 0002B058  90 01 00 18 */	stw r0, 0x18(r1)
.L_8002F3FC:
/* 8002F3FC 0002B05C  80 81 00 18 */	lwz r4, 0x18(r1)
/* 8002F400 0002B060  7C 04 E8 40 */	cmplw r4, r29
/* 8002F404 0002B064  41 80 FF D4 */	blt .L_8002F3D8
/* 8002F408 0002B068  80 01 00 10 */	lwz r0, 0x10(r1)
/* 8002F40C 0002B06C  7C 04 00 40 */	cmplw r4, r0
/* 8002F410 0002B070  40 80 00 58 */	bge .L_8002F468
/* 8002F414 0002B074  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8002F418 0002B078  2C 00 00 00 */	cmpwi r0, 0x0
/* 8002F41C 0002B07C  41 82 00 4C */	beq .L_8002F468
/* 8002F420 0002B080  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8002F424 0002B084  80 61 00 08 */	lwz r3, 0x8(r1)
/* 8002F428 0002B088  7C 00 21 D6 */	mullw r0, r0, r4
/* 8002F42C 0002B08C  7F E3 02 14 */	add r31, r3, r0
/* 8002F430 0002B090  48 00 00 2C */	b .L_8002F45C
.L_8002F434:
/* 8002F434 0002B094  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8002F438 0002B098  38 80 FF FF */	li r4, -0x1
/* 8002F43C 0002B09C  81 81 00 14 */	lwz r12, 0x14(r1)
/* 8002F440 0002B0A0  7F E0 F8 50 */	subf r31, r0, r31
/* 8002F444 0002B0A4  7F E3 FB 78 */	mr r3, r31
/* 8002F448 0002B0A8  7D 89 03 A6 */	mtctr r12
/* 8002F44C 0002B0AC  4E 80 04 21 */	bctrl
/* 8002F450 0002B0B0  80 61 00 18 */	lwz r3, 0x18(r1)
/* 8002F454 0002B0B4  38 03 FF FF */	subi r0, r3, 0x1
/* 8002F458 0002B0B8  90 01 00 18 */	stw r0, 0x18(r1)
.L_8002F45C:
/* 8002F45C 0002B0BC  80 01 00 18 */	lwz r0, 0x18(r1)
/* 8002F460 0002B0C0  2C 00 00 00 */	cmpwi r0, 0x0
/* 8002F464 0002B0C4  40 82 FF D0 */	bne .L_8002F434
.L_8002F468:
/* 8002F468 0002B0C8  7F C3 F3 78 */	mr r3, r30
/* 8002F46C 0002B0CC  BB 61 00 2C */	lmw r27, 0x2c(r1)
/* 8002F470 0002B0D0  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8002F474 0002B0D4  7C 08 03 A6 */	mtlr r0
/* 8002F478 0002B0D8  38 21 00 40 */	addi r1, r1, 0x40
/* 8002F47C 0002B0DC  4E 80 00 20 */	blr
.endfn fn_8002F37C



# 0x800046D0..0x800046D8 | size: 0x8
.section extab, "a"
.balign 4

# extab:0x0 | 0x800046D0 | size: 0x8
.obj "@etb_800046D0", local
.hidden "@etb_800046D0"
/*
 * Flag values:
 * Has Elf Vector: No
 * Large Frame: Yes
 * Has Frame Pointer: No
 * Saved CR: No
 * Saved GPR range: r29-r31
 */
	.4byte 0x18080000
	.4byte 0x00000000
.endobj "@etb_800046D0"

# 0x80004970..0x8000497C | size: 0xC
.section extabindex, "a"
.balign 4

# extabindex:0x0 | 0x80004970 | size: 0xC
.obj "@eti_80004970", local
.hidden "@eti_80004970"
	.4byte dtor_8002F480
	.4byte 0x000000BC
	.4byte "@etb_800046D0"
.endobj "@eti_80004970"

# 0x8002F480..0x8002F53C | size: 0xBC
.text
.balign 4

# .text:0x0 | 0x8002F480 | size: 0xBC
.fn dtor_8002F480, global
/* 8002F480 0002B0E0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8002F484 0002B0E4  7C 08 02 A6 */	mflr r0
/* 8002F488 0002B0E8  2C 03 00 00 */	cmpwi r3, 0x0
/* 8002F48C 0002B0EC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8002F490 0002B0F0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8002F494 0002B0F4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8002F498 0002B0F8  7C 9E 23 78 */	mr r30, r4
/* 8002F49C 0002B0FC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8002F4A0 0002B100  7C 7D 1B 78 */	mr r29, r3
/* 8002F4A4 0002B104  41 82 00 78 */	beq .L_8002F51C
/* 8002F4A8 0002B108  80 83 00 10 */	lwz r4, 0x10(r3)
/* 8002F4AC 0002B10C  80 03 00 08 */	lwz r0, 0x8(r3)
/* 8002F4B0 0002B110  7C 04 00 40 */	cmplw r4, r0
/* 8002F4B4 0002B114  40 80 00 58 */	bge .L_8002F50C
/* 8002F4B8 0002B118  80 03 00 0C */	lwz r0, 0xc(r3)
/* 8002F4BC 0002B11C  2C 00 00 00 */	cmpwi r0, 0x0
/* 8002F4C0 0002B120  41 82 00 4C */	beq .L_8002F50C
/* 8002F4C4 0002B124  80 03 00 04 */	lwz r0, 0x4(r3)
/* 8002F4C8 0002B128  80 63 00 00 */	lwz r3, 0x0(r3)
/* 8002F4CC 0002B12C  7C 00 21 D6 */	mullw r0, r0, r4
/* 8002F4D0 0002B130  7F E3 02 14 */	add r31, r3, r0
/* 8002F4D4 0002B134  48 00 00 2C */	b .L_8002F500
.L_8002F4D8:
/* 8002F4D8 0002B138  80 1D 00 04 */	lwz r0, 0x4(r29)
/* 8002F4DC 0002B13C  38 80 FF FF */	li r4, -0x1
/* 8002F4E0 0002B140  81 9D 00 0C */	lwz r12, 0xc(r29)
/* 8002F4E4 0002B144  7F E0 F8 50 */	subf r31, r0, r31
/* 8002F4E8 0002B148  7F E3 FB 78 */	mr r3, r31
/* 8002F4EC 0002B14C  7D 89 03 A6 */	mtctr r12
/* 8002F4F0 0002B150  4E 80 04 21 */	bctrl
/* 8002F4F4 0002B154  80 7D 00 10 */	lwz r3, 0x10(r29)
/* 8002F4F8 0002B158  38 03 FF FF */	subi r0, r3, 0x1
/* 8002F4FC 0002B15C  90 1D 00 10 */	stw r0, 0x10(r29)
.L_8002F500:
/* 8002F500 0002B160  80 1D 00 10 */	lwz r0, 0x10(r29)
/* 8002F504 0002B164  2C 00 00 00 */	cmpwi r0, 0x0
/* 8002F508 0002B168  40 82 FF D0 */	bne .L_8002F4D8
.L_8002F50C:
/* 8002F50C 0002B16C  2C 1E 00 00 */	cmpwi r30, 0x0
/* 8002F510 0002B170  40 81 00 0C */	ble .L_8002F51C
/* 8002F514 0002B174  7F A3 EB 78 */	mr r3, r29
/* 8002F518 0002B178  48 0F 91 51 */	bl fn_80128668
.L_8002F51C:
/* 8002F51C 0002B17C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8002F520 0002B180  7F A3 EB 78 */	mr r3, r29
/* 8002F524 0002B184  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8002F528 0002B188  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8002F52C 0002B18C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8002F530 0002B190  7C 08 03 A6 */	mtlr r0
/* 8002F534 0002B194  38 21 00 20 */	addi r1, r1, 0x20
/* 8002F538 0002B198  4E 80 00 20 */	blr
.endfn dtor_8002F480



# 0x800046D8..0x800046F0 | size: 0x18
.section extab, "a"
.balign 4

# extab:0x0 | 0x800046D8 | size: 0x18
.obj "@etb_800046D8", local
.hidden "@etb_800046D8"
/*
 * Flag values:
 * Has Elf Vector: No
 * Large Frame: Yes
 * Has Frame Pointer: No
 * Saved CR: No
 * Saved GPR range: r28-r31
 * 
 * PC actions:
 * PC=0000005C, Action: 000010
 * 
 * Exception actions:
 * 000010:
 * Type: DESTROYLOCAL
 * Local: 0x8(SP)
 * Dtor: "dtor_8002F480"
 * Has end bit
 */
	.4byte 0x20080000
	.4byte 0x0000005C
	.4byte 0x00000010
	.4byte 0x00000000
	.4byte 0x82000008
	.4byte dtor_8002F480
.endobj "@etb_800046D8"

# 0x8000497C..0x80004988 | size: 0xC
.section extabindex, "a"
.balign 4

# extabindex:0x0 | 0x8000497C | size: 0xC
.obj "@eti_8000497C", local
.hidden "@eti_8000497C"
	.4byte fn_8002F53C
	.4byte 0x000000F8
	.4byte "@etb_800046D8"
.endobj "@eti_8000497C"

# 0x8002F53C..0x8002F634 | size: 0xF8
.text
.balign 4

# .text:0x0 | 0x8002F53C | size: 0xF8
.fn fn_8002F53C, global
/* 8002F53C 0002B19C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8002F540 0002B1A0  7C 08 02 A6 */	mflr r0
/* 8002F544 0002B1A4  90 01 00 34 */	stw r0, 0x34(r1)
/* 8002F548 0002B1A8  38 00 00 00 */	li r0, 0x0
/* 8002F54C 0002B1AC  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8002F550 0002B1B0  7C 7F 1B 78 */	mr r31, r3
/* 8002F554 0002B1B4  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8002F558 0002B1B8  7C FE 3B 78 */	mr r30, r7
/* 8002F55C 0002B1BC  93 A1 00 24 */	stw r29, 0x24(r1)
/* 8002F560 0002B1C0  7C DD 33 78 */	mr r29, r6
/* 8002F564 0002B1C4  93 81 00 20 */	stw r28, 0x20(r1)
/* 8002F568 0002B1C8  7C 9C 23 78 */	mr r28, r4
/* 8002F56C 0002B1CC  90 61 00 08 */	stw r3, 0x8(r1)
/* 8002F570 0002B1D0  90 C1 00 0C */	stw r6, 0xc(r1)
/* 8002F574 0002B1D4  90 E1 00 10 */	stw r7, 0x10(r1)
/* 8002F578 0002B1D8  90 A1 00 14 */	stw r5, 0x14(r1)
/* 8002F57C 0002B1DC  90 01 00 18 */	stw r0, 0x18(r1)
/* 8002F580 0002B1E0  48 00 00 28 */	b .L_8002F5A8
.L_8002F584:
/* 8002F584 0002B1E4  7F 8C E3 78 */	mr r12, r28
/* 8002F588 0002B1E8  7F E3 FB 78 */	mr r3, r31
/* 8002F58C 0002B1EC  38 80 00 01 */	li r4, 0x1
/* 8002F590 0002B1F0  7D 89 03 A6 */	mtctr r12
/* 8002F594 0002B1F4  4E 80 04 21 */	bctrl
/* 8002F598 0002B1F8  80 61 00 18 */	lwz r3, 0x18(r1)
/* 8002F59C 0002B1FC  7F FF EA 14 */	add r31, r31, r29
/* 8002F5A0 0002B200  38 03 00 01 */	addi r0, r3, 0x1
/* 8002F5A4 0002B204  90 01 00 18 */	stw r0, 0x18(r1)
.L_8002F5A8:
/* 8002F5A8 0002B208  80 81 00 18 */	lwz r4, 0x18(r1)
/* 8002F5AC 0002B20C  7C 04 F0 40 */	cmplw r4, r30
/* 8002F5B0 0002B210  41 80 FF D4 */	blt .L_8002F584
/* 8002F5B4 0002B214  80 01 00 10 */	lwz r0, 0x10(r1)
/* 8002F5B8 0002B218  7C 04 00 40 */	cmplw r4, r0
/* 8002F5BC 0002B21C  40 80 00 58 */	bge .L_8002F614
/* 8002F5C0 0002B220  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8002F5C4 0002B224  2C 00 00 00 */	cmpwi r0, 0x0
/* 8002F5C8 0002B228  41 82 00 4C */	beq .L_8002F614
/* 8002F5CC 0002B22C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8002F5D0 0002B230  80 61 00 08 */	lwz r3, 0x8(r1)
/* 8002F5D4 0002B234  7C 00 21 D6 */	mullw r0, r0, r4
/* 8002F5D8 0002B238  7F E3 02 14 */	add r31, r3, r0
/* 8002F5DC 0002B23C  48 00 00 2C */	b .L_8002F608
.L_8002F5E0:
/* 8002F5E0 0002B240  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8002F5E4 0002B244  38 80 FF FF */	li r4, -0x1
/* 8002F5E8 0002B248  81 81 00 14 */	lwz r12, 0x14(r1)
/* 8002F5EC 0002B24C  7F E0 F8 50 */	subf r31, r0, r31
/* 8002F5F0 0002B250  7F E3 FB 78 */	mr r3, r31
/* 8002F5F4 0002B254  7D 89 03 A6 */	mtctr r12
/* 8002F5F8 0002B258  4E 80 04 21 */	bctrl
/* 8002F5FC 0002B25C  80 61 00 18 */	lwz r3, 0x18(r1)
/* 8002F600 0002B260  38 03 FF FF */	subi r0, r3, 0x1
/* 8002F604 0002B264  90 01 00 18 */	stw r0, 0x18(r1)
.L_8002F608:
/* 8002F608 0002B268  80 01 00 18 */	lwz r0, 0x18(r1)
/* 8002F60C 0002B26C  2C 00 00 00 */	cmpwi r0, 0x0
/* 8002F610 0002B270  40 82 FF D0 */	bne .L_8002F5E0
.L_8002F614:
/* 8002F614 0002B274  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8002F618 0002B278  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8002F61C 0002B27C  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8002F620 0002B280  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 8002F624 0002B284  83 81 00 20 */	lwz r28, 0x20(r1)
/* 8002F628 0002B288  7C 08 03 A6 */	mtlr r0
/* 8002F62C 0002B28C  38 21 00 30 */	addi r1, r1, 0x30
/* 8002F630 0002B290  4E 80 00 20 */	blr
.endfn fn_8002F53C



# 0x800046F0..0x800046F8 | size: 0x8
.section extab, "a"
.balign 4

# extab:0x0 | 0x800046F0 | size: 0x8
.obj "@etb_800046F0", local
.hidden "@etb_800046F0"
/*
 * Flag values:
 * Has Elf Vector: No
 * Large Frame: Yes
 * Has Frame Pointer: No
 * Saved CR: No
 * Saved GPR range: r28-r31
 */
	.4byte 0x20080000
	.4byte 0x00000000
.endobj "@etb_800046F0"

# 0x80004988..0x80004994 | size: 0xC
.section extabindex, "a"
.balign 4

# extabindex:0x0 | 0x80004988 | size: 0xC
.obj "@eti_80004988", local
.hidden "@eti_80004988"
	.4byte fn_8002F634
	.4byte 0x00000078
	.4byte "@etb_800046F0"
.endobj "@eti_80004988"

# 0x8002F634..0x8002F6AC | size: 0x78
.text
.balign 4

# .text:0x0 | 0x8002F634 | size: 0x78
.fn fn_8002F634, global
/* 8002F634 0002B294  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8002F638 0002B298  7C 08 02 A6 */	mflr r0
/* 8002F63C 0002B29C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8002F640 0002B2A0  7C 05 31 D6 */	mullw r0, r5, r6
/* 8002F644 0002B2A4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8002F648 0002B2A8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8002F64C 0002B2AC  7C DE 33 78 */	mr r30, r6
/* 8002F650 0002B2B0  7F E3 02 14 */	add r31, r3, r0
/* 8002F654 0002B2B4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8002F658 0002B2B8  7C BD 2B 78 */	mr r29, r5
/* 8002F65C 0002B2BC  93 81 00 10 */	stw r28, 0x10(r1)
/* 8002F660 0002B2C0  7C 9C 23 78 */	mr r28, r4
/* 8002F664 0002B2C4  48 00 00 20 */	b .L_8002F684
.L_8002F668:
/* 8002F668 0002B2C8  7F FD F8 50 */	subf r31, r29, r31
/* 8002F66C 0002B2CC  7F 8C E3 78 */	mr r12, r28
/* 8002F670 0002B2D0  7F E3 FB 78 */	mr r3, r31
/* 8002F674 0002B2D4  38 80 FF FF */	li r4, -0x1
/* 8002F678 0002B2D8  7D 89 03 A6 */	mtctr r12
/* 8002F67C 0002B2DC  4E 80 04 21 */	bctrl
/* 8002F680 0002B2E0  3B DE FF FF */	subi r30, r30, 0x1
.L_8002F684:
/* 8002F684 0002B2E4  2C 1E 00 00 */	cmpwi r30, 0x0
/* 8002F688 0002B2E8  40 82 FF E0 */	bne .L_8002F668
/* 8002F68C 0002B2EC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8002F690 0002B2F0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8002F694 0002B2F4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8002F698 0002B2F8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8002F69C 0002B2FC  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8002F6A0 0002B300  7C 08 03 A6 */	mtlr r0
/* 8002F6A4 0002B304  38 21 00 20 */	addi r1, r1, 0x20
/* 8002F6A8 0002B308  4E 80 00 20 */	blr
.endfn fn_8002F634



# 0x800046F8..0x80004700 | size: 0x8
.section extab, "a"
.balign 4

# extab:0x0 | 0x800046F8 | size: 0x8
.obj "@etb_800046F8", local
.hidden "@etb_800046F8"
/*
 * Flag values:
 * Has Elf Vector: No
 * Large Frame: Yes
 * Has Frame Pointer: No
 * Saved CR: No
 * Saved GPR range: r26-r31
 */
	.4byte 0x30080000
	.4byte 0x00000000
.endobj "@etb_800046F8"

# 0x80004994..0x800049A0 | size: 0xC
.section extabindex, "a"
.balign 4

# extabindex:0x0 | 0x80004994 | size: 0xC
.obj "@eti_80004994", local
.hidden "@eti_80004994"
	.4byte fn_8002F6AC
	.4byte 0x00000080
	.4byte "@etb_800046F8"
.endobj "@eti_80004994"

# 0x8002F6AC..0x8002F72C | size: 0x80
.text
.balign 4

# .text:0x0 | 0x8002F6AC | size: 0x80
.fn fn_8002F6AC, global
/* 8002F6AC 0002B30C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8002F6B0 0002B310  7C 08 02 A6 */	mflr r0
/* 8002F6B4 0002B314  2C 03 00 00 */	cmpwi r3, 0x0
/* 8002F6B8 0002B318  90 01 00 24 */	stw r0, 0x24(r1)
/* 8002F6BC 0002B31C  BF 41 00 08 */	stmw r26, 0x8(r1)
/* 8002F6C0 0002B320  7C 7A 1B 78 */	mr r26, r3
/* 8002F6C4 0002B324  7C 9B 23 78 */	mr r27, r4
/* 8002F6C8 0002B328  41 82 00 50 */	beq .L_8002F718
/* 8002F6CC 0002B32C  2C 04 00 00 */	cmpwi r4, 0x0
/* 8002F6D0 0002B330  41 82 00 40 */	beq .L_8002F710
/* 8002F6D4 0002B334  83 A3 FF F0 */	lwz r29, -0x10(r3)
/* 8002F6D8 0002B338  3B E0 00 00 */	li r31, 0x0
/* 8002F6DC 0002B33C  83 C3 FF F4 */	lwz r30, -0xc(r3)
/* 8002F6E0 0002B340  7C 1D F1 D6 */	mullw r0, r29, r30
/* 8002F6E4 0002B344  7F 83 02 14 */	add r28, r3, r0
/* 8002F6E8 0002B348  48 00 00 20 */	b .L_8002F708
.L_8002F6EC:
/* 8002F6EC 0002B34C  7F 9D E0 50 */	subf r28, r29, r28
/* 8002F6F0 0002B350  7F 6C DB 78 */	mr r12, r27
/* 8002F6F4 0002B354  7F 83 E3 78 */	mr r3, r28
/* 8002F6F8 0002B358  38 80 FF FF */	li r4, -0x1
/* 8002F6FC 0002B35C  7D 89 03 A6 */	mtctr r12
/* 8002F700 0002B360  4E 80 04 21 */	bctrl
/* 8002F704 0002B364  3B FF 00 01 */	addi r31, r31, 0x1
.L_8002F708:
/* 8002F708 0002B368  7C 1F F0 40 */	cmplw r31, r30
/* 8002F70C 0002B36C  41 80 FF E0 */	blt .L_8002F6EC
.L_8002F710:
/* 8002F710 0002B370  38 7A FF F0 */	subi r3, r26, 0x10
/* 8002F714 0002B374  48 0F 8F 5D */	bl fn_80128670
.L_8002F718:
/* 8002F718 0002B378  BB 41 00 08 */	lmw r26, 0x8(r1)
/* 8002F71C 0002B37C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8002F720 0002B380  7C 08 03 A6 */	mtlr r0
/* 8002F724 0002B384  38 21 00 20 */	addi r1, r1, 0x20
/* 8002F728 0002B388  4E 80 00 20 */	blr
.endfn fn_8002F6AC



# 0x8002F72C..0x8002F790 | size: 0x64
.text
.balign 4

# .text:0x0 | 0x8002F72C | size: 0x3C
.fn fn_8002F72C, global
/* 8002F72C 0002B38C  80 A3 00 00 */	lwz r5, 0x0(r3)
/* 8002F730 0002B390  80 C4 00 00 */	lwz r6, 0x0(r4)
/* 8002F734 0002B394  80 E3 00 04 */	lwz r7, 0x4(r3)
/* 8002F738 0002B398  81 04 00 04 */	lwz r8, 0x4(r4)
/* 8002F73C 0002B39C  81 23 00 08 */	lwz r9, 0x8(r3)
/* 8002F740 0002B3A0  81 44 00 08 */	lwz r10, 0x8(r4)
/* 8002F744 0002B3A4  38 60 00 01 */	li r3, 0x1
/* 8002F748 0002B3A8  7C 05 30 00 */	cmpw r5, r6
/* 8002F74C 0002B3AC  7F 07 40 00 */	cmpw cr6, r7, r8
/* 8002F750 0002B3B0  7F 89 50 00 */	cmpw cr7, r9, r10
/* 8002F754 0002B3B4  4C 82 00 20 */	bnelr
/* 8002F758 0002B3B8  4C 9A 00 20 */	bnelr cr6
/* 8002F75C 0002B3BC  4C 9E 00 20 */	bnelr cr7
/* 8002F760 0002B3C0  38 60 00 00 */	li r3, 0x0
/* 8002F764 0002B3C4  4E 80 00 20 */	blr
.endfn fn_8002F72C

# .text:0x3C | 0x8002F768 | size: 0x28
.fn fn_8002F768, global
/* 8002F768 0002B3C8  80 0C 00 00 */	lwz r0, 0x0(r12)
/* 8002F76C 0002B3CC  81 6C 00 04 */	lwz r11, 0x4(r12)
/* 8002F770 0002B3D0  81 8C 00 08 */	lwz r12, 0x8(r12)
/* 8002F774 0002B3D4  7C 63 02 14 */	add r3, r3, r0
/* 8002F778 0002B3D8  2C 0B 00 00 */	cmpwi r11, 0x0
/* 8002F77C 0002B3DC  41 80 00 0C */	blt .L_8002F788
/* 8002F780 0002B3E0  7D 83 60 2E */	lwzx r12, r3, r12
/* 8002F784 0002B3E4  7D 8C 58 2E */	lwzx r12, r12, r11
.L_8002F788:
/* 8002F788 0002B3E8  7D 89 03 A6 */	mtctr r12
/* 8002F78C 0002B3EC  4E 80 04 20 */	bctr
.endfn fn_8002F768
