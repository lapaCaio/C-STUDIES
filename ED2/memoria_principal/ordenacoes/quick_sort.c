#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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

void particionaII(int *V, int esq, int dir, int *i, int *j){
    int pivo, aux;
    *i = esq;
    *j = dir;
    pivo = V[(esq + dir)/2];

    while(*i <= *j){
        while(V[*i] < pivo && *i < dir){
            (*i)++;
        }
        while(V[*j] > pivo && *j > esq){
            (*j)--;
        }
        if(*i <= *j){  //verifica se é necessário fazer uma troca
            aux = V[*i];
            V[*i] = V[*j];
            V[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }

}

void quick_sortII(int *V, int esq, int dir){
    int i, j;
    particionaII(V, esq, dir, &i, &j);

    if(i < dir){
        quick_sortII(V, i, dir);
    }

    if(j > esq){
        quick_sortII(V, esq, j);
    }
}

int main(int argv, char** argc){
    
    int vet[MAX] = {2, 4, 1, 6, 3, 7, 5, 8, 10, 9};


    quick_sortII(vet, 0, MAX - 1);

    for(int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }

    return EXIT_SUCCESS;
}