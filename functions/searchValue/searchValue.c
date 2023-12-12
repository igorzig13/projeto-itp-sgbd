#include "searchValue.h"

void searchValue(){
    system("clear");
    printf("5. Pesquisar valor em uma tabela:\n");
    char nome[100];

    printf("* Digite o nome da tabela:\n");
    scanf(" %[^\n]", nome);

    char check = ' ';
    while (isNameAvailable(nome) == 0){
        printf("* Atenção: Não foi encontrada uma tabela com esse nome! Tentar novamente? (s/n)\n");
        scanf(" %c", &check);
        if (check == 's'){
            printf("* Digite o nome da tabela:\n");
            scanf(" %[^\n]", nome);
        } else {
            system("clear");
            printf("* Você retornou ao Menu Principal...\n");
            return;
        }
    }
    system("clear");

    FILE *arquivo = openTableFile(nome);
    char** tipo_colunas = getRowInfo(arquivo,0);
    rewind(arquivo);
    char** nome_colunas = getRowInfo(arquivo, 1);
    rewind(arquivo);
    int num_colunas = countColumns(nome);

    printf("* Tabela \"%s\" encontrada com sucesso! Ela possui as seguintes colunas:\n\n", nome);
    for (int i = 0; i < num_colunas; i++) {
        printf("%d. %s\n", i+1, nome_colunas[i]);
    }

    int col_escolhida;
    printf("* Selecione uma coluna para fazer a pesquisa (indique o número correspondente):\n");
    scanf(" %d", &col_escolhida);

    while (col_escolhida < 1 || col_escolhida > num_colunas){
        printf(" * Número inválido! Tente novamente:\n");
        scanf(" %d", &col_escolhida);
    }
    col_escolhida--;

    system("clear");
    printf("* Você escolheu a coluna %s, ela possui tipo %s.\n",
           nome_colunas[col_escolhida], tipo_colunas[col_escolhida]);

    char valor_informado[100];
    int opc = 0;
    if (strcmp(tipo_colunas[col_escolhida], "String") == 0){
        opc = 6;
        printf("* Digite um termo para ser pesquisado na coluna %s:\n", nome_colunas[col_escolhida]);
        scanf(" %[^\n]", valor_informado);
    } else {
        printf("* Opções:\n");
        printf("1. Valores maiores que o informado\n");
        printf("2. Valores maiores ou iguais ao informado\n");
        printf("3. Valores iguais ao informado\n");
        printf("4. Valores menores que o informado\n");
        printf("5. Valores menores ou iguais ao informado\n");
        scanf(" %d", &opc);
        while (opc < 1 || opc > 5){
            printf("* Opção inválida! Tente novamente:\n");
            scanf(" %d", &opc);
        }
        printf("* Digite o valor a ser pesquisado:\n");
        scanf(" %[^\n]", valor_informado);
    }

    fclose(arquivo);
    showResults(opc, nome, valor_informado, col_escolhida);
    waitForKeyPress();
}
void showResults(int opc, char* nome_arquivo, char* termo, int num_coluna){
    int num_linhas = countLines(nome_arquivo);
    int num_colunas = countColumns(nome_arquivo);
    FILE *arquivo = openTableFile(nome_arquivo);
    char tipo[20];
    strcpy(tipo,getRowInfo(arquivo,0)[num_coluna]);
    rewind(arquivo);

    char** linha_atual;
    char* valor_atual;

    int aux[2];
    float auxF[2];
    double auxD[2];

    printf("* Os resultados que correspondem ao valor informado são:\n");
    if (strcmp(tipo, "int") == 0){
        aux[0] = atoi(termo);
        for (int i = 2; i < num_linhas; i++) {
            linha_atual = getRowInfo(arquivo, i);
            rewind(arquivo);
            valor_atual = linha_atual[num_coluna];
            aux[1] = atoi(valor_atual);

            if(opc == 1 && aux[1] > aux[0] ||
            opc == 2 && aux[1] >= aux[0] ||
            opc == 3 && aux[1] == aux[0] ||
            opc == 4 && aux[1] < aux[0] ||
            opc == 5 && aux[1] <= aux[0]){
                printLine(arquivo,i,num_colunas);
            }
        }
    } else if (strcmp(tipo, "float") == 0){
        auxF[0] = atof(termo);
        for (int i = 2; i < num_linhas; i++) {
            linha_atual = getRowInfo(arquivo, i);
            rewind(arquivo);
            valor_atual = linha_atual[num_coluna];
            auxF[1] = atof(valor_atual);

            if(opc == 1 && auxF[1] > auxF[0] ||
               opc == 2 && auxF[1] >= auxF[0] ||
               opc == 3 && auxF[1] == auxF[0] ||
               opc == 4 && auxF[1] < auxF[0] ||
               opc == 5 && auxF[1] <= auxF[0]){
                printLine(arquivo,i,num_colunas);
            }
        }
    } else if (strcmp(tipo, "double") == 0){
        auxD[0] = strtod(termo, NULL);
        for (int i = 2; i < num_linhas; i++) {
            linha_atual = getRowInfo(arquivo, i);
            rewind(arquivo);
            valor_atual = linha_atual[num_coluna];
            auxD[1] = strtod(valor_atual, NULL);

            if(opc == 1 && auxD[1] > auxD[0] ||
               opc == 2 && auxD[1] >= auxD[0] ||
               opc == 3 && auxD[1] == auxD[0] ||
               opc == 4 && auxD[1] < auxD[0] ||
               opc == 5 && auxD[1] <= auxD[0]){
                printLine(arquivo,i,num_colunas);
            }
        }
    } else {
        for (int i = 2; i < num_linhas; i++) {
            linha_atual = getRowInfo(arquivo, i);
            rewind(arquivo);
            valor_atual = linha_atual[num_coluna];

            if(opc == 1 && valor_atual[0] > termo[0] ||
               opc == 2 && valor_atual[0] >= termo[0] ||
               opc == 3 && valor_atual[0] == termo[0] ||
               opc == 4 && valor_atual[0] < termo[0] ||
               opc == 5 && valor_atual[0] <= termo[0] ||
               opc == 6 && stringComparator(termo, valor_atual, 4) == 1){
                printLine(arquivo,i,num_colunas);
            }
        }
    }
    fclose(arquivo);
}

void printLine(FILE *arquivo, int linha, int num_colunas){
    char** dados_linha = getRowInfo(arquivo,linha);
    for (int i = 0; i < num_colunas; i++) {
        printf("|%-20s", dados_linha[i]);
    }
    printf("\n");
    rewind(arquivo);
}