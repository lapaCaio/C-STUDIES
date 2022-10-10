#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void shell_sort(int vet[], int tam){
    int j, aux;
    int h = 1;  //distância entre os elementos que serão comparados

    while(h < tam){
        h = 3 * h + 1;
    }
    
    while(h > 1){
        h /= 3;
        for(int i = h; i < tam; i++){
            aux = vet[i];
            j = i - h;
            while(j >= 0 && aux < vet[j]){
                vet[j + h] = vet[j];
                j -= h;
            }
            vet[j + h] = aux;
        }
    }
}

int main(int argv, char** argc){
    
    int vet[MAX] = {3,6,5,1,2,8,7,9,4};

    shell_sort(vet, MAX);

    for(int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }


    return EXIT_SUCCESS;
}