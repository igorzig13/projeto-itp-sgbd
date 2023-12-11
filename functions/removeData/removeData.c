#include "removeData.h"
#include "../addNewLine/addNewLine.h"

void removeData(){
    system("clear");
    printf("6. Remover linha ou coluna de uma tabela:\n");

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
        deleteRow(nome, nome_chave);
    }
}
void deleteRow(char* nome, char* key){
    FILE *arquivo = openTableFile(nome);
    FILE *arquivoTemp = openTableFile("arquivoTemp");

    char linha[1000];
    // TODO: Ver se está funcionando como esperado:
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (doKeyExists(key, arquivo) == 0){
            fprintf(arquivoTemp, "%s\n", linha);
        }
    }
    fclose(arquivoTemp);
    fclose(arquivo);
}