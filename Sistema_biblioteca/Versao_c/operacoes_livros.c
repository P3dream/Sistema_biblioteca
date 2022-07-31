#include "Cabecalho.h"
#include "operacoes_alunos.h"
#include <stdio_ext.h>
#include <time.h>


void imprimir_livro(struct livros *cab, struct alunos *q) {
    if (cab->prox == NULL) {// se de cara, o cab-> prox for nulo entao nao ha nada registrado.
		system(CLEAR);// limpamos o console.
        printf("Nao ha livros registrados no sistema!\n");
        return;
    }
    int id;
    printf("Digite o id do livro que deseja buscar:\n");
    scanf("%d",&id);
    struct livros *p = cab->prox; // p inicialmente aponta para o primeiro no utilizavel.
    while (p->id != id && p->prox!=NULL) { // enquanto o id do no for diferente do id buscado.
        p = p->prox;
    }
    if(p!=NULL && p->id==id){ // se o no com o id buscado for encontrado, printamos as informacoes associadas a ele.
        printf("ID: %d\n",  p->id);
        printf("Nome: %s\n",  p->nome);
        printf("Categoria: %s\n",  p->categoria);
        printf("Ano de Publicacao: %d\n",  p->ano_de_publi);
        if(p->emprestado){// se estiver emprestado.
            q = busca_alunos(q,p->id_aluno);//buscamos as informacoes do aluno associado a esse emprestimo para obtermos sua matricula.
            printf("Livro esta emprestado emprestado ao aluno de matricula: %s \n",q->matricula);
        }
        else{// se nao estiver emprestado.
            printf("Livro esta disponivel para retirada na bilblioteca!\n");
        }
        printf("\n");
    }
    else{// se o id do livro buscado nao for encontrado.
        printf("Este id nao esta cadastrado.\n");
    }
}

void imprimir_livros(struct livros * cab_livros,struct alunos * q){
    if (cab_livros->prox == NULL) {// se de cara, o cab - > prox for nulo entao nao ha nada registrado.
        printf("Nao ha livros registrados no sistema!\n");
        return;
    }

    struct livros *p = cab_livros->prox; // p inicialmente aponta para o primeiro no utilizavel.
    while (p != NULL) { // printamos as informacoes associadas aos nos.
        printf("ID: %d\n", p->id );
        printf("Nome: %s\n", p->nome );
        printf("Categoria: %s\n", p->categoria );
        printf("Ano de publicacao: %d\n", p->ano_de_publi );
        if(p->emprestado){// se o livro estiver emprestado.
            //struct alunos *ant = NULL;
            q = busca_alunos(q,p->id);//buscamos as informacoes do aluno associado a esse emprestimo para obtermos sua matricula.
            if(q!=NULL){
                printf("O livro esta sob a utilizacao do aluno de matricula: %s\n", q->matricula );
            }
        }
        else{
            printf("Livro disponivel para emprestimo.\n");
        }
        printf("\n");
        p = p->prox;
    }
}

struct livros * busca_livros(struct livros *cab, int id) {
    struct livros *p = cab->prox;// p = cab -> prox ( primeiro no utilizavel).
    while (p != NULL && p->id < id) {// enquanto o id nao for encontrado.
        p = p->prox;
    }
    // p = null => se id nao encontrado.
    // p != null => id encontrado.
    return p;
}

struct livros * busca_livros2(struct livros *cab, int id, struct livros **ant) {
    (*ant) = cab;// definimos o ant como cabeca inicialmente
    struct livros *p = cab->prox;// cabeca = cabeca -> prox 
    while (p != NULL && p->id < id) {// e procuramos pelo id desejado
        (*ant) = p;
        p = p->prox;
    }
    // p = null  => se id nao encontrado.
    // p != null => se id encontrado.
    return p;
}

void inserir_livros(struct livros *cab, int * id, int * num_livros) {
    struct livros *ant = NULL;
    struct livros *p = busca_livros2(cab, *id, &ant);// pegamos o endereco do ultimo no com o ant

    // Criacao e Insercao do novo no com a chave 'k'.
    p = (struct livros *)malloc(sizeof(struct livros)); //p recebe o endereco da memoria alocada para o novo no.
    p->id = *id; // atribuimos o id automatico.
    p->prox = ant->prox; // p-> prox = NULL.
    ant->prox = p; // o no anterior aponta para o novo no.
    printf("Digite o nome do livro que deseja inserir:\n");
    limpar(stdin);// limpa  lixo de stdin.
    fgets(p->nome,100,stdin);// recebe p->nome.
    p->nome[strcspn(p->nome, "\n")] = 0;// retira o '\n' do final.
    
    time_t my_time;
    struct tm * timeinfo; 
    time (&my_time);
    timeinfo = localtime (&my_time); // obtemos a data atual para verificar se a data inserida pelo usuario sera valida.
    
    printf("Digite o ano de publicacao do livro, (Intervalo aceito 0-ano atual):\n");
    scanf("%d", &p->ano_de_publi);
    
    while(p->ano_de_publi < 0 || p->ano_de_publi > timeinfo->tm_year+1900){
        printf("Por favor, Digite novamente o ano de publicacao do livro, (Intervalo aceito 0-ano atual):\n");
        scanf("%d", &p->ano_de_publi);
    }
    
    printf("Digite a categoria do livro:\n");
    limpar(stdin);// limpa  lixo de stdin.
    fgets(p->categoria,100,stdin);// recebe p->categoria.
    p->categoria[strcspn(p->categoria, "\n")] = 0;// retira o '\n' do final.
    *id= *id + 1;// aumenta 1 no id automatico
    p->emprestado=0;// inicialmente comecara com disponivel
    p->id_aluno=-1;// id do aluno que pediu o emprestimo inicialmente comecara com -1.
    *num_livros+=1; // numero de livros cadastrados e incrementado.

    system(CLEAR);// limpamos o console
    printf("Livro cadastrado com sucesso!\n");

}

void emprestar_livro(struct livros *cab_livros, struct alunos *cab_alunos){
    int id_aluno;
    printf("Qual e o id do  aluno que deseja pedir o emprestimo de livro?\n" );
    scanf("%d",&id_aluno);

    //struct alunos *ant_aluno = NULL;
    struct alunos *q = busca_alunos(cab_alunos,id_aluno); // verificamos se o id do aluno e valido
    if(q==NULL){// se nao for
        system(CLEAR);// limpamos o console
        printf("Aluno nao encontrado!\n" );
        return;
    }
    // se o id for valido.
    int id_livro;
    printf("Qual e o id do livro desejado para emprestimo?\n" );
    scanf("%d",&id_livro);
    system(CLEAR);// limpamos o console.
    //struct livros *ant_livros = NULL;
    struct livros *p = busca_livros(cab_livros, id_livro);// verificamos se o livro que o aluno deseja pegar emprestado e valido.
    if(p==NULL){// se nao for
        system(CLEAR);// limpamos o console.
        printf("Livro nao encontrado!\n" );
        return;
    }
    if(p->emprestado==1){// se estiver indisponivel.
        system(CLEAR);// limpamos o console.
        printf("Livro indisponivel para emprestimo no momento!\n" );
        return;
    }
    // se for valido e estiver disponivel.
    q->pendencia=q->pendencia+1;
    p->emprestado=1;
    p->id_aluno = id_aluno;
    system(CLEAR);// limpamos o console.
    printf("Livro emprestado com sucesso!\n");
    return;
}

void devolver_livro(struct livros *cab_livros, struct alunos *cab_alunos){
    printf("Qual e o id do aluno que deseja devolver o livro?\n");
    int id_aluno; 
    scanf("%d",&id_aluno);
    //struct alunos *ant_aluno = cab_alunos;
    struct alunos *p = busca_alunos(cab_alunos,id_aluno);

    if(p==NULL){// se o id do aluno for invalido.
        system(CLEAR);// limpamos o console.
        printf("Aluno nao encontrado!\n");
        return;
    }
    if(p->pendencia==0){// se o aluno que deseja devolver o livro nao tiver pendencias.
        system(CLEAR);// limpamos o console.
        printf("Este aluno nao possui pendencias com a biblioteca!\n");
        return;
    }

    printf("Qual e o id do livro que deseja devolver?\n");
    int id_livro;
    scanf("%d",&id_livro);

    //struct livros *ant_livro = cab_livros;
    struct livros *q = busca_livros(cab_livros,id_livro);// verificamos se o id do livro e valido.

    if(q==NULL){// se nao for.
        system(CLEAR);// limpamos o console
        printf("Livro nao esta cadastrado!\n");
        return;
    }
    if(q->emprestado==0){// se o livro ja se encontrar na biblioteca.
        system(CLEAR);// limpamos o console
        printf("Este livro ja se encontra na biblioteca, por favor, verifique o ID do livro e tente novamente.\n");
    }
    if(q->id_aluno==p->id){// se o id do aluno for o mesmo que pediu o emprestimo do livro.
        p->pendencia = p->pendencia-1; // diminuimos em um as pendencias desse aluno.
        q->emprestado = 0; //o livro volta a ficar disponivel.
        q->id_aluno = -1;
        system(CLEAR);// limpamos o console
        printf("Livro devolvido com sucesso!\n");
    }
    else{
        printf("O aluno que deseja devolver o livro nao e o mesmo que fez o emprestimo. Por favor, tente novamente.\n");
    }
}

void buscar_categoria(struct livros *cab_livros, struct alunos *cab_alunos){
     if (cab_livros->prox == NULL) {// se de cara, o cab - > prox for nulo entao nao ha nada registrado.
        printf("Nao ha livros registrados no sistema!\n");
        return;
    }
    char categoria[100];
    printf("Digite a categoria que deseja buscar: \n");
    limpar(stdin);// limpamos o lixo de stdin.
    fgets(categoria,100,stdin); // lemos a categoria.
    categoria[strcspn(categoria, "\n")] = 0;// retira o '\n' do final.
    
    system(CLEAR);// limpamos o console.
    struct livros *p = cab_livros->prox; // p aponta para o primeiro no valido de livros.
    int encontrado = 0; // funcionara como booleano
    while (p != NULL) {// enquanto for um no valido
        if(strcmp(p->categoria,categoria)==0){// comparamos a categoria, se for a que buscamos, printamos as informacoes associadas ao livro
            encontrado = 1;
            printf("ID: %d\n",  p->id );
            printf("Nome: %s\n",  p->nome );
            printf("Categoria: %s\n",  p->categoria );
            printf("Ano de Publicacao: %d\n",  p->ano_de_publi );
            if(p->emprestado){
                //struct alunos *ant = NULL;
                struct alunos *q = cab_alunos;
                q = busca_alunos(q,p->id);// buscamos as informacoes associadas ao aluno que pediu o emprestimo para mostrar sua matricula.
                if(q!=NULL){
                    printf("Livro esta emprestado emprestado ao aluno de matricula: %s\n" ,q->matricula);
                }
            }
            else{
                printf("Livro esta disponivel para retirada na bilblioteca!\n");
            }
        printf("\n");
        }
        p=p->prox;
    }
    if(encontrado == 0){// se a categoria nao for encontrada apos percorrer a lista encadeada.
        printf("Categoria nao encontrada.\n");
    }
}

void remover_livros(struct livros *cab,int * num_livros) {
    printf("Digite o id do livro que deseja remover:\n" );
    int id;
    scanf("%d",&id);
    limpar(stdin);
    struct livros *ant = cab; // ant aponta para cabeca inicialmente
    struct livros *p = busca_livros2(cab,id,&ant); // buscamos pelo no que possui o id buscado, ant apontara para o no anterior ao que possui o id buscado, caso seja encontrado.

    if (p != NULL && p->emprestado==0) { // se for encontrado e nao estiver emprestado.
        ant->prox = p->prox; // o no anterior aponta para o proximo de p.
        system(CLEAR); // limpamos o console
        printf("O livro %s foi removido com sucesso.\n",p->nome);
        *num_livros= *num_livros - 1; // diminuimos o numero de livros cadastrados 
        free(p); // liberamos a memoria associada ao no excluido.
        return;
    }else if(p == NULL){ // se nao encontrarmos o id que o usuario deseja remover.
        system(CLEAR);
        printf("O ID utilizado nao esta cadastrado, ou entrada invalida.\n" );
        return;
    }
    else if(p->emprestado == 1){ // se encontrarmos o id que o usuario deseja remover, mas o livro estiver atulamente emprestado.
        system(CLEAR);
        printf("O livro %s nao pode ser removido pois esta atualmente emprestado\n",p->nome);
        return;
    }
}
