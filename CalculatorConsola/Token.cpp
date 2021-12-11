#include "Token.h"
#include <iostream>

TokensData* createTokensData()
{
    TokensData* data = new TokenData;

    data->maxSize = 5;
    data->size = 0;
    int maxSize = data->maxSize;

    data->type = (TokenType*)malloc(maxSize * sizeof(TokenType));
    data->textValue = (char**)malloc(maxSize * sizeof(char*));
    data->value = (int*)malloc(maxSize * sizeof(int));
    data->hasValue = (int*)malloc(maxSize * sizeof(int));
    data->positionInLine = (int*)malloc(maxSize * sizeof(int));

    return data;
}
