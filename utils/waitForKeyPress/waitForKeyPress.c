#include "waitForKeyPress.h"

void waitForKeyPress(){
    printf("\n* Digite qualquer tecla para voltar ao Menu Principal.\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
    system("clear");
}