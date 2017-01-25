#include <stdio.h>
#include <stdlib.h>
#include "wavfile.h"

wavfile * wavOpen(char * fname, int srate){

    wavfile * w = malloc(sizeof(wavfile));

    w->file = fopen(fname, "wb");  // on linux just w
    w->dataLength = 0;
    w->srate = srate;

    if(w->file != NULL){
        // skip header
        fseek(w->file, sizeof(struct t_header), SEEK_SET);
        return w;
    } else {
        return NULL;
    }
}

void wavWrite(int16_t * data, int length, wavfile * w){

    size_t s = fwrite(data, sizeof(int16_t), length, w->file);
    if(s == length){
        w->dataLength += length;
    }
}

void wavClose(wavfile * w){

    // begining of file
    fseek(w->file, 0, SEEK_SET);

    struct t_header header;
    header.chunkId = RIFF;
    header.chunkSize = sizeof(struct t_header) + sizeof(int16_t) * w->dataLength - BITS8;
    header.format = WAVE;
    header.subChunk1Id = FMT;
    header.subChunk1Size = LFORMAT;
    header.audioFormat = PCM;
    header.numChannels = CHANNELS;
    header.sampleRate = w->srate;
    header.byteRate = (w->srate * CHANNELS * BPS) / 8;
    header.blockAlign = BALIGN;
    header.bitsPerSample = BPS;
    header.subChunk2Id = DATA;
    header.subChunk2Size = (w->dataLength * CHANNELS * BPS) / 8;

    fwrite(&header, sizeof(header), 1, w->file);

    fclose(w->file);
    free(w);
}
