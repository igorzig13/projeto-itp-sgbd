#ifndef SHOW_TABLE_DATA
#define SHOW_TABLE_DATA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/waitForKeyPress/waitForKeyPress.h"
#include "../../utils/isNameAvailable/isNameAvailable.h"
#include "../../utils/openTableFile/openTableFile.h"
#include "../../utils/countLines/countLines.h"
#include "../../utils/countColumns/countColumns.h"
#include "../../utils/getRowInfo/getRowInfo.h"
#include "../listTables/listTables.h"

void askForTableName();
void showTableData(char *nome);

#endif