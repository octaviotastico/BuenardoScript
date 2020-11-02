#include "execute.h"

ast execute(ast programTree) {
  int type = programTree->type;
  char* name = programTree->name;

  if (type == String || type == Number) { // Atoms
    return programTree;
  }

  if (type == FunctionCall) {
    vector real_args = programTree->args;
    vector unzipped_args = vector_init(AST, 1);
    for(int i = 0; i < size(real_args); i++) {
      ast arg_i = execute(at(real_args, i)->value.a);
      push_back(unzipped_args, arg_i);
    }
    ast res = execute_predef_function(name, unzipped_args);
    return res;
  }
}