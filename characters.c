#include "characters.h"

int isWhiteSpace(char c) {
  return c == ' ';
}

int isNumber(char c) {
  return (c > 47 && c < 58);
}

int isCharacter(char c) {
  return (isNumber(c) || (c > 64 && c < 91) || (c > 96 && c < 123) || (c > 127 && c < 166));
}

int isName(char c) {
  return isCharacter(c);
}

int isOpenBracket(char c) {
  return c == '[';
}

int isClosedBracket(char c) {
  return c == ']';
}

int isString(char c) {
  return c == '"';
}