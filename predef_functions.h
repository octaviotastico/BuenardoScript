#ifndef Functions_H
#define Functions_H

#include "data_structures/include/T.h"
#include "characters.h"
#include <string.h>

ast buenardo_sum(vector args);
ast buenardo_sub(vector args);
ast buenardo_mul(vector args);
ast buenardo_div(vector args);
ast buenardo_pow(vector args);

ast execute_predef_function(char* name, vector args);

#endif