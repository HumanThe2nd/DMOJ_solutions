/*
CCC '10 S3 - Firehose
Author: Dan Shan
Date: 2025-07-30
1. Sort the array of positions
2. Store the gaps between each 2 houses
Binary search minimum length:
- Hydrants have a diameter of 2*length
- We can skip one gap: try all
Time Complexity: O(log(1e6) * H^2) -> O(H^2)
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
    long long num=0,neg=1;
    while((*ptr<'0'||*ptr>'9')&&*ptr!='-')++ptr; // Skip non-digit characters
    while(*ptr=='-')++ptr,neg*=-1;
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num*neg;
}
int cmp(const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}
int main(){
    buff();
    int n=scan(),max=0,a[1000001],gaps[2000002];
    for(int i=0;i<n;++i) a[i]=scan();
    int k=scan();
    if(k>=n) return !puts("0");
    qsort(a,n,sizeof(int),cmp);
    int l=1,r=500002;
    for(int i=1;i<n;++i){
        int gi=a[i]-a[i-1];
        if(gi>max) max=gi;
        gaps[i-1]=gi;
    } gaps[n-1]=1000000+a[0]-a[n-1];
    if(gaps[n-1]>max) max=gaps[n-1];
    for(int i=0;i<n;++i) gaps[i+n]=gaps[i];
    while(l<r){
        int m=(l+r+1)>>1,fi=0;
        for(int s=0;s<n;++s){ // start points
            int f=1,d=(m-1)<<1,c=k-1;
            for(int i=s;i<s+n-1;++i){
                d-=gaps[i];
                if(d<0){ // place hydrant
                    if(!c){
                        f=0; break;
                    } --c;
                    d=(m-1)<<1;
                }
            }
            if(f){ // works
                fi=1; break;
            }
        }
        if(fi) r=m-1; // valid: try shorter
        else l=m; // invalid: try longer
    }
    printf("%d\n",l);
}
