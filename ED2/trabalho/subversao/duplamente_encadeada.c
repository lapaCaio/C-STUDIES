#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tad.h"
#include "funcoes_auxiliares.h"
#include "simplesmente_encadeada.h"

typedef struct no No;

typedef struct aluno Aluno;

typedef struct listadealunos
{
    Aluno aluno;
    struct listadealunos *proximo;
    struct listadealunos *anterior;
} ListaDeAlunos;

ListaDeAlunos *cria_lda()
{
    return NULL;
}

int lda_vazia(ListaDeAlunos **lda)
{
    return (*lda == NULL);
}

ListaDeAlunos *buscar_elemento(ListaDeAlunos **lda, int id)
{
    ListaDeAlunos *nnl = NULL;
    ListaDeAlunos *p;

    for (p = *lda; p != NULL && p->aluno.id != id; p = p->proximo)
        ;

    if (p)
    {
        nnl = p;
    }
    return nnl;
}

void inserir_aluno(ListaDeAlunos **lda)
{

    lt();

    linha();

    printf("\n INSERIR NOVO ALUNO");

    linha();

    printf("\n");

    ListaDeAlunos *n = malloc(sizeof(ListaDeAlunos));
    ListaDeAlunos *p;

    if (n)
    {

        n->aluno = *leAluno();

        lt();

        if (*lda == NULL)
        { // INSERÇÃO EM PRIMEIRO NA LISTA

            n->proximo = n->anterior = NULL;
            *lda = n;
        }
        else if (strcmp(n->aluno.nome, (*lda)->aluno.nome) < 0)
        { // INSERÇÃO NO INÍCIO DA LISTA

            n->proximo = *lda;
            n->anterior = NULL;
            (*lda)->anterior = n;
            *lda = n;
        }
        else
        { // INSERÇÃO COM VÁRIOS VALORES EM ORDEM DECRESCENTE

            for (p = *lda; p->proximo != NULL && strcmp(n->aluno.nome, p->aluno.nome) > 0; p = p->proximo)
                ;

            if (strcmp(n->aluno.nome, p->aluno.nome) < 0)
            {

                n->proximo = p;
                n->anterior = p->anterior;
                p->anterior->proximo = n;
                p->anterior = n;
            }
            else
            {

                n->proximo = p->proximo;
                n->anterior = p;
                p->proximo = n;
            }
        }
    }
    else
    {

        printf("\nOPS! ALGO DEU ERRADO AQUI, DESCULPE-NOS PELO TRANSTORNO... T-T");
    }
}

void alterar_dados(ListaDeAlunos **lda)
{

    int id_buscado;

    lt();

    linha();

    printf("\n ALTERAR DADOS DE UM ALUNO");

    linha();

    id_buscado = 0;

    printf("\n ID DO ALUNO: ");
    scanf("%d", &id_buscado);
    lb();

    if (!lda_vazia(&(*lda)))
    {

        ListaDeAlunos *w;

        for (w = *lda; w->proximo != NULL && w->aluno.id != id_buscado; w = w->proximo)
            ;

        if (w->aluno.id == id_buscado)
        {

            lb();
            alterarNome(&w->aluno);
            lb();
            alterarCurso(&w->aluno);
            lb();
        }
        else
        {

            printf("\n ALUNO NÃO ENCONTRADO!");
        }

        ListaDeAlunos *n = malloc(sizeof(ListaDeAlunos));
        ListaDeAlunos *p;

        if (n)
        {

            n->aluno = w->aluno;

            // REMOÇÃO DA CÓPIA DO ALUNO DA LISTA

            ListaDeAlunos *z = buscar_elemento(&(*lda), id_buscado);

            if (*lda == z)
            {

                *lda = z->proximo;
            }
            else
            {

                z->anterior->proximo = z->proximo;
            }
            if (z->proximo != NULL)
            {

                z->proximo->anterior = z->anterior;
                free(z);
            }

            // INSERÇÃO DO ALUNO COM DADOS TROCADOS NO LUGAR CORRETO DA LISTA

            if (*lda == NULL)
            { // INSERÇÃO EM PRIMEIRO NA LISTA

                n->proximo = n->anterior = NULL;
                *lda = n;
            }
            else if (strcmp(n->aluno.nome, (*lda)->aluno.nome) < 0)
            { // INSERÇÃO NO INÍCIO DA LISTA

                n->proximo = *lda;
                n->anterior = NULL;
                (*lda)->anterior = n;
                *lda = n;
            }
            else
            { // INSERÇÃO COM VÁRIOS VALORES EM ORDEM DECRESCENTE

                for (p = *lda; p->proximo != NULL && strcmp(n->aluno.nome, p->aluno.nome) > 0; p = p->proximo)
                    ;

                if (strcmp(n->aluno.nome, p->aluno.nome) < 0)
                { // SE N VEM ANTES DE P

                    n->proximo = p;
                    n->anterior = p->anterior;
                    p->anterior->proximo = n;
                    p->anterior = n;
                }
                else
                {

                    n->proximo = p->proximo;
                    n->anterior = p;
                    p->proximo = n;
                }
            }
        }
        else
        {

            printf("\n ESTAMOS COM ALGUM PROBLEMA! T-T");
            printf("\n NÃO SERÁ POSSÍVEL ADICIONAR UM ALUNO!");
        }
    }
    else
    {

        lt();
        printf("\n A LISTA DE ALUNOS ESTÁ VAZIA!");
        printf("\n POR FAVOR INSIRA UM ALUNO ANTES DE TENTAR ALTERAR OS DADOS!");
    }
}

void remover_aluno(ListaDeAlunos **lda)
{

    int id_buscado;

    lt();

    linha();

    printf("\n REMOVER UM ALUNO");

    linha();

    if (!lda_vazia(&(*lda)))
    {

        id_buscado = 0;

        printf("\n ID DO ALUNO: ");
        scanf("%d", &id_buscado);
        lb();

        ListaDeAlunos *p = buscar_elemento(&(*lda), id_buscado);

        if (p)
        {

            if (*lda == p)
            { // REMOVE O PRIMEIRO ALUNO

                *lda = p->proximo;
            }
            else
            { // REMOVE ULTIMO ALUNO

                p->anterior->proximo = p->proximo;
            }

            if (p->proximo != NULL)
            { // REMOVE ALUNO NO MEIO

                p->proximo->anterior = p->anterior;
            }
        }
        else
        {

            printf("\n O ALUNO NÃO ENCONTRADO! ");
        }

        free(p);

        for (ListaDeAlunos *p = *lda; p != NULL; p = p->proximo)
        { // PERCORRE A DUPLAMENTE ENCADEADA

            if (p->aluno.prox_amg)
            {

                remove_relacao(&p->aluno.prox_amg, id_buscado);
            }
            else
            {

                printf("\n QUE TRISTE, ESSE ALUNO NÃO TEM AMIGOS... T-T");
            }
        }
    }
    else
    {

        lt();

        linha();

        printf("\n A LISTA DE ALUNOS ESTÁ VAZIA!");
        printf("\n POR FAVOR INSIRA UM ALUNO ANTES DE TENTAR REMOVÊ-LO!");
    }
}

void imprime_alunos(ListaDeAlunos **lda)
{

    lt();

    linha();

    printf("\n LISTA DE ALUNOS");

    linha();

    if (!lda_vazia(&(*lda)))
    {

        printf("\n");

        for (ListaDeAlunos *p = *lda; p != NULL; p = p->proximo)
        {

            imprimeAluno(&p->aluno);
        }

        printf("\n");
    }
    else
    {

        lt();

        linha();

        printf("\n A LISTA DE ALUNOS ESTÁ VAZIA!");
        printf("\n POR FAVOR INSIRA UM ALUNO NA LISTA ANTES DE TENTAR IMPRIMI-LA!");
    }
}

void criar_relacao(ListaDeAlunos **lda)
{

    int id_buscado, id_buscado_2;

    lt();

    linha();

    printf("\n CRIAR RELAÇÃO DE AMIZADE");

    linha();

    if (!lda_vazia(&(*lda)))
    {

        printf("\n ID DO PRIMEIRO ALUNO: ");
        scanf("%d", &id_buscado);
        lb();
        printf("\n ID DO SEGUNDO ALUNO: ");
        scanf("%d", &id_buscado_2);
        lb();

        ListaDeAlunos *busca_amigo_01 = buscar_elemento(&(*lda), id_buscado);   // FUNCIONANDO PERFEITAMENTE
        ListaDeAlunos *busca_amigo_02 = buscar_elemento(&(*lda), id_buscado_2); // FUNCIONANDO PERFEITAMENTE

        insere_relacao(&busca_amigo_01->aluno.prox_amg, id_buscado_2);
        insere_relacao(&busca_amigo_02->aluno.prox_amg, id_buscado);
    }
    else
    {

        lt();

        printf("\n A LISTA DE ALUNOS ESTÁ VAZIA!");
        printf("\n POR FAVOR INSIRA PELO MENOS DOIS ALUNO ANTES DE TENTAR CRIAR UMA RELAÇÃO DE AMIZADE!");
    }
}

void remover_relacao(ListaDeAlunos **lda)
{

    int id_buscado, id_buscado_2;

    lt();

    linha();

    printf("\n REMOVER RELAÇÃO DE AMIZADE: ");

    linha();

    if (!lda_vazia(&(*lda)))
    {

        printf("\n ID DO PRIMEIRO ALUNO: ");
        scanf("%d", &id_buscado);
        lb();
        printf("\n ID DO SEGUNDO ALUNO: ");
        scanf("%d", &id_buscado_2);
        lb();

        ListaDeAlunos *busca_amigo_01 = buscar_elemento(&(*lda), id_buscado);
        ListaDeAlunos *busca_amigo_02 = buscar_elemento(&(*lda), id_buscado_2);

        remove_relacao(&busca_amigo_01->aluno.prox_amg, id_buscado_2);
        remove_relacao(&busca_amigo_02->aluno.prox_amg, id_buscado);
    }
    else
    {

        lt();

        printf("\n A LISTA DE ALUNOS ESTÁ VAZIA!");
    }
}

void imprimir_relacao(ListaDeAlunos **lda)
{

    int id_buscado;

    lt();

    linha();

    printf("\n IMPRIMIR RELAÇÕES DE AMIZADE");

    linha();

    id_buscado = 0;

    printf("\n ID DO ALUNO: ");
    scanf("%d", &id_buscado);
    lb();

    ListaDeAlunos *elo_buscado = buscar_elemento(&(*lda), id_buscado);

    if (elo_buscado)
    {

        ListaDeAlunos *rel_amizade;

        int contador = 0;

        printf("\n AMIGOS DE %s", elo_buscado->aluno.nome);

        for (No *n = elo_buscado->aluno.prox_amg; n != NULL; n = n->prox)
        {
            if (buscar_elemento(&(*lda), n->id))
            {

                rel_amizade = buscar_elemento(&(*lda), n->id); // rel_amizade recebe tipo lda que não existe quando é removido um aluno
                ++contador;

                printf("\n %d) %s", contador, rel_amizade->aluno.nome);
            }
            else
            {
                continue;
            }
        }

        if (elo_buscado->aluno.prox_amg == NULL)
        {
            printf("\n\nO ALUNO SELECIONADO NÃO TEM AMIGOS.\n");
        }
    }
    else
    {
        printf("\n O ALUNO BUSCADO NÃO FOI ENCONTRADO!");
    }
}

void alunos_por_curso(ListaDeAlunos **lda)
{

    char curso_buscado[255];

    lt();

    linha();

    printf("\n IMPRIMIR ALUNOS POR CURSO");

    linha();

    if (!lda_vazia(&(*lda)))
    {

        printf("\n NOME DO CURSO: ");
        scanf("%[^\n]", curso_buscado);
        lb();

        char curso;

        for (ListaDeAlunos *p = *lda; p != NULL; p = p->proximo)
        {

            if (strcmp(curso_buscado, retornaCurso(&p->aluno)) == 0)
            {

                imprimeAluno(&p->aluno);
            }
        }
    }
    else
    {

        lt();

        printf("\n A LISTA DE ALUNOS ESTÁ VAZIA!");
        printf("\n POR FAVOR INSIRA PELO MENOS UM ALUNO ANTES DE TENTAR IMPRIMIR A LISTA DO CURSO!");
    }
}

// FUNÇÃO PARA MEXER NOS ARQUIVOS
void inserir_dados_arquivo(ListaDeAlunos **lda)
{

    // lt();

    printf("\n");

    FILE *arquivo_txt = fopen("entradas.txt", "r");
    rewind(arquivo_txt);

    Aluno *aluno_novo = (Aluno *)malloc(sizeof(Aluno));

    while (fscanf(arquivo_txt, "%[^\t]\t%d\t%[^\n]\n\t", aluno_novo->nome, &aluno_novo->id, aluno_novo->curso) != EOF)
    {

        atualiza_id_global(aluno_novo->id);

        aluno_novo->prox_amg = NULL;

        ListaDeAlunos *n = malloc(sizeof(ListaDeAlunos));
        ListaDeAlunos *p;

        int id_temp;

        while (fscanf(arquivo_txt, "%d ", &id_temp) == 1)
        {
            No *novo_amigo = malloc(sizeof(No));

            novo_amigo->id = id_temp;
            novo_amigo->prox = aluno_novo->prox_amg;
            aluno_novo->prox_amg = novo_amigo;
        }

        if (n)
        {

            n->aluno = *aluno_novo;

            // lt();

            if (*lda == NULL)
            { // INSERÇÃO EM PRIMEIRO NA LISTA

                n->proximo = n->anterior = NULL;
                *lda = n;
            }
            else if (strcmp(n->aluno.nome, (*lda)->aluno.nome) < 0)
            { // INSERÇÃO NO INÍCIO DA LISTA

                n->proximo = *lda;
                n->anterior = NULL;
                (*lda)->anterior = n;
                *lda = n;
            }
            else
            { // INSERÇÃO COM VÁRIOS VALORES EM ORDEM DECRESCENTE

                for (p = *lda; p->proximo != NULL && strcmp(n->aluno.nome, p->aluno.nome) > 0; p = p->proximo)
                    ;

                if (strcmp(n->aluno.nome, p->aluno.nome) < 0)
                {

                    n->proximo = p;
                    n->anterior = p->anterior;
                    p->anterior->proximo = n;
                    p->anterior = n;
                }
                else
                {

                    n->proximo = p->proximo;
                    n->anterior = p;
                    p->proximo = n;
                }
            }
        }
        else
        {

            printf("\nOPS! ALGO DEU ERRADO AQUI, DESCULPE-NOS PELO TRANSTORNO... T-T");
        }
    }

    fclose(arquivo_txt);
}

void salvar_dados_arquivo(ListaDeAlunos **lda)
{

    lt();

    linha();

    printf("\n");

    FILE *arquivo_txt = fopen("entradas.txt", "w");

    for (ListaDeAlunos *p = *lda; p != NULL; p = p->proximo)
    {

        fprintf(arquivo_txt, "%s\t%d\t%s\n\t", p->aluno.nome, p->aluno.id, p->aluno.curso);

        for (No *n = p->aluno.prox_amg; n != NULL; n = n->prox)
        {
            fprintf(arquivo_txt, "%d ", n->id);
        }

        fprintf(arquivo_txt, "\n");
    }

    fclose(arquivo_txt);
}
