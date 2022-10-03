#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    int p,l,c;
    struct nolista *prox;
}NoLista;

typedef struct notrie{
    struct nolista* ocorrencia;
    struct nolista* valor[256];
}NoTrie;

void cria_arvore_trie(NoTrie** t){
    *t = NULL;
}

int main(){




    return EXIT_SUCCESS;
}