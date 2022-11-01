#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void shell_sort(int vet[], int tam){
    int j, aux;
    int h = 1;  //distância entre os elementos que serão comparados

    while(h < tam){
        h = 3 * h + 1; //13
    }
    
    while(h > 1){ //13 maior q 1
        h /= 3; //h = 1
        for(int i = h; i < tam; i++){ //i = 3
            aux = vet[i];  //aux = 1
            j = i - h;  //j = 2
            while(j >= 0 && aux < vet[j]){
                vet[j + h] = vet[j];  //troca de lugar
                j -= h;  //?? 0
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