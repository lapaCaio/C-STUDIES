#include <stdio.h>
#include <stdlib.h>

int preprocessamento(char *P, int psize){
    int k = -1;
    int i = 1;
    int *aux = malloc(sizeof(int)*psize);
    
    if(!aux){
        return NULL;
    }
    
    aux[0] = k;
    for(i = 1; i < psize; i++){
        while(k > -1 && P[k + 1] != P[i]){
            k = aux[k];
        }
        if(P[i] == P[k + 1]){
            k++;
        }
        aux[i] = k;
    }
    return aux;
}

int kmp(char *text, int tsize, char *P, int psize){
    int i;
    int *aux = preprocessamento(P, psize);
    int k = -1;

    if(!aux){
        return -1;
    }
    for(i = 0; i < tsize; i++){
        while(k > -1 && P[k + 1] != text[i]){
            k = aux[k];
        }
        if(text[i] == P[k + 1]){
            k++;
        }
        if(k == psize - 1){
            free(aux);
            return i - k;
        }
    }

    free(aux);
    return -1;
}


int main(int argv, char** argc){

    char text[9];
    char p[4];

    printf("Digite o texto que deseja armazenar (9 letras): ");
    setbuf(stdin,NULL);
    scanf("%[^\n]", text);

    setbuf(stdin,NULL);

    printf("Digite o texto que deseja buscar dentro do texto (4 letras): ");
    scanf("%[^\n]", p);
    setbuf(stdin,NULL);

    int resp = kmp(text, 9, p, 4);

    printf("%d",resp);

    return EXIT_SUCCESS;
}