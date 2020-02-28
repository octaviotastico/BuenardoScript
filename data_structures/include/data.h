#ifndef DATA_H
#define DATA_H

typedef struct Heap* heap;
typedef struct List* list;
typedef struct Pair* pair;
typedef struct Vector* vector;
typedef struct Queue* queue;
typedef struct RBTree* tree;
typedef struct Set* set;
typedef struct Stack* stack;
typedef struct T* typeT;
typedef struct Vector* vector;

#include "assert.h"
#include "defs.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#include "heap.h"
#include "list.h"
#include "pair.h"
#include "queue.h"
#include "rbtree.h"
#include "set.h"
#include "stack.h"
#include "vector.h"

typedef struct Tokens* token;

typedef union TokenType {
  char* Name;
  int Number;
  char* String;
  char Parenthesis;
} TokenType;

typedef enum TokenTypeT {
  Name,
  Number,
  String,
  Parenthesis
} TokenTypeT;

struct Tokens {
  TokenTypeT type;
  char* value;
};

typedef union ParserType {
  char* CallExpression;
  int NumericAtom;
  char* StringAtom;
  char* Identifier;
} ParserType;

typedef enum ParserTypeT {
  CallExpression,
  NumericAtom,
  StringAtom,
  Identifier
} ParserTypeT;

typedef struct AbstractSyntaxTree* ast;

struct AbstractSyntaxTree {
  ParserTypeT type;
  char* name;
  void* arguments; // This could be an ast or a node
};

typedef struct AbstractSyntaxTreeLeaf* node;

struct AbstractSyntaxTreeLeaf {
  char* type;
  char* value;
};

typedef union Data {
	unsigned char uc;               //  1
	signed char sc;                 //  2
	char c;                         //  3
	short int si;                   //  4
	unsigned short int usi;         //  5
	int i;                          //  6
	unsigned int ui;                //  7
	long int li;                    //  8
	unsigned long int uli;          //  9
	long long int lli;              // 10
	unsigned long long int ulli;    // 11
	float f;                        // 12
	double d;                       // 13
    pair p;                         // 14
    vector v;                       // 15
    set s;                          // 16
    stack st;                       // 17
    queue q;                        // 18
    list l;                         // 19
    heap h;                         // 20
	int* p_i;                       // 21
	char* p_c;                      // 22
	void* p_v;                      // 23
    struct Tokens token;            // 24
    TokenTypeT tt;                  // 25
    ParserTypeT pt;                 // 26
} data;

typedef enum types {
    Undefined,                      //  0
    UChar,                          //  1
    SChar,                          //  2
    Char,                           //  3
    SInt,                           //  4
    USInt,                          //  5
    Int,                            //  6
    UInt,                           //  7
    LInt,                           //  8
    ULInt,                          //  9
    LLInt,                          // 10
    ULLInt,                         // 11
    Float,                          // 12
    Double,                         // 13
    Pair,                           // 14
    Vector,                         // 15
    Set,                            // 16
    Stack,                          // 17
    Queue,                          // 18
    List,                           // 19
    Heap,                           // 20
    P_Int,                          // 21
    P_Char,                         // 22
    P_Void,                         // 23
    Token,                          // 24
    TokenTypes,                     // 25
    ParserTypes                     // 26
} type;

#endif