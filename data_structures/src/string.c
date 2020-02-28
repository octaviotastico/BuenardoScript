#include "string.h"

size_t string_size(const char * str) {
    const char *s;
    for (s = str; *s; ++s) {}
    return(s - str);
}