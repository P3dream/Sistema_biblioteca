#include "Cabecalho.h"

void imprimir_aluno(struct alunos *cab) {
    if (cab->prox == NULL) {
        cout << "Nao ha alunos registrados no sistema!" << endl;
        return;
    }
    int id;
    cout << "Digite o id do aluno que deseja buscar: " << endl;
    cin >> id;
    struct alunos *p = busca_alunos(cab,id);
    if(p!=NULL && p->id==id){
        cout << "ID: " << p->id << endl;
        cout << "Nome: " << p->nome << endl;
        cout << "Matricula: " << p->matricula << endl;
        if(p->pendencia > 0){
            cout << "Pendencia: Aluno possui uma ou mais pendencias com a biblioteca";
        }
        else{
            cout << "Pendencia: Aluno nao possui pendencias com a biblioteca";
        }
        cout << endl;
    }
    else{
        cout << "Este id nao esta cadastrado" <<endl;
    }
}

void imprimir_alunos(struct alunos *cab) {
    if (cab->prox == NULL) {
        cout << "Nao ha alunos registrados no sistema!" << endl;
        return;
    }

    struct alunos *p = cab->prox;
    while (p != NULL) {
        cout << "ID: " << p->id << endl;
        cout << "Nome: " << p->nome << endl;
        cout << "Matricula: " << p->matricula << endl;
        if(p->pendencia > 0 ){
            cout << "Pendencia: Aluno possui uma ou mais pendencias com a biblioteca";
        }
        else{
            cout << "Pendencia: Aluno nao possui pendencias com a biblioteca";
        }
        cout << endl;
        p = p->prox;
    }
}

struct alunos * busca_alunos(struct alunos *cab, int k) {
    struct alunos *p = cab->prox;
    while (p != NULL && p->id < k) {
        p = p->prox;
    }
    // p = null  : se chave 'k' nao encontrada.
    // p != null : se p->c = k, entao chave encontrada. Senao, chave nao encontrada.
    return p;
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

struct alunos * busca_alunos_matricula(struct alunos * cab,string matricula,struct alunos **ant){
    (*ant) = cab;
    struct alunos *p = cab->prox;
    while (p != NULL && p->matricula != matricula) {
        (*ant) = p;
        p = p->prox;
    }
    // p = null  : se matricula nao encontrada.
    // p != null : se p->matricula = matricula entao chave encontrada. Senao, chave nao encontrada.
    return p;
};

void inserir_alunos(struct alunos *cab, int * k, int * num_alunos) {
    struct alunos *ant = NULL;
    cin.ignore();
    string matricula;
    cout << "Digite a matricula do aluno" << endl;
    getline(cin,matricula);

    struct alunos *p = busca_alunos_matricula(cab,matricula,&ant);
    if(p!=NULL){
        cout << "Aluno ja possui cadastro na biblioteca!" << endl;
        return;
    }
    // Criacao e Insercao do novo no com a chave 'k'.
    //p = (struct alunos *)malloc(sizeof(struct alunos));
    p = new alunos();
    p->id = *k;
    p->prox = ant->prox;
    ant->prox = p;
    cout << "Digite o nome do aluno que deseja cadastrar" << endl;
    getline(cin,p->nome);
    p->matricula=matricula;
    p->pendencia=0;
    system("cls");
    cout << "Cadastro realizado com sucesso!"<< endl;
    *k= *k + 1;
    *num_alunos+=1;
}

void remover_alunos(struct alunos *cab,int * num_alunos) {
    cout << "Digite o id do aluno que deseja remover" << endl;
    int id;
    cin >> id;
    struct alunos *ant = cab;
    struct alunos *p = busca_alunos2(cab,id,&ant);

    if (p != NULL && p->pendencia==0) {
        ant->prox = p->prox;
        system(CLEAR);
        cout << "Cadastro do aluno " << p->nome << " removido com sucesso" << endl;
        *num_alunos-=1;
        free(p);
    }else if(p == NULL){
        cout << "O ID utilizado nao esta cadastrado." << endl;;
    }
    else if(p->pendencia != 0){
        cout << "O cadastro nao pode ser excluido pois existem pendencias associadas ao aluno "<< p->nome << " ID: " << p->id << " Matricula: " << p->matricula << endl;
    }
}
