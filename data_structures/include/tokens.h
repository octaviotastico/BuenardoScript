#ifndef TOKEN_H
#define TOKEN_H

#include "T.h"

struct Tokens {
	// Pointer to struct T containing the data of the Token //
  typeT value;

	/* Destroy token */
  void (*destroy)(token);

};

token token_init(int ttype, void* value);

void token_destroy(token t);

#endif