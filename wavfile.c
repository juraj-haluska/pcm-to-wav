#include <stdio.h>
#include "wavfile.h"

wavfile wavOpen(char * fname, int dataSize, int srate){

    struct t_header header;
    header.chunkId = RIFF;
    header.chunkSize = sizeof(struct t_header) + sizeof(int16_t) * dataSize - BITS8;
    header.format = WAVE;
    header.subChunk1Id = FMT;
    header.subChunk1Size = LFORMAT;
    header.audioFormat = PCM;
    header.numChannels = CHANNELS;
    header.sampleRate = srate;
    header.byteRate = (srate * CHANNELS * BPS) / 8;
    header.blockAlign = BALIGN;
    header.bitsPerSample = BPS;
    header.subChunk2Id = DATA;
    header.subChunk2Size = (dataSize * CHANNELS * BPS) / 8;

    FILE * f = fopen(fname, "wb");  // on linux just w
    if(f != NULL){
        fwrite(&header, sizeof(header), 1, f);
        return f;
    } else {
        return NULL;
    }
}

void wavWrite(int16_t * data, int length, wavfile f){
    fwrite(data, sizeof(int16_t), length, f);
}

void wavClose(wavfile f){
    fclose(f);
}
