#include "showTableData.h"

void askForTableName(){
    system("clear");
    printf("4. Listar todos os dados de uma tabela:\n");
    char nome[100];

    if(listTables(1) == 0){
        printf("* Digite o nome da tabela que você deseja exibir:\n");
        scanf(" %[^\n]", nome);

        char check = ' ';
        while (isNameAvailable(nome) == 0){
            printf("* Atenção: Não foi encontrada uma tabela com esse nome! Tentar novamente? (s/n)\n");
            scanf(" %c", &check);
            if (check == 's'){
                printf("* Digite o nome da tabela que você deseja exibir:\n");
                scanf(" %[^\n]", nome);
            } else {
                system("clear");
                printf("* Retornando ao Menu Principal...\n");
                return;
            }
        }
        system("clear");

        printf("* Tabela \"%s\" encontrada com sucesso! Dados:\n\n", nome);
        showTableData(nome);
        waitForKeyPress();
    }
}

void showTableData(char *nome){
    FILE *arquivo = openTableFile(nome);
    int numLinhas = countLines(nome);
    int numColunas = countColumns(nome);
    char **dados_linha;

    for (int i = 1; i < numLinhas; i++) {
        dados_linha = getRowInfo(arquivo,i);
        for (int j = 0; j < numColunas; j++) {
            printf("|%-20s", dados_linha[j]);
        }
        printf("\n");
        rewind(arquivo);
    }
    fclose(arquivo);
}