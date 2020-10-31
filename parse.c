#include "parse.h"

/*

AST should look like:

.
├─ Type             // Type of AST ("Atom", or "Function")
├─ Name             // String - Function name
├─ Args             // Vector - Function arguments
└─ Value            // Atom value

*/

typeT getTokenValue(vector v, int pos) {
  token tokenTypeT = at(v, pos)->value.t;
  typeT tokenValue = tokenTypeT->token_value;
  return tokenValue;
}

ast parse(vector v) {
  int pos = -1;
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

    printf("%d - %d", *pos, size(v));

    if ((tokenValue->iType == Bracket) && isOpenBracket(tokenValue->value.bracket)) {
      printf("~[ ");
      ast argument = parser(v, pos);
      push_back(ast_args, argument);
      continue;
    }

    if ((tokenValue->iType == Bracket) && isClosedBracket(tokenValue->value.bracket)) {
      printf("~] ");
      abstract_syntax_tree = ast_init(ast_type, ast_name, ast_args, ast_value);
      return abstract_syntax_tree;
    }

    if (tokenValue->iType == Number) {
      printf("~Num ");
      typeT val = T_init(Number, &tokenValue->value.number);
      ast argument = ast_node_init(Number, val);
      push_back(ast_args, argument);
      continue;
    }

    if (tokenValue->iType == String) {
      printf("~Str ");
      typeT val = T_init(String, &tokenValue->value.string);
      ast argument = ast_node_init(String, val);
      push_back(ast_args, argument);
      continue;
    }

    if (tokenValue->iType == Name) {
      printf("~Fun ");
      ast_type = FunctionCall;
      ast_name = tokenValue->value.name;
      ast_args = vector_init(AST, 1);
      ast_value = NULL; // It is a function call.
      continue;
    }

  } while ((*pos) < size(v));

}

///////////////////////

// vector parse(vector tokens, int start) {

//   for(int i = start; i < size(tokens); i++) {
//     token t = at(tokens, i);
//     if(t->type == Name) {
//       parse_function(tokens, i + 1);
//     } else if ((t->type == Number) || (t->type == String)) {
//       parse_atoms(t);
//     }
//   }

// }

// vector parse_function(vector tokens, int i) {
//   vector arguments = vector_init(ParserTypes, 1);
//   parse(tokens, i + 1);
// }

// vector parse_atoms(token t) {
//   if (t->type == Number) {
//     ast_node leaf = ast_node_init(NumericAtom, t->value);
//     return leaf;
//   }

//   if (t->type == String) {
//     ast_node leaf = ast_node_init(StringAtom, t->value);
//     return leaf;
//   }
// }