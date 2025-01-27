/*
Attraction
Author: Dan Shan
Date: 2025-01-27
coordinate compression, only use relevant coordinates
possible placements:
gaps between fixed attactors to walls or gaps of width 1, cost 1 removeable 
even: fill half the gap, cost 1 removeable per half
odd: 1 removeable takes half+1, another takes half-1, last takes 1
sort moves descending and takes b max moves
special case: 3 zeros surrounded by 1s -> 2,0,1
resolve this by doubling all numbers and use 4,1,1 for this case
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
    return (*(int*)b-*(int*)a);
}
int main(){
    buff();
    int t=scan();
    while(t--){
        int n=scan(),a=scan(),b=scan();
        int v[a+2],q[4*a],r=0,c=0;
        for(int i=0;i<a;i++) v[i]=scan();
        v[a]=0; v[a+1]=n+1;
        qsort(v,a+2,sizeof(int),cmp);
        for(int i=1;i<a;i++){
            int d=v[i]-v[i+1]-1; // current gap
            if(!d) continue;
            if(d==1){ // gap = 1
                q[r++]=2;
            }
            else if(d&1){ // odd gaps
                if(d==3){ // special case
                    q[r++]=4;
                    q[r++]=1;
                    q[r++]=1;
                    continue;
                }
                q[r++]=((d>>1)+1)*2;
                q[r++]=((d>>1)-1)*2;
                q[r++]=2;
            }
            else{ // even gaps
                q[r++]=d;
                q[r++]=d;
            }
        }
        q[r++]=(v[0]-v[1]-1)*2; q[r++]=(v[a]-v[a+1]-1)*2; // edges
        qsort(q,r,sizeof(int),cmp);
        if(b<r) r=b;
        while(r--) c+=q[r];
        printf("%d\n",c>>1);
    }
}
