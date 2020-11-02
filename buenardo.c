#include "pipeline.h"
#include "stdio.h"

int main() {
  printf(">>> BuenadoScript shell <<<\n");
  while(1) {
    char instruction[4096];
    printf(">>> ");
    fgets(instruction, 4096, stdin);
    pipeline(instruction);
  }
}