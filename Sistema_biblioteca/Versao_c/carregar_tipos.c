#include "Cabecalho.h"


void ler_alunos(struct alunos *cab,int * num_alunos,int * id_alunos){

    FILE * File = fopen ("alunos.txt","r");//abrimos o arquivo no modo de leitura
    if(!File){ // se nao conseguir abrir o arquivo e indicado um erro
        printf("Nao foi possivel abrir o arquivo alunos.txt\n");
    }

    char *buffer;
    size_t bufsize = 2;
    int tamanho;
    struct alunos *ant = cab;
    struct alunos *p;
    buffer = (char * )malloc (bufsize * sizeof(char));

    getline(&buffer,&bufsize,File);
    (*id_alunos) = atoi(buffer);

    getline(&buffer,&bufsize,File);
    (*num_alunos) = atoi(buffer);

    for(int i = 0; i<(*num_alunos); i++){
        p = ant->prox;
        p = (struct alunos *)malloc(sizeof(struct alunos));
        ant->prox = p;

        tamanho = getline(&buffer,&bufsize,File);
        strcpy(p->nome, buffer);
        p->nome[tamanho-1]='\0';

        tamanho = getline(&buffer,&bufsize,File);
        strcpy(p->matricula, buffer);
        p->matricula[tamanho-1]='\0';

        tamanho = getline(&buffer,&bufsize,File);
        p->id = atoi(buffer);

        tamanho = getline(&buffer,&bufsize,File);
        p->pendencia = atoi(buffer);

        p->prox = NULL;
        ant = p;
    }
    printf("Alunos carregados com sucesso!\n");
    fclose(File);
}

void ler_livros(struct livros *cab,int * num_livros, int * id_livros){

    FILE * File = fopen ("livros.txt","r");//abrimos o arquivo no modo de leitura
    if(!File){ // se nao conseguir abrir o arquivo e indicado um erro
        printf("Nao foi possivel abrir o arquivo livros.txt\n");
    }

    char *buffer;
    size_t bufsize = 2;
    int tamanho;
    struct livros *ant = cab;
    struct livros *p;
    buffer = (char * )malloc (bufsize * sizeof(char));

    getline(&buffer,&bufsize,File);
    (*id_livros) = atoi(buffer);

    getline(&buffer,&bufsize,File);
    (*num_livros) = atoi(buffer);

    for(int i = 0; i<(*num_livros); i++){
        p = ant->prox;
        p = (struct livros *)malloc(sizeof(struct livros));
        ant->prox = p;

        tamanho = getline(&buffer,&bufsize,File);
        strcpy(p->nome, buffer);
        p->nome[tamanho-1]='\0';

        getline(&buffer,&bufsize,File);
        p->ano_de_publi = atoi(buffer);

        tamanho = getline(&buffer,&bufsize,File);
        strcpy(p->categoria, buffer);
        p->categoria[tamanho-1]='\0';

        getline(&buffer,&bufsize,File);
        p->ano_de_publi = atoi(buffer);

        getline(&buffer,&bufsize,File);
        p->id = atoi(buffer);

        getline(&buffer,&bufsize,File);
        p->emprestado = atoi(buffer);

        getline(&buffer,&bufsize,File);
        p->id_aluno = atoi(buffer);
        p->prox = NULL;
        ant = p;
    }
    printf("Livros carregados com sucesso!\n");
    fclose(File);
}

void ler_infra(struct infra *cab,int * num_infra){

    FILE * File = fopen ("infra.txt","r");//abrimos o arquivo no modo de leitura
    if(!File){ // se nao conseguir abrir o arquivo e indicado um erro
        printf("Nao foi possivel abrir o arquivo alunos.txt\n");
    }

    char *buffer;
    size_t bufsize = 2;
    int tamanho;

    buffer = (char * )malloc (bufsize * sizeof(char));

    getline(&buffer,&bufsize,File);
    (*num_infra) = atoi(buffer);

    struct infra *ant = cab;
    struct infra *p;
    for(int i = 0; i<(*num_infra); i++){
        p = ant->prox;
        p = (struct infra *)malloc(sizeof(struct infra));
        ant->prox = p;

        getline(&buffer,&bufsize,File);
        p->id = atoi(buffer);
        getline(&buffer,&bufsize,File);
        p->tipo = atoi(buffer);
        getline(&buffer,&bufsize,File);
        p->ocupado = atoi(buffer);
        getline(&buffer,&bufsize,File);
        p->id_aluno = atoi(buffer);
        p->prox = NULL;
        ant = p;
    }

    fclose(File);
}
