# BuenardoScript

---

# Table of Contents
1. [Introduction](#Introduction)
2. [About the language](#About-the-language)
   1. [Syntax](#Syntax)
   2. [How to use it](#How-to-use-it)
3. [About the compiler](#About-the-compiler)
   1. [Tokenizer](#Tokenizer)
   2. [Parser](#Parser)
   3. [Code transformation](#Code-transformation)
   4. [Execution](#Execution)
   5. [Important files](#Important-files)

---

## Introduction

BuenardoScript is a relatively simple project, made just for fun, and to learn how to create a mini compiler and programming language. It's programmed 100% in C code.

## About the language:

This is a functional programming language. It means, all you can do is apply and compose functions.

There are already some predefined functions in BuenardoScript.

They are:
- `sum`
- `sub`
- `mul`
- `div`
- `pow`

### Syntax
The syntax is:

```
[function_name arg1 arg2 arg3 ...]
```
For example:

```
[sum a b]                 // Will add a + b
[sum a b c d e f g h]     // Will add a + b + c + d + e + f + g + h
[sub a b c d]             // Will substract like this: a - b - c - d
[mul a b c d]             // Will multiply a * b * c * d
```
You can also compose function calls.

For example:
```
[sum a b [sub c d]]       // Will return a + b + (c - d)
[mul a b [div c d]]       // Will return a * b * (c / d)
[mul [sum a b] [sum c d]] // Will return (a + b) * (c + d)
```

### How to use it

First, compile the C code:
```
gcc buenardo.c -g -o BuenardoScript pipeline.c execute.c predef_functions.c parse.c tokenize.c characters.c data_structures/src/*
```
Then, simply execute it:
```
./BuenardoScript
```

## About the compiler:

This compiler is made by three important parts:

1) Tokenizer
2) Parser
3) Code Transformation
4) Execution

### Tokenizer

The tokenizer takes the original input, and transform it into something called "tokens". This part is also called "Lexical Analysis".

For example, it takes the string "[sum 1 2]", and then it creates a struct Token for each token.

The tokens in this example would be "[", "sum", "1", "2", "]", as you can see, the tokenization deletes some no-needed characters, like the white spaces.

### Parser

The parser takes the array of tokens, created in the tokenization phase, and analyzes them to get more information about the program. This part is also called "Syntactic Analysis".

Here, the parser transform the tokens and creates the AST (Abstract Syntax Tree), a nested struct containing the information about the program, like the function calls and their arguments.

This AST struct contains the type of the node (if it is a function or an argument), the name (of the function, if it is a function call), the arguments of the functions, and the value of the token (if the node is not a function, and it is an argument).

### Code Transformation

The code transformation takes the AST built in the parser phase, and transforms it into C code.

It traverses the AST doing a DFS-like (a way to traverse graphs, "deep first search"), executing the functions in the program with their given arguments.

Some compilers transform the code to another programming language and then compiles it again in the second language. That's called transpilation.

### Execution

BuenardoScript has a shell like python, that executes each sentence in real time.

That's made with just a while(True) loop, reading the user's input, and then calling the compiler for each line.


### Important files:

```
.
├─ characters.h
├─ tokenize.c
├─ parse.c
├─ execute.c
├─ predef_functions.c
├─ buenardo.c
└─ data_structures/
   └─ LOT_OF_STUFF
```

- **characters.c**: Contains simple functions, used by the tokenizer, to get more information about each character it reads in the user's input (Is it a white space? A digit? A character? etc).
- **tokenize.c**: The implementation of the tokenizer! (Not the same as tokens.c and tokens.h, they contain the implementation of the Tokens struct).
- **parse.c**: The implementation of the parser!
- **execute.c**: The execution phase, traverses the AST and calls the predef_functions needed with the vector of parameters.
- **predef_functions.c**: The implementation of the predefined functions mentioned in "About the language".
- **buenardo.c**: The shell that executes BuenardoScript instructions one by one in real time.
- **data_structures**: A superduper important directory (and epic project) that contains the implementation of several data structures, originally created by [CarusoX](https://github.com/CarusoX/Data-Structures-C) and me.
