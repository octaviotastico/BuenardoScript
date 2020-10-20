#ifndef AST_H
#define AST_H

#include "T.h"

struct AbstractSyntaxTree {
  int type;
  char* name;
  short single_arg;
  typeT arg1;
  typeT arg2;

	/* Destroy ast */
  void (*destroy)(ast);
};


ast ast_init(int type, char* name, short single_arg, typeT arg1, typeT arg2);

void ast_destroy(ast a);

#endif