#include "Cabecalho.h"
#include "operacoes_alunos.h"
#include "operacoes_livros.h"
#include "operacoes_infra.h"
#include "salvar_tipos.h"
#include "carregar_tipos.h"

int main() {
   // No cabeca sera utilizado como no auxiliar (sem conteudo).
    struct alunos *cab_alunos = (struct alunos *)malloc(sizeof(struct alunos)); // alocamos a memoria para o no cabeca.
    cab_alunos->prox = NULL;
    int id_alunos = 0; // id alunos e a variavel que dara id automatico aos alunos.
    int num_alunos = 0; // num alunos indicara quantos alunos estao atualmente registrados na biblioteca.
    ler_alunos(cab_alunos,&num_alunos,&id_alunos); // lemos da memoria os alunos previamente cadastrados.


    struct livros *cab_livros = (struct livros *)malloc(sizeof(struct livros)); // alocamos a memoria para o no cabeca.
    cab_livros->prox = NULL;
    int id_livros = 0;// id livros e a variavel que dara id automatico aos livros.
    int num_livros = 0;// id livros e a variavel que dara id automatico aos livros.
    ler_livros(cab_livros,&num_livros,&id_livros);// lemos da memoria os livros previamente cadastrados.

    struct infra *cab_infra = (struct infra *)malloc(sizeof(struct infra));// alocamos a memoria para o no cabeca.
    cab_infra->prox = NULL;
    int num_infra = 0; // num infra indicara quantas infraestruturas estao atualmente registradas na biblioteca.
    ler_infra(cab_infra,&num_infra); //lemos da memoria as infraestruturas previamente cadastradas.

    int acao;
    while(acao!=20){
        printf("Que acao voce deseja realizar?\n");
        printf("\n");
        printf("1 - Registrar um aluno\n");
        printf("2 - Imprimir todos os alunos\n");
        printf("3 - Buscar um aluno por id\n");
        printf("4 - Remover um aluno\n");
        printf("\n");
        printf("5 - Registrar um livro\n");
        printf("6 - Buscar um livro por id\n");
        printf("7 - Buscar livros por categoria\n");
        printf("8 - Imprimir todos os livros\n");
        printf("9 - Emprestar um livro\n");
        printf("10 - Devolver um livro\n");
        printf("11 - Remover um livro\n");
        printf("\n");
        printf("12 - Registrar nova sala, computador ou armario\n");
        printf("13 - Remover sala, computador ou armario\n");
        printf("14 - Imprimir todas infraestruturas\n");
        printf("15 - Emprestar infraestrutura\n");
        printf("16 - Devolver infraestrutura\n");
        printf("17 - Imprimir infraestrutura por tipo\n");
        printf("18 - Imprimir infraestrutura por ID\n");
        printf("\n");
        printf("19 - Informacoes do projeto no GitHub\n");
        printf("\n");
        printf("20 - Fechar o programa\n");
        scanf("%d",&acao);
        switch(acao){
        default:
                system(CLEAR);
                printf("digite uma opcao valida, por favor\n");
            case(1):
                system(CLEAR);
                inserir_alunos(cab_alunos,&id_alunos,&num_alunos);
                break;

            case(2):
                system(CLEAR);
                imprimir_alunos(cab_alunos);
                break;

            case(3):
                system(CLEAR);
                imprimir_aluno(cab_alunos);
                break;

            case(4):
                system(CLEAR);
                remover_alunos(cab_alunos,&num_alunos);
                break;

            case(5):
                system(CLEAR);
                inserir_livros(cab_livros,&id_livros,&num_livros);
                break;

            case(6):
                system(CLEAR);
                imprimir_livro(cab_livros,cab_alunos);
                break;

            case(7):
                system(CLEAR);
                buscar_categoria(cab_livros,cab_alunos);
                break;

            case(8):
                system(CLEAR);
                imprimir_livros(cab_livros,cab_alunos);
                break;

            case(9):
                system(CLEAR);
                emprestar_livro(cab_livros,cab_alunos);
                break;

            case(10):
                system(CLEAR);
                devolver_livro(cab_livros,cab_alunos);
                break;
            case(11):
            	system(CLEAR);
            	remover_livros(cab_livros,&num_livros);
            	break;
            case(12):
                system(CLEAR);
                inserir_infra(cab_infra,&num_infra);
                break;

            case(13):
                system(CLEAR);
                remover_infra(cab_infra,&num_infra);
                break;

            case(14):
                system(CLEAR);
                imprimir_infra(cab_infra,cab_alunos);
                break;

            case(15):
                system(CLEAR);
                emprestar_infra(cab_infra,cab_alunos);
                break;

            case(16):
                system(CLEAR);
                devolver_infra(cab_infra,cab_alunos);
                break;

            case(17):
                system(CLEAR);
                imprime_infra_por_tipo(cab_infra,cab_alunos);
                break;
            case(18):
                system(CLEAR);
                buscar_infra_por_id(cab_infra,cab_alunos);
                break;
            case(19):
                system(CLEAR);
                printf("Voce pode encontrar o codigo fonte e a documentacao desse projeto\n");
                printf("no meu repositorio do GitHub: https://github.com/P3dream/Sistema_biblioteca\n");
                printf("\n");
             case(20):
                salvar_alunos(cab_alunos,&num_alunos,&id_alunos); // salvamos os alunos cadastrados na memoria
                salvar_livros(cab_livros,&num_livros,&id_livros); // salvamos os livros cadastrados na memoria
                salvar_infra(cab_infra,&num_infra); // salvamos as infraestruturas cadastradas na memoria
                break;
        }
    }
    free(cab_alunos);
    free(cab_livros);
    free(cab_infra);
    return 0;
}
