#include "transform.h"

/*
  Transform will change the original code
  to C code.
*/

char* base() {
  return "\n\
    #include \"stdio.h\"\n\
    int main() {\n\
      return 0;\n\
    }\n\
  "
}

void* transform(ast program) {
}