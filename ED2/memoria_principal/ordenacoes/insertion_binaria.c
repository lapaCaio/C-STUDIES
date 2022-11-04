#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void insertion_bin(int *V, int vsize){
    int aux, meio;
    
    for(int i = 1; i < vsize; i++){
        aux = V[i];

        int esq = 0;
        int dir = i;

        while(esq < dir){
            meio = (esq + dir)/2;

            if(V[meio] <= aux){
                esq = meio + 1;
            }else{
                dir = meio;
            }
        }
        for(int j = i; j > esq; j--){
            V[j] = V[j - 1];
        }
        V[dir] = aux;
    }   
}


int main(int argv, char** argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4};

    insertion_bin(vet, MAX);

    for(int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }
    

    return EXIT_SUCCESS;
}