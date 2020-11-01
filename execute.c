#include "execute.h"

typeT execute(ast programTree) {
  zip_ast(programTree);
}

ast zip_ast(ast programTree) {
  int type = programTree->type;
  char* name = programTree->name;

  if (type == String || type == Number) { // Atoms
    return programTree;
  }

  if (type == FunctionCall) {
    vector zipped_args = vector_init(AST, 1); // args are AST nodes
    vector unzipped_args = programTree->args;
    for(int i = 0; i < size(unzipped_args); i++) {
      ast arg_i = at(unzipped_args, i)->value.a;
      ast arg_i_val = zip_ast(arg_i);
      push_back(zipped_args, arg_i_val);
    }
    printf("%s", name);
    execute_predef_function(name, zipped_args);
    printf("All went good :)");
  }
}