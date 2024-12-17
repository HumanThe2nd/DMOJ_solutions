/*
Amplitude Hackathon Winter '24 Problem 2 - Fog Machine
Author: Dan Shan
Date: 2024-12-17
Brute force maximum by adding integers from 1 to infinity until max reached
*/
#include <stdio.h>
int main() {
    int c=1,y,i;
    scanf("%d",&y);
    for(i=2;i<100001;i++){
        c+=i;
        if(c>=y) break;
    }
    printf("%d\n",i-1);
}
