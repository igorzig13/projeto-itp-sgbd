#include "isNameAvailable.h"

// Função para checar se o nome passado como parâmetro já está presente no tableList.txt, se já
// existir retorna 1, se não, retorna 0.
int isNameAvailable(char* nome){
    FILE *arquivo;
    arquivo = fopen("../tables/tableList.txt", "a+");
    rewind(arquivo);

    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        if (strcmp(linha, nome) == 0){
            return 1;
        }
    }

    return 0;
}