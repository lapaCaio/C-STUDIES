#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int busca_binaria(int *V, int n,int key){
    int esquerda = 0;
    int direita = n - 1;

    while(esquerda <= direita){
        int meio = (esquerda + direita)/2;

        if(key < V[meio]){
            direita = meio - 1;
        }else if(key > V[meio]){
            esquerda = meio + 1;
        }else{
            return V[meio];
        }
    }

    return -1;
}

int main(char argv, int **argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4,10};

    busca_binaria(vet, MAX, 6);

    return EXIT_SUCCESS;
}