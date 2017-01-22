#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wavfile.h"
#include "mixer.h"

#define SRATE       44100
#define DATA_SIZE   SRATE * 10  // 10 seconds

int main() {

    int16_t * data1 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));

    for(int i = 0; i < DATA_SIZE ; i++){
        data1[i] = 32000 * sin( (2 * M_PI * 880  * i) / SRATE);
    }

    int16_t * data2 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));

    for(int i = 0; i < DATA_SIZE ; i++){
        data2[i] = 32000 * sin( (2 * M_PI * 440  * i) / SRATE);
    }
/*
    int16_t * data3 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));

    for(int i = 0; i < DATA_SIZE ; i++){
        data3[i] = 32000 * sin( (2 * M_PI * 220  * i) / SRATE);
    }

    int16_t * data4 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));

    for(int i = 0; i < DATA_SIZE ; i++){
        data4[i] = 32000 * sin( (2 * M_PI * 1600  * i) / SRATE);
    }

    int16_t * data5 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));

    for(int i = 0; i < DATA_SIZE ; i++){
        data5[i] = 32000 * sin( (2 * M_PI * 2400  * i) / SRATE);
    }
*/
    int16_t ** map = malloc(sizeof(int16_t *) * 2);
    map[0] = data1;
    map[1] = data2;
    //map[2] = data3;
    //map[3] = data4;
    //map[4] = data5;

    int16_t * out = (int16_t *) malloc(sizeof(int16_t) * DATA_SIZE);

    mix(map, 2, DATA_SIZE, out);


    wavfile wave = wavOpen("mixed.wav", DATA_SIZE, SRATE);

    if(wave != NULL){
        wavWrite(out, DATA_SIZE, wave);
    }

    wavClose(wave);


    free(out);
    free(map);
    free(data1);
    free(data2);
    //free(data3);
    //free(data4);
    //free(data5);

    return 0;
}
