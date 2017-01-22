#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include <stdio.h>
#include "mixer.h"

void mix(uint16_t ** input, int inputs, int length, int16_t * output){
    double * sum = calloc(sizeof(double), length);

    double gain = (1.0 / inputs / 10);

    printf("gain: %f", gain);

    double max = 0;

    // summation
    for(int i = 0; i < inputs; i++){
        for(int a = 0; a < length; a++){
            sum[a] += (double) (input[i][a] * gain);
            if(sum[a] >= max) max = sum[a];
        }
    }

    printf("max: %f", max);
    // normalization
    double factor = TOP / (max*5);
    for(int i = 0; i < length; i++){
        *(output + i) = (int16_t) round(sum[i] * factor);
    }

    free(sum);
}
