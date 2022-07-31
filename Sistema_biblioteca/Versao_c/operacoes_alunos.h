#ifndef OPERACOES_ALUNOS_H_INCLUDED
#define OPERACOES_ALUNOS_H_INCLUDED
#include "Cabecalho.h"


void imprimir_aluno(struct alunos *cab);//Nessa funcao, e possivel buscar um aluno especifico por id.
//Passamos o endereco do no cabeca de alunos para buscarmos pelo id desejado pelo usuario e imprimimos na tela, caso seja encontrado. Sao impressas todas as informacoes associadas a esse aluno.

void imprimir_alunos(struct alunos *cab);//Nessa funcao, todos os alunos registrados sao printados.
//Passamos o endereco do no cabeca de alunos para percorrer os nos da lista encadeada, printando os dados dos alunos.

struct alunos * busca_alunos(struct alunos *cab, int id);//Nessa funcao, um id especifico é buscado, retornando um ponteiro para o no do aluno, caso seja encontrado.
//Passamos o endereco de cabeca de alunos e o id que estamos buscando, para percorrer os nos da lista encadeada e verificar se o id do aluno e o mesmo que o buscado.

struct alunos * busca_alunos2(struct alunos *cab, int k, struct alunos **ant);//Funcao que se assimila ao busca_aluno, entretanto, passamos tambem um ponteiro para o no anterior, usada quando uma remocao ou insercao for utilizada.
//Passamos o endereco do no cabeca de alunos para poder fazer buscas nos alunos registrados, o id buscado, e o um ponteiro para o no anterior.

struct alunos * busca_alunos_matricula(struct alunos * cab, char * matricula);//Funcao utilizada na hora de inserir alunos, para conferir se a matricula, que o usuario deseja cadastrar, ja esta cadastrada.
//Passamos o endereco do no cabeca de alunos e a matricula para verificar se ela ja existe  

void inserir_alunos(struct alunos *cab, int * id, int * num_alunos);// Nessa funcao, e possivel inserir um novo no na lista encadeada, onde serao armazenados os dados de um novo aluno caso ele nao tenha sido previamente cadastrado.
//Passamos o endereco do no cabeca de alunos, o id automatico e o numero total de alunos que sera aumentado, caso haja a adicao de um amigo.

void remover_alunos(struct alunos *cab, int * num_alunos); //Nessa funcao, e feita a remocao de um aluno ( no ) da lista encadeada, liberando a memoria que ele estava utilizando.
//Passamos o endereco do no cabeca de alunos para buscarmos o no de id que o usuario deseja deletar e o numero total de alunos para ser modificado caso haja remocao.

#endif // OPERACOES_ALUNOS_H_INCLUDED
