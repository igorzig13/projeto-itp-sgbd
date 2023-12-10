#include "listTables.h"

// Retorna 1 se não encontrar nenhuma Tabela, 0 se encontrar
int listTables(int isMain){
    if (isMain == 0){
        system("clear");
        printf("2. Listar todas as tabelas:\n");
    }
    FILE *arquivo;
    arquivo = fopen("../tables/tableList.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo tableList.txt\n");
        return -1;
    }

    char linha[100];

    if(fgets(linha,sizeof (linha), arquivo) == NULL){
        printf("* Não foi encontrada nenhuma tabela!\n");
        waitForKeyPress();
        return 1;
    } else {
        rewind(arquivo);
        printf("* Foram encontradas as seguintes tabelas no sistema:\n");
        int contador = 1;
        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            linha[strcspn(linha, "\n")] = '\0';
            printf("%d. %s\n", contador, linha);
            contador++;
        }
    }
    fclose(arquivo);
    if (isMain == 0){
        waitForKeyPress();
    }
    return 0;
}
