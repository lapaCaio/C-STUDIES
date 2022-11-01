#include <stdio.h>
#include <stdlib.h>

#define MAX 10


int bs_mover_para_frente(int *V, int n,int key){
    int aux = 1, temp;
    for(int i = 0; i < n; i++){
        if(V[i] == key){
            temp = V[i - 1];
            V[i - 1] = V[i];
            V[i] = temp;
            return V[i];
        }
    }
    return -1;
}



int main(int argv, char** argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4,10};

    for (int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }

    printf("\n");
    
    bs_mover_para_frente(vet, MAX, 9);

    for (int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }


    return EXIT_SUCCESS;
}