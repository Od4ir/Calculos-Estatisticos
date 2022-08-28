#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubble_sort_bettter(double *V, int n);
void 
double media_aritmetica(double *V, int n);
int frequencia(double *V, int n);
double mediana(double *V, int n);
double moda(double *V, int n);

int main() {
    double *dados;
    int n_dados, i;

    printf("Digite o número de dados: ");
    scanf("%d", &n_dados);

    dados = malloc(n_dados * sizeof(double));

    printf("\nLeitura dos dados: ");
    for(i = 0; i < n_dados; i++) {
        scanf("%d", dados[i]);
    }

    printf("Média Aritmética: %f\n", media_aritmetica(dados, n_dados));
    printf("Mediana: %f\n", mediana(dados, n_dados));
    printf("Mediana: %f\n", moda(dados, n_dados));






}

double frequencia(double *V, n_dados, int i, int freq) {
    int j;
    int freq_abs = 0;
    double freq_rel = 0;

    for(j = i + 1; j < n_dados; j++) {
        if(V[i] == V[j]) {
            freq_abs++;
        }
    }
    freq_rel = double(freq_abs)/n_dados;

    if(freq == 1) return freq_abs;
    else return freq_rel;

}


void bubble_sort_bettter( int *V, int n){
  int passada, j, aux, trocou = 1;

  for(passada = 1; (passada < n)&&(trocou); passada++) {
        trocou = 0 ;
    
        /*Se não houve nenhuma troca, então já está ordenado,
        por isso temos a variável trocou*/
       
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
