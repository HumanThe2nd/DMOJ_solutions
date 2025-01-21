/*
CCO '14 P4 - Where's That Fuel?
Author: Dan Shan
Date: 2025-01-21
Sort planets by ascending fuel cells
skip planets with more cost than fuel
continuing adding valid planets until cost is greater than current fuel or end is reached
Time Complexity O(n*logn)
*/
#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<20 // buffer size
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
    long long n=scan(),p=scan(),a[n];
    for(int i=0;i<n;i++){
        a[i]=scan();
        a[i]=a[i]*100001+scan();
    }
    int c=0,res=a[p-1]/100001;
    a[p-1]=0;
    qsort(a,n,sizeof(long long),cmp);
    for(int i=0;i<n;i++){
        if(a[i]/100001<a[i]%100001) continue; // skip
        if(a[i]%100001>res) break; // no more valid moves
        c++;
        res+=a[i]/100001-a[i]%100001;
    }
    printf("%d\n%d\n",res,c);
}
