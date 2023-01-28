#ifndef TAD_H
#define TAD_H

typedef struct no No; 

typedef struct aluno{
    int id;
    char nome[255];
    char curso[255];
    No* prox_amg;  
}Aluno;

Aluno* leAluno();

void alterarNome(Aluno* a);

void alterarCurso(Aluno* a);

char* retornaCurso(Aluno* a);

void imprimeAluno(Aluno* a);

void atualiza_id_global(int id);

#endif // TAD_H