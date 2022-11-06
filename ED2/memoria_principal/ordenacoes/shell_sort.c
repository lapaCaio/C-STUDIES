#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

void shell_sort(int *V, int tam){
    int j, aux;
    int h = 1;  //distância entre os elementos que serão comparados

    while(h < tam){
        h = (3 * h) + 1;  //h = 13
    }
    
    while(h > 1){ 
        h /= 3; //h = 1

        for(int i = h; i < tam; i++){ //i = 3
            aux = V[i];  //aux = 1
            j = i - h;  //j = -1

            while(j >= 0 && aux < V[j]){
                V[j + h] = V[j];  
                j -= h;  
            }

            V[j + h] = aux;
        }
    }
}

int main(int argv, char** argc){
    
    int vet[MAX] = {3,6,5,1,2,8,7,9,4,10};


    int vetII[50];

    int j = 50;

    for(int i = 0; i < 50; i++){
        vetII[i] = j;
        j--; 
    }

    for(int i = 0; i < 50; i++){
        printf("%d - ", vetII[i]);
    }

    shell_sort(vetII, 50);

    printf("\n=======================================================================\n");

    for(int i = 0; i < 50; i++){
        printf("%d - ", vetII[i]);
    }


    return EXIT_SUCCESS;
}