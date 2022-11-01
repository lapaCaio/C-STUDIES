#include <stdio.h>
#include <stdlib.h>

#define MAX 10


int busca_sequencial_sentinela(int *V, int n,int key){
    int i;

    V[n] = key;

    for(i = 0; V[i] != key; i++);

    if(i < n){
        return V[i];
    }else{
        return -1;
    }
}



int main(int argv, char** argc){

    int vet[MAX + 1] = {3,6,5,1,2,8,7,9,4,10};

    printf("\nChave encontrada! Valor: %d", busca_sequencial_sentinela(vet, MAX, 4));

    return EXIT_SUCCESS;
}