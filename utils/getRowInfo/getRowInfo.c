#include "getRowInfo.h"

char** getRowInfo(FILE *arquivo, int line_number) {
    char **dados = malloc(MAX_COLUMNS * sizeof(char*));
    char linha[1000];

    for (int i = 0; i <= line_number; i++) {
        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            linha[strcspn(linha, "\n")] = '\0';
        }
    }

    int contador = 0;
    char *getInfo = strtok(linha, "|");

    while (getInfo != NULL && contador < MAX_COLUMNS) {
        dados[contador] = malloc((strlen(getInfo) + 1) * sizeof(char));

        strcpy(dados[contador], getInfo);
        contador++;
        getInfo = strtok(NULL, "|");
    }

    dados[contador] = NULL;

    return dados;
}
