#include "Cabecalho.h"

struct infra * busca_infra(struct infra *cab, int k) {
    struct infra *p = cab->prox;
    while (p != NULL && p->id < k) {
        p = p->prox;
    }
    // p = null  : se chave 'k' nao encontrada.
    // p != null : se p->c = k, entao chave encontrada. Senao, chave nao encontrada.
    return p;
}

void inserir_infra(struct infra *cab, int *num_infra){
    int k;
    cout << "Qual id voce deseja cadastrar?" << endl;
    cin >> k;
    system(CLEAR);
    struct infra *ant = NULL;
    struct infra *p = busca_infra2(cab, k,&ant);
    if (p != NULL && p->id == k) {
        system(CLEAR);
        cout << "O ID:  "<< p->id << " ja esta cadastrado! Escolha outro ID, e tente novamente." << endl;
        return;
    }
    // Criacao e Insercao do novo no com a chave 'k'.
    //p = (struct infra *)malloc(sizeof(struct infra));
    p = new infra();
    p->id = k;
    p->prox = ant->prox;
    ant->prox = p;
    cout << "O que voce deseja cadastrar?" << endl;
    cout << "1 - Computador" << endl;
    cout << "2 - Sala" << endl;
    cout << "3 - Armario" << endl;
    cin >> p->tipo;
    p->ocupado = false;
    p->id_aluno = -1;
    system(CLEAR);
    cout << "Cadastro concluido com sucesso!" << endl;
    *num_infra+=1;
}

void remover_infra(struct infra *cab,int * num_infra) {
    cout << "Digite o id da sala,computador ou armario que deseja remover." << endl;
    int id;
    cin >> id;
    struct infra *ant = cab;
    struct infra *p = busca_infra2(cab,id,&ant);
    string string_;

    if( p != NULL && p->id  == id) { //se o ponteiro for diferente de nulo e p->id for igual ao id que estamos buscando.

        if(p->tipo==1){
            string_ = "O Computador";
        }
        else if(p->tipo==2){
            string_ = "A Sala";
        }
        else{
            string_ = "O Armario";
        }
    }

    if (p != NULL && p->id == id && p->ocupado==false) {
        ant->prox = p->prox;
        system(CLEAR);

        cout << string_ <<" de ID: " << p->id << " foi removido com sucesso" << endl;
        *num_infra-=1;
        free(p);
        return;
    }else if(p == NULL || p->id!= id){
        cout << "O Id : " << id << " nao esta cadastrado no sistema!" << endl;
        return;
    }
    else if(p->ocupado == true){
        cout << "O cadastro nao pode ser excluido pois" << string_ << " esta sendo utilizado pelo aluno "<< p->id_aluno << endl;
    }
}

void imprimir_infra(struct infra *cab,struct alunos *q) {
    if (cab->prox == NULL) { // se de cara, o cab - > prox for nulo entao nao ha nada registrado.
        cout << "Nao ha nenhuma infraestrutura registrada no sistema!" << endl;
        return;
    }

    struct infra *p = cab->prox;
    string string_;
    while (p != NULL) {
        if(p->tipo==1){
            string_ = "Computador";
        }
        else if(p->tipo==2){
            string_ = "Sala";
        }
        else{
            string_ = "Armario";
        }
        cout << "ID: " << p->id << endl;
        cout << "Tipo: " << string_ << endl;
        if(p->ocupado){
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                cout << "O(A) "<< string_ <<" esta sob a utilizacao do aluno de matricula: "<< q->matricula << endl;
            }
        }
        else{
            cout << "O(A) "<< string_ << " esta disponivel para utilizacao."<< endl;
        }
        cout << endl;
        p = p->prox;
    }
}

void emprestar_infra(struct infra *cab_infra,struct alunos *cab_alunos){
    int id_aluno;
    cout << "Qual e o id do  aluno que deseja pedir o emprestimo?" << endl;
    cin >> id_aluno;

    //struct alunos *ant_aluno = NULL;
    struct alunos *q = busca_alunos(cab_alunos,id_aluno);
    if(q==NULL){
        cout << "Aluno nao encontrado!" << endl;
        return;
    }

    int id_infra;
    cout << "Qual e o id da infraestrutura para emprestimo?" << endl;
    cin >> id_infra;
    system(CLEAR);
    struct infra *p = busca_infra(cab_infra, id_infra);
    if(p==NULL){
        system(CLEAR);
        cout << "ID de infraestrutura nao encontrado!" << endl;
        return;
    }
    string string_;
    if(p->tipo==1){
            string_ = "O Computador";
    }else if(p->tipo==2){
        string_ = "A Sala";
    }else{
        string_ = "O Armario";
    }

    if(p->ocupado){
        system(CLEAR);
        cout << string_ <<" esta indisponivel para emprestimo no momento. Esta emprestado(a) com o aluno de matricula: " << q->matricula << endl;
        return;
    }
    p->ocupado=true;
    p->id_aluno = id_aluno;
    q->pendencia = q->pendencia+1;
    system(CLEAR);
    cout << string_ << " foi emprestado com sucesso!"<< endl;
    return;
}

void devolver_infra(struct infra *cab_infra,struct alunos * cab_alunos){
    cout << "Qual e o id do aluno que deseja fazer devolucao?" << endl;
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

    cout << "Qual e o id da infraestrutura que ele deseja devolver?" << endl;
    int id_infra;
    cin  >> id_infra;

    struct infra *q = busca_infra(cab_infra,id_aluno);

    if(q==NULL){
        system(CLEAR);
        cout << "Esse ID de infraestrutura nao esta cadastrado!" << endl;
        return;
    }
    if(q->ocupado==false){
        system(CLEAR);
        cout<< "Essa infraestrutura ja se encontra vaga, por favor, verifique o ID e tente novamente." << endl;
    }

    p->pendencia = p->pendencia-1;
    q->ocupado = false;
    system(CLEAR);
    string string_;
    if(q->tipo==1){
            string_ = "O Computador";
    }else if(q->tipo==2){
        string_ = "A Sala";
    }else{
        string_ = "O Armario";
    }
    cout << string_ << " foi devolvido(a) com sucesso!" << endl;
}

void imprime_infra_por_tipo(struct infra *cab,struct alunos *q){
     if (cab->prox == NULL) { // se de cara, o cab - > prox for nulo entao nao ha nada registrado.
        cout << "Nao ha nenhuma infraestrutura registrada no sistema!" << endl;
        return;
    }
    int deseja_buscar;
    cout << "O que voce deseja buscar?" << endl;
    cout << "1 - Computador" << endl;
    cout << "2 - Sala" << endl;
    cout << "3 - Armario" << endl;
    cin >> deseja_buscar;
    system(CLEAR);
    struct infra *p = cab->prox;
    string string_;
    while (p != NULL) {
        if(p->tipo!=deseja_buscar){
            p = p->prox;
            continue;
        }
        if(p->tipo==1){
            string_ = "Computador";
        }
        else if(p->tipo==2){
            string_ = "Sala";
        }
        else{
            string_ = "Armario";
        }
        cout << endl;
        cout << "ID: " << p->id << endl;
        cout << "Tipo: " << string_ << endl;
        if(p->ocupado){
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                cout << "O(A) "<<string_ <<" esta sob a utilizacao do aluno de matricula: "<< q->matricula << endl;
            }
        }
        else{
                cout << "O(A) "<< string_ << " esta disponivel para utilizacao."<< endl;
        }
        cout << endl;
        p = p->prox;
    }

}
void buscar_infra_por_id(struct infra *cab, struct alunos *q){
    if (cab->prox == NULL) {
        cout << "Nao ha infraestrutura registrada no sistema!" << endl;
        return;
    }
    int id;
    cout << "Digite o id da infraestrutura que deseja buscar: " << endl;
    cin >> id;
    struct infra *p = busca_infra(cab,id);
    if(p!=NULL && p->id==id){
        cout << "ID: " << p->id << endl;
        if(p->tipo==1){
            cout << "Tipo: Computador" << endl;
        }
        else if(p->tipo==2){
            cout << "Tipo: Sala" << endl;
        }
        else{
            cout << "Tipo: Armario" << endl;
        }

        if(p->ocupado){
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                cout << "Infraestrutura emprestada ao aluno de matricula: "<< q->matricula << endl;
            }
        }
        else{
            cout << "Esta disponivel para emprestimo." <<endl;
        }
        cout << endl;
    }
    else{
        cout << "Este id nao esta cadastrado." <<endl;
    }
}

struct infra * busca_infra2(struct infra *cab, int k, struct infra **ant){
    (*ant) = cab;
    struct infra *p = cab->prox;
    while (p != NULL && p->id < k) {
        (*ant) = p;
        p = p->prox;
    }
    // p = null  : se chave 'k' nao encontrada.
    // p != null : se p->c = k, entao chave encontrada. Senao, chave nao encontrada.
    return p;
};

