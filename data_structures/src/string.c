#include "../include/string.h"

size_t string_size(const char * str){
  const char *s = str; while(*s) s++;
  return(s - str);
}

// char* concat(char* c1, char* c2) {

//   size_t s1 = string_size(c1);
//   size_t s2 = string_size(c2);
//   size_t s3 = s1 + s2;

//   char c3[s3];

//   for(int i=0; i<s1; i++) c3[i] = c1[i];
//   for(int i=s1; i<s1+s2; i++) c3[i] = c2[i];

//   return c3;
// }