#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#include "tad.h"
#include "simplesmente_encadeada.h"
#include "duplamente_encadeada.h"
#include "funcoes_auxiliares.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    //-----> VARIÁVEIS PRINCIPAIS <------//

    ListaDeAlunos *lda;
    lda = cria_lda();

    //-----> VARIÁVEIS SECUNDÁRIAS <-----//

    int escolha;
    bool condicao = true;

    int id_buscado, id_buscado_2;
    char curso_buscado[255];

    inserir_dados_arquivo(&lda);

    //-----> O RESTO DA MAIN <-----//
    while (condicao)
    {
        escolha = 0;

        linha();
        printf("\n ESCOLHA A OPÇÃO DESEJADA: ");
        linha();
        printf("\n 0 - INSERIR UM NOVO ENTREVISTADO");
        printf("\n 1 - IMPRIMIR MÚSICAS MAIS POPULARES");
        printf("\n 2 - FILTRAR");
        printf("\n 3 - IMPRIMIR A LISTA DE ALUNOS");
        printf("\n 9 - SAIR");
        linha();
        printf("\n >>> ");
        scanf("%d", &escolha);
        lb();

        switch (escolha)
        {
        case 0:

            inserir_aluno(&lda);

            break;

        case 1:

            alterar_dados(&lda);

            break;

        case 2:

            remover_aluno(&lda);

            break;

        case 3:

            imprime_alunos(&lda);

            break;

        case 4:

            lt();

            salvar_dados_arquivo(&lda);

            linha();

            condicao = false;

            break;

        default:

            lb();
            lt();
            linha();
            printf("\n O VALOR QUE VOCÊ DIGITOU NÃO CORRESPONDE A NENHUMA OPÇÃO,");
            printf("\n POR FAVOR DIGITE UM NÚMERO ENTRE 0 E 4 CORRESPONDENDE COM A OPÇÃO QUE DESEJA!");
            linha();

            continue;
        }
    }

    return EXIT_SUCCESS;
}