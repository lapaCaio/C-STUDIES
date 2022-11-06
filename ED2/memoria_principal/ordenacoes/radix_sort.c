#include <stdio.h>
#include <stdlib.h>

int main(int argv, char** argc){

    int vet[MAX] = {1,9,2,6,8};
    bubble_sort(vet, MAX - 1);

    for (int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }


    return EXIT_SUCCESS;
}