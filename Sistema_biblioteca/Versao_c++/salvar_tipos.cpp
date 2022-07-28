#include "Cabecalho.h"

void salvar_alunos(struct alunos *cab,int * num_alunos,int * id_alunos){

    ofstream OutStream;
    OutStream.open("alunos.txt");

    if(!OutStream){
        cout << "Falha ao abrir o arquivo alunos.txt!" << endl;
    }
    if (cab->prox == NULL) {
        cout << "Nao ha alunos para serem salvos!" << endl;
        return;
    }
    OutStream << *id_alunos << endl;
    OutStream << *num_alunos << endl;
    struct alunos *p = cab->prox;

    while (p != NULL) {
        OutStream << p->nome << '\n';
        OutStream << p->matricula << '\n';
        OutStream << p->id << '\n';
        OutStream << p->pendencia << '\n';
        p = p->prox;
    }
    cout << "Alunos salvos com sucesso!" << endl;
    OutStream.close();
}

void salvar_livros(struct livros *cab,int *num_livros,int * id_livros){

    ofstream OutStream;
    OutStream.open("livros.txt");

    if(!OutStream){
        cout << "Falha ao abrir o arquivo livros.txt!" << endl;
    }
    if (cab->prox == NULL) {
        cout << "Nao ha livros para serem salvos!" << endl;
        return;
    }
    OutStream << *id_livros << endl;
    OutStream << *num_livros << endl;
    struct livros *p = cab->prox;

    while (p != NULL) {

        OutStream << p->nome << '\n';
        OutStream << p->ano_de_publi << '\n';
        OutStream << p->categoria << '\n';
        OutStream << p->id << '\n';
        if(p->emprestado){
            OutStream.write("1\n",2);
        }
        else{
            OutStream.write("0\n",2);
        }
        OutStream << p->id_aluno << '\n';
        p = p->prox;

    }
    cout << "Livros salvos com sucesso!" << endl;
    OutStream.close();
}

void salvar_infra(struct infra * cab,int * num_infra){
    if (cab->prox == NULL) {
        cout << "Nao ha infra para ser salva!" << endl;
        return;
    }

    ofstream OutStream;
    OutStream.open("infra.txt");

    if(!OutStream){
        cout << "Falha ao abrir o arquivo infra.txt!" << endl;
    }
    OutStream << *num_infra << endl;
    struct infra *p = cab->prox;

    while (p != NULL) {

        OutStream << p->id << '\n';
        OutStream << p->tipo << '\n';
        if(p->ocupado){
            OutStream.write("1\n",2);
        }
        else{
            OutStream.write("0\n",2);
        }
        OutStream << p->id_aluno << '\n';
        p = p->prox;
        cout << "Infraestruturas salvas com sucesso!" << endl;
    }
    OutStream.close();
}
