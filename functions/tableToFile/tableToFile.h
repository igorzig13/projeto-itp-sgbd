#ifndef TABLE_TO_FILE
#define TABLE_TO_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tableToFile(char* nome, int qtd_colunas, char (*nome_colunas)[qtd_colunas], char (*
tipo_colunas)[qtd_colunas]);

#endif