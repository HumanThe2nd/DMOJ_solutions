/*
Longest Increasing Subsequence
Author: HumanThe2nd
Date: 2025-03-31
For each number Ai:
largest so far: push Ai to back of list
otherwise: overwrite lowest number not less than Ai
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // buffer size
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
int main() {
    buff();
    int n=scan(),dp[1000001],r=1;
    dp[0]=scan();
    for(int i=1;i<n;i++){
        int ai=scan();
        if(ai>dp[r-1]) dp[r++]=ai;
        else{
            int l=0,u=r;
            while(l<u){
                int mid=(l+u)/2;
                if(dp[mid]>=ai) u=mid;
                else l=mid+1;
            }
            dp[l]=ai;
        }
    }
    printf("%d\n",r);
}
