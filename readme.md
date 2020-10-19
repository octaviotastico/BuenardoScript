# BuenardoScript

---

This is a simple project to learn how to create a mini compiler.
It's programmed in C code.

The syntax will be something like:
```
// Single functions
[sum a b c d]   // Will add a+b+c+d
[sub a b c d]   // Will substract a-b-c-d
[mul a b c d]   // Will muliplicate a*b*c*d
[div a b]       // Will divide a/b
[mod a b]       // Will return a modulo b

// Nested functions (NOT ALLOWING THIS FOR NOW)
[sum a b [sub c d]]
[mul a b [div c d]]
```

### This readme will be the shitttttt
(Readme in progress, do not read)

A compiler is made by three important parts:

1) Tokenizer
2) Parser
3) Code transformation

Important files:

```
.
├─ characters.c
├─ tokenize.c
├─ parse.c
├─ convert.c
└─ data_structures
   ├─ include
   │  └─ LOT_OF_STUFF
   └─ src
      └─ LOT_OF_STUFF
```

I don't have any makefile yet, but I guess someday I will... for now, just `gcc tokenize.c -o asd data_structures/src/* && ./asd` the shh outta this code.