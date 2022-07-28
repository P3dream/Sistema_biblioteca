#include "Cabecalho.h"

int get_size(const char* file_name){
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

void ler_alunos(struct alunos *cab,int * num_alunos,int * id_alunos){
    ifstream InputStream;
    InputStream.open("alunos.txt");
    string line;

    if(!InputStream){
        cout << "Falha ao abrir o arquivo alunos.txt!" << endl;
    }
    if(get_size("alunos.txt") <= 1){
        cout << "Nao ha alunos previamente salvos." << endl;
        return;
    }
    else{
        cout << "Alunos carregados com sucesso!" << endl;
    }

    getline(InputStream,line);
    (*id_alunos) = stoi(line);
    getline(InputStream,line);
    (*num_alunos) = stoi(line);
    struct alunos *ant = cab;
    struct alunos *p;
    for(int i = 0; i<(*num_alunos); i++){
        p = ant->prox;
        p = new alunos();
        ant->prox = p;
        InputStream >> p->nome;
        InputStream >> p->matricula;
        InputStream >> p->id;
        InputStream >> p->pendencia;
        p->prox = NULL;
        ant = p;
    }
    InputStream.close();
}

void ler_livros(struct livros *cab,int * num_livros, int * id_livros){

    ifstream InputStream;
    InputStream.open("livros.txt");
    string line;

    if(!InputStream){
        cout << "Falha ao abrir o arquivo livros.txt!" << endl;
    }
    if(get_size("livros.txt") <= 1){
        cout << "Nao ha livros previamente salvos." << endl;
        return;
    }
    else{
        cout << "Livros carregados com sucesso!" << endl;
    }

    getline(InputStream,line);
    (*id_livros) = stoi(line);
    getline(InputStream,line);
    (*num_livros) = stoi(line);
    struct livros *ant = cab;
    struct livros *p;
    for(int i = 0; i<(*num_livros); i++){
        p = ant->prox;
        p = new livros();
        ant->prox = p;
        InputStream >> p->nome;
        InputStream >> p->ano_de_publi;
        InputStream >> p->categoria;
        InputStream >> p->id;
        InputStream >> p->emprestado;
        InputStream >> p->id_aluno;
        p->prox = NULL;
        ant = p;
    }
    InputStream.close();
}

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

