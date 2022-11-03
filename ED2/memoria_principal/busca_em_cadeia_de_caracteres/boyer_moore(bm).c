#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 255

int bmh(char *T, int tsize, char *P, int psize){

    int i, j, k, table[MAXCHAR];

    for(j = 0; j < MAXCHAR; j++){
        table[j] = psize;    
    }
    for(j = 1; j < psize; j++){
        table[P[j - 1]] = psize - j; 
    }

    i = psize;

    while(i <= tsize){
        k = i;
        j = psize;

        while(T[k - 1] = P[j - 1] && j > 0){
            k--;
            j--;
        }

        if(j == 0){
            return k + 1;
        }

        i = i + table[T[i - 1]];
    }
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