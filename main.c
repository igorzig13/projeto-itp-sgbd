#include "main.h"

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
                listTables(0);
                break;
            case '3':
                addNewLine();
                break;
            case '4':
                askForTableName();
                break;
            case '5':
                searchValue();
                break;
            case '6':
                removeData();
                break;
            case '7':
                deleteTable();
                break;
            case '8':
                // encerrar o programa
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
