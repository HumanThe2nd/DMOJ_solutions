// DMOPC '21 Contest 5 P2 - Permutations & Primes
// By: Dan Shan
// n=1 is just 1
// impossible for n=2
// afterwards we print 3 1 2 4 5 6 7 8 and so up to n
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    if(n==2){
        printf("-1\n");
        return 0;
    }
    else if(n==1){
        printf("1\n");
        return 0;
    }
    printf("1 3 2%s",n==3?"\n":" ");
    for(int i=4;i<=n;i++)printf("%d%s",i,i==n?"\n":" ");
}
