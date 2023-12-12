#ifndef SEARCH_VALUE
#define SEARCH_VALUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/waitForKeyPress/waitForKeyPress.h"
#include "../../utils/isNameAvailable/isNameAvailable.h"
#include "../../utils/openTableFile/openTableFile.h"
#include "../../utils/countLines/countLines.h"
#include "../../utils/countColumns/countColumns.h"
#include "../../utils/getRowInfo/getRowInfo.h"
#include "../../utils/stringComparator/stringComparator.h"
#include "../listTables/listTables.h"

void searchValue();
void showResults(int opc, char* nome_arquivo, char* termo, int num_coluna);
void printLine(FILE *arquivo, int linha, int num_colunas);

#endif