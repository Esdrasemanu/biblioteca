#include <stdio.h>
#include <string.h>
#include "livro.h"
#include "biblioteca_encadeada.c"

void menu() {
    printf("\n==== Biblioteca - Lista Encadeada ====\n");
    printf("1. Cadastrar livro\n");
    printf("2. Consultar livro por ISBN\n");
    printf("3. Emprestar livro\n");
    printf("4. Devolver livro\n");
    printf("5. Listar todos os livros\n");
    printf("0. Sair\n");
    printf("Escolha: ");
}

void lerString(char *dest, int tam) {
    fgets(dest, tam, stdin);
    dest[strcspn(dest, "\n")] = '\0';
}

int main() {
    ListaEncadeada lista;
    inicializarLista(&lista);

    int op;
    do {
        menu();
        scanf("%d%*c", &op);
        if (op == 1) {
            Livro livro;
            printf("Titulo: "); lerString(livro.titulo, 101);
            printf("Autor: "); lerString(livro.autor, 101);
            printf("Ano de publicacao: "); scanf("%d%*c", &livro.ano);
            printf("ISBN: "); lerString(livro.isbn, 14);
            livro.status = DISPONIVEL;
            livro.nome_usuario[0] = '\0';
            livro.data_emprestimo[0] = '\0';
            if (cadastrarLivro(&lista, livro))
                printf("Livro cadastrado!\n");
            else
                printf("Erro ao cadastrar livro!\n");
        } else if (op == 2) {
            char isbn[14];
            printf("ISBN: "); lerString(isbn, 14);
            Livro *livro = consultarLivroPorISBN(&lista, isbn);
            if (livro) {
                printf("Titulo: %s\nAutor: %s\nAno: %d\nStatus: %s\n", livro->titulo, livro->autor, livro->ano, livro->status == DISPONIVEL ? "DISPONIVEL" : "EMPRESTADO");
                if (livro->status == EMPRESTADO)
                    printf("Emprestado para: %s em %s\n", livro->nome_usuario, livro->data_emprestimo);
            } else {
                printf("Livro nao encontrado!\n");
            }
        } else if (op == 3) {
            char isbn[14], usuario[101], data[11];
            printf("ISBN: "); lerString(isbn, 14);
            printf("Nome do usuario: "); lerString(usuario, 101);
            printf("Data do emprestimo (DD/MM/AAAA): "); lerString(data, 11);
            if (emprestarLivro(&lista, isbn, usuario, data))
                printf("Livro emprestado!\n");
            else
                printf("Livro nao encontrado ou ja esta emprestado!\n");
        } else if (op == 4) {
            char isbn[14];
            printf("ISBN: "); lerString(isbn, 14);
            if (devolverLivro(&lista, isbn))
                printf("Livro devolvido!\n");
            else
                printf("Livro nao encontrado ou nao esta emprestado!\n");
        } else if (op == 5) {
            listarLivros(&lista);
        }
    } while (op != 0);

    liberarLista(&lista);
    printf("Saindo...\n");
    return 0;
}