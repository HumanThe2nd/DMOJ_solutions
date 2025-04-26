/*
Largest Permutation
Author: HumanThe2nd
Date: 2025-04-26
For every number, move it to its descending index
Move the first K numbers not in their position
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<22
char buf[bs]; // templates
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // fast input
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
void print(int n) { // fast output
    if(!n) putchar('0');
    char s[10];
    int i=0;
    while(n>0){
        s[i++]=(n%10)+'0';
        n/=10;
    }
    while (--i >= 0) {
        putchar(s[i]);
    }
}
int main() {
    buff();
    int n=scan(),k=scan();
    int a[n],ind[n+1]; // A: current array, ind: index of each element
    for(int i=0;i<n;i++){
        a[i]=scan();
        ind[a[i]]=i;
    }
    for(int i=0;i<n;i++){
        if(!k) break; // no moves left
        if(a[i]==n-i) continue; // already in position
        int ai=a[i],ii=ind[n-i]; // current element and its detination
        a[ii]=ai; a[i]=n-i; // swap elements
        ind[n-i]=i; ind[ai]=ii; // swap indexes
        k--;
    }
    print(a[0]);
    for(int i=1;i<n;i++) putchar(' '),print(a[i]);
    putchar('\n');
}
