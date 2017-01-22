#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wavfile.h"

#define SRATE       44100
#define DATA_SIZE   SRATE * 10  // 10 seconds

int main() {

    int16_t * data = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));

    for(int i = 0; i < DATA_SIZE ; i++){
        data[i] = 32000 * sin( (2 * M_PI * 1120  * i) / SRATE);
    }

    wavfile wave = wavOpen("output.wav",DATA_SIZE, SRATE);

    if(wave != NULL){
        wavWrite(data, DATA_SIZE, wave);
    }

    wavClose(wave);

    free(data);

    return 0;
}
