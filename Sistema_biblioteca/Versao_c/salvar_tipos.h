#ifndef SALVAR_TIPOS_H_INCLUDED
#define SALVAR_TIPOS_H_INCLUDED
#include "Cabecalho.h"

void salvar_alunos(struct alunos *cab,int * num_alunos, int * id_alunos);//Funcao utilizada para salvar os dados lidos na execucao do programa, no arquivo "alunos.txt".
//Passamos o endereco de cabeca de alunos para poder listar todos os alunos, o numero de alunos para salvar quantos alunos estao cadastrados no momento, e o id_alunos para gerar id automatico para novos alunos.
void salvar_livros(struct livros *cab, int * num_livros, int * id_livros);//Funcao utilizada para salvar os dados lidos na execucao do programa, no arquivo "livros.txt".
//Passamos o endereco de cabeca de livros para poder listar todos os livros, o numero de livros para salvar quantos livros estao cadastrados no momento, e o id_livros para gerar id automatico para novos livros.
void salvar_infra(struct infra * cab,int * num_infra);//Funcao utilizada para salvar os dados lidos na execucao do programa, no arquivo "infra.txt".
//Passamos o endereco de cabeca de infra para poder listar todos as infraestruturas e o numero de infraestruturas cadastradas no momento.

#endif // SALVAR_TIPOS_H_INCLUDED
