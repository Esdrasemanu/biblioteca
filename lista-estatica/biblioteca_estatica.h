#ifndef blbioteca_estatica.h
#define blbioteca_estatica.h
#include "livro.h"

#define MAX_LIVROS 100

typedef struct {
    Livro livros[MAX_LIVROS];
    int qtd;
} ListaEstatica;

void iniciarLivros(ListaEstatica *lista);
int cadastrarLivros(ListaEstatica *lista, Livro livro);
Livro* consultarLivroPorISBN(ListaEstatica *lista, const char *isbn);
int emprestarLivro(ListaEstatica *lista, const char *isbn, const char *usuario, const char *data);
int devolverLivro(ListaEstatica *lista, const char *isbn);
void listarLivros(ListaEstatica *lista);

#endif