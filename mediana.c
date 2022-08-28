#include <stdio.h>

void bubble_sort_bettter(double *V, int n);
double mediana(double *V, int n);

double mediana(double *V, int n) {
    bubble_sort_bettter(V, n);
    if(n % 2 == 1) return V[(n - 1)/2];
    else return ((V[(n - 1)/2] + V[n/2])/2);
}

void bubble_sort_bettter( int *V, int n){
  int passada, j, aux, trocou = 1;

  for(passada = 1; (passada < n)&&(trocou); passada++) {
        trocou = 0 ;
        for(j=0; j < n - passada; j++) {                                         
            if(V[j] > V[j+1]) {
                aux = V[j+1] ;
                V[j+1] = V[j] ;
                V[j] = aux ;
                trocou = 1 ;
            }
        }
    } 
}
