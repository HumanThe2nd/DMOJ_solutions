/*
BlueBook - Cross Country
Author: Dan Shan
Date: 2025-07-21
conditionals
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    char s[3];
    scanf("%s",s);
    if(s[0]=='M'&&s[1]=='G') puts("midget girls");
    else if(s[0]=='M'&&s[1]=='B') puts("midget boys");
    else if(s[0]=='J'&&s[1]=='G') puts("junior girls");
    else if(s[0]=='J'&&s[1]=='B') puts("junior boys");
    else if(s[0]=='S'&&s[1]=='G') puts("senior girls");
    else if(s[0]=='S'&&s[1]=='B') puts("senior boys");
    else puts("invalid code");
}
