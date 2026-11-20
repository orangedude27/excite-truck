#ifndef NW4HBM_SND_WAVEPLAYER_TYPES_H
#define NW4HBM_SND_WAVEPLAYER_TYPES_H
namespace nw4hbm {
namespace snd {
struct WavePacket {
    u32 unk0;
    u32 unk4;
    const void *channelData[2];
    u32 sampleBytes;
    u8 valid;
    u8 pad15[3];
    void *listLink[2];
};

enum WavePlayerCallbackStage {
    WAVE_CALLBACK_PACKET_PLAYED = 0,
    WAVE_CALLBACK_PACKET_DROPPED = 1
};

class WavePlayer {
public:
    struct PacketList {
        u32 count;
        void *head;
        void *tail;
    };
    void *vtable;
    PacketList packets;
    u32 voiceCount;
    u32 unk14;
    void *voice;
    u8 inPlayerList;
    u8 playing;
    u8 loopSet;
    u8 paused;
    s32 format;
    u32 sampleRate;
    s64 samplesPlayed;
    u8 pad30[0x5C];
    void (*callback)(s32 stage, WavePlayer *player, WavePacket *packet, u32 arg);
    u32 callbackArg;
    void *playerLink[2];
    void Stop();
    void UpdateWavePacket();
};
}  // namespace snd
}  // namespace nw4hbm
#endif
