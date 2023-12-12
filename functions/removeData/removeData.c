#include "removeData.h"
#include "../addNewLine/addNewLine.h"
#include "../showTableData/showTableData.h"

void removeData(){
    system("clear");
    printf("6. Remover um registro de uma tabela:\n");

    char nome[100];
    char chave_primaria[50];
    if (listTables(1) == 0){
        printf("* Digite o nome da tabela na qual você deseja apagar dados:\n");
        scanf(" %[^\n]", nome);

        char check = ' ';
        while (isNameAvailable(nome) == 0){
            printf("* Atenção: Não foi encontrada uma tabela com esse nome! Tentar novamente? (s/n)\n");
            scanf(" %c", &check);
            if (check == 's'){
                printf("* Digite o nome da tabela na qual você deseja apagar dados:\n");
                scanf(" %[^\n]", nome);
            } else {
                system("clear");
                printf("* Retornando ao Menu Principal...\n");
                return;
            }
        }

        system("clear");
        check = ' ';
        printf("* Deseja antes exibir os dados da tabela %s? (s/n)\n ", nome);
        scanf(" %c", &check);
        if (check == 's'){
            showTableData(nome);
        }
        FILE *arquivo = openTableFile(nome);
        char* nome_chave = getRowInfo(arquivo, 1)[0];
        printf("* A chave primária da tabela %s é dada pela coluna %s, digite a chave do registro que "
               "gostaria de apagar:\n", nome, nome_chave);

        int aux;
        scanf(" %d", &aux);
        sprintf(chave_primaria, "%d", aux);
        int contador_tentativas = 0;

        while(doKeyExists(chave_primaria, arquivo) != 1){
            printf("* Chave não encontrada. Tente novamente:\n");
            scanf(" %d", &aux);
            sprintf(chave_primaria, "%d", aux);
            contador_tentativas++;
            if (contador_tentativas >= 3){
                printf("* Operação falhou.\n");
                waitForKeyPress();
                fclose(arquivo);
                return;
            }
        }

        fclose(arquivo);
        deleteRow(nome, chave_primaria);
    }
}
void deleteRow(char* nome, char* key){
    FILE *arquivo = openTableFile(nome);
    FILE *arquivoTemp = openTableFile("arquivoTemp");

    char linha[1000];
    char stringAux[1000];
    char *comparador;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        strcpy(stringAux, linha);
        comparador = strtok(stringAux,"|");
        if (strcmp(comparador, key) != 0){
            fprintf(arquivoTemp, "%s", linha);
        }
    }
    fclose(arquivoTemp);
    fclose(arquivo);

    char endereco[100] = "../tables/";
    strcat(endereco, nome);
    strcat(endereco, ".txt");

    remove(endereco);

    if (rename("../tables/arquivoTemp.txt", endereco) != 0) {
        perror("Erro ao renomear o arquivo temporário");
    }
    printf("* A tabela %s foi atualizada com sucesso.\n", nome);
    waitForKeyPress();
}