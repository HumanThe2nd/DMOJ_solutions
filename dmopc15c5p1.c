// DMOPC '15 Contest 5 P1 - Gel Bananas
// By: Dan Shan
// divide a number (up to 18 digits) by lcm of 2 other numbers
// use long long ints and subtract one before dividing by the lcm of the other 2 nubers and incrementing by 1
#include <stdio.h>
#define lli long long int
lli gcd(lli a, lli b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
lli lcm(lli a,lli b) { return (a / gcd(a, b)) * b; } 
int main(){
lli a,b,x;
scanf("%lld %lld %lld",&a,&b,&x);
lli d = (x-1)/lcm(a,b);
printf("%lld\n",d+1);
}
