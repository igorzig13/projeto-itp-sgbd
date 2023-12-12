#include "countColumns.h"

int countColumns(char* tableName){
    FILE *arquivo = openTableFile(tableName);

    char linha[1000];
    char *aux;
    int contador = 0;
    if (fgets(linha, sizeof(linha), arquivo) != NULL){
        aux = strtok(linha,"|");
    } else {
        printf("* Erro ao contar colunas da tabela.\n");
        return -1;
    }
    while (aux != NULL){
        contador++;
        aux = strtok(NULL, "|");
    }

    fclose(arquivo);
    return contador-1;
}