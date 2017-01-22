//
// Created by halus on 22-Jan-17.
//

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

#endif //PCM_TO_WAV_MAIN_H
