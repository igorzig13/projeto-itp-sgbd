#include "updateTableList.h"



void add_table(char* nome){
    FILE *arquivo;
    arquivo = fopen("../tables/tableList.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao abrir/criar o arquivo tableList.txt\n");
        return;
    }

    fprintf(arquivo, "%s\n", nome);

    fclose(arquivo);

}
// TODO: FUNÇÃO AINDA PRECISA SER IMPLEMENTADA
void remove_table(char *nome){
    FILE *arquivo;
    arquivo = fopen("../tables/tableList.txt", "a");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo tableList.txt\n");
        return;
    }
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        if (strcmp(linha, nome) == 0){

        }
    }

    fclose(arquivo);

}
