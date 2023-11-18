//============================================================================
// Name        : Big Deposits
// Author      : Dan Shan
//============================================================================
// Goal: Find optimal value of n for a given function
// Approach: Binary search each value of n to find the optimal one
// Note: the binary search will finish with 2 values check if smaller works else answer is larger
#include<stdio.h>
#include<math.h>
int main(){
    long double p,y,t;
    scanf("%Lf %Lf %Lf",&p,&y,&t);
    long long int n1 = 0, n2 = 1e18;
    while(n1<n2-1){ // run sim each time will binary searching
        long double ni=(n2+n1)/2;
        long double ti=0;
        for(int i=0;i<y;i++){
            ti+=ni;
            ti=floor(ti*(1+(p/100)));
        }
        if(ti>t) n2 = ni;
        else n1 = ni;
    }
    long double ti=0;
    for(int i=0;i<y;i++){
        ti+=n1;
        ti=floor(ti*(1+(p/100)));
    }
    if(ti>=t) printf("%lld\n",n1);
    else printf("%lld",n2);
}
