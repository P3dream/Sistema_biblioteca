#include "Cabecalho.h"
void ler_alunos(struct alunos *cab,int * num_alunos,int * id_alunos){
    FILE * File = fopen ("alunos.txt","r");//abrimos o arquivo no modo de leitura
    if(!File){ // se nao conseguir abrir o arquivo e indicado um erro
        printf("Nao foi possivel abrir o arquivo alunos.txt\n");
    }

    if(fscanf(File, "%d", id_alunos) == 1){
        fscanf(File,"%d", num_alunos);
    }
    else{
        printf("Nao ha alunos no arquivo para serem carregados.\n");
        return;
    }
    struct alunos *ant = cab;
    struct alunos *p;
    char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char * )malloc (bufsize * sizeof(char));
    for(int i = 0; i<(*num_alunos); i++){
        p = ant->prox;
        p = (struct alunos *)malloc(sizeof(struct alunos));
        ant->prox = p;
        characters = getline(&buffer,&bufsize,stdin);
        fscanf(File,"%s", p->matricula);
        fscanf(File,"%d", &p->id);
        fscanf(File,"%d", &p->pendencia);
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

    if(fscanf(File, "%d", id_livros) == 1){
        fscanf(File,"%d", num_livros);
    }
     else{
        printf("Nao ha livros no arquivo para serem carregados.\n");
        return;
    }
    struct livros *ant = cab;
    struct livros *p;
    for(int i = 0; i<(*num_livros); i++){
        p = ant->prox;
        p = (struct livros *)malloc(sizeof(struct livros));
        ant->prox = p;
        fscanf(File,"%s", p->nome);
        fscanf(File,"%d", &p->ano_de_publi);
        fscanf(File,"%s", p->categoria);
        fscanf(File,"%d", &p->id);
        fscanf(File,"%d", &p->emprestado);
        fscanf(File,"%d", &p->id_aluno);
        p->prox = NULL;
        ant = p;
    }
    printf("Livros carregados com sucesso!\n");
    fclose(File);
}
/***
void ler_infra(struct infra *cab,int * num_infra){

    ifstream InputStream;
    InputStream.open("infra.txt");
    string line;

    if(!InputStream){
        cout << "Falha ao abrir o arquivo infra.txt!" << endl;
    }
    if(get_size("infra.txt") == 0){
        cout << "Nao ha infraestrutura previamente salva." << endl;
        return;
    }
    else{
        cout << "Infraestruturas carregadas com sucesso!" << endl;
    }

    getline(InputStream,line);
    (*num_infra) = stoi(line);
    struct infra *ant = cab;
    struct infra *p;
    for(int i = 0; i<(*num_infra); i++){
        p = ant->prox;
        p = new infra();
        ant->prox = p;
        InputStream >> p->id;
        InputStream >> p->tipo;
        InputStream >> p->ocupado;
        InputStream >> p->id_aluno;
        p->prox = NULL;
        ant = p;
    }
    InputStream.close();
}

***/
