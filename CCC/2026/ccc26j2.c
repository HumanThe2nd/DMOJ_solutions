/*
CCC '26 J2 - Olympic Scores
Author: Dan Shan
Date: Mar 27, 2026
1. Find sum, max, and min of all 5 scores 
2. return (sum - min - max) * difficulty
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int a[6]; // a[5] or "6th index" stores the difficulty
    for(int i = 0; i < 6; ++i){
        scanf("%d", &a[i]);
    }
    int c = a[0], mn = a[0], mx = a[0];
    for(int i = 1; i < 5; ++i){
        if(a[i] < mn) mn = a[i];
        if(a[i] > mx) mx = a[i];
        c += a[i];
    }
    printf("%d\n", a[5] * (c - mx - mn));
}
