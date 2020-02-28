#include <stdio.h>
#include "data_structures/include/T.h"

int main() {
  struct AbstractSyntaxTree abbb;
  abbb.name = "asdas";
  abbb.type = StringAtom;
  printf("%s\n",abbb.name);
  printf("%d\n",abbb.type);
  return 0;
}

// void tokenizer(char* input_text) {
//   int input_text_length = strlen(input_text);
//   int tokens[input_text_length];

//   for(int i = 0; i < input_text_length; i++) {
//     char c = tokens[i];
//     if(isWhiteSpace(c)) continue;

//     int number = 0;
//     while(isNumber(c)) {
//       number *= 10;
//       number += (int)c;
//       i++;
//     }

//     if(isString(c)) {
//       i++;
//       char* str = "";
//       while(!isString(c) && isCharacter(c)) {
//         str += c;
//       }
//       tokens[last_token] = {type: 'String', string_value: str}
//     }
    
//     if(isWhiteSpace(c)) continue;
//   }

//   return tokens;
// }