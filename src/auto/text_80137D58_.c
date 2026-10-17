// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80137F2C(void) {

}

void fn_80138434(void) {
    fn_80137F2C();
}

extern float lbl_805613A4;
int fn_801388F4(void *arg0) { float spC,sp8,temp_f2,temp_f4; double temp_f3; void *p; p=*(void **)((char*)arg0+0x14); sp8=*(float*)((char*)arg0+8); spC=*(float*)((char*)arg0+0xC); temp_f3=-sp8; temp_f4=(float)temp_f3; temp_f2=spC**(float*)((char*)p+8); sp8=spC; spC=(float)temp_f3; if(temp_f2+temp_f4**(float*)((char*)p+0xC)<lbl_805613A4)return 1;return 0; }

void fn_80138958(void *arg0, float *arg1) { fn_801386D0(arg1[0], arg1[1], arg1[2]); }

void fn_80138AD8(void **arg0) { void *p=*arg0; fn_8013C428(*(int*)((char*)p+0x28),p); fn_8012C4D8(*arg0); *arg0=0; }

void *fn_80138B1C(void *arg0) { void *p=*(void **)((char*)arg0+0x24); void *result=0; while(p){ if(*(int*)p==0){result=p;break;} p=*(void **)((char*)p+4); } return result; }

