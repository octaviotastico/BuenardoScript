#include "tokenize.h"
#include "parse.h"
#include "execute.h"
#include "transform.h"

int main() {
  // char* test1 = "[sum 1 2]";
  char* test1 = "[sum 1 2 [sum 1 2] 4]";

  printf("Program: %s\n", test1);

  printf("Starting Tokenizer\n");
  vector v1 = tokenizer(test1);
  printf("Finished Tokenizer\n");

  printf("Starting Parser\n");
  ast a1 = parse(v1);
  printf("Finished Parser\n");

  printf("Starting Execution\n");
  execute(a1);
  printf("Finishing Execution\n");

  // printf("Starting Transformation\n");
  // transform(a1);
  // printf("Finishing Transformation\n");

  return 0;
}