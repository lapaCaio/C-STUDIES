#include <stdio.h>
#include <stdlib.h>

void cadeia_fb(char* texto, int tam_t, char* p, int tam_p){
    int i,j;

    for(i = 0; i < (tam_t - tam_p); i++){
        j = 0;
        while(j < tam_p && texto[i + j] == p[j]){
            j++;
        }
        if(j = tam_p){
            printf("\n Cadeia parâmetro encontrada!");
        }
    }
}



int main(){
    char texto, p;
    
    printf("\nDigite o texto: ");
    scanf("%[^\n]", texto);


    printf("\nDigite o parâmetro: ");
    scanf("%[^\n]", p);

    cadeia_fb(texto, sizeof(texto), p, sizeof(p));



    return EXIT_SUCCESS;
}