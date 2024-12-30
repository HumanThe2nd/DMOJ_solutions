/*
Amplitude Hackathon '23 Practice Problem 3 - Demo Day Demos
Author: Dan Shan
Date: 2024-12-29
Sort the values and brute force maximum through iteration
*/
#include <stdio.h>
#include <stdlib.h>
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
int cmp(const void *a, const void *b){
	long long d=(*(long long*)a-*(long long*)b); // edit sort to avoid overflow
	return (d>0)-(d<0);
}
int main() {
    long long n=scan(),k=scan();
	long long a[n],c=0;
	for(int i=0;i<n;i++) a[i]=scan();
	qsort(a,n,sizeof(long long),cmp);
	for(int i=0;i<n;i++){
		k-=a[i];
		if(k<0) break; // no time
		c++;
	}
	printf("%lld\n",c);
}
