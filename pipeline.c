#include "tokenize.h"
#include "parse.h"

int main() {
  char* test1 = "[sum 1 2]";
  vector v1 = tokenizer(test1);
  // printf("Tokenized %s", test1);

  char* test2 = "[div 256 2]";
  vector v2 = tokenizer(test2);
  // printf("Tokenized %s", test2);

  ast a1 = parse(v1);
  printf("Parsed %s", test1);

  // ast a2 = parse(v2);
  // printf("Parsed %s", test2);

  return 0;
}