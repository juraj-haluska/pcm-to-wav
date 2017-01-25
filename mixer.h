#ifndef PCM_TO_WAV_MIXER_H
#define PCM_TO_WAV_MIXER_H

#include <inttypes.h>

#define TOP     30000
#define DIV     30000.0
void mix(uint16_t ** input, int inputs, int length, int16_t * output);

#endif //PCM_TO_WAV_MIXER_H
