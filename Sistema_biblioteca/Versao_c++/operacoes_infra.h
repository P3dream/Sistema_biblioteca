#ifndef OPERACOES_INFRA_H_INCLUDED
#define OPERACOES_INFRA_H_INCLUDED

struct infra * busca_infra(struct infra *cab, int k);
struct infra * busca_infra2(struct infra *cab, int k, struct infra **ant);
void inserir_infra(struct infra *cab,int * num_infra);
void remover_infra(struct infra *cab,int * num_infra);
void imprimir_infra(struct infra *cab, struct alunos *q);
void emprestar_infra(struct infra *cab_infra,struct alunos *cab_alunos);
void devolver_infra(struct infra *cab_infra,struct alunos * cab_alunos);
void imprime_infra_por_tipo(struct infra *cab,struct alunos *q);
void buscar_infra_por_id(struct infra *cab, struct alunos *q);

#endif // OPERACOES_INFRA_H_INCLUDED
