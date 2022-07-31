#include "Cabecalho.h"
#include "operacoes_alunos.h"
#include <stdio_ext.h>

void imprimir_alunos(struct alunos * cab){
    if (cab->prox == NULL) { // se a lista encadeada estiver vazia, ele ja indica que nao existem registros
        printf("Nao ha alunos registrados no sistema!\n");
        return;
    }
    system(CLEAR);
    struct alunos *p = cab->prox; //ponteiro p recebe o endereco do primeiro no
    while (p != NULL) { // enquanto houver um proximo no, printamos as informacoes do aluno
        printf("ID: %d\n",p->id);
        printf("Nome: %s\n",p->nome);
        printf("Matricula: %s\n",p->matricula);
        if(p->pendencia > 0 ){ // se o aluno possuir 1 ou mais pendencias na biblioteca
            printf("Pendencia: Aluno possui uma ou mais pendencias com a biblioteca\n");
        }
        else{//se nao possuir pendencias na biblioteca
            printf("Pendencia: Aluno nao possui pendencias com a biblioteca\n");
        }
        printf("\n");
        p = p->prox; // passamos para o proximo no
    }
}

struct alunos * busca_alunos(struct alunos *cab, int id) {
    struct alunos *p = cab->prox;
    while (p != NULL && p->id < id) {
        p = p->prox;
    }
    // p = null => id nao encontrado.
    // p != null => se id encontrado.
    return p;
}
void imprimir_aluno(struct alunos *cab) {
    if (cab->prox == NULL) { // se nao houver nenhum nó apos o cabeca
        printf("Nao ha alunos registrados no sistema!\n");
        return;
    }
    int id;
    printf("Digite o id do aluno que deseja buscar: \n");
    scanf("%d",&id);
    system(CLEAR); // limpa o console
    struct alunos *p = busca_alunos(cab,id); 
    if(p!=NULL && p->id==id){ // se o id for encontrado, printamos as inforcacoes do aluno
        printf("ID: %d\n",p->id);
        printf("Nome: %s\n",p->nome);
        printf("Matricula: %s\n",p->matricula);
        if(p->pendencia > 0){
            printf("Pendencia: Aluno possui uma ou mais pendencias com a biblioteca\n");
        }
        else{
            printf("Pendencia: Aluno nao possui pendencias com a biblioteca\n");
        }
        printf("\n");
    }
    else{
        printf("Este id nao esta cadastrado, tente novamente com um id valido.\n");
    }
}


struct alunos * busca_alunos2(struct alunos *cab, int id, struct alunos **ant) {
    (*ant) = cab; // definimos o ant como cabeca inicialmente
    struct alunos *p = cab->prox; // cabeca = cabeca -> prox 
    while (p != NULL && p->id < id) { // e procuramos pelo id desejado
        (*ant) = p;
        p = p->prox;
    }
    // p = null  : se id nao encontrado.
    // p != null : se id encontrado.
    return p;
}

struct alunos * busca_alunos_matricula(struct alunos * cab,char * matricula){
    struct alunos *p = cab->prox;
    while (p != NULL && (strcmp(p->matricula,matricula)!=0)) {
        p = p->prox;
    }
    // p = null  : se matricula nao encontrada.
    // p != null : se p->matricula = matricula entao chave encontrada. Senao, chave nao encontrada.
    return p;
};

void inserir_alunos(struct alunos *cab, int * k, int * num_alunos) {
    struct alunos *ant = NULL;
    char matricula[100];
    printf("Digite a matricula do aluno que deseja inserir:\n");
    limpar(stdin); // limpamos o lixo de sdin.
    fgets(matricula,100,stdin); // recebemos matricula como entrada do usuario.
    system(CLEAR); // limpamos o console.
    struct alunos *p = busca_alunos_matricula(cab,matricula); // buscamos pela matricula digitada, para verificar se ja nao esta cadastrada.

    if(p!=NULL){// se achar
        printf("Aluno ja possui cadastro na biblioteca!\n");
        return;
    }
    //Criacao e Insercao do novo.
    p = (struct alunos *)malloc(sizeof(struct alunos)); //p recebe o endereco da memoria alocada para o novo no.
    p->id = *k; // atribuimos o id automatico.
    p->prox = ant->prox; // p-> prox = NULL.
    ant->prox = p; // o no anterior aponta para o novo no.
    printf("Digite o nome do aluno que deseja cadastrar:\n");
    limpar(stdin); // limpa  lixo de stdin.
    fgets(p->nome,100,stdin); // recebe p->nome.
    p->nome[strcspn(p->nome, "\n")] = 0; // retira o '\n' do final.
    matricula[strcspn(matricula, "\n")] = 0; // retira o '\n' do final.
    strcpy(p->matricula, matricula);//p->matricula=matricula;
    p->pendencia=0; // numero de pendencias inicialmente = 0.
    system(CLEAR); // limpa o console.
    printf("Cadastro realizado com sucesso!\n");
    *k= *k + 1; // soma 1 no id automatico.
    *num_alunos+=1; // soma 1 no numero de alunos cadastrados.
}
void remover_alunos(struct alunos *cab,int * num_alunos) {
    printf("Digite o id do aluno que deseja remover:\n");
    int id;
    scanf("%d",&id);
    struct alunos *ant = cab; // ponteiro para o anterior aponta inicialmente para cabeca.
    struct alunos *p = busca_alunos2(cab,id,&ant); // buscamos pelo id desejado, caso seja encontrado p aponta para o no que desejamos remover e ant para o no anterior ao que desejamos remover.

    if (p != NULL && p->pendencia==0) { // se for encontrado e nao houver pendencias relacionadas a esse aluno.
        ant->prox = p->prox; // o no anterior a (p), que queremos remover, aponta para proximo no depois do p.
        system(CLEAR); // limpamos o console
        printf("Cadastro do aluno %s removido com sucesso\n",p->nome);
        *num_alunos-=1; // diminuimos 1 do numero de alunos cadastrados.
        free(p); // liberamos a memoria que estava sendo usada por esse no.
    }else if(p == NULL){ // se nao encontrarmos um no que possui esse id.
        system(CLEAR); // limpamos o console
        printf("O ID utilizado nao esta cadastrado.\n");
    }
    else if(p->pendencia != 0){ // se o id for encontrado mas o aluno possui pendencias com a biblioteca.
        printf("O cadastro nao pode ser excluido pois existem pendencias associadas ao aluno: %s  ID: %d  Matricula: %s",p->nome,p->id,p->matricula);
    }
}
