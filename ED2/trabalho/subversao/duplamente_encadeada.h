#ifndef DE_H
#define DE_H

typedef struct no No;

typedef struct aluno Aluno;

typedef struct listadealunos{
    Aluno aluno;
    struct listadealunos* proximo;
    struct listadealunos* anterior;
}ListaDeAlunos;

ListaDeAlunos* cria_lda();

int lda_vazia(ListaDeAlunos** lda);

void imprime_lda(ListaDeAlunos** lda);

void inserir_aluno(ListaDeAlunos** lda);

void alterar_dados(ListaDeAlunos** lda);

void remover_aluno(ListaDeAlunos** lda);

void imprime_alunos(ListaDeAlunos** lda);  //...

void criar_relacao(ListaDeAlunos** lda);  //...

void remover_relacao(ListaDeAlunos** lda);

void imprimir_relacao(ListaDeAlunos** lda);

void alunos_por_curso(ListaDeAlunos** lda);

//FUNÇÕES ABAIXO SÃO USADAS PARA COLETAR E SALVAR AS INFORMAÇÕES NO ARQUIVO

void inserir_dados_arquivo(ListaDeAlunos** lda);

void salvar_dados_arquivo(ListaDeAlunos** lda);


#endif  //DE_H