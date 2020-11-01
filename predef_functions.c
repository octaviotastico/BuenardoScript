#include "predef_functions.h"

/*
  This are the predefined functions of BuenardoScript.
  All of them receive a vector of arguments (ast_nodes).
*/

typeT buenardo_sum(vector args) {
  int res = 0;
  for(int i = 0; i < size(args); i++) {
    res += at(args, i)->value.number;
  }
  return T_init(Number, &res);
}

typeT buenardo_sub(vector args) {
  int res = at(args, 0)->value.number;
  for(int i = 1; i < size(args); i++) {
    res -= at(args, i)->value.number;
  }
  return T_init(Number, &res);
}

typeT buenardo_mul(vector args) {
  int res = 1;
  for(int i = 0; i < size(args); i++) {
    res *= at(args, i)->value.number;
  }
  return T_init(Number, &res);
}

typeT buenardo_div(vector args) {
  int res = at(args, 0)->value.number;
  for(int i = 1; i < size(args); i++) {
    res /= at(args, i)->value.number;
  }
  return T_init(Number, &res);
}

typeT buenardo_pow(vector args) {
  int res = at(args, 0)->value.number;
  for(int i = 1; i < size(args); i++) {
    int pow = at(args, i)->value.number;
    while(--pow && pow > 0) {
      res *= res;
    }
  }
  return T_init(Number, &res);
}

typeT execute_predef_function(char* name, vector args) {
  if(name == "buenardo_sum") {
    return buenardo_sum(args);
  }
  if(name == "buenardo_sub") {
    return buenardo_sub(args);
  }
  if(name == "buenardo_mul") {
    return buenardo_mul(args);
  }
  if(name == "buenardo_div") {
    return buenardo_div(args);
  }
  if(name == "buenardo_pow") {
    return buenardo_pow(args);
  }
}

// typeT buenardo_function_caller(vector args) {

// }