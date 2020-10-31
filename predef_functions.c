#include "predef_functions.h"

int sum(typeT arg1, typeT arg2) { // Change it to vector of arguments
  return arg1->value.i + arg2->value.i;
}

int sub(typeT arg1, typeT arg2) { // Change it to vector of arguments
  return arg1->value.i - arg2->value.i;
}

int mul(typeT arg1, typeT arg2) { // Change it to vector of arguments
  return arg1->value.i * arg2->value.i;
}

int div(typeT arg1, typeT arg2) { // Change it to vector of arguments
  return arg1->value.i / arg2->value.i;
}