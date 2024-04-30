// Another Contest 9 Problem 1 - Black Room Boy
// Author: Dan Shan
// Brute force and store answers
#include<stdio.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int main(){
    int t; scan(t);
    for(int ti=0;ti<t;ti++){
        int s[21][21]={};
        int a[4],c=0,sum=0;
        for(int i=0;i<4;i++) {
            scan(a[i]); sum+=a[i];
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i==j) continue;
                if(!s[a[i]+a[j]][sum-a[i]-a[j]]) c++;
                s[a[i]+a[j]][sum-a[i]-a[j]]=1;
            }
        }
        printf("%d\n",c);
        for(int i=0;i<21;i++){
            for(int j=0;j<21;j++){
                if(s[i][j]) printf("%d %d\n",i,j);
            }
        }
    }
}
