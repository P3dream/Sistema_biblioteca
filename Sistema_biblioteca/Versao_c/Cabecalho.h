#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __linux__
    #define CLEAR "clear"
    #define limpar __fpurge
#elif _WIN32
    #define CLEAR "cls"
    #define limpar fflush
#endif

struct alunos{
    char nome[100];
    char matricula[100];
    int id;
    int pendencia;
    struct alunos *prox;
};

struct livros{
    char nome[100];
    char categoria[100];
    int ano_de_publi;
    int id;
    int id_aluno;
    int emprestado;
    struct livros *prox;
};

struct infra{
    int id;
    int tipo;
    int id_aluno;
    int ocupado;
    struct infra *prox;
};


#endif // CABECALHO_H_INCLUDED
