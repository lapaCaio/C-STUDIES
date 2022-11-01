#include <stdio.h>
#include <stdlib.h>

#define MAX 10


int busca_sequencial(int *V, int n,int key){
    for(int i = 0; i < n; i++){
        if(V[i] == key){
            return V[i];
        }
    }
    return -1;
}



int main(int argv, char** argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4,10};

    printf("\nChave encontrada! Valor: %d", busca_sequencial(vet, MAX, 4));

    return EXIT_SUCCESS;
}