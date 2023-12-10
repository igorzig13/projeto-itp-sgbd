#include "openTableFile.h"

// Abre um arquivo de uma tabela no modo a+ (leitura e escrita ao fim do arquivo)
FILE* openTableFile(char* nome){
    FILE *arquivo;
    char endereco[100] = "../tables/";
    strcat(endereco, nome);
    strcat(endereco, ".txt");
    arquivo = fopen(endereco, "a+");

    if(arquivo == NULL){
        printf("* Erro ao abrir o arquivo %s.\n", endereco);
        return NULL;
    }
    return arquivo;
}