/*
UTS Open '24 P3 - LXghts Out
Author: Dan Shan
Date: 2025-01-11
nonzero values of k make the array possible
otherwise, the array is impossible if it consists strictly of 11s seperated by single zeroes
ex: 11, 11011, 11011011 etc 

we can each even segment takes 2 more moves than the odds
so we can store the total number of 1s and even segments
for each even segment we add 2

for the full solution:
We save 3 moves for each even and 1 move for each odd
subtract the respective values for 3*evens then 1*odds k times
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int scan() { // input template
    int num = 0;
    char c = getchar();
    while (c>'9'||c<'0') c = getchar();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar();
    }
    return num;
}
int main(){
    int n=scan(),k=scan(),l=0,c=0,e=0;
    char s[n];
    for(int i=0;i<n;i++) {
        s[i]=getchar();
        if(s[i]=='1') l++;
        else{
            c+=l;
            if(l&&!(l&1)) e++;
            l=0;
        }
    } c+=l;
    if(l&&!(l&1)) e++;
    int f=n>1&&k<1; // flag impossibility
    if(s[0]=='0'||(n>1&&s[1]=='0')) f=0; 
    for(int i=2;i<n;i+=3){
        if(!f) break; // possibility proved
        if(i>n-2){
            f=0; break;
        }
        if(s[i]!='0'||s[i+1]!='1'||s[i+2]!='1') f=0;
    }
    if(f) return puts("-1\n")*0;
    if(k>e){ // save 3 moves per even
        k-=e; c-=e*3;
    }
    else{
        c-=3*k; k=0;
    }
    c+=e*2; // 2 extra moves for each remaining even
    c-=k; // save 1 move per odd
    if(c<0) c=0;
    printf("%d\n",c);
}
