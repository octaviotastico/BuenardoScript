#include "parse.h"

/*

AST should look like:

.
├─ Type             // Int - Type of AST (Atom, or Function)
├─ Name             // String - Function name
├─ Args             // Vector - Function arguments
└─ Value            // TypeT - Atom value

*/

typeT getTokenValue(vector v, int pos) {
  token tokenTypeT = at(v, pos)->value.t;
  typeT tokenValue = tokenTypeT->token_value;
  return tokenValue;
}

ast parse(vector v) {
  int pos = 0;
  return parser(v, &pos);
}

ast parser(vector v, int* pos) {

  ast abstract_syntax_tree;
  char* ast_name;
  int ast_type;
  typeT ast_value;
  vector ast_args;

  do {

    typeT tokenValue = getTokenValue(v, ++(*pos));

    if ((tokenValue->iType == Bracket) && isOpenBracket(tokenValue->value.bracket)) {
      ast argument = parser(v, pos);
      push_back(ast_args, argument);
      continue;
    }

    if ((tokenValue->iType == Bracket) && isClosedBracket(tokenValue->value.bracket)) {
      abstract_syntax_tree = ast_init(ast_type, ast_name, ast_args, ast_value);
      return abstract_syntax_tree;
    }

    if (tokenValue->iType == Number) {
      typeT val = T_init(Number, &tokenValue->value.number);
      ast argument = ast_node_init(Number, val);
      push_back(ast_args, argument);
      continue;
    }

    if (tokenValue->iType == String) {
      typeT val = T_init(String, &tokenValue->value.string);
      ast argument = ast_node_init(String, val);
      push_back(ast_args, argument);
      continue;
    }

    if (tokenValue->iType == Name) {
      ast_type = FunctionCall;
      ast_name = tokenValue->value.name;
      ast_args = vector_init(AST, 1);
      ast_value = NULL; // It is a function call.
      continue;
    }

  } while ((*pos) < size(v));

}