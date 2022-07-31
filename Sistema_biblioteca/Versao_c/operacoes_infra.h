#ifndef OPERACOES_INFRA_H_INCLUDED
#define OPERACOES_INFRA_H_INCLUDED
#include "Cabecalho.h"


struct infra * busca_infra(struct infra *cab, int id);//Nessa funcao, buscamos por um id para verificar se ele esta cadastrado, retornamos um ponteiro para o no, caso seja encontrado, ou para nulo, caso contrario.
//Passamos o endereco do no cabeca de infra para poder fazer buscas nas infraestruturas registradas, e o id buscado.

struct infra * busca_infra2(struct infra *cab, int id, struct infra **ant);//Funcao que se assimila ao busca_infra, entretanto, passamos tambem um ponteiro para o no anterior, usada quando uma remocao ou insercao for utilizada.
//Passamos o endereco do no cabeca de infra para para poder fazer buscas nas infraestruturas registradas, o id buscado, e o um ponteiro para o no anterior.

void inserir_infra(struct infra *cab,int * num_infra);//Nessa funcao, inserimos um novo no na nossa lista encadeada de infraestruturas.
//Passamos o endereco do no cabeca de infra para chegarmos ao ultimo no, e adicionar um novo, em sequencia. Num_infra, que e o numero de infraestruturas cadastradas e passado pois sera atualizado.

void remover_infra(struct infra *cab,int * num_infra);//Nessa funcao, removemos um no especifico, caso o id do aluno que o usuario deseja remover seja encontrado.
//Passamos o endereco do no cabeca de infra para chegarmos ate o no que possui o id buscado. O numero de estruturas cadastradas e atualizado.

void imprimir_infra(struct infra *cab, struct alunos *q);//Nessa funcao, e imprimido na tela a estrutura buscada pelo usuario, caso o id dela seja encontrado, mostrando, tambem, a matricula do aluno que esta utilizando-a, caso esteja ocupada.
//Passamos o endereco do no cabeca de infra para chegarmos ate o no que possui o id buscado. Tambem passamos o endereco do no cabeca de alunos para verificar a matricula do aluno que esta utilizando-a, caso esteja emprestada.

void emprestar_infra(struct infra *cab_infra,struct alunos *cab_alunos);//Nessa funcao, um uma infraestura e emprestada a um aluno, aumentando em um o numero de pendencias de um aluno, e indicando que a infraestrutura esta emprestada, tambem salva o id do aluno que pediu o emprestimo.
//Passamos o endereco do no cabeca de infra para fazermos buscas e o endereco do no cabeca de alunos para realizar o emprestimo, caso possivel.

void devolver_infra(struct infra *cab_infra,struct alunos * cab_alunos);//Nessa funcao, uma infraestrutura e emprestada a um aluno, aumentando em um o numero de pendencias de um aluno, e indicando que a infraestrutura esta emprestada, tambem salva o id do aluno que pediu o emprestimo.
//Passamos o endereco do no cabeca de infra para buscarmos o livro que o aluno deseja devolver, e o endereco do no cabeca de alunos, para fazer buscas e alteracoes no no associado ao id do aluno que deseja fazer a devolucao, caso seja possivel.

void imprime_infra_por_tipo(struct infra *cab,struct alunos *q);//Nessa funcao, e possivel printar todas as infraestruturas registradas no sistema por tipo.
//Passamos o endereco do no cabeca de infra para buscarmos pelo tipo buscado pelo usuario e imprimir na tela. Tambem e passado o endereco do no cabeca de alunos para indicar a matricula do aluno que as esta utilizando, caso estejam ocupadas.

void buscar_infra_por_id(struct infra *cab, struct alunos *q);//Nessa funcao, e possivel buscar uma infraestrutura especifica por id.
//Passamos o endereco do no cabeca de infra para buscarmos pelo tipo buscado pelo usuario e imprimir na tela, caso seja encontrado. Sao impressas todas as informacoes associadas a essa infraestrutura.

#endif // OPERACOES_INFRA_H_INCLUDED
