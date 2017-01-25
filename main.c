#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wavfile.h"
#include "mixer.h"

#define SRATE       44100
#define DATA_SIZE   SRATE   // 10 seconds

#define NUMBA   5

int main() {

    // generate some demo waveforms
    int16_t * data[NUMBA];
    data[0] = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));
    data[1] = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));
    data[2] = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));
    data[3] = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));
    data[4] = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));

    for(int i = 0; i < DATA_SIZE ; i++){
        data[0][i] = 32000 * sin( (2 * M_PI * 880  * i) / SRATE);
        data[1][i] = 32000 * sin( (2 * M_PI * 500  * i) / SRATE);
        data[2][i] = 32000 * sin( (2 * M_PI * 1000  * i) / SRATE);
        data[3][i] = 32000 * sin( (2 * M_PI * 50  * i) / SRATE);
        data[4][i] = 32000 * sin( (2 * M_PI * 1600  * i) / SRATE);
    }

    // mix generated waveforms
    int16_t * mixed = malloc(sizeof(int16_t) * DATA_SIZE);
    mix(data, NUMBA, DATA_SIZE, mixed);

    // write it to .wav file
    wavfile * wave = wavOpen("mixed.wav", SRATE);

    if(wave != NULL){
        wavWrite(mixed, DATA_SIZE, wave);
    }

    wavClose(wave);

    free(mixed);

    free(data[0]);
    free(data[1]);
    free(data[2]);
    free(data[3]);
    free(data[4]);

    return 0;
}
