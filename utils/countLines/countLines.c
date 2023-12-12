#include "countLines.h"

// Conta as linhas de um arquivo de tabela e retorna
int countLines(char* tableName){

    FILE *arquivo = openTableFile(tableName);
    rewind(arquivo);
    char linha[1000];
    int contador = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }

    fclose(arquivo);
    return contador;
}