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
  void* arguments; // This could be an ast or a node
};

typedef struct AbstractSyntaxTreeLeaf* node;

struct AbstractSyntaxTreeLeaf {
  char* type;
  char* value;
};

#endif