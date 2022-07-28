#include "Cabecalho.h"
#include "operacoes_infra.h"
#include "operacoes_alunos.h"

struct infra * busca_infra(struct infra *cab, int k) {
    struct infra *p = cab->prox;
    while (p != NULL && p->id < k) {
        p = p->prox;
    }
    // p = null  : se chave 'k' nao encontrada.
    // p != null : se p->c = k, entao chave encontrada. Senao, chave nao encontrada.
    return p;
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



void inserir_infra(struct infra *cab, int *num_infra){
    int k;
    printf("Qual id voce deseja cadastrar?\n");
    scanf("%d",&k);
    system(CLEAR);
    struct infra *ant = NULL;
    struct infra *p = busca_infra2(cab, k,&ant);
    if (p != NULL && p->id == k) {
        system(CLEAR);
        printf("O ID:  %d ja esta cadastrado! Escolha outro ID, e tente novamente.\n",p->id);
        return;
    }
    // Criacao e Insercao do novo no com a chave 'k'.
    p = (struct infra *)malloc(sizeof(struct infra));
    p->id = k;
    p->prox = ant->prox;
    ant->prox = p;
    printf("O que voce deseja cadastrar?\n");
    printf("1 - Computador\n");
    printf("2 - Sala\n");
    printf("3 - Armario\n");
    scanf("%d",&p->tipo);
    p->ocupado = 0;
    p->id_aluno = -1;
    system(CLEAR);
    printf("Cadastro concluido com sucesso!\n");
    *num_infra+=1;
}

void remover_infra(struct infra *cab,int * num_infra) {
    printf("Digite o id da sala,computador ou armario que deseja remover.\n");
    int id;
    scanf("%d",&id);
    struct infra *ant = cab;
    struct infra *p = busca_infra2(cab,id,&ant);
    char string_[20];

    if( p != NULL && p->id  == id) { //se o ponteiro for diferente de nulo e p->id for igual ao id que estamos buscando.
        if(p->tipo==1){
            strcpy (string_,"O Computador");
        }
        else if(p->tipo==2){
            strcpy (string_,"A sala");
        }
        else{
            strcpy (string_,"O Armario");
        }
    }

    if (p != NULL && p->id == id && p->ocupado==0) {
        ant->prox = p->prox;
        system(CLEAR);

        printf("%s de ID: %d foi removido com sucesso\n",string_,p->id);
        *num_infra-=1;
        free(p);
        return;
    }else if(p == NULL || p->id!= id){
        printf("O Id : %d nao esta cadastrado no sistema!\n",id);
        return;
    }
    else if(p->ocupado == 1){
        printf("O cadastro nao pode ser excluido pois %s esta sendo utilizado pelo aluno: %d \n",string_, p->id_aluno);
    }
}

void imprimir_infra(struct infra *cab,struct alunos *q) {
    if (cab->prox == NULL) { // se de cara, o cab - > prox for nulo entao nao ha nada registrado.
        printf("Nao ha nenhuma infraestrutura registrada no sistema!\n");
        return;
    }

    struct infra *p = cab->prox;
    char string_[20];
    while (p != NULL) {
        if(p->tipo==1){
            strcpy (string_,"O Computador");
        }
        else if(p->tipo==2){
            strcpy (string_,"A sala");
        }
        else{
            strcpy (string_,"O Armario");
        }
        printf("ID: %d\n",p->id);
        printf("Tipo: %s\n",string_);
        if(p->ocupado){
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                printf("O(A) %s esta sob a utilizacao do aluno de matricula: %s \n",string_,q->matricula);
            }
        }
        else{
            printf("O(A) %s esta disponivel para utilizacao.\n",string_);
        }
        printf("\n");
        p = p->prox;
    }
}

void emprestar_infra(struct infra *cab_infra,struct alunos *cab_alunos){
    int id_aluno;
    printf("Qual e o id do  aluno que deseja pedir o emprestimo?\n");
    scanf("%d",&id_aluno);

    //struct alunos *ant_aluno = NULL;
    struct alunos *q = busca_alunos(cab_alunos,id_aluno);
    if(q==NULL){
        printf("Aluno nao encontrado!\n");
        return;
    }

    int id_infra;
    printf("Qual e o id da infraestrutura para emprestimo?\n");
    scanf("%d",&id_infra);
    system(CLEAR);
    struct infra *p = busca_infra(cab_infra, id_infra);
    if(p==NULL){
        system(CLEAR);
        printf("ID de infraestrutura nao encontrado!\n");
        return;
    }
    char string_[20];
    if(p->tipo==1){
        strcpy (string_,"O Computador");
    }
    else if(p->tipo==2){
        strcpy (string_,"A sala");
    }
    else{
        strcpy (string_,"O Armario");
    }

    if(p->ocupado){
        system(CLEAR);
        printf("%s esta indisponivel para emprestimo no momento. Esta emprestado(a) com o aluno de matricula: %s \n",string_,q->matricula);
        return;
    }
    p->ocupado=0;
    p->id_aluno = id_aluno;
    q->pendencia = q->pendencia+1;
    system(CLEAR);
    printf("%s foi emprestado com sucesso!\n",string_ );
    return;
}

void devolver_infra(struct infra *cab_infra,struct alunos * cab_alunos){
    printf("Qual e o id do aluno que deseja fazer devolucao?\n");
    int id_aluno;
    scanf("%d",&id_aluno);

    //struct alunos *ant_aluno = cab_alunos;
    struct alunos *p = busca_alunos(cab_alunos,id_aluno);

    if(p==NULL){
        system(CLEAR);
        printf("Aluno nao encontrado\n!");
        return;
    }
    if(p->pendencia==0){
        system(CLEAR);
        printf("Este aluno nao possui pendencias com a biblioteca\n!");
        return;
    }

    printf("Qual e o id da infraestrutura que ele deseja devolver?\n");
    int id_infra;
    scanf("%d",&id_infra);

    struct infra *q = busca_infra(cab_infra,id_aluno);

    if(q==NULL){
        system(CLEAR);
        printf("Esse ID de infraestrutura nao esta cadastrado!\n");
        return;
    }
    if(q->ocupado==0){
        system(CLEAR);
        printf("Essa infraestrutura ja se encontra vaga, por favor, verifique o ID e tente novamente.\n");
    }

    p->pendencia = p->pendencia-1;
    q->ocupado = 0;
    system(CLEAR);
    char string_[20];
    if(q->tipo==1){
        strcpy (string_,"O Computador");
    }
    else if(q->tipo==2){
        strcpy (string_,"A sala");
    }
    else{
        strcpy (string_,"O Armario");
    }
    printf("%s foi devolvido(a) com sucesso!\n",string_);
}

void imprime_infra_por_tipo(struct infra *cab,struct alunos *q){
     if (cab->prox == NULL) { // se de cara, o cab - > prox for nulo entao nao ha nada registrado.
        printf("Nao ha nenhuma infraestrutura registrada no sistema!");
        return;
    }
    int deseja_buscar;
    printf("O que voce deseja buscar?\n");
    printf("1 - Computador\n");
    printf("2 - Sala\n");
    printf("3 - Armario\n");
    scanf("%d",&deseja_buscar);
    system(CLEAR);
    struct infra *p = cab->prox;
    char string_[20];
    while (p != NULL) {
        if(p->tipo!=deseja_buscar){
            p = p->prox;
            continue;
        }

        if(p->tipo==1){
            strcpy (string_,"O Computador");
        }
        else if(p->tipo==2){
            strcpy (string_,"A sala");
        }
        else{
            strcpy (string_,"O Armario");
        }

        printf("\n");
        printf("ID: %d\n",p->id);
        printf("Tipo: %s\n",string_);
        if(p->ocupado){
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                printf("O(A) %s esta sob a utilizacao do aluno de matricula: %s\n",string_,q->matricula);
            }
        }
        else{
                printf("O(A) %s esta disponivel para utilizacao.\n",string_);
        }
        printf("\n");
        p = p->prox;
    }

}
void buscar_infra_por_id(struct infra *cab, struct alunos *q){
    if (cab->prox == NULL) {
        printf("Nao ha infraestrutura registrada no sistema!\n");
        return;
    }
    int id;
    printf("Digite o id da infraestrutura que deseja buscar:\n");
    scanf("%d",&id);
    struct infra *p = busca_infra(cab,id);
    if(p!=NULL && p->id==id){
        printf("ID: %d\n" ,p->id);
        if(p->tipo==1){
            printf("Tipo: Computador\n");
        }
        else if(p->tipo==2){
            printf("Tipo: Sala\n");
        }
        else{
            printf("Tipo: Armario\n");
        }

        if(p->ocupado){
            q = busca_alunos(q,p->id);
            if(q!=NULL){
                printf("Infraestrutura emprestada ao aluno de matricula: %s",q->matricula);
            }
        }
        else{
            printf("Esta disponivel para emprestimo.\n");
        }
        printf("\n");
    }
    else{
        printf("Este id nao esta cadastrado.\n");
    }
}
