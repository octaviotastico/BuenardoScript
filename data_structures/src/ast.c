#include "../include/ast.h"

ast ast_init(int type, char* name, vector args, typeT value) {
  ast new_ast = (ast)malloc(sizeof(struct AbstractSyntaxTree));
  new_ast->type = type;
  new_ast->name = name;
  new_ast->args = args;
  new_ast->value = value;

  return new_ast;
}

ast ast_node_init(int type, typeT value) {
  return ast_init(type, NULL, NULL, value);
}

// Needs better implementation
void ast_destroy(ast a) {
  destroy(a);
  free(a);
  a = NULL;
}