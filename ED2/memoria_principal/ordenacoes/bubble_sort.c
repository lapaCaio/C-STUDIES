#include <stdio.h>
#include <stdlib.h>

#define MAX 5
//PIOR CASO: ordem inversa




void bubble_sort(int *V, int vtam){
    int aux;
    
    for(int i = vtam; i >= 1; i--){ //percorre o vetor de tras pra frente
        for(int j = 0; j < i; j++){  //percorre o vetor normalmente para realizar as trocas
            if(V[j] > V[j + 1]){  // 
                aux = V[j];
                V[j] = V[j + 1];
                V[j + 1] = aux;
            }
        }
    }
}


int main(int argv, char** argc){

    int vet[MAX] = {1,9,2,6,8};
    bubble_sort(vet, MAX - 1);

    for (int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }


    return EXIT_SUCCESS;
}