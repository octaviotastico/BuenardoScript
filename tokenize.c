#include "data_structures/include/T.h"
#include "./characters.h"

int main() {
    struct AbstractSyntaxTree abbb;
    abbb.name = "asdas";
    abbb.type = StringAtom;
    printf("%s\n",abbb.name);
    printf("%d\n",abbb.type);
    return 0;
}

vector tokenizer(char* input_text) {
    int input_text_length = string_size(input_text);
    vector tokens = vector_init(Token, 1);

    for(int i = 0; i < input_text_length; i++) {
        char c = input_text[i];
        if(isWhiteSpace(c)) continue;

        if(isName(c)) {
            char* str = ""; i++;
            while(!isWhiteSpace(input_text[i])) {
                str += input_text[i]; i++;
            }
            token new_token; // Declare new token
            push_back(tokens, new_token);
        }

        if(isNumber(c)) {
            int number = 0;
            while(isNumber(c)) {
                number *= 10;
                number += (int)c;
                c = input_text[++i];
            }
            token new_token; // Declare new token
            push_back(tokens, new_token); i--;
        }

        if(isString(c)) {
            char* str = ""; i++;
            while(!isString(input_text[i]) && isCharacter(input_text[i])) {
                str += input_text[i]; i++;
            }
            token new_token; // Declare new token
            push_back(tokens, new_token);
        }
    }

    return tokens;
}