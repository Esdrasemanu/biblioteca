#include "biblioteca_estatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarLista(ListaEstatica *lista) {
    lista->qtd = 0;
}

int cadastrarLivro(ListaEstatica *lista, Livro livro) {
    if (lista->qtd >= MAX_LIVROS)
        return 0; //lista já etsá com o máximo de livros
    lista->livros[lista->qtd++] = livro;
    return 1;
}

Livro* consultarLivroPorISBN(ListaEstatica *lista, const char *isbn) {
    for (int i = 0; i < lista->qtd; i++) {
        if (strcmp(lista->livros[i].isbn, isbn) == 0) {
            return &lista->livros[i];
        }
    }
    return NULL;
}

int emprestarLivro(ListaEstatica *lista, const char *isbn, const char *usuario, const char *data) {
    Livro *livro = consultarLivroPorISBN(lista, isbn);
    if (livro && livro->status == DISPONIVEL) {
        livro->status == EMPRESTADO;
        strcpy(livro->nome_usuario, usuario);
        strcpy(livro->data_emprestimo, data);
        return 1;
    }
    return 0;
}

int devolverLivro(ListaEstatica *lista, const char *isbn) {
    Livro *livro = consultarLivroPorISBN(lista, isbn);
    if(livro && livro->status == EMPRESTADO) {
        livro->status == DISPONIVEL;
        livro->nome_usuario[0] = '0';
        livro->data_emprestimo[0] = '0';
        return 1;
    }
    return 0;
}

void listarLivros(ListaEstatica *lista) {
    printf("Lista de livros:\n");
    for (int i = 0; i<lista->qtd; i++) {
        Livro *l = &lista->livros[i];
        printf("Titulo: %s, Autor: %s, Ano: %d, ISBN: %s, Status:%s\n",
            l->titulo, l->autor, l->ano, l->isbn, l->status == DISPONIVEL ? "DISPONIVEL":
            "EMPRESTADO");
        if(l->status == EMPRESTADO)
        printf("Emprestado para: %s, Data de emprestimo:%s\n", l->nome_usuario, l->data_emprestimo);
    }
}