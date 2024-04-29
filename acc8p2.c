// Another Contest 8 Problem 2 - Unnecessary Trash Push
// Author: Dan Shan
#include<stdio.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int main(){
    int t;
    scan(t);
    for(int i=0;i<t;i++){
        long long c=0, n,k,ct=0;
        scan(n); scan(k);
        for(int j=0;j<n;j++){
            long long a;
            scan(a);
            c+=a;
            if(c>=k) {
                ct++; c=0;
            }
        }
        printf("%lld\n",ct);
    }
}
