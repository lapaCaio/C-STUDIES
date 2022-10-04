#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void selection_sort(int vet[], int n){
    int menor, aux;

    for(int i = 0; i < n - 1; i++){
        menor = i;
        for(int j = i + 1; j < n; j++){
            if(vet[menor] > vet[j]){
                menor = j; //posição do menor valor do vetor
            }
            if(i != menor){  //se a pos for diferente, troca 
                aux = vet[i];
                vet[i] = vet[menor];
                vet[menor] = aux;
            }
            for(int a = 0; a < n; a++){
                printf("%d, ", vet[a]);
            }
            printf("\n");
            
        }
    }
}

int main(int argv, char** argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4};


    selection_sort(vet, MAX);

    for(int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }

    return EXIT_SUCCESS;
}