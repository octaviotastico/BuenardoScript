#include "tokens.h"

token create_token(TokenTypeT type, typeT value) {
    token new_token = (token)malloc(sizeof(struct Tokens));
    new_token->type = type;
    new_token->value = value;
    return new_token;
}