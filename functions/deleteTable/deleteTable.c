#include "deleteTable.h"

void deleteTable(){
    system("clear");
    printf("7. Apagar uma tabela:\n");
    // TODO: USAR FUNÇÃO DE LISTAR TABELAS AQUI!
    char nome[50];
    printf("* Digite o nome da tabela a ser apagada:\n");
    scanf(" %s", nome);

    char caminho[100] = "../tables/";
    strcat(caminho, nome);
    strcat(caminho, ".txt");

    printf("* Atenção: Essa ação deletará permanentemente a tabela %s e todos os seus dados, deseja "
           "prosseguir? (s/n)\n", nome);
    char confirmacao = ' ';
    scanf(" %c", &confirmacao);
    if (confirmacao == 's'){
        remove(caminho);
        remove_table(nome);
    } else {
        printf("* Ação cancelada. Voltando ao menu principal...\n");
    }
}