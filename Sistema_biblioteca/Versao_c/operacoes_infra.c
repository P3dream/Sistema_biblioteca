#include "Cabecalho.h"
#include "operacoes_infra.h"
#include "operacoes_alunos.h"

struct infra * busca_infra(struct infra *cab, int id) {
    struct infra *p = cab->prox; // p = cab -> prox ( primeiro no utilizavel).
    while (p != NULL && p->id < id) { // enquanto o id nao for encontrado.
        p = p->prox;
    }
    // p = null => se id nao encontrado.
    // p != null => se id encontrado.
    return p;
}
struct infra * busca_infra2(struct infra *cab, int id, struct infra **ant){
    (*ant) = cab; // anterior aponta para cabeca inicialmente.
    struct infra *p = cab->prox; // p = cab -> prox ( primeiro no utilizavel).
    while (p != NULL && p->id < id) { // enquanto nao encontrar o id buscado.
        (*ant) = p; // anterior aponta para o p.
        p = p->prox; // p aponta para o proximo no.
    }
    // p = null  => se id nao encontrado.
    // p != null => se id encontrado.
    return p;
};



void inserir_infra(struct infra *cab, int *num_infra){
    int id;
    printf("Qual id voce deseja cadastrar?\n");
    scanf("%d",&id);
    system(CLEAR);// limpamos o conspole
    struct infra *ant = NULL; // anterior aponta pra nulo.
    struct infra *p = busca_infra2(cab, id,&ant); // se encontrar o id, o p aponta para o no buscado, e o anterior para o no anterior, se nao, p = NULL.
    if (p != NULL && p->id == id) { // se encontrou .
        system(CLEAR); // limpamos o console.
        printf("O ID:  %d ja esta cadastrado! Escolha outro ID, e tente novamente.\n",p->id);
        return;
    }
    // Criacao e Insercao do novo no.
    p = (struct infra *)malloc(sizeof(struct infra)); //p aponta para a memoria alocada para o novo no
    p->id = id;
    p->prox = ant->prox; ;// p - > aponta para nulo
    ant->prox = p; // ant -> prox aponta para o novo no
    printf("O que voce deseja cadastrar?\n");
    printf("1 - Computador\n");
    printf("2 - Sala\n");
    printf("3 - Armario\n");
    scanf("%d",&p->tipo);
    p->ocupado = 0; // p-> ocupado = 0 inicialmente pois comecara disponivel
    p->id_aluno = -1; // id aluno = -1 inicialmente pois nao esta emprestado a nenhum aluno
    system(CLEAR);// limpamos o console
    printf("Cadastro concluido com sucesso!\n");
    *num_infra+=1; // numero de infraestruturas cadastradas no sistema aumenta em um.
}

void remover_infra(struct infra *cab,int * num_infra) {
    printf("Digite o id da sala,computador ou armario que deseja remover.\n");
    int id;
    scanf("%d",&id);
    struct infra *ant = cab; // anterior aponta para cabeca inicalmente
    struct infra *p = busca_infra2(cab,id,&ant); // buscamos pelo id desejado, caso seja encontrado p aponta para o no que desejamos remover e ant para o no anterior ao que desejamos remover.

    char string_[20];// apenas para ter o nome do tipo de infraestrutura que o usuario escolheu.

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

    if (p != NULL && p->id == id && p->ocupado==0) { // se a infraestrutura for encontrada e nao estiver ocupada, podemos remove-la.
        ant->prox = p->prox; // no anterior a p aponta ao proximo de p.
        system(CLEAR); // limpamos o console.
        printf("%s de ID: %d foi removido com sucesso\n",string_,p->id);
        *num_infra-=1; // diminuimos em um o numero de infraestruturas cadastradas.
        free(p); // liberamos a memoria anteriomente alocada ao no p.
        return;
    }else if(p == NULL || p->id!= id){// se nao encontramos o id buscado.
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

    struct infra *p = cab->prox; // p aponta para o primeiro no utilizavel.
    char string_[20];
    while (p != NULL) {// enquanto houver um no, printamos todas as informacoes relacionadas e ele.
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
        if(p->ocupado){ // se estiver emprestada a um aluno.
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id); // buscamos o aluno que pediu o emprestimo da infraestrutura.
            if(q!=NULL){
                printf("O(A) %s esta sob a utilizacao do aluno de matricula: %s \n",string_,q->matricula);
            }
        }
        else{ // se não.
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
    struct alunos *q = busca_alunos(cab_alunos,id_aluno); // verificamos se o id do aluno e valido.
    if(q==NULL){ // id nao encontrado.
        printf("Aluno nao encontrado!\n");
        return;
    }

    int id_infra;
    printf("Qual e o id da infraestrutura para emprestimo?\n");
    scanf("%d",&id_infra);
    system(CLEAR); // limpamos o console.
    struct infra *p = busca_infra(cab_infra, id_infra); // verificamos se o id esta cadastrado.
    if(p==NULL){ // se nao
        system(CLEAR); // limpamos o console
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

    if(p->ocupado){ // se estiver sendo utilzado por um aluno.
        system(CLEAR); // limpamos o console
        printf("%s esta indisponivel para emprestimo no momento. Esta emprestado(a) com o aluno de matricula: %s \n",string_,q->matricula);
        return;
    }
    // caso o id do aluno e da infra sejam validos, e ela nao estiver indispoivel, pode haver o emprestimo.
    p->ocupado=1;
    p->id_aluno = id_aluno; // salvamos o id do aluno que pediu o emprestimo, nessa infraestrutura.
    q->pendencia = q->pendencia+1; // aumentamos em um o numero de pendencias.
    system(CLEAR);
    printf("%s foi emprestado com sucesso!\n",string_ );
    return;
}

void devolver_infra(struct infra *cab_infra,struct alunos * cab_alunos){
    printf("Qual e o id do aluno que deseja fazer devolucao?\n");
    int id_aluno;
    scanf("%d",&id_aluno);

    //struct alunos *ant_aluno = cab_alunos;
    struct alunos *p = busca_alunos(cab_alunos,id_aluno); // verificamos se o id do aluno e valido.

    if(p==NULL){ // se nao for valido
        system(CLEAR); // limpamos o console
        printf("Aluno nao encontrado\n!");
        return;
    }
    if(p->pendencia==0){ // se for valido mas nao houver pedencias desse aluno com a biblioteca.
        system(CLEAR); // limpamos o console
        printf("Este aluno nao possui pendencias com a biblioteca\n!");
        return;
    }
    // se for valido e houver pendencias.
    printf("Qual e o id da infraestrutura que ele deseja devolver?\n");
    int id_infra;
    scanf("%d",&id_infra);

    struct infra *q = busca_infra(cab_infra,id_aluno); // verificamos se o id da infraestrutura esta cadastrado.

    if(q==NULL){ // se nao for valido.
        system(CLEAR); // limpamos o console
        printf("Esse ID de infraestrutura nao esta cadastrado!\n");
        return;
    }
    if(q->ocupado==0){
        system(CLEAR); // limpamos o console
        printf("Essa infraestrutura ja se encontra vaga, por favor, verifique o ID e tente novamente.\n");
    }
    // apos as verificacoes, se estiver tudo certo e for o aluno que pediu o emprestimo, devolvendo.
    if ( q->id_aluno == p->id ){
        p->pendencia = p->pendencia-1; // diminuimos em um as pendencias do aluno com a biblioteca.
        q->ocupado = 0; // desocupamos a infraestrutura.
        system(CLEAR); // limpamos o console.
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
    else{
        printf("O aluno que deseja devolver a infraestrutura nao foi o mesmo que pediu o emprestimo, tente novamente.\n");
    }
}

void imprime_infra_por_tipo(struct infra *cab,struct alunos *q){
     if (cab->prox == NULL) { // se de cara, o cab - > prox for nulo entao nao ha nada registrado.
        printf("Nao ha nenhuma infraestrutura registrada no sistema!\n");
        return;
    }
    int deseja_buscar;
    printf("O que voce deseja buscar?\n");
    printf("1 - Computador\n");
    printf("2 - Sala\n");
    printf("3 - Armario\n");
    scanf("%d",&deseja_buscar);
    system(CLEAR); // limpamos o console
    struct infra *p = cab->prox; // p aponta para o primeiro no utilizavel.
    char string_[20];
    while (p != NULL) {
        if(p->tipo!=deseja_buscar){ // se a infraestrutura for de um tipo diferente da que o usuario busca, passa para a proxima
            p = p->prox;
            continue;
        }
        // se for do tipo que o usuario busca, printa todas as informacoes associadas a ela.
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
        if(p->ocupado){ // se estiver emprestada, printa as informacoes do aluno que pediu o emprestimo.
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id); // busca pelo no do aluno que pediu o emprestimo para imprimir sua matricula.
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
    if (cab->prox == NULL) { // se de cara, o cab - > prox for nulo entao nao ha nada registrado.
        printf("Nao ha infraestrutura registrada no sistema!\n");
        return;
    }
    int id;
    printf("Digite o id da infraestrutura que deseja buscar:\n");
    scanf("%d",&id);
    struct infra *p = busca_infra(cab,id); // verificamos se e um id valido.
    if(p!=NULL && p->id==id){ // se for valido, e o id buscado for igual ao id do no, imprimimos as informacoes associadas a esse no
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

        if(p->ocupado){ // se a Infraestrutura estiver ocupada
            q = busca_alunos(q,p->id); // buscamos pelas informacoes do aluno associado a essa Infraestrutura para printar sua matricula.
            if(q!=NULL){
                printf("Infraestrutura emprestada ao aluno de matricula: %s",q->matricula);
            }
        }
        else{
            printf("Esta disponivel para emprestimo.\n");
        }
        printf("\n");
    }
    else{// se nao for valido.
        printf("Este id nao esta cadastrado.\n");
    }
}
