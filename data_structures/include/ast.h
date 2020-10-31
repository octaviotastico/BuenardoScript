#ifndef AST_H
#define AST_H

#include "T.h"

// struct AbstractSyntaxTreeNode {
//   int type;
//   typeT value;
// };

struct AbstractSyntaxTree {
  int type;
  char* name;
  vector args;
  typeT value;

	/* Destroy ast */
  void (*destroy)(ast);
};


ast ast_init(int type, char* name, vector args, typeT value);

ast ast_node_init(int type, typeT value);

void ast_destroy(ast a);

#endif