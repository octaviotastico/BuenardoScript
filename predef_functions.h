#ifndef Functions_H
#define Functions_H

#include "data_structures/include/T.h"
#include "characters.h"

typeT buenardo_sum(vector args);
typeT buenardo_sub(vector args);
typeT buenardo_mul(vector args);
typeT buenardo_div(vector args);
typeT buenardo_pow(vector args);

typeT execute_predef_function(char* name, vector args);

#endif