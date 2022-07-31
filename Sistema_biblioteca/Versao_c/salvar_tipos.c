#include "Cabecalho.h"
#include "operacoes_alunos.h"
#include "salvar_tipos.h"

void salvar_alunos(struct alunos *cab,int * num_alunos,int * id_alunos){

    FILE * File; 
    File = fopen ("alunos.txt","w"); // abrimos o arquivo no modo escrita
    if(!File){
        printf("Falha ao abrir o arquivo alunos.txt!\n");
    }

    if (cab->prox == NULL) { // se nao houver alunos para serem salvos
        printf("Nao ha alunos para serem salvos!\n");
        return;
    }
    fprintf(File,"%d\n",*id_alunos); 
    fprintf(File,"%d\n",*num_alunos);
    // salvamos primeiro id alunos e num alunos
    struct alunos *p = cab->prox;

    while (p != NULL) { // percorremos a lista encadeada de alunos printando todas as informacoes.
        fprintf(File,"%s\n",p->nome);
        fprintf(File,"%s\n",p->matricula);
        fprintf(File,"%d\n",p->id);
        fprintf(File,"%d\n",p->pendencia);
        p = p->prox;
    }
    printf("Alunos salvos com sucesso!\n");
    fclose(File);
}

void salvar_livros(struct livros *cab,int *num_livros,int * id_livros){


    FILE * File;
    File = fopen ("livros.txt","w");// abrimos o arquivo no modo escrita
    if(!File){
        printf("Falha ao abrir o arquivo livros.txt!\n");
    }

    if (cab->prox == NULL) {// se nao houver livros para serem salvos
        printf("Nao ha livros para serem salvos!\n");
        return;
    }
    fprintf(File,"%d\n",*id_livros);
    fprintf(File,"%d\n",*num_livros);
    struct livros *p = cab->prox;
    // salvamos primeiro id livros e num livros
    while (p != NULL) {// percorremos a lista encadeada de livros printando todas as informacoes.
        fprintf(File,"%s\n",p->nome);
        fprintf(File,"%d\n",p->ano_de_publi);
        fprintf(File,"%s\n",p->categoria);
        fprintf(File,"%d\n",p->id);
        if(p->emprestado){
            fprintf(File,"%d\n",1);
        }
        else{
            fprintf(File,"%d\n",0);
        }
        fprintf(File,"%d\n",p->id_aluno);
        p = p->prox;
    }
    printf("livros salvos com sucesso!\n");
    fclose(File);
}

void salvar_infra(struct infra * cab,int * num_infra){

    FILE * File;
    File = fopen ("infra.txt","w");// abrimos o arquivo no modo escrita

    if(!File){ 
        printf("Falha ao abrir o arquivo infra.txt!\n");
    }

    if (cab->prox == NULL) {// se nao houver livros para serem salvos
        printf("Nao ha infraestrutura para ser salva!\n");
        return;
    }

    fprintf(File,"%d\n",*num_infra);
    struct infra *p = cab->prox;
    // salvamos primeiro id livros e num livros

    while (p != NULL) {// percorremos a lista encadeada de livros printando todas as informacoes.

        fprintf(File,"%d\n",p->id);
        fprintf(File,"%d\n",p->tipo);
        if(p->ocupado){
            fprintf(File,"%d\n",1);
        }
        else{
            fprintf(File,"%d\n",0);
        }
        fprintf(File,"%d\n",p->id_aluno);
        p = p->prox;
    }
    printf("Infraestruturas salvas com sucesso!\n");
    fclose(File);
}