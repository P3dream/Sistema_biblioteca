#include "Cabecalho.h"
#include "operacoes_alunos.h"
//#include <stdio_ext.h>

void imprimir_livro(struct livros *cab, struct alunos *q) {
    if (cab->prox == NULL) {
		system(CLEAR);
        printf("Nao ha livros registrados no sistema!\n");
        return;
    }
    int id;
    printf("Digite o id do livro que deseja buscar:\n");
    scanf("%d",&id);
    struct livros *p = cab->prox;
    while (p->id != id && p->prox!=NULL) {
        p = p->prox;
    }
    if(p!=NULL){
        printf("ID: %d\n",  p->id);
        printf("Nome: %s\n",  p->nome);
        printf("Categoria: %s\n",  p->categoria);
        printf("Ano de Publicacao: %d\n",  p->ano_de_publi);
        if(p->emprestado){
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                printf("Livro esta emprestado emprestado ao aluno de matricula: %s \n",q->matricula);
            }
        }
        else{
                printf("Livro esta disponivel para retirada na bilblioteca!\n");
        }
        printf("\n");
    }
    else{
        printf("Este id nao esta cadastrado.\n");
    }
}

void imprimir_livros(struct livros * cab_livros,struct alunos * q){
    if (cab_livros->prox == NULL) {
        printf("Nao ha livros registrados no sistema!\n");
        return;
    }

    struct livros *p = cab_livros->prox;
    while (p != NULL) {
        printf("ID: %d\n", p->id );
        printf("Nome: %s\n", p->nome );
        printf("Categoria: %s\n", p->categoria );
        printf("Ano de publicacao: %d\n", p->ano_de_publi );
        if(p->emprestado){
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                printf("O livro esta sob a utilizacao do aluno de matricula: %s\n", q->matricula );
            }
        }
        else{
            printf("Livro disponivel para emprestimo.");
        }
        printf("\n");
        p = p->prox;
    }
}

struct livros * busca_livros(struct livros *cab, int k) {
    struct livros *p = cab->prox;
    while (p != NULL && p->id < k) {
        p = p->prox;
    }
    // p = null  : se chave 'k' nao encontrada.
    // p != null : se p->c = k, entao chave encontrada. Senao, chave nao encontrada.
    return p;
}

struct livros * busca_livros2(struct livros *cab, int k, struct livros **ant) {
    (*ant) = cab;
    struct livros *p = cab->prox;
    while (p != NULL && p->id < k) {
        (*ant) = p;
        p = p->prox;
    }
    // p = null  : se chave 'k' nao encontrada.
    // p != null : se p->c = k, entao chave encontrada. Senao, chave nao encontrada.
    return p;
}

void inserir_livros(struct livros *cab, int * k, int * num_livros) {
    struct livros *ant = NULL;
    struct livros *p = busca_livros2(cab, *k, &ant);

    // Criacao e Insercao do novo no com a chave 'k'.
    p = (struct livros *)malloc(sizeof(struct livros));
    p->id = *k;
    p->prox = ant->prox;
    ant->prox = p;
    printf("Digite o nome do livro que deseja inserir:\n");
    limpar(stdin);
    fgets(p->nome,100,stdin);
    printf("Digite o ano de publicacao do livro:\n");
    scanf("%d", &p->ano_de_publi);
    printf("Digite a categoria do livro:\n");
    fflush(stdin);
    fgets(p->categoria,100,stdin);
    *k= *k + 1;
    p->emprestado=0;
    p->id_aluno=-1;
    *num_livros+=1;

    system(CLEAR);
    printf("Livro cadastrado com sucesso!\n");

}

void emprestar_livro(struct livros *cab_livros, struct alunos *cab_alunos){
    int id_aluno;
    printf("Qual e o id do  aluno que deseja pedir o emprestimo de livro?\n" );
    scanf("%d",&id_aluno);

    //struct alunos *ant_aluno = NULL;
    struct alunos *q = busca_alunos(cab_alunos,id_aluno);
    if(q==NULL){
        system(CLEAR);
        printf("Aluno nao encontrado!\n" );
        return;
    }

    int id_livro;
    printf("Qual e o id do livro desejado para emprestimo?\n" );
    scanf("%d",&id_livro);
    system(CLEAR);
    //struct livros *ant_livros = NULL;
    struct livros *p = busca_livros(cab_livros, id_livro);
    if(p==NULL){
        system(CLEAR);
        printf("Livro nao encontrado!\n" );
        return;
    }
    if(p->emprestado==1){
        system(CLEAR);
        printf("Livro indisponivel para emprestimo no momento!\n" );
        return;
    }
    q->pendencia=q->pendencia+1;
    p->emprestado=1;
    p->id_aluno = id_aluno;
    system(CLEAR);
    printf("Livro emprestado com sucesso!\n");
    return;
}

void devolver_livro(struct livros *cab_livros, struct alunos *cab_alunos){
    printf("Qual e o id do aluno que deseja devolver o livro?\n");
    int id_aluno;
    scanf("%d",&id_aluno);
    //struct alunos *ant_aluno = cab_alunos;
    struct alunos *p = busca_alunos(cab_alunos,id_aluno);

    if(p==NULL){
        system(CLEAR);
        printf("Aluno nao encontrado!\n");
        return;
    }
    if(p->pendencia==0){
        system(CLEAR);
        printf("Este aluno nao possui pendencias com a biblioteca!\n");
        return;
    }

    printf("Qual e o id do livro que deseja devolver?\n");
    int id_livro;
    scanf("%d",&id_livro);

    //struct livros *ant_livro = cab_livros;
    struct livros *q = busca_livros(cab_livros,id_livro);

    if(q==NULL){
        system(CLEAR);
        printf("Livro nao esta cadastrado!\n");
        return;
    }
    if(q->emprestado==0){
        system(CLEAR);
        printf("Este livro ja se encontra na biblioteca, por favor, verifique o ID do livro e tente novamente.\n");
    }
    if(q->id_aluno==p->id){
        p->pendencia = p->pendencia-1;
        q->emprestado = 0;
        system(CLEAR);
        printf("Livro devolvido com sucesso!\n");
    }
    else{
        printf("O aluno que deseja devolver o livro nao e o mesmo que fez o emprestimo. Por favor, tente novamente.\n");
    }
}

void buscar_categoria(struct livros *cab_livros, struct alunos *cab_alunos){
     if (cab_livros->prox == NULL) {
        printf("Nao ha livros registrados no sistema!\n");
        return;
    }
    char categoria[100];
    printf("Digite a categoria que deseja buscar: \n");
    fflush(stdin);
    fgets(categoria,100,stdin);
    system(CLEAR);
    struct livros *p = cab_livros->prox;
    int encontrado = 0;
    while (p != NULL) {
        if(strcmp(p->categoria,categoria)==0){
            encontrado = 1;
            printf("ID: %d\n",  p->id );
            printf("Nome: %s\n",  p->nome );
            printf("Categoria: %s\n",  p->categoria );
            printf("Ano de Publicacao: %d\n",  p->ano_de_publi );
            if(p->emprestado){
                //struct alunos *ant = NULL;
                struct alunos *q = cab_alunos;
                q = busca_alunos(q,p->id);
                if(q!=NULL){
                    printf("Livro esta emprestado emprestado ao aluno de matricula: %s\n" ,q->matricula );
                }
            }
            else{
                    printf("Livro esta disponivel para retirada na bilblioteca!\n");
            }
        printf("\n");
        }
        p=p->prox;
    }
    if(encontrado == 0){
        printf("Categoria nao encontrada.\n" );
    }
}

void remover_livros(struct livros *cab,int * num_livros) {
    printf("Digite o id do livro que deseja remover:\n" );
    int id;
    scanf("%d",&id);
    struct livros *ant = cab;
    struct livros *p = busca_livros2(cab,id,&ant);

    if (p != NULL && p->emprestado==0) {
        ant->prox = p->prox;
        system(CLEAR);
        printf("O livro %s foi removido com sucesso.\n",p->nome);
        *num_livros-=1;
        free(p);
        return;
    }else if(p == NULL){
        system(CLEAR);
        printf("O ID utilizado nao esta cadastrado.\n" );;
        return;
    }
    else if(p->emprestado == 1){
        system(CLEAR);
        printf("O livro %s nao pode ser removido pois esta atualmente emprestado\n",p->nome);
        return;
    }
}
