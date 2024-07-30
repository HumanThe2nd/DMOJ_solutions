// Cheerio Contest 2 P2 - Cereal Boxes
// Author: Dan Shan
#include <stdio.h>
int main() {
    long long m,c,l,q,n=0;
    scanf("%lld%lld%lld%lld",&m,&c,&l,&q);
    while(q>0){
        if(m*c<=q) n+=m;
        else n+=q/c;
        q-=m*c;
        c+=l;
    }
    printf("%lld\n",n);
}
