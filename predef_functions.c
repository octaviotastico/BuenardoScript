#include "predef_functions.h"

/*
  This are the predefined functions of BuenardoScript.
  All of them receive a vector of arguments (ast_nodes).
*/

ast buenardo_sum(vector args) {
  int res = 0;
  for(int i = 0; i < size(args); i++) {
    ast pos_i = at(args, i)->value.a;
    typeT pos_i_tT = pos_i->value;
    res += pos_i_tT->value.number;
  }
  printf("\nLlamada a la funcion Sum -> %d\n", res);
  return ast_node_init(Number, T_init(Number, &res));
}

ast buenardo_sub(vector args) {
  int res = at(args, 0)->value.a->value->value.number;
  for(int i = 1; i < size(args); i++) {
    res -= at(args, i)->value.a->value->value.number;
  }
  return ast_node_init(Number, T_init(Number, &res));
}

ast buenardo_mul(vector args) {
  int res = 1;
  for(int i = 0; i < size(args); i++) {
    res *= at(args, i)->value.a->value->value.number;
  }
  return ast_node_init(Number, T_init(Number, &res));
}

ast buenardo_div(vector args) {
  int res = at(args, 0)->value.a->value->value.number;
  for(int i = 1; i < size(args); i++) {
    res /= at(args, i)->value.a->value->value.number;
  }
  return ast_node_init(Number, T_init(Number, &res));
}

ast buenardo_pow(vector args) {
  int res = at(args, 0)->value.a->value->value.number;
  for(int i = 1; i < size(args); i++) {
    int pow = at(args, i)->value.a->value->value.number;
    while(--pow && pow > 0) {
      res *= res;
    }
  }
  return ast_node_init(Number, T_init(Number, &res));
}

ast execute_predef_function(char* name, vector args) {
  if(strcmp(name, "sum") == 0)
    return buenardo_sum(args);
  else if(strcmp(name, "sub") == 0)
    return buenardo_sub(args);
  else if(strcmp(name, "mul") == 0)
    return buenardo_mul(args);
  else if(strcmp(name, "div") == 0)
    return buenardo_div(args);
  else if(strcmp(name, "pow") == 0)
    return buenardo_pow(args);
}

// typeT buenardo_function_caller(vector args) {

// }