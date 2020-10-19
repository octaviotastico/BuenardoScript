#include "../include/string.h"

size_t string_size(const char * str){
  const char *s = str; while(*s) s++;
  return(s - str);
}