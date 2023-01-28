#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

/*
    CATEGORIAS:
    - homem;
    - mulher;
    - menor ou igual a 20 anos; 
    - maiores de 20 anos;
*/
/*
    COMO FAZER:
    1. cada pessoa deve inserir 5 número de 1 à 30.
    2. 
*/

//----------> ESTRUTURAS <----------//

// tipo abstrato de dados "pessoa"
typedef struct pessoa{
    char nome[255];
    int musicas[MAX];  //as 5 músicas favoritar da pessoa, pela ordem de relevância
}Pessoa;

// unidade mais simples da lista, um nó
typedef struct no{
    Pessoa p;
    struct no* proximo;
    struct no* anterior;
}No;

// descritor da lista duplamente encadeada
typedef struct descritor{
    No* inicio;
    No* final;
    int quantidade;
}Lista;


//----------> FUNÇÕES LISTA <----------//

// função que cria a lista
Lista* cria_lista(){
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li){
        li->inicio = li->final = NULL;
        li->quantidade = 0;
    }
    return li;
}

// função que libera a lista
void libera_lista(Lista* li){
    if(li){
        No* temp;
        while(li->inicio){
            temp = li->inicio;
            li->inicio = li->inicio->proximo;
            free(temp);
        }
        free(li);
    }
}

//função que retorna o tamanho da lista
int tamanho_lista(Lista* li){
    if(!li){
        return 0;
    }
    return li->quantidade;
}

int insere_lista_inicio(Lista* li, Pessoa p){
    if(!li){
        return 0;
    }

    No* nno = (No*)malloc(sizeof(No));

    if(!nno){
        return 0;
    }

    nno->p = p;
    nno->proximo = li->inicio;

    if(!li->inicio){
        li->final = nno;
    }
    li->inicio = nno;
    li->quantidade++;

    return 1;
}

int insere_lista_final(Lista* li, Pessoa p){
    if(!li){
        return 0;
    }

    No* nno = (No*)malloc(sizeof(No));

    if(!nno){
        return 0;
    }

    nno->p = p;
    nno->proximo = NULL;
    
    if(!li->inicio){
        li->inicio = nno;
    }else{
        li->final->proximo = nno;
    }
    li->final = nno;
    li->quantidade++;

    return 1;
}


//----------> FUNÇÕES GERAIS <----------//
void lb(){
    setbuf(stdin, NULL);
}

Pessoa* dados_pessoa(){
    Pessoa* np = (Pessoa*)malloc(sizeof(Pessoa));

    lb();
    printf("\n NOME: ");
    scanf("%[^\n]", np->nome);
    lb();

    int i = 0;
    while(i < MAX){
        printf("\nInforme o código da sua %d° música (de 1 a 30): ", i + 1);
        scanf("%d", np->musicas[i]);

        if(np->musicas[i] > 30 || np->musicas[i] < 1){
            printf("\nFavor inserir apenas números de 1 a 30!");
            i--;
        }

        i++;
    }

    return np;
}

int main(int argc, char** argv){

    Lista* li = cria_lista();

    int escolha;
    bool condicao = true;

    while (condicao) {
        escolha = 0;

        linha();
        printf("\n ESCOLHA A OPÇÃO DESEJADA: ");
        linha();
        printf("\n 1 - INSERIR UM NOVO ALUNO");
        printf("\n 2 - ALTERAR OS DADOS DE UM ALUNO");
        printf("\n 3 - REMOVER UM ALUNO");
        printf("\n 4 - IMPRIMIR A LISTA DE ALUNOS");
        printf("\n 5 - INSERIR RELAÇÃO DE AMIZADE");
        printf("\n 6 - REMOVER RELAÇÃO DE AMIZADE");
        printf("\n 7 - IMPRIMIR AMIGOS DE UM ALUNO");
        printf("\n 8 - IMPRIMIR A LISTA DE ALUNOS POR CURSO");
        printf("\n 9 - SAIR");
        linha();
        printf("\n >>> ");
        scanf("%d", &escolha);
        lb();

    




    return EXIT_SUCCESS;
}