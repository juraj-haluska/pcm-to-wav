#include <stdlib.h>
#include <inttypes.h>
#include "mixer.h"

void mix(uint16_t ** input, int inputs, int length, int16_t * output){

    double * sum = calloc(sizeof(double), length);

    float max_val = 0;
    float min_val = 0;

    for(int a = 0; a < inputs; a++) {
        for (int i = 0; i < length; i++) {
            sum[i] += (float) input[a][i] / DIV;
            if(sum[i] >= max_val) max_val = sum[i];
            if(sum[i] <= min_val) min_val = sum[i];
        }
    }

    // normalize
    int factor = 0;
    if((abs(max_val) >= abs(min_val))) {
        if(max_val != 0) factor = TOP / max_val;
    } else {
        if(min_val != 0) factor = TOP / abs(min_val);
    }
    for(int i = 0; i < length; i++){
        output[i] = (int)(sum[i] * factor);
    }

    free(sum);
}
