#include "Cabecalho.h"
#include "operacoes_alunos.h"
#include "salvar_tipos.h"

void salvar_alunos(struct alunos *cab,int * num_alunos,int * id_alunos){

    FILE * File;
    File = fopen ("alunos.txt","w");
    if(!File){
        printf("Falha ao abrir o arquivo alunos.txt!\n");;
    }

    if (cab->prox == NULL) {
        printf("Nao ha alunos para serem salvos!\n");;
        return;
    }
    fprintf(File,"%d\n",*id_alunos);
    fprintf(File,"%d\n",*num_alunos);
    struct alunos *p = cab->prox;

    while (p != NULL) {
        fprintf(File,"%s\n",p->nome);
        fprintf(File,"%s\n",p->matricula);
        fprintf(File,"%d\n",p->id);
        fprintf(File,"%d\n",p->pendencia);
        p = p->prox;
    }
    printf("Alunos salvos com sucesso!\n");;
    fclose(File);
}

void salvar_livros(struct livros *cab,int *num_livros,int * id_livros){


    FILE * File;
    File = fopen ("livros.txt","w");
    if(!File){
        printf("Falha ao abrir o arquivo livros.txt!\n");;
    }

    if (cab->prox == NULL) {
        printf("Nao ha livros para serem salvos!\n");;
        return;
    }
    fprintf(File,"%d\n",*id_livros);
    fprintf(File,"%d\n",*num_livros);
    struct livros *p = cab->prox;

    while (p != NULL) {
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
        p = p->prox;
    }
    printf("livros salvos com sucesso!\n");;
    fclose(File);
}

void salvar_infra(struct infra * cab,int * num_infra){

    FILE * File;
    File = fopen ("livros.txt","w");

    if(!File){
        printf("Falha ao abrir o arquivo livros.txt!\n");;
    }

    if (cab->prox == NULL) {
        printf("Nao ha infraestrutura para ser salva!\n");;
        return;
    }

    fprintf(File,"%d\n",*num_infra);
    struct infra *p = cab->prox;

    while (p != NULL) {

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
        printf("Infraestruturas salvas com sucesso!\n");
    }
    fclose(File);
}

