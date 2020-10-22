#include "parse.h"

/*

AST should look like:

.
├─ Name             // String - Function name
├─ Single_Multiple  // Bool
├─ Param1           // TypeT
└─ Param2           // TypeT
                    // I could add a vector, and those
                    // could be the arguments, but that
                    // could be a lot more complicated

Recorrer vector de tokens, guardar nombre y parametros 1 y 2 asumiendo que son simples
Revisar param 1 y param 2, si son atomos, aplicar Name, sino, resolver primero param 1, despues param 2, y despues aplicar Name

*/


// Here we receive a vector of tokens, and a position.
// Position is only used for recursion purposes.
ast parse(vector v, int pos) {

  printf("Starting building AST\n");
  ast abstract_syntax_tree;
  int ast_type = AST;
  char* ast_name = "";
  short ast_single_arg = 0;
  token tokenTypeT = NULL;
  typeT tokenValue = NULL;
  void* arg1 = NULL;
  void* arg2 = NULL;

  do {

    tokenTypeT = at(v, pos)->value.t;
    tokenValue = tokenTypeT->token_value;

    if (tokenValue->iType == Bracket) {

      if(isOpenBracket(tokenValue->value.bracket)) {
        printf("ImmaOpenBracket\n");
        pos++; continue;
      }

      if(isClosedBracket(tokenValue->value.bracket)) {
        printf("ImmaClosedBracketc\n");

        abstract_syntax_tree = ast_init(ast_type, ast_name, ast_single_arg, arg1, arg2);
        printf("Finished building AST\n");
        return abstract_syntax_tree;
      }

    }

    if (tokenValue->iType == Name) {

      printf("ImmaFunction\n");

      ast_name = tokenValue->value.name;

      // So... v[i] is a name, then, v[i+1] is arg1, v[i+2] is arg2.
      // If v[i+1] or v[i+2] are a '[' (openingBracket), then they're
      // recursive arguments.
      printf("ImmaFirstArgument\n");
      pos++; typeT arg1TokenValue = (at(v, pos)->value.t)->token_value;
      if (arg1TokenValue->iType == Bracket) {
        arg1 = parse(v, pos); pos++;
        typeT _t = (at(v, pos)->value.t)->token_value;
        while (_t->iType != Bracket && !isClosedBracket(_t->value.bracket)) {
          // Until we find a closing bracket, so we dont
          // count the same function (argument) twice... Not
          // an elegant solution, but it works until I come up
          // with something better.
          // UPDATE: It won't work if the recursion is more than
          //         1 level deep :) SO I NEED ANOTHER SOLUTION
          pos++; _t = (at(v, pos)->value.t)->token_value;
        }
      } else {
        arg1 = arg1TokenValue;
      }

      // This should be the second argument.
      // NEED TOWORK ON SINGLE ARGUMENT FUNCTIONS.
      printf("ImmaSecondArgument\n");
      pos++; typeT arg2TokenValue = (at(v, pos)->value.t)->token_value;
      if (arg2TokenValue->iType == Bracket) {
        arg2 = parse(v, pos); pos++;
        typeT _t = (at(v, pos)->value.t)->token_value;
        while (_t->iType != Bracket && !isClosedBracket(_t->value.bracket)) {
          // Until we find a closing bracket, so we dont
          // count the same function (argument) twice... Not
          // an elegant solution, but it works until I come up
          // with something better.
          // UPDATE: It won't work if the recursion is more than
          //         1 level deep :) SO I NEED ANOTHER SOLUTION
          pos++;
        }
      } else {
        arg2 = arg2TokenValue;
      }
      pos++; continue;
    }

  } while (!(tokenValue->iType == Bracket && isClosedBracket(tokenValue->value.bracket)));

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