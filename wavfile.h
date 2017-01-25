/*  Primitive library for writing mono, 16 bit signed PCM
 *  data to .wav file.
 */

#ifndef PCM_TO_WAV_WAVFILE_H_H
#define PCM_TO_WAV_WAVFILE_H_H

#include <inttypes.h>

#define RIFF        0x46464952
#define WAVE        0x45564157
#define FMT         0x20746d66
#define LFORMAT     16
#define PCM         0x0001
#define CHANNELS    0x0001
#define BPS         16
#define BALIGN      (CHANNELS * BPS) / 8
#define DATA        0x61746164

#define BITS8       8

typedef struct {
    FILE * file;
    unsigned long dataLength;
    int srate;
} wavfile;

struct t_header {
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

wavfile * wavOpen(char * fname, int srate);
void wavWrite(int16_t * data, int length, wavfile * w);
void wavClose(wavfile * w);

#endif //PCM_TO_WAV_WAVFILE_H_H
