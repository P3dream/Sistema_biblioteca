#include "Cabecalho.h"

void imprimir_livro(struct livros *cab, struct alunos *q) {
    if (cab->prox == NULL) {
        cout << "Nao ha livros registrados no sistema!" << endl;
        return;
    }
    int id;
    cout << "Digite o id do livro que deseja buscar: " << endl;;
    cin >> id;
    struct livros *p = cab->prox;
    while (p->id != id && p->prox!=NULL) {
        p = p->prox;
    }
    if(p!=NULL){
        cout << "ID: " << p->id << endl;
        cout << "Nome: " << p->nome << endl;
        cout << "Categoria: " << p->categoria << endl;
        cout << "Ano de Publicacao: " << p->ano_de_publi << endl;
        if(p->emprestado){
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                cout << "Livro esta emprestado emprestado ao aluno de matricula: "<< q->matricula << endl;
            }
        }
        else{
                cout << "Livro esta disponivel para retirada na bilblioteca!"<< endl;
        }
        cout << endl;
    }
    else{
        cout << "Este id nao esta cadastrado";
    }
}

void imprimir_livros(struct livros * cab_livros,struct alunos * q){
    if (cab_livros->prox == NULL) {
        cout << "Nao ha livros registrados no sistema!" << endl;
        return;
    }

    struct livros *p = cab_livros->prox;
    while (p != NULL) {
        cout << "ID: " << p->id << endl;
        cout << "Nome: " << p->nome << endl;
        cout << "Categoria: " << p->categoria << endl;
        cout << "Ano de publicacao: " << p->ano_de_publi << endl;
        if(p->emprestado){
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                cout << "O livro esta sob a utilizacao do aluno de matricula: "<< q->matricula << endl;
            }
        }
        else{
            cout << "Livro disponivel para emprestimo."<<endl;
        }
        cout << endl;
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
    //p = (struct livros *)malloc(sizeof(struct livros));
    p = new livros();
    p->id = *k;
    p->prox = ant->prox;
    ant->prox = p;
    cout << "Digite o nome do livro que deseja inserir:" << endl;
    cin.ignore();
    getline(cin,p->nome);
    cout << "Digite o ano de publicacao do livro:" << endl;
    cin >> p->ano_de_publi;
    cout << "Digite a categoria do livro:"<< endl;
    cin.ignore();
    getline(cin,p->categoria);
    *k= *k + 1;
    p->emprestado=0;
    p->id_aluno=-1;
    *num_livros+=1;

    system(CLEAR);

}

void emprestar_livro(struct livros *cab_livros, struct alunos *cab_alunos){
    int id_aluno;
    cout << "Qual e o id do  aluno que deseja pedir o emprestimo de livro?" << endl;
    cin >> id_aluno;

    //struct alunos *ant_aluno = NULL;
    struct alunos *q = busca_alunos(cab_alunos,id_aluno);
    if(q==NULL){
        cout << "Aluno nao encontrado!" << endl;
        return;
    }

    int id_livro;
    cout << "Qual e o id do livro desejado para emprestimo?" << endl;
    cin >> id_livro;
    system(CLEAR);
    //struct livros *ant_livros = NULL;
    struct livros *p = busca_livros(cab_livros, id_livro);
    if(p==NULL){
        system(CLEAR);
        cout << "Livro nao encontrado!" << endl;
        return;
    }
    if(p->emprestado==true){
        system(CLEAR);
        cout << "Livro indisponivel para emprestimo no momento!" << endl;
        return;
    }
    q->pendencia=q->pendencia+1;
    p->emprestado=true;
    p->id_aluno = id_aluno;
    system(CLEAR);
    cout << "Livro emprestado com sucesso!"<< endl;
    return;
}

void devolver_livro(struct livros *cab_livros, struct alunos *cab_alunos){
    cout << "Qual e o id do aluno que deseja devolver o livro?" << endl;
    int id_aluno;
    cin  >> id_aluno;

    //struct alunos *ant_aluno = cab_alunos;
    struct alunos *p = busca_alunos(cab_alunos,id_aluno);

    if(p==NULL){
        system(CLEAR);
        cout << "Aluno nao encontrado!" << endl;
        return;
    }
    if(p->pendencia==0){
        system(CLEAR);
        cout << "Este aluno nao possui pendencias com a biblioteca!" << endl;
        return;
    }

    cout << "Qual e o id do livro que deseja devolver?" << endl;
    int id_livro;
    cin  >> id_livro;

    //struct livros *ant_livro = cab_livros;
    struct livros *q = busca_livros(cab_livros,id_aluno);

    if(q==NULL){
        system(CLEAR);
        cout << "Livro nao esta cadastrado!" << endl;
        return;
    }
    if(q->emprestado==false){
        system(CLEAR);
        cout<< "Este livro ja se encontra na biblioteca, por favor, verifique o ID do livro e tente novamente." << endl;
    }
    if(q->id_aluno==p->id){
        p->pendencia = p->pendencia-1;
        q->emprestado = false;
        system(CLEAR);
        cout << "Livro devolvido com sucesso!" << endl;
    }
    cout << "O aluno que deseja devolver o livro nao e o mesmo que fez o emprestimo. Por favor, tente novamente." << endl;
}

void buscar_categoria(struct livros *cab_livros, struct alunos *cab_alunos){
     if (cab_livros->prox == NULL) {
        cout << "Nao ha livros registrados no sistema!" << endl;
        return;
    }
    string categoria;
    cout << "Digite a categoria que deseja buscar: " << endl;;
    cin.ignore();
    getline(cin,categoria);
    struct livros *p = cab_livros->prox;
    bool encontrado = false;
    while (p != NULL) {
        if(p->categoria == categoria){
            encontrado = true;
            cout << "ID: " << p->id << endl;
            cout << "Nome: " << p->nome << endl;
            cout << "Categoria: " << p->categoria << endl;
            cout << "Ano de Publicacao: " << p->ano_de_publi << endl;
            if(p->emprestado){
                //struct alunos *ant = NULL;
                struct alunos *q = cab_alunos;
                q = busca_alunos(q,p->id);
                if(q!=NULL){
                    cout << "Livro esta emprestado emprestado ao aluno de matricula: "<< q->matricula << endl;
                }
            }
            else{
                    cout << "Livro esta disponivel para retirada na bilblioteca!"<< endl;
            }
        cout << endl;
        }
        p=p->prox;
    }
    if(encontrado == false){
        cout << "Categoria nao encontrada" << endl;
    }
}

void remover_livros(struct livros *cab,int * num_livros) {
    cout << "Digite o id do livro que deseja remover" << endl;
    int id;
    cin >> id;
    struct livros *ant = cab;
    struct livros *p = busca_livros2(cab,id,&ant);

    if (p != NULL && p->emprestado==false) {
        ant->prox = p->prox;
        system(CLEAR);
        cout << "O livro " << p->nome << " foi removido com sucesso." << endl;
        *num_livros-=1;
        free(p);
        return;
    }else if(p == NULL){
        cout << "O ID utilizado nao esta cadastrado." << endl;;
        return;
    }
    else if(p->emprestado == true){
        cout << "O livro " << p->nome << " nao pode ser removido pois esta atualmente emprestado "<< endl;
        return;
    }
}
