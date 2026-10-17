// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef signed int s32;
typedef float f32;
extern int SetPriority__Q46nw4hbm3snd6detail7AxVoiceFi(int);
extern int fn_800EC8B4(void *);
extern int fn_800EB41C(void *);
extern int Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(void *, const void *);
extern int fn_800E519C(void *);
extern void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, int);
extern void *fn_80128668(void *);
void *__dt__Q46nw4hbm3snd6detail14ChannelManagerFv(void *arg0, int arg1) {
    if (arg0 != 0) {
        if ((char *)arg0 + 0xC != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv((char *)arg0 + 0xC, 0);
        }
        if (arg0 != 0) {
            __dt__Q46nw4hbm2ut6detail12LinkListImplFv(arg0, 0);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void Start__Q46nw4hbm3snd6detail7ChannelFRCQ46nw4hbm3snd6detail8WaveDatal(void *arg0,const void *arg1,int arg2) { *(int *)((char *)arg0+0xD4)=arg2; fn_800EC8B4((char *)arg0+0x20); fn_800EB41C((char *)arg0+8); *(int *)((char *)arg0+0xAC)=0; Setup__Q46nw4hbm3snd6detail7AxVoiceFRCQ46nw4hbm3snd6detail8WaveData(*(void **)((char *)arg0+0xE0),arg1); fn_800E519C(*(void **)((char *)arg0+0xE0)); *(signed char *)((char *)arg0+0x3A)=1; }

void fn_800EA880(void *arg0, int arg1) { int a=*(int *)((char *)arg0+0xAC)+arg1; int b=*(int *)((char *)arg0+0xB0); *(int *)((char *)arg0+0xAC)=a; if(a>b) *(int *)((char *)arg0+0xAC)=b; }

void fn_800EA8A0(void *arg0, int arg1, signed char arg2, float farg0) { *(float *)((char *)arg0 + 0xA8)=farg0; *(int *)((char *)arg0 + 0xB0)=arg1; *(signed char *)((char *)arg0 + 0x3C)=arg2; *(int *)((char *)arg0 + 0xAC)=0; }
extern void *__dt__Q46nw4hbm2ut6detail12LinkListImplFv(void *, int);
extern void *fn_80128668(void *);
