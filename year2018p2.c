/*
New Year's '18 P2 - Mimi and Christmas Cake
Author: Dan Shan
Date: 2024-12-31
Sieve of Erathosthenes to pre-compute 
Time Complexity: O(n)
Sieve takes constant time around O(100000log(100000))
*/
#include <stdio.h>
int scan() {
    int num = 0;
    char c = getchar();
    while (c>'9'||c<'0') c = getchar();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar();
    }
    return num;
}
int a[100001]; // sieve
int main() {
    int n=scan(),c=0;
    a[1]=1; // 1 is not prime
    for(int i=4;i<100001;i+=2) a[i]=1; // seperate evens for efficiency
    for(int i=3;i*i<100001;i+=2){
        if(a[i]) continue; // skip non-primes
        for(int j=2*i;j<100001;j+=i) a[j]=1;
    }
    while(n--){
        int ai=scan();
        if(!a[ai]) c++;
    }
    printf("%d\n",c);
}
