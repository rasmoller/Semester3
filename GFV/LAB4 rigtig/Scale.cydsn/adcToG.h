#include <stdio.h>

float offset_err = 272.5;
float per_gram = 1.953; 

float correct_adc(uint16_t input)
{
    float corrected_output = (input + offset_err)/per_gram - offset_err;
    corrected_output = (corrected_output >= 0) ? corrected_output : 0;
    return (corrected_output) - 3;
}
