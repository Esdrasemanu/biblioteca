#ifndef livro_h
#define livro_h

typedef enum { DISPONIVEL, EMPRESTADO } Status;

typedef struct {
    char titulo[101];
    char autor[101];
    int ano;
    char isbn[14];
    Status status;
    char nome_usuario[101];
    char data_emprestimo[11]; 
} Livro;

#endif