#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>

#ifdef __linux__ // se o sistema operacional for linux
    #define CLEAR "clear"
    #define limpar __fpurge
#elif _WIN32 // se o sistema operacional foi windows
    #define CLEAR "cls"
    #define limpar fflush
#endif

struct alunos{
    char nome[100];  // nome do aluno
    char matricula[100]; // matricula do aluno
    int id; // id do aluno
    int pendencia; // numero de pendencias do aluno com a biblioteca, inicialmente = 0.
    struct alunos *prox; // ponteiro para o proximo no
};

struct livros{
    char nome[100]; // nome do livro
    char categoria[100]; // categoria do livro
    int ano_de_publi; // ano de publicacao do livro
    int id; // id do livro
    int id_aluno;// id do aluno que pediu emprestimo.
    int emprestado; // 0 = nao emprestado, 1 = emprestado
    struct livros *prox; // ponteiro para o proximo no
};

struct infra{
    int id; // id da infraestrutura
    int tipo; // 1 = computador, 2 = sala, 3 = armario.
    int id_aluno; // id do aluno que pediu emprestimo.
    int ocupado; // 0 = livre, 1 = ocupado
    struct infra *prox; // ponteiro para o proximo no
};


#endif // CABECALHO_H_INCLUDED
