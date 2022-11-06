#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 9

void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int *)malloc(tamanho * sizeof(int));

    if (temp){  //verifica se o vetor temp existe
        for (i = 0; i < tamanho; i++){  
            if (!fim1 && !fim2){
                if (V[p1] < V[p2]){
                    temp[i] = V[p1++];
                }else{
                    temp[i] = V[p2++];
                }
                if (p1 > meio){
                    fim1 = 1;
                }
                if (p2 > fim){
                    fim2 = 1;
                }
            }else{
                if (!fim1){
                    temp[i] = V[p1++];
                }else{
                    temp[i] = V[p2++];
                }
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++){  // apenas pega os dados do vetor temporário e joga no vetor principal 
            V[k] = temp[j];
        }       
    }
    free(temp);
}

void merge_sort(int *V, int inicio, int fim){
    int meio;
    if (inicio < fim){
        meio = (inicio + fim)/2;
        merge_sort(V, inicio, meio);
        merge_sort(V, meio + 1, fim);

        merge(V, inicio, meio, fim);  //apenas intercala 
    }
}

int main(int argv, char **argc)
{

    int vet[MAX] = {3, 6, 5, 1, 2, 8, 7, 9, 4};

    merge_sort(vet, 0, MAX - 1);

    for (int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }

    return EXIT_SUCCESS;
}