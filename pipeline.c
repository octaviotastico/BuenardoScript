#include "tokenize.h"
#include "parse.h"
// #include "executer.h"

int main() {
  char* test1 = "[sum 1 2]";

  printf("Program: %s\n", test1);

  printf("Starting Tokenizer\n");
  vector v1 = tokenizer(test1);
  printf("Finished Tokenizer\n");

  printf("Starting Parser\n");
  ast a1 = parse(v1, 0);
  printf("Finished Parser\n");

  // printf("Starting Execution\n");
  // exec e1 = execute(a1);
  // printf("Finished Execution\n");

  return 0;
}