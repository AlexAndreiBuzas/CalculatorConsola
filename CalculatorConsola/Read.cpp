#include "Read.h"
#include <iostream>

char* readLine()
{
    char* line = (char*)malloc(1024);
    fgets(line, 1024, stdin);

    return line;
}