#include <stdio.h>
#include "data.h"

ast parse(vector tokens) {

    int i = 0;
    token t = at(tokens, i);
    while(t->type != Name) {t = at(tokens, i); i++;}

    vector arguments = parse_arguments(tokens, ++i);
    ast tree = ast_init(Identifier, t->value, arguments);
    return tree;

}

vector parse_arguments(vector tokens, int pos) {
    vector arguments = vector_init(ParserTypes, 1);
    for(int i = pos; i < tokens->sz; i++) {
        token t = at(tokens, i);

        if (t->type == Number) {
            ast_node node = ast_node_init(NumericAtom, t->value);
            push_back(arguments, node);
        }

        if (t->type == String) {
            ast_node node = ast_node_init(StringAtom, t->value);
            push_back(arguments, node);
        }
    }
    return arguments;
}

// vector parse(vector tokens, int start) {

//     for(int i = start; i < tokens->sz; i++) {
//         token t = at(tokens, i);
//         if(t->type == Name) {
//             parse_function(tokens, i + 1);
//         } else if ((t->type == Number) || (t->type == String)) {
//             parse_atoms(t);
//         }
//     }

// }

// vector parse_function(vector tokens, int i) {
//     vector arguments = vector_init(ParserTypes, 1);
//     parse(tokens, i + 1);
// }

// vector parse_atoms(token t) {
//     if (t->type == Number) {
//         ast_node leaf = ast_node_init(NumericAtom, t->value);
//         return leaf;
//     }

//     if (t->type == String) {
//         ast_node leaf = ast_node_init(StringAtom, t->value);
//         return leaf;
//     }
// }