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

// Nested functions
[sum a b [sub c d]]
[mul a b [div c d]]
```