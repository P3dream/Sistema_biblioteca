#ifndef OPERACOES_LIVROS_H_INCLUDED
#define OPERACOES_LIVROS_H_INCLUDED

struct livros * busca_livros(struct livros *cab, int k);
struct livros * busca_livros2(struct livros *cab, int k, struct livros **ant);
void inserir_livros(struct livros *cab, int * k,int * num_livros);
void imprimir_livro(struct livros *cab,struct alunos *cab_alunos);
void buscar_categoria(struct livros *cab,struct alunos *cab_alunos);
void imprimir_livros(struct livros *cab,struct alunos *cab_alunos);
void emprestar_livro(struct livros *cab_livros, struct alunos *cab_alunos);
void devolver_livro(struct livros *cab_livros, struct alunos *cab_alunos);
void remover_livros(struct livros *cab,int * num_livros);

#endif // OPERACOES_LIVROS_H_INCLUDED
