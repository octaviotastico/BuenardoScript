#include <stdio.h>
#include "data.h"

typeT parse(vector tokens) {

  token t = at(tokens, 0);
  pop_back(tokens);

  if (t->type == Number) {
    ast_node leaf = ast_node_init(NumericAtom, t->value);
    return leaf;
  }

  if (t->type == String) {
    ast_node leaf = ast_node_init(StringAtom, t->value);
    return leaf;
  }

  if (t->type == Name) {
    ast tree = ast_init(Identifier, t->value, parse(tokens));
    return tree;
  }
}