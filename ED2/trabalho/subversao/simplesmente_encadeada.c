#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int id;
    struct no *prox;
} No;

No *cria_no()
{
    return NULL;
}

int no_vazio(No **n)
{
    return (*n == NULL);
}

void insere_relacao(No **n, int id_amigo)
{

    No *novo_no = (No *)malloc(sizeof(No));

    if (novo_no)
    {

        (*novo_no).id = id_amigo;
        (*novo_no).prox = *n;
        *n = novo_no;
    }
}

void remove_relacao(No **n, int id_amigo)
{ // remove quando tem só 1 aluno
    No *aux, *ant = NULL;
    No *var = malloc(sizeof(No)); // ERRO INESPERADO CORRIGIDO AS... 00:06AM

    if (*n)
    {
        if ((*n)->id == id_amigo)
        { // REMOVE NO INICIO
            ant = *n;
            var = ant;
            *n = ant->prox;
        }
        else
        {
            for (aux = *n; aux->prox && aux->id != id_amigo; aux = aux->prox)
            {
                ant = aux;
            }

            if (aux->prox == NULL && aux->id == id_amigo)
            { // REMOVE NO FINAL SE O ID ESTIVER NELE
                var = aux;
                ant->prox = aux->prox;
                aux->prox = NULL;
            }

            else if (aux->id == id_amigo)
            { // REMOVE DO MEIO DA LISTA
                var = aux;
                ant->prox = aux->prox;
            }
        }
        free(var);
    }
}
