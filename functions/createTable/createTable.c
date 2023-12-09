#include "createTable.h"

int qtdColunas = 0;
char nomeTabela[50];

void createTable(){
    system("clear");
    printf("* Digite um nome para a tabela que será criada:\n");
    scanf(" %[^\n]", nomeTabela); //TODO PRECISA CHECAR SE JÁ EXISTE UMA TABELA COM ESSE NOME!
    printf("* Digite a quantidade de colunas que a tabela terá: (Lembre-se, é necessário pelo menos "
           "uma coluna para guardar a chave primária!)\n");
    while (qtdColunas < 1){
        scanf(" %d", &qtdColunas);
        if (qtdColunas < 1){
            printf("* O valor digitado é menor do que 1! Tente novamente:\n");
        }
    }
    char nome_colunas[qtdColunas][50]; // Só funciona com nomes de até 49 caracteres!
    char tipo_colunas[qtdColunas][20];
    for (int i = 0; i < qtdColunas; i++) {
        if (i == 0){
            printf("* Digite um nome para a coluna 1 (será a CHAVE PRIMÁRIA):\n");
            scanf(" %[^\n]", nome_colunas[i]);
            strcpy(tipo_colunas[0], "int");
        } else {
            printf("* Digite um nome para a coluna %d:\n", i + 1);
            scanf(" %[^\n]", nome_colunas[i]);
            printf("* Escolha o tipo de dado para a coluna %d. Opções:\n", i + 1);
            printf("1. char\n2. int\n3. float\n4. double\n5. string\n");
            strcpy(tipo_colunas[i], numToType());
        }
    }

    // TODO: IMPLEMENTAR A FUNÇÃO ABAIXO
    tableToFile(nomeTabela, qtdColunas, nome_colunas, tipo_colunas);

    printf("* A tabela %s foi criada!\nDigite qualquer tecla para voltar ao menu principal.\n",
           nomeTabela);
    char aux = ' ';
    scanf(" %c", &aux);
    system("clear");
}