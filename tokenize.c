#include "data_structures/include/T.h"
#include "characters.h"

vector tokenizer(char* input_text) {
  int input_text_length = string_size(input_text);
  vector tokens = vector_init(Token, 1);

  for(int i = 0; i < input_text_length; i++) {
    char c = input_text[i];
    if(isWhiteSpace(c)) continue;

    if(isName(c)) {
      char* name = ""; i++;
      while(!isWhiteSpace(input_text[i])) {
        name += input_text[i]; i++;
      }
      token new_token = token_init(Name, name);
      push_back(tokens, new_token);
      continue;
    }

    if(isOpenBracket(c)) {
      token new_token = token_init(Bracket, &c);
      push_back(tokens, new_token);
      continue;
    }

    if(isClosedBracket(c)) {
      token new_token = token_init(Bracket, &c);
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

int main() {
  struct AbstractSyntaxTree abbb;
  char* test = "[sum 1 2]";
  printf("%s", test);

  vector v = tokenizer(test);

  char* test2 = "[div 256 2]";
  printf("%s", test2);

  vector v2 = tokenizer(test2);

  return 0;
}