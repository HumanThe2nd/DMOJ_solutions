/*
Flip the Switches
Author Dan Shan
Last updated: 2025-02-06
Goal: find minimum prefix flips starting from 1 to make a boolean array all 0
For every change in character a move is requried.
If the array ends with 1, an extra move is neeed to zero the full array
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int l=0,c=0;
    char a[1000001];
    a[0]=getchar();
    while(a[0]!='\n') a[0]=getchar();
    a[l]=getchar();
    while(a[l]!='\n') {
        if(l&&a[l]!=a[l-1]) c++;
        l++;
        a[l]=getchar();
    }
    if(a[l-1]=='1') c++;
    printf("%d\n",c);
}
/*
Old Code
Date: 2023-10-06
#include <iostream>
using namespace std;
int main() {
int n,c=0;
scanf("%d",&n);
char s[n+1],cur='0';
scanf("%s",s);
for(int i=n-1;i>=0;i--){ // iterates switches from back
	if(s[i]!=cur){cur=s[i];c++;}
}
printf("%d\n",c);
}*/
