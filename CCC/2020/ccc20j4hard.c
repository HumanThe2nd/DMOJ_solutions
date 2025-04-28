/*
CCC '20 J4 - Cyclic Shifts (Hard)
Author: HumanThe2nd
Date: 2025-04-28
Using Z Algorithm
Create Z Array for prefix & suffix of pattern in text
Check if at any position the suffix+prefix is greater than or equal to the pattern length 
*/
#include <stdio.h>
#include <string.h>
#pragma GCC optimize ("Ofast")
int z[20000002],z2[20000002]; // prefix, suffix
int main() {
    char s[10000001],p[30000002];
    scanf("%s %s",s,p);
    int n=strlen(s),m=strlen(p),l=0,r=0;
    p[m++]='?'; // seperator
    for(int i=0;i<n;++i){
        p[m+i]=s[i];
    }
    n+=m; // length of combined str
    for(int i=1;i<n;++i){
        if(i>r){
            l=r=i;
            while(r<n&&p[r-l]==p[r]) r++;
            z[i]=r-l; r--;
            continue;
        }
        int k=i-l;
        if(z[k]<r-i+1) z[i]=z[k];
        else{
            l=i;
            while(r<n&&p[r-l]==p[r]) r++;
            z[i]=r-l; r--;
        }
    }
    for(int i=0;i<m/2;i++){ // reverse pattern
        char temp=p[i];
        p[i]=p[m-i-2];
        p[m-i-2]=temp;
    } l=r=0;
    int n2=(n-m)/2;
    for(int i=0;i<n2;i++){ // reverse text
        char temp=p[m+i];
        p[m+i]=p[n-i-1];
        p[n-i-1]=temp;
    }
    for(int i=1;i<n;++i){
        if(i>r){
            l=r=i;
            while(r<n&&p[r-l]==p[r]) r++;
            z2[i]=r-l; r--;
            continue;
        }
        int k=i-l;
        if(z2[k]<r-i+1) z2[i]=z2[k];
        else{
            l=i;
            while(r<n&&p[r-l]==p[r]) r++;
            z2[i]=r-l; r--;
        }
    }
    for(int i=0;i<n-m;i++){
        if(z[m+i]+z2[n-i]>=m-1) return !puts("yes");
    }
    puts("no");
}
