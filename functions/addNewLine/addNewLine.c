#include "addNewLine.h"

void addNewLine(){
    system("clear");
    printf("3. Adicionar linha em uma tabela:\n");

    char nome[100];
    if (listTables(1) == 0){
        printf("* Digite o nome da tabela em que você deseja inserir novos dados:\n");
        scanf(" %[^\n]", nome);

        char check = ' ';
        while (isNameAvailable(nome) == 0){
            printf("* Atenção: Não foi encontrada uma tabela com esse nome! Tentar novamente? (s/n)\n");
            scanf(" %c", &check);
            if (check == 's'){
                printf("* Digite o nome da tabela em que você deseja inserir novos dados:\n");
                scanf(" %[^\n]", nome);
            } else {
                system("clear");
                printf("* Retornando ao Menu Principal...\n");
                return;
            }
        }
        system("clear");
        printf("* Adicionando dados à tabela \"%s\":\n", nome);
        FILE *arquivo = openTableFile(nome);

        char **tipos = getRowInfo(arquivo,0);
        rewind(arquivo);
        char **nome_colunas = getRowInfo(arquivo,1);
        char novos_dados[50][50];

        for (int i = 0; tipos[i] != NULL; i++) {
            int aux;
            char auxC;
            float auxF;
            double auxD;
            char auxKey[50];

            if (i == 0){
                printf("* Digite um valor para a coluna %s:\n* ATENÇÃO: esta é a chave primária,"
                       " portanto seu valor deve ser diferente dos já cadastrados!\n",
                       nome_colunas[i]);
                scanf(" %d", &aux);
                sprintf(auxKey,"%d", aux);
                // GARANTE QUE A CHAVE É ÚNICA:
                while (doKeyExists(auxKey, arquivo) != 0){
                    printf("* Erro: Já existe uma chave com esse valor! Tente novamente:\n");
                    scanf(" %d", &aux);
                    sprintf(auxKey,"%d", aux);
                }
                strcpy(novos_dados[i], auxKey);
            } else if (strcmp(tipos[i], "int") == 0){
                printf("* Digite um valor para a coluna %s (tipo: int):\n", nome_colunas[i]);
                scanf(" %d", &aux);
                sprintf(novos_dados[i],"%d", aux);
            } else if (strcmp(tipos[i], "char") == 0){
                printf("* Digite um valor para a coluna %s (tipo: char):\n", nome_colunas[i]);
                scanf(" %c", &auxC);
                sprintf(novos_dados[i],"%c", auxC);
            } else if (strcmp(tipos[i], "float") == 0) {
                printf("* Digite um valor para a coluna %s (tipo: float):\n", nome_colunas[i]);
                scanf(" %f", &auxF);
                sprintf(novos_dados[i], "%.2f", auxF);
            } else if (strcmp(tipos[i], "double") == 0) {
                printf("* Digite um valor para a coluna %s (tipo: double):\n", nome_colunas[i]);
                scanf(" %lf", &auxD);
                sprintf(novos_dados[i], "%.2lf", auxD);
            } else {
                printf("* Digite um valor para a coluna %s (tipo: String):\n", nome_colunas[i]);
                scanf(" %[^\n]", novos_dados[i]);
            }
        }

        for (int i = 0; tipos[i] != NULL ; i++) {
            fputs(novos_dados[i], arquivo);
            fputs("|",arquivo);
        }
        fputs("\n",arquivo);
        fclose(arquivo);
    }
}
// Função deve retornar 1 se encontrar outra chave no sistema com o mesmo valor
int doKeyExists(char* chave, FILE *arquivo){
    char linha[1000];
    char valor[50];
    rewind(arquivo);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        strcpy(valor, strtok(linha,"|"));
        if(strcmp(chave,valor) == 0){
            return 1;
        }
    }
    return 0;
}
