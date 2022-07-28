#include "Cabecalho.h"
#include "operacoes_alunos.h"
//#include <stdio_ext.h>

void imprimir_alunos(struct alunos * cab){
    if (cab->prox == NULL) { // se a lista encadeada estiver vazia, ele ja indica que nao existem registros
        printf("Nao ha alunos registrados no sistema!\n");
        return;
    }
    system(CLEAR);
    struct alunos *p = cab->prox; //ponteiro p recebe o endereco do primeiro no
    while (p != NULL) {
        printf("ID: %d\n",p->id);
        printf("Nome: %s\n",p->nome);
        printf("Matricula: %s\n",p->matricula);
        if(p->pendencia > 0 ){ // se o aluno possuir 1 ou mais pendencias na biblioteca
            printf("Pendencia: Aluno possui uma ou mais pendencias com a biblioteca\n");
        }
        else{//se nao possuir pendencias na biblioteca
            printf("Pendencia: Aluno nao possui pendencias com a biblioteca\n");
        }
        printf("\n");
        p = p->prox; // passamos para o proximo no
    }
}

struct alunos * busca_alunos(struct alunos *cab, int id) {
    struct alunos *p = cab->prox;
    while (p != NULL && p->id < id) {
        p = p->prox;
    }
    // p = null: se id nao encontrado.
    // p != null : se p->c = k, entao chave encontrada. Senao, chave nao encontrada.
    return p;
}
void imprimir_aluno(struct alunos *cab) {
    if (cab->prox == NULL) {
        printf("Nao ha alunos registrados no sistema!\n");
        return;
    }
    int id;
    printf("Digite o id do aluno que deseja buscar: \n");
    scanf("%d",&id);
    system(CLEAR);
    struct alunos *p = busca_alunos(cab,id);
    if(p!=NULL && p->id==id){
        printf("ID: %d\n",p->id);
        printf("Nome: %s\n",p->nome);
        printf("Matricula: %s\n",p->matricula);
        if(p->pendencia > 0){

            printf("Pendencia: Aluno possui uma ou mais pendencias com a biblioteca\n");
        }
        else{
            printf("Pendencia: Aluno nao possui pendencias com a biblioteca\n");
        }
        printf("\n");
    }
    else{
        printf("Este id nao esta cadastrado\n");
    }
}


struct alunos * busca_alunos2(struct alunos *cab, int k, struct alunos **ant) {
    (*ant) = cab;
    struct alunos *p = cab->prox;
    while (p != NULL && p->id < k) {
        (*ant) = p;
        p = p->prox;
    }
    // p = null  : se chave 'k' nao encontrada.
    // p != null : se p->c = k, entao chave encontrada. Senao, chave nao encontrada.
    return p;
}

struct alunos * busca_alunos_matricula(struct alunos * cab,char * matricula,struct alunos **ant){
    (*ant) = cab;
    struct alunos *p = cab->prox;
    while (p != NULL && (strcmp(p->matricula,matricula)!=0)) {
        (*ant) = p;
        p = p->prox;
    }
    // p = null  : se matricula nao encontrada.
    // p != null : se p->matricula = matricula entao chave encontrada. Senao, chave nao encontrada.
    return p;
};

void inserir_alunos(struct alunos *cab, int * k, int * num_alunos) {
    struct alunos *ant = NULL;
    char matricula[100];
    printf("Digite a matricula do aluno que deseja inserir:\n");
    limpar(stdin);
    fgets(matricula,100,stdin);
    system(CLEAR);
    struct alunos *p = busca_alunos_matricula(cab,matricula,&ant);

    if(p!=NULL){
        printf("Aluno ja possui cadastro na biblioteca!\n");
        return;
    }
    // Criacao e Insercao do novo no com a chave 'k'.
    p = (struct alunos *)malloc(sizeof(struct alunos));
    p->id = *k;
    p->prox = ant->prox;
    ant->prox = p;
    printf("Digite o nome do aluno que deseja cadastrar:\n");
    limpar(stdin);
    fgets(p->nome,100,stdin);
    p->nome[strcspn(p->nome, "\n")] = 0;
    matricula[strcspn(matricula, "\n")] = 0;
    strcpy(p->matricula, matricula);//p->matricula=matricula;
    p->pendencia=0;
    system(CLEAR);
    printf("Cadastro realizado com sucesso!\n");
    *k= *k + 1;
    *num_alunos+=1;
}

void remover_alunos(struct alunos *cab,int * num_alunos) {
    printf("Digite o id do aluno que deseja remover:\n");
    int id;
    scanf("%d",&id);
    struct alunos *ant = cab;
    struct alunos *p = busca_alunos2(cab,id,&ant);

    if (p != NULL && p->pendencia==0) {
        ant->prox = p->prox;
        system(CLEAR);
        printf("Cadastro do aluno %s removido com sucesso\n",p->nome);
        *num_alunos-=1;
        free(p);
    }else if(p == NULL){
        system(CLEAR);
        printf("O ID utilizado nao esta cadastrado.\n");
    }
    else if(p->pendencia != 0){
        printf("O cadastro nao pode ser excluido pois existem pendencias associadas ao aluno: %s  ID: %d  Matricula: %s",p->nome,p->id,p->matricula);
    }
}
