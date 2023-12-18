// Bob's Fighting With Monsters
// By: Dan Shan
// modulus n by k and take min of that value of k minus the answer from modulus
#include <stdio.h>
int main(){
long long int n,k;
scanf("%lld %lld",&n,&k);
long long int d1 = n%k,d2 = k-n%k;
printf("%lld\n",d1>d2?d2:d1);
}
