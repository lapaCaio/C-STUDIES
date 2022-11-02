#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int busca_binaria_recursiva(int *V, int inicio, int fim, int key){
    int meio = (inicio + fim)/2;

    if(inicio > fim){
        return -1;
    }else if(V[meio] == key){
        return meio;
    }else if(V[meio] > key){
        return busca_binaria_recursiva(V, inicio, meio - 1, key);
    }else{
        return busca_binaria_recursiva(V, meio + 1, fim, key);
    }

    return -1;
}

int main(char argv, int **argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4,10};

    busca_binaria_recursiva(vet, 0, MAX - 1, 6);

    return EXIT_SUCCESS;
}