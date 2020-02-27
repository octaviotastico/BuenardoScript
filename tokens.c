#include <stdio.h>
#include "stack.h"

///// Tokens /////
typedef struct Tokens* token;

typedef enum {
  Name,
  Number,
  String,
  Parenthesis
} TokenType;

struct Tokens {
  TokenType type;
  char* value;
};

///// AST /////
typedef enum {
  CallExpression,
  NumericAtom,
  StringAtom,
  Identifier
} ParserType;

typedef struct AbstractSyntaxTree* ast;

struct AbstractSyntaxTree {
  ParserType type;
  char* name;
  void* arguments; // This could be an ast or a node
};

typedef struct AbstractSyntaxTreeLeaf* node;

struct AbstractSyntaxTreeLeaf {
  char* type;
  char* value;
};

void parse(stack tokens) {

  // TODO: Recursion with AbstractSyntaxTree, if its not a list.

  struct Tokens token = top(tokens); // TODO: Add new types to data.h

  if (token.type == Number) {
    struct AbstractSyntaxTreeLeaf leaf;
    leaf.type = NumericAtom;
    leaf.value = token.value;
    return leaf;
  }

  if (token.type == String) {
    struct AbstractSyntaxTreeLeaf leaf;
    leaf.type = StringAtom;
    leaf.value = token.value;
    return leaf;
  }

  if (token.type == Name) {
    struct AbstractSyntaxTreeLeaf leaf;
    leaf.type = Identifier;
    leaf.value = token.value;
    return leaf;
  }
}

int main() {
  struct AbstractSyntaxTree abbb;
  abbb.name = "asdas";
  abbb.type = StringAtom;
  printf("%s\n",abbb.name);
  printf("%d\n",abbb.type);
  return 0;
}