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

// vector parse_arguments(vector tokens, int pos) { // TA TODO MAL NO SE QUE HICE ANTES -2 IQ TENIA
//   vector arguments = vector_init(AST, 1);
//   for(int i = pos; i < size(tokens); i++) {
//     token t = at(tokens, i);

//     if (t->type == Number) {
//       ast_node node = ast_node_init(NumericAtom, t->value);
//       push_back(arguments, node);
//     }

//     if (t->type == String) {
//       ast_node node = ast_node_init(StringAtom, t->value);
//       push_back(arguments, node);
//     }
//   }
//   return arguments;
// }

ast parse(vector v, int position) {

  fore(i, position, size(v)) {
    token tokenTypeT = at(v, i)->value.t;
    typeT tokenValue = tokenTypeT->token_value;

    printf("%d ", tokenValue->iType);
    if (tokenValue->iType == Bracket) {
      if(isOpenBracket(tokenValue->value.bracket)) {
        printf("ImmaOpenBracket\n");
      }
      if(isClosedBracket(tokenValue->value.bracket)) {
        printf("ImmaClosedBracketc\n");
      }
    } else if (tokenValue->iType == Name) {
      printf("ImmaName\n");
    } else if (tokenValue->iType == Number) {
      printf("ImmaNumber\n");
    } else if (tokenValue->iType == String) {
      printf("ImmaString\n");
    }
  }
}


// int main() {
//   return 0;
// }

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