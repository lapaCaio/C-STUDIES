#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void insertion_sort(int vet[], int n){
    int j, aux;

    for(int i = 0; i < n; i++){
        aux = vet[i];
        for(j = i; (j > 0) && (aux < vet[j - 1]); j--){
            vet[j] = vet[j - 1];
        }
        vet[j] = aux;
    }
}


int main(int argv, char** argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4};

    insertion_sort(vet, MAX);

    for(int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }

    return EXIT_SUCCESS;
}