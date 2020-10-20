#include "../include/tokens.h"

token token_init(int ttype, void* value) {
  token t = (token)malloc(sizeof(struct Tokens));
  t->token_value = T_init(ttype, value);
  return t;
}

// Needs better implementation
void token_destroy(token t) {
  destroy(t);
  free(t);
  t = NULL;
}