/*
COCI '08 Contest 2 #1 Kornislav
Author: Dan Shan
Date: 2025-09-12

1. Sort array in non-decreasing
2. Return product of 1st and 3rd elements

Explanation:
Each path away from the origin must not be greater than the path that moves back
It is optimal that we move left a[0] (min), come back with a[1]
move down with a[2] and come back with a[4]

Therefore, the max area is the product of the smallest and 3rd smallest elements
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int a[4];
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    for(int i = 0; i < 3; ++i){ // sort
        for(int j = i+1; j < 4; ++j){
            if(a[i] <= a[j]) continue;
            int temp = a[i];
            a[i] = a[j]; a[j] = temp;
        }
    }
    printf("%d\n",a[0]*a[2]);
}
