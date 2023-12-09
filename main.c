#include <stdio.h>
#include <stdlib.h>
#include "utils/mainMenu/mainMenu.h"
#include "functions/createTable/createTable.h"

int main() {
    char op = '0';
    char confirmaSaida = ' ';

    system("clear");
    while (1){
        mainMenu();
        scanf(" %c", &op);
        switch (op) {
            case '1':
                createTable();
                break;
            case '2':
                // manda para função que lista todas as tabelas
                break;
            case '3':
                // manda para função que cria uma nova linha na tabela
                break;
            case '4':
                // manda para função que lista todos os dados de uma tabela
                break;
            case '5':
                // manda para função que pesquisa um valor em uma tabela
                break;
            case '6':
                // manda para função que apaga uma tupla (coluna ou linha) de uma tabela
                break;
            case '7':
                // manda para função que apaga uma tabela.
                break;
            case '8':
                // deve encerrar o programa
                printf("* Deseja realmente sair? (s/n)\n");
                scanf(" %c", &confirmaSaida);
                if (confirmaSaida == 's'){
                    return 0;
                } else {
                    system("clear");
                    break;
                }
            default:
                system("clear");
                printf("* Opção inválida! Tente novamente:\n");
                break;
        }
    }
}
