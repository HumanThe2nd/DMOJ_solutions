/*
OTHS Coding Competition 4 P3 - Photo
Author: Dan Shan
Date: 2025-05-09
Intended Solution: 
Sort all people and put put them into the line in ascending height
(iterate row first, column second)
count the number of people taller than the person in front of them
Time Complexity: O(R*C * log(R*C))
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int cmp (const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
int main(){
    buff();
    int r=scan(),c=scan(),res=c;
    int n=r*c;
    int a[n],p[c];
    for(int i=0;i<n;i++) a[i]=scan();
    qsort(a,n,sizeof(int),cmp);
    for(int i=0;i<c;i++) p[i]=a[i];
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            int ind=i*c+j;
            if(p[j]<a[ind]) res++,p[j]=a[ind];
        }
    }
    printf("%d\n",res);
}
