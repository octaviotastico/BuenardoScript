#ifndef TOKEN_H
#define TOKEN_H

#include "T.h"

typedef union TokenType {
  char* Name;
  int Number;
  char* String;
  char Parenthesis;
} TokenType;

typedef enum TokenTypeT {
  Name,
  Number,
  String,
  Parenthesis
} TokenTypeT;

typedef struct Tokens* token;

struct Tokens {
  TokenTypeT type;
  typeT value;
};

token create_token(TokenTypeT, typeT);

#endif