#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int busca_binaria(int *V, int n,int key){
    int inicio = 0;
    int fim = n - 1;

    while(inicio <= fim){
        int meio = (inicio + fim)/2;

        if(key < V[meio]){
            fim = meio - 1;
        }else if(key > V[meio]){
            inicio = meio + 1;
        }else{
            return V[meio];
        }
    }

    return -1;
}

int busca_binaria_recursiva(int *V, int i, int f, int key){
    int inicio = i;
    int fim = f;

    if(inicio <= fim){
        int meio = (inicio + fim)/2;

        if(key < V[meio]){
            return busca_binaria_recursiva(V, inicio, meio - 1, key);
        }else if(key > V[meio]){
            return busca_binaria_recursiva(V, meio + 1, fim, key);
        }else{
            return V[meio];
        }
    }

    return -1;
}

int main(char argv, int **argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4,10};

    busca_binaria(vet, MAX, 6);

    busca_binaria_recursiva(vet, 0, MAX - 1, 6);

    return EXIT_SUCCESS;
}