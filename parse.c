#include <stdio.h>
#include "data.h"

void parse(stack tokens) {

  // TODO: Recursion with AbstractSyntaxTree, if its not a list.

  struct Tokens token = top(tokens); // TODO: Add new types to data.h

  if (token.type == Number) {
    struct AbstractSyntaxTreeLeaf leaf;
    leaf.type = NumericAtom;
    leaf.value = token.value;
    return leaf;
  }

  if (token.type == String) {
    struct AbstractSyntaxTreeLeaf leaf;
    leaf.type = StringAtom;
    leaf.value = token.value;
    return leaf;
  }

  if (token.type == Name) {
    struct AbstractSyntaxTreeLeaf leaf;
    leaf.type = Identifier;
    leaf.value = token.value;
    return leaf;
  }
}