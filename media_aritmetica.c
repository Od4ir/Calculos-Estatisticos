#include <stdio.h>

double media_aritmetica(double *V, int n) {
    double media = 0; int i;
    for(i = 0; i < n; i++) {
        media = media + V[i];
    }
    return (media/n);
}
