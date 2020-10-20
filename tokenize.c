#include "tokenize.h"

vector tokenizer(char* input_text) {

  vector tokens = vector_init(Token, 1);
  for(int i = 0; i < string_size(input_text); i++) {
    char c = input_text[i];

    if(isWhiteSpace(c)) continue;

    if(isOpenBracket(c) || isClosedBracket(c)) {
      token new_token = token_init(Bracket, &c);
      push_back(tokens, new_token);
      continue;
    }

    if(isName(c)) {
      short j = 0; char name[100];
      while(!isWhiteSpace(input_text[i])) {
        name[j] = input_text[i]; i++; j++;
      }
      token new_token = token_init(Name, name);
      push_back(tokens, new_token);
      continue;
    }

    if(isNumber(c)) {
      int number = 0;
      while(isNumber(c)) {
        number *= 10;
        number += (int)c;
        c = input_text[++i];
      }
      token new_token = token_init(Number, &number);
      push_back(tokens, new_token); i--;
      continue;
    }

    if(isString(c)) {
      char* str = ""; i++;
      while(!isString(input_text[i]) && isCharacter(input_text[i])) {
        str += input_text[i]; i++;
      }
      token new_token = token_init(String, str);
      push_back(tokens, new_token);
      continue;
    }
  }

  return tokens;
}
