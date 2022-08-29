#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubble_sort_bettter(double *V, int n);
void frequencia_absoluta(double *V, int n);
double media_aritmetica(double *V, int n);
void mediana(double *V, int n);
void variancia(double *V, int n);

int main() {
    double *dados;
    int n, i;
    FILE *arq;
    char filename[256];

    printf("Por favor, digite o nome do arquivo de entrada: ");
    scanf("%s", filename);
    arq = fopen(filename, "r");

    fscanf(arq, "%d", &n);

    dados =  malloc(n * (sizeof(double)));

    for(i = 0; i < n; i++) {
        fscanf(arq, "%lf", &dados[i]);
    }

    frequencia_absoluta(dados, n);
    printf("Média Aritmética - %.2lf\n", media_aritmetica(dados, n));
    mediana(dados, n);
    variancia(dados, n);

    free(dados);
    fclose(arq);
    return 0;
}

void bubble_sort_bettter(double *V, int n){
  int passada, j, trocou = 1;
  double aux;

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

void frequencia_absoluta(double *V, int n) {
    int freq_abs;
    int repetiu = 0;
    int i, j;
    double freq_rel;

    bubble_sort_bettter(V, n);

    for(i = 0; i < n; i++) {
        freq_abs = 1;
        for(j = i - 1; (j >= 0)&&(!repetiu); j--) {
            if(V[i] == V[j]) repetiu = 1;
        }

        if(!repetiu) {
            for(j = i + 1; j < n; j++) {
                if(V[i] == V[j]) {
                    freq_abs++;
                }
            }
            freq_rel = (freq_abs*100)/n;
            printf("Dado - %.2lf | Freq. Absoluta - %d\n", V[i], freq_abs);
            //printf("Dado - %.2lf | Freq. Absoluta - %d | Freq. Relativa - %.1lf \n", V[i], freq_abs, freq_rel);
        
        }
        repetiu = 0;
    }
}

double media_aritmetica(double *V, int n) {
    double media = 0; int i;
    for(i = 0; i < n; i++) {
        media = media + V[i];
    }
    return (media/n);
}

void mediana(double *V, int n) {
    bubble_sort_bettter(V, n);
    if(n % 2 == 1) printf("Mediana - %.2lf\n", V[(n - 1)/2]);
    else printf("Mediana - %.2lf\n", ((V[(n - 1)/2] + V[n/2])/2));
}

void variancia(double *V, int n) {
    double var = 0;
    int i;

    for(i = 0; i < n; i++) {
        var = var + (V[i] - media_aritmetica(V, n))*(V[i] - media_aritmetica(V, n));
    }
    var = var/n;
    printf("Variância - %.2lf\n", var);
    var = sqrt(var);
    printf("Desvio Padrão - %.2lf\n", var);
}

