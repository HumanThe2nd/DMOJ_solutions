// Yet Another Contest 8 P1 - Permutation Sorting
// By: Dan Shan
#include <stdio.h>
int main() {
    int n,m=0,c=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        if(a==i&&a>m)c++;
        if(a>m) m=a;
    }
    printf("%d\n",n-c);
}
