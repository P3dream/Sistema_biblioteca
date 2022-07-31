#ifndef OPERACOES_LIVROS_H_INCLUDED
#define OPERACOES_LIVROS_H_INCLUDED
#include "Cabecalho.h"

struct livros * busca_livros(struct livros *cab, int id);//Nessa funcao, um id especifico é buscado, retornando um ponteiro para o no do livro, caso seja encontrado.
//Passamos o endereco de cabeca de livros e o id que estamos buscando, para percorrer os nos da lista encadeada e verificar se o id do livro e o mesmo que o buscado.

struct livros * busca_livros2(struct livros *cab, int id, struct livros **ant);//Funcao que se assimila ao busca_livros, entretanto, passamos tambem um ponteiro para o no anterior, usada quando uma remocao ou insercao for utilizada.
//Passamos o endereco do no cabeca de livros para poder fazer buscas nos livros registrados, o id buscado, e o um ponteiro para o no anterior.

void inserir_livros(struct livros *cab, int * id,int * num_livros);// Nessa funcao, e possivel inserir um novo no na lista encadeada, onde serao armazenados os dados de um novo livro caso ele nao tenha sido previamente cadastrado.
//Passamos o endereco do no cabeca de livros, o id automatico e o numero total de livros que sera aumentado, caso haja a adicao de um amigo.

void imprimir_livro(struct livros *cab,struct alunos *cab_alunos);//Nessa funcao, e possivel buscar um livro especifico por id.
//Passamos o endereco do no cabeca de livros para buscarmos pelo id desejado pelo usuario e imprimimos na tela, caso seja encontrado. Sao impressas todas as informacoes associadas a esse livro.


void buscar_categoria(struct livros *cab,struct alunos *cab_alunos);//Nessa funcao, buscamos pela categoria que o usuario deseja filtrar e printamos as livros com a categoria desejada.
//Passamos o endereco do no cabeca de livros para buscarmos pela categoria desejada, e o endereco do no cabeca de alunos para indicar a matricula do aluno para quem o livro estiver emprestado, caso esteja.

void imprimir_livros(struct livros *cab,struct alunos *cab_alunos);//Nessa funcao, todos os livros registrados sao printados.
//Passamos o endereco do no cabeca de livros para percorrer os nos da lista encadeada, printando os dados dos livros.

void emprestar_livro(struct livros *cab_livros, struct alunos *cab_alunos);//Nessa funcao, um livro e emprestado a um aluno, aumentando em um o numero de pendencias de um aluno, e indicando que o livro esta emprestado, tambem salva o id do aluno que pediu o emprestimo.
//Passamos o endereco do no cabeca de livros para fazermos buscas e o endereco do no cabeca de alunos para realizar o emprestimo, caso possivel.


void devolver_livro(struct livros *cab_livros, struct alunos *cab_alunos);//Nessa funcao, um livro pode ser devolvido por um aluno, caso ele tenha sido previamente pego por um aluno, e so pode ser devolvido pelo aluno que o pegou.
//Passamos o endereco do no cabeca de livros para fazermos a busca do livro que o aluno deseja buscar e o no cabeca de alunos para verificar se ele e realmente o que pediu o emprestimo, para fazer a devolucao.

void remover_livros(struct livros *cab,int * num_livros);//Nessa funcao, removemos um livro (no) que possui o id recebido pela funcao, caso esteja registrado e nao emprestado, da lista encadeada.
//Passamos o endereco do no cabeca de livros para fazermos a busca pelo livro de id equivalente ao id digitado pelo usuario. Tambem passamos o no cabeca de alunos para indicar a matricula do aluno que esta com a posse do livro, caso esteja emprestado.

#endif // OPERACOES_LIVROS_H_INCLUDED
