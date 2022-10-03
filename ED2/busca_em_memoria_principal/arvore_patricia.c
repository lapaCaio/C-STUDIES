#include <stdio.h>
#include <stdlib.h>

#define MAX 8;

// tipo_no = 0 -> FOLHA
//tipo_no = 1 -> INTERMEDIÁRIO (TRATAR PRIMEIRO);

typedef struct no_pat{
    int tipo_no;
    int pos;
    char info[MAX];
    struct no_pat *esq;
    struct no_pat *dir;
}NoPat;

NoPat* criar_vazia(){
    return NULL;
}

int esta_vazia(NoPat* np){
    return (np == NULL);
}

NoPat* insere(NoPat* np, char c[MAX]){
    if(esta_vazia(np)){  //se arvore esta vazia
        np = (NoPat*)malloc(sizeof(NoPat));
        np->esq = np->dir = NULL;
        *(np->info) = c;
        np->tipo_no = 0;
        np->pos = MAX;
    }else{  //FAZER FUNÇÃO DE BUSCA 
        for(int i = 0; i < MAX; i++){
            if(){

            }
        }
    }
}

NoPat* busca(NoPat* np, char c[MAX]){
    if(esta_vazia(np)){
        return NULL;
    }else{
        if(np->tipo_no != 0){
            busca(np->esq, c);
            busca(np->dir, c);
        }else{
            //criar um nó
        }
    }
}

//REMOÇÃO ÁRVORE PATRÍCIA
void remove_pat(NoPat** p, char c[MAX]){
    int altera;
    if(*p != NULL){
        altera = remove_pat2(p, chave);
        if(altera){
            *p = NULL;
        }  
    }
} //código provavlemente inútil... sla...

int remove_pat2(NoPat** p, char[MAX]){
    NoPat* temp;
    int altera;

    if((*p)->tipo_no == 0){
            if(strcmp((*p)->c, c) == 0){
            free(*p);
            return 1;
        }else{
            return 0;
        }
    }else{
        if(c[(*p)->pos] == 0){
            altera = remove_pat2(&((*p)->esq), c);

            if(altera){
                temp = *p;
                *p = temp->dir;
                free(temp);
            }
        }else{
            altera = remove_pat2(&((*p)->dir), c);
            if(altera){
                temp = *p;
                *p = (*p)->esq;
                free(temp);
                return 0;
            }
        }
        
    }
    
}

/*
POSSIBILIDADES DE INSERÇÃO:
1. ARVORE VAZIA
2. NÓ INTERMEDIÁRIO... comparar os bits e posicionar no local certo. ARVORE CHEIA E INSERÇÃO EM UMA POSIÇÃO NO MEIO DA ARVORE.(NÓ INTERMEDIÁRIO);
*/


int main(int argv, char** argc){





    return EXIT_SUCCESS;
}