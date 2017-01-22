#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

#define DATA_SIZE   44100   // 1 second

int main() {

    short * data = (short *)calloc(DATA_SIZE, sizeof(short));

    struct t_header header;
        header.chunkId = RIFF;
        header.chunkSize = sizeof(struct t_header) + sizeof(short) * DATA_SIZE - BITS8;
        header.format = WAVE;
        header.subChunk1Id = FMT;
        header.subChunk1Size = LFORMAT;
        header.audioFormat = PCM;
        header.numChannels = CHANNELS;
        header.sampleRate = SRATE;
        header.byteRate = BRATE;
        header.blockAlign = BALIGN;
        header.bitsPerSample = BPS;
        header.subChunk2Id = DATA;
        header.subChunk2Size = (DATA_SIZE * CHANNELS * BPS) / 8;


    for(int i = 0; i < DATA_SIZE ; i++){
        data[i] = 32000 * sin( (2 * M_PI * 440 * i) / (float)SRATE);
    }

    FILE * f = fopen("output.wav", "w");

    if(f != NULL){
        size_t s;

        s = fwrite(&header, sizeof(header), 1, f);
        s = fwrite(data, sizeof(short), DATA_SIZE, f);

        fflush(f);
        fclose(f);
    }

    free(data);

    return 0;
}