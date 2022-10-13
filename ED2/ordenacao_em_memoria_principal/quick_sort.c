#include <stdio.h>
#include <stdlib.h>

#define MAX 9

int particiona(int vet[], int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = vet[inicio];

    while(esq < dir){
        while(vet[esq] <= pivo){  //avança a posição da esquerda
            esq++;
        }
        while(vet[dir] > pivo){  //recua a posição da direita
            dir--;
        }
        if(esq < dir){  //troca esq e dir
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }
    vet[inicio] = vet[dir];
    vet[dir] = pivo;

    return dir;
}

void quick_sort(int vet[], int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(vet, inicio, fim);
        quick_sort(vet, inicio, pivo - 1);
        quick_sort(vet, pivo + 1, fim);
    }
}

int main(int argv, char** argc){
    
    int vet[MAX] = {3,6,5,1,2,8,7,9,4};


    quick_sort(vet, 0, MAX - 1);

    for(int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }



    return EXIT_SUCCESS;
}