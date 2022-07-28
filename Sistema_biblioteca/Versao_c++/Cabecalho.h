#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h>
#include "operacoes_alunos.h"
#include "operacoes_livros.h"
#include "operacoes_infra.h"
#include "salvar_tipos.h"
#include "carregar_tipos.h"
#include "criptografia.h"

#ifdef __linux__
    #define CLEAR "clear"
#elif _WIN32
    #define CLEAR "cls"
#endif
using namespace std;

struct alunos{
    string nome;
    string matricula;
    int id;
    int pendencia;
    struct alunos *prox;
};

struct livros{
    string nome;
    string categoria;
    int ano_de_publi;
    int id;
    int id_aluno;
    bool emprestado;
    struct livros *prox;
};

struct infra{
    int id;
    int tipo;
    int id_aluno;
    bool ocupado;
    struct infra *prox;
};


#endif // CABECALHO_H_INCLUDED
