#include "biblioteca_dinamica.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void inicializarLista(ListaDinamica *lista) {
    lista->capacidade = 10;
    lista->qtd = 0;
    lista->livros = (Livro*)malloc(lista->capacidade * sizeof(Livro));
}

int cadastrarLivro(ListaDinamica *lista, Livro livro) {
    if (lista->qtd >= lista->capacidade) {
        lista->capacidade *= 2;
        lista->livros = (Livro*)realloc(lista->livros, lista->capacidade * sizeof(Livro));
        if (!lista->livros) return 0;
    }
    lista->livros[lista->qtd++] = livro;
    return 1;
}

Livro* consultarLivroPorISBN(ListaDinamica *lista, const char *isbn) {
    for (int i = 0; i < lista->qtd; i++) {
        if (strcmp(lista->livros[i].isbn, isbn) == 0) {
            return &lista->livros[i];
        }
    }
    return NULL;
}

int emprestarLivro(ListaDinamica *lista, const char *isbn, const char *usuario, const char *data) {
    Livro *livro = consultarLivroPorISBN(lista, isbn);
    if (livro && livro->status == DISPONIVEL) {
        livro->status = EMPRESTADO;
        strncpy(livro->nome_usuario, usuario, 100);
        strncpy(livro->data_emprestimo, data, 10);
        return 1;
    }
    return 0;
}

int devolverLivro(ListaDinamica *lista, const char *isbn) {
    Livro *livro = consultarLivroPorISBN(lista, isbn);
    if (livro && livro->status == EMPRESTADO) {
        livro->status = DISPONIVEL;
        livro->nome_usuario[0] = '\0';
        livro->data_emprestimo[0] = '\0';
        return 1;
    }
    return 0;
}

void listarLivros(ListaDinamica *lista) {
    printf("Livros cadastrados:\n");
    for (int i = 0; i < lista->qtd; i++) {
        Livro *l = &lista->livros[i];
        printf("Titulo: %s | Autor: %s | Ano: %d | ISBN: %s | Status: %s\n",
                l->titulo, l->autor, l->ano, l->isbn,
                l->status == DISPONIVEL ? "DISPONIVEL" : "EMPRESTADO");
        if (l->status == EMPRESTADO)
            printf("  Emprestado para: %s em %s\n", l->nome_usuario, l->data_emprestimo);
    }
}

void liberarLista(ListaDinamica *lista) {
    if (lista->livros)
        free(lista->livros);
    lista->livros = NULL;
    lista->qtd = lista->capacidade = 0;
}