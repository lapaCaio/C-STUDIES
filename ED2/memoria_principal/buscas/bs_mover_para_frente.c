#include <stdio.h>
#include <stdlib.h>

#define MAX 10


int bs_mover_para_frente(int *V, int n,int key){
    int aux = 1, temp;
    for(int i = 0; i < n; i++){
        if(V[i] == key){
            for(int j = i; j >= 0; j--){
                temp = V[j - 1];
                V[j - 1] = V[j];
                V[j] = temp;
            }
            return V[i];
        }
    }
    return -1;
}



int main(int argv, char** argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4,10};

    printf("\nChave encontrada! Valor: %d", bs_mover_para_frente(vet, MAX, 4));

    return EXIT_SUCCESS;
}