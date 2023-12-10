#include "tableToFile.h"

void tableToFile(char* nome, int qtd_colunas, char nome_colunas[qtd_colunas][50], char
tipo_colunas[qtd_colunas][20]){

    char nome_txt[strlen(nome)+ 5];
    strcpy(nome_txt,nome);
    strcat(nome_txt, ".txt");
    char caminho[] = "../tables/";
    size_t tamanho = strlen(nome_txt) + strlen(caminho);
    char endereco[tamanho + 1];

    strcpy(endereco, caminho);
    strcat(endereco, nome_txt);

    FILE *arquivo;
    arquivo = fopen(endereco, "w");
    if(arquivo == NULL){
        printf("* Erro ao gerar o arquivo.\n");
        return;
    }
    for(int i = 0; i < qtd_colunas; i++){
        fprintf(arquivo, "%s|", tipo_colunas[i]);
    }
    fprintf(arquivo, "\n");
    for(int i = 0; i < qtd_colunas; i++){
        fprintf(arquivo, "%s|", nome_colunas[i]);
    }
    fprintf(arquivo,"\n");

    fclose(arquivo);

}