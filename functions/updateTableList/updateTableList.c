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
    char nome_arquivo[] = "../tables/tableList.txt";
    arquivo = fopen(nome_arquivo, "r");
    char nome_arquivoTemp[] = "../tables/arquivoTemp.txt";
    FILE *arquivoTemp = fopen(nome_arquivoTemp, "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo tableList.txt\n");
        return;
    }
    if (arquivoTemp == NULL) {
        perror("Erro ao criar o arquivo temporário\n");
        fclose(arquivo);
        return;
    }

    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        if (strcmp(linha, nome) != 0){
            fprintf(arquivoTemp, "%s\n", linha);
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    remove(nome_arquivo);

    if (rename(nome_arquivoTemp, nome_arquivo) != 0) {
        perror("Erro ao renomear o arquivo temporário");
    }
}
