#include "deleteTable.h"

void deleteTable(){
    system("clear");
    printf("7. Apagar uma tabela:\n");
    if (listTables(1) != 0){
        return;
    }
    char nome[50];
    printf("\n* Digite o NOME da tabela a ser apagada:\n");
    scanf(" %s", nome);

    char check = ' ';
    while(isNameAvailable(nome) == 0){
        printf("* Atenção: Não foi encontrada uma tabela com esse nome! Tentar novamente? (s/n)");
        scanf(" %c", &check);
        if (check == 's'){
            printf("* Digite o NOME da tabela a ser apagada:\n");
            scanf(" %s", nome);
        } else {
            system("clear");
            printf("* Retornando ao Menu Principal...\n");
            return;
        }
    }

    char caminho[100] = "../tables/";
    strcat(caminho, nome);
    strcat(caminho, ".txt");

    printf("* Atenção: Essa ação deletará permanentemente a tabela %s e todos os seus dados, deseja "
           "prosseguir? (s/n)\n", nome);
    check = ' ';
    scanf(" %c", &check);
    if (check == 's'){
        remove(caminho);
        remove_table(nome);
        system("clear");
        printf("* A tabela %s foi apagada com sucesso. Você retornou ao Menu Principal:\n", nome);
    } else {
        system("clear");
        printf("* Ação cancelada. Voltando ao menu principal...\n");
    }
}