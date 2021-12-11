#pragma once

enum TokenType
{
	UNDEFINIED,
	WHITESPACE,
	NUMBER,
	PLUS_OPERATOR,
	MINUS_OPERATOR,
	MULTIPLY_OPERATOR,
	DIVIDE_OPERATOR,
	POWER_OPERATOR,
	OPEN_PARANTHESIS,
	CLOSE_PARANTHESIS,
	END
};

typedef struct TokensData
{
	int maxSize;
	int size;

	TokenType* type;

	char** textValue;
	int* value;

	int* hasValue;
	int* positionInLine;
} TokensData; typedef struct TokenData

TokensData* createTokensData();

void clearTokensData(TokensData* data);

void addToken(TokensData* data, TokenType, char* textValue, int value, int hasValue, int positionInLine);