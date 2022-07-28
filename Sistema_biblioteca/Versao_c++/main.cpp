#include "Cabecalho.h"

int main() {
   // No cabeca sendo utilizado como auxiliar (sem conteudo).
    struct alunos *cab_alunos = new alunos();//(struct alunos *)malloc(sizeof(struct alunos));
    cab_alunos->prox = NULL;
    int id_alunos = 0;
    int num_alunos = 0;
    ler_alunos(cab_alunos,&num_alunos,&id_alunos);


    struct livros *cab_livros = new livros();//(struct livros *)malloc(sizeof(struct livros));
    cab_livros->prox = NULL;
    int id_livros = 0;
    int num_livros = 0;
    ler_livros(cab_livros,&num_livros,&id_livros);

    struct infra *cab_infra = new infra();//(struct infra *)malloc(sizeof(struct infra));
    cab_infra->prox = NULL;
    int num_infra = 0;
    ler_infra(cab_infra,&num_infra);

    int acao;
    while(acao!=20){
        cout << "Que acao voce deseja realizar?" << endl;
        cout << endl;
        cout << "1 - Registrar um aluno" << endl;
        cout << "2 - Imprimir todos os alunos" << endl;
        cout << "3 - Buscar um aluno" << endl;
        cout << "4 - Remover um aluno" << endl;
        cout << endl;
        cout << "5 - Registrar um livro" << endl;
        cout << "6 - Buscar um livro por id" << endl;
        cout << "7 - Buscar livros por categoria" << endl;
        cout << "8 - Imprimir todos os livros" << endl;
        cout << "9 - Emprestar um livro" << endl;
        cout << "10 - Devolver um livro" << endl;
        cout << "11 - Remover um livro" << endl;
        cout << endl;
        cout << "12 - Registrar nova sala, computador ou armario" << endl;
        cout << "13 - Remover sala, computador ou armario" << endl;
        cout << "14 - Imprimir todas infraestruturas" << endl;
        cout << "15 - Emprestar infraestrutura" << endl;
        cout << "16 - Devolver infraestrutura" << endl;
        cout << "17 - Imprimir infraestrutura por tipo" << endl;
        cout << "18 - Imprimir infraestrutura por ID" << endl;
        cout  << endl;
        cout << "19 - Informacoes do projeto no GitHub" << endl;
        cout << endl;
        cout << "20 - Fechar o programa" << endl;
        cin >> acao;
        switch(acao){
        default:
                system(CLEAR);
                cout << "digite uma opcao valida, por favor" << endl;
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
                cout << "Voce pode encontrar o codigo fonte e a documentacao desse projeto" << endl;
                cout << "no meu repositorio do GitHub: https://github.com/P3dream/AEDS1_" << endl;
             case(20):
                salvar_alunos(cab_alunos,&num_alunos,&id_alunos);
                salvar_livros(cab_livros,&num_livros,&id_livros);
                salvar_infra(cab_infra,&num_infra);
                break;
        }
    }
    free(cab_alunos);
    free(cab_livros);
    free(cab_infra);
    return 0;
}
