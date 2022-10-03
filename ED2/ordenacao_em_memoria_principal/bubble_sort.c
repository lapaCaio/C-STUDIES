#include <stdio.h>
#include <stdlib.h>

#define MAX 5
//PIOR CASO: ordem inversa


void bubble_sort(int vet[MAX]){  //implementação clássica
    int cont = 0;
    int cont_trocas = 1; //contar quantas trocas fez...

    while(cont_trocas != 0){
        cont_trocas = 0;

        for(int i = (MAX - 1); i >= 1; i--){
            if(vet[i - 1] >= vet[i]){

                int temp = vet[i - 1];
                vet[i - 1] = vet[i];
                vet[i] = temp; 
                cont++;
                cont_trocas++;
            }
        } 
    }
   printf("\n Número de trocas: %d", cont);
}


int main(int argv, char** argc){

    int vet[MAX] = {1,9,2,6,8};
    bubble_sort(vet);


    return EXIT_SUCCESS;
}