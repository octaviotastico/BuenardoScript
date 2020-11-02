#include "pipeline.h"

int pipeline(char* program) {

  char* test1 = "[sum 1 2 [sum 1 2] [sum 1 2]]";
  char* test2 = "[sum 1 2]";

  // printf("Program: %s\n", program);

  // printf("Starting Tokenizer\n");
  vector v1 = tokenizer(program);
  // printf("Finished Tokenizer\n");

  // printf("Starting Parser\n");
  ast a1 = parse(v1);
  // printf("Finished Parser\n");

  // printf("Starting Execution\n");
  execute(a1);
  // printf("Finishing Execution\n");

  return 0;
}