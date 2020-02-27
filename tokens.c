#include <stdio.h>

///// Tokens /////
typedef struct Tokens* token;

typedef enum {
  Int,
  Name,
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

int main() {
  struct AbstractSyntaxTree abbb;
  abbb.name = "asdas";
  abbb.type = StringAtom;
  printf("%s\n",abbb.name);
  printf("%d\n",abbb.type);
  return 0;
}