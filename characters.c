#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isWhiteSpace(char c) {
  return c == ' ';
}

bool isNumber(char c) {
  return (c > 47 && c < 58);
}

bool isCharacter(char c) {
  return (isNumber(c) || (c > 64 && c < 91) || (c > 96 && c < 123) || (c > 127 && c < 166));
}

bool isOpenBracket(char c) {
  return c == '[';
}

bool isClosedBracket(char c) {
  return c == ']';
}

bool isString(char c) {
  return c == '"';
}

bool isOperator(char c) {
  return ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
}