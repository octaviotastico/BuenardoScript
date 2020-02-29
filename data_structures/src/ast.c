#include "ast.h"

ast ast_init(ParserTypeT type, char* name, vector arguments) {
    ast new_ast = (ast)malloc(sizeof(struct AbstractSyntaxTree));
    new_ast->type = type;
    new_ast->name = name;
    new_ast->arguments = arguments;
    return new_ast;
}

ast_node ast_node_init(ParserTypeT type, typeT value) {
    ast_node new_ast_node = (ast_node)malloc(sizeof(struct AbstractSyntaxTreeLeaf));
    new_ast_node->type = type;
    new_ast_node->value = value;
    return new_ast_node;
}
