#include <stdio.h>
#include "data.h"

// typeT parse(vector tokens, int i) {

//     token t = at(tokens, i);

//     if (t->type == Parenthesis) {
//         return parse(tokens, ++i);
//     }

//     if (t->type == Name) {
//         ast tree = ast_init(Identifier, t->value, parse(tokens, ++i));
//         return tree;
//     }


//     if (t->type == Number) {
//         ast_node leaf = ast_node_init(NumericAtom, t->value);
//         return leaf;
//     }

//     if (t->type == String) {
//         ast_node leaf = ast_node_init(StringAtom, t->value);
//         return leaf;
//     }
// }

vector parse(vector tokens, int start) {

    for(int i = start; i < tokens->sz; i++) {
        token t = at(tokens, i);
        if(t->type == Parenthesis) {
            parse_function(tokens, i + 1);
        } else if ((t->type == Number) || (t->type == String)) {
            parse_atoms(t);
        }
    }

}

vector parse_function(vector tokens, int i) {
    vector arguments = vector_init(ParserTypes, 1);
    token t = at(tokens, i);
    parse(tokens, i + 1);
}

vector parse_atoms(token t) {
    if (t->type == Number) {
        ast_node leaf = ast_node_init(NumericAtom, t->value);
        return leaf;
    }

    if (t->type == String) {
        ast_node leaf = ast_node_init(StringAtom, t->value);
        return leaf;
    }
}