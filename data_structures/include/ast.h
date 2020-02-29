#ifndef AST_H
#define AST_H

#include "T.h"

typedef union ParserType {
  char* CallExpression;
  int NumericAtom;
  char* StringAtom;
  char* Identifier;
} ParserType;

typedef enum ParserTypeT {
  CallExpression,
  NumericAtom,
  StringAtom,
  Identifier
} ParserTypeT;

typedef struct AbstractSyntaxTree* ast;

struct AbstractSyntaxTree {
  ParserTypeT type;
  char* name;
  vector arguments;
};

typedef struct AbstractSyntaxTreeLeaf* ast_node;

struct AbstractSyntaxTreeLeaf {
  ParserTypeT type;
  typeT value;
};

ast ast_init(ParserTypeT, char*, typeT);

ast_node ast_node_init(ParserTypeT, typeT);

#endif