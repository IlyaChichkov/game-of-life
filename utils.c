#include "utils.h"

void clear_console(){
    printf("\e[1;1H\e[2J");
}

/// <summary>
/// Random int number generator [a, b)
/// </summary>
int get_rand_i(int a, int b){
    return rand() % (b - a) + a;
}

/// <summary>
/// Random float number generator [a, b]
/// </summary>
float get_rand_f(float a, float b){
    float scale = rand() / (float) RAND_MAX;
    return a + scale * ( b - a );
}