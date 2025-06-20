/*
DMOPC '15 Contest 6 P3 - Harvest
Author: Dan Shan
Date: 2024-12-08
Input using difference array of missing potatos
Create normal array and subtract missing potatos 
Convert to Prefix sum array
2 pointer approach for minimum interval width
Note: special case where no potatoes are needed, width is zero
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
long long scan() {
    long long num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
long long d[200001],a[200002]; // Difference array, Prefix sum array
int main() {
	long long n=scan(),m=scan(),k=scan();
	if(!k) return putchar_unlocked('0')*0;
    for(int i=1;i<=m;i++){
        int a=scan(),b=scan();
        d[a]--; d[b+1]++;
    }
    for(int i=1;i<=n;i++) a[i]=a[i-1]+d[i];
    for(int i=1;i<=n;i++) a[i]+=m+a[i-1];
    long long l=0,r,w=2e15;
    for(r=0;r<=n;r++){ // two pointer scan
        while(a[r]-a[l]>=k){
            if(r-l<w) w=r-l;
            l++;
        }
    }
    while(a[r]-a[l]>=k){
            if(r-l<w) w=r-l;
            l++;
    }
    if(w==2e15) printf("-1");
    else printf("%lld",w);
    putchar_unlocked('\n');
}
