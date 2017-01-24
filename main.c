#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wavfile.h"
#include "mixer.h"

#define SRATE       44100
#define DATA_SIZE   SRATE * 10 // 10 seconds

int main() {

    int16_t * data1 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));
    int16_t * data2 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));
    int16_t * data3 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));
    int16_t * data4 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));
    int16_t * data5 = (int16_t *) malloc(DATA_SIZE * sizeof(int16_t));

    for(int i = 0; i < DATA_SIZE ; i++){
        data1[i] = 32000 * sin( (2 * M_PI * 880  * i) / SRATE);
        data2[i] = 32000 * sin( (2 * M_PI * 500  * i) / SRATE);
        data3[i] = 32000 * sin( (2 * M_PI * 1000  * i) / SRATE);
        data4[i] = 32000 * sin( (2 * M_PI * 50  * i) / SRATE);
        data5[i] = 32000 * sin( (2 * M_PI * 1600  * i) / SRATE);
    }


    double * sum = calloc(sizeof(double), DATA_SIZE);
    int16_t * out = (int16_t *) malloc(sizeof(int16_t) * DATA_SIZE);

    for(int i = 0; i < DATA_SIZE; i++){
        sum[i] = (float)data1[i] / 30000.0;
        //printf("i:%d/%f\n", i, sum[i]);
    }
    for(int i = 0; i < DATA_SIZE; i++){
        sum[i] += (float)data2[i] / 30000.0;
        //printf("i:%d/%f\n", i, sum[i]);
    }
    for(int i = 0; i < DATA_SIZE; i++){
        sum[i] += (float)data3[i] / 30000.0;
        //printf("i:%d/%f\n", i, sum[i]);
    }
    for(int i = 0; i < DATA_SIZE; i++){
        sum[i] += (float)data4[i] / 30000.0;
        //printf("i:%d/%f\n", i, sum[i]);
    }
    for(int i = 0; i < DATA_SIZE; i++){
        sum[i] += (float)data5[i] / 30000.0;
        //printf("i:%d/%f\n", i, sum[i]);
    }

    for(int i = 0; i < DATA_SIZE; i++){
        out[i] = (int)(sum[i] * 5000);
    }

    wavfile wave = wavOpen("mixed.wav", DATA_SIZE, SRATE);

    if(wave != NULL){
        wavWrite(out, DATA_SIZE, wave);
    }

    wavClose(wave);

    free(sum);
    free(out);
    free(data1);
    free(data2);

    return 0;
}
