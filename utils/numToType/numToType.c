#include "numToType.h"

char* numToType (){
    char c = ' ';
    scanf(" %c", &c);
    switch (c) {
        case '1':
            return "char";
        case '2':
            return "int";
        case '3':
            return "float";
        case '4':
            return "double";
        case '5':
            return "String";
        default:
            printf("Tipo inválido! Tente novamente:\n");
            return numToType();
    }
}