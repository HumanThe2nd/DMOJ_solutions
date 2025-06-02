/*
A Math Contest P1 - Arrays
Author: Dan Shan
Date: 2025-06-01
Math theorem used: Bézout's Identity
Compute GCD of entire array as positives
*/
#include <stdio.h>
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
long long gcd(long long a, long long b){ // gcd template
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
int mn[17][50001],mx[17][50001];
int main(){
    buff();
    int n=scan(),a[n];
    for(int i=0;i<n;++i){
        a[i]=scan();
        if(i) a[i]=gcd(a[i],a[i-1]);
    }
    if(a[n-1]<0) a[n-1]=-a[n-1];
    printf("%d\n",a[n-1]);
}
