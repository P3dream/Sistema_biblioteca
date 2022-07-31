#ifndef CARREGAR_TIPOS_H_INCLUDED
#define CARREGAR_TIPOS_H_INCLUDED

void ler_alunos(struct alunos *cab, int * num_alunos, int * id_alunos);//Funcao utilizada para carregar do arquivo "alunos.txt", dados previamente inseridos pelo usuario.
//passamos como parametro o no cabeca de alunos para salva-los na lista encadeada, o numero de alunos para mantermos o controle de quantos alunos estao atualmente cadastrados na biblioteca e por ultimo o numero do proximo id automatico.

void ler_infra(struct infra *cab,int * num_infra);//Funcao utilizada para carregar do arquivo "infra.txt", dados previamente inseridos pelo usuario.
//passamos como parametro o no cabeca de infra para salva-las na lista encadeada e o numero de infraestruturas para mantermos o controle de quantas infraestruturas estao atualmente cadastradas na biblioteca.


void ler_livros(struct livros *cab,int * num_livros, int * id_livros);//Funcao utilizada para carregar do arquivo "livros.txt", dados previamente inseridos pelo usuario.
//passamos como parametro o no cabeca de livros para salva-los na lista encadeada, o numero de livros para mantermos o controle de quantos livros estao atualmente cadastrados na biblioteca e por ultimo o numero do proximo id automatico.

#endif // CARREGAR_TIPOS_H_INCLUDED
