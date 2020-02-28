#ifndef TOKEN_H
#define TOKEN_H

#include "T.h"

typedef struct Tokens* token;

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

struct Tokens {
  TokenTypeT type;
  char* value;
};

#endif