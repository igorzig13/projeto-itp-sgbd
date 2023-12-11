#ifndef REMOVE_DATA
#define REMOVE_DATA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/waitForKeyPress/waitForKeyPress.h"
#include "../listTables/listTables.h"
#include "../../utils/isNameAvailable/isNameAvailable.h"
#include "../../utils/openTableFile/openTableFile.h"
#include "../../utils/getRowInfo/getRowInfo.h"

void removeData();
void deleteRow(char* nome, char* key);

#endif