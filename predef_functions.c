#include "predef_functions.h"

int buenardo_sum(vector args) {
  int res = 0;
  for(int i = 0; i < size(args); i++) {
    res += at(args, i)->value.number;
  }
  return res;
}

int buenardo_sub(vector args) {
  int res = at(args, 0)->value.number;
  for(int i = 1; i < size(args); i++) {
    res -= at(args, i)->value.number;
  }
  return res;
}

int buenardo_mul(vector args) {
  int res = 1;
  for(int i = 0; i < size(args); i++) {
    res *= at(args, i)->value.number;
  }
  return res;
}

int buenardo_div(vector args) {
  int res = at(args, 0)->value.number;
  for(int i = 1; i < size(args); i++) {
    res /= at(args, i)->value.number;
  }
  return res;
}

int buenardo_pow(vector args) {
  int res = at(args, 0)->value.number;
  for(int i = 1; i < size(args); i++) {
    int pow = at(args, i)->value.number;
    while(--pow && pow > 0) {
      res *= res;
    }
  }
  return res;
}