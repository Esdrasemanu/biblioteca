#ifndef biblioteca_dinamica.h
#define biblioteca_dinamica.h
#include "livro.h"

typedef struct {
    Livro *livros;
    int qtd;
    int capacidade;
} ListaDinamica;

void inicializarLista(ListaDinamica *lista);
int cadastrarLivro(ListaDinamica *lista, Livro livro);
Livro* consultarLivroPorISBN(ListaDinamica *lista, const char *isbn);
int emprestarLivro(ListaDinamica *lista, const char *isbn, const char *usuario, const char *data);
int devolverLivro(ListaDinamica *lista, const char *isbn);
void listarLivros(ListaDinamica *lista);
void liberarLista(ListaDinamica *lista);

#endif