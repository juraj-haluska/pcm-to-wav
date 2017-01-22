#ifndef PCM_TO_WAV_MAIN_H
#define PCM_TO_WAV_MAIN_H

#include <inttypes.h>

typedef struct t_header {
    uint32_t chunkId;
    uint32_t chunkSize;
    uint32_t format;
    uint32_t subChunk1Id;
    uint32_t subChunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    uint32_t subChunk2Id;
    uint32_t subChunk2Size;
};

#define RIFF        0x46464952
#define WAVE        0x45564157
#define FMT         0x20746d66
#define LFORMAT     16
#define PCM         0x0001
#define CHANNELS    0x0001
#define SRATE       44100
#define BPS         16
#define BRATE       (SRATE * CHANNELS * BPS) / 8
#define BALIGN      (CHANNELS * BPS) / 8
#define DATA        0x61746164
#define BITS8       8

#endif //PCM_TO_WAV_MAIN_H
