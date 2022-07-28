#ifndef OPERACOES_ALUNOS_H_INCLUDED
#define OPERACOES_ALUNOS_H_INCLUDED
#include "Cabecalho.h"


void imprimir_aluno(struct alunos *cab);
void imprimir_alunos(struct alunos *cab);
struct alunos * busca_alunos(struct alunos *cab, int k);
struct alunos * busca_alunos2(struct alunos *cab, int k, struct alunos **ant);
struct alunos * busca_alunos_matricula(struct alunos * cab, char * matricula, struct alunos **ant);
void inserir_alunos(struct alunos *cab, int * k, int * num_alunos);
void apagar_alunos(struct alunos *cab);
void remover_alunos(struct alunos *cab, int * num_alunos);

#endif // OPERACOES_ALUNOS_H_INCLUDED
