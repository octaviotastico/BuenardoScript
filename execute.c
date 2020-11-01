#include "execute.h"

typeT execute(ast programTree) {
  zip_ast(programTree);
}

ast zip_ast(ast programTree) {
  int type = programTree->type;
  char* name = programTree->name;

  if (type == String || type == Number) { // Atoms
    // printf("ARGGSSS %d\n", programTree->value->value.number);
    return programTree;
  }

  if (type == FunctionCall) {
    vector real_args = programTree->args;
    vector unzipped_args = vector_init(AST, 1);
    for(int i = 0; i < size(real_args); i++) {
      ast arg_i = zip_ast(at(real_args, i)->value.a);
      push_back(unzipped_args, arg_i);
    }
    // printf("%s\n", name);
    execute_predef_function(name, unzipped_args);
  }
}