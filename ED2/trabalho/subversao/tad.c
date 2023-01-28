#include <stdio.h>
#include <stdlib.h>

#include "funcoes_auxiliares.h"

int id_global = 0;

typedef struct no
{
    int id;
    struct no *prox;
} No;

typedef struct aluno
{
    int id;
    char nome[255];
    char curso[255];
    No *prox_amg;
} Aluno;

Aluno *leAluno()
{
    Aluno *aluno_novo = (Aluno *)malloc(sizeof(Aluno));

    id_global++;
    aluno_novo->id = id_global;

    aluno_novo->prox_amg = NULL;

    lb();
    printf("\n NOME: ");
    scanf("%[^\n]", aluno_novo->nome);
    lb();
    printf(" CURSO: ");
    scanf("%[^\n]", aluno_novo->curso);
    lb();

    return aluno_novo;
}

void alterarNome(Aluno *a)
{
    printf("\n NOVO NOME: ");
    scanf("%[^\n]", a->nome);
    lb();
}

void alterarCurso(Aluno *a)
{
    printf("\n NOVO CURSO: ");
    scanf("%[^\n]", a->curso);
    lb();
}

char *retornaCurso(Aluno *a)
{
    return (a->curso);
}

void imprimeAluno(Aluno *a)
{
    printf("\n ID: %d\t NOME: %s\tCURSO: %s", a->id, a->nome, a->curso);
}

// FUNÇÃO PARA ATUALIZAR ID GLOBAL
void atualiza_id_global(int id)
{
    if (id > id_global)
    { // ATUALIZANDO O ID GLOBAL
        id_global = id;
    }
}