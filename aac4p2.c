/*
An Animal Contest 4 P2 - Lavish Lights
Author: Dan Shan
Date: 2025-02-14
prefix lcm array
binary search first index that the query isn't divisible by 
special case: t=0 -> -1 (all lights start on)
Time Complexity: O(Nlog(1e9) + Ti*logN)
*/
#include <stdio.h>
#include <stdlib.h>
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
long long gcd(long long a, long long b){
	if(b>a){ // make a the larger
		long long temp=b;
		b=a; a=temp;
	}
	while(b){
		long long r=a%b;
		a=b; b=r;	
	}
	return a;
}
long long lcm(long long a,long long b){
    return a*b/gcd(a,b);
}
int main(){
    buff();
    long long n=scan(),q=scan(),a[n];
    a[0]=scan();
    for(int i=1;i<n;i++){ // build lcm array
        a[i]=scan();
        if(a[i-1]<1000000001) a[i]=lcm(a[i-1],a[i]);
        else a[i]=a[i-1];
    }
    while(q--){ // binary search first non-divisible lcm
        long long ti=scan(),l=0,r=n-1;
        if(!ti){ // special case, ti=0
            puts("-1");
            continue;
        }
        while(l!=r){
            long long mid=(l+r)/2;
            if(ti%a[mid]) r=mid; // non-divisble -> right bound down
            else l=mid+1; // divisible -> left bound up
        }
        if(ti%a[l]) printf("%lld\n",l+1); // found
        else puts("-1");
    }
}
