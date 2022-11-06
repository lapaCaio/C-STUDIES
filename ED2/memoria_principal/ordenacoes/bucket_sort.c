#include <stdio.h>
#include <stdlib.h>

#define TAM 5  //tamanho do balde

void bubble_sort(int *V, int tam){

    for(int i = tam; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(V[j] > V[j + 1]){ 
                int aux = V[j];
                V[j] = V[j + 1];
                V[j + 1] = aux;
            }
        }
    }  
}

//=========================================================================================

typedef struct balde{
    int qtd;  //topo?
    int valores[TAM];
}Balde;

void bucket_sort(int *V, int tam){
    int i, j, maior, menor, nBaldes, pos;
    Balde *balde;

    //acha o maior e o menor valor
    maior = menor = V[0];
    for(i = 1; i < tam; i++){
        if(V[i] > maior){
            maior = V[i];
        }
        if(V[i] < menor){
            menor = V[i];
        }
    }

    //inicializa baldes
    nBaldes = (maior - menor) / TAM + 1;
    balde = (Balde*)malloc(nBaldes * sizeof(Balde));
    for(i = 0; i < nBaldes; i++){
        balde[i].qtd = 0;
    }

    //distribui os valores nos baldes
    for(i = 0; i < tam; i++){
        pos = (V[i] - menor)/TAM;
        balde[pos].valores[balde[pos].qtd] = V[i];
        balde[pos].qtd++;
    }

    //ordena os baldes e coloca no array
    pos = 0;
    for(i = 0; i < nBaldes; i++){
        bubble_sort(balde[i].valores, balde[i].qtd);
        for(j = 0; j < balde[i].qtd; j++){
            V[pos] = balde[i].valores[j];
            pos++;
        }
    }

    free(balde);
}


int main(int argc, char** argv){

    int vetII[50];
    int j = 50;

    for(int i = 0; i < 50; i++){
        vetII[i] = j;
        j--; 
    }

    bucket_sort(vetII, 50);

    for(int i = 0; i < 50; i++){
        printf("%d - ", vetII[i]);
    }

    printf("\n=======================================================================\n");

    for(int i = 0; i < 50; i++){
        printf("%d - ", vetII[i]);
    }

    return EXIT_SUCCESS;
}