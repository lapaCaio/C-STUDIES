#include <stdio.h>
#include <stdlib.h>


int brute_force(char* text, int size_text, char* pattern, int size_pattern){  //recebe o texto e o tamanho && o padrao e o tamanho
    for(int i = 0; i < size_text - size_pattern; i++){  //i é menor que (tamanho do texto - tamanho do padrao)?
        int j = 0;

        while(j < size_pattern && text[i + j] == pattern[j]){
            j = j + 1;

            if(j == size_pattern){  //se j tiver o tamanho do padrão
                return i;
            }
        }
    }

    return -1;
}



int main(){

    char text[11];
    char p[6];

    printf("Digite o texto que deseja armazenar (11 letras): ");
    setbuf(stdin,NULL);
    scanf("%[^\n]", text);

    setbuf(stdin,NULL);

    printf("Digite o texto que deseja buscar dentro do texto (6 letras): ");
    scanf("%[^\n]", p);
    setbuf(stdin,NULL);

    int resp = brute_force(text, 11, p, 6);

    printf("%d",resp);

    return EXIT_SUCCESS;
}