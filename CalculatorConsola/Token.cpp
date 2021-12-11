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

void clearTokensData(TokensData* data)
{
    for (int j = 0; j < sizeof(data->textValue) / sizeof(char*); j++)
        free(data->textValue[j]);

    free(data->type);
    free(data->textValue);
    free(data->value);
    free(data->hasValue);
    free(data->positionInLine);

    free(data);
}

void addToken(TokensData* data, TokenType type, char* textValue, double value, int hasValue, int positionInLine)
{
    if (data->size == data->maxSize)
    {
        data->maxSize += 10;
        int maxSize = data->maxSize;

        data->type = (TokenType*)realloc(data->type, maxSize * sizeof(TokenType));
        data->textValue = (char**)realloc(data->textValue, maxSize * sizeof(char*));
        data->value = (double*)realloc(data->value, maxSize * sizeof(double));
        data->hasValue = (int*)realloc(data->hasValue, maxSize * sizeof(int));
        data->positionInLine = (int*)realloc(data->positionInLine, maxSize * sizeof(int));
    }
    int size = data->size;

    data->type[size] = type;
    data->textValue[size] = textValue;
    data->value[size] = value;
    data->hasValue[size] = hasValue;
    data->positionInLine[size] = positionInLine;

    data->size++;
}