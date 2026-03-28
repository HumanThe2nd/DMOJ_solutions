/*
Too Simple
Author: Dan Shan
Date: Mar 27, 2026
Compute the numbers mathematically with booleans
Couldn't get the output to work in C with this approach, sadly
There appears to be an easier (unintended?) approach with *Variadic Functions* that does work in C

a: 1
b: 2
c: 3
d: 4
e: 5
f: 6
g: 7
h: 8
i: 9
j: 10
*/
#include <bits/stdc++.h>
using namespace std;
#define a  true
#define b  a + a
#define c  b + a
#define d  c + a
#define e  d + a
#define f  e + a
#define g  f + a
#define h  g + a
#define i  h + a
#define j  i + a
#define sa (j) * (g) + b
#define sb (j) * (j) + a 
#define sc (j) * (j) + h
#define sd (j) * (j) + j + a
#define se (j) * (d) + d
#define sf (j) * (c) + b
#define sg (j) * (h) + g
#define sh (j) * (j) + j + d
#define si (j) * (j)
#define sj (j) * (c) + c
int main() {
    cout << ((char)(sa));
    cout << ((char)(sb));
    cout << ((char)(sc));
    cout << ((char)(sc));
    cout << ((char)(sd));
    cout << ((char)(se));
    cout << ((char)(sf));
    cout << ((char)(sg));
    cout << ((char)(sd));
    cout << ((char)(sh));
    cout << ((char)(sc));
    cout << ((char)(si));
    cout << ((char)(sj));
    cout << ((char)(j));
}
