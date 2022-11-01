#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void counting_sort(int *V, int tam){
    int i, j, k;
    int box[MAX];

    for(i = 0; i < MAX; i++){
        box[i] = 0;
    }

    for(i = 0; i < tam; i++){
        box[V[i]]++;
    }

    for(i = 0, j = 0; j < MAX; j++){
        for(k = box[j]; k > 0; k--){
            V[i++] = j;
        }
    }
}


int main(int argv, char** argc){

    int vet[MAX] = {3,6,5,1,2,8,7,9,4,10};

    counting_sort(vet, MAX);

    for (int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }

    return EXIT_SUCCESS;
}