#include "biblioteca_encadeada.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void inicializarLista(ListaEncadeada *lista) {
    lista->inicio = NULL;
    lista->qtd = 0;
}

int cadastrarLivro(ListaEncadeada *lista, Livro livro) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) return 0;
    novo->livro = livro;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->qtd++;
    return 1;
}

Livro* consultarLivroPorISBN(ListaEncadeada *lista, const char *isbn) {
    No *atual = lista->inicio;
    while (atual) {
        if (strcmp(atual->livro.isbn, isbn) == 0)
            return &atual->livro;
        atual = atual->prox;
    }
    return NULL;
}

int emprestarLivro(ListaEncadeada *lista, const char *isbn, const char *usuario, const char *data) {
    Livro *livro = consultarLivroPorISBN(lista, isbn);
    if (livro && livro->status == DISPONIVEL) {
        livro->status = EMPRESTADO;
        strncpy(livro->nome_usuario, usuario, 100);
        strncpy(livro->data_emprestimo, data, 10);
        return 1;
    }
    return 0;
}

int devolverLivro(ListaEncadeada *lista, const char *isbn) {
    Livro *livro = consultarLivroPorISBN(lista, isbn);
    if (livro && livro->status == EMPRESTADO) {
        livro->status = DISPONIVEL;
        livro->nome_usuario[0] = '\0';
        livro->data_emprestimo[0] = '\0';
        return 1;
    }
    return 0;
}

void listarLivros(ListaEncadeada *lista) {
    printf("Livros cadastrados:\n");
    No *atual = lista->inicio;
    while (atual) {
        Livro *l = &atual->livro;
        printf("Titulo: %s | Autor: %s | Ano: %d | ISBN: %s | Status: %s\n",
                l->titulo, l->autor, l->ano, l->isbn,
                l->status == DISPONIVEL ? "DISPONIVEL" : "EMPRESTADO");
        if (l->status == EMPRESTADO)
            printf("  Emprestado para: %s em %s\n", l->nome_usuario, l->data_emprestimo);
        atual = atual->prox;
    }
}

void liberarLista(ListaEncadeada *lista) {
    No *atual = lista->inicio;
    while (atual) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    lista->inicio = NULL;
    lista->qtd = 0;
}