#include "execute.h"

typeT execute(ast programTree) {
  char* functionName = programTree->name;
  // vector functionArguments = zip_ast(programTree);
  zip_ast(programTree);
}

typeT zip_ast(ast programTree) {
  int type = programTree->type;

  if (type == String) {
    // return (programTree->value)->value.string; // Value of TypeT
    return (programTree->value); // TypeT
  }

  if (type == Number) {
    // return (programTree->value)->value.number; // Value of TypeT
    return (programTree->value); // TypeT
  }

  if (type == FunctionCall) {
    vector zipped_args = vector_init(TypeT, 1); // args are AST nodes
    vector unzipped_args = programTree->args;
    for(int i = 0; i < size(unzipped_args); i++) {
      ast arg_i = at(unzipped_args, i)->value.a;
      push_back(zipped_args, *zip_ast(arg_i));
      // push_back(zipped_args, arg_i);
    }
    return T_init(Vector, zipped_args);
  }
}