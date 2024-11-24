/*
CCC '12 J1 - Speed fines are not fine!
Author: Dan Shan
Date: 2024-11-24
if statments + conditionals
*/
#include<stdio.h>
int main() {
    int l,s;
    scanf("%d %d",&l,&s);
    if(s<=l) return printf("Congratulations, you are within the speed limit!\n")*0;
    int x=s-l;
    printf("You are speeding and your fine is $");
    if(x>30) printf("500");
    else if(x>20) printf("270");
    else printf("100");
    printf(".\n");
}
