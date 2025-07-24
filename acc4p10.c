/*
Another Contest 4 Problem 10 - Two Rectangles
Author: Dan Shan
Date: 2025-07-24
Query: Can N be written as the sum of 2 square root integers?

1. Subtract the square root of each i less than N
2. If any difference is also a square root, the number is valid
TC: O(sqrt(N))
*/
#include <stdio.h>
#include <math.h>
#pragma GCC optimize ("Ofast")
bool f(int n){
    for(int i=0;i*i<n;++i){
        int d=n-i*i,s=(int)sqrt(d);
        if(s*s==d) return 1;
    }
    return 0;
}
