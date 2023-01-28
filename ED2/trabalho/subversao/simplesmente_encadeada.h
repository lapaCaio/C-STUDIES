#ifndef SE_H
#define SE_H

typedef struct no{
    int id;
    struct no* prox;
}No;

No* cria_no();

int no_vazio(No** n);

void insere_relacao(No** n, int id_amigo);

void remove_relacao(No** n, int id_amigo);

#endif //SE_H