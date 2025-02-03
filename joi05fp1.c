/*
JOI '05 Final Round P1 - Questionnaire
Author: Dan Shan
Date: 2025-02-02
Brute force the order by taking the minimum every iteration
Time Complexity: O(n*m+m^2)
Note:
This could be simplified to O(n*m+mlogm) using custom comparators but its not necessary with provided constraints
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<22 // buffer size
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // fast input template
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int cmp(const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}
int main(){
    buff();
    int n=scan(),m=scan();
    int a[m]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) a[j]+=scan();
    }
    for(int i=0;i<m;i++){
        int max=-1,ind;
        for(int j=0;j<m;j++){
            if(a[j]>max){
                max=a[j]; ind=j;
            }
        }
        a[ind]=-1;
        printf("%d",ind+1);
        putchar(i<m-1?' ':'\n');
    }
}
