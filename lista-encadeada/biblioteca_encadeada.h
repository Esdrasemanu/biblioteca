#ifndef BIBLIOTECA_ENCADEADA_H
#define BIBLIOTECA_ENCADEADA_H
#include "livro.h"

typedef struct No {
    Livro livro;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    int qtd;
} ListaEncadeada;

void inicializarLista(ListaEncadeada *lista);
int cadastrarLivro(ListaEncadeada *lista, Livro livro);
Livro* consultarLivroPorISBN(ListaEncadeada *lista, const char *isbn);
int emprestarLivro(ListaEncadeada *lista, const char *isbn, const char *usuario, const char *data);
int devolverLivro(ListaEncadeada *lista, const char *isbn);
void listarLivros(ListaEncadeada *lista);
void liberarLista(ListaEncadeada *lista);

#endif