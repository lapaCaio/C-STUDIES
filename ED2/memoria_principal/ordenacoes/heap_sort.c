#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void cria_heap(int *V, int i, int f){
    int aux = V[i];
    int j = i * 2 + 1; 

    while(j <= f){ 
        if(j < f){  //pai tem dois filhos?
            if(V[j] < V[j + 1]){  //quem é o maior?
                j = j + 1;
            }
        }
        if(aux < V[j]){  //filho maior que o pai? filho se torna o pai! repetir o processo...
            V[i] = V[j];
            i = j;
            j = (2 * i) + 1;
        }else{
            j = f + 1;
        }
    }
    V[i] = aux;  //antigo pai ocupa o lugar do último filho analisado
}

void heap_sort(int *V, int tam){
    int i, aux;

    for(i = (tam - 1)/2; i >= 0; i--){  //cria heap a partir dos dados
        cria_heap(V, i, tam - 1); 
    }

    for(i = tam - 1; i >= 1; i--){
        aux = V[0];  //pega o maior elemento da heap e colocar na sua posição correspondente  no array
        V[0] = V[i];
        V[i] = aux;
        cria_heap(V, 0, i - 1);  //reconstruir heap
    }
}

int main(int argv, char** argc){
    
    int vet[MAX] = {3,6,5,1,2,8,7,9,4};


    heap_sort(vet, MAX);

    for(int i = 0; i < MAX; i++){
        printf("%d - ", vet[i]);
    }

    return EXIT_SUCCESS;
}