#ifndef Parse_H
#define Parse_H

#include "data_structures/include/T.h"
#include "characters.h"

ast parse(vector v);
ast parser(vector v, int* pos);

#endif