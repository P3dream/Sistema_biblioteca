#include "Cabecalho.h"


void ler_alunos(struct alunos *cab,int * num_alunos,int * id_alunos){

    FILE * File = fopen ("alunos.txt","r");//abrimos o arquivo no modo de leitura
    if(!File){ // se nao conseguir abrir o arquivo e indicado um erro
        printf("Nao foi possivel abrir o arquivo alunos.txt\n");
    }

    char *buffer; // ponteiro para char, utilizado como auxiliar para ler os dados do arquivo.
    size_t bufsize = 2; // definimos um tamanho inicial, mas poderia ser qualquer outro pois sera mudado utilizando a funcao getline.
    int tamanho; // tamanho da string.
    struct alunos *ant = cab; // inicialmente ant apontara para o no cabeca
    struct alunos *p;
    buffer = (char * )malloc (bufsize * sizeof(char)); // alocamos memoria para o buffer

    getline(&buffer,&bufsize,File); // lemos a variavel id_alunos do arquivo
    (*id_alunos) = atoi(buffer); // transformamos em inteiro  e atribuimos a id_alunos

    getline(&buffer,&bufsize,File); // o mesmo para num_alunos
    (*num_alunos) = atoi(buffer);

    for(int i = 0; i<(*num_alunos); i++){// ler num_alunos alunos.
        p = ant->prox;
        p = (struct alunos *)malloc(sizeof(struct alunos));
        ant->prox = p;

        tamanho = getline(&buffer,&bufsize,File);
        strcpy(p->nome, buffer); // copiamos o conteudo da variavel auxiliar buffer para p->nome.
        p->nome[tamanho-1]='\0'; // substituimos o '\n' no fim da string por '\0'

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

    char *buffer;// ponteiro para char, utilizado como auxiliar para ler os dados do arquivo.
    size_t bufsize = 2;// definimos um tamanho inicial, mas poderia ser qualquer outro pois sera mudado utilizando a funcao getline.
    int tamanho; // tamanho da string.
    struct livros *ant = cab;// inicialmente ant apontara para o no cabeca
    struct livros *p;
    buffer = (char * )malloc (bufsize * sizeof(char));// alocamos memoria para o buffer

    getline(&buffer,&bufsize,File);// lemos a variavel id_livros do arquivo
    (*id_livros) = atoi(buffer);// transformamos em inteiro e atribuimos a id_livros

    getline(&buffer,&bufsize,File); // o mesmo para num_livros
    (*num_livros) = atoi(buffer);

    for(int i = 0; i<(*num_livros); i++){// ler num_livros livros.
        p = ant->prox;
        p = (struct livros *)malloc(sizeof(struct livros));
        ant->prox = p;

        tamanho = getline(&buffer,&bufsize,File);
        strcpy(p->nome, buffer);// copiamos o conteudo da variavel auxiliar buffer para p->nome.
        p->nome[tamanho-1]='\0';// substituimos o '\n' no fim da string por '\0'

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

    char *buffer;// ponteiro para char, utilizado como auxiliar para ler os dados do arquivo.
    size_t bufsize = 2;// definimos um tamanho inicial, mas poderia ser qualquer outro pois sera mudado utilizando a funcao getline.
    int tamanho;// tamanho da string.

    buffer = (char * )malloc (bufsize * sizeof(char));// alocamos memoria para o buffer

    getline(&buffer,&bufsize,File);// lemos a variavel num_infra do arquivo
    (*num_infra) = atoi(buffer);// transformamos em inteiro e atribuimos a num_infra

    struct infra *ant = cab;// inicialmente ant apontara para o no cabeca
    struct infra *p;
    for(int i = 0; i<(*num_infra); i++){// ler num_infra infraestruturas.
        p = ant->prox;
        p = (struct infra *)malloc(sizeof(struct infra));
        ant->prox = p;

        getline(&buffer,&bufsize,File); // lemos do arquivo e guardamos em buffer
        p->id = atoi(buffer); // transformamos em inteiro e atribuimos a p->id;
        getline(&buffer,&bufsize,File);
        p->tipo = atoi(buffer);
        getline(&buffer,&bufsize,File);
        p->ocupado = atoi(buffer);
        getline(&buffer,&bufsize,File);
        p->id_aluno = atoi(buffer);
        p->prox = NULL;
        ant = p;
    }
    printf("infraestruturas carregados com sucesso!\n");
    fclose(File);
}
