#include "../include/ast.h"

ast ast_init(int type, char* name, short single_arg, void* arg1, void* arg2) {
  ast new_ast = (ast)malloc(sizeof(struct AbstractSyntaxTree));
  new_ast->type = type;
  new_ast->name = name;
  new_ast->single_arg = single_arg;
  new_ast->arg1 = arg1;
  new_ast->arg2 = arg2;

  return new_ast;
}

// Needs better implementation
void ast_destroy(ast a) {
  destroy(a);
  free(a);
  a = NULL;
}