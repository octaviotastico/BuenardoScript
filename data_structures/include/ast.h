#ifndef AST_H
#define AST_H

#include "T.h"

struct AbstractSyntaxTree {
  int type;
  char* name;
  short single_arg;
  void* arg1;
  void* arg2;

	/* Destroy ast */
  void (*destroy)(ast);
};


ast ast_init(int type, char* name, short single_arg, void* arg1, void* arg2);

void ast_destroy(ast a);

#endif